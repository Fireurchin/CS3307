/* Mingpei Dou */
/* cs3307 */
/* 05/10/2021 */
/* Command header initializes features to aid in GUI */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QListWidget>
#include <iostream>
#include "command.h"

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		explicit MainWindow(QWidget *parent = nullptr);
	private slots:
		 void on_execButton_clicked();
	private:
		// UI
		QVBoxLayout *sysUI;
		QWidget *window;
		
		// initializes labels
		QLabel *inputer, *outputer, *exitCodeDisp, *histDisp;
		
		// initializes labels
		QLineEdit *inputText;
		QTextEdit *outDisp;
		QListWidget *histBox;
		QHBoxLayout *commandBox;

		// initializes labels
		// QVBoxLayout *mainbox;
		
		// misc
		QFrame *midLine;
		QPushButton *pushButton;	// execute button init
		// QSpacerItem *spacer; obsolete
		QSpacerItem *spacerSmall;
};
#endif // MAINWINDOW_H