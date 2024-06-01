#include <iostream>
using namespace std;

int charges(int days, double daily_rate, double med_chagres, double hs_charges)
{

    return (days * daily_rate) + med_chagres + hs_charges;
}

int charges(double med_chagres, double hs_charges)
{

    return (med_chagres + hs_charges);
}

int main()
{
    char patientType;
    int days;
    double dailyRate, medicationCharges, servicesCharges;

    cout << "Enter patient type (I for in-patient, O for out-patient): ";
    cin >> patientType;

    if (patientType == 'I' || patientType == 'i')
    {
        cout << "Enter number of days spent in the hospital: ";
        cin >> days;
        cout << "Enter daily rate: ";
        cin >> dailyRate;
        cout << "Enter hospital medication charges: ";
        cin >> medicationCharges;
        cout << "Enter charges for hospital services: ";
        cin >> servicesCharges;

        double totalCharges = charges(days, dailyRate, medicationCharges, servicesCharges);
        cout << "Total charges: " << totalCharges << endl;
    }
    else if (patientType == 'O' || patientType == 'o')
    {
        cout << "Enter hospital medication charges for out-patient: ";
        cin >> medicationCharges;
        cout << "Enter charges for hospital services for out-patient: ";
        cin >> servicesCharges;

        double totalCharges = charges(medicationCharges, servicesCharges);
        cout << "Total charges: " << totalCharges << endl;
    }
    else
    {
       
      
        cout << "Invalid input! Please enter 'I' or 'O'."<< endl;
        
        
    }

    return 0;
}