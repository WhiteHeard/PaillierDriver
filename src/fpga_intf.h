//
// Created by zhangchi on 2025/8/29.
//

#ifndef PAILLIERDRIVER_FPGA_INTF_H
#define PAILLIERDRIVER_FPGA_INTF_H
#include <fcntl.h>
#ifdef __cplusplus
extern "C"{
#endif

#define OPEN_H2C_SUCCESS  0
#define OPEN_H2C_ERROR   -1
#define OPEN_C2H_SUCCESS  0
#define OPEN_C2H_ERROR   -2


/**
 * Establishes a communication channel between the host and FPGA.
 *
 * This function opens a file descriptor to the specified FPGA interface, which is
 * "/dev/xdma0_h2c_0" by default, with read-write access. Upon success, it prints
 * a success message; otherwise, an error message is printed indicating the failure.
 * @param i the channel number of host2FpgaChannel， chosen from 1 to 4
 * @return The file descriptor of the opened FPGA communication channel upon success,
 *         or -1 if the operation fails, typically due to insufficient permissions or the device not being available.
 */
int open_host2FpgaChannel(int i);

/**
 * Closes the communication channel between the host and FPGA.
 *
 * This function closes the file descriptor associated with the FPGA communication channel specified by `deviceIdentifier`.
 * It is crucial to call this function when communication with the FPGA is no longer needed to release system resources properly.
 *
 * @param deviceIdentifier The file descriptor representing the open communication channel to the FPGA.
 */
void close_host2FpgaChannel(int deviceIdentifier);

/**
 * Writes data from the host to the FPGA through an established communication channel.
 *
 * This function sends a block of data to a specific address within the FPGA, utilizing the provided file descriptor
 * that represents the communication channel. It first seeks to the designated address using `lseek`, then writes
 * the data using the `write` system call. Success or failure messages are printed accordingly.
 *
 * @param deviceIdentifier The file descriptor of the opened FPGA communication channel.
 * @param addr The offset within the FPGA's memory space where data should be written.
 * @param data Pointer to an array of bytes representing the data to be written.
 * @param dataBytesLen The number of bytes to write from the data array.
 *
 * @note Ensure that the `deviceIdentifier` is valid and corresponds to an open FPGA channel.
 * @note The function assumes the channel has been successfully opened with write permissions.
 */
off_t write_from_host_to_fpga(int deviceIdentifier, off_t addr, const unsigned char* data, int dataBytesLen);

/**
 * Establishes a communication channel from the FPGA to the host.
 *
 * This function attempts to open a file descriptor for the FPGA-to-host interface,
 * with the default path set to "/dev/xdma0_c2h_0". It requests both read and write
 * access permissions. Upon successfully opening the channel, a success message is printed.
 * In case of failure, an error message indicating the unsuccessful open operation is displayed.
 * @param i the channel number of host2FpgaChannel， chosen from 1 to 4
 * @return The file descriptor for the FPGA-to-host communication channel if the operation succeeds,
 *         or -1 if it fails, typically due to missing permissions or the absence of the specified device.
 */
int open_fpga2HostChannel(int i);

/**
 * Closes the communication channel from FPGA to host.
 *
 * This function closes the file descriptor associated with the FPGA-to-host communication channel,
 * which was previously opened using a similar function. The `deviceIdentifier` parameter refers
 * to the file descriptor that needs to be closed.
 *
 * @param deviceIdentifier The file descriptor representing the open channel from FPGA to host that should be closed.
 */
void close_fpga2HostChannel(int deviceIdentifier);

/**
 * Reads data from the FPGA to the host through an established communication channel.
 *
 * This function reads a block of data from the FPGA, specified by the address `addr` and
 * the length `dataBytesLen`, into the buffer `data`. The communication channel is identified
 * by the file descriptor `deviceIdentifier`. It first seeks to the correct position in the FPGA memory,
 * then performs the read operation. Success or failure messages are printed to the standard output.
 *
 * @param deviceIdentifier The file descriptor of the already opened FPGA communication channel.
 * @param addr The offset from the beginning of the FPGA memory region to start reading from.
 * @param data Pointer to the buffer where the read data will be stored.
 * @param dataBytesLen The number of bytes to read from the FPGA.
 */
off_t read_from_fpga_to_host(int deviceIdentifier, off_t addr, unsigned char* data, int dataBytesLen);

#ifdef __cplusplus
}
#endif
#endif //PAILLIERDRIVER_FPGA_INTF_H