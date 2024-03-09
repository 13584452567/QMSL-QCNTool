/******************************************************************************/
/**
Program: QMSL

	$Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief
	Log code definitions

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/

#pragma once
//$Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Defines/QMSL_Defines_log_codes_wcdma.h#4 $
// this file should hold items from log_codes_wcdma.h of AMSS

#include "QMSL_Defines_log_codes.h" // for LOG_WCDMA_BASE_C

#define LOG_WCDMA_L1_POWER_CONTROL_WITH_CM_C         (0x001 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_100_C                     (0x100 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_101_C                     (0x101 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_102_C                     (0x102 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_103_C                     (0x103 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_104_C                     (0x104 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_AGC_C                              (0x105 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RACH_PARAMETERS_C                  (0x106 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DRX_MODE_C                         (0x004 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_TRANSPORT_DL_C                     (0x108 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_TRANSPORT_UL_C                     (0x109 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_COMMON_CHANNEL_DL_C                (0x10A + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DEDICATED_CHANNEL_DL_C             (0x10B + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_PHYSICAL_CHANNEL_UL_C              (0x10C + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_PRACH_C                            (0x10D + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RM_UL_C                            (0x10E + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_10F_C                     (0x10F + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_ACTIVE_SET_C                       (0x110 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_NEIGHBOR_SET_C                     (0x111 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DL_TRANSPORT_DEBUGING_C            (0x112 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_CRC_C                              (0x113 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_114_C                     (0x114 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DL_FORMAT_COMB_C                   (0x115 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_BLER_C                             (0x116 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_FINGER_TA_INFO_C                   (0x147 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_148_C                     (0x148 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_STEP_1_SEARCH_C                    (0x14C + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_STEP_2_SEARCH_C                    (0x14D + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_STEP_3_SEARCH_C                    (0x14E + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_LIST_SEARCH_C                      (0x14F + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_UL_DL_POWER_CONTROL_C              (0x150 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_L1_CIPHERING_C                     (0x153 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_L1_COMPACT_CRC_C                   (0x760 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_L1_TFCI_C                          (0x770 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_L1_CM_BLER_C                       (0x775 + LOG_WCDMA_BASE_C)

/* ========================   LAYER 2 PACKETS   ======================== */
#define LOG_WCDMA_UL_MAC_PARAMS_C                    (0x117 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_UL_MAC_TRAFFIC_VOL_MEAS_RPT_C      (0x002 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_118_C                     (0x118 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RLC_UL_STATES_C                    (0x119 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RLC_UL_TM_C                        (0x11A + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RLC_UL_UM_C                        (0x11B + LOG_WCDMA_BASE_C)

#define LOG_WCDMA_DL_MAC_PARAMS_C                    (0x11D + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_11E_C                     (0x11E + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RLC_DL_STATES_C                    (0x11F + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RLC_DL_TM_C                        (0x120 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RLC_DL_UM_C                        (0x121 + LOG_WCDMA_BASE_C)

#define LOG_WCDMA_RACH_CONTROL_PARAMS_C              (0x123 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_UL_FORMAT_COMB_C                   (0x124 + LOG_WCDMA_BASE_C)

#define LOG_WCDMA_RLC_V1_DL_AM_C                     (0x132 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RLC_V1_UL_AM_C                     (0x133 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DL_RLC_AM_USR_PLANE_PDU            (0x134 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DL_RLC_AM_SIG_PLANE_PDU            (0x135 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_UL_AM_STATISTIC_V1                 (0x139 + LOG_WCDMA_BASE_C)

#define LOG_WCDMA_UL_RLC_AM_USR_PLANE_PDU            (0x13B + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_UL_RLC_AM_SIG_PLANE_PDU            (0x13C + LOG_WCDMA_BASE_C)

#define LOG_WCDMA_UL_NAK_AM_PDU                      (0x145 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DL_NAK_AM_PDU                      (0x146 + LOG_WCDMA_BASE_C)

#define LOG_WCDMA_DL_AM_STATISTIC                    (0x14A + LOG_WCDMA_BASE_C)

#define LOG_WCDMA_RLC_V1_UL_CIPHERING_C              (0x161 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RLC_V1_DL_CIPHERING_C              (0x162 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DL_RLC_V1_PDU_CIPHERING_LOG        (0x168 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_UL_RLC_V1_PDU_CIPHERING_LOG        (0x169 + LOG_WCDMA_BASE_C)


/* ========================   LAYER 3 PACKETS   ======================== */
#define LOG_WCDMA_RRC_STATES_C                       (0x125 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RRC_PROTOCOL_ERRORS_C              (0x126 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_CELL_ID_C                          (0x127 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_UL_CHANNEL_MAPPING_C               (0x128 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_DL_CHANNEL_MAPPING_C               (0x129 + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_RESERVED_12A_C                     (0x12A + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_SIB_C                              (0x12B + LOG_WCDMA_BASE_C)
#define LOG_WCDMA_SIGNALING_MSG_C                    (0x12F + LOG_WCDMA_BASE_C)

/* ========================     NAS PACKETS    ========================= */
/* ========================     AMR PACKETS    ========================= */
/* These codes are defined in log_codes_umts.h */

#ifdef FEATURE_QVPHONE

#define LOG_H324_DL_223_PDU                          (0x900 + LOG_WCDMA_BASE_C) /* 0x4900 H324 Downlink 223 MUX PDU */
#define LOG_H324_DL_AUD_SDU                          (0x901 + LOG_WCDMA_BASE_C) /* 0x4901 H324 Downlink Audio SDU */
#define LOG_H324_DL_VID_SDU                          (0x902 + LOG_WCDMA_BASE_C) /* 0x4902 H324 Downlink Video SDU*/
#define LOG_H324_DL_SIG_SDU                          (0x903 + LOG_WCDMA_BASE_C) /* 0x4903 H324 Downlink 245 SDU */
#define LOG_H324_UL_223_PDU                          (0x904 + LOG_WCDMA_BASE_C) /* 0x4904 H324 Uplink 223 MUX PDU */
#define LOG_H324_UL_AUD_SDU                          (0x905 + LOG_WCDMA_BASE_C) /* 0x4905 H324 Uplink Audio SDU */
#define LOG_H324_UL_VID_SDU                          (0x906 + LOG_WCDMA_BASE_C) /* 0x4906 H324 Uplink Video SDU */
#define LOG_H324_UL_SIG_SDU                          (0x907 + LOG_WCDMA_BASE_C) /* 0x4907 H324 Uplink Video SDU */
#define LOG_H324_UL_LL_SIG                           (0x908 + LOG_WCDMA_BASE_C) /* 0x4908 H324 Uplink Adaptation Layer */
#define LOG_H324_DL_LL_SIG                           (0x909 + LOG_WCDMA_BASE_C) /* 0x4909 H324 Downlink Adaptation Layer */
#define LOG_H324_VID_STAT                            (0x90A + LOG_WCDMA_BASE_C) /* 0x490A H324 Video Statistics */
#define LOG_H324_VID_ENCODER                         (0x90B + LOG_WCDMA_BASE_C) /* 0x490B H324 Video ENCODER */
#define LOG_H324_VID_DECODER                         (0x90C + LOG_WCDMA_BASE_C) /* 0x490C H324 Video DECODER */
#define LOG_H324_UL_AUD_TS                           (0x90D + LOG_WCDMA_BASE_C) /* 0x490D H324 Uplink Audio Time Stamp and Seq. Number */
#define LOG_H324_DL_AUD_TS                           (0x90E + LOG_WCDMA_BASE_C) /* 0x490E H324 Downlink Audio Time Stamp and Seq. Number */
#define LOG_H324_UL_VID_TS                           (0x90F + LOG_WCDMA_BASE_C) /* 0x490F H324 Uplink Video Time Stamp and Seq. Number */
#define LOG_H324_DL_VID_TS                           (0x910 + LOG_WCDMA_BASE_C) /* 0x4910 H324 Downlink Video Time Stamp and Seq. Number */

/* The last defined WCDMA log code */
#define LOG_WCDMA_LAST_C                             (0x910 + LOG_WCDMA_BASE_C)

#else

/* The last defined WCDMA log code */
#define LOG_WCDMA_LAST_C                             (0x775 + LOG_WCDMA_BASE_C)

#endif /* FEATURE_QVP_LOGGING */

