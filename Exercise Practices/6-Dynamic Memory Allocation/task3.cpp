#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char *reverseCase(const char *str)
{
    if (str == nullptr || *str == '\0')
    {
        return nullptr;
    }

    size_t len = strlen(str);
    char *result = new char[len + 1];

    for (size_t i = 0; i < len; ++i)
    {
        if (isupper(str[i]))
        {
            result[i] = tolower(str[i]);
        }
        else if (islower(str[i]))
        {
            result[i] = toupper(str[i]);
        }
        else
        {
            result[i] = str[i];
        }
    }

    result[len] = '\0';
    return result;
}

int main()
{
    const char *str1 = "Hello, four Score And Seven years Ago";
    const char *str2 = "Bsf21mXyZ, pU. LahoRE";

    char *reversedStr1 = reverseCase(str1);
    char *reversedStr2 = reverseCase(str2);

    if (reversedStr1 != nullptr)
    {
        cout << "Reversed string 1: " << reversedStr1 << endl;
        delete[] reversedStr1;
    }
    else
    {
        cout << "Empty string 1" << endl;
    }

    if (reversedStr2 != nullptr)
    {
        cout << "Reversed string 2: " << reversedStr2 << endl;
        delete[] reversedStr2;
    }
    else
    {
        cout << "Empty string 2" << endl;
    }

    return 0;
}