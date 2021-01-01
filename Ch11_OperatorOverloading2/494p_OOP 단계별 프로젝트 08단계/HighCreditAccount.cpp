/*
 * 파일이름: HighCreditAccount.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 3] 파일버전 0.8
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
    cout << "계좌 종류: 신용신뢰계좌" << endl;
    Account::PrintInfo();
    cout << "회원 등급: ";
    switch (grade)
    {
    case GRADE::A:
        cout << "A(이자 7%)" << endl << endl; break;
    case GRADE::B:
        cout << "B(이자 4%)" << endl << endl; break;
    case GRADE::C:
        cout << "C(이자 2%)" << endl << endl; break;
    default:
        exit(1);
    }
}