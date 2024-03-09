/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_SWDL/inc/QMSL_QPHONEMS_SWDL.h#8 $
 * $DateTime: 2016/04/04 17:23:23 $
 *
 * DESCRIPTION: QMSL_QPHONEMS_SWDL
 ******************************************************************************
 *
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */

#if !defined(_QLIB_QPHONES_SWDL_H)
#define _QLIB_QPHONES_SWDL_H

#if !defined(_WINDOWS_)
#include "windows.h"
#endif

#include "QMSL_Core\inc\QMSL_Core.h"

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



   /**
      Call back for general SW Download event( replaces the other non-EFS call backs)

      Optional for NV backup/restore and normal download.  Must be used for boot loader and
      multimage download
   */
   //typedef unsigned char( *generalSWDownloadCB )
   //(
   //   unsigned char* pEventStructure   // type union generalSwDownloadEvent_union, as defined in SoftwareDownload.h
   //   // Not declared explicitly here because general users do not need to
   //   // include the SWDownload.h file.
   //);

   /******************************************************************************
                  Streaming Download Diag
   *******************************************************************************/

   /******************************************************************************/
   /**
   Streaming Download ICD, 3.2.1 19 Hello packet, A specialized version of this
   command, to be used as a method to PING a phone in download mode.

   Call DOWNLOAD_Hello with default parameters.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DOWNLOAD_Ping( HANDLE hResourceContext );

      /******************************************************************************/
   /**
   Streaming Download ICD, 3.2.1 19 Hello packet

   This function sends the "hello" packet to the phone, and returns the response
   message, in its entirety, by copying the response packet to a user defined
   buffer.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iVersionNumber = Host shall set this field to indicate the maximum version
                           of this protocol that the host supports. The value for this
                     field is 0x03.

   \param iCompatibleVersion = Host shall set this field to indicate the lowest version
                               of the protocol that it supports. The value for this field
                        is 0x02.

   \param iFeatureBits = Host shall set these bits to indicate the negotiated set
                         of features requested to be used.

   \param pResponseBuffer = The entire response packet, as defined by section 3.2.2 of
                            the streaming download ICD.

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning The function must run in QPHONEMS mode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DOWNLOAD_Hello
   (
      HANDLE hResourceContext,
      unsigned char iVersionNumber,
      unsigned char iCompatibleVersion,
      unsigned char iFeatureBits,
      unsigned char* pResponseBuffer
   );


   /******************************************************************************/
   /**
   Streaming Download ICD, x.x.x QFprom Write

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRowAddress = Row Address

   \param iAddressType = 0 = Corrected Reads
                         1 = Raw Reads

   \param iMSBBytes = Most Significant Bytes.

   \param iLSBBytes = Least Significant Bytes

   \param iErrorCode = 0 if the operation is successful
                  otherwise, return the error code from error response message (0xD) defined in Streaming Download Protocol ICD

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning
   /******************************************************************************/
   /**
   Streaming Download ICD, x.x.x QFprom Write

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRowAddress = Row Address

   \param iAddressType = 0 = Corrected Reads
                         1 = Raw Reads

   \param iMSBBytes = Most Significant Bytes.

   \param iLSBBytes = Least Significant Bytes

   \param iErrorCode = 0 if the operation is successful
                  otherwise, return the error code from error response message (0xD) defined in Streaming Download Protocol ICD

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning The function must run in QPHONEMS mode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DOWNLOAD_QFprom_Write
   (
      HANDLE hResourceContext,
      unsigned long iRowAddress,
      unsigned long iMSBBytes,
      unsigned long iLSBBytes,
      unsigned long *iErrorCode
   );
   /******************************************************************************/
   /**
   Streaming Download ICD, QEprom Read

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRowAddress = Row Address

   \param iAddressType = 0 = Corrected Reads
                         1 = Raw Reads

   \param iMSBBytes = Most Significant Bytes.

   \param iLSBBytes = Least Significant Bytes

   \param iErrorCode = 0 if the operation is successful
                  otherwise, return the error code from error response message (0xD) defined in Streaming Download Protocol ICD
                  iMSBBytes, and iLSBBytes will be returned as 0

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning The function must run in QPHONEMS mode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DOWNLOAD_QFprom_Read
   (
      HANDLE hResourceContext,
      unsigned long iRowAddress,
      unsigned long iAddressType,
      unsigned long *iMSBBytes,
      unsigned long *iLSBBytes,
      unsigned long *iErrorCode
   );

   /******************************************************************************/
   /**
   Upload software image for NOR targets from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   NOR includes QSC1215...

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files

   The function will return once RESET command is issued after download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path
   \param sMBNFileName = MODEM file, usually "all.mbn"
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE
   \param bDownloadReset      = 0 == false (essentially skip reset after download)
                                1 == true 
                           If the flag is TRUE, phone will reset after downloaded
                           The flag must be set to FALSE
   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             QSC1215 = 5000;

   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                           QSC1215 = 5000;
                           
   \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   \warning Note, sDSP1, sMBR, sADSP files are not supported yet

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_UploadNORImage(      
     HANDLE hResourceContext,
    char* sARMPRG_FileName,
    char* sMBNFileName,
    unsigned char bSkipGoToDownload,
    unsigned char bDownloadReset,
    unsigned long iSleepTimeToDOWNLOADmode,
    unsigned long iSleepTimeToGOcommand,
    unsigned long* iErrorCode
    );


   /******************************************************************************/
   /**
   Upload software image with CDT information from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files

   The function will return once RESET command is issued after download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path
   \param sRawProgramFileName = RawProgram xml file path, usually "rawprogram_unsparse.xml"
   \param sPatchFileName = Patch xml file path, usually "patch0.xml"
   \param sEmmcUserPartitionImage = User Partition image file
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   
   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                            
   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                           
   \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   \warning Note, sDSP1, sMBR, sADSP files are not supported yet

   \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
   can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcUserParitionImageWithCDT(      
     HANDLE hResourceContext,
    char* sARMPRG_FileName,
    char* sRawProgramFileName,
    char* sPatchFileName,
    char* sEmmcUserPartitionImage,
    unsigned char bUseTrustedMode,
    unsigned long iSleepTimeToDOWNLOADmode,
    unsigned long iSleepTimeToGOcommand,
    unsigned long* iErrorCode
    );


   /******************************************************************************/
   /**
   Upload software image for Secure Boot 1.0 targets from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Secure Boot 1.0 target includes MSM7x01, MSM7x25, MSM7x27

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files

   The function will return once RESET command is issued after download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path
   \param sPartitionFileName = Partition File Path, usually "partition.mbn"
   \param sPriBootLoader_FileName= Primary Boot Loader File Path, usually, "pbl.mbn"
   \param sQCSecBootLoader_FileName= Qualcomm Secondary Boot Loader, usually "qcsbl.mbn"
   \param sQCSecBootLoaderHeader_FileName= Qualcomm Secondary Boot Loader Header, usually qcsblhd_cfgdata.mbn"
   \param sOEMSecBootLoader_FileName= OEM Secondary Boot Loader, usually "oemsbl.mbn"
   \param sOEMSecBootLoaderHeader_FileName= OEM Secondary Boot Loader Header, usually "oemsblhd.mbn"
   \param sModemFile_FileName= AMSS modem file, usually amss.mbn"
   \param sModemFileHeader_FileName= AMSS modem file header, usually "amsshd.mbn"
   \param sAppsFile_FileName=  AMSS application file, usually "apps.mbn"
   \param sAppsFileHeader_FileName= AMSS application file header, "appshd.mbn";
   \param sAppsBootLoaderFile_FileName= AMSS application boot loader file, usually "appsboot.mbn";
   \param sAppsBootLoaderFileHeader_FileName= AMSS application boot loader header file, usually "appsboothd.mbn";
   \param sWinMobile_FileName= Winmobile file, usually "flash.bin"
   \param sDSP1_FileName= DSP1 file, usually "dsp1.mbn"
   \param sMBR_FileName= MBR file, usually "mbr.mbn"
   \param sADSP_FileName= ADSP file, usually "adsp.mbn"
   \param sCefsModem_FileName = CEFS MODEM file, usually "cefs_modem.mbn"
   \param bOverridePrtnTable = TRUE(1)  to overwrite the stored partition table in the phone
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE

   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             MSM7x25 = 5000;
                             MSM7x25 = 5000;

   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                           MSM7x25 = 5000;
                           MSM7x25 = 5000;

   \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   \warning Note, sDSP1, sMBR, sADSP files are not supported yet

   *******************************************************************************/




   QLIB_API unsigned char QLIB_QPHONEMS_UploadSB1MultiImage
   (   HANDLE hResourceContext,
       char* sARMPRG_FileName,
       char* sPartitionFileName,
       char* sPriBootLoader_FileName,
       char* sQCSecBootLoader_FileName,
       char* sQCSecBootLoaderHeader_FileName,
       char* sOEMSecBootLoader_FileName,
       char* sOEMSecBootLoaderHeader_FileName,
       char* sModemFile_FileName,
       char* sModemFileHeader_FileName,
       char* sAppsFile_FileName,
       char* sAppsFileHeader_FileName,
       char* sAppsBootLoaderFile_FileName,
       char* sAppsBootLoaderFileHeader_FileName,
       char* sWinMobile_FileName,
       char* sDSP1_FileName,
       char* sMBR_FileName,
       char* sADSP_FileName,
       char* sCefsModem_FileName,
       unsigned char bOverridePrtnTable,
       unsigned char bUseTrustedMode,
       unsigned char bSkipGoToDownload,
       unsigned long iSleepTimeToDOWNLOADmode,
       unsigned long iSleepTimeToGOcommand,
       unsigned long *iErrorCode
   );

   QLIB_API unsigned char QLIB_QPHONEMS_SetupStrmDlRetries
   (   
      HANDLE hResourceContext, 
      unsigned long iSleepTimeToRetryHello,
      unsigned long iMaxTriesToHello,
      unsigned long iSleepTimeToRetryNop,
      unsigned long iMaxTriesToNop
   );
   /******************************************************************************/
   /**
   This method is design to work with the fastboot command.
   In Multi unit download enviornment, a fastboot command need to be directed towards specific
   device. This method sets a command that identifies the device as a unqiue

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param serialNumber = serialnumber is the token that is going to get set for fastboot to be used.

   /warning: token can not exceed more than 16 characters.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_SetFactoryToken(HANDLE hResourceContext, char *serialNumber);


   

   /******************************************************************************/
   /**
   Upload software image for Secure Boot 3.0 targets from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Secure Boot 3.0 targets includes 9x15

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files using the user partition method. 

   The function will return once RESET command is issued after MBN download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path name. For example, "NPRG9x15.hex"(regular ARMPRG) or "ENPRG9x15.hex" (emergency downloader)
   \param sPartitionFileName = partition path and file name, usually "partition.mbn"
   \param pPartitonList = contains a pointer to a structure providing information about the .mbn files that are going to be programmed into the device. 
                     At the moment, limit is set to 10 files on the partition name / parition files. Please use the SWDL_UserPartitionList structre. 
                     sPartitionName will contain the partition name. Note: Use the "0:SBL1" as the first partition name. the partition string must be null terminated!
                     sPartitionMBNPath will contain the mbn file path. 
         struct
         {
             char sPartitionName[129];                      // PartitionName For example, 0:SBL1     
             char sPartitionMBNPath[256];                // Path to the mbn files
         }SWDL_UserPartitionEntry;

         struct
         {
             SWDL_UserPartitionEntry oPartitionList[10];
             int  iNumOfPartitionEntry;
         }SWDL_UserPartitionList;

   \param bOverridePrtnTable = TRUE(1)  to overwrite the stored partition table in the phone
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE

   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             MDM9k = 5000;
                             SCMM (MDM6k, QSC6x95) = 5000;
                             LCU (QSC6240/70) = 5000


   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                             MDM9k = 3000;
                             SCMM (MDM6k, QSC6x95) = 3000;
                             LCU (QSC6240/70) = 5000

    \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h   

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DownloadUserPartitions
   (
      HANDLE hResourceContext,
      char* sARMPRG_FileName,
      char* sPartitionFileName,
      void* pPartitonList,
      unsigned char bOverridePrtnTable,
      unsigned char bUseTrustedMode,
      unsigned char bSkipGoToDownload,      
      unsigned long iSleepTimeToDOWNLOADmode,
      unsigned long iSleepTimeToGOcommand,
      unsigned long *iErrorCode
   );

   /******************************************************************************/
   /**
   Upload software image for Secure Boot 2.0 targets from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Secure Boot 2.0 target includes QSC6240/6270, QSC6x95, QSD8x50, MDM9k

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files

   The function will return once RESET command is issued after MBN download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path name. For example, "NPRG6695.hex"(regular ARMPRG) or "ENPRG6695.hex" (emergency downloader)
   \param sPartitionFileName = partition path and file name, usually "partition.mbn"
   \param sDeviceBootLoader_FileName = Device Boot Loader Name, usually "dbl.mbn"
   \param sQFailSafeBootLoader_FileName = Fail safe boot loader name, usually "fsbl.mbn"
   \param sOSBootLoader_FileName = OS boot loader name, usually "osbl.mbn"
   \param sModem_FileName = AMSS File, usually "amss.mbn"
   \param sApps_FileName = AMSS boot loader, usually "apps.mbn"
   \param sAppsBootLoader_FileName = AMSS boot loader, usually "appsboot.mbn"
   \param sWinbMobile_FileName = Win Image Name, usually "flash.bin"
   \param sDSP1_FileName = DSP1 file name, usually "dsp1.mbn"
   \param sDSP2_FileName = DSP2 file name, usually "dsp2.mbn"
   \param sMBR_FileName = MBR file name, usually "mbr.bin"
   \param sADSP_FileName = MBR file name, usually "adsp_q5.mbn"
   \param sTrustZone = Trust Zone name, usually "tzos.mbn"
   \param sROFS1 = ROFS1 file, usually "file.rofs1"
   \param sROFS2 = ROFS2 file, usually "file.rofs2"
   \param sROFS3 = ROFS3 file, usually "file.rofs3"
   \param sCefsModem_FileName = CEFS MODEM file, usually "cefs_modem.mbn"
   \param bOverridePrtnTable = TRUE(1)  to overwrite the stored partition table in the phone
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE

   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             MDM9k = 5000;
                             SCMM (MDM6k, QSC6x95) = 5000;
                             LCU (QSC6240/70) = 5000


   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                             MDM9k = 3000;
                             SCMM (MDM6k, QSC6x95) = 3000;
                             LCU (QSC6240/70) = 5000

    \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   \warning sMBR_FileName, sADSP_FileName, sTrustZone, sORFS1, sORFS2 and sORFS3 partition files are not yet supported.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_UploadSB2MultiImage
   (
      HANDLE hResourceContext,
      char* sARMPRG_FileName,
      char* sPartitionFileName,
      char* sDeviceBootLoader_FileName,
      char* sQFailSafeBOotLoader_FileName,
      char* sOSBootLoader_FileName,
      char* sModem_FileName,
      char* sApps_FileName,
      char* sAppsBootLoader_FileName,
      char* sWinMobile_FileName,
      char* sDSP1FileName,
      char* sDSP2FileName,
      char* sMBR_FileName,
      char* sADSP_FileName,
      char* sTrustZone,
      char* sROFS1,
      char* sROFS2,
      char* sROFS3,
      char* sCefsModem_FileName,
      unsigned char bOverridePrtnTable,
      unsigned char bUseTrustedMode,
      unsigned char bSkipGoToDownload,
      unsigned long iSleepTimeToDOWNLOADmode,
      unsigned long iSleepTimeToGOcommand,
      unsigned long *iErrorCode
   );
   /******************************************************************************/
   /**

   Callback function for QMSL client to collect status during software download

   Note: This method will not work with QPST. It requires Qlib connection.

   *******************************************************************************/
   QLIB_API void QLIB_QPHONEMS_UploadSBMultiImage_ConfigureCallBack( HANDLE hResourceContext, swdlQPHONEMSCB pSWDLCallBack);

   /******************************************************************************/
   /**
   Switch to download mode.

   Note: This method will not work with QPST. It requires Qlib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_SwitchToDownloadMode(HANDLE hResourceContext, unsigned long iSleepTimeToDownloadMode, unsigned long *iErrorCode);

   /******************************************************************************/
   /**
   Switch to download mode, but does not send the NOP command to ensure that
   Device infact has switched over. The reason for that is that sometimes in download mode
   device changes its port.
   This method simply switches the device into download mode allowing user to make a decision on how to proceed next.

   Note: This method will not work with QPST. It requires Qlib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_SwitchToDownloadMode_OptionalValidation(HANDLE hResourceContext, unsigned long iSleepTimeToDownloadMode, unsigned char checkForNOP, unsigned long *iErrorCode);

   /******************************************************************************/
   /**
   This function reboots the phone based on the DMSS Download Protocol

   Ref Doc (80-39912-1)
   Note: This method will not work with QPST. It requires a QLib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DLoad_Reset(HANDLE hResourceContext, int timeoutSeconds);

   /******************************************************************************/
   /**
   This function gets the version of the phone based on the DMSS Download Protocol

   Ref Doc (80-39912-1)
   Note: This method will not work with QPST. It requires a QLib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DLoadVersionReq(HANDLE hResourceContext, int timeoutSeconds);

   /******************************************************************************/
   /**
   This function is used to erase the specified sectors from the unit in the DMSS Download Protocol
   
   Note: This method will not work with QPST. It requires a QLib connection.  Only applicable to QRD target as of Nov 2012.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DLoad_EraseEMMC(HANDLE hResourceContext, int timeoutSeconds, int Sector, int NoOfSectors);

   /******************************************************************************/
   /**
   Send NOP command to ensure that device is in fact in download mode.

   Note: This method will not work with QPST. It requires Qlib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DLoad_SendNop(HANDLE hResourceContext, int timeout);

   /******************************************************************************/
   /**
   Uploads the EMMC user partition image file.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Only supporting 7627A at the moment.



   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download EMMC user partition image file

   The function will return once RESET command is issued after MBN download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path name. For example, "NPRG6695.hex"(regular ARMPRG) or "ENPRG6695.hex" (emergency downloader)
   \param sEmmcUserPartitionImage = EMMC user partition image file

   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE

   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             MDM9k = 5000;
                             SCMM (MDM6k, QSC6x95) = 5000;
                             LCU (QSC6240/70) = 5000


   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                             MDM9k = 3000;
                             SCMM (MDM6k, QSC6x95) = 3000;
                             LCU (QSC6240/70) = 5000

    \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcUserParitionImage
   (
      HANDLE hResourceContext,
      char* sARMPRG_FileName,
      char* sEmmcUserPartitionImage,
      unsigned char bUseTrustedMode,
      unsigned char bSkipGoToDownload,
      unsigned long iSleepTimeToDOWNLOADmode,
      unsigned long iSleepTimeToGOcommand,
      unsigned long *iErrorCode
   );

   /******************************************************************************/
   /**
    Uploads the Flash programmer image file using Sahara Protocol from the host to the device.
   
   Ref Sahara Protocol Doc (80-N1008-1)
   
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_QPHONEMS_ConnectServer_Sahara method.
   \param sARMPRG_FileName = ARMPRG file path name. For example for 9x25 MTP, "NPRG9x25.mbn"(regular ARMPRG) or "ENPRG9x25.mbn" (emergency downloader)

     *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_Sahara_FlashProgrammer
   (
      HANDLE hResourceContext,
      char* sARMPRG_FileName
   );

  /******************************************************************************/
  /**
   Receive the Hello packet after Dload command (will be used for upgrade mechanism), and provide the version number.
   Respond the hello packet as ImageTransfer mode.
 
   Ref Sahara Protocol Doc (80-N1008-1)
   
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_QPHONEMS_ConnectServer method.
   
   \param version = Sahara Protocol version supported and currently used by the device

   \param timeout = Indicates the timeout value for the host to wait for the device to send a Sahara hello packet
   
  *******************************************************************************/

  QLIB_API unsigned char QLIB_QPHONEMS_Sahara_SetImageTransferMode(HANDLE hResourceContext, unsigned long* version, unsigned long timeout);

  /******************************************************************************/
   /**
      Callback function for the Sahara protocol methods for logging purposes.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param pSWDL_QPHONEMS_CB, callback function to display debug messages for Sahara Protocol methods.

     *******************************************************************************/

  QLIB_API void QLIB_QPHONEMS_SaharaConfigureCallback(HANDLE hResourceContext, swdlQPHONEMSCB pSWDL_QPHONEMS_CB);

   /******************************************************************************/
   /**
      Read NV and PRL values from mobile.  The method reads all the NV and PRL from the mobile and does not
   require a NV Definition XML file. The method resembles QPST NV backup operation EXCEPT EFS ITEMS.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sQCN_Path - Path of the QCN file. The file, if exists, will be overwritten.

      \param iResultCode, the result code, See QMSL_Backup_ResultCode_Enum

      \return true if result code is 0

   \warning 7/1/2012: This method does not backup NV item stored as EFS item file or regular file. It has only been proved to backup NV items
   frin 7x27 target

   The method will be updated to backup EFS NV item in future QMSL release.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_BackupNVFromMobileToQCN(HANDLE hResourceContext, char *sQCN_Path, int* iResultCode);

   /******************************************************************************/
   /**
      This method will send the NOP Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/

    QLIB_API unsigned char QLIB_QPHONEMS_FireHoseNOP(HANDLE hResourceContext);

   /******************************************************************************/
   /**
      This method will send the Configure Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param MaxPayloadSizeToTargetInBytes The amount data sent by the host to the device in one shot, must be a multiply of sector size.

   \param memory_name Example: for MSM8974 to memory_name = "eMMC"

   \param target_name Example: for MSM8974 to target_name = "8974"

   \param AckPacketNumber The parameters represents the value of the number of packets after which the host wants the target to Acknowledge reciept of the packets

   \param bSpecifyMaxPayloadSizeToTargetInBytes If the value is false, a negotiated maximum size is used, otherwise the specified MaxPayloadSizeToTargetInBytes is used,

   \param bUseSkipWriteAttr Cause the target to skip writing the data to disk. This allows you to benchmark the performance of USB

   \param bUseAlwaysValidateAttr Causes validation to occur on every packet. This is used to see the impact of validation (hashing) without 
                           needing to enable secure boot.

   \param bUseVerboseAttr Causes the target to send many more logs to the host

   \param bUseAckRawDataEveryNumPackets Causes validation of to occur after every AckPacketNumber(param).

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FireHoseConfigure(  HANDLE hResourceContext,
                                              char* MaxPayloadSizeToTargetInBytes,
                                              char* memory_name,
                                              char* target_name,
                                             char* AckPacketNumber,
                                             unsigned char bSpecifyMaxPayloadSizeToTargetInBytes,
                                             unsigned char bUseSkipWriteAttr,
                                             unsigned char bUseAlwaysValidateAttr,
                                             unsigned char bUseVerboseAttr,
                                             unsigned char bUseAckRawDataEveryNumPackets
                                          );

      /******************************************************************************/
   /**
      This method will send the getsha256digest Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param physical_partition_number Partition number

   \param start_sector Start sector number

   \param sector_size_in_byte Sector size in bytes

   \param num_partition_sectors Total partition number

   \param digest Return digest, must contains at least 65 bytes

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FireHoseGetDigest(   HANDLE hResourceContext,
                                             int physical_partition_number,
                                             int start_sector,
                                             int sector_size_in_byte,
                                             int num_partition_sectors,
                                             char digest[65]);

   /******************************************************************************/
   /**
      This method will calcualte the sha256 hash of a file.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFilePath full path of file to hash

   \param nSectorSizeInByte Sector Size In Bytes

   \param i64Offset offset from begining, a ninus value is ignored and changed to 0, the value must be a multiply of nSectorSizeInByte

   \param i64Length hash data lentgh, the value must be a multiply of nSectorSizeInByte, if the value is 0, it will hash the size of whole, compromising ceiling to a multiply of nSectorSizeInByte

   \param pdigest Return digest, must contains at least 65 bytes

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/
   
   QLIB_API unsigned char QLIB_QPHONEMS_HashFileSHA256(HANDLE hResourceContext, char *sFilePath, int nSectorSizeInByte, __int64 i64Offset, __int64 i64Length, char pdigest[65]);

   /******************************************************************************/
   /**
      This method will calcualte the sha256 hash of a string.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFilePath full path of file to hash

   \param nSectorSizeInByte Sector Size In Bytes

   \param i64Offset offset from begining, a ninus value is ignored and changed to 0, the value must be a multiply of nSectorSizeInByte

   \param i64Length hash data lentgh, the value must be a multiply of nSectorSizeInByte, if the value is 0, it will hash the size of whole, compromising ceiling to a multiply of nSectorSizeInByte

   \param pdigest Return digest, must contains at least 65 bytes

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/
   
   QLIB_API unsigned char QLIB_QPHONEMS_HashStringSHA256(HANDLE hResourceContext, unsigned char *sString, unsigned int nStringLength, char pdigest[65]);

   /******************************************************************************/
   /**
      This method digest list for compare. Must be used together with QLIB_QPHONEMS_EnableReadDataValidation_FireHose for option Always External read back sha256 to PC for check

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param pDigestList A pointer to SWDL_UserPartitionHashList, contains sha256 digest for each download file

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/
   
   QLIB_API unsigned char QLIB_QPHONEMS_FireHoseSetBuildValidationDigest(HANDLE hResourceContext, void *pDigestList);
   
   /******************************************************************************/
   /**
      This method will send the PROGRAM Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param rawprogram The name of the rawprogram file which contains all the image files for which the Program commands are generated.

   \param imageSizeInMB returns the actural downloading size in MB

   \param throughput returns the throughput in MB/s

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FireHoseProgram( HANDLE hResourceContext,
                                            char* rawprogram, float* imageSizeInMB, float* throughput);

   /******************************************************************************/
   /**
      This method will send the PROGRAM Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param patchfile The name of the patchfile file which contains Patch information.

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FireHosePatch( HANDLE hResourceContext,
                                          char* patchfile);

   /******************************************************************************/
   /**
      This method will send the PROGRAM Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param Action this allows the host to either reset or switch off the device in FireHose mode.

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FireHosePower(HANDLE hResourceContext,
                                          char* Action);

   /******************************************************************************/
   /**
      This method will send the PROGRAM Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param Action this allows the host to either reset or switch off the device in FireHose mode.

   \param DelayInSeconds  will postpone the reset or off by several seconds.

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FireHosePower_WithDelay(HANDLE hResourceContext,
                                          char* Action,
                                          unsigned int DelayInSeconds);

   /******************************************************************************/
   /**
      This method will send the PROGRAM Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param DriveNumber denotes the bootable drive .

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FireHoseSetBootableStorageDrive(   HANDLE hResourceContext,
                                                         char* DriveNumber);

   /******************************************************************************/
   /**
      This method will get the storage information when the device is in FireHose mode.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param DriveNumber input, denotes the drive number of the information

   \param info output the information for specified the storage.

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FireHoseGetStorageInfo( HANDLE hResourceContext, char* DriveNumber, char* info);

   /******************************************************************************/
   /**
      This method will send the Erase Command to device when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param DriveNumber denotes the drive which needs to be erased, this erase feature is only available on the USER partition, 
    which is physical partition number 0.

      \return true if result code is 0

     \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_FireHoseErase( HANDLE hResourceContext, char* DriveNumber, unsigned int timeout);

   /******************************************************************************/
   /**
      This method is used for setup customized parameter

      \param skipFiles   the fienames separated by comma, which will be skipped when downloading

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
     *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FirehoseSetConfig_CommaDelimitedSkipFiles(HANDLE hResourceContext, char *skipFiles);

   /******************************************************************************/
   /**
      Callback function for the FireHose protocol methods for logging purposes.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param pSWDL_QPHONEMS_CB, callback function to display debug messages for Sahara Protocol methods.


    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
     *******************************************************************************/

   QLIB_API void QLIB_QPHONEMS_FireHoseConfigureCallback(HANDLE hResourceContext, swdlQPHONEMSCB pSWDL_QPHONEMS_CB);

   /******************************************************************************/
   /**
      This method will download all the images and apply patches for a single RawProgram/Patch xml file (non CDT devices), when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param rawprogram The name of the rawprogram file which contains all the image files for which the Program commands are generated.

   \param patchfile The name of the patchfile file which contains Patch information.

   \param imageSizeInMB returns the actural downloading size in MB

   \param throughput returns the throughput in MB/s

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcImage_FireHose(HANDLE hResourceContext, char* rawprogramfile, char* patchfile,  float* imageSizeInMB, float* throughput);

   /******************************************************************************/
   /**
      This method will download all the images and apply patches for a multiple RawProgram/Patch xml file (CDT devices), when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pPartitionList   Point to SWDL_eMMC_UserPartitionList, this strusture holds a list of the Rawprogram and Patch files which contains the details about the images to download and Patches to apply.

   \param imageSizeInMB returns the actural downloading size in MB

   \param throughput returns the throughput in MB/s

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcImages_FireHose(HANDLE hResourceContext, void* pPartitionList,  float* imageSizeInMB, float* throughput);
   
   /******************************************************************************/
   /**
      This method will download all the images a RawProgram, finding files from search file path list, when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param rawprogramFile   Holds the Rawprogram file which contains the details about the images to download.
   
   \param pMetaBuildContent   Point to SWDL_eMMC_MetaBuild_Content Holds all the full path of the image file in search list

   \param imageSizeInMB   returns the actural downloading size in MB

   \param throughput      returns the throughput in MB/s

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcMetaBuildImage_FireHose(HANDLE hResourceContext, void* pMetaBuildContent, float* imageSizeInMB, float* throughput);

   /******************************************************************************/
   /**
      Enable VIP process and configure vip command, set the digest file list path

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param MaxDigestTableSize   max digest file size for configure command.

   \param SignedDigestTable   Signed digest table full path

   \param ChainedDigestTable   Chained digest table full path

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
   *******************************************************************************/
   
   QLIB_API unsigned char QLIB_QPHONEMS_EnableVIP_FireHose(HANDLE hResourceContext,
                                             unsigned int MaxDigestTableSize,
                                             char *SignedDigestTable,
                                             char *ChainedDigestTable);

   /******************************************************************************/
   /**
      Enable dry run process to create digest table

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param MaxDigestTableSize   max digest file size for to break down command.

   \param DigestTableToSign   Full path for digest table to sign

   \param ChainedDigestTable   Chained digest table full path

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
   *******************************************************************************/
   
   QLIB_API unsigned char QLIB_QPHONEMS_EnableDryRun_FireHose(   HANDLE hResourceContext,
                                                unsigned int MaxDigestTableSize,
                                                char *DigestTableToSign,
                                                char *ChainedDigestTable);

   /******************************************************************************/
   /**
      Break Down raw binary digest table into signed digest table and chained digest table, you need to call QLIB_QPHONEMS_EnableDryRun_FireHose in advance

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param ChainedDigestTable   Binary Digest Table

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
 
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_BreakDownRawDigestTable_FireHose(HANDLE hResourceContext, char *BinaryDigestTable);

   /******************************************************************************/
   /**
      This method is used to enable\disable the skip storage init for ufs provision, Must be called before configuration.
   Default is false

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param enable,   0 -- not enabled, 1 enabled
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_EnableSkipStorageInit_FireHose(HANDLE hResourceContext, unsigned char enable);

   /******************************************************************************/
   /**
      This method is used to enable\disable the read validation after programing which is a exactly verfication of programing data. Must be called before programing.
   Default is false

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param mode,   0 -- No read back
   \            1 -- Always enable external read back all data to PC for check 
   \            2 -- Always enable internal read back check in mobile
   \            3 -- Always enable external read back sha256 to PC for check
   \            4 -- Always enable external read back all data to PC and then hash sha256 for check 
   \            5 -- Follow rawprogram setting to enable internal read back check in mobile
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_EnableReadDataValidation_FireHose(HANDLE hResourceContext, unsigned char mode);

   /******************************************************************************/
   /**
      This method is used to enable\disable the binary data log before\after programe\read. Must be called before programing. Default is false

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param enabled, true for enable and false for disable.
 
   \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_EnableDataLogToFile_FireHose(HANDLE hResourceContext, unsigned char enabled);

   /******************************************************************************/
   /**
      This method is used to Set the delay in milliseconds after writing the data to the device in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param timeinMilliSeconds, represents the time in milliseconds of delay we wish to set.

   \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_SetSendDataDelay_FireHose(HANDLE hResourceContext, int timeinMilliSeconds);

   /******************************************************************************/
   /**
   Connect to FireHose download server without a active phone.

   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   \param pSWDL_QPHONEMS_CB, callback function to display debug messages for Sahara Protocol methods.

   \return HANDLE to use for all subsequent QLIB calls that require a handle.
           If NULL, then no valid phone was found.

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API HANDLE QLIB_QPHONEMS_ConnectServerSimple_FireHose(swdlQPHONEMSCB pSWDL_QPHONEMS_CB);

    /******************************************************************************/
   /**
   Connect a device that is running FireHose download protocol to the server at a certain COM port number.

   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   \param iComPort = COM port number to use for communication with phone.
                  This does not open the COM port at the operating system
                  level until a call is made to the embedded target.


   \param pSWDL_QPHONEMS_CB, callback function to display debug messages for Sahara Protocol methods.

   \return HANDLE to use for all subsequent QLIB calls that require a handle.
           If NULL, then no valid phone was found.

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/

   QLIB_API HANDLE QLIB_QPHONEMS_ConnectServer_FireHose( unsigned int iComPort, swdlQPHONEMSCB pSWDL_QPHONEMS_CB);

   /******************************************************************************/
   /**
   Disconnect the server and close the COM port associated with the FireHose server.

   \param hResourceContext = Resource context that was returned from the call to QLIB_QPHONEMS_ConnectServer_FireHose()

   \return void

   \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010
   *******************************************************************************/

   QLIB_API void QLIB_DisconnectServer_FireHose( HANDLE hResourceContext );

   /*****************************************************************************/
   /**

   This method breaksdown the windows FFU file into image files and also stores the programming information of each of the broken down 
   files into a rawprogram xml file.

   \param hResourceContext = Resource context

   \param pSWDL_QPHONEMS_CB = callback function to display log messages from the method.

   \param ffuFilename = file name of the ffu file that is to be broken down.

   \param ImagePath = points to the Directory location where the image files post break down are to be saved.

   \return true is the result code is 0.

   \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_FFUToRawProgram(HANDLE hResourceContext, swdlQPHONEMSCB pSWDL_QPHONEMS_CB, char* ffuFilename, char* ImagePath);

   /*****************************************************************************/
   /**

   This method is used to switch a device from Diagnostic mode to the Emergency Download mode.

   This comand sent is "75 101 01 00" and is supported from the 8x26 devices onwards.

   \param hResourceContext = ResourceContext

   \return true if the result code is 0

   \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_SwitchToEDL(HANDLE nResourceContext);

   /*****************************************************************************/
   /**
   This method will download all the images and apply patches for a single RawProgram xml file when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param commandXmlFile The xml contains commands to be execute.

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_ExecuteCommandXML_FireHose(HANDLE hResourceContext, char* commandXmlFile);

   /*****************************************************************************/
   /**
   This method will download all the images and apply patches for a single RawProgram xml file when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param rawprogramfile The name of the rawprogram file which contains all the image files for which the Program commands are generated.

   \param imageSizeInMB returns the actural downloading size in MB

   \param throughput returns the throughput in MB/s

   \param read_rawprogram_toptobottom, read_rawprogram_topbottom is set to true for Windows 8 phones, by default this value is false.
                              For Windows Phone 8 the rawprogram xml is parsed and programmed from top to bottom, the order matters since we are not going to applying patch.

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcImage_FireHose_NoPatch(HANDLE hResourceContext, char* rawprogramfile,  float* imageSizeInMB, float* throughput, unsigned char read_rawprogram_toptobottom);

   /*****************************************************************************/
   /**
   This method will download a single images file when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param physicalPartitionNumber eMMC physical partition number

   \param startSector Start sector number of the logical partition

   \param numPartitionSectors sector number for this logical partition

   \param sectorSizeInBytes sector size in bytes

   \param imagefile The name of the image file.

   \param imageSizeInMB returns the actural downloading size in MB

   \param throughput returns the throughput in MB/s

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcSingleImage_FireHose(HANDLE hResourceContext, 
      unsigned int physicalPartitionNumber, char *startSector, unsigned int numPartitionSectors, unsigned int sectorSizeInBytes,
      char* imagefile, float* imageSizeInMB, float* throughput);

   /*****************************************************************************/
   /**
   This method will read a data block to a single images file when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param physicalPartitionNumber eMMC physical partition number

   \param startSector Start sector number of the logical partition

   \param numPartitionSectors sector number for this logical partition

   \param sectorSizeInBytes sector size in bytes

   \param imagefile The name of the image file.

   \param imageSizeInMB returns the actural downloading size in MB

   \param throughput returns the throughput in MB/s

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_ReadEmmcDataBlock_FireHose(HANDLE hResourceContext, 
      unsigned int physicalPartitionNumber, char *startSector, unsigned int numPartitionSectors, unsigned int sectorSizeInBytes,
      char* imagefile, float *imageSizeInMB, float *throughput);

   /*****************************************************************************/
   /**
   This method will apply patches for a single Patch xml file, when the device is in FireHose mode.

   Ref Firehose Protocol Doc (80-NG319-1_A)

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param patchfile The name of the rawprogram file which contains all the image files for which the Program commands are generated.

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_PatchEmmcImage_FireHose(HANDLE hResourceContext, char* patchfile);

   /*****************************************************************************/
   /**
   This method will load digest file and generate the digest table.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param digestFile The digest file records the SHA256 values of image files

   \param digestTable The digest teble parsed from digest file

      \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_LoadBuildValidationDigestFile(HANDLE hResourceContext, char *digestFile, void *digestTable);

   /******************************************************************************/
   /**
   Connect a device that is running sahara download protocol to the server at a certain COM port number.
   This method will start the thread immediately, so we do not miss the SAHARA HELLO packet sent by the device.

   Ref Sahara Protocol Doc (80-N1008-1)

   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   \param iComPort = COM port number to use for communication with phone.
                  This does not open the COM port at the operating system
                  level until a call is made to the embedded target.

   \param version = Sahara Protocol version supported and currently used by the device.

   \param serno = MSM serial number which will be got from device, it only works when bGetInfo is non-zero

   \param msmid = MSM ID which will be got from device, it only works when bGetInfo is non-zero

   \param pkhash = MSM Private Key Hash which will be got from device, it only works when bGetInfo is non-zero

   \param pSWDL_QPHONEMS_CB, callback function to display debug messages for Sahara Protocol methods.

   \param mode = Sahara hello Packet mode, when mode = 0, this indicates a SAHARA_MODE_IMAGE_TX_PENDING mode
                                 when mode = 2, this indicates a SAHARA_MODE_MEMORY_DEBUG mode

   \param timeout, indicates the timeout between reads

   \param bGetInfo = Whether get the MSMID or not

   \return HANDLE to use for all subsequent QLIB calls that require a handle.
           If NULL, then no valid phone was found.

   \return true if result code is 0

    \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API HANDLE QLIB_QPHONEMS_ConnectServer_Sahara( unsigned int iComPort, unsigned long *version, unsigned long *serno, unsigned long *msmid, char *pkhash, unsigned char bGetInfo, int mode, unsigned long timeout, swdlQPHONEMSCB pSWDL_QPHONEMS_CB);

   /******************************************************************************/
   /**
   Disconnect the server and close the COM port associated with the FireHose server.

   \param hResourceContext = Resource context that was returned from the call to QLIB_QPHONEMS_ConnectServer_FireHose()

   \return void

   \Note: This API only works with QMSL Static and Dynamic Libraries compiled under Visual Studio 2010.  It is because the underlying data structure
      can only be found the Windows SDK shipped VS2010

   *******************************************************************************/
   QLIB_API void QLIB_DisconnectServer_Sahara( HANDLE hResourceContext );

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   
