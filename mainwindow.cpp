#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "HexView.h"
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(StateMachine *StateManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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

    Disk = new DiskIO();

    for(int i = 0; i < this->Disk->Devices.size(); i++) {
        QString pathStr = QString::fromUtf8(this->Disk->Devices[i]->model);
        diskList.push_back(pathStr);
        std::cout << this->Disk->Devices[i]->path << std::endl;
        QMenu *drive = new QMenu();
        drive->setTitle(pathStr);
        ui->actionHexView_1->setMenu(drive);
        QAction *partition = new QAction(pathStr, this);
        partition->setObjectName("partition"+QString::number(i));
        ui->actionHexView_1->menu()->addAction(partition);
    }

    if(this->ui->actionHexView_1->menu() != nullptr)
    {
        for(int i = 0; i <this->ui->actionHexView_1->menu()->actions().count(); i++)
        {
            std::cout<<this->ui->actionHexView_1->menu()->actions().count()<<std::endl;
            QAction *disk = this->ui->actionHexView_1->menu()->actions()[i];

            connect(disk, &QAction::triggered, this, &MainWindow::InodeTableTrigger);
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InodeTableTrigger() {
    HexView *inodeWidget = new HexView(this->StateManager->Stack);
    this->StateManager->AddState(inodeWidget);

    //Temporary, need to replace
    inodeWidget->GetCombo()->addItems(diskList);
}

void MainWindow::InsertTab() {
    this->TabWidget->insertTab(this->TabWidget->count(), this->StateManager->Stack->currentWidget(), QString("New Tab"));
    this->TabWidget->setCurrentIndex(this->TabWidget->count() - 1);
    this->TabWidget->show();
    qDebug() << "Tab Inserted";
}
