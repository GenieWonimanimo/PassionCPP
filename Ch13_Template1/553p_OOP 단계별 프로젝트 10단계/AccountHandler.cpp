/*
 * 파일이름: AccountHandler.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 6] 파일버전 0.9
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

AccountHandler::AccountHandler() : accNum(0)
{ }
int AccountHandler::ShowMenu()
{
    int option;

    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: "; cin >> option;
    cout << endl;
    return option;
}

void AccountHandler::MakeAccount()
{
    int kind;
    cout << "[계좌종류선택]" << endl;
    cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
    cout << "선택: "; cin >> kind;
    switch (kind)
    {
    case KIND::NORMAL:
        MakeNormalAccount();
        break;
    case KIND::HIGHCREDIT:
        MakeCreditAccount();
        break;
    default:
        exit(1);
    }
}

void AccountHandler::MakeNormalAccount()
{
    int accID, money, rate;
    String name;

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> accID;
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> money;
    cout << "이자율: "; cin >> rate; cout << endl;
    accArr[accNum++] = new NormalAccount(accID, name, money, rate);
}
void AccountHandler::MakeCreditAccount()
{
    int accID, money, grade;
    String name;
    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> accID;
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> money;
    cout << "회원 등급(1toA, 2toB, 3toC): "; cin >> grade; cout << endl;
    accArr[accNum++] = new HighCreditAccount(accID, name, money, grade);
}

void AccountHandler::Deposit()
{
    int accID;
    cout << "[ 입  금 ]" << endl;
    cout << "계좌 ID: "; cin >> accID;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == accID)
        {
            int money;
            cout << "입금액: "; cin >> money;
            accArr[i]->Deposit(money, accArr[i]->GetRate());
            cout << "입금완료" << endl;
            return;
        }
    }
    cout << "계좌가 없습니다." << endl;
}
void AccountHandler::Withdraw()
{
    int accID;
    cout << "[ 출  금 ]" << endl;
    cout << "계좌 ID: "; cin >> accID;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == accID)
        {
            int money;
            cout << "출금액: "; cin >> money;
            if (accArr[i]->Withdraw(money))
                cout << "출금 완료" << endl;
            return;
        }
    }
    cout << "계좌가 없습니다." << endl;
}
void AccountHandler::PrintAll()
{
    cout << "[ 출  력 ]" << endl;
    for (int i = 0; i < accNum; i++)
        accArr[i]->PrintInfo();
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}