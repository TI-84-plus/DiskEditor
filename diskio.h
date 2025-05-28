#ifndef DISKIO_H
#define DISKIO_H
#include <iostream>
#include <cstdio>
#include <vector>

//extern "C" {
#include <parted/parted.h>
//}

class DiskIO
{
public:
    DiskIO();
    void ReadDisk(std::ifstream *file);
    std::vector<PedDevice*> GetDevices();
    std::vector<PedPartition*> GetPartitions(std::vector<PedDevice*>);

    int GetOS();

    std::vector<PedDevice*> Devices;
    std::vector<PedPartition*> partitions;
    int fd;

};

#endif // DISKIO_H
