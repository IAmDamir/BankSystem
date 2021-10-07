//
// Created by Damir on 10/6/2021.
//

#pragma once
#ifndef BANKSYSTEM_SAVINGSACCOUNT_H
#define BANKSYSTEM_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : protected Account {
public:
  explicit SavingsAccount(string name, float dollars, float euros, float tenge, float interestRate = 1.0);
  ~SavingsAccount();

  bool Deposit(float amount, Currency currency) override;
  bool Withdraw(float amount, Currency currency) override;

protected:
  float interestRate;
};


#endif //BANKSYSTEM_SAVINGSACCOUNT_H
