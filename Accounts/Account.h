//
// Created by Damir on 10/4/2021.
//

#pragma once
#ifndef BANKSYSTEM_ACCOUNT_H
#define BANKSYSTEM_ACCOUNT_H

#include <string>
#include <cmath>
#include <iostream>
#include "Currency.h"

using namespace std;

class Account {
public:
  explicit Account(string name = "Unnamed Account", float dollars = 0.0, float euros = 0.0, float tenge = 0.0);
  virtual ~Account() = 0;

  void CalculateBalance();
  virtual bool Deposit(float amount, Currency currency) = 0;
  virtual bool Withdraw(float amount, Currency currency) = 0;
  virtual void Print(ostream& out) = 0;

  friend ostream& operator<<(ostream& out, Account& account);

  void setName(const string &name);

  void setDollars(float dollars);

  void setEuros(float euros);

  void setTenge(float tenge);

  const string &getName() const;

  float getDollars() const;

  float getEuros() const;

  float getTenge() const;

protected:
  string name;
  // balance = dollars + euros + tenge
  // balance is calculated in tenge
  float balance;
  float dollars;
  float euros;
  float tenge;
};


#endif //BANKSYSTEM_ACCOUNT_H
