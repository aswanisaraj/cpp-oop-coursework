#include <iostream>
#include <cmath>
using namespace std;

class Cuboids
{

private:
    float height, width, depth;

public:
    // Default constructor
    Cuboids()
    {
        height = 1;
        width = 1;
        depth = 1;
    }

    // Parameterized Constructor

    Cuboids(int a, int b, int c)
    {

        if (a > 0 && a < 35)
        {
            height = a;
        }
        else
        {
            height = 1;
        }

        if (b > 0 && b < 35)
        {
            width = b;
        }
        else
        {
            width = 1;
        }

        if (c > 0 && c < 35)
        {
            depth = c;
        }
        else
        {
            depth = 1;
        }
    }

    // parametrized Constructor
    Cuboids(int a, int b)
    {

        if (a > 0 && a < 35)
        {
            height = a;
        }
        else
        {
            height = 1;
        }

        if (b > 0 && b < 35)
        {
            width = b;
        }
        else
        {
            width = 1;
        }

        depth = 1;
    }
    // Copy Constructor

    Cuboids(const Cuboids &obj)
    {

        this->height = obj.height;
        this->width = obj.width;
        this->depth = obj.depth;
    }
    // Destructor

    ~Cuboids()
    {
        cout << "Destructor Called........." << endl;
    }

    // Setter.............
    void setHeight(int a)
    {

        if (a > 0 && a < 35)
        {
            height = a;
        }
        else
        {
            height = 1;
        }
    }
    // Setter.............
    void setWidth(int b)
    {
        if (b > 0 && b < 35)
        {
            width = b;
        }
        else
        {
            width = 1;
        }
    }
    // Setter..............
    void setDepth(int c)
    {
        if (c > 0 && c < 35)
        {
            depth = c;
        }
        else
        {
            depth = 1;
        }
    }
    // getter...........
    float getHeight()
    {
        return height;
    }
    // Getter......

    float getWidth()
    {
        return width;
    }
    // Getter.......

    float getDepth()
    {
        return depth;
    }

    void setCuboids(int a1, int b1, int c1)
    {
        if (a1 > 0 && a1 < 35)
        {
            height = a1;
        }
        else
        {
            height = 1;
        }

        if (b1 > 0 && b1 < 35)
        {
            width = b1;
        }
        else
        {
            width = 1;
        }

        if (c1 > 0 && c1 < 35)
        {
            depth = c1;
        }
        else
        {
            depth = 1;
        }
    }

    void getCuboids()
    {
        cout << "Enter the Height: " << endl;
        cin >> height;
        while (height < 0 && height > 35)
        {
            cin >> height;
        }

        cout << "Enter the Width: " << endl;
        cin >> width;
        while (width < 0 && width > 35)
        {
            cin >> width;
        }

        cout << "Enter the Depth: " << endl;
        cin >> depth;
        while (depth < 0 && depth > 35)
        {
            cin >> depth;
        }
    }

    void putCuboids() const
    {
        cout << "Height of Cuboid: " << height << endl;
        cout << "width of Cuboid: " << width << endl;
        cout << "Depth of Cuboid: " << depth << endl;
    }

    float getSurfaceArea()
    {
        return (2 * (height * width) + 2 * (height * depth) + 2 * (width * depth));
    }

    float getVolume()
    {
        return (height * width * depth);
    }

    float getSpaceDiagonal()
    {
        return sqrt((height * height) + (width * width) + (depth * depth));
    }

    void putCuboidsInfo()
    {

        cout << "\tSurface Area: " << getSurfaceArea() << endl;
        cout << "\tVolume: " << getVolume() << endl;
        cout << "\tSpace Daigonal: " << getSpaceDiagonal() << endl;
    }
};

int main()
{

    Cuboids obj1(12, 14, 16), obj2(10, 20);

    cout << "<-Info of first object->" << endl;
    obj1.putCuboidsInfo();
    cout << endl;
    cout << "<-Info of second object->" << endl;
    obj2.putCuboidsInfo();
    cout << endl;

    return 0;
}
