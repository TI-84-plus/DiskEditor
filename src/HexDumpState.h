#ifndef HEXVIEW_H
#define HEXVIEW_H

#include <QWidget>
#include <QComboBox>
#include "ui_HexDumpState.h"
#include <parted/parted.h>
#include "rawsector.h"
#include <iostream>

namespace Ui {
class HexView;
}

class HexView : public QWidget
{
    Q_OBJECT

public:
    explicit HexView(QWidget *parent = nullptr);

    QComboBox* GetCombo() const { return ui->comboBox; }
    void SetCombo(QStringList part_list) {ui->comboBox->addItems(part_list);}
    QStringList CurrentPartition;

    RawSector hexdump;

    ~HexView();


private:
    Ui::HexView *ui;

private slots:
    void createhexview();
};

#endif // HEXVIEW_H
