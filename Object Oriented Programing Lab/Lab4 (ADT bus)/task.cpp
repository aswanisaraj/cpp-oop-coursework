#include <iostream>

using namespace std;

class Bus
{
    string BusNumber;
    string owner;
    int capacity;

public:
    // default construtor.................
    Bus()
    {
        BusNumber = "";
        owner = "";
        capacity = 0;
    }

    // parametrized  construtor..................
    Bus(string License_number, string owner)
    {
        BusNumber = License_number;
        owner = owner;
        capacity = 0;
    }

    // Copy constructor....................
    Bus(const Bus &obj)
    {
        this->BusNumber = obj.BusNumber;
        this->owner = obj.owner;
        this->capacity = obj.capacity;
    }

    // desructor..........................
    ~Bus()
    {
        cout << "Destructor Executed..." << endl;
    }

    // Setter..........................
    void SetBusNumber(string str1)
    {
        BusNumber = str1;
    }
    void SetOwner(string str2)
    {
        owner = str2;
    }

    void SetCapacity(int cap)
    {
        capacity = cap;
    }

    string GetBusNumber()
    {
        return BusNumber;
    }

    string getOwner()
    {
        return owner;
    }

    int GetCapacity()
    {
        return capacity;
    }

    // member functions............................

    void SetBus(string b_num, string owner, int cap)
    {
        BusNumber = b_num;
        owner = owner;
        capacity = cap;
    }

    void GetBus()
    {
        cout << "Enter bus Number: ";
        getline(cin, BusNumber);

        cout << "Bus Owner name: ";
        getline(cin, owner);

        cout << "Bus Capacity: ";
        cin >> capacity;
        cin.ignore();
    }

    void print()
    {
        cout << "Bus Number: ";
        cout << "\tOwner name: ";
        cout << "\tBus Capacity: ";
        cout << "\n";
    }

    void PutBus()
    {

        cout << BusNumber << "\t\t";
        cout << owner << "\t\t";
        cout << capacity;

        cout << "\n";
    }

    void book()
    {
        capacity += 1;
    }

    void cancel()
    {
        capacity -= 1;
    }
};

int main()
{

    Bus Obj1, Obj2, Obj3, Obj4, Obj5;

    Obj1.GetBus();
    Obj2.GetBus();
    Obj3.GetBus();
    // Obj4.GetBus();
    // Obj4.GetBus();

    Obj1.print();

    Obj1.PutBus();
    Obj2.PutBus();
    Obj3.PutBus();
    // Obj4.PutBus();
    // Obj5.PutBus();

    return 0;
}
