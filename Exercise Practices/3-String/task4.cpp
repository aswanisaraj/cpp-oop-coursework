#include <iostream>
#include <string>
using namespace std;

string concatenateStrings(const string arr[], const int size)
{
    string result;

    // Iterate through each string in the array
    for (int i = 0; i < size; ++i)
    {
        // Append the current string to the result, followed by a blank space
        result += arr[i];
        if (i < size - 1)
        { // Add a blank space after each string except the last one
            result += " ";
        }
    }

    return result;
}

int main()
{
    const int size = 4;
    string arr[size];

    // Input strings from the user
    cout << "Enter " << size << " strings:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "String " << i + 1 << ": ";
        getline(cin, arr[i]);
    }

    // Call the function to concatenate strings
    string concatenatedString = concatenateStrings(arr, size);

    // Display the concatenated string
    cout << "Concatenated string: " << concatenatedString << endl;

    return 0;
}

