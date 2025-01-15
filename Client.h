#pragma once
#include "Person.h"
class Client :
    public Person
{

private:
    double balance;

public:
    // Constructors:
    Client() : Person() {
        this->balance = 1500.0;

    }

    Client(string name, int id, string password, double balance) : Person(name, id, password) {
        setBalance(balance);

    }

    // Setters:
    void setBalance(double balance) {
        if (Validation::validBalance(balance)) {
            this->balance = balance;
        }
        else {
            cout << "Min balance is 1500 " << endl;
            cout << "Please Enter Valid Balance " << endl;
            double new_balance;
            cin >> new_balance;
            setBalance(new_balance);
        }

    }

    // Getters:
    double getBalance() {
        return this->balance;
    }

    // Methods:
    void DisplayInfo() {
        cout << "Name : " << this->getName() << endl;
        cout << "Id : " << this->getId() << endl;
        cout << "Balance = " << this->getBalance() << endl;
        cout << "==============================\n";
    }

    void CheckBalance() {
        cout << "Balance = " << this->getBalance() << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            cout << "Deposit Done Successfully" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance && amount > 0.0) {
            this->balance -= amount;
            cout << "Withdraw Done Successfully" << endl;
        }
        else {
            cout << "Failed, Insufficient balance" << endl;
        }
    }

    void transferTo(Client& client2, double amount) {
        if (amount <= balance && amount > 0) {
            this->balance -= amount;
            client2.balance += amount;
            cout << "Transfer Done Successfully" << endl;
        }
        else {
            cout << "Failed, Insufficient balance" << endl;
        }
    }

   
};

static vector <Client> AllClients;
static vector <Client>::iterator clIt;