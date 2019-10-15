#include <iostream>
#include <limits>
#include "BankAccounts.h"
#include "bank.h"
#include <stdlib.h> //for clear screen
#include <string>
#include <iomanip>

using std::string;


int menuPrompt(bank&);
void menuSelect(int, bank&);
void menuAddAccount(bank&);
void menuDeleteAccount(bank&);
void accountOptions(bank&);
void accountInfo(bank&);
bool accountVerify(bank&, string);


int main()
{
    bank jpAson;

    while(menuPrompt(jpAson)!= 5)
    {
        menuPrompt(jpAson);
    }

    return 0;
}

int menuPrompt(bank& jpAson)
{
    int input, menu;
    std::cout << "Press the number corresponding to the menu you would like to enter (press 4 to quit)" << std::endl;
    std::cout << "\n1. Add Account\n2. Delete Account\n3. Deposit/Withdraw from account\n4. Account Info\n5. QUIT" << std::endl << std::endl;

    std::cin >> input;
    menu = input;

    menuSelect(menu, jpAson);

    return input;
}

void menuSelect(int menu, bank& jpAson) //probs dont need this to be a whole ass function but looks cleaner
{
    //how to include vector to keep track of account instances?

    std::cin.ignore(); // I hope there is a better way to utilize this without having to spam

    switch(menu)
    {
    case 1 :
        {
            menuAddAccount(jpAson);

            break;
        }

    case 2 :
        {
            menuDeleteAccount(jpAson);

            break;
        }

    case 3 :
        {
            accountOptions(jpAson);
            break;
        }

    case 4 :
        {
            accountInfo(jpAson);
            break;
        }
    case 5:
        {
            exit(0);
            break;
        }

    default:
        std:: cout << "Try again" << std::endl;
        menuPrompt(jpAson);
        break;

    }


}
void menuAddAccount(bank& jpAson)
{
    string name;
            int amount;

            std::cout << "What would you like to name the account?" << std::endl;
            std::getline(std::cin, name); //getline not working

            std::cout << "What is the starting amount for this account?" << std::endl;
            std::cout << "(In Cents)";
            std::cin >> amount;

            jpAson.addAccounts(name, amount);

            for (auto i : jpAson.getAccounts())
            {
                std::cout << i.getName() << i.getBalance()<< '\n';
            }
}

void menuDeleteAccount(bank& jpAson)
{
    string name;

    std::cout << "Please enter the name of the account you would like to delete: ";

    std::getline(std::cin,name);

    jpAson.deleteAccount(name);

    for (auto i : jpAson.getAccounts())
        {
            std::cout << i.getName() << i.getBalance()<< '\n';
        }
}

void accountOptions(bank& jpAson)
{
    int menu3;
    std::cout << "Press the number corresponding to the action you would like to make\n";
    std::cout << "1. Withdraw\n2. Deposit\n3. Invest in Wall\n4. Go Back" << std::endl;

    std::cin >> menu3;

    switch(menu3)
            {

            case 1 :
                {
                    string name;
                    int amount;


                    std::cout << "Which account would you like to withdraw from?" << std::endl;
                    std::cin.ignore();

                    std::getline(std::cin,name);


                    if(accountVerify(jpAson, name))
                    {
                        std::cout << "How much would you like to withdraw (In Cents): " << jpAson.displayAccount(name) << std::endl;
                        std::cin >> amount;
                        std::cin.ignore();
                        std::cout << jpAson.getOneAccount(name).withdraw(amount);

                    }
                    else
                    {
                        std::cout << "This account does not exist" << std::endl;
                        accountOptions(jpAson);
                    }



                    break;
                }
            case 2 :
                {

                    string name;
                    int amount;


                    std::cout << "Which account would you like to deposit to?" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin,name);

                    if(accountVerify(jpAson, name))
                    {
                        std::cout << "How much would you like to deposit (In Cents): " << jpAson.displayAccount(name) << std::endl;
                        std::cin >> amount;
                        std::cin.ignore();
                        std::cout << jpAson.getOneAccount(name).deposit(amount);

                    }
                    else
                    {
                        std::cout << "This account does not exist" << std::endl;
                        accountOptions(jpAson);
                    }
                    break;


                }
            case 3 :
                {
                    string name;
                    int amount;


                    std::cout << "Which account would you like to invest in the wall with?" << std::endl;
                    std::cin.ignore();

                    std::getline(std::cin,name);


                    if(accountVerify(jpAson, name))
                    {
                        std::cout << "How much would you like to invest in the wall (In Cents): " << jpAson.displayAccount(name) << std::endl;
                        std::cin >> amount;
                        std::cin.ignore();
                        std::cout << jpAson.investInWall(jpAson.getOneAccount(name),amount);

                    }
                    else
                    {
                        std::cout << "This account does not exist" << std::endl;
                        accountOptions(jpAson);
                    }



                    break;
                }
            case 4:
                {
                    menuPrompt(jpAson);
                    break;
                }
            default:
                {
                    std::cout << "Try Again" << std::endl;
                    accountOptions(jpAson);
                    break;
                }
            }

}
void accountInfo(bank& jpAson)
{
    string account;
    std::cout << "Please Enter the Name of Your Account\n";


    std::getline(std::cin,account);


    if(accountVerify(jpAson, account))
    {
        std::cout << "Your account has a balance of: $";
        std::cout << std::fixed << std::showpoint << std::setprecision(2) << jpAson.getOneAccount(account).balanceInDollars() << std::endl;


    }
    else
    {
        std::cout << "This account does not exist" << std::endl;
        accountOptions(jpAson);

    }

}

bool accountVerify(bank& jpAson, string acc)
{
    if(acc == jpAson.displayAccount(acc))
    {
        return true;
    }
    else
        return false;

}
