/*
 * �����̸�: AccountException.h
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 12] ���Ϲ��� 0.12
 */

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class WithdrawException : public AccountException
{
private:
	int money;
public:
	WithdrawException(int money) : money(money)
	{ }
	virtual void ShowExceptionReason() override;
};

class DepositException : public AccountException
{
private:
	int money;
public:
	DepositException(int money) : money(money)
	{ }
	virtual void ShowExceptionReason() override;
};

#endif