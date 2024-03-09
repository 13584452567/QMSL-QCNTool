/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_CDMA2000_NS.h#5 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_CDMA2000_NS
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_CDMA2000_NS_H)
#define _QMSL_FTM_CDMA2000_NS_H

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
                  cdma2000 FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   Get certain fields from the IS-2000 status.
   CDMA ICD 3.4.111

   The IS2000 Status Request Message asks for current DMSS status information. This information
   is returned in the IS2000 Status Response Message.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piBandClass = output, Band class number
   \param piCurrChan = output, current channel number
   \param piCDMA_RxState = output, reciever state
      \code
         0 = CDMA_STATE (initialization state)
         1 = SC_STATE (sync channel state)
         2 = PC_STATE (paging channel state)
         3 = TCI_STATE (traffic channel initialization state)
         4 = TC_STATE (traffic channel state)
         5 = EXIT_STATE (exit state)
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_IS2000_STATUS_F(
      HANDLE hResourceContext,
      unsigned char* piBandClass,
      unsigned short* piCurrChan,
      unsigned short* piCDMA_RxState );

   /******************************************************************************/
   /** see Call Manager ICD 3.4.50 Call Origination request
           The DM may cause an origination from the DMSS by sending a Call Origination Request
       message. The message specifies the dialed digits and the desired service option. The DMSS
       originates the call and responds with a Call Origination Response message. A successful
       response message does not guarantee a successful call origination. The phones call processing
       state should be monitored using the Phone State (63 / 0x3F) (Section 3.4.60) and/or the Status
       12 / 0x0C) (Section 3.4.9).

       This command starts a mobile originated call through the call origination request
       \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
       \param num_digit = the number of digits to dial; the maximum limit is 32.
       \param digits = the digits to dial; ASCII chars 0 to 9, #, * only; with NULL termination.
       \param so = service option:
           \code
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
               }Diag_call_origination_serice_option_enum_type;
           \endcode

       \return true if the command was successfully sent, false if failed for any reason.

       \warning: A successful response message does not guarantee a successful call origination.
       Callers are responsible to verify the call state from either call processor or phone status logging as explained above.

       **/
   QLIB_API unsigned char QLIB_DIAG_CALL_ORIGINATION_REQUEST
   (HANDLE hResourceContext,
    unsigned char num_digit, unsigned char* digits, unsigned short so);

   /******************************************************************************/
   /**
   CDMA2000 Set the NV_FTM_MODE_I nv item value to either 0 or 1


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iMode = The mode can be either DMSS(0), or FTM(1). The default value is 0.
               The mode change will not take effect until the next phone reset.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_SET_MODE(
      HANDLE hResourceContext,
      unsigned char iMode);

   /******************************************************************************/
   /**
   Enables logging for the CDMA2000 non-signaling commands.  If this is not done, then
   the CDMA2000 NS commands will act only as simple request/response types.

   After this function is called, the cdma2000 non-signaling commands will wait
   for assocated events to occur, before returning.

   The log used to determine searcher state is: 0x119C, FTM_CDMA2000_SRC_TNG_STATUS

   The logs used to determine FER and SER are:
     0x10D9 - FTM_CDMA2000_RDA2_FRAME_INFO, for MSM6100 and later + SC1X and later
     0x10C9 - FTM_CDMA2000_RDA_FRAME_INFO, for MSM6000, MSM6025, MSM6050


   The logs used for AGC are FTM logs:
      LOG_FTM2_LOG_1X_AGC = 0x4
      LOG_FTM2_LOG_1X_AGC_C1   = 0x6

   After this function is called, then the library will begin collecting
   statistics (SER, AGC)


   The function QLIB_FTM_CDMA2000_NS_Stop() should be called when the the CDMA2000 NS
   testing is completed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param eDR_Type = Dymamic range type, defined by FTM_CDMA2000_NS_DR_Types_Enum in QLib_Defines.h
     \code
      0 = FTM_CDMA2000_NS_DR_85_3  = 85.3dB  dynamic range, min_rssi = -106.0dBm
      1 = FTM_CDMA2000_NS_DR_102_4 = 102.4dB dynamic range, min_rssi = -115.0dBm
     \endcode
   \param dTurnAroundConstant = cdma turn around constant, -73dBm for BC0, -76 for BC1.

   \param bEnableDiversityAGCLog = Enabling AGC Logging for diversity antenna
                           This should be set to 0 for non recieve diversity target
                           0 = Diversity AGC logging off
                           1 = Diversity AGC logging on

   \return true if successful, false if fail.

   \warning Will clear status and enable all CDMA2000 NS statistics, via
            FTM_CDMA2000_NS_SetStatisticsState()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_Start(
      HANDLE hResourceContext,
      unsigned char eDR_Type,
      double dTurnAroundConstant,
      unsigned char bEnableDiversityAGCLog);
   /******************************************************************************/
   /**
   This function is same as QLIB_FTM_CDMA2000_NS_Start except addtional flags can be used to
   NOT turn on RDA and Searcher package.

   If both flags, bEnableFTMLog and bEnableRDALog, are set to true, this function behaves exactly the same as
   QLIB_FTM_CDMA2000_NS_Start

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param eDR_Type = Dymamic range type, defined by FTM_CDMA2000_NS_DR_Types_Enum in QLib_Defines.h
     \code
      0 = FTM_CDMA2000_NS_DR_85_3  = 85.3dB  dynamic range, min_rssi = -106.0dBm
      1 = FTM_CDMA2000_NS_DR_102_4 = 102.4dB dynamic range, min_rssi = -115.0dBm
     \endcode
   \param dTurnAroundConstant = cdma turn around constant, -73dBm for BC0, -76 for BC1.

   \param bEnableDiversityAGCLog = Enabling AGC Logging for diversity antenna
                           This should be set to 0 for non recieve diversity target
                           0 = Diversity AGC logging off
                           1 = Diversity AGC logging on

   \param bEnableFTMLog = 0 = Not enabling FTM log
                          1 = Enable FTM log

   \param bEnableSearcherLog = 0 = Not enabling searcher log
                               1 = enabling searcher log

   \param bEnableRDALog = 0 = Not enabling RDA Log
                     1 = Enabling RDA log

   \return true if successful, false if fail.

   \warning Will clear status and enable all CDMA2000 NS statistics, via
            FTM_CDMA2000_NS_SetStatisticsState()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_Start_V2(
      HANDLE hResourceContext,
      unsigned char eDR_Type,
      double dTurnAroundConstant,
      unsigned char bEnableDiversityAGCLog,
      unsigned char bEnableFTMLog,
      unsigned char bEnableSearcherLog,
      unsigned char bEnableRDALog);


   /******************************************************************************/
   /**
   Disables logging for the CDMA2000 non-signaling commands.  This should be done
   after FTM_CDMA2000_NS_StartLogging() is called, and after all CDMA2000 NS testing is
   completed.

   QLIB_FTM_LOG_StopFTM_Log( HANDLE, LOG_FTM2_LOG_1X_AGC ) = stop the primary AGClog

   If diverisity was enabled then QLIB_FTM_LOG_StopFTM_Log( HANDLE, LOG_FTM2_LOG_1X_AGC_C1 ) to stop
   the diversity AGC log

   QLIB_DIAG_ClearAllLogCodes( HANDLE, LOG_EQUIP_ID_1X   ) to stop all RDA and searcher logs

   \return true if successful, false if fail.

   \warning The log mask for the 1X equipment ID will be cleared

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_Stop( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   Turn on or off logging for a certain type of 1xEV-DO non-signaling log

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eLogType = log type to control
      \code
          FTM_CDMA2000_NS_Log_Searcher,  //!<' CDMA2000 Searcher (LOG_CODE 0x119C)
          FTM_CDMA2000_NS_Log_AGC_C0,    //!<' FTM2 log, sub log 5, for Primary AGC
          FTM_CDMA2000_NS_Log_AGC_C1,    //!<' FTM2 log, sub log 7, for Diversity AGC
          FTM_CDMA2000_NS_Log_RDA2,      //!<' CDMA2000 (LOG_CODE 0x10D9), used for SER
          FTM_CDMA2000_NS_Log_RDA,       //!<' CDMA2000 (LOG_CODE 0x10C9), used for SER
      \endcode
   \param bEnableStatistics = true to enable statistics of the specified log type

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_SetStatisticsState(
      HANDLE hResourceContext,
      unsigned char eLogType,
      unsigned char bEnableStatistics);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling,

      Reset the entire internal status structure, including all averages

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bIgnore1stRDA = true to ignore the first RDA log, which may have bad data if the
                          signal generator settings were just changed.
   \return true if successful, false if failure

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_ClearStatus(
      HANDLE hResourceContext,
      unsigned char bIgnore1stRDA);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling,

      Reset the SER/FER internal status structure.  This will not affect
      the other status items, such as AGC

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if failure

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_ClearFER_Status(
      HANDLE hResourceContext);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling,
         Returns a copy of the internal state.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pCDMA2000_NS_State = reference to a FTM_CDMA2000_NS_Status_Struct structure that will be
                           filled in with the state information.
                     Structure type is FTM_CDMA2000_NS_Status_Struct, defined in QLib_Defines.h



   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_GetStatus(
      HANDLE hResourceContext,
      void* pCDMA2000_NS_State );


   /******************************************************************************/
   /**
   CDMA2000 Non-signaling,
         Sets the radio configuratoin and FCH rate set to be used for calculating SER.
         This function can also be used for setting up SER measurements in signaling
         mode.

         In signaling mode, the function QLIB_DIAG_CDMA2000_SetSER_State() should be
         used to control the capture of frame data and calculation of SER results.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eCurrentCDMA2000_RC = Radio configuration to be used. Of type FTM_CDMA2000_NS_FWD_RC_Enum
                                defined in QLib_Defines.h

   \param eCurrentCDMA2000_DataRate = FCH Data rate being used.  Of type  FTM_CDMA2000_NS_REV_FCH_Rates_Enum
                              defined in QLib_Defines.h


   \return true if set successfully

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_SetSER_RCandRS(
      HANDLE hResourceContext,
      unsigned long eCurrentCDMA2000_RC,
      unsigned long eCurrentCDMA2000_DataRate);


   /******************************************************************************/
   /**
   CDMA2000 Non-signaling
      Returns a subset of the cdma2000 NS status--the current FCH SER and FER with the
      option to set a minimum number.

      Will wait until a certain number of symbols or frames have been counted or a time out expires.

      If number of frames is the measurment matrics, set iMinimumNumSymbols = 0
      For example, Get number of FER/SER over 100 frames,

      FTM_CDMA2000_NS_Get_FCH_SER_FER(0,
                              100,
                              &iTotalSymbols,
                              &iTotalErrorSymbols,
                              &iTotalFrames,
                              &iTotalFrameErrors,
                              &dSER_Calculated,
                              &dFER_Calculated,
                              &iTimeOut_ms);

      If number of symbols is the measurement matrics, set iMinimumNumFrames = 0

      For example, Get number of FER/SER over 2000 symbols,

      FTM_CDMA2000_NS_Get_FCH_SER_FER(2000,
                              0,
                              &iTotalSymbols,
                              &iTotalErrorSymbols,
                              &iTotalFrames,
                              &iTotalFrameErrors,
                              &dSER_Calculated,
                              &dFER_Calculated,
                              &iTimeOut_ms);

      If instantenous SER/FER measurments are desired, set both iMinimumNumFrames and iMiniNumSymbols to 0

      if both iMinimumNumFrames and iMiniNumSymbols are non-zero, the function will return after both iMinimumNumFrames and
      iMinimumNumSymbols are reached.


   \param iMinimumNumSymbols = input, minimum number of symbols to capture, set 0
                               to specify there is no minimum number of symbols to wait for
   \param iMinimumNumFrames  = input, mimimum number of frames to capture, , set 0
                               to specify there is no minimum number of frames to wait for

                        If both iMinimumNumSymbols and iMinimumNumFrames  are set to zero then the
                        FER/SER status is returned immediately.

   \param iTotalSymbols = output, total number of symbols that have been recorded
   \param iTotalErrorSymbols = output, total symbol errors recorded
   \param iTotalFrames = output, total frames recorded
   \param iTotalFrameErrors = output, total number of frame errors
   \param dSER_Calculated = output, current SER, since the last time that statistics were cleared.
   \param dFER_Calculated = output, current FER, since the last time that statistics were cleared.
   \param iTimeOut_ms = input, number of milliseconds to wait for the number of symbols to exceed
                        iMinimumNumSymbols.  This time-out applies only when iMinimumNumSymbols > 0.

   \return true if all operations succeeded

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_NS_Get_FCH_SER_FER(
      HANDLE hResourceContext,
      unsigned long iMinimumNumSymbols,
      unsigned long iMinimumNumFrames,
      unsigned long* piTotalSymbols,
      unsigned long* piTotalErrorSymbols,
      unsigned long* piTotalFrames,
      unsigned long* piTotalFrameErrors,
      double* pdSER_Calculated,
      double* pdFER_Calculated,
      unsigned long iTimeOut_ms
   );


   /******************************************************************************/
   /**
   CDMA2000
      Returns a subset of the cdma2000 status--the Paging Channel Symbol Error Rate with the
      option to set a minimum number.

      Will wait until a certain number of symbols have been counted or a time out expires.


   \param iMinimumNumSymbols = input, minimum number of symbols to capture.
   \param piTotalSymbols = output, total number of symbols that have been recorded for paging channel
   \param piTotalErrorSymbols = output, total symbol errors recorded for paging channel
   \param pdPaging_SER_Calculated = output, iTotalErrorSymbols / iTotalSymbols (note, there's no 100 multiplied)

   \param iTimeOut_ms = input, number of milliseconds to wait for the number of symbols to exceed
                        iMinimumNumSymbols.  This time-out applies only when iMinimumNumSymbols > 0.

   \return true if all operations succeeded

   \warning this function calculates the paging channel symbol error rate instead of message error rate.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CDMA2000_Get_Paging_SER(
      HANDLE hResourceContext,
      unsigned long iMinimumNumSymbols,
      unsigned long* piTotalSymbols,
      unsigned long* piTotalErrorSymbols,
      double* pdPaging_SER_Calculated,
      unsigned long iTimeOut_ms );

   /******************************************************************************/
   /**
   CDMA2000
      Call MUX1X_DIAG_PAGING_STAT_F with bit mask 0,
      to clear the 1x MUX paging channel buffer on AMSS(ICD 80-V1294-23);
      Call MC_DIAG_STATE_QUERY_CMD with bit mask 0,
      to clear the 1x Call processing paging channel buffer on AMSS(ICD 80-V1294-20).
      these two buffers are used to calculate the Paging Channel Message Error Rate.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if all operations succeeded

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CDMA2000_Reset_Paging_MER_V2(
      HANDLE hResourceContext);

   /******************************************************************************/
   /**
   CDMA2000
      Call MUX1X_DIAG_PAGING_STAT_F with bit mask 7,
      to read the 1x MUX paging channel buffer on AMSS(ICD 80-V1294-23);
      Call MC_DIAG_STATE_QUERY_CMD with bit mask 7,
      to read the 1x Call processing paging channel buffer on AMSS(ICD 80-V1294-20).
      these two buffers are used to calculate the Paging Channel Message Error Rate.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piTotalNumPages = output, total number of pages that have been recorded for paging channel
   \param pdPaging_MER_Calculated = output, the error message / total * 100

   \return true if all operations succeeded

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CDMA2000_Get_Paging_MER_V2(
      HANDLE hResourceContext,
      unsigned long* piTotalNumPages,
      double* pdPaging_MER_Calculated);

   /******************************************************************************
   /**
   CDMA2000

   Get the transceiver resource manager (TRM) logs (LOG_CODE 0x12E8, See 80-V1294-1)
   User specifies the number of logs to be collected and a time out value.

   This function resets the internal buffer counter, starts the TRM log and stores the logs to the internal buffer
   The internal buffer size, CDMA2000_TRM_LOG_PACKET_BUFFER_SIZE, is defined in QLIB_Defines.h

   This function will not collect packet with Sub Packet ID 10 (Exchange) from the logs

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pTRMLogBuffer = [in/out] a pointer to user buffer of type CDMA2000_TRM_Log_Header

   \param iSzOfTRMLogBuffer = [in] The size of user buffer
                              [out]  The number of valid log packets returned to user

   \param iTimeOut_ms = [in]Timeout value in ms

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CDMA2000_Get_TRM_Logs(
      HANDLE hResourceContext,
      void*   pTRMLogBuffer,
      int*    iSzOfTRMLogBuffer,
      unsigned long iTimeOut_ms);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.1 Acquire pilot

   This function acquires pilot

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iBand_Class = Indicates the band class. Possible values are in FTM_CDMA2000_BandClasstype

      \code
          FTM_CDMA2000_BAND_BC0   = 0,
          FTM_CDMA2000_BAND_BC1   = 1,
          FTM_CDMA2000_BAND_BC2   = 2,
          FTM_CDMA2000_BAND_BC3   = 3,
          FTM_CDMA2000_BAND_BC4   = 4,
          FTM_CDMA2000_BAND_BC5   = 5,
          FTM_CDMA2000_BAND_BC6   = 6,
          FTM_CDMA2000_BAND_BC7   = 7,
          FTM_CDMA2000_BAND_BC8   = 8,
          FTM_CDMA2000_BAND_BC9   = 9,
          FTM_CDMA2000_BAND_BC10   = 10,
          FTM_CDMA2000_BAND_BC11   = 11,
          FTM_CDMA2000_BAND_BC12   = 12,
          FTM_CDMA2000_BAND_BC13   = 13,
          FTM_CDMA2000_BAND_BC14   = 14,
          FTM_CDMA2000_BAND_BC15   = 15,
          FTM_CDMA2000_BAND_BC16   = 16,
          FTM_CDMA2000_BAND_BC17   = 17
      \endcode
   \param iCDMA_Freq  = Indicates the RF channel number.
   \param iACQ_MODE   = Indicates the acquisition mode. Possible values are
      \code
            FTM_CDMA2000_NS_FTM_ACQ_MODE_FULL(0),
            FTM_CDMA2000_NS_FTM_ACQ_MODE_MINI(1),
            FTM_CDMA2000_NS_FTM_ACQ_MODE_MICRO(2).
       \endcode

   \return true if successful, false if fail.

   \warning If this call fails, then QLIB_FTM_CDMA2000_DEMOD_SYNC() should not be called.

   \note

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_PILOT_ACQ(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned long iAcq_Mode);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.1 Acquire pilot

   This function is the same as QLIB_FTM_CDMA2000_PILOT_ACQ except it returns the FTM_ERROR code from embedded side

   \param iFTM_Error = FTM Error code returned from embedded side

   \return true if successful, false if fail.

   \warning If this call fails, then QLIB_FTM_CDMA2000_DEMOD_SYNC() should not be called.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_PILOT_ACQ_V2(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned long iAcq_Mode,
      unsigned char* iFTM_Error);


   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.2 Acquire sync channel

         This function acquires sync channel

   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_PILOT_ACQ() must be called first, with a passing result.

   \note
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_DEMOD_SYNC(HANDLE hResourceContext);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.2 Acquire sync channel

   This function is as same as QLIB_FTM_CDMA2000_DEMOD_SYNC except it returns the FTM_ERROR code

   \param iFTM_Error = FTM Error code returned from embedded side

   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_PILOT_ACQ() must be called first, with a passing result.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_DEMOD_SYNC_V2(HANDLE hResourceContext, unsigned char *iFTM_Error);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.3 Assign forward fundamental channel

   This function assigns forward fundamental channel

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRadio_cfg   = Indicates the Radio Configuration of the F-FCH.
                  Possible values are:
      \code
          FTM_CDMA2000_NS_RC_1(1),
          FTM_CDMA2000_NS_RC_2(2),
          FTM_CDMA2000_NS_RC_3(3),
          FTM_CDMA2000_NS_RC_4(4),
          FTM_CDMA2000_NS_RC_5(5).
      \endcode
   \param iWalsh      = Indicates the Walsh code to be used for F-FCH.
   \param iQOF_Mask_id = Indicates the QOF index. Possible values are 0, 1, 2,and 3.
                     For FTM_FWD_RC1 and FTM_FWD_RC2, this field should be set to 0.
   \param iBypass_LC   = If set to TRUE, the long code mask is set to 0.
   \param iFrame_Offset = Indicates the frame offset for F-FCH.
   \param iSubchan_Gain  = Indicates the Power Control Subchannel Gain.
   \param iFFPC_enable = If set to TRUE, Fast Forward Power Control is enabled.
   \param iFPC_Mode   = Indicates the Forward Power Control Mode.
                    FPC_MODE is not currently used at this time.
   \param iInit_Setpt  = Indicates the initial setpoint for F-FCH.
   \param iOLC_Params_Target_FER = Indicates the target frame error rate for F-FCH.
   \param iOLC_Params_Min_Setpt = Indicates the minimum setpoint for F-FCH.
   \param iOLC_Params_Max_Setpt = Indicates the maximum setpoint for F-FCH.

   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() must be called first, with a passing result.

   \note
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_DEMOD_FCH(
      HANDLE hResourceContext,
      unsigned long iRadio_Cfg,
      unsigned char iWalsh,
      unsigned char iQOF_Mask_ID,
      unsigned char iBypass_LC,
      unsigned char iFrame_Offset,
      unsigned char iSubChan_Gain,
      unsigned char iFFPC_Enable,
      unsigned long iFPC_Mode,
      unsigned char iInit_Setpt,
      unsigned char iOLC_Params_Target_FER,
      unsigned char iOLC_Params_Min_Setpt,
      unsigned char iOLC_Params_Max_Setpt);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.3 Assign forward fundamental channel

   This function is same as QLIB_FTM_CDMA2000_DEMOD_FCH except it returns FTM_ERROR code from embedded side

   \param iFTM_Error = FTM Error code returned from embedded side

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() must be called first, with a passing result.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_DEMOD_FCH_V2(
      HANDLE hResourceContext,
      unsigned long iRadio_Cfg,
      unsigned char iWalsh,
      unsigned char iQOF_Mask_ID,
      unsigned char iBypass_LC,
      unsigned char iFrame_Offset,
      unsigned char iSubChan_Gain,
      unsigned char iFFPC_Enable,
      unsigned long iFPC_Mode,
      unsigned char iInit_Setpt,
      unsigned char iOLC_Params_Target_FER,
      unsigned char iOLC_Params_Min_Setpt,
      unsigned char iOLC_Params_Max_Setpt,
      unsigned char *iFTM_Error);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.4 Assign forward supplemental channel

   This function assigns forward supplemental channel

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRadio_cfg   = Indicates the Radio Configuration of the F-SCH.
                     Possible values are:
      \code
          FTM_CDMA2000_NS_RC_3(3),
          FTM_CDMA2000_NS_RC_4(4),
          FTM_CDMA2000_NS_RC_5(5).
      \endcode
   \param iWALSH      = Indicates the Walsh code to be used for F-SCH.
   \param iQOF_Mask_Id = Indicates the QOF index. Possible values are 0, 1, 2, and 3.
   \param iSch_Rate   = Indicates the data rate for F-SCH

    Possible values for the rate are 0 to 4 which correspond to
      \code
        FTM_RATE_1X (9.6 kbps)
        FTM_RATE_2X (19.2 kbps)
        FTM_RATE_4X (38.4 kbps)
        FTM_RATE_8X(76.8 kbps)
        FTM_RATE_16X (153.6 kbps)
       \endcode


      For turbo-encoded SCH, the possible values are:
       \code
        FTM_RATE_1X (9.6 kbps)
        FTM_RATE_2X (19.2 kbps)
        FTM_RATE_4X (38.4 kbps)
        FTM_RATE_8X(76.8 kbps)
        FTM_RATE_16X (153.6 kbps)
       \endcode
   \param iCoding_type = Indicates the coding type for F-SCH. Possible values are
      \code
         0 - FTM_SCH_CODING_CONVOLUTIONAL
         1 - FTM_SCH_CODING_TURBO
       \endcode
   \param iFFPC_Enable = Indicates whether Forward Power Control is to be enabled.
   \param iFPC_Mode   = Indicates the Forward Power Control Mode.
                    iFPC_MODE is not used at this time.
   \param iInit_Setpt   = Indicates the initial setpoint for F-SCH.
   \param iOLC_Params_Target_FER = Indicates the target frame-error rate for F-SCH.
   \param iOLC_Params_Min_Setpt = Indicates the minimum setpoint for F-SCH.
   \param iOLC_PARAMS_Max_Setpt = Indicates the maximum setpoint for F-SCH.

   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() must be called first, with a passing result.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_CDMA2000_DEMOD_FSCH(
      HANDLE hResourceContext,
      unsigned long iRadio_Cfg,
      unsigned char iWalsh,
      unsigned char iQPF_Mask_ID,
      unsigned long iSch_Rate,
      unsigned long iCoding_Type,
      unsigned char iFFPC_Enable,
      unsigned long iFPC_Mode,
      unsigned char iInit_Setpt,
      unsigned char iOLC_Params_Target_FER,
      unsigned char iOLC_Params_Min_Setpt,
      unsigned char iOLC_Params_Max_Setpt);


   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.5 Assign reverse fundamental channel

   This function assigns reverse fundamental channel

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRadio_cfg = Indicates the Radio Configuration for R-FCH.
                  Possible values are:
      \code
         1 = FTM_REV_RC1
       2 = FTM_REV_RC2
       3 = FTM_REV_RC3
       4 = FTM_REV_RC4
      \endcode
   \param iFrame_offset = Indicates the frame offset for R-FCH.
   \param iFCH_Rate   = Indicates the data rate for R-FCH. Possible values are
      \code
         0 = FTM_CDMA2000_NS_REV_FCH_FULL_RATE
         1 = FTM_CDMA2000_NS_REV_FCH_HALF_RATE
         2 = FTM_CDMA2000_NS_REV_FCH_QTR_RATE
         3 = FTM_CDMA2000_NS_REV_FCH_8TH_RATE
      \endcode
   \param iEnable_RPC   = If set to TRUE, Reverse Power Control is enabled.
   \param iNum_Preambles = Indicates the number of preambles that will be sent on R-FCH. One preamble = 20 ms.
   \param iTX_Pattern   =   Specifies the Tx pattern that is to be transmitted on R-FCH.
                     This pattern will be repeated every 4 bytes.

   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() must be called first, with a passing result.

   \note
   *******************************************************************************/


   QLIB_API unsigned char QLIB_FTM_CDMA2000_MOD_FCH(
      HANDLE hResourceContext,
      unsigned long iRadio_Cfg,
      unsigned char iFrame_Offset,
      unsigned long iFCH_Rate,
      unsigned char iEnable_RPC,
      unsigned short iNum_Preambles,
      unsigned long iTX_Pattern);


   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.5 Assign reverse fundamental channel

   This function is as same as QLIB_FTM_CDMA2000_MOD_FCH except it returns FTM_Error code

   \param iFTM_Error = FTM Error code returned from embedded side

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() must be called first, with a passing result.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/


   QLIB_API unsigned char QLIB_FTM_CDMA2000_MOD_FCH_V2(
      HANDLE hResourceContext,
      unsigned long iRadio_Cfg,
      unsigned char iFrame_Offset,
      unsigned long iFCH_Rate,
      unsigned char iEnable_RPC,
      unsigned short iNum_Preambles,
      unsigned long iTX_Pattern,
      unsigned char *iFTM_Error);


   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.6 Assign reverse supplemental channel

   This function assigns reverse supplemental channel

   \param iRadio_cfg = Indicates the Radio Configuration for R-SCH.
                  Possible value is FTM_REV_RC3(3).
   \param iSch_Rate  = Indicates the R-SCH data rate. Possible values are from 0 to 7 which correspond to
                       The enumeration, FTM_SCH_DataRates_Enum
       \code
       FTM_REV_SCH_1_5_RATE (0 = 1.5 kbps),
       FTM_REV_SCH_2_7_RATE (1 = 2.7 kbps),
       FTM_REV_SCH_4_8_RATE (2 = 4.8 kbps),
       FTM_REV_SCH_9_6_RATE (3 = 9.6 kbps),
       FTM_REV_SCH_19_2_RATE(4 = 19.2 kbps),
       FTM_REV_SCH_38_4_RATE (5 = 38.4 kbps),
       FTM_REV_SCH_76_8_RATE (6 = 76.8kbps), and
       FTM_REV_SCH_153_6_RATE (7 = 153.6kbps) respectively.
      \endcode

      Note that for turbo-encoded frames, the minimum supported rate is FTM_REV_SCH_19_2_RATE.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iCoding_type = Indicates the coding type for R-SCH. Possible values are:
      \code
         0 - FTM_SCH_CODING_CONVOLUTIONAL
         1 - FTM_SCH_CODING_TURBO
       \endcode

   \param iTX_Pattern = Specifies the Tx pattern for R-SC

   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() must be called first, with a passing result.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_CDMA2000_MOD_SCH(
      HANDLE hResourceContext,
      unsigned long iRadio_Cfg,
      unsigned long iSCH_Rate,
      unsigned long iCoding_Type,
      unsigned long iTX_Pattern);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.7 Enable loopback on the fundamental channel

   This command enables the loopback mode where all data received on the forward link is copied
   to the reverse link. The forward and reverse fundamental channels must already be set up before
   loopback mode is requested. The rate of the reverse link matches the forward link. In the case
   where an erasure is received on the forward link, a full rate frame of all zeros is sent on the
   reverse link.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning FTM_CDMA2000_DEMOD_FCH and FTM_CDMA2000_MOD_FCH must be called first

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_CDMA2000_FCH_LOOPBACK( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.8 Enable loopback on the supplemental channel

   This command enables the SCH loopback mode. The forward and reverse supplemental channels
   should already be set up to the same rate.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() and QLIB_FTM_CDMA2000_MOD_SCH must be
            called first, with a passing result.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_SCH_LOOPBACK( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.9 Deassign all traffic channels

   This command releases all traffic channels and leaves the phone ready to acquire a pilot.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_CMD_RELEASE( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.9 Deassign all traffic channels

   This function is same as QLIB_FTM_CDMA2000_CMD_RELEASE except it returns FTM error code from embedded side

   \param iFTM_Error = FTM Error code returned from AMSS

   \return true if successful, false if fail.

   \warning

   \note The function can be used with FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_CMD_RELEASE_V2( HANDLE hResourceContext, unsigned char* iFTM_Error );



   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command

   This command calls pilot acquistion, synchronization and forward fundamental assignment in order.
   Specifically, these functions are called:
      QLIB_FTM_CDMA2000_PILOT_ACQ()
      QLIB_FTM_CDMA2000_DEMOD_SYNC()
      QLIB_FTM_CDMA2000_DEMOD_FCH()

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iBand_Class, Band Class number (1=BC1)
   \param iCDMA_Freq,  CDMA channel number
   \param iRadio_Cfg,  Indicates the Radio Configuration of the F-FCH.
                  Possible values are:
      \code
         1 = FTM_FWD_RC_1
       2 = FTM_FWD_RC_2
       3 = FTM_FWD_RC_3
         4 = FTM_FWD_RC_4
       5 = FTM_FWD_RC_5
      \endcode
   \param iWalsh      Wash code to be used for F-FCH
   \param iFFPC_Enable   If set to TRUE, Fast Forward Power Control is enabled.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_GOTO_FWD_TRAFFIC_STATE(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned long iRadio_Cfg,
      unsigned char iWalsh,
      unsigned char iFFPC_Enable );

   /******************************************************************************/
   /**

   CDMA2000 Non-signaling command 3.2.10 Assign forward dedicated control channel

   This command assigns forward dedicated control channel

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRadio_Cfg = Indicates the Radio Configuration of the F-FCH.
                                 Possible values are FTM_FWD_RC_3(3), FTM_FWD_RC_4(4), and FTM_FWD_RC_5(5).
   \param iWalsh     = Indicates the Walsh code to be used for F-FCH.
   \param iQof_Mask_Id = Indicates the QOF index. Possible values are 0, 1, 2, and 3.
                                    For FTM_FWD_RC1 and FTM_FWD_RC2, this field should be set to 0.
   \param iBypass_Lc = If set to TRUE, the long code mask is set to 0.
   \param iSo_Pri = Indicates the primary service option.
   \param iSo_Sec = Indicates the secondary service option
   \param iFrame_Offset = Indicates the frame offset for F-DCCH.
   \param iIlpc_Enable = If set to TRUE, the inter loop power control is enable.
   \param iOlpc_Enable = If set to TRUE, the open loop power control is enable.
   \param iInit_Setpt = Indicates the Initial setpoint for F-DDCH.
   \param iFpc_Subchan_Gain = Forward Power control sub-chan gain
   \param iOlc_Params_Target_Fer = Indicates the target frame-error rate for F-DCCH.
   \param iOlc_Params_Min_Setpt = Indicates the minimum setpoint for F-DCCH.
   \param iOlc_Params_Max_Setpt = Indicates the maximum setpoint for F-DCCH.

   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() must be called first, with a passing result.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_DEMOD_DCCH   (   HANDLE hResourceContext,
         unsigned long iRadio_Cfg,
         unsigned char iWalsh,
         unsigned char iQof_Mask_Id,
         unsigned char iBypass_Lc,
         unsigned short iSo_Pri,
         unsigned short iSo_Sec,
         unsigned char iIlpc_Enable,
         unsigned char iOlpc_Enable,
         unsigned char iFpc_Subchan_Gain,
         unsigned char iOlc_Params_Target_Fer,
         unsigned char iOlc_Params_Min_Setpt,
         unsigned char iOlc_Params_Max_Setpt);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.11 Assign reverse dedicated control channel

   This command assigns reverse dedicated control channel

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRadio_Cfg = Indicates the Radio Configuration for R-DCCH.
                                 Possible values are FTM_REV_RC3(3) and FTM_REV_RC4(4).
   \param iFrame_Offset - Indicates the frame offset for R-DCCH.
   \param iSch_On = If set to TRUE, the SCH is enabled.
   \param iSch_Rc = Indicates the Radio Configuration of the F-SCH.
                           Possible values are FTM_FWD_RC_3(3), FTM_FWD_RC_4(4).
   \param iSch_Turbo = Indicates the coding type for SCH. Possible values
                              are FTM_CODING_CONVOLUTIONAL(0) and FTM_CODING_TURBO(1).
   \param iSch_Ltu_Size = Indicates the logical transition unit size
   \param iSch_Rate = Indicates the data rate for SCH.
                       Possible values for
      \code
        FTM_RATE_1X (9.6 kbps)
        FTM_RATE_2X (19.2 kbps)
        FTM_RATE_4X (38.4 kbps)
        FTM_RATE_8X(76.8 kbps)
        FTM_RATE_16X (153.6 kbps)
      FTM_RATE_32X (5 = 307.2 kbps)
       \endcode

         For turbo-encoded SCH, the possible values are FTM_RATE_2X, FTM_RATE_4X, FTM_RATE_8X,
         FTM_RATE_16X and FTM_RATE_32X.
   \param iNum_Preambles = Indicates the number of preambles that will be sent on R-DCCH. One preamble = 20 ms.
   \param iTx_Pattern = Specifies the Tx pattern that is to be transmitted on R-DCCH. This pattern will be
                                 repeated every 4 bytes.

   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC() must be called first, with a passing result.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_MOD_DCCH(   HANDLE hResourceContext,
         unsigned long iRadio_Cfg,
         unsigned char iFrame_Offset,
         unsigned char iSch_On,
         unsigned long iSch_Rc,
         unsigned char iSch_Turbo,
         unsigned short iSch_Ltu_Size,
         unsigned long iSch_Rate,
         unsigned short iNum_Preambles,
         unsigned long iTx_Pattern);
   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.2.12 Enable loopback on the dedicated control channel

   This command enables loopback on the dedicated control channel

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning QLIB_FTM_CDMA2000_DEMOD_SYNC(), QLIB_FTM_CDMA2000_MOD_DCCH(),  and
            QLIB_FTM_CDMA2000_DEMOD_DCCH() must be called first, each with a passing result.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_DCCH_LOOPBACK(HANDLE hResourceContext);

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.3.15 Handover

   This function will command the mobile to a new band class and channel number.

   The FTM code for this function was added in December 2006, long afer the
   original cdma2000 non-signaling commands were in FTM.  If the command fails,
   it is quite possible that embedded software does not support it.

   In order to verify the RF channel has been changed, this function uses
   QLIB_DIAG_IS2000_STATUS_F() to check the mobile status for the band class
   and channel number.  If the mobile does not report the new numbers, then a
   this function will also fail.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iBand_Class = Indicates the band class. Possible values are in FTM_CDMA2000_BandClasstype
                  See QLIB_FTM_CDMA2000_PILOT_ACQ() for the full list.
   \param iCDMA_Freq  = Indicates the RF channel number.
   \param iEnable_RPC = 1 to enable reverse link power control (RPC), 0 to disable RPC

   \return true if successful, false if fail.

   \warning This must be called only after the QLIB_FTM_CDMA2000_DEMOD_FCH() is called successfully

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_FTM_FWD_HHO_SC(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned char iEnable_RPC
   );

   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.3.15 Handover

   This function is same as  QLIB_FTM_CDMA2000_FTM_FWD_HHO_SC except it returns FTM Error code

   \param iFTM_Error = FTM Error code returned from embedded side

   \return true if successful, false if fail.

   \warning This must be called only after the QLIB_FTM_CDMA2000_DEMOD_FCH() is called successfully

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_FTM_FWD_HHO_SC_V2(
      HANDLE hResourceContext,
      unsigned long iBand_Class,
      unsigned short iCDMA_Freq,
      unsigned char iEnable_RPC,
      unsigned char *iFTM_Error
   );


   /******************************************************************************/
   /**
   CDMA2000 Non-signaling command 3.3.16 Set reverse link power

   This function overrides the reverse link power control with CDMA2000 NS mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iPower_Type = Indicates the power control method.
                   Possible values are in FTM_CDMA2000_NS_Set_Rev_Power_Type_Enum listed in QLib_Defines.h

   \param iRev_Pwr_indBm10  = Indicates the power level in 10/dBm units as signed number.
                   This field is used only when iPower_Type is set to FTM_1X_TX_POWER_TYPE_AGC_SETPOINT

                   For example, to set 24dBm, 240 should be used

   \return true if successful, false if fail.

   \warning This function should be called only a NS call has been established successfully

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_SET_REV_PWR(
      HANDLE hResourceContext,
      unsigned char iPower_Type,
      long iRev_Pwr_indBm10
   );
   /******************************************************************************/
   /**
   cdma2000 Non-signaling command x.x.xx Reset fowrward link FER/SER statistics

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function should be called only a NS call has been established successfully

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_RESET_FCH_STAT(   HANDLE hResourceContext );
   /******************************************************************************/
   /**
   cdma2000 Non-signaling command x.x.xx Get fowrward link FER/SER statistics

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNumFrame = Total packets since the counter set

   \param iFrameError = Total number of error packets since last counter reset

   \param dFER =   Frame error rate (iFrameError/iNumFrame * 100).
               999.0 is returned if the target does not support the command

   \param iNumSymboal = Total number of symbol in FCH channel

   \param iSymbolError = Total number of symbol error in FCH channel

   \param dSER = Symbol Error Rate (iSymbolError/iNumSymbol * 100)
              999.0 is returned if the target does not support the command

   \return true if successful, false if fail.

   \warning This function should be called only a NS call has been established successfully

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_GET_FCH_STAT(   HANDLE hResourceContext,
         unsigned long* iNumFrame,
         unsigned long* iFrameError,
         double* dFER,
         unsigned long* iNumSymbol,
         unsigned long* iSymbolError,
         double* dSER);
   /******************************************************************************/
   /**
   cdma2000 Non-signaling command x.x.xx Get fowrward link FER/SER statistics

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRxChain = 0 - Primary Rx
                     1 - Secondary Rx

   \param iStatus = 0 - FTM_SUCCESS
                    1 - FTM_INVALID_CMD
                2 - FTM_INVALID_STATE
                3 - FTM_NO_SUCCESS

    \param iRxAGC = Rx AGC value

   \param iRxPowerdBm = output value, Rx power in 1/10 dBm units
                        this is a signed value

   \return true if successful, false if fail.

   \warning This function should be called only a NS call has been established successfully

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA2000_RX_LEVEL_REQ(   HANDLE hResourceContext,
         unsigned char iRxChain,
         unsigned char* iStatus,
         short *iRxAGC,
         short *iRxPowerdBm);


   /******************************************************************************
               SHDR - SGPS Subsystem
   *******************************************************************************/
   /**
   Enables measurement logs for the SHDR/ SGPS Testing.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iLogMask =    The logs can be enabled with a bit mask as defined by FTM_SHDR_MeasurementLogs_Enum.

      The mask values are as follows:
      \code
               0x01 = TRM Response (0x12E8)
               0x02 = 1x Paging MER Log
               0x04 = 1x FTM AGC log for Primary chain
               0x08 = 1x FTM AGC log for Secondary chain
               0x16 = EVDO FTM AGC log for Primary chain
               0x32 = EVDO FTM AGC log for Secondart chain
      \endcode

   \return true if successful, false if fail.

   \warning Will clear status of all the enabled logs

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SHDR_SGPS_EnableMeasurementLogs(
      HANDLE hResourceContext,
      unsigned char iLogMask );
   /*******************************************************************************/
   /**
   Gets measurement logs for the SHDR/ SGPS Testing.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pSHDR_SGPS_MeasLogs

   \return true if successful, false if fail.

   \warning Will clear status of all the enabled logs

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SHDR_SGPS_GetMeasurementLogs(
      HANDLE hResourceContext,
      void* pSHDR_SGPS_MeasLogs,
      long log_mask);

   /******************************************************************************/

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_CDMA2000_NS_H)
