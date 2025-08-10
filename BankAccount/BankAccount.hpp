#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class log {

};

class BankAccount {
    protected:
        std::string owner;
        double m_balance;
        int logSize;
        std::string* log;

        void logTransaction(const std::string& message);
    public:

        BankAccount(const std::string& user, double bal = 0.0);
        virtual ~BankAccount();

        BankAccount(const BankAccount& other);
        BankAccount& operator=(const BankAccount& other);
        BankAccount(BankAccount&& other) noexcept;
        BankAccount& operator=(BankAccount&& other) noexcept;

        virtual void deposit(double amount);
        virtual bool withdraw(double amount);
        double getBalance() const;
        void printLog() const;

};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(const std::string& owner, double rate, double balance = 0.0);
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;
public:
    CheckingAccount(const std::string& owner, double limit, double balance = 0.0);
    bool withdraw(double amount) override;
};

#endif