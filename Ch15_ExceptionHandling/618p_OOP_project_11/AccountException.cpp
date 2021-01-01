/*
 * �����̸�: AccountException.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 12] ���Ϲ��� 0.12
 */

#include "BankingCommonDecl.h"
#include "AccountException.h"


void WithdrawException::ShowExceptionReason()
{
	if (money < 0)
		cout << "[Exception message: money can't be negative number]" << endl;
	else
		cout << "[Exception message: Not enough money to withdraw " << money << "]" << endl;
}

void DepositException::ShowExceptionReason()
{
	cout << "[Exception message: money can't be negative number]" << endl;
}