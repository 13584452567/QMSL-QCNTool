/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Misc/QMSL_AP/inc/QMSL_FTM_AP.h#7 $
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
#if !defined(_QMSL_FTM_AP_H)
#define _QMSL_FTM_AP_H

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
#endif


#ifdef __cplusplus
extern "C" {
#endif
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_TEST_APP_STATUS
   
   Get MMI Test Application Status

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \param iState  State of MMI test execution
               0 = Idle
                   1 = Executing
           
   \param iFail_Count The number of test failed in MMI application
 
   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_TEST_APP_STATUS ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, unsigned char* iState, unsigned int* iFail_Count);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_SELECT_SEQUENCE

   Specify the test sequence file (.seq/.cfg) to load.  Any error in loading .seq/.cfg file will cause 
   MMI Test application to use the default sequence file (MMI.seq).  
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \param iNum_Tests = The number of test available in the sequence

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/   
   QLIB_API unsigned char QLIB_FTM_AP_SELECT_SEQUENCE ( HANDLE hResourceContext, char* sSequenceFile, unsigned short* iFTM_Error_Code, unsigned short *iNum_Test );
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_CLEAR_RESULTS

   Erase the content of the test result file (.res) for the current selected sequence loaded by command FTM_AP_SELECT_SEQUENCE
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/   
   QLIB_API unsigned char QLIB_FTM_AP_CLEAR_RESULTS ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_EXECUTE_SINGLE_TEST

   Execute a single MMI test case specified by the test name
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \param sTestCase Test Case Name in ASCII

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_EXECUTE_SINGLE_TEST ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, char* sTestCase);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_EXECUTE_SINGLE_TEST

   Execute a single MMI test case specified by the test name
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \param sTestCase Test Case Name in ASCII

   \param iTestStatus, The test status returned by the MMI test case

   \param iTimeoutInS, Timeout value in seconds.  If the timeout value is 0, this API will not wait for asychronus log message returned.

   \param iTimeoutOcurred, 1 = Time out occurred.
                           0 = Time out did not occur.

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_EXECUTE_SINGLE_TEST_WithWait ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, char* sTestCase, unsigned long* iTestStatus,unsigned short iTimeoutInS, unsigned char*iTimeoutOcurred);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_EXECUTE_ALL_TESTS

   Start the execution of tests in the selected sequence based on the sequence file (.seq) loaded by command FTM_AP_SELECT_SEQUENCE
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_EXECUTE_ALL_TESTS ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code);
   QLIB_API unsigned char QLIB_FTM_AP_EXECUTE_ALL_TESTS_WithWait ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, unsigned long* iTestStatus,unsigned short iTimeoutInS, unsigned char*iTimeoutOcurred);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_READ_FILE

   Download a file from the FTM_AP folder to the PC
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param sRemoteFileName, the remote filename on the target

   \param sLocalFileName, the local filename on the PC

   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_READ_FILE ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, char * sRemoteFileName, char * sLocalFileName );
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_WRITE_FILE

   Upload a file from the PC to the FTM_AP folder on target
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
 
   \param sRemoteFileName, the remote filename on the target

   \param sLocalFileName, the local filename on the PC

   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_WRITE_FILE ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, char * sRemoteFileName, char * sLocalFileName );
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_ERASE_ALL_FILES

   Erase all files in FTM_AP directory
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_ERASE_ALL_FILES ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_TEST_LIST_TO_FILE

   Publish the list of available test identified by TEST_NAME and VERSION to a file called TestList.Txt, in the FTM_AP directory
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_TEST_LIST_TO_FILE ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_DIR_TO_FILE

   List the FTM_AP directory contents to a file Directory.Txt, in the FTM_AP directory.  
   The Directory.Txt file can later be retrieved to desktop with FTM_AP_READ_FILE command.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   
   \param iFTM_Error_Code FTM Error Code
                          0 = Success
                    1 = Error

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_DIR_TO_FILE ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) only in Linux/Android MMI app target : Application processor test command: FTM_AP_UTILITY

   Enable or disable a specific function of the phone, identified by iUtilityStatus (enable or disable) and iUtilityID (function ID).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iUtilityID = The Utinity ID.

      0  AutoStart: enable/disable running some items (e.g. WLAN/BT scan test) in parallel when entering FFBM mode, this change would take effect after reboot the phone; enable this function could save test time for some specific items; 
      1  WLAN: enable/disable WLAN test mode;
      2  BT: enable/disable BT test mode;
      3  CHARGER: enable/disable charger;
      4  NFC: enable/disable NFC test mode;

   \param iUtilityStatus = The Utinity status.

         0  OFF (disable);
      1  ON  (enable);

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_UTILITY ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, unsigned char iUtilityID, unsigned char iUtilityStatus);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_READ_APP_VERSION

   This command is used to read the version of MMI test application from embedded side

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \The version of MMI test application is scaled by 100

   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_READ_APP_VERSION ( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, unsigned char* sVersion);
   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_EXIT_TEST

   The command will instruct MMI application to exit the current running test. The PC will pass the PASS/FAIL result to MMI app.  
   
   The MMI app will print the PASS/FAIL result to the current result file.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iResult : 1 = PASS 0 = FAIL

   \param sTestCase Test Case Name in ASCII
   
   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_EXIT_TEST( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, unsigned long iResult, char* sTestCase);

   /******************************************************************************/
   /**
   Factory Test Mode(FFBM/MMOS) : Application processor test command: FTM_AP_APPEND_TO_RES

   The command will instruct MMI application to pass each parametric result to the MMI app.
   
   The MMI app will append the line to the current result file.  

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sTestCase Test Case Name in ASCII (maximum length - 64 bytes)

   \param sContentLine in variable ASCII Null terminated. A single containing the name value pair of parametric result.The line should contain "=" character to separate name and value.
   
   \return true if successful, false if fail.

   \note. The user must reset the device

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AP_APPEND_TO_RES( HANDLE hResourceContext, unsigned short* iFTM_Error_Code, char* sTestCase, char* sContentLine);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_FTM_AP_H)
