/*
 * ����Ʈ���� ����: Banking System Ver 0.8
 * 
 * �����̸�: BankingSystemMain.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 3] ���Ϲ��� 0.8
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
    AccountHandler accHandler;
    while (1)
    {
        switch (accHandler.ShowMenu())
        {
        case OPTION::MAKE:
            accHandler.MakeAccount();
            break;
        case OPTION::DEPOSIT:
            accHandler.Deposit();
            break;
        case OPTION::WITHDRAW:
            accHandler.Withdraw();
            break;
        case OPTION::PRINTALL:
            accHandler.PrintAll();
            break;
        case OPTION::TERMINATE:
            cout << "���α׷� ����" << endl;
            return 0;
        default:
            cout << "�߸��� �ɼ� �Է�" << endl;
        }
    }
    return 0;
}