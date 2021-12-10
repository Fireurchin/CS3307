/* Group 69 */
/* cs3307 */
/* 11/10/2021 */
/* miniEconomy header initializes features to aid in volume, demand and volatility */
#ifndef MINIECONOMY_CLASS_H
#define MINIECONOMY_CLASS_H
// #include "pops.h" will add later
// #include "insert_business_class_here.h"
#include <iostream>
#include <random>

class Command{
	private:
		std::string busType, popType; // history
		int typeAmount, volume, ; // exit code
		double volatility, demand;
	
    public:
		MiniEconomy (Business busName);	// Constructor
		double modRev(); // modifies daily revenue
		int getVolume(); // returns volume from business
		double getPopsDemand();	// returns demand from pops
		double getVolatility();	// calculates volatility from business type
		void setVolume(int amm); // sets volume
		void setDemand(int pops);	// sets demand
		void setVolatility(int bust);	// sets volatility
		~MiniEconomy();	// Destructor
};
#endif 