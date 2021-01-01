/*
 * �����̸�: AccountHandler.h
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 5] ���Ϲ��� 0.9
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    AccountArray accArr;
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
