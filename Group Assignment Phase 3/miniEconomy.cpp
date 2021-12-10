/* Group 69 */
/* cs3307 */
/* 11/10/2021 */
/* implements features to aid in volume, demand and volatility */
#include "miniEconomy.h"

		// constructor for class
		MiniEconomy::MiniEconomy(Business busName) {
			setVolume(getVolume);
			setDemand(getPopsDemand);
			setVolatility(getVolatility);
			modRev();
		}
		
		// execute method forked from boost code
		double MiniEconomy::modRev()(){
			double outp = 1;
			exitCode = 1;
			try {
				static std::default_random_engine rng;
				std::uniform_int_distribution<int> dist(-1, 1);
				outp = (dist(rng)*volatility*demand*volume)/3;
			}
			catch (boost::process::process_error&e ){	// catch incorrect command
				std::cout << "CRITICAL ERROR" << std::endl;
			}
			return outp;
		}
		
		// getter methods
		int MiniEconomy::getVolume(){
			return business->globalVolume;
		}
		double MiniEconomy::getPopsDemand(){
			return popGroup->demand;
		}
		double MiniEconomy::getVolatility(){
			// if compare(business->businessType,"type")==0 else etc
		}
		
		// setter for command line
		void MiniEconomy::setVolume(int amm){
			volume = amm;
		}
		
		// setter for command history
		void MiniEconomy::setDemand(int pops){
			demand = pops;
		}
		
		// setter for command history
		void MiniEconomy::setVolatility(int bust){
			volatility = bust;
		}
		
		// destructor (does nothing)
		MiniEconomy::~MiniEconomy(){
		}