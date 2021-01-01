/*
 * �����̸�: Account.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 5] ���Ϲ��� 0.9
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
        cout << "�ܰ� " << balance << "�� ���Դϴ�. �� ���� ���� �Է��ϼ���." << endl;
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
    cout << "���� ID: " << accID << endl;
    cout << "�� ��: " << name << endl;
    cout << "�� ��: " << balance << endl;
}
Account& Account::operator=(const Account& ref)
{
    accID = ref.accID;
    name = ref.name;
    balance = ref.balance;
    return *this;
}