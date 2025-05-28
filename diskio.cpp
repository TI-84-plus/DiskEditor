#include "diskio.h"

DiskIO::DiskIO() {

    this->GetPartitions(this->GetDevices());
}

int GetOS() {

    #ifdef _WIN32
        return 1;

    #elif __linux__
        return 2;

    #endif
};

std::vector<PedDevice*> DiskIO::GetDevices() {

    ped_device_probe_all();
    PedDevice *device = nullptr;

    for(device = ped_device_get_next(device); device != nullptr; device= ped_device_get_next(device)) {
        std::cout	<<"Device:" << device->path<<"\n"
                    <<"Model:"  << device->model<<"\n"
                    <<"Size (Sectors):"  << device->sector_size<<"\n"
                    <<"\n"<<std::endl;
        this->Devices.push_back(device);
    }
    return this->Devices;
};


std::vector<PedPartition*> DiskIO::GetPartitions(std::vector<PedDevice*> Devices) {

    for(int i = 0; i < Devices.size(); i++) {

        std::vector<PedPartition*> partitions;

        PedDisk* disk = ped_disk_new(this->Devices[i]);
        if(!disk) {
            std::cout<<"unable to read"<<std::endl;
        }

        for (PedPartition* part = ped_disk_next_partition(disk ,nullptr); part != nullptr; part = ped_disk_next_partition(disk ,part)) {
            std::cout<<ped_partition_get_path(part)<<std::endl;
            partitions.push_back(part);
        }
    }

    return partitions;
}


void DiskIO::ReadDisk(std::ifstream *file) {

}
