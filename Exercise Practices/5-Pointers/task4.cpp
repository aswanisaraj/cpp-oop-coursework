#include <iostream>

using namespace std;

void getEvenOddSum(int *ptrArray, int size, int *ptrEvenSum, int *ptrOddSum)
{
    for (int i = 0; i < size; i++)
    {
        if (*(ptrArray + i) % 2 == 0)
        {
            *ptrEvenSum += *(ptrArray + i);
        }
        else
        {
            *ptrOddSum += *(ptrArray + i);
        }
    }
}



int main()
{
    int size = 10;
    int ptrEvenSum = 0, ptrOddSum = 0;
    int ptrArray[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    getEvenOddSum(ptrArray, size, &ptrEvenSum, &ptrOddSum);

    cout << "Sum of Even numbers: " << ptrEvenSum << endl;
    cout << "Sum of Even numbers: " << ptrOddSum << endl;

    return 0;
}
