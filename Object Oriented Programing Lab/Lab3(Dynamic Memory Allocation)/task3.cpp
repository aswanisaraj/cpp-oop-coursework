#include <iostream>

using namespace std;

int *getEvenNumbers(const int ar[], const int size, int &evenArraySize)
{

    if (size == 0)
    {
        evenArraySize = 0;
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {

        if (ar[i] % 2 == 0)
        {
            evenArraySize++;
        }
    }

   

    int *evenArray = new int[evenArraySize];

    int x = 0;

    for (int i = 0; i < size; i++)
    {

        if (ar[i] % 2 == 0)
        {
            evenArray[x++] = ar[i];
        }
    }

    if (evenArraySize == 0)
    {
        return NULL;
    }

    return evenArray;
}

int main()
{
    int array[] = {1, 7, 11, 13, 14, 25, 23, 23, 27, 31};
    int size = 10;

    int newArraySize = 0;

    cout << "Original array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    int *resultArray = getEvenNumbers(array, size, newArraySize);

    if (resultArray != NULL)
    {
        cout << "Even elements of  array : ";
        for (int i = 0; i < newArraySize; i++)
        {
            cout << resultArray[i] << " ";
        }
        cout << endl;

        delete[] resultArray;
    }
    else
    {
        cout << "No Even Number......" << endl;
    }

    return 0;
}
