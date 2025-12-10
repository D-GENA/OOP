#include <iostream>
#include <cstdlib>
using namespace std;

/// Defined Class for Acoount
class Account {
protected:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 1000.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "invalid Amount. Balance must be at least $1000.00.\n";
        }
    }

    virtual void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "$" << amount << " Money deposited successfully.\n";
        } else {
            cout << "Error! Please note the deposit amount must be positive.\n";
        }
    }

    virtual bool Withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error! Please note the withdrawal amount must be positive\n";
            return false;l
        }

        if (amount > balance) {
            cout << "Requested withdrawal amount exceeded account in balance.\n";
            return false;
        }

        balance -= amount;
        cout << "Withdrawn: $" << amount << endl;
        return true;
    }

    double GetBalance() const {
        return balance;
    }
};

// Class for saving,Derived from main Account Class
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance), interestRate(rate) {}

    double CalculateInterest() {
        return balance * interestRate;
    }
};

// Class for chequing,Derived from main Account Class
class ChequingAccount : public Account {
private:
    double transactionFee;

public:
    ChequingAccount(double initialBalance, double fee)
        : Account(initialBalance), transactionFee(fee) {}

    bool Withdraw(double amount) override {
        if (Account::Withdraw(amount)) {
            balance -= transactionFee;
            cout << "Transaction fee of $" << transactionFee << "was applied.\n";
        }
        return false;
    }
};

// Main Function of the ATM Menu
int main() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "      Welcome to XYZ Bank ATM Sysytem     \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    int accountType;
    double initialBalance;
    system("pause"); 
    system("cls"); // Clear the screen

    cout << "Select Account Type:\n";
    cout << "1. Savings Account\n";
    cout << "2. Chequing Account\n";
    cout << "Enter choice: ";
    cin >> accountType;

    cout << "\n\nEnter initial account balance: $";
    cin >> initialBalance;

    Account* account = nullptr;

    if (accountType == 1) {
        double rate;
        cout << "Enter interest rate (e.g., 0.05 for 5%): ";
        cin >> rate;
        account = new SavingsAccount(initialBalance, rate);
    }
    else if (accountType == 2) {
        double fee;
        cout << "Enter transaction fee: $";
        cin >> fee;
        account = new ChequingAccount(initialBalance, fee);
    }
    else {
        cout << "Invalid account type.\n";
        return 0;
    }

    int choice;
    double amount;

    // usage of while loop & switch statement
    while (true) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "             MENU               \n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";

        if (accountType == 1) {
            cout << "4. Calculate & Apply Interest\n";
            cout << "5. Exit\n";5
        } else {
            cout << "4. Exit\n";
        }

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n\nCurrent Balance: $" << account->GetBalance() << endl;
            break;

        case 2:
            cout << "Enter deposit amount: $";
            cin >> amount;
            account->Deposit(amount);
            break;

        case 3:
            cout << "Enter withdrawal amount: $";
            cin >> amount;
            account->Withdraw(amount);
            break;

        case 4:
            if (accountType == 1) {
                SavingsAccount* sa = dynamic_cast<SavingsAccount*>(account);
                double interest;
                interest = sa->CalculateInterest();
                sa->Deposit(interest);
                cout << "Interest of $" << interest << " added to balance.\n";
                break;
            } else {
                cout << "Closing ATM Menu... Thank you for banking with us!! [XYZ Bank]\n";
                delete account;
                return 0;
            }

        case 5:
            if (accountType == 1) {
                cout << "Closing ATM Menu... Thank you for banking with us!! [XYZ Bank]\n";
                delete account;
                return 0;
            }
            [[fallthrough]];

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    delete account;
    return 0;
}