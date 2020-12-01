#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> AccountType {"", "CHECKING", "SAVINGS"};

// the class of a bank account, which include the type of the account (checking or savings)
class Account{
private:
  int type; // 1-checking, 2-savings
  int balance;
public:
  Account(int ty, int bal): type(ty), balance(bal) {}
  
  // get the balance of an account
  void getBalance(){
    string confirmation
  }
  
  // withdraw money from an account
  int getWithdraw()
  {
    int withdraw_amount;
    cout << "Please enter the amount of the withdrawal:" << endl;
    cin >> withdraw_amount;
    
    //
  }
};


class Customer{
private:
  string username;
  string PIN;
  vector<Account> accounts;
public:
  Customer(string& un, string pin): username(un), PIN(pin) {}
  void CreateNewAccount(int tp, 
};

class ATM{
private:
  vector<Customer> customers;
public:
  ATM() {};
  //display the main menu
  void displayMenu()
  {
    int option;
    cout << "------Main Menu------" << endl;
    cout << "Please select your account:" << endl;
    cout <<"\t1. Checking \n\t2. Savings \n\t3. Exit" <<endl;
    cin >> option;
    switch(option)
    {
      case 1: display
    }
  }
  
};
