/*
 * �����̸�: AccountHandler.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 6] ���Ϲ��� 0.9
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

AccountHandler::AccountHandler() : accNum(0)
{ }
int AccountHandler::ShowMenu()
{
    int option;

    cout << "-----Menu------" << endl;
    cout << "1. ���°���" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
    cout << "����: "; cin >> option;
    cout << endl;
    return option;
}

void AccountHandler::MakeAccount()
{
    int kind;
    cout << "[������������]" << endl;
    cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
    cout << "����: "; cin >> kind;
    switch (kind)
    {
    case KIND::NORMAL:
        MakeNormalAccount();
        break;
    case KIND::HIGHCREDIT:
        MakeCreditAccount();
        break;
    default:
        exit(1);
    }
}

void AccountHandler::MakeNormalAccount()
{
    int accID, money, rate;
    String name;

    cout << "[���뿹�ݰ��� ����]" << endl;
    cout << "���� ID: "; cin >> accID;
    cout << "�� ��: "; cin >> name;
    cout << "�Աݾ�: "; cin >> money;
    cout << "������: "; cin >> rate; cout << endl;
    accArr[accNum++] = new NormalAccount(accID, name, money, rate);
}
void AccountHandler::MakeCreditAccount()
{
    int accID, money, grade;
    String name;
    cout << "[�ſ�ŷڰ��� ����]" << endl;
    cout << "���� ID: "; cin >> accID;
    cout << "�� ��: "; cin >> name;
    cout << "�Աݾ�: "; cin >> money;
    cout << "ȸ�� ���(1toA, 2toB, 3toC): "; cin >> grade; cout << endl;
    accArr[accNum++] = new HighCreditAccount(accID, name, money, grade);
}

void AccountHandler::Deposit()
{
    int accID;
    cout << "[ ��  �� ]" << endl;
    cout << "���� ID: "; cin >> accID;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == accID)
        {
            int money;
            cout << "�Աݾ�: "; cin >> money;
            accArr[i]->Deposit(money, accArr[i]->GetRate());
            cout << "�ԱݿϷ�" << endl;
            return;
        }
    }
    cout << "���°� �����ϴ�." << endl;
}
void AccountHandler::Withdraw()
{
    int accID;
    cout << "[ ��  �� ]" << endl;
    cout << "���� ID: "; cin >> accID;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == accID)
        {
            int money;
            cout << "��ݾ�: "; cin >> money;
            if (accArr[i]->Withdraw(money))
                cout << "��� �Ϸ�" << endl;
            return;
        }
    }
    cout << "���°� �����ϴ�." << endl;
}
void AccountHandler::PrintAll()
{
    cout << "[ ��  �� ]" << endl;
    for (int i = 0; i < accNum; i++)
        accArr[i]->PrintInfo();
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}