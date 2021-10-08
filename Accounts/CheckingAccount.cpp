//
// Created by Damir on 10/7/2021.
//

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(string name, float dollars, float euros, float tenge) :
  Account(std::move(name), dollars, euros, tenge) {

  this->fee = 15.0;
}

CheckingAccount::~CheckingAccount() = default;

bool CheckingAccount::Deposit(float amount, Currency currency) {
  return Account::Deposit(amount, currency);
}

bool CheckingAccount::Withdraw(float amount, Currency currency) {
  float amountOfCurrency = amount + amount*(fee/100);

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

void CheckingAccount::Print(ostream &out) {
  out << "--------------------------------------------------" << endl;
  out << "This is " << name << "'s Checking account" << endl;
  out << "Your current balance is" << endl;
  out << "Tenge: " << tenge << endl;
  out << "Euros: " << euros << endl;
  out << "Dollars: " << dollars << endl;
  out << "Total in Tenge: " << balance << endl;
  out << "Your fee is: " << fee << '%' << endl;
  out << "--------------------------------------------------" << endl;
}

float CheckingAccount::getFee() const {
  return fee;
}

void CheckingAccount::setFee(float fee) {
  CheckingAccount::fee = fee;
}
