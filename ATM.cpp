#include "ATM.h"

Account::Account(int tp, int bal): type(ty), balance(bal) {}
void Account::getBalance()
{}

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

void Account::makeTransfer()
{
  int transfer_amount;
  int transfer_to = this->type == 1? 2:1; 
  cout << "Enter amount to transfer to your "<< AccountType[transfer_to] << " account."<< endl;
	cin >> transfer_amount;
}
