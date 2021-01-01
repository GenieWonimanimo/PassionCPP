/*
 * 파일이름: AccountException.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 12] 파일버전 0.12
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