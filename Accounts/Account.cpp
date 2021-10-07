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
  float amountOfCurrency = amount*currency;

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
