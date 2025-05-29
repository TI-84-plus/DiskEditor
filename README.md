# Dynamic Disk Editor

Dynamic Disk Editor is a Advanced Disk Editor Application for viewing and editing raw data (sectors) on Physical
Disks and partitions. it give in depth detail about disks and partitions, it shows the hexdump, byte offset, and memory address of the disk.

## Uses
It is widely used in forensic data analysis as well as in recovering corrupted filesystems, partitions or Data
And its useful in data recovery. 

## Features coming soon:
- Hex view of entire partitions and files.
- search feature for sectors and byte offsets.
- search and viewing of super blocks, group discriptior table, inode bitmap, block bitmap, inode tables, and data blocks for ext filesystem.
- proper support for windows.
- data recovery with 2 distinct modes (Content Data mode and metadata mode).
- ability to export data.
  

## Compiliation
  - #### Linux
      - install Qt libraries and CMake [CMake](https://cmake.org.download/) if you dont already have it:
        ```sh
        sudo apt install qtbase5-dev qtbase5-dev-tools cmake g++
        ```
      - Clone the repo
        ```sh
        git clone https://github.com/TI-84-plus/DiskEditor.git
        cd path/to/repo/FileSystemReader
        ```
      - build using cmake
        ```sh
        mkdir build
        cd build/
        cmake ..
        ```
      - run
        - #### Note: to work properly the application needs root privilage
        ```sh
        sudo ./Desktop_Qt_6_9_0-Debug/FileSystemReader
        ```
  - #### Windows
      - ##### coming soon... 
