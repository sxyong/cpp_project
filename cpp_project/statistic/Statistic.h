/**************************************************************************
 * author:		songxy
 * date:		2018/03/21
 * function:	统计模块，为了统计
 *************************************************************************/
#pragma once
#include <stdint.h>		//for uint64_t 

#define	MAX_CORE_NUM	48	//最大的核数量

typedef enum en_statistic_type
{
	ST_TYPE_PKT_REC = 0,  		//接收数据包的数量
	ST_TYPE_PKT_DROP = 1,		//drop数据包的数量
	ST_TYPE_TCP_ADD = 2, 		//创建tcp流的数量
	ST_TYPE_TCP_DEL = 3, 		//删除tcp流的数量
	ST_TYPE_PKT_DISORDER = 4, 	//乱序包的数量
	ST_TYPE_IP_FRAGEMENT = 5, 	//ip分片的数量
	ST_TYPE_COUNT = 6			//总共统计的类型数量
}en_statistic_type;

class Statistic
{
	public:
		static void Add(int nCoreIndex, en_statistic_type type);
		static void Dec(int nCoreIndex, en_statistic_type type);

		static uint64_t GetCount(en_statistic_type type);

	private:
		static uint64_t m_nNum[MAX_CORE_NUM][ST_TYPE_COUNT];
};
