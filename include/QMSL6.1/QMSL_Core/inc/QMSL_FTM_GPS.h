/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Core/inc/QMSL_FTM_GPS.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_GPS
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_GPS_H)
#define _QMSL_FTM_GPS_H

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
                     GPS FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   This command sets the linearity mode of the GPS RF Device.
   This is necessary for selecting the desired linearity mode.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iLinearityMode   = input, specifies the desired linearity mode of the device:
                     Low Linearity or High Linearity
   \code
        0 = FTM_GPS_SET_LINEARITY_MODE_LL               =  Low Linearity Mode,
      1 = FTM_GPS_SET_LINEARITY_MODE_HL               =  High Linearity Mode,
      2 =   FTM_GPS_SET_LINEARITY_MODE_HL_AWS            =  High Linearity Mode for AWS band
      Refer to the enumeration ftm_gps_linearity_mode_enum_type for bit mask definitions.
   \endcode
   \param piStatus                                 = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GPS_SET_LINEARITY_MODE(
      HANDLE hResourceContext,
      unsigned char iLinearityMode,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This command enables or disables the periodic steady-state DC correction at 1Hz rate.
   The periodic steady-state DC correction needs to be disabled prior to performing the IM2 calibration.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iEnable_DC_correction   = input, enables or disables the steady-state periodic DC correction
   \code
        0 = FTM_GPS_DISABLE_SS_DC_CORRECTION=  Disable periodic steady-state DC correction,
      1 = FTM_GPS_ENABLE_SS_DC_CORRECTION   =  Enable periodic steady-state DC correction
      Refer to the enumeration ftm_gps_enable_ss_dc_correction_enum_type for bit mask definitions.
   \endcode
   \param piStatus                        = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GPS_ENABLE_SS_DC_CORRECTION(
      HANDLE hResourceContext,
      unsigned char iEnable_DC_correction,
      unsigned char* piStatus
   );


   /******************************************************************************/
   /**
   This command prepares the GPS RFIC for the IM2 calibration by programming
   its PLL to a different LO output frequency from the normal mode of operation.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iReserved      = input, reserved for future usage or enhancement
   \param piStatus         = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GPS_INIT_FOR_IM2_CAL(
      HANDLE hResourceContext,
      unsigned char* piStatus
   );


   /******************************************************************************/
   /**
   This command triggers a single iteration of the IM2 calibration.
   This command returns the values of DC DACs and IM2 DACs that were found
   to minimize the DC component.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iI_Q_channel_id   = input, defines the channel to use for IM2 calibration: I-channel or Q-channel
   \code
        0 = FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_CHANNEL_I = Perform single IM2cal iteration on I-channel,
      1 = FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_CHANNEL_Q = Perform single IM2cal iteration on Q-channel
      Refer to the enumeration ftm_gps_do_single_im2_channel_enum_type for bit mask definitions.
   \endcode
   \param iDC_cancellation_method   = input, defines which DACs to use for DC cancellation: DC DACs or IM2 DACs
   \code
        0 = FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_METHOD_WITH_DC_DACS  = Cancel DC component using DC DACs,
      1 = FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_METHOD_WITH_IM2_DACS = Cancel DC component using IM2 DACs
      Refer to the enumeration ftm_gps_do_single_im2_cal_iteration_method_enum_type for bit mask definitions.
   \endcode
   \param iDAC_search_space   = input, defines the DAC search space for IM2 calibration: Full search space or Vicinity search space
   \code
        0 = FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_FULL_SEARCH_SPACE     = Full search space (applies to DAC code),
      1 = FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION_VICINITY_SEARCH_SPACE = Vicinity search around previous optimim value (applies to DAC code)
      Refer to the enumeration ftm_gps_do_single_im2_cal_iteration_search_space_enum_type for bit mask definitions.
   \endcode
   \param iPrevious_I_DAC_value            = input,  Previously found optimum value of the I-channel DC DAC. DC DAC if Method is DC DAC. IM2 DAC if Method is IM2 DAC. This is an unsigned number.
   \param iPrevious_Q_DAC_value            = input,  Previously found optimum value of the Q-channel DC DAC. DC DAC if Method is DC DAC. IM2 DAC if Method is IM2 DAC. This is an unsigned number.
   \param piCurrent_I_DAC_optimum_value    = output, Optimum value of the I-channel DC or IM2 DAC. DC DAC if Method is DC DAC. IM2 DAC if Method is IM2 DAC. This is an unsigned number.
   \param piCurrent_Q_DAC_optimum_value    = output, Optimum value of the Q-channel DC or IM2 DAC. DC DAC if Method is DC DAC. IM2 DAC if Method is IM2 DAC. This is an unsigned number.
   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GPS_DO_SINGLE_IM2_CAL_ITERATION(
      HANDLE hResourceContext,
      unsigned char iI_Q_channel_id,
      unsigned char iDC_cancellation_method,
      unsigned char iDAC_search_space,
      unsigned short iPrevious_I_DAC_value,
      unsigned short iPrevious_Q_DAC_value,
      unsigned short* piCurrent_I_DAC_optimum_value,
      unsigned short* piCurrent_Q_DAC_optimum_value,
      unsigned char* piStatus
   );


   /******************************************************************************/
   /**
   This command gets the following fields of GPS RF Status:
   BP Mean I, BP Mean Q, BP Amplitude I, and BP Amplitude Q.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext      = Resource context that was returned from the call to ConnectServer()
   \param piBP_Mean_I         = output, BP_Mean from Aries for I-channel. This is a signed number.
   \param piBP_Mean_Q         = output, BP_Mean from Aries for Q-channel. This is a signed number.
   \param piBP_Amplitude_I      = output, BP_Amplitude from Aries for I-channel. This is a signed number.
   \param piBP_Amplitude_Q      = output, BP_Amplitude from Aries for Q-channel. This is a signed number.
   \param piStatus            = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GPS_GET_BP_MEAN_AND_AMPL(
      HANDLE hResourceContext,
      short* piBP_Mean_I,
      short* piBP_Mean_Q,
      short* piBP_Amplitude_I,
      short* piBP_Amplitude_Q,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This command returns the C/No ratio in tenths of dB of the GPS RFIC RF chain.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext      = Resource context that was returned from the call to ConnectServer()
   \param piCNo_tenths_dB      = output, C/No ratio of the GPS receivers RF chain in tenths of dB.
                          This is a signed number.
   \param piStatus            = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GPS_GET_CN0(
      HANDLE hResourceContext,
      short* piCNo_tenths_dB,
      unsigned char* piStatus
   );


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_GPS_H)

