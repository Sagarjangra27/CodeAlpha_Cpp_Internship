#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction
{
public:
    string type;
    double amount;

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }
};

class Account
{
public:
    int accountNumber;
    double balance;
    vector<Transaction> history;

    Account(int accNo)
    {
        accountNumber = accNo;
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposit Successful!\n";
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        history.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrawal Successful!\n";
    }

    void transfer(Account &receiver, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        history.push_back(Transaction("Transfer Sent", amount));
        receiver.history.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer Successful!\n";
    }

    void showTransactions()
    {
        cout << "\nTransaction History\n";

        if (history.empty())
        {
            cout << "No Transactions Found.\n";
            return;
        }

        for (int i = 0; i < history.size(); i++)
        {
            cout << i + 1 << ". "
                 << history[i].type
                 << " : Rs. " << history[i].amount << endl;
        }
    }

    void displayAccount()
    {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }
};

class Customer
{
public:
    string name;
    Account account;

    Customer(string n, int accNo) : account(accNo)
    {
        name = n;
    }

    void displayCustomer()
    {
        cout << "\nCustomer Name : " << name << endl;
        account.displayAccount();
    }
};

int main()
{
    Customer c1("Sagar", 1001);
    Customer c2("Rahul", 1002);

    int choice;
    double amount;

    do
    {
        cout << "\n===== Banking System =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. View Account Details\n";
        cout << "5. View Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            c1.account.deposit(amount);
            break;

        case 2:
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            c1.account.withdraw(amount);
            break;

        case 3:
            cout << "Enter Transfer Amount: ";
            cin >> amount;
            c1.account.transfer(c2.account, amount);
            break;

        case 4:
            c1.displayCustomer();
            break;

        case 5:
            c1.account.showTransactions();
            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}