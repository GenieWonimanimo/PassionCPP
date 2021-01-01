/*
 * �����̸�: AccountArray.h
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 3] ���Ϲ��� 0.1
 */

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"

class AccountArray
{
private:
	Account** arr;
	int arrlen;
	AccountArray(const AccountArray& ref) {}
	AccountArray& operator=(const AccountArray& arr) {}
public:
	AccountArray(int len = 100);
	Account*& operator[] (int idx);
	Account* operator[] (int idx) const;
	int GetArrLen() const;
	~AccountArray();
};


#endif
