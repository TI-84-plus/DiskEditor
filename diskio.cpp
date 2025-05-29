#include "diskio.h"

DiskIO::DiskIO() {

    GetDevices();
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


void DiskIO::ReadDisk(std::ifstream *file) {

}
