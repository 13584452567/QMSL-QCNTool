/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Defines/QMSL_Defines_ftm_rf_cmd_types.h#4 $
 *
 *  Project : QMSL
 *
 *  Package : FTM mode communication
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Definitions of phone related data structures
 *
 *********************************************************************
 */

#ifndef PHONE_DECL_H_INCLUDED__
#define PHONE_DECL_H_INCLUDED__
#pragma pack(1)

#include <iostream>
using namespace std;



/*- - - - - - Command ID's for Test Task  - - - - - - - - - - - - - - - - -*/

typedef enum
{

   TEST_SET_PDM,        // 0  /* Set a PDM to a value.                  */
   TEST_SET_PDM_CLOSE,        /* Set a PDM to closed loop operation.    */
   TEST_SET_TX_ON,            /* Set the Transmit circuitry ON.         */
   TEST_SET_TX_OFF,           /* Set the Transmit circuitry OFF.        */
   TEST_SET_FM_TX_LVL,        /* Set the FM TX level                    */
   TEST_SET_GPIO,             /* Set a GPIO to a given state.           */
   TEST_SET_GPIO_TS,          /* Set a GPIO to an input or an output.   */
   TEST_SET_MODE,             /* Set the phone's operating mode.        */
   TEST_SET_CHAN,             /* Set the phones current channel.        */
   TEST_SET_TXP_RATE,         /* Set the Transmit puncture rate.        */

   TEST_GET_PDM,       //10   /* Get the value of a PDM.                */
   TEST_GET_GPIO,             /* Get the value read from a GPIO input.  */
   TEST_GET_RSSI,             /* Get the Received signal strength.      */
   TEST_GET_HDET_L,           /* Get power detect.                      */
   TEST_GET_VBATT,            /* Get Battery voltage.                   */
   TEST_GET_TEMP,             /* Get the Temperature of the phone.      */
   TEST_GET_SYNTH_STATE,      /* Get the current synthesizer lock state.*/
   TEST_GET_PHONE_TYPE,       /* Get the phone type.                    */
   TEST_GET_MODE,             /* Get the current operating mode.        */

   TEST_SET_RINGER,           /* Set the Ringer ON or OFF.              */
   TEST_LCD,            //20  /* Run an LCD test                        */
   TEST_SET_KEYPAD_LOCK,      /* Set Keypolling ON or OFF               */
   TEST_GET_KEYPRESS,         /* Get a keypress from the key queue      */

   TEST_FLASH2,                 /* was TEST_SRAM; now testing FLASH 2     */
   TEST_NV_RAM,               /* TEST Non-Volatile RAM memory           */
   TEST_KILL_ESN,             /* was TEST_ROM_CRC; now kill ESN         */

   TEST_RUN_PCM_LPBCK,        /* Set phone into PCM loopback mode       */
   TEST_USB,    /* was TEST_RUN_VOC_SELF_TEST; now testing USB */
   TEST_UART_SELFTEST,        /* Run a UART selftest                    */

   /* FM only commands */
   TEST_FM_SET_SATCC,         /* Set the expected color code value.     */
   TEST_FM_GET_SATCC,   //30  /* Get the color code detect state.       */
   TEST_FM_SET_TXA_MUTE_STATE,   /* Set the state of TX audio mute.     */
   TEST_FM_SET_RXA_MUTE_STATE,   /* Set the state of RX audio mute.     */

   TEST_FM_TX_WBD_RVC_MSG,    /* Prepare to TX a RVC  message.          */
   TEST_FM_TX_WBD_ROCC_MSG,   /* Prepare to TX a ROCC message.          */

   TEST_FM_RX_WBD_FVC_MSG,    /* Prepare to RX a FVC  message.          */
   TEST_FM_RX_WBD_FOCC_MSG,   /* Prepare to RX a FOCC message.          */

   TEST_FM_TX_ST,             /* Send Signalling tone.                  */
   TEST_FM_TXRX_VOICE,        /* Set into FM voice mode.                */

   TEST_GET_DTMF,             /* Get DTMF data.                         */
   TEST_SET_DTMF,       //40  /* Set DTMF data.                         */

   TEST_VOC_FM_LPBCK,         /* Run FM loopback      */
   TEST_VOC_QCELP_PKT_LPBCK,  /* Run QCELP loopback   */

   TEST_SET_PA_ON,            /* Turn ON PA                             */
   TEST_SET_PA_OFF,           /* Turn OFF PA                            */

   TEST_SIDETONE,
   TEST_SINGLE_TONE,          /* Run a single tone test */

   TEST_GET_HDET_H,
   TEST_SET_TXIQ_DATA,
   TEST_RX_IQ_DATA,
   TEST_CDMA_CW_WAVEFORM,  //50
   TEST_SET_BAUD_RATE,
   TEST_GET_CAGC_TXG_CTL,
   TEST_GET_CAGC_RX_AGC,
   TEST_SET_PA_RANGE,
   TEST_LOAD_CAGC_LIN,
   TEST_LOAD_CAGC_LIN_OFF_0,
   TEST_SET_AUDIO_PATH,
   TEST_SET_LNA_RANGE,
   TEST_GET_ADC_VAL,         /* Get ADC mux reading based on the index 0-max */
   TEST_POWER_OFF,        //60
   TEST_UNUSED_4,
   TEST_SET_CONFIG_OPTION,   /* Use to configure a phone.  */
   TEST_FM_SET_AUDIO_EMPHASIS,  /* Set FM Audio Pre-Demphasis ON/OFF  */
   TEST_SET_TX_PWR_LIMIT,
   TEST_SET_COMPANDOR,
   TEST_GET_CHAN,
   TEST_IS_TEST_CODE,         /* Query if test code is loaded           */
   TEST_SET_VOC_RATE,
   TEST_GET_VOC_CAPABILITY,
   TEST_DVT_FUNCTION,       //70
   TEST_SINGLE_TONE_WITH_FREQ,
   TEST_STUFF_LMX2336_SYNTH,   /* Stuff a dword into the lmx2336 rf synth */
   TEST_SET_CDMA_STATE,       /* Set the CDMA state   */
   TEST_SET_FM_STATE,         /* Set the FM state     */
   TEST_GET_PHONE_STATE,      /* Get the current phone state */

   TEST_GET_CODEC,            /* Get Codec Register value */
   TEST_SET_CODEC,            /* Set Codec Register */
   TEST_SET_TX_POWER,         /* Transmit a constant power level, CDMA/FM */
   TEST_MSM_MEMORY,
   TEST_MSM_VITERBI_DECODER,   //80

   TEST_SET_LNA_OFFSET,       /* Set an LNA offset register             */
   TEST_SET_LNA_RISE,         /* Set an LNA rise register               */
   TEST_SET_LNA_FALL,         /* Set an LNA fall register               */

   TEST_SET_DIGITAL_BAND,     /* Digital Mode, band select              */
   TEST_VOC_INTERNAL_PKT_LOOPBACK,
   TEST_BLUETOOTH_FUNCTION,   //86
   TEST_DFM_FUNCTION,         //87
   TEST_GPS_FUNCTION,         //88  t_gps.h

   TEST_MMC_FUNCTION,         //89  t_mmc.h
   TEST_SDAC_FUNCTION,        //90  t_sdac.h
   TEST_UIM_FUNCTION,         //91  t_uim.h
   TEST_SER_FUNCTION,         //92  t_ser.h
   TEST_SERIAL_BUS_FUNCTION,         //93
   TEST_GSM_FUNCTION,         //94 GSM specific tests
   TEST_SET_CARRIER_SUPPRESSION,  // 95
   TEST_SRAM,                 // 96
   TEST_SDRAM,                // 97
   TEST_TOUCH_SCREEN,         // 98
   TEST_SHARED_MEM_RW,				// 99		shared memory test read write; zeus shared mem and rw
   TEST_SHARED_MEM_LOOPBACK_MSM,	// 100  shared memory loopback; write to zeus and write it back
   TEST_SHARED_MEM_LOOPBACK_PDA,	// 101
   TEST_ENABLE_RX_DIVERSITY,      // 102  Sets control registers to enable receiver diversity
   TEST_SET_RX_ANTENNA_PATH,      // 103  Set antenna path for receiver diversity
   TEST_OPEN_LOOP_VERIFICATION,   // 104  Sends turnaround constant for open loop verification
   TEST_VOCODER_FUNCTION,         // 105  Vocoder related items
   TEST_IQ_CAPTURE_FUNCTION,      // 106  t_iq.h; I/Q Caputure related items.
   TEST_CAGC_FUNCTION,            // 107  CAGC related items
   TEST_RF_RADIO_FUNCTION,        // 108  RF Radio related items
   TEST_GET_CODE_VER_STRING,      // 109
   TEST_CDMA2K_TX_FUNCTION,       // 110  CDMA2000 related items
   TEST_SET_DVGA_OFFSET,          // 111
   TEST_RESERVE,									// 112
   TEST_RESERVE_2,								// 113
   TEST_GET_CDMA_IM2,             // 114
   TEST_SET_FREQUENCY_SENSE_GAIN,	// 115
   TEST_SET_TX_CAL,								// 116
   TEST_GET_DVGA_OFFSET,          // 117
   TEST_GET_LNA_OFFSET,           // 118
   TEST_GET_HDET,									// 119
   TEST_GET_FM_IQ,								// 120

   //from Kevin
   FTM_SET_SECONDARY_CHAIN=121,
   FTM_GET_CTON = 122,
   FTM_SECOND_CHAIN_TEST_CALL=123,
   FTM_SET_HDET_TRACKING = 124,
   FTM_CONFIGURE_TX_SWEEP_CAL = 125,
   FTM_GET_CDMA_IM2_WITH_SUPPRESSION=126,
   FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL=127,


   TEST_MAX = 0x7FFF                  /* Useful for checking invalid commands   */

} test_id_type;

typedef WORD enum_type;
typedef short int int2;
typedef WORD word;
typedef DWORD dword;
typedef BYTE byte;

typedef enum
{

   PDM_I_OFFSET=0,
   PDM_Q_OFFSET,
   PDM_TX_AGC_ADJ,
   PDM_RX_AGC_ADJ,
   PDM_TRK_LO_ADJ,

//! PDMs for RX Diversity
   PDM_I_OFFSET_ANT1,
   PDM_Q_OFFSET_ANT1,
   PDM_RX_AGC_ADJ_ANT1,

   PDM_MAX_NUM,

//! PDMs for GSM
   PDM_GSM_VCTCXO_ADJ = 0,
   PDM_GSM_I_DC_OFFSET,
   PDM_GSM_Q_DC_OFFSET,
   PDM_GSM_MAX_NUM

} pdm_id_type;


typedef enum
{
   PA_R0,
   PA_R1,
   PA_R2,
   PA_R3,
   PA_R0_BIT,
   PA_R1_BIT
} pa_range_type;

typedef enum
{
   PA_State0,
   PA_State1,
   PA_State2,
   PA_State3
} pa_state_type;

typedef enum
{
   LNA_R0,
   LNA_R1,
   LNA_R2,
   LNA_R3,
} lna_range_type;


/**
	SBI Data Type
*/
typedef struct
{
   byte slave_id;
   byte data_mask;
   byte reg_address;
   byte reg_data;
} sbi_data_type;

typedef struct
{
   BYTE byte0;
   BYTE byte1;
   BYTE byte2;
} test_byte_type;


typedef struct
{
   WORD id;
   WORD val;
} test_id_val_type;


typedef struct
{
   BYTE get_dvga;
   WORD get_lna_mask;
   WORD dvga;
   WORD lna_0_offset;
   WORD lna_1_offset;
   WORD lna_2_offset;
   WORD lna_3_offset;
} test_dvga_lna_type;

typedef struct
{
   short	 inputRxAgc;
   BYTE get_dvga;
   WORD get_lna_mask;
   WORD dvga;
   WORD lna_0_offset;
   WORD lna_1_offset;
   WORD lna_2_offset;
   WORD lna_3_offset;
} test_dvga_lna_type2;

typedef struct
{
   WORD	 inputRxAgc;
   BYTE get_dvga;
   WORD get_lna_mask;
   WORD dvga;
   WORD lna_0_offset;
   WORD lna_1_offset;
   WORD lna_2_offset;
   WORD lna_3_offset;
} test_dvga_lna_type3;

typedef struct
{
   int2	 inputRxAgc;
   BYTE get_dvga;
   WORD get_lna_mask;
   WORD dvga;
   WORD lna_0_offset;
   WORD lna_1_offset;
   WORD lna_2_offset;
   WORD lna_3_offset;
} test_dvga_lna_type4;

typedef enum
{
   SUBSYSTEM_CDMA2000,
   SUBSYSTEM_WCDMA,
   SUBSYSTEM_GSM,
   SUBSYSTEM_DVT,
   SUBSYSTEM_IQ,
   SUBSYSTEM_DIGITAL,
   SUBSYSTEM_SBI,
   SUBSYSTEM_AUDIO,
   SUBSYSTEM_GPS,
   SUBSYSTEM_MAX
} subsystem_cmd_type;



#define GRFC_MASK    0x000FFFFFL                        /* Mask for 20 GRFC                                          */

#define PA_LUT_MAX_SIZE      64                         /* Number of entries in the PA LUT                           */

#define MOD_CFG_TRL_GB_POS          8
#define MOD_CFG_LDN_GB_POS         12
#define MOD_CFG_OSR_POS            19
#define MOD_CFG_GB_POL_POS         21
#define MOD_CFG_SPEC_INV_POS       22
#define MOD_CFG_GB_LEN_POS         23
#define MOD_CFG_MDSP_IQ_SEL_POS    29
#define MOD_CFG_USE_ROTATOR_POS    30
#define MOD_CFG_CONST_MOD_EN_POS   31

#define CHFILT_CFG_AUTO_ACK_POS       6
#define CHFILT_CFG_DMA_ENA_POS        5
#define CHFILT_CFG_DMA_SEL_POS        3
#define CHFILT_CFG_INVERT_Y1I_POS     2
#define CHFILT_CFG_INVERT_Y1Q_POS     1
#define CHFILT_CFG_USE_ROTATOR_POS    0


/**************************************************
**   MDSP command buffer structures
**************************************************/
#if (defined(__WIN32__) || defined(WIN32))
typedef struct
{
   WORD            mdsp_port_address;
   DWORD              mdsp_port_data;
#else
typedef PACKED struct
{
   uint16          mdsp_port_address;
   uint32             mdsp_port_data;
#endif
} mdsp_peek_poke_type;

/**************************************************
**   GRFC Communication buffer
**************************************************/

typedef enum
{
   GRFC_ACTIVE_HIGH,
   GRFC_ACTIVE_LOW
} enum_grfc_polarity;

typedef enum
{
   GRFC_INPUT,
   GRFC_OUTPUT
} enum_grfc_direction;

typedef enum
{
   GRFC_STATIC_OUTPUT,
   GRFC_TIMED_OUTPUT
} enum_grfc_output_mode;

typedef enum
{
   GRFC_0,
   GRFC_1,
   GRFC_2,
   GRFC_3,
   GRFC_4,
   GRFC_5,
   GRFC_6,
   GRFC_7,
   GRFC_8,
   GRFC_9,
   GRFC_10,
   GRFC_11,
   GRFC_12,
   GRFC_13,
   GRFC_14,
   GRFC_15,
   GRFC_16,
   GRFC_17,
   GRFC_18,
   GRFC_19,
   GRFC_MAX
} enum_grfc_id;

typedef enum
{
   GRFC_CHFILT_TIME,
   GRFC_PA_RAMP_TIME,
   GRFC_PA_PRECHARGE_TIME,
   GRFC_TX_SLEEP,
   GRFC_AUX_MAX
} enum_aux_grfc_id;

#if defined (__WIN32__) || defined(WIN32)
typedef struct
{
   DWORD                               grfc_direction;
   DWORD                             grfc_output_mode;
   DWORD                                grfc_polarity;
#else
typedef PACKED struct
{
   uint32                              grfc_direction;
   uint32                            grfc_output_mode;
   uint32                               grfc_polarity;
#endif
} grfc_setup_type;


#if defined (__WIN32__) || defined(WIN32)
typedef struct
{
   int2         start_offset;
   int2          stop_offset;
#else
typedef PACKED struct
{
   int16        start_offset;
   int16         stop_offset;
#endif
} grfc_timing_offset_type;

#if defined (__WIN32__) || defined(WIN32)
typedef struct
{
   int2           grfc_id;
   union
   {
      BOOLEAN          state;
#else
typedef PACKED struct
{
   enum_type      grfc_id;
   PACKED union
   {
      boolean          state;
#endif
      grfc_timing_offset_type grfc_timing;
   } grfc_cfg;
} grfc_type;



/*------------------------------------------------------------------------------
** Define the data type for the PA LUT
*/

typedef enum
{
   POWER_LEVEL_0_GSM_0900,
   POWER_LEVEL_1_GSM_0900 = POWER_LEVEL_0_GSM_0900,
   POWER_LEVEL_2_GSM_0900 = POWER_LEVEL_0_GSM_0900,
   POWER_LEVEL_3_GSM_0900,
   POWER_LEVEL_4_GSM_0900,
   POWER_LEVEL_5_GSM_0900,
   POWER_LEVEL_6_GSM_0900,
   POWER_LEVEL_7_GSM_0900,
   POWER_LEVEL_8_GSM_0900,
   POWER_LEVEL_9_GSM_0900,
   POWER_LEVEL_10_GSM_0900,
   POWER_LEVEL_11_GSM_0900,
   POWER_LEVEL_12_GSM_0900,
   POWER_LEVEL_13_GSM_0900,
   POWER_LEVEL_14_GSM_0900,
   POWER_LEVEL_15_GSM_0900,
   POWER_LEVEL_16_GSM_0900,
   POWER_LEVEL_17_GSM_0900,
   POWER_LEVEL_18_GSM_0900,
   POWER_LEVEL_19_GSM_0900,
   POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_21_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_22_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_23_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_24_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_25_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_26_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_27_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_28_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_29_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_30_GSM_0900 = POWER_LEVEL_20_GSM_0900,
   POWER_LEVEL_31_GSM_0900 = POWER_LEVEL_20_GSM_0900,

   POWER_LEVEL_29_GSM_1800 = POWER_LEVEL_0_GSM_0900,
   POWER_LEVEL_30_GSM_1800,
   POWER_LEVEL_31_GSM_1800,
   POWER_LEVEL_0_GSM_1800,
   POWER_LEVEL_1_GSM_1800,
   POWER_LEVEL_2_GSM_1800,
   POWER_LEVEL_3_GSM_1800,
   POWER_LEVEL_4_GSM_1800,
   POWER_LEVEL_5_GSM_1800,
   POWER_LEVEL_6_GSM_1800,
   POWER_LEVEL_7_GSM_1800,
   POWER_LEVEL_8_GSM_1800,
   POWER_LEVEL_9_GSM_1800,
   POWER_LEVEL_10_GSM_1800,
   POWER_LEVEL_11_GSM_1800,
   POWER_LEVEL_12_GSM_1800,
   POWER_LEVEL_13_GSM_1800,
   POWER_LEVEL_14_GSM_1800,
   POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_16_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_17_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_18_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_19_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_20_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_21_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_22_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_23_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_24_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_25_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_26_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_27_GSM_1800 = POWER_LEVEL_15_GSM_1800,
   POWER_LEVEL_28_GSM_1800 = POWER_LEVEL_15_GSM_1800,

   POWER_LEVEL_0_GSM_1900 = POWER_LEVEL_0_GSM_0900,
   POWER_LEVEL_1_GSM_1900,
   POWER_LEVEL_2_GSM_1900,
   POWER_LEVEL_3_GSM_1900,
   POWER_LEVEL_4_GSM_1900,
   POWER_LEVEL_5_GSM_1900,
   POWER_LEVEL_6_GSM_1900,
   POWER_LEVEL_7_GSM_1900,
   POWER_LEVEL_8_GSM_1900,
   POWER_LEVEL_9_GSM_1900,
   POWER_LEVEL_10_GSM_1900,
   POWER_LEVEL_11_GSM_1900,
   POWER_LEVEL_12_GSM_1900,
   POWER_LEVEL_13_GSM_1900,
   POWER_LEVEL_14_GSM_1900,
   POWER_LEVEL_15_GSM_1900,
   POWER_LEVEL_16_GSM_1900,
   POWER_LEVEL_17_GSM_1900,
   POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_19_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_20_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_21_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_22_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_23_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_24_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_25_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_26_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_27_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_28_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_29_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_30_GSM_1900 = POWER_LEVEL_18_GSM_1900,
   POWER_LEVEL_31_GSM_1900 = POWER_LEVEL_18_GSM_1900,

   POWER_LEVEL_NUM_LEVELS = 19

} enum_tx_power_level_type;

#if defined (__WIN32__) || defined(WIN32)
typedef struct
{
   BYTE                                ramp_step_size;
   BYTE                                   pa_lut_size;
#else
typedef PACKED struct
{
   uint8                               ramp_step_size;
   uint8                                  pa_lut_size;
#endif /* defined(__WIN32__) || defined(WIN32) */
} pa_lut_cfg_type;


#if defined (__WIN32__) || defined(WIN32)
typedef struct
{
   WORD                      ramp_up[PA_LUT_MAX_SIZE];
   WORD                    ramp_down[PA_LUT_MAX_SIZE];
#else
typedef PACKED struct
{
   uint16                    ramp_up[PA_LUT_MAX_SIZE];
   uint16                  ramp_down[PA_LUT_MAX_SIZE];
#endif /* defined(__WIN32__) || defined(WIN32) */
   pa_lut_cfg_type                             pa_cfg;
} pa_lut_type;


/*------------------------------------------------------------------------------
** Define the data type for the modulator config
*/

#if defined(__WIN32__) || defined(WIN32)
typedef struct
{
   BOOLEAN         cont_mod_en;     /* set cont modulation;                 bit [31]    in mod_cfg */
   BOOLEAN         use_rotator;     /* use rotation;                        bit [30]    in mod_cfg */
   BOOLEAN         mdsp_iq_sel;     /* mdsp I/Q selector;                   bit [29]    in mod_cfg */
   BOOLEAN            spec_inv;     /* use spectral inversion;              bit [22]    in mod_cfg */
   BOOLEAN          gd_bit_pol;     /* guard bit polarity;                  bit [21]    in mod_cfg */
   BYTE          gd_bit_bursts;     /* number of guard bits between bursts; bits[28:23] in mod_cfg */
   BYTE                os_rate;     /* oversampling rate;                   bits[20:19] in mod_cfg */
   BYTE            gd_bit_lead;     /* number of leading guard bits;        bits[18:12] in mod_cfg */
   BYTE           gd_bit_trail;     /* number of trailing guard bits;       bits[11:8]  in mod_cfg */
   BYTE           burst_length;     /* number of bits in a burst;           bits[7:0]   in mod_cfg */
#else
typedef PACKED struct
{
   boolean         cont_mod_en;     /* set cont modulation;                 bit [31]    in mod_cfg */
   boolean         use_rotator;     /* use rotation;                        bit [30]    in mod_cfg */
   boolean         mdsp_iq_sel;     /* mdsp I/Q selector;                   bit [29]    in mod_cfg */
   boolean            spec_inv;     /* use spectral inversion;              bit [22]    in mod_cfg */
   boolean          gd_bit_pol;     /* guard bit polarity;                  bit [21]    in mod_cfg */
   uint8         gd_bit_bursts;     /* number of guard bits between bursts; bits[28:23] in mod_cfg */
   uint8               os_rate;     /* oversampling rate;                   bits[20:19] in mod_cfg */
   uint8           gd_bit_lead;     /* number of leading guard bits;        bits[18:12] in mod_cfg */
   uint8          gd_bit_trail;     /* number of trailing guard bits;       bits[11:8]  in mod_cfg */
   uint8          burst_length;     /* number of bits in a burst;           bits[7:0]   in mod_cfg */
#endif /* defined(__WIN32__) || defined(WIN32) */
} mod_cfg_type;


/*------------------------------------------------------------------------------
** Define the data type for the Burst Transmit Command
** and Continuous Burst Transmit Command
*/

typedef enum
{
   TX_DATA_SOURCE_PSDRND,
   TX_DATA_SOURCE_TONE,
   TX_DATA_SOURCE_BUFFER
} enum_tx_data_source_type;

#if defined(__WIN32__) || defined(WIN32)
typedef struct
{
   BYTE                      slot_num;
   int2                   data_source;
   BYTE                     tsc_index;
   DWORD                   num_bursts; /* this number is examined if infinite_duration == FALSE */
   BOOLEAN          infinite_duration; /* this flags sets the infinite duration of */
#else
typedef PACKED struct
{
   uint8                     slot_num;
   enum_type              data_source;
   uint8                    tsc_index;
   uint32                  num_bursts; /* this number is examined if infinite_duration == FALSE */
   boolean          infinite_duration; /* this flags sets the infinite duration of */
#endif /* defined(__WIN32__) || defined(WIN32) */
} tx_burst_type;


/*------------------------------------------------------------------------------
** Types to set CHFILT parameters
*/

typedef enum
{
   DMA_ACKNOWLEDGE,
   AUTO_ACKNOWLEDGE
} enum_chfilt_auto_ack_type;

typedef enum
{
   DMA_DISABLE,
   DMA_ENABLE
} enum_chfilt_dma_ena_type;

typedef enum
{
   DMA_SEL_A,
   DMA_SEL_B,
   DMA_SEL_C,
   DMA_SEL_D
} enum_chfilt_dma_sel_type;

typedef enum
{
   INVERT_Y1_ENABLE,
   INVERT_Y1_DISABLE
} enum_chfilt_invert_y1_type;

typedef enum
{
   ROTATOR_DISABLE,
   ROTATOR_ENABLE
} enum_chfilt_use_rotator_type;

/*------------------------------------------------------------------------------
** Define the data type for the channel filter config
*/

#if defined(__WIN32__) || defined(WIN32)
typedef struct
{
   BOOLEAN         auto_ack;  /* 0 - use real DMA acknowledge signal (normal)    */
   /* 1 - use auto-acknowledge signal (test & debug)  */
   BOOLEAN          dma_ena;  /* 0 - disable DMA transfer of CHFILT data to MDSP */
   /* 1 - enable  DMA transfer of CHFILT data to MDSP */
   BYTE             dma_sel;  /* 0 - input to stage 1 is DMA'd to MDSP           */
   /* 1 - input to stage 2 is DMA'd to MDSP           */
   /* 2 - input to stage 3 is DMA'd to MDSP           */
   /* 3 - output of stage 3 is DMA'd to MDSP          */
   BOOLEAN       invert_y1i;  /* 0 - map 0 to +1, 1 to -1                        */
   /* 1 - map 0 to -1, 1 to +1                        */
   BOOLEAN       invert_y1q;  /* see invert_y1i                                  */
   BOOLEAN      use_rotator;  /* 0 - do not use rotator between stages 2 & 3     */
   /* 1 - use rotator between stages 2 & 3            */
#else
typedef PACKED struct
{
   boolean         auto_ack;  /* 0 - use real DMA acknowledge signal (normal)    */
   /* 1 - use auto-acknowledge signal (test & debug)  */
   boolean          dma_ena;  /* 0 - disable DMA transfer of CHFILT data to MDSP */
   /* 1 - enable  DMA transfer of CHFILT data to MDSP */
   uint8            dma_sel;  /* 0 - input to stage 1 is DMA'd to MDSP           */
   /* 1 - input to stage 2 is DMA'd to MDSP           */
   /* 2 - input to stage 3 is DMA'd to MDSP           */
   /* 3 - output of stage 3 is DMA'd to MDSP          */
   boolean       invert_y1i;  /* 0 - map 0 to +1, 1 to -1                        */
   /* 1 - map 0 to -1, 1 to +1                        */
   boolean       invert_y1q;  /* see invert_y1i                                  */
   boolean      use_rotator;  /* 0 - do not use rotator between stages 2 & 3     */
   /* 1 - use rotator between stages 2 & 3            */

#endif /* defined(__WIN32__) || defined(WIN32) */
} chfilt_cfg_type;

/*------------------------------------------------------------------------------
** Define the data type for the Burst Receive Command
*/
typedef enum
{
   RX_FUNCTION_GET_RSSI,
   RX_FUNCTION_GET_DC_OFFSETS,
   RX_FUNCTION_STOP_CONTINOUS_RX
} enum_rx_function_type;

#if defined(__WIN32__) || defined(WIN32)
typedef struct
{
   WORD         i_dc_offset;
   WORD         q_dc_offset;
#else
typedef PACKED struct
{
   uint16       i_dc_offset;
   uint16       q_dc_offset;
#endif /* defined(__WIN32__) || defined(WIN32) */
} i_q_dc_offset_type;

#if defined(__WIN32__) || defined(WIN32)
typedef struct
{
   BYTE         slot_num;
   int2         rx_funct;
#else
typedef PACKED struct
{
   uint8        slot_num;
   enum_type    rx_funct;
#endif /* defined(__WIN32__) || defined(WIN32) */
} rx_burst_type;

/* Return the current phone state */
#if defined(__WIN32__) || defined(WIN32)
typedef struct
{
   /* Miscellaneous Status */
   int2                        mode;   /* Current Mode               */
   int2                    phone_id;   /* Phone Type                 */
   /* RF status            */
   WORD                     channel;   /* Current Channel            */
   int2                tx_power_lvl;   /* Current TX PCL             */
   BOOLEAN                 tx_state;   /* TX state                   */
   BOOLEAN                 pa_state;   /* PA state                   */
   int2                   lna_range;   /* LNA gain range             */
   BOOLEAN               lna_on_off;   /* LNA power supply state     */
   BOOLEAN              mixer_state;   /* Mixer state                */
   int2                    vga_gain;   /* VGA gain (DP2000) support  */
   DWORD                       rssi;   /* RSSI returned by MDSP      */
   /* GRFC llaneous Status */
   DWORD              grfc_io_state;   /* GRFC input/output states   */
   DWORD                 grfc_omode;   /* GRFC output mode           */
   DWORD              grfc_polarity;   /* GRFC polarity(acHI/acLO)   */
   DWORD                  grfc_data;   /* GRFC data (register values)*/

   /* PDM status */
   WORD    pdm_val[PDM_GSM_MAX_NUM];    /* PDM Values                 */
#else
typedef PACKED struct
{
   /* Miscellaneous Status */
   enum_type                   mode;   /* Current Mode               */
   enum_type               phone_id;   /* Phone Type                 */
   /* RF status            */
   uint16                   channel;   /* Current Channel            */
   enum_type           tx_power_lvl;   /* Current TX PCL             */
   boolean                 tx_state;   /* TX state                   */
   boolean                 pa_state;   /* PA state                   */
   enum_type              lna_range;   /* LNA gain range             */
   boolean               lna_on_off;   /* LNA power supply state     */
   boolean              mixer_state;   /* Mixer state                */
   int16                   vga_gain;   /* VGA gain (DP2000) support  */
   uint32                      rssi;   /* RSSI returned by MDSP      */
   /* GRFC llaneous Status */
   uint32             grfc_io_state;   /* GRFC input/output states   */
   uint32                grfc_omode;   /* GRFC output mode           */
   uint32             grfc_polarity;   /* GRFC polarity(acHI/acLO)   */
   uint32                 grfc_data;   /* GRFC data (register values)*/

   /* PDM status */
   uint16  pdm_val[PDM_GSM_MAX_NUM];    /* PDM Values                 */
#endif /* defined(__WIN32__) || defined(WIN32) */
   mod_cfg_type             mod_cfg;    /* Modulator config information */
   chfilt_cfg_type       chfilt_cfg;    /* Channel filter config information */
   grfc_timing_offset_type     grfc_timing[GRFC_MAX];		/* GRFC timing information */
   i_q_dc_offset_type i_q_dc_offset;    /* I and Q DC offsets calculated by MDSP */
} gsm_test_state_type;

#if defined(__WIN32__) || defined(WIN32)
typedef struct
{
   int2                                   gsm_test_id;
   union
   {
      BOOLEAN                           generic_bool;
      BYTE                            generic_8bit_u;
      WORD                           generic_16bit_u;
      DWORD                          generic_32bit_u;
      int2                                tx_pwr_lvl;
      int2                                  vga_gain;
#else
typedef PACKED struct
{
   enum_type                              gsm_test_id;
   PACKED union
   {
      boolean                           generic_bool;
      uint8                           generic_8bit_u;
      uint16                         generic_16bit_u;
      uint32                         generic_32bit_u;
      enum_type                           tx_pwr_lvl;
      int16                                 vga_gain;
#endif
      mdsp_peek_poke_type                mdsp_buffer;    /* mdsp buffer for direct peeks/pokes */
      grfc_setup_type                grfc_setup_info;    /* setup for all GRFCs                */
      grfc_type                                 grfc;    /* generic state data for a GRFC      */
      pa_lut_cfg_type                     pa_lut_cfg;    /* PA LUT configuration & power level */
      pa_lut_type                             pa_lut;    /* PA LUT values and cfg information  */
      mod_cfg_type                           mod_cfg;    /* modultaor configuration            */
      tx_burst_type                         tx_burst;    /* TX burst configuration             */
      chfilt_cfg_type                     chfilt_cfg;    /* Channel filter configuration       */
      rx_burst_type                         rx_burst;    /* RX burst command                   */
      gsm_test_state_type                 test_state;    /* Phone state                        */
      i_q_dc_offset_type               i_q_dc_offset;    /* I/Q DC offsets computed by MDSP    */
   } gsm_test_data_union;
} gsm_option_type;


typedef enum
{
   STATE_UNDEFINED,
   STATE_FTM,
   STATE_DMSS
} enum_phone_state_type;

typedef enum
{
   PEEK_DSP_INPORT = 200,			/*   0  - Allows retrieving the content of the QDSP3 MEMB                          */
   POKE_DSP_OUTPORT,           /*   1  - Allows to send user data to the QDSP3 MEMB                               */
   SET_GRFC_ALL,               /*   2  - Allows    user to set all GRFCs (configured as output)                   */
   GET_GRFC_ALL,               /*   3  - Allows    user to sense all GRFCs (configured as input/output)           */
   GRFC_CONFIG_ALL,            /*   4  - Allows    user to configure the GRFC (timing, direction, polarity, mode) */
   SET_GRFC_DATA,              /*   5  - Allows user to set a specific GRFC to the specified state (HI/LOW)       */
   SET_GRFC_OMODE,             /*   6  - Allows user to configure the output mode (static/timed) for a GRFC       */
   SET_GRFC_TRISTATE,          /*   7  - Allows user to tristate a specific GRFC                                  */
   SET_GRFC_POLARITY,          /*   8  - Allows user to set a specific GRFC polarity (active HI/active LOW)       */
   SET_SYNTH_ON,               /*   9  - Turns RF synthesizer circuitry on                                        */

   SET_SYNTH_OFF,              /*  10  - Turns RF synthesizer circuitry off                                       */
   SET_ANTENNA_CONFIG,         /*  11  - Configures the antenna switch/duplexer for RX/TX operation (band)        */
   SET_PA_PROFILE,             /*  12  - Downloads  GSM PA power profile for specified power level                */
   GET_PA_PROFILE,             /*  13  - Retrieves  GSM PA power profile for specified power level                */
   GET_PA_CONFIG,              /*  14  - Retrieves  GSM PA configuartion                                          */
   MODULATE_DATA,              /*  15  - Configures GMSK modulator                                                */
   TRANSMIT_CONT,              /*  16  - Transmits a tone (all 1's to GMSK modulator). Causes RF controls setup   */
   TRANSMIT_BURST,             /*  17  - Transmit user defined data pattern. Causes RF controls setup             */
   SET_VGA_GAIN_VAL,           /*  18  - Programs a gain value onto the VGA in RF module                          */
   SET_LNA_ON,                 /*  19  - Turns LNA On                                                             */

   SET_LNA_OFF,                /*  20  - Turns LNA off                                                            */
   SET_RX_ON,                  /*  21  - Perform all operations required to turn on RX circuitry                  */
   SET_RX_OFF,                 /*  22  - Perform all operations required to turn off RX circuitry                 */
   GET_RX_DC_OFFSET,           /*  23  - Get the residual DC reading from the RX samples                          */
   GET_RX_IQ_DATA,             /*  24  - Receive a specified number of raw RX samples                             */
   GET_RX_BURST,               /*  25  - Receive an RX burst of user specified length. Causes RF controls setup   */
   CHFILT_CONFIG,              /*  26  - Configure the channel filter                                             */
   SET_TX_POWER_LEVEL,         /*  27  - Selects TX power level by choosing a pre-configured PA LUT values        */
   GET_PHONE_TEST_STATE,       /*  28  - Queries the state of the phone, such as current channel, power level, etc*/
   SET_GRFC_TIMING,            /*  29  - Sets the timing information for a GRFC (as well as TX/RX/General)        */
   GET_RSSI,                   /*  30  - Get raw RSSI value                                                       */
   SET_PA_START_DELTA,					/*  31  - Moves the Pa ramp start time by the specified delta											 */
   SET_PA_STOP_DELTA,				  /*  32	- Moves the Pa ramp stop time by the specified delta											 */
   SET_PA_DAC_INPUT,						/*  33  - Sets the digital input sequence code for PA DAC													 */
   GSM_TEST_ID_MAX             /*  34  - Illegal test ID                                                          */

} gsm_test_id_type;



//values returned when requesting phone's mode type
typedef enum
{
   RETURN_FTM_MODE = 1,
   RETURN_ONLINE_MODE = 5

} mode_switching_return_type;


//values used to set phone run time mode
typedef enum
{
   DESIRED_FTM_MODE = 3,
   DESIRED_ONLINE_MODE = 4

} mode_switching_set_type;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntelliCeiver Enums and Data Types ---- Begin
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
   NV_COMMIT_SUCCESS,
   NV_COMMIT_FAIL
} NV_COMMIT_STATUS_TYPE;

class im2_cal_values_type
{
public:
   BYTE iDac;
   BYTE qDac;
   BYTE transconductance;

   bool operator<( const im2_cal_values_type& rhs ) const
   {
      return (this->iDac < rhs.iDac) && (this->qDac < rhs.qDac) && (this->transconductance < rhs.transconductance);
   }

   bool operator>( const im2_cal_values_type& rhs ) const
   {
      return (this->iDac > rhs.iDac) && (this->qDac > rhs.qDac) && (this->transconductance > rhs.transconductance);
   }

   bool operator<=( const im2_cal_values_type& rhs ) const
   {
      return (this->iDac <= rhs.iDac) && (this->qDac <= rhs.qDac) && (this->transconductance <= rhs.transconductance);
   }

   bool operator>=( const im2_cal_values_type& rhs ) const
   {
      return (this->iDac >= rhs.iDac) && (this->qDac >= rhs.qDac) && (this->transconductance >= rhs.transconductance);
   }

   bool operator!=( const im2_cal_values_type& rhs ) const
   {
      return (this->iDac != rhs.iDac) && (this->qDac != rhs.qDac) && (this->transconductance != rhs.transconductance);
   }

   bool operator==( const im2_cal_values_type& rhs ) const
   {
      return (this->iDac == rhs.iDac) && (this->qDac == rhs.qDac) && (this->transconductance == rhs.transconductance);
   }


};


class intelliceiver_cal_values_type
{
public:
   intelliceiver_cal_values_type() : channel( 0xFFFF ), clsJamMidPntPwr (0xFFFF), farJamMidPntPwr( 0xFFFF ) {}
   WORD channel;
   WORD clsJamMidPntPwr;
   WORD farJamMidPntPwr;
   bool operator<( const intelliceiver_cal_values_type& rhs ) const
   {
      return (this->channel < rhs.channel) && (this->clsJamMidPntPwr < rhs.clsJamMidPntPwr) && (this->farJamMidPntPwr < rhs.farJamMidPntPwr);
   }

   bool operator>( const intelliceiver_cal_values_type& rhs ) const
   {
      return (this->channel > rhs.channel) && (this->clsJamMidPntPwr > rhs.clsJamMidPntPwr) && (this->farJamMidPntPwr > rhs.farJamMidPntPwr);
   }

   bool operator<=( const intelliceiver_cal_values_type& rhs ) const
   {
      return (this->channel <= rhs.channel) && (this->clsJamMidPntPwr <= rhs.clsJamMidPntPwr) && (this->farJamMidPntPwr <= rhs.farJamMidPntPwr);
   }

   bool operator>=( const intelliceiver_cal_values_type& rhs ) const
   {
      return (this->channel >= rhs.channel) && (this->clsJamMidPntPwr >= rhs.clsJamMidPntPwr) && (this->farJamMidPntPwr >= rhs.farJamMidPntPwr);
   }

   bool operator!=( const intelliceiver_cal_values_type& rhs ) const
   {
      return (this->channel != rhs.channel) && (this->clsJamMidPntPwr != rhs.clsJamMidPntPwr) && (this->farJamMidPntPwr != rhs.farJamMidPntPwr);
   }

   bool operator==( const intelliceiver_cal_values_type& rhs ) const
   {
      return (this->channel == rhs.channel) && (this->clsJamMidPntPwr == rhs.clsJamMidPntPwr) && (this->farJamMidPntPwr == rhs.farJamMidPntPwr);
   }


};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntelliCeiver Enums and Data Types ---- End
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma pack()

#endif



