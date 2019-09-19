#include "BubleSort.h"

int BubleSort(int *nNum, int nCount)
{
    for(int i=0; i<nCount - 1; i++)
    {
        for(int j=i+1; j<nCount; j++)
        {
            if(nNum[i] < nNum[j])
                continue;

            int nTemp = nNum[i];
            nNum[i] = nNum[j];
            nNum[j] = nTemp;
        }
    }

    return 0;
}