#include <iostream>
using namespace std;

int main()
{

    int number;

    cout << "Enter a number btw (1-10) ";
    cin >> number;
    while (number <= 1 || number >= 10)
    {
        cout << "Warning! Enter a number btw (1-10) ";
        cin >> number;
    }
    cout << "\n";

    switch (number)
    {
    case 1:
        cout << "The number in Roman version:  i" << endl;
        break;
    case 2:
        cout << "The number in Roman version:  ii" << endl;
        break;
    case 3:
        cout << "The number in Roman version:  iii" << endl;
        break;
    case 4:
        cout << "The number in Roman version:  iv" << endl;
        break;
    case 5:
        cout << "The number in Roman version:  v" << endl;
        break;
    case 6:
        cout << "The number in Roman version:  vi" << endl;
        break;
    case 7:
        cout << "The number in Roman version:  vii" << endl;
        break;
    case 8:
        cout << "The number in Roman version:  viii" << endl;
        break;
    case 9:
        cout << "The number in Roman version:  ix" << endl;
        break;
    case 10:
        cout << "The number in Roman version:  x" << endl;
        break;

    default:
        cout << "Number is not in range." << endl;
        break;
    }

    return 0;
}