#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "inodetable.h"
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(StateMachine *StateManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->ui->actionInodeTable, &QAction::triggered, this, &MainWindow::InodeTableTrigger);
    this->StateManager = StateManager;

    connect(StateManager, &StateMachine::InsertTab, this, &MainWindow::InsertTab);

    this->central = new QWidget(this);
    this->layout = new QVBoxLayout(central);
    this->layout->setContentsMargins(0, 0, 0, 0);
    this->layout->setSpacing(0);

    this->layout->addWidget(ui->menubar);
    this->TabWidget = new QTabWidget();
    this->TabWidget->hide();
    this->layout->addWidget(this->TabWidget);

    setCentralWidget(central);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InodeTableTrigger() {
    InodeTable *inodeWidget = new InodeTable(this->StateManager->Stack);
    this->StateManager->AddState(inodeWidget);
}

void MainWindow::InsertTab() {
    this->TabWidget->insertTab(this->TabWidget->count(), this->StateManager->Stack->currentWidget(), QString("New Tab"));
    this->TabWidget->setCurrentIndex(this->TabWidget->count() - 1);
    this->TabWidget->show();
    qDebug() << "Tab Inserted";
}
