#include <iostream>

using namespace std;

int main()
{

    float f = 2.5;
    float t = 8.9;

    float *ptrF = &f;
    float *ptrT = &t;

    cout << "The address of F is " << &f << " and value of F is " << f << endl;
    cout << "The address of F is " << ptrF << " and value of F is " << *ptrF << endl;
    cout << "The address of T is " << ptrT << " and value of F is " << *ptrT << endl;
    cout << "The address of ptrF is " << &ptrF << " and value of ptrT is " << &ptrT << endl;


    return 0;
}