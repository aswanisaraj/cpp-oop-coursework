#include <iostream>
#include <fstream>
#include <sstream> // for stringstream
using namespace std;

int main()
{
    string str;

    cout << "Roll No  Name   CGPA" << endl;
    cout << "----------------------" << endl;

    string file = "students.txt";
    ifstream infile(file);

    if (!infile.is_open())
    {
        cerr << "Failed to open file " << file << endl;
    }
    else
    {
        while (getline(infile, str))
        {
            stringstream ss(str);
            string rollNo, name, cgpa;
            ss >> rollNo >> name >> cgpa;
            cout << rollNo << "\t" << name << "\t" << cgpa << endl;
        }
        infile.close();
    }

    return 0;
}
