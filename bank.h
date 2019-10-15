#ifndef BANK_H
#define BANK_H
#include "BankAccounts.h"
#include <vector>
#include <string>
#include <iostream>
using std::string;
using std::vector;

/// Magnificento

class bank
{
    public:
        bank();
        virtual ~bank();
        vector<BankAccounts> getAccounts();
        BankAccounts getOneAccount(string);
        void addAccounts(string, int);
        void deleteAccount(string);
        string displayAccount(string);
        double investInWall(BankAccounts, int);

    private:
        vector<BankAccounts> accountList;
        int wallFunds;

};

#endif // BANK_H
