#include "ATM.h"

Account::Account(int tp, int bal): type(ty), balance(bal) {}
void Account::getBalance()
{
        cout << "Your account balance is: $" << this->balance << endl;   
}

void Account::getWithdraw()
{
        int withdraw_amount;
        cout << "Please enter the amount of the withdrawal:" << endl;
        cin >> withdraw_amount;
        if(withdraw_amount <= this->balance)
        {
                int account_balance = this->balance-withdraw_amount;
                cout << "Dispensing Cash..." << endl;
                cout << "$" << withdraw_amount << " is withdrawn" << endl;
      
                //update account balance
                this->balance -= withdraw_amount;
                cout << "Balance in the Account:" << this->balance << endl;
        }
        else // insufficient balance
        {
                cout << "Insufficient Funds in the Account" << endl;
                cout << "Balance in the Account:" << this->balance << endl;
        }
}

void Account::getDeposit()
{

        int deposit_amount;
        cout << "Please enter the amount of the deposit:" << endl;
        cin >> deposit_amount;
        //update account balance
  
        this->balance += deposit_amount;   
        cout << "$" << deposit_amount << "was deposited into your account" << endl;
        cout << "Balance in the Account:" << this->balance << endl;
}
//==========================================================================================
Customer::Customer(string& un, string pin): username(un), PIN(pin) {}
void Customer::CreateNewAccount(int tp, int bal)
{
        if(tp != 1 || tp != 2) //invalid account type
        {
                cout << "Invalid account type!" << endl;
        }
        if(bal < 0) // invalid initial balance
        {
                cout << "Balance of a new account should be positive" << endl;
        }
        Account newAccount(tp, bal);
        this->accounts.push_back(newAccount);
}

void Customer::Withdraw(Account account)
{
        auto it = find(this->accounts.begin(), this->accounts.end(), account);
        if(it != accounts.end()) // the account is valid
        {
                it->getWithdraw();
        }
        else //account does not exist
        {
                cout << "The account does not exist." << endl;
        }
}

void Customer::Depoist(Account account)
{
        auto it = find(this->accounts.begin(), this->accounts.end(), account);
        if(it != accounts.end()) // the account is valid
        {
                it->getDeposit();
        }
        else //account does not exist
        {
                cout << "The account does not exist." << endl;
        }
}

void Customer::Transfer(Account ac1, Account ac2)
{
        
}
