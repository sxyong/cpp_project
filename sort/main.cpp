#include <iostream>
#include "BubleSort.h"
#include "QuickSort.h"

using namespace std;

int main(int argc, char* argv[])
{
    int num0[] = {5,2,1,3,4};
    int num1[] = {1,3,2,4,5};
    int num2[] = {4,2,1,3,5};

    // BubleSort(num0, 5);
    // for(int i=0; i<5; i++)
    //     cout << num0[i] << " ";
    // cout<<endl;

    // BubleSort(num1, 5);
    // for(int i=0; i<5; i++)
    //     cout << num1[i] << " ";
    // cout<<endl;

    // BubleSort(num2, 5);
    // for(int i=0; i<5; i++)
    //     cout << num2[i] << " ";
    // cout<<endl;

    QuickSort(num0, 0, 4);
    for(int i=0; i<5; i++)
        cout << num0[i] << " ";
    cout<<endl;

    QuickSort(num1, 0, 4);
    for(int i=0; i<5; i++)
        cout << num1[i] << " ";
    cout<<endl;

    QuickSort(num2, 0, 4);
    for(int i=0; i<5; i++)
        cout << num2[i] << " ";
    cout<<endl;

    return 0;
}