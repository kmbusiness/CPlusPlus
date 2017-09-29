/*
        John Nguyen
        Assignment #8 - Classes
        4/7/2017
 */


#include <iostream>
#include <iomanip>
#include "BankAccount.h"
using namespace std;

void checkBalance(BankAccount);                     // Check Balance
void transfer(BankAccount&, BankAccount&, double);  // Transfer money to different account
void calculateInterest(BankAccount&, double rate, int year, double amount);     // Calculate the intereset and then deposit the money
BankAccount findAcct(BankAccount[10], int);         // Find account to work with


double checkTamount(BankAccount);   // Check to see whether the transfer amount is valid
int checkAcct();                    //Check to see if the account inputted is valid
void accountMenu();                 //Display the account menu
void mainMenu();                    //Display the main menu
int checkMMenu();                   //Check if input for the main menu is valid
double checkDeposit();              //Check if deposit amount is valid
double checkWithdraw(BankAccount);  //Check if withdraw amount is valid
int checkAcctTransfer(BankAccount); //Check if the account selected to be transfer to is valid
int checkYear();                    //Check the amount of year for interest is valid

const double IRATE = .05;           //Interest Rate

int main()
{
    //Create array of bank accounts
    BankAccount customers[10];
    int temp = 0;
    for(int i = 100; i <110; i++)
    {
        BankAccount *bTemp = new BankAccount(i);
        customers[temp] = *bTemp;
        temp++;
    }
    
    //Menu for the whole program
    int mDecision;
    bool loop = true;
    while(loop)
    {
        mainMenu();
        if(cin >> mDecision)
        {
            if(mDecision == 1)
            {
                int acctNum = checkAcct();
                BankAccount inUse = findAcct(customers, acctNum);
                
                accountMenu();
                int aDecision = 0;
                do
                {
                    aDecision = checkMMenu();
                    switch(aDecision)
                    {
                        case 1:
                        {
                            cout << "Enter the deposit amount:" <<endl;
                            double deposit = checkDeposit();
                            inUse.deposit(deposit);
                            accountMenu();
                            break;
                        }
                        case 2:
                        {
                            //Can't withdraw if balance = zero
                            if(inUse.getBalance() == 0)
                            {
                                cout << "Can't do that because balance is zero dollar" << endl;
                                
                            }
                            else
                            {
                                double withdraw = checkWithdraw(inUse);
                                inUse.withdraw(withdraw);
                            }
                            accountMenu();
                            break;
                        }
                        case 3:
                        {
                            checkBalance(inUse);
                            accountMenu();
                            break;
                        }
                        case 4:
                        {
                            //cout << "Enter amount to be put into saving: " << endl;
                            double saving = 0;
                            //cout << "How many year?" << endl;
                            int year = 5;
                            calculateInterest(inUse, IRATE, year, saving);
                            accountMenu();
                            break;
                        }
                        case 5:
                        {
                            if(inUse.getBalance() == 0)
                            {
                                cout << "Can't do that because balance is zero dollar" << endl;
                                
                            }
                            else
                            {
                                double transferAmount = checkTamount(inUse);
                                int tfer = checkAcctTransfer(inUse);

                                //Iterate to the correct account to do the transfer to
                                for (int i = 0; i < 10; i++)
                                {
                                    if (customers[i].getAcct() == tfer)
                                    {
                                        transfer(inUse, customers[i], transferAmount);
                                    }
                                    
                                }

                            }
                            accountMenu();
                            break;
                        }
                        case 6:
                        {
                            cout << "Moving back...\n" << endl;
                            break;
                        }
                    }
                } while (aDecision != 6);
            }
            else if(mDecision == 2)
            {
                cout << "Exiting..." << endl;
                loop = false;
            }
            else
            {
                cout << "Try again\n" << endl;
            }
    }
    else
    {
        cin.clear();
        string invalid;
        cin >> invalid;
        cout << "Try Again\n" << endl;
    }
    
    

    }
    
}
// Main ends

/*
    Find the account to be use
    @parem array of bank account
    @parem account number inputted by user
    @return The account to be use
*/
BankAccount findAcct(BankAccount cust[10], int acct)
{
    BankAccount temp;
    for(int i = 0; i < 10; i++)
    {
        if (acct == cust[i].getAcct())
        {
            temp = cust[i];
            //return cust[i];
        }
    }
    return temp;
}

/*
    Calculate the interest
    @parem Bank account to be use
    @parem the interest rate
    @parem Year for calculating interest
    @parem Amount of money to be deposit
 */
void calculateInterest(BankAccount &cust, double iRate, int year, double amount)
{
    double interest = (cust.getBalance()*iRate*year);
    cout << "Your interest over " << year << " year(s) is $" << setprecision(2) << fixed << interest << endl;
    cust.deposit(interest);
    
}

//void calculateInterest(BankAccount &cust, double iRate, int year, double amount)
//{
//    double interest = (amount*iRate*year) + amount;
//    cout << "Your interest over " << year << " year(s) is $" << setprecision(2) << fixed << interest << endl;
//    cust.deposit(amount);
//    
//}

/*
    Display the account number and balance
    @parem the bank account to be use
 */
void checkBalance(BankAccount cust)
{
    cout << "Account #" << cust.getAcct() << endl;
    cout << "Balance: $" << cust.getBalance() << endl;
}

/*
    Transfer money from account A to account B
    @parem Account A
    @parem Account B
    @parem ammount to be transfer
 */
void transfer(BankAccount &from, BankAccount &to, double amount) //validate amount entered
{
    from.withdraw(amount);
    to.deposit(amount);
}

/*
 Check if the input transfer amount is valid
 @return valid transfer amount
 */
double checkTamount(BankAccount cust)
{
    cout << "Enter amount to be transfer: " << endl;
    double amount = 0;
    bool loop = true;
    while (loop)
    {
        double valid = cust.getBalance();
        if (cin >> amount)
        {
            if (amount >= 0 && amount <= valid)
            {
                loop = false;
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return amount; //Return the valid year input
}

/*
 Check if the input account is valid
 @return valid account
 */
int checkAcct()
{
    cout << "Enter Account Number:" <<endl;
    int acct = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> acct)
        {
            if (acct >= 100 && acct < 110)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return acct; //Return the valid acct input
}

/*
 Check if the deposit input is valid
 @return valid deposit amount
 */
double checkDeposit()
{
    double deposit = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> deposit)
        {
            if (deposit > 0)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return deposit; //Return the valid deposit
}

/*
 Check if the deposit input is valid
 @return valid deposit amount
 */
double checkWithdraw(BankAccount bank)
{
    cout << "Enter the withdraw amount:" <<endl;
    double withdraw = 0;
    bool loop = true;
    while (loop)
    {
        double max = bank.getBalance();
        if (cin >> withdraw)
        {
            if (withdraw > 0 && withdraw <= max)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return withdraw; //Return the valid deposit
}

/*
 Check if the menu input is valid
 @return valid menu input
 */
int checkMMenu()
{
    int menu = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu >= 1 && menu <= 6)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return menu; //Return the valid menu input
}

/*
 Check if the menu input is valid
 @return valid menu input
 */
int checkYear()
{
    int year = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> year)
        {
            if (year > 0)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return year; //Return the valid menu input
}

/*
 Check if the menu input is valid
 @return valid menu input
 */
int checkAcctTransfer(BankAccount bank)
{
    cout << "Enter Account # to transfer to" << endl;
    int acct = 0;
    int sameAcct = bank.getAcct();
    bool loop = true;
    while (loop)
    {
        if (cin >> acct)
        {
            if (acct >= 100 && acct != sameAcct && acct < 110)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return acct; //Return the valid menu input
}

/*
    Display account menu
 */
void accountMenu()
{
    cout << "\nAccount Menu: " << endl;
    cout << "1. Deposit Funds" << endl;
    cout << "2. Withdrawal Funds" << endl;
    cout << "3. Check Account Balance" << endl;
    cout << "4. Put in Savings" << endl;
    cout << "5. Transfer Money" << endl;
    cout << "6. Go back to Main Menu" << endl;
}

/*
    Display main menu
 */
void mainMenu()
{
    cout << "1. Access Account" << endl;
    cout << "2. Quit" << endl;
}



/*
 Rectangle Menu: 1. Display Rectangle 2. Display Area 3. Display Perimeter 4. Back to Main Menu
*/
