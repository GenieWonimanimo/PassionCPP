/*
 * �����̸�: HighCreditAccount.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 3] ���Ϲ��� 0.8
 */

#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int accID, const char* pName, int balance, int grade)
    : Account(accID, pName, balance), grade(grade)
{
    switch (grade)
    {
    case GRADE::A: rate = 7; break;
    case GRADE::B: rate = 4; break;
    case GRADE::C: rate = 2; break;
    default: exit(1);
    }
}
int HighCreditAccount::GetRate() const
{
    return rate;
}
void HighCreditAccount::Deposit(int money, int rate)
{
    Account::Deposit(money, rate);
}
void HighCreditAccount::PrintInfo() const
{
    cout << "���� ����: �ſ�ŷڰ���" << endl;
    Account::PrintInfo();
    cout << "ȸ�� ���: ";
    switch (grade)
    {
    case GRADE::A:
        cout << "A(���� 7%)" << endl << endl; break;
    case GRADE::B:
        cout << "B(���� 4%)" << endl << endl; break;
    case GRADE::C:
        cout << "C(���� 2%)" << endl << endl; break;
    default:
        exit(1);
    }
}