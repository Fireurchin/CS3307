/* Mingpei Dou */
/* cs3307 */
/* 05/10/2021 */
/* main program */
#include "mainwindow.h"
#include <QApplication>
 
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	MainWindow mainWindow;
	mainWindow.showMaximized();
	return app.exec();
}