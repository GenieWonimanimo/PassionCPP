/*
 * �����̸�: Account.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 11, 27] ���Ϲ��� 0.7
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
Account::~Account()
{
    delete[]name;
}