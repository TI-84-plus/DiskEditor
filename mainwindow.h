#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "statemachine.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void InodeTableTrigger();
    void InsertTab();


public:
    MainWindow(StateMachine *StateManager, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    StateMachine *StateManager;
    QVBoxLayout *layout;
    QWidget *central;
    QTabWidget *TabWidget;
};
#endif // MAINWINDOW_H
