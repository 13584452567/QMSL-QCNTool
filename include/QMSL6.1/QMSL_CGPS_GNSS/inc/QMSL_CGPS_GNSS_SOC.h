/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_CGPS_GNSS/inc/QMSL_CGPS_GNSS_SOC.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QLib library routines for the GNSS_SOC system
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_CGPS_GNSS_SOC_H)
#define _QMSL_CGPS_GNSS_SOC_H

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
                     GNSS_SOC DIAG
   *******************************************************************************/

   QLIB_API unsigned char QLIB_DIAG_GNSS_SOC_START_IQ_TEST_CollectResults(
   HANDLE hResourceContext,
   void* pGPS_StartIQ_TestParams,
   char* sIQ_FileName,
   char* sFFT_FileName,
   unsigned char* piStatus);


   QLIB_API unsigned char QLIB_DIAG_GNSS_SOC_START_NBIQ_TEST(HANDLE hResourceContext,
                                              void *pGPS_StartIQ_TestParams,
                                              char *sIQ_FileName,
                                              char *sFFT_FileName,
                                              unsigned char *piStatus); 

   /******************************************************************************/
   /**
   This function instructs the GNSS_SOC engine to enter "Standalone RF verification" mode
   and waits for the associated event, EVENT_GPS_LM_ENTER_SA_RF_VERIF #1247

   The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
   timeout type of QMSL_Timeout_CGPS_Event.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iFlag = input
   \code
        0 = GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE = Enter SA-RF Verif Mode,
      1 = GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE  = Exit SA-RF Verif Mode
         Refer to the enumeration below for bit mask definitions:

            typedef enum
            {
               GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE         = 0x00, // Enter Standalone RF verification mode
               GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE          = 0x01  // Exit Standalone RF verification mode
            } gps_sa_rf_verif_mode_switch_enum_type;
   \endcode
   \param piStatus = output, 0=Command Accepted, 1=Command Rejected

   \return true if successful, false if fail.

   \warning The asynchronous message queue will be cleared in the course of executing this function

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GNSS_SOC_SA_RF_VERIF_MODE_SWITCH_WithWait(
      HANDLE hResourceContext,
      unsigned char iFlag,
      unsigned char* piStatus
   );


   /******************************************************************************/
   /**

   This function instructs the CGPS GNSS_SOC engine to track a single GNSS SV as specified
   by SvTrackParams input parameters. The test can also be stopped using appropriate
      command parameters.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
   \param SvTrackParams   = input. A structure containing Multi-Channel Tracking Test parameters.  Please refer to GNSS_SOC_SINGLE_SvTrack_Struct_type in QLib_Defines.h
      \endcode

   \param piStatus                  = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GNSS_SOC_SINGLE_SV_TRACK(
      HANDLE hResourceContext,
      void *SvTrackParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function instructs the CGPS GNSS_SOC engine to track GNSS SV's as specified
   by SvTrackParams input parameters. The test can also be stopped using appropriate
      command parameters.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
   \param SvTrackParams   = input. A structure containing Multi-Channel Tracking Test parameters.  Please refer to CGPS_Gen8_SvTrack_Struct_type in QLib_Defines.h
      \endcode

   \param piStatus                  = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GNSS_SOC_GEN8_SV_TRACK(
      HANDLE hResourceContext,
      void *SvTrackParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
      Clear the status of the entire CGPS status object
      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \return Returns true if successful, false if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_SOC_ClearStatus( HANDLE hResourceContext );

   /******************************************************************************/
   /**
      Clear a specific status element of the CGPS status

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
      \param eStat = the type of status to clear, type is QMSL_CGPS_Event_Enum from QLibDefines.h
      \return Returns true if successful, false if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_SOC_ClearStatus_Specific( HANDLE hResourceContext, unsigned long eStat );

   /******************************************************************************/
   /**
      Copy the status into the user supplied GSM BER Status structure

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
      \param pCGPS_Status is a structure of type "CGPS_Status_Struct*"

      \return Returns true if successful, false if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_SOC_GetStatus( HANDLE hResourceContext, void* pCGPS_Status );

   /******************************************************************************/
   /**
      Calculate FFT based on the IQ data.

      Call QLIB_CGPS_GetFFT_CalculatedData to get the results

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

      \return Returns true if successful, false if fail or number of FFT samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_SOC_CalculateFFT_Data( HANDLE hResourceContext );

   /******************************************************************************/
   /**
      Returns the FFT Calculated data from the last IQ Capture.  Measured means that this is
      the data reported by the mobile, via the IQ Data Log, ( CGPS_IQ_DATA_LOG, 0x138A)

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
      \param pFFT_Amplitude = OUTPUT, pointer to buffer to store FFT samples, the size of the array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
      \param pFFT_Frequency = OUTPUT, frequency associated with each element in the pFFT_Amplitude array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
      \param iNumSamples = OUTPUT, returns the number of samples that were written into the pFFT_Samples array

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() and QLIB_CGPS_CalculateFFT_Data() must be called first.

      \return Returns true if successful, false if fail or number of FFT samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_SOC_GetFFT_CalculatedData(
      HANDLE hResourceContext,
      double* pFFT_Amplitude,
      double* pFFT_Frequency,
      unsigned long* iNumSamples
   );

      /******************************************************************************/
   /**
      Returns the processed IQ data for the last IQ Capture. The processing includes adding 0.5
      to the I and Q samples and replacing each 2046th and each 20487h sample with 0.

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \param hResourceContext = INPUT, pointer to buffer to store processed I samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
      \param pQ_ProcessedSamples = INPUT, pointer to buffer to store processed Q samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
      \param pNumProcessedSamples = OUTPUT, returns the number of processed samples that were written into the pI_ProcessedSamples and pQ_ProcessedSamples arrays.

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

      \return Returns true if successful, false if fail or number of IQ samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_sOC_GetProcessedIQ_Data(
      HANDLE hResourceContext,
      double* pI_ProcessedSamples,
      double* pQ_ProcessedSamples,
      unsigned long* pNumProcessedSamples
   );

   /******************************************************************************/
   /**
      Returns the processed IQ data for the last IQ Capture. The processing includes adding 0.5
      to the I and Q samples and replacing each 2046th and each 20487h sample with 0.

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \param hResourceContext = INPUT, pointer to buffer to store processed I samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
      \param pQ_ProcessedSamples = INPUT, pointer to buffer to store processed Q samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
      \param pNumProcessedSamples = OUTPUT, returns the number of processed samples that were written into the pI_ProcessedSamples and pQ_ProcessedSamples arrays.

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

      \return Returns true if successful, false if fail or number of IQ samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_SOC_GetProcessedIQ_Data(
      HANDLE hResourceContext,
      double* pI_ProcessedSamples,
      double* pQ_ProcessedSamples,
      unsigned long* pNumProcessedSamples
   );

   #ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_CGPS_GNSS_SOC_H)
