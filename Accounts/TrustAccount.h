//
// Created by Damir on 10/7/2021.
//

#pragma once
#ifndef BANKSYSTEM_TRUSTACCOUNT_H
#define BANKSYSTEM_TRUSTACCOUNT_H


#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount{
public:
  explicit TrustAccount(string name = "Unknown account",
               float dollars = 0, float euros  = 0, float tenge = 0, float interestRate = 0);
  ~TrustAccount() override;

  bool Deposit(float amount, Currency currency) override;
  bool Withdraw(float amount, Currency currency) override;
  void Print(ostream &out) override;
};


#endif //BANKSYSTEM_TRUSTACCOUNT_H
