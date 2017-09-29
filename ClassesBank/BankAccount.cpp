#include <iostream>
#include "BankAccount.h"
using namespace std;


/*
    Defalut Constructor
 */
BankAccount::BankAccount()
{
    acctNum = 0;
    balance = 0;
    
}

/*
    Assign account number and balance
    @parem account number
 */
BankAccount::BankAccount(int acct)
{
    acctNum = acct;
    balance = 0;
}

/*
    Deposit money to the bank
    @parem amount
 */
void BankAccount::deposit(double amount)
{
    double currBal = getBalance();
    double newTotal = currBal + amount;
    balance = newTotal;
}

/*
    Withdraw money from the bank
    @parem amount
 */
void BankAccount::withdraw(double amount)
{
    double currBal = getBalance();
    double newTotal = currBal - amount;
    balance = newTotal;
}
