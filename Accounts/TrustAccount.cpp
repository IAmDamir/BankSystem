//
// Created by Damir on 10/7/2021.
//

#include "TrustAccount.h"

TrustAccount::TrustAccount(string name, float dollars, float euros, float tenge, float interestRate) :
SavingsAccount(std::move(name), dollars, euros, tenge, interestRate) {}

bool TrustAccount::Deposit(float amount, Currency currency) {
  SavingsAccount::Deposit(amount, currency);

  switch (currency) {
    case DOLLAR:
      if (amount >= 1000) {
        dollars += 10;
      }
      break;
    case EURO:
      if (amount/EURO * DOLLAR >= 1000) {
        euros += 10.0 / DOLLAR * EURO;
      }
      break;
    case TENGE:
      if (amount/TENGE * DOLLAR >= 1000) {
        tenge += 10.0 / DOLLAR * TENGE;
      }
      break;
  }

  return true;
}

bool TrustAccount::Withdraw(float amount, Currency currency) {
  if (balance * 0.2 > amount*currency) {
    return Account::Withdraw(amount, currency);
  }

  return false;
}

void TrustAccount::Print(ostream &out) {
  out << "--------------------------------------------------" << endl;
  out << "This is " << name << "'s Trust account" << endl;
  out << "Your current balance is" << endl;
  out << "Tenge: " << tenge << endl;
  out << "Euros: " << euros << endl;
  out << "Dollars: " << dollars << endl;
  out << "Total in Tenge: " << balance << endl;
  out << "Your interest rate is: " << interestRate << endl;
  out << "--------------------------------------------------" << endl;
}

TrustAccount::~TrustAccount() = default;

