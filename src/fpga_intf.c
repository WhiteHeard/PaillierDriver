//
// Created by zhangchi, douwei lei on 2024-November-26.
//

#include "fpga_intf.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int open_host2FpgaChannel(int i){
    int rc;
    switch (i)
    {
    case 0:
        rc = open("/dev/xdma0_h2c_0", O_RDWR);
        if(rc == -1){
            perror("open host2FpgaChannel failed");
            return OPEN_H2C_ERROR;
        }
        break;
    case 1:
        rc = open("/dev/xdma0_h2c_1", O_RDWR);
        if(rc == -1){
            perror("open host2FpgaChannel failed");
            return OPEN_H2C_ERROR;
        }
        break;
    case 2:
        rc = open("/dev/xdma0_h2c_2", O_RDWR);
        if(rc == -1){
            perror("open host2FpgaChannel failed");
            return OPEN_H2C_ERROR;
        }
        break;
    case 3:
        rc = open("/dev/xdma0_h2c_3", O_RDWR);
        if(rc == -1){
            perror("open host2FpgaChannel failed");
            return rc;
        }
        break;
    default:
        rc = open("/dev/xdma0_h2c_0", O_RDWR);
        if(rc == -1){
            perror("open host2FpgaChannel failed");
            return OPEN_H2C_ERROR;
        }
        break;
    }
#ifndef ERROR_LOG_ONLY
    printf("open host2FpgaChannel succeed\n");
#endif
    return rc;
}

void close_host2FpgaChannel(int deviceIdentifier){
    close(deviceIdentifier);
}

off_t write_from_host_to_fpga(int deviceIdentifier, off_t addr, const unsigned char* data, int dataBytesLen){
    off_t rc = 0;
    if(deviceIdentifier == -1){
        printf("input device illegal \n");
        return rc;
    }

    rc = lseek(deviceIdentifier, addr, SEEK_SET);
    if(rc == -1)
    {
        printf("addr Error: %s\n", strerror(errno));
        return rc;
    }
    rc = write(deviceIdentifier, data, dataBytesLen);
    if(rc == -1)
    {
        printf("write data Error: %s \n", strerror(errno));
        return rc;
    }
#ifndef ERROR_LOG_ONLY
    printf("write data succeed\n");
#endif
    return rc;
}

int open_fpga2HostChannel(int i){
    int rc;
    switch (i)
    {
    case 0:
        rc = open("/dev/xdma0_c2h_0", O_RDWR);
        if(rc == -1){
            perror("open fpga2HostChannel failed");
            return OPEN_C2H_ERROR;
        }
        break;
    case 1:
        rc = open("/dev/xdma0_c2h_1", O_RDWR);
        if(rc == -1){
            perror("open fpga2HostChannel failed");
            return OPEN_C2H_ERROR;
        }
        break;
    case 2:
        rc = open("/dev/xdma0_c2h_2", O_RDWR);
        if(rc == -1){
            perror("open fpga2HostChannel failed");
            return OPEN_C2H_ERROR;
        }
        break;
    case 3:
        rc = open("/dev/xdma0_c2h_3", O_RDWR);
        if(rc == -1){
            perror("open fpga2HostChannel failed");
            return OPEN_C2H_ERROR;
        }
        break;
    default:
        rc = open("/dev/xdma0_c2h_0", O_RDWR);
        if(rc == -1){
            perror("open fpga2HostChannel failed");
            return OPEN_C2H_ERROR;
        }
        break;
    }
#ifndef ERROR_LOG_ONLY
    printf("open fpga2HostChannel succeed\n");
#endif
    return rc;
}

void close_fpga2HostChannel(int deviceIdentifier){
    close(deviceIdentifier);
}

off_t read_from_fpga_to_host(int deviceIdentifier, off_t addr, unsigned char* data, int dataBytesLen){
    off_t rc = 0;
    if(deviceIdentifier == -1){
        perror("input device illegal \n");
        return rc;
    }

    rc = lseek(deviceIdentifier, addr, SEEK_SET);
    if(rc == -1)
    {
        printf("addr Error: %s\n", strerror(errno));
        return rc;
    }
    rc = read(deviceIdentifier, data, dataBytesLen);
    if(rc == -1)
    {
        printf("read data Error: %s \n", strerror(errno));
        return rc;
    }
#ifndef ERROR_LOG_ONLY
    printf("read data succeed\n");
#endif
    return rc;
}
