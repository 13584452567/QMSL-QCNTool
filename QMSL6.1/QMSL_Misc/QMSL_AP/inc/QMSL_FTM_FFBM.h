/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Misc/QMSL_AP/inc/QMSL_FTM_FFBM.h#5 $
 * $DateTime: 2016/04/04 17:51:51 $
 *
 *
 ******************************************************************************
 *
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_FFBM_H)
#define _QMSL_FTM_FFBM_H

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
   Factory Test Mode: Fast Factory Boot Mode (FFBM/MMOS) Commands: Set Next Boot Mode

   This command will set the device next boot mode to FFBM or HLOS mode.  The device boot method must support FFBM (Android) or MMOS (Windows Phone) feature. 
   The first target to support FFBM is MSM8x26.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param  iBootMode    The next boot mode after reset

                        0 = FFBM (Android) or MMOS (Windows)
                        1 = High Level Operating System (HLOS) Linux Android/Windows Phone

   \param iSubBootMode   The next sub boot mode after reset
                        
                        0 = Man-machine Interface
                        1 = Man-machine Interface + Modem                         

   \param iFTM_Error_Code FTM Error Code
                          0 = No Error

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FFBM_SET_MODE(  HANDLE hResourceContext, 
                                                   unsigned char iBootMode, 
                                                   unsigned char iSubBootMode, 
                                                   unsigned short *iFTM_Error_Code);

   /******************************************************************************/
   /**
   Factory Test Mode: Fast Factory Boot Mode (FFBM/MMOS) Commands: Get the current boot mode

   This command will return device current boot mode.  The device boot method must support FFBM (Android) or MMOS (Windows Phone) feature. 
   The first target to support FFBM is MSM8x26.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param  iCurrentBootMode    The current boot mode

                        0 = FFBM or MMOS
                        1 = High Level Operating System (HLOS) Linux Android/Windows Phone

   \param iCurrentBootSubMode   The current sub boot mode after reset
                        
                        0 = Man-machine Interface
                        1 = Man-machine Interface + Modem                         

  \param  iNextBootMode    The next boot mode after reset

                        0 = FFBM or MMOS
                        1 = High Level Operating System (HLOS) Linux Android/Windows Phone

   \param iNextBootSubMode   The next sub boot mode after reset
                        
                        0 = Man-machine Interface
                        1 = Man-machine Interface + Modem                         

   \param iFTM_Error_Code FTM Error Code
                          0 = No Error

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FFBM_GET_MODE(  HANDLE hResourceContext, 
                                                   unsigned short *iFTM_Error_Code,
                                                   unsigned char* iCurrentBootMode,
                                                   unsigned char* iCurrentBootSubMode,
                                                   unsigned char* iNextBootMode,
                                                   unsigned char* iNextBootSubMode);


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_FTM_FFBM_H)
