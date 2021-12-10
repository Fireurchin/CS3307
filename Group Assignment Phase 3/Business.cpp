/*
Name: Khaleel, Last commit by Mingpei
Class: CS3307
Date: 2021-11-07
Desc: The game manager that holds all the objects and manages the game
*/

// imports
#include <Business.h>

// Initialize variable (given some default variables, to be modified later)
float upgradeModifier = 1.15; // the modifier to upgrade
float managerModifier = 0.9; // if the manager makes cost to upgrade 10% cheaper
int businessLevel = 0; // the level the business is at
double basePrice = 60; // the first cost to buy business
float revenueDelay = 2.0f; // the delay before revenue is deposited
double revenue = 4; // the amount of revenue the business when ran
//Manager assignedManager;

/**
 * @brief Construct a new Business:: Business object
 * 
 */
Business::Business(){

} // end default constructor

/**
 * @brief Construct a new Business:: Business object
 * 
 * @param _upgradeModifier 
 * @param _managerModifier 
 * @param _businessLevel 
 * @param _basePrice 
 * @param _revenueDelay 
 * @param _revenue 
 */
Business::Business(float _upgradeModifier, float _managerModifier, int _businessLevel, double _basePrice, float _revenueDelay, double _revenue){
    upgradeModifier = _upgradeModifier;
    managerModifier = _managerModifier;
    businessLevel = _businessLevel;
    basePrice = _basePrice;
    revenueDelay = _revenueDelay;
    revenue = _revenue;
    //account = null;
    //assignedManager = null;
} // end constructor

/**
 * @brief Destroy the Business:: Business object
 * 
 */
Business::~Business(){} // end deconstructor

/**
 * @brief calculates the cost needed to upgrade the business to targeted level
 * 
 * @param targetLevel 
 * @return the cost needed to upgrade the business to the targeted level
 */
double Business::costToUpgrade(int targetLevel){ // gets the cost to upgrade business
    return (double) ((basePrice * managerModifier * (pow(upgradeModifier, targetLevel) - pow(upgradeModifier, businessLevel)))/(upgradeModifier - 1)); // returns the cost to upgrade the business from the current level to the targeted level
} // end method
/**
 * @brief upgrades the business to the targeted level
 * 
 * @param newLevel 
 */
void Business::upgradeBusiness(int newLevel){ // ADD BACK IN ONCE BankAccount IS INTEGRATED
    businessLevel = newLevel;
} // end method

/**
* resets business level
*
* @ return void
*/
void Business::resetBusiness(){
 businessLevel = 0; 
} // amogus

/**
 * @brief Gets the business level
 * 
 * @return int value of business level
 */
int Business::getBusinessLevel(){
    return businessLevel;
} // end method

/**
 * @brief The base revenue value of the business
 * 
 * @return double of revenue
 */
double Business::getRevenue(){
	int outp;
	static std::default_random_engine rng;
	std::uniform_int_distribution<int> dist(-1, 1);
	outp = (revenue*dist(rng)*((rand()%7)+1)*basePrice*businessLevel)/(rand()%11);
    return outp;
} // end method



/* // ADD BACK IN ONCE Manager IS INTEGRATED
void Business::setManager(Manager _assignedManager){
    assignedManager = _assignedManager; // set the new bank account
    managerModifier = assignedManager.getModifier();
} // end method
*/