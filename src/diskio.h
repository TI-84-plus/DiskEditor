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

    std::vector<PedPartition*> GetPartitions(PedDevice *device);

    std::vector<PedDisk*> Disks;
    std::vector<PedDevice*> Devices;

private:
    std::vector<PedPartition*> Partitions;
    void LoadPartitions(PedDevice *device);
    void LoadDevices();
};

#endif // DISKIO_H
