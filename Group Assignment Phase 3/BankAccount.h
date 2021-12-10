#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

/**
 * @brief The class that holds the BankAccount object
 * 
 */
class BankAccount{
        private:
            double balance;

        public:
                BankAccount(); // the constructor
                ~BankAccount(); // the deconstructor
                bool withdraw(double amount); // withdraws money into the account if funds are available
                void deposit(double amount); // deposits money into the account
                double getBalance(); // gets the accounts balance
}; // end class

#endif // !
