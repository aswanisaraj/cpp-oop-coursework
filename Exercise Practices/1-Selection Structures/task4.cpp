#include <iostream>
using namespace std;

void findingArea(int width1, int length1, int width2, int length2)
{
    int area1, area2;

    area1 = width1 * length1;
    area2 = width2 * length2;

    if (area1 > area2)
    {
        cout << "Area of first Ractangle is Greater.\n";
    }
    else if (area1 < area2)
    {
        cout << "Area of second Ractangle is Greater.\n";
    }
    else
    {
        cout << "Area of both ractangle are Equal.\n";
    }
}

int main()
{
    int width1, width2, length1, length2;

    cout << "Enter width of first Ractangle: ";
    cin >> width1;

    cout << "Enter length of first Ractangle: ";
    cin >> length1;

    cout << "Enter width of second Ractangle: ";
    cin >> width2;

    cout << "Enter width of first Ractangle: ";
    cin >> length2;

    cout<<endl;
    findingArea(width1,length1,width2, length2);

    return 0;
}
