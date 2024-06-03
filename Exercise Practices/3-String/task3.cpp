#include <iostream>
#include <string>
#include <cctype> // For toupper and tolower
using namespace std;

void countVowels(const string& input) {
    int count[5] = {0}; // Array to store the count of each vowel (a, e, i, o, u)

    // Iterate through each character in the sentence
    for (char ch : input) {
        ch = tolower(ch); // Convert character to lowercase for easier comparison

        // Check if the character is a vowel and update the count accordingly
        switch (ch) {
            case 'a':
                count[0]++;
                break;
            case 'e':
                count[1]++;
                break;
            case 'i':
                count[2]++;
                break;
            case 'o':
                count[3]++;
                break;
            case 'u':
                count[4]++;
                break;
        }
    }

    // Display the count of each vowel
    cout << "Count of 'a's: " << count[0] << endl;
    cout << "Count of 'e's: " << count[1] << endl;
    cout << "Count of 'i's: " << count[2] << endl;
    cout << "Count of 'o's: " << count[3] << endl;
    cout << "Count of 'u's: " << count[4] << endl;
}

int main() {
    string sentence;

    // Input sentence from the user
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Call the function to count vowels
    countVowels(sentence);
    
    return 0;
    
    }

    return 0;
}
