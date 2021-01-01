/*
 * 파일이름: String.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 5] 파일버전 0.12
 */

#include "BankingCommonDecl.h"
#include "String.h"

String::String()
{
	str = NULL;
	len = 0;
}
String::String(const char* str)
{
    len = strlen(str);
    this->str = new char[len + 1];
    strcpy(this->str, str);
}
String::String(const String& strObj)
{
    len = strObj.len;
    str = new char[len + 1];
    strcpy(str, strObj.str);
}

String& String::operator=(const String& strObj)
{
    if (str != NULL)
        delete[]str;
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
    delete[]_str;
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
        delete[]str;
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

String::~String()
{
    if (str != NULL)
        delete[]str;
}