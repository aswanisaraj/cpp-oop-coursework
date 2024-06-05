#include <iostream>

using namespace std;

void sumByPointer(int *ptrA, int *ptrB, int *ptrR)
{
    *ptrR = *ptrA + *ptrB;
    cout << "The sum is: " << *ptrR << endl;
}

int main()
{
    int num1, num2;
    int result;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter Second number: ";
    cin >> num2;

    sumByPointer(&num1, &num2, &result);
    return 0;
}