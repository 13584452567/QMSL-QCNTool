/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Core/inc/QMSL_QFUSE.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_QFUSE
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_QFUSE_H)
#define _QMSL_QFUSE_H

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
                     QFUSE FTM
   *******************************************************************************/

   /******************************************************************************/
   /**

   QFUSE Programming 2.1 FTM_FUSE_READ

   \param   iChainSelect =   0 = Configuraiton chain

         iWriteStatus =   0 = Success
                     1 = Read operation Failure
                     2 = Write operation Failure
                     3 = Operation on selected chain not supported

         aConfigRegister = an array of 5 elements and size of each element is 4 bytes.

   \return true if successful, false if failure

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QFUSE_READ
   (
      HANDLE hResourceContext,
      unsigned short iChainSelect,
      unsigned short* iReadStatus,
      unsigned long   aConfigRegister[5]
   );


   /******************************************************************************/
   /**

   QFUSE Programming 2.2 FTM_FUSE_WRITE

   \param   iChainSelect =   0 = Configuraiton chain

         iWriteStatus =   0 = Success
                     1 = Read operation Failure
                     2 = Write operation Failure
                     3 = Operation on selected chain not supported

         aConfigRegister = an array of 5 elements and size of each element is 4 bytes.

   \return true if successful, false if failure

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QFUSE_WRITE
   (
      HANDLE hResourceContext,
      unsigned short   iChainSelect,
      unsigned short* iWriteStatus,
      unsigned long   aConfigRegister[5]
   );

   /******************************************************************************/
   /**

   QFUSE Programming  FTM_FUSE_WRITE_V2

   \param   iChainSelect =   Chain select value

         iWriteStatus =   0  Success
                     1  Read operation Failure
                     2  Write operation Failure
                     3  Operation on selected chain not supported


         iNumOfConfigRegister = number of register in aConfigRegister

         aConfigRegister = an array of configuration register

   \return true if successful, false if failure

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QFUSE_WRITE_V2
   (
      HANDLE hResourceContext,
      unsigned short  iChainSelect,
      unsigned short* iWriteStatus,
      unsigned short  iNumOfConfigRegister,
      unsigned long*  aConfigRegister
   );

   /******************************************************************************/
   /**

   QFUSE Programming  FTM_FUSE_READ_V2

   \param   iChainSelect =   chain select value

         iReadStatus =   0  Success
                     1  Read operation Failure
                     2  Write operation Failure
                     3  Operation on selected chain not supported


         iNumOfConfigRegister = number of register in aConfigRegister

         aConfigRegister = an array of configuration register

   \return true if successful, false if failure

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_QFUSE_READ_V2
   (
      HANDLE hResourceContext,
      unsigned short  iChainSelect,
      unsigned short* iReadStatus,
      unsigned short  iNumOfConfigRegister,
      unsigned long*  aConfigRegister
   );

   /******************************************************************************/
   /**

   QEPROM Programming  FTM_QEPROM_READ

   Read the raw and corrected value on a given row of QERPOM

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param   iRowAddress =   Row address

   \param   iLSBRaw      =   The raw value of least significant word (lower 32 bit value)

   \param   iMSBRaw      =   The raw value of most significant word (upper 32 bit value)

   \param   iLSBCorrected =   The corrected value of least significant word (lower 32 bit value)

   \param   iMSBCorrected =   The corrected  value of most significatn word (upper 32 bit value)

   \param   iReadStatus =   0  Success
                     1  Read operation Failure

   \return true if successful, false if failure

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QEPROM_READ
   (
      HANDLE hResourceContext,
      unsigned long iRowAddress,
      unsigned long* iLSBRaw,
      unsigned long* iMSBRaw,
      unsigned long* iLSBCorrected,
      unsigned long* iMSBCorrected,
      unsigned long* iReadStatus
   );


   /******************************************************************************/
   /**

   QEPROM Programming  FTM_QEPROM_WRITE

   Write the raw value on a given row of QEPROM

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param   iRowAddress =   Row address

   \param   iLSBRaw      =   The raw value of least significant word (lower 32 bit value)

   \param   iMSBRaw      =   The raw value of most significant word (upper 32 bit value)

   \param   iWriteStatus =   0  Success
                     1  Write operation Failure

   \return true if successful, false if failure

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QEPROM_WRITE
   (
      HANDLE hResourceContext,
      unsigned long iRowAddress,
      unsigned long iLSB,
      unsigned long iMSB,
      unsigned long* iWriteStatus
   );

   #ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_QFUSE_H)
