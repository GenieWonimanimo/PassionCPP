/*
 * 파일이름: AccountHandler.h
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 6] 파일버전 0.92
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
    BoundCheckArray<Account*> accArr;
    int accNum;
public:
    AccountHandler();
    int ShowMenu();
    void MakeAccount();
    void Deposit();
    void Withdraw();
    void PrintAll();
    ~AccountHandler();
protected:
    void MakeNormalAccount();
    void MakeCreditAccount();
};
#endif
