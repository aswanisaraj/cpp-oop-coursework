#include <iostream>
using namespace std;

void displayTime(double seconds)
{
    int minutes = 0, hours = 0, days = 0;

    if (seconds >= 60 && seconds < 3600)
    {
        minutes = seconds / 60;
        cout << "Minutes: " << minutes << endl;
    }
    else if (seconds >= 3600 && seconds < 86400)
    {
        hours = seconds / 3600;
        cout << "Hours: " << hours << endl;
    }
    else if (seconds >= 86400)
    {
        days = seconds / 86400;
        cout << "Days: " << days << endl;
    }
    else
    {
        cout << "Seconds: " << seconds << endl;
    }
}

int main()
{
    double seconds;
    cout << "Enter duration in second: ";
    cin >> seconds;

    displayTime(seconds);
    return 0;
}
