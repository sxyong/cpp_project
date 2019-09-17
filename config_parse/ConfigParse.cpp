#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
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
	if(m_bIsLoad)
		return 0;

	ifstream f(pFileName);
	if(!f.is_open())
		return -1;

	m_bIsLoad = true;

	char buf[1024];
	while(f.getline(buf, sizeof(buf)))
	{
		if(ParseLine(buf, buf + f.gcount()) != 0)
			return -2;
	}

	f.close();

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
