/*
Name: Khaleel
Class: CS3307
Date: 2021-11-07
Desc: The game manager that holds all the objects and manages the game
*/

// imports
#include <GameManager.h>


// Initialize Businesses in ID order
Business tutor; // id = 1
Business spoke; // id = 2
Business wave; // id = 3
Business bookStore; // id = 4
Business theater; // id = 5
Business bikeRental; // id = 6

// Initialize Bank
BankAccount account();

// Initialize UI
// RAOUF WOULD Integrate here


/**
 * @brief Construct a new Game Manager:: Game Manager object
 */
GameManager::GameManager(){
    tutor = Business(1.07f, 1.0f, 1, 10.0, 1.0f, 4.0);
    spoke = Business(1.15f, 1.0f, 0, 50.0, 5.0f, 10.0);
    wave = Business(1.30f, 1.0f, 0, 100.0, 50.0f, 32.30);
    bookStore = Business(1.50f, 1.0f, 0, 500.0, 50.0f, 82.60);
    theater = Business(1.62f, 1.0f, 0, 1000.0, 120.0f, 231.40);
    bikeRental = Business(2.0f, 1.0f, 0, 5000.0, 180.0f, 666.66);

    account = BankAccount();
    account.deposit(0);
} // end method

/**
 * @brief Destroy the Game Manager:: Game Manager object
 */
GameManager::~GameManager(){

} // end method

/**
 * @brief Takes the business id, and updates the according business if the funds are available
 * @return returns the new balance
 * @param businessID 
 */
double GameManager::upgradeBusiness(int businessID){
    Business temp; // the temporary business

    // Set the business we are working on
    switch(businessID){
        case 1:
            temp = tutor;
            break;
        case 2:
            temp = spoke;
            break;
        case 3:
            temp = wave;
            break;
        case 4:
            temp = bookStore;
            break;
        case 5:
            temp = theater;
            break;
        case 6:
            temp = bikeRental;
    } // end switch
    int cost = temp.costToUpgrade(temp.getBusinessLevel() + 1);
    // if we have the funds, buy the upgrade
    if(cost <= account.getBalance()){
        //std::cout << temp.getBusinessLevel() << std::endl;    
        //std::cout << account.getBalance() << std::endl;   
        account.withdraw(cost);
        temp.upgradeBusiness(temp.getBusinessLevel() + 1);
        //std::cout << temp.getBusinessLevel() << std::endl;
        //std::cout << account.getBalance() << std::endl;   
    } // end if

    // update the businesses
    switch(businessID){
        case 1:
            tutor = temp;
            break;
        case 2:
            spoke = temp;
            break;
        case 3:
            wave = temp;
            break;
        case 4:
            bookStore = temp;
            break;
        case 5:
            theater = temp;
            break;
        case 6:
            bikeRental = temp;
    } // end switch

    // ==COULD CALL UPDATE() HERE TO SHOW CHANGE IN BANK ACCOUNT==
    return account.getBalance();
} // end method

/**
 * @brief Runs the business, storing the revenue in the bank account
 * @param businessID 
 * @return returns the new balance
 */
double GameManager::runBusiness(int businessID){ // ADD BACK IN ONCE BankAccount IS INTEGRATED
    Business temp;
    switch(businessID){
        case 1:
            temp = tutor;
            break;
        case 2:
            temp = spoke;
            break;
        case 3:
            temp = wave;
            break;
        case 4:
            temp = bookStore;
            break;
        case 5:
            temp = theater;
            break;
        case 6:
            temp = bikeRental;
    } // end switch

    //std::cout << account.getBalance() << std::endl;
    account.deposit((double) (temp.getRevenue() * (double) temp.getBusinessLevel()/10)); // Later add a timer before adding money to business
    //std::cout << account.getBalance() << std::endl;

    return account.getBalance();
} // end method

BankAccount GameManager:resetAccounts(){
  account.resetHoldings(); // calls reset command in BankAssount
} // end method

BankAccount GameManager::getAccount(){
    return account;
} // end method

double GameManager::getUpgradeCost(int businessID){
    Business temp;
    switch(businessID){
        case 1:
            temp = tutor;
            break;
        case 2:
            temp = spoke;
            break;
        case 3:
            temp = wave;
            break;
        case 4:
            temp = bookStore;
            break;
        case 5:
            temp = theater;
            break;
        case 6:
            temp = bikeRental;
    } // end switch

    return temp.costToUpgrade(temp.getBusinessLevel() + 1);
} // end method

int GameManager::getBusinessLevel(int businessID){
    Business temp;
    switch(businessID){
        case 1:
            temp = tutor;
            break;
        case 2:
            temp = spoke;
            break;
        case 3:
            temp = wave;
            break;
        case 4:
            temp = bookStore;
            break;
        case 5:
            temp = theater;
            break;
        case 6:
            temp = bikeRental;
    } // end switch

    return temp.getBusinessLevel();
} // end method

void GameManager::resetBusiness(){
  tutor.resetBusiness();
  spoke.resetBusiness();
  wave.resetBusiness();
  bookStore.resetBusiness();
  theatre.resetBusiness();
  bikeRental.resetBusiness();
}

double GameManager::getBusinessRevenue(int businessID){
    Business temp;
    switch(businessID){
        case 1:
            temp = tutor;
            break;
        case 2:
            temp = spoke;
            break;
        case 3:
            temp = wave;
            break;
        case 4:
            temp = bookStore;
            break;
        case 5:
            temp = theater;
            break;
        case 6:
            temp = bikeRental;
    } // end switch

    return temp.getRevenue();
} // end method