#ifndef HEXVIEW_H
#define HEXVIEW_H

#include <QWidget>
#include <QComboBox>
#include "ui_HexView.h"
#include <parted/parted.h>

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

    ~HexView();



private:
    Ui::HexView *ui;
};

#endif // HEXVIEW_H
