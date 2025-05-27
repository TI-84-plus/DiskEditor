#include "mainwindow.h"
#include "statemachine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //OwnerShip Problem here
    //Stack needs to call its show member function
    //but first needs to be added as a widget to a QWidget object
    QApplication a(argc, argv);
    StateMachine *StateManager = new StateMachine();


    MainWindow *w = new MainWindow(StateManager);

    w->show();
    return a.exec();
}
