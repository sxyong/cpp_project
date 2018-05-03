/*****************************************************************
 * author:		songxy
 * date:		2018/03/2018
 * function:	解析配置文件
 * 				可以一个名称不可以对应多个值
 ****************************************************************/
#pragma once
#include <vector>
#include <map>

using namespace std;

class ConfigParse
{
	public:
		ConfigParse();
		~ConfigParse();

		//功能：加载配置
		//参数：pFileName 配置文件名称
		//返回值：0 成功   其他失败
		int Load(const char* pFileName);

		//功能：加载配置
		//参数：pData 配置文件数据
		//		nLen 配置文件大小
		//返回值：0 成功   其他失败
		int Load(const char* pData, int nLen);

		//功能：获取一个名称的值
		int GetNameValue(const char* pName, char*& pValue);

	private:
		int ParseLine(const char* pStart, const char* End);

	private:
		bool				m_bIsLoad;			//是否加载配置
		map<string, string>	m_mapContainer;		//名称-值的容器
};
