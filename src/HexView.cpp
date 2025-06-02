#include "HexView.h"

HexView::HexView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HexView)
{
    ui->setupUi(this);
    ui->splitter_3->setSizes({200, 700});

}

HexView::~HexView()
{
    delete ui;
}
