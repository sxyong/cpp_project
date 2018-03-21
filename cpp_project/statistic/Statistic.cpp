#include "Statistic.h"

uint64_t Statistic::m_nNum[MAX_CORE_NUM][ST_TYPE_COUNT] = {0};

void Statistic::Add(int nCoreIndex, en_statistic_type type)
{
	m_nNum[nCoreIndex][type]++;
}

void Statistic::Dec(int nCoreIndex, en_statistic_type type)
{
	m_nNum[nCoreIndex][type]--;
}
	
uint64_t Statistic::GetCount(en_statistic_type type)
{
	uint64_t nTotal = 0;
	for(int i=0;i<MAX_CORE_NUM;i++)
	{
		nTotal += m_nNum[i][type];
	}

	return nTotal;
}
