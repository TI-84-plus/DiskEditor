#include "diskio.h"

DiskIO::DiskIO() {

    Devices = new std::vector<PedDevice*>;
    LoadDevices();
}

int GetOS() {

    #ifdef _WIN32
        return 1;

    #elif __linux__
        return 2;

    #endif
}

void DiskIO::LoadDevices() {

    ped_device_probe_all();
    PedDevice *device = nullptr;

    for(device = ped_device_get_next(device); device != nullptr; device= ped_device_get_next(device)) {
        std::cout	<<"Device:" << device->path<<"\n"
                    <<"Model:"  << device->model<<"\n"
                    <<"Size (Sectors):"  << device->sector_size<<"\n"
                    <<"\n"<<std::endl;
        this->Devices_Model.push_back(device->model);
    }
}


QStringList DiskIO::getPartitions(int index, QObject *action) {

    PedDevice *device = nullptr;
    QStringList PartitionList;

    for(device = ped_device_get_next(device); device != nullptr; device = ped_device_get_next(device))
    {
        std::cout<<device->model<<"\n"<<std::endl;
        if (index == ((action->objectName().toStdString()).back() - '0')) {
            std::cout<<"Device Found: "<<device->model<<std::endl;
            PedDisk *disk = ped_disk_new(device);

            for(PedPartition *part = ped_disk_next_partition(disk, nullptr); part != nullptr; part = ped_disk_next_partition(disk, part)) {

                if(ped_partition_is_active(part)) {
                    std::string s_dev_path = std::string(disk->dev->path) + std::to_string(part->num);
                    QString qs_dev_path = QString::fromStdString(s_dev_path);

                    PartitionList.append(qs_dev_path);
                }
            }
            return PartitionList;
        }
    }
}


QMenu* DiskIO::getDiskAction(QAction *actionHexView) {

    QMenu *driveMenu = new QMenu();
    for(int i = 0; i < this->Devices_Model.size(); i++) {
        QString pathStr = Devices_Model[i];
        this->diskList.push_back(pathStr);
        driveMenu->setTitle(pathStr);
        actionHexView->setMenu(driveMenu);
        QAction *partition = new QAction(pathStr);
        partition->setObjectName("partition"+QString::number(i));
        actionHexView->menu()->addAction(partition);
    }
    return driveMenu ;
}
