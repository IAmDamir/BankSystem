//
// Created by Damir on 10/7/2021.
//

#pragma once
#ifndef BANKSYSTEM_CHECKINGACCOUNT_H
#define BANKSYSTEM_CHECKINGACCOUNT_H


#include "Account.h"

class CheckingAccount : public Account{
public:
  explicit CheckingAccount(string name = "Unknown account",
                           float dollars = 0, float euros = 0, float tenge = 0);
  ~CheckingAccount() override;

  bool Deposit(float amount, Currency currency) override;
  bool Withdraw(float amount, Currency currency) override;
  void Print(ostream &out) override;

  float getFee() const;

  void setFee(float fee);

private:
  float fee;
};


#endif //BANKSYSTEM_CHECKINGACCOUNT_H
