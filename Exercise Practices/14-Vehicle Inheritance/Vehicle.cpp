#include <iostream>

using namespace std;

class Moving_Van
{
protected:
    float payload;
    float mpg;

public:
    // Default constructor
    Moving_Van() : payload(0.0), mpg(0.0) {}

    // Parameterized constructor
    Moving_Van(float Payload, float MPG) : payload(Payload), mpg(MPG) {}

    // Copy constructor
    Moving_Van(const Moving_Van &obj) : payload(obj.payload), mpg(obj.mpg) {}

    // Member function
    virtual void initialize(float Payload, float MPG)
    {
        payload = Payload;
        mpg = MPG;
    }

    float efficiency(float weight) const
    {
        return payload / (payload + weight);
    }

    float cost_per_ton(float fuel_cost) const
    {
        return fuel_cost / (payload / 2000.0);
    }
};

class Driver
{
protected:
    float hourly_pay;
    float weight;

public:
    // Default constructor
    Driver() : hourly_pay(0.0), weight(0.0) {}

    // Parameterized constructor
    Driver(float Hourly_pay, float Weight) : hourly_pay(Hourly_pay), weight(Weight) {}

    // Copy constructor
    Driver(const Driver &obj) : hourly_pay(obj.hourly_pay), weight(obj.weight) {}

    // Member functions
    virtual void initialize(float hourly_pay, float weight)
    {
        this->hourly_pay = hourly_pay;
        this->weight = weight;
    }

    float cost_per_mile() const
    {
        return hourly_pay / 55.0;
    }

    float drivers_weight() const
    {
        return weight;
    }
};

class Driven_Truck : public Moving_Van, public Driver
{
public:
    // Default constructor
    Driven_Truck() : Moving_Van(), Driver() {}

    // Parameterized constructor
    Driven_Truck(float payload, float mpg, float hourly_pay, float weight)
        : Moving_Van(payload, mpg), Driver(hourly_pay, weight) {}

    // Copy constructor
    Driven_Truck(const Driven_Truck &obj)
        : Moving_Van(obj), Driver(obj) {}

    // Initialize function
    void initialize(float payload, float mpg, float hourly_pay, float weight)
    {
        this->payload = payload;
        this->mpg = mpg;
        this->hourly_pay = hourly_pay;
        this->weight = weight;
    }

    float cost_per_full_day(float cost_of_gas) const
    {
        return ((8.0 * hourly_pay) + (8.0 * cost_of_gas * 55.0)) / mpg;
    }

    float total_weight() const
    {
        return payload + weight;
    }
};

int main()
{
    // Creating an object named chuck_ford of the Driven_Truck class
    Driven_Truck chuck_ford;

    // Initialize the chuck_ford object using the initialize method of the Driven_Truck class
    chuck_ford.initialize(5000.0f, 15.0f, 20.0f, 200.0f); // Example values

    // Display the efficiency of the chuck_ford object
    float van_weight = 10000.0f; // Example van weight
    cout << "Efficiency: " << chuck_ford.efficiency(van_weight) << endl;

    // Display the cost per mile of the chuck_ford object
    cout << "Cost per mile: " << chuck_ford.cost_per_mile() << endl;

    // Display the cost per full day of the chuck_ford object
    float cost_of_gas = 3.50f; // Example cost of gas per gallon
    cout << "Cost per full day: " << chuck_ford.cost_per_full_day(cost_of_gas) << endl;

    // Display the total weight of the chuck_ford object
    cout << "Total weight: " << chuck_ford.total_weight() << endl;

    // Testing constructors
    // Default constructor
    Driven_Truck default_truck;
    cout << "Default constructor total weight: " << default_truck.total_weight() << endl;

    // Parameterized constructor
    Driven_Truck param_truck(4000.0f, 12.0f, 25.0f, 150.0f);
    cout << "Parameterized constructor total weight: " << param_truck.total_weight() << endl;

    // Copy constructor
    Driven_Truck copy_truck(param_truck);
    cout << "Copy constructor total weight: " << copy_truck.total_weight() << endl;

    return 0;
}
