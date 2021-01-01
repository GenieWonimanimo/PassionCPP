/*
 * 파일이름: String.h
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 5] 파일버전 0.1
 */
#ifndef __STRING_H__
#define __STRING_H__
#define _CRT_SECURE_NO_WARNINGS

#include "BankingCommonDecl.h"

class String
{
private:
    char* str;
    int len;
public:
    String();
    String(const char* str);
    String(const String& strObj);
    String& operator=(const String& strObj);
    String operator+(const String& strObj);
    String& operator+=(const String& strObj);
    bool operator==(const String& strObj);
    friend ostream& operator<<(ostream& os, const String& strObj);
    friend istream& operator>>(istream& is, String& strObj);
    ~String();
};


#endif