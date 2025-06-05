#include "diskio.h"

DiskIO::DiskIO() {

    LoadDevices();
}


void DiskIO::LoadDevices() {

    ped_device_probe_all();
    PedDevice *device = nullptr;

    for(device = ped_device_get_next(device); device != nullptr; device= ped_device_get_next(device)) {
        std::cout	<<"Device:" << device->path<<"\n"
                    <<"Model:"  << device->model<<"\n"
                    <<"Size (Sectors):"  << device->sector_size<<"\n"
                    <<"\n"<<std::endl;
        this->Devices.push_back(device);
    }
}

std::vector<PedPartition*> DiskIO::GetPartitions(PedDevice *device) {
    this->LoadPartitions(device);
    return this->Partitions;
}

void DiskIO::LoadPartitions(PedDevice *device) {

    PedDisk *disk = ped_disk_new(device);

    std::cout<<"Device Found: "<<device->model<<std::endl;

    for(PedPartition *part = ped_disk_next_partition(disk, nullptr); part != nullptr; part = ped_disk_next_partition(disk, part)) {

        if(ped_partition_is_active(part)) {
            this->Partitions.push_back(part);
        }
    }
}


