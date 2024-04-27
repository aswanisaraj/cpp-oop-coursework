#include <iostream>
using namespace std;

int printMenu()
{
    cout << "-----Calculator Menu-----" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Get Remainder" << endl;
    cout << "6. Exit" << endl;

    cout << "---------------------------" << endl;

    return 0;
}

int performOperation(int a)
{

    int b, c;

    switch (a)
    {
    case 1:

        cout << "Enter first number: ";
        cin >> b;
        cout << "Enter second number: ";
        cin >> c;

        cout << "Answer: " << b + c << endl;
        break;
    case 2:
        cout << "Enter first number: ";
        cin >> b;
        cout << "Enter second number: ";
        cin >> c;
        cout << "Answer: " << b - c << endl;
        break;

    case 3:
        cout << "Enter first number: ";
        cin >> b;
        cout << "Enter second number: ";
        cin >> c;
        cout << "Answer: " << b * c << endl;
        break;

    case 4:
        cout << "Enter first number: ";
        cin >> b;
        cout << "Enter second number: ";
        cin >> c;
        while (c == 0)
        {
            cout << "Enter a non zero number: ";
            cin >> c;
        }
        cout << "Answer: " << b / c << endl;
        break;

    case 5:
        cout << "Enter first number: ";
        cin >> b;
        cout << "Enter second number: ";
        cin >> c;
        while (c == 0)
        {
            cout << "Enter a non zero number: ";
            cin >> c;
        }
        cout << "Remainder: " << b % c << endl;
        break;
    case 6:
        cout << "You are not intrested in Math." << endl;

        break;

    default:
        cout << "Not allowed" << endl;
        break;
    }

    return 0;
}

int main()
{
    printMenu();
    int choice;

    cout << "Enter your choise (1-6): ";
    cin >> choice;
    if (choice == 6)
    {
        cout << "You are not intrested in Math." << endl;
    }

    while (choice > 6 && choice < 1)
    {
        cout << "please enter valid option (1-6): ";
        cin >> choice;
    }
    if (choice < 6 && choice >= 1)
    {
        while (choice != 6)
        {
            performOperation(choice);
            cout << endl;
            printMenu();
            cout << "Enter your choise (1-6): ";
            cin >> choice;

            while (choice > 6 && choice < 1)
            {
                cout << "please enter valid option (1-6): ";
                cin >> choice;
            }
        }
    }

    return 0;
}