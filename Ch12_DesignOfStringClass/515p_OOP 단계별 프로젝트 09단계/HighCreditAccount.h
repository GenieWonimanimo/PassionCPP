/*
 * 파일이름: HighCreditAccount.h
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 5] 파일버전 0.9
 */

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__
#define _CRT_SECURE_NO_WARNINGS

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public Account
{
private:
    int grade;
    int rate;
public:
    HighCreditAccount(int accID, String pName, int balance, int grade);
    virtual int GetRate() const;
    virtual void Deposit(int money, int rate);
    virtual void PrintInfo() const;
};

#endif