/*#include <GameManager.h>
#include <stdio.h>

int main(){
    GameManager game;
    game.runBusiness(1);
    game.runBusiness(2);

    game.upgradeBusiness(1);
    game.upgradeBusiness(1);
    game.upgradeBusiness(1);
    game.upgradeBusiness(1);

    game.runBusiness(1);
} // end main
*/
#include <MainWindow.h>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    
    return a.exec();
}