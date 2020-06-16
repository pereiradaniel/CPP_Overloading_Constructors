// Overloading Constructor
// Transaction.h

//Upgrade the header file for your Transaction class :
//
//    add the prototype for the four - argument constructor

class Transaction {
    int acct;
    char type;
    char desc[21];
    double amount;
public:
    Transaction();
    Transaction(int acct_, char *desc_, char type_, double amount_);
    ~Transaction();
    void enter();
    void display() const;
};