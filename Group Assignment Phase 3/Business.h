/**
 * * Author: Khaleel Abdool Mohammed
 * * Description: This is the header for the Business class
 * * Date: 2021-09-25
**/

#ifndef BUSINESS_H
#define BUSINESS_H

// imports
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <random>

/**
 * @brief The class for the business object
 * 
 */
class Business{
        private:
                float upgradeModifier;
                float managerModifier;
                int businessLevel;
                double basePrice;
                float revenueDelay;
                double revenue;
                //Manager assignedManager
        public:
                Business(); // the default constructor
                Business(float _upgradeModifier, float _managerModifier, int _businessLevel, double _basePrice, float _revenueDelay, double _revenue); // the constructor
                ~Business(); // the deconstructor
                double costToUpgrade(int targetLevel); // gets the cost to upgrade business to targeted level
                void upgradeBusiness(int newLevel); // sets the new level of the business
                int getBusinessLevel(); // gets the businesses level
                double getRevenue(); // gets the businesses revenue
        //      void setManager(Manager _assignedManager
}; // end class

#endif // !
