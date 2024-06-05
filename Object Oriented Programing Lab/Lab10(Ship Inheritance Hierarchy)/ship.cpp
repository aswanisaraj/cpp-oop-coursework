#include <iostream>
#include <string>

using namespace std;

// base class.............
class ship
{
private:
    string ship_name;
    string ship_year;

public:
    // constructer..............

    ship() : ship_name(""), ship_year("")
    {
    }

    ship(string name, string year) : ship_name(name), ship_year(year)
    {
    }

    // mutators...............
    void setName(string name)
    {
        ship_name = name;
    }

    void setYear(string year)
    {
        ship_year = year;
    }

    // Accessors................
    string getName()
    {
        return ship_name;
    }

    string getYear()
    {
        return ship_year;
    }

    // member Function.........

    virtual void print()
    {
        cout << "Ship Name: " << ship_name << endl;
        cout << "Ship built Year: " << ship_year << endl;
    }
};

// subclass..........
class CruiseShip : public ship
{
private:
    int max_pass;

public:
    // constructer..............

    CruiseShip(string name, string year, int max) : ship(name, year), max_pass(max)
    {
    }

    // getter........
    int getMaxPass()
    {
        return max_pass;
    }
    // setter........
    void setMaxPass(int max)
    {
        max_pass = max;
    }

    // member function......
    void print() override
    {
        ship::print();
        cout << "Max Passenger: " << max_pass << endl;
    }
};

class CargoShip : public ship
{
private:
    int Cargo_cap;

public:
    // Constructor................
    CargoShip(string name, string year, int cap) : ship(name, year), Cargo_cap(cap)
    {
    }

    // setter............
    void setCargoCap(int cap)
    {
        Cargo_cap = cap;
    }

    // getter...........
    int getCargoCap()
    {
        return Cargo_cap;
    }

    // Override print function
    void print() override
    {
        cout << "Cargo Ship Name: " << getName() << endl;
        cout << "Cargo Capacity: " << Cargo_cap << " tons" << endl;
    }
};

class BattleShip : public ship
{
private:
    int t_missiles;

public:
    BattleShip(string name, string year, int missiles) : ship(name, year), t_missiles(missiles)
    {
    }
    // setter............
    void setMissiles(int missiles)
    {
        t_missiles = missiles;
    }
    // getter..........
    int getMissiles()
    {
        return t_missiles;
    }

    // Override print function
    void print() override
    {
        cout << "Battle Ship Name: " << getName() << endl;
        cout << "Total Missiles: " << t_missiles << endl;
    }
};

// Implementation of main function......
int main()
{
    ship *arr = new ship[4];

    arr[0] = ship("Ship", "2000");
    arr[1] = CruiseShip("CruiseShip", "2001", 1000); // Polymorphism
    arr[2] = CargoShip("CargoShip", "2003", 2000);  // Polymorphism
    arr[3] = BattleShip("BattleShip", "2002", 2500);

    for (int i = 0; i < 4; ++i)
    {
        arr[i].print();
        cout << endl;
    }

    delete[] arr; // delete memmory
    return 0;
}