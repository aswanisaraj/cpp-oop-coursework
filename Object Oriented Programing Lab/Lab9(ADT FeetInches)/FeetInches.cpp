#include "iostream"

using namespace std;

class FeetInches
{
private:
    int feet;   // To hold a number of feet
    int inches; // To hold a number of inches

    // Private member function to simplify the values in feet and inches
    void simplify()
    {
        if (inches >= 12)
        {
            feet += (inches / 12); // feet = feet + (inches / 12)
            inches = inches % 12;
        }
        else if (inches < 0)
        {
            feet -= ((abs(inches) / 12) + 1); // feet = feet - ((abs(inches) / 12) + 1)

            inches = 12 - (abs(inches) % 12);
        }
    }

public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // Copy constructor
    FeetInches(const FeetInches &right)
    {
        feet = right.feet;
        inches = right.inches;
        simplify();
    }

    // Mutator function to set feet
    void setFeet(int f)
    {
        feet = f;
    }

    // Mutator function to set inches
    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    // Accessor function to get feet
    int getFeet() const
    {
        return feet;
    }

    // Accessor function to get inches
    int getInches() const
    {
        return inches;
    }

    // Overloaded + operator
    FeetInches operator+(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches + right.inches;
        temp.feet = feet + right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded - operator
    FeetInches operator-(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches - right.inches;
        temp.feet = feet - right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded * operator
    FeetInches operator*(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches * right.inches;
        temp.feet = feet * right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded prefix ++ operator
    FeetInches operator++()
    {
        ++inches;
        simplify();

        return *this;
    }

    // Overloaded postfix ++ operator
    FeetInches operator++(int)
    {
        FeetInches temp(feet, inches);

        inches++;
        simplify();

        return temp;
    }

    // Overloaded prefix -- operator
    FeetInches operator--()
    {
        --inches;
        simplify();

        return *this;
    }

    // Overloaded postfix -- operator
    FeetInches operator--(int)
    {
        FeetInches temp(feet, inches);

        inches--;
        simplify();

        return temp;
    }

    // Overloaded > operator
    bool operator>(const FeetInches &right) const
    {
        bool status;

        if (feet > right.feet)
            status = true;
        else if (feet == right.feet && inches > right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded < operator
    bool operator<(const FeetInches &right) const
    {
        return !(*this > right);
    }

    // Overloaded >= operator
    bool operator>=(const FeetInches &right) const
    {
        bool status;

        if (feet >= right.feet)
            status = true;
        else if (feet == right.feet && inches >= right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded <= operator
    bool operator<=(const FeetInches &right) const
    {
        return !(*this >= right);
    }

    // Overloaded == operator
    bool operator==(const FeetInches &right) const
    {
        bool status;

        if (feet == right.feet && inches == right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded != operator
    bool operator!=(const FeetInches &right) const
    {
        return !(*this == right);
    }

    // Friend function to overload << operator for output
    friend ostream &operator<<(ostream &, const FeetInches &);

    // Friend function to overload >> operator for input
    friend istream &operator>>(istream &, FeetInches &);
};

// Overloaded << operator
ostream &operator<<(ostream &out, const FeetInches &obj)
{
    out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

    return out;
}

// Overloaded >> operator
istream &operator>>(istream &in, FeetInches &obj)
{
    cout << "Enter Feet:\t";
    in >> obj.feet;

    cout << "Enter Inches:\t";
    in >> obj.inches;

    return in;
}

class RoomDImension
{
private:
    FeetInches length;
    FeetInches width;

public:
    // parametrized constructor
    RoomDImension(FeetInches &Length, FeetInches &Width) : length{Length}, width{Width}
    {
    }

    // Mutator.....................
    void setLength(FeetInches Length)
    {
        this->length = Length;
    }

    void setWidth(FeetInches Width)
    {
        this->width = Width;
    }

    // Accessor.........
    FeetInches getLength() const
    {
        return length;
    }

    FeetInches getWidth() const
    {
        return width;
    }

    // Calculate Area................
    int calArea()
    {

        return (length.getFeet() * width.getFeet());
    }

    void displayObject() const
    {
        cout << "Width: " << endl;
        cout << "Feet: " << width.getFeet() << "\t" << "Inches: " << width.getInches() << endl;

        cout << "Length: " << endl;
        cout << "Feet: " << length.getFeet() << "\t" << "Inches: " << length.getInches() << endl;
    }
};

class RoomCarpet
{
private:
    RoomDImension roomSize;
    float costPerSquareFoot;

public:
    // Constructor.........................
    RoomCarpet(float Foot, RoomDImension &RoomSize) : roomSize{RoomSize}, costPerSquareFoot{Foot}
    {
    }

    // Mutator...........
    void setRoomSize(RoomDImension obj)
    {
        this->roomSize = obj;
    }

    void setCOSTperSQUAREroot(float cost)
    {
        costPerSquareFoot = cost;
    }
    // Accessor...............
    float getCost() const
    {
        return costPerSquareFoot;
    }
    RoomDImension getRoomSize() const
    {
        return roomSize;
    }

    // return cost
    void returnCost()
    {
        float cost = costPerSquareFoot * roomSize.calArea();
        cout << "Total cost: ";
        cout << cost << endl;
    }

    void displayRoomCarpet()
    {
        cout << "Cost Square per Feet: " << costPerSquareFoot << endl;
        cout << "Following is th Room Size " << endl;
        roomSize.displayObject();
    }
};

int main()
{
    FeetInches length(10, 3);
    FeetInches width(10, 4);

    RoomDImension obj(length, width);

    obj.displayObject();
    RoomCarpet carpet(50, obj);
    cout << endl;
    carpet.displayRoomCarpet();
    carpet.returnCost();

    return 0;
}