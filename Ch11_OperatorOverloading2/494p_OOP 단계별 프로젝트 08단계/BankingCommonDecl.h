/*
 * 파일이름: BankingCommonDecl.h
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 3] 파일버전 0.8
 */

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 프로그램 사용자의 선택 메뉴
namespace OPTION { enum { MAKE = 1, DEPOSIT, WITHDRAW, PRINTALL, TERMINATE }; }
// 계좌 종류
namespace KIND { enum { NORMAL = 1, HIGHCREDIT }; }
// 신용 등급
namespace GRADE { enum { A = 1, B, C }; }

#endif