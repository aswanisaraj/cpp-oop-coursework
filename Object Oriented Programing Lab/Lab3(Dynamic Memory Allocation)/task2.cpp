#include <iostream>

using namespace std;

int main()
{

    int size;
    float sum = 0;
    float average;
    cout << "Enter the size of a float array: ";
    cin >> size;

    float *array = new float[size];

    cout << "Enter the values of the float array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> *(array + i);
    }

    for (int i = 0; i < size; i++)
    {
        sum += *(array + i);
    }
    average = sum / size;

    cout << "The average is: " << average << endl;

    delete[] array;

    return 0;
}