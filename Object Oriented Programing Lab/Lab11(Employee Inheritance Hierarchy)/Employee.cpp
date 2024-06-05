#include <iostream>
#include <string>

using namespace std;

// Base class
class Employee
{
private:
    string firstname;
    string lastname;
    string SSN;

public:
    // Parametrized constructor.................
    Employee(string FirstName, string LastName, string ssn) : firstname(FirstName), lastname(LastName), SSN(ssn)
    {
    }

    // setter..........
    void setFirstName(string name)
    {
        firstname = name;
    }

    void setLastName(string name)
    {
        lastname = name;
    }

    void setSSN(string ssn)
    {
        SSN = ssn;
    }

    // getters.........
    string getFirstName()
    {
        return firstname;
    }
    string getLastName()
    {
        return lastname;
    }
    string getSSN()
    {
        return SSN;
    }
    // member function
    virtual void print() = 0;      // pure virtual
    virtual double earnings() = 0; // pure virtual
};

// Subclass.....
class SalariedEmployee : public Employee
{
private:
    double WeeklySalary;

public:
    SalariedEmployee(string FirstName, string LastName, string ssn) : Employee(FirstName, LastName, ssn), WeeklySalary(0)
    {
    }

    // getter.....
    void setWeeklySalary(double salary)
    {
        WeeklySalary = salary;
    }

    // setter.....
    double getWeeklySalary()
    {
        return WeeklySalary;
    }

    // member function

    void print()
    {
        cout << "Full Name: ";
        cout << getFirstName() << " " << getLastName() << endl;
        cout << "Social Security number: " << getSSN() << endl;
        cout << "Weekly Salary: " << getWeeklySalary() << endl;
    }

    double earnings()
    {

        return getWeeklySalary();
    }
};

// subclass
class HourlyEmployee : public Employee
{
private:
    double wage;
    double hours;

public:
    HourlyEmployee(string FirstName, string LastName, string ssn) : Employee(FirstName, LastName, ssn), wage(0), hours(0)
    {
    }

    // setter....
    void setWage(double wages)
    {
        wage = wages;
    }
    void setHours(double hour)
    {
        hours = hour;
    }

    // getter

    double getWage()
    {
        return wage;
    }
    double getHours()
    {
        return hours;
    }

    // member function
    void print()
    {
        cout << "Full Name: ";
        cout << getFirstName() << " " << getLastName() << endl;
        cout << "Social Security number: " << getSSN() << endl;
        cout << "Wages: " << getWage() << endl;
        cout << "Hours: " << getHours() << endl;
    }

    double earnings()
    {

        return (hours * wage);
    }
};

// Subclass
class CommissionEmployee : public Employee
{
private:
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(string FirstName, string LastName, string ssn, double gross, double commission) : Employee(FirstName, LastName, ssn), grossSales(0), commissionRate(0)
    {
    }

    // setter
    void setgrossSales(double gross)
    {
        grossSales = gross;
    }

    void setcommissionRate(double rate)
    {
        commissionRate = rate;
    }

    // getter
    double getgrossSales()
    {
        return grossSales;
    }
    double getcommissionRate()
    {
        return commissionRate;
    }

    // member function
    void print()
    {
        cout << "Full Name: ";
        cout << getFirstName() << " " << getLastName() << endl;
        cout << "Social Security number: " << getSSN() << endl;
        cout << "Gross Sales: " << getgrossSales() << endl;
        cout << "Commission Rate: " << getcommissionRate() << endl;
    }

    double earnings()
    {
        return (commissionRate * grossSales);
    }
};
// subclass

class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee(string FirstName, string LastName, string ssn, double gross, double commission) : CommissionEmployee(FirstName, LastName, ssn, gross, commission), baseSalary(0)
    {
    }

    // setter
    void setbaseSalary(double salary)
    {
        baseSalary = salary;
    }
    // getter
    double getbaseSalary()
    {
        return baseSalary;
    }

    void print()
    {
        CommissionEmployee::print();
        cout << "Base Salary: " << getbaseSalary() << endl;
    }

    double earnings()
    {
        return ((CommissionEmployee::earnings()) + baseSalary);
    }
};

int main()
{
    // Creating objects

    SalariedEmployee salariedEmp("Mr", "Zohaib", "1111");
    HourlyEmployee hourlyEmp("Hanzala", "Khalid", "2222");
    CommissionEmployee commissionEmp("Aaqil", "Irshad", "3333", 0.0, 0.0);
    BasePlusCommissionEmployee basePlusCommissionEmp("Iqra", "Aziz", "4444", 0.0, 0.0);

    salariedEmp.setWeeklySalary(500.9);
    hourlyEmp.setWage(30);
    hourlyEmp.setHours(13);
    commissionEmp.setcommissionRate(23);
    commissionEmp.setgrossSales(150);
    basePlusCommissionEmp.setgrossSales(3);
    basePlusCommissionEmp.setbaseSalary(100);
    basePlusCommissionEmp.setcommissionRate(15);

    Employee *eptr[4];
    eptr[0] = &salariedEmp;
    eptr[1] = &hourlyEmp;
    eptr[2] = &commissionEmp;
    eptr[3] = &basePlusCommissionEmp;

    for (int i = 0; i < 4; ++i)
    {
        eptr[i]->print();
        cout << "Earnings: " << eptr[i]->earnings() << endl;
        cout << endl;
    }

    return 0;
}
