//
// Created by Damir on 10/7/2021.
//

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(string name, float dollars, float euros, float tenge) :
  Account(std::move(name), dollars, euros, tenge) {

  this->fee = 1.5;
}

bool CheckingAccount::Deposit(float amount, Currency currency) {
  return Account::Deposit(amount, currency);
}

bool CheckingAccount::Withdraw(float amount, Currency currency) {
  float amountOfCurrency = amount*currency*fee/100;

  if (currency == DOLLAR && dollars >= amountOfCurrency) {
    dollars -= amountOfCurrency;
  } else if (currency == EURO && euros >= amountOfCurrency) {
    euros -= amountOfCurrency;
  } else if (currency == TENGE && tenge >= amountOfCurrency) {
    tenge -= amountOfCurrency;
  } else {
    return false;
  }

  CalculateBalance();
  return true;
}
