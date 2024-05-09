/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WP/inc/QMSL_WP7_PVK.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_WP7_PVK
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_WP7_PVK_H)
#define _QMSL_WP7_PVK_H

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
                     WP7 PVK
   *******************************************************************************/

   /******************************************************************************/
   /**

   QLIB_WP7_WRITE_PVK - Refer to 2.7.3 Advanced write PVK in 80-N4255-1

   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \Param  [in]       pPVK_FileName = PVK file path
                  Note: there is a limit of 1k size for this file. 

   \Param  [out]      iStatus

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char  QLIB_WP7_WRITE_PVK( HANDLE hResourceContext, char* pPVK_FileName, unsigned long *iStatus);


   /******************************************************************************/
   /**

   QLIB_API - Refer to 2.7.3 Advanced write PVK in 80-N4255-1


   \Param  [in]       dppBuffer = a file containg buffer that needs to be written to dpp partition. 
                  there will be no processing done on the file. it will simply be sent as is. 
                 any guid or size information must be embedded into the file itself. 
                 Note: there is limit of 5K 

   \Param  [out]      iStatus

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_WP7_WRITE_DPP_Buffer( HANDLE hResourceContext, char *nonPvkDppBufferFile, unsigned long *iStatus);
   

   /******************************************************************************/
   /**

   QLIB_WP7_WRITE_PVK - Refer to 2.7.4 Advanced commit DPP in 80-N4255-1

   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \Param  [out]      iStatus

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char  QLIB_WP7_COMMIT_DPP( HANDLE hResourceContext, unsigned long* iStatus);


   /******************************************************************************/
   /**
   QLIB_WP7_SWITCH_OFF_FTM - it is a command extended from 80-N4255-1. 

   Note: it is not part of the normal modem command. It is an OEM based command strictly for the use of WP7.
   We are adding feature that would keep the device into the FTM mode until this command is sent. 

   Packet that it sends is: 75, 0, 1, 0

   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \Param  [out]      iStatus

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char  QLIB_WP7_SWITCH_OFF_FTM(HANDLE hResourceContext, unsigned long* iStatus);

   

   /******************************************************************************/
   /**

   QLIB_WP7_WRITE_PVK - Refer to 2.7.4 Advanced check if DPP is written in 80-N4255-1

   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \Param  [out]      iDPP_Written

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char  QLIB_WP7_CHECK_DPP_WRITTEN( HANDLE hResourceContext, unsigned long* iDPP_Written);

   /******************************************************************************/
   /**
   Perform interpolation on monotonic x,y data

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param X [input] Input independent array (float)

   \param Y [input] Input dependent array (float)

   \param iInLen [input] Array length of input arrays (x,y) inLen

   \param X1 [input]  independent values for which output should be
          computed

   \param iOutLen [input] Array length of array x1

   \param Y1 [output]  Interpolated output.

   \return true if successful, false otherwise

   *******************************************************************************/

   #ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_WP7_PVK_H)
