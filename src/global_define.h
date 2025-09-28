#ifndef PAILLIERDRIVER_ADDR_LIST_H
#define PAILLIERDRIVER_ADDR_LIST_H

#define CLUSTER_NUMBER                      1    //cluster的数量
#define CORE_NUMBER                         1   //一个cluster中的计算核的数量

#define PING 0
#define PONG 1
#define WORD_BYTES_LEN 16   //一个字长为128比特，即16字节

#define NUMBER_OF_WORD_ENC_NCRT  128  //ENC_NCRT结果为4 * 32个字
#define NUMBER_OF_WORD_DEC_CRT   16   //DEC_CRT结果为16个字
#define NUMBER_OF_WORD_SCALE_MUL 32 //SCALE_MUL结果为32个字

#define ALL_BYTES_LEN_ENC_NCRT (WORD_BYTES_LEN * NUMBER_OF_WORD_ENC_NCRT) //ENC_NCRT结果为32 * 16字节
#define ALL_BYTES_LEN_DEC_CRT (WORD_BYTES_LEN * NUMBER_OF_WORD_DEC_CRT)  //DEC_CRT结果为16 * 16字节
#define ALL_BYTES_LEN_SCALE_MUL (WORD_BYTES_LEN * NUMBER_OF_WORD_SCALE_MUL)  //SCALE_MUL结果为32 * 16字节

#define R_BIT_LEN 1024  //窗口法参数
#define WINDOWS_NUM (R_BIT_LEN >> 3)    //窗口法参数




#endif 