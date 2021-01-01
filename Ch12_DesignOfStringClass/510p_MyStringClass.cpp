#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* str;
    int len;
public:
    String()
    {
        str = NULL;
        len = 0;
    }
    String(const char* str)
    {
        len = strlen(str);
        this->str = new char[len + 1];
        strcpy(this->str, str);
    }
    String(const String& strObj)
    {
        len = strObj.len;
        str = new char[len + 1];
        strcpy(str, strObj.str);
    }
    String& operator=(const String& strObj);
    String operator+(const String& strObj);
    String& operator+=(const String& strObj);
    bool operator==(const String& strObj);
    friend ostream& operator<<(ostream& os, const String& strObj);
    friend istream& operator>>(istream& is, String& strObj);
    ~String()
    {
        if (str != NULL)
            delete []str;
    }
};

String& String::operator=(const String& strObj)
{
    if (str != NULL)
        delete []str;
    len = strObj.len;
    str = new char[len + 1];
    strcpy(str, strObj.str);
    return *this;
}
String String::operator+(const String& strObj)
{
    char* _str = new char[len + strObj.len + 1];
    strcpy(_str, str); strcat(_str, strObj.str);
    String res(_str);
    delete []_str;
    return res;
}
String& String::operator+=(const String& strObj)
{
    /*
    //it can be used, but it create additional obj
    *this = *this + strObj;
    return *this;
    */
    len = len + strObj.len;
    char* _str = new char[len + 1];
    strcpy(_str, str); strcat(_str, strObj.str);

    if (str != NULL)
        delete []str;
    str = _str;
    return *this;
}
bool String::operator==(const String& strObj)
{
    return !strcmp(str, strObj.str);
}
ostream& operator<<(ostream& os, const String& strObj)
{
    os << strObj.str;
    return os;
}
istream& operator>>(istream& is, String& strObj)
{
    char _str[100];
    is >> _str;
    strObj = String(_str);
    return is;
}

int main(void)
{
    String str1 = "I like ";
    String str2 = "string class";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "same string" << endl;
    else
        cout << "different string" << endl;
    
    String str4;
    cout << "Input your string: "; cin >> str4;
    cout << "Your string: " << str4 << endl; 
    return 0;
}