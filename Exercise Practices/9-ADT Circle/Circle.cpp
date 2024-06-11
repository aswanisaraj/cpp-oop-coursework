#include <iostream>
#include <cmath>
using namespace std;

class Circle
{
    int x;
    int y;
    float radius;
    const double PI = 3.141593;

public:
    // Mutator.......................
    void setValues(int a, int b, float rad)
    {
        if (a >= -50 && a <= 50)
        {
            x = a;
        }
        else
        {
            x = 0;
        }

        if (b >= -50 && b <= 50)
        {
            y = b;
        }
        else
        {
            y = 0;
        }

        if (rad >= 1 && rad <= 10)
        {
            radius = rad;
        }
        else
        {
            radius = 5;
        }
    }

    // Accessor..............
    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    float getRadius() const
    {
        return radius;
    }

    double getPI() const
    {
        return PI;
    }

    // Parameterized Constructors...................
    Circle(int X, int Y, float Rad)
    {
        if (X >= -50 && X <= 50)
        {
            x = X;
        }
        else
        {
            x = 0;
        }

        if (Y >= -50 && Y <= 50)
        {
            y = Y;
        }
        else
        {
            y = 0;
        }

        if (Rad >= 1 && Rad <= 10)
        {
            radius = Rad;
        }
        else
        {
            radius = 5;
        }
    }

    Circle(int X, int Y)
    {
        if (X >= -50 && X <= 50)
        {
            x = X;
        }
        else
        {
            x = 0;
        }

        if (Y >= -50 && Y <= 50)
        {
            y = Y;
        }
        else
        {
            y = 0;
        }
        radius = 5;
    }

    Circle(int X, float Rad)
    {
        if (X >= -50 && X <= 50)
        {
            x = X;
        }
        else
        {
            x = 0;
        }
        if (Rad >= 1 && Rad <= 10)
        {
            radius = Rad;
        }
        else
        {
            radius = 5;
        }
        y = 0;
    }

    // Default Constructor................
    Circle()
    {
        x = 0;
        y = 0;
        radius = 5;
    }

    // Copy Constructor...........
    Circle(const Circle &obj)
    {
        x = obj.x;
        y = obj.y;
        radius = obj.radius;
    }
    // Destructor.............
    ~Circle()
    {
        cout << "\nDestructor Executed........." << endl;
    }

    void setCircle(int X, int Y, float Rad)
    {
        if (X >= -50 && X <= 50)
        {
            x = X;
        }
        else
        {
            x = 0;
        }

        if (Y >= -50 && Y <= 50)
        {
            y = Y;
        }
        else
        {
            y = 0;
        }

        if (Rad >= 1 && Rad <= 10)
        {
            radius = Rad;
        }
        else
        {
            radius = 5;
        }
    }

    void getCircle()
    {
        cout << "Enter the x-axis(-50 to 50): ";
        cin >> x;
        while (x < -50 || x > 50)
        {
            cout << "Enter value in range!!!";
            cin >> x;
        }

        cout << "Enter the y-axis: ";
        cin >> y;
        while (y < -50 || y > 50)
        {
            cout << "Enter value in range!!!";
            cin >> y;
        }

        cout << "Enter the Radius: ";
        cin >> radius;
        while (radius < 1 || radius > 10)
        {
            cin >> radius;
        }
    }

    void putCircle() const
    {
        cout << "x-axis: " << x << endl;
        cout << "y-axis: " << y << endl;
        cout << "Radius: " << radius << endl;
    }

    double getArea()
    {
        return PI * pow(radius, 2);
    }

    double getDiameter()
    {
        return (radius * 2);
    }

    double getCircumference()
    {
        return (2 * PI * radius);
    }

    int addCircle(Circle &obj1, Circle &obj2)
    {
        return (obj1.x + obj2.x, obj1.y + obj2.y, obj1.radius + obj2.radius);
    }

    bool isEqual(Circle &obj1, Circle &obj2) const
    {
        if ((obj1.x == obj2.x) && (obj1.y == obj2.y) && (obj1.radius == obj2.radius))
        {
            return true;
        }
        return false;
    }

    int findCircle(const Circle array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if ((this->x == array[i].x) && (this->y == array[i].y) && (this->radius == array[i].radius))
            {
                return i;
            }
        }
        return -1;
    }

    void updateObjects(Circle array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if ((x == array[i].x) && (y == array[i].y))
            {
                array[i].radius = radius;
            }
        }
    }
};

int main()
{
    // Circle obj, obj1(10, 10,5.00), obj2(10, 10, 5.00);
    // obj.getCircle();
    // cout << obj.isEqual(obj1, obj2);
    // int size = 3;
    // Circle obj[size];
    // Circle object(9, 9, 9.00);
    // for (int i = 0; i < size; i++)
    // {
    //     obj[i].getCircle();
    // }

    // for (int i = 0; i < size; i++)
    // {

    //     if (object.findCircle(obj, size) == -1)
    //     {
    //         cout << i << "th index object is not equal to Calling Oject." << endl;
    //     }
    //     else
    //     {
    //         cout << i << "th index object is equal to Calling Oject." << endl;
    //     }
    // }

    return 0;
}
