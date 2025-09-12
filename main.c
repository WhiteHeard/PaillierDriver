#include <stdio.h>
#include "test/test_fpga_intf.h"
int main(void) {
    test_fpga_read_write();
    printf("Hello, World!\n");
    return 0;
}