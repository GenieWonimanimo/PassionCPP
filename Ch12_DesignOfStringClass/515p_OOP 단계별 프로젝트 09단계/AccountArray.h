/*
 * 파일이름: AccountArray.h
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 5] 파일버전 0.9
 */

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__
#define _CRT_SECURE_NO_WARNINGS

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
