#ifndef BANKACCOUNTS_H
#define BANKACCOUNTS_H
#include <string>

using std::string;

/// A beauty

class BankAccounts
{
    public:
        BankAccounts(string, int, int);
        virtual ~BankAccounts();
        string getName();
        int getBalance();
        int getId();

        int withdraw(int);
        int deposit(int);

        double balanceInDollars();


    private:
        std::string name;
        int balance;
        int id;
};

#endif // BANKACCOUNTS_H
