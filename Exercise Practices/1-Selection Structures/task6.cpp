#include <iostream>

using namespace std;

void printMenu()
{
    cout << "1. Air\n";
    cout << "2. Water\n";
    cout << "3. Steel\n";
}

void calculateTime(int distance, int choice)
{

    int time;
    switch (choice)
    {
    case 1:
        time = distance / 1100.0;
        cout << "Time taken: " << time << " seconds" << endl;

        break;
    case 2:
        time = distance / 4900.0;
        cout << "Time taken: " << time << " seconds" << endl;
        break;

    case 3:
        time = distance / 16400.0;
        cout << "Time taken: " << time << " seconds" << endl;
        break;

    default:

        cout << "No time.....\n";
        break;
    }
}

int main()
{
    printMenu();

    int choice, distance;
    cout << "Enter the option(1-3): ";
    while (choice < 1 || choice > 3)
    {

        cin >> choice;
        cout << "choice btw 1 to 3: ";
    }
    cout << endl;

    cout << "Enter distance: ";
    cin >> distance;

    calculateTime(distance, choice);

    return 0;
}