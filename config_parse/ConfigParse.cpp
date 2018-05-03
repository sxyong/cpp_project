#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ConfigParse.h"

#define MAX_NAME_LEN  	256
#define MAX_VALUE_LEN	256

ConfigParse::ConfigParse():m_bIsLoad(false)
{

}

ConfigParse::~ConfigParse()
{

}

int ConfigParse::Load(const char* pFileName)
{
	if(pFileName == NULL)
		return -1;

	if(m_bIsLoad)
		return 0;

	FILE*	fp = fopen(pFileName, "rb");
	int 	nSize = 0;

	if(fp == NULL)
		return -2;
	
	fseek(fp, 0, SEEK_END);
	nSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char* pBuf = (char*)malloc(nSize);
	if(pBuf == NULL)
		return -3;

	if(fread(pBuf, 1, nSize, fp) != nSize)
	{
		free(pBuf);
		pBuf = NULL;
		fclose(fp);
		fp = NULL;

		return -4;
	}

	if(Load(pBuf, nSize) != 0)
	{
		free(pBuf);
		fclose(fp);
		pBuf = NULL;
		return -4;
	}

	free(pBuf);
	pBuf = NULL;
	fclose(fp);
	fp = NULL;

	return 0;
}

int ConfigParse::Load(const char* pData, int nLen)
{
	if(pData == NULL || nLen <=0)
		return -1;

	if(m_bIsLoad)
		return 0;

	const char* pStart = pData;
	const char* pEnd = NULL;

	for(int i=0;i<nLen;i++)
	{
		//找到换行符或者到达末尾
		if(pData[i] == '\n' || (i == nLen - 1))
		{
			pEnd = pData + i;
			if(ParseLine(pStart, pEnd) != 0)
			{
				cout<<"ParseLine failed"<<endl;
			}
			pStart = pEnd + 1;
		}
	}

	m_bIsLoad = true;

	return 0;
}

int ConfigParse::GetNameValue(const char* pName, char*& pValue)
{
	if(!m_bIsLoad)
		return -1;

	map<string, string>::iterator it;
	it = m_mapContainer.find(pName);
	if(it == m_mapContainer.end())
		return -1;

	pValue = (char*)it->second.c_str();
	return 0;
}

int ConfigParse::ParseLine(const char* pStart, const char* pEnd)
{
	char szName[MAX_NAME_LEN] = {0};
	char szValue[MAX_VALUE_LEN] = {0};

	bool isFind = false;		//是否发现=
	int i = 0;
	int j = 0;

	for(const char* p=pStart; p<pEnd; p++)
	{
		if(*p == '=')
		{
			//之前已经有=，在发现=就认为这行不合法
			if(isFind)
			{
				return -1;
			}

			isFind = true;
			continue;
		}
		
		if(isspace(*p))
		{
			continue;
		}

		if(!isFind)
			szName[i++] = *p;

		if(isFind)
			szValue[j++] = *p;
	}

	if(!isFind)
		return -1;

	m_mapContainer.insert(make_pair(szName, szValue));
	return 0;
}
