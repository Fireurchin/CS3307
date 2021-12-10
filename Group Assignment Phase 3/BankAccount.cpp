/*
Name: Khaleel, last push by Mingpei
Class: CS3307
Date: 2021-11-07
Desc: The bank account the stores the users balance and can manipulate said balance
*/

// imports
#include <BankAccount.h>

double balance; // the amount of money in the account

/**
 * @brief Construct a new Bank Account:: Bank Account object
 * 
 */
BankAccount::BankAccount(){
    balance = 0; // set intial balance to 0
} // end method

void BankAccount::resetHoldings(){ // resets account holdings
  balance = 0; // resets balance to 0
}

/**
 * @brief Destroy the Bank Account:: Bank Account object
 * 
 */
BankAccount::~BankAccount(){}

/**
 * @brief Tries to withdraw money from the bank
 * 
 * @param amount 
 * @return true if we have listed funds
 * @return false if we do not have funds
 */
bool BankAccount::withdraw(double amount){
    if(balance >= amount){
        balance -= amount;
        return true;
    } // end if
    return false;
} // end method

/**
 * @brief Deposits money into the account
 * 
 * @param amount 
 */
void BankAccount::deposit(double amount){
    balance += amount;
} // end method

/**
 * @brief Gets the balance of the account
 * 
 * @return double value of balance
 */
double BankAccount::getBalance(){
    return balance;
} // end method