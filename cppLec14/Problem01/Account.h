#ifndef ACCOUNT_H
#define ACCOUNT_H

class NegativeDeposit {
public:
    NegativeDeposit() {}
};

class InsufficientFunds {
public:
    InsufficientFunds() {}
};

class Account
{
private:
    double balance;
    
public:
    Account() { balance = 0; }
    Account(double initialDeposit) { balance = initialDeposit; }
    double getBalance() { return balance; }
    
    //returns new balance or NegativeDeposit if error
    double deposit(double amount)
    {
        NegativeDeposit ex;
        if (amount > 0) balance += amount;
        else throw ex;
        return balance;
    }
    
    //return new balance or InsufficientFunds if invalid amount
    double withdraw(double amount)
    {
        InsufficientFunds ex;
        if ((amount > balance) || (amount < 0)) throw ex;
        else balance -= amount;
        return balance;
    }
};

#endif
