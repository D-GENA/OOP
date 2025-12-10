#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;


class Transaction {
private:
    string type;
    double amount;

public:
    Transaction(string t, double a) : type(t), amount(a) {}

    string report() const {
        return type + " of $" + to_string(amount);
    }
};


class Account {
protected:
    double balance;
    vector<Transaction> log;   
public:
    Account(double initialBalance) {
        if (initialBalance >= 1000.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Invalid Amount. Balance must be at least $1000.00.\n";
        }
    }

    virtual void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "$" << amount << " deposited successfully.\n";

            log.push_back(Transaction("Deposit", amount));
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    virtual bool Withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive.\n";
            return false;
        }

        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return false;
        }

        balance -= amount;
        cout << "Withdrawn: $" << amount << endl;

        log.push_back(Transaction("Withdrawal", amount));
        return true;
    }

    double GetBalance() const {
        return balance;
    }

   
    string report() const {
        string output = "\n~~~~~ TRANSACTION HISTORY ~~~~~\n";
        for (const Transaction& t : log) {
            output += t.report() + "\n";
        }
        output += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return output;
    }
};


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

class ChequingAccount : public Account {
private:
    double transactionFee;

public:
    ChequingAccount(double initialBalance, double fee)
        : Account(initialBalance), transactionFee(fee) {}

    bool Withdraw(double amount) override {
        if (Account::Withdraw(amount)) {
            balance -= transactionFee;
            cout << "Transaction fee of $" << transactionFee << " applied.\n";

            log.push_back(Transaction("Transaction Fee", transactionFee));
            return true;
        }
        return false;
    }
};


int main() {
    try {
        cout << "~~~ Welcome to XYZ Bank ATM System ~~~\n\n";

        int accountType;
        double initialBalance;

        cout << "Select Account Type:\n1. Savings\n2. Chequing\nEnter choice: ";
        cin >> accountType;

        if (!cin) throw runtime_error("Invalid input!");

        cout << "Enter initial balance: $";
        cin >> initialBalance;

        Account* account = nullptr;

        if (accountType == 1) {
            double rate;
            cout << "Enter interest rate (e.g., 0.05): ";
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
            throw runtime_error("Invalid account type.");
        }

        int choice;
        double amount;

        while (true) {
            cout << "\n----- MENU -----\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. View Transaction report\n";
            cout << "5. Save report to C:\\transactions.txt\n";
            cout << "6. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (!cin) throw runtime_error("Invalid menu input!");

            switch (choice) {
            case 1:
                cout << "Balance: $" << account->GetBalance() << endl;
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
                cout << account->report();
                break;

            case 5: {
                ofstream file("C:\\\\transactions.txt");
                file << account->report();
                file.close();
                cout << "Saved to C:\\transactions.txt\n";
                break;
            }

            case 6:
                cout << "Thank you for using XYZ Bank.\n";
                delete account;
                return 0;

            default:
                cout << "Invalid choice.\n";
            }
        }
    }
    catch (exception& e) {
        cout << "\nERROR: " << e.what() << endl;
    }

    return 0;
}
