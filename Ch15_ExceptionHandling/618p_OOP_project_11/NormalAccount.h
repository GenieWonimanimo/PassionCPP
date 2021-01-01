/*
 * 파일이름: NormalAccount.h
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 5] 파일버전 0.92
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include "String.h"

class NormalAccount : public Account
{
private:
    int rate;
public:
    NormalAccount(int accID, String pName, int balance, int rate);
    virtual int GetRate() const;
    virtual void Deposit(int money, int rate);
    virtual void PrintInfo() const;
};

#endif