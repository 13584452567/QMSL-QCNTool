/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_EVDO_NS.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_EVDO_NS
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_EVDO_NS_H)
#define _QMSL_FTM_EVDO_NS_H

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
                     EVDO Non-signaling FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   Enables logging for the EVDO non-signaling commands.  If this is not done, then
   the EVDO NS commands will act only as simple request/response types.

   After this function is called, the commands will for assocated events
   to occur, before they returning to the library client.

   In addition, after this function is called, then the library will begin collecting C/I statistics

   The log used to determine searcher state is: 0x108A, FTM_EVDO_NS_LOG_CODE_FINGER_INFO

   The logs used for AGC are FTM logs:
   \code
      LOG_FTM2_LOG_HDR_AGC      = 0x5
      LOG_FTM2_LOG_HDR_AGC_C1 = 0x7
   \endcode

   When this function is called, only log 0x108A, FTM_EVDO_NS_LOG_CODE_FINGER_INFO will
   be enabled.  At the same time, the FTM AGC logs will be >>DISABLED<<

   The user must call QLIB_FTM_EVDO_NS_EnableMeasurementLogs() in order to activate
   0x1068, FTM_EVDO_NS_LOG_CODE_AIR_LINK_SUMMARY and the FTM AGC logs and measure
   AGC and PER.  This is because the MSM6800 design is such that there will be
   problems if the FTM AGC log is enabled when the pilot acquisition is perfomed. This
   is by-design, so the PC side must be managed around this.

   The function FTM_EVDO_NS_Stop should be called when the the EVDO NS testing
   is completed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iDR_Type = Dymamic range type, defined by FTM_EVDO_NS_DR_Types_Enum in QLib_Defines.h
      \code
          0 = FTM_EVDO_NS_DR_85_3  = 85.3dB  dynamic range, min_rssi = -106.0dBm
          1 = FTM_EVDO_NS_DR_102_4 = 102.4dB dynamic range, min_rssi = -115.0dBm
      \endcode
   \param dTurnAroundConstant = cdma turn around constant, -73dBm for BC0, -76 for BC1.
   \return true if successful, false if fail.

   \warning Will clear status and enable EVDO NS statistics for FTM_EVDO_NS_Log_FingerInfo, via
            FTM_EVDO_NS_SetStatisticsState().  Will also clear the EVDO NS status
          using QLIB_FTM_EVDO_NS_ClearStatus()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_Start( HANDLE hResourceContext,  unsigned char iDR_Type, double dTurnAroundConstant  );


   /******************************************************************************/
   /**
   Enables logging for the EVDO non-signaling commands.  If this is not done, then
   the EVDO NS commands will act only as simple request/response types.

   After this function is called, the commands will for assocated events
   to occur, before they returning to the library client.

   In addition, after this function is called, then the library will begin collecting C/I statistics

   This function is a variant from QLIB_FTM_EVDO_NS_Start() -- the difference is that this function
   does not clear the EVDO NS status and it does not stop the FTM AGC logs.

   The log used to determine searcher state is: 0x108A, FTM_EVDO_NS_LOG_CODE_FINGER_INFO

   The logs used for AGC are FTM logs:
   \code
      LOG_FTM2_LOG_HDR_AGC      = 0x5
      LOG_FTM2_LOG_HDR_AGC_C1 = 0x7
   \endcode

   When this function is called, only log 0x108A, FTM_EVDO_NS_LOG_CODE_FINGER_INFO will
   be enabled.

   The user must call QLIB_FTM_EVDO_NS_EnableMeasurementLogs() in order to activate
   0x1068, FTM_EVDO_NS_LOG_CODE_AIR_LINK_SUMMARY and the FTM AGC logs and measure
   AGC and PER.  This is because the MSM6800 design is such that there will be
   problems if the FTM AGC log is enabled when the pilot acquisition is perfomed. This
   is by-design, so the PC side must be managed around this.

   The function FTM_EVDO_NS_Stop should be called when the the EVDO NS testing
   is completed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iDR_Type = Dymamic range type, defined by FTM_EVDO_NS_DR_Types_Enum in QLib_Defines.h
      \code
          0 = FTM_EVDO_NS_DR_85_3  = 85.3dB  dynamic range, min_rssi = -106.0dBm
          1 = FTM_EVDO_NS_DR_102_4 = 102.4dB dynamic range, min_rssi = -115.0dBm
      \endcode
   \param dTurnAroundConstant = cdma turn around constant, -73dBm for BC0, -76 for BC1.
   \return true if successful, false if fail.

   \warning Will enable EVDO NS statistics for FTM_EVDO_NS_Log_FingerInfo, via
            FTM_EVDO_NS_SetStatisticsState().  Will NOT clear the EVDO NS status
          using QLIB_FTM_EVDO_NS_ClearStatus()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_Start_NO_CLEAR( HANDLE hResourceContext,  unsigned char iDR_Type, double dTurnAroundConstant  );


   /******************************************************************************/
   /**
   Enables measurement logs for the EVDO non-signaling commands.  If this is not done,
   then it will not be possible to report PER and AGC from the QMSL functions.

   This function should be called after a successful transfer to traffic state when
   QLIB_FTM_EVDO_DEMOD_CC_MAC_FTC(), or
   QLIB_FTM_EVDO_MOD_REVERSE_TRA for Release 0, or
   QLIB_FTM_EVDO_REV_A_MOD_TRA for Revision A, or
   QLIB_FTM_EVDO_REV_B_MOD_RTC for Revision B is called.

   After this function is called, then the library will begin collecting
   statistics (PER, C/I, AGC, Rev.0/A Forward Statistics, Power, etc, depending on the mask)

   The logs used to determine PER is: 0x1068, FTM_EVDO_NS_LOG_CODE_AIR_LINK_SUMMARY

   The logs used for AGC are FTM logs:
   \code
          LOG_FTM2_LOG_HDR_AGC    = 0x5
         LOG_FTM2_LOG_HDR_AGC_C1 = 0x7
   \endcode
   \note Only 1 chain of AGC log should be enabled at a time.

   The logs used for forward and reverse links Power:  EVDO_POWER   0x1069

   The logs used for HDR release 0 throughput: EVDO_FORWARD_LINK_STATISTICS_SUMMARY 0x1084

   The logs used for HDR revision A throughput: EVDO_REVA_SU_FWDSTATS 0x1192

   The function QLIB_FTM_EVDO_NS_Stop should be called when the the EVDO NS testing is completed.

   The function QLIB_FTM_EVDO_NS_DisableMeasurementLogs can be used to disable
      any logs that were enabled by this function during testing.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iLogMask = Log mask, defined by FTM_EVDO_NS_MeasurementLogs_Enum.

      The mask values are as follows:
      \code
      FTM_EVDO_NS_LOG_AIR_LINK_SUMMARY = 0x0001,   //!<'  Air link summary 0x1068
      FTM_EVDO_NS_LOG_AGC_C0          = 0x0002,   //!<'  FTM AGC Log for primary Rx (C0)
      FTM_EVDO_NS_LOG_AGC_C1          = 0x0004,   //!<'  FTM AGC Log for secondary Rx (C1)
      FTM_EVDO_NS_LOG_Default        = 0x0003,   //!<'  Default is to include logs air link summary and AGC Primary Chain FTM logs.
      FTM_EVDO_NS_LOG_POWER          = 0x0008,   //!<'  Power Logs 0x1069
      FTM_EVDO_NS_LOG_FWD_STAT       = 0x0010,   //!<'  Forward statistics summary 0x1084
      FTM_EVDO_NS_LOG_REVA_SU_FWD_STAT = 0x0020,   //!<'  Rev. A Single User forward statistics summary 0x1192
      FTM_EVDO_NS_LOG_MC_AIR_LINK     = 0x0040,   //!<'  Rel. B Multi-carrier airlink summary 0x1296
      FTM_EVDO_NS_LOG_MC_SU_FWD_STAT    = 0x0080,   //!<'  Rev. B Multi-carrier Single User forward statistics summary 0x12A2
      FTM_EVDO_NS_LOG_MC_POWER       = 0x0100,   //!<'  Rev. B Multi-carrier Power 0x129C
      FTM_EVDO_NS_LOG_ALL           = 0xFFFB   //!<'  All log codes available for EVDO(excluding Secondary chain FTM AGC log)
      \endcode

      The default mask is FTM_EVDO_NS_LOG_Default, which includes logs for Airlink summary and AGC primary chain FTM logs.

   \return true if successful, false if fail.

   \warning    Only 1 chain of AGC log should be enabled at a time.
         This function will enable EVDO NS statistics based on the mask, via FTM_EVDO_NS_SetStatisticsState().

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_EnableMeasurementLogs( HANDLE hResourceContext,  unsigned short iLogMask );

   /******************************************************************************/
   /**
   Disables measurement logs for the EVDO non-signaling commands.

   After this function is called, then the library will stop collecting
   statistics (PER, C/I, AGC, Rev.0/A Forward Statistics, Power, etc, depending on the mask)

   The logs used to determine PER is: 0x1068, FTM_EVDO_NS_LOG_CODE_AIR_LINK_SUMMARY

   The logs used for AGC are FTM logs:
   \code
          LOG_FTM2_LOG_HDR_AGC    = 0x5
         LOG_FTM2_LOG_HDR_AGC_C1 = 0x7
   \endcode

   The logs used for forward and reverse links Power:  EVDO_POWER   0x1069

   The logs used for HDR release 0 throughput: EVDO_FORWARD_LINK_STATISTICS_SUMMARY 0x1084

   The logs used for HDR revision A throughput: EVDO_REVA_SU_FWDSTATS 0x1192

   The function QLIB_FTM_EVDO_NS_Stop should be called when the the EVDO NS testing is completed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iLogMask = Log mask, defined by FTM_EVDO_NS_MeasurementLogs_Enum.

      The mask values are as follows:
      \code
      FTM_EVDO_NS_LOG_AIR_LINK_SUMMARY = 0x0001,   //!<'  Air link summary 0x1068
      FTM_EVDO_NS_LOG_AGC_C0          = 0x0002,   //!<'  FTM AGC Log for primary Rx (C0)
      FTM_EVDO_NS_LOG_AGC_C1          = 0x0004,   //!<'  FTM AGC Log for secondary Rx (C1)
      FTM_EVDO_NS_LOG_Default        = 0x0003,   //!<'  Default is to include logs air link summary and AGC Primary Chain FTM logs.
      FTM_EVDO_NS_LOG_POWER          = 0x0008,   //!<'  Power Logs 0x1069
      FTM_EVDO_NS_LOG_FWD_STAT       = 0x0010,   //!<'  Forward statistics summary 0x1084
      FTM_EVDO_NS_LOG_REVA_SU_FWD_STAT = 0x0020,   //!<'  Rev. A Single User forward statistics summary 0x1192
      FTM_EVDO_NS_LOG_MC_AIR_LINK     = 0x0040,   //!<'  Rel. B Multi-carrier airlink summary 0x1296
      FTM_EVDO_NS_LOG_MC_SU_FWD_STAT    = 0x0080,   //!<'  Rev. B Multi-carrier Single User forward statistics summary 0x12A2
      FTM_EVDO_NS_LOG_MC_POWER       = 0x0100,   //!<'  Rev. B Multi-carrier Power 0x129C
      FTM_EVDO_NS_LOG_ALL           = 0xFFFB   //!<'  All log codes available for EVDO(excluding Secondary chain FTM AGC log)
      \endcode

      The default mask is FTM_EVDO_NS_LOG_Default, which includes logs for airlink summary and AGC primary chain FTM logs.

   \return true if successful, false if fail.

   \warning This function will disable EVDO NS statistics based on the mask, via FTM_EVDO_NS_SetStatisticsState().
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_DisableMeasurementLogs( HANDLE hResourceContext,  unsigned short iLogMask );


   /******************************************************************************/
   /**
   Disables logging for the EVDO non-signaling commands.  This should be done
   after FTM_EVDO_NS_StartLogging() is called, and after all EVDO NS testing is
   completed.

   This functin calls
      QLIB_FTM_LOG_StopFTM_Log( HANDLE, LOG_FTM2_LOG_HDR_AGC ) to stop primary AGC logs
      QLIB_FTM_LOG_StopFTM_Log( HANDLE, LOG_FTM2_LOG_HDR_AGC_C1 ) to stop diveristy AGC logs
      QLIB_DIAG_ClearExtendedLogCode( HANDLE, LOG_EQUIP_ID_1X, FTM_EVDO_NS_LOG_CODE_FINGER_INFO) to stop FINGER_INFO logs

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning The FTM AGC logs will be disabled.
      The log code enabled by QLIB_EVDO_NS_Start will also be disabled (FTM_EVDO_NS_LOG_CODE_FINGER_INFO 0x108A).
      The log codes enabled by QLIB_FTM_EVDO_NS_EnableMeasurementLogs will NOT be disabled.
      Use QLIB_FTM_EVDO_NS_DisableMeasurementLogs to clear any other log used during EVDO NS testing.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_Stop( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   Turn on or off logging for a certain type of 1xEV-DO non-signaling log

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eLogType = log type to control
      \code
         FTM_EVDO_NS_Log_FingerInfo,            //!<' 1xEV-DO Finger, Ver 2 (LOG_CODE 0x108A), C/I for both C0 and C1
         FTM_EVDO_NS_Log_AGC_C0,             //!<' FTM2 log, sub log 5, for Primary AGC
         FTM_EVDO_NS_Log_AGC_C1,             //!<' FTM2 log, sub log 7, for Diversity AGC
         FTM_EVDO_NS_Log_PER,               //!<' 1xEV-DO Air Link Summary (LOG_CODE 0x1068), used for PER
         FTM_EVDO_NS_Log_FWD_Stat_Summary,      //!<' 1xEV-DO Forward Statistis Summary (LOG_CODE 0x1084), used for Release 0 Throughput
         FTM_EVDO_NS_Log_Power_Summary,         //!<' 1xEV-DO Power logs (LOG_CODE 0x1069), used for EVDO Power.
         FTM_EVDO_NS_Log_RevA_SU_FWD_Stat_Summary,   //!<' 1xEV-DO Rev. A Single User Forward Statistis Summary (LOG_CODE 0x1192), used for Revision A Throughput
         FTM_EVDO_NS_Log_MC_Airlink_Summary,    //!<' 1xEV-DO Multi-carrier Airlink Summary (LOG_CODE 0x1296)
         FTM_EVDO_NS_Log_MC_SU_FWD_Stat_Summary,    //!<' 1xEV-DO Multi-carrier single user Forward Statistis Summary (LOG_CODE 0x12A2)
         FTM_EVDO_NS_Log_MC_Power_Summary,      //!<' 1xEV-DO Multi-carrier Power (LOG_CODE 0x129C)
      \endcode
   \param bEnableStatistics = true to enable statistics of the specified log type

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_SetStatisticsState( HANDLE hResourceContext, unsigned char eLogType, unsigned char bEnableStatistics);


   /******************************************************************************/
   /**
   1XEV-DO Non-signaling,

      Reset the internal status structure, including all averages

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if failure

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_ClearStatus( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling,

      Reset the internal PER status structure, will not affect other statistics,
      such as AGC averages

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if failure

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_ClearPER_Status( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling,
         Returns a copy of the internal state.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pEVDO_NS_State = reference to a FTM_EVDO_NS_Status_Struct structure that will be
                           filled in with the state information.
                     Structure type is FTM_EVDO_NS_Status_Struct, defined in QLib_Defines.h



   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_GetStatus( HANDLE hResourceContext, void* pEVDO_NS_State );

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling,
         Returns a subset of the EVDO NS status--the current average PER and
         the number of 16-

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iMinimumNumPackets = input, minimum number of packets to capture.  Set to 0 to return
                               the current statistics
   \param piTotalPackets = output, total number of packets that have been recorded
   \param pdPER_Calculated = output, current PER, since the last time that statistics were cleared.
   \param iTimeOut_ms = input, number of milliseconds to wait for the number of packets to exceed
                        iMinimumNumPackets.  This time-out applies only when iMinimumNumPackets > 0.

   \return true if all operations succeeded

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_NS_GetPER(
      HANDLE hResourceContext,
      unsigned long iMinimumNumPackets,
      unsigned long* piTotalReceivedPackets,
      double* pdPER_Calculated,
      unsigned long iTimeOut_ms
   );

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.1 Acquire 1xEV-DO forward pilot channel

   This command acquires 1xEV-DO forward pilot channel

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iBand_Class = Indicates the band class. Possible values are:
      \code
          FTM_EVDO_BAND_CLASS_CELLULAR   = 0,
          FTM_EVDO_BAND_CLASS_PCS         = 1,
          FTM_EVDO_BAND_BC0   = 0,
          FTM_EVDO_BAND_BC1   = 1,
          FTM_EVDO_BAND_BC2   = 2,
          FTM_EVDO_BAND_BC3   = 3,
          FTM_EVDO_BAND_BC4   = 4,
          FTM_EVDO_BAND_BC5   = 5,
          FTM_EVDO_BAND_BC6   = 6,
          FTM_EVDO_BAND_BC7   = 7,
          FTM_EVDO_BAND_BC8   = 8,
          FTM_EVDO_BAND_BC9   = 9,
          FTM_EVDO_BAND_BC10   = 10,
          FTM_EVDO_BAND_BC11   = 11,
          FTM_EVDO_BAND_BC12   = 12,
          FTM_EVDO_BAND_BC13   = 13,
          FTM_EVDO_BAND_BC14   = 14,
          FTM_EVDO_BAND_BC15   = 15,
          FTM_EVDO_BAND_BC16   = 16,
          FTM_EVDO_BAND_BC17   = 17
      \endcode

   \param iCdma_Freq = Indicates the RF channel number.
   \param iAcq_Mode = Indicates the acquisition mode; possible value is FTM_ACQ_MODE_FULL(0)
   \param iDiversity_Mode = Indicates whether diversity is enabled (1) or   disabled (0).

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_PILOT_ACQ(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned long iACQ_Mode,
      unsigned long iDiversity_Mode);

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.1 Acquire 1xEV-DO forward pilot channel

   This function is same as QLIB_FTM_EVDO_PILOT_ACQ except it returns FTM_ERROR code

   \param FTM_Error = FTM Error Code from the embedded side

   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_PILOT_ACQ_V2(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned long iACQ_Mode,
      unsigned long iDiversity_Mode,
      unsigned char *iFTM_Error);

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.2 Acquire 1xEV-DO system time

   This command acquires 1xEV-DO system time

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_EVDO_SYS_TIME_ACQ(
      HANDLE hResourceContext);


   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.2 Acquire 1xEV-DO system time

   This function is same as QLIB_FTM_EVDO_SYS_TIME_ACQ except it returns FTM_ERROR code

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \warning

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_EVDO_SYS_TIME_ACQ_V2(
      HANDLE hResourceContext,
      unsigned char *iFTM_Error);
   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.3 Demodulate 1xEV-DO forward CC/MAC/FTC

   This command demodulates 1xEV-DO forward CC/MAC/FTC

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iArq_Enable = Enables/disables the early termination feature when decoding the forward channel.
   \param iDrc_Lockperiod = Time interval in slots between transmission of two consecutive DRCLock bit
                                       transmissions on the Forward MAC Channel.
   \param iDrc_Locklength = Number of times a DRCLock bit is repeated.
   \param iMac_Index    = Medium access control index assigned to the AT: 5 to 63.
   \param iRab_Length = Number of slots over which reverse activity bit is transmitted.
   \param iRab_Offset = Slots in which a new reverse activity bit can be transmitted.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_EVDO_DEMOD_CC_MAC_FTC(
      HANDLE hResourceContext,
      unsigned char* iARQ_Enable,
      unsigned char* iDRC_Lockperiod,
      unsigned char* iDRC_Locklength,
      unsigned char* iMAC_Index,
      unsigned char* iRAB_Index,
      unsigned char* iRAB_Offset);

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.4 Modulate reverse access channel

   This subcommand modulates the reverse access channel.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iACLC_Mask_I_Hi = Upper 32 bits of access channel long code mask for I quadrature, default value is 0x3FF
   \param iACLC_Mask_I_Lo = Lower 32 bits of access channel long code mask for I quadrature,default value is 0x0
   \param iACLC_Mask_Q_Hi = Upper 32 bits of access channel long code mask for Q quadrature,default value is 0x3FE
   \param iACLC_Mask_Q_Lo = Lower 32 bits of access channel long code mask for Q quadrature,default value is 0x1
   \param iAC_Txpattern = Data pattern to transmit, recommended value is 0x84B3E374 (a 32-bit Pseudo-Random Bit Sequence)
   \param iAccess_Cycle_Duration = Duration of an access channel cycle, default value is 64
   \param iOpen_Loop_Adjust = Nominal power used in open-loop power estimate.
                     default value is 81 for low bands, 84 for high bands.
   \param iProbe_Initial_Adjust = Correction power factor used in open-loop power estimate.
                     default value is 15
   \param iProbe_Num_Step = Maximum number of access probes in single-access sequence.
                     default value is 15
   \param iPower_Step = Probe power increase step in unit of 0.5dB
               default value is 15 (7.5dB)
   \param iPreamble_Length = Length of access probe preamble portion.
               default value is 2.
   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_EVDO_MOD_ACC(
      HANDLE hResourceContext,
      unsigned long iACLC_Mask_I_Hi,
      unsigned long iACLC_Mask_I_Lo,
      unsigned long iACLC_Mask_Q_Hi,
      unsigned long iACLC_Mask_Q_Lo,
      unsigned long iAC_Txpattern,
      unsigned char iAccess_Cycle_Duration,
      unsigned char iOpen_Loop_Adjust,
      unsigned char iProbe_Initial_Adjust,
      unsigned char iProbe_Num_Step,
      unsigned char iPower_Step,
      unsigned char iPreamble_Length);


   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.4 Modulate reverse access channel

   This function is same as QLIB_FTM_EVDO_MOD_ACC except it returns the FTM_Error code

   \param iFTM_Error = FTM Error code

   \warning

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_EVDO_MOD_ACC_V2(
      HANDLE hResourceContext,
      unsigned long iACLC_Mask_I_Hi,
      unsigned long iACLC_Mask_I_Lo,
      unsigned long iACLC_Mask_Q_Hi,
      unsigned long iACLC_Mask_Q_Lo,
      unsigned long iAC_Txpattern,
      unsigned char iAccess_Cycle_Duration,
      unsigned char iOpen_Loop_Adjust,
      unsigned char iProbe_Initial_Adjust,
      unsigned char iProbe_Num_Step,
      unsigned char iPower_Step,
      unsigned char iPreamble_Length,
      unsigned char* iFTM_Error);

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.5 Modulate reverse traffic channel

   This subcommand modulates the reverse traffic  channel.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iACK_Gain   = Ratio of the power level of the ACK channel (when transmitted) to the power level
                  of the reverse pilot channel, in unit of 0.5dB.
                  default value is 6 (3dB)
   \param iDataoffset_Nom = Nominal offset of reverse data channel power to the reverse pilot channel power.
                  default value is 0
   \param iDataoffset_9K6 = Ratio of reverse data channel power at 9.6 kbps to
                   the nominal reverse data channel power at 9.6 kbps.
                   default value is 0
   \param iDataoffset_19K2 = Ratio of reverse data channel power at 19.2 kbps to
                  the nominal reverse data channel power at 19.2 kbps.
                  default value is 0
   \param iDataoffset_38K4 = Ratio of reverse data channel power at 38.4 kbps to
                  the nominal reverse data channel power at 38.4 kbps.
                  default value is 0
   \param iDataoffset_76K8 = Ratio of reverse data channel power at 76.8 kbps to
                  the nominal reverse data channel power at 76.8 kbps.
                  default value is 0
   \param iDataoffset_153K6 = Ratio of reverse data channel power at 153.6 kbps to
                   the nominal reverse data channel power at 153.6 kbps.
                   default value is 0
   \param iDRC_Value = DRC value, forward traffic channel data rate, valid values are from 1 to 12.
   \param iDRC_Cover = DRC cover, default value is 1.
   \param iDRC_Gain = Ratio of the power level of the DRC channel (when   transmitted) to the power level of the reverse traffic pilot channel, in unit of 0.5dB.
               default value is 6 (3dB)
   \param iDRC_Length = DRC length
                  0 = DRC length is 1 slot
                  1 = DRC length is 2 slots
                  2 = DRC length is 4 slots
                  3 = DRC length is 8 slots
                  default value is 0.
   \param iDRC_Gating = DRC gating enable/disable, default value is 0.
   \param iFrame_Offset = Frame offset, default value is 0
   \param iPRC_Enable = RPC enable/disable, default value is true
   \param iRPC_Step = Reverse power control step
                  0 = Corresponds to 0.5 dB step
                  1 = Corresponds to 1 dB step
                  default value is 1 dB
   \param iRRI = Reverse rate indicator, reverse traffic channel data rate, valid values are from 1 to 5.
   \param iRTCLC_Mask_I_Hi = Upper 32 bits of reverse traffic channel long code mask for I quadrature, default value is 0x3FF
   \param iRTCLC_Mask_I_Lo = Lower 32 bits of reverse traffic channel long code mask for I quadrature, default value is 0x0
   \param iRTCLC_Mask_Q_Hi = Upper 32 bits of reverse traffic channel long code mask for Q quadrature, default value is 0x3FE
   \param iRTCLC_Mask_Q_Lo = Lower 32 bits of reverse traffic channel long code mask for Q quadrature, default value is 0x1
   \param iRTC_Txpattern = Data pattern to transmit, recommended value is 0x84B3E374 (a 32-bit Pseudo-Random Bit Sequence)
   \param iRTC_Txduty_Cycle = Frame duty cycle of RTCTxPattern. 8 bits. Duty cycle starts at MSB and wraps around after LSB. 1 bit
                     default value is 0xFF
   \param iHDR_ACK_Mode = ack, nak, or do not ack every slot in the non-signaling
         Mode:
      \code
           0 = FTM_EVDO_IS856_COMPLIANT: Normal IS-856 operation. Early decode enabled; do not ack.
           1 = FTM_EVDO_IS856_NO_ACK: IS856 but with no early termination. Early decode disabled; do not ack.
           2 = FTM_EVDO_IS890_MODE_0: First slot decode mode. Ack each slot (test app mode).
           3 = FTM_EVDO_IS890_MODE_1: Full packet decode mode; Nak each slot (test app mode).
           4 = FTM_EVDO_IS890A_MODE_ACK_BPSK: Always ack with bipolar keying (BPSK) modulation.
           5 = FTM_EVDO_IS890A_MODE_NAK_BPSK: Always nak with bipolar keying (BPSK) modulation.
           6 = FTM_EVDO_IS890A_MODE_ACK_OOK: Always ack with on-off keying (OOK) modulation.
           7 = FTM_EVDO_IS890A_MODE_NAK_OOK: Always nak with on-off keying (OOK) modulation.
      \endcode
      Default value is 3, FTM_EVDO_IS890_MODE_1.(Must be FTM_EVDO_IS890_MODE_1 to comply with 3GPP2 Spec IS-866-A)
   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_MOD_REVERSE_TRA(
      HANDLE hResourceContext,
      unsigned char iACK_Gain,
      unsigned char iDataoffset_Nom,
      unsigned char iDataoffset_9K6,
      unsigned char iDataoffset_19K2,
      unsigned char iDataoffset_38K4,
      unsigned char iDataoffset_76K8,
      unsigned char iDataoffset_153K6,
      unsigned char iDRC_Value,
      unsigned char iDRC_Cover,
      unsigned char iDRC_Gain,
      unsigned char iDRC_Length,
      unsigned char iDRC_Gating,
      unsigned char iFrame_Offset,
      unsigned char iPRC_Enable,
      unsigned char iRPC_Step,
      unsigned char iRRI,
      unsigned long iRTCLC_Mask_I_Hi,
      unsigned long iRTCLC_Mask_I_Lo,
      unsigned long iRTCLC_Mask_Q_Hi,
      unsigned long iRTCLC_Mask_Q_Lo,
      unsigned long iRTC_Txpattern,
      unsigned char iRTC_Txduty_Cycle,
      unsigned char iHDR_ACK_Mode);

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.5 Modulate reverse traffic channel

   This function is same as QLIB_FTM_EVDO_MOD_REVERSE_TRA except it returns FTM_Error code

   \param iFTM_Eror = FTM Error code

   \warning

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_MOD_REVERSE_TRA_V2(
      HANDLE hResourceContext,
      unsigned char iACK_Gain,
      unsigned char iDataoffset_Nom,
      unsigned char iDataoffset_9K6,
      unsigned char iDataoffset_19K2,
      unsigned char iDataoffset_38K4,
      unsigned char iDataoffset_76K8,
      unsigned char iDataoffset_153K6,
      unsigned char iDRC_Value,
      unsigned char iDRC_Cover,
      unsigned char iDRC_Gain,
      unsigned char iDRC_Length,
      unsigned char iDRC_Gating,
      unsigned char iFrame_Offset,
      unsigned char iPRC_Enable,
      unsigned char iRPC_Step,
      unsigned char iRRI,
      unsigned long iRTCLC_Mask_I_Hi,
      unsigned long iRTCLC_Mask_I_Lo,
      unsigned long iRTCLC_Mask_Q_Hi,
      unsigned long iRTCLC_Mask_Q_Lo,
      unsigned long iRTC_Txpattern,
      unsigned char iRTC_Txduty_Cycle,
      unsigned char iHDR_ACK_Mode,
      unsigned char* iFTM_Error);


   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, This command causes mobile to demodulate a different foward data rate without releaseing a non-signaling call.
   It calls QLIB_FTM_EVDO_MOD_REVERSE_TRA twice to change to a different rate

   The following procedure can be used to change the data rate:

   1. Set up a non-signaling call
   2. Change the forward data rate on test equipment
   3. Call this function with the new data rate (new DRC value)

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iACK_Gain   =   Ratio of the power level of the ACK channel (when transmitted) to the power level
                                 of the reverse pilot channel.
   \param iDataoffset_Nom = Nominal offset of reverse data channel power to the reverse pilot channel power.
   \param iDataoffset_9K6 = Ratio of reverse data channel power at 9.6 kbps to
                                        the nominal reverse data channel power at 9.6 kbps.
   \param iDataoffset_19K2 = Ratio of reverse data channel power at 19.2 kbps to
                                          the nominal reverse data channel power at 19.2 kbps.
   \param iDataoffset_38K4 = Ratio of reverse data channel power at 38.4 kbps to
                                          the nominal reverse data channel power at 38.4 kbps.
   \param iDataoffset_76K8 = Ratio of reverse data channel power at 76.8 kbps to
                                          the nominal reverse data channel power at 76.8 kbps.
   \param iDataoffset_153K6 = Ratio of reverse data channel power at 153.6 kbps to
                                           the nominal reverse data channel power at 153.6 kbps.
   \param iDRC_Value = DRC value. (the new data rate)
   \param iDRC_Cover = DRC cover.
   \param iDRC_Gain = Ratio of the power level of the DRC channel (when
                                 transmitted) to the power level of the reverse traffic pilot channel.
   \param iDRC_Length = DRC length.
   \param iDRC_Gating = DRC gating enable/disable.
   \param iFrame_Offset = Frame offset.
   \param iPRC_Enable = RPC enable/disable.
   \param iRPC_Step = Reverse power control step.
   \param iRRI = Reverse rate indicator.
   \param iRTCLC_Mask_I_Hi = Upper 32 bits of reverse traffic channel long code mask for I quadrature.
   \param iRTCLC_Mask_I_Lo = Lower 32 bits of reverse traffic channel long code mask for I quadrature.
   \param iRTCLC_Mask_Q_Hi = Upper 32 bits of reverse traffic channel long code mask for Q quadrature.
   \param iRTCLC_Mask_Q_Lo = Lower 32 bits of reverse traffic channel long code mask for Q quadrature.
   \param iRTC_Txpattern = Data pattern to transmit.
   \param iRTC_Txduty_Cycle = Frame duty cycle of RTCTxPattern. 8 bits. Duty cycle starts at MSB
                                             and wraps around after LSB. 1 bit
   \param iHDR_ACK_Mode = ack, nak, or do not ack every slot in the non-signaling
         Mode:
      \code
           0 = FTM_EVDO_IS856_COMPLIANT: Normal IS-856 operation. Early decode enabled; do not ack.
           1 = FTM_EVDO_IS856_NO_ACK: IS856 but with no early termination. Early decode disabled; do not ack.
           2 = FTM_EVDO_IS890_MODE_0: First slot decode mode. Ack each slot (test app mode).
           3 = FTM_EVDO_IS890_MODE_1: Full packet decode mode; Nak each slot (test app mode).
           4 = FTM_EVDO_IS890A_MODE_ACK_BPSK: Always ack with bipolar keying (BPSK) modulation.
           5 = FTM_EVDO_IS890A_MODE_NAK_BPSK: Always nak with bipolar keying (BPSK) modulation.
           6 = FTM_EVDO_IS890A_MODE_ACK_OOK: Always ack with on-off keying (OOK) modulation.
           7 = FTM_EVDO_IS890A_MODE_NAK_OOK: Always nak with on-off keying (OOK) modulation.
      \endcode
      Default value is 3, FTM_EVDO_IS890_MODE_1.(Must be FTM_EVDO_IS890_MODE_1 to comply with 3GPP2 Spec IS-866-A)
   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_EVDO_CHANGE_DRC(
      HANDLE hResourceContext,
      unsigned char iACK_Gain,
      unsigned char iDataoffset_Nom,
      unsigned char iDataoffset_9K6,
      unsigned char iDataoffset_19K2,
      unsigned char iDataoffset_38K4,
      unsigned char iDataoffset_76K8,
      unsigned char iDataoffset_153K6,
      unsigned char iDRC_Value,
      unsigned char iDRC_Cover,
      unsigned char iDRC_Gain,
      unsigned char iDRC_Length,
      unsigned char iDRC_Gating,
      unsigned char iFrame_Offset,
      unsigned char iPRC_Enable,
      unsigned char iRPC_Step,
      unsigned char iRRI,
      unsigned long iRTCLC_Mask_I_Hi,
      unsigned long iRTCLC_Mask_I_Lo,
      unsigned long iRTCLC_Mask_Q_Hi,
      unsigned long iRTCLC_Mask_Q_Lo,
      unsigned long iRTC_Txpattern,
      unsigned char iRTC_Txduty_Cycle,
      unsigned char iHDR_ACK_Mode);


   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.6 This subcommand deassigns all 1xEV-DO channels

   This subcommand deassigns all 1xEV-DO channels

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_CMD_RELEASE(
      HANDLE hResourceContext);


   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command 3.2.6 This subcommand deassigns all 1xEV-DO channels

   This subcommand deassigns all 1xEV-DO channels

   This function send the same command as in QLIB_FTM_EVDO_CMD_RELEASE except that it waits for searcher to go to IDLE state.
   QLIB_FTM_EVDO_NS_Start() must be called first to determine searcher state

   \param iFTM_Error = FTM Error code

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_CMD_RELEASE_V2(
      HANDLE hResourceContext,
      unsigned char *iFTM_Error);


   /******************************************************************************/
   /**
   EVDO Non-signaling command 3.2.7 Demodulate Forward Link with No Reverse Link Rev 0.


   This single replaces the this sequence of commands:
      QLIB_FTM_EVDO_DEMOD_CC_MAC_FTC()
      QLIB_FTM_EVDO_MOD_ACC()
      QLIB_FTM_EVDO_MOD_REVERSE_TRA()

   However, versions of AMSS created before 2006 may not have this command available in the embedded
   source code.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDRC_VALUE = Data rate at which AN transmits data to AT; valid values are from 1 to 14.
   \param iDRC_COVER = DRC cover value associated with the sector from which the forward traffic data at a particular DRC
                  value is requested; valid values are from 1 to 7.
   \param iARQ_ENABLE = Enables/disables the early termination feature when decoding the forward channel
   \param iDRC_LOCKPERIOD = Time interval in slots between transmission of two consecutive DRCLock bit transmissions on the
                     forward MAC channel; valid values are 0 and 1:
                     0 = DRC lock period of 8 slots
                     1 = DRC lock period of 16 slots
   \param iDRC_LOCKLENGTH = Number of times a DRCLock bit is repeated; valid values are from 0 to 3:
                     0 = Repeated 4 times for Rev 0
                     1 = Repeated 8 times for Rev 0
                     2 = Repeated 16 times for Rev 0
                     3 = Repeated 32 times for Rev 0

   \param iMAC_INDEX = Medium access control index assigned to the AT; valid values are 5 to 63 for Rev 0

   \param iRAB_LENGTH = Number of slots over which reverse activity bit is transmitted; valid values are 0 to 3:
                     0 = Corresponds to 8 slots
                     1 = Corresponds to 16 slots
                     2 = Corresponds to 32 slots
                     3 = Corresponds to 64 slots
                  This field is applicable only for Rev 0.

   \param iRAB_OFFSET = Slots in which a new reverse activity bit can be transmitted; the value in slots of RAB Offset is the
                   value of the field x RAB_LENGTH/8.

                  Valid values are from 0 to 7.

                  This field is applicable only for Rev 0.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_DEMOD_FWD_WITH_NO_REV(
      HANDLE hResourceContext,
      unsigned char iDRC_Value,
      unsigned char iDRC_Cover,
      unsigned char iARQ_Enable,
      unsigned char iDRC_Lockperiod,
      unsigned char iDRC_Locklength,
      unsigned char iMAC_Index,
      unsigned char iRAB_Length,
      unsigned char iRAB_Offset);

   /******************************************************************************/
   /**
   EVDO Non-signaling command 3.2.8 Set Idle mode

   This command puts the searcher in Idle mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_SET_IDLE( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   EVDO Non-signaling command 3.2.9 Configure Rev A MAC for Forward CC/MAC/FTC

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSHORT_PACKET_ENABLE = Sets the Short Packet mode bit of the MDSP HDR mode register:
                        0 = Do not try to decode short packet
                        1 = Try all hypotheses, long and short packets, starting with the canonical (long) packet
   \param iMULTI_USER_PACKET_ENABLE = Enables or disables the use of multi-user packet; valid values are 0 and 1:
                        0 = Disables multi-user packet
                        1 = Enables multi-user packet

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_A_CONF_MAC_FOR_FWD_CC_MAC_FTC(
      HANDLE hResourceContext,
      unsigned char iShort_Packet_Enable,
      unsigned char  iMulti_User_Packet_Enable);

   /******************************************************************************/
   /**
   EVDO Rev A Non-signaling command 3.2.10 Modulate Reverse Access Channel Rev A

   This subcommand modulates the reverse access channel in IS-856 Rev A mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iACLC_MASK_I_HI = Upper 32 bits of access channel long code mask for I quadrature, default value is 0x3FF
   \param iACLC_MASK_I_LO = Lower 32 bits of access channel long code mask for I quadrature, default value is 0x0
   \param iACLC_MASK_Q_HI = Upper 32 bits of access channel long code mask for Q quadrature, default value is 0x3FE
   \param iACLC_MASK_Q_LO = Lower 32 bits of access channel long code mask for Q quadrature,default value is 0x1
   \param iAC_TXPATTERN = Data pattern to transmit, recommended value is 0x84B3E374 (a 32-bit Pseudo-Random Bit Sequence)
   \param iACCESS_CYCLE_DURATION = Duration of an access channel cycle in units of slots;
                           valid values are in range of 1 to 255
                           default value is 64.
   \param iOPEN_LOOP_ADJUST = Negative of the nominal power used in open-loop power estimate,
                        expressed as an unsigned value in units of 1 dB
                        Value used by AT is -1 times the value of this field
                        default value is 81 for low bands, 84 for high bands.
   \param iPROBE_INITIAL_ADJUST =   Correction power factor used in open-loop power estimate for initial transmission
                           on access channel
                           Expressed as 2s complement value in units of 1 dB.
                           Valid values are from -16 dB to +15 dB
                           default value is 15
   \param iPROBE_NUM_STEP = Maximum number of access probes in single access sequence; valid values are 1 to 15
                           default value is 15
   \param iPOWER_STEP = Probe power increase step; valid values are 0 to 15 in units of 0.5 dB, default value is 15 (7.5dB)
   \param iPREAMBLE_LENGTH =   Length of access probe preamble portion in frames of 16 slots; valid values are from 1 to 7 frames
                        Applicable only if enhanced access channel feature is not enabled.
                        default value is 2
   \param iENHANCED_ACCESS_ENABLE = Whether enhanced access channel is enabled; valid values are 0 and 1:
                        0 = Enhanced access channel feature is disabled
                        1 = Enhanced access channel feature is enabled
                        default value is 1.
   \param iPREAMBLE_LENGTH_SLOTS = Preamble length in slots; valid values are 0 and 1:
                        0 = Corresponds to 4 slots
                        1 = Corresponds to 16 slots
                        Applicable only if enhanced access channel feature is enabled
                        default value is 1
   \param iACCESS_OFFSET = Indicates the slot relative to the start of access cycle duration when the access terminal may start
                     the access probe; valid values are 0 to 3 in steps of 4 slots
                     Defaults to 0 if enhanced acess channel feature is not enabled
   \param iSECTOR_ACCESS_RATE_MAX = Indicates the maximum data rate at which access channel capsule can be transmitted tor the
                           particular sector; valid values are from 0 to 2:
                           0 = Corresponds to 9.6 kbps
                           1 = Corresponds to 19.2 kbps
                           2 = Corresponds to 38.4 kbps
                           Defaults to 0 if enhanced access channel feature is not enabled
   \param iTERMINAL_ACCESS_RATE_MAX = Indicates the maximum data rate at which AT is allowed to transmit an access probe;
                              valid values are from 0 to 2:
                           0 = Corresponds to 9.6 kbps
                           1 = Corresponds to 19.2 kbps
                           2 = Corresponds to 38.4 kbps
                           Defaults to 0 if enhanced access channel feature is not enabled


   ***********************************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_A_MOD_ACC(   HANDLE hResourceContext,
         unsigned long iACLC_MASK_I_HI,
         unsigned long iACLC_MASK_I_LO,
         unsigned long iACLC_MASK_Q_HI,
         unsigned long iACLC_MASK_Q_LO,
         unsigned long iAC_Txpattern,
         unsigned char iACCESS_CYCLE_DURATION,
         unsigned char iOpen_Loop_Adjust,
         unsigned char iProbe_Initial_Adjust,
         unsigned char iProbe_Num_Step,
         unsigned char iPower_Step,
         unsigned char iPreamble_Length,
         unsigned char iEnhanced_Access_Enable,
         unsigned char iPreamble_Length_Slots,
         unsigned char iAccess_Offset,
         unsigned char iSector_Access_Rate_Max,
         unsigned char iTerminal_Access_Rate_Max);

   /******************************************************************************/
   /**
   EVDO Rev A Non-signaling command 3.2.10 Modulate Reverse Access Channel Rev A

   This function is same as QLIB_FTM_EVDO_REV_A_MOD_ACC except it returns FTM Error Code

   \param iFTM_Error = FTM Error code

   \note This function can be used in QMSL FTM Sequencer operation

   ***********************************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_A_MOD_ACC_V2(   HANDLE hResourceContext,
         unsigned long iACLC_MASK_I_HI,
         unsigned long iACLC_MASK_I_LO,
         unsigned long iACLC_MASK_Q_HI,
         unsigned long iACLC_MASK_Q_LO,
         unsigned long iAC_Txpattern,
         unsigned char iACCESS_CYCLE_DURATION,
         unsigned char iOpen_Loop_Adjust,
         unsigned char iProbe_Initial_Adjust,
         unsigned char iProbe_Num_Step,
         unsigned char iPower_Step,
         unsigned char iPreamble_Length,
         unsigned char iEnhanced_Access_Enable,
         unsigned char iPreamble_Length_Slots,
         unsigned char iAccess_Offset,
         unsigned char iSector_Access_Rate_Max,
         unsigned char iTerminal_Access_Rate_Max,
         unsigned char *FTM_Error);

   /******************************************************************************/
   /**

   EVDO Rev A Non-signaling command 3.2.11 Modulate Reverse Traffic Channel Rev A

   This subcommand modulates the reverse traffic channel in IS-856 Rev A.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDRC_VALUE = Data rate at which AN transmits data to AT; valid values are 1 to 14
   \param iDRC_COVER_VALUE = DRC cover value associated with the sector from which the forward traffic data at
                        particular DRC value is requested; valid values are from 1 to 7
                        default value is 1
   \param iDRC_LENGTH = Number of slots the AT shall use to transmit a single DRC value; valid values are from 0 to 3:
                  0 = DRC length is 1 slot
                  1 = DRC length is 2 slots
                  2 = DRC length is 4 slots
                  3 = DRC length is 8 slots
                  default value is 0.
   \param iDRC_GATING = DRC gating; valid values are 0 or 1:
                  0 = Continuous transmission of DRC value in each slot
                  1 = Discontinuous transmission of DRC channel
                  default value is 0.
   \param iDRC_CH_GAIN = Power of DRC channel relative to pilot channel expressed as 2s complement value in units of 0.5 dB;
                   valid values are from -9 dB to 6 dB;
                   default value is 6 (3dB)
   \param iACK_CH_GAIN = Power of the ACK channel relative to the pilot channel expressed as 2s complement value in units
                    of 0.5 dB; valid values are from -3 dB to 6 dB
                    default value is 6 (3dB)
   \param iDSC_VALUE = Cell cover associated with the forward link data source; valid values are from 1 to 7
                  default value is 1
   \param iDSC_LENGTH = Length of single DSC value transmission in units of 8 slots; valid values are from 1 to 32
                   default value is 8 (64 slots)
   \param iDSC_GAIN = Power of the DSC channel relative to the pilot channel in units of -0.5 dB;
                  valid values are from 0 to -15.5 dB
                  default value is 18 (-9dB)
   \param iRPC_STEP = Power control step size to be used by AT when controlling the power of reverse link; valid values are 0 and 1:
                  0 = Corresponds to 0.5 dB step
                  1 = Corresponds to 1 dB step
                  default value is 1 dB
   \param iFRAME_OFFSET = Offset from CDMA system time for frame start in units of slots; valid values are from 0 to 15 slots
                  default value is 0
   \param iRPC_ENABLE = RPC enable/disable
                  default value is true (enable)
   \param iRTC_TXPATTERN = Data pattern to transmit
                  recommended value is 0x84B3E374 (a 32-bit Pseudo-Random Bit Sequence)
   \param iLCM_I_CHAN_HI = Long code mask for I channel high 32 bits, default value is 0x3FF
   \param iLCM_I_CHAN_LOW = Long code mask for I channel low 32 bits, default value is 0x0
   \param iLCM_Q_CHAN_HI = Long code mask for q channel high 32 bits, default value is 0x3FE
   \param iLCM_Q_CHAN_LOW = Long code mask for q channel low 32 bits, default value is 0x1
   \param iRRI_PAYLOAD = Physical layer packet size index; valid values are from 1 to 12
   \param iHI_CAP_LO_LATENCY = The transmit mode of operation; valid values are 0 and 1:
                        0 = High capacity
                        1 = Low latency
                        default value is 0
   \param iGAIN_TRANSITION_POINT = Set to one less than the number of subframes for which the receiver shall use
                           pretransition T2P values and the number of subpackets after
                           which the receiver shall use posttransition values based on the above-set transmission
                           mode and RRI; valid values are from 0 to 3
                           default value is 3 (must be 3 to comply with 3GPP2 Spec IS-866-A)
   \param iT2P_PRE_TRANSITION = Set to the data channel power relative to the pilot channel power based on above-set RRI and
                         transmission mode for the subframes prior to T2P transition;
                         valid values are from 0 to 128 (inclusive) in units of 0.25 dB
                         default values are:
                         For high capacity mode: {3, 15, 28, 35, 40, 46, 52, 57, 62, 68, 74, 85} for RRI payload from 128 bits to 12288 bits.
                         For low latency mode: {28, 40, 52, 59, 65, 73, 77, 77, 82, 87, 93, 105} for RRI payload from 128 bits to 12288 bits.
   \param iT2P_POST_TRANSITION = Set to the data channel power relative to the pilot channel power based on above-set RRI and
                        transmission mode for the subframes following the T2P_transition_point;
                        valid values are from 0 to 128 (inclusive) in units of 0.25 dB
                        default values are:
                         For both high capacity and low latency modes: {3, 15, 28, 35, 40, 46, 52, 57, 62, 68, 74, 85} for RRI payload from 128 bits to 12288 bits.
   \param iARQ_MODE = Reverse link ARQ mode for sending Acks to and Nacks for reverse link packets; valid values are 0 and 1:
                        0 = ARQ mode bi-polar
                        1 = ARQ mode ON-OFF keying
                        default value is 0
   \param iAUX_PILOT_MIN_PAYLOAD =   Minimum reverse traffic channel payload for which the acess channel is required to
                           transmit the auxiliary pilot channel; valid values are from 0 to 11
                           default value is 7 (3072 bits). Note that this payload starts from 0.
   \param iAUX_PILOT_CHAN_GAIN = Set to auxiliary pilot channel gain relative to the traffic data channel gain;
                           a 4-bit value in units of -1 dB in the range of 0 to -15 dB
                           default value is 12 (-12dB)
   \param iRRICH_GAIN_PRE_TRANSITION = Set to RRI channel gain for the subframes transmitted before the T2P transition
                              based on above-set RRI and transmission mode; specified as
                              2s complement 4-bit number in units of 1 dB
                              default values are 0 for gain transition point 0, 1; -6 dB for gain transition point 2, 3.
   \param iRRICH_GAIN_POST_TRANSITION = Set to RRI channel gain for the subframes transmitted following the T2P transition
                              based on above-set RRI and transmission mode;
                              specified as 2s complement 4-bit number in units of 1 dB
                              default values are -6 dB for all gain transition points.
   \param iHDR_ACK_Mode = ack, nak, or do not ack every slot in the non-signaling
         Mode:
      \code
           0 = FTM_EVDO_IS856_COMPLIANT: Normal IS-856 operation. Early decode enabled; do not ack.
           1 = FTM_EVDO_IS856_NO_ACK: IS856 but with no early termination. Early decode disabled; do not ack.
           2 = FTM_EVDO_IS890_MODE_0: First slot decode mode. Ack each slot (test app mode).
           3 = FTM_EVDO_IS890_MODE_1: Full packet decode mode; Nak each slot (test app mode).
           4 = FTM_EVDO_IS890A_MODE_ACK_BPSK: Always ack with bipolar keying (BPSK) modulation.
           5 = FTM_EVDO_IS890A_MODE_NAK_BPSK: Always nak with bipolar keying (BPSK) modulation.
           6 = FTM_EVDO_IS890A_MODE_ACK_OOK: Always ack with on-off keying (OOK) modulation.
           7 = FTM_EVDO_IS890A_MODE_NAK_OOK: Always nak with on-off keying (OOK) modulation.
      \endcode
      Default value is 3, FTM_EVDO_IS890_MODE_1. (Must be FTM_EVDO_IS890_MODE_1 to comply with 3GPP2 Spec IS-866-A)

   *********************************************************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_A_MOD_TRA(   HANDLE hResourceContext,
         unsigned char iDRC_Value,
         unsigned char iDRC_Cover_Value,
         unsigned char iDRC_Length,
         unsigned char iDRC_Gating,
         char iDRC_Ch_Gain,
         char iACK_Ch_Gain,
         unsigned char iDSC_Value,
         unsigned char iDSC_Length,
         unsigned char iDSC_Gain,
         unsigned char iRPC_Step,
         unsigned char iFrame_Offset,
         unsigned char iRPC_Enable,
         unsigned long iRTC_Txpattern,
         unsigned long iLCM_I_CHAN_HI,
         unsigned long iLCM_I_CHAN_LOW,
         unsigned long iLCM_Q_CHAN_HI,
         unsigned long iLCM_Q_CHAN_LOW,
         unsigned char iRRI_Payload,
         unsigned char iHi_Cap_Lo_Latency,
         unsigned char iGain_Transition_Point,
         unsigned char iT2P_Pre_Transition,
         unsigned char iT2P_Post_Transition,
         unsigned char iARQ_Mode,
         unsigned char iAux_Pilot_Min_Payload,
         unsigned char iAux_Pilot_Chan_Gain,
         char iRRICH_Gain_Pre_Transition,
         char iRRICH_Gain_Post_Transition,
         unsigned char iHDR_ACK_Mode);

   /******************************************************************************/
   /**

   EVDO Rev A Non-signaling command 3.2.11 Modulate Reverse Traffic Channel Rev A

   This subcommand modulates the reverse traffic channel in IS-856 Rev A.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \note This function can be used in QMSL FTM Sequencer operation
   *********************************************************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_A_MOD_TRA_V2(   HANDLE hResourceContext,
         unsigned char iDRC_Value,
         unsigned char iDRC_Cover_Value,
         unsigned char iDRC_Length,
         unsigned char iDRC_Gating,
         char iDRC_Ch_Gain,
         char iACK_Ch_Gain,
         unsigned char iDSC_Value,
         unsigned char iDSC_Length,
         unsigned char iDSC_Gain,
         unsigned char iRPC_Step,
         unsigned char iFrame_Offset,
         unsigned char iRPC_Enable,
         unsigned long iRTC_Txpattern,
         unsigned long iLCM_I_CHAN_HI,
         unsigned long iLCM_I_CHAN_LOW,
         unsigned long iLCM_Q_CHAN_HI,
         unsigned long iLCM_Q_CHAN_LOW,
         unsigned char iRRI_Payload,
         unsigned char iHi_Cap_Lo_Latency,
         unsigned char iGain_Transition_Point,
         unsigned char iT2P_Pre_Transition,
         unsigned char iT2P_Post_Transition,
         unsigned char iARQ_Mode,
         unsigned char iAux_Pilot_Min_Payload,
         unsigned char iAux_Pilot_Chan_Gain,
         char iRRICH_Gain_Pre_Transition,
         char iRRICH_Gain_Post_Transition,
         unsigned char iHDR_ACK_Mode,
         unsigned char *iFTM_Error);



   /*********************************************************************************************************************/
   /**

   EVDO Rev A Non-signaling command 3.2.12 Demodulate Forward Link with No Reverse Link Rev A

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDRC_VALUE = Data rate at which AN transmits data to AT; valid values are from 1 to 14
   \param iDRC_COVER = DRC cover value associated with the sector from which the forward traffic data at a particular DRC
                  value is requested; valid values are from 1 to 7
   \param iDSC_VALUE = Cell cover associated with the forward link data source; valid values are from 1 to 7
   \param iARQ_ENABLE = Enables/disables the early termination feature when decoding the forward channel
   \param iDRC_LOCKPERIOD =   Time interval in slots between transmission of two consecutive DRCLock bit transmissions on the
                        forward MAC channel; valid values are 0 and 1:
                        0 = DRC lock period of 8 slots
                        1 = DRC lock period of 16 slots
   \param iDRC_LOCKLENGTH = Number of times a DRCLock bit is repeated; valid values are from 0 to 3:
                     0 = Repeated 8 times for Rev A
                     1 = Repeated 16 times for Rev A
                     2 = Repeated 32 times for Rev A
                     3 = Repeated 64 times for Rev A
   \param iMAC_INDEX = Medium access control index assigned to the AT; valid values are 5 to 63 and 72 to 127 for Rev A
   \param iRAB_LENGTH = Number of slots over which reverse activity bit is transmitted; valid values are from 0 to 3:
                     0 = Corresponds to 8 slots
                     1 = Corresponds to 16 slots
                     2 = Corresponds to 32 slots
                     3 = Corresponds to 64 slots
                  This field is applicable only for Rev0. For RevA mode, this field is always set to 0.
   \param iRAB_OFFSET = Slots in which a new reverse activity bit can be transmitted.
                  The value in slots of RAB Offset is the value of the field x RAB_LENGTH/8;
                  valid values are from 0 to 7.
                  This field is applicable only for Rev 0.
                  For Rev A mode, this field is always set to 0.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_A_DEMOD_FWD_WITH_NO_REV(   HANDLE hResourceContext,
         unsigned char iDRC_Value,
         unsigned char iDRC_Cover,
         unsigned char iDSC_Value,
         unsigned char iARQ_Enable,
         unsigned char iDRC_Lockperiod,
         unsigned char iDRC_Locklength,
         unsigned char iMAC_Index,
         unsigned char iRAB_Length,
         unsigned char iRAB_Offset);

   /******************************************************************************/
   /**
   EVDO Rev B Non-signaling command: Modulate Reverse Traffic Channel Rev B.
   This command supports 1 FL and multi-RL carriers.
   The Open loop estimate of the 2nd and 3rd carriers are copied from main RL carrier.
   When RPC is disabled, all RL carriers can have a power offset on top of the open loop estimate.
   When RPC is enabled, the power offsets do not take effect. the reverse power will be controlled by the forward link.
      The close loop adjust of the 1st (main) RL carrier is carrierd over to the 2nd/3rd carrier.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bSingleFLMode   = to indicate if the open loop estimate of the multi-carrier reverse link carriers
                  will be derived from the main carrier (on which the pilot/system time is acquired).
                  Currently AMSS only supports bSingleFLMode = TRUE (param reserved for further extension).
                  This parameter does not affect the capability to decode multi-forward link carriers.
                  Configure the equipment at the desired RF frequences, and use this command to make a Rev. B call.
                  The modem will automatically decode all forward carriers and provide valid PER measurement on each carrier.
   \param iNum_RL_Carriers = num of carriers to modulate. valid values are 1, 2 and 3.
   \param iDRC_VALUE = Data rate at which AN transmits data to AT; valid values are 1 to 14.
                  New Rev. B data rates with DRC values from 16 to 27 are allowed on supported AMSS
                  NOTE: This DRC value is used on ALL forward carriers,
                  thus the physical FL signal on equipment must be configured to use the same DRC.
   \param iDRC_CH_GAIN = Power of DRC channel relative to pilot channel n units of 0.5 dB;
                  valid values are -18 to +12 (corresponding from -9 dB to 6 dB)
                  default value is 6 (3dB)
   \param iACK_CH_GAIN = Power of the ACK channel relative to the pilot channelin units
                    of 0.5 dB; valid values are -6 to +12 (corresponding from -3 dB to 6 dB)
                  default value is 6 (3dB)
   \param iDSC_GAIN = Power of the DSC channel relative to the pilot channel in units of -0.5 dB;
                  valid values are from 0 to 31 (corresponding from 0 to -15.5 dB)
                  default value is 18 (-9dB)
   \param iRPC_STEP = Power control step size to be used by AT when controlling the power of reverse link:
               \code
               0 = FTM_EVDO_RPC_STEP_HalfdB: Corresponds to 0.5 dB step
               1 = FTM_EVDO_RPC_STEP_1dB: Corresponds to 1 dB step
               \endcode
               defaut value is 1 dB.
   \param iRPC_ENABLE = enable/disable reverse power control.
               TRUE = Enable RPC
               FALSE = Disable RPC
   \param iRRI_PAYLOAD = Revese link physical layer packet size index; valid values are from 1 to 12 (corresponding from 128Bit to 12288Bit)
   \param iHI_CAP_LO_LATENCY = The transmit mode of operation
            \code
            0 = FTM_EVDO_HIGH_CAPACITY: High capacity,
            1 = FTM_EVDO_LOW_LATENCY: Low capacity
            \endcode
            defaut value is 0:FTM_EVDO_HIGH_CAPACITY

   \param iAUX_PILOT_CHAN_GAIN = Set to auxiliary pilot channel gain relative to the traffic data channel gain;
                        a 4-bit value in units of -1 dB.
                        valid values are from 0 to 15 (corresponding from 0 to -15 dB)
                        default value is 12 (-12 dB)
   \param iPower_Offset = Tx power offset of the main RL carrier from open loop estimate in unit of 1/4 dB, valid only when RPC is disabled.
   \param iRL_2_Channel = channel number of the 2nd RL carrier. Must follow MaxSeparation constraint. valid only when iNum_RL_Carriers =2 or 3
   \param iRL_2_Power_Offset = Tx power offset of the 2nd RL carrier in unit of 1/4 dB, valid only when RPC is disabled and iNum_RL_Carriers = 2 or 3
   \param iRL_2_RRI_Payload = Reverse Rate Indicator Payload of the 2nd RL carrier. valid values are from 1 to 12. valid only only when iNum_RL_Carriers =2 or 3
   \param iRL_3_Channel = channel number of the 3rd RL carrier. Must follow MaxSeparation constraint. valid only when iNum_RL_Carriers =3
   \param iRL_3_Power_Offset = Tx power offset of the 3rd RL carrier in unit of 1/4 dB, valid only when RPC is disabled and iNum_RL_Carriers =3
   \param iRL_3_RRI_Payload = Reverse Rate Indicator Payload of the 3rd RL carrier. valid values are from 1 to 12, valid only when iNum_RL_Carriers =3

   \return true if successful, false if fail.

   \note: The following sequence should be used to call this command.
      QLIB_FTM_EVDO_NS_Start
      QLIB_FTM_EVDO_PILOT_ACQ
      QLIB_FTM_EVDO_SYS_TIME_ACQ
      QLIB_FTM_EVDO_REV_A_MOD_ACC (same API for Rev. A access channel)
      QLIB_FTM_EVDO_REV_B_CONFIG_RTC(optional)
      QLIB_FTM_EVDO_REV_B_MOD_RTC

   *********************************************************************************************************************/

   QLIB_API unsigned char QLIB_FTM_EVDO_REV_B_MOD_RTC(   HANDLE hResourceContext,
         unsigned char bSingleFLMode,
         unsigned char iNum_RL_Carriers,
         unsigned char iDRC_Value,
         char iDRC_Ch_Gain,
         char iACK_Ch_Gain,
         unsigned char iDSC_Gain,
         unsigned char iRPC_Step,
         unsigned char iRPC_Enable,
         unsigned char iRRI_Payload,
         unsigned char iHi_Cap_Lo_Latency,
         unsigned char iAux_Pilot_Chan_Gain,
         unsigned char iPower_Offset,
         unsigned short iRL2_Channel,
         unsigned char iRL2_Power_Offset,
         unsigned char iRL2_RRI_Payload,
         unsigned short iRL3_Channel,
         unsigned char iRL3_Power_Offset,
         unsigned char iRL3_RRI_Payload
                                                     );


   /******************************************************************************/
   /**

   EVDO Rev B Non-signaling command: Configure Reverse Traffic Channel Rev B
   This function is not required if using default values. Otherwise, it can be called multiple times to configure all required fields.
   For example, to configure T2P pre-transition gain for different rri.
   AT will reject this command if AT's current state is in Traffic, and the return value will be false.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDRC_COVER_VALUE = DRC cover value associated with the sector from which the forward traffic data at
                     particular DRC value is requested; valid values are from 1 to 7. default value is 1.
   \param iDRC_LENGTH = Number of slots the AT shall use to transmit a single DRC value
      \code
               0 = FTM_EVDO_DRC_1_SLOTS: DRC length is 1 slot
       1 = FTM_EVDO_DRC_2_SLOTS: DRC length is 2 slots
       2 = FTM_EVDO_DRC_4_SLOTS: DRC length is 4 slots
       3 = FTM_EVDO_DRC_8_SLOTS: DRC length is 8 slots
      \endcode
      default value is 0: FTM_EVDO_DRC_1_SLOTS.
   \param iDRC_GATING = DRC gating:
         0 = FTM_EVDO_DRC_CONTINUOUS:Continuous transmission of DRC value in each slot
         1 = FTM_EVDO_DRC_DISCONTINOUS = Discontinuous transmission of DRC channel
         Default value is 0: FTM_EVDO_DRC_CONTINUOUS
   \param iDSC_VALUE = Cell cover associated with the forward link data source; valid values are from 1 to 7
                  default 1.
   \param iDSC_LENGTH = Length of single DSC value transmission in units of 8 slots; valid values are from 1 to 32
                  default 8 (64 slots)
   \param iFRAME_OFFSET = Offset from CDMA system time for frame start in units of slots; valid values are from 0 to 15 slots
                  default 0
   \param iRTC_TXPATTERN = Data pattern to transmit. recommended value is 0x84B3E374 (a 32-bit Pseudo-Random Bit Sequence)
   \param iLCM_I_CHAN_HI = Long code mask for I channel high 32 bits. default 0x3ff
   \param iLCM_I_CHAN_LOW = Long code mask for I channel low 32 bits. default 0x0
   \param iLCM_Q_CHAN_HI = Long code mask for q channel high 32 bits. default 0x3fe
   \param iLCM_Q_CHAN_LOW = Long code mask for q channel low 32 bits. default 0x1
   \param iARQ_MODE = Reverse link ARQ mode for sending Acks to and Nacks for reverse link packets:
         \code
         0 = FTM_EVDO_ARQ_BPSK: ARQ mode bi-polar FTM_EVDO_ARQ_BPSK,
         1 = FTM_EVDO_ARQ_OOK: ARQ mode ON-OFF keying
         \endcode
         default value is 0, FTM_EVDO_ARQ_BPSK
   \param iHDR_ACK_Mode = ack, nak, or do not ack every slot in the non-signaling mode:
         \code
            0 = FTM_EVDO_IS856_COMPLIANT: Normal IS-856 operation. Early decode enabled; do not ack.
            1 = FTM_EVDO_IS856_NO_ACK: IS856 but with no early termination. Early decode disabled; do not ack.
            2 = FTM_EVDO_IS890_MODE_0: First slot decode mode. Ack each slot (test app mode).
            3 = FTM_EVDO_IS890_MODE_1: Full packet decode mode; Nak each slot (test app mode).
            4 = FTM_EVDO_IS890A_MODE_ACK_BPSK: Always ack with bipolar keying (BPSK) modulation.
            5 = FTM_EVDO_IS890A_MODE_NAK_BPSK: Always nak with bipolar keying (BPSK) modulation.
            6 = FTM_EVDO_IS890A_MODE_ACK_OOK: Always ack with on-off keying (OOK) modulation.
            7 = FTM_EVDO_IS890A_MODE_NAK_OOK: Always nak with on-off keying (OOK) modulation.
         \endcode
         Default value is 3, FTM_EVDO_IS890_MODE_1. (Must be FTM_EVDO_IS890_MODE_1 to comply with 3GPP2 Spec IS-866-A)
   \param iAUX_PILOT_MIN_PAYLOAD =   Minimum reverse traffic channel payload for which the acess channel is required to
                           transmit the auxiliary pilot channel; valid values are from 0 to 11.
                           Default value is 7: 3072 bit.
   \param iRRI_PAYLOAD = Physical layer packet size index used only to configure T2P and RRI channel gain parameters;
                           valid values are from 1 to 12
   \param iHI_CAP_LO_LATENCY = The transmit mode of operation used only to configure T2P and RRI channel gain parameters
         \code
         0 = FTM_EVDO_HIGH_CAPACITY: High capacity,
         1 = FTM_EVDO_LOW_LATENCY: Low capacity
         \endcode
         defaut value is 0:FTM_EVDO_HIGH_CAPACITY

   \param iGAIN_TRANSITION_POINT = Set to one less than the number of subframes for which the receiver shall use
                           pretransition T2P values and the number of subpackets after
                           which the receiver shall use posttransition values based on the above-set transmission
                           mode and RRI; valid values are from 0 to 3. Default value is 3.
   \param iT2P_PRE_TRANSITION = Set to the data channel power relative to the pilot channel power based on above-set RRI and
                         transmission mode for the subframes prior to T2P transition;
                         valid values are from 0 to 128 (inclusive) in units of 0.25 dB.
                         Default vlues are:
                         high capacity mode: 3, 15, 28, 35, 40, 46, 52, 57, 62, 68, 74, 85 for RRI from 1 to 12
                         low latency mode: 28, 40, 52, 59, 65, 73, 77, 77, 82, 87, 93, 105 for RRI from 1 to 12
   \param iT2P_POST_TRANSITION = Set to the data channel power relative to the pilot channel power based on above-set RRI and
                        transmission mode for the subframes following the T2P_transition_point;
                        valid values are from 0 to 128 (inclusive) in units of 0.25 dB
                         Default vlues are:
                         both high capacity and low latency modes: 3, 15, 28, 35, 40, 46, 52, 57, 62, 68, 74, 85 for RRI from 1 to 12

   \param iRRICH_GAIN_PRE_TRANSITION = Set to RRI channel gain for the subframes transmitted before the T2P transition
                              based on above-set RRI and transmission mode; Unit is 1 dB
                        default values are: 0,0,-6,-6 for gain transition point from 0 to 3
   \param iRRICH_GAIN_POST_TRANSITION = Set to RRI channel gain for the subframes transmitted following the T2P transition
                              based on above-set RRI and transmission mode; in units of 1 dB
                        default values are: -6,-6,-6,-6 for gain transition point from 0 to 3

   \return true if successful, false if fail.

   *********************************************************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_B_CONFIG_RTC(   HANDLE hResourceContext,
         unsigned char iDRC_Cover_Value,
         unsigned char iDRC_Length,
         unsigned char iDRC_Gating,
         unsigned char iDSC_Value,
         unsigned char iDSC_Length,
         unsigned char iFrame_Offset,
         unsigned long iRTC_Txpattern,
         unsigned long iLCM_I_CHAN_HI,
         unsigned long iLCM_I_CHAN_LOW,
         unsigned long iLCM_Q_CHAN_HI,
         unsigned long iLCM_Q_CHAN_LOW,
         unsigned char iARQ_Mode,
         unsigned char iHDR_ACK_Mode,
         unsigned char iAux_Pilot_Min_Payload,
         unsigned char iRRI_Payload,
         unsigned char iHi_Cap_Lo_Latency,
         unsigned char iGain_Transition_Point,
         unsigned char iT2P_Pre_Transition,
         unsigned char iT2P_Post_Transition,
         char iRRICH_Gain_Pre_Transition,
         char iRRICH_Gain_Post_Transition);

   /******************************************************************************
   /**
   EVDO Non-signaling command: set same channel params, including pilot add, pilot drop, pilot compare, etc.
   This function is not required to bring up an FTM non-signaling call. Call it only if reconfiguration is required.
   This function applies to Rel. 0, Rev. A and Rev. B, on supported AMSS.
   See 3GPP2 C.S0024-B v2.0: cdma2000 High Rate Packet Data Air Interface Specification, section 7.8.7.2.2 SetManagementSameChannelParameters Attribute.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param   iPilot_Add = Pilot detecting threshold (in -0.5 dB) .
                  This value is used by the access terminal to trigger a RouteUpdate in the Connected State.
                  Valid values are from 0x0 to 0x3F (0 to 63).
                  Default value is 0x0e (-7dB)
   \param    iPilot_Drop = Threshold to start drop timer (in -0.5 dB)
                  This value is used by the access terminal to start a pilot drop timer for a pilot in the Active Set or the Candidate Set.
                  Valid values are from 0x0 to 0x3F (0 to 63)
                  Default value is 0x12 (-9dB)
   \param    iPilot_Compare = Comparison threshold for Route Update message (in 0.5 dB)
                  Active Set versus Candidate Set comparison threshold, expressed as a 2s complement number.
                  Valid values are from 0x0 to 0x3F (0 to 63)
                  Default value is 0x05
   \param    iPilot_Drop_Timer = Expiration time of the Drop timer (lookup table)
                  \code
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
                     }FTM_EVDO_DROP_TIMER_Enum
                  \endcode
                  Default value is FTM_EVDO_DROPTIMER_4_SEC
   \param    bDynamic_Thresholds = Flag to indicate if following 3 parameters are valid
                  This field shall be set to 1 if the following three fields are used. Otherwise, this field shall be set to 0.
                  Default value is 0.
   \param    iSoft_Slope = This field is valid only if DynamicThresholds is set to 1.
                  This field shall be set to an unsigned binary number, which is used
                  by the access terminal in the inequality criterion for adding a pilot to
                  the Active Set or dropping a pilot from the Active Set.
                  Default value is 0
   \param    iAdd_Intercept = This field is valid only if DynamicThresholds is set to 1.
                  This field shall be set to a 2s complement signed binary number in
                  units of dB.
                  Default value is 0
   \param    iDrop_Intercept = This field is valid only if DynamicThresholds is set to 1.
                  This field shall be set to a 2s complement signed binary number in
                  units of dB.
                  Default value is 0
   \param    iNset_Max_Age = Maximum age for NSET pilots.  Pilots this old are dropped first.
                  No unit. This value is used by AMSS to limit a counter (AGE).
                  The AGE counter behavior is described in 3GPP2 C.S0024-B v2.0,
                  section 7.8.6.1.2.7 Neighbor Set Management for Default Route Update Protocol (Rev.0/A),
                  section 7.9.6.1.2.10 Neighbor Set Management for Multi-carrier Route Update Protocol (Rev. B).
                  Default value is 0
   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_CONFIG_SAME_CHANNEL (HANDLE hResourceContext,
         unsigned short iPilot_Add,
         unsigned short iPilot_Drop,
         unsigned short iPilot_Compare,
         unsigned char iPilot_Drop_Timer,
         unsigned char bDynamic_Thresholds,
         char iSoft_Slope,
         char iAdd_Intercept,
         char iDrop_Intercept,
         unsigned char iNset_Max_Age);

   /******************************************************************************
   /**
   EVDO Non-signaling command: configure reverse traffic channel tx data pattern for rev. b.
   This function is not required to bring up an FTM non-signaling call. Call it only if reconfiguration is required.
   This function applies to Rev. B, on supported AMSS.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param   iUse_Pattern = if or not to use fixed data pattern.
         true = the following tx patterns for each carrier will be repeated for entire tx packet
         false = the modem will generte random bytes in the entire tx packet.
   \note   the following params only takes effect when iUse_Pattern = true
   \param   iRL1Tx_Pattern = 32 bits Tx data pattern on reverse link carrier 1.
   \param   iRL2Tx_Pattern = 32 bits Tx data pattern on reverse link carrier 2.
   \param   iRL3Tx_Pattern = 32 bits Tx data pattern on reverse link carrier 3.
   \return true if successful, false if fail.
   \warning It's recommended to use random data bytes in reverse traffic channel (by not calling this command or use iUse_Pattern = 0).
         If use fixed data pattern, it's important to use different patterns on each reverse carrier, to minimize the correlations.
         The recommended values include: (32-bit Pseudo-Random Bit Sequences)
         0x84B3E374, 0x3E375096, 0xEA12CF8D
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_B_CONFIG_RTC_TX_PATTERN (HANDLE hResourceContext,
         unsigned char iUse_Pattern,
         unsigned long iRL1Tx_Pattern,
         unsigned long iRL2Tx_Pattern,
         unsigned long iRL3Tx_Pattern);


   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command to make a 1xEV-DO Release 0 non-signaling call in the desired band and channel.

   This command makes a 1xEV-DO non-signaling call with default parameters for access and traffic channel.
   After this command is successful, use QLIB_FTM_EVDO_NS_EnableMeasurementLogs to enable the measurement log code,
   And use QLIB_FTM_EVDO_NS_GetStatus to poll the measurement result.
   The forward link signal level can be changed to the desired level to perform measurement without affecting the existing call.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iBand_Class = Indicates the band class. Possible values are:
      \code
             FTM_EVDO_BAND_CLASS_CELLULAR   = 0,
             FTM_EVDO_BAND_CLASS_PCS         = 1,
             FTM_EVDO_BAND_BC0   = 0,
             FTM_EVDO_BAND_BC1   = 1,
             FTM_EVDO_BAND_BC2   = 2,
             FTM_EVDO_BAND_BC3   = 3,
             FTM_EVDO_BAND_BC4   = 4,
             FTM_EVDO_BAND_BC5   = 5,
             FTM_EVDO_BAND_BC6   = 6,
             FTM_EVDO_BAND_BC7   = 7,
             FTM_EVDO_BAND_BC8   = 8,
             FTM_EVDO_BAND_BC9   = 9,
             FTM_EVDO_BAND_BC10   = 10,
             FTM_EVDO_BAND_BC11   = 11,
             FTM_EVDO_BAND_BC12   = 12,
             FTM_EVDO_BAND_BC13   = 13,
             FTM_EVDO_BAND_BC14   = 14,
             FTM_EVDO_BAND_BC15   = 15,
             FTM_EVDO_BAND_BC16   = 16,
             FTM_EVDO_BAND_BC17   = 17
      \endcode

   \param iCdma_Freq = Indicates the RF channel number.
   \param iDRC_Value = DRC index of forward traffic channel, valid values are from 1 to 12
   \param iRRI = Reverse rate indicator. valid values are from 1 to 5.
   \param bEnableRPC = enable or disable reverse power control.
   \param iDiversity_Mode = enable or disable diversity mode.
   \param iMax_Num_Attempt = the maximum allowed attempts to make an FTM non-signaling call.

   \return true if successful, false if fail.

   \warning Test equipment must be set to the desired band, channel and MAC index= 63 before calling this command.

         A failed return value (false) indicates phone fails to make an FTM non-signaling call.
         Make sure test equipment has been properly set to the desired band, channel,
         and it transmits a moderate forward link signal (e.g., -55 - -75 dBm).
         If the failure remains, a phone reset is recommended.

   \note The following sub-commands are called until a call is made, or the function reaches the maximum allowed number of attempts.
      The access channel and traffic channel will use default parameters.
      For a complete list of default parameters, see the subcommand respectively.
      \code
         //step 1: enable NS and clear status.
         QLIB_FTM_EVDO_NS_Start;
         //step 2: make sure previous call is down
         QLIB_FTM_EVDO_CMD_RELEASE;
         //step 3: acq pilot
         QLIB_FTM_EVDO_PILOT_ACQ
         //step 4: acq time
         QLIB_FTM_EVDO_SYS_TIME_ACQ
         //step 5: mod acc chan.
         QLIB_FTM_EVDO_MOD_ACC
         //wait half second for phone to transmit at least 1 probe.
         Sleep(500);
         //step 6: mod RTC
         QLIB_FTM_EVDO_MOD_TRA
      \endcode
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_0_START_CALL(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned char iDRC_Value,
      unsigned char iRRI,
      unsigned char bEnableRPC,
      unsigned long iDiversity_Mode,
      unsigned short iMax_Num_Attempt);


   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command to make a 1xEV-DO Revision A non-signaling call in the desired band and channel.

   This command makes a 1xEV-DO non-signaling call with default parameters for access and traffic channel.
   After this command is successful, use QLIB_FTM_EVDO_NS_EnableMeasurementLogs to enable the measurement log code,
   And use QLIB_FTM_EVDO_NS_GetStatus to poll the measurement result.
   The forward link signal level can be changed to the desired level to perform measurement without affecting the existing call.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iBand_Class = Indicates the band class. Possible values are:
      \code
             FTM_EVDO_BAND_CLASS_CELLULAR   = 0,
             FTM_EVDO_BAND_CLASS_PCS         = 1,
             FTM_EVDO_BAND_BC0   = 0,
             FTM_EVDO_BAND_BC1   = 1,
             FTM_EVDO_BAND_BC2   = 2,
             FTM_EVDO_BAND_BC3   = 3,
             FTM_EVDO_BAND_BC4   = 4,
             FTM_EVDO_BAND_BC5   = 5,
             FTM_EVDO_BAND_BC6   = 6,
             FTM_EVDO_BAND_BC7   = 7,
             FTM_EVDO_BAND_BC8   = 8,
             FTM_EVDO_BAND_BC9   = 9,
             FTM_EVDO_BAND_BC10   = 10,
             FTM_EVDO_BAND_BC11   = 11,
             FTM_EVDO_BAND_BC12   = 12,
             FTM_EVDO_BAND_BC13   = 13,
             FTM_EVDO_BAND_BC14   = 14,
             FTM_EVDO_BAND_BC15   = 15,
             FTM_EVDO_BAND_BC16   = 16,
             FTM_EVDO_BAND_BC17   = 17
      \endcode

   \param iCdma_Freq = Indicates the RF channel number.
   \param iDRC_Value = DRC index of forward traffic channel; valid values are from 1 to 14.
   \param iRRI_PAYLOAD = Physical layer packet size index; valid values are from 1 to 12
   \param bEnableRPC = enable or disable reverse power control.
   \param iDiversity_Mode = enable or disable diversity mode.
   \param iMax_Num_Attempt = the maximum allowed attempts to make an FTM non-signaling call.

   \return true if successful, false if fail.

   \warning Test equipment must be set to the desired band, channel and MAC index= 63 before calling this command.

         A failed return value (false) indicates phone fails to make an FTM non-signaling call.
         Make sure test equipment has been properly set to the desired band, channel,
         and it transmits a moderate forward link signal (e.g., -55 - -75 dBm).
         If the failure remains, a phone reset is recommended.

   \note The following sub-commands are called until a call is made, or the function reaches the maximum allowed number of attempts.
      The access channel and traffic channel will use default parameters.
      For a complete list of default parameters, see the subcommand respectively.
      \code
         //step 1: enable NS and clear status.
         QLIB_FTM_EVDO_NS_Start
         //step 2: make sure previous call is down
         QLIB_FTM_EVDO_CMD_RELEASE
         //step 3: acq pilot
         QLIB_FTM_EVDO_PILOT_ACQ
         //step 4: acq time
         QLIB_FTM_EVDO_SYS_TIME_ACQ
         //step 5: mod acc chan.
         QLIB_FTM_EVDO_REV_A_MOD_ACC
         //wait half second for phone to transmit at least 1 probe.
         Sleep(500);
         //step 6: mod RTC
         QLIB_FTM_EVDO_REV_A_MOD_TRA
      \endcode
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_A_START_CALL(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned char iDRC_Value,
      unsigned char iRRI_Payload,
      unsigned char bEnableRPC,
      unsigned long iDiversity_Mode,
      unsigned short iMax_Num_Attempt);

   /******************************************************************************/
   /**
   1XEV-DO Non-signaling, command to make a 1xEV-DO Revision B non-signaling call in the desired band and channel.

   This command makes a 1xEV-DO non-signaling call with default parameters for access and traffic channel.
   After this command is successful, use QLIB_FTM_EVDO_NS_EnableMeasurementLogs to enable the measurement log code,
   And use QLIB_FTM_EVDO_NS_GetStatus to poll the measurement result.
   The forward link signal level can be changed to the desired level to perform measurement without affecting the existing call.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iBand_Class = Indicates the band class. Possible values are:
      \code
             FTM_EVDO_BAND_CLASS_CELLULAR   = 0,
             FTM_EVDO_BAND_CLASS_PCS         = 1,
             FTM_EVDO_BAND_BC0   = 0,
             FTM_EVDO_BAND_BC1   = 1,
             FTM_EVDO_BAND_BC2   = 2,
             FTM_EVDO_BAND_BC3   = 3,
             FTM_EVDO_BAND_BC4   = 4,
             FTM_EVDO_BAND_BC5   = 5,
             FTM_EVDO_BAND_BC6   = 6,
             FTM_EVDO_BAND_BC7   = 7,
             FTM_EVDO_BAND_BC8   = 8,
             FTM_EVDO_BAND_BC9   = 9,
             FTM_EVDO_BAND_BC10   = 10,
             FTM_EVDO_BAND_BC11   = 11,
             FTM_EVDO_BAND_BC12   = 12,
             FTM_EVDO_BAND_BC13   = 13,
             FTM_EVDO_BAND_BC14   = 14,
             FTM_EVDO_BAND_BC15   = 15,
             FTM_EVDO_BAND_BC16   = 16,
             FTM_EVDO_BAND_BC17   = 17
      \endcode

   \param iCdma_Freq = Indicates the RF channel number.
   \param iDRC_Value = DRC index of forward traffic channel; valid values are from 1 to 14;
                  New Rev. B data rates with DRC values from 16 to 27 are allowed on supported AMSS
                  NOTE: This DRC value is used on ALL forward carriers,
                  thus the physical FL signal on equipment must be configured to use the same DRC.
   \param iRRI_PAYLOAD = Physical layer packet size index; valid values are from 1 to 12
   \param bEnableRPC = enable or disable reverse power control.
   \param iDiversity_Mode = enable or disable diversity mode.
   \param iNum_of_Carriers = the number of carriers, valid values are from 1 to 3,
   \param iRL_2_Channel = channel number of the 2nd RL carrier. Must follow MaxSeparation constraint. valid only when iNum_of_Carriers =2 or 3
   \param iRL_2_RRI_Payload = Reverse Rate Indicator Payload of the 2nd RL carrier. valid values are from 1 to 12. valid only only when iNum_of_Carriers =2 or 3
   \param iRL_3_Channel = channel number of the 3rd RL carrier. Must follow MaxSeparation constraint. valid only when iNum_of_Carriers =3
   \param iRL_3_RRI_Payload = Reverse Rate Indicator Payload of the 3rd RL carrier. valid values are from 1 to 12, valid only when iNum_of_Carriers =3
   \param iMax_Num_Attempt = the maximum allowed attempts to make an FTM non-signaling call.

   \return true if successful, false if fail.

   \warning Test equipment must be set to the desired band, channel and with MAC index= 63 before calling this command.
      Only the main forward link carrier at iCDMA_Freq is required to make a Rev. B call;
      All the reverse link measurements are supported with only one forward carrier.
      However, only the forward carriers that are physically present will report valid PER information.

      A failed return value (false) indicates phone fails to make an FTM non-signaling call.
      Make sure test equipment has been properly set to the desired band, channel,
      and it transmits a moderate forward link signal (e.g., -55 - -75 dBm).
      If the failure remains, a phone reset is recommended.

   \note The following sub-commands are called until a call is made, or the function reaches the maximum allowed number of attempts.
      The access channel and traffic channel will use default parameters.
      For a complete list of default parameters, see the subcommand respectively.
      \code
         //step 1: enable NS and clear status.
         QLIB_FTM_EVDO_NS_Start
         //step 2: make sure previous call is down
         QLIB_FTM_EVDO_CMD_RELEASE
         //step 3: acq pilot
         QLIB_FTM_EVDO_PILOT_ACQ
         //step 4: acq time
         QLIB_FTM_EVDO_SYS_TIME_ACQ
         //step 5: mod acc chan. //Rev. B re-uses same command as Rev. A for Access channel.
         QLIB_FTM_EVDO_REV_A_MOD_ACC
         //wait half second for phone to transmit at least 1 probe.
         Sleep(500);
         //step 6: mod RTC
         QLIB_FTM_EVDO_REV_B_MOD_RTC
      \endcode
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_REV_B_START_CALL(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned char iDRC_Value,
      unsigned char iRRI_Payload,
      unsigned char bEnableRPC,
      unsigned long iDiversity_Mode,
      unsigned char iNum_of_Carriers,
      unsigned short iRL2_Channel,
      unsigned char iRL2_RRI_Payload,
      unsigned short iRL3_Channel,
      unsigned char iRL3_RRI_Payload,
      unsigned short iMax_Num_Attempt);

   /******************************************************************************/
   /**
   EVDO Non-signaling command x.x.xx Handoff command

   This function performs hard-handoff in non-signalling

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iBand_Class = Indicates the band class. Possible values are in FTM_CDMA2000_BandClasstype in QLib_Defines.h

   \param iCDMA_Freq  = Indicates the RF channel number.

   \param iEnable_RPC = 1 to enable reverse link power control (RPC), 0 to disable RPC

   \return true if successful, false if fail.

   \warning This must be called only after a NS EVDO is called successfully

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_FWD_HHO_SC(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned char iEnable_RPC );


   /******************************************************************************/
   /**
   EVDO Non-signaling command x.x.xx Handoff command

   This function is same as QLIB_FTM_EVDO_FWD_HHO_SC except it returns FTM_Error code

   \param iFTM_Error = FTM Error Code

   \return true if successful, false if fail.

   \warning This must be called only after a NS EVDO is called successfully

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_FWD_HHO_SC_V2(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned char iEnable_RPC,
      unsigned short *iFTM_Error);



   /******************************************************************************/
   /**
   EVDO Non-signaling command x.x.xx Set reverse link power

   This function overrides the reverse link power control with EVDO NS mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iPower_Type = 1 = enable (Override reverse link power with iRev_Pwr_indBm10)
                   0 = disabled (use power control bit if RPC is enabled)

   \param iRev_Pwr_indBm10  = Indicates the power level in 10/dBm units as signed number.
                   This field is used only when iPower_Type is set to FTM_1X_TX_POWER_TYPE_AGC_SETPOINT

                   For example, to set 24dBm, 240 should be used

   \param iFTM_Error = FTM Error Code

   \return true if successful, false if fail.

   \warning This function should be called only a NS call has been established successfully

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_SET_REV_PWR(
      HANDLE hResourceContext,
      unsigned char iPower_Type,
      unsigned long iRev_Pwr_indBm10,
      unsigned char *iFTM_Error
   );

   /******************************************************************************/
   /**
   EVDO Non-signaling command x.x.xx Reset fowrward link PER statistics

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function should be called only a NS call has been established successfully

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_EVDO_RESET_FWD_STAT( HANDLE hResourceContext);

   /******************************************************************************/
   /**
   Synchronous EVDO Non-signaling command x.x.xx Get fowrward link PER statistics

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iTotalPacket = Total packets since the counter set

   \param iTotalPacketError = Total number of error packets since last counter reset

   \param dPER = Packet Error Rate (iTotalPacketError/iTotalPacket*100)
              999.0 is returned if the traget does not support the command

   \return true if successful, false if fail.

   \warning This function should be called only a NS call has been established successfully

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_GET_FWD_STAT( HANDLE hResourceContext, unsigned long* iTotalPacket, unsigned long* iTotalPacketError, double * dPER);
   /******************************************************************************/
   /**
   Synchronous EVDO Non-signaling command x.x.xx Get forward link power level

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRxChain = 0 - Primary Rx
                     1 - Secondary Rx

   \param iStatus = FTM Error Code
                0 - FTM_SUCCESS
                    1 - FTM_INVALID_CMD
                2 - FTM_INVALID_STATE
                3 - FTM_NO_SUCCESS

    \param iRSSI = Output value, RSSI value. RxAGC_dBm=(RAW_RSSI/640-63.8)

   \param iRxPowerdBm = output value, Rx power in 1/10 dBm units
                        this is a signed value

   \return true if successful, false if fail.

   \warning This function should be called only a NS call has been established successfully

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EVDO_RX_LEVEL_REQ(   HANDLE hResourceContext,
         unsigned char iRxChain,
         unsigned long* iStatus,
         short *iRxAGC,
         short *iRxPowerdBm);



#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_EVDO_NS_H)
