/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_Diagnostic_Subsystem.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_Diag_SubSysCommand
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

   /******************************************************************************/
   /**
   Read ESN, special case of DIAG_NV_READ_F

   Returns the value of the NV_ESN_I NV field, item #0.

   If the handle's target type is APQ, 0xdeadbeef is always returned

   See QLIB_SetTargetType() for details

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piESN = Pointer to the location where the ESN will be stored

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_READ_ESN_F( HANDLE hResourceContext, unsigned long* piESN );

   /******************************************************************************
                  Diagnostic Subsystem (80-V1294-10)
   *******************************************************************************/

   /******************************************************************************/
   /**

   This is sent by the DM to reset both the drop and allocation counts for different packet types
   (logs, events, F3s, delayed response messages) on the various processors (application, modem,
   Hexagon, Riva).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDiagnosticSubsystem = Diagnostic drop ID, type DiagnosticDropCountResetId
         DIAGDIAG_DROP_RESET_COUNT_LOG_APP = 43,      //!<' Logs on the application processor
         DIAGDIAG_DROP_RESET_COUNT_EVENT_APP = 45,    //!<' Events on the application processor
         DIAGDIAG_DROP_RESET_COUNT_F3_APP = 47,       //!<' F3 messages on the application processor
         DIAGDIAG_DROP_RESET_COUNT_DELAY_APP = 70,    //!<' Delayed response messages on the application processor
         DIAGDIAG_DROP_RESET_COUNT_LOG_MODEM = 52,    //!<' Logs on the modem processor
         DIAGDIAG_DROP_RESET_COUNT_EVENT_MODEM = 54   //!<' Events on the modem processor
         DIAGDIAG_DROP_RESET_COUNT_F3_MODEM = 56,     //!<' F3 messages on the modem processor
         DIAGDIAG_DROP_RESET_COUNT_DELAY_MODEM = 80   //!<' Delayed response messages on the modem processor
         DIAGDIAG_DROP_RESET_COUNT_LOG_Q6 = 61,       //!<' Logs on the Hexagon processor
         DIAGDIAG_DROP_RESET_COUNT_EVENT_Q6 = 63,     //!<' Events on the Hexagon processor
         DIAGDIAG_DROP_RESET_COUNT_F3_Q6 = 65,        //!<' F3 messages on the Hexagon processor
         DIAGDIAG_DROP_RESET_COUNT_DELAY_Q6 = 90,     //!<' Delayed response messages on the Hexagon processor
         DIAGDIAG_DROP_RESET_COUNT_LOG_RIVA = 5121,   //!<' Logs on the Riva processor
         DIAGDIAG_DROP_RESET_COUNT_EVENT_RIVA = 5123, //!<' Events on the Riva processor
         DIAGDIAG_DROP_RESET_COUNT_F3_RIVA = 5125,    //!<' F3 messages on the Riva processor
         DIAGDIAG_DROP_RESET_COUNT_DELAY_RIVA = 5130, //!<' Delayed response messages on the Riva processor

   \return True if file is opened successfully.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAGDIAG_RESET_DROP_COUNT(
      HANDLE hResourceContext,
      unsigned short iDiagnosticSubsystem
   );
   /******************************************************************************/
   /**

   Once started manually, the diagnostic services stress test application provides equivalent stress
   test and loopback functionality in the user space as in the kernel space. Currently, subsystem
   command codes with numeric value greater than or equal to 100 are user space commands that
   are registered through the stress test application. This particular command (102) will terminate
   the application, successfully deregistering the commands from the system.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDropCountType = input, Diagnostic drop ID, type DiagnosticDropCountGetId
   DIAGDIAG_GET_DROP_COUNT_LOG_APP = 44,     //!<' Log drop count on the application processor
   DIAGDIAG_GET_DROP_COUNT_EVENT_APP = 46,   //!<' Event drop count on the application processor
   DIAGDIAG_GET_DROP_COUNT_F3_APP = 48,      //!<' F3 drop count on the application processor
   DIAGDIAG_GET_DROP_COUNT_DELAY_APP = 71,   //!<' Delayed response drop count on the application processor
   DIAGDIAG_GET_ALLOC_COUNT_LOG_APP = 49,    //!<' Log allocation count on the application processor
   DIAGDIAG_GET_ALLOC_COUNT_EVENT_APP = 50,  //!<' Event allocation count on the application processor
   DIAGDIAG_GET_ALLOC_COUNT_F3_APP = 51,     //!<' F3 allocation count on the application processor
   DIAGDIAG_GET_ALLOC_COUNT_DELAY_APP = 72,  //!<' Delayed response allocation count on the application processor
   DIAGDIAG_GET_DROP_COUNT_LOG_MODEM = 53,   //!<' Log drop count on the modem processor
   DIAGDIAG_GET_DROP_COUNT_EVENT_MODEM = 55, //!<' Event drop count on the modem processor
   DIAGDIAG_GET_DROP_COUNT_F3_MODEM = 57,    //!<' F3 drop count on the modem processor
   DIAGDIAG_GET_DROP_COUNT_DELAY_MODEM = 81, //!<' Delayed response drop count on the modem processor
   DIAGDIAG_GET_ALLOC_COUNT_LOG_MODEM = 58,  //!<' Log allocation count on the modem processor
   DIAGDIAG_GET_ALLOC_COUNT_EVENT_MODEM = 59, //!<' Event allocation count on the modem processor
   DIAGDIAG_GET_ALLOC_COUNT_F3_MODEM = 60,   //!<' F3 allocation count on the modem processor
   DIAGDIAG_GET_ALLOC_COUNT_DELAY_MODEM = 82, //!<' Delayed response allocation count on the modem processor
   DIAGDIAG_GET_DROP_COUNT_LOG_Q6 = 62,      //!<' Log drop count on the Hexagon processor
   DIAGDIAG_GET_DROP_COUNT_EVENT_Q6 = 64,    //!<' Event drop count on the Hexagon processor
   DIAGDIAG_GET_DROP_COUNT_F3_Q6 = 66,       //!<' F3 drop count on the Hexagon processor
   DIAGDIAG_GET_DROP_COUNT_DELAY_Q6 = 91,    //!<' Delayed response drop count on the Hexagon processor
   DIAGDIAG_GET_ALLOC_COUNT_LOG_Q6 = 67,     //!<' Log allocation count on the Hexagon processor
   DIAGDIAG_GET_ALLOC_COUNT_EVENT_Q6 = 68    //!<' Event allocation count on the Hexagon processor

   \param iDropCount = output, representing the log, event, F3, or delayed response drop
                       count on the application, modem, or Hexagon processor, depending
                       on which subsystem command code was specified.

   \return True if file is opened successfully.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAGDIAG_GET_DROP_COUNT(
      HANDLE hResourceContext,
      unsigned short iDropCountType,
      unsigned long* piDropCount
   );

   /******************************************************************************
                  LTE Diag
   *******************************************************************************/

   /******************************************************************************/
   /**
   Enable/Disable Rx chain for LTE (document pending).

   When this command is called, a particular Rx chain described by iLTERxChainType is enabled/disabled.
   The status are reset upon power cycle.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iLTERxChainType =   Action; possible values are:
                     0 = no action;
                     1 = Enable Rx0 only
                     2 = enable Rx1 only
                     3 = enable Rx0 and Rx1
                     4 = no action
                     5 = disable Rx0 only
                     6 = disable Rx1 only
                     7 = disable Rx 0 and Rx1.
   \code
      typedef enum
      {
         _LTE_RX_CHAIN_TYPE_NO_ACTION = 0,
         _LTE_RX_CHAIN_TYPE_ENABLE_RX0_ONLY = 1,
         _LTE_RX_CHAIN_TYPE_ENABLE_RX1_ONLY = 2,
         _LTE_RX_CHAIN_TYPE_ENABLE_RX0_AND_RX1 = 3,
         _LTE_RX_CHAIN_TYPE_NO_ACTION2 = 4,
         _LTE_RX_CHAIN_TYPE_DISABLE_RX0_ONLY = 5,
         _LTE_RX_CHAIN_TYPE_DISABLE_RX1_ONLY = 6,
         _LTE_RX_CHAIN_TYPE_DISABLE_RX0_AND_RX1 = 7,
         _LTE_RX_CHAIN_TYPE_END_OF_ENUM
      }lte_rx_chain_type_enum_type;

   \endcode

   \return true if successful, false if fail.

   \warning
      1.   After LTE sends RX tuning request to RF driver, this diag commands can be sent to enable/disable a specific chain.
      2.   Note that the diag command can only be sent when RF driver RX is tuned. This is a requirement from the RF S/W side.;
         in another word, this command should be sent after phone goes to traffic state

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_LTE_RX_TOOL_CHAIN_COMMAND( HANDLE hResourceContext, unsigned char iLTERxChainType);

      /******************************************************************************
                  HDR Diag
   *******************************************************************************/

   /******************************************************************************/
   /**
   Set/Get Dip switch for HDR subsystem (80-V1294-2 2.2.3 DIP Switch request/response)

   When the DM sends a DIP switch request message, the DMSS responds by sending a DIP switch
   response message to the DM that contains the current setting of the switches. Each bit is the value
   of a single switch. The DIP switches are reset upon power cycle.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iAction   =   Action; possible values are:
                  0 = Reset DIP switch
                  1 = Set DIP switch
                  2 = Clear all DIP switches
                  3 = Read DIP switch mask

   \param  iDipSwitchBit = DIP switch bit to set or reset (only valid if iAction = 0,1)
                     Refer to 80-V1294-2 table 2.2 for a list of implemented DIP switches.

   \param piDipSwitchMask = A pointer to DIP switch mask returned from DIP SWITCH response message

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_HDR_DIAG_DIP_SWITCH( HANDLE hResourceContext, unsigned char iAction, unsigned char iDipSwitchBit, unsigned long * piDipSwitchMask );


   /******************************************************************************/
   /**
   Reset forward statistics counter for HDR subsystem (80-V1294-2 5.3.119)

   Upon reception of the reset packet, the DMSS would reset all forward statistics counters to zero.
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \note this function should be used every time QLIB_FTM_EVDO_NS_EnableMeasurementLogs() is used for throughput statistics:
         Release 0 throughput: EVDO_FORWARD_LINK_STATISTICS_SUMMARY 0x1084
         Revision A throughput: EVDO_REVA_SU_FWDSTATS   0x1192

   \return true if successful, false if fail.
   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_EVDO_RST_FWD_STATS( HANDLE hResourceContext );

      /******************************************************************************
                  GSM Diag
   *******************************************************************************/

   /******************************************************************************/
   /**
   GSM Diagnostic IC, 3.2.2/3 Status Request/Response

     Get the GSM Call status

      \param aiIMEI[9] = First byte is length (0 to 15), Next 8 bytes are packed BCD
            #define GSM_DIAG_IMEI_SIZE  9

      \param aiIMSI[9] = First byte is length (0 to 15), Next 8 bytes are packed BCD
            #define GSM_DIAG_IMSI_SIZE  9

      \param aiLAI[5] = Location area ID. Format:  3bytes, Public Land Mobile Network Identity, 2bytes Location Area Code
            #define GSM_DIAG_LAI_SIZE   5

      \param piCellID = Cell identity
      \param piCM_CallState = refer to enumeration gsm_call_state_enum:
         \code
              GSM_STATUS_CALL_STATE_NONE           =-1, //!< ' not defined
              GSM_STATUS_CALL_STATE_IDLE           = 0, //!< ' IDLE
              GSM_STATUS_CALL_STATE_ORIG           = 1, //!< ' Originating
              GSM_STATUS_CALL_STATE_WAITING        = 2, //!< ' Waiting
              GSM_STATUS_CALL_STATE_INCOM          = 3, //!< ' Incoming
              GSM_STATUS_CALL_STATE_CC_IN_PROGRESS = 4, //!< ' Concurrent incoming/originating
              GSM_STATUS_CALL_STATE_CONV           = 5  //!< ' Conversation
         \endcode
      \param piCM_OperationalMode = refer to enumeration sys_oprt_mode_enum:
         \code
               SYS_OPRT_MODE_NONE   = -1,            -  FOR INTERNAL USE OF CM ONLY!
               SYS_OPRT_MODE_PWROFF   = 0,            -  Phone is powering off
               SYS_OPRT_MODE_FTM      = 1,         -  Phone is in factory test mode
               SYS_OPRT_MODE_OFFLINE   = 2,         -  Phone is offline
               SYS_OPRT_MODE_OFFLINE_AMPS = 3,         -  Phone is offline analog
               SYS_OPRT_MODE_OFFLINE_CDMA = 4,         -  Phone is offline cdma
               SYS_OPRT_MODE_ONLINE = 5,            -  Phone is online
               SYS_OPRT_MODE_LPM = 6,               -  Phone is in LPM - Low Power Mode
               SYS_OPRT_MODE_RESET = 7,               -  Phone is resetting - i.e. power-cycling
               SYS_OPRT_MODE_NET_TEST_GW = 8,         -  Phone is conducting network test for GSM/WCDMA.
               SYS_OPRT_MODE_OFFLINE_IF_NOT_FTM = 9,   -  offline request during powerup.
               SYS_OPRT_MODE_PSEUDO_ONLINE = 10,      -  Phone is pseudo online, tx disabled

         \endcode
      \param piCM_SystemMode = refer to enumeration for sys_sys_mode_enum:
         \code
               SYS_SYS_MODE_NONE   = -1,      //!< ' FOR INTERNAL USE ONLY!
               SYS_SYS_MODE_NO_SRV   = 0,      //!< ' No service = NV_MODE_INACTIVE
               SYS_SYS_MODE_AMPS   = 1,      //!< ' Analog Mobile Phone System (AMPS) mode
               SYS_SYS_MODE_CDMA   = 2,      //!< ' Code Division Multiple Access (CDMA) mode
               SYS_SYS_MODE_GSM      = 3,      //!< ' Global System for Mobile communications (GSM) mode
               SYS_SYS_MODE_HDR      = 4,      //!< ' High Data Rate (HDR) mode
               SYS_SYS_MODE_WCDMA   = 5,      //!< ' Wideband CDMA (WCDMA) mode
               SYS_SYS_MODE_GPS      = 6,      //!< ' Global Positioning System (GPS) mode
               SYS_SYS_MODE_GW      = 7,      //!< ' GSM and WCDMA mode
               SYS_SYS_MODE_MAX               //!< ' FOR INTERNAL USE ONLY!
         \endcode

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GSM_STATUS_F(
      HANDLE hResourceContext,
      unsigned char iIMEI[9], unsigned char aiIMSI[9],
      unsigned char aiLAI[5],  unsigned short* piCellID, unsigned char* piCM_CallState,
      unsigned char* piCM_OperationalMode, unsigned char* piCM_SystemMode );


   /******************************************************************************/
   /**
   GSM Diagnostic IC, 3.2.7/8 Call origination request/response

     Originate a call from the mobile

      \param iNumDigits = number of digits in the IMSI
      \param aiIMSI = array of IMSI digits to dial
                     #define GSM_DIAG_CALL_ORG_IMSI_SIZE 32 = # of digits
                  IMSI characters are in the ASCII format, for example 0x35 for '5'

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GSM_CALL_ORIG_F( HANDLE hResourceContext, unsigned char iNumDigits, unsigned char aiIMSI[32] );


   /******************************************************************************/
   /**
   GSM Diagnostic IC, 3.2.9/10 Call end request/response

     End the currently active call

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GSM_CALL_END_F( HANDLE hResourceContext );

      /******************************************************************************/
   /** see Call Manager ICD 80-V1294_K 3.9 CM_GET_CALL_INFORMATION_LIST request/response
           This function is called to obtain state information of all the call objects.
           Call attributes returned include call id, call type, call state and dormant status.
           Value of dormant status is valid for only PS calls in WCDMA.
            \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
         \param pRespStruc = pointer to a struct defined by CM_Get_Call_Information_List_Resp_Struct.
       **/
   QLIB_API unsigned char QLIB_DIAG_CM_GET_CALL_INFORMATION_LIST
   (HANDLE hResourceContext,
    void* pRespStruc);


   /******************************************************************************/
   /**
      Send diag command to control the rx diversity chain: PRx only,
      DRx only and both of them. For this API to take effect, the call should be setup first,
      then issue this diag command for config the rx chain

      \param  Byte sys_mode = the technology when this command is using
                   5 = TDSCDMA

      \param  Byte chain_selection = bit mask for chain selection
                   0 = No Chain
                   1 = Bit Mask for Chain 0
                   2 = Bit Mask for Chain 1
                   3 = Bit Mask for Both chains

      \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_CHANGE_RX_DIVERSITY
   (
      HANDLE hResourceContext,
      unsigned char bSysMode,
      unsigned char bChainSelection
   );

#ifdef __cplusplus
}   // extern "C"
#endif
