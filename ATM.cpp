#include "ATM.h"

//Methods for the Class Account
Account::Account(int tp, int bal): type(ty), balance(bal) {}

// Operator overloading
Account Account:: operator = (const Account& account)
{
	this->type = account.type;
	this->balance = account.balance;
	return *this;
}
// function to display the current balance of an account
void Account::getBalance()
{
        cout << "Your account balance is: $" << this->balance << endl;   
}

// function to make a withdrawal from an account
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

// function to make deposit to the current account
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

//Methods for the Class Customer
Customer::Customer(string& un, string pin): username(un), PIN(pin) {}

// fuction to create a new account owned by the customer
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

// function for the customer to make a withdrawal from a certain account
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

// function for the customer to make a deposit to a certain account
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

// function for the customer to make a transfer from the checking to the savings account, or vice versa
void Customer::Transfer(Account ac1, Account ac2)
{
        auto it1 = find(this->accounts.begin(), this->accounts.end(), ac1);
        auto it2 = find(this->accounts.begin(), this->accounts.end(), ac2);
        
        //justifying invalid transfer: accounts must exist and of different type
        if(it1 == accounts.end() || it2 == accounts.end() || it1->type == it2->type)
        {
                cout << "Invalid account information, transaction cannot be completed." << endl;
        }
        int transfer_amount;
        int transfer_to = ac2.type; //transfer from ac1 to ac2
        cout << "Please enter the amount you would like to transfer to your " << AccountType[transfer_to] << "account:" << endl;
        cin >> transfer_amount;
        
        if(transfer_amount <= ac1.balance) // valid transfer
        {
                //update the balance of two accounts
                it1->balance -= transfer_amount;
                it2->balance += transfer_amount;
                cout << "$" << transfer_amount << "was deposited into your " << AccountType[transfer_to] << "account" << endl;
                cout << "Balance in the Account:" << it2->balance << endl;
        }
}

//Methods of the Class ATM

// function to add a new customer to an ATM machine
void ATM::addCustomer(Customer c)
{
        this->customers.push_back(c);
}

// function to validate the PIN of a customer using the ATM
bool ATM::validatePIN(string pin)
{
        for(auto customer:this->customers)
        {
                if(customer.PIN == pin)
                {
                        return true;
                        break;
                }
        }
        return false;
}

// function to display the ATM's main menu
void ATM::displayMenu(Customer c)
{
        int option;
	cout << "----Main Menu----" <<endl;
	cout << "\tPlease select your account. " << endl;
	cout << "\t1. Checkings \n\t2. Savings \n\t3. Exit" << endl;
	cin >> option;
        char response;
	auto it = this->customers.find(c);
	switch(option)
        {
		case 1: this->displayFunction(c, option); // checking account
			break;
		case 2: this->displayFunction(c, option); // savings account
			break;
		default:
			cout << "Would you like to continue (y/n)\n";
			cin >> response;
			if(response == 'y' || response == 'Y')
                        {
                                this->displayMenu();
                        }
                        else if(response == 'n' || response == 'N')
                        {
                                cout << "Thank you for banking with us." << endl;
                                exit(0);
                        }
			break;
	}
}

// function to display action selection for a cunstomer
void ATM::displayFunction(Customer c, int option)
{
        // account option = 1 (checkings)
	// account option = 2 (savings)
	cout << "Please select your action for your " <<AccountType[option] << "account:" << endl;
	cout << "--\n\t1. Check balance"
		<<"\n\t2. Withdraw from " << AccountType[option] 
		<<"\n\t3. Deposit to " << AccountType[option] 
		<<"\n\t4. Transfer " 
		<<"\n\t5. --Return to Menu." << endl;

	// Pass in account type
	Account accout_process, account_transfer;
	for(auto account:c.accounts) // we assume one customer can set up at most two accounts (one checking and one savings)
	{
		if(accout.type == option)
		{
			account_process = account;
		}
		else
		{
			account_transfer = account;
		}			
	}

	int selectMenu;
	cin >> selectMenu;
	string response;
	switch(selectMenu)
	{
		case 1:
			cout << accout_process.getBalance();
			break;
		case 2: 
			cout << c.Withdraw();
			break;
		case 3: 
			cout << c.Deposit();
			break;
		case 4:
			cout << c.Transfer(account_process, account_transfer);
			break;
		case 5:
			this->displayMenu(c); // return to main menu
			break;
		default:
			cout << "Would you like to continue (y/n)\n";
			cin >> response;
			if(response == 'y' || response == 'Y')
                        {
                               	this->displayMenu(c);
                        }
                        else if(response == 'n' || response == 'N')
                        {
                                cout << "Thank you for banking with us." << endl;
                                exit(0);
                        }
			break;
	}
}


// Test function
int main() 
{
	Customer newCustomer("Cus", "1234");
	newCustomer.CreateNewAccount(1, 500); // checking account
	newCustomer.CreateNewAccount(2, 500); // savings account
	ATM atmMachine;
	atmMachine.addCustomer(newCustomer);
	
	string pin;
	cout << "Welcome to Bank of Programming.\n\tPlease enter your PIN to access your account:" << endl;
	do {
		cin >> pin;
		if(atmMachine.validatePIN(pin)) {
			atmMachine.displayMenu(); // continue to main menu
		} else {
			cout << "Invalid pin. Please enter pin number again:" << endl; 
		}
	} while (!atmMachine.validatePin(pin));

	return 0;
}
