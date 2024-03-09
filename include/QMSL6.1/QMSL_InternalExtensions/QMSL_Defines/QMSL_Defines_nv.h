/******************************************************************************/
/**
Program: QMSL

   $Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief
   NV Definition

    In addition, this class provides functionality for common data manipulations.

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/
#pragma once
// $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Defines/QMSL_Defines_nv.h#10 $
// this file should hold items from nv_items.h of AMSS

#include "QMSL_inc\QLib_Defines.h"
#include "QMSL_Defines_basic_types.h"

#pragma pack(push, 1)
#define PACKED

/*=========================================================================*/
/* NVM Items Constant Definitions.                                         */
/*=========================================================================*/

/* Maximum of 109 speed dials */
#define  NV_MAX_SPEED_DIALS                                    109

/* With up to 12-letter names */
#define  NV_MAX_LTRS                                            12

/* Maximum 20 call stack numbers */
#define  NV_MAX_STACK_DIALS                                     20

/* Up to 2 NAMs allowed */
#define  NV_MAX_NAMS                                             2

/* PRL size is 4096 */
#define  NV_ROAMING_LIST_MAX_SIZE                             4096

/* Max SID+NID */
#define  NV_MAX_SID_NID                                          1

/* size of all tables based on temperature */
#define  NV_TEMP_TABLE_SIZ                                       8

/* Size of all tables based on Frequency */
#define  NV_FREQ_TABLE_SIZ                                      16

/* size of all tables based on power level */
#define  NV_PWR_TABLE_SIZ                                       16

/* Size of all tables based on battery voltage */
#define  NV_VOLT_TABLE_SIZ                                       8

/* For 2 IP address records */
#define  NV_IP_ADDRESS_TABLE_SIZE                                2

/* For 4 IP addresses per record */
#define  NV_IP_ADDRESSES_PER_ENTRY                               4

/* Max size of the UP cache */
#define  NV_UP_MAX_CACHE_SIZE                                    1

/* PN ID table size */
#define  NV_PN_ID_TABLE_SIZE                                  2048

/* 100 bytes for each of two items */
#define  NV_SI_TEST_DATA_SIZE                                  100

/* Max size of key field */
#define  NV_UP_MAX_KEY_SIZE                                     16

/* CDMA Tx linearizer master offset size */
#define  NV_CDMA_TX_LIN_MASTER_SIZ                              37
#define  NV_CDMA_TX_LIN_MASTER_BETA_SCALING_SIZ                 64

/* 6 digit security code */
#define  NV_SEC_CODE_SIZE                                        6

/* size of tables based on temperature in MSM6xxx */
#define  NV_TEMP_TABLE2_SIZ                                     16

/* Maximum 32 digit number */
#define  NV_MAX_DIAL_DIGITS                                     32

/* Max of 64 chars in User ID */
#define  NV_MAX_PAP_USER_ID_LENGTH                              64

/* Max of 14 chars in Password */
#define  NV_MAX_PAP_PASSWORD_LENGTH                             14

/* Max length of the PPP password */
#define  NV_MAX_PPP_PASSWORD_LENGTH                            127

/* Max length of the PPP user id */
#define  NV_MAX_PPP_USER_ID_LENGTH                             127

/* Maximum length of Security Services Device Key */
#define  NV_SEC_DEVICE_KEY_MAX_LEN                              32

/* Maximum 20 logs in error log */
#define  NV_MAX_ERR_LOG                                         20

/* 8 characters file name length */
#define  NV_ERR_FILE_NAME_LEN                                    8

/* number digits in FSC */
#define  NV_FSC_SIZ                                              6

/* With up to 5 letters wdc */
#define  NV_WDC_LTRS                                             5

/* Array size for factory info */
#define  NV_FACTORY_INFO_SIZ                                   100

/* Can peek at up to 32 bytes in one request */
#define  NV_MAX_PEEK_SIZE                                       32

/* Can poke at up to 32 bytes in one request */
#define  NV_MAX_POKE_SIZE                                       32

/* CDMA MIN index */
#define  NV_CDMA_MIN_INDEX                                       1

/* Analog MIN index */
#define  NV_ANALOG_MIN_INDEX                                     0

/* One time alarms for DOT */
#define  NV_MAX_ALARMS                                           6

/* Number entries in table */
#define  NV_DIAL_STATE_TABLE_MAX_SIZE                          125

/* Mode is inactive (neither analog nor CDMA) */
#define  NV_MODE_INACTIVE                                        0

/* Mode is analog */
#define  NV_MODE_ANALOG                                          1

/* Mode is CDMA */
#define  NV_MODE_CDMA                                            2

/* Normal Mute */
#define  NV_MUTE_NORM                                            0

/* Mute */
#define  NV_MUTE_MUTE                                            1

/* Mute Speaker */
#define  NV_MUTE_SPKR                                            2

/* For 2 link info table records */
#define  NV_UP_LINK_INFO_TABLE_SIZE                              2

/* Up to 6 SIDs to lock out */
#define  NV_MAX_SID_LOCK                                         6

/* Up to 6 SIDs to acquire */
#define  NV_MAX_SID_ACQ                                          6

/* Up to 2 MINs per NAM allowed */
#define  NV_MAX_MINS                                             2

/* Table consists of 12 words */
#define  NV_MRU_TABLE_SIZE                                      12

/* Up to 10 SID/NIDs to lock out */
#define  NV_MAX_SID_NID_LOCK                                    10

/* Up to 20 home SID/NID pairs */
#define  NV_MAX_HOME_SID_NID                                    20

/* num digits in dir_number */
#define  NV_DIR_NUMB_SIZ                                        10

/* num digits in dir_number_pcs */
#define  NV_DIR_NUMB_PCS_SIZ                                    15

/* Max of 35 table entries */
#define  NV_USER_ZONE_MAX_ENTRIES                               35

/* Max of 15 characters per entry */
#define  NV_USER_ZONE_ENTRY_LENGTH                              15

/* Table consists of 12 words */
#define  NV_MRU2_TABLE_SIZE                                     12

/* Buffer bytes to account for uneven bit in PRL system table */
#define  NV_RAM_PRL_BUF_BYTES                                    6

/* An always-invalid prl version number */
#define  NV_PRL_VERSION_INVALID                        0xFFFF


#define  NV_SIZE_OF_ROAMING_LIST_IN_UNION_TYPE                   1


#define  NV_SIZE_OF_RAM_ROAMING_LIST                   ( NV_ROAMING_LIST_MAX_SIZE + NV_RAM_PRL_BUF_BYTES )

/* Maximum Micro Broswer data size */
#define  NV_UBROWSER_ELEMENT_SIZE                               64

/* Micro Browser table size */
#define  NV_UBROWSER_TABLE_SIZE                                 32


#define  NV_DIAG_RESTART_CONFIG_LOGMASK_SIZE                    16

/* Max size of perm_store field */
#define  NV_UP_MAX_PERM_STORE_SIZE                              10

/* Max size of alert_name field */
#define  NV_UP_ALERT_NAME_SIZE                                  11

/* Number of alert records */
#define  NV_UP_MAX_ALERT_RECORDS                                 9

/* Maximum 16 digit number */
#define  NV_MAX_PKT_ORIG_DIGITS                                 16

/* Maximum of 6 Mobile IP user profiles are supported */
#define  NV_DS_MIP_MAX_NUM_PROF                                  6

/* Maximum length of User NAI field */
#define  NV_MAX_NAI_LENGTH                                      72

/* Maximum length of MN-HA shared secret */
#define  NV_MAX_MN_HA_SHARED_SECRET_LEN                         16

/* Maximum length of MN-AAA shared secret */
#define  NV_MAX_MN_AAA_SHARED_SECRET_LEN                        16

/* Maximum number of Mobile/Home Agent timebase offset */
#define  NV_NUM_DS_MIP_MN_HA_TIME_DELTA                          6

/* Maximum Length of a domain name */
#define  NV_DOMAIN_NAME_SIZE                                   100

/* Maximum length of APN name */
#define  NV_MAX_APN_STRING_LEN                                 128

/* Maximum length of a DS Packet Dial string */
#define  NV_PKT_DIAL_STRING_SIZE                                 5

/* Number of entries in the packet dial string lookup table */
#define  NV_PKT_DIAL_STRING_LIST_SIZE                            4

/* Maximum number of PPP devices */
#define  NV_PPP_MAX_DEV                                          3


#define  NV_HDRSCP_PRTL_SUBTYPE_SIZ                    0x1A


#define  NV_HDR_CURR_STREAM_CFG_SIZ                              4


#define  NV_UATI_LENGTH                                         16


#define  NV_RPC_AUTH_KEY_MAX_LEN                                20


#define  NV_MAX_AN_AUTH_NAI_LENGTH                              64


#define  NV_MAX_AN_AUTH_PASSWORD_LENGTH                         14


#define  NV_MAX_AN_PPP_PASSWORD_LENGTH                         127


#define  NV_MAX_AN_PPP_USER_ID_LENGTH                          127


#define  NV_MAX_AN_AUTH_PASSWD_LONG_LENGTH                     127


#define  NV_MAX_AN_AUTH_USER_ID_LONG_LENGTH                    127

/* Up to 64 */
#define  NV_FR_TEMP_OFFSET_TABLE_SIZ                            64

/* CDMA Rx linearizer offset size */
#define  NV_CDMA_RX_LIN_SIZ                                     16

/* CDMA expected HDET reading vs AGC PDM size */
#define  NV_CDMA_EXP_HDET_VS_AGC_SIZ                            16

/* CDMA HDET error slope vs HDET reading size */
#define  NV_CDMA_ERR_SLP_VS_HDET_SIZ                             8

/* Adj vs. Frequency size */
#define  NV_ADJ_VS_FREQ_SIZ                                     16

/* Adj vs. Temp size */
#define  NV_ADJ_VS_TEMP_SIZ                                      8

/* HDET ADC table size */
#define  NV_HDET_ADC_TABLE_SIZ                                   6

/* Up to 32 items */
#define  NV_FREQ_ADJ_TABLE_SIZ                                  32

/* Portables RF CDMA Compensation Table Size */
#define  NV_RIPPLE_COMP_TABLE_SIZ                               32

/* Portable RX offset Compensation Table Size */
#define  NV_RX_OFFSET_TABLE_SIZ                                 32

/* Portable RX Power Compensation Table Size */
#define  NV_RX_POWER_TABLE_SIZ                                 128

/* Portable RX Error Compensation Table Size */
#define  NV_RX_ERROR_TABLE_SIZ                                 128

/* Portable TX Slope 1 Compensation Table Size */
#define  NV_TX_SLOPE_1_TABLE_SIZ                               128

/* Portable TX Slope 2 Compensation Table Size */
#define  NV_TX_SLOPE_2_TABLE_SIZ                               128

/* Portable Tx Nonlinear Error Compensation Table Size */
#define  NV_TX_NON_LIN_ERR_TABLE_SIZ                           128

/* HDET table size */
#define  NV_HDET_TABLE_SIZ                                     128

/* PCS Rx linearizer offset size */
#define  NV_PCS_RX_LIN_SIZ                                      16

/* PCS Tx linearizer master offset size */
#define  NV_PCS_TX_LIN_MASTER_SIZ                               37

/* PCS expected HDET reading vs AGC PDM size */
#define  NV_PCS_EXP_HDET_VS_AGC_SIZ                             16

/* Number of PA ranges */
#define  NV_NUM_PA_RANGES                                        4

/* Number of Tx linearizers */
#define  NV_NUM_TX_LINEARIZERS                                   4

/* Maximum Switch to Analog values */
#define  NV_MAX_STA_VALUES                                       2

/* Table size of TX AGC backoff values */
#define  NV_TX_BACKOFF_TABLE_SIZE                               20

/* Three values, min, med, and max, of the PA backoff values */
#define  NV_NUM_PA_BCKOFF_CAL_VOLT                               3

/* WCDMA Rx linearizer offset table size */
#define  NV_WCDMA_RX_LIN_SIZ                                    17

/* WCDMA Tx linearizer master offset table size */
#define  NV_WCDMA_TX_LIN_MASTER_SIZ                             37

/* WCDMA expected HDET reading vs TX AGC table size */
#define  NV_WCDMA_EXP_HDET_VS_AGC_SIZ                           16

/* Number of WCDMA Tx linearizers */
#define  NV_WCDMA_NUM_TX_LINEARIZERS                             2

/* Length of a version number in bytes */
#define  NV_SIZE_OF_VERSION                                      8

/* 9 character QCOM serial number */
#define  NV_QC_SERIAL_NUM_LEN                                    9

/* Table size of VCO_COARSE_TUNE table */
#define  NV_VCO_COARSE_TUNE_TABLE_SIZ                           16

/* Max bytes in SMS data buffer */
#define  NV_SMS_DATA_SIZ                                       388

/* Max bytes in SMS DM data buffer */
#define  NV_SMS_DM_DATA_SIZ                                    100

/* Total size of header fields within nvi_sms_type (i.e. excluding data) */
#define  NV_SMS_HEADER_SIZE                                     14

/* Max services */
#define  NV_SMS_MAX_SERVICES                                    32

/* Max number of languages for SMS displayed */
#define  NV_SMS_MAX_LANGUAGES                                    4


#define  NV_SMS_BC_TABLE_SIZE                          ( NV_SMS_MAX_SERVICES * NV_SMS_MAX_LANGUAGES )

/* Total size of label fields within nv_sms_bc_service_table_type */
#define  NV_SMS_BC_SRV_LABEL_SIZE                               30

/* Max size of GSM/WCDMA SMS template */
#define  NV_SMS_GW_PARAMS_SIZE                                 127

/* Max number of GWM/WCDMA SMS routes */
#define  NV_SMS_MAX_ROUTES                                       6

/* Max bytes in SMS GW data buffer */
#define  NV_SMS_GW_DATA_SIZ                                    176

/* Max number of CDMA SMS template */
#define  NV_SMS_CD_PARMS_MAX_ENTRIES                            20

/* Max size of CDMA SMS template */
#define  NV_SMS_CD_PARMS_SIZE                                  126

/* Max table size for GSM/UMTS Cell Broadcast SMS Service table */
#define  NV_SMS_GW_CB_TABLE_SIZE                               200

/* Max storage address for dial type */
#define  MAX_STORAGE_ADDRESS                                    99

/* Up to 20 characters in a pager */
#define  NV_MAX_PAGE_CHARS                                      20

/* 4 digit lock code */
#define  NV_LOCK_CODE_SIZE                                       4

/* Bytes in passwd */
#define  NV_ISD_STD_PASSWD_SIZ                                   4

/* Ten entries in the table */
#define  NV_DIAL_RESTRICT_LVLS_SIZE                             10

/* Up to 12 characters of text allowed */
#define  NV_ROAM_MSG_MAX_SIZE                                   12

/* 12 bytes per table entry */
#define  NV_DIAL_STATE_TABLE_NEXT_STATES                        12

/* 100 bytes per entry */
#define  NV_CARRIER_INFO_ELEMENT_SIZE                          100

/* Max of 3 entries allowed */
#define  NV_CARRIER_INFO_MAX_ELEMENTS                            3

/* Maximum 20 page messages */
#define  NV_MAX_PAGE_MSGS                                       20

/* Up to 6 entries in the table */
#define  NV_ROAM_MSG_MAX_ENTRIES                                 6

/* Max length of multimedia ringer filename */
#define  NV_FS_FILENAME_MAX_LENGTH                              40

/* Number of bytes in an R-UIM CHV */
#define  NV_RUIM_CHV_SIZE                                        8

/* 6 bytes per addr */
#define  NV_BD_ADDR_SIZE                                         6

/* Number of ECC phone numbers can be used */
#define  NV_MAX_NUM_OF_ECC_NUMBER                               10

/* Number of digits in an ECC phone number */
#define  NV_ECC_NUMBER_SIZE                                      3

/* Size of a Public Land Mobile Network ID */
#define  NV_PLMN_ID_SIZE                                         3

/* Maximum length of the equivalent PLMN list */
#define  NV_EQUIVALENT_PLMN_LIST_MAX_SIZE                        5

/* This defines the NAM for the RUIM card */
#define  NV_RUIM_NAM                                             0

/* Size of RPLMN */
#define  NV_RPLMNACA_SIZE                                        2

/* Size of UE IMEI */
#define  NV_UE_IMEI_SIZE                                         9

/* Max acquisition database entries */
#define  MAX_ACQ_DB_ENTRIES                                     10

/* Max acquisition database entries */
#define  MAX_MCC_DIGITS                                          3

/* Max acquisition database entries */
#define  MAX_MNC_DIGITS                                          3


#define  NV_TX_BURST_RAMP_SIZ                                   30


#define  NV_NUM_GSM_PA_PROFILES                                 15


#define  NV_NUM_DCS_PA_PROFILES                                 16


#define  NV_GSM_CAL_ARFCN_SIZ                                    8


#define  NV_DCS_CAL_ARFCN_SIZ                                   16


#define  NV_MAX_NUMBER_OF_BEST_CELLS                             7


#define  NV_EXP_HDET_VS_AGC_SIZ                                 16


#define  NV_GSM_1900_CAL_ARFCN_SIZ                              16


#define  NV_GSM_850_CAL_ARFCN_SIZ                                8


#define  NV_BREW_BKEY_SIZ                                       16


#define  NV_BREW_SERVER_SIZ                                     64


#define  NV_BREW_SID_SIZ                                        32


#define	 NV_MAX_ANT_NO_SIZ										2


#define  NV_INTELLICEIVER_CAL_LENGTH							12


#define  NV_INTELLICEIVER_DETECTOR_COUNT							3

#define  NV_TX_PDM_LIN_TYPE                                     32
#define  NV_TX_PDM_LIN_BETA_SCALING_SIZE                        64

#define  NV_TX_LIN_MASTER_ENH_SIZE                              64

#define  NV_TX_PDM_LIN_ENH_SIZE                                 64

/*=========================================================================*/
/* Enumerators of items to access.                                         */
/*=========================================================================*/
typedef  word  nv_items_enum_type;

#define  NV_ESN_I                                      ((nv_items_enum_type) 0)// already in QLIB_Defines, not according to chitol
#define  NV_ESN_CHKSUM_I                               ((nv_items_enum_type) 1)
#define  NV_VERNO_MAJ_I                                ((nv_items_enum_type) 2)
#define  NV_VERNO_MIN_I                                ((nv_items_enum_type) 3)
#define  NV_SCM_I                                      ((nv_items_enum_type) 4)
#define  NV_SLOT_CYCLE_INDEX_I                         ((nv_items_enum_type) 5)
#define  NV_MOB_CAI_REV_I                              ((nv_items_enum_type) 6)
#define  NV_MOB_FIRM_REV_I                             ((nv_items_enum_type) 7)
#define  NV_MOB_MODEL_I                                ((nv_items_enum_type) 8)
#define  NV_CONFIG_CHKSUM_I                            ((nv_items_enum_type) 9)
#define  NV_PREF_MODE_I                                ((nv_items_enum_type) 10)
#define  NV_CDMA_PREF_SERV_I                           ((nv_items_enum_type) 11)
#define  NV_ANALOG_PREF_SERV_I                         ((nv_items_enum_type) 12)
#define  NV_CDMA_SID_LOCK_I                            ((nv_items_enum_type) 13)
#define  NV_CDMA_SID_ACQ_I                             ((nv_items_enum_type) 14)
#define  NV_ANALOG_SID_LOCK_I                          ((nv_items_enum_type) 15)
#define  NV_ANALOG_SID_ACQ_I                           ((nv_items_enum_type) 16)
#define  NV_ANALOG_FIRSTCHP_I                          ((nv_items_enum_type) 17)
#define  NV_ANALOG_HOME_SID_I                          ((nv_items_enum_type) 18)
#define  NV_ANALOG_REG_I                               ((nv_items_enum_type) 19)
#define  NV_PCDMACH_I                                  ((nv_items_enum_type) 20)
#define  NV_SCDMACH_I                                  ((nv_items_enum_type) 21)
#define  NV_PPCNCH_I                                   ((nv_items_enum_type) 22)
#define  NV_SPCNCH_I                                   ((nv_items_enum_type) 23)
#define  NV_NAM_CHKSUM_I                               ((nv_items_enum_type) 24)
#define  NV_A_KEY_I                                    ((nv_items_enum_type) 25)
#define  NV_A_KEY_CHKSUM_I                             ((nv_items_enum_type) 26)
#define  NV_SSD_A_I                                    ((nv_items_enum_type) 27)
#define  NV_SSD_A_CHKSUM_I                             ((nv_items_enum_type) 28)
#define  NV_SSD_B_I                                    ((nv_items_enum_type) 29)
#define  NV_SSD_B_CHKSUM_I                             ((nv_items_enum_type) 30)
#define  NV_COUNT_I                                    ((nv_items_enum_type) 31)
#define  NV_MIN1_I                                     ((nv_items_enum_type) 32)
#define  NV_MIN2_I                                     ((nv_items_enum_type) 33)
#define  NV_MOB_TERM_HOME_I                            ((nv_items_enum_type) 34)
#define  NV_MOB_TERM_FOR_SID_I                         ((nv_items_enum_type) 35)
#define  NV_MOB_TERM_FOR_NID_I                         ((nv_items_enum_type) 36)
#define  NV_ACCOLC_I                                   ((nv_items_enum_type) 37)
#define  NV_SID_NID_I                                  ((nv_items_enum_type) 38)
#define  NV_MIN_CHKSUM_I                               ((nv_items_enum_type) 39)
#define  NV_CURR_NAM_I                                 ((nv_items_enum_type) 40)
#define  NV_ORIG_MIN_I                                 ((nv_items_enum_type) 41)
#define  NV_AUTO_NAM_I                                 ((nv_items_enum_type) 42)
#define  NV_NAME_NAM_I                                 ((nv_items_enum_type) 43)
#define  NV_NXTREG_I                                   ((nv_items_enum_type) 44)
#define  NV_LSTSID_I                                   ((nv_items_enum_type) 45)
#define  NV_LOCAID_I                                   ((nv_items_enum_type) 46)
#define  NV_PUREG_I                                    ((nv_items_enum_type) 47)
#define  NV_ZONE_LIST_I                                ((nv_items_enum_type) 48)
#define  NV_SID_NID_LIST_I                             ((nv_items_enum_type) 49)
#define  NV_DIST_REG_I                                 ((nv_items_enum_type) 50)
#define  NV_LAST_CDMACH_I                              ((nv_items_enum_type) 51)
#define  NV_CALL_TIMER_I                               ((nv_items_enum_type) 52)
#define  NV_AIR_TIMER_I                                ((nv_items_enum_type) 53)
#define  NV_ROAM_TIMER_I                               ((nv_items_enum_type) 54)
#define  NV_LIFE_TIMER_I                               ((nv_items_enum_type) 55)
#define  NV_RUN_TIMER_I                                ((nv_items_enum_type) 56)
#define  NV_DIAL_I                                     ((nv_items_enum_type) 57)
#define  NV_STACK_I                                    ((nv_items_enum_type) 58)
#define  NV_STACK_IDX_I                                ((nv_items_enum_type) 59)
#define  NV_PAGE_SET_I                                 ((nv_items_enum_type) 60)
#define  NV_PAGE_MSG_I                                 ((nv_items_enum_type) 61)
#define  NV_EAR_LVL_I                                  ((nv_items_enum_type) 62)
#define  NV_SPEAKER_LVL_I                              ((nv_items_enum_type) 63)
#define  NV_RINGER_LVL_I                               ((nv_items_enum_type) 64)
#define  NV_BEEP_LVL_I                                 ((nv_items_enum_type) 65)
#define  NV_CALL_BEEP_I                                ((nv_items_enum_type) 66)
#define  NV_CONT_KEY_DTMF_I                            ((nv_items_enum_type) 67)
#define  NV_CONT_STR_DTMF_I                            ((nv_items_enum_type) 68)
#define  NV_SVC_AREA_ALERT_I                           ((nv_items_enum_type) 69)
#define  NV_CALL_FADE_ALERT_I                          ((nv_items_enum_type) 70)
#define  NV_BANNER_I                                   ((nv_items_enum_type) 71)
#define  NV_LCD_I                                      ((nv_items_enum_type) 72)
#define  NV_AUTO_POWER_I                               ((nv_items_enum_type) 73)
#define  NV_AUTO_ANSWER_I                              ((nv_items_enum_type) 74)
#define  NV_AUTO_REDIAL_I                              ((nv_items_enum_type) 75)
#define  NV_AUTO_HYPHEN_I                              ((nv_items_enum_type) 76)
#define  NV_BACK_LIGHT_I                               ((nv_items_enum_type) 77)
#define  NV_AUTO_MUTE_I                                ((nv_items_enum_type) 78)
#define  NV_MAINTRSN_I                                 ((nv_items_enum_type) 79)
#define  NV_LCKRSN_P_I                                 ((nv_items_enum_type) 80)
#define  NV_LOCK_I                                     ((nv_items_enum_type) 81)
#define  NV_LOCK_CODE_I                                ((nv_items_enum_type) 82)
#define  NV_AUTO_LOCK_I                                ((nv_items_enum_type) 83)
#define  NV_CALL_RSTRC_I                               ((nv_items_enum_type) 84)
#define  NV_SEC_CODE_I                                 ((nv_items_enum_type) 85)
#define  NV_HORN_ALERT_I                               ((nv_items_enum_type) 86)
#define  NV_ERR_LOG_I                                  ((nv_items_enum_type) 87)
#define  NV_UNIT_ID_I                                  ((nv_items_enum_type) 88)
#define  NV_FREQ_ADJ_I                                 ((nv_items_enum_type) 89)
#define  NV_VBATT_I                                    ((nv_items_enum_type) 90)
#define  NV_FM_TX_PWR_I                                ((nv_items_enum_type) 91)
#define  NV_FR_TEMP_OFFSET_I                           ((nv_items_enum_type) 92)
#define  NV_DM_IO_MODE_I                               ((nv_items_enum_type) 93)
#define  NV_CDMA_TX_LIMIT_I                            ((nv_items_enum_type) 94)
#define  NV_FM_RSSI_I                                  ((nv_items_enum_type) 95)
#define  NV_CDMA_RIPPLE_I                              ((nv_items_enum_type) 96)
#define  NV_CDMA_RX_OFFSET_I                           ((nv_items_enum_type) 97)
#define  NV_CDMA_RX_POWER_I                            ((nv_items_enum_type) 98)
#define  NV_CDMA_RX_ERROR_I                            ((nv_items_enum_type) 99)
#define  NV_CDMA_TX_SLOPE_1_I                          ((nv_items_enum_type) 100)
#define  NV_CDMA_TX_SLOPE_2_I                          ((nv_items_enum_type) 101)
#define  NV_CDMA_TX_ERROR_I                            ((nv_items_enum_type) 102)
#define  NV_PA_CURRENT_CTL_I                           ((nv_items_enum_type) 103)
#define  NV_SONY_ATTEN_1_I                             ((nv_items_enum_type) 104)
#define  NV_SONY_ATTEN_2_I                             ((nv_items_enum_type) 105)
#define  NV_VOC_GAIN_I                                 ((nv_items_enum_type) 106)
#define  NV_SPARE_1_I                                  ((nv_items_enum_type) 107)
#define  NV_SPARE_2_I                                  ((nv_items_enum_type) 108)
#define  NV_DATA_SRVC_STATE_I                          ((nv_items_enum_type) 109)
#define  NV_DATA_IO_MODE_I                             ((nv_items_enum_type) 110)
#define  NV_IDLE_DATA_TIMEOUT_I                        ((nv_items_enum_type) 111)
#define  NV_MAX_TX_ADJ_I                               ((nv_items_enum_type) 112)
#define  NV_INI_MUTE_I                                 ((nv_items_enum_type) 113)
#define  NV_FACTORY_INFO_I                             ((nv_items_enum_type) 114)
#define  NV_SONY_ATTEN_3_I                             ((nv_items_enum_type) 115)
#define  NV_SONY_ATTEN_4_I                             ((nv_items_enum_type) 116)
#define  NV_SONY_ATTEN_5_I                             ((nv_items_enum_type) 117)
#define  NV_DM_ADDR_I                                  ((nv_items_enum_type) 118)
#define  NV_CDMA_PN_MASK_I                             ((nv_items_enum_type) 119)
#define  NV_SEND_TIMEOUT_I                             ((nv_items_enum_type) 120)
#define  NV_FM_AGC_SET_VS_PWR_I                        ((nv_items_enum_type) 121)
#define  NV_FM_AGC_SET_VS_FREQ_I                       ((nv_items_enum_type) 122)
#define  NV_FM_AGC_SET_VS_TEMP_I                       ((nv_items_enum_type) 123)
#define  NV_FM_EXP_HDET_VS_PWR_I                       ((nv_items_enum_type) 124)
#define  NV_FM_ERR_SLP_VS_PWR_I                        ((nv_items_enum_type) 125)
#define  NV_FM_FREQ_SENSE_GAIN_I                       ((nv_items_enum_type) 126)
#define  NV_CDMA_RX_LIN_OFF_0_I                        ((nv_items_enum_type) 127)
#define  NV_CDMA_RX_LIN_SLP_I                          ((nv_items_enum_type) 128)
#define  NV_CDMA_RX_COMP_VS_FREQ_I                     ((nv_items_enum_type) 129)
#define  NV_CDMA_TX_COMP_VS_FREQ_I                     ((nv_items_enum_type) 130)
#define  NV_CDMA_TX_COMP_VS_VOLT_I                     ((nv_items_enum_type) 131)
#define  NV_CDMA_TX_LIN_MASTER_OFF_0_I                 ((nv_items_enum_type) 132)
#define  NV_CDMA_TX_LIN_MASTER_SLP_I                   ((nv_items_enum_type) 133)
#define  NV_CDMA_TX_LIN_VS_TEMP_I                      ((nv_items_enum_type) 134)
#define  NV_CDMA_TX_LIN_VS_VOLT_I                      ((nv_items_enum_type) 135)
#define  NV_CDMA_TX_LIM_VS_TEMP_I                      ((nv_items_enum_type) 136)
#define  NV_CDMA_TX_LIM_VS_VOLT_I                      ((nv_items_enum_type) 137)
#define  NV_CDMA_TX_LIM_VS_FREQ_I                      ((nv_items_enum_type) 138)
#define  NV_CDMA_EXP_HDET_VS_AGC_I                     ((nv_items_enum_type) 139)
#define  NV_CDMA_ERR_SLP_VS_HDET_I                     ((nv_items_enum_type) 140)
#define  NV_THERM_I                                    ((nv_items_enum_type) 141)
#define  NV_VBATT_PA_I                                 ((nv_items_enum_type) 142)
#define  NV_HDET_OFF_I                                 ((nv_items_enum_type) 143)
#define  NV_HDET_SPN_I                                 ((nv_items_enum_type) 144)
#define  NV_ONETOUCH_DIAL_I                            ((nv_items_enum_type) 145)
#define  NV_FM_AGC_ADJ_VS_FREQ_I                       ((nv_items_enum_type) 146)
#define  NV_FM_AGC_ADJ_VS_TEMP_I                       ((nv_items_enum_type) 147)
#define  NV_RF_CONFIG_I                                ((nv_items_enum_type) 148)
#define  NV_R1_RISE_I                                  ((nv_items_enum_type) 149)
#define  NV_R1_FALL_I                                  ((nv_items_enum_type) 150)
#define  NV_R2_RISE_I                                  ((nv_items_enum_type) 151)
#define  NV_R2_FALL_I                                  ((nv_items_enum_type) 152)
#define  NV_R3_RISE_I                                  ((nv_items_enum_type) 153)
#define  NV_R3_FALL_I                                  ((nv_items_enum_type) 154)
#define  NV_PA_RANGE_STEP_CAL_I                        ((nv_items_enum_type) 155)
#define  NV_LNA_RANGE_POL_I                            ((nv_items_enum_type) 156)
#define  NV_LNA_RANGE_RISE_I                           ((nv_items_enum_type) 157)
#define  NV_LNA_RANGE_FALL_I                           ((nv_items_enum_type) 158)
#define  NV_LNA_RANGE_OFFSET_I                         ((nv_items_enum_type) 159)
#define  NV_POWER_CYCLES_I                             ((nv_items_enum_type) 160)
#define  NV_ALERTS_LVL_I                               ((nv_items_enum_type) 161)
#define  NV_ALERTS_LVL_SHADOW_I                        ((nv_items_enum_type) 162)
#define  NV_RINGER_LVL_SHADOW_I                        ((nv_items_enum_type) 163)
#define  NV_BEEP_LVL_SHADOW_I                          ((nv_items_enum_type) 164)
#define  NV_EAR_LVL_SHADOW_I                           ((nv_items_enum_type) 165)
#define  NV_TIME_SHOW_I                                ((nv_items_enum_type) 166)
#define  NV_AIR_CNT_I                                  ((nv_items_enum_type) 168)
#define  NV_ROAM_CNT_I                                 ((nv_items_enum_type) 169)
#define  NV_LIFE_CNT_I                                 ((nv_items_enum_type) 170)
#define  NV_SEND_PIN_I                                 ((nv_items_enum_type) 171)
#define  NV_SMS_I                                      ((nv_items_enum_type) 174)
#define  NV_SMS_DM_I                                   ((nv_items_enum_type) 175)
#define  NV_IMSI_MCC_I                                 ((nv_items_enum_type) 176)
#define  NV_IMSI_11_12_I                               ((nv_items_enum_type) 177)
#define  NV_DIR_NUMBER_I                               ((nv_items_enum_type) 178)
#define  NV_VOICE_PRIV_I                               ((nv_items_enum_type) 179)
#define  NV_SPARE_B1_I                                 ((nv_items_enum_type) 180)
#define  NV_SPARE_B2_I                                 ((nv_items_enum_type) 181)
#define  NV_SPARE_W1_I                                 ((nv_items_enum_type) 182)
#define  NV_SPARE_W2_I                                 ((nv_items_enum_type) 183)
#define  NV_FSC_I                                      ((nv_items_enum_type) 184)
#define  NV_ALARMS_I                                   ((nv_items_enum_type) 185)
#define  NV_STANDING_ALARM_I                           ((nv_items_enum_type) 186)
#define  NV_ISD_STD_PASSWD_I                           ((nv_items_enum_type) 187)
#define  NV_ISD_STD_RESTRICT_I                         ((nv_items_enum_type) 188)
#define  NV_DIALING_PLAN_I                             ((nv_items_enum_type) 189)
#define  NV_FM_LNA_CTL_I                               ((nv_items_enum_type) 190)
#define  NV_LIFE_TIMER_G_I                             ((nv_items_enum_type) 191)
#define  NV_CALL_TIMER_G_I                             ((nv_items_enum_type) 192)
#define  NV_PWR_DWN_CNT_I                              ((nv_items_enum_type) 193)
#define  NV_FM_AGC_I                                   ((nv_items_enum_type) 194)
#define  NV_FSC2_I                                     ((nv_items_enum_type) 195)
#define  NV_FSC2_CHKSUM_I                              ((nv_items_enum_type) 196)
#define  NV_WDC_I                                      ((nv_items_enum_type) 197)
#define  NV_HW_CONFIG_I                                ((nv_items_enum_type) 198)
#define  NV_CDMA_RX_LIN_VS_TEMP_I                      ((nv_items_enum_type) 199)
#define  NV_CDMA_ADJ_FACTOR_I                          ((nv_items_enum_type) 200)
#define  NV_CDMA_TX_LIM_BOOSTER_OFF_I                  ((nv_items_enum_type) 201)
#define  NV_CDMA_RX_SLP_VS_TEMP_I                      ((nv_items_enum_type) 202)
#define  NV_CDMA_TX_SLP_VS_TEMP_I                      ((nv_items_enum_type) 203)
#define  NV_PA_RANGE_VS_TEMP_I                         ((nv_items_enum_type) 204)
#define  NV_LNA_SWITCH_VS_TEMP_I                       ((nv_items_enum_type) 205)
#define  NV_FM_EXP_HDET_VS_TEMP_I                      ((nv_items_enum_type) 206)
#define  NV_N1M_I                                      ((nv_items_enum_type) 207)
#define  NV_IMSI_I                                     ((nv_items_enum_type) 208)
#define  NV_IMSI_ADDR_NUM_I                            ((nv_items_enum_type) 209)
#define  NV_ASSIGNING_TMSI_ZONE_LEN_I                  ((nv_items_enum_type) 210)
#define  NV_ASSIGNING_TMSI_ZONE_I                      ((nv_items_enum_type) 211)
#define  NV_TMSI_CODE_I                                ((nv_items_enum_type) 212)
#define  NV_TMSI_EXP_I                                 ((nv_items_enum_type) 213)
#define  NV_HOME_PCS_FREQ_BLOCK_I                      ((nv_items_enum_type) 214)
#define  NV_DIR_NUMBER_PCS_I                           ((nv_items_enum_type) 215)
#define  NV_ROAMING_LIST_I                             ((nv_items_enum_type) 216)
#define  NV_MRU_TABLE_I                                ((nv_items_enum_type) 217)
#define  NV_REDIAL_I                                   ((nv_items_enum_type) 218)
#define  NV_OTKSL_I                                    ((nv_items_enum_type) 219)
#define  NV_TIMED_PREF_MODE_I                          ((nv_items_enum_type) 220)
#define  NV_RINGER_TYPE_I                              ((nv_items_enum_type) 221)
#define  NV_ANY_KEY_ANSWER_I                           ((nv_items_enum_type) 222)
#define  NV_BACK_LIGHT_HFK_I                           ((nv_items_enum_type) 223)
#define  NV_KEY_SOUND_I                                ((nv_items_enum_type) 225)
#define  NV_DIALS_SORTING_METHOD_I                     ((nv_items_enum_type) 226)
#define  NV_LANGUAGE_SELECTION_I                       ((nv_items_enum_type) 227)
#define  NV_MENU_FORMAT_I                              ((nv_items_enum_type) 228)
#define  NV_RINGER_SPKR_LVL_I                          ((nv_items_enum_type) 229)
#define  NV_BEEP_SPKR_LVL_I                            ((nv_items_enum_type) 230)
#define  NV_MRU2_TABLE_I                               ((nv_items_enum_type) 231)
#define  NV_VIBRATOR_I                                 ((nv_items_enum_type) 232)
#define  NV_FLIP_ANSWERS_I                             ((nv_items_enum_type) 233)
#define  NV_DIAL_RESTRICT_LVLS_I                       ((nv_items_enum_type) 234)
#define  NV_DIAL_STATE_TABLE_LEN_I                     ((nv_items_enum_type) 235)
#define  NV_DIAL_STATE_TABLE_I                         ((nv_items_enum_type) 236)
#define  NV_VOICE_PRIV_ALERT_I                         ((nv_items_enum_type) 237)
#define  NV_IP_ADDRESS_I                               ((nv_items_enum_type) 238)
#define  NV_CURR_GATEWAY_I                             ((nv_items_enum_type) 239)
#define  NV_DATA_QNC_ENABLED_I                         ((nv_items_enum_type) 240)
#define  NV_DATA_SO_SET_I                              ((nv_items_enum_type) 241)
#define  NV_UP_LINK_INFO_I                             ((nv_items_enum_type) 242)
#define  NV_UP_PARMS_I                                 ((nv_items_enum_type) 243)
#define  NV_ELAPSED_TIME_I                             ((nv_items_enum_type) 245)
#define  NV_PDM2_I                                     ((nv_items_enum_type) 246)
#define  NV_RX_AGC_MINMAX_I                            ((nv_items_enum_type) 247)
#define  NV_VBATT_AUX_I                                ((nv_items_enum_type) 248)
#define  NV_DTACO_CONTROL_I                            ((nv_items_enum_type) 249)
#define  NV_DTACO_INTERDIGIT_TIMEOUT_I                 ((nv_items_enum_type) 250)
#define  NV_PDM1_I                                     ((nv_items_enum_type) 251)
#define  NV_BELL_MODEM_I                               ((nv_items_enum_type) 252)
#define  NV_PDM1_VS_TEMP_I                             ((nv_items_enum_type) 253)
#define  NV_PDM2_VS_TEMP_I                             ((nv_items_enum_type) 254)
#define  NV_SID_NID_LOCK_I                             ((nv_items_enum_type) 255)
#define  NV_PRL_ENABLED_I                              ((nv_items_enum_type) 256)
#define  NV_ROAMING_LIST_683_I                         ((nv_items_enum_type) 257)
#define  NV_SYSTEM_PREF_I                              ((nv_items_enum_type) 258)
#define  NV_HOME_SID_NID_I                             ((nv_items_enum_type) 259)
#define  NV_OTAPA_ENABLED_I                            ((nv_items_enum_type) 260)
#define  NV_NAM_LOCK_I                                 ((nv_items_enum_type) 261)
#define  NV_IMSI_T_S1_I                                ((nv_items_enum_type) 262)
#define  NV_IMSI_T_S2_I                                ((nv_items_enum_type) 263)
#define  NV_IMSI_T_MCC_I                               ((nv_items_enum_type) 264)
#define  NV_IMSI_T_11_12_I                             ((nv_items_enum_type) 265)
#define  NV_IMSI_T_ADDR_NUM_I                          ((nv_items_enum_type) 266)
#define  NV_UP_ALERTS_I                                ((nv_items_enum_type) 267)
#define  NV_UP_IDLE_TIMER_I                            ((nv_items_enum_type) 268)
#define  NV_SMS_UTC_I                                  ((nv_items_enum_type) 269)
#define  NV_ROAM_RINGER_I                              ((nv_items_enum_type) 270)
#define  NV_RENTAL_TIMER_I                             ((nv_items_enum_type) 271)
#define  NV_RENTAL_TIMER_INC_I                         ((nv_items_enum_type) 272)
#define  NV_RENTAL_CNT_I                               ((nv_items_enum_type) 273)
#define  NV_RENTAL_TIMER_ENABLED_I                     ((nv_items_enum_type) 274)
#define  NV_FULL_SYSTEM_PREF_I                         ((nv_items_enum_type) 275)
#define  NV_BORSCHT_RINGER_FREQ_I                      ((nv_items_enum_type) 276)
#define  NV_PAYPHONE_ENABLE_I                          ((nv_items_enum_type) 277)
#define  NV_DSP_ANSWER_DET_ENABLE_I                    ((nv_items_enum_type) 278)
#define  NV_EVRC_PRI_I                                 ((nv_items_enum_type) 279)
#define  NV_AFAX_CLASS_20_I                            ((nv_items_enum_type) 280)
#define  NV_V52_CONTROL_I                              ((nv_items_enum_type) 281)
#define  NV_CARRIER_INFO_I                             ((nv_items_enum_type) 282)
#define  NV_AFAX_I                                     ((nv_items_enum_type) 283)
#define  NV_SIO_PWRDWN_I                               ((nv_items_enum_type) 284)
#define  NV_PREF_VOICE_SO_I                            ((nv_items_enum_type) 285)
#define  NV_VRHFK_ENABLED_I                            ((nv_items_enum_type) 286)
#define  NV_VRHFK_VOICE_ANSWER_I                       ((nv_items_enum_type) 287)
#define  NV_PDM1_VS_FREQ_I                             ((nv_items_enum_type) 288)
#define  NV_PDM2_VS_FREQ_I                             ((nv_items_enum_type) 289)
#define  NV_SMS_AUTO_DELETE_I                          ((nv_items_enum_type) 290)
#define  NV_SRDA_ENABLED_I                             ((nv_items_enum_type) 291)
#define  NV_OUTPUT_UI_KEYS_I                           ((nv_items_enum_type) 292)
#define  NV_POL_REV_TIMEOUT_I                          ((nv_items_enum_type) 293)
#define  NV_SI_TEST_DATA_1_I                           ((nv_items_enum_type) 294)
#define  NV_SI_TEST_DATA_2_I                           ((nv_items_enum_type) 295)
#define  NV_SPC_CHANGE_ENABLED_I                       ((nv_items_enum_type) 296)
#define  NV_DATA_MDR_MODE_I                            ((nv_items_enum_type) 297)
#define  NV_DATA_PKT_ORIG_STR_I                        ((nv_items_enum_type) 298)
#define  NV_UP_KEY_I                                   ((nv_items_enum_type) 299)
#define  NV_DATA_AUTO_PACKET_DETECTION_I               ((nv_items_enum_type) 300)
#define  NV_AUTO_VOLUME_ENABLED_I                      ((nv_items_enum_type) 301)
#define  NV_WILDCARD_SID_I                             ((nv_items_enum_type) 302)
#define  NV_ROAM_MSG_I                                 ((nv_items_enum_type) 303)
#define  NV_OTKSL_FLAG_I                               ((nv_items_enum_type) 304)
#define  NV_BROWSER_TYPE_I                             ((nv_items_enum_type) 305)
#define  NV_SMS_REMINDER_TONE_I                        ((nv_items_enum_type) 306)
#define  NV_UBROWSER_I                                 ((nv_items_enum_type) 307)
#define  NV_BTF_ADJUST_I                               ((nv_items_enum_type) 308)
#define  NV_FULL_PREF_MODE_I                           ((nv_items_enum_type) 309)
#define  NV_UP_BROWSER_WARN_I                          ((nv_items_enum_type) 310)
#define  NV_FM_HDET_ADC_RANGE_I                        ((nv_items_enum_type) 311)
#define  NV_CDMA_HDET_ADC_RANGE_I                      ((nv_items_enum_type) 312)
#define  NV_PN_ID_I                                    ((nv_items_enum_type) 313)
#define  NV_USER_ZONE_ENABLED_I                        ((nv_items_enum_type) 314)
#define  NV_USER_ZONE_I                                ((nv_items_enum_type) 315)
#define  NV_PAP_DATA_I                                 ((nv_items_enum_type) 316)
#define  NV_DATA_DEFAULT_PROFILE_I                     ((nv_items_enum_type) 317)
#define  NV_PAP_USER_ID_I                              ((nv_items_enum_type) 318)
#define  NV_PAP_PASSWORD_I                             ((nv_items_enum_type) 319)
#define  NV_STA_TBYE_I                                 ((nv_items_enum_type) 320)
#define  NV_STA_MIN_THR_I                              ((nv_items_enum_type) 321)
#define  NV_STA_MIN_RX_I                               ((nv_items_enum_type) 322)
#define  NV_STA_MIN_ECIO_I                             ((nv_items_enum_type) 323)
#define  NV_STA_PRI_I                                  ((nv_items_enum_type) 324)
#define  NV_PCS_RX_LIN_OFF_0_I                         ((nv_items_enum_type) 325)
#define  NV_PCS_RX_LIN_SLP_I                           ((nv_items_enum_type) 326)
#define  NV_PCS_RX_COMP_VS_FREQ_I                      ((nv_items_enum_type) 327)
#define  NV_PCS_TX_COMP_VS_FREQ_I                      ((nv_items_enum_type) 328)
#define  NV_PCS_TX_LIN_MASTER_OFF_0_I                  ((nv_items_enum_type) 329)
#define  NV_PCS_TX_LIN_MASTER_SLP_I                    ((nv_items_enum_type) 330)
#define  NV_PCS_TX_LIN_VS_TEMP_I                       ((nv_items_enum_type) 331)
#define  NV_PCS_TX_LIM_VS_TEMP_I                       ((nv_items_enum_type) 332)
#define  NV_PCS_TX_LIM_VS_FREQ_I                       ((nv_items_enum_type) 333)
#define  NV_PCS_EXP_HDET_VS_AGC_I                      ((nv_items_enum_type) 334)
#define  NV_PCS_HDET_OFF_I                             ((nv_items_enum_type) 335)
#define  NV_PCS_HDET_SPN_I                             ((nv_items_enum_type) 336)
#define  NV_PCS_R1_RISE_I                              ((nv_items_enum_type) 337)
#define  NV_PCS_R1_FALL_I                              ((nv_items_enum_type) 338)
#define  NV_PCS_R2_RISE_I                              ((nv_items_enum_type) 339)
#define  NV_PCS_R2_FALL_I                              ((nv_items_enum_type) 340)
#define  NV_PCS_R3_RISE_I                              ((nv_items_enum_type) 341)
#define  NV_PCS_R3_FALL_I                              ((nv_items_enum_type) 342)
#define  NV_PCS_PA_RANGE_STEP_CAL_I                    ((nv_items_enum_type) 343)
#define  NV_PCS_PDM1_VS_FREQ_I                         ((nv_items_enum_type) 344)
#define  NV_PCS_PDM2_VS_FREQ_I                         ((nv_items_enum_type) 345)
#define  NV_PCS_LNA_RANGE_POL_I                        ((nv_items_enum_type) 346)
#define  NV_PCS_LNA_RANGE_RISE_I                       ((nv_items_enum_type) 347)
#define  NV_PCS_LNA_RANGE_FALL_I                       ((nv_items_enum_type) 348)
#define  NV_PCS_LNA_RANGE_OFFSET_I                     ((nv_items_enum_type) 349)
#define  NV_PCS_RX_LIN_VS_TEMP_I                       ((nv_items_enum_type) 350)
#define  NV_PCS_ADJ_FACTOR_I                           ((nv_items_enum_type) 351)
#define  NV_PCS_PA_RANGE_VS_TEMP_I                     ((nv_items_enum_type) 352)
#define  NV_PCS_PDM1_VS_TEMP_I                         ((nv_items_enum_type) 353)
#define  NV_PCS_PDM2_VS_TEMP_I                         ((nv_items_enum_type) 354)
#define  NV_PCS_RX_SLP_VS_TEMP_I                       ((nv_items_enum_type) 355)
#define  NV_PCS_TX_SLP_VS_TEMP_I                       ((nv_items_enum_type) 356)
#define  NV_PCS_RX_AGC_MINMAX_I                        ((nv_items_enum_type) 357)
#define  NV_PA_OFFSETS_I                               ((nv_items_enum_type) 358)
#define  NV_CDMA_TX_LIN_MASTER0_I                      ((nv_items_enum_type) 367)
#define  NV_CDMA_TX_LIN_MASTER1_I                      ((nv_items_enum_type) 368)
#define  NV_CDMA_TX_LIN_MASTER2_I                      ((nv_items_enum_type) 369)
#define  NV_CDMA_TX_LIN_MASTER3_I                      ((nv_items_enum_type) 370)
#define  NV_TIME_FMT_SELECTION_I                       ((nv_items_enum_type) 371)
#define  NV_SMS_BC_SERVICE_TABLE_SIZE_I                ((nv_items_enum_type) 372)
#define  NV_SMS_BC_SERVICE_TABLE_I                     ((nv_items_enum_type) 373)
#define  NV_SMS_BC_CONFIG_I                            ((nv_items_enum_type) 374)
#define  NV_SMS_BC_USER_PREF_I                         ((nv_items_enum_type) 375)
#define  NV_LNA_RANGE_2_RISE_I                         ((nv_items_enum_type) 376)
#define  NV_LNA_RANGE_2_FALL_I                         ((nv_items_enum_type) 377)
#define  NV_LNA_RANGE_12_OFFSET_I                      ((nv_items_enum_type) 378)
#define  NV_NONBYPASS_TIMER_I                          ((nv_items_enum_type) 379)
#define  NV_BYPASS_TIMER_I                             ((nv_items_enum_type) 380)
#define  NV_IM_LEVEL1_I                                ((nv_items_enum_type) 381)
#define  NV_IM_LEVEL2_I                                ((nv_items_enum_type) 382)
#define  NV_CDMA_LNA_OFFSET_VS_FREQ_I                  ((nv_items_enum_type) 383)
#define  NV_CDMA_LNA_12_OFFSET_VS_FREQ_I               ((nv_items_enum_type) 384)
#define  NV_AGC_PHASE_OFFSET_I                         ((nv_items_enum_type) 385)
#define  NV_RX_AGC_MIN_11_I                            ((nv_items_enum_type) 386)
#define  NV_PCS_LNA_RANGE_2_RISE_I                     ((nv_items_enum_type) 387)
#define  NV_PCS_LNA_RANGE_2_FALL_I                     ((nv_items_enum_type) 388)
#define  NV_PCS_LNA_RANGE_12_OFFSET_I                  ((nv_items_enum_type) 389)
#define  NV_PCS_NONBYPASS_TIMER_I                      ((nv_items_enum_type) 390)
#define  NV_PCS_BYPASS_TIMER_I                         ((nv_items_enum_type) 391)
#define  NV_PCS_IM_LEVEL1_I                            ((nv_items_enum_type) 392)
#define  NV_PCS_IM_LEVEL2_I                            ((nv_items_enum_type) 393)
#define  NV_PCS_CDMA_LNA_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 394)
#define  NV_PCS_CDMA_LNA_12_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 395)
#define  NV_PCS_AGC_PHASE_OFFSET_I                     ((nv_items_enum_type) 396)
#define  NV_PCS_RX_AGC_MIN_11_I                        ((nv_items_enum_type) 397)
#define  NV_RUIM_CHV_1_I                               ((nv_items_enum_type) 398)
#define  NV_RUIM_CHV_2_I                               ((nv_items_enum_type) 399)
#define  NV_GPS1_CAPABILITIES_I                        ((nv_items_enum_type) 400)
#define  NV_GPS1_PDE_ADDRESS_I                         ((nv_items_enum_type) 401)
#define  NV_GPS1_ALLOWED_I                             ((nv_items_enum_type) 402)
#define  NV_GPS1_PDE_TRANSPORT_I                       ((nv_items_enum_type) 403)
#define  NV_GPS1_MOBILE_CALC_I                         ((nv_items_enum_type) 404)
#define  NV_PREF_FOR_RC_I                              ((nv_items_enum_type) 405)
#define  NV_DS_DEFAULT_BAUD_I                          ((nv_items_enum_type) 406)
#define  NV_DIAG_DEFAULT_BAUD_I                        ((nv_items_enum_type) 407)
#define  NV_SIO_DEV_MAP_MENU_ITEM_I                    ((nv_items_enum_type) 408)
#define  NV_TTY_I                                      ((nv_items_enum_type) 409)
#define  NV_PA_RANGE_OFFSETS_I                         ((nv_items_enum_type) 410)
#define  NV_TX_COMP0_I                                 ((nv_items_enum_type) 411)
#define  NV_MM_SDAC_LVL_I                              ((nv_items_enum_type) 412)
#define  NV_BEEP_SDAC_LVL_I                            ((nv_items_enum_type) 413)
#define  NV_SDAC_LVL_I                                 ((nv_items_enum_type) 414)
#define  NV_MM_LVL_I                                   ((nv_items_enum_type) 415)
#define  NV_MM_LVL_SHADOW_I                            ((nv_items_enum_type) 416)
#define  NV_MM_SPEAKER_LVL_I                           ((nv_items_enum_type) 417)
#define  NV_MM_PLAY_MODE_I                             ((nv_items_enum_type) 418)
#define  NV_MM_REPEAT_MODE_I                           ((nv_items_enum_type) 419)
#define  NV_TX_COMP1_I                                 ((nv_items_enum_type) 420)
#define  NV_TX_COMP2_I                                 ((nv_items_enum_type) 421)
#define  NV_TX_COMP3_I                                 ((nv_items_enum_type) 422)
#define  NV_PRIMARY_DNS_I                              ((nv_items_enum_type) 423)
#define  NV_SECONDARY_DNS_I                            ((nv_items_enum_type) 424)
#define  NV_DIAG_PORT_SELECT_I                         ((nv_items_enum_type) 425)
#define  NV_GPS1_PDE_PORT_I                            ((nv_items_enum_type) 426)
#define  NV_MM_RINGER_FILE_I                           ((nv_items_enum_type) 427)
#define  NV_MM_STORAGE_DEVICE_I                        ((nv_items_enum_type) 428)
#define  NV_DATA_SCRM_ENABLED_I                        ((nv_items_enum_type) 429)
#define  NV_RUIM_SMS_STATUS_I                          ((nv_items_enum_type) 430)
#define  NV_PCS_TX_LIN_MASTER0_I                       ((nv_items_enum_type) 431)
#define  NV_PCS_TX_LIN_MASTER1_I                       ((nv_items_enum_type) 432)
#define  NV_PCS_TX_LIN_MASTER2_I                       ((nv_items_enum_type) 433)
#define  NV_PCS_TX_LIN_MASTER3_I                       ((nv_items_enum_type) 434)
#define  NV_PCS_PA_RANGE_OFFSETS_I                     ((nv_items_enum_type) 435)
#define  NV_PCS_TX_COMP0_I                             ((nv_items_enum_type) 436)
#define  NV_PCS_TX_COMP1_I                             ((nv_items_enum_type) 437)
#define  NV_PCS_TX_COMP2_I                             ((nv_items_enum_type) 438)
#define  NV_PCS_TX_COMP3_I                             ((nv_items_enum_type) 439)
#define  NV_DIAG_RESTART_CONFIG_I                      ((nv_items_enum_type) 440)
#define  NV_BAND_PREF_I                                ((nv_items_enum_type) 441)
#define  NV_ROAM_PREF_I                                ((nv_items_enum_type) 442)
#define  NV_GPS1_GPS_RF_DELAY_I                        ((nv_items_enum_type) 443)
#define  NV_GPS1_CDMA_RF_DELAY_I                       ((nv_items_enum_type) 444)
#define  NV_PCS_ENC_BTF_I                              ((nv_items_enum_type) 445)
#define  NV_CDMA_ENC_BTF_I                             ((nv_items_enum_type) 446)
#define  NV_BD_ADDR_I                                  ((nv_items_enum_type) 447)
#define  NV_SUBPCG_PA_WARMUP_DELAY_I                   ((nv_items_enum_type) 448)
#define  NV_GPS1_GPS_RF_LOSS_I                         ((nv_items_enum_type) 449)
#define  NV_DATA_TRTL_ENABLED_I                        ((nv_items_enum_type) 450)
#define  NV_AMPS_BACKSTOP_ENABLED_I                    ((nv_items_enum_type) 451)
#define  NV_GPS1_LOCK_I                                ((nv_items_enum_type) 452)
#define  NV_FTM_MODE_I                                 ((nv_items_enum_type) 453)// already in QLIB_Defines
#define  NV_DS_DEFAULT_BAUDRATE_I                      ((nv_items_enum_type) 454)
#define  NV_DIAG_DEFAULT_BAUDRATE_I                    ((nv_items_enum_type) 455)
#define  NV_JCDMA_DS_F92_I                             ((nv_items_enum_type) 456)
#define  NV_DS_QCMIP_I                                 ((nv_items_enum_type) 459)
#define  NV_DS_MIP_RETRIES_I                           ((nv_items_enum_type) 460)
#define  NV_DS_MIP_RETRY_INT_I                         ((nv_items_enum_type) 461)
#define  NV_DS_MIP_PRE_RE_RRQ_TIME_I                   ((nv_items_enum_type) 462)
#define  NV_DS_MIP_NUM_PROF_I                          ((nv_items_enum_type) 463)
#define  NV_DS_MIP_ACTIVE_PROF_I                       ((nv_items_enum_type) 464)
#define  NV_DS_MIP_GEN_USER_PROF_I                     ((nv_items_enum_type) 465)
#define  NV_DS_MIP_SS_USER_PROF_I                      ((nv_items_enum_type) 466)
#define  NV_HDR_CON_SUSPEND_I                          ((nv_items_enum_type) 467)
#define  NV_HDR_PRE_CC_CYC_ENABLED_I                   ((nv_items_enum_type) 468)
#define  NV_HDR_PRE_CC_CYC_I                           ((nv_items_enum_type) 469)
#define  NV_HDR_SRCH_PARAMS_I                          ((nv_items_enum_type) 470)
#define  NV_HDRSMP_KEEP_ALIVE_START_I                  ((nv_items_enum_type) 471)
#define  NV_HDRSMP_KEEP_ALIVE_SENT_I                   ((nv_items_enum_type) 472)
#define  NV_HDRSMP_KEEP_ALIVE_REQ_INT_I                ((nv_items_enum_type) 473)
#define  NV_HDRAMP_ADDRESS_DATA_I                      ((nv_items_enum_type) 474)
#define  NV_HDRSCP_SESSION_STATUS_I                    ((nv_items_enum_type) 475)
#define  NV_HDRSCP_TOKEN_I                             ((nv_items_enum_type) 476)
#define  NV_HDRSCP_PROTOCOL_SUBTYPE_I                  ((nv_items_enum_type) 477)
#define  NV_HDRAMP_DUAL_EXPIRE_TIME_I                  ((nv_items_enum_type) 478)
#define  NV_HDRSTREAM_CURR_STREAM_CFG_I                ((nv_items_enum_type) 479)
#define  NV_HDR_SET_MNGMT_SAME_CHAN_I                  ((nv_items_enum_type) 480)
#define  NV_HDR_SET_MNGMT_DIFF_CHAN_I                  ((nv_items_enum_type) 481)
#define  NV_HDRLUP_UNSOLICITED_ENABLED_I               ((nv_items_enum_type) 482)
#define  NV_HDRAMAC_INITIAL_CONFIG_I                   ((nv_items_enum_type) 483)
#define  NV_HDRAMAC_POWER_PARAMS_I                     ((nv_items_enum_type) 484)
#define  NV_HDRFMAC_DRC_GATING_I                       ((nv_items_enum_type) 485)
#define  NV_HDRFMAC_HANDOFF_DELAYS_I                   ((nv_items_enum_type) 486)
#define  NV_HDRRMAC_POWER_PARAMS_I                     ((nv_items_enum_type) 487)
#define  NV_HDRRMAC_RATE_PARAMS_I                      ((nv_items_enum_type) 488)
#define  NV_HDRSLP_RESET_SEQNO_I                       ((nv_items_enum_type) 489)
#define  NV_PWR_BACKOFF_VS_VOLT_MED_I                  ((nv_items_enum_type) 490)
#define  NV_PWR_BACKOFF_VS_VOLT_LOW_I                  ((nv_items_enum_type) 491)
#define  NV_PA_BACKOFF_VOLTS_I                         ((nv_items_enum_type) 492)
#define  NV_VBATT_MIN_MAX_I                            ((nv_items_enum_type) 493)
#define  NV_DS_MIP_MN_HA_TIME_DELTA_I                  ((nv_items_enum_type) 494)
#define  NV_DS_MIP_QC_DRS_OPT_I                        ((nv_items_enum_type) 495)
#define  NV_ANT2_CDMA_RX_LIN_OFF_0_I                   ((nv_items_enum_type) 496)
#define  NV_ANT2_CDMA_RX_LIN_SLP_I                     ((nv_items_enum_type) 497)
#define  NV_ANT2_CDMA_RX_COMP_VS_FREQ_I                ((nv_items_enum_type) 498)
#define  NV_ANT2_CDMA_RX_LIN_VS_TEMP_I                 ((nv_items_enum_type) 499)
#define  NV_ANT2_CDMA_RX_SLP_VS_TEMP_I                 ((nv_items_enum_type) 500)
#define  NV_ANT2_LNA_RANGE_OFFSET_I                    ((nv_items_enum_type) 501)
#define  NV_ANT2_LNA_RANGE_12_OFFSET_I                 ((nv_items_enum_type) 502)
#define  NV_ANT2_CDMA_LNA_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 503)
#define  NV_ANT2_CDMA_LNA_12_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 504)
#define  NV_ANT2_PCS_RX_LIN_OFF_0_I                    ((nv_items_enum_type) 505)
#define  NV_ANT2_PCS_RX_LIN_SLP_I                      ((nv_items_enum_type) 506)
#define  NV_ANT2_PCS_RX_COMP_VS_FREQ_I                 ((nv_items_enum_type) 507)
#define  NV_ANT2_PCS_RX_LIN_VS_TEMP_I                  ((nv_items_enum_type) 508)
#define  NV_ANT2_PCS_RX_SLP_VS_TEMP_I                  ((nv_items_enum_type) 509)
#define  NV_ANT2_PCS_LNA_RANGE_OFFSET_I                ((nv_items_enum_type) 510)
#define  NV_ANT2_PCS_LNA_RANGE_12_OFFSET_I             ((nv_items_enum_type) 511)
#define  NV_ANT2_PCS_CDMA_LNA_OFFSET_VS_FREQ_I         ((nv_items_enum_type) 512)
#define  NV_ANT2_PCS_CDMA_LNA_12_OFFSET_VS_FREQ_I      ((nv_items_enum_type) 513)
#define  NV_WCDMA_RX_LIN_I                             ((nv_items_enum_type) 514)
#define  NV_WCDMA_RX_COMP_VS_FREQ_I                    ((nv_items_enum_type) 515)
#define  NV_WCDMA_RX_LIN_VS_TEMP_I                     ((nv_items_enum_type) 516)
#define  NV_WCDMA_RX_SLP_VS_TEMP_I                     ((nv_items_enum_type) 517)
#define  NV_WCDMA_LNA_RANGE_POL_I                      ((nv_items_enum_type) 518)
#define  NV_WCDMA_LNA_RANGE_RISE_I                     ((nv_items_enum_type) 519)
#define  NV_WCDMA_LNA_RANGE_FALL_I                     ((nv_items_enum_type) 520)
#define  NV_WCDMA_IM_LEVEL_I                           ((nv_items_enum_type) 521)
#define  NV_WCDMA_NONBYPASS_TIMER_I                    ((nv_items_enum_type) 522)
#define  NV_WCDMA_BYPASS_TIMER_I                       ((nv_items_enum_type) 523)
#define  NV_WCDMA_LNA_RANGE_OFFSET_I                   ((nv_items_enum_type) 524)
#define  NV_WCDMA_LNA_OFFSET_VS_FREQ_I                 ((nv_items_enum_type) 525)
#define  NV_WCDMA_RX_AGC_MIN_I                         ((nv_items_enum_type) 526)
#define  NV_WCDMA_RX_AGC_MAX_I                         ((nv_items_enum_type) 527)
#define  NV_WCDMA_AGC_PHASE_OFFSET_I                   ((nv_items_enum_type) 528)
#define  NV_WCDMA_TX_LIN_MASTER_0_I                    ((nv_items_enum_type) 529)
#define  NV_WCDMA_TX_LIN_MASTER_1_I                    ((nv_items_enum_type) 530)
#define  NV_WCDMA_TX_COMP_VS_FREQ_0_I                  ((nv_items_enum_type) 531)
#define  NV_WCDMA_TX_COMP_VS_FREQ_1_I                  ((nv_items_enum_type) 532)
#define  NV_WCDMA_TX_LIN_VS_TEMP_0_I                   ((nv_items_enum_type) 533)
#define  NV_WCDMA_TX_LIN_VS_TEMP_1_I                   ((nv_items_enum_type) 534)
#define  NV_WCDMA_TX_SLP_VS_TEMP_0_I                   ((nv_items_enum_type) 535)
#define  NV_WCDMA_TX_SLP_VS_TEMP_1_I                   ((nv_items_enum_type) 536)
#define  NV_WCDMA_R1_RISE_I                            ((nv_items_enum_type) 537)
#define  NV_WCDMA_R1_FALL_I                            ((nv_items_enum_type) 538)
#define  NV_WCDMA_TX_LIM_VS_TEMP_I                     ((nv_items_enum_type) 539)
#define  NV_WCDMA_TX_LIM_VS_FREQ_I                     ((nv_items_enum_type) 540)
#define  NV_WCDMA_ADJ_FACTOR_I                         ((nv_items_enum_type) 541)
#define  NV_WCDMA_EXP_HDET_VS_AGC_I                    ((nv_items_enum_type) 542)
#define  NV_WCDMA_HDET_OFF_I                           ((nv_items_enum_type) 543)
#define  NV_WCDMA_HDET_SPN_I                           ((nv_items_enum_type) 544)
#define  NV_WCDMA_ENC_BTF_I                            ((nv_items_enum_type) 545)
#define  NV_DS_MIP_2002BIS_MN_HA_AUTH_I                ((nv_items_enum_type) 546)
#define  NV_UE_RAT_CAPABILITY_I                        ((nv_items_enum_type) 547)
#define  NV_GSM_UE_OP_CLASS_I                          ((nv_items_enum_type) 548)
#define  NV_UMTS_UE_OP_CLASS_I                         ((nv_items_enum_type) 549)
#define  NV_UE_IMEI_I                                  ((nv_items_enum_type) 550)
#define  NV_MSRAC_SMS_VALUE_I                          ((nv_items_enum_type) 551)
#define  NV_MSRAC_SM_VALUE_I                           ((nv_items_enum_type) 552)
#define  NV_GSM_A5_ALGORITHMS_SUPPORTED_I              ((nv_items_enum_type) 553)
#define  NV_HDRFMAC_DRC_LOCK_I                         ((nv_items_enum_type) 554)
#define  NV_GPS1_LO_CAL_I                              ((nv_items_enum_type) 555)
#define  NV_GPS1_ANT_OFF_DB_I                          ((nv_items_enum_type) 556)
#define  NV_GPS1_PCS_RF_DELAY_I                        ((nv_items_enum_type) 557)
#define  NV_SMS_VM_NUMBER_I                            ((nv_items_enum_type) 558)
#define  NV_SMS_GW_PARMS_I                             ((nv_items_enum_type) 559)
#define  NV_SMS_GW_I                                   ((nv_items_enum_type) 561)
#define  NV_HYBRID_PREF_I                              ((nv_items_enum_type) 562)
#define  NV_SP_ECC_ENABLED_I                           ((nv_items_enum_type) 563)
#define  NV_ECC_LIST_I                                 ((nv_items_enum_type) 564)
#define  NV_BT_LPOS_LAT_I                              ((nv_items_enum_type) 565)
#define  NV_BT_LPOS_LONG_I                             ((nv_items_enum_type) 566)
#define  NV_TEST_CODE_VER_I                            ((nv_items_enum_type) 567)
#define  NV_SYS_SW_VER_I                               ((nv_items_enum_type) 568)
#define  NV_RF_CAL_VER_I                               ((nv_items_enum_type) 569)
#define  NV_RF_CONFIG_VER_I                            ((nv_items_enum_type) 570)
#define  NV_RF_CAL_DATE_I                              ((nv_items_enum_type) 571)
#define  NV_RF_NV_LOADED_DATE_I                        ((nv_items_enum_type) 572)
#define  NV_RF_CAL_DAT_FILE_I                          ((nv_items_enum_type) 573)
#define  NV_DOMAIN_NAME_I                              ((nv_items_enum_type) 574)
#define  NV_PREF_PLMN_I                                ((nv_items_enum_type) 577)
#define  NV_HDR_AN_AUTH_NAI_I                          ((nv_items_enum_type) 579)
#define  NV_HDR_AN_AUTH_PASSWORD_I                     ((nv_items_enum_type) 580)
#define  NV_PUZL_ENABLED_I                             ((nv_items_enum_type) 581)
#define  NV_HDRKEP_CONFIG_I                            ((nv_items_enum_type) 583)
#define  NV_HDRAUTH_CONFIG_I                           ((nv_items_enum_type) 584)
#define  NV_IM_LEVEL3_I                                ((nv_items_enum_type) 585)
#define  NV_IM_LEVEL4_I                                ((nv_items_enum_type) 586)
#define  NV_AGC_VALUE_3_MIN_I                          ((nv_items_enum_type) 587)
#define  NV_AGC_VALUE_4_MIN_I                          ((nv_items_enum_type) 588)
#define  NV_TX_GAIN_ATTEN_LIMIT_I                      ((nv_items_enum_type) 589)
#define  NV_CDMA_LNA_3_FALL_I                          ((nv_items_enum_type) 590)
#define  NV_CDMA_LNA_3_OFFSET_I                        ((nv_items_enum_type) 591)
#define  NV_CDMA_LNA_3_RISE_I                          ((nv_items_enum_type) 592)
#define  NV_CDMA_LNA_3_OFFSET_VS_FREQ_I                ((nv_items_enum_type) 593)
#define  NV_PCS_LNA_3_FALL_I                           ((nv_items_enum_type) 594)
#define  NV_PCS_LNA_3_OFFSET_I                         ((nv_items_enum_type) 595)
#define  NV_PCS_LNA_3_RISE_I                           ((nv_items_enum_type) 596)
#define  NV_PCS_LNA_3_OFFSET_VS_FREQ_I                 ((nv_items_enum_type) 597)
#define  NV_CDMA_LNA_4_FALL_I                          ((nv_items_enum_type) 598)
#define  NV_CDMA_LNA_4_OFFSET_I                        ((nv_items_enum_type) 599)
#define  NV_CDMA_LNA_4_RISE_I                          ((nv_items_enum_type) 600)
#define  NV_CDMA_LNA_4_OFFSET_VS_FREQ_I                ((nv_items_enum_type) 601)
#define  NV_PCS_LNA_4_FALL_I                           ((nv_items_enum_type) 602)
#define  NV_PCS_LNA_4_OFFSET_I                         ((nv_items_enum_type) 603)
#define  NV_PCS_LNA_4_RISE_I                           ((nv_items_enum_type) 604)
#define  NV_PCS_LNA_4_OFFSET_VS_FREQ_I                 ((nv_items_enum_type) 605)
#define  NV_DFM_LNA_FALL_I                             ((nv_items_enum_type) 606)
#define  NV_DFM_LNA_OFFSET_I                           ((nv_items_enum_type) 607)
#define  NV_DFM_LNA_RISE_I                             ((nv_items_enum_type) 608)
#define  NV_DFM_LNA_OFFSET_VS_FREQ_I                   ((nv_items_enum_type) 609)
#define  NV_DFM_AGC_ACC_MIN_1_I                        ((nv_items_enum_type) 610)
#define  NV_DFM_AGC_IM_GAIN_I                          ((nv_items_enum_type) 611)
#define  NV_DFM_AGC_DC_GAIN_I                          ((nv_items_enum_type) 612)
#define  NV_DFM_IM_LEVEL1_I                            ((nv_items_enum_type) 613)
#define  NV_GPS_FG_TRK_OFFSET_SCALER_I                 ((nv_items_enum_type) 614)
#define  NV_DIGITAL_FG_TRK_OFFSET_SCALER_I             ((nv_items_enum_type) 615)
#define  NV_FM_FG_TRK_OFFSET_SCALER_I                  ((nv_items_enum_type) 616)
#define  NV_DFM_LNA_S0_PHASE_OFFSET_I                  ((nv_items_enum_type) 617)
#define  NV_DFM_LNA_S1_PHASE_OFFSET_I                  ((nv_items_enum_type) 618)
#define  NV_CDMA_RXF_CG_IOFFSET_I                      ((nv_items_enum_type) 619)
#define  NV_PCS_RXF_CG_IOFFSET_I                       ((nv_items_enum_type) 620)
#define  NV_FM_RXF_CG_IOFFSET_I                        ((nv_items_enum_type) 621)
#define  NV_GPS_RXF_CG_IOFFSET_I                       ((nv_items_enum_type) 622)
#define  NV_CDMA_RXF_CG_QOFFSET_I                      ((nv_items_enum_type) 623)
#define  NV_PCS_RXF_CG_QOFFSET_I                       ((nv_items_enum_type) 624)
#define  NV_FM_RXF_CG_QOFFSET_I                        ((nv_items_enum_type) 625)
#define  NV_GPS_RXF_CG_QOFFSET_I                       ((nv_items_enum_type) 626)
#define  NV_CDMA_RXF_FG_IOFFSET_I                      ((nv_items_enum_type) 627)
#define  NV_PCS_RXF_FG_IOFFSET_I                       ((nv_items_enum_type) 628)
#define  NV_FM_RXF_FG_IOFFSET_I                        ((nv_items_enum_type) 629)
#define  NV_GPS_RXF_FG_IOFFSET_I                       ((nv_items_enum_type) 630)
#define  NV_CDMA_RXF_FG_QOFFSET_I                      ((nv_items_enum_type) 631)
#define  NV_PCS_RXF_FG_QOFFSET_I                       ((nv_items_enum_type) 632)
#define  NV_FM_RXF_FG_QOFFSET_I                        ((nv_items_enum_type) 633)
#define  NV_GPS_RXF_FG_QOFFSET_I                       ((nv_items_enum_type) 634)
#define  NV_CDMA_DACC_EST_IOFFSET_I                    ((nv_items_enum_type) 635)
#define  NV_PCS_DACC_EST_IOFFSET_I                     ((nv_items_enum_type) 636)
#define  NV_FM_DACC_EST_IOFFSET_I                      ((nv_items_enum_type) 637)
#define  NV_GPS_DACC_EST_IOFFSET_I                     ((nv_items_enum_type) 638)
#define  NV_CDMA_DACC_EST_QOFFSET_I                    ((nv_items_enum_type) 639)
#define  NV_PCS_DACC_EST_QOFFSET_I                     ((nv_items_enum_type) 640)
#define  NV_FM_DACC_EST_QOFFSET_I                      ((nv_items_enum_type) 641)
#define  NV_GPS_DACC_EST_QOFFSET_I                     ((nv_items_enum_type) 642)
#define  NV_CDMA_DACC_IACCUM0_I                        ((nv_items_enum_type) 643)
#define  NV_PCS_DACC_IACCUM0_I                         ((nv_items_enum_type) 644)
#define  NV_FM_DACC_IACCUM0_I                          ((nv_items_enum_type) 645)
#define  NV_GPS_DACC_IACCUM0_I                         ((nv_items_enum_type) 646)
#define  NV_CDMA_DACC_IACCUM1_I                        ((nv_items_enum_type) 647)
#define  NV_PCS_DACC_IACCUM1_I                         ((nv_items_enum_type) 648)
#define  NV_FM_DACC_IACCUM1_I                          ((nv_items_enum_type) 649)
#define  NV_GPS_DACC_IACCUM1_I                         ((nv_items_enum_type) 650)
#define  NV_CDMA_DACC_IACCUM2_I                        ((nv_items_enum_type) 651)
#define  NV_PCS_DACC_IACCUM2_I                         ((nv_items_enum_type) 652)
#define  NV_FM_DACC_IACCUM2_I                          ((nv_items_enum_type) 653)
#define  NV_GPS_DACC_IACCUM2_I                         ((nv_items_enum_type) 654)
#define  NV_CDMA_DACC_IACCUM3_I                        ((nv_items_enum_type) 655)
#define  NV_PCS_DACC_IACCUM3_I                         ((nv_items_enum_type) 656)
#define  NV_FM_DACC_IACCUM3_I                          ((nv_items_enum_type) 657)
#define  NV_GPS_DACC_IACCUM3_I                         ((nv_items_enum_type) 658)
#define  NV_CDMA_DACC_IACCUM4_I                        ((nv_items_enum_type) 659)
#define  NV_PCS_DACC_IACCUM4_I                         ((nv_items_enum_type) 660)
#define  NV_FM_DACC_IACCUM4_I                          ((nv_items_enum_type) 661)
#define  NV_GPS_DACC_IACCUM4_I                         ((nv_items_enum_type) 662)
#define  NV_CDMA_DACC_QACCUM0_I                        ((nv_items_enum_type) 663)
#define  NV_PCS_DACC_QACCUM0_I                         ((nv_items_enum_type) 664)
#define  NV_FM_DACC_QACCUM0_I                          ((nv_items_enum_type) 665)
#define  NV_GPS_DACC_QACCUM0_I                         ((nv_items_enum_type) 666)
#define  NV_CDMA_DACC_QACCUM1_I                        ((nv_items_enum_type) 667)
#define  NV_PCS_DACC_QACCUM1_I                         ((nv_items_enum_type) 668)
#define  NV_FM_DACC_QACCUM1_I                          ((nv_items_enum_type) 669)
#define  NV_GPS_DACC_QACCUM1_I                         ((nv_items_enum_type) 670)
#define  NV_CDMA_DACC_QACCUM2_I                        ((nv_items_enum_type) 671)
#define  NV_PCS_DACC_QACCUM2_I                         ((nv_items_enum_type) 672)
#define  NV_FM_DACC_QACCUM2_I                          ((nv_items_enum_type) 673)
#define  NV_GPS_DACC_QACCUM2_I                         ((nv_items_enum_type) 674)
#define  NV_CDMA_DACC_QACCUM3_I                        ((nv_items_enum_type) 675)
#define  NV_PCS_DACC_QACCUM3_I                         ((nv_items_enum_type) 676)
#define  NV_FM_DACC_QACCUM3_I                          ((nv_items_enum_type) 677)
#define  NV_GPS_DACC_QACCUM3_I                         ((nv_items_enum_type) 678)
#define  NV_CDMA_DACC_QACCUM4_I                        ((nv_items_enum_type) 679)
#define  NV_PCS_DACC_QACCUM4_I                         ((nv_items_enum_type) 680)
#define  NV_FM_DACC_QACCUM4_I                          ((nv_items_enum_type) 681)
#define  NV_GPS_DACC_QACCUM4_I                         ((nv_items_enum_type) 682)
#define  NV_CDMA_DACC_GAIN_MULT_I                      ((nv_items_enum_type) 683)
#define  NV_PCS_DACC_GAIN_MULT_I                       ((nv_items_enum_type) 684)
#define  NV_FM_DACC_GAIN_MULT_I                        ((nv_items_enum_type) 685)
#define  NV_GPS_DACC_GAIN_MULT_I                       ((nv_items_enum_type) 686)
#define  NV_CDMA_IM2_I_VALUE_I                         ((nv_items_enum_type) 687)
#define  NV_PCS_IM2_I_VALUE_I                          ((nv_items_enum_type) 688)
#define  NV_CDMA_IM2_Q_VALUE_I                         ((nv_items_enum_type) 689)
#define  NV_PCS_IM2_Q_VALUE_I                          ((nv_items_enum_type) 690)
#define  NV_RTC_TIME_ADJUST_I                          ((nv_items_enum_type) 691)
#define  NV_FM_VGA_GAIN_OFFSET_I                       ((nv_items_enum_type) 692)
#define  NV_CDMA_VGA_GAIN_OFFSET_I                     ((nv_items_enum_type) 693)
#define  NV_PCS_VGA_GAIN_OFFSET_I                      ((nv_items_enum_type) 694)
#define  NV_FM_VGA_GAIN_OFFSET_VS_FREQ_I               ((nv_items_enum_type) 695)
#define  NV_CDMA_VGA_GAIN_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 696)
#define  NV_PCS_VGA_GAIN_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 697)
#define  NV_FM_VGA_GAIN_OFFSET_VS_TEMP_I               ((nv_items_enum_type) 698)
#define  NV_CDMA_VGA_GAIN_OFFSET_VS_TEMP_I             ((nv_items_enum_type) 699)
#define  NV_PCS_VGA_GAIN_OFFSET_VS_TEMP_I              ((nv_items_enum_type) 700)
#define  NV_FM_MIS_COMP_A_OFFSET_I                     ((nv_items_enum_type) 701)
#define  NV_DIGITAL_MIS_COMP_A_OFFSET_I                ((nv_items_enum_type) 702)
#define  NV_GPS_MIS_COMP_A_OFFSET_I                    ((nv_items_enum_type) 703)
#define  NV_FM_MIS_COMP_B_OFFSET_I                     ((nv_items_enum_type) 704)
#define  NV_DIGITAL_MIS_COMP_B_OFFSET_I                ((nv_items_enum_type) 705)
#define  NV_GPS_MIS_COMP_B_OFFSET_I                    ((nv_items_enum_type) 706)
#define  NV_DS_MIP_RRQ_IF_TFRK_I                       ((nv_items_enum_type) 707)
#define  NV_COLLOC_DISALLOWED_TIME_I                   ((nv_items_enum_type) 708)
#define  NV_HOLD_HDR_TIME_I                            ((nv_items_enum_type) 709)
#define  NV_LO_BIAS_UPDATE_CNT_I                       ((nv_items_enum_type) 710)
#define  NV_HDRSCP_AN_AUTH_STATUS_I                    ((nv_items_enum_type) 712)
#define  NV_IMSI_INDEX_I                               ((nv_items_enum_type) 713)
#define  NV_DS_MIP_ENABLE_PROF_I                       ((nv_items_enum_type) 714)
#define  NV_PCS_IM_LEVEL3_I                            ((nv_items_enum_type) 715)
#define  NV_PCS_IM_LEVEL4_I                            ((nv_items_enum_type) 716)
#define  NV_PCS_AGC_VALUE_3_MIN_I                      ((nv_items_enum_type) 717)
#define  NV_PCS_AGC_VALUE_4_MIN_I                      ((nv_items_enum_type) 718)
#define  NV_HDRSMPKA_START_TIME_I                      ((nv_items_enum_type) 719)
#define  NV_HDRSMPKA_SENT_TIME_I                       ((nv_items_enum_type) 720)
#define  NV_SMS_BC_SERVICE_TABLE_OPTIONS_I             ((nv_items_enum_type) 721)
#define  NV_ACQ_DB_I                                   ((nv_items_enum_type) 722)
#define  NV_ACQ_LIST_1_I                               ((nv_items_enum_type) 723)
#define  NV_GSM_CAL_ARFCN_I                            ((nv_items_enum_type) 724)
#define  NV_DCS_CAL_ARFCN_I                            ((nv_items_enum_type) 725)
#define  NV_GSM_RX_GAIN_RANGE_1_FREQ_COMP_I            ((nv_items_enum_type) 726)
#define  NV_GSM_RX_GAIN_RANGE_2_FREQ_COMP_I            ((nv_items_enum_type) 727)
#define  NV_GSM_RX_GAIN_RANGE_3_FREQ_COMP_I            ((nv_items_enum_type) 728)
#define  NV_GSM_RX_GAIN_RANGE_4_FREQ_COMP_I            ((nv_items_enum_type) 729)
#define  NV_DCS_RX_GAIN_RANGE_1_FREQ_COMP_I            ((nv_items_enum_type) 730)
#define  NV_DCS_RX_GAIN_RANGE_2_FREQ_COMP_I            ((nv_items_enum_type) 731)
#define  NV_DCS_RX_GAIN_RANGE_3_FREQ_COMP_I            ((nv_items_enum_type) 732)
#define  NV_DCS_RX_GAIN_RANGE_4_FREQ_COMP_I            ((nv_items_enum_type) 733)
#define  NV_GSM_TRK_LO_ADJ_PDM_INIT_VAL_I              ((nv_items_enum_type) 734)
#define  NV_GSM_TRK_LO_ADJ_PDM_GAIN_SLOPE_I            ((nv_items_enum_type) 735)
#define  NV_GPS_DOPP_SDEV_I                            ((nv_items_enum_type) 736)
#define  NV_ACQ_LIST_2_I                               ((nv_items_enum_type) 737)
#define  NV_ACQ_LIST_3_I                               ((nv_items_enum_type) 738)
#define  NV_ACQ_LIST_4_I                               ((nv_items_enum_type) 739)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_00_I            ((nv_items_enum_type) 740)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_01_I            ((nv_items_enum_type) 741)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_02_I            ((nv_items_enum_type) 742)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_03_I            ((nv_items_enum_type) 743)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_04_I            ((nv_items_enum_type) 744)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_05_I            ((nv_items_enum_type) 745)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_06_I            ((nv_items_enum_type) 746)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_07_I            ((nv_items_enum_type) 747)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_08_I            ((nv_items_enum_type) 748)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_09_I            ((nv_items_enum_type) 749)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_10_I            ((nv_items_enum_type) 750)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_11_I            ((nv_items_enum_type) 751)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_12_I            ((nv_items_enum_type) 752)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_13_I            ((nv_items_enum_type) 753)
#define  NV_GSM_TX_BURST_RAMP_UP_INDEX_14_I            ((nv_items_enum_type) 754)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_00_I          ((nv_items_enum_type) 755)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_01_I          ((nv_items_enum_type) 756)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_02_I          ((nv_items_enum_type) 757)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_03_I          ((nv_items_enum_type) 758)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_04_I          ((nv_items_enum_type) 759)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_05_I          ((nv_items_enum_type) 760)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_06_I          ((nv_items_enum_type) 761)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_07_I          ((nv_items_enum_type) 762)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_08_I          ((nv_items_enum_type) 763)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_09_I          ((nv_items_enum_type) 764)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_10_I          ((nv_items_enum_type) 765)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_11_I          ((nv_items_enum_type) 766)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_12_I          ((nv_items_enum_type) 767)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_13_I          ((nv_items_enum_type) 768)
#define  NV_GSM_TX_BURST_RAMP_DOWN_INDEX_14_I          ((nv_items_enum_type) 769)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_00_I            ((nv_items_enum_type) 770)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_01_I            ((nv_items_enum_type) 771)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_02_I            ((nv_items_enum_type) 772)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_03_I            ((nv_items_enum_type) 773)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_04_I            ((nv_items_enum_type) 774)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_05_I            ((nv_items_enum_type) 775)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_06_I            ((nv_items_enum_type) 776)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_07_I            ((nv_items_enum_type) 777)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_08_I            ((nv_items_enum_type) 778)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_09_I            ((nv_items_enum_type) 779)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_10_I            ((nv_items_enum_type) 780)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_11_I            ((nv_items_enum_type) 781)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_12_I            ((nv_items_enum_type) 782)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_13_I            ((nv_items_enum_type) 783)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_14_I            ((nv_items_enum_type) 784)
#define  NV_DCS_TX_BURST_RAMP_UP_INDEX_15_I            ((nv_items_enum_type) 785)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_00_I          ((nv_items_enum_type) 786)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_01_I          ((nv_items_enum_type) 787)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_02_I          ((nv_items_enum_type) 788)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_03_I          ((nv_items_enum_type) 789)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_04_I          ((nv_items_enum_type) 790)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_05_I          ((nv_items_enum_type) 791)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_06_I          ((nv_items_enum_type) 792)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_07_I          ((nv_items_enum_type) 793)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_08_I          ((nv_items_enum_type) 794)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_09_I          ((nv_items_enum_type) 795)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_10_I          ((nv_items_enum_type) 796)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_11_I          ((nv_items_enum_type) 797)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_12_I          ((nv_items_enum_type) 798)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_13_I          ((nv_items_enum_type) 799)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_14_I          ((nv_items_enum_type) 800)
#define  NV_DCS_TX_BURST_RAMP_DOWN_INDEX_15_I          ((nv_items_enum_type) 801)
#define  NV_GSM_PA_GAIN_SLOPE_I                        ((nv_items_enum_type) 802)
#define  NV_DCS_PA_GAIN_SLOPE_I                        ((nv_items_enum_type) 803)
#define  NV_GSM_TX_FREQ_COMP_I                         ((nv_items_enum_type) 804)
#define  NV_DCS_TX_FREQ_COMP_I                         ((nv_items_enum_type) 805)
#define  NV_GSM_VBATT_HI_PA_COMP_I                     ((nv_items_enum_type) 806)
#define  NV_GSM_VBATT_LO_PA_COMP_I                     ((nv_items_enum_type) 807)
#define  NV_DCS_VBATT_HI_PA_COMP_I                     ((nv_items_enum_type) 808)
#define  NV_DCS_VBATT_LO_PA_COMP_I                     ((nv_items_enum_type) 809)
#define  NV_VBATT_3200_MV_ADC_I                        ((nv_items_enum_type) 810)
#define  NV_VBATT_3700_MV_ADC_I                        ((nv_items_enum_type) 811)
#define  NV_VBATT_4200_MV_ADC_I                        ((nv_items_enum_type) 812)
#define  NV_GSM_PRECHARGE_I                            ((nv_items_enum_type) 813)
#define  NV_DCS_PRECHARGE_I                            ((nv_items_enum_type) 814)
#define  NV_GSM_PRECHARGE_DUR_I                        ((nv_items_enum_type) 815)
#define  NV_DCS_PRECHARGE_DUR_I                        ((nv_items_enum_type) 816)
#define  NV_DIGITAL_PLL_LOCK_TIMER_I                   ((nv_items_enum_type) 817)
#define  NV_HDR_RX_DIVERSITY_CTRL_I                    ((nv_items_enum_type) 818)
#define  NV_GSM_PA_START_TIME_OFFSET_I                 ((nv_items_enum_type) 819)
#define  NV_GSM_PA_STOP_TIME_OFFSET_I                  ((nv_items_enum_type) 820)
#define  NV_DCS_PA_START_TIME_OFFSET_I                 ((nv_items_enum_type) 821)
#define  NV_DCS_PA_STOP_TIME_OFFSET_I                  ((nv_items_enum_type) 822)
#define  NV_GPS1_PRIVACY_I                             ((nv_items_enum_type) 823)
#define  NV_GPS1_NET_ACCESS_I                          ((nv_items_enum_type) 824)
#define  NV_GPS1_CELLBASED_SMS_I                       ((nv_items_enum_type) 825)
#define  NV_GPS1_TELESERVICE_ID_I                      ((nv_items_enum_type) 826)
#define  NV_HDRRUP_SRCH_PARAMS_I                       ((nv_items_enum_type) 827)
#define  NV_DFM_LNA_BYPASS_TIMER_I                     ((nv_items_enum_type) 828)
#define  NV_DFM_LNA_NONBYPASS_TIMER_I                  ((nv_items_enum_type) 829)
#define  NV_SMS_CFG_ROUTING_I                          ((nv_items_enum_type) 830)
#define  NV_GPS1_NET_DBM_SIZE_I                        ((nv_items_enum_type) 831)
#define  NV_HDR_DO_NOT_DISTURB_I                       ((nv_items_enum_type) 832)
#define  NV_CDMA_TX_GAIN_ATTEN_LIMIT_I                 ((nv_items_enum_type) 833)
#define  NV_PCS_TX_GAIN_ATTEN_LIMIT_I                  ((nv_items_enum_type) 834)
#define  NV_AMPS_TX_GAIN_ATTEN_LIMIT_I                 ((nv_items_enum_type) 835)
#define  NV_GPS_TX_GAIN_ATTEN_LIMIT_I                  ((nv_items_enum_type) 836)
#define  NV_CDMA_IM2_TRANSCONDUCTOR_VALUE_I            ((nv_items_enum_type) 837)
#define  NV_PCS_IM2_TRANSCONDUCTOR_VALUE_I             ((nv_items_enum_type) 838)
#define  NV_LNA_NON_BYPASS_TIMER_0_I                   ((nv_items_enum_type) 839)
#define  NV_LNA_NON_BYPASS_TIMER_1_I                   ((nv_items_enum_type) 840)
#define  NV_LNA_NON_BYPASS_TIMER_2_I                   ((nv_items_enum_type) 841)
#define  NV_LNA_NON_BYPASS_TIMER_3_I                   ((nv_items_enum_type) 842)
#define  NV_LNA_BYPASS_TIMER_0_I                       ((nv_items_enum_type) 843)
#define  NV_LNA_BYPASS_TIMER_1_I                       ((nv_items_enum_type) 844)
#define  NV_LNA_BYPASS_TIMER_2_I                       ((nv_items_enum_type) 845)
#define  NV_LNA_BYPASS_TIMER_3_I                       ((nv_items_enum_type) 846)
#define  NV_SMS_CD_PARMS_I                             ((nv_items_enum_type) 847)
#define  NV_ACQ_ORDER_PREF_I                           ((nv_items_enum_type) 848)
#define  NV_NET_SEL_MODE_PREF_I                        ((nv_items_enum_type) 849)
#define  NV_SERVICE_DOMAIN_PREF_I                      ((nv_items_enum_type) 850)
#define  NV_PPP_AUTHENTICATION_I                       ((nv_items_enum_type) 851)
#define  NV_APN_NAME_I                                 ((nv_items_enum_type) 852)
#define  NV_EQUIVALENT_PLMN_LIST_I                     ((nv_items_enum_type) 853)
#define  NV_DS_MIP_DMU_PKOID_I                         ((nv_items_enum_type) 854)
#define  NV_RTRE_CONFIG_I                              ((nv_items_enum_type) 855)
#define  NV_WCDMA_VGA_GAIN_OFFSET_I                    ((nv_items_enum_type) 856)
#define  NV_WCDMA_VGA_GAIN_OFFSET_VS_FREQ_I            ((nv_items_enum_type) 857)
#define  NV_WCDMA_VGA_GAIN_OFFSET_VS_TEMP_I            ((nv_items_enum_type) 858)
#define  NV_WCDMA_LNA_RANGE_RISE_2_I                   ((nv_items_enum_type) 859)
#define  NV_WCDMA_LNA_RANGE_RISE_3_I                   ((nv_items_enum_type) 860)
#define  NV_WCDMA_LNA_RANGE_FALL_2_I                   ((nv_items_enum_type) 861)
#define  NV_WCDMA_LNA_RANGE_FALL_3_I                   ((nv_items_enum_type) 862)
#define  NV_WCDMA_IM_LEVEL_2_I                         ((nv_items_enum_type) 863)
#define  NV_WCDMA_IM_LEVEL_3_I                         ((nv_items_enum_type) 864)
#define  NV_WCDMA_LNA_RANGE_OFFSET_2_I                 ((nv_items_enum_type) 865)
#define  NV_WCDMA_LNA_RANGE_OFFSET_3_I                 ((nv_items_enum_type) 866)
#define  NV_WCDMA_LNA_OFFSET_VS_FREQ_2_I               ((nv_items_enum_type) 867)
#define  NV_WCDMA_LNA_OFFSET_VS_FREQ_3_I               ((nv_items_enum_type) 868)
#define  NV_WCDMA_IM2_I_VALUE_I                        ((nv_items_enum_type) 869)
#define  NV_WCDMA_IM2_Q_VALUE_I                        ((nv_items_enum_type) 870)
#define  NV_WCDMA_IM2_TRANSCONDUCTOR_VALUE_I           ((nv_items_enum_type) 871)
#define  NV_WCDMA_RX_AGC_MIN_2_I                       ((nv_items_enum_type) 872)
#define  NV_WCDMA_RX_AGC_MIN_3_I                       ((nv_items_enum_type) 873)
#define  NV_WCDMA_VBATT_I                              ((nv_items_enum_type) 874)
#define  NV_WCDMA_THERM_I                              ((nv_items_enum_type) 875)
#define  NV_WCDMA_MAX_TX_POWER_I                       ((nv_items_enum_type) 876)
#define  NV_FM_PA_MAC_HIGH_I                           ((nv_items_enum_type) 877)
#define  NV_CDMA_DYNAMIC_RANGE_I                       ((nv_items_enum_type) 878)
#define  NV_CDMA_MIN_RX_RSSI_I                         ((nv_items_enum_type) 879)
#define  NV_RRC_INTEGRITY_ENABLED_I                    ((nv_items_enum_type) 880)
#define  NV_RRC_CIPHERING_ENABLED_I                    ((nv_items_enum_type) 881)
#define  NV_RRC_FAKE_SECURITY_ENABLED_I                ((nv_items_enum_type) 882)
#define  NV_CDMA_POWERUP_REG_PERFORMED_I               ((nv_items_enum_type) 883)
#define  NV_TX_WARMUP_I                                ((nv_items_enum_type) 884)
#define  NV_LAST_TX_DATA_COUNT_I                       ((nv_items_enum_type) 885)
#define  NV_LAST_RX_DATA_COUNT_I                       ((nv_items_enum_type) 886)
#define  NV_TOTAL_TX_DATA_COUNT_I                      ((nv_items_enum_type) 887)
#define  NV_TOTAL_RX_DATA_COUNT_I                      ((nv_items_enum_type) 888)
#define  NV_DS_MIP_DMU_MN_AUTH_I                       ((nv_items_enum_type) 889)
#define  NV_USB_PRODUCT_ID_OFFSET_I                    ((nv_items_enum_type) 890)
#define  NV_AVCD_CALL_DURATION_I                       ((nv_items_enum_type) 891)
#define  NV_AVCD_TIME_BETWEEN_CALLS_I                  ((nv_items_enum_type) 892)
#define  NV_AVCD_NUMBER_OF_CALLS_I                     ((nv_items_enum_type) 893)
#define  NV_AVCD_SO_I                                  ((nv_items_enum_type) 894)
#define  NV_WCDMA_OUT_OF_SERVICE_THRESH_I              ((nv_items_enum_type) 895)
#define  NV_UIM_FIRST_INST_CLASS_I                     ((nv_items_enum_type) 896)
#define  NV_HDRRUP_OVERRIDE_ALLOWED_I                  ((nv_items_enum_type) 897)
#define  NV_JCDMA_M511_MODE_I                          ((nv_items_enum_type) 898)
#define  NV_JCDMA_M512_MODE_I                          ((nv_items_enum_type) 899)
#define  NV_JCDMA_M513_MODE_I                          ((nv_items_enum_type) 900)
#define  NV_CDMA_P1_RISE_FALL_OFF_I                    ((nv_items_enum_type) 901)
#define  NV_PCS_P1_RISE_FALL_OFF_I                     ((nv_items_enum_type) 902)
#define  NV_GSM_LOCIGPRS_I                             ((nv_items_enum_type) 903)
#define  NV_GSM_KCGPRS_I                               ((nv_items_enum_type) 904)
#define  NV_ERR_FATAL_OPTIONS_I                        ((nv_items_enum_type) 905)
#define  NV_PPP_PASSWORD_I                             ((nv_items_enum_type) 906)
#define  NV_TRK_LO_ADJ_VS_TEMP_I                       ((nv_items_enum_type) 907)
#define  NV_ROT_FREQ_VS_TEMP_I                         ((nv_items_enum_type) 908)
#define  NV_SMS_GW_BEARER_PREF_I                       ((nv_items_enum_type) 909)
#define  NV_PPP_USER_ID_I                              ((nv_items_enum_type) 910)
#define  NV_MULTISLOT_CLASS_I                          ((nv_items_enum_type) 911)
#define  NV_NON_DRX_TIMER_I                            ((nv_items_enum_type) 912)
#define  NV_SPLIT_PAGING_CYCLE_I                       ((nv_items_enum_type) 913)
#define  NV_UIM_PREF_PROTOCOL_I                        ((nv_items_enum_type) 914)
#define  NV_WCDMACS_SYNC_TEST_APP_ENABLED_I            ((nv_items_enum_type) 915)
#define  NV_GSM_GAINRANGE_SWITCHPOINTS_I               ((nv_items_enum_type) 916)
#define  NV_DCS_GAINRANGE_SWITCHPOINTS_I               ((nv_items_enum_type) 917)
#define  NV_HDR_AN_PPP_USER_ID_I                       ((nv_items_enum_type) 919)
#define  NV_HDR_AN_PPP_PASSWORD_I                      ((nv_items_enum_type) 920)
#define  NV_JTACS_PCDMACH_I                            ((nv_items_enum_type) 921)
#define  NV_JTACS_SCDMACH_I                            ((nv_items_enum_type) 922)
#define  NV_GSMUMTS_IMSI_I                             ((nv_items_enum_type) 923)
#define  NV_RTSP_PROXY_SERVER_ADDR_I                   ((nv_items_enum_type) 924)
#define  NV_SMS_GW_DEFAULT_TEMPLATE_I                  ((nv_items_enum_type) 925)
#define  NV_SMS_CD_DEFAULT_TEMPLATE_I                  ((nv_items_enum_type) 926)
#define  NV_NON_COMPLIANCE_COMMENT_I                   ((nv_items_enum_type) 927)
#define  NV_HYSTERISIS_ACTIVATION_TIMER_I              ((nv_items_enum_type) 928)
#define  NV_HYSTERISIS_TIMER_I                         ((nv_items_enum_type) 929)
#define  NV_PKT_DIAL_STRINGS_I                         ((nv_items_enum_type) 930)
#define  NV_VCO_COARSE_TUNE_TABLE_I                    ((nv_items_enum_type) 931)
#define  NV_DATA_INCOMING_CSD_CALL_IS_INTERNAL_I       ((nv_items_enum_type) 932)
#define  NV_DF_I                                       ((nv_items_enum_type) 933)
#define  NV_GSM_PA_TEMP_COMP_INDEX_14_I                ((nv_items_enum_type) 934)
#define  NV_DCS_PA_TEMP_COMP_INDEX_15_I                ((nv_items_enum_type) 935)
#define  NV_RF_TEST_ITEM_1_I                           ((nv_items_enum_type) 936)
#define  NV_RF_TEST_ITEM_2_I                           ((nv_items_enum_type) 937)
#define  NV_NEG_SLOT_CYCLE_INDEX_I                     ((nv_items_enum_type) 938)
#define  NV_BTFD_OLPC_FLOOR_DB_I                       ((nv_items_enum_type) 939)
#define  NV_NON_BTFD_OLPC_FLOOR_DB_I                   ((nv_items_enum_type) 940)
#define  NV_SSPR_P_REV_I                               ((nv_items_enum_type) 941)
#define  NV_RTSP_PROXY_SERVER_ADDR_ALTERNATE_I         ((nv_items_enum_type) 942)
#define  NV_UIM_CDMA_PREF_SLOT_I                       ((nv_items_enum_type) 943)
#define  NV_UIM_GSM_PREF_SLOT_I                        ((nv_items_enum_type) 944)
#define  NV_MRU3_TABLE_I                               ((nv_items_enum_type) 945)
#define  NV_BAND_PREF_16_31_I                          ((nv_items_enum_type) 946)
#define  NV_GPRS_ANITE_GCF_I                           ((nv_items_enum_type) 947)
#define  NV_C1_CDMA_LNA_OFFSET_I                       ((nv_items_enum_type) 948)
#define  NV_C1_CDMA_LNA_OFFSET_VS_FREQ_I               ((nv_items_enum_type) 949)
#define  NV_C1_PCS_LNA_OFFSET_I                        ((nv_items_enum_type) 950)
#define  NV_C1_PCS_LNA_OFFSET_VS_FREQ_I                ((nv_items_enum_type) 951)
#define  NV_C1_CDMA_LNA_2_OFFSET_I                     ((nv_items_enum_type) 952)
#define  NV_C1_CDMA_LNA_2_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 953)
#define  NV_C1_PCS_LNA_2_OFFSET_I                      ((nv_items_enum_type) 954)
#define  NV_C1_PCS_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 955)
#define  NV_C1_CDMA_LNA_3_OFFSET_I                     ((nv_items_enum_type) 956)
#define  NV_C1_CDMA_LNA_3_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 957)
#define  NV_C1_PCS_LNA_3_OFFSET_I                      ((nv_items_enum_type) 958)
#define  NV_C1_PCS_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 959)
#define  NV_C1_CDMA_LNA_4_OFFSET_I                     ((nv_items_enum_type) 960)
#define  NV_C1_CDMA_LNA_4_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 961)
#define  NV_C1_PCS_LNA_4_OFFSET_I                      ((nv_items_enum_type) 962)
#define  NV_C1_PCS_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 963)
#define  NV_C1_CDMA_P1_RISE_FALL_OFFSET_I              ((nv_items_enum_type) 964)
#define  NV_C1_PCS_P1_RISE_FALL_OFFSET_I               ((nv_items_enum_type) 965)
#define  NV_C1_RX_AGC_VALUE_1_MINMAX_I                 ((nv_items_enum_type) 966)
#define  NV_C1_RX_AGC_VALUE_2_MINMAX_I                 ((nv_items_enum_type) 967)
#define  NV_C1_RX_AGC_VALUE_3_MINMAX_I                 ((nv_items_enum_type) 968)
#define  NV_C1_RX_AGC_VALUE_4_MINMAX_I                 ((nv_items_enum_type) 969)
#define  NV_C0_RX_AGC_VREF_VAL_I                       ((nv_items_enum_type) 970)
#define  NV_C1_RX_AGC_VREF_VAL_I                       ((nv_items_enum_type) 971)
#define  NV_C0_GRP_DELAY_ADJ_I                         ((nv_items_enum_type) 972)
#define  NV_C1_GRP_DELAY_ADJ_I                         ((nv_items_enum_type) 973)
#define  NV_C1_CDMA_VGA_GAIN_OFFSET_I                  ((nv_items_enum_type) 974)
#define  NV_C1_CDMA_VGA_GAIN_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 975)
#define  NV_C1_CDMA_VGA_GAIN_OFFSET_VS_TEMP_I          ((nv_items_enum_type) 976)
#define  NV_C1_PCS_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 977)
#define  NV_C1_PCS_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 978)
#define  NV_C1_PCS_VGA_GAIN_OFFSET_VS_TEMP_I           ((nv_items_enum_type) 979)
#define  NV_C1_DIGITAL_MIS_COMP_A_OFFSET_I             ((nv_items_enum_type) 980)
#define  NV_C1_GPS_MIS_COMP_A_OFFSET_I                 ((nv_items_enum_type) 981)
#define  NV_C1_DIGITAL_MIS_COMP_B_OFFSET_I             ((nv_items_enum_type) 982)
#define  NV_C1_GPS_MIS_COMP_B_OFFSET_I                 ((nv_items_enum_type) 983)
#define  NV_C1_CDMA_DACC_IACCUM0_I                     ((nv_items_enum_type) 984)
#define  NV_C1_PCS_DACC_IACCUM0_I                      ((nv_items_enum_type) 985)
#define  NV_C1_GPS_DACC_IACCUM0_I                      ((nv_items_enum_type) 986)
#define  NV_C1_CDMA_DACC_IACCUM1_I                     ((nv_items_enum_type) 987)
#define  NV_C1_PCS_DACC_IACCUM1_I                      ((nv_items_enum_type) 988)
#define  NV_C1_GPS_DACC_IACCUM1_I                      ((nv_items_enum_type) 989)
#define  NV_C1_CDMA_DACC_IACCUM2_I                     ((nv_items_enum_type) 990)
#define  NV_C1_PCS_DACC_IACCUM2_I                      ((nv_items_enum_type) 991)
#define  NV_C1_GPS_DACC_IACCUM2_I                      ((nv_items_enum_type) 992)
#define  NV_C1_CDMA_DACC_IACCUM3_I                     ((nv_items_enum_type) 993)
#define  NV_C1_PCS_DACC_IACCUM3_I                      ((nv_items_enum_type) 994)
#define  NV_C1_GPS_DACC_IACCUM3_I                      ((nv_items_enum_type) 995)
#define  NV_C1_CDMA_DACC_IACCUM4_I                     ((nv_items_enum_type) 996)
#define  NV_C1_PCS_DACC_IACCUM4_I                      ((nv_items_enum_type) 997)
#define  NV_C1_GPS_DACC_IACCUM4_I                      ((nv_items_enum_type) 998)
#define  NV_C1_CDMA_DACC_QACCUM0_I                     ((nv_items_enum_type) 999)
#define  NV_C1_PCS_DACC_QACCUM0_I                      ((nv_items_enum_type) 1000)
#define  NV_C1_GPS_DACC_QACCUM0_I                      ((nv_items_enum_type) 1001)
#define  NV_C1_CDMA_DACC_QACCUM1_I                     ((nv_items_enum_type) 1002)
#define  NV_C1_PCS_DACC_QACCUM1_I                      ((nv_items_enum_type) 1003)
#define  NV_C1_GPS_DACC_QACCUM1_I                      ((nv_items_enum_type) 1004)
#define  NV_C1_CDMA_DACC_QACCUM2_I                     ((nv_items_enum_type) 1005)
#define  NV_C1_PCS_DACC_QACCUM2_I                      ((nv_items_enum_type) 1006)
#define  NV_C1_GPS_DACC_QACCUM2_I                      ((nv_items_enum_type) 1007)
#define  NV_C1_CDMA_DACC_QACCUM3_I                     ((nv_items_enum_type) 1008)
#define  NV_C1_PCS_DACC_QACCUM3_I                      ((nv_items_enum_type) 1009)
#define  NV_C1_GPS_DACC_QACCUM3_I                      ((nv_items_enum_type) 1010)
#define  NV_C1_CDMA_DACC_QACCUM4_I                     ((nv_items_enum_type) 1011)
#define  NV_C1_PCS_DACC_QACCUM4_I                      ((nv_items_enum_type) 1012)
#define  NV_C1_GPS_DACC_QACCUM4_I                      ((nv_items_enum_type) 1013)
#define  NV_SMS_GW_CB_SERVICE_TABLE_I                  ((nv_items_enum_type) 1014)
#define  NV_SMS_GW_CB_SERVICE_TABLE_SIZE_I             ((nv_items_enum_type) 1015)
#define  NV_SMS_GW_CB_CONFIG_I                         ((nv_items_enum_type) 1016)
#define  NV_SMS_GW_CB_USER_PREF_I                      ((nv_items_enum_type) 1017)
#define  NV_CDMA_RX_DIVERSITY_CTRL_I                   ((nv_items_enum_type) 1018)
#define  NV_LONG_PDPACT_TOLERANCE_FOR_TE_I             ((nv_items_enum_type) 1019)
#define  NV_C1_CDMA_IM2_Q_VALUE_I                      ((nv_items_enum_type) 1020)
#define  NV_C1_PCS_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1021)
#define  NV_C1_CDMA_IM2_I_VALUE_I                      ((nv_items_enum_type) 1022)
#define  NV_C1_PCS_IM2_I_VALUE_I                       ((nv_items_enum_type) 1023)
#define  NV_C1_CDMA_IM2_TRANSCONDUCTOR_VALUE_I         ((nv_items_enum_type) 1024)
#define  NV_C1_PCS_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1025)
#define  NV_C1_VCO_COARSE_TUNE_TABLE_I                 ((nv_items_enum_type) 1026)
#define  NV_MDSP_MEM_DUMP_ENABLED_I                    ((nv_items_enum_type) 1027)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_14_I            ((nv_items_enum_type) 1028)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_15_I           ((nv_items_enum_type) 1029)
#define  NV_FORCE_UE_SGSNR_R99_I                       ((nv_items_enum_type) 1030)
#define  NV_FORCE_UE_MSCR_R99_I                        ((nv_items_enum_type) 1031)
#define  NV_GPS_RF_CONFIG_I                            ((nv_items_enum_type) 1032)
#define  NV_C1_CDMA_LNA_1_RISE_I                       ((nv_items_enum_type) 1033)
#define  NV_C1_CDMA_LNA_2_RISE_I                       ((nv_items_enum_type) 1034)
#define  NV_C1_CDMA_LNA_3_RISE_I                       ((nv_items_enum_type) 1035)
#define  NV_C1_CDMA_LNA_4_RISE_I                       ((nv_items_enum_type) 1036)
#define  NV_C1_PCS_LNA_1_RISE_I                        ((nv_items_enum_type) 1037)
#define  NV_C1_PCS_LNA_2_RISE_I                        ((nv_items_enum_type) 1038)
#define  NV_C1_PCS_LNA_3_RISE_I                        ((nv_items_enum_type) 1039)
#define  NV_C1_PCS_LNA_4_RISE_I                        ((nv_items_enum_type) 1040)
#define  NV_C1_CDMA_LNA_1_FALL_I                       ((nv_items_enum_type) 1041)
#define  NV_C1_CDMA_LNA_2_FALL_I                       ((nv_items_enum_type) 1042)
#define  NV_C1_CDMA_LNA_3_FALL_I                       ((nv_items_enum_type) 1043)
#define  NV_C1_CDMA_LNA_4_FALL_I                       ((nv_items_enum_type) 1044)
#define  NV_C1_PCS_LNA_1_FALL_I                        ((nv_items_enum_type) 1045)
#define  NV_C1_PCS_LNA_2_FALL_I                        ((nv_items_enum_type) 1046)
#define  NV_C1_PCS_LNA_3_FALL_I                        ((nv_items_enum_type) 1047)
#define  NV_C1_PCS_LNA_4_FALL_I                        ((nv_items_enum_type) 1048)
#define  NV_C1_CDMA_IM_LEVEL1_I                        ((nv_items_enum_type) 1049)
#define  NV_C1_CDMA_IM_LEVEL2_I                        ((nv_items_enum_type) 1050)
#define  NV_C1_CDMA_IM_LEVEL3_I                        ((nv_items_enum_type) 1051)
#define  NV_C1_CDMA_IM_LEVEL4_I                        ((nv_items_enum_type) 1052)
#define  NV_C1_PCS_IM_LEVEL1_I                         ((nv_items_enum_type) 1053)
#define  NV_C1_PCS_IM_LEVEL2_I                         ((nv_items_enum_type) 1054)
#define  NV_C1_PCS_IM_LEVEL3_I                         ((nv_items_enum_type) 1055)
#define  NV_C1_PCS_IM_LEVEL4_I                         ((nv_items_enum_type) 1056)
#define  NV_GSM_1900_CAL_ARFCN_I                       ((nv_items_enum_type) 1057)
#define  NV_GSM_1900_RX_GAIN_RANGE_1_FREQ_COMP_I       ((nv_items_enum_type) 1058)
#define  NV_GSM_1900_RX_GAIN_RANGE_2_FREQ_COMP_I       ((nv_items_enum_type) 1059)
#define  NV_GSM_1900_RX_GAIN_RANGE_3_FREQ_COMP_I       ((nv_items_enum_type) 1060)
#define  NV_GSM_1900_RX_GAIN_RANGE_4_FREQ_COMP_I       ((nv_items_enum_type) 1061)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_00_I       ((nv_items_enum_type) 1062)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_01_I       ((nv_items_enum_type) 1063)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_02_I       ((nv_items_enum_type) 1064)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_03_I       ((nv_items_enum_type) 1065)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_04_I       ((nv_items_enum_type) 1066)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_05_I       ((nv_items_enum_type) 1067)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_06_I       ((nv_items_enum_type) 1068)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_07_I       ((nv_items_enum_type) 1069)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_08_I       ((nv_items_enum_type) 1070)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_09_I       ((nv_items_enum_type) 1071)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_10_I       ((nv_items_enum_type) 1072)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_11_I       ((nv_items_enum_type) 1073)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_12_I       ((nv_items_enum_type) 1074)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_13_I       ((nv_items_enum_type) 1075)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_14_I       ((nv_items_enum_type) 1076)
#define  NV_GSM_1900_TX_BURST_RAMP_UP_INDEX_15_I       ((nv_items_enum_type) 1077)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_00_I     ((nv_items_enum_type) 1078)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_01_I     ((nv_items_enum_type) 1079)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_02_I     ((nv_items_enum_type) 1080)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_03_I     ((nv_items_enum_type) 1081)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_04_I     ((nv_items_enum_type) 1082)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_05_I     ((nv_items_enum_type) 1083)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_06_I     ((nv_items_enum_type) 1084)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_07_I     ((nv_items_enum_type) 1085)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_08_I     ((nv_items_enum_type) 1086)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_09_I     ((nv_items_enum_type) 1087)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_10_I     ((nv_items_enum_type) 1088)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_11_I     ((nv_items_enum_type) 1089)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_12_I     ((nv_items_enum_type) 1090)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_13_I     ((nv_items_enum_type) 1091)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_14_I     ((nv_items_enum_type) 1092)
#define  NV_GSM_1900_TX_BURST_RAMP_DOWN_INDEX_15_I     ((nv_items_enum_type) 1093)
#define  NV_GSM_1900_PA_GAIN_SLOPE_I                   ((nv_items_enum_type) 1094)
#define  NV_GSM_1900_TX_FREQ_COMP_I                    ((nv_items_enum_type) 1095)
#define  NV_GSM_1900_VBATT_HI_PA_COMP_I                ((nv_items_enum_type) 1096)
#define  NV_GSM_1900_VBATT_LO_PA_COMP_I                ((nv_items_enum_type) 1097)
#define  NV_GSM_1900_PA_START_TIME_OFFSET_I            ((nv_items_enum_type) 1098)
#define  NV_GSM_1900_PA_STOP_TIME_OFFSET_I             ((nv_items_enum_type) 1099)
#define  NV_GSM_1900_GAINRANGE_SWITCHPOINTS_I          ((nv_items_enum_type) 1100)
#define  NV_GSM_850_CAL_ARFCN_I                        ((nv_items_enum_type) 1101)
#define  NV_GSM_850_RX_GAIN_RANGE_1_FREQ_COMP_I        ((nv_items_enum_type) 1102)
#define  NV_GSM_850_RX_GAIN_RANGE_2_FREQ_COMP_I        ((nv_items_enum_type) 1103)
#define  NV_GSM_850_RX_GAIN_RANGE_3_FREQ_COMP_I        ((nv_items_enum_type) 1104)
#define  NV_GSM_850_RX_GAIN_RANGE_4_FREQ_COMP_I        ((nv_items_enum_type) 1105)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_00_I        ((nv_items_enum_type) 1106)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_01_I        ((nv_items_enum_type) 1107)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_02_I        ((nv_items_enum_type) 1108)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_03_I        ((nv_items_enum_type) 1109)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_04_I        ((nv_items_enum_type) 1110)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_05_I        ((nv_items_enum_type) 1111)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_06_I        ((nv_items_enum_type) 1112)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_07_I        ((nv_items_enum_type) 1113)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_08_I        ((nv_items_enum_type) 1114)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_09_I        ((nv_items_enum_type) 1115)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_10_I        ((nv_items_enum_type) 1116)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_11_I        ((nv_items_enum_type) 1117)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_12_I        ((nv_items_enum_type) 1118)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_13_I        ((nv_items_enum_type) 1119)
#define  NV_GSM_850_TX_BURST_RAMP_UP_INDEX_14_I        ((nv_items_enum_type) 1120)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_00_I      ((nv_items_enum_type) 1121)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_01_I      ((nv_items_enum_type) 1122)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_02_I      ((nv_items_enum_type) 1123)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_03_I      ((nv_items_enum_type) 1124)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_04_I      ((nv_items_enum_type) 1125)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_05_I      ((nv_items_enum_type) 1126)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_06_I      ((nv_items_enum_type) 1127)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_07_I      ((nv_items_enum_type) 1128)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_08_I      ((nv_items_enum_type) 1129)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_09_I      ((nv_items_enum_type) 1130)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_10_I      ((nv_items_enum_type) 1131)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_11_I      ((nv_items_enum_type) 1132)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_12_I      ((nv_items_enum_type) 1133)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_13_I      ((nv_items_enum_type) 1134)
#define  NV_GSM_850_TX_BURST_RAMP_DOWN_INDEX_14_I      ((nv_items_enum_type) 1135)
#define  NV_GSM_850_PA_GAIN_SLOPE_I                    ((nv_items_enum_type) 1136)
#define  NV_GSM_850_TX_FREQ_COMP_I                     ((nv_items_enum_type) 1137)
#define  NV_GSM_850_VBATT_HI_PA_COMP_I                 ((nv_items_enum_type) 1138)
#define  NV_GSM_850_VBATT_LO_PA_COMP_I                 ((nv_items_enum_type) 1139)
#define  NV_GSM_850_PA_START_TIME_OFFSET_I             ((nv_items_enum_type) 1140)
#define  NV_GSM_850_PA_STOP_TIME_OFFSET_I              ((nv_items_enum_type) 1141)
#define  NV_GSM_850_GAINRANGE_SWITCHPOINTS_I           ((nv_items_enum_type) 1142)
#define  NV_WCDMA_1900_VGA_GAIN_OFFSET_I               ((nv_items_enum_type) 1143)
#define  NV_WCDMA_1900_VGA_GAIN_OFFSET_VS_FREQ_I       ((nv_items_enum_type) 1144)
#define  NV_WCDMA_1900_VGA_GAIN_OFFSET_VS_TEMP_I       ((nv_items_enum_type) 1145)
#define  NV_WCDMA_1900_LNA_RANGE_RISE_2_I              ((nv_items_enum_type) 1146)
#define  NV_WCDMA_1900_LNA_RANGE_RISE_3_I              ((nv_items_enum_type) 1147)
#define  NV_WCDMA_1900_LNA_RANGE_FALL_2_I              ((nv_items_enum_type) 1148)
#define  NV_WCDMA_1900_LNA_RANGE_FALL_3_I              ((nv_items_enum_type) 1149)
#define  NV_WCDMA_1900_IM_LEVEL_2_I                    ((nv_items_enum_type) 1150)
#define  NV_WCDMA_1900_IM_LEVEL_3_I                    ((nv_items_enum_type) 1151)
#define  NV_WCDMA_1900_LNA_RANGE_OFFSET_2_I            ((nv_items_enum_type) 1152)
#define  NV_WCDMA_1900_LNA_RANGE_OFFSET_3_I            ((nv_items_enum_type) 1153)
#define  NV_WCDMA_1900_LNA_OFFSET_VS_FREQ_2_I          ((nv_items_enum_type) 1154)
#define  NV_WCDMA_1900_LNA_OFFSET_VS_FREQ_3_I          ((nv_items_enum_type) 1155)
#define  NV_WCDMA_1900_IM2_I_VALUE_I                   ((nv_items_enum_type) 1156)
#define  NV_WCDMA_1900_IM2_Q_VALUE_I                   ((nv_items_enum_type) 1157)
#define  NV_WCDMA_1900_IM2_TRANSCONDUCTOR_VALUE_I      ((nv_items_enum_type) 1158)
#define  NV_WCDMA_1900_RX_AGC_MIN_2_I                  ((nv_items_enum_type) 1159)
#define  NV_WCDMA_1900_RX_AGC_MIN_3_I                  ((nv_items_enum_type) 1160)
#define  NV_WCDMA_1900_MAX_TX_POWER_I                  ((nv_items_enum_type) 1161)
#define  NV_WCDMA_1900_OUT_OF_SERVICE_THRESH_I         ((nv_items_enum_type) 1162)
#define  NV_WCDMA_1900_LNA_RANGE_RISE_I                ((nv_items_enum_type) 1163)
#define  NV_WCDMA_1900_LNA_RANGE_FALL_I                ((nv_items_enum_type) 1164)
#define  NV_WCDMA_1900_IM_LEVEL_I                      ((nv_items_enum_type) 1165)
#define  NV_WCDMA_1900_NONBYPASS_TIMER_I               ((nv_items_enum_type) 1166)
#define  NV_WCDMA_1900_BYPASS_TIMER_I                  ((nv_items_enum_type) 1167)
#define  NV_WCDMA_1900_LNA_RANGE_OFFSET_I              ((nv_items_enum_type) 1168)
#define  NV_WCDMA_1900_LNA_OFFSET_VS_FREQ_I            ((nv_items_enum_type) 1169)
#define  NV_WCDMA_1900_RX_AGC_MIN_I                    ((nv_items_enum_type) 1170)
#define  NV_WCDMA_1900_RX_AGC_MAX_I                    ((nv_items_enum_type) 1171)
#define  NV_WCDMA_1900_AGC_PHASE_OFFSET_I              ((nv_items_enum_type) 1172)
#define  NV_WCDMA_1900_TX_LIN_MASTER_0_I               ((nv_items_enum_type) 1173)
#define  NV_WCDMA_1900_TX_LIN_MASTER_1_I               ((nv_items_enum_type) 1174)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_0_I             ((nv_items_enum_type) 1175)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_1_I             ((nv_items_enum_type) 1176)
#define  NV_WCDMA_1900_TX_LIN_VS_TEMP_0_I              ((nv_items_enum_type) 1177)
#define  NV_WCDMA_1900_TX_LIN_VS_TEMP_1_I              ((nv_items_enum_type) 1178)
#define  NV_WCDMA_1900_TX_SLP_VS_TEMP_0_I              ((nv_items_enum_type) 1179)
#define  NV_WCDMA_1900_TX_SLP_VS_TEMP_1_I              ((nv_items_enum_type) 1180)
#define  NV_WCDMA_1900_R1_RISE_I                       ((nv_items_enum_type) 1181)
#define  NV_WCDMA_1900_R1_FALL_I                       ((nv_items_enum_type) 1182)
#define  NV_WCDMA_1900_TX_LIM_VS_TEMP_I                ((nv_items_enum_type) 1183)
#define  NV_WCDMA_1900_TX_LIM_VS_FREQ_I                ((nv_items_enum_type) 1184)
#define  NV_WCDMA_1900_ADJ_FACTOR_I                    ((nv_items_enum_type) 1185)
#define  NV_WCDMA_1900_EXP_HDET_VS_AGC_I               ((nv_items_enum_type) 1186)
#define  NV_WCDMA_1900_HDET_OFF_I                      ((nv_items_enum_type) 1187)
#define  NV_WCDMA_1900_HDET_SPN_I                      ((nv_items_enum_type) 1188)
#define  NV_WCDMA_1900_ENC_BTF_I                       ((nv_items_enum_type) 1189)
#define  NV_RPLMNACT_I                                 ((nv_items_enum_type) 1190)
#define  NV_PS_DATA_ORIG_PREF_I                        ((nv_items_enum_type) 1191)
#define  NV_HDR_AN_AUTH_PASSWD_LONG_I                  ((nv_items_enum_type) 1192)
#define  NV_DS_MIP_QC_HANDDOWN_TO_1X_OPT_I             ((nv_items_enum_type) 1193)
#define  NV_HDR_AN_AUTH_USER_ID_LONG_I                 ((nv_items_enum_type) 1194)
#define  NV_PCS_LNA_BYPASS_TIMER_0_I                   ((nv_items_enum_type) 1195)
#define  NV_WCDMA_AGC_PA_ON_RISE_DELAY_I               ((nv_items_enum_type) 1196)
#define  NV_WCDMA_AGC_PA_ON_FALL_DELAY_I               ((nv_items_enum_type) 1197)
#define  NV_WCDMA_AGC_TX_ON_RISE_DELAY_I               ((nv_items_enum_type) 1198)
#define  NV_WCDMA_AGC_TX_ON_FALL_DELAY_I               ((nv_items_enum_type) 1199)
#define  NV_WCDMA_AGC_UPDATE_TX_AGC_TIME_I             ((nv_items_enum_type) 1200)
#define  NV_WCDMA_1900_AGC_PA_ON_RISE_DELAY_I          ((nv_items_enum_type) 1201)
#define  NV_WCDMA_1900_AGC_PA_ON_FALL_DELAY_I          ((nv_items_enum_type) 1202)
#define  NV_WCDMA_1900_AGC_TX_ON_RISE_DELAY_I          ((nv_items_enum_type) 1203)
#define  NV_WCDMA_1900_AGC_TX_ON_FALL_DELAY_I          ((nv_items_enum_type) 1204)
#define  NV_WCDMA_1900_AGC_UPDATE_TX_AGC_TIME_I        ((nv_items_enum_type) 1205)
#define  NV_PPP_CONFIG_DATA_I                          ((nv_items_enum_type) 1206)
#define  NV_CELL_1X_OLTA_BACKOFF_I                     ((nv_items_enum_type) 1207)
#define  NV_CELL_HDR_OLTA_BACKOFF_I                    ((nv_items_enum_type) 1208)
#define  NV_PCS_OLTA_BACKOFF_I                         ((nv_items_enum_type) 1209)
#define  NV_BC6_TX_LIM_VS_TEMP_I                       ((nv_items_enum_type) 1210)
#define  NV_C0_BC6_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1211)
#define  NV_BC6_TX_LIN_MASTER0_I                       ((nv_items_enum_type) 1212)
#define  NV_BC6_TX_LIN_MASTER1_I                       ((nv_items_enum_type) 1213)
#define  NV_BC6_TX_COMP0_I                             ((nv_items_enum_type) 1214)
#define  NV_BC6_TX_COMP1_I                             ((nv_items_enum_type) 1215)
#define  NV_BC6_TX_LIM_VS_FREQ_I                       ((nv_items_enum_type) 1216)
#define  NV_BC6_EXP_HDET_VS_AGC_I                      ((nv_items_enum_type) 1217)
#define  NV_BC6_HDET_OFF_I                             ((nv_items_enum_type) 1218)
#define  NV_BC6_HDET_SPN_I                             ((nv_items_enum_type) 1219)
#define  NV_BC6_PA_R1_RISE_I                           ((nv_items_enum_type) 1220)
#define  NV_BC6_PA_R1_FALL_I                           ((nv_items_enum_type) 1221)
#define  NV_BC6_LNA_RANGE_POL_I                        ((nv_items_enum_type) 1222)
#define  NV_BC6_LNA_1_RISE_I                           ((nv_items_enum_type) 1223)
#define  NV_BC6_LNA_1_FALL_I                           ((nv_items_enum_type) 1224)
#define  NV_C0_BC6_LNA_RANGE_OFFSET_I                  ((nv_items_enum_type) 1225)
#define  NV_C1_BC6_LNA_RANGE_OFFSET_I                  ((nv_items_enum_type) 1226)
#define  NV_BC6_LNA_2_RISE_I                           ((nv_items_enum_type) 1227)
#define  NV_BC6_LNA_2_FALL_I                           ((nv_items_enum_type) 1228)
#define  NV_BC6_LNA_RANGE_12_OFFSET_I                  ((nv_items_enum_type) 1229)
#define  NV_C0_BC6_IM_LEVEL1_I                         ((nv_items_enum_type) 1230)
#define  NV_C0_BC6_IM_LEVEL2_I                         ((nv_items_enum_type) 1231)
#define  NV_C0_BC6_IM_LEVEL3_I                         ((nv_items_enum_type) 1232)
#define  NV_C0_BC6_IM_LEVEL4_I                         ((nv_items_enum_type) 1233)
#define  NV_C0_BC6_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1234)
#define  NV_C1_BC6_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1235)
#define  NV_BC6_AGC_PHASE_OFFSET_I                     ((nv_items_enum_type) 1236)
#define  NV_BC6_ADJ_FACTOR_I                           ((nv_items_enum_type) 1237)
#define  NV_BC6_RX_AGC_MINMAX_I                        ((nv_items_enum_type) 1238)
#define  NV_BC6_RX_AGC_MIN_11_I                        ((nv_items_enum_type) 1239)
#define  NV_BC6_ENC_BTF_I                              ((nv_items_enum_type) 1240)
#define  NV_BC6_TX_GAIN_ATTEN_LIMIT_I                  ((nv_items_enum_type) 1241)
#define  NV_BC6_LNA_3_FALL_I                           ((nv_items_enum_type) 1242)
#define  NV_BC6_LNA_3_RISE_I                           ((nv_items_enum_type) 1243)
#define  NV_BC6_LNA_3_OFFSET_I                         ((nv_items_enum_type) 1244)
#define  NV_C0_BC6_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1245)
#define  NV_C1_BC6_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1246)
#define  NV_BC6_LNA_4_FALL_I                           ((nv_items_enum_type) 1247)
#define  NV_BC6_LNA_4_RISE_I                           ((nv_items_enum_type) 1248)
#define  NV_C0_BC6_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1249)
#define  NV_C1_BC6_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1250)
#define  NV_C0_BC6_IM2_I_VALUE_I                       ((nv_items_enum_type) 1251)
#define  NV_C1_BC6_IM2_I_VALUE_I                       ((nv_items_enum_type) 1252)
#define  NV_C0_BC6_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1253)
#define  NV_C1_BC6_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1254)
#define  NV_C0_BC6_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1255)
#define  NV_C1_BC6_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1256)
#define  NV_C0_BC6_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1257)
#define  NV_C1_BC6_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1258)
#define  NV_C0_BC6_VGA_GAIN_OFFSET_VS_TEMP_I           ((nv_items_enum_type) 1259)
#define  NV_C1_BC6_VGA_GAIN_OFFSET_VS_TEMP_I           ((nv_items_enum_type) 1260)
#define  NV_BC6_P1_RISE_FALL_OFF_I                     ((nv_items_enum_type) 1261)
#define  NV_C0_BC6_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1262)
#define  NV_C1_BC6_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1263)
#define  NV_C0_BC6_P1_RISE_FALL_OFFSET_I               ((nv_items_enum_type) 1264)
#define  NV_C1_BC6_P1_RISE_FALL_OFFSET_I               ((nv_items_enum_type) 1265)
#define  NV_C0_BC6_DIGITAL_MIS_COMP_A_OFFSET_I         ((nv_items_enum_type) 1266)
#define  NV_C1_BC6_DIGITAL_MIS_COMP_A_OFFSET_I         ((nv_items_enum_type) 1267)
#define  NV_C0_BC6_DIGITAL_MIS_COMP_B_OFFSET_I         ((nv_items_enum_type) 1268)
#define  NV_C1_BC6_DIGITAL_MIS_COMP_B_OFFSET_I         ((nv_items_enum_type) 1269)
#define  NV_C0_BC6_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1270)
#define  NV_C1_BC6_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1271)
#define  NV_BC6_VCO_COARSE_TUNE_TABLE_I                ((nv_items_enum_type) 1272)
#define  NV_GSM_PA_TEMP_COMP_INDEX_00_I                ((nv_items_enum_type) 1273)
#define  NV_GSM_PA_TEMP_COMP_INDEX_01_I                ((nv_items_enum_type) 1274)
#define  NV_GSM_PA_TEMP_COMP_INDEX_02_I                ((nv_items_enum_type) 1275)
#define  NV_GSM_PA_TEMP_COMP_INDEX_03_I                ((nv_items_enum_type) 1276)
#define  NV_GSM_PA_TEMP_COMP_INDEX_04_I                ((nv_items_enum_type) 1277)
#define  NV_GSM_PA_TEMP_COMP_INDEX_05_I                ((nv_items_enum_type) 1278)
#define  NV_GSM_PA_TEMP_COMP_INDEX_06_I                ((nv_items_enum_type) 1279)
#define  NV_GSM_PA_TEMP_COMP_INDEX_07_I                ((nv_items_enum_type) 1280)
#define  NV_GSM_PA_TEMP_COMP_INDEX_08_I                ((nv_items_enum_type) 1281)
#define  NV_GSM_PA_TEMP_COMP_INDEX_09_I                ((nv_items_enum_type) 1282)
#define  NV_GSM_PA_TEMP_COMP_INDEX_10_I                ((nv_items_enum_type) 1283)
#define  NV_GSM_PA_TEMP_COMP_INDEX_11_I                ((nv_items_enum_type) 1284)
#define  NV_GSM_PA_TEMP_COMP_INDEX_12_I                ((nv_items_enum_type) 1285)
#define  NV_GSM_PA_TEMP_COMP_INDEX_13_I                ((nv_items_enum_type) 1286)
#define  NV_DCS_PA_TEMP_COMP_INDEX_00_I                ((nv_items_enum_type) 1287)
#define  NV_DCS_PA_TEMP_COMP_INDEX_01_I                ((nv_items_enum_type) 1288)
#define  NV_DCS_PA_TEMP_COMP_INDEX_02_I                ((nv_items_enum_type) 1289)
#define  NV_DCS_PA_TEMP_COMP_INDEX_03_I                ((nv_items_enum_type) 1290)
#define  NV_DCS_PA_TEMP_COMP_INDEX_04_I                ((nv_items_enum_type) 1291)
#define  NV_DCS_PA_TEMP_COMP_INDEX_05_I                ((nv_items_enum_type) 1292)
#define  NV_DCS_PA_TEMP_COMP_INDEX_06_I                ((nv_items_enum_type) 1293)
#define  NV_DCS_PA_TEMP_COMP_INDEX_07_I                ((nv_items_enum_type) 1294)
#define  NV_DCS_PA_TEMP_COMP_INDEX_08_I                ((nv_items_enum_type) 1295)
#define  NV_DCS_PA_TEMP_COMP_INDEX_09_I                ((nv_items_enum_type) 1296)
#define  NV_DCS_PA_TEMP_COMP_INDEX_10_I                ((nv_items_enum_type) 1297)
#define  NV_DCS_PA_TEMP_COMP_INDEX_11_I                ((nv_items_enum_type) 1298)
#define  NV_DCS_PA_TEMP_COMP_INDEX_12_I                ((nv_items_enum_type) 1299)
#define  NV_DCS_PA_TEMP_COMP_INDEX_13_I                ((nv_items_enum_type) 1300)
#define  NV_DCS_PA_TEMP_COMP_INDEX_14_I                ((nv_items_enum_type) 1301)
#define  NV_GSM_AMR_CALL_CONFIG_I                      ((nv_items_enum_type) 1302)
#define  NV_GSM_PA_TEMP_COMP_INT8_INDEX_14_I           ((nv_items_enum_type) 1303)
#define  NV_DCS_PA_TEMP_COMP_INT8_INDEX_15_I           ((nv_items_enum_type) 1304)
#define  NV_GMM_PTMSI_SIG_TOBE_DELETED_I               ((nv_items_enum_type) 1305)
#define  NV_C0_BC6_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1306)
#define  NV_CDMA_TX_CAL_CHAN_I                         ((nv_items_enum_type) 1307)
#define  NV_CDMA_RX_CAL_CHAN_I                         ((nv_items_enum_type) 1308)
#define  NV_PCS_RX_CAL_CHAN_I                          ((nv_items_enum_type) 1309)
#define  NV_PCS_TX_CAL_CHAN_I                          ((nv_items_enum_type) 1310)
#define  NV_SEC_DEVICE_KEY_I                           ((nv_items_enum_type) 1311)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_00_I            ((nv_items_enum_type) 1312)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_01_I            ((nv_items_enum_type) 1313)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_02_I            ((nv_items_enum_type) 1314)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_03_I            ((nv_items_enum_type) 1315)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_04_I            ((nv_items_enum_type) 1316)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_05_I            ((nv_items_enum_type) 1317)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_06_I            ((nv_items_enum_type) 1318)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_07_I            ((nv_items_enum_type) 1319)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_08_I            ((nv_items_enum_type) 1320)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_09_I            ((nv_items_enum_type) 1321)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_10_I            ((nv_items_enum_type) 1322)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_11_I            ((nv_items_enum_type) 1323)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_12_I            ((nv_items_enum_type) 1324)
#define  NV_GSM_850_PA_TEMP_COMP_INDEX_13_I            ((nv_items_enum_type) 1325)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_00_I           ((nv_items_enum_type) 1326)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_01_I           ((nv_items_enum_type) 1327)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_02_I           ((nv_items_enum_type) 1328)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_03_I           ((nv_items_enum_type) 1329)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_04_I           ((nv_items_enum_type) 1330)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_05_I           ((nv_items_enum_type) 1331)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_06_I           ((nv_items_enum_type) 1332)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_07_I           ((nv_items_enum_type) 1333)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_08_I           ((nv_items_enum_type) 1334)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_09_I           ((nv_items_enum_type) 1335)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_10_I           ((nv_items_enum_type) 1336)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_11_I           ((nv_items_enum_type) 1337)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_12_I           ((nv_items_enum_type) 1338)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_13_I           ((nv_items_enum_type) 1339)
#define  NV_GSM_1900_PA_TEMP_COMP_INDEX_14_I           ((nv_items_enum_type) 1340)
#define  NV_TCP_GRACEFUL_DORMANT_CLOSE_I               ((nv_items_enum_type) 1341)
#define  NV_INTERFREQ_ENABLED_I                        ((nv_items_enum_type) 1342)
#define  NV_EPLMN_ENABLED_I                            ((nv_items_enum_type) 1343)
#define  NV_DTMF_I                                     ((nv_items_enum_type) 1344)
#define  NV_TRK_LO_ADJ_DEFAULT_I                       ((nv_items_enum_type) 1345)
#define  NV_TRK_LO_ADJ_SLOPE_DEFAULT_I                 ((nv_items_enum_type) 1346)
#define  NV_WCDMA_PA_GAIN_UP_TIME_I                    ((nv_items_enum_type) 1347)
#define  NV_WCDMA_PA_GAIN_DOWN_TIME_I                  ((nv_items_enum_type) 1348)
#define  NV_BC6_GPS1_RF_DELAY_I                        ((nv_items_enum_type) 1349)
#define  NV_BC6_RF_TUNE_RESERVED_I                     ((nv_items_enum_type) 1350)
#define  NV_BC6_TX_LIN_MASTER2_I                       ((nv_items_enum_type) 1351)
#define  NV_BC6_TX_LIN_MASTER3_I                       ((nv_items_enum_type) 1352)
#define  NV_BC6_TX_COMP2_I                             ((nv_items_enum_type) 1353)
#define  NV_BC6_TX_COMP3_I                             ((nv_items_enum_type) 1354)
#define  NV_BC6_PA_R2_RISE_I                           ((nv_items_enum_type) 1355)
#define  NV_BC6_PA_R2_FALL_I                           ((nv_items_enum_type) 1356)
#define  NV_BC6_PA_R3_RISE_I                           ((nv_items_enum_type) 1357)
#define  NV_BC6_PA_R3_FALL_I                           ((nv_items_enum_type) 1358)
#define  NV_C0_BC6_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1359)
#define  NV_C0_BC6_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1360)
#define  NV_C0_BC6_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1361)
#define  NV_C0_BC6_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1362)
#define  NV_C0_BC6_LNA_1_RISE_I                        ((nv_items_enum_type) 1363)
#define  NV_C0_BC6_LNA_1_FALL_I                        ((nv_items_enum_type) 1364)
#define  NV_C0_BC6_LNA_2_RISE_I                        ((nv_items_enum_type) 1365)
#define  NV_C0_BC6_LNA_2_FALL_I                        ((nv_items_enum_type) 1366)
#define  NV_C0_BC6_LNA_3_RISE_I                        ((nv_items_enum_type) 1367)
#define  NV_C0_BC6_LNA_3_FALL_I                        ((nv_items_enum_type) 1368)
#define  NV_C0_BC6_LNA_4_RISE_I                        ((nv_items_enum_type) 1369)
#define  NV_C0_BC6_LNA_4_FALL_I                        ((nv_items_enum_type) 1370)
#define  NV_C1_BC6_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1371)
#define  NV_C1_BC6_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1372)
#define  NV_C1_BC6_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1373)
#define  NV_C1_BC6_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1374)
#define  NV_C1_BC6_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1375)
#define  NV_C1_BC6_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1376)
#define  NV_C1_BC6_LNA_1_RISE_I                        ((nv_items_enum_type) 1377)
#define  NV_C1_BC6_LNA_1_FALL_I                        ((nv_items_enum_type) 1378)
#define  NV_C1_BC6_LNA_2_RISE_I                        ((nv_items_enum_type) 1379)
#define  NV_C1_BC6_LNA_2_FALL_I                        ((nv_items_enum_type) 1380)
#define  NV_C1_BC6_LNA_3_RISE_I                        ((nv_items_enum_type) 1381)
#define  NV_C1_BC6_LNA_3_FALL_I                        ((nv_items_enum_type) 1382)
#define  NV_C1_BC6_LNA_4_RISE_I                        ((nv_items_enum_type) 1383)
#define  NV_C1_BC6_LNA_4_FALL_I                        ((nv_items_enum_type) 1384)
#define  NV_C1_BC6_IM_LEVEL1_I                         ((nv_items_enum_type) 1385)
#define  NV_C1_BC6_IM_LEVEL2_I                         ((nv_items_enum_type) 1386)
#define  NV_C1_BC6_IM_LEVEL3_I                         ((nv_items_enum_type) 1387)
#define  NV_C1_BC6_IM_LEVEL4_I                         ((nv_items_enum_type) 1388)
#define  NV_BC5_GPS1_RF_DELAY_I                        ((nv_items_enum_type) 1389)
#define  NV_BC5_RF_TUNE_RESERVED_I                     ((nv_items_enum_type) 1390)
#define  NV_BC5_TX_LIM_VS_TEMP_I                       ((nv_items_enum_type) 1391)
#define  NV_BC5_TX_LIN_MASTER0_I                       ((nv_items_enum_type) 1392)
#define  NV_BC5_TX_LIN_MASTER1_I                       ((nv_items_enum_type) 1393)
#define  NV_BC5_TX_LIN_MASTER2_I                       ((nv_items_enum_type) 1394)
#define  NV_BC5_TX_LIN_MASTER3_I                       ((nv_items_enum_type) 1395)
#define  NV_BC5_TX_COMP0_I                             ((nv_items_enum_type) 1396)
#define  NV_BC5_TX_COMP1_I                             ((nv_items_enum_type) 1397)
#define  NV_BC5_TX_COMP2_I                             ((nv_items_enum_type) 1398)
#define  NV_BC5_TX_COMP3_I                             ((nv_items_enum_type) 1399)
#define  NV_BC5_TX_LIM_VS_FREQ_I                       ((nv_items_enum_type) 1400)
#define  NV_BC5_PA_R1_RISE_I                           ((nv_items_enum_type) 1401)
#define  NV_BC5_PA_R1_FALL_I                           ((nv_items_enum_type) 1402)
#define  NV_BC5_PA_R2_RISE_I                           ((nv_items_enum_type) 1403)
#define  NV_BC5_PA_R2_FALL_I                           ((nv_items_enum_type) 1404)
#define  NV_BC5_PA_R3_RISE_I                           ((nv_items_enum_type) 1405)
#define  NV_BC5_PA_R3_FALL_I                           ((nv_items_enum_type) 1406)
#define  NV_BC5_HDET_OFF_I                             ((nv_items_enum_type) 1407)
#define  NV_BC5_HDET_SPN_I                             ((nv_items_enum_type) 1408)
#define  NV_BC5_EXP_HDET_VS_AGC_I                      ((nv_items_enum_type) 1409)
#define  NV_BC5_ENC_BTF_I                              ((nv_items_enum_type) 1410)
#define  NV_BC5_VCO_COARSE_TUNE_TABLE_I                ((nv_items_enum_type) 1411)
#define  NV_BC5_P1_RISE_FALL_OFF_I                     ((nv_items_enum_type) 1412)
#define  NV_C0_BC5_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1413)
#define  NV_C0_BC5_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1414)
#define  NV_C0_BC5_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1415)
#define  NV_C0_BC5_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1416)
#define  NV_C0_BC5_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1417)
#define  NV_C0_BC5_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1418)
#define  NV_C0_BC5_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1419)
#define  NV_C0_BC5_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1420)
#define  NV_C0_BC5_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1421)
#define  NV_C0_BC5_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1422)
#define  NV_C0_BC5_IM2_I_VALUE_I                       ((nv_items_enum_type) 1423)
#define  NV_C0_BC5_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1424)
#define  NV_C0_BC5_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1425)
#define  NV_C0_BC5_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1426)
#define  NV_C0_BC5_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1427)
#define  NV_C0_BC5_LNA_1_RISE_I                        ((nv_items_enum_type) 1428)
#define  NV_C0_BC5_LNA_1_FALL_I                        ((nv_items_enum_type) 1429)
#define  NV_C0_BC5_LNA_2_RISE_I                        ((nv_items_enum_type) 1430)
#define  NV_C0_BC5_LNA_2_FALL_I                        ((nv_items_enum_type) 1431)
#define  NV_C0_BC5_LNA_3_RISE_I                        ((nv_items_enum_type) 1432)
#define  NV_C0_BC5_LNA_3_FALL_I                        ((nv_items_enum_type) 1433)
#define  NV_C0_BC5_LNA_4_RISE_I                        ((nv_items_enum_type) 1434)
#define  NV_C0_BC5_LNA_4_FALL_I                        ((nv_items_enum_type) 1435)
#define  NV_C0_BC5_IM_LEVEL1_I                         ((nv_items_enum_type) 1436)
#define  NV_C0_BC5_IM_LEVEL2_I                         ((nv_items_enum_type) 1437)
#define  NV_C0_BC5_IM_LEVEL3_I                         ((nv_items_enum_type) 1438)
#define  NV_C0_BC5_IM_LEVEL4_I                         ((nv_items_enum_type) 1439)
#define  NV_C1_BC5_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1440)
#define  NV_C1_BC5_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1441)
#define  NV_C1_BC5_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1442)
#define  NV_C1_BC5_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1443)
#define  NV_C1_BC5_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1444)
#define  NV_C1_BC5_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1445)
#define  NV_C1_BC5_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1446)
#define  NV_C1_BC5_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1447)
#define  NV_C1_BC5_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1448)
#define  NV_C1_BC5_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1449)
#define  NV_C1_BC5_IM2_I_VALUE_I                       ((nv_items_enum_type) 1450)
#define  NV_C1_BC5_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1451)
#define  NV_C1_BC5_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1452)
#define  NV_C1_BC5_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1453)
#define  NV_C1_BC5_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1454)
#define  NV_C1_BC5_LNA_1_RISE_I                        ((nv_items_enum_type) 1455)
#define  NV_C1_BC5_LNA_1_FALL_I                        ((nv_items_enum_type) 1456)
#define  NV_C1_BC5_LNA_2_RISE_I                        ((nv_items_enum_type) 1457)
#define  NV_C1_BC5_LNA_2_FALL_I                        ((nv_items_enum_type) 1458)
#define  NV_C1_BC5_LNA_3_RISE_I                        ((nv_items_enum_type) 1459)
#define  NV_C1_BC5_LNA_3_FALL_I                        ((nv_items_enum_type) 1460)
#define  NV_C1_BC5_LNA_4_RISE_I                        ((nv_items_enum_type) 1461)
#define  NV_C1_BC5_LNA_4_FALL_I                        ((nv_items_enum_type) 1462)
#define  NV_C1_BC5_IM_LEVEL1_I                         ((nv_items_enum_type) 1463)
#define  NV_C1_BC5_IM_LEVEL2_I                         ((nv_items_enum_type) 1464)
#define  NV_C1_BC5_IM_LEVEL3_I                         ((nv_items_enum_type) 1465)
#define  NV_C1_BC5_IM_LEVEL4_I                         ((nv_items_enum_type) 1466)
#define  NV_BC4_GPS1_RF_DELAY_I                        ((nv_items_enum_type) 1467)
#define  NV_BC4_RF_TUNE_RESERVED_I                     ((nv_items_enum_type) 1468)
#define  NV_BC4_TX_LIM_VS_TEMP_I                       ((nv_items_enum_type) 1469)
#define  NV_BC4_TX_LIN_MASTER0_I                       ((nv_items_enum_type) 1470)
#define  NV_BC4_TX_LIN_MASTER1_I                       ((nv_items_enum_type) 1471)
#define  NV_BC4_TX_LIN_MASTER2_I                       ((nv_items_enum_type) 1472)
#define  NV_BC4_TX_LIN_MASTER3_I                       ((nv_items_enum_type) 1473)
#define  NV_BC4_TX_COMP0_I                             ((nv_items_enum_type) 1474)
#define  NV_BC4_TX_COMP1_I                             ((nv_items_enum_type) 1475)
#define  NV_BC4_TX_COMP2_I                             ((nv_items_enum_type) 1476)
#define  NV_BC4_TX_COMP3_I                             ((nv_items_enum_type) 1477)
#define  NV_BC4_TX_LIM_VS_FREQ_I                       ((nv_items_enum_type) 1478)
#define  NV_BC4_PA_R1_RISE_I                           ((nv_items_enum_type) 1479)
#define  NV_BC4_PA_R1_FALL_I                           ((nv_items_enum_type) 1480)
#define  NV_BC4_PA_R2_RISE_I                           ((nv_items_enum_type) 1481)
#define  NV_BC4_PA_R2_FALL_I                           ((nv_items_enum_type) 1482)
#define  NV_BC4_PA_R3_RISE_I                           ((nv_items_enum_type) 1483)
#define  NV_BC4_PA_R3_FALL_I                           ((nv_items_enum_type) 1484)
#define  NV_BC4_HDET_OFF_I                             ((nv_items_enum_type) 1485)
#define  NV_BC4_HDET_SPN_I                             ((nv_items_enum_type) 1486)
#define  NV_BC4_EXP_HDET_VS_AGC_I                      ((nv_items_enum_type) 1487)
#define  NV_BC4_ENC_BTF_I                              ((nv_items_enum_type) 1488)
#define  NV_BC4_VCO_COARSE_TUNE_TABLE_I                ((nv_items_enum_type) 1489)
#define  NV_BC4_P1_RISE_FALL_OFF_I                     ((nv_items_enum_type) 1490)
#define  NV_C0_BC4_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1491)
#define  NV_C0_BC4_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1492)
#define  NV_C0_BC4_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1493)
#define  NV_C0_BC4_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1494)
#define  NV_C0_BC4_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1495)
#define  NV_C0_BC4_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1496)
#define  NV_C0_BC4_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1497)
#define  NV_C0_BC4_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1498)
#define  NV_C0_BC4_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1499)
#define  NV_C0_BC4_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1500)
#define  NV_C0_BC4_IM2_I_VALUE_I                       ((nv_items_enum_type) 1501)
#define  NV_C0_BC4_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1502)
#define  NV_C0_BC4_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1503)
#define  NV_C0_BC4_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1504)
#define  NV_C0_BC4_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1505)
#define  NV_C0_BC4_LNA_1_RISE_I                        ((nv_items_enum_type) 1506)
#define  NV_C0_BC4_LNA_1_FALL_I                        ((nv_items_enum_type) 1507)
#define  NV_C0_BC4_LNA_2_RISE_I                        ((nv_items_enum_type) 1508)
#define  NV_C0_BC4_LNA_2_FALL_I                        ((nv_items_enum_type) 1509)
#define  NV_C0_BC4_LNA_3_RISE_I                        ((nv_items_enum_type) 1510)
#define  NV_C0_BC4_LNA_3_FALL_I                        ((nv_items_enum_type) 1511)
#define  NV_C0_BC4_LNA_4_RISE_I                        ((nv_items_enum_type) 1512)
#define  NV_C0_BC4_LNA_4_FALL_I                        ((nv_items_enum_type) 1513)
#define  NV_C0_BC4_IM_LEVEL1_I                         ((nv_items_enum_type) 1514)
#define  NV_C0_BC4_IM_LEVEL2_I                         ((nv_items_enum_type) 1515)
#define  NV_C0_BC4_IM_LEVEL3_I                         ((nv_items_enum_type) 1516)
#define  NV_C0_BC4_IM_LEVEL4_I                         ((nv_items_enum_type) 1517)
#define  NV_C1_BC4_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1518)
#define  NV_C1_BC4_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1519)
#define  NV_C1_BC4_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1520)
#define  NV_C1_BC4_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1521)
#define  NV_C1_BC4_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1522)
#define  NV_C1_BC4_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1523)
#define  NV_C1_BC4_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1524)
#define  NV_C1_BC4_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1525)
#define  NV_C1_BC4_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1526)
#define  NV_C1_BC4_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1527)
#define  NV_C1_BC4_IM2_I_VALUE_I                       ((nv_items_enum_type) 1528)
#define  NV_C1_BC4_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1529)
#define  NV_C1_BC4_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1530)
#define  NV_C1_BC4_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1531)
#define  NV_C1_BC4_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1532)
#define  NV_C1_BC4_LNA_1_RISE_I                        ((nv_items_enum_type) 1533)
#define  NV_C1_BC4_LNA_1_FALL_I                        ((nv_items_enum_type) 1534)
#define  NV_C1_BC4_LNA_2_RISE_I                        ((nv_items_enum_type) 1535)
#define  NV_C1_BC4_LNA_2_FALL_I                        ((nv_items_enum_type) 1536)
#define  NV_C1_BC4_LNA_3_RISE_I                        ((nv_items_enum_type) 1537)
#define  NV_C1_BC4_LNA_3_FALL_I                        ((nv_items_enum_type) 1538)
#define  NV_C1_BC4_LNA_4_RISE_I                        ((nv_items_enum_type) 1539)
#define  NV_C1_BC4_LNA_4_FALL_I                        ((nv_items_enum_type) 1540)
#define  NV_C1_BC4_IM_LEVEL1_I                         ((nv_items_enum_type) 1541)
#define  NV_C1_BC4_IM_LEVEL2_I                         ((nv_items_enum_type) 1542)
#define  NV_C1_BC4_IM_LEVEL3_I                         ((nv_items_enum_type) 1543)
#define  NV_C1_BC4_IM_LEVEL4_I                         ((nv_items_enum_type) 1544)
#define  NV_BC3_GPS1_RF_DELAY_I                        ((nv_items_enum_type) 1545)
#define  NV_BC3_RF_TUNE_RESERVED_I                     ((nv_items_enum_type) 1546)
#define  NV_BC3_TX_LIM_VS_TEMP_I                       ((nv_items_enum_type) 1547)
#define  NV_BC3_TX_LIN_MASTER0_I                       ((nv_items_enum_type) 1548)
#define  NV_BC3_TX_LIN_MASTER1_I                       ((nv_items_enum_type) 1549)
#define  NV_BC3_TX_LIN_MASTER2_I                       ((nv_items_enum_type) 1550)
#define  NV_BC3_TX_LIN_MASTER3_I                       ((nv_items_enum_type) 1551)
#define  NV_BC3_TX_COMP0_I                             ((nv_items_enum_type) 1552)
#define  NV_BC3_TX_COMP1_I                             ((nv_items_enum_type) 1553)
#define  NV_BC3_TX_COMP2_I                             ((nv_items_enum_type) 1554)
#define  NV_BC3_TX_COMP3_I                             ((nv_items_enum_type) 1555)
#define  NV_BC3_TX_LIM_VS_FREQ_I                       ((nv_items_enum_type) 1557)
#define  NV_BC3_PA_R1_RISE_I                           ((nv_items_enum_type) 1558)
#define  NV_BC3_PA_R1_FALL_I                           ((nv_items_enum_type) 1559)
#define  NV_BC3_PA_R2_RISE_I                           ((nv_items_enum_type) 1560)
#define  NV_BC3_PA_R2_FALL_I                           ((nv_items_enum_type) 1561)
#define  NV_BC3_PA_R3_RISE_I                           ((nv_items_enum_type) 1562)
#define  NV_BC3_PA_R3_FALL_I                           ((nv_items_enum_type) 1563)
#define  NV_BC3_HDET_OFF_I                             ((nv_items_enum_type) 1564)
#define  NV_BC3_HDET_SPN_I                             ((nv_items_enum_type) 1565)
#define  NV_BC3_EXP_HDET_VS_AGC_I                      ((nv_items_enum_type) 1566)
#define  NV_BC3_ENC_BTF_I                              ((nv_items_enum_type) 1567)
#define  NV_BC3_VCO_COARSE_TUNE_TABLE_I                ((nv_items_enum_type) 1568)
#define  NV_BC3_P1_RISE_FALL_OFF_I                     ((nv_items_enum_type) 1569)
#define  NV_C0_BC3_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1570)
#define  NV_C0_BC3_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1571)
#define  NV_C0_BC3_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1572)
#define  NV_C0_BC3_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1573)
#define  NV_C0_BC3_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1574)
#define  NV_C0_BC3_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1575)
#define  NV_C0_BC3_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1576)
#define  NV_C0_BC3_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1577)
#define  NV_C0_BC3_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1578)
#define  NV_C0_BC3_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1579)
#define  NV_C0_BC3_IM2_I_VALUE_I                       ((nv_items_enum_type) 1580)
#define  NV_C0_BC3_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1581)
#define  NV_C0_BC3_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1582)
#define  NV_C0_BC3_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1583)
#define  NV_C0_BC3_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1584)
#define  NV_C0_BC3_LNA_1_RISE_I                        ((nv_items_enum_type) 1585)
#define  NV_C0_BC3_LNA_1_FALL_I                        ((nv_items_enum_type) 1586)
#define  NV_C0_BC3_LNA_2_RISE_I                        ((nv_items_enum_type) 1587)
#define  NV_C0_BC3_LNA_2_FALL_I                        ((nv_items_enum_type) 1588)
#define  NV_C0_BC3_LNA_3_RISE_I                        ((nv_items_enum_type) 1589)
#define  NV_C0_BC3_LNA_3_FALL_I                        ((nv_items_enum_type) 1590)
#define  NV_C0_BC3_LNA_4_RISE_I                        ((nv_items_enum_type) 1591)
#define  NV_C0_BC3_LNA_4_FALL_I                        ((nv_items_enum_type) 1592)
#define  NV_C0_BC3_IM_LEVEL1_I                         ((nv_items_enum_type) 1593)
#define  NV_C0_BC3_IM_LEVEL2_I                         ((nv_items_enum_type) 1594)
#define  NV_C0_BC3_IM_LEVEL3_I                         ((nv_items_enum_type) 1595)
#define  NV_C0_BC3_IM_LEVEL4_I                         ((nv_items_enum_type) 1596)
#define  NV_C1_BC3_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1597)
#define  NV_C1_BC3_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1598)
#define  NV_C1_BC3_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1599)
#define  NV_C1_BC3_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1600)
#define  NV_C1_BC3_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1601)
#define  NV_C1_BC3_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1602)
#define  NV_C1_BC3_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1603)
#define  NV_C1_BC3_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1604)
#define  NV_C1_BC3_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1605)
#define  NV_C1_BC3_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1606)
#define  NV_C1_BC3_IM2_I_VALUE_I                       ((nv_items_enum_type) 1607)
#define  NV_C1_BC3_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1608)
#define  NV_C1_BC3_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1609)
#define  NV_C1_BC3_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1610)
#define  NV_C1_BC3_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1611)
#define  NV_C1_BC3_LNA_1_RISE_I                        ((nv_items_enum_type) 1612)
#define  NV_C1_BC3_LNA_1_FALL_I                        ((nv_items_enum_type) 1613)
#define  NV_C1_BC3_LNA_2_RISE_I                        ((nv_items_enum_type) 1614)
#define  NV_C1_BC3_LNA_2_FALL_I                        ((nv_items_enum_type) 1615)
#define  NV_C1_BC3_LNA_3_RISE_I                        ((nv_items_enum_type) 1616)
#define  NV_C1_BC3_LNA_3_FALL_I                        ((nv_items_enum_type) 1617)
#define  NV_C1_BC3_LNA_4_RISE_I                        ((nv_items_enum_type) 1618)
#define  NV_C1_BC3_LNA_4_FALL_I                        ((nv_items_enum_type) 1619)
#define  NV_C1_BC3_IM_LEVEL1_I                         ((nv_items_enum_type) 1620)
#define  NV_C1_BC3_IM_LEVEL2_I                         ((nv_items_enum_type) 1621)
#define  NV_C1_BC3_IM_LEVEL3_I                         ((nv_items_enum_type) 1622)
#define  NV_C1_BC3_IM_LEVEL4_I                         ((nv_items_enum_type) 1623)
#define  NV_BC1_GPS1_RF_DELAY_I                        ((nv_items_enum_type) 1624)
#define  NV_BC1_RF_TUNE_RESERVED_I                     ((nv_items_enum_type) 1625)
#define  NV_BC1_TX_LIM_VS_TEMP_I                       ((nv_items_enum_type) 1626)
#define  NV_BC1_TX_LIN_MASTER0_I                       ((nv_items_enum_type) 1627)
#define  NV_BC1_TX_LIN_MASTER1_I                       ((nv_items_enum_type) 1628)
#define  NV_BC1_TX_LIN_MASTER2_I                       ((nv_items_enum_type) 1629)
#define  NV_BC1_TX_LIN_MASTER3_I                       ((nv_items_enum_type) 1630)
#define  NV_BC1_TX_COMP0_I                             ((nv_items_enum_type) 1631)
#define  NV_BC1_TX_COMP1_I                             ((nv_items_enum_type) 1632)
#define  NV_BC1_TX_COMP2_I                             ((nv_items_enum_type) 1633)
#define  NV_BC1_TX_COMP3_I                             ((nv_items_enum_type) 1634)
#define  NV_BC1_TX_LIM_VS_FREQ_I                       ((nv_items_enum_type) 1635)
#define  NV_BC1_PA_R1_RISE_I                           ((nv_items_enum_type) 1636)
#define  NV_BC1_PA_R1_FALL_I                           ((nv_items_enum_type) 1637)
#define  NV_BC1_PA_R2_RISE_I                           ((nv_items_enum_type) 1638)
#define  NV_BC1_PA_R2_FALL_I                           ((nv_items_enum_type) 1639)
#define  NV_BC1_PA_R3_RISE_I                           ((nv_items_enum_type) 1640)
#define  NV_BC1_PA_R3_FALL_I                           ((nv_items_enum_type) 1641)
#define  NV_BC1_HDET_OFF_I                             ((nv_items_enum_type) 1642)
#define  NV_BC1_HDET_SPN_I                             ((nv_items_enum_type) 1643)
#define  NV_BC1_EXP_HDET_VS_AGC_I                      ((nv_items_enum_type) 1644)
#define  NV_BC1_ENC_BTF_I                              ((nv_items_enum_type) 1645)
#define  NV_BC1_VCO_COARSE_TUNE_TABLE_I                ((nv_items_enum_type) 1646)
#define  NV_BC1_P1_RISE_FALL_OFF_I                     ((nv_items_enum_type) 1647)
#define  NV_C0_BC1_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1648)
#define  NV_C0_BC1_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1649)
#define  NV_C0_BC1_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1650)
#define  NV_C0_BC1_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1651)
#define  NV_C0_BC1_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1652)
#define  NV_C0_BC1_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1653)
#define  NV_C0_BC1_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1654)
#define  NV_C0_BC1_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1655)
#define  NV_C0_BC1_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1666)
#define  NV_C0_BC1_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1667)
#define  NV_C0_BC1_IM2_I_VALUE_I                       ((nv_items_enum_type) 1668)
#define  NV_C0_BC1_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1669)
#define  NV_C0_BC1_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1670)
#define  NV_C0_BC1_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1671)
#define  NV_C0_BC1_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1672)
#define  NV_C0_BC1_LNA_1_RISE_I                        ((nv_items_enum_type) 1673)
#define  NV_C0_BC1_LNA_1_FALL_I                        ((nv_items_enum_type) 1674)
#define  NV_C0_BC1_LNA_2_RISE_I                        ((nv_items_enum_type) 1675)
#define  NV_C0_BC1_LNA_2_FALL_I                        ((nv_items_enum_type) 1676)
#define  NV_C0_BC1_LNA_3_RISE_I                        ((nv_items_enum_type) 1677)
#define  NV_C0_BC1_LNA_3_FALL_I                        ((nv_items_enum_type) 1678)
#define  NV_C0_BC1_LNA_4_RISE_I                        ((nv_items_enum_type) 1679)
#define  NV_C0_BC1_LNA_4_FALL_I                        ((nv_items_enum_type) 1680)
#define  NV_C0_BC1_IM_LEVEL1_I                         ((nv_items_enum_type) 1681)
#define  NV_C0_BC1_IM_LEVEL2_I                         ((nv_items_enum_type) 1682)
#define  NV_C0_BC1_IM_LEVEL3_I                         ((nv_items_enum_type) 1683)
#define  NV_C0_BC1_IM_LEVEL4_I                         ((nv_items_enum_type) 1684)
#define  NV_C1_BC1_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1685)
#define  NV_C1_BC1_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1686)
#define  NV_C1_BC1_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1687)
#define  NV_C1_BC1_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1689)
#define  NV_C1_BC1_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1690)
#define  NV_C1_BC1_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1691)
#define  NV_C1_BC1_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1692)
#define  NV_C1_BC1_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1693)
#define  NV_C1_BC1_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1694)
#define  NV_C1_BC1_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1695)
#define  NV_C1_BC1_IM2_I_VALUE_I                       ((nv_items_enum_type) 1696)
#define  NV_C1_BC1_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1697)
#define  NV_C1_BC1_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1698)
#define  NV_C1_BC1_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1699)
#define  NV_C1_BC1_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1700)
#define  NV_C1_BC1_LNA_1_RISE_I                        ((nv_items_enum_type) 1701)
#define  NV_C1_BC1_LNA_1_FALL_I                        ((nv_items_enum_type) 1702)
#define  NV_C1_BC1_LNA_2_RISE_I                        ((nv_items_enum_type) 1703)
#define  NV_C1_BC1_LNA_2_FALL_I                        ((nv_items_enum_type) 1704)
#define  NV_C1_BC1_LNA_3_RISE_I                        ((nv_items_enum_type) 1705)
#define  NV_C1_BC1_LNA_3_FALL_I                        ((nv_items_enum_type) 1706)
#define  NV_C1_BC1_LNA_4_RISE_I                        ((nv_items_enum_type) 1707)
#define  NV_C1_BC1_LNA_4_FALL_I                        ((nv_items_enum_type) 1708)
#define  NV_C1_BC1_IM_LEVEL1_I                         ((nv_items_enum_type) 1709)
#define  NV_C1_BC1_IM_LEVEL2_I                         ((nv_items_enum_type) 1710)
#define  NV_C1_BC1_IM_LEVEL3_I                         ((nv_items_enum_type) 1711)
#define  NV_C1_BC1_IM_LEVEL4_I                         ((nv_items_enum_type) 1712)
#define  NV_BC0_GPS1_RF_DELAY_I                        ((nv_items_enum_type) 1713)
#define  NV_BC0_RF_TUNE_RESERVED_I                     ((nv_items_enum_type) 1714)
#define  NV_BC0_TX_LIM_VS_TEMP_I                       ((nv_items_enum_type) 1715)
#define  NV_BC0_TX_LIN_MASTER0_I                       ((nv_items_enum_type) 1716)
#define  NV_BC0_TX_LIN_MASTER1_I                       ((nv_items_enum_type) 1717)
#define  NV_BC0_TX_LIN_MASTER2_I                       ((nv_items_enum_type) 1718)
#define  NV_BC0_TX_LIN_MASTER3_I                       ((nv_items_enum_type) 1719)
#define  NV_BC0_TX_COMP0_I                             ((nv_items_enum_type) 1720)
#define  NV_BC0_TX_COMP1_I                             ((nv_items_enum_type) 1721)
#define  NV_BC0_TX_COMP2_I                             ((nv_items_enum_type) 1722)
#define  NV_BC0_TX_COMP3_I                             ((nv_items_enum_type) 1723)
#define  NV_BC0_TX_LIM_VS_FREQ_I                       ((nv_items_enum_type) 1724)
#define  NV_BC0_PA_R1_RISE_I                           ((nv_items_enum_type) 1725)
#define  NV_BC0_PA_R1_FALL_I                           ((nv_items_enum_type) 1726)
#define  NV_BC0_PA_R2_RISE_I                           ((nv_items_enum_type) 1727)
#define  NV_BC0_PA_R2_FALL_I                           ((nv_items_enum_type) 1728)
#define  NV_BC0_PA_R3_RISE_I                           ((nv_items_enum_type) 1729)
#define  NV_BC0_PA_R3_FALL_I                           ((nv_items_enum_type) 1730)
#define  NV_BC0_HDET_OFF_I                             ((nv_items_enum_type) 1731)
#define  NV_BC0_HDET_SPN_I                             ((nv_items_enum_type) 1732)
#define  NV_BC0_EXP_HDET_VS_AGC_I                      ((nv_items_enum_type) 1733)
#define  NV_BC0_ENC_BTF_I                              ((nv_items_enum_type) 1734)
#define  NV_BC0_VCO_COARSE_TUNE_TABLE_I                ((nv_items_enum_type) 1735)
#define  NV_BC0_P1_RISE_FALL_OFF_I                     ((nv_items_enum_type) 1736)
#define  NV_C0_BC0_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1737)
#define  NV_C0_BC0_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1738)
#define  NV_C0_BC0_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1739)
#define  NV_C0_BC0_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1740)
#define  NV_C0_BC0_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1741)
#define  NV_C0_BC0_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1742)
#define  NV_C0_BC0_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1743)
#define  NV_C0_BC0_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1744)
#define  NV_C0_BC0_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1745)
#define  NV_C0_BC0_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1746)
#define  NV_C0_BC0_IM2_I_VALUE_I                       ((nv_items_enum_type) 1747)
#define  NV_C0_BC0_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1748)
#define  NV_C0_BC0_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1749)
#define  NV_C0_BC0_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1750)
#define  NV_C0_BC0_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1751)
#define  NV_C0_BC0_LNA_1_RISE_I                        ((nv_items_enum_type) 1752)
#define  NV_C0_BC0_LNA_1_FALL_I                        ((nv_items_enum_type) 1753)
#define  NV_C0_BC0_LNA_2_RISE_I                        ((nv_items_enum_type) 1754)
#define  NV_C0_BC0_LNA_2_FALL_I                        ((nv_items_enum_type) 1755)
#define  NV_C0_BC0_LNA_3_RISE_I                        ((nv_items_enum_type) 1756)
#define  NV_C0_BC0_LNA_3_FALL_I                        ((nv_items_enum_type) 1757)
#define  NV_C0_BC0_LNA_4_RISE_I                        ((nv_items_enum_type) 1758)
#define  NV_C0_BC0_LNA_4_FALL_I                        ((nv_items_enum_type) 1759)
#define  NV_C0_BC0_IM_LEVEL1_I                         ((nv_items_enum_type) 1760)
#define  NV_C0_BC0_IM_LEVEL2_I                         ((nv_items_enum_type) 1761)
#define  NV_C0_BC0_IM_LEVEL3_I                         ((nv_items_enum_type) 1762)
#define  NV_C0_BC0_IM_LEVEL4_I                         ((nv_items_enum_type) 1763)
#define  NV_C1_BC0_TX_CAL_CHAN_I                       ((nv_items_enum_type) 1764)
#define  NV_C1_BC0_RX_CAL_CHAN_I                       ((nv_items_enum_type) 1765)
#define  NV_C1_BC0_LNA_1_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1766)
#define  NV_C1_BC0_LNA_2_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1767)
#define  NV_C1_BC0_LNA_3_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1768)
#define  NV_C1_BC0_LNA_4_OFFSET_VS_FREQ_I              ((nv_items_enum_type) 1769)
#define  NV_C1_BC0_LNA_1_OFFSET_I                      ((nv_items_enum_type) 1770)
#define  NV_C1_BC0_LNA_2_OFFSET_I                      ((nv_items_enum_type) 1771)
#define  NV_C1_BC0_LNA_3_OFFSET_I                      ((nv_items_enum_type) 1772)
#define  NV_C1_BC0_LNA_4_OFFSET_I                      ((nv_items_enum_type) 1773)
#define  NV_C1_BC0_IM2_I_VALUE_I                       ((nv_items_enum_type) 1774)
#define  NV_C1_BC0_IM2_Q_VALUE_I                       ((nv_items_enum_type) 1775)
#define  NV_C1_BC0_VGA_GAIN_OFFSET_I                   ((nv_items_enum_type) 1776)
#define  NV_C1_BC0_VGA_GAIN_OFFSET_VS_FREQ_I           ((nv_items_enum_type) 1777)
#define  NV_C1_BC0_IM2_TRANSCONDUCTOR_VALUE_I          ((nv_items_enum_type) 1778)
#define  NV_C1_BC0_LNA_1_RISE_I                        ((nv_items_enum_type) 1779)
#define  NV_C1_BC0_LNA_1_FALL_I                        ((nv_items_enum_type) 1780)
#define  NV_C1_BC0_LNA_2_RISE_I                        ((nv_items_enum_type) 1781)
#define  NV_C1_BC0_LNA_2_FALL_I                        ((nv_items_enum_type) 1782)
#define  NV_C1_BC0_LNA_3_RISE_I                        ((nv_items_enum_type) 1783)
#define  NV_C1_BC0_LNA_3_FALL_I                        ((nv_items_enum_type) 1784)
#define  NV_C1_BC0_LNA_4_RISE_I                        ((nv_items_enum_type) 1785)
#define  NV_C1_BC0_LNA_4_FALL_I                        ((nv_items_enum_type) 1786)
#define  NV_C1_BC0_IM_LEVEL1_I                         ((nv_items_enum_type) 1787)
#define  NV_C1_BC0_IM_LEVEL2_I                         ((nv_items_enum_type) 1788)
#define  NV_C1_BC0_IM_LEVEL3_I                         ((nv_items_enum_type) 1789)
#define  NV_C1_BC0_IM_LEVEL4_I                         ((nv_items_enum_type) 1790)
#define  NV_RFR_BB_FILTER_I                            ((nv_items_enum_type) 1791)
#define  NV_RFR_IQ_LINE_RESISTOR_I                     ((nv_items_enum_type) 1792)
#define  NV_WCDMA_RFR_VCO_COARSE_TUNING_I              ((nv_items_enum_type) 1793)
#define  NV_RFR_VCO_COARSE_TUNING_1900_I               ((nv_items_enum_type) 1794)
#define  NV_WCDMA_TX_ROT_ANGLE_PA_STATE_00_I           ((nv_items_enum_type) 1795)
#define  NV_WCDMA_TX_ROT_ANGLE_PA_STATE_01_I           ((nv_items_enum_type) 1796)
#define  NV_WCDMA_TX_ROT_ANGLE_PA_STATE_10_I           ((nv_items_enum_type) 1797)
#define  NV_WCDMA_TX_ROT_ANGLE_PA_STATE_11_I           ((nv_items_enum_type) 1798)
#define  NV_AMR_I                                      ((nv_items_enum_type) 1799)
#define  NV_WCDMA_SPIKE_MITIGATION_ENABLED_I           ((nv_items_enum_type) 1800)
#define  NV_PA_COMPENSATE_UP_I                         ((nv_items_enum_type) 1801)
#define  NV_PA_COMPENSATE_DOWN_I                       ((nv_items_enum_type) 1802)
#define  NV_SN_PPP_STATUS_I                            ((nv_items_enum_type) 1803)
#define  NV_DS_UCSD_RLPV2_DEFAULT_I                    ((nv_items_enum_type) 1804)
#define  NV_SELECT_TECH_FOR_CARD_I                     ((nv_items_enum_type) 1805)
#define  NV_PPP_NCP_REMOTE_INITIATE_I                  ((nv_items_enum_type) 1806)
#define  NV_DS_UCSD_RLP_VERSION_GSM_I                  ((nv_items_enum_type) 1807)
#define  NV_DS_UCSD_RLP_VERSION_WCDMA_I                ((nv_items_enum_type) 1808)
#define  NV_DS_ATCOP_RLP_VERSION_DEFAULT_I             ((nv_items_enum_type) 1809)
#define  NV_DS_UCSD_RECOVERY_MODE_SREJ_I               ((nv_items_enum_type) 1810)
#define  NV_TCP_KEEPALIVE_IDLE_TIME_I                  ((nv_items_enum_type) 1811)
#define  NV_RF_TUNE_RESERVED_I                         ((nv_items_enum_type) 1812)
#define  NV_DATA_FORCE_CDMA_PKT_STR_I                  ((nv_items_enum_type) 1813)
#define  NV_WCDMA_800_VGA_GAIN_OFFSET_I                ((nv_items_enum_type) 1814)
#define  NV_WCDMA_800_VGA_GAIN_OFFSET_VS_FREQ_I        ((nv_items_enum_type) 1815)
#define  NV_WCDMA_800_VGA_GAIN_OFFSET_VS_TEMP_I        ((nv_items_enum_type) 1816)
#define  NV_WCDMA_800_LNA_RANGE_RISE_2_I               ((nv_items_enum_type) 1817)
#define  NV_WCDMA_800_LNA_RANGE_RISE_3_I               ((nv_items_enum_type) 1818)
#define  NV_WCDMA_800_LNA_RANGE_FALL_2_I               ((nv_items_enum_type) 1819)
#define  NV_WCDMA_800_LNA_RANGE_FALL_3_I               ((nv_items_enum_type) 1820)
#define  NV_WCDMA_800_IM_LEVEL_2_I                     ((nv_items_enum_type) 1821)
#define  NV_WCDMA_800_IM_LEVEL_3_I                     ((nv_items_enum_type) 1822)
#define  NV_WCDMA_800_LNA_RANGE_OFFSET_2_I             ((nv_items_enum_type) 1823)
#define  NV_WCDMA_800_LNA_RANGE_OFFSET_3_I             ((nv_items_enum_type) 1824)
#define  NV_WCDMA_800_LNA_OFFSET_VS_FREQ_2_I           ((nv_items_enum_type) 1825)
#define  NV_WCDMA_800_LNA_OFFSET_VS_FREQ_3_I           ((nv_items_enum_type) 1826)
#define  NV_WCDMA_800_IM2_I_VALUE_I                    ((nv_items_enum_type) 1827)
#define  NV_WCDMA_800_IM2_Q_VALUE_I                    ((nv_items_enum_type) 1828)
#define  NV_WCDMA_800_IM2_TRANSCONDUCTOR_VALUE_I       ((nv_items_enum_type) 1829)
#define  NV_WCDMA_800_RX_AGC_MIN_2_I                   ((nv_items_enum_type) 1830)
#define  NV_WCDMA_800_RX_AGC_MIN_3_I                   ((nv_items_enum_type) 1831)
#define  NV_WCDMA_800_MAX_TX_POWER_I                   ((nv_items_enum_type) 1832)
#define  NV_WCDMA_800_OUT_OF_SERVICE_THRESH_I          ((nv_items_enum_type) 1833)
#define  NV_WCDMA_800_LNA_RANGE_RISE_I                 ((nv_items_enum_type) 1834)
#define  NV_WCDMA_800_LNA_RANGE_FALL_I                 ((nv_items_enum_type) 1835)
#define  NV_WCDMA_800_IM_LEVEL_I                       ((nv_items_enum_type) 1836)
#define  NV_WCDMA_800_NONBYPASS_TIMER_I                ((nv_items_enum_type) 1837)
#define  NV_WCDMA_800_BYPASS_TIMER_I                   ((nv_items_enum_type) 1838)
#define  NV_WCDMA_800_LNA_RANGE_OFFSET_I               ((nv_items_enum_type) 1839)
#define  NV_WCDMA_800_LNA_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 1840)
#define  NV_WCDMA_800_RX_AGC_MIN_I                     ((nv_items_enum_type) 1841)
#define  NV_WCDMA_800_RX_AGC_MAX_I                     ((nv_items_enum_type) 1842)
#define  NV_WCDMA_800_AGC_PHASE_OFFSET_I               ((nv_items_enum_type) 1843)
#define  NV_WCDMA_800_TX_LIN_MASTER_0_I                ((nv_items_enum_type) 1844)
#define  NV_WCDMA_800_TX_LIN_MASTER_1_I                ((nv_items_enum_type) 1845)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_0_I              ((nv_items_enum_type) 1846)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_1_I              ((nv_items_enum_type) 1847)
#define  NV_WCDMA_800_TX_LIN_VS_TEMP_0_I               ((nv_items_enum_type) 1848)
#define  NV_WCDMA_800_TX_LIN_VS_TEMP_1_I               ((nv_items_enum_type) 1849)
#define  NV_WCDMA_800_TX_SLP_VS_TEMP_0_I               ((nv_items_enum_type) 1850)
#define  NV_WCDMA_800_TX_SLP_VS_TEMP_1_I               ((nv_items_enum_type) 1860)
#define  NV_WCDMA_800_R1_RISE_I                        ((nv_items_enum_type) 1861)
#define  NV_WCDMA_800_R1_FALL_I                        ((nv_items_enum_type) 1862)
#define  NV_WCDMA_800_TX_LIM_VS_TEMP_I                 ((nv_items_enum_type) 1863)
#define  NV_WCDMA_800_TX_LIM_VS_FREQ_I                 ((nv_items_enum_type) 1864)
#define  NV_WCDMA_800_ADJ_FACTOR_I                     ((nv_items_enum_type) 1865)
#define  NV_WCDMA_800_EXP_HDET_VS_AGC_I                ((nv_items_enum_type) 1866)
#define  NV_WCDMA_800_HDET_OFF_I                       ((nv_items_enum_type) 1867)
#define  NV_WCDMA_800_HDET_SPN_I                       ((nv_items_enum_type) 1868)
#define  NV_WCDMA_800_ENC_BTF_I                        ((nv_items_enum_type) 1869)
#define  NV_WCDMA_800_AGC_PA_ON_RISE_DELAY_I           ((nv_items_enum_type) 1870)
#define  NV_WCDMA_800_AGC_PA_ON_FALL_DELAY_I           ((nv_items_enum_type) 1871)
#define  NV_WCDMA_800_AGC_TX_ON_RISE_DELAY_I           ((nv_items_enum_type) 1872)
#define  NV_WCDMA_800_AGC_TX_ON_FALL_DELAY_I           ((nv_items_enum_type) 1873)
#define  NV_WCDMA_800_AGC_UPDATE_TX_AGC_TIME_I         ((nv_items_enum_type) 1874)
#define  NV_PA_R_MAP_I                                 ((nv_items_enum_type) 1875)
#define  NV_PS_IPV6_IID_I                              ((nv_items_enum_type) 1876)
#define  NV_RF_BC_CONFIG_I                             ((nv_items_enum_type) 1877)
#define  NV_RF_HW_CONFIG_I                             ((nv_items_enum_type) 1878)
#define  NV_BC0_HDR_IM_FALL_I                          ((nv_items_enum_type) 1879)
#define  NV_BC0_HDR_IM_RISE_I                          ((nv_items_enum_type) 1880)
#define  NV_VCO_TEMP_I                                 ((nv_items_enum_type) 1881)
#define  NV_VCO_DEFAULT_I                              ((nv_items_enum_type) 1882)
#define  NV_VCO_SLOPE_I                                ((nv_items_enum_type) 1883)
#define  NV_VCO_SLOPE_RANGE_I                          ((nv_items_enum_type) 1884)
#define  NV_RGS_TIME_I                                 ((nv_items_enum_type) 1885)
#define  NV_RGS_TYPE_I                                 ((nv_items_enum_type) 1886)
#define  NV_RGS_TEMP_I                                 ((nv_items_enum_type) 1887)
#define  NV_RGS_ROT_I                                  ((nv_items_enum_type) 1888)
#define  NV_RGS_VCO_I                                  ((nv_items_enum_type) 1889)
#define  NV_BC0_HDR_IM_LEVEL_I                         ((nv_items_enum_type) 1890)
#define  NV_GSM_TX_BURST_OFFSET_ADJ_I                  ((nv_items_enum_type) 1891)
#define  NV_DIAG_DEBUG_CONTROL_I                       ((nv_items_enum_type) 1892)
#define  NV_QVP_APP_DEFAULT_CAPABILITY_TYPE_I          ((nv_items_enum_type) 1893)
#define  NV_RR_STORED_LAST_BEST_ARFCNS_BAND_I          ((nv_items_enum_type) 1894)
#define  NV_DIAG_DEBUG_DETAIL_I                        ((nv_items_enum_type) 1895)
#define  NV_IPV6_ENABLED_I                             ((nv_items_enum_type) 1896)
#define  NV_IPV6_SM_CONFIG_I                           ((nv_items_enum_type) 1897)
#define  NV_C1_BC0_VCO_COARSE_TUNE_TABLE_I             ((nv_items_enum_type) 1898)
#define  NV_C1_BC1_VCO_COARSE_TUNE_TABLE_I             ((nv_items_enum_type) 1899)
#define  NV_C1_BC3_VCO_COARSE_TUNE_TABLE_I             ((nv_items_enum_type) 1900)
#define  NV_C1_BC4_VCO_COARSE_TUNE_TABLE_I             ((nv_items_enum_type) 1901)
#define  NV_C1_BC5_VCO_COARSE_TUNE_TABLE_I             ((nv_items_enum_type) 1902)
#define  NV_C1_BC6_VCO_COARSE_TUNE_TABLE_I             ((nv_items_enum_type) 1903)
#define  NV_C1_RFR_BB_FILTER_I                         ((nv_items_enum_type) 1904)
#define  NV_IPV6_PRIMARY_DNS_I                         ((nv_items_enum_type) 1905)
#define  NV_IPV6_SECONDARY_DNS_I                       ((nv_items_enum_type) 1906)
#define  NV_AUTH_REQUIRE_PASSWORD_ENCRYPTION_I         ((nv_items_enum_type) 1907)
#define  NV_WCDMA_PRACH_R1_RISE_OFFSET_I               ((nv_items_enum_type) 1908)
#define  NV_WCDMA_1900_PRACH_R1_RISE_OFFSET_I          ((nv_items_enum_type) 1909)
#define  NV_WCDMA_PRACH_R1_FALL_OFFSET_I               ((nv_items_enum_type) 1910)
#define  NV_WCDMA_1900_PRACH_R1_FALL_OFFSET_I          ((nv_items_enum_type) 1911)
#define  NV_WCDMA_800_PRACH_R1_FALL_OFFSET_I           ((nv_items_enum_type) 1912)
#define  NV_AAGPS_MAX_OSC_UNC_I                        ((nv_items_enum_type) 1913)
#define  NV_AAGPS_MAX_OSC_UNC_RATE_I                   ((nv_items_enum_type) 1914)
#define  NV_AAGPS_PROCESSING_LOSSES_I                  ((nv_items_enum_type) 1915)
#define  NV_AAGPS_MAX_PLATFORM_VELOCITY_I              ((nv_items_enum_type) 1916)
#define  NV_AAGPS_MAX_PLATFORM_ACCL_I                  ((nv_items_enum_type) 1917)
#define  NV_AAGPS_DEFAULT_QOS_TIME_I                   ((nv_items_enum_type) 1918)
#define  NV_AAGPS_RAPID_FIX_REPORT_MAX_LATENCY_I       ((nv_items_enum_type) 1919)
#define  NV_AAGPS_POSITIONING_MODES_SUPPORTED_I        ((nv_items_enum_type) 1920)
#define  NV_AAGPS_DEFAULT_REF_TIME_UNC_I               ((nv_items_enum_type) 1921)
#define  NV_AAGPS_DEFAULT_REF_POSITION_UNC_I           ((nv_items_enum_type) 1922)
#define  NV_AAGPS_APP_TRACKING_GPSIDLE_THSLD_I         ((nv_items_enum_type) 1923)
#define  NV_AAGPS_GPS_LOCK_CONTROL_I                   ((nv_items_enum_type) 1924)
#define  NV_AAGPS_DEFAULT_URL_I                        ((nv_items_enum_type) 1925)
#define  NV_AAGPS_DEFAULT_IP_ADDRESS_I                 ((nv_items_enum_type) 1926)
#define  NV_AAGPS_TRANSPORT_TYPE_I                     ((nv_items_enum_type) 1927)
#define  NV_AAGPS_KEEP_WARM_MODE_I                     ((nv_items_enum_type) 1928)
#define  NV_AAGPS_2G_MO_LRSUPPORT_I                    ((nv_items_enum_type) 1929)
#define  NV_AAGPS_EMERGENCY_SERVICES_SPPRT_I           ((nv_items_enum_type) 1930)
#define  NV_WCDMA_800_PRACH_R1_RISE_OFFSET_I           ((nv_items_enum_type) 1931)
#define  NV_PDSN_AS_PROXY_IPV6_DNS_SERVER_I            ((nv_items_enum_type) 1932)
#define  NV_HDRAMP_HARDWARE_ID_I                       ((nv_items_enum_type) 1933)
#define  NV_AAGPS_PROTOCOL_SELECT_I                    ((nv_items_enum_type) 1934)
#define  NV_AAGPS_APP_TRKG_PERIODIC_REQ_DLY_MARGIN_I   ((nv_items_enum_type) 1935)
#define  NV_AAGPS_DEFAULT_QOS_UNC_I                    ((nv_items_enum_type) 1936)
#define  NV_AAGPS_APP_TRACKING_GPSON_THSLD_I           ((nv_items_enum_type) 1937)
#define  NV_AAGPS_MT_LRSUPPORT_I                       ((nv_items_enum_type) 1940)
#define  NV_IPV6_FAILOVER_CONFIG_I                     ((nv_items_enum_type) 1941)
#define  NV_UIM_USE_CAVE_FOR_AN_AUTH_I                 ((nv_items_enum_type) 1942)
#define  NV_MEID_I                                     ((nv_items_enum_type) 1943)
#define  NV_GPS1_CALL_RELATED_I                        ((nv_items_enum_type) 1944)
#define  NV_RF_ANTSEL_GSM_DEFAULT_I                    ((nv_items_enum_type) 1945)
#define  NV_RF_ANTSEL_GSM_850_TX_I                     ((nv_items_enum_type) 1946)
#define  NV_RF_ANTSEL_GSM_850_RX_I                     ((nv_items_enum_type) 1947)
#define  NV_RF_ANTSEL_GSM_900_TX_I                     ((nv_items_enum_type) 1948)
#define  NV_RF_ANTSEL_GSM_900_RX_I                     ((nv_items_enum_type) 1949)
#define  NV_RF_ANTSEL_GSM_1800_TX_I                    ((nv_items_enum_type) 1950)
#define  NV_RF_ANTSEL_GSM_1800_RX_I                    ((nv_items_enum_type) 1951)
#define  NV_RF_ANTSEL_GSM_1900_TX_I                    ((nv_items_enum_type) 1952)
#define  NV_RF_ANTSEL_GSM_1900_RX_I                    ((nv_items_enum_type) 1953)
#define  NV_RF_ANTSEL_UMTS_800_I                       ((nv_items_enum_type) 1954)
#define  NV_RF_ANTSEL_UMTS_1900_I                      ((nv_items_enum_type) 1955)
#define  NV_RF_ANTSEL_UMTS_2100_I                      ((nv_items_enum_type) 1956)
#define  NV_TCP_SACK_TIMESTAMP_ENABLED_I               ((nv_items_enum_type) 1957)
#define  NV_PRL_PREF_I                                 ((nv_items_enum_type) 1958)
#define  NV_AAGPS_DEFAULT_IP_PORT_I                    ((nv_items_enum_type) 1959)
#define  NV_AAGPS_3G_MO_LRSUPPORT_I                    ((nv_items_enum_type) 1960)
#define  NV_AAGPS_DEVELOPMENT_TEST_CONTROL_I           ((nv_items_enum_type) 1961)
#define  NV_DIAG_DEBUG_MAX_FILES_I                     ((nv_items_enum_type) 1962)
#define  NV_WCDMA_800_PA_COMPENSATE_UP_I               ((nv_items_enum_type) 1963)
#define  NV_WCDMA_800_PA_COMPENSATE_DOWN_I             ((nv_items_enum_type) 1964)
#define  NV_WCDMA_1900_PA_COMPENSATE_UP_I              ((nv_items_enum_type) 1965)
#define  NV_WCDMA_1900_PA_COMPENSATE_DOWN_I            ((nv_items_enum_type) 1966)
#define  NV_WCDMA_800_PA_GAIN_UP_TIME_I                ((nv_items_enum_type) 1967)
#define  NV_WCDMA_800_PA_GAIN_DOWN_TIME_I              ((nv_items_enum_type) 1968)
#define  NV_WCDMA_1900_PA_GAIN_UP_TIME_I               ((nv_items_enum_type) 1969)
#define  NV_WCDMA_1900_PA_GAIN_DOWN_TIME_I             ((nv_items_enum_type) 1970)
#define  NV_WCDMA_TX_CAL_CHAN_I                        ((nv_items_enum_type) 1971)
#define  NV_WCDMA_RX_CAL_CHAN_I                        ((nv_items_enum_type) 1972)
#define  NV_WCDMA_1900_TX_CAL_CHAN_I                   ((nv_items_enum_type) 1973)
#define  NV_WCDMA_1900_RX_CAL_CHAN_I                   ((nv_items_enum_type) 1974)
#define  NV_WCDMA_800_TX_CAL_CHAN_I                    ((nv_items_enum_type) 1975)
#define  NV_WCDMA_800_RX_CAL_CHAN_I                    ((nv_items_enum_type) 1976)
#define  NV_BREW_CARRIER_ID_I                          ((nv_items_enum_type) 1977)
#define  NV_BREW_PLATFORM_ID_I                         ((nv_items_enum_type) 1978)
#define  NV_BREW_BKEY_I                                ((nv_items_enum_type) 1979)
#define  NV_BREW_SERVER_I                              ((nv_items_enum_type) 1980)
#define  NV_BREW_DOWNLOAD_FLAGS_I                      ((nv_items_enum_type) 1981)
#define  NV_BREW_AUTH_POLICY_I                         ((nv_items_enum_type) 1982)
#define  NV_BREW_PRIVACY_POLICY_I                      ((nv_items_enum_type) 1983)
#define  NV_BREW_SUBSCRIBER_ID_I                       ((nv_items_enum_type) 1984)
#define  NV_WCDMA_RX_DELAY_I                           ((nv_items_enum_type) 1985)
#define  NV_WCDMA_800_RX_DELAY_I                       ((nv_items_enum_type) 1986)
#define  NV_WCDMA_1900_RX_DELAY_I                      ((nv_items_enum_type) 1987)
#define  NV_AAGPS_DEVELOPMENT_TEST_CONTROL2_I          ((nv_items_enum_type) 1988)
#define  NV_AAGPS_DEVELOPMENT_TEST_CONTROL3_I          ((nv_items_enum_type) 1989)
#define  NV_AAGPS_DEVELOPMENT_TEST_CONTROL4_I          ((nv_items_enum_type) 1990)
#define  NV_AAGPS_DEVELOPMENT_TEST_CONTROL5_I          ((nv_items_enum_type) 1991)
#define  NV_MEID_CD_I                                  ((nv_items_enum_type) 1992)
#define  NV_GPS1_VX_LCS_AGENT_I                        ((nv_items_enum_type) 1993)
#define  NV_GPS1_VX_APP_TRUSTED_SETTINGS_I             ((nv_items_enum_type) 1994)
#define  NV_GPS1_VX_NI_TELESERVICE_ID_I                ((nv_items_enum_type) 1995)
#define  NV_GPS1_VX_LCS_AGENT_PREV6_ONLY_I             ((nv_items_enum_type) 1996)
#define  NV_GPS1_VX_MO_MAX_DURATION_I                  ((nv_items_enum_type) 1997)
#define  NV_OOSOPERATIONPREF_I                         ((nv_items_enum_type) 1998)
#define  NV_GPS1_VX_GPS_DURING_VOICE_CALL_I            ((nv_items_enum_type) 1999)
#define  NV_WLAN_TECH_PREF_I                           ((nv_items_enum_type) 2000)
#define  NV_DS_UCSD_RLP_ADM_IDLE_I                     ((nv_items_enum_type) 2001)
#define  NV_WLAN_SCAN_PREF_I                           ((nv_items_enum_type) 2003)
#define  NV_HDRBCMCS_OVHD_PERIOD_I                     ((nv_items_enum_type) 2004)
#define  NV_HDRBCMCS_PAGE_REG_PERIOD_I                 ((nv_items_enum_type) 2005)
#define  NV_HDRBCMCS_DYN_REG_PERIOD_I                  ((nv_items_enum_type) 2006)
#define  NV_HDRBCMCS_MONITOR_PERIOD_I                  ((nv_items_enum_type) 2007)
#define  NV_HDRBCMCS_NUM_PERIODS_I                     ((nv_items_enum_type) 2008)
#define  NV_WCDMA_TX_LIN_MASTER_2_I                    ((nv_items_enum_type) 2009)
#define  NV_WCDMA_TX_LIN_MASTER_3_I                    ((nv_items_enum_type) 2010)
#define  NV_WCDMA_TX_COMP_VS_FREQ_2_I                  ((nv_items_enum_type) 2011)
#define  NV_WCDMA_TX_COMP_VS_FREQ_3_I                  ((nv_items_enum_type) 2012)
#define  NV_WCDMA_TX_LIN_VS_TEMP_2_I                   ((nv_items_enum_type) 2013)
#define  NV_WCDMA_TX_LIN_VS_TEMP_3_I                   ((nv_items_enum_type) 2014)
#define  NV_WCDMA_TX_SLP_VS_TEMP_2_I                   ((nv_items_enum_type) 2015)
#define  NV_WCDMA_TX_SLP_VS_TEMP_3_I                   ((nv_items_enum_type) 2016)
#define  NV_WCDMA_R2_RISE_I                            ((nv_items_enum_type) 2017)
#define  NV_WCDMA_R2_FALL_I                            ((nv_items_enum_type) 2018)
#define  NV_WCDMA_R3_RISE_I                            ((nv_items_enum_type) 2019)
#define  NV_WCDMA_R3_FALL_I                            ((nv_items_enum_type) 2020)
#define  NV_PA_COMPENSATE_UP_R2_I                      ((nv_items_enum_type) 2021)
#define  NV_PA_COMPENSATE_DOWN_R2_I                    ((nv_items_enum_type) 2022)
#define  NV_PA_COMPENSATE_UP_R3_I                      ((nv_items_enum_type) 2023)
#define  NV_PA_COMPENSATE_DOWN_R3_I                    ((nv_items_enum_type) 2024)
#define  NV_WCDMA_PRACH_R2_RISE_OFFSET_I               ((nv_items_enum_type) 2025)
#define  NV_WCDMA_PRACH_R2_FALL_OFFSET_I               ((nv_items_enum_type) 2026)
#define  NV_WCDMA_PRACH_R3_RISE_OFFSET_I               ((nv_items_enum_type) 2027)
#define  NV_WCDMA_PRACH_R3_FALL_OFFSET_I               ((nv_items_enum_type) 2028)
#define  NV_WCDMA_PA_RANGE_MAP_I                       ((nv_items_enum_type) 2029)
#define  NV_WCDMA_1900_TX_LIN_MASTER_2_I               ((nv_items_enum_type) 2030)
#define  NV_WCDMA_1900_TX_LIN_MASTER_3_I               ((nv_items_enum_type) 2031)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_2_I             ((nv_items_enum_type) 2032)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_3_I             ((nv_items_enum_type) 2033)
#define  NV_WCDMA_1900_TX_LIN_VS_TEMP_2_I              ((nv_items_enum_type) 2034)
#define  NV_WCDMA_1900_TX_LIN_VS_TEMP_3_I              ((nv_items_enum_type) 2035)
#define  NV_WCDMA_1900_TX_SLP_VS_TEMP_2_I              ((nv_items_enum_type) 2036)
#define  NV_WCDMA_1900_TX_SLP_VS_TEMP_3_I              ((nv_items_enum_type) 2037)
#define  NV_WCDMA_1900_R2_RISE_I                       ((nv_items_enum_type) 2038)
#define  NV_WCDMA_1900_R2_FALL_I                       ((nv_items_enum_type) 2039)
#define  NV_WCDMA_1900_R3_RISE_I                       ((nv_items_enum_type) 2040)
#define  NV_WCDMA_1900_R3_FALL_I                       ((nv_items_enum_type) 2041)
#define  NV_WCDMA_1900_PA_COMPENSATE_UP_R2_I           ((nv_items_enum_type) 2042)
#define  NV_WCDMA_1900_PA_COMPENSATE_DOWN_R2_I         ((nv_items_enum_type) 2043)
#define  NV_WCDMA_1900_PA_COMPENSATE_UP_R3_I           ((nv_items_enum_type) 2044)
#define  NV_WCDMA_1900_PA_COMPENSATE_DOWN_R3_I         ((nv_items_enum_type) 2045)
#define  NV_WCDMA_1900_TX_ROT_ANGLE_PA_STATE_00_I      ((nv_items_enum_type) 2046)
#define  NV_WCDMA_1900_TX_ROT_ANGLE_PA_STATE_01_I      ((nv_items_enum_type) 2047)
#define  NV_WCDMA_1900_TX_ROT_ANGLE_PA_STATE_10_I      ((nv_items_enum_type) 2048)
#define  NV_WCDMA_1900_TX_ROT_ANGLE_PA_STATE_11_I      ((nv_items_enum_type) 2049)
#define  NV_WCDMA_1900_PRACH_R2_RISE_OFFSET_I          ((nv_items_enum_type) 2050)
#define  NV_WCDMA_1900_PRACH_R2_FALL_OFFSET_I          ((nv_items_enum_type) 2051)
#define  NV_WCDMA_1900_PRACH_R3_RISE_OFFSET_I          ((nv_items_enum_type) 2052)
#define  NV_WCDMA_1900_PRACH_R3_FALL_OFFSET_I          ((nv_items_enum_type) 2053)
#define  NV_WCDMA_1900_PA_RANGE_MAP_I                  ((nv_items_enum_type) 2054)
#define  NV_WCDMA_800_TX_LIN_MASTER_2_I                ((nv_items_enum_type) 2055)
#define  NV_WCDMA_800_TX_LIN_MASTER_3_I                ((nv_items_enum_type) 2056)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_2_I              ((nv_items_enum_type) 2057)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_3_I              ((nv_items_enum_type) 2058)
#define  NV_WCDMA_800_TX_LIN_VS_TEMP_2_I               ((nv_items_enum_type) 2059)
#define  NV_WCDMA_800_TX_LIN_VS_TEMP_3_I               ((nv_items_enum_type) 2060)
#define  NV_WCDMA_800_TX_SLP_VS_TEMP_2_I               ((nv_items_enum_type) 2061)
#define  NV_WCDMA_800_TX_SLP_VS_TEMP_3_I               ((nv_items_enum_type) 2062)
#define  NV_WCDMA_800_R2_RISE_I                        ((nv_items_enum_type) 2063)
#define  NV_WCDMA_800_R2_FALL_I                        ((nv_items_enum_type) 2064)
#define  NV_WCDMA_800_R3_RISE_I                        ((nv_items_enum_type) 2065)
#define  NV_WCDMA_800_R3_FALL_I                        ((nv_items_enum_type) 2066)
#define  NV_WCDMA_800_PA_COMPENSATE_UP_R2_I            ((nv_items_enum_type) 2067)
#define  NV_WCDMA_800_PA_COMPENSATE_DOWN_R2_I          ((nv_items_enum_type) 2068)
#define  NV_WCDMA_800_PA_COMPENSATE_UP_R3_I            ((nv_items_enum_type) 2069)
#define  NV_WCDMA_800_PA_COMPENSATE_DOWN_R3_I          ((nv_items_enum_type) 2070)
#define  NV_WCDMA_800_TX_ROT_ANGLE_PA_STATE_00_I       ((nv_items_enum_type) 2071)
#define  NV_WCDMA_800_TX_ROT_ANGLE_PA_STATE_01_I       ((nv_items_enum_type) 2072)
#define  NV_WCDMA_800_TX_ROT_ANGLE_PA_STATE_10_I       ((nv_items_enum_type) 2073)
#define  NV_WCDMA_800_TX_ROT_ANGLE_PA_STATE_11_I       ((nv_items_enum_type) 2074)
#define  NV_WCDMA_800_PRACH_R2_RISE_OFFSET_I           ((nv_items_enum_type) 2075)
#define  NV_WCDMA_800_PRACH_R2_FALL_OFFSET_I           ((nv_items_enum_type) 2076)
#define  NV_WCDMA_800_PRACH_R3_RISE_OFFSET_I           ((nv_items_enum_type) 2077)
#define  NV_WCDMA_800_PRACH_R3_FALL_OFFSET_I           ((nv_items_enum_type) 2078)
#define  NV_WCDMA_800_PA_RANGE_MAP_I                   ((nv_items_enum_type) 2079)
#define  NV_BC0_VCO_COARSE_TUNE_2_I                    ((nv_items_enum_type) 2080)
#define  NV_BC1_VCO_COARSE_TUNE_2_I                    ((nv_items_enum_type) 2081)
#define  NV_BC3_VCO_COARSE_TUNE_2_I                    ((nv_items_enum_type) 2082)
#define  NV_BC4_VCO_COARSE_TUNE_2_I                    ((nv_items_enum_type) 2083)
#define  NV_BC5_VCO_COARSE_TUNE_2_I                    ((nv_items_enum_type) 2084)
#define  NV_BC6_VCO_COARSE_TUNE_2_I                    ((nv_items_enum_type) 2085)
#define  NV_GSM_PRUI_00_I                              ((nv_items_enum_type) 2086)
#define  NV_GSM_PRUI_01_I                              ((nv_items_enum_type) 2087)
#define  NV_GSM_PRUI_02_I                              ((nv_items_enum_type) 2088)
#define  NV_GSM_PRUI_03_I                              ((nv_items_enum_type) 2089)
#define  NV_GSM_PRUI_04_I                              ((nv_items_enum_type) 2090)
#define  NV_GSM_PRUI_05_I                              ((nv_items_enum_type) 2091)
#define  NV_GSM_PRUI_06_I                              ((nv_items_enum_type) 2092)
#define  NV_GSM_PRUI_07_I                              ((nv_items_enum_type) 2093)
#define  NV_GSM_PRUI_08_I                              ((nv_items_enum_type) 2094)
#define  NV_GSM_PRUI_09_I                              ((nv_items_enum_type) 2095)
#define  NV_GSM_PRUI_10_I                              ((nv_items_enum_type) 2096)
#define  NV_GSM_PRDI_00_I                              ((nv_items_enum_type) 2097)
#define  NV_GSM_PRDI_01_I                              ((nv_items_enum_type) 2098)
#define  NV_GSM_PRDI_02_I                              ((nv_items_enum_type) 2099)
#define  NV_GSM_PRDI_03_I                              ((nv_items_enum_type) 2100)
#define  NV_GSM_PRDI_04_I                              ((nv_items_enum_type) 2101)
#define  NV_GSM_PRDI_05_I                              ((nv_items_enum_type) 2102)
#define  NV_GSM_PRDI_06_I                              ((nv_items_enum_type) 2103)
#define  NV_GSM_PRDI_07_I                              ((nv_items_enum_type) 2104)
#define  NV_GSM_PRDI_08_I                              ((nv_items_enum_type) 2105)
#define  NV_GSM_PRDI_09_I                              ((nv_items_enum_type) 2106)
#define  NV_GSM_PRDI_10_I                              ((nv_items_enum_type) 2107)
#define  NV_GSM_PRDI_11_I                              ((nv_items_enum_type) 2108)
#define  NV_DCS_PRUI_00_I                              ((nv_items_enum_type) 2109)
#define  NV_DCS_PRUI_01_I                              ((nv_items_enum_type) 2110)
#define  NV_DCS_PRUI_02_I                              ((nv_items_enum_type) 2111)
#define  NV_DCS_PRUI_03_I                              ((nv_items_enum_type) 2112)
#define  NV_DCS_PRUI_04_I                              ((nv_items_enum_type) 2113)
#define  NV_DCS_PRUI_05_I                              ((nv_items_enum_type) 2114)
#define  NV_DCS_PRUI_06_I                              ((nv_items_enum_type) 2115)
#define  NV_DCS_PRUI_07_I                              ((nv_items_enum_type) 2116)
#define  NV_DCS_PRUI_08_I                              ((nv_items_enum_type) 2117)
#define  NV_DCS_PRUI_09_I                              ((nv_items_enum_type) 2118)
#define  NV_DCS_PRUI_10_I                              ((nv_items_enum_type) 2119)
#define  NV_DCS_PRUI_11_I                              ((nv_items_enum_type) 2120)
#define  NV_DCS_PRUI_12_I                              ((nv_items_enum_type) 2121)
#define  NV_DCS_PRDI_00_I                              ((nv_items_enum_type) 2122)
#define  NV_DCS_PRDI_01_I                              ((nv_items_enum_type) 2123)
#define  NV_DCS_PRDI_02_I                              ((nv_items_enum_type) 2124)
#define  NV_DCS_PRDI_03_I                              ((nv_items_enum_type) 2125)
#define  NV_DCS_PRDI_04_I                              ((nv_items_enum_type) 2126)
#define  NV_DCS_PRDI_05_I                              ((nv_items_enum_type) 2127)
#define  NV_DCS_PRDI_06_I                              ((nv_items_enum_type) 2128)
#define  NV_DCS_PRDI_07_I                              ((nv_items_enum_type) 2129)
#define  NV_DCS_PRDI_08_I                              ((nv_items_enum_type) 2130)
#define  NV_DCS_PRDI_09_I                              ((nv_items_enum_type) 2131)
#define  NV_DCS_PRDI_10_I                              ((nv_items_enum_type) 2132)
#define  NV_DCS_PRDI_11_I                              ((nv_items_enum_type) 2133)
#define  NV_DCS_PRDI_12_I                              ((nv_items_enum_type) 2134)
#define  NV_GSM_1900_PRUI_00_I                         ((nv_items_enum_type) 2135)
#define  NV_GSM_1900_PRUI_01_I                         ((nv_items_enum_type) 2136)
#define  NV_GSM_1900_PRUI_02_I                         ((nv_items_enum_type) 2137)
#define  NV_GSM_1900_PRUI_03_I                         ((nv_items_enum_type) 2138)
#define  NV_GSM_1900_PRUI_04_I                         ((nv_items_enum_type) 2139)
#define  NV_GSM_1900_PRUI_05_I                         ((nv_items_enum_type) 2140)
#define  NV_GSM_1900_PRUI_06_I                         ((nv_items_enum_type) 2141)
#define  NV_GSM_1900_PRUI_07_I                         ((nv_items_enum_type) 2142)
#define  NV_GSM_1900_PRUI_08_I                         ((nv_items_enum_type) 2143)
#define  NV_GSM_1900_PRUI_09_I                         ((nv_items_enum_type) 2144)
#define  NV_GSM_1900_PRUI_10_I                         ((nv_items_enum_type) 2145)
#define  NV_GSM_1900_PRUI_11_I                         ((nv_items_enum_type) 2146)
#define  NV_GSM_1900_PRUI_12_I                         ((nv_items_enum_type) 2147)
#define  NV_GSM_1900_PRDI_02_I                         ((nv_items_enum_type) 2148)
#define  NV_GSM_1900_PRDI_03_I                         ((nv_items_enum_type) 2149)
#define  NV_GSM_1900_PRDI_04_I                         ((nv_items_enum_type) 2150)
#define  NV_GSM_1900_PRDI_05_I                         ((nv_items_enum_type) 2151)
#define  NV_GSM_1900_PRDI_06_I                         ((nv_items_enum_type) 2152)
#define  NV_GSM_1900_PRDI_07_I                         ((nv_items_enum_type) 2153)
#define  NV_GSM_1900_PRDI_09_I                         ((nv_items_enum_type) 2154)
#define  NV_GSM_1900_PRDI_10_I                         ((nv_items_enum_type) 2155)
#define  NV_GSM_1900_PRDI_12_I                         ((nv_items_enum_type) 2156)
#define  NV_GSM_VL_TL_BRUI_14_I                        ((nv_items_enum_type) 2157)
#define  NV_GSM_VL_TL_BRUI_13_I                        ((nv_items_enum_type) 2158)
#define  NV_GSM_VL_TL_BRUI_12_I                        ((nv_items_enum_type) 2159)
#define  NV_GSM_VL_TL_BRDI_14_I                        ((nv_items_enum_type) 2160)
#define  NV_GSM_VL_TL_BRDI_13_I                        ((nv_items_enum_type) 2161)
#define  NV_GSM_VL_TL_BRDI_12_I                        ((nv_items_enum_type) 2162)
#define  NV_DCS_VL_TL_BRUI_15_I                        ((nv_items_enum_type) 2163)
#define  NV_DCS_VL_TL_BRUI_14_I                        ((nv_items_enum_type) 2164)
#define  NV_DCS_VL_TL_BRUI_13_I                        ((nv_items_enum_type) 2165)
#define  NV_DCS_VL_TL_BRDI_15_I                        ((nv_items_enum_type) 2166)
#define  NV_DCS_VL_TL_BRDI_14_I                        ((nv_items_enum_type) 2167)
#define  NV_DCS_VL_TL_BRDI_13_I                        ((nv_items_enum_type) 2168)
#define  NV_GSM_1900_VL_TL_BRUI_15_I                   ((nv_items_enum_type) 2169)
#define  NV_GSM_1900_VL_TL_BRUI_14_I                   ((nv_items_enum_type) 2170)
#define  NV_GSM_1900_VL_TL_BRUI_13_I                   ((nv_items_enum_type) 2171)
#define  NV_GSM_1900_VL_TL_BRDI_15_I                   ((nv_items_enum_type) 2172)
#define  NV_GSM_1900_VL_TL_BRDI_14_I                   ((nv_items_enum_type) 2173)
#define  NV_GSM_1900_VL_TL_BRDI_13_I                   ((nv_items_enum_type) 2174)
#define  NV_GSM_VM_TL_BRUI_14_I                        ((nv_items_enum_type) 2175)
#define  NV_GSM_VM_TL_BRUI_13_I                        ((nv_items_enum_type) 2176)
#define  NV_GSM_VM_TL_BRUI_12_I                        ((nv_items_enum_type) 2177)
#define  NV_GSM_VM_TL_BRDI_14_I                        ((nv_items_enum_type) 2178)
#define  NV_GSM_VM_TL_BRDI_13_I                        ((nv_items_enum_type) 2179)
#define  NV_GSM_VM_TL_BRDI_12_I                        ((nv_items_enum_type) 2180)
#define  NV_DCS_VM_TL_BRUI_15_I                        ((nv_items_enum_type) 2181)
#define  NV_DCS_VM_TL_BRUI_14_I                        ((nv_items_enum_type) 2182)
#define  NV_DCS_VM_TL_BRUI_13_I                        ((nv_items_enum_type) 2183)
#define  NV_DCS_VM_TL_BRDI_15_I                        ((nv_items_enum_type) 2184)
#define  NV_DCS_VM_TL_BRDI_14_I                        ((nv_items_enum_type) 2185)
#define  NV_DCS_VM_TL_BRDI_13_I                        ((nv_items_enum_type) 2186)
#define  NV_GSM_1900_VM_TL_BRUI_15_I                   ((nv_items_enum_type) 2187)
#define  NV_GSM_1900_VM_TL_BRUI_14_I                   ((nv_items_enum_type) 2188)
#define  NV_GSM_1900_VM_TL_BRUI_13_I                   ((nv_items_enum_type) 2189)
#define  NV_GSM_1900_VM_TL_BRDI_15_I                   ((nv_items_enum_type) 2190)
#define  NV_GSM_1900_VM_TL_BRDI_14_I                   ((nv_items_enum_type) 2191)
#define  NV_GSM_1900_VM_TL_BRDI_13_I                   ((nv_items_enum_type) 2192)
#define  NV_GSM_VH_TL_BRUI_14_I                        ((nv_items_enum_type) 2193)
#define  NV_GSM_VH_TL_BRUI_13_I                        ((nv_items_enum_type) 2194)
#define  NV_GSM_VH_TL_BRUI_12_I                        ((nv_items_enum_type) 2195)
#define  NV_GSM_VH_TL_BRDI_14_I                        ((nv_items_enum_type) 2196)
#define  NV_GSM_VH_TL_BRDI_13_I                        ((nv_items_enum_type) 2197)
#define  NV_GSM_VH_TL_BRDI_12_I                        ((nv_items_enum_type) 2198)
#define  NV_DCS_VH_TL_BRUI_15_I                        ((nv_items_enum_type) 2199)
#define  NV_DCS_VH_TL_BRUI_14_I                        ((nv_items_enum_type) 2200)
#define  NV_DCS_VH_TL_BRUI_13_I                        ((nv_items_enum_type) 2201)
#define  NV_DCS_VH_TL_BRDI_15_I                        ((nv_items_enum_type) 2202)
#define  NV_DCS_VH_TL_BRDI_14_I                        ((nv_items_enum_type) 2203)
#define  NV_DCS_VH_TL_BRDI_13_I                        ((nv_items_enum_type) 2204)
#define  NV_GSM_1900_VH_TL_BRUI_15_I                   ((nv_items_enum_type) 2205)
#define  NV_GSM_1900_VH_TL_BRUI_14_I                   ((nv_items_enum_type) 2206)
#define  NV_GSM_1900_VH_TL_BRUI_13_I                   ((nv_items_enum_type) 2207)
#define  NV_GSM_1900_VH_TL_BRDI_15_I                   ((nv_items_enum_type) 2208)
#define  NV_GSM_1900_VH_TL_BRDI_14_I                   ((nv_items_enum_type) 2209)
#define  NV_GSM_1900_VH_TL_BRDI_13_I                   ((nv_items_enum_type) 2210)
#define  NV_GSM_VL_TM_BRUI_14_I                        ((nv_items_enum_type) 2211)
#define  NV_GSM_VL_TM_BRUI_13_I                        ((nv_items_enum_type) 2212)
#define  NV_GSM_VL_TM_BRUI_12_I                        ((nv_items_enum_type) 2213)
#define  NV_GSM_VL_TM_BRDI_14_I                        ((nv_items_enum_type) 2214)
#define  NV_GSM_VL_TM_BRDI_13_I                        ((nv_items_enum_type) 2215)
#define  NV_GSM_VL_TM_BRDI_12_I                        ((nv_items_enum_type) 2216)
#define  NV_DCS_VL_TM_BRUI_15_I                        ((nv_items_enum_type) 2217)
#define  NV_DCS_VL_TM_BRUI_14_I                        ((nv_items_enum_type) 2218)
#define  NV_DCS_VL_TM_BRUI_13_I                        ((nv_items_enum_type) 2219)
#define  NV_DCS_VL_TM_BRDI_15_I                        ((nv_items_enum_type) 2220)
#define  NV_DCS_VL_TM_BRDI_14_I                        ((nv_items_enum_type) 2221)
#define  NV_DCS_VL_TM_BRDI_13_I                        ((nv_items_enum_type) 2222)
#define  NV_GSM_1900_VL_TM_BRUI_15_I                   ((nv_items_enum_type) 2223)
#define  NV_GSM_1900_VL_TM_BRUI_14_I                   ((nv_items_enum_type) 2224)
#define  NV_GSM_1900_VL_TM_BRUI_13_I                   ((nv_items_enum_type) 2225)
#define  NV_GSM_1900_VL_TM_BRDI_15_I                   ((nv_items_enum_type) 2226)
#define  NV_GSM_1900_VL_TM_BRDI_14_I                   ((nv_items_enum_type) 2227)
#define  NV_GSM_1900_VL_TM_BRDI_13_I                   ((nv_items_enum_type) 2228)
#define  NV_GSM_VM_TM_BRUI_14_I                        ((nv_items_enum_type) 2229)
#define  NV_GSM_VM_TM_BRUI_13_I                        ((nv_items_enum_type) 2230)
#define  NV_GSM_VM_TM_BRUI_12_I                        ((nv_items_enum_type) 2231)
#define  NV_GSM_VM_TM_BRDI_14_I                        ((nv_items_enum_type) 2232)
#define  NV_GSM_VM_TM_BRDI_13_I                        ((nv_items_enum_type) 2233)
#define  NV_GSM_VM_TM_BRDI_12_I                        ((nv_items_enum_type) 2234)
#define  NV_DCS_VM_TM_BRUI_15_I                        ((nv_items_enum_type) 2235)
#define  NV_DCS_VM_TM_BRUI_14_I                        ((nv_items_enum_type) 2236)
#define  NV_DCS_VM_TM_BRUI_13_I                        ((nv_items_enum_type) 2237)
#define  NV_DCS_VM_TM_BRDI_15_I                        ((nv_items_enum_type) 2238)
#define  NV_DCS_VM_TM_BRDI_14_I                        ((nv_items_enum_type) 2239)
#define  NV_DCS_VM_TM_BRDI_13_I                        ((nv_items_enum_type) 2240)
#define  NV_GSM_1900_VM_TM_BRUI_15_I                   ((nv_items_enum_type) 2241)
#define  NV_GSM_1900_VM_TM_BRUI_14_I                   ((nv_items_enum_type) 2242)
#define  NV_GSM_1900_VM_TM_BRUI_13_I                   ((nv_items_enum_type) 2243)
#define  NV_GSM_1900_VM_TM_BRDI_15_I                   ((nv_items_enum_type) 2244)
#define  NV_GSM_1900_VM_TM_BRDI_14_I                   ((nv_items_enum_type) 2245)
#define  NV_GSM_1900_VM_TM_BRDI_13_I                   ((nv_items_enum_type) 2246)
#define  NV_GSM_VH_TM_BRUI_14_I                        ((nv_items_enum_type) 2247)
#define  NV_GSM_VH_TM_BRUI_13_I                        ((nv_items_enum_type) 2248)
#define  NV_GSM_VH_TM_BRUI_12_I                        ((nv_items_enum_type) 2249)
#define  NV_GSM_VH_TM_BRDI_14_I                        ((nv_items_enum_type) 2250)
#define  NV_GSM_VH_TM_BRDI_13_I                        ((nv_items_enum_type) 2251)
#define  NV_GSM_VH_TM_BRDI_12_I                        ((nv_items_enum_type) 2252)
#define  NV_DCS_VH_TM_BRUI_15_I                        ((nv_items_enum_type) 2253)
#define  NV_DCS_VH_TM_BRUI_14_I                        ((nv_items_enum_type) 2254)
#define  NV_DCS_VH_TM_BRUI_13_I                        ((nv_items_enum_type) 2255)
#define  NV_DCS_VH_TM_BRDI_15_I                        ((nv_items_enum_type) 2256)
#define  NV_DCS_VH_TM_BRDI_14_I                        ((nv_items_enum_type) 2257)
#define  NV_DCS_VH_TM_BRDI_13_I                        ((nv_items_enum_type) 2258)
#define  NV_GSM_1900_VH_TM_BRUI_15_I                   ((nv_items_enum_type) 2259)
#define  NV_GSM_1900_VH_TM_BRUI_14_I                   ((nv_items_enum_type) 2260)
#define  NV_GSM_1900_VH_TM_BRUI_13_I                   ((nv_items_enum_type) 2261)
#define  NV_GSM_1900_VH_TM_BRDI_15_I                   ((nv_items_enum_type) 2262)
#define  NV_GSM_1900_VH_TM_BRDI_14_I                   ((nv_items_enum_type) 2263)
#define  NV_GSM_1900_VH_TM_BRDI_13_I                   ((nv_items_enum_type) 2264)
#define  NV_GSM_VL_TH_BRUI_14_I                        ((nv_items_enum_type) 2265)
#define  NV_GSM_VL_TH_BRUI_13_I                        ((nv_items_enum_type) 2266)
#define  NV_GSM_VL_TH_BRUI_12_I                        ((nv_items_enum_type) 2267)
#define  NV_GSM_VL_TH_BRDI_14_I                        ((nv_items_enum_type) 2268)
#define  NV_GSM_VL_TH_BRDI_13_I                        ((nv_items_enum_type) 2269)
#define  NV_GSM_VL_TH_BRDI_12_I                        ((nv_items_enum_type) 2270)
#define  NV_DCS_VL_TH_BRUI_15_I                        ((nv_items_enum_type) 2271)
#define  NV_DCS_VL_TH_BRUI_14_I                        ((nv_items_enum_type) 2272)
#define  NV_DCS_VL_TH_BRUI_13_I                        ((nv_items_enum_type) 2273)
#define  NV_DCS_VL_TH_BRDI_15_I                        ((nv_items_enum_type) 2274)
#define  NV_DCS_VL_TH_BRDI_14_I                        ((nv_items_enum_type) 2275)
#define  NV_DCS_VL_TH_BRDI_13_I                        ((nv_items_enum_type) 2276)
#define  NV_GSM_1900_VL_TH_BRUI_15_I                   ((nv_items_enum_type) 2277)
#define  NV_GSM_1900_VL_TH_BRUI_14_I                   ((nv_items_enum_type) 2278)
#define  NV_GSM_1900_VL_TH_BRUI_13_I                   ((nv_items_enum_type) 2279)
#define  NV_GSM_1900_VL_TH_BRDI_15_I                   ((nv_items_enum_type) 2280)
#define  NV_GSM_1900_VL_TH_BRDI_14_I                   ((nv_items_enum_type) 2281)
#define  NV_GSM_1900_VL_TH_BRDI_13_I                   ((nv_items_enum_type) 2282)
#define  NV_GSM_VM_TH_BRUI_14_I                        ((nv_items_enum_type) 2283)
#define  NV_GSM_VM_TH_BRUI_13_I                        ((nv_items_enum_type) 2284)
#define  NV_GSM_VM_TH_BRUI_12_I                        ((nv_items_enum_type) 2285)
#define  NV_GSM_VM_TH_BRDI_14_I                        ((nv_items_enum_type) 2286)
#define  NV_GSM_VM_TH_BRDI_13_I                        ((nv_items_enum_type) 2287)
#define  NV_GSM_VM_TH_BRDI_12_I                        ((nv_items_enum_type) 2288)
#define  NV_DCS_VM_TH_BRUI_15_I                        ((nv_items_enum_type) 2289)
#define  NV_DCS_VM_TH_BRUI_14_I                        ((nv_items_enum_type) 2290)
#define  NV_DCS_VM_TH_BRUI_13_I                        ((nv_items_enum_type) 2291)
#define  NV_DCS_VM_TH_BRDI_15_I                        ((nv_items_enum_type) 2292)
#define  NV_DCS_VM_TH_BRDI_14_I                        ((nv_items_enum_type) 2293)
#define  NV_DCS_VM_TH_BRDI_13_I                        ((nv_items_enum_type) 2294)
#define  NV_GSM_1900_VM_TH_BRUI_15_I                   ((nv_items_enum_type) 2295)
#define  NV_GSM_1900_VM_TH_BRUI_14_I                   ((nv_items_enum_type) 2296)
#define  NV_GSM_1900_VM_TH_BRUI_13_I                   ((nv_items_enum_type) 2297)
#define  NV_GSM_1900_VM_TH_BRDI_15_I                   ((nv_items_enum_type) 2298)
#define  NV_GSM_1900_VM_TH_BRDI_14_I                   ((nv_items_enum_type) 2299)
#define  NV_GSM_1900_VM_TH_BRDI_13_I                   ((nv_items_enum_type) 2300)
#define  NV_GSM_VH_TH_BRUI_14_I                        ((nv_items_enum_type) 2301)
#define  NV_GSM_VH_TH_BRUI_13_I                        ((nv_items_enum_type) 2302)
#define  NV_GSM_VH_TH_BRUI_12_I                        ((nv_items_enum_type) 2303)
#define  NV_GSM_VH_TH_BRDI_14_I                        ((nv_items_enum_type) 2304)
#define  NV_GSM_VH_TH_BRDI_13_I                        ((nv_items_enum_type) 2305)
#define  NV_GSM_VH_TH_BRDI_12_I                        ((nv_items_enum_type) 2306)
#define  NV_DCS_VH_TH_BRUI_15_I                        ((nv_items_enum_type) 2307)
#define  NV_DCS_VH_TH_BRUI_14_I                        ((nv_items_enum_type) 2308)
#define  NV_DCS_VH_TH_BRUI_13_I                        ((nv_items_enum_type) 2309)
#define  NV_DCS_VH_TH_BRDI_15_I                        ((nv_items_enum_type) 2310)
#define  NV_DCS_VH_TH_BRDI_14_I                        ((nv_items_enum_type) 2311)
#define  NV_DCS_VH_TH_BRDI_13_I                        ((nv_items_enum_type) 2312)
#define  NV_GSM_1900_VH_TH_BRUI_15_I                   ((nv_items_enum_type) 2313)
#define  NV_GSM_1900_VH_TH_BRUI_14_I                   ((nv_items_enum_type) 2314)
#define  NV_GSM_1900_VH_TH_BRUI_13_I                   ((nv_items_enum_type) 2315)
#define  NV_GSM_1900_VH_TH_BRDI_15_I                   ((nv_items_enum_type) 2316)
#define  NV_GSM_1900_VH_TH_BRDI_14_I                   ((nv_items_enum_type) 2317)
#define  NV_GSM_1900_VH_TH_BRDI_13_I                   ((nv_items_enum_type) 2318)
#define  NV_GSM_C0_TX_FREQ_COMP_I                      ((nv_items_enum_type) 2319)
#define  NV_DCS_C0_TX_FREQ_COMP_I                      ((nv_items_enum_type) 2320)
#define  NV_GSM_1900_C0_TX_FREQ_COMP_I                 ((nv_items_enum_type) 2321)
#define  NV_GSM_C1_TX_FREQ_COMP_I                      ((nv_items_enum_type) 2322)
#define  NV_DCS_C1_TX_FREQ_COMP_I                      ((nv_items_enum_type) 2323)
#define  NV_GSM1900_C1_TX_FREQ_COMP_I                  ((nv_items_enum_type) 2324)
#define  NV_GSM_ENABLE_TX_FREQ_COMP_VS_PCL_I           ((nv_items_enum_type) 2325)
#define  NV_DCS_ENABLE_TX_FREQ_COMP_VS_PCL_I           ((nv_items_enum_type) 2326)
#define  NV_GSM_1900_ENABLE_TX_FREQ_COMP_VS_PCL_I      ((nv_items_enum_type) 2327)
#define  NV_THERM_COMP_THRESHOLDS_I                    ((nv_items_enum_type) 2328)
#define  NV_VBATT_COMP_THRESHOLDS_I                    ((nv_items_enum_type) 2329)
#define  NV_WCDMA_C0_TX_COMP_VS_FREQ_0_I               ((nv_items_enum_type) 2330)
#define  NV_WCDMA_C0_TX_COMP_VS_FREQ_1_I               ((nv_items_enum_type) 2331)
#define  NV_WCDMA_C1_TX_COMP_VS_FREQ_0_I               ((nv_items_enum_type) 2332)
#define  NV_WCDMA_C1_TX_COMP_VS_FREQ_1_I               ((nv_items_enum_type) 2333)
#define  NV_WCDMA_TX_LIM_VS_VOLT_OFFSET_I              ((nv_items_enum_type) 2334)
#define  NV_GSM_VL_TL_PRUI_14_I                        ((nv_items_enum_type) 2335)
#define  NV_GSM_VL_TL_PRUI_13_I                        ((nv_items_enum_type) 2336)
#define  NV_GSM_VL_TL_PRUI_12_I                        ((nv_items_enum_type) 2337)
#define  NV_GSM_VL_TL_PRDI_14_I                        ((nv_items_enum_type) 2338)
#define  NV_GSM_VL_TL_PRDI_13_I                        ((nv_items_enum_type) 2339)
#define  NV_GSM_VL_TL_PRDI_12_I                        ((nv_items_enum_type) 2340)
#define  NV_DCS_VL_TL_PRUI_15_I                        ((nv_items_enum_type) 2341)
#define  NV_DCS_VL_TL_PRUI_14_I                        ((nv_items_enum_type) 2342)
#define  NV_DCS_VL_TL_PRUI_13_I                        ((nv_items_enum_type) 2343)
#define  NV_DCS_VL_TL_PRDI_15_I                        ((nv_items_enum_type) 2344)
#define  NV_DCS_VL_TL_PRDI_14_I                        ((nv_items_enum_type) 2345)
#define  NV_DCS_VL_TL_PRDI_13_I                        ((nv_items_enum_type) 2346)
#define  NV_GSM_1900_VL_TL_PRUI_15_I                   ((nv_items_enum_type) 2347)
#define  NV_GSM_1900_VL_TL_PRUI_14_I                   ((nv_items_enum_type) 2348)
#define  NV_GSM_1900_VL_TL_PRUI_13_I                   ((nv_items_enum_type) 2349)
#define  NV_GSM_1900_VL_TL_PRDI_15_I                   ((nv_items_enum_type) 2350)
#define  NV_GSM_1900_VL_TL_PRDI_14_I                   ((nv_items_enum_type) 2351)
#define  NV_GSM_1900_VL_TL_PRDI_13_I                   ((nv_items_enum_type) 2352)
#define  NV_GSM_VM_TL_PRUI_14_I                        ((nv_items_enum_type) 2353)
#define  NV_GSM_VM_TL_PRUI_13_I                        ((nv_items_enum_type) 2354)
#define  NV_GSM_VM_TL_PRUI_12_I                        ((nv_items_enum_type) 2355)
#define  NV_GSM_VM_TL_PRDI_14_I                        ((nv_items_enum_type) 2356)
#define  NV_GSM_VM_TL_PRDI_13_I                        ((nv_items_enum_type) 2357)
#define  NV_GSM_VM_TL_PRDI_12_I                        ((nv_items_enum_type) 2358)
#define  NV_DCS_VM_TL_PRUI_15_I                        ((nv_items_enum_type) 2359)
#define  NV_DCS_VM_TL_PRUI_14_I                        ((nv_items_enum_type) 2360)
#define  NV_DCS_VM_TL_PRUI_13_I                        ((nv_items_enum_type) 2361)
#define  NV_DCS_VM_TL_PRDI_15_I                        ((nv_items_enum_type) 2362)
#define  NV_DCS_VM_TL_PRDI_14_I                        ((nv_items_enum_type) 2363)
#define  NV_DCS_VM_TL_PRDI_13_I                        ((nv_items_enum_type) 2364)
#define  NV_GSM_1900_VM_TL_PRUI_15_I                   ((nv_items_enum_type) 2365)
#define  NV_GSM_1900_VM_TL_PRUI_14_I                   ((nv_items_enum_type) 2366)
#define  NV_GSM_1900_VM_TL_PRUI_13_I                   ((nv_items_enum_type) 2367)
#define  NV_GSM_1900_VM_TL_PRDI_15_I                   ((nv_items_enum_type) 2368)
#define  NV_GSM_1900_VM_TL_PRDI_14_I                   ((nv_items_enum_type) 2369)
#define  NV_GSM_1900_VM_TL_PRDI_13_I                   ((nv_items_enum_type) 2370)
#define  NV_GSM_VH_TL_PRUI_14_I                        ((nv_items_enum_type) 2371)
#define  NV_GSM_VH_TL_PRUI_13_I                        ((nv_items_enum_type) 2372)
#define  NV_GSM_VH_TL_PRUI_12_I                        ((nv_items_enum_type) 2373)
#define  NV_GSM_VH_TL_PRDI_14_I                        ((nv_items_enum_type) 2374)
#define  NV_GSM_VH_TL_PRDI_13_I                        ((nv_items_enum_type) 2375)
#define  NV_GSM_VH_TL_PRDI_12_I                        ((nv_items_enum_type) 2376)
#define  NV_DCS_VH_TL_PRUI_15_I                        ((nv_items_enum_type) 2377)
#define  NV_DCS_VH_TL_PRUI_14_I                        ((nv_items_enum_type) 2378)
#define  NV_DCS_VH_TL_PRUI_13_I                        ((nv_items_enum_type) 2379)
#define  NV_DCS_VH_TL_PRDI_15_I                        ((nv_items_enum_type) 2380)
#define  NV_DCS_VH_TL_PRDI_14_I                        ((nv_items_enum_type) 2381)
#define  NV_DCS_VH_TL_PRDI_13_I                        ((nv_items_enum_type) 2382)
#define  NV_GSM_1900_VH_TL_PRUI_15_I                   ((nv_items_enum_type) 2383)
#define  NV_GSM_1900_VH_TL_PRUI_14_I                   ((nv_items_enum_type) 2384)
#define  NV_GSM_1900_VH_TL_PRUI_13_I                   ((nv_items_enum_type) 2385)
#define  NV_GSM_1900_VH_TL_PRDI_15_I                   ((nv_items_enum_type) 2386)
#define  NV_GSM_1900_VH_TL_PRDI_14_I                   ((nv_items_enum_type) 2387)
#define  NV_GSM_1900_VH_TL_PRDI_13_I                   ((nv_items_enum_type) 2388)
#define  NV_GSM_VL_TM_PRUI_14_I                        ((nv_items_enum_type) 2389)
#define  NV_GSM_VL_TM_PRUI_13_I                        ((nv_items_enum_type) 2390)
#define  NV_GSM_VL_TM_PRUI_12_I                        ((nv_items_enum_type) 2391)
#define  NV_GSM_VL_TM_PRDI_14_I                        ((nv_items_enum_type) 2392)
#define  NV_GSM_VL_TM_PRDI_13_I                        ((nv_items_enum_type) 2393)
#define  NV_GSM_VL_TM_PRDI_12_I                        ((nv_items_enum_type) 2394)
#define  NV_DCS_VL_TM_PRUI_15_I                        ((nv_items_enum_type) 2395)
#define  NV_DCS_VL_TM_PRUI_14_I                        ((nv_items_enum_type) 2396)
#define  NV_DCS_VL_TM_PRUI_13_I                        ((nv_items_enum_type) 2397)
#define  NV_DCS_VL_TM_PRDI_15_I                        ((nv_items_enum_type) 2398)
#define  NV_DCS_VL_TM_PRDI_14_I                        ((nv_items_enum_type) 2399)
#define  NV_DCS_VL_TM_PRDI_13_I                        ((nv_items_enum_type) 2400)
#define  NV_GSM_1900_VL_TM_PRUI_15_I                   ((nv_items_enum_type) 2401)
#define  NV_GSM_1900_VL_TM_PRUI_14_I                   ((nv_items_enum_type) 2402)
#define  NV_GSM_1900_VL_TM_PRUI_13_I                   ((nv_items_enum_type) 2403)
#define  NV_GSM_1900_VL_TM_PRDI_15_I                   ((nv_items_enum_type) 2404)
#define  NV_GSM_1900_VL_TM_PRDI_14_I                   ((nv_items_enum_type) 2405)
#define  NV_GSM_1900_VL_TM_PRDI_13_I                   ((nv_items_enum_type) 2406)
#define  NV_GSM_VM_TM_PRUI_14_I                        ((nv_items_enum_type) 2407)
#define  NV_GSM_VM_TM_PRUI_13_I                        ((nv_items_enum_type) 2408)
#define  NV_GSM_VM_TM_PRUI_12_I                        ((nv_items_enum_type) 2409)
#define  NV_GSM_VM_TM_PRDI_14_I                        ((nv_items_enum_type) 2410)
#define  NV_GSM_VM_TM_PRDI_13_I                        ((nv_items_enum_type) 2411)
#define  NV_GSM_VM_TM_PRDI_12_I                        ((nv_items_enum_type) 2412)
#define  NV_DCS_VM_TM_PRUI_15_I                        ((nv_items_enum_type) 2413)
#define  NV_DCS_VM_TM_PRUI_14_I                        ((nv_items_enum_type) 2414)
#define  NV_DCS_VM_TM_PRUI_13_I                        ((nv_items_enum_type) 2415)
#define  NV_DCS_VM_TM_PRDI_15_I                        ((nv_items_enum_type) 2416)
#define  NV_DCS_VM_TM_PRDI_14_I                        ((nv_items_enum_type) 2417)
#define  NV_DCS_VM_TM_PRDI_13_I                        ((nv_items_enum_type) 2418)
#define  NV_GSM_1900_VM_TM_PRUI_15_I                   ((nv_items_enum_type) 2419)
#define  NV_GSM_1900_VM_TM_PRUI_14_I                   ((nv_items_enum_type) 2420)
#define  NV_GSM_1900_VM_TM_PRUI_13_I                   ((nv_items_enum_type) 2421)
#define  NV_GSM_1900_VM_TM_PRDI_15_I                   ((nv_items_enum_type) 2422)
#define  NV_GSM_1900_VM_TM_PRDI_14_I                   ((nv_items_enum_type) 2423)
#define  NV_GSM_1900_VM_TM_PRDI_13_I                   ((nv_items_enum_type) 2424)
#define  NV_GSM_VH_TM_PRUI_14_I                        ((nv_items_enum_type) 2425)
#define  NV_GSM_VH_TM_PRUI_13_I                        ((nv_items_enum_type) 2426)
#define  NV_GSM_VH_TM_PRUI_12_I                        ((nv_items_enum_type) 2427)
#define  NV_GSM_VH_TM_PRDI_14_I                        ((nv_items_enum_type) 2428)
#define  NV_GSM_VH_TM_PRDI_13_I                        ((nv_items_enum_type) 2429)
#define  NV_GSM_VH_TM_PRDI_12_I                        ((nv_items_enum_type) 2430)
#define  NV_DCS_VH_TM_PRUI_15_I                        ((nv_items_enum_type) 2431)
#define  NV_DCS_VH_TM_PRUI_14_I                        ((nv_items_enum_type) 2432)
#define  NV_DCS_VH_TM_PRUI_13_I                        ((nv_items_enum_type) 2433)
#define  NV_DCS_VH_TM_PRDI_15_I                        ((nv_items_enum_type) 2434)
#define  NV_DCS_VH_TM_PRDI_14_I                        ((nv_items_enum_type) 2435)
#define  NV_DCS_VH_TM_PRDI_13_I                        ((nv_items_enum_type) 2436)
#define  NV_GSM_1900_VH_TM_PRUI_15_I                   ((nv_items_enum_type) 2437)
#define  NV_GSM_1900_VH_TM_PRUI_14_I                   ((nv_items_enum_type) 2438)
#define  NV_GSM_1900_VH_TM_PRUI_13_I                   ((nv_items_enum_type) 2439)
#define  NV_GSM_1900_VH_TM_PRDI_15_I                   ((nv_items_enum_type) 2440)
#define  NV_GSM_1900_VH_TM_PRDI_14_I                   ((nv_items_enum_type) 2441)
#define  NV_GSM_1900_VH_TM_PRDI_13_I                   ((nv_items_enum_type) 2442)
#define  NV_GSM_VL_TH_PRUI_14_I                        ((nv_items_enum_type) 2443)
#define  NV_GSM_VL_TH_PRUI_13_I                        ((nv_items_enum_type) 2444)
#define  NV_GSM_VL_TH_PRUI_12_I                        ((nv_items_enum_type) 2445)
#define  NV_GSM_VL_TH_PRDI_14_I                        ((nv_items_enum_type) 2446)
#define  NV_GSM_VL_TH_PRDI_13_I                        ((nv_items_enum_type) 2447)
#define  NV_GSM_VL_TH_PRDI_12_I                        ((nv_items_enum_type) 2448)
#define  NV_DCS_VL_TH_PRUI_15_I                        ((nv_items_enum_type) 2449)
#define  NV_DCS_VL_TH_PRUI_14_I                        ((nv_items_enum_type) 2450)
#define  NV_DCS_VL_TH_PRUI_13_I                        ((nv_items_enum_type) 2451)
#define  NV_DCS_VL_TH_PRDI_15_I                        ((nv_items_enum_type) 2452)
#define  NV_DCS_VL_TH_PRDI_14_I                        ((nv_items_enum_type) 2453)
#define  NV_DCS_VL_TH_PRDI_13_I                        ((nv_items_enum_type) 2454)
#define  NV_GSM_1900_VL_TH_PRUI_15_I                   ((nv_items_enum_type) 2455)
#define  NV_GSM_1900_VL_TH_PRUI_14_I                   ((nv_items_enum_type) 2456)
#define  NV_GSM_1900_VL_TH_PRUI_13_I                   ((nv_items_enum_type) 2457)
#define  NV_GSM_1900_VL_TH_PRDI_15_I                   ((nv_items_enum_type) 2458)
#define  NV_GSM_1900_VL_TH_PRDI_14_I                   ((nv_items_enum_type) 2459)
#define  NV_GSM_1900_VL_TH_PRDI_13_I                   ((nv_items_enum_type) 2460)
#define  NV_GSM_VM_TH_PRUI_14_I                        ((nv_items_enum_type) 2461)
#define  NV_GSM_VM_TH_PRUI_13_I                        ((nv_items_enum_type) 2462)
#define  NV_GSM_VM_TH_PRUI_12_I                        ((nv_items_enum_type) 2463)
#define  NV_GSM_VM_TH_PRDI_14_I                        ((nv_items_enum_type) 2464)
#define  NV_GSM_VM_TH_PRDI_13_I                        ((nv_items_enum_type) 2465)
#define  NV_GSM_VM_TH_PRDI_12_I                        ((nv_items_enum_type) 2466)
#define  NV_DCS_VM_TH_PRUI_15_I                        ((nv_items_enum_type) 2467)
#define  NV_DCS_VM_TH_PRUI_14_I                        ((nv_items_enum_type) 2468)
#define  NV_DCS_VM_TH_PRUI_13_I                        ((nv_items_enum_type) 2469)
#define  NV_DCS_VM_TH_PRDI_15_I                        ((nv_items_enum_type) 2470)
#define  NV_DCS_VM_TH_PRDI_14_I                        ((nv_items_enum_type) 2471)
#define  NV_DCS_VM_TH_PRDI_13_I                        ((nv_items_enum_type) 2472)
#define  NV_GSM_1900_VM_TH_PRUI_15_I                   ((nv_items_enum_type) 2473)
#define  NV_GSM_1900_VM_TH_PRUI_14_I                   ((nv_items_enum_type) 2474)
#define  NV_GSM_1900_VM_TH_PRUI_13_I                   ((nv_items_enum_type) 2475)
#define  NV_GSM_1900_VM_TH_PRDI_15_I                   ((nv_items_enum_type) 2476)
#define  NV_GSM_1900_VM_TH_PRDI_14_I                   ((nv_items_enum_type) 2477)
#define  NV_GSM_1900_VM_TH_PRDI_13_I                   ((nv_items_enum_type) 2478)
#define  NV_GSM_VH_TH_PRUI_14_I                        ((nv_items_enum_type) 2479)
#define  NV_GSM_VH_TH_PRUI_13_I                        ((nv_items_enum_type) 2480)
#define  NV_GSM_VH_TH_PRUI_12_I                        ((nv_items_enum_type) 2481)
#define  NV_GSM_VH_TH_PRDI_14_I                        ((nv_items_enum_type) 2482)
#define  NV_GSM_VH_TH_PRDI_13_I                        ((nv_items_enum_type) 2483)
#define  NV_GSM_VH_TH_PRDI_12_I                        ((nv_items_enum_type) 2484)
#define  NV_DCS_VH_TH_PRUI_15_I                        ((nv_items_enum_type) 2485)
#define  NV_DCS_VH_TH_PRUI_14_I                        ((nv_items_enum_type) 2486)
#define  NV_DCS_VH_TH_PRUI_13_I                        ((nv_items_enum_type) 2487)
#define  NV_DCS_VH_TH_PRDI_15_I                        ((nv_items_enum_type) 2488)
#define  NV_DCS_VH_TH_PRDI_14_I                        ((nv_items_enum_type) 2489)
#define  NV_DCS_VH_TH_PRDI_13_I                        ((nv_items_enum_type) 2490)
#define  NV_GSM_1900_VH_TH_PRUI_15_I                   ((nv_items_enum_type) 2491)
#define  NV_GSM_1900_VH_TH_PRUI_14_I                   ((nv_items_enum_type) 2492)
#define  NV_GSM_1900_VH_TH_PRUI_13_I                   ((nv_items_enum_type) 2493)
#define  NV_GSM_1900_VH_TH_PRDI_15_I                   ((nv_items_enum_type) 2494)
#define  NV_GSM_1900_VH_TH_PRDI_14_I                   ((nv_items_enum_type) 2495)
#define  NV_GSM_1900_VH_TH_PRDI_13_I                   ((nv_items_enum_type) 2496)
#define  NV_FACTORY_DATA_1_I                           ((nv_items_enum_type) 2497)
#define  NV_FACTORY_DATA_2_I                           ((nv_items_enum_type) 2498)
#define  NV_FACTORY_DATA_3_I                           ((nv_items_enum_type) 2499)
#define  NV_FACTORY_DATA_4_I                           ((nv_items_enum_type) 2500)
#define  NV_GSM_PRUI_11_I                              ((nv_items_enum_type) 2501)
#define  NV_GSM_1900_PRDI_00_I                         ((nv_items_enum_type) 2502)
#define  NV_GSM_1900_PRDI_01_I                         ((nv_items_enum_type) 2503)
#define  NV_GSM_1900_PRDI_11_I                         ((nv_items_enum_type) 2504)
#define  NV_GSM_1900_PRDI_08_I                         ((nv_items_enum_type) 2505)
#define  NV_APPX5_PREF_I                               ((nv_items_enum_type) 2506)
#define  NV_WLAN_NET_SEL_MODE_PREF_I                   ((nv_items_enum_type) 2507)
#define  NV_EDGE_FEATURE_SUPPORT_I                     ((nv_items_enum_type) 2508)
#define  NV_EDGE_MULTISLOT_CLASS_I                     ((nv_items_enum_type) 2509)
#define  NV_EDGE_8PSK_POWER_CLASS_I                    ((nv_items_enum_type) 2510)
#define  NV_EDGE_8PSK_POWER_CAPABILITY_I               ((nv_items_enum_type) 2511)
#define  NV_GERAN_FEATURE_PACK_1_I                     ((nv_items_enum_type) 2512)
#define  NV_GSM_AMAM_MAX_PWR_I                         ((nv_items_enum_type) 2513)
#define  NV_GSM_AMAM_MIN_PWR_I                         ((nv_items_enum_type) 2514)
#define  NV_DCS_AMAM_MAX_PWR_I                         ((nv_items_enum_type) 2515)
#define  NV_DCS_AMAM_MIN_PWR_I                         ((nv_items_enum_type) 2516)
#define  NV_GSM_850_AMAM_MAX_PWR_I                     ((nv_items_enum_type) 2517)
#define  NV_GSM_850_AMAM_MIN_PWR_I                     ((nv_items_enum_type) 2518)
#define  NV_GSM_1900_AMAM_MAX_PWR_I                    ((nv_items_enum_type) 2519)
#define  NV_GSM_1900_AMAM_MIN_PWR_I                    ((nv_items_enum_type) 2520)
#define  NV_GSM_AMAM_MASTER_TBL_SEG1_F1_I              ((nv_items_enum_type) 2521)
#define  NV_GSM_AMAM_MASTER_TBL_SEG2_F1_I              ((nv_items_enum_type) 2522)
#define  NV_GSM_AMAM_MASTER_TBL_SEG3_F1_I              ((nv_items_enum_type) 2523)
#define  NV_GSM_AMAM_MASTER_TBL_SEG4_F1_I              ((nv_items_enum_type) 2524)
#define  NV_GSM_AMAM_MASTER_TBL_SEG5_F1_I              ((nv_items_enum_type) 2525)
#define  NV_GSM_AMAM_MASTER_TBL_SEG6_F1_I              ((nv_items_enum_type) 2526)
#define  NV_GSM_AMAM_MASTER_TBL_SEG7_F1_I              ((nv_items_enum_type) 2527)
#define  NV_GSM_AMAM_MASTER_TBL_SEG8_F1_I              ((nv_items_enum_type) 2528)
#define  NV_DCS_AMAM_MASTER_TBL_SEG1_F1_I              ((nv_items_enum_type) 2529)
#define  NV_DCS_AMAM_MASTER_TBL_SEG2_F1_I              ((nv_items_enum_type) 2530)
#define  NV_DCS_AMAM_MASTER_TBL_SEG3_F1_I              ((nv_items_enum_type) 2531)
#define  NV_DCS_AMAM_MASTER_TBL_SEG4_F1_I              ((nv_items_enum_type) 2532)
#define  NV_DCS_AMAM_MASTER_TBL_SEG5_F1_I              ((nv_items_enum_type) 2533)
#define  NV_DCS_AMAM_MASTER_TBL_SEG6_F1_I              ((nv_items_enum_type) 2534)
#define  NV_DCS_AMAM_MASTER_TBL_SEG7_F1_I              ((nv_items_enum_type) 2535)
#define  NV_DCS_AMAM_MASTER_TBL_SEG8_F1_I              ((nv_items_enum_type) 2536)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG1_F1_I          ((nv_items_enum_type) 2537)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG2_F1_I          ((nv_items_enum_type) 2538)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG3_F1_I          ((nv_items_enum_type) 2539)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG4_F1_I          ((nv_items_enum_type) 2540)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG5_F1_I          ((nv_items_enum_type) 2541)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG6_F1_I          ((nv_items_enum_type) 2542)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG7_F1_I          ((nv_items_enum_type) 2543)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG8_F1_I          ((nv_items_enum_type) 2544)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG1_F1_I         ((nv_items_enum_type) 2545)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG2_F1_I         ((nv_items_enum_type) 2546)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG3_F1_I         ((nv_items_enum_type) 2547)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG4_F1_I         ((nv_items_enum_type) 2548)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG5_F1_I         ((nv_items_enum_type) 2549)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG6_F1_I         ((nv_items_enum_type) 2550)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG7_F1_I         ((nv_items_enum_type) 2551)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG8_F1_I         ((nv_items_enum_type) 2552)
#define  NV_GSM_AMAM_MASTER_TBL_SEG1_F2_I              ((nv_items_enum_type) 2553)
#define  NV_GSM_AMAM_MASTER_TBL_SEG2_F2_I              ((nv_items_enum_type) 2554)
#define  NV_GSM_AMAM_MASTER_TBL_SEG3_F2_I              ((nv_items_enum_type) 2555)
#define  NV_GSM_AMAM_MASTER_TBL_SEG4_F2_I              ((nv_items_enum_type) 2556)
#define  NV_GSM_AMAM_MASTER_TBL_SEG5_F2_I              ((nv_items_enum_type) 2557)
#define  NV_GSM_AMAM_MASTER_TBL_SEG6_F2_I              ((nv_items_enum_type) 2558)
#define  NV_GSM_AMAM_MASTER_TBL_SEG7_F2_I              ((nv_items_enum_type) 2559)
#define  NV_GSM_AMAM_MASTER_TBL_SEG8_F2_I              ((nv_items_enum_type) 2560)
#define  NV_DCS_AMAM_MASTER_TBL_SEG1_F2_I              ((nv_items_enum_type) 2561)
#define  NV_DCS_AMAM_MASTER_TBL_SEG2_F2_I              ((nv_items_enum_type) 2562)
#define  NV_DCS_AMAM_MASTER_TBL_SEG3_F2_I              ((nv_items_enum_type) 2563)
#define  NV_DCS_AMAM_MASTER_TBL_SEG4_F2_I              ((nv_items_enum_type) 2564)
#define  NV_DCS_AMAM_MASTER_TBL_SEG5_F2_I              ((nv_items_enum_type) 2565)
#define  NV_DCS_AMAM_MASTER_TBL_SEG6_F2_I              ((nv_items_enum_type) 2566)
#define  NV_DCS_AMAM_MASTER_TBL_SEG7_F2_I              ((nv_items_enum_type) 2567)
#define  NV_DCS_AMAM_MASTER_TBL_SEG8_F2_I              ((nv_items_enum_type) 2568)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG1_F2_I          ((nv_items_enum_type) 2569)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG2_F2_I          ((nv_items_enum_type) 2570)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG3_F2_I          ((nv_items_enum_type) 2571)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG4_F2_I          ((nv_items_enum_type) 2572)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG5_F2_I          ((nv_items_enum_type) 2573)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG6_F2_I          ((nv_items_enum_type) 2574)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG7_F2_I          ((nv_items_enum_type) 2575)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG8_F2_I          ((nv_items_enum_type) 2576)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG1_F2_I         ((nv_items_enum_type) 2577)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG2_F2_I         ((nv_items_enum_type) 2578)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG3_F2_I         ((nv_items_enum_type) 2579)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG4_F2_I         ((nv_items_enum_type) 2580)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG5_F2_I         ((nv_items_enum_type) 2581)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG6_F2_I         ((nv_items_enum_type) 2582)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG7_F2_I         ((nv_items_enum_type) 2583)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG8_F2_I         ((nv_items_enum_type) 2584)
#define  NV_GSM_AMPM_MASTER_TBL_SEG1_F1_I              ((nv_items_enum_type) 2585)
#define  NV_GSM_AMPM_MASTER_TBL_SEG2_F1_I              ((nv_items_enum_type) 2586)
#define  NV_GSM_AMPM_MASTER_TBL_SEG3_F1_I              ((nv_items_enum_type) 2587)
#define  NV_GSM_AMPM_MASTER_TBL_SEG4_F1_I              ((nv_items_enum_type) 2588)
#define  NV_GSM_AMPM_MASTER_TBL_SEG5_F1_I              ((nv_items_enum_type) 2589)
#define  NV_GSM_AMPM_MASTER_TBL_SEG6_F1_I              ((nv_items_enum_type) 2590)
#define  NV_GSM_AMPM_MASTER_TBL_SEG7_F1_I              ((nv_items_enum_type) 2591)
#define  NV_GSM_AMPM_MASTER_TBL_SEG8_F1_I              ((nv_items_enum_type) 2592)
#define  NV_DCS_AMPM_MASTER_TBL_SEG1_F1_I              ((nv_items_enum_type) 2593)
#define  NV_DCS_AMPM_MASTER_TBL_SEG2_F1_I              ((nv_items_enum_type) 2594)
#define  NV_DCS_AMPM_MASTER_TBL_SEG3_F1_I              ((nv_items_enum_type) 2595)
#define  NV_DCS_AMPM_MASTER_TBL_SEG4_F1_I              ((nv_items_enum_type) 2596)
#define  NV_DCS_AMPM_MASTER_TBL_SEG5_F1_I              ((nv_items_enum_type) 2597)
#define  NV_DCS_AMPM_MASTER_TBL_SEG6_F1_I              ((nv_items_enum_type) 2598)
#define  NV_DCS_AMPM_MASTER_TBL_SEG7_F1_I              ((nv_items_enum_type) 2599)
#define  NV_DCS_AMPM_MASTER_TBL_SEG8_F1_I              ((nv_items_enum_type) 2600)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG1_F1_I          ((nv_items_enum_type) 2601)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG2_F1_I          ((nv_items_enum_type) 2602)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG3_F1_I          ((nv_items_enum_type) 2603)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG4_F1_I          ((nv_items_enum_type) 2604)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG5_F1_I          ((nv_items_enum_type) 2605)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG6_F1_I          ((nv_items_enum_type) 2606)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG7_F1_I          ((nv_items_enum_type) 2607)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG8_F1_I          ((nv_items_enum_type) 2608)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG1_F1_I         ((nv_items_enum_type) 2609)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG2_F1_I         ((nv_items_enum_type) 2610)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG3_F1_I         ((nv_items_enum_type) 2611)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG4_F1_I         ((nv_items_enum_type) 2612)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG5_F1_I         ((nv_items_enum_type) 2613)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG6_F1_I         ((nv_items_enum_type) 2614)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG7_F1_I         ((nv_items_enum_type) 2615)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG8_F1_I         ((nv_items_enum_type) 2616)
#define  NV_GSM_AMPM_MASTER_TBL_SEG1_F2_I              ((nv_items_enum_type) 2617)
#define  NV_GSM_AMPM_MASTER_TBL_SEG2_F2_I              ((nv_items_enum_type) 2618)
#define  NV_GSM_AMPM_MASTER_TBL_SEG3_F2_I              ((nv_items_enum_type) 2619)
#define  NV_GSM_AMPM_MASTER_TBL_SEG4_F2_I              ((nv_items_enum_type) 2620)
#define  NV_GSM_AMPM_MASTER_TBL_SEG5_F2_I              ((nv_items_enum_type) 2621)
#define  NV_GSM_AMPM_MASTER_TBL_SEG6_F2_I              ((nv_items_enum_type) 2622)
#define  NV_GSM_AMPM_MASTER_TBL_SEG7_F2_I              ((nv_items_enum_type) 2623)
#define  NV_GSM_AMPM_MASTER_TBL_SEG8_F2_I              ((nv_items_enum_type) 2624)
#define  NV_DCS_AMPM_MASTER_TBL_SEG1_F2_I              ((nv_items_enum_type) 2625)
#define  NV_DCS_AMPM_MASTER_TBL_SEG2_F2_I              ((nv_items_enum_type) 2626)
#define  NV_DCS_AMPM_MASTER_TBL_SEG3_F2_I              ((nv_items_enum_type) 2627)
#define  NV_DCS_AMPM_MASTER_TBL_SEG4_F2_I              ((nv_items_enum_type) 2628)
#define  NV_DCS_AMPM_MASTER_TBL_SEG5_F2_I              ((nv_items_enum_type) 2629)
#define  NV_DCS_AMPM_MASTER_TBL_SEG6_F2_I              ((nv_items_enum_type) 2630)
#define  NV_DCS_AMPM_MASTER_TBL_SEG7_F2_I              ((nv_items_enum_type) 2631)
#define  NV_DCS_AMPM_MASTER_TBL_SEG8_F2_I              ((nv_items_enum_type) 2632)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG1_F2_I          ((nv_items_enum_type) 2633)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG2_F2_I          ((nv_items_enum_type) 2634)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG3_F2_I          ((nv_items_enum_type) 2635)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG4_F2_I          ((nv_items_enum_type) 2636)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG5_F2_I          ((nv_items_enum_type) 2637)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG6_F2_I          ((nv_items_enum_type) 2638)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG7_F2_I          ((nv_items_enum_type) 2639)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG8_F2_I          ((nv_items_enum_type) 2640)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG1_F2_I         ((nv_items_enum_type) 2641)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG2_F2_I         ((nv_items_enum_type) 2642)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG3_F2_I         ((nv_items_enum_type) 2643)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG4_F2_I         ((nv_items_enum_type) 2644)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG5_F2_I         ((nv_items_enum_type) 2645)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG6_F2_I         ((nv_items_enum_type) 2646)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG7_F2_I         ((nv_items_enum_type) 2647)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG8_F2_I         ((nv_items_enum_type) 2648)
#define  NV_GSM_CALPATH_RSB_A_G1_I                     ((nv_items_enum_type) 2649)
#define  NV_GSM_CALPATH_RSB_B_G1_I                     ((nv_items_enum_type) 2650)
#define  NV_GSM_850_CALPATH_RSB_A_G1_I                 ((nv_items_enum_type) 2651)
#define  NV_GSM_850_CALPATH_RSB_B_G1_I                 ((nv_items_enum_type) 2652)
#define  NV_DCS_CALPATH_RSB_A_G1_I                     ((nv_items_enum_type) 2653)
#define  NV_DCS_CALPATH_RSB_B_G1_I                     ((nv_items_enum_type) 2654)
#define  NV_GSM_1900_CALPATH_RSB_A_G1_I                ((nv_items_enum_type) 2655)
#define  NV_GSM_1900_CALPATH_RSB_B_G1_I                ((nv_items_enum_type) 2656)
#define  NV_GSM_CALPATH_RSB_A_G2_I                     ((nv_items_enum_type) 2657)
#define  NV_GSM_CALPATH_RSB_B_G2_I                     ((nv_items_enum_type) 2658)
#define  NV_GSM_850_CALPATH_RSB_A_G2_I                 ((nv_items_enum_type) 2659)
#define  NV_GSM_850_CALPATH_RSB_B_G2_I                 ((nv_items_enum_type) 2660)
#define  NV_DCS_CALPATH_RSB_A_G2_I                     ((nv_items_enum_type) 2661)
#define  NV_DCS_CALPATH_RSB_B_G2_I                     ((nv_items_enum_type) 2662)
#define  NV_GSM_1900_CALPATH_RSB_A_G2_I                ((nv_items_enum_type) 2663)
#define  NV_GSM_1900_CALPATH_RSB_B_G2_I                ((nv_items_enum_type) 2664)
#define  NV_GSM_AMAM_GAIN_LOW_TEMP_I                   ((nv_items_enum_type) 2665)
#define  NV_GSM_AMAM_DC_LOW_TEMP_I                     ((nv_items_enum_type) 2666)
#define  NV_GSM_AMAM_GAIN_HIGH_TEMP_I                  ((nv_items_enum_type) 2667)
#define  NV_GSM_AMAM_DC_HIGH_TEMP_I                    ((nv_items_enum_type) 2668)
#define  NV_GSM_AMAM_GAIN_NOM_TEMP_I                   ((nv_items_enum_type) 2669)
#define  NV_GSM_AMAM_DC_NOM_TEMP_I                     ((nv_items_enum_type) 2670)
#define  NV_GSM_850_AMAM_GAIN_LOW_TEMP_I               ((nv_items_enum_type) 2671)
#define  NV_GSM_850_AMAM_DC_LOW_TEMP_I                 ((nv_items_enum_type) 2672)
#define  NV_GSM_850_AMAM_GAIN_HIGH_TEMP_I              ((nv_items_enum_type) 2673)
#define  NV_GSM_850_AMAM_DC_HIGH_TEMP_I                ((nv_items_enum_type) 2674)
#define  NV_GSM_850_AMAM_GAIN_NOM_TEMP_I               ((nv_items_enum_type) 2675)
#define  NV_GSM_850_AMAM_DC_NOM_TEMP_I                 ((nv_items_enum_type) 2676)
#define  NV_DCS_AMAM_GAIN_LOW_TEMP_I                   ((nv_items_enum_type) 2677)
#define  NV_DCS_AMAM_DC_LOW_TEMP_I                     ((nv_items_enum_type) 2678)
#define  NV_DCS_AMAM_GAIN_HIGH_TEMP_I                  ((nv_items_enum_type) 2679)
#define  NV_DCS_AMAM_DC_HIGH_TEMP_I                    ((nv_items_enum_type) 2680)
#define  NV_DCS_AMAM_GAIN_NOM_TEMP_I                   ((nv_items_enum_type) 2681)
#define  NV_DCS_AMAM_DC_NOM_TEMP_I                     ((nv_items_enum_type) 2682)
#define  NV_GSM_1900_AMAM_GAIN_LOW_TEMP_I              ((nv_items_enum_type) 2683)
#define  NV_GSM_1900_AMAM_DC_LOW_TEMP_I                ((nv_items_enum_type) 2684)
#define  NV_GSM_1900_AMAM_GAIN_HIGH_TEMP_I             ((nv_items_enum_type) 2685)
#define  NV_GSM_1900_AMAM_DC_HIGH_TEMP_I               ((nv_items_enum_type) 2686)
#define  NV_GSM_1900_AMAM_GAIN_NOM_TEMP_I              ((nv_items_enum_type) 2687)
#define  NV_GSM_1900_AMAM_DC_NOM_TEMP_I                ((nv_items_enum_type) 2688)
#define  NV_GSM_AMAM_ARFCN_I                           ((nv_items_enum_type) 2689)
#define  NV_DCS_AMAM_ARFCN_I                           ((nv_items_enum_type) 2690)
#define  NV_GSM_850_AMAM_ARFCN_I                       ((nv_items_enum_type) 2691)
#define  NV_GSM_1900_AMAM_ARFCN_I                      ((nv_items_enum_type) 2692)
#define  NV_ABNORMAL_EXIT_COUNT_I                      ((nv_items_enum_type) 2693)
#define  NV_SYS_STRUCT_FCT_FILE_NAME_I                 ((nv_items_enum_type) 2694)
#define  NV_SYS_STRUCT_FCT_FILE_XSUM_I                 ((nv_items_enum_type) 2695)
#define  NV_SYS_CUSTOM_INI_FILE_NAME_I                 ((nv_items_enum_type) 2696)
#define  NV_SYS_CUSTOM_INI_FILE_XSUM_I                 ((nv_items_enum_type) 2697)
#define  NV_SYS_STD_MAP_FILE_VER_I                     ((nv_items_enum_type) 2698)
#define  NV_SYS_STD_MAP_FILE_XSUM_I                    ((nv_items_enum_type) 2699)
#define  NV_SYS_SPC_DELTA_FILE_VER_I                   ((nv_items_enum_type) 2700)
#define  NV_SYS_SPC_DELTA_FILE_XSUM_I                  ((nv_items_enum_type) 2701)
#define  NV_LCD_ID_I                                   ((nv_items_enum_type) 2702)
#define  NV_WCDMA_PA_RANGE_FOR_DVS_I                   ((nv_items_enum_type) 2703)
#define  NV_WCDMA_PA_COMPENSATE_UP_WITH_DVS_I          ((nv_items_enum_type) 2704)
#define  NV_WCDMA_PA_COMPENSATE_DN_WITH_DVS_I          ((nv_items_enum_type) 2705)
#define  NV_WCDMA_1900_PA_RANGE_FOR_DVS_I              ((nv_items_enum_type) 2706)
#define  NV_WCDMA_1900_PA_COMPENSATE_UP_WITH_DVS_I     ((nv_items_enum_type) 2707)
#define  NV_WCDMA_1900_PA_COMPENSATE_DN_WITH_DVS_I     ((nv_items_enum_type) 2708)
#define  NV_WCDMA_800_PA_RANGE_FOR_DVS_I               ((nv_items_enum_type) 2709)
#define  NV_WCDMA_800_PA_COMPENSATE_UP_WITH_DVS_I      ((nv_items_enum_type) 2710)
#define  NV_WCDMA_800_PA_COMPENSATE_DN_WITH_DVS_I      ((nv_items_enum_type) 2711)
#define  NV_WCDMA_MAX_PWR_BACKOFF_VOLTAGES_I           ((nv_items_enum_type) 2712)
#define  NV_WCDMA_MAX_PWR_BACKOFF_VOLT1_I              ((nv_items_enum_type) 2713)
#define  NV_WCDMA_MAX_PWR_BACKOFF_VOLT2_I              ((nv_items_enum_type) 2714)
#define  NV_WCDMA_MAX_PWR_BACKOFF_VOLT3_I              ((nv_items_enum_type) 2715)
#define  NV_WCDMA_1900_MAX_PWR_BACKOFF_VOLTAGES_I      ((nv_items_enum_type) 2716)
#define  NV_WCDMA_1900_MAX_PWR_BACKOFF_VOLT1_I         ((nv_items_enum_type) 2717)
#define  NV_WCDMA_1900_MAX_PWR_BACKOFF_VOLT2_I         ((nv_items_enum_type) 2718)
#define  NV_WCDMA_1900_MAX_PWR_BACKOFF_VOLT3_I         ((nv_items_enum_type) 2719)
#define  NV_WCDMA_800_MAX_PWR_BACKOFF_VOLTAGES_I       ((nv_items_enum_type) 2720)
#define  NV_WCDMA_800_MAX_PWR_BACKOFF_VOLT1_I          ((nv_items_enum_type) 2721)
#define  NV_WCDMA_800_MAX_PWR_BACKOFF_VOLT2_I          ((nv_items_enum_type) 2722)
#define  NV_WCDMA_800_MAX_PWR_BACKOFF_VOLT3_I          ((nv_items_enum_type) 2723)
#define  NV_WCDMA_HS_R1_RISE_I                         ((nv_items_enum_type) 2724)
#define  NV_WCDMA_HS_R1_FALL_I                         ((nv_items_enum_type) 2725)
#define  NV_WCDMA_HS_R2_RISE_I                         ((nv_items_enum_type) 2726)
#define  NV_WCDMA_HS_R2_FALL_I                         ((nv_items_enum_type) 2727)
#define  NV_WCDMA_HS_R3_RISE_I                         ((nv_items_enum_type) 2728)
#define  NV_WCDMA_HS_R3_FALL_I                         ((nv_items_enum_type) 2729)
#define  NV_WCDMA_1900_HS_R1_RISE_I                    ((nv_items_enum_type) 2730)
#define  NV_WCDMA_1900_HS_R1_FALL_I                    ((nv_items_enum_type) 2731)
#define  NV_WCDMA_1900_HS_R2_RISE_I                    ((nv_items_enum_type) 2732)
#define  NV_WCDMA_1900_HS_R2_FALL_I                    ((nv_items_enum_type) 2733)
#define  NV_WCDMA_1900_HS_R3_RISE_I                    ((nv_items_enum_type) 2734)
#define  NV_WCDMA_1900_HS_R3_FALL_I                    ((nv_items_enum_type) 2735)
#define  NV_WCDMA_800_HS_R1_RISE_I                     ((nv_items_enum_type) 2736)
#define  NV_WCDMA_800_HS_R1_FALL_I                     ((nv_items_enum_type) 2737)
#define  NV_WCDMA_800_HS_R2_RISE_I                     ((nv_items_enum_type) 2738)
#define  NV_WCDMA_800_HS_R2_FALL_I                     ((nv_items_enum_type) 2739)
#define  NV_WCDMA_800_HS_R3_RISE_I                     ((nv_items_enum_type) 2740)
#define  NV_WCDMA_800_HS_R3_FALL_I                     ((nv_items_enum_type) 2741)
#define  NV_GSM_AUTOCAL_PWR_DAC_F1_I                   ((nv_items_enum_type) 2742)
#define  NV_GSM_AMAM_DYNAMIC_RANGE_I                   ((nv_items_enum_type) 2743)
#define  NV_DCS_AUTOCAL_PWR_DAC_F1_I                   ((nv_items_enum_type) 2744)
#define  NV_DCS_AMAM_DYNAMIC_RANGE_I                   ((nv_items_enum_type) 2745)
#define  NV_GSM_850_AUTOCAL_PWR_DAC_F1_I               ((nv_items_enum_type) 2746)
#define  NV_GSM_850_AMAM_DYNAMIC_RANGE_I               ((nv_items_enum_type) 2747)
#define  NV_GSM_1900_AUTOCAL_PWR_DAC_F1_I              ((nv_items_enum_type) 2748)
#define  NV_GSM_1900_AMAM_DYNAMIC_RANGE_I              ((nv_items_enum_type) 2749)
#define  NV_GSM_CALPATH_RSB_I                          ((nv_items_enum_type) 2750)
#define  NV_DCS_CALPATH_RSB_I                          ((nv_items_enum_type) 2751)
#define  NV_GSM_850_CALPATH_RSB_I                      ((nv_items_enum_type) 2752)
#define  NV_GSM_1900_CALPATH_RSB_I                     ((nv_items_enum_type) 2753)
#define  NV_GSM_AMAM_SYS_GAIN_DC_CORR_I                ((nv_items_enum_type) 2754)
#define  NV_GSM_850_AMAM_SYS_GAIN_DC_CORR_I            ((nv_items_enum_type) 2755)
#define  NV_DCS_AMAM_SYS_GAIN_DC_CORR_I                ((nv_items_enum_type) 2756)
#define  NV_GSM_1900_AMAM_SYS_GAIN_DC_CORR_I           ((nv_items_enum_type) 2757)
#define  NV_GSM_AMAM_ARFCN_F1_I                        ((nv_items_enum_type) 2758)
#define  NV_DCS_AMAM_ARFCN_F1_I                        ((nv_items_enum_type) 2759)
#define  NV_GSM_850_AMAM_ARFCN_F1_I                    ((nv_items_enum_type) 2760)
#define  NV_GSM_1900_AMAM_ARFCN_F1_I                   ((nv_items_enum_type) 2761)
#define  NV_GSM_AMAM_ARFCN_F2_I                        ((nv_items_enum_type) 2762)
#define  NV_DCS_AMAM_ARFCN_F2_I                        ((nv_items_enum_type) 2763)
#define  NV_GSM_850_AMAM_ARFCN_F2_I                    ((nv_items_enum_type) 2764)
#define  NV_GSM_1900_AMAM_ARFCN_F2_I                   ((nv_items_enum_type) 2765)
#define  NV_GSM_AUTOCAL_PWR_DAC_F2_I                   ((nv_items_enum_type) 2766)
#define  NV_DCS_AUTOCAL_PWR_DAC_F2_I                   ((nv_items_enum_type) 2767)
#define  NV_GSM_850_AUTOCAL_PWR_DAC_F2_I               ((nv_items_enum_type) 2768)
#define  NV_GSM_1900_AUTOCAL_PWR_DAC_F2_I              ((nv_items_enum_type) 2769)
#define  NV_GSM_POLAR_PATH_DELAY_I                     ((nv_items_enum_type) 2770)
#define  NV_DCS_POLAR_PATH_DELAY_I                     ((nv_items_enum_type) 2771)
#define  NV_GSM_850_POLAR_PATH_DELAY_I                 ((nv_items_enum_type) 2772)
#define  NV_GSM_1900_POLAR_PATH_DELAY_I                ((nv_items_enum_type) 2773)
#define  NV_GSM_OPLL_BW_VAL_I                          ((nv_items_enum_type) 2774)
#define  NV_DCS_OPLL_BW_VAL_I                          ((nv_items_enum_type) 2775)
#define  NV_GSM_850_OPLL_BW_VAL_I                      ((nv_items_enum_type) 2776)
#define  NV_GSM_1900_OPLL_BW_VAL_I                     ((nv_items_enum_type) 2777)
#define  NV_GSM_BASEBAND_BW_VAL_I                      ((nv_items_enum_type) 2778)
#define  NV_DCS_BASEBAND_BW_VAL_I                      ((nv_items_enum_type) 2779)
#define  NV_GSM_850_BASEBAND_BW_VAL_I                  ((nv_items_enum_type) 2780)
#define  NV_GSM_1900_BASEBAND_BW_VAL_I                 ((nv_items_enum_type) 2781)
#define  NV_USB_CURRENT_DEVICE_I                       ((nv_items_enum_type) 2782)
#define  NV_GPS1_MIN_NUM_SVS_I                         ((nv_items_enum_type) 2783)
#define  NV_AAGPS_DEFAULT_ALLOW_RRC_I                  ((nv_items_enum_type) 2784)
#define  NV_AAGPS_DEFAULT_MTLR_GUARD_TIMER_I           ((nv_items_enum_type) 2785)
#define  NV_AAGPS_DEFAULT_SMLC_COMM_TIMEOUT_I          ((nv_items_enum_type) 2786)
#define  NV_AAGPS_DEFAULT_PRESUPL_UE_TIMER1_VALUE_I    ((nv_items_enum_type) 2787)
#define  NV_AAGPS_DEFAULT_PRESUPL_UE_TIMER2_VALUE_I    ((nv_items_enum_type) 2788)
#define  NV_AAGPS_DEFAULT_PRESUPL_UE_TIMER3_VALUE_I    ((nv_items_enum_type) 2789)
#define  NV_ACTIVE_EPZID_TYPE_I                        ((nv_items_enum_type) 2790)
#define  NV_C0_BC0_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2791)
#define  NV_C1_BC0_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2792)
#define  NV_C0_BC1_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2793)
#define  NV_C1_BC1_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2794)
#define  NV_C0_BC3_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2795)
#define  NV_C1_BC3_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2796)
#define  NV_C0_BC4_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2797)
#define  NV_C1_BC4_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2798)
#define  NV_C0_BC5_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2799)
#define  NV_C1_BC5_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2800)
#define  NV_C0_BC6_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2801)
#define  NV_C1_BC6_RX_CAL_CHAN_LRU_I                   ((nv_items_enum_type) 2802)
#define  NV_CCM_VERSION_INFO_I                         ((nv_items_enum_type) 2803)
#define  NV_TURNOFF_COUNTER_I                          ((nv_items_enum_type) 2804)
#define  NV_POWERDOWN_STATUS_I                         ((nv_items_enum_type) 2805)
#define  NV_PHONE_POWER_ON_STATUS_I                    ((nv_items_enum_type) 2806)
#define  NV_FIRST_POWER_ON_TIME_I                      ((nv_items_enum_type) 2807)
#define  NV_SW_VERSION_INFO_I                          ((nv_items_enum_type) 2808)
#define  NV_SET_DATE_FORMAT_I                          ((nv_items_enum_type) 2809)
#define  NV_SET_TIME_FORMAT_I                          ((nv_items_enum_type) 2810)
#define  NV_SET_SHOW_TIME_I                            ((nv_items_enum_type) 2811)
#define  NV_SET_AUTO_TIME_I                            ((nv_items_enum_type) 2812)
#define  NV_SET_BUDDHIST_YEAR_I                        ((nv_items_enum_type) 2813)
#define  NV_BC0_HDR_P1_RISE_FALL_OFF_I                 ((nv_items_enum_type) 2814)
#define  NV_BC1_HDR_P1_RISE_FALL_OFF_I                 ((nv_items_enum_type) 2815)
#define  NV_BC3_HDR_P1_RISE_FALL_OFF_I                 ((nv_items_enum_type) 2816)
#define  NV_BC4_HDR_P1_RISE_FALL_OFF_I                 ((nv_items_enum_type) 2817)
#define  NV_BC5_HDR_P1_RISE_FALL_OFF_I                 ((nv_items_enum_type) 2818)
#define  NV_BC6_HDR_P1_RISE_FALL_OFF_I                 ((nv_items_enum_type) 2819)
#define  NV_DS_INCOMING_DATA_RLP_TIMEOUT_I             ((nv_items_enum_type) 2820)
#define  NV_DS_DEFAULT_INACTIVITY_RESTORE_TIMEOUT_I    ((nv_items_enum_type) 2821)
#define  NV_CHG_USB_NVDISABLE_VAL_I                    ((nv_items_enum_type) 2822)
#define  NV_CONSORTIUM_CONFIG_I                        ((nv_items_enum_type) 2823)
#define  NV_DEVICE_SERIAL_NO_I                         ((nv_items_enum_type) 2824)
#define  NV_DS_MIP_RM_NAI_I                            ((nv_items_enum_type) 2825)
#define  NV_SMS_BMC_READING_PREF_I                     ((nv_items_enum_type) 2826)
#define  NV_VOC_HS_MIC_GAIN_ADJUST_I                   ((nv_items_enum_type) 2827)
#define  NV_AUTO_POWER_OFF_I                           ((nv_items_enum_type) 2828)
#define  NV_FAST_SEARCH_I                              ((nv_items_enum_type) 2829)
#define  NV_UPLOADMEDIA_ALBUM_MENU_ENABLED_I           ((nv_items_enum_type) 2830)
#define  NV_UPLOADMEDIA_ALBUM_ADDR_I                   ((nv_items_enum_type) 2831)
#define  NV_UPLOADMEDIA_POSTCARD_MENU_ENABLED_I        ((nv_items_enum_type) 2832)
#define  NV_UPLOADMEDIA_POSTCARD_SEPARATOR_I           ((nv_items_enum_type) 2833)
#define  NV_UPLOADMEDIA_POSTCARD_ADDR_I                ((nv_items_enum_type) 2834)
#define  NV_UPLOADMEDIA_POSTCARD_MAX_CHARACTERS_I      ((nv_items_enum_type) 2835)
#define  NV_UPLOADMEDIA_POSTCARD_MAX_RECIPIENTS_I      ((nv_items_enum_type) 2836)
#define  NV_UPLOADMEDIA_POSTCARD_AUTO_SAVE_I           ((nv_items_enum_type) 2837)
#define  NV_EMAIL_ACTIVE_PROFILE_I                     ((nv_items_enum_type) 2838)
#define  NV_BT_ACTIVE_I                                ((nv_items_enum_type) 2839)
#define  NV_BT_VISIBLE_I                               ((nv_items_enum_type) 2840)
#define  NV_BT_SAP_ENABLE_I                            ((nv_items_enum_type) 2841)
#define  NV_WCLOCK_AUTO_NITZ_ZONE_DST_I                ((nv_items_enum_type) 2842)
#define  NV_TIMEZONE_I                                 ((nv_items_enum_type) 2843)
#define  NV_HDRSCP_BCMCS_ENABLE_I                      ((nv_items_enum_type) 2844)
#define  NV_WCDMA_1800_VGA_GAIN_OFFSET_I               ((nv_items_enum_type) 2845)
#define  NV_WCDMA_1800_VGA_GAIN_OFFSET_VS_FREQ_I       ((nv_items_enum_type) 2846)
#define  NV_WCDMA_1800_VGA_GAIN_OFFSET_VS_TEMP_I       ((nv_items_enum_type) 2847)
#define  NV_WCDMA_1800_LNA_RANGE_RISE_2_I              ((nv_items_enum_type) 2848)
#define  NV_WCDMA_1800_LNA_RANGE_RISE_3_I              ((nv_items_enum_type) 2849)
#define  NV_WCDMA_1800_LNA_RANGE_FALL_2_I              ((nv_items_enum_type) 2850)
#define  NV_WCDMA_1800_LNA_RANGE_FALL_3_I              ((nv_items_enum_type) 2851)
#define  NV_WCDMA_1800_IM_LEVEL_2_I                    ((nv_items_enum_type) 2852)
#define  NV_WCDMA_1800_IM_LEVEL_3_I                    ((nv_items_enum_type) 2853)
#define  NV_WCDMA_1800_LNA_RANGE_OFFSET_2_I            ((nv_items_enum_type) 2854)
#define  NV_WCDMA_1800_LNA_RANGE_OFFSET_3_I            ((nv_items_enum_type) 2855)
#define  NV_WCDMA_1800_LNA_OFFSET_VS_FREQ_2_I          ((nv_items_enum_type) 2856)
#define  NV_WCDMA_1800_LNA_OFFSET_VS_FREQ_3_I          ((nv_items_enum_type) 2857)
#define  NV_WCDMA_1800_IM2_I_VALUE_I                   ((nv_items_enum_type) 2858)
#define  NV_WCDMA_1800_IM2_Q_VALUE_I                   ((nv_items_enum_type) 2859)
#define  NV_WCDMA_1800_IM2_TRANSCONDUCTOR_VALUE_I      ((nv_items_enum_type) 2860)
#define  NV_WCDMA_1800_RX_AGC_MIN_2_I                  ((nv_items_enum_type) 2861)
#define  NV_WCDMA_1800_RX_AGC_MIN_3_I                  ((nv_items_enum_type) 2862)
#define  NV_WCDMA_1800_LNA_RANGE_RISE_I                ((nv_items_enum_type) 2863)
#define  NV_WCDMA_1800_LNA_RANGE_FALL_I                ((nv_items_enum_type) 2864)
#define  NV_WCDMA_1800_IM_LEVEL_I                      ((nv_items_enum_type) 2865)
#define  NV_WCDMA_1800_NONBYPASS_TIMER_I               ((nv_items_enum_type) 2866)
#define  NV_WCDMA_1800_BYPASS_TIMER_I                  ((nv_items_enum_type) 2867)
#define  NV_WCDMA_1800_LNA_RANGE_OFFSET_I              ((nv_items_enum_type) 2868)
#define  NV_WCDMA_1800_LNA_OFFSET_VS_FREQ_I            ((nv_items_enum_type) 2869)
#define  NV_WCDMA_1800_RX_AGC_MIN_I                    ((nv_items_enum_type) 2870)
#define  NV_WCDMA_1800_RX_AGC_MAX_I                    ((nv_items_enum_type) 2871)
#define  NV_WCDMA_1800_AGC_PHASE_OFFSET_I              ((nv_items_enum_type) 2872)
#define  NV_WCDMA_1800_TX_LIN_MASTER_0_I               ((nv_items_enum_type) 2873)
#define  NV_WCDMA_1800_TX_LIN_MASTER_1_I               ((nv_items_enum_type) 2874)
#define  NV_WCDMA_1800_TX_LIN_MASTER_2_I               ((nv_items_enum_type) 2875)
#define  NV_WCDMA_1800_TX_LIN_MASTER_3_I               ((nv_items_enum_type) 2876)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_0_I             ((nv_items_enum_type) 2877)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_1_I             ((nv_items_enum_type) 2878)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_2_I             ((nv_items_enum_type) 2879)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_3_I             ((nv_items_enum_type) 2880)
#define  NV_WCDMA_1800_TX_LIN_VS_TEMP_0_I              ((nv_items_enum_type) 2881)
#define  NV_WCDMA_1800_TX_LIN_VS_TEMP_1_I              ((nv_items_enum_type) 2882)
#define  NV_WCDMA_1800_TX_LIN_VS_TEMP_2_I              ((nv_items_enum_type) 2883)
#define  NV_WCDMA_1800_TX_LIN_VS_TEMP_3_I              ((nv_items_enum_type) 2884)
#define  NV_WCDMA_1800_TX_SLP_VS_TEMP_0_I              ((nv_items_enum_type) 2885)
#define  NV_WCDMA_1800_TX_SLP_VS_TEMP_1_I              ((nv_items_enum_type) 2886)
#define  NV_WCDMA_1800_TX_SLP_VS_TEMP_2_I              ((nv_items_enum_type) 2887)
#define  NV_WCDMA_1800_TX_SLP_VS_TEMP_3_I              ((nv_items_enum_type) 2888)
#define  NV_WCDMA_1800_R1_RISE_I                       ((nv_items_enum_type) 2889)
#define  NV_WCDMA_1800_R1_FALL_I                       ((nv_items_enum_type) 2890)
#define  NV_WCDMA_1800_TX_LIM_VS_TEMP_I                ((nv_items_enum_type) 2891)
#define  NV_WCDMA_1800_TX_LIM_VS_FREQ_I                ((nv_items_enum_type) 2892)
#define  NV_WCDMA_1800_ADJ_FACTOR_I                    ((nv_items_enum_type) 2893)
#define  NV_WCDMA_1800_EXP_HDET_VS_AGC_I               ((nv_items_enum_type) 2894)
#define  NV_WCDMA_1800_HDET_OFF_I                      ((nv_items_enum_type) 2895)
#define  NV_WCDMA_1800_HDET_SPN_I                      ((nv_items_enum_type) 2896)
#define  NV_WCDMA_1800_MAX_TX_POWER_I                  ((nv_items_enum_type) 2897)
#define  NV_WCDMA_1800_OUT_OF_SERVICE_THRESH_I         ((nv_items_enum_type) 2898)
#define  NV_WCDMA_1800_ENC_BTF_I                       ((nv_items_enum_type) 2899)
#define  NV_WCDMA_1800_RX_DELAY_I                      ((nv_items_enum_type) 2900)
#define  NV_WCDMA_1800_AGC_PA_ON_RISE_DELAY_I          ((nv_items_enum_type) 2901)
#define  NV_WCDMA_1800_AGC_PA_ON_FALL_DELAY_I          ((nv_items_enum_type) 2902)
#define  NV_WCDMA_1800_AGC_TX_ON_RISE_DELAY_I          ((nv_items_enum_type) 2903)
#define  NV_WCDMA_1800_AGC_TX_ON_FALL_DELAY_I          ((nv_items_enum_type) 2904)
#define  NV_WCDMA_1800_AGC_UPDATE_TX_AGC_TIME_I        ((nv_items_enum_type) 2905)
#define  NV_WCDMA_1800_PA_GAIN_UP_TIME_I               ((nv_items_enum_type) 2906)
#define  NV_WCDMA_1800_PA_GAIN_DOWN_TIME_I             ((nv_items_enum_type) 2907)
#define  NV_WCDMA_1800_TX_ROT_ANGLE_PA_STATE_00_I      ((nv_items_enum_type) 2908)
#define  NV_WCDMA_1800_TX_ROT_ANGLE_PA_STATE_01_I      ((nv_items_enum_type) 2909)
#define  NV_WCDMA_1800_TX_ROT_ANGLE_PA_STATE_10_I      ((nv_items_enum_type) 2910)
#define  NV_WCDMA_1800_TX_ROT_ANGLE_PA_STATE_11_I      ((nv_items_enum_type) 2911)
#define  NV_RFR_VCO_COARSE_TUNING_1800_I               ((nv_items_enum_type) 2912)
#define  NV_WCDMA_1800_PA_COMPENSATE_UP_I              ((nv_items_enum_type) 2913)
#define  NV_WCDMA_1800_PA_COMPENSATE_DOWN_I            ((nv_items_enum_type) 2914)
#define  NV_WCDMA_1800_PRACH_R1_RISE_OFFSET_I          ((nv_items_enum_type) 2915)
#define  NV_WCDMA_1800_PRACH_R1_FALL_OFFSET_I          ((nv_items_enum_type) 2916)
#define  NV_WCDMA_1800_TX_CAL_CHAN_I                   ((nv_items_enum_type) 2917)
#define  NV_WCDMA_1800_RX_CAL_CHAN_I                   ((nv_items_enum_type) 2918)
#define  NV_WCDMA_1800_R2_RISE_I                       ((nv_items_enum_type) 2919)
#define  NV_WCDMA_1800_R2_FALL_I                       ((nv_items_enum_type) 2920)
#define  NV_WCDMA_1800_R3_RISE_I                       ((nv_items_enum_type) 2921)
#define  NV_WCDMA_1800_R3_FALL_I                       ((nv_items_enum_type) 2922)
#define  NV_WCDMA_1800_PA_COMPENSATE_UP_R2_I           ((nv_items_enum_type) 2923)
#define  NV_WCDMA_1800_PA_COMPENSATE_DOWN_R2_I         ((nv_items_enum_type) 2924)
#define  NV_WCDMA_1800_PA_COMPENSATE_UP_R3_I           ((nv_items_enum_type) 2925)
#define  NV_WCDMA_1800_PA_COMPENSATE_DOWN_R3_I         ((nv_items_enum_type) 2926)
#define  NV_WCDMA_1800_PRACH_R2_RISE_OFFSET_I          ((nv_items_enum_type) 2927)
#define  NV_WCDMA_1800_PRACH_R2_FALL_OFFSET_I          ((nv_items_enum_type) 2928)
#define  NV_WCDMA_1800_PRACH_R3_RISE_OFFSET_I          ((nv_items_enum_type) 2929)
#define  NV_WCDMA_1800_PRACH_R3_FALL_OFFSET_I          ((nv_items_enum_type) 2930)
#define  NV_WCDMA_1800_PA_RANGE_MAP_I                  ((nv_items_enum_type) 2931)
#define  NV_WCDMA_1800_PA_RANGE_FOR_DVS_I              ((nv_items_enum_type) 2932)
#define  NV_WCDMA_1800_PA_COMPENSATE_UP_WITH_DVS_I     ((nv_items_enum_type) 2933)
#define  NV_WCDMA_1800_PA_COMPENSATE_DN_WITH_DVS_I     ((nv_items_enum_type) 2934)
#define  NV_WCDMA_1800_MAX_PWR_BACKOFF_VOLTAGES_I      ((nv_items_enum_type) 2935)
#define  NV_WCDMA_1800_MAX_PWR_BACKOFF_VOLT1_I         ((nv_items_enum_type) 2936)
#define  NV_WCDMA_1800_MAX_PWR_BACKOFF_VOLT2_I         ((nv_items_enum_type) 2937)
#define  NV_WCDMA_1800_MAX_PWR_BACKOFF_VOLT3_I         ((nv_items_enum_type) 2938)
#define  NV_WCDMA_1800_HS_R1_RISE_I                    ((nv_items_enum_type) 2939)
#define  NV_WCDMA_1800_HS_R1_FALL_I                    ((nv_items_enum_type) 2940)
#define  NV_WCDMA_1800_HS_R2_RISE_I                    ((nv_items_enum_type) 2941)
#define  NV_WCDMA_1800_HS_R2_FALL_I                    ((nv_items_enum_type) 2942)
#define  NV_WCDMA_1800_HS_R3_RISE_I                    ((nv_items_enum_type) 2943)
#define  NV_WCDMA_1800_HS_R3_FALL_I                    ((nv_items_enum_type) 2944)
#define  NV_WCDMA_1800_DCH_AGC_UPDATE_TX_AGC_TIME_I    ((nv_items_enum_type) 2945)
#define  NV_WCDMA_1800_AGC_TX_ADJ_PDM_DELAY_I          ((nv_items_enum_type) 2946)
#define  NV_WCDMA_1900_DCH_AGC_UPDATE_TX_AGC_TIME_I    ((nv_items_enum_type) 2947)
#define  NV_WCDMA_1900_AGC_TX_ADJ_PDM_DELAY_I          ((nv_items_enum_type) 2948)
#define  NV_WCDMA_800_DCH_AGC_UPDATE_TX_AGC_TIME_I     ((nv_items_enum_type) 2949)
#define  NV_WCDMA_800_AGC_TX_ADJ_PDM_DELAY_I           ((nv_items_enum_type) 2950)
#define  NV_WCDMA_DCH_AGC_UPDATE_TX_AGC_TIME_I         ((nv_items_enum_type) 2951)
#define  NV_WCDMA_AGC_TX_ADJ_PDM_DELAY_I               ((nv_items_enum_type) 2952)
#define  NV_DS_SIP_RM_NAI_I                            ((nv_items_enum_type) 2953)
#define  NV_BAND_PREF_32_63_I                          ((nv_items_enum_type) 2954)
#define  NV_MMS_MAX_MSG_SIZE1_I                        ((nv_items_enum_type) 2955)
#define  NV_MMS_MAX_MSG_SIZE2_I                        ((nv_items_enum_type) 2956)
#define  NV_MMS_MAX_MSG_SIZE3_I                        ((nv_items_enum_type) 2957)
#define  NV_MMS_MAX_SIZE_USER_SELECTABLE_I             ((nv_items_enum_type) 2958)
#define  NV_MMS_ACTIVE_MAX_MSG_SIZE_I                  ((nv_items_enum_type) 2959)
#define  NV_MMS_ACTIVE_PROFILE_I                       ((nv_items_enum_type) 2960)
#define  NV_MMS_HIDE_NUMBER_I                          ((nv_items_enum_type) 2961)
#define  NV_MMS_REQ_DELIVERY_RPT_I                     ((nv_items_enum_type) 2962)
#define  NV_MMS_REQ_READ_RPT_I                         ((nv_items_enum_type) 2963)
#define  NV_MMS_PRIORITY_I                             ((nv_items_enum_type) 2964)
#define  NV_MMS_VALIDITY_PERIOD_I                      ((nv_items_enum_type) 2965)
#define  NV_MMS_SLIDE_DURATION_I                       ((nv_items_enum_type) 2966)
#define  NV_MMS_RETRIEVAL_HOME_I                       ((nv_items_enum_type) 2967)
#define  NV_MMS_RETRIEVAL_ROAM_I                       ((nv_items_enum_type) 2968)
#define  NV_MMS_DELIVERY_TIME_I                        ((nv_items_enum_type) 2969)
#define  NV_MMS_ALLOW_ANON_MSG_I                       ((nv_items_enum_type) 2970)
#define  NV_MMS_CREATION_MODE_I                        ((nv_items_enum_type) 2971)
#define  NV_MMS_AUTOSIG_I                              ((nv_items_enum_type) 2972)
#define  NV_MMS_AUTO_SAVE_I                            ((nv_items_enum_type) 2973)
#define  NV_MMS_ALLOW_READ_RPT_I                       ((nv_items_enum_type) 2974)
#define  NV_MMS_ALLOW_DELIVERY_RPT_I                   ((nv_items_enum_type) 2975)
#define  NV_MMS_MAX_RECIPIENTS_I                       ((nv_items_enum_type) 2976)
#define  NV_MMS_MAX_STORED_MMS_I                       ((nv_items_enum_type) 2977)
#define  NV_MMS_SIGNATURE_ACTIVE_TEMPLATE_I            ((nv_items_enum_type) 2978)
#define  NV_BT_FILELOCATION_ONDEVICE_I                 ((nv_items_enum_type) 2979)
#define  NV_WCDMA_UTRAN_TX_LIM_VS_TEMP_OFFSET_I        ((nv_items_enum_type) 2980)
#define  NV_WCDMA_1800_UTRAN_TX_LIM_VS_TEMP_OFFSET_I   ((nv_items_enum_type) 2981)
#define  NV_WCDMA_800_UTRAN_TX_LIM_VS_TEMP_OFFSET_I    ((nv_items_enum_type) 2982)
#define  NV_WCDMA_1900_UTRAN_TX_LIM_VS_TEMP_OFFSET_I   ((nv_items_enum_type) 2983)
#define  NV_SENDVIA_CFG_I                              ((nv_items_enum_type) 2984)
#define  NV_PU_PROMPT_ENABLED_I                        ((nv_items_enum_type) 2985)
#define  NV_USER_GREETING_I                            ((nv_items_enum_type) 2986)
#define  NV_SCREENSAVER_STYLE_I                        ((nv_items_enum_type) 2987)
#define  NV_SCREENSAVER_TIMEOUT_I                      ((nv_items_enum_type) 2988)
#define  NV_MESSAGING_FONT_I                           ((nv_items_enum_type) 2989)
#define  NV_SYNCML_DM_ACTIVEPROFILE_I                  ((nv_items_enum_type) 2990)
#define  NV_SYNCML_DS_ACTIVEPROFILE_I                  ((nv_items_enum_type) 2991)
#define  NV_SYNCML_SYNCDIRECTION_I                     ((nv_items_enum_type) 2992)
#define  NV_SYNCML_DATATOSYNC_I                        ((nv_items_enum_type) 2993)
#define  NV_SYNCML_APPSTOSYNC_I                        ((nv_items_enum_type) 2994)
#define  NV_MS_SMS_ACTIVE_PROFILE_I                    ((nv_items_enum_type) 2995)
#define  NV_MS_SMS_TEXT_SIZE_I                         ((nv_items_enum_type) 2996)
#define  NV_MS_SMS_AUTOHEADER_I                        ((nv_items_enum_type) 2997)
#define  NV_MS_SMS_AUTOSIGNATURE_I                     ((nv_items_enum_type) 2998)
#define  NV_MS_SMS_HEADER_ACTIVE_TEMPLATE_I            ((nv_items_enum_type) 2999)
#define  NV_MS_SMS_SIGNATURE_ACTIVE_TEMPLATE_I         ((nv_items_enum_type) 3000)
#define  NV_MS_SMS_AUTOSAVE_I                          ((nv_items_enum_type) 3001)
#define  NV_MS_SMS_AUTODELETE_I                        ((nv_items_enum_type) 3002)
#define  NV_MS_SMS_ALLOW_EMOTICONS_I                   ((nv_items_enum_type) 3003)
#define  NV_MS_SMS_MAX_SEGMENTS_I                      ((nv_items_enum_type) 3004)
#define  NV_MS_SMS_MAX_RECIPIENTS_I                    ((nv_items_enum_type) 3005)
#define  NV_MS_SMS_MAX_NUMBER_OF_SMS_I                 ((nv_items_enum_type) 3006)
#define  NV_MS_SMS_MAX_TEMPLATES_I                     ((nv_items_enum_type) 3007)
#define  NV_MS_SMS_OPCO_TYPES_SUPPORTED_I              ((nv_items_enum_type) 3008)
#define  NV_MS_SMS_SMSC_ADDRESS1_I                     ((nv_items_enum_type) 3009)
#define  NV_MS_SMS_SMSC_ADDRESS2_I                     ((nv_items_enum_type) 3010)
#define  NV_MS_SMS_SMSC_ADDRESS3_I                     ((nv_items_enum_type) 3011)
#define  NV_MS_SMS_SMSC_ADDRESS4_I                     ((nv_items_enum_type) 3012)
#define  NV_MS_SMS_SMSC_ADDRESS5_I                     ((nv_items_enum_type) 3013)
#define  NV_WCDMA_MAX_TX_POWER_DCH_PC4_I               ((nv_items_enum_type) 3014)
#define  NV_POC_SHOW_PT_MENU_I                         ((nv_items_enum_type) 3015)
#define  NV_POC_SERVER_IP1_I                           ((nv_items_enum_type) 3016)
#define  NV_POC_SERVER_IP2_I                           ((nv_items_enum_type) 3017)
#define  NV_POC_SERVER_PORT_I                          ((nv_items_enum_type) 3018)
#define  NV_POC_NAI_I                                  ((nv_items_enum_type) 3019)
#define  NV_POC_BILLING_SERVICE_I                      ((nv_items_enum_type) 3020)
#define  NV_POC_GLM_PASSWORD_I                         ((nv_items_enum_type) 3021)
#define  NV_POC_RTP_PORT_I                             ((nv_items_enum_type) 3022)
#define  NV_POC_SIP_PORT_I                             ((nv_items_enum_type) 3023)
#define  NV_POC_IS_SIG_COMP_I                          ((nv_items_enum_type) 3024)
#define  NV_POC_MAX_AUTH_RETRIES_I                     ((nv_items_enum_type) 3025)
#define  NV_POC_CONNECTION_PROFILE_I                   ((nv_items_enum_type) 3026)
#define  NV_RF_ANTSEL_UMTS_1800_I                      ((nv_items_enum_type) 3027)
#define  NV_IM_SHOW_MENU_I                             ((nv_items_enum_type) 3028)
#define  NV_IM_CONNECTION_PROFILE_I                    ((nv_items_enum_type) 3029)
#define  NV_IM_PRIMARY_IP_ADDR_I                       ((nv_items_enum_type) 3030)
#define  NV_IM_PRIMARY_PORT_I                          ((nv_items_enum_type) 3031)
#define  NV_IM_ENCODING_METHOD_I                       ((nv_items_enum_type) 3032)
#define  NV_IM_SERVER_NAME_I                           ((nv_items_enum_type) 3033)
#define  NV_IM_WV_VERSION_I                            ((nv_items_enum_type) 3034)
#define  NV_BC0_PA_DVS_VOLTAGE_I                       ((nv_items_enum_type) 3035)
#define  NV_BC1_PA_DVS_VOLTAGE_I                       ((nv_items_enum_type) 3036)
#define  NV_BC3_PA_DVS_VOLTAGE_I                       ((nv_items_enum_type) 3037)
#define  NV_BC4_PA_DVS_VOLTAGE_I                       ((nv_items_enum_type) 3038)
#define  NV_BC5_PA_DVS_VOLTAGE_I                       ((nv_items_enum_type) 3039)
#define  NV_BC6_PA_DVS_VOLTAGE_I                       ((nv_items_enum_type) 3040)
#define  NV_EXT_OP_LIST_ENTRY_VALID_I                  ((nv_items_enum_type) 3041)
#define  NV_EXT_OP_LIST_ENTRY_NAME_I                   ((nv_items_enum_type) 3042)
#define  NV_EXT_OP_LIST_ENTRY_PLMN_I                   ((nv_items_enum_type) 3043)
#define  NV_BM_BAT_STATS_I                             ((nv_items_enum_type) 3044)
#define  NV_DISPLAY_LANGUAGE_OPTIONS_I                 ((nv_items_enum_type) 3045)
#define  NV_DISPLAY_LANGUAGE_I                         ((nv_items_enum_type) 3046)
#define  NV_INPUT_LANGUAGE_MODE_I                      ((nv_items_enum_type) 3047)
#define  NV_INPUT_LANGUAGE_OPTIONS_I                   ((nv_items_enum_type) 3048)
#define  NV_INPUT_LANGUAGE_I                           ((nv_items_enum_type) 3049)
#define  NV_SYS_CONVERT_SCRIPT_VER_I                   ((nv_items_enum_type) 3050)
#define  NV_SYS_PROD_SPEC_CONVERT_SCRIPT_VER_I         ((nv_items_enum_type) 3051)
#define  NV_SYS_MANUAL_CONVERT_SCRIPT_VER_I            ((nv_items_enum_type) 3052)
#define  NV_IRDA_ACTIVE_I                              ((nv_items_enum_type) 3053)
#define  NV_IRDA_FILE_LOCATION_I                       ((nv_items_enum_type) 3054)
#define  NV_GSM_RAMP_UP_STEPS_I                        ((nv_items_enum_type) 3055)
#define  NV_GSM_RAMP_UP_RAISE_COSINE_POWER_I           ((nv_items_enum_type) 3056)
#define  NV_GSM_RAMP_DOWN_STEPS_I                      ((nv_items_enum_type) 3057)
#define  NV_GSM_RAMP_DOWN_RAISE_COSINE_POWER_I         ((nv_items_enum_type) 3058)
#define  NV_GSM_POWER_LEVELS_I                         ((nv_items_enum_type) 3059)
#define  NV_DCS_POWER_LEVELS_I                         ((nv_items_enum_type) 3060)
#define  NV_GSM_850_POWER_LEVELS_I                     ((nv_items_enum_type) 3061)
#define  NV_GSM_1900_POWER_LEVELS_I                    ((nv_items_enum_type) 3062)
#define  NV_GSM_PA_EN_START_I                          ((nv_items_enum_type) 3063)
#define  NV_GSM_ANT_TIMING_REL_TO_PA_EN_START_I        ((nv_items_enum_type) 3064)
#define  NV_DCS_PA_EN_START_I                          ((nv_items_enum_type) 3065)
#define  NV_DCS_ANT_TIMING_REL_TO_PA_EN_START_I        ((nv_items_enum_type) 3066)
#define  NV_GSM_850_PA_EN_START_I                      ((nv_items_enum_type) 3067)
#define  NV_GSM_1900_PA_EN_START_I                     ((nv_items_enum_type) 3068)
#define  NV_GSM_1900_ANT_TIMING_REL_TO_PA_EN_START_I   ((nv_items_enum_type) 3069)
#define  NV_GSM_PA_EN_STOP_I                           ((nv_items_enum_type) 3070)
#define  NV_GSM_ANT_TIMING_REL_TO_PA_EN_STOP_I         ((nv_items_enum_type) 3071)
#define  NV_DCS_PA_EN_STOP_I                           ((nv_items_enum_type) 3072)
#define  NV_DCS_ANT_TIMING_REL_TO_PA_EN_STOP_I         ((nv_items_enum_type) 3073)
#define  NV_GSM_850_PA_EN_STOP_I                       ((nv_items_enum_type) 3074)
#define  NV_GSM_850_ANT_TIMING_REL_TO_PA_EN_STOP_I     ((nv_items_enum_type) 3075)
#define  NV_GSM_1900_PA_EN_STOP_I                      ((nv_items_enum_type) 3076)
#define  NV_GSM_1900_ANT_TIMING_REL_TO_PA_EN_STOP_I    ((nv_items_enum_type) 3077)
#define  NV_GSM_AMAM_MASTER_TBL_SEG1_F3_I              ((nv_items_enum_type) 3078)
#define  NV_GSM_AMAM_MASTER_TBL_SEG2_F3_I              ((nv_items_enum_type) 3079)
#define  NV_GSM_AMAM_MASTER_TBL_SEG3_F3_I              ((nv_items_enum_type) 3080)
#define  NV_GSM_AMAM_MASTER_TBL_SEG4_F3_I              ((nv_items_enum_type) 3081)
#define  NV_GSM_AMAM_MASTER_TBL_SEG5_F3_I              ((nv_items_enum_type) 3082)
#define  NV_GSM_AMAM_MASTER_TBL_SEG6_F3_I              ((nv_items_enum_type) 3083)
#define  NV_GSM_AMAM_MASTER_TBL_SEG7_F3_I              ((nv_items_enum_type) 3084)
#define  NV_GSM_AMAM_MASTER_TBL_SEG8_F3_I              ((nv_items_enum_type) 3085)
#define  NV_DCS_AMAM_MASTER_TBL_SEG1_F3_I              ((nv_items_enum_type) 3086)
#define  NV_DCS_AMAM_MASTER_TBL_SEG2_F3_I              ((nv_items_enum_type) 3087)
#define  NV_DCS_AMAM_MASTER_TBL_SEG3_F3_I              ((nv_items_enum_type) 3088)
#define  NV_DCS_AMAM_MASTER_TBL_SEG4_F3_I              ((nv_items_enum_type) 3089)
#define  NV_DCS_AMAM_MASTER_TBL_SEG5_F3_I              ((nv_items_enum_type) 3090)
#define  NV_DCS_AMAM_MASTER_TBL_SEG6_F3_I              ((nv_items_enum_type) 3091)
#define  NV_DCS_AMAM_MASTER_TBL_SEG7_F3_I              ((nv_items_enum_type) 3092)
#define  NV_DCS_AMAM_MASTER_TBL_SEG8_F3_I              ((nv_items_enum_type) 3093)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG1_F3_I          ((nv_items_enum_type) 3094)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG2_F3_I          ((nv_items_enum_type) 3095)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG3_F3_I          ((nv_items_enum_type) 3096)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG4_F3_I          ((nv_items_enum_type) 3097)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG5_F3_I          ((nv_items_enum_type) 3098)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG6_F3_I          ((nv_items_enum_type) 3099)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG7_F3_I          ((nv_items_enum_type) 3100)
#define  NV_GSM_850_AMAM_MASTER_TBL_SEG8_F3_I          ((nv_items_enum_type) 3101)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG1_F3_I         ((nv_items_enum_type) 3102)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG2_F3_I         ((nv_items_enum_type) 3103)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG3_F3_I         ((nv_items_enum_type) 3104)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG4_F3_I         ((nv_items_enum_type) 3105)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG5_F3_I         ((nv_items_enum_type) 3106)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG6_F3_I         ((nv_items_enum_type) 3107)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG7_F3_I         ((nv_items_enum_type) 3108)
#define  NV_GSM_1900_AMAM_MASTER_TBL_SEG8_F3_I         ((nv_items_enum_type) 3109)
#define  NV_GSM_AMPM_MASTER_TBL_SEG1_F3_I              ((nv_items_enum_type) 3110)
#define  NV_GSM_AMPM_MASTER_TBL_SEG2_F3_I              ((nv_items_enum_type) 3111)
#define  NV_GSM_AMPM_MASTER_TBL_SEG3_F3_I              ((nv_items_enum_type) 3112)
#define  NV_GSM_AMPM_MASTER_TBL_SEG4_F3_I              ((nv_items_enum_type) 3113)
#define  NV_GSM_AMPM_MASTER_TBL_SEG5_F3_I              ((nv_items_enum_type) 3114)
#define  NV_GSM_AMPM_MASTER_TBL_SEG6_F3_I              ((nv_items_enum_type) 3115)
#define  NV_GSM_AMPM_MASTER_TBL_SEG7_F3_I              ((nv_items_enum_type) 3116)
#define  NV_GSM_AMPM_MASTER_TBL_SEG8_F3_I              ((nv_items_enum_type) 3117)
#define  NV_DCS_AMPM_MASTER_TBL_SEG1_F3_I              ((nv_items_enum_type) 3118)
#define  NV_DCS_AMPM_MASTER_TBL_SEG2_F3_I              ((nv_items_enum_type) 3119)
#define  NV_DCS_AMPM_MASTER_TBL_SEG3_F3_I              ((nv_items_enum_type) 3120)
#define  NV_DCS_AMPM_MASTER_TBL_SEG4_F3_I              ((nv_items_enum_type) 3121)
#define  NV_DCS_AMPM_MASTER_TBL_SEG5_F3_I              ((nv_items_enum_type) 3122)
#define  NV_DCS_AMPM_MASTER_TBL_SEG6_F3_I              ((nv_items_enum_type) 3123)
#define  NV_DCS_AMPM_MASTER_TBL_SEG7_F3_I              ((nv_items_enum_type) 3124)
#define  NV_DCS_AMPM_MASTER_TBL_SEG8_F3_I              ((nv_items_enum_type) 3125)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG1_F3_I          ((nv_items_enum_type) 3126)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG2_F3_I          ((nv_items_enum_type) 3127)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG3_F3_I          ((nv_items_enum_type) 3128)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG4_F3_I          ((nv_items_enum_type) 3129)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG5_F3_I          ((nv_items_enum_type) 3130)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG6_F3_I          ((nv_items_enum_type) 3131)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG7_F3_I          ((nv_items_enum_type) 3132)
#define  NV_GSM_850_AMPM_MASTER_TBL_SEG8_F3_I          ((nv_items_enum_type) 3133)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG1_F3_I         ((nv_items_enum_type) 3134)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG2_F3_I         ((nv_items_enum_type) 3135)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG3_F3_I         ((nv_items_enum_type) 3136)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG4_F3_I         ((nv_items_enum_type) 3137)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG5_F3_I         ((nv_items_enum_type) 3138)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG6_F3_I         ((nv_items_enum_type) 3139)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG7_F3_I         ((nv_items_enum_type) 3140)
#define  NV_GSM_1900_AMPM_MASTER_TBL_SEG8_F3_I         ((nv_items_enum_type) 3141)
#define  NV_GSM_AMAM_ARFCN_F3_I                        ((nv_items_enum_type) 3142)
#define  NV_DCS_AMAM_ARFCN_F3_I                        ((nv_items_enum_type) 3143)
#define  NV_GSM_850_AMAM_ARFCN_F3_I                    ((nv_items_enum_type) 3144)
#define  NV_GSM_1900_AMAM_ARFCN_F3_I                   ((nv_items_enum_type) 3145)
#define  NV_GSM_AUTOCAL_PWR_DAC_F3_I                   ((nv_items_enum_type) 3146)
#define  NV_DCS_AUTOCAL_PWR_DAC_F3_I                   ((nv_items_enum_type) 3147)
#define  NV_GSM_850_AUTOCAL_PWR_DAC_F3_I               ((nv_items_enum_type) 3148)
#define  NV_GSM_1900_AUTOCAL_PWR_DAC_F3_I              ((nv_items_enum_type) 3149)
#define  NV_GSM_850_ANT_TIMING_REL_TO_PA_EN_START_I    ((nv_items_enum_type) 3150)
#define  NV_GSM_RTR6250_RSB_I                          ((nv_items_enum_type) 3151)
#define  NV_DCS_RTR6250_RSB_I                          ((nv_items_enum_type) 3152)
#define  NV_GSM_850_RTR6250_RSB_I                      ((nv_items_enum_type) 3153)
#define  NV_GSM_1900_RTR6250_RSB_I                     ((nv_items_enum_type) 3154)
#define  NV_DISPLAY_LANGUAGE_AUTO_I                    ((nv_items_enum_type) 3155)
#define  NV_INPUT_LANGUAGE_AUTO_I                      ((nv_items_enum_type) 3156)
#define  NV_BROWSER_DISPLAY_SPLASH_I                   ((nv_items_enum_type) 3157)
#define  NV_BROWSER_HTTP_REFERER_I                     ((nv_items_enum_type) 3158)
#define  NV_BROWSER_ACTIVE_PROFILE_I                   ((nv_items_enum_type) 3159)
#define  NV_BROWSER_DISABLE_IMAGE_I                    ((nv_items_enum_type) 3160)
#define  NV_BROWSER_DISABLE_SOUND_I                    ((nv_items_enum_type) 3161)
#define  NV_BROWSER_DISABLE_OBJECT_I                   ((nv_items_enum_type) 3162)
#define  NV_BROWSER_MAILTO_PHONENUM_I                  ((nv_items_enum_type) 3163)
#define  NV_BROWSER_MAILTO_EMAIL_I                     ((nv_items_enum_type) 3164)
#define  NV_BROWSER_COOKIE_ENABLE_I                    ((nv_items_enum_type) 3165)
#define  NV_BROWSER_SECURE_PROMPT_I                    ((nv_items_enum_type) 3166)
#define  NV_BROWSER_IDCACHE_I                          ((nv_items_enum_type) 3167)
#define  NV_BROWSER_TITLE_REGION_I                     ((nv_items_enum_type) 3168)
#define  NV_BROWSER_SHOWSESSIONINFO_I                  ((nv_items_enum_type) 3169)
#define  NV_CURRENTLY_ACTIVE_PROFILE_I                 ((nv_items_enum_type) 3170)
#define  NV_ALLOW_MP3_RINGERS_I                        ((nv_items_enum_type) 3171)
#define  NV_ALLOW_AACPLUS_RINGERS_I                    ((nv_items_enum_type) 3172)
#define  NV_ALLOW_NON_DRM_RINGERS_I                    ((nv_items_enum_type) 3173)
#define  NV_CBS_ENABLED_I                              ((nv_items_enum_type) 3174)
#define  NV_CBS_MAX_TOPIC_INDEX_I                      ((nv_items_enum_type) 3175)
#define  NV_CBS_MIN_TOPIC_INDEX_I                      ((nv_items_enum_type) 3176)
#define  NV_CBS_ALLOW_RECEIVE_I                        ((nv_items_enum_type) 3177)
#define  NV_CBS_DISPLAY_CELL_INFO_I                    ((nv_items_enum_type) 3178)
#define  NV_CBS_NUM_SELECTED_TOPICS_I                  ((nv_items_enum_type) 3179)
#define  NV_IRDA_DEVICE_NAME_I                         ((nv_items_enum_type) 3180)
#define  NV_IRDA_PNP_DEVICE_ID_I                       ((nv_items_enum_type) 3181)
#define  NV_IRDA_PNP_MANUFACTURER_I                    ((nv_items_enum_type) 3182)
#define  NV_IRDA_PNP_NAME_I                            ((nv_items_enum_type) 3183)
#define  NV_IRDA_PNP_DEVICE_CATEGORY_I                 ((nv_items_enum_type) 3184)
#define  NV_IRDA_PNP_COMPATIBILITY_COUNT_I             ((nv_items_enum_type) 3185)
#define  NV_IRDA_PNP_STATUS_I                          ((nv_items_enum_type) 3186)
#define  NV_IRDA_PNP_VERSION_I                         ((nv_items_enum_type) 3187)
#define  NV_DISPLAY_LANGUAGE_GROUP_NUM_I               ((nv_items_enum_type) 3188)
#define  NV_POC_AUTO_ANSWER_I                          ((nv_items_enum_type) 3189)
#define  NV_POC_INCOMING_CALL_TIMEOUT_I                ((nv_items_enum_type) 3190)
#define  NV_POC_AUTO_LOGIN_I                           ((nv_items_enum_type) 3191)
#define  NV_POC_WILDCARDS_I                            ((nv_items_enum_type) 3192)
#define  NV_POC_HISTORY_LENGTH_I                       ((nv_items_enum_type) 3193)
#define  NV_POC_SECONDARY_PDP_CONTEXT_I                ((nv_items_enum_type) 3194)
#define  NV_POC_EARLY_SESSION_I                        ((nv_items_enum_type) 3195)
#define  NV_POC_QOS_MODE_I                             ((nv_items_enum_type) 3196)
#define  NV_POC_MAX_CONCURRENT_USER_LIMIT1_I           ((nv_items_enum_type) 3197)
#define  NV_POC_MAX_CONCURRENT_USER_LIMIT2_I           ((nv_items_enum_type) 3198)
#define  NV_POC_MAX_CONCURRENT_USER_LIMIT3_I           ((nv_items_enum_type) 3199)
#define  NV_POC_BUFFERED_PACKETS_I                     ((nv_items_enum_type) 3200)
#define  NV_POC_SPEAKER_PHONE_I                        ((nv_items_enum_type) 3201)
#define  NV_IM_NOTIFICATION_I                          ((nv_items_enum_type) 3202)
#define  NV_IM_AUTO_LOGIN_I                            ((nv_items_enum_type) 3203)
#define  NV_IM_SUPPORTED_BEARERS_I                     ((nv_items_enum_type) 3204)
#define  NV_IM_SUPPORTED_CIR_METHODS_I                 ((nv_items_enum_type) 3205)
#define  NV_IM_MAX_SEARCH_RESULTS_I                    ((nv_items_enum_type) 3206)
#define  NV_IM_SHORT_LOGIN_SEQUENCE_I                  ((nv_items_enum_type) 3207)
#define  NV_IM_NO_CONTACTS_EXIST_I                     ((nv_items_enum_type) 3208)
#define  NV_IM_SEND_FILE_DISABLED_I                    ((nv_items_enum_type) 3209)
#define  NV_IM_VERSION_DISCOVERY_I                     ((nv_items_enum_type) 3210)
#define  NV_IM_LOGIN_TYPE_I                            ((nv_items_enum_type) 3211)
#define  NV_IM_INITIAL_DELIVERY_METHOD_I               ((nv_items_enum_type) 3212)
#define  NV_IM_ANY_CONTENT_I                           ((nv_items_enum_type) 3213)
#define  NV_IM_ACCEPTED_CHAR_SETS_I                    ((nv_items_enum_type) 3214)
#define  NV_IM_ACCEPTED_CONTENT_TYPES_I                ((nv_items_enum_type) 3215)
#define  NV_IM_ACCEPTED_TRANSFER_ENCODINGS_I           ((nv_items_enum_type) 3216)
#define  NV_IM_ACCEPTED_CONTENT_LENGTH_I               ((nv_items_enum_type) 3217)
#define  NV_IM_PARSER_SIZE_I                           ((nv_items_enum_type) 3218)
#define  NV_IM_MAX_SAVED_CONVERSATIONS_I               ((nv_items_enum_type) 3219)
#define  NV_IM_MAX_CONCURRENT_CONVERSATIONS_I          ((nv_items_enum_type) 3220)
#define  NV_IM_SUPPORTED_BEARER_COUNT_I                ((nv_items_enum_type) 3221)
#define  NV_IM_SERVER_PORT_I                           ((nv_items_enum_type) 3222)
#define  NV_IM_HIDE_SERVER_I                           ((nv_items_enum_type) 3223)
#define  NV_IM_ALLOW_CHANGE_SERVER_I                   ((nv_items_enum_type) 3224)
#define  NV_IM_INTERNET_PROFILE_I                      ((nv_items_enum_type) 3225)
#define  NV_IM_KNOCK_SERVICE_TIMEOUT_I                 ((nv_items_enum_type) 3226)
#define  NV_IM_PASSWORD_I                              ((nv_items_enum_type) 3227)
#define  NV_IM_CIR_PORT_I                              ((nv_items_enum_type) 3228)
#define  NV_IM_SCHEMA_COUNT_I                          ((nv_items_enum_type) 3229)
#define  NV_IM_CIR_METHODS_COUNT_I                     ((nv_items_enum_type) 3230)
#define  NV_IM_MULTIPLE_TRANSACTIONS_I                 ((nv_items_enum_type) 3231)
#define  NV_IM_SMSC_ADDRESS_I                          ((nv_items_enum_type) 3232)
#define  NV_IM_OPTIONAL_HEADER_I                       ((nv_items_enum_type) 3233)
#define  NV_IM_DIGEST_SCHEMAS_I                        ((nv_items_enum_type) 3234)
#define  NV_POC_LIMIT_SELECTION_I                      ((nv_items_enum_type) 3235)
#define  NV_IM_USERID_I                                ((nv_items_enum_type) 3236)
#define  NV_BC0_VCO_TUNE_2_I                           ((nv_items_enum_type) 3237)
#define  NV_BC1_VCO_TUNE_2_I                           ((nv_items_enum_type) 3238)
#define  NV_BC3_VCO_TUNE_2_I                           ((nv_items_enum_type) 3239)
#define  NV_BC4_VCO_TUNE_2_I                           ((nv_items_enum_type) 3240)
#define  NV_BC5_VCO_TUNE_2_I                           ((nv_items_enum_type) 3241)
#define  NV_BC6_VCO_TUNE_2_I                           ((nv_items_enum_type) 3242)
#define  NV_MM_ENABLE_REAL_I                           ((nv_items_enum_type) 3243)
#define  NV_DIAG_DEBUG_CALL_TRACE_I                    ((nv_items_enum_type) 3244)
#define  NV_ENABLE_FASTTRACK_I                         ((nv_items_enum_type) 3245)
#define  NV_IM_EDIT_MESSENGER_ID_PSWD_I                ((nv_items_enum_type) 3246)
#define  NV_IM_SAFETY_TIP_I                            ((nv_items_enum_type) 3247)
#define  NV_IM_START_STRING_I                          ((nv_items_enum_type) 3248)
#define  NV_IM_MAX_RECEIVED_FILE_LIMIT_I               ((nv_items_enum_type) 3249)
#define  NV_WAP_AUTO_CONNECT_I                         ((nv_items_enum_type) 3250)
#define  NV_WAP_LOCKOUT_TIME_I                         ((nv_items_enum_type) 3251)
#define  NV_DIAG_SPC_UNLOCK_TTL_I                      ((nv_items_enum_type) 3252)
#define  NV_C0_BC0_IM2_LPM_1_I                         ((nv_items_enum_type) 3253)
#define  NV_C0_BC1_IM2_LPM_1_I                         ((nv_items_enum_type) 3254)
#define  NV_C0_BC3_IM2_LPM_1_I                         ((nv_items_enum_type) 3255)
#define  NV_C0_BC4_IM2_LPM_1_I                         ((nv_items_enum_type) 3256)
#define  NV_C0_BC5_IM2_LPM_1_I                         ((nv_items_enum_type) 3257)
#define  NV_C0_BC6_IM2_LPM_1_I                         ((nv_items_enum_type) 3258)
#define  NV_C0_BC0_IM2_LPM_2_I                         ((nv_items_enum_type) 3259)
#define  NV_C0_BC1_IM2_LPM_2_I                         ((nv_items_enum_type) 3260)
#define  NV_C0_BC3_IM2_LPM_2_I                         ((nv_items_enum_type) 3261)
#define  NV_C0_BC4_IM2_LPM_2_I                         ((nv_items_enum_type) 3262)
#define  NV_C0_BC5_IM2_LPM_2_I                         ((nv_items_enum_type) 3263)
#define  NV_C0_BC6_IM2_LPM_2_I                         ((nv_items_enum_type) 3264)
#define  NV_C0_BC0_INTELLICEIVER_CAL_I                 ((nv_items_enum_type) 3265)
#define  NV_C0_BC1_INTELLICEIVER_CAL_I                 ((nv_items_enum_type) 3266)
#define  NV_C0_BC3_INTELLICEIVER_CAL_I                 ((nv_items_enum_type) 3267)
#define  NV_C0_BC4_INTELLICEIVER_CAL_I                 ((nv_items_enum_type) 3268)
#define  NV_C0_BC5_INTELLICEIVER_CAL_I                 ((nv_items_enum_type) 3269)
#define  NV_C0_BC6_INTELLICEIVER_CAL_I                 ((nv_items_enum_type) 3270)
#define  NV_C0_BC0_LNA_SWITCHPOINTS_LPM_1_I            ((nv_items_enum_type) 3271)
#define  NV_C0_BC1_LNA_SWITCHPOINTS_LPM_1_I            ((nv_items_enum_type) 3272)
#define  NV_C0_BC3_LNA_SWITCHPOINTS_LPM_1_I            ((nv_items_enum_type) 3273)
#define  NV_C0_BC4_LNA_SWITCHPOINTS_LPM_1_I            ((nv_items_enum_type) 3274)
#define  NV_C0_BC5_LNA_SWITCHPOINTS_LPM_1_I            ((nv_items_enum_type) 3275)
#define  NV_C0_BC6_LNA_SWITCHPOINTS_LPM_1_I            ((nv_items_enum_type) 3276)
#define  NV_C0_BC0_LNA_SWITCHPOINTS_LPM_2_I            ((nv_items_enum_type) 3277)
#define  NV_C0_BC1_LNA_SWITCHPOINTS_LPM_2_I            ((nv_items_enum_type) 3278)
#define  NV_C0_BC3_LNA_SWITCHPOINTS_LPM_2_I            ((nv_items_enum_type) 3279)
#define  NV_C0_BC4_LNA_SWITCHPOINTS_LPM_2_I            ((nv_items_enum_type) 3280)
#define  NV_C0_BC5_LNA_SWITCHPOINTS_LPM_2_I            ((nv_items_enum_type) 3281)
#define  NV_C0_BC6_LNA_SWITCHPOINTS_LPM_2_I            ((nv_items_enum_type) 3282)
#define  NV_RFR_VCO_COARSE_TUNING_800_I                ((nv_items_enum_type) 3283)
#define  NV_POC_NETINITDEREG_I                         ((nv_items_enum_type) 3284)
#define  NV_POC_APP_TIMEOUT_I                          ((nv_items_enum_type) 3285)
#define  NV_POC_REGISTRATION_TIMEOUT_I                 ((nv_items_enum_type) 3286)
#define  NV_POC_GLM_TIMEOUT_I                          ((nv_items_enum_type) 3287)
#define  NV_JAVA_CONNECTION_PROFILE_ID_I               ((nv_items_enum_type) 3288)
#define  NV_JAVA_INTERNET_PROFILE_ID_I                 ((nv_items_enum_type) 3289)
#define  NV_ENABLE_EXT_GPS_ANTENNA_PWR_SUPPLY_I        ((nv_items_enum_type) 3290)
#define  NV_PRESUPL_WAP_GATEWAY_ADDRESS_I              ((nv_items_enum_type) 3291)
#define  NV_PRESUPL_WAP_GATEWAY_PORT_I                 ((nv_items_enum_type) 3292)
#define  NV_GPS1_POSITION_REPORT_I                     ((nv_items_enum_type) 3293)
#define  NV_SET_VOICE_CALL_TONE_I                      ((nv_items_enum_type) 3294)
#define  NV_CONN_PROFILE_UNPW_RO_OVERRIDE_I            ((nv_items_enum_type) 3295)
#define  NV_INTERNET_PROFILE_UNPW_RO_OVERRIDE_I        ((nv_items_enum_type) 3296)
#define  NV_AAGPS_RTI_VALIDITY_DUR_I                   ((nv_items_enum_type) 3297)
#define  NV_IPV6_UMTS_FAILOVER_CONFIG_I                ((nv_items_enum_type) 3298)
#define  NV_POC_FORBID_CHANGE_USERID_I                 ((nv_items_enum_type) 3299)
#define  NV_POC_WTUSER_PASSWORD_I                      ((nv_items_enum_type) 3300)
#define  NV_CBS_MAX_MSG_PER_TOPIC_I                    ((nv_items_enum_type) 3301)
#define  NV_BROWSER_FWDURL_TO_I                        ((nv_items_enum_type) 3302)
#define  NV_BROWSER_WAP_SIM_COMBINELOCK_I              ((nv_items_enum_type) 3303)
#define  NV_BROWSER_STARTPAGE_READONLY_I               ((nv_items_enum_type) 3304)
#define  NV_CMGR_DISPLAY_RO_FOR_MISSING_DCF_I          ((nv_items_enum_type) 3305)
#define  NV_CMGR_PROMPT_FOR_RO_DELETE_I                ((nv_items_enum_type) 3306)
#define  NV_CMGR_AUTO_REDIRECT_TO_LICENSE_SERVER_I     ((nv_items_enum_type) 3307)
#define  NV_SET_DRM_CONTENT_PROMPT_I                   ((nv_items_enum_type) 3308)
#define  NV_CMGR_WD_REMAINING_HOURS_1_THRESHOLD_I      ((nv_items_enum_type) 3309)
#define  NV_CMGR_WD_REMAINING_HOURS_2_THRESHOLD_I      ((nv_items_enum_type) 3310)
#define  NV_CMGR_WD_RUN_EVERY_HOURS_I                  ((nv_items_enum_type) 3311)
#define  NV_SET_DRM_EXPIRE_WARNING_I                   ((nv_items_enum_type) 3312)
#define  NV_CMGR_MAX_PREVIEW_DATA_SIZE_I               ((nv_items_enum_type) 3313)
#define  NV_BROWSER_DISABLE_IMAGE_RO_I                 ((nv_items_enum_type) 3314)
#define  NV_BROWSER_DISABLE_SOUND_RO_I                 ((nv_items_enum_type) 3315)
#define  NV_BROWSER_TIMEOUT_I                          ((nv_items_enum_type) 3316)
#define  NV_BROWSER_TIMEOUT_RO_I                       ((nv_items_enum_type) 3317)
#define  NV_BROWSER_SECURE_PROMPT_RO_I                 ((nv_items_enum_type) 3318)
#define  NV_BROWSER_FONTSIZE_I                         ((nv_items_enum_type) 3319)
#define  NV_BROWSER_TEXTWRAP_I                         ((nv_items_enum_type) 3320)
#define  NV_BROWSER_SCROLLSTEP_I                       ((nv_items_enum_type) 3321)
#define  NV_BROWSER_EXIT_PROMPT_I                      ((nv_items_enum_type) 3322)
#define  NV_PU_FORCE_ON_I                              ((nv_items_enum_type) 3323)
#define  NV_BROWSER_JUMP_PORTAL_NAME_I                 ((nv_items_enum_type) 3324)
#define  NV_BROWSER_JUMP_EMBDLNK1_NAME_I               ((nv_items_enum_type) 3325)
#define  NV_BROWSER_JUMP_EMBDLNK2_NAME_I               ((nv_items_enum_type) 3326)
#define  NV_BROWSER_JUMP_EMBDLNK3_NAME_I               ((nv_items_enum_type) 3327)
#define  NV_BROWSER_JUMP_EMBDLNK4_NAME_I               ((nv_items_enum_type) 3328)
#define  NV_BROWSER_JUMP_EMBDLNK5_NAME_I               ((nv_items_enum_type) 3329)
#define  NV_BROWSER_JUMP_EMBDLNK6_NAME_I               ((nv_items_enum_type) 3330)
#define  NV_BROWSER_JUMP_EMBDLNK7_NAME_I               ((nv_items_enum_type) 3331)
#define  NV_BROWSER_JUMP_EMBDLNK8_NAME_I               ((nv_items_enum_type) 3332)
#define  NV_VOICE_MAIL_LINE1_I                         ((nv_items_enum_type) 3333)
#define  NV_VOICE_MAIL_USE_SIM_NUMBER_I                ((nv_items_enum_type) 3334)
#define  NV_VOICE_MAIL_NOTIFY_I                        ((nv_items_enum_type) 3335)
#define  NV_VOICE_MAIL_LINE2_I                         ((nv_items_enum_type) 3336)
#define  NV_CAMERA_APP_SAVE_LOCATION_I                 ((nv_items_enum_type) 3337)
#define  NV_VT_SHOW_MY_IMAGE_I                         ((nv_items_enum_type) 3338)
#define  NV_VT_AUTO_REDIAL_I                           ((nv_items_enum_type) 3339)
#define  NV_SET_RINGER_VOLUME_I                        ((nv_items_enum_type) 3340)
#define  NV_WCDMA_C0_TX_LIM_VS_FREQ_I                  ((nv_items_enum_type) 3341)
#define  NV_SOS_KEY_ENABLED_I                          ((nv_items_enum_type) 3342)
#define  NV_SOS_NUMBER_I                               ((nv_items_enum_type) 3343)
#define  NV_WAP_TRUSTED_DOMAIN_I                       ((nv_items_enum_type) 3344)
#define  NV_WAP_PUSH_AUTOLOAD_I                        ((nv_items_enum_type) 3345)
#define  NV_IM_SERVER_ADDRESS_I                        ((nv_items_enum_type) 3346)
#define  NV_POC_TIMEOUT_SCALE_I                        ((nv_items_enum_type) 3347)
#define  NV_MR_DEFAULTS_STORED_I                       ((nv_items_enum_type) 3348)
#define  NV_SET_PLAY_STARTUP_SOUND_I                   ((nv_items_enum_type) 3349)
#define  NV_SET_PLAY_SHUTDOWN_SOUND_I                  ((nv_items_enum_type) 3350)
#define  NV_SET_PLAY_STARTUP_ANIMATION_I               ((nv_items_enum_type) 3351)
#define  NV_SET_PLAY_SHUTDOWN_ANIMATION_I              ((nv_items_enum_type) 3352)
#define  NV_GSM_POLAR_RAMP_PROFILE_I                   ((nv_items_enum_type) 3353)
#define  NV_GPS1_MSB_BACK_OFF_FACTOR_I                 ((nv_items_enum_type) 3354)
#define  NV_GPS1_MSB_BACK_OFF_MIN_I                    ((nv_items_enum_type) 3355)
#define  NV_GPS1_MSB_BACK_OFF_MAX_I                    ((nv_items_enum_type) 3356)
#define  NV_GPS1_MSB_BACK_OFF_RESET_I                  ((nv_items_enum_type) 3357)
#define  NV_GPS1_MSB_THROTTLE_ENABLE_I                 ((nv_items_enum_type) 3358)
#define  NV_MANUAL_PLMN_SEL_I                          ((nv_items_enum_type) 3359)
#define  NV_MANUAL_PLMN_SELECTION_I                    ((nv_items_enum_type) 3360)
#define  NV_CONSORTIUM_CONFIG_NUMB_I                   ((nv_items_enum_type) 3361)
#define  NV_HDR_EQUALIZER_CTRL_I                       ((nv_items_enum_type) 3362)
#define  NV_WLAN_ENABLE_PS_MODE_I                      ((nv_items_enum_type) 3363)
#define  NV_MF_700_LNA_RISE_2_I                        ((nv_items_enum_type) 3364)
#define  NV_MF_700_LNA_RISE_3_I                        ((nv_items_enum_type) 3365)
#define  NV_MF_700_LNA_RISE_4_I                        ((nv_items_enum_type) 3366)
#define  NV_MF_700_LNA_FALL_2_I                        ((nv_items_enum_type) 3367)
#define  NV_MF_700_LNA_FALL_3_I                        ((nv_items_enum_type) 3368)
#define  NV_MF_700_LNA_FALL_4_I                        ((nv_items_enum_type) 3369)
#define  NV_MF_700_AGC_VS_FREQ_I                       ((nv_items_enum_type) 3370)
#define  NV_MF_700_RX_CAL_CHAN_I                       ((nv_items_enum_type) 3371)
#define  NV_MF_HW_CONFIG_I                             ((nv_items_enum_type) 3372)
#define  NV_MF_BAND_CONFIG_I                           ((nv_items_enum_type) 3373)
#define  NV_MF_AFC_LOOP_PARAMS_I                       ((nv_items_enum_type) 3374)
#define  NV_LAST_REGISTERED_SCI_I                      ((nv_items_enum_type) 3375)
#define  NV_MMS_MAX_CHARS_SLIDE_I                      ((nv_items_enum_type) 3376)
#define  NV_MMS_MAX_NUMBER_OF_SLIDES_I                 ((nv_items_enum_type) 3377)
#define  NV_MMS_MAX_SUBJECT_SIZE_I                     ((nv_items_enum_type) 3378)
#define  NV_QVP_APP_DEFAULT_AUDIO_CAPABILITY_TYPE_I    ((nv_items_enum_type) 3379)
#define  NV_QVP_APP_DEFAULT_VIDEO_CAPABILITY_TYPE_I    ((nv_items_enum_type) 3380)
#define  NV_HDRMRLP_NUM_BYTES_TO_LOG_I                 ((nv_items_enum_type) 3381)
#define  NV_SECTIME_TIME_OFFSETS_I                     ((nv_items_enum_type) 3382)
#define  NV_DS_UCSD_NT_CONNECT_STATE_I                 ((nv_items_enum_type) 3383)
#define  NV_PB_RECORDASOUND_I                          ((nv_items_enum_type) 3384)
#define  NV_PB_AUTO_POWER_OFF_I                        ((nv_items_enum_type) 3385)
#define  NV_BC0_HDR_G0_IM_FALL_I                       ((nv_items_enum_type) 3386)
#define  NV_BC0_HDR_G0_IM_RISE_I                       ((nv_items_enum_type) 3387)
#define  NV_BC0_HDR_G0_IM_LEVEL_I                      ((nv_items_enum_type) 3388)
#define  NV_SET_LINGER_TIME_I                          ((nv_items_enum_type) 3389)
#define  NV_PB_SIM_DEFAULTNUMBERPRIORITY_FIRST_I       ((nv_items_enum_type) 3390)
#define  NV_PB_SIM_DEFAULTNUMBERPRIORITY_SECOND_I      ((nv_items_enum_type) 3391)
#define  NV_PB_SIM_DEFAULTNUMBERPRIORITY_THIRD_I       ((nv_items_enum_type) 3392)
#define  NV_PB_DEFAULT_SORTING_I                       ((nv_items_enum_type) 3393)
#define  NV_SND_SEND_RESTRICTED_I                      ((nv_items_enum_type) 3394)
#define  NV_POC_ROAMIING_ALERT_ENABLED_I               ((nv_items_enum_type) 3395)
#define  NV_GSM_850_PRECHARGE_I                        ((nv_items_enum_type) 3396)
#define  NV_GSM_850_PRECHARGE_DUR_I                    ((nv_items_enum_type) 3397)
#define  NV_GSM_1900_PRECHARGE_I                       ((nv_items_enum_type) 3398)
#define  NV_GSM_1900_PRECHARGE_DUR_I                   ((nv_items_enum_type) 3399)
#define  NV_MS_SMS_USE_SMSC_FROM_SIM_I                 ((nv_items_enum_type) 3400)
#define  NV_BROWSER_JUMP_MENU_SETTING_ENABLED_I        ((nv_items_enum_type) 3401)
#define  NV_BROWSER_DRM_WAIT_TIME_I                    ((nv_items_enum_type) 3402)
#define  NV_LC_ENABLED_I                               ((nv_items_enum_type) 3403)
#define  NV_LC_SERVICENAME_I                           ((nv_items_enum_type) 3404)
#define  NV_LC_CONNECTIONPROFILE_I                     ((nv_items_enum_type) 3405)
#define  NV_LC_INTERNETPROFILE_I                       ((nv_items_enum_type) 3406)
#define  NV_LC_UDPPUSHSERVERNAME_I                     ((nv_items_enum_type) 3407)
#define  NV_LC_UDPPUSHSERVERPORT_I                     ((nv_items_enum_type) 3408)
#define  NV_LC_UDPPUSHRETRYTIMES_I                     ((nv_items_enum_type) 3409)
#define  NV_LC_UDPPUSHRETRYSECONDS_I                   ((nv_items_enum_type) 3410)
#define  NV_LC_MSGASSEMBLYTIMEOUT_I                    ((nv_items_enum_type) 3411)
#define  NV_LC_TICKERTIMEOUT_I                         ((nv_items_enum_type) 3412)
#define  NV_LC_TICKERSPEED_I                           ((nv_items_enum_type) 3413)
#define  NV_LC_TICKERSTARTDELAY_I                      ((nv_items_enum_type) 3414)
#define  NV_LC_MAXTICKERITEMS_I                        ((nv_items_enum_type) 3415)
#define  NV_LC_BACKLIGHTTIMEOUT_I                      ((nv_items_enum_type) 3416)
#define  NV_LC_TRUSTEDDOMAIN_I                         ((nv_items_enum_type) 3417)
#define  NV_LC_SUBURL_KEY_LABEL_I                      ((nv_items_enum_type) 3418)
#define  NV_HOMEZONE_ENABLED_I                         ((nv_items_enum_type) 3419)
#define  NV_BC0_ANT_QUALITY_I                          ((nv_items_enum_type) 3420)
#define  NV_BC1_ANT_QUALITY_I                          ((nv_items_enum_type) 3421)
#define  NV_BC3_ANT_QUALITY_I                          ((nv_items_enum_type) 3422)
#define  NV_BC4_ANT_QUALITY_I                          ((nv_items_enum_type) 3423)
#define  NV_BC5_ANT_QUALITY_I                          ((nv_items_enum_type) 3424)
#define  NV_BC6_ANT_QUALITY_I                          ((nv_items_enum_type) 3425)
#define  NV_MEDIA_PLAYER_MIN_UDP_PORT_I                ((nv_items_enum_type) 3426)
#define  NV_MEDIA_PLAYER_MAX_UDP_PORT_I                ((nv_items_enum_type) 3427)
#define  NV_MEDIA_PLAYER_CONN_PROF_I                   ((nv_items_enum_type) 3428)
#define  NV_MEDIA_PLAYER_QOS_ENABLE_I                  ((nv_items_enum_type) 3429)
#define  NV_GPS1_NUM_SEARCHER_TASKS_I                  ((nv_items_enum_type) 3430)
#define  NV_GSM_PA_TRANSITION_TABLE_I                  ((nv_items_enum_type) 3431)
#define  NV_K_KEY_I                                    ((nv_items_enum_type) 3432)
#define  NV_CIPHER_KEY_I                               ((nv_items_enum_type) 3433)
#define  NV_INT_KEY_I                                  ((nv_items_enum_type) 3434)
#define  NV_LAST_3G_KEY_ID_I                           ((nv_items_enum_type) 3435)
#define  NV_SSEQ_I                                     ((nv_items_enum_type) 3436)
#define  NV_CK_THRESHOLD_I                             ((nv_items_enum_type) 3437)
#define  NV_SQN_ARR_1_I                                ((nv_items_enum_type) 3438)
#define  NV_SQN_ARR_2_I                                ((nv_items_enum_type) 3439)
#define  NV_WCDMA_MIN_TX_POWER_I                       ((nv_items_enum_type) 3440)
#define  NV_CCBS_SEL_I                                 ((nv_items_enum_type) 3441)
#define  NV_HOME_SCREEN_ENABLED_I                      ((nv_items_enum_type) 3442)
#define  NV_HOME_SCREEN_LAYOUT_I                       ((nv_items_enum_type) 3443)
#define  NV_IS_THM_INITIALIZED_I                       ((nv_items_enum_type) 3444)
#define  NV_HEAPTRACKER_ENABLED_I                      ((nv_items_enum_type) 3445)
#define  NV_TRM_CONFIG_I                               ((nv_items_enum_type) 3446)
#define  NV_IRDA_INACTIVITY_TIMER_I                    ((nv_items_enum_type) 3447)
#define  NV_MMS_MAX_TEMPLATES_I                        ((nv_items_enum_type) 3448)
#define  NV_MMS_TEXT_SIZE_I                            ((nv_items_enum_type) 3449)
#define  NV_VIDEO_APP_SAVE_LOCATION_I                  ((nv_items_enum_type) 3450)
#define  NV_CAMERA_DEFAULT_NAME_PREFIX_I               ((nv_items_enum_type) 3451)
#define  NV_VIDEO_DEFAULT_NAME_PREFIX_I                ((nv_items_enum_type) 3452)
#define  NV_CAMERA_AUDIO_RECORD_I                      ((nv_items_enum_type) 3453)
#define  NV_CAMERA_PICT_RESOLUTION_FRONT_I             ((nv_items_enum_type) 3454)
#define  NV_CAMERA_PICT_RESOLUTION_BACK_I              ((nv_items_enum_type) 3455)
#define  NV_CAMERA_VIDEO_RESOLUTION_FRONT_I            ((nv_items_enum_type) 3456)
#define  NV_CAMERA_VIDEO_RESOLUTION_BACK_I             ((nv_items_enum_type) 3457)
#define  NV_HDRSCP_SUBTYPE_CUSTOM_CONFIG_I             ((nv_items_enum_type) 3458)
#define  NV_SET_LINGER_TIME_MENU_ENABLE_I              ((nv_items_enum_type) 3459)
#define  NV_JAVA_SHOW_LOGO_ON_START_I                  ((nv_items_enum_type) 3460)
#define  NV_ENS_ENABLED_I                              ((nv_items_enum_type) 3461)
#define  NV_DIAG_SPC_TIMEOUT_I                         ((nv_items_enum_type) 3462)
#define  NV_MS_SMS_HEADER_TEMPLATE_FILE_I              ((nv_items_enum_type) 3463)
#define  NV_MS_SMS_SIGNATURE_TEMPLATE_FILE_I           ((nv_items_enum_type) 3464)
#define  NV_HDRIDLE_ENHANCED_CONFIG_I                  ((nv_items_enum_type) 3465)
#define  NV_HDRIDLE_SLOT_CYCLE_TIMEOUTS_I              ((nv_items_enum_type) 3466)
#define  NV_BACK_LIGHT_INTENSITY_I                     ((nv_items_enum_type) 3467)
#define  NV_DISPLAY_DURATION_I                         ((nv_items_enum_type) 3468)
#define  NV_C0_BC0_INTELLICEIVER_DET_THRESH_I          ((nv_items_enum_type) 3469)
#define  NV_C0_BC1_INTELLICEIVER_DET_THRESH_I          ((nv_items_enum_type) 3470)
#define  NV_C0_BC3_INTELLICEIVER_DET_THRESH_I          ((nv_items_enum_type) 3471)
#define  NV_C0_BC4_INTELLICEIVER_DET_THRESH_I          ((nv_items_enum_type) 3472)
#define  NV_C0_BC5_INTELLICEIVER_DET_THRESH_I          ((nv_items_enum_type) 3473)
#define  NV_C0_BC6_INTELLICEIVER_DET_THRESH_I          ((nv_items_enum_type) 3474)
#define  NV_SET_VOICE_VOLUME_I                         ((nv_items_enum_type) 3475)
#define  NV_SET_MEDIA_VOLUME_I                         ((nv_items_enum_type) 3476)
#define  NV_HDRRMAC_CONFIG_I                           ((nv_items_enum_type) 3477)
#define  NV_GPS1_CROSS_CORR_THRESHOLD_DBHZ_I           ((nv_items_enum_type) 3478)
#define  NV_GPS1_CME_T_TRACK_THRESHOLD_I               ((nv_items_enum_type) 3479)
#define  NV_GPS1_VX_LCSAGENT_V2_HANDOFF_ENABLE_I       ((nv_items_enum_type) 3480)
#define  NV_GPS1_VX_LCSAGENT_MO_BACKOFF_DURATION_I     ((nv_items_enum_type) 3481)
#define  NV_ODM_BACKLIGHT_INTENSITY_I                  ((nv_items_enum_type) 3482)
#define  NV_ODM_POWER_SAVE_TIMEOUT_I                   ((nv_items_enum_type) 3483)
#define  NV_ODM_BACKLIGHT_TIMEOUT_I                    ((nv_items_enum_type) 3484)
#define  NV_TIMEZONE_CITY_I                            ((nv_items_enum_type) 3485)
#define  NV_SIGMAREJECT_I                              ((nv_items_enum_type) 3486)
#define  NV_VELNOISEINONESECDRIVE_I                    ((nv_items_enum_type) 3487)
#define  NV_VELNOISEINONESECPED_I                      ((nv_items_enum_type) 3488)
#define  NV_VELNOISEINONESECSTATIC_I                   ((nv_items_enum_type) 3489)
#define  NV_EXTRACLOCKBIASERROR_I                      ((nv_items_enum_type) 3490)
#define  NV_CONFIGMASK_I                               ((nv_items_enum_type) 3491)
#define  NV_MAXPROPAGATIONWONEWMEAS_I                  ((nv_items_enum_type) 3492)
#define  NV_CONFIGCONTROLFLAG_I                        ((nv_items_enum_type) 3493)
#define  NV_AAGPS_DEVELOPMENT_TEST_CONTROL6_I          ((nv_items_enum_type) 3494)
#define  NV_SET_ALARM_CLOCK_TONE_SETTING_I             ((nv_items_enum_type) 3495)
#define  NV_SYS_DEFAULT_EFS_FILE_NAME_I                ((nv_items_enum_type) 3496)
#define  NV_SYS_EFS_FILE_NAME_I                        ((nv_items_enum_type) 3497)
#define  NV_SYS_DEFAULT_NV_INI_FILE_NAME_I             ((nv_items_enum_type) 3498)
#define  NV_SYS_NV_INI_FILE_NAME_I                     ((nv_items_enum_type) 3499)
#define  NV_SYS_SCRIPT_FILE_NAME_I                     ((nv_items_enum_type) 3500)
#define  NV_GSM_GAINRANGE5_SWITCHPOINTS_I              ((nv_items_enum_type) 3501)
#define  NV_GSM_RX_GAIN_RANGE_5_FREQ_COMP_I            ((nv_items_enum_type) 3502)
#define  NV_DCS_RX_GAIN_RANGE_5_FREQ_COMP_I            ((nv_items_enum_type) 3503)
#define  NV_GSM_850_RX_GAIN_RANGE_5_FREQ_COMP_I        ((nv_items_enum_type) 3504)
#define  NV_GSM_1900_RX_GAIN_RANGE_5_FREQ_COMP_I       ((nv_items_enum_type) 3505)
#define  NV_DCS_GAINRANGE5_SWITCHPOINTS_I              ((nv_items_enum_type) 3506)
#define  NV_GSM_850_GAINRANGE5_SWITCHPOINTS_I          ((nv_items_enum_type) 3507)
#define  NV_GSM_1900_GAINRANGE5_SWITCHPOINTS_I         ((nv_items_enum_type) 3508)
#define  NV_DCS_POLAR_RAMP_PROFILE_I                   ((nv_items_enum_type) 3509)
#define  NV_GSM_1900_POLAR_RAMP_PROFILE_I              ((nv_items_enum_type) 3510)
#define  NV_GSM_850_POLAR_RAMP_PROFILE_I               ((nv_items_enum_type) 3511)
#define  NV_WCDMA_TX_LIM_VS_TEMP_VOICE_CALL_ACTIVE_I   ((nv_items_enum_type) 3512)
#define  NV_HDRBCMCS_DISABLE_ONE_TIME_REG_I            ((nv_items_enum_type) 3513)
#define  NV_HDRBCMCS_DISABLE_SUBNET_REG_I              ((nv_items_enum_type) 3514)
#define  NV_CDMA_RX_CHAIN_SEL_THRESH_I                 ((nv_items_enum_type) 3515)
#define  NV_SET_AUTO_KEYLOCK_I                         ((nv_items_enum_type) 3516)
#define  NV_SET_ANY_KEY_ANSWER_I                       ((nv_items_enum_type) 3517)
#define  NV_VP_FRAME_RATE_I                            ((nv_items_enum_type) 3518)
#define  NV_DYN_CLOCK_VOLTAGE_I                        ((nv_items_enum_type) 3519)
#define  NV_GPS1_SEEDPOS_OPTION_I                      ((nv_items_enum_type) 3520)
#define  NV_MS_SEND_ATTEMPTS_I                         ((nv_items_enum_type) 3521)
#define  NV_MS_PERIOD_BETW_SEND_ATTEMPTS_I             ((nv_items_enum_type) 3522)
#define  NV_MS_SEND_IN_BACKGROUND_I                    ((nv_items_enum_type) 3523)
#define  NV_WCDMA_DL_FREQ_I                            ((nv_items_enum_type) 3524)
#define  NV_WCDMA_DL_FREQ_ENABLED_I                    ((nv_items_enum_type) 3525)
#define  NV_MS_SMS_SMSC_ADDRESS6_I                     ((nv_items_enum_type) 3526)
#define  NV_MS_SMS_SMSC_ADDRESS7_I                     ((nv_items_enum_type) 3527)
#define  NV_MS_SMS_SMSC_ADDRESS8_I                     ((nv_items_enum_type) 3528)
#define  NV_MS_SMS_SMSC_ADDRESS9_I                     ((nv_items_enum_type) 3529)
#define  NV_MS_SMS_SMSC_ADDRESS10_I                    ((nv_items_enum_type) 3530)
#define  NV_AUTO_TIME_ENABLE_I                         ((nv_items_enum_type) 3531)
#define  NV_SMS_MO_RETRY_PERIOD_I                      ((nv_items_enum_type) 3532)
#define  NV_SMS_MO_RETRY_INTERVAL_I                    ((nv_items_enum_type) 3533)
#define  NV_RMNET_AUTOCONNECT_I                        ((nv_items_enum_type) 3534)
#define  NV_ENABLE_BT_DIAG_I                           ((nv_items_enum_type) 3535)
#define  NV_BC14_TX_LIN_MASTER0_I                      ((nv_items_enum_type) 3536)
#define  NV_BC14_TX_LIN_MASTER1_I                      ((nv_items_enum_type) 3537)
#define  NV_BC14_TX_LIN_MASTER2_I                      ((nv_items_enum_type) 3538)
#define  NV_BC14_TX_LIN_MASTER3_I                      ((nv_items_enum_type) 3539)
#define  NV_BC14_GPS1_RF_DELAY_I                       ((nv_items_enum_type) 3540)
#define  NV_BC14_TX_LIM_VS_TEMP_I                      ((nv_items_enum_type) 3541)
#define  NV_BC14_TX_COMP0_I                            ((nv_items_enum_type) 3542)
#define  NV_BC14_TX_COMP1_I                            ((nv_items_enum_type) 3543)
#define  NV_BC14_TX_COMP2_I                            ((nv_items_enum_type) 3544)
#define  NV_BC14_TX_COMP3_I                            ((nv_items_enum_type) 3545)
#define  NV_BC14_TX_LIM_VS_FREQ_I                      ((nv_items_enum_type) 3546)
#define  NV_BC14_PA_R1_RISE_I                          ((nv_items_enum_type) 3547)
#define  NV_BC14_PA_R1_FALL_I                          ((nv_items_enum_type) 3548)
#define  NV_BC14_PA_R2_RISE_I                          ((nv_items_enum_type) 3549)
#define  NV_BC14_PA_R2_FALL_I                          ((nv_items_enum_type) 3550)
#define  NV_BC14_PA_R3_RISE_I                          ((nv_items_enum_type) 3551)
#define  NV_BC14_PA_R3_FALL_I                          ((nv_items_enum_type) 3552)
#define  NV_BC14_HDET_OFF_I                            ((nv_items_enum_type) 3553)
#define  NV_BC14_HDET_SPN_I                            ((nv_items_enum_type) 3554)
#define  NV_BC14_EXP_HDET_VS_AGC_I                     ((nv_items_enum_type) 3555)
#define  NV_BC14_ENC_BTF_I                             ((nv_items_enum_type) 3556)
#define  NV_BC14_VCO_COARSE_TUNE_TABLE_I               ((nv_items_enum_type) 3557)
#define  NV_BC14_VCO_TUNE_2_I                          ((nv_items_enum_type) 3558)
#define  NV_BC14_P1_RISE_FALL_OFF_I                    ((nv_items_enum_type) 3559)
#define  NV_BC14_HDR_P1_RISE_FALL_OFF_I                ((nv_items_enum_type) 3560)
#define  NV_C0_BC14_TX_CAL_CHAN_I                      ((nv_items_enum_type) 3561)
#define  NV_C0_BC14_RX_CAL_CHAN_I                      ((nv_items_enum_type) 3562)
#define  NV_C0_BC14_RX_CAL_CHAN_LRU_I                  ((nv_items_enum_type) 3563)
#define  NV_C0_BC14_LNA_1_OFFSET_I                     ((nv_items_enum_type) 3564)
#define  NV_C0_BC14_LNA_2_OFFSET_I                     ((nv_items_enum_type) 3565)
#define  NV_C0_BC14_LNA_3_OFFSET_I                     ((nv_items_enum_type) 3566)
#define  NV_C0_BC14_LNA_4_OFFSET_I                     ((nv_items_enum_type) 3567)
#define  NV_C0_BC14_LNA_1_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3568)
#define  NV_C0_BC14_LNA_2_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3569)
#define  NV_C0_BC14_LNA_3_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3570)
#define  NV_C0_BC14_LNA_4_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3571)
#define  NV_C0_BC14_IM2_I_VALUE_I                      ((nv_items_enum_type) 3572)
#define  NV_C0_BC14_IM2_Q_VALUE_I                      ((nv_items_enum_type) 3573)
#define  NV_C0_BC14_VGA_GAIN_OFFSET_I                  ((nv_items_enum_type) 3574)
#define  NV_C0_BC14_VGA_GAIN_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 3575)
#define  NV_C0_BC14_IM2_TRANSCONDUCTOR_VALUE_I         ((nv_items_enum_type) 3576)
#define  NV_C0_BC14_LNA_1_RISE_I                       ((nv_items_enum_type) 3577)
#define  NV_C0_BC14_LNA_1_FALL_I                       ((nv_items_enum_type) 3578)
#define  NV_C0_BC14_LNA_2_RISE_I                       ((nv_items_enum_type) 3579)
#define  NV_C0_BC14_LNA_2_FALL_I                       ((nv_items_enum_type) 3580)
#define  NV_C0_BC14_LNA_3_RISE_I                       ((nv_items_enum_type) 3581)
#define  NV_C0_BC14_LNA_3_FALL_I                       ((nv_items_enum_type) 3582)
#define  NV_C0_BC14_LNA_4_RISE_I                       ((nv_items_enum_type) 3583)
#define  NV_C0_BC14_LNA_4_FALL_I                       ((nv_items_enum_type) 3584)
#define  NV_C0_BC14_IM_LEVEL1_I                        ((nv_items_enum_type) 3585)
#define  NV_C0_BC14_IM_LEVEL2_I                        ((nv_items_enum_type) 3586)
#define  NV_C0_BC14_IM_LEVEL3_I                        ((nv_items_enum_type) 3587)
#define  NV_C0_BC14_IM_LEVEL4_I                        ((nv_items_enum_type) 3588)
#define  NV_C1_BC14_TX_CAL_CHAN_I                      ((nv_items_enum_type) 3589)
#define  NV_C1_BC14_RX_CAL_CHAN_I                      ((nv_items_enum_type) 3590)
#define  NV_C1_BC14_LNA_1_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3591)
#define  NV_C1_BC14_LNA_2_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3592)
#define  NV_C1_BC14_LNA_3_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3593)
#define  NV_C1_BC14_LNA_4_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3594)
#define  NV_C1_BC14_LNA_1_OFFSET_I                     ((nv_items_enum_type) 3595)
#define  NV_C1_BC14_LNA_2_OFFSET_I                     ((nv_items_enum_type) 3596)
#define  NV_C1_BC14_LNA_3_OFFSET_I                     ((nv_items_enum_type) 3597)
#define  NV_C1_BC14_LNA_4_OFFSET_I                     ((nv_items_enum_type) 3598)
#define  NV_C1_BC14_IM2_I_VALUE_I                      ((nv_items_enum_type) 3599)
#define  NV_C1_BC14_IM2_Q_VALUE_I                      ((nv_items_enum_type) 3600)
#define  NV_C1_BC14_VGA_GAIN_OFFSET_I                  ((nv_items_enum_type) 3601)
#define  NV_C1_BC14_VGA_GAIN_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 3602)
#define  NV_C1_BC14_IM2_TRANSCONDUCTOR_VALUE_I         ((nv_items_enum_type) 3603)
#define  NV_C1_BC14_LNA_1_RISE_I                       ((nv_items_enum_type) 3604)
#define  NV_C1_BC14_LNA_1_FALL_I                       ((nv_items_enum_type) 3605)
#define  NV_C1_BC14_LNA_2_RISE_I                       ((nv_items_enum_type) 3606)
#define  NV_C1_BC14_LNA_2_FALL_I                       ((nv_items_enum_type) 3607)
#define  NV_C1_BC14_LNA_3_RISE_I                       ((nv_items_enum_type) 3608)
#define  NV_C1_BC14_LNA_3_FALL_I                       ((nv_items_enum_type) 3609)
#define  NV_C1_BC14_LNA_4_RISE_I                       ((nv_items_enum_type) 3610)
#define  NV_C1_BC14_LNA_4_FALL_I                       ((nv_items_enum_type) 3611)
#define  NV_C1_BC14_IM_LEVEL1_I                        ((nv_items_enum_type) 3612)
#define  NV_C1_BC14_IM_LEVEL2_I                        ((nv_items_enum_type) 3613)
#define  NV_C1_BC14_IM_LEVEL3_I                        ((nv_items_enum_type) 3614)
#define  NV_C1_BC14_IM_LEVEL4_I                        ((nv_items_enum_type) 3615)
#define  NV_C1_BC14_VCO_COARSE_TUNE_TABLE_I            ((nv_items_enum_type) 3616)
#define  NV_BC14_ANT_QUALITY_I                         ((nv_items_enum_type) 3617)
#define  NV_BC14_PA_DVS_VOLTAGE_I                      ((nv_items_enum_type) 3618)
#define  NV_C0_BC14_LNA_SWITCHPOINTS_LPM_1_I           ((nv_items_enum_type) 3619)
#define  NV_C0_BC14_LNA_SWITCHPOINTS_LPM_2_I           ((nv_items_enum_type) 3620)
#define  NV_C0_BC14_IM2_LPM_1_I                        ((nv_items_enum_type) 3621)
#define  NV_C0_BC14_IM2_LPM_2_I                        ((nv_items_enum_type) 3622)
#define  NV_C0_BC14_INTELLICEIVER_CAL_I                ((nv_items_enum_type) 3623)
#define  NV_C0_BC14_INTELLICEIVER_DET_THRESH_I         ((nv_items_enum_type) 3624)
#define  NV_C1_BC14_RX_CAL_CHAN_LRU_I                  ((nv_items_enum_type) 3625)
#define  NV_SYS_VARIANT_NAME_I                         ((nv_items_enum_type) 3626)
#define  NV_SET_SSAVER_AUTO_KEYLOCK_I                  ((nv_items_enum_type) 3627)
#define  NV_DTM_FEATURE_SUPPORT_I                      ((nv_items_enum_type) 3628)
#define  NV_DTM_MULTISLOT_CLASS_I                      ((nv_items_enum_type) 3629)
#define  NV_EDA_FEATURE_SUPPORT_I                      ((nv_items_enum_type) 3630)
#define  NV_MF_MRU_CHAN_I                              ((nv_items_enum_type) 3631)
#define  NV_SRCH_DBG_MASK_I                            ((nv_items_enum_type) 3632)
#define  NV_STRIDE_ACTIVE_I                            ((nv_items_enum_type) 3633)
#define  NV_DDTM_SETTINGS_I                            ((nv_items_enum_type) 3634)
#define  NV_SD_CFG_ITEMS_I                             ((nv_items_enum_type) 3635)
#define  NV_VOIP_QOS_EVDO_SIP_PROFILE_ID_I             ((nv_items_enum_type) 3636)
#define  NV_VOIP_QOS_EVDO_RTP_PROFILE_ID_I             ((nv_items_enum_type) 3637)
#define  NV_VOIP_QOS_EVDO_DSCP_I                       ((nv_items_enum_type) 3638)
#define  NV_VOIP_DTX_ENABLED_I                         ((nv_items_enum_type) 3639)
#define  NV_MF_AFC_INNER_LOOP_GAIN_I                   ((nv_items_enum_type) 3640)
#define  NV_MF_AFC_INIT_FREQ_OFFSET_I                  ((nv_items_enum_type) 3641)
#define  NV_MF_C0_IM2_I_VALUE_I                        ((nv_items_enum_type) 3642)
#define  NV_MF_C0_IM2_Q_VALUE_I                        ((nv_items_enum_type) 3643)
#define  NV_MF_C0_IM2_TRANSCONDUCTOR_VALUE_I           ((nv_items_enum_type) 3644)
#define  NV_MF_C1_IM2_I_VALUE_I                        ((nv_items_enum_type) 3645)
#define  NV_MF_C1_IM2_Q_VALUE_I                        ((nv_items_enum_type) 3646)
#define  NV_MF_C1_IM2_TRANSCONDUCTOR_VALUE_I           ((nv_items_enum_type) 3647)
#define  NV_MF_ACQ_PARAMETERS_I                        ((nv_items_enum_type) 3648)
#define  NV_WCDMA_RRC_VERSION_I                        ((nv_items_enum_type) 3649)
#define  NV_WCDMA_900_VGA_GAIN_OFFSET_I                ((nv_items_enum_type) 3650)
#define  NV_WCDMA_900_VGA_GAIN_OFFSET_VS_FREQ_I        ((nv_items_enum_type) 3651)
#define  NV_WCDMA_900_VGA_GAIN_OFFSET_VS_TEMP_I        ((nv_items_enum_type) 3652)
#define  NV_WCDMA_900_LNA_RANGE_RISE_2_I               ((nv_items_enum_type) 3653)
#define  NV_WCDMA_900_LNA_RANGE_RISE_3_I               ((nv_items_enum_type) 3654)
#define  NV_WCDMA_900_LNA_RANGE_FALL_2_I               ((nv_items_enum_type) 3655)
#define  NV_WCDMA_900_LNA_RANGE_FALL_3_I               ((nv_items_enum_type) 3656)
#define  NV_WCDMA_900_IM_LEVEL_2_I                     ((nv_items_enum_type) 3657)
#define  NV_WCDMA_900_IM_LEVEL_3_I                     ((nv_items_enum_type) 3658)
#define  NV_WCDMA_900_LNA_RANGE_OFFSET_2_I             ((nv_items_enum_type) 3659)
#define  NV_WCDMA_900_LNA_RANGE_OFFSET_3_I             ((nv_items_enum_type) 3660)
#define  NV_WCDMA_900_LNA_OFFSET_VS_FREQ_2_I           ((nv_items_enum_type) 3661)
#define  NV_WCDMA_900_LNA_OFFSET_VS_FREQ_3_I           ((nv_items_enum_type) 3662)
#define  NV_WCDMA_900_IM2_I_VALUE_I                    ((nv_items_enum_type) 3663)
#define  NV_WCDMA_900_IM2_Q_VALUE_I                    ((nv_items_enum_type) 3664)
#define  NV_WCDMA_900_IM2_TRANSCONDUCTOR_VALUE_I       ((nv_items_enum_type) 3665)
#define  NV_WCDMA_900_RX_AGC_MIN_2_I                   ((nv_items_enum_type) 3666)
#define  NV_WCDMA_900_RX_AGC_MIN_3_I                   ((nv_items_enum_type) 3667)
#define  NV_WCDMA_900_MAX_TX_POWER_I                   ((nv_items_enum_type) 3668)
#define  NV_WCDMA_900_OUT_OF_SERVICE_THRESH_I          ((nv_items_enum_type) 3669)
#define  NV_WCDMA_900_LNA_RANGE_RISE_I                 ((nv_items_enum_type) 3670)
#define  NV_WCDMA_900_LNA_RANGE_FALL_I                 ((nv_items_enum_type) 3671)
#define  NV_WCDMA_900_IM_LEVEL_I                       ((nv_items_enum_type) 3672)
#define  NV_WCDMA_900_NONBYPASS_TIMER_I                ((nv_items_enum_type) 3673)
#define  NV_WCDMA_900_BYPASS_TIMER_I                   ((nv_items_enum_type) 3674)
#define  NV_WCDMA_900_LNA_RANGE_OFFSET_I               ((nv_items_enum_type) 3675)
#define  NV_WCDMA_900_LNA_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3676)
#define  NV_WCDMA_900_RX_AGC_MIN_I                     ((nv_items_enum_type) 3677)
#define  NV_WCDMA_900_RX_AGC_MAX_I                     ((nv_items_enum_type) 3678)
#define  NV_WCDMA_900_AGC_PHASE_OFFSET_I               ((nv_items_enum_type) 3679)
#define  NV_WCDMA_900_TX_LIN_MASTER_0_I                ((nv_items_enum_type) 3680)
#define  NV_WCDMA_900_TX_LIN_MASTER_1_I                ((nv_items_enum_type) 3681)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_0_I              ((nv_items_enum_type) 3682)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_1_I              ((nv_items_enum_type) 3683)
#define  NV_WCDMA_900_TX_LIN_VS_TEMP_0_I               ((nv_items_enum_type) 3684)
#define  NV_WCDMA_900_TX_LIN_VS_TEMP_1_I               ((nv_items_enum_type) 3685)
#define  NV_WCDMA_900_TX_SLP_VS_TEMP_0_I               ((nv_items_enum_type) 3686)
#define  NV_WCDMA_900_TX_SLP_VS_TEMP_1_I               ((nv_items_enum_type) 3687)
#define  NV_WCDMA_900_R1_RISE_I                        ((nv_items_enum_type) 3688)
#define  NV_WCDMA_900_R1_FALL_I                        ((nv_items_enum_type) 3689)
#define  NV_WCDMA_900_TX_LIM_VS_TEMP_I                 ((nv_items_enum_type) 3690)
#define  NV_WCDMA_900_TX_LIM_VS_FREQ_I                 ((nv_items_enum_type) 3691)
#define  NV_WCDMA_900_ADJ_FACTOR_I                     ((nv_items_enum_type) 3692)
#define  NV_WCDMA_900_EXP_HDET_VS_AGC_I                ((nv_items_enum_type) 3693)
#define  NV_WCDMA_900_HDET_OFF_I                       ((nv_items_enum_type) 3694)
#define  NV_WCDMA_900_HDET_SPN_I                       ((nv_items_enum_type) 3695)
#define  NV_WCDMA_900_ENC_BTF_I                        ((nv_items_enum_type) 3696)
#define  NV_WCDMA_900_AGC_PA_ON_RISE_DELAY_I           ((nv_items_enum_type) 3697)
#define  NV_WCDMA_900_AGC_PA_ON_FALL_DELAY_I           ((nv_items_enum_type) 3698)
#define  NV_WCDMA_900_AGC_TX_ON_RISE_DELAY_I           ((nv_items_enum_type) 3699)
#define  NV_WCDMA_900_AGC_TX_ON_FALL_DELAY_I           ((nv_items_enum_type) 3700)
#define  NV_WCDMA_900_AGC_UPDATE_TX_AGC_TIME_I         ((nv_items_enum_type) 3701)
#define  NV_WCDMA_900_PRACH_R1_RISE_OFFSET_I           ((nv_items_enum_type) 3702)
#define  NV_WCDMA_900_PRACH_R1_FALL_OFFSET_I           ((nv_items_enum_type) 3703)
#define  NV_WCDMA_900_TX_CAL_CHAN_I                    ((nv_items_enum_type) 3704)
#define  NV_WCDMA_900_RX_CAL_CHAN_I                    ((nv_items_enum_type) 3705)
#define  NV_WCDMA_900_TX_LIN_MASTER_2_I                ((nv_items_enum_type) 3706)
#define  NV_WCDMA_900_TX_LIN_MASTER_3_I                ((nv_items_enum_type) 3707)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_2_I              ((nv_items_enum_type) 3708)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_3_I              ((nv_items_enum_type) 3709)
#define  NV_WCDMA_900_TX_LIN_VS_TEMP_2_I               ((nv_items_enum_type) 3710)
#define  NV_WCDMA_900_TX_LIN_VS_TEMP_3_I               ((nv_items_enum_type) 3711)
#define  NV_WCDMA_900_TX_SLP_VS_TEMP_2_I               ((nv_items_enum_type) 3712)
#define  NV_WCDMA_900_TX_SLP_VS_TEMP_3_I               ((nv_items_enum_type) 3713)
#define  NV_WCDMA_900_R2_RISE_I                        ((nv_items_enum_type) 3714)
#define  NV_WCDMA_900_R2_FALL_I                        ((nv_items_enum_type) 3715)
#define  NV_WCDMA_900_R3_RISE_I                        ((nv_items_enum_type) 3716)
#define  NV_WCDMA_900_R3_FALL_I                        ((nv_items_enum_type) 3717)
#define  NV_WCDMA_900_PA_COMPENSATE_UP_R2_I            ((nv_items_enum_type) 3718)
#define  NV_WCDMA_900_PA_COMPENSATE_DOWN_R2_I          ((nv_items_enum_type) 3719)
#define  NV_WCDMA_900_PA_COMPENSATE_UP_R3_I            ((nv_items_enum_type) 3720)
#define  NV_WCDMA_900_PA_COMPENSATE_DOWN_R3_I          ((nv_items_enum_type) 3721)
#define  NV_WCDMA_900_TX_ROT_ANGLE_PA_STATE_00_I       ((nv_items_enum_type) 3722)
#define  NV_WCDMA_900_TX_ROT_ANGLE_PA_STATE_01_I       ((nv_items_enum_type) 3723)
#define  NV_WCDMA_900_TX_ROT_ANGLE_PA_STATE_10_I       ((nv_items_enum_type) 3724)
#define  NV_WCDMA_900_TX_ROT_ANGLE_PA_STATE_11_I       ((nv_items_enum_type) 3725)
#define  NV_WCDMA_900_PRACH_R2_RISE_OFFSET_I           ((nv_items_enum_type) 3726)
#define  NV_WCDMA_900_PRACH_R2_FALL_OFFSET_I           ((nv_items_enum_type) 3727)
#define  NV_WCDMA_900_PRACH_R3_RISE_OFFSET_I           ((nv_items_enum_type) 3728)
#define  NV_WCDMA_900_PRACH_R3_FALL_OFFSET_I           ((nv_items_enum_type) 3729)
#define  NV_WCDMA_900_PA_RANGE_MAP_I                   ((nv_items_enum_type) 3730)
#define  NV_WCDMA_900_DCH_AGC_UPDATE_TX_AGC_TIME_I     ((nv_items_enum_type) 3731)
#define  NV_WCDMA_900_AGC_TX_ADJ_PDM_DELAY_I           ((nv_items_enum_type) 3732)
#define  NV_WCDMA_900_UTRAN_TX_LIM_VS_TEMP_OFFSET_I    ((nv_items_enum_type) 3733)
#define  NV_WCDMA_900_PA_GAIN_UP_TIME_I                ((nv_items_enum_type) 3734)
#define  NV_WCDMA_900_PA_GAIN_DOWN_TIME_I              ((nv_items_enum_type) 3735)
#define  NV_WCDMA_900_PA_COMPENSATE_UP_I               ((nv_items_enum_type) 3736)
#define  NV_WCDMA_900_PA_COMPENSATE_DOWN_I             ((nv_items_enum_type) 3737)
#define  NV_WCDMA_900_RX_DELAY_I                       ((nv_items_enum_type) 3738)
#define  NV_WCDMA_900_PA_RANGE_FOR_DVS_I               ((nv_items_enum_type) 3739)
#define  NV_WCDMA_900_PA_COMPENSATE_UP_WITH_DVS_I      ((nv_items_enum_type) 3740)
#define  NV_WCDMA_900_PA_COMPENSATE_DN_WITH_DVS_I      ((nv_items_enum_type) 3741)
#define  NV_WCDMA_900_MAX_PWR_BACKOFF_VOLTAGES_I       ((nv_items_enum_type) 3742)
#define  NV_WCDMA_900_MAX_PWR_BACKOFF_VOLT1_I          ((nv_items_enum_type) 3743)
#define  NV_WCDMA_900_MAX_PWR_BACKOFF_VOLT2_I          ((nv_items_enum_type) 3744)
#define  NV_WCDMA_900_MAX_PWR_BACKOFF_VOLT3_I          ((nv_items_enum_type) 3745)
#define  NV_WCDMA_900_HS_R1_RISE_I                     ((nv_items_enum_type) 3746)
#define  NV_WCDMA_900_HS_R1_FALL_I                     ((nv_items_enum_type) 3747)
#define  NV_WCDMA_900_HS_R2_RISE_I                     ((nv_items_enum_type) 3748)
#define  NV_WCDMA_900_HS_R2_FALL_I                     ((nv_items_enum_type) 3749)
#define  NV_WCDMA_900_HS_R3_RISE_I                     ((nv_items_enum_type) 3750)
#define  NV_WCDMA_900_HS_R3_FALL_I                     ((nv_items_enum_type) 3751)
#define  NV_RFR_VCO_COARSE_TUNING_900_I                ((nv_items_enum_type) 3752)
#define  NV_NITZ_NW_INFO_I                             ((nv_items_enum_type) 3753)
#define  NV_CBS_MAX_MSGS_PER_TOPIC_I                   ((nv_items_enum_type) 3754)
#define  NV_CAMERA_TYPE_I                              ((nv_items_enum_type) 3755)
#define  NV_GPS1_DYNAMIC_MODE_I                        ((nv_items_enum_type) 3756)
#define  NV_DQOS_SUPPORTED_I                           ((nv_items_enum_type) 3757)
#define  NV_AAGPS_USE_TRANSPORT_SECURITY_I             ((nv_items_enum_type) 3758)
#define  NV_C1_WCDMA_2100_VGA_GAIN_OFFSET_I            ((nv_items_enum_type) 3759)
#define  NV_C1_WCDMA_2100_LNA_RANGE_RISE_I             ((nv_items_enum_type) 3760)
#define  NV_C1_WCDMA_2100_LNA_RANGE_FALL_I             ((nv_items_enum_type) 3761)
#define  NV_C1_WCDMA_2100_IM_LEVEL_I                   ((nv_items_enum_type) 3762)
#define  NV_C1_WCDMA_2100_NONBYPASS_TIMER_I            ((nv_items_enum_type) 3763)
#define  NV_C1_WCDMA_2100_BYPASS_TIMER_I               ((nv_items_enum_type) 3764)
#define  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_I           ((nv_items_enum_type) 3765)
#define  NV_C1_WCDMA_2100_LNA_OFFSET_VS_FREQ_I         ((nv_items_enum_type) 3766)
#define  NV_C1_WCDMA_2100_VGA_GAIN_OFFSET_VS_FREQ_I    ((nv_items_enum_type) 3767)
#define  NV_C1_WCDMA_2100_VGA_GAIN_OFFSET_VS_TEMP_I    ((nv_items_enum_type) 3768)
#define  NV_C1_WCDMA_2100_LNA_RANGE_RISE_2_I           ((nv_items_enum_type) 3769)
#define  NV_C1_WCDMA_2100_LNA_RANGE_RISE_3_I           ((nv_items_enum_type) 3770)
#define  NV_C1_WCDMA_2100_LNA_RANGE_RISE_4_I           ((nv_items_enum_type) 3771)
#define  NV_C1_WCDMA_2100_LNA_RANGE_FALL_2_I           ((nv_items_enum_type) 3772)
#define  NV_C1_WCDMA_2100_LNA_RANGE_FALL_3_I           ((nv_items_enum_type) 3773)
#define  NV_C1_WCDMA_2100_LNA_RANGE_FALL_4_I           ((nv_items_enum_type) 3774)
#define  NV_C1_WCDMA_2100_IM_LEVEL_2_I                 ((nv_items_enum_type) 3775)
#define  NV_C1_WCDMA_2100_IM_LEVEL_3_I                 ((nv_items_enum_type) 3776)
#define  NV_C1_WCDMA_2100_IM_LEVEL_4_I                 ((nv_items_enum_type) 3777)
#define  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_2_I         ((nv_items_enum_type) 3778)
#define  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_3_I         ((nv_items_enum_type) 3779)
#define  NV_C1_WCDMA_2100_LNA_RANGE_OFFSET_4_I         ((nv_items_enum_type) 3780)
#define  NV_C1_WCDMA_2100_LNA_OFFSET_VS_FREQ_2_I       ((nv_items_enum_type) 3781)
#define  NV_C1_WCDMA_2100_LNA_OFFSET_VS_FREQ_3_I       ((nv_items_enum_type) 3782)
#define  NV_C1_WCDMA_2100_LNA_OFFSET_VS_FREQ_4_I       ((nv_items_enum_type) 3783)
#define  NV_C1_WCDMA_2100_IM2_I_VALUE_I                ((nv_items_enum_type) 3784)
#define  NV_C1_WCDMA_2100_IM2_Q_VALUE_I                ((nv_items_enum_type) 3785)
#define  NV_C1_WCDMA_2100_IM2_TRANSCONDUCTOR_VALUE_I   ((nv_items_enum_type) 3786)
#define  NV_C1_WCDMA_2100_RX_CAL_CHAN_I                ((nv_items_enum_type) 3787)
#define  NV_C1_RF_ANTSEL_UMTS_2100_I                   ((nv_items_enum_type) 3788)
#define  NV_C1_WCDMA_1900_VGA_GAIN_OFFSET_I            ((nv_items_enum_type) 3789)
#define  NV_C1_WCDMA_1900_VGA_GAIN_OFFSET_VS_FREQ_I    ((nv_items_enum_type) 3790)
#define  NV_C1_WCDMA_1900_VGA_GAIN_OFFSET_VS_TEMP_I    ((nv_items_enum_type) 3791)
#define  NV_C1_WCDMA_1900_LNA_RANGE_RISE_I             ((nv_items_enum_type) 3792)
#define  NV_C1_WCDMA_1900_LNA_RANGE_RISE_2_I           ((nv_items_enum_type) 3793)
#define  NV_C1_WCDMA_1900_LNA_RANGE_RISE_3_I           ((nv_items_enum_type) 3794)
#define  NV_C1_WCDMA_1900_LNA_RANGE_RISE_4_I           ((nv_items_enum_type) 3795)
#define  NV_C1_WCDMA_1900_LNA_RANGE_FALL_I             ((nv_items_enum_type) 3796)
#define  NV_C1_WCDMA_1900_LNA_RANGE_FALL_2_I           ((nv_items_enum_type) 3797)
#define  NV_C1_WCDMA_1900_LNA_RANGE_FALL_3_I           ((nv_items_enum_type) 3798)
#define  NV_C1_WCDMA_1900_LNA_RANGE_FALL_4_I           ((nv_items_enum_type) 3799)
#define  NV_C1_WCDMA_1900_IM_LEVEL_I                   ((nv_items_enum_type) 3800)
#define  NV_C1_WCDMA_1900_IM_LEVEL_2_I                 ((nv_items_enum_type) 3801)
#define  NV_C1_WCDMA_1900_IM_LEVEL_3_I                 ((nv_items_enum_type) 3802)
#define  NV_C1_WCDMA_1900_IM_LEVEL_4_I                 ((nv_items_enum_type) 3803)
#define  NV_C1_WCDMA_1900_LNA_RANGE_OFFSET_2_I         ((nv_items_enum_type) 3804)
#define  NV_C1_WCDMA_1900_LNA_RANGE_OFFSET_3_I         ((nv_items_enum_type) 3805)
#define  NV_C1_WCDMA_1900_LNA_RANGE_OFFSET_4_I         ((nv_items_enum_type) 3806)
#define  NV_C1_WCDMA_1900_LNA_OFFSET_VS_FREQ_2_I       ((nv_items_enum_type) 3807)
#define  NV_C1_WCDMA_1900_LNA_OFFSET_VS_FREQ_3_I       ((nv_items_enum_type) 3808)
#define  NV_C1_WCDMA_1900_LNA_OFFSET_VS_FREQ_4_I       ((nv_items_enum_type) 3809)
#define  NV_C1_WCDMA_1900_IM2_I_VALUE_I                ((nv_items_enum_type) 3810)
#define  NV_C1_WCDMA_1900_IM2_Q_VALUE_I                ((nv_items_enum_type) 3811)
#define  NV_C1_WCDMA_1900_IM2_TRANSCONDUCTOR_VALUE_I   ((nv_items_enum_type) 3812)
#define  NV_C1_WCDMA_1900_NONBYPASS_TIMER_I            ((nv_items_enum_type) 3813)
#define  NV_C1_WCDMA_1900_BYPASS_TIMER_I               ((nv_items_enum_type) 3814)
#define  NV_C1_WCDMA_1900_LNA_RANGE_OFFSET_I           ((nv_items_enum_type) 3815)
#define  NV_C1_WCDMA_1900_LNA_OFFSET_VS_FREQ_I         ((nv_items_enum_type) 3816)
#define  NV_C1_WCDMA_1900_RX_CAL_CHAN_I                ((nv_items_enum_type) 3817)
#define  NV_C1_RF_ANTSEL_UMTS_1900_I                   ((nv_items_enum_type) 3818)
#define  NV_C1_WCDMA_800_VGA_GAIN_OFFSET_I             ((nv_items_enum_type) 3819)
#define  NV_C1_WCDMA_800_VGA_GAIN_OFFSET_VS_FREQ_I     ((nv_items_enum_type) 3820)
#define  NV_C1_WCDMA_800_VGA_GAIN_OFFSET_VS_TEMP_I     ((nv_items_enum_type) 3821)
#define  NV_C1_WCDMA_800_LNA_RANGE_RISE_I              ((nv_items_enum_type) 3822)
#define  NV_C1_WCDMA_800_LNA_RANGE_RISE_2_I            ((nv_items_enum_type) 3823)
#define  NV_C1_WCDMA_800_LNA_RANGE_RISE_3_I            ((nv_items_enum_type) 3824)
#define  NV_C1_WCDMA_800_LNA_RANGE_RISE_4_I            ((nv_items_enum_type) 3825)
#define  NV_C1_WCDMA_800_LNA_RANGE_FALL_I              ((nv_items_enum_type) 3826)
#define  NV_C1_WCDMA_800_LNA_RANGE_FALL_2_I            ((nv_items_enum_type) 3827)
#define  NV_C1_WCDMA_800_LNA_RANGE_FALL_3_I            ((nv_items_enum_type) 3828)
#define  NV_C1_WCDMA_800_LNA_RANGE_FALL_4_I            ((nv_items_enum_type) 3829)
#define  NV_C1_WCDMA_800_IM_LEVEL_I                    ((nv_items_enum_type) 3830)
#define  NV_C1_WCDMA_800_IM_LEVEL_2_I                  ((nv_items_enum_type) 3831)
#define  NV_C1_WCDMA_800_IM_LEVEL_3_I                  ((nv_items_enum_type) 3832)
#define  NV_C1_WCDMA_800_IM_LEVEL_4_I                  ((nv_items_enum_type) 3833)
#define  NV_C1_WCDMA_800_LNA_RANGE_OFFSET_I            ((nv_items_enum_type) 3834)
#define  NV_C1_WCDMA_800_LNA_RANGE_OFFSET_2_I          ((nv_items_enum_type) 3835)
#define  NV_C1_WCDMA_800_LNA_RANGE_OFFSET_3_I          ((nv_items_enum_type) 3836)
#define  NV_C1_WCDMA_800_LNA_RANGE_OFFSET_4_I          ((nv_items_enum_type) 3837)
#define  NV_C1_WCDMA_800_LNA_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 3838)
#define  NV_C1_WCDMA_800_LNA_OFFSET_VS_FREQ_2_I        ((nv_items_enum_type) 3839)
#define  NV_C1_WCDMA_800_LNA_OFFSET_VS_FREQ_3_I        ((nv_items_enum_type) 3840)
#define  NV_C1_WCDMA_800_LNA_OFFSET_VS_FREQ_4_I        ((nv_items_enum_type) 3841)
#define  NV_C1_WCDMA_800_IM2_I_VALUE_I                 ((nv_items_enum_type) 3842)
#define  NV_C1_WCDMA_800_IM2_Q_VALUE_I                 ((nv_items_enum_type) 3843)
#define  NV_C1_WCDMA_800_IM2_TRANSCONDUCTOR_VALUE_I    ((nv_items_enum_type) 3844)
#define  NV_C1_WCDMA_800_NONBYPASS_TIMER_I             ((nv_items_enum_type) 3845)
#define  NV_C1_WCDMA_800_BYPASS_TIMER_I                ((nv_items_enum_type) 3846)
#define  NV_C1_WCDMA_800_RX_CAL_CHAN_I                 ((nv_items_enum_type) 3847)
#define  NV_C1_RF_ANTSEL_UMTS_800_I                    ((nv_items_enum_type) 3848)
#define  NV_RFR_VCO_COARSE_TUNE_2_1900_I               ((nv_items_enum_type) 3849)
#define  NV_RFR_WCDMA_C0_C1_DELAY_I                    ((nv_items_enum_type) 3850)
#define  NV_WCDMA_RX_DIVERSITY_CTRL_I                  ((nv_items_enum_type) 3851)
#define  NV_WCDMA_EQUALIZER_CTRL_I                     ((nv_items_enum_type) 3852)
#define  NV_BC11_GPS1_RF_DELAY_I                       ((nv_items_enum_type) 3853)
#define  NV_BC11_TX_LIM_VS_TEMP_I                      ((nv_items_enum_type) 3854)
#define  NV_BC11_TX_LIN_MASTER0_I                      ((nv_items_enum_type) 3855)
#define  NV_BC11_TX_LIN_MASTER1_I                      ((nv_items_enum_type) 3856)
#define  NV_BC11_TX_LIN_MASTER2_I                      ((nv_items_enum_type) 3857)
#define  NV_BC11_TX_LIN_MASTER3_I                      ((nv_items_enum_type) 3858)
#define  NV_BC11_TX_COMP0_I                            ((nv_items_enum_type) 3859)
#define  NV_BC11_TX_COMP1_I                            ((nv_items_enum_type) 3860)
#define  NV_BC11_TX_COMP2_I                            ((nv_items_enum_type) 3861)
#define  NV_BC11_TX_COMP3_I                            ((nv_items_enum_type) 3862)
#define  NV_BC11_TX_LIM_VS_FREQ_I                      ((nv_items_enum_type) 3863)
#define  NV_BC11_PA_R1_RISE_I                          ((nv_items_enum_type) 3864)
#define  NV_BC11_PA_R1_FALL_I                          ((nv_items_enum_type) 3865)
#define  NV_BC11_PA_R2_RISE_I                          ((nv_items_enum_type) 3866)
#define  NV_BC11_PA_R2_FALL_I                          ((nv_items_enum_type) 3867)
#define  NV_BC11_PA_R3_RISE_I                          ((nv_items_enum_type) 3868)
#define  NV_BC11_PA_R3_FALL_I                          ((nv_items_enum_type) 3869)
#define  NV_BC11_HDET_OFF_I                            ((nv_items_enum_type) 3870)
#define  NV_BC11_HDET_SPN_I                            ((nv_items_enum_type) 3871)
#define  NV_BC11_EXP_HDET_VS_AGC_I                     ((nv_items_enum_type) 3872)
#define  NV_BC11_ENC_BTF_I                             ((nv_items_enum_type) 3873)
#define  NV_BC11_VCO_COARSE_TUNE_TABLE_I               ((nv_items_enum_type) 3874)
#define  NV_BC11_P1_RISE_FALL_OFF_I                    ((nv_items_enum_type) 3875)
#define  NV_C0_BC11_TX_CAL_CHAN_I                      ((nv_items_enum_type) 3876)
#define  NV_C0_BC11_RX_CAL_CHAN_I                      ((nv_items_enum_type) 3877)
#define  NV_C0_BC11_LNA_1_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3878)
#define  NV_C0_BC11_LNA_2_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3879)
#define  NV_C0_BC11_LNA_3_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3880)
#define  NV_C0_BC11_LNA_4_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3881)
#define  NV_C0_BC11_LNA_1_OFFSET_I                     ((nv_items_enum_type) 3882)
#define  NV_C0_BC11_LNA_2_OFFSET_I                     ((nv_items_enum_type) 3883)
#define  NV_C0_BC11_LNA_3_OFFSET_I                     ((nv_items_enum_type) 3884)
#define  NV_C0_BC11_LNA_4_OFFSET_I                     ((nv_items_enum_type) 3885)
#define  NV_C0_BC11_IM2_I_VALUE_I                      ((nv_items_enum_type) 3886)
#define  NV_C0_BC11_IM2_Q_VALUE_I                      ((nv_items_enum_type) 3887)
#define  NV_C0_BC11_VGA_GAIN_OFFSET_I                  ((nv_items_enum_type) 3888)
#define  NV_C0_BC11_VGA_GAIN_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 3889)
#define  NV_C0_BC11_IM2_TRANSCONDUCTOR_VALUE_I         ((nv_items_enum_type) 3890)
#define  NV_C0_BC11_LNA_1_RISE_I                       ((nv_items_enum_type) 3891)
#define  NV_C0_BC11_LNA_1_FALL_I                       ((nv_items_enum_type) 3892)
#define  NV_C0_BC11_LNA_2_RISE_I                       ((nv_items_enum_type) 3893)
#define  NV_C0_BC11_LNA_2_FALL_I                       ((nv_items_enum_type) 3894)
#define  NV_C0_BC11_LNA_3_RISE_I                       ((nv_items_enum_type) 3895)
#define  NV_C0_BC11_LNA_3_FALL_I                       ((nv_items_enum_type) 3896)
#define  NV_C0_BC11_LNA_4_RISE_I                       ((nv_items_enum_type) 3897)
#define  NV_C0_BC11_LNA_4_FALL_I                       ((nv_items_enum_type) 3898)
#define  NV_C0_BC11_IM_LEVEL1_I                        ((nv_items_enum_type) 3899)
#define  NV_C0_BC11_IM_LEVEL2_I                        ((nv_items_enum_type) 3900)
#define  NV_C0_BC11_IM_LEVEL3_I                        ((nv_items_enum_type) 3901)
#define  NV_C0_BC11_IM_LEVEL4_I                        ((nv_items_enum_type) 3902)
#define  NV_C1_BC11_TX_CAL_CHAN_I                      ((nv_items_enum_type) 3903)
#define  NV_C1_BC11_RX_CAL_CHAN_I                      ((nv_items_enum_type) 3904)
#define  NV_C1_BC11_LNA_1_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3905)
#define  NV_C1_BC11_LNA_2_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3906)
#define  NV_C1_BC11_LNA_3_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3907)
#define  NV_C1_BC11_LNA_4_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 3908)
#define  NV_C1_BC11_LNA_1_OFFSET_I                     ((nv_items_enum_type) 3909)
#define  NV_C1_BC11_LNA_2_OFFSET_I                     ((nv_items_enum_type) 3910)
#define  NV_C1_BC11_LNA_3_OFFSET_I                     ((nv_items_enum_type) 3911)
#define  NV_C1_BC11_LNA_4_OFFSET_I                     ((nv_items_enum_type) 3912)
#define  NV_C1_BC11_IM2_I_VALUE_I                      ((nv_items_enum_type) 3913)
#define  NV_C1_BC11_IM2_Q_VALUE_I                      ((nv_items_enum_type) 3914)
#define  NV_C1_BC11_VGA_GAIN_OFFSET_I                  ((nv_items_enum_type) 3915)
#define  NV_C1_BC11_VGA_GAIN_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 3916)
#define  NV_C1_BC11_IM2_TRANSCONDUCTOR_VALUE_I         ((nv_items_enum_type) 3917)
#define  NV_C1_BC11_LNA_1_RISE_I                       ((nv_items_enum_type) 3918)
#define  NV_C1_BC11_LNA_1_FALL_I                       ((nv_items_enum_type) 3919)
#define  NV_C1_BC11_LNA_2_RISE_I                       ((nv_items_enum_type) 3920)
#define  NV_C1_BC11_LNA_2_FALL_I                       ((nv_items_enum_type) 3921)
#define  NV_C1_BC11_LNA_3_RISE_I                       ((nv_items_enum_type) 3922)
#define  NV_C1_BC11_LNA_3_FALL_I                       ((nv_items_enum_type) 3923)
#define  NV_C1_BC11_LNA_4_RISE_I                       ((nv_items_enum_type) 3924)
#define  NV_C1_BC11_LNA_4_FALL_I                       ((nv_items_enum_type) 3925)
#define  NV_C1_BC11_IM_LEVEL1_I                        ((nv_items_enum_type) 3926)
#define  NV_C1_BC11_IM_LEVEL2_I                        ((nv_items_enum_type) 3927)
#define  NV_C1_BC11_IM_LEVEL3_I                        ((nv_items_enum_type) 3928)
#define  NV_C1_BC11_IM_LEVEL4_I                        ((nv_items_enum_type) 3929)
#define  NV_BC11_VCO_TUNE_2_I                          ((nv_items_enum_type) 3930)
#define  NV_BC11_HDR_P1_RISE_FALL_OFF_I                ((nv_items_enum_type) 3931)
#define  NV_C0_BC11_RX_CAL_CHAN_LRU_I                  ((nv_items_enum_type) 3932)
#define  NV_C1_BC11_RX_CAL_CHAN_LRU_I                  ((nv_items_enum_type) 3933)
#define  NV_BC11_ANT_QUALITY_I                         ((nv_items_enum_type) 3934)
#define  NV_C0_BC11_IM2_LPM_1_I                        ((nv_items_enum_type) 3935)
#define  NV_C0_BC11_IM2_LPM_2_I                        ((nv_items_enum_type) 3936)
#define  NV_C0_BC11_INTELLICEIVER_CAL_I                ((nv_items_enum_type) 3937)
#define  NV_C0_BC11_LNA_SWITCHPOINTS_LPM_1_I           ((nv_items_enum_type) 3938)
#define  NV_C0_BC11_LNA_SWITCHPOINTS_LPM_2_I           ((nv_items_enum_type) 3939)
#define  NV_C0_BC11_INTELLICEIVER_DET_THRESH_I         ((nv_items_enum_type) 3940)
#define  NV_BC11_PA_DVS_VOLTAGE_I                      ((nv_items_enum_type) 3941)
#define  NV_C1_BC11_VCO_COARSE_TUNE_TABLE_I            ((nv_items_enum_type) 3942)
#define  NV_VOIP_WLAN_PRFRD_CODEC_I                    ((nv_items_enum_type) 3943)
#define  NV_VOIP_EVDO_PRFRD_CODEC_I                    ((nv_items_enum_type) 3944)
#define  NV_WCDMA_PA_COMP_UP_VS_FREQ_I                 ((nv_items_enum_type) 3945)
#define  NV_WCDMA_PA_COMP_DOWN_VS_FREQ_I               ((nv_items_enum_type) 3946)
#define  NV_WCDMA_PA_COMP_UP_R2_VS_FREQ_I              ((nv_items_enum_type) 3947)
#define  NV_WCDMA_PA_COMP_DOWN_R2_VS_FREQ_I            ((nv_items_enum_type) 3948)
#define  NV_WCDMA_PA_COMP_UP_R3_VS_FREQ_I              ((nv_items_enum_type) 3949)
#define  NV_WCDMA_PA_COMP_DOWN_R3_VS_FREQ_I            ((nv_items_enum_type) 3950)
#define  NV_WCDMA_800_PA_COMP_UP_VS_FREQ_I             ((nv_items_enum_type) 3951)
#define  NV_WCDMA_800_PA_COMP_DOWN_VS_FREQ_I           ((nv_items_enum_type) 3952)
#define  NV_WCDMA_800_PA_COMP_UP_R2_VS_FREQ_I          ((nv_items_enum_type) 3953)
#define  NV_WCDMA_800_PA_COMP_DOWN_R2_VS_FREQ_I        ((nv_items_enum_type) 3954)
#define  NV_WCDMA_800_PA_COMP_UP_R3_VS_FREQ_I          ((nv_items_enum_type) 3955)
#define  NV_WCDMA_800_PA_COMP_DOWN_R3_VS_FREQ_I        ((nv_items_enum_type) 3956)
#define  NV_WCDMA_1900_PA_COMP_UP_VS_FREQ_I            ((nv_items_enum_type) 3957)
#define  NV_WCDMA_1900_PA_COMP_DOWN_VS_FREQ_I          ((nv_items_enum_type) 3958)
#define  NV_WCDMA_1900_PA_COMP_UP_R2_VS_FREQ_I         ((nv_items_enum_type) 3959)
#define  NV_WCDMA_1900_PA_COMP_DOWN_R2_VS_FREQ_I       ((nv_items_enum_type) 3960)
#define  NV_WCDMA_1900_PA_COMP_UP_R3_VS_FREQ_I         ((nv_items_enum_type) 3961)
#define  NV_WCDMA_1900_PA_COMP_DOWN_R3_VS_FREQ_I       ((nv_items_enum_type) 3962)
#define  NV_WCDMA_900_PA_COMP_UP_VS_FREQ_I             ((nv_items_enum_type) 3963)
#define  NV_WCDMA_900_PA_COMP_DOWN_VS_FREQ_I           ((nv_items_enum_type) 3964)
#define  NV_WCDMA_900_PA_COMP_UP_R2_VS_FREQ_I          ((nv_items_enum_type) 3965)
#define  NV_WCDMA_900_PA_COMP_DOWN_R2_VS_FREQ_I        ((nv_items_enum_type) 3966)
#define  NV_WCDMA_900_PA_COMP_UP_R3_VS_FREQ_I          ((nv_items_enum_type) 3967)
#define  NV_WCDMA_900_PA_COMP_DOWN_R3_VS_FREQ_I        ((nv_items_enum_type) 3968)
#define  NV_WCDMA_TX_PDM_LIN_0_I                       ((nv_items_enum_type) 3969)
#define  NV_WCDMA_TX_PDM_LIN_1_I                       ((nv_items_enum_type) 3970)
#define  NV_WCDMA_TX_PDM_LIN_2_I                       ((nv_items_enum_type) 3971)
#define  NV_WCDMA_TX_PDM_LIN_3_I                       ((nv_items_enum_type) 3972)
#define  NV_WCDMA_800_TX_PDM_LIN_0_I                   ((nv_items_enum_type) 3973)
#define  NV_WCDMA_800_TX_PDM_LIN_1_I                   ((nv_items_enum_type) 3974)
#define  NV_WCDMA_800_TX_PDM_LIN_2_I                   ((nv_items_enum_type) 3975)
#define  NV_WCDMA_800_TX_PDM_LIN_3_I                   ((nv_items_enum_type) 3976)
#define  NV_WCDMA_1900_TX_PDM_LIN_0_I                  ((nv_items_enum_type) 3977)
#define  NV_WCDMA_1900_TX_PDM_LIN_1_I                  ((nv_items_enum_type) 3978)
#define  NV_WCDMA_1900_TX_PDM_LIN_2_I                  ((nv_items_enum_type) 3979)
#define  NV_WCDMA_1900_TX_PDM_LIN_3_I                  ((nv_items_enum_type) 3980)
#define  NV_WCDMA_900_TX_PDM_LIN_0_I                   ((nv_items_enum_type) 3981)
#define  NV_WCDMA_900_TX_PDM_LIN_1_I                   ((nv_items_enum_type) 3982)
#define  NV_WCDMA_900_TX_PDM_LIN_2_I                   ((nv_items_enum_type) 3983)
#define  NV_WCDMA_900_TX_PDM_LIN_3_I                   ((nv_items_enum_type) 3984)
#define  NV_WCDMA_1800_PA_COMP_UP_VS_FREQ_I            ((nv_items_enum_type) 3985)
#define  NV_WCDMA_1800_PA_COMP_DOWN_VS_FREQ_I          ((nv_items_enum_type) 3986)
#define  NV_WCDMA_1800_PA_COMP_UP_R2_VS_FREQ_I         ((nv_items_enum_type) 3987)
#define  NV_WCDMA_1800_PA_COMP_DOWN_R2_VS_FREQ_I       ((nv_items_enum_type) 3988)
#define  NV_WCDMA_1800_PA_COMP_UP_R3_VS_FREQ_I         ((nv_items_enum_type) 3989)
#define  NV_WCDMA_1800_PA_COMP_DOWN_R3_VS_FREQ_I       ((nv_items_enum_type) 3990)
#define  NV_WCDMA_1800_TX_PDM_LIN_0_I                  ((nv_items_enum_type) 3991)
#define  NV_WCDMA_1800_TX_PDM_LIN_1_I                  ((nv_items_enum_type) 3992)
#define  NV_WCDMA_1800_TX_PDM_LIN_2_I                  ((nv_items_enum_type) 3993)
#define  NV_WCDMA_1800_TX_PDM_LIN_3_I                  ((nv_items_enum_type) 3994)
#define  NV_WCDMA_BC4_VGA_GAIN_OFFSET_I                ((nv_items_enum_type) 3995)
#define  NV_WCDMA_BC4_VGA_GAIN_OFFSET_VS_FREQ_I        ((nv_items_enum_type) 3996)
#define  NV_WCDMA_BC4_VGA_GAIN_OFFSET_VS_TEMP_I        ((nv_items_enum_type) 3997)
#define  NV_WCDMA_BC4_LNA_RANGE_RISE_2_I               ((nv_items_enum_type) 3998)
#define  NV_WCDMA_BC4_LNA_RANGE_RISE_3_I               ((nv_items_enum_type) 3999)
#define  NV_WCDMA_BC4_LNA_RANGE_FALL_2_I               ((nv_items_enum_type) 4000)
#define  NV_WCDMA_BC4_LNA_RANGE_FALL_3_I               ((nv_items_enum_type) 4001)
#define  NV_WCDMA_BC4_IM_LEVEL_2_I                     ((nv_items_enum_type) 4002)
#define  NV_WCDMA_BC4_IM_LEVEL_3_I                     ((nv_items_enum_type) 4003)
#define  NV_WCDMA_BC4_LNA_RANGE_OFFSET_2_I             ((nv_items_enum_type) 4004)
#define  NV_WCDMA_BC4_LNA_RANGE_OFFSET_3_I             ((nv_items_enum_type) 4005)
#define  NV_WCDMA_BC4_LNA_OFFSET_VS_FREQ_2_I           ((nv_items_enum_type) 4006)
#define  NV_WCDMA_BC4_LNA_OFFSET_VS_FREQ_3_I           ((nv_items_enum_type) 4007)
#define  NV_WCDMA_BC4_IM2_I_VALUE_I                    ((nv_items_enum_type) 4008)
#define  NV_WCDMA_BC4_IM2_Q_VALUE_I                    ((nv_items_enum_type) 4009)
#define  NV_WCDMA_BC4_IM2_TRANSCONDUCTOR_VALUE_I       ((nv_items_enum_type) 4010)
#define  NV_WCDMA_BC4_RX_AGC_MIN_2_I                   ((nv_items_enum_type) 4011)
#define  NV_WCDMA_BC4_RX_AGC_MIN_3_I                   ((nv_items_enum_type) 4012)
#define  NV_WCDMA_BC4_MAX_TX_POWER_I                   ((nv_items_enum_type) 4013)
#define  NV_WCDMA_BC4_OUT_OF_SERVICE_THRESH_I          ((nv_items_enum_type) 4014)
#define  NV_WCDMA_BC4_LNA_RANGE_RISE_I                 ((nv_items_enum_type) 4015)
#define  NV_WCDMA_BC4_LNA_RANGE_FALL_I                 ((nv_items_enum_type) 4016)
#define  NV_WCDMA_BC4_IM_LEVEL_I                       ((nv_items_enum_type) 4017)
#define  NV_WCDMA_BC4_NONBYPASS_TIMER_I                ((nv_items_enum_type) 4018)
#define  NV_WCDMA_BC4_BYPASS_TIMER_I                   ((nv_items_enum_type) 4019)
#define  NV_WCDMA_BC4_LNA_RANGE_OFFSET_I               ((nv_items_enum_type) 4020)
#define  NV_WCDMA_BC4_LNA_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4021)
#define  NV_WCDMA_BC4_RX_AGC_MIN_I                     ((nv_items_enum_type) 4022)
#define  NV_WCDMA_BC4_RX_AGC_MAX_I                     ((nv_items_enum_type) 4023)
#define  NV_WCDMA_BC4_AGC_PHASE_OFFSET_I               ((nv_items_enum_type) 4024)
#define  NV_WCDMA_BC4_TX_LIN_MASTER_0_I                ((nv_items_enum_type) 4025)
#define  NV_WCDMA_BC4_TX_LIN_MASTER_1_I                ((nv_items_enum_type) 4026)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_0_I              ((nv_items_enum_type) 4027)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_1_I              ((nv_items_enum_type) 4028)
#define  NV_WCDMA_BC4_TX_LIN_VS_TEMP_0_I               ((nv_items_enum_type) 4029)
#define  NV_WCDMA_BC4_TX_LIN_VS_TEMP_1_I               ((nv_items_enum_type) 4030)
#define  NV_WCDMA_BC4_TX_SLP_VS_TEMP_0_I               ((nv_items_enum_type) 4031)
#define  NV_WCDMA_BC4_TX_SLP_VS_TEMP_1_I               ((nv_items_enum_type) 4032)
#define  NV_WCDMA_BC4_R1_RISE_I                        ((nv_items_enum_type) 4033)
#define  NV_WCDMA_BC4_R1_FALL_I                        ((nv_items_enum_type) 4034)
#define  NV_WCDMA_BC4_TX_LIM_VS_TEMP_I                 ((nv_items_enum_type) 4035)
#define  NV_WCDMA_BC4_TX_LIM_VS_FREQ_I                 ((nv_items_enum_type) 4036)
#define  NV_WCDMA_BC4_ADJ_FACTOR_I                     ((nv_items_enum_type) 4037)
#define  NV_WCDMA_BC4_EXP_HDET_VS_AGC_I                ((nv_items_enum_type) 4038)
#define  NV_WCDMA_BC4_HDET_OFF_I                       ((nv_items_enum_type) 4039)
#define  NV_WCDMA_BC4_HDET_SPN_I                       ((nv_items_enum_type) 4040)
#define  NV_WCDMA_BC4_ENC_BTF_I                        ((nv_items_enum_type) 4041)
#define  NV_WCDMA_BC4_AGC_PA_ON_RISE_DELAY_I           ((nv_items_enum_type) 4042)
#define  NV_WCDMA_BC4_AGC_PA_ON_FALL_DELAY_I           ((nv_items_enum_type) 4043)
#define  NV_WCDMA_BC4_AGC_TX_ON_RISE_DELAY_I           ((nv_items_enum_type) 4044)
#define  NV_WCDMA_BC4_AGC_TX_ON_FALL_DELAY_I           ((nv_items_enum_type) 4045)
#define  NV_WCDMA_BC4_AGC_UPDATE_TX_AGC_TIME_I         ((nv_items_enum_type) 4046)
#define  NV_WCDMA_BC4_PRACH_R1_RISE_OFFSET_I           ((nv_items_enum_type) 4047)
#define  NV_WCDMA_BC4_PRACH_R1_FALL_OFFSET_I           ((nv_items_enum_type) 4048)
#define  NV_WCDMA_BC4_TX_CAL_CHAN_I                    ((nv_items_enum_type) 4049)
#define  NV_WCDMA_BC4_RX_CAL_CHAN_I                    ((nv_items_enum_type) 4050)
#define  NV_WCDMA_BC4_TX_LIN_MASTER_2_I                ((nv_items_enum_type) 4051)
#define  NV_WCDMA_BC4_TX_LIN_MASTER_3_I                ((nv_items_enum_type) 4052)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_2_I              ((nv_items_enum_type) 4053)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_3_I              ((nv_items_enum_type) 4054)
#define  NV_WCDMA_BC4_TX_LIN_VS_TEMP_2_I               ((nv_items_enum_type) 4055)
#define  NV_WCDMA_BC4_TX_LIN_VS_TEMP_3_I               ((nv_items_enum_type) 4056)
#define  NV_WCDMA_BC4_TX_SLP_VS_TEMP_2_I               ((nv_items_enum_type) 4057)
#define  NV_WCDMA_BC4_TX_SLP_VS_TEMP_3_I               ((nv_items_enum_type) 4058)
#define  NV_WCDMA_BC4_R2_RISE_I                        ((nv_items_enum_type) 4059)
#define  NV_WCDMA_BC4_R2_FALL_I                        ((nv_items_enum_type) 4060)
#define  NV_WCDMA_BC4_R3_RISE_I                        ((nv_items_enum_type) 4061)
#define  NV_WCDMA_BC4_R3_FALL_I                        ((nv_items_enum_type) 4062)
#define  NV_WCDMA_BC4_PA_COMPENSATE_UP_R2_I            ((nv_items_enum_type) 4063)
#define  NV_WCDMA_BC4_PA_COMPENSATE_DOWN_R2_I          ((nv_items_enum_type) 4064)
#define  NV_WCDMA_BC4_PA_COMPENSATE_UP_R3_I            ((nv_items_enum_type) 4065)
#define  NV_WCDMA_BC4_PA_COMPENSATE_DOWN_R3_I          ((nv_items_enum_type) 4066)
#define  NV_WCDMA_BC4_TX_ROT_ANGLE_PA_STATE_00_I       ((nv_items_enum_type) 4067)
#define  NV_WCDMA_BC4_TX_ROT_ANGLE_PA_STATE_01_I       ((nv_items_enum_type) 4068)
#define  NV_WCDMA_BC4_TX_ROT_ANGLE_PA_STATE_10_I       ((nv_items_enum_type) 4069)
#define  NV_WCDMA_BC4_TX_ROT_ANGLE_PA_STATE_11_I       ((nv_items_enum_type) 4070)
#define  NV_WCDMA_BC4_PRACH_R2_RISE_OFFSET_I           ((nv_items_enum_type) 4071)
#define  NV_WCDMA_BC4_PRACH_R2_FALL_OFFSET_I           ((nv_items_enum_type) 4072)
#define  NV_WCDMA_BC4_PRACH_R3_RISE_OFFSET_I           ((nv_items_enum_type) 4073)
#define  NV_WCDMA_BC4_PRACH_R3_FALL_OFFSET_I           ((nv_items_enum_type) 4074)
#define  NV_WCDMA_BC4_PA_RANGE_MAP_I                   ((nv_items_enum_type) 4075)
#define  NV_WCDMA_BC4_DCH_AGC_UPDATE_TX_AGC_TIME_I     ((nv_items_enum_type) 4076)
#define  NV_WCDMA_BC4_AGC_TX_ADJ_PDM_DELAY_I           ((nv_items_enum_type) 4077)
#define  NV_WCDMA_BC4_UTRAN_TX_LIM_VS_TEMP_OFFSET_I    ((nv_items_enum_type) 4078)
#define  NV_WCDMA_BC4_PA_GAIN_UP_TIME_I                ((nv_items_enum_type) 4079)
#define  NV_WCDMA_BC4_PA_GAIN_DOWN_TIME_I              ((nv_items_enum_type) 4080)
#define  NV_WCDMA_BC4_PA_COMPENSATE_UP_I               ((nv_items_enum_type) 4081)
#define  NV_WCDMA_BC4_PA_COMPENSATE_DOWN_I             ((nv_items_enum_type) 4082)
#define  NV_WCDMA_BC4_RX_DELAY_I                       ((nv_items_enum_type) 4083)
#define  NV_WCDMA_BC4_PA_RANGE_FOR_DVS_I               ((nv_items_enum_type) 4084)
#define  NV_WCDMA_BC4_PA_COMPENSATE_UP_WITH_DVS_I      ((nv_items_enum_type) 4085)
#define  NV_WCDMA_BC4_PA_COMPENSATE_DN_WITH_DVS_I      ((nv_items_enum_type) 4086)
#define  NV_WCDMA_BC4_MAX_PWR_BACKOFF_VOLTAGES_I       ((nv_items_enum_type) 4087)
#define  NV_WCDMA_BC4_MAX_PWR_BACKOFF_VOLT1_I          ((nv_items_enum_type) 4088)
#define  NV_WCDMA_BC4_MAX_PWR_BACKOFF_VOLT2_I          ((nv_items_enum_type) 4089)
#define  NV_WCDMA_BC4_MAX_PWR_BACKOFF_VOLT3_I          ((nv_items_enum_type) 4090)
#define  NV_WCDMA_BC4_HS_R1_RISE_I                     ((nv_items_enum_type) 4091)
#define  NV_WCDMA_BC4_HS_R1_FALL_I                     ((nv_items_enum_type) 4092)
#define  NV_WCDMA_BC4_HS_R2_RISE_I                     ((nv_items_enum_type) 4093)
#define  NV_WCDMA_BC4_HS_R2_FALL_I                     ((nv_items_enum_type) 4094)
#define  NV_WCDMA_BC4_HS_R3_RISE_I                     ((nv_items_enum_type) 4095)
#define  NV_WCDMA_BC4_HS_R3_FALL_I                     ((nv_items_enum_type) 4096)
#define  NV_RFR_VCO_COARSE_TUNING_BC4_I                ((nv_items_enum_type) 4097)
#define  NV_RF_ANTSEL_UMTS_900_I                       ((nv_items_enum_type) 4098)
#define  NV_RF_ANTSEL_UMTS_BC4_I                       ((nv_items_enum_type) 4099)
#define  NV_GPS1_NMEA_OUTPUT_I                         ((nv_items_enum_type) 4100)
#define  NV_ROAM_IND_CUSTOM_HOME_I                     ((nv_items_enum_type) 4101)
#define  NV_CDMA_SO68_ENABLED_I                        ((nv_items_enum_type) 4102)
#define  NV_RTR_BB_FILTER_I                            ((nv_items_enum_type) 4103)
#define  NV_MF_CHAN_SUPPORT_I                          ((nv_items_enum_type) 4104)
#define  NV_MF_RF_PATH_CONFIG_I                        ((nv_items_enum_type) 4105)
#define  NV_MF_RSSI_CAL_VS_FREQ_0_I                    ((nv_items_enum_type) 4106)
#define  NV_MF_RSSI_CAL_VS_FREQ_1_I                    ((nv_items_enum_type) 4107)
#define  NV_MF_RSSI_CAL_VS_FREQ_2_I                    ((nv_items_enum_type) 4108)
#define  NV_MF_RSSI_CAL_VS_FREQ_3_I                    ((nv_items_enum_type) 4109)
#define  NV_UPLOADMEDIA_POSTCARD_SERVER_READONLY_I     ((nv_items_enum_type) 4110)
#define  NV_UMTS_CALL_VT_CODEC_LIST_I                  ((nv_items_enum_type) 4111)
#define  NV_WCDMA_BC4_TX_PDM_LIN_0_I                   ((nv_items_enum_type) 4112)
#define  NV_WCDMA_BC4_TX_PDM_LIN_1_I                   ((nv_items_enum_type) 4113)
#define  NV_WCDMA_BC4_TX_PDM_LIN_2_I                   ((nv_items_enum_type) 4114)
#define  NV_WCDMA_BC4_TX_PDM_LIN_3_I                   ((nv_items_enum_type) 4115)
#define  NV_INTERRAT_NACC_SUPPORT_I                    ((nv_items_enum_type) 4116)
#define  NV_DARP_FEATURE_SUPPORT_I                     ((nv_items_enum_type) 4117)
#define  NV_HSDPA_CAT_I                                ((nv_items_enum_type) 4118)
#define  NV_GSM_IM2_850_I                              ((nv_items_enum_type) 4174)
#define  NV_GSM_IM2_900_I                              ((nv_items_enum_type) 4175)
#define  NV_GSM_IM2_1800_I                             ((nv_items_enum_type) 4176)
#define  NV_GSM_IM2_1900_I                             ((nv_items_enum_type) 4177)
#define  NV_GSM_TX_RSB_CORR_I                          ((nv_items_enum_type) 4179)
#define  NV_DCS_TX_RSB_CORR_I                          ((nv_items_enum_type) 4180)
#define  NV_GSM_850_TX_RSB_CORR_I                      ((nv_items_enum_type) 4181)
#define  NV_GSM_1900_TX_RSB_CORR_I                     ((nv_items_enum_type) 4182)
#define  NV_GSM_1900_TX_RSB_CORR_I                     ((nv_items_enum_type) 4182)
#define  NV_THERM_TEMP_MIN_I                           ((nv_items_enum_type) 4225)
#define  NV_THERM_TEMP_MAX_I                           ((nv_items_enum_type) 4226)
#define  NV_BC15_TX_LIN_MASTER0_I                      ((nv_items_enum_type) 4268)
#define  NV_BC15_TX_LIN_MASTER1_I                      ((nv_items_enum_type) 4269)
#define  NV_BC15_TX_LIN_MASTER2_I                      ((nv_items_enum_type) 4270)
#define  NV_BC15_TX_LIN_MASTER3_I                      ((nv_items_enum_type) 4271)
#define  NV_BC15_GPS1_RF_DELAY_I                       ((nv_items_enum_type) 4272)
#define  NV_BC15_TX_LIM_VS_TEMP_I                      ((nv_items_enum_type) 4273)
#define  NV_BC15_TX_COMP0_I                            ((nv_items_enum_type) 4274)
#define  NV_BC15_TX_COMP1_I                            ((nv_items_enum_type) 4275)
#define  NV_BC15_TX_COMP2_I                            ((nv_items_enum_type) 4276)
#define  NV_BC15_TX_COMP3_I                            ((nv_items_enum_type) 4277)
#define  NV_BC15_TX_LIM_VS_FREQ_I                      ((nv_items_enum_type) 4278)
#define  NV_BC15_PA_R1_RISE_I                          ((nv_items_enum_type) 4279)
#define  NV_BC15_PA_R1_FALL_I                          ((nv_items_enum_type) 4280)
#define  NV_BC15_PA_R2_RISE_I                          ((nv_items_enum_type) 4281)
#define  NV_BC15_PA_R2_FALL_I                          ((nv_items_enum_type) 4282)
#define  NV_BC15_PA_R3_RISE_I                          ((nv_items_enum_type) 4283)
#define  NV_BC15_PA_R3_FALL_I                          ((nv_items_enum_type) 4284)
#define  NV_BC15_HDET_OFF_I                            ((nv_items_enum_type) 4285)
#define  NV_BC15_HDET_SPN_I                            ((nv_items_enum_type) 4286)
#define  NV_BC15_EXP_HDET_VS_AGC_I                     ((nv_items_enum_type) 4287)
#define  NV_BC15_ENC_BTF_I                             ((nv_items_enum_type) 4288)
#define  NV_BC15_VCO_COARSE_TUNE_TABLE_I               ((nv_items_enum_type) 4289)
#define  NV_BC15_VCO_TUNE_2_I                          ((nv_items_enum_type) 4290)
#define  NV_BC15_P1_RISE_FALL_OFF_I                    ((nv_items_enum_type) 4291)
#define  NV_BC15_HDR_P1_RISE_FALL_OFF_I                ((nv_items_enum_type) 4292)
#define  NV_C0_BC15_TX_CAL_CHAN_I                      ((nv_items_enum_type) 4293)
#define  NV_C0_BC15_RX_CAL_CHAN_I                      ((nv_items_enum_type) 4294)
#define  NV_C0_BC15_RX_CAL_CHAN_LRU_I                  ((nv_items_enum_type) 4295)
#define  NV_C0_BC15_LNA_1_OFFSET_I                     ((nv_items_enum_type) 4296)
#define  NV_C0_BC15_LNA_2_OFFSET_I                     ((nv_items_enum_type) 4297)
#define  NV_C0_BC15_LNA_3_OFFSET_I                     ((nv_items_enum_type) 4298)
#define  NV_C0_BC15_LNA_4_OFFSET_I                     ((nv_items_enum_type) 4299)
#define  NV_C0_BC15_LNA_1_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4300)
#define  NV_C0_BC15_LNA_2_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4301)
#define  NV_C0_BC15_LNA_3_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4302)
#define  NV_C0_BC15_LNA_4_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4303)
#define  NV_C0_BC15_IM2_I_VALUE_I                      ((nv_items_enum_type) 4304)
#define  NV_C0_BC15_IM2_Q_VALUE_I                      ((nv_items_enum_type) 4305)
#define  NV_C0_BC15_VGA_GAIN_OFFSET_I                  ((nv_items_enum_type) 4306)
#define  NV_C0_BC15_VGA_GAIN_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 4307)
#define  NV_C0_BC15_IM2_TRANSCONDUCTOR_VALUE_I         ((nv_items_enum_type) 4308)
#define  NV_C0_BC15_LNA_1_RISE_I                       ((nv_items_enum_type) 4309)
#define  NV_C0_BC15_LNA_1_FALL_I                       ((nv_items_enum_type) 4310)
#define  NV_C0_BC15_LNA_2_RISE_I                       ((nv_items_enum_type) 4311)
#define  NV_C0_BC15_LNA_2_FALL_I                       ((nv_items_enum_type) 4312)
#define  NV_C0_BC15_LNA_3_RISE_I                       ((nv_items_enum_type) 4313)
#define  NV_C0_BC15_LNA_3_FALL_I                       ((nv_items_enum_type) 4314)
#define  NV_C0_BC15_LNA_4_RISE_I                       ((nv_items_enum_type) 4315)
#define  NV_C0_BC15_LNA_4_FALL_I                       ((nv_items_enum_type) 4316)
#define  NV_C0_BC15_IM_LEVEL1_I                        ((nv_items_enum_type) 4317)
#define  NV_C0_BC15_IM_LEVEL2_I                        ((nv_items_enum_type) 4318)
#define  NV_C0_BC15_IM_LEVEL3_I                        ((nv_items_enum_type) 4319)
#define  NV_C0_BC15_IM_LEVEL4_I                        ((nv_items_enum_type) 4320)
#define  NV_C1_BC15_TX_CAL_CHAN_I                      ((nv_items_enum_type) 4321)
#define  NV_C1_BC15_RX_CAL_CHAN_I                      ((nv_items_enum_type) 4322)
#define  NV_C1_BC15_LNA_1_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4323)
#define  NV_C1_BC15_LNA_2_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4324)
#define  NV_C1_BC15_LNA_3_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4325)
#define  NV_C1_BC15_LNA_4_OFFSET_VS_FREQ_I             ((nv_items_enum_type) 4326)
#define  NV_C1_BC15_LNA_1_OFFSET_I                     ((nv_items_enum_type) 4327)
#define  NV_C1_BC15_LNA_2_OFFSET_I                     ((nv_items_enum_type) 4328)
#define  NV_C1_BC15_LNA_3_OFFSET_I                     ((nv_items_enum_type) 4329)
#define  NV_C1_BC15_LNA_4_OFFSET_I                     ((nv_items_enum_type) 4330)
#define  NV_C1_BC15_IM2_I_VALUE_I                      ((nv_items_enum_type) 4331)
#define  NV_C1_BC15_IM2_Q_VALUE_I                      ((nv_items_enum_type) 4332)
#define  NV_C1_BC15_VGA_GAIN_OFFSET_I                  ((nv_items_enum_type) 4333)
#define  NV_C1_BC15_VGA_GAIN_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 4334)
#define  NV_C1_BC15_IM2_TRANSCONDUCTOR_VALUE_I         ((nv_items_enum_type) 4335)
#define  NV_C1_BC15_LNA_1_RISE_I                       ((nv_items_enum_type) 4336)
#define  NV_C1_BC15_LNA_1_FALL_I                       ((nv_items_enum_type) 4337)
#define  NV_C1_BC15_LNA_2_RISE_I                       ((nv_items_enum_type) 4338)
#define  NV_C1_BC15_LNA_2_FALL_I                       ((nv_items_enum_type) 4339)
#define  NV_C1_BC15_LNA_3_RISE_I                       ((nv_items_enum_type) 4340)
#define  NV_C1_BC15_LNA_3_FALL_I                       ((nv_items_enum_type) 4341)
#define  NV_C1_BC15_LNA_4_RISE_I                       ((nv_items_enum_type) 4342)
#define  NV_C1_BC15_LNA_4_FALL_I                       ((nv_items_enum_type) 4343)
#define  NV_C1_BC15_IM_LEVEL1_I                        ((nv_items_enum_type) 4344)
#define  NV_C1_BC15_IM_LEVEL2_I                        ((nv_items_enum_type) 4345)
#define  NV_C1_BC15_IM_LEVEL3_I                        ((nv_items_enum_type) 4346)
#define  NV_C1_BC15_IM_LEVEL4_I                        ((nv_items_enum_type) 4347)
#define  NV_C1_BC15_VCO_COARSE_TUNE_TABLE_I            ((nv_items_enum_type) 4348)
#define  NV_BC15_ANT_QUALITY_I                         ((nv_items_enum_type) 4349)
#define  NV_BC15_PA_DVS_VOLTAGE_I                      ((nv_items_enum_type) 4350)
#define  NV_C0_BC15_LNA_SWITCHPOINTS_LPM_1_I           ((nv_items_enum_type) 4351)
#define  NV_C0_BC15_LNA_SWITCHPOINTS_LPM_2_I           ((nv_items_enum_type) 4352)
#define  NV_C0_BC15_IM2_LPM_1_I                        ((nv_items_enum_type) 4353)
#define  NV_C0_BC15_IM2_LPM_2_I                        ((nv_items_enum_type) 4354)
#define  NV_C0_BC15_INTELLICEIVER_CAL_I                ((nv_items_enum_type) 4355)
#define  NV_C0_BC15_INTELLICEIVER_DET_THRESH_I         ((nv_items_enum_type) 4356)
#define  NV_C1_BC15_RX_CAL_CHAN_LRU_I                  ((nv_items_enum_type) 4357)
#define  NV_DCVS_ACPU_ENABLE_I                         ((nv_items_enum_type) 4358)
#define  NV_GPSONE_PASSWORD_I                          ((nv_items_enum_type) 4359)
#define  NV_VOIP_CALLERID_MODE_I                       ((nv_items_enum_type) 4360)
#define  NV_WLAN_MULTIDOMAIN_CAPABILITY_PREF_I         ((nv_items_enum_type) 4361)
#define  NV_UMTS_NBNS_ENABLE_I                         ((nv_items_enum_type) 4362)
#define  NV_SCUDIF_CALLSETUP_PREF_I                    ((nv_items_enum_type) 4363)
#define  NV_VOIP_REFER_SUBSCRIPTION_EXPIRES_DURATION_I ((nv_items_enum_type) 4364)
#define  NV_VOIP_NOTIFY_REFER_RESPONSE_DURATION_I      ((nv_items_enum_type) 4365)
#define  NV_SMS_SERVICE_OPTION_I                       ((nv_items_enum_type) 4366)
#define  NV_DRM_BIND_SIM_RIGHTS_I                      ((nv_items_enum_type) 4367)
#define  NV_GSM_850_PA_TEMP_COMP_MAX_PWR_I             ((nv_items_enum_type) 4368)
#define  NV_GSM_PA_TEMP_COMP_MAX_PWR_I                 ((nv_items_enum_type) 4369)
#define  NV_DCS_PA_TEMP_COMP_MAX_PWR_I                 ((nv_items_enum_type) 4370)
#define  NV_GSM_1900_PA_TEMP_COMP_MAX_PWR_I            ((nv_items_enum_type) 4371)
#define  NV_GSM_RSSI_TEMP_VALUES_I                     ((nv_items_enum_type) 4372)
#define  NV_GSM_850_RX_GAIN_RANGE_1_TEMP_COMP_I        ((nv_items_enum_type) 4373)
#define  NV_GSM_RX_GAIN_RANGE_1_TEMP_COMP_I            ((nv_items_enum_type) 4374)
#define  NV_DCS_RX_GAIN_RANGE_1_TEMP_COMP_I            ((nv_items_enum_type) 4375)
#define  NV_GSM_1900_RX_GAIN_RANGE_1_TEMP_COMP_I       ((nv_items_enum_type) 4376)
#define  NV_GSM_850_RX_GAIN_RANGE_2_TEMP_COMP_I        ((nv_items_enum_type) 4377)
#define  NV_GSM_RX_GAIN_RANGE_2_TEMP_COMP_I            ((nv_items_enum_type) 4378)
#define  NV_DCS_RX_GAIN_RANGE_2_TEMP_COMP_I            ((nv_items_enum_type) 4379)
#define  NV_GSM_1900_RX_GAIN_RANGE_2_TEMP_COMP_I       ((nv_items_enum_type) 4380)
#define  NV_GSM_850_RX_GAIN_RANGE_3_TEMP_COMP_I        ((nv_items_enum_type) 4381)
#define  NV_GSM_RX_GAIN_RANGE_3_TEMP_COMP_I            ((nv_items_enum_type) 4382)
#define  NV_DCS_RX_GAIN_RANGE_3_TEMP_COMP_I            ((nv_items_enum_type) 4383)
#define  NV_GSM_1900_RX_GAIN_RANGE_3_TEMP_COMP_I       ((nv_items_enum_type) 4384)
#define  NV_GSM_850_RX_GAIN_RANGE_4_TEMP_COMP_I        ((nv_items_enum_type) 4385)
#define  NV_GSM_RX_GAIN_RANGE_4_TEMP_COMP_I            ((nv_items_enum_type) 4386)
#define  NV_DCS_RX_GAIN_RANGE_4_TEMP_COMP_I            ((nv_items_enum_type) 4387)
#define  NV_GSM_1900_RX_GAIN_RANGE_4_TEMP_COMP_I       ((nv_items_enum_type) 4388)
#define  NV_GSM_850_RX_GAIN_RANGE_5_TEMP_COMP_I        ((nv_items_enum_type) 4389)
#define  NV_GSM_RX_GAIN_RANGE_5_TEMP_COMP_I            ((nv_items_enum_type) 4390)
#define  NV_DCS_RX_GAIN_RANGE_5_TEMP_COMP_I            ((nv_items_enum_type) 4391)
#define  NV_GSM_1900_RX_GAIN_RANGE_5_TEMP_COMP_I       ((nv_items_enum_type) 4392)
#define  NV_DCVSAPPS_NV_I                              ((nv_items_enum_type) 4393)
#define  NV_GPS1_SEC_UPDATE_RATE_I                     ((nv_items_enum_type) 4394)
#define  NV_MMGSDI_ME_CONFIG_PARAM_I                   ((nv_items_enum_type) 4395)
#define  NV_DS_MIP_DEREG_RETRIES_I                     ((nv_items_enum_type) 4396)
#define  NV_RUIM_NO_SUPPORT_I                          ((nv_items_enum_type) 4397)
#define  NV_UIM_SELECT_DEFAULT_USIM_APP_I              ((nv_items_enum_type) 4398)
#define  NV_DETECT_HW_RESET_I                          ((nv_items_enum_type) 4399)
#define  NV_WCDMA_IM_LEVEL_4_I                         ((nv_items_enum_type) 4400)
#define  NV_WCDMA_LNA_OFFSET_VS_FREQ_4_I               ((nv_items_enum_type) 4401)
#define  NV_WCDMA_LNA_RANGE_FALL_4_I                   ((nv_items_enum_type) 4402)
#define  NV_WCDMA_LNA_RANGE_OFFSET_4_I                 ((nv_items_enum_type) 4403)
#define  NV_WCDMA_LNA_RANGE_RISE_4_I                   ((nv_items_enum_type) 4404)
#define  NV_WCDMA_1900_IM_LEVEL_4_I                    ((nv_items_enum_type) 4405)
#define  NV_WCDMA_1900_LNA_OFFSET_VS_FREQ_4_I          ((nv_items_enum_type) 4406)
#define  NV_WCDMA_1900_LNA_RANGE_FALL_4_I              ((nv_items_enum_type) 4407)
#define  NV_WCDMA_1900_LNA_RANGE_OFFSET_4_I            ((nv_items_enum_type) 4408)
#define  NV_WCDMA_1900_LNA_RANGE_RISE_4_I              ((nv_items_enum_type) 4409)
#define  NV_WCDMA_800_IM_LEVEL_4_I                     ((nv_items_enum_type) 4410)
#define  NV_WCDMA_800_LNA_OFFSET_VS_FREQ_4_I           ((nv_items_enum_type) 4411)
#define  NV_WCDMA_800_LNA_RANGE_FALL_4_I               ((nv_items_enum_type) 4412)
#define  NV_WCDMA_800_LNA_RANGE_OFFSET_4_I             ((nv_items_enum_type) 4413)
#define  NV_WCDMA_800_LNA_RANGE_RISE_4_I               ((nv_items_enum_type) 4414)
#define  NV_WCDMA_1800_IM_LEVEL_4_I                    ((nv_items_enum_type) 4415)
#define  NV_WCDMA_1800_LNA_OFFSET_VS_FREQ_4_I          ((nv_items_enum_type) 4416)
#define  NV_WCDMA_1800_LNA_RANGE_FALL_4_I              ((nv_items_enum_type) 4417)
#define  NV_WCDMA_1800_LNA_RANGE_OFFSET_4_I            ((nv_items_enum_type) 4418)
#define  NV_WCDMA_1800_LNA_RANGE_RISE_4_I              ((nv_items_enum_type) 4419)
#define  NV_WCDMA_900_IM_LEVEL_4_I                     ((nv_items_enum_type) 4420)
#define  NV_WCDMA_900_LNA_OFFSET_VS_FREQ_4_I           ((nv_items_enum_type) 4421)
#define  NV_WCDMA_900_LNA_RANGE_FALL_4_I               ((nv_items_enum_type) 4422)
#define  NV_WCDMA_900_LNA_RANGE_OFFSET_4_I             ((nv_items_enum_type) 4423)
#define  NV_WCDMA_900_LNA_RANGE_RISE_4_I               ((nv_items_enum_type) 4424)
#define  NV_WCDMA_BC4_IM_LEVEL_4_I                     ((nv_items_enum_type) 4425)
#define  NV_WCDMA_BC4_LNA_OFFSET_VS_FREQ_4_I           ((nv_items_enum_type) 4426)
#define  NV_WCDMA_BC4_LNA_RANGE_FALL_4_I               ((nv_items_enum_type) 4427)
#define  NV_WCDMA_BC4_LNA_RANGE_OFFSET_4_I             ((nv_items_enum_type) 4428)
#define  NV_WCDMA_BC4_LNA_RANGE_RISE_4_I               ((nv_items_enum_type) 4429)
#define  NV_IPV6_PRIVACY_EXTENSIONS_ENABLED_I          ((nv_items_enum_type) 4430)
#define  NV_IPV6_PRIVATE_ADDRESS_CONFIG_I              ((nv_items_enum_type) 4431)
#define  NV_GPRS_GEA_ALGORITHMS_SUPPORTED_I            ((nv_items_enum_type) 4432)
#define  NV_REX_TRACE_I                                ((nv_items_enum_type) 4433)
#define  NV_C1_WCDMA_1800_VGA_GAIN_OFFSET_I            ((nv_items_enum_type) 4434)
#define  NV_C1_WCDMA_1800_VGA_GAIN_OFFSET_VS_FREQ_I    ((nv_items_enum_type) 4435)
#define  NV_C1_WCDMA_1800_VGA_GAIN_OFFSET_VS_TEMP_I    ((nv_items_enum_type) 4436)
#define  NV_C1_WCDMA_1800_LNA_RANGE_RISE_I             ((nv_items_enum_type) 4437)
#define  NV_C1_WCDMA_1800_LNA_RANGE_RISE_2_I           ((nv_items_enum_type) 4438)
#define  NV_C1_WCDMA_1800_LNA_RANGE_RISE_3_I           ((nv_items_enum_type) 4439)
#define  NV_C1_WCDMA_1800_LNA_RANGE_RISE_4_I           ((nv_items_enum_type) 4440)
#define  NV_C1_WCDMA_1800_LNA_RANGE_FALL_I             ((nv_items_enum_type) 4441)
#define  NV_C1_WCDMA_1800_LNA_RANGE_FALL_2_I           ((nv_items_enum_type) 4442)
#define  NV_C1_WCDMA_1800_LNA_RANGE_FALL_3_I           ((nv_items_enum_type) 4443)
#define  NV_C1_WCDMA_1800_LNA_RANGE_FALL_4_I           ((nv_items_enum_type) 4444)
#define  NV_C1_WCDMA_1800_IM_LEVEL_I                   ((nv_items_enum_type) 4445)
#define  NV_C1_WCDMA_1800_IM_LEVEL_2_I                 ((nv_items_enum_type) 4446)
#define  NV_C1_WCDMA_1800_IM_LEVEL_3_I                 ((nv_items_enum_type) 4447)
#define  NV_C1_WCDMA_1800_IM_LEVEL_4_I                 ((nv_items_enum_type) 4448)
#define  NV_C1_WCDMA_1800_LNA_RANGE_OFFSET_2_I         ((nv_items_enum_type) 4449)
#define  NV_C1_WCDMA_1800_LNA_RANGE_OFFSET_3_I         ((nv_items_enum_type) 4450)
#define  NV_C1_WCDMA_1800_LNA_RANGE_OFFSET_4_I         ((nv_items_enum_type) 4451)
#define  NV_C1_WCDMA_1800_LNA_OFFSET_VS_FREQ_2_I       ((nv_items_enum_type) 4452)
#define  NV_C1_WCDMA_1800_LNA_OFFSET_VS_FREQ_3_I       ((nv_items_enum_type) 4453)
#define  NV_C1_WCDMA_1800_LNA_OFFSET_VS_FREQ_4_I       ((nv_items_enum_type) 4454)
#define  NV_C1_WCDMA_1800_IM2_I_VALUE_I                ((nv_items_enum_type) 4455)
#define  NV_C1_WCDMA_1800_IM2_Q_VALUE_I                ((nv_items_enum_type) 4456)
#define  NV_C1_WCDMA_1800_IM2_TRANSCONDUCTOR_VALUE_I   ((nv_items_enum_type) 4457)
#define  NV_C1_WCDMA_1800_NONBYPASS_TIMER_I            ((nv_items_enum_type) 4458)
#define  NV_C1_WCDMA_1800_BYPASS_TIMER_I               ((nv_items_enum_type) 4459)
#define  NV_C1_WCDMA_1800_LNA_RANGE_OFFSET_I           ((nv_items_enum_type) 4460)
#define  NV_C1_WCDMA_1800_LNA_OFFSET_VS_FREQ_I         ((nv_items_enum_type) 4461)
#define  NV_C1_WCDMA_1800_RX_CAL_CHAN_I                ((nv_items_enum_type) 4462)
#define  NV_C1_WCDMA_900_VGA_GAIN_OFFSET_I             ((nv_items_enum_type) 4463)
#define  NV_C1_WCDMA_900_VGA_GAIN_OFFSET_VS_FREQ_I     ((nv_items_enum_type) 4464)
#define  NV_C1_WCDMA_900_VGA_GAIN_OFFSET_VS_TEMP_I     ((nv_items_enum_type) 4465)
#define  NV_C1_WCDMA_900_LNA_RANGE_RISE_I              ((nv_items_enum_type) 4466)
#define  NV_C1_WCDMA_900_LNA_RANGE_RISE_2_I            ((nv_items_enum_type) 4467)
#define  NV_C1_WCDMA_900_LNA_RANGE_RISE_3_I            ((nv_items_enum_type) 4468)
#define  NV_C1_WCDMA_900_LNA_RANGE_RISE_4_I            ((nv_items_enum_type) 4469)
#define  NV_C1_WCDMA_900_LNA_RANGE_FALL_I              ((nv_items_enum_type) 4470)
#define  NV_C1_WCDMA_900_LNA_RANGE_FALL_2_I            ((nv_items_enum_type) 4471)
#define  NV_C1_WCDMA_900_LNA_RANGE_FALL_3_I            ((nv_items_enum_type) 4472)
#define  NV_C1_WCDMA_900_LNA_RANGE_FALL_4_I            ((nv_items_enum_type) 4473)
#define  NV_C1_WCDMA_900_IM_LEVEL_I                    ((nv_items_enum_type) 4474)
#define  NV_C1_WCDMA_900_IM_LEVEL_2_I                  ((nv_items_enum_type) 4475)
#define  NV_C1_WCDMA_900_IM_LEVEL_3_I                  ((nv_items_enum_type) 4476)
#define  NV_C1_WCDMA_900_IM_LEVEL_4_I                  ((nv_items_enum_type) 4477)
#define  NV_C1_WCDMA_900_LNA_RANGE_OFFSET_2_I          ((nv_items_enum_type) 4478)
#define  NV_C1_WCDMA_900_LNA_RANGE_OFFSET_3_I          ((nv_items_enum_type) 4479)
#define  NV_C1_WCDMA_900_LNA_RANGE_OFFSET_4_I          ((nv_items_enum_type) 4480)
#define  NV_C1_WCDMA_900_LNA_OFFSET_VS_FREQ_2_I        ((nv_items_enum_type) 4481)
#define  NV_C1_WCDMA_900_LNA_OFFSET_VS_FREQ_3_I        ((nv_items_enum_type) 4482)
#define  NV_C1_WCDMA_900_LNA_OFFSET_VS_FREQ_4_I        ((nv_items_enum_type) 4483)
#define  NV_C1_WCDMA_900_IM2_I_VALUE_I                 ((nv_items_enum_type) 4484)
#define  NV_C1_WCDMA_900_IM2_Q_VALUE_I                 ((nv_items_enum_type) 4485)
#define  NV_C1_WCDMA_900_IM2_TRANSCONDUCTOR_VALUE_I    ((nv_items_enum_type) 4486)
#define  NV_C1_WCDMA_900_NONBYPASS_TIMER_I             ((nv_items_enum_type) 4487)
#define  NV_C1_WCDMA_900_BYPASS_TIMER_I                ((nv_items_enum_type) 4488)
#define  NV_C1_WCDMA_900_LNA_RANGE_OFFSET_I            ((nv_items_enum_type) 4489)
#define  NV_C1_WCDMA_900_LNA_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 4490)
#define  NV_C1_WCDMA_900_RX_CAL_CHAN_I                 ((nv_items_enum_type) 4491)
#define  NV_C1_WCDMA_BC4_VGA_GAIN_OFFSET_I             ((nv_items_enum_type) 4492)
#define  NV_C1_WCDMA_BC4_VGA_GAIN_OFFSET_VS_FREQ_I     ((nv_items_enum_type) 4493)
#define  NV_C1_WCDMA_BC4_VGA_GAIN_OFFSET_VS_TEMP_I     ((nv_items_enum_type) 4494)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_RISE_I              ((nv_items_enum_type) 4495)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_RISE_2_I            ((nv_items_enum_type) 4496)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_RISE_3_I            ((nv_items_enum_type) 4497)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_RISE_4_I            ((nv_items_enum_type) 4498)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_FALL_I              ((nv_items_enum_type) 4499)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_FALL_2_I            ((nv_items_enum_type) 4500)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_FALL_3_I            ((nv_items_enum_type) 4501)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_FALL_4_I            ((nv_items_enum_type) 4502)
#define  NV_C1_WCDMA_BC4_IM_LEVEL_I                    ((nv_items_enum_type) 4503)
#define  NV_C1_WCDMA_BC4_IM_LEVEL_2_I                  ((nv_items_enum_type) 4504)
#define  NV_C1_WCDMA_BC4_IM_LEVEL_3_I                  ((nv_items_enum_type) 4505)
#define  NV_C1_WCDMA_BC4_IM_LEVEL_4_I                  ((nv_items_enum_type) 4506)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_OFFSET_2_I          ((nv_items_enum_type) 4507)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_OFFSET_3_I          ((nv_items_enum_type) 4508)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_OFFSET_4_I          ((nv_items_enum_type) 4509)
#define  NV_C1_WCDMA_BC4_LNA_OFFSET_VS_FREQ_2_I        ((nv_items_enum_type) 4510)
#define  NV_C1_WCDMA_BC4_LNA_OFFSET_VS_FREQ_3_I        ((nv_items_enum_type) 4511)
#define  NV_C1_WCDMA_BC4_LNA_OFFSET_VS_FREQ_4_I        ((nv_items_enum_type) 4512)
#define  NV_C1_WCDMA_BC4_IM2_I_VALUE_I                 ((nv_items_enum_type) 4513)
#define  NV_C1_WCDMA_BC4_IM2_Q_VALUE_I                 ((nv_items_enum_type) 4514)
#define  NV_C1_WCDMA_BC4_IM2_TRANSCONDUCTOR_VALUE_I    ((nv_items_enum_type) 4515)
#define  NV_C1_WCDMA_BC4_NONBYPASS_TIMER_I             ((nv_items_enum_type) 4516)
#define  NV_C1_WCDMA_BC4_BYPASS_TIMER_I                ((nv_items_enum_type) 4517)
#define  NV_C1_WCDMA_BC4_LNA_RANGE_OFFSET_I            ((nv_items_enum_type) 4518)
#define  NV_C1_WCDMA_BC4_LNA_OFFSET_VS_FREQ_I          ((nv_items_enum_type) 4519)
#define  NV_C1_WCDMA_BC4_RX_CAL_CHAN_I                 ((nv_items_enum_type) 4520)
#define  NV_MF_PREF_RF_CHAN_LIST_I                     ((nv_items_enum_type) 4521)
#define  NV_MF_IC_UPDATE_RATE_I                        ((nv_items_enum_type) 4522)
#define  NV_NPT_COUNT_I                                ((nv_items_enum_type) 4523)
#define  NV_BCX_BLOCK_GPS1_RF_DELAY_I					 ((nv_items_enum_type) 4549)
#define  NV_BC0_TX_PDM_0_I                             ((nv_items_enum_type) 4795)
#define  NV_BC0_TX_PDM_1_I                             ((nv_items_enum_type) 4796)
#define  NV_BC0_TX_PDM_2_I                             ((nv_items_enum_type) 4797)
#define  NV_BC0_TX_PDM_3_I                             ((nv_items_enum_type) 4798)
#define  NV_BC1_TX_PDM_0_I                             ((nv_items_enum_type) 4799)
#define  NV_BC1_TX_PDM_1_I                             ((nv_items_enum_type) 4800)
#define  NV_BC1_TX_PDM_2_I                             ((nv_items_enum_type) 4801)
#define  NV_BC1_TX_PDM_3_I                             ((nv_items_enum_type) 4802)
#define  NV_BC3_TX_PDM_0_I                             ((nv_items_enum_type) 4803)
#define  NV_BC3_TX_PDM_1_I                             ((nv_items_enum_type) 4804)
#define  NV_BC3_TX_PDM_2_I                             ((nv_items_enum_type) 4805)
#define  NV_BC3_TX_PDM_3_I                             ((nv_items_enum_type) 4806)
#define  NV_BC4_TX_PDM_0_I                             ((nv_items_enum_type) 4807)
#define  NV_BC4_TX_PDM_1_I                             ((nv_items_enum_type) 4808)
#define  NV_BC4_TX_PDM_2_I                             ((nv_items_enum_type) 4809)
#define  NV_BC4_TX_PDM_3_I                             ((nv_items_enum_type) 4810)
#define  NV_BC5_TX_PDM_0_I                             ((nv_items_enum_type) 4811)
#define  NV_BC5_TX_PDM_1_I                             ((nv_items_enum_type) 4812)
#define  NV_BC5_TX_PDM_2_I                             ((nv_items_enum_type) 4813)
#define  NV_BC5_TX_PDM_3_I                             ((nv_items_enum_type) 4814)
#define  NV_BC6_TX_PDM_0_I                             ((nv_items_enum_type) 4815)
#define  NV_BC6_TX_PDM_1_I                             ((nv_items_enum_type) 4816)
#define  NV_BC6_TX_PDM_2_I                             ((nv_items_enum_type) 4817)
#define  NV_BC6_TX_PDM_3_I                             ((nv_items_enum_type) 4818)
#define  NV_BC11_TX_PDM_0_I                            ((nv_items_enum_type) 4819)
#define  NV_BC11_TX_PDM_1_I                            ((nv_items_enum_type) 4820)
#define  NV_BC11_TX_PDM_2_I                            ((nv_items_enum_type) 4821)
#define  NV_BC11_TX_PDM_3_I                            ((nv_items_enum_type) 4822)
#define  NV_BC14_TX_PDM_0_I                            ((nv_items_enum_type) 4823)
#define  NV_BC14_TX_PDM_1_I                            ((nv_items_enum_type) 4824)
#define  NV_BC14_TX_PDM_2_I                            ((nv_items_enum_type) 4825)
#define  NV_BC14_TX_PDM_3_I                            ((nv_items_enum_type) 4826)
#define  NV_BC15_TX_PDM_0_I                            ((nv_items_enum_type) 4827)
#define  NV_BC15_TX_PDM_1_I                            ((nv_items_enum_type) 4828)
#define  NV_BC15_TX_PDM_2_I                            ((nv_items_enum_type) 4829)
#define  NV_BC15_TX_PDM_3_I                            ((nv_items_enum_type) 4830)
#define  NV_BC0_TX_LIN_0_I                             ((nv_items_enum_type) 4831)
#define  NV_BC0_TX_LIN_1_I                             ((nv_items_enum_type) 4832)
#define  NV_BC0_TX_LIN_2_I                             ((nv_items_enum_type) 4833)
#define  NV_BC0_TX_LIN_3_I                             ((nv_items_enum_type) 4834)
#define  NV_BC1_TX_LIN_0_I                             ((nv_items_enum_type) 4835)
#define  NV_BC1_TX_LIN_1_I                             ((nv_items_enum_type) 4836)
#define  NV_BC1_TX_LIN_2_I                             ((nv_items_enum_type) 4837)
#define  NV_BC1_TX_LIN_3_I                             ((nv_items_enum_type) 4838)
#define  NV_BC3_TX_LIN_0_I                             ((nv_items_enum_type) 4839)
#define  NV_BC3_TX_LIN_1_I                             ((nv_items_enum_type) 4840)
#define  NV_BC3_TX_LIN_2_I                             ((nv_items_enum_type) 4841)
#define  NV_BC3_TX_LIN_3_I                             ((nv_items_enum_type) 4842)
#define  NV_BC4_TX_LIN_0_I                             ((nv_items_enum_type) 4843)
#define  NV_BC4_TX_LIN_1_I                             ((nv_items_enum_type) 4844)
#define  NV_BC4_TX_LIN_2_I                             ((nv_items_enum_type) 4845)
#define  NV_BC4_TX_LIN_3_I                             ((nv_items_enum_type) 4846)
#define  NV_BC5_TX_LIN_0_I                             ((nv_items_enum_type) 4847)
#define  NV_BC5_TX_LIN_1_I                             ((nv_items_enum_type) 4848)
#define  NV_BC5_TX_LIN_2_I                             ((nv_items_enum_type) 4849)
#define  NV_BC5_TX_LIN_3_I                             ((nv_items_enum_type) 4850)
#define  NV_BC6_TX_LIN_0_I                             ((nv_items_enum_type) 4851)
#define  NV_BC6_TX_LIN_1_I                             ((nv_items_enum_type) 4852)
#define  NV_BC6_TX_LIN_2_I                             ((nv_items_enum_type) 4853)
#define  NV_BC6_TX_LIN_3_I                             ((nv_items_enum_type) 4854)
#define  NV_BC11_TX_LIN_0_I                            ((nv_items_enum_type) 4855)
#define  NV_BC11_TX_LIN_1_I                            ((nv_items_enum_type) 4856)
#define  NV_BC11_TX_LIN_2_I                            ((nv_items_enum_type) 4857)
#define  NV_BC11_TX_LIN_3_I                            ((nv_items_enum_type) 4858)
#define  NV_BC14_TX_LIN_0_I                            ((nv_items_enum_type) 4859)
#define  NV_BC14_TX_LIN_1_I                            ((nv_items_enum_type) 4860)
#define  NV_BC14_TX_LIN_2_I                            ((nv_items_enum_type) 4861)
#define  NV_BC14_TX_LIN_3_I                            ((nv_items_enum_type) 4862)
#define  NV_BC15_TX_LIN_0_I                            ((nv_items_enum_type) 4863)
#define  NV_BC15_TX_LIN_1_I                            ((nv_items_enum_type) 4864)
#define  NV_BC15_TX_LIN_2_I                            ((nv_items_enum_type) 4865)
#define  NV_BC15_TX_LIN_3_I                            ((nv_items_enum_type) 4866)
#define  NV_HDR_RX_DIV_BC_ENABLE_MASK_I                ((nv_items_enum_type) 4867)
#define  NV_CDMA_RX_DIV_BC_ENABLE_MASK_I               ((nv_items_enum_type) 4868)
#define  NV_GSM_CARRIER_SUPPRESSION_I                  ((nv_items_enum_type) 4869)
#define  NV_GSM_850_CARRIER_SUPPRESSION_I              ((nv_items_enum_type) 4870)
#define  NV_GSM_DCS_CARRIER_SUPPRESSION_I              ((nv_items_enum_type) 4871)
#define  NV_GSM_1900_CARRIER_SUPPRESSION_I             ((nv_items_enum_type) 4872)
#define  NV_DVBH_STORE_NW_INFO_TO_EFS_I                ((nv_items_enum_type) 4873)
#define  NV_DVBH_EFS_NW_INFO_EXPIRY_TIME_I             ((nv_items_enum_type) 4874)
#define  NV_DVBH_NW_ACQ_ON_CELL_ID_MISMATCH_I          ((nv_items_enum_type) 4875)
#define  NV_DVBH_WAIT_FOR_NIT_OTHER_I                  ((nv_items_enum_type) 4876)
#define  NV_DVBH_ALL_NIT_ACQ_TIMEOUT_I                 ((nv_items_enum_type) 4877)
#define  NV_DVBH_LNKG_ACQ_TIMEOUT_I                    ((nv_items_enum_type) 4878)
#define  NV_DISPLAY_UPDATE_POWER_TEST_MODE_I           ((nv_items_enum_type) 4879)
#define  NV_BC0_PA_R_MAP_I                             ((nv_items_enum_type) 4880)
#define  NV_BC1_PA_R_MAP_I                             ((nv_items_enum_type) 4881)
#define  NV_BC3_PA_R_MAP_I                             ((nv_items_enum_type) 4882)
#define  NV_BC4_PA_R_MAP_I                             ((nv_items_enum_type) 4883)
#define  NV_BC5_PA_R_MAP_I                             ((nv_items_enum_type) 4884)
#define  NV_BC6_PA_R_MAP_I                             ((nv_items_enum_type) 4885)
#define  NV_BC11_PA_R_MAP_I                            ((nv_items_enum_type) 4886)
#define  NV_BC14_PA_R_MAP_I                            ((nv_items_enum_type) 4887)
#define  NV_BC15_PA_R_MAP_I                            ((nv_items_enum_type) 4888)
#define  NV_HDRSRCH_DBG_MSK_I                          ((nv_items_enum_type) 4889)
#define  NV_AIMS_ON_I                                  ((nv_items_enum_type) 4890)
#define  NV_MBP_RF_DVBH_CAL_FREQ_I                     ((nv_items_enum_type) 4891)
#define  NV_MBP_RF_DVBH_GS0_CAL_I                      ((nv_items_enum_type) 4892)
#define  NV_MBP_RF_DVBH_GS1_CAL_I                      ((nv_items_enum_type) 4893)
#define  NV_MBP_RF_DVBH_GS2_CAL_I                      ((nv_items_enum_type) 4894)
#define  NV_MBP_RF_DVBH_GS3_CAL_I                      ((nv_items_enum_type) 4895)
#define  NV_MBP_RF_DVBH_GS4_CAL_I                      ((nv_items_enum_type) 4896)
#define  NV_MBP_RF_DVBH_GS5_CAL_I                      ((nv_items_enum_type) 4897)
#define  NV_MBP_RF_MFLO_CAL_FREQ_I                     ((nv_items_enum_type) 4898)
#define  NV_MBP_RF_MFLO_GS0_CAL_I                      ((nv_items_enum_type) 4899)
#define  NV_MBP_RF_MFLO_GS1_CAL_I                      ((nv_items_enum_type) 4900)
#define  NV_MBP_RF_MFLO_GS2_CAL_I                      ((nv_items_enum_type) 4901)
#define  NV_MBP_RF_MFLO_GS3_CAL_I                      ((nv_items_enum_type) 4902)
#define  NV_MBP_RF_MFLO_GS4_CAL_I                      ((nv_items_enum_type) 4903)
#define  NV_MBP_RF_MFLO_GS5_CAL_I                      ((nv_items_enum_type) 4904)
#define  NV_QVP_APP_PSVT_ENABLE_FLAG_I                 ((nv_items_enum_type) 4905)
#define  NV_CGPS_DGPS_CORRECTIONS_ALLOWED_I            ((nv_items_enum_type) 4906)
#define  NV_CGPS_MAXIMUM_DGPS_INTERVAL_I               ((nv_items_enum_type) 4907)
#define  NV_CGPS_USE_FDIC_I                            ((nv_items_enum_type) 4908)
#define  NV_CGPS_ALTITUDE_HOLD_MODE_I                  ((nv_items_enum_type) 4909)
#define  NV_CGPS_PDOP_MASK_I                           ((nv_items_enum_type) 4910)
#define  NV_CGPS_2D_PDOP_MASK_I                        ((nv_items_enum_type) 4911)
#define  NV_CGPS_REFERENCE_MODE_I                      ((nv_items_enum_type) 4912)
#define  NV_CGPS_OPERATION_MODE_I                      ((nv_items_enum_type) 4913)
#define  NV_CGPS_ELEVATION_MASK_I                      ((nv_items_enum_type) 4914)
#define  NV_CGPS_MAX_ALMANAC_AGE_IN_WEEKS_I            ((nv_items_enum_type) 4915)
#define  NV_CGPS_STEERING_ON_STARTUP_I                 ((nv_items_enum_type) 4916)
#define  NV_ICMP6_ND_CONFIG_I                          ((nv_items_enum_type) 4917)
#define  NV_HS_USB_REMOTE_WAKEUP_DELAY_I               ((nv_items_enum_type) 4918)
#define  NV_DVBH_UHF_BAND_FREQ_RANGE_AND_OFFSET_1_I    ((nv_items_enum_type) 4919)
#define  NV_DVBH_UHF_BAND_FREQ_RANGE_AND_OFFSET_2_I    ((nv_items_enum_type) 4920)
#define  NV_DVBH_CELL_ID_RANGE_I                       ((nv_items_enum_type) 4921)
#define  NV_JCDMA_RUIM_ID_I                            ((nv_items_enum_type) 4922)
#define  NV_JCDMA_UIM_LOCK_I                           ((nv_items_enum_type) 4923)
#define  NV_DIAG_FTM_MODE_SWITCH_I                     ((nv_items_enum_type) 4924)
#define  NV_DHCP4_OPTIONS_MASK_I                       ((nv_items_enum_type) 4925)
#define  NV_DHCP6_OPTIONS_MASK_I                       ((nv_items_enum_type) 4926)
#define  NV_GPS1_XTRA_TIME_INFO_ENABLED_I              ((nv_items_enum_type) 4927)
#define  NV_GPS1_XTRA_TIME_INFO_UNC_THRESH_I           ((nv_items_enum_type) 4928)
#define  NV_GPS1_XTRA_TIME_INFO_DELAY_THRESH_I         ((nv_items_enum_type) 4929)
#define  NV_GPS1_XTRA_PRIMARY_SNTP_SERVER_URL_I        ((nv_items_enum_type) 4930)
#define  NV_GPS1_XTRA_SECONDARY_SNTP_SERVER_URL_I      ((nv_items_enum_type) 4931)
#define  NV_GPS1_XTRA_TERTIARY_SNTP_SERVER_URL_I       ((nv_items_enum_type) 4932)
#define  NV_MF_PROXY_I                                 ((nv_items_enum_type) 4933)
#define  NV_MF_PROXY_LEN_I                             ((nv_items_enum_type) 4934)
#define  NV_WCDMA_1900_C0_C1_DELAY_I                   ((nv_items_enum_type) 4935)
#define  NV_WCDMA_1800_C0_C1_DELAY_I                   ((nv_items_enum_type) 4936)
#define  NV_WCDMA_BC4_C0_C1_DELAY_I                    ((nv_items_enum_type) 4937)
#define  NV_WCDMA_900_C0_C1_DELAY_I                    ((nv_items_enum_type) 4938)
#define  NV_WCDMA_800_C0_C1_DELAY_I                    ((nv_items_enum_type) 4939)
#define  NV_IMS_FW_API_ENABLE_FLAG_I                   ((nv_items_enum_type) 4940)
#define  NV_WCDMA_REL6_TX_BETA_SCALING_COMP_I          ((nv_items_enum_type) 4941)
#define  NV_WCDMA_REL6_TX_AGC_OFFSET_I                 ((nv_items_enum_type) 4942)
#define  NV_WCDMA_REL6_TX_MPR_BACKOFF_I                ((nv_items_enum_type) 4943)
#define  NV_WCDMA_1900_REL6_TX_BETA_SCALING_COMP_I     ((nv_items_enum_type) 4944)
#define  NV_WCDMA_1900_REL6_TX_AGC_OFFSET_I            ((nv_items_enum_type) 4945)
#define  NV_WCDMA_1900_REL6_TX_MPR_BACKOFF_I           ((nv_items_enum_type) 4946)
#define  NV_WCDMA_800_REL6_TX_BETA_SCALING_COMP_I      ((nv_items_enum_type) 4947)
#define  NV_WCDMA_800_REL6_TX_AGC_OFFSET_I             ((nv_items_enum_type) 4948)
#define  NV_WCDMA_800_REL6_TX_MPR_BACKOFF_I            ((nv_items_enum_type) 4949)
#define  NV_WCDMA_BC4_REL6_TX_BETA_SCALING_COMP_I      ((nv_items_enum_type) 4950)
#define  NV_WCDMA_BC4_REL6_TX_AGC_OFFSET_I             ((nv_items_enum_type) 4951)
#define  NV_WCDMA_BC4_REL6_TX_MPR_BACKOFF_I            ((nv_items_enum_type) 4952)
#define  NV_XO_FIELD_CALIBRATION_I                     ((nv_items_enum_type) 4953)
#define  NV_XO_FACTORY_CALIBRATION_I                   ((nv_items_enum_type) 4954)
#define  NV_XO_CAL_CONV_I                              ((nv_items_enum_type) 4955)
#define  NV_WCDMA_LNA_PHASE_CTL_I                      ((nv_items_enum_type) 4956)
#define  NV_C1_WCDMA_LNA_PHASE_CTL_I                   ((nv_items_enum_type) 4957)
#define  NV_HOME_MCC_I                                 ((nv_items_enum_type) 4958)
#define  NV_USR_SID_TO_MCC_ASSOC_TBL_I                 ((nv_items_enum_type) 4959)
#define  NV_HS_BASED_PLUS_DIAL_SETTING_I               ((nv_items_enum_type) 4960)
#define  NV_DS_AT_V250_REGISTERS_I                     ((nv_items_enum_type) 4961)
#define  NV_DS_AT_S_REGISTERS_I                        ((nv_items_enum_type) 4962)
#define  NV_PROCESS_RESTART_SWITCH_I                   ((nv_items_enum_type) 4963)
#define  NV_HDRSCP_FORCE_AT_CONFIG_I                   ((nv_items_enum_type) 4964)
#define  NV_WCDMA_TX_COMP_VS_FREQ_0_SECONDARY_I        ((nv_items_enum_type) 4965)
#define  NV_WCDMA_TX_COMP_VS_FREQ_1_SECONDARY_I        ((nv_items_enum_type) 4966)
#define  NV_WCDMA_TX_COMP_VS_FREQ_2_SECONDARY_I        ((nv_items_enum_type) 4967)
#define  NV_WCDMA_TX_COMP_VS_FREQ_3_SECONDARY_I        ((nv_items_enum_type) 4968)
#define  NV_WCDMA_TX_COMP_VS_FREQ_SEC_PDM_LIST_I       ((nv_items_enum_type) 4969)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_0_SECONDARY_I   ((nv_items_enum_type) 4970)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_1_SECONDARY_I   ((nv_items_enum_type) 4971)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_2_SECONDARY_I   ((nv_items_enum_type) 4972)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_3_SECONDARY_I   ((nv_items_enum_type) 4973)
#define  NV_WCDMA_1900_TX_COMP_VS_FREQ_SEC_PDM_LIST_I  ((nv_items_enum_type) 4974)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_0_SECONDARY_I    ((nv_items_enum_type) 4975)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_1_SECONDARY_I    ((nv_items_enum_type) 4976)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_2_SECONDARY_I    ((nv_items_enum_type) 4977)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_3_SECONDARY_I    ((nv_items_enum_type) 4978)
#define  NV_WCDMA_800_TX_COMP_VS_FREQ_SEC_PDM_LIST_I   ((nv_items_enum_type) 4979)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_0_SECONDARY_I   ((nv_items_enum_type) 4980)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_1_SECONDARY_I   ((nv_items_enum_type) 4981)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_2_SECONDARY_I   ((nv_items_enum_type) 4982)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_3_SECONDARY_I   ((nv_items_enum_type) 4983)
#define  NV_WCDMA_1800_TX_COMP_VS_FREQ_SEC_PDM_LIST_I  ((nv_items_enum_type) 4984)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_0_SECONDARY_I    ((nv_items_enum_type) 4985)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_1_SECONDARY_I    ((nv_items_enum_type) 4986)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_2_SECONDARY_I    ((nv_items_enum_type) 4987)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_3_SECONDARY_I    ((nv_items_enum_type) 4988)
#define  NV_WCDMA_BC4_TX_COMP_VS_FREQ_SEC_PDM_LIST_I   ((nv_items_enum_type) 4989)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_0_SECONDARY_I    ((nv_items_enum_type) 4990)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_1_SECONDARY_I    ((nv_items_enum_type) 4991)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_2_SECONDARY_I    ((nv_items_enum_type) 4992)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_3_SECONDARY_I    ((nv_items_enum_type) 4993)
#define  NV_WCDMA_900_TX_COMP_VS_FREQ_SEC_PDM_LIST_I   ((nv_items_enum_type) 4994)
#define  NV_CUST_UQCN_C2K_VERSION_I                    ((nv_items_enum_type) 4995)
#define  NV_CUST_UQCN_UMTS_VERSION_I                   ((nv_items_enum_type) 4996)
#define  NV_BC0_TX_PWR_COMP0_I                         ((nv_items_enum_type) 4997)
#define  NV_BC0_TX_PWR_COMP1_I                         ((nv_items_enum_type) 4998)
#define  NV_BC0_TX_PWR_COMP2_I                         ((nv_items_enum_type) 4999)
#define  NV_BC0_TX_PWR_COMP3_I                         ((nv_items_enum_type) 5000)
#define  NV_BC1_TX_PWR_COMP0_I                         ((nv_items_enum_type) 5001)
#define  NV_BC1_TX_PWR_COMP1_I                         ((nv_items_enum_type) 5002)
#define  NV_BC1_TX_PWR_COMP2_I                         ((nv_items_enum_type) 5003)
#define  NV_BC1_TX_PWR_COMP3_I                         ((nv_items_enum_type) 5004)
#define  NV_BC3_TX_PWR_COMP0_I                         ((nv_items_enum_type) 5005)
#define  NV_BC3_TX_PWR_COMP1_I                         ((nv_items_enum_type) 5006)
#define  NV_BC3_TX_PWR_COMP2_I                         ((nv_items_enum_type) 5007)
#define  NV_BC3_TX_PWR_COMP3_I                         ((nv_items_enum_type) 5008)
#define  NV_BC5_TX_PWR_COMP0_I                         ((nv_items_enum_type) 5009)
#define  NV_BC5_TX_PWR_COMP1_I                         ((nv_items_enum_type) 5010)
#define  NV_BC5_TX_PWR_COMP2_I                         ((nv_items_enum_type) 5011)
#define  NV_BC5_TX_PWR_COMP3_I                         ((nv_items_enum_type) 5012)
#define  NV_BC6_TX_PWR_COMP0_I                         ((nv_items_enum_type) 5013)
#define  NV_BC6_TX_PWR_COMP1_I                         ((nv_items_enum_type) 5014)
#define  NV_BC6_TX_PWR_COMP2_I                         ((nv_items_enum_type) 5015)
#define  NV_BC6_TX_PWR_COMP3_I                         ((nv_items_enum_type) 5016)
#define  NV_BC11_TX_PWR_COMP0_I                        ((nv_items_enum_type) 5017)
#define  NV_BC11_TX_PWR_COMP1_I                        ((nv_items_enum_type) 5018)
#define  NV_BC11_TX_PWR_COMP2_I                        ((nv_items_enum_type) 5019)
#define  NV_BC11_TX_PWR_COMP3_I                        ((nv_items_enum_type) 5020)
#define  NV_BC14_TX_PWR_COMP0_I                        ((nv_items_enum_type) 5021)
#define  NV_BC14_TX_PWR_COMP1_I                        ((nv_items_enum_type) 5022)
#define  NV_BC14_TX_PWR_COMP2_I                        ((nv_items_enum_type) 5023)
#define  NV_BC14_TX_PWR_COMP3_I                        ((nv_items_enum_type) 5024)
#define  NV_BC15_TX_PWR_COMP0_I                        ((nv_items_enum_type) 5025)
#define  NV_BC15_TX_PWR_COMP1_I                        ((nv_items_enum_type) 5026)
#define  NV_BC15_TX_PWR_COMP2_I                        ((nv_items_enum_type) 5027)
#define  NV_BC15_TX_PWR_COMP3_I                        ((nv_items_enum_type) 5028)
#define  NV_THERM_BINS_I                               ((nv_items_enum_type) 5029)
#define  NV_BC4_TX_PWR_COMP0_I                         ((nv_items_enum_type) 5030)
#define  NV_BC4_TX_PWR_COMP1_I                         ((nv_items_enum_type) 5031)
#define  NV_BC4_TX_PWR_COMP2_I                         ((nv_items_enum_type) 5032)
#define  NV_BC4_TX_PWR_COMP3_I                         ((nv_items_enum_type) 5033)
#define  NV_CGPS_QOS_OVERRIDE_ACC_THRESHOLD_I          ((nv_items_enum_type) 5034)
#define  NV_CGPS_QOS_OVERRIDE_TIME_I                   ((nv_items_enum_type) 5035)
#define  NV_WEB_INFO_I                                 ((nv_items_enum_type) 5036)
#define  NV_SIOTA_CALL_INFO_I                          ((nv_items_enum_type) 5037)
#define  NV_PHONE_BOOT_NAIURL_I                        ((nv_items_enum_type) 5038)
#define  NV_PHONE_BOOT_URL_I                           ((nv_items_enum_type) 5039)
#define  NV_DS_PHONE_RDF_URL_I                         ((nv_items_enum_type) 5040)
#define  NV_BROWSER_DOMAIN_TRUSTED_I                   ((nv_items_enum_type) 5041)
#define  NV_IOTA_COMMIT_I                              ((nv_items_enum_type) 5042)
#define  NV_DVBH_NIT_ACTUAL_ACQ_TIMEOUT_I              ((nv_items_enum_type) 5043)
#define  NV_HS_USB_DIAG_ON_LEGACY_USB_PORT_I           ((nv_items_enum_type) 5044)
#define  NV_HW_ENTROPY_I                               ((nv_items_enum_type) 5045)
#define  NV_CGPS_MEM_CONFIG_I                          ((nv_items_enum_type) 5046)
#define  NV_CGPS_NMEA_CONFIG_INFO_I                    ((nv_items_enum_type) 5047)
#define  NV_WCDMA_800_TIMER_HYSTERISIS_I               ((nv_items_enum_type) 5048)
#define  NV_WCDMA_900_TIMER_HYSTERISIS_I               ((nv_items_enum_type) 5049)
#define  NV_WCDMA_BC4_TIMER_HYSTERISIS_I               ((nv_items_enum_type) 5050)
#define  NV_WCDMA_1800_TIMER_HYSTERISIS_I              ((nv_items_enum_type) 5051)
#define  NV_WCDMA_1900_TIMER_HYSTERISIS_I              ((nv_items_enum_type) 5052)
#define  NV_WCDMA_2100_TIMER_HYSTERISIS_I              ((nv_items_enum_type) 5053)
#define  NV_WCDMA_800_TX_LIN_MASTER_0_ENH_I            ((nv_items_enum_type) 5054)
#define  NV_WCDMA_900_TX_LIN_MASTER_0_ENH_I            ((nv_items_enum_type) 5055)
#define  NV_WCDMA_BC4_TX_LIN_MASTER_0_ENH_I            ((nv_items_enum_type) 5056)
#define  NV_WCDMA_1800_TX_LIN_MASTER_0_ENH_I           ((nv_items_enum_type) 5057)
#define  NV_WCDMA_1900_TX_LIN_MASTER_0_ENH_I           ((nv_items_enum_type) 5058)
#define  NV_WCDMA_2100_TX_LIN_MASTER_0_ENH_I           ((nv_items_enum_type) 5059)
#define  NV_WCDMA_800_TX_PDM_LIN_0_ENH_I               ((nv_items_enum_type) 5060)
#define  NV_WCDMA_900_TX_PDM_LIN_0_ENH_I               ((nv_items_enum_type) 5061)
#define  NV_WCDMA_BC4_TX_PDM_LIN_0_ENH_I               ((nv_items_enum_type) 5062)
#define  NV_WCDMA_1800_TX_PDM_LIN_0_ENH_I              ((nv_items_enum_type) 5063)
#define  NV_WCDMA_1900_TX_PDM_LIN_0_ENH_I              ((nv_items_enum_type) 5064)
#define  NV_WCDMA_2100_TX_PDM_LIN_0_ENH_I              ((nv_items_enum_type) 5065)
#define  NV_GSM_850_KV_CAL_I                           ((nv_items_enum_type) 5066)
#define  NV_GSM_900_KV_CAL_I                           ((nv_items_enum_type) 5067)
#define  NV_GSM_1800_KV_CAL_I                          ((nv_items_enum_type) 5068)
#define  NV_GSM_1900_KV_CAL_I                          ((nv_items_enum_type) 5069)
#define  NV_BC1_BALUN_CTL_I                            ((nv_items_enum_type) 5070)
#define  NV_BC2_BALUN_CTL_I                            ((nv_items_enum_type) 5071)
#define  NV_BC3_BALUN_CTL_I                            ((nv_items_enum_type) 5072)
#define  NV_BC4_BALUN_CTL_I                            ((nv_items_enum_type) 5073)
#define  NV_BC6_BALUN_CTL_I                            ((nv_items_enum_type) 5074)
#define  NV_BC8_BALUN_CTL_I                            ((nv_items_enum_type) 5075)
#define  NV_BC9_BALUN_CTL_I                            ((nv_items_enum_type) 5076)
#define  NV_UNDP_HSU_VID_PID_I                         ((nv_items_enum_type) 5077)
#define  NV_UNDP_HSU_MFGSTR_I                          ((nv_items_enum_type) 5078)
#define  NV_UNDP_HSU_PRODSTR_I                         ((nv_items_enum_type) 5079)
#define  NV_GSM_850_SMPS_PDM_TBL_I					 ((nv_items_enum_type) 5091)
#define  NV_GSM_900_SMPS_PDM_TBL_I                     ((nv_items_enum_type) 5092)
#define  NV_GSM_1800_SMPS_PDM_TBL_I					 ((nv_items_enum_type) 5093)
#define  NV_GSM_1900_SMPS_PDM_TBL_I				     ((nv_items_enum_type) 5094)
#define  NV_BC10_GPS1_RF_DELAY_I                       ((nv_items_enum_type) 5167)
#define  NV_GSM_850_PADAC_DC_OFFSET_I                  ((nv_items_enum_type) 5285)
#define  NV_GSM_900_PADAC_DC_OFFSET_I                  ((nv_items_enum_type) 5286)
#define  NV_GSM_1800_PADAC_DC_OFFSET_I                 ((nv_items_enum_type) 5287)
#define  NV_GSM_1900_PADAC_DC_OFFSET_I                 ((nv_items_enum_type) 5288)
#define  NV_GSM_850_RGI_G0_F1_I                        ((nv_items_enum_type) 5291)
#define  NV_GSM_850_RGI_G1_F1_I                        ((nv_items_enum_type) 5292)
#define  NV_GSM_850_RGI_G2_F1_I                        ((nv_items_enum_type) 5293)
#define  NV_GSM_850_RGI_G3_F1_I                        ((nv_items_enum_type) 5294)
#define  NV_GSM_850_RGI_G0_F2_I                        ((nv_items_enum_type) 5295)
#define  NV_GSM_850_RGI_G1_F2_I                        ((nv_items_enum_type) 5296)
#define  NV_GSM_850_RGI_G2_F2_I                        ((nv_items_enum_type) 5297)
#define  NV_GSM_850_RGI_G3_F2_I                        ((nv_items_enum_type) 5298)
#define  NV_GSM_900_RGI_G0_F1_I                        ((nv_items_enum_type) 5299)
#define  NV_GSM_900_RGI_G1_F1_I                        ((nv_items_enum_type) 5300)
#define  NV_GSM_900_RGI_G2_F1_I                        ((nv_items_enum_type) 5301)
#define  NV_GSM_900_RGI_G3_F1_I                        ((nv_items_enum_type) 5302)
#define  NV_GSM_900_RGI_G0_F2_I                        ((nv_items_enum_type) 5303)
#define  NV_GSM_900_RGI_G1_F2_I                        ((nv_items_enum_type) 5304)
#define  NV_GSM_900_RGI_G2_F2_I                        ((nv_items_enum_type) 5305)
#define  NV_GSM_900_RGI_G3_F2_I                        ((nv_items_enum_type) 5306)
#define  NV_GSM_1800_RGI_G0_F1_I                       ((nv_items_enum_type) 5307)
#define  NV_GSM_1800_RGI_G1_F1_I                       ((nv_items_enum_type) 5308)
#define  NV_GSM_1800_RGI_G2_F1_I                       ((nv_items_enum_type) 5309)
#define  NV_GSM_1800_RGI_G3_F1_I                       ((nv_items_enum_type) 5310)
#define  NV_GSM_1800_RGI_G0_F2_I                       ((nv_items_enum_type) 5311)
#define  NV_GSM_1800_RGI_G1_F2_I                       ((nv_items_enum_type) 5312)
#define  NV_GSM_1800_RGI_G2_F2_I                       ((nv_items_enum_type) 5313)
#define  NV_GSM_1800_RGI_G3_F2_I                       ((nv_items_enum_type) 5314)
#define  NV_GSM_1900_RGI_G0_F1_I                       ((nv_items_enum_type) 5315)
#define  NV_GSM_1900_RGI_G1_F1_I                       ((nv_items_enum_type) 5316)
#define  NV_GSM_1900_RGI_G2_F1_I                       ((nv_items_enum_type) 5317)
#define  NV_GSM_1900_RGI_G3_F1_I                       ((nv_items_enum_type) 5318)
#define  NV_GSM_1900_RGI_G0_F2_I                       ((nv_items_enum_type) 5319)
#define  NV_GSM_1900_RGI_G1_F2_I                       ((nv_items_enum_type) 5320)
#define  NV_GSM_1900_RGI_G2_F2_I                       ((nv_items_enum_type) 5321)
#define  NV_GSM_1900_RGI_G3_F2_I                       ((nv_items_enum_type) 5322)
#define  NV_GSM_850_PMEAS_G0_F1_I                      ((nv_items_enum_type) 5323)
#define  NV_GSM_850_PMEAS_G1_F1_I                      ((nv_items_enum_type) 5324)
#define  NV_GSM_850_PMEAS_G2_F1_I                      ((nv_items_enum_type) 5325)
#define  NV_GSM_850_PMEAS_G3_F1_I                      ((nv_items_enum_type) 5326)
#define  NV_GSM_850_PMEAS_G0_F2_I                      ((nv_items_enum_type) 5327)
#define  NV_GSM_850_PMEAS_G1_F2_I                      ((nv_items_enum_type) 5328)
#define  NV_GSM_850_PMEAS_G2_F2_I                      ((nv_items_enum_type) 5329)
#define  NV_GSM_850_PMEAS_G3_F2_I                      ((nv_items_enum_type) 5330)
#define  NV_GSM_900_PMEAS_G0_F1_I                      ((nv_items_enum_type) 5331)
#define  NV_GSM_900_PMEAS_G1_F1_I                      ((nv_items_enum_type) 5332)
#define  NV_GSM_900_PMEAS_G2_F1_I                      ((nv_items_enum_type) 5333)
#define  NV_GSM_900_PMEAS_G3_F1_I                      ((nv_items_enum_type) 5334)
#define  NV_GSM_900_PMEAS_G0_F2_I                      ((nv_items_enum_type) 5335)
#define  NV_GSM_900_PMEAS_G1_F2_I                      ((nv_items_enum_type) 5336)
#define  NV_GSM_900_PMEAS_G2_F2_I                      ((nv_items_enum_type) 5337)
#define  NV_GSM_900_PMEAS_G3_F2_I                      ((nv_items_enum_type) 5338)
#define  NV_GSM_1800_PMEAS_G0_F1_I                     ((nv_items_enum_type) 5339)
#define  NV_GSM_1800_PMEAS_G1_F1_I                     ((nv_items_enum_type) 5340)
#define  NV_GSM_1800_PMEAS_G2_F1_I                     ((nv_items_enum_type) 5341)
#define  NV_GSM_1800_PMEAS_G3_F1_I                     ((nv_items_enum_type) 5342)
#define  NV_GSM_1800_PMEAS_G0_F2_I                     ((nv_items_enum_type) 5343)
#define  NV_GSM_1800_PMEAS_G1_F2_I                     ((nv_items_enum_type) 5344)
#define  NV_GSM_1800_PMEAS_G2_F2_I                     ((nv_items_enum_type) 5345)
#define  NV_GSM_1800_PMEAS_G3_F2_I                     ((nv_items_enum_type) 5346)
#define  NV_GSM_1900_PMEAS_G0_F1_I                     ((nv_items_enum_type) 5347)
#define  NV_GSM_1900_PMEAS_G1_F1_I                     ((nv_items_enum_type) 5348)
#define  NV_GSM_1900_PMEAS_G2_F1_I                     ((nv_items_enum_type) 5349)
#define  NV_GSM_1900_PMEAS_G3_F1_I                     ((nv_items_enum_type) 5350)
#define  NV_GSM_1900_PMEAS_G0_F2_I                     ((nv_items_enum_type) 5351)
#define  NV_GSM_1900_PMEAS_G1_F2_I                     ((nv_items_enum_type) 5352)
#define  NV_GSM_1900_PMEAS_G2_F2_I                     ((nv_items_enum_type) 5353)
#define  NV_GSM_1900_PMEAS_G3_F2_I                     ((nv_items_enum_type) 5354)
#define  NV_GSM_1800_PA_R1_TO_R2_I                     ((nv_items_enum_type) 5355)
#define  NV_GSM_1800_PA_R2_TO_R4_I                     ((nv_items_enum_type) 5356)
#define  NV_GSM_1900_PA_R1_TO_R2_I                     ((nv_items_enum_type) 5357)
#define  NV_GSM_1900_PA_R2_TO_R4_I                     ((nv_items_enum_type) 5358)
#define  NV_GSM_850_PA_R1_TO_R2_I                      ((nv_items_enum_type) 5359)
#define  NV_GSM_850_PA_R2_TO_R3_I                      ((nv_items_enum_type) 5360)
#define  NV_GSM_850_PA_R3_TO_R4_I                      ((nv_items_enum_type) 5361)
#define  NV_GSM_900_PA_R1_TO_R2_I                      ((nv_items_enum_type) 5362)
#define  NV_GSM_900_PA_R2_TO_R3_I                      ((nv_items_enum_type) 5363)
#define  NV_GSM_900_PA_R3_TO_R4_I                      ((nv_items_enum_type) 5364)
#define  NV_GSM_850_PA_PREDIST_SWPT1_I                 ((nv_items_enum_type) 5365)
#define  NV_GSM_850_PA_PREDIST_SWPT2_I                 ((nv_items_enum_type) 5366)
#define  NV_GSM_900_PA_PREDIST_SWPT1_I                 ((nv_items_enum_type) 5367)
#define  NV_GSM_900_PA_PREDIST_SWPT2_I                 ((nv_items_enum_type) 5368)
#define  NV_GSM_1800_PA_PREDIST_SWPT1_I                ((nv_items_enum_type) 5369)
#define  NV_GSM_1800_PA_PREDIST_SWPT2_I                ((nv_items_enum_type) 5370)
#define  NV_GSM_1900_PA_PREDIST_SWPT1_I                ((nv_items_enum_type) 5371)
#define  NV_GSM_1900_PA_PREDIST_SWPT2_I                ((nv_items_enum_type) 5372)
#define  NV_GSM_LINEAR_TX_GAIN_PARAM_I                 ((nv_items_enum_type) 5477)
#define  NV_EDGE_LINEAR_TX_GAIN_PARAM_I                ((nv_items_enum_type) 5478)
#define  NV_BCX_BLOCK_1_GPS1_RF_DELAY_I				    ((nv_items_enum_type) 6054)
#define  NV_GSM_850_LINEAR_TX_GAIN_PARAM_I             ((nv_items_enum_type) 6472)
#define  NV_GSM_1800_LINEAR_TX_GAIN_PARAM_I            ((nv_items_enum_type) 6473)
#define  NV_GSM_1900_LINEAR_TX_GAIN_PARAM_I            ((nv_items_enum_type) 6474)
#define  NV_EDGE_850_LINEAR_TX_GAIN_PARAM_I            ((nv_items_enum_type) 6475)
#define  NV_EDGE_1800_LINEAR_TX_GAIN_PARAM_I           ((nv_items_enum_type) 6476)
#define  NV_EDGE_1900_LINEAR_TX_GAIN_PARAM_I           ((nv_items_enum_type) 6477)
// New NV Items for Gen 8 GNSS
#define  NV_GPS1_GNSS_RXD_ENABLE_I					   ((nv_items_enum_type) 6758)
#define  NV_GPS1_GNSS_SYS_CONTROL_I					   ((nv_items_enum_type) 6759)
// #define  NV_GPS1_GNSS_HBW_CONTROL_I					((nv_items_enum_type) ????)
#define  NV_GPS1_GNSS_GLO_CONTROL_I					   ((nv_items_enum_type) 6760)
#define  NV_GPS1_GNSS_RXD_RF_LOSS_I					   ((nv_items_enum_type) 6761)
#define  NV_GPS1_GNSS_HBW_RF_LOSS_I					   ((nv_items_enum_type) 6762)
#define  NV_GPS1_GNSS_GLO_RF_LOSS_CENTER_7_I			((nv_items_enum_type) 6763)
#define  NV_GPS1_GNSS_GLO_RF_LOSS_CENTER_0_I			((nv_items_enum_type) 6764)
#define  NV_GPS1_GNSS_GLO_RF_LOSS_CENTER_6_I			((nv_items_enum_type) 6765)
#define  NV_GPS1_GNSS_LBW_RXD_GROUP_DELAY_DIFF_I	((nv_items_enum_type) 6766)
#define  RFNV_GSM_850_CHAR_PREDIST_ENV_GAIN_I      ((nv_items_enum_type) 24194)
#define  RFNV_GSM_900_CHAR_PREDIST_ENV_GAIN_I      ((nv_items_enum_type) 24195)
#define  RFNV_GSM_1800_CHAR_PREDIST_ENV_GAIN_I     ((nv_items_enum_type) 24196)
#define  RFNV_GSM_1900_CHAR_PREDIST_ENV_GAIN_I     ((nv_items_enum_type) 24197)
// GSM Tx Cal Data NVs
#define  RFNV_GSM_C0_GSM850_TX_CAL_DATA_I         ((nv_items_enum_type) 24972)
#define  RFNV_GSM_C0_GSM900_TX_CAL_DATA_I         ((nv_items_enum_type) 24973)
#define  RFNV_GSM_C0_GSM1800_TX_CAL_DATA_I        ((nv_items_enum_type) 24974)
#define  RFNV_GSM_C0_GSM1900_TX_CAL_DATA_I        ((nv_items_enum_type) 24975)
#define  RFNV_GSM_C2_GSM850_TX_CAL_DATA_I         ((nv_items_enum_type) 24976)
#define  RFNV_GSM_C2_GSM900_TX_CAL_DATA_I         ((nv_items_enum_type) 24977)
#define  RFNV_GSM_C2_GSM1800_TX_CAL_DATA_I        ((nv_items_enum_type) 24978)
#define  RFNV_GSM_C2_GSM1900_TX_CAL_DATA_I        ((nv_items_enum_type) 24979)
// GSM power control levels (PCL)
#define  RFNV_GSM_C0_GSM850_POWER_LEVELS_I         ((nv_items_enum_type) 25076)
#define  RFNV_GSM_C0_GSM900_POWER_LEVELS_I         ((nv_items_enum_type) 25077)
#define  RFNV_GSM_C0_GSM1800_POWER_LEVELS_I        ((nv_items_enum_type) 25078)
#define  RFNV_GSM_C0_GSM1900_POWER_LEVELS_I        ((nv_items_enum_type) 25079)
#define  RFNV_GSM_C2_GSM850_POWER_LEVELS_I         ((nv_items_enum_type) 25080)
#define  RFNV_GSM_C2_GSM900_POWER_LEVELS_I         ((nv_items_enum_type) 25081)
#define  RFNV_GSM_C2_GSM1800_POWER_LEVELS_I        ((nv_items_enum_type) 25082)
#define  RFNV_GSM_C2_GSM1900_POWER_LEVELS_I        ((nv_items_enum_type) 25083)
// GSM Temp Comp Therm Read NVs
#define  RFNV_GSM_C0_GSM850_CAL_THERM_READ_I       ((nv_items_enum_type) 27911)
#define  RFNV_GSM_C0_GSM900_CAL_THERM_READ_I       ((nv_items_enum_type) 27912)
#define  RFNV_GSM_C0_GSM1800_CAL_THERM_READ_I      ((nv_items_enum_type) 27913)
#define  RFNV_GSM_C0_GSM1900_CAL_THERM_READ_I      ((nv_items_enum_type) 27914)
#define  RFNV_GSM_C2_GSM850_CAL_THERM_READ_I       ((nv_items_enum_type) 27915)
#define  RFNV_GSM_C2_GSM900_CAL_THERM_READ_I       ((nv_items_enum_type) 27916)
#define  RFNV_GSM_C2_GSM1800_CAL_THERM_READ_I      ((nv_items_enum_type) 27917)
#define  RFNV_GSM_C2_GSM1900_CAL_THERM_READ_I      ((nv_items_enum_type) 27918)

#define  NV_GPS1_GNSS_BDS_RF_LOSS_I                ((nv_items_enum_type) 70325)

#define RFNV_PCL_NUM_ITEMS          16    // the number of elements in RFNV_GSM_Cx_GSMxxxx_POWER_LEVELS_I
#define RFNV_ENV_GAIN_ITEMS         16    // number of elemements in the RFNV_GSM_*_CHAR_PREDIST_ENV_GAIN_I array.
#define RFNV_ENV_GAIN_SIZE          64    // number of elemements in the RFNV_GSM_*_CHAR_PREDIST_ENV_GAIN_I array.
#define RFNV_ENV_GAIN_MODE_BEGIN    2     // mode index corresponding to RFNV_GSM_*_CHAR_PREDIST_ENV_GAIN_I[0]

#define  NV_MAX_I                                      ((nv_items_enum_type) 6769)



/*=========================================================================*/
/* NVM Items Type Definitions.                                             */
/*=========================================================================*/

/* Type for generic minimum/maximum type */
typedef PACKED struct
{
   /* minimum */
   byte                                             min;
   /* maximum */
   byte                                             max;
} nv_minmax_type;

/* Type to hold security code. */
/*
 * The security code is fixed length and is stored as ASCII string.
 */
typedef PACKED struct
{
   /* Security code array */
   byte                                             digits[NV_SEC_CODE_SIZE];
} nv_sec_code_type;

/* Generic enabled/disabled per NAM type */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Enabled flag */
   byte                                             enabled;
} nv_enabled_type;

/* Type to hold authentication A key and the associated NAM id. */
/*
 * The number is 64 bits per IS-54 appendix A (CAI Appendix X).
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* A key array */
   qword                                            key;
} nv_a_key_type;

/* Type to hold authentication A key 16 bit CRC chksum. */
/*
 * The checksum is generated with a generator polynomial
 * as used for CDMA reverse and forward traffic signaling messages,
 * per CAI sections 6.7.2.2.2 and 7.8.3.2. Exact security and protection
 * of the A-Key is for now TBD.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Chcksum */
   word                                             chksum;
} nv_a_key_chksum_type;

/* Type to hold SSD (A or B) variable and the associated NAM id. */
/*
 * Each SSD is 64 bits, per CAI sections 2.3.12.1.1 and 6.3.12.1.1
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* SSD array */
   qword                                            ssd;
} nv_ssd_type;

/* Type to hold SSD (A or B) 16 bit CRC checksum */
/*
 * The checksum is generated with a generator polynomial as used
 * for CDMA reverse and forward traffic signaling messages, per CAI sections
 * 6.7.2.2.2 and 7.7.3.2
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Chcksum */
   word                                             chksum;
} nv_ssd_chksum_type;

/* Type to hold user id for Password Authentication Protocol */
typedef PACKED struct
{
   /* Length of user_id */
   byte                                             user_id_len;
   /* The user_id */
   byte                                             user_id[NV_MAX_PAP_USER_ID_LENGTH];
} nv_pap_user_id_type;

/* Type to hold password for Password Authentication Protocol */
typedef PACKED struct
{
   /* Length of Password */
   byte                                             password_len;
   /* The Password */
   byte                                             password[NV_MAX_PAP_PASSWORD_LENGTH];
} nv_pap_password_type;

/* Type to hold simple IP PPP password */
typedef PACKED struct
{
   /* Length of Password */
   byte                                             password_len;
   /* The Password */
   byte                                             password[NV_MAX_PPP_PASSWORD_LENGTH];
} nv_ppp_password_type;

/* Type to hold user id for PPP authentication */
typedef PACKED struct
{
   /* Length of user id */
   byte                                             user_id_len;
   /* The user id */
   byte                                             user_id[NV_MAX_PPP_USER_ID_LENGTH];
} nv_ppp_user_id_type;

/* Type for NV_SEC_DEVICE_KEY_I */
typedef PACKED struct
{

   uint8                                            device_key_len;

   uint8                                            device_key_data[NV_SEC_DEVICE_KEY_MAX_LEN];
} nv_sec_device_key_type;

/* Type to hold ESN */
/*
 * The ESN and its checksum are write-once protected and the NV
 * task will not write to NV an ESN or its checksum if the stored ESN or its
 * checksum are non-zero
 */
typedef PACKED struct
{
   /* esn */
   dword                                            esn;
} nv_esn_type;

/* Type to hold ESN checksum */
/*
 * The checksum is 30 bit CRC with generator polynomial as used for
 * CDMA sync channel signalling, per CAI section 7.7.1.2.2. The ESN
 * and its checksum are write-once proteted and the NV task will not
 * write to NV an ESN or its checksum if the stored ESN, or its checksum
 * or the internal valid flag are not valid. This item can be written
 * only once internally, by the NV task.
 * The status of this item can be read externally by other tasks to verify
 * that the ESN has been correctly programmed to NV.
 */
typedef PACKED struct
{
   /* esn chksum */
   dword                                            chksum;
} nv_esn_chksum_type;

/* Type to hold configuration checksum */
/*
 * The checksum is a simple 0xFFFF marker which indicates that
 * configuration parameters have been programmed and are valid
 */
typedef PACKED struct
{
   /* Config checksum */
   word                                             chksum;
} nv_config_chksum_type;

/* Type to hold NAM data checksum. */
/*
 * The checksum is a simple 0xFFFF marker which is set to
 * indicate that NAM parameters have been programmed and are valid.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* The checksum */
   word                                             chksum;
} nv_nam_chksum_type;

/* Type to hold run timer, with units as shown. */
/*
 * The range is a zillion years.
 * Timer             units
 * -----             -----
 * Run Time          minutes
 */
typedef PACKED struct
{
   /* hold the run timer */
   dword                                            time;
} nv_run_time_type;

/* Type to hold maintenance order and reason code */
/*
 * Maintenance reason is per IS-95 section 7.7.4
 */
typedef PACKED struct
{
   /* Set when maintenance order received */
   boolean                                          maint_order;
   /* Maintenance reason received in the order */
   byte                                             maint_reason;
} nv_maintrsn_type;

/* Type to hold lock order and reason code */
/*
 * Lock reason is per IS-95 section 7.7.4
 */
typedef PACKED struct
{
   /* Set when lock order received and until unlocked */
   boolean                                          lock_order;
   /* Lock reason received in the order */
   byte                                             lock_reason;
} nv_lckrsn_type;

/* Type to hold error log. */
/*
 * Up to NV_MAX_ERR_LOG error codes are stored, each with number of times
 * detected, file name, and line number
 */
typedef PACKED struct
{
   /* Storage address from 0 to NV_MAX_ERR_LOG-1 */
   byte                                             address;
   /* Number of occurrences (0=full, FF=empty) */
   byte                                             err_count;
   /* File name string */
   byte                                             file_name[NV_ERR_FILE_NAME_LEN];
   /* Line number in file */
   word                                             line_num;
   /* TRUE if fatal error */
   boolean                                          fatal;
} nv_err_log_type;

/* Type to hold Field Service Code */
/*
 * Fixed length and is stored as ASCII string.
 */
typedef PACKED struct
{
   /* Field Service Code */
   byte                                             fsc[NV_FSC_SIZ];
} nv_fsc_type;

/* Type to hold fsc2 */
typedef PACKED struct
{
   /* fsc2 */
   dword                                            fsc2;
} nv_fsc2_type;

/* Type to hold fsc2 checksum */
typedef PACKED struct
{
   /* fsc2_chksum */
   dword                                            fsc2_chksum;
} nv_fsc2_chksum_type;

/* Type to hold warranty date code and changes */
typedef PACKED struct
{
   /* Warranty date code */
   byte                                             wdc[NV_WDC_LTRS];
   /* in case the wdc def. changes */
   byte                                             extra[3];
} nv_wdc_type;

/* Type for rental timer */
typedef PACKED struct
{
   /* total number of ticks of the clock */
   dword                                            ticks;
} nv_rental_timer_type;

/* Type for Peek operation */
typedef PACKED struct
{
   /* Where to start peek from */
   word                                             address;
   /* How many bytes to peek */
   byte                                             length;
   /* Returned peek data */
   byte                                             mem[NV_MAX_PEEK_SIZE];
} nv_peek_type;

/* Type for Poke operation */
typedef PACKED struct
{
   /* Where to start poke */
   word                                             address;
   /* How many bytes to poke */
   byte                                             length;
   /* poke data */
   byte                                             mem[NV_MAX_POKE_SIZE];
} nv_poke_type;

/* UP encryption key */
typedef PACKED struct
{
   /* UP link info table index */
   byte                                             index;
   /* Access key */
   byte                                             key[NV_UP_MAX_KEY_SIZE];
} nv_up_key_type;

/* DATA SERVICES default SIO baud rate */
typedef  word  nv_sio_baudrate_type;

#define  NV_SIO_BAUDRATE_AUTO                          ((nv_sio_baudrate_type)0)

#define  NV_SIO_BAUDRATE_45                            ((nv_sio_baudrate_type)1)

#define  NV_SIO_BAUDRATE_50                            ((nv_sio_baudrate_type)2)

#define  NV_SIO_BAUDRATE_75                            ((nv_sio_baudrate_type)3)

#define  NV_SIO_BAUDRATE_110                           ((nv_sio_baudrate_type)4)

#define  NV_SIO_BAUDRATE_150                           ((nv_sio_baudrate_type)5)

#define  NV_SIO_BAUDRATE_300                           ((nv_sio_baudrate_type)6)

#define  NV_SIO_BAUDRATE_600                           ((nv_sio_baudrate_type)7)

#define  NV_SIO_BAUDRATE_1200                          ((nv_sio_baudrate_type)8)

#define  NV_SIO_BAUDRATE_2400                          ((nv_sio_baudrate_type)9)

#define  NV_SIO_BAUDRATE_4800                          ((nv_sio_baudrate_type)10)

#define  NV_SIO_BAUDRATE_9600                          ((nv_sio_baudrate_type)11)

#define  NV_SIO_BAUDRATE_14400                         ((nv_sio_baudrate_type)12)

#define  NV_SIO_BAUDRATE_19200                         ((nv_sio_baudrate_type)13)

#define  NV_SIO_BAUDRATE_38400                         ((nv_sio_baudrate_type)14)

#define  NV_SIO_BAUDRATE_57600                         ((nv_sio_baudrate_type)15)

#define  NV_SIO_BAUDRATE_76800                         ((nv_sio_baudrate_type)16)

#define  NV_SIO_BAUDRATE_115200                        ((nv_sio_baudrate_type)17)

#define  NV_SIO_BAUDRATE_230400                        ((nv_sio_baudrate_type)18)

#define  NV_SIO_BAUDRATE_BEST                          ((nv_sio_baudrate_type)32766)

#define  NV_SIO_BAUDRATE_MAX                           ((nv_sio_baudrate_type)32767)

/* Type of NV_JCDMA_DS_F92_I */
typedef  word  nv_jcdma_ds_f92_enum_type;
/* Async/Fax 9600bps */
#define  NV_JCDMA_DS_F92_ASYNC_FAX_96                  ((nv_jcdma_ds_f92_enum_type)0)
/* Async/Fax 14400bps */
#define  NV_JCDMA_DS_F92_ASYNC_FAX_144                 ((nv_jcdma_ds_f92_enum_type)1)
/* Packet 9600bps */
#define  NV_JCDMA_DS_F92_PACKET_96                     ((nv_jcdma_ds_f92_enum_type)2)
/* Packet 14400bps */
#define  NV_JCDMA_DS_F92_PACKET_144                    ((nv_jcdma_ds_f92_enum_type)3)
/* Packet 64kbps */
#define  NV_JCDMA_DS_F92_PACKET_HIGH                   ((nv_jcdma_ds_f92_enum_type)4)

/* Type for EVRC Priority, EVRC first or 13K first */
typedef  word  nv_evrc_pri_enum_type;
/* Priority: EVRC first */
#define  NV_EVRC_1ST                                   ((nv_evrc_pri_enum_type)0)
/* Priority: 13K first */
#define  NV_EVRC_13K_1ST                               ((nv_evrc_pri_enum_type)1)

/* Enum Type to hold preferred serving system. */
typedef  word  nv_sys_enum_type;
/* A only */
#define  NV_SYS_A_ONLY                                 ((nv_sys_enum_type)0)
/* A then B */
#define  NV_SYS_A_PREF                                 ((nv_sys_enum_type)1)
/* B only */
#define  NV_SYS_B_ONLY                                 ((nv_sys_enum_type)2)
/* B then A */
#define  NV_SYS_B_PREF                                 ((nv_sys_enum_type)3)
/* Home SID only */
#define  NV_SYS_HOME_ONLY                              ((nv_sys_enum_type)4)
/* Home SID preferred */
#define  NV_SYS_HOME_PREF                              ((nv_sys_enum_type)5)

/* Type to hold preferred serving system and the associated NAM. */
/*
 * Type is per CAI section 2.3.10.1.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Preferred system per above enum */
   nv_sys_enum_type                                 sys;
} nv_pref_serv_type;

/* Type to hold SID(s) for lockout. */
/*
 * The phone will reject acquisition if any of these SID(s) is acquired.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* SID */
   word                                             sid[NV_MAX_SID_LOCK];
} nv_sid_lock_type;

/* Type to hold SID(s) for acquisition. */
/*
 * The phone will allow acquisition only on these SID(s).
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* SID */
   word                                             sid[NV_MAX_SID_ACQ];
} nv_sid_acq_type;

/* Type to hold MIN1p for 2 MINs along with the associated NAM id. */
/*
 * The number is 24 bits, per CAI section 2.3.1.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* MIN1 */
   dword                                            min1[NV_MAX_MINS];
} nv_min1_type;

/* Type to hold MIN2p for 2 MINs along with the associated NAM id. */
/*
 * The number is 10 bits, per CAI section 2.3.1.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* MIN2 */
   word                                             min2[NV_MAX_MINS];
} nv_min2_type;

/* Type to hold FIRSTCHPp and associated NAM. */
/*
 * Value is 11 bits, per CAI section 2.3.7.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* FIRSTCHPp channel */
   word                                             channel;
} nv_firstchp_type;

/* Type to hold SID and associated NAM. */
/*
 * The SID is 15 bits, per CAI section 2.3.8.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* SID */
   word                                             sid;
} nv_sid_type;

/* Enumeration for possible registration values. */
typedef  word  nv_analog_reg_enum_type;
/* Autonomous registration disabled */
#define  NV_DISABLED                                   ((nv_analog_reg_enum_type)0)
/* Autonomuos registration enabled, tell location */
#define  NV_WHEREABOUTS_KNOWN                          ((nv_analog_reg_enum_type)1)
/* Autonomous registration enabled, hide location */
#define  NV_WHEREABOUTS_UNKNOWN                        ((nv_analog_reg_enum_type)2)

/* Type to hold analog registration type, along with associated NAM id */
/*
 * Type includes enumeration for possible registration values.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Registration kind per enum above */
   nv_analog_reg_enum_type                          kind;
} nv_analog_reg_type;

/* Type to hold CDMA channel and associated NAM. */
/*
 * Value is 11 bits for Primary and Secondary channels,
 * per CAI section 6.1.1.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* A carrier channel number */
   word                                             channel_a;
   /* B carrier channel number */
   word                                             channel_b;
} nv_cdmach_type;

/* Type to hold last CDMA channel the mobile was on */
/*
 * Value is 11 bits for Primary and Secondary channels,
 * per CAI section 6.1.1.
 */
typedef PACKED struct
{
   /* A carrier channel number */
   word                                             channel_a;
   /* B carrier channel number */
   word                                             channel_b;
} nv_last_cdmach_type;

/* Type to hold CDMA mobile termination type along with associated NAM. */
/*
 * To be used for the MOB_TERM_... variables for registration.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Registration enabled */
   boolean                                          enabled[NV_MAX_MINS];
} nv_mob_term_type;

/* Type for ACCOLCp, along with associated NAM id. */
/*
 * Value is 4 bit, per CAI section 2.3.5
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* ACCLOCp class */
   byte                                             ACCOLCpClass[NV_MAX_MINS];
} nv_accolc_type;

/* Block or System Enum Type */
typedef  word  nv_block_or_sys_enum_type;
/* PCS Block A */
#define  NV_PCS_BLOCK_A                                ((nv_block_or_sys_enum_type)0)
/* PCS Block B */
#define  NV_PCS_BLOCK_B                                ((nv_block_or_sys_enum_type)1)
/* PCS Block C */
#define  NV_PCS_BLOCK_C                                ((nv_block_or_sys_enum_type)2)
/* PCS Block D */
#define  NV_PCS_BLOCK_D                                ((nv_block_or_sys_enum_type)3)
/* PCS Block E */
#define  NV_PCS_BLOCK_E                                ((nv_block_or_sys_enum_type)4)
/* PCS Block F */
#define  NV_PCS_BLOCK_F                                ((nv_block_or_sys_enum_type)5)
/* Cellular System A */
#define  NV_CELLULAR_SYS_A                             ((nv_block_or_sys_enum_type)6)
/* Cellular System B */
#define  NV_CELLULAR_SYS_B                             ((nv_block_or_sys_enum_type)7)
/* Invalid System */
#define  NV_BLOCK_OR_SYS_INVALID                       ((nv_block_or_sys_enum_type)8)
/* PCS Block G */
#define  NV_PCS_BLOCK_G                                ((nv_block_or_sys_enum_type)9)
/* PCS Block H */
#define  NV_PCS_BLOCK_H                                ((nv_block_or_sys_enum_type)10)

/* Type to hold ZONE_LIST, per CAI section 6.3.4. */
typedef PACKED struct
{
   /* REG_ZONEsp */
   word                                             reg_zone;
   /* SIDsp */
   word                                             sid;
   /* NIDsp */
   word                                             nid;
   /* block_or_sys */
   nv_block_or_sys_enum_type                        block_or_sys;
   /* band_class */
   byte                                             band_class;
} nv_zone_list_type;

/* Type to hold SID_NID_LIST, per IS-95A section 6.3.4. */
typedef PACKED struct
{
   /* sid */
   word                                             sid;
   /* nid */
   word                                             nid;
   /* block_or_sys */
   nv_block_or_sys_enum_type                        block_or_sys;
   /* band_class */
   byte                                             band_class;
} nv_sid_nid_list_type;

/* Type to hold distance based registration paremeters. */
/*
 * Per CAI section 6.3.4.
 */
typedef PACKED struct
{
   /* BASE_LAT_REGsp */
   dword                                            base_lat_reg;
   /* BASE_LONG_REGsp */
   dword                                            base_long_reg;
   /* BASE_DIST_REGsp */
   word                                             reg_dist_reg;
} nv_dist_reg_type;

/* Type to hold call timers and associated NAM id. */
/*
 * Each NAM has its own set of these timers with units as shown.
 * The range of these timers is more than 100 years.
 *    Timer                     units
 *    -----                     -----
 *    Call Time                 seconds
 *    Air Time                  minutes
 *    Roam Time                 minutes
 *    Life Time                 minutes
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Time */
   dword                                            time;
} nv_call_time_type;


typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;

   word                                             table[NV_MRU_TABLE_SIZE];
} nv_mru_table_type;

/* Type to hold SID+NID pairs. */
/*
 * The SID is 15 bits, per CAI 2.3.8, and the NID is 16 bits,
 * per CAI section 2.3.10.3.
 */
typedef PACKED struct
{
   /* 15 bits, per CAI 2.3.8 */
   word                                             sid;
   /* 16 bits, per CAI section 2.3.10.3 */
   word                                             nid;
} nv_sid_nid_pair_type;

/* Type to hold 'home' SID+NID pairs for CDMA acquisition */
/*
 * The type also holds NAM id. Note that this item is NOT
 * 'per-MIN'
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* SID+NID pair */
   nv_sid_nid_pair_type                             pair[NV_MAX_HOME_SID_NID];
} nv_home_sid_nid_type;

/* Type to hold SID+NID pairs to be locked out from CDMA acquisition. */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* SID+NID Pair */
   nv_sid_nid_pair_type                             pair[NV_MAX_SID_NID_LOCK];
} nv_sid_nid_lock_type;

/* Type to hold IMSI type */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* International Mobile Station ID */
   qword                                            imsi;
} nv_imsi_type;

/* System type (A or B) */
typedef  word  nv_system_type;
/* System A */
#define  NV_SYSTEM_A                                   ((nv_system_type)0)
/* System B */
#define  NV_SYSTEM_B                                   ((nv_system_type)1)

/* Specifies either a channel or cellular system */
typedef PACKED union
{
   /* The CDMA channel to acquire */
   word                                             cdma_channel;
   /* The cellular system: A or B */
   nv_system_type                                   cellular_system;
} nv_cs_union_type;

/* Type for EVRC preferred voice service options. */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* evrc_capability_enabled */
   boolean                                          evrc_capability_enabled;
   /* home_page_voice_so */
   word                                             home_page_voice_so;
   /* home_orig_voice_so */
   word                                             home_orig_voice_so;
   /* roam_orig_voice_so */
   word                                             roam_orig_voice_so;
} nv_pref_voice_so_type;

/* Type to hold IMSI MCC , along with the associated NAM id. */
/*
 * The number is 24 bits
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* imsi_mcc */
   word                                             imsi_mcc;
} nv_imsi_mcc_type;

/* Type to hold IMSI_11_12 for 4 MINs along with the associated NAM id */
/*
 * The number is 8 bits.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* imsi_11_12 */
   byte                                             imsi_11_12;
} nv_imsi_11_12_type;

/* Type to hold IMSI length along with associated NAM id */
/*
 * The number is 3 bits, per J-STD-008 section 2.3.1.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Length of the IMSI for this NAM */
   byte                                             num;
} nv_imsi_addr_num_type;

/* Type to hold TMSI length, along with the associated NAM id. */
/*
 * The number is 4 bits, per J-STD-008 section 2.3.15.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* TMSI zone length */
   byte                                             length;
} nv_tmsi_zone_length_type;

/* Type to hold TMSI zone, along with the associated NAM id. */
/*
 * The number is 64 bits, per J-STD-008 section 2.3.15.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* The TMSI zone */
   qword                                            zone;
} nv_tmsi_zone_type;

/* Type to hold TMSI code, along with the associated NAM id. */
/*
 * The number is 32 bits, per J-STD-008 section 2.3.15.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* The TMSI code */
   dword                                            code;
} nv_tmsi_code_type;

/* Type to hold TMSI expiration timer, along with the associated NAM id. */
/*
 * The number is 24 bits, per J-STD-008 section 2.3.15.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* The TMSI expiration timer */
   dword                                            time;
} nv_tmsi_exp_time_type;

/* Type to hold the subscribers' home block (3 bits), along with the */
/*
 * associated NAM id.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Home block */
   byte                                             block;
} nv_home_block_type;

/* Type to hold DIR_NUMBER with associated NAM id */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Directory Number */
   byte                                             dir_number[NV_DIR_NUMB_SIZ];
} nv_dir_number_type;

/* Type to hold mobile directory number */
/*
 * (per IS-683) section 3.5.2.2).
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Number of digits */
   byte                                             n_digits;
   /* The digits */
   byte                                             digitn[NV_DIR_NUMB_PCS_SIZ];
} nv_mob_dir_data_type;

/* PN Id type */
typedef PACKED struct
{
   /* PN Id */
   byte                                             data[NV_PN_ID_TABLE_SIZE];
} nv_pn_id_type;

/* Same structure as nv_pn_id_type but for use in union nv_items_type */
typedef PACKED struct
{
   /* PN Id */
   byte                                             data;
} nv_pn_id_union_type;

/* Type for User Zone Table */
typedef PACKED struct
{
   /* Which table index? */
   byte                                             index;
   /* Roam Indicator value */
   byte                                             roam_ind;
   /* Control type */
   byte                                             control;
   /* The text entry */
   byte                                             text[NV_USER_ZONE_ENTRY_LENGTH];
} nv_user_zone_type;

/* Type to hold CDMA data information for OTASP Commit operation */
typedef PACKED struct
{
   /* Number of IMSI address digits */
   byte                                             imsi_addr_num;
   /* Mobile country code */
   word                                             mcc;
   /* 11th and 12th digits of IMSI */
   byte                                             imsi_11_12;
   /* Corresponds to old min1 */
   dword                                            imsi_s1;
   /* Corresponds to old min2 */
   word                                             imsi_s2;
   /* Access Overload Class */
   byte                                             accolc;
   /* Termination Indicator for the home system */
   boolean                                          mob_term_home;
   /* Termination indicator for SID roaming */
   boolean                                          mob_term_for_sid;
   /* Termination indicator for NID roaming */
   boolean                                          mob_term_for_nid;
   /* System Identification and Network Identification Pair */
   nv_sid_nid_pair_type                             pair[NV_MAX_SID_NID];
} nv_cdma_data_type;

/* Type to hold AMPS NAM information for 800 MHz cellular. */
/*
 * Includes information from the Cellular parameter block (IS-683 section
 * 4.5.2.1
 */
typedef PACKED struct
{
   /* First paging channel for the home system */
   word                                             firstchp;
   /* Analog home system identification */
   word                                             home_sid;
} nv_amps_data_type;

/* FOR OTASP COMMIT operation -- type to hold the IMSI-T parameters */
typedef PACKED struct
{

   dword                                            s1;

   word                                             s2;

   byte                                             imsi_t_11_12;

   word                                             mcc;

   byte                                             addr_num;
} nv_imsi_t_data_type;

/* Roaming list type */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;

   word                                             prl_version;

   word                                             size;

   boolean                                          valid;

   byte                                             roaming_list[NV_ROAMING_LIST_MAX_SIZE];
} nv_roaming_list_type;

/* type to hold the consolidated data to be commited. */
/*
 * This type also stores the control flags
 */
typedef PACKED struct
{
   /* Which NAM the data is for */
   byte                                             nam;
   /* Commit mobile directory number if set */
   boolean                                          commit_mob_dir;
   /* Commit CDMA information if set */
   boolean                                          commit_ftc_cdma;
   /* Commit AMPS NAM information if set */
   boolean                                          commit_ftc_amps;
   /* Commit roaming list if set */
   boolean                                          commit_roam_list;
   /* Commit SPC if set */
   boolean                                          commit_spc;
   /* Commit IMSI_T parms if set */
   boolean                                          commit_imsi_t;
   /* Commit nam lock parms if set */
   boolean                                          commit_nam_lock;
   /* The data to commit to nv */
   nv_mob_dir_data_type                             mob_dir;
   /* The data to commit to nv */
   nv_cdma_data_type                                ftc_cdma;
   /* The data to commit to nv */
   nv_amps_data_type                                ftc_amps;
   /* The data to commit to nv */
   nv_roaming_list_type                             *roam_list_ptr;
   /* The data to commit to nv */
   nv_sec_code_type                                 spc;
   /* The data to commit to nv */
   nv_imsi_t_data_type                              imsi_t;
   /* The data to commit to nv */
   nv_enabled_type                                  nam_lock;
} nv_otasp_commit_type;

/* Specifies either a channel, cellular system or plmn */
typedef PACKED union
{
   /* The CDMA channel to acquire */
   word                                             cdma_channel;
   /* The cellular system: A or B */
   nv_system_type                                   cellular_system;

   byte                                             plmn[3];
} nv_sid_union_type;

/* An MRU3 table entry */
typedef PACKED struct
{
   /* The mode */
   byte                                             mode;
   /* The band bit mask */
   dword                                            band_mask;
   /* System id */
   nv_sid_union_type                                sid;
   /* Reserved bytes to make sure the size */
   byte                                             spare[2];
} nv_mru3_table_entry_type;

/* Type for NV_MRU3_TABLE_I */
typedef PACKED struct
{
   /* NAM id 0 - N */
   byte                                             nam;

   nv_mru3_table_entry_type                         entry[NV_MRU_TABLE_SIZE];
} nv_mru3_table_type;

/* An MRU2 Table entry */
typedef PACKED struct
{
   /*  The mode: AMPS or CDMA */
   byte                                             mode;
   /* The band class: cellular or PCS */
   byte                                             band_class;
   /* The CDMA channel or cellular system */
   nv_cs_union_type                                 cs;
} nv_mru2_table_entry_type;

/* The MRU2 Table */
typedef PACKED struct
{
   /* NAM id 0..N */
   byte                                             nam;
   /* table entry */
   nv_mru2_table_entry_type                         entry[NV_MRU2_TABLE_SIZE];
} nv_mru2_table_type;

/* Acquire band class */
typedef  word  nv_band_pref_enum_type;
/* class 0, System A */
#define  NV_BAND_PREF_BC0_A                            ((nv_band_pref_enum_type)1)
/* class 0, System B */
#define  NV_BAND_PREF_BC0_B                            ((nv_band_pref_enum_type)2)
/* class 0 */
#define  NV_BAND_PREF_BC0                              ((nv_band_pref_enum_type)3)
/* class 1 */
#define  NV_BAND_PREF_BC1                              ((nv_band_pref_enum_type)4)
/* class 3 */
#define  NV_BAND_PREF_BC3                              ((nv_band_pref_enum_type)16)
/* class 4 */
#define  NV_BAND_PREF_BC4                              ((nv_band_pref_enum_type)32)
/* class 5 */
#define  NV_BAND_PREF_BC5                              ((nv_band_pref_enum_type)64)
/* class 8 - DCS 1800 Band */
#define  NV_BAND_PREF_GSM_DCS_1800                     ((nv_band_pref_enum_type)128)
/* class 9 - Extended GSM (E-GSM) 900 Band */
#define  NV_BAND_PREF_GSM_EGSM_900                     ((nv_band_pref_enum_type)256)
/* class 9P - Standard or Primary GSM (P-GSM) 900 Band */
#define  NV_BAND_PREF_GSM_PGSM_900                     ((nv_band_pref_enum_type)512)
/* any class */
#define  NV_BAND_PREF_ANY                              ((nv_band_pref_enum_type)65535)

/* band pref type */
typedef PACKED struct
{
   /* nam */
   byte                                             nam;
   /* band */
   nv_band_pref_enum_type                           band;
} nv_band_pref_type;

/* system selection roam preferences */
typedef  word  nv_roam_pref_enum_type;

#define  NV_ROAM_PREF_HOME                             ((nv_roam_pref_enum_type)1)

#define  NV_ROAM_PREF_AFFIL                            ((nv_roam_pref_enum_type)3)

#define  NV_ROAM_PREF_ANY                              ((nv_roam_pref_enum_type)255)

/* roam pref type */
typedef PACKED struct
{
   /* nam */
   byte                                             nam;
   /* roam */
   nv_roam_pref_enum_type                           roam;
} nv_roam_pref_type;


typedef PACKED struct
{
   /* nam ID 0-n */
   byte                                             nam;
   /* prl_version */
   word                                             prl_version;
   /* size */
   word                                             size;
   /* valid bit */
   boolean                                          valid;
   /* roaming list */
   byte                                             roaming_list[NV_SIZE_OF_ROAMING_LIST_IN_UNION_TYPE];
} nv_roaming_list_union_type;

/* Only Roaming list type header */
typedef PACKED struct
{
   /* NAM Id 0-n */
   byte                                             nam;
   /* prl_version */
   word                                             prl_version;
   /* size */
   word                                             size;
   /* valid bit */
   boolean                                          valid;
} nv_roaming_list_header_type;

/* Same structure as roaming_list_type */
/*
 * But adding some buffer bytes at the end of
 * roaming_list FASTPRL. This structure is used in RAM
 */
typedef PACKED struct
{
   /* NAM Id 0-n */
   byte                                             nam;
   /* prl_version */
   word                                             prl_version;
   /* size */
   word                                             size;
   /* valid bit */
   boolean                                          valid;
   /* Roaming list */
   byte                                             roaming_list[NV_SIZE_OF_RAM_ROAMING_LIST];
} nv_ram_roaming_list_type;

/* Type to hold analog/digital prefered mode, and the associated NAM */
typedef  word  nv_mode_enum_type;
/* CDMA then Analog */
#define  NV_MODE_DIGITAL_PREF                          ((nv_mode_enum_type)0)
/* CDMA only */
#define  NV_MODE_DIGITAL_ONLY                          ((nv_mode_enum_type)1)
/* Analog then CDMA */
#define  NV_MODE_ANALOG_PREF                           ((nv_mode_enum_type)2)
/* Analog only */
#define  NV_MODE_ANALOG_ONLY                           ((nv_mode_enum_type)3)
/* Determine mode automatically */
#define  NV_MODE_AUTOMATIC                             ((nv_mode_enum_type)4)
/* Emergency mode */
#define  NV_MODE_E911                                  ((nv_mode_enum_type)5)
/* Restrict to home only */
#define  NV_MODE_HOME_ONLY                             ((nv_mode_enum_type)6)
/* Restrict to PCS home only */
#define  NV_MODE_PCS_CDMA_ONLY                         ((nv_mode_enum_type)7)
/* Restrict to cellular home only */
#define  NV_MODE_CELL_CDMA_ONLY                        ((nv_mode_enum_type)8)

#define  NV_MODE_CDMA_ONLY                             ((nv_mode_enum_type)9)

#define  NV_MODE_HDR_ONLY                              ((nv_mode_enum_type)10)

#define  NV_MODE_CDMA_AMPS_ONLY                        ((nv_mode_enum_type)11)

#define  NV_MODE_GPS_ONLY                              ((nv_mode_enum_type)12)
/* Service is limited to GSM only */
#define  NV_MODE_GSM_ONLY                              ((nv_mode_enum_type)13)
/* Service is limited to WCDMA only */
#define  NV_MODE_WCDMA_ONLY                            ((nv_mode_enum_type)14)

#define  NV_MODE_WLAN_ONLY                             ((nv_mode_enum_type)15)

#define  NV_MODE_ANY_BUT_HDR                           ((nv_mode_enum_type)16)

#define  NV_MODE_GSM_WCDMA_ONLY                        ((nv_mode_enum_type)17)

#define  NV_MODE_DIGITAL_LESS_HDR_ONLY                 ((nv_mode_enum_type)18)

#define  NV_MODE_CDMA_HDR_ONLY                         ((nv_mode_enum_type)19)

#define  NV_MODE_CDMA_AMPS_HDR_ONLY                    ((nv_mode_enum_type)20)

#define  NV_MODE_CDMA_WLAN_ONLY                        ((nv_mode_enum_type)21)

#define  NV_MODE_HDR_WLAN_ONLY                         ((nv_mode_enum_type)22)

#define  NV_MODE_CDMA_HDR_WLAN_ONLY                    ((nv_mode_enum_type)23)

#define  NV_MODE_GSM_WLAN_ONLY                         ((nv_mode_enum_type)24)

#define  NV_MODE_WCDMA_WLAN_ONLY                       ((nv_mode_enum_type)25)

#define  NV_MODE_GW_WLAN_ONLY                          ((nv_mode_enum_type)26)

#define  NV_MODE_CDMA_AMPS_HDR_WLAN_ONLY               ((nv_mode_enum_type)27)

#define  NV_MODE_CDMA_AMPS_WLAN_ONLY                   ((nv_mode_enum_type)28)

#define  NV_MODE_ANY_BUT_HDR_WLAN                      ((nv_mode_enum_type)29)

#define  NV_MODE_LTE_ONLY                              ((nv_mode_enum_type)30)

#define  NV_MODE_GWL                                   ((nv_mode_enum_type)31)

#define  NV_MODE_CDMA_LTE_ONLY                         ((nv_mode_enum_type)32)

#define  NV_MODE_HDR_LTE_ONLY                          ((nv_mode_enum_type)33)

#define  NV_MODE_GSM_LTE_ONLY                          ((nv_mode_enum_type)34)

#define  NV_MODE_WCDMA_LTE_ONLY                        ((nv_mode_enum_type)35)

#define  NV_MODE_CDMA_HDR_LTE_ONLY                     ((nv_mode_enum_type)36)

#define  NV_MODE_CDMA_GSM_LTE_ONLY                     ((nv_mode_enum_type)37)

#define  NV_MODE_CDMA_WCDMA_LTE_ONLY                   ((nv_mode_enum_type)38)

#define  NV_MODE_HDR_GSM_LTE_ONLY                      ((nv_mode_enum_type)39)

#define  NV_MODE_HDR_WCDMA_LTE_ONLY                    ((nv_mode_enum_type)40)

#define  NV_MODE_CDMA_LTE_WLAN_ONLY                    ((nv_mode_enum_type)41)

#define  NV_MODE_HDR_LTE_WLAN_ONLY                     ((nv_mode_enum_type)42)

#define  NV_MODE_GSM_LTE_WLAN_ONLY                     ((nv_mode_enum_type)43)

#define  NV_MODE_WCDMA_LTE_WLAN_ONLY                   ((nv_mode_enum_type)44)

#define  NV_MODE_CDMA_HDR_LTE_WLAN_ONLY                ((nv_mode_enum_type)45)

#define  NV_MODE_CDMA_GSM_LTE_WLAN_ONLY                ((nv_mode_enum_type)46)

#define  NV_MODE_CDMA_WCDMA_LTE_WLAN_ONLY              ((nv_mode_enum_type)47)

#define  NV_MODE_HDR_GSM_LTE_WLAN_ONLY                 ((nv_mode_enum_type)48)

#define  NV_MODE_HDR_WCDMA_LTE_WLAN_ONLY               ((nv_mode_enum_type)49)

#define  NV_MODE_ANY_BUT_WLAN                          ((nv_mode_enum_type)50)

#define  NV_MODE_CDMA_GSM_WCDMA                        ((nv_mode_enum_type)51)

#define  NV_MODE_CDMA_HDR_GSM_WCDMA                    ((nv_mode_enum_type)52)

#define  NV_MODE_TDS                                   ((nv_mode_enum_type)53)

#define  NV_MODE_TDS_GSM                               ((nv_mode_enum_type)54)

#define  NV_MODE_TDS_GSM_LTE                           ((nv_mode_enum_type)55)

#define  NV_MODE_TDS_LTE                               ((nv_mode_enum_type)60)

/* Preferred mode */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Preferred mode per enum above */
   nv_mode_enum_type                                mode;
} nv_pref_mode_type;

/* Type to hold the call history */
/*
 * COUNT parameter and the associated NAM id, per CAI section 2.3.12.1.3.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* COUNTsp */
   byte                                             count;
} nv_count_type;

/* Type to hold SID+NID pairs for CDMA acquisition along with NAM id. */
/*
 * NID is 16 bits, per CAI section 2.3.10.3.  There are up to 4 SID+NID
 * pairs, in descending preferrence (0=first, 3=last).
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* SID+NID Pair */
   nv_sid_nid_pair_type                             pair[NV_MAX_MINS][NV_MAX_SID_NID];
} nv_sid_nid_type;

/* Type to hold MIN data checksum. */
/*
 * The checksum is a simple 0xFFFF marker which specifies that MIN
 * parameters have been programmed and are valid.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Checksum */
   word                                             chksum[NV_MAX_MINS];
} nv_min_chksum_type;

/* Type to hold ORIG_MIN id, along with the associated NAM id. */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* MIN id 0-N */
   byte                                             id;
} nv_orig_min_type;

/* Type to hold the name of each NAM, along with the associated NAM id */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* NAM name string */
   byte                                             name[NV_MAX_LTRS];
} nv_name_nam_type;

/* System Preference */
typedef  word  nv_sys_pref_enum_type;
/* A only */
#define  NV_SP_A_ONLY                                  ((nv_sys_pref_enum_type)0)
/* B only */
#define  NV_SP_B_ONLY                                  ((nv_sys_pref_enum_type)1)
/* Home only */
#define  NV_SP_HOME_ONLY                               ((nv_sys_pref_enum_type)2)
/* Home preferred */
#define  NV_SP_STANDARD                                ((nv_sys_pref_enum_type)3)

/* Type to hold the system preference and the associated NAM. */
/*
 * This item replaces NV_CDMA_PREF_SERV_I and NV_ANALOG_PREF_SERV_I for
 * SSPR 800.
 */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* Preferred system per above enum */
   nv_sys_pref_enum_type                            sys;
} nv_sys_pref_type;

/* Preferences for ps data calls. */
typedef  word  nv_ps_data_orig_pref_enum_type;

#define  NV_PS_DATA_ORIG_PREF_CDMA_ONLY                ((nv_ps_data_orig_pref_enum_type)0)

#define  NV_PS_DATA_ORIG_PREF_CDMA_HDR                 ((nv_ps_data_orig_pref_enum_type)1)

#define  NV_PS_DATA_ORIG_PREF_CDMA_HDR_IF_CHINA        ((nv_ps_data_orig_pref_enum_type)2)

#define  NV_PS_DATA_ORIG_PREF_GW_ONLY                  ((nv_ps_data_orig_pref_enum_type)3)

#define  NV_PS_DATA_ORIG_PREF_ANY                      ((nv_ps_data_orig_pref_enum_type)4)

/* Microbrowser data table type */
typedef PACKED struct
{
   /* Which array element */
   byte                                             index;
   /* The data */
   byte                                             data[NV_UBROWSER_ELEMENT_SIZE];
} nv_ubrowser_type;

/* Type of DATA SERVICES default SIO baud */
typedef  word  nv_sio_baud_type;

#define  NV_SIO_BITRATE_AUTO                           ((nv_sio_baud_type)0)

#define  NV_SIO_BITRATE_45                             ((nv_sio_baud_type)1)

#define  NV_SIO_BITRATE_50                             ((nv_sio_baud_type)2)

#define  NV_SIO_BITRATE_75                             ((nv_sio_baud_type)3)

#define  NV_SIO_BITRATE_110                            ((nv_sio_baud_type)4)

#define  NV_SIO_BITRATE_150                            ((nv_sio_baud_type)5)

#define  NV_SIO_BITRATE_300                            ((nv_sio_baud_type)6)

#define  NV_SIO_BITRATE_600                            ((nv_sio_baud_type)7)

#define  NV_SIO_BITRATE_1200                           ((nv_sio_baud_type)8)

#define  NV_SIO_BITRATE_2400                           ((nv_sio_baud_type)9)

#define  NV_SIO_BITRATE_4800                           ((nv_sio_baud_type)10)

#define  NV_SIO_BITRATE_9600                           ((nv_sio_baud_type)11)

#define  NV_SIO_BITRATE_19200                          ((nv_sio_baud_type)12)

#define  NV_SIO_BITRATE_38400                          ((nv_sio_baud_type)13)

#define  NV_SIO_BITRATE_57600                          ((nv_sio_baud_type)14)

#define  NV_SIO_BITRATE_115200                         ((nv_sio_baud_type)15)

#define  NV_SIO_BITRATE_230400                         ((nv_sio_baud_type)16)

#define  NV_SIO_BITRATE_BEST                           ((nv_sio_baud_type)17)

#define  NV_SIO_BITRATE_MAX                            ((nv_sio_baud_type)18)

/* One-time startup configuration for DIAG services type. */
typedef PACKED struct
{

   byte                                             event_config;

   byte                                             msg_level;

   byte                                             logmask[NV_DIAG_RESTART_CONFIG_LOGMASK_SIZE];

   byte                                             reserved[4];
} nv_diag_restart_config_type;

/* Type to hold IP address information */
typedef PACKED struct
{
   /* IP address table */
   byte                                             ip[NV_IP_ADDRESSES_PER_ENTRY];
   /* Port address */
   word                                             port;
} nv_ip_address_type;

/* Type to hold Unwired Planet link info */
typedef PACKED struct
{
   /* UP link info table index */
   byte                                             index;
   /* Number of valid ip addresses */
   word                                             numAddr;
   /* IP address */
   nv_ip_address_type                               addr[NV_IP_ADDRESS_TABLE_SIZE];
   /* Length of key field */
   byte                                             key_length;
   /* Obsolete key is stored in NV_UP_KEY_I */
   byte                                             obsolete[NV_UP_MAX_KEY_SIZE];
} nv_up_link_info_type;

/* UP parameters type */
typedef PACKED struct
{
   /* Last active IP address */
   byte                                             curr_gateway;
   /* Last alert state */
   byte                                             alert_state;
   /* Disconnect time-out value */
   byte                                             disconnect_timer;
   /* permanent storage */
   byte                                             perm_storage[NV_UP_MAX_PERM_STORE_SIZE];
} nv_up_parms_type;

/* UP alerts type */
typedef PACKED struct
{
   /* To specify which of the 9 records to access */
   byte                                             index;
   /* Alert name */
   byte                                             alert_name[NV_UP_ALERT_NAME_SIZE];
   /* Alert status */
   byte                                             alert_status;
   /* Alert Id */
   word                                             alert_id;
} nv_up_alert_record_type;

/* UP cache type */
typedef PACKED struct
{
   /* The UP cache */
   byte                                             cache[NV_UP_MAX_CACHE_SIZE];
} nv_up_cache_type;

/* Same structure as nv_up_cache_type but for use in union nv_item_type */
typedef PACKED union
{
   /* UP cache */
   byte                                             cache;
} nv_up_cache_union_type;

/* Type for V5.2 control functionality */
typedef  word  nv_v52_control_enum_type;
/* V5.2 support disabled, functionality bypassed */
#define  NV_V52_DISABLED                               ((nv_v52_control_enum_type)0)
/* V5.2 support enabled, with no local buffering */
#define  NV_V52_ENABLED                                ((nv_v52_control_enum_type)1)
/* V5.2 support enabled, with local buffering */
#define  NV_V52_LOCAL_BUFFERING                        ((nv_v52_control_enum_type)2)
/* V5.2 support reserved field */
#define  NV_V52_FUTURE_SUPPORT                         ((nv_v52_control_enum_type)3)

/* Type for analog fax mode */
typedef  word  nv_afax_type;
/* Analog Fax end-to-end */
#define  NV_AFAX_ETE                                   ((nv_afax_type)0)
/* Analog Fax Class 2.0 */
#define  NV_AFAX_CLASS2                                ((nv_afax_type)1)

/* Type to hold the dial string used for originating packet data calls */
typedef PACKED struct
{
   /* Number of digits */
   byte                                             num_digits;
   /* The digit array */
   byte                                             digits[NV_MAX_PKT_ORIG_DIGITS];
} nv_data_pkt_orig_str_type;

/* Type to hold the general info. of a Mobile IP user prof */
typedef PACKED struct
{
   /* entry index */
   byte                                             index;
   /* Length of User NAI field */
   byte                                             nai_length;
   /* Network Access Identifier */
   byte                                             nai[NV_MAX_NAI_LENGTH];
   /* SPI set 1 bit */
   boolean                                          mn_ha_spi_set;
   /* Security Parameter Index for MN-HA authentication */
   dword                                            mn_ha_spi;
   /* SPI set 1 bit */
   boolean                                          mn_aaa_spi_set;
   /* Security Parameter Index for MN-AAA authentication */
   dword                                            mn_aaa_spi;
   /* Reverse tunneling preference */
   boolean                                          rev_tun_pref;
   /* IP address of mobile set to 0 for dynamic home address */
   dword                                            home_addr;
   /* Primary Home Agent IP address */
   dword                                            primary_ha_addr;
   /* Secondary Home Agent IP address */
   dword                                            secondary_ha_addr;
} nv_ds_mip_gen_user_prof_type;

/* Type to hold the shared secret info. of a Mobile IP user prof */
typedef PACKED struct
{
   /* entry index */
   byte                                             index;
   /* Length of MN-HA shared secret */
   byte                                             mn_ha_shared_secret_length;
   /* MN-HA shared secret */
   byte                                             mn_ha_shared_secret[NV_MAX_MN_HA_SHARED_SECRET_LEN];
   /* Length of MN-AAA shared secret */
   byte                                             mn_aaa_shared_secret_length;
   /* MN_AAA shared secret */
   byte                                             mn_aaa_shared_secret[NV_MAX_MN_AAA_SHARED_SECRET_LEN];
} nv_ds_mip_ss_user_prof_type;

/* Type for timebase diff. between home agent and mobile */
typedef PACKED struct
{
   /* entry index */
   byte                                             index;
   /* time difference */
   uint32                                           time_delta;
} nv_ds_mip_mn_ha_time_delta_type;

/* Type for Authentication */
typedef  word  nv_ppp_auth_enum_type;

#define  NV_NO_AUTH                                    ((nv_ppp_auth_enum_type)0)

#define  NV_PAP                                        ((nv_ppp_auth_enum_type)1)

#define  NV_CHAP                                       ((nv_ppp_auth_enum_type)2)

/* Type for Public Key Organization Identifier */
typedef PACKED struct
{
   /* entry index */
   byte                                             index;

   byte                                             pkoid;
} nv_ds_mip_dmu_pkoid_type;

/* Type for Mobile Node Authenticator */
typedef PACKED struct
{
   /* entry index */
   byte                                             index;

   byte                                             mn_auth[3];
} nv_ds_mip_dmu_mn_auth_type;


typedef  word  nv_rtsp_proxy_server_flag_type;

#define  NV_ADDR_INVALID                               ((nv_rtsp_proxy_server_flag_type)0)

#define  NV_IPV4_ADDR_MASK                             ((nv_rtsp_proxy_server_flag_type)1)

#define  NV_IPV6_ADDR_MASK                             ((nv_rtsp_proxy_server_flag_type)2)


typedef PACKED union
{

   uint32                                           v4;

   uint64                                           v6[2];
} nv_rtsp_proxy_server_addr;

/* Type for NV_RTSP_PROXY_SERVER_ADDR_I */
typedef PACKED struct
{

   nv_rtsp_proxy_server_flag_type                   flags;

   uint16                                           port;

   nv_rtsp_proxy_server_addr                        addr;
} nv_rtsp_proxy_server_addr_type;

/* Operating Mode Type */
typedef  word  nv_operating_mode_enum_type;
/* GSM/GPRS Mode */
#define  NV_OPMODE_GPRS                                ((nv_operating_mode_enum_type)1)
/* WCDMA Mode */
#define  NV_OPMODE_WCDMA                               ((nv_operating_mode_enum_type)2)
/* CDMA/1x Mode */
#define  NV_OPMODE_CDMA                                ((nv_operating_mode_enum_type)4)

/* Type for NV_PKT_DIAL_STRINGS_I */
typedef PACKED struct
{
   /* DS Packet Dial String */
   byte                                             dial_string[NV_PKT_DIAL_STRING_SIZE];
   /* DS Call Type Operating Modes */
   nv_operating_mode_enum_type                      call_type;
   /* DS Permitted Operating Modes */
   nv_operating_mode_enum_type                      modes_permitted;
} nv_pkt_dial_string_type;

/* Type for NV_PPP_CONFIG_DATA_I */
typedef PACKED struct
{
   /* entry index */
   byte                                             index;

   uint16                                           lcp_term_timeout;

   uint16                                           lcp_ack_timeout;

   uint8                                            lcp_req_try;

   uint8                                            lcp_nak_try;

   uint8                                            lcp_term_try;

   uint8                                            auth_retry;

   uint16                                           auth_timeout;

   uint16                                           ipcp_term_timeout;

   uint16                                           ipcp_ack_timeout;

   uint8                                            ipcp_req_try;

   uint8                                            ipcp_nak_try;

   uint8                                            ipcp_term_try;

   uint8                                            ipcp_compression_enable;

   uint16                                           ipv6cp_term_timeout;

   uint16                                           ipv6cp_ack_timeout;

   uint8                                            ipv6cp_req_try;

   uint8                                            ipv6cp_nak_try;

   uint8                                            ipv6cp_term_try;

   uint8                                            ipv6cp_compression_enable;
} nv_ppp_configure_data_type;

/* Type for NV_PPP_NCP_REMOTE_INITIATE_I */
typedef PACKED struct
{
   /* entry index */
   byte                                             index;

   byte                                             ipcp;

   byte                                             ipv6cp;
} nv_ppp_ncp_remote_initiate_type;

/* Type for NV_PS_IPV6_IID_I */
typedef PACKED struct
{

   byte                                             ipv6_iid_enum_type;

   uint64                                           iid_val;
} nv_ps_ipv6_iid_type;

/* Type for NV_IPV6_SM_CONFIG_I  */
typedef PACKED struct
{

   int16                                            init_sol_delay;

   int16                                            sol_interval;

   int16                                            resol_interval;

   int16                                            max_sol_attempts;

   int16                                            max_resol_attempts;

   int16                                            pre_ra_exp_resol_time;
} nv_ip6_sm_config_type;

/* Type for NV_IPV6_PRIMARY_DNS_I, NV_IPV6_SECONDARY_DNS_I  */
typedef PACKED struct
{

   uint64                                           prefix;

   uint64                                           iid;
} nv_ipv6_address_type;

/* Type of HDR searching parameters */
typedef PACKED struct
{

   uint16                                           pilot_inc;

   uint8                                            pilot_add;

   uint8                                            pilot_drop;

   int8                                             pilot_compare;

   uint8                                            pilot_drop_timer;
   /* HAI x6 Only */
   boolean                                          dynamic_threshold;
   /* HAI x6 Only */
   uint8                                            soft_slope;
   /* HAI x6 Only */
   int8                                             add_intercept;
   /* HAI x6 Only */
   int8                                             drop_intercept;

   uint8                                            aset_win_size;

   uint8                                            nset_win_size;

   uint8                                            rset_win_size;

   uint8                                            nset_max_age;
} nv_hdr_srch_params_type;

/* Type of HDR channel management parameters */
typedef PACKED struct
{

   uint8                                            pilot_add;

   uint8                                            pilot_drop;

   uint8                                            pilot_compare;

   uint8                                            pilot_drop_timer;

   boolean                                          dynamic_thresholds;

   uint8                                            soft_slope;
   /* HAI x6 Only */
   int8                                             add_intercept;
   /* HAI x6 Only */
   int8                                             drop_intercept;

   uint8                                            nset_max_age;
} nv_hdr_chan_mgmt_params_type;


typedef PACKED struct
{

   uint32                                           session_seed;

   uint32                                           transmit_ati;

   uint32                                           receive_mati;

   uint32                                           receive_rati;

   uint32                                           receive_current_uati;

   uint32                                           receive_new_uati;

   boolean                                          new_uati_valid;

   uint8                                            uati[NV_UATI_LENGTH];

   uint8                                            uati_color_code;

   uint8                                            uati_subnet_mask;
} nv_hdramp_address_data_type;


typedef  word  nv_hdrscp_session_status_enum_type;

#define  NV_SCP_SESSION_INACTIVE                       ((nv_hdrscp_session_status_enum_type)0)

#define  NV_SCP_SESSION_DEFAULT                        ((nv_hdrscp_session_status_enum_type)1)

#define  NV_SCP_SESSION_ACTIVE                         ((nv_hdrscp_session_status_enum_type)2)

#define  NV_SCP_SESSION_MAX                            ((nv_hdrscp_session_status_enum_type)32767)

/* Access MAC Initial Configuration Attribute */
typedef PACKED struct
{

   uint8                                            capsule_length_max;

   uint8                                            power_step;

   uint8                                            probe_sequence_max;

   uint8                                            probe_backoff;

   uint8                                            probe_sequence_backoff;
} nv_hdramac_initial_config_type;

/* Access MAC Power Parameters Attribute */
typedef PACKED struct
{

   uint8                                            data_offset_nom;

   uint8                                            data_offset_9k6;
} nv_hdramac_power_params_type;

/* Forward Traffic MAC Handoff Delays Attribute */
typedef PACKED struct
{

   uint8                                            softer_handoff_delay;

   uint8                                            soft_handoff_delay;
} nv_hdrfmac_handoff_delays_type;

/* Reverse Traffic MAC Power Parameters Attribute */
typedef PACKED struct
{

   uint8                                            data_offset_nom;

   uint8                                            data_offset_9k6;

   uint8                                            data_offset_19k2;

   uint8                                            data_offset_38k4;

   uint8                                            data_offset_76k8;

   uint8                                            data_offset_153k6;

   uint8                                            rpc_step;
} nv_hdrrmac_power_params_type;

/* Reverse Traffic MAC Rate Parameters Attribute */
typedef PACKED struct
{

   uint8                                            transition_009k6_019k2;

   uint8                                            transition_019k2_038k4;

   uint8                                            transition_038k4_076k8;

   uint8                                            transition_076k8_153k6;

   uint8                                            transition_019k2_009k6;

   uint8                                            transition_038k4_019k2;

   uint8                                            transition_076k8_038k4;

   uint8                                            transition_153k6_076k8;
} nv_hdrrmac_rate_params_type;

/* Type of NV_HDRFMAC_DRC_LOCK_I */
typedef PACKED struct
{

   uint8                                            drc_lock_length;

   uint8                                            drc_lock_period;
} nv_hdrfmac_drc_lock_type;

/* Type of NV_HDRKEP_CONFIG_I */
typedef PACKED struct
{

   uint16                                           key_len;

   boolean                                          keys_are_valid;
   /* w */
   uint8                                            rpc_auth_key[NV_RPC_AUTH_KEY_MAX_LEN];
} nv_hdrkep_config_type;

/* Type of NV_HDRAUTH_CONFIG_I */
typedef PACKED struct
{

   uint16                                           ac_auth_key_len;
} nv_hdrauth_config_type;

/* Type for NAI for 1xEV(HDR) Access Network CHAP authentication */
typedef PACKED struct
{
   /* length of NAI */
   byte                                             nai_len;
   /* the NAI */
   byte                                             nai[NV_MAX_AN_AUTH_NAI_LENGTH];
} nv_hdr_an_auth_nai_type;

/* Type for password for 1xEV(HDR) Access Network CHAP authentication */
typedef PACKED struct
{
   /* length of password */
   byte                                             password_len;
   /* the password */
   byte                                             password[NV_MAX_AN_AUTH_PASSWORD_LENGTH];
} nv_hdr_an_auth_password_type;

/* Type of HDR searching parameters */
typedef PACKED struct
{

   uint16                                           pilot_inc;

   uint8                                            aset_win_size;

   uint8                                            nset_win_size;

   uint8                                            rset_win_size;
} nv_hdrrup_srch_params_type;

/* NAI for AN authentication */
typedef PACKED struct
{
   /* length of NAI */
   byte                                             user_id_len;
   /* the NAI */
   byte                                             user_id[NV_MAX_AN_PPP_USER_ID_LENGTH];
} nv_hdr_an_ppp_nai_type;

/* Password for AN authentication */
typedef PACKED struct
{
   /* length of password */
   byte                                             password_len;
   /* the password */
   byte                                             password[NV_MAX_AN_PPP_PASSWORD_LENGTH];
} nv_hdr_an_ppp_password_type;

/* Type of NV_HDR_AN_AUTH_PASSWD_LONG_I */
typedef PACKED struct
{
   /* length of password */
   byte                                             passwd_len;
   /* the password */
   byte                                             passwd[NV_MAX_AN_AUTH_PASSWD_LONG_LENGTH];
} nv_hdr_an_auth_passwd_long_type;

/* Type of NV_HDR_AN_AUTH_USER_ID_LONG_I */
typedef PACKED struct
{
   /* length of user id */
   byte                                             user_id_len;
   /* the user id */
   byte                                             user_id[NV_MAX_AN_AUTH_USER_ID_LONG_LENGTH];
} nv_hdr_an_auth_user_id_long_type;

/* Type for Analog (FM) TX power levels */
typedef PACKED struct
{
   /* power level 0 (max) */
   byte                                             level_0;
   /* power level 1 */
   byte                                             level_1;
   /* power level 2 */
   byte                                             level_2;
   /* power level 3 */
   byte                                             level_3;
   /* power level 4 */
   byte                                             level_4;
   /* power level 5 */
   byte                                             level_5;
   /* power level 6 */
   byte                                             level_6;
   /* power level 7 */
   byte                                             level_7;
} nv_fm_tx_pwr_type;

/* Type for Frequency/Temperature Offset Table */
typedef PACKED struct
{
   /* item */
   byte                                             item[NV_FR_TEMP_OFFSET_TABLE_SIZ];
} nv_fr_temp_offset_type;

/* Type for ADC range for HDET sampling */
typedef PACKED struct
{
   /* HDET ADC value */
   byte                                             value[NV_HDET_ADC_TABLE_SIZ];
} nv_fm_hdet_adc_range_type;

/* Type for frequency adjustment table */
typedef PACKED struct
{
   /* Frequency adjustment table */
   byte                                             item[NV_FREQ_ADJ_TABLE_SIZ];
} nv_freq_adj_type;

/* Type for Switch to AMPS 2-word arrays */
typedef PACKED struct
{
   /* Index */
   byte                                             index;
   /* value */
   word                                             value[NV_MAX_STA_VALUES];
} nv_sta_values_type;

/* PA offset type */
typedef PACKED struct
{
   /* Offset */
   int2                                             offset;
   /* Temperature adjustement array */
   int1                                             temp_adj[NV_TEMP_TABLE_SIZ];
   /* Frequency adjustement array */
   int1                                             freq_adj[NV_FREQ_TABLE_SIZ];
} nv_pa_offset_type;

/* Tx linearizer structure */
typedef PACKED struct
{
   /* Offset */
   int2                                             offset;
   /* Slope */
   byte                                             slope[NV_CDMA_TX_LIN_MASTER_SIZ];
} nv_tx_linearizer_type;

/* Same structure as nv_tx_linearizer_type */
/*
 * However, this type is only for use in the nv_item_type union
 * so it will be under 128 bytes in size
 */
typedef PACKED struct
{
   /* Offset */
   int2                                             offset;
   /* Slope */
   byte                                             slope;
} nv_tx_linearizer_union_type;

/* Type of IS2000 CAI radio configuration RC preference */
typedef  word  nv_rc_pref_type;

#define  NV_CAI_RC_1                                   ((nv_rc_pref_type)1)

#define  NV_CAI_RC_2                                   ((nv_rc_pref_type)2)

#define  NV_CAI_RC_3                                   ((nv_rc_pref_type)3)

#define  NV_CAI_RC_4                                   ((nv_rc_pref_type)4)

#define  NV_CAI_RC_5                                   ((nv_rc_pref_type)5)

/* pcs transmit frequency compensation table 0 */
typedef PACKED struct
{

   int1                                             nv_cdma_tx_lin_vs_temp[NV_TEMP_TABLE_SIZ];

   int1                                             nv_cdma_tx_slp_vs_temp[NV_TEMP_TABLE_SIZ];

   int1                                             nv_cdma_tx_comp_vs_freq[NV_FREQ_TABLE_SIZ];
} nv_tx_comp_type;

/* dB backoff for low and medium voltage */
typedef PACKED struct
{
   /* dB backoff for low voltage */
   uint8                                            low;
   /* dB backoff for medium voltage */
   uint8                                            medium;
} nv_pwr_bckoff_vs_volt_type;

/* Type for obsolete sms item */
typedef PACKED struct
{
   /* reservation confirmation code */
   dword                                            confirmation_code;
   /* sms message to delete prior to write */
   dword                                            deletion_list;
   /* sms entry [ 0..100] */
   byte                                             address;
   /* status mask */
   byte                                             status;
   /* User data */
   byte                                             user_data_length;
   /* Call back length */
   byte                                             call_back_length;
   /* Mask */
   qword                                            param_mask;
   /* bytes in 'data', [8..325] */
   word                                             length;
   /* generic sms data, variable size */
   byte                                             data[NV_SMS_DATA_SIZ];
} nv_sms_type;

/* Type for real sms item */
typedef PACKED struct
{
   /* reservation confirmation code */
   dword                                            confirmation_code;
   /* sms message to delete prior to write */
   dword                                            deletion_list;
   /* sms entry [ 0..100] */
   byte                                             address;
   /* status mask */
   byte                                             status;
   /* User data */
   byte                                             user_data_length;
   /* Call back length */
   byte                                             call_back_length;
   /* Mask */
   qword                                            param_mask;
   /* bytes in 'data', [8..325] */
   word                                             length;
   /* generic sms data, variable size */
   byte                                             data[NV_SMS_DM_DATA_SIZ];
} nv_sms_dm_type;

/* Type for SMS broadcast service table entry */
typedef PACKED struct
{
   /* entry index */
   byte                                             index;
   /* for delete operation */
   boolean                                          active_service;
   /* type of service */
   word                                             service;
   /* type of language */
   byte                                             language;
   /* for */
   boolean                                          selected;
   /* priority of the service */
   byte                                             priority;
   /* a UI text label for each service/language pair */
   byte                                             label[NV_SMS_BC_SRV_LABEL_SIZE];
} nv_sms_bc_service_table_type;

/* Type for GSM/WCDMA SMS voice mail center phone number */
typedef PACKED struct
{
   /* number of digits in the phone number */
   uint8                                            num_digits;
   /* the value of all digits in the phone number */
   uint8                                            digits[NV_MAX_DIAL_DIGITS];
} nv_sms_vm_number_type;

/* Type to store GSM/WCDMA template */
typedef PACKED struct
{
   /* Size of the GSM/WCDMA SMS parameters */
   uint8                                            len;
   /* The GSM/WCDMA SMS parameters */
   uint8                                            data[NV_SMS_GW_PARAMS_SIZE];
} nv_sms_gw_parms_type;

/* Type for GSM/WCDMA sms item */
typedef PACKED struct
{
   /* reservation confirmation code */
   dword                                            confirmation_code;
   /* sms message to delete prior to write */
   dword                                            deletion_list;
   /* sms entry [ 0..100] */
   uint8                                            address;
   /* length of 'data' */
   uint8                                            length;
   /* generic sms data, variable size */
   uint8                                            data[NV_SMS_GW_DATA_SIZ];
} nv_sms_gw_type;

/* Type to store GSM/WCDMA SMS routing configurations */
typedef PACKED struct
{

   uint8                                            pp_routes[NV_SMS_MAX_ROUTES];

   uint8                                            pp_mem_stores[NV_SMS_MAX_ROUTES];

   uint8                                            bc_routes[NV_SMS_MAX_ROUTES];

   uint8                                            bc_mem_stores[NV_SMS_MAX_ROUTES];

   boolean                                          transfer_status_report;
} nv_sms_routing_type;

/* Type to store CDMA SMS Parameters/templates */
typedef PACKED struct
{

   uint8                                            address;

   uint8                                            len;

   uint8                                            data[NV_SMS_CD_PARMS_SIZE];
} nv_sms_cd_parms_type;

/* Type for NV_SMS_BC_SERVICE_TABLE_OPTIONS_I */
typedef PACKED struct
{

   byte                                             index;

   byte                                             label_encoding;

   byte                                             bc_alert;

   byte                                             max_messages;
} nv_sms_bc_service_table_options_type;

/* Type to store MO Message template */
typedef PACKED struct
{

   uint8                                            mem_store;

   uint8                                            index;
} nv_sms_default_template_type;

/* Type for NV_SMS_GW_CB_SERVICE_TABLE_I */
typedef PACKED struct
{
   /* Table entry index */
   byte                                             index;
   /* Whether the entry is valid */
   boolean                                          active_service;
   /* Service ID range start */
   word                                             service_from;
   /* Service ID range end */
   word                                             service_to;
   /* Selected/Deselected the service */
   boolean                                          selected;
   /* Service ID textual information */
   byte                                             label[NV_SMS_BC_SRV_LABEL_SIZE];
   /* Label encoding */
   byte                                             label_encoding;
   /* Alert type */
   byte                                             bc_alert;
   /* Maximum number of messages can be stored for this service ID or range */
   byte                                             max_messages;
} nv_sms_gw_cb_service_table_type;

/* not provided */
typedef PACKED struct
{

   word                                             msg_id;

   word                                             wap_msg_id;

   boolean                                          mem_avail;
} nv_ruim_sms_status_type;

/* type to hold speed dial number. */
/*
 * 'num_digits' and 'num_letters' indicate the actual number of digits
 * and letters, or zero if none.
 * The storage address is in the range 0-99 for speed dial numbers
 */
typedef PACKED struct
{
   /* Address (index) */
   byte                                             address;
   /* flag bits */
   byte                                             status;
   /* Number of digits */
   byte                                             num_digits;
   /* Array of digits */
   byte                                             digits[NV_MAX_DIAL_DIGITS];
   /* Name associated with number */
   byte                                             letters[NV_MAX_LTRS];
} nv_dial_type;

/* Type to hold call stack dial number */
/*
 * 'num_digits' and 'num_letters' indicates the actual number of
 * digits and letters, or zero if none. The storage address is in the
 * range of 0-9 for a stack number.
 */
typedef PACKED struct
{
   /* Storage address */
   byte                                             address;
   /* flag bits */
   byte                                             status;
   /* years to seconds */
   dword                                            time_stamp;
   /* Number of digits */
   byte                                             num_digits;
   /* Array of digits */
   byte                                             digits[NV_MAX_DIAL_DIGITS];
   /* Name associated with number */
   byte                                             letters[NV_MAX_LTRS];
   /* Duration of the call */
   dword                                            duration;
} nv_stdial_type;

/* Type to hold call stack index. */
/*
 * The array of bytes allows sorting the call stack by
 * order of dialing and resorting as it is being used. The secret field
 * indicates if a secret number is in that stack location.
 */
typedef PACKED struct
{
   /* Index array */
   byte                                             index[NV_MAX_STACK_DIALS];
   /* TRUE if a secret number */
   boolean                                          secret[NV_MAX_STACK_DIALS];
} nv_stack_idx_type;

/* Type to specify page answer rings and answer mode. */
typedef PACKED struct
{
   /* paging mode */
   byte                                             enable;
   /* Number of rings when to accept page */
   byte                                             rings;
} nv_page_set_type;

/* Type to hold page message. */
/*
 * The page characters are stored as ASCII string.
 */
typedef PACKED struct
{
   /* Storage address 0-19 */
   byte                                             address;
   /* Time stamp */
   dword                                            time_stamp;
   /* New page status */
   boolean                                          newPage;
   /* Number of characters */
   byte                                             num_chars;
   /* Array of characters */
   byte                                             chars[NV_MAX_PAGE_CHARS];
} nv_page_msg_type;

/* Type to hold display banner. */
/*
 * The banner is fixed length and is stored as ASCII string.
 */
typedef PACKED struct
{
   /* Banner */
   byte                                             letters[NV_MAX_LTRS];
} nv_banner_type;

/* Type to specify auto answer rings and enable/disable. */
typedef PACKED struct
{
   /* TRUE if auto answer enabled */
   boolean                                          enable;
   /* Number of rings when to answer call */
   byte                                             rings;
} nv_auto_answer_type;

/* Type to specify auto redial rings and enable/disable */
typedef PACKED struct
{
   /* TRUE if auto redial enabled */
   boolean                                          enable;
   /* Number of 10 seconds system busy before redial */
   byte                                             rings;
} nv_auto_redial_type;

/* Type to hold user lock code. */
/*
 * The lock code is fixed length and is stored as ASCII string.
 */
typedef PACKED struct
{
   /* Lock code array */
   byte                                             digits[NV_LOCK_CODE_SIZE];
} nv_lock_code_type;

/* Air time counter */
typedef PACKED struct
{
   /* NAM id 0-N */
   byte                                             nam;
   /* count */
   dword                                            cnt;
} nv_call_cnt_type;

/* Type to hold the standing alarms for India DOT */
typedef PACKED struct
{
   /* which standing alarm */
   byte                                             alarm_id;
   /* DOT alarms */
   dword                                            alarms;
} nv_alarms_type;

/* Type to hold the standing alarms for India DOT */
typedef PACKED struct
{
   /* isd std password */
   byte                                             isd_std_passwd[NV_ISD_STD_PASSWD_SIZ];
} nv_isd_std_passwd_type;

/* Type to specify which type of keypress sound should be emitted. */
typedef  word  nv_key_sound_enum_type;
/* Emit clicks for key presses */
#define  NV_KEY_SOUND_CLICK                            ((nv_key_sound_enum_type)0)
/* Emit tones for key presses */
#define  NV_KEY_SOUND_TONES                            ((nv_key_sound_enum_type)1)

/* Type to specify use of which phone book sorting method */
typedef  word  nv_dials_sort_enum_type;
/* Sort entries alphabetically */
#define  NV_SORT_ALPHABETICAL                          ((nv_dials_sort_enum_type)0)
/* Sort entries by location */
#define  NV_SORT_BY_LOCATION                           ((nv_dials_sort_enum_type)1)

/* Type to specify which language to use for the user interface */
typedef  word  nv_language_enum_type;
/* Use English language */
#define  NV_LANGUAGE_ENGLISH                           ((nv_language_enum_type)0)
/* Use Spanish language */
#define  NV_LANGUAGE_SPANISH                           ((nv_language_enum_type)1)
/* Use French language */
#define  NV_LANGUAGE_FRENCH                            ((nv_language_enum_type)2)
/* Use Portuguese language */
#define  NV_LANGUAGE_PORTUGUESE                        ((nv_language_enum_type)3)

/* Type to specify the user interface menu format */
typedef  word  nv_menu_format_enum_type;
/* Display full menus */
#define  NV_MENU_FULL                                  ((nv_menu_format_enum_type)0)
/* Display short menus */
#define  NV_MENU_SHORT                                 ((nv_menu_format_enum_type)1)

/* Type for ISS2 dialing plan restriction levels */
typedef PACKED struct
{
   /* Type for ISS2 dialing plan restriction levels. */
   byte                                             restriction_level[NV_DIAL_RESTRICT_LVLS_SIZE];
} nv_dial_restrict_lvls_type;

/* Type to hold the downloadable roaming messages */
typedef PACKED struct
{
   /* Which table entry to reference */
   byte                                             index;
   /* The roaming message text */
   byte                                             text[NV_ROAM_MSG_MAX_SIZE];
} nv_roam_msg_type;

/* Type for the number of entries in the table */
typedef PACKED struct
{
   /* Number of elem_type entries currently stored */
   word                                             length;
} nv_dial_state_table_len_type;

/* Type of the elements within the table. */
typedef PACKED struct
{
   /* Storage index */
   byte                                             address;
   /* next state */
   byte                                             next_state[NV_DIAL_STATE_TABLE_NEXT_STATES];
   /* timeout */
   byte                                             timeout;
   /* restriction_level */
   byte                                             restriction_level;
   /* remaining_digits */
   byte                                             remaining_digits;
} nv_dial_state_table_elem_type;

/* Type definitions for DTACO */
typedef  word  nv_dtaco_enum_type;
/* DTACO disabled */
#define  NV_DTACO_DISABLED                             ((nv_dtaco_enum_type)0)
/* DTACO enabled */
#define  NV_DTACO_ENABLED                              ((nv_dtaco_enum_type)1)
/* DTACO enabled on flip */
#define  NV_DTACO_ENABLED_ON_FLIP                      ((nv_dtaco_enum_type)2)

/* Type definitions for DTACO */
typedef PACKED struct
{

   nv_dtaco_enum_type                               dtaco_control;
} nv_dtaco_control_type;

/* Type definitions for Carrier Info items. */
typedef PACKED struct
{
   /* Element ID: 0, 1, or 2 */
   byte                                             element;
   /* data */
   byte                                             data[NV_CARRIER_INFO_ELEMENT_SIZE];
} nv_carrier_info_type;

/* Type definitions for UI date/time format display. */
typedef  word  nv_time_fmt_enum_type;
/*  Use 12MMDD  */
#define  NV_TIME_FMT_12MMDD                            ((nv_time_fmt_enum_type)0)
/*  Use 12DDMM  */
#define  NV_TIME_FMT_12DDMM                            ((nv_time_fmt_enum_type)1)
/*  Use 24MMDD  */
#define  NV_TIME_FMT_24MMDD                            ((nv_time_fmt_enum_type)2)
/*  Use 24DDMM  */
#define  NV_TIME_FMT_24DDMM                            ((nv_time_fmt_enum_type)3)

/* Type definitions for R-UIM CHV. */
typedef PACKED struct
{

   byte                                             digits[NV_RUIM_CHV_SIZE];
} nv_ruim_chv_type;

/* Type definitions for gpsOne transport mechanism */
typedef  word  nv_gps1_transport_type;
/*  Use IP  */
#define  NV_IP_TRANSPORT                               ((nv_gps1_transport_type)0)
/*  Use DBM  */
#define  NV_DBM_TRANSPORT                              ((nv_gps1_transport_type)1)

/* Type definitions for gpsOne Position Calculations */
typedef  word  nv_gps1_position_calc_type;
/*  Use Mobile based Position Calculations  */
#define  NV_POSITION_CALC_MOBILE                       ((nv_gps1_position_calc_type)0)
/*  Use PDE based Position Calculations  */
#define  NV_POSITION_CALC_PDE                          ((nv_gps1_position_calc_type)1)

/* Type definitions for Bluetooth address */
typedef PACKED struct
{

   byte                                             bd_addr[NV_BD_ADDR_SIZE];
} nv_bd_addr_type;

/* Type definitions for Public Land Mobile Network ID */
typedef PACKED struct
{

   byte                                             identity[NV_PLMN_ID_SIZE];
} nv_plmn_id_type;

/* Type definitions for Public Land Mobile Network */
typedef PACKED struct
{
   /* Network ID */
   nv_plmn_id_type                                  plmn_id;
   /* PLMN's radio access technology */
   byte                                             rat;
   /* Circuit, Packet or Circuit&Packet switched */
   byte                                             service_type;
} nv_plmn_id_info_type;


typedef  word  nv_acq_order_pref_enum_type;
/* Determine acquisition order automatically */
#define  NV_ACQ_ORDER_PREF_AUTOMATIC                   ((nv_acq_order_pref_enum_type)0)
/* Acquisition order is GSM first, followed by WCDMA */
#define  NV_ACQ_ORDER_PREF_GSM_WCDMA                   ((nv_acq_order_pref_enum_type)1)
/* Acquisition order is WCDMA first, followed by GSM */
#define  NV_ACQ_ORDER_PREF_WCDMA_GSM                   ((nv_acq_order_pref_enum_type)2)

/* acq order pref type */
typedef PACKED struct
{
   /* NAM */
   byte                                             nam;
   /* acquisition order preference */
   nv_acq_order_pref_enum_type                      acq_order;
} nv_acq_order_pref_type;


typedef  word  nv_net_sel_mode_pref_enum_type;
/* Select network automatically */
#define  NV_NET_SEL_MODE_PREF_AUTOMATIC                ((nv_net_sel_mode_pref_enum_type)0)
/* Select network manually */
#define  NV_NET_SEL_MODE_PREF_MANUAL                   ((nv_net_sel_mode_pref_enum_type)1)
/* Select network for limited service */
#define  NV_NET_SEL_MODE_PREF_LIMITED_SRV              ((nv_net_sel_mode_pref_enum_type)2)

/* network selection mode pref type */
typedef PACKED struct
{
   /* NAM */
   byte                                             nam;
   /* network selection mode preference */
   nv_net_sel_mode_pref_enum_type                   net_sel_mode;
} nv_net_sel_mode_pref_type;


typedef  word  nv_srv_domain_pref_enum_type;
/* Prefer Circuit Switched only */
#define  NV_SRV_DOMAIN_PREF_CS_ONLY                    ((nv_srv_domain_pref_enum_type)0)
/* Prefer Packet Switched only */
#define  NV_SRV_DOMAIN_PREF_PS_ONLY                    ((nv_srv_domain_pref_enum_type)1)
/* Prefer Circuit and Packet Switched only */
#define  NV_SRV_DOMAIN_PREF_CS_PS                      ((nv_srv_domain_pref_enum_type)2)
/* Prefer Any service domain */
#define  NV_SRV_DOMAIN_PREF_ANY                        ((nv_srv_domain_pref_enum_type)3)

/* service domain pref type */
typedef PACKED struct
{
   /* NAM */
   byte                                             nam;
   /* service domain preference */
   nv_srv_domain_pref_enum_type                     srv_domain;
} nv_srv_domain_pref_type;


typedef PACKED struct
{
   /* PLMN ID of the registered PLMN that sent the equi. PLMN list */
   nv_plmn_id_type                                  rplmn;
   /* Number of PLMNs in the list */
   uint8                                            length;
   /* Array of equivalent PLMNs */
   nv_plmn_id_type                                  plmn[NV_EQUIVALENT_PLMN_LIST_MAX_SIZE];
} nv_equivalent_plmn_list_type;


typedef  word  nv_rtre_configuration_type;
/* RTRE configuration: use R-UIM only */
#define  NV_RTRE_CONFIG_RUIM_ONLY                      ((nv_rtre_configuration_type)0)
/* RTRE configuration: use NV only */
#define  NV_RTRE_CONFIG_NV_ONLY                        ((nv_rtre_configuration_type)1)
/* RTRE configuration: use R-UIM if available or NV */
#define  NV_RTRE_CONFIG_RUIM_OR_DROP_BACK              ((nv_rtre_configuration_type)2)
/* RTRE configuration: GSM on 1x */
#define  NV_RTRE_CONFIG_SIM_ACCESS                     ((nv_rtre_configuration_type)3)

/* RTRE control type */
typedef  word  nv_rtre_control_type;
/* Use the R-UIM */
#define  NV_RTRE_CONTROL_USE_RUIM                      ((nv_rtre_control_type)0)
/* Do not use the R-UIM */
#define  NV_RTRE_CONTROL_NO_RUIM                       ((nv_rtre_control_type)1)
/* Use a GSM card for provisioning, no R-UIM functions */
#define  NV_RTRE_CONTROL_SIM_ACCESS                    ((nv_rtre_control_type)2)

/* RTRE polling control type */
typedef  word  nv_rtre_polling_control_type;
/* Do not poll the UIM card */
#define  NV_RTRE_POLLING_CONTROL_NO_POLL               ((nv_rtre_polling_control_type)0)
/* Poll the UIM card */
#define  NV_RTRE_POLLING_CONTROL_POLL                  ((nv_rtre_polling_control_type)1)


typedef  word  nv_uim_first_inst_class_type;
/* First UIM instruction class: GSM SIM */
#define  NV_UIM_FIRST_INST_CLASS_GSM_SIM               ((nv_uim_first_inst_class_type)0)
/* First UIM instruction class: UMTS SIM */
#define  NV_UIM_FIRST_INST_CLASS_UMTS_SIM              ((nv_uim_first_inst_class_type)1)


typedef PACKED struct
{

   word                                             option;
} nv_err_fatal_options_type;


typedef  word  nv_uim_pref_protocol_type;
/* Preferred Protocol T=0 */
#define  NV_UIM_PREF_PROTOCOL_T_0                      ((nv_uim_pref_protocol_type)0)
/* Preferred Protocol T=1 */
#define  NV_UIM_PREF_PROTOCOL_T_1                      ((nv_uim_pref_protocol_type)1)
/* Preferred Protocol None */
#define  NV_UIM_PREF_PROTOCOL_NONE                     ((nv_uim_pref_protocol_type)2)

/* Type for NV_UIM_CDMA_PREF_SLOT_I and NV_UIM_GSM_PREF_SLOT_I */
typedef  word  nv_uim_slot_type;
/* Preferred slot None */
#define  NV_UIM_SLOT_NONE                              ((nv_uim_slot_type)0)
/* Preferred slot 1 */
#define  NV_UIM_SLOT_1                                 ((nv_uim_slot_type)1)
/* Preferred slot 2 */
#define  NV_UIM_SLOT_2                                 ((nv_uim_slot_type)2)

/* Type for NV_RPLMNACT_I */
typedef PACKED struct
{

   byte                                             act[2];
} nv_rplmnact_type;

/* Type to hold UE IMEI */
typedef PACKED struct
{
   /* International Mobile Equipment Identity */
   byte                                             ue_imei[NV_UE_IMEI_SIZE];
} nv_ue_imei_type;

/* This structure defines the PLMN */
typedef PACKED struct
{
   /* Mobile Country Code - one digit per byte range 0..9) */
   byte                                             mcc[MAX_MCC_DIGITS];
   /* Number of MNC digits */
   byte                                             num_mnc_digits;
   /* Mobile Network Code - one digit per byte (range 0..9) */
   byte                                             mnc[MAX_MNC_DIGITS];
} nv_rrc_plmn_identity_type;

/* Enumerates all possible band classes */
typedef PACKED enum
{

   NV_RRC_CSP_BAND_PCS                            = 0,

   NV_RRC_CSP_BAND_CELL                           = 1,

   NV_RRC_CSP_BAND_IMT2K                          = 2
} nv_rrc_csp_band_class_e_type;

/* Acquisition entry type */
typedef PACKED struct
{
   /* PLMN ID */
   nv_rrc_plmn_identity_type                        plmn_id;
   /* Frequency where PLMN is present */
   uint32                                           freq;
   /* Band Class */
   nv_rrc_csp_band_class_e_type                     band_class;
   /* Type of this stored acquisition entry */
   uint32                                           status_mask;
   /* Current Cell ID selected */
   uint32                                           cell_id;
   /* Scrambling Code of the Cell */
   uint32                                           scr_code;
   /* Location Area Code of the cell */
   uint32                                           lac;
} nv_acq_entry_type;

/* Acquisition database */
typedef PACKED struct
{
   /* Next Acquisition pointer to be read */
   uint32                                           curr_rd_index;
   /* Next Acquisition pointer to write */
   uint32                                           curr_wr_index;
   /* Indicates if the last entry in database pointer list is Invalid */
   boolean                                          last_entry_invalid;
   /* List of ordered indices to acquisition entries */
   uint8                                            acq_list_indices[MAX_ACQ_DB_ENTRIES];
} nv_acq_db_type;

/* List of Acquisition entries */
typedef PACKED struct
{
   /* Acquisition entry */
   nv_acq_entry_type                                acq_entry[3];
} nv_acq_list1_type;

/* List of Acquisition entries */
typedef PACKED struct
{
   /* Acquisition entry */
   nv_acq_entry_type                                acq_entry[2];
} nv_acq_list2_type;


typedef PACKED struct
{

   word                                             value[NV_TX_BURST_RAMP_SIZ];
} nv_tx_burst_ramp_index_type;



typedef PACKED struct
{

   int8                                             max_gainrange_1;

   int8                                             min_gainrange_2;

   int8                                             max_gainrange_2;

   int8                                             min_gainrange_3;

   int8                                             max_gainrange_3;

   int8                                             min_gainrange_4;
} nv_gainrange_switchpoint_type;


typedef  word  nv_sys_band_T;

#define  NV_SYS_BAND_EGSM_900                          ((nv_sys_band_T)0)

#define  NV_SYS_BAND_PGSM_900                          ((nv_sys_band_T)1)

#define  NV_SYS_BAND_PCS_1900                          ((nv_sys_band_T)2)

#define  NV_SYS_BAND_DCS_1800                          ((nv_sys_band_T)3)

#define  NV_SYS_BAND_CELL_850                          ((nv_sys_band_T)4)

/* ARFCN type, includes band if quadband is supported */
typedef PACKED struct
{

   uint16                                           num;

   nv_sys_band_T                                    band;
} NV_ARFCN_T;


typedef PACKED struct
{

   byte                                             no_of_entries;

   NV_ARFCN_T                                       last_best_cells[NV_MAX_NUMBER_OF_BEST_CELLS];
} nv_rr_stored_last_best_arfcns_band_type;

/* prl */
typedef PACKED struct
{
   /* nam */
   byte                                             nam;
   /* prl */
   uint32                                           prl;
} nv_prl_pref_type;


typedef PACKED struct
{
   /* nam */
   uint8                                            nam;
   /* WLAN Technology Preference */
   uint32                                           tech_pref;
} nv_wlan_tech_pref_type;


typedef PACKED struct
{
   /* Max. Power in dBm of AMAM Master  table */
   int32                                            maxdBm;
   /* Min power in dBm of AMAM master table */
   int32                                            mindBm;
} nv_amam_dynamic_range;

typedef PACKED struct
{
   /* Power in dBm measured at dacval */
   int16                                            pwrdBm;
   /* Dac value at which power is measured */
   uint16                                           dacval;
} nv_autocal_pwr_dac_type;

typedef PACKED struct
{
   int16                                            Aval[4]; //A Value
   int16                                            Bval[4]; //B Value
} nv_rtr6250_rsb_type;

typedef PACKED struct
{
   byte			i_value;
   byte			q_value;
   byte			t_value;
} nv_intelliceiver_im2_type;


typedef PACKED struct
{
   uint16   channel[3];
   uint8    idac[3];
   uint8    qdac[3];
   uint8    gm;
} nv_gsm_im2_type;


/*=========================================================================*/
/* NVM Items Union Type.                                                   */
/*=========================================================================*/

#pragma component(mintypeinfo, on )
union nv_item_type
{
   /* NV Peek Operation */
   nv_peek_type                                     peek;
   /* NV Poke Operation */
   nv_poke_type                                     poke;
   /* OTASP Commit operation - writes several NV items */
   nv_otasp_commit_type                             *otasp_commit;
   /* Electronic Serial Number */
   nv_esn_type                                      esn;
   /* Checksum for Electronic Serial Number */
   nv_esn_chksum_type                               esn_chksum;
   /* NV major version number, changing it forces an NV rebuild */
   byte                                             verno_maj;
   /* NV minor version number, changing it forces an NV rebuild */
   byte                                             verno_min;
   /* Station Class Mark is 8 bits, as per CAI section 6.3.3 */
   byte                                             scm;
   /* The mobile Slot Cycle index is 8 bits, per CAI section 1.1.2.2 */
   byte                                             slot_cycle_index;
   /* Mobile CAI revision number (8 bits) */
   byte                                             mob_cai_rev;
   /* Mobile firmware revision number (16 bits) */
   word                                             mob_firm_rev;
   /* Mobile model (8 bits) */
   byte                                             mob_model;
   /* Physical configuration checksum */
   nv_config_chksum_type                            config_chksum;
   /* System preferred mode */
   nv_pref_mode_type                                pref_mode;
   /* CDMA pref serv (A only, A pref, B only, B pref, Home only, SID only) */
   nv_pref_serv_type                                cdma_pref_serv;
   /* Analog pref service  */
   nv_pref_serv_type                                analog_pref_serv;
   /* CDMA SID lockout list for the given NAM */
   nv_sid_lock_type                                 cdma_sid_lock;
   /* CDMA SID Acquisition list for the given NAM */
   nv_sid_acq_type                                  cdma_sid_acq;
   /* Analog SID lockout list */
   nv_sid_lock_type                                 analog_sid_lock;
   /* Analog SID acquisition */
   nv_sid_acq_type                                  analog_sid_acq;
   /* First analog channel for the given NAM */
   nv_firstchp_type                                 analog_firstchp;
   /* Analog home system ID for the given NAM */
   nv_sid_type                                      analog_home_sid;
   /* Analog reg setting (disabled, whereabouts known, whereabouts unknown) */
   nv_analog_reg_type                               analog_reg;
   /* Primary CDMA channel for the given NAM */
   nv_cdmach_type                                   pcdmach;
   /* Secondary CDMA channel for the given NAM */
   nv_cdmach_type                                   scdmach;
   /* Primary PCN channel for the given NAM */
   nv_cdmach_type                                   ppcnch;
   /* Secondary PCN channel for the given NAM */
   nv_cdmach_type                                   spcnch;
   /* NAM checksum */
   nv_nam_chksum_type                               nam_chksum;
   /* Authentication A key (2 words) */
   nv_a_key_type                                    a_key;
   /* Authenitcation A Key chksum */
   nv_a_key_chksum_type                             a_key_chksum;
   /* Shared Secret Data A - used for authentication (2 dwords) */
   nv_ssd_type                                      ssd_a;
   /* Shared Secret Data A checksum */
   nv_ssd_chksum_type                               ssd_a_chksum;
   /* Shared Secret Data B for the given NAM - used for CDMA voice privacy */
   nv_ssd_type                                      ssd_b;
   /* Shared Secret Data B checksum */
   nv_ssd_chksum_type                               ssd_b_chksum;
   /* Roam count - 1 byte for the given nam */
   nv_count_type                                    count;
   /* MIN 1 (phone number) for the given NAM, in quotes, or encoded MIN1 */
   nv_min1_type                                     min1;
   /* MIN 2 (area code) for the given NAM, in quotes, or encoded MIN2 */
   nv_min2_type                                     min2;
   /* CDMA Mobile terminated home SID for the given NAM (true, false) */
   nv_mob_term_type                                 mob_term_home;
   /* CDMA Mobile terminated foreign SID for the given NAM (true, false) */
   nv_mob_term_type                                 mob_term_for_sid;
   /* CDMA Mobile terminated foreign NID for the given NAM (true, false) */
   nv_mob_term_type                                 mob_term_for_nid;
   /* Access overload class for the given nam */
   nv_accolc_type                                   accolc;
   /* Up to 4 CDMA SID/NID pairs for the given NAM */
   nv_sid_nid_type                                  sid_nid;
   /* MIN Checksum for the given NAM */
   nv_min_chksum_type                               min_chksum;
   /* Current NAM */
   byte                                             curr_nam;
   /* Call origination MIN (index 0-3) within the given NAM */
   nv_orig_min_type                                 orig_min;
   /* Auto-select NAM on roaming (not implemented) (true, false) */
   boolean                                          auto_nam;
   /* This item holds the name of each NAM. */
   nv_name_nam_type                                 name_nam;
   /* Next analog registration */
   dword                                            nxtreg;
   /* Last SID registered */
   word                                             lstsid;
   /* Analog location area ID */
   word                                             locaid;
   /* Analog power up registration identifier (true, false) */
   boolean                                          pureg;
   /* CDMA registration zone list */
   nv_zone_list_type                                zone_list;
   /* CDMA SID/NID list */
   nv_sid_nid_list_type                             sid_nid_list;
   /* Distance based registration variables */
   nv_dist_reg_type                                 dist_reg;
   /* Last CDMA channel acquired for the given NAM */
   nv_cdmach_type                                   last_cdmach;
   /* Call timer item */
   nv_call_time_type                                call_timer;
   /* Air timer for the given NAM */
   nv_call_time_type                                air_timer;
   /* Resettable cumulative roam time */
   nv_call_time_type                                roam_timer;
   /* Life time (non-resettable) cumulative call timer */
   nv_call_time_type                                life_timer;
   /* Time hardware has been running (minutes) */
   nv_run_time_type                                 run_timer;
   /* Speed dial number */
   nv_dial_type                                     dial;
   /* Call stack number */
   nv_stdial_type                                   stack;
   /* Call stack last number index */
   nv_stack_idx_type                                stack_idx;
   /* OBSOLETE Page settings */
   nv_page_set_type                                 page_set;
   /* Page message and time (new = true, false) */
   nv_page_msg_type                                 page_msg;
   /* Hanset earpiece volume level (1 min - 255 max, 0 = off) */
   byte                                             ear_level;
   /* Hanset earpiece volume level (1 min - 255 max, 0 = off) */
   byte                                             speaker_level;
   /* External speaker ringer volume (1 min - 255 max, 0 = off) */
   byte                                             ringer_level;
   /* Key beep volume level(1 min - 255 max, 0 = off) */
   byte                                             beep_level;
   /* One minute call beeper select (on, off) */
   boolean                                          call_beep;
   /* Continuous keypad DTMF tones select (on, off) */
   boolean                                          cont_key_dtmf;
   /* Continuous string (memory) DTMF tones select (on, off) */
   boolean                                          cont_str_dtmf;
   /* Service area enter/exit alert select (on, off) */
   boolean                                          svc_area_alert;
   /* Call fade alert select (on, off) */
   boolean                                          call_fade_alert;
   /* Idle banner to display */
   nv_banner_type                                   banner;
   /* Specifies handset brightness with 0 to 255 (0 equals blank). */
   byte                                             lcd;
   /* Auto power off: time to stay on when ignition off */
   byte                                             auto_power;
   /* Auto answer setting */
   nv_auto_answer_type                              auto_answer;
   /* Auto redial setting, time in 10 second units */
   nv_auto_redial_type                              auto_redial;
   /* Auto hyphen setting (on, off) */
   boolean                                          auto_hyphen;
   /* Backlight (0: never on, 1-10: secs before going off, 255: never off) */
   byte                                             back_light;
   /* Auto radio mute setting (on, off) */
   boolean                                          auto_mute;
   /* Base station maintenance reason */
   nv_maintrsn_type                                 maintrsn;
   /* Base station lock reason until power cycled */
   nv_lckrsn_type                                   lckrsn_p;
   /* Indicator of whether user locked the phone */
   byte                                             lock;
   /* Lock code string (4 characters 0-9, representing the lock code) */
   nv_lock_code_type                                lock_code;
   /* Auto lock setting (on, off) */
   boolean                                          auto_lock;
   /* Call restrictions (word, 0 = no restrictions) */
   word                                             call_rstrc;
   /* 6 digit security code, represented by a string of digits (0-9) */
   nv_sec_code_type                                 sec_code;
   /* Horn alert setting (on, off) */
   boolean                                          horn_alert;
   /* Retrievs and adds an entry to the error log */
   nv_err_log_type                                  err_log;
   /* Unit hardware ID */
   dword                                            unit_id;
   /* Frequency adjust values in a 32 byte table in a file */
   nv_freq_adj_type                                 freq_adj;
   /* V battery regulator array values given, or in a file */
   nv_minmax_type                                   vbatt;
   /* Analog tx power level array */
   nv_fm_tx_pwr_type                                fm_tx_pwr;
   /* Frequency Temp offset values in a 64 byte table in a file */
   nv_fr_temp_offset_type                           fr_temp_offset;
   /* SIO mode for DM (HDLC, ASYNC 9.6K, ASYNC 19.2K, ASYNC 38.4K, MONO */
   byte                                             dm_io_mode;
   /* Portable only - to limit TX_GAIN_ADJ when output is exceeded */
   byte                                             cdma_tx_limit;
   /* Portable - Analog RSSI adjustment values given, or in a file */
   nv_minmax_type                                   fm_rssi;
   /* Portable CDMA UHF ripple compensation table values from a file */
   byte                                             cdma_ripple[NV_RIPPLE_COMP_TABLE_SIZ];
   /* CDMA RX Offset compensation */
   byte                                             cdma_rx_offs[NV_RX_OFFSET_TABLE_SIZ];
   /* CDMA RX Power */
   byte                                             cdma_rx_pwr[NV_RX_POWER_TABLE_SIZ];
   /* CDMA RX Error */
   byte                                             cdma_rx_err[NV_RX_ERROR_TABLE_SIZ];
   /* CDMA Tx gain comp slope compensation table values from file */
   byte                                             cdma_tx_slp1[NV_TX_SLOPE_1_TABLE_SIZ];
   /* Portable - CDMA Tx gain adjust slope comp. table values from file */
   byte                                             cdma_tx_slp2[NV_TX_SLOPE_2_TABLE_SIZ];
   /* Portable CDMA Tx non-linear error comp. table values from a file */
   byte                                             cdma_tx_err[NV_TX_NON_LIN_ERR_TABLE_SIZ];
   /* Portable current control table values in a file */
   byte                                             pa_cur_ctl[NV_HDET_TABLE_SIZ];
   /* Special attentuator parameter for Sony chipset (byte) */
   byte                                             sony_atten_1;
   /* Special attentuator parameter for Sony chipset (byte) */
   byte                                             sony_atten_2;
   /* Vocoder gain */
   word                                             voc_gain;
   /* Spare NV item for develper's use (word) */
   word                                             spare_1;
   /* Spare NV item for develper's use (word) */
   word                                             spare_2;
   /* Data services enabled/disabled (on/off) */
   boolean                                          data_srvc_enabled;
   /* External data port mode (9600, 19.2K, 38.4K) */
   byte                                             data_io_mode;
   /* Data services idle time in seconds */
   word                                             idle_data_timeout;
   /* Maximum Tx adjust */
   byte                                             max_tx_adj;
   /* Initial mute setting (norm, mute, spkr) */
   byte                                             init_mute;
   /* Free form factory info - 100 bytes in a file */
   byte                                             fact_info[NV_FACTORY_INFO_SIZ];
   /* Special attentuator parameter for Sony chipset (byte) */
   byte                                             sony_atten_3;
   /* Special attentuator parameter for Sony chipset (byte) */
   byte                                             sony_atten_4;
   /* Special attentuator parameter for Sony chipset (byte) */
   byte                                             sony_atten_5;
   /* Multidrop address of the mobile */
   byte                                             dm_addr;
   /* Short code PN offset mask choice - 0: off-by-one, 1:IS-95 compliant */
   byte                                             cdma_pn_mask;
   /* Time (secs) from last digit dialed until phone number is sent (ISS-1) */
   byte                                             send_timeout;
   /* NGP FM TX_AGC_ADJ setting vs power - 16 bytes in a file */
   byte                                             fm_agc_set_vs_pwr[NV_PWR_TABLE_SIZ];
   /* NGP FM TX_AGC_ADJ setting vs frequency - 16 int1s in a file */
   int1                                             fm_agc_set_vs_freq[NV_FREQ_TABLE_SIZ];
   /* NGP FM TX_AGC_ADJ setting vs temperature - 8 int1s in a file */
   int1                                             fm_agc_set_vs_temp[NV_TEMP_TABLE_SIZ];
   /* NGP FM expected HDET reading vs power - 16 bytes in a file */
   byte                                             fm_exp_hdet_vs_pwr[NV_PWR_TABLE_SIZ];
   /* NGP FM HDET error slope vs power - 16 bytes in a file */
   byte                                             fm_err_slp_vs_pwr[NV_PWR_TABLE_SIZ];
   /* NGP Deviation adj. trim - one byte, or one byte in a file */
   byte                                             fm_freq_sense_gain;
   /* NGP CDMA Rx linearizer offset - one byte, or one byte in a file */
   byte                                             cdma_rx_lin_off_0;
   /* NGP CDMA Rx linearizer slope - 16 bytes in a file */
   byte                                             cdma_rx_lin_slp[NV_CDMA_RX_LIN_SIZ];
   /* CDMA RX compensation table vs frequency */
   int1                                             cdma_rx_comp_vs_freq[NV_FREQ_TABLE_SIZ];
   /* CDMA RX compensation table vs frequency */
   int1                                             cdma_tx_comp_vs_freq[NV_FREQ_TABLE_SIZ];
   /* CDMA TX compnesation table vs battery voltage */
   int1                                             cdma_tx_comp_vs_volt[NV_VOLT_TABLE_SIZ];
   /* NGP CDMA Tx linearizer master offset: 1 word or 1 word in file */
   word                                             cdma_tx_lin_master_off_0;
   /* NGP CDMA Tx linearizer master slope - 36 bytes in a file */
   byte                                             cdma_tx_lin_master_slp[NV_CDMA_TX_LIN_MASTER_SIZ];
   /* NGP CDMA Tx linearizer trim vs temp - 8 bytes in a file */
   byte                                             cdma_tx_lin_vs_temp[NV_TEMP_TABLE_SIZ];
   /* NGP CDMA Tx linearizer trim vs voltage - 8 bytes in a file */
   byte                                             cdma_tx_lin_vs_volt[NV_VOLT_TABLE_SIZ];
   /* NGP CDMA Tx power limit vs temperature - 8 bytes in a file */
   byte                                             cdma_tx_lim_vs_temp[NV_TEMP_TABLE_SIZ];
   /* NGP CDMA Tx power limit vs voltage - 8 int1s in a file */
   int1                                             cdma_tx_lim_vs_volt[NV_VOLT_TABLE_SIZ];
   /* NGP CDMA Tx power limit vs frequency - 16 int1s in a file */
   int1                                             cdma_tx_lim_vs_freq[NV_FREQ_TABLE_SIZ];
   /* NGP CDMA expected HDET reading vs AGC PDM - 16 bytes in a file */
   byte                                             cdma_exp_hdet_vs_agc[NV_CDMA_EXP_HDET_VS_AGC_SIZ];
   /* NGP CDMA HDET error slope vs HDET reading - 8 bytes in a file */
   byte                                             cdma_err_slp_vs_hdet[NV_CDMA_ERR_SLP_VS_HDET_SIZ];
   /* NGP RF & LCD compensation - 2 bytes, or 2 bytes in a file */
   nv_minmax_type                                   therm;
   /* RF comp based on voltage - 2 bytes given or in a file */
   nv_minmax_type                                   vbatt_pa;
   /* NGP ADC HDET reading offset - one byte, or one byte in a file */
   byte                                             hdet_off;
   /* NGP ADC HDET reading span - one byte, or one byte in a file */
   byte                                             hdet_spn;
   /* NGP ena/dis UI one touch dialing (on, off) */
   boolean                                          onetouch_dial;
   /* FM AGC adjust v. Frequency Table - 16 int1s in a file */
   byte                                             fm_agc_adj_vs_freq[NV_ADJ_VS_FREQ_SIZ];
   /* FM AGC adjust vs. Temperature Table - 8 int1s in a file */
   byte                                             fm_agc_adj_vs_temp[NV_ADJ_VS_TEMP_SIZ];
   /* RF configuration - 1 byte, or one byte in a file */
   byte                                             rf_config;
   /* R1 rise - 1 byte, or one byte in a file */
   byte                                             r1_rise;
   /* R1 fall - 1 byte, or one byte in a file */
   byte                                             r1_fall;
   /* R2 rise - 1 byte, or one byte in a file */
   byte                                             r2_rise;
   /* R2 fall - 1 byte, or one byte in a file */
   byte                                             r2_fall;
   /* R3 rise - 1 byte, or one byte in a file */
   byte                                             r3_rise;
   /* R3 fall - 1 byte, or one byte in a file */
   byte                                             r3_fall;
   /* PA range step calibration - 1 byte, or one byte in a file */
   byte                                             pa_range_step_cal;
   /* LNA range polarization - 1 byte, or one byte in a file */
   byte                                             lna_range_pol;
   /* LNA range rise - 1 byte, or one byte in a file */
   int1                                             lna_range_rise;
   /* LNA range fall - 1 byte - or one byte in a file */
   int1                                             lna_range_fall;
   /* LNA range offset - 1 word, or one word in a file */
   word                                             lna_range_offset;
   /* Count of power cycles - 1 byte */
   dword                                            power_cycles;
   /* Alerts level - 1 byte */
   byte                                             alerts_lvl;
   /* Alerts level shadow - 1 byte */
   byte                                             alerts_lvl_shadow;
   /* Ringer level shadow - 1 byte */
   byte                                             ringer_lvl_shadow;
   /* Beep level shadow - 1 byte */
   byte                                             beep_lvl_shadow;
   /* Ear level shadow - 1 byte */
   byte                                             ear_lvl_shadow;
   /* Boolean whether to show time or not (true, false) */
   boolean                                          time_show;
   /* Air time counter item */
   nv_call_cnt_type                                 air_cnt;
   /* Roam count - 1 byte for the given nam */
   nv_call_cnt_type                                 roam_cnt;
   /* Life count - 1 byte */
   dword                                            life_cnt;
   /* Boolean whether to send PIN or not (true, false) */
   boolean                                          send_pin;
   /* SMS item - Obsolete */
   nv_sms_dm_type                                   sms;
   /* SMS item */
   nv_sms_dm_type                                   sms_obsolete;
   /* Mobile Country Code: string of 3 digits in quotes, or encoded MCC */
   nv_imsi_mcc_type                                 imsi_mcc;
   /* True IMSI Mobile Network Code for given NAM */
   nv_imsi_11_12_type                               imsi_11_12;
   /* Directory Number: string of 10 digits */
   nv_dir_number_type                               dir_number;
   /* Voice privacy - 1 byte */
   byte                                             voice_priv;
   /* Spare byte - obsolete item */
   byte                                             spare_b1;
   /* Spare byte - obsolete item */
   byte                                             spare_b2;
   /* Spare word - obsolete item */
   word                                             spare_w1;
   /* Spare word - obsolete item */
   word                                             spare_w2;
   /* Field Service Code: string of 6 digits */
   nv_fsc_type                                      fsc;
   /* One time alarms for DOT: 1 byte ID, 1 dword DOT alarms */
   nv_alarms_type                                   alarms;
   /* Standing alarm - 1 word */
   word                                             standing_alarm;
   /* ISD STD Password: string of 4 digits */
   nv_isd_std_passwd_type                           isd_std_passwd;
   /* ISD STD Restrictions: 1 byte */
   byte                                             isd_std_restrict;
   /* ISS2 Dialing Plan: 1 word */
   word                                             dialing_plan;
   /* NGP FM LNA control - 2 bytes (min/max) or 2 bytes in the given file */
   nv_minmax_type                                   fm_lna_ctl;
   /* Life time (non-resettable) cumulative call timer */
   nv_run_time_type                                 life_timer_g;
   /* Last call time for given NAM */
   nv_run_time_type                                 call_timer_g;
   /* Power Down count - 1 dword */
   dword                                            pwr_dwn_cnt;
   /* FM Automatic Gain Control */
   nv_minmax_type                                   fm_agc;
   /* FSC2, future use - 1 dword */
   nv_fsc2_type                                     fsc2;
   /* FSC2 checksum, future use - 1 dword */
   nv_fsc2_chksum_type                              fsc2_chksum;
   /* Warranty Date Code - string of 5 chars - 3 date code, 2 swap count */
   nv_wdc_type                                      wdc;
   /* Hardware Configuration - 1 dword */
   dword                                            hw_config;
   /* CDMA Rx Linearizer vs. Temperature table - 8 int1s in a file */
   int1                                             cdma_rx_lin_vs_temp[NV_TEMP_TABLE_SIZ];
   /* CDMA Adjust factor- 1 byte, or 1 byte in a file */
   byte                                             cdma_adj_factor;
   /* CDMA Tx Limit Booster offset - 1 byte, or 1 byte in a file */
   byte                                             cdma_tx_lim_booster_off;
   /* CDMA Rx Slope vs. Temperature table - 8 int1s in a file */
   int1                                             cdma_rx_slp_vs_temp[NV_TEMP_TABLE_SIZ];
   /* CDMA Tx Slope vs. Temperature table - 8 int1s in a file */
   int1                                             cdma_tx_slp_vs_temp[NV_TEMP_TABLE_SIZ];
   /* PA Range vs. Temperature table - 8 int1s in a file */
   int1                                             pa_range_vs_temp[NV_TEMP_TABLE_SIZ];
   /* LNA Switch vs. Temperature table - 8 int1s in a file */
   int1                                             lna_switch_vs_temp[NV_TEMP_TABLE_SIZ];
   /* FM Exp HDET vs. Temperature table - 8 int1s in a file */
   byte                                             fm_exp_hdet_vs_temp[NV_TEMP_TABLE_SIZ];
   /* N1M from IS-95A.  1 byte */
   byte                                             n1m;
   /* Mobile IMSI */
   nv_imsi_type                                     imsi;
   /* IMSI Int'l Mobile Station ID length for given NAM */
   nv_imsi_addr_num_type                            imsi_addr_num;
   /* TMSI zone length for the given NAM */
   nv_tmsi_zone_length_type                         assigning_tmsi_zone_length;
   /* TMSI zone for the given NAM */
   nv_tmsi_zone_type                                assigning_tmsi_zone;
   /* TMSI code for given NAM */
   nv_tmsi_code_type                                tmsi_code;
   /* TMSI expiration time for given NAM */
   nv_tmsi_exp_time_type                            tmsi_exp_timer;
   /* Home PCS frequency block */
   nv_home_block_type                               home_block;
   /* Mobile Directory Number. There is a max of 15 digits for the number */
   nv_mob_dir_data_type                             mob_dir_number;

   nv_roaming_list_union_type                       roaming_list;
   /* Most recently used table for a NAM. */
   nv_mru_table_type                                mru_table;
   /* Auto redial setting, time in 10 second units */
   nv_dial_type                                     redial;
   /* One time keypad subsidy lock. */
   nv_sec_code_type                                 otksl;
   /* Used with PREF_MODE. */
   boolean                                          timed_pref_mode;
   /* Ringer type setting. type is a byte */
   byte                                             ringer_type;
   /* enable/disable answer with any key option */
   boolean                                          any_key_answer;
   /* Hands free kit bklight setting. */
   byte                                             back_light_hfk;
   /* Type of keypress sound emitted. type: 0-Emit tones, 1-Emit clicks */
   nv_key_sound_enum_type                           key_sound;
   /* Phone book sorting method. method: 0-Alphabetical, 1-By Location */
   nv_dials_sort_enum_type                          sorting_method;
   /* Language for user interfaca. language: 0-English, 1-Spanish, 2-French */
   nv_language_enum_type                            language_selection;
   /* Type of user interface. format: 0-Disp full menus, 1-Disp short menus */
   nv_menu_format_enum_type                         menu_format;
   /* External speaker ringer volume */
   byte                                             ringer_spkr_lvl;
   /* External speaker key beep volume */
   byte                                             beep_spkr_lvl;
   /* Most recently used table for a NAM. */
   nv_mru2_table_type                               mru2_table;
   /* Vibrator usage setting */
   byte                                             vibrator;
   /* Opening clam shell answers call */
   boolean                                          flip_answers;
   /* ISS2 dialing restriction levels */
   nv_dial_restrict_lvls_type                       dial_restrict_lvls;
   /* Number elements in state table */
   nv_dial_state_table_len_type                     dial_state_table_len;
   /* ISS2 dialing plan state table */
   nv_dial_state_table_elem_type                    dial_state_table;
   /* Voice privacy alert setting: On/Off */
   byte                                             voice_priv_alert;
   /* IP address obsolete item */
   byte                                             ip_address_obsolete;
   /* Curr gateway obsolete item */
   byte                                             curr_gateway_obsolete;
   /* Data service QNC enable/disable */
   boolean                                          data_qnc_enabled;
   /* Data services Service Option (byte) */
   byte                                             data_so_set;
   /* Unwired Planet link info (IP addresses and key data) */
   nv_up_link_info_type                             up_link_info;
   /* Unwired Planet parameters: Current gateway, alert state, etc. */
   nv_up_parms_type                                 up_parms;
   /* Timer 1 word */
   word                                             elapsed_time;
   /* PDM2 RF Calibration - 1 byte */
   byte                                             pdm2;
   /* Receiver AGC minimum & maximum - two bytes given or in a file */
   nv_minmax_type                                   rx_agc_minmax;
   /* Auxiliary V battery regulator array - (two bytes) given or in a file */
   nv_minmax_type                                   vbatt_aux;
   /* Enable status of DTACO feature {enable, disable, enable_on_flip} */
   nv_dtaco_control_type                            dtaco_control;
   /* DTACO feature timeout after last dialed digit - 1 byte */
   byte                                             dtaco_interdigit_timeout;
   /* PDM1 RF Calibration - 1 byte */
   byte                                             pdm1;
   /* QCT-6x00/7x00 Bell modem feature enable/disable */
   boolean                                          bell_modem;
   /* PDM1 vs. Temperature table - 8 int1s in a a file */
   int1                                             pdm1_vs_temp[NV_TEMP_TABLE_SIZ];
   /* PDM2 vs. Temperature table - 8 int1s in a a file */
   int1                                             pdm2_vs_temp[NV_TEMP_TABLE_SIZ];
   /* CDMA SID/NID pair to lockout for the given NAM and given index(0-9) */
   nv_sid_nid_lock_type                             sid_nid_lock;
   /* Roaming list enabled/disabled */
   nv_enabled_type                                  prl_enabled;
   /* IS-683-A format roaming list */
   nv_roaming_list_union_type                       roaming_list_683;
   /* System preference (A only, B only, Home only, Standard) */
   nv_sys_pref_type                                 system_pref;
   /* Home SID+NID pair item */
   nv_home_sid_nid_type                             home_sid_nid;
   /* Over-The-Air Programming and Activation */
   nv_enabled_type                                  otapa_enabled;
   /* SPASM protection for active NAM */
   nv_enabled_type                                  nam_lock;
   /* True IMSI MIN1, in quotes, or encoded value, for given NAM */
   nv_min1_type                                     imsi_t_s1;
   /* True IMSI MIN2, in quotes, or encoded value, for given NAM */
   nv_min2_type                                     imsi_t_s2;
   /* True IMSI MCC, 3 digits in quotes, or encoded MCC, for given NAM */
   nv_imsi_mcc_type                                 imsi_t_mcc;
   /* True IMSI Mobile Network Code for given NAM */
   nv_imsi_11_12_type                               imsi_t_11_12;
   /* True IMSI Int'l Mobile Station ID length for given NAM */
   nv_imsi_addr_num_type                            imsi_t_addr_num;
   /* Unwired Planet alerts */
   nv_up_alert_record_type                          up_alert_record;
   /* Unwired Planet idle timer */
   word                                             up_idle_timer;
   /* Assumes SMS time stamps are sent as UTC instead of local time */
   boolean                                          sms_utc;
   /* Distinctive ringer sound for incoming roaming calls */
   byte                                             roam_ringer;
   /* Rental timer */
   nv_rental_timer_type                             rental_timer;
   /* Tick size of rental call timer */
   byte                                             rental_timer_inc;
   /* rental timer counter */
   dword                                            rental_cnt;
   /* Use rental call timer */
   boolean                                          rental_timer_enabled;
   /* Enable full system preference display operation */
   boolean                                          full_system_pref;
   /* Ringer frequency on BORSCHT-equipped mobiles (QCT-7x00 & similar) */
   byte                                             borscht_ringer_freq;
   /* Enable pay (coin/card-operated) phone support */
   boolean                                          payphone_enable;
   /* DSP answer detection */
   boolean                                          dsp_answer_det_enable;
   /* EVRC/13K priority: EVRC first, 13K first */
   nv_evrc_pri_enum_type                            evrc_pri;
   /* Class 2.0 analog fax (Obsolete) */
   boolean                                          afax_class_20;
   /* V5.2 control */
   nv_v52_control_enum_type                         v52_control;
   /* Bitmap and ASCII name info for carrier */
   nv_carrier_info_type                             carrier_info;
   /* Analog fax mode */
   nv_afax_type                                     afax;
   /* Serial I/O Powerdown (Distinguish between old & new UARTS */
   boolean                                          sio_pwrdwn;
   /* EVRC voice service options - NAM, EVRC enable, three service options */
   nv_pref_voice_so_type                            pref_voice_so;
   /* Voice Recoginition Hands Free Kit enabled/disabled */
   boolean                                          vrhfk_enabled;
   /* Voice Recoginition Hands Free Kit Voice Answer enabled/disabled */
   boolean                                          vrhfk_voice_answer;
   /* PDM1 vs frequency - 16 int1s in a file */
   int1                                             pdm1_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PDM2 vs frequency - 16 int1s in a file */
   int1                                             pdm2_vs_freq[NV_FREQ_TABLE_SIZ];
   /* SMS auto-deletion enabled status */
   boolean                                          sms_auto_delete;
   /* Enable or disable silent redial */
   boolean                                          srda_enabled;
   /* Indicate keypresses via debug messages */
   boolean                                          output_ui_keys;
   /* Polarity reversal timeout */
   byte                                             pol_rev_timeout;
   /* System Integration test data. filename contains 100 bytes of data */
   byte                                             si_test_data_1[NV_SI_TEST_DATA_SIZE];
   /* System Integration test data. filename contains 100 bytes of data */
   byte                                             si_test_data_2[NV_SI_TEST_DATA_SIZE];
   /* Enable or disable service programming code change via OTASP */
   boolean                                          spc_change_enabled;
   /* Medium Data Rate mode */
   byte                                             data_mdr_mode;
   /* Packet data call origination string. Maximum 16 digits. */
   nv_data_pkt_orig_str_type                        data_pkt_orig_str;
   /* Unwired Planet encryption key */
   nv_up_key_type                                   up_key;
   /* Packet data configuration item */
   byte                                             data_auto_packet_detection;
   /* Automatic volume control */
   boolean                                          auto_volume_enabled;
   /* Enable use of wildcard System ID */
   boolean                                          wildcard_sid;
   /* Roaming notification messages */
   nv_roam_msg_type                                 roam_msg;
   /* One-time keypad subsidy lock flags */
   byte                                             otksl_flag;
   /* Browser Identifier */
   byte                                             browser_type;
   /* Tone for sms reminder */
   byte                                             sms_reminder_tone;
   /* Micro browser data */
   nv_ubrowser_type                                 ubrowser;
   /* BTF Adjustment value */
   int2                                             btf_adjust;
   /* Controls pref display options */
   boolean                                          full_pref_mode;
   /* Browser confirmation screen display option */
   byte                                             up_browser_warn;
   /* FM HDET ADC range */
   nv_fm_hdet_adc_range_type                        fm_hdet_adc_range;
   /* CDMA HDET ADC range */
   byte                                             cdma_hdet_adc_range;
   /* PN code selection */
   nv_pn_id_union_type                              pn_id;
   /* Enable/Disable User Zone table */
   boolean                                          user_zone_enabled;
   /* User Zone Table */
   nv_user_zone_type                                user_zone;

   byte                                             pap_data_obsolete;
   /* Default user AT command profile */
   byte                                             data_default_profile;
   /* User ID for Password Authentication Protocol */
   nv_pap_user_id_type                              pap_user_id;
   /* Actual Password for Password Authentication Protocol */
   nv_pap_password_type                             pap_password;
   /* Number of wakeup samples below threshold */
   nv_sta_values_type                               sta_tbye;
   /* Threshold for Rx+Ec/Io (RSSI) trigger */
   nv_sta_values_type                               sta_min_thr;
   /* Threshold for Rx trigger */
   nv_sta_values_type                               sta_min_rx;
   /* Threshold for Rx-Only idle trigger */
   nv_sta_values_type                               sta_min_ecio;
   /* Switch to AMPS priority setting */
   byte                                             sta_pri;
   /* PCS Rx linearizer offset */
   byte                                             pcs_rx_lin_off_0;
   /* PCS Rx linearizer slop */
   byte                                             pcs_rx_lin_slp[NV_PCS_RX_LIN_SIZ];
   /* PCS Rx gain comp vs frequency */
   int1                                             pcs_rx_comp_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PCS Tx gain comp vs frequency */
   int1                                             pcs_tx_comp_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PCS Tx linearizer master offset */
   word                                             pcs_tx_lin_master_off_0;
   /* PCS Tx linearizer master slope */
   byte                                             pcs_tx_lin_master_slp[NV_PCS_TX_LIN_MASTER_SIZ];
   /* PCS Tx power limit vs temperature */
   byte                                             pcs_tx_lin_vs_temp[NV_TEMP_TABLE_SIZ];
   /* PCS Tx power limit vs temperature */
   byte                                             pcs_tx_lim_vs_temp[NV_TEMP_TABLE_SIZ];
   /* PCS Tx power limit vs frequency */
   int1                                             pcs_tx_lim_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PCS expected HDET reaing vs AGC PDM */
   byte                                             pcs_exp_hdet_vs_agc[NV_PCS_EXP_HDET_VS_AGC_SIZ];
   /* ADC HDET reading offset */
   byte                                             pcs_hdet_off;
   /* ADC HDET reading span */
   byte                                             pcs_hdet_spn;
   /* TX output power level at which PA is stepped up */
   byte                                             pcs_r1_rise;
   /* TX output power level at which PA is stepped down */
   byte                                             pcs_r1_fall;
   /* TX output power level at which PA is stepped up */
   byte                                             pcs_r2_rise;
   /* TX output power level at which PA is stepped down */
   byte                                             pcs_r2_fall;
   /* TX output power level at which PA is stepped up */
   byte                                             pcs_r3_rise;
   /* TX output power level at which PA is stepped down */
   byte                                             pcs_r3_fall;
   /* Calibrate PA range gain step */
   byte                                             pcs_pa_range_step_cal;
   /* PDM1 vs frequency compensation table */
   int1                                             pcs_pdm1_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PDM2 vs frequency compensation table */
   int1                                             pcs_pdm2_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Polarity of LNA range control signal */
   byte                                             pcs_lna_range_pol;
   /* Receive power level at which LNA should be bypassed */
   int1                                             pcs_lna_range_rise;
   /* Receive power level at which LNA should be turned on */
   int1                                             pcs_lna_range_fall;
   /* Value that is added to receive power reading when LNA is bypassed */
   word                                             pcs_lna_range_offset;
   /* PCS Rx linearizer vs temperature */
   int1                                             pcs_rx_lin_vs_temp[NV_TEMP_TABLE_SIZ];
   /* PCS adjustment factor */
   byte                                             pcs_adj_factor;
   /* Changes in PA_RANGE_STEP over temp */
   int1                                             pcs_pa_range_vs_temp[NV_TEMP_TABLE_SIZ];
   /* TX temperature compensation using PDM1 */
   int1                                             pcs_pdm1_vs_temp[NV_TEMP_TABLE_SIZ];
   /* TX temperature compensation using PDM2 */
   int1                                             pcs_pdm2_vs_temp[NV_TEMP_TABLE_SIZ];
   /* Slope variations of Master RX linearizer curve over temperature */
   int1                                             pcs_rx_slp_vs_temp[NV_TEMP_TABLE_SIZ];
   /* Slope variations of Master TX linearizer curve over temperature */
   int1                                             pcs_tx_slp_vs_temp[NV_TEMP_TABLE_SIZ];
   /* Receiver AGC min-max */
   nv_minmax_type                                   pcs_rx_agc_minmax;
   /* PA offsets */
   nv_pa_offset_type                                pa_offsets[NV_NUM_PA_RANGES];
   /* CAGC forward mode CDMA TX linearizer master table 0. */
   nv_tx_linearizer_type                            cdma_tx_lin_master0;
   /* CAGC forward mode CDMA TX linearizer master table 1. */
   nv_tx_linearizer_type                            cdma_tx_lin_master1;
   /* CAGC forward mode CDMA TX linearizer master table 2. */
   nv_tx_linearizer_type                            cdma_tx_lin_master2;
   /* CAGC forward mode CDMA TX linearizer master table 3. */
   nv_tx_linearizer_type                            cdma_tx_lin_master3;
   /* CDMA TX linearizer master tables for beta scaling. */
   int16                                            cdma_tx_lin_master_beta_scaling_0[NV_CDMA_TX_LIN_MASTER_BETA_SCALING_SIZ];
   int16                                            cdma_tx_lin_master_beta_scaling_1[NV_CDMA_TX_LIN_MASTER_BETA_SCALING_SIZ];
   int16                                            cdma_tx_lin_master_beta_scaling_2[NV_CDMA_TX_LIN_MASTER_BETA_SCALING_SIZ];
   int16                                            cdma_tx_lin_master_beta_scaling_3[NV_CDMA_TX_LIN_MASTER_BETA_SCALING_SIZ];
   /* Specifies date/time display format. */
   nv_time_fmt_enum_type                            time_fmt_selection;
   /* Broadcast SMS service table siz */
   word                                             sms_bc_service_table_size;
   /* Broadcast SMS service table to contain service/language details */
   nv_sms_bc_service_table_type                     sms_bc_service_table;
   /* Broadcast SMS config identifies services, carrier disabled or enabled */
   byte                                             sms_bc_config;
   /* Broadcast SMS user preferences, deactivated or activated */
   byte                                             sms_bc_user_pref;
   /* Receive power level to bypass the second LNA */
   int1                                             lna_range_2_rise;
   /* Receive power level to turn ON the second LNA */
   int1                                             lna_range_2_fall;
   /* Offset added to receive power when the 1st and 2nd LNAs are bypassed */
   int2                                             lna_range_12_offset;
   /* Duration of non-bypass state multiples of 52us (3-bits) */
   byte                                             nonbypass_timer;
   /* Duration of bypass state multiples of 6.6ms (5-bits) */
   byte                                             bypass_timer;
   /* LNA1 InterMod anti-jamming threshold power level */
   byte                                             im_level1;
   /* LNA2 InterMod anti-jamming threshold power level */
   byte                                             im_level2;
   /* NV_LNA_RANGE_OFFSET frequency compensation table, units of AGC value */
   int1                                             cdma_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* NV_LNA_12_RANGE_OFFSET freq compensation table, units of AGC value */
   int1                                             cdma_lna_12_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Phase rotation setting for LNA_DECISION 01 and 11 */
   byte                                             agc_phase_offset;
   /* RX_AGC_MIN_11 is used to limit Rx AGC value when 2nd LNA is bypassed */
   nv_minmax_type                                   rx_agc_min_11;
   /* Receive power level to bypass the second LNA */
   int1                                             pcs_lna_range_2_rise;
   /* Receive power level to turn ON the second LNA */
   int1                                             pcs_lna_range_2_fall;
   /* Offset added to Receive power when the 1st and 2nd LNAs are bypassed */
   int2                                             pcs_lna_range_12_offset;
   /* Duration of non-bypass state multiples of 52us (3-bits) */
   byte                                             pcs_nonbypass_timer;
   /* Duration of bypass state multiples of 6.6ms (5-bits) */
   byte                                             pcs_bypass_timer;
   /* LNA1 InterMod anti-jamming threshold power level */
   byte                                             pcs_im_level1;
   /* LNA2 InterMod anti-jamming threshold power level */
   byte                                             pcs_im_level2;
   /* NV_LNA_RANGE_OFFSET frequency compensation table, units of AGC value */
   int1                                             pcs_cdma_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* NV_LNA_12_RANGE_OFFSET freq compensation table, units of AGC value */
   int1                                             pcs_cdma_lna_12_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Phase rotation setting for LNA_DECISION 01 and 11 */
   byte                                             pcs_agc_phase_offset;
   /* RX_AGC_MIN_11 is used to limit Rx AGC value when 2nd LNA is bypassed */
   nv_minmax_type                                   pcs_rx_agc_min_11;
   /* Card Holder Verification 1 for R-UIM */
   nv_ruim_chv_type                                 ruim_chv_1;
   /* Card Holder Verification 2 for R-UIM */
   nv_ruim_chv_type                                 ruim_chv_2;
   /* gpsOne Capabilities */
   byte                                             gps1_capabilities;
   /* PDE TCP Address */
   dword                                            gps1_pde_address;
   /* Position Determination Services Lock-out */
   boolean                                          gps1_allowed;
   /* Perferred transport mechanism */
   nv_gps1_transport_type                           gps1_pde_transport;
   /* Mobile vs PDE based Position Calculations */
   nv_gps1_position_calc_type                       gps1_mobile_calc;
   /* IS2000 CAI radio configuration RC preference */
   nv_rc_pref_type                                  pref_for_rc;
   /* DATA SERVICES default SIO baud rate */
   nv_sio_baud_type                                 ds_default_baud;
   /* DIAG default SIO baud rate */
   nv_sio_baud_type                                 diag_default_baud;
   /* Serial Device Mapper configuration menu item information */
   int1                                             sio_dev_map_menu_item;
   /* Specifies whether TTY is enabled or disabled */
   byte                                             tty;
   /* Digitally compensate for PA gain steps in each of the 4 PA states */
   int2                                             pa_range_offsets[NV_NUM_PA_RANGES];
   /* For temp. and freq. compensation of the Tx linearizer */
   nv_tx_comp_type                                  tx_comp0;
   /* Stereo DAC Multimedia volume level */
   byte                                             mm_sdac_lvl;
   /* Stereo DAC key beep volume level */
   byte                                             beep_sdac_lvl;
   /* Stereo DAC volume level */
   byte                                             sdac_lvl;
   /* Handset Multimedia volume level */
   byte                                             mm_lvl;
   /* Headset Multimedia volume level */
   byte                                             mm_lvl_shadow;
   /* HFK Multimedia volume level */
   byte                                             mm_speaker_lvl;
   /* Multimedia play mode */
   byte                                             mm_play_mode;
   /* Multimedia play mode */
   byte                                             mm_repeat_mode;
   /* For temp. and freq. compensation of the Tx linearizer */
   nv_tx_comp_type                                  tx_comp1;
   /* For temp. and freq. compensation of the Tx linearizer */
   nv_tx_comp_type                                  tx_comp2;
   /* For temp. and freq. compensation of the Tx linearizer */
   nv_tx_comp_type                                  tx_comp3;
   /* The Primary IP Address of the DNS Server */
   dword                                            primary_dns;
   /* The Secondary IP Address of the DNS Server */
   dword                                            secondary_dns;
   /* Info for DIAG boot port selection */
   byte                                             diag_port_select;
   /* Listening port associated with PDE address */
   dword                                            gps1_pde_port;
   /* Multimedia ringer filename */
   byte                                             mm_ringer_file[40];
   /* Multimedia file location */
   byte                                             mm_storage_device;
   /* Enables/disables the mobile's ability to SCRM. */
   boolean                                          data_scrm_enabled;

   nv_ruim_sms_status_type                          ruim_sms_status;
   /* PCS Tx linearizer Table for internal PA=00 */
   nv_tx_linearizer_type                            pcs_tx_lin_master0;
   /* PCS Tx linearizer Table for internal PA=01 */
   nv_tx_linearizer_type                            pcs_tx_lin_master1;
   /* PCS Tx linearizer Table for internal PA=10 */
   nv_tx_linearizer_type                            pcs_tx_lin_master2;
   /* PCS Tx linearizer Table for internal PA=11 */
   nv_tx_linearizer_type                            pcs_tx_lin_master3;
   /* PCS PA range offsets */
   int2                                             pcs_pa_range_offsets[NV_NUM_PA_RANGES];
   /* pcs transmit frequency compensation table 0 */
   nv_tx_comp_type                                  pcs_tx_comp0;
   /* pcs transmit frequency compensation table 1 */
   nv_tx_comp_type                                  pcs_tx_comp1;
   /* pcs transmit frequency compensation table 2 */
   nv_tx_comp_type                                  pcs_tx_comp2;
   /* pcs transmit frequency compensation table 3 */
   nv_tx_comp_type                                  pcs_tx_comp3;
   /* One-time startup configuration for DIAG services. */
   nv_diag_restart_config_type                      diag_restart_config;
   /* Stores the band-class preference on a per NAM basis */
   nv_band_pref_type                                band_pref;
   /* Stores the roaming preference on a per NAM basis */
   nv_roam_pref_type                                roam_pref;
   /* GPS RF Signal Delay */
   word                                             gps1_gps_rf_delay;
   /* CDMA RF Signal Delay */
   word                                             gps1_cdma_rf_delay;
   /* CHIPX8 delay for SYNC80M via 1900mhz PCS path in RF card, biased +25. */
   dword                                            pcs_enc_btf;
   /* CHIPX8 delay for SYNC80M via 800mhz CDMA path in RF card, biased +25. */
   dword                                            cdma_enc_btf;
   /* Bluetooth device address of the mobile */
   nv_bd_addr_type                                  bd_addr;
   /* Provides the less-than-one-PCG warm-up for the PA. */
   word                                             subpcg_pa_warmup_delay;
   /* RF Loss in GPS RF Chain */
   byte                                             gps1_gps_rf_loss;
   /* In IS2000, if mobile should self-throttle R-SCH. */
   boolean                                          data_trtl_enabled;
   /* AMPS backstop system enabled status */
   nv_enabled_type                                  amps_backstop_enabled;
   /* GPS One lock status */
   dword                                            gps1_lock;
   /* Determines boot up mode of a factory testmode phone */
   byte                                             ftm_mode;
   /* Default Data Services port baud rate */
   nv_sio_baudrate_type                             ds_default_baudrate;
   /* Default diag port baud rate */
   nv_sio_baudrate_type                             diag_default_baudrate;
   /* Stores JCDMA F92 option selected. */
   word                                             jcdma_ds_f92;
   /* The mode for Mobile IP behavior */
   byte                                             ds_qcmip;
   /* The number of Mobile IP Registration Retries attempted */
   byte                                             ds_mip_retries;
   /* The initial interval between mobile IP registration attempts */
   byte                                             ds_mip_retry_int;
   /* The time before Mobile IP reg. expiration to attempt re-registration. */
   byte                                             ds_mip_pre_re_rrq_time;
   /* Number of populated MIP profiles */
   byte                                             ds_mip_num_prof;
   /* The currently active Mobile IP user profile */
   byte                                             ds_mip_active_prof;
   /* Active Mobile IP profile settings */
   nv_ds_mip_gen_user_prof_type                     ds_mip_gen_user_prof;
   /* Active Mobile IP profile settings */
   nv_ds_mip_ss_user_prof_type                      ds_mip_ss_user_prof;
   /* CON - advertised suspend time before sleep upon connection close */
   uint32                                           hdr_con_suspend;
   /* Preferred Control Channel Cycle Enabled */
   uint8                                            hdr_pre_cc_cyc_enabled;
   /* Preferred Control Channel Cycle */
   uint16                                           hdr_pre_cc_cyc;
   /* HDR Search Parameters */
   nv_hdr_srch_params_type                          hdr_srch_params;
   /* SMP - Time at which keep alive timer was started */
   uint32                                           hdrsmp_keep_alive_start;
   /* SMP - Time at which keep alive message was last sent */
   uint32                                           hdrsmp_keep_alive_sent;
   /* keep alive interval */
   uint16                                           hdrsmp_keep_alive_req_int;
   /* AMP - all data related to addresses */
   nv_hdramp_address_data_type                      hdramp_address_data;
   /* SCP - status of the session */
   nv_hdrscp_session_status_enum_type               hdrscp_session_status;
   /* SCP - session token (generated by AN) */
   uint16                                           hdrscp_token;
   /* SCP - list of all protocol subtypes */
   uint16                                           hdrscp_protocol_subtype[NV_HDRSCP_PRTL_SUBTYPE_SIZ];
   /* AMP - time at which the dual addresses expire */
   uint32                                           hdramp_dual_expire_time;
   /* Configuration of current stream */
   uint16                                           hdrstream_curr_stream_cfg[NV_HDR_CURR_STREAM_CFG_SIZ];
   /* HDR Set Management Same Channel Parameters */
   nv_hdr_chan_mgmt_params_type                     hdr_set_mngmt_same_chan;
   /* HDR Set Management Different Channel Parameters */
   nv_hdr_chan_mgmt_params_type                     hdr_set_mngmt_diff_chan;
   /* If we are configured to send unsolicited location updates */
   boolean                                          hdrlup_unsolicited_enabled;
   /* HDR Access MAC InitialConfiguration Attribute */
   nv_hdramac_initial_config_type                   hdramac_initial_config;
   /* HDR Access MAC PowerParameters Attribute */
   nv_hdramac_power_params_type                     hdramac_power_params;
   /* Forward Traffic MAC DRC Gating Attribute */
   uint8                                            hdrfmac_drc_gating;
   /* Forward Traffic MAC HandoffDelays Attribute */
   nv_hdrfmac_handoff_delays_type                   hdrfmac_handoff_delays;
   /* Reverse Traffic MAC PowerParameters Attribute */
   nv_hdrrmac_power_params_type                     hdrrmac_power_params;
   /* Reverse Traffic MAC RateParameters Attribute */
   nv_hdrrmac_rate_params_type                      hdrrmac_rate_params;
   /* Next expected SLP ResetMsg Sequence Number (set to 0 at SessionBoot) */
   uint8                                            hdrslp_reset_seqno;
   /* The backoff values for the medium backoff calibration values */
   uint8                                            pwr_backoff_vs_volt_med[NV_TX_BACKOFF_TABLE_SIZE];
   /* The backoff values for the low backoff calibration values */
   uint8                                            pwr_backoff_vs_volt_low[NV_TX_BACKOFF_TABLE_SIZE];
   /* Three voltages where PA Backoff was characterized */
   uint8                                            pa_backoff_volts[NV_NUM_PA_BCKOFF_CAL_VOLT];
   /* High and low voltages for Vbatt ADC calib. counts */
   nv_minmax_type                                   vbatt_min_max;
   /* Timebase diff. between home agent and mobile for active MIP profile */
   nv_ds_mip_mn_ha_time_delta_type                  ds_mip_mn_ha_time_delta;
   /* Qualcomm PREV 6 MIP handoff optimization enable */
   boolean                                          ds_mip_qc_drs_opt;
   /* CDMA Rx linearizer offset for the second antenna */
   byte                                             ant2_cdma_rx_lin_off_0;
   /* CDMA Rx linearizer slope for the second antenna */
   byte                                             ant2_cdma_rx_lin_slp[NV_CDMA_RX_LIN_SIZ];
   /* CDMA Rx gain comp vs freq. for the second antenna */
   int1                                             ant2_cdma_rx_comp_vs_freq[NV_FREQ_TABLE_SIZ];
   /* CDMA Rx linearizer vs temperature for the second antenna */
   int1                                             ant2_cdma_rx_lin_vs_temp[NV_TEMP_TABLE_SIZ];
   /* PCS/CDMA RF Calibration items */
   int1                                             ant2_cdma_rx_slp_vs_temp[NV_TEMP_TABLE_SIZ];
   /* Value that is added to rec. pwr. reading when LNA is bypassed */
   word                                             ant2_lna_range_offset;
   /* Offset added to Rec. pwr when the 1st and 2nd LNAs are bypassed */
   int2                                             ant2_lna_range_12_offset;
   /* NV_LNA_RANGE_OFFSET freq. compensation table, units of AGC value */
   int1                                             ant2_cdma_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* NV_LNA_12_RANGE_OFFSET freq. compensation table, units of AGC value */
   int1                                             ant2_cdma_lna_12_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PCS/CDMA mode Rx AGC linearization table */
   byte                                             ant2_pcs_rx_lin_off_0;
   /* PCS Rx linearizer slope for the second antenna */
   byte                                             ant2_pcs_rx_lin_slp[NV_PCS_RX_LIN_SIZ];
   /* PCS Rx gain comp vs frequency for the second antenna */
   int1                                             ant2_pcs_rx_comp_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PCS Rx linearizer vs temperature for the second antenna */
   int1                                             ant2_pcs_rx_lin_vs_temp[NV_TEMP_TABLE_SIZ];
   /* Slope variations of Master RX lin. curve for the 2nd antenna */
   int1                                             ant2_pcs_rx_slp_vs_temp[NV_TEMP_TABLE_SIZ];
   /* Value that is added to rec. pwr reading when LNA is bypassed */
   word                                             ant2_pcs_lna_range_offset;
   /* Offset added to Rec. pwr when the 1st and 2nd LNAs are bypassed */
   int2                                             ant2_pcs_lna_range_12_offset;
   /* NV_LNA_RANGE_OFFSET freq. compensation table, units of AGC value */
   int1                                             ant2_pcs_cdma_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* NV_LNA_12_RANGE_OFFSET freq. compensation table, units of AGC value */
   int1                                             ant2_pcs_cdma_lna_12_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* WCDMA Rx AGC linearizer offset value */
   uint16                                           wcdma_rx_lin[NV_WCDMA_RX_LIN_SIZ];
   /* WCDMA RX AGC PDM delta vs. Frequency */
   int8                                             wcdma_rx_comp_vs_freq[NV_FREQ_TABLE_SIZ];
   /* WCDMA Rx AGC PDM delta vs. Temperature */
   int8                                             wcdma_rx_lin_vs_temp[NV_TEMP_TABLE_SIZ];
   /* WCDMA Rx AGC PDM delta vs. Temperature */
   int8                                             wcdma_rx_slp_vs_temp[NV_TEMP_TABLE_SIZ];
   /* WCDMA LNA range polarity */
   uint8                                            wcdma_lna_range_pol;
   /* WCDMA Rx power level at which LNA should be bypassed */
   int16                                            wcdma_lna_range_rise;
   /* WCDMA Rx power level at which LNA should be turned on */
   int16                                            wcdma_lna_range_fall;
   /* LNA InterMod (high to low gain ) anti-jamming threshold power level */
   int16                                            wcdma_im_level;
   /* Duration of non-bypass state in multiple of 66us (8-bits) */
   uint8                                            wcdma_nonbypass_timer;
   /* Duration of bypass state in multiple of 6.6ms (11-bits) */
   uint16                                           wcdma_bypass_timer;
   /* Value that is added to Rx power reading when LNA is bypassed */
   int16                                            wcdma_lna_range_offset;
   /* WCDMA LNA range offset delta vs. frequency in unit of AGC value */
   int8                                             wcdma_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* WCDMA Receiver AGC min */
   int16                                            wcdma_rx_agc_min;
   /* WCDMA Receiver AGC max */
   int16                                            wcdma_rx_agc_max;
   /* WCDMA LNA Phase adjustment when LNA is bypassed */
   uint8                                            wcdma_agc_phase_offset;

   /* WCDMA Tx AGC linearizer master offset value for lowest PA gain state */
   uint16                                           wcdma_tx_lin_master_0[NV_WCDMA_TX_LIN_MASTER_SIZ];
   /* WCDMA Tx AGC enhanced linearizer master offset value for lowest PA gain state */
   uint16                                           wcdma_tx_enh_lin_master_0[NV_TX_LIN_MASTER_ENH_SIZE];
   /* WCDMA Tx AGC linearizer master offset value for highest PA gain state */
   uint16                                           wcdma_tx_lin_master_1[NV_WCDMA_TX_LIN_MASTER_SIZ];

   uint16                                           wcdma_tx_lin_master_2[NV_WCDMA_TX_LIN_MASTER_SIZ];
   uint16                                           wcdma_tx_lin_master_3[NV_WCDMA_TX_LIN_MASTER_SIZ];


   /* Tx Linearizer PDM array for PA Range 0,1,2 and 3 (used for all PA ranges)*/
   uint16                                           wcdma_tx_pdm_lin_x[NV_TX_PDM_LIN_TYPE];
   uint16                                           wcdma_tx_pdm_enh_lin_x[NV_TX_PDM_LIN_ENH_SIZE];


   /* WCDMA Tx AGC delta vs. frequency for lowest PA gain state */
   int8                                             wcdma_tx_comp_vs_freq_0[NV_FREQ_TABLE_SIZ];
   /* WCDMA Tx AGC delta vs. frequency for highest PA gain state */
   int8                                             wcdma_tx_comp_vs_freq_1[NV_FREQ_TABLE_SIZ];

   int8                                             wcdma_tx_comp_vs_freq_2[NV_FREQ_TABLE_SIZ];
   int8                                             wcdma_tx_comp_vs_freq_3[NV_FREQ_TABLE_SIZ];

   /* WCDMA Tx AGC PDM delta vs. temp for lowest PA gain state */
   int8                                             wcdma_tx_lin_vs_temp_0[NV_TEMP_TABLE_SIZ];
   /* WCDMA Tx AGC PDM delta vs. temp for highest PA gain state */
   int8                                             wcdma_tx_lin_vs_temp_1[NV_TEMP_TABLE_SIZ];
   /* WCDMA Tx AGC PDM slope delta vs. temp for lowest PA gain state */
   int8                                             wcdma_tx_slp_vs_temp_0[NV_TEMP_TABLE_SIZ];
   /* WCDMA Tx AGC PDM slope delta vs. temp for highest PA gain state */
   int8                                             wcdma_tx_slp_vs_temp_1[NV_TEMP_TABLE_SIZ];
   /* TX power level to switch PA from lowest to highest gain state */
   uint16                                           wcdma_r1_rise;
   /* TX power level to switch PA from highest to lowest gain state */
   uint16                                           wcdma_r1_fall;
   /* WCDMA Tx power limit vs. temperature (absolute not delta) */
   uint8                                            wcdma_tx_lim_vs_temp[NV_TEMP_TABLE_SIZ];
   /* WCDMA Tx power limit vs. frequency (absolute not delta) */
   int16                                            wcdma_tx_lim_vs_freq[NV_FREQ_TABLE_SIZ];
   /* WCDMA TX power limit gain step adjustment factor */
   uint8                                            wcdma_adj_factor;
   /* WCDMA expected HDET reading vs Tx AGC */
   uint8                                            wcdma_exp_hdet_vs_agc[NV_WCDMA_EXP_HDET_VS_AGC_SIZ];
   /* WCDMA ADC HDET reading offset */
   uint8                                            wcdma_hdet_off;
   /* WCDMA ADC HDET reading span */
   uint8                                            wcdma_hdet_spn;
   /* CHIPX8 delay for SYNC80M via 800mhz CDMA path in RF card, biased +25. */
   uint32                                           wcdma_enc_btf;
   /* RFC2002bis MN-HA authenticator calculation */
   boolean                                          ds_mip_2002bis_mn_ha_auth;
   /* UE rat capability */
   byte                                             ue_rat_capability;
   /* GSM UE operating class */
   byte                                             gsm_ue_op_class;
   /* UMTS UE operating class */
   byte                                             umts_ue_op_class;
   /* International Mobile Equipment Identity */
   nv_ue_imei_type                                  ue_imei;
   /* MSRAC-SMS value */
   byte                                             msrac_sms_value;
   /* MSRAC-SM value */
   byte                                             msrac_sm_value;
   /* GSM A5 Algorithm Support Bitmap */
   byte                                             gsm_a5_algorithms_supported;
   /* Configurable parameters for DRC Lock in HDR */
   nv_hdrfmac_drc_lock_type                         hdrfmac_drc_lock;
   /* LO Calibration offset */
   int16                                            gps1_lo_cal;
   /* GPS Antenna offset in DB */
   int16                                            gps1_ant_off_db;
   /* The len. of time taken for a PCS signal to pass through the RF chain */
   int16                                            gps1_pcs_rf_delay;
   /* Phone number of voice mail center */
   nv_sms_vm_number_type                            sms_vm_number;
   /* Storage for GSM/WCDMA template */
   nv_sms_gw_parms_type                             sms_gw_parms;
   /* Storage for GSM/WCDMA SMS messagesj */
   nv_sms_gw_type                                   sms_gw;
   /* Preferred mode in hybrid operation */
   byte                                             hybrid_pref;
   /* Service Provider ECC is enabled */
   boolean                                          sp_ecc_enabled;
   /* ECC phone numbers */
   byte                                             ecc_list[NV_MAX_NUM_OF_ECC_NUMBER][NV_ECC_NUMBER_SIZE];
   /* Latitude value for the Bluetooth LPOS application */
   uint32                                           bt_lpos_lat;
   /* Longtitude value for the Bluetooth LPOS application */
   uint32                                           bt_lpos_long;
   /* Embedded Phone-t Version */
   byte                                             test_code_ver[NV_SIZE_OF_VERSION];
   /* DMSS S/W Version */
   byte                                             sys_sw_ver[NV_SIZE_OF_VERSION];
   /* RF CAL Program Version */
   byte                                             rf_cal_ver[NV_SIZE_OF_VERSION];
   /* RFCAL configuration file version */
   byte                                             rf_config_ver[NV_SIZE_OF_VERSION];
   /* Date RF calibration was done */
   dword                                            rf_cal_date;
   /* Date RF calibration data loaded */
   dword                                            rf_nv_loaded_date;
   /* Name of RFCAL .dat */
   byte                                             rf_cal_dat_file[NV_QC_SERIAL_NUM_LEN];
   /* Data Services domain name */
   byte                                             domain_name[NV_DOMAIN_NAME_SIZE];
   /* The Public Land Mobile Network preferred by the user */
   nv_plmn_id_info_type                             pref_plmn;
   /* Stores the NAI for 1xEV(HDR) Access Network CHAP Authentication */
   nv_hdr_an_auth_nai_type                          hdr_an_auth_nai;
   /* Stores the password for 1xEV(HDR) Access Network CHAP Authentication */
   nv_hdr_an_auth_password_type                     hdr_an_auth_password;
   /* If the PUZL is enabled or not */
   nv_enabled_type                                  puzl_enabled;
   /* Session configuration for HDR KEP */
   nv_hdrkep_config_type                            hdrkep_config;
   /* Session configuration for HDR AUTH */
   nv_hdrauth_config_type                           hdrauth_config;
   /* 8-bit IM anti-jamming threshold data for the 4th stage */
   int1                                             im_level3;
   /* 8-bit IM anti-jamming threshold data for the 5th stage */
   int1                                             im_level4;
   /* Minimum power output from the AGC accumulator */
   int1                                             agc_value_3_min;
   /* Minimum power output from the AGC accumulator */
   int1                                             agc_value_4_min;
   /* Gain attenuation limit */
   int2                                             tx_gain_atten_limit;
   /* Falling threshold data for the 3rd stage */
   int1                                             cdma_lna_3_fall;
   /* Offset Value subtr from IF VGA linearizer table */
   int2                                             cdma_lna_3_offset;
   /* 8-bit rising threshold data */
   int1                                             cdma_lna_3_rise;
   /* Gain variations of the LNA */
   int1                                             cdma_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* 8-bit falling threshold data */
   int1                                             pcs_lna_3_fall;
   /* Offset to be subtr from IF VGA linearizer table */
   int2                                             pcs_lna_3_offset;
   /* 8-bit rising threshold data */
   int1                                             pcs_lna_3_rise;
   /* Gain variations of the LNA */
   int1                                             pcs_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* 8-bit falling threshold data */
   int1                                             cdma_lna_4_fall;
   /* Offset to be subtr from IF VGA linearizer table */
   int2                                             cdma_lna_4_offset;
   /* 8-bit falling threshold data */
   int1                                             cdma_lna_4_rise;
   /* Gain variations of the LNA */
   int1                                             cdma_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* 8-bit falling threshold data */
   int1                                             pcs_lna_4_fall;
   /* Offset to be subtr from IF VGA linearizer table */
   int2                                             pcs_lna_4_offset;
   /* 8-bit falling threshold data */
   int1                                             pcs_lna_4_rise;
   /* Gain variations of the LNA */
   int1                                             pcs_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* 2nd stage LNA falling threshold */
   int1                                             dfm_lna_fall;
   /* 2nd stage LNA rising threshold offset */
   int2                                             dfm_lna_offset;
   /* 2nd stage LNA rising threshold */
   int1                                             dfm_lna_rise;
   /* offset value when the two-stage LNA is in its 2nd stage */
   int1                                             dfm_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* 2nd stage LNA minimum AGC accumulator output */
   byte                                             dfm_agc_acc_min_1;
   /* AGC filter gain */
   byte                                             dfm_agc_im_gain;
   /* AGC filter gain */
   byte                                             dfm_agc_dc_gain;
   /* 2 stage threshold data */
   int1                                             dfm_im_level1;
   /* No of shifts to the input value of the fine-grained loop */
   byte                                             gps_fg_trk_offset_scaler;
   /* No of shifts to the input value of the fine-grained loop */
   byte                                             digital_fg_trk_offset_scaler;
   /* No of shifts to the input value of the fine-grained loop */
   byte                                             fm_fg_trk_offset_scaler;
   /* Static phase offset for LNA gain step 0 */
   word                                             dfm_lna_s0_phase_offset;
   /* Static phase offset for LNA gain step 1 */
   word                                             dfm_lna_s1_phase_offset;
   /* I accumulator in the coarse-grain DC offset cancellation loop */
   dword                                            cdma_rxf_cg_ioffset;
   /* I accumulator in the coarse-grain DC offset cancellation loop */
   dword                                            pcs_rxf_cg_ioffset;
   /* I accumulator in the coarse-grain DC offset cancellation loop */
   dword                                            fm_rxf_cg_ioffset;
   /* I accumulator in the coarse-grain DC offset cancellation loop */
   dword                                            gps_rxf_cg_ioffset;
   /* Q accumulator in the coarse-grain DC offset cancellation loop */
   dword                                            cdma_rxf_cg_qoffset;
   /* Q accumulator in the coarse-grain DC offset cancellation loop */
   dword                                            pcs_rxf_cg_qoffset;
   /* Q accumulator in the coarse-grain DC offset cancellation loop */
   dword                                            fm_rxf_cg_qoffset;
   /* Q accumulator in the coarse-grain DC offset cancellation loop */
   dword                                            gps_rxf_cg_qoffset;
   /* I accumulator in the fine-grain DC offset cancellation loop */
   dword                                            cdma_rxf_fg_ioffset;
   /* I accumulator in the fine-grain DC offset cancellation loop */
   dword                                            pcs_rxf_fg_ioffset;
   /* I accumulator in the fine-grain DC offset cancellation loop */
   dword                                            fm_rxf_fg_ioffset;
   /* I accumulator in the fine-grain DC offset cancellation loop */
   dword                                            gps_rxf_fg_ioffset;
   /* Q accumulator in the fine-grain DC offset cancellation loop */
   dword                                            cdma_rxf_fg_qoffset;
   /* Q accumulator in the fine-grain DC offset cancellation loop */
   dword                                            pcs_rxf_fg_qoffset;
   /* Q accumulator in the fine-grain DC offset cancellation loop */
   dword                                            fm_rxf_fg_qoffset;
   /* Q accumulator in the fine-grain DC offset cancellation loop */
   dword                                            gps_rxf_fg_qoffset;
   /* I accumulator in the estimator */
   dword                                            cdma_dacc_est_ioffset;
   /* I accumulator in the estimator */
   dword                                            pcs_dacc_est_ioffset;
   /* I accumulator in the estimator */
   dword                                            fm_dacc_est_ioffset;
   /* I accumulator in the estimator */
   dword                                            gps_dacc_est_ioffset;
   /* Q accumulator in the estimator */
   dword                                            cdma_dacc_est_qoffset;
   /* Q accumulator in the estimator */
   dword                                            pcs_dacc_est_qoffset;
   /* Q accumulator in the estimator */
   dword                                            fm_dacc_est_qoffset;
   /* Q accumulator in the estimator */
   dword                                            gps_dacc_est_qoffset;
   /* I accumulator associated with gain step 0 in the DAC controller */
   byte                                             cdma_dacc_iaccum0;
   /* I accumulator associated with gain step 0 in the DAC controller */
   byte                                             pcs_dacc_iaccum0;
   /* I accumulator associated with gain step 0 in the DAC controller */
   byte                                             fm_dacc_iaccum0;
   /* I accumulator associated with gain step 0 in the DAC controller */
   byte                                             gps_dacc_iaccum0;
   /* I accumulator associated with gain step 1 in the DAC controller */
   byte                                             cdma_dacc_iaccum1;
   /* I accumulator associated with gain step 1 in the DAC controller */
   byte                                             pcs_dacc_iaccum1;
   /* I accumulator associated with gain step 1 in the DAC controller */
   byte                                             fm_dacc_iaccum1;
   /* I accumulator associated with gain step 1 in the DAC controller */
   byte                                             gps_dacc_iaccum1;
   /* I accumulator associated with gain step 2 in the DAC controller */
   byte                                             cdma_dacc_iaccum2;
   /* I accumulator associated with gain step 2 in the DAC controller */
   byte                                             pcs_dacc_iaccum2;
   /* I accumulator associated with gain step 2 in the DAC controller */
   byte                                             fm_dacc_iaccum2;
   /* I accumulator associated with gain step 2 in the DAC controller */
   byte                                             gps_dacc_iaccum2;
   /* I accumulator associated with gain step 3 in the DAC controller */
   byte                                             cdma_dacc_iaccum3;
   /* I accumulator associated with gain step 3 in the DAC controller */
   byte                                             pcs_dacc_iaccum3;
   /* I accumulator associated with gain step 3 in the DAC controller */
   byte                                             fm_dacc_iaccum3;
   /* I accumulator associated with gain step 3 in the DAC controller */
   byte                                             gps_dacc_iaccum3;
   /* I accumulator associated with gain step 4 in the DAC controller */
   byte                                             cdma_dacc_iaccum4;
   /* I accumulator associated with gain step 4 in the DAC controller */
   byte                                             pcs_dacc_iaccum4;
   /* I accumulator associated with gain step 4 in the DAC controller */
   byte                                             fm_dacc_iaccum4;
   /* I accumulator associated with gain step 4 in the DAC controller */
   byte                                             gps_dacc_iaccum4;
   /* Q accumulator associated with gain step 0 in the DAC controller */
   byte                                             cdma_dacc_qaccum0;
   /* Q accumulator associated with gain step 0 in the DAC controller */
   byte                                             pcs_dacc_qaccum0;
   /* Q accumulator associated with gain step 0 in the DAC controller */
   byte                                             fm_dacc_qaccum0;
   /* Q accumulator associated with gain step 0 in the DAC controller */
   byte                                             gps_dacc_qaccum0;
   /* Q accumulator associated with gain step 1 in the DAC controller */
   byte                                             cdma_dacc_qaccum1;
   /* Q accumulator associated with gain step 1 in the DAC controller */
   byte                                             pcs_dacc_qaccum1;
   /* Q accumulator associated with gain step 1 in the DAC controller */
   byte                                             fm_dacc_qaccum1;
   /* Q accumulator associated with gain step 1 in the DAC controller */
   byte                                             gps_dacc_qaccum1;
   /* Q accumulator associated with gain step 2 in the DAC controller */
   byte                                             cdma_dacc_qaccum2;
   /* Q accumulator associated with gain step 2 in the DAC controller */
   byte                                             pcs_dacc_qaccum2;
   /* Q accumulator associated with gain step 2 in the DAC controller */
   byte                                             fm_dacc_qaccum2;
   /* Q accumulator associated with gain step 2 in the DAC controller */
   byte                                             gps_dacc_qaccum2;
   /* Q accumulator associated with gain step 3 in the DAC controller */
   byte                                             cdma_dacc_qaccum3;
   /* Q accumulator associated with gain step 3 in the DAC controller */
   byte                                             pcs_dacc_qaccum3;
   /* Q accumulator associated with gain step 3 in the DAC controller */
   byte                                             fm_dacc_qaccum3;
   /* Q accumulator associated with gain step 3 in the DAC controller */
   byte                                             gps_dacc_qaccum3;
   /* Q accumulator associated with gain step 4 in the DAC controller */
   byte                                             cdma_dacc_qaccum4;
   /* Q accumulator associated with gain step 4 in the DAC controller */
   byte                                             pcs_dacc_qaccum4;
   /* Q accumulator associated with gain step 4 in the DAC controller */
   byte                                             fm_dacc_qaccum4;
   /* Q accumulator associated with gain step 4 in the DAC controller */
   byte                                             gps_dacc_qaccum4;
   /* Gain value used to scale the estimator accumulator by before updating */
   byte                                             cdma_dacc_gain_mult;
   /* Gain value used to scale the estimator accumulator by before updating */
   byte                                             pcs_dacc_gain_mult;
   /* Gain value used to scale the estimator accumulator by before updating */
   byte                                             fm_dacc_gain_mult;
   /* Gain value used to scale the estimator accumulator by before updating */
   byte                                             gps_dacc_gain_mult;
   /* IM2 cal. items generated during RF Cal to be loaded into RFR6000 */
   byte                                             cdma_im2_i_value;
   /* IM2 cal. items generated during RF Cal to be loaded intoRFR6000 */
   byte                                             pcs_im2_i_value;
   /* IM2 cal. items generated during RF Cal to be loaded intoRFR6000 */
   byte                                             cdma_im2_q_value;
   /* IM2 cal. items generated during RF Cal to be loaded intoRFR6000 */
   byte                                             pcs_im2_q_value;
   /* Deviations adj. in the 32,768Hz crystal oscillator freq. */
   byte                                             rtc_time_adjust;
   /* 13-bit two's complement integer for FM VGA gain offset */
   int2                                             fm_vga_gain_offset;
   /* 13-bit two's complement integer for CDMA VGA gain offset */
   int2                                             cdma_vga_gain_offset;
   /* 13-bit two's complement integer for PCS VGA gain offset */
   int2                                             pcs_vga_gain_offset;
   /* FM VGA gain offset variations over the frequencies */
   int1                                             fm_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* CDMA VGA gain offset variations over the frequencies */
   int1                                             cdma_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PCS VGA gain offset variations over the frequencies */
   int1                                             pcs_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* FM VGA gain offset variations over the temperatures */
   int2                                             fm_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* CDMA VGA gain offset variations over the temperatures */
   int2                                             cdma_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* PCS VGA gain offset variations over the temperatures */
   int2                                             pcs_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* In-phase coefficient for mismatch compensation */
   int32                                            fm_mis_comp_a_offset;
   /* In-phase coefficient for mismatch compensation */
   int32                                            digital_mis_comp_a_offset;
   /* In-phase coefficient for mismatch compensation */
   int32                                            gps_mis_comp_a_offset;
   /* In-phase coefficient for mismatch compensation */
   int32                                            fm_mis_comp_b_offset;
   /* In-phase coefficient for mismatch compensation */
   int32                                            digital_mis_comp_b_offset;
   /* In-phase coefficient for mismatch compensation */
   int32                                            gps_mis_comp_b_offset;
   /* Send RRQ only if there was traffic since previous RRQ */
   boolean                                          ds_mip_rrq_if_tfrk;
   /* Collocated HDR disallowed time */
   uint16                                           colloc_disallowed_time;
   /* Hold HDR time */
   uint16                                           hold_hdr_time;
   /* Number of times NV value updated via IIR filter */
   byte                                             lo_bias_update_cnt;
   /* Stores HDR Access Network Authentication Status */
   boolean                                          hdrscp_an_auth_status;
   /* Used to allow a user to Save an IMSI as an Index in NV */
   byte                                             imsi_index;
   /* Enable or disable a user profile. */
   byte                                             ds_mip_enable_prof[NV_DS_MIP_MAX_NUM_PROF];
   /* Contains 8-bit IM anti-jamming threshold data */
   int1                                             pcs_im_level3;
   /* Contains 8-bit IM anti-jamming threshold data */
   int1                                             pcs_im_level4;
   /* provides the minimum power output from the AGC accumulator */
   int1                                             pcs_agc_value_3_min;
   /* provides the minimum power output from the AGC accumulator */
   int1                                             pcs_agc_value_4_min;
   /* SMP - Time at which keep alive timer was started */
   qword                                            hdrsmpka_start_time;
   /* SMP - Time at which keep alive message was last sent. */
   qword                                            hdrsmpka_sent_time;
   /* Supplement item to the item NV_SMS_BC_SERVICE_TABLE_I */
   nv_sms_bc_service_table_options_type             sms_bc_service_table_options;
   /* Acquisition database */
   nv_acq_db_type                                   acq_db;
   /* First Acquisition List */
   nv_acq_list1_type                                acq_list_1;
   /* E-GSM ARFCNs used for GSM radio Rx/Tx frequency compensation */
   uint16                                           gsm_cal_arfcn[NV_GSM_CAL_ARFCN_SIZ];
   /* E-GSM ARFCNs used for DCS radio Rx/Tx frequency compensation */
   uint16                                           dcs_cal_arfcn[NV_DCS_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 1 */
   uint16                                           gsm_rx_gain_range_1_freq_comp[NV_GSM_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 2 */
   uint16                                           gsm_rx_gain_range_2_freq_comp[NV_GSM_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 3 */
   uint16                                           gsm_rx_gain_range_3_freq_comp[NV_GSM_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 4 */
   uint16                                           gsm_rx_gain_range_4_freq_comp[NV_GSM_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 5 */
   uint16                                           gsm_rx_gain_range_5_freq_comp[NV_GSM_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 1 */
   uint16                                           dcs_rx_gain_range_1_freq_comp[NV_DCS_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 2 */
   uint16                                           dcs_rx_gain_range_2_freq_comp[NV_DCS_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 3 */
   uint16                                           dcs_rx_gain_range_3_freq_comp[NV_DCS_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 4 */
   uint16                                           dcs_rx_gain_range_4_freq_comp[NV_DCS_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 4 */
   uint16                                           dcs_rx_gain_range_5_freq_comp[NV_DCS_CAL_ARFCN_SIZ];
   /* Trial PDM value that results in 13MHz TCXO */
   uint16                                           gsm_trk_lo_adj_pdm_init_val;
   /* Gain Slope for TCXO device in ppm/pdm units */
   uint16                                           gsm_trk_lo_adj_pdm_gain_slope;
   /* Calibrated standard deviation of this phone's doppler estimator in Hz */
   byte                                             gps_dopp_sdev;
   /* Second Acquisition List */
   nv_acq_list1_type                                acq_list_2;
   /* Third Acquisition List */
   nv_acq_list2_type                                acq_list_3;
   /* Fourth Acquisition List */
   nv_acq_list2_type                                acq_list_4;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_00;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_01;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_02;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_03;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_04;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_05;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_06;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_07;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_08;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_09;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_10;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_11;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_12;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_13;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_up_index_14;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_00;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_01;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_02;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_03;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_04;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_05;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_06;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_07;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_08;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_09;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_10;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_11;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_12;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_13;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_tx_burst_ramp_down_index_14;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_00;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_01;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_02;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_03;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_04;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_05;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_06;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_07;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_08;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_09;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_10;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_11;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_12;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_13;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_14;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_up_index_15;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_00;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_01;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_02;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_03;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_04;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_05;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_06;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_07;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_08;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_09;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_10;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_11;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_12;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_13;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_14;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      dcs_tx_burst_ramp_down_index_15;
   /* PA DAC counts per dB */
   byte                                             gsm_pa_gain_slope[NV_NUM_GSM_PA_PROFILES];
   /* PA DAC counts per dB */
   byte                                             dcs_pa_gain_slope[NV_NUM_DCS_PA_PROFILES];
   /* 1/16 dB */
   int8                                             gsm_tx_freq_comp[8];
   /* 1/16 dB */
   int8                                             dcs_tx_freq_comp[16];
   /* 1/16 dB per volt */
   byte                                             gsm_vbatt_hi_pa_comp;
   /* 1/16 dB per volt */
   byte                                             gsm_vbatt_lo_pa_comp;
   /* 1/16 dB per volt */
   byte                                             dcs_vbatt_hi_pa_comp;
   /* 1/16 dB per volt */
   byte                                             dcs_vbatt_lo_pa_comp;
   /* PA DAC value */
   word                                             vbatt_3200_mv_adc;
   /* PA DAC value */
   word                                             vbatt_3700_mv_adc;
   /* PA DAC value */
   word                                             vbatt_4200_mv_adc;
   /* PA DAC value */
   word                                             gsm_precharge;
   /* PA DAC value */
   word                                             dcs_precharge;
   /* Quarter-symbol */
   word                                             gsm_precharge_dur;
   /* Quarter-symbol */
   word                                             dcs_precharge_dur;
   /* Timer value to wait until checking the state of LOCK_DET */
   byte                                             digital_pll_lock_timer;
   /* HDR rx diversity control parameter */
   uint8                                            hdr_rx_diversity_ctrl;
   /* Quarter-symbol */
   int8                                             gsm_pa_start_time_offset;
   /* Quarter-symbol */
   int8                                             gsm_pa_stop_time_offset;
   /* Quarter-symbol */
   int8                                             dcs_pa_start_time_offset;
   /* Quarter-symbol */
   int8                                             dcs_pa_stop_time_offset;
   /* Position Location Privacy */
   byte                                             gps1_privacy;
   /* Position Location Network Access Control */
   byte                                             gps1_net_access;
   /* Enables/Disables Cell Based Position Determination */
   boolean                                          gps1_cellbased_sms;
   /* Enables/Disables Cell Based Position Determination */
   word                                             gps1_teleservice_id;
   /* HDR Search Parameters */
   nv_hdrrup_srch_params_type                       hdrrup_srch_params;
   /* Bypass timer value when LNA is in BYPASS_HOLD_STATE */
   word                                             dfm_lna_bypass_timer;
   /* Bypass timer value when LNA is in NONBYPASS_HOLD_STATE */
   word                                             dfm_lna_nonbypass_timer;
   /* Storage for SMS routing configuration */
   nv_sms_routing_type                              sms_cfg_routing;
   /* Data Burst Packet Size supported by this netword */
   byte                                             gps1_net_dbm_size;
   /* Stop monitoring 1x page while in HDR data call */
   boolean                                          hdr_do_not_disturb;
   /* Transmitter Gain Attenuation Limit. */
   int2                                             cdma_tx_gain_atten_limit;
   /* Transmitter Gain Attenuation Limit. */
   int2                                             pcs_tx_gain_atten_limit;
   /* Transmitter Gain Attenuation Limit. */
   int2                                             amps_tx_gain_atten_limit;
   /* Transmitter Gain Attenuation Limit. */
   int2                                             gps_tx_gain_atten_limit;
   /* ZIFRIC register value that controls IM2 transconductance */
   byte                                             cdma_im2_transconductor_value;
   /* ZIFRIC register value that controls IM2 transconductance */
   byte                                             pcs_im2_transconductor_value;
   /* Bypass timer value */
   word                                             lna_non_bypass_timer_0;
   /* Bypass timer value */
   word                                             lna_non_bypass_timer_1;
   /* Bypass timer value */
   word                                             lna_non_bypass_timer_2;
   /* Bypass timer value */
   word                                             lna_non_bypass_timer_3;
   /* Bypass timer value */
   word                                             lna_bypass_timer_0;
   /* Bypass timer value */
   word                                             lna_bypass_timer_1;
   /* Bypass timer value */
   word                                             lna_bypass_timer_2;
   /* Bypass timer value */
   word                                             lna_bypass_timer_3;
   /* CDMA SMS Parameters/templates */
   nv_sms_cd_parms_type                             sms_cd_parms;
   /* Specifies the order of acquiring a GSM/WCDMA system */
   nv_acq_order_pref_type                           acq_order_pref;
   /* Indicates how a network should be selected, auto or manually */
   nv_net_sel_mode_pref_type                        net_sel_mode_pref;
   /* Indicates the type of service domain that should be acquired */
   nv_srv_domain_pref_type                          service_domain_pref;
   /* Authentication type */
   nv_ppp_auth_enum_type                            ppp_authentication;
   /* APN name to be used in the PDP-context activation procedure */
   byte                                             apn_name[NV_MAX_APN_STRING_LEN];
   /* List of equivalent PLMNs received from the RPLMN */
   nv_equivalent_plmn_list_type                     equivalent_plmn_list;
   /* Public Key Organization Identifier */
   nv_ds_mip_dmu_pkoid_type                         ds_mip_dmu_pkoid;
   /* RTRE configuration */
   nv_rtre_configuration_type                       rtre_config;
   /* RX AGC offset for each VGA gain */
   int16                                            wcdma_vga_gain_offset;
   /* RX AGC offset for each VGA gain based on frequency */
   int8                                             wcdma_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* RX AGC offset for each VGA gain based on temperature */
   int8                                             wcdma_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* LNA threshold from mid to low state */
   int16                                            wcdma_lna_range_rise_2;
   /* Mixer threshold from high to low state */
   int16                                            wcdma_lna_range_rise_3;
   /* LNA threshold from low to mid state */
   int16                                            wcdma_lna_range_fall_2;
   /* Mixer threshold from low to high state */
   int16                                            wcdma_lna_range_fall_3;
   /* IM threshold for LNA mid to low state */
   int16                                            wcdma_im_level_2;
   /* Mixer threshold for high to low state */
   int16                                            wcdma_im_level_3;
   /* LNA gain step from mid to low state */
   int16                                            wcdma_lna_range_offset_2;
   /* Mixer gain step from high to low state */
   int16                                            wcdma_lna_range_offset_3;
   /* LNA gain step from mid to low state based on frequency */
   int8                                             wcdma_lna_offset_vs_freq_2[NV_FREQ_TABLE_SIZ];
   /* Mixer gain step from high to low state based on frequency */
   int8                                             wcdma_lna_offset_vs_freq_3[NV_FREQ_TABLE_SIZ];
   /* I cancellation value for lower in-band jammer */
   uint8                                            wcdma_im2_i_value;
   /* Q cancellation value for lower in-band jammer */
   uint8                                            wcdma_im2_q_value;
   /* Transconductor value for lower in-band jammer */
   uint8                                            wcdma_im2_transconductor_value;
   /* Linearizer underflow for LNA low gain state and Mixer High gainstate */
   int16                                            wcdma_rx_agc_min_2;
   /* Linearizer underflow for LNA Low gain state and Mixer Low gain state */
   int16                                            wcdma_rx_agc_min_3;
   /* VBATT min and max voltage value */
   uint8                                            wcdma_vbatt[2];
   /* THERM min and max voltage value */
   uint8                                            wcdma_therm[2];
   /* WCDMA UE Maximum TX power in dbm */
   int8                                             wcdma_max_tx_power;
   /* The FM MAC level that the PA will switch from low to high gain */
   byte                                             fm_pa_mac_high;
   /* Selects dynamic range in Rx Front. */
   int2                                             cdma_dynamic_range;
   /* Min Rx RSSI in 1/10 dB increments. */
   int2                                             cdma_min_rx_rssi;
   /* Enables Integrity Protection feature in the UE */
   boolean                                          rrc_integrity_enabled;
   /* Enables Ciphering feature in the UE */
   boolean                                          rrc_ciphering_enabled;
   /* Fake Security turned on/off in the UE */
   boolean                                          rrc_fake_security_enabled;
   /* This NV item records the # of CDMA powerup registration performed */
   qword                                            cdma_powerup_reg_performed;
   /* Defines the Tx Warmup duration. */
   word                                             tx_warmup;
   /* Remember the amount of data call bytes transmitted */
   uint32                                           last_tx_data_count;
   /* Remember the amount of data call bytes received */
   uint32                                           last_rx_data_count;
   /* Remember the accumulated data call bytes transmitted */
   uint32                                           total_tx_data_count;
   /* Remember the accumulated data call bytes received */
   uint32                                           total_rx_data_count;
   /* Mobile Node Authenticator */
   nv_ds_mip_dmu_mn_auth_type                       ds_mip_dmu_mn_auth;
   /* Configurable USB product id offset */
   byte                                             usb_product_id_offset;
   /* Call duration */
   uint16                                           avcd_call_duration;
   /* Time between calls */
   uint16                                           avcd_time_between_calls;
   /* Number of calls */
   uint16                                           avcd_number_of_calls;
   /* Service option */
   uint16                                           avcd_so;
   /* Minimum value before searcher declares OUT_OF_SERVICE_AREA */
   int16                                            wcdma_out_of_service_thresh;
   /* Indicates which class to use for the first UIM instruction. */
   nv_uim_first_inst_class_type                     uim_first_inst_class;
   /* HDR Set Management Parameters Override Allowed */
   uint8                                            hdrrup_override_allowed;
   /* M511 mode setting */
   uint8                                            jcdma_m511_mode;
   /* M512 mode setting */
   uint8                                            jcdma_m512_mode;
   /* M513 mode setting */
   uint8                                            jcdma_m513_mode;
   /* Adjustments to PA rise and fall values during P1 data calls. */
   byte                                             cdma_p1_rise_fall_off[8];
   /* Adjustments to PA rise and fall values during P1 data calls. */
   byte                                             pcs_p1_rise_fall_off[8];
   /* GSM GPRS location information */
   byte                                             gsm_locigprs[14];
   /* GSM GPRS Ciphering Key and CKSN */
   byte                                             gsm_kcgprs[9];
   /* Used to change powerdown options in fatal error handling */
   nv_err_fatal_options_type                        err_fatal_options;
   /* Simple IP PPP password */
   nv_ppp_password_type                             ppp_password;
   /* PDM value based on temperature */
   uint16                                           trk_lo_adj_vs_temp[64];
   /* Finger or searcher rotator value based on temperature */
   int16                                            rot_freq_vs_temp[64];
   /* GSM/UMTS SMS bearer preference */
   byte                                             sms_gw_bearer_pref;
   /* User ID for PPP authentication */
   nv_ppp_user_id_type                              ppp_user_id;
   /* The Multi Slot Class for GPRS mobiles */
   byte                                             multislot_class;
   /* NON DRX timer value for GPRS mobiles */
   byte                                             non_drx_timer;
   /* SPLIT_PAGING_CYCLE value for GPRS mobiles */
   byte                                             split_paging_cycle;
   /* Indicates what the preferred UIM protocol is */
   nv_uim_pref_protocol_type                        uim_pref_protocol;
   /* WCDMA Circuit Switched Data Synchronous Test App */
   boolean                                          wcdmacs_sync_test_app_enabled;
   /* GSM gain range switch points in units of dB_FS */
   nv_gainrange_switchpoint_type                    gsm_gainrange_switchpoints;
   /* DCS gain range switch points in units of dB_FS */
   nv_gainrange_switchpoint_type                    dcs_gainrange_switchpoints;
   /* NAI for AN authentication */
   nv_hdr_an_ppp_nai_type                           hdr_an_ppp_user_id;
   /* Password for AN authentication */
   nv_hdr_an_ppp_password_type                      hdr_an_ppp_password;
   /* Primary JTACS CDMA channel */
   nv_cdmach_type                                   jtacs_pcdmach;
   /* Secondary JTAGS CDMA channel */
   nv_cdmach_type                                   jtacs_scdmach;
   /* GSM/UMTS IMSI (International Mobile Subscriber Identity) */
   byte                                             gsmumts_imsi[8];
   /* IP address and port of RTSP protocol proxy server */
   nv_rtsp_proxy_server_addr_type                   rtsp_proxy_server_addr;
   /* User's pref regarding which template to use for MO GSM/WCDMA msg */
   nv_sms_default_template_type                     sms_gw_default_template;
   /* User's pref regarding which template to use for MO CDMA msg */
   nv_sms_default_template_type                     sms_cd_default_template;
   /* Comment to track factory non-compliant behavior */
   uint8                                            non_compliance_comment[64];
   /* Defines the PZID hysterisis activation timer in seconds */
   uint16                                           hysterisis_activation_timer;
   /* Defines the PZID hysterisis timer in seconds */
   uint16                                           hysterisis_timer;
   /* Packet Call Dial String Lookup Table */
   nv_pkt_dial_string_type                          pkt_dial_strings[NV_PKT_DIAL_STRING_LIST_SIZE];
   /* Table of VCO Coarse Tune Values */
   byte                                             vco_coarse_tune_table[NV_VCO_COARSE_TUNE_TABLE_SIZ];
   /* For processing incoming CS Data calls as internal CSD calls */
   boolean                                          data_incoming_csd_call_is_internal;
   /* Dynamic Feature */
   byte                                             df[20];
   /* Temperature comp of GSM PA in AMSS6200 */
   int16                                            gsm_pa_temp_comp_index_14[16];
   /* Temperature comp of DCS PA in AMSS6200 */
   int16                                            dcs_pa_temp_comp_index_15[16];
   /* RF NV test item 1 */
   uint32                                           rf_test_item_1;
   /* RF NV test item 2 */
   uint32                                           rf_test_item_2;
   /* Negative SCI preference by the user */
   int8                                             neg_slot_cycle_index;
   /* OLPC floor value used for BTFD call */
   int8                                             btfd_olpc_floor_db;
   /* OLPC floor value used for non-BTFD call */
   int8                                             non_btfd_olpc_floor_db;
   /* PRL protocol revision number */
   byte                                             sspr_p_rev;
   /* IP address and port of RTSP protocol proxy server */
   nv_rtsp_proxy_server_addr_type                   rtsp_proxy_server_addr_alternate;
   /* Indicates the preferred slot for CDMA application. */
   nv_uim_slot_type                                 uim_cdma_pref_slot;
   /* Indicates the preferred slot for GSM application. */
   nv_uim_slot_type                                 uim_gsm_pref_slot;
   /* Define a MRU3 data type */
   nv_mru3_table_type                               mru3_table;
   /* Expand band pref from 16 bits to 32 bits */
   nv_band_pref_type                                band_pref_16_31;
   /* Enable Anite GCF 51.010 Test Case Workarounds */
   boolean                                          gprs_anite_gcf;
   /* Offset to be subtracted from input to IF VGA linearizer table. */
   int2                                             c1_cdma_lna_offset;
   /* Stores gain variations of the LNA. */
   int1                                             c1_cdma_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Offset to be subtracted from input to IF VGA linearizer table. */
   int2                                             c1_pcs_lna_offset;
   /* Gain variations of the LNA when in the 4th gain state. */
   int1                                             c1_pcs_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Offset to be subtracted from input to IF VGA linearizer table. */
   int2                                             c1_cdma_lna_2_offset;
   /* Gain variations of the LNA when in the 4th gain state. */
   int1                                             c1_cdma_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Offset to be subtracted from input to IF VGA linearizer table. */
   int2                                             c1_pcs_lna_2_offset;
   /* Gain variations of the LNA when in the 4th gain state. */
   int1                                             c1_pcs_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Offset to be subtracted from input to IF VGA linearizer table. */
   int2                                             c1_cdma_lna_3_offset;
   /* Gain variations of the LNA when in the 4th gain state. */
   int1                                             c1_cdma_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Offset to be subtracted from input to IF VGA linearizer table. */
   int2                                             c1_pcs_lna_3_offset;
   /* Gain variations of the LNA when in the 4th gain state. */
   int1                                             c1_pcs_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Offset to be subtracted from input to IF VGA linearizer table. */
   int2                                             c1_cdma_lna_4_offset;
   /* Gain variations of the LNA when in the 4th gain state. */
   int1                                             c1_cdma_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Offset to be subtracted from input to IF VGA linearizer table. */
   int2                                             c1_pcs_lna_4_offset;
   /* Gain variations of the LNA when in the 4th gain state. */
   int1                                             c1_pcs_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* CDMA PA Rise/Fall offsets during data calls. */
   byte                                             c1_cdma_p1_rise_fall_offset[8];
   /* PCS PA Rise/Fall offsets during data calls */
   byte                                             c1_pcs_p1_rise_fall_offset[8];
   /* AGC min and max values to prevent linearizer under and over flow. */
   nv_minmax_type                                   c1_rx_agc_value_1_minmax;
   /* AGC min and max values to prevent linearizer under and over flow. */
   nv_minmax_type                                   c1_rx_agc_value_2_minmax;
   /* AGC min and max values to prevent linearizer under and over flow. */
   nv_minmax_type                                   c1_rx_agc_value_3_minmax;
   /* AGC min and max values to prevent linearizer under and over flow. */
   nv_minmax_type                                   c1_rx_agc_value_4_minmax;
   /* Holds the base VREF value. */
   byte                                             c0_rx_agc_vref_val;
   /* Holds the base VREF value. */
   byte                                             c1_rx_agc_vref_val;
   /* Defines Group Delay Adjust. */
   byte                                             c0_grp_delay_adj;
   /* Defines Group Delay Adjust. */
   byte                                             c1_grp_delay_adj;
   /* 13-bit two's complement integer for Digital VGA gain offset. */
   int2                                             c1_cdma_vga_gain_offset;
   /* Digital VGA gain offset variations over the frequencies. */
   int1                                             c1_cdma_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Digital VGA gain offset variations over the temperatures. */
   int2                                             c1_cdma_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* Digital VGA gain offset. */
   int2                                             c1_pcs_vga_gain_offset;
   /* Digital VGA gain offset variations over the frequencies. */
   int1                                             c1_pcs_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Digital VGA gain offset variations over the temperatures. */
   int2                                             c1_pcs_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* In-phase coefficient for mismatch compensation. */
   int4                                             c1_digital_mis_comp_a_offset;
   /* In-phase coefficient for mismatch compensation. */
   int4                                             c1_gps_mis_comp_a_offset;
   /* In-phase coefficient for mismatch compensation. */
   int4                                             c1_digital_mis_comp_b_offset;
   /* In-phase coefficient for mismatch compensation. */
   int4                                             c1_gps_mis_comp_b_offset;
   /* Internal use only */
   byte                                             c1_cdma_dacc_iaccum0;
   /* Internal use only */
   byte                                             c1_pcs_dacc_iaccum0;
   /* Internal use only */
   byte                                             c1_gps_dacc_iaccum0;
   /* Internal use only */
   byte                                             c1_cdma_dacc_iaccum1;
   /* Internal use only */
   byte                                             c1_pcs_dacc_iaccum1;
   /* Internal use only */
   byte                                             c1_gps_dacc_iaccum1;
   /* Internal use only */
   byte                                             c1_cdma_dacc_iaccum2;
   /* Internal use only */
   byte                                             c1_pcs_dacc_iaccum2;
   /* Internal use only */
   byte                                             c1_gps_dacc_iaccum2;
   /* Internal use only */
   byte                                             c1_cdma_dacc_iaccum3;
   /* Internal use only */
   byte                                             c1_pcs_dacc_iaccum3;
   /* Internal use only */
   byte                                             c1_gps_dacc_iaccum3;
   /* Internal use only */
   byte                                             c1_cdma_dacc_iaccum4;
   /* Internal use only */
   byte                                             c1_pcs_dacc_iaccum4;
   /* Internal use only */
   byte                                             c1_gps_dacc_iaccum4;
   /* Internal use only */
   byte                                             c1_cdma_dacc_qaccum0;
   /* Internal use only */
   byte                                             c1_pcs_dacc_qaccum0;
   /* Internal use only */
   byte                                             c1_gps_dacc_qaccum0;
   /* Internal use only */
   byte                                             c1_cdma_dacc_qaccum1;
   /* Internal use only */
   byte                                             c1_pcs_dacc_qaccum1;
   /* Internal use only */
   byte                                             c1_gps_dacc_qaccum1;
   /* Internal use only */
   byte                                             c1_cdma_dacc_qaccum2;
   /* Internal use only */
   byte                                             c1_pcs_dacc_qaccum2;
   /* Internal use only */
   byte                                             c1_gps_dacc_qaccum2;
   /* Internal use only */
   byte                                             c1_cdma_dacc_qaccum3;
   /* Internal use only */
   byte                                             c1_pcs_dacc_qaccum3;
   /* Internal use only */
   byte                                             c1_gps_dacc_qaccum3;
   /* Internal use only */
   byte                                             c1_cdma_dacc_qaccum4;
   /* Internal use only */
   byte                                             c1_pcs_dacc_qaccum4;
   /* Internal use only */
   byte                                             c1_gps_dacc_qaccum4;
   /* GSM/UMTS Cell Broadcast SMS Service Table */
   nv_sms_gw_cb_service_table_type                  sms_gw_cb_service_table;
   /* GSM/UMTS Cell Broadcast SMS Service Table Size */
   word                                             sms_gw_cb_service_table_size;
   /* GSM/UMTS Cell Broadcast SMS Carrier's Configuration */
   byte                                             sms_gw_cb_config;
   /* GSM/UMTS Cell Broadcase SMS User's Preference */
   byte                                             sms_gw_cb_user_pref;
   /* Controls CDMA Receive Diversity Settings */
   word                                             cdma_rx_diversity_ctrl;
   /* Enable/disable tolerance to long PDP context setup time for TE calls */
   boolean                                          long_pdpact_tolerance_for_te;
   /* IM2 calibration item */
   byte                                             c1_cdma_im2_q_value;
   /* IM2 calibration item */
   byte                                             c1_pcs_im2_q_value;
   /* IM2 calibration item */
   byte                                             c1_cdma_im2_i_value;
   /* IM2 calibration item */
   byte                                             c1_pcs_im2_i_value;
   /* value that controls IM2 transconductance for CDMA mode */
   byte                                             c1_cdma_im2_transconductor_value;
   /* value that controls IM2 transconductance for PCS mode */
   byte                                             c1_pcs_im2_transconductor_value;
   /* Stores the coarse tuning values of the chain 1 RFR internal VCO */
   byte                                             c1_vco_coarse_tune_table[NV_VCO_COARSE_TUNE_TABLE_SIZ];
   /* Flag to enable dumping mdsp memory to flash. */
   boolean                                          mdsp_mem_dump_enabled;
   /* RF GSM 850 PA temp comp table */
   int16                                            gsm_850_pa_temp_comp_index_14;
   /* RF GSM 1900 PA temp comp table */
   int16                                            gsm_1900_pa_temp_comp_index_15;
   /* Set this item for Forcing UE to behave as GSM R99 version */
   byte                                             force_ue_sgsnr_r99;
   /* Set this item for Forcing UE to behave as GSM R99 version */
   byte                                             force_ue_mscr_r99;
   /* GPS receive chain configuration */
   byte                                             gps_rf_config;
   /* 8-bit rising threshold data for 2nd Chain LNA 1 */
   byte                                             c1_cdma_lna_1_rise;
   /* 8-bit rising threshold data for 2nd Chain LNA 2 */
   byte                                             c1_cdma_lna_2_rise;
   /* 8-bit rising threshold data for 2nd Chain LNA 3 */
   byte                                             c1_cdma_lna_3_rise;
   /* 8-bit rising threshold data for 2nd Chain LNA 4 */
   byte                                             c1_cdma_lna_4_rise;
   /* 8-bit rising threshold data for 2nd Chain LNA 1 */
   byte                                             c1_pcs_lna_1_rise;
   /* 8-bit rising threshold data for 2nd Chain LNA 2 */
   byte                                             c1_pcs_lna_2_rise;
   /* 8-bit rising threshold data for 2nd Chain LNA 3 */
   byte                                             c1_pcs_lna_3_rise;
   /* 8-bit rising threshold data for 2nd Chain LNA 4 */
   byte                                             c1_pcs_lna_4_rise;
   /* 8-bit falling threshold data for 2nd Chain LNA 1 */
   byte                                             c1_cdma_lna_1_fall;
   /* 8-bit falling threshold data for 2nd Chain LNA 2 */
   byte                                             c1_cdma_lna_2_fall;
   /* 8-bit falling threshold data for 2nd Chain LNA 3 */
   byte                                             c1_cdma_lna_3_fall;
   /* 8-bit falling threshold data for 2nd Chain LNA 4 */
   byte                                             c1_cdma_lna_4_fall;
   /* 8-bit falling threshold data for 2nd Chain LNA 1 */
   byte                                             c1_pcs_lna_1_fall;
   /* 8-bit falling threshold data for 2nd Chain LNA 2 */
   byte                                             c1_pcs_lna_2_fall;
   /* 8-bit falling threshold data for 2nd Chain LNA 3 */
   byte                                             c1_pcs_lna_3_fall;
   /* 8-bit falling threshold data for 2nd Chain LNA 4 */
   byte                                             c1_pcs_lna_4_fall;
   /* 8-bit IM anti-jamming threshold data, Level-1. */
   byte                                             c1_cdma_im_level1;
   /* 8-bit IM anti-jamming threshold data, Level-2. */
   byte                                             c1_cdma_im_level2;
   /* 8-bit IM anti-jamming threshold data, Level-3. */
   byte                                             c1_cdma_im_level3;
   /* 8-bit IM anti-jamming threshold data, Level-4. */
   byte                                             c1_cdma_im_level4;
   /* 8-bit IM anti-jamming threshold data, Level-1. */
   byte                                             c1_pcs_im_level1;
   /* 8-bit IM anti-jamming threshold data, Level-2. */
   byte                                             c1_pcs_im_level2;
   /* 8-bit IM anti-jamming threshold data, Level-3. */
   byte                                             c1_pcs_im_level3;
   /* 8-bit IM anti-jamming threshold data, Level-4. */
   byte                                             c1_pcs_im_level4;
   /* E-GSM ARFCNs used for DCS radio Rx/Tx frequency compensation */
   int16                                            gsm_1900_cal_arfcn[NV_GSM_1900_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 1 */
   int16                                            gsm_1900_rx_gain_range_1_freq_comp[NV_GSM_1900_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 2 */
   int16                                            gsm_1900_rx_gain_range_2_freq_comp[NV_GSM_1900_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 3 */
   int16                                            gsm_1900_rx_gain_range_3_freq_comp[NV_GSM_1900_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 4 */
   int16                                            gsm_1900_rx_gain_range_4_freq_comp[NV_GSM_1900_CAL_ARFCN_SIZ];
   /* DCS frequency compensated Rx gain values for gain range 5 */
   int16                                            gsm_1900_rx_gain_range_5_freq_comp[NV_GSM_1900_CAL_ARFCN_SIZ];
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_00;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_01;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_02;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_03;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_04;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_05;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_06;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_07;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_08;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_09;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_10;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_11;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_12;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_13;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_14;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_up_index_15;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_00;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_01;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_02;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_03;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_04;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_05;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_06;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_07;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_08;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_09;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_10;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_11;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_12;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_13;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_14;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_1900_tx_burst_ramp_down_index_15;
   /* PA DAC counts per dB */
   byte                                             gsm_1900_pa_gain_slope[NV_NUM_DCS_PA_PROFILES];
   /* 1/16 dB */
   int8                                             gsm_1900_tx_freq_comp[16];
   /* 1/16 dB per volt */
   byte                                             gsm_1900_vbatt_hi_pa_comp;
   /* 1/16 dB per volt */
   byte                                             gsm_1900_vbatt_lo_pa_comp;
   /* Quarter-symbol */
   int8                                             gsm_1900_pa_start_time_offset;
   /* Quarter-symbol */
   int8                                             gsm_1900_pa_stop_time_offset;
   /* DCS gain range switch points in units of dB_FS */
   nv_gainrange_switchpoint_type                    gsm_1900_gainrange_switchpoints;
   /* E-GSM ARFCNs used for GSM radio Rx/Tx frequency compensation */
   int16                                            gsm_850_cal_arfcn[NV_GSM_850_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 1 */
   int16                                            gsm_850_rx_gain_range_1_freq_comp[NV_GSM_850_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 2 */
   int16                                            gsm_850_rx_gain_range_2_freq_comp[NV_GSM_850_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 3 */
   int16                                            gsm_850_rx_gain_range_3_freq_comp[NV_GSM_850_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 4 */
   int16                                            gsm_850_rx_gain_range_4_freq_comp[NV_GSM_850_CAL_ARFCN_SIZ];
   /* E-GSM frequency compensated Rx gain values for gain range 5 */
   int16                                            gsm_850_rx_gain_range_5_freq_comp[NV_GSM_850_CAL_ARFCN_SIZ];

   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_00;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_01;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_02;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_03;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_04;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_05;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_06;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_07;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_08;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_09;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_10;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_11;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_12;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_13;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_up_index_14;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_00;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_01;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_02;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_03;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_04;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_05;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_06;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_07;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_08;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_09;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_10;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_11;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_12;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_13;
   /* PA DAC value */
   nv_tx_burst_ramp_index_type                      gsm_850_tx_burst_ramp_down_index_14;
   /* PA DAC counts per dB */
   byte                                             gsm_850_pa_gain_slope[NV_NUM_GSM_PA_PROFILES];
   /* 1/16 dB */
   int8                                             gsm_850_tx_freq_comp[8];
   /* 1/16 dB per volt */
   byte                                             gsm_850_vbatt_hi_pa_comp;
   /* 1/16 dB per volt */
   byte                                             gsm_850_vbatt_lo_pa_comp;
   /* Quarter-symbol */
   int8                                             gsm_850_pa_start_time_offset;
   /* Quarter-symbol */
   int8                                             gsm_850_pa_stop_time_offset;
   /* GSM gain range switch points in units of dB_FS */
   nv_gainrange_switchpoint_type                    gsm_850_gainrange_switchpoints;
   /* RX AGC offset for each VGA gain */
   int16                                            wcdma_1900_vga_gain_offset;
   /* RX AGC offset for each VGA gain based on frequency */
   int8                                             wcdma_1900_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* RX AGC offset for each VGA gain based on temperature */
   int8                                             wcdma_1900_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* LNA threshold from mid to low state */
   int16                                            wcdma_1900_lna_range_rise_2;
   /* Mixer threshold from high to low state */
   int16                                            wcdma_1900_lna_range_rise_3;
   /* LNA threshold from low to mid state */
   int16                                            wcdma_1900_lna_range_fall_2;
   /* Mixer threshold from low to high state */
   int16                                            wcdma_1900_lna_range_fall_3;
   /* IM threshold for LNA mid to low state */
   int16                                            wcdma_1900_im_level_2;
   /* Mixer threshold for high to low state */
   int16                                            wcdma_1900_im_level_3;
   /* LNA gain step from mid to low state */
   int16                                            wcdma_1900_lna_range_offset_2;
   /* Mixer gain step from high to low state */
   int16                                            wcdma_1900_lna_range_offset_3;
   /* LNA gain step from mid to low state based on frequency */
   int8                                             wcdma_1900_lna_offset_vs_freq_2[NV_FREQ_TABLE_SIZ];
   /* Mixer gain step from high to low state based on frequency */
   int8                                             wcdma_1900_lna_offset_vs_freq_3[NV_FREQ_TABLE_SIZ];
   /* I cancellation value for lower in-band jammer */
   uint8                                            wcdma_1900_im2_i_value;
   /* Q cancellation value for lower in-band jammer */
   uint8                                            wcdma_1900_im2_q_value;
   /* Transconductor value for lower in-band jammer */
   uint8                                            wcdma_1900_im2_transconductor_value;
   /* Linearizer underflow for LNA low gain state and Mixer High gainstate */
   int16                                            wcdma_1900_rx_agc_min_2;
   /* Linearizer underflow for LNA Low gain state and Mixer Low gain state */
   int16                                            wcdma_1900_rx_agc_min_3;
   /* WCDMA UE Maximum TX power in dbm */
   int8                                             wcdma_1900_max_tx_power;
   /* Minimum value before searcher declares OUT_OF_SERVICE_AREA */
   int16                                            wcdma_1900_out_of_service_thresh;
   /* WCDMA Rx power level at which LNA should be bypassed */
   int16                                            wcdma_1900_lna_range_rise;
   /* WCDMA Rx power level at which LNA should be turned on */
   int16                                            wcdma_1900_lna_range_fall;
   /* LNA InterMod (high to low gain ) anti-jamming threshold power level */
   int16                                            wcdma_1900_im_level;
   /* Duration of non-bypass state in multiple of 66us (8-bits) */
   uint8                                            wcdma_1900_nonbypass_timer;
   /* Duration of bypass state in multiple of 6.6ms (11-bits) */
   uint16                                           wcdma_1900_bypass_timer;
   /* Value that is added to Rx power reading when LNA is bypassed */
   int16                                            wcdma_1900_lna_range_offset;
   /* WCDMA LNA range offset delta vs. frequency in unit of AGC value */
   int8                                             wcdma_1900_lna_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* WCDMA Receiver AGC min */
   int16                                            wcdma_1900_rx_agc_min;
   /* WCDMA Receiver AGC max */
   int16                                            wcdma_1900_rx_agc_max;
   /* WCDMA LNA Phase adjustment when LNA is bypassed */
   uint8                                            wcdma_1900_agc_phase_offset;
   /* WCDMA Tx AGC linearizer master offset value for lowest PA gain state */
   uint16                                           wcdma_1900_tx_lin_master_0[NV_WCDMA_TX_LIN_MASTER_SIZ];
   /* WCDMA Tx AGC linearizer master offset value for highest PA gain state */
   uint16                                           wcdma_1900_tx_lin_master_1[NV_WCDMA_TX_LIN_MASTER_SIZ];
   /* WCDMA Tx AGC delta vs. frequency for lowest PA gain state */
   int8                                             wcdma_1900_tx_comp_vs_freq_0[NV_FREQ_TABLE_SIZ];
   /* WCDMA Tx AGC delta vs. frequency for highest PA gain state */
   int8                                             wcdma_1900_tx_comp_vs_freq_1[NV_FREQ_TABLE_SIZ];
   /* WCDMA Tx AGC PDM delta vs. temp for lowest PA gain state */
   int8                                             wcdma_1900_tx_lin_vs_temp_0[NV_TEMP_TABLE_SIZ];
   /* WCDMA Tx AGC PDM delta vs. temp for highest PA gain state */
   int8                                             wcdma_1900_tx_lin_vs_temp_1[NV_TEMP_TABLE_SIZ];
   /* WCDMA Tx AGC PDM slope delta vs. temp for lowest PA gain state */
   int8                                             wcdma_1900_tx_slp_vs_temp_0[NV_TEMP_TABLE_SIZ];
   /* WCDMA Tx AGC PDM slope delta vs. temp for highest PA gain state */
   int8                                             wcdma_1900_tx_slp_vs_temp_1[NV_TEMP_TABLE_SIZ];
   /* TX power level to switch PA from lowest to highest gain state */
   uint16                                           wcdma_1900_r1_rise;
   /* TX power level to switch PA from highest to lowest gain state */
   uint16                                           wcdma_1900_r1_fall;
   /* WCDMA Tx power limit vs. temperature (absolute not delta) */
   uint8                                            wcdma_1900_tx_lim_vs_temp[NV_TEMP_TABLE_SIZ];
   /* WCDMA Tx power limit vs. frequency (absolute not delta) */
   int16                                            wcdma_1900_tx_lim_vs_freq[NV_FREQ_TABLE_SIZ];
   /* WCDMA TX power limit gain step adjustment factor */
   uint8                                            wcdma_1900_adj_factor;
   /* WCDMA expected HDET reading vs Tx AGC */
   uint8                                            wcdma_1900_exp_hdet_vs_agc[NV_WCDMA_EXP_HDET_VS_AGC_SIZ];
   /* WCDMA ADC HDET reading offset */
   uint8                                            wcdma_1900_hdet_off;
   /* WCDMA ADC HDET reading span */
   uint8                                            wcdma_1900_hdet_spn;
   /* CHIPX8 delay for SYNC80M via 800mhz CDMA path in RF card, biased +25. */
   uint32                                           wcdma_1900_enc_btf;
   /* RPLMN Last Used Access Technology */
   nv_rplmnact_type                                 rplmnact;
   /* Indicates which preferences for ps data calls. */
   nv_ps_data_orig_pref_enum_type                   ps_data_orig_pref;
   /* Password used in HDR for Access Network stream CHAP authentication */
   nv_hdr_an_auth_passwd_long_type                  hdr_an_auth_passwd_long;
   /* Flag to do PPP resync on HDR to 1X handdown */
   boolean                                          ds_mip_qc_handdown_to_1x_opt;
   /* User ID used in HDR for Access Network stream CHAP authentication */
   nv_hdr_an_auth_user_id_long_type                 hdr_an_auth_user_id_long;
   /* Bypass timer value when the LNA_CNTL state machine is at 0001 */
   word                                             pcs_lna_bypass_timer_0;
   /* Delay time before PA_ON rises */
   uint16                                           wcdma_agc_pa_on_rise_delay;
   /* Delay time before PA_ON falls */
   uint16                                           wcdma_agc_pa_on_fall_delay;
   /* Delay time before TX_ON rises */
   uint16                                           wcdma_agc_tx_on_rise_delay;
   /* Delay time before TX_ON falls */
   uint16                                           wcdma_agc_tx_on_fall_delay;
   /* Tx agc update time */
   uint16                                           wcdma_agc_update_tx_agc_time;
   /* Delay time before PA_ON rises */
   uint16                                           wcdma_1900_agc_pa_on_rise_delay;
   /* Delay time before PA_ON rises */
   uint16                                           wcdma_1900_agc_pa_on_fall_delay;
   /* Delay time before TX_ON rises */
   uint16                                           wcdma_1900_agc_tx_on_rise_delay;
   /* Delay time before TX_ON falls */
   uint16                                           wcdma_1900_agc_tx_on_fall_delay;
   /* Tx agc update time */
   uint16                                           wcdma_1900_agc_update_tx_agc_time;
   /* PPP configuration options */
   nv_ppp_configure_data_type                       ppp_config_data;
   /* Offset to be applied in LNA Switch Point optimization calculation */
   int1                                             cell_1x_olta_backoff[4];
   /* Offset to be applied in LNA Switch Point optimization calculation */
   int1                                             cell_hdr_olta_backoff[4];
   /* Offset to be applied in LNA Switch Point optimization calculation */
   int1                                             pcs_olta_backoff[4];



   /* Tx power limit vs temperature */
   byte                                             bc6_tx_lim_vs_temp[NV_TEMP_TABLE_SIZ];
   /* Coefficients for Freq comp for Rx */
   word                                             c0_bc6_rx_cal_chan[16];
   /* Tx linearizer with internal PA=00 */
   nv_tx_linearizer_type                            bc6_tx_lin_master0;
   /* Tx linearizer with internal PA=01 */
   nv_tx_linearizer_type                            bc6_tx_lin_master1;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc6_tx_comp0;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc6_tx_comp1;
   /* Tx power limit vs frequency */
   int1                                             bc6_tx_lim_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Expected HDET reading */
   byte                                             bc6_exp_hdet_vs_agc[NV_EXP_HDET_VS_AGC_SIZ];
   /* ADC HDET reading offset */
   byte                                             bc6_hdet_off;
   /* ADC HDET reading span */
   byte                                             bc6_hdet_spn;
   /* PA stepup threshold to state 1 */
   byte                                             bc6_pa_r1_rise;
   /* PA stepdown threshold to state 0 */
   byte                                             bc6_pa_r1_fall;
   /* Control Sig for LNA Polarity */
   byte                                             bc6_lna_range_pol;
   /* LNA bypass Rx power level */
   int1                                             bc6_lna_1_rise;
   /* LNA turn on Rx power level */
   int1                                             bc6_lna_1_fall;
   /* Rx pwr offset when LNA is bypassed */
   word                                             c0_bc6_lna_range_offset;
   /* Rx pwr offset when LNA is bypassed */
   word                                             c1_bc6_lna_range_offset;
   /* Bypass level for 2nd LNA */
   int1                                             bc6_lna_2_rise;
   /* Nonbypass level for 2nd LNA */
   int1                                             bc6_lna_2_fall;
   /* Rx Range Offset when 2nd LNA is bypassed */
   int2                                             bc6_lna_range_12_offset;
   /* IM threshold for 2nd stage */
   byte                                             c0_bc6_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c0_bc6_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c0_bc6_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c0_bc6_im_level4;
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c0_bc6_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c1_bc6_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Phase rotation setting */
   byte                                             bc6_agc_phase_offset;
   /* Adjustment factor */
   byte                                             bc6_adj_factor;
   /* Receiver AGC min-max */
   nv_minmax_type                                   bc6_rx_agc_minmax;
   /* Rx AGC min-max */
   nv_minmax_type                                   bc6_rx_agc_min_11;
   /* Chipx8 delay */
   dword                                            bc6_enc_btf;
   /* CDMA Gain attenuation limit */
   int2                                             bc6_tx_gain_atten_limit;
   /* Falling threshold data */
   int1                                             bc6_lna_3_fall;
   /* Rising threshold data */
   int1                                             bc6_lna_3_rise;
   /* VGA linearizer Offset */
   int2                                             bc6_lna_3_offset;
   /* Gain variations of the LNA */
   int1                                             c0_bc6_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Gain variations of the LNA */
   int1                                             c1_bc6_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* Falling threshold data */
   int1                                             bc6_lna_4_fall;
   /* Rising threshold data */
   int1                                             bc6_lna_4_rise;
   /* VGA linearizer Offset */
   int2                                             c0_bc6_lna_4_offset;
   /* VGA linearizer Offset */
   int2                                             c1_bc6_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc6_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc6_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc6_im2_q_value;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc6_im2_q_value;
   /* VGA gain offset */
   int2                                             c0_bc6_vga_gain_offset;
   /* VGA gain offset */
   int2                                             c1_bc6_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c0_bc6_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA gain offset vs frequencies */
   int1                                             c1_bc6_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA gain offset vs temperatures */
   int2                                             c0_bc6_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* VGA gain offset vs temperatures */
   int2                                             c1_bc6_vga_gain_offset_vs_temp[NV_TEMP_TABLE_SIZ];
   /* P1 mode PA Rise/Fall offsets */
   byte                                             bc6_p1_rise_fall_off[8];
   /* LNA offsets in 4th state. */
   int1                                             c0_bc6_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA offsets in 4th state. */
   int1                                             c1_bc6_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* PA Rise/Fall offsets. */
   byte                                             c0_bc6_p1_rise_fall_offset[8];
   /* PA Rise/Fall offsets. */
   byte                                             c1_bc6_p1_rise_fall_offset[8];
   /* Coeff for mismatch compensation. */
   int4                                             c0_bc6_digital_mis_comp_a_offset;
   /* Coeff for mismatch compensation. */
   int4                                             c1_bc6_digital_mis_comp_a_offset;
   /* Coeff for mismatch compensation. */
   int4                                             c0_bc6_digital_mis_comp_b_offset;
   /* Coeff for mismatch compensation. */
   int4                                             c1_bc6_digital_mis_comp_b_offset;
   /* IM2 transconductance. */
   byte                                             c0_bc6_im2_transconductor_value;
   /* IM2 transconductance. */
   byte                                             c1_bc6_im2_transconductor_value;
   /*  VCO Coarse Tune Table. */
   byte                                             bc6_vco_coarse_tune_table[NV_VCO_COARSE_TUNE_TABLE_SIZ];
   /* GSM PA temperature comp for power index 0 */
   int8                                             gsm_pa_temp_comp_index_00[16];
   /* GSM PA temperature comp for power index 1 */
   int8                                             gsm_pa_temp_comp_index_01[16];
   /* GSM PA temperature comp for power index 2 */
   int8                                             gsm_pa_temp_comp_index_02[16];
   /* GSM PA temperature comp for power index 3 */
   int8                                             gsm_pa_temp_comp_index_03[16];
   /* GSM PA temperature comp for power index 4 */
   int8                                             gsm_pa_temp_comp_index_04[16];
   /* GSM PA temperature comp for power index 5 */
   int8                                             gsm_pa_temp_comp_index_05[16];
   /* GSM PA temperature comp for power index 6 */
   int8                                             gsm_pa_temp_comp_index_06[16];
   /* GSM PA temperature comp for power index 7 */
   int8                                             gsm_pa_temp_comp_index_07[16];
   /* GSM PA temperature comp for power index 8 */
   int8                                             gsm_pa_temp_comp_index_08[16];
   /* GSM PA temperature comp for power index 9 */
   int8                                             gsm_pa_temp_comp_index_09[16];
   /* GSM PA temperature comp for power index 10 */
   int8                                             gsm_pa_temp_comp_index_10[16];
   /* GSM PA temperature comp for power index 11 */
   int8                                             gsm_pa_temp_comp_index_11[16];
   /* GSM PA temperature comp for power index 12 */
   int8                                             gsm_pa_temp_comp_index_12[16];
   /* GSM PA temperature comp for power index 13 */
   int8                                             gsm_pa_temp_comp_index_13[16];
   /* DCS PA temperature comp for power index 0 */
   int8                                             dcs_pa_temp_comp_index_00[16];
   /* DCS PA temperature comp for power index 1 */
   int8                                             dcs_pa_temp_comp_index_01[16];
   /* DCS PA temperature comp for power index 2 */
   int8                                             dcs_pa_temp_comp_index_02[16];
   /* DCS PA temperature comp for power index 3 */
   int8                                             dcs_pa_temp_comp_index_03[16];
   /* DCS PA temperature comp for power index 4 */
   int8                                             dcs_pa_temp_comp_index_04[16];
   /* DCS PA temperature comp for power index 5 */
   int8                                             dcs_pa_temp_comp_index_05[16];
   /* DCS PA temperature comp for power index 6 */
   int8                                             dcs_pa_temp_comp_index_06[16];
   /* DCS PA temperature comp for power index 7 */
   int8                                             dcs_pa_temp_comp_index_07[16];
   /* DCS PA temperature comp for power index 8 */
   int8                                             dcs_pa_temp_comp_index_08[16];
   /* DCS PA temperature comp for power index 9 */
   int8                                             dcs_pa_temp_comp_index_09[16];
   /* DCS PA temperature comp for power index 10 */
   int8                                             dcs_pa_temp_comp_index_10[16];
   /* DCS PA temperature comp for power index 11 */
   int8                                             dcs_pa_temp_comp_index_11[16];
   /* DCS PA temperature comp for power index 12 */
   int8                                             dcs_pa_temp_comp_index_12[16];
   /* DCS PA temperature comp for power index 13 */
   int8                                             dcs_pa_temp_comp_index_13[16];
   /* DCS PA temperature comp for power index 14 */
   int8                                             dcs_pa_temp_comp_index_14[16];
   /* To enable/disable AMR capability for GSM */
   boolean                                          gsm_amr_call_config;
   /* Temperature comp of GSM PA in AMSS6200 */
   int8                                             gsm_pa_temp_comp_int8_index_14[16];
   /* Temperature comp of DCS PA in AMSS6200 */
   int8                                             dcs_pa_temp_comp_int8_index_15[16];
   /* This value indicates that the P-TMSI Signature is to be deleted */
   boolean                                          gmm_ptmsi_sig_tobe_deleted;
   /* Coefficients for Freq comp for Tx */
   word                                             c0_bc6_tx_cal_chan[16];
   /* Coefficients for Freq comp for CDMA Tx */
   word                                             cdma_tx_cal_chan[16];
   /* Coefficients for Freq comp for CDMA Rx */
   word                                             cdma_rx_cal_chan[16];
   /* Coefficients for Freq comp for PCS Rx. */
   word                                             pcs_rx_cal_chan[16];
   /* Coefficients for Freq comp for PCS Tx. */
   word                                             pcs_tx_cal_chan[16];
   /* Security Services Device Key */
   nv_sec_device_key_type                           sec_device_key;
   /* GSM-850 PA temperature comp for power index 0 */
   int8                                             gsm_850_pa_temp_comp_index_00[16];
   /* GSM-850 PA temperature comp for power index 1 */
   int8                                             gsm_850_pa_temp_comp_index_01[16];
   /* GSM-850 PA temperature comp for power index 2 */
   int8                                             gsm_850_pa_temp_comp_index_02[16];
   /* GSM-850 PA temperature comp for power index 3 */
   int8                                             gsm_850_pa_temp_comp_index_03[16];
   /* GSM-850 PA temperature comp for power index 4 */
   int8                                             gsm_850_pa_temp_comp_index_04[16];
   /* GSM-850 PA temperature comp for power index 5 */
   int8                                             gsm_850_pa_temp_comp_index_05[16];
   /* GSM-850 PA temperature comp for power index 6 */
   int8                                             gsm_850_pa_temp_comp_index_06[16];
   /* GSM-850 PA temperature comp for power index 7 */
   int8                                             gsm_850_pa_temp_comp_index_07[16];
   /* GSM-850 PA temperature comp for power index 8 */
   int8                                             gsm_850_pa_temp_comp_index_08[16];
   /* GSM-850 PA temperature comp for power index 9 */
   int8                                             gsm_850_pa_temp_comp_index_09[16];
   /* GSM-850 PA temperature comp for power index 10 */
   int8                                             gsm_850_pa_temp_comp_index_10[16];
   /* GSM-850 PA temperature comp for power index 11 */
   int8                                             gsm_850_pa_temp_comp_index_11[16];
   /* GSM-850 PA temperature comp for power index 12 */
   int8                                             gsm_850_pa_temp_comp_index_12[16];
   /* GSM-850 PA temperature comp for power index 13 */
   int8                                             gsm_850_pa_temp_comp_index_13[16];
   /* GSM-1900 PA temperature comp for power index 0 */
   int8                                             gsm_1900_pa_temp_comp_index_00[16];
   /* GSM-1900 PA temperature comp for power index 1 */
   int8                                             gsm_1900_pa_temp_comp_index_01[16];
   /* GSM-1900 PA temperature comp for power index 2 */
   int8                                             gsm_1900_pa_temp_comp_index_02[16];
   /* GSM-1900 PA temperature comp for power index 3 */
   int8                                             gsm_1900_pa_temp_comp_index_03[16];
   /* GSM-1900 PA temperature comp for power index 4 */
   int8                                             gsm_1900_pa_temp_comp_index_04[16];
   /* GSM-1900 PA temperature comp for power index 5 */
   int8                                             gsm_1900_pa_temp_comp_index_05[16];
   /* GSM-1900 PA temperature comp for power index 6 */
   int8                                             gsm_1900_pa_temp_comp_index_06[16];
   /* GSM-1900 PA temperature comp for power index 7 */
   int8                                             gsm_1900_pa_temp_comp_index_07[16];
   /* GSM-1900 PA temperature comp for power index 8 */
   int8                                             gsm_1900_pa_temp_comp_index_08[16];
   /* GSM-1900 PA temperature comp for power index 9 */
   int8                                             gsm_1900_pa_temp_comp_index_09[16];
   /* GSM-1900 PA temperature comp for power index 10 */
   int8                                             gsm_1900_pa_temp_comp_index_10[16];
   /* GSM-1900 PA temperature comp for power index 11 */
   int8                                             gsm_1900_pa_temp_comp_index_11[16];
   /* GSM-1900 PA temperature comp for power index 12 */
   int8                                             gsm_1900_pa_temp_comp_index_12[16];
   /* GSM-1900 PA temperature comp for power index 13 */
   int8                                             gsm_1900_pa_temp_comp_index_13[16];
   /* GSM-1900 PA temperature comp for power index 14 */
   int8                                             gsm_1900_pa_temp_comp_index_14[16];
   /* Flag for graceful close of dormant connections */
   boolean                                          tcp_graceful_dormant_close;
   /* Enables/Disables Inter Freq Feature */
   boolean                                          interfreq_enabled;
   /* Requested by customer to enable/disable EPLMN feature */
   boolean                                          eplmn_enabled;
   /* Dtmf values can be set to 3 values */
   uint8                                            dtmf;
   /* TRK LO ADJ default value */
   uint16                                           trk_lo_adj_default;
   /* TRK LO ADJ slope default value */
   uint16                                           trk_lo_adj_slope_default;
   /* Time delay to adjust PA range transition to high gain */
   uint16                                           wcdma_pa_gain_up_time;
   /* Time delay to adjust PA range transition to low gain */
   uint16                                           wcdma_pa_gain_down_time;
   /* The GPS Chain Delay cal. parameter. */
   word                                             bc6_gps1_rf_delay;
   /* Reserved for RF Tune */
   byte                                             bc6_rf_tune_reserved;
   /* Tx linearizer with internal PA=10 */
   nv_tx_linearizer_type                            bc6_tx_lin_master2;
   /* Tx linearizer with internal PA=11 */
   nv_tx_linearizer_type                            bc6_tx_lin_master3;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc6_tx_comp2;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc6_tx_comp3;
   /* PA stepup threshold to state 2 */
   byte                                             bc6_pa_r2_rise;
   /* PA stepdown threshold to state 1 */
   byte                                             bc6_pa_r2_fall;
   /* PA stepup threshold to state 3 */
   byte                                             bc6_pa_r3_rise;
   /* PA stepdown threshold to state 2 */
   byte                                             bc6_pa_r3_fall;
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c0_bc6_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c0_bc6_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c0_bc6_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c0_bc6_lna_3_offset;
   /* LNA rise 1 threshold */
   int1                                             c0_bc6_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c0_bc6_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c0_bc6_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c0_bc6_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c0_bc6_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c0_bc6_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c0_bc6_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c0_bc6_lna_4_fall;
   /* Coefficients for Freq comp for Tx */
   word                                             c1_bc6_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c1_bc6_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c1_bc6_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c1_bc6_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c1_bc6_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c1_bc6_lna_3_offset;
   /* LNA rise 1 threshold */
   int1                                             c1_bc6_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c1_bc6_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c1_bc6_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c1_bc6_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c1_bc6_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c1_bc6_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c1_bc6_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c1_bc6_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c1_bc6_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c1_bc6_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c1_bc6_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c1_bc6_im_level4;
   /* The GPS Chain Delay cal. parameter. */
   word                                             bc5_gps1_rf_delay;
   /* Reserved for RF Tune */
   byte                                             bc5_rf_tune_reserved;
   /* Tx power limit vs temperature */
   byte                                             bc5_tx_lim_vs_temp[8];
   /* Tx linearizer with internal PA=00 */
   nv_tx_linearizer_type                            bc5_tx_lin_master0;
   /* Tx linearizer with internal PA=01 */
   nv_tx_linearizer_type                            bc5_tx_lin_master1;
   /* Tx linearizer with internal PA=10 */
   nv_tx_linearizer_type                            bc5_tx_lin_master2;
   /* Tx linearizer with internal PA=11 */
   nv_tx_linearizer_type                            bc5_tx_lin_master3;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc5_tx_comp0;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc5_tx_comp1;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc5_tx_comp2;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc5_tx_comp3;
   /* Tx power limit vs frequency */
   int1                                             bc5_tx_lim_vs_freq[16];
   /* PA stepup threshold to state 1 */
   byte                                             bc5_pa_r1_rise;
   /* PA stepdown threshold to state 0 */
   byte                                             bc5_pa_r1_fall;
   /* PA stepup threshold to state 2 */
   byte                                             bc5_pa_r2_rise;
   /* PA stepdown threshold to state 1 */
   byte                                             bc5_pa_r2_fall;
   /* PA stepup threshold to state 3 */
   byte                                             bc5_pa_r3_rise;
   /* PA stepdown threshold to state 2 */
   byte                                             bc5_pa_r3_fall;
   /* ADC HDET reading offset */
   byte                                             bc5_hdet_off;
   /* ADC HDET reading span */
   byte                                             bc5_hdet_spn;
   /* Expected HDET reading */
   byte                                             bc5_exp_hdet_vs_agc[16];
   /* Chipx8 delay */
   dword                                            bc5_enc_btf[16];
   /* VCO Coarse Tune Table. */
   byte                                             bc5_vco_coarse_tune_table[16];
   /* P1 mode PA Rise/Fall offsets */
   byte                                             bc5_p1_rise_fall_off[8];
   /* Coefficients for Freq comp for Tx */
   word                                             c0_bc5_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c0_bc5_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c0_bc5_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c0_bc5_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c0_bc5_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c0_bc5_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c0_bc5_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c0_bc5_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c0_bc5_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c0_bc5_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc5_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc5_im2_q_value;
   /* VGA gain offset */
   int2                                             c0_bc5_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c0_bc5_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c0_bc5_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c0_bc5_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c0_bc5_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c0_bc5_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c0_bc5_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c0_bc5_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c0_bc5_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c0_bc5_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c0_bc5_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c0_bc5_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c0_bc5_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c0_bc5_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c0_bc5_im_level4;
   /* Coefficients for Freq comp for Tx */
   word                                             c1_bc5_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c1_bc5_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c1_bc5_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c1_bc5_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c1_bc5_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c1_bc5_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c1_bc5_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c1_bc5_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c1_bc5_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c1_bc5_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc5_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc5_im2_q_value;
   /* VGA gain offset */
   int2                                             c1_bc5_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c1_bc5_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c1_bc5_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c1_bc5_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c1_bc5_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c1_bc5_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c1_bc5_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c1_bc5_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c1_bc5_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c1_bc5_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c1_bc5_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c1_bc5_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c1_bc5_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c1_bc5_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c1_bc5_im_level4;
   /* The GPS Chain Delay cal. parameter. */
   word                                             bc4_gps1_rf_delay;
   /* Reserved for RF Tune */
   byte                                             bc4_rf_tune_reserved;
   /* Tx power limit vs temperature */
   byte                                             bc4_tx_lim_vs_temp[8];
   /* Tx linearizer with internal PA=00 */
   nv_tx_linearizer_type                            bc4_tx_lin_master0;
   /* Tx linearizer with internal PA=01 */
   nv_tx_linearizer_type                            bc4_tx_lin_master1;
   /* Tx linearizer with internal PA=10 */
   nv_tx_linearizer_type                            bc4_tx_lin_master2;
   /* Tx linearizer with internal PA=11 */
   nv_tx_linearizer_type                            bc4_tx_lin_master3;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc4_tx_comp0;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc4_tx_comp1;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc4_tx_comp2;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc4_tx_comp3;
   /* Tx power limit vs frequency */
   int1                                             bc4_tx_lim_vs_freq[16];
   /* PA stepup threshold to state 1 */
   byte                                             bc4_pa_r1_rise;
   /* PA stepdown threshold to state 0 */
   byte                                             bc4_pa_r1_fall;
   /* PA stepup threshold to state 2 */
   byte                                             bc4_pa_r2_rise;
   /* PA stepdown threshold to state 1 */
   byte                                             bc4_pa_r2_fall;
   /* PA stepup threshold to state 3 */
   byte                                             bc4_pa_r3_rise;
   /* PA stepdown threshold to state 2 */
   byte                                             bc4_pa_r3_fall;
   /* ADC HDET reading offset */
   byte                                             bc4_hdet_off;
   /* ADC HDET reading span */
   byte                                             bc4_hdet_spn;
   /* Expected HDET reading */
   byte                                             bc4_exp_hdet_vs_agc[16];
   /* Chipx8 delay */
   dword                                            bc4_enc_btf[16];
   /* VCO Coarse Tune Table. */
   byte                                             bc4_vco_coarse_tune_table[16];
   /* P1 mode PA Rise/Fall offsets */
   byte                                             bc4_p1_rise_fall_off[8];
   /* Coefficients for Freq comp for Tx */
   word                                             c0_bc4_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c0_bc4_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c0_bc4_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c0_bc4_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c0_bc4_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c0_bc4_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c0_bc4_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c0_bc4_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c0_bc4_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c0_bc4_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc4_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc4_im2_q_value;
   /* VGA gain offset */
   int2                                             c0_bc4_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c0_bc4_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c0_bc4_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c0_bc4_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c0_bc4_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c0_bc4_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c0_bc4_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c0_bc4_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c0_bc4_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c0_bc4_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c0_bc4_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c0_bc4_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c0_bc4_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c0_bc4_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c0_bc4_im_level4;
   /* Coefficients for Freq comp for Tx */
   word                                             c1_bc4_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c1_bc4_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c1_bc4_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c1_bc4_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c1_bc4_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c1_bc4_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c1_bc4_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c1_bc4_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c1_bc4_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c1_bc4_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc4_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc4_im2_q_value;
   /* VGA gain offset */
   int2                                             c1_bc4_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c1_bc4_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c1_bc4_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c1_bc4_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c1_bc4_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c1_bc4_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c1_bc4_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c1_bc4_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c1_bc4_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c1_bc4_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c1_bc4_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c1_bc4_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c1_bc4_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c1_bc4_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c1_bc4_im_level4;
   /* The GPS Chain Delay cal. parameter. */
   word                                             bc3_gps1_rf_delay;
   /* Reserved for RF Tune */
   byte                                             bc3_rf_tune_reserved;
   /* Tx power limit vs temperature */
   byte                                             bc3_tx_lim_vs_temp[8];
   /* Tx linearizer with internal PA=00 */
   nv_tx_linearizer_type                            bc3_tx_lin_master0;
   /* Tx linearizer with internal PA=01 */
   nv_tx_linearizer_type                            bc3_tx_lin_master1;
   /* Tx linearizer with internal PA=10 */
   nv_tx_linearizer_type                            bc3_tx_lin_master2;
   /* Tx linearizer with internal PA=11 */
   nv_tx_linearizer_type                            bc3_tx_lin_master3;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc3_tx_comp0;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc3_tx_comp1;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc3_tx_comp2;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc3_tx_comp3;
   /* Tx power limit vs frequency */
   int1                                             bc3_tx_lim_vs_freq[16];
   /* PA stepup threshold to state 1 */
   byte                                             bc3_pa_r1_rise;
   /* PA stepdown threshold to state 0 */
   byte                                             bc3_pa_r1_fall;
   /* PA stepup threshold to state 2 */
   byte                                             bc3_pa_r2_rise;
   /* PA stepdown threshold to state 1 */
   byte                                             bc3_pa_r2_fall;
   /* PA stepup threshold to state 3 */
   byte                                             bc3_pa_r3_rise;
   /* PA stepdown threshold to state 2 */
   byte                                             bc3_pa_r3_fall;
   /* ADC HDET reading offset */
   byte                                             bc3_hdet_off;
   /* ADC HDET reading span */
   byte                                             bc3_hdet_spn;
   /* Expected HDET reading */
   byte                                             bc3_exp_hdet_vs_agc[16];
   /* Chipx8 delay */
   dword                                            bc3_enc_btf[16];
   /* VCO Coarse Tune Table. */
   byte                                             bc3_vco_coarse_tune_table[16];
   /* P1 mode PA Rise/Fall offsets */
   byte                                             bc3_p1_rise_fall_off[8];
   /* Coefficients for Freq comp for Tx */
   word                                             c0_bc3_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c0_bc3_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c0_bc3_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c0_bc3_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c0_bc3_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c0_bc3_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c0_bc3_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c0_bc3_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c0_bc3_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c0_bc3_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc3_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc3_im2_q_value;
   /* VGA gain offset */
   int2                                             c0_bc3_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c0_bc3_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c0_bc3_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c0_bc3_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c0_bc3_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c0_bc3_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c0_bc3_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c0_bc3_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c0_bc3_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c0_bc3_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c0_bc3_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c0_bc3_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c0_bc3_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c0_bc3_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c0_bc3_im_level4;
   /* Coefficients for Freq comp for Tx */
   word                                             c1_bc3_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c1_bc3_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c1_bc3_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c1_bc3_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c1_bc3_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c1_bc3_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c1_bc3_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c1_bc3_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c1_bc3_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c1_bc3_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc3_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc3_im2_q_value;
   /* VGA gain offset */
   int2                                             c1_bc3_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c1_bc3_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c1_bc3_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c1_bc3_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c1_bc3_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c1_bc3_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c1_bc3_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c1_bc3_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c1_bc3_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c1_bc3_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c1_bc3_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c1_bc3_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c1_bc3_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c1_bc3_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c1_bc3_im_level4;
   /* The GPS Chain Delay cal. parameter. */
   word                                             bc1_gps1_rf_delay;
   /* Reserved for RF Tune */
   byte                                             bc1_rf_tune_reserved;
   /* Tx power limit vs temperature */
   byte                                             bc1_tx_lim_vs_temp[8];
   /* Tx linearizer with internal PA=00 */
   nv_tx_linearizer_type                            bc1_tx_lin_master0;
   /* Tx linearizer with internal PA=01 */
   nv_tx_linearizer_type                            bc1_tx_lin_master1;
   /* Tx linearizer with internal PA=10 */
   nv_tx_linearizer_type                            bc1_tx_lin_master2;
   /* Tx linearizer with internal PA=11 */
   nv_tx_linearizer_type                            bc1_tx_lin_master3;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc1_tx_comp0;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc1_tx_comp1;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc1_tx_comp2;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc1_tx_comp3;
   /* Tx power limit vs frequency */
   int1                                             bc1_tx_lim_vs_freq[16];
   /* PA stepup threshold to state 1 */
   byte                                             bc1_pa_r1_rise;
   /* PA stepdown threshold to state 0 */
   byte                                             bc1_pa_r1_fall;
   /* PA stepup threshold to state 2 */
   byte                                             bc1_pa_r2_rise;
   /* PA stepdown threshold to state 1 */
   byte                                             bc1_pa_r2_fall;
   /* PA stepup threshold to state 3 */
   byte                                             bc1_pa_r3_rise;
   /* PA stepdown threshold to state 2 */
   byte                                             bc1_pa_r3_fall;
   /* ADC HDET reading offset */
   byte                                             bc1_hdet_off;
   /* ADC HDET reading span */
   byte                                             bc1_hdet_spn;
   /* Expected HDET reading */
   byte                                             bc1_exp_hdet_vs_agc[16];
   /* Chipx8 delay */
   dword                                            bc1_enc_btf[16];
   /* VCO Coarse Tune Table. */
   byte                                             bc1_vco_coarse_tune_table[16];
   /* P1 mode PA Rise/Fall offsets */
   byte                                             bc1_p1_rise_fall_off[8];
   /* Coefficients for Freq comp for Tx */
   word                                             c0_bc1_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c0_bc1_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c0_bc1_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c0_bc1_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c0_bc1_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c0_bc1_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c0_bc1_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c0_bc1_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c0_bc1_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c0_bc1_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc1_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc1_im2_q_value;
   /* VGA gain offset */
   int2                                             c0_bc1_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c0_bc1_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c0_bc1_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c0_bc1_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c0_bc1_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c0_bc1_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c0_bc1_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c0_bc1_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c0_bc1_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c0_bc1_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c0_bc1_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c0_bc1_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c0_bc1_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c0_bc1_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c0_bc1_im_level4;
   /* Coefficients for Freq comp for Tx */
   word                                             c1_bc1_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c1_bc1_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c1_bc1_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c1_bc1_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c1_bc1_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c1_bc1_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c1_bc1_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c1_bc1_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c1_bc1_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c1_bc1_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc1_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc1_im2_q_value;
   /* VGA gain offset */
   int2                                             c1_bc1_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c1_bc1_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c1_bc1_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c1_bc1_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c1_bc1_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c1_bc1_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c1_bc1_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c1_bc1_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c1_bc1_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c1_bc1_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c1_bc1_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c1_bc1_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c1_bc1_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c1_bc1_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c1_bc1_im_level4;
   /* The GPS Chain Delay cal. parameter. */
   word                                             bc0_gps1_rf_delay;
   /* Reserved for RF Tune */
   byte                                             bc0_rf_tune_reserved;
   /* Tx power limit vs temperature */
   byte                                             bc0_tx_lim_vs_temp[8];
   /* Tx linearizer with internal PA=00 */
   nv_tx_linearizer_type                            bc0_tx_lin_master0;
   /* Tx linearizer with internal PA=01 */
   nv_tx_linearizer_type                            bc0_tx_lin_master1;
   /* Tx linearizer with internal PA=10 */
   nv_tx_linearizer_type                            bc0_tx_lin_master2;
   /* Tx linearizer with internal PA=11 */
   nv_tx_linearizer_type                            bc0_tx_lin_master3;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc0_tx_comp0;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc0_tx_comp1;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc0_tx_comp2;
   /* Compensation for Tx linz */
   nv_tx_comp_type                                  bc0_tx_comp3;
   /* Tx power limit vs frequency */
   int1                                             bc0_tx_lim_vs_freq[16];
   /* PA stepup threshold to state 1 */
   byte                                             bc0_pa_r1_rise;
   /* PA stepdown threshold to state 0 */
   byte                                             bc0_pa_r1_fall;
   /* PA stepup threshold to state 2 */
   byte                                             bc0_pa_r2_rise;
   /* PA stepdown threshold to state 1 */
   byte                                             bc0_pa_r2_fall;
   /* PA stepup threshold to state 3 */
   byte                                             bc0_pa_r3_rise;
   /* PA stepdown threshold to state 2 */
   byte                                             bc0_pa_r3_fall;
   /* ADC HDET reading offset */
   byte                                             bc0_hdet_off;
   /* ADC HDET reading span */
   byte                                             bc0_hdet_spn;
   /* Expected HDET reading */
   byte                                             bc0_exp_hdet_vs_agc[16];
   /* Chipx8 delay */
   dword                                            bc0_enc_btf[16];
   /* VCO Coarse Tune Table. */
   byte                                             bc0_vco_coarse_tune_table[16];
   /* P1 mode PA Rise/Fall offsets */
   byte                                             bc0_p1_rise_fall_off[8];
   /* Coefficients for Freq comp for Tx */
   word                                             c0_bc0_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c0_bc0_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c0_bc0_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c0_bc0_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c0_bc0_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c0_bc0_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c0_bc0_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c0_bc0_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c0_bc0_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c0_bc0_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc0_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c0_bc0_im2_q_value;
   /* VGA gain offset */
   int2                                             c0_bc0_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c0_bc0_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c0_bc0_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c0_bc0_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c0_bc0_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c0_bc0_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c0_bc0_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c0_bc0_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c0_bc0_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c0_bc0_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c0_bc0_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c0_bc0_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c0_bc0_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c0_bc0_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c0_bc0_im_level4;
   /* Coefficients for Freq comp for Tx */
   word                                             c1_bc0_tx_cal_chan[16];
   /* Coefficients for Freq comp for Rx */
   word                                             c1_bc0_rx_cal_chan[16];
   /* LNA bypass offset vs. freq. Comp for state 1 */
   int1                                             c1_bc0_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 2 */
   int1                                             c1_bc0_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 3 */
   int1                                             c1_bc0_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* LNA bypass offset vs. freq. Comp for state 4 */
   int1                                             c1_bc0_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
   /* VGA linearizer Offset for state 1 */
   int2                                             c1_bc0_lna_1_offset;
   /* VGA linearizer Offset for state 2 */
   int2                                             c1_bc0_lna_2_offset;
   /* VGA linearizer Offset for state 3 */
   int2                                             c1_bc0_lna_3_offset;
   /* VGA linearizer Offset for state 4 */
   int2                                             c1_bc0_lna_4_offset;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc0_im2_i_value;
   /* IM2 cal for RFR6000 */
   byte                                             c1_bc0_im2_q_value;
   /* VGA gain offset */
   int2                                             c1_bc0_vga_gain_offset;
   /* VGA gain offset vs frequencies */
   int1                                             c1_bc0_vga_gain_offset_vs_freq[16];
   /* IM2 transconductance. */
   byte                                             c1_bc0_im2_transconductor_value;
   /* LNA rise 1 threshold */
   int1                                             c1_bc0_lna_1_rise;
   /* LNA fall 1 threshold */
   int1                                             c1_bc0_lna_1_fall;
   /* LNA rise 2 threshold */
   int1                                             c1_bc0_lna_2_rise;
   /* LNA fall 2 threshold */
   int1                                             c1_bc0_lna_2_fall;
   /* LNA rise 3 threshold */
   int1                                             c1_bc0_lna_3_rise;
   /* LNA fall 3 threshold */
   int1                                             c1_bc0_lna_3_fall;
   /* LNA rise 4 threshold */
   int1                                             c1_bc0_lna_4_rise;
   /* LNA fall 4 threshold */
   int1                                             c1_bc0_lna_4_fall;
   /* IM threshold for 2nd stage */
   byte                                             c1_bc0_im_level1;
   /* IM threshold for 3rd stage */
   byte                                             c1_bc0_im_level2;
   /* IM threshold for 4th stage */
   byte                                             c1_bc0_im_level3;
   /* IM threshold for 5th stage */
   byte                                             c1_bc0_im_level4;
   /* Tunes the RX baseband filter bandwidth */
   uint8                                            rfr_bb_filter;
   /* Tunes the value of the baseband resistor */
   uint8                                            rfr_iq_line_resistor;
   /* Maps coarse tune codes to actual VCO frequency ranges */
   uint8                                            wcdma_rfr_vco_coarse_tuning[12];
   /* Maps coarse tune codes to actual VCO frequency ranges */
   uint8                                            rfr_vco_coarse_tuning_1900[12];
   /* TX rotator angle for PA range state 00 */
   uint16                                           wcdma_tx_rot_angle_pa_state_00;
   /* TX rotator angle for PA range state 01 */
   uint16                                           wcdma_tx_rot_angle_pa_state_01;
   /* TX rotator angle for PA range state 10 */
   uint16                                           wcdma_tx_rot_angle_pa_state_10;
   /* TX rotator angle for PA range state 11 */
   uint16                                           wcdma_tx_rot_angle_pa_state_11;
   /* To Support Adative Multi Rate (Full rate and Half Rate) Speech */
   boolean                                          amr;
   /* True - Enable spike mitigation or False - Disable spike mitigation */
   boolean                                          wcdma_spike_mitigation_enabled;

   /* Mobile Equipment IDentifier */
   qword                                            meid;
   /* MEID Check Digit */
   uint8                                            meid_cd;

   /* Max. Power for GSM_900 AMAM Table */
   int16                                            gsm_amam_max_pwr;
   /* Min. Power for GSM_900 AMAM Table */
   int16                                            gsm_amam_min_pwr;
   /* Max. Power for DCS_1800 AMAM Table */
   int16                                            dcs_amam_max_pwr;
   /* Min. Power for DCS_1800 AMAM Table */
   int16                                            dcs_amam_min_pwr;
   /* Max. Power for GSM_850 AMAM Table */
   int16                                            gsm_850_amam_max_pwr;
   /* Min. Power for GSM_850 AMAM Table */
   int16                                            gsm_850_amam_min_pwr;
   /* Max. Power for GSM_1900 AMAM Table */
   int16                                            gsm_1900_amam_max_pwr;
   /* Min. Power for GSM_1900 AMAM table */
   int16                                            gsm_1900_amam_min_pwr;
   /* GSM_900 AMAM Master Table Segment1 at Freq. F1 */
   uint16                                           gsm_amam_master_tbl_seg1_f1[64];
   /* GSM_900 AMAM Master Table Segment2 at Freq. F1 */
   uint16                                           gsm_amam_master_tbl_seg2_f1[64];
   /* GSM_900 AMAM Master Table Segment3 at Freq. F1 */
   uint16                                           gsm_amam_master_tbl_seg3_f1[64];
   /* GSM_900 AMAM Master Table Segment4 at Freq. F1 */
   uint16                                           gsm_amam_master_tbl_seg4_f1[64];
   /* GSM_900 AMAM Master Table Segment5 at Freq. F1 */
   uint16                                           gsm_amam_master_tbl_seg5_f1[64];
   /* GSM_900 AMAM Master Table Segment6 at Freq. F1 */
   uint16                                           gsm_amam_master_tbl_seg6_f1[64];
   /* GSM_900 AMAM Master Table Segment7 at Freq. F1 */
   uint16                                           gsm_amam_master_tbl_seg7_f1[64];
   /* GSM_900 AMAM Master Table Segment8 at Freq. F1 */
   uint16                                           gsm_amam_master_tbl_seg8_f1[64];
   /* DCS_1800 AMAM Master Table Segment1 at Freq. F1 */
   uint16                                           dcs_amam_master_tbl_seg1_f1[64];
   /* DCS_1800 AMAM Master Table Segment2 at Freq. F1 */
   uint16                                           dcs_amam_master_tbl_seg2_f1[64];
   /* DCS_1800 AMAM Master Table Segment3 at Freq. F1 */
   uint16                                           dcs_amam_master_tbl_seg3_f1[64];
   /* DCS_1800 AMAM Master Table Segment4 at Freq. F1 */
   uint16                                           dcs_amam_master_tbl_seg4_f1[64];
   /* DCS_1800 AMAM Master Table Segment5 at Freq. F1 */
   uint16                                           dcs_amam_master_tbl_seg5_f1[64];
   /* DCS_1800 AMAM Master Table Segment6 at Freq. F1 */
   uint16                                           dcs_amam_master_tbl_seg6_f1[64];
   /* DCS_1800 AMAM Master Table Segment7 at Freq. F1 */
   uint16                                           dcs_amam_master_tbl_seg7_f1[64];
   /* DCS_1800 AMAM Master Table Segment8 at Freq. F1 */
   uint16                                           dcs_amam_master_tbl_seg8_f1[64];
   /* GSM_850 AMAM Master Table Segment1 at Freq. F1 */
   uint16                                           gsm_850_amam_master_tbl_seg1_f1[64];
   /* GSM_850 AMAM Master Table Segment2 at Freq. F1 */
   uint16                                           gsm_850_amam_master_tbl_seg2_f1[64];
   /* GSM_850 AMAM Master Table Segment3 at Freq. F1 */
   uint16                                           gsm_850_amam_master_tbl_seg3_f1[64];
   /* GSM_850 AMAM Master Table Segment4 at Freq. F1 */
   uint16                                           gsm_850_amam_master_tbl_seg4_f1[64];
   /* GSM_850 AMAM Master Table Segment5 at Freq. F1 */
   uint16                                           gsm_850_amam_master_tbl_seg5_f1[64];
   /* GSM_850 AMAM Master Table Segment6 at Freq.F1 */
   uint16                                           gsm_850_amam_master_tbl_seg6_f1[64];
   /* GSM_850 AMAM Master Table Segment7 at Freq. F1 */
   uint16                                           gsm_850_amam_master_tbl_seg7_f1[64];
   /* GSM_850 AMAM Master Table Segment8 at Freq. F1 */
   uint16                                           gsm_850_amam_master_tbl_seg8_f1[64];
   /* GSM_1900 AMAM Master Table Segment1 at Freq. F1 */
   uint16                                           gsm_1900_amam_master_tbl_seg1_f1[64];
   /* GSM_1900 AMAM Master Table Segment2 at Freq. F1 */
   uint16                                           gsm_1900_amam_master_tbl_seg2_f1[64];
   /* GSM_1900 AMAM Master Table Segment3 at Freq. F1 */
   uint16                                           gsm_1900_amam_master_tbl_seg3_f1[64];
   /* GSM_1900 AMAM Master Table Segment4 at Freq. F1 */
   uint16                                           gsm_1900_amam_master_tbl_seg4_f1[64];
   /* GSM_1900 AMAM Master Table Segment5 at Freq. F1 */
   uint16                                           gsm_1900_amam_master_tbl_seg5_f1[64];
   /* GSM_1900 AMAM Master Table Segment6 at Freq. F1 */
   uint16                                           gsm_1900_amam_master_tbl_seg6_f1[64];
   /* GSM_1900 AMAM Master Table Segment7 at Freq. F1 */
   uint16                                           gsm_1900_amam_master_tbl_seg7_f1[64];
   /* GSM_1900 AMAM Master Table Segment8 at Freq. F1 */
   uint16                                           gsm_1900_amam_master_tbl_seg8_f1[64];
   /* GSM_900 AMAM Master Table Segment1 at Freq. F2 */
   uint16                                           gsm_amam_master_tbl_seg1_f2[64];
   /* GSM_900 AMAM Master Table Segment2 at Freq. F2 */
   uint16                                           gsm_amam_master_tbl_seg2_f2[64];
   /* GSM_900 AMAM Master Table Segment3 at Freq. F2 */
   uint16                                           gsm_amam_master_tbl_seg3_f2[64];
   /* GSM_900 AMAM Master Table Segment4 at Freq. F2 */
   uint16                                           gsm_amam_master_tbl_seg4_f2[64];
   /* GSM_900 AMAM Master table Segment5 at Freq. F2 */
   uint16                                           gsm_amam_master_tbl_seg5_f2[64];
   /* GSM_900 AMAM Master Table Segment6 at Freq. F2 */
   uint16                                           gsm_amam_master_tbl_seg6_f2[64];
   /* GSM_900 AMAM Master Table Segment7 at Freq. F2 */
   uint16                                           gsm_amam_master_tbl_seg7_f2[64];
   /* GSM_900 AMAM Master Table Segment8 at Freq. F2 */
   uint16                                           gsm_amam_master_tbl_seg8_f2[64];
   /* DCS_1800 AMAM Master Table Segment1 at Freq. F2 */
   uint16                                           dcs_amam_master_tbl_seg1_f2[64];
   /* DCS_1800 AMAM Master Table Segment2 at Freq. F2 */
   uint16                                           dcs_amam_master_tbl_seg2_f2[64];
   /* DCS_1800 AMAM Master Table Segment3 at Freq. F2 */
   uint16                                           dcs_amam_master_tbl_seg3_f2[64];
   /* DCS_1800 AMAM Master Table Segment4 at Freq. F2 */
   uint16                                           dcs_amam_master_tbl_seg4_f2[64];
   /* DCS_1800 AMAM Master Table Segment5 at Freq. F2 */
   uint16                                           dcs_amam_master_tbl_seg5_f2[64];
   /* DCS_1800 AMAM Master Table Segment6 at Freq. F2 */
   uint16                                           dcs_amam_master_tbl_seg6_f2[64];
   /* DCS_1800 AMAM Master Table Segment7 at Freq. F2 */
   uint16                                           dcs_amam_master_tbl_seg7_f2[64];
   /* DCS_1800 AMAM Master Table Segment8 at Freq. F2 */
   uint16                                           dcs_amam_master_tbl_seg8_f2[64];
   /* GSM_850 AMAM Master Table Segment1 at Freq. F2 */
   uint16                                           gsm_850_amam_master_tbl_seg1_f2[64];
   /* GSM_850 AMAM Master Table Segment2 at Freq. F2 */
   uint16                                           gsm_850_amam_master_tbl_seg2_f2[64];
   /* GSM_850 AMAM Master Table Segment3 at Freq. F2 */
   uint16                                           gsm_850_amam_master_tbl_seg3_f2[64];
   /* GSM_850 AMAM Master Table Segment4 at Freq. F2 */
   uint16                                           gsm_850_amam_master_tbl_seg4_f2[64];
   /* GSM_850 AMAM Master Table Segment5 at Freq. F2 */
   uint16                                           gsm_850_amam_master_tbl_seg5_f2[64];
   /* GSM_850 AMAM Master Table Segment6 at Freq. F2 */
   uint16                                           gsm_850_amam_master_tbl_seg6_f2[64];
   /* GSM_850 AMAM Master Table Segment7 at Freq. F2 */
   uint16                                           gsm_850_amam_master_tbl_seg7_f2[64];
   /* GSM_850 AMAM Master Table Segment8 at Freq. F2 */
   uint16                                           gsm_850_amam_master_tbl_seg8_f2[64];
   /* GSM_1900 AMAM Master Table Segment1 at Freq. F2 */
   uint16                                           gsm_1900_amam_master_tbl_seg1_f2[64];
   /* GSM_1900 AMAM Master Table Segment2 at Freq. F2 */
   uint16                                           gsm_1900_amam_master_tbl_seg2_f2[64];
   /* GSM_1900 AMAM Master Table Segment3 at Freq. F2 */
   uint16                                           gsm_1900_amam_master_tbl_seg3_f2[64];
   /* GSM_1900 AMAM Master Table Segment4 at Freq. F2 */
   uint16                                           gsm_1900_amam_master_tbl_seg4_f2[64];
   /* GSM_1900 AMAM Master Table Segment5 at Freq. F2 */
   uint16                                           gsm_1900_amam_master_tbl_seg5_f2[64];
   /* GSM_1900 AMAM Master Table Segment6 at Freq. F2 */
   uint16                                           gsm_1900_amam_master_tbl_seg6_f2[64];
   /* GSM_1900 AMAM Master Table Segment7 at Freq. F2 */
   uint16                                           gsm_1900_amam_master_tbl_seg7_f2[64];
   /* GSM_1900 AMAM Master Table Segment8 at Freq. F2 */
   uint16                                           gsm_1900_amam_master_tbl_seg8_f2[64];
   /* GSM_900 AMPM Master Table Segment1 at Freq. F1 */
   uint32                                           gsm_ampm_master_tbl_seg1_f1[32];
   /* GSM_900 AMPM Master Table Segment2 at Freq. F1 */
   uint32                                           gsm_ampm_master_tbl_seg2_f1[32];
   /* GSM_900 AMPM Master Table Segment3 at Freq. F1 */
   uint32                                           gsm_ampm_master_tbl_seg3_f1[32];
   /* GSM_900 AMPM Master Table Segment4 at Freq. F1 */
   uint32                                           gsm_ampm_master_tbl_seg4_f1[32];
   /* GSM_900 AMPM Master Table Segment5 at Freq. F1 */
   uint32                                           gsm_ampm_master_tbl_seg5_f1[32];
   /* GSM_900 AMPM Master Table Segment6 at Freq. F1 */
   uint32                                           gsm_ampm_master_tbl_seg6_f1[32];
   /* GSM_900 AMPM Master Table Segment7 at Freq. F1 */
   uint32                                           gsm_ampm_master_tbl_seg7_f1[32];
   /* GSM_900 AMPM Master Table Segment8 at Freq. F1 */
   uint32                                           gsm_ampm_master_tbl_seg8_f1[32];
   /* DCS_1800 AMPM Master Table Segment1 at Freq. F1 */
   uint32                                           dcs_ampm_master_tbl_seg1_f1[32];
   /* DCS_1800 AMPM Master Table Segment2 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg2_f1[32];
   /* DCS_1800 AMPM Master Table Segment3 at Freq. F1 */
   uint32                                           dcs_ampm_master_tbl_seg3_f1[32];
   /* DCS_1800 AMPM Master Table Segment4 at Freq. F1 */
   uint32                                           dcs_ampm_master_tbl_seg4_f1[32];
   /* DCS_1800 AMPM Master Table Segment5 at Freq. F1 */
   uint32                                           dcs_ampm_master_tbl_seg5_f1[32];
   /* DCS_1800 AMPM Master Table Segment6 at Freq. F1 */
   uint32                                           dcs_ampm_master_tbl_seg6_f1[32];
   /* DCS_1800 AMPM Master Table Segment7 at Freq. F1 */
   uint32                                           dcs_ampm_master_tbl_seg7_f1[32];
   /* DCS_1800 AMPM Master Table Segment8 at Freq. F1 */
   uint32                                           dcs_ampm_master_tbl_seg8_f1[32];
   /* GSM_850 AMPM Master Table Segment1 at Freq. F1 */
   uint32                                           gsm_850_ampm_master_tbl_seg1_f1[32];
   /* GSM_850 AMPM Master Table Segment2 at Freq. F1 */
   uint32                                           gsm_850_ampm_master_tbl_seg2_f1[32];
   /* GSM_850 AMPM Master Table Segment3 at Freq. F1 */
   uint32                                           gsm_850_ampm_master_tbl_seg3_f1[32];
   /* GSM_850 AMPM Master Table Segment4 at Freq. F1 */
   uint32                                           gsm_850_ampm_master_tbl_seg4_f1[32];
   /* GSM_850 AMPM Master Table Segment5 at Freq. F1 */
   uint32                                           gsm_850_ampm_master_tbl_seg5_f1[32];
   /* GSM_850 AMPM Master Table Segment6 at Freq. F1 */
   uint32                                           gsm_850_ampm_master_tbl_seg6_f1[32];
   /* GSM_850 AMPM Master Table Segment7 at Freq. F1 */
   uint32                                           gsm_850_ampm_master_tbl_seg7_f1[32];
   /* GSM_850 AMPM Master Table Segment8 at Freq. F1 */
   uint32                                           gsm_850_ampm_master_tbl_seg8_f1[32];
   /* GSM_1900 AMPM Master Table Segment1 at Freq. F1 */
   uint32                                           gsm_1900_ampm_master_tbl_seg1_f1[32];
   /* GSM_1900 AMPM Master Table Segment2 at Freq. F1 */
   uint32                                           gsm_1900_ampm_master_tbl_seg2_f1[32];
   /* GSM_1900 AMPM Master Table Segment3 at Freq. F1 */
   uint32                                           gsm_1900_ampm_master_tbl_seg3_f1[32];
   /* GSM_1900 AMPM Master Table Segment4 at Freq. F1 */
   uint32                                           gsm_1900_ampm_master_tbl_seg4_f1[32];
   /* GSM_1900 AMPM Master Table Segment5 at Freq. F1 */
   uint32                                           gsm_1900_ampm_master_tbl_seg5_f1[32];
   /* GSM_1900 AMPM Master Table Segment6 at Freq. F1 */
   uint32                                           gsm_1900_ampm_master_tbl_seg6_f1[32];
   /* GSM_1900 AMPM Master Table Segment7 at Freq. F1 */
   uint32                                           gsm_1900_ampm_master_tbl_seg7_f1[32];
   /* GSM_1900 AMPM Master Table Segment8 at Freq. F1 */
   uint32                                           gsm_1900_ampm_master_tbl_seg8_f1[32];
   /* GSM_900 AMPM Master Table Segment1 at Freq. F2 */
   uint32                                           gsm_ampm_master_tbl_seg1_f2[32];
   /* GSM_900 AMPM Master Table Segment2 at Freq. F2 */
   uint32                                           gsm_ampm_master_tbl_seg2_f2[32];
   /* GSM_900 AMPM Master Table Segment3 at Freq. F2 */
   uint32                                           gsm_ampm_master_tbl_seg3_f2[32];
   /* GSM_900 AMPM Master Table Segment4 at Freq. F2 */
   uint32                                           gsm_ampm_master_tbl_seg4_f2[32];
   /* GSM_900 AMPM Master Table Segment5 at Freq. F2 */
   uint32                                           gsm_ampm_master_tbl_seg5_f2[32];
   /* GSM_900 AMPM Master Table Segment6 at Freq. F2 */
   uint32                                           gsm_ampm_master_tbl_seg6_f2[32];
   /* GSM_900 AMPM Master Table Segment7 at Freq. F2 */
   uint32                                           gsm_ampm_master_tbl_seg7_f2[32];
   /* GSM_900 AMPM Master Table Segment8 at Freq. F2 */
   uint32                                           gsm_ampm_master_tbl_seg8_f2[32];
   /* DCS_1800 AMPM Master Table Segment1 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg1_f2[32];
   /* DCS_1800 AMPM Master Table Segment2 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg2_f2[32];
   /* DCS_1800 AMPM Master Table Segment3 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg3_f2[32];
   /* DCS_1800 AMPM Master Table Segment4 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg4_f2[32];
   /* DCS_1800 AMPM Master Table Segment5 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg5_f2[32];
   /* DCS_1800 AMPM Master Table Segment6 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg6_f2[32];
   /* DCS_1800 AMPM Master Table Segment7 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg7_f2[32];
   /* DCS_1800 AMPM Master Table Segment8 at Freq. F2 */
   uint32                                           dcs_ampm_master_tbl_seg8_f2[32];
   /* GSM_850 AMPM Master Table Segment1 at Freq. F2 */
   uint32                                           gsm_850_ampm_master_tbl_seg1_f2[32];
   /* GSM_850 AMPM Master Table Segment2 at Freq. F2 */
   uint32                                           gsm_850_ampm_master_tbl_seg2_f2[32];
   /* GSM_850 AMPM Master Table Segment3 at Freq. F2 */
   uint32                                           gsm_850_ampm_master_tbl_seg3_f2[32];
   /* GSM_850 AMPM Master Table Segment4 at Freq. F2 */
   uint32                                           gsm_850_ampm_master_tbl_seg4_f2[32];
   /* GSM_850 AMPM Master Table Segment5 at Freq. F2 */
   uint32                                           gsm_850_ampm_master_tbl_seg5_f2[32];
   /* GSM_850 AMPM Master Table Segment6 at Freq. F2 */
   uint32                                           gsm_850_ampm_master_tbl_seg6_f2[32];
   /* GSM_850 AMPM Master Table Segment7 at Freq. F2 */
   uint32                                           gsm_850_ampm_master_tbl_seg7_f2[32];
   /* GSM_850 AMPM Master Table Segment8 at Freq. F2 */
   uint32                                           gsm_850_ampm_master_tbl_seg8_f2[32];
   /* GSM_1900 AMPM Master Table Segment1 at Freq. F2 */
   uint32                                           gsm_1900_ampm_master_tbl_seg1_f2[32];
   /* GSM_1900 AMPM Master Table Segment2 at Freq. F2 */
   uint32                                           gsm_1900_ampm_master_tbl_seg2_f2[32];
   /* GSM_1900 AMPM Master Table Segment3 at Freq. F2 */
   uint32                                           gsm_1900_ampm_master_tbl_seg3_f2[32];
   /* GSM_1900 AMPM Master Table Segment4 at Freq. F2 */
   uint32                                           gsm_1900_ampm_master_tbl_seg4_f2[32];
   /* GSM_1900 AMPM Master Table Segment5 at Freq. F2 */
   uint32                                           gsm_1900_ampm_master_tbl_seg5_f2[32];
   /* GSM_1900 AMPM Master Table Segment6 at Freq. F2 */
   uint32                                           gsm_1900_ampm_master_tbl_seg6_f2[32];
   /* GSM_1900 AMPM Master Table Segment7 at Freq. F2 */
   uint32                                           gsm_1900_ampm_master_tbl_seg7_f2[32];
   /* GSM_1900 AMPM Master Table Segment8 at Freq. F2 */
   uint32                                           gsm_1900_ampm_master_tbl_seg8_f2[32];
   /* GSM_900 Calpath RSB_A value for Gain state 1 */
   int16                                            gsm_calpath_rsb_a_g1;
   /* GSM_900 Calpath RSB_B value for Gain state 1 */
   int16                                            gsm_calpath_rsb_b_g1;
   /* GSM_850 Calpath RSB_A value for Gain state 1 */
   int16                                            gsm_850_calpath_rsb_a_g1;
   /* GSM_850 Calpath RSB_B value for Gain state 1 */
   int16                                            gsm_850_calpath_rsb_b_g1;
   /* DCS_1800 Calpath RSB_A value for Gain state 1 */
   int16                                            dcs_calpath_rsb_a_g1;
   /* DCS_1800 Calpath RSB_B value for Gain state 1 */
   int16                                            dcs_calpath_rsb_b_g1;
   /* GSM_1900 Calpath RSB_A value for Gain state 1 */
   int16                                            gsm_1900_calpath_rsb_a_g1;
   /* GSM_1900 Calpath RSB_B value for Gain state 1 */
   int16                                            gsm_1900_calpath_rsb_b_g1;
   /* GSM_900 Calpath RSB_A value for Gain state 2 */
   int16                                            gsm_calpath_rsb_a_g2;
   /* GSM_900 Calpath RSB_B value for Gain state 2 */
   int16                                            gsm_calpath_rsb_b_g2;
   /* GSM_850 Calpath RSB_A value for Gain state 2 */
   int16                                            gsm_850_calpath_rsb_a_g2;
   /* GSM_850 Calpath RSB_B value for Gain state 2 */
   int16                                            gsm_850_calpath_rsb_b_g2;
   /* DCS_1800 Calpath RSB_A value for Gain state 2 */
   int16                                            dcs_calpath_rsb_a_g2;
   /* DCS_1800 Calpath RSB_B value for Gain state 2 */
   int16                                            dcs_calpath_rsb_b_g2;
   /* GSM_1900 Calpath RSB_A value for Gain state 2 */
   int16                                            gsm_1900_calpath_rsb_a_g2;
   /* GSM_1900 Calpath RSB_B value for Gain state 2 */
   int16                                            gsm_1900_calpath_rsb_b_g2;
   /* GSM_900 Gain in percent applied to AMAM table at low temp. */
   int16                                            gsm_amam_gain_low_temp;
   /* GSM_900 DC in percent applied to AMAM table at low temp. */
   int16                                            gsm_amam_dc_low_temp;
   /* GSM_900 Gain in percent applied to AMAM table at high temp. */
   int16                                            gsm_amam_gain_high_temp;
   /* GSM_900 DC in percent applied to AMAM table at high temp. */
   int16                                            gsm_amam_dc_high_temp;
   /* GSM_900 Gain in percent applied to AMAM table at nominal temp. */
   int16                                            gsm_amam_gain_nom_temp;
   /* GSM_900 DC in percent applied to AMAM table at nominal temp. */
   int16                                            gsm_amam_dc_nom_temp;
   /* GSM_850 Gain in percent applied to AMAM table at low temp. */
   int16                                            gsm_850_amam_gain_low_temp;
   /* GSM_850 DC in percent applied to AMAM table at low temp. */
   int16                                            gsm_850_amam_dc_low_temp;
   /* GSM_850 Gain in percent applied to AMAM table at high temp. */
   int16                                            gsm_850_amam_gain_high_temp;
   /* GSM_850 DC in percent applied to AMAM table at high temp. */
   int16                                            gsm_850_amam_dc_high_temp;
   /* GSM_850 Gain in percent applied to AMAM table at nominal temp. */
   int16                                            gsm_850_amam_gain_nom_temp;
   /* GSM_850 DC in percent applied to AMAM table at nominal temp. */
   int16                                            gsm_850_amam_dc_nom_temp;
   /* DCS_1800 Gain in percent applied to AMAM table at low temp. */
   int16                                            dcs_amam_gain_low_temp;
   /* DCS_1800 DC in percent applied to AMAM table at low temp. */
   int16                                            dcs_amam_dc_low_temp;
   /* DCS_1800 Gain in percent applied to AMAM table at high temp. */
   int16                                            dcs_amam_gain_high_temp;
   /* DCS_1800 DC in percent applied to AMAM table at high temp. */
   int16                                            dcs_amam_dc_high_temp;
   /* DCS_1800 Gain in percent applied to AMAM table at nominal temp. */
   int16                                            dcs_amam_gain_nom_temp;
   /* DCS_1800 DC in percent applied to AMAM table at nominal temp. */
   int16                                            dcs_amam_dc_nom_temp;
   /* GSM_1900 Gain in percent applied to AMAM table at low temp. */
   int16                                            gsm_1900_amam_gain_low_temp;
   /* GSM_1900 DC in percent applied to AMAM table at low temp. */
   int16                                            gsm_1900_amam_dc_low_temp;
   /* GSM_1900 Gain in percent applied to AMAM table at high temp. */
   int16                                            gsm_1900_amam_gain_high_temp;
   /* GSM_1900 DC in percent applied to AMAM table at high temp. */
   int16                                            gsm_1900_amam_dc_high_temp;
   /* GSM_1900 Gain in percent applied to AMAM table at nominal temp. */
   int16                                            gsm_1900_amam_gain_nom_temp;
   /* GSM_1900 DC in percent applied to AMAM table at nominal temp. */
   int16                                            gsm_1900_amam_dc_nom_temp;
   /* GSM_900 Reference ARFCN for AMAM and AMPM Calibration at F1  */
   uint16                                           gsm_amam_arfcn_f1;
   /* DCS Reference ARFCN for AMAM and AMPM Calibration at F1 */
   uint16                                           dcs_amam_arfcn_f1;
   /* GSM_850 Reference ARFCN for AMAM and AMPM Calibration at F1 */
   uint16                                           gsm_850_amam_arfcn_f1;
   /* GSM_1900 Reference ARFCN for AMAM and AMPM Calibration at F1 */
   uint16                                           gsm_1900_amam_arfcn_f1;
   /* GSM_900 Reference ARFCN for AMAM and AMPM Calibration at F2 */
   uint16                                           gsm_amam_arfcn_f2;
   /* DCS_1800 Reference ARFCN for AMAM and AMPM Calibration at F2 */
   uint16                                           dcs_amam_arfcn_f2;
   /* GSM_850 Reference ARFCN for AMAM and AMPM Calibration at F2 */
   uint16                                           gsm_850_amam_arfcn_f2;
   /* GSM_1900 Reference ARFCN for AMAM and AMPM Calibration at F2 */
   uint16                                           gsm_1900_amam_arfcn_f2;
   /* GSM_900 - Extenal measurement of DAC vs Pwr required for autocal */
   nv_autocal_pwr_dac_type                          gsm_autocal_pwr_dac_f1;
   /* GSM_900 - Dynamic range in dBm of AMAM table.  */
   nv_amam_dynamic_range                            gsm_amam_dynamic_range;
   /* DCS - External Measurement of DAC vs Power required for autocal */
   nv_autocal_pwr_dac_type                          dcs_autocal_pwr_dac_f1;
   /* DCS - Dynamic Range in dBm of AMAM Table.  */
   nv_amam_dynamic_range                            dcs_amam_dynamic_range;
   /* GSM_850 - External measurement of DAC vs Power required for autocal */
   nv_autocal_pwr_dac_type                          gsm_850_autocal_pwr_dac_f1;
   /* GSM_850 - Dynamic range in dBm of AMAM Table. */
   nv_amam_dynamic_range                            gsm_850_amam_dynamic_range;
   /* GSM_1900 - External Measurement of DAC vs Power required for autocal */
   nv_autocal_pwr_dac_type                          gsm_1900_autocal_pwr_dac_f1;
   /* GSM_1900 - Dynamic range in dBm of AMAM Table. */
   nv_amam_dynamic_range                            gsm_1900_amam_dynamic_range;
   /* GSM DC DC PDM table*/
   word											gsm_dc_dc_pdm_list[16];

   //OPLL cal items
   uint8                                           gsm_opll_bw_val;  //gsm 900 OPLL cal val
   uint8                                           dcs_opll_bw_val;  //dcs OPLL cal val
   uint8                                           gsm_850_opll_bw_val;  //gsm 850 OPLL cal val
   uint8                                           gsm_1900_opll_bw_val;  //gsm 1900 OPLL cal val

   //RTR6250 RSB Calibration
   /* GSM RTR6250 RSB */
   nv_rtr6250_rsb_type                              gsm_rtr6250_rsb;
   /* DCS RTR6250 RSB */
   nv_rtr6250_rsb_type                              dcs_rtr6250_rsb;
   /* GSM 850 RTR6250 RSB */
   nv_rtr6250_rsb_type                              gsm_850_rtr6250_rsb;
   /* GSM 1900 RTR6250 RSB */
   nv_rtr6250_rsb_type                              gsm_1900_rtr6250_rsb;

   byte											   intelliceiver_cal[14];
   nv_intelliceiver_im2_type						intelliceiver_im2;

   /* Channel number list for TX frequency compensation */
   int16                                            wcdma_tx_cal_chan[NV_FREQ_TABLE_SIZ];
   /* Channel number list for RX frequency compensation */
   int16                                            wcdma_rx_cal_chan[NV_FREQ_TABLE_SIZ];
   /* Channel number list for TX frequency compensation */
   int16                                            wcdma_1900_tx_cal_chan[NV_FREQ_TABLE_SIZ];
   /* Channel number list for RX frequency compensation */
   int16                                            wcdma_1900_rx_cal_chan[NV_FREQ_TABLE_SIZ];
   /* Channel number list for TX frequency compensation */
   int16                                            wcdma_800_tx_cal_chan[NV_FREQ_TABLE_SIZ];
   /* Channel number list for RX frequency compensation */
   int16                                            wcdma_800_rx_cal_chan[NV_FREQ_TABLE_SIZ];

   uint8											   trm_config;

   ///* Tx baseband gain fine tune value for linearizer 0. */
// int8                                             wcdma_tx_bb_gain_tune_lin0;
// /* Tx baseband gain fine tune value for linearizer 1. */
// int8                                             wcdma_tx_bb_gain_tune_lin1;
// /* Tx baseband gain fine tune value for linearizer 2. */
// int8                                             wcdma_tx_bb_gain_tune_lin2;
// /* Tx baseband gain fine tune value for linearizer 3. */
// int8                                             wcdma_tx_bb_gain_tune_lin3;



   /* Values for low, mid, and high channel IM2 DAC values for IM2. */
   nv_gsm_im2_type                                    gsm_im2;
   //nv_gsm_im2_type                                  gsm_im2_850;
   /* Values for low, mid, and high channel IM2 DAC values for IM2. */
//  nv_gsm_im2_type                                  gsm_im2_900;
   /* Values for low, mid, and high channel IM2 DAC values for IM2. */
//  nv_gsm_im2_type                                  gsm_im2_1800;
   /* Values for low, mid, and high channel IM2 DAC values for IM2. */
//  nv_gsm_im2_type                                  gsm_im2_1900;



   /*
   //yet to be defined
      //Tx baseband gain fine tune value for linearizer 0.
     int8                                             wcdma_800_tx_bb_gain_tune_lin0;
     //Tx baseband gain fine tune value for linearizer 1.
      int8                                             wcdma_800_tx_bb_gain_tune_lin1;
     //Tx baseband gain fine tune value for linearizer 2.
      int8                                             wcdma_800_tx_bb_gain_tune_lin2;
     //Tx baseband gain fine tune value for linearizer 3.
     int8                                             wcdma_800_tx_bb_gain_tune_lin3;


      //Tx baseband gain fine tune value for linearizer 0.
     int8                                             wcdma_1900_tx_bb_gain_tune_lin0;
     //Tx baseband gain fine tune value for linearizer 1.
      int8                                             wcdma_1900_tx_bb_gain_tune_lin1;
     //Tx baseband gain fine tune value for linearizer 2.
      int8                                             wcdma_1900_tx_bb_gain_tune_lin2;
     //Tx baseband gain fine tune value for linearizer 3.
     int8                                             wcdma_1900_tx_bb_gain_tune_lin3;
   */
//
//	// BC14 RF NV items
//	/* Tx Linearizer Table Gain State 0 */
//	nv_tx_linearizer_type							bc14_tx_lin_master0;
//	/* Tx Linearizer Table Gain State 1*/
//	nv_tx_linearizer_type							bc14_tx_lin_master1;
//	/* Tx Linearizer Table Gain State 2*/
//	nv_tx_linearizer_type							bc14_tx_lin_master2;
//	/* Tx Linearizer Table Gain State 3*/
//	nv_tx_linearizer_type							bc14_tx_lin_master3;
//
//	uint16						     				bc14_gps1_rf_delay;
//
//	uint8											bc14_tx_lim_vs_temp[8];
//	/* Tx Lin vs Freq Gain State 0 */
//	nv_tx_comp_type									bc14_tx_comp0;
//	/* Tx Lin vs Freq Gain State 1*/
//	nv_tx_comp_type									bc14_tx_comp1;
//	/* Tx Lin vs Freq Gain State 2*/
//	nv_tx_comp_type									bc14_tx_comp2;
//	/* Tx Lin vs Freq Gain State 3*/
//	nv_tx_comp_type									bc14_tx_comp3;
//	/* LIM VS FREQ*/
//	int8	bc14_tx_lim_vs_freq[16];
//	/* PA RISE FALL value (constant NV items)*/
//	uint8											bc14_pa_r1_rise;
//
//	uint8											bc14_pa_r1_fall;
//
//	uint8											bc14_pa_r2_rise;
//
//	uint8											bc14_pa_r2_fall;
//
//	uint8											bc14_pa_r3_rise;
//
//	uint8											bc14_pa_r3_fall;
//	/* HDET measurement (measured NV items)*/
//	uint8											bc14_hdet_off;
//
//	uint8											bc14_hdet_spn;
//
//	uint8											bc14_exp_hdet_vs_agc[16];
//
//	uint32											c1_bc14_lna_1_rise;
//
//	uint8											bc14_vco_coarse_tune_table[NV_VCO_COARSE_TUNE_TABLE_SIZ];
//
//	uint8											bc14_vco_tune_2[NV_VCO_COARSE_TUNE_TABLE_SIZ];
//
//	uint8											bc14_p1_rise_fall_off[8];
//
//	uint8											bc14_hdr_p1_rise_fall_off[16];
//	/* Calibration channel */
//	uint16											c0_bc14_tx_cal_chan[16];
//
//	uint16											c0_bc14_rx_cal_chan[16];
//
//	uint8											c0_bc14_rx_cal_chan_lru[NV_FREQ_TABLE_SIZ];
//	/* LNA offsets (measured NV items)*/
//	int16											c0_bc14_lna_1_offset;
//
//	int16											c0_bc14_lna_2_offset;
//
//	int16											c0_bc14_lna_3_offset;
//
//	int16											c0_bc14_lna_4_offset;
//
//	int8											c0_bc14_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//
//	int8											c0_bc14_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//
//	int8											c0_bc14_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//
//	int8											c0_bc14_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//	/* IM2 items (measured NV items)*/
//	uint8											c0_bc14_im2_i_value;
//
//	uint8											c0_bc14_im2_q_value;
//
//	int16											c0_bc14_vga_gain_offset;
//
//	int8											c0_bc14_vga_gain_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//
//	uint8											c0_bc14_im2_transconductor_value;
//	/* LNA rise/fall values (constant NV items)*/
//	int8											c0_bc14_lna_1_rise;
//
//	int8											c0_bc14_lna_1_fall;
//
//	int8											c0_bc14_lna_2_rise;
//
//	int8											c0_bc14_lna_2_fall;
//
//	int8											c0_bc14_lna_3_rise;
//
//	int8											c0_bc14_lna_3_fall;
//
//	int8											c0_bc14_lna_4_rise;
//
//	int8											c0_bc14_lna_4_fall;
//
//	uint8											c0_bc14_im_level1;
//
//	uint8											c0_bc14_im_level2;
//
//	uint8											c0_bc14_im_level3;
//
//	uint8											c0_bc14_im_level4;
//
//	uint16											c1_bc14_tx_cal_chan[16];
//
//	uint16											c1_bc14_rx_cal_chan[16];
//	/* diversity LNA vs FREQ (measured NV items)*/
//	int8											c1_bc14_lna_1_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//
//	int8											c1_bc14_lna_2_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//
//	int8											c1_bc14_lna_3_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//
//	int8											c1_bc14_lna_4_offset_vs_freq[NV_FREQ_TABLE_SIZ];
//	/* diversity, LNA offsets, (measured NV items)*/
//	int16											c1_bc14_lna_1_offset;
//
//	int16											c1_bc14_lna_2_offset;
//
//	int16											c1_bc14_lna_3_offset;
//
//	int16											c1_bc14_lna_4_offset;
//
//	uint8											c1_bc14_im2_i_value;
//
//	uint8											c1_bc14_im2_q_value;
//	/* diversity, VGA gain offset, (measured NV items)*/
///*
//	int16											c1_bc14_vga_gain_offset;
//
//	int8											c1_bc14_vga_gain_offset_vs_freq[16];
//
//	uint8											c1_bc14_im2_transconductor_value;
//*/
//	/* diversity, LNA rise/fall values (constant NV items)*/
///*
//	int8											c1_bc14_lna_1_rise;
//
//	int8											c1_bc14_lna_1_fall;
//
//	int8											c1_bc14_lna_2_rise;
//
//	int8											c1_bc14_lna_2_fall;
//
//	int8											c1_bc14_lna_3_rise;
//
//	int8											c1_bc14_lna_3_fall;
//
//	int8											c1_bc14_lna_4_rise;
//
//	int8											c1_bc14_lna_4_fall;
//
//	uint8											c1_bc14_im_level1;
//
//	uint8											c1_bc14_im_level2;
//
//	uint8											c1_bc14_im_level3;
//
//	uint8											c1_bc14_im_level4;
//*/
//	//uint8											c1_bc14_vco_coarse_tune_table[16];
//	/*	Relative	Atenna	"Quality,"	BC14	*/
//	//uint16											bc14_ant_quality[NV_MAX_ANT_NO_SIZ][NV_FREQ_TABLE_SIZ];
//
//	//uint16											bc14_pa_dvs_voltage;
//
//	//nv_rf_rx_agc_lpm_switchpoints					c0_bc14_lna_switchpoints_lpm_1;
//
//	//nv_rf_rx_agc_lpm_switchpoints					c0_bc14_lna_switchpoints_lpm_2;
//
//	//nv_rf_rx_im2_cal								c0_bc14_im2_lpm_1;
//
//	//nv_rf_rx_im2_cal								c0_bc14_im2_lpm_2;
//
//	//uint8											c0_bc14_intelliceiver_cal[NV_INTELLICEIVER_CAL_LENGTH];
//
//	//int8											c0_bc14_intelliceiver_det_thresh[NV_INTELLICEIVER_DETECTOR_COUNT][5];
//
//	//uint8											c1_bc14_rx_cal_chan_lru[NV_FREQ_TABLE_SIZ];

   /* CDMA TX linearizer PDM tables for beta scaling. */
   int16                                           cdma_tx_pdm_lin_beta_scaling_0[NV_TX_PDM_LIN_BETA_SCALING_SIZE];
   int16                                           cdma_tx_pdm_lin_beta_scaling_1[NV_TX_PDM_LIN_BETA_SCALING_SIZE];
   int16                                           cdma_tx_pdm_lin_beta_scaling_2[NV_TX_PDM_LIN_BETA_SCALING_SIZE];
   int16                                           cdma_tx_pdm_lin_beta_scaling_3[NV_TX_PDM_LIN_BETA_SCALING_SIZE];
};
#pragma component(mintypeinfo, off)
#pragma pack(pop)
