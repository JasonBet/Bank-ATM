#include "BankAccounts.h"

BankAccounts::BankAccounts(string name, int amount, int id)
{
    this->balance = amount;
    this->name = name;
    this->id = id;
}

BankAccounts::~BankAccounts()
{
    //dtor
}

string BankAccounts::getName()
{
    return this->name;
}

int BankAccounts::getBalance()
{
    return this->balance;
}

int BankAccounts::getId()
{
    return this->id;
}

int BankAccounts::withdraw(int dinero)
{
    this->balance -= dinero;
    return this->balance;
}

int BankAccounts::deposit(int moneys)
{
    this->balance += moneys;
    return this->balance;
}

double BankAccounts::balanceInDollars()
{
    double temp = this->balance;
    return temp / 100;
}
