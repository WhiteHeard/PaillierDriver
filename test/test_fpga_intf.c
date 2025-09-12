//
// Created by zhangchi on 2025/9/1.
//
#include "fpga_intf.h"
#include "test_fpga_intf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void test_fpga_read_write() {
    int wc = open_host2FpgaChannel(0);
    int rc = open_fpga2HostChannel(0);
    FILE *rd;
    //if( (rd=fopen("/home/zhangchi/CLionProjects/PaillierDriver/test/test_fpga_read_write.txt", "wb+")) == NULL ){  //以二进制方式打开
    //    puts("Fail to open file!");
    //    exit(0);
    //}
    if( (rd=fopen("/home/zhangchi/CLionProjects/PaillierDriver/test/test_fpga_read_write.txt", "rb+")) == NULL ){  //以二进制方式打开
        puts("Fail to open file!");
        exit(0);
    }
    uint8_t *i_buf;
    i_buf = malloc(sizeof(uint8_t)*0x10000);
    uint8_t *o_buf;
    o_buf = malloc(sizeof(uint8_t)*0x10000);

    fread(i_buf, 1, 0x10000, rd);
    //write_from_host_to_fpga(wc,0,i_buf,0x10000);
    read_from_fpga_to_host(rc, 0, o_buf, 0x10000);
    for (int i = 0; i < 0x10; i++) {
        printf("%2x | %2x\n",i_buf[i],o_buf[i]);
    }
    close_host2FpgaChannel(wc);
    close_fpga2HostChannel(rc);
    free(i_buf);
    free(o_buf);

}