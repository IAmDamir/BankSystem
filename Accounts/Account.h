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

  // Calculates how much balance you have depending on amount of money you have in each currency
  void CalculateBalance();
  // Adds money to your account
  virtual bool Deposit(float amount, Currency currency) = 0;
  // Removes money frm your account, the value removed cannot be more than you already have
  virtual bool Withdraw(float amount, Currency currency) = 0;
  /* I haven't understood how and why we should overload operator through the other interface
   * while we already have the abstract class for these purposes, so I decided to overload ostream operator here
   */
  // This function calls another function called Print() since overloaded operators cannot be abstract
  friend ostream& operator<<(ostream& out, Account& account);
  // Actually outputs our class
  virtual void Print(ostream& out) = 0;

  // Setters
  void setName(const string &name);
  void setDollars(float dollars);
  void setEuros(float euros);
  void setTenge(float tenge);
  // Getters
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
