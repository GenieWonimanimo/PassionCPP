/*
 * �����̸�: NormalAccount.h
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 11, 27] ���Ϲ��� 0.7
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"

class NormalAccount : public Account
{
private:
    int rate;
public:
    NormalAccount(int accID, const char* pName, int balance, int rate);
    virtual int GetRate() const;
    virtual void Deposit(int money, int rate);
    virtual void PrintInfo() const;
};

#endif