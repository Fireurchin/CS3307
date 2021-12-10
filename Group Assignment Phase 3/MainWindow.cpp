/**
 * * Author: Khaleel Abdool Mohammed
 * * Description: This class can Holds the main functionality of the GUI window
 * * Date: 2021-09-25
**/

// imports
#include "MainWindow.h"
#include <QVector>


/**
* * Name: mainwindow
* * Description: The constructor for the mainwindow class
* * Parameters:
* *	- parent: stores the parent of the window
* * Return:
* *	- N/A
**/	
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    // set game manager up
    game = new GameManager();
	
	// reset
	resetAll = new QPushButton("", this);
	resetLabel = new QLabel("temp", this);

    // buttons to run businesses
    runtutor = new QPushButton("", this);
    runspoke = new QPushButton("", this);
    runwave = new QPushButton("", this);
    runbookstore = new QPushButton("", this);
    runtheater = new QPushButton("", this);
    runbikerental = new QPushButton("", this);

    // buttons to upgrade business
    upgradetutor = new QPushButton("upgrade", this);
    upgradespoke = new QPushButton("upgrade", this);
    upgradewave = new QPushButton("upgrade", this);
    upgradebookstore = new QPushButton("upgrade", this);
    upgradetheater = new QPushButton("upgrade", this);
    upgradebikerental = new QPushButton("upgrade", this);

    // labels to show upgrade cost
	upgradetutorlabel = new QLabel("temp", this); 
	upgradespokelabel = new QLabel("temp", this);
	upgradewavelabel = new QLabel("temp", this);
	upgradebookstorelabel = new QLabel("temp", this);
	upgradetheaterlabel = new QLabel("temp", this);
	upgradebikerentallabel = new QLabel("temp", this);

    // labels to show business revenue value
    tutorlabel = new QLabel("temp", this); 
	spokelabel = new QLabel("temp", this); 
	wavelabel = new QLabel("temp", this); 
	bookstorelabel = new QLabel("temp", this); 
	theaterlabel = new QLabel("temp", this); 
	bikerentallabel = new QLabel("temp", this); 

    // bank label
    banklabel = new QLabel("0$", this);

    // set label text
    banklabel->setText(QString("%1$").arg(game->getAccount().getBalance(), 2));
    upgradetutorlabel->setText(QString("%1$").arg(game->getUpgradeCost(1), 2));
    upgradespokelabel->setText(QString("%1$").arg(game->getUpgradeCost(2), 2));
    upgradewavelabel->setText(QString("%1$").arg(game->getUpgradeCost(3), 2));
    upgradebookstorelabel->setText(QString("%1$").arg(game->getUpgradeCost(4), 2));
    upgradetheaterlabel->setText(QString("%1$").arg(game->getUpgradeCost(5), 2));
    upgradebikerentallabel->setText(QString("%1$").arg(game->getUpgradeCost(6), 2));
	resetLabel->setText(QString("Reset?"));

    tutorlabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(1) * (double) game->getBusinessLevel(1)/10),2));
    spokelabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(2) * (double) game->getBusinessLevel(2)/10),2));
    wavelabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(3) * (double) game->getBusinessLevel(3)/10),2));
    bookstorelabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(4) * (double) game->getBusinessLevel(4)/10),2));
    theaterlabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(5) * (double) game->getBusinessLevel(5)/10),2));
    bikerentallabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(6) * (double) game->getBusinessLevel(6)/10),2));


    // set their bounds 
    runtutor->setGeometry(QRect(QPoint(100, 100), QSize(100, 50)));
    runspoke->setGeometry(QRect(QPoint(100, 200), QSize(100, 50)));
    runwave->setGeometry(QRect(QPoint(100, 300), QSize(100, 50)));
    runbookstore->setGeometry(QRect(QPoint(300, 100), QSize(100, 50)));
    runtheater->setGeometry(QRect(QPoint(300, 200), QSize(100, 50)));
    runbikerental->setGeometry(QRect(QPoint(300, 300), QSize(100, 50)));

    upgradetutor->setGeometry(QRect(QPoint(100, 150), QSize(100, 50)));
    upgradespoke->setGeometry(QRect(QPoint(100, 250), QSize(100, 50)));
    upgradewave->setGeometry(QRect(QPoint(100, 350), QSize(100, 50)));
    upgradebookstore->setGeometry(QRect(QPoint(300, 150), QSize(100, 50)));
    upgradetheater->setGeometry(QRect(QPoint(300, 250), QSize(100, 50)));
    upgradebikerental->setGeometry(QRect(QPoint(300, 350), QSize(100, 50)));

	upgradetutorlabel->setGeometry(QRect(QPoint(200, 150), QSize(100, 50)));
	upgradespokelabel->setGeometry(QRect(QPoint(200, 250), QSize(100, 50)));
	upgradewavelabel->setGeometry(QRect(QPoint(200, 350), QSize(100, 50)));
	upgradebookstorelabel->setGeometry(QRect(QPoint(400, 150), QSize(100, 50)));
	upgradetheaterlabel->setGeometry(QRect(QPoint(400, 250), QSize(100, 50)));
	upgradebikerentallabel->setGeometry(QRect(QPoint(400, 350), QSize(100, 50)));

    tutorlabel->setGeometry(QRect(QPoint(200, 100), QSize(100, 50)));
	spokelabel->setGeometry(QRect(QPoint(200, 200), QSize(100, 50)));
	wavelabel->setGeometry(QRect(QPoint(200, 300), QSize(100, 50)));
	bookstorelabel->setGeometry(QRect(QPoint(400, 100), QSize(100, 50)));
	theaterlabel->setGeometry(QRect(QPoint(400, 200), QSize(100, 50)));
	bikerentallabel->setGeometry(QRect(QPoint(400, 300), QSize(100, 50)));

    banklabel->setGeometry(QRect(QPoint(100, 400), QSize(100, 50)));
	
	resetLabel->setGeometry(QRect(QPoint(200, 150), QSize(100, 50)));

    // Set icons for some of the buttons
    runtutor->setIcon(QIcon("icons/tutoricon.png"));
    runtutor->setIconSize(runspoke->rect().size());
    runspoke->setIcon(QIcon("icons/spokeicon.png"));
    runspoke->setIconSize(runspoke->rect().size());
    runwave->setIcon(QIcon("icons/waveicon.png"));
    runwave->setIconSize(runspoke->rect().size());
    runbookstore->setIcon(QIcon("icons/bookstoreicon.png"));
    runbookstore->setIconSize(runspoke->rect().size());
    runtheater->setIcon(QIcon("icons/theatericon.jpg"));
    runtheater->setIconSize(runspoke->rect().size());
    runbikerental->setIcon(QIcon("icons/bikerentalicon.jpg"));
    runbikerental->setIconSize(runspoke->rect().size());

    // Connect functionality to buttons
	connect(runtutor, &QPushButton::released, this, &MainWindow::RunBusinessTutor); // connect its release to the Execute_Command event
	connect(runspoke, &QPushButton::released, this, &MainWindow::RunBusinessSpoke); // connect its release to the Execute_Command event
	connect(runwave, &QPushButton::released, this, &MainWindow::RunBusinessWave); // connect its release to the Execute_Command event
	connect(runbookstore, &QPushButton::released, this, &MainWindow::RunBusinessBookStore); // connect its release to the Execute_Command event
	connect(runtheater, &QPushButton::released, this, &MainWindow::RunBusinessTheater); // connect its release to the Execute_Command event
	connect(runbikerental, &QPushButton::released, this, &MainWindow::RunBusinessBikeRental); // connect its release to the Execute_Command event

	connect(upgradetutor, &QPushButton::released, this, &MainWindow::UpgradeBusinessTutor); // connect its release to the Execute_Command event
	connect(upgradespoke, &QPushButton::released, this, &MainWindow::UpgradeBusinessSpoke); // connect its release to the Execute_Command event
	connect(upgradewave, &QPushButton::released, this, &MainWindow::UpgradeBusinessWave); // connect its release to the Execute_Command event
	connect(upgradebookstore, &QPushButton::released, this, &MainWindow::UpgradeBusinessBookStore); // connect its release to the Execute_Command event
	connect(upgradetheater, &QPushButton::released, this, &MainWindow::UpgradeBusinessTheater); // connect its release to the Execute_Command event
	connect(upgradebikerental, &QPushButton::released, this, &MainWindow::UpgradeBusinessBikeRental); // connect its release to the Execute_Command event
	
	connect(resetButton, &QPushButton::released, this, &MainWindow::resetAll); // runs reset command on release of input
} // end window creation

void MainWindow::RunBusinessTutor(){
   UpdateBank(game->runBusiness(1));
} // end method

void MainWindow::RunBusinessSpoke(){
   UpdateBank(game->runBusiness(2));
} // end method

void MainWindow::RunBusinessWave(){
   UpdateBank(game->runBusiness(3));
} // end method

void MainWindow::RunBusinessBookStore(){
   UpdateBank(game->runBusiness(4));
} // end method

void MainWindow::RunBusinessTheater(){
   UpdateBank(game->runBusiness(5));
} // end method

void MainWindow::RunBusinessBikeRental(){
   UpdateBank(game->runBusiness(6));
} // end method

void MainWindow::UpgradeBusinessTutor(){
    UpdateBank(game->upgradeBusiness(1));
    upgradetutorlabel->setText(QString("%1$").arg(game->getUpgradeCost(1), 2));
    tutorlabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(1) * (double) game->getBusinessLevel(1)/10),2));
} // end method

void MainWindow::UpgradeBusinessSpoke(){
    UpdateBank(game->upgradeBusiness(2));
    upgradespokelabel->setText(QString("%1$").arg(game->getUpgradeCost(2), 2));
    spokelabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(2) * (double) game->getBusinessLevel(2)/10),2));
} // end method

void MainWindow::UpgradeBusinessWave(){
    UpdateBank(game->upgradeBusiness(3));
    upgradewavelabel->setText(QString("%1$").arg(game->getUpgradeCost(3), 2));
    wavelabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(3) * (double) game->getBusinessLevel(3)/10),2));

} // end method

void MainWindow::UpgradeBusinessBookStore(){
    UpdateBank(game->upgradeBusiness(4));
    upgradebookstorelabel->setText(QString("%1$").arg(game->getUpgradeCost(4), 2));
    bookstorelabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(4) * (double) game->getBusinessLevel(4)/10),2));
} // end method

void MainWindow::UpgradeBusinessTheater(){
    UpdateBank(game->upgradeBusiness(5));
    upgradetheaterlabel->setText(QString("%1$").arg(game->getUpgradeCost(5), 2));
    theaterlabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(5) * (double) game->getBusinessLevel(5)/10),2));
} // end method

void MainWindow::UpgradeBusinessBikeRental(){
    UpdateBank(game->upgradeBusiness(6));
    upgradebikerentallabel->setText(QString("%1$").arg(game->getUpgradeCost(6), 2));
    bikerentallabel->setText(QString("%1$").arg((double) (game->getBusinessRevenue(6) * (double) game->getBusinessLevel(6)/10),2));
} // end method

void MainWindow::UpdateBank(double newBalance){
    QString str = QString("%1$").arg(newBalance, 2);
    banklabel->setText(QString("%1$").arg(newBalance, 2));
} // end method

void MainWindow::resetAll(){
   UpdateBank(game->resetAccounts());
   game->resetBusiness();
} // end method
