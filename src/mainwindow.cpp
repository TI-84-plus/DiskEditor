#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "HexView.h"
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    StateManager = new StateMachine(this, this);

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
    ui->actionHexView_1->setMenu(Disk->getDiskAction(ui->actionHexView_1));

    for(int i = 0; i < ui->actionHexView_1->menu()->actions().size(); i++)
    {
        if(this->ui->actionHexView_1->menu() != nullptr)
        {
            connect(ui->actionHexView_1->menu()->actions()[i], &QAction::triggered, this, &MainWindow::InodeTableTrigger);
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
    //std::vector<PedPartition*> *Partition = &this->Disk->partitions;
    QObject *device = sender();
    std::string device_model = (device->objectName().toStdString());
    std::cout<<device_model<<std::endl;
    int index = std::stoi(std::string(1, device_model.back()));
    QStringList Partition_list = this->Disk->getPartitions(index, device);

    inodeWidget->GetCombo()->addItems(Partition_list);
}

void MainWindow::InsertTab() {
    this->TabWidget->insertTab(this->TabWidget->count(), this->StateManager->Stack->currentWidget(), QString("New Tab"));
    this->TabWidget->setCurrentIndex(this->TabWidget->count() - 1);
    this->TabWidget->show();
    qDebug() << "Tab Inserted";
}
