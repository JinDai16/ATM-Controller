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
  Account(int ty, int bal)
  Account operator = (const Account& account)
  void getBalance()
  void getWithdraw()
  void getDeposit()
};

class Customer{
private:
  string username;
  string PIN;
  vector<Account> accounts;
public:
  Customer(string& un, string& pin)
  void CreateNewAccount(int tp, int bal)
  void Withdraw(Account account)
  void Deposit(Account account)
  void Transfer(Account ac1, Account ac2);
};

class ATM{
private:
  vector<Customer> customers;
public:
  ATM() {};
  //display the main menu
  void addCustomer(Customer c);
  bool validatePIN(string pin)
  void displayMenu(Customer c)
  void displayFunction(Customer c, int option)  
};
