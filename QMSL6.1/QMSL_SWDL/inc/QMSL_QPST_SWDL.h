/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_SWDL/inc/QMSL_QPST_SWDL.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_QPST_SWDL
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_QPST_SWDL_H)
#define _QMSL_QPST_SWDL_H

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
                     Software Download
   *******************************************************************************/

   /******************************************************************************/
   /**
   Download boot loader image taken from hex file from PC to MP and next should restart
   MP (but this funtionality is not done good in MP).
   QLIB_UploadBootLoaderOnlyHexFile

   Note: This function requires the use of QPST.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadBootLoaderOnlyHexFile(
      HANDLE hResourceContext,
      char* sFileName, char* sSPC,
      unsigned char bUseCustomArmProg,
      unsigned char bUploadArmProg
   );

   /******************************************************************************/
   /**
   Upload a Boot file from the PC to the phone.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFileName = the local path and filename of the hex boot file to upload.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadBootFileBeforeHexFile
   (
      HANDLE hResourceContext,
      char* sFileName
   );

   /******************************************************************************/
   /**
   Upload a CEFS file from the PC to the phone.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFileName = the local path and filename of the CEFS file to upload.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadCEFS_File
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sPartitionFileName
   );

   /******************************************************************************/
   /**
   Upload a CEFS file from the PC to the phone, specifying the ARMPROG file, for
   use when the phone is already in download mode.
   This is equivalent to QPST SW Download CEFS tab, "Restore Modem CEFS", function

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFileName = the local path and filename of the CEFS file to upload.
   \param iDloadArmprg = if bUseCustomArmprg = false, then ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType

   \code
   From QPST code, SharedInc/ArmprgType.h:

   typedef enum      // Default armprg to use when mobile alread in download mode.
   {
                    // apStandard must be first.
   apStandard,          // MSM3000, 3100, 3300, 5000, 5010, 5100, 5105

   apMSM6000,    // MSM6000
   apMSM6050,    // MSM6050
   apMSM6200_1,  // MSM6200 Cheetah
   apMSM6100,    // MSM6100 Cougar with NOR flash
   apMSM6100NAND,// MSM6100 Cougar with NAND flash.
   apMSM6250,      // MSM6250 (Saber) NOR flash
   apMSM6250NAND,  // MSM6250 (Saber) NAND flash
   apMSM6500,      // MSM6500 (Jaguar) NOR flash
   apMSM6500NAND,  // MSM6500 (Jaguar) NAND flash
   apMSM6100NORFFA, // MSM6100 FFA with NOR flash
   apMSM6550,       // MSM6550 (Eagle) NOR flash
   apMSM6550NAND,   // MSM6550 NAND (3/9/05)
   apMSM6550PB,     // MSM6550 progressive boot
   apEM6700,        // MSM6700 emulator (Quasar)
   apMSM6275NOR,    // MSM6275 (Raven) NOR
   apMSM6275NAND,   // MSM6275 (Raven) NAND
   apMSM6800NOR,    // MSM6800 (DoRA) NOR
   apMSM6800NAND,   // MSM6800 (DoRA) NAND
   apMSM6250Sec,    // MSM6250 secure (one-time programmable)
   apMSM7500NAND,   // MSM7500 (Phoenix)
   apMSMSC1x,       // SC1x a.k.a. QSC, NOR progressive
   apMSM6280NAND,   // MSM6280 NAND multi-image
   apMSM7200NAND,   // MSM7200 NAND multi-image
   apMSM7500NOR,    // MSM7500 NOR multi-image
   apMSM6260NAND,   // MSM6260 NAND
   apMSM6245NAND,   // MSM6245 NAND multi-image, progressive
   apMSM6255aNAND,  // MSM6255A NAND, progressive
   apMSM6800NAND65nm,  // 65nm MSM6800
   apMSMSC2x,       // SC2x a.k.a. QSC60x5
   apMSM7200a,      // MSM7200a
   apMSM7600,       // MSM7600
   apMSMSC2xNOR,     // SC2x using aprg60x5.hex (NOR)
   apMSMSC2xNAND,    // SC2X using nprg60x5.hex (NAND),
   apMSM6260NOR,     // MSM6260 NOR
   apMSM7500a,       // MSM7500a, NAND
   apMDM1000,        // MSM7200a/7500a NOR
   apMSM6235NOR,     // MSM6235 NOR
   apMSM6235NAND,    // MSM6235 NAND
   apMSM7225NAND,    // MSM7225 NAND
   apMSM6246NAND,    // MSM6246 NAND

                    // 11/16/07 added for consistency:
   apMSM6245NOR,     // APRG6245.HEX
   apMSM6246NOR,     // APRG6246.HEX
   apMSM6255aNOR,    // APRG6255A.HEX
   apMSM6800bNOR,    // APRG6800B.HEX
   apMSM7200NOR,     // APRG7200.HEX
   apMSM7200aNOR,    // APRG7200A.HEX
   apMSM7225NOR,     // APRG7225.HEX
   apMSM7500aNOR,    // APRG7500A.HEX
   apMSM7600NOR,     // APRG7600.HEX

   apMSM7800NAND,    // NPRG7800.HEX
   apMSMQSC6270x40NAND,  // QSC6270/40

   apQsd8250NANDV1,  // NPRG8250.HEX
   apQsd8650NANDV1,  // NPRG8650.HEX
   apQsc1100NOR,     // APRG1100.HEX
   apQsc1110NOR,     // APRG1110.HEX
   apQsd8250NANDV2,  // NPRG8250.HEX
   apQsd8650NANDV2,  // NPRG8650.HEX

   apQst1105NAND,    // NPRG1105A.HEX

   apMSM7625NAND,
   apQsc7630NAND,

   apMDM8200NAND,

   apQst1105NOR,
   apQsc6295NAND,

   apMsm1500NAND,
   apMsm1500NOR,
   apMsm1600NAND,
   apMsm1600NOR,
   apMsm1700NAND,
   apMsm1700NOR,

   apMsm7525NAND,
   apMsm7627NAND,

   apMarkerForDialog // apMarkerForDialog must be last.

   } dloadArmprgType ;
   \endcode

   Note: This function requires the use of QPST.

   \return true if successful, false if fail.

   \warning This function is grouped with the EFS functions, not the download functions,
            so it is important to check for errors in the EFS area, not Software download.

          This might be a little confusing because the other CEFS functions are grouped
          under software download.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadCEFS_File2
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sPartitionFileName,
      long iDloadArmprg
   );


   /******************************************************************************/
   /**
   Upload a CEFS file from the PC to the phone alternate filesystem, specifying the ARMPROG file, for
   use when the phone is already in download mode.

   This is equivalent to QPST SW Download CEFS tab, "Restore Applications CEFS", function

   Note: This function requires the use of QPST.

   \param sFileName = the path and filename of the CEFS file to upload.
   \param sPartitionFileName = the path and filename of the partition file to upload.
   \param iDloadArmprg = ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadCEFS_ImageAlternate
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sPartitionFileName,
      long iDloadArmprg
   );


   /******************************************************************************/
   /**
   Backup a CEFS file from the mobile modem file system to PC

   This is equivalent to QPST SW Download CEFS tab, "Backup Legacy CEFS", function

   Note: This function requires the use of QPST.

   \param sFileName = the PC path and filename of the CEFS file to be stored.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_BackupCEFS_Legacy
   (
      HANDLE hResourceContext,
      char* sFileName
   );


   /******************************************************************************/
   /**
   Backup a CEFS file from the mobile alternate file system to PC

   This is equivalent to QPST SW Download CEFS tab, "Backup Alternate CEFS", function

   Note: This function requires the use of QPST.

   \param sFileName = the PC path and filename of the CEFS file to be stored.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_BackupCEFS_Alternate
   (
      HANDLE hResourceContext,
      char* sFileName
   );


   /******************************************************************************/
   /**
   Restore a raw CEFS file from PC to the mobile alternate file

   This is equivalent to QPST SW Download CEFS tab, "Write raw (spare+data) Apps EFS image", function

   Note: This function requires the use of QPST.

   \param sFileName = the path and filename of the CEFS file to upload..

   \param sPartitionFileName = the path and filename of the partition file to upload.

   \param iDloadArmprg =  ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType


   \return true if successful, false if fail.

   \warning

   ******************************************************************************/
   QLIB_API unsigned char QLIB_StartRestoreRawAppsEfsImage
   (
      HANDLE hResourceContext,
      char* sFileName,
      char* sPartitionFileName,
      long iDloadArmprg
   );

   /******************************************************************************/
   /**
   Restore a factory file from PC to the mobile mobile

   This is equivalent to QPST SW Download Factory Image tab

   Note: This function requires the use of QPST.

   \param sFileName = the path and filename of the CEFS file to upload.

   \param useCustomArmprg = true to always use "ARMPRG.HEX"

                        false, the ARM PROG file will be determined by querying the phone
                        model and selecting the correct APRGxxxx.HEX file.

   \param iDloadArmprg = if bUseCustomArmprg = false, then ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType


   \return true if successful, false if fail.

   \warning

   ******************************************************************************/

   QLIB_API unsigned char QLIB_StartFactoryImageDownload
   (
      HANDLE hResourceContext,
      char* sFileName,
      unsigned char bUseCustomArmPrg,
      long iDloadArmprg
   );

   /******************************************************************************/
   /**
   Upload a multi-image software image from the PC to the phone.  This function
   performs an "OBL" download, which is equivalent to the QPST Software Download application.

   For the following string inputs DON'T PASS NULL's, use "".  To control which files
   will be sent, use the paraemter, iDownloadBitMask.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sPartitionFileName = partition path and file name, usually "partition.mbn"
   \param sOTBPL_FileName = OTBPL path and file name, usually "obl.mbn"
   \param sPBL_FileName = Primary Boot Loader, usually "pbl.mbn"
   \param sQCSBL_FileName = secure boot loader, usually "qcsblhd_cfgdata.mbn"
   \param sQCSBL_HeaderName = secure boot loader header, usually "qcsbl.mbn"
   \param sOEMSBL_FileName = OEM secure boot loader, usually "oemsbl.mbn"
   \param sOEMSBL_HeaderName = OEM secure boot loader header, usually "oemsblhd.mbn"
   \param sModemFileName = AMSS File, usually "amss.mbn"
   \param sModemHeaderName = AMSS Header, usually "amsshd.mbn"
   \param sAppsFileName = Application file
   \param sAppsHeaderName = Application header file
   \param char bOverridePrtnTable = TRUE to overwrite the stored partition table in the phone
   \param char bUseTrustedMode = TRUE to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.

   \param sSPC = Service Programming Code, usually "000000"
   \param bClearErrorLog = TRUE to clear the QPST error log
   \param sStorageFile = file name of temporary QCN file
   \param bOverrideModelCheck = TRUE to override a model number check
   \param bSkipReset = TRUEto skip the reset operation after the phone is programmed
   \param bUseCustomArmprg =  FALSE to let QPST server determine which ARMPRG to bet used.
                             If TRUE, then the NPRG or ARMPRG will be searched for in the
                       same folder as the modem file name.
   \param iDloadArmprg = if bUseCustomArmprg = false, then ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType
   \param iDownloadBitMask = bitmask of files to download, based on SWD_miFileTypeBitmask_enum

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadMultiImage
   (
      HANDLE hResourceContext,
      char* sPartitionFileName,
      char* sOTBPL_FileName,
      char* sPBL_FileName,
      char* sQCSBL_FileName,
      char* sQCSBL_HeaderName,
      char* sOEMSBL_FileName,
      char* sOEMSBL_HeaderName,
      char* sModemFileName,
      char* sModemHeaderName,
      char* sAppsFileName,
      char* sAppsHeaderName,
      char* sAppsBlFileName,
      char* sAppsBlHeaderFileName,
      unsigned char bOverridePrtnTable,
      unsigned char bUseTrustedMode,
      char* sSPC,
      unsigned char bClearErrorLog,
      char* sStorageFile,
      unsigned char bOverrideModelCheck,
      unsigned char bSkipReset,
      unsigned char bUseCustomArmprg,
      long iDloadArmprg,
      long iDownloadBitMask
   );

   /******************************************************************************/
   /**
   Upload a multi-image software image from the PC to the phone.  This function
   is equivalent to the "Multi-image" tab in the QPST Software Download application.

   For the following string inputs DON'T PASS NULL's, use "".  To control which files
   will be sent, use the paraemter, iDownloadBitMask.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sPartitionFileName = partition path and file name, usually "partition.mbn"
   \param sPBL_FileName = Primary Boot Loader, usually "pbl.mbn"
   \param sQCSBL_FileName = secure boot loader, usually "qcsblhd_cfgdata.mbn"
   \param sQCSBL_HeaderName = secure boot loader header, usually "qcsbl.mbn"
   \param sOEMSBL_FileName = OEM secure boot loader, usually "oemsbl.mbn"
   \param sOEMSBL_HeaderName = OEM secure boot loader header, usually "oemsblhd.mbn"
   \param sModemFileName = AMSS File, usually "amss.mbn"
   \param sModemHeaderName = AMSS Header, usually "amsshd.mbn"
   \param sAppsFileName = Application file
   \param sAppsHeaderName = Application header file
   \param sAppsBlFileName = Application boot loader file
   \param sAppsBlHeaderFileName = Application boot loader header file
   \param char bOverridePrtnTable = TRUE to overwrite the stored partition table in the phone
   \param char bUseTrustedMode = TRUE to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.

   \param sSPC = Service Programming Code, usually "000000"
   \param bClearErrorLog = TRUE to clear the QPST error log
   \param sStorageFile = file name of temporary QCN file
   \param bOverrideModelCheck = TRUE to override a model number check
   \param bSkipReset = TRUEto skip the reset operation after the phone is programmed
   \param bUseCustomArmprg =  FALSE to let QPST server determine which ARMPRG to bet used.
                             If TRUE, then the NPRG or ARMPRG will be searched for in the
                       same folder as the modem file name.
   \param iDloadArmprg = if bUseCustomArmprg = false, then ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType
   \param iDownloadBitMask = bitmask of files to download, based on SWD_miFileTypeBitmask_enum

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadMultiImage2
   (
      HANDLE hResourceContext,
      char* sPartitionFileName,
      char* sPBL_FileName,
      char* sQCSBL_FileName,
      char* sQCSBL_HeaderName,
      char* sOEMSBL_FileName,
      char* sOEMSBL_HeaderName,
      char* sModemFileName,
      char* sModemHeaderName,
      char* sAppsFileName,
      char* sAppsHeaderName,
      char* sAppsBlFileName,
      char* sAppsBlHeaderFileName,
      unsigned char bOverridePrtnTable,
      unsigned char bUseTrustedMode,
      char* sSPC,
      unsigned char bClearErrorLog,
      char* sStorageFile,
      unsigned char bOverrideModelCheck,
      unsigned char bSkipReset,
      unsigned char bUseCustomArmprg,
      long iDloadArmprg,
      long iDownloadBitMask
   );

   /******************************************************************************/
   /**
   Upload a multi-image software image from the PC to the phone.  This function
   is equivalent to the "Multi-image" tab in the QPST Software Download application,
   and the main difference from version 2 is that it supports a Windows Mobile image

   For the following string inputs DON'T PASS NULL's, use "".  To control which files
   will be sent, use the paraemter, iDownloadBitMask.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sPartitionFileName = partition path and file name, usually "partition.mbn"
   \param sPBL_FileName = Primary Boot Loader, usually "pbl.mbn"
   \param sQCSBL_FileName = secure boot loader, usually "qcsblhd_cfgdata.mbn"
   \param sQCSBL_HeaderName = secure boot loader header, usually "qcsbl.mbn"
   \param sOEMSBL_FileName = OEM secure boot loader, usually "oemsbl.mbn"
   \param sOEMSBL_HeaderName = OEM secure boot loader header, usually "oemsblhd.mbn"
   \param sModemFileName = AMSS File, usually "amss.mbn"
   \param sModemHeaderName = AMSS Header, usually "amsshd.mbn"
   \param sAppsFileName = Application file
   \param sAppsHeaderName = Application header file
   \param sAppsBlFileName = Application boot loader file
   \param sAppsBlHeaderFileName = Application boot loader header file
   \param sWinMobileImageFileName = Windows Mobile Image file
   \param char bOverridePrtnTable = TRUE to overwrite the stored partition table in the phone
   \param char bUseTrustedMode = TRUE to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.

   \param sSPC = Service Programming Code, usually "000000"
   \param bClearErrorLog = TRUE to clear the QPST error log
   \param sStorageFile = file name of temporary QCN file
   \param bOverrideModelCheck = TRUE to override a model number check
   \param bSkipReset = TRUEto skip the reset operation after the phone is programmed
   \param bUseCustomArmprg =  FALSE to let QPST server determine which ARMPRG to bet used.
                             If TRUE, then the NPRG or ARMPRG will be searched for in the
                       same folder as the modem file name.
   \param iDloadArmprg = if bUseCustomArmprg = false, then ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType
   \param iDownloadBitMask = bitmask of files to download, based on SWD_miFileTypeBitmask_enum

   \return true if successful, false if fail.

   \warning !!! This function has not been tested yet.  It will be tested for the QDART 3.2.20
            release on December 14, 2007 !!!

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadMultiImage3
   (
      HANDLE hResourceContext,
      char* sPartitionFileName,
      char* sPBL_FileName,
      char* sQCSBL_FileName,
      char* sQCSBL_HeaderName,
      char* sOEMSBL_FileName,
      char* sOEMSBL_HeaderName,
      char* sModemFileName,
      char* sModemHeaderName,
      char* sAppsFileName,
      char* sAppsHeaderName,
      char* sAppsBlFileName,
      char* sAppsBlHeaderFileName,
      char* sWinMobileImageFileName,
      unsigned char bOverridePrtnTable,
      unsigned char bUseTrustedMode,
      char* sSPC,
      unsigned char bClearErrorLog,
      char* sStorageFile,
      unsigned char bOverrideModelCheck,
      unsigned char bSkipReset,
      unsigned char bUseCustomArmprg,
      long iDloadArmprg,
      long iDownloadBitMask
   );

   /******************************************************************************/
   /**
   Upload a multi-image software image (Multimage Download 1.0) from the PC to the phone.  This function supports using
   emegerncy download.  The function requires QPST 2.7.335 or beyond for runtime.

   The following statement is taken from QPST 2.7.335 release note section.  QPST release note can be found
   in "c:\program files\QPST\bin\readme.txt

   "Added "Use Emerg. Host D/L" feature to Software Download. This feature will only work with chipsets
    that support emergency host download, and allows you to download new images to a mobile device that
    has an empty or corrupted flash device. If you enable this feature Software Download will
    attempt to use a special flash programmer (eNPRGxxxx.hex) that is chipset-dependant"

   For the following string inputs DON'T PASS NULL's, use "".  To control which files
   will be sent, use the paraemter, iDownloadBitMask.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sPartitionFileName = partition path and file name, usually "partition.mbn"
   \param sPBL_FileName = Primary Boot Loader, usually "pbl.mbn"
   \param sQCSBL_FileName = secure boot loader, usually "qcsblhd_cfgdata.mbn"
   \param sQCSBL_HeaderName = secure boot loader header, usually "qcsbl.mbn"
   \param sOEMSBL_FileName = OEM secure boot loader, usually "oemsbl.mbn"
   \param sOEMSBL_HeaderName = OEM secure boot loader header, usually "oemsblhd.mbn"
   \param sModemFileName = AMSS File, usually "amss.mbn"
   \param sModemHeaderName = AMSS Header, usually "amsshd.mbn"
   \param sAppsFileName = Application file
   \param sAppsHeaderName = Application header file
   \param sAppsBlFileName = Application boot loader file
   \param sAppsBlHeaderFileName = Application boot loader header file
   \param sWinMobileImageFileName = Windows Mobile Image file
   \param sDSP1FileName = DSP1 file name
   \param sDSP2FileName = DSP2 file name
   \param bUseEmergDL = 1 to use emergency download, 0 to use normal download
   \param sMBRFileName = SBR file name
   \param char bOverridePrtnTable = TRUE to overwrite the stored partition table in the phone
   \param char bUseTrustedMode = TRUE to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.

   \param sSPC = Service Programming Code, usually "000000"
   \param bClearErrorLog = TRUE to clear the QPST error log
   \param sStorageFile = file name of temporary QCN file
   \param bOverrideModelCheck = TRUE to override a model number check
   \param bSkipReset = TRUEto skip the reset operation after the phone is programmed
   \param bUseCustomArmprg =  FALSE to let QPST server determine which ARMPRG to bet used.
                             If TRUE, then the NPRG or ARMPRG will be searched for in the
                       same folder as the modem file name.
   \param iDloadArmprg = if bUseCustomArmprg = false, then ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType
   \param iDownloadBitMask = bitmask of files to download, based on SWD_miFileTypeBitmask_enum

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadMultiImage5
   (
      HANDLE hResourceContext,
      char* sPartitionFileName,
      char* sPBL_FileName,
      char* sQCSBL_FileName,
      char* sQCSBL_HeaderName,
      char* sOEMSBL_FileName,
      char* sOEMSBL_HeaderName,
      char* sModemFileName,
      char* sModemHeaderName,
      char* sAppsFileName,
      char* sAppsHeaderName,
      char* sAppsBlFileName,
      char* sAppsBlHeaderFileName,
      char* sWinMobileImageFileName,
      char* sDSP1FileName,
      char* sDSP2FileName,
      unsigned char  bUseEmergDL,
      char* sMBRFileName,
      unsigned char bOverridePrtnTable,
      unsigned char bUseTrustedMode,
      char* sSPC,
      unsigned char bClearErrorLog,
      char* sStorageFile,
      unsigned char bOverrideModelCheck,
      unsigned char bSkipReset,
      unsigned char bUseCustomArmprg,
      long iDloadArmprg,
      long iDownloadBitMask
   );

   /******************************************************************************/
   /**
   Upload a multi-image software image (Secure Boot 2.0) from the PC to the phone.
   The function requires QPST 2.7.365 or beyond for runtime.

   For the following string inputs DON'T PASS NULL's, use "".  To control which files
   will be sent, use the paraemter, iDownloadBitMask.

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
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


   \param bUseEmergDL = 1 to use emergency download, 0 to use normal download
   \param char bOverridePrtnTable = TRUE to overwrite the stored partition table in the phone
   \param char bUseTrustedMode = TRUE to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.

   \param sSPC = Service Programming Code, usually "000000"
   \param bClearErrorLog = TRUE to clear the QPST error log
   \param sStorageFile = file name of temporary QCN file, ""
   \param bOverrideModelCheck = TRUE to override a model number check
   \param bSkipReset = TRUE to skip the reset operation after the phone is programmed.  This is ignored by QPST
   \param bUseCustomArmprg =  FALSE to let QPST server determine which ARMPRG to bet used.
                             If TRUE, then the NPRG or ARMPRG will be searched for in the
                       same folder as the modem file name.
   \param iDloadArmprg = if bUseCustomArmprg = false, then ID of the ARMPRG to use
                          refer to the enumeration, dloadArmprgType in QLib_SoftwareDownload

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_UploadSB2MultiImage
   (
      HANDLE hResourceContext,
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
      unsigned char  bUseEmergDL,
      unsigned char bOverridePrtnTable,
      unsigned char bUseTrustedMode,
      char* sSPC,
      unsigned char bClearErrorLog,
      char* sStorageFile,
      unsigned char bOverrideModelCheck,
      unsigned char bSkipReset,
      unsigned char bUseCustomArmprg,
      long iDloadArmprg
   );

   /******************************************************************************/
   /**
   Aborts the most recent software download operation (SW Download, QCN file transfer).

   Note: This function requires the use of QPST.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return none

   \warning Any current operations will be terminated.  This can cause problems with the
            phone state.  If a FLASH programming is interrupted, the phone may become
          unusable and require JTAG.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_AbortSW_DownloadOperation( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Note: This function requires the use of QPST.

   Return the phone status, as reported by QPST Server.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatus = value of the current status, as defined by the SWD_enPhoneMode enumeration
                     in SoftwareDownload.h

      typedef enum SWD_enPhoneMode
      {   SWD_modeNone            = 0,
         SWD_modeDataServices      = SWD_modeNone + 1,
         SWD_modeDownload         = SWD_modeDataServices + 1,
         SWD_modeDiagnostic         = SWD_modeDownload + 1,
         SWD_modeDiagnosticOffline   = SWD_modeDiagnostic + 1,
         SWD_modeReset            = SWD_modeDiagnosticOffline + 1,
         SWD_modeStreamDownload      = SWD_modeReset + 1,
         SWD_modeMspDownload         = SWD_modeStreamDownload + 1,
         SWD_modeMspDiagnostic      = SWD_modeMspDownload + 1,
         SWD_modeMspDiagnosticOffline= SWD_modeMspDiagnostic + 1,
         SWD_modeMspReset         = SWD_modeMspDiagnosticOffline + 1,
         SWD_modeMspStreamDownload   = SWD_modeMspReset + 1
      };

      This enumeration list is defined by QPST software with regard to the phone state

   \return true if successful, false if fail.

   \warning---this function is only valid when the library is in QPST mode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GetQpstPhoneStatus( HANDLE hResourceContext, unsigned long* piStatus );

   /******************************************************************************/
   /**

      Get the error status and description of the last software download operation.

      Note: This function requires the use of QPST.

      \param bErrorOccurred    = true if an error occurred during the last operation.  False if no error
                           occurred during the last operation.

      \param sErrorMessage     = Filled filled in with a text description of the most recent error.
                           Empty if no error has occurred.

      \param iMaxStringLength  = Maximum nQumber of characters available in the sErrorMessage buffer

      \return true if successful, false if failure

      \warning  The error information will be cleared after this is called.

   *******************************************************************************/
   QLIB_API void QLIB_GetLastSoftwareDownloadErrorInfo
   ( HANDLE hResourceContext, unsigned char* bErrorOccurred, char *sErrorMessage, int iMaxStringLength );

 
   /******************************************************************************/
   /**

   Download a CEFS file from the phone to the PC

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sLocalFile = absolute path of file to create on PC

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DownloadCEFS_File( HANDLE hResourceContext, char* sLocalFile );

  /******************************************************************************/
   /**

   Get the QPST Sahara Hello Behavior

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSaharaHelloRspBehavior = see SaharaHelloRspBehavior in QLib_SoftwareDownloadDefines.h

   \return true if successful, false if fail.

   \warning This function requires QPST version 2.7.4xx
   *******************************************************************************/
   QLIB_API unsigned char QLIB_GetSaharaHelloBehavior( HANDLE hResourceContext, unsigned short *iSaharaHelloRspBehavior );
  /******************************************************************************/
   /**

   Set the QPST Sahara Hello Behavior

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSaharaHelloRspBehavior = see SaharaHelloRspBehavior in QLib_SoftwareDownloadDefines.h

   \return true if successful, false if fail.

   \warning This function requires QPST version 2.7.4xx
   *******************************************************************************/
   QLIB_API unsigned char QLIB_SetSaharaHelloBehavior( HANDLE hResourceContext, unsigned short iSaharaHelloRspBehavior );
   #ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_QPST_SWDL_H)
