/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Core/inc/QMSL_FTM_Log.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_Log
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QLIB_FTM_LOG_H)
#define _QLIB_FTM_LOG_H

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
                     FTM Log
   *******************************************************************************/
   /******************************************************************************/
   /**
   FTM Log, 3.1 FTM enable log

      FTM log packets are enabled with the FTM_LOG_ENABLE request. The parameters to this
      request are the ID of the FTM log to enable, the periodicity of log packet generation, and the
      number of readings to be included in each log packet. To reduce log bandwidth, several readings
      can be buffered into a single log packet and sent as a single burst.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iLogCode - FTM Log packet number
   \param iInterval - Time (in ms) between subsequent log packets
   \param iNumBuffers - Number of buffers per log packet

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOG_ENABLE(
      HANDLE hResourceContext, unsigned short iLogCode, unsigned long iInterval, unsigned long iNumBuffers  );


   /******************************************************************************/
   /**
   FTM Log, 3.2 FTM disable log
      An FTM log is disabled with the FTM_LOG_DISABLE command.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iLogCode - FTM Log packet number

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOG_DISABLE( HANDLE hResourceContext, unsigned short iLogCode );

   /******************************************************************************/
   /**
   High level function to activate logging for a specific FTM2 log.  This function
   also turns on QMSL logging and sets up the phone's log filter to allow
   the FTM2 log to be generated.

   The operations called are:
      QLIB_FTM_LOG_ENABLE
      QLIB_DIAG_SetExtendedLogCode
      QLIB_DIAG_SetPhoneLoggingState
      QLIB_DIAG_ClearPhoneLogQueue

   \param iFTM_LogCode = FTM Log code, such as LOG_FTM2_LOG_WCDMA_BER or LOG_FTM2_LOG_PRINTF

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOG_StartFTM_Log( HANDLE hResourceContext, unsigned short iFTM_LogCode);

   /******************************************************************************/
   /**
   High level function to set the number of buffers to be used for all FTM LOG ENABLE
   operations which call QLIB_FTM_LOG_StartFTM_Log().  This includes:
   \code
        QLIB_FTM_CDMA2000_NS_Start()
        QLIB_FTM_EVDO_NS_Start()
        QLIB_FTM_WCDMA_BER_StartSession()
        QLIB_FTM_GSM_BER_StartSession()
   \endcode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iNumBuffersPerLog = Number of buffers per log packet

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOG_SetFTM_LogBufferCount( HANDLE hResourceContext, unsigned long iNumBuffersPerLog );

   /******************************************************************************/
   /**
   High level function to disable logging for a specific FTM2 log.  This function
   also turns off QMSL logging.

   The operations called are:
      FTM_LOG_DISABLE
      DIAG_SetPhoneLoggingState
      DIAG_ClearPhoneLogQueue

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iFTM_LogCode = FTM Log code, such as LOG_FTM2_LOG_WCDMA_BER or LOG_FTM2_LOG_PRINTF

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOG_StopFTM_Log( HANDLE hResourceContext, unsigned short iFTM_LogCode);

   /******************************************************************************/
   /**
   High level function to return the most recently received log report, or if no report
   is in the async queue, then the function will wait up-to a specified amount of time
   for a report to be received.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iFTM_LogCode = FTM Log code, such as LOG_FTM2_LOG_WCDMA_BER or LOG_FTM2_LOG_PRINTF
   \param pFTM2LogMessage = pointer to a structure of FTM2LogMessage type (defined in QLib_Defines.h).
          If a lot message is found, the FTM2-specific section will be copied into this
         structure.
   \param piLogSize = number of bytes copied into the pFTM2LogMessage structure

   \param iTimeOut_ms = millisecond time-out. If not log code is detected by the time this
                        expires, then the return value will be false.


   \return true if a log was found, false if one was not found.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOG_WaitForNextLog(
      HANDLE hResourceContext,
      unsigned short iFTM_LogCode,
      void* pFTM2LogMessage,
      unsigned short* piLogSize,
      unsigned long iTimeOut_ms );

   /******************************************************************************/
   /**
   Used for cdma2000, 1xEV-DO and WCDMA

   Waits until a certain number of a specified metric has been completed.
   The metric can be:
   \code
         - cdma2000 primary or secondonary AGC
       - 1xEV-DO primary or secondonary AGC
       - 1xEV-DO primary or secondary C/I
       - WCDMA primary or secondonary AGC
   \endcode

   The algorithm will wait until a certain number number of metrics has been recieved.  Two different types of
   metrics can be specified and the code will not return until both conditions are satisfied (e.g. a certain
   number of C2I and a certain number of AGC records)

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param eMetric1Type = input, specification of the type of metric (mode | agc/c2i / antenna ), defined by QMSL_WaitForMetric_Types
      \code
        QMSL_WaitForMetric_cdma2000_AGC_C0,      //!<' cdma2000 AGC C0
        QMSL_WaitForMetric_cdma2000_AGC_C1,     //!<' cdma2000 AGC C1
        QMSL_WaitForMetric_evdo2000_AGC_C0,     //!<' 1xEV-DO AGC C0
        QMSL_WaitForMetric_evdo2000_AGC_C0,     //!<' 1xEV-DO AGC C1
        QMSL_WaitForMetric_evdo2000_C2I_C0,     //!<' 1xEV-DO C/I C0
        QMSL_WaitForMetric_evdo2000_C2I_C1,     //!<' 1xEV-DO C/I C1
        QMSL_WaitForMetric_evdo2000_C2I_Both_C0_C1,  //!<' 1xEV-DO C/I, both C0 and C1
      QMSL_WaitForMetric_Max                  //!<' Maximum number
      \endcode


   \param eMetric2Type = input, specification of the type of metric (mode | agc/c2i / antenna ), defined by QMSL_WaitForMetric_Types
                     Use QMSL_WaitForMetric_Max to specify no check for the 2nd metric type

   \param iMetric1MinimumCount = input, minimum number of records to capture for eMetric1Type.
   \param iMetric2MinimumCount = input, minimum number of records to capture for eMetric2Type,
                           disregarded if eMetric2Type == QMSL_WaitForMetric_Max
   \param iInterLogTimeOut_ms = input, number of milliseconds to wait between the receipt of each log.
                           Separate timeout counters are maintained for each metric type.

   \return true if all operations succeeded and the total number of records is found for both conditions.

   \warning After this function is called, the data structured must be retrieved from QMSL using the

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WaitForMetric(
      HANDLE hResourceContext,
      unsigned long eMetric1Type,
      unsigned long eMetric2Type,
      unsigned long iMetric1MinimumCount,
      unsigned long iMetric2MinimumCount,
      unsigned long iInterLogTimeOut_ms
   );



#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_LOG_H)

