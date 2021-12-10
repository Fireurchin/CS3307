/* Mingpei Dou */
/* cs3307 */
/* 05/10/2021 */
/* mainwindow class implements features of mainwindow.h */
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent) {
	// main UI
	sysUI = new QVBoxLayout();
	
	// GUI identifiers
	inputer = new QLabel("Enter Command: ");
	outputer = new QLabel("Output");
	exitCodeDisp = new QLabel("Exit Status: ");
	histDisp = new QLabel("History");

	//command frontend
	inputText = new QLineEdit();	// input box
	inputText->setStyleSheet("border: 1px solid blue");
	pushButton = new QPushButton("Execute");	// execute command button
	connect(pushButton, &QPushButton::released, this, &MainWindow::on_execButton_clicked);	// Connect button signal to appropriate slot
	
	//output boxes
	outDisp = new QTextEdit();
	outDisp->setReadOnly(true);	// no write
	histBox = new QListWidget();
	
	// graphical flourishes
	midLine = new QFrame;
	midLine->setFrameShape(QFrame::HLine);
	midLine->setFrameShadow(QFrame::Sunken);

	// program container
	window = new QWidget;
	commandBox = new QHBoxLayout();
		
	// misc
	spacerSmall = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum); // spacer

	// command console
	commandBox->addWidget(inputer);	// backend
	commandBox->addWidget(inputText); // frontend
	commandBox->addWidget(pushButton);
	sysUI->addLayout(commandBox);	// adds command console

	// command output
	sysUI->addWidget(outputer);
	sysUI->addWidget(outDisp);
	sysUI->addWidget(exitCodeDisp);
	
	// midline
	sysUI->addSpacerItem(spacerSmall);
	sysUI->addWidget(midLine);
	sysUI->addSpacerItem(spacerSmall);

	// command history
	sysUI->addWidget(histDisp);
	sysUI->addWidget(histBox);

	// add main UI to window
	window->setLayout(sysUI);
	window->show();
}

void MainWindow::on_execButton_clicked(){
	if (inputText->text().isEmpty()){
		exitCodeDisp->setText("Exit Status: "+QString::number(127));	// exit code for empty command
		outDisp->setText("Invalid Command: Empty Blocks Cannot Be Parsed");
	}
	else {
		Command command(inputText->text().toStdString()); // command declaration
		outDisp->setText(QString::fromStdString(command.execute()));	// display command
		histBox->insertItem(0,QString::fromStdString(command.getHistory()));	// manage command history in LIFO manner
		exitCodeDisp->setText("Exit Status: "+QString::number(command.getExitCode()));	// return exit code
	}
}