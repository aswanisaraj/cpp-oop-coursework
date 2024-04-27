#include <iostream>
#include <cctype>
using namespace std;

class Faculty
{
private:
    int id;
    string firstName;
    string lastName;
    string qualification;
    float salary;

public:
    // Setters...............Mutators
    void setId(int ID)
    {
        if (ID >= 1001 && ID <= 1065)
        {
            id = ID;
        }
    }

    void setfirstName(string str1)
    {
        firstName = str1;
    }

    void setlastName(string str2)
    {
        lastName = str2;
    }

    void setqualification(string str3)
    {
        qualification = str3;
    }

    void setSalary(float Sal)
    {
        if (Sal >= 20000 && Sal <= 100000)
        {
            salary = Sal;
        }
    }

    // Getter............accessors
    int getID() const
    {
        return id;
    }

    string getfirstName() const
    {
        return firstName;
    }

    string getlastName()const
    {
        return lastName;
    }

    string getQualification() const
    {
        return qualification;
    }

    float getSalary() const
    {
        return salary;
    }

    // Default Constructor
    Faculty()
    {

        id = 0;
        firstName = "";
        lastName = "";
        qualification = "";
        salary = -1;
    }

    // Parametrized constructor...............
    Faculty(int a, string b, string c, string d)
    {
        if (a >= 1001 && a <= 1065)
        {
            id = a;
        }
        else
        {
            id = 0;
        }

        firstName = b;
        lastName = c;
        qualification = d;
        salary = -1;
    }

    Faculty(int a, string b, string c)
    {
        if (a >= 1001 && a <= 1065)
        {
            id = a;
        }
        else
        {
            id = 0;
        }

        firstName = b;
        lastName = "";
        qualification = c;
        salary = -1;
    }

    Faculty(int a, string b, string c, string d, float sal)
    {
        if (a >= 1001 && a <= 1065)
        {
            id = a;
        }
        else
        {
            id = 0;
        }

        firstName = b;
        lastName = c;
        qualification = d;
        if (sal >= 20000 && sal <= 100000)
        {
            salary = sal;
        }
        else
        {
            salary = -1;
        }
    }

    // Copy Constructor
    Faculty(const Faculty &obj)
    {
        id = obj.id;
        firstName = obj.firstName;
        lastName = obj.lastName;
        qualification = obj.qualification;
        salary = obj.salary;
    }
    ~Faculty()
    {
        cout << "Destructor Executed........" << endl;
    }

    void set(int a, string b, string c, string d, float sal)
    {
        if (a >= 1001 && a <= 1065)
        {
            id = a;
        }
        else
        {
            id = 0;
        }

        firstName = b;
        lastName = c;
        qualification = d;
        if (sal >= 20000.00 && sal <= 100000.00)
        {
            salary = sal;
        }
        else
        {
            salary = -1;
        }
    }

    void read()
    {
        cout << "Identification Number(1001 to 1065): ";
        cin >> id;
        while (id < 1001 || id > 1065)
        {
            cout << "Enter Valid Id!!!!: ";
            cin >> id;
        }
        cout << "First Name: ";
        cin >> firstName;
        cout << "Last Name: ";
        cin >> lastName;
        cout << "qualification: ";
        cin >> qualification;
        cout << "Salary(20000 to 100000): ";
        cin >> salary;
        while (salary > 100000.00 || salary < 20000.00)
        {
            cout << "Enter valid Salary!!: ";
            cin >> salary;
        }
    }

    void write() const
    {
        cout << "-----------------------------------" << endl;
        cout << "Identification Number: " << id << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "qualification: " << qualification << endl;
        cout << "Salary: " << salary << endl;
    }

    bool isPostGraduate() const
    {
        if (tolower(qualification == "phd") || tolower(qualification == "ms"))
        {
            return true;
        }

        return false;
    }

    float getTakeHomeSalary()
    {

        if (salary >= 20000.00)
        {
            return (salary - (7 * 20000.00) / 100);
        }
        return -1;
    }

    float isJoined() const
    {
        if (salary >= 20000.00)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Faculty Emp1, Emp2;
    cout << "first employee info..............\n";
    Emp1.read();
    cout << endl;
    Emp1.write();
    if (Emp1.isPostGraduate())
    {
        cout << "Faculty is PostGraduate......" << endl;
    }
    else
    {
        cout << "Faculty is not PostGraduate......" << endl;
    }

    if (Emp1.isJoined())
    {
        cout << "Salary is Above 20k...." << endl;
        cout << "-----------------------------------" << endl;
    }
    else
    {
        cout << "Salary is not Above 20k...." << endl;
    }

    cout << "Second Employee info................\n";

    Emp2.read();
    cout << endl;
    Emp2.write();
    if (Emp2.isPostGraduate())
    {
        cout << "Faculty is PostGraduate......" << endl;
    }
    else
    {
        cout << "Faculty is not PostGraduate......" << endl;
    }

    if (Emp2.isJoined())
    {
        cout << "Salary is Above 20k...." << endl;
        cout << "-----------------------------------" << endl;
    }
    else
    {
        cout << "Salary is not Above 20k...." << endl;
    }

    cout << endl;

    return 0;
}
