#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string name;
    int id;
    string department;
    string position;

public:
    // Constructor that accepts name, id, department, and position
    Employee(string empName, int empId, string empDepartment, string empPosition)
        : name(empName), id(empId), department(empDepartment), position(empPosition) {}

    // Constructor that accepts name and id only
    Employee(string empName, int empId)
        : name(empName), id(empId), department(""), position("") {}

    // Default constructor
    Employee() : name(""), id(0), department(""), position("") {}

    // Copy constructor
    Employee(const Employee &other)
        : name(other.name), id(other.id), department(other.department), position(other.position) {}

    // Destructor
    ~Employee()
    {
        cout << "Destructor executed..." << endl;
    }

    // Getters and setters for name
    string getName() const
    {
        return name;
    }

    void setName(const string &empName)
    {
        name = empName;
    }

    // Getters and setters for id
    int getId() const
    {
        return id;
    }

    void setId(int empId)
    {
        id = empId;
    }

    // Getters and setters for department
    string getDepartment() const
    {
        return department;
    }

    void setDepartment(const string &empDepartment)
    {
        department = empDepartment;
    }

    // Getters and setters for position
    string getPosition() const
    {
        return position;
    }

    void setPosition(const string &empPosition)
    {
        position = empPosition;
    }

    // Method to set all information
    void setInfo(string empName, int empId, string empDepartment, string empPosition)
    {
        name = empName;
        id = empId;
        department = empDepartment;
        position = empPosition;
    }

    // Method to get info from user
    void getInfo()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(); // To clear the buffer
        cout << "Enter department: ";
        getline(cin, department);
        cout << "Enter position: ";
        getline(cin, position);
    }

    // Method to display information
    void putInfo() const
    {
        cout << name << "\t" << id << "\t" << department << "\t" << position << endl;
    }
};

int main()
{
    Employee emp1("Naveed Ali", 1230, "Computer Science", "Assistant Professor");
    Employee emp2("Nouman Abdullah", 1231, "Software Engineering", "Lecturer");
    Employee emp3("Naeem Ahmad", 1241, "Computer Science", "Lecturer");
    Employee emp4("Nadia", 1242, "Information Technology", "Assistant Professor");

    // Using default constructor and setInfo method
    Employee emp5;
    emp5.setInfo("John Doe", 1250, "Mathematics", "Professor");

    // Display information of each employee
    cout << "Name           IdNumber          Department        Position" << endl;
    emp1.putInfo();
    emp2.putInfo();
    emp3.putInfo();
    emp4.putInfo();
    emp5.putInfo();
    cout << endl;

    return 0;
}
