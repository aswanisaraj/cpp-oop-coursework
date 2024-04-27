#include <iostream>
#include <fstream>

using namespace std;

void printMenu(int arr[], int size)
{
    cout << "----- Data Operations Menu -----\n";
    cout << "0. Display Original Data\n";
    cout << "1. Get Minimum Number\n";
    cout << "2. Get Maximum Number\n";
    cout << "3. Get Sum of Data\n";
    cout << "4. Get Average of Data\n";
    cout << "5. Count Odd/Even Numbers\n";
    cout << "6. Exit\n";
    cout << "------------------------------------------\n";
}

void printOriginalData(int arr[], int size)
{
    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << "\t";
        if (i % 9 == 0 && i != 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

void getMinimumNumber(int arr[], int size)
{
    int min = 9999;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "The minimum number is: " << min << endl;
}

void getMaximumNumber(int arr[], int size)
{
    int max = -9999;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << "The maximum number is : " << max << endl;
}

void getSumOfData(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    cout << "Total sum is: " << sum << endl;
}

void getAverageOfData(int arr[], int size)
{
    int sum = 0;
    float average;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    average = sum / 100.0;

    cout << "The Average is: " << average << endl;
}

void countOddEvenNumbers(int arr[], int size)
{
    int e_count = 0, o_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            e_count++;
        }
        else
        {
            o_count++;
        }
    }
    cout << "Count of Odd numbers: " << o_count << endl;
    cout << "Count of Even numbers: " << e_count << endl;
}

int main()
{
    int data;
    int array[100];
    int i = 0;
    int choice = 0;

    ifstream file("input.txt");

    if (file.is_open())
    {
        while (file >> data)
        {
            array[i] = (int)data;
            i++;
        }

        cout << endl;
    }
    else
    {
        cerr << "Failed to open file......\n";
    }

    // printMenu(array, 100);
    // cin >> choice;

    while (choice != 6)
    {
        printMenu(array, 100);
        cout << "Enter option: ";
        cin >> choice;

        while (choice > 6 || choice < 0)
        {
            cout << "please enter valid option (0-6): ";
            cin >> choice;
        }

        if (choice == 0)
        {
            printOriginalData(array, 100);
        }
        else if (choice == 1)
        {
            getMinimumNumber(array, 100);
        }
        else if (choice == 2)
        {
            getMaximumNumber(array, 100);
        }
        else if (choice == 3)
        {
            getSumOfData(array, 100);
        }
        else if (choice == 4)
        {
            getAverageOfData(array, 100);
        }
        else if (choice == 5)
        {
            countOddEvenNumbers(array, 100);
        }
        else
        {
            cout << "Allah Hafiz" << endl;
        }
    }
    file.close();
    return 0;
}
