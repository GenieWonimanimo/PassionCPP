/*
 * 파일이름: Account.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 5] 파일버전 0.9
 */

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account()
    : accID(0), balance(0)
{ }
Account::Account(int accID, String pName, int balance)
    : accID(accID), name(pName), balance(balance)
{ }
Account::Account(const Account& copy)
    : accID(copy.accID), name(copy.name), balance(copy.balance)
{ }
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
Account& Account::operator=(const Account& ref)
{
    accID = ref.accID;
    name = ref.name;
    balance = ref.balance;
    return *this;
}