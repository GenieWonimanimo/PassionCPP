/*
 * �����̸�: AccountHandler.h
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 6] ���Ϲ��� 0.92
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
