#include <iostream>
using namespace std;

int main()
{

    int rows = 4, coloumn = 4;
    int matrix[rows][coloumn];
    int transpose[rows][coloumn];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            cout << "Enter element " << i + 1 << " row " << j + 1 << " coloumn: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
        cout << "\n";
    }

    cout << "Transpose Matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}