//
// Created by Damir on 10/4/2021.
//

#include "Account.h"

Account::Account(string name, float dollars, float euros, float tenge) {
  this->name = std::move(name);
  this->dollars = dollars;
  this->euros = euros;
  this->tenge = tenge;
  CalculateBalance();
}

Account::~Account() = default;

void Account::CalculateBalance() {
  // Rounds each currency before starting calculating
  dollars = round(dollars*100)/100;
  euros = round(euros*100)/100;
  tenge = round(tenge*100)/100;

  balance = dollars*DOLLAR;
  balance += euros*EURO;
  balance += tenge*TENGE;
}

bool Account::Deposit(float amount, Currency currency) {
  switch (currency) {
    case DOLLAR:
      dollars += amount;
      break;
    case EURO:
      euros += amount;
      break;
    case TENGE:
      tenge += amount;
      break;
  }

  CalculateBalance();

  return true;
}

bool Account::Withdraw(float amount, Currency currency) {
  if (currency == DOLLAR && dollars >= amount) {
    dollars -= amount;
  } else if (currency == EURO && euros >= amount) {
    euros -= amount;
  } else if (currency == TENGE && tenge >= amount) {
    tenge -= amount;
  } else {
    return false;
  }

  CalculateBalance();

  return true;
}

ostream &operator<<(ostream &out, Account &account) {
  account.Print(out);
  return out;
}

const string &Account::getName() const {
  return name;
}
float Account::getDollars() const {
  return dollars;
}
float Account::getEuros() const {
  return euros;
}
float Account::getTenge() const {
  return tenge;
}

void Account::setName(const string &name) {
  Account::name = name;
}
void Account::setDollars(float dollars) {
  Account::dollars = dollars;
}
void Account::setEuros(float euros) {
  Account::euros = euros;
}
void Account::setTenge(float tenge) {
  Account::tenge = tenge;
}