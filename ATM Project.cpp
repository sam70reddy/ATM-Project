#include <iostream>
#include <limits>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    string type;
    double balance;

public:
    BankAccount(string name, int accountNumber, string type, double balance) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->type = type;
        this->balance = balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
            return;
        }

        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        }
    }

    void showCustomerInfo() {
        cout << "Customer Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << type << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    string getName() {
        return name;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getType() {
        return type;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount customer1("Samantha", 18235, "Savings", 235.0);
     BankAccount customer2("Ramesh", 19285, "Savings", 289.0);
      BankAccount customer3("paramesh", 16285, "Savings", 129.0);

    double withdrawalAmount;
    cout << "Enter amount to withdraw: $";
    while (!(cin >> withdrawalAmount)) {
        cout << "Invalid input. Please enter a numeric value: $";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    customer1.withdraw(withdrawalAmount);

    cout << "\nYour account information:\n";
    customer1.showCustomerInfo();

    return 0;
}
