#include "iostream"
#include "vector"

using namespace std;

class NumDays
{
private:
    double hours;
    double days;

public:
    void SetVaraibles()
    {
        days += (hours / 8.0);
    }
    // Default constructor........
    NumDays() : days{0}, hours{0}
    {
    }

    // Constructor.......
    NumDays(double hour)
    {
        this->hours = hour;
        this->days = 0;
        SetVaraibles();
    }

    void setHours(double hour)
    {
        this->hours = hour;
        SetVaraibles();
    }

    double getHours()
    {
        return hours;
    }

    double getDays()
    {
        return days;
    }

    // Operator overloaded...............
    NumDays operator+(const NumDays &obj)
    {

        NumDays temp;
        temp.hours = this->hours + obj.hours;

        return temp;
    }

    // Operator overloaded...............
    NumDays operator+(const NumDays &obj)
    {

        NumDays temp;
        temp.hours = this->hours - obj.hours;

        return temp;
    }
    // Prefix
    NumDays operator++()
    {

        ++hours;
        SetVaraibles();
        return *this;
    }

    // Prefix...

    NumDays operator--()
    {

        --hours;
        SetVaraibles();
        return *this;
    }

    // postfix
    NumDays operator++(int)
    {
        NumDays temp;
        hours++;
        SetVaraibles();
        return temp;
    }

    // postfix
    //  postfix
    NumDays operator++(int)
    {
        NumDays temp;
        hours--;
        SetVaraibles();
        return temp;
    }
};
class TimeOff
{
private:
    string employeeName;
    int employeeId;
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;

public:
    // Constructor
    TimeOff(const string &name, int id, double maxSickHours, double sickTakenHours,
            double maxVacationHours, double vacTakenHours, double maxUnpaidHours,
            double unpaidTakenHours) : employeeName(name), employeeId(id),
                                       maxSickDays(maxSickHours), sickTaken(sickTakenHours),
                                       maxVacation(maxVacationHours), vacTaken(vacTakenHours),
                                       maxUnpaid(maxUnpaidHours), unpaidTaken(unpaidTakenHours) {}

    // Member functions to set and get employee information
    void setEmployeeInfo(const string &name, int id)
    {
        employeeName = name;
        employeeId = id;
    }

    string getEmployeeName() const
    {
        return employeeName;
    }

    int getEmployeeId() const
    {
        return employeeId;
    }

    // Member functions to set and get sick leave
    void setSickLeave(double maxSickHours, double sickTakenHours)
    {
        maxSickDays.setHours(maxSickHours);
        sickTaken.setHours(sickTakenHours);
    }

    NumDays getMaxSickDays() const
    {
        return maxSickDays;
    }

    NumDays getSickTaken() const
    {
        return sickTaken;
    }

    // Member functions to set and get vacation
    void setVacation(double maxVacationHours, double vacTakenHours)
    {
                
        maxVacation.setHours(maxVacationHours);
        vacTaken.setHours(vacTakenHours);
    }

    NumDays getMaxVacation() const
    {
        return maxVacation;
    }

    NumDays getVacTaken() const
    {
        return vacTaken;
    }

    // Member functions to set and get unpaid time off
    void setUnpaid(double maxUnpaidHours, double unpaidTakenHours)
    {
        maxUnpaid.setHours(maxUnpaidHours);
        unpaidTaken.setHours(unpaidTakenHours);
    }

    NumDays getMaxUnpaid() const
    {
        return maxUnpaid;
    }

    NumDays getUnpaidTaken() const
    {
        return unpaidTaken;
    }
};

int main()
{

    return 0;
}