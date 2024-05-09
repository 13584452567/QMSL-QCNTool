/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WP/inc/QMSL_FTM_WP.h#7 $
 * $DateTime: 2016/04/04 17:51:51 $
 *
 *
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */

#if !defined(_QMSL_FTM_WP_H)
#define _QMSL_FTM_WP_H

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
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone 8.1 test command: FTM_WP_FUSE_CHECK

   Check if fuses are blown correctly. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sData this returns a 8 byte return value related to the fuses blown
   
   \param iFTM_Error_Code FTM Error Code
                     0 = Success
                   
   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_FUSE_CHECK(HANDLE hResourceContext, unsigned char* sData, unsigned long* iFTM_Error_Code);

   /******************************************************************************/

   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_FILE

   Provision single file onto device provisioning partition(DPP)

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFileName This is the filename of the candidate file,t he candidate file is required to be uploaded to device
               prior to this command.

   \param sFile_DPP_Type, this parameter denotes the type of the DPP item the sFileName is to be 
                     provisioned as, where 0 = QCOM and 1 = OEM

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_FILE(HANDLE hResourceContext, char* sFileName, unsigned short* sFile_DPP_Type, unsigned long* iFTM_ERROR_CODE );

   /******************************************************************************/

   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_SSD

   Provision Secure Software Download (SSD) keystore.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFileName, this is the SSD filename, the SSD key is required to be uploaded to device 
               before calling this command.
   .

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_SSD(HANDLE hResourceContext, char* sFileName, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_HDCP_CEK

   Provision HDCP 2.x CEK key

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFileName this is the filename of the file containing the HDCP 2.x CEK key we wish to provision onto the windows phone.
               the file should be uploaded onto the device before calling this command.

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_HDCP_CEK(HANDLE hResourceContext, char* sFileName, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_HDCP_DATA

   Provision HDCP 2.x DATA key.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFileName this is the filename of the file containing the HDCP 2.x DATA key we wish to provision onto the windows phone.
               the file should be uploaded onto the device before calling this command.

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_HDCP_DATA(HANDLE hResourceContext, char* sFileName, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_OPM_PUB

   Provision PVP-OPM public key. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFileName this is the filename of the file containing the PVP-OPM public key we wish to provision onto the windows phone.
               the file should be uploaded onto the device before calling this command

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_OPM_PUB(HANDLE hResourceContext, char* sFileName, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_OPM_PRIV

   Provision PVP-OPM private key. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFileName this is the filename of the file containing the PVP-OPM private key we wish to provision onto the windows phone.
               the file should be uploaded onto the device before calling this command

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_OPM_PRIV(HANDLE hResourceConttext, char* sFileName, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_GET_DEVICE_UNIQUE_ID

   Get the unique device id for the windows phone. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param ovk_variable this is the unique 32 byte id that is generated by the phone.

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_GET_DEVICE_UNIQUE_ID(HANDLE hResourceContext, unsigned char* ovk_variable, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_OVK_HASH

   Provision PVP-OPM private key. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFileName this is the filename of the file containing the signed OVK hash private key we wish to provision onto the windows phone.
               the file should be uploaded onto the device before calling this command

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_OVK_HASH(HANDLE hResourceContext, char* sFileName, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_OVK_HASH

   Disable DIAG and factory services, switch USB transport from Serial composite mode to MTP mode, disable test 
   signing, enable secureboot. 
 
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_LOCK_DEVICE(HANDLE hResourceContext, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/

   /******************************************************************************/
   /**
   80-NG894-15
   WINDOWS 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_VALIDATE_PROVISIONED_FILE

   Disable DIAG and factory services, switch USB transport from Serial composite mode to MTP mode, disable test 
   signing, enable secureboot. 
 
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFileName file to be validated

   \param sFile_DPP_Type, this parameter denotes the type of the DPP item the sFileName is to be 
                     provisioned as, where 0 = QCOM and 1 = OEM

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WP_VALIDATE_PROVISIONED_FILE(HANDLE hResourceContext, char* sFileName, unsigned short sFile_DPP_Type, unsigned long* iFTM_ERROR_CODE);


   /******************************************************************************/
   /**
   80-NG894-15
   WINDOWS 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_READ_PROVISIONED_FILE

   Disable DIAG and factory services, switch USB transport from Serial composite mode to MTP mode, disable test 
   signing, enable secureboot. 
 
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFile_DPP_Type, this parameter denotes the type of the DPP item the sFileName is to be 
                     provisioned as, where 0 = QCOM and 1 = OEM

   \param sRemoteFileName file to be read

   \param sLocalFileName PC location where to store the file

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WP_READ_PROVISIONED_FILE(HANDLE hResourceContext, unsigned short sFile_DPP_Type, char * sRemoteFileName, char * sLocalFileName, unsigned long* iFTM_Error_Code);


   /******************************************************************************/
   /**
   80-NG894-15
   WINDOWS 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_REGISTRY_READ

   Disable DIAG and factory services, switch USB transport from Serial composite mode to MTP mode, disable test 
   signing, enable secureboot. 
 
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sKeyValuePath The key value path to read

   \param sKeyType registry key type 
                     0 -   HKEY_CLASS_ROOT
                     1 -   HKEY_CURRENT_USER
                     2 -   HKEY_LOCAL_MACHINE
                     3 -   HKEY_USERS
                     4 -   HKEY_CONFIG

   \param iFTM_Error_Code FTM Error Code
                     0 = Success         

   \param sSize The size of registry key

   \param sDate The registry key value

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WP_REGISTRY_READ( HANDLE hResourceContext, char* sKeyValuePath, unsigned short sKeyType, unsigned long* iFTM_ERROR_CODE, unsigned short* sSize, char* sData);


   /******************************************************************************/
   /**
   80-NG894-15
   WINDOWS 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_SHUTDOWN

   Disable DIAG and factory services, switch USB transport from Serial composite mode to MTP mode, disable test 
   signing, enable secureboot. 
 
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sStichyCharging The key value path to read
                     0 -   Disable sticky charging
                     1 -   Enaable sticky charging                  

   \param iFTM_Error_Code FTM Error Code
                     0 = Success         

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WP_SHUTDOWN(HANDLE hResourceContext, unsigned short sStichyCharging, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   80-NG894-15
   WINDOWS 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_FACTORY_RESET

   Disable DIAG and factory services, switch USB transport from Serial composite mode to MTP mode, disable test 
   signing, enable secureboot. 
 
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iFTM_Error_Code FTM Error Code
                     0 = Success         

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WP_FACTORY_RESET(HANDLE hResourceContext, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_HDCP_HDMI_V1

   Provision HDCP HDMI V1 key. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sKeyFile this is the filename of the HDCP HDMI V1 key

   \param sDpsFile this is the filename of the HDCP HDMI V1 DPS file

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_HDCP_HDMI_V1(HANDLE hResourceContext, char* sKeyFile, char* sDpsFile, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_PROVISION_HDCP_HDMI_V2

   Provision HDCP HDMI V2 key. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param sKeyFile this is the filename of the HDCP HDMI V2 key

   \param sDpsFile this is the filename of the HDCP HDMI V2 DPS file

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_PROVISION_HDCP_HDMI_V2(HANDLE hResourceContext, char* sKeyFile, char* sDpsFile, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_VALIDATE_HDCP_HDMI_V1

   Validate HDCP HDMI V1 key. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_VALIDATE_HDCP_HDMI_V1(HANDLE hResourceContext, unsigned long* iFTM_ERROR_CODE);

   /******************************************************************************/
   /**
   WINDOWS PHONE 8.1 method 

   Factory Test Mode(FFBM/MMOS) : Windows Phone test command: FTM_WP_VALIDATE_HDCP_HDMI_V2

   Validate HDCP HDMI V2 key. 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iFTM_Error_Code FTM Error Code
                     0 = Success                    

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WP_VALIDATE_HDCP_HDMI_V2(HANDLE hResourceContext, unsigned long* iFTM_ERROR_CODE);

#ifdef __cplusplus
}   
#endif

#endif   
