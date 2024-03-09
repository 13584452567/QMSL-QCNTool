/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_AGPS.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_APGS
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QLIB_AGPS_FTM_H)
#define _QLIB_AGPS_FTM_H

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
                     AGPS FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   Factory Test Mode AGPS, 3.2.1 Subcommand 0 - set test mode

   Enables/disables AGPS Test Mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iOnOff = 0 - OFF disable test mode, 1 - ON enable test mode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AGPS_SET_TEST_MODE( HANDLE hResourceContext, unsigned char iOnOff );

   /******************************************************************************/
   /**
   Factory Test Mode AGPS, 3.2.2 Subcommand 1 - self-test

   Starts a self-test of AGPS-based MSM; tests include memory test, signal
           processing test, and boot code checksum test

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iPassFail = returns 1 byte with 3 LSB indicators:
                         0x01 = Memory result
                    0x02 = STP result
                    0x03 = Bootcode Checksum

                    these 3 results are 0 if self test passes, 1 if self test fails

                    This field should be and with 0x07 and if the result is zero,
                    then all 3 modes are pass.

   \return true if sent successfully, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AGPS_SELF_TEST( HANDLE hResourceContext, unsigned char* iPassFail  );

   /******************************************************************************/
   /**
   Factory Test Mode AGPS, 3.2.3 Subcommand 2 - set idle mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   Places the Location Services Manager (LSM) task in idle mode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AGPS_IDLE_MODE( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode AGPS, 3.2.4 Subcommand 3 - standalone test mode

   Verifies the GSP operation in a standalone mode of AGPS-based MSM

      In this mode, an AGPS-based MSM performs position fixes at the rate of 1 sec continuously. The
      results of each fix are sent out as MMGPS LOG packets. The results could include Satellite
      Vehicle (SV) statistics (like SNR, Doppler, code phase, uncertainties, etc.), calculated positions,
      and/or statistics of the RF path (oscillator frequency bias, AGC calibration, DC offset
      adjustments, etc.).
      This test is repetitive and is performed every second. This can be stopped by sending either an
      Idle Mode command or by sending a request to start a different test.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AGPS_STANDALONE_TEST_MODE( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode AGPS, 3.2.5 Subcommand 4 - SV tracking

   Processes a single SV continuously and produces results on a regular basis

      The results, which include SV SNR, Doppler, code phase, etc., are sent out as MMGPS 20
      LOG packets.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param = iSatelliteVehicleId = SV identifier, 0-32

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AGPS_SV_TRACKING( HANDLE hResourceContext, unsigned char iSatelliteVehicleId );

   /******************************************************************************/
   /**
   Factory Test Mode AGPS, 3.2.6 Subcommand 5 - IQ capture

   Captures a snapshot of the baseband IQ data

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iCenterFreq_Hz = center frequency (Hz)
   \param iSampleFreq_Hz = (1 MHz or 2MHz)
     \code
         0 - I/Q Capture Sampling frequency 1MHz
       1 - I/Q Capture Sampling frequency 2KHz
     \endcode
   \param iStartDelay = start delay (ms)
   \param iAutoCenter = auto center frequency, 0-No auto center, 1-Auto Center
   \param piMaxRecordSize = output, maximum number of samples take.  Each sample is (1) I sample and (2) Q sample.
                            Each I sample is a 16-bit signed number, as is each Q sample.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AGPS_IQ_CAPTURE
   (
      HANDLE hResourceContext, unsigned long iCenterFreq_Hz, unsigned long iSampleFreq_Hz,
      unsigned short iStartDelay, unsigned char iAutoCenter, unsigned short* piMaxRecordSize
   );

   /******************************************************************************/
   /**
   Factory Test Mode AGPS, 3.2.7 Subcommand 6 - get IQ data

   Returns the baseband IQ data

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pIQ_Data = Buffer of 256 16-bit numbers, representing 128 pairs of I and Q samples
   \param piRecord = The record number that is being requested.  A group of 256 samples is a record.
                 Each sample is either an I or a Q sample of 16-bits.  The order is I0, then Q0,
                 then I1 then Q1, to I127 and Q127.

                     The response packet returns the actual record number that is returned, and
                 this value is updated with the value stored in the response packet.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AGPS_GET_IQ_DATA
   ( HANDLE hResourceContext, short* piIQ_Data, unsigned short* piRecord );

   /******************************************************************************/
   /**
   Factory Test Mode AGPS, 3.2.8 Subcommand 122 - get C/N

   Returns the AGPS C/N in units 1/10dB.  Uses the LSM to perform an IQ capture
   and spectral analysis

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piCTON = Output, C/N value in dB multiplied by 10

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AGPS_GET_CTON
   ( HANDLE hResourceContext, long* piCTON );



#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_AGPS_FTM_H)

