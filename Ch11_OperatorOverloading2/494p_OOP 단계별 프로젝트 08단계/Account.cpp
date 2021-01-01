/*
 * �����̸�: Account.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 3] ���Ϲ��� 0.8
 */

#include "BankingCommonDecl.h"
#include "Account.h"
Account::Account()
    : accID(0), balance(0), name(NULL)
{}
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
    delete[]name;
    name = new char[strlen(ref.name) + 1];
    strcpy(name, ref.name);
    balance = ref.balance;
    return *this;
}
Account::~Account()
{
    delete[]name;
}