cmake_minimum_required(VERSION 3.20)
project(BankSystem)

set(CMAKE_CXX_STANDARD 20)
add_executable(main main.cpp Accounts/Currency.h
                Accounts/Account.cpp Accounts/Account.h
                Accounts/SavingsAccount.cpp Accounts/SavingsAccount.h
                Accounts/CheckingAccount.cpp Accounts/CheckingAccount.h
                Accounts/TrustAccount.cpp Accounts/TrustAccount.h
        )