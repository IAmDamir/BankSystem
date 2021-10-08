#include <iostream>

#include "Accounts/TrustAccount.h"
#include "Accounts/CheckingAccount.h"

int main() {
  Account *savingsAccount = new SavingsAccount();

  savingsAccount->Deposit(122, DOLLAR);
  savingsAccount->Withdraw(123, DOLLAR);

  cout << *savingsAccount;

  savingsAccount->Withdraw(122, DOLLAR);

  cout << *savingsAccount;


  CheckingAccount checkingAccount;

  checkingAccount.Deposit(123, EURO);
  checkingAccount.Withdraw(104.55, EURO);

  cout << checkingAccount;


  Account *trustAccount = new TrustAccount();

  trustAccount->Deposit(1500, EURO);

  cout << *trustAccount;

  delete savingsAccount;
  delete trustAccount;
  return 0;
}
