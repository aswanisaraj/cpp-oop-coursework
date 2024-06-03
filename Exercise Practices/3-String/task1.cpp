#include <iostream>
#include <algorithm>
using namespace std;

void palindrome(string S)
{
    string T;
    T = S;

    reverse(T.begin(), T.end());

    if (S == T)
    {
        cout << "The entered string is a palindrome.";
    }
    else
    {
        cout << "The entered string is not a palindrome.";
    }

    cout <<"\n";
}

int main()
{
    string S;
    cout<<"Enter a string: ";
    cin >> S;
    palindrome(S);
    return 0;
}