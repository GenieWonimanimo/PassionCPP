/*
 * �����̸�: NormalAccount.h
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 5] ���Ϲ��� 0.92
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include "String.h"

class NormalAccount : public Account
{
private:
    int rate;
public:
    NormalAccount(int accID, String pName, int balance, int rate);
    virtual int GetRate() const;
    virtual void Deposit(int money, int rate);
    virtual void PrintInfo() const;
};

#endif