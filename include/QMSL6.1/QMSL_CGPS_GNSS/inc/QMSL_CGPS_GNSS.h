/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_CGPS_GNSS/inc/QMSL_CGPS_GNSS.h#9 $
 * $DateTime: 2015/10/29 15:54:50 $
 *
 * DESCRIPTION: QLib library routines for the CGPS and GNSS 
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_CGPS_GNSS_H)
#define _QMSL_CGPS_GNSS_H

#if !defined(_WINDOWS_)
#include "windows.h"
#endif

#include "QMSL_CGPS_GNSS_SOC.h"

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
                  CGPS DIAG
*******************************************************************************/

/******************************************************************************/
/**
This function instructs the CGPS engine to enter "Standalone RF verification" mode.


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

\warning This version of the function does not wait for the associated event.
         Use QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait() to wait for the event.

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH(
   HANDLE hResourceContext,
   unsigned char iFlag,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to enter "Standalone RF verification" mode
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
QLIB_API unsigned char QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait(
   HANDLE hResourceContext,
   unsigned char iFlag,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to perform one dwell on one channel.

This command will check the status field and return false if the command was rejected.

\param hResourceContext = Resource context that was returned from the call to ConnectServer()
\param iFlags            = input, Enables different functionalities
                    Refer to these enumerations for bit mask definitions:
   \code
         typedef enum
         {
            GPS_PRESCRIBED_DWELL_NO_RESULTS            = 0x00, // Do not send dwell results
            GPS_PRESCRIBED_DWELL_SEND_RESULTS          = 0x01  // Send dwell results
         } gps_prescribed_dwell_results_enum_type;   //Bit 0

         typedef enum
         {
            GPS_PRESCRIBED_DWELL_CHIPX1                = 0x00, // Chipx1
            GPS_PRESCRIBED_DWELL_CHIPX2                = 0x02  // Chipx2
         } gps_prescribed_dwell_chip_rate_enum_type; //Bit 1

         typedef enum
      {
             GPS_PRESCRIBED_DWELL_NO_INCOHER_SUMS     = 0x00, // Do not report incoherent sums
             GPS_PRESCRIBED_DWELL_REPORT_INCOHER_SUMS  = 0x04  // Report incoherent sums
         } gps_prescribed_dwell_incoher_sums_enum_type; //Bit 2

         typedef enum
         {
             GPS_PRESCRIBED_DWELL_NO_COHER_SUMS       = 0x00, // Do not report coherent sums
             GPS_PRESCRIBED_DWELL_REPORT_COHER_SUMS    = 0x08  // Report coherent sums
         } gps_prescribed_dwell_coher_sums_enum_type; //Bit 3

         typedef enum
      {
             GPS_PRESCRIBED_DWELL_START_NOW           = 0x00, // Start now
             GPS_PRESCRIBED_DWELL_USE_TOA              = 0x0A  // Use TOA
         } gps_prescribed_dwell_start_time_enum_type; //Bit[5:4]

         typedef enum
         {
             GPS_PRESCRIBED_DWELL_USE_RF              = 0x00, // Use RF
             GPS_PRESCRIBED_DWELL_USE_TS               = 0x40  // Use TS
         } gps_prescribed_dwell_source_enum_type; //Bit 6

         typedef enum
         {
             GPS_PRESCRIBED_DWELL_NO_INIT             = 0x00, // Do not initialize TS and BC at starte of dwell
             GPS_PRESCRIBED_DWELL_INIT_TS_AND_BC       = 0x80  // Initialize TS and BC at start of dwell
         } gps_prescribed_dwell_source_init_type; //Bit 7
   \endcode
\param iTOA              = input, Time of Applicability. GPS_RTC time at which dwell must start.
\param iSV               = input, Satellite PRN [0..32]. If zero, correlation is codeless.
\param iSearchMode       = input, Pre-Detection Mode.
\param iPOST_DET_N       = input, Number of Post-Detection.
\param iTASK_MASK1       = input, Bit31:Bit0 - Task32:Task1. A set bit implies that that task must be selected.
\param iTASK_MASK2       = input, Bit7:Bit0 - Task40:Task33. A set bit implies that that task must be selected.
\param iDOPP_FREQ        = input, Signed (1000/65536 Hz/Bit). Range: -32768000 to +32768000 Hz.
\param iDOPP_FREQ_RATE   = input, Signed (1000/65536 Hz/sec/Bit). Range: -32768000 to +32768000 Hz/sec.
\param iSUB_MS           = input, Unsigned (1/256 Chips/Bit). Range: 0 to 1023 chips.
\param iCNO_Threshold    = input, Used for declaring dwell as a detection. Dwell result DM packet.
                    will be send only if CNo exceeds this threshold. Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.
\param iJammerThreshold  = input, Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.

\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning This version of the function does not wait for the response event. To wait for
         the event use QLIB_DIAG_GPS_PRESCRIBED_DWELL_WithWait

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_PRESCRIBED_DWELL(
   HANDLE hResourceContext,
   unsigned short iFlags,
   unsigned long iTOA,
   unsigned char iSV,
   unsigned char iSearchMode,
   unsigned short iPOST_DET_N,
   unsigned long iTASK_MASK1,
   unsigned char iTASK_MASK2,
   unsigned long iDOPP_FREQ,
   unsigned long iDOPP_FREQ_RATE,
   unsigned long iSUB_MS,
   unsigned short iCNO_Threshold,
   unsigned short iJammerThreshold,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to perform one dwell on one channel, then
wait for the corresponding event, EVENT_GPS_LM_PD_COMPLETE, #1250.

The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
timeout type of QMSL_Timeout_CGPS_Event.

This command will check the status field and return false if the command was rejected.

\param hResourceContext = Resource context that was returned from the call to ConnectServer()
\param iFlags            = input, Enables different functionalities
                    Refer to these enumerations for bit mask definitions:
   \code
         typedef enum
         {
            GPS_PRESCRIBED_DWELL_NO_RESULTS            = 0x00, // Do not send dwell results
            GPS_PRESCRIBED_DWELL_SEND_RESULTS          = 0x01  // Send dwell results
         } gps_prescribed_dwell_results_enum_type;   //Bit 0

         typedef enum
         {
            GPS_PRESCRIBED_DWELL_CHIPX1                = 0x00, // Chipx1
            GPS_PRESCRIBED_DWELL_CHIPX2                = 0x02  // Chipx2
         } gps_prescribed_dwell_chip_rate_enum_type; //Bit 1

         typedef enum
      {
             GPS_PRESCRIBED_DWELL_NO_INCOHER_SUMS     = 0x00, // Do not report incoherent sums
             GPS_PRESCRIBED_DWELL_REPORT_INCOHER_SUMS  = 0x04  // Report incoherent sums
         } gps_prescribed_dwell_incoher_sums_enum_type; //Bit 2

         typedef enum
         {
             GPS_PRESCRIBED_DWELL_NO_COHER_SUMS       = 0x00, // Do not report coherent sums
             GPS_PRESCRIBED_DWELL_REPORT_COHER_SUMS    = 0x08  // Report coherent sums
         } gps_prescribed_dwell_coher_sums_enum_type; //Bit 3

         typedef enum
      {
             GPS_PRESCRIBED_DWELL_START_NOW           = 0x00, // Start now
             GPS_PRESCRIBED_DWELL_USE_TOA              = 0x0A  // Use TOA
         } gps_prescribed_dwell_start_time_enum_type; //Bit[5:4]

         typedef enum
         {
             GPS_PRESCRIBED_DWELL_USE_RF              = 0x00, // Use RF
             GPS_PRESCRIBED_DWELL_USE_TS               = 0x40  // Use TS
         } gps_prescribed_dwell_source_enum_type; //Bit 6

         typedef enum
         {
             GPS_PRESCRIBED_DWELL_NO_INIT             = 0x00, // Do not initialize TS and BC at starte of dwell
             GPS_PRESCRIBED_DWELL_INIT_TS_AND_BC       = 0x80  // Initialize TS and BC at start of dwell
         } gps_prescribed_dwell_source_init_type; //Bit 7
   \endcode
\param iTOA              = input, Time of Applicability. GPS_RTC time at which dwell must start.
\param iSV               = input, Satellite PRN [0..32]. If zero, correlation is codeless.
\param iSearchMode       = input, Pre-Detection Mode.
\param iPOST_DET_N       = input, Number of Post-Detection.
\param iTASK_MASK1       = input, Bit31:Bit0 - Task32:Task1. A set bit implies that that task must be selected.
\param iTASK_MASK2       = input, Bit7:Bit0 - Task40:Task33. A set bit implies that that task must be selected.
\param iDOPP_FREQ        = input, Signed (1000/65536 Hz/Bit). Range: -32768000 to +32768000 Hz.
\param iDOPP_FREQ_RATE   = input, Signed (1000/65536 Hz/sec/Bit). Range: -32768000 to +32768000 Hz/sec.
\param iSUB_MS           = input, Unsigned (1/256 Chips/Bit). Range: 0 to 1023 chips.
\param iCNO_Threshold    = input, Used for declaring dwell as a detection. Dwell result DM packet.
                    will be send only if CNo exceeds this threshold. Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.
\param iJammerThreshold  = input, Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.

\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning The asynchronous message queue will be cleared in the course of executing this function
*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_PRESCRIBED_DWELL_WithWait(
   HANDLE hResourceContext,
   unsigned short iFlags,
   unsigned long iTOA,
   unsigned char iSV,
   unsigned char iSearchMode,
   unsigned short iPOST_DET_N,
   unsigned long iTASK_MASK1,
   unsigned char iTASK_MASK2,
   unsigned long iDOPP_FREQ,
   unsigned long iDOPP_FREQ_RATE,
   unsigned long iSUB_MS,
   unsigned short iCNO_Threshold,
   unsigned short iJammerThreshold,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to perform one dwell on one channel.
It first enables the log code mask _EVENT_GPS_LM_PD_COMPLETE, enables event control,
clears event queue/log queue, and existing status for CGPS_Dwell_Complete, then starts a prescribed dwell.

Use QLIB_DIAG_GPS_PRESCRIBED_DWELL_CHECK_STATUS  to check completion.

This command will check the status field and return false if the command was rejected.

\param hResourceContext = Resource context that was returned from the call to ConnectServer()
\param iFlags          = input, Enables different functionalities
                  Refer to these enumerations for bit mask definitions:
  \code
     typedef enum
     {
       GPS_PRESCRIBED_DWELL_NO_RESULTS           = 0x00, // Do not send dwell results
       GPS_PRESCRIBED_DWELL_SEND_RESULTS         = 0x01  // Send dwell results
     } gps_prescribed_dwell_results_enum_type;   //Bit 0

     typedef enum
     {
       GPS_PRESCRIBED_DWELL_CHIPX1               = 0x00, // Chipx1
       GPS_PRESCRIBED_DWELL_CHIPX2               = 0x02  // Chipx2
     } gps_prescribed_dwell_chip_rate_enum_type; //Bit 1

     typedef enum
     {
        GPS_PRESCRIBED_DWELL_NO_INCOHER_SUMS    = 0x00, // Do not report incoherent sums
        GPS_PRESCRIBED_DWELL_REPORT_INCOHER_SUMS = 0x04  // Report incoherent sums
     } gps_prescribed_dwell_incoher_sums_enum_type; //Bit 2

     typedef enum
     {
        GPS_PRESCRIBED_DWELL_NO_COHER_SUMS      = 0x00, // Do not report coherent sums
        GPS_PRESCRIBED_DWELL_REPORT_COHER_SUMS   = 0x08  // Report coherent sums
     } gps_prescribed_dwell_coher_sums_enum_type; //Bit 3

     typedef enum
     {
        GPS_PRESCRIBED_DWELL_START_NOW          = 0x00, // Start now
        GPS_PRESCRIBED_DWELL_USE_TOA             = 0x0A  // Use TOA
     } gps_prescribed_dwell_start_time_enum_type; //Bit[5:4]

     typedef enum
     {
        GPS_PRESCRIBED_DWELL_USE_RF             = 0x00, // Use RF
        GPS_PRESCRIBED_DWELL_USE_TS              = 0x40  // Use TS
     } gps_prescribed_dwell_source_enum_type; //Bit 6

     typedef enum
     {
        GPS_PRESCRIBED_DWELL_NO_INIT            = 0x00, // Do not initialize TS and BC at starte of dwell
        GPS_PRESCRIBED_DWELL_INIT_TS_AND_BC      = 0x80  // Initialize TS and BC at start of dwell
     } gps_prescribed_dwell_source_init_type; //Bit 7
  \endcode
\param iTOA            = input, Time of Applicability. GPS_RTC time at which dwell must start.
\param iSV             = input, Satellite PRN [0..32]. If zero, correlation is codeless.
\param iSearchMode     = input, Pre-Detection Mode.
\param iPOST_DET_N     = input, Number of Post-Detection.
\param iTASK_MASK1     = input, Bit31:Bit0 - Task32:Task1. A set bit implies that that task must be selected.
\param iTASK_MASK2     = input, Bit7:Bit0 - Task40:Task33. A set bit implies that that task must be selected.
\param iDOPP_FREQ      = input, Signed (1000/65536 Hz/Bit). Range: -32768000 to +32768000 Hz.
\param iDOPP_FREQ_RATE  = input, Signed (1000/65536 Hz/sec/Bit). Range: -32768000 to +32768000 Hz/sec.
\param iSUB_MS         = input, Unsigned (1/256 Chips/Bit). Range: 0 to 1023 chips.
\param iCNO_Threshold   = input, Used for declaring dwell as a detection. Dwell result DM packet.
                  will be send only if CNo exceeds this threshold. Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.
\param iJammerThreshold = input, Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.

\param piStatus        = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning The asynchronous message queue will be cleared in the course of executing this function
*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_PRESCRIBED_DWELL_START(
   HANDLE hResourceContext,
   unsigned short iFlags,
   unsigned long iTOA,
   unsigned char iSV,
   unsigned char iSearchMode,
   unsigned short iPOST_DET_N,
   unsigned long iTASK_MASK1,
   unsigned char iTASK_MASK2,
   unsigned long iDOPP_FREQ,
   unsigned long iDOPP_FREQ_RATE,
   unsigned long iSUB_MS,
   unsigned short iCNO_Threshold,
   unsigned short iJammerThreshold,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
   This function checks to see if an CGPS_Dwell_Complete event has been received.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
   \param iOverrideTimeout_ms        = new timeout value to override the one configured using ConfigureTimeout().
                           if iOverrideTimeout_ms < 0 or unspecified, use general timeout from ConfigureTimeout.
                           if iOverrideTimeout_ms ==0, return immediately.
                           if iOverrideTimeout_ms>0, it will override the one from ConfigureTimeout().

   \return true if successful, false if fail.

   ******************************************************************************/


QLIB_API unsigned char QLIB_DIAG_GPS_PRESCRIBED_DWELL_CHECK_STATUS(
   HANDLE hResourceContext,
   long iOverrideTimeout_ms
   );



/******************************************************************************/
/**
This function instructs the CGPS engine to start an IQ collect at a given point along
the GPS and AFLT signal paths, and performs FFT if requested. Raw IQ values and/or
FFT powers are output in MGP DM log packets.

This command will check the status field and return false if the command was rejected.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().
\param pGPS_StartIQ_TestParams       = structure of type gps_start_iq_test_struct_type, which contains
                             all input parameters.

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning This funciton does not collect the results using in the log message.  To do
         so, use QLIB_DIAG_GPS_START_IQ_TEST_CollectResults()

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_START_IQ_TEST(
   HANDLE hResourceContext,
   void *pGPS_StartIQ_TestParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to start an IQ collect at a given point along
the GPS and AFLT signal paths, and performs FFT if requested. Raw IQ values and/or
FFT powers are output in MGP DM log packets.

This command will check the status field and return false if the command was rejected.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().
\param pGPS_StartIQ_TestParams       = structure of type gps_start_iq_test_struct_type, which contains
                             all input parameters.

\param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning The asynchronous message queue will be cleared in the course of executing this function

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_START_IQ_TEST_CollectResults(
   HANDLE hResourceContext,
   void *pGPS_StartIQ_TestParams,
   char *sIQ_FileName,
   char *sFFT_FileName,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function instructs the CGPS engine to start a 60 second IQ test.

This command will check the status field and return false if the command was rejected.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().
\param pGPS_StartIQ_TestParams       = structure of type gps_start_iq_test_struct_type, which contains
                             all input parameters.

\param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

******************************************************************************/

QLIB_API unsigned char QLIB_DIAG_GPS_START_IQ_TEST_60sec(
   HANDLE hResourceContext,
   void *pGPS_StartIQ_TestParams,
   char *sIQ_FileName,
   char *sFFT_FileName,
   unsigned char *piStatus
   );



/******************************************************************************/
/**

This function checks to see if an CGPS_IQ_Test_Complete event has been received.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().

\return true if successful, false if fail.

******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_Check_IQ_TEST_Status(HANDLE hResourceContext);

/******************************************************************************/
/**

This function closes IQ test related files if they have been opened.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().

******************************************************************************/
QLIB_API void QLIB_DIAG_GPS_Close_IQ_TEST_Files(HANDLE hResourceContext);


/******************************************************************************/
/**
   Returns the IQ data for the last IQ Capture. This is the data reported by the mobile,
   via the IQ Data Log, ( CGPS_IQ_DATA_LOG, 0x138A)

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

   \param pI_Samples = INPUT, pointer to buffer to store I samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
   \param pQ_Samples = INPUT, pointer to buffer to store Q samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
   \param pNumSamples = OUTPUT, returns the number of samples that were written into the pI_Samples and pQ_Samples arrays.

   \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

   \return Returns true if successful, false if fail or number of IQ samples = 0

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_GetIQ_Data(
   HANDLE hResourceContext,
   char *pI_Samples,
   char *pQ_Samples,
   unsigned long *pNumSamples
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
QLIB_API unsigned char QLIB_CGPS_GetProcessedIQ_Data(
   HANDLE hResourceContext,
   double *pI_ProcessedSamples,
   double *pQ_ProcessedSamples,
   unsigned long *pNumProcessedSamples
   );


/******************************************************************************/
/**
   Returns the FFT Measured data from the last IQ Capture.  Measured means that this is
   the data reported by the mobile, via the IQ Data Log, ( CGPS_IQ_DATA_LOG, 0x138A)

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

   \param pFFT_Samples = INPUT, pointer to buffer to store FFT samples, the size of the array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
   \param pNumSamples = OUTPUT, returns the number of samples that were written into the pFFT_Samples array

   \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

   \return Returns true if successful, false if fail or number of FFT samples = 0

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_GetFFT_MeasuredData(
   HANDLE hResourceContext,
   unsigned short *pFFT_Samples,
   unsigned long *pNumSamples
   );

/******************************************************************************/
/**
   Calculate FFT based on the IQ data.

   Call QLIB_CGPS_GetFFT_CalculatedData to get the results

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

   \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

   \return Returns true if successful, false if fail or number of FFT samples = 0

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_CalculateFFT_Data(HANDLE hResourceContext);

/******************************************************************************/
/**
   Calculate FFT based on the ADC IQ data.

   Call QLIB_CGPS_GetADC_FFT_CalculatedData to get the results

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
   \param bCW_SigGen_Active  = set to true if the the CW signal generator was on during data collection
   \param bADCLiteConfig     = set to true to indicate that the "Lite" ADC config should be used unless Gen8B+ logs are received
   \param _dCW_SigGen_Freq_Offset_kHz = Signalling offset in KHz
   \param dCW_SigGen_level_dBm = Signaling power level in dBm

   \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

   \return Returns true if successful, false if fail or number of FFT samples = 0

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_CalculateADC_FFT_Data(HANDLE hResourceContext, 
                                                       unsigned char bCW_SigGen_Active, 
                                                       unsigned char bADCLiteConfig,
                                                       double _dCW_SigGen_Freq_Offset_kHz, 
                                                       double dCW_SigGen_level_dBm, 
                                                       void* WideBandJam); 


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
QLIB_API unsigned char QLIB_CGPS_GetFFT_CalculatedData(
   HANDLE hResourceContext,
   double *pFFT_Amplitude,
   double *pFFT_Frequency,
   unsigned long *iNumSamples
   );

/******************************************************************************/
/**
   Returns the FFT Calculated data from the last ADC IQ Capture.  Measured means that this is
   the data reported by the mobile, via the IQ Data Log, ( CGPS_IQ_DATA_LOG, 0x138A)  This
   also returns the ADC result data.

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
   \param pFFT_Amplitude = OUTPUT, pointer to buffer to store FFT samples, the size of the array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
   \param pFFT_Frequency = OUTPUT, frequency associated with each element in the pFFT_Amplitude array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
   \param pADC_NoiseFloor = OUTPUT, Noise Floor data, the size of the array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
   \param pNormalized_ISamples = OUTPUT, Normalized I Sample data, the size of the array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
   \param pNormalized_QSamples = OUTPUT, Normalized Q Sample data, the size of the array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
   \param iNumSamples = OUTPUT, returns the number of samples that were written into the pFFT_Samples array
   \param pAdcIqResults = OUTPUT, returns the ADC IQ Results

   \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() and QLIB_CGPS_CalculateFFT_Data() must be called first.

   \return Returns true if successful, false if fail or number of FFT samples = 0

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_GetADC_FFT_CalculatedData(
   HANDLE hResourceContext,
   double *pFFT_Amplitude,
   double *pFFT_Frequency,
   double *pADC_NoiseFloor,
   unsigned long *iNumFftSamples,
   double *pNormalized_ISamples,
   double *pNormalized_QSamples,
   unsigned long *iNumSamples,
   void *pAdcIqResults
   );

/******************************************************************************/
/**
      Clear the IQ data for the last IQ Capture to release memory.

      \param hResourceContext = Resource context that was returned from the call to ConnectServer().
      \warning QLIB_CGPS_GetIQ_Data
            /QLIB_CGPS_GetProcessedIQ_Data
            /QLIB_CGPS_GetFFT_MeasuredData
            QLIB_CGPS_CalculateFFT_Data cannot be called after this function as the memory is cleared.

      \return Returns true if successful, false if fail or number of IQ samples = 0

   *******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_ClearIQ_Data(
   HANDLE hResourceContext);

/******************************************************************************/
/**
This function instructs the CGPS engine to track the specified SV or all the SVs depending on the input command. The test can be stopped
using appropriate command parameters (see below).

This command will check the status field and return false if the command was rejected.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().
\param iSV                           = input.    Satellite PRN [0:32]. If zero (GPS_SV_TRACK_ALL), operation is track all SVs.
\param iCommand                      = input.    defined by gps_sv_track_command_enum_type:
   \code
        GPS_SV_TRACK_START_CLEAR_ALL = 0
        GPS_SV_TRACK_START_NO_CLEAR  = 1
        GPS_SV_TRACK_STOP_CLEAR_ALL  = 2
        GPS_SV_TRACK_STOP_NO_CLEAR   = 3
        GPS_SV_TRACK_START_CLEAR_ALL_NO_BITEDGE_DETECTION = 5
        GPS_SV_TRACK_START_NO_CLEAR_NO_BITEDGE_DETECTION = 6

     \endcode

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_SV_TRACK(
   HANDLE hResourceContext,
   unsigned char iSV,
   unsigned char iCommand,
   unsigned char *piStatus
   );



/******************************************************************************/
/**

This function instructs the CGPS GEN8 engine to track GNSS SV's as specified
by SvTrackParams input parameters. The test can also be stopped using appropriate
   command parameters.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param SvTrackParams = input. A structure containing Multi-Channel Tracking Test parameters.  Please refer to CGPS_Gen8_SvTrack_Struct_type in QLib_Defines.h
   \endcode

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_SV_TRACK(
   HANDLE hResourceContext,
   void *SvTrackParams,
   unsigned char *piStatus
   );


/******************************************************************************/
/*

This function instructs the CGPS GEN8 engine to track GNSS SV's as specified
by SvTrackParams input parameters. The test can also be stopped using appropriate
   command parameters.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param SvTrackParams     = input. A structure containing Multi-Channel Tracking Test parameters.  Please refer to CGPS_Gen8B_SvTrack_Struct_type in QLib_Defines.h
   \endcode

\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8B_SV_TRACK( HANDLE hResourceContext,
                                                     void *SvTrackParams,
                                                     unsigned char *piStatus );

/******************************************************************************/
/*

This function instructs the CGPS GEN8 engine to track GNSS SV's as specified
by SvTrackParams input parameters. The test can also be stopped using appropriate
   command parameters.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param SvTrackParams     = input. A structure containing Multi-Channel Tracking Test parameters.  Please refer to CGPS_Gen8C_SvTrack_Struct_type in QLib_Defines.h
   \endcode

\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8C_SV_TRACK( HANDLE hResourceContext,
   void *SvTrackParams,
                                            unsigned char* piStatus );

/******************************************************************************/
/**

This function sends the CGPS GEN8 engine HW Configure command to the phone.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param HwConfigParams    = input. A structure containing HW Configure command parameters.  Please refer to CGPS_Gen8_HwConfig_Struct_type in QLib_Defins.h
   \endcode

\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_HW_CONFIG(
   HANDLE hResourceContext,
   void *HwConfigParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function sends the CGPS GEN8 engine PRx RF Mode DM command to the phone.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param PRx_Mode  = input. A CGPS_Gen8_Rx_RfMode_Struct_type structure containing PRx RF Mode command parameters.  Please refer to
CGPS_Gen8_Rx_RfMode_Struct_type in QLib_Defines.h

\endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/

QLIB_API unsigned char QLIB_GPS_GEN8_PRx_Mode_Config(
   HANDLE hResourceContext,
   void *PRx_Mode
   );

/******************************************************************************/
/**

This function sends the CGPS GEN8 engine RF Linearity Config DM command to the phone.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param DRx_On_Off_Config = input. A CGPS_Gen8_Rf_Linearity_Config_Struct_type structure containing RF Linearity Config command parameters .
\endcode

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_GPS_GEN8_RF_Linearity_Config(
   HANDLE hResourceContext,
   void *RF_Linearity_Config
   );

/******************************************************************************/
/**

This function sends the GNSS_NAV_SET_CONFIG DM command to the phone returning the command response.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer(). 
\param Requested_Contellation_Mask  = A bit mask of the requested constellation configuration.
                                       Bit 0  GPS
                                       Bit 1  Glonass
                                       Bit 2  Beidou
                                       Bit 4  Galileo
 
\param Supportted_Contellation_Mask  = Returned bit mask of the supportted constellation configuration. 
\param Actual_Contellation_Mask      = Returned bit mask of the current constellation configuration. 
 
\endcode

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_GPS_GEN8_GNSS_NAV_SET_CONFIG( HANDLE hResourceContext,
                                                          unsigned char  Requested_Constellation_Mask,
                                                          unsigned char* Supportted_Contellation_Mask,
                                                          unsigned char* Actual_Constellsation_Mask 
                                                          );

/******************************************************************************/
/**

This function sends the GNSS_NAV_SET_CONFIG DM command to the phone returning the command response.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer(). 
\param Requested_Contellation_Mask  = A bit mask of the requested constellation configuration.
                                       Bit 0  GPS
                                       Bit 1  Glonass
                                       Bit 2  Beidou
                                       Bit 4  Galileo
 
\param Supportted_Contellation_Mask  = Returned bit mask of the supportted constellation configuration. 
\param Actual_Contellation_Mask      = Returned bit mask of the current constellation configuration. 
 
\endcode

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_GPS_GEN8_GNSS_Get_ADCIQ_Saturation_Percentage(HANDLE hResourceContext,
                                                                          unsigned char *ADC_IQ_SAT_PER_STATUS,
                                                                          double* Percent_of_I_Samples_Saturated,
                                                                          double* Percent_of_Q_Samples_Saturated
                                                                          );

QLIB_API unsigned char QLIB_GNSS_Get_RF_Dev_Capabilites(HANDLE hResourceContext, unsigned long *Capabilities );


/******************************************************************************/
/*

This function sends the CGPS GEN8 engine GPS Engine Query RF Dev Capability DM Command Config DM command to the phone.

This command will check the status field and return false if the command was rejected.
\param EngineRev = output, GNSS Engine Revision.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_GPS_GEN8_Get_GNSS_Engine_Revision(HANDLE hResourceContext,  long* EngineRevision);


/******************************************************************************/
/**

This function Initilizes a specific GPS PDAPI client.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_INITIALIZE(
   HANDLE hResourceContext,
   void *FixCollectionParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function registers or deregisters GPS PD related callbacks and events.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_REGISTER_PD(
   HANDLE hResourceContext,
   void *FixCollectionParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function activates a specific PDAPI client, so that it will be notified of Session Manager
events for which it is registered.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_ACTIVATE(
   HANDLE hResourceContext,
   void *FixCollectionParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function deactivates a particular PDAPI client, so that it will not be notified of
Session Manager events for which it is registered.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_DEACTIVATE(
   HANDLE hResourceContext,
   void *FixCollectionParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function releases a specific PDAPI client when it no longer needs the Session Manager.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_RELEASE(
   HANDLE hResourceContext,
   void *FixCollectionParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function requests the target to start a CGPS session with the specified parameters.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_START(
   HANDLE hResourceContext,
   void *FixCollectionParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function requests the target to end an ongoing CGPS session with the specified parameters.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_END(
   HANDLE hResourceContext,
   void *FixCollectionParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function requests the target to set configuration parameters in either the NV or
Session Manager.

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_SET_PARAM(
   HANDLE hResourceContext,
   void *FixCollectionParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**

This function sends LTE PRS Aiding Data to the GNSS Engine

This command will check the status field and return false if the command was rejected.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param Command Header    = input. A structure containing the command header paramters. 
\param Aiding Data       = input. A structure containing Aiding Data to be sent. 

\param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_PDAPI_Send_LTE_PRS_Aiding_Data( HANDLE hResourceContext,
                                                                 void *Aiding_Data_Command,
                                                                 unsigned char *piStatus
                                                                 );

/******************************************************************************/
/**
This function instructs the CGPS GEN 8 engine to start an IQ collect, performs FFT
if requested. Raw IQ values and/or FFT powers are output in MGP DM log packets.

This command will check the status field and return false if the command was rejected.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().
\param pGPS_StartIQ_TestParams       = structure of type CGPS_Gen8_StartIqTest_struct_type, which contains
                             all input parameters.

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning This funciton does not collect the results using in the log message.  To do
         so, use QLIB_DIAG_GPS_START_IQ_TEST_CollectResults()

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_START_IQ_TEST(
   HANDLE hResourceContext,
   void *pGPS_StartIQ_TestParams,
   unsigned char *piStatus);

/******************************************************************************/
/**
This function instructs the CGPS Gen 8 engine to start an IQ collect and performs
FFT if requested. Raw IQ values and/or FFT powers are output in MGP DM log packets.

This command will check the status field and return false if the command was rejected.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().
\param pGPS_StartIQ_TestParams       = structure of type CGPS_Gen8_StartIqTest_struct_type, which contains
                             all input parameters.   Supportted collect modes include:

                              1  WBIQ LBW-GPS (2.046 MHz sample rate)
                              3  WBIQ GLO     (1.022 MHz sample rate)
                              4  FBIQ HBW-GPS (20.46 MHz sample rate)

\param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning The asynchronous message queue will be cleared in the course of executing this function

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_START_IQ_TEST_CollectResults(
   HANDLE hResourceContext,
   void *pGPS_StartIQ_TestParams,
   char *sIQ_FileName,
   char *sFFT_FileName,
   unsigned char *piStatus);


/******************************************************************************/
/**
This function queries RF Blanking Status.

This command will check the status field and return false if the command was rejected.

\param hResourceContext     = Resource context that was returned from the call to ConnectServer().
\param BlankingStatus       = Structure of type GNSS_BlankingStatus_Response_type to recive the blanking status. 


\param piStatus             = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GNSS_QueryBlankingStatus(HANDLE hResourceContext,
                                                          unsigned char* Enabled,
                                                          unsigned long* Rx1Counter,
                                                          unsigned long* Rx2Counter);


/******************************************************************************/
/**

This function instructs the CGPS engine to start a 60 second IQ test.

This command will check the status field and return false if the command was rejected.

\param hResourceContext              = Resource context that was returned from the call to ConnectServer().
\param pGPS_StartIQ_TestParams       = structure of type CGPS_Gen8_StartIqTest_struct_type, which contains
                             all input parameters.

\param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

******************************************************************************/

QLIB_API unsigned char QLIB_DIAG_GPS_Gen8_START_IQ_TEST_60sec(
   HANDLE hResourceContext,
   void *pGPS_StartIQ_TestParams,
   char *sIQ_FileName,
   char *sFFT_FileName,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to perform one dwell on one channel.

This command will check the status field and return false if the command was rejected.

\param hResourceContext = Resource context that was returned from the call to ConnectServer()
\param PrescribedDwellParams= Pointer to a structure containing the Prescribed Dwell command paramters.
Please refer to CGPS_Gen8_PrescribedDwell_struct_type in QLib_Defines.h


\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning This version of the function does not wait for the response event. To wait for
         the event use QLIB_DIAG_GPS_PRESCRIBED_DWELL_WithWait

*******************************************************************************/

QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_PRESCRIBED_DWELL(
   HANDLE hResourceContext,
   void *PrescribedDwellParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to perform one dwell on one channel, then
wait for the corresponding event, EVENT_GPS_LM_PD_COMPLETE, #1250.

The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
timeout type of QMSL_Timeout_CGPS_Event.

This command will check the status field and return false if the command was rejected.

\param hResourceContext = Resource context that was returned from the call to ConnectServer()
\param PrescribedDwellParams = input, A structure containing the prescrbed dwell
                              command parameters.  Please refer to CGPS_Gen8_PrescribedDwell_struct_type in QLib_Defines.h

\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning The asynchronous message queue will be cleared in the course of executing this function
*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_PRESCRIBED_DWELL_WithWait(
   HANDLE hResourceContext,
   void *PrescribedDwellParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to perform one dwell on one channel, then
wait for the corresponding event, EVENT_GPS_LM_PD_COMPLETE, #1250.

The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
timeout type of QMSL_Timeout_CGPS_Event.

This command will check the status field and return false if the command was rejected.

\param hResourceContext = Resource context that was returned from the call to ConnectServer()
\param PrescribedDwellParams = input, A structure containing the prescrbed dwell
                              command parameters.  Please refer to CGPS_Gen8_PrescribedDwell_struct_type in QLib_Defines.h

\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning The asynchronous message queue will be cleared in the course of executing this function
*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8B_PRESCRIBED_DWELL_WithWait(
   HANDLE hResourceContext,
   void *PrescribedDwellParams,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
This function instructs the CGPS engine to perform one dwell on one channel, then
wait for the corresponding event, EVENT_GPS_LM_PD_COMPLETE, #1250.

The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
timeout type of QMSL_Timeout_CGPS_Event.

This command will check the status field and return false if the command was rejected.

\param hResourceContext = Resource context that was returned from the call to ConnectServer()
\param PrescribedDwellParams = input, A structure containing the prescrbed dwell
                              command parameters.  Please refer to CGPS_Gen8_PrescribedDwell_struct_type in QLib_Defines.h

\param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning The asynchronous message queue will be cleared in the course of executing this function
*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_GEN8C_PRESCRIBED_DWELL_WithWait(
   HANDLE hResourceContext,
   void *PrescribedDwellParams,
   unsigned char *piStatus
   );


/******************************************************************************/
/**
   Clear the status of the entire CGPS status object
   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

   \return Returns true if successful, false if fail

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_ClearStatus(HANDLE hResourceContext);

/******************************************************************************/
/**
   Clear a specific status element of the CGPS status

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
   \param eStat = the type of status to clear, type is QMSL_CGPS_Event_Enum from QLibDefines.h
   \return Returns true if successful, false if fail

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_ClearStatus_Specific(HANDLE hResourceContext, unsigned long eStat);

/******************************************************************************/
/**
   Copy the status into the user supplied GSM BER Status structure

   \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
   \param pCGPS_Status is a structure of type "CGPS_Status_Struct*"

   \return Returns true if successful, false if fail

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_GetStatus(HANDLE hResourceContext, void *pCGPS_Status);

/******************************************************************************/
/**
Starts the async messages (logs and events) associated with CGPS.  These logs are:
\code
      CGPS_IQ_DATA_LOG = 0x138A
    CGPS_RF_STATUS_REPORT_LOG 0x1372

\endcode

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param bEnableEvents = true to enable CGPS events, false to disable.  The events that will be enabled are:
\code
    _EVENT_GPS_PD_COMM_FAILURE      = 1241,
    _EVENT_GPS_PD_COMM_DONE         = 1242,
    _EVENT_GPS_PD_EVENT_END         = 1243,
    _EVENT_GPS_PA_EVENT_CALLBACK    = 1244,
    _EVENT_GPS_PD_CMD_ERR_CALLBACK  = 1245,
    _EVENT_GPS_PA_CMD_ERR_CALLBACK  = 1246,
    _EVENT_GPS_LM_ENTER_SA_RF_VERIF = 1247,
    -EVENT_GPS_LM_EXIT_SA_RF_VERIF  = 1248,
    _EVENT_GPS_LM_ERROR_SA_RF_VERIF = 1249,
    _EVENT_GPS_LM_PD_COMPLETE       = 1250,
    _EVENT_GPS_LM_IQ_TEST_COMPLETE  = 1251,
    _EVENT_GNSS_PRESC_DWELL_COMPLETE = 1717

\endcode

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_StartCGPS_AsyncMessages(
   HANDLE hResourceContext,
   unsigned char bEnableEvents
   );

/******************************************************************************/
/**
Performs a CW SNR measurment by using other CGPS functions:
   - Optionally activates/deactivates CGPS test mode using QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait()
   - Captures Wideband IQ data using QLIB_DIAG_GPS_START_IQ_TEST()
   - Calculates FFT using QLIB_CGPS_CalculateFFT_Data()
   - Gets the FFT results using QLIB_CGPS_GetFFT_CalculatedData()
   - Peforms a peak search and C/N calculation using the FFT data

This function is designed to be used for factory testing, for quick verification of the GPS path.
It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
-120dBm and -100dBm.  -110dBm is suggested.

For troubleshooting, it is possible to enable a text file to log the IQ data in a format that a Matlab script
will be able to parse.  To use the Matlab script:
\code
   cgps_IqTest_IqFileProc( 6.0, 100, -120, 'c:\CGPS_SNR_IQ_Capture.txt' )

   For this case,
   RF_NoiseFigure = 6.0dB
   SigFreqKhz = 100kHz
   SigLevelDbm = -120.0dBm
   FileName = c:\CGPS_SNR_IQ_Capture.txt

\endcode

The SNR calculation is exactly as found the CGPS Matlab script named, ""

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8, etc.)
\param iAutoSetGPS_VerificationMode = input, true to set the GPS Verification mode ON before the capture and OFF after the capture
                              if true, the CGPS timeout will automatically be set to 15 seconds using the function QLIB_ConfigureTimeOut()
\param sIQ_FileName = input, file name to store a text file which can be used by the MatLab script, cgps_IqTest_FftFileProc.m
                  if NULL, then no file will be created.
\param iNumberOfIntegrations = number of integrations (separate embedded IQ captures) to use.  The higher the number of integrations,
                               the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                        The maximum number of integrations is 10.
\param pdSNR = output, pointer to storage for the output results


\return true if successful, false if fail.

\warning if iAutoSetGPS_VerificationMode==1 then this function will increase the CGPS timeout to 15 seconds:
\code
    QLIB_ConfigureTimeOut(g_hResourceContext, QMSL_Timeout_CGPS_Event, 15000 )
\endcode

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_CGPS_SNR(
   HANDLE hResourceContext,
   unsigned short iCaptureSize_kSamples,
   unsigned char  iAutoSetGPS_VerificationMode,
   unsigned short iNumberOfIntegrations,
   char *sIQ_FileName,
   double *pdSNR
   );
/******************************************************************************/
/**
Commands the mobile to start a WB I/Q capature and returns C/N calculated by mobile

   - Optionally activates/deactivates CGPS test mode using QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait()
   - Captures Wideband IQ data using QLIB_DIAG_GPS_START_IQ_TEST()
    - Returns the C/N and frequency bin calculated by embedded side

 Note: Please note that C/N or SNR returned is expected to be different from the one returned by QLIB_DIAG_CGPS_SNR.
It is because the two functions use different alogorithm to compute SNR.

This function is designed to be used for factory testing, for quick verification of the GPS path.
It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

The function requires that embedded side to be able to return C/N via LOG_CGPS_WB_FFT_STATS_C (0x1487).

The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
-120dBm and -100dBm.  -110dBm is suggested.

For more information, please refer to 80-VR679-1 (C/N0 Measurement Method for GPS Testing on Production Line)

For troubleshooting, it is possible to enable a text file to log the IQ data in a format that a Matlab script
will be able to parse.  To use the Matlab script:
\code
   cgps_IqTest_IqFileProc( 6.0, 100, -120, 'c:\CGPS_SNR_IQ_Capture.txt' )

   For this case,
   RF_NoiseFigure = 6.0dB
   SigFreqKhz = 100kHz
   SigLevelDbm = -120.0dBm
   FileName = c:\CGPS_SNR_IQ_Capture.txt

\endcode

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8, etc.)
\param iAutoSetGPS_VerificationMode = input, true to set the GPS Verification mode ON before the capture and OFF after the capture
                              if true, the CGPS timeout will automatically be set to 15 seconds using the function QLIB_ConfigureTimeOut()
\param sIQ_FileName = input, file name to store a text file which can be used by the MatLab script, cgps_IqTest_FftFileProc.m
                  if NULL, then no file will be created.
\param iNumberOfIntegrations = number of integrations (separate embedded IQ captures) to use.  The higher the number of integrations,
                               the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                        The maximum number of integrations is 10.
\param pdCNoDBHz = output, pointer to Signal strength calculated in dBHz as part of WBIQ test
\param piFreqInHz = output, pointer to Frequency in Hz calculated as part of WBIQ test

\return true if successful, false if fail.

\warning if iAutoSetGPS_VerificationMode==1 then this function will increase the CGPS timeout to 15 seconds:
\code
    QLIB_ConfigureTimeOut(g_hResourceContext, QMSL_Timeout_CGPS_Event, 15000 )
\endcode

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_CGPS_GET_EMBEDDED_CALCULATED_CTON(
   HANDLE hResourceContext,
   unsigned short iCaptureSize_kSamples,
   unsigned char  iAutoSetGPS_VerificationMode,
   unsigned short iNumberOfIntegrations,
   char *sIQ_FileName,
   double *pdCNoDBHz,
   int *piFreqInHz
   );

/******************************************************************************/
/**
 Requests the phone to return the GPS C/No(dB) and frequency offset(Hz) calculated by embedded side.
 For more information, please refer to "DM Command to get C/No for testing GEN8 GPS at Production Line", 80-VU919-1 A.

 This function is designed to be used for factory testing, for quick verification of the GPS path.
 It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

 The function requires that embedded side to be able to return C/No via LOG_CGPS_WB_FFT_STATS_C (0x1487).
 QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait(GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE) must be called first, with the RF signal disabled.

 The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
 -120dBm and -100dBm.  -110dBm is suggested.

To configure the timeout, use QLIB_ConfigureTimeOut(QMSL_Timeout_CGPS_Event, timeout) to configure.

 \param hResourceContext = Resource context that was returned from the call to ConnectServer().
 \param iCollectMode          = input, defines the collect point of I/Q samples, see the definition of gps_start_iq_test_collect_mode_gen8.
 \param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8, etc.)
 \param iNumberOfIntegrations = number of integrations (separate embedded I/Q captures) to use.  The higher the number of integrations,
                                 the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                                The maximum number of integrations is 10.
 \param pdCNoDBHz = output, pointer to C/No calculated in dB.
 \param piFreqInHz = output, pointer to Frequency offset in Hz.

 \return true if successful, false if fail.
 *******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GEN8_GET_EMBEDDED_CALCULATED_CTON(
   HANDLE hResourceContext,
   unsigned char iCollectMode,
   unsigned short iCaptureSize_kSamples,
   unsigned char iNumberOfIntegrations,
   double *pdCNoDBHz,
   int *piFreqInHz,
   bool bExitSARFOnComplete = false
   ); 


/******************************************************************************/
/*
 Requests the phone to return the GPS C/No(dB) and frequency offset(Hz) calculated by embedded side.
 For more information, please refer to "DM Command to get C/No for testing GEN8 GPS at Production Line", 80-VU919-1 A.

 This function is designed to be used for factory testing, for quick verification of the GPS path.
 It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

 The function requires that embedded side to be able to return C/No via LOG_CGPS_WB_FFT_STATS_C (0x1487).
 QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait(GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE) must be called first, with the RF signal disabled.

 The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
 -120dBm and -100dBm.  -110dBm is suggested.

To configure the timeout, use QLIB_ConfigureTimeOut(QMSL_Timeout_CGPS_Event, timeout) to configure.

 \param hResourceContext = Resource context that was returned from the call to ConnectServer().
 \param iCollectMode          = input, defines the collect point of I/Q samples, see the definition of gps_start_iq_test_collect_mode_gen8.
 \param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8, etc.)
 \param iNumberOfIntegrations = number of integrations (separate embedded I/Q captures) to use.  The higher the number of integrations,
                                 the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                        The maximum number of integrations is 10.
\param GLO_FrequencyID       = The GLONASS SV Frequency ID in the range -7 to +6.
\param GLO_FrequencyID       = The GLONASS Hardware Channel to be used, in the range 1 to 12.
 \param pdCNoDBHz = output, pointer to C/No calculated in dB.
 \param piFreqInHz = output, pointer to Frequency offset in Hz.

 \return true if successful, false if fail.
 *******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GNSS_GET_EMBEDDED_CALCULATED_CTON(
   HANDLE hResourceContext,
   unsigned char iCollectMode,
   unsigned short iCaptureSize_kSamples,
   unsigned char iNumberOfIntegrations,
   char GLO_FrequencyID,
   unsigned char GLO_HW_Channel,
   double *pdCNoDBHz,
   int *piFreqInHz,
   bool bExitSARFOnComplete = false
   );

/******************************************************************************/
/**
Requests the phone to return the GNSS (GPS or GLO) C/No(dB) and
frequency offset(Hz) calculated by embedded side. For more
information, please refer to "DM Command to get C/No for testing
GEN8 GPS at Production Line", 80-Vxxxx-1 A.

This function is designed to be used for factory testing, for quick verification of the GPS path.
It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

The function requires that embedded side to be able to return C/No via LOG_CGPS_WB_FFT_STATS_C (0x1487).
QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait(GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE) must be called first, with the RF signal disabled.

The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
-120dBm and -100dBm.  -110dBm is suggested.

\param hResourceContext = Resource context that was returned from the call to ConnectServer().
\param iCollectMode          = input, defines the collect point of I/Q samples, see the definition of gps_start_iq_test_collect_mode_gen8.
\param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8,16,32)
\param iNumberOfIntegrations = number of integrations (separate embedded I/Q captures) to use.  The higher the number of integrations,
                     the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                     The maximum number of integrations is 10.
\param GLO_FrequencyID       = The GLONASS SV Frequency ID in the range -7 to +6.
\param GLO_FrequencyID       = The GLONASS Hardware Channel to be used, in the range 1 to 12.
\param poFFT_STats           = Pointer to an instance of GNSS_WB_FFT_Stats_v2 to contain the received data

\return true if successful, false if fail.

*******************************************************************************/


QLIB_API unsigned char QLIB_DIAG_GNSS_GET_EMBEDDED_CALCULATED_CTON_ALL_CONSTELLATIONS(
                                                                                      HANDLE hResourceContext,
                                                                                      unsigned char iCollectMode,          
                                                                                      unsigned short iCaptureSize_kSamples,
                                                                                      unsigned char iNumberOfIntegrations, 
                                                                                      char GLO_FrequencyID,
                                                                                      unsigned char GLO_HW_Channel,
                                                                                      bool bExitSARFOnComplete,
                                                                                      void *poFFT_Stats
   ); 


/******************************************************************************/
/**
Factory Test Mode, GNSS FTM RF Mode ID 34, Subcommand 253 - External LNA

FTM ICD DCN: TBD

Enable/disable external LNA

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param iEnable = 0= diable, 1 = enable

\return true if successful, false if fail.

\warning

*******************************************************************************/

QLIB_API unsigned char QLIB_FTM_GNSS_EXTERNAL_LNA(HANDLE hResourceContext, unsigned char iEnable);


/******************************************************************************/

/**
This function instructs the CGPS engine to enter "Standalone RF verification" mode.


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

\warning This version of the function does not wait for the associated event.
         Use QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait() to wait for the event.

*******************************************************************************/
QLIB_API unsigned char QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH(
   HANDLE hResourceContext,
   unsigned char iFlag,
   unsigned char *piStatus
   );

/******************************************************************************/
/**
 This function configures the onboard Spectrum Analysis 
  
 \param SCAN_MODE              = 0 - Single Shot, 1 - Continuos
 \param SCAN_START_STOP        = 1 - start scan, 0 - stop scan, 2 - stop and restart scan 
 \param GPS_SCAN_TYPES_ENABLED = Bit Mask for GPS Scan types: 
                                 Bit 0 = Fast Scan, Bit 1 = Deep Scan 
 \param GLO_SCAN_TYPES_ENABLED = Bit Mask for GLONASS Scan Types: 
                                 Bit 0 = Fast Scan, Bit 1 = Deep Scan
 \param PROBE_POINT_FOR_SCAN   = Bit Mask for probe point to be used in collecting 
                                 spectrum analysis samples:
                                 Bit 0-3 to 1 for Probe points P1-P4
 \param TRACKING_MODE_CONTROL  = 0 - Disable tracking mode for jammers 
                                 1 - Enable tracking mode for jammers
 \param RESET_NOTCH_FILTERS    = Option to reset all the Notch filters currently
                                 assigned. When issued with a start option, this
                                 resets notch filters prior to Start. When issued
                                 with a stop option, this resets notch filters
                                 after stopping the scan.
                                 1 - Reset notch filters
                                 0 - Do not reset notch filters

 \return true if successful, false if fail.


 *******************************************************************************/
QLIB_API unsigned char QLIB_GNSS_SpecAn_Control(HANDLE hResourceContext,
                                                unsigned char SCAN_MODE,
                                                unsigned char SCAN_START_STOP,
                                                unsigned char GPS_SCAN_TYPES_ENABLED,
                                                unsigned char GLO_SCAN_TYPES_ENABLED,
                                                unsigned char PROBE_POINT_FOR_SCAN,
                                                unsigned char TRACKING_MODE_CONTROL,
                                                unsigned char RESET_NOTCH_FILTERS
                                                );


/******************************************************************************/
/**
 This function configures the onboard Spectrum Analysis 
  
 \param SCAN_MODE              = 0 - Single Shot, 1 - Continuos
 \param SCAN_START_STOP        = 1 - start scan, 0 - stop scan, 2 - stop and restart scan 
 \param GPS_SCAN_TYPES_ENABLED = Bit Mask for GPS Scan types: 
                                 Bit 0 = Fast Scan, Bit 1 = Deep Scan 
 \param GLO_SCAN_TYPES_ENABLED = Bit Mask for GLONASS Scan Types: 
                                 Bit 0 = Fast Scan, Bit 1 = Deep Scan
 \param PROBE_POINT_FOR_SCAN   = Bit Mask for probe point to be used in collecting 
                                 spectrum analysis samples:
                                 Bit 0-3 to 1 for Probe points P1-P4
 \param TRACKING_MODE_CONTROL  = 0 - Disable tracking mode for jammers 
                                 1 - Enable tracking mode for jammers
 \param RESET_NOTCH_FILTERS    = Option to reset all the Notch filters currently
                                 assigned. When issued with a start option, this
                                 resets notch filters prior to Start. When issued
                                 with a stop option, this resets notch filters
                                 after stopping the scan.
                                 1 - Reset notch filters
                                 0 - Do not reset notch filters
 \param BDS_SCAN_TYPES_ENABLED = Bit 0 - enable Fast scan; Bit 7- enable Shallow scan

 \return true if successful, false if fail.


 *******************************************************************************/

QLIB_API unsigned char QLIB_GNSS_SpecAn_Control_V2( HANDLE hResourceContext,
                                                    unsigned char SCAN_MODE,
                                                    unsigned char SCAN_START_STOP,
                                                    unsigned char GPS_SCAN_TYPES_ENABLED,
                                                    unsigned char GLO_SCAN_TYPES_ENABLED,
                                                    unsigned char PROBE_POINT_FOR_SCAN,
                                                    unsigned char TRACKING_MODE_CONTROL,
                                                    unsigned char RESET_NOTCH_FILTERS,
                                                    unsigned char BDS_SCAN_TYPES_ENABLED
                                                    );

/******************************************************************************/
/**
This function sends a GNSS XO Factory Calibration Request for an APQ target.

\param RX_FREQ_KHZ             Carrier Frequency in KHz
\param OFFSET                  Downlink signal offset with reference to the 
                               carrier frequency.
\param POWER_LEVEL             The power level of the CW Tone in dBm 
\param XTAL                    The XTAL package used: 1 = TCXOMGR_XTAL_2016 
                                                      2 = TCXOMGR_XTAL_2520 
\param piStatus                Pointer to where the status will be stored 
\param pPostProcessor          Class to do WBIQ Post Processing at the end of each embedded WBIQ test 
\param sIQ_Filename            IQ Data file name.  Set to NULL to not collect IQ data 
 
\return true if successful, false if fail 
****************************************************************************/
QLIB_API unsigned char QLIB_GNSS_XO_Factory_Cal_Request(HANDLE          hResourceContext,
                                                        unsigned long   RX_FREQ_KHZ,
                                                        long            OFFSET,
                                                        short           POWER_LEVEL,
                                                        unsigned char   XTAL,
                                                        unsigned char   *piStatus,
                                                        void *pPostProcessor = NULL,
                                                        char *sIQ_Filename  = NULL);

/******************************************************************************/
/**
This function sends a GNSS TCXO Factory Calibration Request for an APQ target, 
and will await the results 

\param RX_FREQ_KHZ             Carrier Frequency in KHz
\param OFFSET                  Downlink signal offset with reference to the 
                               carrier frequency.
\param POWER_LEVEL             The power level of the CW Tone in dBm 
\param XTAL                    The XTAL package used: 1 = TCXOMGR_XTAL_2016 
                                                      2 = TCXOMGR_XTAL_2520
\param piStatus                Pointer to where the status will be stored 
\param iTimeoutValue           Number of miliseconds to wait for response. 
\param pPostProcessor          Class to do WBIQ Post Processing at the end of each embedded WBIQ test 
\param sIQ_Filename            IQ Data file name.  Set to NULL to not collect IQ data 
 
\return true if successful, false if fail 
****************************************************************************/
QLIB_API unsigned char QLIB_GNSS_XO_Factory_Cal_Request_WithWait(HANDLE          hResourceContext,
                                                                 unsigned long   RX_FREQ_KHZ,
                                                                 long            OFFSET,
                                                                 short           POWER_LEVEL,
                                                                 unsigned char   XTAL,
                                                                 unsigned char   *piStatus,
                                                                 unsigned long   iTimeoutValue,
                                                                 void *pPostProcessor = NULL,
                                                                 char *sIQ_Filename  = NULL);


/****************************************************************************/
/**
This function will let a caller know if it is safe to process IQ packets even 
in cases where the event ending IQ collection has not been received 
 
\return true if it is safe to process IQ packets, false otherwise 
*/
QLIB_API bool QLIB_GNSS_ALLOW_POST_PROCESSING_WITHOUT_EVENT(HANDLE hResourceContext); 

/******************************************************************************/
/**
This function will start a Sensor Assisted Positioning (SAP) session by starting 
a GNSS track. 
 
\param _oPDAPIRequest     - Parameters for the PDAPI Request required to start the SAP session 
\param _sAccFileName      - File name of the .csv file with the accelerator data.  Set to "\0" 
                            to not create file
\param _sGyroFileName     - File name of the .csv file with the gyroscope data.  Set to "\0" 
                            to not create file 
\param _sGyroTempFileName - File name of the .csv file with the gyroscope temperature data.  Set to "\0" 
                            to not create file 
 
\return true if the successful, false if fail 
*/
QLIB_API bool QLIB_DIAG_GNSS_Start_SAP_Session(HANDLE hResourceContext,
                                               void *_oPDAPIRequest,
                                               char *_sAccFileName,
                                               char *_sGyroFileName,
                                               char *_sGyroTempFileName); 

/******************************************************************************/
/**
This function will start a Sensor Assisted Positioning (SAP) session by starting 
a GNSS track. 
 
\param _oPDAPIRequest - Parameters for the PDAPI Request required to start the SAP session 
 
\return true if the successful, false if fail 
*/
QLIB_API bool QLIB_DIAG_GNSS_Stop_SAP_Session(HANDLE hResourceContext, void* _oPDAPIRequest); 

/******************************************************************************/
/** 
This function will return the collected Sensor Assited Positioning (SAP) data 
 
\param pAccData - location to receive the pointer to the Acceleration data.  Must be a vector<GNSS_Sensors_Sensor_Data> 
\param pGyroDAta - location to receive the pointer to the Gyroscope data. Must be a vector<GNSS_Sensors_Sensor_Data> 
\param pGyroTempData - location to receive the pointer to the Gyroscope Temperature data. Must be a vector<GNSS_Sensors_Sensor_Data> 
\param pLogVersion - location to receive the GNSS Sensors log version 
 
\return true if successful, false otherwise. 
 
NOTE: this function returns the pointers to the data storage area.  Any changes made to the data will impact future calls to 
this function.  It is strongly recommended that it be followed immediates by a call to QLIB_DIAG_GNSS_Clear_SAP_Data()

*/
QLIB_API bool QLIB_DIAG_GNSS_Get_SAP_Data(HANDLE hResourceContext, void **pAccData, void **pGyroData, void **pGyroTempData, unsigned int * pLogVersion);

/******************************************************************************/
/**
This function will clear the collected Sensor Assisted Positioning (SAP) data  
*/
QLIB_API bool QLIB_DIAG_GNSS_Clear_SAP_Data(HANDLE hResourceContext); 



/********************************************************************************/
/**
This function will set the minimum time between GNSS_Sensor Axis change detections. 
If an axis change is detected during this interval it will be ignored. 
 
\param iMinAxisChangeTime_ms - Minimum time between axis change detections in ms  
*/
QLIB_API bool QLIB_DIAG_GNSS_Set_Sensor_Min_Axis_Change_Time(HANDLE hResourceContext, long iMinAxisChangeTime_ms); 

/*********************************************************************************/
/** Sets the maximum expected number of logs during the current/next collection

\param iLogCount = expected number of logs
\return true if the size was successfully set, false otherwise.
*******************************************************************************/
QLIB_API bool QLIB_DIAG_GNSS_Set_Sensor_Max_Log_Size(HANDLE hResourceContext, unsigned int iLogCount); 



/*******************************************************************************/
/**
   Allows the reading of data from .csv files - primarily for debugging purposes 
    
   \param char *sACC_Filename - Name of the file containing the acc data. 
   \param char *sGYRO_Filename - Name of the file containing the gyro data. 
   \param char *sGYROTEMP_Filename - Name of the file containing the gyro temp data. 
   \return true if the files are read in successfully 
 *******************************************************************************/
QLIB_API bool QLIB_DIAG_GNSS_loadDataFromFile(HANDLE hResourceContext, char *sACC_Filename, char *sGYRO_Filename, char *sGYROTEMP_Filename); 


/*******************************************************************************/
/**
   Retrieves the raw I and Q data collected by the IQ Packet Parser 
    
   \param  char **pm_pI_Samples - Pointer to receive the pointer to the I Samples 
   \param  char **pm_pQ_Samples - Pointer to receive the pointer to the Q Samples 
   \param  unsigned int *pu_SampleCouint - Pointer to receive the number of samples collected. 
 *******************************************************************************/
QLIB_API bool QLIB_DIAG_GNSS_getRawIQMeasurements(HANDLE hResourceContext, char **pm_pI_Samples, char **pm_pQ_Samples, unsigned int *pu_SampleCount); 

/******************************************************************************/
/**
This function instructs the Location engine to start a factory IQ collect.

This command will check the status field and return false if the command was rejected.

\param pFactoryGPS_StartIQ_TestParams = structure of type GNSS_Factory_IQ_Test_params, which contains
                                        all input parameters.
\param pResponse                      = structure of type GNSS_Factory_IQ_Test_response_header, which contains 
                                        all of the output results from the immediate response.

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API bool QLIB_DIAG_GNSS_START_FACTORY_IQ_TEST(
                                                   HANDLE hResourceContext,
                                                   void* pParams,
                                                   void* pResponse,
                                                   char & iStatus
                                                   ); 

/******************************************************************************/
/**
This function instructs the Location engine to start a factory IQ collect.  It then waits for the respoinse

This command will check the status field and return false if the command was rejected.

\param pGPS_StartIQ_TestParams       = structure of type DIAG_GNSS_START_FACTORY_IQ_TEST, which contains
                             all input parameters.

\param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                             If NULL or empty string, then no data will be stored to file.

\param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API bool QLIB_DIAG_GNSS_START_FACTORY_IQ_TEST_CollectResults(
    HANDLE hResourceContext,
    void *pGPS_StartIQ_TestParams,
    char *sIQ_FileName,
    char *sFFT_FileName,
    char& piStatus
   ); 

   #ifdef __cplusplus
}   // extern "C"
#endif

            #endif  // defined(_QMSL_CGPS_GNSS_H)
