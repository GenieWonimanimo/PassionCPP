/*
 * 파일이름: AccountArray.cpp
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 5] 파일버전 0.9
 */

#include "BankingCommonDecl.h"
#include "AccountArray.h"

AccountArray::AccountArray(int len) : arrlen(len)
{
	arr = new Account*[len];
}
Account*& AccountArray::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
		exit(1);
	return arr[idx];
}
Account* AccountArray::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
		exit(1);
	return arr[idx];
}
int AccountArray::GetArrLen() const { return arrlen; }
AccountArray::~AccountArray()
{
	delete[]arr;
}