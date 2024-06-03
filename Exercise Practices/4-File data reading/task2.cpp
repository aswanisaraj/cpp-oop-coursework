#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string myfile = "input.txt";

    ifstream file(myfile);

    if (file.is_open())
    {
        int rollNumber, quizScore;
        int maxScore = -1;

        while (file >> rollNumber)
        {
            maxScore = -1;
            cout << rollNumber << " ";
            for (int i = 0; i < 10; ++i)
            {
                file >> quizScore;
                cout << quizScore << " ";
                if (quizScore > maxScore)
                {
                   maxScore = quizScore;
                }
            }
            cout << maxScore << endl;
        }
    }
    else
    {
        cerr << "Error opening file: " << myfile << endl;
    }

    return 0;
}
