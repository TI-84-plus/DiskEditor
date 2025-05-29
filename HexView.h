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
    PedDevice *CurrentDevice;

    ~HexView();



private:
    Ui::HexView *ui;
};

#endif // HEXVIEW_H
