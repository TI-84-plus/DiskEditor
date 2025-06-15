#ifndef RAWSECTOR_H
#define RAWSECTOR_H
#include <fstream>
#include <iostream>
#include <QMainWindow>
#include <vector>
#include <iomanip>

class RawSector
{
public:
    RawSector();

    std::vector<std::vector<char>> rawDiskSec;
    void RawReadSector(QString ParitionPath);

    void PrintHexDump(std::vector<char> buffer, std::size_t size, std::size_t bytesPerLine = 16);
};

#endif // RAWSECTOR_H
