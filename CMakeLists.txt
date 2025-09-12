cmake_minimum_required(VERSION 4.0)
project(PaillierDriver C)

set(CMAKE_C_STANDARD 11)
include_directories(/home/zhangchi/CLionProjects/PaillierDriver/src)
include_directories(/home/zhangchi/CLionProjects/PaillierDriver/test)
add_executable(PaillierDriver main.c
        src/addr_list.c
        src/fpga_intf.c
        test/test_fpga_intf.c)
