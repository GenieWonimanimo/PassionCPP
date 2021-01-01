/*
 * 소프트웨어 버전: Banking System Ver 0.8
 * 
 * 파일이름: BankingSystemMain.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 3] 파일버전 0.8
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
    AccountHandler accHandler;
    while (1)
    {
        switch (accHandler.ShowMenu())
        {
        case OPTION::MAKE:
            accHandler.MakeAccount();
            break;
        case OPTION::DEPOSIT:
            accHandler.Deposit();
            break;
        case OPTION::WITHDRAW:
            accHandler.Withdraw();
            break;
        case OPTION::PRINTALL:
            accHandler.PrintAll();
            break;
        case OPTION::TERMINATE:
            cout << "프로그램 종료" << endl;
            return 0;
        default:
            cout << "잘못된 옵션 입력" << endl;
        }
    }
    return 0;
}