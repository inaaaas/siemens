#include "BankAccount.hpp"

int main() {
    SavingsAccount sa("Alice", 0.05, 1000);
    CheckingAccount ca("Bob", 500, 200);

    sa.deposit(200);
    sa.withdraw(100);

    ca.withdraw(600);
    ca.deposit(300);

    sa.printLog();

    ca.printLog();

    return 0;
}