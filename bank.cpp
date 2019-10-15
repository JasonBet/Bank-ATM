#include "bank.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;

bank::bank()
{
    this->wallFunds = 0;
}

bank::~bank()
{

}



vector<BankAccounts> bank::getAccounts() // yaya "dont cout" bla bla i got it
{
    return this->accountList;
}

void bank::addAccounts(string name, int amount)
{
    int id = this->accountList.size();
    BankAccounts temp(name, amount, id);
    this->accountList.push_back(temp);
}

void bank::deleteAccount(string name)
{
    for(int i = 0; i < this->accountList.size(); i++)
    {
        if(this->accountList[i].getName() == name)
        {
            this->accountList.erase(this->accountList.begin()+i);
        }
    }
}

string bank::displayAccount(string name)
{
    for(int i = 0; i < this->accountList.size(); i++)
    {
        if(this->accountList[i].getName() == name)
        {
            return this->accountList[i].getName();
        }
    }
}

BankAccounts bank::getOneAccount(string name)
{
    for(auto i : this->accountList)
    {
        if(name == i.getName())
        {
            return i;
        }
    }
}

double bank::investInWall(BankAccounts acc, int amount)
{
    this->wallFunds += acc.withdraw(amount);
    double temp = this-> wallFunds;
    return temp / 100;
}
