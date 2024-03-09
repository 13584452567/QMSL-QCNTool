/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Core/inc/QMSL_Diag.h#8 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_Diag
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_DIAG_H)
#define _QMSL_DIAG_H

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
                     Diagnostic commands
   *******************************************************************************/
   /******************************************************************************/
   /**

   The function checks whether the phone is in FTM mode.

   Depending on the command code ( FTM_COMMAND_59 or FTM_COMMAND75 ),
   this function uses different methods to check for FTM mode.

   Method 1:
   If the command code is set to FTM_COMMAND_59, this function reads the NV_FTM_MODE item to check
   whether the phone is in FTM mode.

   Note that MSM6000/6025/6050 and older MSM targets use FTM_COMMAND_59 command code for FTM mode transcation.

   Method 2:
   If the command code is set to FTM_COMMAND_75, this function issues a CM state info request
   to query the phone state.  The command is CMLOG_STATE_INFO_F (refer 80-V1294-7, 3.2).

   General comment:
   The command code should be set by QLIB_FTM_SET_COMMAND_CODE function before this function is called.
   By default, the command code is FTM_COMMAND_75.

   \param pbIsFTMMode = output, true(1) if the phone is in FTM mode,
                            false(0) if the phone is not in FTM mode

   \return true if the function is successful

   *******************************************************************************/
   QLIB_API unsigned char QLIB_IsFTM_Mode(HANDLE hResourceContext, unsigned char *pbIsFTMMode);

   /******************************************************************************/
   /**

   Returns the current mode of the phone, determined by calling the Call manager status
   command, 80-V1294-7 CMLOG_STATE_INFO_F.  The field returned is OPERATIONAL_MODE

   This function is not available on AMSS which does not support the diagnostic subsystem
   commands (e.g. not available on MSM6000, MSM6025, MSM6050).

   For APQ only target, CMLOG_STATE_INFO_F is not supported.

   If the QMSL handle target type is set to APQ, {0x75, 0x32, 0x3, 0x0} will be sent to phone to check
   for diag servic.  SYS_OPRT_MODE_AQ_DIAG_ALIVE or SYS_OPRT_MODE_APQ_DIAG_NO_RESPONSE will be response value

   Please also refer to QLIB_SetTargetType for more details

   \param piPhoneMode = output, true(1) if the phone is in FTM mode,
                            false(0) if the phone is not in FTM mode
   \code
      SYS_OPRT_MODE_PWROFF        = 0,   //!< ' Phone is powering off
      SYS_OPRT_MODE_FTM           = 1,   //!< ' Phone is in factory test mode
      SYS_OPRT_MODE_OFFLINE       = 2,   //!< ' Phone is offline
      SYS_OPRT_MODE_OFFLINE_AMPS  = 3,   //!< ' Phone is offline analog
      SYS_OPRT_MODE_OFFLINE_CDMA  = 4,   //!< ' Phone is offline cdma
      SYS_OPRT_MODE_ONLINE        = 5,   //!< ' Phone is online
      SYS_OPRT_MODE_LPM           = 6,   //!< ' Phone is in LPM - Low Power Mode
      SYS_OPRT_MODE_RESET         = 7,   //!< ' Phone is resetting - i.e. power-cycling
      SYS_OPRT_MODE_NET_TEST_GW   = 8,   //!< ' Phone is conducting network test for GSM/WCDMA.
      SYS_OPRT_MODE_OFFLINE_IF_NOT_FTM = 9, //!< ' offline request during powerup.
      SYS_OPRT_MODE_PSEUDO_ONLINE = 10, //!< ' Phone is pseudo online, tx disabled

     SYS_OPRT_MODE_APQ_DIAG_ALIVE = 12,      //!< 'Defined by QMSL, not by AMSS, indicate AMSS diag service is alive
     SYS_OPRT_MODE_APQ_DIAG_NO_RESPONSE = 13      //!< 'Defined by QMSL, not by AMSS, indicate AMSS diag service is dead (no diag response)

   \endcode

   \return true if the function is successful

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GetPhoneOperatingMode(HANDLE hResourceContext, unsigned long *piPhoneMode);

   /******************************************************************************/
   /**

   Returns the call status the phone, determined by calling the Call manager status
   command, 80-V1294-7 CMLOG_STATE_INFO_F.  The fields returned are
   OVERALL_CALL_STATE and SYSTEM_MODE

   Note 1: This function is not available on AMSS which does not support the diagnostic subsystem
   commands (e.g. not available on MSM6000, MSM6025, MSM6050).


   Note 2: this function will not return meaningful results for GSM and WCDMA.  Use QLIB_DIAG_GSM_STATUS_F()
   for these modes.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piPhoneMode = output, true(1) if the phone is in FTM mode,
                            false(0) if the phone is not in FTM mode
   \code
      CM_CALL_STATE_NONE       = -1,     //!< 'FOR INTERNAL USE OF CM ONLY!
      CM_CALL_STATE_IDLE       = 0,      //!< ' Call is in idle state - i.e. no call
      CM_CALL_STATE_ORIG       = 1,      //!< ' Call is in origination state
      CM_CALL_STATE_INCOM      = 3,      //!< ' Call is in alerting state
      CM_CALL_STATE_CC_IN_PROGRESS = 4,  //!< ' Call is originating but waiting for call control to complete
      CM_CALL_STATE_CONV       = 5,      //!< ' Call is in conversation state
   \endcode

   \param piSystemMode = output, system mode
   \code
       SYS_SYS_MODE_NONE    = -1, //!< ' FOR INTERNAL USE ONLY!
       SYS_SYS_MODE_NO_SRV  = 0, //!< ' No service = NV_MODE_INACTIVE
       SYS_SYS_MODE_AMPS    = 1, //!< ' Analog Mobile Phone System (AMPS) mode
       SYS_SYS_MODE_CDMA    = 2, //!< ' Code Division Multiple Access (CDMA) mode
       SYS_SYS_MODE_GSM     = 3, //!< ' Global System for Mobile communications (GSM) mode
       SYS_SYS_MODE_HDR     = 4, //!< ' High Data Rate (HDR) mode
       SYS_SYS_MODE_WCDMA   = 5, //!< ' Wideband CDMA (WCDMA) mode
       SYS_SYS_MODE_GPS     = 6, //!< ' Global Positioning System (GPS) mode
       SYS_SYS_MODE_GW      = 7, //!< ' GSM and WCDMA mode

   \endcode

   \return true if the function is successful

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GetPhoneCallState(
      HANDLE hResourceContext,
      unsigned long *piCallState,
      unsigned long *piSystemMode);

   /******************************************************************************/
   /**

   Returns the call status the phone, determined by calling the Call manager status
   command, 80-V1294-7 Rev. H CMLOG_STATE_INFO_F2.  The fields returned are
   OVERALL_CALL_STATE and SYSTEM_MODE

   Note 1: This function is not available on AMSS which does not support the diagnostic subsystem
   commands CMLOG_STATE_INFO_F2.

   Note 2: this function will not return meaningful results for GSM and WCDMA.  Use QLIB_DIAG_GSM_STATUS_F()
   for these modes.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param piPhoneMode = output, true(1) if the phone is in FTM mode,
                            false(0) if the phone is not in FTM mode
   \code
      CM_CALL_STATE_NONE       = -1,     //!< 'FOR INTERNAL USE OF CM ONLY!
      CM_CALL_STATE_IDLE       = 0,      //!< ' Call is in idle state - i.e. no call
      CM_CALL_STATE_ORIG       = 1,      //!< ' Call is in origination state
      CM_CALL_STATE_INCOM      = 3,      //!< ' Call is in alerting state
      CM_CALL_STATE_CC_IN_PROGRESS = 4,  //!< ' Call is originating but waiting for call control to complete
      CM_CALL_STATE_CONV       = 5,      //!< ' Call is in conversation state
   \endcode

   \param piSystemMode = output, system mode
   \code
       SYS_SYS_MODE_NONE    = -1, //!< ' FOR INTERNAL USE ONLY!
       SYS_SYS_MODE_NO_SRV  = 0, //!< ' No service = NV_MODE_INACTIVE
       SYS_SYS_MODE_AMPS    = 1, //!< ' Analog Mobile Phone System (AMPS) mode
       SYS_SYS_MODE_CDMA    = 2, //!< ' Code Division Multiple Access (CDMA) mode
       SYS_SYS_MODE_GSM     = 3, //!< ' Global System for Mobile communications (GSM) mode
       SYS_SYS_MODE_HDR     = 4, //!< ' High Data Rate (HDR) mode
       SYS_SYS_MODE_WCDMA   = 5, //!< ' Wideband CDMA (WCDMA) mode
       SYS_SYS_MODE_GPS     = 6, //!< ' Global Positioning System (GPS) mode
       SYS_SYS_MODE_GW      = 7, //!< ' GSM and WCDMA mode
   SYS_SYS_MODE_WLAN    = 8,       //!< ' WLAN mode
   SYS_SYS_MODE_LTE    = 9,       //!< ' LTE
   SYS_SYS_MODE_GWL       = 10,    //!< ' GSM, WCDMA and LTE mode

   \endcode

   \return true if the function is successful

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GetPhoneCallState_V2(
      HANDLE hResourceContext,
      unsigned long *piCallState,
      unsigned long *piSystemMode);

   /******************************************************************************/
   /**

   The function changes phone to FTM or ONLINE mode through NV item NV_FTM_MODE method.

   This function:

   1. Changes phone to offline mode (QLIB_DIAG_CONTROL_F(MODE_OFFLINE_F))
   2. Delays by the timeout value QMSL_Timeout_Delay_OFFLINE, which can be set wiht
      QLIB_ConfigureTimeout()
   2. Writes bFTMmode value to NV item NV_FTM_MODE (453)

   If (bReset == 1), the function returns immediately after reset command is issued.

   \param bFTMMode = (1 = FTM mode), (0 = ONLINE mode)
   \param bReset = (1 = Reset after NV write), (0 = No reset after NV write)

   \return true if the function is successful

   *******************************************************************************/
   QLIB_API unsigned char QLIB_ChangeFTM_BootMode(HANDLE hResourceContext, unsigned char bFTMmode, unsigned char bReset);

   /******************************************************************************/
   /**

   The function changes the mode to ONLINE or FTM mode using run time method

   The function calls IsFTM_Mode to determines the phone is in FTM mode or not.

   If current mode is not equal to bFTMmode, it will switch mode.

   General comment:
   This function can't be used in MSM6000/6025/6050 and older MSM targets.  As they
   use FTM_COMMAND_59 command code for FTM and DO NOT support runtime swtiching to FTM

   The command code should be set to FTM_COMMAND_75 by QLIB_FTM_SET_COMMAND_CODE function
   before this function is called.

   By default, the command code is FTM_COMMAND_75.

   \param bFTMMode = (1 = FTM mode), (0 = ONLINE mode)

   \return true if the function is successful

   *******************************************************************************/
   QLIB_API unsigned char QLIB_ChangeFTM_ModeRuntime(HANDLE hResourceContext, unsigned char bFTMmode);


   /******************************************************************************/
   /**
   DMSS Diagnostic ICD, 3.4.38 Mode Change Request/Response
   WCDMA Diagnostic ICD, 3.5.23 Mode Change Request/Response

   Changes the current system state.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eMode = Defined by mode_enum_type in QLib_Defines.h
   \code
        MODE_OFFLINE_A_F = 0,    //!<' Go to offline analog
        MODE_OFFLINE_D_F = 1,    //!<' Go to offline digital
        MODE_RESET_F = 2,        //!<' Reset. Only exit from offline
        MODE_FTM_F = 3,          //!<' FTM mode
        MODE_ONLINE_F = 4,       //!<' Go to Online
        MODE_LPM_F = 5,          //!<' Low Power Mode (if supported)
        MODE_POWER_OFF_F = 6,    //!<' Power off (if supported)
        MODE_MAX_F = 7           //!<' Last (and invalid) mode enum value

   \endcode

   \return Returns true if the phone mode change executed correctly,
   see below warning for the return value for certain phone modes.

   \warning,  If the new mode is one of the following modes:
      MODE_FTM_F,
      MODE_ONLINE_F,
      MODE_OFFLINE_A_F,
      MODE_OFFLINE_D_F,
   the following actions will be performed after the command is successfully sent to the mobile.

   1. if the delay of the following types (associated with the desired eMode) has a value greater than 0,
      QMSL_Timeout_Delay_ONLINE_FTM
      QMSL_Timeout_Delay_ONLINE
      QMSL_Timeout_Delay_OFFLINE
   the delay for the desired mode will be issued.

   2. if the FTM command code is FTM_COMMAND_75:
   QLIB_GetPhoneOperatingMode() will be called to read the phone mode back.
   If the mode doesn't match with the desired mode, a 100 ms delay will be issued,
   and the status polling will continue until the mode matches,
   or the QMSL_Timeout_Runtime_Mode_Switching timer expires.

   the return value will be true only if the phone mode read back matches with the desired
   phone mode within the timeout of QMSL_Timeout_Runtime_Mode_Switching

   if the FTM command code is FTM_COMMAND_59:
   an extra fixed delay of QMSL_Timeout_Runtime_Mode_Switching will be issued( if it has a value greater than 0).
   the phone mode will not be read back, thus the return value will not be updated based on mode matching.

   The delay and timeout can be controled by QLIB_ConfigureTimeOut() and read by QLIB_GetTimeOut()
   with coresponding timeout ID.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_CONTROL_F(HANDLE hResourceContext, int eMode );


   /******************************************************************************/
   /**

   DMSS ICD, 3.4.35 Nonvolatile Item Read Request/Response
   WCDMA Diagnostic ICD, 3.5.23 Mode Change Request/Response

   Read an NV Item


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  item_id   = Enumeration ID of NV Item
   \param  pItemData = Reference to storage area for data
   \param   iLength   = size of data, in bytes
   \param  iStatus   = Reference to storage area for status
   \code
     NV_DONE_S = 0,      // Request completed okay
     NV_BUSY_S = 1,      // Request is queued
     NV_BADCMD_S = 2,    // Unrecognizable command field
     NV_FULL_S = 3,      // The NVM is full
     NV_FAIL_S = 4,      // Command failed, reason other than NVM was full
     NV_NOTACTIVE_S = 5, // Variable was not active
     NV_BADPARM_S = 6,   // Bad parameter in command block
     NV_READONLY_S = 7,  // Parameter is write-protected and thus read only
     NV_BADTG_S = 8,     // Item not valid for Target
     NV_NOMEM_S = 9,     // free memory exhausted
     NV_NOTALLOC_S = 10  // address is not a valid allocation

   \endcode

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_DIAG_NV_READ_F
   (HANDLE hResourceContext, unsigned short iItemID, unsigned char* pItemData, int iLength, unsigned short* iStatus);

   /******************************************************************************/
   /**

   DMSS ICD, 3.4.35 Nonvolatile Item Read Request/Response
   WCDMA Diagnostic ICD, 3.5.23 Mode Change Request/Response

   Read an NV Item for Dual SIM devices

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  item_id   = Enumeration ID of NV Item
   \param  pItemData = Reference to storage area for data
   \param  iContextID = ID of SIM index NV Item pertains to ( 0 or 1)
   \param   iLength   = size of data, in bytes
   \param  iStatus   = Reference to storage area for status
   \code
     NV_DONE_S = 0,      // Request completed okay
     NV_BUSY_S = 1,      // Request is queued
     NV_BADCMD_S = 2,    // Unrecognizable command field
     NV_FULL_S = 3,      // The NVM is full
     NV_FAIL_S = 4,      // Command failed, reason other than NVM was full
     NV_NOTACTIVE_S = 5, // Variable was not active
     NV_BADPARM_S = 6,   // Bad parameter in command block
     NV_READONLY_S = 7,  // Parameter is write-protected and thus read only
     NV_BADTG_S = 8,     // Item not valid for Target
     NV_NOMEM_S = 9,     // free memory exhausted
     NV_NOTALLOC_S = 10  // address is not a valid allocation

   \endcode

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_DIAG_NV_READ_EXT_F
   (HANDLE hResourceContext, unsigned short iItemID, unsigned char* pItemData, unsigned short iContextID, int iLength, unsigned short* iStatus);

   /******************************************************************************/
   /**

   DMSS ICD, 3.4.35 Nonvolatile Item Read Request/Response
   WCDMA Diagnostic ICD, 3.5.23 Mode Change Request/Response

   Read an NV Item--this version handles NV array items


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  item_id   = Enumeration ID of NV Item
   \param   iArrayIndex =  Index within NV array
   \param  pItemData = Reference to storage area for data
   \param   iLength   = size of data, in bytes
   \param  iStatus   = Reference to storage area for status
   \code
     NV_DONE_S = 0,      // Request completed okay
     NV_BUSY_S = 1,      // Request is queued
     NV_BADCMD_S = 2,    // Unrecognizable command field
     NV_FULL_S = 3,      // The NVM is full
     NV_FAIL_S = 4,      // Command failed, reason other than NVM was full
     NV_NOTACTIVE_S = 5, // Variable was not active
     NV_BADPARM_S = 6,   // Bad parameter in command block
     NV_READONLY_S = 7,  // Parameter is write-protected and thus read only
     NV_BADTG_S = 8,     // Item not valid for Target
     NV_NOMEM_S = 9,     // free memory exhausted
     NV_NOTALLOC_S = 10  // address is not a valid allocation

   \endcode

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_DIAG_NV_READ_ARRAY_F
   (HANDLE hResourceContext, unsigned short iItemID, unsigned char iArrayIndex, unsigned char* pItemData, int iLength, unsigned short* iStatus);

   /******************************************************************************/
   /**

   DMSS ICD, 3.4.36 Nonvolatile Item Write Request/Response
   WCDMA Diagnostic ICD, 3.5.22 Nonvolatile Item Write Request/Response

   Write an NV Item


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iItemID  = ID of NV Item
   \param  pItemData = Reference to storage area for data
   \param   iLength = size of data, in bytes
   \param  iStatus = Reference to storage area for status
   \code
     NV_DONE_S = 0,      // Request completed okay
     NV_BUSY_S = 1,      // Request is queued
     NV_BADCMD_S = 2,    // Unrecognizable command field
     NV_FULL_S = 3,      // The NVM is full
     NV_FAIL_S = 4,      // Command failed, reason other than NVM was full
     NV_NOTACTIVE_S = 5, // Variable was not active
     NV_BADPARM_S = 6,   // Bad parameter in command block
     NV_READONLY_S = 7,  // Parameter is write-protected and thus read only
     NV_BADTG_S = 8,     // Item not valid for Target
     NV_NOMEM_S = 9,     // free memory exhausted
     NV_NOTALLOC_S = 10  // address is not a valid allocation

   \endcode

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_DIAG_NV_WRITE_F
   (HANDLE hResourceContext, unsigned short iItemID, unsigned char* pItemData, int iLength, unsigned short* iStatus);

   /******************************************************************************/
   /**

   DMSS ICD, 3.4.36 Nonvolatile Item Write Request/Response
   WCDMA Diagnostic ICD, 3.5.22 Nonvolatile Item Write Request/Response

   Write an NV Item for Dual DIM devices


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iItemID  = ID of NV Item
   \param  pItemData = Reference to storage area for data
   \param  iContextID = ID of SIM index NV Item pertains to ( 0 or 1)
   \param   iLength = size of data, in bytes
   \param  iStatus = Reference to storage area for status
   \code
     NV_DONE_S = 0,      // Request completed okay
     NV_BUSY_S = 1,      // Request is queued
     NV_BADCMD_S = 2,    // Unrecognizable command field
     NV_FULL_S = 3,      // The NVM is full
     NV_FAIL_S = 4,      // Command failed, reason other than NVM was full
     NV_NOTACTIVE_S = 5, // Variable was not active
     NV_BADPARM_S = 6,   // Bad parameter in command block
     NV_READONLY_S = 7,  // Parameter is write-protected and thus read only
     NV_BADTG_S = 8,     // Item not valid for Target
     NV_NOMEM_S = 9,     // free memory exhausted
     NV_NOTALLOC_S = 10  // address is not a valid allocation

   \endcode

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_DIAG_NV_WRITE_EXT_F
   (HANDLE hResourceContext, unsigned short iItemID, unsigned char* pItemData, unsigned short iContextID, int iLength, unsigned short* iStatus);

   /******************************************************************************/
   /**

   DMSS ICD, 3.4.36 Nonvolatile Item Write Request/Response
   WCDMA Diagnostic ICD, 3.5.22 Nonvolatile Item Write Request/Response

   Write an NV Item--this version handles NV array items

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iItemID  = ID of NV Item
   \param   iArrayIndex =  Index within NV array
   \param  pItemData = Reference to storage area for data
   \param   iLength = size of data, in bytes
   \param  iStatus = Reference to storage area for status
   \code
     NV_DONE_S = 0,      // Request completed okay
     NV_BUSY_S = 1,      // Request is queued
     NV_BADCMD_S = 2,    // Unrecognizable command field
     NV_FULL_S = 3,      // The NVM is full
     NV_FAIL_S = 4,      // Command failed, reason other than NVM was full
     NV_NOTACTIVE_S = 5, // Variable was not active
     NV_BADPARM_S = 6,   // Bad parameter in command block
     NV_READONLY_S = 7,  // Parameter is write-protected and thus read only
     NV_BADTG_S = 8,     // Item not valid for Target
     NV_NOMEM_S = 9,     // free memory exhausted
     NV_NOTALLOC_S = 10  // address is not a valid allocation

   \endcode

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_DIAG_NV_WRITE_ARRAY_F
   (HANDLE hResourceContext, unsigned short iItemID, unsigned char iArrayIndex,
    unsigned char* pItemData, int iLength, unsigned short* iStatus);

   /******************************************************************************/
   /**

   Activates a batch mode for performing NV Write operations.  In this
   mode each call to QLIB_DIAG_NV_WRITE_F and QLIB_DIAG_NV_WRITE_ARRAY_F will be
   queued in the PC's RAM and will not be written immediately to the phone.  This is
   done in order to take advantage of the multiple-NV write operation, which will
   be invoked when the DIAG_NV_WRITE_FlushBatchQueue() command is called.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bStartBatchMode = true to activate NV Write batch mode, false to stop it.

   \return true if successful, false if fail.

   \warning After this function is completed, the batch mode will be disabled, and must be
            restarted with a call to DIAG_NV_WRITE_SetBatchMode.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_NV_WRITE_SetBatchMode( HANDLE hResourceContext, unsigned char bStartBatchMode );

   /******************************************************************************/
   /**

   Allows the user to specify a list of NV items that can be read-only.  When
   the batch queue is flushed, if these NV items fail because the field is
   read-only, then the command will not fail.

   An example of a field that can be read-only is #571, NV_RF_CAL_DATE_I

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param aiNvIdList = Array of NV Item ID numbers.

   \param iListSize = number of items in the NV Item ID list.

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_NV_WRITE_BatchQueue_SetRO_List(
      HANDLE hResourceContext,
      unsigned short* aiNvIdList,
      unsigned short iListSize);

   /******************************************************************************/
   /**

   Flushes all NV write requests that have been queued since the last time that
   QLIB_DIAG_NV_WRITE_SetBatchMode().  Uses the multiple NV Write operation to optimize
   the NV write time.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piLastErrorNvId = the ID of the last NV item that had an error.  If no error,
                         then it will be a value of NV_WRITE_BATCH_ITEM_NO_ERROR, -1

   \param piLastTotalStatus = return value of the entire write operation, refer to MNVW_Status_Enum
   \param piLastItemStatus = last NV_WRITE status, refer to nv_stat_enum_type

   \return true if successful, false if fail.

   \warning Will reset any open batch session.  If items has been queued up, they
            must be written using the QLIB_DIAG_NV_WRITE_FlushBatchQueue().

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_NV_WRITE_FlushBatchQueue(
      HANDLE hResourceContext, unsigned short* piLastErrorNvId,
      unsigned short* piLastTotalStatus, unsigned char* piLastItemStatus  );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.29 Handset Emulation Keypress Request/Response
   WCDMA Diagnostic ICD, 3.5.18 Handset Emulation Keypress Request/Response

   Emulate a key press


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iKey = ID of Key.  Lookup in QLib_Defines.h
   \param  iHold = Key release indicator
   \code
      0 = Selected keypress will be emulated,
          then a key release will be emulated

      1 = Selected keypress will be emulated,
          but no key release will be emulated;
          this is used to simulate the effect of
          holding down a key, such as CLEAR
          or END; you should send a second message

   \endcode

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_DIAG_HS_KEY_F(HANDLE hResourceContext, int iKey, unsigned char iHold);


   /******************************************************************************/
   /**
   DMSS ICD, 3.4.1 Version Number Request/Response
   WCDMA Diagnostic ICD, 3.5.15 Diag version request/response

   Return software version information

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param comp_date[ 11] = Compile date Jun 11 1991
      \param comp_time[ 8 ] = Compile time hh:mm:ss
      \param rel_date [ 11] = Release date
      \param rel_time [ 8 ] = Release time
      \param ver_dir  [ 8 ] = Version directory
      \param scm =  Station Class Mark
      \param mob_cai_rev = CAI rev
      \param mob_model = Mobile Model
      \param mob_firm_rev = Firmware Rev
      \param slot_cycle_index = Slot Cycle Index
      \param voc_maj = Vocoder major version
      \param voc_min = Vocoder minor version

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_DIAG_VERNO_F(
      HANDLE hResourceContext,
      char comp_date[ 11 ],
      char comp_time[ 8 ],
      char rel_date [ 11 ],
      char rel_time [ 8 ],
      char ver_dir  [ 8 ],
      unsigned char* scm,
      unsigned char* mob_cai_rev,
      unsigned char* mob_model,
      unsigned short* mob_firm_rev,
      unsigned char* slot_cycle_index,
      unsigned char* voc_maj,
      unsigned char* voc_min
   );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.3 Memory Peek Request/Response  (8-bit version)
   WCDMA Diagnostic ICD, 3.5.1 Memory peek request/response

   When the DM sends a Memory Peek Request Message to the DMSS, the DMSS responds with a
   Memory Peek Response Message that contains the contents of a block of memory starting at the
   given ADDRESS and consisting of LENGTH items.

   The request may ask for up to 16 BYTES.

   The ADDRESS is specified as a 32-bit flat address.

   This packet is protected by the DMSS Security Plan. The Security Passunsigned short Request Message
   must be sent to the DMSS successfully before this message will be accepted.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iAddress = Address of peek region start; given as a flat address
   \param   iNumItems = number of items to read, must be <= 16 bytes (16 8-bit items)
   \param  pArray = array of items in which data will be stored.  Size must be at least
                        "<iNumItems> * data size" bytes long
                   For 8-bit items, this is <iNumItems> * 1 (bytes)

   \return true if successful, false if fail.

   \warning None

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_MEMORY_PEEK_F(
      HANDLE hResourceContext, unsigned long iAddress, unsigned short iNumItems, unsigned char* pItemArray );


   /******************************************************************************/
   /**
   DMSS ICD, 3.4.3 Memory Peek Request/Response (16-bit version)
   WCDMA Diagnostic ICD, 3.5.1 Memory peek request/response

   When the DM sends a Memory Peek Request Message to the DMSS, the DMSS responds with a
   Memory Peek Response Message that contains the contents of a block of memory starting at the
   given ADDRESS and consisting of LENGTH items.

   The request may ask for up to 8 16-bit values.

   The ADDRESS is specified as a 32-bit flat address.

   This packet is protected by the DMSS Security Plan. The Security Passunsigned short Request Message
   must be sent to the DMSS successfully before this message will be accepted.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iAddress = Address of peek region start; given as a flat address
   \param   iNumItems = number of items to read, must be <= 16 bytes (8 16-bit items)
   \param  pArray = array of items in which data will be stored.  Size must be at least
                        "<iNumItems> * data size" bytes long
                   For 16-bit items, this is <iNumItems> * 2 (bytes)

   \return true if successful, false if fail.

   \warning !!! The ICD reports 16-bytes available for transfer, but the source code limits the size to 4 bytes.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_MEMORY_PEEK_WORD_F(
      HANDLE hResourceContext, unsigned long iAddress, unsigned short iNumItems, unsigned short* pItemArray );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.3 Memory Peek Request/Response (32-bit version)
   WCDMA Diagnostic ICD, 3.5.1 Memory peek request/response

   When the DM sends a Memory Peek Request Message to the DMSS, the DMSS responds with a
   Memory Peek Response Message that contains the contents of a block of memory starting at the
   given ADDRESS and consisting of LENGTH items.

   The request may ask for up to 4 16-bit values.

   The ADDRESS is specified as a 32-bit flat address.

   This packet is protected by the DMSS Security Plan. The Security Passunsigned short Request Message
   must be sent to the DMSS successfully before this message will be accepted.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iAddress = Address of peek region start; given as a flat address
   \param   iNumItems = number of items to read, must be <= 16 bytes (4 32-bit items)
   \param  pArray = array of items in which data will be stored.  Size must be at least
                        "<iNumItems> * data size" bytes long
                   For 32-bit items, this is <iNumItems> * 4 (bytes)

   \return true if successful, false if fail.

   \warning !!! The ICD reports 16-bytes available for transfer, but the source code limits the size to 8 bytes.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_MEMORY_PEEK_DWORD_F(
      HANDLE hResourceContext, unsigned long iAddress, unsigned short iNumItems, unsigned long* pItemArray );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.4 Memory Poke Request/Response  (16-bit version)
   WCDMA Diagnostic ICD, 3.5.2 Memory poke request/response

   When the DM sends a Memory Poke Request Message to the DMSS, the DMSS writes the
   data provided into its memory and responds with a Memory Poke Response Message. The
   poke request may request up to 16 BYTES. The response to a correctly formatted Memory Poke Request
   is a copy of the request.

   This packet is protected by the DMSS Security Plan. The Security Passunsigned short Request Message
   must be successfully sent to the DMSS before this message will be accepted.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iAddress = Address of peek region start; given as a flat address
   \param   iNumItems = number of items to read, must be <= 16 bytes (16 8-bit items)
   \param  pArray = array of items in which data will be stored.  Size must be at least
                        "<iNumItems> * data size" bytes long
                   For 8-bit items, this is <iNumItems> * 1 (bytes)
                        The size of this array must be at least <iNumBytes> long

   \return true if successful, false if fail.

   \warning !!! The ICD reports 16-bytes available for transfer, but the source code limits the size to 4 bytes.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_MEMORY_POKE_F(
      HANDLE hResourceContext, unsigned long iAddress, unsigned short iNumItems, unsigned char* pItemArray );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.4 Memory Poke Request/Response  (16-bit version)
   WCDMA Diagnostic ICD, 3.5.2 Memory poke request/response

   When the DM sends a Memory Poke Request Message to the DMSS, the DMSS writes the
   data provided into its memory and responds with a Memory Poke Response Message. The
   poke request may request up to 8 16-bit numbers. The response to a correctly formatted
   Memory Poke Request is a copy of the request.

   This packet is protected by the DMSS Security Plan. The Security Passunsigned short Request Message
   must be successfully sent to the DMSS before this message will be accepted.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iAddress = Address of peek region start; given as a flat address
   \param   iNumItems = number of items to read, must be <= 16 bytes (8 16-bit items)
   \param  pArray = array of items in which data will be stored.  Size must be at least
                        "<iNumItems> * data size" bytes long
                   For 16-bit items, this is <iNumItems> * 2 (bytes)
                        The size of this array must be at least <iNumBytes> long

   \warning !!! The ICD reports 16-bytes available for transfer, but the source code limits the size to 4 bytes.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_MEMORY_POKE_WORD_F(
      HANDLE hResourceContext, unsigned long iAddress, unsigned short iNumItems, unsigned short* pItemArray );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.4 Memory Poke Request/Response (32-bit version)
   WCDMA Diagnostic ICD, 3.5.2 Memory poke request/response

   When the DM sends a Memory Poke Request Message to the DMSS, the DMSS writes the
   data provided into its memory and responds with a Memory Poke Response Message. The
   poke request may request up to 4 32-bit numbers. The response to a correctly formatted
   Memory Poke Request is a copy of the request.

   This packet is protected by the DMSS Security Plan. The Security Passunsigned short Request Message
   must be successfully sent to the DMSS before this message will be accepted.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iAddress = Address of peek region start; given as a flat address
   \param   iNumItems = number of items to read, must be <= 16 bytes (4 32-bit items)
   \param  pArray = array of items in which data will be stored.  Size must be at least
                        "<iNumItems> * data size" bytes long
                   For 32-bit items, this is <iNumItems> * 4 (bytes)
                        The size of this array must be at least <iNumBytes> long

   \warning !!! The ICD reports 16-bytes available for transfer, but the source code limits the size to 8 bytes.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_MEMORY_POKE_DWORD_F(
      HANDLE hResourceContext, unsigned long iAddress, unsigned short iNumItems, unsigned long* pItemArray );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.63 Service Programming Code Request/Response
   WCDMA Diagnostic ICD, 3.5.29.3 Service Programming Code Request Message

   Sends the service programming code (SPC) to the phone.

   The SPC is a 6 digit number, which can enable certain operations, according to
   the DMSS Security Plan.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iSPC = array of 6 bytes, which hold the service programming code
               6 bytes of security code, in ASCII format (digits 0..9 only)
   \param   piSPC_Result = Result of the SPC
      \code
         1 = code was correct and Service Programming (SP) is unlocked
         0 = code was incorrect and SP is still locked
      \endcode

   \return true if successful, false if fail.

   \warning if the code was incorrect, the phone will time out for 10 sec
      before responding to any more requests through the serial interface.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SPC_F(
      HANDLE hResourceContext, unsigned char iSPC[6], unsigned char* piSPC_Result );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.124.2 Extended Build ID Response Message

   This packet is an extension to the Version Number Request/Response packet (CMD_CODE 0)

   \param piMSM_HW_Version = MSM version.  This is an extension of the MSM_VER
                            field from the Version Number Request/Response packet (DIAG_VER_NO_F)
   \param piMobModel = Manufacturer's mobile model number.  This is an extension of
                      MOB_MODEL field from the Version Number Request/Response packet

   \param sMobSwRev = Mobile software revision string. This string is a NULL-terminated
                      ASCII string. If string is nonexistent, a NULL char indicates an
                  empty string. This field is an extension of the VER_DIR field
                  from the Version Number Request/Response packet

                      NOTE: Enough memory must be available at this pointer location
                  to store the entire string.  Recommend a buffer of 512 bytes.

   \param sModelStr = Mobile model string.  This string is an ASCII NULL-terminated string.
                      If string is nonexistent, a NULL char indicates an empty string.

                       NOTE: Enough memory must be available at this pointer location
                  to store the entire string.  Recommend a buffer of 512 bytes.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_EXT_BUILD_ID_F
   ( HANDLE hResourceContext, unsigned long* piMSM_HW_Version, unsigned long* piMobModel,
     char* sMobSwRev, char* sModelStr );

   /******************************************************************************/
   /**
   DMSS ICD, 3.4.9 Status Request/response Message

   The Status Request Message asks for current DMSS status information.
   This information is returned in the Status Response Message.

   \param ESN = Electronic serial number. See IS-95-A 2.3.2 or J-STD-008 2.3.2.
   \param RF_mode
      \code
         Current mode of the RF hardware
         0 = Analog
         1 = CDMA cellular
         2 = CDMA PCS
         3 = Sleep mode
         4 = GPS
         5 = HDR
      \endcode
   \param MIN1_Analog = Analog MIN1 for the current NAM (valid only for analog
                         capability phones)
   \param MIN1_CDMA = CDMA MIN1 for the current NAM.
                       For IS-95-A compliance, these are set to the same value.
                       See IS-95-A 2.3.1 or J-STD-008 6.3.1. (MIN1 is equivalent
                       to IMSI_S1.)
   \param MIN2_Analog = Analog MIN2 for the current NAM (valid only for analog
                         capability phones)
   \param MIN2_CDMA = CDMA MIN2 for the current NAM
                         For IS-95-A compliance, these are set to the same value.
                         See IS-95-A 2.3.1, or J-STD-008 6.3.1. (MIN2 is equivalent
                         to IMSI_S2.)
   \param CDMA_RX_State = Current CDMA RX process state
      \code
           - 0 = Entering CDMA state
           - 1 = Sync channel state
           - 2 = Paging channel state
           - 3 = Traffic channel initialization state
           - 4 = Traffic channel state
           - 5 = Exit state
      \endcode
   \param CDMA_Good_Frames = Valid only for Sync and Paging Channel States
      \code
           1 = Good frames received since the last status request
           0 = Five or more bad frames and no good frames
               received since the last status request
           -1 = Unknown - no good or bad frames received for two
                or more status requests
      \endcode
   \param Analog_Bad_Frames = Count of bad frames (Analog only); saturates at 65535
                               This item is only valid for analog capability phones.
   \param Analog_Word_Syncs = Number of word sync sequences received in analog control
                               or voice channel modes; saturates at 65535
                               See IS-95-A 3.7.1.
                               This item is only valid for analog capability phones.
   \param Entry_Reason = Reason call processing entered
                          Use the field RF_MODE to determine which interpretation
                          of the following values to use.
                          CDMA mode (Cellular and PCS)
      \code
           0 = Normal CDMA operation
           1 = Continue previous operation
           2 = Enter offline CDMA mode
           3 = Originate call in CDMA mode

           Analog Mode
           0 = Normal analog operation
           1 = Digital-to-analog handoff
           2 = Originate call in Analog mode
           3 = Page response
           4 = Voice channel assignment
           5 = Continue previous operation
           6 = Enter offline Analog mode
      \endcode
   \param Current_Chan = Current center frequency channel for Analog or CDMA
   \param CDMA_Code_Chan = CDMA code channel (CDMA only).
                            This is invalid after any Handoff Direction Message on the
                            Traffic Channel. See IS-95-A 7.1.3.1 or J-STD-008 3.1.3
   \param Pilot_Base = Pilot PN of current cell (CDMA only)
                        See IS-95-A 7.1.3.2 or J-STD-008 3.1.3.2.
   \param SID = Current system ID
                 See IS-95-A 7.7.1.3 or J-STD-008 3.7.1.3.
   \param NID = Current network ID
                 See IS-95-A 7.7.1.3 or J-STD-008 3.7.1.3.
   \param LocaID = Current location area ID (Analog only)
                    This item is only valid for analog capability phones. See
                    IS-95-A 2.3.4.2.
   \param RSSI = Current RSSI (RF signal strength) level for analog
                  To convert to dBm/30 KHz, use -110 + (RSSI * 62/255). This
                  value is a rather rough estimate. This item is only valid for
                  analog capability phones.
   \param Power = Current mobile output power level index for analog
                  This item is only valid for analog capability phones. See
                  IS-95-A Table 2.1.2-1.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_STATUS_REQUEST_F( HANDLE hResourceContext,
         unsigned long* ESN,
         unsigned short *RF_mode,
         unsigned long *MIN1_Analog,
         unsigned long *MIN1_CDMA,
         unsigned short *MIN2_Analog,
         unsigned short *MIN2_CDMA,
         unsigned short *CDMA_RX_State,
         unsigned char *CDMA_Good_Frames,
         unsigned short *Analog_Bad_Frames,
         unsigned short *Analog_Word_Syncs,
         unsigned short *Entry_Reason,
         unsigned short *Current_Chan,
         unsigned char *CDMA_Code_Chan,
         unsigned short *Pilot_Base,
         unsigned short *SID,
         unsigned short *NID,
         unsigned short *LocaID,
         unsigned short *RSSI,
         unsigned char *Power
                                                    );

   /******************************************************************************/
   /**
   WCDMA ICD, 3.4.9 Status request message (cmd_code 14 of the WCDMA subsystem)

   Returns the phone status--offline, online, other

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piTMC_State = Return value of TMC state:
      \code
        0  = DIAG_STATUS_OFFLINE =  Offline
        1  = DIAG_STATUS_ONLINE  =  Online
        2  = DIAG_STATUS_LPM     =  Low power mode
        99 = DIAG_STATUS_UNKNOWN =  Unknown state
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_STATUS_F( HANDLE hResourceContext, unsigned char* piTMC_State );

   /******************************************************************************/
   /**
   WDMSS ICD, 3.5.24 Error Record Retrieval Request/Response
   CDMA ICD, 3.4.39 Error Record Retrieval Request/Response

   When the DMSS software encounters an error condition, it stores an error record in its
   nonvolatile memory. An error is defined uniquely by its source file and line number. Another
   invocation of an error that has already been recorded does not allocate another error record, it
   increments the count for the existing error. There are dozens of potential errors in the DMSS
   code, however, there is room in NV for 20 different error records, each of which includes the
   number of times the error has occurred, the source file and line of the location of the software
   reporting the error, and whether the error was fatal. Fatal errors cause the DMSS to reset,
   nonfatal errors do not.
   The error number (0 to 19) does not indicate anything about the errors other than the order in
   which they were recorded. It is just a 20-position array, and as a new error needs to be
   recorded, a new error record is used to record it.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pErrorRead = Pointer to a structure (QLIB_DIAG_Err_Read) that will hold the error
                       read results.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ERR_READ_F( HANDLE hResourceContext, unsigned char *pErrorRead );

   /******************************************************************************/
   /**
   WDMSS ICD, 3.5.25 Error Record Clear Request/Response
   CDMA ICD, 3.4.40.1 Error Record Clear Request Message

   The accumulated error statistics in the DMSS can be cleared by sending an Error Record Clear
   Request Message. A single error record (identified by index, 0 to 19) or all error records
   (identified by index -1) may be cleared with a single Error Record Clear Request Message. After
   clearing the specified error record, the DMSS shall send an Error Record Clear Response
   Message to the DM.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorRec = Index of error record to be cleared.  If ERROR_REC is -1 (0xFF), the DMSS
                      shall clear all error records. If iErrorRec is between 0 and 19 inclusive,
                  the DMSS shall clear the error record specified by iErrorRec.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ERR_CLEAR_F( HANDLE hResourceContext, unsigned char iErrorRec );

   /******************************************************************************/
   /**
   Sirius custom diag command

   Sends the trigger for the security freeze step to be executed on the mobile

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SECURITY_FREEZE_F( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   CDMA ICD, 3.4.56 Switch to Downloader Request/Response
   WCDMA ICD, 3.5.29 Switch to Downloader Request/Response

   Sending a Switch to Downloader Request Message will cause a jump to the resident
   downloader. In response, the phone sends a Switch to Downloader Response Message before
   it jumps to the resident downloader. The DMSS must be in an offline state in order to accept
   this command.

    \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning After this command is sent, the phone will respond only to download protocol commands

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_DLOAD_F( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Start CNV backup

   If the CNV backup has been triggered by a DIAG command, the response to the DIAG
   command will tell the PC if the backup was successful or not (If it's SWUOTA
   triggered F3 messages are all that can give status of CNV backup).
   There are 2 responses to the DIAG command, first reports on the status if the
   command has been successfully queued in CNV, and the second response reports on
   the status of the backup.

   NV_CNV_DIAG_BACKUP: Command sent from the DM to the DMSS to backup the NV data to CNV.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_NV_CNV_DIAG_BACKUP_F( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   CDMA ICD, 3.4.44 DIP Switch Retrieval Request/Response

   The DM requests the software DIP switch settings by sending a DIP Switch Retrieval Request
   Message to the DMSS. The DMSS responds by sending a DIP Switch Retrieval Response
   Message to the DM that contains the current setting of the software switches. Each bit is the
   value of a single switch. The DIP switches are not true DIP switches but software-only, and
   they reset upon power cycle.

   DIP switches are highly hardware dependent and their meanings are volatile; any permanent
   configuration options will be given NV items or DIAG packets.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piSwitchValues = 16-bit bit mask of switch values

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GET_DIPSW_F( HANDLE hResourceContext, unsigned short* piSwitchValues );

   /******************************************************************************/
   /**
   CDMA ICD, 3.4.45 DIP Switch Set Request/Response

   The DM changes the value of one or more of the software DIP switches by sending a DIP
   Switch Set Request Message. The DMSS responds by setting the value of the switch word to
   the value given in the DIP Switch Set Request Message, and sending a DIP Switch Set
   Response Message in return. Note that all the switches are set at once, so it is necessary to read
   the current switch settings and return the current values of all the switches that are not being
   changed.

   DIP switches are highly hardware dependent and their meanings are volatile; any permanent
   configuration switches options will be given NV items or DIAG packets.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSwitchValues = 16-bit bit mask of switch values

   \return true if successful, false if fail.

   \warning None.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SET_DIPSW_F( HANDLE hResourceContext, unsigned short iSwitchValues );

   /******************************************************************************/
   /**

   Function:  DownloadPRL

   Description:  Copy PRL from phone to PC

   See Command 73 (0x49) in 80-V1294-1

   Parameter(s):
      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iNAM_Index = NAM index for the PRL
      \param sPRL_Path = path of PRL file

      \return true if successful, false if failure

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DownloadPRL( HANDLE hResourceContext, short iNAM_Index, char* sPRL_Path );

   /******************************************************************************/
   /**

   Function:  UploadPRL

   Description:  Copy PRL from PC to phone

   See Command 72 (0x48) in 80-V1294-1

   Parameter(s):
      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iNAM_Index = NAM index for the PRL
      \param sPRL_Path = path of PRL file

      \return true if successful, false if failure

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_UploadPRL( HANDLE hResourceContext, short iNAM_Index, char* sPRL_Path );

      /******************************************************************************
                     Phone async Logging
   *******************************************************************************/

   /******************************************************************************/
   /**

      Set phone logging on or off

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param bEnableLogging = true to enable logging, false to disable

      \return true if call succeeds, false if it fails

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetPhoneLoggingState( HANDLE hResourceContext, unsigned char bEnableLogging );


   /******************************************************************************/
   /**

   Waits a specified amount of time for a phone log message and returns the contents to the user.
   NOTE: phone log is different from "text" logs

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param piLogSize = Pointer to number of bytes received in the log message
      \param piLogBytes = Pointer to a buffer to store the log message.
      \param iTimeout = millisecond time out

   \return Returns true if a valid log message was found within the specified time-out.\

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GetNextPhoneLog
   (
      HANDLE hResourceContext,
      unsigned short* piLogSize,
      unsigned char* piLogBytes,
      unsigned long iTimeOut
   );

   /******************************************************************************/
   /**
     Searches the async queue for a specific exnteded debug message (text message)
     and returns whether the message is found + the parameters of the message.

     Extended messages are response message #121, documented in the CDMA and WCDMA
     ICD's.  They operate like a printf statement with text format string and 4
     32-bit integer arguments.

     Example:
       string = "CEFS extraction completed with status %d"
      arg1 = 1 or 0
      arg2 = 0 always
      arg3 = 0 always
      arg4 = 0 always

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param sSearch string = NULL terminated 8-bit ASCII string to search for

      \param pbFoundMessage = output, true if the text message was found.
      \param piArg1 = output, value of the ARGS_1 field
      \param piArg2 = output, value of the ARGS_2 field
      \param piArg3 = output, value of the ARGS_3 field

   \return true if all commands are successful

   \warning The async queue be cleared as messages are searched for.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_FindDebugMessage
   (
      HANDLE hResourceContext,
      char* sSearchString,
      unsigned char* pbFoundMessage,
      unsigned long* piArg1,
      unsigned long* piArg2,
      unsigned long* piArg3
   );

   /******************************************************************************/
   /**
      Clear log message queue

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if success, false if failed.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ClearPhoneLogQueue( HANDLE hResourceContext );

   /******************************************************************************/
   /**
      Returns the current size of the Phone Log queue

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param piLogQueueSize = Number of entries currently in the log queue

   \return Returns true if a valid log message was in the queue, false if not.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GetPhoneLogQueueSize( HANDLE hResourceContext, unsigned long* iLogQueueSize );

   /******************************************************************************/
   /**

      Sets the phone's log mask, based on an extended log code.  An extended
      log code is one which is a sub-group of an equipment ID.  This function will overwrite
      any existing log code mask that has been setup.

      For example, for "MMGPS report measurement (LOG_CODE 0x7005)"

      The equipment ID is 7 and the item ID is

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. UMTS is code 0x0007
      \param iLogCode = log code as defined by the ICD documents, e.g. MMGPS report measurement is 0x7005
      \param iLastItem = last possible item that can be logged for the given equipment ID

      \return true if call succeeds, false if it fails

      \warning None


   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetExtendedLogCode(
      HANDLE hResourceContext, unsigned char iEquipmentID, unsigned short iLogCode, unsigned short iLastItem );

   /******************************************************************************/
   /**

      Sets the phone's log mask, based on an extended log codes.  An extended
      log code is one which is a sub-group of an equipment ID.  This function will overwrite
      any existing log code mask that has been setup.

     This function works like QLIB_DIAG_AddExtendedLogCodes

     Unlike QLIB_DIAG_AddExtendedLogCodes, this function 
     
     1. will not query the device for the number of log bits supported by the equipment 
     2. will not combine the mobile's current log bit mask for the equipment

     This function can be used to optimize the performance of setting a log bit mask.

      For example, for "cdma2000 searcher finger status (0x119C)" and "cdma2000 RDA frame info (0x10D9)"
     
      The equipment ID is 1

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. cdma 1x equipment ID is 1
      \param aiLogCodeList = the list of log codes
      \param iLogCodeListSize = number of items in the aiLogCodeList

      \return true if call succeeds, false if it fails

      \warning None


   *******************************************************************************/

     QLIB_API unsigned char QLIB_DIAG_SetExtendedLogCodes(
      HANDLE hResourceContext,
      unsigned char iEquipmentID,
      unsigned short* aiLogCodeList,
      unsigned short iLogCodeListSize
   );

   /******************************************************************************/
   /**

      Sets the phone's log mask, based on an extended log code.  An extended
      log code is one which is a sub-group of an equipment ID.  This function will
      append the requested log code to the phone's exisiting log code mask.

      For example, for "MMGPS report measurement (LOG_CODE 0x7005)"

      The equipment ID is 7 and the item ID is

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. UMTS is code 0x0007
      \param iLogCode = log code as defined by the ICD documents, e.g. MMGPS report measurement is 0x7005

      \return true if call succeeds, false if it fails

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_AddExtendedLogCode(
      HANDLE hResourceContext, unsigned char iEquipmentID, unsigned short iLogCode );

   /******************************************************************************/
   /**

      Sets the phone's log mask, based on multiple user-provided log code.  An extended
      log code is one which is a sub-group of an equipment ID.  This function will
      append the requested log code to the phone's exisiting log code mask.

      For example, for "MMGPS report measurement (LOG_CODE 0x7005)"

      The equipment ID is 7 and the item ID is 0x7005

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. UMTS is code 0x0007
      \param aiLogCodeList = log code as defined by the ICD documents, e.g. MMGPS report measurement is 0x7005
      \param iLogCodeListSize = number of items in the aiLogCodeList

      \return true if call succeeds, false if it fails
      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_AddExtendedLogCodes(
      HANDLE hResourceContext,
      unsigned char iEquipmentID,
      unsigned short* aiLogCodeList,
      unsigned short iLogCodeListSize
   );

   /******************************************************************************/
   /**

      Clear the phone's log mask, based on an extended log code.  An extended
      log code is one which is a sub-group of an equipment ID.  This function will
      clear the requested log code from the phone's exisiting log code mask.

      For example, for "MMGPS report measurement (LOG_CODE 0x7005)"

      The equipment ID is 7 and the item ID is is 0x7005

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. UMTS is code 0x0007
      \param iLogCode = log code as defined by the ICD documents, e.g. MMGPS report measurement is 0x7005

      \return true if call succeeds, false if it fails

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ClearExtendedLogCode(
      HANDLE hResourceContext, unsigned char iEquipmentID, unsigned short iLogCode );

   /******************************************************************************/
   /**

      Clear the phone's log mask, based on multiple user-provided log code.  An extended
      log code is one which is a sub-group of an equipment ID.  This function will
      clear the requested log code from the phone's exisiting log code mask.

      For example, for "MMGPS report measurement (LOG_CODE 0x7005)"

      The equipment ID is 7 and the item ID is 0x7005

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. UMTS is code 0x0007
      \param aiLogCodeList = log code as defined by the ICD documents, e.g. MMGPS report measurement is 0x7005
      \param iLogCodeListSize = number of items in the aiLogCodeList

      \return true if call succeeds, false if it fails

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ClearExtendedLogCodes(
      HANDLE hResourceContext,
      unsigned char iEquipmentID,
      unsigned short* aiLogCodeList,
      unsigned short iLogCodeListSize
   );


   /******************************************************************************/
   /**

      Clear all log codes for a specific equipment ID.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. UMTS is code 0x0007

      \return true if call succeeds, false if it fails

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ClearAllLogCodes(
      HANDLE hResourceContext,
      unsigned char iEquipmentID
   );

   /******************************************************************************/
   /**

      Looks through the existing async queue for a specific log code.  If not found
      then waits (based on the timeout) for a specified log code to be captured.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. UMTS is code 0x0007
      \param iLogCode = log code as defined by the ICD documents, e.g. MMGPS report measurement is 0x7005
      \param iTimeOut_ms = millisecond timeout
      \param pLogData = pointer to a buffer that the log data will be copied into.  All data
                        received (except CRC) is copied into this buffer.
                    Size of each the storage buffer should be DIAG_MAX_PACKET_SIZE
      \param piLogSize = number of bytes stored in the log structure

      \return true if at least one log code was captured, false if no log was found

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GetSingleLog(
      HANDLE hResourceContext,
      unsigned char iEquipmentID,
      unsigned short iLogCode,
      unsigned long iTimeOut_ms,
      void* pLogData,
      unsigned short* aiLogDataSize
   );

   /******************************************************************************/
   /**

      Looks through the existing async queue for a specific log code.  If not found
      then waits (based on the timeout) for a specified log code to be captured.

      Will collect logs until iNumLogs has been captured or the timeout occurs

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEquipmentID = equipment id, as defined by the ICD documents, e.g. UMTS is code 0x0007
      \param iLogCode = log code as defined by the ICD documents, e.g. MMGPS report measurement is 0x7005
      \param piNumLogs = as an input, it is the number of logs to look for.  as an output
                         it is the number of logs that were actually found.

      \param iTimeOut_ms = millisecond timeout
      \param apLogData = array of pointers to buffers that the log data will be copied into.
                         All data received (except CRC) is copied into these buffer.
                     Size of array must be at least iNumLogs.

      \param aiLogDataSizes = output, the size of each log will be stored here

      \return true if at least one log code was captured, false if no log codes were found

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GetMultipleLogs(
      HANDLE hResourceContext,
      unsigned char iEquipmentID,
      unsigned short iLogCode,
      unsigned short* piNumLogs,
      unsigned long iTimeOut_ms,
      void* apLogData[],
      unsigned short aiLogDataSizes[]
   );

   /******************************************************************************/
   /**
      CDMA ICD, 3.4.94 Event Report Control Request/Response
      WCDMA ICD, 3.5.35 Event Report Control Request/Response

      When the DM sends an Event Report Control Request Message, the DMSS responds with an
      Event Report Control Response Message. This command is used to configure the service, as
      well as for the service to send information. See Section 3.4.95 for information on the Event
      Report Message.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param bOperationSwitch = Turn scheduling on or off: 0 = Off, 1 = On

      \return true if call succeeds, false if it fails

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_EventReportControl( HANDLE hResourceContext, unsigned char bOperationSwitch );

   /******************************************************************************/
   /**
      Sets or clears an individual bit in the Event Mask by calling QLIB_DIAG_SetEventMaskBits()

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iMaskID = bit position in the event mask, which will be turned on or off
      \param bMaskState = 0 = Off-Disabled, 1 = On-Enabled

      \return true if call succeeds, false if it fails

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetEventMaskBit(
      HANDLE hResourceContext,
      unsigned short iMaskID,
      unsigned char bMaskState);

   /******************************************************************************/
   /**
      Sets or clears the entire Event Mask.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param bMaskState = 0 = Off-Disable all events, 1 = On-Enable all events

      \return true if call succeeds, false if it fails

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetEntireEventMaskState(
      HANDLE hResourceContext,
      unsigned char bMaskState);

   /******************************************************************************/
   /**

   Returns the next event on the event queue.

   See QLIB_DIAG_GetEventQueueSize() for more information about the Event queue.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param pEvent = Pointer to a structure QMSL_Event_Element_Struct.

   \return Returns true if an event was in the queue, false if not.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GetNextEvent
   (
      HANDLE hResourceContext,
      void* pEvent
   );

   /******************************************************************************/
   /**

   Waits a specified amount of time for a phone event and returns the contents to the user.

   See QLIB_DIAG_GetEventQueueSize() for more information about the Event queue.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEventID = ID of event to look for.
                        For a wild card event ID, use QMSL_EVENT_ID_WILDCARD (0xFFFF)

                        For a full list of events, see the AMSS software header file,
                    services\diag\event_defs.h

                        While waiting for an event, any other events that are found and do
                    not match the iEventID criteria will be discarded, so it is important
                    to search for events in the correct order or to use the wildcard search
                    that will return each event as it is found.

                        This function must be called one time for each event that is of interest.


      \param pEvent = Pointer to a structure QMSL_Event_Element_Struct.
      \param iTimeout_ms = millisecond time out

   \return Returns true if a valid log message was found within the specified time-out.\

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_WaitForEvent
   (
      HANDLE hResourceContext,
      unsigned short iEventID,
      void* pEvent,
      unsigned long iTimeOut_ms
   );

   /******************************************************************************/
   /**
      Clear Event queue.

      See QLIB_DIAG_GetEventQueueSize() for more information about the Event queue.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if success, false if failed.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ClearEventQueue( HANDLE hResourceContext );

   /******************************************************************************/
   /**
      Returns the current size of the Event queue.  The an event queue element
      is added for each event received from the mobile phone.  One "event response" packet
      may contain multiple events packets.  QMSL will parse the "event response" packet
      and extract each event, then place each event into the queue.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param piEventQueueSize = Number of entries currently in the Event queue

   \return Returns true if a valid log message was in the queue, false if not.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GetEventQueueSize( HANDLE hResourceContext, unsigned long* piEventQueueSize );

   /******************************************************************************/
   /**
      Sets or clears multiple bits in the Event Mask by calling these functions:

      1) CDMA ICD, 3.4.129 Event Get Mask Request/Response
      2) CDMA ICD, 3.4.130 Event Set Mask Request/Response

      Get Mask:

      The Event Get Mask Request Message is sent by the DM to the DMSS to get the current event
      mask.
      Event Mask is a byte array where each bit denotes an event IDs configuration. A bit value of 1
      specifies that the item is enabled. A bit value of 0 specifies that the item is disabled. The Event
      mask representation is similar to the Log mask representation described in Section 3.4.115.
      EVENT_LAST_ID is the last event ID supported. The Event mask array is of size
      (EVENT_LAST_ID / 8 + 1).

      NOTE The first byte at index zero (i.e., left-most) in the event mask array is the least significant byte;
      last byte (i.e., right-most) is the most significant byte. Within a byte, the right-most bit is the
      least significant bit and the left-most bit is the most significant bit.

      Set Mask:
      The Event Set Mask Request Message is sent by the DM to the DMSS to set the event mask.
      NUM_BITS specifies the mask length of the user. If the number of bits specified in the set mask
      command is smaller than the total number of bits supported, then only the specified bits are set
      starting from the beginning; the remaining bits are not changed.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param aiMaskID_List = array of mask ID's, which are bit position in the event mask.
      \param iMaskID_ListSize = number of mask ID's in aiMaskID_List
      \param bMaskState = 0 = Off-Disabled, 1 = On-Enabled the corresponding bit in the event mask

      \return true if call succeeds, false if it fails

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetEventMaskBits(
      HANDLE hResourceContext,
      unsigned short* aiMaskID_List,
      unsigned char iMaskID_ListSize,
      unsigned char bMaskState);


   /******************************************************************************/
   /**

   Function to look up a string related to an event id

   \param iEventID is the event ID from the async event packet
   \param sBuffer = text buffer that will be filled out with the string label of the event
   upon the byte buffer. the maximum possible size is 256 characters.
   \return None
   *******************************************************************************/
   QLIB_API void QLIB_GetEventText( unsigned short iEventID, char* sBuffer );

   /******************************************************************************/
   /**
      3.5.45.2 Logging Configuration Response Message, CMD_CODE=115

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iOperation = OPERATION parameter of the 3.5.45.1 Logging Configuration
                          Request Message

      \param piOperationData = OPERATION_DATA parameter of the 3.5.45.1 Logging
                               Configuration Request Message

                               If the operation data is returned from the message, this buffer
                         will be overwritten

      \param piOperationDataSize = number of bytes to be sent in the piOperationData buffer

                               If the operation data is returned from the message, this number
                         will be updated with the size of the operation data buffer that was
                         returned.

      \param iStatus = STATUS returned in the 3.5.45.2 Logging Configuration
                       Response Message

   \return Returns true if a valid log message was found within the specified time-out.

      \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetExtendedLogMask( HANDLE hResourceContext, unsigned long iOperation, unsigned char* piOperationData,  unsigned short* piOperationDataSize);

   /******************************************************************************/
   /**
      WCDMA ICD, 3.5.17 Message Request/Response, CMD_CODE=31

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iMessageLevel= Minimum message severity level
      \code
           0000 = all messages (MSG_LVL_LOW)
           0001 = medium and above (MSG_LVL_MED)
           0002 = high and above (MSG_LVL_HIGH)
           0003 = error and above (MSG_LVL_ERROR)
           0004 = fatal error only (MSG_LVL_FATAL)
           00FF = no messages (MSG_LVL_NONE)
      \endcode


   \return Returns true if a valid log message was found within the specified time-out.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetMessageLevel( HANDLE hResourceContext, unsigned short iMessageLevel );

   /******************************************************************************/
   /**
      CDMA ICD, 3.4.125 Extended Message Configuration Request/Response

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iSSID
         See section 3.4.125.2 of the CDMA ICD for description of SSID's,
         basically they are unique identifiers assigned to an internal client
         of the debug message service.

         For example, sub system 6000 is a hex value of 0x1770

         Sub systems ID's can be identified as the value on the left side of the message ID
         listed in QXDM.  The right side of the message id is the bit number, which is the
         exponent of 2, used to determine the RT_MASK value.

         For example 0003/04 is a subsystem value of 3 a RT_MASK of 16, which is (2^4)
         Another example 6002/01 is a subsystem value of 0x1772 and a RT mask of 1, which is (2^1)


      \param iRT_MASK = Bit mask to determine what message levels are enabled
         \code
                Bit 1 (0x01) = Low
                Bit 2 (0x02_ = Medium
                Bit 3 (0x04) = High
                Bit 4 (0x08) = Error
                Bit 5 (0x10) = Fatal
                ...
                There can be numerous more sub categories, depending on the SSID

                0xFFFFFFFF = all messaages for the SSID
         \endcode



   \return Returns true if command succeeded, false if failed.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetMessageFilter( HANDLE hResourceContext, unsigned short iSSID, unsigned long iRT_MASK );

   /******************************************************************************/
   /**
      CDMA ICD, 3.4.125 Extended Message Configuration Request/Response

      Set All Run-time F3 Message Masks for all SubSystem.

      Implement commmand 0x7D, SubCommand 0x5 in 80-V1294-1

      \param iRT_MASK = Bit mask to determine what message levels are enabled
         \code
                Bit 1 (0x01) = Low
                Bit 2 (0x02_ = Medium
                Bit 3 (0x04) = High
                Bit 4 (0x08) = Error
                Bit 5 (0x10) = Fatal
                ...
                There can be numerous more sub categories, depending on the SSID

                0xFFFFFFFF = all messaages for the SSID
         \endcode

   \return Returns true if command succeeded, false if failed.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_SetAllMessageFilter( HANDLE hResourceContext, unsigned long iRT_MASK );

   /******************************************************************************/
   /**

     Fills in the ExtendedMessage structure with data from an extended log message
     buffer.  This function is necessary because the extended messages are not always
     the same size, depending on how many arguments are passed, and how long the
     file name and format string fields are.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param pBuffer = byte buffer to be parsed.  The referenced buffer must contain a valid extended message.
      \param pExtendedMessage = pointer to the ExtendedMessage structure that will be filled in based
                                upon the byte buffer.  This buffer is cast to a unsigned char* so that
                          the ExtendedMessage structure does not need to be defined for all
                          users of the library.

   \return Returns true if a valid extended log message was found in the pBuffer
           data buffer, and then parsed with no invalid values.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ParseExtendedMessage
   (
      HANDLE hResourceContext,
      unsigned char* pBuffer,
      unsigned char* pExtendedMessage
   );

      /******************************************************************************/
   /**

     Parses all messages the current Async queue and places a summary report on
     the console and/or the QLIB text log file.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iLogType = Log type bit mask, defined in QLib_Defines.h, for example, LOG_IO
      \param bSendToConsole = true to show data on the console, false to not show on console
      \param bSendToQlibLogFile = true to send report to QLIB text log file, false to not send
      \param bShowBinaryData = true to show the binary data of the async packet, false to not show
                                upon the byte buffer.
   \return

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DumpAsyncMessageToTextLog
   (
      HANDLE hResourceContext,
      unsigned int iLogType,
      unsigned char bSendToConsole,
      unsigned char bSendToQlibLogFile,
      unsigned char bShowBinaryData
   );

     /******************************************************************************
                     Phone sync (command) Logging
   *******************************************************************************/

   /******************************************************************************/
   /**
      Clear command response queue.  This is a queue of all messages that
      are not asynchronous log/debug/event types

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if success, false if failed.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_ClearCommandResponseQueue( HANDLE hResourceContext );

   /******************************************************************************/
   /**
      Returns the current size of the Command Responsequeue

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param piCmdRspQueueSize = Number of entries currently in the log queue

   \return Returns true if a valid message was in the Command Response queue, false if not.

   \warning .
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GetCommandResponseQueueSize(
      HANDLE hResourceContext, unsigned long* piCmdRspQueueSize );

   /******************************************************************************/
   /**

     Waits a specified amount of time for a command response message and returns the
     contents to the user directly.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param piSize = Pointer to number of bytes received in the command response message
      \param piBytes = Pointer to a buffer to store the command response message.
      \param iTimeout = millisecond time out

   \return Returns true if a valid log message was found within the specified time-out.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GetNextCommandResponse
   (
      HANDLE hResourceContext,
      unsigned short* piSize,
      unsigned char* piBytes,
      unsigned long iTimeOut
   );

      /******************************************************************************
                     Keypad Diag
   *******************************************************************************/

   /******************************************************************************/
   /**
   Diagnostic Keypad function

      This function starts the capturing of key presses by configuring the
      phone's extended message parameters to look for the "Applicaitons Default-high"
      set of messages.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_KeyPress_StartCapture( HANDLE hResourceContext  );

   /******************************************************************************/
   /**
   Diagnostic Keypad function

      This function stops the capturing of key presses by configuring the
      phone's extended message parameters to ignore the "Applicaitons Default-high"
      and "Legacy/Error" sets of messages.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_KeyPress_StopCapture( HANDLE hResourceContext  );

   /******************************************************************************/
   /**
   Diagnostic Keypad function

      This function clears the "key press" queue, which is a list of log messages
      that have been captured, indicating key press events

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_KeyPress_ClearQueue( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Diagnostic Keypad function

      This function clears the "key press" queue, which is a list of log messages
      that have been captured, indicating key press events

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piKeypressQueueSize = Number of entries currently in the Keypress Queue

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_KeyPress_GetQueueSize ( HANDLE hResourceContext, unsigned long* piKeypressQueueSize);


   /******************************************************************************/
   /**
   Diagnostic Keypad function

      This function returns the next key press event in the KeyPress queue.

      The KeyPress queue us determined by capturing log messages from the
      phone and locating certain key press event messages.

      When this function is called, the first key press event message to be received
      is returned and then that message is removed from the queue.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piKeypressID = Key press identifier, according to the KeyPressID enumeration
   \param piKeyPressEvent = Key press event type, according to the KeyPressEvent enumeration

   \return true if successful, false if fail or if KeyPress queue is empty.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_KeyPress_GetNextKeyEvent
   ( HANDLE hResourceContext, unsigned short* piKeyPressID, unsigned char* piKeyPressEvent );

   /******************************************************************************/
   /**
   Diagnostic Keypad function

      This function clears the keypress map, which correlates 16-bit hardware keypress
      ID's to 8-bit software ID's.

      After this function is called, keypress map entries must be specified using
      the DIAG_KeyPress_AddMapEntry() operation, to add the desired mapping entries.

      Before this function is called, a default (hard-coded) set of mapping entries
      will be used in the library.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail or if KeyPress queue is empty.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_KeyPress_ClearMap( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Diagnostic Keypad function

      This function clears the keypress map, which correlates 16-bit hardware keypress
      ID's to 8-bit software ID's.

      After this function is called, keypress map entries must be specified using
      the DIAG_KeyPress_AddMapEntry() operation, to add the desired mapping entries.

      Before this function is called, a default (hard-coded) set of mapping entries
      will be used in the library.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iHW_ID  = Hardware ID of the keypress map entry

   \param iKeypressID = Key press software identifier, according to the KeyPressID enumeration
                        Normally, these would map into the KeyPressID enumeration, but
                   for flexibility this data type is an unsigned 8-bit number,
                   so that values beyond the enermation list can be used.

   \return true if successful, false if fail or if KeyPress queue is empty.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_KeyPress_AddMapEntry
   ( HANDLE hResourceContext, unsigned short iHW_ID, unsigned char iKeyPressSW_ID );

   /******************************************************************************/
   /**
   Diagnostic Keypad function

      This function sets up the strings used to detect a keypress up/down in
      F3 messages

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sKeyUpString = the text string that will be sent when a key is released
                         (allowed up).  Only the porition of the string that is
                    constant for every key should be shown.

                          For example "AEEKey_RemovePressed: "

                    Following  this string, the F3 messages should have the hex
                    value of the hardware ID for the key press.  For example,
                    "AEEKey_RemovePressed: 0x0327" would indicate key with the
                    HW id of 0x0327.



   \param sKeyDownString = the text string that will be sent when a key is pressed.
                         Only the porition of the string that is constant for every
                    key should be shown.

                          For example "AEEKey_AddPressed: "

                    Following  this string, the F3 messages should have the hex
                    value of the hardware ID for the key press.  For example,
                    "AEEKey_AddPressed: 0x0327" would indicate key with the
                    HW id of 0x0327.

   \param iSSID  = the sub-system ID of the Message that needs to be activated in order
                   to receive key press messages.  Usually this is a value of 0 for
               the "legacy" category.  See the function DIAG_SetMessageFilter() for
               more information.

   \param iRT_MASK = the real time mask of the subsystem message.  The typical value
                     is 8, which corresponds to the "Error" catgory of message.  These
                 messsages are not necessarily errors--it is  just a message category.

                 See the function DIAG_SetMessageFilter() for more information.

   \return true if successful, false if failiure.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_KeyPress_ConfigureKeyDetect
   ( HANDLE hResourceContext, char* sKeyUpString, char* sKeyDownString, unsigned short iSSID, unsigned long iRT_MASK  );


   QLIB_API unsigned char QLIB_DIAG_ChallengeAsyncFilterPW( HANDLE hResourceContext, unsigned long iPassword );

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_DIAG_H)

