// Overloading Constructor
// Transaction.cpp

//Upgrade the implementation file for your Transaction type :
//
//add the definition for the four - argument constructor
//add the logic for validating data to your four - argument constructor
//call the four - argument constructor from the enter() function

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Transaction.h"

Transaction::Transaction() {
    acct = 0;
    desc[0] = '\0';
    type = 'd';
    amount = 0.0;
}

Transaction::Transaction(int acct_, char *desc_, char type_, double amount_) {
    
    if (acct_ > 0 && *desc_ != '\0' && (type_ == 'd' || type_ == 'c') && amount_ > 0.0) {
        acct = acct_;
        strcpy_s(desc, desc_);
        type = type_;
        amount = amount_;
    }
    else {
        cout << "Invalid data!";
    }
 
}

Transaction::~Transaction() { }

void Transaction::enter() {

    // local variables accept input temporarily
    int      acct_;
    char     type_;
    char desc_[21];
    double amount_;

    // store input from the user in the local variables
    cout << "Enter the account number : ";
    cin >> acct_; ;
    cin.ignore();
    cout << "Enter the desription : ";
    cin.getline(desc_, 21);
    cout << "Enter the account type (d for debit, c for credit) : ";
    cin >> type_; ;
    cout << "Enter the account amount : ";
    cin >> amount_;

    Transaction temp(acct_, desc_, type_, amount_);
    *this = temp;

}

void Transaction::display() const {

    if (acct != 0) {
        cout << setw(10) << acct;
        cout << ' ' << setw(20) << left << desc << right;
        cout << setprecision(2) << fixed;
        if (type == 'd')
            cout << setw(20) << amount;
        else
            cout << setw(10) << amount;
    }
    else
        cout << "no data available" << endl;
}