#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename = "input.txt";
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    int rollNumber;
    int quizScores[10];

    while (file >> rollNumber)
    {
        for (int i = 0; i < 10; ++i)
        {
            file >> quizScores[i];
        }

        
        int highest1 = -1; 
        int highest2 = -1; 

        for (int i = 0; i < 10; ++i)
        {
            if (quizScores[i] > highest1)
            {
                highest2 = highest1; 
                highest1 = quizScores[i]; 
            }
            else if (quizScores[i] > highest2)
            {
                highest2 = quizScores[i]; 
            }
        }

        cout << rollNumber << " " << highest2 << " " << highest1 << endl;
    }

    file.close();
    
    
    return 0;
    
    
    }

    return 0;
}
