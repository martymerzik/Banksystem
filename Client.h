#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"
#include <vector>
using namespace std;
class Client : public Person {
private:
    double balance;
public:
    static vector<Client> allClients;

    Client(int id, string name, string password, double balance) : Person(id, name, password) {
        if (Validation::validationbalance(balance)) {
            this->balance = balance;
        }
        else
            cout << "invlide balance\n";
    }
    void setBalance(double balance) {
        if (Validation::validationbalance(balance)) {
            this->balance = balance;
        }
        else
        cout << "invlide balance\n";

    }
    double getBalance() {
        return this->balance;
    }
    //*methods
    double Deposit(double amount) {
        this->balance += amount;
        return balance;
    }
    double Withdraw(double amount) {
        if (amount <= balance) {
            this->balance -= amount;
            return balance;
        }
        else
            cout << "Amount exceeds\n";

    }

    double TransferTO(Client& recipient, double amount) {
        if (amount <= balance) {
            balance -= amount;
            recipient.Deposit(amount);
        }
        else
            cout << "Amount exceeds\n";
    }
    void CheckBalance() {
        cout << "Balance: " << getBalance << endl;
    }

    void Display() {
        Person::Display;
        cout << "Balance :" << getBalance << endl;
    }


};
vector<Client> Client::allClients;



