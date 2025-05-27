#ifndef INODETABLE_H
#define INODETABLE_H

#include <QWidget>
#include "diskio.h"

namespace Ui {
class InodeTable;
}

class InodeTable : public QWidget
{
    Q_OBJECT

public:
    explicit InodeTable(QWidget *parent = nullptr);
    ~InodeTable();

    DiskIO *Disk;


private:
    Ui::InodeTable *ui;
};

#endif // INODETABLE_H
