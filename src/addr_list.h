//
// Created by zhangchi on 2025/8/29.
//

#ifndef PAILLIERDRIVER_ADDR_LIST_H
#define PAILLIERDRIVER_ADDR_LIST_H

//========================================
// Paillier DDR Address List             |
//========================================

#define DDR0_ADDR                           0x00000000_00000000ULL   //DDR0地址
#define DDR1_ADDR                           0x00000001_00000000ULL   //DDR1地址


//===========================================
// Clustger CSR Register Address List       |
//===========================================

#define CONF_CONTROL_RESULT_PING_ADDR       0x0000000100000000ULL   //control模块中，配置子模块result_control的ping位置的地址    
#define CONF_CONTROL_RESULT_PONG_ADDR       0x0000000100001000ULL   //control模块中，配置子模块result_control的pong位置的地址        
#define CONF_CONTROL_STATE_PING_ADDR        0x0000000100010000ULL   //control模块中，配置子模块rstate_control的ping位置的地址  
#define CONF_CONTROL_STATE_PONG_ADDR        0x0000000100020000ULL   //control模块中，配置子模块rstate_control的pong位置的地址  
#define CONF_CONTROL_RESET_PINGPONG_ADDR    0x00000000ff810000ULL   //拉高所有input_path模块的return2ping，用于计算结束后复位至ping通道  
#define CONF_CACHE_START_ADDR               0x0000000000820000ULL   //拉高所有input_path模块的return2ping，用于计算结束后复位至ping通道 
#define CONF_CACHE_PING_ADDR                0x00000000ff830000ULL   //拉高所有input_path模块的return2ping，用于计算结束后复位至ping通道  
#define CONF_CACHE_PONG_ADDR                0x00000000ff840000ULL   //拉高所有input_path模块的return2ping，用于计算结束后复位至ping通道  
#define CONF_CONTROL_RESET_CORE_ADDR        0x0000000100040000ULL   //control模块中，启动复位信号的地址，但实际并未用control模块启动复位信号  

#define STATE_PING                          0x0000000400000000ULL   //读取ping的计算状态的地址
#define STATE_PONG                          0x0000000400000020ULL   //读取pong的计算状态的地址
#define BRAM_CONTROL_BRAM2AXI               0x0000000500000000ULL   //control模块中，子模块result_control向此地址写入计算结果


//===========================================
// Paillier Unit CSR Register Address List  |
//===========================================
#define PAILLIER_PADDING                    0x00
#define PAILLIER_REGSET_ADDR                0x02
#define PAILLIER_MODE_ADDR                  0x00 
#define PAILLIER_LEN_ADDR                   0x01 
#define PAILLIER_PING_TRIGGER_ADDR          0x02 
#define PAILLIER_PONG_TRIGGER_ADDR          0x03 
// #define PAILLIER_N_PRIME_ADDR               0x04 
// #define PAILLIER_N2_PRIME_ADDR              0x05 
// #define PAILLIER_P2_PRIME_ADDR              0x06 
// #define PAILLIER_Q2_PRIME_ADDR              0x07 
#define PAILLIER_PRMT_ADDR                  0x08 
#define PAILLIER_THREAD_NUM_ADDR            0x09 
#define PAILLIER_TRIGGER_START_ADDR         0x0A 
#define PAILLIER_PLAIN_LENGTH               0x0F
#define PAILLIER_CIPHER_LENGTH              0x1F
      
#define MODE_ENC_CRT                        0x00
#define MODE_ENC_NCRT                       0x01
#define MODE_DEC_CRT                        0x02
#define MODE_SCALE_MUL                      0x03
#define MODE_EVAL_ADD                       0x04
      
#define PAILLIER_TRIGGER_START              0x01
#define PAILLIER_TRIGGER_END                0x00
#define TRIGGER_OFFSET_PING                 0x02
#define TRIGGER_OFFSET_PONG                 0x03
      
#define TRIGGER_ADDR_ENC_CRT                0x8F
#define TRIGGER_ADDR_ENC_NCRT               0xBF
#define TRIGGER_ADDR_DEC_CRT                0x1F
#define TRIGGER_ADDR_SCALE_MUL              0x8F
#define TRIGGER_ADDR_EVAL_ADD               0x9F


//========================================
// Paillier Unit Input RAM Address List  |
//========================================

// Data Address List
// Range from 0x000 ~ 0x0FF
//----------------------------------------
#define RAM_IN_OP1_PING          0x200
#define RAM_IN_OP2_PING          0x280
#define RAM_IN_OP1_PONG          0x300
#define RAM_IN_OP2_PONG          0x380

// #define RAM_IN_OP1_PING          0x000
// #define RAM_IN_OP2_PING          0x040
// #define RAM_IN_OP1_PONG          0x080
// #define RAM_IN_OP2_PONG          0x0C0

// Constant Data Address List
// Range from 0x120 ~ 0x1FF
//----------------------------------------
#define RAM_IN_N2_PRIME          0x120
#define RAM_IN_N_PRIME           0x140
#define RAM_IN_P2_PRIME          0x150
#define RAM_IN_Q2_PRIME          0x160
#define RAM_IN_N2                0x180
#define RAM_IN_N                 0x1A0
#define RAM_IN_P2                0x1B0
#define RAM_IN_Q2                0x1C0
#define RAM_IN_HS                0x1D0


// Initialization Parameter Address List
// Range from 0x000 ~ 0x11F
//----------------------------------------
#define RAM_IN_N_MOD_N2          0x000
#define RAM_IN_R4_MOD_N2         0x020
#define RAM_IN_QQR2_MOD_N2       0x040
#define RAM_IN_PPR2_MOD_N2       0x060
#define RAM_IN_R2_MOD_N          0x080
#define RAM_IN_R2_MOD_P2         0x090
#define RAM_IN_R2_MOD_Q2         0x0A0
#define RAM_IN_LAMBDA_MOD_PHI_P2 0x0B0
#define RAM_IN_LAMBDA_MOD_PHI_Q2 0x0C0
#define RAM_IN_N_INV_MOD_R       0x0D0
#define RAM_IN_RMU_INV_MOD_N     0x0E0
#define RAM_IN_ONE               0x0F0
#define RAM_IN_ZERO              0x100
// Pre-Calculated Data Address List
// Range from 0x100 ~ 0x17F
//----------------------------------------
#define RAM_IN_PRE_START         0x100

#define RAM_PRE_DATA_0           0x000
#define RAM_PRE_DATA_1           0x020
#define RAM_PRE_DATA_2           0x040
#define RAM_PRE_DATA_3           0x060
#define RAM_PRE_DATA_4           0x080
#define RAM_PRE_DATA_5           0x0A0
#define RAM_PRE_DATA_6           0x0C0
#define RAM_PRE_DATA_7           0x0E0
#endif //PAILLIERDRIVER_ADDR_LIST_H