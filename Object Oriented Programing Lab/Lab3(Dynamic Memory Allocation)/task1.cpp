#include <iostream>

using namespace std;

int main()
{

    int *ptrX = nullptr;
    int *ptrY = nullptr;

    ptrX = new int(2);
    ptrY = new int(8);
    cout << "The address of ptrX is  " << &ptrX << endl;
    cout << "value of ptrX is " << ptrX << endl;
    
    cout << "The value of memory location where it points to is " << *ptrX << endl;
    cout << "The address of ptrY is  " << &ptrY << endl;
    cout << "value of ptrY is " << ptrY << endl;
    cout << "The value of memory location where it points to is " << *ptrY << endl;

    delete ptrX;
    delete ptrY;

    return 0;
}