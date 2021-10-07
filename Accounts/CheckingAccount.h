//
// Created by Damir on 10/7/2021.
//

#pragma once
#ifndef BANKSYSTEM_CHECKINGACCOUNT_H
#define BANKSYSTEM_CHECKINGACCOUNT_H


#include "Account.h"

class CheckingAccount : Account{
public:
  CheckingAccount(string name, float dollars, float euros, float tenge);

  bool Deposit(float amount, Currency currency) override;
  bool Withdraw(float amount, Currency currency) override;
private:
  float fee;
};


#endif //BANKSYSTEM_CHECKINGACCOUNT_H
