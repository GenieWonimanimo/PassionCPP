/*
 * 파일이름: NormalAccount.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 5] 파일버전 0.9
 */

#include "BankingCommonDecl.h"
#include "NormalAccount.h"

NormalAccount::NormalAccount(int accID, String pName, int balance, int rate)
    : Account(accID, pName, balance), rate(rate)
{ }
int NormalAccount::GetRate() const { return rate; }
void NormalAccount::Deposit(int money, int rate)
{
    Account::Deposit(money, rate);
}
void NormalAccount::PrintInfo() const
{
    cout << "계좌 종류: 보통예금계좌" << endl;
    Account::PrintInfo();
    cout << "이자율: " << rate << endl << endl;
}