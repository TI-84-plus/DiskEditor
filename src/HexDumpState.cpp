#include "HexDumpState.h"

HexView::HexView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HexView)
{
    ui->setupUi(this);
    ui->splitter_3->setSizes({200, 700});

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &HexView::createhexview);
}


void HexView::createhexview() {

    std::cout<<CurrentPartition[ui->comboBox->currentIndex()].toStdString()<<std::endl;
    hexdump.RawReadSector(CurrentPartition[ui->comboBox->currentIndex()]);
}

HexView::~HexView()
{
    delete ui;
}
