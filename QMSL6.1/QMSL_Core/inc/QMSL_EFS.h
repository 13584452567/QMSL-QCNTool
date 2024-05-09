/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Core/inc/QMSL_EFS.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_EFS
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QLIB_EFS_H)
#define _QLIB_EFS_H

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
                     Callback function definitions
   *******************************************************************************/
#if !defined(DIAG_FS_MAX_FILENAME_LEN)
#define DIAG_FS_MAX_FILENAME_LEN      80 /* Specified by EFS2              */
#define DIAG_FS_MAX_PATHNAME_LEN     128 /* Specified by EFS2              */
#endif
#define QLIB_EFS_MAX_FILENAME_LEN DIAG_FS_MAX_PATHNAME_LEN


//! Call back for an EFS directory element
   typedef unsigned char( *EfsDirCB )
   (
      char name[QLIB_EFS_MAX_FILENAME_LEN],  //defined in DiagEfsPkt.h
      unsigned char isFile,

      //attributes follow below
      unsigned short iAttributeMask,
      unsigned char iBufferingOption,
      unsigned char iCleanupOption,
      unsigned long iCreateDate,
      unsigned long iFileSize,
      HANDLE hContextID
   );

   /**
      Call back for EFS functions
   */
   typedef unsigned char (*EfsFileTransferCB)
   (
      char srcname[512],
      char dstname[512],
      int oper,
      int suboper,
      unsigned long bytestransferred,
      unsigned long filesize,
      HANDLE hContextID
   );


   /******************************************************************************
                     EFS Functions
   *******************************************************************************/


   /******************************************************************************/
   /**
   Initiates an EFS directory on a folder and calls a call-back function for each
   entry in the folder (both files and folders)

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFolderPath = must be in the format "folder1/folder2" without a leading "/"
   \return none

   \warning If callback function is not supplied, data will not be returned to the calling program.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsDirectory( HANDLE hResourceContext, char* sFolderPath );



   /******************************************************************************/
   /**

   Write file from computer to phone

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sLocalFile   = absolute path of file on PC
      \param sEFS_File      = absolute path of file to write on phone,
                                must be in the format "folder/file.ext" without a leading "/"

   \return true if successful, false if failure

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsWrite( HANDLE hResourceContext, char *sLocalFile, char *sEFS_File );

   /******************************************************************************/
   /**

   Write file from computer to phone using a RAM buffer isntead of a file.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sLocalMem       = buffer pointer to file contenet keeping in memory on PC
      \param iSize          = buffer size
      \param sEFS_File      = absolute path of file to write on phone,
                                must be in the format "folder/file.ext" without a leading "/"

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsWriteMem( HANDLE hResourceContext, char *sLocalMem, unsigned long iSize, char *sEFS_File );


   /******************************************************************************/
   /**

   EFS2, 80-V1294-11, 3.40 EFS2_DIAG_GET

   This packet is used to retrieve an EFS2 special item file

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param sEFS_File        = absolute path of file on phone,
                                must be in the format "/folder/file.ext" with a leading "/"
      \param sLocalFile       = absolute path of file to create on PC



   \return true if successful, false if failure

   *******************************************************************************/
   QLIB_API unsigned char QLIB_Efs2GetItem( HANDLE hResourceContext, char *sEFS_File, char *sLocalFile , int iEFSFileLength );

   /******************************************************************************/
   /**
   EFS2, 80-V1294-11, 3.40 EFS2_DIAG_PUT

   This packet is used to store a value in an EFS2 special item file.
   Item files can hold a small 2 amount of data more efficiently than regular files.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param sLocalFile       = absolute path of file to from PC

      \param sEFS_File        = absolute path of file to create on phone

      \return true if successful, false if failure

   *******************************************************************************/
   QLIB_API unsigned char QLIB_Efs2PutItem( HANDLE hResourceContext, char *sLocalFile, char *sEFS_File );

   /******************************************************************************/
   /**
   EFS2, 80-V1294-11, 3.40 EFS2_DIAG_PUT

   This packet is used to store a value in an EFS2 special item file.
   Item files can hold a small 2 amount of data more efficiently than regular files.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param sLocalMem       = store item 

      \param sEFS_File        = absolute path of file to create on phone

     \param sLocalMem       = item size

      \return true if successful, false if failure

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsPutItemFromMem(HANDLE hResourceContext, char *sLocalMem, char *sEFS_File, int iSize);

   /******************************************************************************/
   /**

   Reads EFS2 file content into a memory buffer

      \param hResourceContext[in] = Resource context that was returned from the call to QLIB_ConnectServer()

    \param dataBuffer[out]      = buffer where content of EFS file is stored

    \dataBufferSize[in,out]     = Size of dataBuffer. Number of bytes read into dataBuffer when function returns
                                  If original buffer is too small function fails and dataBufferSize contains size of EFS file

      \param sEFS_File[in]        = absolute path of file on phone,
                                    must be in the format "/folder/file.ext" with a leading "/"

   \return true if successful, false if failure

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsReadMem( HANDLE hResourceContext, char *dataBuffer, long *dataBufferSize, char *sEFS_File );

   /******************************************************************************/
   /**

   Read file from phone

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sEFS_File        = absolute path of file on phone,
                                must be in the format "folder/file.ext" without a leading "/"
      \param sLocalFile       = absolute path of file to create on PC

   Comments:  creates attr file is the same file path as data but with .att appended

   \return true if successful, false if failure

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsRead( HANDLE hResourceContext, char *sEFS_File, char *sLocalFile );

   /******************************************************************************/
   /**

   Set the size of the payload data to be used when requesting an EFS Read or Write.
   The higher this number, the fewer request/response packets will be needed to complete
   an EFS operation.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEFS_Read_Size = size of the payload of data used for the EFS read request packet.
                              The size should be less than DIAG_MAX_PACKET_SIZE minus the packet
                        response header for an EFS read. Default value is 524.

      \param iEFS_Write_Size = size of the payload of data used for the EFS write request packet.
                              The size should be less than DIAG_MAX_PACKET_SIZE minus the packet
                        request header for an EFS write.  Default is 536

   Comments:  creates attr file is the same file path as data but with .att appended

   \return true if successful, false if failure

   \warning The packet size has dependancies on the transport layer (QPST + Diagnostic handler in embedded software)
            If the size is set to a point that is <DIAG_MAX_PACKET_SIZE, but the request is failing, then the problem
          is most likely in one of these physical layer handlers and not in QMSL.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_SetEfsReadAndWritePacketSize(
      HANDLE hResourceContext,
      unsigned short iEFS_Read_Size,
      unsigned short iEFS_Write_Size );

   /******************************************************************************/
   /**

   Delete file from phone

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sFileName  - absolute path of file on phone,
                     must be in the format "folder/file.ext" without a leading "/"

   Comments:   Delete takes the phone offline, so you need to reset afterwards

   \return true if successful, false if failure


   \warning    This function is mapped into the diagnostic class, so that they will
               be available when QPST is not used.  Given this, they will not return
            error information via the EFS interface--rather the error information
            will be returned via the diagnostic interface.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsDelete( HANDLE hResourceContext, char *sFileName );

   /******************************************************************************/
   /**

   Delete folder and its contents from phone

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sFolderPath  - absolute path of folder on phone, without a leading "/"

   Comments:   Delete takes the phone offline, so you need to reset afterwards

   \return true if successful, false if failure


   \warning    This function is mapped into the diagnostic class, so that they will
               be available when QPST is not used.  Given this, they will not return
            error information via the EFS interface--rather the error information
            will be returned via the diagnostic interface.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsDelTree( HANDLE hResourceContext, char *sFolderPath );

   /******************************************************************************/
   /**

   Sets the permission bits on a file on the phone

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sFileName =  Absolute path of file on phone
      \param oAttr  = Attributes to set the file to

   Return Value:
      true if successful, false if failure

   \return true if successful, false if failure

   \warning  This function is not currently implemented.  If called, an error will be returned.

   *******************************************************************************/
   //unsigned char QLIB_EfsSetPermissions( char *sFileName, EfsDirItem* oAttr ) ;
   // bn: Oct 8, 2004, Disabled for Oct 15 release because more information is needed about this operation


   /******************************************************************************/
   /**

   Create a folder in the EFS file system

   Parameter(s):

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sEFS_Folder = absolute path of dir to create on phone.
                   So to make the dir "temp" off of the dir 'brew'
                   which is at root do "brew/temp" as the path
                   must be in the format "folder/folder2" without a leading "/"



   \return true if successful, false if failure

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsMkDir( HANDLE hResourceContext, char *sEFS_Folder );


   /******************************************************************************/
   /**

   Remove directory from phone

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sEFS_Folder      - absolute path of dir to create on phone.
                   So to remove the dir "temp" off of the dir 'brew'
                   which is at root, do "brew/temp" as the path
                   must be in the format "folder1/folder2" without a leading "/"

   \return true if successful, false if failure

   \warning    This function is mapped into the diagnostic class, so that they will
               be available when QPST is not used.  Given this, they will not return
            error information via the EFS interface--rather the error information
            will be returned via the diagnostic interface.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsRmDir( HANDLE hResourceContext, char *sEFS_Folder );

   /******************************************************************************/
   /**

   Remove a directory tree from the phone's EFS

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sEFS_Folder      - absolute path of dir to create on phone.
                   So to remove the dir "temp" off of the dir 'brew'
                   which is at root, do "brew/temp" as the path
                   must be in the format "folder1/folder2" without a leading "/"

   \return true if successful, false if failure

   \warning    This function is mapped into the QPST diagnostic class, so it will
               be availble only when QPST is used.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsRmTree( HANDLE hResourceContext, char *sEFS_Folder );

   /******************************************************************************/
   /**
   EFS2, 3.16 EFS2_DIAG_RENAME request/response

   This is used to rename a file or directory. Note that duplicate requests to rename a directory will
   lead to an error code being returned the second time if the rename was successful the first time. If
   the duplicate request is due to a missing response packet, the tool needs to check the error code to
   make sure that the error is reasonable (ENOENT will be the error returned in this case).

   NOTE If a request is received to remove an already removed directory, nothing is done
   but an error is   not reported.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorNo = Error code if error; otherwise, 0
   \param sOldFilePath = Old path name of file, for example "FactoryTest/Pictures/1.jpg"
                  This is case sensitive.
                  must be in the format "folder/file.ext" without a leading "/"

   \param sNewFilePath = New path name of file, for example "FactoryTest/Pictures/1.jpg"
                  This is case sensitive.
                  must be in the format "folder/file.ext" without a leading "/"

   \return True if successful, false if the command fails

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_DIAG_RENAME(
      HANDLE hResourceContext, char* sOldFilePath, char* sNewFilePath, unsigned long* piErrorNo );

   /******************************************************************************/
   /**
   EFS2, 3.17 EFS2_DIAG_STAT request/response

   This is used to retrieve information about a named file or directory.

   \param sFilePath = File, for example "FactoryTest/Pictures/1.jpg"
                  This is case sensitive.
                  must be in the format "folder/file.ext" without a leading "/"

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorNo = Error code if error; otherwise, 0
   \param piMode = File mode
   \param piSize = File Size
   \param piNlink = Number of links
   \param piAtime = Time of last access
   \param piMtime = Time of last modify
   \param piCtime = Time of last change
   \return True if successful, false if the command fails

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_DIAG_STAT(
      HANDLE hResourceContext, char* sFilePath, unsigned long* piErrorNo, unsigned long* piMode, unsigned long* piSize,
      unsigned long* piNlink, unsigned long* piAtime, unsigned long* piMtime, unsigned long* piCtime );

   /******************************************************************************/
   /**
   EFS2, 3.20 EFS2_DIAG_CHMOD request/response

   This is used to change the access permissions of a file or directory.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piMode = New Mode
   \param sFilePath = File, for example "FactoryTest/Pictures/1.jpg"
                  This is case sensitive.
                  must be in the format "folder/file.ext" without a leading "/"
   \param piErrorNo = Error code if error; otherwise, 0

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_DIAG_CHMOD(
      HANDLE hResourceContext, unsigned short iMode, char* sFilePath, unsigned long* piErrorNo);

   /******************************************************************************/
   /**
   EFS2, 3.21 EFS2_DIAG_STATFS request/response

   This is used to retrieve information about a file system. Note that the request packet must specify
   a path to a file or directory. Information is returned about the file system containing the named
   file or directory.


   \param iMode = New Mode
   \param sFilePath = File, for example "FactoryTest/Pictures/1.jpg"
                  This is case sensitive.
                  must be in the format "folder/file.ext" without a leading "/"

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorNo = Error code if error; otherwise, 0
   \param piFS_ID = File system ID
   \param piFS_Type = File system type
   \param piBlockSize = File system block size
   \param piTotalBlocks = File system size in bytes
   \param piAvailBlocks = Blocks available in file system
   \param piFreeBlocks = Blocks free in file system
   \param piMaxFileSize = Maximum size of a file in this file system
   \param piNfiles = Current number of files in this file system
   \param piMaxNfiles = Maximum number of files in this file system

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_DIAG_STATFS(
      HANDLE hResourceContext, char* sFilePath, unsigned long* piErrorNo, unsigned long* piFS_ID,
      unsigned long* piFS_Type, unsigned long* piBlockSize,
      unsigned long* piTotalBlocks, unsigned long* piAvailBlocks, unsigned long* piFreeBlocks, unsigned long* piMaxFileSize,
      unsigned long* piNfiles, unsigned long* piMaxNfiles);

   /******************************************************************************/
   /**
   EFS2, 3.22 EFS2_DIAG_ACCESS request/response

   Check a named file for accessibility. This is used to check access
   permissions for a file or directory.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iPermissionBits = Permissions bits
   \param sFilePath = File, for example "FactoryTest/Pictures/1.jpg"
                  This is case sensitive.
                  must be in the format "folder/file.ext" without a leading "/"

   \param piErrorNo = Error code if error; otherwise, 0

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_DIAG_ACCESS( HANDLE hResourceContext, unsigned short iPermissionBits, char* sFilePath, unsigned long* piErrorNo);

   /******************************************************************************/
   /**
   EFS2, 3.23 EFS2_DIAG_DEV_INFO request/response

   This command is used to request the specifications of the flash device being used in the phone.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorNo = Error code if error; otherwise, 0
   \param piTotalNumOfBlocks = Total number of blocks in the device
   \param piNumPagesPerBlock = Number of pages in a block
   \param piPageSize = Size of page data region in bytes
   \param piTotalPageSize = Size of total page_size
   \param piMakerId = Device maker ID
   \param piDeviceId = Device ID
   \param piDeviceType = 0 indicates NOR device, 1 indicates NAND
   \param sDeviceName = Beginning of the string containing name of the device (null terminated string)

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_DIAG_DEV_INFO(
      HANDLE hResourceContext, unsigned long* piErrorNo, unsigned long* piTotalNumOfBlocks,
      unsigned long* piNumPagesPerBlock, unsigned long* piPageSize, unsigned long* piTotalPageSize,
      unsigned long* piMakerId, unsigned long* piDeviceId, unsigned char* piDeviceType, char* psDeviceName );

   /******************************************************************************/
   /**
   EFS2,   EFS2_DIAG_READLINK request/response

   this is used to retrieve path name pointed out by a link.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sPathName =   path name of link file, for example "VoiceDB/Lang/English/engdat1.dtw"
                  this is case sensitive.
                  must be in the format "folder/file.ext" without a leading "/"

   \param sPointedFilePath = received path pointed out by a link
   \return true if successful, false if the command fails

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsReadLink( HANDLE hResourceContext, char *sEFS_Path, char *sEFS_Pointed_Path);

   /******************************************************************************/
   /**
   EFS2,   EFS2_DIAG_CREATE_LINK request/response

   this is used to create link

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sPathName =   path name of link file, for example "VoiceDB/Lang/English/engdat1.dtw"
                  this is case sensitive.
                  must be in the format "folder/file.ext" without a leading "/"

   \param sPointedFilePath = path pointed by a link
   \return true if successful, false if the command fails

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_EfsCreateLink( HANDLE hResourceContext, char *sEFS_Path, char *sEFS_Pointed_Path);

   /******************************************************************************/
   /**
   EFS2,   EFS2_DIAG_EXTENDED_INFO request/response

   this is used to request EFS information.  The user must supply a query type, and
   the function will perform the query and return either an integer or a string,
   depending upon the query type.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iQueryType = type of query to perform. Values are defined by EFS2_EXT_Kind_Enum in QLib_Defines.h

   \param piReturnDataType = output, data type (int or string) that is being returned.
                             Values are defined by EFS2_EXT_Kind_Enum in QLib_Defines.h

   \param piReturnInt = output, holds integer return values

   \param sReturnString = output, holds string return values

   \return true if successful, false if the command fails

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_DIAG_EXTENDED_INFO(
      HANDLE hResourceContext,
      unsigned long iQueryType,
      unsigned long* piReturnDataType,
      unsigned long* piReturnInt,
      char sReturnString[32]
   );

   /******************************************************************************/
   /**
   EFS2, 80-V1294-11 3.50 EFS2_DIAG_SYNC_NO_WAIT and EFS2_DIAG_SYNC_GET_STATUS request/response

   This command is used to synchronize the file system to the backing store, start the sync process,
   and return immediately, without blocking the caller. Upon return, a SYNC_TOKEN will be
   provided to the caller. The caller uses this SYNC_TOKEN to learn about the status of this sync
   operation, by calling the EFS2_DIAG_SYNC_GET_STATUS command

   Send EFS2_DIAG_SYNC_NO_WAIT command and return the status of by calling EFS2_DIAG_SYNC_GET_STATUS

   After EFS2_DIAG_SYNC_NO_WAIT is sent succesfully, QMSL will poll for sync status by calling EFS_DIAG_SYNC_GET_STATUS.
   The polling occurs every 100ms until "sync is complete" status is returned or timeout

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

    \param sFilePath = EFS file path to be synced

   \param iTimeOut_ms = Timeout value in ms for waiting for "sync is complete" message.

   \param piExecutionStuats = 0 = Command executed ok ("sync is complete" diag message is received)
                        1 = Command error occured ("ERRNO is not zero")
                        2 = Command can't be dispatched target ("0x18 is returned as when EFS2_DIAG_SYNC_NO_WAIT is sent")
                        3 = Timeout occurred ("sync is pendinng" diag response is last received when timeout)

   \return true if successful, false if the command fails

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_SyncWithWait(
      HANDLE hResourceContext,
      unsigned char* sFilePath,
      unsigned long iTimeOut_ms,
      unsigned char* piExecutionStatus
   );

   /******************************************************************************/
   /**
   EFS2, 80-V1294-11 3.50 EFS2_DIAG_SYNC_NO_WAIT and EFS2_DIAG_SYNC_GET_STATUS request/response

   This command is used to synchronize the file system to the backing store, start the sync process,
   and return immediately, without blocking the caller. Upon return, a SYNC_TOKEN will be
   provided to the caller. The caller uses this SYNC_TOKEN to learn about the status of this sync
   operation, by calling the EFS2_DIAG_SYNC_GET_STATUS command

   Send EFS2_DIAG_SYNC_NO_WAIT command and return the status of by calling EFS2_DIAG_SYNC_GET_STATUS

   After EFS2_DIAG_SYNC_NO_WAIT is sent succesfully, QMSL will poll for sync status by calling EFS_DIAG_SYNC_GET_STATUS.
   The polling occurs every 100ms until "sync is complete" status is returned or timeout

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

    \param sFilePath = EFS file path to be synced

   \param iTimeOut_ms = Timeout value in ms for waiting for "sync is complete" message.

   \param piExecutionStuats = 0 = Command executed ok ("sync is complete" diag message is received)
                        1 = Command error occured ("ERRNO is not zero")
                        2 = Command can't be dispatched target ("0x18 is returned as when EFS2_DIAG_SYNC_NO_WAIT is sent")
                        3 = Timeout occurred ("sync is pendinng" diag response is last received when timeout)

   \return true if successful, false if the command fails

   \warning
   *******************************************************************************/
   QLIB_API unsigned long QLIB_EFS2_GetGroupInfo(
      HANDLE hResourceContext,
      unsigned char* sFilePath,
      unsigned long* efs_file_size,
      unsigned long* remaining_efs_file_size
   );

   /**
   EFS2,  80-V1294-11 3.55 EFS2_DIAG_MAKE_GOLDEN_COPY request/response

   This packet requests the creation of a backup (golden copy) of the current state of the file system.
   Creation of a backup for the file system is NOT supported for all storage devices (e.g. Flash).
   DIAG can only be used to create a backup one time over the life of the device. If a power loss
   occurs during backup creation, the backup will not be created and further attempts to create a
   backup using DIAG will fail.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

    \param sFilePath = Path name (NULL-terminated string)

   \param pERRNO =  If successful, 0; otherwise, error code

   \return true if successful, false if the command fails

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_EFS2_DIAG_MAKE_GOLDEN_COPY(
      HANDLE hResourceContext,
      unsigned char *sFilePath,
      unsigned long* pERRNO);


   /******************************************************************************/
   /**
   Aborts the most recent EFS download operation.  Will only affect these functions:
      QLIB_EfsWrite()
      QLIB_EfsRead()

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer().



   \return none

   \warning Any current operations will be terminated.  This can cause problems with the
            phone state.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_AbortEFS_Operation( HANDLE hResourceContext );

   /******************************************************************************/
   /**


   Get the error status and description of the last EFS operation.  The only operations
   that use this mechanism are:
      QLIB_DownloadPRL()
      QLIB_UploadPRL()
      QLIB_DownloadCEFS_File()
      QLIB_EfsRmTree()

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param bErrorOccurred    = true if an error occurred during the last operation.  False if no error
                           occurred during the last operation.

      \param sErrorMessage     = Filled filled in with a text description of the most recent error.
                           Empty if no error has occurred.

      \param iMaxStringLength  = Maximum number of characters available in the sErrorMessage buffer

      \return true if successful, false if failure

      \warning  The error information will be cleared after this is called.

   *******************************************************************************/
   QLIB_API void QLIB_GetLastEfsErrorInfo
   ( HANDLE hResourceContext, unsigned char* bErrorOccurred, char *sErrorMessage, int iMaxStringLength );


   #ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_H)
