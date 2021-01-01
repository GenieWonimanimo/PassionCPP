#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char* str)
{
    int len = strlen(str);
    int num = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            throw str[i];
        num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (0 - '0')));
    }
    return num;
}

int main(void)
{
    char str1[100];
    char str2[100];

    while (1)
    {
        cout << "Input two numbers: ";
        cin >> str1 >> str2;

        try
        {
            cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
            break;
        }
        catch(char ch)
        {
            cout << "Character " << ch << " was Inputted" << endl;
            cout << "ReEnter your numbers" << endl;
        }
    }
    cout << "terminate" << endl;
    return 0;
}