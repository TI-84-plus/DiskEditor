#include "inodetable.h"
#include "ui_inodetable.h"

InodeTable::InodeTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InodeTable)
{
    ui->setupUi(this);
    ui->splitter_3->setSizes({200, 700});

    Disk = new DiskIO();

    QStringList *diskList = new QStringList();

    std::cout<<this->Disk->Partitions.size()<<std::endl;

    for(int i = 0; i < this->Disk->Partitions.size(); i++) {
        QString pathStr = QString::fromUtf8(this->Disk->Partitions[i]->path);
        diskList->push_back(pathStr);
        std::cout << this->Disk->Partitions[i]->path << std::endl;
    }

    ui->comboBox->addItems(*diskList);
}

InodeTable::~InodeTable()
{
    delete ui;
}
