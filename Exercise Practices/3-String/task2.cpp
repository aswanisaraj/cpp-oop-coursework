#include <iostream>
#include <string>
using namespace std;

int countWords(const string S)
{
    int count = 0;
    int n = S.length();
    bool inWord = false; // Flag to track if currently inside a word
    for (int i = 0; i < n; i++)
    {
        if (S[i] == ' ')
        {
            // If a space is encountered and the flag is set (indicating we're in a word),
            // increment count and reset the flag
            if (inWord) 
            {
                count++;
                inWord = false;
            }
        }
        else
        {
            // If a non-space character is encountered, set the flag to indicate we're in a word
            inWord = true;
        }
    }

    // Increment count if the last character is not a space (to include the last word)
    if (inWord)
        count++;

    return count;
}



int main()
{
    string S;
    cout << "Enter a string: ";
    getline(cin, S);
    countWords(S);
    int count = countWords(S);
    
    
    return 0;
    
   }
    cout << "Number of words:" << count << endl;
    return 0;
}
