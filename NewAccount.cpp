#include "NewAccount.h"
#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;

void account::create_account()
{
    cout << "\nEnter The account No. : "; cin >> acno;
    cout << "\n\nEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name, 50);
   
    cout << "\n\nPlease enter your new PIN Number: \n";
    cin >> PIN;

    while (!(cin >> PIN)) 
    {
        cout << "Error: Please enter a valid PIN: ";
        cin.clear();
        cin.ignore();
    }
    


    cout << "\n\nPlease re-enter your PIN to Verify:";
    cin >> VerifyPIN;

    while (!(VerifyPIN == PIN)) {
        cout << "The PINs do not match, please enter it again to match: ";

        cin.clear();
        cin.ignore();
    }

    cout << "\nEnter Type of The account (C/S) : "; cin >> type;
    while ((type != 'S') && (type != 'C')) {
        cout << "Invalid Account type, please try again: ";

        cin.clear();
        cin.ignore();
    }

    type = toupper(type);
    cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
    cin >> deposit;
    cout << "\n\n\nAccount Created..";
}

void account::show_account() const
{
    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Holder Name : ";
    cout << name;
    cout << "\nType of Account : " << type;
    cout << "\nBalance amount : " << deposit;
}


void account::modify()
{
    cout << "\nAccount No. : " << acno;
    cout << "\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nModify Type of Account : "; cin >> type;
    type = toupper(type);
    cout << "\nModify Balance amount : "; cin >> deposit;
}


void account::dep(int x)
{
    deposit += x;
}

void account::draw(int x)
{
    deposit -= x;
}

void account::report() const
{
    cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

int account::retacno() const
{
    return acno;
}

int account::retpin() const
{
    return PIN;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const
{
    return type;
}
