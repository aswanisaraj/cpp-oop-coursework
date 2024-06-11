#include <iostream>
#include <string>

using namespace std;

class Package
{
private:
    string sender_name;
    string receiver_name;
    string sender_addr;
    string receiver_addr;
    string sender_city;
    string receiver_city;
    float weight; //(in ounces)
    float costPerOunce;

public:
    // default constructor
    Package()
    {
        weight = 0.0;
        costPerOunce = 0.0;
        sender_name = "";
        receiver_name = "";
        sender_addr = "";
        receiver_addr = "";
        sender_city = "";
        receiver_city = "";
    }
    // constructor
    Package(string nameS, string nameR, string addrS, string addrR, string cityS, string cityR, float Weight, float perounceCost)
    {
        if (Weight > 0)
        {
            weight = Weight;
        }

        if (perounceCost > 0)
        {
            costPerOunce = perounceCost;
        }

        sender_name = nameS;
        receiver_name = nameR;
        sender_addr = addrS;
        receiver_addr = addrR;
        sender_city = cityS;
        receiver_city = cityR;
    }

    // Getters
    string getSenderName() const { return sender_name; }
    string getReceiverName() const { return receiver_name; }
    string getSenderAddress() const { return sender_addr; }
    string getReceiverAddress() const { return receiver_addr; }
    string getSenderCity() const { return sender_city; }
    string getReceiverCity() const { return receiver_city; }
    float getWeight() const { return weight; }
    float getCostPerOunce() const { return costPerOunce; }

    // member function
    virtual float calculateCost() const
    {
        return weight * costPerOunce;
    }
};

// subclass
class TwoDayPackage : public Package
{
private:
    float flatFee;

public:
    // constructor
    TwoDayPackage(string nameS, string nameR, string addrS, string addrR, string cityS, string cityR, float Weight, float perounceCost, float FlatFee)
        : Package(nameS, nameR, addrS, addrR, cityS, cityR, Weight, perounceCost)
    {
        if (FlatFee > 0)
        {
            flatFee = FlatFee;
        }
    }

    float calculateCost() const override
    {
        return Package::calculateCost() + flatFee;
    }
};

// second subclass
class OvernightPackage : public Package
{
private:
    float feePerOunce;

public:
    // constructor
    OvernightPackage(string nameS, string nameR, string addrS, string addrR, string cityS, string cityR, float Weight, float perounceCost, float FeePerOunce)
        : Package(nameS, nameR, addrS, addrR, cityS, cityR, Weight, perounceCost)
    {
        if (FeePerOunce > 0)
        {
            feePerOunce = FeePerOunce;
        }
    }

    float calculateCost() const override
    {
        return Package::calculateCost() + (getWeight() * feePerOunce);
    }
};

int main()
{
    // creating objects of the classes
    Package p1("Saraj", "Arsalan", "Jeejal house", "Amrani house", "Mithi", "Hyderabad", 53.9, 1.09);
    TwoDayPackage p2("Saraj", "Arsalan", "Jeejal house", "Amrani house", "Mithi", "Hyderabad", 50.9, 2.09, 10.0);
    OvernightPackage p3("Saraj", "Arsalan", "Jeejal house", "Amrani house", "Mithi", "Hyderabad", 50.9, 2.09, 0.5);

    cout << "Package cost: " << p1.calculateCost() << endl;
    cout << "TwoDayPackage cost: " << p2.calculateCost() << endl;
    cout << "OvernightPackage cost: " << p3.calculateCost() << endl;

    return 0;
}
