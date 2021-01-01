/*
 * �����̸�: NormalAccount.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 3] ���Ϲ��� 0.8
 */

#include "BankingCommonDecl.h"
#include "NormalAccount.h"

NormalAccount::NormalAccount(int accID, const char* pName, int balance, int rate)
    : Account(accID, pName, balance), rate(rate)
{ }
int NormalAccount::GetRate() const { return rate; }
void NormalAccount::Deposit(int money, int rate)
{
    Account::Deposit(money, rate);
}
void NormalAccount::PrintInfo() const
{
    cout << "���� ����: ���뿹�ݰ���" << endl;
    Account::PrintInfo();
    cout << "������: " << rate << endl << endl;
}