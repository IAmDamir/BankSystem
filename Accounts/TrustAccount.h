//
// Created by Damir on 10/7/2021.
//

#pragma once
#ifndef BANKSYSTEM_TRUSTACCOUNT_H
#define BANKSYSTEM_TRUSTACCOUNT_H


#include "SavingsAccount.h"

class TrustAccount : protected SavingsAccount{
public:
  TrustAccount(string name, float dollars, float euros, float tenge, float interestRate);
  ~TrustAccount();

  bool Deposit(float amount, Currency currency) override;
  bool Withdraw(float amount, Currency currency) override;
};


#endif //BANKSYSTEM_TRUSTACCOUNT_H
