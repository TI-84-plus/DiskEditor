#ifndef DISKIO_H
#define DISKIO_H
#include <iostream>
#include <cstdio>
#include <vector>
#include <QAction>
#include <QMenu>

//extern "C" {
#include <parted/parted.h>
//}

class DiskIO {
public:
    DiskIO();

    QMenu* getDiskAction(QAction *actionHexView);
    void LoadDevices();
    QStringList getPartitions(int index, QObject *action);

    int GetOS();

    QStringList Devices_Model;
    QStringList diskList;

    std::vector<PedDevice*>* Devices;

};

#endif // DISKIO_H
