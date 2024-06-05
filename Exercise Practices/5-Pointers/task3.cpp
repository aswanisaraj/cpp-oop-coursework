#include <iostream>

using namespace std;

void arrayByPointer(double *ptrArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Value: " << *(ptrArray + i) << " Address: " << (ptrArray + i) << endl;
    }
}

int main(int argc, char const *argv[])
{
    int size = 10;
    double array[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    arrayByPointer(array, size);

    return 0;
}
