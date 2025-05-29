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
        QMenu *drive = new QMenu();
        drive->setTitle(pathStr);
        ui->actionHexView_1->setMenu(drive);
        QAction *partition = new QAction(pathStr, this);
        partition->setObjectName("partition"+QString::number(i));
        ui->actionHexView_1->menu()->addAction(partition);

        if(this->ui->actionHexView_1->menu() != nullptr)
        {
            connect(partition, &QAction::triggered, this, &MainWindow::InodeTableTrigger);        }
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

    for(int i = 0; i < this->Disk->Devices.size(); i++) {
        QString index = ("partition"+QString::number(i));
        if(device->objectName() == index) {
            int DeviceIndex = index.toInt();
        }
    }

    PedDisk *disk = ped_disk_new(Disk->Devices[0]);
    QStringList partList;

    for(PedPartition *part = ped_disk_next_partition(disk, nullptr); part != nullptr; part = ped_disk_next_partition(disk, part)) {

        if(ped_partition_is_active(part)) {
            QString part_name = QString::fromUtf8(ped_partition_get_name(part)); //not used
            std::string s_dev_path = std::string(disk->dev->path) + std::to_string(part->num);
            QString qs_dev_path = QString::fromStdString(s_dev_path);

            partList.append(qs_dev_path);
            std::cout<<s_dev_path<<std::endl;
        }
    }
    inodeWidget->GetCombo()->addItems(partList);
}

void MainWindow::InsertTab() {
    this->TabWidget->insertTab(this->TabWidget->count(), this->StateManager->Stack->currentWidget(), QString("New Tab"));
    this->TabWidget->setCurrentIndex(this->TabWidget->count() - 1);
    this->TabWidget->show();
    qDebug() << "Tab Inserted";
}
