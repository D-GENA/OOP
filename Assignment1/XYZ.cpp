#include <iostream>
using namespace std;


// Defined Class for Acoount
class Account {
private:
    double balance; // use to store account balance as a double

public:
    // Constructor to initializes balance
    setBalance(double initialBalance) {
        if (initialBalance >= 1000.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << " invalid Amount. Balance must be at least $1000.00.\n";
        }
    }

    // Member function to deposit money
    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "$" << amount << " Money deposited successfully.\n";
        } else {
            cout << "Error! Please note the deposit amount must be positive.\n";
        }
    }

    // Member function to withdraw money
    void Withdraw(double amount) {
        if (amount > balance) {
            cout << "Requested withdrawal amount exceeded account in balance.\n";
        } else if (amount <= 0) {
            cout << "Error! Please note the withdrawal amount must be positive.\n";
        } else {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully.\n";
        }
    }

    // function to return the current balance
    double GetBalance() const {
        return balance;
    }
};


// Main Function of the ATM Menu

int main() {
    double initialBalance;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "      Welcome to XYZ Bank ATM System      \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Enter initial account balance: $";
    cin >> initialBalance;

    setBalance userAccount(initialBalance);


    int choice;
    double amount;

    // usage of while loop & switch statement
    while (true) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "          MAIN MENU            \n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1. Balance Inquiry\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit system\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current Balance is: $" << userAccount.GetBalance() << "\n";
                break;

            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;
                userAccount.Deposit(amount);
                break;

            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                userAccount.Withdraw(amount);
                break;

            case 4:
                cout << "Closing ATM Menu... Thank you for banking with us!! [XYZ Bank]\n";
                return 0; // exit program

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
