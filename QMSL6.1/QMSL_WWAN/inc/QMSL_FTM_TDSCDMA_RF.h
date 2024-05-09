/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_TDSCDMA_RF.h#5 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_TDSCDMA_RF
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_TDSCDMA_RF_H)
#define _QMSL_FTM_TDSCDMA_RF_H

#if !defined(_WINDOWS_)
#include "windows.h"
#endif

/**
   Establish whether the library is being compiled into a DLL (exporting),
   or being included from a client (importing)

   When the DLL is built, then QLIB_EXPORTS should be defined
*/
#ifdef QLIB_API
#undef QLIB_API
#endif

#ifdef QLIB_EXPORTS
#define QLIB_API __declspec(dllexport)
#else
#define QLIB_API __declspec(dllimport)
#endif

#if defined(QLIB_STATIC)
#undef QLIB_API
#define QLIB_API
//#define QLIB_API __cdecl
#endif


#ifdef __cplusplus
extern "C" {
#endif


   /******************************************************************************
                     TDSCDMA RF Commands
   *******************************************************************************/

   /******************************************************************************/
   /**
   TDSCDMA RF API, 80-NA917-1, FTM_TDSCDMA_SET_BURST_TX_PARAMS

   This API sets the parameters for burst mode TX
   The power level for all time slots will be the same.
   The Tx slots always start on Ts1. It is not possible to have non-contiguous UL slot configuration.
   The UpPTS is not transmitted

   UL PHY specific settings:
   -   Spreading Factor: 1
   -   Channelization Code: 1
   -   Scrambling code: 1
   -   Mid-amble code: 0
   -   Mid-amble shift: 112

   In the current implementation, all power enabled slots will be set to the same power level as power_level_ts1.  .

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param NumSlots = Number of uplink slots (Min: 1, Max: 5, 0xFF: Continuous UL )

   \param ModulationType = 0 -> QPSK
                           1 -> 16-QAM

   \param PowerTS1 = Indicates the power level for TS1 in 1/10dBm.

   \param PowerTS2 = Indicates the power level for TS2 in 1/10dBm.

   \param PowerTS3 = Indicates the power level for TS3 in 1/10dBm.

   \param PowerTS4 = Indicates the power level for TS4 in 1/10dBm.

   \param PowerTS5 = Indicates the power level for TS5 in 1/10dBm.

   \param iFTM_Error_Code = FTM Error code returned by FTM command
                            *   0  Success
                            *   1  Failure

   \return true if the commands were executed without a device communication failure.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
                     It will only be available in AMSS MSM8974 equivalents according to the
                     Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_SET_BURST_TX_PARAMS(HANDLE hResourceContext,
         unsigned char iNumSlots,
         unsigned char iModulationType,
         short iPowerTS1,
         short iPowerTS2,
         short iPowerTS3,
         short iPowerTS4,
         short iPowerTS5,
         unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
   TDSCDMA RF API, 80-NA917-1, FTM_TDSCDMA_BURST_TX

   Turn ON/OFF the TX in burst mode. The TX parameters are configured by sending the
   FTM_TDSCDMA_SET_BURST_TX_PARAMS command.
   Bursted Tx operation cannot be enabled while bursted Rx operation is enabled.
   If bursted Rx operation is enabled, then it will be automatically disabled.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iEnable =  0 > Turn OFF TX
                     1 > Turn ON TX

   \param iFTM_Error_Code = FTM Error code returned by FTM command
                            *   0  Success
                            *   1  Failure

   \return true if the commands were executed without a device communication failure.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
                     It will only be available in AMSS MSM8974 equivalents according to the
                     Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BURST_TX(HANDLE hResourceContext,
         unsigned char iEnable,
         unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
   TDSCDMA RF API, 80-NA917-1, FTM_TDSCDMA_BURST_RX

   Turn ON/OFF the RX in burst mode. Currently, only single slot RX is supported.
   The command set a specific LNA state based on an expected power level.
   Bursted Rx operation cannot be enabled while bursted Tx operation is enabled.
   If bursted Tx operation is enabled, then it will be automatically disabled.
   To receive power level reports use FTM_GET_RX_LEVEL_DBM command.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iExpectedDLLevel = Expected DL Level in dbm10 units

   \param iEnable =  0 > Turn OFF RX
                     1 > Turn ON RX

   \param iFTM_Error_Code = FTM Error code returned by FTM command
                            *   0  Success
                            *   1  Failure

   \return true if the commands were executed without a device communication failure.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
                     It will only be available in AMSS MSM8974 equivalents according to the
                     Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BURST_RX(HANDLE hResourceContext,
         unsigned short iExpectedDLLevel,
         unsigned char iEnable,
         unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
   TDSCDMA RF API, 80-NA917-1, FTM_TDSCDMA_IQ_LOGGING

   This command captures the IQ data in Burst mode. Currently, only single-slot capture in FTM
   RF mode is supported in TDSCDMA.
   The overall level procedure for IQ capture is
   *   UE enters FTM RF mode
   *   Rx is configured
   *   Single-slot IQ capture cmd is issued and IQ data is captured to IQ data buffer
   The IQ data buffer will not be changed until next IQ data capture.
   If RxD path IQ data needs to be captured, RxD path Rx must be configured first.
   This command is valid only when the UE is in the FTM RF state and related path Rx on which IQ data needs to be captured is configured.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iAntennaPort =  * 0 = Rx0
                          * 1 = Rx1
                          * 2 = Rx0 + Rx1 (Currently Rx0 + Rx1 is not supported)

   \param iFTM_Error_Code = FTM Error code returned by FTM command
                            *   0  Success
                            *   1  Failure

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_IQ_LOGGING (HANDLE hResourceContext,
         short iAntennaPort,
         unsigned short* iFTM_Error_Code);



#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_TDSCDMA_RF_H)
