#include "rawsector.h"

RawSector::RawSector() {

}

void RawSector::RawReadSector(QString ParitionPath){

    std::ifstream partition("/home/fiveeght/Desktop/temp.png", std::ios::binary);

    std::vector<std::vector<char>> RawSectors;
    for(std::size_t i = 0; i < 8; ++i) {

        std::vector<char> buffer(512);
        //std::cout<<"This! "<<ParitionPath.toStdString()<<std::endl;

        partition.read(buffer.data(), buffer.size());

        RawSectors.push_back(buffer);

        RawSector::PrintHexDump(buffer, buffer.size());
    }
}


void RawSector::PrintHexDump(std::vector<char> buffer, std::size_t size, std::size_t bytesPerLine) {

    for(std::size_t i = 0; i < size; i += bytesPerLine) {

        for(std::size_t j = 0; j < bytesPerLine && i + j < size; ++j) {

            std::cout<< std::setw(2) << std::setfill('0') << std::hex <<(static_cast<unsigned int>(static_cast<unsigned char>(buffer[i + j]))) << " ";

        }
        std::cout<< std::endl;
    }
}
