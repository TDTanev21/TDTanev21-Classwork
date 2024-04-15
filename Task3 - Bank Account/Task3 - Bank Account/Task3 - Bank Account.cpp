#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

class BankAccount {
private:
    string clientName;
    string accountNumber;
    double balance;

public:
   
    BankAccount() : balance(0.0) {}


    void createAccount() {
        cout << "Enter your name: ";
        getline(cin, clientName); 
        while (true) {
            cout << "Enter account number (numbers only): ";
            getline(cin, accountNumber);
            if (isNumeric(accountNumber)) 
                break;
            else
                cout << "Invalid account number. Please enter numbers only." << endl;
        }

        while (true) {
            cout << "Enter initial balance (numbers only): ";
            string balance;
            getline(cin, balance);
            if (isNumeric(balance)) { 
                balance = stod(balance);
                break;
            }
            else
                cout << "Invalid balance. Please enter numbers only." << endl;
        }
    }

    
    bool isNumeric(const string& str) {
        for (char c : str) {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    void displayAccount() {
        cout << "Client Name: " << clientName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into the account." << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from the account." << endl;
        }
        else {
            cout << "Insufficient funds to withdraw " << amount << endl;
        }
    }
};

int main() 
{
    BankAccount account;
    account.createAccount(); 
    cout << "\nBank Account Details:\n";
    account.displayAccount();
    double amount;
    cout << "\nEnter amount to deposit: ";
    cin >> amount;
    account.deposit(amount);
    cout << "\nUpdated Account Details:\n";
    account.displayAccount();
    cout << "\nEnter amount to withdraw: ";
    cin >> amount;
    account.withdraw(amount);
    cout << "\nUpdated Account Details:\n";
    account.displayAccount();
}
