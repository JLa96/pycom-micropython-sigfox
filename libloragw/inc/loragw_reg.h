/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
  (C)2013 Semtech-Cycleo

Description:
    Functions used to handle a single LoRa concentrator.
    Registers are addressed by name.
    Multi-bytes registers are handled automatically.
    Read-modify-write is handled automatically.

License: Revised BSD License, see LICENSE.TXT file include in the project
Maintainer: Sylvain Miermont
*/


#ifndef _LORAGW_REG_H
#define _LORAGW_REG_H

/* -------------------------------------------------------------------------- */
/* --- DEPENDANCIES --------------------------------------------------------- */

#include <stdint.h>        /* C99 types */
#include <stdbool.h>    /* bool type */

#include "config.h"    /* library configuration options (dynamically generated) */

/* -------------------------------------------------------------------------- */
/* --- INTERNAL SHARED TYPES ------------------------------------------------ */

struct lgw_reg_s {
    int8_t  page;        /*!< page containing the register (-1 for all pages) */
    uint8_t addr;        /*!< base address of the register (7 bit) */
    uint8_t offs;        /*!< position of the register LSB (between 0 to 7) */
    bool    sign;        /*!< 1 indicates the register is signed (2 complem.) */
    uint8_t leng;        /*!< number of bits in the register */
    bool    rdon;        /*!< 1 indicates a read-only register */
    int32_t dflt;        /*!< register default value */
};

/* -------------------------------------------------------------------------- */
/* --- INTERNAL SHARED FUNCTIONS -------------------------------------------- */

int reg_w_align32(void *spi_target, uint8_t spi_mux_mode, uint8_t spi_mux_target, struct lgw_reg_s r, int32_t reg_value);
int reg_r_align32(void *spi_target, uint8_t spi_mux_mode, uint8_t spi_mux_target, struct lgw_reg_s r, int32_t *reg_value);

/* -------------------------------------------------------------------------- */
/* --- PUBLIC CONSTANTS ----------------------------------------------------- */

#define LGW_REG_SUCCESS  0
#define LGW_REG_ERROR    -1

/*
auto generated register mapping for C code : 11-Jul-2013 13:20:40
this file contains autogenerated C struct used to access the LORA registers
this file is autogenerated from registers description
293 registers are defined
*/

#define LGW_PAGE_REG 0
#define LGW_SOFT_RESET 1
#define LGW_VERSION 2
#define LGW_RX_DATA_BUF_ADDR 3
#define LGW_RX_DATA_BUF_DATA 4
#define LGW_TX_DATA_BUF_ADDR 5
#define LGW_TX_DATA_BUF_DATA 6
#define LGW_CAPTURE_RAM_ADDR 7
#define LGW_CAPTURE_RAM_DATA 8
#define LGW_MCU_PROM_ADDR 9
#define LGW_MCU_PROM_DATA 10
#define LGW_RX_PACKET_DATA_FIFO_NUM_STORED 11
#define LGW_RX_PACKET_DATA_FIFO_ADDR_POINTER 12
#define LGW_RX_PACKET_DATA_FIFO_STATUS 13
#define LGW_RX_PACKET_DATA_FIFO_PAYLOAD_SIZE 14
#define LGW_MBWSSF_MODEM_ENABLE 15
#define LGW_CONCENTRATOR_MODEM_ENABLE 16
#define LGW_FSK_MODEM_ENABLE 17
#define LGW_GLOBAL_EN 18
#define LGW_CLK32M_EN 19
#define LGW_CLKHS_EN 20
#define LGW_START_BIST0 21
#define LGW_START_BIST1 22
#define LGW_CLEAR_BIST0 23
#define LGW_CLEAR_BIST1 24
#define LGW_BIST0_FINISHED 25
#define LGW_BIST1_FINISHED 26
#define LGW_MCU_AGC_PROG_RAM_BIST_STATUS 27
#define LGW_MCU_ARB_PROG_RAM_BIST_STATUS 28
#define LGW_CAPTURE_RAM_BIST_STATUS 29
#define LGW_CHAN_FIR_RAM0_BIST_STATUS 30
#define LGW_CHAN_FIR_RAM1_BIST_STATUS 31
#define LGW_CORR0_RAM_BIST_STATUS 32
#define LGW_CORR1_RAM_BIST_STATUS 33
#define LGW_CORR2_RAM_BIST_STATUS 34
#define LGW_CORR3_RAM_BIST_STATUS 35
#define LGW_CORR4_RAM_BIST_STATUS 36
#define LGW_CORR5_RAM_BIST_STATUS 37
#define LGW_CORR6_RAM_BIST_STATUS 38
#define LGW_CORR7_RAM_BIST_STATUS 39
#define LGW_MODEM0_RAM0_BIST_STATUS 40
#define LGW_MODEM1_RAM0_BIST_STATUS 41
#define LGW_MODEM2_RAM0_BIST_STATUS 42
#define LGW_MODEM3_RAM0_BIST_STATUS 43
#define LGW_MODEM4_RAM0_BIST_STATUS 44
#define LGW_MODEM5_RAM0_BIST_STATUS 45
#define LGW_MODEM6_RAM0_BIST_STATUS 46
#define LGW_MODEM7_RAM0_BIST_STATUS 47
#define LGW_MODEM0_RAM1_BIST_STATUS 48
#define LGW_MODEM1_RAM1_BIST_STATUS 49
#define LGW_MODEM2_RAM1_BIST_STATUS 50
#define LGW_MODEM3_RAM1_BIST_STATUS 51
#define LGW_MODEM4_RAM1_BIST_STATUS 52
#define LGW_MODEM5_RAM1_BIST_STATUS 53
#define LGW_MODEM6_RAM1_BIST_STATUS 54
#define LGW_MODEM7_RAM1_BIST_STATUS 55
#define LGW_MODEM0_RAM2_BIST_STATUS 56
#define LGW_MODEM1_RAM2_BIST_STATUS 57
#define LGW_MODEM2_RAM2_BIST_STATUS 58
#define LGW_MODEM3_RAM2_BIST_STATUS 59
#define LGW_MODEM4_RAM2_BIST_STATUS 60
#define LGW_MODEM5_RAM2_BIST_STATUS 61
#define LGW_MODEM6_RAM2_BIST_STATUS 62
#define LGW_MODEM7_RAM2_BIST_STATUS 63
#define LGW_MODEM_MBWSSF_RAM0_BIST_STATUS 64
#define LGW_MODEM_MBWSSF_RAM1_BIST_STATUS 65
#define LGW_MODEM_MBWSSF_RAM2_BIST_STATUS 66
#define LGW_MCU_AGC_DATA_RAM_BIST0_STATUS 67
#define LGW_MCU_AGC_DATA_RAM_BIST1_STATUS 68
#define LGW_MCU_ARB_DATA_RAM_BIST0_STATUS 69
#define LGW_MCU_ARB_DATA_RAM_BIST1_STATUS 70
#define LGW_TX_TOP_RAM_BIST0_STATUS 71
#define LGW_TX_TOP_RAM_BIST1_STATUS 72
#define LGW_DATA_MNGT_RAM_BIST0_STATUS 73
#define LGW_DATA_MNGT_RAM_BIST1_STATUS 74
#define LGW_GPIO_SELECT_INPUT 75
#define LGW_GPIO_SELECT_OUTPUT 76
#define LGW_GPIO_MODE 77
#define LGW_GPIO_PIN_REG_IN 78
#define LGW_GPIO_PIN_REG_OUT 79
#define LGW_MCU_AGC_STATUS 80
#define LGW_MCU_ARB_STATUS 81
#define LGW_CHIP_ID 82
#define LGW_EMERGENCY_FORCE_HOST_CTRL 83
#define LGW_RX_INVERT_IQ 84
#define LGW_MODEM_INVERT_IQ 85
#define LGW_MBWSSF_MODEM_INVERT_IQ 86
#define LGW_RX_EDGE_SELECT 87
#define LGW_MISC_RADIO_EN 88
#define LGW_FSK_MODEM_INVERT_IQ 89
#define LGW_FILTER_GAIN 90
#define LGW_RADIO_SELECT 91
#define LGW_IF_FREQ_0 92
#define LGW_IF_FREQ_1 93
#define LGW_IF_FREQ_2 94
#define LGW_IF_FREQ_3 95
#define LGW_IF_FREQ_4 96
#define LGW_IF_FREQ_5 97
#define LGW_IF_FREQ_6 98
#define LGW_IF_FREQ_7 99
#define LGW_IF_FREQ_8 100
#define LGW_IF_FREQ_9 101
#define LGW_CHANN_OVERRIDE_AGC_GAIN 102
#define LGW_CHANN_AGC_GAIN 103
#define LGW_CORR0_DETECT_EN 104
#define LGW_CORR1_DETECT_EN 105
#define LGW_CORR2_DETECT_EN 106
#define LGW_CORR3_DETECT_EN 107
#define LGW_CORR4_DETECT_EN 108
#define LGW_CORR5_DETECT_EN 109
#define LGW_CORR6_DETECT_EN 110
#define LGW_CORR7_DETECT_EN 111
#define LGW_CORR_SAME_PEAKS_OPTION_SF6 112
#define LGW_CORR_SAME_PEAKS_OPTION_SF7 113
#define LGW_CORR_SAME_PEAKS_OPTION_SF8 114
#define LGW_CORR_SAME_PEAKS_OPTION_SF9 115
#define LGW_CORR_SAME_PEAKS_OPTION_SF10 116
#define LGW_CORR_SAME_PEAKS_OPTION_SF11 117
#define LGW_CORR_SAME_PEAKS_OPTION_SF12 118
#define LGW_CORR_SIG_NOISE_RATIO_SF6 119
#define LGW_CORR_SIG_NOISE_RATIO_SF7 120
#define LGW_CORR_SIG_NOISE_RATIO_SF8 121
#define LGW_CORR_SIG_NOISE_RATIO_SF9 122
#define LGW_CORR_SIG_NOISE_RATIO_SF10 123
#define LGW_CORR_SIG_NOISE_RATIO_SF11 124
#define LGW_CORR_SIG_NOISE_RATIO_SF12 125
#define LGW_CORR_NUM_SAME_PEAK 126
#define LGW_CORR_MAC_GAIN 127
#define LGW_ADJUST_MODEM_START_OFFSET_RDX4 128
#define LGW_ADJUST_MODEM_START_OFFSET_SF12_RDX4 129
#define LGW_DBG_CORR_SELECT_SF 130
#define LGW_DBG_CORR_SELECT_CHANNEL 131
#define LGW_DBG_DETECT_CPT 132
#define LGW_DBG_SYMB_CPT 133
#define LGW_CHIRP_INVERT_RX 134
#define LGW_DC_NOTCH_EN 135
#define LGW_IMPLICIT_CRC_EN 136
#define LGW_IMPLICIT_CODING_RATE 137
#define LGW_IMPLICIT_PAYLOAD_LENGHT 138
#define LGW_FREQ_TO_TIME_INVERT 139
#define LGW_FREQ_TO_TIME_DRIFT 140
#define LGW_PAYLOAD_FINE_TIMING_GAIN 141
#define LGW_PREAMBLE_FINE_TIMING_GAIN 142
#define LGW_TRACKING_INTEGRAL 143
#define LGW_FRAME_SYNCH_PEAK1_POS 144
#define LGW_FRAME_SYNCH_PEAK2_POS 145
#define LGW_PREAMBLE_SYMB1_NB 146
#define LGW_FRAME_SYNCH_GAIN 147
#define LGW_SYNCH_DETECT_TH 148
#define LGW_LLR_SCALE 149
#define LGW_SNR_AVG_CST 150
#define LGW_PPM_OFFSET 151
#define LGW_MAX_PAYLOAD_LEN 152
#define LGW_ONLY_CRC_EN 153
#define LGW_ZERO_PAD 154
#define LGW_DEC_GAIN_OFFSET 155
#define LGW_CHAN_GAIN_OFFSET 156
#define LGW_FORCE_HOST_RADIO_CTRL 157
#define LGW_FORCE_HOST_FE_CTRL 158
#define LGW_FORCE_DEC_FILTER_GAIN 159
#define LGW_MCU_RST_0 160
#define LGW_MCU_RST_1 161
#define LGW_MCU_SELECT_MUX_0 162
#define LGW_MCU_SELECT_MUX_1 163
#define LGW_MCU_CORRUPTION_DETECTED_0 164
#define LGW_MCU_CORRUPTION_DETECTED_1 165
#define LGW_MCU_SELECT_EDGE_0 166
#define LGW_MCU_SELECT_EDGE_1 167
#define LGW_CHANN_SELECT_RSSI 168
#define LGW_RSSI_BB_DEFAULT_VALUE 169
#define LGW_RSSI_DEC_DEFAULT_VALUE 170
#define LGW_RSSI_CHANN_DEFAULT_VALUE 171
#define LGW_RSSI_BB_FILTER_ALPHA 172
#define LGW_RSSI_DEC_FILTER_ALPHA 173
#define LGW_RSSI_CHANN_FILTER_ALPHA 174
#define LGW_IQ_MISMATCH_A_AMP_COEFF 175
#define LGW_IQ_MISMATCH_A_PHI_COEFF 176
#define LGW_IQ_MISMATCH_B_AMP_COEFF 177
#define LGW_IQ_MISMATCH_B_SEL_I 178
#define LGW_IQ_MISMATCH_B_PHI_COEFF 179
#define LGW_TX_TRIG_IMMEDIATE 180
#define LGW_TX_TRIG_DELAYED 181
#define LGW_TX_TRIG_GPS 182
#define LGW_TX_START_DELAY 183
#define LGW_TX_FRAME_SYNCH_PEAK1_POS 184
#define LGW_TX_FRAME_SYNCH_PEAK2_POS 185
#define LGW_TX_RAMP_DURATION 186
#define LGW_TX_OFFSET_I 187
#define LGW_TX_OFFSET_Q 188
#define LGW_TX_MODE 189
#define LGW_TX_ZERO_PAD 190
#define LGW_TX_EDGE_SELECT 191
#define LGW_TX_EDGE_SELECT_TOP 192
#define LGW_TX_GAIN 193
#define LGW_TX_CHIRP_LOW_PASS 194
#define LGW_TX_FCC_WIDEBAND 195
#define LGW_TX_SWAP_IQ 196
#define LGW_MBWSSF_IMPLICIT_HEADER 197
#define LGW_MBWSSF_IMPLICIT_CRC_EN 198
#define LGW_MBWSSF_IMPLICIT_CODING_RATE 199
#define LGW_MBWSSF_IMPLICIT_PAYLOAD_LENGHT 200
#define LGW_MBWSSF_AGC_FREEZE_ON_DETECT 201
#define LGW_MBWSSF_FRAME_SYNCH_PEAK1_POS 202
#define LGW_MBWSSF_FRAME_SYNCH_PEAK2_POS 203
#define LGW_MBWSSF_PREAMBLE_SYMB1_NB 204
#define LGW_MBWSSF_FRAME_SYNCH_GAIN 205
#define LGW_MBWSSF_SYNCH_DETECT_TH 206
#define LGW_MBWSSF_DETECT_MIN_SINGLE_PEAK 207
#define LGW_MBWSSF_DETECT_TRIG_SAME_PEAK_NB 208
#define LGW_MBWSSF_FREQ_TO_TIME_INVERT 209
#define LGW_MBWSSF_FREQ_TO_TIME_DRIFT 210
#define LGW_MBWSSF_PPM_CORRECTION 211
#define LGW_MBWSSF_PAYLOAD_FINE_TIMING_GAIN 212
#define LGW_MBWSSF_PREAMBLE_FINE_TIMING_GAIN 213
#define LGW_MBWSSF_TRACKING_INTEGRAL 214
#define LGW_MBWSSF_ZERO_PAD 215
#define LGW_MBWSSF_MODEM_BW 216
#define LGW_MBWSSF_RADIO_SELECT 217
#define LGW_MBWSSF_RX_CHIRP_INVERT 218
#define LGW_MBWSSF_LLR_SCALE 219
#define LGW_MBWSSF_SNR_AVG_CST 220
#define LGW_MBWSSF_PPM_OFFSET 221
#define LGW_MBWSSF_RATE_SF 222
#define LGW_MBWSSF_ONLY_CRC_EN 223
#define LGW_MBWSSF_MAX_PAYLOAD_LEN 224
#define LGW_TX_STATUS 225
#define LGW_FSK_CH_BW_EXPO 226
#define LGW_FSK_RSSI_LENGTH 227
#define LGW_FSK_RX_INVERT 228
#define LGW_FSK_PKT_MODE 229
#define LGW_FSK_PSIZE 230
#define LGW_FSK_CRC_EN 231
#define LGW_FSK_DCFREE_ENC 232
#define LGW_FSK_CRC_IBM 233
#define LGW_FSK_ERROR_OSR_TOL 234
#define LGW_FSK_RADIO_SELECT 235
#define LGW_FSK_BR_RATIO 236
#define LGW_FSK_REF_PATTERN_LSB 237
#define LGW_FSK_REF_PATTERN_MSB 238
#define LGW_FSK_PKT_LENGTH 239
#define LGW_FSK_TX_GAUSSIAN_EN 240
#define LGW_FSK_TX_GAUSSIAN_SELECT_BT 241
#define LGW_FSK_TX_PATTERN_EN 242
#define LGW_FSK_TX_PREAMBLE_SEQ 243
#define LGW_FSK_TX_PSIZE 244
#define LGW_FSK_NODE_ADRS 245
#define LGW_FSK_BROADCAST 246
#define LGW_FSK_AUTO_AFC_ON 247
#define LGW_FSK_PATTERN_TIMEOUT_CFG 248
#define LGW_SPI_RADIO_A__DATA 249
#define LGW_SPI_RADIO_A__DATA_READBACK 250
#define LGW_SPI_RADIO_A__ADDR 251
#define LGW_SPI_RADIO_A__CS 252
#define LGW_SPI_RADIO_B__DATA 253
#define LGW_SPI_RADIO_B__DATA_READBACK 254
#define LGW_SPI_RADIO_B__ADDR 255
#define LGW_SPI_RADIO_B__CS 256
#define LGW_RADIO_A_EN 257
#define LGW_RADIO_B_EN 258
#define LGW_RADIO_RST 259
#define LGW_LNA_A_EN 260
#define LGW_PA_A_EN 261
#define LGW_LNA_B_EN 262
#define LGW_PA_B_EN 263
#define LGW_PA_GAIN 264
#define LGW_LNA_A_CTRL_LUT 265
#define LGW_PA_A_CTRL_LUT 266
#define LGW_LNA_B_CTRL_LUT 267
#define LGW_PA_B_CTRL_LUT 268
#define LGW_CAPTURE_SOURCE 269
#define LGW_CAPTURE_START 270
#define LGW_CAPTURE_FORCE_TRIGGER 271
#define LGW_CAPTURE_WRAP 272
#define LGW_CAPTURE_PERIOD 273
#define LGW_MODEM_STATUS 274
#define LGW_VALID_HEADER_COUNTER_0 275
#define LGW_VALID_PACKET_COUNTER_0 276
#define LGW_VALID_HEADER_COUNTER_MBWSSF 277
#define LGW_VALID_HEADER_COUNTER_FSK 278
#define LGW_VALID_PACKET_COUNTER_MBWSSF 279
#define LGW_VALID_PACKET_COUNTER_FSK 280
#define LGW_CHANN_RSSI 281
#define LGW_BB_RSSI 282
#define LGW_DEC_RSSI 283
#define LGW_DBG_MCU_DATA 284
#define LGW_DBG_ARB_MCU_RAM_DATA 285
#define LGW_DBG_AGC_MCU_RAM_DATA 286
#define LGW_NEXT_PACKET_CNT 287
#define LGW_ADDR_CAPTURE_COUNT 288
#define LGW_TIMESTAMP 289
#define LGW_DBG_CHANN0_GAIN 290
#define LGW_DBG_CHANN1_GAIN 291
#define LGW_DBG_CHANN2_GAIN 292
#define LGW_DBG_CHANN3_GAIN 293
#define LGW_DBG_CHANN4_GAIN 294
#define LGW_DBG_CHANN5_GAIN 295
#define LGW_DBG_CHANN6_GAIN 296
#define LGW_DBG_CHANN7_GAIN 297
#define LGW_DBG_DEC_FILT_GAIN 298
#define LGW_SPI_DATA_FIFO_PTR 299
#define LGW_PACKET_DATA_FIFO_PTR 300
#define LGW_DBG_ARB_MCU_RAM_ADDR 301
#define LGW_DBG_AGC_MCU_RAM_ADDR 302
#define LGW_SPI_MASTER_CHIP_SELECT_POLARITY 303
#define LGW_SPI_MASTER_CPOL 304
#define LGW_SPI_MASTER_CPHA 305
#define LGW_SIG_GEN_ANALYSER_MUX_SEL 306
#define LGW_SIG_GEN_EN 307
#define LGW_SIG_ANALYSER_EN 308
#define LGW_SIG_ANALYSER_AVG_LEN 309
#define LGW_SIG_ANALYSER_PRECISION 310
#define LGW_SIG_ANALYSER_VALID_OUT 311
#define LGW_SIG_GEN_FREQ 312
#define LGW_SIG_ANALYSER_FREQ 313
#define LGW_SIG_ANALYSER_I_OUT 314
#define LGW_SIG_ANALYSER_Q_OUT 315
#define LGW_GPS_EN 316
#define LGW_GPS_POL 317
#define LGW_SW_TEST_REG1 318
#define LGW_SW_TEST_REG2 319
#define LGW_SW_TEST_REG3 320
#define LGW_DATA_MNGT_STATUS 321
#define LGW_DATA_MNGT_CPT_FRAME_ALLOCATED 322
#define LGW_DATA_MNGT_CPT_FRAME_FINISHED 323
#define LGW_DATA_MNGT_CPT_FRAME_READEN 324
#define LGW_TX_TRIG_ALL 325

#define LGW_TOTALREGS 326

/* -------------------------------------------------------------------------- */
/* --- PUBLIC FUNCTIONS PROTOTYPES ------------------------------------------ */

/**
@brief Connect LoRa concentrator by opening SPI link
@param spi_only indicates if we only want to create the SPI connexion to the
concentrator, or if we also want to reset it and configure the FPGA (if present)
@param tx_notch_filter TX notch filter frequency to be set in the FPGA (only
used with SX1301AP2 reference design).
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_connect(bool spi_only);

/**
@brief Disconnect LoRa concentrator by closing SPI link
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_disconnect(void);

/**
@brief Use the soft-reset register to put the concentrator in initial state
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_soft_reset(void);

/**
@brief Check if the registers are ok, send diagnostics to stdio/stderr/file
@param f file descriptor to to which the check result will be written
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_check(FILE *f);

/**
@brief LoRa concentrator register write
@param register_id register number in the data structure describing registers
@param reg_value signed value to write to the register (for u32, use cast)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_w(uint16_t register_id, int32_t reg_value);

/**
@brief LoRa concentrator register read
@param register_id register number in the data structure describing registers
@param reg_value pointer to a variable where to write register read value
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_r(uint16_t register_id, int32_t *reg_value);

/**
@brief LoRa concentrator register burst write
@param register_id register number in the data structure describing registers
@param data pointer to byte array that will be sent to the LoRa concentrator
@param size size of the transfer, in byte(s)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_wb(uint16_t register_id, uint8_t *data, uint16_t size);

/**
@brief LoRa concentrator register burst read
@param register_id register number in the data structure describing registers
@param data pointer to byte array that will be written from the LoRa concentrator
@param size size of the transfer, in byte(s)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_rb(uint16_t register_id, uint8_t *data, uint16_t size);
/**
@brief LoRa concentrator receive cmd for PGW
*/
int lgw_reg_receive_cmd( uint8_t max_packet, uint8_t *data);
int lgw_reg_rxrf_setconfcmd(  uint8_t rfchain, uint8_t *data,uint16_t size);
int lgw_reg_rxif_setconfcmd(  uint8_t rfchain, uint8_t *data,uint16_t size);
int lgw_reg_sendconfcmd(uint8_t *data,uint16_t size);
int lgw_txgainreg_setconfcmd( uint8_t *data,uint16_t size);
int lgw_regtrigger(uint32_t *data);
#endif

/* --- EOF ------------------------------------------------------------------ */
