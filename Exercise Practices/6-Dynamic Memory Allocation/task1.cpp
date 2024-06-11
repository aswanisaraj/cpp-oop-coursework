#include <iostream>

using namespace std;

int *squareElements(const int ar[], const int size, int &newArraySize)
{
    if (size == 0)
    {
        newArraySize = 0; 
        return NULL;     
    }

    int *SquaredArray = new int[size];

    for (int i = 0; i < size; i++)
    {
        SquaredArray[i] = ar[i] * ar[i];
    }

    newArraySize = size;
    return SquaredArray;

    
}

int main(int argc, char const *argv[])
{
    int array[] = {5, 10, 15, 20, 25};
    int size = 5;

    int newArraySize = 0;

    int *resultArray = squareElements(array, size, newArraySize);

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
