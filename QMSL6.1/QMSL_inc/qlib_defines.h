/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_inc/QLib_Defines.h#342 $
 * $DateTime: 2016/06/24 11:41:42 $
 *
 * DESCRIPTION: Definition for data types, structures, and used for the QLib.
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */

/*
\code
List of sections contained in this document:
QMSL - Connection/disconnection
Diagnostic - General Asynchronous message Logging
Diagnostic - Specific log messages
Diagnostic - phone version info
Diagnostic - reading embedded error information
Diagnostic - General command defines
Diagnostic - EFS Subsystem
Diagnostic - NV Subsystem
Diagnostic - GSDI Subsystem
Diagnostic - Streaming Download subsystem
Diagnostic - GPS Subsystem
Diagnostic - Call Manager subsytem
Diagnostic - LTE subsytem
Diagnostic - HDR subsytem
Diagnostic - GSM subsytem
Diagnostic - Handset subsytem
Diagnostic - MediaFLO subsystem
Diagnostic - CGPS subsystem
Diagnostic - ISDB-T subsystem
FTM - Command ID's
FTM - System Modes
FTM - RF Modes
FTM - RF Definitions
FTM - GSM RF
FTM - cdma2000 non-signaling log parser definitions
FTM - cdma2000 non-signaling
FTM - EVDO non-signaling log parser definitions
FTM - EVDO non-signaling
FTM - SV
FTM - Bluetooth
FTM - AGPS
FTM - PMIC
FTM - Customer Extensions
FTM - Audio
FTM - Camera
FTM - Log
FTM - WCDMA BER
FTM - HSDPA BLER
FTM - GSM BER
FTM - EGPRS BLER
FTM - Common RF
FTM - MediaFLO
FTM - GPS
FTM - Sequencer
Diagnostic - UBM DVBH
FTM - WLAN
FTM - NFC
FTM - FM FTM (FM Broadcast Radio)
FTM - Definitions for multiple FTM modes
QMSL - Text logging flags
QMSL - Time Out defintions
QMSL - Calibration Data Manager
QMSL - NV Tool
QMSL - Band Class Helper
\endcode
*/

#if !defined(_QLIB_DEFINES_H)
#define _QLIB_DEFINES_H

#pragma pack(1)        /* DM <--> DMSS packet definitions are byte packed */
//Define this flag for QMSL POSIX Portability. Enable this flag only for POSIX portability
//#define QMSL_POSIX_PORTABLE
/*===========================================================================
Definition of primitive data types
===========================================================================*/
#if !defined( QMSL_NO_REDEFINITION_OF_UNSIGNED_INTEGER_TYPES )

typedef unsigned char byte;         //!<' Definition of unsigned 8-bit type
typedef unsigned short word ;       //!<' Definition of unsigned 16-bit type
typedef unsigned long dword ;       //!<' Definition of unsigned 32-bit type

// AMSS types
typedef  unsigned long long int  uint64;      //!< Unsigned 64 bit value
typedef  unsigned long int  uint32;      //!< Unsigned 32 bit value
typedef  unsigned short     uint16;      //!< Unsigned 16 bit value
typedef  unsigned char      uint8;       //!< Unsigned 8  bit value
typedef  signed long int    int32;       //!< Signed 32 bit value
typedef  signed short       int16;       //!< Signed 16 bit value
typedef  signed char        int8;        //!< Signed 8  bit value

typedef  unsigned long int  uint4;       //!< Unsigned 32 bit value
typedef  unsigned short     uint2;       //!< Unsigned 16 bit value
typedef  unsigned char      uint1;       //!< Unsigned 8  bit value

typedef  signed short       int2;        //!< Signed 16 bit value
typedef  signed char        int1;        //!< Signed 8  bit value

#if !defined (QMSL_POSIX_PORTABLE)
typedef unsigned __int64 qword;  //!<' Definition of unsigned 64-bit type
#else
typedef unsigned long qword;
#endif

#endif  // #if !defined( QMSL_NO_REDEFINITION_OF_UNSIGNED_INTEGER_TYPES )

#if !defined( QMSL_NO_REDEFINITION_OF_BOOLEAN_TYPES )
typedef unsigned char boolean;
typedef unsigned char BOOLEAN;
#endif

/******************************************************************************
Basic Definitions
*******************************************************************************/

#if !defined( TRUE )
#define TRUE   1   //!<' Boolean true value.
#endif

#if !defined( FALSE )
#define FALSE  0   //!<' Boolean false value.
#endif

#if !defined( ON )
#define  ON   1    //!<' On value.
#endif

#if !defined( OFF )
#define  OFF  0    //!<' Off value.
#endif

//! Size of the ITEM DATA field for an NV request
#define DIAG_NV_ITEM_DATA_SIZE 128

//! Maximum size of diagnostic packet
#define DIAG_MAX_PACKET_SIZE (4096+1024)    /*Increased the size due to Sahara Protocol requirments */

//! Definition of the COM port value that will be used to "auto detect" the COM port
#define QLIB_COM_AUTO_DETECT ((word)0xFFFF)

/**
Definition of the COM port value that allows a NULL or empty connection, in
other words a phone does not have to be connected.  Only commands that do not
send a request/response will work in this mode. For example the mode is designed
to allow a DLF log file to playback while the QMSL measurent state machines are
active (e.g. cdma2000 SER/FER report)

WARNING: this device type is only valid in QPHONEMS mode (set using QLIB_SetLibraryMode() )
*/
#define QLIB_COM_NULL ((word)0xFFFE)

//! Definition of SUCCESS for the FTM STATUS field
#define DIAG_FTM_STATUS_SUCCESS 0

//! Definition of FAIL for the FTM STATUS field
#define DIAG_FTM_STATUS_FAIL 1

//!Defies maximum no. of character for EFS filename
#define EFS_MAX_FILENAME_LEN 40

/*=============================================================================*/
#define TXLIN_NUM_LINEARIZERS 4
#define TXLIN_NUM_TOTAL_LINEARIZERS 192
#define TXLIN_NUM_TOTAL_DPD_LINEARIZERS 32
#define TXLIN_NUM_SEGMENTS 64
#define TX_LINEARIZER_NUM_WAVEFORM 3
#define TX_LINEARIZER_NUM_WAVEFORM_REV2 4
#define TXLIN_NUM_FCOMP_SWEEP 2
#define TXLIN_NUM_CHANNELS 16
#define TXLIN_NUM_FREQCOMP_RGI_BIN 8
#define TXLIN_DEFAULT_FREQ_INDEX 7
#define TXLIN_NV_SIZE_MAX 99880
#define RX_MEAS_MAX_NUMPAYLOADS 2
#define ESC_MAX_DEVICES 8
#define MAX_LNA_GAIN_STATE 8
#define TXLIN_XPT_DPD_NUM_COEFF 16
#define NUM_RX_LNA_OFFSETS 5
#define MAX_NUM_TX_PATHS 4
#define MAX_NUM_CAL_PACKETS 10
#define MAX_CAL_PACKET_SIZE 4096
#define MAX_CAL_RESP_BUFFER_SIZE 40000
#define MAX_NUM_CAL_PKT_QUERY_RETRY 20
#define MAX_NUM_EPDT_SIZE 128
#define MAX_NUM_PA_STATES_FOR_PIN_CAL 8
#define MAX_NUM_FBRX_BANDWIDTH 14
#define MAX_NUM_FBRX_NV_MODES 4
#define NUM_FBRX_GAIN_STATES 4
#define NUM_RSB_GAIN_STATES 8
#define MAX_ENH_INTERNAL_DEVICE_CAL_RSB_VER_LENGTH 3000
#define WCDMA_TDS_ENH_INTERNAL_DEVICE_CAL_RSB_VER_LENTH 512
#define NUM_MAX_STG_FREQ_OFFS_FBRX_DROOP 12
#define NUM_MAX_DROOP_FILTER_PER_SWEEP 4
#define MAX_DROOP_FILTER_LEN 32
#define NUM_TX_RSB_IQMC_COMP 4
#define FFBRX_MAX_NUM_SC_DATA_BUF 136
#define FBRX_DATA_BUF_SIZE 800
#define FBRX_CAPTURE_MAX_NUMBER_OF_BYTES_DIAG 3700
#define DIAG_LIMIT_IN_BYTES 4020
#define MAX_NUM_RFM_PATHS 16
#define MAX_NUM_XPT_MODES 2
#define MAX_NUM_STG1_CAPTURES 20
#define MAX_TARGET_MEAS_PTS 5
#define MAX_TARGET_CALC_PTS 5
#define MAX_NUM_CHAN_QSC_RADIO_CONFIG_V1 3 //SC, DC,3C
#define MAX_NUM_PA_STATES_QSC 8
#define MAX_NUM_LIN_PER_PA_STATE_QSC 8
#define MAX_NUM_WFM_TYPES_QSC 6
#define MAX_NUM_FCOMP_CHANS_QSC 16
#define MAX_NUM_KERNELS 3
#define RFLM_LTE_PATH_TYPE_MAX 6
#define RFLM_LTE_CC_MAX 5
#define MAX_NUM_MULTIRX_PATHS 4
#define MAX_NUM_LO_FREQ_OFFSETS_FD_RX_RSB 4
#define MAX_NUM_LO_FREQ_OFFSETS_RX_RSB 4
#define MAX_NUM_RX_RSB_RFM_PATHS 8
#define MAX_NUM_RX_RSB_BWS 7
#define MAX_NUM_RX_RSB_CHANS 1
#define MAX_TX_LIN_PWR_LIST_SIZE    128 /* Max number of Tx lin measurements */
#define MAX_CHAN_LIST_SIZE          16 /* Max number of Tx cal channels */
#define MAX_PA_STATES               4 /* Max number of PA states */
#define MAX_GSM_MODULATION_TYPES    2 /* GMSK and 8PSK */
#define MAX_XPT_BW_COMBO 8 /* Number of BW dependent NV settings, could be upto 32 in LTE CA combinations */
/**
Defies maximum no. of bytes used for IQ samples response packtes payload.
The actual number of I and Q samples in the payload is dependent on the data format
of IQ samples (i.e. each I and Q sample can be either 8-bit or 16-bit)
*/
#define FTM_IQ_SAMPLES_MAX_NUMBER_OF_BYTES 3584

/******************************************************************************
QMSL - Connection/disconnection
*******************************************************************************/
/**
Packet mode definitions for QLIB_SetPacketMode

*/
typedef enum
{
   QLIB_PacketMode_BothDiag = 0,    //!<' Both library and phone in Diagnostic mode
   QLIB_PacketMode_BothAT       = 1,    //!<' Both library and phone in AT mode
   QLIB_PacketMode_LibAT        = 2,     //!<' Library in AT mode, phone is not controlled
   QLIB_PacketMode_QDL_NoHDLC        = 3     //!<' Library in QDL mode, No HDLC framing required, See 80-P0482-1 section 3
} QLIB_PacketMode_Enum;

#define QLIB_LIB_MODE_QPHONEMS false    //!<' Internal engine, QPHONEMS, also used for user defined transport
#define QLIB_LIB_MODE_QPST     true     //!<' Use QPST for packet transport

/**
Target type constant used by QLIB_SetTargetType
*/
typedef enum
{
   QLIB_TARGET_TYPE_MSM_MDM = 0,    // The target supports WWAN modem.
   QLIB_TARGET_TYPE_APQ     = 1,    // Application processor only type target (APQ).  No WWAN modem
   QLIB_TARGET_TYPE_MAX_INVALID = 2 // The invalid target type
} QLIB_TargetType_Enum;

/**
Target type constant used by QLIB_SetDiagType
*/
typedef enum
{
   QLIB_DIAG_FULL            = 0,    // The Diagnostic protocol using CRC and HDLC framing. Refer to 80-V1294-1 section 2
   QLIB_DIAG_QDL             = 1,    // The Diagnostic protocol without using CRC and HLDC framing. Refer to 80-P0482-1 section 3
   QLIB_DIAG_TYPE_INVLAID    = 2     // The invalid target type
} QLIB_DiagType_Enum;


/******************************************************************************
Diagnostic - General Request/Response
*******************************************************************************/

/*--------------------------------------------------------------------------

Command Codes between the Diagnostic Monitor and the mobile. Packets
travelling in each direction are defined here, while the packet templates
for requests and responses are distinct.  Note that the same packet id
value can be used for both a request and a response.  These values
are used to index a dispatch table in diag.c, so

DON'T CHANGE THE NUMBERS ( REPLACE UNUSED IDS WITH FILLERS ). NEW IDs
MUST BE ASSIGNED AT THE END.

This list is originally taken from the file DiagDefines.h, then reduced
to only include items necessary for this library.

If more items are desired or if new diag commands are added then this list
should be resync'd.

Note: The prefix _ is used here because the function names are exactly
the enumeration ID, as used in the embedded code

----------------------------------------------------------------------------*/

#define _DIAG_VERNO_F           0   //!<' Version Number Request/Response
#define _DIAG_ESN_F             1   //!<' Mobile Station ESN Request/Response
#define _DIAG_MEMORY_PEEK_BYTE_F 2  //!<' Memory peek request/response (8-bit)
#define _DIAG_MEMORY_PEEK_WORD_F 3  //!<' Memory peek request/response (16-bit)
#define _DIAG_MEMORY_PEEK_DWORD_F 4 //!<' Memory peek request/response (32-bit)
#define _DIAG_MEMORY_POKE_BYTE_F 5  //!<' Memory poke request/response (8-bit)
#define _DIAG_MEMORY_POKE_WORD_F 6  //!<' Memory poke request/response (16-bit)
#define _DIAG_MEMORY_POKE_DWORD_F 7 //!<' Memory poke request/response (32-bit)
#define _DIAG_STATUS_REQUEST_F  12  //!<'Status Request/Response
#define _DIAG_STATUS_F          14  //!<' Phone status
#define _DIAG_EFS2_DIAG_STAT    15  //!<' status
#define _DIAG_LOG_F             16  //!<' Log packet Request/Response

#define _DIAG_BAD_CMD_F         19  //!<' Invalid Command Response
#define _DIAG_BAD_PARM_F        20  //!<' Invalid parmaeter Response
#define _DIAG_BAD_LEN_F         21  //!<' Invalid packet length Response
#define _DIAG_BAD_MODE_F        24  //!<' Packet not allowed in this mode

/* 22-23 Reserved */

/* Packet not allowed in this mode
( online vs offline )                      */
#define DIAG_BAD_MODE_F     24

#define _DIAG_MSG_F             31  //!<' Request for msg report
#define _DIAG_HS_KEY_F          32  //!<' Handset Emulation -- keypress
#define _DIAG_SUBSYS_CMD_CODE   36  //!<' Subsystem command code for get group info
#define _DIAG_NV_READ_F         38  //!<' Read NV item
#define _DIAG_NV_WRITE_F        39  //!<' Write NV item
#define _DIAG_CONTROL_F         41  //!<' Mode change request
#define _DIAG_ERR_READ_F        42  //!<' Read error list
#define _DIAG_ERR_CLEAR_F       43  //!<' Clear error list
#define _DIAG_GET_DIPSW_F       47  //!<' Retreive dipswitch
#define _DIAG_SET_DIPSW_F       48  //!<' Set dipswitch
#define _DIAG_VOC_PCM_LB_F      49  //!<' Start/Stop Vocoder PCM loopback
#define _DIAG_VOC_PKT_LB_F      50  //!<' Start/Stop Vocoder PKT loopback
#define _DIAG_CALL_ORIGINATION      53  //!<' Start a Mobile Origination call, e.g., SO55 IS2000 loopback
#define _DIAG_DLOAD_F           58  //!<' Switch to download mode
#define _DIAG_SPC_F             65  //!<' Send the Service Prog. Code to allow SP
#define _DIAG_SERIAL_MODE_CHANGE 68 //!<' Switch mode from diagnostic to data
#define _DIAG_EXT_LOGMASK_F     93  //!<' Extended logmask for > 32 bits.
#define _DIAG_EVENT_REPORT_F    96  //!<' Static Event reporting.
#define _DIAG_PRL_WRITE         72  //!<' Single PRL Write
#define _DIAG_PRL_READ          73  //!<' Single PRL Read
#define _DIAG_SUBSYS_CMD_F      75  //!<' Subssytem dispatcher (extended diag cmd)
#define _DIAG_NV_WRITE_ONLINE_F 76  //!<' Write to NV location without going Offline
#define _DIAG_FEATURE_QUERY     81
#define _DIAG_IS2000_STATUS_F   112 //!<' IS-2000 Status
#define _DIAG_LOG_CONFIG_F      115 //!<' Logging configuration packet
#define _DIAG_EXT_MSG_F         121 //!<' Extended msg report
#define _DIAG_PROTOCOL_LOOPBACK_F  123 //!<' Diagnostics protocol loopback.
#define _DIAG_EXT_BUILD_ID_F    124 //!<' Extended build ID
#define _DIAG_EXT_MSG_CONFIG_F  125 //!<' Request for extended msg report
#define _DIAG_SECURITY_FREEZE_F 0xff    //!<' Request for Sirius security freeze (not defined yet)
#define _DIAG_QDL_HEADER            126 //!<' The first byte and last byte in QDL protocol (0x7E) See 80-P0482-1 section 3
#define _DIAG_SUBSYS_CMD_VER_2_F    128
#define _DIAG_EVENT_MASK_GET_F      129 //!<' Get event mask
#define _DIAG_EVENT_MASK_SET_F      130 //!<' Set event mask
#define _DIAG_OPTIMIZED_EXT_MSG_F   146 //!<' Optimized extended message (QShrink)
#define _DIAG_LOG_MULTI_SIM   152 //!< ' MultiSim Wrapper
#define _DIAG_QSHRINK_4      153 //!<  Optimized extended message (QShrink4)

/**
Diagnostic Subsystems, from Services\diagcmd.h

*/
typedef enum
{
   _DIAG_SUBSYS_OEM     = 0,
   _DIAG_SUBSYS_ZREX        = 1,
   _DIAG_SUBSYS_SD          = 2,
   _DIAG_SUBSYS_BT          = 3,
   _DIAG_SUBSYS_WCDMA       = 4,
   _DIAG_SUBSYS_HDR     = 5,
   _DIAG_SUBSYS_DIABLO      = 6,
   _DIAG_SUBSYS_TREX        = 7,
   _DIAG_SUBSYS_GSM     = 8,
   _DIAG_SUBSYS_UMTS        = 9,
   _DIAG_SUBSYS_HWTC        = 10,
   _DIAG_SUBSYS_FTM     = 11,
   _DIAG_SUBSYS_REX     = 12,
   _DIAG_SUBSYS_GPS     = 13,
   _DIAG_SUBSYS_WMS     = 14,
   _DIAG_SUBSYS_CM          = 15,
   _DIAG_SUBSYS_HS          = 16,
   _DIAG_SUBSYS_AUDIO_SETTINGS   = 17,
   _DIAG_SUBSYS_DIAG_SERV   = 18,
   _DIAG_SUBSYS_EFS     = 19,
   _DIAG_SUBSYS_PORT_MAP_SETTINGS  = 20,
   _DIAG_SUBSYS_MEDIAPLAYER= 21,
   _DIAG_SUBSYS_QCAMERA = 22,
   _DIAG_SUBSYS_MOBIMON = 23,
   _DIAG_SUBSYS_GUNIMON = 24,
   _DIAG_SUBSYS_LSM     = 25,
   _DIAG_SUBSYS_QCAMCORDER  = 26,
   _DIAG_SUBSYS_MUX1X       = 27,
   _DIAG_SUBSYS_DATA1X      = 28,
   _DIAG_SUBSYS_SRCH1X      = 29,
   _DIAG_SUBSYS_CALLP1X = 30,
   _DIAG_SUBSYS_APPS        = 31,
   _DIAG_SUBSYS_SETTINGS    = 32,
   _DIAG_SUBSYS_GSDI        = 33,
   _DIAG_SUBSYS_TMC     = 34,
   _DIAG_SUBSYS_USB     = 35,
   _DIAG_SUBSYS_PM          = 36,
   _DIAG_SUBSYS_DEBUG       = 37,
   _DIAG_SUBSYS_QTV     = 38,
   _DIAG_SUBSYS_CLKRGM      = 39,
   _DIAG_SUBSYS_DEVICES = 40,
   _DIAG_SUBSYS_WLAN        = 41,
   _DIAG_SUBSYS_PS_DATA_LOGGING=42,
   _DIAG_SUBSYS_MFLO        = 43,
   _DIAG_SUBSYS_DTV     = 44,
   _DIAG_SUBSYS_RRC     = 45,
   _DIAG_SUBSYS_PROF        = 46,
   _DIAG_SUBSYS_TCXOMGR = 47,
   _DIAG_SUBSYS_NV          = 48,
   _DIAG_SUBSYS_AUTOCONFIG  = 49,
   _DIAG_SUBSYS_PARAMS      = 50,
   _DIAG_SUBSYS_MDDI        = 51,
   _DIAG_SUBSYS_DS_ATCOP    = 52,
   _DIAG_SUBSYS_L4LINUX = 53,
   _DIAG_SUBSYS_MVS     = 54,
   _DIAG_SUBSYS_CNV     = 55,
   _DIAG_SUBSYS_LTE     = 68,
   _DIAG_SUBSYS_CMAPI   = 85,
   _DIAG_SUBSYS_GNSS_SOC = 92,
   _DIAG_SUBSYS_SYSTEM_OPERATIONS = 101,
   _DIAG_SUBSYS_LAST
} DiagPkt_Subsys_cmd_enum_type;

/******************************************************************************
Diagnostic - General Asynchronous message Logging
*******************************************************************************/

//! Structure to define storage area for a response messages in a queue
typedef struct
{
   word iMessageLength;

   // This object can be accessed as a single large buffer of bytes...
   byte iData[DIAG_MAX_PACKET_SIZE];
} ResponseMessage;

/*===========================================================================*/
/**
enum log_equip_id_enum_type

\brief Log Equipment IDs. The number is represented by 4 bits.
*/
/*===========================================================================*/
typedef enum
{
   LOG_EQUIP_ID_OEM   = 0,  //!<' 3rd party OEM (licensee) use
   LOG_EQUIP_ID_1X    = 1,  //!<' Traditional 1X line of products
   LOG_EQUIP_ID_RSVD2 = 2,
   LOG_EQUIP_ID_RSVD3 = 3,
   LOG_EQUIP_ID_WCDMA = 4,  //!<' WCDMA
   LOG_EQUIP_ID_GSM   = 5,  //!<' GSM
   LOG_EQUIP_ID_MSP   = 6,
   LOG_EQUIP_ID_UMTS  = 7,  //!<' UMGS
   LOG_EQUIP_ID_TDMA  = 8,  //!<' TDMA
   LOG_EQUIP_ID_BOA   = 9, //!<' BOA
   LOG_EQUIP_ID_DTV   = 10,//!<' DTC
   LOG_EQUIP_ID_LTE   = 11, //!<' LTE
   LOG_EQUIP_ID_DSP   = 12,//!<' DSP
   LOG_EQUIP_ID_TDSCDMA = 13,//!<' TDSCDMA

   LOG_EQUIP_ID_LAST_DEFAULT = LOG_EQUIP_ID_TDSCDMA,
   LOG_EQUIP_ID_MAX = 16
} log_equip_id_enum_type;

/*===========================================================================*/
/**
enum log_operation_id_enum_type

\brief List of log configuration operations
*/
typedef enum
{
   LOG_CONFIG_OP_DisableLogging,    //!<' 0 = Disable logging service
   LOG_CONFIG_OP_RetrieveIDs,       //!<' 1 = Retrieve ID ranges
   LOG_CONFIG_OP_Reserved,          //!<' 2 = (Reserved)
   LOG_CONFIG_OP_SetLogMask,        //!<' 3 = Set log mask
   LOG_CONFIG_OP_GetLogMask     //!<' 4 = Get log mask
} log_operation_id_enum_type;

#define LOG_CODE_FTM_2          0x117C  //!<' FTM Version 2 log file
#define LOG_CODE_BT_HCI_EVENT   0x1366  //!<' Bluetooth HCI Event, 0x1366
#define LOG_CODE_LAST_ITEM_1X   0x02E8  //!<' Last item number for 1X, log code 1.

//! Number of bytes used for time stamp in diagnostic async messages
#define QMSL_DIAG_TIME_STAMP_SIZE 8

/*===========================================================================*/
/**
structure for an SD\EMMC Information

*/
/*===========================================================================*/
typedef enum
{
   SDCC_CARD_UNKNOWN = 0, /**< Card cannot be detected */
   SDCC_CARD_SD = 1, /**< SD card with card size <= 2GB */
   SDCC_CARD_MMC = 2, /**< MMC card with card size <= 2GB */
   SDCC_CARD_COMB = 3, /**< Comb card that supports both SDIO and memory */
   SDCC_CARD_SDIO = 4, /**< SDIO card */
   SDCC_CARD_SDHC = 5, /**< SD high capacity card with card size > 2GB */
   SDCC_CARD_MMCHC = 6 /**< MMC high capacity card with card size > 2GB */
} SDCC_CARD_TYPE;
/*SDCC_EXTRACT_COMMON_END*/

typedef enum
{
   SDCC_SD_SPEED_CLASS_0,
   SDCC_SD_SPEED_CLASS_2,
   SDCC_SD_SPEED_CLASS_4,
   SDCC_SD_SPEED_CLASS_6
} sdcc_sd_speed_class_type;
/**
* @ingroup sdcc_api
* speed class for MMC/eMMC card
* Refer to JEDEC Standard No.\ 84-A43, Sections 7.8.1 and 8.4 for
* detailed speed class definition
*/
typedef enum
{
   SDCC_MMC_SPEED_CLASS_LOWEST = 0x00, /**< For cards not reaching the 2.4MB/s
                                       * value */
   SDCC_MMC_SPEED_CLASS_A = 0x08, /**< Lower bus category classes (26MHz
                                                                      * clock with 4bit data bus operation) */
   SDCC_MMC_SPEED_CLASS_B = 0x0A,
   SDCC_MMC_SPEED_CLASS_C = 0x0F,
   SDCC_MMC_SPEED_CLASS_D = 0x14,
   SDCC_MMC_SPEED_CLASS_E = 0x1E,
   SDCC_MMC_SPEED_CLASS_F = 0x28, /**< Mid bus category classes (26MHz
                                                                                                     * clock with 8bit data bus or 52MHz
                                                                                                     * clock with 4bit data bus operation) */
   SDCC_MMC_SPEED_CLASS_G = 0x32,
   SDCC_MMC_SPEED_CLASS_H = 0x3C,
   SDCC_MMC_SPEED_CLASS_J = 0x46,
   SDCC_MMC_SPEED_CLASS_K = 0x50, /**< High bus category classes (52MHz
                                                                                                                                    * clock with 8bit data bus operation) */
   SDCC_MMC_SPEED_CLASS_M = 0x64,
   SDCC_MMC_SPEED_CLASS_O = 0x78,
   SDCC_MMC_SPEED_CLASS_R = 0x8C,
   SDCC_MMC_SPEED_CLASS_T = 0xA0
} sdcc_mmc_speed_class_type;

typedef struct _sdcc_mem_info
{
   SDCC_CARD_TYPE card_type; /**< card type such as SD or MMC */
   dword card_size_in_sectors;
   /**< If the sdcc device handle represents the entire device, card size in
   * sectors denotes the size for the card.\ If the sdcc device handle
   * represents a physical partition, card size in sectors denotes the size
   * of the physical partition.
   * Each sector has 512 bytes */
   dword write_protect_group_size_in_sectors;
   /**< size of the write protect group in sectors
   * Each sector has 512 bytes.\ If this is 0, write protect is not
   * supported.\ This write protect group size can vary from 512 bytes to
   * 33292800 kilobytes.\ Refer to sections 8.3 and 8.4 in JEDEC Standard
   * No. 84-A44 for write protect group size calculation details. */
   dword block_len; /**< number of bytes per block */
   union
   {
      sdcc_sd_speed_class_type sd_speed_class;
      /**< speed class for SD card */
      sdcc_mmc_speed_class_type mmc_speed_class;
      /**< speed class for MMC card */
   } speed_class;
   dword reliable_write_sector_count;
   /**< For eMMC only: the number of reliable write sector count supported */
   boolean is_embedded_device;
   /**< flag to indicate if device is embedded */
   dword num_phy_partition_created;
   /**< number of physical partition created */
   dword phy_partition_type;
   /**< type of physical partition to indicate if partition is the user
   * area, boot partition, general purpose partition, etc. */
   boolean is_phy_partition_bootable;
   /**< flag to indicate if the physical partition is bootable */
   word mfr_id; /**< manufacturer ID */
   word oem_id; /**< OEM/application ID */
   byte prod_name[7];
   /**< product name with NULL terminator
   * For SD card, product name is 5 characters long
   * For MMC card, product name is 6 characters long */
   byte prod_rev; /**< product revision */
   dword prod_serial_num; /**< product serial number */
   byte mfr_date[8];
   /**< manufacturing date according to SD Physical Layer Specification and
   * MMC/eMMC System Specification
   * Manufacturing date is in mm/yyyy format. */
} sdcc_mem_info_type;

/*===========================================================================*/
/**
structure for an ExtendedMessage, as described in CDMA ICD 3.4.121 Extended Message

*/
/*===========================================================================*/
#define EXTENDED_MESSAGE_FTM_STRING_SIZE 200

#define EXTENDED_MESSAGE_MAX_NUM_ARGS 10

typedef struct
{
   byte CMD_CODE;       //!< ' Message ID. The DMSS sets CMD_CODE to 121 for this message.
   byte TS_TYPE;        //!< ' Time stamp type; an enumeration indicating the format of the TIME field
   byte NUM_ARGS;       //!< ' The number of 32-bit arguments listed in the ARGS field.
   byte DROP_CNT;       //!< ' Total number of messages dropped between this message and the previous one
   byte TIME[QMSL_DIAG_TIME_STAMP_SIZE];        //!< ' Time the message was originally generated (not transmitted)
   word LINE_NUMBER;    //!< ' Line number identifying location of the message in the file denoted by FILE_NAME
   word SS_ID;          //!< ' Subsystem identifier; see Section 3.4.125.2 for description
   dword SS_MASK;       //!< ' Subsystem mask; see Section 3.4.125.2 for description
   dword ARG_1;     //!< ' The first 32-bit signed arguments, corresponding to the printf-style FMT_STRING, for backward compitability
   dword ARG_2;     //!< ' The second 32-bit signed arguments, corresponding to the printf-style FMT_STRING, for backward compitability
   dword ARG_3;     //!< ' The third 32-bit signed arguments, corresponding to the printf-style FMT_STRING, for backward compitability
   dword ARGS[EXTENDED_MESSAGE_MAX_NUM_ARGS];//!< ' Array of all 32-bit signed arguments, corresponding to the printf-style FMT_STRING
   char FMT_STRING[EXTENDED_MESSAGE_FTM_STRING_SIZE];       //!< ' NULL-terminated ASCII string containing a printf()-style format,
   //!< '  string, with formatting specifiers
   char FILE_NAME[EXTENDED_MESSAGE_FTM_STRING_SIZE];        //!< ' NULL-terminated ASCII file name string identifying the location of message

   char FORMATTED_STRING[EXTENDED_MESSAGE_FTM_STRING_SIZE];//!< ' NULL-terminated ASCII string containing the final output combining FMT_STRING and ARGS.
} ExtendedMessage;

/*===========================================================================*/
/**
structure for an optimized Extended Message, as described in CDMA ICD 3.4.132 Optimized extended message (149/0x92)
*/
/*===========================================================================*/
typedef struct
{
   byte CMD_CODE;       //!< ' Message ID. The DMSS sets CMD_CODE to 121 for this message.
   byte TS_TYPE;        //!< ' Time stamp type; an enumeration indicating the format of the TIME field
   byte NUM_ARGS;       //!< ' The number of 32-bit arguments listed in the ARGS field.
   byte DROP_CNT;       //!< ' Total number of messages dropped between this message and the previous one
   byte TIME[QMSL_DIAG_TIME_STAMP_SIZE];        //!< ' Time the message was originally generated (not transmitted)
   word LINE_NUMBER;    //!< ' Line number identifying location of the message in the file denoted by FILE_NAME
   word SS_ID;          //!< ' Subsystem identifier; see Section 3.4.125.2 for description
   dword SS_MASK;       //!< ' Subsystem mask; see Section 3.4.125.2 for description
   dword HASH;          //!< ' Hash value generated by Qshrink tool for debug string
   dword ARGS[EXTENDED_MESSAGE_MAX_NUM_ARGS];       //!< ' Array of 32-bit signed arguments, corresponding to the printf-style FMT_STRING; this array contains NUM_ARGS 32-bit arguments

   char FILE_NAME[EXTENDED_MESSAGE_FTM_STRING_SIZE];        //!< ' NULL-terminated ASCII file name string identifying the location of message
   char FORMATTED_STRING[EXTENDED_MESSAGE_FTM_STRING_SIZE];//!< ' NULL-terminated ASCII string containing the final output combining FMT_STRING and ARGS.
} OptimizedExtendedMessage;

/*===========================================================================*/
/**
Structure of a log message, as described in WCDMA ICD section 4.1 - Log record structure
*/
/*===========================================================================*/

typedef struct
{
   byte CMD_CODE;
   byte MORE;
   word length;
   word length2;
   word log_item;
   byte iTimeStamp[QMSL_DIAG_TIME_STAMP_SIZE];
   byte iLogMsgData[DIAG_MAX_PACKET_SIZE - 6] ;
} LogMessage;

/*===========================================================================*/
/**
Structure of a streaming message, as described in WCDMA ICD 3.5.17.2 - Message Response Message
*/
/*===========================================================================*/

typedef struct
{
   byte CMD_CODE;       // (31) for a streaming message
   word QUANTITY;
   dword DROP_CNT;
   dword TOTAL_MSGS;
   byte MESSAGE_LEVEL;
   char FILE_NAME[13];
   word LINE_NUMBER;
   byte FMT_STRING[40];
   dword CODE1;
   dword CODE2;
   dword CODE3;
   byte TIME[QMSL_DIAG_TIME_STAMP_SIZE];
} MessageResponse;

/**
Subsystem dispatcher header, request or response.
*/
typedef struct
{
   byte cmdCode ;             //!<' = DIAG_SUBSYS_CMD_F
   byte subsysId ;            //!<' = diagpkt_subsys_cmd_enum_type
   word subsysCmdCode ;      //!<' Subsystem-specific command code.
} diagpkt_subsys_header_type;

/**
FTM Subsystem dispatcher header, request with extended information
*/
typedef struct
{
   diagpkt_subsys_header_type Diag_Header;

   word cmd_id;         //!<' ftm_hdr.cmd_id;
   word data_len;           //!<' ftm_hdr.data_len
   word rsp_pkt_size;       //!<' ftm_hdr.rsp_pkt_size
} ftm_extended_request_header_type;

/**
FTM Subsystem dispatcher header, response with extended information + status
*/
typedef struct
{
   ftm_extended_request_header_type ftm_extended_header;
   word status;
} ftm_extended_response_header_type;

/*===========================================================================*/
/**
Structure of a streaming event, as described in WCDMA ICD 3.4.95 Event Report
*/
/*===========================================================================*/

typedef struct
{
   byte CMD_CODE;       //!<' (96) for a streaming event
   word iLength;        //!<' # of bytes in the EVENTS field
   byte aiEvents[ DIAG_MAX_PACKET_SIZE - 3];    //!<' EVENTS field, list of event items
} Event_struct;

/*===========================================================================*/
/**
Structure of a the EVENT item defintion, as described in WCDMA ICD 3.4.95 Event Report
*/
/*===========================================================================*/

typedef struct
{
   word EVENT_ID;       //!<' # of event ID
   word iLength;        //!<' # of bytes in the EVENTS field
   byte iTime[QMSL_DIAG_TIME_STAMP_SIZE];       //!<' time event was generated, this is possibly a 2-byte field
   byte iPayloadEn; //!<' Is the payload enabled?
   byte aiPayload[DIAG_MAX_PACKET_SIZE];    //!<' payload, generally not used, size is variable
} EventItem_struct;

/**
Bit field maping of the EVENT_ID field
*/
typedef struct
{
   //! Unique event ID
   word event_id : 12;

   word reserved : 1;

   /**
   Flag to specify whether PAYLOAD _DATA is present in event
   \code
   0 = No payload data
   1 = One byte of payload data, no PAYLOAD_LENGTH field
   2 = Two bytes of payload data, no PAYLOAD_LENGTH field
   3 = One byte PAYLOAD_LENGTH field specifying length of payload data to follow it
   \endcode
   */
   word payload_length_flag : 2;

   /**
   \code
   0 = Full system time stamp is 8 bytes
   1 = Truncated time stamp is 2 bytes
   \endcode
   */
   word time_length : 1;
} EventIdBitField;

/*===========================================================================*/
/**
enum time_length_enum_type

\brief Enumeration for the time stamp in CDMA DMSS ICD 80-V1294-1 3.4.95
*/
typedef enum
{
   FULL_SYS_TIME = 0,
   TRUNCATED_SYS_TIME,
   MAX_SYS_TIME = 0xff
} time_length_enum_type;

/*===========================================================================*/
/**
enum time_stamp_length

\brief Enumeration for the time stamp length (bytes) in CDMA DMSS ICD 80-V1294-1 3.4.95
*/
typedef enum
{
   TRUNCATED_TIMESTAMP = 2,
   FULL_SYSTEM_TIMESTAMP = 8
} time_stamp_length;

/*===========================================================================*/
/**
enum payload_length_data_flag

\brief Enumeration for the payload_length_data_flag in CDMA DMSS ICD 80-V1294-1 3.4.95
*/
typedef enum
{
   NO_PAYLOAD_DATA = 0,
   ONE_BYTE_PAYLOAD_DATA,
   TWO_BYTE_PAYLOAD_DATA,
   VAR_LENGTH_PAYLOAD_DATA,
   MAX_PAYLOAD_DATA = 0xff
} payload_length_data_flag;

/*===========================================================================*/
/**
struct QMSL_Event_Element_Struct

\brief Structure to define how QMSL will store events in the event queue
*/
#define QMSL_EVENT_PAYLOAD_DATA_MAX 256
typedef struct
{
   unsigned char time_length;   //!< # of bytes used to store type, 8 = full system time (FULL_SYSTEM_TIMESTAMP), 2=Truncated time (TRUNCATED_TIMESTAMP)
   unsigned char time[QMSL_DIAG_TIME_STAMP_SIZE];       //!< 8 or 2 bytes of system time, format depends upon time_length field
   unsigned short event_id; //!< 12-bit unique ID of event
   unsigned char payload_len;   //!< # of bytes stored in payload_len
   unsigned char payload_data[ QMSL_EVENT_PAYLOAD_DATA_MAX ];   //!< payload data, payload_len field determines # of valid bytes
} QMSL_Event_Element_Struct;

//! Wildcard event ID
#define QMSL_EVENT_ID_WILDCARD 0xFFFF

/******************************************************************************
Diagnostic - Specific log messages
*******************************************************************************/

/*===========================================================================*/
/**
Structure for interpretting log code 0x7005, MMGPS report measurement

This log message has an array of these items.  The overall structure
is defined by MMGPS_ReportMeasurement.
*/
/*===========================================================================*/
typedef struct
{
   byte SV_ID;
   byte HEALTH;
   byte ELEVATION;
   byte AZIMUTH;
   word SNR;
   word CNO;
   word LATENCY_MS;
   byte PRE_INT;
   word POST_INT;
   dword    MILLISECOND;
   dword    SUB_MILLISECOND;
   word SV_TIME_UNC;
   dword    SV_SPEED;
   word SV_SPEED_UNC;
   word MEAS_STATUS;
   byte CHANNEL_STATE;
   byte GOOD_OBSERVATIONS;
   byte TOTAL_OBSERVATIONS;
   word RESERVED;
} MMGPS_ReportMeasurement_MeasurementRow;

#define DIAG_MMGPS_NUM_MEASUREMENT_REPORTS 13

/*===========================================================================*/
/**
Structure for interpretting log code 0x7005, MMGPS report measurement

*/
/*===========================================================================*/
typedef struct
{
   dword    FCOUNT;
   MMGPS_ReportMeasurement_MeasurementRow aMeasurements[ DIAG_MMGPS_NUM_MEASUREMENT_REPORTS ];
} MMGPS_ReportMeasurement;

/*===========================================================================*/
/**
Structure for interpretting log code 0x701f, MMGPS report measurement

This log message has an array of these items.  The overall structure
is defined by MMGPS_ReportMeasurement.
*/
/*===========================================================================*/
typedef struct
{
   byte SV_ID;
   byte HEALTH;
   byte ELEVATION;
   byte AZIMUTH;
   word SNR;
   word CNO;
   word LATENCY_MS;
   byte PRE_INT;
   word POST_INT;
   dword    MILLISECOND;
   dword    SUB_MILLISECOND;
   word SV_TIME_UNC;
   dword    SV_SPEED;
   word SV_SPEED_UNC;
   word MEAS_STATUS;
   byte CHANNEL_STATE;
   byte GOOD_OBSERVATIONS;
   byte TOTAL_OBSERVATIONS;
   dword    RESERVED;       // The size of this field is the difference between version 1 and 3
} MMGPS_ReportMeasurement_MeasurementRow_V3;

#define DIAG_MMGPS_NUM_MEASUREMENT_REPORTS_V3 32
/*===========================================================================*/
/**
Structure for interpretting log code 0x701f, MMGPS report measurement

*/
/*===========================================================================*/
typedef struct
{
   dword    FCOUNT;
   word LENGTH;
   byte VERSION;
   byte RESERVE1[8];
   byte NUMBER_SVS; // 1 to 32

   MMGPS_ReportMeasurement_MeasurementRow aMeasurements[ DIAG_MMGPS_NUM_MEASUREMENT_REPORTS_V3 ];
} MMGPS_ReportMeasurement_V3;

/**
Structure of the Bluetooth local version, as defined in "BLUETOOTH SPECIFICATION Version 1.1"
*/
typedef struct
{
   byte  BT_EventHeader[6]; //!<'  Header information associated with the Bluetooth event
   byte  BT_Status;         //!<'  Should == BT_BE_SUCCESS == 0x00
   byte  HCI_Version;           //!<'  Should == (BT_HCI_VERSION_1_1 == 0x01) ||(BT_HCI_VERSION_1_2 = 0x02)
   word HCI_Revision;           //!<'  Should == 0
   byte  LMP_Version;           //!<'  For 1.1: (BT_LMP_VERSION_1_0 == 0x01), for 2.0: BT_LMP_VERSION_1_2
   word Manufacturer_Name;      //!<'  For QCOM: 29 (0x1D)
   word LMP_Subversion;     //!<'  BT_LMP_SUB_VER_NUM_0 == 0
} Bluetooth_LocalVersion_struct;

/**
Details described in HCI Vendor specific Interface Control 80-VE132-7 section 2.5.2.1

The structure describes the measured RF performance statistics for the test link.
Fields of the structure describe the data returned for one channel.
*/
typedef struct
{
   unsigned long packetReceived;
   unsigned long packetAccessError;
   unsigned long hecError;
   unsigned long crcError;
   unsigned long totalPacketBitErrors;
   unsigned long firstHalfBitErrors;
   unsigned long lastHalfBitErrors;
   unsigned long rssiReading;
} BlueTooth_Prod_Test_Channel_Stat;

/**
Details described in HCI Vendor specific Interface Control

The structure describes the measured RF performance statistics for the list mode test link.
Fields of the structure describe the data returned for one modulation type.
*/
typedef struct
{
   unsigned long totalReceivePackets;
   unsigned long totalAccessOKPackets;
   unsigned long totalHECOKPackets;
   unsigned long totalTypeOKPackets;
   unsigned long totalCrcOKPackets;
   unsigned long totalPayloadOKPackets;
   unsigned long totalBitError;
} BlueTooth_Prod_Test_ListMode_Stat;

typedef struct
{
   unsigned long totalReceivePackets;
   unsigned long totalAccessOKPackets;
   unsigned long totalHECOKPackets;
   unsigned long totalTypeOKPackets;
   unsigned long totalCrcOKPackets;
   unsigned long totalPayloadOKPackets;
} LE_Prod_Test_ListMode_Stat;

/**
Details described in HCI Vendor specific Interface Control HCI_GET_PER

The structure describes the measured RF performance statistics for the test link.
Fields of the structure describe the data returned for one channel.
*/
typedef struct
{
   unsigned long packetcrcError;
   unsigned long packetReceived;
} BlueTooth_Prod_Test_PER_Stat;

/**
different packet types that can be transmitted from the BlueTooth
Each of these packets contain a different type of payload length.
80-VE132-7 documents the use of following values with in the Production test commands.
*/
typedef enum
{
   BT_NULL = 0x00,
   BT_POLL = 0X01,
   BT_FHS = 0X02,
   BT_DM1 = 0x03,
   BT_DH1 = 0x04,
   BT_AUX1 = 0x09,
   BT_DM3 = 0x0A,
   BT_DH3 = 0x0B,
   BT_DM5 = 0x0E,
   BT_DH5 = 0x0F,
   BT_2_DH1 = 0x24,
   BT_2_DH3 = 0x2A,
   BT_2_DH5 = 0x2E,
   BT_3_DH1 = 0x28,
   BT_3_DH3 = 0x2B,
   BT_3_DH5 = 0x2F,
   BT_HV1 = 0x05,
   BT_HV2 = 0x06,
   BT_HV3 = 0x07,
   BT_DV = 0x08,
   BT_EV3 = 0x17,
   BT_EV4 = 0x1C,
   BT_EV5 = 0x1D,
   BT_2_EV3 = 0x36,
   BT_2_EV5 = 0x3C,
   BT_3_EV3 = 0x37,
   BT_3_EV5 = 0x3D
} BlueTooth_PacketType;

/**
Transmitted pattern payload, independent of the master pattern.
80-VE132-7 documents the use of following values with in the Production test commands.
*/
typedef enum
{
   ALL_ZEROES           = 0x00,
   ALL_ONES         = 0x01,
   ALTERNATING_BIT      = 0x02,
   ALTERNATING_NIBBLE   = 0x03,
   PSEUDO_RANDOM        = 0x04
} BlueTooth_TransmittPatternPayload;

/**
Different transmit types used in VS_PROD_TEST_SUBCOMMAND_TEST_TXC_ONLY
80-VE132-7 documents the use of following values in section 2.5.1.5
*/
typedef enum
{
   BT_1_CARRIER = 0x04,
   BT_1_PRBS9 = 0x05,
   BT_1_PRBS15 = 0x06,
   BT_1_PATTERN = 0x07,
   BT_2_PRBS9 = 0x08,
   BT_2_PRBS15 = 0x09,
   BT_2_PATTERN = 0x0A,
   BT_3_PRBS9 = 0x0B,
   BT_3_PRBS15 = 0x0C,
   BT_3_PATTERN = 0x0D
} BlueTooth_TransmitType;

/**
BT Response return from different commands.
80-VE132-7 documents the use of following struct in section 2.5.1.4
*/
typedef struct
{
   unsigned char eventCode;
   unsigned char lengthOfPacket;
   unsigned char status;
   unsigned char num_hci_command_packets;
   unsigned short command_opcode;
} BlueTooth_HCI_COMMAND_STATUS_EVENT;

/**
BT Response return from different commands.
80-VE132-7 documents the use of following struct in section 2.5.1.5
*/
typedef struct
{
   unsigned char eventCode;
   unsigned char lengthOfPacket;
   unsigned char num_hci_command_packets;
   unsigned short commandOpCode;
} BlueTooth_HCI_COMMAND_COMPLETE_EVENT;

/**
BT Response return from different commands.
80-VE132-7 documents the use of following struct in section 2.5.1.4
*/
typedef struct
{
   unsigned char eventCode;
   unsigned char lengthOfPacket;
   unsigned char status;
   unsigned short connection_handle;
   unsigned char bd_Add1;
   unsigned char bd_Add2;
   unsigned char bd_Add3;
   unsigned char bd_Add4;
   unsigned char bd_Add5;
   unsigned char bd_Add6;
   unsigned char linkType;
   unsigned char encryption;
} BlueTooth_HCI_CONNECTION_COMPLETE_EVENT;

/**
BT Response to the EDL_POKE32_REQ command.
*/
typedef struct
{
   unsigned char eventCode;
   unsigned char paramTotalLength;
   unsigned char vendorDownloadResponse;
   unsigned char downloadResponse;
   unsigned char status;
   unsigned char processor;
   unsigned char application;
} BlueTooth_HCI_EDI_STATUS_RSP_EVENT;

/******************************************************************************
NFC FTM
*******************************************************************************/
/**
FTM command IDs for NFC FTM subystem
*/
typedef enum
{
   _FTM_NFC_I2C_SLAVE_WRITE             = 0,    //!< I2C slave write
   _FTM_NFC_I2C_SLAVE_READ              = 1,    //!< I2C slave read
   _FTM_NFC_NFCC_COMMAND_RESPONSE       = 2,    //!< NFCC Command-Response
   _FTM_NFC_SEND_DATA                   = 3,    //!< Send Data Command-Response
   _FTM_NFC_REQ_CHIP_TYPE               = 4,    //!< Get Chip Type
   _FTM_NFC_FWPIN_CTRL                  = 5,    //!< Set FW Pin State
} FTM_NFC_Command_ID_Enum;

#define LOG_NFC_FTM 0x1802

/**
The maximum number of bytes in an NFC FTM payload
*/
#define FTM_NFC_LOG_PAYLOAD_MAX_SIZE 258

/**
The maximum number of bytes in an NFC NCI command payload
*/
#define FTM_NFC_NCI_CMD_PAYLOAD_MAX_SIZE 258

/**
The maximum number of bytes in an NFC NCI response payload
*/
#define FTM_NFC_NCI_RSP_PAYLOAD_MAX_SIZE 258

/**
The maximum number of bytes in an NFC NCI notification payload
*/
#define FTM_NFC_NCI_NTF_PAYLOAD_MAX_SIZE 258

/**
The maximum number of bytes in an NFC Send Data command payload
*/
#define FTM_NFC_DATA_PAYLOAD_MAX_SIZE 258

/**
The maximum number of NFC FTM Logs
*/
#define FTM_NFC_LOG_MAX_LOGS    1000

/**
NFC FTM Log definition for one log entry
*/
typedef struct
{
   byte iTimeStamp[QMSL_DIAG_TIME_STAMP_SIZE];                          //!<' AMSS timestamp

   unsigned char aNFC_FTM_Log_Payload[FTM_NFC_LOG_PAYLOAD_MAX_SIZE];    //!<' NFC FTM log payload

   unsigned short iNFC_FTM_Load_Payload_Size;                           //!<' Size of NFC FTM log payload
} FTM_NFC_Log;

/**
This buffer stores an array of NFC FTM logs
*/
typedef struct
{
   FTM_NFC_Log aNFC_FTM_Logs [FTM_NFC_LOG_MAX_LOGS];                    //!<' Array of FTM logs

   unsigned short iNumFTMNFCLogs;                                       //!<' Number of valid Bluetooth FTM logs in aNFC_FTM_Logs

   unsigned char  bBufferFull;                                          //!<' 1 indicates the internal buffer is full. NFC FTM logs may have been discarded.  0 indicates the buffer is not full
} FTM_NFC_Logs;

/******************************************************************************
FM FTM (FM Broadcast Radio)
*******************************************************************************/
/**
FTM command IDs for FM FTM subystem
*/
typedef enum
{
   _FTM_FM_RX_ENABLE_RECEIVER             = 7,    //!< Enable FM Receiver
   _FTM_FM_RX_DISABLE_RECEIVER            = 8,    //!< Disable FM Receiver
   _FTM_FM_RX_CONFIGURE_RECEIVER          = 9,    //!< Configure FM Receiver
   _FTM_FM_RX_SET_MUTE_MODE               = 10,   //!< Set FM Receiver Mute Mode
   _FTM_FM_RX_SET_STEREO_MODE             = 11,   //!< Set FM Receiver Stereo Mode
   _FTM_FM_RX_SET_STATION                 = 12,   //!< Tune FM Receiver
   _FTM_FM_RX_SET_SIGNAL_THRESHOLD        = 14,   //!< Set the threshold that the FM driver uses to determine which stations have service available
   _FTM_FM_RX_GET_STATION_PARAMETERS      = 15,   //!< Get FM Receiver Parameters
   _FTM_FM_RX_GET_RDS_PS                  = 17,   //!< Get FM RDS Program Service
   _FTM_FM_RX_GET_RDS_RT                  = 18,   //!< Get FM RDS Radio Text
   _FTM_FM_RX_SEARCH_STATIONS             = 20,   //!< Initiates basic seek and scan operations
   _FTM_FM_RX_SEARCH_RDS_STATIONS         = 21,   //!< Initiates RDS based seek and scan operations.
   _FTM_FM_RX_SEARCH_STATIONS_LIST        = 22,   //!< Initiates station list search operations.
   _FTM_FM_RX_CANCEL_SEARCH               = 23,   //!< This function cancels any ongoing search operation (including seek, scan, and searchlist)
   _FTM_FM_RX_RDS_GROUP_OPTIONS           = 24,   //!< Set FM Receiver RDS Group Options
   _FTM_FM_RX_RDS_GROUP_PROC_OPTIONS      = 25,   //!< This function enables or disables RDS/RBDS group processing features.
   _FTM_FM_TX_ENABLE_TRANSMITTER          = 33,   //!< Enable FM Transmitter
   _FTM_FM_TX_DISABLE_TRANSMITTER         = 34,   //!< Disable FM Transmitter
   _FTM_FM_TX_CONFIGURE_TRANSMITTER       = 35,   //!< Configure FM Transmitter
   _FTM_FM_TX_SET_STATION                 = 37,   //!< Tune FM Transmitter
   _FTM_FM_TX_TX_RDS_GROUPS               = 42,   //!< Set FM Tx RDS Groups
   _FTM_FM_TX_TX_CONT_RDS_GROUPS          = 43,   //!< Set FM Tx Continuous RDS Groups
   _FTM_FM_TX_TX_RDS_CTRL                 = 44,   //!< Set FM Tx RDS Control
   _FTM_FM_TX_GET_RDS_GROUP_BUF_SIZE      = 45,   //!< Get FM Tx RDS Group Buffer Size
   _FTM_FM_RX_GET_SIGNAL_THRESHOLD        = 46,   //!< Get the threshold that the FM driver uses to determine which stations have service available
   _FTM_FM_BUS_WRITE                      = 47,   //!< FM I2C Write
   _FTM_FM_BUS_READ                       = 48,   //!< FM I2C Read
   _FTM_FM_NOTIFY_WAN                     = 49,   //!< FM Notify WWAN
   _FTM_FM_NOTIFY_FM                      = 50,   //!< FM Notify FM
   _FTM_FM_ROUTE_AUDIO                    = 52,   //!< Set FM Audio Route
   _FTM_FM_RX_SET_AF_THRESHOLD            = 53,   //!< Set Alternate Frequency Threshold
   _FTM_FM_RX_SET_RSSI_CHECK_TIMER        = 54,   //!< Set RSSI Check Timer
   _FTM_FM_RX_SET_RDS_PI_TIMER            = 55,   //!< Set RDS PI Timer
   _FTM_FM_RX_GET_AF_THRESHOLD            = 56,   //!< Get Alternate Frequency Threshold
   _FTM_FM_RX_GET_RSSI_CHECK_TIMER        = 57,   //!< Get RSSI Check Timer
   _FTM_FM_RX_GET_RDS_PI_TIMER            = 58,   //!< Get RDS PI Timer

   _FTM_FM_RX_SET_HLSI                    = 100,  //!< Set High side / Low side injection
   _FTM_FM_RX_SET_SOFTMUTE                = 101,  //!< Set Soft Mute
   _FTM_FM_RX_SET_ANTENNA                 = 102,  //!< Select Antenna
   _FTM_FM_RX_ENABLE_NOTCH                = 103,  //!< Enable/disable low/high pass notch filter
   _FTM_FM_RX_READ_RDS_GROUP_COUNTERS     = 104,  //!< Read RDS Group Counters
   _FTM_FM_TX_SET_INTERNAL_TONE           = 105,  //!< Select internal audio tones for modulation of FM transmitter
   _FTM_FM_SSBI_PEEK                      = 106,  //!< Read  FM Iris (SSBI) register
   _FTM_FM_SSBI_POKE                      = 107,  //!< Write FM Iris (SSBI) register
   _FTM_FM_RIVA_PEEK                      = 108,  //!< Read  FM Riva register
   _FTM_FM_RIVA_POKE                      = 109,  //!< Write FM Riva register
   _FTM_FM_GET_PIN_CONNECTIVITY           = 110,  //!< Get Pin Connectivity
   _FTM_FM_RX_ENABLE_AUDIO                = 111,  //!< Enable FM Audio
   _FTM_FM_RX_DISABLE_AUDIO               = 112,  //!< Disable FM Audio
   _FTM_FM_RX_SET_AUDIO_VOLUME            = 113,   //!< Set FM Audio Volume
   _FTM_FM_RX_READ_RDS_GROUP_COUNTERS_EXT = 114,  //!< Read RDS Group Counters Extension
   _FTM_FM_RX_SET_GET_RESET_AGC           = 115   //!< Set Get Reset AGC
} FTM_FM_Command_ID_Enum;

/**
FM audio destination options
*/
typedef enum
{
   FM_RX_AUDIO_TO_HEADSET = 0,       //!<'  Route FM Rx audio to headset
   FM_RX_AUDIO_TO_SPEAKER  = 1       //!<'  Route FM Rx audio to speaker
} FTM_FM_Audio_Destiniation_Enum;

/**
FM high-side/low-side injection options
*/
typedef enum
{
   FM_HLSI_AUTO     = 0,        //!<'  Automatically select High-side/Low-side injection
   FM_HLSI_LOWSIDE  = 1,        //!<'  Force Low-side injection
   FM_HLSI_HIGHSIDE = 2         //!<'  Force High-side injection
} FTM_FM_Hlsi_Enum;

/**
FM Soft Mute enable/disable options
*/
typedef enum
{
   FM_RX_SOFTMUTE_DISABLED  = 0,        //!<'  Soft Mute feature is disabled.
   FM_RX_SOFTMUTE_ENABLED   = 1         //!<'  Soft Mute feature is enabled.
} FTM_FM_SoftMute_Enum;

/**
FM Antenna selection options
*/
typedef enum
{
   FM_ANTENNA_WIRED_HEADSET = 0,        //!<'  Force selection of wired headset FM antenna.
   FM_ANTENNA_PWB           = 1         //!<'  Force selection of PWB FM antenna.
} FTM_FM_Antenna_Enum;

/**
FM Notch Filter options. These filters improve concurrent operation with other radios
*/
typedef enum
{
   FM_DISABLE_NOTCH_FILTERS         = 0,    //!<'  Do not enable either Notch Filter
   FM_ENABLE_LOW_PASS_NOTCH_FILTER  = 1,    //!<'  Enable Low Pass Notch Filter
   FM_ENABLE_HIGH_PASS_NOTCH_FILTER = 2     //!<'  Enable High Pass Notch Filter
} FTM_FM_NotchFilter_Enum;

/**
FM TX Audio Tone options. These audio waveforms are used to modulate FM TX for testing
*/
typedef enum
{
   FM_TX_AUDIO_TONE_NOTONE              = 0,    //!<'
   FM_TX_AUDIO_TONE_1KHZ_0DBFS_LR       = 1,    //!<'  1 kHz tone @ 0 dBFS applied equally to Left & Right
   FM_TX_AUDIO_TONE_1KHZ_0DBFS_LEFT     = 2,    //!<'  1 kHz tone @ 0 dBFS applied to Left only
   FM_TX_AUDIO_TONE_1KHZ_0DBFS_RIGHT    = 3,    //!<'  1 kHz tone @ 0 dBFS applied to Right only
   FM_TX_AUDIO_TONE_1KHZ_N18DBFS_LR     = 4,    //!<'  1 kHz tone @ -18 dBFS applied equally to Left & Right
   FM_TX_AUDIO_TONE_15KHZ_N18DBFS_LR    = 5,    //!<' 15 kHz tone @ -18 dBFS applied equally to Left & Right
} FTM_FM_TxAudioTone_Enum;

typedef enum
{
   FM_RX   = 0, //!<'  The current FM Rx/Tx mode is RX
   FM_TX    = 1     //!<'  The current FM Rx/Tx mode is TX
} FTM_FM_RxOrTx_Enum;

/**
FM band types.  These types defines the FM band minimum and maximum frequencies in the FM band.
*/
typedef enum
{
   FM_US_EUROPE_BAND      = 0,      //!<'  US/Europe FM band (87.5Mhz <-> 108MHz)
   FM_JAPAN_STANDARD_BAND = 1,      //!<'  Japan Standard Band (76Mhz <-> 90MHz)
   FM_JAPAN_WIDE_BAND     = 2,      //!<'  Japan Wide Band (76Mhz <-> 108MHz)
   FM_USER_DEFINED_BAND   = 3       //!<'  User defined band ( x Mhz <-> y Mhz where x < y and x >= 76 Mhz and y <= 108 Mhz)
} FTM_FM_BandLimits_Enum;

/**
Pre-emphasis/De-emphasis filter time constant
*/
typedef enum
{
   FM_DE_EMP75 = 0,    //!<'  This is the pre-emphasis/de-emphasis timing typically used in the United States and Japan.
   FM_DE_EMP50 = 1      //!<'  This is the pre-emphasis/de-emphasis timing typically used outside of the United states and Japan.
} FTM_FM_Emphasis_Enum;

/**
FM Channel Spacing.  This value typically varies from one geographic region to another.
*/
typedef enum
{
   FM_CHSPACE_200_KHZ     = 0,
   FM_CHSPACE_100_KHZ     = 1,
   FM_CHSPACE_50_KHZ      = 2
} FTM_FM_ChanSpacing_Enum;

/**
RDS/RBDS settings. These settings determine whether the FM
driver should operate in RDS mode, RBDS mode, or neither.
*/
typedef enum
{
   FM_RDS_STD_RBDS = 0, //!<'  RBDS mode (Typically used in the United States).
   FM_RDS_STD_RDS  = 1, //!<'  RDS mode (Typically used outside of the United States).
   FM_RDS_STD_NONE = 2      //!<'  No RDS/RBDS decoding.
} FTM_FM_RdsStd_Enum;

/**
Signal threshold levels. These settings describe the different signal thresholds
offered by the FM driver. The use of these levels will determine what quality of
stations will be found during a search or Alternative Frequency jump.
Additionally, this same level is used for determining at what threshold will a
Service Available event will be generated.
*/
typedef enum
{
   FM_RX_SIGNAL_THRESHOLD_VERY_WEAK    = 0,  //!<' FM driver will consider stations with a very weak signal level to be acceptable.
   FM_RX_SIGNAL_THRESHOLD_WEAK         = 1,  //!<' FM driver will consider stations with a relatively weak signal level to be acceptable.
   FM_RX_SIGNAL_THRESHOLD_STRONG       = 2,  //!<' FM driver will consider stations with a relatively strong signal level to be acceptable.
   FM_RX_SIGNAL_THRESHOLD_VERY_STRONG  = 3    //!<' FM driver will consider stations with a very strong signal level to be acceptable.
} FTM_FM_RxSignalThreshold_Enum;

/**
Search Modes
These are different search modes offered by the FM driver
*/
typedef enum
{
   FM_RX_SRCH_MODE_SEEK = 0,    //!<'  FM driver will tune to the next station that meets a signal level requirement
   FM_RX_SRCH_MODE_SCAN = 1     //!<'  FM driver will tune to all stations that meet a signal level requirement
} FTM_FM_RxSearchMode_Enum;

/**
Search Dwell Times
This describes how long, in seconds, the FM driver will stay tuned to a station during a scan.
*/
typedef enum
{
   FM_RX_DWELL_PERIOD_0S    = 0,    //!<'  FM driver will remain tuned to the a station for 1 second  during a scan
   FM_RX_DWELL_PERIOD_1S    = 1,    //!<'  FM driver will remain tuned to the a station for 1 second  during a scan
   FM_RX_DWELL_PERIOD_2S    = 2,    //!<'  FM driver will remain tuned to the a station for 2 seconds during a scan
   FM_RX_DWELL_PERIOD_3S    = 3,    //!<'  FM driver will remain tuned to the a station for 3 seconds during a scan
   FM_RX_DWELL_PERIOD_4S    = 4,    //!<'  FM driver will remain tuned to the a station for 4 seconds during a scan
   FM_RX_DWELL_PERIOD_5S    = 5,    //!<'  FM driver will remain tuned to the a station for 5 seconds during a scan
   FM_RX_DWELL_PERIOD_6S    = 6,    //!<'  FM driver will remain tuned to the a station for 6 seconds during a scan
   FM_RX_DWELL_PERIOD_7S    = 7     //!<'  FM driver will remain tuned to the a station for 7 seconds during a scan
} FTM_FM_RxSearchDwellTime_Enum;

/**
Search Direction
This decribes whether searches will increment or decrement frequencies while searching the band
*/
typedef enum
{
   FM_RX_SEARCHDIR_UP       = 0,    //!<'  Each frequency searched will be greater than the previous frequency, except when wrapping around the band
   FM_RX_SEARCHDIR_DOWN = 1     //!<'  Each frequency searched will be less than the previous frequency, except when wrapping around the band
} FTM_FM_RxSearchDir_Enum;

/**
User defined FM band range structure. These settings are used to describe a user defined FM band.
*/
typedef struct
{
   unsigned long lowerLimit;    //!<'  User defined FM band start (lower limit).
   unsigned long upperLimit;    //!<'  User defined FM band end (high limit).
} FTM_FM_BandRange_Struct;

/**
FM Radio Settings structure. These settings typically differ from one geographic region to another
*/
typedef struct
{
   FTM_FM_BandLimits_Enum   radioBand;      //!<'  The FM band range settings.
   FTM_FM_Emphasis_Enum     emphasis;       //!<'  The Pre-emphasis/De-emphasis timing setting.
   FTM_FM_ChanSpacing_Enum  chSpacing;      //!<'  The FM channel spacing settings.
   FTM_FM_RdsStd_Enum       rdsStd;     //!<'  The FM RDS/RBDS settings.
   FTM_FM_BandRange_Struct  bandRange;      //!<'  The user define FM band settings.
} FTM_FM_RadioCfg_Struct;

/**
This type determines which audio input/output paths on the FM core are enabled/disabled.
*/
typedef enum
{
   FM_API_AUDIO_OFF                 = 0,    //!<'  Audio to/from the FM core disabled.
   FM_API_AUDIO_OUT_ANALOG              = 1,    //!<'  Analog audio from the FM core enabled.
   FM_API_AUDIO_OUT_DIGITAL_M           = 2,    //!<'  Digital audio from the FM core enabled (FM core is the master).
   FM_API_AUDIO_OUT_DIGITAL_S           = 3,    //!<'  Digital audio from the FM core enabled (FM core is the slave).
   FM_API_AUDIO_OUT_ANALOG_DIGITAL_M    = 4,    //!<'  Analog and digital audio from the FM core enabled (FM core is the master).
   FM_API_AUDIO_OUT_ANALOG_DIGITAL_S    = 5,    //!<'  Analog and digital audio from the FM core enabled (FM core is the slave).
   FM_API_AUDIO_IN_DIGITAL_M            = 6,    //!<'  FM core digital input enabled (FM core is the master).
   FM_API_AUDIO_IN_DIGITAL_S            = 7,    //!<'  FM core digital input enabled (FM core is the slave).
   FM_API_AUDIO_MAX                 = 8     //!<'  Maximum possible FM audio paths.
} FTM_FM_AudioRoute_Enum;

/**
FM mute mode setting.  This value is used to mute or unmute
audio from the FM device.  Both the left and right audio
channels can be muted/unmuted independently.
*/
typedef enum
{
   FM_RX_NOMUTE     = 0,    //!<'  Unmute both audio channels
   FM_RX_MUTELEFT   = 1,    //!<'  Mute only the left audio channel
   FM_RX_MUTERIGHT  = 2,    //!<'  Mute only the right audio channel
   FM_RX_MUTEBOTH   = 3     //!<'  Mute both audio channels
} FTM_FM_RxMute_Enum;

/**
FM Mono/Stereo mode setting.  This value is allow mono/stereo mixing or to force mono only reception.
*/
typedef enum
{
   FM_RX_AUTO_MONO_STEREO_MODE  = 0,    //!<'  Both mono and stereo reception is possible;  The FM hardware will transition to stereo when possible.
   FM_RX_FORCE_MONO_ONLY_MODE   = 1 //!<'  Force mono only reception.
} FTM_FM_RxStereoMonoMode_Enum;

/**
FM driver operating mode.  These modes allow the client to
put the FM driver into and out of low power mode. Low power
mode should be used when only FM audio is required.  All
other functionality may be disabled while in low power mode.
*/
//typedef enum
//{
//  FM_RX_NORMAL_MODE       = 0,    //!<'  FM driver in normal operating mode; All normal functionality should be possible.
//  FM_RX_LOW_POWER_MODE    = 1     //!<'  FM driver in limited operating mode; Only FM audio should be possible.
//} FTM_FM_RxPwrMode_Enum;

typedef struct
{
   byte threshold;
} RssiThreshold;

typedef struct
{
   dword    frequency;
   byte serviceAvailability;
   byte rssi;
   byte stereoProgram;
   byte rdsSyncStatus;
   byte muteMode;
} RxSetStation;

//! Definition of log code for the FM Radio Log Messages
#define LOG_FM_RADIO    0x14CC

typedef struct
{
   byte b[256];
} FMBytes;
/*===========================================================================*/
/**
Structure for interpretting log code 0x14CC, FM Log Message

*/
/*===========================================================================*/
typedef struct
{
   byte EventName;
   byte EventResult;
   union
   {
      RssiThreshold rssi;
      RxSetStation  rsSS;
      FMBytes b;
   };
} FM_LogMessage;

#define FM_RADIO_LOG_MAX_LOGS 256
/**
This buffer stores the FM FTM logs
*/
typedef struct
{
   FM_LogMessage msg[FM_RADIO_LOG_MAX_LOGS];            //!<' Array of FTM logs

   unsigned short iNumFMRadioLogs;                                      //!<' Number of valid Bluetooth FTM logs in aBluetooth_FTM_Logs

   unsigned char  bBufferFull;                                                  //!<' 1 indicates the internal buffer is full. Bluetooth FTM logs may have been discarded.  0 indicates the buffer is not full
} FM_Logs;

/**
FM Command status. This status is returned for all indirect commands.
*/
typedef enum
{
   FM_CMD_PENDING = 0,          //!<'  Command is pending completion.
   FM_CMD_SUCCESS,              //!<'  Command successfully completed.
   FM_CMD_NO_RESOURCES,     //!<'  No resources to execute command, try again later.
   FM_CMD_INVALID_PARAM,        //!<'  Command contains invalid parameters.
   FM_CMD_DISALLOWED,           //!<'  Command is currently disallowed.
   FM_CMD_UNRECOGNIZED_CMD, //!<'  Command unsupported.
   FM_CMD_FAILURE               //!<'  General failure condition.
} FTM_FM_CmdStatus_Enum;

/**
FM event result.
*/
typedef enum
{
   FM_EV_SUCCESS  = 0,          //!<'  Event indicates success.
   FM_EV_FAILURE  = 1,          //!<'  Event is a response to a command that failed
   FM_EV_CMD_DISALLOWED = 2,    //!<'  Event is a response to a command that was disallowed.
   FM_EV_CMD_INVALID_PARAM = 3  //!<'  Event is a response to a command that contained an invalid parameter.
} FTM_FM_EvResult_Enum;

/**
FM Receiver event names
*/
typedef enum
{
   FM_RX_EV_ENABLE_RECEIVER         = 0,
   FM_RX_EV_DISABLE_RECEIVER            = 1,
   FM_RX_EV_CFG_RECEIVER                = 2,
   FM_RX_EV_MUTE_MODE_SET               = 3,
   FM_RX_EV_STEREO_MODE_SET         = 4,
   FM_RX_EV_RADIO_STATION_SET           = 5,
   FM_RX_EV_PWR_MODE_SET                = 6,
   FM_RX_EV_SET_SIGNAL_THRESHOLD        = 7,
   FM_RX_EV_RADIO_TUNE_STATUS           = 8,
   FM_RX_EV_STATION_PARAMETERS          = 9,
   FM_RX_EV_RDS_LOCK_STATUS         = 10,   // 0x0A
   FM_RX_EV_STEREO_STATUS               = 11,   // 0x0B
   FM_RX_EV_SERVICE_AVAILABLE           = 12,   // 0x0C
   FM_RX_EV_GET_SIGNAL_THRESHOLD        = 13,   // 0x0D
   FM_RX_EV_SEARCH_IN_PROGRESS          = 14,   // 0x0E
   FM_RX_EV_SEARCH_RDS_IN_PROGRESS      = 15,   // 0x0F
   FM_RX_EV_SEARCH_LIST_IN_PROGRESS = 16,   // 0x10
   FM_RX_EV_SEARCH_COMPLETE         = 17,   // 0x11
   FM_RX_EV_SEARCH_RDS_COMPLETE     = 18,   // 0x12
   FM_RX_EV_SEARCH_LIST_COMPLETE        = 19,   // 0x13
   FM_RX_EV_SEARCH_CANCELLED            = 20,   // 0x14
   FM_RX_EV_RDS_GROUP_DATA              = 21,   // 0x15
   FM_RX_EV_RDS_PS_INFO             = 22,   // 0x16
   FM_RX_EV_RDS_RT_INFO             = 23,   // 0x17
   FM_RX_EV_RDS_AF_INFO             = 24,   // 0x18
   FM_RX_EV_RDS_PI_MATCH_AVAILABLE      = 25,   // 0x19
   FM_RX_EV_RDS_GROUP_OPTIONS_SET       = 26,   // 0x20
   FM_RX_EV_RDS_PROC_REG_DONE           = 27,   // 0x21
   FM_RX_EV_RDS_PI_MATCH_REG_DONE       = 28,   // 0x22
   FM_TX_EV_ENABLE_TRANSMITTER          = 100,  // 0x64
   FM_TX_EV_DISABLE_TRANSMITTER     = 101,  // 0x65
   FM_TX_EV_CFG_TRANSMITTER         = 102,  // 0x66
   FM_TX_EV_RADIO_TUNE_STATUS           = 104,  // 0x68
   FM_TX_EV_TX_RDS_GROUPS_COMPLETE      = 110,  // 0x6E
   FM_TX_EV_TX_CONT_RDS_GROUPS_COMPLETE= 111,   // 0x6F
   FM_TX_EV_TX_RDS_GROUP_CTRL_COMPLETE  = 112,  // 0x70
} FTM_FM_Event_Enum;

typedef enum
{
   FM_RX_SERVICE_NOT_AVAILABLE  = 0,    //!<'  No stations were found in the FM band.
   FM_RX_SERVICE_AVAILABLE      = 1 //!<'  At least one station was found in the FM band.
} FTM_FM_RxServAvble_Enum;

typedef enum
{
   FM_RX_MONO_PROGRAM     = 0,  //!<'  The currently received audio is mono
   FM_RX_STEREO_PROGRAM   = 1   //!<'  The currently received audio is stereo
} FTM_FM_RxStereoProgram_Enum;

typedef enum
{
   FM_RX_NO_RDS_SYNC = 0,   //!<'  No RDS/RBDS decoding possible.
   FM_RX_RDS_SYNC    = 1    //!<'  RDS/RBDS decoding.
} FTM_FM_RxRdsSync_Enum;

typedef struct
{
   dword                            Frequency;
   FTM_FM_RxServAvble_Enum          ServiceAvailability;
   byte                         Rssi;
   FTM_FM_RxStereoProgram_Enum      StereoProgram;
   FTM_FM_RxRdsSync_Enum            RxRdsSync;
   FTM_FM_RxStereoMonoMode_Enum MuteMode;
} FTM_FM_RxSetStation_Struct;

/**
RDS/RBDS Program Identification type.
*/
typedef word FmPrgmIdType;

/**
RDS/RBDS Program Type type.
*/
typedef byte FmPrgmType;

/**
Program Service Info event structure.
*/
typedef struct
{
   byte         psNum;              // The number of Program Service strings (9 characters each) contained within pCmptPSText
   FmPrgmIdType piPrgmId;           // The RDS/RBDS Program Identification (PI) being broadcasted (Example: 0x51CE)
   FmPrgmType       ptyPrgmType;        // The RDS/RBDS Program Type being broadcasted (Example: 0 -> 'News').
   boolean      taPrgmCodeFlag;         // The RDS/RBDS Traffic Program (TP) code.
   boolean      taAnnouncementCodeFlag; // The RDS/RBDS Traffic announcement (TA) code.
   boolean      msSwitchCodeFlag;       // The RDS/RBDS Music-speech switch (M/S) code.
   boolean      decIdCtrlCodeFlag;      // The RDS/RBDS Decoder-identification (DI) control code.
   const char*  pCmptPSText;            // An array of NULL terminated Program Service strings Each Program
   // Service string will be 8 characters in length and will include
   // NULL termination (9 characters total).
   // Refer to psNum for the number of strings contained in this buffer.
} FTM_FM_RxRdsPSSummaryEvStruct;

/**
RadioText Info event structure.
*/
typedef struct
{
   byte                length;          // The length of the RadioText string contained in pRadioText
   FmPrgmIdType     piPrgmId;       // The RDS/RBDS Program Identification (PI) being broadcasted (Example: 0x51CE).
   FmPrgmType           ptyPrgmType;    // The RDS/RBDS Program Type being broadcasted (Example: 0 -> 'News').
   boolean             taPrgmCodeFlag;  // The RDS/RBDS Traffic announcement (TA) code.
   boolean             textAbFlag;      // The RDS/RBDS Text A/B flag.
   const char*         pRadioText;      // A single NULL terminated string which contains the RadioText string.
} FTM_FM_RxRdsRTSummaryEvStruct;

/**
Alternative Frequency Info event structure.
*/
typedef struct
{
   dword               radioFreq;       // The currently tuned frequency in kHz (Example: 96500 -> 96.5Mhz)
   dword               noOfAFInList;    // The number of Alternative Frequencies contained within pAFFreqList
   FmPrgmIdType     piPrgmId;       // The RDS/RBDS Program Identification (PI) being broadcasted (Example: 0x51CE).
   const dword*     pAFFreqList;    // A pointer to the RDS/RBDS Alternative Frequencies (in kHz).
} FTM_FM_RxRdsAFSummaryEvStruct;

typedef enum
{
   FTM_FM_RX_RDS_CHANGE_FILTER_DISABLED = 0,
   FTM_FM_RX_RDS_CHANGE_FILTER_ENABLED = 1
} FTM_FM_RxRdsChangeFilter_Enum;

typedef struct
{
   dword    mask;
   dword    groupBufferSize;
   //FTM_FM_RxRdsChangeFilter_Enum  ChangeFilterEnabled;
   boolean  ChangeFilterEnabled;
} FTM_FM_RxRdsGroupOptions_Struct;

#define FM_RX_RDS_WORDS_PER_GROUP       4   //!<' 4 16-bit words per RDS group
#define FM_MAX_RX_RDS_GROUPS            21  //!<' Max # of FM RDS groups

typedef enum
{
   FTM_TX_RDS_GROUP_PAUSE = 0,
   FTM_TX_RDS_GROUP_CLEAR = 1,
   FTM_TX_RDS_GROUP_RESUME = 2
}
FTM_FM_TxRdsGroupControl_Enum;

/**
FM Radio Status structure for Aynch log message data
*/
typedef struct
{
   /**
   Status array, indexed by log_FTM2_WCDMA_BER_log_id_enum

   Will be set to true if a log message was received for that log type
   */
   byte bHasUpdated[ 48 ];

   word                 iFTM_LOG_ID;
   byte                 iEventName;
   FTM_FM_EvResult_Enum iEventResult;

   FTM_FM_RxOrTx_Enum       RxOrTx;

   //
   //   Related to Enable Receiver, Configure Receiver, Enable Transmitter, Configure Transmitter event log messages
   //
   FTM_FM_RadioCfg_Struct               RadioCfg;

   //
   //   Related to Set Rx Station event log message
   //
   FTM_FM_RxSetStation_Struct           RxStation;

   //
   //   Related to Set Rx Rds Group Options event log message
   //
   FTM_FM_RxRdsGroupOptions_Struct      RxRdsGroupOptions;
   word RxRdsGroupBuffer[FM_MAX_RX_RDS_GROUPS][FM_RX_RDS_WORDS_PER_GROUP];

   //
   //   Related to Set Tx Station event log message
   //
   dword                                TxFrequency;

   //
   //   Related to Set Tx RDS Group Control event log message
   //
   FTM_FM_TxRdsGroupControl_Enum        TxRdsGroupControl;
} FTM_FM_Status_Struct;

//! Maximum size of a QMSL Text Log
#define QLIB_MAX_TEXT_LOG_SIZE 12295

/**
Definition of the LOG code #id that will be used to indicate that a certain log is actually
a QMSL Text log, not a normal phone log.

The idea is that text messages from the library will be sent the the QMSL client using the
asynchronous log mechanism.  Log messages will be generated of command code #16, which is
defined in the parimary ICD's for CDMA and WCDMA.

*/
#define QLIB_TEXT_LOG_CODE 0xFFFF

/**
Structure of the QMSL text messages, which are sent through the async logging interface
*/
typedef struct
{
   /**
   Log level is a 16-bit field that indicates what level this log code is.

   The levels are defined in the pre-processor constants list that includes
   LOG_IO and LOG_FN.

   #define LOG_IO           0x0001  // data IO (data bytes)
   #define LOG_FN           0x0002  // function calls with parameters

   */
   word iLogLevel;
   word iReserved;                                  //!<'  Reserved for future use
   long iTimer_ms;                                  //!<'  # of milliseconds since the log was started
   byte  sLogText[ QLIB_MAX_TEXT_LOG_SIZE ];        //!<'  The text string
} QMSL_TextLog_struct;

/******************************************************************************
Diagnostic - phone version info
*******************************************************************************/

/*============================================================================

PACKET   diag_verno_rsp_type

ID       DIAG_VERNO_F

PURPOSE  Sent by the DMSS, contains version and date information

============================================================================*/
#define QLIB_VERNO_DATE_STRLEN 11               //!<' Length of date field (bytes)
#define QLIB_VERNO_TIME_STRLEN  8               //!<' Length of time field (bytes)
#define QLIB_VERNO_DIR_STRLEN   8               //!<' Length of version directory (bytes)

/*===========================================================================*/
/**
\brief Version information structure.

To be used with the QLIB_DIAG_VERNO_F command.
*/
/*===========================================================================*/
struct QLIB_PhoneResp_Version
{
   byte cmd_code;                              //!<' Command code
   char comp_date[ QLIB_VERNO_DATE_STRLEN ];   //!<' Compile date Jun 11 1991
   char comp_time[ QLIB_VERNO_TIME_STRLEN ];   //!<' Compile time hh:mm:ss
   char rel_date [ QLIB_VERNO_DATE_STRLEN ];   //!<' Release date
   char rel_time [ QLIB_VERNO_TIME_STRLEN ];   //!<' Release time
   char ver_dir  [ QLIB_VERNO_DIR_STRLEN ];    //!<' Version directory
   byte scm;                                   //!<' Station Class Mark
   byte mob_cai_rev;                           //!<' CAI rev
   byte mob_model;                             //!<' Mobile Model
   word mob_firm_rev;                          //!<' Firmware Rev
   byte slot_cycle_index;                      //!<' Slot Cycle Index
   byte voc_maj;                               //!<' Vocoder major version
   byte voc_min;                                  //!<' Vocoder minor version
};

/******************************************************************************
Diagnostic - reading embedded error information
*******************************************************************************/

/*===========================================================================*/
/**
\brief Error record information structure.

To be used with the QLIB_DIAG_ERR_READ_F command.
*/
/*===========================================================================*/
typedef struct
{
   /**
   Error address.  Index (0-19) of this error record; sequential
   */
   byte iAddress;

   /**
   Error count
   Number of times this error has been recorded. If zero, this error
   record is empty; this saturates at 255
   */
   byte iCount;

   /**
   Root name of file.
   The root name of the file where the error was detected, such as
   mobile for mobile.c. Longfile names are truncated to the first
   eight characters
   */
   byte sFileName[ 8 ];

   /**
   Line number within file.
   The line number within FILE_NAME where the error was detected
   */
   word iLineNum;

   /**
   Error fatal indicator
   If nonzero, the error was fatal. If zero, the error was nonfatal
   */
   byte bFatal;
} QLIB_DIAG_Err_Read_Element;

#define QLIB_NUM_ERR_READ_ELEMENTS 20

/*===========================================================================*/
/**
\brief Error record information structure.

To be used with the QLIB_DIAG_ERR_READ_F command.
*/
/*===========================================================================*/
typedef struct
{
   /**
   Error count.  The number of ERR_RECORDS that have valid error data.
   */
   word iErrorCount;

   /**
   Errors ignored count
   Number of errors ignored since last DMSS reset. This happens when another
   error record cannot be allocated, or the COUNT for a given error is saturated.
   ERR_RECORDS = 20 of the following five records
   */
   word iErrorIgnored;

   //! Array of error read elements
   QLIB_DIAG_Err_Read_Element aErrorRecords[ QLIB_NUM_ERR_READ_ELEMENTS ];
} QLIB_DIAG_Err_Read;

/******************************************************************************
Diagnostic - General command defines
*******************************************************************************/

/*===========================================================================*/
/**
PACKET   diag_control_req_type

ID       DIAG_CONTROL_F

PURPOSE  Sent by DM to direct the DMSS to go offline or reset
These are defined in services/cm/cmdiag.h

RESPONSE DMSS changes mode or resets
*/
/*===========================================================================*/
typedef enum
{
   MODE_OFFLINE_A_F = 0,    //!<' Go to offline analog
   MODE_OFFLINE_D_F = 1,    //!<' Go to offline digital
   MODE_RESET_F = 2,        //!<' Reset. Only exit from offline
   MODE_FTM_F = 3,          //!<' FTM mode
   MODE_ONLINE_F = 4,       //!<' Go to Online
   MODE_LPM_F = 5,          //!<' Low Power Mode (if supported)
   MODE_POWER_OFF_F = 6,    //!<' Power off (if supported)
   MODE_MAX_F = 7           //!<' Last (and invalid) mode enum value
} mode_enum_type;

/*===========================================================================*/
/**
enum nv_stat_enum_type

\brief States defined as possible return values for an NV function.

This definition was taken from NV.H and should be resync'd if the list in that
file changes.
*/
/*===========================================================================*/
typedef enum
{
   NV_DONE_S,          //!<' Request completed okay
   NV_BUSY_S,          //!<' Request is queued
   NV_BADCMD_S,        //!<' Unrecognizable command field
   NV_FULL_S,          //!<' The NVM is full
   NV_FAIL_S,          //!<' Command failed, reason other than NVM was full
   NV_NOTACTIVE_S,     //!<' Variable was not active
   NV_BADPARM_S,       //!<' Bad parameter in command block
   NV_READONLY_S,      //!<' Parameter is write-protected and thus read only
   NV_BADTG_S,         //!<' Item not valid for Target
   NV_NOMEM_S,         //!<' free memory exhausted
   NV_NOTALLOC_S,      //!<' address is not a valid allocation
   NV_STAT_ENUM_PAD = 0x7FFF     //!<' Pad to 16 bits on ARM
} nv_stat_enum_type;

/*===========================================================================*/
/**
enum rfnv_read_write_status_enum

\brief States defined as possible return values for an NV function.

QLIB_FTM_RFNV_READ/WRITE APIs FTM error code enum
*/
/*===========================================================================*/
typedef enum
{
   RFCOMMON_RFNV_READ_SUCCESS =  0,
   RFCOMMON_RFNV_READ_FAILED =   1,
   RFCOMMON_RFNV_WRITE_SUCCESS = 2,
   RFCOMMON_RFNV_WRITE_FAILED =  3,
   RFCOMMON_RFNV_INACTIVE     =  4,
   RFCOMMON_NV_INVALID_SIZE =    5,
   RFCOMMON_NV_BAD_OFFSET = 6,
   RFCOMMON_NV_FILE_OPEN_FAIL = 7,
   RFCOMMON_NV_FILE_SEEK_FAIL = 8,
   RFCOMMON_NV_FILE_NOT_FOUND = 9
}  rfnv_read_write_status_enum;
/*===========================================================================*/
/**
Enums for the return values of the command DIAG_STATUS_F

*/
/*===========================================================================*/
typedef enum
{
   DIAG_STATUS_OFFLINE = 0, //!<' OFFLINE Status
   DIAG_STATUS_ONLINE = 1   ,   //!<' ONLINE Status
   DIAG_STATUS_LPM = 2  ,       //!<' Low Power Status
   DIAG_STATUS_UNKNOWN = 99 //!<' Last (and invalid) mode enum value
} diag_status_enum_type;

/*===========================================================================
NV Item enumerations

The NV ID's are not published in QMSL, in order to avoid synchronization
issues with new builds of software.  The enumerations should be taken
from the SERVCIES\NV\NV.H file in the embedded software, which will always
have the correct and up-to-date enumeration ID's for a specific target.
===========================================================================*/

typedef enum
{
   _DIAG_SUBSYS_NV_READ_EXT_F = 0x01,   // Dual SIM item read
   _DIAG_SUBSYS_NV_WRITE_EXT_F = 0x02   // Dual SIM item write
} SubsysNVSubsysCmdCode;

/*===========================================================================*/
/**
enum KeyPressID

\brief Enumeration of key press identifiers

These definitions came from PHONEI.H.  If more key press ID's are added then
the list should be resync'd
*/
/*===========================================================================*/
typedef enum
{
   HS_NONE_K = 0,        //!<'  No more keycodes available
   HS_ON_HOOK_K,         //!<'  phone has gone on-hook
   HS_OFF_HOOK_K,        //!<'  phone has gone off-hook
   HS_RING_VOL_0_K,      //!<'  ringer volume 0 (Keep 0-2 in order)
   HS_RING_VOL_1_K,      //!<'  ringer volume 1 ( and sequential!!)
   HS_RING_VOL_2_K,      //!<'  ringer volume 2
   HS_EAR_UP_K,          //!<'  earpiece up
   HS_EAR_UP_END_K,      //!<'  earpiece up + end pressed
   HS_EAR_DOWN_K,        //!<'  earpiece down
   HS_PF1_K,             //!<'  softkey #1 (left-most)
   HS_PF2_K,             //!<'  softkey #2 (right-most)
   HS_MSG_K,             //!<'  message waiting
   HS_POUND_K = 0x23,    //!<'  '#' key, ASCII '#'
   HS_STAR_K = 0x2A,     //!<'  '*' key, ASCII '*'
   HS_0_K = 0x30,        //!<'  '0' key, ASCII '0'
   HS_1_K = 0x31,        //!<'  '1' key, ASCII '1'
   HS_2_K = 0x32,        //!<'  '2' key, ASCII '2'
   HS_3_K = 0x33,        //!<'  '3' key, ASCII '3'
   HS_4_K = 0x34,        //!<'  '4' key, ASCII '4'
   HS_5_K = 0x35,        //!<'  '5' key, ASCII '5'
   HS_6_K = 0x36,        //!<'  '6' key, ASCII '6'
   HS_7_K = 0x37,        //!<'  '7' key, ASCII '7'
   HS_8_K = 0x38,        //!<'  '8' key, ASCII '8'
   HS_9_K = 0x39,        //!<'  '9' key, ASCII '9'
   HS_SEND_K = 0x50,     //!<'  Send key
   HS_END_K = 0x51,      //!<'  End key or Power key (Based on Target)
   HS_CLR_K = 0x52,      //!<'  Clear key
   HS_STO_K = 0x53,      //!<'  Store key
   HS_UP_K = 0x54,       //!<'  Up-arrow key was pressed
   HS_DOWN_K = 0x55,     //!<'  Down-arrow key was pressed
   HS_MUTE_K = 0x56,     //!<'  Mute Key
   HS_RCL_K = 0x57,      //!<'  Recall key
   HS_SD1_K = 0x58,      //!<'  speed dial #1
   HS_SD2_K = 0x59,      //!<'  speed dial #2
   HS_SD3_K = 0x5A,      //!<'  speed dial #3
   HS_MENU_K = 0x5B,     //!<'  Menu key
   HS_ALPHA_K = 0x5C,    //!<'  Alpha key
   HS_DEC_POUND_K,       //!<'  Decoded # DTMF
   HS_DEC_STAR_K,        //!<'  Decoded * DTMF
   HS_DEC_0_K,           //!<'  Decoded 0 DTMF
   HS_DEC_1_K,           //!<'  Decoded 1 DTMF
   HS_DEC_2_K,           //!<'  Decoded 2 DTMF
   HS_DEC_3_K,           //!<'  Decoded 3 DTMF
   HS_DEC_4_K,           //!<'  Decoded 4 DTMF
   HS_DEC_5_K,           //!<'  Decoded 5 DTMF
   HS_DEC_6_K,           //!<'  Decoded 6 DTMF
   HS_DEC_7_K,           //!<'  Decoded 7 DTMF
   HS_DEC_8_K,           //!<'  Decoded 8 DTMF
   HS_DEC_9_K,           //!<'  Decoded 9 DTMF
   HS_DEC_A_K,           //!<'  Decoded A DTMF
   HS_DEC_B_K,           //!<'  Decoded B DTMF
   HS_DEC_C_K,           //!<'  Decoded C DTMF
   HS_DEC_D_K,           //!<'  Decoded D DTMF
   HS_PWR_ON_K,          //!<'  Power key is switched 'on'
   HS_PWR_OFF_K,         //!<'  Power key is switched 'off'
   HS_PWR_K,             //!<'  Power key
   HS_INFO_K,            //!<'  Info key
   HS_FREE_K,            //!<'  Phone was placed in hands-free cradle
   HS_PHONE_K,           //!<'  Phone was lifted from hands-free cradle
   HS_IGN_OFF_K,         //!<'  Ignition was turned off
   HS_IGN_ON_K,          //!<'  Ignition was turned on
   HS_TMR_ON_K,          //!<'  Power-up timer 'on' pseudo-key
   HS_TMR_OFF_K,         //!<'  Power-up timer 'off' pseudo-key
   HS_BAD_BATT_K,        //!<'  The car battery is failing
   HS_EXT_PWR_ON_K,      //!<'  External power was turned on
   HS_EXT_PWR_OFF_K,     //!<'  External power was turned off
   HS_REDIAL_K,          //!<'  Redial key
   HS_RSSI_K,            //!<'  RSSI key
   HS_HFK_CORD_K,        //!<'  Coil cord carkit
   HS_HFK_NOCORD_K,      //!<'  Non-coil cord carkit
   HS_HEADSET_K,         //!<'  Headset connected
   HS_HEADSET_OFF_K,     //!<'  Headset disconnected
   HS_DEV_UNKNOWN_K,     //!<'  Unknown device ID
   HS_EXT_DEV_K,         //!<'  ONES detector finds external device
   HS_CHARGING_ON_K,     //!<'  Key to note battery charging active
   HS_CHARGING_OFF_K,    //!<'  Key to note battery charging stopped
   HS_LEFT_K,           //!<'  Left soft Key
   HS_RIGHT_K,          //!<'  Right soft Key
   HS_APPLICATION_K,        //!<'  Application key
   HS_RIGHT_SELECT_K,   //!<'  Right hand select key
   HS_LEFT_SELECT_K,        //!<'  Left hand select key
   HS_BROWSER_K,            //!<'  Browser key
   HS_LO_RES_CAMERA_K,  //!<'  Low resolution Camera key
   HS_HI_RES_CAMERA_K,  //!<'  High resolution Camera key
   HS_PTT_K,                //!<'  Push to talk
   HS_RELEASE_K = 0xff   //!<'  Key to note that all keys are up
} KeyPressID;

/*===========================================================================*/
/**
enum KeyPressEvent

\brief Enumeration of key press identifiers

These definitions came from PHONEI.H.  If more key press ID's are added then
the list should be resync'd
*/
/*===========================================================================*/
typedef enum
{
   DIAG_KeyPress_Down       = 1,
   DIAG_KeyPress_Up     = 2,
   DIAG_KeyPress_Unknown    = 3
} KeyPressEventType;

//! Structure for defining a key press event
typedef struct
{
   KeyPressID eKeyID;
   KeyPressEventType eKeyEvent;
} KeyPressEvent;

/******************************************************************************
Diagnostic - Diagnostic Subsystem
*******************************************************************************/

//! Diagnostic drop reset ID, from 80-V1294-10
typedef enum
{
   DIAGDIAG_DROP_COUNT_LOG_APP = 43,      //!<' Logs on the application processor
   DIAGDIAG_DROP_COUNT_EVENT_APP = 45,    //!<' Events on the application processor
   DIAGDIAG_DROP_COUNT_F3_APP = 47,       //!<' F3 messages on the application processor
   DIAGDIAG_DROP_COUNT_DELAY_APP = 70,    //!<' Delayed response messages on the application processor
   DIAGDIAG_DROP_COUNT_LOG_MODEM = 52,    //!<' Logs on the modem processor
   DIAGDIAG_DROP_COUNT_EVENT_MODEM = 54,  //!<' Events on the modem processor
   DIAGDIAG_DROP_COUNT_F3_MODEM = 56,     //!<' F3 messages on the modem processor
   DIAGDIAG_DROP_COUNT_DELAY_MODEM = 80,  //!<' Delayed response messages on the modem processor
   DIAGDIAG_DROP_COUNT_LOG_Q6 = 61,       //!<' Logs on the Hexagon processor
   DIAGDIAG_DROP_COUNT_EVENT_Q6 = 63,     //!<' Events on the Hexagon processor
   DIAGDIAG_DROP_COUNT_F3_Q6 = 65,        //!<' F3 messages on the Hexagon processor
   DIAGDIAG_DROP_COUNT_DELAY_Q6 = 90,     //!<' Delayed response messages on the Hexagon processor
   DIAGDIAG_DROP_COUNT_LOG_RIVA = 5121,   //!<' Logs on the Riva processor
   DIAGDIAG_DROP_COUNT_EVENT_RIVA = 5123, //!<' Events on the Riva processor
   DIAGDIAG_DROP_COUNT_F3_RIVA = 5125,    //!<' F3 messages on the Riva processor
   DIAGDIAG_DROP_COUNT_DELAY_RIVA = 5130  //!<' Delayed response messages on the Riva processor
} DiagnosticDropCountResetId;

//! Diagnostic drop reset ID, from 80-V1294-10
typedef enum
{
   DIAGDIAG_GET_DROP_COUNT_LOG_APP = 44,     //!<' Log drop count on the application processor
   DIAGDIAG_GET_DROP_COUNT_EVENT_APP = 46,   //!<' Event drop count on the application processor
   DIAGDIAG_GET_DROP_COUNT_F3_APP = 48,      //!<' F3 drop count on the application processor
   DIAGDIAG_GET_DROP_COUNT_DELAY_APP = 71,   //!<' Delayed response drop count on the application processor
   DIAGDIAG_GET_ALLOC_COUNT_LOG_APP = 49,    //!<' Log allocation count on the application processor
   DIAGDIAG_GET_ALLOC_COUNT_EVENT_APP = 50,  //!<' Event allocation count on the application processor
   DIAGDIAG_GET_ALLOC_COUNT_F3_APP = 51,     //!<' F3 allocation count on the application processor
   DIAGDIAG_GET_ALLOC_COUNT_DELAY_APP = 72,  //!<' Delayed response allocation count on the application processor
   DIAGDIAG_GET_DROP_COUNT_LOG_MODEM = 53,   //!<' Log drop count on the modem processor
   DIAGDIAG_GET_DROP_COUNT_EVENT_MODEM = 55, //!<' Event drop count on the modem processor
   DIAGDIAG_GET_DROP_COUNT_F3_MODEM = 57,    //!<' F3 drop count on the modem processor
   DIAGDIAG_GET_DROP_COUNT_DELAY_MODEM = 81, //!<' Delayed response drop count on the modem processor
   DIAGDIAG_GET_ALLOC_COUNT_LOG_MODEM = 58,  //!<' Log allocation count on the modem processor
   DIAGDIAG_GET_ALLOC_COUNT_EVENT_MODEM = 59, //!<' Event allocation count on the modem processor
   DIAGDIAG_GET_ALLOC_COUNT_F3_MODEM = 60,   //!<' F3 allocation count on the modem processor
   DIAGDIAG_GET_ALLOC_COUNT_DELAY_MODEM = 82, //!<' Delayed response allocation count on the modem processor
   DIAGDIAG_GET_DROP_COUNT_LOG_Q6 = 62,      //!<' Log drop count on the Hexagon processor
   DIAGDIAG_GET_DROP_COUNT_EVENT_Q6 = 64,    //!<' Event drop count on the Hexagon processor
   DIAGDIAG_GET_DROP_COUNT_F3_Q6 = 66,       //!<' F3 drop count on the Hexagon processor
   DIAGDIAG_GET_DROP_COUNT_DELAY_Q6 = 91,    //!<' Delayed response drop count on the Hexagon processor
   DIAGDIAG_GET_ALLOC_COUNT_LOG_Q6 = 67,     //!<' Log allocation count on the Hexagon processor
   DIAGDIAG_GET_ALLOC_COUNT_EVENT_Q6 = 68    //!<' Event allocation count on the Hexagon processor
} DiagnosticDropCountGetId;

/******************************************************************************
Diagnostic - EFS Subsystem
*******************************************************************************/

/**
EFS sub system commands
*/
typedef enum
{
   _EFS2_DIAG_HELLO = 0,        //!<' Parameter negotiation packet
   _EFS2_DIAG_QUERY = 1,        //!<' Send information about EFS2 params
   _EFS2_DIAG_OPEN      = 2,        //!<' Open a file
   _EFS2_DIAG_CLOSE = 3,        //!<' Close a file
   _EFS2_DIAG_READ      = 4,        //!<' Read a file
   _EFS2_DIAG_WRITE = 5,        //!<' Write a file
   _EFS2_DIAG_SYMLINK   = 6,        //!<' Create a symbolic link
   _EFS2_DIAG_READLINK  = 7,        //!<' Read a symbolic link
   _EFS2_DIAG_UNLINK    = 8,        //!<' Remove a symbolic link or file
   _EFS2_DIAG_MKDIR = 9,        //!<' Create a directory
   _EFS2_DIAG_RMDIR = 10,       //!<' Remove a directory
   _EFS2_DIAG_OPENDIR   = 11,       //!<' Open a directory for reading               */
   _EFS2_DIAG_READDIR   = 12,       //!<' Read a directory                           */
   _EFS2_DIAG_CLOSEDIR  = 13,       //!<' Close an open directory                    */
   _EFS2_DIAG_RENAME    = 14,       //!<' Rename a file or directory                 */
   _EFS2_DIAG_STAT      = 15,       //!<' Obtain information about a named file      */
   _EFS2_DIAG_LSTAT = 16,       //!<' Obtain information about a symbolic link   */
   _EFS2_DIAG_FSTAT = 17,       //!<' Obtain information about a file descriptor */
   _EFS2_DIAG_CHMOD = 18,       //!<' Change file permissions                    */
   _EFS2_DIAG_STATFS    = 19,       //!<' Obtain file system information             */
   _EFS2_DIAG_ACCESS    = 20,       //!<' Check a named file for accessibility       */
   _EFS2_DIAG_NAND_DEV_INFO = 21,   //!<' Get NAND device info */
   _EFS2_DIAG_FACT_IMAGE_START  = 22,   //!<' Start EFS2 data output for Factory Image */
   _EFS2_DIAG_FACT_IMAGE_READ   = 23,   //!<' Get EFS2 data for Factory Image */
   _EFS2_DIAG_FACT_IMAGE_END    = 24,   //!<' End EFS2 data output for Factory Image */
   _EFS2_DIAG_PREP_FACT_IMAGE   = 25,   //!<' Prepare file system for image dump */
   _EFS2_DIAG_PUT_DEPRECATED        = 26,           //!<' Use _EFS2_DIAG_PUT instead
   _EFS2_DIAG_GET_DEPRECATED        = 27,           //!<'_EFS2_DIAG_GET instead
   _EFS2_DIAG_ERROR = 28,           //!<'
   _EFS2_DIAG_EXTENDED_INFO = 29,   //!<' Get Extra information. */
   _EFS2_DIAG_DELTREE   = 37,       //!<' Delete a directory and its content */
   _EFS2_DIAG_PUT       = 38,           //!<' Used to store special item file in EFS2
   _EFS2_DIAG_GET       = 39,           //!<' Used to retrieve a special item file in EFS2
   _EFS2_DIAG_SYNC_NO_WAIT      = 48,   //!<' Syncchronziation fileystem with no wait
   _EFS2_DIAG_GET_SYNC_STATUS   = 49,   //!<' Get status for previous _EFS2_DIAG_SYNC_NO_WAIT command
   _EFS2_DIAG_MAKE_GOLDEN_COPY  = 53    //!<' Make golden copy of modem eFS on eMMC device
} EFS2_CMD_Enum;

/**
Data types of extended EFS information--string or integer
*/
typedef enum
{
   EFS2_EXT_Kind_Int        = 0,    //!<' Extended Information will be returned as an integer
   EFS2_EXT_Kind_String = 1     //!<' ExtendedInformation will be returned as a string
} EFS2_EXT_Kind_Enum;

/**
Currently defined queries. Querying information that is not available
will return an efs2_diag_error_rsp_type packet with the error code set
to FS_DIAG_UNAVAILABLE_INFO. All queries expect 'path' to be set to an
EFS2 path that determines which filesystem the query applies to. The
path must be null terminated.

*/

/**
Types of extended EFS information queries
*/
typedef enum
{
   /**
   Return the flash device name. 'data' is ignored Results in a string.
   */
   EFS2_DIAG_EXT_QUERY_DEVICE_NAME          = 0,

   /**
   Return a field of the device ID. 'data' indicates which ID
   field to return. '0' is always the Maker ID, and '1' begins the
   device-specific ID. The client should always request values
   until the FS_DIAG_UNAVAILABLE_INFO is returned, indicating there
   are no more ID values.
   */
   EFS2_DIAG_EXT_QUERY_DEVICE_ID            = 1,

   /**
   Return the number of blocks in this EFS2 partition. These are
   FLASH blocks (called sectors for NOR). 'data' is ignored.
   */
   EFS2_DIAG_EXT_QUERY_FILESYSTEM_BLOCKS    = 2,

   /**
   Return the total number of blocks in the flash device containing
   this filesystem. 'data' is ignored.
   */
   EFS2_DIAG_EXT_QUERY_TOTAL_BLOCKS     = 3,

   /**
   Return the number of pages per block for this device. This
   query is only valid for devices that have a fixed block size.
   For devices with varying block sizes, the TBD request must be
   used. 'data' is ignored.
   */
   EFS2_DIAG_EXT_QUERY_PAGES_PER_BLOCK      = 4,

   /**
   Return the number of bytes in a single page for this device.
   'data' is ignored'.
   */
   EFS2_DIAG_EXT_QUERY_PAGE_SIZE            = 5,

   /**
   Return the bus width of the flash device used in this
   filesystem. 'data' is ignored.
   */
   EFS2_DIAG_EXT_QUERY_FLASH_BUS_WIDTH      = 6,

   /**
   Return string description of flash type ("NAND", "NOR", etc).
   */
   EFS2_DIAG_EXT_QUERY_FLASH_TYPE           = 7
} EFS2_EXT_QueryType_Enum;

/******************************************************************************
Diagnostic - NV Subsystem
*******************************************************************************/

/**
Multiple NV write Subsystem commands
*/
typedef enum
{
   _DIAG_NV_MNVW_Write = 0
} MNVW_CMD_Enum;

// Maximum payload size for multiple NV write.  Leave 200 bytes margin so that HDLC characters
// can be expand with escape sequences.  This still might not be enough if one NV field has
// numerous 0x7e or 0x7d values
#define DIAG_MNVW_MAX_PAYLOAD_SIZE 1520 - 200

/**
Status types for Multiple NV Write
*/
typedef enum
{
   DIAG_MNVW_Status_OK,             //!<' 0 - Request NV write items completed OK
   DIAG_MNVW_Status_InvalidTotal,       //!<' 1 - Request total item number invalid
   DIAG_MNVW_Status_InvalidLength,      //!<' 2 - Request total item length limit exceeded
   DIAG_MNVW_Status_MismatchLength, //!<' 3 - Request item lengths mismatched with total item length
   DIAG_MNVW_Status_Error               //!<' 4 - Request NV write items failed with ERROR
} MNVW_Status_Enum;

/**
Structure for MNV Diag Command response header
*/
typedef struct
{
   byte  iCMD_Code;
   byte  iSubSysId;
   word iSubSysCmdCode;
   word iNvItemTotal;
   word iNvItemTotalLength;
   word iNvStatusTotal;
   byte iNvItemDataTotal;
} MVNW_Response_Struct;

/**
Structure for individual NV items in the MNV Diag Command response
*/
typedef struct
{
   byte  iNvItemLength;
   word iNvItem;
   byte  iNvItemStatus;
   byte  iNvItemData;
} MVNW_Response_NvItem_Struct;

/**
CNV Subsystem commands
*/
typedef enum
{
   _DIAG_NV_CNV_DIAG_BACKUP_F = 0
} CNV_CMD_Enum;

/**
Structure for Diag  Command version 2 responses
*/
typedef struct
{
   byte  iCMD_Code;
   byte  iSubSysId;
   word iSubSysCmdCode;
   dword  iCommandStatus;
   word iDelayedResponseId;
   word iDelayedResponseCount;
} DIAG_CMD_Ver2_Resp;

/**
For the "command status" result on Diag Version 2 commands.
*/
#define DIAG_V2_SUCCESS 0

/**
For multiple NV Write,
*/
#define NV_WRITE_BATCH_ITEM_NO_ERROR -1

//  ---------------------------------------------------------
//  defines for log codes
//
//  ---------------------------------------------------------

//! AAGPS Measurement log
#define _DIAG_LOG_AAGPS_MEASUREMENT 0x7005

//! AAGPS Measurement log version 3
#define _DIAG_LOG_AAGPS_MEASUREMENT_V3 0x701F

/******************************************************************************
UIM Diagnostic - MM GSDI Subsystem. Doc: 80-VL005-1
*******************************************************************************/

#define MMGSDIDIAG_GENERIC_COMMAND 0X00000080
#define MMGSDIAG_STATUS_SUCCESS 0

//10 seconds.
#define MMGSDIDIAG_TIME_OUT 10000

typedef enum
{
   MMGSDI_GW_PROV_PRI_SESSION   = 0,
   CHANNEL_NON_EXCLUSIVE        = 0,
   CHANNEL_EXCLUSIVE            = 1,
   SET_NOTIFY                   = 0,
   AID_LEN                      = 16
} UIMDIAG_SESSION_OPEN_COMMAND_OPTIONS;

//Pero settings. Doc: 80-VL005-1
typedef enum
{
   UIMDIAG_MMGSDI_CLIENT_ID_AND_EVT_REG_CMD = 64000,
   UIMDIAG_MMGSDI_CLIENT_ID_AND_EVT_DEREG_CMD   = 64001,
   UIMDIAG_MMGSDI_SESSION_OPEN_CMD              = 64002,
   UIMDIAG_MMGSDI_SESSION_CLOSE_CMD         = 64003,
   UIMDIAG_MMGSDI_SESSION_PERSO_ACTIVATE_CMD    = 64021,
   UIMDIAG_MMGSDI_SESSION_PERSO_DEACTIVATE_CMD  = 64022,
   UIMDIAG_MMGSDI_SESSION_PERSO_GET_INDICATORS_CMD =   64023,
   UIMDIAG_MMGSDI_SESSION_PERSO_SET_DATA_CMD    = 64024,
   UIMDIAG_MMGSDI_SESSION_PERSO_GET_DATA_CMD    = 64025,
   UIMDIAG_MMGSDI_SESSION_PERSO_GET_KEY_CMD = 64033,
   UIMDIAG_MMGSDI_SESSION_PERSO_UNBLOCK_CMD  = 64034
} UIMDIAG_SubCommand;

//Pero settings. Doc: 80-VL005-1
typedef enum
{
   CMD_CODE = 0x80,
   SUBSYS_ID    = 0x21
} UIMDIAG_CommandCode;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   byte cmd_code;
   byte subsys_id;
   word subsys_cmd_code;
} MMGSDI_DIAG_Common_Request_Packet;
typedef MMGSDI_DIAG_Common_Request_Packet SIMLOCK_Common_Request_Header;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   byte cmd_code;
   byte subsys_id;
   word subsys_cmd_code;
   dword    command_status;
   word delayed_response_id;
   word delayed_response_count;
} MMGSDI_DIAG_Common_Response_Packet;
typedef MMGSDI_DIAG_Common_Response_Packet SIMLOCK_Common_Response_Header;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    client_id_and_evt_reg_packet;
   dword    client_ref;
} MMGSDI_CLIENT_ID_AND_EVT_REG_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    client_id_high;
   dword    client_id_low;
} MMGSDI_CLIENT_ID_AND_EVT_REG_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    diag_common_request_packet;
   dword    client_id_low;
   dword    client_id_high;
} MMGSDI_CLIENT_ID_AND_EVT_DEREG_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    client_id_high;
   dword    client_id_low;
} MMGSDI_CLIENT_ID_AND_EVT_DEREG_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    client_id_and_evt_reg_packet;
   dword    client_id_low;
   dword    client_id_high;
   dword    session_type;
   dword    exclusive_channel;
   dword    set_notify;
   dword    aid_len;
   byte aid[16];
} MMGSDI_SESSION_OPEN_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    session_id_high;
   dword    session_id_low;
   dword    channel_id;
   dword    app_type;
   dword    aid_len;
   byte *aid;
   dword    label_len;
   byte *label;
} MMGSDI_SESSION_OPEN_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    diag_common_request_packet;
   dword    session_id_high;
   dword    session_id_low;
} MMGSDI_SESSION_CLOSE_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    session_id_high;
   dword    session_id_low;
   dword    app_type;
   dword    aid_len;
   byte aid[32];
} MMGSDI_SESSION_CLOSE_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    client_id_and_evt_reg_packet;
   dword    session_id_high;
   dword    session_id_low;
   dword    feature_type;
   dword    key_type;
} MMGSDI_SESSION_PERSO_GET_KEY_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    feature;
   dword    imei_length;
   dword    key_length;
   byte imei_data[32];
   byte key_data[16];
} MMGSDI_SESSION_PERSO_GET_KEY_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    diag_common_request_packet;
   dword    session_id_high;
   dword    session_id_low;
   dword    feature_type;
   dword    data_length;
   byte *data;
} MMGSDI_SESSION_PERSO_ACTIVATE_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    perso_action;
   dword    perso_feature;
   dword    num_retries_left;
} MMGSDI_SESSION_PERSO_ACTIVATE_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    diag_common_request_packet;
   dword    session_id_high;
   dword    session_id_low;
   dword    feature_type;
   dword    data_length;
   byte *data;
} MMGSDI_SESSION_PERSO_DEACTIVATE_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    perso_action;
   dword    perso_feature;
   dword    num_retries;
} MMGSDI_SESSION_PERSO_DEACTIVATE_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    diag_common_request_packet;
   dword    session_id_high;
   dword    session_id_low;
   dword    feature_type;
   dword    data_length;
   byte *data;
} MMGSDI_SESSION_PERSO_UNBLOCK_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    perso_action;
   dword    perso_feature;
   dword    num_retries;
} MMGSDI_SESSION_PERSO_UNBLOCK_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    diag_common_request_packet;
   dword    session_id_high;
   dword    session_id_low;
   dword    feature_type;
   dword    data_length;
   byte *data;
} MMGSDI_SESSION_PERSO_SET_DATA_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    session_id_high;
   dword    session_id_low;
} MMGSDI_SESSION_PERSO_SET_DATA_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    diag_common_request_packet;
   dword    session_id_high;
   dword    session_id_low;
   dword    feature_name;
} MMGSDI_SESSION_PERSO_GET_DATA_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    perso_action;
   dword    data_length;
} MMGSDI_SESSION_PERSO_GET_DATA_Response_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Request_Packet    diag_common_request_packet;
   dword    session_id_high;
   dword    session_id_low;
   dword    perso_feature_indicator;
} MMGSDI_SESSION_PERSO_GET_INDICATORS_Request_Packet;

//Pero settings. Doc: 80-VL005-1
typedef struct
{
   MMGSDI_DIAG_Common_Response_Packet command_packet;
   dword    status;
   dword    nw_ind_status;
   dword    ns_ind_status;
   dword    sp_ind_status;
   dword    cp_ind_status;
   dword    sim_ind_status;
   dword    ruim_nw1_ind;
   dword    ruim_nw2_ind;
   dword    ruim_hrpd_ind;
   dword    ruim_sp_ind;
   dword    ruim_cp_ind;
   dword    ruim_ruim_ind;
} MMGSDI_SESSION_PERSO_GET_INDICATORS_Response_Packet;

/******************************************************************************
Diagnostic - GSDI Subsystem
*******************************************************************************/

//! GSDI Generic command, for the SUBSYS_CMD_CODE field
#define GSDIDIAG_GENERIC_COMMAND 0X00000000

/**
GSDIDIAG Commands
*/
typedef enum
{
   //GSDIDIAG_MIN_CMD =-1
   _GSDIDIAG_SIM_READ_CMD                       = 0x00,
   _GSDIDIAG_SIM_WRITE_CMD                      = 0x01,
   _GSDIDIAG_SIM_INCREASE_CMD                   = 0x02,
   _GSDIDIAG_GET_FILE_ATTRIBUTES_CMD            = 0x04,
   _GSDIDIAG_GET_PIN_STATUS_CMD                 = 0x05,
   _GSDIDIAG_VERIFY_PIN_CMD                     = 0x06,
   _GSDIDIAG_CHANGE_PIN_CMD                     = 0x07,
   _GSDIDIAG_UNBLOCK_PIN_CMD                    = 0x08,
   _GSDIDIAG_DISABLE_PIN_CMD                    = 0x09,
   _GSDIDIAG_ENABLE_PIN_CMD                     = 0x0A,
   _GSDIDIAG_GET_SIM_CAPABILITES_CMD            = 0x0C,
   _GSDIDIAG_ILLEGAL_SIM_CMD                    = 0x0F,
   _GSDIDIAG_SIM_SEARCH_CMD                     = 0x10,
   _GSDIDIAG_SELECT_CMD                         = 0x12,
   _GSDIDIAG_GET_IMAGE_CMD                      = 0x14,
   _GSDIDIAG_SIM_REFRESH_CMD                    = 0x15,
   _GSDIDIAG_GET_AVAILABLE_APPS_CMD             = 0x17,
   _GSDIDIAG_ACTIVATE_FEATURE_INDICATOR_CMD     = 0x40,
   _GSDIDIAG_DEACTIVATE_FEATURE_INDICATOR_CMD   = 0x41,
   _GSDIDIAG_GET_FEATURE_INDICATION_CMD         = 0x42,
   _GSDIDIAG_SET_FEATURE_INDICATOR_DATA_CMD     = 0x43,
   _GSDIDIAG_GET_FEATURE_INDICATOR_KEY_CMD      = 0x44,
   _GSDIDIAG_UNBLOCK_FEATURE_INDICATOR_CMD      = 0x45,
   _GSDIDIAG_GET_PERM_FEATURE_INDICATION_CMD    = 0x46,
   _GSDIDIAG_PERM_DISABLE_FEATURE_INDICATOR_CMD = 0x47,
   _GSDIDIAG_GENERIC_CMD                        = 0x48,
   _GSDIDIAG_GET_ATR_CMD                        = 0x49,
   _GSDIDIAG_SIM_OPEN_CHANNEL_CMD               = 0x50,
   _GSDIDIAG_SIM_CLOSE_CHANNEL_CMD              = 0x51,
   _GSDIDIAG_SIM_SEND_CHANNEL_DATA_CMD          = 0x52,
   _GSDIDIAG_ATCSIM_RAW_APDU_CMD                = 0x53,
   _GSDIDIAG_SIM_USIM_RUIM_SEARCH_CMD           = 0x54,
   _GSDIDIAG_GET_ECC_CMD                        = 0x55,
   _GSDIDIAG_SECURE_DEVICE_INFO_CMD             = 0x56,
   _GSDIDIAG_SIM_SECURE_STORE_CMD               = 0x57,
   _GSDIDIAG_ROOT_KEY_WRITE_CMD                 = 0x58,
   _GSDIDIAG_ROOT_KEY_READ_CMD                  = 0x59,
   _GSDIDIAG_SIM_SECURE_READ_CMD                = 0x5A,
   _GSDIDIAG_VERIFY_PHONE_CODE_CMD              = 0x5B,
   _GSDIDIAG_CHANGE_PHONE_CODE_CMD              = 0x5C,
   _GSDIDIAG_UNBLOCK_PHONE_CODE_CMD             = 0x5D,
   _GSDIDIAG_SET_PHONE_CODE_CMD                 = 0x5E,
   _GSDIDIAG_GET_LIB_VERSION_CMD                = 0x5F,
   _GSDIDIAG_ACTIVATE_ONCHIP_SIM_CMD            = 0x61,
   _GSDIDIAG_SEND_APDU_CMD                      = 0x99,
   _GSDIDIAG_GET_FEATURE_INDICATOR_DATA_CMD     = 0xAE,
   _GSDIDIAG_MAX_CMD                            = 0xFF
} GSDI_DIAG_CMD_Enum;

/**
Values for the APS_AS_TRANSPORT field
*/
typedef enum
{
   GSDI_DIAG_APS_As_Transport_CmdResponse,  //!< ' Response is in Command Response Header (Pass or Fail)
   GSDI_DIAG_APS_As_Transport_DelayedResponse   //!< ' Response is in the Response Payload.
} GSDI_DIAG_APS_AsTransport_Enum;

/**
Header for the GSDI Response
\code
Field               Length
------              ------
CMD_CODE                1
SUBSYS_ID               1
SUBSYS_CMD_CODE         2
COMMAND_STATUS          4
DELAYED_RESPONSE_ ID    2
DELAYED_RESPONSE_COUNT  2
SUBCOMMAND              4
APS_AS_TRANSPORT        4
STATUS                  4  <--- This one seems to be missing

typedef PACKED struct gsdidiag_generic_cmd_rsp_type
{
typedef PACKED struct  gsdidiag_rsp_header_type
{
uint8  command_code;
uint8  subsys_id;
uint16 subsys_cmd_code;
uint32 status;
uint16 delayed_rsp_id;
uint16 rsp_count;
uint32 aps_as_transport;
} rsp_header;

typedef PACKED struct
{
uint32 subcommand;
uint32 gsdi_status;
}gsdidiag_subcmd_rsp_hdr_type;

PACKED union gsdidiag_rsp_payload_type
{
gsdidiag_rsp_data_payload_type         data;
gsdidiag_rsp_channel_data_payload_type channel_data;
gsdidiag_rsp_atcsim_payload_type       atcsim_data;
gsdidiag_rsp_sim_read_payload_type     sim_read_data;
gsdidiag_rsp_sim_get_ecc_type          ecc_data;
uint8 num_retries;
byte rec_num_accessed;
gsdidiag_root_key_rsp_type             root_key_write;
gsdidiag_root_key_rsp_type             root_key_read;
gsdidiag_sim_secure_read_rsp_type      sim_secure_read;
gsdidiag_get_lib_version_rsp_type      lib_version;
}rsp_payload;
} response;
\endcode
*/
typedef struct
{
   byte  iCMD_Code;
   byte  iSubSysId;
   word iSubSysCmdCode;
   dword  iCommandStatus;
   word iDelayedResponseId;
   word iDelayedResponseCount;
   dword  iApsAsTransport;
   dword  iSubCommand;
   dword  iStatus;
} GSDI_DIAG_DelayedResponseHeader;

/*
GSDI Request Header

typedef PACKED struct
{
typedef PACKED struct gsdidiag_sim_get_file_attributes_cmd_req_type
{
typedef PACKED struct gsdidiag_cmd_header_type
{
uint8 command_code;
uint8 subsys_id;
uint16 subsys_cmd_code;
} header;

uint8  sim_slot_number;
uint8  sim_app_id_len;
uint8  sim_app_id[GSDI_MAX_APP_ID_LEN];
uint32 sim_elementary_file;
char   efs_filename[1];
} cmd_header;

typedef PACKED struct gsdidiag_req_payload_type
{
typedef PACKED struct gsdidiag_subcmd_req_hdr_type
{
uint32 subcommand;
uint32 gsdi_status;
} sub_cmd_hdr;

PACKED union
{
gsdidiag_two_pin_cmd_type      change_pin;
gsdidiag_channel_req_cmd_type  channel_req;
gsdidiag_sim_read_req_cmd_type sim_read_req;
gsdidiag_sim_usim_ruim_search  sim_usim_ruim_search_req;
gsdidiag_sim_secure_store_cmd_type sim_secure_store_req;
gsdidiag_root_key_write_req_cmd_type root_key_write_req;
gsdidiag_verify_phone_code_cmd_type  verify_phone_code_req;
gsdidiag_change_phone_code_cmd_type  change_phone_code_req;
gsdidiag_unblock_phone_code_cmd_type unblock_phone_code_req;
gsdidiag_set_phone_code_cmd_type     set_phone_code_req;
}request;
}req_payload;
}gsdidiag_generic_cmd_req_type;

*/

/**
GSDI Response structure for commands that are not "delayed response"
*/
typedef struct
{
   byte  iCMD_Code;
   byte  iSubSysId;
   word iSubSysCmdCode;
   dword  iCommandStatus;
   word iTransactionID;
   byte iSIM_SlotNumber;
} GSDI_DIAG_ResponseHeader;

/**
Enum of status values for GSDI commands
*/
typedef enum
{
   GSDI_DIAG_STAT_Success               = 0,  //!< ' COMMAND COMPLETED SUCCESSFULLY
   GSDI_DIAG_STAT_GeneralError      = 1,  //!< ' GENERAL ERROR:  No other information specified
   GSDI_DIAG_STAT_AccessDenied      = 2,  //!< ' ACCESS DENIED:  Security Procedures performed thus far don't satisfy restrictions
   GSDI_DIAG_STAT_NotFound          = 3,  //!< ' NOT FOUND:  SIM Elementary File or Directory File was not found.
   GSDI_DIAG_STAT_IncompatPinStauts = 4,  //!< ' INCOMPATIBLE PIN STATUS:  Trying to perform a PIN Action for a PIN that is not in the correct state.  For example, trying to Disable an already Disabled PIN.
   GSDI_DIAG_STAT_IncorrectCode     = 5,  //!< ' INCORRECT CODE:  The Code provided is incorrect for the PIN ID used.
   GSDI_DIAG_STAT_CodeBlocked           = 6,  //!< ' CODE BLOCKED:  The Number of retries has been exceeded and the PIN is now blocked.
   GSDI_DIAG_STAT_IncreaseImpossible    = 7,  //!< ' INCREASE IMPOSSIBLE:  The INCREASE Command has failed due to a Bad Value
   GSDI_DIAG_STAT_IncorrectParameters = 8,  //!< ' INCORRECT PARAMETERS:  The SIM detected an incorrect parameter for the action performed.
   GSDI_DIAG_STAT_NotSupported      = 9,  //!< ' NOT SUPPORTED:  Not allowed by GSDI due to Service Table Values
   GSDI_DIAG_STAT_NotInitialized        = 10, //!< ' NOT INIT:  Cache has not been INIT
   GSDI_DIAG_STAT_IllegalSim            = 11, //!< ' SUCCESS BUT ILLEGAL SIM:  The SIM has been marked as an illegal SIM for the network, but the actions are succeeding on the SIM.
   GSDI_DIAG_STAT_SimTechnicalProblems = 14,//!< ' SIM TECHNICAL PROBLEMS:  The SIM malfunctioned.
   GSDI_DIAG_STAT_NoEfSelected      = 15, //!< ' NO EF SELECTED:  Attempted to read a file without first selecting it.
   GSDI_DIAG_STAT_EfInconsistent        = 16, //!< ' EF INCONSISTENT:  Trying to Read a Record when the file is a Binary or similar type error.
   GSDI_DIAG_STAT_UnknownInstClass  = 17, //!< ' UNKNOWN INST CLASS:  Trying to send a UICC Command to a GSM/RUIM Card or vice versa.
   GSDI_DIAG_STAT_IncorrectLength       = 21, //!< ' INCORRECT LENGTH:  A Bad length was provided in the command.
   GSDI_DIAG_STAT_DriversTimedOut       = 22, //!< ' DRIVERS TIMED OUT:  The Drivers communicating with the Card Timed Out.
   GSDI_DIAG_STAT_CodePermBlocked       = 23  //!< ' CODE PERM BLOCKED:  The Unblock Code has been blocked.  Need Administrative assistance to unblock it.
} GSDI_DIAG_StatusEnum;

/**
For the "command status" result on GSDI commands.
*/
#define GSDI_SUCCESS DIAG_V2_SUCCESS

/**
Enum of dealyed response counts GSDI commands
*/
typedef enum
{
   GSDI_DIAG_ResponseCount_First                = 0,    //!< ' 0 - First Response (Immediate)
   GSDI_DIAG_ResponseCount_Delayed              = 1     //!< ' 1 - Second Response  (Delayed)
} GSDI_DIAG_ResponseCountEnum;

/**
Enum for GSDI SIM Index mode

Copied from embedded source code file gsdidiag.h
*/
typedef enum
{
   GSDI_DIAG_IndexNone      = 0x00000000,
   GSDI_DIAG_IndexAbsolute = 0x00000001,
   GSDI_DIAG_IndexCurrent   = 0x00000002,
   GSDI_DIAG_IndexNext      = 0x00000003,
   GSDI_DIAG_IndexPrevious = 0x00000004
} GSDI_DIAG_SIM_IndexMode;

/**
Enumerated type:  gsdidiag_elementary_file_enum_type
Define Filenames Available through GSDI - DIAG Interface
CDMA RUIM Related Files Range:  0x00000001 - 0x000000FF
GSM  SIM  Related Files Range:  0x00001000 - 0x0000FF00
UMTS USIM Related Files Range:  0x00010000 - 0x00FF0000
TELECOM   Related Files Range:  0x01000000 - 0xFF000000

Copied from embedded source code file gsdidiag.h
*/

typedef enum
{
   //GSDIDIAG_MIN_CMD =-1

   GSDIDIAG_MF_ICCID                             = 0x00000001,
   GSDIDIAG_MF_ELP                               = 0x00000002,
   GSDIDIAG_MF_DIR                               = 0x00000003,
   GSDIDIAG_MF_ARR                               = 0x00000004,
   GSDIDIAG_MF_PL                                = 0x00000005,

   GSDIDIAG_CDMA_CC                              = 0x00000100,
   GSDIDIAG_CDMA_IMSI_M                          = 0x00000101,
   GSDIDIAG_CDMA_IMSI_T                          = 0x00000102,
   GSDIDIAG_CDMA_ANALOG_HOME_SID                 = 0x00000103,
   GSDIDIAG_CDMA_ANALOG_OP_PARAMS                = 0x00000104,
   GSDIDIAG_CDMA_ANALOG_LOCN_AND_REGN_IND        = 0x00000105,
   GSDIDIAG_CDMA_HOME_SID_NID                    = 0x00000106,
   GSDIDIAG_CDMA_ZONE_BASED_REGN_IND             = 0x00000107,
   GSDIDIAG_CDMA_SYS_REGN_IND                    = 0x00000108,
   GSDIDIAG_CDMA_DIST_BASED_REGN_IND             = 0x00000109,
   GSDIDIAG_CDMA_ACCOLC                          = 0x0000010A,
   GSDIDIAG_CDMA_CALL_TERM_MOD_PREF              = 0x0000010B,
   GSDIDIAG_CDMA_SCI                             = 0x0000010C,
   GSDIDIAG_CDMA_ANALOG_CHAN_PREF                = 0x0000010D,
   GSDIDIAG_CDMA_PRL                             = 0x0000010E,
   GSDIDIAG_CDMA_RUIM_ID                         = 0x0000010F,
   GSDIDIAG_CDMA_SVC_TABLE                       = 0x00000110,
   GSDIDIAG_CDMA_SPC                             = 0x00000111,
   GSDIDIAG_CDMA_OTAPA_SPC_ENABLE                = 0x00000112,
   GSDIDIAG_CDMA_NAM_LOCK                        = 0x00000113,
   GSDIDIAG_CDMA_OTASP_OTAPA_FEATURES            = 0x00000114,
   GSDIDIAG_CDMA_SERVICE_PREF                    = 0x00000115,
   GSDIDIAG_CDMA_ESN_ME                          = 0x00000116,
   GSDIDIAG_CDMA_RUIM_PHASE                      = 0x00000117,
   GSDIDIAG_CDMA_PREF_LANG                       = 0x00000118,
   GSDIDIAG_CDMA_UNASSIGNED_1                    = 0x00000119,
   GSDIDIAG_CDMA_SMS                             = 0x0000011A,
   GSDIDIAG_CDMA_SMS_PARAMS                      = 0x0000011B,
   GSDIDIAG_CDMA_SMS_STATUS                      = 0x0000011C,
   GSDIDIAG_CDMA_SUP_SVCS_FEATURE_CODE_TABLE     = 0x0000011D,
   GSDIDIAG_CDMA_UNASSIGNED_2                    = 0x0000011E,
   GSDIDIAG_CDMA_HOME_SVC_PVDR_NAME              = 0x0000011F,
   GSDIDIAG_CDMA_UIM_ID_USAGE_IND                = 0x00000120,
   GSDIDIAG_CDMA_ADM_DATA                        = 0x00000121,
   GSDIDIAG_CDMA_MSISDN                          = 0x00000122,
   GSDIDIAG_CDMA_MAXIMUM_PRL                     = 0x00000123,
   GSDIDIAG_CDMA_SPC_STATUS                      = 0x00000124,

   GSDIDIAG_GSM_LP                               = 0x00000200,
   GSDIDIAG_GSM_IMSI                             = 0x00000201,
   GSDIDIAG_GSM_KC                               = 0x00000202,
   GSDIDIAG_GSM_PLMN                             = 0x00000203,
   GSDIDIAG_GSM_HPLMN                            = 0x00000204,
   GSDIDIAG_GSM_ACM_MAX                          = 0x00000205,
   GSDIDIAG_GSM_SST                              = 0x00000206,
   GSDIDIAG_GSM_ACM                              = 0x00000207,
   GSDIDIAG_GSM_GID1                             = 0x00000208,
   GSDIDIAG_GSM_GDI2                             = 0x00000209,
   GSDIDIAG_GSM_SPN                              = 0x0000020A,
   GSDIDIAG_GSM_PUCT                             = 0x0000020B,
   GSDIDIAG_GSM_CBMI                             = 0x0000020C,
   GSDIDIAG_GSM_BCCH                             = 0x0000020D,
   GSDIDIAG_GSM_ACC                              = 0x0000020E,
   GSDIDIAG_GSM_FPLMN                            = 0x0000020F,
   GSDIDIAG_GSM_LOCI                             = 0x00000210,
   GSDIDIAG_GSM_AD                               = 0x00000211,
   GSDIDIAG_GSM_PHASE                            = 0x00000222,
   GSDIDIAG_GSM_VGCS                             = 0x00000223,
   GSDIDIAG_GSM_VGCSS                            = 0x00000224,
   GSDIDIAG_GSM_VBS                              = 0x00000225,
   GSDIDIAG_GSM_VBSS                             = 0x00000226,
   GSDIDIAG_GSM_EMLPP                            = 0x00000227,
   GSDIDIAG_GSM_AAEM                             = 0x00000228,
   GSDIDIAG_GSM_CBMID                            = 0x00000229,
   GSDIDIAG_GSM_ECC                              = 0x0000022A,
   GSDIDIAG_GSM_CBMIR                            = 0x0000022B,
   GSDIDIAG_GSM_DCK                              = 0x0000022C,
   GSDIDIAG_GSM_CNL                              = 0x0000022D,
   GSDIDIAG_GSM_NIA                              = 0x0000022E,
   GSDIDIAG_GSM_KCGPRS                           = 0x0000022F,
   GSDIDIAG_GSM_LOCIGPRS                         = 0x00000230,
   GSDIDIAG_GSM_SUME                             = 0x00000231,
   GSDIDIAG_GSM_PLMNWAT                          = 0x00000232,
   GSDIDIAG_GSM_OPLMNWACT                        = 0x00000233,
   GSDIDIAG_GSM_CPBCCH                           = 0x00000234,
   GSDIDIAG_GSM_INVSCAN                          = 0x00000235,
   GSDIDIAG_GSM_RPLMNACT                         = 0x00000236,
   GSDIDIAG_GSM_SAI                              = 0x00000237,
   GSDIDIAG_GSM_SLL                              = 0x00000238,
   GSDIDIAG_GSM_MEXE_ST                          = 0x00000239,
   GSDIDIAG_GSM_ORPK                             = 0x0000023A,
   GSDIDIAG_GSM_ARPK                             = 0x0000023B,
   GSDIDIAG_GSM_TPRPK                            = 0x0000023C,
   GSDIDIAG_GSM_IMG                              = 0x0000023D,
   GSDIDIAG_GSM_IMG1INST1                        = 0x0000023E,
   GSDIDIAG_GSM_IMG1INST2                        = 0x0000023F,
   GSDIDIAG_GSM_IMG1INST3                        = 0x00000240,
   GSDIDIAG_GSM_IMG2INST1                        = 0x00000241,
   GSDIDIAG_GSM_IMG2INST2                        = 0x00000242,
   GSDIDIAG_GSM_IMG2INST3                        = 0x00000243,
   GSDIDIAG_GSM_IMG3INST1                        = 0x00000244,
   GSDIDIAG_GSM_IMG3INST2                        = 0x00000245,
   GSDIDIAG_GSM_IMG3INST3                        = 0x00000246,
   GSDIDIAG_GSM_HPLMNWACT                        = 0x00000247,

   GSDIDIAG_TELECOM_ADN                          = 0x00000300,
   GSDIDIAG_TELECOM_FDN                          = 0x00000301,
   GSDIDIAG_TELECOM_SMS                          = 0x00000302,
   GSDIDIAG_TELECOM_CCP                          = 0x00000303,
   GSDIDIAG_TELECOM_ECCP                         = 0x00000304,
   GSDIDIAG_TELECOM_MSISDN                       = 0x00000305,
   GSDIDIAG_TELECOM_SMSP                         = 0x00000306,
   GSDIDIAG_TELECOM_SMSS                         = 0x00000307,
   GSDIDIAG_TELECOM_LND                          = 0x00000308,
   GSDIDIAG_TELECOM_SDN                          = 0x00000309,
   GSDIDIAG_TELECOM_EXT1                         = 0x0000030A,
   GSDIDIAG_TELECOM_EXT2                         = 0x0000030B,
   GSDIDIAG_TELECOM_EXT3                         = 0x0000030C,
   GSDIDIAG_TELECOM_BDN                          = 0x0000030D,
   GSDIDIAG_TELECOM_EXT4                         = 0x0000030E,
   GSDIDIAG_TELECOM_SMSR                         = 0x0000030F,
   GSDIDIAG_TELECOM_CMI                          = 0x00000310,
   GSDIDIAG_TELECOM_SUME                         = 0x00000311,
   GSDIDIAG_TELECOM_ARR                          = 0x00000312,
   GSDIDIAG_TELECOM_PBR                          = 0x00000313,
   GSDIDIAG_TELECOM_CCP1                         = 0x00000314,
   GSDIDIAG_TELECOM_UID                          = 0x00000315,
   GSDIDIAG_TELECOM_PSC                          = 0x00000316,
   GSDIDIAG_TELECOM_CC                           = 0x00000317,
   GSDIDIAG_TELECOM_PUID                         = 0x00000318,
   GSDIDIAG_TELECOM_ADN1                         = 0x00000319,
   GSDIDIAG_TELECOM_GRP                          = 0x0000031A,
   GSDIDIAG_TELECOM_GRP1                         = 0x0000031B,
   GSDIDIAG_TELECOM_GAS                          = 0x0000031C,
   GSDIDIAG_TELECOM_SNE                          = 0x0000031D,
   GSDIDIAG_TELECOM_SNE1                         = 0x0000031E,
   GSDIDIAG_TELECOM_EMAIL                        = 0x0000031F,
   GSDIDIAG_TELECOM_EMAIL1                       = 0x00000320,
   GSDIDIAG_TELECOM_IAP                          = 0x00000321,
   GSDIDIAG_TELECOM_IAP1                         = 0x00000322,
   GSDIDIAG_TELECOM_PBC                          = 0x00000323,

   GSDIDIAG_TELECOM_GRAPHICS_IMG                 = 0x00000400,

   GSDIDIAG_USIM_LI                              = 0x00000500,
   GSDIDIAG_USIM_IMSI                            = 0x00000501,
   GSDIDIAG_USIM_KEYS                            = 0x00000502,
   GSDIDIAG_USIM_KEYSPS                          = 0x00000503,
   GSDIDIAG_USIM_PLMNWACT                        = 0x00000504,
   GSDIDIAG_USIM_UPLMNSEL                        = 0x00000505,
   GSDIDIAG_USIM_HPLMN                           = 0x00000506,
   GSDIDIAG_USIM_ACM_MAX                         = 0x00000507,
   GSDIDIAG_USIM_UST                             = 0x00000508,
   GSDIDIAG_USIM_ACM                             = 0x00000509,
   GSDIDIAG_USIM_GID1                            = 0x0000050A,
   GSDIDIAG_USIM_GID2                            = 0x0000050B,
   GSDIDIAG_USIM_SPN                             = 0x0000050C,
   GSDIDIAG_USIM_PUCT                            = 0x0000050D,
   GSDIDIAG_USIM_CMBI                            = 0x0000050E,
   GSDIDIAG_USIM_ACC                             = 0x0000050F,
   GSDIDIAG_USIM_FPLMN                           = 0x00000510,
   GSDIDIAG_USIM_LOCI                            = 0x00000511,
   GSDIDIAG_USIM_AD                              = 0x00000512,
   GSDIDIAG_USIM_CBMID                           = 0x00000513,
   GSDIDIAG_USIM_ECC                             = 0x00000514,
   GSDIDIAG_USIM_CBMIR                           = 0x00000515,
   GSDIDIAG_USIM_PSLOCI                          = 0x00000516,
   GSDIDIAG_USIM_FDN                             = 0x00000517,
   GSDIDIAG_USIM_SMS                             = 0x00000518,
   GSDIDIAG_USIM_MSISDN                          = 0x00000519,
   GSDIDIAG_USIM_SMSP                            = 0x0000051A,
   GSDIDIAG_USIM_SMSS                            = 0x0000051B,
   GSDIDIAG_USIM_SDN                             = 0x0000051C,
   GSDIDIAG_USIM_EXT2                            = 0x0000051D,
   GSDIDIAG_USIM_EXT3                            = 0x0000051E,
   GSDIDIAG_USIM_SMSR                            = 0x0000051F,
   GSDIDIAG_USIM_ICI                             = 0x00000520,
   GSDIDIAG_USIM_OCI                             = 0x00000521,
   GSDIDIAG_USIM_ICT                             = 0x00000522,
   GSDIDIAG_USIM_OCT                             = 0x00000523,
   GSDIDIAG_USIM_EXT5                            = 0x00000524,
   GSDIDIAG_USIM_CCP2                            = 0x00000525,
   GSDIDIAG_USIM_EMLPP                           = 0x00000526,
   GSDIDIAG_USIM_AAEM                            = 0x00000527,
   GSDIDIAG_USIM_GMSI                            = 0x00000528,
   GSDIDIAG_USIM_HIDDENKEY                       = 0x00000529,
   GSDIDIAG_USIM_BDN                             = 0x0000052A,
   GSDIDIAG_USIM_EXT4                            = 0x0000052B,
   GSDIDIAG_USIM_CMI                             = 0x0000052C,
   GSDIDIAG_USIM_EST                             = 0x0000052D,
   GSDIDIAG_USIM_ACL                             = 0x0000052E,
   GSDIDIAG_USIM_DCK                             = 0x0000052F,
   GSDIDIAG_USIM_CNL                             = 0x00000530,
   GSDIDIAG_USIM_START_HFN                       = 0x00000531,
   GSDIDIAG_USIM_THRESHOLD                       = 0x00000532,
   GSDIDIAG_USIM_OPLMNWACT                       = 0x00000533,
   GSDIDIAG_USIM_OPLMNSEL                        = 0x00000534,
   GSDIDIAG_USIM_HPLMNWACT                       = 0x00000535,
   GSDIDIAG_USIM_ARR                             = 0x00000536,
   GSDIDIAG_USIM_RPLMNACT                        = 0x00000537,
   GSDIDIAG_USIM_NETPAR                          = 0x00000538,
   GSDIDIAG_USIM_ADN                             = 0x00000539,
   GSDIDIAG_USIM_ADN1                            = 0x0000053A,
   GSDIDIAG_USIM_GAS                             = 0x0000053B,
   GSDIDIAG_USIM_GAS1                            = 0x0000053C,
   GSDIDIAG_USIM_GRP1                            = 0x0000053D,
   GSDIDIAG_USIM_SNE                             = 0x0000053E,
   GSDIDIAG_USIM_SNE1                            = 0x0000053F,
   GSDIDIAG_USIM_EMAIL                           = 0x00000540,
   GSDIDIAG_USIM_EMAIL1                          = 0x00000541,
   GSDIDIAG_USIM_IAP                             = 0x00000542,
   GSDIDIAG_USIM_IAP1                            = 0x00000543,

   GSDIDIAG_USIM_PHONEBOOK_PBR                   = 0x00000600,
   GSDIDIAG_USIM_PHONEBOOK_CCP1                  = 0x00000601,
   GSDIDIAG_USIM_PHONEBOOK_UID                   = 0x00000602,
   GSDIDIAG_USIM_PHONEBOOK_PSC                   = 0x00000603,
   GSDIDIAG_USIM_PHONEBOOK_CC                    = 0x00000604,
   GSDIDIAG_USIM_PHONEBOOK_PUID                  = 0x00000605,
   GSDIDIAG_USIM_PHONEBOOK_PBC                   = 0x00000606,

   GSDIDIAG_USIM_GSMACCESS_KC                    = 0x00000700,
   GSDIDIAG_USIM_GSMACCESS_KCGPRS                = 0x00000701,
   GSDIDIAG_USIM_GSMACCESS_CPBCCH                = 0x00000702,
   GSDIDIAG_USIM_GSMACCESS_INVSCAN               = 0x00000703,

   GSDIDIAG_USIM_MEXE_MEXE_ST                    = 0x00000800,
   GSDIDIAG_USIM_MEXE_ORPK                       = 0x00000801,
   GSDIDIAG_USIM_MEXE_ARPK                       = 0x00000802,
   GSDIDIAG_USIM_MEXE_TPRPK                      = 0x00000803
                                                   //reserved
} GSDI_DIAG_SIM_ElementaryFile_Enum;

/**
Enumerated type for GSDI SIM Simple Req

Defines Index Modes Available for Commands.
0 = User specified values for SIM_INDEX_MODE, SIM_
OFFSET, SIM_REC_NUM, SIM_DATA_LEN: user has to
deal with chunking: for record based files, user has to
specify SIM_REC_NUM
1 = Phone uses appropriate values; also returns the
complete data in a file; user is transparent to chunking

Copied from embedded source code file gsdidiag.h

*/

typedef enum
{
   GSDIDIAG_SIM_SIMPLE_REQ_ONE_STEP = 0x00, // Mobile software performs only one step of preparing data
   GSDIDIAG_SIM_SIMPLE_REQ_ALL_STEPS = 0x01 // Mobile software merges all data into a complete file
} GSDI_DIAG_SimpleReq_Enum;

/**
Enumerated type for GSDI indexing modes

Defines Index Modes Available for Commands.
GSDIDIAG_NO_INDEX        :  Applicable to Binary/Transparent Files
GSDIDIAG_INDEX_ABSOLUTE  :  Applicable to Linear Fixed / Cyclic Files
GSDIDIAG_INDEX_NEXT      :  Applicable to Cyclic Files
GSDIDIAG_INDEX_PREVIOUS  :  Applicable to Cyclic Files

Copied from embedded source code file gsdidiag.h

*/

typedef enum
{
   GSDIDIAG_NO_INDEX       = 0x00,
   GSDIDIAG_INDEX_ABSOLUTE = 0x01,
   GSDIDIAG_INDEX_CURRENT  = 0x02,
   GSDIDIAG_INDEX_NEXT     = 0x03,
   GSDIDIAG_INDEX_PREVIOUS = 0x04,
} GSDI_DIAG_IndexModes_Enum;

/**
Enumerated personality types to be used with GSDI functions.

Copied from embedded source code file gsdidiag.h
*/
typedef enum
{
   GSDIDIAG_PERSO_NW      = 0x00,
   GSDIDIAG_PERSO_NS      = 0x01,
   GSDIDIAG_PERSO_SP      = 0x02,
   GSDIDIAG_PERSO_CP      = 0x03,
   GSDIDIAG_PERSO_SIM     = 0x04
} GSDI_DIAG_PersoFeature_Enum;

/**
Enumerated personality types to be used with GSDI functions.

Copied from embedded source code file gsdidiag.h
*/
typedef enum
{
   EVENT_GSDI_GET_FILE_ATTRIBUTES   = 999,
   EVENT_GSDI_SIM_READ              = 1000,
   EVENT_GSDI_SIM_WRITE         = 1001,
   EVENT_GSDI_GET_PIN_STATUS        = 1002,
   EVENT_GSDI_VERIFY_PIN            = 1003,
   EVENT_GSDI_UNBLOCK_PIN           = 1004,
   EVENT_GSDI_DISABLE_PIN           = 1005,
   EVENT_GSDI_ENABLE_PIN            = 1006,
   EVENT_GSDI_SIM_INCREASE          = 1007,
   EVENT_GSDI_EXECUTE_APDU_REQ      = 1008,
   EVENT_GSDI_ACTIVATE_FEATURE_IND  = 1037,
   EVENT_GSDI_DEACTIVATE_FEATURE_IND    = 1038,
   EVENT_GSDI_GET_FEATURE_IND           = 1039,
   EVENT_GSDI_SET_FEATURE_DATA          = 1040,
   EVENT_GSDI_UNBLOCK_FEATURE_IND       = 1041,
   EVENT_GSDI_GET_CONTROL_KEY           = 1042,
   EVENT_GSDI_OTA_DEPERSO               = 1043,
   EVENT_GSDI_GET_PERM_FEATURE_IND      = 1044,
   EVENT_GSDI_PERM_DISBALE_FEATURE_IND  = 1045
} GSDI_DIAG_EventId;

/**
Structure for parsing GSDI event responses
*/
typedef struct
{
   unsigned long CMD_STATUS;        //!<' GSDI_SUCCESS = success, otherwise failure codes in chapter 5 of GSDI ICD
   unsigned short TRANSACTION_ID;   //!<' Transaction ID returned from request response.
   unsigned char data[1];           //!<' First data element of data the other data elments
} GSDIDIAG_EventHeader;

/**
Enum for GSDI SIM Applications

*/
typedef enum
{
   GSDI_DIAG_Apps_Telecom   = 0x01,
   GSDI_DIAG_Apps_GSM       = 0x02,
   GSDI_DIAG_Apps_USIM      = 0x04,
   GSDI_DIAG_Apps_RUIM      = 0x08,
   GSDI_DIAG_Apps_EMV       = 0x10,
   GSDI_DIAG_Apps_DCS1800   = 0x20
} GSDI_DIAG_SIM_AppsList;

/******************************************************************************
UIMDIAG SIMLOCK
*******************************************************************************/

//80-VL005-1
typedef enum
{
   UIMDIAG_SIMLOCK_SET_POLICY_CMD           = 0xea60,
   UIMDIAG_SIMLOCK_HCK_LOCK_CMD             = 0xea61,
   UIMDIAG_SIMLOCK_CK_LOCK_CMD              = 0xea62,
   UIMDIAG_SIMLOCK_UNLOCK_CMD               = 0xea63,
   UIMDIAG_SIMLOCK_GET_STATUS_CMD           = 0xea64,
   UIMDIAG_SIMLOCK_GET_CATEGORY_DATA_CMD    = 0xea65,
   UIMDIAG_SIMLOCK_ADD_LOCK_CODES_HCK_CMD = 0xea66,
   UIMDIAG_SIMLOCK_ADD_LOCK_CODES_CK_CMD  = 0xea67,
   UIMDIAG_SIMLOCK_GET_CATEGORY_DATA_EXT_CMD= 0xea68
} SIMLOCK_SubCommand;

//80-VL005-1 7.17
typedef enum
{
   SIMLOCK_SUCCESS,                     /* Command performed successfully                                               */
   SIMLOCK_GENERIC_ERROR,                   /* Generic error has occurred                                                   */
   SIMLOCK_INCORRECT_KEY,                   /* Incorrect input key                                                          */
   SIMLOCK_INCORRECT_PARAMS,                /* Invalid input parameter                                                      */
   SIMLOCK_MEMORY_ERROR_HEAP_EXHAUSTED, /* Insufficient heap memory resources                                           */
   SIMLOCK_MAX_RETRIES_REACHED,         /* Max number of tries to unlock the device has been reached. Device is blocked.*/
   SIMLOCK_INVALID_STATE,                   /* The command cannot be performed in the current SIM Lock state                */
   SIMLOCK_UNSUPPORTED,                 /* Functionality not supported                                                  */
   SIMLOCK_INVALID_LOCK_DATA,               /* Invalid code data                                                            */
   SIMLOCK_CONFLICTING_LOCK_DATA,           /* The new code is conflicting with an existing valid code                      */
} SIM_Lock_Result_Status;

//80-VL005-1 7.18
typedef enum
{
   SIMLOCK_SLOT_POLICY_SAME_ON_ALL_SLOTS,           /* Additional slots have same SimLock configuration as slot 1                   */
   SIMLOCK_SLOT_POLICY_UNIQUE_FOR_EACH_SLOT,        /* Additional slots have a different SimLock configuration (ie. different CK)   */
   SIMLOCK_SLOT_POLICY_LOCK_ONLY_SLOT_1,            /* Card on slot 1 may be locked but additional slots are unlocked               */
   SIMLOCK_SLOT_POLICY_VALID_CARD_MUST_ON_SLOT_1,   /* Additional slots are valid as long as card on slot one is verified           */
   SIMLOCK_SLOT_POLICY_VALID_CARD_MUST_ON_A_SLOT    /* All slots are free as longfar as a valid card is present in any slot         */
} SIMLock_Slot_Policy_Enum;

//80-VL005-1 7.19
typedef enum
{
   SIMLOCK_SUBSCRIPTION_POLICY_INDEPENDENT,            /* Each subscription is independent                                              */
   SIMLOCK_SUBSCRIPTION_POLICY_VALID_3GPP_REQUIRED,    /* 3GPP subscription is required to be verified before using 3GPP2 subscription  */
   SIMLOCK_SUBSCRIPTION_POLICY_VALID_3GPP2_REQUIRED,       /* 3GPP2 subscription is required to be verified before using 3GPP subscription  */
   SIMLOCK_SUBSCRIPTION_POLICY_VALID_BOTH_REQUIRED,    /* Both subscriptions are required to be verified                                */
} SIM_Lock_Subscription_Policy_Enum;

typedef struct
{
   SIMLOCK_Common_Response_Header header;
   dword simlock_status;
} SIMLOCK_Response_Payload;

//80-VL005-1 8.1
typedef struct
{
   SIMLOCK_Common_Request_Header header;
   byte slot_policy;
   byte sub_policy;
} SIMLOCK_SET_POLICY_CMD_Request_Payload;

typedef SIMLOCK_Response_Payload SIMLOCK_SET_POLICY_CMD_Response_Payload;

//80-VL005-1 8.2,8.3
typedef struct
{
   SIMLOCK_Common_Request_Header header;
   byte slot;
   byte category;
   byte auto_lock;
   byte blacklist;
   dword num_retries_max;
   dword iteration_cnt;
} SIMLOCK_LOCK_HEADER;

#define NUM_DATA_PER_CODE 20
typedef struct
{
   byte num_codes;
   byte code_data[1];
} SIMLOCK_LOCK_DATA;
//8.2
typedef struct
{
   byte salt[16];
   byte hck[32];
} SIMLOCK_HCK_LOCK;

typedef struct
{
   SIMLOCK_LOCK_HEADER header;
   SIMLOCK_HCK_LOCK hck;
   SIMLOCK_LOCK_DATA data;
} SIMLOCK_HCK_LOCK_CMD_Request_Payload;

typedef SIMLOCK_Response_Payload SIMLOCK_HCK_LOCK_CMD_Response_Payload;

//8.3
#define MAX_CK_DATA 16
typedef struct
{
   byte ck_len;
   byte ck_data[1];
} SIMLOCK_CK_LOCK;

typedef SIMLOCK_Response_Payload SIMLOCK_CK_LOCK_CMD_Response_Payload;

//80-VL005-1 8.4
typedef struct
{
   SIMLOCK_Common_Request_Header header;
   byte slot;
   byte category;
} SIMLOCK_UNLOCK_HEADER;

typedef struct
{
   SIMLOCK_UNLOCK_HEADER header;
   SIMLOCK_CK_LOCK ck_lock;
} SIMLOCK_UNLOCK_CMD_Request_Payload;

typedef struct
{
   SIMLOCK_Common_Response_Header header;
   dword simlock_status;
   dword max_retries;
   dword curr_retries;
} SIMLOCK_UNLOCK_CMD_Response_Payload;

//80-VL005-1 8.5
typedef SIMLOCK_Common_Request_Header SIMLOCK_GET_STATUS_CMD_Request_Payload;

typedef struct
{
   SIMLOCK_Common_Response_Header header;
   dword simlock_status;
   byte lock_policy;
   byte sub_polick;
   byte lock_info[484];
} SIMLOCK_GET_STATUS_CMD_Response_Payload;

//80-VL005-1 8.6
typedef SIMLOCK_UNLOCK_HEADER SIMLOCK_GET_CATEGORY_DATA_CMD_Request_Payload;

typedef struct
{
   SIMLOCK_Common_Response_Header header;
   dword simlock_status;
   byte category;
   byte num_codes;
   byte code_data[1];
} SIMLOCK_GET_CATEGORY_DATA_CMD_Response_Payload;

//80-VL005-1 8.7
typedef struct
{
   SIMLOCK_Common_Request_Header header;
   byte slot;
   byte category;
   byte blacklist;
   byte hck[32];
   byte num_codes;
   byte code_data[1];
} SIMLOCK_ADD_LOCK_CODES_HCK_CMD_Request_Payload;

typedef SIMLOCK_Response_Payload SIMLOCK_ADD_LOCK_CODES_HCK_CMD_Response_Payload;

typedef struct
{
   SIMLOCK_Common_Request_Header header;
   byte slot;
   byte category;
   byte blacklist;
} SIMLOCK_ADD_LOCK_CODES_CK_CMD_HEADER;

typedef SIMLOCK_Response_Payload SIMLOCK_ADD_LOCK_CODES_CK_CMD_Response_Payload;
/******************************************************************************
SW Download - Streaming Download subsystem

For complete command list, please refer to 80-39912-1

*******************************************************************************/
/**
definitions of legal streaming download protocol commands
*/
typedef enum
{
   WRITE_CMD          = 1,      /* Write command                - sent */
   ACK_CMD            = 2,      /* ACK command                  - recv */
   NAK_CMD            = 3,      /* NAK command                  - recv */
   ERASE_CMD          = 4,      /* Erase command                - sent */
   GO_CMD             = 5,      /* Go command                   - sent */
   NOP_CMD            = 6,      /* NOP command                  - sent */
   PARAM_REQ          = 7,      /* Parameter request command    - sent */
   PARAM_RSP          = 8,      /* Parameter response command   - recv */
   RESET_CMD          = 10,     /* Reset command                - sent */
   UNLOCK_CMD         = 11,     /* Unlock command               - sent */
   SW_VER_REQ         = 12,     /* Software version request     - sent */
   SW_VER_RSP         = 13,     /* Software version response    - recv */
   PWR_DOWN_REQ   = 14,     /* Power Down request           - sent */
   WRITE_CMD32        = 15,     /* Write 32-bit command         - sent */
   MEMORY_DEBUG_REQ  =  16,     /* Memory debug query           - sent */
   MEMORY_DEBUG_RSP  =  17,     /* Memory debug info            - recv */
   MEMORY_READ_REQ   =  18,     /* Memory read request          - sent */
   MEMORY_READ_RSP   =  19,     /* Memory read response         - recv */
   FACTORY_TOKEN_CMD = 27,      /* Sets token for factory tools = sent */
   ERASE_EMMC_CMD    =  28      /* Erase Information command    - sent.  Only applies to QRD Targets at the moment */
} Download_Protocol_Cmd_Enum;

/******************************************************************************
SW Download - Streaming Download subsystem

For complete command list, please refer to 80-V5348-1

*******************************************************************************/
/**
definitions of legal streaming download protocol commands
*/
typedef enum
{
   HELLO_CMD =          0x1,                //!< ' Hello command                 - sent */
   HELLO_RSP_CMD =      0x2,                //!< ' Hello command response        - recv */
   READ_CMD =           0x3,                //!< ' Read command                  - sent */
   READ_RSP_CMD =       0x4,                //!< ' Read command response         - recv */
   S_WRITE_CMD =        0x5,                //!< ' Simple write command          - sent */
   S_WRITE_RSP_CMD =    0x6,                //!< ' Simple write command response - recv */
   STRM_WRITE_CMD =     0x7,                //!< ' Stream write command          - sent */
   STRM_WRITE_RSP_CMD = 0x8,                //!< ' Stream write command response - recv */
   STRM_NOP_CMD =            0x9,               //!< ' NOP command                   - sent */
   STRM_NOP_RSP_CMD =        0xa,               //!< ' NOP command response          - recv */
   STRM_RESET_CMD =          0xb,               //!< ' Reset command                 - sent */
   STRM_RESET_RSP_CMD =      0xc,               //!< ' Reset command response        - recv */
   ERROR_CMD =          0xd,                //!< ' Error response                - recv */
   LOG_CMD =            0xe,                //!< ' Log response                  - recv */
   STRM_UNLOCK_CMD =         0xf,               //!< ' Unlock command                - sent */
   UNLOCK_RSP_CMD =    0x10,                //!< ' Unlock command response       - recv */
   POWER_OFF_CMD =     0x11,                //!< ' Power off command             - sent */
   POWER_OFF_RSP_CMD = 0x12,                //!< ' Power off command response    - recv */
   DWNLDR_OPEN_CMD =   0x13,                //!< ' Open downloader               - sent */
   DWNLDR_OPEN_RSP_CMD = 0x14,              //!< ' Open downloader response      - recv */
   DWNLDR_CLOSE_CMD =  0x15,                //!< ' Close downloader              - sent */
   DWNLDR_CLOSE_RSP_CMD = 0x16,         //!< ' Close downloader response     - recv */
   DWNLDR_SECURITY_MODE_CMD = 0x17,     //!< ' Multi-image security mode          - sent
   DWNLDR_SECURITY_MODE_RSP_CMD = 0x18, //!< ' Multi-image security mode response - recv
   DWNLDR_PRTN_TBL_CMD = 0x19,              //!< ' Multi-image partition command      - sent
   DWNLDR_PRTN_TBL_RSP_CMD = 0x1A,          //!< ' Multi-image partition response     - recv
   DWNLDR_MULTI_IMG_OPEN_CMD = 0x1B,        //!< ' Multi-image open command           - sent
   DWNLDR_MULTI_IMG_OPEN_RSP_CMD = 0x1C,    //!< ' Multi-image open response          - recv
   DWNLDR_FLASH_ERASE_CMD = 0x1D,           //!< ' Erase flash (multi- to single- d/l) cmd
   DWNLDR_FLASH_ERASE_RSP_CMD = 0x1E,       //!< ' Erase flash response
   QFPROM_WRITE_CMD         = 0x32,         //!< ' QFPROM write command - sent
   QFPROM_WRITE_RSP_CMD     = 0x33,         //!< ' QFPROM write response = recv
   QFPROM_READ_CMD          = 0x34,         //!< ' QFPROM read command - sent
   QFPROM_READ_RSP_CMD      = 0x35          //!< ' QFPROM read response = recv
} Streaming_Download_Cmd_Enum;

/******************************************************************************
SW Download - Sahara Download subsystem

For complete command list, please refer to 80-N1008-1

*******************************************************************************/
/**
definitions of legal sahara download protocol commands
*/
typedef enum
{
   SAHARA_HELLO_REQ      =0x1,
   SAHARA_HELLO_RSP      =0x2,
   SAHARA_READ_DATA      =0x3,
   SAHARA_END_TRANSFER   =0x4,
   SAHARA_DONE_REQ       =0x5,
   SAHARA_DONE_RSP       =0x6,
   SAHARA_RESET_REQ      =0x7,
   SAHARA_RESET_RSP      =0x8,
   SAHARA_MEMORY_DEBUG   =0x9,
   SAHARA_MEMORY_READ    =0xA,
   SAHARA_CMD_READY      =0xB,
   SAHARA_SWITCH_MODE    =0xC,
   SAHARA_EXECUTE_REQ    =0xD,
   SAHARA_EXECUTE_RSP    =0xE,
   SAHARA_EXECUTE_DATA   =0xF,
   SAHARA_MEMORY_DEBUG_64=0x10,
   SAHARA_MEMORY_READ_64 =0x11,
   SAHARA_READ_DATA_64   =0x12,
} Sahara_Protocol_Cmd_Enum;

/**
QMSL_DownloadAgent_Error_Enum

Errorcode returned by QLIB_QPHONEMS_UploadSB1MultiImage and QLIB_QPHONEMS_UploadSB2MultiImage
*/
typedef enum
{
   QMSL_DOWNLOAD_NO_ERROR                       = 0x0000,
   QMSL_DOWNLOAD_FILE_NOT_FOUND             = 0x0001,
   QMSL_DOWNLOAD_FILE_TYPE_NOT_SUPPORT          = 0x0002,
   QMSL_DOWNLOAD_FAIL_TO_SET_SECURITY_MODE      = 0x0003,
   QMSL_DOWNLOAD_FAIL_TO_SEND_PARTITION     = 0x0004,
   QMSL_DOWNLOAD_FAIL_TO_SEND_DBL               = 0x0005,
   QMSL_DOWNLOAD_FAIL_TO_SEND_OSBL              = 0x0006,
   QMSL_DOWNLOAD_FAIL_TO_SEND_FSBL              = 0x0007,
   QMSL_DOWNLOAD_FAIL_TO_SEND_MODEM         = 0x0008,
   QMSL_DOWNLOAD_FAIL_TO_GET_AMSS_VERSION       = 0x0009,
   QMSL_DOWNLOAD_FAIL_TO_SEND_DIAG_DOWDLOAD_CMD = 0x000a,
   QMSL_DOWNLOAD_FAIL_TO_SEND_DIAG_OFFLINE_CMD   = 0x000b,
   QMSL_DOWNLOAD_FAIL_TO_REPOPEN_PORT           = 0x000c,
   QMSL_DOWNLOAD_FAIL_TO_DOWNLOAD_ARMPRG        = 0x000d,
   QMSL_DOWNLOAD_FAIL_TO_FETCH_DL_PARAM     = 0x000e,
   QMSL_DOWNLOAD_NO_HELLO_COMMAND_RESPONSE      = 0x000f,
   QMSL_DOWNLOAD_FAIL_TO_SEND_DSP1              = 0x0010,
   QMSL_DOWNLOAD_FAIL_TO_SEND_DSP2              = 0x0011,
   QMSL_DOWNLOAD_FAIL_TO_SEND_PBL               = 0x0012,
   QMSL_DOWNLOAD_FAIL_TO_SEND_QCSBL         = 0x0013,
   QMSL_DOWNLOAD_FAIL_TO_SEND_QCSBLH            = 0x0014,
   QMSL_DOWNLOAD_FAIL_TO_SEND_OEMSBL            = 0x0016,
   QMSL_DOWNLOAD_FAIL_TO_SEND_APPS_BOOTLOADER  = 0x0017,
   QMSL_DOWNLOAD_FAIL_TO_SEND_APPS              = 0x0018,
   QMSL_DOWNLOAD_FAIL_TO_SEND_WINMOBILE     = 0x0019,
   QMSL_DOWNLOAD_ERROR_UNKNOWN                  = 0x001a,
   QMSL_DOWNLOAD_FAIL_TO_SEND_CEFS_MODEM        = 0x001b
} QMSL_DownloadAgent_Error_Enum;

//structure providing information about the .mbn files that are going to be programmed into the device.
//At the moment, limit is set to 10 files on the partition name / parition files. Please use the SWDL_UserPartitionList structre.
//sPartitionName will contain the partition name. Note: Use the "0:SBL1" as the first partition name. the partition string must be null terminated!
//sPartitionMBNPath will contain the mbn file path.

typedef struct
{
   char sPartitionName[129];                   // PartitionName For example, 0:SBL1
   char sPartitionMBNPath[256];               // Path to the mbn files
} SWDL_UserPartitionEntry;

typedef struct
{
   SWDL_UserPartitionEntry oPartitionList[10];
   int  iNumOfPartitionEntry;
} SWDL_UserPartitionList;

typedef struct
{
   //Requires File Name only
   char ImageFileName[256];
   char SHA256Hash[129];
} SWDL_UserPartitionHash;

typedef struct
{
   SWDL_UserPartitionHash pFileHashList[128];
   int  iNumOfFileHashEntry;
} SWDL_UserPartitionHashList;

/* FireHose Partition File List Defination */
typedef struct
{
   char RawProgramFileName[256];
   char PatchFileName[256] ;
} SWDL_eMMC_UserPartitionFileEntry;

typedef struct
{
   SWDL_eMMC_UserPartitionFileEntry pFileList[10];
   int  iNumOfPartitionEntry;
} SWDL_eMMC_UserPartitionList;

typedef struct
{
   char SearchFileName[256];
} SWDL_eMMC_MetaBuild_SearchFileEntry;

typedef struct
{
   SWDL_eMMC_MetaBuild_SearchFileEntry pFileList[200];
   int  iNumOfSearchFileEntry;
} SWDL_eMMC_MetaBuild_SearchFileList;

typedef struct
{
   SWDL_eMMC_MetaBuild_SearchFileList pSearchFileList;
   SWDL_eMMC_UserPartitionList pUserPartitionFileList;
} SWDL_eMMC_MetaBuild_Content;

/******************************************************************************
Diagnostic - GPS Subsystem
*******************************************************************************/

/*
GPS sub system commands, from Services\LSM\diag_pdapi.h
*/
typedef enum
{
   _GPS_START_CMD               = 0x0000,
   _GPS_END_CMD             = 0x0001,
   _GPS_STATE_CMD               = 0x0002,
   _GPS_SET_NV_PARAM_CMD        = 0x0003,
   _GPS_GET_LAST_KNOWN_POS_CMD  = 0x0004,

   _GPS_GET_PDSM_PARAMS_CMD = 0x0006,
   _GPS_PDSM_TCP_SOCKET_CMD = 0x0007,
   _GPS_DIAG_START_TASK     = 0x0008,
   _GPS_DIAG_END_TASK           = 0x000C,
   _GPS_DIAG_TEST_API_CMD       = 0x000D,
   _GPS_NOTIFY_VERIFY_SEND_USER_ACTION      =   0x0010,
   _GPS_API_CMD             = 0x0011,
   _GPS_SET_TEST_MODE_PARAMS    = 0x0012,
   _GPS_USE_THIS_POS            = 0x0013
} GPS_Cmd_Enum;

/******************************************************************************
Diagnostic - Call Manager subsytem
*******************************************************************************/

//! Call states, used by QLIB_DIAG_GSM_STATUS_F and QLIB_GetPhoneCallState
typedef enum
{
   CM_CALL_STATE_NONE   = -1,       //!< 'FOR INTERNAL USE OF CM ONLY!
   CM_CALL_STATE_IDLE   = 0,        //!< ' Call is in idle state - i.e. no call
   CM_CALL_STATE_ORIG   = 1,        //!< ' Call is in origination state
   CM_CALL_STATE_INCOM  = 3,        //!< ' Call is in alerting state
   CM_CALL_STATE_CC_IN_PROGRESS = 4,    //!< ' Call is originating but waiting for call control to complete
   CM_CALL_STATE_CONV   = 5,        //!< ' Call is in conversation state
   CM_CALL_STATE_MAX                    //!< ' FOR INTERNAL USE OF CM ONLY!
} cm_call_state_enum;

//! System operating modes, from services/cm/sys.h
typedef enum
{
   SYS_OPRT_MODE_NONE   = -1,       //!< ' FOR INTERNAL USE OF CM ONLY!
   SYS_OPRT_MODE_PWROFF = 0,        //!< ' Phone is powering off
   SYS_OPRT_MODE_FTM        = 1,        //!< ' Phone is in factory test mode
   SYS_OPRT_MODE_OFFLINE    = 2,        //!< ' Phone is offline
   SYS_OPRT_MODE_OFFLINE_AMPS = 3,  //!< ' Phone is offline analog
   SYS_OPRT_MODE_OFFLINE_CDMA = 4,  //!< ' Phone is offline cdma
   SYS_OPRT_MODE_ONLINE = 5,            //!< ' Phone is online
   SYS_OPRT_MODE_LPM = 6,           //!< ' Phone is in LPM - Low Power Mode
   SYS_OPRT_MODE_RESET = 7,         //!< ' Phone is resetting - i.e. power-cycling
   SYS_OPRT_MODE_NET_TEST_GW = 8,   //!< ' Phone is conducting network test for GSM/WCDMA.
   SYS_OPRT_MODE_OFFLINE_IF_NOT_FTM = 9,    //!< ' offline request during powerup.
   SYS_OPRT_MODE_PSEUDO_ONLINE = 10,    //!< ' Phone is pseudo online, tx disabled
   SYS_OPRT_MODE_MAX = 11,              //!< ' FOR INTERNAL USE OF CM ONLY!
   SYS_OPRT_MODE_APQ_DIAG_ALIVE = 12,       //!< 'Defined by QMSL, not by AMSS, indicate AMSS diag service is alive
   SYS_OPRT_MODE_APQ_DIAG_NO_RESPONSE = 13      //!< 'Defined by QMSL, not by AMSS, indicate AMSS diag service is dead (no diag response)
} sys_oprt_mode_enum;

//! System modes, from services/cm/sys.h
typedef enum
{
   SYS_SYS_MODE_NONE        = -1,       //!< ' FOR INTERNAL USE ONLY!
   SYS_SYS_MODE_NO_SRV  = 0,        //!< ' No service = NV_MODE_INACTIVE
   SYS_SYS_MODE_AMPS        = 1,        //!< ' Analog Mobile Phone System (AMPS) mode
   SYS_SYS_MODE_CDMA        = 2,        //!< ' Code Division Multiple Access (CDMA) mode
   SYS_SYS_MODE_GSM     = 3,        //!< ' Global System for Mobile communications (GSM) mode
   SYS_SYS_MODE_HDR     = 4,        //!< ' High Data Rate (HDR) mode
   SYS_SYS_MODE_WCDMA   = 5,        //!< ' Wideband CDMA (WCDMA) mode
   SYS_SYS_MODE_GPS     = 6,        //!< ' Global Positioning System (GPS) mode
   SYS_SYS_MODE_GW      = 7,        //!< ' GSM and WCDMA mode
   SYS_SYS_MODE_WLAN    = 8,        //!< ' WLAN mode
   SYS_SYS_MODE_LTE     = 9,        //!< ' LTE
   SYS_SYS_MODE_GWL     = 10,   //!< ' GSM, WCDMA and LTE mode
   SYS_SYS_MODE_TDS     = 11,    //!< ' TD-SCDMA mode
   SYS_SYS_MODE_MAX                 //!< ' FOR INTERNAL USE ONLY!
} sys_sys_mode_enum;

//! For use by QLIB_DIAG_GSM_STATUS_F, defined in 80-V5295-1, section 3.2.4
typedef enum
{
   GSM_STATUS_CALL_STATE_NONE           = -1,   //!< ' not defined
   GSM_STATUS_CALL_STATE_IDLE           = 0,    //!< ' IDLE
   GSM_STATUS_CALL_STATE_ORIG           = 1,    //!< ' Originating
   GSM_STATUS_CALL_STATE_WAITING        = 2,    //!< ' Waiting
   GSM_STATUS_CALL_STATE_INCOM          = 3,    //!< ' Incoming
   GSM_STATUS_CALL_STATE_CC_IN_PROGRESS = 4,    //!< ' Concurrent incoming/originating
   GSM_STATUS_CALL_STATE_CONV           = 5 //!< ' Conversation
} gsm_call_state_enum;

/**
Call Origination, see Call Manager ICD 3.4.50

*/

typedef enum
{
   _DIAG_CALL_ORIGINATION_SO_ID_IS96                           = 1,
   _DIAG_CALL_ORIGINATION_SO_ID_8K_LOOPBACK                    = 2,
   _DIAG_CALL_ORIGINATION_SO_ID_MARKOV                         = 3,
   _DIAG_CALL_ORIGINATION_SO_ID_RESERVED                       = 4,
   _DIAG_CALL_ORIGINATION_SO_ID_VOICE_IS96A                    = 5,
   _DIAG_CALL_ORIGINATION_SO_ID_VOICE_13K                      = 6,
   _DIAG_CALL_ORIGINATION_SO_ID_RATESET2_MARKOV                = 7,
   _DIAG_CALL_ORIGINATION_SO_ID_RATESET1_MARKOV                = 8,
   _DIAG_CALL_ORIGINATION_SO_ID_13K_LOOPBACK                   = 9,
   _DIAG_CALL_ORIGINATION_SO_ID_13K_MARKOV                     = 10,
   _DIAG_CALL_ORIGINATION_SO_ID_EVRC                           = 11,
   _DIAG_CALL_ORIGINATION_SO_ID_RATESET2_SMS                   = 14,
   _DIAG_CALL_ORIGINATION_SO_ID_13K_VOICE                      = 17,
   _DIAG_CALL_ORIGINATION_SO_ID_MDR_RS1FWD_RS1REV              = 22,
   _DIAG_CALL_ORIGINATION_SO_ID_MDR_RS1FWD_RS2REV              = 23,
   _DIAG_CALL_ORIGINATION_SO_ID_MDR_RS2FWD_RS1REV              = 24,
   _DIAG_CALL_ORIGINATION_SO_ID_MDR_RS2FWD_RS2REV              = 25,
   _DIAG_CALL_ORIGINATION_SO_ID_MDR_RS1FWD_RS1REV_DATAPATTERN  = 36,
   _DIAG_CALL_ORIGINATION_SO_ID_MDR_RS2FWD_RS2REV_DATAPATTERN  = 37,
   _DIAG_CALL_ORIGINATION_SO_ID_IS2000_MARKOV                  = 54,
   _DIAG_CALL_ORIGINATION_SO_ID_IS2000_LOOPBACK                = 55,
   _DIAG_CALL_ORIGINATION_SO_ID_4GV_NARROWBAND                 = 68,
   _DIAG_CALL_ORIGINATION_SO_ID_SMS                            = 65534
} Diag_call_origination_serice_option_enum_type;

typedef enum
{
   CM_CALL_TYPE_VOICE = 0,
   CM_CALL_TYPE_CS_DATA = 1,
   CM_CALL_TYPE_PS_DATA = 2,
   CM_CALL_TYPE_SMS = 3,
   CM_CALL_TYPE_PD = 4,
   CM_CALL_TYPE_TEST = 5,
   CM_CALL_TYPE_OTAPA = 6,
   CM_CALL_TYPE_STD_OTAPA = 7,
   CM_CALL_TYPE_NON_STD_OTAPA = 8,
   CM_CALL_TYPE_EMERGENCY = 9,
   CM_CALL_TYPE_SUPS = 10,
   CM_CALL_TYPE_VT = 11,
   CM_CALL_TYPE_VT_LOOPBACK = 12,
   CM_CALL_TYPE_VIDEO_SHARE = 13
} CM_CALL_TYPE_ENUM;

typedef struct
{
   byte call_id;
   byte call_type;
   byte call_state;
   byte ps_call_dormant;
} CM_Call_Record_Struct;

#define CM_GET_CALL_INFORMATION_LIST_MAX_NUM_CALLS 4

typedef struct
{
   byte cmd_code;
   byte subsys_id;
   word subsys_cmd_code;
   byte status;
   byte num_calls;
   CM_Call_Record_Struct call_records[CM_GET_CALL_INFORMATION_LIST_MAX_NUM_CALLS];
} CM_Get_Call_Information_List_Resp_Struct;

/******************************************************************************
Diagnostic - LTE subsytem
*******************************************************************************/
typedef enum
{
   _LTE_RX_TOOL_CHAIN_COMMAND = 0x4000,

   _LTE_CMD_ID_END_OF_ENUM
} lte_subsys_cmd_id_enum;

typedef enum
{
   _LTE_RX_CHAIN_TYPE_NO_ACTION = 0,
   _LTE_RX_CHAIN_TYPE_ENABLE_RX0_ONLY = 1,
   _LTE_RX_CHAIN_TYPE_ENABLE_RX1_ONLY = 2,
   _LTE_RX_CHAIN_TYPE_ENABLE_RX0_AND_RX1 = 3,
   _LTE_RX_CHAIN_TYPE_NO_ACTION2 = 4,
   _LTE_RX_CHAIN_TYPE_DISABLE_RX0_ONLY = 5,
   _LTE_RX_CHAIN_TYPE_DISABLE_RX1_ONLY = 6,
   _LTE_RX_CHAIN_TYPE_DISABLE_RX0_AND_RX1 = 7,
   _LTE_RX_CHAIN_TYPE_END_OF_ENUM
} lte_rx_chain_type_enum_type;

/******************************************************************************
Diagnostic - HDR subsytem
*******************************************************************************/
//! QCT HDR Subsystem command IDs (80-V1294-2) Table 2.1
typedef enum
{
   _HDR_RST_ACCESS_CNT                  = 0,
   _HDR_RST_FWD_STATS                   = 1,
   _HDR_RST_RTC_RATE_CNT                = 2,
   _HDR_RST_CONN_ATTEMPT_CNT            = 3,
   _HDR_RST_PAGE_MSG_CNT                = 4,
   _HDR_RST_SESSION_ATTEMPT_CNT     = 5,
   _HDR_RST_RLP_STATS                   = 6,
   _HDR_AT_CONFIG                       = 7,
   _HDR_STATE                           = 8,
   _HDR_DIP_SWITCH                      = 9,
   _HDR_MCS_FLOW_COMMAND                = 10,
   _HDR_MCS_DEBUG_COMMAND               = 11,
   _HDR_MCS_CLR_STATS_COMMAND           = 12,
   _HDR_RST_CONNECTED                   = 13
} hdr_subsys_cmd_id_enum;

/******************************************************************************
Diagnostic - GSM subsytem
*******************************************************************************/

// Constants for GSM Diag
#define GSM_DIAG_IMEI_SIZE  9
#define GSM_DIAG_IMSI_SIZE  9
#define GSM_DIAG_LAI_SIZE   5
#define GSM_DIAG_CALL_ORG_IMSI_SIZE 32

/**
GSM Diagnostic commands, from Services\diag\gsmdiag.h

*/
typedef enum
{
   _GSM_DIAG_VERNO_F           = 0,
   _GSM_STATUS_F               = 1,
   _GSM_TMC_STATE_RETRIEVAL_F  = 2,
   _GSM_DIAG_CALL_ORIG_F       = 3,
   _GSM_DIAG_CALL_END_F        = 4,
   _GSM_GPRS_LOG_PACKET_REQ_F  = 5
} DiagGsmCmd_Enum;

/******************************************************************************
Diagnostic - MediaFLO subsytem
*******************************************************************************/

/**
MediaFLO Diagnostic commands, from mflog.h

*/
typedef enum
{
   _MFLO_RST_PLP_STATS                  = 0,    //!< ' Reset Total/Bad PLP counters                */
   _MFLO_GET_FLO_STATE                  = 1,    //!< ' Get FLO State                               */
   _MFLO_START_FLO                      = 2,    //!< ' Start FLO                                   */
   _MFLO_GET_FLO_VERSION_INFO           = 6,    //!< ' Get the FLO H/W & S/W Versions              */
   _MFLO_ACTIVATE_FLOW                  = 9,    //!< ' Start decoding FLOW                         */
   _MFLO_DEACTIVATE_FLOW                = 10,   //!< ' Stop decoding FLOW                          */
   _MFLO_GET_BOUND_FLOW_LIST            = 11,   //!< ' Get Bound FLOW List                         */
   _MFLO_GET_MLC_INFO                   = 12,   //!< ' Get MLC Info                                */
   _MFLO_GET_RSSI_VALUE                 = 13,   //!< ' Get RSSI Value                              */
   _MFLO_GET_MLC_PLP_STAT_DYN_PARAMS    = 14,   //!< ' Get MLC PLPs/CBs stats                      */
   _MFLO_SET_RF_CHNL                    = 15,   //!< ' Set RF Channel                              */
   _MFLO_GET_RF_CHNL                    = 16,   //!< ' Get RF Channel                              */
   _MFLO_RST_MLC_PLP_STATS              = 17,   //!< ' Reset MLC Total/Bad PLP counters            */
   _MFLO_GET_MLC_DYN_PARAMS             = 18,   //!< ' Get MLC Dynamic Parameters                  */
   _MFLO_GET_OIS_PLP_STAT               = 21,   //!< ' Get PLP stats for OIS channel               */
   _MFLO_RST_OIS_PLP_STAT               = 22,   //!< ' Reset PLP stats for OIS channel             */
   _MFLO_GET_FLO_SUBSTATE               = 39,   //!< ' Get FLO SUB State                           */
   _MFLO_GET_ACTIVE_MLC_LIST            = 40,   //!< ' Get MLCs Info for the all active ones       */
   _MFLO_GET_FLO_PLP_DYN_PARAMS         = 43,   //!< ' Get PLP Params based on FLOW Id             */
   _MFLO_ENABLE_FTAP_PLP_DATA           = 44,   //!< ' Enable PacketRecord logging mode            */
   _MFLO_ENABLE_FTAP_OIS                = 45,   //!< ' Enable OIS logging mode                     */
   _MFLO_ENABLE_WIC_LIC                 = 46,   //!< ' Enable FTAP WIC/LIC Logging                 */
   _MFLO_FTAP_ACTIVATE_FLOW             = 48,   //!< ' Activate FTAP FLOW                          */
   _MFLO_GET_CONTROL_CHANNEL_DATA       = 54,   //!< ' Enable Control Channel Data logging         */
   _MFLO_GET_PLATFORM_CONFIG            = 127,  //!< ' Get the platform configuration information  */
   _MFLO_GET_CI_AVG                     = 131,  //!< ' Get the C/I Average                         */
   _MFLO_FTM_SET_DEMOD_CONFIG           = 200,  //!< ' Sets the demodulation configuration         */
   _MFLO_FTM_RF_INITIALIZE              = 201,  //!< ' Initialize the FLO calibration driver       */
   _MFLO_FTM_GET_PLL_LOCK_STATUS        = 202,  //!< ' Get the current state of the RF Synth PLL   */
   _MFLO_FTM_TUNE_RF_IN_HZ              = 203,  //!< ' Tunes the RF Frequency in Hz                */
   _MFLO_FTM_GET_RSSI                   = 204,  //!< ' Get RSSI value                              */
   _MFLO_FTM_GET_AGC_STATE              = 205,  //!< ' Get the current state of the AGC            */
   _MFLO_FTM_GET_RSSI_CAL_POINT         = 206,  //!< ' Get RSSI calibration point                  */
   _MFLO_FTM_LOAD_RSSI_CAL_POINT        = 207,  //!< ' Load a cal point into memory.               */
   _MFLO_FTM_LOAD_AGC_CAL_CHAN_LIST     = 208,  //!< ' Loads the cal. channel list into memory     */
   _MFLO_FTM_WRITE_CAL_DATA_TO_NV       = 209,  //!< ' Write the requested calibration data to NV  */
   _MFLO_FTM_SET_GAIN_STATE             = 210,  //!< ' Set the AGC gain state to a fixed state     */
   _MFLO_FTM_SET_AGC_DEFAULT            = 211,  //!< ' Set the AGC gain state to automatic         */
   _MFLO_FTM_SET_AGC_GAIN_TRACKING      = 212,  //!< ' Enable/disable AGC Gain Tracking            */
   _MFLO_FTM_LNA_SELECT                 = 213,  //!< ' Set the LNA selection for a given RF mode   */
   _MFLO_FTM_SET_ANT_TUNE               = 214,  //!< ' Set the Antenna Tune for a given RF mode    */
   _MFLO_FTM_NS_SET_NS_MODE             = 250,  //!< ' NS - Enables FLO Demod during FTM Mode      */
   _MFLO_FTM_NS_ACQUIRE_FLO_SYSTEM      = 251,  //!< ' NS - Acquire FLO system                     */
   _MFLO_FTM_NS_ACTIVATE_FLOW           = 252,  //!< ' NS - Activate FLO                           */
   _MFLO_FTM_NS_DEACTIVATE_FLOW         = 253,  //!< ' NS - Deactivate FLO                         */
   _MFLO_FTM_NS_TUNE_FREQ_AND_BW        = 254,  //!< ' NS - Tune frequency and bandwidth           */
   _MFLO_FTM_NS_GET_RSSI_AND_GAIN_STATE = 255,  //!< ' NS - Get RSSI and Gain State                */
   _MFLO_FTM_NS_GET_STREAM_INFO         = 256,  //!< ' NS - Get stream information                 */
   _MFLO_FTM_NS_GET_MLC_DYN_PARAMS      = 257,  //!< ' NS - Get MLC dynamic parameters             */
   _MFLO_FTM_NS_RESET_MLC_PLP_STATS     = 259,  //!< ' NS - Reset MLC PLP stats                    */
   _MFLO_FTM_NS_RESET_ALL_PLP_STATS     = 260,  //!< ' NS - Reset all PLP stats                    */
   _MFLO_FTM_NS_GET_ALL_ACTIVE_FLOW_IDS = 261,  //!< ' NS - Get all active flow ids                */
   _MFLO_FTM_NS_GET_OIS_STATE           = 263,  //!< ' NS - Get OIS State                          */
   _MFLO_FTM_NS_ENABLE_FTAP_PLP_DATA    = 264,  //!< ' NS - Start/stop FTAP data packet logging    */
   _MFLO_FTM_NS_SET_FLO_SLEEP           = 265,  //!< ' NS - Set FLO sleep                          */
   _MFLO_FTM_NS_SET_JAMMER_DETECT_MODE  = 266,  //!< ' NS - Set the jammer detect mode             */
   _MFLO_FTM_NS_SET_AGC_GAIN_TRACKING   = 267,  //!< ' NS - Enable/disable AGC Gain Tracking       */
   _MFLO_FTM_NS_FREEZE_GAIN_STATE       = 268,  //!< ' NS - Freeze the AGC gain state              */
   _MFLO_FTM_GET_FLO_FTM_STATE          = 269,  //!< ' Get the FLO FTM state                       */
   _MFLO_FTM_NS_GET_JAMMER_DETECT_STATE = 270   //!< ' NS - Get the jammer detect state            */
} mflo_diag_subsys_cmd_enum_type;

/**
MediaFLO Log Codes, from mflog.h

*/
#define LOG_MFLO_RSSI_VALUE_DYNAMIC_PARAMS_C        0x11F5
#define LOG_MFLO_FTAP_PACKETRECORD_HEADER_PARAMS_C  0x120C
#define LOG_MFLO_FTAP_PACKETRECORD_PARAMS_C         0x120D
#define LOG_MFLO_FTAP_WOIS_PARAMS_C                 0x120E
#define LOG_MFLO_FTAP_LOIS_PARAMS_C                 0x120F
#define LOG_MFLO_FTAP_WID_LID_PARAMS_C              0x1210
#define LOG_MFLO_FDM_RECORDS_C                      0x121F

#define MFLO_MAX_LOG_PACKET_SIZE                    1542
#define MFLO_MAX_FTAP_PACKET_RECORDS                111
#define MFLO_FIRST_LAYERED_FLO_TX_MODE              6
#define MFLO_LAST_LAYERED_FLO_TX_MODE               11
#define MFLO_FIRST_LAYERED_FLO_EV_TX_MODE           80
#define MFLO_MAX_MLC_FLOW_MAPPING_RECORDS           80

//! MediaFLO Binding type
typedef enum
{
   MFLO_OVERHEAD   = 0x00,
   RT_VIDEO_CODEC  = 0x01,
   RT_AUDIO_CODEC  = 0x02,
   NRT_MEDIA       = 0x03,
   DATACAST        = 0x04,
   TAP             = 0x05,
   FIXED_TAP       = 0x06,
   NOT_BOUND       = 0xFF
} mftypes_binding_type;

//! MediaFLO System type
typedef enum
{
   WOIS             = 0x00,     //! Wide System
   WIDE             = 0x00,     //! Wide System
   LOIS             = 0x01,     //! Local System
   LOCAL            = 0x01,     //! Local System
   WIDE_AND_LOCAL   = 0x02
} mftypes_system_type;

//! MediaFLO State type
typedef enum
{
   INVALID_STATE        = 0x00,
   ACQUIRING_STATE      = 0x01,
   IDLE_STATE           = 0x02,
   ACTIVE_STATE         = 0x03,
   UNAVAILABLE_STATE    = 0x04,
   VARIABLE_NOT_SET     = 0xFF  //! Used when a function to get the state fails
} mftypes_state_type;

//! MediaFLO Transmit mode type
typedef enum
{
   REG_QPSK_1_3         = 0,
   MREG_QPSK_1_2        = 1,
   REG_16_QAM_1_3       = 2,
   REG_16_QAM_1_2       = 3,
   REG_16_QAM_2_3       = 4,
   REG_16_QPSK_1_5      = 5,
   LAY_QPSK_1_3_ER_4    = 6,
   LAY_QPSK_1_2_ER_4    = 7,
   LAY_QPSK_2_3_ER_4    = 8,
   LAY_QPSK_1_3_ER_6_25 = 9,
   LAY_QPSK_1_2_ER_6_25 = 10,
   LAY_QPSK_2_3_ER_6_25 = 11
} mftypes_trans_mode_type;

//! MediaFLO Activate Status type
typedef enum
{
   ACTIVATE_FAILED      = 0x00,
   ACTIVATING           = 0x01,
   ACTIVATE_SUCCESS     = 0x02
} mftypes_activate_status_type;

//! MediaFLO Flow Status type
typedef enum
{
   FLOW_NOT_ACTIVATED   = 0x00,
   FLOW_ACTIVATED       = 0x01,
   FLOW_DEACTIVATING    = 0x02
} mftypes_flow_status_type;

//! MediaFLO MLC Status type
typedef enum
{
   MLC_NOT_ACTIVE   = 0x00,
   MLC_ACTIVE       = 0x01
} mftypes_mlc_status_type;

//! MediaFLO Record Retrieval Status type
typedef enum
{
   NO_RECORDS_AVAILABLE = 0x00,
   RECORDS_RETRIEVED    = 0x01
} mftypes_record_retrieval_status_type;

//! MediaFLO Sleep Setting type
typedef enum
{
   SLEEP_AND_SNOOZE_DISABLED        = 0x00,
   SLEEP_ENABLED_SNOOZE_DISABLED    = 0x01,
   SLEEP_DISABLED_SNOOZE_ENABLED    = 0x02,
   SLEEP_ENABLED_SNOOZE_ENABLED     = 0x03
} mftypes_sleep_settings_type;

//! MediaFLO Structure to store MLC PLP statistics
typedef struct
{
   dword BasePlpsPreRsGood;
   dword BasePlpsPreRsErasures;
   dword BasePlpsPostRsGood;
   dword BasePlpsPostRsErasures;
   dword EnhPlpsPreRsGood;
   dword EnhPlpsPreRsErasures;
   dword EnhPlpsPostRsGood;
   dword EnhPlpsPostRsErasures;
   dword BaseCbsPreRsGood;
   dword BaseCbsPreRsErasures;
   dword BaseCbsPostRsGood;
   dword BaseCbsPostRsErasures;
   dword EnhCbsPreRsGood;
   dword EnhCbsPreRsErasures;
   dword EnhCbsPostRsGood;
   dword EnhCbsPostRsErasures;
} mftypes_mlc_plp_stats_type;

//! MediaFLO Structure to store NS PLP statistics
typedef struct
{
   dword PlpsPreRsGood;
   dword PlpsPreRsErasures;
   dword PlpsPostRsGood;
   dword PlpsPostRsErasures;
} mftypes_plp_stats_type;

//! MediaFLO Structure to store NS CB statistics
typedef struct
{
   dword CbsPostRsGood;
   dword CbsPostRsErasures;
} mftypes_cb_stats_type;

//! MediaFLO Protocol task's substate type
typedef enum
{
   SUBSTATE_IDLE        = 0x0,
   SUBSTATE_GET_OIS = 0x1,
   SUBSTATES_GET_CC = 0x2
} mftypes_substate;

//! MediaFLO OIS reception mode type
typedef enum
{
   DISABLE_WOIS_AND_LOIS    = 0x0,
   ENABLE_WOIS_ONLY     = 0x1,
   ENABLE_LOIS_ONLY     = 0x2,
   ENABLE_WOIS_AND_LOIS = 0x3
} mftypes_ois_reception_mode_type;

//! MediaFLO Reed-Solomon code type
typedef enum
{
   RS_16_16_0       = 0x0,
   RS_16_14_2       = 0x1,
   RS_16_12_4       = 0x2,
   RS_16_8_8        = 0x3
} mftypes_reed_solomon_code_type;

//! MediaFLO Structure to store MLC dynamic param info
typedef struct
{
   byte MlcID;
   dword BaseFFTaddress;
   word SymbolOffset;
   byte StartSlotOffset;
   byte MinSlot;
   byte MaxSlot;
   word NumSlots;
   byte NumCodeBlocks;
   mftypes_trans_mode_type TxMode;
   byte OuterCode;
   byte Stream1Bound;
   byte Stream2Bound;
   byte FFTframeCount;
} mftypes_mlc_dyn_params_type;

//! MediaFLO Structure to store info about active flows
typedef struct
{
   dword FlowID;
   byte MlcID;
   byte StreamID;
   byte StreamUsesBothLayers;
   byte ByteInterleaveEnabled;
   mftypes_binding_type BindingType;
   mftypes_system_type System;
} mftypes_active_flow_info;

//! MediaFLO Structure to store info about active MLCs
typedef struct
{
   dword Base_FFT_Address;
   mftypes_trans_mode_type TransmitMode;
   byte OuterCode;
   byte NumCbsInCurrentSF;
   mftypes_mlc_plp_stats_type MlcPlpStats;
   byte Stream1Bound;
   byte Stream2Bound;
} mftypes_active_mlc_info;

//! Structure to associate Flow ID, MLC ID, Tx Mode,
//! Base FTAP PLP per Superframe, Enhancement FTAP PLP per Superframe
typedef struct
{
   dword FlowID;
   byte MLC_ID;
   byte TxMode;
   word PLPperSuperframeBase;
   word PLPperSuperframeEnh;
} mftypes_mlc_schedule;

//! MediaFLO Structure to associate FTAP Sequence Numbers with their corresponding FTAP Test Signature
typedef struct
{
   dword FTAP_SequenceNumber;
   byte FTAP_TestSignature;
} mftypes_seq_vs_sig;

//! MediaFLO Structure to store the TAP Message Content for the FLO Tx Waveform
typedef struct
{
   byte NumberOfSuperframes;                // Number of superframes in the FLO Tx Waveform
   byte NumberOfFlowIDs;                    // Number of FlowIDs available to be decoded in the FLO Tx Waveform
   mftypes_mlc_schedule* pMLC_Schedule; // Structure which associates Flow ID, MLC ID, Tx Mode and PLP per superframe for the FLO Tx Waveform
   mftypes_seq_vs_sig* pSeq_vs_Sig;     // Structure which associates FTAP Sequence Numbers in the FLO Tx Waveform with their corresponding FTAP Test Signature
} mftypes_tap_msg_content;

//! MediaFLO Structure to store data for one Flow ID for one superframe while parsing log packets
typedef struct
{
   dword FlowID;                            // Flow ID corresponding to the statistics in this data structure
   word PLPperSuperframeBase;               // Number of Base PLPs in each superframe
   word PLPperSuperframeEnh;                // Number of Enhancement PLPs in each superframe
   mftypes_seq_vs_sig* pLoggedSeqVsSigBase;// Pointer to array of mftypes_seq_vs_sig structures to store Base FTAP Seq Num / FTAP Test Sig pairs
   mftypes_seq_vs_sig* pLoggedSeqVsSigEnh;  // Pointer to array of mftypes_seq_vs_sig structures to store Enhancement FTAP Seq Num / FTAP Test Sig pairs
   word BaseLength;                     // Number of Base FTAP Seq Num / FTAP Test Sig pairs recorded
   word EnhLength;                          // Number of Enhancement FTAP Seq Num /FTAP Test Sig pairs recorded
   byte* pMatches;                          // Pointer to byte array with length PLPperSuperframeBase * Number of Superframes
   word NumBasePLPs;                        // Number of Base PLPs recorded
   word NumEnhPLPs;                     // Number of Enhancement PLPs recorded
   word NumBaseErasures;                    // Number of Base erasures recorded
   word NumEnhErasures;                 // Number of Enhancement erasures recorded
   word NumBaseSeqSigErrors;                // Number of Base FTAP Seq Num / FTAP Test Sig errors recorded
   word NumEnhSeqSigErrors;             // Number of Enhancement FTAP Seq Num / FTAP Test Sig errors recorded
} mftypes_current_sf_stats;

//! MediaFLO Error code type
typedef enum
{
   NOT_AVAILABLE                                = 0,
   TAP_MSG_CONTENT_NOT_INITIALIZED              = 1,
   NO_LOG_PACKETS                               = 2,
   MEMORY_ALLOCATION_ERROR                      = 3,
   INVALID_NUMBER_OF_FLOW_IDS                   = 4,
   RCVD_LOGPACKET_FOR_INVALID_FLOWID            = 5,
   PLP_STATS_ALL_ZERO                           = 6,
   INVALID_REED_SOLOMON_TYPE                    = 7,
   INVALID_NUMBER_OF_PLP_RECORDS                = 8,
   MISSING_LOG_PACKETS                          = 9,
   PLP_STATS_NOT_UPDATING                       = 10
} mftypes_error_code;

//! MediaFLO Type of PER to measure
typedef enum
{
   BASE_ONLY                    = 0,
   ENHANCEMENT_ONLY         = 1,
   BASE_AND_ENHANCEMENT     = 2
} mftypes_per_to_measure;

//! MediaFLO Reed Solomon type
typedef enum
{
   PRE_REED_SOLOMON         = 0,
   POST_REED_SOLOMON            = 1,
   PRE_OR_POST_REED_SOLOMON = 2
} mftypes_reed_solomon;

//! MediaFLO PER measurement result
typedef enum
{
   FAILED               = 0,
   PASSED               = 1,
   KEEP_TESTING     = 2
} mftypes_per_result;

//! MediaFLO control channel message type
typedef enum
{
   MFCC_FDM             = 0x00,
   MFCC_RDM             = 0x01,
   MFCC_NDM             = 0x02,
   MFCC_FILLER          = 0x03,
   MFCC_FMS             = 0xEF
} mftypes_cc_msg_type;

//! MediaFLO Structure for holding the overall PER statistics for the current measurement
typedef struct
{
   dword iFlowID;                   //! Flow ID corresponding to the statistics in this data structure
   double dPER_Base;                //! Base Layer Packet Error Rate for all superframes
   double dPER_Enh;             //! Enhancement Layer Packet Error Rate for all superframes
   dword iTotalPLPBase;             //! Total number of Base Layer PLPs recorded
   dword iTotalPLPEnh;          //! Total number of Enhancement Layer PLPs recorded
   dword iTotalErrorsBase;      //! Total number of Base Layer Errors recorded (includes erasures and mismatched FTAP_SequenceNumber / FTAP_TestSignature pairs)
   dword iTotalErrorsEnh;           //! Total number of Enhancement Layer Errors recorded (includes erasures and mismatched FTAP_SequenceNumber / FTAP_TestSignature pairs)
   dword iTotalErasuresBase;        //! Total number of Base Layer Erasures recorded
   dword iTotalErasuresEnh;     //! Total number of Enhancement Layer Erasures recorded
   dword iTotalSeqSigErrorsBase;    //! Total number of Base Layer FTAP Sequence Number / FTAP Test Signature Errors recorded
   dword iTotalSeqSigErrorsEnh; //! Total number of Enhancement Layer FTAP Sequence Number / FTAP Test Signature Errors recorded
} mftypes_per_statistics;

//! MediaFLO Structure for holding the overall WID LID statistics for the current measurement
typedef struct
{
   dword iTotalWIDLIDMeasured;  //! Total number WID and LIDs measured
   dword iTotalErrorsWID;           //! Total number of WID Errors.
   dword iTotalErrorsLID;           //! Total number of LID Errors.
   double dWIDErrorRate;           //! WID Error Rate
   double dLIDErrorRate;           //! LID Error Rate
} mftypes_widlid_statistics;

//! MediaFLO Structure used to parse the LOG_MFLO_FTAP_PACKETRECORD_HEADER_PARAMS_C log packets
typedef struct
{
   dword sysTime;
   dword flow_id;
   byte mlc_id;
   byte strm_id;
   byte system;
   byte trans_mode;
   byte rs_code;
   word rssi_int_part;
   byte rssi_fract_part;
   byte rssi_value_positive;
   dword num_PLP_records;
} mftypes_ftap_packet_record_header_params;

//! MediaFLO Structure used to parse individual PLP records. A LOG_MFLO_FTAP_PACKETRECORD_PARAMS_C
//! log packet contains a variable number of individual PLP records.
typedef struct
{
   dword flow_id;
   byte data_record_or_parity;
   byte base_or_enhancement;
   byte preRS_ErasureIndicator;
   byte postRS_ErasureIndicator;
   dword FTAP_SequenceNumber;
   byte FTAP_TestSignature;
} mftypes_ftap_plp_record;

//! MediaFLO Structure used to parse the first four entries in LOG_MFLO_FTAP_PACKETRECORD_PARAMS_C log packets
typedef struct
{
   dword sysTime;
   word log_seq_num;
   byte last_packet;
   word actual_num_plp_records;
} mftypes_ftap_logpkt_header_type;

//! MediaFLO Structure used to parse the LOG_MFLO_FTAP_PACKETRECORD_PARAMS_C log packets
typedef struct
{
   mftypes_ftap_logpkt_header_type logpkt_header;
   mftypes_ftap_plp_record plp_records[MFLO_MAX_FTAP_PACKET_RECORDS];
} mftypes_ftap_packet_record_params;

//! MediaFLO Structure used to parse the first five entries in LOG_MFLO_FDM_RECORDS_C log packets
typedef struct
{
   dword superframe_number;
   word current_seq_num;
   word total_seq_num;
   word num_records_in_this_log;
   word reserved;
} mftypes_fdm_record_header_type;

//! MediaFLO Structure used to parse individual records that map MLC ID to Flow ID in LOG_MFLO_FDM_RECORDS_C
//! log packets. A LOG_MFLO_FDM_RECORDS_C log packet contains a variable number of mapping records.
typedef struct
{
   dword service_id;
   byte flow_desc;
   byte mlc_id;
   byte system;
   byte stream_id;
   byte trans_mode;
   byte outer_code;
   word reserved1;
   dword reserved2;
} mftypes_mfcc_mlc_flow_mapping_info_type;

//! MediaFLO Structure used to parse LOG_MFLO_FDM_RECORDS_C log packets
typedef struct
{
   mftypes_fdm_record_header_type logpkt_header;
   mftypes_mfcc_mlc_flow_mapping_info_type mflog_fdm_mapping[MFLO_MAX_MLC_FLOW_MAPPING_RECORDS];
} mftypes_fdm_records_type;

//! MediaFLO Structure used to store a Control Channel Record
typedef struct
{
   word service_id;
   byte flow_desc;
   byte mlc_id;
   byte system;
   byte stream_id;
   byte trans_mode;
   byte outer_code;
} mftypes_mf_control_channel_record;

//! MediaFLO L-Band Channel Numbers
typedef enum
{
   MFLO_L_BAND_LA_CHANNEL = 0x01,
   MFLO_L_BAND_LB_CHANNEL = 0x02,
   MFLO_L_BAND_LC_CHANNEL = 0x03,
   MFLO_L_BAND_LD_CHANNEL = 0x04,
   MFLO_L_BAND_LE_CHANNEL = 0x05,
   MFLO_L_BAND_LF_CHANNEL = 0x06,
   MFLO_L_BAND_LG_CHANNEL = 0x07,
   MFLO_L_BAND_LH_CHANNEL = 0x08,
   MFLO_L_BAND_LI_CHANNEL = 0x09,
   MFLO_L_BAND_LJ_CHANNEL = 0x0A,
   MFLO_L_BAND_LK_CHANNEL = 0x0B,
   MFLO_L_BAND_LL_CHANNEL = 0x0C,
   MFLO_L_BAND_LM_CHANNEL = 0x0D,
   MFLO_L_BAND_LN_CHANNEL = 0x0E,
   MFLO_L_BAND_LO_CHANNEL = 0x0F,
   MFLO_L_BAND_LP_CHANNEL = 0x10,
   MFLO_L_BAND_LQ_CHANNEL = 0x11,
   MFLO_L_BAND_LR_CHANNEL = 0x12,
   MFLO_L_BAND_LS_CHANNEL = 0x13,
   MFLO_L_BAND_LT_CHANNEL = 0x14,
   MFLO_L_BAND_LU_CHANNEL = 0x15,
   MFLO_L_BAND_LV_CHANNEL = 0x16,
   MFLO_L_BAND_LW_CHANNEL = 0x17
} mftypes_l_band_channel_type;

//! MediaFLO Jammer Detection Modes
typedef enum
{
   MFLO_JD_MODE_AUTO = 0,
   MFLO_JD_MODE_1    = 1,
   MFLO_JD_MODE_2    = 2
} mftypes_jd_mode_type;

//! MediaFLO Jammer Detection States
typedef enum
{
   MFLO_JD_STATE_INVALID      = 0,
   MFLO_JD_STATE_MODE_1       = 1,
   MFLO_JD_STATE_MODE_2       = 2,
   MFLO_JD_STATE_INITIALIZING = 3
} mftypes_jd_state_type;

//! MediaFLO Jammer Detection Substates
typedef enum
{
   MFLO_JD_SUBSTATE_NONE    = 0,
   MFLO_JD_SUBSTATE_POLLING = 1
} mftypes_jd_substate_type;

//! MediaFLO MBP Bus Mode
typedef enum
{
   MFLO_MBP_BUS_MODE_EBI2     = 0,
   MFLO_MBP_BUS_MODE_EBI2_MUX = 1,
   MFLO_MBP_BUS_MODE_SDIO     = 2
} mftypes_mbp_bus_mode;

//! MediaFLO FTM State
typedef enum
{
   MFLO_FTM_STATE_UNINITIALIZED = 0,
   MFLO_FTM_STATE_INITIALIZING  = 1,
   MFLO_FTM_STATE_DEMOD         = 2,
   MFLO_FTM_STATE_CALIBRATION   = 3
} mftypes_ftm_state_type;

/******************************************************************************
Diagnostic - CGPS subsystem
*******************************************************************************/

//! CGPS Subsystem command
#define CGPS_SUBSYSTEM 101  //!< CGPS Diagnostic subystem ID

//! CGPS Packet version
#define CGPS_PACKET_VERSION 1
#define CGPS_GEN8_PACKET_VERSION 50

/**
Converged GPS commands
*/
typedef enum
{
   _GPS_CMD_CODE_GPS_SA_RF_VERIF_MODE_SWITCH    =  20,   //!< ' CGPS engine enters or exits "Standalone (SA) RF Verification" mode
   _GPS_CMD_CODE_GPS_PRESCRIBED_DWELL           =  21,   //!< ' CGPS engine performs one dwell on one channel
   _GPS_CMD_CODE_GPS_START_IQ_TEST              =  22,   //!< ' CGPS engine starts an IQ collect
   _GPS_CMD_CODE_GPS_SV_TRACK                   =  23,   //!< ' CGPS engine tracks the specified SV or all SVs
   _GPS_CMD_CODE_GPS_GEN8_HW_CONFIG             =  26,   //!< ' Configure CGPS Gen8 engine hardware
   _GPS_CMD_CODE_GPS_MULTI_CHANNEL_TRACK        =  27,   //!( ' CGPS Gen8 Engine starts multi channel SV tracking
   _GPS_CMD_CODE_GPS_PRX_MODE                   =  28,   //!( ' Configure CGPS Gen8 Engine Primary Recieve chain mode
   _GPS_CMD_CODE_GPS_LINEARITY_MODE             =  29,   //!( ' Configure CGPS Gen8 Engine Linearity mode
   _GPS_CMD_CODE_GPS_Query_GNSS_Engine_Revision =  30,   //!( ' Get Revision of GNSS Engine (Gen8, Gen8A, ...)
   _GPS_CMD_CODE_GPS_SpecAn_Control             =  42,   //!( ' Configure/Stoart/Stop Onboard Spectrum analysis.
   _GPS_CMD_CODE_GPS_FACTORY_IQ_TEST            = 114    //!( ' Start a factory (onboard) IQ Test
} gps_cmd_code_enum_type;

typedef enum
{
   GNSS_ENGINE_REVISION_UNKNOWN      = 0,
   GNSS_ENGINE_REVISION_GEN8         = 50,
   GNSS_ENGINE_REVISION_GEN8A        = 51,
   GNSS_ENGINE_REVISION_GEN8A_SpecAn = 52,
   GNSS_ENGINE_REVISION_GEN8B        = 53,
   GNSS_ENGINE_REVISION_GEN8B_BDS    = 54,
   GNSS_ENGINE_REVISION_GEN8C        = 55,
   GNSS_ENGINE_REVISION_GEN8C_GAL    = 56,
   GNSS_ENGINE_REVISION_MIN          = GNSS_ENGINE_REVISION_GEN8,
   GNSS_ENGINE_REVISION_MAX          = GNSS_ENGINE_REVISION_GEN8C_GAL
} GNSS_ENGINE_REVISIONS;

typedef enum
{
   GNSS_Start_IQ_TEST_COMMAND_REVISION_GEN8  = 50,
   GNSS_Start_IQ_TEST_COMMAND_REVISION_GEN8B = 51,
   GNSS_Start_IQ_TEST_COMMAND_REVISION_GEN8C      = 52,
   GNSS_Start_IQ_TEST_COMMAND_REVISION_GEN8C_GAL  = 53
} GNSS_Start_IQ_TEST_COMMAND_REVS;

typedef enum
{
   _GNSS_XO_FACTORY_COARSE_DC_CAL            = 0x0FB //!(' Start factory/coarse calibration - Sent to TCXOMGR Subsys
} gnss_xo_factory_code_enum_type;

/**
Events used by CGPS functions
*/
typedef enum
{
   _EVENT_GPS_PD_COMM_FAILURE       = 1241,
   _EVENT_GPS_PD_COMM_DONE          = 1242,
   _EVENT_GPS_PD_EVENT_END          = 1243,
   _EVENT_GPS_PA_EVENT_CALLBACK     = 1244,
   _EVENT_GPS_PD_CMD_ERR_CALLBACK   = 1245,
   _EVENT_GPS_PA_CMD_ERR_CALLBACK   = 1246,
   _EVENT_GPS_LM_ENTER_SA_RF_VERIF  = 1247,
   _EVENT_GPS_LM_EXIT_SA_RF_VERIF   = 1248,
   _EVENT_GPS_LM_ERROR_SA_RF_VERIF  = 1249,
   _EVENT_GPS_LM_PD_COMPLETE        = 1250,
   _EVENT_GPS_LM_IQ_TEST_COMPLETE   = 1251,
   _EVENT_GPS_SBAS_DEMOD_REPORT     = 1457,
   _EVENT_GNSS_PRESC_DWELL_COMPLETE = 1717,
   _EVENT_GNSS_SPECTRUM_ANALYZER_STATUS = 2243
} gps_events_enum_type;

/**
Logs used by CGPS functions
*/
typedef enum
{
   //! Log code for CGPS Measurement Report
   CGPS_MEASUREMENT_REPORT_LOG          = 0x1371,

   //! Log code for CGPS RF Status
   CGPS_RF_STATUS_REPORT_LOG            = 0x1372,

   //! Log code for IQ and FFT data
   CGPS_IQ_DATA_LOG                 = 0x138A,

   //! Log code for prescribed dwell status
   CGPS_PRESCRIBED_DWELL_STATUS_LOG     = 0x1374,

   //! Log code for GPS soft decisions, used during the GPS BER test
   GPS_DEMOD_SOFT_DECISIONS_LOG     = 0x1253,

   //! Log code for GPS SBAS Demodulated bits
   CGPS_SBAS_DEMODULATED_BITS           = 0x1457,

   //! Log code for GPS SBAS Demod Soft Symbols
   CGPS_SBAS_DEMOD_SOFT_SYMBOLS         = 0x1458,

   //! Log code for ME Job Info Log
   CGPS_ME_JOB_INFO_LOG                 = 0x13BA,

   GNSS_GPS_MEASUREMENT_REPORT_LOG      = 0x1477,
   GNSS_DEMOD_SOFT_DECISIONS_LOG        = 0x1479,
   GNSS_GLONASS_MEASUREMENT_REPORT_LOG  = 0x1480,
   GNSS_GPS_HBW_RXD_MEASUREMENT_LOG = 0x1481,
   GNSS_PRX_RF_HW_STATUS_REPORT_LOG = 0x147E,
   GNSS_DRX_RF_HW_STATUS_REPORT_LOG = 0x147F,

   //! Log code for CGPS WB FFT C/N
   CGPS_WB_FFT_STATS_C_LOG              = 0x1487,
   GNSS_BROADBANDJAMMER_INFO_LOG =  0x1526,
   GNSS_FastTimeCalibration_Log = 0x1567,
   GNSS_LTE_PRS_RSTD_Measurements = 0x1599,
   GNSS_LTE_PRS_TOA_Measurements = 0x159A,
   GNSS_BDS_MEASUREMENT_REPORT_LOG  =  0x1756,
   GNSS_XO_FACTORY_MEASUREMENT_REPORT_LOG =  0x1803,

   GNSS_WARF_DATA_LOG = 0x1649,

   GNSS_INJECT_SENSOR_DATA = 0x1510,
   GNSS_GAL_MEASUREMENT_REPORT_LOG  =  0x1886   // this is wrong, put in-place to help development.
} gps_logs_enum_type;

typedef enum
{
   BP_NONE    = 0,
   BP_LBW_GPS = 1,
   BP_LBW_GAL = 1,
   BP_BDS     = 2,
   BP_GLONASS = 4,
   BP_HBW_GPS = 8,
} gnss_bp_enum_type;

/**
Used for the OBS_STATE field of the log message, CGPS_MEASUREMENT_REPORT_LOG = 0x1371,
*/
typedef enum
{
   CGPS_MEASUREMENT_OBS_STATE_IDLE = 0,
   CGPS_MEASUREMENT_OBS_STATE_SEARCH = 1,
   CGPS_MEASUREMENT_OBS_STATE_SEARCH_VERIFY = 2,
   CGPS_MEASUREMENT_OBS_STATE_BIT_EDGE = 3,
   CGPS_MEASUREMENT_OBS_STATE_TRACK_VERIFY = 4,
   CGPS_MEASUREMENT_OBS_STATE_TRACKING = 5,
   CGPS_MEASUREMENT_OBS_STATE_RESTART = 6,
   CGPS_MEASUREMENT_OBS_STATE_DPO_TRACK = 7
} gps_measurement_report_state_enum_type;

/** For C/N measurement, Measurement state should have the following bits on
bit 0 = submillisecond is valid
bit 8 = good parity
*/
#define CGPS_MEASUREMENT_MEAS_STATE_CTON_FILTER 0x11

/** CGPS Measurement Status bit definitions   */
#define CGPS_MEAS_STATUS_NULL               0x0000

#define CGPS_MEAS_STATUS_SM_VALID           0x0001
#define CGPS_MEAS_STATUS_SB_VALID           0x0002
#define CGPS_MEAS_STATUS_MS_VALID           0x0004
#define CGPS_MEAS_STATUS_BE_CONFIRM         0x0008

#define CGPS_MEAS_STATUS_VE_VALID           0x0010
#define CGPS_MEAS_STATUS_VE_FINE            0x0020
#define CGPS_MEAS_STATUS_LP_VALID           0x0040
#define CGPS_MEAS_STATUS_LP_POS             0x0080

#define CGPS_MEAS_STATUS_GOOD_DATA          0x0100
#define CGPS_MEAS_STATUS_FROM_RNG_DIFF      0x0200
#define CGPS_MEAS_STATUS_FROM_VE_DIFF       0x0400
#define CGPS_MEAS_STATUS_XCORR              0x0800

#define CGPS_MEAS_STATUS_TENTATIVE          0x1000
#define CGPS_MEAS_STATUS_DONT_USE           0x2000
#define CGPS_MEAS_STATUS_NEED_SIR_CHECK     0x4000
#define CGPS_MEAS_STATUS_ACQ_OR_PROBATION   0x8000

#define CGPS_MEAS_STATUS_ROUND_ROBIN_RX_DIVERSITY       0x40000
#define CGPS_MEAS_STATUS_RX_DIVERSITY_MEASUREMENT       0x80000

#define CGPS_MEAS_STATUS_LBW_RXD_COMBINED_MEASUREMENT   0x10000
#define CGPS_MEAS_STATUS_HBW_GPS_NU4_MEASUREMENT        0x20000
#define CGPS_MEAS_STATUS_HBW_GPS_NU8_MEASUREMENT        0x40000
#define CGPS_MEAS_STATUS_HBW_GPS_UNIFORM_MEASUREMENT    0x80000

#define CGPS_MEAS_STATUS_GNSS_MULTIPATH_INDICATOR       0x100000

/**
Format for CGPS Measurement Report SV row
CGPS_MEASUREMENT_REPORT_LOG         = 0x1371,
*/
typedef struct
{
   byte SV_ID;
   byte OBS_STATE;          // value 5 = CGPS_MEASUREMENT_OBS_STATE_TRACKING = tracking, this is check for in C/N measurment
   byte OBS_CNT;
   byte OBS_GOOD_CNT;
   byte FILTER_N;
   word CNO;
   word LATENCY;
   byte PRE_INT;
   word POST_INT;
   dword    UNFILT_MS;
   float    UNFILT_SM;
   float    UNFILT_TIME_UNC;
   float    UNFILT_SPEED;
   float    UNFILT_SPEED_UNC;
   dword    MEAS_STATUS;
   byte MISC_STATUS;
   dword    MULTIPATH_EST;
   float    AZI_RAD;
   float    ELEV_RAD;
   long CARRIER_PHASE_CYCLES;
   int  CARRIER_PHASE_FRACT;
   dword    RESERVED1;
} CGPS_MeasurementReportLog_SvRow_Struct;

typedef struct
{
   byte SV_ID;
   byte OBS_STATE;          // value 5 = CGPS_MEASUREMENT_OBS_STATE_TRACKING = tracking, this is check for in C/N measurment
   byte OBS_CNT;
   byte OBS_GOOD_CNT;
   word     PARITY_ERROR_CNT;
   byte FILTER_N;
   word CNO;
   short    LATENCY;
   byte PRE_INT;
   word POST_INT;
   dword    UNFILT_MS;
   float    UNFILT_SM;
   float    UNFILT_TIME_UNC;
   float    UNFILT_SPEED;
   float    UNFILT_SPEED_UNC;
   dword    MEAS_STATUS;
   byte MISC_STATUS;
   dword    MULTIPATH_EST;
   float    AZI_RAD;
   float    ELEV_RAD;
   long CARRIER_PHASE_CYCLES;
   word CARRIER_PHASE_FRACT;
   float    FINE_SPEED;
   float    FINE_SPEED_UNC;
   byte CycleSlipCount;
   byte CLK_OFFSET_PPM; // Fixed Clock Offset in 2's complement format, resolution 0.2 (range +/- 25.6 ppm)
   byte RESERVED1;
   byte RESERVED2;
   byte RESERVED3;
} CGPS_GEN8_MeasurementReportLog_SvRow_Struct;

typedef struct
{
   union
   {
      unsigned char     prn_bytes[2];
      unsigned short    prn_number;
   };
   union
   {
      unsigned char     noise_bytes[2];
      unsigned short    noise_power;
   };
   union
   {
      unsigned char     signal_bytes[4];
      int               signal_power;
   };
   union
   {
      unsigned char     doppler_bytes[4];
      int               doppler_frequency;
   };
   union
   {
      unsigned char     phase_bytes[2];
      unsigned short    prn_phase;
   };
   union
   {
      unsigned char     chips_bytes[2];
      unsigned short    prn_chips;
   };
   union
   {
      unsigned char     cycle_bytes[2];
      unsigned short    prn_cycles;
   };
   union
   {
      unsigned char     bit_bytes[2];
      unsigned short    prn_bits;
   };
   union
   {
      unsigned char     tow_bytes[4];
      unsigned int      gps_tow;
   };
} GNSS_SOC_measurement_report;

typedef struct
{
   union
   {
      unsigned char     prn_bytes[2];
      unsigned short    prn_number;
   };
   union
   {
      unsigned char     noise_bytes[2];
      unsigned short    noise_power;
   };
   union
   {
      unsigned char     signal_bytes[4];
      int               signal_power;
   };
   union
   {
      unsigned char     doppler_bytes[4];
      int               doppler_frequency;
   };
} GNSS_SOC_single_sv_measurement_report;

// Set to 16 until real limit is known.
#define MAX_LOG_PRNS 16

typedef struct
{
   unsigned char              version;
   unsigned char               resp_type;
   union
   {
      unsigned char            packet_num_bytes[4];
      unsigned int             packet_num;
   };
   union
   {
      unsigned char            packet_cnt_bytes[4];
      unsigned int             packet_cnt;
   };
   union
   {
      unsigned char          time_bytes[4];
      int                      ms_time;
   };
   unsigned char              glo_igain;
   unsigned char              glo_qgain;
   unsigned char              gps_igain;
   unsigned char              gps_qgain;
   unsigned char              num_prns;
   GNSS_SOC_measurement_report reports[MAX_LOG_PRNS];
} GNSS_SOC_MeasurementReportLog_Struct;

typedef struct
{
   unsigned char                         version;
   unsigned char                         resp_type;
   union
   {
      unsigned char                      packet_num_bytes[4];
      unsigned int                       packet_num;
   };
   union
   {
      unsigned char                      packet_cnt_bytes[4];
      unsigned int                       packet_cnt;
   };
   union
   {
      unsigned char                      time_bytes[4];
      int                                ms_time;
   };
   unsigned char                         test_mode;
   unsigned int                          mclk_int;
   unsigned short                        mclk_frac;
   unsigned char                         igain;
   unsigned char                         qgain;
   unsigned char                         number_svs;   // 0 or 1
   GNSS_SOC_single_sv_measurement_report report;
} GNSS_SOC_SingleSvMeasurementReportLog_Struct;

//! Number of SV's in a measurement report
#define CGPS_MAX_NUM_SV_IN_MEASUREMENT_REPORT 16

/**
Format for CGPS Measurement Report
CGPS_MEASUREMENT_REPORT_LOG         = 0x1371,
*/
typedef struct
{
   byte iVersion;
   dword iFCOUNT;
   word iGPS_Week;
   dword iGPS_MS;
   dword iTimeBias;
   dword iTimUncertainty;
   dword iFreqBias;
   dword iFreqUncertainty;
   byte iNumSVs;    //!< ' Number of SV's in report, 0...16
   CGPS_MeasurementReportLog_SvRow_Struct aSvRows[ CGPS_MAX_NUM_SV_IN_MEASUREMENT_REPORT ];
} CGPS_MeasurementReportLog_Struct;

typedef struct
{
   byte iVersion;
   dword iFCOUNT;
   word iGPS_Week;
   dword iGPS_MS;
   dword iTimeBias;
   dword iTimUncertainty;
   dword iFreqBias;
   dword iFreqUncertainty;
   byte  iNumSVs;   //!< ' Number of SV's in report, 0...16
   CGPS_GEN8_MeasurementReportLog_SvRow_Struct aSvRows[ CGPS_MAX_NUM_SV_IN_MEASUREMENT_REPORT ];
} CGPS_GEN8_GpsMeasurementReportLog_Struct;

#define GEN8_GPS_MEASUREMENT_VERSION 0
#define GNSS_SOC_MEASUREMENT_VERSION  100
#define GNSS_SOC_SINGLE_SV_MEASUREMENT_VERSION 200

typedef struct
{
   char SV_ID;
   char SV_FREQ_INDEX;
   byte OBS_STATE;
   byte OBS_CNT;
   byte GOOD_OBS_CNT;
   byte HEMMING_ERR_CNT;
   byte FILTER_N;
   word CNO;
   short    LATENCY;
   byte PRE_INT;
   word POST_INT;
   dword    UNFILT_MS;
   float    UNFILT_SM;
   float    UNFILT_TIME_UNC;
   float    UNFILT_SPEED;
   float    UNFILT_SPEED_UNC;
   dword    MEAS_STATUS;
   byte MISC_STATUS;
   dword    MULTIPATH_EST;
   float    AZI_RAD;
   float    ELEV_RAD;
   long CARRIER_PHASE_CYCLES;
   word CARRIER_PHASE_FRACT;
   float    FINE_SPEED;
   float    FINE_SPEED_UNC;
   byte CycleSlipCount;
   byte CLK_OFFSET_PPM; // Fixed Clock Offset in 2's complement format, resolution 0.2 (range +/- 25.6 ppm)
   byte RESERVED1;
   byte RESERVED2;
   byte RESERVED3;
} CGPS_GEN8_GlonassMeasurementReportLog_SvRow_Struct;

typedef struct
{
   byte     SV_ID;
   byte     OBS_STATE;
   byte     OBS_CNT;
   byte     GOOD_OBS_CNT;
   word     PARITY_ERROR_MASK;
   byte     FILTER_N;
   word     CNO;
   short    LATENCY;
   byte     PRE_INT;
   word     POST_INT;
   dword    UNFILT_MS;
   float    UNFILT_SM;
   float    UNFILT_TIME_UNC;
   float    UNFILT_SPEED;
   float    UNFILT_SPEED_UNC;
   dword    MEAS_STATUS;
   byte     MISC_STATUS;
   dword    MULTIPATH_EST;
   float    AZI_RAD;
   float    ELEV_RAD;
   long     CARRIER_PHASE_CYCLES;
   word     CARRIER_PHASE_FRACT;
   float    FINE_SPEED;
   float    FINE_SPEED_UNC;
   byte     CycleSlipCount;
   dword    RESERVED1;
} CGPS_GEN8_BDS_MeasurementReportLog_SvRow_Struct;

typedef struct
{
   word     SV_ID;
   byte     OBS_STATE;
   byte     OBS_CNT;
   byte     GOOD_OBS_CNT;
   word     PARITY_ERROR_MASK;
   byte     FILTER_N;
   word     CNO;
   short    LATENCY;
   byte     PRE_INT;
   word     POST_INT;
   dword    UNFILT_MS;
   float    UNFILT_SM;
   float    UNFILT_TIME_UNC;
   float    UNFILT_SPEED;
   float    UNFILT_SPEED_UNC;
   dword    MEAS_STATUS;
   byte     MISC_STATUS;
   dword    MULTIPATH_EST;
   float    AZI_RAD;
   float    ELEV_RAD;
   long     CARRIER_PHASE_CYCLES;
   word     CARRIER_PHASE_FRACT;
   float    FINE_SPEED;
   float    FINE_SPEED_UNC;
   byte     CycleSlipCount;
   dword    RESERVED1;
} CGPS_GEN8_GAL_MeasurementReportLog_SvRow_Struct;

typedef struct
{
   byte iVersion;
   dword    iFCOUNT;
   byte GLO_FOUR_YEAR;
   word GLO_CAL_DAYS;
   dword    GLO_MSEC;
   float    TIME_BIAS;
   float    TIME_UNC;
   float    FREQ_BIAS;
   float    FREQ_UNC;
   byte NUMBER_SVS;
   CGPS_GEN8_GlonassMeasurementReportLog_SvRow_Struct aSvRows[ CGPS_MAX_NUM_SV_IN_MEASUREMENT_REPORT ];
} CGPS_GEN8_GlonassMeasurementReportLog_Struct;

typedef struct
{
   byte  iVersion;
   byte  EngineType;
   byte  HW_Version;
   dword iFCOUNT;
   word  BDS_Week;
   dword BDS_MSEC;
   dword TIME_BIAS;
   dword TIME_UNC;
   dword FREQ_BIAS;
   dword FREQ_UNC;
   byte  NUMBER_SVS;
   CGPS_GEN8_BDS_MeasurementReportLog_SvRow_Struct aSvRows[ CGPS_MAX_NUM_SV_IN_MEASUREMENT_REPORT ];
} CGPS_GEN8_BDS_MeasurementReportLog_Struct;

typedef struct
{
   byte  iVersion;
   byte  EngineType;
   byte  HW_Version;
   dword iFCOUNT;
   word  GAL_Week;
   dword GAL_MSEC;
   dword TIME_BIAS;
   dword TIME_UNC;
   dword FREQ_BIAS;
   dword FREQ_UNC;
   byte  NUMBER_SVS;
   CGPS_GEN8_GAL_MeasurementReportLog_SvRow_Struct aSvRows[ CGPS_MAX_NUM_SV_IN_MEASUREMENT_REPORT ];
} CGPS_GEN8_GAL_MeasurementReportLog_Struct;

/**
Format for CGPS Measurement Report
CGPS_MEASUREMENT_REPORT_LOG         = 0x1371,
*/

typedef struct
{
   byte SV_ID;              // Satellite ID
   byte OBS_STATE;          // SV observation state
   byte OBS_CNT;            // Count of all observations, both success and failure
   byte OBS_GOOD_CNT;       // Count of good observations
   word     PARITY_ERROR_MASK;  // Parity Error Subframe mask
   byte FILTER_N;           // Carrier-to-code filtering. # of filter stages
   word CNO;                // Carrier to Noise in a 1Hz bandwidth, 0.01 dB-Hz per bit
   word LATENCY;            // Current Fcount minus Fcount at which measurement was effective
   byte PRE_INT;            // Pre-det interval in ms
   word POST_INT;           // Number of post-dets
   dword    UNFILT_MS;          // Unfiltered measurement millisecond in user time, Unsigned value in ms.
   float    UNFILT_SM;          // Unfiltered measurement fractional ms in user time.
   float    OFFSET_UNFILT_SM;   // Unfiltered measurement fraction ms offset from LBW GPS.
   float    UNFILT_TIME_UNC;    // Unfiltered SV time uncertainty in nanoseconds
   float    UNFILT_SPEED;       // Unfiltered SV speed in m/s
   float    OFFSET_UNFILT_SPEED;// Unfiltered Sv Speed offset from LBW GPS.
   float    UNFILT_SPEED_UNC;   // Unfiltered SV speed uncertainty in m/s
   dword    MEAS_STATUS;        // Measurement status flags.
   byte MISC_STATUS;
   dword    MULTIPATH_EST;
   float    AZI_RAD;
   float    ELEV_RAD;
   dword    CARRIER_PHASE_CYCLES;
   word CARRIER_PHASE_FRACT;
   float    FINE_SPEED;
   float    FINE_SPEED_UNC;
   byte CycleSlipCount;
   byte CLK_OFFSET_PPM; // Fixed Clock Offset in 2's complement format, resolution 0.2 (range +/- 25.6 ppm)
   //dword  RESERVED1;
   byte RESERVED1;
   byte RESERVED2;
   byte RESERVED3;
} CGPS_GEN8_HBW_MeasurementReportLog_SvRow_Struct;

typedef struct
{
   byte iVersion;           // Version number of packet = 0
   dword    iFCOUNT;            // Receiver's millisecond count value
   word iGPS_Week;          // GPS Week number
   dword    iGPS_MS;            // GPS Millisecond into the week
   float    iTimeBias;          // (User time - GPS time) in milliseconds
   float    iTimeUncertainty;   // Clock time uncertainty in nanoseconds.
   float    iFreqBias;          // Clock frequency bias in m/s
   float    iFreqUncertainty;   // Clock frequency uncertainty in m/s
   byte iMeasurementType;   // Gps Measurement Type
   byte iNumSVs;            // Number of SV's in report, 0...16
   CGPS_GEN8_HBW_MeasurementReportLog_SvRow_Struct aSvRows[ CGPS_MAX_NUM_SV_IN_MEASUREMENT_REPORT ];
} CGPS_HBW_MeasurementReportLog_Struct;

typedef enum
{
   CGPS_GEN8_MeasurementType_LBW_GPS_Measurement    = 0,
   CGPS_GEN8_MeasurementType_HBW_GPS_Measurement    = 1,
   CGPS_GEN8_MeasurementType_RxD_Measurement        = 2
} CGPS_GEN8_MeasurementType_type;

#define CGPS_GEN8_MiscStatus_MultipathEstValid 1;   // Bit 0, "AND" with MISC_STATUS to determine if Multipath estimate is valid
#define CGPS_GEN8_MiscStatus_DirValid 2 ;           // Bit 1, "AND" with MISC_STATUS to determine if Azi and Elev are valid

/**
Format for CGPS RF Status
CGPS_RF_STATUS_REPORT_LOG           = 0x1372,
*/
typedef struct
{
   byte iVersion;
   dword iFCOUNT;
   byte iPLL_ChanAndLockStatus;
   short iBP_Mean_I;
   short iBP_Mean_Q;
   unsigned short iBP_Ampl_I;
   unsigned short iBP_Ampl_Q;

   // There are more fields in this log, but these are the only ones supported by QMSL.
   // Please see CGPS ICD for further fields.
} CGPS_RF_StatusLog_Struct;

typedef struct
{
   byte   Bp3FreqIndex;  /* -7 to +6 with -8 representing unused */
   dword  Bp3AmplI;      /* BP3 Amp I */
   dword  Bp3AmplQ;      /* BP3 Amp Q */
   dword  Bp3RotFineFreq; /* Fine Rotator Value in kHz */
} GNSS_Bp3RfStatusType;

typedef struct
{
   byte iVersion;
   byte GNSS_HW_VER;
   dword    iFCOUNT;
   char RFIC_ID_PRX[12];
   byte RFIC_MODE;
   byte RFIC_LIN_STATE;
   byte RF_VCO_TUNE_CODE;
   word RF_DC_DAC_I;
   word RF_DC_DAC_Q;

   long PGA_GAIN;
   dword    ADC_SAMPLE_RATE_FREQ;
   dword    ADC_PRE_MEAN_I;
   dword    ADC_PRE_MEAN_Q;

   byte BP1_LBW_SAMPLE_RATE;
   short    BP1_LBW_MEAN_I;
   short    BP1_LBW_MEAN_Q;
   dword    BP1_LBW_PRE_AMPL_I;
   dword    BP1_LBW_PRE_AMPL_Q;
   dword    BP1_LBW_AMPL_I;
   dword    BP1_LBW_AMPL_Q;
   float    BP1_LBW_FINE_FREQ;
   byte BP1_LBW_NOTCH_ACTIVE;
   short    BP1_LBW_GROUP_DELAY;

   byte BP3_GLO_SAMPLE_RATE;
   short    BP3_GLO_MEAN_I;
   short    BP3_GLO_MEAN_Q;
   dword    BP3_GLO_AMPL_I;
   dword    BP3_GLO_AMPL_Q;
   float    BP3_GLO_FINE_FREQ;
   byte BP3_GLO_NOTCH_ACTIVE;
   short    BP3_GLO_GROUP_DELAY;

   byte BP4_HBW_SAMPLE_RATE;
   short    BP4_HBW_MEAN_I;
   short    BP4_HBW_MEAN_Q;
   dword    BP4_HBW_AMPL_I;
   dword    BP4_HBW_AMPL_Q;
   float    BP4_HBW_FINE_FREQ;
   byte BP4_HBW_NOTCH_ACTIVE;
   short    BP4_HBW_GROUP_DELAY;

   dword    MND_CNTR_M;
   dword    MND_CNTR_N;
   dword    MND_CNTR_D;

   byte  AgcType;           /* 0: Reserved 1: 50hz SWAGC 2: HWAGC 3: 1k SWAGC 4: RESERVED */
   byte RESERVED[8];
   dword Bp3PreAmplI;
   dword Bp3PreAmplQ;
   GNSS_Bp3RfStatusType Bp3Info[12];
} GNSS_PRX_RF_HW_StatusLog_Struct;

typedef struct
{
   byte     iVersion;       // = 3 for the rev of the log
   byte     GNSS_HW_VER;
   dword    iFCOUNT;
   char     RFIC_ID_PRX[12];
   byte     RFIC_MODE;
   byte     RFIC_LIN_STATE;
   byte     RF_VCO_TUNE_CODE;
   word     RF_DC_DAC_I;
   word     RF_DC_DAC_Q;

   long     PGA_GAIN;
   dword    ADC_SAMPLE_RATE_FREQ;
   dword    ADC_PRE_MEAN_I;
   dword    ADC_PRE_MEAN_Q;

   byte     BP1_LBW_SAMPLE_RATE;
   word    BP1_LBW_MEAN_I;
   word    BP1_LBW_MEAN_Q;
   dword    BP1_LBW_PRE_AMPL_I;
   dword    BP1_LBW_PRE_AMPL_Q;
   dword    BP1_LBW_AMPL_I;
   dword    BP1_LBW_AMPL_Q;
   float    BP1_LBW_FINE_FREQ;
   byte     BP1_LBW_NOTCH_ACTIVE;
   short    BP1_LBW_GROUP_DELAY;

   byte    BP2_BDS_SampleRate;
   word    BP2_BDS_MeanI;
   word    BP2_BDS_MeanQ;
   dword   BP2_BDS_PreAmplI;
   dword   BP2_BDS_PreAmplQ;
   dword   BP2_BDS_AmplI;
   dword   BP2_BDS_AmplQ;
   dword   BP2_BDS_RotFineFreq;
   byte    BP2_BDS_NumActNotch;
   word    BP2_BDS_GrpDelay;

   byte     BP3_GLO_SAMPLE_RATE;
   short    BP3_GLO_MEAN_I;
   short    BP3_GLO_MEAN_Q;
   dword    BP3_GLO_AMPL_I;
   dword    BP3_GLO_AMPL_Q;
   float    BP3_GLO_FINE_FREQ;
   byte     BP3_GLO_NOTCH_ACTIVE;
   short    BP3_GLO_GROUP_DELAY;

   byte     BP4_HBW_SAMPLE_RATE;
   short    BP4_HBW_MEAN_I;
   short    BP4_HBW_MEAN_Q;
   dword    BP4_HBW_AMPL_I;
   dword    BP4_HBW_AMPL_Q;
   float    BP4_HBW_FINE_FREQ;
   byte     BP4_HBW_NOTCH_ACTIVE;
   short    BP4_HBW_GROUP_DELAY;

   dword    MND_CNTR_M;
   dword    MND_CNTR_N;
   dword    MND_CNTR_D;

   byte  AgcType;           /* 0: Reserved 1: 50hz SWAGC 2: HWAGC 3: 1k SWAGC 4: RESERVED */
   byte RESERVED[8];
   dword Bp3PreAmplI;
   dword Bp3PreAmplQ;
   GNSS_Bp3RfStatusType Bp3Info[12];
} GNSS_PRX_RF_HW_StatusLog_Rev3_Struct;

/* RF and HW status for Primary Rx */
#define GNSS_NAV_HW_VER_MAX_STR_LEN 15
#define GNSS_CONFIG_MAX_STR_LEN 20
#define GNSS_RF_MODE_MAX_STR_LEN 10
#define GNSS_RF_STATUS_MAX_STR_LEN 12
#define C_MGP_TOTAL_GLO_SUB_CHAN_NUM (12)

typedef struct
{
   byte    iVersion;
   char    GNSS_NavHwVer[GNSS_NAV_HW_VER_MAX_STR_LEN];
   char    GNSS_ActualConfig[GNSS_CONFIG_MAX_STR_LEN];
   dword   iFCOUNT;  /* FCount value at reference tick */

   /* RF Status */
   char    RFIC_ID_PRX[GNSS_RF_STATUS_MAX_STR_LEN];
   char    RF_OpMode[GNSS_RF_MODE_MAX_STR_LEN];
   byte    RF_DcOffsetI[2];
   byte    RF_DcOffsetQ[2];
   long    PGA_GAIN;

   /* ADC processor status */
   dword  ADC_SAMPLE_RATE_FREQ;
   long   ADC_PRE_MEAN_I;
   long   ADC_PRE_MEAN_Q;
   dword  ADC_AMP_I_p1mV;
   dword  ADC_AMP_Q_p1mV;

   /* BP1 LBW processor status */
   byte   BP1_LBW_SAMPLE_RATE;
   byte   BP1_LBW_GainStep;
   dword  BP1_LBW_PRE_AMPL_I;
   dword  BP1_LBW_PRE_AMPL_Q;
   dword  BP1_LBW_AMPL_I;
   dword  BP1_LBW_AMPL_Q;

   dword  BP1_GAL_AMPL_I;
   dword  BP1_GAL_AMPL_Q;

   dword  BP1_LBW_FINE_FREQ;
   dword  BP1_LBW_RsRateHWU;
   byte   BP1_LBW_NOTCH_ACTIVE;
   short  BP1_LBW_GROUP_DELAY;

   /* BP2 BDS processor status */
   byte   BP2_BDS_SampleRate;
   byte   BP2_BDS_GainStep;
   dword  BP2_BDS_PreAmplI;
   dword  BP2_BDS_PreAmplQ;
   dword  BP2_BDS_AmplI;
   dword  BP2_BDS_AmplQ;
   dword  BP2_BDS_RotFineFreq;
   dword  BP2_BDS_RsRateHWU;
   byte   BP2_BDS_NumActNotch;
   short  BP2_BDS_GrpDelay;

   /* BP3 GLO processor status */
   byte   BP3_GLO_SampleRate;
   byte   BP3_GLO_GainStep;
   dword  BP3_GLO_PreAmplI;
   dword  BP3_GLO_PreAmplQ;
   dword  BP3_GLO_RsRateHWU;
   byte   BP3_GLO_NumActNotch;
   short  BP3_GLO_GrpDelay;

   /* M/N:D to derive chipx80 from GPLL0 */
   dword  MNDCntrM;
   dword  MNDCntrN;
   dword  MNDCntrD;

   char    Reserved[8];
   GNSS_Bp3RfStatusType Bp3Info[C_MGP_TOTAL_GLO_SUB_CHAN_NUM];
} GNSS_PRX_RF_HW_StatusLog_Rev4_Struct;

typedef struct
{
   byte iVersion;
   dword    iFCOUNT;
   char RFIC_ID_PRX[12];
   byte RFIC_MODE;
   byte RFIC_LIN_STATE;
   byte RF_PLL_LOCK_STATUS;
   word RF_VCO_TUNE_CODE;
   byte RF_DC_OFFSET_I;
   byte RF_DC_OFFSET_Q;

   char ADC_GAIN[12];
   float    ADC_SAMPLE_RATE_FREQ;
   byte ADC_PRE_MEAN_IQ_VALID;
   float    ADC_PRE_MEAN_I;
   float    ADC_PRE_MEAN_Q;

   byte BP2_DRX_SAMPLE_RATE;
   short    BP2_DRX_MEAN_I;
   short    BP2_DRX_MEAN_Q;
   float    BP2_DRX_AMPL_I;
   float    BP2_DRX_AMPL_Q;
   float    BP2_DRX_FINE_FREQ;
   byte BP2_DRX_NOTCH_ACTIVE;
   short    BP2_DRX_GROUP_DELAY;

   dword    RESERVED;
} GNSS_DRX_RF_HW_StatusLog_Struct;

typedef enum
{
   GNSS_RficMode_GPS_ZIF             = 1,
   GNSS_RficMode_GPS_LIF             = 2,
   GNSS_RficMode_GNSS_Concurrent_LIF = 5
} GNSS_RficMode_type;

typedef enum
{
   GNSS_RficLinearityState_Low  = 0,
   GNSS_RficLinearityState_High = 1
} GNSS_RficLinearityState_type;

typedef enum
{
   GNSS_RfPllLockStatus_Unknown    = 0,
   GNSS_RfPllLockStatus_Locked     = 1,
   GNSS_RfPllLockStatus_NotLocked  = 2
} GNSS_RfPllLockStatus_type;

/**
Format for CGPS RF Status
GPS_DEMOD_SOFT_DECISIONS_LOG            = 0x1253
*/
typedef struct
{
   unsigned char Version;
   unsigned char SvPrn;
   unsigned short DemodId;
   unsigned long BitId;
   unsigned short SoftDecision[20];
   unsigned char NumberOfBits;
} CGPS_Demod_Soft_Decisions_Struct;

typedef struct
{
   unsigned char    Version;
   unsigned char    GnssType;
   byte             SvPrn;
   dword            BitId;
   unsigned char    NumberOfBits;
   short            SoftDecision[20];
   dword            RESERVED_1;
   dword            RESERVED_2;
} GNSS_Demod_Soft_Decisions_Struct;

/**
Format for the sample data blocks in LOG_GNSS_INJECT_SENSOR_DATA
*/
typedef struct
{
   uint16           w_SampleTimeOffset;
   union
   {
      float           f_xAxisSample;
      byte             b_xAxisSampleRaw[4];
      uint32           dw_xAxisSampleRawUint;
   };
   union
   {
      float           f_yAxisSample;
      byte             b_yAxisSampleRaw[4];
      uint32           dw_yAxisSampleRawUint;
   };
   union
   {
      float           f_zAxisSample;
      byte             b_zAxisSampleRaw[4];
      uint32           dw_zAxisSampleRawUint;
   };
} GNSS_Inject_Sensor_Data_Samples;

typedef enum
{
   GNSS_Sensor_Undefined                 = 0x00,
   GNSS_Sensor_Accelerometer             = 0x01,
   GNSS_Sensor_Gyro                      = 0x02,
   GNSS_Sensor_Magnetometer              = 0x03,
   GNSS_Sensor_Accelerometer_Temperature = 0x04,
   GNSS_Sensor_Gyro_Temperature          = 0x08,
   GNSS_Sensor_Last                      = 0xFF    // Keep at end of list
} GNSS_Sensor_Logged_Type;

#define MAX_SENSOR_SAMPLES 50

/**
Format for LOG_GNSS_INJECT_SENSOR_DATA       = 0x1510
*/
typedef struct
{
   uint8            version;
   uint8            u_SensorLogged;
   uint32           dw_TimeOfFirstSample;
   uint8            u_Flags;
   uint8            u_NumSamples;
   GNSS_Inject_Sensor_Data_Samples SensorSamples[MAX_SENSOR_SAMPLES];
} GNSS_Inject_Sensor_Data_v1;

typedef struct
{
   uint8            version;
   uint8            u_SensorLogged;
   uint16           w_TimeGpsWeekOfFirstSample;
   uint32           dw_TimeGpsMsecOfFirstSample;
   uint32           dw_SensorTimeOfFirstSample;
   uint8            u_Flags;
   uint8            u_NumSamples;
   GNSS_Inject_Sensor_Data_Samples SensorSamples[MAX_SENSOR_SAMPLES];
} GNSS_Inject_Sensor_Data_v2;

typedef enum
{
   GNSS_GnssTypeGPS  = 1,
   GNSS_GnssTypeGlonass = 2,
   GNSS_GnssTypeBDS = 3,
   GNSS_GnssTypeGAL = 4
} GNSS_GnssType_type;

/**
Format for CGPS ME Job Info
CGPS_ME_JOB_INFO_LOG                = 0x13BA
*/
typedef struct
{
   unsigned short w_JobSeqCnt; /* Job sequence count */
   unsigned char  u_JobType;   /* Job Type */
   unsigned char  u_Sv;        /* SV being specified in the Job */
} CGPS_mc_JobIDType;

typedef struct
{
   unsigned char        u_Version;     /* Version id of this log */
   unsigned char        u_Cno;         /* baseband C/N0 of detected signal in dBHz. 0 means no signal found */
   unsigned char        u_Sensitivity; /* baseband sensitivity of the search attempted in dBHz */
   unsigned short       w_CodePhase;   /* code phase in chipx1 */
   unsigned short       x_Doppler;     /* doppler in Hz */
   CGPS_mc_JobIDType    q_JobId;       /* JobId */
   unsigned long int    q_FCount;      /* FCount */
} CGPS_ME_JobInfo;

/* Enumeration of the various job types */
typedef enum
{
   CGPS_MC_TYPE_MSA_JOB,
   CGPS_MC_TYPE_FAST_SCAN_JOB,
   CGPS_MC_TYPE_DEEP_JOB,
   CGPS_MC_TYPE_SHALLOW_KNOWN_JOB,
   CGPS_MC_TYPE_SHALLOW_UNKNOWN_JOB,
   CGPS_MC_TYPE_SIDE_LOBE_SCAN_JOB,
   CGPS_MC_TYPE_VERIFY_JOB,
   CGPS_MC_TYPE_VERIFY_TRACK_JOB,
   CGPS_MC_TYPE_BIT_EDGE_JOB,
   CGPS_MC_TYPE_TRACK_JOB,
   CGPS_MC_TYPE_FTM_JOB,
   CGPS_MC_TYPE_PD_JOB,                    /* Prescribed dwell job */
   CGPS_MC_TYPE_SBAS_SEARCH_JOB,
   CGPS_MC_TYPE_DPO_JOB,
   CGPS_MC_TYPE_JOB_END = CGPS_MC_TYPE_DPO_JOB
} CGPS_mc_JobEnumType;

/**
Parameters for QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH
*/

/**
Enumeration for QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH() -> iFlag field
*/
typedef enum
{
   GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE         = 0x00, //!< ' Enter Standalone RF verification mode
   GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE         = 0x01  //!< ' Exit Standalone RF verification mode
} gps_sa_rf_verif_mode_switch_enum_type;

/**
Parameters for QLIB_DIAG_GNSS_SOC_SA_RF_VERIF_MODE_SWITCH
*/

/**
Enumeration for QLIB_DIAG_GNSS_SOC_SA_RF_VERIF_MODE_SWITCH() ->
iFlag field
*/
typedef enum
{
   GNSS_SOC_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE        = 0x00, //!< ' Enter Standalone RF verification mode
   GNSS_SOC_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE         = 0x01  //!< ' Exit Standalone RF verification mode
} gnss_soc_sa_rf_verif_mode_switch_enum_type;

/**
Parameters for QLIB_DIAG_GPS_PRESCRIBED_DWELL
*/

/**
Enumerations for QLIB_DIAG_GPS_PRESCRIBED_DWELL() -> iFlags field -> bit field

Bit mask to define request.  Bitmask values defined by
Bit 0 = Send dwell results
Bit 1 = 0/1 - Chipx1 / Chipx2
Bit 2 = Report Incoherent Sums
Bit 3 = Report Coherent Sums
Bit 4 = 00 - Start now; 1-Use TOA;
Bit  = Reserved
Bit 6 = Use RF/TS
Bit 7 = Initialize TS and BC at start of dwell (Applicable only if TS is used).
Bit[15:8] = Reserved
*/
typedef enum
{
   GPS_PRESCRIBED_DWELL_NO_RESULTS                      = 0x00, //!< ' Do not send dwell results
   GPS_PRESCRIBED_DWELL_SEND_RESULTS                    = 0x01  //!< ' Send dwell results
} gps_prescribed_dwell_results_enum_type;   //Bit 0

typedef enum
{
   GPS_PRESCRIBED_DWELL_CHIPX1                          = 0x00, //!< ' Chipx1
   GPS_PRESCRIBED_DWELL_CHIPX2                          = 0x02  //!< ' Chipx2
} gps_prescribed_dwell_chip_rate_enum_type; //Bit 1

typedef enum
{
   GPS_PRESCRIBED_DWELL_NO_INCOHER_SUMS                 = 0x00, //!< ' Do not report incoherent sums
   GPS_PRESCRIBED_DWELL_REPORT_INCOHER_SUMS             = 0x04  //!< ' Report incoherent sums
} gps_prescribed_dwell_incoher_sums_enum_type;  //Bit 2

typedef enum
{
   GPS_PRESCRIBED_DWELL_NO_COHER_SUMS                   = 0x00, //!< ' Do not report coherent sums
   GPS_PRESCRIBED_DWELL_REPORT_COHER_SUMS               = 0x08  //!< ' Report coherent sums
} gps_prescribed_dwell_coher_sums_enum_type;    //Bit 3

typedef enum
{
   GPS_PRESCRIBED_DWELL_START_NOW                       = 0x00, //!< ' Start now
   GPS_PRESCRIBED_DWELL_USE_TOA                     = 0x10  //!< ' Use TOA
} gps_prescribed_dwell_start_time_enum_type;    //Bit[5:4]

typedef enum
{
   GPS_PRESCRIBED_DWELL_USE_RF                      = 0x00, //!< ' Use RF
   GPS_PRESCRIBED_DWELL_USE_TS                          = 0x40  //!< ' Use TS
} gps_prescribed_dwell_source_enum_type;        //Bit 6

typedef enum
{
   GPS_PRESCRIBED_DWELL_NO_INIT                     = 0x00, //!< ' Do not initialize TS and BC at start of dwell
   GPS_PRESCRIBED_DWELL_INIT_TS_AND_BC                  = 0x80  //!< ' Initialize TS and BC at start of dwell
} gps_prescribed_dwell_source_init_type;        //Bit 7

/**
Enumeration for QLIB_DIAG_GPS_PRESCRIBED_DWELL() -> iSearchMode field
*/
typedef enum
{
   GPS_PRESCRIBED_DWELL_SEARCH_MODE_0          = 0x00, //!< ' Pre-Detection Mode 0: Search Time 10ms
   GPS_PRESCRIBED_DWELL_SEARCH_MODE_1         = 0x01, //!< ' Pre-Detection Mode 1: Search Time 20ms
   GPS_PRESCRIBED_DWELL_SEARCH_MODE_2         = 0x02, //!< ' Pre-Detection Mode 2: Search Time 160ms
   GPS_PRESCRIBED_DWELL_SEARCH_MODE_3         = 0x03, //!< ' Pre-Detection Mode 3: Search Time 20ms BET
   GPS_PRESCRIBED_DWELL_SEARCH_MODE_4         = 0x04, //!< ' Pre-Detection Mode 4: Search Time 20ms P75
   GPS_PRESCRIBED_DWELL_SEARCH_MODE_5         = 0x05, //!< ' Pre-Detection Mode 5: Search Time 2ms
   GPS_PRESCRIBED_DWELL_SEARCH_MODE_6         = 0x06  //!< ' Pre-Detection Mode 6: Search Time 2ms BET
} gps_prescribed_dwell_search_mode_enum_type;

#define GPS_SV_TRACK_ALL 0  //!< The SV ID 0 for GPS_SV_TRACK indicates that all SV's should be tracked

/**
Parameters for QLIB_DIAG_GPS_START_IQ_TEST()
*/

/**
Enumerations for QLIB_DIAG_GPS_START_IQ_TEST() -> iRequests field -> bit field

Bit mask to define request.  Bitmask values defined by
Bit[1:0] = 00-No FFT Report; 01-Report FFT; 10-Report FFT. Use Hanning window; 11=Reserved.
Bit 2 = 0-Do not report raw IQ samples; 1-Report raw IQ samples.
Bit 3 = 1-Report narrowband peak profile.
Bit 4: RTC selection (ignored if phone is in UMTS mode). 0-GPS; 1-CDMA.
Bit 5: Start Mode. 0-Start immediately; 1-Start synchronous to FCount.
Bit[7:6]: Reserved.

*/
typedef enum
{
   GPS_START_IQ_TEST_REQ_NO_FFT                     = 0x00, //!< ' No FFT Report.
   GPS_START_IQ_TEST_REQ_FFT                            = 0x01, //!< ' Report FFT.
   GPS_START_IQ_TEST_REQ_FFT_HANNING                    = 0x02  //!< ' Report FFT. Use Hanning window.
} gps_start_iq_test_req_fft_enum_type;  //Bit[1:0]

typedef enum
{
   GPS_START_IQ_TEST_REQ_IQ_NO_SAMPLES                  = 0x00, //!< ' Do not report raw IQ samples.
   GPS_START_IQ_TEST_REQ_IQ_REPORT_SAMPLES              = 0x04  //!< ' Report raw IQ samples.
} gps_start_iq_test_req_iq_enum_type;   //Bit2

typedef enum
{
   GPS_START_IQ_TEST_REQ_NO_NARROWBAND_PEAK_PROFILE = 0x00, //!< ' Report no narrowband peak profile.
   GPS_START_IQ_TEST_REQ_NARROWBAND_PEAK_PROFILE        = 0x08  //!< ' Report narrowband peak profile.
} gps_start_iq_test_req_peak_profile_enum_type; //Bit3

typedef enum
{
   GPS_START_IQ_TEST_REQ_RTC_GPS                        = 0x00, //!< ' RTC selection is GPS
   GPS_START_IQ_TEST_REQ_RTC_CDMA                       = 0x10  //!< ' RTC selection is CDMA
} gps_start_iq_test_req_rtc_select; //Bit4

typedef enum
{
   GPS_START_IQ_TEST_REQ_START_IMMED                    = 0x00, //!< ' Start immediately
   GPS_START_IQ_TEST_REQ_START_SYNC_FCOUNT              = 0x20  //!< ' Start synchronous to Fcount
} gps_start_iq_test_req_start_mode; //Bit5

typedef enum
{
   IQTEST_FLAG_ENABLE_IQ_LOGGING            = 0x1,
   IQTEST_FLAG_ENABLE_FFT_LOGGING           = 0x2,
   IQTEST_FLAG_ENABLE_HANNING               = 0x4,
   IQTEST_FLAG_DISABLE_DROPPED_LOG_RECOVERY = 0x8
} gps_start_iq_test_req_gen8;

typedef enum
{
   IQ_TEST_CONTROL_START,
   IQ_TEST_CONTROL_STOP,
   IQ_TEST_CONTROL_CONTINUE,
   IQ_TEST_CONTROL_RETRANSMIT,
   IQ_TEST_CONTROL_MAX
} gps_start_iq_test_control_gen8;

typedef enum
{
   COLLECT_MODE_WBIQ_BP1_BP2_2MHZ,
   COLLECT_MODE_WBIQ_BP1_2MHZ,
   COLLECT_MODE_WBIQ_BP2_2MHZ,
   COLLECT_MODE_WBIQ_BP3_1MHZ,
   COLLECT_MODE_FBIQ_BP4_20MHZ,
   COLLECT_MODE_NBIQ_BP1_AUTO_1KHZ,
   COLLECT_MODE_NBIQ_BP2_AUTO_1KHZ,
   COLLECT_MODE_NBIQ_BP3_AUTO_1KHZ,
   COLLECT_MODE_NBIQ_BP1_MANUAL_1KHZ,
   COLLECT_MODE_NBIQ_BP2_MANUAL_1KHZ,
   COLLECT_MODE_NBIQ_BP3_MANUAL_1KHZ,
   COLLECT_MODE_NBIQ_BP4_MANUAL_1KHZ,
   COLLECT_MODE_ADC1_16_POINT_8_MHZ,
   COLLECT_MODE_ADC2_16_POINT_8_MHZ,
   COLLECT_MODE_ADC1_ADC2_21_MHZ,
   COLLECT_MODE_FBIQ_BP3_10MHZ,
   COLLECT_MODE_81_MHZ_ADC_IQ,
   COLLECT_MODE_WBIQ_BP2_4MHZ, // Beidou
   COLLECT_MODE_WBIQ_GAL,
   COLLECT_MODE_MAX
} gps_start_iq_test_collect_mode_gen8;

/**
Enumerations for QLIB_DIAG_GPS_START_IQ_TEST() -> iTestSourceInfo field -> bit field

Bit mask to define Test Source information.  Bitmask values defined by
Bit 0: 0/1 Input to SD is from RF/TS.
Bit [1:6]: SV Id.
Bit 7: 0/1 Data OFF/ON.
Bit 8: 0/1 Noise ON/OFF.
Bit [15:9]: Reserved
Bits 1 to 8 are valid only when input to SD from TS.
*/
typedef enum
{
   GPS_START_IQ_TEST_TS_INPUT_RF                    = 0x00, //!< ' Input to SD is RF.
   GPS_START_IQ_TEST_TS_INPUT_TS                    = 0x01  //!< ' Input to SD is TS(Test Source).
} gps_start_iq_test_ts_input_enum_type; //Bit 0

typedef enum
{
   GPS_START_IQ_TEST_TS_SV_ID_0                 = 0x00, //!< ' SV Id = 0
   GPS_START_IQ_TEST_TS_SV_Id_1                 = 0x02, //!< ' SV Id = 1
   GPS_START_IQ_TEST_TS_SV_Id_2                 = 0x04, //!< ' SV Id = 2
   GPS_START_IQ_TEST_TS_SV_Id_3                 = 0x06, //!< ' SV Id = 3
   GPS_START_IQ_TEST_TS_SV_Id_4                 = 0x08, //!< ' SV Id = 4
   GPS_START_IQ_TEST_TS_SV_Id_5                 = 0x0A, //!< ' SV Id = 5
   GPS_START_IQ_TEST_TS_SV_Id_6                 = 0x0C, //!< ' SV Id = 6
   GPS_START_IQ_TEST_TS_SV_Id_7                 = 0x0E, //!< ' SV Id = 7
   GPS_START_IQ_TEST_TS_SV_Id_8                 = 0x10, //!< ' SV Id = 8
   GPS_START_IQ_TEST_TS_SV_Id_9                 = 0x12, //!< ' SV Id = 9
   GPS_START_IQ_TEST_TS_SV_Id_10                    = 0x14, //!< ' SV Id = 10
   GPS_START_IQ_TEST_TS_SV_Id_11                    = 0x16, //!< ' SV Id = 11
   GPS_START_IQ_TEST_TS_SV_Id_12                    = 0x18, //!< ' SV Id = 12
   GPS_START_IQ_TEST_TS_SV_Id_13                    = 0x1A, //!< ' SV Id = 13
   GPS_START_IQ_TEST_TS_SV_Id_14                    = 0x1C, //!< ' SV Id = 14
   GPS_START_IQ_TEST_TS_SV_Id_15                    = 0x1E, //!< ' SV Id = 15
   GPS_START_IQ_TEST_TS_SV_Id_16                    = 0x20, //!< ' SV Id = 16
   GPS_START_IQ_TEST_TS_SV_Id_17                    = 0x22, //!< ' SV Id = 17
   GPS_START_IQ_TEST_TS_SV_Id_18                    = 0x24, //!< ' SV Id = 18
   GPS_START_IQ_TEST_TS_SV_Id_19                    = 0x26, //!< ' SV Id = 19
   GPS_START_IQ_TEST_TS_SV_Id_20                    = 0x28, //!< ' SV Id = 20
   GPS_START_IQ_TEST_TS_SV_Id_21                    = 0x2A, //!< ' SV Id = 21
   GPS_START_IQ_TEST_TS_SV_Id_22                    = 0x2C, //!< ' SV Id = 22
   GPS_START_IQ_TEST_TS_SV_Id_23                    = 0x2E, //!< ' SV Id = 23
   GPS_START_IQ_TEST_TS_SV_Id_24                    = 0x30, //!< ' SV Id = 24
   GPS_START_IQ_TEST_TS_SV_Id_25                    = 0x32, //!< ' SV Id = 25
   GPS_START_IQ_TEST_TS_SV_Id_26                    = 0x34, //!< ' SV Id = 26
   GPS_START_IQ_TEST_TS_SV_Id_27                    = 0x36, //!< ' SV Id = 27
   GPS_START_IQ_TEST_TS_SV_Id_28                    = 0x38, //!< ' SV Id = 28
   GPS_START_IQ_TEST_TS_SV_Id_29                    = 0x3A, //!< ' SV Id = 29
   GPS_START_IQ_TEST_TS_SV_Id_30                    = 0x3C, //!< ' SV Id = 30
   GPS_START_IQ_TEST_TS_SV_Id_31                    = 0x3E, //!< ' SV Id = 31
} gps_start_iq_test_ts_sv_id_enum_type; //Bit[6:1]

typedef enum
{
   GPS_START_IQ_TEST_TS_DATA_OFF                    = 0x00, //!< ' Data Off
   GPS_START_IQ_TEST_TS_DATA_ON                 = 0x80  //!< ' Data On
} gps_start_iq_test_ts_data_enum_type;  //Bit 7

typedef enum
{
   GPS_START_IQ_TEST_TS_NOISE_OFF                   = 0x00, //!< ' Noise Off
   GPS_START_IQ_TEST_TS_NOISE_ON                    = 0x100 //!< ' Noise On
} gps_start_iq_test_ts_noise_enum_type; //Bit 8

/**
Enumeration for QLIB_DIAG_GPS_START_IQ_TEST() -> iSM_Point field
This enumeration defines the block from which signal collection must be done.
0-Dual point SM collect;
1-Single point SM collect, Channel 0;
2-Single point SM collect, Channel 1;
3-Any other point (single point);
4-255-Reserved
*/
typedef enum
{
   GPS_START_IQ_TEST_SM_DUAL_POINT_SM               = 0x00, //!< ' Dual point SM collect.
   GPS_START_IQ_TEST_SM_SINGLE_POINT_SM_0           = 0x01, //!< ' Single point SM collect, Channel 0.
   GPS_START_IQ_TEST_SM_SINGLE_POINT_SM_1           = 0x02, //!< ' Single point SM collect, Channel 1.
   GPS_START_IQ_TEST_SM_SINGLE_POINT_OTHER          = 0x03  //!< ' Any other point (single point).
} gps_start_iq_test_sm_point_enum_type;

/**
Enumeration for QLIB_DIAG_GPS_START_IQ_TEST() -> iCollectPoint field
This enumeration defines the Collection Point as follows:
If "Dual point" or "Single point, channel 0" is chosen above (iSM_Point):
Bit[2:0] allow one of 7 collection points to be routed to the lower 16 bits of the test output.
Bit[5:3] allow one of 7 other collection points to be routed on the higher 16 bits of the test output.
Test output is a collection of 32-bit words (two int16s).
If Collection point is "BC signal log", sample frequency is chosen using Bit[7:6]. See below.
*/

/**
Enumeration for QLIB_DIAG_GPS_START_IQ_TEST() -> iCollectPoint field -> Bit[2:0]
*/

typedef enum
{
   GPS_START_IQ_TEST_COLLECT_LOWER16BITS_NONE                       = 0x00, //!< ' Collection Point = None
   GPS_START_IQ_TEST_COLLECT_LOWER16BITS_MISC_BITS                  = 0x01, //!< ' Collection Point = Misc Bits (reset, Test Strobe etc.)
   GPS_START_IQ_TEST_COLLECT_LOWER16BITS_BC_OUTPUT                  = 0x02, //!< ' Collection Point = BC Output
   GPS_START_IQ_TEST_COLLECT_LOWER16BITS_TS_I_NON_QUANT         = 0x03, //!< ' Collection Point = TS 'I', non-quantized
   GPS_START_IQ_TEST_COLLECT_LOWER16BITS_BC_I_FILTER_OUT            = 0x04, //!< ' Collection Point = BC 'I' filter output
   GPS_START_IQ_TEST_COLLECT_LOWER16BITS_BC_I_NON_QUANT         = 0x05, //!< ' Collection Point = BC 'I', non-quantized
   GPS_START_IQ_TEST_COLLECT_LOWER16BITS_BC_SIGNAL_LOG              = 0x06, //!< ' Collection Point = BC signal log, lower 16 bits
   GPS_START_IQ_TEST_COLLECT_LOWER16BITS_RTC_INPUT                  = 0x07  //!< ' Collection Point = RTC input, Chip and cycle count
} gps_start_iq_test_collect_lower16bits_enum_type;  //Bit[2:0], Valid if "Dual point" or "Single point, channel0" is chosen above in gps_start_iq_test_sm_point_enum_type

/**
Enumeration for QLIB_DIAG_GPS_START_IQ_TEST() -> iCollectPoint field -> Bit[5:3]
*/

typedef enum
{
   GPS_START_IQ_TEST_COLLECT_HIGHER16BITS_TS_IQ                 = 0x00, //!< ' Collection Point = TS 'IQ'
   GPS_START_IQ_TEST_COLLECT_HIGHER16BITS_MISC_BITS             = 0x08, //!< ' Collection Point = Rx 'IQ' input
   GPS_START_IQ_TEST_COLLECT_HIGHER16BITS_BC_OUTPUT             = 0x0A, //!< ' Collection Point = Aux 'IQ' input
   GPS_START_IQ_TEST_COLLECT_HIGHER16BITS_TS_I_NON_QUANT            = 0x18, //!< ' Collection Point = TS 'Q', non-quantized
   GPS_START_IQ_TEST_COLLECT_HIGHER16BITS_BC_I_FILTER_OUT           = 0x20, //!< ' Collection Point = BC 'Q' filter output
   GPS_START_IQ_TEST_COLLECT_HIGHER16BITS_BC_I_NON_QUANT            = 0x28, //!< ' Collection Point = BC 'Q', non-quantized
   GPS_START_IQ_TEST_COLLECT_HIGHER16BITS_BC_SIGNAL_LOG         = 0x30, //!< ' Collection Point = BC signal log, upper 16 bits
   GPS_START_IQ_TEST_COLLECT_HIGHER16BITS_RTC_INPUT             = 0x38  //!< ' Collection Point = RTC input, FC
} gps_start_iq_test_collect_higher16bits_enum_type; //Bit[5:3], Valid if "Dual point" or "Single point, channel1" is chosen above in gps_start_iq_test_sm_point_enum_type

/**
Enumeration for QLIB_DIAG_GPS_START_IQ_TEST() -> iCollectPoint field -> Bit[7:6]
*/
typedef enum
{
   GPS_START_IQ_TEST_COLLECT_SAMPLE_FREQ_4BIT_I_16MHZ               = 0x00, //!< ' Sample Frequency = 4-bit I at 16.368MHz. Valid if collection point is "BC signal log"
   GPS_START_IQ_TEST_COLLECT_SAMPLE_FREQ_4BIT_Q_16MHZ               = 0x40, //!< ' Sample Frequency = 4-bit Q at 16.368MHz. Valid if collection point is "BC signal log"
   GPS_START_IQ_TEST_COLLECT_SAMPLE_FREQ_2BIT_IQ_16MHZ              = 0x80, //!< ' Sample Frequency = 2-bit I and Q at 16.368MHz. Valid if collection point is "BC signal log"
   GPS_START_IQ_TEST_COLLECT_SAMPLE_FREQ_4BIT_IQ_8MHZ               = 0xC0  //!< ' Sample Frequency = 4-bit I and Q at 8.1844MHz. Valid if collection point is "BC signal log"
} gps_start_iq_test_collect_sample_freq_enum_type;  //Bit[7:6], Valid if collection point is "BC signal log"

/**
Enumeration for QLIB_DIAG_GPS_START_IQ_TEST() -> iCollectPoint field -> Bit[7:0] if "Other" is chosen in "SM_Point"
*/
typedef enum
{
   GPS_START_IQ_TEST_COLLECT_OTHER_SAMPLE_SERVER_2MHZ               = 0x00, //!< ' Collection Point = Sample Server, 2MHz. Valid if "Other" is chosen in "SM_Point"
   GPS_START_IQ_TEST_COLLECT_OTHER_SAMPLE_SERVER_1KHZ               = 0x01, //!< ' Sample Frequency = Sample Server, 1kHz. Valid if "Other" is chosen in "SM_Point"
   GPS_START_IQ_TEST_COLLECT_OTHER_DEC_OFFSET_ESTIMATOR         = 0x02, //!< ' Sample Frequency = DC Offset estimator. Valid if "Other" is chosen in "SM_Point"
   GPS_START_IQ_TEST_COLLECT_OTHER_AFLT                         = 0x03, //!< ' Sample Frequency = AFLT. Valid if "Other" is chosen in "SM_Point"
   GPS_START_IQ_TEST_COLLECT_OTHER_AFLT_AND_BC                      = 0x04  //!< ' Sample Frequency = AFLT and BC simultaneous. Valid if "Other" is chosen in "SM_Point"
} gps_start_iq_test_collect_other_enum_type;    //Bit[7:0], Valid if "Other" is chosen in "SM_Point"

/**
Below this are CGPS defintitions introduced by QMSL, above are defitions created by the CGPS ICD document
*/

/**
Structure for parameters for QLIB_DIAG_GPS_START_IQ_TEST()
*/
typedef struct
{
   /**
   Defines the request for FFT, IQ samples, Narrowband peak profile, RTC Selection, and Start Mode.

   These requests are combined into a single byte using the following enumeration values
   \code
   FFT                      - gps_start_iq_test_req_fft_enum_type
   IQ samples               - gps_start_iq_test_req_iq_enum_type
   Narrow band peak profile - gps_start_iq_test_req_peak_profile_enum_type
   RTC Selection            - gps_start_iq_test_req_rtc_select
   Start Mode               - gps_start_iq_test_req_start_mode
   \endcode

   Example:
   gps_start_iq_test_struct_type oIQ_Test;
   oIQ_Test.iRequests = GPS_START_IQ_TEST_REQ_FFT | GPS_START_IQ_TEST_REQ_IQ_REPORT_SAMPLES | GPS_START_IQ_TEST_REQ_START_IMMED;
   */

   /**
   Bit mask to define requests.  Bitmask values defined by
   Bit[1:0] = 00-No FFT Report; 01-Report FFT; 10-Report FFT. Use Hanning window; 11=Reserved.
   Bit 2 = 0-Do not report raw IQ samples; 1-Report raw IQ samples.
   Bit 3 = 1-Report narrowband peak profile.
   Bit 4: RTC selection (ignored if phone is in UMTS mode). 0-GPS; 1-CDMA.
   Bit 5: Start Mode. 0-Start immediately; 1-Start synchronous to FCount.
   Bit[7:6]: Reserved.
   */
   unsigned char iRequests;

   /**
   FCount. Unsigned. Applicable only if set to "Start Mode" in "iRequests" field above.
   */
   unsigned long iFCount;

   /**
   Bit mask to define Test Source information.  Bitmask values defined by
   Bit 0: 0/1 Input to SD is from RF/TS.
   Bit [1:6]: SV Id.
   Bit 7: 0/1 Data OFF/ON.
   Bit 8: 0/1 Noise ON/OFF.
   Bit [9:15]: Reserved
   Bits 1 to 8 are valid only when input to SD from TS.
   */

   unsigned short iTestSourceInfo;

   /**
   Unsigned value in dBHz. This field is valid only when TS is enabled.
   */
   unsigned char iTestSourceSignalStrength;

   /**
   Signed value (1000/65536 Hz/Bit). This field is valid only when TS is enabled.
   */
   //unsigned short iTestSourceDoppler;
   long iTestSourceDoppler; //Changed to long in order to match the Perl file IqTest.pm

   /**
   Number of Samples collected in multiples of 1024 samples, limit is CGPS_SAMPLE_GROUP_COUNT_MAX
   */
   unsigned short iKiloSamples;

   /**
   Number of FFT integrations. 0:1000-Number of integrations. 1001-65,536-Reserved. Applicable only if FFT reporting is chosen.
   */
   unsigned short iFFT_Integration;

   /**
   This enumeration defines the block from which signal collection must be done.
   0-Dual point SM collect;
   1-Single point SM collect, Channel 0;
   2-Single point SM collect, Channel 1;
   3-Any other point (single point);
   4-255-Reserved
   */
   unsigned char iSM_Point;

   /**
   This enumeration defines the Collection Point as follows:
   If "Dual point" or "Single point, channel 0" is chosen above (iSM_Point):
   Bit[2:0] allow one of 7 collection points to be routed to the lower 16 bits of the test output.
   Bit[5:3] allow one of 7 other collection points to be routed on the higher 16 bits of the test output.
   Test output is a collection of 32-bit words (two int16s).
   If Collection point is "BC signal log", sample frequency is chosen using Bit[7:6]. See below.
   */
   unsigned char iCollectPoint;

   /**
   0:6 - Number of bits to shift samples in GPS Searcher.
   7:255 - Reserved.
   Shift 0 shifts for for weak signals
   Shift 6 shifts for for strong signals
   */
   unsigned char iScale;

   /**
   Initial Collection Start Delay. Range: 0 to 65535 ms.
   */
   unsigned short iStartDelay;

   /**
   Wideband FFT Center Frequency. Signed: Sample_Rate/2^32 per bit.
   Range: -Sample_Rate/2 to Sample_Rate/2 Hz.
   Applicable only when collect point are after cordic.
   Else center frequency is zero.
   */
   unsigned long iWidebandCenterFreq;

   /**
   Narrowband FFT Center Frequency. Signed: Sample_Rate/2^32 per bit.
   Range: -Sample_Rate/2 to Sample_Rate/2 Hz.
   Applicable only when collect point are after cordic.
   Else center frequency is zero.
   */
   unsigned long iNarrowbandCenterFreq;

   /**
   Number of Wideband Peaks to identify. Range: 0 to 255.
   */
   unsigned char iNumWidebandPeaks;

   /**
   Number of Samples on Each Side of Peak to Include in Peak Sum. Range: 0 to 255.
   */
   unsigned char iNumWidebandAdjSamples;

   /**
   Number of Narrowband Peaks to identify. Range: 0 to 255.
   */
   unsigned char iNumNarrowbandPeaks;

   /**
   Number of Samples on Each Side of Peak to Include in Peak Sum. Range: 0 to 255.
   */

   unsigned char iNumNarrowbandAdjSamples;
} gps_start_iq_test_struct_type;

/**
Commands for QLIB_DIAG_GPS_SV_TRACK() request
*/
typedef enum
{
   GPS_SV_TRACK_START_CLEAR_ALL = 1,                //!< ' CGPS engine starts tracking and clears any satellites currently being tracked
   GPS_SV_TRACK_START_NO_CLEAR      = 2,                //!< ' CGPS engine starts tracking without clearing the satellites currently being tracked
   GPS_SV_TRACK_STOP_CLEAR_ALL      = 3,                //!< ' CGPS engine stops tracking and clears any satellites currently being tracked
   GPS_SV_TRACK_STOP_NO_CLEAR       = 4,                    //!< ' CGPS engine stops tracking without clearing the satellites currently being tracked
   GPS_SV_TRACK_START_CLEAR_ALL_NO_BITEDGE_DETECTION = 5,   //!< ' CGPS engine starts tracking, clears all, and does not use bit edge detection
   GPS_SV_TRACK_START_NO_CLEAR_NO_BITEDGE_DETECTION = 6,    //!< ' CGPS engine starts tracking, does not clear, and does not use bit edge detection
   GPS_SV_TRACK_START_CLEAR_ALL_FORCE_DPO = 7,              //!< ' CGPS engine starts tracking in Dynamic Power Optimization mode clearing current status
   GPS_SV_TRACK_START_NO_CLEAR_FORCE_DPO = 8,               //!< ' CGPS engine starts tracking in Dynamic Power Optimization mode without clearing current status
   GPS_SV_TRACK_START_SBAS_CLEAR_ALL = 9,                   //!< ' CGPS engine starts tracking in SBAS Mode clearing current status
   GPS_SV_TRACK_START_SBAS_NO_CLEAR = 10,                   //!< ' CGPS engine starts tracking in SBAS Mode without clearing current status
   GPS_SV_TRACK_START_SBAS_CLEAR_ALL_NO_SYMBOL_EDGE_DETECTION = 11, //!< ' CGPS engine starts tracking in SBAS Mode, clears current status, no SED
   GPS_SV_TRACK_START_SBAS_NO_CLEAR_NO_SYMBOL_EDGE_DETECTION = 12       //!< ' CGPS engine starts tracking in SBAS Mode without clearing current status, no SED
} gps_sv_track_command_enum_type;

/*
Enums for GEN 8 Multi-Channel Tracking Types
*/
typedef enum
{
   MultiChan_Track_PRI_GLO_HBW_U   = 0,
   MultiChan_Track_PRI_GLO_RxD     = 1,
   MultiChan_Track_PRI_GLO         = 2,
   MultiChan_Track_PRI_RxD_Linked  = 3,
   SinglChan_Track_PRI             = 4,
   SinglChan_Track_GLO             = 5,
   MultiChan_Track_SBAS            = 6,
   SinglChan_GPS_DPO               = 7,
   SinglChan_Track_RxD             = 8,
   SinglChan_Track_PRI_HBW_U       = 9,
   SinglChan_Track_PRI_HBW_NU4     = 10,
   SinglChan_Track_PRI_HBW_NU8     = 11,
   MultiChan_Track_BDS             = 12,
   MultiChan_Track_PRI_BDS         = 13,
   MultiChan_Track_PRI_GLO_BDS     = 14,
   MultiChan_Track_PRI_GLO_BDS_GAL = 15,
   MultiChan_Track_GAL             = 16,
   MultiChan_Track_PRI_GAL         = 17,
   MultiChan_Track_PRI_BDS_GAL     = 18,
   MultiChan_Track_PRI_GLO_GAL     = 19
} gnss_multichan_track_test_enum_type;

/**
CGPS Event types

These are events, which can be receipt of logs or events. They constitute a particular event
in the CGPS behavior for QMSL.

*/
typedef enum
{
   /*
   Enter / exit verification mode.  When entering or exiting the verification mode
   it is possible to recieve either an error, or the event which indicates the mode
   switch was successful
   */
   CGPS_Enter_Verification_Mode,                //!<' Mapped to event _EVENT_GPS_LM_ENTER_SA_RF_VERIF
   CGPS_Exit_Verification_Mode,             //!<' Mapped to event _EVENT_GPS_LM_EXIT_SA_RF_VERIF
   CGPS_Verification_Mode_Error,                //!<' Mapped to event _EVENT_GPS_LM_ERROR_SA_RF_VERIF

   CGPS_IQ_FFT_DataReceived,                    //!<' Mapped to log CGPS_IQ_DATA_LOG
   CGPS_IQ_Test_Complete,                       //!<' Mapped to event _EVENT_GPS_LM_IQ_TEST_COMPLETE
   CGPS_Dwell_Complete,                     //!<' Mapped to event _EVENT_GPS_LM_PD_COMPLETE
   CGPS_Dwell_Status,                           //!<' Mapped to log CGPS_PRESCRIBED_DWELL_STATUS_LOG

   CGPS_GPS_MeasurementReceived,                //!<' Mapped to log CGPS_MEASUREMENT_REPORT_LOG
   CGPS_RF_Status_Recieved,                 //!<' Mapped to log CGPS_RF_STATUS_REPORT_LOG

   CGPS_Demodulation_Soft_Decision,         //!<' Mapped to log GPS_DEMOD_SOFT_DECISIONS_LOG

   GNSS_GPS_MeasurementReceived,                //!<' Mapped to log GNSS_GPS_MEASUREMENT_REPORT_LOG
   GNSS_GLONASS_MeasurementReceived,            //!<' Mapped to log GNSS_GLONASS_MEASUREMENT_REPORT_LOG
   GNSS_GPS_HBW_RXD_MeasurementReceived,        //!<' Mapped to log GNSS_GPS_HBW_RXD_MEASUREMENT_LOG
   GNSS_DEMOD_MeasurementReceived,              //!<' Mapped to log GNSS_DEMOD_SOFT_DECISIONS_LOG
   GNSS_PRX_RF_Status_Recieved,             //!<' Mapped to log GNSS_PRX_RF_HW_STATUS_REPORT_LOG
   GNSS_DRX_RF_Status_Recieved,             //!<' Mapped to log GNSS_DRX_RF_HW_STATUS_REPORT_LOG

   CGPS_WB_FFT_STATS_C_Complete,                //!<' Mapped to log LOG_CGPS_WB_FFT_STATS_C
   GNSS_Presc_Dwell_Complete,                       //!<' Mapped to event _EVENT_GNSS_PRESC_DWELL_COMPLETE
   GNSS_BroadbandJammerInfoRecieved,        //!<' Mapped to event _EVENT_GNSS_PRESC_DWELL_COMPLETE
   GNSS_FastTimeCalibrationLogRecieved,
   GNSS_TCXO_MGR_FIELD_CAL_DATARecieved,
   GNSS_TCXO_Freq_Est_DATARecieved,
   GNSS_SPECTRUM_ANALYZER_STATUS,
   GNSS_BDS_MeasurementReceived,
   GNSS_XO_FACTORY_Cal_Log_Received,          //!<' Mapped to log GNSS_XO_FACTORY_MEASUREMENT_REPORT_LOG
   GNSS_Inject_Sensor_Data_Log_Received,      //!< Mapped to GNSS_INJECT_SENSOR_DATA
   GNSS_GAL_MeasurementReceived,                //!<' Mapped to log GNSS_GPS_MEASUREMENT_REPORT_LOG
   GNSS_Factory_IQ_Test_Response_Received,      //!<' Mapped to GNSS_Factory_IQ_Test_response_results (delayed response)
   CGPS_QMSL_Event_Max                          //!<' Used to determine the last event ID for sizing arrays and error checking
} QMSL_CGPS_Event_Enum;

/*
Enums for GNSS_SOC Single-Channel Tracking Types
*/
typedef enum
{
   SingleChan_Track_GLO   = 0,
   SingleChan_Track_GPS   = 1
} gnss_soc_single_chan_track_test_enum_type;

/**
CGPS IQ FFT Common Info
*/
typedef struct
{
   byte  iVersion;
   byte  iRespType;
   dword iTotal_Pkts;
} CGPS_IQ_FFT_CommonInfo;

/**
CGPS IQ Config Info
*/
typedef struct
{
   //! Log version
   byte iLogVersion;

   // SM Point
   byte iSmPoint;

   //! Collection point
   byte iCollectPoint;

   //! Number of sample groups (groups of 1024 samples)
   word iNumSamples_1k;

   //! Total number of samples--iNumSamples_1k * 1024
   dword iNumSamples;

   //! Number of integrations, as reported by log 0x138A.  This value is known to not be valid
   word iIntegrations_FromLog;

   //! Peak power, converted to dB
   float dPeakPower_dB;

   //! Misc config info
   byte iFlags;

   //! IQ Frequency, copied as-is from the log
   unsigned long iIQ_BP_Freq;

   //! FFT frequency converted using the formula p_ConfigPkt->z_IqDM_Config.l_BP_Freq * 2.046e6/(1<<19)
   float dFFT_BP_Freq;

   //! Was hanning window used
   unsigned char bHanningWindowUsed;

   //! FFT Center
   long iFFT_CenterFreq;

   /* The following are only used for GEN8B and later */

   //! ADC Sample Frequency
   unsigned long uAdcSampleFreqHz;

   //! Sample memory size
   unsigned long uSampleMemSize;

   //! Reference oscillator offset
   long sRefOscoOffset;

   //! IF Downlink Conversion Frequency
   long sIfDownConvFreq;

   //! PGA Gain
   long sPGAGain;

   unsigned long q_PGA_SET_POINT;
   unsigned long q_ADC_VREF;
   unsigned char u_ADC_NUM_BITS;
   unsigned char u_ADC_CONFIG_FLAGS;
} CGPS_IQ_FFT_ConfigInfo;

/**
CGPS Status structure for IQ and FFT Data configuration
*/
typedef struct
{
   //! SM data Point
   byte iSmPt;

   //! Collected data point
   byte iCollectPt;

   byte iGen8CollectMode;

   //! Input file name (not used)
   char sInFileName[1024];

   //! IQ Output file name
   char sOutIqFileName[1024];

   //! FFT Output file name
   char sOutFftFileName[1024];

   //! Flag to track if IQ file should be created, if the name is not empty
   unsigned char bShouldIQ_FileBeCreated;

   //! Flag to track if FFT file should be created, if the name is not empty
   unsigned char bShouldFFT_FileBeCreated;

   //! Flag to track whether IQ File is created
   unsigned char bIqFileCreated;

   //! Flag to track whether FFT File is created
   unsigned char bFftFileCreated;

   //! Common IQ FFT Info
   CGPS_IQ_FFT_CommonInfo oCommonInfo;

   //! Common Config Info
   CGPS_IQ_FFT_ConfigInfo oConfigInfo;

   //! Number of IQ Measured samples
   unsigned long iNum_IQ_Measured_Samples;

   //! Number of FFT Measured samples
   unsigned long iNum_FFT_Measured_Samples;

   //! Number of FFT Calculated values
   unsigned long iNum_FFT_Calculated_Values;

   //! Time stamp of the first IQ data log
   byte iFirstIQ_LogTimeStamp[QMSL_DIAG_TIME_STAMP_SIZE];

   unsigned long FirstSampleFCOUNT;

   // GNSS_SOC (Griffon)
   unsigned long  u_LogsExpected;
   unsigned long  u_CurrentLog;
   short          BytesPerLog;
   unsigned char  u_LogType;
   unsigned char  u_IGain;
   unsigned char  u_QGain;
   double SigPosSave[10];
} CGPS_IQ_FFT_DataConfig;

//! Maximum number of GPS Measurement report logs that will be stored
#define CGPS_MAX_MEASUREMENTS_STORAGE 1000

//! Number of samples in a 1k sample group
#define CGPS_IQ_SAMPLE_GROUP_SIZE 1024

//! Maximum number of 1K IQ Samples
#define CGPS_IQ_SAMPLE_GROUP_COUNT_MAX 450

//! Maximum number of 1K IQ Samples
#define CGPS_GEN8_IQ_SAMPLE_GROUP_COUNT_MAX 1024

//! Maximum number of 1K FFT Samples (reported from mobile)
#define CGPS_FFT_SAMPLE_GROUP_COUNT_MAX 32

//! Maximum number of IQ samples per capture
#define CGPS_MAX_IQ_SAMPLES_PER_CAPTURE ( CGPS_IQ_SAMPLE_GROUP_COUNT_MAX * CGPS_IQ_SAMPLE_GROUP_SIZE )

//! Maximum number of IQ samples per capture
#define CGPS_GEN8_MAX_IQ_SAMPLES_PER_CAPTURE ( CGPS_GEN8_IQ_SAMPLE_GROUP_COUNT_MAX * CGPS_IQ_SAMPLE_GROUP_SIZE )

//! Maximum size of IQ data returned from the phone including all collections (0..1000), 1k sample sizes (1..450)
//! The realistic limit is 10 groups of 450k samples
#define CGPS_MAX_IQ_SAMPLES_PER_IQ_CAPTURE_COMMAND ( 10 * CGPS_IQ_SAMPLE_GROUP_COUNT_MAX * CGPS_IQ_SAMPLE_GROUP_SIZE)

//! Maximum size of IQ data returned from the phone including all collections (0..1000), 1k sample sizes (1..450)
//! The realistic limit is 10 groups of 450k samples
#define CGPS_GEN8_MAX_IQ_SAMPLES_PER_IQ_CAPTURE_COMMAND ( 30 * CGPS_GEN8_IQ_SAMPLE_GROUP_COUNT_MAX * CGPS_IQ_SAMPLE_GROUP_SIZE)

//! Maximum number of calculated FFT points based on the maximum IQ sample size
#define CGPS_MAX_CALCULATED_FFT_SAMPLES_PER_CAPTURE ( CGPS_MAX_IQ_SAMPLES_PER_CAPTURE )

//! Maximum number of calculated FFT points based on the maximum IQ sample size
#define CGPS_GEN8_MAX_CALCULATED_FFT_SAMPLES_PER_CAPTURE ( CGPS_GEN8_MAX_IQ_SAMPLES_PER_CAPTURE )

//! Maximum number of inband FFT points based on the maximum IQ sample size. WBIQ would need the max at +/- 100 kHz (12.8K for 256k sample collect).
// Allocate as a function of  sig proc mem. Allocate more than necessary.
#define CGPS_GEN8_INBAND_FFT_SAMPLES_PER_CAPTURE ( CGPS_GEN8_IQ_SAMPLE_GROUP_COUNT_MAX * CGPS_IQ_SAMPLE_GROUP_SIZE)

//! Minimum SV ID
#define CGPS_MIN_SV_ID 1

//! Maximum GPS SV ID
#define CGPS_MAX_SV_ID 32

//! Minimum SV ID
#define CGPS_MIN_SBAS_SV_ID 120

//! Maximum SV ID
#define CGPS_MAX_SBAS_SV_ID 138

//! Minimum SV ID
#define CGPS_MIN_GLONASS_SV_ID -7

//! Maximum GPS SV ID
#define CGPS_MAX_GLONASS_SV_ID 6

//! Minimum SV ID
#define CGPS_MIN_BDS_SV_ID 1

//! Maximum GPS SV ID
#define CGPS_MAX_BDS_SV_ID 37

//! Minimum SV ID
#define CGPS_MIN_GAL_SV_ID 1

//! Maximum GPS SV ID
#define CGPS_MAX_GAL_SV_ID 30

/**
Measurement summary (calculated values) structure for CGPS measurement reports
.
*/
typedef struct
{
   byte iSV_ID;             //!<' SV ID

   dword iNumReports;           //!<' Total number of reports that have been found

   // C/N
   double dC_N_Sum;     //!<' Sum of all C/N measurements, in integer form
   double dC_N_SumSquares;      //!<' Sum of the squares of C/N measurements
   double dC_N_Average_dB;      //!<' Average dB value of C_N
   double dC_N_StdDev_dB;       //!<' Standard deviation dB value of C_N
   double dC_N_Min_dB;          //!<' Minimum dB value of C_N
   double dC_N_Max_dB;          //!<' Maximum dB value of C_N

   // Speed
   double dSpeed_Sum;           //!<' Sum of all speed measurements
   double dSpeed_SumSquares;    //!<' Sum of the squares of speed
   double dSpeed_Average_mps;   //!<' Average meters per second value of Speed
   double dSpeed_StdDev_mps;    //!<' Standard deviation meters per second value of speed
   double dSpeed_Min_mps;       //!<' Minimum mps value of Speed
   double dSpeed_Max_mps;       //!<' Maximum mps value of Speed

   // Acceleration
   double dLastAcceleration;        //!<' The last calculated acceleration
   double dLastSpeed;               //!<' The last recorded speed
   dword  iLastFCOUNT;              //!<' The last recorded FCOUNT
   double dMaxAcceleration;     //!<' Maximum calculated acceleration
   dword iMaxAccelerationFCOUNT;    //!<' FCOUNT at maximum calculated acceleration
   double dMaxAccelerationTime;     //!<' iMaxAccelerationTime * 0.001

   // System processing loss
   double dSystemProcessingLoss;    //!<' 173.9 - 130.0 - dC_N_Average_dB

   // Average Acceleration
   double dLastAvgAcceleration;     //!<' The last calculated acceleration
   double dLastSpeedBuffer[12];     //!<' The last recorded speed
   dword  iLastFCOUNTBuffer[12];        //!<' The last recorded FCOUNT
   double dMaxAvgAcceleration;          //!<' Maximum calculated acceleration
   dword  iMaxAvgAccelerationFCOUNT;    //!<' FCOUNT at maximum calculated acceleration
   double dMaxAvgAccelerationTime;      //!<' iMaxAccelerationTime * 0.001
   word   iLastBufferIndex;         //!<' The last recorded speed/FCOUNT index for
   //!<' circular buffer of 12 consecutive valid values
   double dLast_5Second_AvgAcceleration;        //!<' The last calculated acceleration
   double dLast_5Second_SpeedBuffer[12];        //!<' The last recorded speed
   dword  iLast_5Second_FCOUNTBuffer[12];       //!<' The last recorded FCOUNT
   double dMax_5Second_AvgAcceleration;         //!<' Maximum calculated acceleration
   dword  iMax_5Second_AvgAccelerationFCOUNT;   //!<' FCOUNT at maximum calculated acceleration
   double dMax_5Second_AvgAccelerationTime;     //!<' iMaxAccelerationTime * 0.001
   word   iLast_5Second_BufferIndex;            //!<' The last recorded speed/FCOUNT index for
   //!<' circular buffer of 5 consecutive valid values

   // Need to add Doppler
} CGPS_MeasurementReportInfo;

/**
Measurement summary (calculated values) structure for GNSS
Broadband Jammer Info status .
*/
typedef struct
{
   byte iSV_ID;                             //!<' SV ID
   unsigned char AgcType;               //!<' AGC Type

   dword iNumReports;                       //!<' Total number of reports that have been processed

   // Predicted C/N
   double Predicted_CtoN_Sum;               //!<' Sum of all Predicted C/N measurements, in integer form
   double Predicted_CtoN_SumSquares;    //!<' Sum of the squares of Predicted C/N measurements
   double Predicted_CtoN_Average_dB;    //!<' Average dB value of Predicted C_N
   double Predicted_CtoN_StdDev_dB;     //!<' Standard deviation dB value of Predicted C_N
   double Predicted_CtoN_Min_dB;            //!<' Minimum dB value of Predicted C_N
   double Predicted_CtoN_Max_dB;            //!<' Maximum dB value of Predicted C_N

   // Measured C/N
   double Measured_CtoN_Sum;                //!<' Sum of all C/N measurements, in integer form
   double Measured_CtoN_SumSquares;     //!<' Sum of the squares of C/N measurements
   double Measured_CtoN_Average_dB;     //!<' Average dB value of C_N
   double Measured_CtoN_StdDev_dB;      //!<' Standard deviation dB value of C_N
   double Measured_CtoN_Min_dB;         //!<' Minimum dB value of C_N
   double Measured_CtoN_Max_dB;         //!<' Maximum dB value of C_N

   dword  iLastFCOUNT;                      //!<' The last recorded FCOUNT

   // System processing loss
   double dSystemProcessingLoss;    //!<' 173.9 - 130.0 - dC_N_Average_dB
} GNSS_BroadBandJammerInfoStatus;

/**
This structure is used to consolodate parameteres that are common to
SV measurement processing but are unaligned in the various measurement
log records. Data is transferred from those structures into this
common structure which is then passed to a common processing algorithm.
*/
typedef struct
{
   dword    iFCOUNT;
   byte SV_ID;
   word CNO;
   byte OBS_STATE;
   float    UNFILT_SPEED;
   dword    UNFILT_MS;
   float    UNFILT_SM;
   dword    MEAS_STATUS;
   byte CLK_OFFSET;
} CGPS_SingleSvParams_Type;

/**
Summary structure for CGPS RF Status reports (CGPS_RF_STATUS_REPORT_LOG).
Keeps track of BP Mean I and Q and BP Amplitude I and Q, which are required
for the CGPS AGC test.

*/
typedef struct
{
   dword iTotalLogs;                //!<' Total number of RF Status logs recieved.
   dword iNumReports;           //!<' Number of RF Status Logs for which statistics have been accumulated.

   //
   // Stats for BP Mean
   //
   double dSum_BP_Mean_I;       //!<' Sum of all BP Mean I values
   double dSum_BP_Mean_Q;       //!<' Sum of all BP Mean Q values

   double dSumSq_BP_Mean_I; //!<' Sum of squares of all BP Mean I values
   double dSumSq_BP_Mean_Q; //!<' Sum of squares of all BP Mean Q values

   double dMin_BP_Mean_I;       //!<' Minimum of all BP Mean I values
   double dMin_BP_Mean_Q;       //!<' Minimum of all BP Mean Q values

   double dMax_BP_Mean_I;       //!<' Maximum of all BP Mean I values
   double dMax_BP_Mean_Q;       //!<' Maximum of all BP Mean Q values

   double dAvg_BP_Mean_I;       //!<' Average of all BP Mean I values
   double dAvg_BP_Mean_Q;       //!<' Average of all BP Mean Q values

   double dStdDev_BP_Mean_I;    //!<' Standard deviation of all BP Mean I values
   double dStdDev_BP_Mean_Q;    //!<' Standard deviation of all BP Mean Q values

   //
   // Stats for BP Amplitude
   //
   double dSum_BP_Ampl_I;       //!<' Sum of all BP Amplitude I values
   double dSum_BP_Ampl_Q;       //!<' Sum of all BP Amplitude Q values

   double dSumSq_BP_Ampl_I; //!<' Sum of squares of all BP Amplitude I values
   double dSumSq_BP_Ampl_Q; //!<' Sum of squares of all BP Amplitude Q values

   double dMin_BP_Ampl_I;       //!<' Minimum of all BP Amplitude I values
   double dMin_BP_Ampl_Q;       //!<' Minimum of all BP Amplitude Q values

   double dMax_BP_Ampl_I;       //!<' Maximum of all BP Amplitude I values
   double dMax_BP_Ampl_Q;       //!<' Maximum of all BP Amplitude Q values

   double dAvg_BP_Ampl_I;       //!<' Average of all BP Amplitude I values
   double dAvg_BP_Ampl_Q;       //!<' Average of all BP Amplitude Q values

   double dStdDev_BP_Ampl_I;    //!<' Standard deviation of all BP Amplitude I values
   double dStdDev_BP_Ampl_Q;    //!<' Standard deviation of all BP Amplitude Q values

   long  PGA_GAIN;
   long MinPgaGain;
   long MaxPgaGain;

   long  Sum_PRE_AMPL_I;
   long  Sum_PRE_AMPL_Q;
   long Sum_PRE_AMPL_Samples;

   byte AgcType;

   char RF_IC_ID[12];
   char RF_OpMode[10];

   byte Version;
} CGPS_BP_AGC_RF_StatusInfo;

typedef struct
{
   byte   Bp3FreqIndex;       //!<' -7 to +6 with -8 representing unused
   //!
   double dSum_BP_Ampl_I;       //!<' Sum of all BP Amplitude I values
   double dSum_BP_Ampl_Q;       //!<' Sum of all BP Amplitude Q values

   double dSumSq_BP_Ampl_I; //!<' Sum of squares of all BP Amplitude I values
   double dSumSq_BP_Ampl_Q; //!<' Sum of squares of all BP Amplitude Q values

   double dMin_BP_Ampl_I;       //!<' Minimum of all BP Amplitude I values
   double dMin_BP_Ampl_Q;       //!<' Minimum of all BP Amplitude Q values

   double dMax_BP_Ampl_I;       //!<' Maximum of all BP Amplitude I values
   double dMax_BP_Ampl_Q;       //!<' Maximum of all BP Amplitude Q values

   double dAvg_BP_Ampl_I;       //!<' Average of all BP Amplitude I values
   double dAvg_BP_Ampl_Q;       //!<' Average of all BP Amplitude Q values

   double dStdDev_BP_Ampl_I;    //!<' Standard deviation of all BP Amplitude I values
   double dStdDev_BP_Ampl_Q;    //!<' Standard deviation of all BP Amplitude Q values
} CGPS_GLO_BP_AGC_RF_StatusInfo;

/**
Structure to map CGPS_WB_FFT_STATS_C (0x1487) version 0-1
*/
typedef struct
{
   unsigned char   iVersion;   //!<' Version of the log
   unsigned long    iCNoDBHz;   //!<' Signal strength calculated in 0.1 dBHz as part of WBIQ test
   long         iFreq;      //!<' Frequency in Hz calculated as part of WBIQ test
} CGPS_WB_FFT_Stats;

// Masks for decoding iGNSSConfigMask (below) to determine which constellations
#define GNSS_NAV_CONFIG_GPS 0x01
#define GNSS_NAV_CONFIG_GLO 0x02
#define GNSS_NAV_CONFIG_BDS 0x10
#define GNSS_NAV_CONFIG_GAL 0x20

typedef struct
{
   unsigned char   iVersion;           //!<' Version of the log
   unsigned long   iGPSCNoDBHz;        //!<' Signal strength calculated in 0.1 dBHz as part of GPS WBIQ test
   long            iGPSFreq;           //!<' Frequency in Hz calculated as part of GPS WBIQ test
   unsigned long   iGLOCNoDBHz;        //!<' Signal strength calculated in 0.1 dBHz as part of GLO WBIQ test
   long            iGLOFreq;           //!<' Frequency in Hz calculated as part of GLO WBIQ test
   unsigned long   iBDSCNoDBHz;        //!<' Signal strength calculated in 0.1 dBHz as part of BDS WBIQ test
   long            iBDSFreq;           //!<' Frequency in Hz calculated as part of BDS WBIQ test
   unsigned long   iGALCNoDBHz;        //!<' Signal strength calculated in 0.1 dBHz as part of GAL WBIQ test
   long            iGALFreq;           //!<' Frequency in Hz calculated as part of GAL WBIQ test
   unsigned char   iGNSSConfigMask;    //!<' Bit mask for GNSS Config: bit 0 - GPS, bit 1 - GLO, bit 4 - BDS, bit 5 - GAL
   long            iADCMeanI;          //!<' Mean estimate (DC) of the I component in ADC processor
   long            iADCMeanQ;          //!<' Mean estimate (DC) of the Q component in ADC processor
   long            iADCAmpI;           //!<' Amplitude estimate of the I component in ADC processor
   long            iADCAmpQ;           //!<' Amplitude estimate of the Q component in ADC processor
} GNSS_WB_FFT_Stats_v2;

#define GNSS_LBW_AGC  0
#define GNSS_BDS_AGC  1
#define GNSS_GLO_AGC  2
#define GNSS_GAL_AGC  3
#define GNSS_HBW_AGC  4

/**
Structure to map the log data for the CGPS prescribed dwell log (CGPS_PRESCRIBED_DWELL_STATUS_LOG, log 0x1374).
*/
typedef struct
{
   unsigned char VERSION;
   unsigned char RESP_TYPE;
   unsigned long TOTAL_PACKETS;
   unsigned long PACKET_NUM;
   unsigned char SV_ID;
   unsigned long GPS_RTC;
   unsigned char STATUS_FLAG;
   unsigned char SRCH_MODE_INDEX;
   unsigned short POST_DETECTION_N;
   unsigned short CNO_DB;
   unsigned long CODE_PHASE;
   unsigned long DOPP;
   unsigned long MULTIPATH_EST;
   unsigned long RESERVED;
} CGPS_PrescribedDwell_LogStruct;

//! Constants for the RESP_TYPE values in CGPS_PrescribedDwell_LogStruct
typedef enum
{
   CGPS_PrescribedDwell_Type_DwellResults   = 0,
   CGPS_PrescribedDwell_Type_IncohSums = 1,
   CGPS_PrescribedDwell_Type_CohSums = 2
} CGPS_PrescribedDwell_ResponseType;

//! Bit mask for STATUS_FLAG values in CGPS_PrescribedDwell_LogStruct
typedef enum
{
   CGPS_PrescribedDwell_Status_ValidPeak    = 1,    //!< '  Bit 0, 2^0 = valid peak indicator
   CGPS_PrescribedDwell_Status_Multipath    = 2     //!< '  Bit 1, 2^1 = multipath indicator
} CGPS_PrescribedDwell_Status;

//! Constants for the SRCH_MODE_INDEX values in CGPS_PrescribedDwell_LogStruct
typedef enum
{
   CGPS_PrescribedDwell_SearchMode_10ms = 0,
   CGPS_PrescribedDwell_SearchMode_20ms = 1,
   CGPS_PrescribedDwell_SearchMode_160ms    = 2
} CGPS_PrescribedDwell_SearchMode;

typedef struct
{
   byte Version;
   dword    FCOUNT;
   dword    SEQ_NUM;
   byte RxD_FLAG;
   word STATUS_FLAG;
   char SV;
   float    DOPP_HZ;
   float    DOPP_UNC_HZ;
   dword DOPP_WIN_USED_HZ;
   float    CNO_DBHZ;
   float    CODE_PHASE_CHIPS;
   float    CODE_PHASE_UNC_CHIPS;
   word CODE_WIN_USED_CHIPS;
   byte SRCH_MODE;
   word NUM_POSTD;
   byte GLO_HW_CHAN;
   byte PFA;
   word DWELL_CNT;
   word TOTAL_NUM_DWELLS;
   word PASS_DWELL_CNT;
   dword q_RawPeakHeight;         /* Raw Peak height in linear energy before any interpolation */
   float  f_RawCnoDB;             /* GPS/GLO dwell CNo in dbHz. Valid only when "peak is VALID".
                                  Interpreted by parsing tool as float.
                                  Transmitted on diag interface as uint32.*/
   dword    RESERVED;
} CGPS_GEN8_PrescribedDwell_LogStruct;

typedef struct
{
   byte     Version;
   dword    FCOUNT;
   dword    SEQ_NUM;
   byte     RxD_FLAG;
   word     STATUS_FLAG;
   char     SV;
   float    DOPP_HZ;
   float    DOPP_UNC_HZ;
   dword    DOPP_WIN_USED_HZ;
   float    CNO_DBHZ;
   float    CODE_PHASE_CHIPS;
   float    CODE_PHASE_UNC_CHIPS;
   dword    CODE_WIN_USED_CHIPS;  // This field was 2 bytes till Gen8C.
   byte     SRCH_MODE;
   word     NUM_POSTD;
   byte     GLO_HW_CHAN;
   byte     PFA;
   word     DWELL_CNT;
   word     TOTAL_NUM_DWELLS;
   word     PASS_DWELL_CNT;
   dword    q_RawPeakHeight;         /* Raw Peak height in linear energy before any interpolation */
   float    f_RawCnoDB;             /* GPS/GLO dwell CNo in dbHz. Valid only when "peak is VALID".
                                    Interpreted by parsing tool as float.
                                    Transmitted on diag interface as uint32.*/
   dword    RESERVED;
} CGPS_GEN8_C_PrescribedDwell_LogStruct;

//! Constants for the SRCH_MODE_INDEX values in CGPS_GEN8_PrescribedDwell_LogStruct
typedef enum
{
   GPS_LBW_Chipx1_10ms_PDI                =  0,
   GPS_LBW_Chipx2_10ms_PDI                =  1,
   GPS_LBW_Chipx1_20ms_PDI                =  2,
   GPS_LBW_Chipx2_20ms_PDI                =  3,
   GPS_LBW_Chipx2_160ms_PDI               =  4,
   GPS_LBW_Chipx2_BET                     =  5,
   GPS_LBW_Chipx1_20ms_PDI_750_Hz =   6,
   GPS_LBW_Chipx2_20ms_PDI_750_Hz =   7,
   GPS_LBW_Chipx2_2ms_PDI         =   8,
   GPS_LBW_Chipx2_2ms_PDI_BET     =   9,
   GPS_HBW_Chipx20_20ms_PDI       =  10,
   GPS_HBW_Chipx20_20ms_PDI_NU4   =  11,
   GPS_HBW_Chipx20_20ms_PDI_NU8   =  12,
   GLO_Chipx1_5ms_PDI             =  13,
   GLO_Chipx2_5ms_PDI             =  14,
   GLO_Chipx1_10ms_PDI            =  15,
   GLO_Chipx2_10ms_PDI            =  16,
   GLO_Chipx1_20ms_PDI            =  17,
   GLO_Chipx2_20ms_PDI            =  18,
   GLO_Chipx2_BET_10              =  19,
   GLO_Chipx2_BET_20              =  20,
   GLO_Chipx1_20ms_PDI_750_Hz     =  21,
   GLO_Chipx2_20ms_PDI_750_Hz     =  22,
   BDS_Chipx1_1ms_PDI             =  30,
   BDS_Chipx2_1ms_PDI             =  31,
   BDS_Chipx1_20ms_PDI            =  32,
   BDS_Chipx2_20ms_PDI            =  33,
   BDS_Chipx2_20ms_BET            =  34,
   GAL_Chipx4_4ms_PDI             =  38,
   GAL_Chipx4_20ms_PDI            =  39,
   GAL_Chipx4_100ms_PDI           =  40,
   GAL_Chipx4_4x1                 =  41
} CGPS_GEN8_PrescribedDwell_SearchMode;

//! Constants for the SRCH_MODE_INDEX values in CGPS_GEN9_PrescribedDwell_LogStruct
typedef enum
{
   /*GPS*/
   C_ME_SRCH_MODE_L1_CX1_10_PDI     = 0,
   C_ME_SRCH_MODE_L1_CX2_10_PDI     = 1,
   C_ME_SRCH_MODE_L1_CX1_20_PDI     = 2,
   C_ME_SRCH_MODE_L1_CX2_20_PDI     = 3,
   C_ME_SRCH_MODE_L1_CX2_160_PDI    = 4,
   C_ME_SRCH_MODE_L1_CX2_BET        = 5,
   C_ME_SRCH_MODE_L1_CX2_20_PDI_750 = 6,
   C_ME_SRCH_MODE_L1_CX1_2_PDI_BET  = 20,

   /*GLO*/
   C_ME_SRCH_MODE_R1_CX1_5_PDI      = 7,
   C_ME_SRCH_MODE_R1_CX2_5_PDI      = 8,
   C_ME_SRCH_MODE_R1_CX1_10_PDI     = 9,
   C_ME_SRCH_MODE_R1_CX2_10_PDI     = 10,
   C_ME_SRCH_MODE_R1_CX1_20_PDI     = 11,
   C_ME_SRCH_MODE_R1_CX2_20_PDI     = 12,
   C_ME_SRCH_MODE_R1_CX2_BET_10     = 13,
   C_ME_SRCH_MODE_R1_CX2_BET_20     = 14,

   /*BDS*/
   C_ME_SRCH_MODE_B1_CX1_1_PDI      = 21,
   C_ME_SRCH_MODE_B1_CX2_1_PDI      = 22,
   C_ME_SRCH_MODE_B1_CX1_20_PDI     = 23,
   C_ME_SRCH_MODE_B1_CX2_20_PDI     = 24,
   C_ME_SRCH_MODE_B1_CX2_20_PDI_BET = 25,
   C_ME_SRCH_MODE_B1_CX2_2_PDI      = 26,
   C_ME_SRCH_MODE_B1_CX1_2_PDI_BET  = 27,
   C_ME_SRCH_MODE_B1_CX2_2_PDI_BET  = 28,

   /*GAL*/
   C_ME_SRCH_MODE_E1_CX4_4_PDI       = 29,
   C_ME_SRCH_MODE_E1_CX4_20_PDI      = 30,
   C_ME_SRCH_MODE_E1_CX4_100_PDI     = 31,
   C_ME_SRCH_MODE_E1_CX4_4x1         = 32

} CGPS_GEN9_PrescribedDwell_SearchMode;

typedef enum
{
   GPS_PrescribedDwellLog = 0,
   GLO_PrescribedDwellLog = 1,
   BDS_PrescribedDwellLog = 2,
   GAL_PrescribedDwellLog = 3
};
//! Bit mask for STATUS_FLAG values in CGPS_PrescribedDwell_LogStruct
typedef enum
{
   CGPS_GEN8_PrescribedDwell_Status_ValidPeak   = 1,    //!< '  Bit 0, 2^0 = valid peak indicator
   CGPS_GEN8_PrescribedDwell_Status_Automatic   = 2,
   CGPS_GEN8_PrescribedDwell_Status_Truncated   = 4,
   CGPS_GEN8_PrescribedDwell_Status_Randomized  = 8
} CGPS_GEN8_PrescribedDwell_Status;

typedef enum
{
   CGPS_PrescribedDwell_RxD_Type_NoRxD = 0,
   CGPS_PrescribedDwell_RxD_Type_RxD_Linked = 1,
   CGPS_PrescribedDwell_RxD_Type_RxD_Only = 2
} CGPS_GEN8_RxD_Type;

/**
Summary structure for CGPS RF Status reports (CGPS_RF_STATUS_REPORT_LOG).
Keeps track of BP Mean I and Q, which are required for the CGPS AGC test.

*/
typedef struct
{
   //! Total number of event reports that have been found, this is based on counting the number of times that event
   //! _EVENT_GPS_LM_PD_COMPLETE/_EVENT_GNSS_PRESC_DWELL_COMPLETE #1250/#1717 is received
   dword iNumEventReports;

   /*
   For this release of QMSL, the CGPS_PRESCRIBED_DWELL_STATUS_LOG, log 0x1374, is not being
   parsed, so certain parameters will not be reported in this structure.  In the next
   major release, these values will be filled in.
   */
   //! Total number of log reports that have been found, this is based on counting the number of times that the
   //! CGPS_PRESCRIBED_DWELL_STATUS_LOG, 0x1374, is received
   dword iNumLogReports;

   //! Total number of valid peaks that have been found by counting STATUS_FLAG==1
   dword iNumValidPeaks;

   dword iNumValidAutoDwells;

   //! Maximum C/No measured
   double dMaxCNO;

   //! Average C/No measured
   double dAverageCNO;

   //! Standard deviation of C/No
   double dStdDevCNO;

   //! Sum of CNO
   double dSumCNO;

   //! Sum of CNO squares (for standard deviation)
   double dSumOfSquaresCNO;

   /////////////////////////////////////////////////////

   //! Minimum Raw C/No measured
   double dMinRawCNO;

   //! Maximum Raw C/No measured
   double dMaxRawCNO;

   //! Average Raw C/No measured
   double dAverageRawCNO;

   //! Standard deviation of Raw C/No
   double dStdDevRawCNO;

   //! Sum of Raw CNO
   double dSumRawCNO;

   //! Raw C/No Sum of squares (for standard deviation)
   double dSumOfSquaresRawCNO;

   //! Minimum Speed
   double dMinSpeed;

   //! Maximum Speed
   double dMaxSpeed;

   //! Average Speed
   double dAvgSpeed;

   //! Sum of Speeds
   double dSpeedSum;

   //! Speed Sum of squares (for standard deviation)
   double dStdDevSpeed;

   //! Speed Sum of squares (for standard deviation)
   double dSumOfSquaresSpeed;

   //! Minimum Acceleration
   double dMinAcceleration;

   //! Maximum Acceleration
   double dMaxAcceleration;

   //! Average Acceleration
   double dAvgAcceleration;

   //! Sum of Acceleration
   double dSumAcceleration;

   //! Acceleration Sum of squares (for standard deviation)
   double dStdDevAcceleration;

   //! Acceleration Sum of squares (for standard deviation)
   double dSumOfSquaresAcceleration;

   //! FCOUNT from last measurment log
   dword LastFcount;

   //! Speed calculated for last measurement log.
   double LastSpeed;

   // Last search mode reported -- srch_mode field
   CGPS_PrescribedDwell_LogStruct oLastPrescribedDwellStatus;

   CGPS_GEN8_PrescribedDwell_LogStruct oGen8LastPrescribedDwellStatus;
   CGPS_GEN8_C_PrescribedDwell_LogStruct oGen8_C_LastPrescribedDwellStatus;
} CGPS_PrescribedDwell_StatusInfo;

/**
*/
/**
Statistics for GPS Demodulation soft decisions, used for GSP BER testing,
based on log GPS_DEMOD_SOFT_DECISIONS_LOG, 0x1253
*/
typedef struct
{
   //! Total number of logs received
   dword iNumLogReports;

   //! Total number of bits received
   dword iNumBits;

   //! Total number of bit errors
   dword iNumBitErrors;

   //! Calculated BER
   double dBER;

   // Copy of the last reported log, GPS_DEMOD_SOFT_DECISIONS_LOG, 0x1253
   CGPS_Demod_Soft_Decisions_Struct oLastDemodSoftDecisionLog;
} CGPS_BER_StatusInfo;

typedef struct
{
   byte   q_Version;
   byte    u_ErrorCode;
   float    f_TCalAverValueNsec;
   dword   q_TCalUncertaintyNsec;
   float    f_TCalMaxValueNsec;
   float    f_TCalMinValueNsec;
   float    f_PpmAverToaCCx16;
   long    l_PpmSrchWinCenterCCx16;
   dword   q_PpmNumToaSamplesAccumulated;
   word    x_PpmMaxToaCCx16;
   word    x_PpmMinToaCCx16;
   float    f_PpmAverEcIodB;
   float    f_PpmMaxEcIodB;
   float    f_PpmMinEcIodB;
   float    f_TtGnssRtcS80SubMsecGCx80;
   float   f_TtRefCdmaRtcS80SubPnRollCCx16;
   float   f_TtRefCdmaRtcS80AdjustSubPnRollCCx16;
   dword   q_TtRefGnssRtcs80FCount;
   dword   q_TtNumTTSamplesAccumulated;
   float    f_TtMaxGnssRtcS80SubMsecGCx80;
   float    f_TtMinGnssRtcS80SubMsecGCx80;
   byte    u_GpsSv;
   float    f_GpsPeakCodePhSubMsec;
   dword   q_GpsPeakCodePhMsec;
   dword   q_GpsPeakFCount;
   float    f_GpsPeakCNodBHz;
   dword   q_GpsPeakLatency;
   float    f_GpsSpeedMperSec;
   dword   q_GpsParams;
} GNSS_FastTimeCalibrationStruct;

typedef long tcxomgr_temp_type;
typedef struct
{
   long                      c3;
   long                      c2;
   long                      c1;
   long                      c0;
   tcxomgr_temp_type         t0;
   tcxomgr_temp_type         t0p;
   long                      p;
} tcxomgr_log_coeff_struct_type;

#define TCXOMGR_LOG_FREQ_EST_MAX_ENTRIES  10

struct tcxomgr_log_freq_est_hdr_struct_type
{
   unsigned char      Version;
#if !defined (QMSL_POSIX_PORTABLE)
   unsigned __int64   ts;                   /* Timestamp of log */
#else
   unsigned long ts;                    /* Timestamp of log */
#endif
   unsigned char      num_freq_est_data;    /* Num of freq_est data entries */
   unsigned char      num_rpush_data;       /* num of rpush entries */
   unsigned char      rot_valid;            /* num of rot samples */
};

struct tcxomgr_log_freq_est_data_struct_type
{
   // there are num_freq_est_data of these (288 bytes)
   unsigned long     delta_time;     /* Time since log pacjket start */
   unsigned long     time_ms;        /* Time in ms since start of estimator */
   long              temp_xo;        /* XO Temperature */
   long              temp_pmic;  /* PMIC temperature */
   long              therm_accum;    /* Thermal Accum */
   long              total_accum;    /* Total accum after RFE correction */
   long              rfe;            /* Residual Freq Error */
   long              rfe_slope;  /* RFE slope */
   long              total_slope;    /* Total sloep = RFE Slope + thermal slope */
};

struct tcxomgr_log_freq_est_rpush_struct_type
{
   // there are num_rpush_data of these (80 bytes)
   unsigned short      rot_time;          /* Time of rpush */
   short            rot_value;        /* Rpush value */
   unsigned char       rot_client;        /* Rpush client */
   unsigned char       rot_client_state; /* Rpush client state */
   long                 xo_temp;             /* XO temp at rpush */
};

struct tcxomgr_log_freq_est_struct_type
{
   tcxomgr_log_freq_est_hdr_struct_type     freq_est_hdr;
   tcxomgr_log_freq_est_data_struct_type    data[TCXOMGR_LOG_FREQ_EST_MAX_ENTRIES];
   tcxomgr_log_freq_est_rpush_struct_type   rpush[TCXOMGR_LOG_FREQ_EST_MAX_ENTRIES];
   short                                    rot[TCXOMGR_LOG_FREQ_EST_MAX_ENTRIES];  // If rot_valid
};

typedef struct
{
   int    iReportCount;     // Number of GNSS_SOC reports received/gain count

   // GLONASS IGain             -- reused for single SV regardless of GPS or GLO
   double dIgainGlo_Sum;
   double dIgainGlo_SumSquare;
   double dIgainGlo_Mean;
   double dIgainGlo_StdDev;
   double dIgainGlo_min;
   double dIgainGlo_max;

   // GLONASS QGain             -- reused for single SV regardless of GPS or GLO
   double dQgainGlo_Sum;
   double dQgainGlo_SumSquare;
   double dQgainGlo_Mean;
   double dQgainGlo_StdDev;
   double dQgainGlo_min;
   double dQgainGlo_max;

   double dGainBalGlo;

   // GPS IGain
   double dIgainGps_Sum;
   double dIgainGps_SumSquare;
   double dIgainGps_Mean;
   double dIgainGps_StdDev;
   double dIgainGps_min;
   double dIgainGps_max;

   // GPS QGain
   double dQgainGps_Sum;
   double dQgainGps_SumSquare;
   double dQgainGps_Mean;
   double dQgainGps_StdDev;
   double dQgainGps_min;
   double dQgainGps_max;

   double dGainBalGps;
} GNSS_SOC_GainSummary;

typedef struct
{
   int iprn;
   int iItemCount;

   // C/No Values
   double dCNo_Sum;
   double dCNo_SumSquare;
   double dCNo_Mean;
   double dCNo_StdDev;
   double dCNo_min;
   double dCNo_max;

   // SPR Values
   double dSPR_Sum;
   double dSPR_SumSquare;
   double dSPR_Mean;
   double dSPR_StdDev;
   double dSPR_min;
   double dSPR_max;

   // Doppler Values
   double dDoppler_Sum;
   double dDoppler_SumSquare;
   double dDoppler_Mean;
   double dDoppler_StdDev;
   double dDoppler_min;
   double dDoppler_max;
} GNSS_SOC_MeasurementSummary;

typedef struct
{
   long   XO_Temp_Measurements;
   double XO_Temp_Min;
   double XO_Temp_Max;
   double XO_Temp_Sum;
} GNSS_XO_Temp_Summary;

// The following structures and enums are defined here since they are shared between
// the status structure and message and log structures below
typedef enum
{
   GNSS_TCXOMGR_XTAL_2016 = 1,
   GNSS_TCXOMGR_XTAL_2520 = 2
} GNSS_XO_FACTORY_CAL_XTAL_Type;

typedef enum
{
   GNSS_XO_FACTORY_TECHNOLOGY_CDMA          = 0,
   GNSS_XO_FACTORY_TECHNOLOGY_WCDMA         = 1,
   GNSS_XO_FACTORY_TECHNOLOGY_GSM           = 2,
   GNSS_XO_FACTORY_TECHNOLOGY_LTE           = 3,
   GNSS_XO_FACTORY_TECHNOLOGY_TDSCDMA       = 4,
   GNSS_XO_FACTORY_TECHNOLOGY_CDMA_SEC      = 5,
   GNSS_XO_FACTORY_TECHNOLOGY_GPS           = 6
} GNSS_XO_FACTORY_CAL_TECHNOLOGY_Type;

typedef enum
{
   GNSS_XO_FACTORY_PASSED                              =  0,
   GNSS_XO_FACTORY_FAIL_Technology_not_supported       =  1,
   GNSS_XO_FACTORY_FAIL_DC_Offset_far_off_check        =  2,
   GNSS_XO_FACTORY_FAIL_XO_Fluctiates_over_IQ          =  3,
   GNSS_XO_FACTORY_FAIL_PMIC_Fluctiates_over_IQ        =  4,
   GNSS_XO_FACTORY_FAIL_Rotaters_not_zero              =  5,
   GNSS_XO_FACTORY_FAIL_Reached_term_limits            =  6,
   GNSS_XO_FACTORY_FAIL_Failed_temp_span               =  7,
   GNSS_XO_FACTORY_FAIL_XO_temp_too_low                =  8,
   GNSS_XO_FACTORY_FAIL_XO_temp_too_high               =  9,
   GNSS_XO_FACTORY_FAIL_Noisy_IQ_Samps                 = 10,
   GNSS_XO_FACTORY_FAIL_Phase_jump_in_IQ               = 11,
   GNSS_XO_FACTORY_FAIL_Message_router_init_fail       = 12,
   GNSS_XO_FACTORY_FAIL_Message_router_send_fail       = 13,
   GNSS_XO_FACTORY_FAIL_Message_router_recv_fail       = 14,
   GNSS_XO_FACTORY_FAIL_Other                          = 15,
   GNSS_XO_FACTORY_FAIL_XO_temp_span_timeout           = 16,
   GNSS_XO_FACTORY_FAIL_XO_max_sample_reached          = 17,
   GNSS_XO_FACTORY_FAIL_XO_temp_span_too_small         = 18,
   GNSS_XO_FACTORY_FAIL_GNSS_Fail_no_tone              = 19,
   GNSS_XO_FACTORY_FAIL_GNSS_Fail_mult_tones           = 20,
   GNSS_XO_FACTORY_FAIL_GNSS_Fail_strong_jammer        = 21,
   GNSS_XO_FACTORY_FAIL_GNSS_FAIL_Data_Collect_timeout = 22,
   GNSS_XO_FACTORY_FAIL_no_log_received                = 255
} GNSS_XO_FACTORY_FAIL_Type;

typedef enum
{
   GNSS_XO_FACTORY_QUAL_Cal_failed               =  0,
   GNSS_XO_FACTORY_QUAL_Not_callibrated          =  1,
   GNSS_XO_FACTORY_QUAL_Intermediate_step        =  2,
   GNSS_XO_FACTORY_QUAL_Coarse_Callibrated       =  5,
   GNSS_XO_FACTORY_QUAL_Intermediate_field_cal   =  6,
   GNSS_XO_FACTORY_QUAL_Fine_Callibrated         =  7,
   GNSS_XO_FACTORY_QUAL_C1_Caled_C0_Factory_cal  =  8,
   GNSS_XO_FACTORY_QUAL_Field_done_C0_C1_C3_OK   = 11
} GNSS_XO_FACTORY_QUAL_Type;

typedef struct
{
   dword                        Version;           // Set to 1
   long                         INIT_XO_FREQ_ERROR; // Pre Factory Calibration Error (HRPPM Units)
   long                         DC_XO_FREQ_ERROR;  // Post Cores Calibration Error (HRPPM Units)
   long                         INIT_TEMP;         // Temperature before TCXO (Degree C * 1024)
   long                         FINAL_TEMP;        // Temperature after TCXO (Degree C * 1024)
   long                         C3;                // C3 coefficient in units 2^-32 ppm/C^3
   long                         C2;                // C2 coefficient in units 2^-28 ppm/C^2
   long                         C1;                // C1 coefficient in units 2^-24 ppm/C
   long                         C0;                // C0 coefficient in units 2^-12 ppm
   long                         T0;                // Reference XO Temperature Term (Degree C * 1024)
   long                         T0P;               // Reference PMIC Temperature Term (Degree C * 1024)
   long                         P;                 // PMIC Compression factor
   long                         CNo;               // GNSS Measured C/No value.
   byte                         INIT_XO_TRIM;      // Pre Factory Calibration XO Trim Capacitance (???)
   byte                         DC_XO_TRIM;        // Post XO Course Calibration XO Trim Capacitance (???)
   byte                         FAIL_REASON;       // GNSS_XO_FACTORY_FAIL_Type
   byte                         FT_QUAL_IND;       // GNSS_XO_FACTORY_QUAL_Type
} GNSS_XO_FACTORY_CAL_Resp_struct_type;

typedef struct
{
   unsigned short FLAGS;                          //!< ' Bit 0: Enables IQ DM Logging.
   //!< ' Bit 1: Enables FFT (on-board) DM Logging
   //!< ' Bit 2: Hanning window enabled for on-board FFT
   //!< ' Bit 4: Enable C/No measurements for a single consternation
   //!< ' Bit 5: Enable C/No measurements for all enabled consternations in a single command
   //!< ' Bit 6: Automatically exit Standalone RF (SARF) mode upon compellation
   //!< ' Bit 7: Enable widband jammer power estimation for ADC IQ
   //!< ' All other bits are reserved
   unsigned char  COLLECT_MODE;                   //!< ' See gps_start_iq_test_collect_mode_gen8
   signed char    GLO_R1_CHAN;                    //!< ' GLO SV Frequency: 8 - for all, -7 to +6 for specific GLO Frequency ID
   unsigned char  GLO_HW_CHAN;                    //!< ' GLO Hardware Channel Number 0: automatic, 1-12: unique HW Chan to use
   unsigned short SAMPLE_COUNT_1K;                //!< ' Number of samples (in multiples of 1024) collected per incoherent integration.
   //!< ' 1, 2, 4, 8, 16 or 32 - power of 2 with max of 32
   unsigned char  INTEGRATIONS;                   //!< ' Number of incoherent integrations.  Greater than 0 - Allowed
   unsigned long  ADC_IQ_SAT_THRESH;              //!< ' Applicable when COLLECT_MODE is 16.  ADCIQ Saturation threshold specified in units of
   //!< ' 0.01%.  Unsigned.  Range 0 to 10000.  e.g. 9950 for a saturation of 99.5%
   unsigned long  ADC_IQ_WB_JAMMER_START_REQ_HZ;  //!< ' Applicable when COLLECT_MODE is 16 and Bit 7 of FLAGS is set.  ADC IQ widband
   //!< ' jammer estimation start frequency in Hz.  Absolute frequency: e.g. 1555000000 for
   //!< ' LTE B13 start frequency of 1555 MHz.  Assumes reference tone at +100 KHz offset relitive to
   //!< ' GPS L1
   unsigned long  ADC_IQ_WB_JAMMER_STOP_REQ_HZ;   //!< ' Applicable when COLLECT_MODE is 16 and Bit 7 of FLAGS is set.  ADC IQ widband
   //!< ' jammer estimation stop frequency in Hz.  Absolute frequency: e.g. 1573000000 for
   //!< ' LTE B13 stop frequency of 1573 MHz.  Assumes reference tone at +100 KHz offset relitive to
   //!< ' GPS L1
   signed long    ADC_IQ_REF_TONE_PWR_DBM;        //!< ' Applicable when COLLECT_MODE is 16 and Bit 7 of FLAGS is set.  ADC IQ reference tone
   //!< ' power in units of dBm at +100 KHz offset relitive to GPS L1.  Signed
} GNSS_Factory_IQ_Test_params;

typedef struct
{
   unsigned char  CMD_CODE;                      //!< ' Hard Coded to 128
   unsigned char  SUBSYS_ID;                     //!< ' Subsystem ID - 13 for GPS
   unsigned short SUBSYS_CMD_CODE;               //!< ' Subsystem Command Code - set to 114
   unsigned long  SUBSYS_STATUS;                 //!< ' Subsystem Status: 0 - Success, 1 - Failure
   unsigned short SUBSYS_DELAYED_RESP_ID;        //!< ' Subsystem Response ID: non-zero if successful, 0 if request failed.
   unsigned short SUBSYS_DELAYED_RESP_CNT;       //!< ' Subsystem Response Count: 0 - initial respond, 1 - delayed response.
} GNSS_Factory_IQ_Test_response_header;

struct GNSS_Factory_IQ_Test_response_results : GNSS_Factory_IQ_Test_response_header
{
    unsigned char  VERSION;                       //!< ' Version - set to 54
    unsigned char  GNSS_CONFIG_MASK;              //!< ' Bit mask for the GNSS consternation settings.  C/No results are valid for the configured
    //!< ' consternations
    //!< '   Bit 0 - GPS
    //!< '   Bit 1 - Glonass
    //!< '   Bit 4 - Biedou
    //!< '   Bit 5 - Galileo
    unsigned long  GPS_CNO;                       //!< ' GPS Signal strength calculated in 0.1 dBHz, as part of WB IQ tests if supported by HW/SW
    unsigned long  GPS_FREQ;                      //!< ' GPS Frequency is calculated in Hz, as part of the WB IQ tests if supported by HW/SW
    unsigned long  GLO_CNO;                       //!< ' Glonass Signal strength calculated in 0.1 dBHz, as part of WB IQ tests if supported by HW/SW
    unsigned long  GLO_FREQ;                      //!< ' Glonass Frequency is calculated in Hz, as part of the WB IQ tests if supported by HW/SW
    unsigned long  BDS_CNO;                       //!< ' Biedou Signal strength calculated in 0.1 dBHz, as part of WB IQ tests if supported by HW/SW
    unsigned long  BDS_FREQ;                      //!< ' Biedou Frequency is calculated in Hz, as part of the WB IQ tests if supported by HW/SW
    unsigned long  GAL_CNO;                       //!< ' Galileo Signal strength calculated in 0.1 dBHz, as part of WB IQ tests if supported by HW/SW
    unsigned long  GAL_FREQ;                      //!< ' Galileo Frequency is calculated in Hz, as part of the WB IQ tests if supported by HW/SW
    signed long    ADC_MEAN_I;                    //!< ' Mean estimate (DC) of I component in the ADC processor in 0.1 mV.  Value is signed
    signed long    ADC_MEAN_Q;                    //!< ' Mean estimate (DC) of Q component in the ADC processor in 0.1 mV.  Value is signed.
    unsigned long  ADC_AMP_I;                     //!< ' Amplitude estimate of I component in the ADC processor in 0.1 mV.  Value is unsigned.
    unsigned long  ADC_AMP_Q;                     //!< ' Alacrities estimate of Q component in the ADC processor in 0.1 mV.  Value is unsigned.
    unsigned char  ADC_IQ_SAT_PER_STATUS;         //!< ' Status of the ADC IQ saturation percentage command:
    //!< '  0 - ADC IQ saturation percentage is not valid
    //!< '  3 - Number of samples in ADC IQ test was zero
    //!< '  4 - ADC IQ saturation percentage is valid
    unsigned long  I_SAMPLE_SATURATION_PERCENTAGE; //!< ' % of I samples saturated in units of 0.001%.  Value is unsigned.
    unsigned long  Q_SAMPLE_SATURATION_PERCENTAGE; //!< ' % of Q samples saturated in units of 0.001%.  Value is unsigned.
    signed   long  ADC_WB_JAMMER_POWER_EST_DB;    //!< ' Estimated wideband jammer power in units of 0.01 dB.  Value is signed.  Only valid if wideband
    //!< ' jammer power estimation was enabled in the ADC IQ test request.
};


/**
Measurement and status structure for CGPS
*/
typedef struct
{
   //! Keeps track of whether an event has occurred
   unsigned char abHasEventOccurred[CGPS_QMSL_Event_Max];

   //! Configuration that is retrieved from the log messages for CGPS IQ Data Capture and FFT
   CGPS_IQ_FFT_DataConfig oIQ_FFT_DataConfig;

   /**
   C/N and Doppler measurement structure, includes all "GPS Measurement Report" log data for each SV,
   indexed by SV ID.  The zero index is not used.
   */
   CGPS_MeasurementReportInfo oMeasurementReports[CGPS_MAX_SV_ID +  1];

   //! Baseband Processor AGC statistics from the "RF Status" log
   CGPS_BP_AGC_RF_StatusInfo oRF_Status_AGC;

   //! GPS Prescribed dwell status
   CGPS_PrescribedDwell_StatusInfo oDwellStatus;
   CGPS_PrescribedDwell_StatusInfo oGloDwellStatus;
   CGPS_PrescribedDwell_StatusInfo oBdsDwellStatus;
   CGPS_PrescribedDwell_StatusInfo oGalDwellStatus;

   //! BER Status
   CGPS_BER_StatusInfo oBER_Status;

   CGPS_BER_StatusInfo oGPS_BER_Status;
   CGPS_BER_StatusInfo oBDS_BER_Status;
   CGPS_BER_StatusInfo oGLO_BER_Status;
   CGPS_BER_StatusInfo oGAL_BER_Status;

   CGPS_BP_AGC_RF_StatusInfo    oGNSS_BP_RF_Status_AGC[4];
   CGPS_GLO_BP_AGC_RF_StatusInfo    oGNSS_GLO_BP_RF_Status_AGC[12];

   //! WB FFT Status (Log 0x1487) version 0-1
   CGPS_WB_FFT_Stats oWB_FFT_Stats;
   //! WB FFT Status (Log 0x1487) version 2
   GNSS_WB_FFT_Stats_v2 oWB_FFT_Stats_2;

   CGPS_MeasurementReportInfo oGloMeasurementReports[CGPS_MAX_SV_ID +  1];
   CGPS_MeasurementReportInfo oLBWMeasurementReports[CGPS_MAX_SV_ID +  1];
   CGPS_MeasurementReportInfo oRxDMeasurementReports[CGPS_MAX_SV_ID +  1];
   CGPS_MeasurementReportInfo oHBWMeasurementReports[CGPS_MAX_SV_ID +  1];
   CGPS_MeasurementReportInfo oBdsMeasurementReports[CGPS_MAX_BDS_SV_ID +  1];
   CGPS_MeasurementReportInfo oGalMeasurementReports[CGPS_MAX_SV_ID +  1];

   GNSS_BroadBandJammerInfoStatus GPS_BroadBandJammerInfoStatus[CGPS_MAX_SV_ID +  1];
   GNSS_BroadBandJammerInfoStatus GLO_BroadBandJammerInfoStatus[CGPS_MAX_SV_ID +  1];
   GNSS_BroadBandJammerInfoStatus BDS_BroadBandJammerInfoStatus[CGPS_MAX_SV_ID +  1];
   GNSS_BroadBandJammerInfoStatus GAL_BroadBandJammerInfoStatus[CGPS_MAX_SV_ID +  1];

   GNSS_FastTimeCalibrationStruct oFast_TimeCalibration_Status;

   tcxomgr_log_coeff_struct_type oTCXO_Field_Data;

   tcxomgr_log_freq_est_struct_type o_TCXO_FreqEst_Data;

   GNSS_SOC_GainSummary              o_GNSS_SOC_GainData;

   GNSS_SOC_MeasurementSummary       o_GNSS_SOC_MeasurementSummary[CGPS_MAX_NUM_SV_IN_MEASUREMENT_REPORT];

   GNSS_XO_Temp_Summary GNSS_XO_Temp_Data;

   byte SpectumAnalyzerStatusEvent;

   GNSS_XO_FACTORY_CAL_Resp_struct_type    o_GNSS_XO_FACTORY_Cal_Response;

   int i_Sensor_Rotations_Detected;

   double d_Sensor_Parser_Capacity_Percentage;

   long i_Acc_Sensor_Measurements_Received;
   long i_Gyro_Sensor_Measurements_Received;
   long i_GyroTemp_Sensor_Measurements_Received;

   GNSS_Factory_IQ_Test_response_results oFactory_IQ_Test_results;
}
CGPS_Status_Struct;

#define CGPS_MAX_SBAS_DECODED_WORDS 16

typedef  struct
{
   dword    q_BlankingStartRtc;
   word w_NumBlankedSymbs;
} CGPS_SbasBlankingInfoType_Struct;

typedef struct
{
   byte u_SvPrnNum;
   dword    q_GpsRTC;  /* GPSRTC of first sample */
   byte u_LogCnt;
   word w_PreamblePosSamp;
   byte u_SbasVitFlags;
   CGPS_SbasBlankingInfoType_Struct    z_SbasBlankingInfo[2];
   word w_NumVitDecBits;
   dword    q_DecBits[CGPS_MAX_SBAS_DECODED_WORDS];
} CGPS_SbasDecodedWords_Struct;

#define CGPS_MAX_SBAS_SOFT_DEC 500
typedef struct
{
   unsigned char        u_SvPrnNum;
   unsigned long int    q_GpsRTC;  /* GPSRTC of first sample */
   unsigned char        u_LogCnt;
   unsigned short       w_BlankStartIdx;
   unsigned short       w_NumBlankedSamp;
   unsigned long int    q_CostasDerDopp;
   unsigned char        u_CostasFlags;
   unsigned char        u_Reserved[10];
   unsigned short       w_NumSoftSymbs;
   signed char          b_SoftDecisions[CGPS_MAX_SBAS_SOFT_DEC];
} CGPS_SbasDemodSoftSymbols_Struct;

typedef enum
{
   CGPS_SBAS_DEMOD_STATUS_INACTIVE = 0,
   CGPS_SBAS_DEMOD_STATUS_NO_BE_DET,
   CGPS_SBAS_DEMOD_STATUS_NO_PRE_DET,
   CGPS_SBAS_DEMOD_STATUS_NO_PEAK,
   CGPS_SBAS_DEMOD_STATUS_DPO_DET,
   CGPS_SBAS_DEMOD_STATUS_CRC_FAIL,
   CGPS_SBAS_DEMOD_STATUS_CRC_PASS,
   CGPS_SBAS_DEMOD_STATUS_FRAME_SKIPPED
} CGPS_SbasDemodStatus_type;

typedef struct
{
   unsigned char    SvPrn;
   unsigned char    DemodStatus;
   unsigned short   NumberOfSamples;
   unsigned short   BlankingStartIndex;
   unsigned short   BlankingEndDuration;
   unsigned char    CNo;
} CGPS_SbasDemodReportEvent_Struct;

enum
{
   CGPS_GEN8_HW_CONFIG_RF_MODE_IGNORE_FIELD,
   CGPS_GEN8_HW_CONFIG_RF_MODE_PRI_NB_RXD_ALWAYS_OFF,
   CGPS_GEN8_HW_CONFIG_RF_MODE_PRI_WB_RXD_ALWAYS_OFF,
   CGPS_GEN8_HW_CONFIG_RF_MODE_PRI_WB_RXD_ON,
   CGPS_GEN8_HW_CONFIG_RF_MODE_BP4_GLO_TEST,
   CGPS_GEN8_HW_CONFIG_RF_MODE_BP2_BDS_TEST
};

enum
{
   CGPS_GEN8_HW_CONFIG_RF_LINEARITY_IGNORE_FIELD,
   CGPS_GEN8_HW_CONFIG_RF_LINEARITY_LOW = 1,
   CGPS_GEN8_HW_CONFIG_RF_LINEARITY_HIGH,
   CGPS_GEN8_HW_CONFIG_RF_LINEARITY_AUTO,
};

typedef struct
{
   unsigned char u_RfMode;              //!< ' RF Mode:
   //!< '   0 - Ignore this field
   //!< '   1 - Narrowband GPS
   //!< '   2 - Wideband GPS
   //!< '   3 - Reserved
   //!< '   4 - GLONASS
   unsigned char u_RfLinearity;     //!< ' Linearity Mode:
   //!< '   0 - Ignore this field
   //!< '   1 - Low Linearity
   //!< '   2 - High Linearity
   //!< '   3 - Automatic
   unsigned char u_RfRxdOnTimeSec;  //!< ' Not Used
   unsigned char u_RfRxdOffTimeSec; //!< ' Not Used.
   unsigned long q_Reserved;            //!< ' Reserved, Must be 0.
} CGPS_Gen8_HwConfig_Struct_type;

enum
{
   CGPS_GEN8_PRX_RF_MODE_GPSL1 = 0,
   CGPS_GEN8_PRX_RF_MODE_WIDEBANDGNSS,
   CGPS_GEN8_PRX_RF_MODE_GLO
} ;

enum
{
   CGPS_GEN8_LINEARITY_LOW = 0,
   CGPS_GEN8_LINEARITY_High,
   CGPS_GEN8_LINEARITY_Automatic
} ;

typedef struct
{
   unsigned char u_RfMode;      //!< '
   byte          b_Reserved1; //!< '
   byte          b_Reserved2;   //!< '
   byte          b_Reserved3; //!< '
} CGPS_Gen8_Rx_RfMode_Struct_type;

typedef struct
{
   unsigned char u_RfLinearity; //!< ' Linearity Mode. 0 - Low Linearity, 1 - High Linearity, 2 - Automatic
   unsigned long q_Reserved;     //!< '
} CGPS_Gen8_Rf_Linearity_Config_Struct_type;

typedef struct
{
   unsigned char    u_TestMode;                 //!< ' See gnss_multichan_track_test_enum_type
   unsigned char    u_GloHwChan;                //!< ' GLO Hardware Channel Number 0: automatic, 1-12: unique HW Chan to use
   unsigned char    u_GpsOrSbasSvId;            //!< ' GPS SV to track: 0 for all, 1-32 for GPS SV, 33-52 for SBAS
   char                 b_GloFreqencyId;            //!< ' GLO SV Frequency: 8 - for all, -7 to +6 for specific GLO Frequency ID
   unsigned char    u_GpsSbasBitEdgeAction; //!< ' Bit 0: 0 - Enable GPS Data BitEdge Detection, 1 - disable GPS Data BitEdge Detection
   unsigned char    u_GloBitEdgeAction;     //!< ' Bit 0: 0 - Enable GLO Data BitEdge Detection, 1 - disable GLO Data BitEdge Detection
   //!< ' Bit 1: 0 - Don't Bypass Meander BitEdge, 1 - Bypass Meander BitEdge
   //!< ' Bit 2: 0 - Don't Bypass TimeMark BitEdge, 1 - Bypass TimeMark BitEdge
   unsigned char    u_Command;                  //!< ' 1 Clear all states, then start
   //!< ' 2 Keep old states, and start
   //!< ' 3 Stop test, and clear all states
   //!< ' 4 Stop test, and keep the states
} CGPS_Gen8_SvTrack_Struct_type;

typedef struct
{
   unsigned char    u_TestMode;                 //!< ' See gnss_multichan_track_test_enum_type
   unsigned char    u_GloHwChan;                //!< ' GLO Hardware Channel Number 0: automatic, 1-12: unique HW Chan to use
   unsigned char    u_GpsOrSbasSvId;            //!< ' GPS SV to track: 0 for all, 1-32 for GPS SV, 33-52 for SBAS
   char             b_GloFreqencyId;            //!< ' GLO SV Frequency: 8 - for all, -7 to +6 for specific GLO Frequency ID
   unsigned char    u_BDS_SvId;                 //!< ' GPS SV to track: 0 for all, 1-32 for GPS SV, 33-52 for SBASunsigned char u_GpsSbasBitEdgeAction;
   unsigned char    u_GpsSbasBitEdgeAction;     //!< ' Bit 0: 0 - Enable GPS Data BitEdge Detection, 1 - disable GPS Data BitEdge Detection
   unsigned char    u_GloBitEdgeAction;         //!< ' Bit 0: 0 - Enable GLO Data BitEdge Detection, 1 - disable GLO Data BitEdge Detection
   //!< ' Bit 1: 0 - Don't Bypass Meander BitEdge, 1 - Bypass Meander BitEdge
   //!< ' Bit 2: 0 - Don't Bypass TimeMark BitEdge, 1 - Bypass TimeMark BitEdge
   unsigned char    u_BDS_BitEdgeAction;        //!< ' Bit 0: 0 - Don't Bypass Data BitEdge Detection, 1 - Bypass Data BitEdge Detection
   //!< ' Bit 1: 0 - Don't Bypass N-H code, 1 - Bypass N-H code
   unsigned char    u_Command;                  //!< ' 1 Clear all states, then start
   //!< ' 2 Keep old states, and start
   //!< ' 3 Stop test, and clear all states
   //!< ' 4 Stop test, and keep the states
} CGPS_Gen8B_SvTrack_Struct_type;

typedef struct
{
   unsigned char    u_TestMode;                 //!< ' See gnss_multichan_track_test_enum_type
   unsigned char    u_GloHwChan;                //!< ' GLO Hardware Channel Number 0: automatic, 1-12: unique HW Chan to use
   unsigned char    u_GpsOrSbasSvId;            //!< ' GPS SV to track: 0 for all, 1-32 for GPS SV, 33-52 for SBAS
   char             b_GloFreqencyId;            //!< ' GLO SV Frequency: 8 - for all, -7 to +6 for specific GLO Frequency ID
   unsigned char    u_BDS_SvId;                 //!<
   unsigned char    u_GAL_SvId;                 //!<
   unsigned char    u_GpsSbasBitEdgeAction;     //!< ' Bit 0: 0 - Enable GPS Data BitEdge Detection, 1 - disable GPS Data BitEdge Detection
   unsigned char    u_GloBitEdgeAction;         //!< ' Bit 0: 0 - Enable GLO Data BitEdge Detection, 1 - disable GLO Data BitEdge Detection
   //!< ' Bit 1: 0 - Don't Bypass Meander BitEdge, 1 - Bypass Meander BitEdge
   //!< ' Bit 2: 0 - Don't Bypass TimeMark BitEdge, 1 - Bypass TimeMark BitEdge
   unsigned char    u_BDS_BitEdgeAction;        //!< ' Bit 0: 0 - Don't Bypass Data BitEdge Detection, 1 - Bypass Data BitEdge Detection
   unsigned char    u_GAL_BitEdgeAction;         //
   unsigned char    u_Command;                  //!< ' 1 Clear all states, then start
   //!< ' 2 Keep old states, and start
   //!< ' 3 Stop test, and clear all states
   //!< ' 4 Stop test, and keep the states
} CGPS_Gen8C_SvTrack_Struct_type;

typedef struct
{
   byte CommandRevision;
   unsigned char    TEST_CONTROL;               //!< ' 0 - Start IqTest
   unsigned short   FLAGS;                  //!< ' Bit 0: Enables IQ DM Logging.
   //!< ' Bit 1: Enables FFT (on-board) DM Logging
   //!< ' Bit 2: Hanning window enabled for on-board FFT
   unsigned short   RETRANSMIT_PACKET_NUM;  //!< ' Not Used
   unsigned char    RF_STATUS_LOG_RATE_HZ;  //!< ' Logging Rate of RF Status Log, Range: 1 ~ 10
   unsigned char    COLLECT_MODE;           //!< ' See gps_start_iq_test_collect_mode_gen8
   char             GLO_R1_CHAN;            //!< ' GLO SV Frequency: 8 - for all, -7 to +6 for specific GLO Frequency ID
   unsigned char    GLO_HW_CHAN;            //!< ' GLO Hardware Channel Number 0: automatic, 1-12: unique HW Chan to use
   unsigned short   SAMPLE_CNT_1K;          //!< ' Number of samples (in multiples of 1024) collected per incoherent integration.
   //!< '       1 ~ 1024 - Valid for all WB/FB IQ
   //!< '       0 ~ 1024 - Valid for all NB. 0 => Continuous NBIQ
   //!< '       > 1024 - Invalid
   unsigned char    INTEGRATIONS;           //!< ' Number of incoherent integrations
   signed long      CENTER_FREQ_NBIQ;       //!< ' Center frequency used in Searcher for NB IQ test (Manual Mode only)
   //!< '    1 Hz/Bit.
   //!< '    Range:
   //!< '       -1.023 MHz ~ +1.023 MHz for BP1 and BP2
   //!< '       -511 kHz ~ +511 kHz for BP3
   //!< '       -10.23 MHz ~ +10.23 MHz for BP4

   unsigned char     bADCLiteConfig;         //!<  ' ADC Lite (small memory) used on ADC IQ tests only, don't care otherwise.
} CGPS_Gen8_StartIqTest_struct_type;

typedef struct
{
   byte CommandRevision;
   unsigned char    TEST_CONTROL;               //!< ' 0 - Start IqTest
   unsigned short   FLAGS;                  //!< ' Bit 0: Enables IQ DM Logging.
   //!< ' Bit 1: Enables FFT (on-board) DM Logging
   //!< ' Bit 2: Hanning window enabled for on-board FFT
   unsigned short   RETRANSMIT_PACKET_NUM;  //!< ' Not Used
   unsigned char    RF_STATUS_LOG_RATE_HZ;  //!< ' Logging Rate of RF Status Log, Range: 1 ~ 10
   unsigned char    COLLECT_MODE;           //!< ' See gps_start_iq_test_collect_mode_gen8
   char             GLO_R1_CHAN;            //!< ' GLO SV Frequency: 8 - for all, -7 to +6 for specific GLO Frequency ID
   unsigned char    GLO_HW_CHAN;            //!< ' GLO Hardware Channel Number 0: automatic, 1-12: unique HW Chan to use
   unsigned short   SAMPLE_CNT_1K;          //!< ' Number of samples (in multiples of 1024) collected per incoherent integration.
   //!< '       1 ~ 1024 - Valid for all WB/FB IQ
   //!< '       0 ~ 1024 - Valid for all NB. 0 => Continuous NBIQ
   //!< '       > 1024 - Invalid
   unsigned char    INTEGRATIONS;           //!< ' Number of incoherent integrations
   signed long      CENTER_FREQ_NBIQ;       //!< ' Center frequency used in Searcher for NB IQ test (Manual Mode only)
   //!< '    1 Hz/Bit.
   //!< '    Range:
   //!< '       -1.023 MHz ~ +1.023 MHz for BP1 and BP2
   //!< '       -511 kHz ~ +511 kHz for BP3
   //!< '       -10.23 MHz ~ +10.23 MHz for BP4

   unsigned char     bADCLiteConfig;         //!<  ' ADC Lite (small memory) used on ADC IQ tests only, don't care otherwise.
   unsigned long    ADC_IQ_Saturation_Threshold;
} CGPS_Gen8C_StartIqTest_struct_type;

typedef struct
{
   unsigned char    CMD_CONTROL_FLAG;                       //!< ' Bit 0: Enable GPS Prescribed Dwell
   //!< ' Bit 1: Enable GLO Prescribed Dwell
   unsigned long    SEQ_NUM;                         //!< ' Reserved
   unsigned char    GPS_RxD_FLAG;                    //!< ' Must be set to 0
   unsigned char    GPS_CONTROL_FLAG;                //!< ' Bit 0: 0
   //!< '       0 = As Prescribed. All parameters specified in this command are applied unchanged.
   //!< '       1 = Automatic. Automatic code phase and doppler centering. Code phase and doppler parameters from the DM command are ignored. The GNSS software propagates the values from prior measurements stored in software.
   //!< ' Bit 1:    Applicable to Auto dwells ONLY.
   //!< '       0 = No Truncation of code phase center
   //!< '       1 = Truncation of code phase center so that the peak is randomly sampled within the chip.
   //!< ' Bit 2:    Applicable to Auto dwells ONLY.
   //!< '       0 = No Randomization of Doppler
   //!< '       1 = Randomization of doppler
   unsigned char    GPS_SV;                          //!< ' GPS SV to track: 1-32 for GPS SV, 33-52 for SBAS
   long             GPS_DOPP_HZ;                     //!< ' Doppler (center frequency) to search at. Not applicable to Auto dwells.
   //!< '       1 Hz resolution
   //!< '       Range: -1 MHz ~ 1 MHz
   unsigned long    GPS_DOPP_WIN_HZ;                 //!< ' Two sided frequency window
   //!< '       1 Hz resolution
   //!< '       Range: -2 MHz ~ 2 MHz
   unsigned long    GPS_CODE_PHASE_CENTER_CHIPX40;   //!< ' Code phase center in chipx32. Not applicable to Auto dwells.
   //!< '       Chipx32 Resolution
   //!< '       Range: 0 ~ 1022*32
   unsigned short   GPS_CODE_PHASE_WIN_CHIPX1;       //!< ' Code phase window size in units of chips.
   //!< '       Range: > 0 and < 1023 for GPS
   unsigned char    GPS_SRCH_MODE;                   //!< ' GPS Search Mode:
   //!< '       3 - GPS LBW Chipx2 20ms PDI
   //!< '       4 - GPS LBW Chipx2 160ms PDI
   unsigned short   GPS_NUM_POSTD;                   //!< ' Number of Post Detections
   //!< '       Range: 1 ~ 65535
   unsigned char    GPS_PFA;                         //!< ' Probability of False Alarm value. PFA is internally represented as a power of 10.
   //!< ' This field defines the exponent without the negative sign.
   //!< ' Eg., If PFA 10^(-4) is desired, then this field equals 4.
   //!< '       Range: 0 ~ 255
   unsigned long    GPS_RESERVED;                           //!< ' Must be set to 0
   unsigned char    GLO_CONTROL_FLAG;                //!< ' Bit 0:
   //!< '       0 = As Prescribed. All parameters specified in this command are applied unchanged.
   //!< '       1 = Automatic. Automatic code phase and doppler centering. Code phase and doppler
   //!< '            parameters from the DM command are ignored. The GNSS software propagates the
   //!< '            values from prior measurements stored in software.
   //!< ' Bit 1:    Applicable to Auto dwells ONLY.
   //!< '       0 = No Truncation of code phase center
   //!< '       1 = Truncation of code phase center so that the peak is randomly sampled within the chip.
   //!< ' Bit 2:    Applicable to Auto dwells ONLY.
   //!< '       0 = No Randomization of Doppler
   //!< '       1 = Randomization of doppler
   char             GLO_FREQ_K;                      //!< ' GLO SV Frequency: -7 to +6 for specific GLO Frequency ID
   long             GLO_DOPP_HZ;                     //!< ' Doppler (center frequency) to search at. Not applicable to Auto dwells.
   //!< '       1 Hz resolution
   //!< '       Range: -1 MHz ~ 1 MHz
   unsigned long    GLO_DOPP_WIN_HZ;                 //!< ' Two sided frequency window
   //!< '       1 Hz resolution
   //!< '       Range: -2 MHz ~ 2 MHz
   unsigned long    GLO_CODE_PHASE_CENTER_CHIPX40;   //!< ' Code phase center in chipx32. Not applicable to Auto dwells.
   //!< '       Chipx32 Resolution
   //!< '       Range: 0 ~ 510*32
   unsigned short   GLO_CODE_PHASE_WIN_CHIPX1;       //!< ' Code phase window size in units of chips.
   //!< '       Range: > 0 and < 511 for GLO
   unsigned char    GLO_SRCH_MODE;                   //!< ' GLONASS Search Mode
   //!< '       18  - GLO Chipx2 20ms PDI
   unsigned short   GLO_NUM_POSTD;                          //!< ' Number of Post Detections
   //!< '       Range: 1 ~ 65535
   unsigned char    GLO_HW_CHAN;                     //!< ' GLO Hardware Channel Number 0: automatic, 1-12: unique HW Chan to use
   unsigned char    GLO_PFA;                         //!< ' Probability of False Alarm value. PFA is internally represented as a power of 10.
   //!< ' This field defines the exponent without the negative sign.
   //!< ' Eg., If PFA 10^(-4) is desired, then this field equals 4.
   //!< '       Range: 0 ~ 255
   unsigned long    GLO_RESERVED;                           //!< ' Must be set to 0
   unsigned short   DWELL_CNT;                       //!< ' Not Used
   unsigned short   TOTAL_NUM_DWELLS;                //!< ' Not Used
   unsigned short   PASS_DWELL_CNT;                  //!< ' Not Used
   unsigned long    RESERVED;                              //!< ' Must be set to 0
   unsigned char    BDS_CONTROL_FLAG;                //!< ' Bit 0:
   //!< '       0 = As Prescribed. All parameters specified in this command are applied unchanged.
   //!< '       1 = Automatic. Automatic code phase and doppler centering. Code phase and doppler
   //!< '            parameters from the DM command are ignored. The GNSS software propagates the
   //!< '            values from prior measurements stored in software.
   //!< ' Bit 1:    Applicable to Auto dwells ONLY.
   //!< '       0 = No Truncation of code phase center
   //!< '       1 = Truncation of code phase center so that the peak is randomly sampled within the chip.
   //!< 'The following are used for GNSS Engine revs > Gen8B_BDS
   unsigned char   BDS_SV;                           //!< ' SV id for BDS Dwell, 1 ~ 37 for BDS
   signed long     BDS_DOPP_MPS;                     //!< ' Doppler (center frequency) to search at. Not applicable to Auto dwells.
   //!< ' 1 m/s resolution, Range:  -19000 m/s ~ +19000 m/s
   unsigned long   BDS_DOPP_WIN_HZ;                  //!< ' Two sided frequency window 1 Hz resolution, Range: -2 MHz ~ 2 MHz
   unsigned long   BDS_CODE_PHASE_CENTER_CHIPX40;    //!< ' Code phase center in chipx40. Chipx40 Resolution, Range: 0 ~ 2045*40
   unsigned short  BDS_CODE_PHASE_WIN_CHIPX1;        //!< ' Code phase window size in units of chips.  Range: > 0 and < 2046
   unsigned char   BDS_SRCH_MODE;                    //!< ' 30  BDS Chipx1 1ms PDI
   //!< ' 31  BDS Chipx2 1ms PDI
   //!< ' 32  BDS Chipx1 20ms PDI
   //!< ' 33  BDS Chipx2 20ms PDI
   //!< ' 34  BDS Chipx2 20ms BET
   unsigned short  BDS_NUM_POSTD;                    //!< ' Number of Post Detections. Range: 1 ~ 65535
   unsigned char   BDS_PFA;                          //!< ' Probability of False Alarm value. PFA is internally represented as a power of 10.
   unsigned long   BDS_RESERVED;                     //!< ' Reserved. To ensure future compatibility, this value must be set to zero.

   unsigned char   MAX_SV_DWELL;                     //!< ' Enablement of Max SV Dwell
   //!< '0 for disable, 1 for enable
   //!< ' Bit 1: GPS
   //!< ' Bit 2: GLO
   //!< ' Bit 3: BDS
   //!< ' Bit 4: GAL

   unsigned char    GAL_CONTROL_FLAG;                //!< ' Bit 0:
   //!< '       0 = As Prescribed. All parameters specified in this command are applied unchanged.
   //!< '       1 = Automatic. Automatic code phase and doppler centering. Code phase and doppler
   //!< '            parameters from the DM command are ignored. The GNSS software propagates the
   //!< '            values from prior measurements stored in software.
   //!< ' Bit 1:    Applicable to Auto dwells ONLY.
   //!< '       0 = No Truncation of code phase center
   //!< '       1 = Truncation of code phase center so that the peak is randomly sampled within the chip.
   //!< 'The following are used for GNSS Engine revs > Gen8B_GAL
   unsigned char   GAL_SV;                           //!< ' SV id for GAL Dwell, 1 ~ 37 for GAL
   signed long     GAL_DOPP_MPS;                     //!< ' Doppler (center frequency) to search at. Not applicable to Auto dwells.
   //!< ' 1 m/s resolution, Range:  -19000 m/s ~ +19000 m/s
   unsigned long   GAL_DOPP_WIN_HZ;                  //!< ' Two sided frequency window 1 Hz resolution, Range: -2 MHz ~ 2 MHz
   unsigned long   GAL_CODE_PHASE_CENTER_CHIPX40;    //!< ' Code phase center in chipx40. Chipx40 Resolution, Range: 0 ~ 2045*40
   unsigned short  GAL_CODE_PHASE_WIN_CHIPX1;        //!< ' Code phase window size in units of chips.  Range: > 0 and < 2046
   unsigned char   GAL_SRCH_MODE;                    //!< ' 30  GAL Chipx1 1ms PDI
   //!< ' 31  GAL Chipx2 1ms PDI
   //!< ' 32  GAL Chipx1 20ms PDI
   //!< ' 33  GAL Chipx2 20ms PDI
   //!< ' 34  GAL Chipx2 20ms BET
   unsigned short  GAL_NUM_POSTD;                    //!< ' Number of Post Detections. Range: 1 ~ 65535
   unsigned char   GAL_PFA;                          //!< ' Probability of False Alarm value. PFA is internally represented as a power of 10.
   unsigned long   GAL_RESERVED;                     //!< ' Reserved. To ensure future compatibility, this value must be set to zero.
} CGPS_Gen8_PrescribedDwell_struct_type;

// Log code assigned for this is 0x1526. (LOG_GNSS_BROADBAND_JAMMER_INFO_C)
typedef struct
{
   unsigned char    u_Version;                      //!< ' Log Version
   unsigned char    u_Sv;                           //!< ' SV
   unsigned char    u_NumNoiseBins;                 //!< ' Number of noise (freq)bins used to get measured mean noise
   unsigned char    u_SearchMode;               //!< ' Search Mode
   unsigned char   u_AgcType;                 //!< ' AGC Type
   //!< '    0: RESERVED
   //!< '    1: 50hz SWAGC
   //!< '    2: HWAGC
   //!< '    3: 1k SWAGC
   //!< '    4: RESERVED
   unsigned char   e_PeakResult;              //!< ' Peak status - BMP, BEP, BOP, etc
   unsigned short   w_DetectionThreshold;       //!< ' Detection threshold in fixed eng units
   unsigned short   w_DualLowThreshold;         //!< ' DualLowThreshold (if Dual thresh is enabled)
   unsigned short   w_ScaledDetectionThreshold;//!< ' Scaled Detection threshold fixed eng units
   unsigned short   w_ScaledDualLowThreshold;   //!< ' Scaled Dual Low Threshold for LTE B13
   //!< ' (Increased threshold based on SV) in fixed energy units
   unsigned short   w_DetThreshWithMeasNoise;   //!< ' Detection threshold with measured noise in Fixed eng unit
   unsigned short   w_DualLowThreshWithMeasNoise;//!< ' Dual Low Threshold  with measured noise in Fixed eng unit
   unsigned short   w_PredictedNoise;               //!< ' Predicted Noise in fixed eng units
   unsigned short   w_MeasuredMeanNoise;            //!< ' Measured Noise (after running Broadband jammer test) in fixed energy unit
   unsigned short   w_PeakEng;                      //!< ' Raw Peak Energy
   unsigned long int    q_GnssRtcMs;
   float    q_PredCNo;                  //!< ' CNo computed with Predicted Noise
   float    q_MeasCNo;                  //!< ' CNo computed with Measured Mean Noise
   float    q_2ndPredCNo;               //!< ' CNo computed with Predicted Noise of 2nd peak sent to MC
   float    q_2ndMeasCNo;               //!< ' CNo computed with Measured Mean Noise of 2nd peak sent to MC
} GNSS_BroadBandJammerInfoStruct;

typedef struct
{
   unsigned char    TEST_CONTROL;               //!< ' 0 - Start IqTest
   unsigned short   FLAGS;                  //!< ' Bit 0: Enables IQ DM Logging.
   //!< ' Bit 1: Enables FFT (on-board) DM Logging
   //!< ' Bit 2: Hanning window enabled for on-board FFT
   unsigned short   RETRANSMIT_PACKET_NUM;  //!< ' Not Used
   unsigned char    RF_STATUS_LOG_RATE_HZ;  //!< ' Logging Rate of RF Status Log, Range: 1 ~ 10
   unsigned char    COLLECT_MODE;           //!< ' See gps_start_iq_test_collect_mode_gen8
   char             GLO_R1_CHAN;            //!< ' GLO SV Frequency: 8 - for all, -7 to +6 for specific GLO Frequency ID
   unsigned char    GLO_HW_CHAN;            //!< ' GLO Hardware Channel Number 0: automatic, 1-12: unique HW Chan to use
   unsigned short   SAMPLE_CNT_1K;          //!< ' Number of samples (in multiples of 1024) collected per incoherent integration.
   //!< '       1 ~ 1024 - Valid for all WB/FB IQ
   //!< '       0 ~ 1024 - Valid for all NB. 0 => Continuous NBIQ
   //!< '       > 1024 - Invalid
   unsigned char    INTEGRATIONS;           //!< ' Number of incoherent integrations
   signed long      CENTER_FREQ_NBIQ;       //!< ' Center frequency used in Searcher for NB IQ test (Manual Mode only)
   double GNSS_SOC_TCXO_Speed;
} CGPS_GNSS_SOC_StartIqTest_struct_type;

typedef struct
{
   unsigned char VERSION;                  //!< '  1
   unsigned char SCAN_MODE;                //!< '  0 ?Single Shot for IQ tests, 1 ?Continous mode for other RFDev tests
   unsigned char SCAN_START_STOP;          //!< '  0 - Stop scan; 1 - Start Scan;  2 ?Stop and restart scan
   unsigned char GPS_SCAN_TYPES_ENABLED;   //!< '  Bit 0 - enable Fast scan; Bit 1 - enable Deep scan
   unsigned char GLO_SCAN_TYPES_ENABLED;   //!< '  Bit 0 - enable Fast scan; Bit 1 - enable Deep scan
   unsigned char PROBE_POINT_FOR_SCAN;     //!< '  Set Bit 0:3 to 1 for Probe point P1-P4
   unsigned char TRACKING_MODE_CONTROL;    //!< '  0 - disable, 1 enable
   unsigned char RESET_NOTCH_FILTERS;      //!< '  0 - Do not reset notch filters; 1 - Reset notch filters
} GNSS_SpecAn_Config_Request_type;

typedef struct
{
   unsigned char VERSION;                  //!< '  1
   unsigned char SCAN_MODE;                //!< '  0 ?Single Shot for IQ tests, 1 ?Continous mode for other RFDev tests
   unsigned char SCAN_START_STOP;          //!< '  0 - Stop scan; 1 - Start Scan;  2 ?Stop and restart scan
   unsigned char GPS_SCAN_TYPES_ENABLED;   //!< '  Bit 0 - enable Fast scan; Bit 1 - enable Deep scan
   unsigned char GLO_SCAN_TYPES_ENABLED;   //!< '  Bit 0 - enable Fast scan; Bit 1 - enable Deep scan
   unsigned char PROBE_POINT_FOR_SCAN;     //!< '  Set Bit 0:3 to 1 for Probe point P1-P4
   unsigned char TRACKING_MODE_CONTROL;    //!< '  0 - disable, 1 enable
   unsigned char RESET_NOTCH_FILTERS;      //!< '  0 - Do not reset notch filters; 1 - Reset notch filters
   unsigned char BDS_SCAN_TYPES_ENABLED;   //!< '  Bit 0 - enable Fast scan; Bit 7- enable Shallow scan
} GNSS_SpecAn_Config_Request_type_V2;

typedef struct
{
   byte  CMD_CODE;                //  128 (0x80)
   byte  SUBSYS_ID;               //  13 (0x0D)
   word  SUBSYS_CMD_CODE;         //  109
   dword SUBSYS_STATUS;           //  0 for SUCCESS
   word  SUBSYS_DELAYED_RSP_ID;   //  0 Nothing more to follow
   word  SUBSYS_RESPONSE_CNT;     //  0 for 1st response
   byte  Enabled;                 //  1 if either Rx1 or Rx2 blanking are enabled, 0 otherwise.
   dword Rx1Counter;              //  Current Rx1 Blank count
   dword Rx2Counter;              //  Current Rx2 Blank count
} GNSS_BlankingStatus_Response_type;

typedef struct
{
   diagpkt_subsys_header_type   Diag_Header;
   dword                        Status;
   word                         Delayed_response_id;
   word                         Response_count;
} GNSS_XO_FACTORY_CAL_Rsp_Header_type;

typedef struct
{
   dword                        Version;           // Set to 1
   dword                        RX_Freq_KHz;       // Carrier Freq. in KHz
   long                         Offset;            // Downlink Signal Offset, ref. Carrier Freq.
   long                         PowerLevel;        // Power Level of the CW Signal dBm
   byte                         XTAL;              // GNSS_XO_FACTORY_CAL_XTAL_Type
   byte                         Technology;        // GNSS_XO_FACTORY_CAL_TECHNOLOGY_Type
} GNSS_XO_FACTORY_CAL_Request_struct_type;

#define _GNSS_XO_FACTORY_IDENTIFIER 0xFEDCBA98

typedef struct
{
   diagpkt_subsys_header_type                HEADER;
   dword                                    IDENTIFIER;        //  Unique identifier for this command
   GNSS_XO_FACTORY_CAL_Request_struct_type  REQUEST_DATA;
} GNSS_XO_FACTORY_CAL_Request;

typedef struct
{
   GNSS_XO_FACTORY_CAL_Rsp_Header_type  HEADER;
   dword                                IDENTIFIER;         // Unique identifier from request
   GNSS_XO_FACTORY_CAL_Resp_struct_type RESPONSE_DATA;
} GNSS_XO_FACTORY_CAL_Delayed_Resp;

// Note: due to shared structural components, this log is defined here rather than with
// the other GNSS Log messages

/**
Format for GNSS TCXO Measurement report:
GNSS_XO_FACTORY_MEASUREMENT_REPORT_LOG = 0x1803
*/
typedef struct
{
   dword                              IDENTIFIER;        //  Unique identifier for this command
   GNSS_XO_FACTORY_CAL_Request_struct_type  REQUEST_DATA;
   GNSS_XO_FACTORY_CAL_Resp_struct_type     RESPONSE_DATA;
} GNSS_XO_FACTORY_Measurement_Log_Struct;

typedef struct
{
   unsigned char    u_duration;                 //!< ' Duration of track in seconds (1-60)
   unsigned char    u_TestMode;                 //!< ' See gnss_soc_single_chan_track_test_enum_type
   unsigned char    u_GpsSvId;                  //!< ' GPS SV to track: 0 for all, 1-32 for GPS SV
   char             b_GloFreqencyId;            //!< ' GLO SV Frequency: 8 - for all, -7 to +6 for specific GLO Frequency ID
} GNSS_SOC_SINGLE_SvTrack_Struct_type;

/* ADC Return/output struct definations */
typedef struct
{
   double power;
   double frequency;
   double bandwidth;
} GNSS_adcSpurInfo;

typedef struct
{
   double total_rms;
   double total_rms_isamp;
   double total_rms_qsamp;
   double peak_noise_total;
   double noise_gps;
   double average_noise_gps;
   double peak_noise_gps;
   double noise_glo;
   double average_noise_glo;
   double peak_noise_glo;
   double noise_bds;
   double peak_noise_bds;
   double noise_gal;
   double peak_noise_gal;
   double noise_spurs;
   double noise_pdsdelta_gpsglo_dB;
   double mean_iq_amp_mv;
   double cdf_adc_amp_ninety_tile;
   double fsample;
   double inv_R;
   double sigPosHz;
   double fLO;
   double gpsBand[2];
   double gloBand[2];
   double bdsBand[2];
   double galBand[2];
   byte   logVersion;
   void * spur_data_power;     // Must point to a vector<GNSS_adcSpurInfo>
   void * spur_data_frequency; // Must point to a vector<GNSS_adcSpurInfo>
   bool   LTE_Supportted_WideBand_Jammer_Config;
   int    LTE_Band;
   int    LTE_Start_RB;
   int    LTE_Number_Of_RBs;
   double LTE_jammer_pow;
   double LTE_WideBandJam_Lower_Limit;
   double LTE_WideBandJam_Upper_Limit;
   double rbw;
   long pgaGain;
   byte spur_data_size;
} GNSS_adcIqResults;

typedef struct
{
   bool   Use_LTE_WideBandJam_Limits;
   double LTE_WideBandJam_Lower_Limit;
   double LTE_WideBandJam_Upper_Limit;
} GNSS_ADCIQ_WideBandJam_Parameters;

typedef struct
{
   uint16           packet_type;   // Should always be 0x1510
   uint8            version;
   uint8            u_SensorLogged;
   uint32           dw_TimeOfFirstSample;
   uint16           w_SampleTimeOffset;
   uint8            u_Flags;
   uint8            u_NumSamples;
   uint32           dw_FinalTimestamp;
   double           f_xAxisSample;
   double           f_yAxisSample;
   double           f_zAxisSample;
   uint16           w_TimeGpsWeekOfFirstSample;
   uint32           dw_TimeGpsMsecOfFirstSample;
} GNSS_Sensors_Sensor_Data;

/******************************************************************************
Diagnostic - CGPS PD API subsystem
*******************************************************************************/
#define CGPS_DIAG_PDAPI_CMD_SUBSYSTEM 100

#define CGPS_DIAG_PDAPI_CMD_PACKET_VERSION 1

#define PDSM_PA_DELETE_EPH  0x0001
#define PDSM_PA_DELETE_ALM  0x0002
#define PDSM_PA_DELETE_POS  0x0004
#define PDSM_PA_DELETE_TIME 0x0008
#define PDSM_PA_DELETE_IONO  0x0010
#define PDSM_PA_DELETE_UTC  0x0020
#define PDSM_PA_DELETE_HEALTH 0x0040
#define PDSM_PA_DELETE_SVDIR  0x0080
#define PDSM_PA_DELETE_SVSTEER 0x0100
#define PDSM_PA_DELETE_SADATA 0x0200
#define PDSM_PA_DELETE_RTI    0x0400
#define PDSM_PA_TIME_UNC 0x800
#define PDSM_PA_POS_UNC 0x1000
#define PDSM_PA_TIME_OFFSET 0x2000
#define PDSM_PA_POS_OFFSET 0x4000
#define PDSM_PA_DELETE_CELLDB_INFO 0x8000
#define PDSM_PA_RESERVED1 0x10000
#define PDSM_PA_RESERVED2 0x20000

typedef enum
{
   _DIAG_CGPS_INIT = 0X00, // 00
   _DIAG_CGPS_REGISTER_PD = 0X01, // 01
   _DIAG_CGPS_REGISTER_PA_CMD = 0x02, //Not Supported
   _DIAG_CGPS_REGISTER_LCS_CMD = 0x03, //Not Supported
   _DIAG_CGPS_REGISTER_EXT_STAT_CMD = 0x04, //Not Supported
   _DIAG_CGPS_ACTIVATE = 0X07, // 07
   _DIAG_CGPS_DEACTIVATE = 0X08, // 08
   _DIAG_CGPS_RELEASE = 0X09, // 09
   _DIAG_CGPS_START = 0X0A, // 10
   _DIAG_CGPS_END_CMD = 0x0B, //11
   _DIAG_CGPS_SET_PARAM = 0X0C, // 12
   _DIAG_CGPS_GET_PARAM_CMD = 0x0D, //Not Supported
   _DIAG_CGPS_GET_LAST_KNOWN_POSITION_CMD = 0x0E, //Not Supported
   _DIAG_CGPS_GET_PDAPI_VERS_CMD = 0x0F, //Not Supported
   _DIAG_CGPS_NOTIFY_VERIFY_SEND_USER_ACTION_CMD = 0x10, //Not Supported
   _DIAG_CGPS_INJECT_TIME_CMD = 0x11, //Not Supported
   _DIAG_CGPS_LCS_VX_INIT_CLIENT_CMD = 0x1F, //Not Supported
   _DIAG_CGPS_LCS_VX_INIT_CLIENT_APP_INFO_CMD = 0x20, //Not Supported
   _DIAG_CGPS_LCS_VX_RELEASE_CLIENT_CMD = 0x21, //Not Supported
   _DIAG_CGPS_LCS_VX_QUERY_CONFIG_CMD = 0x22, //Not Supported
   _DIAG_CGPS_LCS_VX_GET_CLIENT_TYPE_CMD = 0x23, //Not Supported
   _DIAG_CGPS_LCS_VX_GET_STATUS_CMD = 0x24, //Not Supported
   _DIAG_CGPS_QUERY_SM_VERSION = 0xC8  //Not Supported
} CGPS_PDAPI_Cmd_Code_Enum_type;

typedef enum
{
   PDSM_SESSION_OPERATION_MIN = 0,
   PDSM_SESSION_OPERATION_STANDALONE_ONLY,
   PDSM_SESSION_OPERATION_MSBASED,
   PDSM_SESSION_OPERATION_MSASSISTED,
   PDSM_SESSION_OPERATION_OPTIMAL_SPEED,
   PDSM_SESSION_OPERATION_OPTIMAL_ACCURACY,
   PDSM_SESSION_OPERATION_OPTIMAL_DATA,
   PDSM_SESSION_OPERATION_REF_POSITION,
   PDSM_SESSION_OPERATION_MAX = 0x10000000
} PDSM_PD_Operation_Mode_Enum_type;

typedef enum
{
   PDSM_CLIENT_TYPE_NONE = -1,     /* FOR INTERNAL USE OF PDSM ONLY! */

   PDSM_CLIENT_TYPE_BROWSER,           /* Reserved for browser Client */
   PDSM_CLIENT_TYPE_UI,            /* Reserved for UI running on Same processor */
   PDSM_CLIENT_TYPE_PDA,               /* Reserver for KALI PDA */
   PDSM_CLIENT_TYPE_DM,            /* For DM over RPC */
   PDSM_CLIENT_TYPE_NI,            /* Reserved for NI Clients */
   PDSM_CLIENT_TYPE_BREW,              /* Reserved for BREW clients */
   PDSM_CLIENT_TYPE_JAVA,              /* Reserved for Java Clients */
   PDSM_CLIENT_TYPE_TEST1,         /* Test client types, Added/Deleted in future */
   PDSM_CLIENT_TYPE_TEST2,         /* Test client types, Added/Deleted in future */
   PDSM_CLIENT_TYPE_OEM,               /* Reserved for OEM Clients */
   PDSM_CLIENT_TYPE_TEST3,         /* Reserved for KDDI Clients */
   PDSM_CLIENT_TYPE_XTRA,              /* Reserved for gpsOneXTRA Clients */
   PDSM_CLIENT_TYPE_ATCOP,         /* Reserved for ATCOP Clients */
   PDSM_CLIENT_TYPE_MAX,               /* FOR INTERNAL USE OF PDSM ONLY! */

   PDSM_CLIENT_TYPE_E_SIZE=0x100000   /* To force enum to int */
} CGPS_PDSM_Client_Type_Enum_type;

typedef enum
{
   PDSM_PD_SESS_TYPE_MIN = -1,            /* Internal use of PDSM */
   PDSM_PD_SESS_TYPE_LATEST,              /* Get latest PD info */
   PDSM_PD_SESS_TYPE_NEW,                 /* Get new position */
   PDSM_PD_SESS_TYPE_TRACK_IND,           /* Tracking mode independent fixes */
   PDSM_PD_SESS_TYPE_DATA_DLOAD,          /* Data download option */
   PDSM_PD_SESS_TYPE_MAX,                 /* For internal use of PDSM */
   PDSM_PD_SESS_TYPE_E_SIZE=0x10000000    /* Fix the enum size to int */
} PDSM_PD_Session_Type_Enum_type;

typedef enum
{
   PDSM_SERVER_OPTION_MIN = -1,
   PDSM_SERVER_OPTION_USE_DEFAULT,         /* Use Default settings for TLM type+adrs */
   PDSM_SERVER_OPTION_USE_LOCAL,           /* Use param's along with fn call */
   PDSM_SERVER_OPTION_MAX = 0x10000000
} PDSM_Server_Option_Enum_type;

typedef enum
{
   PDSM_SERVER_ADDR_TYPE_MIN = -1,
   PDSM_SERVER_TYPE_IPV4_ADDRESS,
   PDSM_SERVER_TYPE_URL_ADDRESS,
   PDSM_SERVER_TYPE_IPV6_ADDRESS,
   PDSM_SERVER_ADDR_TYPE_MAX = 0x1000000
} PDSM_Server_Address_Type_Enum_type;

typedef enum
{
   GPS_PD_Delete_Params = 04
} CGPS_PDAPI_Parameter_Enum_type;

typedef enum
{
   GPSDIAG_END_NON_DLOAD = 0,  //end nondata download/position session
   GPSDIAG_END_DLOAD = 1       //end data download session
} CGPS_PDAPI_End_Type_Enum_type;

typedef struct
{
   unsigned char iCmdCode;

   unsigned long iClientType;

   unsigned char iRegisterType;

   unsigned char iSessionType;
   unsigned char iOperationMode;
   unsigned char iServerOption;
   unsigned char iServerAddressType;
   unsigned long iClassID;
   unsigned char iQoSPerformance;
   unsigned long iQoSAccuracyThreshold;
   unsigned long iTimeBetweenFixes;
   unsigned long iNumberOfFixes;
   unsigned long iClientID;
   unsigned long Reserved1;
   unsigned long Reserved2;
   unsigned long iServerAddress;
   unsigned long iServerPort;

   unsigned char iParamType;
   unsigned short iParamLength;
   unsigned long iAidingDataMask;
   unsigned long iTimeUncertainty;
   unsigned long iPositionUncertainty;
   unsigned long iTimeOffset;
   unsigned long iPositionOffset;
   unsigned long iEphemerisSVMask;
   unsigned long iAlmanacSVMask;
   unsigned long iCellDBInfoDeleteMask;

   unsigned long iSessionEndType;
} CGPS_PDAPI_Request_Struct_type;

typedef struct
{
   uint8   Command_Code;        // 108
   uint8   SubSys_ID;           // 11
   uint16  SubSys_Command_code; // 1
   uint8   CGPS_Command_Code;   // 1
   uint8   Version;             // 1
   uint32  Client_ID;           // 8
   uint32  File_Size;           // Length of aiding Data;
   uint32  Data_Part_number;    // 1 - all data can be sent in a single packet.
   uint32  Total_Parts;         // 1 - only need one packet
   uint32  Data_Length;         // Length of aiding Data;
   uint32  AidingData[500];
} GNSS_LTE_PRS_Aiding_Data_Command_Struct;

/******************************************************************************
Diagnostic - ISDB-T subsytem
*******************************************************************************/

typedef enum
{
   _DIAG_ISDB_UBM_L1_ACQ_CMD                        = 100,  //!< ' Acquire                                  */
   _DIAG_ISDB_UBM_L1_RESET_CMD                      = 101,  //!< ' Reset                                    */
   _DIAG_ISDB_UBM_L1_ACQ_STATUS                     = 102,  //!< ' Acquire Status?                          */
   _DIAG_ISDB_UBM_L1_POWERUP_CMD                    = 103,  //!< ' Power Up                                 */
   _DIAG_ISDB_UBM_L1_POWERDOWN_CMD                  = 104,  //!< ' Power Down                               */
   _DIAG_ISDB_UBM_L1_ROUTE_Y1Y2_DEBUG_BUS           = 105,  //!< ' Route Y1Y2 Samples to the Debug Bus      */
   _DIAG_ISDB_UBM_L1_RS1_PACKET_CNT_CMD             = 106,  //!< ' Collect Packet Counter Statistics        */
   _DIAG_ISDB_UBM_L1_RECORD_TSIF_PACKETS_CMD        = 107,  //!< ' Record TSIF Packets                      */
   _DIAG_ISDB_UBM_L1_CONFIGURE_CIR_LOG_PARAMS       = 108,  //!< ' Configure No. of Frames per CIR Log      */
   _DIAG_ISDB_UBM_L1_PRBS_ONE_BIT_CMD               = 109,  //!< ' Setup VBER one-bit error Test            */
   _DIAG_ISDB_UBM_L1_PRBS_ONE_BIT_STATUS            = 110,  //!< ' 1 Bits Counted in PRBS one-bit Test      */
   _DIAG_ISDB_UBM_L1_ENABLE_LNA_UPDATE              = 111,  //!< ' Enable LNA Update Loop                   */
   _DIAG_ISDB_UBM_L1_DISABLE_LNA_UPDATE             = 112,  //!< ' Disable LNA Update Loop                  */
   _DIAG_ISDB_UBM_L1_CFG_JAMMER_CMD                 = 113,  //!< ' Change pre-FFT Jammer Parameters         */
   _DIAG_ISDB_UBM_L1_RSSI_STATUS                    = 114,  //!< ' Return Current RSSI Information          */
   _DIAG_ISDB_UBM_L1_RECOVERY_CMD                   = 115,  //!< ' Enter the Recovery State                 */
   _DIAG_ISDB_UBM_L1_CFG_RDSP_LOG_CMD               = 116,  //!< ' Configure RDSP Data Logging              */
   _DIAG_ISDB_UBM_L1_CFG_POST_FFT_JAMMER_CMD        = 117,  //!< ' Configure Post-FFT Jammer Parameters     */
   _DIAG_ISDB_UBM_L1_USE_RSSI_CAL_CMD               = 118,  //!< ' Enable/Disables RSSI calibration data    */
   _DIAG_ISDB_UBM_L1_SET_LNA_CMD                    = 119,  //!< ' Set the LNA State                        */
   _DIAG_ISDB_UBM_L1_SET_PERIODIC_LOG_ADDR          = 120,  //!< ' Set the Address for RDSP Log Items       */
   _DIAG_ISDB_UBM_L1_ANT_TUNE_PDM_CONTROL_CMD       = 122,  //!< ' Control the Antenna Tune PDM Pin         */
   _DIAG_ISDB_UBM_L1_RDSP_WRITE_CMD                 = 123,  //!< ' Write specific RDSP registers            */
   _DIAG_ISDB_UBM_L1_GET_TMCC_FRAME_INFO_CMD        = 124,  //!< ' Get the TMCC Information Field           */
   _DIAG_ISDB_UBM_L1_CFG_ITEM                       = 125,  //!< ' Set/Read a given L1 Configuration Item   */
   _DIAG_ISDB_UBM_L1_PEEK_POKE_CMD                  = 126,  //!< ' Read/Write DSP/HW Registers              */
   _DIAG_ISDB_UBM_L1_RESET_PKT_TRASH_COUNTERS_CMD   = 127,  //!< ' TBD                                      */
   _DIAG_ISDB_UBM_L1_HARD_RECOVERY_CMD              = 128,  //!< ' TBD                                      */
   _DIAG_ISDB_UBM_L1_SAMPSRV_DUMP_CMD               = 129,  //!< ' Handle a sample server dump (QXDM)       */
   _DIAG_ISDB_UBM_L1_ESR_RESET_CMD                  = 130,  //!< ' Reset the ESR counters                   */
   _DIAG_ISDB_UBM_L1_PERF_CNTS_RESET_CMD            = 131,  //!< ' Reset the performance counters           */
   _DIAG_ISDB_UBM_L1_PERF_CNTS_SET_PRINT_MASK_CMD   = 132,  //!< ' Set the Performance Counters Print Mask  */
   _DIAG_ISDB_UBM_L1_LOG_ACQ_CMD                    = 133,  //!< ' Request the acquisition status log       */
   _DIAG_ISDB_UBM_L1_GET_TECHNOLOGY_CMD             = 134,  //!< ' Get the current working technology       */
   _DIAG_ISDB_UBM_L1_RDSP_HALT_CMD                  = 135,  //!< ' Halt the RDSP                            */
   _DIAG_ISDB_UBM_L1_RETRY_ACQ_CMD                  = 136,  //!< ' Retry Acquisition                        */
   _DIAG_ISDB_UBM_L1_GET_CURRENT_STATE_CMD          = 137,  //!< ' Get the current state of L1              */
   _DIAG_ISDB_UBM_L1_RESTORE_DEFAULT_CFG_CMD        = 138,  //!< ' Restore L1 SW cfg values to default      */
   _DIAG_ISDB_UBM_L1_GET_VERSION_INFO_CMD           = 139,  //!< ' Get version and supported technologies   */
   _DIAG_ISDB_UBM_L1_RS1_PACKET_CNT_RES_V2_CMD      = 140,  //!< ' Get RS1 packet count                     */
   _DIAG_ISDB_UBM_L1_GET_PARAM_VAL_CMD              = 141,  //!< ' Get L1-L3 API parameter                          */
   _DIAG_ISDB_UBM_L1_HANDLE_TRACK_LOOPS_CFG_CMD     = 143,  //!< ' Configure tracking loops                         */
   _DIAG_ISDB_UBM_L1_GET_TRACK_LOOPS_STATUS_CMD     = 144   //!< ' Get tracking loops status (Enabled/ Disabled)    */
} isdbt_diag_subsys_cmd_enum_type;

typedef enum
{
   ISDB_UBM_L1_CFG_EBI2_WS                              =0,     //!< EBI2 waitstates
   ISDB_UBM_L1_HANDLE_L3_ACK                            =7,     //!< whether to handle acks intended for L3 by L1
   //!< 0 -> Handle L3 acks
   //!< 1 -> Do not handle L3 acks
   ISDB_UBM_L1_CFG_USE_ACQ_TIMEOUT                      =8,     //!< whether to use the acquisition timeout
   //!< 0 -> Do not use acq timeout
   //!< 1 -> Use acq timeout
   ISDB_UBM_L1_CFG_ACQ_TIMEOUT_MS                       =26,    //!< Time for acquisition timeout in ms
   ISDB_UBM_L1_CFG_RECOVERY_RETRIES                     =30,    //!< Number of recovery attempts
   ISDB_UBM_L1_CFG_SOFT_RECOVERY_DELAY                  =64,    //!< Soft recovery delay before reacquire [mSec]
   ISDB_UBM_L1_CFG_SRECOVERY_MIN_GOOD_RS1               =65,    //!< Number of good RS1 packets needed to avoid recovery
   ISDB_UBM_L1_CFG_SRECOVERY_MAX_DROP_COUNT             =66,    //!< Number of consecutive TPS frames with high RS1 packets
   ISDB_UBM_L1_CFG_RS1_DEX_LOCK_MAX_COUNT               =67,    //!< Number of consecutive TPS frames with RS1 lock
   ISDB_UBM_L1_CFG_INFINITE_SRECOVERY_TRAFFIC           =69,    //!< Soft recovery traffic (even if LOS)
   ISDB_UBM_L1_CFG_RF_TUNE_TIME_US                      =70,    //!< Expected RF tune time in micro seconds
   ISDB_UBM_L1_CFG_HARD_RECOVERY_POWERUP_WAIT_MS        =72,    //!< Wait between powerdown and powerup during hard recovery
   ISDB_UBM_L1_CFG_HARD_RECOVERY_ACQUISITION_WAIT_MS    =73,    //!< Wait between acquisitions during hard recovery
   ISDB_UBM_L1_CFG_RDSP_KEEP_ALIVE_TIMEOUT_MS           =74,    //!< Timeout on DSP interrupt
   ISDB_UBM_L1_CFG_RF_TUNE_MAX_POLLS                    =75,    //!< Max number of times the RF Tune process will repeat; multiply by UBM_L1_CFG_RF_TUNE_TIME_US to get the RF Tune timeout time
   ISDB_UBM_L1_CFG_DIAG_RDSP_TMCC_POWER_OPT_ENABLED     =76,    //!< Enable Power Save
   ISDB_UBM_L1_CFG_DIAG_FINE_TIME_FREEZE_TH             =77,    //!< Minimal ADC Level Threshold (in dBFS) for using Fine Time algorithm (Otherwise, Freeze is active)
   ISDB_UBM_L1_CFG_DIAG_NUM_M1_FAILED_ACQ_TRANS_M2      =78,    //!< Number of acquisition tries in Mode 1 before trying Mode 2
   ISDB_UBM_L1_CFG_DIAG_NUM_M2_FAILED_ACQ_TRANS_M1      =79,    //!< Number of acquisition tries in Mode 2 before trying Mode 1
   ISDB_UBM_L1_CFG_DIAG_TIME_TRACKING_CIR_TH_MODE2      =80,    //!< Channel Impulse Response (CIR) tap values below this threshold are zeroed before time tracking algorithm uses the CIR in Mode 2
   ISDB_UBM_L1_CFG_DIAG_TIME_TRACKING_CIR_TH_MODE3      =81,    //!< Channel Impulse Response (CIR) tap values below this threshold are zeroed before time tracking algorithm uses the CIR in Mode 3
   ISDB_UBM_L1_CFG_DIAG_TIME_TRACKING_DOPPLER_TH_MODE2  =82,    //!< Maximal doppler threshold for using FineTime algorithm in Mode 2, while ZFCE is not available
   ISDB_UBM_L1_CFG_DIAG_TIME_TRACKING_DOPPLER_TH_MODE3  =83,    //!< Maximal doppler threshold for using FineTime algorithm in Mode 3, while ZFCE is not available
   ISDB_UBM_L1_CFG_DIAG_DOPPLER_SWITCH_TH_MODE2         =84,    //!< Minimal doppler threshold for using ZFCE algorithm in Mode 2
   ISDB_UBM_L1_CFG_DIAG_DOPPLER_SWITCH_TH_MODE3         =85,    //!< Minimal doppler threshold for using ZFCE algorithm in Mode 3
   ISDB_UBM_L1_CFG_DIAG_ACQ_CTA_TH                      =86,    //!< At least one CTA hypothesis must be above this threshold to continue acquisition, Otherwise, acquisition is aborted
} ubm_isdb_configuration_items;

typedef enum
{
   ISDB_UBM_L1_MODE_2                           = 2,
   ISDB_UBM_L1_MODE_3                           = 3,
   ISDB_UBM_L1_MODE_ALL                         = 255
} ubm_isdb_mode;

typedef enum
{
   ISDB_UBM_L1_GUARD_4                          = 0,
   ISDB_UBM_L1_GUARD_8                          = 1,
   ISDB_UBM_L1_GUARD_16                         = 2,
   ISDB_UBM_L1_GUARD_ALL                        = 255
} ubm_isdb_guard;

typedef enum
{
   ISDB_RDSP_LOG_CPCE                           = 0,
   ISDB_RDSP_LOG_CPCE_UTILIZED_PATHLIST         = 1,
   ISDB_RDSP_LOG_CPCE_CANDIDATE_PATHLIST        = 2,
   ISDB_RDSP_LOG_CIR                            = 3,
   ISDB_RDSP_LOG_ACQUISITION_LIKELIHOOD         = 4,
   ISDB_RDSP_LOG_JAMMER_FFT_OUTPUT              = 5,
   ISDB_RDSP_LOG_TDSP_PERIODIC_LOGGING          = 6,
   ISDB_RDSP_LOG_TMCC_INFO                      = 7
} ubm_isdb_cfg_rdsp_log;

typedef enum
{
   ISDB_RDSP_WRITE_RX_FRONT_EE_INCR_THRESH      = 0,
   ISDB_RDSP_WRITE_RX_FRONT_EE_DECR_THRESH      = 1,
   ISDB_RDSP_WRITE_RX_FRONT_LNA_GAIN_STEPS      = 2,
   ISDB_RDSP_WRITE_RX_FRONT_GAIN_ADJUST         = 3
} ubm_isdb_rdsp_write_item;

typedef enum
{
   ISDB_UBM_L1_DIAG_TIME_TRACK_ID       = 0,
   ISDB_UBM_L1_DIAG_FREQ_TRACK_ID       = 1,
   ISDB_UBM_L1_DIAG_COARSE_DC_TRACK_ID  = 2,
   ISDB_UBM_L1_DIAG_FINE_DC_TRACK_ID    = 3,
   ISDB_UBM_L1_DIAG_AGC_TRACK_ID        = 4
} ubm_isdb_tracking_loops_id;

/******************************************************************************
Diagnostic - MBP RF subsystem
*******************************************************************************/

typedef enum
{
   _MBP_RF_SET_CFG_ITEM_CMD             = 12,   //!< ' Set Configuration Item
   _MBP_RF_SET_OPERATION_MODE_CMD       = 21,   //!< ' Set Operation Mode
   _MBP_RF_DUMP_SBI_SETTINGS_TO_EFS_CMD = 27,   //!< ' Dump SBI settings to file on phones EFS
   _MBP_RF_PEEK_POKE_CMD                = 30    //!< ' RF PEEK/POKE command
} mbp_diag_subsys_cmd_enum_type;

//! DVB-H/ISDB-T MBP Configuration Items
typedef enum
{
   MBP_RF_CFG_SPUR_CANCELLATION_ENABLED     = 13,   //"< ' Spur Cancellation Control (0=disable,1=enable)
   MBP_RF_CFG_ISDB_NB_JD_ENABLED            = 17,   //"< ' ISDB-T Narrowband Jammer Detection Control (0=disable,1=enable)
   MBP_RF_CFG_ISDB_WB_JD_ENABLED            = 18,   //"< ' ISDB-T Wideband Jammer Detection Control (0=disable,1=enable)
   MBP_RF_CFG_DVBH_NB_JD_ENABLED            = 19,   //"< ' DVB-H Narrowband Jammer Detection Control (0=disable,1=enable)
   MBP_RF_CFG_DVBH_WB_JD_ENABLED            = 20,   //"< ' DVB-H Wideband Jammer Detection Control (0=disable,1=enable)
   MBP_RF_CFG_JD_RSSI_TH_M1_QPSK            = 31,   //"< ' RSSI threshold in 100ths dBms above which automatic JD mode switching is enabled, QPSK
   MBP_RF_CFG_JD_RSSI_TH_M1_16QAM           = 32,   //"< ' RSSI threshold in 100ths dBms above which automatic JD mode switching is enabled, 16QAM
   MBP_RF_CFG_JD_RSSI_TH_M1_64QAM           = 33,   //"< ' RSSI threshold in 100ths dBms above which automatic JD mode switching is enabled, 64QAM
   MBP_RF_CFG_JD_RSSI_TH_M2_QPSK            = 34,   //"< ' RSSI threshold in 100ths dBms below which JD mode is forced to JD mode 1, QPSK
   MBP_RF_CFG_JD_RSSI_TH_M2_16QAM           = 35,   //"< ' RSSI threshold in 100ths dBms below which JD mode is forced to JD mode 1, 16QAM
   MBP_RF_CFG_JD_RSSI_TH_M2_64QAM           = 36    //"< ' RSSI threshold in 100ths dBms below which JD mode is forced to JD mode 1, 64QAM
} mbprftypes_cfg_item_type;

//! DVB-H/ISDB-T Jammer Detection Modes
typedef enum
{
   MBP_RF_JD_MODE_AUTO = 0,
   MBP_RF_JD_MODE_1    = 1,
   MBP_RF_JD_MODE_2    = 2
} mbprftypes_jd_mode_type;

/******************************************************************************
Diagnostic - Handset subsytem
*******************************************************************************/
/**
Handset Diagnostic commands, from Services\hs\gsmdiag.h
*/
typedef enum
{
   _HS_DISPLAY_GET_PARAMS_CMD       = 0,    //!< ' Get display information (height, width, bpp)
   _HS_DISPLAY_CAPTURE_DELAYED_CMD  = 2     //!< ' Capture screen contents
} DiagHsCmd_Enum;

/******************************************************************************
Diagnostic - TCXO Manager
*******************************************************************************/
#define TCXO_MGR_AUTO_FREQ_CTRL_LOG 0x1350
#define XO_FREQ_ESTIMATION_LOG      0x13D1
#define TCXO_MGR_FIELD_CAL_DATA     0x13D2

/******************************************************************************
FTM - Command ID's
*******************************************************************************/

/*===========================================================================*/
/**
\brief Enumeration to choose between the command formats.

Currently, the two formats are using CMD_CODE = 59 and CMD_CODE = 75
59 is used for MSM5xxx targets and 75 was introduced for MSM6xxx targets
*/
/*===========================================================================*/
typedef enum
{
   FTM_COMMAND_75 = 75, //!<' Command code 75 is used for MSM6100 and later
   FTM_COMMAND_59 = 59, //!<' Command code 59 is used for 5500 and 60xx
   FTM_COMMAND_TYPE_INVALID = -1    //!<' Invalid indicator
}  FTM_Command_Type;

/**
FTM Commands enumeration.

These are renamed with an _ prefix in order to avoid conflict with
the function names.

*/
typedef enum
{
   _FTM_SET_PDM             = 0,    //!< Sets a PDM to a value
   _FTM_SET_TX_ON               = 2,    //!< Sets the transmit circuitry ON
   _FTM_SET_TX_OFF              = 3,    //!< Sets the transmit circuitry OFF
   _FTM_SET_MODE                = 7,    //!< Sets the phones operating mode
   _FTM_SET_CHAN                = 8,    //!< Sets the phones current channel
   _FTM_GSM_DO_IP2_CAL          = 12,   //!< Do GSM IIP2 Cal
   _FTM_OVERRIDE                = 15,
   _FTM_SET_SMPS_PA_BIAS_VAL    = 17,   //!< Sets SMPS PA Bias Value
   _FTM_SET_SMPS_PA_BIAS_OVERRIDE = 18, //!< Set SMPS PA Bias Override mode
   _FTM_GET_SYNTH_STATE     = 16,   //!< Gets the current synthesizer lock state
   _FTM_GET_FEM_DIRECTORY_INFO  = 21,   //!< Gets names of directories containing XML files
   _FTM_SET_LNA_LINEARITY       = 25,   //!< Set LNA linearity mode
   _FTM_FM_TX_ST                = 37,   //!< Sends signaling tone
   _FTM_CDMA_CW_WAVEFORM        = 50,   //!< Turns on/off I/Q spreading of CDMA reverse link
   _FTM_GET_RX_AGC              = 53,   //!< Gets AGC value of Rx AGC loop
   _FTM_SET_PA_RANGE            = 54,   //!< Sets PA range
   _FTM_SET_TUNABLE_CAP         = 55,   //!< Sets the Tunable Cap register
   _FTM_SET_LNA_RANGE           = 58,   //!< Sets LNA range
   _FTM_GET_ADC_VAL         = 59,   //!< Gets ADC value
   _FTM_SET_LNA_OFFSET          = 81,   //!< Sets LNA offset
   _FTM_SET_CONCURRENCY_SCENARIO            = 100,  //!< Set RF senario
   _FTM_GET_CDMA_IM2            = 114,  //!< Gets IM2 IQ values
   _FTM_SET_DVGA_OFFSET     = 111,  //!< Sets DVGA offset
   _FTM_SET_FREQUENCY_SENSE_GAIN = 115,//!< Sets Frequency Sense Gain
   _FTM_TX_SWEEP_CAL            = 116,  //!< FTM Tx Sweep Cal
   _FTM_GET_DVGA_OFFSET     = 117,  //!< Gets DVGA Offset
   _FTM_GET_LNA_OFFSET          = 118,  //!< Gets LNA Offset
   _FTM_GET_HDET_FROM_TX_SWEEP_CAL = 119, //!< FTM Get HDET from Tx Cal
   _FTM_GET_FM_IQ               = 120,  //!< Gets FM IQ
   _FTM_SET_SECONDARY_CHAIN = 121,  //!< Set secondary Rx mode
   _FTM_GET_CTON                = 122,  //!< Get Rx Carrier / Noise ratio
   _FTM_SECOND_CHAIN_TEST_CALL  = 123,  //!< Set the call test mode for the second Rx
   _FTM_SET_HDET_TRACKING       = 124,  //!< Track Tx power to a specified HDET value
   _FTM_CONFIGURE_TX_SWEEP_CAL = 125,   //!< Configure the Tx Sweep command parameters
   _FTM_GET_CDMA_IM2_WITH_SUPPRESSION = 126, //!<Get CDMA IM2 with suppression
   _FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL=127, //!< Return all of the HDET values measured in the last TX SWEEP
   _FTM_SET_RF_POWER_MODE       = 128,  //!<' Set RF mode to High,Mid or Low power mode
   _FTM_SET_TX_SWEEP_STEP_SIZE = 129,   //!<' Configure CDMA/WCDMA Tx AGC PDM Step size for Tx sweep
   _FTM_TX_RX_FREQ_CAL_SWEEP    = 130,  //!<' CDMA Tx Rx Frequency measurement
   _FTM_LOAD_RF_NV              = 131,  //!<' load RF NV from NV
   _FTM_DO_INTERNAL_DEVICE_CAL  = 132,  //!<' Perform internal device cal
   _FTM_DO_DC_CAL               = 133,  //!<' Initialize the DC accumulators.
   _FTM_DO_XO_DC_CAL            = 134,  //!<! Coarse DC frequency calibration for XO targets
   _FTM_DO_XO_FT_CURVE_CAL     = 135,   //!<! Fine DC frequency and FT Curve Calibration for XO targets
   _FTM_SET_TX_WAVEFORM     = 136,  //!< Generates the specified waveform with given attributes.
   _FTM_SET_CALIBRATION_STATE  = 137,  //!<! Set the calibration state to active or inactive
   _FTM_GET_THERM = 138, //!<! Read back thermistor value
   _FTM_GET_AGC_RESOLUTION_TX   = 139,   //!<! Get Tx AGC Resolution Information
   _FTM_GET_AGC_RESOLUTION_RX   = 140,   //!<! Get Rx AGC Resolution Information
   _FTM_SELECT_RX_ANTENNA = 141,        //!<' Select the antenna source for 2nd receiver for FTS
   _FTM_GET_ENH_THERM = 142,//!<! Read back 32bit thermistor value
   _FTM_DO_IQ_MISMATCH_CAL = 143, //!<! Receiver IQ mismatch calibration
   _FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL_V2=144,  //!< Return all of the HDET values measured in the last TX SWEEP
   _FTM_DO_ICI_CAL = 145, //!<! Receiver ICI calibration
   _FTM_DO_WCDMA_IQ_LOGGING = 184, //!<' WCDMA IQ data logging command
   _FTM_SET_BLOCK_MASK = 153, //!< Sets the block mask and NV Block table for the RF Mode set in the SET_MODE command
   _FTM_DO_ENH_XO_DC_CAL = 154, //!<' Coarse DC frequency calibration for ENH XO targets
   _FTM_DO_ENH_XO_FT_CURVE_CAL = 155,   //!<' Fine DC frequency and FT Curve Calibration for ENH XO targets
   _FTM_DO_ENH_XO_FT_COLLECT_SAMPLE = 156,  //!<' Collect Sample
   _FTM_DO_ENH_XO_DC_CAL_V2 = 157,  //!<' Coarse DC frequency calibration for ENH XO targets - improved logging
   _FTM_DO_ENH_XO_FT_CURVE_CAL_V2 = 158,    //!<' Fine DC frequency and FT Curve Calibration for ENH XO targets - improved logging
   _FTM_DO_ENH_XO_FT_COLLECT_SAMPLE_V2 = 159,   //!<' Collect Sample - improved logging
   _FTM_ENABLE_LPM_HDET = 161,
   _FTM_GET_LPM_HDET_FROM_TX_SWEEP_CAL=162,
   _FTM_GET_ALL_LPM_HDET_FROM_TX_SWEEP_CAL=163,
   _FTM_SAR_POWER_LIMIT_SIMULATION = 164,//!<' FTM SV command
   _FTM_GET_UNIFIED_ENH_THERM = 165,   //!<' Generic command to get Therm read for a given tech on a device
   _FTM_TRIGGER_EPT_IQ_CAP = 169, //!<' Trigger EPT IQ Capture
   _FTM_CONFIG_EUL_WAVEFORM  = 170, //!<' FTM RF command to configure EUL tx waveform
   _FTM_DISABLE_EUL_WAVEFORM = 172, //!<' FTM RF command to disable EUL tx waveform, restores to R99 waveform
   _FTM_WCDMA_SET_TXAGC = 173, //!<' FTM RF command to program the PA range, LUT index and Digital Gain to reach programmed TxAGC
   _FTM_WCDMA_TXAGC_SWEEP = 174, //!<' FTM RF command to perform TxAGC sweep
   _FTM_SWITCH_TX_ANT = 175, /* FTM Command to switch to the Div. Tx Chain*/
   _FTM_SET_TX_POWER_DBM = 176,  //!<' FTM RF command to program the PA range, LUT index and Digital Gain to reach programmed Tx Power Level
   _FTM_LTE_SET_NET_SIG_VALUE = 177, //!<' FTM RF command that configures additional LTE parameters for the FTM_SET_TX_POWER_DBM  function
   _FTM_GET_RX_LEVEL_DBM = 179,  //!<' FTM RF command to get Rx Level in dbm10 and Raw AGC Value
   _FTM_WCDMA_GET_RX_LEVEL_DBM_X2W_MEAS = 935,  //!<' FTM RF command to get Rx Level in dbm10 and Raw AGC Value for WCDMA in X2W IRAT scenarios
   _FTM_SET_OFFSET_CW = 180,  //!<' Generates Offset CW Tone at given frequency
   _FTM_SET_PA_STATE = 182, //!< Sets PA range
   _FTM_LTE_SET_LNA_STATE_DBM = 185, //!< Sets the Rx LNA range based on a target dBm downlink level
   _FTM_SET_FREQ_ADJUST = 186, //!< Adjusts the Tx and Rx frequency
   _FTM_LTE_SET_TDD_PARAMS = 187, //!< Sets and TDD UL-DL cnfiguration and specifies on what subframes UE will transmit
   _FTM_GET_MULTIPLE_RX_LEVEL_DBM = 187,  //!<' FTM RF command to get Rx Level in dbm10 and Raw AGC Value
   _FTM_GET_ET_PATH_DELAY = 188, //!<' Command to get the ET path delay computed by the firmware
   _FTM_SET_TX_ENH_CAL_ACTION   = 190, //!<' Sets enhanced cal actions for transmitter
   _FTM_LOAD_TX_LINEARIZER_CAL_DATA = 191, //!<' Loads the Tx linearizer calibration data for a given band
   _FTM_LOAD_TX_FREQCOMP_CAL_DATA = 192, //!<' Loads Tx Freq comp Cal data for a given band
   _FTM_SET_PWR_OPTIMIZATION_MODE = 193, //!<' Sets the QPOET power optimization mode
   _FTM_LOAD_DPD_TBLS           = 197, //!<' Load DPD tables
   _FTM_SET_SAPT_STATE          = 198, //!<' Set SAPT state
   _FTM_SET_PA_PROFILE          = 212,
   _FTM_CONF_MODULATE_DATA      = 215,
   _FTM_SET_TRANSMIT_CONT       = 216,
   _FTM_SET_TRANSMIT_BURST      = 217,
   _FTM_SET_RX_BURST            = 225,
   _FTM_SET_TX_POWER_LEVEL      = 227,
   _FTM_GET_RSSI                = 230,
   _FTM_SET_PA_START_DELTA      = 231,
   _FTM_SET_PA_STOP_DELTA       = 232,
   _FTM_SET_PA_DAC_INPUT        = 233,
   _FTM_SET_RX_CONTINUOUS       = 234,  //!< Set Rx continuous
   _FTM_SET_TX_CAL_SWEEP        = 235,  //!< Tx cal sweep
   _FTM_USE_FIXED_VECTOR        = 518,

   // GSM Polar Calibration
   _FTM_DO_GSM_AUTOCAL          = 236,  //!< Do autocal
   _FTM_SET_PATH_DELAY          = 237,  //!< Set the path delay for AMAM/AMPM
   _FTM_SET_AMAM_TABLE_GAIN     = 238,  //!< Set the gain for the AMAM table
   _FTM_SET_AMAM_TABLE_DC       = 239,  //!< Set the DC offset for the AMAM table
   _FTM_SET_TX_FRAME_MATRIX     = 240,  //!< Set the TX frame matrix
   _FTM_ENABLE_POLAR_REF_CAL    = 241,  //!< Enable polar path reference calibration
   _FTM_SET_TWOTONE_FREQ_OFFSET = 242,   //!< Sets the frequency offset for the two tone transmit
   _FTM_DO_CALPATH_RSB          = 243,  //!< Measure calpath RSB
   _FTM_DO_RTR6250_RSB          = 244,  //!< Load VI firmware for RSB
   _FTM_SET_OPLL_BW             = 245,  //!< set Chargepump current registers
   _FTM_RX_GAIN_RANGE_CAL       = 246,  //!< GSM Rx Gain Range Calibration (multiple gain states in one command)
   _FTM_GSM_SET_LINEAR_RGI      = 247,  //!< GSM Set Linear RF Gain Index

   _FTM_BASEBAND_BW_CAL     = 250,  //!< Baseband Bandwidth calibration
   _FTM_TX_KV_CAL                   = 251,  //!< Kvco Calibration
   _FTM_SET_GSM_LINEAR_PA_RANGE = 252, //!< GSM PA Range
   _FTM_GNSS_EXTERNAL_LNA         = 253, //!< GNSS External LNA
   _FTM_TX_KV_CAL_V2              = 254,  //!< Kvco Calibration V2

   // EGPRS non-signaling Command ID's
   _FTM_EGPRS_BER_START_GPRS_IDLE_MODE_REQ = 256,   //!< EGPRS - Idle mode request
   _FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK    = 257,  //!< EGPRS - establish SRB loopback
   _FTM_EGPRS_BER_CONFIGURE_DL_TBF          = 258,  //!< EGPRS - configure DL temporary block flow
   _FTM_EGPRS_BER_CONFIGURE_UL_TBF          = 259,  //!< EGPRS - configure UL temporary block flow
   _FTM_EGPRS_BER_RELEASE_ALL_TBF           = 260,  //!< EGPRS - release all TBF
   _FTM_EGPRS_BER_RELEASE_UL_TBF            = 261,  //!< EGPRS - release all UL TBF
   _FTM_EGPRS_BER_CONFIGURE_DL_TBF_V2           = 262,  //!< EGPRS - configure DL temporary block flow V2
   _FTM_EGPRS_BER_CONFIGURE_UL_TBF_V2           = 263,  //!< EGPRS - configure UL temporary block flow V2
   _FTM_EGPRS_BER_EXEC_VFS_REQ               = 264,   //!< EGPRS - execute VFS
   _FTM_EGPRS_BER_EVENT_STATUS_CLEAR_REQ     = 266,  //!<EGPRS - Clear event satus
   _FTM_EGPRS_BER_EVENT_STATUS_REQ           = 267,  //!<EGPRS - Wait for event satus

   // GSM Diversiy Rx Command ID's
   _FTM_GET_GSM_PRX_DRX_RSSI      = 268,  //!< GSM Rx Gain Range for PRx and DRx -> Fetch the RSSI results
   _FTM_RX_GAIN_RANGE_PRX_DRX_CAL = 269,  //!< GSM Rx Gain Range Calibration for PRx and DRx (multiple gain states in one command)

   // WCDMA HSDPA command ID's
   _FTM_HSDPA_BLER_CMD_START_HS         = 256,  //!< HSDPA -
   _FTM_HSDPA_BLER_CMD_STOP_HS              = 257,  //!< HSDPA -
   _FTM_HSDPA_BLER_CMD_RECONFIG_HS          = 258,  //!< HSDPA -
   _FTM_HSDPA_BLER_CMD_CONFIG_HS_PDSCH      = 259,  //!< HSDPA -
   _FTM_HSDPA_BLER_CMD_CONFIG_HS_SCCH       = 260,  //!< HSDPA -
   _FTM_HSDPA_BLER_CMD_CONFIG_HS_DSCH       = 261,  //!< HSDPA -
   _FTM_HSDPA_BLER_CMD_CONFIG_HS_DPCCH      = 262,  //!< HSDPA -
   _FTM_HSDPA_BLER_EVENT_STATUS_CLEAR_REQ   = 263,  //!< HSDPA - Clear BER Event Status
   _FTM_HSDPA_BLER_EVENT_STATUS_REQ         = 264,  //!< HSDPA - Get BER Event Status

   /* FTM GSM Extended Command IDs */
   _FTM_GSM_POLAR_TX_SWEEP_CAL = 300,       //!< FTM GSM TX Sweep calibration
   _FTM_TX_RSB_DC_SWEEP        = 301,       //!< GSM Tx RSB DC Sweep calibration
   _FTM_GSM_TX_DETECTOR_CAL    = 302,       //!< GSM Tx Detector Cal
   _FTM_GSM_TX_4X_FMOD_SWEEP   = 303,       //!< GSM Sweep Tx 4xFMod calibration
   _FTM_TX_CS_SWEEP            = 304,       //!< GSM Tx CS Sweep calibration

   _FTM_GSM_TX_ENVDC_CS_SWEEP    = 308,     //!< GSM Envelope DC Carrier Suppression Sweep
   _FTM_TX_CFG2_AMAM_SWEEP       = 309,     //!< EDGE Tx Predistortion Calibration
   _FTM_GSM_TX_GAIN_SWEEP        = 310,     //!< GSM Tx DA Calibration
   _FTM_GSM_RX_FREQ_CAL_SWEEP    = 311,     //!< GSM Rx Frequency measurement
   _FTM_GSM_GET_ENV_GAIN_NV_DATA = 860,     //!< GSM FTM_GSM_GET_ENV_GAIN_NV_DATA structure
   _FTM_GSM_V4_CAL_SWEEP         = 864,     //!< GSM V4 calibration sweep command
   _FTM_GSM_V4_CAL_EXEC          = 865,     //!< GSM V4 calibration sweep execution command
   _FTM_GSM_V4_GET_RESULTS       = 866,     //!< GSM V4 calibration sweep --> obtain results from the phone
   _FTM_GSM_V4_CLEANUP           = 867,     //!< GSM V4 calibration sweep --> cleanup data on embedded side
   _FTM_GSM_V4_DISABLE_PREDIST   = 249,     //!< GSM V4 calibration sweep --> disable predistortion for GSM sweep
   _FTM_GSM_SET_PA_BIAS_NV       = 930,     //!< GSM SET PA BIAS NV-->  FTM command Load Rgi vs Icq, PCl vs Vcc and Rgi vs Vcc information to the phone
   _FTM_GSM_SET_ALT_PATH         = 335,     //!< enabled/disables the overwriting of the alternate path in GSM. Also specifies what path to use.
   _FTM_GSM_GET_NV_CONTAINER     = 336,     //!< GSM get NV container for whith to write NV data --> used for alternate path calibration
   _FTM_GSM_SET_DEVICE_AND_SIG_PATH  = 346, //!< GSM set device and signal path
   _FTM_GSM_FBRX_CAL             = 981,     //!< GSM FBRx Calibration
   _FTM_GSM_SET_ASDIV_PATH       = 348,     //!< GSM Set ASDIV Path

   /* FTM IRAT */
   _FTM_MEAS_GTOW_TEST_WCDMA = 319,
   _FTM_MEAS_GTOW_TEST_GSM = 320,
   _FTM_MEAS_WTOG_TEST_GSM = 321,
   _FTM_MEAS_WTOG_TEST_WCDMA = 322,

   _FTM_GSM_RSSI_TO_DB = 323,
   _FTM_TX_CFG2_AMAM_SWEEP_V2 = 324,            //!< EDGE Tx Predistortion Calibration V2

   _FTM_DO_SELF_CAL = 325,                //!< DO SELF CAL

   _FTM_MEAS_XTOY_TEST_Y = 326,                    //!LTE interRAT commands
   _FTM_MEAS_XTOY_TEST_X = 327,                    //!LTE interRAT commands
   _FTM_MEAS_NULL2X_SCRIPT_START = 337,            //!LTE interRAT : NULL2X start
   _FTM_MEAS_NULL2X_SCRIPT_EXIT = 338,             //!LTE interRAT : NULL2X exit
   _FTM_MEAS_HALF_SCRIPT_FH_TO_FX = 339,           //!LTE interRAT : Home Freq to Neighbour X
   _FTM_MEAS_HALF_SCRIPT_FH_TO_FY = 340,           //!LTE interRAT : Home Freq to Neighbour Ycommands
   _FTM_MEAS_HALF_SCRIPT_FX_TO_FY = 341,           //!LTE interRAT : Neighbour X to Neighbour Y
   _FTM_MEAS_HALF_SCRIPT_FX_TO_FH = 342,           //!LTE interRAT : Neighbour X to Home Freq
   _FTM_MEAS_HALF_SCRIPT_FY_TO_FX = 343,           //!LTE interRAT : Neighbour Y to Neighbour X
   _FTM_MEAS_HALF_SCRIPT_FY_TO_FH = 344,           //!LTE interRAT : Neighbour Y to Home Freq
   _FTM_MEAS_GET_RXAGC = 345,                      //!LTE interRAT : Command to get RXAGC during FTM IRAT

   _FTM_GSM_SETUP_RX_BURST_FOR_EXPECTED_PWR = 329, //!< GSM FTM RF Command
   _FTM_GSM_GET_MEAS_PWR = 330,                 //!< GSM FTM RF Command
   _FTM_GSM_GET_MEAS_PWR_DRX = 333,                 //!< GSM FTM RF Command

   _FTM_SET_WCDMA_SECONDARY_CHAIN = 121,    //!< Enable/disable secondary Rx

   /*LTE Command IDs*/
   _FTM_SET_TX_BANDWIDTH = 400,
   _FTM_SET_RX_BANDWIDTH,
   _FTM_SET_TX_GAIN_INDEX,
   _FTM_SET_LTE_WAVEFORM,
   _FTM_STOP_LTE_WAVEFORM,

   _FTM_LTE_SET_TX_CARRIER_INDEX = 425,

   _FTM_LTE_SET_MODULATION_TYPE = 512,          // Set modulation type for LTE
   _FTM_LTE_GET_RXAGC_DATA = 516,               // Get RXAGC data from multiple rx chains
   _FTM_LTE_RFFE_DEVICE_STATUS_UPDATE = 527,    //!<' LTE Device Status Update API
   _FTM_SET_PATH_SEL_OVERRIDE_INDEX = 528,                // API to override the path selection
   _FTM_SET_DEVICE_PATH = 530,

   _FTM_LTE_CONFIG_DECONFIG_RX_CHAIN = 533, //Config LTE Rx Chaindiversity
   _FTM_LTE_SET_DEVICES = 538, //LTE Device Alloc
   _FTM_LTE_GET_HORXD_BAND_SUPPORT_STATUS = 540, // HORXD_BAND_SUPPORT_STATUS

   /*Dual Carrier Related Command IDs*/
   _FTM_GET_CAGC_DUAL_CARRIER_RX_AGC = 600, //'< for carrier 1 in dual carrier mode
   _FTM_SET_DUAL_CARRIER_DVGA_OFFSET = 601, //'< for carrier 1 in dual carrier mode
   _FTM_GET_DUAL_CARRIER_DVGA_OFFSET = 602, //'< for carrier 1 in dual carrier mode
   _FTM_SET_MULTI_CHAN = 603,
   _FTM_DO_ICI_CAL_MULTI_CARRIER = 606,

   /* FTM RF Command */
   _FTM_RFNV_READ       = 604,              //'< Read NV item via FTM API
   _FTM_RFNV_WRITE      = 605,                          //'< Write NV item via FTM API

   _FTM_CFG_AND_EXEC_CAL_SWEEP = 608,        //'< Configure and Start the Calibration Sweep
   _FTM_GET_CAL_SWEEP_RESULTS = 609,         //'< Fetch cal sweep results
   _FTM_ANT_TUNER_OVERWRITE_CMD = 610,       //'< FTM Antenna Tuner override (3rd ant tunner)
   _FTM_RX_WAIT_DBM = 611,                   //'< FTM Sequencer waits till the RX power reaches a given trigger level
   _FTM_SET_MULTI_CARRIER_TX = 612,          // To enable or disable DC-HSUPA waveform.
   _FTM_RF_MODE_EXIT  = 614,                 //'< Forces RF driver to disable any activities and exit the current mode

   _FTM_DO_TX_INTERNAL_CAL = 621,    //'< Perform Tx Internal Device Calibration
   _FTM_RFFE_MULTIBYTE_READWRITE  = 622,       //'< Multi Byte RF Front End (RFFE) Read/Write command
   _FTM_RFFE_READWRITE  = 623,                 //'< Single Byte RF Front End (RFFE) Read/Write command

   _FTM_XO_CALIBRATION = 624, //'< XO Cal command

   _FTM_SET_XPT_TXAGC_OVERRIDE = 625,
   _FTM_XPT_MLINE_COMPUTE = 626,
   _FTM_DO_RSB_TXLO_CAL = 627,
   _FTM_SET_XPT_CAL_CONFIG = 629,
   _FTM_RFNV_READ_V2 = 631,                 //'< Read large NV item via FTM API
   _FTM_RFNV_WRITE_V2 = 632,                //'< Write large NV item via FTM API
   _FTM_RFNV_GET_MAX_TRANSFER_SIZE = 633,   //'< Get maximum diag buffer transfer size
   _FTM_RX_WAIT_DBM_V2 = 634,               /*!< FTM Sequencer waits till the RX power reaches a given trigger level in a given direction */
   _FTM_CALIBRATION_SWEEP_COMPRESSED = 635, //'< Calibration Sweep - Compressed Command
   _FTM_RF_GET_TXLUT_INFO_FOR_RED_CAL = 652, // Get TXLUT for Reduced RGI CAL.
   _FTM_GET_STATIC_INFO = 653,               //Get the switch points from the PA static NV
   _FTM_RF_LTE_NLIC_ON_OFF = 654,            // API to configure NLIC params.
   _FTM_GET_RF_PATH_INFORMATION = 655,       /*!< Get RF Path Information */
   _FTM_STG_COMMON_CONTROL = 657, //Enable/Disable the STG

   _FTM_NLIC_CHAR_PARAMS_OVERRIDE = 658,
   _FTM_NLIC_CHAR_GET_MEAS_RESULTS = 659,
   _FTM_NLIC_CHAR_MODE_ENTER = 662,
   _FTM_LTE_RF_CONFIG = 694,

   /*TDSCDMA cmds, owns 700 to 799*/
   _FTM_TDSCDMA_SET_TXAGC = 700,
   _FTM_TDSCDMA_TXAGC_SWEEP = 701,
   _FTM_TDSCDMA_TPC_CONTROL = 702,
   _FTM_TDSCDMA_IQ_LOGGING = 703,
   _FTM_TDSCDMA_SET_TX_CONTINOUS = 704,
   _FTM_TDSCDMA_SET_BURST_TX_PARAMS = 712,
   _FTM_TDSCDMA_BURST_TX = 713,
   _FTM_TDSCDMA_BURST_RX = 714,
   _FTM_TDSCDMA_SWITCH_TX_WAVEFORM = 715,
   _FTM_DO_FBRX_RSB_CAL = 718,
   _FTM_TDSCDMA_TRIGGER_PORT_SWITCH = 720,   //!<' TDS-CDMA Device Status Update API

   _FTM_SET_TUNER_PROGRAM_SCENARIO = 849,
   _FTM_SET_TUNER_SCENARIO_OVERRIDE = 850,
   _FTM_SET_TUNER_TUNE_CODE_OVERRIDE   = 861,
   _FTM_GET_RFFE_DEVICE_INFO = 863,
   _FTM_DO_TUNER_SELF_CAL = 904,
   _FTM_TUNER_RL_CMD = 905,
   _FTM_RFFE_GET_DEVICE_SETTING = 936,
   _FTM_PROGRAM_TUNER = 1001,
   _FTM_GET_TUNER_STATUS = 1003,

   /*IQ Capture commands owns 900-915 and 947-948*/
   _FTM_IQ_CAPTURE_GET_CONFIG = 900,            //!<' Get key parameters for IQ capture
   _FTM_IQ_CAPTURE_ACQUIRE_SAMPLES = 901,       //!<' Acquire one set of IQ samples
   _FTM_IQ_CAPTURE_GET_SAMPLES = 902,           //!<' Read acquired IQ samples via FTM API
   _FTM_IQ_CAPTURE_ACQUIRE_PRXDRX_SAMPLES = 947,//!<' Acquire one set of IQ samples for simultaneous PRx DRx capture
   _FTM_IQ_CAPTURE_GET_PRXDRX_SAMPLES = 948,    //!<' Read acquired IQ samples via FTM API for simultaneous PRx DRx capture
   _FTM_IQ_CAPTURE_ANALYZE_SAMPLES = 903,       //!<' Analyze acquired IQ data
   _FTM_GSM_CAPTURE_IQ  = 11,                   //!<' Configure the GSM IQ capture mode

   _FTM_LTE_CONFIG_TX_RX = 910,
   /*FTM RF FBRx commands*/
   _FTM_RF_MEAS_TX_PARAMS = 911,
   _FTM_RF_MEAS_FBRX_NOISE = 912,
   _FTM_FBRX_IQ_CAPTURE_TRIGGER = 913,
   _FTM_FBRX_IQ_CAPTURE_GET_SAMPLES = 914,
   _FTM_FBRX_SINGLE_TRIGGER = 646,
   _FTM_FBRX_DEBUG_SAMPLE_CAPTURES = 654,

   _FTM_DO_ENH_INTERNAL_DEVICE_CAL=649,
   _FTM_FEEDBACK_SETUP =931,

   _FTM_TXRX_AGC_RELOAD = 937, //!<' 1x AGC Reload
   _FTM_RF_SET_SELFTEST_MODE = 938,
   _FTM_SET_DCOC_VAL = 939,
   _FTM_WRITE_DCOC_VAL = 942,
   _FTM_RFFE_GET_DEVICE_IDS = 949,
   _FTM_DRDS_RECONFIG_ENABLE = 950,
   _FTM_TUNER_GET_TUNE_CODE = 953,
   _FTM_DEVICE_MANAGER_MODE = 954,
   _FTM_COMMON_PRINT_MESSAGE = 969,
   _FTM_GET_ESC_SWEEP_RESULTS_COMPRESSED = 970,
   _FTM_QLNK_SELF_TEST = 972,
   _FTM_QLNK_WARM_START = 974,
   _FTM_QLNK_HIBERNATE = 975,
   _FTM_QLNK_PING_TEST = 976,
   _FTM_QLNK_REG_RW = 977,
   _FTM_QLNK_BER_TEST = 978,
   _FTM_QLNK_WTR_RW = 979,
   _FTM_QLNK_DO_WTR_SCRIPT = 980,

   _FTM_SELFTEST_SET_FBRX_STATE = 982,

   _FTM_GET_RFFE_DEVICE_INFO_V2 = 1000,

   _FTM_GET_UNIFIED_ENH_THERM_V2 = 1002,

   _FTM_ASSIGN_RADIO_ALLOCATION = 1004,

   _FTM_FEM_COMMON_DISPATCH = 1005,

   _FTM_GET_HW_INDEX = 1006,

   _FTM_SET_TRM_ANT_PORT_STATE = 1019,

   _FTM_GET_TRM_ANT_PORT_STATE = 1020,

   _FTM_DIAG_CMD_ID_MAX
} FTM_Command_ID_Type;

typedef enum
{
   _FTM_RF_TEST_CMD_UNASSIGNED = 0, /*!< 0 : Unassigned command */

   _FTM_RF_TEST_CMD_RADIO_CONFIGURE = 1, /*!< 1 : Radio Configure command */

   _FTM_RF_TEST_CMD_RX_MEASURE = 2, /*!< 2 : Rx Measure command */

   _FTM_RF_TEST_CMD_TX_CONTROL = 3, /*!< 3 : Tx Control command */

   _FTM_RF_TEST_CMD_QUERY_RECOMMENDED_RADIO_ALLOCATION = 4, /*!< 4 : Query RF path command */

   _FTM_RF_TEST_CMD_IQ_CAPTURE = 6,  /*!< 6 : IQ Capture command */

   _FTM_RF_TEST_CMD_TX_MEASURE = 7,  /*!< 7 : Tx Measure command */

   _FTM_RF_TEST_CMD_MSIM_CONFIG = 8,  /*!< 8 : Multi SIM Config command */

   _FTM_RF_TEST_CMD_IRAT_CONFIG = 9,   /*!< 9 : IRAT Config command */

   _FTM_RF_TEST_CMD_NUM  /*!< Max : Defines maximum number of command IDs */
} FTM_RF_TEST_Command_Enum_Type;

typedef enum
{
   _FTM_RF_ANT_TUNER_RESERVED = 0, /*!< 0 : Reserved */

   _FTM_RF_ANT_TUNER_SET_TUNER_PROPERTIES = 1, /*!< 1 : Set Tuner Properties command */

   _FTM_RF_ANT_TUNER_GET_TUNER_STATUS = 2, /*!< 2 : Get Tuner Status command */

   _FTM_RF_ANT_TUNER_CMD_NUM  /*!< Max : Defines maximum number of command IDs */
} FTM_RF_ANT_TUNER_Command_Enum_Type;

/******************************************************************************
FTM - System Modes
*******************************************************************************/

/**
\brief Enumeration of FTM Mode ID's, to be used int the "mode_id" field of the
FTM header
*/
typedef enum
{
   FTM_MODE_ID_CDMA_1X    = 0,    //!<' RF CDMA 1X mode - RX0
   FTM_MODE_ID_WCDMA      = 1,    //!<' RF WCDMA mode
   FTM_MODE_ID_GSM            = 2,     //!<' RF GSM Mode (chain 0)
   FTM_MODE_ID_CDMA_1X_RX1  = 3,    //!<' RF CDMA 1X mode - RX1
   FTM_MODE_ID_BLUETOOTH  = 4,    //!<' Bluetooth
   FTM_MODE_ID_CDMA_1X_CALL = 7,   //!<' CALL CDMA 1X mode
   FTM_MODE_ID_HDR_C      = 8,    //!<' HDC non signaling
   FTM_MODE_ID_LOGGING    = 9,    //!<' FTM Logging
   FTM_MODE_ID_AGPS       = 10,   //!<' Async GPS
   FTM_MODE_ID_PMIC       = 11,   //!<' PMIC FTM Command
   FTM_MODE_GSM_BER           = 13,    //!<' GSM BER (chain 0)
   FTM_MODE_ID_AUDIO      = 14,   //!<' Audio FTM
   FTM_MODE_ID_CAMERA     = 15,   //!<' Camera
   FTM_MODE_WCDMA_BER     = 16,   //!<' WCDMA BER
   FTM_MODE_ID_GSM_EXTENDED_C = 17,    //!<' GSM Extended commands (chain 0)
   FTM_MODE_CDMA_API_V2   = 18,   //!<' CDMA RF Cal API v2
   FTM_MODE_ID_MF_C       = 19,   //!<' MediaFLO
   FTM_MODE_RF_COMMON     = 20,   //!<' RF Common
   FTM_MODE_WCDMA_RX1     = 21,   //!<' WCDMA diversity RX (RX1)
   FTM_MODE_WLAN          = 22,   //!<' WLAN FTM
   FTM_MODE_QFUSE         = 24,   //!<' QFUSE FTM
   FTM_MODE_ID_MF_NS      = 26,   //!<' MediaFLO NS FTM
   FTM_MODE_GPS           = 28,   //!<' GPS FTM (Note: FTM_MODE_GPS = 28 is never in any commerical AMSS SW)
   FTM_MODE_FMRDS         = 28,   //!<' Frequency Modulation (FM) Radio FTM
   FTM_MODE_ID_LTE        = 29,       //!<' LTE FTM Calibration
   FTM_MODE_LTE_NS        = 30,       //!<' LTE FTM Non-Signaling
   FTM_MODE_ID_CDMA_1X_C2 = 32,       //!<' CDMA SV Path mode - Chain 2
   FTM_MODE_IRAT          = 33,       //!<' FTM IRAT
   FTM_MODE_ID_DVBH       = 240,    //!<' DVB-H Diag
   FTM_MODE_ID_ISDBT      = 240,    //!<' ISDB-T Diag
   FTM_MODE_ID_MBP        = 241,    //!<' MBP RF Diag
   FTM_MODE_SE_BER        = 27,   //!<' FTM SE BER
   FTM_MODE_GNSS_RF       = 34,   //!<' GNSS FTM RF
   FTM_MODE_LTE_RX1       = 35,       //!<' LTE FTM Calibration Diversity
   FTM_MODE_RFNV          = 36,   //!<' FTM RF NV
   FTM_MODE_SEQUENCER     = 37,   //!<' FTM Sequencer
   FTM_MODE_SV            = 38, //!<' FTM Simultaneous Voice
   FTM_MODE_RFM_C         = 39, //!<' FTM_RFM_C
   FTM_MODE_ID_1X_C3_C        = 40,   //!<' FTM_1X_C3_C
   FTM_MODE_ID_RFCA_MAL_C     = 41,   //!<' FTM_RFCA_MAL_C
   FTM_MODE_ID_TDSCDMA        = 42,  //!<' FTM_MODE_ID_TDSCDMA
   FTM_MODE_ID_TDSCDMA_RX1    = 43,   //!<' FTM_MODE_ID_TDSCDMA_RX1
   FTM_MODE_ID_TDSCDMA_BER    = 44,   //!<' FTM_MODE_ID_TDSCDMA_BER
   FTM_MODE_ID_1X_C4_C        = 45,   //!<' FTM_1X_C4_C
   FTM_MODE_ID_1X_C5_C        = 118,   //!<' FTM_1X_C5_C
   FTM_MODE_ID_LTE_C3         = 47,    //!<' LTE Mode ID for SCell Primary
   FTM_MODE_ID_LTE_C4         = 48,    //!<' LTE Mode ID for SCell Secondary

   FTM_MODE_ID_GSM_C2          = 49,    //!<' FTM_GSM_C2_C (chain 2)
   FTM_MODE_ID_GSM_EXTENDED_C2 = 50,    //!<' FTM_GSM_EXTENDED_C2_C (chain 2)
   FTM_MODE_ID_GSM_BER_C2      = 51,    //!<' FTM_GSM_BER_C2_C (chain 2)
   FTM_MODE_ID_FTM_AP          = 52,    // !<' FTM AP (Linux MMI Application)
   FTM_MODE_ID_FFBM            = 53,    // !<' FTM AP , FFBM/HLOS mode switching
   FTM_MODE_ID_NFC             = 55,    //!<' FTM NFC
   FTM_MODE_WCDMA_RX3_C          = 56,    //!<' WCDMA Chain 3
   FTM_MODE_WCDMA_RX4_C          = 57,    //!<' WCDMA Chain 4
   FTM_MODE_ID_GSM_C1            = 58,    //!<' GSM Chain 1
   FTM_MODE_WP_C              = 64,    //!<' Interface between Factory tool and MMI app used in factory test mode to do device provisioning, fuses status checking and device locking, and so on. Commands are functional for Windows phone target only
   FTM_MODE_ID_LTE_C5         = 65,     //!<' LTE Mode ID for SCell2 Primary
   FTM_MODE_ID_LTE_C6         = 66,     //!<' LTE Mode ID for SCell2 Diversity
   FTM_MODE_ID_LTE_SET_DEVICES = 67,   //!<' LTE Mode ID for set devices
   FTM_MODE_WCDMA_RX5_C       = 68,    //!<' WCDMA Chain 5
   FTM_MODE_WCDMA_RX6_C       = 69,    //!<' WCDMA Chain 6
   FTM_MODE_WCDMA_RX7_C       = 70,    //!<' WCDMA Chain 7
   FTM_MODE_WCDMA_RX8_C       = 71,    //!<' WCDMA Chain 8
   FTM_MODE_ID_ANT            = 94,     //!<' ANT FTM, dispatched on AP side
   FTM_MODE_ID_HDR_C0         = 95,     //!<' HDR C0
   FTM_MODE_ID_HDR_C1         = 96,     //!<' HDR C1
   FTM_MODE_ID_HDR_C2         = 97,     //!<' HDR C2
   FTM_MODE_ID_HDR_C3         = 98,     //!<' HDR C3
   FTM_TDSCDMA_C2_C      = 99,      //!<' TDSCDMA C2
   FTM_TDSCDMA_C3_C      = 100,     //!<' TDSCDMA C3
   FTM_MODE_ID_GSM_C4          = 101,
   FTM_MODE_ID_GSM_EXTENDED_C4 = 103,
   FTM_MODE_FTM_RF_TEST = 105,            //!<' FTM-RF TEST SUBSYSTEM
   FTM_MODE_FTM_RF_ANT_TUNER = 121,       //! FTM RF Antenna Tuner
   FTM_MODE_ID_SECURITY_ID_SENSOR    = 255,     //!<' SECURITY ID SENSOR
   FTM_MODE_WIGIG          = 256,      //!<' WIGIG FTM (802.11ad 60GHz)
   FTM_MODE_ID_PRODUCTION = 0x8000, //!<' Production FTM
   FTM_MODE_ID_LTM        = 0x8001  //!<' LTM
} FTM_Mode_Id_Enum;

/******************************************************************************
FTM - RF Modes
*******************************************************************************/

/**
\brief Enumeration of RF Mode ID's, from services\ftm\ftm.h
*/
typedef enum
{
   PHONE_MODE_FM=1,             //!<' FM
   PHONE_MODE_SLEEP=2,              //!<' Sleep Mode
   PHONE_MODE_GPS=3,                //!<' GPS
   PHONE_MODE_GPS_SINAD=4,          //!<' GPS SINAD
   PHONE_MODE_CDMA_800=5,           //!<' CDMA 800
   PHONE_MODE_CDMA_1900=6,          //!<' CDMA 1900
   PHONE_MODE_CDMA_1800=8,          //!<' CDMA 1800
   PHONE_MODE_J_CDMA=14,            //!<' JCDMA
   PHONE_MODE_CDMA_450=17,          //!<' CDMA 450
   PHONE_MODE_CDMA_IMT=19,          //!<' CDMA IMT
   PHONE_MODE_CDMA_1900_EXT=26, //!<' Secndary CDMA 1900MHz Band, Band Class 14
   PHONE_MODE_CDMA_450_EXT=27,      //!<' CDMA BC 11 (450 Extension)
   PHONE_MODE_CDMA_800_SEC=33,      //!<' Secondary CDMA 800MHz Band, Band Class 10

   PHONE_MODE_WCDMA_IMT=9,          //!<' WCDMA IMT, Band I
   PHONE_MODE_GSM_900=10,           //!<' GSM 900
   PHONE_MODE_GSM_1800=11,          //!<' GSM 1800
   PHONE_MODE_GSM_1900=12,          //!<' GSM 1900
   PHONE_MODE_BLUETOOTH=13,     //!<' Bluetooth
   PHONE_MODE_WCDMA_1900A=15,       //!<' WCDMA 1900 A, Band II Add
   PHONE_MODE_WCDMA_1900B=16,       //!<' WCDMA 1900 B, Band II Gen
   PHONE_MODE_GSM_850=18,           //!<' GSM 850
   PHONE_MODE_WCDMA_800=22,     //!<' WCDMA 800, Band V Gen
   PHONE_MODE_WCDMA_800A=23,        //!<' WCDMA 800, Band V Add
   PHONE_MODE_WCDMA_1800=25,        //!<' WCDMA 1800, Band III
   PHONE_MODE_WCDMA_BC4=28,     //!<' WCDMA BC4-used for both Band IV Gen and Band IV Add
   PHONE_MODE_WCDMA_BC8=29,     //!<' WCDMA BC8, Band VIII

   PHONE_MODE_MF_700=30,            //!<' MediaFLO
   PHONE_MODE_WCDMA_BC9=31,     //!<' WCDMA BC9 (1750MHz & 1845MHz), Band IX
   PHONE_MODE_CDMA_BC15=32,     //!<' CDMA Band Class 15
   PHONE_MODE_LTE_B1=34,            //!<' LTE Band Class 1
   PHONE_MODE_LTE_B7=35,            //!<' LTE Band Class 7
   PHONE_MODE_LTE_B4=42,            //!<' LTE Band Class 4
   PHONE_MODE_LTE_B11=41,           //!<' LTE Band Class 11
   PHONE_MODE_LTE_B13=36,       //!<' LTE Band Class 13
   PHONE_MODE_LTE_B17=37,       //!<' LTE Band Class 17
   PHONE_MODE_LTE_B38=38,       //!<' LTE Band Class 38
   PHONE_MODE_LTE_B40=39,       //!<' LTE Band Class 40
   PHONE_MODE_WCDMA_1500=40,        //!<' WCDMA BC11 (1500MHz) Band XI

   PHONE_MODE_LTE_B2=43,
   PHONE_MODE_LTE_B3=44,
   PHONE_MODE_LTE_B5=45,
   PHONE_MODE_LTE_B6=46,
   PHONE_MODE_LTE_B8=47,
   PHONE_MODE_LTE_B9=48,
   PHONE_MODE_LTE_B10=49,
   PHONE_MODE_LTE_B12=50,
   PHONE_MODE_LTE_B14=51,
   PHONE_MODE_LTE_B15=52,
   PHONE_MODE_LTE_B16=53,
   PHONE_MODE_LTE_B18=54,
   PHONE_MODE_LTE_B19=55,
   PHONE_MODE_LTE_B20=56,
   PHONE_MODE_LTE_B21=57,
   PHONE_MODE_LTE_B22=58,
   PHONE_MODE_LTE_B23=59,
   PHONE_MODE_LTE_B24=60,
   PHONE_MODE_LTE_B25=61,
   PHONE_MODE_LTE_B26=62,
   PHONE_MODE_LTE_B27=63,
   PHONE_MODE_LTE_B28=64,
   PHONE_MODE_LTE_B29=65,
   PHONE_MODE_LTE_B30=66,
   PHONE_MODE_LTE_B31=67,
   PHONE_MODE_LTE_B32=68,
   PHONE_MODE_LTE_B33=69,
   PHONE_MODE_LTE_B34=70,
   PHONE_MODE_LTE_B35=71,
   PHONE_MODE_LTE_B36=72,
   PHONE_MODE_LTE_B37=73,
   PHONE_MODE_LTE_B39=74,

   PHONE_MODE_WCDMA_BC19=75,     //!<' WCDMA BC19 (subset of 800MHz) Band XIX
   PHONE_MODE_LTE_B41=76,
   PHONE_MODE_LTE_B42=77,
   PHONE_MODE_LTE_B39_B=78,
   PHONE_MODE_LTE_B45=79,

   PHONE_MODE_LTE_B252 = 80,
   PHONE_MODE_LTE_B255 = 82,
   PHONE_MODE_LTE_B66 = 83,
   PHONE_MODE_LTE_B43 = 88,
   PHONE_MODE_LTE_B46 = 89,

   /*TDSCDMA reserves 90 - 99*/
   PHONE_MODE_TDSCDMA_B34=90,
   PHONE_MODE_TDSCDMA_B39=91,
   PHONE_MODE_TDSCDMA_B40=92,

   // Connectivity (WLAN, NFC, FM Radio and WIGIG RF Modes are used for QDART NPT tool purposes only)
   PHONE_MODE_WLAN_2G=100,
   PHONE_MODE_WLAN_5G=101,

   PHONE_MODE_NFC=110,

   PHONE_MODE_FM_RADIO_US_EU = 115,
   PHONE_MODE_FM_RADIO_JAPAN = 116,
   PHONE_MODE_FM_RADIO_JAPAN_WIDE = 117,
   PHONE_MODE_FM_RADIO_USER_DEFINED = 118,

   PHONE_MODE_WIGIG = 120,
   /*
   QMSL Developers: please modify:
   - QLib.h  ->  QLIB_FTM_SET_MODE()
   - Diag_FTM.cpp  ->  Diag_FTM::FTM_SET_MODE()
   - QLIBFTMPhone.cpp when this list is changed.
   */
   PHONE_MODE_MAX=255               //!<' Maximum possible mode ID
} FTM_RF_Mode_Enum;

/*
The following are obsolete RF modes, or unused for Factory:

PHONE_MODE_FM=1,                //!<' AMPS
PHONE_MODE_CDMA=0,              //!<' Obsolete
PHONE_MODE_GPS_SINAD=4,         //!<' GPS SINAD (obsolete)
PHONE_MODE_CDMA_800=5,          //!<' cdma2000 BC0
PHONE_MODE_CDMA_1900=6,         //!<' cdma2000 BC1
PHONE_MODE_HDR=7,               //!<' HDR Call Test
PHONE_MODE_CDMA_1800=8,         //!<' cdma2000 1800MHz
PHONE_MODE_J_CDMA=14,           //!<' cdma2000 JCDMA
PHONE_MODE_CDMA_450=17,         //!<' cdma2000 BC4, 450MHz
PHONE_MODE_CDMA_IMT=19,         //!<' cdma2000 BC6, IMT band
*/
/******************************************************************************
FTM - FTM Tuner Tune Code Override Data Structure
*******************************************************************************/
/**
\brief FTM_Set_Tuner_Override_V0. This version 0 of Tuner Tune Code override data structure
*/
typedef struct
{
   unsigned char c1;       //!<' Capacitor 1 tune code.  Valid ranges are 0 to the max tune code supported by hardware
   unsigned char c2;       //!<' Capacitor 2 tune code.  Valid ranges are 0 to the max tune code supported by hardware
   unsigned char iSwitchConfiguration;    //!<'Bit Mask Controlling the state of all swiches in the tuner
} FTM_Set_Tuner_Override_V0;
/**
\brief FTM_Set_Tuner_NVData_V0. This version 0 of Tuner Tune Code NV Data structure
*/
typedef struct
{
   unsigned char cs1;      //!<' Code word 1
   unsigned char cs2;      //!<' Code word 2
} FTM_Set_Tuner_NVData_V0;
/******************************************************************************
FTM - RF Definitions
*******************************************************************************/

//! # of elements for the piHDETvalues parameter in QLIB_FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL
#define QLIB_FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL_ARRAY_SIZE 32

/******************************************************************************
FTM - GSM RF
*******************************************************************************/

#define FTM_GSM_TX_AGC_PACKET_VERSION 2
/**
\brief Enumeration of GSM Tx data sources for QLIB_FTM_SET_TRANSMIT_CONT
*/
typedef enum
{
   FTM_GSM_TX_DATA_SOURCE_PSDRND,       //!<' Pseudorandom
   FTM_GSM_TX_DATA_SOURCE_TONE,     //!<' Single tone
   FTM_GSM_TX_DATA_SOURCE_BUFFER,       //!<' Buffer
   FTM_GSM_TX_DATA_SOURCE_TWOTONE       //!<' 2 tone
} FTM_GSM_TX_DataSources_Enum;

/**
Maximum number of rows to be returned from the GSM Tx Polar Internal calibration log
*/
#define FTM_GSM_TX_POLAR_INTERNAL_AUTOCAL_MAX_DATA_ROWS 500

/**
\brief Enumeration of LNA states to be used for the iBitMask parameter of QLIB_FTM_RX_GAIN_RANGE_CAL()
*/
typedef enum
{
   FTM_GSM_RX_GAIN_RANGE_0  = 0x01, //!<' Gain range 0
   FTM_GSM_RX_GAIN_RANGE_1  = 0x02, //!<' Gain range 1
   FTM_GSM_RX_GAIN_RANGE_2  = 0x03, //!<' Gain range 2
   FTM_GSM_RX_GAIN_RANGE_3  = 0x04, //!<' Gain range 3
   FTM_GSM_RX_GAIN_RANGE_4  = 0x05  //!<' Gain range 4
} FTM_GSM_RX_GainRange_Enum;

typedef enum
{
   FTM_GSM_CAL_MOD_TYPE_GMSK = 0,

   FTM_GSM_CAL_MOD_TYPE_8PSK = 1,

   FTM_GSM_CAL_MOD_TYPE_ALL = 0xFFFF
} FTM_GSM_CAL_MOD_TYPE;

/**
Number of return values for the aiRSSI_Result array used in QLIB_FTM_RX_GAIN_RANGE_CAL()
*/
#define FTM_GSM_RX_GAIN_RANGE_CAL_NUM_RETURN_VALUES 8

/******************************************************************************
FTM - cdma2000 non-signaling log parser definitions
*******************************************************************************/

/**
Sub packet of RDA2 -- RDA_CHANNELS_INFO_TYPE / INDIVIDUAL_CHANNELS
*/
typedef union
{
   struct
   {
      byte RPICH    : 1;
      byte FCH  : 1;
      byte DCCH : 1;
      byte SCH0 : 1;
      byte SCCH : 3;
      byte reserved : 1;
   } individual_channels;
   byte mask;
} RDA_Channels_Info_Type;

/**
Sub packet of RDA2 -- CHAN_RC_TYPE
*/
typedef struct
{
   word FCH_rc;
   word DCCH_rc;
   word SCH_rc;
   word reserved0;
   word reserved1;
} Chan_RC;

/**
Sub packet of RDA2 -- FCH_RDA_SUB_RECORD_TYPE
*/
typedef struct
{
   dword reserved0;
   word  ser;
   byte  decision;      //!< Data rate, according to RDA_CDMA_TRAFFIC_DATA_RATE_TYPE
   byte  reserved1;
} FCH_RDA_Sub_Record_Type;

/**
Sub packet of RDA2 -- DCCH_RDA_SUB_RECORD_TYPE
*/
typedef struct
{
   dword reserved0;
   dword reserved1;
   word  reserved2;
   word  reserved3;
   word  ser;
   byte decision;       //!< Data rate, according to RDA_CDMA_TRAFFIC_DATA_RATE_TYPE
   byte reserved4[3];
} DCCH_RDA_Sub_Record_Type;

/**
Enumeration of "decision" types FCH_RDA_SUB_RECORD_TYPE
available for CDMA system
*/
typedef enum
{
   RDA_DataRate_Erasure,
   RDA_DataRate_OneEighth,
   RDA_DataRate_OneQuarter,
   RDA_DataRate_OneHalf,
   RDA_DataRate_Full,
   RDA_DataRate_Max
} RDA_CDMA_TRAFFIC_DATA_RATE_TYPE;

/**
Sub-FIELD OF RDA2 -- SCH_RDA_SUB_RECORD_2_TYPE
*/
typedef union
{
   struct
   {
      word  ltu_crc;            //!< ' LTU crc value
      word  ser;                //!< ' SER for the frame
      byte  status;             //!< ' frame CRC
      byte  reserved[3];
   } dev_sch_conv;
   struct
   {
      word  min_llr;            //!< ' Log Likelihood Ratio
      byte  num_iterations;     //!< ' Indicates the number of iterations run by the TD
      byte  crc_pass;           //!< ' 1=Good frame
      byte  reserved[4];
   } dev_sch_turbo;
} sch_code_type;
/* --This definition was removed December 14, 2005
typedef union
{
struct
{
word    ltu_crc;
byte    status;
byte    ser;
} dev_sch_conv;
struct
{
word    min_llr;
byte    num_iterations;
byte    crc_pass;
} dev_sch_turbo;
} sch_code_type;
*/

/**
Sub packet of RDA2 -- SCH_RDA_SUB_RECORD_2_TYPE
*/
typedef struct
{
   dword    reserved0;
   sch_code_type sch_code;
   word    reserved2;
   word    reserved3;
   word    rate;
   byte    decision;        //!< Data rate, according to RDA_CDMA_TRAFFIC_DATA_RATE_TYPE
   byte    codeType;        //!< (0) FTM_SCH_CODING_CONVOLUTIONAL,  (1) FTM_SCH_CODING_TURBO
} SCH_RDA_Sub_Record_Type;

/**
Sub-FIELD OF RDA2 -- SCH_RDA_SUB_RECORD_2_TYPE
*/
typedef union
{
   struct
   {
      word  ltu_crc;
      word  ser;
      byte  status;
      byte  reserved[3];
   } dev_sch_conv;
   struct
   {
      word  min_llr;
      byte  num_iterations;
      byte  crc_pass;
      byte  reserved[4];
   } dev_sch_turbo;
} sch_code_2_type;

/**
Sub packet of RDA2 -- SCH_RDA_SUB_RECORD_2_TYPE

This structure is the only difference between the
RDA and RDA2 log packet types
*/
typedef struct
{
   dword     reserved0;
   sch_code_2_type sch_code;
   word  reserved2;
   word  reserved3;
   word  rate;      //!< Max Data rate of SCH
   byte  decision;  //!< Data rate, according to RDA_CDMA_TRAFFIC_DATA_RATE_TYPE
   byte  codeType;  //!< (0) FTM_SCH_CODING_CONVOLUTIONAL,  (1) FTM_SCH_CODING_TURBO
} SCH_RDA_Sub_Record_2_Type;

/**
Union for the RC field of RDA_SUB_RECORD_HEADER_TYPE
*/
typedef union
{
   struct
   {
      word  fch_rc  : 3;
      word  dcch_rc : 3;
      word  sch_rc :    3;
      word  frame_offset : 7;
   } chan_rc;
   word mask;
} Chan_RC_Type;

/**
Sub packet of RDA2 -- RDA_SUB_RECORD_HEADER_TYPE
*/
typedef struct
{
   Chan_RC_Type         rc;
   RDA_Channels_Info_Type   assigned_channels;

   byte     num_sub_records;
   byte  reference_buf[1];
} RDA_Sub_Record_Header_Type;

/**
Searcher log header (logs 0x119A - 0x11A3)
*/
typedef struct
{
   byte iVersion;
   byte iNumSubPackets;
   word iReserved;
   byte iSubPacketsData[1];
} SRCH_TNG_GeneralizedSearcherHeader;

/**
Searcher sub packet data header (logs 0x119A - 0x11A3)
*/
typedef struct
{
   byte iSubPacketID;
   byte iSubPacketVersion;
   word iSubPacketSize;
   byte iSubPacketData[1];
} SRCH_TNG_GeneralizedSearcherSubPacketHeader;

/**
Searcher status sub packet data (sub packet type #1)
*/
typedef struct
{
   byte iSearcherState;
   byte iReserved;
   word iForwardRC;
} SRCH_TNG_SearcherStatus;

/**
RF sub packet data (sub packet type #2)
*/
typedef struct
{
   byte iRX0BandClass;
   byte iRX1BandClass;
   word iRX0CDMAChannel;
   word iRX1CDMAChannel;
   byte iRX0AGC;
   byte iRX1AGC;
   word iTxPower;
   byte iTxGainAdj;
   byte iTxPowerLimit;
} SRCH_TNG_RFStatus;

/**
Idle Demod Stats sub packet data (sub packet type #18)
*/
typedef struct
{
   byte iChannel;    // 0-PCH, 1-BCCH, 2-FCCCH
   byte iReserved;
   word iFrameSEC;
   dword iFrameEnergy;
} SRCH_TNG_IdleDemodStats;

//! Definition of searcher TNG General Status
#define FTM_CDMA2000_SRC_TNG_STATUS     0x119C

//! Rate Determination Algorithm Frame Information (LOG_CODE 0x10D9)
#define FTM_CDMA2000_RDA2_FRAME_INFO        0x10D9

//! Rate Determination Algorithm Frame Information (LOG_CODE 0x10D9)
#define FTM_CDMA2000_RDA_FRAME_INFO     0x10C9

//! Definition of searcher TNG Demodulation Info (LOG_CODE 0x119D)
#define FTM_CDMA2000_SRC_TNG_DEMOD_INFO 0x119D

//! C2K paging channel symbol rate
#define CDMA2000_PAGING_CHANNEL_SYMBOL_RATE 19200

//! LTE PDSCH
#define LTE_PDSCH_INDICATION 0xB173

//! Stucture of SER_Sub_Data record used in Paging MER Message
typedef struct
{
   byte chain;
   word ser;
   byte bad_message; // This message would have been counted in the MER statistics as a failure
} SER_Sub_Data;

//! Max number of accumulated SER_Sub_Data Record
#define MAX_NUM_ACCUM_SER 20

//! Structure of Paging MER Message
typedef struct
{
   word   count; /* number of SER record in the ser array, could use uint8 here, but for alignment, use uint16*/
   byte pch_rate;
   SER_Sub_Data records[MAX_NUM_ACCUM_SER];
} RXC_SER_Log;

//! Stucture of Paging MER Statistics
typedef struct
{
   long totalPagingSER;
   long totalNumSymbol;
} CDMA2000_Paging_SER_Stat;

//!Max number of RF subpackets
#define CDMA2000_DEMOD_RF_SUBPACKET_BUFFER_SIZE 1000

//! Structure to hold the demod status RF subpacket data
typedef struct
{
   long Rx0_Bandclass[CDMA2000_DEMOD_RF_SUBPACKET_BUFFER_SIZE];
   long Rx1_Bandclass[CDMA2000_DEMOD_RF_SUBPACKET_BUFFER_SIZE];
   double Rx0_AGC_dBm;
   double Rx0_AGC;
   double Rx1_AGC_dBm;
   double Rx1_AGC;
   double TxPower;
   double TxGainAdj;
   double TxPowerLimit;
   double TxPowerLimit_dBm;
   long iTotalRecords;
} CDMA2000_Demod_RF_Stat;

//! cdma2000 Transceiver Resource Manager (TRM) Log (LOG_CODE 0x12E8)
#define CDMA2000_TRANSCEIVER_RESOURCE_MANAGER_LOG 0x12E8

//! Structure of client state in TRM subpkt 0 to 9 and 11 header
typedef struct
{
   byte iLockSate;
   byte iResource;
   byte iReason;
   byte iPriority;
   byte iChain;
   byte iGranted;
   byte iGroup;
   byte iRetain;
} CDMA2000_TRM_Client_State;

//! Structure of cdma2000 Transceiver Resource Manager Log Header
typedef struct
{
   byte iTrmSubPktId;
   byte iVersion;
   byte iClientID;
   byte iClientLogID;
   CDMA2000_TRM_Client_State _oOldClientState;
   CDMA2000_TRM_Client_State _oNewClientState;
} CDMA2000_TRM_Log_Header;

#define CDMA2000_TRM_LOG_PACKET_BUFFER_SIZE 1000

/**
Structure of FTM2 1X Primary AGC, FTM Log code = LOG_FTM2_LOG_1X_AGC = 0x4, See 80-V9151-1 (Factory Test Mode 1X Logging API Interface Control Document)
*/
typedef struct
{
   word ftm_log_id;
   short rx_agc;
   short tx_gain_ctl;
   short tx_gain_adj;
   short tx_open_loop;
   word tx_agc_adj;
   byte pa_ratchet;
   byte lna_state;
   byte pa_state;
   byte hdet_raw;
   word therm_raw;
   byte therm_scaled;
   byte temp_index;
   byte temp_remainder;
   byte intelliceiver_state;
   word hdet_v2;
   word pa_smps_pdm;
   word betaprimevalue;
   short tx_agc_raw;
   uint8 xpt_mode;
   word pin_comp;
   word pout_comp;
   word env_scale_backoff;
   word iq_backoff;
   word xpt_delay;
   word dpd_index;
   word pa_icq;
} FTM_LOG_1X_AGC_Struct;

/**
Structure of FTM 1 1X Secondary AGC, FTM Log Code = LOG_FTM2_LOG_1X_AGC_C1  = 0x6, See 80-V9151-1 (Factory Test Mode 1X Logging API Interface Control Document)
*/
typedef struct
{
   word ftm_log_id;
   short rx_agc;
   short tx_gain_ctl;
   short tx_gain_adj;
   short tx_open_loop;
   word tx_agc_adj;
   byte pa_ratchet;
   byte lna_state;
   byte pa_state;
   byte hdet_raw;
   word therm_raw;
   byte therm_scaled;
   byte temp_index;
   byte temp_remainder;
   short rx_agc_c1;
   byte lna_state_c1;
   byte intelliceiver_state;
   word hdet_v2;
   word pa_smps_pdm;
   word betaprimevalue;
   short tx_agc_raw;
   uint8 xpt_mode;
   word pin_comp;
   word pout_comp;
   word env_scale_backoff;
   word iq_backoff;
   word xpt_delay;
   word dpd_index;
   word pa_icq;
} FTM_LOG_1X_AGC_C1_Struct;

//! Definition of log code for CDMA2000 RF Warmup time
#define CDMA2000_LOG_CODE_RF_WARMUP_TIME    0x1449
#define CDMA2000_LOG_CODE_RF_WARMUP_TIME_MAX_NUM_SUB_PKT 1
/**
Structure of CDMA2000 RF Warmup Time sub pkt struct
*/
typedef struct
{
   //header
   byte pkt_id;
   byte pkt_ver;
   word pkt_size;
   //payload
   byte device;
   dword curr_wu_time;
   dword min_wu_time;
   dword max_wu_time;
   dword avg_wu_time;
   dword expected_wu_time;
   dword histogram_wu_time[21];
   dword wu_count;
   byte lna_state;
   byte lna_gain;
   short rx_agc;
} CDMA2000_LOG_RF_WARMUP_TIME_SUB_PKT_Struct;

/**
Structure of CDMA2000 RF Warmup Time pkt struct
*/
typedef struct
{
   //generic header is not considered as log payload in QMSL
   //   dword len;
   //   dword code;
   //   byte ts[8];//uint64 time stamp
   byte pkt_version;
   byte num_subpkt;
   word hdr_reserved;
   CDMA2000_LOG_RF_WARMUP_TIME_SUB_PKT_Struct sub_pkt[CDMA2000_LOG_CODE_RF_WARMUP_TIME_MAX_NUM_SUB_PKT];
} CDMA2000_LOG_RF_WARMUP_TIME_PKT_Struct;

/**
Number of symbols per frame for FCH
*/
typedef enum
{
   FTM_CDMA2000_NS_NUM_SYMBOLS_RC1_FRAME = 384,
   FTM_CDMA2000_NS_NUM_SYMBOLS_RC2_FRAME = 384,
   FTM_CDMA2000_NS_NUM_SYMBOLS_RC3_FRAME = 768,
   FTM_CDMA2000_NS_NUM_SYMBOLS_RC4_FRAME = 384,
   FTM_CDMA2000_NS_NUM_SYMBOLS_RC5_FRAME = 768
} FTM_CDMA2000_NS_SymbolsPerFrame_Enum;

/**
Number of symbols per frame for F-DCCH
*/
typedef enum
{
   FTM_CDMA2000_NS_DCCH_NUM_SYMBOLS_RC1_FRAME = 0,
   FTM_CDMA2000_NS_DCCH_NUM_SYMBOLS_RC2_FRAME = 0,
   FTM_CDMA2000_NS_DCCH_NUM_SYMBOLS_RC3_FRAME = 768,
   FTM_CDMA2000_NS_DCCH_NUM_SYMBOLS_RC4_FRAME = 384,
   FTM_CDMA2000_NS_DCCH_NUM_SYMBOLS_RC5_FRAME = 768
} FTM_CDMA2000_NS_DCCH_SymbolsPerFrame_Enum;

/**
Number of symbols per frame for F-SCH
*/
typedef enum
{
   FTM_CDMA2000_NS_SCH_NUM_SYMBOLS_RC1_FRAME = 0,
   FTM_CDMA2000_NS_SCH_NUM_SYMBOLS_RC2_FRAME = 0,
   FTM_CDMA2000_NS_SCH_NUM_SYMBOLS_RC3_FRAME = 768,
   FTM_CDMA2000_NS_SCH_NUM_SYMBOLS_RC4_FRAME = 384,
   FTM_CDMA2000_NS_SCH_NUM_SYMBOLS_RC5_FRAME = 768
} FTM_CDMA2000_NS_SCH_SymbolsPerFrame_Enum;

/**
Power type enumeration used by _FTM_CDMA2000_SET_REV_PWR command
*/
typedef enum
{
   FTM_1X_TX_POWER_TYPE_AGC_SETPOINT    = 0,
   FTM_1X_TX_POWER_TYPE_RPC_ENABLE      = 1,
   FTM_1X_TX_POWER_TYPE_RPC_DISABLE = 2,
   FTM_1X_TX_POWER_TYPE_POWER_UP        = 3,
   FTM_1X_TX_POWER_TYPE_POWER_DOWN      = 4
} FTM_CDMA2000_NS_Set_Rev_Power_Type_Enum;

/******************************************************************************
FTM - cdma2000 and EVDO non-signaling command ID
*******************************************************************************/

/**
\brief Enumeration of CDMA2000 and EVDO non-signaling FTM Sub-command ID's
*/
typedef enum
{
   _FTM_CDMA2000_PILOT_ACQ      = 100,  //!<'   Acquire Pilot
   _FTM_CDMA2000_DEMOD_SYNC = 101,  //!<'   Acquire Sync channel
   _FTM_CDMA2000_DEMOD_FCH      = 102,  //!<'   Assign forward fundamental channel and setup parameters
   _FTM_CDMA2000_DEMOD_FSCH = 103,  //!<'   Assign forward supplemental channel
   _FTM_CDMA2000_MOD_FCH        = 104,  //!<'   Assign reverse fundamental channel
   _FTM_CDMA2000_MOD_SCH        = 105,  //!<'   Assign reverse supplemental channel
   _FTM_CDMA2000_FCH_LOOPBACK   = 106,  //!<'   Enable loopback on the fundamental channel
   _FTM_CDMA2000_SCH_LOOPBACK   = 107,  //!<'   Enable loopback on the supplemental channel
   _FTM_CDMA2000_CMD_RELEASE    = 108,  //!<'   Deassign all traffic channels
   _FTM_CDMA2000_SET_MODE       = 109,  //!<'   Set Mode
   _FTM_CDMA2000_DEMOD_DCCH = 110,  //!<' Assign fotward dedicated control channel
   _FTM_CDMA2000_MOD_DCCH       = 111,  //!<' Assign reverse dedicated control channel
   _FTM_CDMA2000_DCCH_LOOPBACK = 112,   //!<' Enable loopback on the dedicated control channel
   _FTM_EVDO_PILOT_ACQ          = 113,  //!<'Acquire HDR forware pilot channel
   _FTM_EVDO_DEMOD_SYNC     = 114,  //!<'Acquire HDR system time
   _FTM_EVDO_DEMOD_CC_MAC_FTC   = 115,  //!<'Demodulate HDR CC/MAC/FTC
   _FTM_EVDO_MOD_ACC            = 116,  //!<'Modulate reverse access channel
   _FTM_EVDO_MOD_TRA            = 117,  //!<'Modulate reverse traffic channel
   _FTM_EVDO_CMD_RELEASE        = 118,  //!<'Deassign HDR channels
   _FTM_CDMA2000_RF_CMDS        = 119,  //!<' RF Subcommands (RF Calibration)
   _FTM_CDMA2000_DEMOD_FCH_DCCH = 120,
   //!<'Assign forward fundamental channel and dedicated control channel simultaneously (Release A)
   _FTM_CDMA2000_MOD_FCH_DCCH   = 121,
   //!<'Assign reverse fundamental channel and dedicated control channel simultaneously (Release A)
   _FTM_CDMA2000_SET_REV_PWR    = 140,   //!<' Set CDMA2000 Reverse link Power
   _FTM_CDMA2000_RESET_FCH_STAT = 141,   //!<' Reset F-FCH Statistics
   _FTM_CDMA2000_GET_FCH_STAT   = 142,   //!<' Get F-FCH Statistics
   _FTM_EVDO_DEMOD_FWD_WITH_NO_REV  = 122, //!<'Demodulate Forward Link with No Reverse Link Rev 0
   _FTM_EVDO_SET_IDLE               = 123, //!<'Put the searcher in Idle mode
   _FTM_EVDO_REV_A_CONF_MAC_FOR_FWD_CC_MAC_FTC = 124, //!<'configure the Rev A packet mode
   _FTM_EVDO_REV_A_MOD_ACC          = 125, //!<'Modulate the reverse access channel in IS-896 Rev A mode
   _FTM_EVDO_REV_A_MOD_TRA          = 126, //!<'Modulate the reverse traffic channel in IS-896 Rev A
   _FTM_EVDO_REV_A_DEMOD_FWD_WITH_NO_REV  = 127, //!<'Demodulate Forward Link with No Reverse Link Rev A
   _FTM_FWD_HHO_SC                  = 128, //!<'Handover for cdma2000
   _FTM_EVDO_REV_B_MOD_RTC          = 131, //!<'Modulate the reverse traffic channel in IS-896 Rev B
   _FTM_EVDO_REV_B_CONFIG_RTC       = 132, //!<'Config the reverse traffic channel in IS-896 Rev B
   _FTM_EVDO_CONFIG_SAME_CHANNEL    = 133, //!<'Config the same channel params defined in IS-896, including pilot drop, pilot add etc.
   _FTM_EVDO_REV_B_CONFIG_RTC_TX_PATTERN    = 134, //!<'Config the tx data pattern on reverse link carriers for Rev B
   _FTM_EVDO_HHO_SC                 = 143,  //!<' Hard handover for EVDO
   _FTM_EVDO_SET_REV_PWR            = 135,  //!<'Set EVDO Reverse link power
   _FTM_EVDO_RESET_FWD_STAT         = 144,  //!<' Reset EVDO Forward Link Statistics
   _FTM_EVDO_GET_FWD_STAT           = 145,  //!<' Get EVDO Forward Link Statistics
   _FTM_CDMA2000_RX_LEVEL_REQ       = 146,  //!<' Get cdma2000 Rx power level
   _FTM_EVDO_RX_LEVEL_REQ           = 147,  //!<' Get EVDO Rx power level
   _FTM_1X_RADIO_ENTER  = 4096,
   _FTM_1X_RADIO_EXIT = 4097,
   _FTM_1X_RADIO_ENABLE = 4098,
   _FTM_1X_RADIO_DISABLE  = 4099,
   _FTM_1X_RADIO_WAKEUP_RX  = 4100,
   _FTM_1X_RADIO_SLEEP_RX = 4101,
   _FTM_1X_RADIO_WAKEUP_TX  = 4102,
   _FTM_1X_RADIO_SLEEP_TX = 4103,
   _FTM_1X_RADIO_RETUNE = 4104,
   _FTM_1X_RADIO_ENABLE_DIV = 4105,
   _FTM_1X_RADIO_DISABLE_DIV  = 4106,
   _FTM_1X_RADIO_GET_RXAGC  = 4107,
   _FTM_1X_RADIO_GET_TXAGC  = 4108,
   _FTM_1X_RADIO_SET_TX_POWER = 4109,
   _FTM_1X_RADIO_POWER_MODE_OVERRIDE = 4112,
   _FTM_1X_RADIO_CLEAR_PM_OVERRIDE = 4113,
   _FTM_HDR_RADIO_ENTER = 8192,
   _FTM_HDR_RADIO_EXIT  = 8193,
   _FTM_HDR_RADIO_ENABLE  = 8194,
   _FTM_HDR_RADIO_DISABLE = 8195,
   _FTM_HDR_RADIO_WAKEUP_RX = 8196,
   _FTM_HDR_RADIO_SLEEP_RX  = 8197,
   _FTM_HDR_RADIO_WAKEUP_TX = 8198,
   _FTM_HDR_RADIO_SLEEP_TX  = 8199,
   _FTM_HDR_RADIO_RETUNE  = 8200,
   _FTM_HDR_RADIO_ENABLE_DIV  = 8201,
   _FTM_HDR_RADIO_DISABLE_DIV = 8202,
   _FTM_HDR_RADIO_GET_RXAGC = 8203,
   _FTM_HDR_RADIO_GET_TXAGC = 8204,
   _FTM_HDR_RADIO_SET_TX_POWER  = 8205
} FTM_CDMA2000_Cmd_Id_Enum;

/**
\brief Enumeration of Calibration API V2 (80-V2376-1) FTM Sub-command ID's
*/
typedef enum
{
   _FTM_CDMA_CAL_V2_COMMIT_NV           = 0,            //!<'Commit RF calibration to NV
   _FTM_CDMA_CAL_V2_CAL_DVGA            = 1,            //!<'Calibrate DVGA
   _FTM_CDMA_CAL_V2_CAL_LNA         = 2,            //!<'Calibrate LNA
   _FTM_CDMA_CAL_V2_CAL_IM2         = 3,            //!<'Calibrate IM2
   _FTM_CDMA_CAL_V2_INTELLICEIVER       = 4,                //!<'Calibrate Intelliceiver
   _FTM_CDMA_CAL_V2_INTELLICEIVER_RC_TUNE =5            //!<'Intelliceiver RC Tune calibration
}   FTM_CDMA_CAL_V2_Cmd_Id_Enum;

/**
cdma2000 Band Class identifiers for QLIB_FTM_CDMA2000_PILOT_ACQ()

The enumeration values are the same as the band class number.  If an
enumeration is not available for a new band class number then the
an integer with the band class number can be used.

*/
typedef enum
{
   FTM_CDMA2000_BAND_BC0    = 0,
   FTM_CDMA2000_BAND_BC1    = 1,
   FTM_CDMA2000_BAND_BC2    = 2,
   FTM_CDMA2000_BAND_BC3    = 3,
   FTM_CDMA2000_BAND_BC4    = 4,
   FTM_CDMA2000_BAND_BC5    = 5,
   FTM_CDMA2000_BAND_BC6    = 6,
   FTM_CDMA2000_BAND_BC7    = 7,
   FTM_CDMA2000_BAND_BC8    = 8,
   FTM_CDMA2000_BAND_BC9    = 9,
   FTM_CDMA2000_BAND_BC10   = 10,
   FTM_CDMA2000_BAND_BC11   = 11,
   FTM_CDMA2000_BAND_BC12   = 12,
   FTM_CDMA2000_BAND_BC13   = 13,
   FTM_CDMA2000_BAND_BC14   = 14,
   FTM_CDMA2000_BAND_BC15   = 15,
   FTM_CDMA2000_BAND_BC16   = 16,
   FTM_CDMA2000_BAND_BC17   = 17
} FTM_CDMA2000_BandClasstype;

/**
1x dynamic range types

This is a list of dynamic range configurations used for 1x non-signaling,
to convert results from AGC units to dB and dBm
*/
typedef enum
{
   FTM_CDMA2000_NS_DR_85_3,     //!<' 85.3dB dynamic range, min_rssi = -106.0dBm
   FTM_CDMA2000_NS_DR_102_4     //!<' 102.4dB dynamic range, min_rssi = -115.0dBm
} FTM_CDMA2000_NS_DR_Types_Enum;

/**
1x acquisition modes
*/
typedef enum
{
   FTM_CDMA2000_NS_FTM_ACQ_MODE_FULL    = 0,    //!<' Full
   FTM_CDMA2000_NS_FTM_ACQ_MODE_MINI    = 1,    //!<' Mini, not supported, not to be used
   FTM_CDMA2000_NS_FTM_ACQ_MODE_MICRO   = 2     //!<' Micro, not supported, not to be used
} FTM_CDMA2000_NS_PilotAcqMode_Enum;

/**
1x REV FCH rates
*/
typedef enum
{
   FTM_CDMA2000_NS_REV_FCH_FULL_RATE    = 0,    //!<' Full rate
   FTM_CDMA2000_NS_REV_FCH_HALF_RATE    = 1,    //!<' half rate
   FTM_CDMA2000_NS_REV_FCH_QTR_RATE = 2,    //!<' quarter rate
   FTM_CDMA2000_NS_REV_FCH_8TH_RATE = 3     //!<' eighth rate
} FTM_CDMA2000_NS_REV_FCH_Rates_Enum;

/**
1x FCH rate SETS
*/
typedef enum
{
   FTM_CDMA2000_NS_RC_1 = 1,    //!<' RC1
   FTM_CDMA2000_NS_RC_2 = 2,    //!<' RC2
   FTM_CDMA2000_NS_RC_3 = 3,    //!<' RC3
   FTM_CDMA2000_NS_RC_4 = 4,    //!<' RC4
   FTM_CDMA2000_NS_RC_5 = 5     //!<' RC5
} FTM_CDMA2000_NS_FWD_RC_Enum;

/**
CDMA2000 SCH Coding types
*/
typedef enum
{
   FTM_SCH_CODING_CONVOLUTIONAL,
   FTM_SCH_CODING_TURBO
} FTM_SCH_CODING_Enum;

/**
CDMA2000 SCH reverse link data rates
*/
typedef enum
{
   FTM_REV_SCH_1_5_RATE,    //!<' (0 = 1.5 kbps),
   FTM_REV_SCH_2_7_RATE,    //!<'  (1 = 2.7 kbps),
   FTM_REV_SCH_4_8_RATE,    //!<'  (2 = 4.8 kbps),
   FTM_REV_SCH_9_6_RATE,    //!<'  (3 = 9.6 kbps),
   FTM_REV_SCH_19_2_RATE,   //!<' (4 = 19.2 kbps),
   FTM_REV_SCH_38_4_RATE,   //!<'  (5 = 38.4 kbps),
   FTM_REV_SCH_76_8_RATE,   //!<'  (6 = 76.8kbps), and
   FTM_REV_SCH_153_6_RATE   //!<'  (7 = 153.6kbps) respectively.

   // Note that for turbo-encoded frames, the minimum supported rate is FTM_REV_SCH_19_2_RATE.
} FTM_SCH_DataRates_Enum;

/**
CDMA2000 SCH foward link data rates
*/
typedef enum
{
   FTM_RATE_1X, //!<' (9.6 kbps)
   FTM_RATE_2X, //!<' (19.2 kbps)
   FTM_RATE_4X, //!<' (38.4 kbps)
   FTM_RATE_8X, //!<' (76.8 kbps)
   FTM_RATE_16X //!<' (153.6 kbps)
} ftm_spread_rate_type;

/**
CDMA2000 Non-signaling return status
*/
typedef enum
{
   _FTM_CDMA2000_CMD_SUCCESS        = 0,                //!<'Indicates Success
   _FTM_CDMA2000_INVALID_CMD        = 1,                //!<'Indicates an invalid cmd
   _FTM_CDMA2000_INVALID_STATE      = 2,                //!<'Indicates that FTM cannot process the command in current state
   _FTM_CDMA2000_NO_SUCCESS     = 3                 //!<'Indicates failure
} FTM_CDMA2000_CMD_STATUS;

/**
CDMA2000 Non-signaling Log types

This is a list of the types of log events that will be monitored during CDMA2000 non-signaling
*/
typedef enum
{
   FTM_CDMA2000_NS_Log_Searcher,                //!<' CDMA2000 Searcher (LOG_CODE 0x119C)
   FTM_CDMA2000_NS_Log_AGC_C0,                  //!<' FTM2 log, sub log 5, for Primary AGC
   FTM_CDMA2000_NS_Log_AGC_C1,                  //!<' FTM2 log, sub log 7, for Diversity AGC
   FTM_CDMA2000_NS_Log_RDA2,                    //!<' CDMA2000 (LOG_CODE 0x10D9), used for SER
   FTM_CDMA2000_NS_Log_RDA,                 //!<' CDMA2000 (LOG_CODE 0x10C9), used for SER

   FTM_CDMA2000_NS_Log_MAX                      //!<' Maximum # of logs that are being scanned for
} FTM_CDMA2000_NS_Log_Types_Enum;

/**
CDMA2000 Non-signaling Event types

This is a list of the types of event types that will be monitored during CDMA2000 non-signaling.

Generally an event is based on reveiving one asynchronous log message + checking the state
of one log sub fields.

*/
typedef enum
{
   FTM_CDMA2000_NS_Event_PilotAcq,              //!<' Searcher State = 0x3 (Acquisition of the pilot channel)
   FTM_CDMA2000_NS_Event_RecSync,               //!<' Searcher State = 0x4 (Reception of the sync channel)
   FTM_CDMA2000_NS_Event_Traffic,               //!<' Searcher State = 0x8 (Operation on the traffic channel)

   FTM_CDMA2000_NS_Event_RDA_Update,            //!<' Rate determination algorithm report #1
   FTM_CDMA2000_NS_Event_RDA2_Update,           //!<' Rate determination algorithm report #2
   FTM_CDMA2000_NS_Event_PrimaryAGC,            //!<' Primary AGC
   FTM_CDMA2000_NS_Event_SecondaryAGC,          //!<' Secondary AGC

   FTM_CDMA2000_NS_Event_MAX                    //!<' Maximum # of events
} FTM_CDMA2000_NS_Event_Types_Enum;

/**
Searcher states, as used in "Searcher Status subpacket" in Srch TNG General Status Log (0x119C)
*/
typedef enum
{
   FTM_CDMA2000_Searcher_RawInit            = 0x00, //!<'  Raw initialization state
   FTM_CDMA2000_Searcher_DeepSleep          = 0x01, //!<'  Deep sleep in start state
   FTM_CDMA2000_Searcher_InitStateCDMA      = 0x02, //!<'  Initial state for CDMA operation
   FTM_CDMA2000_Searcher_PilotAcq           = 0x03, //!<'  Acquisition of the pilot channel
   FTM_CDMA2000_Searcher_RecSync            = 0x04, //!<'  Reception of the sync channel
   FTM_CDMA2000_Searcher_SyncToPage     = 0x05, //!<'  Transition from sync to paging channel
   FTM_CDMA2000_Searcher_Paging         = 0x06, //!<'  Operation on the paging channel
   FTM_CDMA2000_Searcher_SlottedSleep       = 0x07, //!<'  Slotted mode sleep state
   FTM_CDMA2000_Searcher_Traffic            = 0x08, //!<'  Operation on the traffic channel
   FTM_CDMA2000_Searcher_RetToSync          = 0x09, //!<'  Return from paging or traffic to sync channel (unslew)
   FTM_CDMA2000_Searcher_PCG                = 0x0a, //!<'  Operation in PCG state
   FTM_CDMA2000_Searcher_PowerUp            = 0x0b  //!<'  Powerup state
} FTM_CDMA2000_SearcherStates_Enum;

/**
Statistics for 1X AGC, structure definition is shared between Primary and secondary antennas,
but separate instances will be created for both

*/
typedef struct
{
   dword iTotalRecords; //!< Total number of AGC records that have been received

   //unsigned double ftm_log_id;
   double dRxAGC;               //!< AGC units
   double dRxAGC_linear;        //!< Linear power (mW)
   double dRxAGC_dBm;           //!< Log power (dBm)

   double dTxGainCtl;           //!< AGC units
   double dTxGainCtl_linear;    //!< Linear power (mW)
   double dTxGainCtl_dBm;       //!< Log power (dBm)

   double dTxGainAdj;           //!< AGC units
   double dTxGainAdj_dB;        //!< Log power (dB)

   double dTxOpenLoop;          //!< AGC units
   double dTxOpenLoop_linear;   //!< Linear power (mW)
   double dTxOpenLoop_dBm;      //!< Log power (dBm)

   double dTxAgcAdj;
   double dPA_Ratchet;
   double dLNA_State;
   double dPA_State;
   double dHDET_Raw;
   double dThermRaw;
   double dThermScaled;
   double dTempIndex;
   double dTempRemainder;
   double dIntelliceiverState;
   double dHDET_V2;
   double dPaSmpsPdm;               //!< smps pdm;
   double dTxAgcRaw;
   double dHDET_dBm;
   double dBetaprimevalue;
   double dXpt_mode;
   double dPin_comp;
   double dPout_comp;
   double dEnv_scale_backoff;
   double dIq_backoff;
   double dXpt_delay;
   double dDpd_index;
   double dPA_icq;
} FTM_LOG_1X_AGC_Statistics;

/**
SER statistics structure to be used for cdma2000 non-signaling.
*/
typedef struct
{
   long iSumFrames;     //!< Number of frames counted
   long iSumSymbols;        //!< Number of symbols counted

   long iSumFramesErrors;   //!< Number of frames errors counted
   long iSumSymbolErrors;   //!< Number of symbols errors counted

   double dFER;         //!< Calculated FER
   double dSER;         //!< Calculated SER
} FTM_CDMA2000_SER_Statistics;

/**
Structure to be used for cdma2000 non-signaling status.

Contains searcher status, AGC statistics, and SER/FER statistics.
*/
typedef struct
{
   //! Array to keep track of whether a certain event has occured, indexed to FTM_CDMA2000_NS_Event_Types_Enum
   byte bHasUpdated[ FTM_CDMA2000_NS_Event_MAX ];

   /**
   Searcher information
   */
   FTM_CDMA2000_SearcherStates_Enum eSearcherState;

   //FTM_LOG_EVDO_CtoI_Statistics_Struct oEVDO_CtoI_Stats;

   /**
   Data for primary AGC
   */
   FTM_LOG_1X_AGC_Struct oCDMA2000_AGC_C0;                  //!< Most recent Primary AGC information
   FTM_LOG_1X_AGC_Statistics oCDMA2000_AGC_C0_LatestStats;  //!< Most recent Statistics for Primary AGC, transformed from oCDMA2000_AGC_C0
   FTM_LOG_1X_AGC_Statistics oCDMA2000_AGC_C0_SumStats; //!< Summed Statistics for Primary AGC
   FTM_LOG_1X_AGC_Statistics oCDMA2000_AGC_C0_AvgStats; //!< Averageed statistics for Secondary AGC

   /**
   Data for secondary AGC
   */
   FTM_LOG_1X_AGC_C1_Struct oCDMA2000_AGC_C1;           //!< Most recent Secondary AGC information
   FTM_LOG_1X_AGC_Statistics oCDMA2000_AGC_C1_LatestStats;  //!< Most recent Statistics for Secondary AGC, transformed from oCDMA2000_AGC_C1
   FTM_LOG_1X_AGC_Statistics oCDMA2000_AGC_C1_SumStats; //!< Summed for Secondary AGC
   FTM_LOG_1X_AGC_Statistics oCDMA2000_AGC_C1_AvgStats; //!< Averageed statistics for Secondary AGC

   /**
   FCH SER statistics
   */
   FTM_CDMA2000_SER_Statistics oCDMA2000_FCH_SER_Stats;

   /**
   FCH SER statistics per data rate

   Indexed by the enumeration: RDA_CDMA_TRAFFIC_DATA_RATE_TYPE;

   */
   FTM_CDMA2000_SER_Statistics oCDMA2000_FCH_SER_Stats_perRate[ RDA_DataRate_Max ];

   /**
   DCCH SER statistics
   */
   FTM_CDMA2000_SER_Statistics oCDMA2000_DCCH_SER_Stats;

   /**
   SCH SER statistics
   */
   FTM_CDMA2000_SER_Statistics oCDMA2000_SCH_SER_Stats;
} FTM_CDMA2000_NS_Status_Struct;

/******************************************************************************
FTM - EVDO non-signaling log parser definitions
*******************************************************************************/

//! Definition of log code for 1xEV-DO Finger Info
#define FTM_EVDO_NS_LOG_CODE_FINGER_INFO        0x108A

//! Definition of log code for 1xEV-DO Air Link Summary
#define FTM_EVDO_NS_LOG_CODE_AIR_LINK_SUMMARY   0x1068

//! Definition of log code for 1xEVDO Foward link statistics summary
#define EVDO_FORWARD_LINK_STATISTICS_SUMMARY    0x1084

//! Definition of log code for 1xEVDO Power Logs
#define EVDO_POWER  0x1069

//! Definition of log code for 1xEVDO Rev. A Single-user forward statistics summary
#define EVDO_REVA_SU_FWDSTATS   0x1192

//! Definition of log code for 1xEVDO Rev. B Multi-carrier single-user forward statistics summary
#define EVDO_MC_SU_FWD_STATS    0x12A2

//! Definition of log code for 1xEVDO Rev. B Multi-carrier air link summary
#define EVDO_MC_AIR_LINK_SUMMARY 0x1296

//! Definition of log code for 1xEVDO Rev. B Multi-carrier power
#define EVDO_MC_POWER 0x129C

//! Definition of maximum num of carriers for 1xEVDO Rev. B Multi-carrier
#define EVDO_MC_MAX_NUM_CARRIERS 3

/**
Structure of FTM2 EVDO Primary AGC, FTM Log code = LOG_FTM2_LOG_HDR_AGC     = 0x5
*/
typedef struct
{
   word ftm_log_id;
   short rx_agc;
   short tx_gain_ctl;
   short tx_gain_adj;
   short tx_open_loop;
   word tx_agc_adj;
   byte pa_ratchet;
   byte lna_state;
   byte pa_state;
   byte hdet_raw;
   word therm_raw;
   byte therm_scaled;
   byte temp_index;
   byte temp_remainder;
   byte intelliceiver_state;
   word hdet_v2;
   word pa_smps_pdm;
} FTM_LOG_EVDO_AGC_C0_Struct;

/**
Structure of FTM2 EVDO Secondary AGC, FTM Log Code = LOG_FTM2_LOG_HDR_AGC_C1 = 0x7
*/
typedef struct
{
   word ftm_log_id;
   short rx_agc;
   short tx_gain_ctl;
   short tx_gain_adj;
   short tx_open_loop;
   word tx_agc_adj;
   byte pa_ratchet;
   byte lna_state;
   byte pa_state;
   byte hdet_raw;
   word therm_raw;
   byte therm_scaled;
   byte temp_index;
   byte temp_remainder;
   short rx_agc_c1;
   byte lna_state_c1;
   byte intelliceiver_state;
   word hdet_v2;
   word pa_smps_pdm;
} FTM_LOG_EVDO_AGC_C1_Struct;

/**
Structure of the per-finger data used in log code 0x108A
*/
typedef struct
{
   word PilotPN;            //!<'
   dword  RTCOffset;        //!<'
   word C2I;                //!<'
   byte locked_antenna_diversity_fingindex; //!<'
   byte RPCCellIdx_ASPIdx;                      //!<'
   word Antenna0C2I;                //!<' C/I equivalent of the finger for antenna 0; only valid when
   //!<' Diversity is enabled
   word Antenna1C2I;                //!<' C/I equivalent of the finger for antenna 1; only valid when
   //!<' Diversity is enabled
} LOG_1XEVDO_Finger_Ver2_FingerInfo_Struct;

#define LOG_1XEVDO_MAX_FINGERS 12
/**
Structure of the header information for log code 0x108A,
at the end is the data for up to 12 fingers
*/
typedef struct
{
   byte srch_state;             //!<' State of the HDRSRCH state machine; refer to for nomenclature
   dword MSTR;                      //!<' Mobile station (AT) time reference offset relative to the RTC
   //!<' timebase in units of 1/8 chip

   word MSTRError;                  //!<' MSTR offset relative to earliest arriving in-lock and
   //!<' enabled active set pilot in units of 1/8 chip

   word MSTRPilotPN;                //!<' Pilot PN of the finger, which the MSTR is tracking;
   //!<' typically, the earliest arriving finger

   byte NumFingers;     //!<' Number of fingers (12 max)
   LOG_1XEVDO_Finger_Ver2_FingerInfo_Struct fingerData[ LOG_1XEVDO_MAX_FINGERS ];   //!<' Finger data
} LOG_1XEVDO_Finger_Ver2_Info_Struct;

/** Structure of the header information for log code 0x1084
1xEV-DO Forward Statistics Summery
*/
typedef struct
{
   dword    cc38400_good;
   dword    cc38400_bad;
   dword    cc76800_good;
   dword    cc76800_bad;
   dword    tc38400_good;
   dword    tc38400_bad;
   dword    tc76800_good;
   dword    tc76800_bad;
   dword    tc153600_good;
   dword    tc153600_bad;
   dword    tc307200short_good;
   dword    tc307200short_bad;
   dword    tc307200long_good;
   dword    tc307200long_bad;
   dword    tc614400short_good;
   dword    tc614400short_bad;
   dword    tc614400long_good;
   dword    tc614400long_bad;
   dword    tc921600_good;
   dword    tc921600_bad;
   dword    tc1228800short_good;
   dword    tc1228800short_bad;
   dword    tc1228800long_good;
   dword    tc1228800long_bad;
   dword    tc1843200_good;
   dword    tc1843200_bad;
   dword    tc2457600_good;
   dword    tc2457600_bad;
   dword    tcrate38400[16];
   dword    tcrate76800[8];
   dword    tcrate153600[4];
   dword    tcrate307200short[2];
   dword    tcrate307200long[4];
   dword    tcrate614400short[1];
   dword    tcrate614400long[2];
   dword    tcrate921600[2];
   dword    tcrate1228800short[1];
   dword    tcrate1228800long[2];
   dword    tcrate1843200[1];
   dword    tcrate2457600[1];
   dword    ccrate38400[16];
   dword    ccrate76800[8];
   dword    seq_num;
} LOG_1XEVDO_Forward_Statistics_Summary_Struct;

/**
Structure of the log message 0x1069, 1xEV-DO Power
*/
typedef struct
{
   byte PAState;                //!<' ATType [Bit3:Bit0]: 1 ?MSM4500.. 2 ?MSM5500;
   //!<' RatchetMode [Bit4]:register shows the state of the Tx power limiting: 0 ?Tx power not limited.. 1 ?Tx power is limited
   //!<' gives the state of the power amplifier.. 0 ?PA off.. 1 ?PA on
   short TxOpenLoopPower;       //!<' Signed; Tx power determined by the open loop adjust mechanism; in units of 1/256 dBm
   short TxClosedLoopAdjus; //!<' Signed; Tx power determined by the closed loop adjust mechanism; in units of 1/256 dB and in the range of [-128,127] dB
   short TxPilotPower;          //!<' Signed; represents the pilot power that is transmitted over the pilot channel; this is calculated based on the TxOpenLoopPower and the TxClosedLoopAdjust; in units of 1/256 dBm
   short TxTotalPower;      //!<' Signed; register holds the total Tx power as determined by the entire Tx AGC mechanism; in units of 1/256 dBm
   short RxAGC0;                //!<' Signed; represents the field that holds the total receive power as seen by Antenna 0; in units of 1/256 dBm
   short RxAGC1;                //!<' Signed; represents this field that holds the total receive power as seen by the Antenna 1; in units of 1/256 dBm
} LOG_1XEVDO_Power;

/** Structure for log code 0x1192
1xEV-DO Rev. A single user Forward Statistics Summery
*/
typedef struct
{
   dword seq_num;
   dword tc0_128bits_good;
   dword tc0_256bits_good;
   dword tc0_512bits_good;
   dword tc0_1024bits_good;
   dword tc0_bad;
   dword tc1_128bits_good;
   dword tc1_256bits_good;
   dword tc1_512bits_good;
   dword tc1_1024bits_good;
   dword tc1_bad;
   dword tc2_128bits_good;
   dword tc2_256bits_good;
   dword tc2_512bits_good;
   dword tc2_1024bits_good;
   dword tc2_bad;
   dword tc3_128bits_good;
   dword tc3_256bits_good;
   dword tc3_512bits_good;
   dword tc3_1024bits_good;
   dword tc3_bad;
   dword tc4_128bits_good;
   dword tc4_256bits_good;
   dword tc4_512bits_good;
   dword tc4_1024bits_good;
   dword tc4_bad;
   dword tc5_512bits_good;
   dword tc5_1024bits_good;
   dword tc5_2048bits_good;
   dword tc5_bad;
   dword tc6_128bits_good;
   dword tc6_256bits_good;
   dword tc6_512bits_good;
   dword tc6_1024bits_good;
   dword tc6_bad;
   dword tc7_512bits_good;
   dword tc7_1024bits_good;
   dword tc7_2048bits_good;
   dword tc7_bad;
   dword tc8_1024bits_good;
   dword tc8_3072bits_good;
   dword tc8_bad;
   dword tc9_512bits_good;
   dword tc9_1024bits_good;
   dword tc9_2048bits_good;
   dword tc9_bad;
   dword tc10_4096bits_good;
   dword tc10_bad;
   dword tc11_1024bits_good;
   dword tc11_3072bits_good;
   dword tc11_bad;
   dword tc12_4096bits_good;
   dword tc12_bad;
   dword tc13_5120bits_good;
   dword tc13_bad;
   dword tc14_5120bits_good;
   dword tc14_bad;

   dword tc0_128bits[16];
   dword tc0_256bits[16];
   dword tc0_512bits[16];
   dword tc0_1024bits[16];
   dword tc1_128bits[16];
   dword tc1_256bits[16];
   dword tc1_512bits[16];
   dword tc1_1024bits[16];
   dword tc2_128bits[8];
   dword tc2_256bits[8];
   dword tc2_512bits[8];
   dword tc2_1024bits[8];
   dword tc3_128bits[4];
   dword tc3_256bits[4];
   dword tc3_512bits[4];
   dword tc3_1024bits[4];
   dword tc4_128bits[2];
   dword tc4_256bits[2];
   dword tc4_512bits[2];
   dword tc4_1024bits[2];
   dword tc5_512bits[4];
   dword tc5_1024bits[4];
   dword tc5_2048bits[4];
   dword tc6_128bits[1];
   dword tc6_256bits[1];
   dword tc6_512bits[1];
   dword tc6_1024bits[1];
   dword tc7_512bits[2];
   dword tc7_1024bits[2];
   dword tc7_2048bits[2];
   dword tc8_1024bits[2];
   dword tc8_3072bits[2];
   dword tc9_512bits[1];
   dword tc9_1024bits[1];
   dword tc9_2048bits[1];
   dword tc10_4096bits[2];
   dword tc11_1024bits[1];
   dword tc11_3072bits[1];
   dword tc12_4096bits[1];
   dword tc13_5120bits[2];
   dword tc14_5120bits[1];
   dword ccsht_128bits_good;
   dword ccsht_256bits_good;
   dword ccsht_512bits_good;
   dword ccsht_bad;
   dword cc38400_good;
   dword cc38400_bad;
   dword cc76800_good;
   dword cc76800_bad;
   dword ccsht_128bits[4];
   dword ccsht_256bits[4];
   dword ccsht_512bits[4];
   dword ccrate38400[16];
   dword ccrate76800[8];
} LOG_1XEVDO_RevA_SU_FWD_Stats_Struct;

/**
Traffic channel formulas:
80-V1294-1 Rev. YH
section 5.3.269.1:
PER:
Througput when served
Instantaneous throughput
Instantaneous throughput 1 sec
*/

/** Structure for log code 0x12A2
1xEV-DO Rev. B multi-carrier single user Forward Statistics Summery
*/
typedef struct
{
   byte version;
   dword log_sequence_number;
   byte carrier_Count;
   byte carrier_id[3];

   dword tc0_128bits_good;
   dword tc0_256bits_good;
   dword tc0_512bits_good;
   dword tc0_1024bits_good;
   dword tc0_bad;
   dword tc1_128bits_good;
   dword tc1_256bits_good;
   dword tc1_512bits_good;
   dword tc1_1024bits_good;
   dword tc1_bad;
   dword tc2_128bits_good;
   dword tc2_256bits_good;
   dword tc2_512bits_good;
   dword tc2_1024bits_good;
   dword tc2_bad;
   dword tc3_128bits_good;
   dword tc3_256bits_good;
   dword tc3_512bits_good;
   dword tc3_1024bits_good;
   dword tc3_bad;
   dword tc4_128bits_good;
   dword tc4_256bits_good;
   dword tc4_512bits_good;
   dword tc4_1024bits_good;
   dword tc4_bad;
   dword tc5_512bits_good;
   dword tc5_1024bits_good;
   dword tc5_2048bits_good;
   dword tc5_bad;
   dword tc6_128bits_good;
   dword tc6_256bits_good;
   dword tc6_512bits_good;
   dword tc6_1024bits_good;
   dword tc6_bad;
   dword tc7_512bits_good;
   dword tc7_1024bits_good;
   dword tc7_2048bits_good;
   dword tc7_bad;
   dword tc8_1024bits_good;
   dword tc8_3072bits_good;
   dword tc8_bad;
   dword tc9_512bits_good;
   dword tc9_1024bits_good;
   dword tc9_2048bits_good;
   dword tc9_bad;
   dword tc10_4096bits_good;
   dword tc10_bad;
   dword tc11_1024bits_good;
   dword tc11_3072bits_good;
   dword tc11_bad;
   dword tc12_4096bits_good;
   dword tc12_bad;
   dword tc13_5120bits_good;
   dword tc13_bad;
   dword tc14_5120bits_good;
   dword tc14_bad;

   dword tc0_128bits[16];
   dword tc0_256bits[16];
   dword tc0_512bits[16];
   dword tc0_1024bits[16];
   dword tc1_128bits[16];
   dword tc1_256bits[16];
   dword tc1_512bits[16];
   dword tc1_1024bits[16];
   dword tc2_128bits[8];
   dword tc2_256bits[8];
   dword tc2_512bits[8];
   dword tc2_1024bits[8];
   dword tc3_128bits[4];
   dword tc3_256bits[4];
   dword tc3_512bits[4];
   dword tc3_1024bits[4];
   dword tc4_128bits[2];
   dword tc4_256bits[2];
   dword tc4_512bits[2];
   dword tc4_1024bits[2];
   dword tc5_512bits[4];
   dword tc5_1024bits[4];
   dword tc5_2048bits[4];
   dword tc6_128bits[1];
   dword tc6_256bits[1];
   dword tc6_512bits[1];
   dword tc6_1024bits[1];
   dword tc7_512bits[2];
   dword tc7_1024bits[2];
   dword tc7_2048bits[2];
   dword tc8_1024bits[2];
   dword tc8_3072bits[2];
   dword tc9_512bits[1];
   dword tc9_1024bits[1];
   dword tc9_2048bits[1];
   dword tc10_4096bits[2];
   dword tc11_1024bits[1];
   dword tc11_3072bits[1];
   dword tc12_4096bits[1];
   dword tc13_5120bits[2];
   dword tc14_5120bits[1];
   byte cc_stats_included;
   //Rest of the log packet is included only if cc_stats_included is 1.
   dword ccsht_128bits_good;
   dword ccsht_256bits_good;
   dword ccsht_512bits_good;
   dword ccsht_bad;
   dword cc38400_good;
   dword cc38400_bad;
   dword cc76800_good;
   dword cc76800_bad;
   dword ccsht_128bits[4];
   dword ccsht_256bits[4];
   dword ccsht_512bits[4];
   dword ccrate38400[16];
   dword ccrate76800[8];
} LOG_1XEVDO_MC_SU_FWD_Stats_Struct;
/**
Traffic channel formulas:
80-V1294-1 Rev. YH
section 5.3.432.1:
PER:
Througput when served
Instantaneous throughput
Instantaneous throughput 1 sec
*/

/** Structure of each carrier ID for log code 0x1296
1xEV-DO Rev. B multi-carrier Airlink Summery
*/
typedef struct
{
   byte carrier_id[3];
   byte per_slot[80]; //Note: ICD 80-V1294-1 Rev. YH has a typo of 3x16, it's indeed 5x16.
   byte per_asp[42];
   byte basp_info;
   dword reserved;
   word num_bad_pkts;//of last 16 packet to compute PER
} LOG_1XEVDO_MC_Air_Link_Summary_Carrier_Struct;

/** Structure for log code 0x1296
1xEV-DO Rev. B multi-carrier Airlink Summery
*/
typedef struct
{
   byte version;
   byte num_carriers;
   byte str;
   byte ref_subaset_locked_mode;
   LOG_1XEVDO_MC_Air_Link_Summary_Carrier_Struct carriers_stat[EVDO_MC_MAX_NUM_CARRIERS];
} LOG_1XEVDO_MC_Air_Link_Summary_Struct;

/**
Structure for an instance of the multi-carriers power in log packet 0x129C
*/
typedef struct
{
   byte CarrierId[3]; //!<' Bit mask identifying the carrier;
   byte PowerInfo;//!<' Bit mask to hold fields of per carrier power information in a packet;
   short TxOpenLoopPower;       //!<' Signed; Tx power determined by the open loop adjust mechanism; in units of 1/256 dBm
   short TxClosedLoopAdjus; //!<' Signed; Tx power determined by the closed loop adjust mechanism; in units of 1/256 dB and in the range of [-128,127] dB
   short TxPilotPower;          //!<' Signed; represents the pilot power that is transmitted over the pilot channel; this is calculated based on the TxOpenLoopPower and the TxClosedLoopAdjust; in units of 1/256 dBm
   short TxTotalPower;      //!<' Signed; register holds the total Tx power as determined by the entire Tx AGC mechanism; in units of 1/256 dBm
   short RxAGC0;                //!<' Signed; represents the field that holds the total receive power as seen by Antenna 0; in units of 1/256 dBm
   short RxAGC1;                //!<' Signed; represents this field that holds the total receive power as seen by the Antenna 1; in units of 1/256 dBm
} LOG_1XEVDO_MC_Power_Carrier_Struct;

/**
Structure for an instance of the multi-carriers in log packet 0x129C
*/
typedef struct
{
   byte Version; //!<' version number
   byte LNAState; //!<' LNA gain state of the log packet
   byte TxEnabled;//!<' number of pilots per frame;
   word Hstr;//!<' current half slot reference count.
   short TotalTxPower; //!<' Total Tx power over all the carriers.
   byte numCarriers; //!<' number of carriers in the log packets.
   LOG_1XEVDO_MC_Power_Carrier_Struct carrier_stat[EVDO_MC_MAX_NUM_CARRIERS];
} LOG_1XEVDO_MC_Power_Struct;

//! Definition of log code for CDMA2000 RF Warmup time
#define EVDO_LOG_CODE_RF_WARMUP_TIME    0x15BF
#define EVDO_LOG_CODE_RF_WARMUP_TIME_MAX_NUM_SUB_PKT 1
/**
Structure of CDMA2000 RF Warmup Time sub pkt struct
*/
typedef struct
{
   //header
   byte pkt_id;
   byte pkt_ver;
   word pkt_size;
   //payload
   byte device;
   dword curr_wu_time;
   dword min_wu_time;
   dword max_wu_time;
   dword avg_wu_time;
   dword expected_wu_time;
   dword histogram_wu_time[21];
   dword wu_count;
   byte lna_state;
   byte lna_gain;
   short rx_agc[4];
} EVDO_LOG_RF_WARMUP_TIME_SUB_PKT_Struct;

/**
Structure of EVDO RF Warmup Time pkt struct
*/
typedef struct
{
   //generic header is not considered as log payload in QMSL
   //   dword len;
   //   dword code;
   //   byte ts[8];//uint64 time stamp
   byte pkt_version;
   byte num_subpkt;
   word hdr_reserved;
   EVDO_LOG_RF_WARMUP_TIME_SUB_PKT_Struct sub_pkt[EVDO_LOG_CODE_RF_WARMUP_TIME_MAX_NUM_SUB_PKT];
} EVDO_LOG_RF_WARMUP_TIME_PKT_Struct;

/******************************************************************************
FTM - EVDO non-signaling
*******************************************************************************/

/**
EVDO Return Status
*/
typedef enum
{
   _FTM_EVDO_CMD_SUCCESS            = 0,        //!<'Indicate Success
   _FTM_EVDO_CMD_INVALID_STATE      = 1,        //!<'Indicates that FTM cannot process the cmd in current state
   _FTM_EVDO_CMD_NO_SUCCESS     = 2         //!<'Indicates faiure
} FTM_EVDO_CMD_STATUS;

/**
EVDO Band Class identifiers for QLIB_FTM_EVDO_PILOT_ACQ

The enumeration values are the same as the band class number.  If an
enumeration is not available for a new band class number then the
an integer with the band class number can be used.

*/
typedef enum
{
   FTM_EVDO_BAND_CLASS_CELLULAR = 0,
   FTM_EVDO_BAND_CLASS_PCS          = 1,
   FTM_EVDO_BAND_BC0    = 0,
   FTM_EVDO_BAND_BC1    = 1,
   FTM_EVDO_BAND_BC2    = 2,
   FTM_EVDO_BAND_BC3    = 3,
   FTM_EVDO_BAND_BC4    = 4,
   FTM_EVDO_BAND_BC5    = 5,
   FTM_EVDO_BAND_BC6    = 6,
   FTM_EVDO_BAND_BC7    = 7,
   FTM_EVDO_BAND_BC8    = 8,
   FTM_EVDO_BAND_BC9    = 9,
   FTM_EVDO_BAND_BC10   = 10,
   FTM_EVDO_BAND_BC11   = 11,
   FTM_EVDO_BAND_BC12   = 12,
   FTM_EVDO_BAND_BC13   = 13,
   FTM_EVDO_BAND_BC14   = 14,
   FTM_EVDO_BAND_BC15   = 15,
   FTM_EVDO_BAND_BC16   = 16,
   FTM_EVDO_BAND_BC17   = 17
} FTM_EVDO_BandClasstype;

/**
EVDO Band Class ACK type for reverse traffic channel identifiers for QLIB_FTM_EVDO_PILOT_ACQ
*/
typedef enum
{
   FTM_EVDO_IS856_COMPLIANT = 0,       //!<' 0 Normal IS-856 operation: early decode enabled; no ACK override
   FTM_EVDO_IS856_NO_ACK,              //!<' 1 IS-856 but with no early termination; early decode disabled
   FTM_EVDO_IS890_MODE_0,              //!<' 2 First  slot decode mode; ACK each slot (test app mode)
   FTM_EVDO_IS890_MODE_1,              //!<' 3 Full packet decode mode; NAK each slot (test app mode)
   FTM_EVDO_IS890A_MODE_ACK_BPSK,      //!<' 4 Always ACK with bipolar keying (BPSK) modulation
   FTM_EVDO_IS890A_MODE_NAK_BPSK,      //!<' 5 Always NAK with bipolar keying (BPSK) modulation
   FTM_EVDO_IS890A_MODE_ACK_OOK,       //!<' 6 Always ACK with on-off keying (OOK) modulation
   FTM_EVDO_IS890A_MODE_NAK_OOK        //!<' 7 Always NAK with on-off keying (OOK) modulation
} FTM_EVDO_MAC_ACK_Mode_Enum;

/**
EVDO dynamic range types

This is a list of dynamic range configurations used for 1xEV-DO non-signaling,
to convert results from AGC units to dB and dBm
*/
typedef enum
{
   FTM_EVDO_NS_DR_85_3,             //!<' 85.3dB dynamic range, min_rssi = -106.0dBm
   FTM_EVDO_NS_DR_102_4             //!<' 102.4dB dynamic range, min_rssi = -115.0dBm
} FTM_EVDO_NS_DR_Types_Enum;

/**
EVDO DRC Length
*/
typedef enum
{
   FTM_EVDO_DRC_1_SLOTS = 0,
   FTM_EVDO_DRC_2_SLOTS,
   FTM_EVDO_DRC_4_SLOTS,
   FTM_EVDO_DRC_8_SLOTS
} FTM_EVDO_DRC_LENGTH_Enum;

/**
EVDO DRC Gating
*/
typedef enum
{
   FTM_EVDO_DRC_CONTINUOUS = 0,
   FTM_EVDO_DRC_DISCONTINOUS
} FTM_EVDO_DRC_GATING_Enum;

/**
EVDO RPC Step
*/
typedef enum
{
   FTM_EVDO_RPC_STEP_HalfdB = 0,
   FTM_EVDO_RPC_STEP_1dB
} FTM_EVDO_RPC_STEP_Enum;

/**
EVDO Transmission mode
*/
typedef enum
{
   FTM_EVDO_HIGH_CAPACITY = 0,
   FTM_EVDO_LOW_LATENCY
} FTM_EVDO_TRANS_MODE_Enum;

/**
EVDO ARQ mode
*/
typedef enum
{
   FTM_EVDO_ARQ_BPSK = 0,
   FTM_EVDO_ARQ_OOK
} FTM_EVDO_ARQ_MODE_Enum;

/**
EVDO Search Window Offsets
Pilot Drop Timer Values
*/

typedef enum
{
   FTM_EVDO_DROPTIMER_100_MS,
   FTM_EVDO_DROPTIMER_1_SEC,
   FTM_EVDO_DROPTIMER_2_SEC,
   FTM_EVDO_DROPTIMER_4_SEC,
   FTM_EVDO_DROPTIMER_6_SEC,
   FTM_EVDO_DROPTIMER_9_SEC,
   FTM_EVDO_DROPTIMER_13_SEC,
   FTM_EVDO_DROPTIMER_19_SEC,
   FTM_EVDO_DROPTIMER_27_SEC,
   FTM_EVDO_DROPTIMER_39_SEC,
   FTM_EVDO_DROPTIMER_55_SEC,
   FTM_EVDO_DROPTIMER_79_SEC,
   FTM_EVDO_DROPTIMER_112_SEC,
   FTM_EVDO_DROPTIMER_159_SEC,
   FTM_EVDO_DROPTIMER_225_SEC,
   FTM_EVDO_DROPTIMER_319_SEC,
   FTM_EVDO_DROPTIMER_MAX_SIZE
} FTM_EVDO_DROP_TIMER_Enum;

/**
EVDO Non-signaling Log types

This is a list of the types of log events that will be monitored during EVDO non-signaling
*/
typedef enum
{
   FTM_EVDO_NS_Log_FingerInfo,              //!<' 1xEV-DO Finger, Ver 2 (LOG_CODE 0x108A)
   FTM_EVDO_NS_Log_AGC_C0,                  //!<' FTM2 log, sub log 5, for Primary AGC
   FTM_EVDO_NS_Log_AGC_C1,                  //!<' FTM2 log, sub log 7, for Diversity AGC
   FTM_EVDO_NS_Log_PER,                 //!<' 1xEV-DO Air Link Summary (LOG_CODE 0x1068), used for PER
   FTM_EVDO_NS_Log_FWD_Stat_Summary,        //!<' 1xEV-DO Forward Statistis Summary (LOG_CODE 0x1084)
   FTM_EVDO_NS_Log_Power_Summary,           //!<' 1xEV-DO Power logs (LOG_CODE 0x1069)
   FTM_EVDO_NS_Log_RevA_SU_FWD_Stat_Summary,    //!<' 1xEV-DO Rev. A Single User Forward Statistis Summary (LOG_CODE 0x1192)
   FTM_EVDO_NS_Log_MC_Airlink_Summary,      //!<' 1xEV-DO Multi-carrier Airlink Summary (LOG_CODE 0x1296)
   FTM_EVDO_NS_Log_MC_SU_FWD_Stat_Summary,      //!<' 1xEV-DO Multi-carrier single user Forward Statistis Summary (LOG_CODE 0x12A2)
   FTM_EVDO_NS_Log_MC_Power_Summary,        //!<' 1xEV-DO Multi-carrier Power (LOG_CODE 0x129C)

   FTM_EVDO_NS_Log_MAX                      //!<' Maximum 3 of logs that are being scanned for
} FTM_EVDO_NS_Log_Types_Enum;

/**
EVDO Non-signaling Event types

This is a list of the types of event types that will be monitored during EVDO non-signaling.

Generally an event is based on reveiving one asynchronous log message + checking the state
of one log sub fields.

*/
typedef enum
{
   FTM_EVDO_NS_Event_Synchronization,       //!<' FingerInfo log, Searcher == "Synchronization" after Aquire Pilot
   FTM_EVDO_NS_Event_Idle,                  //!<' FingerInfo log, Searcher == "Idle" after Aquire system time
   FTM_EVDO_NS_Event_Traffic,               //!<' FingerInfo log, Searcher == "Traffic" after Modulate Reverse Traffic
   FTM_EVDO_NS_Event_Deassign,              //!<' FingerInfo log, Searcher == "Inactive" after Deassign
   //!<' (not working on all targets)

   FTM_EVDO_NS_Event_PrimaryAGC,            //!<' FTM2 log, sub log 5, for Primary AGC
   FTM_EVDO_NS_Event_SecondaryAGC,          //!<' FTM2 log, sub log 7, for Diversity AGC
   FTM_EVDO_NS_Event_PER_Update,            //!<' 1xEV-DO Air Link Summary (LOG_CODE 0x1068), used for PER
   FTM_EVDO_NS_Event_C2I_Update,            //!<' FingerInfo log, C2I updates from individual finger reports
   FTM_EVDO_NS_Event_FWD_Stat_Summary_Update,   //!<' 1xEV-DO Forward Statistis Summary (LOG_CODE 0x1084)
   FTM_EVDO_NS_Event_Power_Update,          //!<' 1xEV-DO Power Logs (LOG_CODE 0x1069)
   FTM_EVDO_NS_Event_RevA_SU_FWD_Stat_Summary_Update,   //!<' 1xEV-DO Rev. A single user Forward Statistis Summary (LOG_CODE 0x1192)
   FTM_EVDO_NS_Event_MC_Airlink_Summary_Update, //!<' 1xEV-DO multi-carrier airlink Summary (LOG_CODE 0x1296)
   FTM_EVDO_NS_Event_MC_SU_FWD_Stat_Summary_Update, //!<' 1xEV-DO multi-carrier single user Forward Statistis Summary (LOG_CODE 0x12A2)
   FTM_EVDO_NS_Event_MC_Power_Update,   //!<' 1xEV-DO multi-carrier power logs (LOG_CODE 0x129C)

   FTM_EVDO_NS_Event_MAX                    //!<' Maximum # of events
} FTM_EVDO_NS_Event_Types_Enum;

/**
Searcher states, as used in the "SrchState" field of 1xEV-DO Finger log (0x108A)
*/
typedef enum
{
   FTM_EVDO_NS_Searcher_Inactive            = 0x00, //!<'  Start (inactive)
   FTM_EVDO_NS_Searcher_Acquisition     = 0x01, //!<'  Acquisition 0x01
   FTM_EVDO_NS_Searcher_Synchronization = 0x02, //!<'  Synchronization 0x02
   FTM_EVDO_NS_Searcher_Idle                = 0x03, //!<'  Idle 0x03
   FTM_EVDO_NS_Searcher_IdleSuspended       = 0x3a, //!<'  Idle suspended 0x3a
   FTM_EVDO_NS_Searcher_IdleOffFreq     = 0x3c, //!<'  Idle off-frequency searching (OFS) 0x3c
   FTM_EVDO_NS_Searcher_Sleep               = 0x3e, //!<'  Sleep 0x3e
   FTM_EVDO_NS_Searcher_Reqacusition        = 0x3f, //!<'  Reacquisition 0x3f
   FTM_EVDO_NS_Searcher_Traffic         = 0x04, //!<'  Traffic 0x04
   FTM_EVDO_NS_Searcher_TrafficSuspended    = 0x4a, //!<'  Traffic suspended 0x4a
   FTM_EVDO_NS_Searcher_Traffic_OFS     = 0x4c, //!<'  Traffic OFS 0x4c
   FTM_EVDO_NS_Searcher_Invalid         = 0xFF  //!<'  Invalid (defined at PC Library level, not embedded)
} FTM_EVDO_NS_SearcherStates_Enum;

/**
Structure to contain statistics about the EVDO AGC History for either Primary or diversity AGC.

One instance of this structure will be created for both "sums" and "averages"
for both antenna 0 and antenna 1.  This means that a total of 4 will be available:
1) C0 Sums
2) C0 Averages
3) C1 Sums
4) C1 Averages

For the following fields, when averages are calculated, the fields are converted to dB:
double dTxGainAdj;              //!< tx_gain_adj;

For the following fields, when averages are calculated, the fields are converted to dBm:
double dRxAGC;                  //!< rx_agc field for C0 and rx_agc_c1 for C1 logs
double dTxGainCtl;              //!< tx_gain_ctl field
double dTxOpenLoop;             //!< tx_open_loop;
*/
typedef struct
{
   dword iTotalRecords; //!< Total number of AGC records that have been received

   double dRxAGC;                   //!< rx_agc field for C0 and rx_agc_c1 for C1 logs -- AGC units
   double dRxAGC_linear;            //!< Linear power (mW)
   double dRxAGC_dBm;               //!< Log power (dBm)

   double dTxGainCtl;               //!< tx_gain_ctl field -- AGC units
   double dTxGainCtl_linear;        //!< Linear power (mW)
   double dTxGainCtl_dBm;           //!< Log power (dBm)

   double dTxGainAdj;               //!< tx_gain_adj -- AGC units
   double dTxGainAdj_dB;            //!< Log power (dB)

   double dTxOpenLoop;              //!< tx_open_loop -- AGC units
   double dTxOpenLoop_linear;       //!< Linear power (mW)
   double dTxOpenLoop_dBm;          //!< Log power (dBm)

   double dTxAgcAdj;                //!< tx_agc_adj -- AGC units

   double dPA_Ratchet;              //!< pa_ratchet;
   double dLNA_State;               //!< lna_state for C0 and lna_state_c1 for C1
   double dPA_State;                //!< pa_state
   double dHDET_Raw;                //!< hdet_raw;
   double dThermRaw;                //!< therm_raw;
   double dThermScaled;             //!< therm_scaled;
   double dTempIndex;               //!< temp_index
   double dTempRemainder;           //!< temp_remainder
   double dIntelliceiverState;      //!< intelliceiver_state, only for C0
   double dHDET_V2;                 //!< hdet_v2;
   double dPaSmpsPdm;               //!< smps pdm;
} FTM_EVDO_NS_AGC_Statistics;

/**
Structure to contain statistics about the C/I measurements
*/
typedef struct
{
   dword iTotalReports;         //!< Total # of C/I reports, each report hold 16 packet results

   long iSumC2I;                    //!< Sum of all combined CtoI reports
   double dC2I_dB;                  //!< Calculated Combined C2I, C_I0 (dB) = 10 x Log10 (C2I/512)

   long iSumC2I_C0;             //!< Sum of all CtoI reports for primary antenna
   double dC2I_C0_dB;               //!< Calculated C2I for primary antenna, C_I0 (dB) = 10 x Log10 (C2I/512)

   dword iSumC2I_C1;                //!< Sum of all CtoI reports for diversity antenna
   double dC2I_C1_dB;               //!< Calculated C2I for diversity antenna, C_I0 (dB) = 10 x Log10 (C2I/512)
} FTM_LOG_EVDO_CtoI_Statistics_Struct;

/**
Structure of the log message 0x1068, 1xEV-DO Air Link Summary
*/
typedef struct
{
   byte CDRCBuffer[8];          //!<' DRC indices predicted by the predictor for the 16 slots of
   //!<' the previous frames. Each DRC index is 4 bits. Two DRC
   //!<' indices are combined into 1 byte.

   word BestASPSINRBuffer[16];  //!<' SINR for the BEST ASP for previous frames last 16 odd
   //!<' half slots. This represents for both the antennas.
   byte Flags;                  //!<' PktRcvdFlag, PAState, BestASPPredicted

   word ASPFilteredSINR[6]; //!<' Filtered SINR for the 6 ASPs [1,6]

   word PilotPNASP[6];          //!<' Pilot PN for the 6 ASPs [1,6]

   short RPC[6];                //!<' Filtered RPC values read from the DSP for six possible
   //!<' ASPs [1,6]. RPC[..] values are IIR filtered by the DSP
   //!<' over past 64 samples.

   short PERInst;               //!<' Instantaneous Packet Error Rate. This value is calculated
   //!<' once every 16 packets are received.
   //!<' PERInst = Number of bad packets / 16; 16384 = 100%

   word PERSequence;            //!<' Packet Error Rate sequence. This represents the number
   //!<' of times the PERInstantaneous value is calculated.

   word HSTR;                   //!<' Current half slot reference count (DSP register)

   byte RPCCellIndex[6];        //!<' RPC Cell map for each ASP index
} LOG_1XEVDO_Air_Link_Summary_Struct;

/**
Structure to contain statistics about the EVDO PER History,
from (event == FTM_EVDO_NS_Event_PER_Update)
*/
typedef struct
{
   dword iTotalReports;     //!< Total # of PER reports, each report hold 16 packet results

   dword iTotalPackets;     //!< Total # of packets that are included

   double dSumOfPER;            //!< Total of all instantaneous (kept in "bad packets/16" units)

   /*
   Calculated "PER short" average based on all the PER reports and adjusted for 16 packets per report

   */
   double dPER_Calculated;

   dword iBandClass; //! band class of the carrier that reports this PER statistic, valid only for multi-carrier log code 0x1296

   word iChannel;//! channel number of the carrier that reports this PER statistic, valid only for multi-carrier log code 0x1296

   /*
   Calculated EVDO best ASP SINR in dB.
   The BestASPSINRBuffer[0 ... 15] from 1xEV-DO Air Link Summary (LOG_CODE 0x1068)
   is averaged over the 16 half slots, then converted to dB with equation
   10*log10(BestASPSINRBuffer_Average/512)
   currently only implemented for Rev.0/A, must have FTM_EVDO_NS_Log_PER statistics enabled to get a valid reading.
   */
   double dBestAspSinrAverage;
   double dBestAspSinrSum_Raw;//raw data, average of all SINR over 16 half slots, then sum over all log records received.
} FTM_EVDO_NS_PER_Statistics_Struct;

/**
Structure to contain statistics about the EVDO Power history.
Calculated based on Rev.0/A evdo power log 0x1069
*/
typedef struct
{
   dword iTotalReports; // each report contains 2 packets for 0x1069; 1 packet for 0x129C
   dword iTotalPackets;
   double RxAGC0;
   double RxAGC1;
   double TxOpenLoopPower;
   double TxClosedLoopAdjus;
   double TxTotalPower;
   double TxPilotPower;
   double RxAGC0_Linear_sum;
   double RxAGC1_Linear_sum;
   double TxOpenLoopPower_Linear_sum;
   double TxClosedLoopAdjus_Linear_sum;
   double TxTotalPower_Linear_sum;
   double TxPilotPower_Linear_sum;

   /*pa_state: valid only Rev.0/A log code 0x1069:
   ATType [Bit3:Bit0] gives the type of the AT unit: 1 ?MSM4500; 2 ?MSM5500
   RatchetMode [Bit4] register shows the state of the Tx power limiting: 0 ?Tx power not limitedl;1 ?Tx power is limited
   PAState [Bit5] gives the state of the power amplifier 0 ?PA off; 1 - PA on.
   for Rev. B multi-carrier log code 0x129C
   note: this field doesn't do averaging. if multiple logs are received, the last sample is used.
   */
   byte pa_state;
   /*PowerInfo: valid only Rev.B log code 0x129C:
   Bit 0 ?Register shows the state of the Tx power limiting: 0 ?Tx power not limited;. 1 ?Tx power is limited
   Bit 1 ?State of the power amplifier: 0 ?PA Off; 1 ?PA On;
   Bits 7:2 ?Reserved bits
   note: this field doesn't do averaging. if multiple logs are received, the last sample is used.
   */
   byte PowerInfo;
   /*LNAState: valid only Rev.B log code 0x129C:
   LNA gain state
   note: this field doesn't do averaging. if multiple logs are received, the last sample is used.
   */
   byte LNAState;

   dword iBandClass; //! band class of the carrier that reports this statistic, valid only for multi-carrier log code 0x129C
   word iChannel;//! channel number of the carrier that reports this statistic, valid only for multi-carrier log code 0x129C

   double RxAGC0_min;//! in dBm
   double RxAGC0_max;//! in dBm
   double RxAGC1_min;//! in dBm
   double RxAGC1_max;//! in dBm
   double TxTotalPower_min;//! in dBm
   double TxTotalPower_max;//! in dBm
} FTM_EVDO_NS_Power_Statistics_Struct;

/**
Structure to contain statistics about the EVDO Throughput history.
Calculated based on Rev.0/A/B single user forward statistics summary
*/
typedef struct
{
   dword iTotalReports;
   dword iTotalPackets;
   double dThroughputWhenServed;
   double dThroughputInst;
   double dThroughputInst_1s;
   double dPacketErrorRate;
   double dPacketErrorRate_1s;
   dword seq_num;
   dword seq_num_prev;
   dword iBandClass; //! band class of the carrier that reports this throughput statistic, valid only for multi-carrier log code 0x12A2
   word iChannel;//! channel number of the carrier that reports this throughput statistic, valid only for multi-carrier log code 0x12A2
} FTM_EVDO_NS_Throughput_Statistics_Struct;

/**
Searcher states, as used in the "SrchState" field of 1xEV-DO Finger log (0x108A)
*/
typedef struct
{
   //! Array to keep track of whether a certain event has occured, indexed to FTM_EVDO_NS_Event_Types_Enum
   byte bHasUpdated[ FTM_EVDO_NS_Event_MAX ];

   /**
   Finger information
   */
   FTM_EVDO_NS_SearcherStates_Enum eSearcherState;

   FTM_LOG_EVDO_CtoI_Statistics_Struct oEVDO_LatestCtoI_Stats;  //!<' Most recent CtoI report
   FTM_LOG_EVDO_CtoI_Statistics_Struct oEVDO_CtoI_Stats;        //!<' Average CtoI

   /**
   Data for primary AGC
   */
   FTM_LOG_EVDO_AGC_C0_Struct oEVDO_AGC_C0;             //!<' Most recent Primary AGC information
   FTM_EVDO_NS_AGC_Statistics oEVDO_AGC_C0_LatestStats; //!<' Most recent primary AGC report, converted to dBm
   FTM_EVDO_NS_AGC_Statistics oEVDO_AGC_C0_SumStats;        //!<' Sums Primary AGC
   FTM_EVDO_NS_AGC_Statistics oEVDO_AGC_C0_AvgStats;        //!<' Averages for Primary AGC

   /**
   Data for seC0ndary AGC
   */
   FTM_LOG_EVDO_AGC_C1_Struct oEVDO_AGC_C1;             //!<' Most recent secondary AGC information
   FTM_EVDO_NS_AGC_Statistics oEVDO_AGC_C1_LatestStats; //!<' Most recent secondary AGC report, converted to dBm
   FTM_EVDO_NS_AGC_Statistics oEVDO_AGC_C1_SumStats;        //!<' Sums for secondary AGC
   FTM_EVDO_NS_AGC_Statistics oEVDO_AGC_C1_AvgStats;        //!<' Averages for secondary AGC

   /**
   Data for PER (event == FTM_EVDO_NS_Event_PER_Update)
   */
   word iLastInstantaneousPER;                      //!<' Most recent instantaneous PER recorded,
   //!<' PERInst = Number of bad packets / 16, 16384 = 100%

   FTM_EVDO_NS_PER_Statistics_Struct oPER_Stats;    //!<' PER Statistics

   /**
   Last received Air Link Summary log message
   */
   LOG_1XEVDO_Air_Link_Summary_Struct oAirLinkSummary;

   /**
   Last received EVDO Forward Statistics Summary
   */
   LOG_1XEVDO_Forward_Statistics_Summary_Struct oFWDStatSummary;//!<' Most recent forward statistics
   LOG_1XEVDO_Forward_Statistics_Summary_Struct oFWDStatSummary_Prev;//!<'  Second latest packet

   FTM_EVDO_NS_Throughput_Statistics_Struct oThroughput_Stats;
   /**
   Last received EVDO Power. Each log report includes two packets
   */
   LOG_1XEVDO_Power oPower[2];

   FTM_EVDO_NS_Power_Statistics_Struct oPower_Stats;

   /**
   Last received EVDO Rev. A Single User Forward Statistics Summary
   */
   LOG_1XEVDO_RevA_SU_FWD_Stats_Struct oRevAFWDStatSummary; //!<' Most recent Rev. A Single User forward statistics
   LOG_1XEVDO_RevA_SU_FWD_Stats_Struct oRevAFWDStatSummary_Prev;//!<'  Second latest packet

   FTM_EVDO_NS_Throughput_Statistics_Struct oThroughput_Stats_RevA;
   /**
   Last received EVDO Multi-carrier Single User Forward Statistics Summary
   */
   LOG_1XEVDO_MC_SU_FWD_Stats_Struct oMCFWDStatSummary[EVDO_MC_MAX_NUM_CARRIERS];//!<' Most recent Rev. B MC Single User forward statistics
   LOG_1XEVDO_MC_SU_FWD_Stats_Struct oMCFWDStatSummary_Prev[EVDO_MC_MAX_NUM_CARRIERS];//!<' Second latest forward statistics

   FTM_EVDO_NS_Throughput_Statistics_Struct oMCThroughput_Stats[EVDO_MC_MAX_NUM_CARRIERS];//!<' Throughput Statistics for MC carrier 1 - 3.

   /**
   Last received EVDO Multi-carrier Airlink Summary
   */
   LOG_1XEVDO_MC_Air_Link_Summary_Struct oMCAirLinkSummary;
   FTM_EVDO_NS_PER_Statistics_Struct oMCPER_Stats[EVDO_MC_MAX_NUM_CARRIERS];    //!<' PER Statistics for MC carrier 1 - 3.

   /**
   Last received EVDO Multi-carrier Power
   */
   LOG_1XEVDO_MC_Power_Struct oMCPower;
   FTM_EVDO_NS_Power_Statistics_Struct oMCPower_Stats[EVDO_MC_MAX_NUM_CARRIERS];
} FTM_EVDO_NS_Status_Struct;

//! Define for the bWaitForStatus flag for the EVDO NS functions -- indicate wait for status
#define FTM_EVDO_NS_WaitForStatus TRUE

//! Define for the bWaitForStatus flag for the EVDO NS functions -- indicate no wait for status
#define FTM_EVDO_NS_NoWaitForStatus FALSE

/**
Bit mask enumeration of measurement logs available for 1XEVD0 non-signaling
*/
typedef enum
{
   FTM_EVDO_NS_LOG_AIR_LINK_SUMMARY = 0x0001,  //!<'  Air link summary 0x1068
   FTM_EVDO_NS_LOG_AGC_C0           = 0x0002,  //!<'  FTM AGC Log for primary Rx (C0)
   FTM_EVDO_NS_LOG_AGC_C1           = 0x0004,  //!<'  FTM AGC Log for secondary Rx (C1)
   FTM_EVDO_NS_LOG_Default          = 0x0003,  //!<'  Default is to include all logs air link summary and AGC Primary Chain FTM logs.
   FTM_EVDO_NS_LOG_POWER             = 0x0008,  //!<'  Power Logs 0x1069
   FTM_EVDO_NS_LOG_FWD_STAT          = 0x0010,  //!<'  Forward statistics summary 0x1084
   FTM_EVDO_NS_LOG_REVA_SU_FWD_STAT = 0x0020,  //!<'  Rev. A Single User forward statistics summary 0x1192
   FTM_EVDO_NS_LOG_MC_AIR_LINK       = 0x0040,  //!<'  Rel. B Multi-carrier airlink summary 0x1296
   FTM_EVDO_NS_LOG_MC_SU_FWD_STAT   = 0x0080,  //!<'  Rev. B Multi-carrier Single User forward statistics summary 0x12A2
   FTM_EVDO_NS_LOG_MC_POWER      = 0x0100,  //!<'  Rev. B Multi-carrier Power 0x129C
   FTM_EVDO_NS_LOG_ALL               = 0xFFFB   //!<'  All log codes available for EVDO(excluding Secondary chain FTM AGC log)
} FTM_EVDO_NS_MeasurementLogs_Enum;

/******************************************************************************
FTM - SV
*******************************************************************************/

/******************************************************************************
Diagnostic - SHDR/SGPS subsytem
*******************************************************************************/
/**
Bit mask enumeration of measurement logs available for 1XEVD0 non-signaling
*/
typedef enum
{
   SHDR_LOG_TRM_RESPONSE        = 1,  //!<'  TRM Response Log
   SHDR_LOG_1x_PSER          = 2,  //!<'  1x Paging SER
   SHDR_LOG_1x_DEMOD_RF_SUBPKT   = 4,  //!<'  Information from the Demod Status Log: RF SubPacket
   SHDR_LOG_1x_STATUS            = 8,   //<'  1x Status Logs
   SHDR_LOG_EVDO_POWER           = 16,  //!<'  EVDO Power Log
   SHDR_LOG_EVDO_STATUS      = 32,
   SHDR_LOG_EVDO_FINGER      = 64,  //!<' EVDO Finget Log Packet
   SHDR_LOG_CGPS                 = 128, //<!<' All CGPS Logs
} FTM_SHDR_MeasurementLogs_Enum;

typedef struct
{
   CDMA2000_TRM_Log_Header oTRMLogs [ CDMA2000_TRM_LOG_PACKET_BUFFER_SIZE ];
   double oPagingSER;
   long oPagingSER_NumOfSymbols;
   FTM_CDMA2000_NS_Status_Struct oCDMA2000_Status;
   FTM_EVDO_NS_Status_Struct oEVDO_Staus;
   CDMA2000_Demod_RF_Stat oDemodRFStatus;
   int iTotalTRMRecords;
   CGPS_Status_Struct oCGPS_Status;
   int iTimeout_ms;
   int iTotalDemodRFStatusRecord;
} SHDR_SGPS_MeasurementLogs_Struct;

/******************************************************************************
FTM - Bluetooth
*******************************************************************************/

/**
\brief Enumeration of Bluetooth FTM Command ID's
*/
typedef enum
{
   _FTM_BT_HCI_USER_CMD     = 0     //!<' Bluetooth HCI User Command.  Use _ to avoid name conflict with function
} FTM_Bluetooth_Cmd_Id_Enum;

/**
The maximum number of bytes in a Bluetooth FTM payload (transport mode (1 byte) + HCI event header (2 byte) + HCI event payload (255) = 258)
*/
#define FTM_BLUETOOH_LOG_PAYLOAD_MAX_SIZE 258

/**
The maximum number of Bluetooth FTM Logs
*/
#define FTM_BLUETOOTH_LOG_MAX_LOGS  255

/**
A Bluetooth FTM Log
*/
typedef struct
{
   byte iTimeStamp[QMSL_DIAG_TIME_STAMP_SIZE];                                  //!<' AMSS timestamp

   unsigned char aBluetooh_FTM_Log_Payload[FTM_BLUETOOH_LOG_PAYLOAD_MAX_SIZE];  //!<' Bluetooth FTM log payload

   unsigned short iBluetooth_FTM_Load_Payload_Size;                         //!<' Size of Bluetooth FTM log payload
} FTM_Bluetooth_Log;

/**
This buffer stores the Bluetooth FTM logs
*/
typedef struct
{
   FTM_Bluetooth_Log aBluetooh_FTM_Logs [FTM_BLUETOOTH_LOG_MAX_LOGS];           //!<' Array of FTM logs

   unsigned short iNumFTMBluetoothLogs;                                     //!<' Number of valid Bluetooth FTM logs in aBluetooth_FTM_Logs

   unsigned char  bBufferFull;                                                  //!<' 1 indicates the internal buffer is full. Bluetooth FTM logs may have been discarded.  0 indicates the buffer is not full
} FTM_Bluetooth_Logs;

/******************************************************************************
FTM - ANT
*******************************************************************************/
/**
\brief FTM command IDs for FTM ANT subystem
Use _ to differentiate from the function names
This enum is only for QMSL internal use.
Embedded side daemon strips off this byte.
*/
typedef enum
{
   _FTM_ANT_RESET                       =  1,   //!<' Reset ANT stack
   _FTM_ANT_ASSIGN_LOGICAL_CHANNEL      =  2,   //!<' Assign logical channel
   _FTM_ANT_SET_LOGICAL_CHANNEL_ID      =  3,   //!<' Set logical channel ID
   _FTM_ANT_SET_RF_CHANNEL              =  4,   //!<' Set RF channel
   _FTM_ANT_SET_MESSAGE_PERIOD          =  5,   //!<' Set message period
   _FTM_ANT_SET_DATA_PAYLOAD            =  6,   //!<' Set data payload
   _FTM_ANT_SET_TX_POWER                =  7,   //!<' Set transmit power
   _FTM_ANT_START_TEST                  =  8,   //!<' Start test
   _FTM_ANT_RESET_TEST                  =  9,   //!<' Reset test
   _FTM_ANT_GET_RX_TEST_RESULT_STATUS   = 10,   //!<' Get Rx test result status
   _FTM_ANT_GET_TX_TEST_RESULT_STATUS   = 11,   //!<' Get Tx test result status
} FTM_ANT_Command_ID_Enum;

/**
The maximum number of bytes in an ANT FTM payload (transport mode (1 byte) + HCI event header (2 byte) + HCI event payload (255) = 258)
*/
#define FTM_ANT_LOG_PAYLOAD_MAX_SIZE 258

/**
The maximum number of Bluetooth FTM Logs
*/
#define FTM_ANT_LOG_MAX_LOGS    255

/**
ANT FTM Log
*/
typedef struct
{
   byte iTimeStamp[QMSL_DIAG_TIME_STAMP_SIZE];                                  //!<' AMSS timestamp

   unsigned char aANT_FTM_Log_Payload[FTM_ANT_LOG_PAYLOAD_MAX_SIZE];    //!<' ANT FTM log payload

   unsigned short iANT_FTM_Load_Payload_Size;                           //!<' Size of ANT FTM log payload
} FTM_ANT_Log;

/**
This buffer stores the ANT FTM logs
*/
typedef struct
{
   FTM_ANT_Log aANT_FTM_Logs [FTM_ANT_LOG_MAX_LOGS];            //!<' Array of FTM logs

   unsigned short iNumFTMANTLogs;                                       //!<' Number of valid Bluetooth FTM logs in aANT_FTM_Logs

   unsigned char  bBufferFull;                                                  //!<' 1 indicates the internal buffer is full. ANT FTM logs may have been discarded.  0 indicates the buffer is not full
} FTM_ANT_Logs;

/******************************************************************************
WCNSS Audio Logs
*******************************************************************************/

#define LOG_CODE_WCNSS_AUDIO    0x1558  //!<' WCNSS Audio Log Packets

/**
The maximum number of audio payload bytes in a WCNSS Audio Log
*/
#define WCNSS_AUDIO_LOG_PAYLOAD_MAX_SIZE 960// current FM audio packets have 480 bytes of payload. 960 allows for a 2x increase in packet size (at half the rate)

/**
The maximum number of WCNSS Audio Logs to store
*/
#define WCNSS_AUDIO_LOG_MAX_LOGS    4096 // current packet rate is 400 packets per second. this buffer size determines how much audio can be recorded. 4096 should give slightly over 10 seconds of data

/**
The FM AUDIO SAMPLE RATE
*/
#define FM_AUDIO_SAMPLE_RATE 48000

/**
The FM STEREO AUDIO BYTE RATE
*/
#define FM_STEREO_AUDIO_BYTE_RATE 192000

/**
Enumeration of WCNSS Audio Sources
*/
typedef enum
{
   _RIVA_AUDIO_LOG_SRC_BT_VOICE_SPEAKER         = 0x00001000,   //!<' BT VOICE SPEAKER
   _RIVA_AUDIO_LOG_SRC_BT_VOICE_MIC             = 0x00001001,   //!<' BT VOICE MIC
   _RIVA_AUDIO_LOG_SRC_BT_A2DP                  = 0x00001002,   //!<' BT A2DP
   _RIVA_AUDIO_LOG_SRC_FM_RX                    = 0x00001003,   //!<' FM RX
   _RIVA_AUDIO_LOG_SRC_FM_TX                    = 0x00001004    //!<' FM TX
} WCNSS_AUDIO_SOURCE_Enum;

/**
Enumeration of WCNSS Audio Formats
*/
typedef enum
{
   _RIVA_AUDIO_LOG_FMT_PCM          = 0,    //!<' 16-bit PCM, 2's complement signed values  in little endian format
   _RIVA_AUDIO_LOG_FMT_CVSD         = 1,    //!<' 8-bit CVSD compressed audio
   _RIVA_AUDIO_LOG_FMT_MSBC         = 2     //!<' 16-bit MSBC compressed audio
} WCNSS_AUDIO_FORMAT_Enum;

/**
Enumeration of WCNSS Audio Direction
*/
typedef enum
{
   _RIVA_AUDIO_LOG_RX           = 0,        //!<' RX
   _RIVA_AUDIO_LOG_TX           = 1         //!<' TX
} WCNSS_AUDIO_DIRECTION_Enum;

/**
A WCNSS Audio Log
*/
typedef struct
{
   byte iTimeStamp[QMSL_DIAG_TIME_STAMP_SIZE];                  //!<' AMSS timestamp

   unsigned int iPacketVersion;                                 //!<' WCNSS Audio packet version

   unsigned int iAudioSource;                                   //!<' Audio Source (see enum WCNSS_AUDIO_SOURCE_Enum)

   unsigned int iAudioFormat;                                   //!<' Audio Format (see enum WCNSS_AUDIO_FORMAT_Enum)

   unsigned int iDirection;                                     //!<' Audio Direction (see enum WCNSS_AUDIO_DIRECTION_Enum)

   unsigned int iSampleRate;                                    //!<' Audio Sample Rate

   unsigned int iChannelCount;                                  //!<' Audio Channel Count (1=mono, 2=stereo)

   unsigned int iPayloadSize;                                   //!<' Size of Audio data payload (header fields NOT ncluded)

   unsigned char aPayload[WCNSS_AUDIO_LOG_PAYLOAD_MAX_SIZE];    //!<' WCNSS Audio log payload
} WCNSS_Audio_Log;

/**
This buffer stores the WCNSS Audio logs
*/
typedef struct
{
   WCNSS_Audio_Log aWCNSS_Audio_Log[WCNSS_AUDIO_LOG_MAX_LOGS];  //!<' Array of WCNS Audio logs

   unsigned int iNumWCNSSAudioLogs;                             //!<' Number of valid WCNSS Audio logs in aWCNSS_Audio_Log

   unsigned int iTotalPayloadSize;                              //!<' Accumulative payload size from all buffered WCNSS Audio logs in aWCNSS_Audio_Log

   unsigned char  bBufferFull;                                  //!<' 1 indicates the internal buffer is full. WCNSS Audio logs may have been discarded.  0 indicates the buffer is not full
} WCNSS_Audio_Logs;

/******************************************************************************
FTM - AGPS
*******************************************************************************/

/**
\brief Enumeration of AGS FTM Command ID's
Use _ to differentiate from the function names
*/
typedef enum
{
   _FTM_AGPS_SET_TEST_MODE          = 0,    //!<' Set AGPS Test Mode
   _FTM_AGPS_SELF_TEST              = 1,    //!<' AGPS Self Test
   _FTM_AGPS_IDLE_MODE              = 2,    //!<' Set AGPS Idle Mode
   _FTM_AGPS_STANDALONE_TEST_MODE   = 3,    //!<' Set AGPS Standalone Test Mode
   _FTM_AGPS_SV_TRACKING            = 4,    //!<' Set AGPS single SV tracking
   _FTM_AGPS_IQ_CAPTURE         = 5,    //!<' Set AGPS IQ Capture
   _FTM_AGPS_GET_IQ_DATA            = 6,        //!<' Set AGPS Get IQ data
   _FTM_AGPS_GET_CTON               = 122   //!<' Get AGPS C/N
} FTM_AGPS_Cmd_Id_Enum;

/******************************************************************************
FTM - PMIC
*******************************************************************************/
/**
FTM Subsystem dispatcher header, response with extended information + status
*/
typedef struct
{
   ftm_extended_request_header_type ftm_extended_header;
   byte status;
} ftm_pmic_response_header_type;

/**
\brief Enumeration of PMIC sub Command ID's
*/
typedef enum
{
   _FTM_PMIC_TEST_RTC       = 0,    //!<' PMIC Real Time Clock
   _FTM_PMIC_TEST_CHG       = 1,    //!<' PMIC Charger control
   _FTM_PMIC_TEST_USB       = 2,    //!<' PMIC USB
   _FTM_PMIC_TEST_AMUX      = 3,    //!<' PMIC Analog Multiplexer
   _FTM_PMIC_TEST_VREG      = 4,    //!<' PMIC Voltage Regulator
   _FTM_PMIC_TEST_INT       = 5,    //!<' PMIC Interrupts
   _FTM_PMIC_TEST_UI        = 6,    //!<' PMIC User Interface Commands
   _FTM_PMIC_TEST_SPKR      = 8,    //!<' PMIC Speakers
   _FTM_PMIC_TEST_VID       = 9,    //!<' PMIC Video amplifier (VID)
   _FTM_PMIC_TEST_MIC       = 10,   //!<' PMIC Microphone commands
   _FTM_PMIC_TEST_RESET = 11,   //!<' PMIC Hard reset command resets all of the PMIC hardware blocks, excluding the RTC
   _FTM_PMIC_TEST_MPP       = 12,   //!<' PMIC Test Multi-purpose Pin (MPP)
   _FTM_PMIC_TEST_GEN       = 13,   //!<' PMIC General testing
   _FTM_PMIC_TEST_VREG_EXT  = 15   //!<' PMIC Voltage Regulator Extended (use VREG enum)
} FTM_PMIC_Cmd_Id_Enum;

/**
\brief Enumeration of PMIC FTM Sub-command ID's
*/
typedef enum
{
   // FTM_PMIC_TEST_RTC group
   _FTM_PMIC_RTC_SET_GET_TIME           = 0,    //!<' PMIC RTC Set/Get time
   _FTM_PMIC_RTC_SET_GET_ALARM_TIME = 1,    //!<' PMIC RTC Set/Get alarm
   _FTM_PMIC_RTC_STOP                   = 2,    //!<' PMIC RTC Stop real time clock
   _FTM_PMIC_RTC_GET_ALARM_STATUS       = 3,    //!<' PMIC RTC Get alarm status
   _FTM_PMIC_RTC_DISABLE_ALARM          = 4,    //!<' PMIC RTC Disable Alarm
   _FTM_PMIC_RTC_SET_GET_TIME_ADJUST    = 5,    //!<' PMIC RTC Get/set time adjustment

   // Charger Commands
   _FTM_PMIC_CHG_SET_SWITCH_STATE       = 0,    //!<' PMIC Charger, Set switch state
   _FTM_PMIC_CHG_SET_CONFIG         = 1,    //!<' PMIC Charger, configure

   // Analog Mux
   _FTM_PMIC_AMUX_CONFIG                = 0,        //!<' PMIC Analog Mux, Configure

   // Voltage Reglator
   _FTM_PMIC_VREG_CONTROL               = 0,    //!<' PMIC Vreg, Control LDO
   _FTM_PMIC_VREG_SET_LEVEL         = 1,    //!<' PMIC Vreg, Set voltage level
   _FTM_PMIC_VREG_CONFIG_SMPS_MODE      = 2,    //!<' PMIC Vreg, configure SMPS mode
   _FTM_PMIC_VREG_CONFIG_LDO_PD_SW      = 3,    //!<' PMIC Vreg, Configure LDO Power Down
   _FTM_PMIC_VREG_LP_MODE_CONTROL       = 4,    //!<' PMIC Vreg, Configure Low Power mode

   _FTM_PMIC_VREG_SMPS_CLK_CONFIG       = 5,    //!<' PMIC Vreg, Configure SMPS clock
   _FTM_PMIC_VREG_GET_LEVEL         = 6,    //!<' PMIC Vreg, Get voltage level
   _FTM_PMIC_VREG_GET_ENUM_LIST     = 7,    //!<' PMIC Vreg, Get a list of vreg enumeration

   // Interrupts
   _FTM_PMIC_INT_GET_RT_STATUS          = 0,    //!<' PMIC Interrupt, Get interrupt status
   _FTM_PMIC_INT_CLR_IRQ                = 1,    //!<' PMIC Interrupt, clear interrupts

   // User Interface
   _FTM_PMIC_UI_SET_DRIVE_LEVEL     = 0,    //!<' PMIC User Interface, set drive level
   _FTM_PMIC_UI_CONFIG_SPKR         = 1,    //!<' PMIC User Interface, configure speaker

   // MIC Interface
   _FTM_PMIC_MIC_DISABLE                = 0,    //!<' PMIC MIC, MIC disable
   _FTM_PMIC_MIC_ENABLE             = 1,    //!<' PMIC MIC, MIC enable
   _FTM_PMIC_MIC_GET_STATUS         = 2,    //!<' PMIC MIC, Get Stats
   _FTM_PMIC_MIC_SET_LEVEL              = 3,    //!<' PMIC MIC, Set voltage level
   _FTM_PMIC_MIC_GET_LEVEL              = 4,    //!<' PMIC MIC, Get voltage level

   // Speaker
   _FTM_PMIC_SPKR_SET_GET_HPF_CORNER_FREQ = 0,  //!<' PMIC Speaker HPF Corner freq

   // Hard reset
   _FTM_PMIC_HARD_RESET             = 0,    //!<' PMIC Hard reset

   // MPP
   _FTM_PMIC_MPP_CONFIG_DIGITAL_IN      = 0,    //!<' PMIC MPP, Config digital input pin
   _FTM_PMIC_MPP_CONFIG_DIGITAL_OUT = 1,    //!<' PMIC MPP, Config digital output pin
   _FTM_PMIC_MPP_CONFIG_DIGITAL_INOUT   = 2,    //!<' PMIC MPP, Config digital bidirectional pin
   _FTM_PMIC_MPP_CONFIG_ANALOG_IN       = 3,    //!<' PMIC MPP, Config analog input pin
   _FTM_PMIC_MPP_CONFIG_ANALOG_OUT      = 4,    //!<' PMIC MPP, Config analog output pin
   _FTM_PMIC_MPP_CONFIG_I_SINK          = 5,    //!<' PMIC MPP, Config a pin to be current sink

   // General
   _FTM_PMIC_GET_MODEL                  = 0     //!<' PMIC General, Get Model
} FTM_PMIC_SubCmd_Id_Enum;

typedef enum
{
   // FTM_PMIC_TEST_RTC group
   FTM_PMIC_SET_VALUE = 0,  //!<' PMIC Set value
   FTM_PMIC_GET_VALUE = 1   //!<' PMIC Get value
} FTM_PMIC_SET_GET_Enum;

/* This type specifies the charger switch types available to control */

typedef enum
{
   FTM_PMIC_CHG_SWITCH_WALL_CHGR            = 0,
   FTM_PMIC_CHG_SWITCH_BATTERY_TRANSISTOR   = 1,
   FTM_PMIC_CHG_SWITCH_WALL_PULSE_CHGR      = 2,
   FTM_PMIC_CHG_SWITCH_VCP                  = 3,
   FTM_PMIC_CHG_SWITCH_BATT_ALARM           = 4,
   FTM_PMIC_CHG_SWITCH_COIN_CELL            = 5,
   FTM_PMIC_CHG_SWITCH_USB_CHGR             = 6,
   FTM_PMIC_CHG_SWITCH_CHG_APP              = 7,      //!<' Charger Application task
   FTM_PMIC_CHG_SWITCH_NUM_SWITCHES
} ftm_pmic_chg_switch_type;

/** This type specifies the charger type available for configuration */
typedef enum
{
   FTM_PMIC_CHG_CONFIG_WALL_PULSE_CHGR            = 0,
   FTM_PMIC_CHG_CONFIG_WALL_PULSE_CHGR_VBAT_DET   = 1,
   FTM_PMIC_CHG_CONFIG_WALL_CHGR_TRANISTOR_LIMITS = 2,
   FTM_PMIC_CHG_CONFIG_TRICKLE_CHARGER            = 3,
   FTM_PMIC_CHG_CONFIG_COIN_CELL_CHGR             = 4,
   FTM_PMIC_CHG_CONFIG_BATT_ALARM                 = 5,
   FTM_PMIC_CHG_CONFIG_USB_TRANSISTOR_LIMITS      = 6,
   FTM_PMIC_CHG_CONFIG_PWR_CTRL_LIMIT             = 7
} ftm_pmic_chg_set_config_type;

/** This type specifies the charger types available for power control limiting configuration */
typedef enum
{
   FTM_PMIC_CHG_PWR_CTRL_LIMIT_WALL = 0,
   FTM_PMIC_CHG_PWR_CTRL_LIMIT_USB  = 1
} ftm_pmic_chg_pwr_ctrl_limit_select_type;

/** This type specifies the time format for the RTC commands */
typedef enum
{
   FTM_PMIC_RTC_MODE_12_HOUR_AM  = 0,
   FTM_PMIC_RTC_MODE_12_HOUR_PM  = 1,
   FTM_PMIC_RTC_MODE_24_HOUR     = 2
} ftm_pmic_rtc_mode_type;

/** This type specifies the VERG SMPS Clock commands */
typedef enum
{
   FTM_PM_VREG_SMPS_CLK_SEL_CMD       = 0,
   FTM_PM_VREG_SMPS_CLK_TCXO_DIV_CMD  = 1,
   FTM_PM_VREG_SMPS_CLK_INVALID_CMD
} ftm_pmic_vreg_smps_config_clk_cmd;

/** This type specifies the pin types for the FTM_SET_PMIC_DRIVE_LEVEL command */
typedef enum
{
   FTM_PMIC_UI_DRV_SEL_LCD = 0,
   FTM_PMIC_UI_DRV_SEL_KPD = 1,
   FTM_PMIC_UI_DRV_SEL_VIB = 2
} ftm_pmic_ui_high_drive_pin_id_type;

/* This type specifies the interface for the set time rtc cmd */

typedef struct
{
   byte      ftm_rtc_month;
   byte      ftm_rtc_day;
   word      ftm_rtc_year;
   byte      ftm_rtc_hour;
   byte      ftm_rtc_min;
   byte      ftm_rtc_sec;
} ftm_pmic_rtc_set_time_cmd_type;

/**
\brief Enumeration of PMIC RTC Alarm ID's
*/
typedef enum
{
   // FTM_PMIC_TEST_RTC group
   RTC_ALARM_1 = 1,
   RTC_ALARM_2 = 2,
   RTC_ALARM_3 = 3
} FTM_PMIC_RTC_Alarm_Id_Enum;

typedef enum
{
   PMIC_MIC_VOLT_2_00V = 0,
   PMIC_MIC_VOLT_1_93V = 1,
   PMIC_MIC_VOLT_1_80V = 2,
   PMIC_MIC_VOLT_1_73V = 3
} FTM_PMIC_MIC_Voltage_Enum;

/******************************************************************************
FTM - Audio
*******************************************************************************/
/**
\brief Enumeration of Audio FTM Sub-command ID's
*/
typedef enum
{
   _FTM_AUDIO_SET_PATH              = 0,    //!<'  Sets up the audio path
   _FTM_AUDIO_SET_VOLUME            = 1,    //!<'  Sets up the volume in the current audio path
   _FTM_AUDIO_DSP_LOOPBACK          = 2,    //!<'  Sets up audio loopback in the DSP
   _FTM_AUDIO_PCM_LOOPBACK          = 3,    //!<'  Sets up audio loopback in the codec
   _FTM_AUDIO_TONES_PLAY            = 4,    //!<'  Plays tones at specified frequency
   _FTM_AUDIO_TONES_STOP            = 5,    //!<'  Stops the tones that are currently playing
   _FTM_AUDIO_NS_CONTROL            = 6,    //!<'  Toggles the noise suppressor ON/OFF
   _FTM_AUDIO_PCM_CAPTURE           = 7,    //!<'  Start a PCM capture
   _FTM_AUDIO_GET_PCM_CAPTURE_DATA  = 8,    //!<'  Get data from a PCM capture
   _FTM_AUDIO_PCM_CAPTURE_STOP      = 9,    //!<'  Clear the PCM capture buffers
   _FTM_AUDIO_SET_CODECTXGAIN_ADJ   = 10,   //!<'  Set the CodecTxGainAdjust
   _FTM_AUDIO_SET_PATH_INPUT_OUTPUT = 10,   //!<'  Activates an input and an output device pairing for the FTM DSP Loopback and Tone Play test.
   _FTM_AUDIO_PCM_ENABLE_WITH_PARAM = 11,   //!<'  Starts PCM audio recording
} FTM_Audio_SubCmd_Id_Enum;

/**
\brief Enumeration of Audio Devices for use with the FTM_AUDIO_SET_PATH command
*/
typedef enum
{
   FTM_AUDIO_PATH_HANDSET           = 0,    //!<'  Handset
   FTM_AUDIO_PATH_HANDSFREE     = 1,    //!<'  Handsfree kit
   FTM_AUDIO_PATH_MONO_HEADSET      = 2,    //!<'  Mono headset
   FTM_AUDIO_PATH_STEREO_HEADSET    = 3,    //!<'  Stereo headset
   FTM_AUDIO_PATH_ANALOG_HANDSFREE  = 4,    //!<'  Analog handsfree kit
   FTM_AUDIO_PATH_STEREO_DAC        = 5,    //!<'  Stereo DAC
   FTM_AUDIO_PATH_SPEAKER_PHONE = 6,    //!<'  Speaker phone
   FTM_AUDIO_PATH_TTY_HANDSFREE = 7,    //!<'  TTY Handsfree kit
   FTM_AUDIO_PATH_TTY_HEADSET       = 8,    //!<'  TTY headset
   FTM_AUDIO_PATH_TTY_VCO           = 9,    //!<'  TTY VCO
   FTM_AUDIO_PATH_TTY_HCO           = 10,   //!<'  TTY HCO
   FTM_AUDIO_PATH_BT_INTERCOM       = 11,   //!<'  Bluetooth intercom
   FTM_AUDIO_PATH_BT_HEADSET        = 12,   //!<'  Bluetooth headset
   FTM_AUDIO_PATH_BT_AUDIO          = 13,   //!<'  Bluetooth local audio
   FTM_AUDIO_PATH_USB_AUDIO     = 14,   //!<'  USB audio
   FTM_AUDIO_PATH_FM_MONO_HS        = 15,   //!<'  FM Mono headset
   FTM_AUDIO_PATH_FM_STEREO_HS      = 16    //!<'  FM Stereo headset
} FTM_Audio_Device_Id_Enum;

typedef enum
{
   FTM_AUDIO_SND_METHOD_VOICE = 0,          //!<'  Use the device's voice generator
   FTM_AUDIO_SND_METHOD_KEY_BEEP = 1,       //!<'  Use the device's keybeep generator
   FTM_AUDIO_SND_METHOD_MESSAGE = 2,        //!<'  Use the path's ringer, or voice generator
   FTM_AUDIO_SND_METHOD_RING = 3            //!<'  Use the device's ring generator
} FTM_Audio_Sound_Methods_Enum;

/******************************************************************************
FTM - AP
*******************************************************************************/
/**
\brief Enumeration of Audio Devices for use with the FTM_AUDIO_SET_PATH command
*/
typedef enum
{
   FTM_AP_TEST_APP_STATUS_CMD     = 0,
   FTM_AP_SELECT_SEQUENCE_CMD     = 1,
   FTM_AP_CLEAR_RESULTS_CMD       = 2,
   FTM_AP_EXECUTE_SINGLE_TEST_CMD = 3,
   FTM_AP_EXECUTE_ALL_TESTS_CMD   = 4,
   FTM_AP_READ_FILE_CMD           = 5,
   FTM_AP_WRITE_FILE_CMD          = 6,
   FTM_AP_ERASE_ALL_FILES_CMD     = 7,
   FTM_AP_TEST_LIST_TO_FILE_CMD   = 8,
   FTM_AP_DIR_TO_FILE_CMD         = 9,
   FTM_AP_EXIT_TEST_CMD           = 10,
   FTM_AP_UTILITY_CMD             = 11,
   FTM_AP_APPEND_TO_RES_CMD       = 12,
   FTM_AP_READ_APP_VERSION_CMD    = 13
} FTM_AP_CMD_ID_Enum;

typedef struct FTM_MMI_Test
{
   char company[20];
   char group[20];
   char testname[30];
} FTM_MMI_Test;

/******************************************************************************
FTM - SECURITY_ID_SENSOR
*******************************************************************************/
/**
\brief Enumeration of SECURITY_ID_SENSOR FTM Sub-command ID's
*/
typedef enum
{
   _FTM_SECURITY_ID_SENSOR_START                   = 1,        //!<' Starts SECURITY_ID_SENSOR services
   _FTM_SECURITY_ID_SENSOR_WRITE_PARAMETER         = 3,        //!<' Sets scan parameters for SECURITY_ID_SENSOR sensor
   _FTM_SECURITY_ID_SENSOR_READ_PARAMETER          = 4,        //!<' Reads scan parameters for SECURITY_ID_SENSOR sensor
   _FTM_SECURITY_ID_SENSOR_GET_MAX_BUFFER_LENGTH   = 7,        //!<' Gets the max. buffer size for data transfer
   _FTM_SECURITY_ID_SENSOR_READ_IMAGE              = 8,        //!<' Reads part of previously scanned image
   _FTM_SECURITY_ID_SENSOR_EXEC                    = 9,        //!<' Executes self test
   _FTM_SECURITY_ID_SENSOR_READ_EXEC_STATUS        = 10,       //!<' Returns self tets status
   _FTM_SECURITY_ID_SENSOR_READ_INFO               = 12,       //!<' Returns subsystem info
   _FTM_SECURITY_ID_SENSOR_WRITE_CALIBRATION       = 13,       //!<' Writes Calibration data to OTP or eeprom memory
   _FTM_SECURITY_ID_SENSOR_READ_TEMPERATURE        = 14,       //!<' Reads sensor temperature
   _FTM_SECURITY_ID_SENSOR_READ_LIVENESS           = 15,       //!<' Returns liveness detection status
   _FTM_SECURITY_ID_SENSOR_WRITE_MFG_DATA          = 16,       //!<' Updates value for en manufaturing data entry
   _FTM_SECURITY_ID_SENSOR_READ_MFG_DATA           = 17,       //!<' Retruns value for en manufaturing data entry
   _FTM_SECURITY_ID_SENSOR_CALIBRATION_STATUS      = 18,       //!<' Returns Calibration status
   _FTM_SECURITY_ID_SENSOR_SET_TEST_PARAMETER      = 19,       //!<' Sets value for test parameter
   _FTM_SECURITY_ID_SENSOR_GET_TEST_PARAMETER      = 20,       //!<' Get current value for test parameter
   _FTM_SECURITY_ID_SENSOR_STOP                    = 99,       //!<' Stops the SECURITY_ID_SENSOR service
} FTM_SECURITY_ID_SENSOR_SubCmd_Id_Enum;

/******************************************************************************
FTM - WP
*******************************************************************************/
/**
The enum represents a list of all the FTM_WP commands. See 80-NG894-15
*/
typedef enum
{
   FTM_WP_FUSE_CHECK_CMD                = 0,
   FTM_WP_PROVISION_FILE_CMD            = 1,
   FTM_WP_PROVISION_SSD_CMD             = 2,
   FTM_WP_PROVISION_HDCP_CEK_CMD        = 3,
   FTM_WP_PROVISION_HDCP_DATA_CMD       = 4,
   FTM_WP_PROVISION_OPM_PUB_CMD         = 5,
   FTM_WP_PROVISION_OPM_PRIV_CMD        = 6,
   FTM_WP_GET_DEVICE_UNIQUE_ID_CMD      = 7,
   FTM_WP_PROVISION_OVK_HASH_CMD        = 8,
   FTM_WP_LOCK_DEVICE_CMD               = 9,
   FTM_WP_VALIDATE_PROVISIONED_FILE_CMD = 10,
   FTM_WP_READ_PROVISIONED_FILE_CMD     = 11,
   FTM_WP_REGISTRY_READ_CMD             = 12,
   FTM_WP_SHUTDOWN_CMD                  = 13,
   FTM_WP_FACTORY_RESET_CMD             = 14,
   FTM_WP_PROVISION_HDCP_HDMI_V1_CMD   = 15,
   FTM_WP_PROVISION_HDCP_HDMI_V2_CMD   = 16,
   FTM_WP_VALIDATE_HDCP_HDMI_V1_CMD    = 17,
   FTM_WP_VALIDATE_HDCP_HDMI_V2_CMD    = 18
}   FTM_WP_CMD_ID_Enum;

/******************************************************************************
FTM - Camera
*******************************************************************************/

/**
\brief Enumeration of Camera FTM Sub-command ID's
*/
typedef enum
{
   _FTM_CAMERA_START                = 0,        //!<' Starts camera services
   _FTM_CAMERA_STOP             = 1,        //!<' Stops camera services
   _FTM_CAMERA_SET_PARM         = 2,        //!<' Sets operational parameters for camera sensor
   _FTM_CAMERA_SET_DIMENSIONS       = 3,        //!<' Sets camera dimensions
   _FTM_CAMERA_START_PREVIEW        = 4,        //!<' Enters preview state
   _FTM_CAMERA_STOP_PREVIEW     = 5,        //!<' Exits preview state
   _FTM_CAMERA_TAKE_PICTURE_AND_ENCODE  = 6,    //!<' Takes a picture and encode it
   _FTM_CAMERA_GET_PICTURE          = 7,        //!<' Gets raw or encoded data from phone
   _FTM_CAMERA_GET_PARM         = 8,        //!<' Gets operational parameters for camera sensor
   _FTM_CAMERA_GET_INFO         = 9,        //!<' Reads the camera information
   _FTM_CAMERA_SET_SENSOR_ID        = 10        //!<' Select the camera sensor
} FTM_Camera_SubCmd_Id_Enum;

/**
\brief Enumeration of Camera Status, which is returned from calling camera services API.
See also: (80-V5310-1) Camera Services Interface Specification and Operational Description
*/
typedef enum
{
   CAMERA_SUCCESS,
   CAMERA_INVALID_STATE,
   CAMERA_INVALID_PARM,
   CAMERA_INVALID_FORMAT,
   CAMERA_NO_SENSOR,
   CAMERA_NO_MEMORY,
   CAMERA_NOT_SUPPORTED,
   CAMERA_FAILED,
   CAMERA_INVALID_STAND_ALONE_FORMAT,
   CAMERA_MALLOC_FAILED_STAND_ALONE,
} FTM_Camera_Status_Enum;

/**
\brief Enumeration of Camera Status, for use with the FTM_CAMERA_SET_PARM command.
See also: (80-V5310-1) Camera Services Interface Specification and Operational Description, Table 2-4.
*/
typedef enum
{
   CAMERA_PARM_STATE,
   CAMERA_PARM_ACTIVE_CMD,
   CAMERA_PARM_ZOOM,
   CAMERA_PARM_ENCODE_ROTATION,
   CAMERA_PARM_SENSOR_POSITION,
   CAMERA_PARM_CONTRAST,
   CAMERA_PARM_BRIGHTNESS,
   CAMERA_PARM_SHARPNESS,
   CAMERA_PARM_EXPOSURE,
   CAMERA_PARM_WB,
   CAMERA_PARM_EFFECT,
   CAMERA_PARM_AUDIO_FMT,
   CAMERA_PARM_FPS,
   CAMERA_PARM_FLASH,
   CAMERA_PARM_RED_EYE_REDUCTION,
   CAMERA_PARM_NIGHTSHOT_MODE,
   CAMERA_PARM_REFLECT,
   CAMERA_PARM_PREVIEW_MODE,
   CAMERA_PARM_ANTIBANDING,
   CAMERA_PARM_THUMBNAIL_WIDTH,
   CAMERA_PARM_THUMBNAIL_HEIGHT,
   CAMERA_PARM_THUMBNAIL_QUALITY
} FTM_Camera_Param_Enum;

/**
\brief Enumeration of Camera Preview settings for use with the FTM_CAMERA_SET_PARM command.
See also: (80-V5310-1) Camera Services Interface Specification and Operational Description, Table 2-4.
*/
typedef enum
{
   CAMERA_PREVIEW_MODE_SNAPSHOT,
   CAMERA_PREVIEW_MODE_MOVIE
} FTM_Camera_Param_Preview_Enum;

/**
\brief Enumeration of Camera orientations
*/
typedef enum
{
   CAMERA_ORIENTATION_LANDSCAPE,
   CAMERA_ORIENTATION_PORTRAIT
} FTM_Camera_Orientation_Enum;

/**
\brief Enumeration of Camera orientations
*/
typedef enum
{
   CAMERA_RAW,
   CAMERA_JPEG
} FTM_Camera_Format_Enum;

/******************************************************************************
FTM - Log
*******************************************************************************/

/**
\brief Enumeration of FTM Logging commands.
*/
typedef enum
{
   _FTM_LOG_ENABLE      = 0,
   _FTM_LOG_DISABLE = 1
} FTM_Logging_SubCmd_Id_Enum;

/*===========================================================================*/
/**
enum log_FTM2_id_enum

\brief Log ID's for the FTM2 log message
*/
/*===========================================================================*/
typedef enum
{
   LOG_FTM2_LOG_PRINTF      = 0x00,     //!<' FTM printf
   LOG_FTM2_LOG_BT          = 0x01,     //!<' FTM Bluetooth
   LOG_FTM2_LOG_DACC_ACCUM  = 0x02,     //!<' DACC accumulator
   LOG_FTM2_LOG_DACC_ACCUM_C0= 0x03,        //!<' DACC accumulator, antenna 2
   LOG_FTM2_LOG_1X_AGC      = 0x4,      //!<' 1X Primary AGC
   LOG_FTM2_LOG_HDR_AGC     = 0x5,      //!<' EVDO Primary AGC
   LOG_FTM2_LOG_1X_AGC_C1   = 0x6,      //!<' 1X Secondary AGC
   LOG_FTM2_LOG_HDR_AGC_C1  = 0x7,      //!<' EVDO Secondary AGC
   LOG_FTM2_LOG_IM2_DFT     = 0x8,
   LOG_FTM2_LOG_FFT         = 0x9,
   LOG_FTM2_GSM_AUTOCAL     = 0xA,      //!<' FTM GSM Auto Calibration
   LOG_FTM2_GSM_THERM_VBATT = 0xB,      //!<' FTM GSM Therm & Batt
   LOG_FTM2_INTELLICEIVER   = 0xB,      //!<' FTM CDMA Intelliceiver
   LOG_FTM2_LOG_TX_RX_SWEEP = 0x0B,     //!<' results from FTM_LOG_TX_RX_SWEEP
   LOG_FTM2_LOG_GSM_RX_SWEEP    = 0x0C,     //!<' results from FTM_LOG_GSM_RX_SWEEP
   LOG_FTM2_LOG_ANT         = 0x0D,     //!<' FTM ANT
   LOG_FTM2_LOG_HDET_TRACKING   = 0x10,
   LOG_FTM2_LOG_ICI_CAL         = 0x20, //!<' ICI cal log message
   LOG_FTM2_SEQ_LOG_ID          = 0x11, //!<' FTM Sequence Log ID

   LOG_FTM2_LOG_WCDMA_AGC   = 0x1004,   //!<' FTM WCDMA AGC
   LOG_FTM2_LOG_GSM_BER     = 0x1005,   //!<' FTM GSM BER
   LOG_FTM2_LOG_WCDMA_BER   = 0x1006,   //!<' FTM WCDMA BER
   LOG_FTM2_LOG_WCDMA_AGC_V2 = 0x1007,  //!<' FTM WCDMA AGC V2
   LOG_FTM2_LOG_SE_BER =    0x1009,  //!<' FTM WCDMA SE BER

   LOG_FTM2_LOG_LTE_TX_AGC  = 0x1111, //!<' FTM LTE Tx AGC
   LOG_FTM2_LOG_LTE_RX_AGC  = 0x1112,  //!<' FTM LTE Rx AGC
   LOG_FTM2_LOG_LTE_TX_AGC_ENH   = 0x1114, //!<' FTM LTE Tx AGC Enhanced
   LOG_FTM2_LOG_LTE_RX_AGC_CA  = 0x1115,  //!<' FTM LTE Rx AGC (CA capable)
   LOG_FTM2_LOG_LTE_Rx_AGC_CA_HORXD = 0x1116,  //!<' FTM LTE Rx AGC (CA and HoRxD capable)

   LOG_FTM2_LOG_TDSCDMA_RX_AGC    = 0x1120,
   LOG_FTM2_LOG_TDSCDMA_TX_AGC    = 0x1121,
   LOG_FTM2_LOG_TDSCDMA_BER       = 0x1122,
   LOG_FTM2_LOG_TDSCDMA_TXPLIM    = 0x1123,
   LOG_FTM2_LOG_GSM_TX_AGC        = 0x1124,
   LOG_FTM2_LOG_FTM_AP            = 0x1125, //'<' FTM AP (MMI test) status
   LOG_FTM2_LOG_GSM_TX_AGC_ENH    = 0x1127,

   LOG_FTM2_LOG_INVALID_MAX
} log_FTM2_id_enum;

//! Size of FTM Log ID
#define LOG_FTM2_LOG_ID_SIZE 2

//! Size of the header information on an FTM2 log packet, including the standard log header+FTM2 log id fields
#define LOG_FTM2_HEADER_SIZE 14

//! Size of Log Response header.  See Log Response in 3.4.13.2 of 80-V1294-1
#define LOG_RESPONSE_HEADER_SIZE 4

/*===========================================================================*/
/**
Structure of the general FTM2LogMessage, 80-V9147-1_A - FTM Logging API
*/
/*===========================================================================*/

typedef struct
{
   // Portion unique to FTM logs
   word iFTM_LogID; //!<' Log ID
   byte  Data[DIAG_MAX_PACKET_SIZE];        //!<' Pointer to the data
} FTM2LogMessage;

/*===========================================================================*/
/**
Structure of the general FTM2BTLogMessage, Bluetooth FTM Logging API
for Bluetooth HCI Event log ID 0x1366
*/
/*===========================================================================*/

typedef struct
{
   word iBT_Event_LogID;                    //!<' Log ID
   byte iProtocolByte;                      //!<' This is for dummy protocol byte to support legacy architecture
   byte  Data[DIAG_MAX_PACKET_SIZE];        //!<' Pointer to the data
} BT_HCI_LogMessage;

/*===========================================================================*/
/**
Structure of the WCDMA FTM2LogMessage, 80-V9147-1_A - FTM Logging API
*/
/*===========================================================================*/

typedef struct
{
   // Portion unique to FTM logs
   word iFTM_LogID; //!<' Log ID
   short iRX_AGC;
   short iTX_AGC;
   short iTx_AGC_ADJ;
   byte  iLNA_STATE;
   byte  iPA_STATE;
   byte  iHDET;
   word iThemistor;
   byte  iScaledThermistor;
   byte  iTempCompIndex;
   byte  iTempCompRemainder;
} FTM2LogMessage_WCDMA_AGC;

typedef struct
{
   word iFTM_LogID;
   short iRX_AGC;
   short iTX_AGC;
   short iTx_AGC_ADJ;
   byte iLNA_STATE;
   byte iPA_STATE;
   byte iHDET;
   word iThemistor;
   byte iScaledThermistor;
   byte iTempCompIndex;
   byte iTempCompRemainder;
   short iRX_AGC_C1;
   byte iLNA_STATE_C1;
} FTM2LogMessage_WCDMA_AGC_V2;

/**
Indicator that a default timeout should be used
*/
#define FTM_NONSIG_DEFAULT_TIMEOUT  0

/******************************************************************************
FTM - WCDMA BER
*******************************************************************************/

/**
\brief Enumeration of FTM WCDMA BER commands.
*/
typedef enum
{
   _FTM_WCDMA_START_MODE_REQ        = 0,
   _FTM_WCDMA_STOP_MODE_REQ     = 1,
   _FTM_WCDMA_START_IDLE_MODE_REQ   = 2,
   _FTM_WCDMA_ACQUIRE_REQ           = 3,
   _FTM_WCDMA_RMC_DCH_SETUP_REQ = 4,
   _FTM_WCDMA_RMC_DCH_SETUP_REQ_V2  = 5,
   _FTM_WCDMA_BER_RMC_DCH_TFCS_CONFIG_REQ    = 6,
   _FTM_WCDMA_BER_EVENT_STATUS_CLEAR_REQ     = 7,
   _FTM_WCDMA_BER_EVENT_STATUS_REQ           = 8,
   _FTM_WCDMA_BER_SET_UL_POWER               = 9,
   _FTM_WCDMA_BER_RX_LEVEL_REQ               = 10,
   _FTM_WCDMA_BER_TPC_CONTROL                = 11,
   _FTM_WCDMA_BER_RSCP                       = 12
} FTM_WCDMA_BER__SubCmd_Id_Enum;

/**
\brief event_type used by QLIB_FTM_WCDMA_BER_EVENT_STATUS_REQ
*/
typedef enum
{
   FTM_WCDMA_BER_START_WCDMA_MODE_CNF   = 0,
   FTM_WCDMA_BER_STOP_WCDMA_MODE_CNF    = 1,
   FTM_WCDMA_BER_IDLE_MODE_CNF          = 2,
   FTM_WCDMA_BER_ACQ_CNF                = 3,
   FTM_WCDMA_BER_CPHY_SETUP_CNF     = 4,
   FTM_WCDMA_PHYCHAN_ESTABLISHED_IND    = 5
} FTM_WCDMA_BER_EVENT_STATUS_Enum;

/**
\brief error codes used by QLIB_FTM_WCDMA_BER_EVENT_STATUS_REQ
*/
typedef enum
{
   FTM_WCDMA_BER_SYNC_STATUS_SUCCESS                     = 0,
   FTM_WCDMA_BER_SYNC_STATUS_GEN_FAILURE                 = 1,
   FTM_WCDMA_BER_SYNC_STATUS_TIMEOUT_EXPIRED             = 2,
   FTM_WCDMA_BER_SYNC_STATUS_EVENT_STATUS_FAILED         = 3,
   FTM_WCDMA_BER_SYNC_STATUS_UNKNOWN_CMD                 = 4,
   FTM_WCDMA_BER_SYNC_STATUS_PWR_SETTING_OUT_OF_RANGE    = 5,
   FTM_WCDMA_BER_SYNC_STATUS_OVERRIDE_VALUE_UNSUPPORTED  = 6
} FTM_WCDMA_BER_SYNC_STATUS_ERROR_CODE_Enum;

/**
Structure of response packet for certian non-sigaling commands
CMD_CODE    - Message ID.       DM sets CMD_CODE to 75
SUB_SYS_ID  - FTM ID is 11.     Mode ID Mode ID for FTM WCDMA
Reserved    - 0
rsp_id      - 0x1002 = FTM_WCDMA_BER
rsp_cid     - Command ID that generated.
rsp_scid    - Subcommand ID that generated
Status      - 0 = DIAG_FTM_STATUS_SUCCESS. 1 = DIAG_FTM_STATUS_SUCCESS
*/
typedef struct
{
   byte  iCMD_Code;
   byte  iSubSysId;
   byte  iModeID;
   byte  iReserved;
   word iRspId;
   word iRspCid;
   word iRspSCid;
   byte  iStatus;
} FTM_BER_Response_Struct;

/*===========================================================================*/
/**
enum log_FTM2_WCDMA_BER_log_id_enum, 80-V9698-1_A

\brief Log ID's for the WCDMA BER FTM2 log message
*/
/*===========================================================================*/
typedef enum
{
   LOG_FTM2_WCDMA_START_MODE_CNF            = 0,        //!<' FTM WCDMA BER start WCDMA mode confirmation
   LOG_FTM2_WCDMA_STOP_MODE_CNF         = 1,        //!<' FTM WCDMA BER stop WCDMA mode confirmation
   LOG_FTM2_WCDMA_START_IDLE_MODE_REQ   = 2,        //!<' FTM WCDMA BER start idle mode confirmation
   LOG_FTM2_WCDMA_ACQUIRE_CNF           = 3,        //!<' FTM WCDMA BER acquire confirmation
   LOG_FTM2_WCDMA_CPHY_SETUP_CNF            = 4,        //!<' FTM WCDMA BER CPHY setup confirmation
   LOG_FTM2_WCDMA_PHYCHAN_ESTABLISHED_IND= 5,       //!<' FTM WCDMA BER physical channel established confirmation
   LOG_FTM2_WCDMA_CPHY_ERROR_IND            = 6,        //!<' FTM WCDMA BER pyhsical channel error
   LOG_FTM2_WCDMA_RL_FAILURE_IND            = 7,        //!<' FTM WCDMA BER Reverselink error
   LOG_FTM2_WCDMA_BER_Max
} log_FTM2_WCDMA_BER_log_id_enum;

/*===========================================================================*/
/**
enum for WCDMA non-signaling Acquisition type
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_AcqTypeFreqOnly        = 0,    //!<' Frequency valid only
   FTM_WCDMA_BER_AcqTypeFreqAndScrCode  = 1,    //!<' Frequency and scrambling code valid only
   FTM_WCDMA_BER_AcqTypeFreqScrCodePN   = 2     //!<' Frequency, scrambling code, and PN position valid
} FTM_WCDMA_BER_AcqType_Enum;

/*===========================================================================*/
/**
enum for WCDMA non-signaling power control type
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_TX_POWER_CONTROL_TYPE_AGC_SETPOINT,
   FTM_WCDMA_BER_TX_POWER_CONTROL_TYPE_RPC_ENABLE,
   FTM_WCDMA_BER_TX_POWER_CONTROL_TYPE_POWER_UP_BITS,
   FTM_WCDMA_BER_TX_POWER_CONTROL_TYPE_MAX
} FTM_WCDMA_BER_PowerControlType_Enum;

/*===========================================================================*/
/**
enum for WCDMA non-signaling Acquisition mode
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_AcqModeMicro   = 0,    //!<' Micro acquisition (not currently supported)
   FTM_WCDMA_BER_AcqModeFull    = 1     //!<' 1 = Full acquisition freq ARFCN to attempt acquisition. Required for acq_type = 0, 1, or 2.
} FTM_WCDMA_BER_AcqMode_Enum;

/*===========================================================================*/
/**
enum for WCDMA non-signaling RMC type
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_RMC_Type12_2kpbs               = 0,    //!<' RMC 12.2 kbps channel,
   FTM_WCDMA_BER_RMC_Type64kbps             = 1,    //!<' RMC 64 kbps channel,
   FTM_WCDMA_BER_RMC_Type384kpbs                = 2,    //!<' RMC 384 kbps channel, (Not currently supported)
   FTM_WCDMA_BER_RMC_Type12_2kpbs_Symmetric = 3,    //!<' RMC 12.2 kbps channel, block size in the DL and UL is the same
   FTM_WCDMA_BER_RMC_Type64kbps_Symmetric       = 4,    //!<' RMC 64 kbps channel, block size in the DL and UL is the same
   FTM_WCDMA_BER_RMC_Type384kbps_Symmetric      = 5     //!<' RMC 384 kbps channel, block size in the DL and UL is the same

                                                  // Note: For first 3 data rate enumeration, UL CRC bits are looped back from DL
                                                  // Note: For last  3 data rate enumeration, UL CRC is valid and computed based on Rx data bits
} FTM_WCDMA_BER_RMC_Type_Enum;

/*===========================================================================*/
/**
enum for WCDMA non-signaling Power Algorithm types
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_PCA_Type_Alg1  = 0,    //!<' Power control algorithm 1
   FTM_WCDMA_BER_PCA_Type_Alg2  = 1     //!<' Power control algorithm 2
} FTM_WCDMA_BER_PCA_Type_Enum;

/*===========================================================================*/
/**
enum for WCDMA non-signaling Power Algorithm types
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_PCA_Size_1dB   = 0,    //!<' 1dB for power control algorithm
   FTM_WCDMA_BER_PCA_Size_2dB   = 1     //!<' 2dB for power control algorithm
} FTM_WCDMA_BER_PCA_Size_Enum;

/*===========================================================================*/
/**
enum for WCDMA non-signaling Power Algorithm types
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_UL_TFCS_CONFIG = 0,
   FTM_WCDMA_BER_DL_TFCS_CONFIG = 1
} FTM_WCDMA_BER_TFCS_ConfigType;

/**
Structure to store the state of WCDMA BER.  This structure is used with the functions:
QLIB_FTM_WCDMA_BER_ClearStatus()
QLIB_FTM_WCDMA_BER_GetStatus()
*/
typedef struct
{
   /**
   Status array, indexed by log_FTM2_WCDMA_BER_log_id_enum

   Will be set to true if a log message was received for that log type
   */
   byte bHasUpdated[ LOG_FTM2_WCDMA_BER_Max ];

   //
   // Related to ACQUIRE_CNF
   //
   /**
   ACQUIRE_CNF.Status = 0 = Acquisition failed, frequency and scr_code data not valid, 1 = Acquisition successful
   */
   byte iACQUIRE_CNF_status;

   //! ACQUIRE_CNF.Frequency = Frequency where CPICH was acquired
   dword iACQUIRE_CNF_frequency;

   //! ACQUIRE_CNF.Scr_Code = Primary CPICH scrambling code identified during acquisition
   dword iACQUIRE_CNF_scr_code;

   //
   // Related to CPHY_SETUP_CNF
   //
   /**
   CPHY_SETUP_CNF.status
   0 = CPHY_SETUP request failed
   1 = CPHY_SETUP request successful.
   */
   byte iCPHY_SETUP_status;

   //
   // Related to PHYCHAN_ESTABLISHED_IND
   //
   /**
   PHYCHAN_ESTABLISHED_IND.status
   0 = Physical channel could not be established.
   1 = Physical channel was successfully established.
   */
   byte iPHYCHAN_ESTABLISHED_IND_status;

   //
   // WCDMA AGC message
   //
   //! Updated flag for WCDMA AGC
   byte bWCDMA_AGChasUpdated;

   //! Storage for WCDMA AGC
   FTM2LogMessage_WCDMA_AGC oWCDMA_AGC;
}  WCDMA_BER_State;

/*===========================================================================*/
/**
enum for WCDMA non-signaling N312 parameters
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_N312_s1    = 0,
   FTM_WCDMA_BER_N312_s50   = 1,
   FTM_WCDMA_BER_N312_s100  = 2,
   FTM_WCDMA_BER_N312_s200  = 3,
   FTM_WCDMA_BER_N312_s400  = 4,
   FTM_WCDMA_BER_N312_s600  = 5,
   FTM_WCDMA_BER_N312_s800  = 6,
   FTM_WCDMA_BER_N312_s1000 = 7,
} ftm_wcdma_ber_n312_type;

/*===========================================================================*/
/**
enum for WCDMA non-signaling N313 parameters
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_N313_s1   = 0,
   FTM_WCDMA_BER_N313_s2   = 1,
   FTM_WCDMA_BER_N313_s4   = 2,
   FTM_WCDMA_BER_N313_s10  = 3,
   FTM_WCDMA_BER_N313_s20  = 4,
   FTM_WCDMA_BER_N313_s50  = 5,
   FTM_WCDMA_BER_N313_s100 = 6,
   FTM_WCDMA_BER_N313_s200 = 7
} ftm_wcdma_ber_n313_type;

/*===========================================================================*/
/**
enum for WCDMA non-signaling N315 parameters
*/
/*===========================================================================*/
typedef enum
{
   FTM_WCDMA_BER_N315_s1   = 0,
   FTM_WCDMA_BER_N315_s50  = 1,
   FTM_WCDMA_BER_N315_s100 = 2,
   FTM_WCDMA_BER_N315_s200 = 3,
   FTM_WCDMA_BER_N315_s400 = 4,
   FTM_WCDMA_BER_N315_s600 = 5,
   FTM_WCDMA_BER_N315_s800 = 6,
   FTM_WCDMA_BER_N315_s1000 = 7
} ftm_wcdma_ber_n315_type;

/******************************************************************************
FTM - HSDPA BLER
*******************************************************************************/

/** This enumeration specifies the pre-configured HSET list, to be used with QLIB_FTM_HSDPA_BLER_Configure_HS_DSCH */
typedef enum
{
   HSDPA_HSET_1_QPSK = 1,       //!< ' HSET 1, QPSK
   HSDPA_HSET_1_16QAM,          //!< ' HSET1, 16QAM
   HSDPA_HSET_2_QPSK,           //!< ' HSET2, QPSK
   HSDPA_HSET_2_16QAM,          //!< ' HSET2, 16QAM
   HSDPA_HSET_3_QPSK,           //!< ' HSET3, QPSK
   HSDPA_HSET_3_16QAM,          //!< ' HSET3, 16QAM
   HSDPA_HSET_4_QPSK,           //!< ' HSET4, QPST
   HSDPA_HSET_5_QPSK,           //!< ' HSET5, QPST
   HSDPA_HSET_6_QPSK = 0xFF //!< ' HSET6, QPST
} ftm_hsdpa_ber_hset_type;

/** This type specifies the possible asynchronous event packet types */
typedef enum
{
   FTM_LOG_HSDPA_HS_CHANNEL_START_IND   = 0x40, //!< ' HSDPA Start completion indicator
   FTM_LOG_HSDPA_HS_CHANNEL_STOP_IND    = 0x41, //!< ' HSDPA Stop completion indicator
   FTM_LOG_HSDPA_HS_CHANNEL_RECFG_IND   = 0x42, //!< ' HSDPA Reconfigure completion indicator

   // Identifiers to help with the size of the event list
   FTM_LOG_HSDPA_EVENT_Max,                                     //!< ' Maximum ID + 1
   FTM_LOG_HSDPA_EVENT_First = FTM_LOG_HSDPA_HS_CHANNEL_START_IND,  //!< ' First valid ID
   FTM_LOG_HSDPA_EVENT_Last = FTM_LOG_HSDPA_EVENT_Max - 1,          //!< ' Last valid ID
   FTM_LOG_HSDPA_EVENT_Count = FTM_LOG_HSDPA_EVENT_Max -
                               FTM_LOG_HSDPA_EVENT_First            //!< ' Size of valid list
} log_FTM2_HSDPA_BER_log_id_enum;

/**
Enumeration of HSDPA channel states
*/
typedef enum
{
   FTM_HSDPA_BLER_HS_CHAN_STATE_INACTIVE,
   FTM_HSDPA_BLER_HS_CHAN_STATE_ACTIVE
} ftm_hsdpa_bler_hs_chan_state_type;

/**
Enumeration of HSDPA force-stop error states
*/
typedef enum
{
   FTM_HSDPA_BLER_HS_FORCE_STOP__NO_ERROR = 0,
   FTM_HSDPA_BLER_HS_FORCE_STOP__ERROR_OP_IN_PROGRESS,
   FTM_HSDPA_BLER_HS_FORCE_STOP__ERROR_HS_INACTIVE
} ftm_hsdpa_bler_hs_force_stop_error_type;

/**
\brief event_type used by QLIB_FTM_HSDPA_BLER_EVENT_STATUS_REQ
*/
typedef enum
{
   FTM_HSDPA_BLER_HS_CHANNEL_START_SYNC_STATUS = 0,
   FTM_HSDPA_BLER_HS_CHANNEL_STOP_SYNC_STATUS  = 1,
   FTM_HSDPA_BLER_HS_CHANNEL_RECFG_SYNC_STATUS  = 2
}
FTM_HSDPA_BLER_EVENT_STATUS_Enum;

/**
Structure to store the state of HSDPA BER.  This structure is used with the functions:
QLIB_FTM_HSDPA_BER_ClearStatus()
QLIB_FTM_HSDPA_BER_GetStatus()
*/
typedef struct
{
   /**
   Status array, indexed by log_FTM2_WCDMA_BER_log_id_enum

   Will be set to true if a log message was received for that log type
   */
   byte bHasUpdated[ FTM_LOG_HSDPA_EVENT_Count ];

   //
   // Related to FTM_LOG_HSDPA_HS_CHANNEL_START_IND
   //
   /**
   CHANNEL_START_IND.status = 0 = Start operation failed, 1 = Start operation success
   */
   byte iCHANNEL_START_IND_status;

   //
   // Related to FTM_LOG_HSDPA_HS_CHANNEL_STOP_IND
   //
   /**
   CHANNEL_STOP_IND.status = 0 = Stop operation failed, 1 = Stop operation success
   */
   byte iCHANNEL_STOP_IND_status;

   //
   // Related to FTM_LOG_HSDPA_HS_CHANNEL_RECFG_IND
   //
   /**
   CHANNEL_RECFG_IND.ReconfigureStatus = 0 = Reconfigure operation failed, 1 = Reconfigure operation success
   */
   byte iCHANNEL_RECFG_IND_ReconfigureStatus;
}  HSDPA_BER_State;

/******************************************************************************
FTM - TDSCDMA BER
*******************************************************************************/

/**
\brief Enumeration of FTM TDSCDMA BER commands.
*/
typedef enum
{
   _FTM_TDSCDMA_START_MODE_REQ      = 0,
   _FTM_TDSCDMA_STOP_MODE_REQ          = 1,
   _FTM_TDSCDMA_IDLE_MODE_REQ         = 2,//not currently supported by amss
   _FTM_TDSCDMA_ACQUIRE_REQ         = 3,
   _FTM_TDSCDMA_RMC_DCH_SETUP_REQ   = 4,
   _FTM_TDSCDMA_DROP_ALL_REQ    = 5,//note: diff from wcdma
   _FTM_TDSCDMA_BER_RMC_DCH_TFCS_CONFIG_REQ  = 6,
   _FTM_TDSCDMA_BER_EVENT_STATUS_CLEAR_REQ   = 7,
   _FTM_TDSCDMA_BER_EVENT_STATUS_REQ             = 8,
   _FTM_TDSCDMA_BER_SET_UL_POWER                 = 9,
   _FTM_TDSCDMA_BER_RX_LEVEL_REQ                 = 10,
   _FTM_TDSCDMA_BER_TPC_CONTROL              = 11,
   _FTM_TDSCDMA_BER_RSCP                         = 12,
   _FTM_TDSCDMA_HSUPA_BER_START            = 0x2000
} FTM_TDSCDMA_BER__SubCmd_Id_Enum;

/**
\brief event_type used by QLIB_FTM_TDSCDMA_BER_EVENT_STATUS_REQ
*/
typedef enum
{
   FTM_TDSCDMA_BER_START_TDSCDMA_MODE_CNF   = 0,
   FTM_TDSCDMA_BER_STOP_TDSCDMA_MODE_CNF    = 1,
   FTM_TDSCDMA_BER_IDLE_MODE_CNF            = 2,//not currently supported by amss
   FTM_TDSCDMA_BER_ACQ_CNF              = 3,
   FTM_TDSCDMA_BER_CPHY_SETUP_CNF       = 4,
   FTM_TDSCDMA_BER_PHYCHAN_ESTABLISHED_IND  = 5,
   FTM_TDSCDMA_BER_EVENT_STATUS_MAX
} FTM_TDSCDMA_BER_EVENT_STATUS_Enum;

/**
\brief error codes used by QLIB_FTM_TDSCDMA_BER_EVENT_STATUS_REQ
*/
typedef enum
{
   FTM_TDSCDMA_BER_SYNC_STATUS_SUCCESS                     = 0,
   FTM_TDSCDMA_BER_SYNC_STATUS_GEN_FAILURE                 = 1,
   FTM_TDSCDMA_BER_SYNC_STATUS_TIMEOUT_EXPIRED             = 2,
   FTM_TDSCDMA_BER_SYNC_STATUS_EVENT_STATUS_FAILED         = 3,
   FTM_TDSCDMA_BER_SYNC_STATUS_UNKNOWN_CMD                 = 4,
   FTM_TDSCDMA_BER_SYNC_STATUS_PWR_SETTING_OUT_OF_RANGE    = 5,
   FTM_TDSCDMA_BER_SYNC_STATUS_OVERRIDE_VALUE_UNSUPPORTED  = 6
} FTM_TDSCDMA_BER_SYNC_STATUS_ERROR_CODE_Enum;

/**
Structure of response packet for certian non-sigaling commands
CMD_CODE    - Message ID.       DM sets CMD_CODE to 75
SUB_SYS_ID  - FTM ID is 11.     Mode ID Mode ID for FTM TDSCDMA
Reserved    - 0
rsp_id      - 0x1002 = FTM_TDSCDMA_BER
rsp_cid     - Command ID that generated.
rsp_scid    - Subcommand ID that generated
Status      - 0 = DIAG_FTM_STATUS_SUCCESS. 1 = DIAG_FTM_STATUS_SUCCESS
*/
typedef struct
{
   byte  iCMD_Code;
   byte  iSubSysId;
   byte  iModeID;
   byte  iReserved;
   word iRspId;
   word iRspCid;
   word iRspSCid;
   byte  iStatus;
} FTM_TDSCDMA_BER_Response_Struct;

/*===========================================================================*/
/**
enum log_FTM2_TDSCDMA_BER_log_id_enum, 80-V9698-1_A

\brief Log ID's for the TDSCDMA BER FTM2 log message
*/
/*===========================================================================*/
typedef enum
{
   LOG_FTM2_TDSCDMA_START_MODE_CNF          = 0,        //!<' FTM TDSCDMA BER start TDSCDMA mode confirmation
   LOG_FTM2_TDSCDMA_STOP_MODE_CNF           = 1,        //!<' FTM TDSCDMA BER stop TDSCDMA mode confirmation
   LOG_FTM2_TDSCDMA_IDLE_MODE_CNF         = 2,      //!<' FTM TDSCDMA BER idle mode confirmation
   LOG_FTM2_TDSCDMA_ACQUIRE_CNF         = 3,        //!<' FTM TDSCDMA BER acquire confirmation
   LOG_FTM2_TDSCDMA_CPHY_SETUP_CNF          = 4,        //!<' FTM TDSCDMA BER CPHY setup confirmation
   LOG_FTM2_TDSCDMA_PHYCHAN_ESTABLISHED_IND= 5,     //!<' FTM TDSCDMA BER physical channel established confirmation
   LOG_FTM2_TDSCDMA_CPHY_ERROR_IND          = 6,        //!<' FTM TDSCDMA BER pyhsical channel error
   LOG_FTM2_TDSCDMA_RL_FAILURE_IND          = 7,        //!<' FTM TDSCDMA BER Reverselink error
   LOG_FTM2_TDSCDMA_BER_Max
} log_FTM2_TDSCDMA_BER_log_id_enum;

/*===========================================================================*/
/**
enum for TDSCDMA non-signaling power control type
*/
/*===========================================================================*/
typedef enum
{
   FTM_TDSCDMA_BER_TX_POWER_CONTROL_TYPE_AGC_SETPOINT,
   FTM_TDSCDMA_BER_TX_POWER_CONTROL_TYPE_RPC_ENABLE,
   FTM_TDSCDMA_BER_TX_POWER_CONTROL_TYPE_POWER_UP_BITS,
   FTM_TDSCDMA_BER_TX_POWER_CONTROL_TYPE_MAX
} FTM_TDSCDMA_BER_PowerControlType_Enum;

/*===========================================================================*/
/**
enum for TDSCDMA non-signaling RMC type
*/
/*===========================================================================*/
typedef enum
{
   FTM_TDSCDMA_BER_RMC_TYPE_12_2_SC            = 0,
   FTM_TDSCDMA_BER_RMC_TYPE_12_2_MC            = 1,
   FTM_TDSCDMA_BER_RMC_TYPE_64              = 2,
   FTM_TDSCDMA_BER_RMC_TYPE_144              = 3,
   FTM_TDSCDMA_BER_RMC_TYPE_384             = 4,
   FTM_TDSCDMA_BER_RMC_TYPE_MAX             = 5 //invalid
} FTM_TDSCDMA_BER_RMC_Type_Enum;

/*===========================================================================*/
/**
enum for TDSCDMA non-signaling Power Algorithm types
*/
/*===========================================================================*/
typedef enum
{
   FTM_TDSCDMA_BER_PCA_Size_0dB = 0,    //!<' 0dB for power control algorithm
   FTM_TDSCDMA_BER_PCA_Size_1dB = 1,    //!<' 1dB for power control algorithm
   FTM_TDSCDMA_BER_PCA_Size_2dB = 2,        //!<' 2dB for power control algorithm
   FTM_TDSCDMA_BER_PCA_Size_3dB  = 3,   //!<' 3dB for power control algorithm
   FTM_TDSCDMA_BER_PCA_Size_Invalid     //!<' invalid for power control algorithm
} FTM_TDSCDMA_BER_PCA_Size_Enum;

//hy todo: revise Rx/Tx agc struct once available

typedef enum
{
   FTM_TDSCDMA_BER_UL_TFCS_CONFIG = 0,
   FTM_TDSCDMA_BER_DL_TFCS_CONFIG = 1
} FTM_TDSCDMA_BER_TFCS_ConfigType;

/*---------------------------------------------------------------------------*/
/*                        TFW RF AGC Log                                     */
/*---------------------------------------------------------------------------*/
/**
\defgroup rfAgcLog RF AGC LOG
\ingroup rfSharedMemoryInterface
@verbatim
This section describes the RF AGC log
@endverbatim
*/
/*\{*/
typedef struct
{
   /*! \brief Received power in dBm*256
   float64 rxPowerdBm = ."rxPowerdBmData" / 256.0f*/
   long rxPowerdBm;
   /*! \brief LNA state */
   byte lnaState;
   /*! \brief DVGA gain */
   short rxfeDvgaGain;

   short reserved[5];
   //RSCP
} TFW_RX_AGC_RESULT_PER_CHAIN_T;

typedef struct
{
   /*! \brief subframe number */
   short sfn;
   /*! \brief slot number */
   short slot;
   /*! \brief antenna selection, 0:ant0, 1:ant1, 2:both */
   byte antennaSelect;
   /*! \brief operation frequency, Hz */
   dword operationFreq;
   /*! \brief frequency error, 32Q8, Hz */
   long freqError;
   /*! \brief rotator adjust */
   long rotatorVal;
   TFW_RX_AGC_RESULT_PER_CHAIN_T chains[2];
} TFW_RX_AGC_RESULT_BUF_T;

typedef struct
{
   /*! \brief Desired power from SW dBm*16
   ."desiredTxPwrData" / 16.0f;*/
   short   desiredTxPwrSW;
   /*! \brief actual TX power dBm*16
   ."actualTxChanPowerData" / 16.0f*/
   short actualTxChanPower;
   /*! \brief computed TX power dBm*16
   ."computedTxChanPowerData" / 16.0f*/
   short computedTxChanPower;
   /*! \brief  beta gain for data part of the physical channel
   (."betaDataData" / 32768.0f)*/
   short    betaData;
   /*! \brief  beta gain for midamble
   (."betaMidData" / 32768.0f)*/
   short    betaMid;
   /*! \brief PA backoff dB*16
   ."paBackoffData" / 16.0f*/
   word   paBackoff;
   short reserved[5];
} TFW_TX_AGC_RESULT_PER_CHANN_T;

typedef struct
{
   /*! \brief subframe number */
   word sfn;
   /*! \brief slot number */
   word slot;
   /*! \brief transmission frequency*/
   dword frequency;
   /*! \brief pathloss*/
   dword pathloss;
   /*! \brief Total TX power dBm*16
   "txOutputPowerData" / 16.0f*/
   short txOutputPower;
   /*! \brief maximum power ratio dBm*512
   mpr/512 dBm*/
   short mprValue;
   /*! \brief analog power dBm*512
   analogPwr/512 dBm*/
   short analogPwr;
   /*! \brief backoff at DAC dB*512
   dacBackoff/512 dB*/
   short dacBackoff;
   /*! \brief power compensation of temperature and frequency dB*512
   tempFreqPwrComp/512 dB*/
   short tempFreqPwrComp;
   /*! \brief MTPL, Max transmit power limit dBm*512
   "mtplData" / 512.0f*/
   word mtpl;
   /*! \brief Tx gain entry, 0-63*/
   word rfaGainLutIndex;
   /*! \brief PA Gain State, 0-3*/
   word paGainState;
   /*! \brief Flag indicating min power limits reached*/
   byte minPwrLimited;
   /*! \brief Flag indicating max power limits reached*/
   byte maxPwrLimited;
   /*! \brief Flag indicating transmit power override*/
   byte txPwrOverrideFlag;
   /*! \brief Transmit power override value*/
   short txPwrOverrideValue;

   /*! \brief rotator adjust */
   long rotatorVal;
   /*! \brief time advance */
   long TimingAdvance;

   /*! \brief per chan info*/
   TFW_TX_AGC_RESULT_PER_CHANN_T chans[2];
} TFW_TX_AGC_RESULT_BUF_T;

typedef struct
{
   byte Version;

   TFW_RX_AGC_RESULT_BUF_T RxAgcStruc;

   word        reserved[5];
} ftm_log_tdscdma_rx_agc_data_type;

typedef struct
{
   byte Version;

   TFW_TX_AGC_RESULT_BUF_T TxAgcStruc;

   word            hdet_raw;
   short             hdet;
   word            therm_raw;
   byte              therm_scaled;
   byte              temp_comp_index;
   byte              temp_comp_rem;
   short             smps_bias;
   short             reserved[5];
} ftm_log_tdscdma_tx_agc_data_type;

typedef struct
{
   word iFTM_LogID;
   ftm_log_tdscdma_rx_agc_data_type rx;
} FTM2LogMessage_TDSCDMA_RxAGC;

typedef struct
{
   word iFTM_LogID;
   ftm_log_tdscdma_tx_agc_data_type tx;
} FTM2LogMessage_TDSCDMA_TxAGC;

/**
Structure to store the state of TDSCDMA BER.  This structure is used with the functions:
QLIB_FTM_TDSCDMA_BER_ClearStatus()
QLIB_FTM_TDSCDMA_BER_GetStatus()
*/
typedef struct
{
   /**
   Status array, indexed by log_FTM2_TDSCDMA_BER_log_id_enum

   Will be set to true if a log message was received for that log type
   */
   byte bHasUpdated[ LOG_FTM2_TDSCDMA_BER_Max ];

   //
   // Related to ACQUIRE_CNF
   //
   /**
   ACQUIRE_CNF.Status = 0 = Acquisition failed, frequency and scr_code data not valid, 1 = Acquisition successful
   */
   byte iACQUIRE_CNF_status;

   //! ACQUIRE_CNF.Frequency = Frequency where CPICH was acquired
   dword iACQUIRE_CNF_frequency;

   //
   // Related to CPHY_SETUP_CNF
   //
   /**
   CPHY_SETUP_CNF.status
   0 = CPHY_SETUP request failed
   1 = CPHY_SETUP request successful.
   */
   byte iCPHY_SETUP_status;

   //
   // Related to PHYCHAN_ESTABLISHED_IND
   //
   /**
   PHYCHAN_ESTABLISHED_IND.status
   0 = Physical channel could not be established.
   1 = Physical channel was successfully established.
   */
   byte iPHYCHAN_ESTABLISHED_IND_status;

   //
   // TDSCDMA AGC message
   //
   //! Updated flag for TDSCDMA AGC
   byte bTDSCDMA_RxAGChasUpdated;
   byte bTDSCDMA_TxAGChasUpdated;

   //! Storage for TDSCDMA AGC
   FTM2LogMessage_TDSCDMA_RxAGC oTDSCDMA_RxAGC;
   FTM2LogMessage_TDSCDMA_TxAGC oTDSCDMA_TxAGC;
}  TDSCDMA_BER_State;

/******************************************************************************
FTM - TDSHSDPA BLER
*******************************************************************************/
//todo:

/******************************************************************************
FTM - GSM BER
*******************************************************************************/

/**
\brief Enumeration of FTM GSM BER commands.
*/
typedef enum
{
   _FTM_GSM_START_MODE_REQ              = 0,
   _FTM_GSM_SELECT_SPECIFIC_BCCH_REQ    = 1,
   _FTM_GSM_START_IDLE_MODE_REQ         = 2,
   _FTM_GSM_CONFIG_LOOPBACK_TYPE_REQ    = 3,
   _FTM_GSM_CHANNEL_ASSIGN_REQ          = 4,
   _FTM_GSM_CHANNEL_RELEASE_REQ         = 5,
   _FTM_GSM_STOP_GSM_MODE_REQ           = 6,
   _FTM_GSM_BER_CHANNEL_ASSIGN_V2_REQ   = 7,
   _FTM_GSM_BER_EVENT_STATUS_CLEAR_REQ  = 8,
   _FTM_GSM_BER_EVENT_STATUS_REQ        = 9,
   _FTM_GSM_BER_RX_LEVEL_REQ            = 10
} FTM_GSM_BER_SubCmd_Id_Enum;

/**
\brief Enumerations for GSM Band, for GSM BER tests
*/
typedef enum
{
   FTM_GSM_BER_PGSM_900,
   FTM_GSM_BER_EGSM_900,
   FTM_GSM_BER_PCS_1900,
   FTM_GSM_BER_DCS_1800,
   FTM_GSM_BER_CELL_850
} FTM_GSM_BER_Band_Enum;

/**
\brief Enumerations for GSM loopback types
*/
typedef enum
{
   FTM_GSM_BER_Disable_Loopback,
   FTM_GSM_BER_Loopback_Type_A,
   FTM_GSM_BER_Loopback_Type_B,
   FTM_GSM_BER_Loopback_Type_C
} FTM_GSM_BER_LoopbackType_Enum;

/**
\brief Enumerations for channel modes
*/
typedef enum
{
   FTM_GSM_BER_SPEECH_FULL_RATE,
   FTM_GSM_BER_SPEECH_HALF_RATE,
   FTM_GSM_BER_SPEECH_ENHANCED_FULL_RATE,
   FTM_GSM_BER_AMR_FULL_RATE,
   FTM_GSM_BER_AMR_HALF_RATE,
   FTM_GSM_BER_DATA_14_4_KBPS_FULL_RATE,
   FTM_GSM_BER_DATA_9_6_KBPS_FULL_RATE
} FTM_GSM_BER_Channel_Modes_Enum;
/**
\brief event_type used by QLIB_FTM_GSM_BER_EVENT_STATUS_REQ
*/
typedef enum
{
   FTM_GSM_BER_START_GSM_MODE_SYNC_STATUS                   = 0,
   FTM_GSM_BER_SELECT_SPECIFIC_BCCH_CNF_SYNC_STATUS     = 1,
   FTM_GSM_BER_START_IDLE_MODE_SYNC_STATUS                  = 2,
   FTM_GSM_BER_CHANNEL_ASSIGN_SYNC_STATUS                   = 3,
   FTM_GSM_BER_CHANNEL_RELEASE_SYNC_STATUS                  = 4,
   FTM_GSM_BER_STOP_GSM_MODE_SYNC_STATUS                    = 5,
   FTM_GSM_BER_SACCH_SYNC_STATUS                            = 6
} FTM_GSM_BER_EVENT_STATUS_Enum;

/* This type specifies the synchronous status types reported using
the FTM_GSM_BER_EVENT_STATUS_REQ command
*/
typedef enum
{
   FTM_GSM_BER_SYNC_STATUS_SUCCESS             = 0,
   FTM_GSM_BER_SYNC_STATUS_GEN_FAILURE         = 1,
   FTM_GSM_BER_SYNC_STATUS_TIMEOUT_EXPIRED     = 2,
   FTM_GSM_BER_SYNC_STATUS_EVENT_STATUS_FAILED = 3
} FTM_GSM_BER_SYNC_STATUS_ERROR_CODE_Enum;

/*===========================================================================*/
/**
struct GSM_EGPRS_CONFIGURE_DL_TBF_V2_Slot, 80-V5529-1

\brief A single DL slot configuration definition
*/
/*===========================================================================*/
typedef struct
{
   byte active;         //!<' 1 = Active, 0 = Inactive
   byte timeSlotNumber;    //!<' Time slot value: 0..7
} GSM_EGPRS_CONFIGURE_DL_TBF_V2_Slot;
/*===========================================================================*/
/**
struct GSM_EGPRS_CONFIGURE_DL_TBF_V2_Slot_Configuration, 80-V5529-1

\brief used by QLIB_FTM_EGPRS_BER_CONFIGURE_DL_TBF_V2 to pass downlink slot configuration
*/
/*===========================================================================*/
typedef struct
{
   GSM_EGPRS_CONFIGURE_DL_TBF_V2_Slot slots[8];
} GSM_EGPRS_CONFIGURE_DL_TBF_V2_Slot_Configuration;

/*===========================================================================*/
/**
struct GSM_EGPRS_CONFIGURE_UL_TBF_V2_Slot, 80-V5529-1

\brief A single UL slot configuration definition
*/
/*===========================================================================*/
typedef struct
{
   byte gamma;              //!<' Back off value from max power, 0 - 0dB, 1 - 2dB, 2, - 4dB,... , See description in  FTM_EGPRS_BER_CONFIGURE_UL_TBF_V2 command (80-V5529-1)
   byte active;         //!<' 1 = Active, 0 = Inactive
   byte timeSlotNumber; //!<' Time slot value: 0..7
} GSM_EGPRS_CONFIGURE_UL_TBF_V2_Slot;

/*===========================================================================*/
/**
struct GSM_EGPRS_CONFIGURE_UL_TBF_V2_Slot_Configuration, 80-V5529-1

\brief used by QLIB_FTM_EGPRS_BER_CONFIGURE_UL_TBF_V2 to pass downlink slot configuration
*/
/*===========================================================================*/
typedef struct
{
   GSM_EGPRS_CONFIGURE_UL_TBF_V2_Slot slots[8];
} GSM_EGPRS_CONFIGURE_UL_TBF_V2_Slot_Configuration;

/*===========================================================================*/
/**
enum log_FTM2_GSM_BER_log_id_enum, 80-V3951-1

\brief Log ID's for the GSM BER FTM2 log message
*/
/*===========================================================================*/
typedef enum
{
   LOG_FTM2_START_GSM_MODE_CNF          = 0,    //!<' Start GSM confirm
   LOG_FTM2_SELECT_SPECIFIC_BCCH_CNF        = 1,    //!<' FTM GSM BER select specific BCCH confirmation
   LOG_FTM2_START_IDLE_MODE_CNF         = 2,    //!<' FTM GSM BER start idle mode confirmation
   LOG_FTM2_CHANNEL_ASSIGN_CNF          = 3,    //!<' FTM GSM BER channel assign confirmation
   LOG_FTM2_CHANNEL_RELEASE_CNF         = 4,    //!<' FTM GSM BER channel release confirmation
   LOG_FTM2_STOP_GSM_MODE_CNF           = 5,    //!<' FTM GSM BER stop GSM mode confirmation
   LOG_FTM2_PH_DATA_IND                 = 6,    //!<' FTM GSM BER Ph data indication
   LOG_FTM2_FTM_LOG_GSM_BER_DED_RPT     = 7,    //!<' FTM GSM BER dedicated measurement report

   LOG_FTM2_FTM_LOG_GSM_MAX                 //!<' Size of list, not a valid log ID
} log_FTM2_GSM_BER_log_id_enum;

/*===========================================================================*/
/**
enum log_FTM2_GSM_BER_PH_Channel_Type_enum, 80-V3951-1

\brief Channel types for the PH_DATA_IND message
*/
/*===========================================================================*/
typedef enum
{
   LOG_FTM2_GSM_PH_IND_DCCH = 0,    //!<' DCCH
   LOG_FTM2_GSM_PH_IND_BCCH = 1,    //!<' BCCH
   LOG_FTM2_GSM_PH_IND_RACH = 2,    //!<' RACH
   LOG_FTM2_GSM_PH_IND_CCCH = 3,    //!<' CCCH
   LOG_FTM2_GSM_PH_IND_SACCH    = 4,    //!<' SACCH
   LOG_FTM2_GSM_PH_IND_SDCCH    = 5,    //!<' SDCCH
   LOG_FTM2_GSM_PH_IND_FACCH_F  = 6,    //!<' FACCH_F
   LOG_FTM2_GSM_PH_IND_FACCH_H  = 7,    //!<' FACCH_H

   LOG_FTM2_FTM_PH_IND_Chan_Max //!<' Size of list, not a valid channel ID
} log_FTM2_GSM_BER_PH_Channel_Type_enum;

/**
Structure to store the state of GSM BER.  This structure is used with the functions:
QLIB_FTM_GSM_BER_ClearStatus()
QLIB_FTM_GSM_BER_GetStatus()
*/
typedef struct
{
   /**
   Status array, indexed by log_FTM2_GSM_BER_log_id_enum

   Will be set to true if a log message was received for that log type
   */
   byte bHasUpdated[ LOG_FTM2_FTM_LOG_GSM_MAX ];

   //
   // Related to SELECT_SPECIFIC_BCCH_CNF
   //
   /**
   This confirmation indicates that the select specific BCCH request has completed, and reports
   whether the FCCH/SCH channels were detected, as well as the SCH data.

   0 = FCCH/SCH not found. Acquisition failed. 1 = FCCH/SCH acquired successfully.
   */
   byte bSCCH_Found;

   //! Data decoded from SCH channel. Data is only valid if bSCCH_Found?is 1.
   dword iSchData;

   //
   // Related to CHANNEL_ASSIGN_CNF
   //
   //! 0 = Success. >0 = Error occurred.
   byte iCHANNEL_ASSIGN_CNF_status;

   //
   // Related to PH_DATA_IND
   //
   /**
   The last channel type message:

   0 = DCCH
   1 = BCCH
   2 = RACH
   3 = CCCH
   4 = SACCH
   5 = SDCCH
   6 = FACCH_F
   7 = FACCH_H

   Not all of these channel_types are used during the BER test.
   */
   byte iPH_ChannelType;

   /**
   The last status:

   0 = Data block for the associated channel_type has not passed the
   crc_check
   1 = Data block for the associated channel_type has passed the
   crc_check
   */
   byte iPH_CRC_Pass;

   /**
   Array of channels, indicating whether a certain channel status has been received
   since the last time that status was cleared.
   */
   byte abHasPH_DATA_ReceivedChannelStatus[ LOG_FTM2_FTM_PH_IND_Chan_Max ] ;

   /**
   Array of channels, indicating channel status.  Only valid if the cooresponding
   abHasRecievedChannelStatus[] array index is set to true, to indicate that a status
   message for this channel has been received since the last time that status was cleared.
   */
   byte abPH_DATA_LastChannelStatus[ LOG_FTM2_FTM_PH_IND_Chan_Max ] ;

   //
   // Related to GSM_BER_DED_RPT
   //
   //! RxLev_Full as reported by Layer 1
   byte iDED_RPtRxLev_Full;

   //! RxQual_Full as reported by Layer 1
   byte iDED_RPtRxQual_Full;

   //
   // Related to call status, SACCH accumulator which indicates
   //
   //! Starting level for the SACCH counter, will be set to value of 40, but user can override
   short iGSM_BER_SACCH_Accumulator_Max;

   //! Current value of the SACCH counter, decremented 1 for a failed SACCH, incremented 1 for a good SACCH
   //! saturated at 0 on low end and iGSM_BER_SACCH_Count_max on the high end
   short iGSM_BER_SACCH_Accumulator_Value;

   //! Total number of updates that have been made to iGSM_BER_SACCH_Accumulator_Value.
   //! if the value is zero, then no updates have been made so status cannot be determined
   short iGSM_BER_SACCH_Accumulator_TotalUpdates;
}  GSM_BER_State;

/**
Enumeration to control whether a non-signaling session should be initialized
*/
typedef enum
{
   FTM_GSM_BER_SLOT_0  = 0,     //!<' Slot 0
   FTM_GSM_BER_SLOT_1  = 1,     //!<' Slot 1
   FTM_GSM_BER_SLOT_2  = 2,     //!<' Slot 2
   FTM_GSM_BER_SLOT_3  = 3,     //!<' Slot 3
   FTM_GSM_BER_SLOT_4  = 4,     //!<' Slot 4
   FTM_GSM_BER_SLOT_5  = 5,     //!<' Slot 5
   FTM_GSM_BER_SLOT_6  = 6,     //!<' Slot 6
   FTM_GSM_BER_SLOT_7  = 7          //!<' Slot 7
} FTM_GSM_BER_Slot_Enum;

/******************************************************************************
FTM - EGPRS BLER
*******************************************************************************/

/**
Enumeration of EGPRS BER log events
*/
typedef enum
{
   FTM_LOG_EGPRS_BER_TBF_IND           = 0x40,
   FTM_LOG_EGPRS_BER_MAC_PH_DATA_IND,
   FTM_LOG_EGPRS_BER_SERVING_MEAS_IND,

   // Identifiers to help with the size of the event list
   FTM_LOG_EGPRS_EVENT_Max,                                         //!< ' Maximum ID + 1
   FTM_LOG_EGPRS_EVENT_First    = FTM_LOG_EGPRS_BER_TBF_IND,            //!< ' First valid ID
   FTM_LOG_EGPRS_EVENT_Last = FTM_LOG_EGPRS_EVENT_Max - 1,          //!< ' Last valid ID
   FTM_LOG_EGPRS_EVENT_Count    = FTM_LOG_EGPRS_EVENT_Max -
                                  FTM_LOG_EGPRS_EVENT_First           //!< ' Size of valid list
} log_FTM2_EGPRS_BER_log_id_enum;

/**
This enumeration specifies the types of TBFs that we generate events for
*/

typedef enum
{
   FTM_LOG_EGPRS_BER_TBF_DL,    //!<' 0 = DL TBF
   FTM_LOG_EGPRS_BER_TBF_UL //!<' 1 = UL TBF
} ftm_log_egprs_tbf_enum;

/**
This enumeration specifies the sub-event types for the FTM_LOG_EGPRS_BER_TBF_IND EVENT
*/
typedef enum
{
   FTM_LOG_EGPRS_TBF_EVENT_ESTABLISHED, //!<' TBF Established. TBF type indicated in
   //!<' tbf_type field has been successfully established.

   FTM_LOG_EGPRS_TBF_EVENT_RELEASED,        //!<' TBF Released. TBF type indicated in tbf_type field has been
   //!<' successfully released.

   FTM_LOG_EGPRS_TBF_EVENT_ERROR            //!<' TBF Error. An error has occurred related to the TBF indicated in
   //!<' the tbf_type field. This may require a reconfiguration of the TBF
   //!<' before proceeding.
} ftm_log_egprs_tbf_event_type;

/**
Structure to store the state of EGPRS BER.  This structure is used with the functions:
QLIB_FTM_EGPRS_BER_ClearStatus()
QLIB_FTM_EGPRS_BER_GetStatus()
*/
typedef struct
{
   /*

   Events represented:
   FTM_LOG_EGPRS_BER_TBF_IND
   FTM_LOG_EGPRS_BER_MAC_PH_DATA_IND,
   FTM_LOG_EGPRS_BER_SERVING_MEAS_IND,
   */

   /**
   Status array, indexed by log_FTM2_EGPRS_BER_log_id_enum

   Will be set to true if a log message was received for that log type
   */
   byte bHasUpdated[ FTM_LOG_EGPRS_EVENT_Count ];

   //
   // Related to FTM_LOG_EGPRS_BER_TBF_IND
   //
   /**
   Type of event the event is for:
   \code
   0 = DL TBF
   1 = UL TBF
   \endcode

   Type can be cast as: ftm_log_egprs_tbf_type

   */
   byte bTBF_IND_type;

   /**
   This indication informs the user of an event related to either the DL or UL TBF.

   \code
   0 = TBF Established. TBF type indicated in tbf_type field has been
   successfully established.

   1 = TBF Released. TBF type indicated in tbf_type field has been
   successfully released.

   2 = TBF Error. An error has occurred related to the TBF indicated in
   the tbf_type field. This may require a reconfiguration of the TBF
   before proceeding.
   \endcode

   Type can be cast as: ftm_log_egprs_tbf_event_type
   */
   byte eTBF_IND_UL_event;

   //! DL status, same as the UL values
   byte eTBF_IND_DL_event;

   //
   // Related to FTM_LOG_EGPRS_BER_SERVING_MEAS_IND
   //
   //! RxLev_average as reported by Layer 1. Range should be 0-63.
   byte iSERVING_MEAS_IND_RxLev_average;
}  EGPRS_BER_State;

/**
\brief event_type used by QLIB_FTM_EGPRS_BER_EVENT_STATUS_REQ
*/
typedef enum
{
   FTM_EGPRS_BER_UL_TBF_ESTABLISHED_SYNC_STATUS     = 0,
   FTM_EGPRS_BER_UL_TBF_RELEASED_SYNC_STATUS            = 1,
   FTM_EGPRS_BER_DL_TBF_ESTABLISHED_SYNC_STATUS     = 2,
   FTM_EGPRS_BER_DL_TBF_RELEASED_SYNC_STATUS            = 3
} FTM_EGRPS_BER_EVENT_STATUS_Enum;
/******************************************************************************
FTM - FTM_AP Log Struct
*******************************************************************************/
typedef struct
{
   dword  iTestStatus;
   char   sTestName[256];
} FTM_AP_Log;

/******************************************************************************
FTM - Common RF
*******************************************************************************/

/**
This enumeration specifies the RX Action list for the FTM_TX_RX_FREQ_CAL_SWEEP function
*/
typedef enum
{
   FTM_TX_RX_FREQ_RX_ACTION_LNA0    = 0,    //!<' - calibrate LNA offset 0
   FTM_TX_RX_FREQ_RX_ACTION_LNA1    = 1,    //!<' - calibrate LNA offset 1
   FTM_TX_RX_FREQ_RX_ACTION_LNA2    = 2,    //!<' - calibrate LNA offset 2
   FTM_TX_RX_FREQ_RX_ACTION_LNA3    = 3,    //!<' - calibrate LNA offset 3
   FTM_TX_RX_FREQ_RX_ACTION_LNA4    = 4,    //!<' - calibrate LNA offset 4
   FTM_TX_RX_FREQ_RX_ACTION_DVGA    = 100,  //!<' - calibrate DVGA offset
   FTM_TX_RX_FREQ_RX_ACTION_NOTHING = 255   //!<' - do nothing
} ftm_tx_rx_freq_cal_sweep_rx_action_enum;

/**
This enumeration specifies RX chain list for the FTM_TX_RX_FREQ_CAL_SWEEP function
*/
typedef enum
{
   FTM_TX_RX_FREQ_RX_CHAIN_0        = 0,    //!<' - Primary RX
   FTM_TX_RX_FREQ_RX_CHAIN_1        = 1     //!<' - Secondary RX
} ftm_tx_rx_freq_cal_sweep_rx_chain_enum;

/**
List specifying the rx power mode to use for each step of a given frequency.
The values are ignored for chipsets that do not support rx power modes.
*/
typedef enum
{
   FTM_TX_RX_FREQ_RX_PM_High        = 0,    //!<' - Rx high power mode
   FTM_TX_RX_FREQ_RX_PM_Medium      = 1,    //!<' - Rx medium power mode
   FTM_TX_RX_FREQ_RX_PM_Low     = 2     //!<' - Rx low power mode
} ftm_tx_rx_freq_cal_sweep_rx_power_mode_enum;

/**
Maximum number of frequencies
*/
#define FTM_TX_RX_FREQ_MAX_FREQUENCIES 16

/**
Maximum number of Segments per frequency
*/
#define FTM_TX_RX_FREQ_MAX_SEGMENTS 20

/**
Structure that contains a super set of the command request parameters and the
resulting log.  Divided into an inputs section and outputs section.

To be used with the function QLIB_FTM_TX_RX_FREQ_CAL_SWEEP()
*/

typedef struct
{
   /**
   Inputs, must be filled in before the QLIB_FTM_TX_RX_FREQ_CAL_SWEEP() function is called, but
   will also be overwritten by the response data.

   */
   /**
   Specifies which rx chain is active for each segment
   \code
   FTM_TX_RX_FREQ_RX_CHAIN_0 = 0, //!<' - Primary RX
   FTM_TX_RX_FREQ_RX_CHAIN_1 = 1  //!<' - Secondary RX
   \endcode
   */
   word iRxChain;

   /**
   The number of frequencies on which the calibration procedure will be performed. Maximum is 16.
   */
   byte iNumFreqs;

   /**
   The number of steps per frequency. A step corresponds to a power level at which tx
   and rx measurements may be performed. This number must include one step for switching
   frequency. Maximum value is 6.
   */
   byte iNumSteps;

   /**
   The length of one power step in units of sleep counter cycles. Minimum value is 655 (20ms).
   */
   word iStepLength;

   /**
   List of uplink channel numbers on which calibration is to be performed. Must have num_freqs elements.
   */
   word aiChannelList[ FTM_TX_RX_FREQ_MAX_FREQUENCIES ];

   /**
   List giving the tx pdm to set for each step. Must have num_steps elements.
   */
   word aiTxPDM_List[ FTM_TX_RX_FREQ_MAX_SEGMENTS ];

   /**
   The expected agc value used as the input to the LNA or DVGA offset calibration routine
   for the primary RX path for each step. If rx_action_list is 255 for a particular step then
   the expected agc value is not used.
   */
   short aiExpectedRxAGC_ValList[ FTM_TX_RX_FREQ_MAX_SEGMENTS ];

   /**
   List giving the desired PA range for each step at a given frequency. Must have
   num_steps elements. A value of 255 indicates no tx activity will take place for that step.
   */
   byte aiPA_RangeList[ FTM_TX_RX_FREQ_MAX_SEGMENTS ];

   /**
   Flag indicating whether to take an HDET measurement for each step. Zero
   indicates an HDET measurement will not be taken, a non-zero value indicates an
   HDET measurement will be taken.
   */
   byte aiReadHDET_List[ FTM_TX_RX_FREQ_MAX_SEGMENTS ];

   /**
   List specifying the rx action to take for each step of a given frequency.

   Valid values are defined by the enumeration ftm_tx_rx_freq_cal_sweep_rx_action_enum:
   \code
   FTM_TX_RX_FREQ_RX_ACTION_LNA0    = 0,    //!<' - calibrate LNA offset 0
   FTM_TX_RX_FREQ_RX_ACTION_LNA1    = 1,    //!<' - calibrate LNA offset 1
   FTM_TX_RX_FREQ_RX_ACTION_LNA2    = 2,    //!<' - calibrate LNA offset 2
   FTM_TX_RX_FREQ_RX_ACTION_LNA3    = 3,    //!<' - calibrate LNA offset 3
   FTM_TX_RX_FREQ_RX_ACTION_LNA4    = 4,    //!<' - calibrate LNA offset 4
   FTM_TX_RX_FREQ_RX_ACTION_DVGA    = 100,  //!<' - calibrate DVGA offset
   FTM_TX_RX_FREQ_RX_ACTION_NOTHING = 255   //!<' - do nothing
   \endcode
   */
   byte aiRxActionList[ FTM_TX_RX_FREQ_MAX_SEGMENTS ];

   /**
   List specifying the rx power mode to use for each step of a given frequency.
   The values are ignored for chipsets that do not support rx power modes.
   Valid values are:
   \code
   FTM_TX_RX_FREQ_RX_PM_High        = 0,    //!<' - Rx high power mode
   FTM_TX_RX_FREQ_RX_PM_Medium      = 1,    //!<' - Rx medium power mode
   FTM_TX_RX_FREQ_RX_PM_Low     = 2     //!<' - Rx low power mode
   \endcode
   */
   byte aiRxPowerMode[ FTM_TX_RX_FREQ_MAX_SEGMENTS ];

   /**
   Output, will be filled in by QLIB_FTM_TX_RX_FREQ_CAL_SWEEP()

   */
   /**
   The result of the requested rx calibration on the primary receive path (if any) for
   a given step and frequency. The results are ordered as each step for the first frequency,
   followed by each step for the second frequency, etc.
   */
   word aiRxResults[FTM_TX_RX_FREQ_MAX_FREQUENCIES][ FTM_TX_RX_FREQ_MAX_SEGMENTS ];

   /**
   The HDET value for each step and each frequency. If read_hdet_list is not set to one
   for a particular step than hdet_results should be ignored for the corresponding steps.
   The results are ordered as each step for the first frequency, followed by each step for
   the second frequency, etc.
   */
   word aiHDET_Results[FTM_TX_RX_FREQ_MAX_FREQUENCIES][ FTM_TX_RX_FREQ_MAX_SEGMENTS ];

   /**
   This value will be set to a 1 if the response log received from the mobile includes
   the extended fields for rx_chain_list and rx_lpm_list.

   If this value is zero, then the values of aiRxChainList and aiRxPowerMode should
   not be used
   */
   unsigned char bIsExtendedFormat;
} FTM_Tx_Rx_Freq_Cal_Sweep_Request_Response;

#define MAX_GSM_RX_SWEEP_FRAMES 100
#define GSM_RX_SWEEP_SLOT_PER_FRAME 8

/**
FTM GSM Rx sweep calibration state enumeration
*/
typedef enum
{
   L1_FTM_RX_SWEEP_STATUS_NULL                      = 1,    //!<' Status null
   L1_FTM_RX_SWEEP_STATUS_FCCH_STARTED              = 2,    //!<' FCCH acquisition started
   L1_FTM_RX_SWEEP_STATUS_FCCH_FAIL             = 3,    //!<' FCCH acquisition failed
   L1_FTM_RX_SWEEP_STATUS_FCCH_SUCCESS              = 4,    //!<' FCCH acquisition successful
   L1_FTM_RX_SWEEP_STATUS_SCH_STARTED               = 5,    //!<' SCH acquisition started
   L1_FTM_RX_SWEEP_STATUS_SCH_FAIL                  = 6,    //!<' SCH acquisition failed
   L1_FTM_RX_SWEEP_STATUS_SCH_SUCCESS               = 7,    //!<' SCH acquisition successful
   L1_FTM_RX_SWEEP_STATUS_POWER_MEAS_STARTED        = 8,    //!<' RSSI power measurements started
   L1_FTM_RX_SWEEP_STATUS_POWER_MEAS_ABORTED        = 9,    //!<' RSSI power measurements aborted
   L1_FTM_RX_SWEEP_STATUS_POWER_MEAS_COMPLETE       = 10    //!<' RSSI power measurements done - Success
} ftm_gsm_rx_freq_cal_sweep_state_type;

/**
Structure that is part of the FTM response packet for GSM Rx Sweep Calibration.
Contains the status and number of frames in the packet.
*/
typedef struct
{
   word iStatus;            //<!' GSM Rx Sweep status
   word iNumFrames;     //<!' Number of frames in the response packet
} ftm_gsm_rx_freq_cal_sweep_response_hdr;

/**
Structure that is part of the FTM response packet for GSM Rx Sweep Calibration.
Contains the contents of a single frame in the response.
*/
typedef struct
{
   dword  aRSSI[GSM_RX_SWEEP_SLOT_PER_FRAME];       //<!' RSSI measurements for each measure
} ftm_gsm_rx_freq_cal_sweep_response_frame;

/**
Structure that contains a super set of the command request parameters and the
resulting log.  Divided into an inputs section and outputs section.

To be used with the function QLIB_FTM_GSM_RX_FREQ_CAL_SWEEP()
*/
typedef struct
{
   /**
   Inputs: must be filled in when QLIB_FTM_GSM_RX_FREQ_CAL_SWEEP() is called
   */
   //! FCCH/SCH channel
   word iFchChan;
   //! FCCH/SCH band
   word iFchBand;
   //! Number of measurement frames
   word iNumFrames;
   //! Band list for all frames
   word aBand[MAX_GSM_RX_SWEEP_FRAMES];
   //! Channel list for all frames
   word aChan[MAX_GSM_RX_SWEEP_FRAMES];
   //! Gain range list for slots in all frames
   byte aGainState[MAX_GSM_RX_SWEEP_FRAMES][GSM_RX_SWEEP_SLOT_PER_FRAME];
   /**
   Outputs: will be filled by QLIB_FTM_GSM_RX_FREQ_CAL_SWEEP()
   */
   //! Sweep result status
   ftm_gsm_rx_freq_cal_sweep_state_type  iStatus;
   //! RSSI measurements
   dword aRSSI[MAX_GSM_RX_SWEEP_FRAMES][GSM_RX_SWEEP_SLOT_PER_FRAME];
} FTM_GSM_Rx_Freq_Cal_Sweep_Request_Response;

#define FTM_TCXOMGR_CAL_NUM_SAMPLES   127       /* max number of samples to record                       */

/**
XO Calibration to write calibration data to NV or not
*/
typedef enum
{
   FTM_TCXOMGR_CAL_RECORD_NONE = 0x0,                 /* do not record            */
   FTM_TCXOMGR_CAL_RECORD_RAM  = 0x1,                 /* record to RAM            */
   FTM_TCXOMGR_CAL_RECORD_NV   = 0x3                 /* record to RAM and NV     */
} ftm_tcxomgr_cal_record_enum_type;

typedef enum
{
   FTM_TCXOMGR_CAL_FT_QUAL_NOT_CAL,                   /* uncalibrated             */
   FTM_TCXOMGR_CAL_FT_QUAL_FAC1,                      /* 56 PPM mode              */
   FTM_TCXOMGR_CAL_FT_QUAL_FT1,                       /*  5 PPM mode              */
   FTM_TCXOMGR_CAL_FT_QUAL_FT2,                       /*  3 PPM mode              */
   FTM_TCXOMGR_CAL_FT_QUAL_FAILED                      /* 56 PPM mode
                                                       (Fac Cal Failed, phone
                                                       should have failed in
                                                       Factory)                */
} ftm_tcxomgr_cal_ft_qual_enum_type;

/**
XO Calibration return status state
*/
typedef enum
{
   FTM_TCXOMGR_CAL_STATE_NOT_CAL,                     /* intial uncalibrated state*/
   FTM_TCXOMGR_CAL_STATE_COARSE,                      /* Coarse tuning completed  */
   FTM_TCXOMGR_CAL_STATE_SAMP,                        /* Samples Captured         */
   FTM_TCXOMGR_CAL_STATE_C1C2C3,                      /* C1C2C3 determined        */
   FTM_TCXOMGR_CAL_STATE_FINE,                        /* Fine tuning completed    */
   FTM_TCXOMGR_CAL_STATE_COMPLETED,                   /* Fac Cal completed        */
   FTM_TCXOMGR_CAL_STATE_FAILED                      /* Fac Cal failed           */
} ftm_tcxomgr_cal_state_enum_type;

/**
FTM calibration state enumeration
*/
typedef enum
{
   CAL_STATE_INACTIVE = 0,
   CAL_STATE_ACTIVE = 1
} ftm_cal_state_type;

typedef struct
{
   dword          xo;               /* 2^-10 C, XTAL temp       */
   dword          pmic;              /* 2^-10 C, PMIC temp       */
   dword          pa;                /* 2^-10 C, PA temp         */
} ftm_tcxomgr_temp_set_type;

typedef struct
{
   ftm_tcxomgr_temp_set_type      min;                /* min temps encountered in calibration */
   ftm_tcxomgr_temp_set_type      max;                /* max temps encountered in calibration */
} ftm_tcxomgr_cal_temp_range_type;

/**
XO calibraiton fac data type
*/
typedef struct
{
   dword                      c3;                 /* units of 2^-32 ppm/C^3  */
   dword                      c2;                 /* units of 2^-28 ppm/C^2  */
   dword                      c1;                 /* units of 2^-24 ppm/C    */
   dword                      c0;                 /* units of 2^-12 ppm      */
   dword                         t0;                 /* Ref XO Temp term units of 2^-10 C       */
   dword                         t0p;                /* Ref PMIC Temp term units of 2^-10 C       */
   dword                      p;                  /* PMIC compensation factor*/
   byte                      ft_qual_ind;        /* quality indicator of the coefficients       */
   unsigned char               xo_trim;           /* corresponding xo_trim val for coefficients   */
} ftm_tcxomgr_cal_fac_data_type;

/**
XO Trim value
*/
typedef struct
{
   unsigned char current;                        /* current normal used in phone */
   unsigned char table;                            /* table used(for debug) */
} ftm_tcxomgr_cal_trim_value;

/**
XO calibration info type
*/
typedef struct
{
   unsigned char                        init_xo_trim;       /* pre FacCal xo_trim val   */
   unsigned char                        dc_xo_trim;         /* post Coarse DC xo_trim   */
   unsigned char                     fin_xo_trim;        /* post Fine DC xo_trim     */
   unsigned char                     final_xo_trim;      /* post FacCal xo_trim val  */
   dword                                s_ram_cap_cnt;      /* num of SRAM captures     */
   dword                                freq_est_calc_cnt;  /* num freq est calculations*/
   ftm_tcxomgr_temp_set_type            init_temp;          /* initial temp (XO,PMIC,PA)*/
   ftm_tcxomgr_temp_set_type            final_temp;         /* final temp (XO,PMIC,PA)  */
   ftm_tcxomgr_cal_temp_range_type  temp_range;        /* temp range encountered   */
} ftm_tcxomgr_cal_info_type;

/**
SELF CAL DAC Cal Value
*/
#define RFCOMMON_NUM_TXDAC_NUM_MSB_RESULTS     36
#define RFCOMMON_NUM_TXDAC_NUM_DC_RESULTS      1
#define RFCOMMON_NUM_ETDAC_NUM_MSB_RESULTS     18
#define RFCOMMON_NUM_ETDAC_NUM_RPOLY_RESULTS   1

typedef struct
{
   /* DAC cal results per chain
         IQ DAC MSB cal - 36x24 reg array
         IQ DAC DC cal   - 14-bits
         ET DAC MSB cal - 18x24 reg array
         ET DAC Rpoly    -  8-bits */
   uint8  txdac_msb_result_valid;
   uint32 txdac_msb_results[RFCOMMON_NUM_TXDAC_NUM_MSB_RESULTS];
   uint8  txdac_dc_result_valid;
   uint32 txdac_dc_results[RFCOMMON_NUM_TXDAC_NUM_DC_RESULTS];
   uint8  etdac_msb_result_valid;
   uint32 etdac_msb_results[RFCOMMON_NUM_ETDAC_NUM_MSB_RESULTS];
   uint8  etdac_rpoly_result_valid;
   uint32 etdac_rpoly_results[RFCOMMON_NUM_ETDAC_NUM_RPOLY_RESULTS];
} ftm_selfcal_dac_cal_data_type;

/* tcxomgr factory failure reasons */
typedef enum
{
   TCXOMGR_CAL_FAIL_NONE,                   /* Passed successfully            */
   TCXOMGR_ERR_EST_FAIL_UNSUPPORTED_TECH,   /* Tech is not supported          */
   TCXOMGR_ERR_EST_FAIL_DC_OFFSET_FAR,      /* DC Offset far off check offset */
   TCXOMGR_ERR_EST_FAIL_SAMPLE_XO_TEMP,     /* Xo fluctuates over IQ sample   */
   TCXOMGR_ERR_EST_FAIL_SAMPLE_PMIC_TEMP,   /* Pmic fluctuates over IQ sample */
   TCXOMGR_ERR_EST_FAIL_SAMPLE_ROTATOR,     /* Rotators are not zero          */
   TCXOMGR_CAL_FAIL_TRIM_SATURATED,         /* Reached the trim limits        */
   TCXOMGR_CAL_FAIL_TEMP_SPAN,              /* Failed req degree change       */
   TCXOMGR_CAL_FAIL_TEMP_LESS_THAN_MIN,     /* XO temp less than allowed      */
   TCXOMGR_CAL_FAIL_TEMP_MORE_THAN_MAX,     /* XO temo more than allowed      */
   TCXOMGR_ERR_EST_FAIL_NOISY_IQ,           /* Noisy IQ samples               */
   TCXOMGR_ERR_EST_FAIL_PHASE_JUMPS,        /* Phase jumps in IQ              */
   TCXOMGR_ERR_EST_FAIL_MSGR_INIT,          /* Message router error           */
   TCXOMGR_ERR_EST_FAIL_MSGR_SEND,          /* Message router error           */
   TCXOMGR_ERR_EST_FAIL_MSGR_RECV,          /* Message router error           */
   TCXOMGR_ERR_EST_FAIL_FATAL_ERROR,
   TCXOMGR_CAL_FAIL_TEMP_SPAN_TIMEOUT = 16,     /* XO temp span time out reached  */
   TCXOMGR_CAL_FAIL_TEMP_MAX_SAMPLES = 17,      /* XO max samples reached         */
   TCXOMGR_CAL_FAIL_TEMP_SPAN_TOO_SMALL = 18,   /* XO temp span is too small      */
   TCXOMGR_CAL_FAIL_UNKNOWN_ERROR
} ftm_tcxomgr_cal_failure_enum_type;

typedef struct
{
   unsigned char                        init_xo_trim;           /* pre FacCal xo_trim val   */
   unsigned char                        dc_xo_trim;             /* post Coarse DC xo_trim   */
   unsigned char                     fin_xo_trim;        /* post Fine DC xo_trim     */
   unsigned char                     final_xo_trim;      /* post FacCal xo_trim val  */

   dword                      init_xo_freqerr;           /* pre FacCal freqerr       */
   dword                      dc_xo_freqerr;             /* post Coarse DC freqerr   */
   dword                      fin_xo_freqerr;            /* post Fine DC freqerr     */
   dword                      final_xo_freqerr;          /* post FacCal freqerr      */

   dword                                s_ram_cap_cnt;             /* num of SRAM captures     */
   dword                                freq_est_calc_cnt;         /* num freq est calculations*/

   ftm_tcxomgr_temp_set_type            init_temp;           /* initial temp (XO,PMIC,PA)*/
   ftm_tcxomgr_temp_set_type            final_temp;          /* final temp (XO,PMIC,PA)  */
   ftm_tcxomgr_cal_temp_range_type  temp_range;          /* temp range encountered   */
   ftm_tcxomgr_cal_failure_enum_type fail_reason;  /* Failure reason           */
} ftm_tcxomgr_cal_info_type_v2;

/**
XO calibration FT Sample type
*/
typedef struct
{
   ftm_tcxomgr_temp_set_type     xo_temp[ FTM_TCXOMGR_CAL_NUM_SAMPLES ];        /* 2^-10 C, XTAL temp       */
   dword                            xo_freq[ FTM_TCXOMGR_CAL_NUM_SAMPLES ];     /* 2^-12 ppm, XO frequency  */
   dword                            c1_est;                                     /* estimate for coef C1     */
   dword                            num_samples;                                /* num samples taken        */
   ftm_tcxomgr_cal_temp_range_type temp_range;                              /* temp range encountered   */
} ftm_tcxomgr_cal_ft_sample_type;

/**
FTM request packet for XO calibration
*/
typedef struct
{
   word  iReserved;         //<!' Reserved set to 0
   dword iOffset;               //<!' Frequency offset (Hz)
   dword iTemp_Span;            //<!' time span (ms)
   word  iMin_ft_samples;       //<!' min sample (3)
   word  iMax_ft_samples;       //<!' max sample (100)
   word  iSubstage_Time;        //<!' Substage time
   word  iPdm_value;            //<!' Tx PDM
   word iPA_range;              //<!' PA range
   word  iTimeOut;              //<!' timeout --> msec for SC2X and LCU projects but sec for SCMM because of the long wait time for 1C temp span
   dword  iWrite_NV;            //<!' 0 to write NV
}   FTM_XO_Cal_Request;

/**
FTM response packet for XO calibration
*/
typedef struct
{
   byte cmd;                                               //<' Command ID (75)
   byte subsys;                                        //<' Subsystem (11)
   word mode;                                          //<' Mode ID (20)
   word ftm_cmd;                                           //<' FTM command id
   word req_len;                                           //<' FTM request length (not used)
   word resp_len;                                      //<' FTM response length (not used)
   word state;                                          //<!' State of coefficients
   ftm_tcxomgr_cal_fac_data_type   nom_coef;                //<!' nominal coefficients
   word reserved;
   ftm_tcxomgr_cal_fac_data_type   cal_coef;                //<!' calibrated coefficients
   word reserved1;
   ftm_tcxomgr_cal_info_type     tcxomgr_cal_info_pkt;  //<!' calibration information
} FTM_XO_Cal_Response;

typedef struct
{
   byte cmd;                                               //<' Command ID (75)
   byte subsys;                                        //<' Subsystem (11)
   word mode;                                          //<' Mode ID (20)
   word ftm_cmd;                                           //<' FTM command id
   word req_len;                                           //<' FTM request length (not used)
   word resp_len;                                      //<' FTM response length (not used)
   word state;                                          //<!' State of coefficients
   ftm_tcxomgr_cal_fac_data_type   nom_coef;                //<!' nominal coefficients
   word reserved;
   ftm_tcxomgr_cal_fac_data_type   cal_coef;                //<!' calibrated coefficients
   word reserved1;
   ftm_tcxomgr_cal_info_type_v2      tcxomgr_cal_info_pkt;  //<!' calibration information
} FTM_XO_Cal_Response_v2;

typedef struct
{
   word  iReserved1;            //<!' Reserved set to 0
   dword iOffset;               //<!' Frequency offset (Hz)
   dword iTemp_Span;            //<!' time span (ms)
   word  iMin_ft_samples;       //<!' min sample (3)
   word  iMax_ft_samples;       //<!' max sample (100)
   word  iSubstage_Time;        //<!' Substage time
   word  iTimeOut;              //<!' timeout (ms)
   byte  iTechnology;           //<!' Technology. 0 - 1x,1- WCDMA,2 - GSM. (enums are not bytes).
   byte  iReserved2;            //<!' Reserved set to 0
   word  iReserved3;            //<!' Reserved set to 0
   dword iRxFreq;               //<!' Rx Frequency in kHz.
   dword  iWrite_NV;            //<!' 0 to write NV
}   FTM_ENH_XO_Cal_Request;

typedef enum
{
   XO_DC_COARSE_CAL     = 1,
   XO_COLLECT_SAMPLES   = 2,
   XO_FT_CURVE_CAL      = 3
}
ftm_xo_cal_command_type;

typedef struct
{
   byte  technology;                        /*!<  Technology
                                            tcxomgr_cal_xo_cal_tech enum:
                                            TECHNOLOGY_CDMA     = 0,
                                            TECHNOLOGY_WCDMA    = 1,
                                            TECHNOLOGY_GSM      = 2,
                                            TECHNOLOGY_LTE      = 3,
                                            TECHNOLOGY_TDSCDMA  = 4,
                                            TECHNOLOGY_CDMA_SEC = 5,
                                            TECHNOLOGY_MAX      = 6*/
   dword rx_freq_khz;                        /*!< Carrier frequency in kHz*/
   dword  offset;                            /*!< Single tone freq offset relative to the carrier freq in Hz */
   dword  temp_span;                         /*!< Temperature span for factory calibration */
   word min_ft_samples;                      /*!< Min number of FT samples */
   word max_ft_samples;                      /*!< Max number of FT Samples */
   word substage_time;                       /*!< Time to wait between samp substages (ms)*/
   word timeout_time;                        /*!< Maximum time to run each step before declaring failure (ms) */
   byte update_nv;                           /*!< Decides if TCXO manager writes XO cal Nv
                                             TCXOMGR_CAL_RECORD_NONE = 0x0 - do not record
                                             TCXOMGR_CAL_RECORD_RAM  = 0x1 - record to RAM
                                             TCXOMGR_CAL_RECORD_NV   = 0x3 - record to RAM and NV     */
   word wb_id;                               /*!< WB device ID used for IQ capture; Currently unused  */
   word temp_grad_timeout;                   /*!< Timeout value to reach req temp */
   byte xtal;                                /*!<  XTAL package used in the device
                                             tcxomgr_cal_xtal_enum_type:
                                             TCXOMGR_XTAL_DEFAULT = 0,
                                             TCXOMGR_XTAL_2016    = 1,
                                             TCXOMGR_XTAL_2520    = 2,
                                             TCXOMGR_XTAL_MAX */
} ftm_xo_cal_parameter_type;

/**
FTM Tx waveform attribute type
*/
typedef enum
{
   CW_OFFSET_ZER0_KHZ = 0,
   CW_OFFSET_19_2_KHZ = 1
} ftm_tx_waveform_attrib_type;

/**
FTM Tx waveform type
*/
typedef enum
{
   CDMA_WAVEFORM = 0,
   CW_WAVEFORM = 1
} ftm_tx_waveform_type;

typedef struct
{
   word iChannel;
   byte ipaRange[MAX_PA_STATES];                                    //<!' Tx sweep PA Ranges
   byte inum_pwr_list[MAX_PA_STATES];                               //<!' Tx sweep Power list sizes
   byte tx_lin_pdm_list[MAX_PA_STATES][MAX_TX_LIN_PWR_LIST_SIZE];   //<!' Tx sweep PDM lists
   word tx_lin_pwr_list[MAX_PA_STATES][MAX_TX_LIN_PWR_LIST_SIZE];   //<!' Tx sweep Power lists
} FTM_Load_Tx_Linearizer_Cal_Data_Request;

typedef struct
{
   byte ipaRange[MAX_PA_STATES];                                    //<!' First Tx freqcomp PA Range
   word ichan_list[MAX_CHAN_LIST_SIZE];                         //<!' Tx Cal channel list
   byte tx_freqcomp_pdm_list[MAX_PA_STATES];                                    //<!' Tx freqcomp PDM List
   word tx_freqcomp_pwr_list[MAX_PA_STATES][MAX_CHAN_LIST_SIZE];    //<!'Tx FreqComp Power lists
   byte inum_cal_chan;                                              //<!' Number of FreqComp Cal channels
} FTM_Load_Tx_FreqComp_Cal_Data_Request;

typedef struct
{
   byte cmd;                                            //<!' Command ID (75)
   byte subsys;                                     //<!' Subsystem (11)
   word mode;                                           //<!' Mode ID (20)
   word ftm_cmd;                                        //<!' FTM command id
   word ftm_error_code;                             //<!' Error Code
} FTM_Load_Tx_Cal_Data_Response;

#define RFFE_MAX_DEVICE_INSTANCES 5
#define RFFE_MAX_DEVICE_TRANSACTIONS 256
#define RFFE_MAX_DEVICE_IDS 255

typedef struct
{
   byte cmd;                                               //<' Command ID (75)
   byte subsys;                                        //<' Subsystem (11)
   word mode;                                             //<' Mode ID (20)
   word ftm_cmd;                                           //<' FTM command id
   word status;
   word mfg_id[RFFE_MAX_DEVICE_INSTANCES];
   word prd_id[RFFE_MAX_DEVICE_INSTANCES];
   word rev_id[RFFE_MAX_DEVICE_INSTANCES];
} FTM_GET_RFFE_DEVICE_INFO_Response;

typedef struct
{
   byte rf_mode;
   byte rfm_device;
   byte rffe_device_type;
} FTM_GET_RFFE_DEVICE_INFO_Request;

typedef struct
{
   byte rf_mode;
   byte tx_signal_path;
   byte tx_rfm_device;
   byte rx_signal_path;
   byte rx_rfm_device;
   byte rffe_device_type;
} FTM_GET_RFFE_DEVICE_INFO_Request_V2;

typedef struct
{
   word mfg_id;
   word prd_id;
   word prd_rev;
} FTM_RFFE_Info_Type;

typedef struct
{
   word status;
   word num_device_instances;
   FTM_RFFE_Info_Type device_info_ids[RFFE_MAX_DEVICE_IDS];
} FTM_GET_RFFE_DEVICE_IDS_Response;

/**
Struct to hold RFFE device transaction
address and data
*/
typedef struct
{
   byte address;
   byte data;
} FTM_RFFE_Transaction_type;

typedef struct
{
   word pCellChan;
   word sCellChan;
} FTM_RFFE_CHAN_List_type;

typedef enum
{
   RFFE_DEVICE_PA = 1,
   RFFE_DEVICE_ASM,
   RFFE_DEVICE_PAPM,
   RFFE_DEVICE_TUNER,
   RFFE_DEVICE_INVALID = 0xFFFF
} FTM_RFFE_Device_type;

typedef enum
{
   LINK_TYPE_DOWNLINK = 0,
   LINK_TYPE_UPLINK,
   LINK_TYPE_INVALID = 0xFFFFFFFF
} LINK_TYPE;

/**
struct to hold RFFE transaction per device type
*/
typedef struct
{
   byte bus_id;
   byte slave_id;
   word mfg_id;
   word prd_id;
   word rev_id;
   byte num_transactions;
   FTM_RFFE_Transaction_type device_transactions[RFFE_MAX_DEVICE_TRANSACTIONS];
} FTM_RFFE_Device_Setting_Response_type;

/**
struct to hold RFFE transaction request packet
*/
typedef struct
{
   byte iRfMode;
   byte iRfmDeviceId;
   byte iChainType;
   byte iScenario;
   byte iNumCells;
   byte iLinkType;
   byte iRffeDeviceType;
   FTM_RFFE_CHAN_List_type iChanList;
} FTM_RFFE_Device_Setting_Request_type;

/**
struct to hold FEM_Directory_Info request packet
**/
typedef struct
{
   byte cmdId;
   byte subSysId;
   word modeId;
   word ftmCmdId;
   word reqLen;
   word rspLen;
   byte reqIdx;
} FTM_FEM_Directory_Info_Request_type;

/**
struct to hold FEM Device Settings Path Info
*/
typedef struct
{
   byte numDirPaths;
   byte dirPathSize;
   byte isPathProffNVBased;
   char dirPath[256];
} FTM_FEM_Directory_Path_type;

/**
struct to hold FEM_Directory_Info response packet
**/
typedef struct
{
   byte cmdId;
   byte subSysId;
   word modeId;
   word ftmCmdId;
   word reqLen;
   word rspLen;
   FTM_FEM_Directory_Path_type dirPathInfo;
} FTM_FEM_Directory_Info_Response_type;

/**
struct to hold HW_INDEX request packet
**/
typedef struct
{
   byte cmdId;
   byte subSysId;
   word modeId;
   word ftmCmdId;
} FTM_Get_HW_Index_Request_Type;

/**
struct to hold Status and HW Indices
**/
typedef struct
{
   byte status;
   byte hwIndex1;
   byte hwIndex2;
} FTM_HW_Indices_Info_Type;

/**
struct to hold FTM_TX_FREQ_OVERRIDE response packet
**/
typedef struct
{
   byte cmdId;
   byte subSysId;
   word modeId;
   word ftmCmdId;
   word reqLen;
   word rspLen;
   FTM_HW_Indices_Info_Type hwIndicesInfo;
} FTM_Tx_Freq_Override_Response_Type;

/**
struct to hold FTM_HWTC_COMMON_STG_ENABLE params
*/
typedef struct
{
   byte iInstanceNum;
   dword iStgFreq; //in MHz
} FTM_HTWTC_COMMON_STG_ENABLE_Request_Type;


#define MAX_TX_PATH_GAIN_COMP 8

typedef struct
{
   word dpd_index;
   word first_trigger;
   word last_trigger;
   word num_samples;
   /* EPT_CMD
   01 = EPT_Config
   02 = EPT_IQ Capture
   03 = EPT_Apply_DPD
   04 = FB RX On/Off
   05= IQ gain Update
   */
   signed char ept_cmd;
   dword fb_component;
   dword fb_device;
   dword fb_component_state;
   byte tx_component;//currently declare this as a global variable 3 such that it enables both txcomp0 and txcomp1
   word tx_comp_mask;
   dword tx_path_gain[MAX_TX_PATH_GAIN_COMP];
   word sub_opcode;
} ept_request;

#define MAX_RX_RESULTS_PER_SEG 8
#define MAX_NUM_DEVICES 8
#define MAX_NUM_POWER_MODES 2
#define MAX_NUM_SWP_RECORDS 200
#define MAX_NUM_SWEEPS 2
#define MAX_NUM_MEAS_ACTIONS 32
#define MAX_NUM_TX_OVERRIDES 2
/**
Structure that contains a super set of the command request parameters.

To be used with the function QLIB_FTM_CFG_AND_EXEC_CAL_SWEEP()
*/
// INPUTS
typedef struct
{
   /**
   Inputs, must be filled in before the QLIB_FTM_CFG_AND_EXEC_CAL_SWEEP() function is called.
   Each parameter listed here could be part of every segment of the cal sweep depending on the
   opcode which determines the action to be performed for every segment.

   */
   /**
   Specifies which action will be performed in the segment
   A Bitmask to select the action to be performed.

   Opcode = 0x0000 - It is a NOP segment
   Opcode = 0x0001 - It is a Config Segment to configure RF mode and Channel
   Opcode = 0x0002 - It is a Retune Segment to change Channel
   Opcode = 0x0004 - It is a Waveform Config Segment
   Opcode = 0x0008 - It is a Tx Meas Segment
   Opcode = 0x0010 - It is a HDET Meas Segment
   Opcode = 0x0020 - It is a Cfg Rx Segment
   Opcode = 0x0040 - It is a Meas Rx Segment

   Enabling multiple bits will allow multiple actions to be performed in a segment.

   */
   word opcode;

   /**
   The length of one power step in units of us.
   */
   word segLen;

   /**
   The Master Device Mask
   Bit mask where each bit represents a Master Device
   For Ex. 0x01 would represent master device 0 (Bit 0)
   and 0x02 would represent master device 1 (Bit 1)
   */
   byte masterDev;

   /**
   The Slave Device ID
   Slave ID has 4 bits for each bit of the master device mask
   Master Device Mask : Bits ->   7      6      5      4      3      2      1      0
   Slave Device ID : Bits ->  | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
   For Ex. if master device mask is 0x01 (meaning Device 0 is a master device) and
   if its slave device ID is 1, then SlaveDev would be 0xFFFFFFF1 (an F represents no slave device)
   */
   dword slaveDev;

   /**
   The band that cal has to be performed in.
   */
   byte rfmode;

   /**
   The channel at which the cal is done.
   */
   word ulChan;

   /**
   The Tx bandwidth for LTE
   */
   word txBW;

   /**
   The Rx bandwidth for LTE
   */
   word rxBW;

   /**
   The Tx waveform used. Could be:
   1. CW
   2. CDMA
   3. WCDMA
   4. LTE (maybe)
   */
   byte txWaveform;

   /**
   The purpose of the Tx segment
   1. Linearizer_Voice
   2. Linearizer_Single Carrier ( e.g DO Rev 0/A )
   3. Linearizer_Multi Carrier ( e.g DO Rev B )
   4. FreqComp_lin_vs_Freq
   5. FreqComp_Lim_vs_Freq
   6. FreqComp_ILPC
   7. FreqComp_Secondary
   */
   word txPurpose;

   /**
   The number of RBs for LTE
   */
   byte numRBs;

   /**
   The Start RBs for LTE
   */
   byte startRB;

   /**
   Provides a choice to select Tx measurement options
   Bit 0     = MTD enable
   Bit 1     = IQ Capture Enable
   Bit 2     = ET enable
   Bit 3 - 7 = Reserved
   */
   byte txAction;

   /**
   The PA state to be set
   */
   byte paState;

   /**
   The RGI to be set.
   */
   byte rgi;

   /**
   The PA SMPS bias to be set
   */
   dword paBias;

   /**
   Tx Flag used to indicate the device for which Tx cal is done.
   Bit 0 - 3 = Select the Tx Device
   Bit 4 - 7 = Reserved for more devices
   */
   byte txFlag;

   /**
   Number of HDET averages to take during the measurement. If 0, HDET action/measurement is NOT performed.
   */
   byte numHdetAvg;

   /**
   Number of LPM HDET averages to take during the measurement. If 0, LPM HDET action/measurement is NOT performed.
   */
   byte numLpmHdetAvg;

   /**
   HDET Flag used to indicate the device for which HDET cal is done.
   Bit 0 - 3 = Select the Tx Device
   Bit 4 - 7 = Reserved for more devices
   */
   byte hdetFlag;

   /**
   List specifying the rx action to take. CHECK if we should use the below enum!!!!!!!!!!!!!!!!!!!!!!!!

   Valid values are defined by the enumeration ftm_tx_rx_freq_cal_sweep_rx_action_enum:
   \code
   FTM_TX_RX_FREQ_RX_ACTION_LNA0    = 0,    //!<' - calibrate LNA offset 0
   FTM_TX_RX_FREQ_RX_ACTION_LNA1    = 1,    //!<' - calibrate LNA offset 1
   FTM_TX_RX_FREQ_RX_ACTION_LNA2    = 2,    //!<' - calibrate LNA offset 2
   FTM_TX_RX_FREQ_RX_ACTION_LNA3    = 3,    //!<' - calibrate LNA offset 3
   FTM_TX_RX_FREQ_RX_ACTION_LNA4    = 4,    //!<' - calibrate LNA offset 4
   FTM_TX_RX_FREQ_RX_ACTION_DVGA    = 100,  //!<' - calibrate DVGA offset
   FTM_TX_RX_FREQ_RX_ACTION_NOTHING = 255   //!<' - do nothing
   \endcode
   */
   word rxActions;

   /**
   List specifying the rx power mode to use. CHECK if we should use the below enum!!!!!!!!!!!!!!!!!!!!!!!!
   The values are ignored for chipsets that do not support rx power modes.
   Valid values are:
   \code
   FTM_TX_RX_FREQ_RX_PM_High        = 0,    //!<' - Rx high power mode
   FTM_TX_RX_FREQ_RX_PM_Medium      = 1,    //!<' - Rx medium power mode
   FTM_TX_RX_FREQ_RX_PM_Low     = 2     //!<' - Rx low power mode
   \endcode
   */
   byte rxPM;

   /**
   The expected agc value used as the input to the LNA or DVGA offset calibration routine
   for the primary RX path. If rx_action_list is 255 for a particular step then
   the expected agc value is not used
   */
   word expRxAGC;

   /**
   Rx flag used to select Rx Device.
   Bits 0 - 3 = Select the Rx Device
   Bits 4 - 7 = Reserved
   */
   byte rxFlag;

   /**
   List specifying the rx action to take in MC mode. CHECK if we should use the below enum!!!!!!!!!!!!!!!!!!!!!!!!

   Valid values are defined by the enumeration ftm_tx_rx_freq_cal_sweep_rx_action_enum:
   \code
   FTM_TX_RX_FREQ_RX_ACTION_LNA0    = 0,    //!<' - calibrate LNA offset 0
   FTM_TX_RX_FREQ_RX_ACTION_LNA1    = 1,    //!<' - calibrate LNA offset 1
   FTM_TX_RX_FREQ_RX_ACTION_LNA2    = 2,    //!<' - calibrate LNA offset 2
   FTM_TX_RX_FREQ_RX_ACTION_LNA3    = 3,    //!<' - calibrate LNA offset 3
   FTM_TX_RX_FREQ_RX_ACTION_LNA4    = 4,    //!<' - calibrate LNA offset 4
   FTM_TX_RX_FREQ_RX_ACTION_DVGA    = 100,  //!<' - calibrate DVGA offset
   FTM_TX_RX_FREQ_RX_ACTION_NOTHING = 255   //!<' - do nothing
   \endcode
   */
   //byte mcRxActions;

   /**
   List specifying the rx power mode to use in MC mode. CHECK if we should use the below enum!!!!!!!!!!!!!!!!!!!!!!!!
   The values are ignored for chipsets that do not support rx power modes.
   Valid values are:
   \code
   FTM_TX_RX_FREQ_RX_PM_High        = 0,    //!<' - Rx high power mode
   FTM_TX_RX_FREQ_RX_PM_Medium      = 1,    //!<' - Rx medium power mode
   FTM_TX_RX_FREQ_RX_PM_Low     = 2     //!<' - Rx low power mode
   \endcode
   */
   //byte mcRxPM;

   /**
   The expected agc value used as the input to the LNA or DVGA offset calibration routine
   for the primary RX path in MC mode. If rx_action_list is 255 for a particular step then
   the expected agc value is not used
   */
   //word mcExpRxAGC;

   /**
   Rx flag used to select Rx Device in MC mode.
   Bits 0 - 3 = Select the Rx Device
   Bits 4 - 7 = Reserved
   */
   //byte mcRxFlag;

   /**
   Channel offset to be used from the center channel in MC mode for the 2nd carrier
   */
   word chanOffset;

   ept_request ept_req;
} FTM_Cal_Sweep_Request;

// Different struct types for different opcode bit combinations
// Different struct types for different opcode bit combinations

typedef struct
{
   /*! @brief AMAM Coef */
   signed long am[4];
   /*! @brief AMPM Coef */
   signed long pm[3];
   /*! @brief Phase Shift */
   signed char pm_shift[3];
   /*! @brief DPD Status */
   unsigned char status;
} QMSL_Tx_Dpd_Poly_Coef_Type;

typedef enum
{
   FTM_Tx_PowerOptAction_FullBias = 0,
   FTM_Tx_PowerOptAction_APT_DOUBLE_SWEEP = 1,
   FTM_Tx_PowerOptAction_EPT = 2,
   FTM_Tx_PowerOptAction_APT_SINGLE_SWEEP = 3,
   FTM_Tx_PowerOptAction_DualAptTableWithSingleAptSweep = 4, // use 1st calibration table for 2nd APT calibration table, but replace the 1st APT voltages with the 2nd APT voltages.
   FTM_Tx_PowerOptAction_EPT_Enh = 5,
   FTM_Tx_PowerOptAction_EPT_Enh_HDET = 6,
   FTM_Tx_PowerOptAction_LastValid = 6,
   FTM_Tx_PowerOptAction_MAX = (FTM_Tx_PowerOptAction_LastValid+1)
} FTM_Cal_Sweep_Tx_PowerOptAction_Type;

typedef enum
{
   FTM_Tx_Purpose_Linearizer_Voice =            1,
   FTM_Tx_Purpose_Linearizer_Single_Carrier =   2,
   FTM_Tx_Purpose_Linearizer_Multi_Carrier  =   3,
   FTM_Tx_Purpose_FreqComp_Lin_vs_Freq =        4,
   FTM_Tx_Purpose_FreqComp_Lim_vs_Freq =        5,
   FTM_Tx_Purpose_FreqComp_ILPC     =       6,
   FTM_Tx_Purpose_FreqComp_Secondary    =       7,
   FTM_Tx_Purpose_Linearizer_EPT                   =        8,
   FTM_Tx_Purpose_Available_Max         =        8, // added for input error check
   FTM_Tx_Purpose_Max                   =       0xFFFF
} FTM_Cal_Sweep_Tx_Purpose_Type;

// Multi_Lin NV V3 TX purpose types
// TODO: make cal_sweep_records have these values --> currently using the above enum
typedef enum
{
   FTM_Tx_Purp_Lin_Voice_MLV3             = 0,
   FTM_Tx_Purp_Lin_Data_Type_1_MLV3       = 1,
   FTM_Tx_Purp_Lin_Data_Type_2_MLV3       = 2,
   FTM_Tx_Purp_Lin_First_Sweep_MLV3       = 3,
   FTM_Tx_Purp_Lin_First_Sweep_40M_MLV3   = 4,
   FTM_Tx_Purp_Lin_Data_Type_1_40M_MLV3   = 5,
   FTM_Tx_Purp_Lin_Num_Waveform_MLV3      = 6,
   FTM_Tx_Purp_FreqComp_Lin_vs_Freq_MLV3  = 104,
   FTM_Tx_Purp_FreqComp_Lim_vs_Freq_MLV3  = 105,
   FTM_Tx_Purpose_Lin_First_Sweep_40M_MLV3= 204,
   FTM_Tx_Purpose_Lin_Data_Type_1_40M_MLV3= 205,
   FTM_Tx_Purp_FreqComp_ILPC_MLV3         = 206,
   FTM_Tx_Purp_FreqComp_Sec_MLV3          = 207,
   FTM_Tx_Purp_Lin_EPT_MLV3               = 208
} FTM_Cal_Multi_lin_V3_Tx_Purpose_Type;

typedef struct
{
   word opcode;
   word segLen;
} FTM_Cal_Sweep_Opcode_Req;

typedef struct
{
   //NEW_EPT
   //word sub_opcode;
   dword sub_opcode;
} FTM_Cal_Sweep_Sub_Opcode_Req;

typedef struct
{
   //NEW_EPT
   //word sub_opcode;
   byte debug_mode;
} FTM_Cal_Sweep_XPT_Debug_Mode_Req;

typedef struct
{
   byte masterDev;
   dword slaveDev;
   byte rfmode;
   word ulChan;
   word txBW;
   word rxBW;
   word chanOffset;
} FTM_Cal_Sweep_Cfg_Req;

typedef struct
{
   byte masterDev;
   word ulChan;
   word chanOffset;
} FTM_Cal_Sweep_Retune_Req;

typedef struct
{
   byte txWaveform;
   byte numRBs;
   byte startRB;
} FTM_Cal_Sweep_Tx_Wfm_Cfg_Req;

typedef struct
{
   byte txAction;
   byte paState;
   byte rgi;
   dword paBias;
   byte txFlag;
} FTM_Cal_Sweep_TxMeas_Req;

typedef struct
{
   byte numHdetAvg;
   byte numLpmHdetAvg;
   byte hdetFlag;
} FTM_Cal_Sweep_HDET_Meas_Req;

typedef struct
{
   word rxActions;
   byte rxPM;
   byte rxFlag;
} FTM_Cal_Sweep_RxCfg_Req;

typedef struct
{
   word rxActions;
   byte rxPM;
   word expRxAGC;
   byte rxFlag;
} FTM_Cal_Sweep_RxMeas_Req;

typedef struct
{
   byte version;
   word flag;
   byte prim_device;
   byte fb_device;
} FTM_Cal_Sweep_EPT_Config_Req;

typedef struct
{
   byte version;
   word flag;
   byte prim_device;
   byte fb_device;
   word num_samples;
   byte first_trigger;
   byte last_trigger;
   word dpd_index;
} FTM_Cal_Sweep_EPT_IQ_Cap_Req;

typedef struct
{
   byte version;
   word flag;
   byte prim_device;
   byte fb_device;
   word dpd_index;
} FTM_Cal_Sweep_EPT_Apply_DPD_Req;

typedef struct
{
   byte version;
   word flag;
   byte prim_device;
   byte fb_device;
   word fb_component;
   word fb_component_state;
} FTM_Cal_Sweep_XPT_FB_Config;

#define EPT_MAX_NUM_TX_PATH_GAIN_COMP 8

typedef struct
{
   byte version;
   word flag;
   byte prim_device;
   byte tx_component;
   dword TxCompGain[EPT_MAX_NUM_TX_PATH_GAIN_COMP];
} FTM_Cal_Sweep_XPT_Tx_Path_Gain;
/*
typedef struct
{
byte txAction;
byte paState;
byte rgi;
dword paBias;
byte txFlag;
byte numHdetAvg;
byte numLpmHdetAvg;
byte hdetFlag;
word rxActions;
byte rxPM;
byte rxFlag;
} FTM_Cal_Sweep_Tx_HDET_Rx_Cfg_Req;

typedef struct
{
word opcode;
word segLen;
byte txAction;
byte paState;
byte rgi;
dword paBias;
byte txFlag;
byte numHdetAvg;
byte numLpmHdetAvg;
byte hdetFlag;
word rxActions;
byte rxPM;
word expRxAGC;
byte rxFlag;
} FTM_Cal_Sweep_Tx_HDET_Rx_Meas_Req;

typedef struct
{
word opcode;
word segLen;
byte txAction;
byte paState;
byte rgi;
dword paBias;
byte txFlag;
byte numHdetAvg;
byte numLpmHdetAvg;
byte hdetFlag;
word mcRxActions;
byte mcRxPM;
byte mcRxFlag;
word chanOffset;
} FTM_Cal_Sweep_Tx_HDET_MCRx_Cfg_Req;

typedef struct
{
word opcode;
word segLen;
byte txAction;
byte paState;
byte rgi;
dword paBias;
byte txFlag;
byte numHdetAvg;
byte numLpmHdetAvg;
byte hdetFlag;
word mcRxActions;
byte mcRxPM;
word mcExpRxAGC;
byte mcRxFlag;
word chanOffset;
} FTM_Cal_Sweep_Tx_HDET_MCRx_Meas_Req;

typedef struct
{
word opcode;
word segLen;
byte txAction;
byte paState;
byte rgi;
dword paBias;
byte txFlag;
word rxActions;
byte rxPM;
byte rxFlag;
} FTM_Cal_Sweep_Tx_Rx_Cfg_Req;

typedef struct
{
word opcode;
word segLen;
byte txAction;
byte paState;
byte rgi;
dword paBias;
byte txFlag;
word rxActions;
byte rxPM;
word expRxAGC;
byte rxFlag;
} FTM_Cal_Sweep_Tx_Rx_Meas_Req;

typedef struct
{
word opcode;
word segLen;
byte txAction;
byte paState;
byte rgi;
dword paBias;
byte txFlag;
word mcRxActions;
byte mcRxPM;
byte mcRxFlag;
word chanOffset;
} FTM_Cal_Sweep_Tx_MCRx_Cfg_Req;

typedef struct
{
word opcode;
word segLen;
byte txAction;
byte paState;
byte rgi;
dword paBias;
byte txFlag;
word mcRxActions;
byte mcRxPM;
word mcExpRxAGC;
byte mcRxFlag;
word chanOffset;
} FTM_Cal_Sweep_Tx_MCRx_Meas_Req;
*/

// OUTPUTS
typedef struct
{
   /**
   Output, will be filled in by QLIB_FTM_GET_CAL_SWEEP_RESULTS()

   */
   /**
   The result of the requested rx calibration on each receive path for
   a given step and frequency. Array of Rx results which can hold results
   for upto 8 devices that can be simulaneiously calibrated with the new cal sweep.
   */
   word aiRxResults[MAX_NUM_DEVICES][MAX_RX_RESULTS_PER_SEG];

   /**
   The result of the requested rx calibration on each receive path for
   a given step and frequency. Array of Rx results which can hold results
   for upto 8 devices that can be simulaneiously calibrated with the new cal sweep.
   */
   word aiRxResultsLPM[MAX_NUM_DEVICES][MAX_RX_RESULTS_PER_SEG];

   /**
   The result of the requested MC rx calibration on the receive path for
   a given step and frequency. Array of Rx results which can hold results
   for upto 8 devices that can be simulaneiously calibrated with the new cal sweep.
   */
   word aiMCRxResults[MAX_NUM_DEVICES][MAX_RX_RESULTS_PER_SEG];

   /**
   The HDET value for each segment measured by the phone. There will be a HDET result
   returned whenever HDET opcode bit is enabled and Number of HDET averages for that
   segment is greater than 0.
   */
   word aiHDETResults;

   /**
   The LPM HDET value for each segment measured by the phone. There will be a LPM HDET result
   returned whenever HDET opcode bit is enabled and Number of LPM HDET averages for that
   segment is greater than 0.
   */
   word aiLPMHDETResults;

   /** The Tx power measured from the box . Make sure the TxPower is dB10 for Linearizer and dB100 for FreqComp*/
   word aiTxPower;

   /* EPT Cal Information */
   QMSL_Tx_Dpd_Poly_Coef_Type aiEpt;
} FTM_Cal_Sweep_Response;

typedef enum
{
   /*!< Success Code indicating that the Calibration request packet sent
   from PC is stored in Linked List in embedded side */
   FTM_CAL_SWEEP_ERR_CODE_PACKET_ALLOCATED = 2,

   /*!< Success code indicating that ISE has been scheduled for calibration */
   FTM_CAL_SWEEP_ERR_CODE_ISR_SCHEDULED = 1,

   /*!< Success */
   FTM_CAL_SWEEP_ERR_CODE_SUCCESS = 0,

   /*!< Failure */
   FTM_CAL_SWEEP_ERR_CODE_FAILURE = -1,

   /*!< Error Code indicating invalid callback being registered for the
   active technology */
   FTM_CAL_SWEEP_ERR_CODE_INVALID_CALLBACK = -2,

   /*!< Error Code indicating bad CRC being detected at the end of the request
   packet */
   FTM_CAL_SWEEP_ERR_CODE_INVALID_CRC = -3,

   /*!< Error Code indicating that the Configuration packet buffer allocation
   is empty */
   FTM_CALIBRATION_CONFIG_ALLOC_FAILURE = -4
} FTM_CAL_SWEEP_ERR_CODE_TYPE;

typedef enum
{
   /*!< Success Code indicating that the Read to Result buffer is successful
   and the result data sent back to PC is valid */
   FTM_CALIBRATION_RESULTS_READ_SUCCESS = 0,

   /*!< Error Code indicating that memory for results could not be allocated */
   FTM_CALIBRATION_RESULTS_ALLOC_FAILURE = -1,

   /*!< Error Code indicating that the Read is disabled for the Result buffer
   as write is happening currently */
   FTM_CALIBRATION_RESULTS_READ_DISABLED = -2,

   /*!< Error Code indicating that the Result buffer is empty */
   FTM_CALIBRATION_RESULTS_EMPTY_BUFFER = -3
} FTM_CAL_SWEEP_RESULTS_ERR_CODE_TYPE;

/*----------------------------------------------------------------------------*/
/*!
@brief
Error mask enumeration indicating errors in each segment
*/
typedef enum
{
   FTM_CAL_SEG_ERR_SEG_DURATION_OVERRUN    = 0,
   /*!< Error code to indicate that there as segment duration overrun. Thus
   the Rx or Tx measurement is not aligned with the external measurement tool.*/

   FTM_CAL_SEG_ERR_INVALID_RFM_MODE        = 1,
   /*!< Error code to indicate that the resolved RFM Mode for the calibration
   sweep is invalid. */

   FTM_CAL_SEG_ERR_CFG_RADIO_FAILURE       = 2,
   /*!< Error code to indicate that tech specific Configure Radio action failed.
   This indicates that radio could not be tuned to RxTx state on requested
   device, band and channel.*/

   FTM_CAL_SEG_ERR_CFG_RADIO_NULL_CB       = 3,
   /*!< Error code to indicate that the tech specific configure radio callback
   function is NULL. This error code will be seen when the Configure radio
   opcode bit is enabled while the CB function is NULL. */

   FTM_CAL_SEG_ERR_CFG_TX_WF_FAILURE       = 4,
   /*!< Error code to indicate that tech specific Configure tx waveform action
   failed. This indicates that Tx waveform could not be set to requested type.*/

   FTM_CAL_SEG_ERR_CFG_TX_WF_NULL_CB       = 5,
   /*!< Error code to indicate that the tech specific configure Tx waveform
   callback function is NULL. This error code will be seen when the Configure
   Tx wavefoem opcode bit is enabled while the CB function is NULL. */

   FTM_CAL_SEG_ERR_RETUNE_RADIO_FAILURE    = 6,
   /*!< Error code to indicate that tech specific retune Radio action failed.
   This indicates that radio could not be retuned to RxTx state on requested
   device, band and channel.*/

   FTM_CAL_SEG_ERR_RETUNE_RADIO_NULL_CB    = 7,
   /*!< Error code to indicate that the tech specific retune radio callback
   function is NULL. This error code will be seen when the retune radio
   opcode bit is enabled while the CB function is NULL. */

   FTM_CAL_SEG_ERR_CFG_TX_FAILURE          = 8,
   /*!< Error code to indicate that tech specific Configure Tx action failed.
   This indicates that Tx radio could not be overridden to given PA State, RGI,
   and PA Bias*/

   FTM_CAL_SEG_ERR_CFG_TX_NULL_CB          = 9,
   /*!< Error code to indicate that the tech specific configure Tx callback
   function is NULL. This error code will be seen when the Configure Tx
   opcode bit is enabled while the CB function is NULL. */

   FTM_CAL_SEG_ERR_MEAS_HDET_FAILURE       = 10,
   /*!< Error code to indicate that tech specific HDET measurement action
   failed. */

   FTM_CAL_SEG_ERR_MEAS_HDET_NULL_CB       = 11,
   /*!< Error code to indicate that the tech specific measure HDET callback
   function is NULL. This error code will be seen when the measure HDET
   opcode bit is enabled while the CB function is NULL. */

   FTM_CAL_SEG_ERR_CFG_RX_FAILURE          = 12,
   /*!< Error code to indicate that tech specific configure Rx action
   failed. This indicates that Rx radio could not be overriden to given
   LNA state and LNA gain. */

   FTM_CAL_SEG_ERR_CFG_RX_NULL_CB          = 13,
   /*!< Error code to indicate that the tech specific configure Rx callback
   function is NULL. This error code will be seen when the Configure Rx
   opcode bit is enabled while the CB function is NULL. */

   FTM_CAL_SEG_ERR_MEAS_RX_FAILURE         = 14,
   /*!< Error code to indicate that tech specific Rx measurement action
   failed. */

   FTM_CAL_SEG_ERR_MEAS_RX_NULL_CB         = 15,
   /*!< Error code to indicate that the tech specific measure Rx callback
   function is NULL. This error code will be seen when the measure Rx
   opcode bit is enabled while the CB function is NULL. */

   FTM_CAL_SEG_ERR_TEAR_RADIO_FAILURE      = 16,
   /*!< Error code to indicate Radio tear down failure occured. This indicates
   the Radio will not be in sleep state at the end of calibration sweep. */

   FTM_CAL_SEG_ERR_TEAR_RADIO_NULL_CB      = 17,
   /*!< Error code to indicate that the tech specific radio callback
   function is NULL. Radio should always be torn down at the end of the sweep.
   This this error code will be invoked, if there is not callback funciton
   register for a tech. */

   FTM_CAL_SEG_ERR_TX_MEAS_NUM_MISMATCH    = 18,
   /*!< Error code to indicate that there is a mismatch between the expected
   number of Tx measurement by cal v3 common framework and the number of Tx
   measurement sent by tech specific Tx measurement function. */

   FTM_CAL_SEG_ERR_RX_MEAS_NUM_MISMATCH    = 19,
   /*!< Error code to indicate that there is a mismatch between the expected
   number of Rx measurement by cal v3 common framework and the number of Rx
   measurement sent by tech specific Rx measurement function. */

   FTM_CAL_SEG_ERR_TX_MEAS_DATA_OVERFLOW    = 20,
   /*!< Error code to indicate that there is a mismatch Tx measurement data
   returned by tech specific callback funciton is bigger than the max
   value #FTM_CALIBRATION_SEG_TX_BUFF_SIZE_MAX. */

   FTM_CAL_SEG_ERR_RX_MEAS_DATA_OVERFLOW    = 21,
   /*!< Error code to indicate that there is a mismatch Rx measurement data
   returned by tech specific callback funciton is bigger than the max
   value #FTM_CALIBRATION_SEG_RX_BUFF_SIZE_MAX. */

   FTM_CAL_SEG_ERR_PUSH_RESULT_FAILURE      = 22,
   /*!< Error code to indicate that RxTx results could not be pushed into
   the results possibly because of buffer overflow. */

   FTM_CAL_SEG_ERR_TIMER_UPDATE             = 23,
   /*!< Error code indicating the Timer installation or update has failed. */

   FTM_CAL_SEG_ERR_XPT_FAILURE              = 24,
   /*!< Error code indicating the XPT operation has failed. More details on
   the type of error can be found out by looking at the Error Code in XPT
   results buffer */

   FTM_CAL_SEG_ERR_POLLING_FAILURE          = 25,
   /*!< Error code indicating the POLLING operation has failed. */

   FTM_CAL_SEG_ERR_RADIO_SETUP_FAILURE      = 26,
   /*!< Error code indicating the Radio Setup operation has failed. */

   FTM_CAL_SEG_ERR_TX_OVERRIDE_FAILURE      = 27,
   /*!< Error code indicating the Tx override operation has failed. */

   FTM_CAL_SEG_ERR_RX_MEASURE_FAILURE       = 28,
   /*!< Error code indicating the Rx measure operation has failed. */

   FTM_CAL_SEG_ERR_TX_MEASURE_FAILURE       = 29,
   /*!< Error code indicating the Tx measure operation has failed. */

   FTM_CAL_SEG_ERR_DATA_FAILURE             = 30,
   /*!< Error code indicating the Data operation has failed. */

   FTM_CAL_COMPRESSION_STATUS_BUFFER_FAILURE = 31,
   /*!< Error code indicating that there was not enough room in output buffer if input buffer is too small to be compressed. */

   FTM_CAL_COMPRESSION_STATUS_DATA_FAILURE = 32,
   /*!< Error code indicating the input data to compress or uncompression is incomplete or corrupted*/

   FTM_CAL_SEG_ERR_MAX_NUM
   /*!< Maximum number of segment error code. This enum should not be
   used for any purpose other than counting the number of error codes. */
} ftm_calibration_segment_error_code_mask;

typedef struct
{
   // UL channel of measurement
   unsigned short chan;

   // PA State of measurement
   char pa;

   // RGI for measurement
   unsigned short rgi;

   // Power measured
   signed short power;

   // Bias used for measurement
   unsigned long bias;
} ftm_ref_cal_meas;

typedef struct
{
   unsigned short freq_comp_ref_chan;
   unsigned short freq_comp_ch_list[TXLIN_NUM_CHANNELS];
   unsigned short freq_comp_rgi_list[TXLIN_NUM_LINEARIZERS][TXLIN_NUM_FREQCOMP_RGI_BIN];
   unsigned short freq_comp_bias_list[TXLIN_NUM_LINEARIZERS][TXLIN_NUM_FREQCOMP_RGI_BIN];
   unsigned short rgi_threshold_list[TXLIN_NUM_LINEARIZERS][TXLIN_NUM_FREQCOMP_RGI_BIN];
   unsigned short upper_bound_chan_list[TXLIN_NUM_LINEARIZERS][TX_LINEARIZER_NUM_WAVEFORM][TXLIN_NUM_CHANNELS];
   unsigned short pa_list[TXLIN_NUM_LINEARIZERS][TX_LINEARIZER_NUM_WAVEFORM][TXLIN_NUM_CHANNELS];
   unsigned short pa_max_bias;
} QMSL_Ref_Cal_NV_Gen_Info;

/******************************************************************************
FTM - MediaFLO
*******************************************************************************/
/**
\brief Enumeration of MediaFLO Command IDs
*/
typedef enum
{
   _FTM_MF_GET_RSSI_CAL_POINT               = 400,  //!< MediaFLO - get Rssi Cal Point
   _FTM_MF_GET_RX_RSSI                      = 401,  //!< MediaFLO - get Rssi value
   _FTM_MF_GET_AGC_STATE                    = 402,  //!< MediaFLO - get AGC state
   _FTM_MF_WRITE_CAL_DATA                   = 403,  //!< MediaFLO - write cal data to NV
   _FTM_MF_LNA_SELECT                       = 406,  //!< MediaFLO - select LNA
   _FTM_MF_RF_SWITCH_CONFIG             = 407,  //!< MediaFLO - switch control pins
   _FTM_MF_SYNTH_LOCK                       = 408,  //!< MediaFLO - synthesizer lock state
   _FTM_MF_SET_GAIN_STATE                   = 411,  //!< MediaFLO - set gain state
   _FTM_MF_TUNE_PLL                     = 413,  //!< MediaFLO - tune PLL
   _FTM_MF_GET_IM2                          = 415,  //!< MediaFLO - perform IM2 cal
} FTM_MF_Cmd_Id_Enum;

typedef enum
{
   _FTM_UBM_MF_GET_RSSI_CAL_POINT           = 0,    //!< MediaFLO - get Rssi Cal Point
   _FTM_UBM_MF_GET_RSSI                     = 1,    //!< MediaFLO - get Rssi value
   _FTM_UBM_MF_GET_AGC_STATE                = 2,    //!< MediaFLO - get AGC state
   _FTM_UBM_MF_WRITE_CAL_DATA_TO_NV         = 3,    //!< MediaFLO - write cal data to NV
   _FTM_UBM_MF_SET_RF_ON                    = 4,    //!< MediaFLO - Turn on RF_ON
   _FTM_UBM_MF_RF_POWER_UP_RF               = 5,    //!< MediaFLO - Power Up RF
   _FTM_UBM_MF_LNA_SELECT                   = 6,    //!< MediaFLO - LNA Selection (MBP16x0)
   _FTM_UBM_MF_RF_SET_ANT_TUNE              = 7,    //!< MediaFLO - Set Antenna Tune (MBP16x0)
   _FTM_UBM_MF_SYNTH_LOCK                   = 8,    //!< MediaFLO - synthesizer lock state
   _FTM_UBM_MF_SET_LNA                      = 9,    //!< MediaFLO - Enable Disable LNA
   _FTM_UBM_MF_TUNE_RF_IN_HZ                = 10,   //!< MediaFLO - Tune RF in Hz
   _FTM_UBM_MF_SET_GAIN_STATE               = 11,   //!< MediaFLO - set gain state
   _FTM_UBM_MF_TOGGLE_TCXO_ON               = 12,   //!< MediaFLO - Toggle TCXO On
   _FTM_UBM_MF_TUNE_PLL                     = 13,   //!< MediaFLO - tune PLL
   _FTM_UBM_MF_LOAD_RSSI_CAL_POINT          = 14,   //!< MediaFLO - Load RSSI Cal Point
   _FTM_UBM_MF_SET_AGC_DEFAULT              = 16,   //!< MediaFLO - Set AGC default
   _FTM_UBM_MF_RF_INITIALIZE                = 17,   //!< MediaFLO - RF initialise
   _FTM_UBM_MF_LOAD_AGC_CAL_CHAN_LIST       = 18,   //!< MediaFLO - Load AGC Calibration Channel List
   _FTM_UBM_MF_POWER_DOWN_RF                = 19,   //!< MediaFLO - Power Down
   _FTM_UBM_MF_SET_DEMOD_CONFIG             = 20,   //!< MediaFLO - set demodulation configuration
   _FTM_UBM_MF_LNA_SELECT_2                 = 21,   //!< MediaFLO - LNA Selection (MBP2700)
   _FTM_UBM_MF_RF_SET_ANT_TUNE_2            = 22    //!< MediaFLO - Set Antenna Tune (MBP2700)
} FTM_UBM_MF_Cmd_Id_Enum;

typedef enum
{
   _FTM_MFLO_NS_SET_NS_MODE                         = 0,   //!< MediaFLO NS - enable FLO demod
   _FTM_MFLO_NS_ACQUIRE_FLO_SYSTEM                  = 1,   //!< MediaFLO NS - acquire FLO system
   _FTM_MFLO_NS_ACTIVATE_FLOW                       = 2,   //!< MediaFLO NS - activate FLO
   _FTM_MFLO_NS_DEACTIVATE_FLOW                     = 3,   //!< MediaFLO NS - deactivate FLO
   _FTM_MFLO_NS_GET_STREAM_INFO                     = 4,   //!< MediaFLO NS - get stream info
   _FTM_MFLO_NS_GET_MLC_DYN_PARAMS                  = 5,   //!< MediaFLO NS - get MLC dynamic params
   _FTM_MFLO_NS_GET_OIS_STATS                       = 6,   //!< MediaFLO NS - get OIS demodulation statistics
   _FTM_MFLO_NS_RESET_MLC_PLP_STATS                 = 7,   //!< MediaFLO NS - reset MLC PLP stats
   _FTM_MFLO_NS_RESET_ALL_PLP_STATS                 = 8,   //!< MediaFLO NS - reset all PLP stats
   _FTM_MFLO_NS_GET_ALL_ACTIVE_FLOW_IDS             = 9,   //!< MediaFLO NS - get all active flow ids
   _FTM_MFLO_NS_GET_CONTROL_CHANNEL_RECORDS         = 10,  //!< MediaFLO NS - get control channel records
   _FTM_MFLO_NS_GET_AIS_CHANNEL                     = 11,  //!< MediaFLO NS - get AIS channel
   _FTM_MFLO_NS_DEACTIVATE_ALL_FLOWS                = 12,  //!< MediaFLO NS - deactivate all flows
   _FTM_MFLO_NS_TUNE_FREQ_AND_BW                    = 13,  //!< MediaFLO NS - tune freq and bw
   _FTM_MFLO_NS_GET_RSSI                            = 14,  //!< MediaFLO NS - get RSSI
   _FTM_MFLO_NS_SET_FLO_SLEEP                       = 15,  //!< MediaFLO NS - set FLO sleep
   _FTM_MFLO_NS_GET_OIS_STATE                       = 16,  //!< MediaFLO NS - get OIS State
   _FTM_MFLO_NS_INITIALIZE_RF                       = 17,  //!< MediaFLO NS - initialize NS mode
   _FTM_MFLO_NS_SET_CONFIG_OPTIONS                  = 18,  //!< MediaFLO NS - set demodulation configuration
   _FTM_MFLO_NS_RESET_OIS_STATS                     = 19,  //!< MediaFLO NS - reset the OIS statistics
   _FTM_MFLO_NS_GET_MLC_DYN_PARAMS_LOG              = 20,  //!< MediaFLO NS - get the MLC dynamic parameters
   _FTM_MFLO_NS_GET_FLOW_PLP_DYN_PARAMS             = 21,  //!< MediaFLO NS - get the PLP statistics based on a Flow ID
   _FTM_MFLO_NS_ENABLE_FTAP_PLP_DATA                = 22,  //!< MediaFLO NS - start/stop FTAP data packet records logging
   _FTM_MFLO_NS_ENABLE_FTAP_OIS_RECEPTION_MODE      = 23,  //!< MediaFLO NS - start/stop FTAP OIS reception test mode
   _FTM_MFLO_NS_ENABLE_FTAP_WICLIC_RECEPTION_MODE   = 24,  //!< MediaFLO NS - start/stop FTAP WICLIC reception test mode
   _FTM_MFLO_NS_SET_JAMMER_DETECT_MODE              = 25,  //!< MediaFLO NS - set Jammer Detection Mode
   _FTM_MFLO_NS_FREEZE_GAIN_STATE                   = 26,  //!< MediaFLO NS - freeze the AGC gain state
   _FTM_MFLO_NS_ENABLE_AFC_OUTER_LOOP               = 27,  //!< MediaFLO NS - enable the AFC outer loop
   _FTM_MFLO_NS_DISABLE_AGC_GAIN_TRACKING           = 28,  //!< MediaFLO NS - disable AGC Gain Tracking
   _FTM_MFLO_NS_GET_JAMMER_DETECT_STATE             = 29,  //!< MediaFLO NS - get the Jammer Detection State
   _FTM_MFLO_NS_GET_RSSI_AND_GAIN_STATE             = 30   //!< MediaFLO NS - get RSSI and Gain State
} FTM_MF_NS_Cmd_Id_Enum;

typedef enum
{
   FTM_MFLO_US      = 0,
   FTM_MFLO_VHF = 1,
   FTM_MFLO_UHF = 2,
   FTM_MFLO_L_BAND = 3
} ftm_mflo_rf_mode;

typedef enum
{
   FTM_MFLO_5_MHZ_BW    = 5,
   FTM_MFLO_6_MHZ_BW    = 6,
   FTM_MFLO_7_MHZ_BW    = 7,
   FTM_MFLO_8_MHZ_BW    = 8
} ftm_mflo_bandwidth;

typedef enum
{
   FTM_MFLO_2K_FFT = 0,
   FTM_MFLO_4K_FFT = 1,
   FTM_MFLO_8K_FFT = 2
} ftm_mflo_fft_size;

typedef enum
{
   FTM_MFLO_1_16_CP_LENGTH = 0,
   FTM_MFLO_1_8_CP_LENGTH = 1,
   FTM_MFLO_3_16_CP_LENGTH = 2,
   FTM_MFLO_1_4_CP_LENGTH = 3
} ftm_mflo_cp_length;

// IC Mode definition for MBP1600/MBP1610
typedef enum
{
   FTM_MFLO_IC_DISABLED = 0,
   FTM_MFLO_IC_BYPASSED = 1,
   FTM_MFLO_IC_ENABLED = 2,
   FTM_MFLO_IC_DYNAMIC = 3
} ftm_mflo_ic_mode;

// IC Mode definition for MBP2600/MBP2700
typedef enum
{
   FTM_MFLO_IC_2_DISABLED = 0,
   FTM_MFLO_IC_2_ENABLED = 1,
   FTM_MFLO_IC_2_DYNAMIC = 3
} ftm_mflo_ic_mode_2;

typedef enum
{
   FTM_MFLO_DMTT_DISABLED = 0,
   FTM_MFLO_DMTT_LEGACY = 1,
   FTM_MFLO_DMTT_W_TDM2_RDSP_NOT_USED = 2,
   FTM_MFLO_DMTT_W_TDM2_RDSP_USED = 3,
   FTM_MFLO_DMTT_TPC_BASED = 4
} ftm_mflo_dmtt_mode;

typedef enum
{
   FTM_MFLO_NS_OUTER_CODE_NONE = 0,
   FTM_MFLO_NS_OUTER_CODE_RS_7_8 = 1,
   FTM_MFLO_NS_OUTER_CODE_RS_3_4 = 2,
   FTM_MFLO_NS_OUTER_CODE_RS_1_2 = 3,
   FTM_MFLO_NS_OUTER_CODE_REP_4 = 4
} ftm_mflo_mlc_outer_code;

typedef enum
{
   FTM_MFLO_NS_ENABLE_WOIS_ONLY = 0x0,
   FTM_MFLO_NS_ENABLE_LOIS_ONLY = 0x1,
   FTM_MFLO_NS_ENABLE_WOIS_AND_LOIS = 0x2,
   FTM_MFLO_NS_DISABLE_WOIS_AND_LOIS = 0x3
} ftm_mflo_ois_test_mode_type;

typedef struct
{
   dword  num_good_pre_rs;
   dword  num_erasure_pre_rs;
   dword  num_good_post_rs;
   dword  num_erasure_post_rs;
} ftm_mflo_stats_type;

//! Structure to define storage area for a mediaFLO NS FTM request/response messages
typedef struct
{
   dword flow_id;
   byte   binding;
   byte  mlc_id;
   byte  strm_id;
   byte  strm_uses_both_layers;
   byte  byte_interleave_enabled;
   byte  system;
   dword base_fft_addr;
   byte  trans_mode;
   byte  outer_code;
   byte  num_cbs_in_curr_sf;
   union
   {
      ftm_mflo_stats_type plp_stats[2];  /* 8 uint32s */
      dword gen_1_w[8];
   } ftm_mflo_var_data_1;
   union
   {
      ftm_mflo_stats_type cb_stats[2];   /* 8 uint32s */
      dword gen_2_w[8];
   } ftm_mflo_var_data_2;
   byte  strm1_bound;
   byte  strm2_bound;
   word strm_lens[2];
} ftm_mflo_type;

//! Structure to parse WIC and LIC packets
typedef struct
{
   int reserved;
   char WID;
   char LID;
} wid_lid_packet;

typedef enum
{
   MFLO_T_UHF1      = 0,    /* MBP2600 */
   MFLO_F_LBAND = 1,    /* MBP2700 LBAND */
   MFLO_F_LNA1      = 2,    /* MBP2700 LNA1 */
   MFLO_F_LNA2      = 3,    /* MBP2700 LNA2 */
} ftm_mflo_rf_lna_type;

/******************************************************************************
FTM - LTE
*******************************************************************************/

//! LTE FTM Packet version
#define LTE_FTM_PACKET_VERSION 0

/**
LTE Non-signaling FTM commands
*/
typedef enum
{
   _FTM_LTE_NS_START            = 500,      //!< ' This command puts the system in LTE mode.
   _FTM_LTE_NS_ACQ              = 501,      //!< ' This command starts acquisition process.
   _FTM_LTE_NS_START_DP     = 502,      //!< ' This command configures the data channel such that data can be recevied.
   _FTM_LTE_NS_IDLE         = 503,  //!< ' This command can be used to directly go from LTE CONNECTED state to an ENTERED_MODE state.
   _FTM_LTE_NS_STOP         = 504,      //!< ' This command halts all outstanding operation and exits the LTE mode.
   _FTM_LTE_NS_IS_CONNECTED = 505,      //!< ' This command checks if LTE NS Call is up.
   _FTM_LTE_NS_CONFIG_UL_WAVEFORM           = 506,  //'<' This command reconfigure the UL waveform.
   _FTM_LTE_NS_CONFIG_UL_POWER              = 507,  //'<' This command override the Tx power
   _FTM_LTE_NS_GET_DL_LEVEL                 = 508,  //'<' This command gets the Rx power
   _FTM_LTE_NS_RESET_DL_BLER_REPORT         = 509,  //'<' This command reset the DL BLER report
   _FTM_LTE_NS_GET_DL_BLER_REPORT           = 510,  //'<' This command gets the DL BLER report
   _FTM_LTE_NS_HANDOVER                     = 511,  //'<' This command performs the handover
   _FTM_LTE_NS_TDD_CONFIG                   = 516,  //'<' This command performs the handover
   _FTM_LTE_NS_ENABLE_SCELL                 = 519,  //'<' This commands configures and activates SCELL
   _FTM_LTE_NS_DISABLE_SCELL                = 520,  //'<' This commands disables SCELL and puts UE in PCELL mode
   _FTM_LTE_NS_GET_ALL_CARR_DL_BLER         = 521,  //'<' This command reports the downlink BLER accumators for all active carriers
   _FTM_LTE_NS_ENABLE_MULTI_SCELL           = 522,  //'<' This command configures and activates SCELL<x>
   _FTM_LTE_NS_DISABLE_MULTI_SCELL          = 523,  //'<' This command disables SCELL<x>
   _FTM_LTE_NS_ENABLE_MULTI_SCELL_RX_TX     = 535,  //'<' This command enables UL & DL on SCELL<x>
   _FTM_LTE_NS_DISABLE_MULTI_SCELL_RX_TX    = 536,  //'<' This command disables UL & DL on SCELL<x>
   _FTM_LTE_NS_RX_SELECT_CHAIN_REQ          = 537   //'<' This command select Rx chain
} lte_ftm_cmd_code_enum_type;

/******************************************************************************
FTM - GPS
*******************************************************************************/

//! GPS FTM Packet version
#define GPS_FTM_PACKET_VERSION 0

/**
GPS FTM commands
*/
typedef enum
{
   _FTM_GPS_SET_LINEARITY_MODE          = 0,    //!< ' This command sets the desired linearity mode
   _FTM_GPS_ENABLE_SS_DC_CORRECTION = 1,    //!< ' This command enables or disables periodic DC correction, with 1ms period
   _FTM_GPS_INIT_FOR_IM2_CAL            = 2,    //!< ' This command prepares the GPS RFIC for the DC-based IM2 calibration
   _FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION= 3, //!< ' This command triggers a single iteration of the DC-based IM2 calibration
   _FTM_GPS_GET_BP_MEAN_AND_AMPL        = 4,    //!< ' This command returns BP_Mean and BP_Ampl from the Aries GPS engine
   _FTM_GPS_GET_CN0                 = 5     //!< ' This command returns the measured C/No ratio in tenths of dB
} gps_ftm_cmd_code_enum_type;

/**
Enumeration for QLIB_FTM_GPS_SET_LINEARITY_MODE() -> iLinearityMode field
*/
typedef enum
{
   FTM_GPS_SET_LINEARITY_MODE_LL        = 0x00,   //!< ' Low Linearity Mode
   FTM_GPS_SET_LINEARITY_MODE_HL        = 0x01,   //!< ' High Linearity Mode
   FTM_GPS_SET_LINEARITY_MODE_HL_AWS    = 0x02    //!< ' High Linearity Mode for AWS band
} ftm_gps_linearity_mode_enum_type;

/**
Enumeration for QLIB_FTM_GPS_ENABLE_SS_DC_CORRECTION() -> iEnable_DC_correction field
*/
typedef enum
{
   FTM_GPS_DISABLE_SS_DC_CORRECTION     = 0x00,  //!< ' Disable periodic steady-state DC correction
   FTM_GPS_ENABLE_SS_DC_CORRECTION          = 0x01   //!< ' Enable periodic steady-state DC correction
} ftm_gps_enable_ss_dc_correction_enum_type;

/**
Enumeration for QLIB_FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION() -> iI_Q_channel_id field
*/
typedef enum
{
   FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_CHANNEL_I        = 0x00,  //!< ' Perform single IM2cal iteration on I-channel
   FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_CHANNEL_Q        = 0x01   //!< ' Perform single IM2cal iteration on Q-channel
} ftm_gps_do_single_im2_channel_enum_type;

/**
Enumeration for QLIB_FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION() -> iDC_cancellation_method field
*/
typedef enum
{
   FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_METHOD_WITH_DC_DACS      = 0x00,  //!< ' Cancel DC component using DC DACs
   FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_METHOD_WITH_IM2_DACS = 0x01   //!< ' Cancel DC component using IM2 DACs
} ftm_gps_do_single_im2_cal_iteration_method_enum_type;

/**
Enumeration for QLIB_FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION() -> iDAC_search_space field
*/
typedef enum
{
   FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_FULL_SEARCH_SPACE        = 0x00,  //!< ' Full search space (applies to DAC code)
   FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_VICINITY_SEARCH_SPACE    = 0x01   //!< ' Vicinity search around previous optimim value (applies to DAC code)
} ftm_gps_do_single_im2_cal_iteration_search_space_enum_type;

/******************************************************************************
FTM - Sequencer
*******************************************************************************/

//! Maximum size of QMSL local command buffer for sequencer,
//! MDM9k seems to have problem handling diag command of 2048 bytes
#define FTM_Sequencer_Command_Queue_Buffer_Size             2047

//! This size should equal to the maximum diag packet size
#define MAX_FTM_Sequencer_Command_Queue_Buffer_Size DIAG_MAX_PACKET_SIZE

//! Defintions for use with the bSequencerRunningOnPC parameter in QLIB_FTM_SEQ_SetSequencerMode
#define QMSL_FTM_SEQUENCER_MODE_EMBEDDED (FALSE)
#define QMSL_FTM_SEQUENCER_MODE_DESKTOP (TRUE)

//! Defintions for use with the bSequencerRunningOnPC parameter in QLIB_FTM_SEQ_SetSequencerMode
#define QMSL_FTM_SEQUENCER_MODE_INACTIVE (FALSE)
#define QMSL_FTM_SEQUENCER_MODE_ACTIVE (TRUE)

/******************************************************************************
Diag - UBM DVBH
*******************************************************************************/
/**
\brief Enumeration of DVBH Command IDs
*/
typedef enum
{
   _DIAG_DVBH_UBM_L1_ACQ_CMD                    =0,
   _DIAG_DVBH_UBM_L1_CFG_CTRL_PID_CMD           =1,
   _DIAG_DVBH_UBM_L1_CFG_DATA_PID_CMD           =2,
   _DIAG_DVBH_UBM_L1_CFG_ITEM                   =5,
   _DIAG_DVBH_UBM_L1_ACQ_STATUS             =7,
   _DIAG_DVBH_UBM_L1_PRBS_ONE_BIT_CMD           =8,
   _DIAG_DVBH_UBM_L1_PRBS_ONE_BIT_STATUS        =9,
   _DIAG_DVBH_UBM_L1_POWERUP_CMD                =10,
   _DIAG_DVBH_UBM_L1_POWERDOWN_CMD              =11,
   _DIAG_DVBH_UBM_L1_WAKEUP_NOW_CMD         =12,
   _DIAG_DVBH_UBM_L1_ENABLE_LNA_UPDATE          =15,
   _DIAG_DVBH_UBM_L1_DISABLE_LNA_UPDATE     =16,
   _DIAG_DVBH_UBM_L1_PACKET_CNT_CMD         =17,
   _DIAG_DVBH_UBM_L1_CFG_JAMMER_CMD         =18,
   _DIAG_DVBH_UBM_L1_RSSI_STATUS                =19,
   _DIAG_DVBH_UBM_L1_CFG_POST_FFT_JAMMER_CMD    =23,
   _DIAG_DVBH_UBM_L1_USE_RSSI_CAL_CMD           =26,
   _DIAG_DVBH_UBM_L1_SET_LNA_CMD                =27,
   _DIAG_DVBH_UBM_L1_PREPARE_FOR_CW_CAL     =33,
   _DIAG_DVBH_UBM_L1_DISABLE_DSP_LOOPS_CMD      =35
} DIAG_DVBH_UBM_L1_Cmd_Id_Enum;

typedef enum
{
   UBM_L1_MODE_1        = 1,
   UBM_L1_MODE_2        = 2,
   UBM_L1_MODE_3        = 3,
   UBM_L1_MODE_ALL      = 255
} ubm_dvbh_mode;
typedef enum
{
   UBM_L1_GUARD_4       =0,
   UBM_L1_GUARD_8       =1,
   UBM_L1_GUARD_16      =2,
   UBM_L1_GUARD_32      =3,
   UBM_L1_GUARD_ALL =255
} ubm_dvbh_guard;
typedef enum
{
   UBM_L1_BW_5          =5,
   UBM_L1_BW_6          =6,
   UBM_L1_BW_7          =7,
   UBM_L1_BW_8          =8,
} ubm_dvbh_bandwidth;
typedef enum
{
   UBM_L1_CFG_EBI2_WS               =0,             //!< EBI2 waitstates
   UBM_L1_CFG_USE_PLLS              =1,             //!< whether to use RUMI's PLLs or System clock
   UBM_L1_CFG_CTRL_PID_EXT_MODE =2,             //!< whether to use MPE bank memory for Control PID
   //!< 0 -> Dont use bank memory
   //!< 1 -> Use bank memory
   UBM_L1_CFG_CTRL_PID_EBI2_MODE    =3,             //!< whether to read control PIDs via EBI2
   //!< 0 -> use TSIF to read PIDs
   //!< 1 -> use EBI2 to read PIDs
   UBM_L1_CFG_PAGE_MODE         =4,             //!< whether to use page mode for EBI2 comms to MBP.
   //!< 0 -> Dont use page mode
   //!< 1 -> Use page mode
   UBM_L1_CFG_USE_MODE2_CPCE        =5,             //!< whether to use channel estimation for mode 2
   //!< 0 -> do not use channel estimation
   //!< 1 -> use channel estimation
   UBM_L1_CFG_DEBUG             =6,             //!< whether to turn on CFG debugging messages
   //!< 0 -> Turn off CFG messages
   //!< 1 -> Turn on CFG messages
   UBM_L1_HANDLE_L3_ACK         =7,             //!< whether to handle acks intended for L3 by L1
   //!< 0 -> Handle L3 acks
   //!< 1 -> Do not handle L3 acks
   UBM_L1_CFG_USE_ACQ_TIMEOUT       =8,             //!< whether to use the acquisition timeout
   //!< 0 -> Do not use acq timeout
   //!< 1 -> Use acq timeout
   UBM_L1_CFG_SNOOZE                =9,             //!< whether to allow snoozing
   //!< 0 -> Disable snooze
   //!< 1 -> Enable snooze
   UBM_L1_CFG_SLEEP             =10,            //!< whether to allow sleeping
   //!< 0 -> Disable sleep
   //!<  1 -> Enable sleep
   UBM_L1_CFG_BW                    =11,            //!<  Set the channel bandwidth.
   //!<  0 -> UBM_L1_BW_5_MHZ
   //!<  1 -> UBM_L1_BW_6_MHZ
   //!<  2 -> UBM_L1_BW_7_MHZ
   //!<  3 -> UBM_L1_BW_8_MHZ
   UBM_L1_RX_FRONT_WARMUP           =12,            //!<  whether to do rx front warmup
   //!<  0 -> Dont use RX front end warmup
   //!<  1 -> Do RX front end warmup
   UBM_L1_CHANGE_TCXO_PDM           =13,            //!<  Whether to do TCXO corrections
   //!<  0 -> do not change TCXO PDM
   //!<  1 -> change TCXO PDM
   UBM_L1_MAP_ADDR_12_18            =14,            //!<  Whether to map A12-18 on debug bus  no matter whether page mode is used
   //!<  0 -> do not map A12-18
   //!<  1 -> do map A12 -18
   UBM_L1_FAP_LAP_CORR_MASK     =15,            //!<  Bit mask to enable/disable FAP/LAP correction for particular mode/guard combinations.
   //!<  To enable FAP/LAP correction for mode i, guard j, set bit number (i-1)*4+j to 1.
   //!<  Otherwise set it to 0. Default is 0x100, for mode 3 guard 0 only (8k, 1/4 guard).
   UBM_L1_SIGNAL_MONITOR            =16,            //!<  Signal Monitor.  Currently not used.  Default value is 0.
   UBM_L1_CFG_INPUT_MODE            =17,            //!<  Input mode type.
   //!< 0 -> RF mode
   //!< 1 -> IQ mode
   //!< 2 -> Y1Y2 mode
   UBM_L1_CFG_RDSP_CLK_SRC          =18             //!<  RDSP clock source
                                     //!<  0 -> Internal clock source (by PLL).
                                     //!< 1 -> External clock source.
} ubm_dvbh_configuration_items;
/******************************************************************************
FTM - WLAN
*******************************************************************************/

////////////////////
// First are the Philips definitions
////////////////////

/** Maximum message size */
#define FTM_WLAN_Philips_MAX_MSG_SIZE 1600

/** Philips "source" field value */
#define FTM_WLAN_Philips_SOURCE 0xFF

/** The FTM_WLAN_Philips_PCTI_READ_STATISTICS  response size, in byte */
#define FTM_WLAN_Philips_PCTI_READ_STATISTICS_RESPONSE_SIZE 128

/**
These are the module types which will be passed to the firmware
for each specific module selection from the host.

Used for SET_MODULE.
*/
typedef enum
{
   /* Washington modules (not supported) */
   FTM_WLAN_Philips_M1      = 0x00,
   FTM_WLAN_Philips_M2      = 0x01,
   FTM_WLAN_Philips_M3      = 0x02,
   FTM_WLAN_Philips_M4      = 0x03,
   FTM_WLAN_Philips_MWAmax  = 0x0F, /* end of Washington range */
   /* Georgia modules */
   FTM_WLAN_Philips_M_BGW211    = 0x10
} FTM_WLAN_Philips_enModuleType;

/* *
The data rate which will be passed from the host
This gets transferred to the rates required in the firmware

Used for TX_BURST
*/
typedef enum
{
   /* 11b rates backwards compatible with washington */
   FTM_WLAN_Philips_RATE_1_MBPS = 0x0,
   FTM_WLAN_Philips_RATE_2_MBPS = 0x1,
   FTM_WLAN_Philips_RATE_5_MBPS = 0x2,
   FTM_WLAN_Philips_RATE_11_MBPS    = 0x3,
   /* plcp rate codes used for OFDM rates */
   FTM_WLAN_Philips_RATE_6_MBPS = 11,
   FTM_WLAN_Philips_RATE_9_MBPS = 15,
   FTM_WLAN_Philips_RATE_12_MBPS    = 10,
   FTM_WLAN_Philips_RATE_18_MBPS    = 14,
   FTM_WLAN_Philips_RATE_24_MBPS    = 9,
   FTM_WLAN_Philips_RATE_36_MBPS    = 13,
   FTM_WLAN_Philips_RATE_48_MBPS    = 8,
   FTM_WLAN_Philips_RATE_54_MBPS    = 12
} FTM_WLAN_Philips_enDataRate;

/**
Sleep Test Option defines, used for SLEEP_MODE
*/
typedef enum
{
   FTM_WLAN_Philips_PCTI_SLEEP_DOWN = 0x0,
   FTM_WLAN_Philips_PCTI_TIMED_SLEEP = 0x1
} FTM_WLAN_Philips_enSleepMode;

/**
These are the results which will be passed from the firmware
for each specific command from the host
*/
typedef enum
{
   FTM_WLAN_Philips_PCTI_SUCCESS            = 0x00,
   FTM_WLAN_Philips_PCTI_FAILURE            = 0x01,
   FTM_WLAN_Philips_PCTI_NOT_SUPPORTED      = 0x02,
   /* Georgia (PCTI) specific */
   FTM_WLAN_Philips_PCTI_INVALID_PARAMETER  = 0x03,
   FTM_WLAN_Philips_PCTI_MISSING_PARAMETER  = 0x04,
   FTM_WLAN_Philips_PCTI_TEST_RUNNING       = 0x05
} FTM_WLAN_Philips_enPctiStatus;

/**
This corresponds to the data specific part of TX_CONTINUOUS test.
*/
typedef enum
{
   FTM_WLAN_Philips_SINGLETONE_100KHZ       = 1,
   FTM_WLAN_Philips_SINGLETONE_3MHZ     = 2,
   FTM_WLAN_Philips_SINGLETONE_5d5MHZ       = 3,
   FTM_WLAN_Philips_DUALTONE_100_300KHZ = 4,
   FTM_WLAN_Philips_DUALTONE_3_3d1MHZ       = 5,
   FTM_WLAN_Philips_DUALTONE_5d5_5d6MHZ = 6,
   FTM_WLAN_Philips_QPSK_0_1_SEQUENCE       = 7,
   FTM_WLAN_Philips_QPSK_PN_SEQUENCE        = 8
} FTM_WLAN_Philips_enSignalType;

/**
Specific request type used for passing Diagnostic request to the host
*/
typedef enum
{
   FTM_WLAN_Philips_PCTI_START                  = 0x01, //!< 'same as FTM_WLAN_Philips_PCTI_CONNECT_DUT
   FTM_WLAN_Philips_PCTI_SLEEP                  = 0x02, //!< 'not supported by PCTI
   FTM_WLAN_Philips_PCTI_TX_CONTINUOUS          = 0x03,
   FTM_WLAN_Philips_PCTI_TX_BURST               = 0x04,
   FTM_WLAN_Philips_PCTI_TX_POWER_CONTROL       = 0x05,
   FTM_WLAN_Philips_PCTI_RX_CONTINUOUS          = 0x06,
   FTM_WLAN_Philips_PCTI_REG_READ               = 0x08, //!< 'not supported by PCTI
   FTM_WLAN_Philips_PCTI_REG_WRITE              = 0x09, //!< 'not supported by PCTI
   FTM_WLAN_Philips_PCTI_EEPROM_READ            = 0x0A,
   FTM_WLAN_Philips_PCTI_EEPROM_WRITE           = 0x0B,
   FTM_WLAN_Philips_PCTI_SDIO_LOGIC         = 0x0C, //!< 'not supported by PCTI
   FTM_WLAN_Philips_PCTI_GET_MAC_ADDRESS        = 0x0D,
   FTM_WLAN_Philips_PCTI_STOP                   = 0x12,
   FTM_WLAN_Philips_PCTI_SET_TX_DATA            = 0x13,
   FTM_WLAN_Philips_PCTI_THREE_WIRE_READ        = 0x14, //!< 'not supported by PCTI
   FTM_WLAN_Philips_PCTI_THREE_WIRE_WRITE       = 0x15, //!< 'not supported by PCTI
   FTM_WLAN_Philips_PCTI_SET_MODULE         = 0x16,
   FTM_WLAN_Philips_PCTI_DISCONNECT_DUT     = 0x17,
   /* Georgia (PCTI) specific */
   FTM_WLAN_Philips_PCTI_GET_HWSW_VERSIONS      = 0x20,
   FTM_WLAN_Philips_PCTI_TX_POWER_SET_CALIBRATED    = 0x21,
   FTM_WLAN_Philips_PCTI_MEMORY_READ            = 0x22,
   FTM_WLAN_Philips_PCTI_MEMORY_WRITE           = 0x23,
   FTM_WLAN_Philips_PCTI_SB_REGISTER_READ       = 0x24,
   FTM_WLAN_Philips_PCTI_SB_REGISTER_WRITE      = 0x25,
   FTM_WLAN_Philips_PCTI_RF_REGISTER_READ       = 0x26,
   FTM_WLAN_Philips_PCTI_RF_REGISTER_WRITE      = 0x27,
   FTM_WLAN_Philips_PCTI_COEX_LINE_READ     = 0x28,
   FTM_WLAN_Philips_PCTI_COEX_LINE_WRITE        = 0x29,
   FTM_WLAN_Philips_PCTI_CHECK_EXT_32KHZ_CLOCK = 0x2A,
   FTM_WLAN_Philips_PCTI_READ_STATISTICS        = 0x2B,
   FTM_WLAN_Philips_PCTI_RESET_STATISTICS       = 0x2C,
   FTM_WLAN_Philips_PCTI_SET_MAC_ADDRESS        = 0x2D,
   FTM_WLAN_Philips_PCTI_SLEEP_MODE         = 0x2E,
   FTM_WLAN_Philips_PCTI_GET_TEMPERATURE        = 0x2F,
   FTM_WLAN_Philips_PCTI_GET_CALIBRATIONINFO    = 0x30,
   FTM_WLAN_Philips_PCTI_SET_CALIBRATIONINFO    = 0x31,
   FTM_WLAN_Philips_PCTI_LOOPBACK_MODE          = 0x32,
   FTM_WLAN_Philips_PCTI_DEBUG_LEVEL            = 0x33
} FTM_WLAN_Philips__enPctiType;

/**
Redefinition for Washington Compatibility
*/
#define FTM_WLAN_Philips_PCTI_CONNECT_DUT FTM_WLAN_Philips_PCTI_START

////////////////////
// Second are the Atheros definitions
////////////////////
/** Atheros: Continuous Transmit */
#define FTM_WLAN_Atheros_CMD_CONT_TRANSMIT  0x0

/** Atheros: Continuous Receive */
#define FTM_WLAN_Atheros_CMD_CONT_RECEIVE   0x1

/** Atheros: Force wake/sleep */
#define FTM_WLAN_Atheros_CMD_WAKE_SLEEP     0x2

/** Atheros: Continuous Receive Command Action*/

/** Accept all incoming frames */
#define FTM_WLAN_Atheros_CMD_CONT_RECEIVE_ACT_PROMISCUOUS_MODE  0x0
/** Accept frames accept only frames with dest address equal specified mac address */
#define FTM_WLAN_Atheros_CMD_CONT_RECEIVE_ACT_FILTER_MODE       0x1
/** Disable Rx and get last Rx report */
#define FTM_WLAN_Atheros_CMD_CONT_RECEIVE_ACT_OFF_MODE          0x2
/** Set MAC Address */
#define FTM_WLAN_Atheros_CMD_CONT_RECEIVE_ACT_SET_MAC_ADDRESS   0x3

typedef enum
{
   /* 11b rates backwards compatible with washington */
   FTM_WLAN_Atheros_RATE_1_MBPS = 0,
   FTM_WLAN_Atheros_RATE_2_MBPS = 1,
   FTM_WLAN_Atheros_RATE_5_MBPS = 2,
   FTM_WLAN_Atheros_RATE_11_MBPS    = 3,
   /* plcp rate codes used for OFDM rates */
   FTM_WLAN_Atheros_RATE_6_MBPS = 4,
   FTM_WLAN_Atheros_RATE_9_MBPS = 5,
   FTM_WLAN_Atheros_RATE_12_MBPS    = 6,
   FTM_WLAN_Atheros_RATE_18_MBPS    = 7,
   FTM_WLAN_Atheros_RATE_24_MBPS    = 8,
   FTM_WLAN_Atheros_RATE_36_MBPS    = 9,
   FTM_WLAN_Atheros_RATE_48_MBPS    = 10,
   FTM_WLAN_Atheros_RATE_54_MBPS    = 11,
} FTM_WLAN_Atheros_enDataRate;

typedef enum
{
   FTM_WLAN_Atheros_CMD_SYNC = 0,
   FTM_WLAN_Atheros_CMD_ASYNC = 1
} FTM_WLAN_Atheros_cmdType;

typedef enum
{
   FTM_WLAN_BDF_GET_MAX_TRANSFER_SIZE = 1,
   FTM_WLAN_BDF_READ = 2,
   FTM_WLAN_BDF_WRITE = 3,
   FTM_WLAN_BDF_GET_FNAMEPATH = 4,
   FTM_WLAN_BDF_SET_FNAMEPATH = 5
} FTM_WLAN_BDF_cmdType;

/** Qualcomm Atheros AR6005 self init result structure */
#define PSAT_WHAL_NUM_11G_CAL_PIERS_MAX 3
#define PSAT_WHAL_NUM_11A_CAL_PIERS_MAX 5

typedef struct
{
   char    olpcGainDelta_diff;
   char    olpcGainDelta_abs;
   unsigned char   thermCalVal;
   unsigned char   numTryBF;
   unsigned int  cmac_olpc;
   unsigned int  cmac_psat;
   unsigned short  cmac_olpc_pcdac;
   unsigned short  cmac_psat_pcdac;
   short  lineSlope;
   short  lineVariance;
   unsigned short  psatParm;
   char   reserved[2];
} OLPCGAIN_THERM_DUPLET;

typedef struct
{
   OLPCGAIN_THERM_DUPLET olpcGainTherm2G[PSAT_WHAL_NUM_11G_CAL_PIERS_MAX];
   OLPCGAIN_THERM_DUPLET olpcGainTherm5G[PSAT_WHAL_NUM_11A_CAL_PIERS_MAX];
} PSAT_CAL_RESULTS;

/////////////////////////////
///   Below this are Qualcomm specific definitions
/////////////////////////////

/**
The list of commands in the FTM_WLAN mode_id
*/
typedef enum
{
   _FTM_WLAN_USER_CMD        = 0        //!<' Send a user command buffer to any WLAN module
} FTM_WLAN_CmdEnum;

/**
Defines the types of modules supported, to be used for the eModuleType parameter
for FTM_WLAN operations in QLIB.H, and for the FTM_WLAN_USER_CMD.

*/
typedef enum
{
   FTM_WLAN_ModuleType_Philips  = 0x00, //!< Philips WLAN module
   FTM_WLAN_ModuleType_Atheros  = 0x01, //!< Atheros WLAN module
   FTM_WLAN_ModuleType_GEN6 = 0x02, //!< Qualcomm GEN6 (WCN1312)
} FTM_WLAN_ModuleTypeEnum;

//! Size of WLAN MAC Address
#define FTM_WLAN_MAC_ADRESS_SIZE 6

/******************************************************************************
FTM - QFUSE
*******************************************************************************/
typedef enum
{
   FTM_QFUSE_Read   = 0x00,     //!< QFUSE read request
   FTM_QFUSE_Write  = 0x01,     //!< QFUSE write request
} FTM_QFUSE_CmdEnum;

/******************************************************************************
FTM - QEPROM
*******************************************************************************/
typedef enum
{
   FTM_QEPROM_Read      = 0x00,     //!< QEPROM read request
   FTM_QEPROM_Write = 0x01,     //!< QEPROM write request
} FTM_QEPROM_CmdEnum;

#define FTM_QFUSE_Configuration_Chain 0

/**
QEPROM read/write API status enumeration
*/
typedef enum
{
   QFPROM_NO_ERR= 0,
   QFPROM_DATA_PTR_NULL_ERR,
   QFPROM_ADDRESS_INVALID_ERR,
   QFPROM_CLOCK_SETTINGS_INVALID_ERR,
   QFPROM_NO_SPECIAL_ITEM_FOUND_ERR,
   QFPROM_OPERATION_NOT_ALLOWED_ERR,
   QFPROM_FAILED_TO_CHANGE_VOLTAGE_ERR,
   QFPROM_WRITE_ERR,
   QFPROM_REGION_NOT_SUPPORTED_ERR,
   QFPROM_REGION_NOT_READABLE_ERR,
   QFPROM_REGION_NOT_WRITEABLE_ERR,
   QFPROM_REGION_FEC_ENABLED_NOT_WRITEABLE_ERR,
   QFPROM_REGION_RAW_ADDR_READ_BACK_VERIFY_ERR,
   QFPROM_REGION_CORR_ADDR_READ_BACK_VERIFY_ERR,
   QFPROM_ROW_BOUNDARY_CONDITION_VERIFY_ERR,

   /* Add above this */
   QFPROM_ERR_UNKNOWN = 0x7FFFFFFF        /* To ensure it's 32 bits wide */
} QFPROM_ERR_CODE;

/******************************************************************************
QMSL - Calibration Data Manager
*******************************************************************************/
/**
Definition of NV Modes, which are used to specify which series of NV items will be written to.

For example, older cdma2000 targets use the "NV_CDMA_" and "NV_PCS" prefixes while newer targets
use "NV_BC0_" and "NV_BC1_" prefixes.

These prefixes map to different nv_mode_id_type values.

"NV_CDMA" is NV_MODE_CDMA_800 and "NV_BCO" is NV_MODE_BC0

IMPORTANT: Maintain the order of these elements the same as the order of the elements in nv_mode_id in QMSL_NVDefinition.xsd
*/

typedef enum
{
   NV_MODE_CDMA_800=5,
   NV_MODE_CDMA_1900=6,
   NV_MODE_WCDMA_IMT=9,
   NV_MODE_WCDMA_1900A=15,
   NV_MODE_WCDMA_1900B=16,
   NV_MODE_WCDMA_800=22,
   NV_MODE_WCDMA_800A=23,
   NV_MODE_WCDMA_1800=25,
   NV_MODE_WCDMA_BC4=28,
   NV_MODE_WCDMA_BC8=29,

   NV_MODE_BC0 = 100,
   NV_MODE_BC1 = 101,
   NV_MODE_BC2 = 102,
   NV_MODE_BC3 = 103,
   NV_MODE_BC4 = 104,
   NV_MODE_BC5 = 105,
   NV_MODE_BC6 = 106,
   NV_MODE_BC7 = 107,
   NV_MODE_BC8 = 108,
   NV_MODE_BC9 = 109,
   NV_MODE_BC10 = 110,
   NV_MODE_BC11 = 111,
   NV_MODE_BC14 = 114,
   NV_MODE_BC15 = 115,
   NV_MODE_BCX_BLOCK = 150,
   NV_MODE_BCX_BLOCK1 = 151,
   // GSM NV mode id
   NV_MODE_GSM_850  = 18,
   NV_MODE_GSM_EGSM = 10,
   NV_MODE_GSM_DCS  = 11,
   NV_MODE_GSM_1900 = 12,
   NV_MODE_GSM_DCS_B  = 13,
   // LTE NV Mode ids
   NV_MODE_LTE_B1 = 34,
   NV_MODE_LTE_B7 = 35,
   NV_MODE_LTE_B13 = 36,
   NV_MODE_LTE_B17 = 37,
   NV_MODE_LTE_B38 = 38,
   NV_MODE_LTE_B40 = 39,

   NV_MODE_WCDMA_1500=40,
   //WCDMA Dual Carrier NV
   NV_MODE_WCDMA_DC1 = 41,
   NV_MODE_WCDMA_DC2 = 42,
   NV_MODE_WCDMA_IMT_DC = 43,

   NV_MODE_LTE_B4 = 44,
   NV_MODE_LTE_B11 = 45,

   NV_MODE_LTE_B2=46,
   NV_MODE_LTE_B3=47,
   NV_MODE_LTE_B5=48,
   NV_MODE_LTE_B6=49,
   NV_MODE_LTE_B8=50,
   NV_MODE_LTE_B9=51,
   NV_MODE_LTE_B10=52,
   NV_MODE_LTE_B12=53,
   NV_MODE_LTE_B14=54,
   NV_MODE_LTE_B15=55,
   NV_MODE_LTE_B16=56,
   NV_MODE_LTE_B18=57,
   NV_MODE_LTE_B19=58,
   NV_MODE_LTE_B20=59,
   NV_MODE_LTE_B21=60,
   NV_MODE_LTE_B22=61,
   NV_MODE_LTE_B23=62,
   NV_MODE_LTE_B24=63,
   NV_MODE_LTE_B25=64,
   NV_MODE_LTE_B26=65,
   NV_MODE_LTE_B27=66,
   NV_MODE_LTE_B28=67,
   NV_MODE_LTE_B29=68,
   NV_MODE_LTE_B30=69,
   NV_MODE_LTE_B31=70,
   NV_MODE_LTE_B32=71,
   NV_MODE_LTE_B33=72,
   NV_MODE_LTE_B34=73,
   NV_MODE_LTE_B35=74,
   NV_MODE_LTE_B36=75,
   NV_MODE_LTE_B37=76,
   NV_MODE_LTE_B39=77,

   NV_MODE_WCDMA_1900B_DC = 78,
   NV_MODE_WCDMA_900_DC = 79,

   NV_MODE_LTE_B41=80,
   NV_MODE_LTE_B42=81,
   NV_MODE_LTE_B43=82,
   NV_MODE_LTE_B44=83,

   //TDSCDMA reserves 90 - 99
   NV_MODE_TDSCDMA_B34=90,
   NV_MODE_TDSCDMA_B39=91,
   NV_MODE_TDSCDMA_B40=92,
   NV_MODE_TDSCDMA_B40_B=93,

   //WCDMA Dual Carrier NV
   NV_MODE_WCDMA_1500_DC=160,
   NV_MODE_WCDMA_1800_DC=161,
   NV_MODE_WCDMA_B4_DC=162,
   //LTE NV Mode ids
   NV_MODE_LTE_B40_B = 163,
   NV_MODE_LTE_B41_B = 164,
   NV_MODE_LTE_B41_C = 165,
   NV_MODE_LTE_B28_B = 166,
   NV_MODE_LTE_B39_B = 167,

   NV_MODE_LTE_B45 = 168,
   NV_MODE_LTE_B252 = 169,
   NV_MODE_LTE_B255 = 171,

   NV_MODE_LTE_B66 = 172,

   NV_MODE_MAX=255
} nv_mode_id_type;

/**
Tx Freq Compensation NV type

All 1x MSM targets with RF chipsets other than RTR6500 use use QMSL_TX_COMP to map NVs to NV_<band class>_TX_COMP
All UMTS MSM targets use QMSL_TX_COMP to map NVs to NV_<band class>_TX_COMP
All 1x MSM targets with RF chipset RTR6500 use QMSL_TX_PWR_COMP to map NVs to NV_<band class>_TX_PWR_COMP

*/
typedef enum
{
   QMSL_NV_TX_COMP = 0,
   QMSL_NV_TX_PWR_COMP = 1
} nv_tx_comp_res_type;

/**
Tx Freq Compensatiion NV type
*/

typedef enum
{
   NV_TX_COMP_PRIM_ONLY = 0,      // Used by all targets
   NV_TX_COMP_PRIM_AND_SEC = 1   // Used by RTR6285.  RTR6285 requires 2 Tx freq compenstation values
} nv_tx_freq_comp_type;
/*
Array size defintions for QMSL RF Calibration Data Manager
*/
//!Number of FBRx Gain states
#define QMSL_NUM_FBRx_GAIN_STATES 4

//!Number of coefficients per droop filter
#define QMSL_DROOP_FILTER_COEFFS_NUM 32

//!Number of FBRx Modes
#define QMSL_NUM_FBRx_MODES 4

//! Maximum number of cdma/wcdma number of Rx LNA states
#define QMSL_CDMA_RX_LNA_STATE_MAX 6

//! Maximum number of cdma/wcdma number of Rx power modes
#define QMSL_CDMA_MAX_RX_POWER_MODES 4

//! LTE IM2 NV Size
#define QMSL_LTE_IM2_SIZE 3

//! Maximum number of cdma/wcdma receivers
#define QMSL_CDMA_MAX_RECEIVERS 4

//! Maximum number of cdma/wcdma calibration channels
#define QMSL_CDMA_MAX_CHANNELS 16

//! Maximum number of PDM's available in any cdma/wcdma mode
#define QMSL_CDMA_MAX_PDM_STEPS 512

//! Maximum number of Tx Gain States available in any cdma/wcdma mode
#define QMSL_CDMA_MAX_TX_GAIN_STATES 4

//! Maximum number of Tx Gain States available in LTE mode
#define QMSL_LTE_MAX_TX_GAIN_STATES 8

//! Maximum number of RGI's available in any GSM mode
#define QMSL_GSM_MAX_RGI_STEPS 32

//! Maximum number of PCL's for any GSM mode
#define QMSL_GSM_MAX_PCL_STEPS 16

//! Maximum number of phase/amplitude samples for predistortion cal
#define QMSL_GSM_MAX_PREDIST_SAMPLES 64000

//! Maximum number of phase/amplitude samples for predistortion cal
#define QMSL_GSM_MAX_NON_IQ_PREDIST_SAMPLES 512

//! Number of PreDistortion Calibration AM/PM NV items per channel
#define QMSL_NV_MANAGER_PREDIST_CAL_TABLE_NUM           2

//! Maximum number of Tx Gain States available in any gsm mode
#define QMSL_GSM_MAX_TX_GAIN_STATES 8

//! Max GSM DA calibration number of steps - affects both GSM V2 and V3 calibration. This is a modem software limitation.
#define QMSL_GSM_MAX_DA_CAL_NUM_STEPS  325

//! Maximum number of Tx Gain States available in any gsm mode
#define QMSL_GSM_MAX_TX_CAL_CHANNELS 3

//! Maximum number of measurements for Tx Lim vs Freq, at each frequency, for any cdma/wcdma mode
#define QMSL_CDMA_MAX_TX_LIM_MEASUREMENTS 20

#define QMSL_CDMA_INTELLICEIVER_VALUE_ARRAY 128
/**
Defintion of one band of cdma2000/WCDMA Rx measurement structure, for use with the
QMSL RF Calibration Data manager functions
*/

//! NV item name length
#define QMSL_NV_MANAGER_NV_ITEM_NAME_LENGTH     50

//! Maximum number of DVGA/LNA offset vs freq NV item size
#define QMSL_NV_MANAGER_MAX_DVGA_LNA_OFFSET_VS_FREQ_SIZE    48

//! CDMA Tx Linearizer table slope size
#define QMSL_NV_MANAGER_CDMA_TX_LIN_TABLE_SLOPE_SIZE    36

//! CDMA Tx Linearizer table slope size
#define QMSL_NV_MANAGER_CDMA_TX_LIN_TABLE_SIZE  37

//! WCDMA Tx Linearizer table size
#define QMSL_NV_MANAGER_WCDMA_TX_LIN_TABLE_SIZE     37

//! WCDMA Tx Linearizer(Beta scaling) table size
#define QMSL_NV_MANAGER_WCDMA_BETA_SCALING_NV_SIZE  32

//! WCDMA Enhanced Tx Linearizer(Beta scaling) table size
#define QMSL_NV_MANAGER_WCDMA_ENH_BETA_SCALING_NV_SIZE  64

//! LTE Tx Linearizer(Beta scaling) table size
#define QMSL_NV_MANAGER_LTE_BETA_SCALING_NV_SIZE    64

//! CDMA Tx Linearizer(Beta scaling) table max size
#define QMSL_NV_MANAGER_CDMA_BETA_SCALING_NV_SIZE   64

//! CDMA Tx Linearizer (RTR6500) table msx size
#define QMSL_NV_MANAGER_CDMA_TX_LIN_RTR6500_TABLE_SIZE 64

//! Maximum number of Polar cal raw data point
#define QMSL_NV_MANAGER_POLAR_CAL_RAW_DATA_MAX_SIZE 512

//! Polar calibration AMAM table size
#define QMSL_NV_MANAGER_POLAR_CAL_AMAM_TABLE_SIZE   64
#define QMSL_GSM_NUM_DAC_AMAM_TABLE                 2*QMSL_NV_MANAGER_POLAR_CAL_AMAM_TABLE_SIZE

//! Polar calibration AMAM table size
#define QMSL_NV_MANAGER_PREDISTORTION_CAL_AMAM_AMPM_TABLE_SIZE  64

//! Linear Tx Calibration DPD Table Size
#define QMSL_NV_MANAGER_EDGE_DPD_TABLE_SIZE 128

//! Maximum number of PCLs / Band in GSM/EDGe
#define QMSL_GSM_MAX_PCL_LIST_SIZE 16

//! Polar calibration AMPM table size
#define QMSL_NV_MANAGER_POLAR_CAL_AMPM_TABLE_SIZE   32

//! Number of Polar Calibration AM/PM NV items per channel
#define QMSL_NV_MANAGER_POLAR_CAL_TABLE_NUM         8

#define QMSL_NV_MANAGER_HDET_VS_AGC_NV_SIZE         16

#define QMSL_NV_MANAGER_GSM_IM2_CAL_MAX_SIZE        3

#define QMSL_NV_MANAGER_THERM_CAL_OFFSETS_FOR_NV_THERM_BINS   8

#define QMSL_NV_MANAGER_COMPRESSED_VALUE_MAX_SIZE       3800

#define QMSL_NV_MANAGER_MAX_NV_SIZE      QMSL_NV_MANAGER_COMPRESSED_VALUE_MAX_SIZE

//! Enhanced Predistortion Calibration: Digital gain table size
#define QMSL_NV_MANAGER_ENH_CAL_DIG_GAIN_TABLE_SIZE 64

/**
Defintion of Rx Calibration Measurement (DVGA and LNA offsets) for use with the
QMSL RF Calibration Data manager functions
*/
typedef struct
{
   //! Storage of LNA Offset measurements for each channel, gain state and Rx power mode.
   short aiLNA_Measured[ QMSL_CDMA_MAX_CHANNELS ][ QMSL_CDMA_RX_LNA_STATE_MAX ][ QMSL_CDMA_MAX_RX_POWER_MODES ];

   //! Storage of DVGA Offset measurements for each channel and Rx power mode. Not used for LTE.
   short aiDVGA_Measured[ QMSL_CDMA_MAX_CHANNELS ] [ QMSL_CDMA_MAX_RX_POWER_MODES ];

   //! \brief An array of LNA NV indices measured.\n
   //! For 1x targets, the lowest LNA NV index is 0.\n
   //! For UMTS targets, the lowest LNA NV index is 1.\n
   //! For LTE targets, the lowest LNA NV index is 0.
   unsigned short aiLNA_States[ QMSL_CDMA_RX_LNA_STATE_MAX ];

   //! Number of Rx LNA NV indices measured.
   unsigned long iNumMeasured_LNA_States;

   //! Number of Rx power modes measured. Set to 1 for chipsets that do not support selectable Rx power modes (non-IntelliCeiver).
   unsigned long iNumMeasuredPowerModes;

   //! \brief Indicates whether the measured data is for the primary or secondary Rx chain.\n
   //! 0 = Primary, 1 = Secondary
   unsigned short iPath;

   //! Indicates whether carrier aggregation is enabled
   //! 0 = CA enabled; 1 = CA disabled
   unsigned short iCAenabled;
} QMSL_CDMA_RxFreq_Measurement_struct;

/**
Definition of NV item generated by QMSL RF Calibration Data manager
*/
typedef struct
{
   //! NV item enumeration
   short            iNVenum;

   //! NV item name
   char         sNVName[QMSL_NV_MANAGER_NV_ITEM_NAME_LENGTH];

   //! The NV byte array
   unsigned char    aNVItemData[DIAG_NV_ITEM_DATA_SIZE];

   //! Number of byte in the array
   unsigned char   iNumOfBytes;

   //! The compressed byte array
   unsigned char  aRFNVItemData[QMSL_NV_MANAGER_COMPRESSED_VALUE_MAX_SIZE];

   //! Number of valid bytes in aRFNVItemData
   unsigned short iNumOfValidBytesInRFItemData;
   //
} QMSL_RFCAL_NV_Item;

/**
Definition of Generic NV item
*/
typedef struct
{
   //! NV item enumeration
   short            iNVenum;

   //! The NV byte array
   unsigned char    aNVItemData[QMSL_NV_MANAGER_MAX_NV_SIZE];

   //! Number of valide bytes in the array
   unsigned short   iNumOfValidBytes;
   //
} QMSL_NV_Item;

/**
Definition of DVGA offset generated by QMSL RF Calibration Data manager
*/

typedef struct
{
   //! DVGA offset
   short            iDVGAOffset;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_CDMA_Rx_DVGA_NV_Result;

/**
Definition of DVGA offset vs Freq generated by QMSL RF Calibration Data manager
*/

typedef struct
{
   //! DVGA offset vs Freq
   char iDVGAOffsetVsFreq[QMSL_NV_MANAGER_MAX_DVGA_LNA_OFFSET_VS_FREQ_SIZE];

   //! Storage of DVGA Offset vs freq
   short    iDVGAOffsetVsFreqItem[ QMSL_CDMA_MAX_CHANNELS ] [ QMSL_CDMA_MAX_RX_POWER_MODES ];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
}  QMSL_CDMA_Rx_DVGA_VS_FREQ_NV_Result;

/**
Definition of LNA offset generated by QMSL RF Calibration Data manager
*/

typedef struct
{
   //! LNA offset
   short            iLNAOffset;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
}  QMSL_CDMA_Rx_LNA_NV_Result;

/**
Definition of LTE LNA offset generated by QMSL RF Calibration Data manager
*/

typedef struct
{
   //! LNA offset
   short            iLNAOffset[16];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
}  QMSL_LTE_Rx_LNA_NV_Result;

/**
Definition of LNA offset vs freq generated by QMSL RF Calibration Data manager
*/

typedef struct
{
   //! LNA offset vs freq
   char iLNAOffsetVsFreq[QMSL_NV_MANAGER_MAX_DVGA_LNA_OFFSET_VS_FREQ_SIZE];

   //! LNA offset vs freq
   char     iLNAOffsetVsFreqItem[ QMSL_CDMA_MAX_CHANNELS ][ QMSL_CDMA_MAX_RX_POWER_MODES ];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
}  QMSL_CDMA_Rx_LNA_VS_FREQ_NV_Result;

typedef struct
{
   //! LNA offset vs freq
   short    iLNAOffsetVsFreq[128];

   //! LNA offset vs freq
   short    iLNAOffsetVsFreqItem[128];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
}  QMSL_LTE_Rx_LNA_VS_FREQ_NV_Result;

/**
Definition of Rx calibration (DVGA and LNA) results generated by QMSL RF Calibration Data manager
*/
typedef struct
{
   //! DVGA offset
   QMSL_CDMA_Rx_DVGA_NV_Result aDVGA;

   //! DVGA offset vs freq
   QMSL_CDMA_Rx_DVGA_VS_FREQ_NV_Result aDVGAvsFreq;

   //! LNA offset
   QMSL_CDMA_Rx_LNA_NV_Result aLNA[QMSL_CDMA_RX_LNA_STATE_MAX];

   //! LNA offset vs freq
   QMSL_CDMA_Rx_LNA_VS_FREQ_NV_Result aLNAvsFreq[QMSL_CDMA_RX_LNA_STATE_MAX];

   //! LTE LNA offset
   QMSL_LTE_Rx_LNA_NV_Result aLTELNAOffset;

   //! LTE LNA offset vs freq
   QMSL_LTE_Rx_LNA_VS_FREQ_NV_Result aLTELNAOffsetvsFreq;

   //! Number of LNA states generated by NV Manager
   int iNumOfLNAstates;
} QMSL_CDMA_Rx_DVGA_LNA_Cal_NV_Result;

typedef struct
{
   //! Intra CA LNA offset
   signed char iIntraLNAOffset[384];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_LTE_Rx_IntraCA_Cal_NV_Result;

/**
Definition of Rx IM2 measurments for use with QMSL RF Calibration Data manager
*/
typedef struct
{
   //! Storage of IM2 - I values for each Rx power mode.
   unsigned short aiIM2_I[ QMSL_CDMA_MAX_RX_POWER_MODES ];

   //! Storage of IM2 - Q values for each Rx power mode.
   unsigned short aiIM2_Q[ QMSL_CDMA_MAX_RX_POWER_MODES ];

   //! Storage of IM2 - G (transconductance) values for each Rx power mode.
   unsigned short aiIM2_G[ QMSL_CDMA_MAX_RX_POWER_MODES ];

   //! Number of Rx power modes measured. Set to 1 for chipsets that do not support selectable Rx power modes (non-IntelliCeiver).
   unsigned long iNumMeasuredPowerModes;

   //! \brief Indicates whether the measured data is for the primary or secondary Rx chain.\n
   //! 0 = Primary, 1 = Secondary
   unsigned short iPath;
} QMSL_CDMA_RxIM2_Measurement_struct;

//! Maximum number of PDMs and Pwrs for DC DC PDM calibration
#define QMSL_GSM_MAX_PDM_PCL_INDEX 16

//  Definition of GSM Tx DC DC PDM Calibration results generated by QMSL RF Calbration Data Manager

typedef struct
{
   //! DC DC PDM CAL TABLE table value
   unsigned long iDC_DC_PDM_CAL_TBL[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! NV item generated
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_DC_DC_PDM_Cal_NV_struct;

/**
Definition of GSM Tx DC DC PDM Calibration measurements for use by QMSL RF Calbration Data Manager
*/
typedef struct
{
   //! Storage for size of NV array
   int iNVcount;
   //! Storage for the RfMode
   int iRfMode;
   //! Storage for Number of measurements made
   int iNumMeas;
   //! Storage for Number of measurements used
   int iNumMeasUsed;
   //! Storage for the coefts of the Quadratic Curve fit daX^2 + dbX + dc
   double da,db,dc;
   //! Storage for the lowest possible PDM value to be written to the NV
   double dPdmAbsMin;
   //! Storage for lowest power measured to be used for curve fitting
   double dPwrCurveFitMin;
   //! Storage for highest power measured to be used for curve fitting
   double dPwrCurveFitMax;
   //! Storage for the measured Tx Power
   double aSmpsTxPwr[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Storage for the set PDM
   double aSmpsPDM[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Storage for the measurements used for curve fitting
   double aSmpsTxPwrUsed[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Storage for the PDM values used for curve fitting
   double aSmpsPDMUsed[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Storage for the Head Room values to be added to NV PDM values.
   double dHeadRoomList[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Storage for the NV generation Mask, a 0 indicates VBATT instead of SMPS power supply.
   double dMaskNVGeneration[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Storage for the PDM values generated from the curve fit equation for each of the PCL powers.
   double dPdmListCurveFit[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Storage for the Pwr values corresponding to each PCL value.
   double dPwrListNV[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Storage for the final NV generated
   double dPdmListNV[QMSL_GSM_MAX_PDM_PCL_INDEX];
} QMSL_GSM_DC_DC_PDM_Measurement_struct;

//  Definition of GSM Tx DC DC PDM Calibration results generated by QMSL RF Calbration Data Manager
typedef struct
{
   //! DC DC PDM CAL TABLE table value
   unsigned long iPADAC_DC_OFFSET[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! NV item generated
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_PA_DAC_Cal_NV_struct;

/**
Definition of GSM Tx DC DC PDM Calibration measurements for use by QMSL RF Calbration Data Manager
*/
typedef struct
{
   //! Storage for size of NV array
   int iNVcount;
   //! Storage for the RfMode
   int iNumMeas;
   //! Storage for the coefts of the Quadratic Curve fit daX^2 + dbX + dc
   double da,db,dc;
   //! DC Offset Step size
   int iDCOffsetStep;
   //! Tx Power Tolerance
   double dTxPowerTolerance;
   //! Maximum Target Tx Power
   double dTargetTxPwrMax;
   //! Target Tx Power List
   double dTargetTxPwrs[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Set SMPS PDM
   int iSmpsPdms[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Target Tx Power List
   double dMeasTxPwr[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Power Levels to be used in curve fit
   double dPwrListNV[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Computed DC Offset from curve fit
   double dDCOffsetCurveFit[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Set DC Offset to be used for curve fitting
   double dDCOffsetSet[QMSL_GSM_MAX_PDM_PCL_INDEX];
   //! Set computed DC Offset generated for NV
   double dDCOffsetNV[QMSL_GSM_MAX_PDM_PCL_INDEX];
} QMSL_GSM_PA_DAC_Measurement_struct;

/**
Definition of CDMA Rx IM2 results generated by QMSL RF Calibration Data manager
*/
typedef struct
{
   //! Number of valid NV items generated in aNVitem
   unsigned short iNumOfNVitemsGenerated;

   //! NV items generated
   QMSL_RFCAL_NV_Item aNVitem[5];
} QMSL_CDMA_RxIM2_NV_struct;

/**
Definition of LTE Rx IM2 results generated by QMSL RF Calibration Data manager
*/
typedef struct
{
   //! Number of valid NV items generated in aNVitem
   unsigned char iIM2IQG[QMSL_LTE_IM2_SIZE];

   //! NV item generated
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_LTE_RxIM2_NV_struct;

// Need to add jammer cal

/**
Defintion of structure for one band of cdma2000/WCDMA tx linearizer measurement, for
use with the QMSL RF Calibration Data manager functions
*/
typedef struct
{
   //! Storage for Tx power (dBm) for each gain range
   double aiTxLinPower[ QMSL_CDMA_MAX_TX_GAIN_STATES ][ QMSL_CDMA_MAX_PDM_STEPS ];

   //! Storage for Tx PDMs (AGC) for each gain range
   unsigned short aiTxLinPDM[ QMSL_CDMA_MAX_TX_GAIN_STATES ][ QMSL_CDMA_MAX_PDM_STEPS ];

   //! Storage for HDET values to be used to generate HDET vs AGC table
   unsigned short aiTxHDET[ QMSL_CDMA_MAX_PDM_STEPS ];

   //! Flag to state if LPM HDET data is included in aiTxHDETLPM or not
   unsigned char aiTxHDETLPMEnabled;

   //! Storage for LPM HDET values to be used to generate LPM HDET vs AGC table
   unsigned short aiTxHDETLPM[ QMSL_CDMA_MAX_PDM_STEPS ];

   //! Number of Tx gain states for which Tx power vs PDM was measured
   unsigned long iNumMeasuredTxGainStates;

   //! Number of Tx power vs PDM values measured for each gain state
   unsigned short iNumTxPowerMeasurementsPerRange[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! \brief Tx measurement to NV Index mapping. The value is mapped to the index of the NV_TX_LIN_<index> item.\n
   //! For example, a 3 gain range design with aiTxMeasToNVMapping = [0, 1, 3] maps to NV_TX_LIN_0, NV_TX_LIN_1 and NV_TX_LIN_3\n
   //! aiTxLinPower[0] and aiTxLinPDM[0] generate NV_TX_LIN_0\n
   //! aiTxLinPower[1] and aiTxLinPDM[1] generate NV_TX_LIN_1\n
   //! aiTxLinPower[2] and aiTxLinPDM[2] generate NV_TX_LIN_3\n
   //! Any values in aiTxLinPower[3] and aiTxLinPDM[3] are ignored
   unsigned short aiTxMeasToNVMapping[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! \brief Tx measurement index used to generate the HDET vs AGC table\n
   //! For example, a value of 2 means that aiTxHDET and aiTxLinPower[2] are used to generate the HDET vs AGC table
   unsigned short iTxMeasIndexUsedForHDET;

   //! Desired power level for HDET Span calculation (usually 26 dBm)
   double HDET_SpanPower_dBm;

   //! Desired power level for HDET Offset calculation (usually 18 dBm)
   double HDET_OffsetPower_dBm;
} QMSL_CDMA_TxLin_struct;

/**
Defintion of structure for one band of cdma2000/WCDMA/LTE tx linearizer measurement, for
use with the QMSL RF Calibration Data manager functions
*/
typedef struct
{
   //! Storage for Tx power (dBm) for each Tx gain state.
   double aiTxLinPower[ QMSL_CDMA_MAX_TX_GAIN_STATES ][ QMSL_CDMA_MAX_PDM_STEPS ];

   //! Storage for Tx PDMs for each gain state.
   unsigned short aiTxLinPDM[ QMSL_CDMA_MAX_TX_GAIN_STATES ][ QMSL_CDMA_MAX_PDM_STEPS ];

   //! Max power to be achieved for each gain state if max power is to be extrapolated, Used for CDMA1x only.
   double adMaxPower[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! Min power to be achieved for each gain state if min power is to be extrapolated. Used for CDMA1x only.
   double adMinPower[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! Extrapolate maximum power or not (1 to extrapolate up to adMaxPower[i] for each gain state, 0 not to extrapolate). Used for CDMA1x only.
   unsigned char aiExtrapolatedMaxPower[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! Extraploate minimum power or not (1 to extrapolate down to adMinPower[i] for each gain state, 0 not to extrapolate). Used for CDMA1x only.
   unsigned char aiExtrapolatedMinPower[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! Storage for HDET values to be used to generate HDET vs AGC table.
   unsigned short aiTxHDET[ QMSL_CDMA_MAX_PDM_STEPS ];

   //! Flag to state if LPM HDET data is included in aiTxHDETLPM or not. Used for LTE BC13 only.
   unsigned char aiTxHDETLPMEnabled;

   //! Storage for LPM HDET values to be used to generate LPM HDET vs AGC table. Used for LTE BC13 only.
   unsigned short aiTxHDETLPM[ QMSL_CDMA_MAX_PDM_STEPS ];

   //! Number of Tx gain states for which Tx power vs PDM was measured.
   unsigned long iNumMeasuredTxGainStates;

   //! Number of Tx power vs PDM values measured for each gain state
   unsigned short iNumTxPowerMeasurementsPerGainState[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! \brief Tx measurement to NV Index mapping. The value is mapped to the index of the NV_TX_LIN_<index> item.\n
   //! For example, a 3 gain range design with aiTxMeasToNVMapping = [0, 1, 3] maps to NV_TX_LIN_0, NV_TX_LIN_1 and NV_TX_LIN_3\n
   //! aiTxLinPower[0] and aiTxLinPDM[0] generate NV_TX_LIN_0\n
   //! aiTxLinPower[1] and aiTxLinPDM[1] generate NV_TX_LIN_1\n
   //! aiTxLinPower[2] and aiTxLinPDM[2] generate NV_TX_LIN_3\n
   //! Any values in aiTxLinPower[3] and aiTxLinPDM[3] are ignored.
   unsigned short aiTxMeasToNVMapping[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! The number of elements to generate in the Tx linearizer table. Used for CDMA1x targets only. For SC2X use 48, for all other platforms use 64.
   unsigned short iTotalNVItems;

   //! \brief Tx measurement index used to generate the HDET vs AGC table\n
   //! For example, a value of 2 means that aiTxHDET and aiTxLinPower[2] are used to generate the HDET vs AGC table.
   unsigned short iTxMeasIndexUsedForHDET;

   //! Desired power level for HDET Offset calculation (usually 18 dBm)
   double HDET_SpanPower_dBm;

   //! Desired power level for HDET Span calculation (usually 26 dBm)
   double HDET_OffsetPower_dBm;

   //! Desired start power level for LPM HDET.
   double LPM_HDET_Start_Power_dBm;

   //! Desired threshold power level for LPM HDET.
   double LPM_HDET_Threshold_Power_dBm;

   //! Desired power level for LPM HDET Offset calculation. Used for LTE BC13 only.
   double LPM_HDET_SpanPower_dBm;

   //! Desired power level for LPM HDET Span calculation. Used for LTE BC13 only.
   double LPM_HDET_OffsetPower_dBm;

   //! PDM step size used for Tx sweep for each gain state
   unsigned short aiTxSweepStepSize[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! The head room PDM count for each gain state. Not used for CDMA1x. If Tx sweep start PDM + head room PDM > iUMTS_TxAGC_PDM_Max, this parameter has no effect.
   unsigned short aiHeadRoomPDMCountList[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! The PDM step size to be used for extrapolation in each gain state. Not used for CDMA1x.
   unsigned short aiExtrapolation_PDM_StepSize[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! \brief The max Tx AGC PDM used to generate the UMTS Tx linearizer table.\n
   //! For RTR6275, the value is 383.  For RTR6285, the value is 255. Not used for CDMA1x.
   unsigned short iUMTS_TxAGC_PDM_Max;

   //! The Tx AGC PDM value corresponding to minimum Tx gain.  Used to limit NV PDM index values at min during extrapolation. Not used for CDMA1x.
   unsigned short i_TxAGC_PDM_MinGain;

   //! \brief Number of NV value counts per dB \n
   //! For CDMA1x target, use 10 (i.e. 1/10 dB per count) or 100 (i.e. 1/100 dB per count)\n
   //! For UMTS target, use 10 (i.e. 1/10 dB per count) or 12 (i.e. 1/12 dB per count)\n
   //! For LTE target, use 10 (i.e. 1/10 dB per count)\n
   //! For RTR6500 target, use 100 (i.e. 1/100 dB per count)\n
   //! For RTR8600 target, use 10 (i.e. 1/10 dB per count)
   int iNV_Resolution;

   //!  Boolean to specify if TX_LIN_MASTER_0 is enhanced (64 elements) or not. Used for UMTS only. Set to 0 for CDMA1x/LTE.
   unsigned char iEnh_Linearizer_0_NV;

   //!  Boolean to specify if non-monotonic items have to be skipped. Not used for CDMA1x.
   unsigned char iSkip_NonMonotonic_Items;

   //!  Boolean to specify if lower powers are to be extrapolated or not (1 = do not extrapolate lower powers, 0 = extrapolate lower powers). Not used for CDMA1x.
   unsigned char iDo_Not_Extrapolate_Lower_Powers;

   //!  Boolean to specify whether HDET_V2 is used
   unsigned char iUse_HDET_V2;

   //! Boolean to specify whether composite HDET NV is used
   unsigned char iUse_Extended_HDET_NV;

   //! Max limit for HDET
   int iHDET_MaxLim;

   //! Sort NV by PDM or Power (0 = Sort NV by Power, 1 = Sort NV by PDM)
   int iSortNVTxLin;

   //! Sorting order (0 = descending, 1 = ascending)
   int iSortingOrder;

   //! Primary == 0, SV Path(C2) == 1
   unsigned short iTxPath;

   //! Boolean to specify if V2 Tx NVs should be written to or not
   unsigned char iWrite_To_V2_Tx_NV;
} QMSL_CDMA_TxLin_BetaScaling_struct;

/**
Definition of a CDMA Tx Linearizer table
*/
typedef struct
{
   //! Tx Linearizer master offset
   short            iMasterOffset;

   //! Tx Linearizer slope table
   unsigned char    aiSlope[QMSL_NV_MANAGER_CDMA_TX_LIN_TABLE_SLOPE_SIZE];

   //! Tx Linearizer power levels used to generate NV item
   double           adTxLinPowerLevel [QMSL_NV_MANAGER_CDMA_TX_LIN_TABLE_SLOPE_SIZE + 1];

   //! PDMs correponding to power levels in adTxLinPowerLevel
   unsigned short   aiPDM [QMSL_NV_MANAGER_CDMA_TX_LIN_TABLE_SLOPE_SIZE + 1];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_CDMA_TxLin_NV_struct;

/**
Definition of a WCDMA Tx Linearizer table (3U platform)
*/
typedef struct
{
   //! PDMs correponding to power levels in adTxLinPowerLevel
   unsigned short   aiPDM[QMSL_NV_MANAGER_WCDMA_TX_LIN_TABLE_SIZE];

   //! Tx Linearizer power levels used to generate NV item
   double   adTxLinPowerLevel[QMSL_NV_MANAGER_WCDMA_TX_LIN_TABLE_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_WCDMA_TxLin_NV_struct;

/**
Definition of a Tx Linearizer table(UMTS)
*/
typedef struct
{
   //! Tx Lin PDM table
   unsigned short   aiPDM[QMSL_NV_MANAGER_WCDMA_ENH_BETA_SCALING_NV_SIZE];

   //! The PDM table NV item
   QMSL_RFCAL_NV_Item oPDMNVItem;

   //! Tx Lin power table
   unsigned short aiPower[QMSL_NV_MANAGER_WCDMA_ENH_BETA_SCALING_NV_SIZE];

   //! The power table NV item
   QMSL_RFCAL_NV_Item oPowerNVItem;

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_WCDMA_TxLin_BetaScaling_NV_struct;

/**
Definition of a Tx Linearizer table(LTE)
*/
typedef struct
{
   //! Tx Lin Gain Index table
   unsigned short   aiGainIndex[QMSL_NV_MANAGER_LTE_BETA_SCALING_NV_SIZE];

   //! The Gain Index table NV item
   QMSL_RFCAL_NV_Item oGainIndexNVItem;

   //! Tx Lin power table
   unsigned short aiPower[QMSL_NV_MANAGER_LTE_BETA_SCALING_NV_SIZE];

   //! The power table NV item
   QMSL_RFCAL_NV_Item oPowerNVItem;

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_LTE_TxLin_BetaScaling_NV_struct;

/**
Definition of a Tx Linearizer table (1x)
*/
typedef struct
{
   //! Tx Lin PDM table
   unsigned short   aiPDM[QMSL_NV_MANAGER_CDMA_BETA_SCALING_NV_SIZE];

   //! The PDM table NV item
   QMSL_RFCAL_NV_Item oPDMNVItem;

   //! Tx Lin power table
   short aiPower[QMSL_NV_MANAGER_CDMA_BETA_SCALING_NV_SIZE];

   //! The power table NV item
   QMSL_RFCAL_NV_Item oPowerNVItem;

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_CDMA_TxLin_BetaScaling_NV_struct;

/**
Definition of a Tx Linearizer table
*/

typedef struct
{
   //! Tx Lin table
   unsigned short   aiPDM[QMSL_NV_MANAGER_CDMA_TX_LIN_RTR6500_TABLE_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oPDMNVItem;

   short aiPower[QMSL_NV_MANAGER_CDMA_TX_LIN_RTR6500_TABLE_SIZE];

   QMSL_RFCAL_NV_Item oPowerNVItem;

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_CDMA_TxLin_RTR6500_NV_struct;

/**
Definition of HDET offset generated by QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! HDET offset
   unsigned short   iHDET_offset;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
}  QMSL_CDMA_HDET_OFFSET_NV_struct;

/**
Definition of HDET span generated by QMSL RF Calibration Data Manager
*/

typedef struct
{
   //! HDET offset
   unsigned short   iHDET_span;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
}  QMSL_CDMA_HDET_SPAN_NV_struct;

/**
Definition of LTE HDET offset and span NV item generated by QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! HDET offset
   unsigned short   iHDET_offset_span[2];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
}  QMSL_LTE_HDET_OFFSET_SPAN_NV_struct;

/**
Definition of HDET vs AGC table generated by QMSL RF Calibration Data Manager
*/

typedef struct
{
   //! HDET vs AGC table
   unsigned short           aHDET_vs_AGC[QMSL_NV_MANAGER_HDET_VS_AGC_NV_SIZE];

   //! Tx Power Level(dBm) used to generate HDET vs AGC
   double                   adTxPowerLevel[QMSL_NV_MANAGER_HDET_VS_AGC_NV_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_CDMA_HDET_VS_AGC_NV_struct;

/**
Definition of LPM HDET vs AGC table generated by QMSL RF Calibration Data Manager
*/

typedef struct
{
   //! LPM HDET Start Power
   unsigned short           iLPM_HDET_START_Power;

   //! LPM HDET vs AGC table
   unsigned short           aLPM_HDET_vs_AGC[QMSL_NV_MANAGER_HDET_VS_AGC_NV_SIZE];

   //! Tx Power Level(dBm) used to generate LPM HDET vs AGC
   double                   adTxPowerLevel[QMSL_NV_MANAGER_HDET_VS_AGC_NV_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_CDMA_LPM_HDET_VS_AGC_V2_NV_struct;

/**
Definition of composite LPM HDET data generated by QMSL RF Calibration Data Manager
*/

typedef struct
{
   //! Enable LPM HDET
   unsigned char        iEnable;

   //! LPM HDET Offset
   unsigned short       iLPM_HDET_Offset;

   //! LPM HDET Span
   unsigned short       iLPM_HDET_Span;

   //! LPM HDET Threshold
   unsigned short       iLPM_HDET_Threshold;

   //! LPM HDET vs AGC table
   unsigned short           aLPM_HDET_vs_AGC[QMSL_NV_MANAGER_HDET_VS_AGC_NV_SIZE];

   //! Tx Power Level(dBm) used to generate LPM HDET vs AGC
   double                   adTxPowerLevel[QMSL_NV_MANAGER_HDET_VS_AGC_NV_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item   oNVitem;
} QMSL_CDMA_LPM_HDET_VS_AGC_V3_NV_struct;

/**
Definition of Tx Linearizer, HDET spand and offset, HDET vs AGC tables generated by QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! 1x target Tx Linearizer
   QMSL_CDMA_TxLin_NV_struct    aTx_GainState[QMSL_CDMA_MAX_TX_GAIN_STATES];

   //! HDET vs AGC
   QMSL_CDMA_HDET_VS_AGC_NV_struct aHDET_vs_AGC;

   //! LPM HDET vs AGC
   QMSL_CDMA_HDET_VS_AGC_NV_struct aLPM_HDET_vs_AGC;

   //! HDET offset
   QMSL_CDMA_HDET_OFFSET_NV_struct  aHDET_offset;

   //! HDET span
   QMSL_CDMA_HDET_SPAN_NV_struct    aHDET_span;

   //! LTE HDET Offset and Span
   QMSL_LTE_HDET_OFFSET_SPAN_NV_struct aHDET_offset_span;

   //! UMTS target Tx Linearizer
   QMSL_WCDMA_TxLin_NV_struct   aWCDMA_Tx_GainState[QMSL_CDMA_MAX_TX_GAIN_STATES];
} QMSL_CDMA_TxLin_Cal_Result_struct;

/**
Definition of Tx Linearizer, HDET spand and offset, HDET vs AGC tables generated by QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! 1x Linearizer table
   QMSL_CDMA_TxLin_BetaScaling_NV_struct aTx_GainState[QMSL_CDMA_MAX_TX_GAIN_STATES];

   //! UMTS Linearizer table
   QMSL_WCDMA_TxLin_BetaScaling_NV_struct   aWCDMA_TxLin[QMSL_CDMA_MAX_TX_GAIN_STATES];

   //! LTE Linearizer table
   QMSL_LTE_TxLin_BetaScaling_NV_struct  aLTE_TxLin[QMSL_CDMA_MAX_TX_GAIN_STATES];

   //! HDET vs Tx AGC
   QMSL_CDMA_HDET_VS_AGC_NV_struct aHDET_vs_AGC;

   //! LPM HDET vs AGC
   QMSL_CDMA_HDET_VS_AGC_NV_struct aLPM_HDET_vs_AGC;

   //! LPM HDET vs AGC V2
   QMSL_CDMA_LPM_HDET_VS_AGC_V2_NV_struct aLPM_HDET_vs_AGC_V2;

   //! LPM HDET vs AGC V3
   QMSL_CDMA_LPM_HDET_VS_AGC_V3_NV_struct aLPM_HDET_vs_AGC_V3;

   //! HDET offset
   QMSL_CDMA_HDET_OFFSET_NV_struct  aHDET_offset;

   //! HDET span
   QMSL_CDMA_HDET_SPAN_NV_struct    aHDET_span;

   //! LPM HDET offset
   QMSL_CDMA_HDET_OFFSET_NV_struct  aLPM_HDET_offset;

   //! LPM HDET span
   QMSL_CDMA_HDET_SPAN_NV_struct    aLPM_HDET_span;

   //! LTE HDET Offset and Span
   QMSL_LTE_HDET_OFFSET_SPAN_NV_struct aHDET_offset_span;
} QMSL_CDMA_TxLin_BetaScaling_Result_struct;

/**
Definition of Tx Linearizer (RTR6500), HDET spand and offset, HDET vs AGC tables generated by QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! Tx Linearizer (RTR6500)
   QMSL_CDMA_TxLin_RTR6500_NV_struct    aTx_GainState[QMSL_CDMA_MAX_TX_GAIN_STATES];

   //! HDET vs AGC
   QMSL_CDMA_HDET_VS_AGC_NV_struct aHDET_vs_AGC;

   //! HDET offset
   QMSL_CDMA_HDET_OFFSET_NV_struct  aHDET_offset;

   //! HDET span
   QMSL_CDMA_HDET_SPAN_NV_struct    aHDET_span;
} QMSL_CDMA_TxLin_RTR6500_Result_struct;

/**
Defintion of one band of cdma2000/WCDMA/LTE Tx Linearizer vs Frequency measurement structure,
for use with the QMSL RF Calibration Data manager functions
*/
typedef struct
{
   //! Storage of Tx linearizer vs frequency measurement data in dBm
   double aiTxMeasuredPower[ QMSL_CDMA_MAX_TX_GAIN_STATES ][ QMSL_CDMA_MAX_CHANNELS ];

   //! \brief Tx measurement to NV Index mapping. The value is mapped to the index of the NV_TX_COMP_<index> item.\n
   //! For example, a 3 gain range design with aiTxMeasToNVMapping = [0, 1, 3] maps to NV_TX_COMP_0, NV_TX_COMP_1 and NV_TX_COMP_3\n
   //! aiTxMeasuredPower[0][] is used to generate NV_TX_COMP_0\n
   //! aiTxMeasuredPower[1][] is used to generate NV_TX_COMP_1\n
   //! aiTxMeasuredPower[2][] is used to generate NV_TX_COMP_3\n
   //! Any values in aiTxMeasuredPower[3] are ignored.
   unsigned short aiTxMeasToNVMapping[ QMSL_CDMA_MAX_TX_GAIN_STATES];

   //! Number of Tx gain states measured
   unsigned short iNumMeasuredTxGainStates;

   //! \brief Flag indicating what type of Tx frequency compensation data is included.\n
   //! 0 = only primary Tx freq comp data\n
   //! 1 = both primary and secondary Tx freq comp data\n
   //! See 80-V4341-84 'WCDMA Secondary Tx Comp vs Freq for RTR6285/RTR6280'.
   unsigned short iTxCompType;

   //! \brief Secondary frequency compensation may or may not be performed for all Tx gain states.\n
   //! This item indicates which Tx gain states have secondary frequency compensation measurements.\n
   //! Use 0 to indicate no secondary frequency compensation measurements for the corresponding gain state.\n
   //! Use 1 to indicate there are secondary frequency compensation measurements for the corresponding gain state.\n
   //! This array must be populated when iTxCompType = 1.
   unsigned short a2ndTxCompHasMeas[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! \brief The PDM value used to generate the secondary Tx frequency compensation table.\n
   //! Used by WCDMA Secondary Tx Comp vs Freq for RTR6285/RTR6280 (See 80-V4341-84).
   unsigned short a2ndTxCompPDM[ QMSL_CDMA_MAX_TX_GAIN_STATES ];

   //! \brief Storage of Tx power in dBm for secondary freq comp PDM.\n
   //! Used by WCDMA Secondary Tx Comp vs Freq for RTR6285/RTR6280 (See sec_comp_meas in 80-V4341-84).
   double aiTx_sec_comp_meas[ QMSL_CDMA_MAX_TX_GAIN_STATES ] [ QMSL_CDMA_MAX_CHANNELS ];

   //! \brief Storage of Tx power in dBm for secondary freq comp PDM + 1.\n
   //! Used by WCDMA Secondary Tx Comp vs Freq for RTR6285/RTR6280 (See sec_comp_meas_next in 80-V4341-84).
   double aiTx_sec_comp_meas_next[ QMSL_CDMA_MAX_TX_GAIN_STATES ] [ QMSL_CDMA_MAX_CHANNELS ];

   //! \brief Overrwrite the static component for C2K Tx power vs comp NV item with zero
   // For cdma2000 Tx PWR COMP (see NV_BCy_TX_PWR_COMPn in 80-VP447-13), there is a static component
   // Prior to QMSL 5.3.38. the static component is always overwritten with 0
   // Setting this to  1 will force QMSL to read the static component from NV and reapply the static component.  This will trigger a NV_READ from mobile
   // Setting this to  0 will fource QMSL to read and use 0 for the static component

   unsigned char bC2K_Not_Overwrite_Tx_Pwr_Comp_Static_Component_With_Zero;
} QMSL_CDMA_TxLinVsFreq_struct;

/**
Definition of Tx COMP table generaed by QMSL RF Calibraiton Data Manager
*/
typedef struct
{
   //! Tx Comp Value offset
   char aiTxCompValue[QMSL_CDMA_MAX_CHANNELS];

   //! Indicate that this item has valid data
   int  iHasValidData;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_CDMA_Tx_LinVsFreq_NV_struct;

/**
Definition of Tx COMP table generaed by QMSL RF Calibraiton Data Manager
*/
typedef struct
{
   //! Tx Comp Value offset
   char aiTxCompValue[128];

   //! Indicate that this item has valid data
   int  iHasValidData;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_LTE_Tx_LinVsFreq_NV_struct;

/**
Definition of Tx COMP tables generaed by QMSL RF Calibraiton Data Manager
*/
typedef struct
{
   //! Array of Tx Frequency compensation result
   QMSL_CDMA_Tx_LinVsFreq_NV_struct aTx_FreqComp [QMSL_CDMA_MAX_TX_GAIN_STATES];

   //! Array of Tx 2nd Frequency compensation result
   QMSL_CDMA_Tx_LinVsFreq_NV_struct aTx_2ndFreqComp [QMSL_CDMA_MAX_TX_GAIN_STATES];

   //! Array of Tx Frequency compensation result
   QMSL_LTE_Tx_LinVsFreq_NV_struct  aTx_LTEFreqComp;

   //! NV_<band>_TX_COMP_VS_FREQ_SEC_PDM_LIST
   QMSL_RFCAL_NV_Item                   oTx_Comp_Vs_Freq_Sec_PDM_List;
} QMSL_CDMA_Tx_LinVsFreq_Cal_NV_Result_struct;

/**
Definition of the reference channel Tx power vs HDET measurement data.  The reference channel data is
used by LIM vs FREQ calculation.

Note that the data needs to be sorted from high to lower power

i.e.  aiTxMeasuredPower[0] = highest power, aiTxMeasuredHDET[0] = HDET at the highest power, aiTxAGC[0] = Tx AGC at the highest power\n
aiTxMeasuredPower[1] = 2nd highest power, aiTxMeasuredHDET[1] = HDET at the 2nd highest power, aiTxAGC[1] = Tx AGC at the 2nd highest power
*/
typedef struct
{
   //! Measured HDET values
   int aiTxMeasuredHDET [QMSL_CDMA_MAX_PDM_STEPS];

   //! Measured power in dBm
   double aiTxMeasuredPower [QMSL_CDMA_MAX_PDM_STEPS];

   //! Tx AGC values used for the measurements
   double aiTxAGC [QMSL_CDMA_MAX_PDM_STEPS];

   //! Number of measurements.  Must be less than QMSL_CDMA_MAX_PDM_STEPS.
   int iNumMeasurement;
} QMSL_CDMA_TxLimVsFreq_RefChan_Measurement_struct;

/**
Definition of one band of cdma2000/WCDMA/LTE Tx Limit vs Frequency measurement structure,
for use with the QMSL RF Calibration Data manager functions
*/
typedef struct
{
   //! Tx AGC (PDM) values used during LIM vs FREQ calibration
   short    aiTxMeasuredPDM[ QMSL_CDMA_MAX_CHANNELS][ QMSL_CDMA_MAX_TX_LIM_MEASUREMENTS ];

   //! Tx powers (in dBm) measured during LIM vs FREQ calibration
   double aiTxMeasuredPower[ QMSL_CDMA_MAX_CHANNELS ][ QMSL_CDMA_MAX_TX_LIM_MEASUREMENTS ];

   //! HDET values measured during LIM vs FREQ calibration
   unsigned int  aiTxMeasuredHDET[ QMSL_CDMA_MAX_CHANNELS][ QMSL_CDMA_MAX_TX_LIM_MEASUREMENTS ];

   //! Number of Tx measurements (Tx AGC, Power, HDET) at each channel
   int iNumOfTxLimMeasurement [QMSL_CDMA_MAX_CHANNELS];

   QMSL_CDMA_TxLimVsFreq_RefChan_Measurement_struct oRefChMeas;
} QMSL_CDMA_TxLimVsFreq_struct;

/**
Definition of CDMA Tx LIM vs FREQ data generated by QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! LIM vs FREQ NV item
   char         aiLimVsFreq[QMSL_CDMA_MAX_CHANNELS];

   //! The Tx output power at reference HDET at each channel.  The reference HDET is HDET measured at Max power at reference channel
   double           adTxMaxPower[QMSL_CDMA_MAX_CHANNELS];

   //! The expected Tx PDM (AGC) at desired max power
   short            aiExpectedTxAGCatMaxPower[QMSL_CDMA_MAX_CHANNELS];

   //! The expected HDET at desired max power
   short            aiExpectedHDETatMaxPower[QMSL_CDMA_MAX_CHANNELS];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_CDMA_Tx_LimVsFreq_NV_struct;

/**
Defintion of one band of cdma2000/WCDMA/LTE Tx or Rx channels structure,
for use with the QMSL RF Calibration Data manager functions
*/
typedef struct
{
   //! Channel numbers used for measurements
   unsigned short aiMeasuredChannels[ QMSL_CDMA_MAX_CHANNELS ];

   //! Number of channels measured
   unsigned long iNumMeasuredChannels;

   //! Reference channel
   unsigned short iRefChannel;
} QMSL_CDMA_MeasuredChannels_struct;

/**
Definition of the list of channels to genreate NV
*/
typedef struct
{
   //! Channel numbers used for generating NV
   unsigned short aiNVChannels[ QMSL_CDMA_MAX_CHANNELS ];
} QMSL_CDMA_NVChannels_struct;

/**
Definition of Intellieceiver calibration item
*/
typedef struct
{
   //! The array to hold intelliceiver calibration value
   unsigned char aiIntelliceiverValue [QMSL_CDMA_INTELLICEIVER_VALUE_ARRAY];

   //! actual size of aiIntelliceiverValue
   int            iSizeOfIntelliceiverValue;
} QMSL_CDMA_Intelliceiver_Value;

/**
Definition of GSM Tx RSB calibration result
*/
typedef struct
{
   //! RSB calibration optimal alpha value
   unsigned char A_value;

   //! RSB calibration optimal beta value
   unsigned char B_value;
}  QMSL_GSM_Tx_RSB_struct;

//! Max number of GSM Rx LNA gain range calibration
#define QMSL_GSM_RX_GAIN_RANGE 5

#define QMSL_GSM_RX_GAIN_RANGE_CONSOLIDATED 8

//! Max number of channels used for GSM Rx LNA gain range calibration.
//! For GSM 850/900, the number of calibration channel is 8.
//! For GSM 1800(DCS)/1900(PCS), the number of calibration channel is 16.
#define QMSL_GSM_RX_GAIN_RANGE_CHANNELS 16

/**
Definition of GSM gain range calibration measurement data for use with QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! A two dimensional array to hold GSM gain range calibraion value.  The first index is index of gain range.  The second index is index of channel
   unsigned long aiRSSIValue[QMSL_GSM_RX_GAIN_RANGE][QMSL_GSM_RX_GAIN_RANGE_CHANNELS];

   //! The calibration power levels (in dBm) used for each gain range in aiRSSIValue
   double aiCalibrationPwr[QMSL_GSM_RX_GAIN_RANGE];

   //! Number of valid gain range in aiRSSIValue
   unsigned long iNumRxGainRange;

   //! \brief Number of calibration channels\n
   //! For GSM 850/900, the number of calibration channel is 8.\n
   //! For GSM 1800(DCS)/1900(PCS), the number of calibration channel is 16.
   unsigned long iNumChannel;
}  QMSL_GSM_Rx_Gain_Range_struct;

/**
Definition of GSM gain range calibration NV results generated by QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! Number of valid gain range in aiRSSIValue
   unsigned long iNumRxGainRange;

   //! The RSSI Value
   unsigned short aiRSSI_NV_Value[QMSL_GSM_RX_GAIN_RANGE][QMSL_GSM_RX_GAIN_RANGE_CHANNELS];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem[QMSL_GSM_RX_GAIN_RANGE];
}  QMSL_GSM_Rx_Gain_Range_NV_struct;

/**
Definition of GSM gain range calibration measurement data for use with QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! Chain ID - C0=0, C2=2 etc
   unsigned char iChainId;

   //! This is the NV container for which to write the Rx NV data.
   //! For example, Rx NV data for chainID C0 can be written to NV container C3 (Cx).
   unsigned char iNvContainer;

   //! \brief Number of calibration channels\n
   //! For GSM 850/900, the number of calibration channel is 8.\n
   //! For GSM 1800(DCS)/1900(PCS), the number of calibration channel is 16.
   unsigned long iNumChannel; //find where this is populated

   //! List of channels used in calibration
   unsigned short aiChannelList[QMSL_GSM_RX_GAIN_RANGE_CHANNELS];

   //! Number of valid gain range in aiRSSIValue
   unsigned long iNumRxGainRange; //find where this is populated

   //! The calibration power levels (in dBm) used for each gain range in aiRSSIValue
   double aiCalibrationPwr[QMSL_GSM_RX_GAIN_RANGE];

   //! A two dimensional array to hold GSM gain range calibraion value.  The first index is index of gain range.  The second index is index of channel
   unsigned long aiRSSIValue[QMSL_GSM_RX_GAIN_RANGE][QMSL_GSM_RX_GAIN_RANGE_CHANNELS];
}  QMSL_GSM_Rx_Calibration_Params_and_Meas;

typedef struct QMSL_GSM_Rx_Calibration_Params_and_Meas_Consolidated
{
   //! Antenna Path
   unsigned short iAntennaPath;

   //! Chain ID - C0=0, C2=2 etc
   unsigned char iChainId;

   unsigned short  iCaltype;

   unsigned short iRFMDevice; //added recently
   //! This is the NV container for which to write the Rx NV data.
   //! For example, Rx NV data for chainID C0 can be written to NV container C3 (Cx).
   unsigned short iNvContainer;

   //! \brief Number of calibration channels\n
   //! For GSM 850/900, the number of calibration channel is 8.\n
   //! For GSM 1800(DCS)/1900(PCS), the number of calibration channel is 16.
   unsigned long iNumChannel;

   //! List of channels used in calibration
   unsigned short aiChannelList[QMSL_GSM_RX_GAIN_RANGE_CHANNELS];

   //! Number of valid gain range in aiRSSIValue
   unsigned long iNumRxGainRange;

   //! The calibration power levels (in dBm) used for each gain range in aiRSSIValue
   double aiCalibrationPwr[QMSL_GSM_RX_GAIN_RANGE];

   //! A two dimensional array to hold GSM gain range calibraion value.  The first index is index of gain range.  The second index is index of channel
   unsigned long aiRSSIValue[QMSL_GSM_RX_GAIN_RANGE_CONSOLIDATED][QMSL_GSM_RX_GAIN_RANGE_CHANNELS];


} QMSL_GSM_Rx_Calibration_Params_and_Meas_Consolidated;


/**
Definition of GSM gain range calibration + Channels NV results
generated by QMSL RF Calibration Data Manager
*/
typedef struct QMSL_GSM_Rx_Gain_Channels_NV_Rev0_Struct
{
   //Number of valid entries in channel list that has freq comp data (8 for low bands, 16 for high bands)
   unsigned char  iChannelListSize;

   // Rx calibrated channel list , capped at 16
   unsigned short aiChannelList[QMSL_GSM_RX_GAIN_RANGE_CHANNELS];

   //Rx FREQ comp data for all LNA states
   short aiGSM_Rx_Gain_NV_Value[QMSL_GSM_RX_GAIN_RANGE][QMSL_GSM_RX_GAIN_RANGE_CHANNELS];
} QMSL_GSM_Rx_Gain_Channels_NV_Rev0_Type;

typedef struct QMSL_GSM_Rx_Gain_Channels_NV_Container
{
   QMSL_GSM_Rx_Gain_Channels_NV_Rev0_Type nvRev0;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_Rx_Calibration_NV;

/**
Definition of GSM IM2 calibration results for use with QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! An array to hold the calibration channels
   unsigned short aiChannel[QMSL_NV_MANAGER_GSM_IM2_CAL_MAX_SIZE];

   //! An array to hold IM2 I values across the calibration channels
   unsigned char aIM2_I[QMSL_NV_MANAGER_GSM_IM2_CAL_MAX_SIZE];

   //! An array to hold IM2 Q values across the calibration channels
   unsigned char aIM2_Q[QMSL_NV_MANAGER_GSM_IM2_CAL_MAX_SIZE];

   //! IM2 Transconductance values across the calibration channels
   unsigned char aIM2_Transconductance;
}  QMSL_GSM_IM2_struct;

/**
A struct to hold individual polar calibration sweep record
*/
typedef struct
{
   //! The DAC value
   long dac;

   //! Duration count
   long duration_counts;

   //! Amplitude in dBm
   double   amp_dBm;

   //! Phase in Radian
   double   phase_rad;
} QMSL_GSM_Polar_Cal_SweepRecord;

/**
Definition of GSM Tx Polar Calibration channel
*/
typedef enum QMSL_GSM_Polar_Cal_Frequency
{
   //! NV items generated will be mapped to F1
   QMSL_POLAR_CAL_F1_CHANNEL = 1,

   //! NV items generated will be mapped to F2
   QMSL_POLAR_CAL_F2_CHANNEL = 2,

   //! NV items generated will be mapped to F3
   QMSL_POLAR_CAL_F3_CHANNEL = 3
} QMSL_GSM_Polar_Cal_Frequency;

/**
Definition of GSM Tx Polar Calibration for use with QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! Polar calibration sweep record
   QMSL_GSM_Polar_Cal_SweepRecord aPolar_Cal_Sweep_Result[QMSL_NV_MANAGER_POLAR_CAL_RAW_DATA_MAX_SIZE];

   //! Number of valid polar calibration sweep record in aPolar_Cal_Sweep_Result
   int iNumOfPoloarCalSweepRecord;
} QMSL_GSM_Polar_Cal_Measurement;

/**
Definition of GSM Tx Polar Calibration for use with QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! Polar calibration sweep record
   QMSL_GSM_Polar_Cal_SweepRecord aPolar_Cal_Sweep_Result[QMSL_NV_MANAGER_POLAR_CAL_RAW_DATA_MAX_SIZE];

   //! Number of valid polar calibration sweep record in aPolar_Cal_Sweep_Result
   int iNumOfPoloarCalSweepRecord;

   //! Smoothing Window Size in dB
   double   dSmoothingWindowSize;

   //! Calibration channel number
   unsigned short   iChannel;

   //! The generated NV items mapping.  Enumeration of QMSL_GSM_Polar_Cal_Frequency.
   QMSL_GSM_Polar_Cal_Frequency iFreqnecyLocation;

   //!  The maximum power (in dBm)
   double           dNVMaxPower;

   //! The minimum power (in dBm)
   double           dNVMinPower;
} QMSL_GSM_Polar_Cal_Result;

typedef struct
{
   //! The NV Container to Use
   unsigned char iTxNvContainer;
   //! The signal path
   unsigned char iTxSigPath;

   //! Calibration channel number
   unsigned short   iChannel[ QMSL_GSM_MAX_TX_CAL_CHANNELS ];

   //! The generated NV items mapping.  Enumeration of QMSL_GSM_Polar_Cal_Frequency.
   QMSL_GSM_Polar_Cal_Frequency iFreqMapping[ QMSL_GSM_MAX_TX_CAL_CHANNELS ];

   //! Storage for GSM mode Tx power (dBm) for each gain range
   double aiGSMTxPowerMeas[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][ QMSL_GSM_MAX_TX_GAIN_STATES ][ QMSL_GSM_MAX_RGI_STEPS ];

   //! Storage for EDGE mode Tx power (dBm) for each gain range
   double aiEDGETxPowerMeas[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][ QMSL_GSM_MAX_TX_GAIN_STATES ][ QMSL_GSM_MAX_RGI_STEPS ];

   //! Storage for GSM mode Tx RGI for each gain range
   unsigned short aiGSMTxRGI[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][ QMSL_GSM_MAX_TX_GAIN_STATES ][ QMSL_GSM_MAX_RGI_STEPS ];

   //! Storage for EDGE mode Tx RGI for each gain range
   unsigned short aiEDGETxRGI[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][ QMSL_GSM_MAX_TX_GAIN_STATES ][ QMSL_GSM_MAX_RGI_STEPS ];

   //! Number of channels measured
   unsigned long iNumChannels;

   //! Number of Tx gain indices measured
   unsigned long iNumMeasuredTxGainStates;

   //! Number of Tx power vs RGI values measured for each gain state
   unsigned short iNumTxPowerMeasurementsPerRange;

   //! Saturation Detection Window in dB
   double iSaturationDetectionWindow;

   //! Tx Measurement to NV Index mapping. The value is mapped to the gain (G) index of RGI and PMEAS items
   unsigned short aiTxMeasToNVMapping[ QMSL_GSM_MAX_TX_GAIN_STATES];
} QMSL_GSM_DA_Cal_Result;

typedef struct
{
   //! Calibration channel for this measurement
   unsigned short chan;

   //! Frequency mapping for this channel (?)
   QMSL_GSM_Polar_Cal_Frequency freqMapping;

   //! PA value for this measurement
   unsigned short pa;

   //! RGI value for this measurement
   unsigned short rgi;

   //! Power measured at this channel, PA value, and RGI
   double power;
} QMSL_DA_Measurement;

/**
Definition of a Tx RGI vs PMEAS
*/

typedef struct
{
   //! Tx Lin PDM table
   unsigned char    aiRGI[QMSL_GSM_MAX_RGI_STEPS];

   //! The PDM table NV item
   QMSL_RFCAL_NV_Item oRGINVItem;

   //! Tx Lin power table
   short aiPower[QMSL_GSM_MAX_RGI_STEPS];

   //! The power table NV item
   QMSL_RFCAL_NV_Item oPowerNVItem;
} QMSL_GSM_RGI_PMeas_NV_struct;

typedef struct
{
   //! RGI PMEAS Struct
   QMSL_GSM_RGI_PMeas_NV_struct aEDGERgiPmeasNV[QMSL_GSM_MAX_TX_GAIN_STATES];

   //! RGI PMEAS Struct
   QMSL_GSM_RGI_PMeas_NV_struct aGSMRgiPmeasNV[QMSL_GSM_MAX_TX_GAIN_STATES];

   //! DA Cal Channel value
   unsigned short   iChannel;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oChanNVitem;
} QMSL_GSM_DA_Cal_NV_struct;

typedef struct
{
   //! RGI PMEAS Struct
   QMSL_GSM_DA_Cal_NV_struct aDaCalChanNV[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_GSM_DA_Cal_NV_Chan_struct;

/**
Definition of a Tx RGI vs PMEAS v2
(channel, power, and RGI values are embedded into structure
instead of having to reference an external table)
*/

typedef struct
{
   //! Tx Lin PDM table
   unsigned char    aiRGI[QMSL_GSM_MAX_RGI_STEPS];

   //! The PDM table NV item
   QMSL_RFCAL_NV_Item oRGINVItem;

   //! Tx Lin power table
   short aiPower[QMSL_GSM_MAX_RGI_STEPS];

   //! The power table NV item
   QMSL_RFCAL_NV_Item oPowerNVItem;

   //! DA Cal PA value
   unsigned short iPaVal;
} QMSL_GSM_RGI_PMeas_NV_struct_v2;

typedef struct
{
   //! RGI PMEAS Struct
   QMSL_GSM_RGI_PMeas_NV_struct_v2 aEDGERgiPmeasNV[QMSL_GSM_MAX_TX_GAIN_STATES];

   //! Number of RGI PMEAS structs in use for EDGE
   unsigned short numEDGEStructs;

   //! RGI PMEAS Struct
   QMSL_GSM_RGI_PMeas_NV_struct_v2 aGSMRgiPmeasNV[QMSL_GSM_MAX_TX_GAIN_STATES];

   //! Number of RGI PMEAS structs in use for GSM
   unsigned short numGSMStructs;

   //! DA Cal Channel value
   unsigned short   iChannel;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oChanNVitem;
} QMSL_GSM_DA_Cal_NV_struct_v2;

typedef struct
{
   //! RGI PMEAS Struct
   QMSL_GSM_DA_Cal_NV_struct_v2 aDaCalChanNV[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   // Number of channel structs in use
   unsigned short numChanStructs;

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_GSM_DA_Cal_NV_Chan_struct_v2;

/**
Tx Cx Nv Items
*/

typedef struct QMSL_GSM_TX_PWR_ERR_List_Variant_Struct
{
   unsigned char mod;                                  // 0 = GMSK, 1 = 8PSK
   unsigned char channel_index;                        // the channel number
   signed short  pwr_err_list[QMSL_GSM_MAX_PCL_STEPS]; // list of PCL power errors
} QMSL_GSM_TX_PWR_ERR_List_Variant_Type;

//This holds the RGI List - two per pa(g,e) - size = 37 bytes
//iVariantHeader should be initialized by constructor (or) be static const - but memcpy doesnt seem to pick it up
#define QMSL_GSM_RGI_PYLD_SIZE    37
typedef struct QMSL_GSM_RGI_List_Variant_Struct
{
   unsigned short iVariantHeader;
   unsigned char iModulationType;     /*0 = GMSK, 1 = 8PSK*/
   unsigned char iPaState;
   unsigned char iNumValidRGI;
   unsigned char aRgiList[QMSL_GSM_MAX_RGI_STEPS];
} QMSL_GSM_RGI_List_Variant_Type;

//This holds the PMEAS List - two per channel/pa(g,e) - size = 69 bytes
#define QMSL_GSM_PMEAS_PYLD_SIZE    69
typedef struct QMSL_GSM_PMEAS_List_Variant_Struct
{
   unsigned short iVariantHeader;
   unsigned char iModulationType;     /*0 = GMSK, 1 = 8PSK*/
   unsigned char iChannelIndex;
   unsigned char iPaState;
   short aPmeasList[QMSL_GSM_MAX_RGI_STEPS];
} QMSL_GSM_PMEAS_List_Variant_Type;

//This holds one DPD Table - AMAM - two/channel - size = 260
#define QMSL_GSM_DPD_AMAM_PYLD_SIZE    260
typedef struct QMSL_GSM_DPD_AMAM_List_Variant_Struct
{
   unsigned short iVariantHeader;
   unsigned char iTableType; // AMAM or AMPM
   unsigned char iChannelIndex;
   unsigned short aDpdTable[QMSL_NV_MANAGER_EDGE_DPD_TABLE_SIZE];
} QMSL_GSM_DPD_AMAM_List_Variant_Type;

//This holds one DPD Table - AMPM - two/channel - size = 260
#define QMSL_GSM_DPD_AMPM_PYLD_SIZE    260
typedef struct QMSL_GSM_DPD_AMPM_List_Variant_Struct
{
   unsigned short iVariantHeader;
   unsigned char iTableType; // AMAM or AMPM
   unsigned char iChannelIndex;
   short aDpdTable[QMSL_NV_MANAGER_EDGE_DPD_TABLE_SIZE];
} QMSL_GSM_DPD_AMPM_List_Variant_Type;

//This holds one Pwr Error / PCL table - size = 36
// refer to iModulationType in QMSL_GSM_PwrErr_Per_PCL_List_Variant_Type
#define QMSL_GSM_PwrErr_Per_PCL_GMSK_Type    0
#define QMSL_GSM_PwrErr_Per_PCL_8PSK_Type    1
#define QMSL_GSM_PwrErr_PCL_PYLD_SIZE        36
typedef struct QMSL_GSM_PwrErr_Per_PCL_List_Variant_Struct
{
   unsigned short iVariantHeader;
   unsigned char iModulationType;     /*0 = GMSK, 1 = 8PSK*/
   unsigned char iChannelIndex;
   short aPwrErrPerPcl[QMSL_GSM_MAX_PCL_LIST_SIZE];
} QMSL_GSM_PwrErr_Per_PCL_List_Variant_Type;

typedef struct QMSL_Variant_Marker_Struct
{
   unsigned short iVersion;
   unsigned short iNumElements;
} QMSL_Variant_Marker_Type;

typedef struct QMSL_GSM_Tx_Cal_NV_Header_Struct
{
   unsigned char iChannelListSize;
   unsigned short iChannelList[QMSL_GSM_MAX_TX_CAL_CHANNELS];
   short iamamMaxPowerDbm100;
   unsigned char iPredistortionRgi;
} QMSL_GSM_Tx_Cal_NV_Header_Type;

// This represents the ultimat maximum size, which will typically not be meet,
// since a max of 3 PA states is typically used.
// size = 3ch*((4pa * 2mod *69 pmeas) + (2*260dpd) + (2mod * 36PCL)) + (4pa*2mod*37rgi) = 3728 bytes (for 4 PA states)
// As a function of PA states (QMSL_GSM_MAX_TX_GAIN_STATES), size equals
// 4 PA = 3728
// 5 PA = 4216
// 6 PA = 4704
// 7 PA = 5192
// 8 PA = 5680
//Adding Header Total NV Size = 3728 + 4 + 10 = 3742
#define GSM_TX_CAL_NV_REV0_MAX_PAYLOAD_SIZE  QMSL_GSM_MAX_TX_CAL_CHANNELS                                  \
   * ( (QMSL_GSM_MAX_TX_GAIN_STATES*2*QMSL_GSM_PMEAS_PYLD_SIZE)   \
   + (QMSL_GSM_DPD_AMAM_PYLD_SIZE+QMSL_GSM_DPD_AMPM_PYLD_SIZE) \
   + (2*QMSL_GSM_PwrErr_PCL_PYLD_SIZE)                         \
   )                                                            \
   + (QMSL_GSM_MAX_TX_GAIN_STATES*2*QMSL_GSM_RGI_PYLD_SIZE)
#define GSM_TX_CAL_NV_REV0_NUM_BYTES_IN_PAYLOAD_HEADER 14
#define GSM_TX_CAL_NV_REV0_NUM_BYTES_CHANSIZE          1
#define GSM_TX_CAL_NV_REV0_NUM_BYTES_CHAN              2
#define GSM_TX_CAL_NV_REV0_NUM_BYTES_AMAM_MAX          2
#define GSM_TX_CAL_NV_REV0_NUM_BYTES_RGI_PRED          1
#define GSM_TX_CAL_NV_REV0_NUM_BYTES_VERSION           2
#define GSM_TX_CAL_NV_REV0_NUM_BYTES_NUMELEM           2

typedef struct QMSL_GSM_Tx_Cx_Cal_NV_Rev0_Struct
{
   QMSL_GSM_Tx_Cal_NV_Header_Type aNvHeader;
   QMSL_Variant_Marker_Type aVariantMarker;
   unsigned char aPayload[GSM_TX_CAL_NV_REV0_MAX_PAYLOAD_SIZE];
} QMSL_GSM_Tx_Cx_Cal_NV_Rev0_Type;

typedef struct QMSL_GSM_Tx_Cx_Cal_NV_Rev1_Struct
{
   QMSL_Variant_Marker_Type aVariantMarker;
   unsigned char aPayload[GSM_TX_CAL_NV_REV0_MAX_PAYLOAD_SIZE];
} QMSL_GSM_Tx_Cx_Cal_NV_Rev1_Type;

typedef struct QMSL_RFNV_GSM_DATA_TYPE_TX_CAL_CHAN_REV1
{
   unsigned short dataTypeHeader;
   unsigned char nvContainer;
   unsigned char rfmDevice;
   unsigned char numberofdTxChannels;
   unsigned short txchannels[QMSL_GSM_MAX_TX_CAL_CHANNELS];
} QMSL_RFNV_GSM_TX_CAL_CHAN_REV1_TYPE;
typedef struct QMSL_RFNV_GSM_DATA_TYPE_TX_CAL_CHAN
{
   unsigned short dataTypeHeader;
   unsigned char numberofdTxChannels;
   unsigned short txchannels[QMSL_GSM_MAX_TX_CAL_CHANNELS];
} QMSL_RFNV_GSM_TX_CAL_CHAN_TYPE;

typedef struct QMSL_RFNV_GSM_DATA_TYPE_TX_CAL_AMAM_RGI_REV1
{
   unsigned short dataTypeHeader;
   unsigned char nvContainer;
   unsigned char rfmDevice;
   signed short amamMaxindBm100;
   unsigned char rgiforPredistortion;
} QMSL_RFNV_GSM_TX_CAL_AMAM_RGI_REV1_TYPE;
typedef struct QMSL_RFNV_GSM_DATA_TYPE_TX_CAL_AMAM_RGI
{
   unsigned short dataTypeHeader;
   signed short amamMaxindBm100;
   unsigned char rgiforPredistortion;
} QMSL_RFNV_GSM_TX_CAL_AMAM_RGI_TYPE;

typedef struct QMSL_GSM_RGI_List_Variant_Rev1_Struct
{
   unsigned short iVariantHeader;
   unsigned char nvContainer;
   unsigned char rfmDevice;
   unsigned char iModulationType;     /*0 = GMSK, 1 = 8PSK*/
   unsigned char iPaState;
   unsigned char iNumValidRGI;
   unsigned char aRgiList[QMSL_GSM_MAX_RGI_STEPS];
} QMSL_GSM_RGI_List_Variant_Rev1_Type;

typedef struct QMSL_GSM_PMEAS_List_Variant_Rev1_Struct
{
   unsigned short iVariantHeader;
   unsigned char nvContainer;
   unsigned char rfmDevice;
   unsigned char iModulationType;     /*0 = GMSK, 1 = 8PSK*/
   unsigned char iChannelIndex;
   unsigned char iPaState;
   short aPmeasList[QMSL_GSM_MAX_RGI_STEPS];
} QMSL_GSM_PMEAS_List_Variant_Rev1_Type;

typedef struct QMSL_GSM_DPD_AMAM_List_Variant_Rev1_Struct
{
   unsigned short iVariantHeader;
   unsigned char nvContainer;
   unsigned char rfmDevice;
   unsigned char iTableType; // AMAM or AMPM
   unsigned char iChannelIndex;
   unsigned short aDpdTable[QMSL_NV_MANAGER_EDGE_DPD_TABLE_SIZE];
} QMSL_GSM_DPD_AMAM_List_Variant_Rev1_Type;

typedef struct QMSL_GSM_DPD_AMPM_List_Variant_Rev1_Struct
{
   unsigned short iVariantHeader;
   unsigned char nvContainer;
   unsigned char rfmDevice;
   unsigned char iTableType; // AMAM or AMPM
   unsigned char iChannelIndex;
   short aDpdTable[QMSL_NV_MANAGER_EDGE_DPD_TABLE_SIZE];
} QMSL_GSM_DPD_AMPM_List_Variant_Rev1_Type;

typedef struct QMSL_GSM_Tx_IQ_Predist_Cal_Ancillary_Data
{
   //! Predistortion Calibration Estimated Freq. Error
   float afreqErrEstimate[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Predistortion Calibration Estimated Delay
   int aDelayEstimate[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Predistortion Calibration Estimated Delay
   float aMinPowerInEdgeDuration[QMSL_GSM_MAX_TX_CAL_CHANNELS];
} QMSL_GSM_Tx_IQ_Predist_Cal_Ancillary_Data_Type;

typedef struct QMSL_GSM_Tx_Gain_Channels_NV_Container
{
   QMSL_GSM_Tx_Cx_Cal_NV_Rev0_Type nvRev0;

   QMSL_GSM_Tx_IQ_Predist_Cal_Ancillary_Data iqCalData;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;

   //! Indicates whether the NV data in this struct is valid.
   int iHasValidData;
} QMSL_GSM_Tx_Calibration_NV;

typedef struct QMSL_GSM_Tx_Gain_Channels_Consoldiated_NV_Container
{
   QMSL_GSM_Tx_Cx_Cal_NV_Rev1_Type nvRev1;

   QMSL_GSM_Tx_IQ_Predist_Cal_Ancillary_Data iqCalData;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;

   //! Indicates whether the NV data in this struct is valid.
   int iHasValidData;

   unsigned int iDatatypeVer;
   int calTemp;
} QMSL_GSM_Tx_Calibration_Consolidated_NV;

/**
Definition of GSM Tx Polar Calibration AM table generated by QMSL RF Calbration Data Manager
*/
typedef struct
{
   //! AMAM table value
   unsigned short   AMAM[QMSL_NV_MANAGER_POLAR_CAL_AMAM_TABLE_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_Polar_Cal_AMAM_NV_struct;

/**
Definition of GSM Tx Polar Calibration PM table generated by QMSL RF Calbration Data Manager
*/
typedef struct
{
   //! AMPM table value
   unsigned int AMPM[QMSL_NV_MANAGER_POLAR_CAL_AMPM_TABLE_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_Polar_Cal_AMPM_NV_struct;

/**
Definition of GSM Tx Polar Calibration channel generated by QMSL RF Calbration Data Manager
*/
typedef struct
{
   //! AMPM table value
   unsigned short   iChannel;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_Polar_Cal_AMAM_CalChannel_NV_struct;

/**
Definition of GSM Tx Polar Calibration dynamic range generated by QMSL RF Calbration Data Manager
*/
typedef struct
{
   //! Max power
   int              iMaxPower;

   //! Min power
   int              iMinPower;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_Polar_Cal_AMAM_DynamicRange_NV_struct;

/**
Definition of GSM Tx Polar Calibration results generated by QMSL RF Calbration Data Manager
*/
typedef struct
{
   //! Polar calibration smoothed result
   QMSL_GSM_Polar_Cal_SweepRecord aPolar_Cal_Sweep_Smoothed_Result[QMSL_NV_MANAGER_POLAR_CAL_RAW_DATA_MAX_SIZE];

   //! Number of valid polar calibration sweep record in aPolar_Cal_Sweep_Smoothed_Result
   int iNumOfPoloarCalSweepRecord;

   //! Polar Calibration AMAM NV items table
   QMSL_GSM_Polar_Cal_AMAM_NV_struct aAMAM_NV[QMSL_NV_MANAGER_POLAR_CAL_TABLE_NUM];

   //! Polar Calibration AMPM NV items table
   QMSL_GSM_Polar_Cal_AMPM_NV_struct aAMPM_NV[QMSL_NV_MANAGER_POLAR_CAL_TABLE_NUM];

   //! Polar Calibration AMAM ARFCN NV items table
   QMSL_GSM_Polar_Cal_AMAM_CalChannel_NV_struct aCalChannel;

   //! Polar Calibration Dynamic range NV items table
   QMSL_GSM_Polar_Cal_AMAM_DynamicRange_NV_struct aDyanmicRange;
} QMSL_GSM_Polar_Cal_NV_struct;

/**
Definition of GSM Tx Predistion calibrated data
*/
typedef struct
{
   // the NV container to use
   unsigned char iTxNvContainer;

   //! The generated NV items mapping.  Enumeration of QMSL_GSM_Polar_Cal_Frequency.
   QMSL_GSM_Polar_Cal_Frequency iFreqMapping[ QMSL_GSM_MAX_TX_CAL_CHANNELS ];

   //! Phase samples of predistortion calibration waveform
   float adTxPhaseArr[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][QMSL_GSM_MAX_PREDIST_SAMPLES];

   //! Amplitude samples of predistortion calibration waveform
   float adTxAmpl[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][QMSL_GSM_MAX_PREDIST_SAMPLES];

   //! Number of channels measured
   unsigned long iNumChannels;

   //! Number of samples. = iDcSamples+iEdgeSamples+iNoiseSamples+ more noise samples.
   unsigned short iNumPredistortionWaveformSamples;

   //Cal RGI
   unsigned short iCalRgi;

   //! The sampling rate
   unsigned long iSamplingRateHz;

   //! Number of DC samples in the calibration waveform
   unsigned long iDcSamples;

   //! Number of EDGE samples in the waveform (in quarter symbols)
   unsigned long iEdgeSamples;

   //! Number of samples corresponding to trigger delay (in quarter symbols)
   unsigned long iNoiseSamples;

   //! Cal EDGE Tx Gain Param (Range 30 - 256)
   unsigned short iEDGETxGainParam;

   //! Cal EDGE Tx Calibration Waveform Param (Range > 4096)
   unsigned short iEDGETxCalScale;

   //! Percent of the DC Waveform to skip for initial transient (Range 10 - 60)
   float iDCTransientPercent;

   //! Cal EDGE Tx Calibration Waveform Param ( 1 < Range < 100)
   unsigned short iEDGETransientSymbols;

   //! Modem Constants
   unsigned char iOverRideModemConstants;
   float dDigGainUnity;
   float dRampUnity;
   float dExtensionFloor;
   float dDacScale;

   //! Debug Smooothing
   unsigned char iOverrideSmooothingDefaults;
   unsigned char iEnableAmAmSmoothing;
   float dAmAmKnot;
   float dAmPmKnot;
} QMSL_GSM_PreDist_Cal_Result;

/**
Struct for passing in control information (like whether to do slope correction or not)
for Enhanced Predistortion Cal.
*/
typedef struct
{
   // The NV container to use
   unsigned char iTxNvContainer;

   //! Algorithm Type: 0->GSM V3, 1-> GSM V4
   unsigned short iAlgType;

   //! Whether or not to do piecewise-linear adaptation before writing characterized data to NV
   unsigned short bDoPiecewiseAdaptation;

   //! Whether or not to do slope correction before writing characterized data to NV
   unsigned short bDoSlopeCorrection;

   //! Whether or not to do power adaptation before writing characterized data to NV
   unsigned short bDoPowerAdaptation;

   //! Whether to align the slope-correct curve to the original on the low side (if set to 1) or high side (if set to 0)
   unsigned short bSlopeCorrAlignLow;

   //! Whether or not to use this point in the DUT Digital Gain table for slope correction
   unsigned short bSlopeCorrUseDutPoint[QMSL_NV_MANAGER_ENH_CAL_DIG_GAIN_TABLE_SIZE];

   //! Whether or not to use this point in the DUT Digital Gain table for slope correction
   unsigned short bSlopeCorrUseCharPoint[QMSL_NV_MANAGER_ENH_CAL_DIG_GAIN_TABLE_SIZE];

   // ... and extend as necessary
} QMSL_GSM_EnhLinTx_Cal_Control;

/**
Struct containing data from a characterized curve
This is ONE curve for some (band, channel, RGI) combination, containing data for
both AMAM and AMPM parts, indexed by a common DAC.
Can be used for both characterized data and measured data.
Note : the Char DAC is float here as the average xml file can have non-integer DAC list
*/
typedef struct
{
   //! Characterized table - DAC column - THIS MUST BE SORTED IN ORDER OF ASCENDING DAC
   float dCharDac[QMSL_GSM_NUM_DAC_AMAM_TABLE];

   //! Characterized table - power column
   float dCharPower[QMSL_GSM_NUM_DAC_AMAM_TABLE];

   //! Characterized table - AMPM column
   float dCharAmpm[QMSL_GSM_NUM_DAC_AMAM_TABLE];
} QMSL_GSM_EnhLinTx_Cal_CharCurve;

/**
Struct containing extended data from a characterized curve - this is used for averaging
when additional working data like AMAM gain and standard deviation need to be tracked
When done, the aCharCurve can be directly taken from this and used to process NV.
(i.e., all the values in this struct, including those in aCharCurve, must be consistent when processing is finished)
*/
typedef struct
{
   //! Regular data
   QMSL_GSM_EnhLinTx_Cal_CharCurve aCharCurve;

   //! AMAM Gain
   float dAmamGain[QMSL_GSM_NUM_DAC_AMAM_TABLE];

   //! AMAM standard deviation (pointwise, when averaging), only valid if this is an averaged curve
   float dStdevAmam[QMSL_GSM_NUM_DAC_AMAM_TABLE];

   //! AMPM standard deviation (pointwise, when averaging), only valid if this is an averaged curve
   float dStdevAmpm[QMSL_GSM_NUM_DAC_AMAM_TABLE];
} QMSL_GSM_EnhLinTx_Cal_ExtCharCurve;

/**
Struct for passing in control information (like whether to do slope correction or not)
for Enhanced Predistortion Cal.
*/
typedef struct
{
   // nothing to see here, no options right now ...
   // ... but extend as necessary
} QMSL_GSM_EnhLinTx_Averaging_Control;

/**
Struct containing digital gain data
Can be used for both characterized data and measured data.
*/
typedef struct
{
   //! Digital Gain entry, raw NV values (NOT the mode passed onto the phone, but rather the power it means) - THIS MUST BE SORTED IN ORDER OF ASCENDING DIGGAIN
   unsigned int iDigGain[QMSL_NV_MANAGER_ENH_CAL_DIG_GAIN_TABLE_SIZE];

   //! Power corresponding to the digital gain
   float dPower[QMSL_NV_MANAGER_ENH_CAL_DIG_GAIN_TABLE_SIZE];

   //! Number of entries in this table
   unsigned int iNumEntries;
} QMSL_GSM_EnhLinTx_Cal_DigGainTable;

/**
Characterized data input to the Enhanced Predistortion Cal NV Generation
*/
typedef struct
{
   //! Number of channels measured
   unsigned int iNumChannels;

   //! The generated NV items mapping.  Enumeration of QMSL_GSM_Polar_Cal_Frequency.
   QMSL_GSM_Polar_Cal_Frequency iFreqMapping[ QMSL_GSM_MAX_TX_CAL_CHANNELS ];

   //! Cal RGI
   unsigned short iCalRgi;

   //! Modem DAC scaling constant
   float dDacScale;

   //! The characterized curves
   QMSL_GSM_EnhLinTx_Cal_CharCurve aCharCurves[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! And Digital Gain tabes
   QMSL_GSM_EnhLinTx_Cal_DigGainTable aCharDigGain[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! And Digital Gain tabes for the device-under-calibration (DUCk?)
   QMSL_GSM_EnhLinTx_Cal_DigGainTable aDutDigGain[QMSL_GSM_MAX_TX_CAL_CHANNELS];
} QMSL_GSM_EnhLinTx_Cal_Data;

/**
Definition of GSM Tx Predistion calibrated data
*/
typedef struct
{
   //! The generated NV items mapping.  Enumeration of QMSL_GSM_Polar_Cal_Frequency.
   QMSL_GSM_Polar_Cal_Frequency iFreqMapping[ QMSL_GSM_MAX_TX_CAL_CHANNELS ];

   //! Phase of predistortion calibration waveform
   float adTxPhaseArr[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][QMSL_GSM_MAX_NON_IQ_PREDIST_SAMPLES];

   //! Amplitude of predistortion calibration waveform
   float adTxAmpl[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][QMSL_GSM_MAX_NON_IQ_PREDIST_SAMPLES];

   //! DAC of predistortion Cal waveform
   unsigned short aiDac[QMSL_GSM_MAX_NON_IQ_PREDIST_SAMPLES];

   //! Number of channels measured
   unsigned long iNumChannels;

   //! Number of measured segments
   unsigned short iPredistortionMeasurementSize;

   //Cal RGI
   unsigned short iCalRgi;

   //! Warmup Loss - Gets applied to the AMAM dynamic range
   float dWarmupLossCorrection;

   //! AMPM Slope Correction - in deg/10dB
   float dAMPMSlopeCompensation;

   //! AMAM Slope Correction - in deg/10dB
   float dAMAMSlopeCompensation;

   //! AMAM Knot
   float dAMAMKnot;

   //! AMPM Knot
   float dAMPMKnot;

   //! Modem Constants
   unsigned char iOverRideModemConstants;
   float dDacScale;
} QMSL_GSM_NonIQ_PreDist_Cal_Result;

/**
Definition of GSM Tx Predistortion AMAM
*/
typedef struct
{
   //! AMAM table value
   unsigned short   AMAM[QMSL_NV_MANAGER_PREDISTORTION_CAL_AMAM_AMPM_TABLE_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_Predistortion_Cal_AMAM_NV_struct;

/**
Definition of GSM Tx Predistortion AMPM
*/
typedef struct
{
   //! AMPM table value
   short    AMPM[QMSL_NV_MANAGER_PREDISTORTION_CAL_AMAM_AMPM_TABLE_SIZE];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_Predistortion_Cal_AMPM_NV_struct;

/**
Definition of GSM Tx Predistortion Calibration RGI
*/
typedef struct
{
   //! Max power
   int              iPredistRGI;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_GSM_Predistortion_Cal_RGI_NV_struct;

/**
Definition of GSM Tx Predistortion calibration NV
Reusing Dynamic Range items from Polar Calibration
*/
typedef struct
{
   //! Predistortion Calibration AMAM NV items table
   QMSL_GSM_Predistortion_Cal_AMAM_NV_struct aAMAM_NV[QMSL_NV_MANAGER_PREDIST_CAL_TABLE_NUM];

   //! Predistortion Calibration AMPM NV items table
   QMSL_GSM_Predistortion_Cal_AMPM_NV_struct aAMPM_NV[QMSL_NV_MANAGER_PREDIST_CAL_TABLE_NUM];
} QMSL_GSM_PreDist_Cal_AMAM_AMPM_NV_struct;

typedef struct
{
   //! Predistortion Calibration AMAM NV items table
   QMSL_GSM_PreDist_Cal_AMAM_AMPM_NV_struct aAMAM_AMPM_NV[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Predistortion Calibration Dynamic range NV items table
   QMSL_GSM_Polar_Cal_AMAM_DynamicRange_NV_struct aDyanmicRange;

   //! Predistortion Calibration
   QMSL_GSM_Predistortion_Cal_RGI_NV_struct aCalRGI;

   //! Predistortion Calibration Estimated Freq. Error
   float afreqErrEstimate[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Predistortion Calibration Estimated Delay
   int aDelayEstimate[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Predistortion Calibration Estimated Delay
   float aMinPowerInEdgeDuration[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Indicate that this item has valid data
   int              iHasValidData;
} QMSL_GSM_PreDist_Cal_NV_Chan_struct;

/**
Struct containing data output from Power Adaptation
*/
typedef struct
{
   //! Characterized device power
   float dCharPower;

   //! Device-under-test power
   float dDutPower;

   //! Delta between those, applied to the characterized power
   float dCorrectionDelta;

   //! Whether or not the data here is valid - if this is false, likely because slope correction not performed
   unsigned short bDataValid;

   //! Whether or not power adaptation failed
   unsigned short bFailed;
} QMSL_GSM_EnhLinTx_Cal_PowerAdaptation_Result;

/**
Struct containing data output from Slope Correction
*/
typedef struct
{
   //! Whether or not this point in the characterized DigGain table was used during slope correction
   unsigned short bUseCharPoint[QMSL_NV_MANAGER_ENH_CAL_DIG_GAIN_TABLE_SIZE];

   //! Whether or not this point in the DUT DigGain table was used during slope correction
   unsigned short bUseDutPoint[QMSL_NV_MANAGER_ENH_CAL_DIG_GAIN_TABLE_SIZE];

   //! Characterized Power vs. DigitalGain slope
   float dCharSlope;
   //! Characterized Power vs. DigitalGain Y-intercept
   float dCharInt;
   //! Characterized Power vs. DigitalGain R-squared (how "nicely" it fit linearly)
   float dCharRsq;

   //! Device-Under-Test Power vs. DigitalGain slope
   float dDutSlope;
   //! Device-Under-Test Power vs. DigitalGain Y-intercept
   float dDutInt;
   //! CDevice-Under-Test Power vs. DigitalGain R-squared (how "nicely" it fit linearly)
   float dDutRsq;

   //! Amount AMAM (dB) was multiplied by (stretched out)
   float dSlopeCorrectionFactor;

   //! Whether or not the data here is valid - if this is false, likely because slope correction not performed
   unsigned short bDataValid;

   //! Whether or not slope correction failed - currently, there is no reason to fail
   unsigned short bFailed;
} QMSL_GSM_EnhLinTx_Cal_SlopeCorrection_Result;

typedef struct
{
   //! Predistortion Calibration AMAM NV items table
   QMSL_GSM_PreDist_Cal_AMAM_AMPM_NV_struct aAMAM_AMPM_NV[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Predistortion Calibration Dynamic range NV items table
   QMSL_GSM_Polar_Cal_AMAM_DynamicRange_NV_struct aDyanmicRange;

   //! Predistortion Calibration
   QMSL_GSM_Predistortion_Cal_RGI_NV_struct aCalRgi;

   //! Characterized Digital Gain table used in calculations
   QMSL_GSM_EnhLinTx_Cal_DigGainTable aCharDigGain[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! DUT Digital Gain table used in calculations
   QMSL_GSM_EnhLinTx_Cal_DigGainTable aDutDigGain[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Slope Correction results
   QMSL_GSM_EnhLinTx_Cal_SlopeCorrection_Result aSlopeCorrection[QMSL_GSM_MAX_TX_CAL_CHANNELS];

   //! Power Adaptation
   QMSL_GSM_EnhLinTx_Cal_PowerAdaptation_Result aPowerAdaptation;

   //! Indicate that this item has valid data
   int              iDataValid;
} QMSL_GSM_EnhLinTx_Cal_NV_Result;

/**
Definition of Internal Thermistor calibration measurements for use with QMSL RF Calibration Manager
*/
typedef struct
{
   //! The device on which therm was measured
   unsigned char iRFDevice;
   //! The calibration temperature (typically room temperature)
   char iCalTemp;
   //! The HKADC reading during calibration
   char iHKADCAtCalTemp;
   //! The ENH Therm Value at Room Temp
   unsigned long iEnhThermAtCalTemp;
   //! The slope.  The typical value is - 1/3
   double dSlope;
   //! Minimum temperature
   char iMinTemp;
   //! Maximum temperature
   char iMaxTemp;
   //! Indicates whether or not to populate NV_THERM_BINS_I
   unsigned char bFillNVThermBins;
   //! Indicates whether or not to use two slopes
   unsigned char bUseTwoSlopes;
   //! Indicates whether or not to use two slopes
   unsigned char bUseEnhTherm;
   //! Min Temp Slope
   double dMinTempSlope;
   //! Max Temp Slope
   double dMaxTempSlope;
   //! Indicates whether or not to use offsets for NV Therm Bins Calculation
   unsigned char bUseOffsetsForThermBinNV;
   //! The offsets to be applied for NV Therm Bins Calculation
   int dOffsetsForThermBinsNV[QMSL_NV_MANAGER_THERM_CAL_OFFSETS_FOR_NV_THERM_BINS];
} QMSL_Internal_Thermistor_Cal_Meas_struct;

/**
Definition of Internal Thermistor calibration NVs for use with QMSL RF Calibration Manager
*/
typedef struct
{
   //! ADC at min temperature
   //int iADC_Min_Temp;

   //! ADC at max temperature
   //int iADC_Max_Temp;

   //! NV_THERM
   QMSL_RFCAL_NV_Item oNV_Therm;

   //! NV_THERM_MIN
   QMSL_RFCAL_NV_Item oNV_Therm_Min;

   //! NV_THERM_MAX
   QMSL_RFCAL_NV_Item oNV_Therm_Max;

   //! NV_THERM_BINS
   QMSL_RFCAL_NV_Item oNV_Therm_Bins;
} QMSL_Internal_Thermistor_Cal_NV_struct;

/**
Definition of GPS RFIC IM2 calibration measurements for use with QMSL RF Calibration Manager
*/
typedef struct
{
   //! IM2 calibration result for I-channel IM2 DAC
   unsigned short iGPS_IM2_I_DAC;
   //! IM2 calibration result for Q-channel IM2 DAC
   unsigned short iGPS_IM2_Q_DAC;
} QMSL_GPS_IM2_Cal_Results_struct;

/**
Definition of GPS RFIC IM2 calibration NVs for use with QMSL RF Calibration Manager
*/
typedef struct
{
   //! NV_GPS_I_IM2_DAC
   QMSL_RFCAL_NV_Item oNV_GPS_IM2_I_DAC;
   //! NV_GPS_I_IM2_DAC
   QMSL_RFCAL_NV_Item oNV_GPS_IM2_Q_DAC;
} QMSL_GPS_IM2_Cal_NV_struct;

/**
Definition of Rx IQMismatch calibration NVs for use with QMSL RF Calibration Manager
*/
typedef struct
{
   //! NV_MISCOMP_A
   QMSL_RFCAL_NV_Item oNV_Mis_Comp_A_Coeff;

   //! NV_MISCOMP_B
   QMSL_RFCAL_NV_Item oNV_Mis_Comp_B_Coeff;
} QMSL_RxIQMismatch_Cal_NV_struct;

/**
Definition of Rx IQMismatch calibration measurements for use with QMSL RF Calibration Manager
*/
typedef struct
{
   //! Mismatch Compensation A
   short mismatch_value_A;

   //! Mismatch Compensation B
   short mismatch_value_B;

   //! Chain information
   unsigned short rx_path;
} QMSL_RxIQMismatch_Cal_Meas_struct;

typedef struct
{
   //!INO data [input], ino_data[0]=I0, ino_data[1]=Q0, ino_data[2]=I1, ino_data[3]=Q1, ... ino_data[25598]=I12799, ino_data[25599]=Q12799.  These I/Q data are collected via asychoronus FTM log
   char ino_data[25600];

   //!Coefficients [output](the real and imaginary data are returned via QLIB_RFCAL_Rx_ICI_Calibration_Algorithm), user doesn't need to fill it
   long coefficients[32];

   //! Chain information [input], rx_path = 0 for primary Rx, rx_path = 1 fo diversity path
   unsigned short rx_path;

   //! SNR (dB) value obtained as a result of performing ICI calibration.
   double snr;

   //!Whether Dual carrier is enabled
   long multiple_carriers;

   //!If multiple carriers are enabled, which carrier the measurement is for
   long carrier_id;

   //!Trunc Bits
   long trunc_bits;

   //!Filter Length
   long filterLength;
} QMSL_Rx_ICI_Cal_Meas_struct;

typedef struct
{
   //An array of 17 NV items
   QMSL_RFCAL_NV_Item oNV_ICI_CAL_Coefficients[17];

   //Single NV item used for multiple carrier case
   //setting for two carriers as of current implementation
   QMSL_RFCAL_NV_Item oNV_Multi_Chan_ICI_CAL_Coefficients[2];
} QMSL_Rx_ICI_Cal_NV_struct;

/**
Enumeration for writing calibration channel
*/
typedef enum
{
   QMSL_TX_CAL_CHANNEL = 0x0,     //!< 'Tx calibration channel
   QMSL_RX_CAL_CHANNEL = 0x1,     //!< 'Rx Primary Path calibration channel
   QMSL_RX1_CAL_CHANNEL = 0x2,    //!< 'Rx Secondary Path calibration channel
   QMSL_TX_C2_CAL_CHANNEL = 0x3,  //!< 'Chain 2 Tx Path calibration channel
   QMSL_RX_C2_CAL_CHANNEL = 0x4,   //!< 'Chain 2 Rx Path calibration channel
   QMSL_RX_C3_CAL_CHANNEL = 0x5   //!< 'Chain 3 Rx Path calibration channel
} QMSL_RFCAL_Channel_Type;

/**
NV write item status
*/
typedef struct
{
   //! Enumeration
   unsigned short iNVenum;

   //! NV_WRITE's status or FTM_RFNV_WRITE's FTM Error Code
   unsigned short iStatus;

   //! NV item name
   char         sNVName[QMSL_NV_MANAGER_NV_ITEM_NAME_LENGTH];

   // ! The write method, 0 = NV_WRITE; 1 = FTM_RFNV_WRITE 2 = FTM_RFNV_WRITE_V2
   unsigned short iWriteMethod;
} QMSL_RFCal_Write_Status;

#define QMSL_NV_MANAGER_WRITE_TO_PHONE_MAX_ITEM 1024

/**
Structure to hold the NV write status from QLIB_RFCAL_NV_Manager_WriteToPhone
*/
typedef struct
{
   QMSL_RFCal_Write_Status aNVItemStatus[QMSL_NV_MANAGER_WRITE_TO_PHONE_MAX_ITEM];

   unsigned int iNumOfItemsInCache;
} QMSL_RFCal_WriteToPhone_Status;

/**
QMSL ReadVerify item status
*/
typedef struct
{
   //! Enumeration (RFNV ID)
   unsigned short iNVenum;

   //! 0 == Data mismatch, 1 == Data match
   unsigned short iVerifiedStatus;

} QMSL_RFCal_ReadVerify_Item_Status;

/**
Structure to hold the NV write status from QLIB_RFCAL_NV_Manager_ReadVerify
*/
typedef struct
{
   QMSL_RFCal_ReadVerify_Item_Status aNVItemStatus[QMSL_NV_MANAGER_WRITE_TO_PHONE_MAX_ITEM];

   //! Number of valid item in aNVItemStatus
   unsigned int iNumOfItemsVerified;
} QMSL_RFCal_ReadVerify_Status;

typedef enum
{
   NV_Manager_WriteToPhone_AUTO_DETECT          = 0,            // Auto detect to use NV_WRITE or FTM_RFNV_WRITE (default)
   NV_Manager_WriteToPhone_USE_LEGACY_NV_WRITE = 1,         // Use Legacy NV Write (80-V1294-1)
   NV_Manager_WriteToPhone_USE_FTM_SEQUENCER   = 2          // Use FTM Sequencer in conjunction with FTM_RVNV_WRITE
}
QMSL_Manager_WriteToPhone_Method;

typedef enum
{
   QMSL_RFcal_TempCompAdj_MeasureType_TX_LIN_VS_TEMP = 1,   // QMSL_TempCompAdjustment Measure Type = Tx_Lin_Vs_Temp
   // add other type in the future
} QMSL_RFCal_TempCompAdjustMeasureType;                   // Measure Type of TempComp Adjust based on temperature of the calibration, currently supports Tx, will extend to Rx in the future

typedef enum
{
   QMSL_RFCal_TempCompAdj_ResCode_TEMPCOMP_ADJ_SUCCESS,                            // TempComp Adjust based on the temprature of the calibration success
   QMSL_RFCal_TempCompAdj_ResCode_NVToolManager_NULL_POINTER,                      // NVToolManager that used to read NV data from QCN file is NULL pointer, QCN FILE not found
   QMSL_RFCal_TempCompAdj_ResCode_QCN_FILE_ERR,                                     // QCN file Error
   QMSL_RFCal_TempCompAdj_ResCode_NOT_FOUND_REQUESTED_NV_IN_QCN_FILE_ERR,          // Requested NV Not found in QCN file failure
   QMSL_RFCal_TempCompAdj_ResCode_REQUIRED_MEASURE_TYPE_ERR,                       // Requested Measurement Type not Supported in CalNVManager
   QMSL_RFCal_TempCompAdj_ResCode_NV_NOT_DEFINED_IN_CAL_NVMANAGER_ERR,             // Requested NV Not Supported in CalNVManager
   QMSL_RFCal_TempCompAdj_ResCode_NV_READ_FROM_CAL_NVMANAGER_ERR,                  // Requested NV Read from CalNVManager fail
   QMSL_RFCal_TempCompAdj_ResCode_NOT_SUPPORTED_TECHNOLOGY,                        // Requested RF_Mode is not a supported technology for tempComp Adjust with Cal temperature
   QMSL_RFCal_TempCompAdj_ResCode_REQUIRED_PA_STATE_ERR,                           // Requested PA state is out of supported PA state, currently it's 4
   QMSL_RFCal_TempCompAdj_ResCode_CUR_THERMAL_ADC_EXCEED_MAX_THERMAL_ADC,          // Current calibration temperature thermal ADC reading greater than the max thermal ADC (which means the current calibration tempeture is lower than the low limit
   QMSL_RFCal_TempCompAdj_ResCode_CUR_THERMAL_ADC_EXCEED_MIN_THERMAL_ADC,          // Current calibration temperature thermal ADC reading less than the minimum thermal ADC (which means the current calibration tempeture is higher than the high limit
   QMSL_RFCal_TempCompAdj_ResCode_TEMPCOMP_TABLE_SIZE_ERROR,                        // Tempcomp Table Size failure, For GSM, Table Size=16, for WBand, TempComp Table Size=8
   QMSL_RFCal_TempCompAdj_ResCode_THERM_BIN_NV_ERROR,                               // ThermBin NV not correct
   QMSL_RFCal_TempCompAdj_ResCode_NV_SIZE_EXCEED_QMSL_MAX_BINARY_DATA_SIZE,         // Requested TempComp NV dataSize (in bytes) exceeds CalNVManager Max binary DataSize
} QMSL_RFCal_TempCompAdjust_ResCode_Enum;                                           // Returned errCode of TempComp Adjust

typedef enum
{
   DPD_TYPE_AMAM,
   DPD_TYPE_AMPM,
   DPD_TYPE_EPDT,
   DPD_TYPE_NONE
} QMSL_load_dpd_input_table_type;

/******************************************************************************
QMSL - NV Tool
*******************************************************************************/
/**
The maximum size of RFNV data
*/
#define MAX_RFNV_DATA_SZ	28672	//16384

/**
The maximum size of RFNV data in EFS file
*/
#define MAX_EFS_RFNV_DATA_SZ MAX_RFNV_DATA_SZ

/**
The maximum size of a RF NV file, which will be written to item file storage in QCN
If the file size is larger than MAX_EFS_RFNV_ITEM_FILE_SIZE, the file will be written to EFS Backup file store in QCN
*/
#define MAX_EFS_RFNV_ITEM_FILE_SZ 106
/**
The maximum size of EFS file path to be written to TAR
*/
#define TAR_PATH_MAX 100
/**
The enumeration for the "source" parameter in NV Tool call back function

*/

typedef enum
{
   NV_Tool_LoadNVsFromSource        = 0,
   NV_Tool_LoadNVsFromQCN           = 1,
   NV_Tool_LoadNVsFromMobile        = 2,
   NV_Tool_WriteNVsToSource         = 3,
   NV_Tool_WriteNVsToQCN            = 4,
   NV_Tool_WriteNVsToMobile         = 5,
   NV_Tool_ReadSingleNVFromMobile   = 6,
   NV_Tool_WriteNVsToTAR            = 7,
   NV_Tool_LoadNVsFromBDF           = 8,
   NV_Tool_WriteNVsToBDF         = 9,
   BackupNV_LoadNVsFromMobile    = 10,
   BackupNV_WriteNVsToQCN        = 11,
}
QMSL_NVTool_CallBack_Source_Enum;

/**
The enumeration for the "event" parameter in NV Tool call back function
*/
typedef enum
{
   NVTool_NV_DONE_S         = 0,        //!<' Request completed okay
   NVTool_NV_BUSY_S            = 1,     //!<' Request is queued
   NVTool_NV_BADCMD_S           = 2,        //!<' Unrecognizable command field
   NVTool_NV_FULL_S            = 3,     //!<' The NVM is full
   NVTool_NV_FAIL_S            = 4,     //!<' Command failed, reason other than NVM was full
   NVTool_NV_NOTACTIVE_S        = 5,        //!<' Variable was not active
   NVTool_NV_BADPARM_S          = 6,        //!<' Bad parameter in command block
   NVTool_NV_READONLY_S     = 7,        //!<' Parameter is write-protected and thus read only
   NVTool_NV_BADTG_S            = 8,        //!<' Item not valid for Target
   NVTool_NV_NOMEM_S            = 9,        //!<' free memory exhausted
   NVTool_NV_NOTALLOC_S     = 10,       //!<' address is not a valid allocation
   NVTool_NV_UNKOWN_S           = 11,       //!<' Unknown response from NV_READ or NV_WRITE command
   NVTool_NV_Written_To_SRC    = 12,       //!<' NV Item appended to NV source XML
   NVTool_NV_Written_To_QCN    = 13,       //!<' NV Item appended to QCN
   NVTool_NV_Read_From_SRC_SUCCESS   = 14,       //!<' NV Item read from NV source file and added to NV tool
   NVTool_NV_Read_From_QCN_SUCCESS   = 15,       //!<' NV Item read from QCN file and added to NV tool
   NVTool_NV_Read_From_SRC_FAIL      = 16,       //!<' NV Item read from NV source file, but failed to add the item to NV tool
   NVTool_NV_Read_From_QCN_FAIL      = 17,       //!<' NV Item read from QCN file, but failed to add the item to NV tool
   NVTool_NV_Read_From_SRC_SUCCESS_FILTERED_OUT   = 18,       //!<' NV Item read from NV source file. It is NOT added to NV tool because it is filtered out
   NVTool_NV_Read_From_QCN_SUCCESS_FILTERED_OUT   = 19,       //!<' NV Item read from QCN file. It is not added to NV tool because it is filtered out
   NVTool_NV_Written_To_TAR  = 20,
} QMSL_NVTool_CallBack_Event_Enum;

/**
The result code returned by NV (QCN/XML/Mobile NV management) tool function
*/
typedef enum
{
   ERROR_FREE,                              //!<' No error
   MSXML_FAILED_TO_INSTANTIATE,         //!<' Check MSMXL6 is installed on target machine
   MSXML_FAILED_TO_LOAD_SRC,                //!<' Check that source file exists and is well formatted
   MSXML_FAILED_TO_SAVE_SRC,                //!<' Check that target path exists
   MSXML_FAILED_TO_LOAD_DEF,                //!<' Check that definition file exists and is well formatted
   SOURCE_XML_VALIDATION_FAILED,           //!<' Failed to validate source xml
   DEF_XML_VALIDATION_FAILED,              //!<' Failed to validate definition xml
   FAILED_TO_OPEN_QCN,                     //!<' Check that QCN exists or path is valid.  QCN file may be opened by other application
   INDEX_OUT_OF_BOUND,                      //!<' Check index
   NV_ITEM_NOT_DEFINED,                 //!<' The NV item doesn't have an definition
   NV_ITEM_NO_VALUE,                        //!<' The NV item doesn't not have any values
   NV_ITEM_FAILED_TO_SET_VALUE,         //!<' Failed to set the item value
   NV_ITEM_FAILED_TO_GET_VALUE,         //!<' Failed to get the item value
   NV_ITEM_REDEFINED,                       //!<' A NV Item has been defined by a previous load.  The NV item definition is overwritten
   FAILED_TO_OPEN_SRC,                      //!<' Failed to open source file
   FAILED_TO_OPEN_QDF,                      //!<' Failed to open a file for writing QDF
   FAILED_TO_CONNECT_TO_MOBILE,         //!<' Failed to read/write NVs from/to mobile.  Check phone connection
   FAILED_TO_OPEN_HTML,                 //!<' Failed to open HTML file for write access
   FAILED_TO_OPEN_QCN_STORAGE,              //!<' Failed to open a QCN file because QMSL can't get a valid storage
   FAILED_TO_OPEN_FILTER_FILE,              //!<' Failed to open filter file
   FAILED_TO_READ_ITEM_FROM_QCN_FILE,       //!<' Failed to read an item from QCN file
   FAILED_TO_READ_ITEM_FROM_SRC_FILE,       //!<' Failed to read an item from source file
   FAILED_TO_READ_RFNV_OR_EFS_ITEM_FROM_MOBILE,   //!<' Failed to read RFNV or EFS item from mobile
   FAILED_TO_WRITE_RFNV_OR_EFS_ITEM_TO_MOBILE,     //!<' Failed to write RFNV or EFS item to mobile
   FAILED_TO_OPEN_TAR,                       //!<' Failed to open source file
   FAILED_TO_ACCESS_BDF,         //!<' Failed to read/write NVs from/to BDF.
   NVITEM_NOT_VARIANT,             //!<' The select NV item is not Variant Type
   FAILED_TO_INSERT_DATA_INTO_VARIANT_NV,             //!<' Failed to insert data into variant NV
   INCOMING_BUFFER_TO_SMALL,                       //!<' The incoming buffer is too small to copy data
   DATATYPE_DICTIONARY_NOT_FOUND,                       //!<' The <Datatype> dictionary is not loaded with NV Tool API
   NVTool_UNKNOWN                           //!<' Unknown
// Any new enumeration should have an entry in string NVTool_Manager::ResultCodeString[]

} QMSL_NVTool_ResultCode_Enum;

//The QMSL_NVTool_Backup_ResultCode_Enum is referred by QLIB_BackupNVFromMobileToQCN in QMSL_NVTool_Manager
//to return error codes
typedef enum
{
   BACKUP_ERROR_FREE,
   BACKUP_FAILED_TO_READ_EXT_BUILD_INFO,
   BACKUP_FAILED_TO_READ_FEATURE_MASK,
   BACKUP_FAILED_TO_OPEN_QCN_STORAGE,
   BACKUP_FAILED_TO_READ_STORAGE_CONFIGURATION,
   BACKUP_FAILED_TO_CREATE_EFS_BACKUP,
   BACKUP_FAILED_TO_OPEN_NV_STORAGE,
   BACKUP_FAILED_TO_OPEN_NV_STORAGE_BY_CONTEXT,
   BACKUP_UNKNOWN
} QMSL_Backup_ResultCode_Enum;

/******************************************************************************
QMSL - Band Class Helper
*******************************************************************************/
// Define offsets for assigning band enum values to keep bands grouped by tech
#define GSM_BAND_ENUM_START     0
#define WCDMA_BAND_ENUM_START   100
#define HDR_BAND_ENUM_START     200
#define BLUETOOTH_BAND_ENUM_START  300
#define MEDIAFLO_BAND_ENUM_START  400
#define FM_BAND_ENUM_START  500
#define DVBH_BAND_ENUM_START  600
#define GPS_BAND_ENUM_START  700
#define ISDBT_BAND_ENUM_START  800
#define LTE_BAND_ENUM_START  20000
#define TDSCDMA_BAND_ENUM_START  1000
#define WLAN_BAND_ENUM_START  1100
#define NFC_BAND_ENUM_START 1200
#define FM_RADIO_BAND_ENUM_START 1300
#define WIGIG_RADIO_BAND_ENUM_START 1400
// For band that use simple band enumeration, declare offset constants to simplify the task of
// translating from the enum value to the band number (e.g. BH_WCDMA_BAND_I - LTE_BAND_ENUM_OFFSET = 1)
#define WCDMA_BAND_ENUM_OFFSET ((WCDMA_BAND_ENUM_START) - (1))
#define TDSCDMA_BAND_ENUM_OFFSET ((TDSCDMA_BAND_ENUM_START) - (1))
#define LTE_BAND_ENUM_OFFSET ((LTE_BAND_ENUM_START) - (1))

/**
The enumeration is used by band helper functions
*/
typedef enum
{
   BH_GSM_BAND_E_GSM = GSM_BAND_ENUM_START,
   BH_GSM_BAND_P_GSM,
   BH_GSM_BAND_DCS,
   BH_GSM_BAND_PCS,
   BH_GSM_BAND_850,
   BH_GSM_END_OF_BANDS, // must be after all GSM bands

   BH_FM_BAND_800,

   BH_WCDMA_BAND_I = WCDMA_BAND_ENUM_START,
   BH_WCDMA_BAND_II,
   BH_WCDMA_BAND_III,
   BH_WCDMA_BAND_IV,
   BH_WCDMA_BAND_V,
   BH_WCDMA_BAND_VI,
   BH_WCDMA_BAND_VII,
   BH_WCDMA_BAND_VIII,
   BH_WCDMA_BAND_IX,
   BH_WCDMA_BAND_X,
   BH_WCDMA_BAND_XI,
   BH_WCDMA_BAND_XII,
   BH_WCDMA_BAND_XIII,
   BH_WCDMA_BAND_XIV,
   BH_WCDMA_BAND_XV,
   BH_WCDMA_BAND_XVI,
   BH_WCDMA_BAND_XVII,
   BH_WCDMA_BAND_XVIII,
   BH_WCDMA_BAND_XIX,
   BH_WCDMA_END_OF_BANDS, // must be after all WCDMA bands

   BH_CDMA_BAND_CLASS_0 = HDR_BAND_ENUM_START,//US Cellular
   BH_CDMA_BAND_CLASS_1,//US PCS
   BH_CDMA_BAND_CLASS_2,//TACS
   BH_CDMA_BAND_CLASS_3,//JTACS
   BH_CDMA_BAND_CLASS_4,//Korean PCS
   BH_CDMA_BAND_CLASS_5,//NMT-450
   BH_CDMA_BAND_CLASS_6,//IMT-2000
   BH_CDMA_BAND_CLASS_7,//700-MHz
   BH_CDMA_BAND_CLASS_8,//1800-MHz
   BH_CDMA_BAND_CLASS_9,//900-MHz
   BH_CDMA_BAND_CLASS_10, //SECONDARY800,
   BH_CDMA_BAND_CLASS_11, // Extended 450MHz
   BH_CDMA_BAND_CLASS_12,
   BH_CDMA_BAND_CLASS_13,
   BH_CDMA_BAND_CLASS_14, // Extended BC1
   BH_CDMA_BAND_CLASS_15, // AWS Band
   BH_CDMA_END_OF_BANDS, // must be after all CDMA bands

   BH_BLUETOOTH_BAND_ISM = BLUETOOTH_BAND_ENUM_START, //ISM - Industrial Scientific Medicine
   BH_BLUETOOTH_END_OF_BANDS, // must be after all BLUETOOTH bands

   BH_MEDIAFLO_BAND_US = MEDIAFLO_BAND_ENUM_START,
   BH_MEDIAFLO_BAND_VHF,
   BH_MEDIAFLO_BAND_UHF,
   BH_MEDIAFLO_BAND_L,
   BH_MEDIAFLO_END_OF_BANDS, // must be after all MEDIAFLO bands

   BH_DVBH_BAND_UHF_BW8_N0 = DVBH_BAND_ENUM_START,
   BH_DVBH_BAND_UHF_BW8_N1,
   BH_DVBH_BAND_UHF_BW8_N2,
   BH_DVBH_BAND_UHF_BW7_N0,
   BH_DVBH_BAND_UHF_BW7_N1,
   BH_DVBH_BAND_UHF_BW7_N2,
   BH_DVBH_BAND_UHF_BW6_N0,
   BH_DVBH_BAND_UHF_BW6_N1,
   BH_DVBH_BAND_UHF_BW6_N2,
   BH_DVBH_BAND_UHF_BW5_N0,
   BH_DVBH_BAND_UHF_BW5_N1,
   BH_DVBH_BAND_UHF_BW5_N2,
   BH_DVBH_END_OF_BANDS, // must be after all DVB-H bands

   BH_GPS_BAND_L1 = GPS_BAND_ENUM_START, // civilian GPS, L1
   BH_GPS_END_OF_BANDS, // must be after all GPS bands

   BH_ISDBT_BAND_BW6_JAPAN = ISDBT_BAND_ENUM_START,
   BH_ISDBT_BAND_BW6_BRAZIL,
   BH_ISDBT_END_OF_BANDS, // must be after all ISDB-T bands

   BH_LTE_BAND_1 = LTE_BAND_ENUM_START,
   BH_LTE_BAND_2,
   BH_LTE_BAND_3,
   BH_LTE_BAND_4,
   BH_LTE_BAND_5,
   BH_LTE_BAND_6,
   BH_LTE_BAND_7,
   BH_LTE_BAND_8,
   BH_LTE_BAND_9,
   BH_LTE_BAND_10,
   BH_LTE_BAND_11,
   BH_LTE_BAND_12,
   BH_LTE_BAND_13,
   BH_LTE_BAND_14,
   BH_LTE_BAND_15,
   BH_LTE_BAND_16,
   BH_LTE_BAND_17,
   BH_LTE_BAND_18,
   BH_LTE_BAND_19,
   BH_LTE_BAND_20,
   BH_LTE_BAND_21,
   BH_LTE_BAND_22,
   BH_LTE_BAND_23,
   BH_LTE_BAND_24,
   BH_LTE_BAND_25,
   BH_LTE_BAND_26,
   BH_LTE_BAND_27,
   BH_LTE_BAND_28,
   BH_LTE_BAND_29,
   BH_LTE_BAND_30,
   BH_LTE_BAND_31,
   BH_LTE_BAND_32,
   BH_LTE_BAND_33,
   BH_LTE_BAND_34,
   BH_LTE_BAND_35,
   BH_LTE_BAND_36,
   BH_LTE_BAND_37,
   BH_LTE_BAND_38,
   BH_LTE_BAND_39,
   BH_LTE_BAND_40,
   BH_LTE_BAND_41,
   BH_LTE_BAND_42,
   BH_LTE_BAND_43,
   BH_LTE_BAND_44,
   BH_LTE_BAND_45,
   BH_LTE_BAND_46,
   BH_LTE_BAND_66 = LTE_BAND_ENUM_START + 65,
   BH_LTE_BAND_125 = LTE_BAND_ENUM_START+124,
   BH_LTE_BAND_126,
   BH_LTE_BAND_127,
   BH_LTE_BAND_252 = LTE_BAND_ENUM_START+251,
   BH_LTE_BAND_253,
   BH_LTE_BAND_254,
   BH_LTE_BAND_255,
   BH_LTE_END_OF_BANDS,

   //band 33 is the first tdd band
   BH_TDSCDMA_BAND_B33 = TDSCDMA_BAND_ENUM_START, //1900 MHz to 1920 MHz
   BH_TDSCDMA_BAND_B34, //2010 MHz to 2025 MHz
   BH_TDSCDMA_BAND_B35, //1850 MHz to 1910 MHz
   BH_TDSCDMA_BAND_B36, //1930 MHz to 1990 MHz
   BH_TDSCDMA_BAND_B37, //1910 MHz to 1930 MHz
   BH_TDSCDMA_BAND_B38, //2570 MHz to 2620 MHz
   BH_TDSCDMA_BAND_B39, //1880 MHz to 1920 MHz
   BH_TDSCDMA_BAND_B40, //2300 MHz to 2400 MHz
   BH_TDSCDMA_BAND_B41, //2496 MHz to 2690 MHz
   BH_TDSCDMA_BAND_B42, //3400 MHz to 3600 MHz
   BH_TDSCDMA_BAND_B43, //3600 MHz to 3800 MHz
   BH_TDSCDMA_END_OF_BANDS,

   BH_WLAN_BAND_2G = WLAN_BAND_ENUM_START, // 2.4 GHz band
   BH_WLAN_BAND_5G,                         // 5 GHz band
   BH_WLAN_END_OF_BANDS,

   BH_NFC = NFC_BAND_ENUM_START,
   BH_NFC_END_OF_BANDS,

   BH_FM_RADIO_US_EU= FM_RADIO_BAND_ENUM_START,
   BH_FM_RADIO_JAPAN,
   BH_FM_RADIO_JAPAN_WIDE,
   BH_FM_RADIO_USER_DEFINED,
   BH_FM_RADIO_END_OF_BANDS,

   BH_WIGIG_BAND_60G = WIGIG_RADIO_BAND_ENUM_START,
   BH_WIGIG_END_OF_BANDS,

   END_OF_BH_BAND_CLASS_ENUM = 0xFFFFFFFF
} BAND_CLASS_ENUM;

/******************************************************************************
FTM - Definitions for multiple FTM modes
*******************************************************************************/

/**

*/
typedef enum
{
   QMSL_WaitForMetric_cdma2000_AGC_C0,      //!<' cdma2000 AGC C0
   QMSL_WaitForMetric_cdma2000_AGC_C1,      //!<' cdma2000 AGC C1
   QMSL_WaitForMetric_evdo2000_AGC_C0,      //!<' 1xEV-DO AGC C0
   QMSL_WaitForMetric_evdo2000_AGC_C1,      //!<' 1xEV-DO AGC C1
   QMSL_WaitForMetric_evdo2000_C2I_C0,      //!<' 1xEV-DO C/I C0
   QMSL_WaitForMetric_evdo2000_C2I_C1,      //!<' 1xEV-DO C/I C1
   QMSL_WaitForMetric_evdo2000_C2I_Both_C0_C1,      //!<' 1xEV-DO C/I, both C0 and C1

   QMSL_WaitForMetric_Max                   //!<' Maximum number
} QMSL_WaitForMetric_Types;

/******************************************************************************
QMSL - Text logging flags
*******************************************************************************/

//  ---------------------------------------------------------
//  defines for phone logging settings
//
//  ---------------------------------------------------------

#define LOG_NOTHING     0x0000  //!<' log nothing

#define LOG_C_HIGH_LEVEL_START  0x0200  //!<' High level C function start, indicates the begining of a high level C function, which
//!<' calls other low level C functions internal to the library

#define LOG_C_HIGH_LEVEL_STOP   0x4000  //!<' High level C function stop

#define LOG_IO          0x0001  //!<' data IO (data bytes)
#define LOG_FN          0x0002  //!<' function calls with parameters
#define LOG_RET         0x0004  //!<' function return data

#define LOG_INF         0x0008  //!<' general information (nice to know)--do not use this one, as
//!<' this space needs to be reserved for async messages

#define LOG_ASYNC       0x0008  //!<' asynchronous messages

#define LOG_ERR         0x0010  //!<' critical error information

#define LOG_IO_AHDLC    0x0020  //!<' HDLC IO tracing (data bytes)
#define LOG_FN_AHDLC    0x0040  //!<' HDLC layer function calls
#define LOG_RET_AHDLC   0x0080  //!<' HDLC function return data
#define LOG_INF_AHDLC   0x0100  //!<' HDLC general information
#define LOG_ERR_AHDLC   LOG_INF_AHDLC   //!<' HDLC Error info merged with LOG_INF_AHDLC, to free up the log bit

#define LOG_IO_DEV      0x0400  //!<' device IO tracing (data bytes)
#define LOG_FN_DEV      0x0800  //!<' device layer function calls
#define LOG_RET_DEV     0x1000  //!<' device function return data
#define LOG_INF_DEV     0x2000  //!<' device general information
#define LOG_ERR_DEV     LOG_INF_DEV     //!<' device error information, merged with LOG_INF_DEV to free up the log bit

#define LOG_DEFAULT     (LOG_C_HIGH_LEVEL_START|LOG_C_HIGH_LEVEL_STOP|LOG_FN|LOG_IO|LOG_RET|LOG_ERR|LOG_ASYNC) //!<'  default settings

#define LOG_ALL         0xFFFF  //!<' everything

/**
Enumeration of extended text logging categories, to be used with
QLIB_ExtendedTextMessage_SetCategoryEnable(),

QMSL Developer note:  when this list is updated, please also update these functions:
void Diag_FTM::InitExtendedTextMessageList( void )
*/
typedef enum
{
   QMSL_ExtTextMsgCat_MediaFLO_Parse         = 0,  //!< ' MediaFLO Layer one log parsing
   QMSL_ExtTextMsgCat_cdma2000_RDA_Parse     = 1,  //!< ' cdma2000 RDA log parsing for SER/FER
   QMSL_ExtTextMsgCat_NV_Manager_Debug        = 2,  //!< ' NV Manager Debug Message
   QMSL_ExtTextMsgCat_NV_Tool_Debug          = 3,   //!< ' NV Tool Debug Message
   QMSL_ExtTextMsgCat_QPHONEMS_SW_Download = 4     //!< ' QPHONEMS Software Download (aka QMSL_DownloadAgent)
} QMSL_Extended_Text_Message_Category_Enum;

//! Maximum number of characters in the category name string, to be used with QLIB_ExtendedTextMessage_GetCategoryListItem()
#define QMSL_EXTENDED_TEXT_MESSAGE_CATEGORY_NAME_SIZE 30

/******************************************************************************
QMSL - SE BER Command IDs, Structs and Enums
*******************************************************************************/
/**
Single Ended BER Command IDs. refer to 80-VG331-1

*/
typedef enum
{
   _FTM_SE_BER_CONFIGURE_REQ            = 0,
   _FTM_SE_BER_START_LOG_REQ            = 1,
   _FTM_SE_BER_STOP_LOG_REQ         = 2,
   _FTM_SE_BER_SET_LOOP_AB_ORDER_REQ   = 3,
   _FTM_SE_BER_SET_EXPECTED_MCS_REQ    = 4,
   _FTM_SE_BER_CLEAR_SYNC_STATUS        = 5,
   _FTM_SE_BER_GET_SYNC_STATUS          = 6
} FTM_SE_BER_Command_IDs;

/**
Enum containing the list of Loopback types.
*/
typedef enum
{
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC122K = 0, // 12.2kbps RMC
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC64K = 1,  // 64 kbps RMC
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_C = 2,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_5_6 = 3,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_7_9 = 4,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_A = 5,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_B = 6,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC384K = 7,   // 384 kbps
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC12p2K = 8,//TDS 12.2kbps rmc, for both Single code and multi-code
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC64K = 9, //TDS 64kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC144K = 10,//TDS 384kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC384K = 11,//TDS 384kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_4 = 12,

   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_MAX              //!< Size of list, not a valid log ID
} log_FTM2_SE_BER_Loopback_Type_enum;

/**
Response packet for WCDMA RMC 12.2Mbps/64Mbps, GSM Loop C  Types
*/
typedef struct
{
   /**
   Frame Number that this BER information corresponds to (GSM TDMA Frame
   Number for GSM and EGPRS/CFN for WCDMA operation)
   */
   dword    frame_number;
   /**
   Slot number that this data block BER info corresponds to.  This will be
   useful for multislot operation, in order to collect BER statistics independently on different timeslots.
   */
   byte slot_num;

   /**
   PN state for the data block.  This will indicate if the local PN generator is in
   sync or out of sync for this particular data block.
   Sync detection is evaluated on a data block by data block basis.
   \code
   0 ?PN state unlocked (out of sync)
   1 ?PN state locked (in sync)
   \endcode
   */
   byte pn_state;

   //! Number of bits in this data block.
   word num_bits;

   //! Number of errors in this data block.
   word num_errors;
} FTM_SE_BER_TYPE_I_RESPONSE_Struct;

/**
Response packet for GSM Loop A/B  Types
*/
typedef struct
{
   /**
   Frame Number that this BER information corresponds to (GSM TDMA Frame Number
   for GSM and EGPRS/CFN for WCDMA operation)
   */
   dword    frame_number;

   /**
   */
   byte slot_num;       //!< Slot number that this data block BER info corresponds to.  This will be useful
   //!< for multislot operation, in order to collect BER statistics independently on different timeslots.

   /**
   PN state for the data block.  This will indicate if the local PN generator is in
   sync or out of sync for this particular data block.
   Sync detection is evaluated on a data block by data block basis. 0 ?PN state unlocked (out of sync)/
   1 ?PN state locked (in sync)
   */
   byte pn_state;

   /**
   0 ?Bad Frame = FALSE and 1 ?Bad Frame = TRUE
   */
   byte bad_frame_indicator;

   /**
   Number of class 1a bits in this data block.  For full rate speech this
   will be set to 50.
   */
   word num_class1a_bits;

   /**
   Number of errors in the class 1a bits.
   */
   word num_class1a_errors;

   /**
   Number of class 1b bits in this data block.  For full rate speech this
   will be set to 132.
   */
   word num_class1b_bits;

   /**
   Number of errors in the class 1b bits.
   */
   word num_class1b_errors;

   /**
   Number of class 2 bits in this data block.  For full rate speech this
   will be set to 78.
   */
   word num_class2_bits;

   /**
   Number of errors in the class 2 bits.
   */
   word num_class2_errors;
} FTM_SE_BER_TYPE_II_RESPONSE_Struct;

//! LOG STRUCT for WCDMA RMC 12.2kbps/64kbps, GSM Loop C  Types
typedef struct
{
   word ftm_log_id;
   byte se_ber_log_type;
   byte num_payloads;
   /**
   In the START SE BER LOG REQUEST sent prior to the start measurement, the number of frames per log or
   num payloads is configured which is also returned in the response packet.
   \code
   8 -?Send a BER log packet every 8 data blocks processed.
   16 -?Send a BER log packet every 16 data blocks processed.
   32 -- Send a BER log packet every 32 data blocks processed.
   64 -- Send a BER log packet every 64 data blocks processed.
   \endcode
   */
   FTM_SE_BER_TYPE_I_RESPONSE_Struct resp_struct[64];
} FTM_SE_BER_TYPE_I_LOG_Struct;

//! LOG STRUCT for GSM Loop A/B  Types
typedef struct
{
   word ftm_log_id;
   byte se_ber_log_type;
   byte num_payloads;
   /**
   In the START SE BER LOG REQUEST sent prior to the start measurement, the number of frames per log or num
   payloads is configured which is also returned in the response packet.
   \code
   8 -?Send a BER log packet every 8 data blocks processed.
   16 -?Send a BER log packet every 16 data blocks processed.
   32 -- Send a BER log packet every 32 data blocks processed.
   64 -- Send a BER log packet every 64 data blocks processed.
   \endcode
   */
   FTM_SE_BER_TYPE_II_RESPONSE_Struct resp_struct[64];
} FTM_SE_BER_TYPE_II_LOG_Struct;

//!  Statistics structure to hold the BER and good frame ratios.
typedef struct
{
   double BER;          //!< BER for LB WCDMA RMC 12.2Mbps/64Mbps, GSM Loop C types.
   double BER_1a;       //!< BER for LB 1a bits of GSM Loop A/B Types.
   double BER_1b;       //!< BER for LB 1b bits of GSM Loop A/B Types.
   double BER_2;        //!< BER for LB 2 bits of GSM Loop A/B Types.
   double RBER_1a;      //!< Residual BER for LB 1a bits of GSM Loop A/B Types.
   double RBER_1b;      //!< Residual BER for LB 1b bits of GSM Loop A/B Types.
   double RBER_2;       //!< Residual  BER for LB 2 bits of GSM Loop A/B Types.
   double frame_erasure_ratio;   //!< Frame erasure ratio for GSM Loop A/B types.
} SE_BER_Statistics;

//!<  Measurement struct that holds the current status for SE BER measurements.
typedef struct
{
   dword frames_received;   //!< Number of frames recieved.
   dword frames_valid;      //!< Number of valid frames, decided from the pnstate state of each frame.
   dword frames_invalid;    //!< Number of invalid frames, decided from the pnstate state of each frame.
   dword bad_frame_indicator_accum; //!<     BFI from each frame is summed up
   dword bits_counted;      //!<Total number of bits in this data block, applicable for RMC 12.2K,64K,GSM Loop C types.
   dword errors_counted;    //!<Total number of errors, applicable for RMC 12.2K,64K,GSM Loop C types.
   dword bits_counted_1a;   //!<Total number of class 1a bits in this data block.  For full rate speech this will be
   //!< set to 50 for each frame, applicable for GSM A/B types.
   dword errors_counted_1a; //!<Total number of errors in the class 1a bits, applicable for GSM A/B types.
   /**
   Total number of class 1b bits in this data block.  For full rate speech this will be
   set to 132 for each frame, applicable for GSM A/B types.
   */
   dword bits_counted_1b;

   dword errors_counted_1b;  //!<Total number of errors in the class 1b bits, applicable for GSM A/B types.

   /**
   Total number of class 2 bits in this data block.  For full rate speech this will be
   set to 78 for each frame, applicable for GSM A/B types.
   */
   dword bits_counted_2;
   dword errors_counted_2;             //!<Total number of errors in the class 2 bits, applicable for GSM A/B types.
   /**
   Total number of residual class 1a bits in this data block.  For full rate speech this will be
   set to 50 for each frame, applicable for GSM A/B types.
   */
   dword residual_bits_counted_1a;

   /**
   Total number of errors in the residual class 1a bits, applicable for GSM A/B types.
   */
   dword residual_errors_counted_1a;

   /**
   Total number of residual class 1b bits in this data block.  For full rate speech this will be
   set to 132 for each frame, applicable for GSM A/B types.
   */
   dword residual_bits_counted_1b;

   /**
   Total number of errors in the residual class 1b bits, applicable for GSM A/B types.
   */
   dword residual_errors_counted_1b;

   /**
   Total number of residual class 2 bits in this data block.  For full rate speech this will be
   set to 78 for each frame, applicable for GSM A/B types.
   */
   dword residual_bits_counted_2;

   /**
   Total number of errors in the residual class 2 bits, applicable for GSM A/B types.
   */
   dword residual_errors_counted_2;

   /**
   BER and good frame ratio struct.
   */
   SE_BER_Statistics ber_stats;

   /**
   contains the loopback type information.
   */
   log_FTM2_SE_BER_Loopback_Type_enum eSE_BER_Loopback_Type;
} SE_BER_Status;

/******************************************************************************
QMSL - Time Out defintions
*******************************************************************************/

/**
Enumeration of time-out values that can be set / retrieved using
QLIB_ConfigureTimeOut() and QLIB_GetTimeOut()

*/
typedef enum
{
   // Timeouts for Diag_FTM area
   QMSL_Timeout_General,            //!< 'General communications time out, used for SendSync()  (4,000ms default)
   QMSL_Timeout_IsPhoneConnected,   //!< 'Timeout when connecting IsPhoneConnected() command (80ms default)
   QMSL_Timeout_Connect,            //!< 'Timeout for connecting to a phone the first time (200ms default)

   QMSL_Timeout_Nonsignaling,       //!< 'Non-signaling timeout (1,000ms default)

   QMSL_Timeout_GSDI,               //!< 'Timeout to be used for GSDI commands (6,000ms default)
   QMSL_Timeout_CNV,                //!< 'Timeout to be used for preparation of CNV (default 10,000ms)

   QMSL_Timeout_CDMA_FreqSweep, //!< 'Timeout to be used for CDMA Tx Rx Frequency Sweep (default 10,000ms)

   QMSL_Timeout_WriteData,          //!< 'Timeout to be used for writing data to a communications device,
   //!< ' does not include read back of response (default 900ms)
   //!< ' this cannot be set in QPST mode.

   QMSL_Timeout_ReadData,           //!< 'Timeout to be used for reading data from a communications device,
   //!< ' this timeout is only for the low level read operation and does not
   //!< ' consider the call context, such as whether a synchronous command is
   //!< ' currently being executed.  Default is 500ms

   QMSL_Timeout_GSDI_Event,     //!< 'Timeout to be used when waiting for a GSDI Diag event
   //!< ' Default is 3000ms

   QMSL_Timeout_CGPS_Event,     //!< 'Timeout to be used when waiting for events relatd to CGPS functions
   //!< ' Default is 10000ms

   /*
   Below this are configurable delays for the Diag_FTM area
   */

   /**
   Delay when switching from ONLINE-FTM mode.  This is needed
   for some targets because they do not process FTM commands
   immediately after going into FTM mode.  A recommended value
   is 200ms, but the default value is 0ms for backwards compatability.

   This is used in the function QLIB_DIAG_CONTROL_F()
   */
   QMSL_Timeout_Delay_ONLINE_FTM,

   /**
   Delay when switching to ONLINE mode.  This is needed
   because it often takes some time for the AMSS to change modes.
   Default is 0ms

   This is used in the function QLIB_DIAG_CONTROL_F()
   */
   QMSL_Timeout_Delay_ONLINE,

   /**
   Delay when switching to OFFLINE mode.  This is needed
   because it often takes some time for the AMSS to change modes, for example
   a power down registration must be done for some systems.
   Default is 3000ms

   This is used in the function QLIB_ChangeFTM_BootMode() and
   in QLIB_DIAG_CONTROL_F().
   */
   QMSL_Timeout_Delay_OFFLINE,

   /**
   This delay will be used when the mobile enters a GSM RF mode
   */
   QMSL_Timeout_Delay_GSM_RF_Mode,

   /**
   This delay will be used by QLIB_MFLO_GetPER_Phy() and QLIB_MFLO_GetPER_PhyMAC(),
   to set the delay between checking FLO status.  Default value is 100ms

   QLIB_MFLO_GetPER_Phy() uses this value to set the timeout when waiting for
   a status log.

   QLIB_MFLO_GetPER_PhyMAC() uses the value as the duration between the calls
   to poll the phone for status.

   This delay will be used by QLIB_MFLO_GetPER_Phy() and QLIB_MFLO_GetPER_PhyMAC(),
   to set the delay between checking FLO status.  Default value is 100ms.

   QLIB_MFLO_GetPER_Phy() uses this value as the duration between calls to get the
   stats when the stats are not updating.

   QLIB_MFLO_GetPER_PhyMAC() uses the value as the duration between the calls
   to get the next log packet from the queue when the queue is empty.
   */
   QMSL_Timeout_Delay_MediaFLO_StatusCheck,

   /**
   Timeout in ms for collecting async IQ log from ICI calibration

   This timeout is used by QLIB_FTM_GET_ICI_CAL_DATA()
   */
   QMSL_Timeout_ICI_IQ_Data,
   /**
   Timeout in ms for waiting for BT HCI response

   This timeout is used by QLIB_FTM_BT_HCI_USER_CMD_WithEventResponse
   */
   QMSL_Timeout_BT_HCI_Response,

   /**
   Timeout in ms for phone to complete runtime mode switching,
   valid only if the desired mode is Online, FTM , Offline, LPM, default value is 5000ms

   This timeout is used by QLIB_DIAG_CONTROL_F
   */
   QMSL_Timeout_Runtime_Mode_Switching,

   /**
   Timeout in ms for QMSL to return if the queue execution complete message is never received from embedded side

   Default is 10s (10000 ms)
   This timeout is used by QLIB_FTM_SEQ_EXECUTE_QUEUE
   */
   QMSL_Timeout_Embedded_Sequencer_Execution,

   // Note to QMSL developers, new delays and timeouts should be added here, before the
   // the SW Download timouts

   // Timeout for software download
   /**
   Timeout for the duration of the next softare download action.
   For example, a download that should take 7 minutes, the timeout can be set to 8 minutes.
   Default will be 10 minutes ( 10 minutes * 60seconds/minute * 1000milliseconds/secon = 600000ms
   */
   QMSL_Timeout_SoftwareDownloadActivity,

   QMSL_Timeout_ListSizeMax     //!< 'Not a timeout, just used to determine timeout list size
} QMSL_TimeOutType_Enum;

typedef enum
{
   XPT_SEQ_PASS,
   /*!< XPT sequence Error code  : pass */
   XPT_SEQ_PARAMS_INVALID,
   /*!< XPT sequence Error code  : Parameter validation failed. */
   XPT_SEQ_SM_FAILURE,
   /*!< XPT sequence Error code  : State machine failure. Wrong state or Wrong event received in a state. */
   XPT_SEQ_MEM_ALLOC_FAILURE,
   /*!< XPT sequence Error code  : Memory allocation failure .  */
   XPT_SEQ_API_FAILURE,
   /*!< XPT sequence Error code  : Status of internal API returned false.  */
   XPT_SEQ_RGI_DELTA_MISSING,
   /*!< XPT sequence Error code  : RGI Delta not available.  */
   XPT_STG1_PWR_LIM_FAILURE,
   /*!< XPT sequence Error code  : STG1 Powers measured failing limit. */
   XPT_STG1_CAPT_FAILURE,
   /*!< XPT sequence Error code  : STG1 Captures failed. No results available */
   XPT_STG1_PROC_FAILURE,
   /*!< XPT sequence Error code  : STG1 Processing failed. No results available */
   XPT_STG1_RESERVED = 0x20,
   /*!< XPT sequence Error code  : Error codes reserved for other failures in STG1.  */
   XPT_MLINE_FAILURE,
   /*!< XPT sequence Error code  : Mline failure. For detail look in mline result packet debug mask.*/
   XPT_STG2_CAPT_FAILURE,
   /*!< XPT sequence Error code  : STG2 Captures failed. No results available */
   XPT_STG2_PROC_FAILURE,
   /*!< XPT sequence Error code  : STG2 Processing failed. No results available */
   XPT_RESULT_CODE_MAX = 0xFFFF
} xpt_result_code;

#define LTE_MAX_NUM_TX_PATHS 4
#define LTE_MAX_NUM_RX_PATHS 4
#define LTE_MAX_NUM_CA_RX_PATHS 10
#define LTE_MAX_NUM_RX_HORXD_PATHS 24

typedef struct
{
   byte iVersion;
   byte iTx_Chain;
   byte iStart_RB_Index;
   byte iNum_RBs;
   byte iPA_STATE;
   word iTx_Gain_Index;
   long iTx_AGC;  /* Tx AGC value*/
   long iTx_Freq_Comp;
   long iTx_Temp_Comp;
   long iMTPL;    /* Max Tx Power Limit */
   word iIQ_Gain; /* Digital IQ gain scaling */
   byte iMPR;
   byte iAMPR;
   byte iNS_Value;
   word iSAR_MTPL;
   byte iHDET_Mode;
   word iHDET_ADC;
   signed short iHDET_dBm;
   word iThemistor;
   byte iScaledThermistor;
   byte iTempCompIndex;
   byte iTempCompRemainder;
} FTM2LogMessage_LTE_Tx_AGC_Datapath;

/* This type specifies the data packet associated with the Tx LTE AGC ENH log */
typedef struct
{
   byte iVersion;
   byte iTx_Chain;
   byte iStart_RB_Index;
   byte iNum_RBs;
   byte iPA_STATE;
   word iTx_Gain_Index;
   long iTx_AGC;  /* Tx AGC value*/
   long iTx_Freq_Comp;
   long iTx_Temp_Comp;
   long iMTPL;    /* Max Tx Power Limit */
   word iIQ_Gain; /* Digital IQ gain scaling */
   byte iMPR;
   byte iAMPR;
   byte iNS_Value;
   word iSAR_MTPL;
   byte iHDET_Mode;
   word iHDET_ADC;
   signed short iHDET_dBm;
   word iThemistor;
   byte iScaledThermistor;
   byte iTempCompIndex;
   byte iTempCompRemainder;
   uint16 pa_smps_pdm;     /* Raw 10 bit PA SMPS value used by FW */
} FTM2LogMessage_LTE_Tx_Enh_AGC_Datapath;

typedef struct
{
   uint8 current_xpt_mode;
   boolean et_flag;
   boolean xpt_transition;
   uint8 dpd_cfg;
   uint8 am_tbl_size;
   uint8 pm_tbl_size;
   uint8 det_tbl_size;
   uint16 am_offsets;
   uint16 am_bank_id;
   uint16 pm_offsets;
   uint16 pm_bank_id;
   uint16 det_offsets;
   uint16 det_bank_id;
   uint16 iq_gain_lut;
   int32 p_out_comp;
   int32 p_in_comp;
   uint32 selected_rgi_with_pout;
   uint32 selected_rgi_with_pin;
   uint32 env_scale_backoff;
   uint32 iq_backoff;
   int32  delay;
   uint32 dpd_indx;
   uint8 pa_icq_val;
} FTM2LogMessage_LTE_Tx_XPT_DataPath;

typedef struct
{
   byte             iNumTxPaths;
   FTM2LogMessage_LTE_Tx_AGC_Datapath datapath[LTE_MAX_NUM_TX_PATHS];
} FTM2LogMessage_LTE_Tx_AGC;

typedef struct
{
   byte              iVersion;
   byte              iRx_Chain;
   byte              iLNA_STATE;
   signed short      iRX_AGC;
} FTM2LogMessage_LTE_Rx_AGC_Datapath;

typedef struct
{
   byte             iNumRxPaths;
   FTM2LogMessage_LTE_Rx_AGC_Datapath datapath[LTE_MAX_NUM_RX_PATHS];
} FTM2LogMessage_LTE_Rx_AGC;

typedef struct
{
   byte              iVersion;
   byte              iRx_Chain;
   byte              iLNA_STATE;
   signed short      iRX_AGC;
   unsigned int      reserved;
} FTM2LogMessage_LTE_CA_Enabled_Rx_AGC_Datapath;

typedef struct
{
   byte iNumRxPaths;
   FTM2LogMessage_LTE_CA_Enabled_Rx_AGC_Datapath datapath[LTE_MAX_NUM_CA_RX_PATHS];
} FTM2LogMessage_LTE_CA_Enabled_Rx_AGC;

typedef struct
{
   byte iNumRxPaths;
   FTM2LogMessage_LTE_CA_Enabled_Rx_AGC_Datapath datapath[LTE_MAX_NUM_RX_HORXD_PATHS];
} FTM2LogMessage_LTE_HORXD_Enabled_Rx_AGC;

/* This type specifies the data packet for all Tx chains in the LTE Tx AGC log */
typedef struct
{
   uint8 iNumTxPaths;
   FTM2LogMessage_LTE_Tx_Enh_AGC_Datapath datapath[MAX_NUM_TX_PATHS];
   FTM2LogMessage_LTE_Tx_XPT_DataPath xpt_path[MAX_NUM_TX_PATHS];
} FTM2LogMessage_LTE_Tx_AGC_Enh;

/* This type specifies the data packet for all Tx chains in the LTE Tx AGC Enh log Ver0 used for Nikel*/
typedef struct
{
   uint8 iNumTxPaths;
   FTM2LogMessage_LTE_Tx_Enh_AGC_Datapath datapath[MAX_NUM_TX_PATHS];
} FTM2LogMessage_LTE_Tx_AGC_Enh_Ver0;

typedef struct
{
   uint8 iNumTxPaths;
   FTM2LogMessage_LTE_Tx_Enh_AGC_Datapath datapath[MAX_NUM_TX_PATHS];
   FTM2LogMessage_LTE_Tx_XPT_DataPath xpt_path[MAX_NUM_TX_PATHS]; //this is the structure you pointed to
   uint32 ext_pa_icq_val[MAX_NUM_TX_PATHS]; //this is the new field
} FTM2LogMessage_LTE_Tx_AGC_Enh_V3;

//!<  Measurement struct that holds the current status for LTE PDSCH measurements.
typedef struct
{
   double m_crc_pass;
   double m_crc_fail;
   double m_bytes_recieved;
   double m_num_log_pkts;
   double m_mcs;
   double num_sub_frames;
   // params
   unsigned char earlyTermination;

   // results
   double tPut;
   double tPut_pctFromPeak;
   int measCount;

   unsigned char version_supported;
   unsigned char packet_version;
} LTE_PDSCH_BLER_Status;

/******************************************************************************
LTE PDSCH V1 Packet
*******************************************************************************/
// --------------------------------------------------------------------------
// lte_pdschstatindication_v1_record_transport_block
//
// --------------------------------------------------------------------------
typedef struct
{
   unsigned char harq_id:4;                                         ///< Harq ID 36.213 sec. 7 (up to 8 for FDD (0 -7), up to 15 for TDD (0-14))
   unsigned char rv:2;                                              ///< Redundancy version (0 , 1, 2, 3)
   unsigned char ndi:1;                                             ///< New data indicator (0 or 1)
   unsigned char crc_result:1;
   unsigned char rnti_type:4;
   unsigned char tb_index:1;                                        ///< The transport block index where 2 transport blocks are received with the       same rnti (for MIMO) Index  [0 , 1] will be present to represent TB with same RNTI otherwise 0 by default
   unsigned char discarded_retx_present:1;                          ///< Discarded retransmission: Additional retransmission of already received       data due to ack->nak misdetection
   unsigned char reserved:2;
   unsigned long tb_size:14;                                       ///< Transport block size in bytes
   unsigned long reserved0:2;
   unsigned char mcs;                                               ///< MCS index
   ///< Range: 0 <= mcs <= 31
   unsigned char reserved1;
} lte_pdschstatindication_v1_record_transport_block;

// --------------------------------------------------------------------------
// lte_pdschstatindication_v1_record
//
// --------------------------------------------------------------------------
typedef struct
{
   unsigned short subframe_num:4;                                   ///< OTA tx subframe number 0 < = range <= 9
   unsigned short frame_num:12;                                     ///< OTA tx frame number 0 <= range <= 1023
   unsigned char num_rbs;                                           ///< Number of rbs allocated Range: 0 < num rbs <= 100
   unsigned char num_layers;                                        ///< Number of layers Range:  1<= num layers <= 4
   unsigned short num_transport_blocks_present:8;                   ///< 0 <= range <= 3
   unsigned short reserved:8;
   lte_pdschstatindication_v1_record_transport_block transport_blocks[2];//< Note that the original ML1 PDSCH Packet specifies the number of
   //< of the transport_blocks as 1. Making the size 2 to support the
   //< byte misalignment.
   unsigned short rsvd_for_byte_align_tools_code;                   //< Note that the original ML1 PDSCH Packet does not contain
   //< this. This was added to fix the byte misalignment.
} lte_pdschstatindication_v1_records;

//! LOG STRUCT for LTE PDSCH  Types
typedef struct
{
   unsigned long version:8;                                        ///< Log packet version
   unsigned long num_records:8;                                    ///< Number of records present in the log packet  0 < Range <= 25
   unsigned long reserved:16;
   lte_pdschstatindication_v1_records records[25];
} LTE_PDSCH_LOG_Struct_V1;

/******************************************************************************
LTE PDSCH V2 Packet
*******************************************************************************/
// --------------------------------------------------------------------------
// lte_pdschstatindication_v2_record
//
// --------------------------------------------------------------------------
typedef struct
{
   /*! ********** PDSCH stat per record **************/

   /* OTA Tx time stamp */
   unsigned short    subframe_num:4;                   ///< 0 ~9     //32bit word1 start
   unsigned short    frame_num:12;                     ///< radio frame number 0-1023

   unsigned short num_rbs:8;                           ///< number or rbs allocated
   unsigned short num_layers:8;                        ///< number of layers
   //32bit word1 end

   /*! Num of transport blocks present or valid */
   unsigned short    num_trbs_present:8;
   unsigned short    reserved0:8;

   /*! FIXED SIZE ALLOACTION based on "LTE_LL1_MAX_PDSCH_TRANMISSIONS_PER_TTI" */
   struct                                                //32bit word 2 - 5.5  start
   {
      unsigned char     harq_id:4;                       ///< (up to 8 for FDD, up to 15 for TDD)
      unsigned char     rv:2;                            ///< (0, 1, 2, 3)
      unsigned char     ndi:1;                           ///< (0 or 1)
      unsigned char     crc_result:1;

      unsigned char     rnti_type:4;
      unsigned char     tb_index:1;                      ///< (0 or  1 (MIMO))
      unsigned char     pdsch_result_discard_retx:1;
      unsigned char     reserved1:2;

      unsigned short    trblk_size:14;                 /// Size in bytes
      unsigned short    reserved2:2;                                  //32 bit word end

      unsigned short    mcs:8;                          ///< ( MCS index 0 - 31)
      unsigned short    reserved3:8;
   } tb[3];
   //32bit word 2 - 5.5  end
} lte_ml1_log_dlm_pdsch_stat_record_v2;

//! LOG STRUCT for LTE PDSCH  Types
typedef struct
{
   unsigned long version:8;                                        ///< Log packet version
   unsigned long num_records:8;                                    ///< Number of records present in the log packet  0 < Range <= 25
   unsigned long reserved:16;
   lte_ml1_log_dlm_pdsch_stat_record_v2 records[25];
} LTE_PDSCH_LOG_Struct_V2;

/******************************************************************************
LTE PDSCH V3 Packet
*******************************************************************************/
/*! @brief DLM pdsch stat record log structure  = 2 + 2 + 2 + 3* [6] = 24 bytes
*/
typedef struct
{
   /*! ********** PDSCH stat per record **************/

   /* OTA Tx time stamp */
   unsigned short    subframe_num:4;                   ///< 0 ~9     //32bit word1 start
   unsigned short    frame_num:12;                     ///< radio frame number 0-1023

   unsigned short num_rbs:8;                           ///< number or rbs allocated
   unsigned short num_layers:8;                        ///< number of layers
   //32bit word1 end

   /*! Num of transport blocks present or valid */
   unsigned short    num_trbs_present:8;
   unsigned short    reserved0:8;

   /*! FIXED SIZE ALLOACTION based on "LTE_LL1_MAX_PDSCH_TRANMISSIONS_PER_TTI" */
   struct                                                //32bit word 2 - 5.5  start
   {
      unsigned char     harq_id:4;                       ///< (up to 8 for FDD, up to 15 for TDD)
      unsigned char     rv:2;                            ///< (0, 1, 2, 3)
      unsigned char     ndi:1;                           ///< (0 or 1)
      unsigned char     crc_result:1;

      unsigned char     rnti_type:4;
      unsigned char     tb_index:1;                      ///< (0 or  1 (MIMO))
      unsigned char     pdsch_result_discard_retx:1;
      unsigned char     did_recomb:1;
      unsigned char     reserved1:1;

      unsigned short    trblk_size:14;                 /// Size in bytes
      unsigned short    reserved2:2;                                  //32 bit word end

      unsigned short    mcs:8;                          ///< ( MCS index 0 - 31)
      unsigned short    reserved3:8;
   } tb[3];
   //32bit word 2 - 5.5  end
} lte_ml1_log_dlm_pdsch_stat_record_v3;

//! LOG STRUCT for LTE PDSCH  Types
typedef struct
{
   unsigned long version:8;                                        ///< Log packet version
   unsigned long num_records:8;                                    ///< Number of records present in the log packet  0 < Range <= 25
   unsigned long reserved:16;
   lte_ml1_log_dlm_pdsch_stat_record_v3 records[25];
} LTE_PDSCH_LOG_Struct_V3;

/******************************************************************************
LTE PDSCH V4 Packet
*******************************************************************************/
typedef struct
{
   /*! ********** PDSCH stat per record **************/

   /* OTA Tx time stamp */
   unsigned short    subframe_num:4;                   ///< 0 ~9     //32bit word1 start
   unsigned short    frame_num:12;                     ///< radio frame number 0-1023

   unsigned short num_rbs:8;                           ///< number or rbs allocated
   unsigned short num_layers:8;                        ///< number of layers
   //32bit word1 end

   /*! Num of transport blocks present or valid */
   unsigned short    num_trbs_present:8;
   unsigned short    reserved0:8;

   /*! FIXED SIZE ALLOACTION based on "LTE_LL1_MAX_PDSCH_TRANMISSIONS_PER_TTI" */
   struct                                                //32bit word 2 - 5.5  start
   {
      unsigned char     harq_id:4;                       ///< (up to 8 for FDD, up to 15 for TDD)
      unsigned char     rv:2;                            ///< (0, 1, 2, 3)
      unsigned char     ndi:1;                           ///< (0 or 1)
      unsigned char     crc_result:1;

      unsigned char     rnti_type:4;
      unsigned char     tb_index:1;                      ///< (0 or  1 (MIMO))
      unsigned char     pdsch_result_discard_retx:1;
      unsigned char     did_recomb:1;
      unsigned char     reserved1:1;

      unsigned short    trblk_size:14;                 /// Size in bytes
      unsigned short    reserved2:2;                                  //32 bit word end

      unsigned short    mcs:8;                          ///< ( MCS index 0 - 31)
      unsigned short    num_rbs:8;                      ///< number of rbs allocated to this tb
   } tb[3];

   unsigned short      pmch_id:8;     ///< PMCH id: only applicable to pmch decodes
   unsigned short      area_id:8;     ///< Area id used: only applicable to pmch decodes  //32bit word 2 - 6  end
} lte_ml1_log_dlm_pdsch_stat_record_v4;

//! LOG STRUCT for LTE PDSCH  Types (V4)
typedef struct
{
   unsigned long version:8;                                        ///< Log packet version
   unsigned long num_records:8;                                    ///< Number of records present in the log packet  0 < Range <= 25
   unsigned long reserved:16;
   lte_ml1_log_dlm_pdsch_stat_record_v4 records[25];
} LTE_PDSCH_LOG_Struct_V4;

//! LOG STRUCT for LTE PDSCH  Types (V4)
typedef struct
{
   unsigned long version:8;                                        ///< Log packet version
   unsigned long num_records:8;                                    ///< Number of records present in the log packet  0 < Range <= 25
   unsigned long reserved:16;
} LTE_PDSCH_LOG_Struct_Header;

typedef struct
{
   unsigned short iSourceTech;
   unsigned short iSourceBand;
   unsigned short iSourceChannel;
   unsigned short iSourceBandwidth;
   unsigned short iSourceDiversityEnable;
   unsigned short iSourceBufferIndex;
   unsigned short iTargetTech;
   unsigned short iTargetBand;
   unsigned short iTargetChannel;
   unsigned short iTargetBandwidth;
   unsigned short iTargetDiversityEnable;
   unsigned short iTargetBufferIndex;
   unsigned short iTestLevel;
} lte_ftm_xtoy_test_params;

typedef struct
{
   unsigned short iSourceTech;
   unsigned short iSourceBand;
   unsigned short iSourceChannel;
   unsigned short iSourceBandwidth;
   unsigned short iSourceDiversityEnable;
   unsigned short iSourceBufferIndex;
   unsigned short iTargetTech;
   unsigned short iTargetBand;
   unsigned short iTargetChannel;
   unsigned short iTargetBandwidth;
   unsigned short iTargetDiversityEnable;
   unsigned short iTargetBufferIndex;
   unsigned short iCarrier1enabled; //additon of CA parameters
   unsigned short iCarrier1band;
   unsigned short iCarrier1channel;
   unsigned short iCarrier1Bandwidth;
   unsigned short iCarrier1DiversityEnable;
   unsigned short iTestLevel;
} lte_ftm_xtoy_test_params_v2;

typedef struct
{
   unsigned short iSourceTech;

   unsigned short iSourceCarrierPath0Device;
   unsigned short iSourceCarrierPath0Band;
   unsigned short iSourceCarrierPath0CarrierType;
   unsigned short iSourceCarrierPath0ChannelCar0;
   unsigned short iSourceCarrierPath0ChannelCar1;
   unsigned short iSourceCarrierPath0ChannelCar2;
   unsigned short iSourceCarrierPath0Bandwidth;
   unsigned short iSourceCarrierPath0DiversityEnable;
   unsigned short iSourceCarrierPath0DiversityDeviceID1;
   unsigned short iSourceCarrierPath0DiversityDeviceID2;
   unsigned short iSourceCarrierPath0DiversityDeviceID3;
   unsigned short iSourceCarrierPath0TxEnable;
   unsigned short iSourceCarrierPath0TxDevice;

   unsigned short iTargetTech;
   unsigned short iTargetDevice;
   unsigned short iTargetBand;
   unsigned short iTargetChannel;
   unsigned short iTargetBandwidth;
   unsigned short iTargetDiversityEnable;
   unsigned short iTargetDiversityDevice;

   unsigned short iTestLevel;

   unsigned short iSourceCarrierPath1FlagEnable;
   unsigned short iSourceCarrierPath1Device;
   unsigned short iSourceCarrierPath1Band;
   unsigned short iSourceCarrierPath1CarrierType;
   unsigned short iSourceCarrierPath1ChannelCar0;
   unsigned short iSourceCarrierPath1ChannelCar1;
   unsigned short iSourceCarrierPath1ChannelCar2;
   unsigned short iSourceCarrierPath1Bandwidth;
   unsigned short iSourceCarrierPath1DiversityEnable;
   unsigned short iSourceCarrierPath1DiversityDeviceID1;
   unsigned short iSourceCarrierPath1DiversityDeviceID2;
   unsigned short iSourceCarrierPath1DiversityDeviceID3;
   unsigned short iSourceCarrierPath1TxEnable;
   unsigned short iSourceCarrierPath1TxDevice;

   unsigned short iSourceCarrierPath2FlagEnable;
   unsigned short iSourceCarrierPath2Device;
   unsigned short iSourceCarrierPath2Band;
   unsigned short iSourceCarrierPath2CarrierType;
   unsigned short iSourceCarrierPath2ChannelCar0;
   unsigned short iSourceCarrierPath2ChannelCar1;
   unsigned short iSourceCarrierPath2ChannelCar2;
   unsigned short iSourceCarrierPath2Bandwidth;
   unsigned short iSourceCarrierPath2DiversityEnable;
   unsigned short iSourceCarrierPath2DiversityDeviceID1;
   unsigned short iSourceCarrierPath2DiversityDeviceID2;
   unsigned short iSourceCarrierPath2DiversityDeviceID3;
   unsigned short iSourceCarrierPath2TxEnable;
   unsigned short iSourceCarrierPath2TxDevice;

} ftm_meas_xtoy_test_params_v3;

typedef struct
{
   unsigned short iTargetTech;
   unsigned short iTargetDevice;
   unsigned short iTargetBand;
   unsigned short iTargetChannel;
   unsigned short iTargetBandwidth;
   unsigned short iTargetDiversityEnable;
   unsigned short iTargetDiversityDevice;

   unsigned short iTestLevel;

} ftm_meas_null_2x_script;

typedef struct
{
   unsigned short iFxTech;
   unsigned short iFxDevice;
   unsigned short iFxBand;
   unsigned short iFxChannel;
   unsigned short iFxBandwidth;
   unsigned short iFxDiversityEnable;
   unsigned short iFxDiversityDevice;

   unsigned short iFyTech;
   unsigned short iFyDevice;
   unsigned short iFyBand;
   unsigned short iFyChannel;
   unsigned short iFyBandwidth;
   unsigned short iFyDiversityEnable;
   unsigned short iFyDiversityDevice;

   unsigned short iTestLevel;

} ftm_meas_half_script;

typedef struct
{
   unsigned short rxagc_error_response;

   unsigned short CAPath_0_device_rxagc_car0;
   unsigned short CAPath_0_device_rxagc_car1;
   unsigned short CAPath_0_device_rxagc_car2;
   unsigned short CAPath_0_div_device1_rxagc_car0;
   unsigned short CAPath_0_div_device1_rxagc_car1;
   unsigned short CAPath_0_div_device1_rxagc_car2;
   unsigned short CAPath_0_div_device2_rxagc_car0;
   unsigned short CAPath_0_div_device2_rxagc_car1;
   unsigned short CAPath_0_div_device2_rxagc_car2;
   unsigned short CAPath_0_div_device3_rxagc_car0;
   unsigned short CAPath_0_div_device3_rxagc_car1;
   unsigned short CAPath_0_div_device3_rxagc_car2;

   unsigned short CAPath_1_device_rxagc_car0;
   unsigned short CAPath_1_device_rxagc_car1;
   unsigned short CAPath_1_device_rxagc_car2;
   unsigned short CAPath_1_div_device1_rxagc_car0;
   unsigned short CAPath_1_div_device1_rxagc_car1;
   unsigned short CAPath_1_div_device1_rxagc_car2;
   unsigned short CAPath_1_div_device2_rxagc_car0;
   unsigned short CAPath_1_div_device2_rxagc_car1;
   unsigned short CAPath_1_div_device2_rxagc_car2;
   unsigned short CAPath_1_div_device3_rxagc_car0;
   unsigned short CAPath_1_div_device3_rxagc_car1;
   unsigned short CAPath_1_div_device3_rxagc_car2;

   unsigned short CAPath_2_device_rxagc_car0;
   unsigned short CAPath_2_device_rxagc_car1;
   unsigned short CAPath_2_device_rxagc_car2;
   unsigned short CAPath_2_div_device1_rxagc_car0;
   unsigned short CAPath_2_div_device1_rxagc_car1;
   unsigned short CAPath_2_div_device1_rxagc_car2;
   unsigned short CAPath_2_div_device2_rxagc_car0;
   unsigned short CAPath_2_div_device2_rxagc_car1;
   unsigned short CAPath_2_div_device2_rxagc_car2;
   unsigned short CAPath_2_div_device3_rxagc_car0;
   unsigned short CAPath_2_div_device3_rxagc_car1;
   unsigned short CAPath_2_div_device3_rxagc_car2;

} ftm_meas_rxagc;


/***********************************************

NLIC Enum and FTM commands

***********************************************/

typedef enum
{
   NLIC_HARMONIC_DELAY_CHAR,
   NLIC_HARMONIC_ANT_KER_CHAR,
   NLIC_IMD_DELAY_CHAR,
   NLIC_IMD_ANT_KER_CHAR,
   NLIC_INVALID_CHAR
} NLIC_SCENARIO_TYPE;

typedef enum
{
   NLIC_PARAMS_OVERRIDE_ACTION_NONE = 0,
   NLIC_PARAMS_OVERRIDE_ACTION_VALUE = 1,
   NLIC_PARAMS_OVERRIDE_ACTION_INVALID = 0xFF
} NLIC_PARAMS_OVERRIDE_ACTION_TYPE;

typedef struct
{
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE nlicOnOffActType;
   byte nlicOnOff;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE delayActType;
   word delayVal;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE kernelSelActType;
   word kernelVal;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE antennaSelActType;
   byte antennaVal;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE pccBandActType;
   byte pccBand;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE sccBandActType;
   byte sccBand;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE victimCarrierIndexActType;
   byte victimCarrierIndex;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE txPwrThresholdActType;
   byte txPwrThreshold;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE linearMActType;
   byte linearM;
   NLIC_PARAMS_OVERRIDE_ACTION_TYPE linearQActType;
   word linearQ;
} lte_nlic_override_params_info_verA;

typedef enum
{
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_SUCCESS = 0,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_GENERAL_FAILURE = 1,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_NULL_POINTER = 2,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_UE_NOT_IN_CORRECT_MODE = 3,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_UE_NOT_IN_RIGHT_STATE = 4,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_INCORRECT_INPUT_PARAMS = 5,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_INCORRECT_MEAS_TYPE = 6,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_FAILED_TO_SEND_FW_MSG = 7,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_RESULT_NOT_READY = 8,
   NLIC_CHAR_PARAMS_OVERRIDE_ACTION_MAX_ERROR = 0xFFFF
} NLIC_CHAR_PARAMS_OVERRIDE_ACTION_TYPE;

typedef struct
{
   byte Aggressor_carrier_idx;
   word Aggressor_band;
   word Aggressor_ul_channel;
   byte Aggressor_bw;
   byte Aggressor_start_rb;
   byte Aggressor_num_rbs;
   word Aggressor_tx_pwr;
   byte Victim_carrier_idx;
   word Victim_band;
   word Victim_dl_channel;
   byte Victim_bw;
   byte Other_carrier_idx;
   word Time_delay_int;
   word Time_delay_frac;
   byte Ant_sel;
   byte Num_kernels;
   byte Kernel_cfg[3];
   byte Number_of_taps;
   byte Interf_mechanism_coeff[7];
   byte Clock_mode;
}  nlic_override_harmonic_data;

typedef struct
{
   byte Aggressor1_carrier_idx;
   word Aggressor1_band;
   word Aggressor1_ul_channel;
   byte Aggressor1_bw;
   byte Aggressor1_start_rb;
   byte Aggressor1_num_rbs;
   word Aggressor1_tx_pwr;
   byte Aggressor2_carrier_idx;
   word Aggressor2_band;
   word Aggressor2_ul_channel;
   byte Aggressor2_bw;
   byte Aggressor2_start_rb;
   byte Aggressor2_num_rbs;
   word Aggressor2_tx_pwr;
   byte Victim_carrier_idx;
   word Victim_band;
   word Victim_dl_channel;
   byte Victim_bw;
   byte Tx_index;
   word Time_delay_int;
   word Time_delay_frac;
   word Time_IMD;
   byte Ant_sel;
   byte Num_kernels;
   byte Kernel_cfg[3];
   byte Number_of_taps;
   byte Interf_mechanism_coeff[7];
   byte Clock_mode;
}  nlic_override_imd_data;

typedef enum
{
   NLIC_CHAR_GET_RESULTS_ACTION_SUCCESS = 0,
   NLIC_CHAR_GET_RESULTS_ACTION_GENERAL_FAILURE = 1,
   NLIC_CHAR_GET_RESULTS_ACTION_NULL_POINTER = 2,
   NLIC_CHAR_GET_RESULTS_ACTION_UE_NOT_IN_CORRECT_MODE = 3,
   NLIC_CHAR_GET_RESULTS_ACTION_UE_NOT_IN_RIGHT_STATE = 4,
   NLIC_CHAR_GET_RESULTS_ACTION_INCORRECT_INPUT_PARAMS = 5,
   NLIC_CHAR_GET_RESULTS_ACTION_INCORRECT_MEAS_TYPE = 6,
   NLIC_CHAR_GET_RESULTS_ACTION_FAILED_TO_SEND_FW_MSG = 7,
   NLIC_CHAR_GET_RESULTS_ACTION_RESULT_NOT_READY = 8,
   NLIC_CHAR_GET_RESULTS_ACTION_MAX_ERROR = 0xFFFF
} NLIC_CHAR_GET_RESULTS_ACTION_TYPE;

typedef struct
{
   uint32 Delay_value[MAX_NUM_TX_PATHS];
   int32 Intf_pwr[MAX_NUM_TX_PATHS];
   int32 Kernerl_energy[MAX_NUM_TX_PATHS][MAX_NUM_KERNELS];
} nlic_char_meas_result_data;

typedef enum
{
   TX_LINEARIZER_VOICE,
   TX_LINEARIZER_SINGLE_CARRIER,
   TX_LINEARIZER_MULTI_CARRIER,
   TX_LINEARIZER_FIRST_SWEEP,
   TX_LINEARIZER_NUM_WAVEFORM_MAX,
} QMSL_Tx_Linearizer_Waveform_Type;

typedef struct
{
   /*! @brief Tx channel of the linearizer*/
   unsigned short tx_chan;
   /*! @brief RGI/LUT index */
   unsigned short rgi[TXLIN_NUM_SEGMENTS];
   /*! @brief TxAGC in dB10 */
   short  power[TXLIN_NUM_SEGMENTS];
   /*! @brief SMPS Bias */
   unsigned long apt[TXLIN_NUM_SEGMENTS];
} QMSL_Tx_Cal_Linearizer_Table_NV_Type;

typedef struct
{
   QMSL_Tx_Dpd_Poly_Coef_Type dpd[TXLIN_NUM_SEGMENTS];
} QMSL_Tx_Cal_DPD_Linearizer_Table_NV_Type;

typedef struct
{
   /*! @brief upper bound channl of which the linearizer will be used
   if upper_bound_chan = 0 then this node has no Cal data */
   unsigned short upper_bound_chan;
   /*! @brief memory offset of the dynamic linearizer table location from the end of fixed NV structure
   tx_band_cal_nv_type. Unit is per sizeof(tx_linearizer_table_nv_type)*/
   unsigned char table_offset;
} QMSL_Tx_Cal_Multi_Linearizer_Index_Node_NV_Type;

typedef struct
{
   /*! @brief upper bound channl of which the linearizer will be used
   if upper_bound_chan = 0 then this node has no Cal data */
   unsigned short upper_bound_chan;
   /*! @brief memory offset of the dynamic linearizer table location from the end of fixed NV structure
   tx_band_cal_nv_type. Unit is per sizeof(tx_linearizer_table_nv_type)*/
   unsigned char table_offset;
   /*! @brief table offset for the DPD table */
   unsigned char dpd_table_offset;
} QMSL_Tx_Cal_Multi_Linearizer_Index_Node_NV_Type_Rev2;

typedef QMSL_Tx_Cal_Multi_Linearizer_Index_Node_NV_Type tx_linearizer_index_type[TXLIN_NUM_CHANNELS];

typedef QMSL_Tx_Cal_Multi_Linearizer_Index_Node_NV_Type_Rev2 tx_linearizer_index_type_rev2[TXLIN_NUM_CHANNELS];

typedef struct
{
   /*! @brief 16 channel frequency compensation value */
   signed char freq_comp[TXLIN_NUM_CHANNELS];
   /*! @brief threshold of the RGI under which the freq comp will be applied
   if rgi_threshold = 0 then this bin has no valid freqcomp data */
   unsigned short rgi_threshold;
} QMSL_Tx_Cal_Freq_Offset_Row_NV_Type;

/*! @brief up to 8 bins in one PA state for different freq comp */
typedef QMSL_Tx_Cal_Freq_Offset_Row_NV_Type tx_freq_offset_table_type[TXLIN_NUM_FREQCOMP_RGI_BIN];

typedef struct
{
   /*! @brief Tx frequency compensation table */
   tx_freq_offset_table_type tx_freq_offsets;
   /*! @brief Linearizer index for all waveform types  */
   tx_linearizer_index_type linearizer_index[TX_LINEARIZER_NUM_WAVEFORM];
} QMSL_Tx_PA_State_Cal_Data_NV_Type;

typedef struct
{
   /*! @brief Tx frequency compensation table */
   tx_freq_offset_table_type tx_freq_offsets[TXLIN_NUM_FCOMP_SWEEP];
   /*! @brief Linearizer index for all waveform types  */
   tx_linearizer_index_type_rev2 linearizer_index[TX_LINEARIZER_NUM_WAVEFORM_REV2];
} QMSL_Tx_PA_State_Cal_Data_NV_Type_Rev2;

// Static/Fixed Sized Portion
typedef struct
{
   unsigned char reserved[8];
   /*! @brief Tx calibrated channel list */
   unsigned short tx_cal_chan[TXLIN_NUM_CHANNELS];
   /*! @brief Tx linearizer index for all PA gain statess */
   QMSL_Tx_PA_State_Cal_Data_NV_Type tx_pa_state_cal_data[TXLIN_NUM_LINEARIZERS];
} QMSL_Tx_Band_Cal_NV_Type;

typedef struct
{
   unsigned char reserved[8];
   /*! @brief Tx calibrated channel list */
   unsigned short tx_cal_chan[TXLIN_NUM_CHANNELS];
   /*! @brief Tx linearizer index for all PA gain statess */
   QMSL_Tx_PA_State_Cal_Data_NV_Type_Rev2 tx_pa_state_cal_data[TXLIN_NUM_LINEARIZERS];
} QMSL_Tx_Band_Cal_NV_Type_Rev2;

/*!Overall Structure */
typedef struct
{
   /*! @brief Tx calibrated channel list */
   QMSL_Tx_Band_Cal_NV_Type band_cal_data;
   /*! @brief Tx linearizer index for all PA gain statess */
   QMSL_Tx_Cal_Linearizer_Table_NV_Type tx_lin_data[TXLIN_NUM_TOTAL_LINEARIZERS];
   QMSL_RFCAL_NV_Item oTxCalNVItem;
} QMSL_Tx_Cal_Complete_NV_Type;

typedef struct
{
   /*! @brief Tx calibrated channel list */
   QMSL_Tx_Band_Cal_NV_Type_Rev2 band_cal_data;
   /*! @brief Tx linearizer index for all PA gain statess */
   QMSL_Tx_Cal_Linearizer_Table_NV_Type tx_lin_data[TXLIN_NUM_TOTAL_LINEARIZERS];
   QMSL_Tx_Cal_DPD_Linearizer_Table_NV_Type tx_dpd_lin_data[TXLIN_NUM_TOTAL_DPD_LINEARIZERS];
   QMSL_RFCAL_NV_Item oTxCalNVItem;
} QMSL_Tx_Cal_Complete_NV_Type_Rev2;

struct txpwr_apt_data_struct
{
   //! RGI as the key to the map
   unsigned long apt;

   //! Measured Power
   short power;

   //! EPT
   QMSL_Tx_Dpd_Poly_Coef_Type ept;
};

typedef struct
{
   unsigned short freq_comp_ref_ch_list[TXLIN_NUM_LINEARIZERS];
   unsigned short freq_comp_ch_list[TXLIN_NUM_CHANNELS];
   unsigned short freq_comp_rgi_list[TXLIN_NUM_LINEARIZERS][TXLIN_NUM_FREQCOMP_RGI_BIN];
   unsigned short freq_comp_bias_list[TXLIN_NUM_LINEARIZERS][TXLIN_NUM_FREQCOMP_RGI_BIN];
   unsigned short rgi_threshold_list[TXLIN_NUM_LINEARIZERS][TXLIN_NUM_FREQCOMP_RGI_BIN];
   unsigned short upper_bound_chan_list[TXLIN_NUM_LINEARIZERS][TX_LINEARIZER_NUM_WAVEFORM_REV2][TXLIN_NUM_CHANNELS];
   unsigned short ref_chan_list[TXLIN_NUM_LINEARIZERS][TX_LINEARIZER_NUM_WAVEFORM_REV2][TXLIN_NUM_CHANNELS];
} QMSL_Tx_Cal_NV_Gen_Info;

/*===========================================================================*/
/**
enum log_operation_id_enum_type

\brief List of log configuration operations
*/
typedef enum
{
   /*! @Check for device using diag loop back: _DIAG_PROTOCOL_LOOPBACK_F */
   device_chk_diag_lb = 0,
   /*! @Check for device using version number request: _DIAG_VERNO_F */
   device_chk_version = 1,
   /*! @Invalid */
   device_chk_invalid = 0xF
} QMSL_Device_Check_Enum;
/*===========================================================================*/

/*==========================================================================*/
//                     ESC PARSER DEFINITIONS
/*==========================================================================*/
// REQUEST PACKET STRUCTURES
typedef struct
{
   byte cmd;
   /*!< Command Identification */

   byte sub_sys;
   /*!< Sub-system Identification. For instance - 11 for FTM */

   word  mode;
   /*!< RF Mode Identification. For Instance - 0 for FTM_COMMON_C */

   word  cdma_cmd;
   /*!< FTM Sub Command. Example-  FTM_CALIBRATION_SWEEP */

   word req_len;
   /*!< Length of Diag Request Packet to the Target */

   word rsp_len;
   /*!< Length of response packet to Diag/PC */

   dword cal_param;
   /*!< Caibraiton Configuration Param */
} ftm_cal_sweep_config_req_pkt_type;

typedef struct
{
   byte start_cal_cmd;
   /*!< Start Calibration Sweep Command. This command will be used to trigger
   the calibration sweep after unpacking the calibraiton configuration data.
   If the Calibration command is sent without this flag set, the embedded
   driver will just unpack and calibration configuration data and store it. */

   byte last_sweep;
   /*!<
   @brief
   Flag indicating, if the Calibration configruation packet(CCP) is for the
   last sweep.

   @details
   This is a flag indicating, if the Calibration configruation packet(CCP) is for
   the last sweep. Based on this flag, RF tear down will be done.

   If the flag is FALSE, that means more calibration actions will be coming in
   future. Thus Radio will not be torn down. However, ceasing of ISR and
   dealloction of the configuration buffer and results buffer will be done for
   this flag. This puts a requirement on the tools side to send a result fetch
   command to embedded side before sending another CCP.

   If the flag is TRUE, this indicates that there will no more associated
   calibration actions. Thus tearing down of RF, ceasring ISR, dellocating
   buffers will be done.

   The main purpose of this flag is to support those call boxes which does not
   support multiple PA State power measurement in a single sweep. Thus, if
   the Tx Power Sweep on different PA states are distributed on various
   Cal sweep commands, then this flag will be useful not to tear down radio
   in between different PA state transition.
   */

   byte debug_mode;
   /*!< Flag indicating, if the debug mode is enabled or not. For debug mode,
   extra F3 debug messages will be sent to Tools*/

   word num_of_segments;
   /*!< Number of calibration segments/instances passed with this command. Based
   on this number, approripate dynamic memory allocation is done. */

   word tot_instr_size;
   /*!< Total size of all instruction(OpCode+Payload) from all segments. This
   will be used to perform dynamic memory allocation for configuration parameter
   storage. */

   word cal_data_len;
   /*!< Expected Length of Calibration Data for this payload */
} ftm_calibration_config_packet_header_type;

/*----------------------------------------------------------------------------*/
/*!
@brief
Structure to extract the Header from the Calibration Configuration Packet
*/
typedef struct
{
   ftm_calibration_config_packet_header_type packet_header;
   /*!< Calibration Configuration Packet Header */

   byte instr_ptr;
   /*!< RF Calibration Instruction which include opcode and Payload */
} ftm_calibration_config_packet_type;

/*----------------------------------------------------------------------------*/

typedef struct
{
   byte device_master;
   /*!< Master RF Device for which the RF is to be configured to. This is a bit
   mask, where each bit defines a master device. For instance. Bit 0 corresponds
   to RFM_DEVICE_0 */

   dword device_slave;
   /*!< Slave RF Device for which the RF is to be configured to. Each 4 bit
   define the slave device for a master device. If the 4 bit value is set to 0xF,
   that means, there is no slave device. */

   byte rf_mode;
   /*!< The RF Mode for which the RF Calibration is to be done. Supporting the
   Legacy definition, this variable will indicate the RF Tech and band on
   which the calibraiton is done. This will be later typecasted to
   ftm_mode_id_type. */

   word channel;
   /*!< The RF uplink channel to which the the Radio should be tuned to peform
   RF Calibration. For LTE, since downlink channel is different, software should
   calculate the downlink channel based on this uplink channel. */

   word rx_bandwidth;
   /*!< Bandwidth of the Rx Channel. This will be used by LTE only */

   word tx_bandwidth;
   /*!< Bandwidth of the Rx Channel. This will be used by LTE only */

   word dc_channel_offset;
   /*!< Channel/Frequency offset for Dual Carrier Calibration */
} ftm_cal_instr_payload_config_radio_type;

typedef struct
{
   byte device_master;
   /*!< Master RF Device for which the RF is to be retuned. This is a bit
   mask, where each bit defines a master device. For instance. Bit 0 corresponds
   to RFM_DEVICE_0 */

   word channel;
   /*!< The RF uplink channel to which the the Radio should be tuned to peform
   RF Calibration. For LTE, since downlink channel is different, software should
   calculate the downlink channel based on this uplink channel. */

   word dc_channel_offset;
   /*!< Channel offset for Dual Carrier Calibration */
} ftm_cal_instr_payload_retune_radio_type;

typedef struct
{
   byte waveform;
   /*!< The type of Tx Waveform to be used for Tx Measurement */

   byte num_of_rb;
   /*!< Number of LTE Resource Block for Tx Waveform. */

   byte start_rb;
   /*!< Starting Location of LTE Resource Block for Tx Waveform. */
} ftm_cal_instr_payload_config_tx_wf_type;

typedef struct
{
   byte cal_action;
   /*!<
   @brief
   The transmit calibration actions.

   @details
   This indicates the Tx action to be performed with this opcode
   on a given segment.Tx Action definitions can be found in
   #ftm_calibration_tx_action_enum_type.
   */

   byte pa_state;
   /*!< PA State to which the TxAGC is to be overridden during Tx Measurement */

   byte rgi;
   /*!< RTR Gain Index to be overridden to. If the RGI is invalid
   (#FTM_CALIBRATION_INVALID_RGI), then Tx RGI override will be skipped. */

   dword pa_bias;
   /*!< PA Bias value to be applied */

   byte device_flag;
   /*!<
   @brief
   Tx Flag Mask indicating which device to calibrate.

   @details
   This is a mask indicating which devices are to be calibrated simultaneously.
   Following are the definitions of the bits defining Device Calibration
   -# B[0] : RFM Device 0 calibration
   -# B[1] : RFM Device 1 calibration
   -# B[2] : RFM Device 2 calibration
   -# B[3] : RFM Device 3 calibration
   -# B[4] : RFM Device 4 calibration
   -# B[5] : RFM Device 5 calibration
   -# B[6] : RFM Device 6 calibration
   -# B[7] : RFM Device 7 calibration

   The bits are defined in by #ftm_calibration_device_flag_mask_enum_type
   */
} ftm_cal_instr_payload_config_tx_type;

typedef struct
{
   byte hdet_sample;
   /*!< Number of HDET Samples to be taken for averaging */

   byte lpm_hdet_sample;
   /*!< Number of LPM HDET Samples to be taken for averaging */

   byte device_flag;
   /*!<
   @brief
   Tx Flag Mask indicating which device to calibrate.

   @details
   This is a mask indicating which devices are to be calibrated simultaneously.
   Following are the definitions of the bits defining Device Calibration
   -# B[0] : RFM Device 0 calibration
   -# B[1] : RFM Device 1 calibration
   -# B[2] : RFM Device 2 calibration
   -# B[3] : RFM Device 3 calibration
   -# B[4] : RFM Device 4 calibration
   -# B[5] : RFM Device 5 calibration
   -# B[6] : RFM Device 6 calibration
   -# B[7] : RFM Device 7 calibration

   The bits are defined in by #ftm_calibration_device_flag_mask_enum_type
   */
} ftm_cal_instr_payload_meas_hdet_type;

typedef struct
{
   word cal_action;
   /*!<
   @brief
   The receive calibration actions mask.

   @details
   This is a mask indicating the Rx action to be performed with this opcode
   on a given segment. Following are the definitions of the bits defining
   Rx action
   -# B[0] : LNA 0 Calibration
   -# B[1] : LNA 1 Calibration
   -# B[2] : LNA 2 Calibration
   -# B[3] : LNA 3 Calibration
   -# B[4] : LNA 4 Calibration
   -# B[5] : LNA 5 Calibration
   -# B[7:6] : Reserved
   -# B[8] : Wideband DC calibration
   -# B[15:9] : Reserved

   These definitions are also documented in #ftm_calibration_rx_action_enum_type.
   */

   byte power_mode;
   /*!< Intelliceiver Power Mode for calibration. 0 indicates Low Power Mode
   and 1 indicates High Power Mode */

   byte device_flag;
   /*!<
   @brief
   Rx Flag Mask indicating which device to calibrate.

   @details
   This is a mask indicating which devices are to be calibrated simultaneously.
   Following are the definitions of the bits defining Device Calibration
   -# B[0] : RFM Device 0 calibration
   -# B[1] : RFM Device 1 calibration
   -# B[2] : RFM Device 2 calibration
   -# B[3] : RFM Device 3 calibration
   -# B[4] : RFM Device 4 calibration
   -# B[5] : RFM Device 5 calibration
   -# B[6] : RFM Device 6 calibration
   -# B[7] : RFM Device 7 calibration

   The bits are defined in by #ftm_calibration_device_flag_mask_enum_type
   */
} ftm_cal_instr_payload_config_rx_type;

typedef struct
{
   word cal_action;
   /*!<
   @brief
   The receive calibration actions mask.

   @details
   This is a mask indicating the Rx action to be performed with this opcode
   on a given segment. Following are the definitions of the bits defining
   Rx action
   -# B[0] : LNA 0 Calibration
   -# B[1] : LNA 1 Calibration
   -# B[2] : LNA 2 Calibration
   -# B[3] : LNA 3 Calibration
   -# B[4] : LNA 4 Calibration
   -# B[5] : LNA 5 Calibration
   -# B[8:6] : Reserved
   -# B[9] : Wideband DC calibration
   -# B[15:10] : Reserved

   These definitions are also documented in #ftm_calibration_rx_action_enum_type.
   */

   byte power_mode;
   /*!< Intelliceiver Power Mode for calibration. 0 indicates Low Power Mode
   and 1 indicates High Power Mode */

   signed short exp_rxagc;
   /*!< Expected RxAGC in 1/10 dB units */

   byte device_flag;
   /*!<
   @brief
   Rx Flag Mask indicating which device to calibrate.

   @details
   This is a mask indicating which devices are to be calibrated simultaneously.
   Following are the definitions of the bits defining Device Calibration
   -# B[0] : RFM Device 0 calibration
   -# B[1] : RFM Device 1 calibration
   -# B[2] : RFM Device 2 calibration
   -# B[3] : RFM Device 3 calibration
   -# B[4] : RFM Device 4 calibration
   -# B[5] : RFM Device 5 calibration
   -# B[6] : RFM Device 6 calibration
   -# B[7] : RFM Device 7 calibration

   The bits are defined in by #ftm_calibration_device_flag_mask_enum_type
   */
} ftm_cal_instr_payload_meas_rx_type;

// RESPONSE PACKET STRUCTURES
typedef struct
{
   byte cmd;
   /*!< Command Identification */

   byte sub_sys;
   /*!< Sub-system Identification. For instance - 11 for FTM */

   word  mode;
   /*!< RF Mode Identification. For Instance - 0 for FTM_COMMON_C */

   word  cdma_cmd;
   /*!< FTM Sub Command. Example-  FTM_CALIBRATION_SWEEP */

   word req_len;
   /*!< Length of Diag Request Packet to the Target */

   word rsp_len;
   /*!< Length of response packet to Diag/PC */
} ftm_cal_sweep_config_resp_pkt_type;

typedef struct
{
   word ept_iq_capture_num_samples;
   /*!< Number of IQ Samples to be captured  */
   word ept_iq_capture_first_trigger;
   /*!< Indicator for first trigger  */
   word ept_iq_capture_last_trigger;
   /*!< Indicator for first trigger  */
   word dpd_index;
   /*!< Capture IQ and store AMAM/AMPM tables at DPD Index */
} ftm_cal_xpt_instr_payload_ept_capture_iq_type;

typedef struct
{
   word subopcode;
} ftm_cal_subcode_payload;
typedef struct
{
   word dpd_index;
   /*!< DPD Index corresponding to the AMAM/AMPM tables that need to be applied*/
} ftm_cal_xpt_instr_payload_ept_apply_dpd_type;
/*----------------------------------------------------------------------------*/
/*!
@brief
Structure to hold Rx calibration Data
*/
typedef struct
{
   byte *rx_buffer;
   /*!<
   @brief
   Pointer to the Rx Result buffer for current segment to be filled by tech
   specific Rx measurement function.

   @details
   Container to store the calibration results. Each calibration result will
   of size #ftm_calibration_rx_meas_data_type. All these results will be packed
   together. The order of calibration results will be as following.
   - RFM Device 0 PM 0 Rx Cal Action 0 Measurement ( LNA0 )
   - RFM Device 0 PM 0 Rx Cal Action 1 Measurement ( LNA1 )
   - RFM Device 0 PM 0 Rx Cal Action 2 Measurement ( LNA1 )
   - RFM Device 0 PM 0 Rx Cal Action 3 Measurement ( LNA2 )
   - RFM Device 0 PM 0 Rx Cal Action 4 Measurement ( LNA3 )
   - RFM Device 0 PM 0 Rx Cal Action 5 Measurement ( LNA4 )
   - RFM Device 0 PM 0 Rx Cal Action 6 Measurement ( LNA5 )
   - RFM Device 0 PM 0 Rx Cal Action 7 Measurement
   - <i>Other Rx Cal Action measurement for RFM Device 0 </i>
   - RFM Device 0 Rx PM 0 Cal Action 15 Measurement
   - RFM Device 0 PM 1 Rx Cal Action 0 Measurement ( LNA0 )
   - RFM Device 0 PM 1 Rx Cal Action 1 Measurement ( LNA1 )
   - RFM Device 0 PM 1 Rx Cal Action 2 Measurement ( LNA1 )
   - RFM Device 0 PM 1 Rx Cal Action 3 Measurement ( LNA2 )
   - RFM Device 0 PM 1 Rx Cal Action 4 Measurement ( LNA3 )
   - RFM Device 0 PM 1 Rx Cal Action 5 Measurement ( LNA4 )
   - RFM Device 0 PM 1 Rx Cal Action 6 Measurement ( LNA5 )
   - RFM Device 0 PM 1 Rx Cal Action 7 Measurement
   - <i>Other Rx Cal Action measurement for RFM Device 0 </i>
   - RFM Device 0 Rx PM 1 Cal Action 15 Measurement
   - RFM Device 1 PM 0 Rx Cal Action 0 Measurement ( LNA0 )
   - RFM Device 1 PM 0 Rx Cal Action 1 Measurement ( LNA1 )
   - RFM Device 1 PM 0 Rx Cal Action 2 Measurement ( LNA1 )
   - RFM Device 1 PM 0 Rx Cal Action 3 Measurement ( LNA2 )
   - RFM Device 1 PM 0 Rx Cal Action 4 Measurement ( LNA3 )
   - RFM Device 1 PM 0 Rx Cal Action 5 Measurement ( LNA4 )
   - RFM Device 1 PM 0 Rx Cal Action 6 Measurement ( LNA5 )
   - RFM Device 1 PM 0 Rx Cal Action 6 Measurement ( LNA1 )
   - <i>Other Rx Cal Action measurement for RFM Device 1 </i>
   - RFM Device 1 PM 0 Rx Cal Action 15 Measurement
   - <i>Other Rx Cal Action measurement for Remaining devices </i>
   - <i>Other Rx Cal Action measurement for Remaining devices </i>
   - RFM Device7 PM 1 Rx Cal Action 15 Measurement

   Based on Rx Cal Action Mask and Rx Flag mask, all above listed rx measurement
   may not be present. In that case, <b>all data should still be packed
   together. </b>
   */

   byte num_of_rx_reads;
   /*!< Pointer to the container where tech specific rx measurement query
   function fills the number of Rx reads taken during this rx measurement. */

   word max_rx_buffer_len;
   /*!< Maximum result buffer in bytes that can be used to store Rx results for
   this segment. Tech specific Rx measurement query function should check
   against this number to avoid buffer overflow. */
} ftm_calibration_rx_result_type;

/*----------------------------------------------------------------------------*/
/*!
@brief
Structure to hold Tx calibration Data
*/
typedef struct
{
   byte *tx_buffer;
   /*!<
   @brief
   Pointer to the Tx Result buffer for current segment to be filled by tech
   specific Tx measurement function.

   @details
   Container to store the calibration results. Each calibration result will
   of size #ftm_calibration_tx_meas_data_type. All these results will be packed
   together. The order of calibration results will be as following.
   - RFM Device 0 HDET Measurement
   - RFM Device 0 LPM HDET
   - RFM Device 1 HDET Measurement
   - RFM Device 1 LPM HDET
   - <i>Other Tx measurement for Remaining devices </i>
   - RFM Device 7 HDET Measurement
   - RFM Device 7 LPM HDET

   Based on Tx Flag mask, all above listed Tx measurement
   may not be present. In that case, <b>all data should still be packed
   together. </b>
   */

   byte num_of_tx_reads;
   /*!< Pointer to the container where tech specific Tx measurement query
   function fills the number of Tx reads taken during this Tx measurement. */

   word max_tx_buffer_len;
   /*!< Maximum result buffer that can be used to store Tx results for
   this segment. Tech specific Tx measurement query function should check
   against this number to avoid buffer overflow. */
} ftm_calibration_tx_result_type;

/*----------------------------------------------------------------------------*/
/*!
@brief
Structure to hold RF calibration Data
*/
typedef struct
{
   ftm_calibration_rx_result_type rx_result;
   /*!< Structure to hold Rx calibration results */

   word rx_result_size;
   /*!< Size of Rx results in number of bytes */

   ftm_calibration_tx_result_type tx_result;
   /*!< Structure to hold Tx Calibration results */

   word tx_result_size;
   /*!< Size of Tx results in number of bytes */
} ftm_calibration_result_type;

/*====================================================*/
//                    CAL V4
/*====================================================*/
const int QMSL_XPT_CAL_MAX_AMAM_SIZE = 256;
const int QMSL_XPT_CAL_EQ_FIR_COEF_SIZE = 4;
const int QMSL_XPT_CAL_PREDIST_SIZE = 16;
const int QMSL_XPT_CAL_EXPANDED_PREDIST_SIZE = 64;
const int QMSL_XPT_CAL_EXPANDED_DET_SIZE = 128;
const int QMSL_XPT_MAX_NUM_MEAS_POWERS = 10;
const int QMSL_FB_GAIN_MEAS_XCORR_LOG_SIZE = 32;

typedef enum
{
   MAX_BIAS_LINEARIZER = 0,
   APT_LINEARIZER = 1,
   XPT_SWP1 = 2,
   MAX_BIAS_FREQCOMP = 3,
   APT_FREQCOMP = 4,
   MULTI_CHAN_LINEARIZER = 5,
   XPT_SWP2 = 6,
   XPT_SWP3 = 7,
   XPT_FREQCOMP = 8,
   XPT_DELAY = 9,
   APT_FREQCOMP_STAGGER_RXTX = 10,
   XPT_FREQCOMP_STAGGER_RXTX = 11,
   XPT_FREQCOMP_SERIAL_TX = 12,
   XPT_FREQCOMP_SERIAL_RX = 13,
   INTRACA_FCOMP = 14,
   XPT_PIN_CAL = 15,
   XPT_FREQCOMP_SERIAL_TUNE_PCELL = 16,
   RXONLY_FREQCOMP = 17,
   REF_CAL = 100,
   INT_CAL_MAX_BIAS_LINEARIZER = 101,
   INT_CAL_APT_LINEARIZER = 102,
   INT_CAL_MAX_BIAS_FREQCOMP = 103,
   INT_CAL_APT_FREQCOMP = 104,
   MULTI_TECH_MULTI_BAND_REF_CAL = 105,
   INT_CAL_XPT_SWP1 = 106,
   INT_CAL_XPT_SWP2 = 107,
   INT_CAL_XPT_SWP3 = 108,
   INT_CAL_XPT_FREQCOMP = 109,
   MULTI_BAND_RX_CHARACTERIZED_CAL = 110,
   COMBINED_IQ_AGC_REF_CAL = 111,
   RX_RSB_CAL = 112,
   INTERCA_SCELL_FCOMP = 113,
   MULTI_BAND_RX_CHARACTERIZED_INTRA_CAL = 114,
   MULTI_BAND_TX_REF_CAL = 115,
   SEQ_CAL_CONNECTED = 1000,
   SEQ_CAL_UNCONNECTED = 1001,
   SEQ_CAL_UNCONNECTED_XPT0 = 1002,
   MAX_SWEEP_TYPE = 0xFFFF
} ESC_SWEEP_TYPE;

//For distinguishing between different types of cals to be used by TestTimeAggregator
typedef enum
{
   DEFAULT_CAL_FOR_TIME_AGGREGATION = 0,
   REF_CAL_FOR_TIME_AGGREGATION = 1,
   INT_CAL_FOR_TIME_AGGREGATION = 2
} CAL_TYPE_FOR_TIME_AGGREGATION;

typedef enum
{
   ESC_SUB_SWEEP_DEFAULT        = 0,
   ESC_SUB_SWEEP_XPT_ALIGNMENT  = 1,
   ESC_SUB_SWEEP_RGI_DELTA      = 2,
   ESC_SUB_SWEEP_DPD_CONSTRUCT  = 3,
   ESC_SUB_SWEEP_APPLY_DPD      = 4,
   ESC_SUB_SWEEP_THERM_READ     = 5,
   ESC_SUB_SWEEP_DELAY_PROC     = 6,
   ESC_SUB_SWEEP_DELAY_CAPTURE  = 7,
   ESC_SUB_SWEEP_PIN_CAPTURE    = 8,
   ESC_SUB_SWEEP_PIN_PROC       = 9,
   ESC_SUB_SWEEP_APT_CA         = 10,
   ESC_SUB_SWEEP_TX_RSB         = 11,
   ESC_SUB_SWEEP_TX_RSB_PROCESS = 12,
   ESC_SUB_SWEEP_TX_RSB_PRE     = 13,
   ESC_SUB_SWEEP_TX_RSB_POST    = 14,
   ESC_SUB_SWEEP_OVERLAP        = 15,
   ESC_SUB_SWEEP_FBGAINBW_10M   = 16,
   ESC_SUB_SWEEP_RB_SWEEP       = 17,
   ESC_SUB_SWEEP_DELTA_GAIN_PIN_POUT = 18,
   ESC_SUB_SWEEP_MAX            = 0xFFFF
} ESC_SUB_SWEEP_TYPE;


typedef enum
{
   RESULT_TX_CALIBRATION_DATA_RFM_PATH_INFO = 0,
   RESULT_TX_CALIBRATION_DATA_NVID = 1,
   RESULT_TX_CALIBRATION_DATA_MAXBIAS_APT_LINEARIZER_CALIBRATION_DATA = 2,
   RESULT_TX_CALIBRATION_DATA_MAXBIAS_APT_FREQCOMP_CALIBRATION_DATA = 3,
   RESULT_TX_CALIBRATION_DATA_THERM_READ = 4,
   RESULT_TX_CALIBRATION_DATA_FREQCOMP_CALIBRATION_CHANNEL_LIST = 5,
   RESULT_TX_CALIBRATION_DATA_EPT_VOLTERRA_DATA = 6,
   RESULT_TX_CALIBRATION_DATA_ET_VOLTERRA_DATA = 7,
   RESULT_TX_CALIBRATION_DATA_EPT_DPD_DATA = 8,
   RESULT_TX_CALIBRATION_DATA_ET_DPD_DATA = 9,
   RESULT_TX_CALIBRATION_DATA_MAX = 0xFFFF
} TX_RESULT_DATA_TYPE;

typedef enum
{
   RESULT_RX_CALIBRATION_DATA_RFM_PATH_INFO = 0,
   RESULT_RX_CALIBRATION_DATA_NVID = 1,
   RESULT_RX_CALIBRATION_DATA_FREQCOMP_DATA= 2,
   RESULT_RX_CALIBRATION_DATA_MAX = 0xFFFF
} RX_RESULT_DATA_TYPE;

typedef enum
{
   RESULT_FBRX_CALIBRATION_DATA_RFM_PATH_INFO = 0,
   RESULT_FBRX_CALIBRATION_DATA_NVID = 1,
   RESULT_FBRX_CALIBRATION_DATA_GAIN_CALIBRATION_DATA = 2,
   RESULT_FBRX_CALIBRATION_DATA_FREQCOMP_CALIBRATION_CHANNEL_LIST = 3,
   RESULT_FBRX_CALIBRATION_DATA_MAX = 0xFFFF
} FBRX_RESULT_DATA_TYPE;

typedef enum
{
   RESULT_XPT_DELAY_CALIBRATION_DATA_RFM_PATH_INFO = 0,
   RESULT_XPT_DELAY_CALIBRATION_DATA_NVID = 1,
   RESULT_XPT_DELAY_CALIBRATION_DATA_FREQCOMP_DATA= 2,
   RESULT_XPT_DELAY_CALIBRATION_DATA_MAX = 0xFFFF
} XPT_DELAY_RESULT_DATA_TYPE;

typedef enum
{
   XPT_DEBUG_INFO_XPT_MODE = 0,
   XPT_DEBUG_INFO_STG1_PWR = 1,
   XPT_DEBUG_INFO_STG1_CAPTURE_DATA = 2,
   XPT_DEBUG_INFO_STG2_CAPTURE_DATA = 3,
   XPT_DEBUG_INFO_STG1_DPD_RES = 4,
   XPT_DEBUG_INFO_MLINE_RESULT_TABLE = 5,
   XPT_DEBUG_INFO_MLINE_RESULT_SELECT_SWP_CALC = 6,
   XPT_DEBUG_INFO_MLINE_RESULT_SELECT_SWP_MEAS = 7,
   XPT_DEBUG_INFO_MLINE_RESULT_SLOPE = 8,
   XPT_DEBUG_INFO_MLINE_RESULT_DEBUG_MASK = 9,
   XPT_DEBUG_INFO_MLINE_RESULT_COMP_PTS = 10,
   XPT_DEBUG_INFO_ET_DELAY = 11,
   XPT_DEBUG_INFO_STG0_RESULT = 12,
   XPT_DEBUG_INFO_MLINE_RESULT_NUM_TYPES,
   XPT_DEBUG_INFO_DATA_MAX = 0xFFFF
} XPT_DEBUG_INFO_DATA_TYPE;

typedef enum
{
   RESULT_FD_RXRSB_CALIBRATION_DATA_RFM_PATH_INFO = 0,
   RESULT_FD_RXRSB_CALIBRATION_DATA_NVID = 1,
   RESULT_FD_RXRSB_CALIBRATION_DATA_RESULT_DATA = 2,
   RESULT_FD_RXRSB_CALIBRATION_DATA_MAX = 0xFFFF
} FD_RXRSB_RESULT_DATA_TYPE;


typedef struct
{
   uint8  tx_device_id;
   uint8  fbrx_gain_state;
   uint8  ubias;
   uint16 scale_rx;
} FTM_COMMON_FBRX_SINGLE_TRIGGER_Request_Payload;

typedef struct
{
   uint8  tech;
   uint8  tx_device;
   uint8  carrier_idx;
   uint8  fbrx_gain_state;
   uint8  ubias;
   uint16 scale_rx;
} FTM_COMMON_FBRX_SINGLE_TRIGGER_Request_Payload_V2;

/*! Structure used to hold Single Trigger output parameters */
typedef struct
{
   uint8   status;
   int16   gain;
   uint32  ls_err;
   uint16  xcorr_log[32];
}  FTM_COMMON_FBRX_SINGLE_TRIGGER_Response_Payload;

typedef struct
{
   uint8   status;
   uint8   tx_handle;
   int16   gain;
   uint32  ls_err;
   uint16  xcorr_log[32];
}  FTM_COMMON_FBRX_SINGLE_TRIGGER_Response_Payload_V2;

typedef struct
{
   uint8   cmd;
   uint8   sub_sys;
   uint16  mode;
   uint16  subsys_cmd;
   uint16  req_len;
   uint16  rsp_len;
   uint16  num_of_bytes;
   uint8   version;   /* ftm_common_fbrx_debug_type version */
   uint8   tech;
   uint8   band;
   boolean is_last_packet;
   uint32  err_code;  /* Generic error code */
   uint8   num_of_captures; /* number of valid sample captures of type ftm_common_fbrx_debug_type */
}  FTM_FBRX_DEBUG_GET_SAMPLE_CAPTURES_Response_Header;

typedef struct
{
   uint32 channel;   // UL channel
   uint8 gain_state;
   uint8 fbrx_mode;
   boolean fbrx_sample_is_good;
   uint16 tx_sample_length;
   uint16 rx_sample_length;
   uint32 tx_samples[FBRX_DATA_BUF_SIZE];
   uint32 rx_samples[FBRX_DATA_BUF_SIZE];
}  FTM_FBRX_DEBUG_DATA;

typedef struct
{
   uint8   num_of_captures; /* number of valid sample captures of type ftm_common_fbrx_debug_type */
   FTM_FBRX_DEBUG_DATA   capture_data[FFBRX_MAX_NUM_SC_DATA_BUF]; /* of datatype ftm_common_fbrx_debug_data_type  */
}  FTM_FBRX_DEBUG_GET_SAMPLE_CAPTURES_Response_Payload;

typedef enum
{
   FBRX_AGC_GAIN = 0,
   FBRX_IQ_GAIN = 1,
   FBRX_UKERNEL_GAIN = 2,
   FBRX_WTR_PWR = 3,
   FBRX_GAIN_MAX = 0xFF
} ESC_INT_CAL_FB_RX_CAL_MODE;

typedef enum
{
   FBRX_AGC_COMPUTE_UBIAS_RXSCALE                = 0,
   FBRX_AGC_USE_UBIAS_RXSCALE                    = 1,
   FBRX_AGC_CALC_UBIAS_RXSCALE_BASED_ON_EXP_PWR  = 2,
   FBRX_AGC_MAX_SUPPORTED_ACTION = 0xFF
} FBRX_ACTION_TYPE;

typedef struct
{
   signed short fbGain;
   word uBias;
   unsigned short rxScale;
} FB_GAIN_CAL_RESULTS;

typedef enum
{
   REF_CAL_V1 = 0,
   REF_CAL_V2 = 1,
   REF_CAL_VMAX = 255
} REF_CAL_RESULT_VERSION;

typedef enum
{
   ESC_RES_VER_0 = 0x0,
   ESC_RES_VER_1 = 0x1,
   ESC_RES_VER_MAX = 0xFFFF
} ESC_RES_VER_NUM;

// This enum is used to match the result type returned by the UE
// Each value is actually the bit representing the Opcode used for that segment.
// Results are expected only for Bits 12, 13, 14 and 15 of the opcode for Cal V4.
typedef enum
{
   ESC_RES_TYPE_DATA = 11,
   ESC_RES_TYPE_XPT = 13,
   ESC_RES_TYPE_RX = 14,
   ESC_RES_TYPE_TX = 15,
   ESC_RES_ENHANCED_INTERNAL_DEVICE_CAL= 17,
   ESC_RES_TYPE_SEQ_BLD = 18,
   ESC_RES_TYPE_SEQ_EXE = 19,
   ESC_RES_TYPE_MAX = 255
} ESC_RES_TYPE;

//  Enumeration of all Data Calibration Result Actions.
typedef enum
{
   ESC_DATA_RES_ACTION_RGI_PWR_TBL           = 0,
   ESC_DATA_RES_ACTION_PUSH_DPD_TBL          = 1,
   ESC_DATA_RES_ACTION_PROCESS_MLINE         = 2,
   ESC_DATA_RES_ACTION_PROCESS_DELAY         = 3,
   ESC_DATA_RES_ACTION_PROCESS_DPD           = 4,
   ESC_DATA_RES_ACTION_LOAD_CALC_DPD         = 5,
   ESC_DATA_RES_ACTION_GET_MLINE_RESULTS     = 6,
   ESC_DATA_RES_ACTION_XPT_CAP_RESULTS       = 7,
   ESC_DATA_RES_ACTION_PROCESS_PIN           = 8,
   ESC_DATA_RES_ACTION_PROCESS_PIN_EXT       = 10,
   ESC_DATA_RES_ACTION_PUSH_FBRX_AGC_TBL     = 11,
   ESC_DATA_RES_ACTION_RETURN_RF_CAL_RESULTS_AND_COMMIT_NV = 12,
   ESC_DATA_RES_ACTION_CALC_DELTA_GAIN_PIN_POUT = 14,
   ESC_DATA_RES_ACTION_LOAD_DELTA_GAIN_PIN_POUT = 15,
   ESC_DATA_RES_ACTION_MAX
} ESC_DATA_RES_ACTION_TYPE;

// This enum is used to indicate the params of the Tx Override Opcode which are to be overriden.
// Used to form the Tx Params Mask of the Tx Override Payload.
typedef enum
{
   ESC_TX_OVERRIDE_PA_STATE         = 0x0001,
   ESC_TX_OVERRIDE_RGI              = 0x0002,
   ESC_TX_OVERRIDE_BIAS             = 0x0004,
   ESC_TX_OVERRIDE_IQ_GAIN          = 0x0008,
   ESC_TX_OVERRIDE_ENV_SCALE        = 0x0010,
   ESC_TX_OVERRIDE_PA_CURRENT       = 0x0020,
   ESC_TX_OVERRIDE_DELAY            = 0x0040,
   ESC_TX_OVERRIDE_MAX              = 0xFFFF
} ESC_TX_OVERRIDE_TYPE;

// This enum defines the actions for IQ Gain and Env Scale Tx Overrides
typedef enum
{
   ESC_TX_OVERRIDE_ACTION_SKIP     = 0x0,
   ESC_TX_OVERRIDE_ACTION_USE_VAL  = 0x1,
   ESC_TX_OVERRIDE_ACTION_SW_DEF   = 0x2,
   ESC_TX_OVERRIDE_ACTION_FROM_STATIC_NV   = 0x3,
   ESC_TX_OVERRIDE_ACTION_USE_COMPUTED_VAL = 0x4,
   ESC_TX_OVERRIDE_ACTION_MAX      = 0xFFFF
} ESC_TX_OVERRIDE_ACTION_TYPE;

// This enum defines Tx Override Type Mask
typedef enum
{
   ESC_TX_OVERRIDE_MASK_POWER    = 0x0001,
   ESC_TX_OVERRIDE_MASK_DPD      = 0x0002,
   ESC_TX_OVERRIDE_MASK_MAX      = 0xFFFF
} ESC_TX_OVERRIDE_MASK_TYPE;

// This enum defines the Power Override Type
typedef enum
{
   ESC_TX_PWR_OVERRIDE_PARAMS    = 0x0001,
   ESC_TX_PWR_OVERRIDE_ABS_PWR   = 0x0002,
   ESC_TX_PWR_OVERRIDE_MAX       = 0xFFFF
} ESC_TX_PWR_OVERRIDE_TYPE;

// This enum defines the Tx Meas Action Type
typedef enum
{
   ESC_TX_MEAS_ACTION_NO_ACTION      = 0x00,
   ESC_TX_MEAS_ACTION_HDET_MEAS      = 0x01,
   ESC_TX_MEAS_ACTION_LPM_HDET_MEAS  = 0x02,
   ESC_TX_MEAS_ACTION_THERM_READ     = 0x04,
   ESC_TX_MEAS_ACTION_FB_GAIN_MEAS   = 0x08,
   ESC_TX_MEAS_ACTION_FB_POWER_MEAS  = 0x10,
   ESC_TX_MEAS_ACTION_FB_GAIN_AGC_MEAS    = 0x20,
   ESC_TX_MEAS_ACTION_MAX            = 0xFF
} ESC_TX_MEAS_ACTION_TYPE;

// This enum defines the XPT Action Type
typedef enum
{
   ESC_XPT_ACTION_NONE           = 0,
   ESC_XPT_ACTION_CAL_CFG        = 1,
   ESC_XPT_ACTION_IQ_CAP         = 2,
   ESC_XPT_ACTION_MAX            = 255
} ESC_XPT_ACTION_TYPE;

// This enum defines Capture Type for ESC Cal
typedef enum
{
   ESC_XPT_CAP_EPT               = 0,
   ESC_XPT_CAP_ET                = 1,
   ESC_XPT_CAP_DELAY             = 2,
   ESC_XPT_CAP_LEAKAGE           = 3,
   ESC_XPT_CAP_PIN               = 4,
   ESC_XPT_CAP_MAX               = 255
} ESC_XPT_CAP_TYPE;

// This enum defines Capture Processing Type
typedef enum
{
   ESC_XPT_CAP_PROC_NO_PROC      = 0,
   ESC_XPT_CAP_PROC_SWP1         = 1,
   ESC_XPT_CAP_PROC_SWP2         = 2,
   ESC_XPT_CAP_PROC_SWP3         = 3,
   ESC_XPT_CAP_PROC_MAX          = 255
} ESC_XPT_CAP_PROC_TYPE;

// This enum defines Load Calc DPD Action
typedef enum
{
   LOAD_CALC_DPD_ACTION_LOAD_UNITY    = 0,
   LOAD_CALC_DPD_ACTION_LOAD_ISC      = 1,
   LOAD_CALC_DPD_ACTION_LOAD_SC       = 2,
   LOAD_CALC_DPD_ACTION_MAX           = 255
} LOAD_CALC_DPD_ACTION_TYPE;

// This enum defines the actions for Tx Internal Cal Feed Back Setup
typedef enum
{
   ESC_FEEDBACK_SETUP_ACTION_SKIP                     = 0x0,
   ESC_FEEDBACK_SETUP_ACTION_CONFIG_WTR               = 0x1,
   ESC_FEEDBACK_SETUP_ACTION_CONFIG_RXLM_FOR_XPT      = 0x2,
   ESC_FEEDBACK_SETUP_ACTION_CONFIG_RXLM_FOR_FBAGC    = 0x4,
   ESC_FEEDBACK_SETUP_ACTION_MASK_CONFIGURE_STG       = 0x8,
   ESC_FEEDBACK_SETUP_ACTION_CONFIGURE_FBRX_FOR_IQRMS = 0x16,
   ESC_FEEDBACK_SETUP_ACTION_MAX                      = 0xFFFF
} ESC_FEEDBACK_SETUP_ACTION_TYPE;

// This enum defines the Sync Opcode Events
typedef enum
{
   ESC_SYNC_EVENT_SYNC_WITH_SYS_TX_BDRY      = 0x0,
   ESC_SYNC_EVENT_MAX                        = 0xFFFF
} ESC_SYNC_EVENT_TYPE;

typedef enum
{
   RESULT_NO_ACTION             = 0,
   /*!< XPT Result Action - No Action */

   RESULT_MLINE_TABLE           = 1,
   /*!< XPT Result Action - Return EXT M Line Table */

   RESULT_SELECTION_SWEEP       = 2,
   /*!< XPT Result Action - Return Selection Sweep table*/

   RESULT_COMPRESSION_POINTS    = 4,
   /*!< XPT Result Action - Return Compression Points*/

   RESULT_MLINE_SLOPE_POINTS    = 8,
   /*!< XPT Result Action - Return M Line Slope Points*/

   RESULT_AMAM_RMS    = 16
                        /*!< XPT Result Action - Return the AMAM RMS value */
} XPT_MLINE_RESULTS_ACTION_TYPE;

typedef enum
{
   /* When Bias to be picked out of Mline is greater than Vdmax,
   interpolate bias between previous entry and the failing entry
   for required target power. If this is less than Vdmax, then cap
   the Bias to Vdmax. If this is greater than Vdmax, then fail */
   XPT_MLINE_BIAS_OPTION_CALC_INTERP_BIAS = 0,
   /* If M line calculated Bias is greater than VdMax, cap to Vdmax */
   XPT_MLINE_BIAS_OPTION_CAP_TO_VDMAX = 1,
   /* Pick power closest to target power from Mline, except for the
   max target power.Bias action follows INTERP_BIAS behaviour */
   XPT_MLINE_BIAS_OPTION_CLOSEST_POWER_INTERP_BIAS = 2,
   /* Pick power closest to target power from Mline, except for the max target power.
   Returns max possible entry from Mline for bias limit for all target powers that exceed bias limit and
   returns max entry for max tgt power, irrespective of max target power */
   XPT_MLINE_BIAS_OPTION_PWR_RET_MAX_ENTRY = 3,
   /* MLine Calculation to be done with compression point backed off by 0.1dB at a time for the 4 captures
   respectively. Ex.. first point cal will use 3dB, next 2.9, next 2.8 and last 2.7 */
   XPT_MLINE_CALC_WITH_p1dB_COMPPT_BACKOFF = 4,
   /* MLine Calculation to be done with compression point backed off by 0.3dB at a time for the 4 captures
   respectively. Ex.. first point cal will use 3dB, next 2.7, next 2.4 and last 2.1 */
   XPT_MLINE_CALC_WITH_p3dB_COMPPT_BACKOFF = 5,
   /* MLine Calculation to be done with compression point backed off by 0.5dB at a time for the 4 captures
   respectively. Ex.. first point cal will use 3dB, next 2.5, next 2.0 and last 1.5 */
   XPT_MLINE_CALC_WITH_p5dB_COMPPT_BACKOFF = 6,
   /* Option Max - Invalid option */
   XPT_MLINE_BIAS_OPTION_MAX = 0xFFFF
} XPT_MLINE_BIAS_OPTION_TYPE;

// This enum defines XPT Capture Result Mask
typedef enum
{
   XPT_CAP_RES_MASK_COMP     = 0x0001,
   XPT_CAP_RES_MASK_DPD      = 0x0002,
   XPT_CAP_RES_MASK_PAR      = 0x0004,
   XPT_CAP_RES_MASK_RXRMS    = 0x0008,
   XPT_CAP_RES_MASK_MAX      = 0xFFFF
} XPT_CAP_RES_MASK_TYPE;

// This enum is used to define sub sweep types to be defined for Ref Cal
typedef enum
{
   DO_REF_CAL=0,
   /*Do Reference Cal only*/

   DO_FBRX_CAL=1,
   /*Do FBRx Cal only*/

   DO_FBRX_CAL_REF_CAL=2,
   /*FBRX CAL + Ref Cal*/

   FBRX_CAL_MODE_TYPE_MAX=255
} FBRX_CAL_MODE_TYPE;

//This enum is used to define Rx Meas actions used by ESC Sweeps
typedef enum
{
   //LNA offset measurement
   ESC_RX_MEAS_ACTION_MEAS_LNA_OFFSET     = 0x0001,

   //Dual Carrier LNA Offset measurement
   ESC_RX_MEAS_ACTION_MEAS_DC_LNA_OFFSET  = 0x0002,

   //RX AGC measurement
   ESC_RX_MEAS_ACTION_MEAS_RX_AGC         = 0x0004,

   //3C LNA Offset Measurement
   ESC_RX_MEAS_ACTION_3C_LNA_OFFSET       = 0x0008,

   //IQ RMS Measurement
   ESC_RX_MEAS_ACTION_MEAS_IQ_RMS         = 0x0010,

   ESC_RX_MEAS_ACTION_MAX                 = 0xFFFF
} ESC_RX_MEAS_ACTION_TYPE;

// This enum is used for specifying Rx Cal types in Rx characterization xml
typedef enum
{
   //Single Carrier LNA offset measurement
   ESC_RX_CAL_TYPE_SC                     = 0x00,

   //Dual Carrier LNA offset measurement
   ESC_RX_CAL_TYPE_DC                     = 0x01,

   //Three Carrier LNA offset measurement
   ESC_RX_CAL_TYPE_3C                     = 0x02,

   //Inter-band CA LNA offset measurement
   ESC_RX_CAL_TYPE_INTER_CA               = 0x03,

   //Intra-band CA LNA offset measurement
   ESC_RX_CAL_TYPE_INTRA_CA               = 0x04,

   ESC_RX_CAL_TYPE_INVALID                = 0xFF
} ESC_RX_CAL_TYPE;

// This enum is used to define the Enh Int Cal Action Bit Mask
typedef enum
{
   // FBRx Droop Cal
   ENH_INT_DEV_CAL_FBDROOP        = 0x0001,

   // Tx BBF Group Delay Cal
   ENH_INT_DEV_CAL_TX_GROUP_DELAY = 0x0002,

   // Rx IIP2 Cal
   ENH_INT_DEV_CAL_IIP2           = 0x0004,

   // FBRx DC Cal
   ENH_INT_DEV_CAL_FBDC           = 0x0008,

   // RSB Cal
   ENH_INT_DEV_CAL_RSB            = 0x0010,

   ENH_INT_DEV_CAL_RSB_GET_RESULT = 0x0100,
   /*!< Request RSB Data */

   // Max
   MAX_ENH_INT_DEV_CAL_MAX        = 0xFFFF
} ESC_ENH_INT_DEV_CAL_TYPE;

typedef enum
{
   TX_LINEARIZER_NO_AUX_DATA,
   TX_LINEARIZER_EPT_DPD_AUX_DATA,
   TX_LINEARIZER_EPT_DPD_V2_DATA,
   TX_LINEARIZER_ET_DPD_DATA,
   TX_LINEARIZER_EPT_VOLTERRA_DATA,
   TX_LINEARIZER_ET_VOLTERRA_DATA,
   TX_LINEARIZER_DPD_INVALID
} QMSL_MULTILIN_V3_XPT_DPD_TYPE_ENUM;

typedef enum
{
   XPT_DEBUG_PARMS = 0,
   XPT_RGI_DELTA_PARAMS = 1,
   XPT_FIRST_SWP_PARMS = 2,
   XPT_MLINE_PARMS_NO_CALCPWR = 3,
   XPT_MLINE_PARMS_W_CALCPWR = 4,
   XPT_ET_PARMS = 5,
   XPT_SEC_SWP_PARAMS = 6,
   XPT_FCOMP_PARAMS = 7,
   XPT_LIMITS_PARAMS = 8,
   XPT_UPPER_BND_CHAN_PARAM = 9,
   XPT_PARMS_INVALID
} QMSL_XPT_PARAM_TYPEID_ENUM;

typedef enum
{
   XPT_START_TO_STG2_PROC = 0,
   XPT_RGI_DELTA = 1,
   XPT_START_TO_STG1_PWR_MEAS = 2,
   XPT_START_TO_STG1_CAPT = 3,
   XPT_START_TO_STG1_PROC = 4,
   XPT_START_TO_MLINE = 5,
   XPT_START_TO_STG2_CAPT = 6,
   XPT_START_TO_STG3_PWR = 7,
   XPT_STG2_CAPT_TO_STG3_PWR = 8,
   XPT_START_TO_STG0_PWR_MEAS = 9,
   XPT_START_TO_STG0_CAPT = 10,
   XPT_START_TO_STG0_PROC = 11,
   XPT_SEQ_ACTN_INVALID
} QMSL_XPT_SEQ_ACTN_ENUM;

typedef struct
{
   // Length of opcode
   word opCodeLen;

   // Union for 256 bits of opcode. Allows opcode to be variable length
   union
   {
      word opCode;
      qword opCodeGrp0;
      qword opCodeGrp1;
      qword opCodeGrp2;
      qword opCodeGrp3;
   } opCodeGrp;
} var_len_opcode_type;

typedef struct
{
   /**
   Specifies which action will be performed in the segment
   A Bitmask to select the action to be performed.

   Opcode = 0x0000 - NOP segment
   Opcode = 0x0001 - Config Segment to configure RF mode and Channel
   Opcode = 0x0002 - Retune Segment to change Channel
   Opcode = 0x0004 - Waveform Config Segment
   Opcode = 0x0008 - Tx Meas Segment
   Opcode = 0x0010 - HDET Meas Segment
   Opcode = 0x0020 - Cfg Rx Segment
   Opcode = 0x0040 - Meas Rx Segment
   Opcode = 0x0080 - XPT Segment
   Opcode = 0x0100 - Radio Config Segment
   Opcode = 0x0200 - Tx Override Segment
   Opcode = 0x0400 - Data Segment

   Enabling multiple bits will allow multiple actions to be performed in a segment.

   */
   var_len_opcode_type varLenOpcode;

   /**
   The length of one power step in units of us.
   */
   word segLen;
} cal_sweep_opcode;

typedef struct
{
   // Master Device
   byte masterDev;

   // Slave Device
   byte slaveDev;

   // Master Device State
   byte masterDevState;

   // Slave Device State
   byte slaveDevState;
} cal_sweep_params_device;

typedef struct
{
   // PCell Master Device
   byte pcellmasterDev;

   // PCell Slave Device
   byte pcellslaveDev;

   // SCell Master Device
   byte scellmasterDev;

   // SCell Slave Device
   byte scellslaveDev;
} cal_sweep_params_device_mapping;

typedef struct
{
   //The channel at which the cal is done.
   dword ulChan;

   //The Tx bandwidth for LTE
   dword rxBW;

   //The Rx bandwidth for LTE
   dword txBW;
} cal_sweep_params_chan_info;

typedef struct
{
   // Number of Channels
   byte numChans;

   // Channel Info for each channel
   cal_sweep_params_chan_info chanInfo[TXLIN_NUM_CHANNELS];
} cal_sweep_params_chan;

typedef struct
{
   /**
   The Tx waveform used. Could be:
   0. Default
   1. CW
   2. Offset CW
   3. LTE PUSCH
   4. EUL
   */
   byte txWaveform;

   //The Offset for Offset CW waveform
   dword cwOffset;

   //The number of RBs for LTE
   byte numRBs;

   //The Start RBs for LTE
   byte startRB;

   //The Subtest config for FTM EUL waveform
   word eulConfig;
} cal_sweep_params_wfm;

//Split Band path Override.
typedef struct
{
   //Path override value for Master Device. Default value is 255
   byte master_device_pathoverride;

   //Path override value for Slave Device. Default is 255
   byte slave_device_pathoverride;
} cal_sweep_params_path_selection;

//Alternate Path Struct
typedef struct
{
   //Alternate Path Value of Master Device  . Default is 0
   byte master_device_alternate_path;

   //Alternate Path Value of Slave Device. Default is 0
   byte slave_device_alternate_path;
} cal_sweep_params_alternate_path;

//enum for Radio Setup Opcode Versions
typedef enum
{
   RADIO_SETUP_OPCODE_V0, //Default Version used

   RADIO_SETUP_OPCODE_V1,

   RADIO_SETUP_OPCODE_V255 = 255,
} RADIO_SETUP_OPCODE_VERSION;

//enums for Radio Setup Meas Actions
typedef enum
{
   RADIO_SETUP_DEFAULT_ACTION = 0,

   RADIO_SETUP_PATH_SELECT_OVERRIDE = 1,

   RADIO_SETUP_ALTERNATE_PATH_OVERRIDE = 2,

   RADIO_SETUP_ACTION_MAX = 65535,
} RADIO_SETUP_MEAS_ACTION;

#define DEFAULT_ALTERNATE_PATH 0
#define DEFAULT_PATH_SELECT_OVERRIDE_INDEX 255

typedef struct
{
   //Radio Setup Action bitmask. Only available on Version 2 and above of the opcode.
   dword radio_setup_action_mask;

   cal_sweep_params_path_selection path_select_cfg;

   cal_sweep_params_alternate_path alternate_path_cfg;
} cal_sweep_params_radio_setup_action;

typedef struct
{
   //The XPT Mode to be set
   byte xptMode;

   // Tx Override Type Mask
   dword txOverrideMask;

   // Power Override Type
   byte pwrOverrideType;

   // Tx Param Mask
   dword pwrParamMask;

   //The PA state to be set
   byte paState;

   //The RGI to be set.
   byte rgi;

   //The bias to be set
   dword bias;

   // Action for IQ Gain Override
   byte iqGainAction;

   //The IQ Gain bias to be set
   dword iqGain;

   // Action for Envelope Scale Override
   byte envScaleAction;

   //The Envelope Scale to be set
   dword envScale;

   //The PA Quiescent Current to be set
   dword quiescentCurrent;

   // Action for Delay Value Override
   byte delayAction;

   //The Delay Value to be set
   dword delay;

   //The Power for RGI Lookup/ Expected Power
   word expPwr;

   //Ref channel for Tx Override
   dword refChan;

   //The DPD Index to be set
   word dpdIndex;
} cal_sweep_var_len_tx_params;

typedef struct
{
   // Version
   byte version;

   // Debug Mode
   byte debugMode;

   // Flag
   word flag;

   /**
   Tx Mask used to indicate the device/s for which Tx cal is done.
   Bit 0 - 3 = Select the Tx Device
   Bit 4 - 7 = Reserved for more devices
   */
   byte txDevice;

   // Variable Length of Tx Params per device
   cal_sweep_var_len_tx_params txParams[MAX_NUM_DEVICES];
} cal_sweep_params_tx;

typedef struct
{
   // Result FB Gain State
   byte fbGainState;

   // Result FBRx Mode
   byte fbrxMode;

   // Result FBRx Error Type
   byte fbErrType;

   // Result FB Gain
   word fbGainRes;

   // Result LOFT
   dword fbLOFTRes;

   // Result FB RSB Res
   dword fbRSBRes;

   // Result FB Gain Imbalance
   word fbGainImbRes;

   // Result FB Phase Imbalance
   word fbPhaseImbRes;

   // Result LS Error
   dword fbLSError;

   // Result Cross Correlation Log
   word fbXCorrLog[QMSL_FB_GAIN_MEAS_XCORR_LOG_SIZE];
} cal_sweep_res_fb_gain_meas_res;


typedef struct
{
   // Result FB Gain State
   byte fbNumCaptures;

   // Result FBRx Mode
   byte fbrxMode;

   // Result FB Gain State
   byte fbGainState;

   // Result FBRx Error Type
   word fbErrType;

   // Result FB Gain
   word fbGainRes;

   // Result FBRx Ubias
   byte fbUbias;

   // Result FBRx Ubias
   word fbRxScale;

   // Result LOFT
   dword fbResidualDc;

   // Result RSB
   dword fbRSB;

   // Result FB Gain Imbalance
   word fbGainImbRes;

   // Result FB Phase Imbalance
   word fbPhaseImbRes;

   // Result FB tx_tx_conj_corr
   dword fbTxTxConjCorr;

   // Result FB tx_tx_corr
   dword fbTxTxCorr;

   // Result FB tx_sum
   dword fbTxSum;

   // Result FB rx_tx_conj_corr
   dword fbRxTxConjCorr;

   // Result FB rx_tx_corr
   dword fbRxTxCorr;

   // Result FB rx_sum
   dword fbRxSum;

   // Result FB rx_rx_conj_corr
   dword fbRxRxConjCorr;

   // Result FB rx_rx_corr
   dword fbRxRxCorr;

   // Result FB Gain RMS Signal Level
   dword fbRmsSignalLevel;

   // Result LS Error
   dword fbLSError;

   // Result FB max correlation peak
   word fbMaxCorrPeak;

   // Result FBRx Ubias
   byte fbMaxCorrPeakIndex;

   // Result Cross Correlation Log
   word fbXCorrLog[QMSL_FB_GAIN_MEAS_XCORR_LOG_SIZE];
} cal_sweep_res_fb_gain_agc_meas_res;


typedef struct
{
   // Result Tx Power
   double txPower;

   // Result HDET/LPM HDET
   word hdet[MAX_NUM_DEVICES][MAX_NUM_MEAS_ACTIONS];

   // FB Gain Meas Results
   cal_sweep_res_fb_gain_meas_res fbGainMeas;

   // FB Power Meas Result
   word fbPower;

   // FB Gain Agc Meas Results
   cal_sweep_res_fb_gain_agc_meas_res fbGainAgcMeas;
} cal_sweep_res_tx;

typedef struct cal_sweep_res_tx_int_cal_tag {
    // Feedback AGC
    word fbAGC;

    // reference Tx power (From TE). For parallel box measurements
    word refTxPower;

    // offset to be applied
    word offset;

    // Is this a reference point
    bool refMeasurement;

    void cal_sweep_res_tx_int_cal();

    //FB IQ RMS value
    word fbiqrms;

    //FB Path Gain
    word fbpathgain;
} cal_sweep_res_tx_int_cal;

void cal_sweep_res_tx_int_cal::cal_sweep_res_tx_int_cal() {
    refMeasurement = false;
}

typedef struct
{
   /**
   List specifying the rx action to take. CHECK if we should use the below enum!!!!!!!!!!!!!!!!!!!!!!!!

   Valid values are defined by the enumeration ftm_tx_rx_freq_cal_sweep_rx_action_enum:
   \code
   FTM_TX_RX_FREQ_RX_ACTION_LNA0    = 0,    //!<' - calibrate LNA offset 0
   FTM_TX_RX_FREQ_RX_ACTION_LNA1    = 1,    //!<' - calibrate LNA offset 1
   FTM_TX_RX_FREQ_RX_ACTION_LNA2    = 2,    //!<' - calibrate LNA offset 2
   FTM_TX_RX_FREQ_RX_ACTION_LNA3    = 3,    //!<' - calibrate LNA offset 3
   FTM_TX_RX_FREQ_RX_ACTION_LNA4    = 4,    //!<' - calibrate LNA offset 4
   FTM_TX_RX_FREQ_RX_ACTION_DVGA    = 100,  //!<' - calibrate DVGA offset
   FTM_TX_RX_FREQ_RX_ACTION_NOTHING = 255   //!<' - do nothing
   \endcode
   */
   word rxActions;

   /**
   List specifying the rx power mode to use. CHECK if we should use the below enum!!!!!!!!!!!!!!!!!!!!!!!!
   The values are ignored for chipsets that do not support rx power modes.
   Valid values are:
   \code
   FTM_TX_RX_FREQ_RX_PM_High        = 0,    //!<' - Rx high power mode
   FTM_TX_RX_FREQ_RX_PM_Medium      = 1,    //!<' - Rx medium power mode
   FTM_TX_RX_FREQ_RX_PM_Low     = 2     //!<' - Rx low power mode
   \endcode
   */
   byte rxPM;

   /**
   The expected agc value used as the input to the LNA or DVGA offset calibration routine
   for the primary RX path. If rx_action_list is 255 for a particular step then
   the expected agc value is not used
   */
   word expRxAGC;

   /**
   Rx flag used to select Rx Device.
   Bits 0 - 3 = Select the Rx Device
   Bits 4 - 7 = Reserved
   */
   byte rxFlag;

   /**
   Rx Path .The index of the array is the device and the value is the path for that device. Please make sure
   to fill this information for the Consolidated Rx NV generation to work correctly. Default values for the path should be 0
   */
   byte rxPath[MAX_NUM_DEVICES];

   /**Type of Rx Calibration performed for this record. Refer to RFNV_RX_CAL_DATA_NV_TYPE for enumeration definitions**/
   unsigned short rxCalibrationType;

   /**
   Feedback Device
   */
   byte fbDev;

   /**
   Feedback Component
   */
   byte fbComponent;

   /**
   Feedback Device State
   */
   byte fbDevState;
} cal_sweep_params_rx;

typedef struct
{
   // Result Rx results per Device, per Power Mode, Per LNA State
   word lnaOffset[MAX_NUM_DEVICES][MAX_NUM_MEAS_ACTIONS];

   // Multi Carrier???????

   //FB IQ RMS results
   word iqrms;

   //FB Gain state
   byte fbstate;
} cal_sweep_res_rx;

typedef struct
{
   // XPT Mode
   byte xptMode;

   // Gain Comp
   word gainComp;

   // FBRx Gain State
   byte fbGainState;

   // FBRx UBias
   byte uBias;

   // FBRx Rx Scale
   word rxScale;

   // Enable Debug mode to save captures
   byte debugModeEn;
} cal_sweep_fb_gain_meas_params;

typedef struct
{
   // FBRx Gain State
   byte fbGainState;

   // Number of measurement averages
   byte numSamples;
} cal_sweep_fb_power_meas_params;

typedef struct
{
   // FBRx Gain State
   byte fbGainState;

   // FBRx Gain Expected Power
   word expPower;

   // FBRx Action Mask
   byte fbrxAction;

   // Enable Debug mode to save captures
   byte debugModeEn;
} cal_sweep_fb_gain_agc_meas_params;

typedef struct
{
   // Number of HDET averages to take during the measurement. If 0, HDET action/measurement is NOT performed.
   byte numHdetAvg;

   // Number of LPM HDET averages to take during the measurement. If 0, LPM HDET action/measurement is NOT performed.
   byte numLpmHdetAvg;

   // FB Gain Cal Params
   cal_sweep_fb_gain_meas_params fbGainParams;

   // FB Meas power params
   cal_sweep_fb_power_meas_params fbPowerMeasParams;

   // FB Gain Cal Agc Params
   cal_sweep_fb_gain_agc_meas_params fbGainAgcParams;
} cal_sweep_tx_meas;

typedef struct
{
   /**
   Bit Mask to indicate Tx Measurement Action
   Bit 0 - HDET
   Bit 1 - LPM HDET
   Bit 2 - Therm Read
   Bit 3 - FB Gain Meas
   Bit 4 - FB Gain Power
   Bit 5 - FB Gain Agc Meas
   */
   word txMeasAction;

   // Tx Meas Items
   cal_sweep_tx_meas txMeasPayload;
} cal_sweep_var_len_tx_meas;

typedef struct
{
   // Version
   byte version;

   // Debug Mode
   byte debugMode;

   // Flag
   word flag;

   /**
   HDET Flag used to indicate the device for which HDET cal is done.
   Bit 0 - 3 = Select the Tx Device
   Bit 4 - 7 = Reserved for more devices
   */
   byte txMeasFlag;

   // Var Length Tx Meas Payload per device
   cal_sweep_var_len_tx_meas txMeas[MAX_NUM_DEVICES];
} cal_sweep_params_tx_meas;

typedef struct
{
   // Device for XPT
   byte dev;

   // Feedback Device for XPT
   byte fbDev;

   // Flag for indicating EPT/ET mode
   // 0 - APT
   // 1 - EPT
   // 2 - ET
   byte xptMode;
} cal_sweep_xpt_cfg;

typedef struct
{
   // Device for XPT
   byte dev;

   // Feedback Device for XPT
   byte fbDev;

   // Flag for indicating capture mode
   // 0 - EPT IQ Capture
   // 1 - ET IQ Capture
   // 2 - Delay Cal IQ Capture
   // 3 - Leakage Cal IQ Capture
   byte capType;

   // Number of samples
   word numSamples;

   // First Trigger
   byte firstTrig;

   // Last Trigger
   byte lastTrig;

   // Processing Flag
   // 0 : No Processing
   // 1 : Process 1 (1st Sweep Processing)
   // 2 : Process 2 (2nd Sweep Processing
   // 3 : Process 3 (3rd Sweep Processing)
   byte procFlag;
} cal_sweep_xpt_capture_iq;

typedef struct
{
   // Version
   byte version;

   // Debug Mode
   byte debugMode;

   // Flag
   word flag;

   // XPT Action
   dword xptAction;

   // XPT Config
   cal_sweep_xpt_cfg xpt_cfg;

   // XPT Capture IQ
   cal_sweep_xpt_capture_iq xptCaptureIQ;
} cal_sweep_xpt;

typedef struct
{
   // Version
   byte version;

   // Debug Mode
   byte debugMode;

   // Flag
   word flag;

   // Event
   word syncEvent;

   // Device
   byte device;
} cal_sweep_sync;

typedef struct
{
   // Flag to indicate RGI vs Pwr data operation in the segment
   bool doRgiVsPwrOp;

   // Number of RGI Delta Pairs
   byte numRGIDeltas;

   // RGI in RGI vs Pwr (RGI Deltas)
   byte rgi[64];

   // Power in RGI vs Pwr (RGI Deltas)
   word pwr[64];
} cal_sweep_rgi_vs_pwr;

typedef struct
{
   // Flag to indicate RGI vs Pwr data operation in the segment
   bool doRgiVsPwrVsStateOp;

   // Number of RGI Delta Pairs
   byte numRGIDeltas;

   // Pa state
   byte paState;

   // Offset to extract data for Pa state 1 and Pa state 2.
   byte xptMode;

   // RGI in RGI vs Pwr (RGI Deltas)
   byte rgi[64];

   // Power in RGI vs Pwr (RGI Deltas)
   word pwr[64];
} cal_sweep_rgi_vs_pwr_vs_state;

typedef struct
{
   uint32 ls_err;
   /*! The least squares error*/
   int32 gain_fbrx_nom;
   /*! nominal fbrx gain */
   int32 p_tx_nom;
   /*! nominal tx power */
   uint16 hw_gain_delta;
   /*! Gain delta from the Gexp */
   uint16 fbrx_hw_gain;
   /*! The ILPC HW gain */
   uint16 fbrx_sw_gain;
   /*! The SW gain */
   int16 txfe_power;
   /*! TxFE Tx power for ILPC - logging only */
   uint8 trunc_bits;
   /*! The trunc bits used for FBRx Gain Cal */
   uint8 predet_idx;
   /*! The timing alignment index at which the best correlation was found */
   uint8 fbrx_mode;
   /*! The FBRx mode used */
   uint8 fbrx_gain_state;
   /*! The FBRx gain state used */
} rfcommon_core_fbrx_result_type;
typedef struct
{
   uint32 channel;
   /* Channel */
   uint8 numberOfGainStates;
   /* Number of Gain States */
   rfcommon_core_fbrx_result_type fbrxResult[4]; // FBRX_GAIN_STATE_MAX
   /* Array that contains FBRx Gain Data for each Gain State */
} ftm_fbrxgain_channel_result;
typedef struct
{
   uint8 fbrxMode;
   /* FBRX Calibration Mode */
   uint8 numberofChannels;
   /* Number of Channels */
   ftm_fbrxgain_channel_result channelResults[16]; // MAX_NUM_FBRX_GAIN_CHANNELS
} ftm_fbrxgain_mode_result;
typedef struct
{
   uint32 sig_path;
   uint64 fbrxCalErrDebugMask;
   uint32 fbrxCalDataType;
   uint16 rfmDevice;
   uint16 antennaPath;
   uint16 thermAdc;
   uint16 band;
   uint8 tech;
   uint8 subband;
   uint8 nvContainerIdx;
   uint8 calSuccessful;
   uint8 numberOfFbrxModes;
   ftm_fbrxgain_mode_result modeResults[4]; // MAX_NUM_FBRX_GAIN_MODES
} ftm_fbrxgain_path_result;

typedef struct
{
   uint8 reserved;
   uint16 band;
   uint8 subband; /* Split band. A = 0,  B = 1, C = 2 */
   uint8 numberofRFMPaths;
   /* Number of RFM Paths */
   ftm_fbrxgain_path_result pathResults[8]; //FIX HARDCODING:  MAX_NUM_FBRX_RFM_PATHS
   /* Array of pointers to dynamically allocated Storage */
} cal_sweep_fbrx_gain_paths_results;


typedef struct ftm_xpt_delay_bw_info_type
{
  int32 min_bw_kHz;
  int32 max_bw_kHz;

  bool operator == ( const ftm_xpt_delay_bw_info_type& bw_info )
  const
  {
      if  ( min_bw_kHz == bw_info.min_bw_kHz && max_bw_kHz == bw_info.max_bw_kHz ) return true;
      else return false;
  }

  bool operator != ( const ftm_xpt_delay_bw_info_type& bw_info )
  const
  {
      if  ( min_bw_kHz != bw_info.min_bw_kHz || max_bw_kHz != bw_info.max_bw_kHz ) return true;
      else return false;
  }

  bool operator > ( const ftm_xpt_delay_bw_info_type& bw_info )
  const
  {
      if  ( min_bw_kHz > bw_info.min_bw_kHz && max_bw_kHz > bw_info.max_bw_kHz ) return true;
      else return false;
  }

  bool operator >= ( const ftm_xpt_delay_bw_info_type& bw_info )
  const
  {
      if  ( min_bw_kHz > bw_info.min_bw_kHz && max_bw_kHz > bw_info.max_bw_kHz ) return true;
      else return false;
  }

  bool operator <= ( const ftm_xpt_delay_bw_info_type& bw_info )
  const
  {
      if  ( min_bw_kHz < bw_info.min_bw_kHz && max_bw_kHz < bw_info.max_bw_kHz ) return true;
      else return false;
  }

  bool operator < ( const ftm_xpt_delay_bw_info_type& bw_info )
  const
  {
      if  ( min_bw_kHz < bw_info.min_bw_kHz && max_bw_kHz < bw_info.max_bw_kHz ) return true;
      else return false;
  }

} ftm_xpt_delay_bw_info_type;

typedef struct
{
  /* TX BW info */
  ftm_xpt_delay_bw_info_type bw_info;
  /*ADC temperature reading */
  uint32 therm_adc;  
  /* Number of TX Channels */
  uint8 numberOfChannels;
  /* TX num of channels */
  uint32 channelList[TXLIN_NUM_CHANNELS];
  /* ET analog delay based on freq */  
  int32 delay_vs_freq[TXLIN_NUM_CHANNELS];
} ftm_xpt_delay_bw_result;

typedef struct
{
  uint32 sig_path;
  uint64 xptDelayCalErrDebugMask;
  uint16 rfmDevice;
  uint16 antennaPath;
  uint16 thermAdc;
  uint16 band;
  uint8 tech;
  uint8 subband;
  uint8 nvContainerIdx;
  uint8 calSuccessful;
  uint8 numberOfBWs;
  /* XPT Delay BW Data type */  
  ftm_xpt_delay_bw_result bwResult[MAX_XPT_BW_COMBO];
} ftm_xpt_delay_path_result;

typedef struct
{
   uint8 reserved;
   uint16 band;
   uint8 subband; /* Split band. A = 0,  B = 1, C = 2 */
   uint8 numberofRFMPaths;
   ftm_xpt_delay_path_result pathResults[MAX_NUM_TX_PATHS]; 
} cal_sweep_xpt_delay_paths_results;

#define MAX_NUMBER_FBRX_AGC_RECORDS 96

typedef struct
{
   // Channel
   dword channel;

   // FBRx Mode
   byte fbrxMode;

   // FBRx Gain State
   byte fbrxGainState;

   // FBRx Gain Value
   word fbrxGain;

   // Power
   word power;

   // FBRx Ubias
   byte fbrxuBias;

   // FBRx RxScale
   word fbrxRxscale;
} cal_sweep_fbrx_gain_agc_tbl_record;

typedef struct
{
   // Flag to indicate to push Fb Gain Agc Table
   bool doFbGainAgcOp;

   // Field to mask different Fb Gain Data Types Records
   dword dataType;

   // Number of FB Gain Elements in the table
   byte numFbGainElements;

   // FBRx Agc Table Records
   cal_sweep_fbrx_gain_agc_tbl_record fbrx_agc_record[MAX_NUMBER_FBRX_AGC_RECORDS];

   // FBRx Gain Data
   cal_sweep_fbrx_gain_paths_results * ptr_fbrx_cal_data;
} cal_sweep_fbrx_gain_agc_tbl;

typedef struct
{
   // Flag to indicate Nominal DPD Load operation in the segment
   bool doDPDLoadOp;

   // XPT Type
   byte xptType;

   // Number of AMAM Values
   byte numAMAM;

   // AMAM Table
   word AMAM[QMSL_XPT_CAL_EXPANDED_PREDIST_SIZE];

   // Number of AMPM Values
   byte numAMPM;

   // AMPM Table
   word AMPM[QMSL_XPT_CAL_EXPANDED_PREDIST_SIZE];

   // Number of DET Values
   byte numDET;

   // DET Table
   word DET[QMSL_XPT_CAL_EXPANDED_DET_SIZE];
} cal_sweep_nom_dpd_tbl;

typedef struct
{
   // Flag to indicate M Point Calc operation in the segment
   bool doMPtCalcOp;

   // Linear Region Percent
   word linRegPct;

   // Compression Point EPT
   word compDBEpt;

   // Compression Point ET
   word compDBEt;

   // PA State EPT
   byte paEpt;

   // Compression Point ET
   byte paEt;

   // Curve Fit Type
   byte curveFitType;

   // Vd Max EPT
   dword vdMaxEpt;

   // Vd Max EPT
   dword vdMaxEt;

   // Vd Max EPT
   byte mlineBiasOption;

   // Number of Measured Powers in Swp1
   byte numSwp1MeasPwrs;

   // Number of EPT Powers to be measured in Swp2
   byte numSwp2EptMeasPwrs;

   // Number of EPT Powers to be calculated in Swp2
   byte numSwp2EptCalcPwrs;

   // Number of ET Powers to be measured in Swp2
   byte numSwp2EtMeasPwrs;

   // Number of ET Powers to be calculated in Swp2
   byte numSwp2EtCalcPwrs;

   // PA State for Measured Swp1
   byte swp1pa[10];

   // RGI for Measured Swp1
   byte swp1rgi[10];

   // Bias for Measured Swp1
   dword swp1bias[10];

   // Measured Powers in Swp1 * 100
   word measPwrSwp1DB10[10];

   // Measured Powers for Swp2 * 100
   word eptMeasPwrSwp2DB100[10];

   // Measured Powers for Swp2 * 100
   word eptCalcPwrSwp2DB100[10];

   // Measured Powers for Swp2 * 100
   word etMeasPwrSwp2DB100[10];

   // Measured Powers for Swp2 * 100
   word etCalcPwrSwp2DB100[10];
} cal_sweep_m_pt_calc;

typedef struct
{
   // Flag to indicate Delay Value data operation in the segment
   bool doDelayValProcOp;

   // Upper Bound Channel
   dword upperBoundChan;

   // 5MHZ Offset
   word fiveMHzOffset;

   // 10MHZ Offset
   word tenMHzOffset;

   // 20MHZ Offset
   word twentyMHzOffset;
} cal_sweep_delay_val_proc;

typedef struct
{
   // Flag to indicate Pin Value data operation in the segment
   bool doPinValProcOp;

   // Compression Point
   byte targetComp_dB10;

   // Current Channel
   dword currChannel;

   // PA State
   byte paState;

   byte processMask;
} cal_sweep_pin_val_proc;

typedef struct
{
   // Flag to indicate DPD Calc data operation in the segment
   bool do_dpd_calc_op;

   // XPT Mode
   byte xptMode;

   // Number of Powers to be measured in Swp2
   byte numSwp2MeasPwrs;

   // Number of Powers to be calculated in Swp2
   byte numSwp2CalcPwrs;

   // Measured Powers for Swp2 * 100
   word measPwrSwp2DB100[10];

   // Measured Powers for Swp2 * 100
   word calcPwrSwp2DB100[10];
} cal_sweep_dpd_calc;

typedef struct
{
   //Flag to inidicate MLine result fetch operation in the segment
   bool do_get_mline_res_op;

   //EPT MLine results action mask
   word eptMlineResAction;

   //ET MLine results action mask
   word etMlineResAction;

   //EPT PA State
   byte eptPAState;

   //ET PA State
   byte etPAState;

   //EPT number of selection sweep Measured target powers
   byte numEptSelSwpMeasPwrs;

   //EPT number of selection sweep Calculated target powers
   byte numEptSelSwpCalcPwrs;

   //EPT number of compression points
   byte numEptCompPts;

   //ET number of selection sweep Measured target powers
   byte numEtSelSwpMeasPwrs;

   //ET number of compression points
   byte numEtCompPts;

   //EPT number of amam rms values
   byte numEptAMAMRMSVals;

   //ET number of amam rms values
   byte numEtAMAMRMSVals;

   //EPT Selection sweep Measured target powers
   word eptSelSwpMeasPwrsdB100[QMSL_XPT_MAX_NUM_MEAS_POWERS];

   //EPT Selection sweep Calculated target powers
   word eptSelSwpCalcPwrsdB100[QMSL_XPT_MAX_NUM_MEAS_POWERS];

   //EPT expected Compression point Rgi
   byte eptCompPtRgi[QMSL_XPT_MAX_NUM_MEAS_POWERS];

   //EPT Compression point Bias
   dword eptCompPtBias[QMSL_XPT_MAX_NUM_MEAS_POWERS];

   //ET Selection sweep Measured target powers
   word etSelSwpMeasPwrsdB100[QMSL_XPT_MAX_NUM_MEAS_POWERS];

   //ET expected Compression point Rgi
   byte etCompPtRgi[QMSL_XPT_MAX_NUM_MEAS_POWERS];

   //ET Compression point Bias
   dword etCompPtBias[QMSL_XPT_MAX_NUM_MEAS_POWERS];
} cal_sweep_get_mline_res;

typedef struct
{
   // Flag to indicate DPD Calc data operation in the segment
   bool do_load_calc_dpd_op;

   // Load Action
   byte loadAction;

   // XPT Mode
   byte xptMode;

   // QPOET min voltage
   word qpoetMinV;

   // QPOET max voltage
   word qpoetMaxV;

   // ET min voltage
   word etMinV;

   // Number of Powers to be measured in Swp2
   byte numSwp2MeasPwrs;

   // Number of Powers to be calculated in Swp2
   byte numSwp2CalcPwrs;

   // Measured Powers for Swp2 * 100
   word measPwrSwp2DB100[10];

   // Measured Powers for Swp2 * 100
   word calcPwrSwp2DB100[10];
} cal_sweep_load_calc_dpd;

typedef struct
{
   // Flag to indicate Get XPT Capture Results Operation in the segment
   bool do_xpt_cap_res_op;

   // Result Mask
   dword xptResMask;

   // Number of Results
   dword xptCapNumRes;
} cal_sweep_get_xpt_cap_req;

typedef struct
{
   // Flag to indicate get seq execute results in the segment
   bool do_get_rf_cal_res_commit_nv_op;

   // Result_mask
   byte result_mask;

   // NV_write_mask
   byte nv_write_mask;

   // Band
   word band;

   // Subband. Zero for regular band and split band A. Split band B (e.g., 41B): 1,  Split Band C: 2
   byte subband;

} cal_sweep_get_rf_cal_res_commit_nv_req;

typedef struct
{
   //Flag to indicate that segment has opcode to push swp1 measurements from connected cal, to phone.
   bool do_push_swp1_pwr_meas_conn;

   //number of pwr measments
   byte num_meas_pwrs;

   byte pa_state[MAX_NUM_STG1_CAPTURES*MAX_NUM_XPT_MODES]; // max number of stg1 captures * max number of support XPT modes.

   byte rgi[MAX_NUM_STG1_CAPTURES*MAX_NUM_XPT_MODES];

   word bias[MAX_NUM_STG1_CAPTURES*MAX_NUM_XPT_MODES];

   word pwr_meas[MAX_NUM_STG1_CAPTURES*MAX_NUM_XPT_MODES];

} cal_sweep_swp1_pwrs_conn;

#define MAX_NUM_LUT_DELTA_GAIN_PIN_POUT   4
#define MAX_NUM_PIN_DELTA_GAIN_PIN_POUT   8
#define MAX_NUM_ROW_DELTA_GAIN_PIN_POUT   MAX_NUM_PIN_DELTA_GAIN_PIN_POUT

typedef struct
{
   byte dpd_tbl_idx;
   byte align_swp_idx;
   byte lut_step_size;
   int8 pin_misalign_min;
   int8 pin_misalign_max;
} cal_sweep_delta_gain_pin_pout_calc_item;

typedef struct
{
   int8 misalign_pin;
   int8 gain_compression;
   int8 delta_pout;
} cal_sweep_delta_gain_pin_pout_lut_row;

typedef struct
{
   byte num_lut_row;
   byte dpd_tbl_idx;
   cal_sweep_delta_gain_pin_pout_lut_row row[MAX_NUM_ROW_DELTA_GAIN_PIN_POUT];
} cal_sweep_delta_gain_pin_pout_lut_item;

typedef struct
{
   bool do_delta_gain_pin_pout_calc_op;

   byte num_lut;
   cal_sweep_delta_gain_pin_pout_calc_item lut[MAX_NUM_LUT_DELTA_GAIN_PIN_POUT];//   vector<cal_sweep_delta_gain_pin_pout_calc_item> lut_req;
} cal_sweep_delta_gain_pin_pout_calc;

typedef struct
{
   bool do_delta_gain_pin_pout_load_op;
} cal_sweep_delta_gain_pin_pout_load;

typedef struct
{
   byte num_lut;
   cal_sweep_delta_gain_pin_pout_lut_item lut[MAX_NUM_LUT_DELTA_GAIN_PIN_POUT];
} cal_sweep_delta_gain_pin_pout_load_res_type;

typedef struct
{
   // Version
   byte version;

   // Debug Mode
   byte debugMode;

   // Flag
   word flag;

   /* The band that cal has to be performed in.
   * CDMA = 0
   * WCDMA = 1
   * GSM = 2
   * LTE = 10
   * TDSCDMA = 11
   */
   byte tech;

   // Ref Channel
   dword refChan;

   // Device
   byte dev;

   // Data Action
   dword dataAction;

   // RGI vs Power Type
   cal_sweep_rgi_vs_pwr rgiVsPwr;

   // RGI vs Power vs State Type
   cal_sweep_rgi_vs_pwr_vs_state rgiVsPwrVsState;

   // Nominal DPD Table Type
   cal_sweep_nom_dpd_tbl nomDPDTbl;

   // M - Point Line Calc Type
   cal_sweep_m_pt_calc mptCalc;

   // Delay Value Processing Type
   cal_sweep_delay_val_proc delayValProc;

   // Pin Value Processing Type
   cal_sweep_pin_val_proc pinValProc;

   // FBRx Agc Table Type
   cal_sweep_fbrx_gain_agc_tbl fbrxAgcTbl;

   // DPD Calculation Type
   cal_sweep_dpd_calc dpdCalc;

   // Load Calc DPD Type
   cal_sweep_load_calc_dpd loadCalcDpd;

   // MLine result params
   cal_sweep_get_mline_res getMlineRes;

   // XPT Capture Results
   cal_sweep_get_xpt_cap_req xptCapReq;

   // Seq Execute Results
   cal_sweep_get_rf_cal_res_commit_nv_req getRfCalResCommitNvReq;

   cal_sweep_swp1_pwrs_conn swp1ConnPwrMeas;
   // Flag to indicate data operation in the segment
   bool doDataOp;

   // Delta Gain Pin Pout Calculation params
   cal_sweep_delta_gain_pin_pout_calc deltaGainPinpoutCalc;
   // Delta Gain Pin Pout Load Flag
   cal_sweep_delta_gain_pin_pout_load deltaGainPinPoutLoad;

} cal_sweep_data;


typedef enum
{
   POLL_EVENT_MASK_EPT_EXPANSION_DONE =  0x1,  //Bit 0

   POLL_EVENT_MASK_RX_THRESHOLD_REACHED = 0x2, //Bit 1,

   POLL_EVENT_MASK_EPT_PROCESSING_DONE = 0x4, //Bit 2

   POLL_EVENT_MASK_SEQ_BLD_DONE = 0x8, //Bit 3

   POLL_EVENT_MASK_SEQ_EXEC_DONE = 0x10, //Bit 4


} polling_event_mask_type;

typedef enum
{
   SEQ_TYPE_UNDEFINED,

   SEQ_RADIO_SETUP,

   SEQ_MULTI_RX_CFG_MEAS,

   SEQ_FD_RX_RSB,

   SEQ_FBRX_DROOP_RSB,

   SEQ_FREQ_COMP,

   SEQ_APT_CAL,

   SEQ_XPT_CAL,

   SEQ_DELAY_CAL,

   SEQ_FBRXGAIN_CAL,

   SEQ_GSM_TX_CAL,

   NUM_SEQ_TYPE,

   SEQ_TYPE_MAX = 0xFFFF
} sequence_type;

typedef enum
{
   RFM_PATH_TYPE_TX = 0,

   RFM_PATH_TYPE_PRX = 1,

   RFM_PATH_TYPE_DRX = 2,

   RFM_PATH_TYPE_INVALID = 0xFF
} ftm_rfm_path_type;

typedef enum
{
   RADIO_SETUP_TECH_BAND_PATH_CHAN = 0,

   RADIO_SETUP_BAND_PATH_CHAN = 1,

   RADIO_SETUP_PATH_CHAN = 2,

   RADIO_SETUP_CHAN = 3,

   RADIO_SETUP_BANDWIDTH = 4,

   RADIO_SETUP_ANT_SWITCH = 5,

   RADIO_SETUP_INVALID = 0xFF
} ftm_radio_setup_type;

typedef enum
{
   TX_WFM_DEFAULT = 0,

   TX_WFM_CW = 1,

   TX_WFM_OFFSET_CW = 2,

   TX_WFM_OFFSET_LTE_PUSCH = 3,

   TX_WFM_OFFSET_EUL = 4,

   TX_WFM_DPD = 5,

   TX_WFM_WCDMA_DUAL_CARRIER = 6,

   TX_WFM_INVALID = 0xFFFF
} ftm_tx_wfm_type;

/**
A listing of all potential RF devices in the system.

Not all instances of the RF driver will support every device
enumerated below.  Some devices may only support Rx, some may
support both Rx and Tx.
*/
typedef enum
{
   /*! RF Device 0 */
   RFM_DEVICE_0,

   /*! RF Device 1 */
   RFM_DEVICE_1,

   /*! RF Device 2 */
   RFM_DEVICE_2,

   /*! RF Device 3 */
   RFM_DEVICE_3,

   /*! RF Device 4 */
   RFM_DEVICE_4,

   /*! RF Device 5 */
   RFM_DEVICE_5,

   /*! Max WAN devices */
   RFM_MAX_WAN_DEVICES,

   /*! RF GPS Device */
   RFM_DEVICE_GPS,

   /*! @deprecated This should not be used to size arrays, but is provided
   for legacy support.  */
   RFM_MAX_DEVICES,

   /*! Can be used to indicate an invalid RFM device.  */
   RFM_INVALID_DEVICE,

   /*! Wild card to indicate ALL RFM Devices*/
   RFM_ALL_DEVICES = 0xFFFF
} rfm_device_enum_type;

typedef enum
{
   RS_PATH_ACTION_OFF = 0,
   RS_PATH_ACTION_ON = 1,
   RS_PATH_ACTION_INVALID = 0xFF
} ftm_rs_path_action;

typedef enum
{
   APT_SEQ_FULL_BIAS_LIN = 0,
   APT_SEQ_APT_LIN = 1,
   APT_SEQ_FCOMP = 2,
   APT_SEQ_DELTA_FCOMP = 3,
   APT_SEQ_MAX = 0xFF
} apt_seq_enum_type;

typedef enum
{
   GSM_TX_CALIBRATION_TYPE_DA = 0,

   GSM_TX_CALIBRATION_TYPE_DPD = 1,

   GSM_TX_CALIBRATION_TYPE_MAX

} GSM_TX_CALIBRATION_TYPE;

typedef enum
{
   QSC_LIN_EXP_PWR_OPTION_PER_RGI = 1,

   QSC_LIN_EXP_PWR_OPTION_GAIN = 2,

   QSC_LIN_EXP_PWR_OPTION_MAX

} QSC_LIN_EXP_PWR_OPTION_TYPE;

typedef enum
{
   QSC_LIN_LIMIT_OPTION_DISABLE = 0,

   QSC_LIN_LIMIT_OPTION_USE_LIMIT = 1,

   QSC_LIN_LIMIT_OPTION_MAX

} QSC_LIN_LIMIT_OPTION;

typedef struct
{
   uint16 rfmDevice;
   uint32 sigPath;
   uint16 antennaSwitchPath;
   uint16 reserved;
} rfm_path_type;

typedef enum
{
   SIGNAL_PATH_DEFAULT = 0xFFFF,
   ANTENNA_PATH_DEFAULT = 0xFFFF,
   RFM_DEVICE_DEFAULT = 0xFFFF
} default_rfm_path_values;

typedef struct
{
   rfm_device_enum_type rfm_device;
   uint32 sig_path;
} rf_lte_ftm_rfm_path_type;

typedef struct
{
   uint8 path_active[RFLM_LTE_PATH_TYPE_MAX];
   rf_lte_ftm_rfm_path_type rfm_path[RFLM_LTE_PATH_TYPE_MAX];
   uint16 band;
   uint8 rx_bw;
   uint8 tx_bw;
   uint32 rx_chan;
   uint32 tx_chan;
} rfa_rf_lte_ftm_rf_config_chain_data;

typedef struct
{
   uint8 rfm_path_override;
   rfa_rf_lte_ftm_rf_config_chain_data path_params[RFLM_LTE_CC_MAX];
} rfa_rf_lte_ftm_rf_config_data;

/* The first 5 entries are for memoryless DPD, The last 20 entries are for memory DPD. */

#define XPT_DPD_NUM_COEFF 16

#define RFCOM_TXLIN_MEMORYLESS_VOLTERRA_NUM_KERNEL_WEIGHTS    5

#define RFCOM_TXLIN_MEMORY_VOLTERRA_NUM_KERNEL_WEIGHTS        20

/*----------------------------------------------------------------------------*/
/*!
@brief
Structure used to hold the unpacked sequence build radio setup parameters
*/
typedef struct
{
   uint16 band;

   uint8 subBand;

   uint8 bwType;

   uint8 numChannels;

   uint32 channelList[MAX_NUM_CHAN_QSC_RADIO_CONFIG_V1];

   rfm_path_type rfmPath;

   uint8 nvContainerId;

   uint8 rfmPathType;

   uint8 txWfmType;

   uint32 cwOffset;

   uint8 numRBs;

   uint8 startRBIdx;

} ftm_cal_seq_bld_radio_setup_path_params;


typedef struct
{
   byte radioSetupType;

   word tech;

   byte isTearDown;

   byte numRFMPaths;//RFM path = rfm_dev + signal_path

   ftm_cal_seq_bld_radio_setup_path_params radioSetupPathParams[MAX_NUM_RFM_PATHS];

} ftm_cal_seq_bld_radio_setup_path_params_v0;


typedef struct
{
   byte version;

   union
   {
      ftm_cal_seq_bld_radio_setup_path_params_v0 radioSetupV0;
   };

} ftm_cal_seq_bld_radio_setup_params;


typedef struct
{
   uint8 lnaGainState; //LNA gain state to be configured for Rx measurement

   uint16 agcSettlingTime; //WTR ADC Settling time

   uint16 accumulationTime; //Samples Accumulation Time

   uint8 measType;

} ftm_cal_seq_bld_fd_rx_rsb_params_v0;

typedef struct
{
   byte version;

   union
   {
      ftm_cal_seq_bld_fd_rx_rsb_params_v0 fdRxRSB_V0;
   };

} ftm_cal_seq_bld_fd_rx_rsb_params;


typedef struct cal_txoveride_parameters
{
   /* Mode of PA operation. 0 - APT, 1 - EPT, 2 - ET */
   uint8 xptMode;

   /* parameters to override for Tx Configuration. Each bit overrides a particular Tx parameter.
      Refer to ESC_TX_OVERRIDE_TYPE enumeration for bit mask definition */
   uint8 txPowerOverridebitMask;

   /* PA State */
   uint8 paState;

   /* RGI */
   uint16 rgi;

   /* Bias */
   uint16 biasinmilliVolts;

   /* IQ Gain Action. Refer to ESC_TX_OVERRIDE_ACTION_TYPE enumeration for action  definition */

   uint8 iqgainAction;

   /* IQ Gain Value */
   uint32 iqGainValue;

   /* Envelope Scale Action.
   */
   uint8 envScaleAction;

   /* Envelope Scale Value, Refer to ESC_TX_OVERRIDE_ACTION_TYPE enumeration for action  definition */
   uint32 envScaleValue;

   /* Quiescent Current */
   uint16 quiescentCurrent;

   /* Delay Action,Refer to ESC_TX_OVERRIDE_ACTION_TYPE enumeration for action  definition*/
   uint8 delayAction;

   /* Delay Value  */
   int32 delayValue;
} ftm_seq_bld_fbrxgain_txoverrideParameters;

typedef struct cal_fbrx_parameters
{
   /*!< FBRx Gain State to Calibrate */
   byte fbrxGainState;

   /* Expected Power in to the FBRx Path(FBRx Calibration Tx Powers) */
   int16 expectedPowerdBm10;

} ftm_cal_seq_bld_fbrxgain_fbrxParameters;


#define MAX_NUM_OVERRIDES 100

typedef enum
{
   TX_OVERRIDE_FBRX_GAIN_MEASURE  = 0,
   TX_OVERRIDE_ONLY = 1,
} ftm_fbrx_purpose_type;

typedef struct
{
   /* defines the purpose. Enumerations defined in ftm_fbrx_purpose_type */
   uint8 purposeType;

   /* Number of FBRx Gain States to calibrate. */
   uint16 numberofOverrides;

   /* FBRx Gain Settings for Gain States. */
   ftm_cal_seq_bld_fbrxgain_fbrxParameters fbrxParameters[MAX_NUM_OVERRIDES];

   /* Tx Settings for Gain States. */
   ftm_seq_bld_fbrxgain_txoverrideParameters txOverrideParameters[MAX_NUM_OVERRIDES];
} ftm_seq_cal_bld_fbrxgain_parameters_v0;

typedef struct 
{
   /*!< XPT Delay Channel */
   uint32 channelList[TXLIN_NUM_CHANNELS];
   /*!< XPT Delay Upper Bound Channel */
   uint32 upperBounChannelList[TXLIN_NUM_CHANNELS];
   /*!< ET Delay Compression Point */
   word compresionPt; 
   /*!< XPT Delay Min Delay Limit */
   word delayValMin;
   /*!< XPT Delay Max Delay Limit */
   word delayValMax;

   word epdt[QMSL_XPT_CAL_EXPANDED_DET_SIZE];

} ftm_cal_seq_xpt_delay_parameters;

typedef struct
{
   /* FBRx Gain Settings for Gain States. */
   ftm_cal_seq_xpt_delay_parameters delayParameters;

   /* Tx Settings for Gain States. */
   ftm_seq_bld_fbrxgain_txoverrideParameters txOverrideParameter;
} ftm_seq_cal_bld_xpt_delay_parameters;


typedef enum
{
   FTM_CAL_SEQ_FBRXGAIN_BLD_VERSION0  = 0,
} ftm_fbrxgain_build_version;

typedef struct
{
   uint8 version;
   union
   {
      ftm_seq_cal_bld_fbrxgain_parameters_v0 version0;
   } fbrxGainbuildParameters;
} ftm_seq_cal_bld_fbrxgain_parameters;

typedef struct
{
   /* Gain State to calibrate. */
   uint16 overrideIndex;
} ftm_seq_cal_exec_fbrxgain_parameters_v0;

typedef struct
{
   uint8 version;
   union
   {
      ftm_seq_cal_exec_fbrxgain_parameters_v0 version0;
   } fbrxGainexecParameters;
} ftm_seq_cal_exec_fbrxgain_parameters;

typedef struct
{
   int16 rxmax;
   int16 rxmin;
} ftm_cal_seq_bld_rx_limit_type;

/*----------------------------------------------------------------------------*/
/*!
@brief
Structure used to hold the unpacked sequence build multi rx config and measure per device parameters
*/
typedef struct
{
   uint32 signal_path; //signal path
   uint16 rfm_device; //RFM device
   uint16 switch_port;
   uint16 reserved;
   ftm_cal_seq_bld_rx_limit_type rx_limit[MAX_LNA_GAIN_STATE];
} ftm_cal_seq_bld_multirx_target_path_type;

typedef struct
{
   uint16 number_of_paths; //if 0, multi-RX will use all RX paths in RadioSetup as target path.
   ftm_cal_seq_bld_multirx_target_path_type target_paths[MAX_NUM_MULTIRX_PATHS];
} ftm_cal_seq_bld_multirx_target_path_list;

/*----------------------------------------------------------------------------*/
/*!
@brief
Structure used to hold the unpacked sequence build multi rx config and measure parameters
*/
typedef struct
{
   uint8 version;

   uint16 band;

   uint8 subBand;

   uint8 meas_type;

   uint8 meas_purpose;

   uint16 gain_state_bit_mask;

   ftm_cal_seq_bld_multirx_target_path_list target_path_list;

   uint8 pwr_mode[MAX_LNA_GAIN_STATE];

   int16 exp_rxagc[MAX_LNA_GAIN_STATE];

   uint8 nv_action_flag;

   uint8 limit_option;

   ftm_cal_seq_bld_rx_limit_type rx_limit[MAX_LNA_GAIN_STATE];

   uint16 agc_settling_time;

   uint16 accumulation_time;

   uint16 size;

   int dl_power; //this field is not to be sent to DUT
} ftm_cal_seq_bld_multi_rx_cfg_meas_parameter_type;

typedef struct
{
   byte paState;

   word maxBias;

   word maxIcq;

   byte numRGIs;

   word rgi[TXLIN_NUM_SEGMENTS];

   byte expPwrOption;

   int16 expPwr[TXLIN_NUM_SEGMENTS];

   int16 paGain;

   byte limitOption;

   int16 maxPwr;

   int16 minPwr;

   int16 minDeltaPwr;
} ftm_cal_seq_bld_lin_per_pa_param_type;

typedef struct
{
   dword upperBoundChannel;

   byte numPAStates;

   ftm_cal_seq_bld_lin_per_pa_param_type aptLin[8];
} ftm_cal_seq_bld_apt_seq_lin_parameter_type;

typedef struct
{
   byte numPaStates;

   byte paStates[8];

   byte numEntriesPerPa[8];

   int16 aptPowers[256];

   word aptBias[256];

   word aptIcq[256];

   byte gainDeltaOption;

   int16 gainDeltas[256];
} ftm_cal_seq_bld_apt_seq_apt_char_data_type;

typedef struct
{
   byte numFcompChans;

   byte numFcomps;

   byte paStateList[64];

   byte rgiPwrSelectList[64];

   int16 powerList[64];

   int16 aptFreqCompOffsetList[64];

   word rgiList[64];

   word rgiThresholdList[64];

   byte limitOption;

   int16 maxdBList[64];

   int16 mindBList[64];
} ftm_cal_seq_bld_apt_seq_fcomp_parameter_type;


typedef struct
{
   byte aptSeqType;

   byte version;

   ftm_cal_seq_bld_apt_seq_apt_char_data_type aptCharData;

   ftm_cal_seq_bld_apt_seq_lin_parameter_type linParams;

   ftm_cal_seq_bld_apt_seq_fcomp_parameter_type fcompParams;
} ftm_cal_seq_bld_apt_seq_parameter_type;

typedef struct
{
   uint16 rgi;
   uint16 bias;
} rgiBiasType;

typedef struct
{
   byte xpt_seq_actn;
   /*!< Flag indicating where to stop XPT SM */
   byte get_xpt_dbg_info;
   /*!< Bool Flag indicating whethere to write to the result packet */
   byte rgi_delta_src_from_parms;

   byte rgi_delta_start;

   byte rgi_delta_stop;

   byte rgi_delta_step;

   unsigned int num_captures;

   byte xpt_mode;

   byte exp_pwrs_in_params;

   //IF XPT moDe is EPT send EPDT.
   word epdt[QMSL_XPT_CAL_EXPANDED_DET_SIZE];

   byte paState;

   uint32 upperBoundChannel;

   word icq;

   rgiBiasType rb[MAX_NUM_STG1_CAPTURES];

   int16 exp_pwr_db10[MAX_NUM_STG1_CAPTURES];

   uint16 mline_rsvd_flag;

   uint16 comp_dB;

   byte curve_fit_type;

   uint16 vd_max;

   uint16 vd_min[MAX_TARGET_MEAS_PTS];

   byte num_target_meas_pwrs;

   byte num_target_calc_pwrs;

   int16 target_meas_pwrs[MAX_TARGET_MEAS_PTS];

   int16 target_calc_pwrs[MAX_TARGET_CALC_PTS];

   uint32 kernel_mask;

   uint8 num_fcomps;

   uint8 num_fcomp_chans;

   int16 fcomp_meas_pwr_idx[MAX_TARGET_MEAS_PTS];

   uint8 limit_option; // 0 - Don't Check power limits, only compression limits , 1 - Check Power limits and Compression point limits.

   int16 stg1_highlim[MAX_NUM_STG1_CAPTURES];

   int16 stg1_lowlim[MAX_NUM_STG1_CAPTURES];

} ftm_cal_seq_bld_xpt_params;

typedef struct
{
   byte pa_state;

   byte mod_type_mask;

   byte num_rgi;

   word rgi[TXLIN_NUM_SEGMENTS];

   byte exp_pwr_option;

   int16 exp_pwr[TXLIN_NUM_SEGMENTS];

   int16 pa_gain;

   byte limit_option;

   int16 max_pwr;

   int16 min_pwr;

   int16 min_delta_pwr;

} ftm_gsm_tx_da_cal_per_pa_param_type;

typedef struct
{
   byte num_pa_states;

   ftm_gsm_tx_da_cal_per_pa_param_type pa_params[MAX_PA_STATES];

} ftm_gsm_tx_da_cal_param_type;

typedef struct
{
   byte dpd_pa_state;

   byte dpd_cal_rgi_src;

   word dpd_cal_rgi;

   int16 exp_pwr;

} ftm_gsm_tx_dpd_cal_param_type;

typedef struct
{
   byte cal_type;

   ftm_gsm_tx_da_cal_param_type da_cal_params;

   ftm_gsm_tx_dpd_cal_param_type dpd_cal_params;

} ftm_cal_seq_bld_gsm_tx_cal_params;

typedef struct cal_seq_build
{
   byte version;

   byte debugMode;

   word reserved;

   word seqType;

   dword handle;
   /*!< Handle/ID under which to store the prepared sequence, so that the execute action can use it later. */

   ftm_cal_seq_bld_radio_setup_params radioSetupParams;

   ftm_cal_seq_bld_xpt_params xptSeqParams;

   ftm_cal_seq_bld_multi_rx_cfg_meas_parameter_type multiRxCfgMeas;

   ftm_seq_cal_bld_fbrxgain_parameters fbrxGainParameters;

   ftm_cal_seq_bld_apt_seq_parameter_type aptSeq;

   ftm_cal_seq_bld_fd_rx_rsb_params fdRxRSBParams;

   ftm_cal_seq_bld_gsm_tx_cal_params gsmTxCalParams;

   ftm_seq_cal_bld_xpt_delay_parameters xptDelayParameters;

   byte supportParallel;

} cal_sweep_seqbuild;

typedef struct cal_seq_exec
{
   byte version;

   byte debugMode;

   word reserved;

   word seqType;

   dword handle;

   byte aptSeqType;

   byte aptSeqVersion;

   byte supportParallel;

   ftm_seq_cal_exec_fbrxgain_parameters fbrxGainParameters;

   byte offset_flag;

} cal_sweep_seqexec;


typedef struct cal_seq_done_event_parms_n
{
   unsigned long seq_type;

   unsigned long handle_id;
} cal_seq_done_event_parms_t;

/*  Structure for polling opcode params */

typedef struct
{
   byte version;

   byte debugMode;

   word flag;

   // us after which the polling opcode will timeout
   unsigned long timeout_us;

   //Events to poll.
   unsigned long long event_mask;

   cal_seq_done_event_parms_t seq_bld_parm;

   cal_seq_done_event_parms_t seq_exec_parm;

} cal_sweep_polling;

typedef struct
{
   // DPD Valid Flag
   byte dpdValid;

   // XPT Mode
   byte xptMode;

   // RGI for the row
   word rgi;

   // Bias for the row
   word smpsBias;

   // PA State for the row
   byte paState;

   // Measured or Calculated
   byte measured;

   // Requested Power
   word power;

   // AMAM Table for NV
   word amamRes[QMSL_XPT_CAL_PREDIST_SIZE];

   // AMPM Table for NV
   word ampmRes[QMSL_XPT_CAL_PREDIST_SIZE];
} cal_sweep_data_dpd_proc_action_res_type;

typedef struct
{
   // DET Valid Flag
   byte detValid;

   // Measured or Calculated
   byte measured;

   // Detrough Table
   word epdtTbl[QMSL_XPT_CAL_EXPANDED_DET_SIZE];
} cal_sweep_data_load_dpd_epdt_res_type;

typedef struct
{
   // Channel for delay calc
   dword delayChan;

   // BW for Delay Calc
   dword delayBw;

   // Delay Value returned from UE
   dword delayVal;
} cal_sweep_data_delay_val_proc_res_type;

typedef struct
{
   // Channel for Pin calc
   dword pinChan;

   // Computed Pin back off
   dword pinCompensation;

   // Peak compression achieved for the channel
   byte pinPeakCompression;

   // Status of Pin Cal. 1: Success and 0: Failure
   byte isPinCalSuccessful;
} cal_sweep_data_pin_cal_proc_res_type;

typedef struct
{
   // Channel for Pin calc
   dword pinChan;

   // Extra process mask for extended PIN CAL
   byte processMask;

   // Extra process status mask for extended PIN CAL
   byte statusMask;

   // Computed Pin back off
   dword pinCompensation;

   // Peak compression achieved for the channel
   byte pinPeakCompression;

   // AMPM Scaling factor
   dword ampmScalingFactor;
} cal_sweep_data_ext_pin_cal_proc_res_type;

typedef struct
{
   //XPT rgi used during IQ capture
   byte rgi;

   //Bias calculated from MLine
   dword bias_out;

   //Power calculated from MLine
   dword pow_out_db100;
} cal_sweep_mline_outputs_res_type;

typedef struct
{
   // Number of rows in the M Line table
   byte num_mline_table_rows;

   // Result structure to hold M Line table output for each row
   cal_sweep_mline_outputs_res_type mline_results[TXLIN_NUM_SEGMENTS];
} cal_sweep_mline_table_res_type;

typedef struct
{
   // Selection sweep valid flag
   byte selec_swp_valid;

   // Selection Sweep Rgi
   byte selec_swp_rgi;

   //Selection Sweep power
   word selec_swp_pwr;

   //Selection Sweep Bias
   dword selec_swp_bias;
} cal_sweep_mline_selec_sweep_outputs_res_type;

typedef struct
{
   // Number of selection sweep rows
   byte num_selec_swp_pwrs;

   // Selection Sweep results structure
   cal_sweep_mline_selec_sweep_outputs_res_type selec_sweep_table[QMSL_XPT_MAX_NUM_MEAS_POWERS];
} cal_sweep_mline_selec_res_type;

typedef struct
{
   // Number of compression points
   byte num_compr_pt;

   // List to hold compression in voltage
   byte compr_pt_list [QMSL_XPT_MAX_NUM_MEAS_POWERS];
} cal_sweep_mline_compr_pt_res_type;

typedef struct
{
   // M Line co-efficient a
   dword vout_vin_a;

   // M Line co-efficient b
   dword vout_vin_b;

   // M Line co-efficient c
   dword vout_vin_c;

   // M Line co-efficient d
   dword vcc_vin_d;

   // M Line co-efficient e
   dword vcc_vin_e;

   // M Line co-efficient f
   dword vcc_vin_f;
} cal_sweep_mline_slope_res_type;

typedef struct
{
   // Number of amam rms values
   byte num_amam_rms_values;

   // AMAM RMS value for each capture
   dword amam_rms_val[QMSL_XPT_MAX_NUM_MEAS_POWERS];
} cal_sweep_mline_amam_rms_res_type;

typedef struct
{
   // M Line table struct
   cal_sweep_mline_table_res_type mline_table_res;

   // Selection Sweep meas struct
   cal_sweep_mline_selec_res_type selec_swp_meas_res;

   // Selection Sweep calculated struct
   cal_sweep_mline_selec_res_type selec_swp_calc_res;

   // Compression results struct
   cal_sweep_mline_compr_pt_res_type compr_pt_res;

   // M line slope-intercept results struct
   cal_sweep_mline_slope_res_type mline_slope_res;

   // AMAM RMS value for each capture
   cal_sweep_mline_amam_rms_res_type mline_amam_rms_res;

   //M line debug mask
   dword mline_debug_mask;
} cal_sweep_xpt_mline_res_type;

typedef struct
{
   // DPD Valid Flag
   byte dpdValid;

   // XPT Mode
   byte xptMode;

   // RGI for the row
   word rgi;

   // Bias for the row
   word smpsBias;

   // PA State for the row
   byte paState;

   // ICq for the row
   dword icq;

   // IQ Gain for the row
   dword iqGain;

   // Env Scale for the row
   dword envSc;
} cal_sweep_xpt_cap_common_res_type;

typedef struct
{
   // Compression for the row
   word compression;
} cal_sweep_xpt_cap_comp_res_type;

typedef struct
{
   // AMAM Table for NV
   word amamRes[QMSL_XPT_CAL_PREDIST_SIZE];

   // AMPM Table for NV
   word ampmRes[QMSL_XPT_CAL_PREDIST_SIZE];
} cal_sweep_xpt_cap_dpd_res_type;

typedef struct
{
   //Rx PAR
   word rxPar;
} cal_sweep_xpt_cap_rx_par_res_type;

typedef struct
{
   //Rx RMS
   dword rxRms;
} cal_sweep_xpt_cap_rx_rms_res_type;

typedef struct
{
   // Common Result Type
   cal_sweep_xpt_cap_common_res_type xptCapCommonRes;

   // Compression Result Type
   cal_sweep_xpt_cap_comp_res_type xptCapCompRes;

   // DPD Result Type
   cal_sweep_xpt_cap_dpd_res_type xptCalDpdRes;

   // Rx PAR
   cal_sweep_xpt_cap_rx_par_res_type xptCalRxParRes;

   //Rx RMS
   cal_sweep_xpt_cap_rx_rms_res_type xptCalRxRmsRes;
} cal_sweep_xpt_cap_res_type;

typedef struct
{
   // XPT Capture Result Mask
   dword xptCapResMask;

   // Number of Results
   dword xptCapNumRes;

   // XPT Capture Results
   cal_sweep_xpt_cap_res_type xptRes[100];
} cal_sweep_data_xpt_cap_res_type;

typedef struct
{
   // Data Type
   byte data_type;

   // nv id
   word nv_id;

   // nv write time
   dword nv_write_time;

} cal_sweep_data_push_fbrx_res_type;
typedef struct
{
   /* RGI/LUT index */
   uint16 rgi;
   /* TxAGC in dB10 unit*/
   int16  power;
   /* Lower 16 bits kept as bias voltage for backwards compatibility */
   uint16 pa_bias_voltage;
   /* PA quiescent current setting */
   uint16 pa_q_current;
   /* DPD index */
   uint16 dpd_index;
   /* IQ offset for temp comp*/
   uint8 iq_offset;
   /* Index indicates the freq-comp array to use */
   uint16 fcomp_idx;
} seq_cal_tx_lin_row_type;

typedef struct
{
   uint8 num_valid_rows;

   /*! The DPD type used by this linearizer */
   QMSL_MULTILIN_V3_XPT_DPD_TYPE_ENUM dpd_type;

   /*! The number of DPDs used by this line*/
   uint16 num_dpd;

   seq_cal_tx_lin_row_type table[64];  //FIX HARDCODING: NUM LINE TABLE ENTRIES

} seq_cal_tx_cal_res_linearizer_tbl_type;


typedef struct
{
   int16 kw_i;  /* kernel weight I */
   int16 kw_q;  /* kernel weight Q */
} volterra_kernel_weight_type;

/* Every EPT/ET cal point (RGI) has one Volterra DPD config data set */
typedef struct
{
   /* Volterra kernel weights mask */
   uint32 kernel_config;
   uint16 memless_scaling;
   uint16 memory_scaling;

   volterra_kernel_weight_type memless_kw[RFCOM_TXLIN_MEMORYLESS_VOLTERRA_NUM_KERNEL_WEIGHTS];
   volterra_kernel_weight_type memory_kw[RFCOM_TXLIN_MEMORY_VOLTERRA_NUM_KERNEL_WEIGHTS];

} ept_vt_row_type;

/* Every EPT/ET cal point (RGI) has one Volterra DPD config data set */
typedef struct
{
   /* Volterra kernel weights mask */
   uint32 kernel_config;
   uint16 memless_scaling;
   uint16 memory_scaling;

   volterra_kernel_weight_type memless_kw[RFCOM_TXLIN_MEMORYLESS_VOLTERRA_NUM_KERNEL_WEIGHTS];
   volterra_kernel_weight_type memory_kw[RFCOM_TXLIN_MEMORY_VOLTERRA_NUM_KERNEL_WEIGHTS];

   /* Volterra De-trough table */
   uint16 xpt_dt[XPT_DPD_NUM_COEFF];

} et_vt_row_type;

/*! Contains AMAM/AMPM items for a single RGI  */
typedef struct
{
   uint16 xpt_am[XPT_DPD_NUM_COEFF];
   int16 xpt_pm[XPT_DPD_NUM_COEFF];
} ept_dpd_row_type;

/*! Contains AMAM/AMPM/De-Trough items for a single RGI  */
typedef struct
{
   uint16 xpt_am[XPT_DPD_NUM_COEFF];
   int16 xpt_pm[XPT_DPD_NUM_COEFF];
   uint16 xpt_dt[XPT_DPD_NUM_COEFF];
} et_dpd_row_type;

typedef union
{
   ept_dpd_row_type ept_dpd;
   et_dpd_row_type et_dpd;
   ept_vt_row_type ept_vt;
   et_vt_row_type et_vt;
} xpt_vt_row_type;

typedef struct
{
   // tx apt linearlizer result
   seq_cal_tx_cal_res_linearizer_tbl_type tx_linearizer_table;

   // tx xpt linearlizer result
   xpt_vt_row_type xpt_linearlizer_table[10];
} seq_cal_tx_cal_res_linearizer_tbl_data_type;

typedef struct
{
   /* pass fail status for frequency compenstaion. */
   uint8 fcomp_cal_status;

   uint8 fcomp_type;

   uint16 fcomp_idx;

   /* Frequency compensation offsets from center channel  */
   int8 fcomp[MAX_NUM_FCOMP_CHANS_QSC];
} seq_cal_tx_freq_comp_tbl_type;

typedef struct
{
   uint32 lin_entry_mask;

   uint8 pa_state;

   uint8 linearizer_table_mask;

   seq_cal_tx_cal_res_linearizer_tbl_data_type linearizer_tbl_data[MAX_NUM_WFM_TYPES_QSC];

   uint8 num_fcomp;

   seq_cal_tx_freq_comp_tbl_type freq_comp_data[MAX_NUM_PA_STATES_QSC];

} seq_cal_tx_cal_res_per_pa_data_type;

typedef struct
{
   uint32 ref_channel;

   uint32 upper_bound_channel;

   uint32 tx_cal_chan[MAX_NUM_FCOMP_CHANS_QSC];

   uint8 tx_cal_chan_size;

   uint8 pa_state_mask;

   uint16 ref_lin_temp_adc;

   seq_cal_tx_cal_res_per_pa_data_type tx_pa_state_cal_data[MAX_NUM_LIN_PER_PA_STATE_QSC];

} seq_cal_tx_lin_fcomp_res_type;

typedef struct
{
   uint8 nv_container;

   uint16 rfm_dev;

   uint16 antenna_path;

   uint32 signal_path;

   uint8 cal_status;

   uint8 xpt_cal_status[3]; // 0: Apt 1:ept 2:et

   uint64 cal_error_debug_mask;

   seq_cal_tx_lin_fcomp_res_type tx_fcomp_lin_res_data;

} seq_cal_tx_res_arr_type;

typedef struct
{
   /* nv writing time in u sec. Failure: 0 */
   uint32 nv_write_time;

   /* nv id. Failure: 0 */
   uint16 nv_id;

   /* reserved field */
   uint16 reserved;

   uint8 num_valid_results;

   seq_cal_tx_res_arr_type tx_res_arr[2]; //FIX HARDCODING: NUM TX CHAINS
}
seq_cal_tx_cal_res_type;


/*!
  @brief
  Structure containing XPT power measurement debug result type.
*/
typedef struct pwr_dbg_n
{
   uint8 num_meas;
   /*<  Number of debug power measurements returned */

   int16 pwr[64];
   /*<  Array of num_meas power measurements returned for debug  */
} xpt_dbg_stg1_pwr_t;

/*
   @brief
   Structure containing XPT
*/
typedef struct stg0_dbg_n
{
   uint8 num_meas;
   // Number of debug power measurements returned

   int16 rgi[TXLIN_NUM_SEGMENTS];
   // Array of optimal RGI returned for debug

   int16 pwr[TXLIN_NUM_SEGMENTS];
   // Array of measured power returned for debug

   int16 compdB[TXLIN_NUM_SEGMENTS];
   // Array of compression returned for debug
} xpt_dbg_stg0_t;

/*! Structure for M Line Outputs (no floats) */
typedef struct
{
   uint8 rgi;
   /*!< XPT RGI used during IQ Capture */

   uint32 bias_out;
   /*!< Bias calculated from M Line */

   uint32 pow_out_db10;
   /*!< Power calculated by old M Line, target pwr in New Mline */

   int16 iq_offset_db10;
   /*!< IQ offset calculated by New Mline. Unused by Old Mline.*/

   uint32 dbg_mask;
   /*!< Unused by Old Mline. Dbg mask for each Mline output   */

} ftm_common_xpt_mline_outputs_int_data;
/*----------------------------------------------------------------------------*/
/*! Struct to hold M Line results table*/

typedef struct
{
   uint8 num_mline_table_rows;
   ftm_common_xpt_mline_outputs_int_data mline_results[64 /* RFCOM_TXLIN_NUM_SEGMENTS */];
} ftm_calibration_mline_result_table_type;

/*----------------------------------------------------------------------------*/
/*! Struct to hold XPT Selection Sweep elements*/

typedef struct
{
   uint8 selec_swp_valid;
   uint8 selec_swp_rgi;
   int16 selec_swp_pwr;
   uint32 selec_swp_bias;
   uint16 selec_swp_iq_offset;
} ftm_calibration_mline_selec_swp_op;

/*----------------------------------------------------------------------------*/
/*! Struct to hold XPT Selection sweep table*/

typedef struct
{
   uint8 num_selec_swp_pwrs;
   ftm_calibration_mline_selec_swp_op mline_selec_swp[QMSL_XPT_MAX_NUM_MEAS_POWERS];
} ftm_calibration_mline_result_selec_sweep_type;


typedef struct
{
   int vout_vin_a;
   int vout_vin_b;
   int vout_vin_c;
   int vcc_vin_d;
   int vcc_vin_e;
   int vcc_vin_f;
} ftm_calibration_mline_result_slope_type;
/*----------------------------------------------------------------------------*/
/*! Struct to hold XPT Compression point list*/

typedef struct
{
   uint8 num_compression_points;
   uint8 compression_point_list[QMSL_XPT_MAX_NUM_MEAS_POWERS];
} ftm_calibration_mline_result_compression_point_type;
typedef struct
{
   ftm_calibration_mline_result_table_type mline_table_result;
   ftm_calibration_mline_result_selec_sweep_type selec_swp_calc_result;
   ftm_calibration_mline_result_selec_sweep_type selec_swp_meas_result;
   ftm_calibration_mline_result_compression_point_type compression_point_result;
   ftm_calibration_mline_result_slope_type mline_slope_result;
   uint32 mline_debug_mask;

} ftm_calibration_mline_result_xpt_type;

typedef struct dpd_bin_type_m
{
   uint8 * dpd_bin_fmt_buff; // Please allocate 1500 bytes

   uint16 num_bytes_in_binformat;

   uint16 allocatedBufferSize;

   uint8 dpd_index;

} ftm_calv3_dpd_bin_type;

typedef struct dpd_res_type_m
{
   uint8 num_dpds;

   ftm_calv3_dpd_bin_type dpd_bin[QMSL_XPT_MAX_NUM_MEAS_POWERS];

} xpt_dbg_dpd_res_t;

typedef struct
{
   /*! @brief TX handle */
   uint32 tx_handle;
   /*! @brief TX samples */
   uint8* tx_buff_ptr;
   /*! @brief FBRX handle */
   uint32 fbrx_handle;
   /*! @brief RX samples */
   uint8* rx_buff_ptr;
} xpt_dbg_capt_samp_buffer_s;

typedef struct capt_dbg_n
{
   uint8 num_capt;
   /*!< Number of captures done in first stage for this pa state. */

   uint8 capt_format;
   /*!< Capture format indicator. */

   xpt_dbg_capt_samp_buffer_s capt_buff[QMSL_XPT_MAX_NUM_MEAS_POWERS];
} xpt_dbg_capt_dbg_t;
typedef struct per_pa_dbg_m
{
   xpt_result_code   xpt_result;

   /* Bit 0 set => stg1_powers to be sent back to PC .*/
   /* Bit 1 set => stg1_capt_dbg to be sent back to PC .*/
   /* Bit 2 set => stg1_dpd_res to be sent back to PC .*/
   /* Bit 3 set => mline_res to be sent back to PC .*/
   /* Bit 4 set => stg2_capt_dbg to be sent back to PC .*/
   /* Bit 5 set => et_delay to be sent back to PC .*/
   /* Bit 6 set => stg0_result to be sent back to PC .*/
   uint32 debug_return_mask;

   xpt_dbg_stg1_pwr_t stg1_powers;
   /*!< stage 1 powers*/

   xpt_dbg_capt_dbg_t* stg1_capt_dbg;
   /*!< Ptr to teh capture buffer. Only allocated if Debug data is requested in calibration params. */

   xpt_dbg_dpd_res_t stg1_dpd_res;

   ftm_calibration_mline_result_xpt_type mline_res;
   /*!< Mline Results per pa state  */

   xpt_dbg_capt_dbg_t* stg2_capt_dbg;

   /* et delay */
   int32 et_delay;

   /*!< Stage 0 RGI and PWR*/
   xpt_dbg_stg0_t stg0_result;
} xpt_dbg_type;
typedef struct
{
   seq_cal_tx_cal_res_type tx_cal_data;

   xpt_dbg_type xpt_debug_data[3 /* RFCOMMON_MDSP_XPT_MODE_MAX */];

   cal_sweep_xpt_delay_paths_results tx_delay_cal_data;
} seq_cal_unconnected_res_type;

typedef struct
{
   uint8   number_of_valid_channels;
   uint8   number_of_valid_splits;
   uint32  channel_list[16]; // FIX HARDCODING:RFNV_NUMBER_OF_PCLS

   struct
   {
      uint16 concurrent_dev_mask;
      int16  freq_comp_offset[8][16]; // FIX HARDCODING:RFNV_MAX_LNA_GAIN_STATES = 8, RFNV_NUMBER_OF_PCLS = 16
   } split_freq_comp_offset[3]; // HARDCODING: RFNV_MAX_NUM_SPLIT_LNA_CASES

} seq_cal_rx_cal_split_lna_data_v3;

typedef struct
{
   uint8   number_of_valid_channels;
   uint16  cal_type;
   uint16  concurrent_dev_mask;
   uint32  channel_list[16]; // FIX HARDCODING:RFNV_NUMBER_OF_PCLS
   int16   freq_comp_offset[8][16]; // FIX HARDCODING:RFNV_MAX_LNA_GAIN_STATES = 8, RFNV_NUMBER_OF_PCLS = 16
} seq_cal_rx_cal_stand_alone_lna_data_v3;

typedef struct
{
   uint8 cal_success;
   uint8 tech;
   uint8 subband;
   uint16 band;
   //path info
   uint8 nv_container_id;
   uint16 rfm_device_id;
   uint32 signal_path;
   uint16 antenna_port;

   //LNA gain state mask
   uint16 lna_state_mask;

   uint64 error_debug_mask;
   uint32 data_type;

   // Single RX
   seq_cal_rx_cal_stand_alone_lna_data_v3 standalone_lna_result;

   //CA RX
   seq_cal_rx_cal_split_lna_data_v3 split_lna_result;

} seq_cal_rx_cal_path_res_type;

#define RFNV_MAX_NUM_RX_PATHS 64
typedef struct
{
   /* nv writing time in u sec. Failure: 0 */
   uint32 nv_write_time;

   /* nv id. Failure: 0 */
   uint16 nv_id;

   /*Number of Rx paths for which result data is populated and tracked in the 'rx_data_arr' below.*/
   uint8 num_valid_rx_paths;

   /*Array to track Rx result data for all paths. Each element points to a dynamically allocated data section.*/
   seq_cal_rx_cal_path_res_type rx_data_arr[RFNV_MAX_NUM_RX_PATHS];
} seq_cal_rx_cal_res_type;

typedef struct
{
   /* nv writing time in u sec. Failure: 0 */
   uint32 nv_write_time;

   /* nv id. Failure: 0 */
   uint16 nv_id;

   /* Number of RFM Paths */
   uint8 numberofRFMPaths;

   /* Array of pointers to dynamically allocated Storage */
   ftm_fbrxgain_path_result pathResults[8]; //FIX HARDCODING:  MAX_NUM_FBRX_RFM_PATHS
} seq_cal_fbrxgain_cal_res_type;


typedef struct
{
   uint8 bwType;

   uint8 numLOFreqOffsets;

   int32 loFreqOffset[MAX_NUM_LO_FREQ_OFFSETS_RX_RSB];

   int16 preCalRSBValues[MAX_NUM_LO_FREQ_OFFSETS_RX_RSB];

   int32 realCoeff[MAX_NUM_LO_FREQ_OFFSETS_RX_RSB];

   int32 imagCoeff[MAX_NUM_LO_FREQ_OFFSETS_RX_RSB];

} ftm_fd_rx_rsb_bw_data;

typedef struct
{
   uint32 channel;

   uint8 numBWs;

   ftm_fd_rx_rsb_bw_data bwData[MAX_NUM_RX_RSB_BWS];

} ftm_rx_rsb_cal_debug_data;

typedef struct
{
   rfm_path_type rfmPath;
   uint64 error_debug_mask;
   uint8 cal_success;
   uint8 nvContID;
   uint8 tech;
   uint8 subband;
   uint16 band;
   ftm_rx_rsb_cal_debug_data rsbCalDebugData;

} ftm_fd_rx_rsb_path_data;


typedef struct
{
   uint8 numPaths;

   ftm_fd_rx_rsb_path_data pathData[MAX_NUM_RX_RSB_RFM_PATHS];

} seq_cal_ftm_fd_rx_rsb_cal_data;
typedef struct
{
   seq_cal_rx_cal_res_type rx_cal_data;
   seq_cal_fbrxgain_cal_res_type fbrx_cal_data;
   seq_cal_ftm_fd_rx_rsb_cal_data fdRxRSBdata;
} seq_cal_connected_res_type;

typedef enum
{
   SEQ_CAL_RESULT_TYPE_NONE = 0,
   SEQ_CAL_RESULT_TYPE_TX  = 1, // Used as bitmask
   SEQ_CAL_RESULT_TYPE_RXGAIN  = 2, // Used as bitmask
   SEQ_CAL_RESULT_TYPE_FBRXGAIN = 4, // Used as bitmask
   SEQ_CAL_RESULT_TYPE_XPT_DBG_INFO = 8, // Used as bitmask
   SEQ_CAL_RESULT_TYPE_FD_RXRSB = 16, // Used as bitmask
   SEQ_CAL_RESULT_TYPE_XPT_DELAY = 32, // Used as bitmask
} seq_cal_res_type;

typedef struct
{
   /* Result Mask 0x1:SEQ_CAL_RESULT_TYPE_TX, 0x2:SEQ_CAL_RESULT_TYPE_RXGAIN, 0x4:SEQ_CAL_RESULT_TYPE_FBRXGAIN */
   uint8 result_mask;

   /* NV Write mask: 0x1:SEQ_CAL_RESULT_TYPE_TX, 0x2:SEQ_CAL_RESULT_TYPE_RXGAIN, 0x4:SEQ_CAL_RESULT_TYPE_FBRXGAIN */
   uint8 nv_write_mask;

   seq_cal_unconnected_res_type unconn_res_data;

   seq_cal_connected_res_type conn_res_data;

} cal_sweep_data_seq_cal_res_type;

typedef struct
{
   // Load Meas DPD Results Type
   cal_sweep_data_dpd_proc_action_res_type measDpdRes[10];

   // Load Calc DPD Results Type
   cal_sweep_data_dpd_proc_action_res_type calcDpdRes[10];

   // Load Unity Meas EPDT Results Type
   cal_sweep_data_load_dpd_epdt_res_type measLoadEPDTRes[10];

   // Load Unity Calc EPDT Results Type
   cal_sweep_data_load_dpd_epdt_res_type calcLoadEPDTRes[10];

   // Delay Val Proc Results
   cal_sweep_data_delay_val_proc_res_type delayRes;

   // Pin Cal Proc Results
   cal_sweep_data_pin_cal_proc_res_type pinCalRes;

   // Extended Pin Cal Proc Results
   cal_sweep_data_ext_pin_cal_proc_res_type pinCalResExt;

   // EPT M Line results action mask
   word EptMlineAction;

   // ET M Line results action mask
   word EtMlineAction;

   // Mline Results type EPT
   cal_sweep_xpt_mline_res_type EptMlineRes;

   // Mline results type ET
   cal_sweep_xpt_mline_res_type EtMlineRes;

   // XPT Capture Results Type
   cal_sweep_data_xpt_cap_res_type xptCapRes;

   // Push FBRx cal Result Type
   cal_sweep_data_push_fbrx_res_type pushfbrxRes;

   // Seq Cal Results Type
   cal_sweep_data_seq_cal_res_type *seqCalRes;

   // Delta Gain Pin Pout Results Type
   cal_sweep_delta_gain_pin_pout_load_res_type pinpoutRes;

} cal_sweep_res_data;

typedef struct
{
   uint64 seq_bld_proc_time;
   uint32 seq_bld_result_code;
} cal_sweep_res_seq_bld;

typedef struct
{
   uint64 seq_exe_proc_time;
   uint32 seq_exe_result_code;
} cal_sweep_res_seq_exe;

typedef struct
{
   //Master Path
   byte masterPath;

   //Slave Path
   byte slavePath;
} cal_sweep_path;

typedef struct
{
   // Version
   byte version;

   // Debug Mode
   byte debugMode;

   // Flag
   word flag;

   // Device type
   cal_sweep_params_device device;

   //PCell and SCell device type
   cal_sweep_params_device_mapping device_mapping;

   /* The band that cal has to be performed in.
   * CDMA = 0
   * WCDMA = 1
   * GSM = 2
   * LTE = 10
   * TDSCDMA = 11
   */
   byte tech;

   /* The band that cal has to be performed in.
   *
   */
   word band;

   // Channel type
   cal_sweep_params_chan chan;

   // Upper bound channel
   cal_sweep_params_chan ubchan;

   // Waveform type
   cal_sweep_params_wfm wfm;

   // Cal Path
   cal_sweep_path path;

   //Radio Setup Actions
   cal_sweep_params_radio_setup_action radio_setup_action;
} cal_sweep_params_radio_setup;

typedef struct
{
   // LNA State
   byte lna_state;

   // Power Mode
   byte power_mode;

   // Expected RxAGC
   word exp_rxagc;
} rx_meas_payload;

typedef struct
{
   // Rx Measurement Action
   word rx_meas_action;

   // Payloads
   rx_meas_payload payloads[RX_MEAS_MAX_NUMPAYLOADS];
} rx_meas_actions;

typedef struct
{
   // Version
   byte version;

   // Debug Mode
   byte debug_mode;

   // Flag
   word flag;

   // Device for Rx Measurement
   byte dev;

   // Rx Meas Actions
   rx_meas_actions actions[ESC_MAX_DEVICES];
} cal_sweep_params_rx_meas;

typedef struct
{
   // Version
   byte version;

   // Debug Mode
   byte debug_mode;

   // Flag
   word flag;

   // Primary Device for int cal
   byte pdev;

   // Feedback Device for int cal
   byte fbDev;

   // Action to perform; defined in ESC_FEEDBACK_SETUP_ACTION_TYPE
   word fbAction;

   // Feedback path Enable/Disable
   byte fbEnable;

   // Feed back Gain state to use
   byte fbGainState;

   // RXLM Enable/Disable for Xpt
   byte rxlmXptEnable;

   // RXLM Enable/Disable for FB AGC
   byte rxlmFbAgcEnable;

   // Current PA state (used for saving/looking up offsets)
   byte paState;

   // Reference RGI (used for saving/looking up offsets)
   byte refRGI;

   byte fbRxCalMode;

   byte stgEnable;

   byte stgState;

   word freq_offset_khz;

   byte isScell;

} cal_sweep_params_tx_int_cal;

typedef enum
{
   ENH_INTERNAL_DEVICE_CAL_FBDROOP = 0,
   ENH_INTERNAL_DEVICE_CAL_GROUP_DELAY = 1,
   ENH_INTERNAL_DEVICE_CAL_IP2 = 2,
   ENH_INTERNAL_DEVICE_CAL_DC = 3,
   ENH_INTERNAL_DEVICE_CAL_RSB=4,
   ENH_INTERNAL_DEVICE_CAL_RETURN_RSB_RESULTS = 5,
   MAX_ENH_INTERNAL_DEVICE_CAL_MAX = 6
} ENH_INTERNAL_DEVICE_CAL_BIT_TYPE;

typedef enum
{
   FTM_ENH_INTERNAL_DEVICE_CAL_RXRSB_RES_PRX1 = 0,
   FTM_ENH_INTERNAL_DEVICE_CAL_RXRSB_RES_DRX1 = 1,
   FTM_ENH_INTERNAL_DEVICE_CAL_RXRSB_RES_PRX2 = 2,
   FTM_ENH_INTERNAL_DEVICE_CAL_RXRSB_RES_DRX2 = 3,
   FTM_ENH_INTERNAL_DEVICE_CAL_RSB_RES_FBRX = 4,
   FTM_ENH_INTERNAL_DEVICE_CAL_RXRSB_RES_PRX3 = 4,
   FTM_ENH_INTERNAL_DEVICE_CAL_RXRSB_RES_DRX3 = 5,
   FTM_ENH_INTERNAL_DEVICE_CAL_RSB_RES_FBRX_ULCA = 6,
   FTM_ENH_INTERNAL_DEVICE_CAL_RSB_RES_MAX = 8
} ftm_enh_internal_device_cal_rsb_rxpath;

typedef enum
{
   FTM_ENH_INTERNAL_DEVICE_CAL_RSB_ALG_CALLBOX = 0,
   FTM_ENH_INTERNAL_DEVICE_CAL_RSB_ALG_STG = 1,
   FTM_ENH_INTERNAL_DEVICE_CAL_RSB_ALG_TX = 2,
   FTM_ENH_INTERNAL_DEVICE_CAL_RSB_ALG_MAX
} ftm_enh_internal_device_cal_rsb_alg;

typedef enum
{
   FTM_ENH_INTERNAL_DEVICE_CAL_RX_RSB = 0,
   FTM_ENH_INTERNAL_DEVICE_CAL_FB_RSB = 1,
   FTM_ENH_INTERNAL_DEVICE_CAL_RSBTYPE_MAX
} ftm_enh_internal_device_cal_rsb_type;
//Common Enh Internal Device Cal RequestPacket structure

typedef struct
{
   unsigned char cmd;
   unsigned char sub_sys;
   unsigned short mode;
   unsigned short ftm_cmd_id;
   unsigned short req_len;
   unsigned short resp_len;
   unsigned char res_rev;
   unsigned char dbg_mode_en;
   unsigned short flag;
   unsigned long  tot_instr_len;
   unsigned long  int_cal_type_mask;
   unsigned char tech;
   unsigned char bw;
   unsigned short band;
   unsigned long  ref_chan;
   unsigned short dev_mask;
} common_header_request;

typedef struct
{
   unsigned char fb_droop_method;
   unsigned char tx_device;
   unsigned char fbrx_gain_state;
   unsigned char num_Captures;
   long stg_freq_offset_list_khz[NUM_MAX_STG_FREQ_OFFS_FBRX_DROOP];
   unsigned short num_iq_samples;
   unsigned char do_processing;
} fb_droop_instruction;

typedef struct
{
   unsigned char num_Gain_States;
   unsigned char fbrx_gain_state[NUM_FBRX_GAIN_STATES];
   unsigned short num_iq_samples;
} fb_dc_instruction;

typedef struct
{
   unsigned char rsb_type;
   unsigned char rsb_cal_alg; // 0 for using callbox, 1 for using stg, 2 for using Tx
   int offset_khz; // offset from the ref chan, for using internal stg only
   unsigned char num_gain_states;
   unsigned char gain_states[NUM_RSB_GAIN_STATES];
   unsigned char iq_capture_type;
   unsigned long iq_sample_size;
   unsigned char carrier_id; //Carrier_id, 0 for PCell,  1 for SCell0,
   unsigned short pcell_band_for_scell; // pcell band_for scell, valid only if scell rsb cal is requested
   unsigned long pcell_ref_chan_for_scell; //pcell reference channel, valid only if scell rsb cal is requested
} rx_fbrx_rsb_instruction;

typedef struct
{
   common_header_request common_header;
   fb_droop_instruction droop_instr;
   fb_dc_instruction dc_instr;
   rx_fbrx_rsb_instruction rsb_instr;
} common_enh_internal_device_cal;

typedef struct
{
   unsigned long fbrx_mode_nv;
   unsigned char fbrx_gain_state[NUM_FBRX_GAIN_STATES];
   long dcval[NUM_FBRX_GAIN_STATES][2];
} fb_dc_resp;

typedef struct
{
   unsigned long fbrx_tech_bw_type;
   unsigned char filter_group_delay;
   unsigned char filter_taps_num;
   long filter_coeffs[MAX_DROOP_FILTER_LEN];
} ftm_fbrx_droop_result_data_type;

//RSB cal validation payload structure
typedef struct
{
   uint8 band;  /*! Band for which RSB cal data is available */
   uint8 rfm_device;  /*! devcie for which RSB cal data is available */
   uint8 gain_state; /*! gain state for which RSB cal data is available */
} rsb_calibrated_data_type;

typedef struct
{
   uint16 calibrated_elements;
   rsb_calibrated_data_type rsb_cal_ver[1024];
} rsb_cal_verfication_data_type;

typedef struct
{
   uint8 nv_active;
   int16 sin_theta_final;
   int16 cos_theta_final;
   int16 gain_inv_final;
   int16 sin_theta_after_cal;
   int16 cos_theta_after_cal;
   int16 gain_inv_after_cal;
   int8  rsb_before_cal;
   int8  rsb_after_cal;
} ftm_rsb_result_data_type;

typedef struct
{
   uint8 device_mask;
   uint8 num_gain_states;
   uint8 gain_states[NUM_RSB_GAIN_STATES];
   ftm_rsb_result_data_type rsb_res[FTM_ENH_INTERNAL_DEVICE_CAL_RSB_RES_MAX][NUM_RSB_GAIN_STATES];
} ftm_enh_internal_device_cal_rsb_result_type;

typedef struct
{
   int32 rsb_cal_error_code;
   uint16 rsb_cal_flag;
   ftm_enh_internal_device_cal_rsb_result_type rsb_resp;
   rsb_cal_verfication_data_type rsb_cal_ver_data;
} rx_fbrx_rsb_result_type;

typedef struct
{
   int32 rsb_cal_error_code;
   uint16 rsb_cal_flag;
   rsb_cal_verfication_data_type rsb_cal_ver_data;
} rx_fbrx_rsb_result_verify_type;

typedef struct
{
   unsigned char fbrx_gain_state;
   unsigned char num_filters;
   ftm_fbrx_droop_result_data_type fbrx_droop_res[NUM_MAX_DROOP_FILTER_PER_SWEEP];
   unsigned long stg_raw_tone_pwrs[NUM_MAX_STG_FREQ_OFFS_FBRX_DROOP];
} ftm_enh_internal_device_cal_fb_droop_result_type;

typedef union
{
   ftm_enh_internal_device_cal_fb_droop_result_type droop_rsp_payload;
   ftm_enh_internal_device_cal_rsb_result_type rsb_rsp_payload;
   fb_dc_resp dc_resp;
} enh_internal_device_cal_individual_payload;

typedef struct
{
   unsigned char cmd;                                               //<' Command ID (75)
   unsigned char subsys;                                        //<' Subsystem (11)
   unsigned short mode;                                          //<' Mode ID (20)
   unsigned short ftm_cmd;                                         //<' FTM command id
   unsigned short req_len;
   unsigned short resp_len;
   unsigned char  tech; // tech
   unsigned short band;      // <band
   unsigned char bw;// fbrx_bandwidth
   unsigned long cal_type_error_mask;// Error mask indicating which internal cal type get erro
   long cal_status_error_code;
   unsigned short cal_res_len;
   unsigned long ic_bit;
   unsigned short fbrx_res_len;
} common_enh_internal_device_resp_Header;

typedef struct
{
   common_enh_internal_device_resp_Header rsp_common_header;
   enh_internal_device_cal_individual_payload rsp_individual;
   rsb_cal_verfication_data_type rsb_cal_ver_data; // this is for rsb_cal_ver_extra data for flag=2 type
} common_enh_internal_device_resp;

typedef struct
{
   common_enh_internal_device_resp_Header rsp_common_header;
   rsb_cal_verfication_data_type rsb_cal_ver_data; // this is for rsb_cal_ver_extra data
} enh_internal_device_resp_rsb_verification; //verification only type

typedef struct
{
   bool do_Enhanced_Internal_Device_cal;
   unsigned char version;
   unsigned char res_rev;
   unsigned char dbg_mode_en;
   unsigned short flag;
   unsigned char tech;
   unsigned short band;
   unsigned long ref_chan;
   unsigned long  int_cal_type_mask;
   unsigned char num_sig_bandwidth;
   unsigned char bw[MAX_NUM_FBRX_BANDWIDTH];
   unsigned short dev_mask;
   fb_dc_instruction dc_instr;
   rx_fbrx_rsb_instruction rsb_instr;
   unsigned short numReqRsbCalElement;
   bool use_txrx_split;
   unsigned char unique_dev_logical_dev_map[ESC_MAX_DEVICES]; //unique_device_map[0]
} cal_sweep_enh_int_device_cal;

typedef struct
{
   fb_dc_resp dc_resp;
   unsigned char num_gain_states;
} cal_sweep_res_fb_dc;

typedef union
{
   cal_sweep_res_fb_dc fbdc_res[MAX_NUM_FBRX_NV_MODES];
} cal_sweep_res_individual_int_device_cal;

typedef struct
{
   unsigned char cmd;                                               //<' Command ID (75)
   unsigned char subsys;                                        //<' Subsystem (11)
   unsigned short mode;                                          //<' Mode ID (20)
   unsigned short ftm_cmd;                                         //<' FTM command id
   unsigned short req_len;
   unsigned short resp_len;
   unsigned char  tech; // tech
   unsigned short band;      // <band
   unsigned char bw[MAX_NUM_FBRX_BANDWIDTH];// fbrx_bandwidth
   unsigned long cal_type_error_mask;// Error mask indicating which internal cal type get erro
   long cal_status_error_code;
   unsigned short cal_res_len;
   unsigned long ic_bit;
   unsigned short fbrx_res_len;
   cal_sweep_res_individual_int_device_cal  individual_res_int_device_cal;
} cal_sweep_res_enh_int_device_cal;
/*Structure to save the pa switch points */
typedef struct
{
   unsigned char tech;
   unsigned char action;
   unsigned short band;
   unsigned char tx_device;
} FTM_GET_STATIC_INFO_REQUEST;
typedef struct
{
   unsigned short num_act_pa_state;
   signed short pa_rise[8];
   signed short pa_fall[8];
} FTM_GET_STATIC_PA_SWPT_INFO;

typedef struct
{
   unsigned char status;
   FTM_GET_STATIC_INFO_REQUEST req_info;
   union
   {
      FTM_GET_STATIC_PA_SWPT_INFO pa_info;
   };
} FTM_GET_STATIC_INFO_RESPONSE;
typedef enum
{
   PA_SWPT_ACTION
} Static_action;
/*Structure to write the PA tunable Reg  */
typedef struct
{
   unsigned short tech;
   unsigned char offset;
} set_tunable_cap_pkt;

//Add more extensions in union structure to accommodate future extensions
/**
Structure that contains the set of cal sweep record parameters.

To be used with the function QLIB_FTM_CFG_AND_EXEC_CAL_SWEEP()
*/
// INPUTS
/**
Inputs, must be filled in before the QLIB_FTM_CFG_AND_EXEC_CAL_SWEEP() function is called.
Each parameter listed is a part of every segment of the cal sweep.

*/
typedef struct
{
   // Version
   unsigned short version;

   //Instance->for split bands
   unsigned char instance;

   // Is Config Segment
   bool isCfgSeg;

   // Is NOP Segment
   bool isNopSeg;

   // Is BW Change Segment
   bool isBWChangeSeg;

   // Opcode type
   cal_sweep_opcode opcode;

   // Radio Config type
   cal_sweep_params_radio_setup radio_cfg;

   // Tx Params
   cal_sweep_params_tx txParams;

   // HDET Params
   cal_sweep_params_tx_meas txMeasParams;

   // Tx Results
   cal_sweep_res_tx txRes;

   // Rx Params
   cal_sweep_params_rx rxParams;

   // Rx Results
   cal_sweep_res_rx rxRes;

   // Int Cal Params
   cal_sweep_params_tx_int_cal txIntCalParams;

   // Tx Int Cal Results
   cal_sweep_res_tx_int_cal txIntCalRes;

   // Data Type
   cal_sweep_data data;

   // Data Results
   cal_sweep_res_data dataRes;

   // XPT Type
   cal_sweep_xpt xpt;

   // Sync Type
   cal_sweep_sync sync;

   // Rx Meas Type
   cal_sweep_params_rx_meas rxMeas;

   //Enhanced Internal Device Cal Type
   cal_sweep_enh_int_device_cal EnhIntDevCal;

   cal_sweep_res_fb_dc fbresDc;

   rx_fbrx_rsb_result_type rx_fbrxRsbRes;

   cal_sweep_seqbuild seqBuild;

   cal_sweep_res_seq_bld seqBuildRes;

   cal_sweep_seqexec seqExec;

   cal_sweep_res_seq_exe seqExecuteRes;

   cal_sweep_polling polling;

   // Tx Purpose (for NV)
   word txPurpose;

   //To indicate if the current segment is a measurement segment or not
   bool measSeg;

   //To indicate if the current segment has results expected or not
   bool resExpected;

   // Sweep Type
   unsigned short swpType;

   // Sub Sweep Type
   unsigned short subSwpType;

   // To track to which frame the record belongs in frame based sweep
   int frame_index;

   // Ordinal ID of record in its frame
   int ue_record_index;
} cal_sweep_record;

typedef struct
{
   // Result Type
   byte resType;

   // Version
   byte version;

   // Device Mask
   byte devMask;
} cal_sweep_resp_header;

typedef struct
{
   // Result Type
   byte resType;

   // Result Action Type
   byte resActionType;

   // Version
   byte version;
} cal_sweep_data_resp_header;

typedef struct
{
   // Result Type
   byte resType;

   // Version
   byte version;

   // Error Code
   qword errCode;

   // XPT Action
   dword xptAction;
} cal_sweep_xpt_resp_header;

/**
xPT type.  This value is used to identify the specific Power Tracking scheme
*/
typedef enum
{
   XPT_TYPE_NOPT     = -1,
   XPT_TYPE_APT      = 0,
   XPT_TYPE_EPT      = 1,   //!<'  EPT Enhanced Power Tracking
   XPT_TYPE_ET       = 2,   //!<'  ET Envelope Tracking

   XPT_TYPE_INVALID
} FTM_xptType_Enum;

/**
xPT type.  This value is used to identify the specific Power Tracking scheme
*/
typedef enum
{
   LOAD_DPD_XPT_TYPE_EPT      = 0,  //!<'  EPT Enhanced Power Tracking
   LOAD_DPD_XPT_TYPE_ET       = 1,  //!<'  ET Envelope Tracking

   LOAD_DPD_XPT_TYPE_INVALID
} FTM_LoadDpdXptType_Enum;

/**
RFM Device type for primary Tx path
*/
typedef enum
{
   PRI_PATH_DEV_0             = 0,
   PRI_PATH_DEV_1             = 1,
   PRI_PATH_DEV_2             = 2,
   PRI_PATH_DEV_3             = 3,
   PRI_PATH_DEV_4             = 4,
   PRI_PATH_DEV_5             = 5,
   PRI_PATH_DEV_6             = 6,
   PRI_PATH_DEV_7             = 7,
   PRI_PATH_DEV_8             = 8,
   PRI_PATH_DEV_9             = 9,

   PRI_PATH_INVALID
} FTM_PriPathDevType_Enum;

/**
RFM device type for the feedback path
*/
typedef enum
{
   FB_PATH_DEV_0             = 0,
   FB_PATH_DEV_1             = 1,
   FB_PATH_DEV_2             = 2,
   FB_PATH_DEV_3             = 3,
   FB_PATH_DEV_4             = 4,
   FB_PATH_DEV_5             = 5,
   FB_PATH_DEV_6             = 6,
   FB_PATH_DEV_7             = 7,
   FB_PATH_DEV_8             = 8,
   FB_PATH_DEV_9             = 9,

   FB_PATH_INVALID
} FTM_FBPathDevType_Enum;

/**
Specifies the type of load DPD action which must be performed. Not yet finalized
*/
typedef enum
{
   DPD_ACTION_TYPE_ISC        = 0,
   DPD_ACTION_TYPE_INIT       = 1,
   DPD_ACTION_TYPE_SAVE       = 2,
   DPD_ACTION_TYPE_COMMIT     = 3,

   DPD_ACTION_TYPE_INVALID
} FTM_LoadDPDActionType_enum;

/**
Specifies the type of Tx Override action which must be performed.
*/
typedef enum
{
   OVERRIDE_ACTION_TYPE_SKIP            = 0,  /* skip override for specified tx override param */
   OVERRIDE_ACTION_TYPE_VAL_OVERRIDE    = 1,  /* set specified tx override param to value provided */
   OVERRIDE_ACTION_TYPE_DEFAULT         = 2,  /* set specified tx override param to sw default*/
   OVERRIDE_ACTION_TYPE_NV              = 3,  /* set specified tx override param to value in NV */
   OVERRIDE_ACTION_TYPE_INVALID         = 0xFFFF
} FTM_OverrideActionType_enum;

typedef enum QMSL_RFNV_DATA_TYPE_IDS
{
   /* 0-99 is reserved for legacy data types, will be added later */
   QMSL_RFNV_DATA_TYPE_ID_CAL_CHANS        = 100,
   QMSL_RFNV_DATA_TYPE_ID_FREQ_OFFSETS     = 101,
   QMSL_RFNV_DATA_TYPE_ID_LIN_TABLE_V3     = 102,
   //QMSL_RFNV_DATA_TYPE_ID_EPT_DPD_V1     = 103, /* <-- Not used. Here only to acknowledge Nikel's EPT */
   QMSL_RFNV_DATA_TYPE_ID_EPT_DPD_V2       = 104,
   QMSL_RFNV_DATA_TYPE_ID_ET_DPD           = 105,
   QMSL_RFNV_DATA_TYPE_ID_RGI_LIST         = 106,   /* QMSL_RFNV_data_rgi_list_type */
   QMSL_RFNV_DATA_TYPE_ID_PMEAS_LIST       = 107,   /* QMSL_RFNV_data_pmeas_list_type */
   QMSL_RFNV_DATA_TYPE_ID_AMAM_LIST        = 108,   /* QMSL_RFNV_data_amam_ampm_list_type */
   QMSL_RFNV_DATA_TYPE_ID_AMPM_LIST        = 109,   /* QMSL_RFNV_data_pwr_err_list_type */
   QMSL_RFNV_DATA_TYPE_ID_TX_PWR_ERR_LIST  = 110,   /* QMSL_RFNV_data_pwr_err_list_type */
   QMSL_RFNV_DATA_TYPE_ID_REF_LIN_TEMP_ADC = 111,    /* */
   QMSL_RFNV_DATA_TYPE_ID_FB_GAIN_TYPE     = 112,    /* QMSL_RFNV_data_pwr_err_list_type */
   QMSL_RFNV_DATA_TYPE_ID_AMPM_SCALING_FACTOR = 113,
   QMSL_RFNV_DATA_TYPE_RX_CAL_OFFSET_V1    = 115,
   QMSL_RFNV_DATA_TYPE_RX_OFFSET_VS_FREQ_V1 = 116,
   QMSL_RFNV_DATA_TYPE_ID_FB_GAIN_TYPE_V2  = 117,
   QMSL_RFNV_DATA_TYPE_RX_CAL_OFFSET_V2         =118,
   QMSL_RFNV_DATA_TYPE_ID_LIN_TABLE_V4_TXRSBLOFT  = 119,
   QMSL_RFNV_DATA_TYPE_ID_LTE_BW_FBRX_DROOP_CAL  = 123,
   QMSL_RFNV_DATA_TYPE_RxRSB_CAL = 124,
   QMSL_RFNV_DATA_TYPE_FBRX_THERM_ADC_V1   = 127,
   QMSL_RFNV_GSM_TYPE_RX_CAL_OFFSET_V1       = 188,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_CHAN       = 189,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_AMAM_RGI   = 190,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_RGI_LIST   = 191,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_PMEAS_LIST = 192,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_AMAM_LIST  = 193,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_PWR_ERR    = 194,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_AMPM_LIST  = 195,
   QMSL_RFNV_DATA_TYPE_ID_DELTA_GAIN_PIN_POUT= 204,
   QMSL_RFNV_DATA_TYPE_VARIANT_SUB_HEADER_V2    = 206,
   QMSL_RFNV_DATA_TYPE_GSM_RX_CAL_OFFSET_V2     = 233,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_CHAN_V2       = 234,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_AMAM_RGI_V2   = 235,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_RGI_V2        = 236,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_PMEAS_LIST_V2 = 237,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_AMAM_LIST_V2  = 238,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_PWR_ERR_V2    = 239,
   QMSL_RFNV_DATA_TYPE_GSM_TX_CAL_AMPM_LIST_V2  = 240,
} QMSL_RFNV_DATA_TYPE_IDS_ENUM;

/*! Structure for XPT Cal Input Data */
typedef struct
{
   /*!< XPT RGI used during IQ Capture */
   byte rgi;

   /*!< XPT Bias used during IQ Capture */
   dword bias;
} QMSL_xpt_cal_input_data;

/*! Structure for XPT Cal Output Data */
typedef struct
{
   /*!< Power measured during IQ Capture */
   dword pout_meas_dbm100;
} QMSL_xpt_cal_output_data;

/*! Structure for XPT cal AMAM results */
typedef struct
{
   /*!< Vins to represent the AMAM Data */
   word vin_x100[QMSL_XPT_CAL_MAX_AMAM_SIZE];

   /*!< Vouts to represent the AMAM Data */
   word vout_x100[QMSL_XPT_CAL_MAX_AMAM_SIZE];
} QMSL_xpt_cal_amam_data;

/*! Structure for XPT cal Data */
typedef struct
{
   QMSL_xpt_cal_input_data xpt_cal_inputs;
   /*!< XPT Cal Inputs */

   QMSL_xpt_cal_output_data xpt_cal_outputs;
   /*!< XPT Cal Outputs */
} QMSL_xpt_cal_data;

/*! Structure for RGI Deltas Sweep Data */
typedef struct
{
   /*!< RGI used for RGI Deltas Sweep */
   byte rgi;

   /*!< Power measured for the above RGI during the RGI Deltas Sweep */
   dword pmeas_dbm100;
} QMSL_ftm_common_rgi_delta_data;

/*! Structure for M Line Outputs (no floats) */
typedef struct
{
   /*!< XPT RGI used during IQ Capture */
   byte rgi;

   /*!< Bias calculated from M Line */
   dword bias_out;

   /*!< Power calculated from M Line */
   dword pow_out_dbm10;
} QMSL_xpt_mline_outputs_data;

/*! Structure for xPT DPD File */
typedef struct
{
   byte capt_status;
   /*!< Capture Status from FW (0 = success) */

   byte proc_status;
   /*!< Processing Status from FW (0 = success) */

   word num_amam_samples;
   /*!< Number of AMAM samples (=256) */

   word num_ampm_samples;
   /*!< Number of AMPM samples (=256) */

   word amam[QMSL_XPT_CAL_MAX_AMAM_SIZE];
   /*!< AMAM results */

   short ampm[QMSL_XPT_CAL_MAX_AMAM_SIZE];
   /*!< AMPM results*/

   long rx_dc_i;
   /*!< Rx DC I */

   long rx_dc_q;
   /*!< Rx DC Q*/

   dword rx_pre_eq_rms_mag;
   /*!< Rx pre-EQ RMS Mag */

   long eq_fir_coefficients[QMSL_XPT_CAL_EQ_FIR_COEF_SIZE];
   /*!< EQ FIR coefficients */

   char eq_fir_shift;
   /*!< EQ FIR shift */

   word tx_rms_mag;
   /*!< Tx RMS Mag */

   word rx_post_eq_rms_mag;
   /*!< Rx Post_EQ RMS Mag */

   short rx_peak_offset;
   /*!< Rx Peak Offset */

   short post_eq_snr;
   /*!< Post-EQ SNR*/

   short post_eq_par;
   /*!< Post-EQ PAR*/

   short post_eq_par_max;
   /*!< Post-EQ PAR for max peak*/

   word num_am_predist;
   /*!< Num. entries in AM Predistortion table=16 */

   word num_pm_predist;
   /*!< Num. entries in PM Predistortion table=16 */

   word am_predist_table[QMSL_XPT_CAL_PREDIST_SIZE];
   /*!< AM predistortion table */

   short pm_predist_table[QMSL_XPT_CAL_PREDIST_SIZE];
   /*!< PM predistortion table */

   char am_dist_shift;
   /*!< AM distortion shift */

   word am_expanded_predist_table[QMSL_XPT_CAL_EXPANDED_PREDIST_SIZE];
   /*!< Expanded AM predistortion table */

   short pm_expanded_predist_table[QMSL_XPT_CAL_EXPANDED_PREDIST_SIZE];
   /*!< Expanded PM predistortion table */

   short rx_gain_high;
   /*!< Rx Gain High*/

   short rx_gain_low;
   /*!< Rx Gain Low*/

   short rx_gain_max;
   /*!< Rx Gain Max*/

} QMSL_xpt_dpd_file_data;

typedef enum
{
   QMSL_MLINE_CURVE_FIT_LINEAR = 0,
   /*!< Linear Curve Fit */

   QMSL_MLINE_CURVE_FIT_QUADRATIC = 1,
   /*!< Quadratic Curve Fit */

   QMSL_MLINE_CURVE_FIT_THIRD_ORDER = 2,
   /*!< Third Order Curve Fit */

   QMSL_MLINE_CURVE_FIT_MAX_NUM
   /*!< MLine Curve Fit max num */
} QMSL_ftm_mline_curve_fit_type;

typedef struct
{
   unsigned long channel;
   unsigned long upperBoundCh;
   bool bMeasured;             //! specifies whether was measured or calculated
   FTM_xptType_Enum eXptType;
   unsigned char iRgi;
   unsigned long iBias;
   unsigned long iIqGain;
   unsigned short iEnvScale;
   unsigned short iPaState;
   unsigned short iPaCurrent;
   long iPout_dbm10;
   QMSL_xpt_dpd_file_data sDpdData;
   unsigned short iNumEpdt;
   unsigned short aEpdt[MAX_NUM_EPDT_SIZE];
} QMSL_xpt_cal_lin_nv_struct;

/* This struct is going to be filled up in EPT PA State*/
typedef struct
{
   unsigned long channel;
   unsigned long upperBoundCh;
   unsigned short iPaState;
   unsigned char iRgi;
   unsigned long iBias;
   unsigned long iIqGain;
   unsigned short iEnvScale;
   unsigned short iPaCurrent;
   long iPout_dbm10;
} QMSL_xpt_cal_rgi_delta_nv_struct;

typedef struct
{
   unsigned long iChannel;
   //unsigned long iNumMeasurements;
   FTM_xptType_Enum aXptType;
   unsigned short aPaState;
   long aPout_dbm10;
} QMSL_xpt_cal_freq_comp_nv_struct;

typedef struct
{
   unsigned short numProtoCalLinRecords;
   unsigned short numProtoCalFcompRecords;
   unsigned short numProtoCalRgiDeltaRecords;
   // RGI Delta will only be measured in EPT PA state
   // This needs to be copied to ET PA State
   unsigned short iEtPaState;
   QMSL_xpt_cal_lin_nv_struct* aProto_Cal_Lin_Records;
   QMSL_xpt_cal_freq_comp_nv_struct* aProto_Cal_FComp_Records;
   QMSL_xpt_cal_rgi_delta_nv_struct* aProto_Cal_Rgi_Delta_Records;
} QMSL_xpt_cal_nv_struct;

const unsigned char QMSL_MULTILIN_V3_FCOMP_TYPE_INVALID = 0xFF;
const unsigned char QMSL_MULTILIN_V3_FCOMP_TYPE_FULL_BIAS = 0;
const unsigned char QMSL_MULTILIN_V3_FCOMP_TYPE_XPT = 1;

const int MAX_XPT_FREQ_COMP_MEAS = 8;
typedef struct QMSL_RFNV_CAL_CHANS_DATA_STRUCT
{
   unsigned short iVariantHeader;
   /*! @brief Tx calibrated channel list */
   unsigned long aTxCalChannels[TXLIN_NUM_CHANNELS];
} QMSL_RFNV_CAL_CHANS_DATA_TYPE;

typedef struct QMSL_RFNV_FREQ_OFFSETS_DATA_STRUCT
{
   unsigned short iVariantHeader;
   /*! @brief PA state this data belongs to */
   unsigned char iPaState;
   /*! @brief The freq-comp type (i.e full bias or otherwise) this data belongs to */
   unsigned char iFcompSweepType;
   /*! @brief The freq comp index this data belongs to */
   unsigned short iFcompIndex;
   /*! @brief 16 channel frequency compensation value */
   unsigned char aFreqOffsets[TXLIN_NUM_CHANNELS];
} QMSL_RFNV_FREQ_OFFSETS_DATA_TYPE;

typedef struct QMSL_RFNV_LIN_TABLE_V3_DATA_STRUCT
{
   unsigned short iVariantHeader;
   /*! @brief PA state this linearizer belongs to */
   unsigned char iPaState;
   /*! @brief Waveform type this linearizer belongs to */
   unsigned char iWaveformState;
   /*! @brief Tx channel this linearizer belongs to in chan list */
   unsigned long  iTxChannel;
   /*! @brief Upper bound tx frequency */
   unsigned long iUpperBoundTxChannel;
   /*! @brief RGI/LUT index */
   unsigned short aRgiList[TXLIN_NUM_SEGMENTS];
   /*! @brief TxAGC in dB10 */
   short  aTxPower[TXLIN_NUM_SEGMENTS];
   /*! @brief SMPS Bias */
   unsigned long aBias[TXLIN_NUM_SEGMENTS];
   /*! PA Current */
   unsigned short aPaCurrent[TXLIN_NUM_SEGMENTS];
   /*! IQ Offset */
   unsigned short aIqOffset[TXLIN_NUM_SEGMENTS];
   /*! DPD Type that this linearizer uses */
   unsigned char iXptDpdType;
   /*! The total number of DPDs that this linearizer uses */
   unsigned short iNumDpds;
   /*! DPD Index */
   unsigned short aDpdIndices[TXLIN_NUM_SEGMENTS];
   /*! The freq-comp type to be used */
   unsigned char iFCompType;
   /*! The total number of freqcomp lists that this linearizer uses */
   unsigned short iNumFComps;
   /*! The freq comp index this row is associated with */
   unsigned short aFcompIndex[TXLIN_NUM_SEGMENTS];
} QMSL_RFNV_LIN_TABLE_V3_DATA_TYPE;

typedef struct QMSL_RFNV_LIN_TABLE_TXRSBLOFT_DATA_STRUCT
{
   /*! Tx RSB compensation value */
   unsigned long aRsbComp[TXLIN_NUM_SEGMENTS];
   /*! Tx LOFT compensation value */
   unsigned long aLoftComp[TXLIN_NUM_SEGMENTS];
} QMSL_RFNV_TXRSBLOFT_DATA_TYPE;

typedef struct QMSL_RFNV_LIN_TABLE_V4_DATA_STRUCT
{
   unsigned short iVariantHeader;
   /*! @brief PA state this linearizer belongs to */
   unsigned char iPaState;
   /*! @brief Waveform type this linearizer belongs to */
   unsigned char iWaveformState;
   /*! @brief Tx channel this linearizer belongs to in chan list */
   unsigned long  iTxChannel;
   /*! @brief Upper bound tx frequency */
   unsigned long iUpperBoundTxChannel;
   /*! @brief RGI/LUT index */
   unsigned short aRgiList[TXLIN_NUM_SEGMENTS];
   /*! @brief TxAGC in dB10 */
   short  aTxPower[TXLIN_NUM_SEGMENTS];
   /*! @brief SMPS Bias */
   unsigned long aBias[TXLIN_NUM_SEGMENTS];
   /*! PA Current */
   unsigned short aPaCurrent[TXLIN_NUM_SEGMENTS];
   /*! IQ Offset */
   unsigned short aIqOffset[TXLIN_NUM_SEGMENTS];
   /*! DPD Type that this linearizer uses */
   unsigned char iXptDpdType;
   /*! The total number of DPDs that this linearizer uses */
   unsigned short iNumDpds;
   /*! DPD Index */
   unsigned short aDpdIndices[TXLIN_NUM_SEGMENTS];
   /*! The freq-comp type to be used */
   unsigned char iFCompType;
   /*! The total number of freqcomp lists that this linearizer uses */
   unsigned short iNumFComps;
   /*! The freq comp index this row is associated with */
   unsigned short aFcompIndex[TXLIN_NUM_SEGMENTS];
   /*! Tx RSB & LOFT compensation data */
   QMSL_RFNV_TXRSBLOFT_DATA_TYPE txRsbLoftData;
} QMSL_RFNV_LIN_TABLE_V4_DATA_TYPE;

typedef struct QMSL_RFNV_DELTA_GAIN_PIN_POUT_DATA_STRUCTURE
{
   unsigned short iVariantHeader;
   byte dpd_idx;
   byte num_pin;
   int8 pin_misalign[MAX_NUM_PIN_DELTA_GAIN_PIN_POUT];
   int8 gain_comp[MAX_NUM_PIN_DELTA_GAIN_PIN_POUT];
   int8 pout_delta[MAX_NUM_PIN_DELTA_GAIN_PIN_POUT];
} QMSL_RFNV_DELTA_GAIN_PIN_POUT_DATA_STRUCTURE;

typedef union QMSL_RFNV_LIN_TABLE_UNION_DATA_STRUCT
{
   /*! V3 Type Lin Table */
   QMSL_RFNV_LIN_TABLE_V3_DATA_TYPE linTableV3;
   /*! V4 Type Lin Table with Tx RSB/LOFT */
   QMSL_RFNV_LIN_TABLE_V4_DATA_TYPE linTableV4;
} QMSL_RFNV_LIN_TABLE_UNION_DATA_TYPE;

typedef struct QMSL_RFNV_LIN_TABLE_VARIANT_DATA_STRUCT
{
   /*! Size of Lin Table corresponding to linTable */
   unsigned long tblSize;
   /*! Enum Indicating type of data contained in linTable*/
   QMSL_RFNV_DATA_TYPE_IDS_ENUM linTableType;
   /*! Union Struct containing table corresponding to linTableId ID */
   QMSL_RFNV_LIN_TABLE_UNION_DATA_TYPE linTable;
} QMSL_RFNV_LIN_TABLE_VARIANT_DATA_TYPE;

typedef struct QMSL_RFNV_EPT_DPD_V2_DATA_TYPE
{
   unsigned short iVariantHeader;
   /*! @brief Index identifying this EPT DPD record */
   unsigned short iRecordIndex;
   /*! @brief AMAM Coeff */
   unsigned long aAmAm[TXLIN_XPT_DPD_NUM_COEFF];
   /*! @brief AMPM Coeff */
   long aAmPm[TXLIN_XPT_DPD_NUM_COEFF];
} QMSL_RFNV_EPT_DPD_V2_DATA_TYPE;

typedef struct QMSL_RFNV_ET_DPD_DATA_TYPE
{
   unsigned short iVariantHeader;
   /*! @brief Index identifying this ET DPD record */
   unsigned short iRecordIndex;
   /*! @brief AMAM Coeff */
   unsigned long aAmAm[TXLIN_XPT_DPD_NUM_COEFF];
   /*! @brief AMPM Coeff */
   long aAmPm[TXLIN_XPT_DPD_NUM_COEFF];
   /*! @brief Detrough */
   unsigned long aDetrough[TXLIN_XPT_DPD_NUM_COEFF];
} QMSL_RFNV_ET_DPD_DATA_TYPE;

typedef struct QMSL_RFNV_REF_LIN_TEMP_ADC_STRUCT
{
   unsigned short iVariantHeader;
   /*! @brief Temperature ADC Read */
   unsigned short iTempADC;
} QMSL_RFNV_REF_LIN_TEMP_ADC_TYPE;

typedef struct QMSL_RFNV_DATA_TYPE_RX_CAL_OFFSET_V1_STRUCT
{
   unsigned short iVariantHeader;
   /*! @brief Index identifying this RX_CAL_OFFSET_V1 record */
   unsigned char iChainID;
   /*! @brief Chain ID */
   unsigned char iCarrID;
   /*! @brief Carrier ID */
   signed short iLNAOffsets[ NUM_RX_LNA_OFFSETS ];
   /*! @brief Vector of LNA Offsets */
   signed short iVGAOffset;
   /*! @brief VGA Offset */
} QMSL_RFNV_DATA_TYPE_RX_CAL_OFFSET_V1_TYPE;

typedef struct QMSL_RFNV_DATA_TYPE_RX_OFFSET_VS_FREQ_V1_STRUCT
{
   unsigned short iVariantHeader;
   /*! @brief Index identifying this RX_OFFSET_VS_FREQ_V1 record */
   unsigned char iChainID;
   /*! @brief Chain ID */
   unsigned short iChannel;
   /*! @brief Channel */
   unsigned char iChanIDX;
   /*! @brief Channel Index*/
   signed char iVGAGainOffsetVsFreq;
   /*! @brief VGA Gain Offset Vs Freq*/
   signed char iLNAOffsetVsFreq[ NUM_RX_LNA_OFFSETS - 1 ];
   /*! @brief LNA Offset Vs Freq*/
} QMSL_RFNV_DATA_TYPE_RX_OFFSET_VS_FREQ_V1_TYPE;

typedef struct QMSL_RFCAL_Unified_Rx_Struct
{
   /*! @brief Ref Channel */
   unsigned short iRefRxChan[2];
   QMSL_Variant_Marker_Type aVariantMarker;
   unsigned char aPayload[448];//according to the NV definition
   //3*2*sizeof(QMSL_RFNV_DATA_TYPE_RX_CAL_OFFSET_V1_TYPE)+16*2*sizeof(QMSL_RFNV_DATA_TYPE_RX_OFFSET_VS_FREQ_V1_TYPE)
} QMSL_RFCAL_UNIFIED_RX_TYPE;

typedef enum
{
   RX_CARR_SC = 0,
   RX_CARR_DC = 1,
   RX_CARR_3C = 2,
   RX_CARR_MAX = 255
} RX_CARR_ID;

typedef struct QMSL_RFNV_DATA_FB_GAIN_STRUCT
{
   unsigned char channel_index;
   /*! @brief Index identifying this channel record */
   unsigned char gain_state_index;
   /*! @brief Index identifying this fb_gain_state */
   short fbrx_gain_value;
   /*! @brief Index identifying this fb_gain_state */
} QMSL_RFNV_DATA_FB_GAIN_TYPE;

typedef struct
{
   /*! @brief variable for Channel Index */
   uint8 channel_index;

   /*! @brief variable for feedback mode Index */
   uint8 fbrx_mode_index;

   /*! @brief variable for Gain State Index */
   uint8 gain_state_index;

   /*! @brief variable for Gain value */
   int32 fbrx_gain_value;

   /*! @brief variable for Tx Power */
   int16 tx_power;

   /*! @brief variable for bias */
   uint8 ubias;

   /*! @brief variable for rx scale */
   uint16 rx_scale;

   /*! @brief variable for peak index value for Fb Cross Correlation */
   uint16 fbXCorrPeakIndex;
} QMSL_RFNV_DATA_FB_GAIN_TYPE_V2;

typedef struct QMSL_RFNV_DATA_FB_GAIN_THERM_READ_TYPE
{
   uint16 variantdatatype;

   /*! @brief Therm Read */
   uint16 therm_read;
} QMSL_RFNV_DATA_FB_GAIN_THERM_READ_TYPE;

typedef enum
{
   FBRX_GAIN_DATA_V1 = 0,
   FBRX_GAIN_DATA_V2 = 1,
   FBRX_GAIN_DATA_MAX = 255
} FBRX_GAIN_DATA_VERSION;

typedef struct
{
   uint16 variantdatatype;
   union
   {
      QMSL_RFNV_DATA_FB_GAIN_TYPE fbrx_gain_data_v1;
      QMSL_RFNV_DATA_FB_GAIN_TYPE_V2 fbrx_gain_data_v2;
   } fbrx_gain_data_type;
} QMSL_RFNV_FBRX_GAIN_DATA;

#define FBRX_GAIN_STATE_MAX (2)
#define FBRX_MAX_NUM_CAL_CHANNELS (16)
#define FBRX_NUM_MODES_MAX (8)
//define mode index
typedef struct
{
   enum {FBRX_DATA_SIZE_MAX = FBRX_MAX_NUM_CAL_CHANNELS * FBRX_GAIN_STATE_MAX * FBRX_NUM_MODES_MAX * sizeof(QMSL_RFNV_FBRX_GAIN_DATA)};

   uint8 num_cal_channel;

   uint16 cal_channel_list[FBRX_MAX_NUM_CAL_CHANNELS];

   QMSL_Variant_Marker_Type aVariantMarker;

   uint8 aPayload[FBRX_DATA_SIZE_MAX];
} QMSL_RFNV_FBRX_GAIN_NV_Container;

//Definition for Feedback RX DC Cal
typedef struct
{
   long dc_i;
   long dc_q;
} QMSL_DC_CAL_PER_GAIN_STATE;

typedef struct
{
   unsigned char reserved;

   QMSL_DC_CAL_PER_GAIN_STATE DC_CAL[QMSL_NUM_FBRx_GAIN_STATES][QMSL_NUM_FBRx_MODES];
} QMSL_DC_CAL_NV_STRUCT;

typedef struct
{
   unsigned char group_delay;
   unsigned char num_filter_taps;
   long filter_coeffs[QMSL_DROOP_FILTER_COEFFS_NUM];
} QMSL_FBRX_DROOP_CAL_DATA_STRUCT;

typedef struct
{
   unsigned char reserved;

   QMSL_FBRX_DROOP_CAL_DATA_STRUCT FBRX_DROOP_CAL_DATA_STRUCT;
} QMSL_FBRX_DROOP_CAL_NV_STRUCT;

typedef struct
{
   uint16 variantdatatype;

   uint8 fbrx_mode_index;

   unsigned char reserved;

   QMSL_FBRX_DROOP_CAL_DATA_STRUCT FBRX_DROOP_CAL_DATA_STRUCT;
} QMSL_FBRX_DROOP_CAL_PER_BAND_NV_STRUCT;

typedef struct
{
   enum {FBRX_DROOP_PER_BAND_DATA_SIZE_MAX = FBRX_NUM_MODES_MAX * (sizeof(QMSL_FBRX_DROOP_CAL_PER_BAND_NV_STRUCT))};

   QMSL_Variant_Marker_Type aVariantMarker;

   uint8 aPayload[FBRX_DROOP_PER_BAND_DATA_SIZE_MAX];
} QMSL_RFNV_FBRX_DROOP_PER_BAND_NV_Container;

typedef struct
{
   QMSL_RFNV_FBRX_DROOP_PER_BAND_NV_Container fbrx_droop_cal_struct;

   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_RFNV_FBRX_DROOP_PER_BAND_NV_RESULT;

typedef struct
{
   QMSL_DC_CAL_NV_STRUCT DC_CAL_STRUCT;

   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_DC_CAL_NV_RESULT;

typedef struct
{
   QMSL_FBRX_DROOP_CAL_NV_STRUCT FBRX_DROOP_CAL_STRUCT;

   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_FBRX_DROOP_CAL_NV_RESULT;

//Note : This size only includes payload section and not the variant marker
#define QMSL_TXLIN_NV_V3_NUM_CHAN_TABLES 1
#define QMSL_TXLIN_NV_V3_MAX_FREQ_TABLES 32 //8*4 - 8 FComp per PA for 4 Waveform types
#define QMSL_TXLIN_NV_V3_MAX_LIN_TABLES 256 //16*4*4 - 16 Chan * 4 PAs * 4 Waveform types
//Some of these Max numbers are arbitrary - based only on discussions in the lab.
//May need to be revisited if the design changes - for now - this far exceeds planned design (1 waveform * 4 max dpds)
#define QMSL_TXLIN_NV_V3_MAX_DPD_TABLES 512   //16*1*2*16 - 16 Chan * 1 PA * 2 Max Waveform Types per linearizers * 16 MAX DPDs per linearizer
#define QMSL_TXLIN_NV_V3_MAX_TEMP_TABLES 1
#define QMSL_TXLIN_NV_V3_SIZE_MAX  ( 0                           \
   + (QMSL_TXLIN_NV_V3_NUM_CHAN_TABLES  *  sizeof( QMSL_RFNV_CAL_CHANS_DATA_TYPE    ) )  \
   + (QMSL_TXLIN_NV_V3_MAX_FREQ_TABLES  *  sizeof( QMSL_RFNV_FREQ_OFFSETS_DATA_TYPE ) )  \
   + (QMSL_TXLIN_NV_V3_MAX_LIN_TABLES   *  sizeof( QMSL_RFNV_LIN_TABLE_V3_DATA_TYPE ) )  \
   + (QMSL_TXLIN_NV_V3_MAX_DPD_TABLES   *  sizeof( QMSL_RFNV_EPT_DPD_V2_DATA_TYPE   ) )  \
   + (QMSL_TXLIN_NV_V3_MAX_DPD_TABLES   *  sizeof( QMSL_RFNV_ET_DPD_DATA_TYPE       ) )  \
   + (QMSL_TXLIN_NV_V3_MAX_TEMP_TABLES  *  sizeof( QMSL_RFNV_REF_LIN_TEMP_ADC_TYPE  ) ) )

#define QMSL_FBRX_GAIN_FREQ_CHANNEL_LIST_MAX (16) //16 channel data per band for storing FB_Gain NV Item
#define QMSL_FBRX_GAIN_STATES_MAX (2) //Set to 2 : High Attenuation State and Low Attenuation State
#define QMSL_FBRX_GAIN_FREQ_V0_SIZE_MAX (QMSL_FBRX_GAIN_STATES_MAX * QMSL_FBRX_GAIN_FREQ_CHANNEL_LIST_MAX * sizeof(QMSL_FBRX_GAIN_FREQ_LIST_Variant_Type ) )
//Maximum Size of Payload for FBRX_GAIN_FREQ NV Item 2*16*6 - 2 FB_States * 16 Chan * 6( variant header(2) +channel_index(1) + gain_state_index(1)+ fbrx_gain_value(1) )
//V0: Version 0

typedef struct QMSL_FBRX_GAIN_FREQ_LIST_Variant_Struct
{
   unsigned short iVariantHeader;

   //struct containing channel index , gain_state and fb path gain
   QMSL_RFNV_DATA_FB_GAIN_TYPE afbgaindata;
} QMSL_FBRX_GAIN_FREQ_LIST_Variant_Type;

typedef struct QMSL_RFCAL_FBRX_GAIN_FREQ_NV_Rev0_Struct
{
   // No of Cal channels (currently set to 16)
   unsigned char num_cal_chan;

   //Array of cal channel numbers
   unsigned short cal_channel_list[QMSL_FBRX_GAIN_FREQ_CHANNEL_LIST_MAX];

   QMSL_Variant_Marker_Type aVariantMarker;

   //Payload containing FB_GAIN_TYPE structs
   unsigned char aPayload[QMSL_FBRX_GAIN_FREQ_V0_SIZE_MAX];
} QMSL_RFCAL_FBRX_GAIN_FREQ_NV_Rev0_Type;

typedef struct QMSL_RFCAL_FBRX_GAIN_FREQ_NV_Container
{
   //The actual NV Item
   QMSL_RFCAL_NV_Item nvFbGainNvItem;

   //The NV data
   QMSL_RFCAL_FBRX_GAIN_FREQ_NV_Rev0_Type nvFbGainv0Rev0;
} QMSL_RFCAL_FBRX_GAIN_FREQ_NV;

typedef struct QMSL_RFCAL_ESC_NV_Rev0_Struct
{
   QMSL_Variant_Marker_Type aVariantMarker;
   unsigned char aPayload[QMSL_TXLIN_NV_V3_SIZE_MAX];
} QMSL_RFCAL_ESC_NV_Rev0_Type;

typedef struct QMSL_RFCAL_LTE_TX_XPT_DELAY_NV
{
   unsigned char iNumActiveEntries;
   unsigned short int aUpperBoundChannels[TXLIN_NUM_CHANNELS];
   int a05MHzDelay[TXLIN_NUM_CHANNELS];
   int a10MHzDelay[TXLIN_NUM_CHANNELS];
   int a20MHzDelay[TXLIN_NUM_CHANNELS];
} QMSL_RFCAL_LTE_TX_XPT_DELAY_NV_Type;

typedef struct QMSL_RFCAL_WCDMA_TX_XPT_DELAY_NV
{
   unsigned char iNumActiveEntries;
   unsigned short int aUpperBoundChannels[TXLIN_NUM_CHANNELS];
   int aDelay[TXLIN_NUM_CHANNELS];
} QMSL_RFCAL_WCDMA_TX_XPT_DELAY_NV_Type;

typedef struct QMSL_RFCAL_TDSCDMA_TX_XPT_DELAY_NV_Type
{
   unsigned char iNumActiveEntries;
   unsigned short int aUpperBoundChannels[TXLIN_NUM_CHANNELS];
   int aDelay[TXLIN_NUM_CHANNELS];
} QMSL_RFCAL_TDSCDMA_TX_XPT_DELAY_NV_Type;

typedef struct QMSL_RFCAL_TX_XPT_PIN_CAL_DATA_NV
{
   int16 aPinVsFreq[MAX_NUM_PA_STATES_FOR_PIN_CAL][TXLIN_NUM_CHANNELS];
} QMSL_RFCAL_TX_XPT_PIN_CAL_DATA_NV_Type;

typedef struct QMSL_RFCAL_TX_XPT_PIN_CAL_INFO
{
   unsigned int optionMask; // bit0: AMAM; bit1: AMPM
   unsigned int numberOfPinChannels;
   unsigned short pinChannelArray[TXLIN_NUM_CHANNELS];
} QMSL_RFCAL_TX_XPT_PIN_CAL_CHANNELS;

typedef struct QMSL_RFCAL_TX_XPT_AMPM_CAL_DATA_NV
{
   QMSL_Variant_Marker_Type variantTypeHearder; //version 0, number of element 1
   unsigned short variantDataType; // should be QMSL_RFNV_DATA_TYPE_ID_AMPM_SCALING_FACTOR (113)
   int aAMPMScalingFactorVsFreq[TXLIN_NUM_CHANNELS];
} QMSL_RFCAL_TX_XPT_AMPM_CAL_DATA_NV_Type;

typedef struct QMSL_RFCAL_ESC_Calibration_NV_Container
{
   //The NV Data
   QMSL_RFCAL_ESC_NV_Rev0_Type nvMultiLinv3Rev0;

   //! The actual NV item
   QMSL_RFCAL_NV_Item nvMultiLinv3Item;

   //The NV Data
   QMSL_RFCAL_LTE_TX_XPT_DELAY_NV_Type lteDelayNV;

   //! The actual NV item
   QMSL_RFCAL_NV_Item lteDelayNVitem;

   //The NV Data
   QMSL_RFCAL_WCDMA_TX_XPT_DELAY_NV_Type wcdmaDelayNV;

   //! The actual NV item
   QMSL_RFCAL_NV_Item wcdmaDelayNVitem;

   //The NV Data
   QMSL_RFCAL_TDSCDMA_TX_XPT_DELAY_NV_Type tdsDelayNV;

   //! The actual NV item
   QMSL_RFCAL_NV_Item tdsDelayNVitem;

   //! PIN/AMPM CAL channels (not to be written into NV)
   QMSL_RFCAL_TX_XPT_PIN_CAL_INFO pinCalInfo;

   //Tx XPT Pin Cal Data Needed for NV generation
   QMSL_RFCAL_TX_XPT_PIN_CAL_DATA_NV_Type txXptPinCalDataForNV;

   //! Actual NV Data
   QMSL_RFCAL_NV_Item txXptPinCalNVItem;

   //The NV Data for FBRx Gain NV
   QMSL_RFNV_FBRX_GAIN_NV_Container fbrxgainNVdata;

   //! The actual NV item
   QMSL_RFCAL_NV_Item fbrxgainNVitem;

   //The NV Data for FBRx DC NV
   QMSL_DC_CAL_NV_STRUCT fbrxDcNVdata;

   //! The actual NV item
   QMSL_RFCAL_NV_Item fbrxDcNVitem;

   //! AMPM Scaling Cal Data
   QMSL_RFCAL_TX_XPT_AMPM_CAL_DATA_NV_Type xptAMPMScalingCalDataForNV;

   //! Actual NV Data
   QMSL_RFCAL_NV_Item xptAMPMScalingCalNVItem;
} QMSL_RFCAL_ESC_Calibration_NV;

// structure in the format of the Cal V4 multiLin Header for the linearizer table struct
typedef struct QMSL_RFCAL_ESC_Multilin_NV_Header_Container
{
   // the PA state
   unsigned char paState;
   // the waveform type
   unsigned char waveformType;
   // the uplink/Tx channel
   unsigned long txChan;
   // the upper bound tx channel
   unsigned long upperBoundTxChan;
} QMSL_RFCAL_ESC_Multilin_NV_Header;

typedef struct
{
   //! Flag to state if HDET data is included or not.
   unsigned char HDETEnabled;

   //! PA state for which HDET was measured.
   unsigned char HDETPAState;

   //! Flag to state if LPM HDET data is included or not. Used for LTE BC13 only.
   unsigned char HDETLPMEnabled;

   //! Desired power level for HDET Offset calculation (usually 18 dBm).
   double HDETSpanPower_dBm;

   //! Desired power level for HDET Span calculation (usually 26 dBm).
   double HDETOffsetPower_dBm;

   //! Desired start power level for LPM HDET.
   double LPMHDETStartPower_dBm;

   //! Desired threshold power level for LPM HDET.
   double LPMHDETThresholdPower_dBm;

   //! Desired power level for LPM HDET Offset calculation. Used for LTE BC13 only.
   double LPMHDETSpanPower_dBm;

   //! Desired power level for LPM HDET Span calculation. Used for LTE BC13 only.
   double LPMHDETOffsetPower_dBm;

   //!  Boolean to specify whether HDET_V2 is used
   unsigned char useHDETV2;

   //! Boolean to specify whether composite HDET NV is used
   unsigned char useExtendedHDETNV;

   //! Max limit for HDET
   int HDETMaxLim;
} QMSL_RFCAL_ESC_HDET_NV_Params;

typedef struct
{
   //! HDET vs Tx AGC
   QMSL_CDMA_HDET_VS_AGC_NV_struct aHDET_vs_AGC;

   //! LPM HDET vs AGC
   QMSL_CDMA_HDET_VS_AGC_NV_struct aLPM_HDET_vs_AGC;

   //! LPM HDET vs AGC V2
   //QMSL_CDMA_LPM_HDET_VS_AGC_V2_NV_struct aLPM_HDET_vs_AGC_V2;

   //! LPM HDET vs AGC V3
   QMSL_CDMA_LPM_HDET_VS_AGC_V3_NV_struct aLPM_HDET_vs_AGC_V3;

   //! HDET offset
   QMSL_CDMA_HDET_OFFSET_NV_struct aHDET_offset;

   //! HDET span
   QMSL_CDMA_HDET_SPAN_NV_struct    aHDET_span;

   //! LPM HDET offset
   QMSL_CDMA_HDET_OFFSET_NV_struct aLPM_HDET_offset;

   //! LPM HDET span
   QMSL_CDMA_HDET_SPAN_NV_struct    aLPM_HDET_span;

   //! LTE HDET Offset and Span
   QMSL_LTE_HDET_OFFSET_SPAN_NV_struct aHDET_offset_span;
} QMSL_RFCAL_ESC_HDET_NV_Results;

/**
Definition of Tx LIM vs FREQ data generated by QMSL RF Calibration Data Manager
*/
typedef struct
{
   //! LIM vs FREQ NV item
   char aiLimVsFreq[QMSL_CDMA_MAX_CHANNELS];

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_RFCAL_Tx_LimVsFreq_NV_Results;

typedef struct
{
   uint8 num_modes;

   ftm_fbrx_droop_result_data_type fbrx_droop_data_for_nv[FBRX_NUM_MODES_MAX];
} QMSL_RFCAL_FBRX_Droop_data_type;

typedef enum
{
   CMAPI_SYS_MODE_CDMA,
   CMAPI_SYS_MODE_HDR,
   CMAPI_SYS_MODE_GSM,
   CMAPI_SYS_MODE_WCDMA,
   CMAPI_SYS_MODE_LTE,
   CMAPI_SYS_MODE_TDSCDMA,
   CMAPI_SYS_MODE_MAX
} cmapi_sys_mode_enum_type;

/*====================================================*/
//                    GSM CAL V4
/*====================================================*/
#define GSM_V4_MAX_NUM_OF_SLOTS           8       // 8 slots in a TDMA frame
#define GSM_V4_MAX_NUM_OF_FRAMES          400     // max number of frames that can be sent in FTM command
#define GSM_V4_MAX_NUM_OF_DEVICES         2       // Tx/Rx chains
#define GSM_V4_MAX_PACKET_SIZE            3400    // the max size of the FTM packets sent for GSM V4 Cal
#define GSM_V4_MAX_NUM_RESULTS            400     // the maximum number of results returned by the FTM command
#define GSM_V4_MAX_NUM_RESULTS_PER_SLOT   2       // maximum number of results returned per slot
#define GSM_V4_MAX_BUFF_SIZE              3400    // maximum buffer size of returned measurement results from phone
#define GSM_V4_TEMP_CMD_BUFF_SIZE         30500   // size of the temporary buffer for holding the GSM V4 cal command, which is variable in length
// Max # of slots   = (8 Tx slots) + (2 Rx slots) = 10
// Bytes per Frame = (10 slots) * (7 bytes per slot) + ( 6 bytes for frame header) = 76 bytes
// Max Command Size = (76 bytes per frame) * (400 frames) + (10 bytes for header) = 30410 bytes

//------- Embedded side constants that affect the Tools Development -------//
// The # of slots by which a Tx burst is shifted, relative to what is scheduled. This affects call-box setup.
// For example, if a Tx burst is schedule in slot 0, it will appear in slot 3.
#define GSM_V4_TX_SLOT_SHIFT_ON_PHONE      3
// The frame delay between band changes during the sweep
#define GSM_V4_INTRA_BAND_FRAME_DELAY      4
// The # of segments by of delay between band changes
#define GSM_V4_INTRA_BAND_SEG_DELAY        GSM_V4_INTRA_BAND_FRAME_DELAY * GSM_V4_MAX_NUM_OF_SLOTS
// The # of slots by which the secondary Tx chain is shifted relative to the primary Tx chain
#define GSM_V4_SEC_CHAIN_TX_SHIFT_ON_PHONE 4

//--------------------- Packet Structures for FTM Command -------------------//
// GSM V4 Tx PCL operation payload
// 2 bytes
typedef struct
{
   unsigned char modType;       // MCS index - valid range is 0 to 8
   // 0->MCS-1, 8->MCS-9
   unsigned char PCL_Index;     // PCL index value - valid rane is 0-15 - this indicates the index of the RFN_GSM_Cx_GSMxxxx_POWER_LEVELS_DB NV
} GSM_V4_PCL_Payload;

// GSM V4 Tx RGI operation payload
// 4 bytes
typedef struct
{
   unsigned char modType;     // Modulation Type: 0=8PSK, 1=GMSK
   unsigned char paState;     // PA state, 0 to 3
   unsigned char RGI;         // RGI - 0 to 31
   unsigned char envScale;
} GSM_V4_RGI_Payload;

// GSM V4 Rx RSSI operation payload
// 3 byte
typedef struct
{
   unsigned short channel;    // the channel
   unsigned char lnaState;    // the LNA state
} GSM_V4_RSSI_Payload;

// GSM V4 Rx dBm operation payload
// 4 byte
typedef struct
{
   unsigned short channel;    // the channel
   short expPwr;              // the expected power in dBm
} GSM_V4_RX_DBM_Payload;

// GSM V4 Tx dBm operation payload
// 3 byte
typedef struct
{
   unsigned char  mcs;        // modulation and coding scheme
   short pwr_dBm100;          // tx power in dBm*100
} GSM_V4_TX_DBM_Payload;

typedef struct
{
   unsigned char fbrx_gain_state;
   unsigned char pa_state;
   unsigned char rgi;
   unsigned char mod_type;
} GSM_V4_FBRx_Payload;

// enum of slot operation types
// 4 bytes
typedef enum
{
   Tx_PCL_Meas_Op,
   Tx_RGI_Meas_Op,
   Rx_RSSI_Meas_Op,
   Rx_DBM_Meas_Op,
   Tx_DBM_Meas_OP,
   Rx_RSSI_Meas_HiLin_Op,
   FBRx_Meas_Op
} GSM_V4_Slot_Operation_Type;

// slot payload
// 7 bytes
typedef struct
{
   unsigned char devID;       // the Tx/Rx chain ID
   unsigned char slotNum;     // the slot in which the Tx/Rx operation is to occur
   unsigned char slotOpID;    // corresponds to the GSM_V4_Slot_Operation_Type enum - 0->PCL, 1->RGI, 2->RSSI
   union
   {
      GSM_V4_PCL_Payload    pclPayload;
      GSM_V4_RGI_Payload    rgiPayload;
      GSM_V4_RSSI_Payload   rssiPayload;
      GSM_V4_RX_DBM_Payload rxDBmPayload;
      GSM_V4_TX_DBM_Payload txDBmPayload;
      GSM_V4_FBRx_Payload  fbrxPayload;
   } slotPayload;
} GSM_V4_Slot_Payload;

// frame payload
typedef struct
{
   unsigned char  band;
   unsigned short channel;
   unsigned char  numSlotsInPayload;
} GSM_V4_Frame_Header;

// main packet structure header
typedef struct
{
   unsigned short numFrames;
   unsigned short numChains;                                      // the number of chains/devices
   unsigned char  a_devId[GSM_V4_MAX_NUM_OF_DEVICES];             // device ID (chain list), Tx/Rx
   unsigned int   reserved;                                       // reserved for future use
} GSM_V4_Cal_Config_Header;

//--------------------- FTM Command Return Structure -------------------//
#define GSM_V4_Rx_RSSI_Result_Size  (9)   // bytes
#define GSM_V4_FBRx_GAIN_Result_Size (22)

typedef struct
{
   unsigned short channel;          // the channel of the result
   unsigned char  lnaState;         // the LNA state of the result (if Rx)
   unsigned int rssiMeasResult;     // Rx RSSI result, measured by the phone
   short rxPwr_dBm16;               // Rx power result, measured by the phone, in dBm16 units
} GSM_V4_RX_RSSI_RESULT_TYPE;

typedef struct
{
   unsigned short channel;          // the channel of the result
   unsigned char fbrxState;         // the FBRx gain state of the result
   unsigned int hwfbrxGainResult;   // FBRx gain result, measured by the ILPC HW
   unsigned int swfbrxGainResult;   // FBRx gain result, measured by the FW
   unsigned int error;
   unsigned char trunc_bits;
   unsigned int ls_err;
   unsigned short tempADC;
} GSM_V4_FBRx_GAIN_RESULT_TYPE;

#define GSM_V4_Result_Size  (GSM_V4_FBRx_GAIN_Result_Size + 1)   // currently 23 bytes
typedef struct
{
   unsigned char opID;
   union
   {
      GSM_V4_RX_RSSI_RESULT_TYPE rssiResult;
   } opResult;
} GSM_V4_Result_Type;

#define GSM_V4_Result_Payload_Size  (GSM_V4_MAX_NUM_RESULTS_PER_SLOT*GSM_V4_Result_Size + 5)   // currently 51 bytes
typedef struct
{
   unsigned short frameID;
   unsigned char  devID;         // device ID (chain ID)
   unsigned char  slotNum;
   unsigned char  numResults;
   GSM_V4_Result_Type result[GSM_V4_MAX_NUM_RESULTS_PER_SLOT];
} GSM_V4_Result_Payload_Type;

#define GSM_V4_Result_Response_Size  (GSM_V4_MAX_NUM_RESULTS*GSM_V4_Result_Payload_Size*GSM_V4_MAX_NUM_OF_DEVICES + 2)   // currently 400*51*2 + 2 bytes
typedef struct
{
   unsigned short numPayload;
   GSM_V4_Result_Payload_Type payload[GSM_V4_MAX_NUM_RESULTS*GSM_V4_MAX_NUM_OF_DEVICES];
} GSM_V4_FTM_CMD_Response_Type;

#define GSM_V4_Result_Buff_Size (GSM_V4_MAX_BUFF_SIZE + 3) // currently 3403 bytes
typedef struct
{
   unsigned char  emptyResultBuff;   // true if no more data is going to be sent
   unsigned short buffSize;          // Max value GSM_V4_MAX_BUFF_SIZE
   unsigned char  buffData[ GSM_V4_MAX_BUFF_SIZE ];
} GSM_V4_Result_Buff_Type;

#define MAX_NUM_OF_MOD_TYPE_GSM_PA_BIAS_NV 2 //Maximum no of Modulation types set to 2 GMSK and EDGE supported
#define MAX_NUM_OF_RGI_GSM_PA_BIAS_NV 32
#define MAX_NUM_PA_STATES_GSM_PA_BIAS_NV 6
#define MAX_NUM_PCL_COUNTS_GSM_PA_BIAS_NV 16

//--------------------- QMSL struct for holding payload for GSM RGI vs Icq data -------------------//
typedef struct
{
   unsigned char pa_state;
   unsigned short cal_vcc;
   unsigned int rgi_icq[MAX_NUM_OF_MOD_TYPE_GSM_PA_BIAS_NV*MAX_NUM_OF_RGI_GSM_PA_BIAS_NV];
} QMSL_FTM_GSM_PA_BIAS_PARAMS_TYPE;

//--------------------- QMSL struct for GSM V4 Tx PCL Cal Results -------------------//
typedef struct
{
   //! The NV Container to Use
   unsigned char iTxNvContainer;

   //! Number of channels measured
   unsigned long iNumChannels;

   //! Calibration channel number
   unsigned short   iChannel[ QMSL_GSM_MAX_TX_CAL_CHANNELS ];

   //! Storage for GSM mode Tx power error (dBm) for each PCL index for each channel
   double aiGSMTxPowerMeasErr[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][ QMSL_GSM_MAX_PCL_STEPS ];

   //! Storage for EDGE mode Tx power error (dBm) for each PCL index for each channel
   double aiEDGETxPowerMeasErr[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][ QMSL_GSM_MAX_PCL_STEPS ];

   //! Storage for GSM mode Tx PCL for each channel
   unsigned short aiGSM_pclIdx[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][ QMSL_GSM_MAX_PCL_STEPS ];

   //! Storage for EDGE mode Tx PCL for each channel
   unsigned short aiEDGE_pclIdx[ QMSL_GSM_MAX_TX_CAL_CHANNELS ][ QMSL_GSM_MAX_PCL_STEPS ];

   //! Number of Tx gain indices measured
   unsigned long iNumMeasuredPCL;
} QMSL_GSM_V4_PCL_Cal_Result;

typedef struct
{
   //ftm_mode_id_type
   unsigned char iRfMode;

   //Boolean
   unsigned char iOverrideStg;

   unsigned char iPrxDevice;
   unsigned char iDrxDevice;

   //Boolean
   unsigned char iExitRequired;
} QMSL_FTM_RSB_TXLO_PKT_TYPE;

typedef struct
{
   //ftm_mode_id_type
   unsigned char iRfMode;

   //Boolean
   unsigned char iOverrideStg;

   //Tx Device
   unsigned char iTxDevice;

   //Boolean 0- No Teardown 1-Teardown Radio
   unsigned char iExitRequired;
} QMSL_FTM_FBRX_RSB_PKT_TYPE;

typedef enum
{
   MLINE_DEBUG_MASK_NDB_COMPR_PT_FAILURE = 0,
   /*! Did not achieve expected compression for M Line */

   MLINE_DEBUG_MASK_EXPPWR_GT_MAXPWR_MEAS = 1,
   /*! Did not find a power in the M Line table
   greater than requested power for measured powers */

   MLINE_DEBUG_MASK_EXPPWR_LT_MAXPWR_MEAS = 2,
   /*! Did not find a power in the M Line table less
   than requested power  for measured powers*/

   MLINE_DEBUG_MASK_INTBIAS_LT_VMAX_MEAS = 3,
   /*! Selected Bias > Vdmax but interpolated Bias < Vmax
   for measured powers*/

   MLINE_DEBUG_MASK_INTBIAS_GT_VMAX_MEAS = 4,
   /*! Selected Bias > Vdmax and interpolated Bias > Vmax
   for measured powers */

   MLINE_DEBUG_MASK_EXPPWR_GT_MAXPWR_CALC = 5,
   /*! Did not find a power in the M Line table
   greater than requested power for calculated powers*/

   MLINE_DEBUG_MASK_EXPPWR_LT_MAXPWR_CALC = 6,
   /*! Did not find a power in the M Line table less
   than requested power for calculated powers */

   MLINE_DEBUG_MASK_INTBIAS_LT_VMAX_CALC = 7,
   /*! Selected Bias > Vdmax but interpolated Bias < Vmax
   for calculated powers */

   MLINE_DEBUG_MASK_INTBIAS_GT_VMAX_CALC = 8,
   /*! Selected Bias > Vdmax and interpolated Bias > Vmax
   for calculated powers */

   MLINE_DEBUG_MASK_NEG_BIAS_SLOPE = 9
                                     /*! Progressively decreasing Bias condition in the M Line table*/
} ftm_mline_debug_mask;

/*====================================================*/
//                    LTE CA NS
/*====================================================*/

/*! Maximum number of LTE Carriers for which FTM_LTE_NS_GET_ALL_CARR_DL_BLER return the BLER information(Pcell + all Scell) */
#define MAX_NUM_LTE_CARRIERS_BLER 5
#define MAX_NUM_LTE_SCC 4

/*! Structure to define BLER response for an LTE carrier */
typedef struct
{
   /*! Carrier ID */
   byte carrierID;

   /*! Total Number of Blocks Received for this Carrier*/
   dword totalBlocksReceived;

   /*! Total Number of Error Blocks */
   dword totalBlockErrors;

   /*! Throughput*/
   dword throughputbps;
} ftm_lte_bler_struct;

/*! Structure to define BLER response for all LTE carriers*/
typedef struct
{
   /*! Total number of carriers for which DL BLER is reported(PCELL + All SCELL) */
   byte numCarriers;

   /*! Array to hold the BLER information for all Carriers */
   ftm_lte_bler_struct carrier_BLER_Array[MAX_NUM_LTE_CARRIERS_BLER];
} ftm_lte_bler_allCarr_Struct;

typedef struct
{
   /*! This is the E-UTRA band, which is band-1, e.g. B1 will be identified through scc_band = 0  */
   unsigned char scc_band;
   /*! SCC DL channel number */
   unsigned long scc_chan;
} ftm_lte_ns_scc_config_struct;

typedef struct
{
   /*! This is the E-UTRA band, which is band-1, e.g. B1 will be identified through scc_band = 0  */
   unsigned char scc_ul_band;
   /*! SCC UL channel number */
   unsigned long scc_ul_chan;
   /*! SCC C-RNTI value */
   unsigned short c_rnti;
   /*! SCC Network Signaling Value */
   unsigned char ns_ca_val;
   /*! SCC Uplink locical channel ID used by RLC */
   unsigned char ul_lcid_val;
   /*! SCC P_MAX corresponds to P_EMAX in [S1]; this value limits UE Tx power; the UE must not transmit at higher power than min[P_EMAX, P_UMAX], where P_UMAX is the maximum the UE is capable of transmitting */
   unsigned char pwr_limit;
   /*! SCC UL BW */
   unsigned char ul_bw;
} ftm_lte_ns_scc_ul_config_struct;

typedef struct
{
   ftm_lte_ns_scc_config_struct SCC_config_Array[MAX_NUM_LTE_SCC];
} ftm_lte_ns_multi_scc_config_struct;

typedef struct
{
   ftm_lte_ns_scc_config_struct SCC_dl_config_Array[MAX_NUM_LTE_SCC];
   ftm_lte_ns_scc_ul_config_struct SCC_ul_config_Array[MAX_NUM_LTE_SCC];
} ftm_lte_ns_multi_scc_ul_dl_config_struct;

typedef struct
{
   unsigned char averages;
   unsigned short delay;
   unsigned char inc_gain;
   unsigned char ref_gain;
   unsigned char thr_gain;
   unsigned char tia_range;
   unsigned char ref_phs_gain;
   unsigned char thr_phs_gain;
   unsigned char inp_pwr_phs_gain;
} ftm_tuner_rl_cmd_inputs;

typedef struct
{
   unsigned short pwr_thr_raw;
   unsigned short pwr_ref_raw;
   unsigned short pwr_inc_raw;
   unsigned short pwr_thr_dbm;
   unsigned short pwr_ref_dbm;
   unsigned short pwr_inc_dbm;
   unsigned short rl_dbm;
   unsigned short pwr_phs_inp_raw;
   unsigned short pwr_phs_thr_raw;
   unsigned short pwr_phs_ref_raw;
} ftm_tuner_rl_cmd_outputs;

const int FTM_RF_MAX_TUNE_CODE_SIZE_IN_BYTES = 8;
const int FTM_RF_MAX_NUM_ANTENNAS = 4;
const int MAX_TUNERS_TO_PROGRAM = 5;

typedef struct
{
   unsigned char tuner_id;
   unsigned char tunecode_size;
   unsigned char tunecode[FTM_RF_MAX_TUNE_CODE_SIZE_IN_BYTES];
   unsigned char nvg;
   unsigned char status;
} ftm_program_tuner_info;

typedef struct
{
  /*!< Antenna number */
  uint8 ant_num;

  /*!< Tuner Manager Type */
  uint8 tuner_mgr_type;

  /*!< Impedance Tuner - Tx Algo Type */
  uint8 impedance_tx_algo_type;

  /*!< Indicates the size of tune code in bytes */
  uint8 tune_code_size;
  
  /*!< Tune code data*/
  uint8 tune_code_data[FTM_RF_MAX_TUNE_CODE_SIZE_IN_BYTES];

  /*!< Tuner manager device state*/
  uint8 device_state;

  /*!< Aperture Tuner - Tx Algo Type */
  uint8 aperture_tx_algo_type;

  /*!< Tuner - Rx Algo Type */
  uint8 rx_algo_type;

  /*!< charge pump status of the tuners associated with the antenna */
  uint8 charge_pump_status;
  
  /*!< Byte level tunecode mapping. 
  Each byte carries the tuner instance ID of the corresponding 
  tunecode byte in TuneCode data*/
  uint8 tune_code_mapping[FTM_RF_MAX_TUNE_CODE_SIZE_IN_BYTES];
}ftm_rf_ant_tuner_tuner_status_data_type;

/*! Enumeration to indicate the status code*/
typedef enum
{
  FTM_RF_ANT_TUNER_SC_SUCCESS = 0, /*!< 0 : Indicates the success status of requested command */

  FTM_RF_ANT_TUNER_SC_BAD_CMD = 1,/*!< 1 : Indicates bad command */

  FTM_RF_ANT_TUNER_SC_CMD_HANDLER_FAIL = 2,/*!< 2 : Indicates the failure from the command handler */

  FTM_RF_ANT_TUNER_SC_NULL_PARAM = 3,/*!< 3 : Indicates the failure from the command handler */

  FTM_RF_ANT_TUNER_SC_NO_RSP_FROM_HANDLER = 4,/*!< 4: Indicates there is not response from handler*/

  FTM_RF_ANT_TUNER_SC_NUM  /*!< Max : Defines maximum number of error codes */

} ftm_rf_ant_tuner_status_code_enum_type;

typedef enum
{
  FTM_SET_TUNER_DISABLE_TUNE_CODE_OVERRIDE = 0, /*!< 0 : Disable TuneCode override */

  FTM_SET_TUNER_ENABLE_TUNE_CODE_OVERRIDE = 1, /*!< 1 :  Enable TuneCode override(stick to Tune code) */

  FTM_SET_TUNER_UPDATE_TUNE_CODE_ONCE = 2, /*!< 2 : Update TuneCode Once (Do not stick to TuneCode */

  FTM_SET_TUNER_TRIGGER_SCENARIO_OVERRIDE = 3, /*!< 3 : Scenario override */
  
  FTM_SET_TUNER_ENABLE_ACL = 4, /*!< 4 : Enable ACL*/
  
  FTM_SET_TUNER_DISABLE_ACL = 5, /*!< 4 : Disable ACL*/

  FTM_SET_TUNER_TUNE_CODE_UPDATE_TYPE_NUM  /*!< Max : Defines maximum number of tune code update types */

} ftm_rf_ant_tuner_tune_code_update_enum_type;

typedef enum
{
   _FTM_COMMON_SET_ANTENNA = 7
} FTM_Common_Command_ID_Type;

typedef enum
{
   FBRX_NV_MODE_0 = 0,
   FBRX_NV_MODE_1 = 1,
   FBRX_NV_MODE_2 = 2,
   FBRX_NV_MODE_3 = 3
} FBRX_NV_MODE;

typedef enum
{
   CALLBOX = 0,
   STG = 1
} RXRSB_SIGNAL_SOURCE;

const int DEFAULT_NV_CONTAINER_VALUE = 255;
const int MAX_NUM_PATH = 8;

typedef struct calnvgenparam
{
   unsigned short version;
   unsigned short nvcontainer[MAX_NUM_DEVICES][MAX_NUM_PATH];
   //read existing NV data from phone before modifying/adding
   bool readNVdatafromDUT;
} rxNVgenParam;

const unsigned short MAX_NUM_RX_CHANNELS = 16;
const unsigned short MAX_NUM_GAIN_STATES = 8;
//Structure to store Rx Gain offset data for each path
typedef struct RFNV_DATA_TYPE_RX_CAL_DATA_INFO_V1
{
   /*! NV Container Index */
   unsigned short containerindex;

   /*! Calibration Data Type( Single Carrier or Dual Carrier or 3C) */
   unsigned short caltype;

   /*! Array of Channels that has been calibrated */
   unsigned short achannels[MAX_NUM_RX_CHANNELS];

   /*! Two dimensional array; For each gain state g; 0 < g < MAX_NUM_GAIN_STATES , MAX_NUM_RX_CHANNELS offsets are stored */
   short gainvsfreq[MAX_NUM_GAIN_STATES][MAX_NUM_RX_CHANNELS];
} RFNV_DATA_TYPE_RX_CAL_DATA_INFO_V1;

typedef struct
{
   unsigned char nv_active;
   short sin_theta;
   short cos_theta;
   short gain_inv;
} RSB_DATA_PER_GAIN;

typedef struct
{
   /*! NV Container Index */
   unsigned short containerindex;
   unsigned char  rsb_type;
   unsigned short dl_channel;
   int offset_in_kHz;
   unsigned char  bw;
   RSB_DATA_PER_GAIN       rsb_data[MAX_NUM_GAIN_STATES];
} RFNV_DATA_TYPE_RxRSB_CAL_INFO_V3;

typedef struct
{
   unsigned short dataTypeHeader;
   unsigned char sig_path;
   unsigned char dev;
   unsigned char ant_swt;
} QMSL_RFNV_VARIANT_SUB_HEADER_V2;

typedef struct
{
   unsigned short datatypeheader;
   union
   {
      RFNV_DATA_TYPE_RX_CAL_DATA_INFO_V1 rxcaldata_v1;
      RFNV_DATA_TYPE_RxRSB_CAL_INFO_V3 rxcaldata_v3;
   } rxcaldata;
} RFNV_DATA_TYPE_RX_CAL_DATA;

typedef enum
{
   RFNV_DATA_TYPE_RX_CAL_OFFSET_V2 = QMSL_RFNV_DATA_TYPE_RX_CAL_OFFSET_V2,
   RFNV_DATA_TYPE_ID_LIN_TABLE_V4 = QMSL_RFNV_DATA_TYPE_ID_LIN_TABLE_V4_TXRSBLOFT,
   RFNV_DATA_TYPE_RxRSB_CAL = QMSL_RFNV_DATA_TYPE_RxRSB_CAL,
} RX_CAL_DATA_INFO_VERSION;

//Maximum Number of Cal Types each NV container can hold
const unsigned short MAX_NUM_TYPES_PER_RX_NV_CONTAINER = 8;

/*Total Size for Rx Cal data is equal to the product of
sizeof(RFNV_DATA_TYPE_RX_CAL_DATA) - Size of each Rx Cal Data struct
*/

const size_t RX_CAL_DATA_SIZE_MAX = sizeof(RFNV_DATA_TYPE_RX_CAL_DATA) * MAX_NUM_DEVICES * MAX_NUM_PATH * MAX_NUM_TYPES_PER_RX_NV_CONTAINER;
typedef struct
{
   QMSL_Variant_Marker_Type aVariantMarker;

   uint8 aPayload[RX_CAL_DATA_SIZE_MAX];
} QMSL_RFNV_RX_CAL_NV_Container;

typedef struct
{
   //!Rx Cal Data
   QMSL_RFNV_RX_CAL_NV_Container nvcontainer;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_RFNV_RX_CAL_NV;

typedef enum RFNV_RX_CAL_DATA_NV_TYPE
{
   /* WCDMA RX NV_TYPE use 1-5000*/
   RFNV_RX_CAL_DATA_NV_TYPE_START    = 0,
   RFNV_RX_CAL_DATA_NV_TYPE_WCDMA_SC = 1,
   RFNV_RX_CAL_DATA_NV_TYPE_WCDMA_DC = 2,
   RFNV_RX_CAL_DATA_NV_TYPE_WCDMA_3C = 3,

   /* LTE RX NV_TYPE use 5001-10000*/
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_START  = 5000,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_BW_1p4 = 5001,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_BW_3p5 = 5002,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_BW_5p0 = 5003,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_BW_10p0 = 5004,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_BW_15p0 = 5005,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_BW_20p0 = 5006,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_BW_40p0 = 5007,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_INTRA_BW_1p4 = 5008,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_INTRA_BW_3p5 = 5009,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_INTRA_BW_5p0 = 5010,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_INTRA_BW_10p0 = 5011,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_INTRA_BW_15p0 = 5012,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_INTRA_BW_20p0 = 5013,
   RFNV_RX_CAL_DATA_NV_TYPE_LTE_INTRA_BW_40p0 = 5014,

   /* C2K  RX NV_TYPE use 10001-15000*/
   RFNV_RX_CAL_DATA_NV_TYPE_CDMA_START  = 10000,
   RFNV_RX_CAL_NV_TYPE_CDMA_PM0 = 10001,
   RFNV_RX_CAL_NV_TYPE_CDMA_PM1 = 10002,
   RFNV_RX_CAL_NV_TYPE_CDMA_PM2 = 10003,

   /* TDS RX NV_TYPE use 15001-20000*/
   RFNV_RX_CAL_DATA_NV_TYPE_TDSCDMA_START  = 15000,
   RFNV_RX_CAL_DATA_NV_TYPE_TDSCDMA_LL     = 15001,
   RFNV_RX_CAL_DATA_NV_TYPE_TDSCDMA_HL     = 15002,

   RFNV_RX_CAL_DATA_NV_TYPE_TDSCDMA_MAX = 65535,
} RFNV_RX_CAL_DATA_NV_TYPE;

/* ==============  Data strcuture for Common CAL  ================ */
/*!

Contains items necessary to generate Common Cal Data.

*/
typedef struct
{
   QMSL_CDMA_Rx_DVGA_LNA_Cal_NV_Result rxCalNV;
   QMSL_CDMA_NVChannels_struct nvChannels;
   unsigned short devIndex;
} QMSL_COMMON_RFCAL_RX_NV;

typedef struct
{
   QMSL_RFCAL_ESC_HDET_NV_Params hdetNVMeas;
   QMSL_RFCAL_ESC_HDET_NV_Results hdetNVRes;
   QMSL_RFCAL_Tx_LimVsFreq_NV_Results limVsFreqNv;
   QMSL_RFCAL_ESC_Calibration_NV escCalNv;
   union
   {
      QMSL_COMMON_RFCAL_RX_NV rxNVLegacy[4];
      QMSL_RFNV_RX_CAL_NV rxNV;
   };
   unsigned short rxSize;
   byte rfMode;
} QMSL_COMMON_RFCAL_NV;

typedef cal_sweep_record* pointerToCalSweepRecords;
typedef struct
{
   unsigned short numberofRecords;
   pointerToCalSweepRecords records;
} qmsl_cal_data_records;

typedef struct qmsl_fbrx_gain_records_generation_control
{
   unsigned short fbrxmodeofOutputRecords;
   unsigned short fbrxModeofSourceRecords;
   double gainRatioindB;
} qmsl_fbrx_gain_records_generation_control;

typedef enum qmsl_fbrx_gain_records_generation_technique
{
   EXTRAPOLATE_USING_KNOWN_FBRX_MODE_DATA = 0,
   EXTRAPOLATE_USING_GAIN_RATIO = 1,
   GENERATION_TECHNIQUE_MAX = 65535,
} qmsl_fbrx_gain_records_generation_technique;

typedef struct qmsl_fbrx_gain_records_generation
{
   qmsl_fbrx_gain_records_generation_technique techniqueUsed;
   qmsl_fbrx_gain_records_generation_control controls;
} qmsl_fbrx_gain_records_generation;

typedef enum
{
   FTM_RF_TEST_RC_EC_DEV_GRANT_INTERIM = 0, /*!< 0 : Indicates RFM device allocation failure */

   FTM_RF_TEST_RC_EC_DEV_GRANT_CONFIRM = 1, /*!< 1 : Indicates RFM device allocation failure */

   FTM_RF_TEST_RC_EC_DEV_GRANT_RELEASE = 2, /*!< 2 : Indicates RFM device allocation failure */

   FTM_RF_TEST_RC_EC_NULL_PARAM = 3, /*!< 3 : Indicates NULL parameter */

   FTM_RF_TEST_RC_EC_PROP_INCOMPATIBLE = 4, /*!< 4 : Indicates incompatible property */

   FTM_RF_TEST_RC_EC_PROP_BAD_VAL = 5, /*!< 5 : Indicates Bad property value */

   FTM_RF_TEST_RC_EC_MALLOC_FAILURE = 6, /*!< 6 : Indicates malloc failure */

   FTM_RF_TEST_RC_EC_NULL_CB = 7, /*!< 7 : NULL Tech callback */

   FTM_RF_TEST_RC_EC_CORRUPTION = 8, /*!< 8 : Indicates generic corruption */

   FTM_RF_TEST_RC_EC_NUM  /*!< Max : Defines maximum number of error codes */
} ftm_rf_test_radio_config_error_code_enum_type;

typedef enum
{
   FTM_RF_TEST_RADIO_CFG_PROP_UNASSIGNED = 0, /*!< 0 : Unassigned property */

   FTM_RF_TEST_RADIO_CFG_PROP_RX_CARRIER = 1, /*!< 1 : Receiver Carrier Number */

   FTM_RF_TEST_RADIO_CFG_PROP_TX_CARRIER = 2, /*!< 2 : Transmit Carrier Number */

   FTM_RF_TEST_RADIO_CFG_PROP_RFM_DEVICE_PRI = 3, /*!< 3 : Primary RFM device */

   FTM_RF_TEST_RADIO_CFG_PROP_RFM_DEVICE_DIV = 4, /*!< 4 : Diversity RFM device */

   FTM_RF_TEST_RADIO_CFG_PROP_BAND = 5, /*!< 5 : Operating Tech Band */

   FTM_RF_TEST_RADIO_CFG_PROP_CHANNEL = 6, /*!< 6 : Operating Tech channel */

   FTM_RF_TEST_RADIO_CFG_PROP_BANDWIDTH = 7,  /*!< 7 : Radio Bandwidth */

   FTM_RF_TEST_RADIO_CFG_PROP_RX_MODE = 8, /*!< 8 : Rx Mode: Burst or Continous */

   FTM_RF_TEST_RADIO_CFG_PROP_SIG_PATH = 9, /*!< 9 : Signal Path for AT forward */

   FTM_RF_TEST_RADIO_CFG_PROP_ANT_PATH = 10, /*!< 10 : Antenna Path */

   FTM_RF_TEST_RADIO_CFG_PROP_FREQ_ADJ_PPB = 11, /*!< 11 : Frequency Adjust - User Adjust */

   FTM_RF_TEST_RADIO_CFG_PROP_FREQ_ADJ_CNTR_FREQ = 12, /*!< 12 : Frequency Adjust - Center Freq */

   FTM_RF_TEST_RADIO_CFG_PROP_FREQ_ADJ_ENBL_XO = 13, /*!< 13 : Frequency Adjust - Enable XO */

   FTM_RF_TEST_RADIO_CFG_PROP_FREQ_ADJ_TOTAL_ADJ = 14, /*!< 14 : Frequency Adjust - Total Adjust */

   FTM_RF_TEST_RADIO_CFG_PROP_NUM  /*!< Max : Defines maximum number of properties */
} ftm_rf_test_radio_config_property_type;

typedef enum
{
   FTM_TX_CONTROL_PROP_UNASSIGNED = 0, /*!< 0 : Unassigned property */

   FTM_TX_CONTROL_PROP_TX_CARRIER = 1, /*!< 1 : Receiver Carrier Number */

   FTM_TX_CONTROL_PROP_RFM_DEVICE = 2, /*!< 2 : RFM device for this measurement*/

   FTM_TX_CONTROL_PROP_TX_ACTION = 3, /*!< 3 : TX ACTION ENABLE/DISABLE */

   FTM_TX_CONTROL_PROP_TX_POWER = 4, /*!< 4 : Transimit Power */

   FTM_TX_CONTROL_PROP_RB_CONFIG = 5, /*!< 5 : LTE Start RB */

   FTM_TX_CONTROL_PROP_SIG_PATH = 6,  /*!< 6 : Signal Path for AT forward */

   FTM_TX_CONTROL_PROP_NUM_OF_RB = 7,  /*!< 7 : LTE Number of RBs */

   FTM_TX_CONTROL_PROP_TX_WAVEFORM = 8,  /*!< 8 : LTE & GSM Tx waveform */

   FTM_TX_CONTROL_PROP_NETWORK_SIGNAL = 9,  /*!< 9 : LTE Network signalling value */

   FTM_TX_CONTROL_PROP_TX_SLOT = 10,  /*!< 10 : GSM TX SLOT Number */

   FTM_TX_CONTROL_PROP_MODULATION_TYPE = 11,  /*!< 11 : LTE Modulation Type */

   FTM_TX_CONTROL_PROP_NUM  /*!< Max : Defines maximum number of properties */
} ftm_rf_test_tx_control_property_type;

typedef enum
{
   FTM_TRM_RRA_PROP_UNASSIGNED          = 0, /*!< Unassigned property */
   FTM_TRM_RRA_PROP_SUB_IDX            = 1, /*!< Subscription Index from ftm_rf_test_subscriber_enum_type */
   FTM_TRM_RRA_PROP_TECH             = 2, /*!< Tech from ftm_rf_technology_type values */
   FTM_TRM_RRA_PROP_BAND             = 3, /*!< Band from sys_band_class_e_type values */
   FTM_TRM_RRA_PROP_CHAN             = 4, /*!< Chan */
   FTM_TRM_RRA_PROP_BANDWIDTH         = 5, /*!< Bandwidth in Hz */
   FTM_TRM_RRA_PROP_RXTX             = 6, /*!< Indicates if request is for Rx or Tx path from ftm_rf_test_device_radio_trx_t*/
   FTM_TRM_RRA_PROP_CHAIN            = 7, /*!< Chain 0/1/2/3/n */
   FTM_TRM_RRA_PROP_CARRIER_IDX         = 8, /*!< Carrier Index 0/1/2/n */
   FTM_TRM_RRA_PROP_RESOURCE          = 9, /*!< Resource from ftm_trm_resource_type values */
   FTM_TRM_RRA_PROP_REASON            = 10, /*!< Resource Reason from ftm_trm_reason_type values */
   FTM_TRM_RRA_PROP_PATH_FUNCTIONALITY  = 11, /*!< Path Functionality from ftm_trm_path_functionality_type values */
   FTM_TRM_RRA_PROP_DEVICE            = 12, /*!< Device from rfm_device_enum_type values */
   FTM_TRM_RRA_PROP_SIGNAL_PATH         = 13,  /*!< Signal */
   FTM_TRM_RRA_PROP_ANT_PATH     = 14,  /*!< Antenna path */

   FTM_TRM_RRA_PROP_NUM   /*!< Max : Defines maximum number of properties */
} ftm_trm_rra_property_type;

typedef enum
{
   FTM_TRM_ARA_PROP_UNASSIGNED   = 0,  /*!< Unassigned property */
   FTM_TRM_ARA_PROP_CARRIER_IDX  = 1,  /*!< Carrier Index 0/1/2/n */
   FTM_TRM_ARA_PROP_BAND         = 2,  /*!< Band from sys_band_class_e_type values */
   FTM_TRM_ARA_PROP_RXTX         = 3,  /*!< Indicates if request is for Rx or Tx path from ftm_rf_test_device_radio_trx_t*/
   FTM_TRM_ARA_PROP_CHAIN        = 4,  /*!< Chain 0/1/2/3/n */
   FTM_TRM_ARA_PROP_DEVICE       = 5, /*!< Device from rfm_device_enum_type values */
   FTM_TRM_ARA_PROP_SIGNAL_PATH  = 6, /*!< Signal */
   FTM_TRM_ARA_PROP_ANTENNA_PATH = 7, /*!< Antenna Path */

   /* ADD MORE ITEMS ABOVE THIS LINE */
   FTM_TRM_ARA_PROP_NUM  /*!< Max : Defines maximum number of properties */
} ftm_trm_ara_property_type;

typedef enum
{
   FTM_MSIM_CONFIG_PROP_UNASSIGNED          = 0, /*!< Unassigned property */
   FTM_MSIM_CONFIG_PROP_SUBSCRIBER          = 1, /*!< Subscription Index from ftm_rf_test_subscriber_enum_type */
   FTM_MSIM_CONFIG_PROP_TECH                = 2, /*!< Tech from ftm_rf_technology_type values */
   FTM_MSIM_CONFIG_PROP_SCENARIO            = 3, /*!< RXTX or RX scenario */

   FTM_MSIM_CONFIG_PROP_NUM    /*!< Max : Defines maximum number of properties */
} ftm_msim_config_property_type;

typedef enum
{
   FTM_RF_TEST_MSIM_SCENARIO_RX          = 0, /* Rx  */
   FTM_RF_TEST_MSIM_SCENARIO_RX_TX       = 1, /*Rx Tx */
} ftm_msim_scenario_type;

typedef enum
{
   FTM_RF_TEST_EC_SUB_ALLOC  = 0, /*!< 0 : Indicates subscription allocation failure*/

   FTM_RF_TEST_EC_SUB_RELEASE  = 1, /*!< 1 : Indicates subscription release failure */

   FTM_RF_TEST_CMD_HANDLER_FAIL  = 2, /*!< 2 : Indicates command handlder failure */

   FTM_RF_TEST_EC_NULL_PARAM  = 3, /*!< 3 : Indicates NULL parameter*/

   FTM_RF_TEST_EC_RSP_CREATION  = 4, /*!<  4 : Failure during response creation*/

   FTM_RF_TEST_EC_BAD_CMD  = 5, /*!< 5 : Bad Command */

   FTM_RF_TEST_EC_BAD_CMD_HANDLER  = 6, /*!< 6 : Signal Path for AT forward */

   FTM_RF_TEST_EC_UMCOMPRESS_FAIL  = 7, /*!< 7 : Uncompress failure */

   FTM_RF_TEST_EC_MALLOC_FAILRE  = 8, /*!< 8 : Malloc failure */

   FTM_RF_TEST_EC_NUM  /*!< Max : Defines maximum number of properties */
} ftm_rf_test_error_code_enum_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the size of the reserved field in FTM test command packet.  */
typedef uint16 ftm_rf_test_command_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the size of the reserved field in FTM test command packet.  */
typedef uint32 ftm_rf_test_field_reserved_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the size of the version field in FTM test command packet.  */
typedef uint32 ftm_rf_test_field_version_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the size of the subscription field in FTM test command packet.  */
typedef uint32 ftm_rf_test_field_subscriber_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the size of the technology field in FTM test command packet.  */
typedef uint32 ftm_rf_test_field_technology_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the error code mask for response packet. Each bit indicates a type of error. */
typedef uint32 ftm_rf_test_field_error_code_mask_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the size of the property field in FTM test command packet.  */
typedef uint32 ftm_rf_test_field_property_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the size of the property value field in FTM test command packet.  */
typedef long long ftm_rf_test_field_property_val_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define carrier */
typedef uint32 ftm_rf_test_carrier_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Type definition to define the RxAGC Data type during Rx Measure.  */
typedef int16 ftm_rf_test_rx_measure_agc_type;

/*! Type definition to define the LNA Gain State type during Rx Measure.  */
typedef uint16 ftm_rf_test_rx_measure_lna_gain_state_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Defintion of property type and value in FTM test request comamnd */
typedef struct
{
   ftm_rf_test_field_property_type type;
   /*!< Defines the type of property defined by #ftm_rf_test_radio_config_property_type */

   ftm_rf_test_field_property_val_type value;
   /*!< Variable to hold the value for the given property */
} ftm_rf_test_property_data_type;

typedef struct
{
   /*! Number of properties*/
   unsigned long num_properties;
   /*! Defintion of property type and value in FTM RF Test request/response properties*/
   ftm_rf_test_property_data_type properties[256];

} ftm_rf_test_property_data;

typedef struct
{
   /*! Size of blob data in bytes*/
   unsigned long num_binary_data_bytes;
   /*! Holds the blob data*/
   byte *binary_data;

} ftm_rf_test_blob_data;

typedef struct
{
   /*! Number of properties*/
   unsigned long num_properties;
   /*! Defintion of property type and value in FTM Test IQ capture request packet per carrier*/
   ftm_rf_test_property_data_type *properties;
   /*! Number of IQ data*/
   unsigned long num_iq_data;
   /*! Holds the IQ data*/
   byte *iq_data;

} ftm_rf_test_iq_captures;

/*! Enumeration to indicate the type of subscribers */
typedef enum
{
   FTM_RF_TEST_SUBSCRIBER_0 = 0, /*!< 0 : First subscriber */

   FTM_RF_TEST_SUBSCRIBER_1 = 1, /*!< 1 : Second subscriber */

   FTM_RF_TEST_SUBSCRIBER_NUM  /*!< Max : Defines maximum number of subscriber IDs */
} ftm_rf_test_subscriber_enum_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Enumeration to indicate the type of properties for FTM Rx Measure Command.
  These enumeration are used to define the content of #ftm_rf_test_field_property_type in FTM test command packet */
typedef enum
{
   FTM_RF_MEASURE_PROP_UNASSIGNED = 0, /*!< 0 : Unassigned property */

   FTM_RX_MEASURE_PROP_RX_CARRIER = 1, /*!< 1 : Receiver Carrier Number */

   FTM_RX_MEASURE_PROP_RFM_DEVICE = 2, /*!< 2 : RFM device for this measurement*/

   FTM_RX_MEASURE_PROP_EXPECTED_AGC = 3, /*!< 3 : Expected AGC Value */

   FTM_RX_MEASURE_PROP_RX_AGC = 4, /*!< 4 : RxAGC value */

   FTM_RX_MEASURE_PROP_LNA_GAIN_STATE = 5, /*!< 5 : LNA Gain State */

   FTM_RX_MEASURE_PROP_SIG_PATH  = 6, /*!< 6 : Signal Path for AT forward */

   FTM_RX_MEASURE_PROP_RX_MODE  = 7, /*!< 7 : GSM Rx Mode: Burst or Continous */

   FTM_RX_MEASURE_PROP_RX_SLOT  = 8, /*!< 8 : GSM Rx Slot Number */

   FTM_RX_MEASURE_PROP_RX_NUM_BURSTS  = 9, /*!< 9 : GSM only, Number of bursts */

   FTM_RX_MEASURE_PROP_MEAS_SENSITIVITY  = 10, /*!< 10 : Measure Sensitivity */

   FTM_RX_MEASURE_PROP_MEAS_CTON  = 11, /*!< 11 : Measure CtoN */

   FTM_RX_MEASURE_PROP_MEAS_PEAK_FREQ = 12, /*!< 12 : Measure Peak Frequency */

   FTM_RX_MEASURE_PROP_NUM  /*!< Max : Defines maximum number of properties */

} ftm_rf_test_rx_measure_property_type;


/*! Enumeration to indicate the type of properties for FTM Rx Measure Command.
  These enumeration are used to define the content of #ftm_rf_test_field_property_type in FTM test command packet */
typedef enum
{
   RX_MEASURE_RSP_DEFAULT_CARRIER_PROP, /*!< 0 : Carrier property map */

   RX_MEASURE_RSP_DEFAULT_DEVICE_PROP, /*!< 1 : Device property map*/

   RX_MEASURE_RSP_DEFAULT_AGC_PROP, /*!< 2 : AGC property map*/

   RX_MEASURE_RSP_DEFAULT_LNA_GS_PROP, /*!< 1 : LNA Gain State property map */

   RX_MEASURE_RSP_DEFAULT_PROPERTY_NUM  /*!< Max : Defines maximum number of properties per measurement response*/

} ftm_rf_test_rx_measure_response_default_property_map_type;

/*! Enumeration to indicate the type of properties for FTM Tx Measure Command.
  These enumeration are used to define the content of #ftm_rf_test_field_property_type in FTM test command packet */
typedef enum
{
  FTM_TX_MEASURE_PROP_UNASSIGNED = 0, /*!< 0 : Unassigned property */

  FTM_TX_MEASURE_PROP_NUM_AVERAGES,  /*!< 1 : Number of averages */

  FTM_TX_MEASURE_PROP_TX_CARRIER,    /*!< 2 : Uplink Carrier */

  FTM_TX_MEASURE_PROP_TX_DEVICE,     /*!< 3 : Tx device */
    
  FTM_TX_MEASURE_PROP_MEAS_POWER,    /*!< 4 : Tx power measurement action */

  FTM_TX_MEASURE_PROP_MEAS_EVM,      /*!< 5 : EVM measurement action */

  FTM_TX_MEASURE_PROP_MEAS_ACLR,     /*!< 6 : ACLR measurement action */ 

  FTM_TX_MEASURE_PROP_MEAS_VSWR,     /*!< 7 : VSWR measurement action */

  FTM_TX_MEASURE_PROP_MEAS_REPORT_TX_IQ,    /*!< 8 : Request TX IQ data */

  FTM_TX_MEASURE_PROP_MEAS_REPORT_FBRX_IQ,    /*!< 9 : Request FBRx IQ data */

  FTM_TX_MEASURE_PROP_MEAS_SPEC_FLATNESS,    /*!< 10 : Spectrum Flatness measurement action */

  FTM_TX_MEASURE_PROP_POWER,    /*!< 11 : Measured Tx power in dBm10*/

  FTM_TX_MEASURE_PROP_EVM,    /*!< 12 : Measured EVM in %*100 units */

  FTM_TX_MEASURE_PROP_ACLR_UTRA1_POS,    /*!< 13 : Measured ACLR metric in dB100 */

  FTM_TX_MEASURE_PROP_ACLR_UTRA1_NEG,    /*!< 14 : Measured ACLR metric in dB100 */

  FTM_TX_MEASURE_PROP_ACLR_UTRA2_POS,    /*!< 15 : Measured ACLR metric in dB100 */

  FTM_TX_MEASURE_PROP_ACLR_UTRA2_NEG,    /*!< 16 : Measured ACLR metric in dB100 */

  FTM_TX_MEASURE_PROP_ACLR_EUTRA_POS,    /*!< 17 : Measured ACLR metric in dB100 */

  FTM_TX_MEASURE_PROP_ACLR_EUTRA_NEG,   /*!< 18 : Measured ACLR metric in dB100 */

  FTM_TX_MEASURE_PROP_VSWR_RATIO,    /*!< 19 : Measured VSWR ratio in dB10 */

  FTM_TX_MEASURE_PROP_VSWR_RETURN_LOSS,    /*!< 20 : Measured VSWR return loss in dB100 */

  FTM_TX_MEASURE_PROP_VSWR_S11_MAG,    /*!< 21 : Measured VSWR S11 gain in dB100 */

  FTM_TX_MEASURE_PROP_VSWR_S11_PHASE,    /*!< 22 : Measured VSWR S11 phase in degree100 */

  FTM_TX_MEASURE_PROP_VSWR_FWD_PWR,    /*!< 23 : Measured VSWR forward power in dB100 */
  
  FTM_TX_MEASURE_PROP_VSWR_REV_PWR,    /*!< 24 : Measured VSWR reverse power in dB100 */

  FTM_TX_MEASURE_PROP_SFL_R1,    /*!< 25 : Measured Range 1 peak to peak ripple in normal conditions ( dB100) */

  FTM_TX_MEASURE_PROP_SFL_R2,    /*!< 26 : Measured Range 2 peak to peak ripple in normal conditions ( dB100) */

  FTM_TX_MEASURE_PROP_SFL_R12,    /*!< 27 : Measured Range 1/2 peak to peak ripple in normal conditions ( dB100) */

  FTM_TX_MEASURE_PROP_SFL_R21,     /*!< 28 : Measured Range 2/1 peak to peak ripple in normal conditions ( dB100) */

  FTM_TX_MEASURE_PROP_SFL_R1_EXT,    /*!< 29 : Measured Range 1 peak to peak ripple in extreme conditions ( dB100) */

  FTM_TX_MEASURE_PROP_SFL_R2_EXT,    //*!< 30 : Measured Range 2 peak to peak ripple in extreme conditions ( dB100) */

  FTM_TX_MEASURE_PROP_SFL_R12_EXT,    /*!< 31 : Measured Range 1/2 peak to peak ripple in extreme conditions ( dB100) */

  FTM_TX_MEASURE_PROP_SFL_R21_EXT,     /*!< 32 : Measured Range 2/1 peak to peak ripple in extreme conditions ( dB100) */

  FTM_TX_MEASURE_RESERVED0,    /*!< 33 : Reserved for future use */

  FTM_TX_MEASURE_MEAS_TX_TOTAL, /*!< 34 :  Total power across all carriers measurement action*/

  FTM_TX_MEASURE_TOTAL_PWR,  /*!< 35 : Measured total power across all carriers in dBm10 */

  FTM_TX_MEASURE_DEBUG_DATA, /*!< 36  : debug data in blob property format */

  FTM_TX_MEASURE_RESERVED4,  /*!< 37 : Reserved for future use */

  FTM_TX_MEASURE_RESERVED5,  /*!< 38 : Reserved for future use */

  FTM_TX_MEASURE_RESERVED6,   /*!< 39 : Reserved for future use */

  FTM_TX_MEASURE_RESERVED1,   /*!< 40 : Reserved for future use */

  FTM_TX_MEASURE_RESERVED2,   /*!< 41 : Reserved for future use */

  FTM_TX_MEASURE_TECHNOLOGY,  /*!< 42 : Technology */

  FTM_TX_MEASURE_SUBSCRIBER   /*!< 43 : Indicates the subscription ID*/

} ftm_rf_test_tx_measure_response_default_property_map_type;


/*! Structure to hold input and output data for each RxAGC measurement. Techs
  may get a list of below structs and are expected to execute and fill each of
  them */
typedef struct
{
   boolean response_prop_mask[5]; //FTM_RX_MEASURE_PROP_NUM

   struct ftm_rf_test_rx_measure_in_t
   {
      rfm_device_enum_type device;
      /*!< Device required to be measured*/

      ftm_rf_test_carrier_type carrier;
      /*!< Carrier required to be measured*/

      ftm_rf_test_rx_measure_agc_type expected_agc;
      /*!< Expected RxAGC value for this measurement. Some technologies requires
        expected RxAGC value to determine LNA gain state. */

   } input;
   /*!< Input parameters. All params required to perform a Rx measurement goes
     here */

   struct ftm_rf_test_rx_measure_out_t
   {
      ftm_rf_test_rx_measure_agc_type rxagc;
      /*!< Measured RxAGC value, 16bits*/

      ftm_rf_test_rx_measure_lna_gain_state_type lna_gain_state;
      /*!< LNA gain state, 16 bits */

   } output;
   /*!< Output parameters. All results goes here */

} ftm_rf_test_rx_measure_unpacked_data_t;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Index type for response properties from measurement data. The order is fixed
  and should not be changed. Can only be expanded. All results must be converted
  to property type as part of reponse payload. So any new type of results should
  have a new index and rx_measurement_result_type will be expanded automatically
  */
typedef enum
{
   FTM_RF_TEST_RX_MEAS_RSP_INDEX_CARRIER = 0,
   FTM_RF_TEST_RX_MEAS_RSP_INDEX_DEVICE = 1,
   FTM_RF_TEST_RX_MEAS_RSP_INDEX_RXAGC_VALUE = 2,
   FTM_RF_TEST_RX_MEAS_RSP_INDEX_LNA_GAIN_STATE = 3,
   FTM_RF_TEST_RX_MEAS_RSP_NUM
} ftm_rf_test_rx_measure_rsp_index_type;

/*--------------------------------------------------------------------------------------------------------------------*/
/*! Response Data structure for each measurement. It packs N number of properties
  in to one structs for ease of impelemntation. The final payload will have a
  list of measure_result_types. IMPORTANT: This type should not be modified.
  Any new type of properties to be added should be added to
  ftm_rf_test_rx_measure_rsp_index_type. The result_type will be expanded
  automatically*/
typedef struct
{
   ftm_rf_test_field_error_code_mask_type error_code;
   /*!< Error code where each bit indicates an unique error defined by #ftm_rf_test_error_code_enum_type. Zero value
   indictaes, there was no error */

   uint32 number_of_properties;
   /*!< Number of Properties accumulated based on the measurement results. The ultimate reponse payload carries this
     number to inform tools the size of the list*/

   ftm_rf_test_property_data_type* result_prop_list;
   /*!< List of Response properties. The list begives at the address of result_properties and continues further*/

} ftm_rf_test_rx_measure_rsp_payload_type;

/************ END FTM-RF-TEST Support *********************/

/*! Enumeration to indicate the type device being requested */
typedef enum
{
   RFC_CONFIG_RX,
   RFC_CONFIG_TX,
   RFC_CONFIG_RXTX_MAX,
   RFC_CONFIG_RXTX_INVALID = RFC_CONFIG_RXTX_MAX,
} Device_Type;
/*! The status type for each tuner as sent back by the get_tune_code command */
typedef struct
{
   uint8 tuner_id; /* Index of tuner from which tune code is read */
   uint8 tune_code_size;  /* actual size of tune code*/
   uint8 tune_code[8]; /* 8 is the max size of tune code*/
   bool is_tuner_enabled;
} ftm_get_tune_code_status_type;

/*! Response type for FTM_GET_TUNE_CODE command */
typedef struct
{
   uint8 num_tuners;
   ftm_get_tune_code_status_type tune_code_status[5]; /*5 Tuners per chain */
} ftm_get_tune_code_response_type;



/*! Definition of Request Packet Structure for getting RF Path information  */
typedef struct
{
   uint8 technology; /*!< Technology information 0 - CDMA , 1 - WCDMA, 2 - GSM, 3 - LTE, 4 - TDSCDMA */

   uint16 band; /*!< Band Information. 0xFFFF will retrieve information for all bands in that technology*/

   uint8 subBand; /* Sub Band Information for Split Bands */

   uint8 actionType; /*!< Type of Path for which information is needed ; 0 = All Paths 1 = Calibrated Paths only  */
} RFPathInformationRequest;

/*! Definition of Version 0 of RF Path Information Packet */
typedef struct
{
   uint16 band; /*!< Band */
   uint8 subBand; /*!< Sub Band */
   uint32 signalPath; /*!< RF Front End Path */
   uint16 rfmDevice; /*!< WTR Path */
   uint16 antennaPath; /* Antenna Path  */
   uint16 reserved; /* for future use */
   uint32 associatedSignalPath; /*!< RF Front End Path */
   uint16 associatedRFMDevice; /*!< WTR Path */
   uint16 associatedantennaPath; /* Antenna Path  */
   uint16 associatedreserved; /* for future use */
   uint8 nvcontainer; /*!< NV Container Index */
   uint8 rfmPathType; /*!< Defines Type of RFM path ; 0 = PRx; 1 = DRx 2 = Tx */
   uint8 actionType; /*!< 0 = Characterization 1 = Calibration  */
} RFPathInformationPacketVersion0;

/* Response Packet Header */
typedef struct
{
   uint8 isLastPacket; /*!< Flag to check if more response packet are expected from phone */

   uint8 compressionStatus; /*!< Status of compression */

   uint8 errorStatus; /*!< Status of the response packet */
} RFPathInformationResponseHeader;

/* Response Packet Payload*/
#define MAX_NUM_BANDS 50

#define MAX_NUM_PACKETS (MAX_NUM_BANDS * MAX_NUM_RFM_PATHS)
typedef struct
{
   uint16 packetVersion; /*!< Version of response payload , initialized in the constructor of the class*/

   uint16 numberofPackets; /*!< Number of packets of the specified version returned */
   /*! Union of payloads */
   union
   {
      RFPathInformationPacketVersion0 version0; /*!< Version 0  of response packet */
   } packet[MAX_NUM_PACKETS];
} RFPathInformationResponsePayload;

/*! Definition of response packet payload  */
typedef struct
{
   RFPathInformationResponseHeader responseHeader; /*!< Response Header */

   RFPathInformationResponsePayload responsePayload; /*!< Response Payload */
} RFPathInformationResponse;

/* Enumeration of Error status*/
typedef enum
{
   FTM_RF_PATH_STATUS_NO_ERROR, /*!< No Error */
   FTM_RF_PATH_STATUS_INVALID_TECHNOLOGY, /*!< Invalid Technology */
   FTM_RF_PATH_STATUS_INVALID_BAND, /*!< Invalid Band */
   FTM_RF_PATH_STATUS_INVALID_PATH_TYPE, /*!< Invalid Path Type */
   FTM_RF_PATH_STATUS_NO_TABLE_INFORMATION,/*!< No Table Information */
   FTM_RF_PATH_STATUS_MEM_ALLOC_FAILED,/*!< Memory allocation failed */
   FTM_RF_PATH_STATUS_NULL_POINTER_RECEIVED, /*!< Null Pointer received */
   FTM_RF_PATH_STATUS_MAX_PACKET_EXCEEDED, /*!< Response packet size exceeded */
   FTM_RF_PATH_ERROR_STATUS_MAX             = 0xFF,
} RFPathInformationResponseErrorStatus;

typedef enum
{
   FTM_RF_PATH_INFORMATION_RESPONSE_VERSION0,
   FTM_RF_PATH_INFORMATION_RESPONSE_MAX_VERSION = 0xFF,
} RFPathInformationResponseVersion;

typedef enum
{
   FTM_PACKET_COMPRESSION_FAIL = 0,
   FTM_PACKET_COMPRESSION_SUCESS = 1,
   FTM_PACKET_COMPRESSION_STATUS_INVALID = 0xFF,
} ftmPacketCompressionStatus;

typedef struct
{
   unsigned long ftm_rf_tech; /*!< Technology information 0 - CDMA , 1 - WCDMA, 2 - GSM, 3- LTE, 4 - TDSCDMA */
   unsigned long subscriber;
   unsigned long queryAPIType;
   uint8 technology; /*!< Technology information 0 - CDMA , 1 - WCDMA, 2 - GSM, 10- LTE, 11 - TDSCDMA */
   uint16 band; /*!< Band Information. 0xFFFF will retrieve information for all bands in that technology*/
   uint8 subBand; /* Sub Band Information for Split Bands */
   unsigned long  ulchan;
   unsigned long  dlchan;
   unsigned long  bandwidth;
   uint8 actionType; /*!< Type of Path for which information is needed ; 0 = All Paths 1 = Calibrated Paths only  */
   bool isPRxOnly;
   bool isRxOnly;
   bool isLTEMIMO;
   int tx_dev;
   int tx_sigpath;
   int tx_antpath;
   int rx0_dev;
   int rx0_sigpath;
   int rx0_antpath;
   int rx1_dev;
   int rx1_sigpath;
   int rx1_antpath;
   int rx2_dev;
   int rx2_sigpath;
   int rx2_antpath;
   int rx3_dev;
   int rx3_sigpath;
   int rx3_antpath;
   bool freqAdj_apply;
   long freqAdj_ppb;
   long freqAdj_centerFrequency;
   bool freqAdj_enableXO;
   long freqAdj_totalAdjust;
} rf_path_assignment;

typedef struct
{
   /*!< Multi-Slot support - Only use these params if multiple slots need to be enabled (burst mode). */     
   unsigned long tx_slot;          /*!<Tx Slot Number. */    
   long tx_power_dBm10;            /*!< Desired Tx Power in dBm10. */ 
   unsigned long slot_tx_action;   /*!< Tx Action to perform for this command. Can be ON or OFF  */ 
   unsigned long slot_tx_waveform; /*!< TX waveform */
     
} ftm_rf_test_multi_slot_params;

typedef struct
{
   unsigned long ftm_rf_tech; /*!< Technology information 0 - CDMA , 1 - WCDMA, 2 - GSM, 3- LTE, 4 - TDSCDMA */
   unsigned long subscriber;
   unsigned long tx_carr;
   long tx_power_dBm10;
   long startRB;
   long numRB;
   unsigned long tx_waveform;
   unsigned long tx_action;
   unsigned long nw_signalling_value;
   unsigned long tx_slot;
   unsigned long tx_dev;
   unsigned long tx_sigpath;
   unsigned long mod_type;
   bool enable_multislot_control; //This is set to true if multiple slots need to be enabled . In continuous mode this is set to false .
   unsigned long num_slots; //Number of slots to be enabled
   ftm_rf_test_multi_slot_params multi_slot_params[8];
   
} tx_prop_values;

typedef struct
{
   unsigned long ftm_rf_tech; /*!< Technology information 0 - CDMA , 1 - WCDMA, 2 - GSM, 3- LTE, 4 - TDSCDMA */
   unsigned long subscriber;
   unsigned long rx_carr;
   unsigned long rx_dev;
   unsigned long rx_mode;
   unsigned long rx_slot;
   unsigned long rx_num_bursts;
   double exp_rxagc;
} rx_prop_values;

typedef struct
{
   short rx_agc;
   short rx_lna_state;
   unsigned long rx_peak_frequency;
   double rx_cton;
   double rx_estimated_sensitivity;
} rx_measurements;

typedef struct
{
   unsigned long ftm_rf_tech; /*!< Technology information 0 - CDMA , 1 - WCDMA, 2 - GSM, 3- LTE, 4 - TDSCDMA */
   unsigned long subscriber;
   unsigned long tx_carrier;
   unsigned long tx_device;
   unsigned long meas_pwr;
   unsigned long meas_evm;
   unsigned long meas_aclr;
   unsigned long meas_vswr;
   unsigned long req_tx_iq;
   unsigned long req_fbrx_iq;
   unsigned long meas_sfl;
   unsigned long meas_pwr_2;
   unsigned long num_of_averages;
} tx_meas_prop_values;

typedef struct
{
   double        tx_pwr;
   double        evm;
   double        aclr_utra1_pos;
   double        aclr_utra1_neg;
   double        aclr_utra2_pos;
   double        aclr_utra2_neg;
   double        aclr_eutra_pos;
   double        aclr_eutra_neg;
   double        vswr_ratio;
   double        vswr_return_loss;
   double        vswr_s11_mag;
   double        vswr_s11_phase;
   double        vswr_fwd_pwr;
   double        vswr_rev_pwr;
   double        spec_flat_r1;
   double        spec_flat_r2;
   double        spec_flat_r12;
   double        spec_flat_r21;
   double        spec_flat_r1_ext;
   double        spec_flat_r2_ext;
   double        spec_flat_r12_ext;
   double        spec_flat_r21_ext;
} selftest_tx_measurements;

typedef struct RFNV_GSM_RX_CAL_OFFSET_V1
{
   /*! NV Container Index */
   unsigned char containerindex;

   /*! RFM Device*/
   unsigned char RFMDevice;

   /*! Calibration Data Type( Regular Linearity and High Linearity ) */
   unsigned short caltype;

   /*! Number of Calibrated Channels */
   unsigned char numCalibratedChannels;

   /*! Array of Channels that has been calibrated */
   unsigned short achannels[MAX_NUM_RX_CHANNELS];

   /*! Two dimensional array; For each gain state g; 0 < g < MAX_NUM_GAIN_STATES , MAX_NUM_RX_CHANNELS offsets are stored */
   unsigned short gainvsfreq[MAX_NUM_GAIN_STATES][MAX_NUM_RX_CHANNELS];
} RFNV_GSM_RX_CAL_OFFSET_V1 ;

typedef struct RFNV_GSM_RX_CAL_OFFSET_V2
{
   /*! Calibration Data Type( Regular Linearity and High Linearity ) */
   unsigned short caltype;

   /*! Number of Calibrated Channels */
   unsigned char numCalibratedChannels;

   /*! Array of Channels that has been calibrated */
   unsigned short achannels[MAX_NUM_RX_CHANNELS];

   /*! Two dimensional array; For each gain state g; 0 < g < MAX_NUM_GAIN_STATES , MAX_NUM_RX_CHANNELS offsets are stored */
   unsigned short gainvsfreq[MAX_NUM_GAIN_STATES][MAX_NUM_RX_CHANNELS];
} RFNV_GSM_RX_CAL_OFFSET_V2 ;

const size_t RX_CAL_GSM_SIZE_MAX = (sizeof(QMSL_RFNV_VARIANT_SUB_HEADER_V2) + sizeof(unsigned int)+sizeof(RFNV_GSM_RX_CAL_OFFSET_V2)) * MAX_NUM_DEVICES * MAX_NUM_PATH * MAX_NUM_TYPES_PER_RX_NV_CONTAINER; // dataTypeHeader is unsigned int

typedef struct
{
   QMSL_Variant_Marker_Type aVariantMarker;


   uint8 aPayload[RX_CAL_GSM_SIZE_MAX];

} QMSL_RFNV_RX_CAL_GSM_NV_Container;

typedef struct
{
   //!Rx Cal Data
   QMSL_RFNV_RX_CAL_GSM_NV_Container nvcontainer;

   //! The actual NV item
   QMSL_RFCAL_NV_Item oNVitem;
} QMSL_RFNV_RX_CAL_GSM_NV;

typedef enum
{
   RFNV_GSM_TYPE_RX_CAL_OFFSET_V1 = QMSL_RFNV_GSM_TYPE_RX_CAL_OFFSET_V1,
   RFNV_GSM_TYPE_RX_CAL_HEAD_V2 = QMSL_RFNV_DATA_TYPE_VARIANT_SUB_HEADER_V2,
   RFNV_GSM_TYPE_RX_CAL_OFFSET_V2 = QMSL_RFNV_DATA_TYPE_GSM_RX_CAL_OFFSET_V2,


} RX_CAL_DATA_GSM_INFO_VERSION;

typedef struct
{
   unsigned short dev_tx;
   unsigned short dev_prx;
   unsigned short dev_drx;
   unsigned short dev_drx2;
   unsigned short dev_drx3;
   unsigned int   dev_data;
   unsigned short dev_info;
} ftm_set_lte_device_per_carrier_type;

typedef struct
{
   ftm_set_lte_device_per_carrier_type carrier[3]; /*PCC, SCC1, SCC2 */
} ftm_set_lte_devices_request_type;  //request command of LTE device alloc

typedef struct
{
   unsigned short type_id;

   unsigned char channel_index;
   /*! @brief Index identifying this channel record */
   unsigned char gain_state_index;
   /*! @brief Index identifying this fb_gain_state */
   unsigned char modulation_index;
   /*! @brief Modulation type. 0 for GMSK and 1 for 8PSK*/
   short fbrx_rms;
   /*! @brief fbrx raw value */
   short box_rms;
   /*! @brief power measured value */
} RFNV_DATA_GSM_FB_GAIN_TYPE;


typedef struct
{
   enum {GSM_FBRX_DATA_SIZE_MAX = FBRX_MAX_NUM_CAL_CHANNELS * FBRX_GAIN_STATE_MAX * FBRX_NUM_MODES_MAX * sizeof(RFNV_DATA_GSM_FB_GAIN_TYPE)};

   uint8 num_cal_channel;

   uint16 cal_channel_list[FBRX_MAX_NUM_CAL_CHANNELS];

   QMSL_Variant_Marker_Type aVariantMarker;

   uint8 aPayload[GSM_FBRX_DATA_SIZE_MAX];

} RFNV_DATA_GSM_FB_GAIN_NV;

typedef struct
{
   RFNV_DATA_GSM_FB_GAIN_NV NV_data;

   QMSL_RFCAL_NV_Item GSM_Fbrx_NV_Item;

} QMSL_RFNV_GSM_FBRX_GAIN_NV_Container;

typedef struct
{
   unsigned char instance;
   unsigned short mfg_id;
   unsigned short prd_id;
   unsigned char rev_id;
   unsigned char sw_rev;
   unsigned char rffe_bus_1;
   unsigned char rffe_usid_1;
   unsigned char rffe_bus_2;
   unsigned char rffe_usid_2;
   unsigned char dev_present_flag;
   unsigned char proff_id;
   unsigned char lut_file_found;
   unsigned char settings_path_found;
   unsigned char settings_file_found;
   unsigned char efs_swapped;
} FEM_Report;

#define MAX_NUM_FEM_DEVICES 30

typedef struct
{
   unsigned short hw_id;
   unsigned char rfc_init_status;
   unsigned char platform_id;
   unsigned char board_id;
   unsigned char num_devices;
   FEM_Report device_info[MAX_NUM_FEM_DEVICES];
} FEM_Report_Response;

#pragma pack()  // Restore default packeting

#endif // !defined(_QLIB_DEFINES)
