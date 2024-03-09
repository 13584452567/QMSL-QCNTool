/******************************************************************************
 * $Header$
 * $DateTime$
 *
 * DESCRIPTION: Definitions required for software download
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#ifndef _QLIB_SOFTWARE_DOWNLOAD_DEFINES_H
#define _QLIB_SOFTWARE_DOWNLOAD_DEFINES_H


#include "QLIB_Defines.h"


/***************************************************************************************************************/
/**                  Definitions for generic Software Download events                                                  */
/***************************************************************************************************************/

// Will be delcared later...
union union_generalSwDownloadEvent;

//! Callback for a General SW Download Event
typedef unsigned char( *swd_generalEvent )
(
   unsigned char* pGeneralEvent   //   recievers of this call back must cast to: union_generalSwDownloadEvent
);

/**
   enumeration of SW download event types
*/
typedef enum
{
   SWD_downloadEvent,         //   uses struct downloadEvent_struct;
   SWD_nvBackupEvent,         //   uses struct nvBackupEvent_struct;
   SWD_doAutoRestore,         //  No data
   SWD_reportLoaderStatus,      //   uses struct bootDownloadStatus_struct;
   SWD_bootDownloadStart,      //   uses struct bootDownloadStart_struct;
   SWD_bootReportLoaderStatus,   //   uses struct bootReportLoaderStatus_struct;
   SWD_bootDownloadStatus,      //  uses struct bootDownloadStatus_struct;
   SWD_bootDownloadProgress,   //   uses struct bootDownloadProgress_struct;
   SWD_bootDownloadComplete,   //  No data
   SWD_MIReportLoaderStatus,   //   uses struct MIReportLoaderStatus_struct;
   SWD_MIReportFlashStatus,   //   uses struct MIReportFlashStatus_struct;
   SWD_MIStartDownload,      //   uses struct MIStartDownload_struct;
   SWD_MIDownloadProgress,      //   uses struct MIDownloadProgress_struct;
   SWD_MIDownloadComplete,      //   No data
   SWD_MIDownloadStatus,      //   uses struct MIDownloadStatus_struct;
   SWD_Event_None            //  No event specified
} SwDownload_EventTypes;

/**
   enumeration of QPST Server Event Types
*/
typedef enum
{   
   QPST_serverEventServerStarting = 0,
   QPST_serverEventServerRunning,
   QPST_serverEventServerStopping,   
   QPST_serverEventUpdatePhoneStatus,   
   QPST_serverEventUpdatePortStatus,
   QPST_serverEventUpdateListActiveObjects,   
   QPST_serverEventUpdateListPortConfigs,   
   QPST_serverEventPhoneEvent,   
   QPST_serverEventCount,   
   QPST_serverEventPhoneLockStatus,   
   QPST_serverEventPhoneAuthStatus,   
   QPST_serverEventUpdateMspStatus,   
   QPST_serverEventApsUseOnly,   
   QPST_serverEventUpdateIpServer,   
   QPST_serverEventUpdatePhonePortStatus,
   QPST_serverEventFileSystemChange,   
   QPST_serverEventSaharaDwnldStart,   
   QPST_serverEventSaharaDwnldFileSent,
   QPST_serverEventSaharaDwnldDone,   
   QPST_serverEventSaharaDumpStart,   
   QPST_serverEventSaharaDumpSectDone,
   QPST_serverEventSaharaDumpDone,   
} QPST_Server_Event_Types;

/**
   enumeration of Sahara Hello Response Behavior
*/
typedef enum
{
  HelloRspDefault,                // Send a hello response with mode copied from hello.
  HelloRspDumpNotDownload,        // If hello = download request, request a dump instead.
  HelloRspDownloadNotDump,        // If hello = dump request, request download instead.
  HelloRspWait                    // Don't send a Hello response until one of the previous 3 modes is selected.
} SaharaHelloRspBehavior;


#define SWD_StringMaxSize 100

/*
   The following is a set of structures and a union which will handle all software download
   events.  This eliminates the need for separate event classes and call back functions.

   In other words, there will be one single event handler call back and it will process
   a union of events
*/

//! Callback for a download event
typedef struct
{
   unsigned long status;
   unsigned short error;
   unsigned short percentCompleted;
   unsigned short block;
   unsigned long address;
   char dataString[SWD_StringMaxSize ];
} downloadEvent_struct;

//! Callback for a NV Backup Event
typedef struct
{
   unsigned long status;
   unsigned short error;
   unsigned short percentCompleted;
   unsigned short nvItem;
   char dataString[SWD_StringMaxSize ];
} nvBackupEvent_struct;


typedef struct
{
   char flashName[SWD_StringMaxSize ];
   unsigned long loaderSize;
} bootDownloadStart_struct;

typedef struct
{
   unsigned long statusCode;
   unsigned long detailCode;
} bootDownloadStatus_struct;

typedef struct
{
   char bsLoaderName[SWD_StringMaxSize ];
   long  customLoader;
   long  localFile;
} reportLoaderStatus_struct;


typedef struct
{
   char bsLoaderName[SWD_StringMaxSize ];
   long  customLoader;
   long  localFile;
} bootReportLoaderStatus_struct;

typedef struct
{
   unsigned long bytesWritten;
} bootDownloadProgress_struct;

// No need for sepearate structure
//       virtual void bootDownloadComplete() ;


// IAtlasDownloadEvents3
typedef struct
{
   char bsLoaderName[SWD_StringMaxSize ];
   long customLoader;
   long localFile;
} MIReportLoaderStatus_struct;

typedef struct
{
   char flashName[SWD_StringMaxSize ];
} MIReportFlashStatus_struct;

typedef struct
{
   unsigned long imageSize;
   unsigned long imageType;
} MIStartDownload_struct;

typedef struct
{
   unsigned long bytesWritten;
} MIDownloadProgress_struct;


typedef struct
{
   unsigned long statusCode;
   unsigned long detailCode;
} MIDownloadStatus_struct;


/**
   Union of all possible download events
*/
typedef union
{
   downloadEvent_struct         downloadEvent;
   nvBackupEvent_struct         nvBackupEvent;
   reportLoaderStatus_struct      reportLoaderStatus;
   bootDownloadStart_struct      bootDownloadStart;
   bootDownloadStatus_struct      bootDownloadStatus;
   bootReportLoaderStatus_struct   bootReportLoaderStatus;
   bootDownloadProgress_struct      bootDownloadProgress;
   MIReportLoaderStatus_struct      MIReportLoaderStatus;
   MIReportFlashStatus_struct      MIReportFlashStatus;
   MIStartDownload_struct         MIStartDownload;
   MIDownloadProgress_struct      MIDownloadProgress;
   MIDownloadStatus_struct         MIDownloadStatus;
} generalSwDownloadEvent_union;

/**
   Union of all download events + CONTEXT ID + Event type
*/
typedef struct
{
   SwDownload_EventTypes eEventType;         //!<' Type of event
   HANDLE hContextID;                     //!<' Event type
   generalSwDownloadEvent_union uEventData;   //!<' Event Data
} generalSwDownloadEvent_struct;


/**
   Enumeration of file types to be used selected for download
   by uploadMultiImage()

   taken from QPST's sharedinc/MultiImageDownload.h
*/
typedef enum        // File type bitmasks
{
   miType_None        = 0,
   miTypePrtnFile     = 0x0001,
   miTypePblFile      = 0x0002,
   miTypeQcSblFile    = 0x0004,
   miTypeQcSblHdFile  = 0x0008,
   miTypeOemSblFile   = 0x0010,
   miTypeOemSblHdFile = 0x0020,
   miTypeAmssFile     = 0x0040,
   miTypeAmssHdFile   = 0x0080,
   miTypeAppsFile     = 0x0100,
   miTypeAppsHdFile   = 0x0200,
   miTypeOblFile      = 0x0400,
   miTypeAppsBlFile   = 0x0800,
   miTypeAppsBlHdFile = 0x1000,
   miType_All         = 0x1FFF,
   miTypeWinMobile    = 0x2000,
   miTypeDsp1         = 0x4000,
   miTypeDsp2         = 0x8000,
   miType_AllExApps   = 0x04FF
} SWD_miFileTypeBitmask_enum;



/*
   Enumeration of Arm prog types, taken from QPST's sharedinc/ArmprgType.h
   This following enum is taken from QPST 2.7.371
*/
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
   apQsc7630NAND,    // DON'T USE - use 7x30

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

   apQsc6695NAND,

   apQsc6195NAND,
   apQsc7230NAND,    // DON'T USE - use 7x30
   apQsc7830NAND,    // DON't USE - use 7x30
   apQsc6695NAND_2,  // different flash prg name than apQsc6695NAND

   apMdm9kNAND,

   apMdm6600NAND,

   apMsm7x30NAND,

   apMsm7x30eMMC,

   apMdm6615NAND,

   apMsm7225ANAND,
   apMsm7625ANAND,
   apMsm7227ANAND,
   apMsm7627ANAND,

   apMarkerForDialog // apMarkerForDialog must be last.
} dloadArmprgType ;

/**
   Note for support.  Download status and error numbers are found in the QPST software,
   under sharedinc/downloadres.h

   These definitions do not have further documentation, so it is necessary to look
   closely at the name of the item and see it used in the log context in order
   to know how it works.

   Here is the "status" and "error" list as of QPST 2.7.341:
*/
#define IDS_PHONEIMAGEOPENERR 102
#define IDS_DOWNLOADABORTEDSTATUS 103

#define IDS_IMAGEDESCRAMBLINGSTATUS 106
#define IDS_HEX32IMAGEDECODINGSTATUS 107
#define IDS_HEX32FLASHPRGDECODINGSTATUS 108
#define IDS_HEX32ARMPRGDECODINGSTATUS 109
#define IDS_FLASHPRGOPENERR 110
#define IDS_ARMPRGOPENERR 111
#define IDS_PHONEDISCONNECTEDERR 112
#define IDS_DOWNLOADSUCCESSSTATUS 113
#define IDS_JUMPINGTODOWNLOADMODESTATUS 114
#define IDS_JUMPTODOWNLOADMODEERR 115
#define IDS_JUMPINGTODOWNLOADMODESUCCESSSTATUS 116
#define IDS_WRITINGBLOCKSTATUS 117
#define IDS_ERASINGBLOCKSTATUS 118
#define IDS_WRITINGBOOTBLOCKSTATUS 119
#define IDS_ERASINGBOOTBLOCKSTATUS 120
#define IDS_SENDINGFLASHPRGSTATUS       121
#define IDS_PINGINGFLASHPRGSTATUS 122
#define IDS_BADFCSRSN 123
#define IDS_INVALIDADDRRSN 124
#define IDS_INVALIDLENRSN 125
#define IDS_ENDOFPKTRSN 126
#define IDS_TOOLONGRSN 127
#define IDS_UNKNOWNCMDRSN 128
#define IDS_OPFAILRSN 129
#define IDS_IDMISMATCHRSN 130
#define IDS_PROGVOLTRSN 131
#define IDS_VERIFYRDBACKRSN 132
#define IDS_NEEDUNLOCKRSN 133
#define IDS_BADPASSWORDRSN 134

#define IDS_RESETINGPHONESTATUS 137
#define IDS_FLASHPRGCOMMUNICATIONERR 138
#define IDS_PARAMREQUESTERR 139
#define IDS_DOWNLOADCOMMUNICATIONERR 140
#define IDS_RESETFAILEDERR 141
#define IDS_TRYINGTOCOMMUNICATESTATUS 142
#define IDS_DIAGCOMMUNICATIONERR 143
#define IDS_ZEROINGMODELNUMBERSTATUS 144

#define IDS_RESTORESUCCESSSTATUS 148
#define IDS_RESTOREFAILSTATUS 149
#define IDS_MODEOFFLINESTATUS 150
#define IDS_MODEOFFLINEERR 151

#define IDS_RESTORINGNVSTATUS 153
#define IDS_SENDINGSPCSTATUS 154
#define IDS_BACKUPSUCCESSSTATUS 155
#define IDS_BACKUPFAILSTATUS 156
#define IDS_MODEONLINESTATUS 157
#define IDS_MODEONLINEERR 158

#define IDS_MODELNUMBERQUERYERR 166
#define IDS_BACKINGUPNVSTATUS 167
#define IDS_DISKIOERR 168
#define IDS_BADRESPONSEERR 169

#define IDS_INVALIDHEXFILEERR 176
#define IDS_UNKNOWNIMAGESCRAMBLERERR 177
#define IDS_UNEXPECTEDEXCEPTIONERR 178
#define IDS_UNKNOWNDEVICEERR 179
#define IDS_MODELNUMBERERASEERR 180
#define IDS_FLASHPRGSTARTERR 181
#define IDS_PARAMREQUESTSTATUS 182
#define IDS_ROAMINGLISTREADERR 183
#define IDS_MODEDETECTIONERR 184
#define IDS_MODEDIAGERR 185
#define IDS_SPCUNLOCKERR 186

#define IDS_SENDINGROAMINGLISTSTATUS 188
#define IDS_FEATUREMASKQUERYERR 189
#define IDS_FAMILYNUMBERMISMATCHERR 190
#define IDS_MODELNUMBERMISMATCHERR 191
#define IDS_STARTINGERASESTATUS 192

#define IDS_PARAMRESPONSESTATUS 209

#define IDS_ROAMINGLISTLOADERR 211
#define IDS_FEATUREMASKSTATUS 212
#define IDS_ESNMISMATCHWITHCALDATAERR 213
#define IDS_FAILEDFILECHECKERR 214
#define IDS_STARTINGFLASHPRGSTATUS 215
#define IDS_ROAMINGLISTSAVEERR 216
#define IDS_MODELNOTSUPPORTEDERR 217
#define IDS_PHONELOCKERR 218
#define IDS_TIMEOUTRSN 219

#define IDS_ERRORLOGCLEARERR 221
#define IDS_VERIFYINGPHONEIMAGESTATUS 222
#define IDS_VERIFYINGPHONEIMAGEERR 223

#define IDS_INVALIDFLASHPRGERR 230

#define IDS_HEXFILETOOBIGERR 232
#define IDS_SKIPPINGROAMINGLISTERR 233

#define IDS_HARDWAREINCOMPATIBLEERR 236
#define IDS_EFSPARSERERR 237
#define IDS_PHONEIMAGELOWMEMERR 238
#define IDS_LOADEFSFILEERR 239
#define IDS_PHONEIMAGETOOBIGERR 240
#define IDS_FAMILYNUMBERREADERR 241
#define IDS_FLASHDEVICENAMESTATUS       242
#define IDS_EFSPROCESSCMDERR 243

#define IDS_LOADEFSSTATUS 245
#define IDS_SELFEXTRACTIONERR 246
#define IDS_QCNFILEMODELMISMATCH 247
#define IDS_EFSREMOTELINKSTATUS 248
#define IDS_WRITEEFSSTATUS 249
#define IDS_EXTRACTINGBUNDLESTATUS 250
#define IDS_DELETINGEFSSTATUS 251
#define IDS_DELETINGEFSFILESERR 252
#define IDS_ENUMEFSERR 253
#define IDS_DELETINGEFSDIRERR 254
#define IDS_REMOTELINKERR 255
#define IDS_EFSFILELOADERR 256
#define IDS_CREATEEFSDIRERR 257
#define IDS_INTERNALERR 258
#define IDS_FILEOPENERR 259
#define IDS_LOADEFSREMOTEERR 260

#define IDS_DEVINTEL28F400              500
#define IDS_DEVAMDAM29F400              501
#define IDS_DEVINTEL28F800              502
#define IDS_DEVAMDAM29LV400T            503
#define IDS_DEVAMDAM29LV800T            504
#define IDS_DEVSHARPLH28F400            505
#define IDS_DEVHITACHIHN29WT800T        506
#define IDS_DEVTITMS28F800SZT           507
#define IDS_DEVAMDAM29DL800T            508
#define IDS_DEVINTEL28F800B3            509
#define IDS_DEVINTEL28F160B3            510
#define IDS_DEVSHARPLH28F800            511
#define IDS_DEVMITSUBISHI29GT161        512
#define IDS_DEVAMDAM29DL163             513
#define IDS_DEVFUJITSU29DL162           514
#define IDS_DEVATMEL49BV8192AT          515
#define IDS_DEVATMEL49BV1604T           516

#define IDS_LOADQCNEFSSTATUS 600
#define IDS_DIALINGPLANLOADERR 601
#define IDS_TEMPDIRCREATEERR 602
#define IDS_ZEROFILELENGTHERR 603
#define IDS_COUNTFILECREATEERR 604
#define IDS_BACKINGUPCERT 605
#define IDS_RESTORECERT 606
#define IDS_ARMPRGOPENFAILED 607
#define IDS_ARMPRGCLOSEFAILED 608
#define IDS_NANDPRGONLY 609
#define IDS_BOOTONNANDONLY 610
#define IDS_NOTSTRMDOWNLOAD 611
#define IDS_WINCEIMAGEDECODINGSTATUS 612
#define IDS_BACKINGUPPDP 613
#define IDS_RESTOREPDP 614
#define IDS_PDPVERNOMATCH 615
#define IDS_PBNIMAGEDECODINGSTATUS 616
#define IDS_SENDINGSECMODE 617
#define IDS_INVSECMODE 618
#define IDS_INVSECSUPPORT 619
#define IDS_PRTNTBLDECODINGSTATUS 620
#define IDS_PRTNTBLOPENERR 621
#define IDS_SENDINGPRTNTBL 622
#define IDS_PRTNUSEOVERIDE 623
#define IDS_PRTNTBLBAD 624
#define IDS_PRTNERSFAIL 625
#define IDS_PBLDECODINGSTATUS 626
#define IDS_PBLOPENERR 627
#define IDS_PBLDLOPEN 628
#define IDS_PBLDLOPENFAIL 629
#define IDS_SENDINGPBL 630
#define IDS_QCSBLDECODINGSTATUS 631
#define IDS_QCSBLOPENERR 632
#define IDS_QCSBLDLOPEN 633
#define IDS_QCSBLDLOPENFAIL 634
#define IDS_SENDINGQCSBL 635
#define IDS_QCSBLHDRDECODINGSTATUS 636
#define IDS_QCSBLHDROPENERR 637
#define IDS_QCSBLHDRDLOPEN 638
#define IDS_QCSBLHDRDLOPENFAIL 639
#define IDS_SENDINGQCSBLHDR 640
#define IDS_OEMSBLDECODINGSTATUS 641
#define IDS_OEMSBLOPENERR 642
#define IDS_OEMSBLDLOPEN 643
#define IDS_OEMSBLDLOPENFAIL 644
#define IDS_SENDINGOEMSBL 645
#define IDS_OEMSBLHDRDECODINGSTATUS 646
#define IDS_OEMSBLHDROPENERR 647
#define IDS_OEMSBLHDRDLOPEN 648
#define IDS_OEMSBLHDRDLOPENFAIL 649
#define IDS_SENDINGOEMSBLHDR 650
#define IDS_MIMODEMDECODINGSTATUS 651
#define IDS_MIMODEMOPENERR 652
#define IDS_MIMODEMDLOPEN 653
#define IDS_MIMODEMDLOPENFAIL 654
#define IDS_SENDINGMIMODEM 655
#define IDS_MIMODEMHDRDECODINGSTATUS 656
#define IDS_MIMODEMHDROPENERR 657
#define IDS_MIMODEMHDRDLOPEN 658
#define IDS_MIMODEMHDRDLOPENFAIL 659
#define IDS_SENDINGMIMODEMHDR 660
#define IDS_MIAPPSDECODINGSTATUS 661
#define IDS_MIAPPSOPENERR 662
#define IDS_MIAPPSHDRDECODINGSTATUS 663
#define IDS_MIAPPSHDROPENERR 664
#define IDS_MIMODEMWRFAIL 665
#define IDS_MIMODEMCLOSEFAIL 666
#define IDS_OEMSBLWRFAIL 667
#define IDS_OEMSBLCLOSEFAIL 668
#define IDS_QCSBLWRFAIL 669
#define IDS_QCSBLCLOSEFAIL 670
#define IDS_QCSBLHDRWRFAIL 671
#define IDS_QCSBLHDRCLOSEFAIL 672
#define IDS_PBLWRFAIL 673
#define IDS_PBLCLOSEFAIL 674
#define IDS_USESTDDOWNLOADFORNOR 675
#define IDS_USEMIDOWNLOADFORNAND 676
#define IDS_OBLDECODINGSTATUS 677
#define IDS_OBLOPENERR 678
#define IDS_OBLDLOPEN 679
#define IDS_SENDINGOBL 680
#define IDS_OBLWRFAIL 681
#define IDS_OBLCLOSEFAIL 682
#define IDS_OBLDLOPENFAIL 683
#define IDS_OBLPROTECTED 684
#define IDS_BINIMAGEDECODINGSTATUS 685
#define IDS_FERASESTART 686
#define IDS_FERASEEND 687
#define IDS_FERASEFAIL 688
#define IDS_FERASEBOOT 689
#define IDS_FERASENANDONLY 690
#define IDS_MISENDEFSDECODINGSTATUS 691
#define IDS_MICEFSOPENERR 692
#define IDS_MICEFSOPEN 693
#define IDS_SENDINGMICEFS 694
#define IDS_MICEFSWRFAIL 695
#define IDS_MICEFSCLOSEFAIL 696
#define IDS_MICEFSDLOPENFAIL 697
#define IDS_MIAPPSDLOPEN 698
#define IDS_SENDINGMIAPPS 699
#define IDS_MIAPPSWRFAIL 700
#define IDS_MIAPPSCLOSEFAIL 701
#define IDS_MIAPPSDLOPENFAIL 702
#define IDS_MIAPPSBLDECODINGSTATUS 703
#define IDS_MIAPPSBLOPENERR 704
#define IDS_MIAPPSBLHDRDECODINGSTATUS 705
#define IDS_MIAPPSBLHDROPENERR 706
#define IDS_MIAPPSBLDLOPEN 707
#define IDS_SENDINGMIAPPSBL 708
#define IDS_MIAPPSBLWRFAIL 709
#define IDS_MIAPPSBLCLOSEFAIL 710
#define IDS_MIAPPSBLDLOPENFAIL 711
#define IDS_NOARMPRGFORCOMBO 712
#define IDS_ATMDL1F1    713
#define IDS_ATMDL1F2    714
#define IDS_ATMDL1F3    715
#define IDS_ATMDL1F4    716
#define IDS_ATMDL1F5    717
#define IDS_ATMDL1F6    718
#define IDS_ATMDL2F1    719
#define IDS_ATMDL2F2    720
#define IDS_ATMDL2F3    721
#define IDS_ATMNVBF1    722
#define IDS_ATMNVBF2    723
#define IDS_ATMNVBF3    724
#define IDS_ATMNVRF1    725
#define IDS_ATMNVRF2    726
#define IDS_ATMNVRF3    727
#define IDS_ATMNVRF4    728
#define IDS_ATMABORT    729
#define IDS_ATMMIDLC    730
#define IDS_ATMDL3F1    731
#define IDS_ATMDL3F2    732
#define IDS_ATMDL3F3    733
#define IDS_ATMDL3F4    734
#define IDS_ATMDL3F5    735
#define IDS_ATMDL3F6    736
#define IDS_ATMDL3F7    737
#define IDS_ATMDL4F1    738
#define IDS_ATMDL4F2    739
#define IDS_ATMDL4F3    740
#define IDS_ATMDL4F4    741
#define IDS_ATMDL4F5    742
#define IDS_ATMDL4F6    743
#define IDS_ATMDL4F7    744
#define IDS_ATMDL4F8    745
#define IDS_ATMDL5F1    746
#define IDS_ATMDL5F2    747
#define IDS_ATMDL5F3    748
#define IDS_ATMDL5F4    749
#define IDS_ATMDL5F5    750
#define IDS_ATMDL5F6    751
#define IDS_ATMDL5F7    752
#define IDS_ATMDL6F1    753
#define IDS_ATMDL6F2    754
#define IDS_ATMDL6F3    755

#define IDS_SKIP1FILE   756
#define IDS_SKIP2FILES  757

#define IDS_BACKINGUPBREW 758
#define IDS_RESTOREBREW   759

#define IDS_MIWINMOBILEDECODINGSTATUS 760
#define IDS_MIWINMOBILEOPENERR 761
#define IDS_SENDINGMIWINMOBILE 762
#define IDS_MIWINMOBILEWRFAIL 763
#define IDS_MIWINMOBILECLOSEFAIL 764
#define IDS_MIWINMOBILEDLOPENFAIL 765

#define IDS_BACKINGUPITEMS 766
#define IDS_RESTOREITEMS 767

#define IDS_NOUSERPRTNS 768
#define IDS_USERPRTNDECODINGSTATUS 769
#define IDS_USERPRTNOPENERR 770
#define IDS_USERPRTNDLOPEN 771
#define IDS_USERPRTNDLOPENFAIL 772
#define IDS_SENDINGUSERPRTN 773
#define IDS_USERPRTNWRFAIL 774
#define IDS_USERPRTNCLOSEFAIL 775
#define IDS_PRTNNOOVERIDE 776

#define IDS_INVNVIDRESP 777

#define IDS_SB2DBLDECODINGSTATUS 778
#define IDS_SB2DBLOPENERR 779
#define   IDS_SB2DBLSENDINGFILE 780
#define   IDS_SB2DBLWRFAIL 781
#define   IDS_SB2DBLCLOSEFAIL   782
#define   IDS_SB2DBLDLOPENFAIL 783

#define   IDS_SB2FSBLDECODINGSTATUS 784
#define   IDS_SB2FSBLOPENERR 785
#define   IDS_SB2FSBLSENDINGFILE 786
#define   IDS_SB2FSBLWRFAIL 787
#define   IDS_SB2FSBLCLOSEFAIL 788
#define   IDS_SB2FSBLDLOPENFAIL 789

#define   IDS_SB2OSBLDECODINGSTATUS 790
#define   IDS_SB2OSBLOPENERR 791
#define   IDS_SB2OSBLSENDINGFILE 792
#define   IDS_SB2OSBLWRFAIL 793
#define   IDS_SB2OSBLCLOSEFAIL 794
#define   IDS_SB2OSBLDLOPENFAIL 795

#define   IDS_DSP1DECODINGSTATUS 796
#define   IDS_DSP1OPENERR   797
#define   IDS_DSP1DLOPEN 798
#define   IDS_DSP1SENDINGFILE   799
#define   IDS_DSP1WRFAIL 800
#define   IDS_DSP1CLOSEFAIL 801
#define   IDS_DSP1DLOPENFAIL 802

#define   IDS_DSP2DECODINGSTATUS 803
#define   IDS_DSP2OPENERR   804
#define   IDS_DSP2DLOPEN 805
#define   IDS_DSP2SENDINGFILE   806
#define   IDS_DSP2WRFAIL 807
#define   IDS_DSP2CLOSEFAIL 808
#define   IDS_DSP2DLOPENFAIL 809

#define   IDS_ATMFACTF1 810
#define   IDS_ATMFACTF2 811
#define   IDS_ATMFACTF3 812
#define   IDS_FACTFILEOPENFAIL 813
#define   IDS_FACTIMGWRFAIL 814
#define   IDS_FACTIMGOPENFAIL   815
#define   IDS_FACTIMGCLOSEFAIL 816

#define   IDS_MBRDECODINGSTATUS 817
#define   IDS_MBROPENERR 818
#define   IDS_MBRDLOPEN 819
#define   IDS_MBRSENDINGFILE 820
#define   IDS_MBRWRFAIL 821
#define   IDS_MBRCLOSEFAIL 822
#define   IDS_MBRDLOPENFAIL 823


#endif // _QLIB_SOFTWARE_DOWNLOAD_DEFINES_H
