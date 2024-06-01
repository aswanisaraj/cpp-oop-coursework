#include <iostream>

using namespace std;

int main()
{

    int a, b;

    cout << "Enter first Number: ";
    cin >> a;
    cout << "Enter second Number: ";
    cin >> b;

    if (a < b)
    {
        cout << "Asending Order: " << a << " " << b << endl;
        
        
    }
    else
    {
        cout << "Asending Order: " << b << " " << a << endl;
        
    }

    return 0;
}