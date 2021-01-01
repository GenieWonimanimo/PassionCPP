/*
 * 파일이름: Account.h
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 3] 파일버전 0.8
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#define _CRT_SECURE_NO_WARNINGS
class Account
{
private:
    int accID;
    char* name;
    int balance;
public:
    Account();
    Account(int accID, const char* pName, int balance);
    Account(const Account& copy);
    int GetAccID() const;
    virtual int GetRate() const = 0;
    virtual void Deposit(int money, int rate);
    bool Withdraw(int money);
    virtual void PrintInfo() const;
    Account& operator=(const Account& ref);
    ~Account();
};

#endif