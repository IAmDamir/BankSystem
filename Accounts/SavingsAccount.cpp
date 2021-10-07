//
// Created by Damir on 10/6/2021.
//


#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(string name, float dollars, float euros, float tenge, float interestRate) :
  Account(move(name), dollars, euros, tenge){

  this->interestRate = interestRate;
}

SavingsAccount::~SavingsAccount() = default;

bool SavingsAccount::Deposit(float amount, Currency currency) {
  if (Account::Deposit(amount, currency)) {
    interestRate *= 1 + ((interestRate/100)*currency);
    // Making interestRate precision to 2 digits.
    interestRate = round(interestRate*100)/100;
    return true;
  }
  return false;
}

bool SavingsAccount::Withdraw(float amount, Currency currency) {
  return Account::Withdraw(amount, currency);
}
