/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_CDMA_Intelliceiver_RF.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_CDMA_Intelliceiver_RF
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_CDMA_INTELLICEIVER_RF_H)
#define _QMSL_CDMA_INTELLICEIVER_RF_H

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
                     FTM CDMA RF Calibration API V2
   *******************************************************************************/

   /******************************************************************************/
   /**
   FTM CDMA RF Cal API v2 3.1 (80-V2376-1) Commit RF Calibration to NV

   The Commit RF Cal command is used to store the current state of the RF calibration into NV.
   The Version 2 RF calibration APIs maintain states internally, temporarily recording any receiver
   calibration updates. When calibration is complete, all values can be written once to NV with a
   single command, eliminating the need to externally compute Rx calibration NV and resend the
   values to the mobile. In platforms that support Rx diversity, Rx calibration for both Rx chains are
   written to NV with a single execution of this command.
   The Commit API is optional and need not be used. Rx calibration may still be written to NV with
   individual NV write requests, as per the old API. NV remains unchanged until the command is
   issued, so the Version 2 calibration APIs may be used safely for testing, without concern of
   corrupting existing calibration data. All uncommitted changes will be lost when the mobile
   reboots or executes a runtime switch into Online mode.


   \param  iBandClass,
            Band to be written to NV
            0 = band class 0
            1 = band class 1
            3 = band class 3
            4 = band class 4
            5 = band class 5
            6 = band class 6
         Values 2 and 7 through 20 are reserved for future CDMA use

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA_API2_COMMIT_RF_TO_NV( HANDLE hResourceContext, unsigned short iBandClass );


   /******************************************************************************/
   /**
   FTM CDMA RF Cal API v2 3.2 (80-V2376-1) Calibrate DVGA

   This command calculates and returns the DVGA offset for the current channel of operation. This
   is a frequency-dependent API, and the DVGA offset returned will be automatically associated
   with the correct bin in the channel list.
   The input parameters are the receiver path the user wants to calibrate (path 1 is only supported on
   platforms that implement Rx diversity) and the input power at the antenna. This input power is in
   AGC units. To convert input power in dBm to AGC units in a 102.4-dB dynamic range platform
   with a minimum RSSI of -115 dBm, use the equation:
      -512 + 10*(InputPower(dBM) + 115)

   The input power should be selected such that the baseband input to the MSM is sufficiently
   strong but will not saturate the baseband ADC. This is a target-dependent value and should be
   selected based on the expected RF gain for a given gain lineup with margin for part-to-part
   variation.

   IntelliCeiver platforms may return more than one DVGA offset calibration value. The number of
   calibration values that are returned will be indicated in the Calibration Count field of the response
   packet

   \param   iPath,   0 - Primary Rx path
               1 - diversity Rx path
   \param   iInputPower   Input power at the antenna, in AGC units (1/10th dB)
   \param  iCount[in/out]      [in] Size of iDVGAarray Buffer
                        [out] Calibration Count (N)
   \param  iDVGAArray DVGA value array { DVGA_0, ... DVGA_N }

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA_API2_CALIBRATE_DVGA( HANDLE hResourceContext,
         unsigned char iPath,
         short iInputPower,
         unsigned char* iCount,
         unsigned short* iDVGAarray );


   /******************************************************************************/
   /**
   FTM CDMA RF Cal API v2 3.3 (80-V2376-1) Calibrate LNA

   This command calculates and returns the LNA offset for a particular gain state for the current
   channel of operation. This is a frequency-dependent API, and the LNA offset returned will be
   automatically associated with the correct bin in the channel list.
   The input parameters are the receiver path the user wants to calibrate (path 1 is only supported on
   platforms that implement Rx diversity), the LNA gain step to calibrate, and the input power at the
   antenna. This input power is in AGC units. To convert input power in dBm to AGC units, use the
   equation described in Section 3.2.

    IntelliCeiver platforms may return more than one LNA offset calibration value. The number of
   calibration values that are returned will be indicated in the Calibration Count field of the response
   packet.


   \param   iPath,   0 - Primary Rx path
               1 - diversity Rx path
   \param  iLNAstep LNA step
               .. 0 = first LNA gain step (G0-G1)
               .. 1 = second LNA gain step (G1-G2)
               .. 2 = third LNA gain step (G2-G3)
               .. 3 = fourth LNA gain step (G3-G4)
    \param   iInputPower   Input power at the antenna, in AGC units (1/10th dB)
   \param  iCount[in/out]      [in] Size of iLNAarray Buffer
                        [out] Calibration Count (N)
   \param  iLNAarray LNA value array { LNA<iLNAstep>0, ... LNA<iLNAstep>N }

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_CDMA_API2_CALIBRATE_LNA(   HANDLE hResourceContext,
         unsigned char   iPath,
         short  iInputPower,
         unsigned char   iLNAstep,
         unsigned char*   iCount,
         unsigned short* iLNAarray );

   /******************************************************************************/
   /**
   FTM CDMA RF Cal API v2 3.4 (80-V2376-1) Calibrate IM2

   This command returns the optimum IM2 value for the current band. This is a
   frequency-independent calibration item. The input parameter is the receiver path the user
   wants to calibrate (path 1 is only supported on platforms that implement Rx diversity).
   IntelliCeiver platforms may return more than one IM2 value. The number of calibration values
   that are returned will be indicated in the Calibration Count field of the response packet.
   The Suppression field returns a measure of the IM2 performance improvement. Suppression will
   vary from part-to-part and is described in the IM2 calibration with suppression section of [Q4].


   \param   iPath,   0 - Primary Rx path
               1 - diversity Rx path

   \param  iSuppression Characteristic IM2 performance vs. uncalibrated (dB)
   \param  iCount[in/out]      [in] Size of aiIM2result Buffer
                        [out] Calibration Count (N)
   \param  aiIM2result         IM2 result array { I 0, Q 0, Transconductance 0, ...  I N, Q N, Transconductance N}

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA_API2_CALIBRATE_IM2(   HANDLE hResourceContext,
         unsigned char iPath,
         unsigned short* iSuppression,
         unsigned char* iCount,
         unsigned char* iIM2result );

   /******************************************************************************/
   /**
   FTM CDMA RF Cal API v2 3.5 (80-V2376-1) Calibrate  IntelliCeiver

   This command calibrates the internal circuitry of IntelliCeiver chips. This is a
   frequency-independent calibration item. The parameters are a receive path, for which only
   path 0 is supported, and the power level of the input signal, in AGC units, as described in

   Section 3.2.
   The calibration input waveform must be an unmodulated carrier 1-MHz positive offset from
   the center of the channel where the calibration is performed. The calibration channel is not
   significant, though it should be selected such that the input waveform will not be affected by any
   rolloff in band selection filters. It is recommended that this calibration be performed on the same
   channel on which the IM2 calibration is performed, but it is not necessary.
   The response packet contains a Success field, indicating if the calibration was successful. A zero
   returned in this field indicates a problem was detected during calibration. Check the levels and
   setup of the test equipment and repeat the calibration. The remaining data is an opaque BLOB
   containing the IntelliCeiver calibration. The Response Length field will be used to indicate the
   number of valid data bytes in the packet. The calibration BLOB data are the bytes following the
   packet header and success field, to the end of the packet indicated by the Response Length.


   \param   iPath,   0 - Primary Rx path
               1 - diversity Rx path

   \param  iInputPower   Input power at the antenna, in AGC units (1/10th dB)
   \param  iSizeOfBLOB [in/out]      [in] Size of iCalibtrationBLOB input buffer
                              [out] Actual size of calibration BLOB returned from embedded side
   \param  iCalibrationBLOB         Opaque calibration value that must be written to the
                              IntelliCeiver calibration NV item exactly as returned

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA_API2_CALIBRATE_INTELLICEIVER(   HANDLE hResourceContext,
         unsigned char iPath,
         short iInputPower,
         unsigned char* iSizeOfBLOB,
         unsigned char* iCalibrationBLOC );


   /******************************************************************************/
   /**
   FTM CDMA RF Cal API v2 3.6 (80-V2376-1) Calibrate IntelliCeiver RC Tune

   This API triggers a R/C search to find the optiomal Tx Notch location that results in Jammer Detector not tripping while in the prescense of a CDMA jammer

   \param   iPath,   0 - Primary Rx path
               1 - Diversity Rx path

   \param  iStatus [out]   Status returned from embedded side
                     0 - Always tripped (Errors)
                     1 - No errors

   \param  iResistance [out]   Resistence value returned

   \param  iCapacitance [out]   Capacitance value returned

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA_API2_CALIBRATE_INTELLICEIVER_RC_TUNE(   HANDLE hResourceContext,
         unsigned char iPath,
         unsigned char* iStatus,
         unsigned short* iResistance,
         unsigned short* iCapacitance );

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_CDMA_INTELLICEIVER_H)
