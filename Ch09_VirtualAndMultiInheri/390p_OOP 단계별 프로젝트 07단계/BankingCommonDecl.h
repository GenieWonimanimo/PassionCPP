/*
 * �����̸�: BankingCommonDecl.h
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 11, 27] ���Ϲ��� 0.7
 */

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ���α׷� ������� ���� �޴�
namespace OPTION { enum { MAKE = 1, DEPOSIT, WITHDRAW, PRINTALL, TERMINATE }; }
// ���� ����
namespace KIND { enum { NORMAL = 1, HIGHCREDIT }; }
// �ſ� ���
namespace GRADE { enum { A = 1, B, C }; }

#endif