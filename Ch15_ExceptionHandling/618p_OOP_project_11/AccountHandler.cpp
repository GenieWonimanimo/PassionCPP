/*
 * �����̸�: AccountHandler.cpp
 * �ۼ���: ������
 * ������Ʈ ����: [2020, 12, 6] ���Ϲ��� 0.92
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "AccountException.h"
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
    while (1)
    {
        try
        {
            cout << "�Աݾ�: "; cin >> money;
            if (money < 0)
                throw DepositException(money);
            else
                break;
        }
        catch (AccountException& expn)
        {
            expn.ShowExceptionReason();
        }
    }
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
    while (1)
    {
        try
        {
            cout << "�Աݾ�: "; cin >> money;
            if (money < 0)
                throw DepositException(money);
            else
                break;
        }
        catch (AccountException& expn)
        {
            expn.ShowExceptionReason();
        }
    }
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
            int money = -1;
            while (1)
            {
                try
                {
                    cout << "�Աݾ�: "; cin >> money;
                    if (money < 0)
                        throw DepositException(money);
                    else
                        break;
                }
                catch (AccountException& expn)
                {
                    expn.ShowExceptionReason();
                    cout << "�ٽ� �Է��ϼ���. " << endl;
                }

            }
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
            int money = -1;
            while (1)
            {
                try
                {
                    cout << "��ݾ�: "; cin >> money;
                    if (money < 0 || money > accArr[i]->GetBalance())
                        throw WithdrawException(money);
                    else
                        break;
                }
                catch (AccountException& expn)
                {
                    expn.ShowExceptionReason();
                    cout << "�ٽ� �Է��ϼ���. " << endl;
                }
                
            }
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