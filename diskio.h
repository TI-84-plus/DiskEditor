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

    int GetOS();

    std::vector<PedDevice*> Devices;
    int fd;

};

#endif // DISKIO_H
