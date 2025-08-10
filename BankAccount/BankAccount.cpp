#include "BankAccount.hpp"
#define SIZE 100

void BankAccount::logTransaction(const std::string& message) {
            log[logSize++] = message;
}

BankAccount::BankAccount(const std::string& user, double bal) 
            : owner(user), m_balance(bal), logSize(0) {
                log = new std::string[SIZE];
                logTransaction(owner + "'s Account opened");
}

BankAccount::~BankAccount () {
    delete[] log;
}

BankAccount::BankAccount(const BankAccount& other) : m_balance(other.m_balance), owner(other.owner), logSize(other.logSize) {
    log = new std::string[SIZE];
    for (int i = 0; i < logSize; ++i) {
        log[i] = other.log[i];
    }
 }

 BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this == &other) {
        return *this;
    }
    delete[] log;

    m_balance = other.m_balance;
    owner = other.owner;
    logSize = other.logSize;
    log = new std::string[SIZE];
    for (int i = 0; i < logSize; ++i) {
        log[i] = other.log[i];
    }
    return *this;
 }

 BankAccount::BankAccount(BankAccount&& other) noexcept 
    : m_balance(other.m_balance), owner(std::move(other.owner)), log(other.log), logSize(other.logSize) {
        other.log = nullptr;
        other.m_balance = 0.0;
        other.logSize = 0;
 }

 BankAccount& BankAccount::operator=(BankAccount&& other) noexcept {
        if (this == &other) return *this;

        delete[] log;
        m_balance = other.m_balance;
        owner = std::move(other.owner);
        log = other.log;
        logSize = other.logSize;
        other.log = nullptr;
        other.logSize = 0;
        other.m_balance = 0.0;
        return *this;
 }

void BankAccount::deposit(double amount) {
    m_balance += amount;
    logTransaction("Deposited: " + std::to_string(amount));
}
bool BankAccount::withdraw(double amount) {
    if (m_balance >= amount) {
        m_balance -= amount;
        logTransaction("Withdrew: " + std::to_string(amount));
        return true;
    }
    logTransaction("Not enought founds");
    return false;
}

double BankAccount::getBalance() const {
    return m_balance;
}

void BankAccount::printLog() const {
        std::cout << "\nTransaction log for " << owner << ":\n";
        for (size_t i = 0; i < logSize; ++i) {
            std::cout << "  - " << log[i] << "\n";
        }
}

SavingsAccount::SavingsAccount(const std::string& owner, double rate, double balance) 
    : BankAccount(owner, balance), interestRate(rate){}

CheckingAccount::CheckingAccount(const std::string& owner, double limit, double balance) 
    : BankAccount(owner, balance), overdraftLimit(limit) {}


bool CheckingAccount::withdraw(double amount) {
    if (BankAccount::m_balance + overdraftLimit >= amount) {
        BankAccount::m_balance -= amount;
        BankAccount::logTransaction("Withdrew with overdraft: " + std::to_string(amount));
        return true;
    }
    BankAccount::logTransaction("Overdraft limit");
    return false;
}
