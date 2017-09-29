#ifndef BankAccount_h
#define BankAccount_h

class BankAccount
{
    private:
    
    double balance; // How much is in the bank
    int acctNum; // Bank Num
    
    public:
    BankAccount();                                  //  default constructor
    BankAccount(int);                               //  constructor
    double getBalance(){return balance;}            //  return Balance
    int getAcct(){return acctNum;}                  //  return Accoutn number
    void deposit(double);                           //  Deposit
    void withdraw(double);                          //  Withdraw
    
};

#endif
