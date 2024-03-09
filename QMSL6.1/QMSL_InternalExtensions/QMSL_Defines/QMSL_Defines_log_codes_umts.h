/******************************************************************************/
/**
Program: QMSL

	$Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief
	UMTS Log code definitions from log_codes_umts.h of AMSS
 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/
#pragma once


#include "QMSL_Defines_log_codes.h" // for LOG_UMTS_BASE_C

#define LOG_UMTS_CALL_FLOW_ANALYSIS_C               (0x01  + LOG_UMTS_BASE_C)

/* ========================   MMGPS PACKETS   ============================ */
#define LOG_UMTS_MMGPS_REP_CLK_LOG_PACKET_C         (0x02  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_POS_LOG_PACKET_C         (0x03  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_MEAS_LOG_PACKET_C        (0x05  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_RESERVED0_LOG_PACKET_C   (0x07  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_RF_STATUS_LOG_PACKET_C   (0x08  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_FREQ_CALIBRATION_LOG_PACKET_C \
                                                    (0x09  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_SVR_TX_LOG_PACKET_C      (0x0A  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_SVR_RX_LOG_PACKET_C      (0x0B  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_SV_MEAS_LOG_PACKET_C     (0x0C  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_DWELL_LOG_PACKET_C       (0x0D  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_TIME_TAG_LOG_PACKET_C    (0x0E  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_RESERVED1_LOG_PACKET_C   (0x0F  + LOG_UMTS_BASE_C)

#define LOG_UMTS_MMGPS_REP_GPS_INTFC_TX_LOG_PACKET_C (0x10  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_GPS_INTFC_RX_LOG_PACKET_C (0x11  + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_EVT_LOG_PACKET_C          (0x12  + LOG_UMTS_BASE_C)

#define LOG_UMTS_PDSM_GET_POSITION_C                 (0x13 + LOG_UMTS_BASE_C)
#define LOG_UMTS_PDSM_SET_PARAMETERS_C               (0x14 + LOG_UMTS_BASE_C)
#define LOG_UMTS_PDSM_END_SESSION_C                  (0x15 + LOG_UMTS_BASE_C)
#define LOG_UMTS_PDSM_NOTIFY_VERIFY_RESP_C           (0x16 + LOG_UMTS_BASE_C)

#define LOG_UMTS_PDSM_POSITION_REPORT_CALLBACK_C     (0x17 + LOG_UMTS_BASE_C)
#define LOG_UMTS_PDSM_PD_EVENT_CALLBACK_C            (0x18 + LOG_UMTS_BASE_C)
#define LOG_UMTS_PDSM_PA_EVENT_CALLBACK_C            (0x19 + LOG_UMTS_BASE_C)
#define LOG_UMTS_PDSM_NOTIFY_VERIFY_REQUEST_C        (0x1A + LOG_UMTS_BASE_C)
#define LOG_UMTS_PDSM_PD_CMD_ERR_CALLBACK_C          (0x1B + LOG_UMTS_BASE_C)
#define LOG_UMTS_PDSM_PA_CMD_ERR_CALLBACK_C          (0x1C + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_UNC_ELLIPSE_LOG_PACKET_C  (0x1D + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_POS_TYPE2_LOG_PACKET_C    (0x1E + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_REP_MEAS_TYPE3_LOG_PACKET_C   (0x1F + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_20                   (0x20 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_21                   (0x21 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_22                   (0x22 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_23                   (0x23 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_24                   (0x24 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_25                   (0x25 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_26                   (0x26 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_27                   (0x27 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_28                   (0x28 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_29                   (0x29 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_2A                   (0x2A + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_2B                   (0x2B + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_2C                   (0x2C + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_2D                   (0x2D + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_2E                   (0x2E + LOG_UMTS_BASE_C)
#define LOG_UMTS_MMGPS_RESERVED_2F                   (0x2F + LOG_UMTS_BASE_C)

/* ========================   NAS LAYER PACKETS   ======================== */
#define LOG_UMTS_NAS_GMM_STATE_LOG_PACKET_C         (0x130 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_MM_STATE_LOG_PACKET_C          (0x131 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_REG_LOG_PACKET_C               (0x132 + LOG_UMTS_BASE_C)
#define LOG_UMTS_CS_CALL_SETUP_INFO_LOG_PACKET_C    (0x133 + LOG_UMTS_BASE_C)
#define LOG_UMTS_PS_CALL_INFO_LOG_PACKET_C          (0x134 + LOG_UMTS_BASE_C)
#define LOG_UMTS_MM_INFO_LOG_PACKET_C               (0x135 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_PS_CONNECTION_QOS_LOG_PACKET_C (0x136 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_CS_CONNECTION_BC_LOG_PACKET_C  (0x137 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_UE_DYNAMIC_ID_LOG_PACKET_C     (0x138 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_UE_STATIC_ID_LOG_PACKET_C      (0x139 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_OTA_MESSAGE_LOG_PACKET_C       (0x13A + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_CFA_MESSAGE_LOG_PACKET_C       (0x13B + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_ERROR_MESSAGE_LOG_PACKET_C     (0x13C + LOG_UMTS_BASE_C)
#define LOG_UMTS_CS_CALL_RELEASE_INFO_LOG_PACKET_C  (0x13D + LOG_UMTS_BASE_C)
#define LOG_UMTS_CS_CALL_CHANGE_INFO_LOG_PACKET_C   (0x13E + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_EPLMN_LIST_LOG_PACKET_C        (0x150 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_FPLMN_LIST_UPDATE_LOG_PACKET_C (0x151 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_FPLMN_LIST_LOG_PACKET_C        (0x152 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_HPLMN_SEARCH_TIMER_START_LOG_PACKET_C  (0x153 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_HPLMN_SEARCH_TIMER_EXPIRE_LOG_PACKET_C (0x154 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_HPLMN_SEARCH_START_LOG_PACKET_C (0x155 + LOG_UMTS_BASE_C)
#define LOG_UMTS_NAS_HPLMN_SEARCH_END_LOG_PACKET_C   (0x156 + LOG_UMTS_BASE_C)

/* ========================      AMR PACKETS     ========================= */
#define LOG_UMTS_TX_VOCODER_PACKET_C                (0x13F + LOG_UMTS_BASE_C)
#define LOG_UMTS_RX_VOCODER_PACKET_C                (0x140 + LOG_UMTS_BASE_C)
#define LOG_UMTS_TX_VOCODER_PACKET_DSP_C            (0x143 + LOG_UMTS_BASE_C)
#define LOG_UMTS_RX_VOCODER_PACKET_DSP_C            (0x144 + LOG_UMTS_BASE_C)

/* ========================   CS DATA PACKETS   ========================== */
#define LOG_UMTS_CS_DATA_RX_C                       (0x141 + LOG_UMTS_BASE_C)
#define LOG_UMTS_CS_DATA_TX_C                       (0x142 + LOG_UMTS_BASE_C)

/* ========================  CFA FILTER PACKETS  ========================= */
#define LOG_UMTS_CFA_FIRST_FILTER_C                 (0x200 + LOG_UMTS_BASE_C)
#define LOG_UMTS_CFA_LAST_FILTER_C                  (0x2FF + LOG_UMTS_BASE_C)

/* ========================  CM LOG PACKETS  ========================= */
#define LOG_UMTS_RESPONSE_NOTIFY                    (0x401 + LOG_UMTS_BASE_C)
#define LOG_UMTS_USS_DATA_CONF                      (0x402 + LOG_UMTS_BASE_C)
#define LOG_UMTS_USS_FWD_AOC                        (0x403 + LOG_UMTS_BASE_C)
#define LOG_GET_CALL_INFO                           (0x404 + LOG_UMTS_BASE_C)
#define LOG_LCS_MOLR_CONF_INFO                      (0x405 + LOG_UMTS_BASE_C)

/* The last defined UMTS log code */
#define LOG_UMTS_LAST_C                             (0x4FF + LOG_UMTS_BASE_C)