#include <iostream>
using namespace std;

// Function for accepting the elements
int getData(int data[], int size)
{
    cout << "Enter the elements of array : ";
    for (int i = 0; i < size; ++i)
    {

        cin >> data[i];
    }

    return size;
}

// Function for displaying the Elements
int displayData(int data[], int size)
{
    cout << "The elements of the array are : ";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << "\n";
    return size;
}
// Function returning the even count 
int countEven(int data[], int size)
{
    int even_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] % 2 == 0)
        {
            even_count++;
        }
    }

    return even_count;
}


//function returning the mean
float mean(int data[], int size)
{
    int sum;
    float mean;
    for (int i = 0; i < size; i++)
    {
        sum += (data[i]);
    }
    mean = sum / size;

    return mean;
}

int main()
{

    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int data[size];

    getData(data, size);
    displayData(data, size);
    int evens = countEven(data, size);
    cout << "Count of evens: " << evens << endl;
    float m = mean(data, size);
    cout << "Mean is : " << m << endl;

    return 0;
}