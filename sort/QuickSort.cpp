#include "QuickSort.h"

void QuickSort(int nNum[], int nStart, int nEnd)
{
    if(nEnd <= nStart)
        return ;

    int nValue = nNum[nStart];
    int nLow = nStart;
    int nHigh = nEnd;

    while(nLow < nHigh)
    {
        while(nLow < nHigh && nNum[nHigh] > nValue)
            nHigh--;

        nNum[nLow] = nNum[nHigh];

        while(nLow < nHigh && nNum[nLow] <= nValue)
            nLow++;

        nNum[nHigh] = nNum[nLow];
    }

    nNum[nLow] = nValue;

    QuickSort(nNum, nStart, nLow - 1);
    QuickSort(nNum, nLow + 1, nHigh);
}