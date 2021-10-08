#include <iostream>

#include "Accounts/TrustAccount.h"
#include "Accounts/CheckingAccount.h"

int main() {
  Account *account = new SavingsAccount();

  account->Deposit(122, DOLLAR);
  account->Withdraw(123, DOLLAR);

  cout << *account;

  account->Withdraw(122, DOLLAR);

  cout << *account;

  delete account;

  account = new CheckingAccount();

  account->Deposit(123, EURO);
  account->Withdraw(104.55, EURO);

  cout << *account;

  delete account;

  account = new TrustAccount();

  account->Deposit(1500, EURO);
  account->Withdraw(1500*0.2, EURO);

  cout << *account;

  delete account;
  return 0;
}
