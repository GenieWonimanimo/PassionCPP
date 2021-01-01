/*
 * 파일이름: Account.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 11, 27] 파일버전 0.7
 */

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int accID, const char* pName, int balance)
    : accID(accID), balance(balance)
{
    name = new char[strlen(pName) + 1];
    strcpy(name, pName);
}
Account::Account(const Account& copy)
    : accID(copy.accID), balance(copy.balance)
{
    name = new char[strlen(copy.name) + 1];
    strcpy(name, copy.name);
}
int Account::GetAccID() const { return accID; }
void Account::Deposit(int money, int rate)
{
    balance += money;
    balance *= (1 + (rate / double(100)));
}
bool Account::Withdraw(int money)
{
    if (money > balance)
    {
        cout << "잔고가 " << balance << "원 뿐입니다. 더 작은 값을 입력하세요." << endl;
        return false;
    }
    else
    {
        balance -= money;
        return true;
    }
}
void Account::PrintInfo() const
{
    cout << "계좌 ID: " << accID << endl;
    cout << "이 름: " << name << endl;
    cout << "잔 액: " << balance << endl;
}
Account::~Account()
{
    delete[]name;
}