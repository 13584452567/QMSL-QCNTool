/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_XO_CAL.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_XO_CAL
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_XO_CAL_H)
#define _QMSL_FTM_XO_CAL_H

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

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_XO_DC_CAL

   SC2x

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_XO_Cal_Request[input] Pointer to FTM_XO_Cal_Request

   \param FTM_XO_Cal_Response[input] Pointer to FTM_XO_Cal_Response

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_DO_XO_DC_CAL (HANDLE hResourceContext, void * pFTM_XO_Cal_Request, void *pFTM_XO_Cal_Response);

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_XO_FT_CURVE_CAL

   SC2x

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_XO_Cal_Request[input] Pointer to FTM_XO_Cal_Request

   \param FTM_XO_Cal_Response[input] Pointer to FTM_XO_Cal_Response

   \return true if successful, false if fail.


   \warning
   *******************************************************************************/


   QLIB_API unsigned char QLIB_FTM_DO_XO_FT_CURVE_CAL (HANDLE hResourceContext, void * pFTM_XO_Cal_Request, void *pFTM_XO_Cal_Response);

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_ENH_XO_DC_CAL

   Enhanced XO Coarse DC Calibration

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_XO_Cal_Request[input] Pointer to FTM_ENH_XO_Cal_Request

   \param FTM_XO_Cal_Response[input] Pointer to FTM_XO_Cal_Response

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_DO_ENH_XO_DC_CAL (HANDLE hResourceContext, void * pFTM_ENH_XO_Cal_Request, void *pFTM_XO_Cal_Response);

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_ENH_XO_FT_CURVE_CAL

   Enhanced XO FT Curve and Fine DC Calibration.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_XO_Cal_Request[input] Pointer to FTM_XO_Cal_Request

   \param FTM_XO_Cal_Response[input] Pointer to FTM_XO_Cal_Response

   \return true if successful, false if fail.


   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_ENH_XO_FT_CURVE_CAL (HANDLE hResourceContext, void * pFTM_ENH_XO_Cal_Request, void *pFTM_XO_Cal_Response);

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_ENH_XO_FT_COLLECT_SAMPLE

   Enhanced FT Curve Sample collection. This command results in the phone
        collecting FT curve samples (to be later used for processing by the curvefit functions

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_XO_Cal_Request[input] Pointer to FTM_XO_Cal_Request

   \param FTM_XO_Cal_Response[input] Pointer to FTM_XO_Cal_Response

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_ENH_XO_FT_COLLECT_SAMPLE (HANDLE hResourceContext, void * pFTM_ENH_XO_Cal_Request, void *pFTM_XO_Cal_Response);

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_ENH_XO_DC_CAL_V2

   Enhanced XO Coarse DC Calibration

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_XO_Cal_Request[input] Pointer to FTM_ENH_XO_Cal_Request

   \param FTM_XO_Cal_Response[input] Pointer to FTM_XO_Cal_Response_v2

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_DO_ENH_XO_DC_CAL_V2 (HANDLE hResourceContext, void * pFTM_ENH_XO_Cal_Request, void *pFTM_XO_Cal_Response_v2);

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_ENH_XO_FT_CURVE_CAL_V2

   Enhanced XO FT Curve and Fine DC Calibration.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_XO_Cal_Request[input] Pointer to FTM_XO_Cal_Request

   \param FTM_XO_Cal_Response[input] Pointer to FTM_XO_Cal_Response_v2

   \return true if successful, false if fail.


   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_ENH_XO_FT_CURVE_CAL_V2 (HANDLE hResourceContext, void * pFTM_ENH_XO_Cal_Request, void *pFTM_XO_Cal_Response_v2);

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_ENH_XO_FT_COLLECT_SAMPLE_V2

   Enhanced FT Curve Sample collection. This command results in the phone
        collecting FT curve samples (to be later used for processing by the curvefit functions

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_XO_Cal_Request[input] Pointer to FTM_XO_Cal_Request

   \param FTM_XO_Cal_Response[input] Pointer to FTM_XO_Cal_Response_v2

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_ENH_XO_FT_COLLECT_SAMPLE_V2 (HANDLE hResourceContext, void * pFTM_ENH_XO_Cal_Request, void *pFTM_XO_Cal_Response_v2);

   /******************************************************************************/
   /**
   FTM RF Common, QLIB_FTM_XO_CALIBRATION

   A unified interface to perform all XO cal actions
      1. dc_coarse_cal
      2. collect_sample
      3. ft_curve_cal

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param xo_cal_command[input] xo cal action to perform

   \param xo_cal_version[input] xo cal version (only 3 supported currently)

   \param ftm_xo_cal_params[input] Pointer to ftm_xo_cal_parameter_type

   \param ftm_xo_cal_response[output] Pointer to FTM_XO_Cal_Response_v2

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_XO_CALIBRATION
   (
      HANDLE hResourceContext,
      unsigned short xo_cal_command,
      unsigned char xo_cal_version,
      void* ftm_xo_cal_params,
      void* ftm_xo_cal_response
   );

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, QLIB_FTM_SET_CALIBRATION_STATE

   This command is used to generate an Tx waveform of given type with specified attributes.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  icalState = 0 - CAL_STATE_INACTIVE
                  1 - CAL_STATE_ACTIVE
                  2 - CAL_STATE_INACTIVE_FTM_TEST

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_XO_CALH)
