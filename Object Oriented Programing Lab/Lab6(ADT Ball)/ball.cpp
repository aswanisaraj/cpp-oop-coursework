#include <iostream>
using namespace std;

class Ball
{
    int id;
    string bname;
    int quantity;
    float price;

public:
    // Parametrized Constructor...............
    Ball(int Id, string name, int Quantity, float Price)
    {

        if (Id > 0)
        {
            id = Id;
        }
        else
        {
            id = 0;
        }

        if (Quantity > 0)
        {
            quantity = Quantity;
        }
        else
        {
            quantity = 0;
        }

        if (price > 0)
        {
            Price = price;
        }
        else
        {
            price = 0;
        }

        bname = name;
    }

    Ball(int Id, string name, int Quantity)
    {

        if (Id > 0)
        {
            id = Id;
        }
        else
        {
            id = 0;
        }

        if (Quantity > 0)
        {
            quantity = Quantity;
        }
        else
        {
            quantity = 0;
        }

        price = 0;
        bname = name;
    }

    Ball(int Id, string name, float Price)
    {

        if (Id > 0)
        {
            id = Id;
        }
        else
        {
            id = 0;
        }

        if (price > 0)
        {
            Price = price;
        }
        else
        {
            price = 0;
        }
        quantity = 0;
        bname = name;
    }
    // Copy constructor
    Ball(const Ball &obj)
    {
        id = obj.id;
        bname = obj.bname;
        quantity = obj.quantity;
        price = obj.price;
    }

    ~Ball()
    {
        cout << "Destructor Executed...." << endl;
    }

    // Mutators.....................
    void setId(int Id)
    {

        if (Id > 0)
        {
            id = Id;
        }
    }

    void setName(string name)
    {
        bname = name;
    }

    void setQuantity(int Quantity)
    {
        if (Quantity > 0)
        {
            quantity = Quantity;
        }
    }

    void setPrice(float Price)
    {
        if (Price > 0)
        {
            price = Price;
        }
    }

    // Accessors.......
    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return bname;
    }

    int getQuantity() const
    {
        return quantity;
    }

    float getPrice() const
    {
        return price;
    }

    // Member Functions
    void setBall(int Id, string name, int Quantity, float Price)
    {

        if (Id > 0)
        {
            id = Id;
        }
        else
        {
            id = 0;
        }

        if (Quantity > 0)
        {
            quantity = Quantity;
        }
        else
        {
            quantity = 0;
        }

        if (price > 0)
        {
            Price = price;
        }
        else
        {
            price = 0;
        }

        bname = name;
    }

    void getBall()
    {

        cout << "Enter Id((Greater than 0): ";
        cin >> id;
        while (id < 0)
        {
            cout << "Enter Valid Id: ";
            cin >> id;
        }

        cout << "Enter Brand Name: ";
        cin >> bname;

        cout << "Enter Quantity((Greater than 0): ";
        cin >> quantity;
        while (quantity < 0)
        {
            cout << "\nEnter Valid quantity: ";
            cin >> quantity;
        }

        cout << "Enter price((Greater than 0): ";
        cin >> price;
        while (price < 0)
        {
            cout << "\nEnter Valid price: ";
            cin >> price;
        }
    }

    void putBall() const
    {
        cout << "____Ball Info_____" << endl;
        cout << "Ball Id:" << id << endl;
        cout << "Ball Brand Name:" << bname << endl;
        cout << "Ball Quantity:" << quantity << endl;
        cout << "Ball Price:" << price << endl;
    }

    float getTotalPrice() const
    {
        float totalPrice;
        if (quantity >= 1)
        {
            totalPrice = (quantity)*price;
            return totalPrice;
        }

        return 0;
    }

    bool isSame(const Ball &obj) const
    {
        if (id == obj.id && quantity == obj.quantity && price == obj.price && bname == obj.bname)
        {
            return 1;
        }
        return 0;
    }

    void updateName(Ball arr[], int size) const
    {
        for (int i = 0; i < size; i++)
        {
            if (id == arr[i].id)
            {
                arr[i].bname = bname;
            }
        }
    }

    Ball getMaxPrice(const Ball balls[], int size) const
    {
        int max = 0, index = 0;
        for (int i = 0; i < size; i++)
        {
            if (balls[i].price > max)
            {
                max = balls[i].price;
                index = i;
            }
        }
        return balls[index];
    }

    float getAveragePrice(Ball arr[], int size) const
    {
        float average, sum;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].price <= 50)
            {
                sum = +arr[i].price;
            }
            average = sum / size;
        }
        return average;
    }
};

int main()
{
    Ball obj(1, "shine", 3, 100.0);
    Ball obj1 = obj; // Copy constructor checking.............
    Ball r(2, "CA", 4, 150.0);

    // mutators Checking..................
    r.setId(1);
    r.setName("Osaka");
    r.setQuantity(10);
    r.setPrice(100.0);

    // Getters checking.............
    cout << r.getId() << endl;
    cout << r.getName() << endl;
    cout << r.getQuantity() << endl;
    cout << r.getPrice() << endl;

    // r.getBall();
    r.putBall();
    cout << r.getTotalPrice() << endl;
    cout << r.isSame(obj) << endl;

    Ball arr[3] = {Ball(1, "AA", 10, 70.0), Ball(2, "BB", 5, 100.0), Ball(1, "CC", 15, 50.0)};

    r.updateName(arr, 3);
    r.getMaxPrice(arr, 3);
    r.getAveragePrice(arr, 3);

    // cout << r.getAveragePrice() << endl;

    return 0;
}
