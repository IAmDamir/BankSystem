//
// Created by Damir on 10/6/2021.
//

#pragma once
#ifndef BANKSYSTEM_SAVINGSACCOUNT_H
#define BANKSYSTEM_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
  explicit SavingsAccount(string name = "Unknown Account",
                          float dollars = 0, float euros = 0, float tenge = 0, float interestRate = 1);
  ~SavingsAccount() override;

  bool Deposit(float amount, Currency currency) override;
  bool Withdraw(float amount, Currency currency) override;
  void Print(ostream &out) override;

  float getInterestRate() const;

  void setInterestRate(float interestRate);

protected:
  float interestRate;
};


#endif //BANKSYSTEM_SAVINGSACCOUNT_H
