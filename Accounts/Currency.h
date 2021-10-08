//
// Created by Damir on 10/6/2021.
//

#pragma once

#ifndef BANKSYSTEM_CURRENCY_H
#define BANKSYSTEM_CURRENCY_H
// Enumerator that contains each currency and the value of them compared to TENGE
// TODO consider making constructor instead of enum,
// TODO since we need to dynamically assign the values of each currency
enum Currency {
  DOLLAR = 3,
  EURO = 2,
  TENGE = 1
};

#endif //BANKSYSTEM_CURRENCY_H
