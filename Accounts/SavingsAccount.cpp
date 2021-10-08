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

void SavingsAccount::Print(ostream& out) {
  out << "--------------------------------------------------" << endl;
  out << "This is " << name << "'s Savings account" << endl;
  out << "Your current balance is" << endl;
  out << "Tenge: " << tenge << endl;
  out << "Euros: " << euros << endl;
  out << "Dollars: " << dollars << endl;
  out << "Total in Tenge: " << balance << endl;
  out << "Your interest rate is: " << interestRate << endl;
  out << "--------------------------------------------------" << endl;
}

float SavingsAccount::getInterestRate() const {
  return interestRate;
}

void SavingsAccount::setInterestRate(float interestRate) {
  SavingsAccount::interestRate = interestRate;
}
