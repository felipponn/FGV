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

void printArray(int arriNumbers[], int iLength)
{
    for (int i = 0; i < iLength; i ++) cout << arriNumbers[i] << " ";
    cout << endl;
}

int main()
{
    int arriNumbers[] = {42, 7, 0, 666, 13};
    int iArraySize = sizeof(arriNumbers)/sizeof(arriNumbers[0]);
    
    cout << "Array original: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeStart = high_resolution_clock::now();
    bubbleSort(arriNumbers, iArraySize);
    auto timeStop = high_resolution_clock::now();
    
    cout << "Array original ordenado: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop-timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "=====================" << endl;

    return 0;
}
