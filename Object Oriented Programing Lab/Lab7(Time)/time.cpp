#include <iostream>

using namespace std;
class Time
{
private:
    int second, minute, hour;

public:
    // Muttatoras..................................................
    void setSecond(int s)
    {
        if (s >= 0 && s <= 59)
        {
            second = s;
        }
    }

    void setMinute(int m)
    {
        if (m >= 0 && m <= 59)
        {
            minute = m;
        }
    }

    void setHour(int h)
    {
        if (h >= 0 && h <= 23)
        {
            hour = h;
        }
    }

    // accessors..........................................

    int getSecond() const
    {

        return second;
    }

    int getMinute() const
    {
        return minute;
    }

    int getHour() const
    {
        return hour;
    }

    // Constructors...................................................

    Time()
    {
        second = 0;
        minute = 0;
        hour = 0;
    }

    Time(int m, int h)
    {
        second = 0;

        if (m <= 59 && m >= 0)
        {
            minute = m;
        }
        else
        {
            minute = 0;
        }

        if (h <= 23 && h >= 0)
        {
            hour = h;
        }
        else
        {
            hour = 0;
        }
    }

    Time(int h, int m, int s)
    {

        if (m <= 59 && m >= 0)
        {
            minute = m;
        }
        else
        {
            minute = 0;
        }

        if (h <= 23 && h >= 0)
        {
            hour = h;
        }
        else
        {
            hour = 0;
        }

        if (s <= 59 && s >= 0)
        {
            second = s;
        }
        else
        {
            second = 0;
        }
    }
    // Friend Function...............................................
    friend ostream &operator<<(ostream &os, const Time &check);
    friend istream &operator>>(istream &is, Time &check);
    friend int operator-(const Time &lhs, const Time &rhs);
    friend bool operator+(const Time &check);

    // Pre-increment (++).............................
    Time operator++()
    {

        second++;
        if (second == 60)
        {
            second = 0;
            minute++;
        }
        if (minute == 60)
        {
            minute = 0;
            hour++;
        }
        if (hour == 23)
        {

            hour = 0;
        }
        return *this;
    }

    // Pre-decrement (--)..........................................

    Time operator--()
    {

        second--;
        if (second < 0)
        {
            second = 59;
            minute--;
        }
        if (minute < 0)
        {
            minute = 59;
            hour--;
        }
        return *this;
    }

    // Post-increment (++)....................................
    Time operator++(int)
    {

        Time temp = *this;
        second++;
        if (second == 60)
        {
            second = 0;
            minute++;
        }
        if (minute == 60)
        {
            minute = 0;
            hour++;
        }
        
        return *this;
    }
    // Post-decrement (--)......................................................

    Time operator--(int)
    {

        Time temp = *this;
        second--;
        if (second < 0)
        {
            second = 59;
            minute--;
        }
        if (minute < 0)
        {
            minute = 59;
            hour--;
        }
        return *this;
    }
};

//<<...................................................................
ostream &operator<<(ostream &cout, const Time &check)
{
    cout << check.hour << ":" << check.minute << ":" << check.second;
    return cout;
}

// >>.................................................
istream &operator>>(istream &cin, Time &check)
{
    cout << "Hour: ";
    cin >> check.hour;

    while (check.hour < 0 || check.hour > 23)
    {
        cout << "Valid input: ";
        cin >> check.hour;
    }

    cout << "Minute: ";
    cin >> check.minute;

    while (check.minute < 0 || check.minute > 59)
    {
        cout << "Valid input: ";
        cin >> check.minute;
    }

    cout << "Second: ";
    cin >> check.second;

    while (check.second < 0 || check.second > 59)
    {
        cout << "Valid input: ";
        cin >> check.second;
    }

    return cin;
}

// Binary subtraction (-) ................................................................

int operator-(const Time &lhs, const Time &rhs)
{
    int SECOND1 = (lhs.hour * 3600) + (lhs.minute * 60) + lhs.second;
    int SECOND2 = (rhs.hour * 3600) + (rhs.minute * 60) + rhs.second;

    int final = SECOND1 - SECOND2;
    return final;
}

// Unary Addition (+) ..................................................

bool operator+(const Time &check)
{
    if ((check.hour >= 9 && check.hour <= 17) && (check.minute == 0) && (check.second == 0))
    {
        return true;
    }
    return false;
}

// Main Function..............................
int main()
{
    Time obj1, obj2(16, 51, 0), obj3(16, 50, 45);

    cin >> obj1;
    

    obj1--;
    cout << obj1 << endl;

    obj1++;
    cout << obj1 << endl;

     obj1++;
    cout << obj1 << endl;



    ++obj2;
    cout << obj2 << endl;

    --obj2;
    cout << obj2 << endl;

    int ans = obj2 - obj3;

    cout << ans << endl;
    return 0;
}
