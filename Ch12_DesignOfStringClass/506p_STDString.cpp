#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    
    str1 += str2;
    if (str1 == str3)
        cout << "same string" << endl;
    else
        cout << "different string" << endl;
    
    string string4;
    cout << "Input your string: "; cin >> string4;
    cout << "Your string: " << string4 << endl;
    return 0;
}