/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Core/inc/QMSL_QCN.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_QCN
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#pragma once

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
                     QCN
   *******************************************************************************/
   /******************************************************************************/
   /**
   Upload a HEX file from the PC to the phone.

   This is also commonly referred to as "software download," but in a technical sense
   the information is being transferred from the PC to the phone, so the function name
   is based on the "upload" operation

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFileName = the local path and filename of the hex file to upload.
   \param sSPC = Service Provider Code, normally "000000"
   \param bClearErrorLog = true to clear phone's NV items which start the most recent errors.
   \param bOverrideModelCheck = true to allow a mismtach between the HEX file and the phone's model identifier
   \param bSkipReset = true to skip the reset of the phone after the HEX file is downloaded
   \param bUseCustomArmProg = true to always use "ARMPRG.HEX"

                        false, the ARM PROG file will be determined by querying the phone
                        model and selecting the correct APRGxxxx.HEX file.

                        These files are always in the QPST Server executable folder, usually
                        C:\Program Files\QPST\bin

   \param bUploadArmProg = true to send ARMPROG, false to not send ARMPROG
   \param bDoAutoRestoreBackup = true to backup the phone's NV data to the QCN file indicated
                           by sAutoRestoreBackupName.
   \param sAutoRestoreBackupName = Name of the QCN file to backup the phone's data into.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadHexFile
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sSPC,
      unsigned char  bClearErrorLog,
      unsigned char  bOverrideModelCheck,
      unsigned char  bSkipReset,
      unsigned char  bUseCustomArmProg,
      unsigned char  bUploadArmProg,
      unsigned char  bDoAutoRestoreBackup,
      char* sAutoRestoreBackupName
   );

   /******************************************************************************/
   /**
   Upload a QCN (NV memory contents) file from the PC to the phone.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFileName = Path and file name of QCN file
   \param sSPC = Service provider code, usually "000000"
   \param bAutoRestore = true always, when sending a QCN file to the phone
   \param bSkipReset = true to not reset after QCN file uploaded, false to force reset after QCN file is uploaded
   \param bAllowEsnMismatch = true to allow the ESN to be mismatched between the QCN file and the phone
   \param bIgnorePhoneModel = true to allow the phone model number to be mismatched between the QCN file and the phone

   \return true if successful, false if fail.

   \warning This function does not support xQCN. To restore xQCN file, please use QLIB_UploadQcnFile_V2

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadQcnFile
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sSPC,
      unsigned char bAutoRestore,
      unsigned char bSkipReset,
      unsigned char bAllowEsnMismatch,
      unsigned char bIgnorePhoneModel
   );

   /******************************************************************************/
   /**
   Upload a QCN (NV memory contents) file from the PC to the phone.

   Note: This function requires the use of QPSTServer.exe and AtmnServer.exe

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFileName = Path and file name of QCN or xQCN file
   \param sSPC = Service provider code, usually "000000"
   \param bAllowEsnMismatch = true to allow the ESN to be mismatched between the QCN file and the phone


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadQcnFile_V2
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sSPC,
      unsigned char bAllowEsnMismatch
   );

   /******************************************************************************/
   /**
   Download a QCN (NV memory contents) file from the phone to the PC.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFileName = Path and file name of QCN file
   \param sSPC = Service provider code, usually "000000"

   \return true if successful, false if fail.

   \warning. This function does not support xQCN. To backup NV as xQCN file, please use QLIB_DownloadQcnFile_V2

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DownloadQcnFile
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sSPC
   );

   /******************************************************************************/
   /**
   Download a QCN (NV memory contents) file from the phone to the PC.

   Note: This function requires the use of QPSTServer.exe and AtmnServer.exe

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param sFileName = Path and file name of QCN file. If the file extension is "xqcn", a XQCN file will be created
   
   \param sSPC = Service provider code, usually "000000"

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DownloadQcnFile_V2
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sSPC
   );


#ifdef __cplusplus
}   // extern "C"
#endif
