#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "statemachine.h"
#include "diskio.h"
#include <QMenu>
#include "HexDumpState.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void InsertTab();


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    StateMachine *StateManager;
    QVBoxLayout *layout;
    QWidget *central;
    QTabWidget *TabWidget;
    DiskIO *Disk;
    QStringList diskList;
};
#endif // MAINWINDOW_H
