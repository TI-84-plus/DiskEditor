#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    StateManager = new StateMachine(this);

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
    QMenu *menu = new QMenu();

    ui->actionHexView_1->setMenu(menu);
    for(int i = 0; i < Disk->Devices.size(); i++) {
        QString model = QString::fromUtf8(Disk->Devices[i]->model);

        QAction *part = new QAction(Disk->Devices[i]->model);
        part->setObjectName(Disk->Devices[i]->path);
        ui->actionHexView_1->menu()->addAction(part);
        QStringList partitionPaths;

        for(PedPartition* partition : Disk->GetPartitions(Disk->Devices[i])) {
            QString part_name = QString::fromStdString(Disk->Devices[i]->path + std::to_string(partition->num));
            partitionPaths.append(part_name);
        }
        connect(ui->actionHexView_1->menu()->actions()[i], &QAction::triggered, this, [this, partitionPaths]() {
            HexView *hexView = this->StateManager->PushState<HexView>();
            hexView->CurrentPartition = partitionPaths;
            hexView->GetCombo()->addItems(partitionPaths);
            hexView->GetCombo()->setCurrentIndex(0);
        });


        // connect(qobject_cast<HexView*>(this->StateManager->Stack->currentWidget())->GetCombo(),
        //         QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::DiskReader);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::InsertTab() {
    this->TabWidget->insertTab(this->TabWidget->count(), this->StateManager->Stack->currentWidget(), QString("New Tab"));
    this->TabWidget->setCurrentIndex(this->TabWidget->count() - 1);
    this->TabWidget->show();
    qDebug() << "Tab Inserted";
}
