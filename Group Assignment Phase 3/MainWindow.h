/**
 * * Author: Khaleel Abdool Mohammed
 * * Description: This is a header for the MainWindow class
 * * Date: 2021-09-25
**/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// imports
#include <QtWidgets>
#include <GameManager.h>

// the namespace
namespace Ui {
	  class MainWindow;
}

/**
* * Name: MainWindow
* * Description: holds all the info for the MainWindow class
* * Parameters:
* *	- N/A
* * Return:
* *	- N/A
**/
class MainWindow : public QMainWindow
{
	Q_OBJECT
	public:
		    explicit MainWindow(QWidget *parent = nullptr); // creates the main window we would use
		    private slots:
                void UpdateBank(double newBalance);
               
                void RunBusinessTutor();
                void RunBusinessSpoke();
                void RunBusinessWave();
                void RunBusinessBookStore();
                void RunBusinessTheater();
                void RunBusinessBikeRental();

                void UpgradeBusinessTutor();
                void UpgradeBusinessSpoke();
                void UpgradeBusinessWave();
                void UpgradeBusinessBookStore();
                void UpgradeBusinessTheater();
                void UpgradeBusinessBikeRental();
				
				void resetAll();

	private:

            GameManager *game;

            // buttons to run businesses
            QPushButton *runtutor;
            QPushButton *runspoke;
            QPushButton *runwave;
            QPushButton *runbookstore;
            QPushButton *runtheater;
            QPushButton *runbikerental;

            // buttons to upgrade business
            QPushButton *upgradetutor;
            QPushButton *upgradespoke;
            QPushButton *upgradewave;
            QPushButton *upgradebookstore;
            QPushButton *upgradetheater;
            QPushButton *upgradebikerental;

            // labels to show upgrade cost
			QLabel *upgradetutorlabel; 
			QLabel *upgradespokelabel; 
			QLabel *upgradewavelabel; 
			QLabel *upgradebookstorelabel; 
			QLabel *upgradetheaterlabel; 
			QLabel *upgradebikerentallabel; 

            // labels to show business revenue value
            QLabel *tutorlabel; 
			QLabel *spokelabel; 
			QLabel *wavelabel; 
			QLabel *bookstorelabel; 
			QLabel *theaterlabel; 
			QLabel *bikerentallabel; 
			
			// reset
			QPushButton *resetButton;
			QLabel *resetLabel;

            // Bank label
            QLabel *banklabel; 


}; // end class
#endif // MAINWINDOW_H