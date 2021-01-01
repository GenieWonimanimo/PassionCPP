#include <iostream>
#include <cstring>
using namespace std;

class DepositException
{
private:
    int reqDep; // request deposit
public:
    DepositException(int money) : reqDep(money)
    { }
    void ShowExceptionReason()
    {
        cout << "[exception message: " << reqDep << " can't be depositted]" << endl;
    }
};

class WithdrawException
{
private:
    int balance;
public:
    WithdrawException(int money) : balance(money)
    { }
    void ShowExceptionReason()
    {
        cout << "[exception message: balance " << balance << ", not enough balance]" << endl;
    }
};

class Account
{
private:
    char accNum[50];
    int balance;
public:
    Account(const char* acc, int money) : balance(money)
    {
        strcpy(accNum, acc);
    }
    void Deposit(int money)
    {
        if (money < 0)
            throw DepositException(money);
        balance += money;
    }
    void Withdraw(int money)
    {
        if (money > balance)
            throw WithdrawException(money);
        balance -= money;
    }
    void ShowMyMoney()
    {
        cout << "balance: " << balance << endl << endl;
    }
};

int main(void)
{
    Account myAcc("56789-827120", 5000);

    try
    {
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    }
    catch(DepositException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try
    {
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4500);
    }
    catch(WithdrawException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    return 0;
}