#include <iostream>

using namespace std;

int *PairWiseSum(const int ar[], const int size, int &newArraySize)
{
    if (size == 0)
    {
        newArraySize = 0; 
        return NULL;      
    }

    int *SumArray = new int[size];

    for (int i = 0; i < size; i + 2)
    {
        SumArray[i] = ar[i] + ar[i + 1];
    }

    newArraySize = size;
    return SumArray;

    
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;

    int newArraySize = 0;

    int *resultArray = PairWiseSum(array, size, newArraySize);

    cout << "Original array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    if (resultArray != NULL)
    {
        cout << "Squared array elements: ";
        for (int i = 0; i < newArraySize; i++)
        {
            cout << resultArray[i] << " ";
        }
        cout << endl;

        delete[] resultArray;
    }
    else
    {
        cout << "Input array is empty." << endl;
    }

    return 0;
}
