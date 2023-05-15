#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swapValue(int& iValue1, int& iValue2)
{
    int iTemp = iValue1;
    iValue1 = iValue2;
    iValue2 = iTemp;
}

void bubbleSort(int arriNumbers[], int iLength)
{
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop ++)
        for (int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop ++)
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
}

void optimizedBubbleSort(int arriNumbers[], int iLength)
{
    bool bUnordered = false;
    
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop ++)
    {
        bUnordered = false;
        
        for (int iInnerLoop = 0; iInnerLoop < iLength - 1 - iOuterLoop; iInnerLoop ++)
        {
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
            {
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
                bUnordered = true;
            }
        }
        
        if (bUnordered == false) break;
    }
}

void printArray(int arriNumbers[], int iLength)
{
    for (int i = 0; i < iLength; i ++) cout << arriNumbers[i] << " ";
    cout << endl;
}

int main()
{
    int arriNumbers_1[] = {42, 7, 0, 666, 13};
    int iArraySize_1 = sizeof(arriNumbers_1)/sizeof(arriNumbers_1[0]);
    
    cout << "Array original: ";
    printArray(arriNumbers_1, iArraySize_1);
    
    auto timeStart = high_resolution_clock::now();
    bubbleSort(arriNumbers_1, iArraySize_1);
    auto timeStop = high_resolution_clock::now();
    
    cout << "Array original ordenado: ";
    printArray(arriNumbers_1, iArraySize_1);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop-timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "=====================" << endl;
    
    int arriNumbers_2[] = {42, 7, 0, 666, 13};
    int iArraySize_2 = sizeof(arriNumbers_2)/sizeof(arriNumbers_2[0]);
    
    cout << "Array embaralhado de novo: ";
    printArray(arriNumbers_2, iArraySize_2);
    
    timeStart = high_resolution_clock::now();
    optimizedBubbleSort(arriNumbers_2, iArraySize_2);
    timeStop = high_resolution_clock::now();
    
    cout << "Array ordenado: ";
    printArray(arriNumbers_2, iArraySize_2);
    
    timeDuration = duration_cast<nanoseconds>(timeStop-timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;
    
    cout << "=====================" << endl;

    return 0;
}
