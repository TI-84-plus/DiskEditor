#include "diskio.h"

DiskIO::DiskIO() {

    this->GetPartitions();
}

int GetOS() {

    #ifdef _WIN32
        return 1;

    #elif __linux__
        return 2;

    #endif
};

std::vector<PedDevice*> DiskIO::GetPartitions() {

    ped_device_probe_all();
    PedDevice *part = nullptr;

    for(part = ped_device_get_next(part); part != nullptr; part = ped_device_get_next(part)) {
        std::cout	<<"Device:" << part->path<<"\n"
                    <<"Model:"  << part->model<<"\n"
                    <<"Size (Sectors):"  << part->sector_size<<"\n"
                    <<"\n"<<std::endl;
        this->Partitions.push_back(part);
    }
    return this->Partitions;

};

void DiskIO::ReadDisk(std::ifstream *file) {

}
