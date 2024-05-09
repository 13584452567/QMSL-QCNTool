/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_TDSCDMA_NS.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_TDSCDMA_NS
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_TDSCDMA_NS_H)
#define _QMSL_FTM_TDSCDMA_NS_H

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
                     TDSCDMA BER FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   TDSCDMA BER API, 80-V9698-1, START_TDSCDMA_MODE_REQUEST command

   This command starts the TDSCDMA Layer 1 task from an Inactive state. This will initialize the
   4 Layer 1 subsystem and the necessary driver

   This function can be used in FTM Sequencing mode operation.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_START_MODE_REQ(HANDLE hResourceContext, unsigned char* iStatus);

   /******************************************************************************/
   /**
   TDSCDMA BER API, 80-V9698-1, ACQUIRE_REQ command

   TThis command starts a cell search acquisition procedure. Currently, the user may only specify an
   3 ARFCN to perform the cell search procedure..

   This function can be used in FTM Sequencing mode operation.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iChannel = TDSCDMA RF channel

   \param iStatus =    0 == command success
                       1 == command fail

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_ACQUIRE_REQ( HANDLE hResourceContext, unsigned short iChannel, unsigned char* iStatus );

   /******************************************************************************/
   /**
   TDSCDMA BER API, 80-V9698-1, RMC_DCH_RECONFIGURE command

   This request attempts to reconfigure the RMC DCH call when a call is already established.
   Some platforms may be able to use this command to initially establish the RMC call directly after performing an acquisition step

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRMC_Type (refer to FTM_TDSCDMA_BER_RMC_Type_Enum)
   \param iDL_Slot = downlink timeslot. valid values are 2 to 6.
   \param iUL_Slot = uplink timeslot. valid values are 1 to 6.
   \param iUL_MaxTxPwr = Maximum transmit power in dBm.

   \param iUL_TPC_StepSize = 1,2,3 dB per step

   \param iChannel = TDSCDMA RF Channel (downlink). use zero if not in reconfig

   \param iStatus =    0 == command success
                       1 == command fail

   \return true if all operations succeeded and the correct event messages were received

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_RMC_DCH_SETUP_REQ( HANDLE hResourceContext,
         unsigned char iRMC_Type,
         unsigned char iDL_Slot,
         unsigned char iUL_Slot,
         unsigned char iUL_MaxTxPwr,
         unsigned char iUL_TPC_StepSize,
         unsigned short iChannel,
         unsigned char *iStatus);

   /******************************************************************************/
   /**
   TDSCDMA BER API, 80-V9698-1, QLIB_FTM_TDSCDMA_DROP_ALL_REQ command

   This command drops all channels from DCH state, but does not stops the TDSCDMA Layer 1 services

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus =    0 == command success
                       1 == command fail

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_DROP_ALL_REQ(HANDLE hResourceContext, unsigned char* iStatus);

   /******************************************************************************/
   /**
   TDSCDMA BER API, 80-V9698-1, STOP_TDSCDMA_MODE_REQ command

   This command stops the TDSCDMA Layer 1 services and returns to the inactive state.
   If the user has previously given a Start TDSCDMA mode request, the user must issue this command before proceeding to other FTM tests, or entering Online mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus =    0 == command success
                       1 == command fail

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_STOP_MODE_REQ(HANDLE hResourceContext, unsigned char* iStatus);


   /******************************************************************************/
   /**
   TDSCDMA BER, Start a TDSCDMA BER session. After this function is called, the acquisition
   function will need to be called, FTM_TDSCDMA_BER_Acquire.

      This function calls these operations and checks for errors:
         QLIB_FTM_TDSCDMA_BER_ClearStatus

      These low-level FTM operations are called and the associated events are verifed:
         START_TDSCDMA_MODE_REQ

      If the first START_TDSCDMA_MODE_REQ call fails, because a physical channel is
      already setup, then the function will call STOP_TDSCDMA_MODE_REQ and try to
      re-start the TDSCDMA non-signaling session.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTimeOut_ms = millisecond timeout for all TDSCDMA BER operations.  This should
                   be long enough that all operations will return the desired
                   events before the timeout is complete.

                   If the command response events occur before the timeout is
                   complete then the program flow will continue immediately, so there
                   is no penalty for having a long time-out, unless an error occurs.

                   FTM_NONSIG_DEFAULT_TIMEOUT to use the system's default timeout.

                   Will only be updated when a session is being intilalized.

   \return true if network session is setup successful, false if there are any failures

   \warning The active log mask will be changed to log only log FTM2 log packets.
            When the function is completed, the state of ASYNC logging will be enabled.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_StartSession(   HANDLE hResourceContext, unsigned long iTimeOut_ms );

   /******************************************************************************/
   /**
   TDSCDMA BER, acquire a downlink pilot.  Before this function is called,
   FTM_TDSCDMA_BER_StartSession must be called.  When the function is completed, the
   phone will be in the IDLE state.


   These low-level FTM operations are called and the associated events are verifed:
      ACQUIRE_REQ

      START_TDSCDMA_IDLE_REQ - will be called if any RMC channels have been setup sinc
      the last time that ACQUIRE_REQ has been called.

   This function will automatically retry the downlink acquisition up to 5 times, for the
   very first acquisition after the QLIB_FTM_TDSCDMA_BER_StartSession() is called.
   This is necessary because there are some layer 1 reasons why the first acquisition
   may not be successful immediately. In testing of 1000 attempts, it was to not
   explicitly issue an TDSCDMA_BER_IDLE command because this command is not necessary.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChannel = TDSCDMA RF channel

   \return true if network session is setup successful, false if there are any failures


   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_AcquirePilot( HANDLE hResourceContext, unsigned short iChannel );

   /******************************************************************************/
   /**
   TDSCDMA BER, go to IDLE mode.

      This function calls these operations and checks for errors:
         FTM_TDSCDMA_IDLE_MODE_REQ

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if idle mode has been entered successfully, false if there are any failures

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_Idle( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   TDSCDMA BER, drop all TDSCDMA channels.

      This function calls these operations and checks for errors:
         FTM_TDSCDMA_DROP_ALL_REQ

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if idle mode has been entered successfully, false if there are any failures

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_DropAll( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   TDSCDMA BER, Setup a RMC DCH channel.  This must be done after the
   FTM_TDSCDMA_BER_AcquirePilot function has completed successfully.

      This request attempts to reconfigure the RMC DCH call when a call is already established.
      Some platforms may be able to use this command to initially establish the RMC call directly after performing an acquisition step

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRMC_Type (refer to FTM_TDSCDMA_BER_RMC_Type_Enum)
      \param iDL_Slot = downlink timeslot. valid values are 2 to 6.
      \param iUL_Slot = uplink timeslot. valid values are 1 to 6.
   \param iUL_MaxTxPwr = Maximum transmit power in dBm.

      \param iUL_TPC_StepSize = 1,2,3 dB per step


      \param iStatus =    0 == command success
                          1 == command fail

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_SetupRMC_DCH(
      HANDLE hResourceContext,
      unsigned char iRMC_Type, unsigned char iDL_Slot, unsigned char iUL_Slot, unsigned char iUL_MaxTxPwr, unsigned char iUL_TPC_StepSize);

   /******************************************************************************/
   /**
   TDSCDMA BER, handover to a new RMC DCH channel.  This must be done after the
   QLIB_FTM_TDSCDMA_BER_SetupRMC_DCH function has completed successfully.
   This request attempts to reconfigure the RMC DCH call when a call is already established.
   Some platforms may be able to use this command to initially establish the RMC call directly after performing an acquisition step

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRMC_Type (refer to FTM_TDSCDMA_BER_RMC_Type_Enum)
   \param iDL_Slot = downlink timeslot. valid values are 2 to 6.
   \param iUL_Slot = uplink timeslot. valid values are 1 to 6.
   \param iUL_MaxTxPwr = Maximum transmit power in dBm.

   \param iUL_TPC_StepSize = 1,2,3 dB per step

   \param iChannel = TDSCDMA RF Channel (downlink). use zero if not in reconfig

   \param iStatus =    0 == command success
                       1 == command fail

   \return true if all operations succeeded and the correct event messages were received


   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_Handover(
      HANDLE hResourceContext,
      unsigned char iRMC_Type, unsigned char iDL_Slot, unsigned char iUL_Slot, unsigned char iUL_MaxTxPwr, unsigned char iUL_TPC_StepSize, unsigned short iChannel );


   /******************************************************************************/
   /**
   TDSCDMA BER, 3.8 FTM TDSCDMA TFCS Configuration request

   The tfcs_config table must be 4 unique numbers, all between 0 and 3.
   This defines how the TFCI values should be mapped to each Transport Format
   Combination.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param aiTFCS_Config=

      To solve the Agilent issue you would send the command using tfcs_select =
      FTM_TDSCDMA_BER_UL_TFCS_CONFIG, and tfcs_config = {0,2,1,3}.

      If you don't send the command the default behavior is tfcs_config = {0,1,2,3}.
      Subtle difference, enough to break the Agilent.  Right now we don't really
      need to send a DL_TFCS_CONFIG since other the equipment are flexible or adhere
      to the standard RMC config.

   \param eTFCS_Select = specifies configuration of UL or DL, defined by
      \code
           FTM_TDSCDMA_BER_UL_TFCS_CONFIG = 0,
           FTM_TDSCDMA_BER_DL_TFCS_CONFIG = 1
      \endcode

   \param iStatus
      \code
          0 = Success (COMMAND_SUCCESS)
          1 = Failure (COMMAND_FAILED)
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_RMC_DCH_TFCS_CONFIG_REQ(
      HANDLE hResourceContext,
      unsigned char eTFCS_Select,
      unsigned char aiTFCS_Config[ 4] );



   /******************************************************************************/
   /**
   TDSCDMA BER, Clear BER event status, Section 3.9 FTM Reset Event Status

      This command send FTM command to clear the event status.

      This command clears event status that is used for QLIB_FTM_TDSCDMA_BER_EVENT_STATUS_REQ function,

      This function could be called before the TDSCDMA BER function that generates the event.
      For example, QLIB_FTM_TDSCDMA_BER_AcquirePilot

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iStatus = 0 - COMMAND_SUCCESS
                   1 - COMMAND_FAILED
      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_EVENT_STATUS_CLEAR_REQ(HANDLE hResourceContext, unsigned short* iStatus);

   /******************************************************************************/
   /**
   TDSCDMA BER, Wait for event, Section 3.10

      This command allows the user to wait for a specific TDSCDMA BER non-signaling event. By
      using this command it is possible to avoid using the asynchronous events for the most common
      event types.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iEventType = See FTM_TDSCDMA_BER_EVENT_STATUS_Enum in QLib_Defines.h

                     0 -   FTM_TDSCDMA_BER_START_TDSCDMA_MODE_CNF
                     1 - FTM_TDSCDMA_BER_STOP_TDSCDMA_MODE_CNF
                     2 - FTM_TDSCDMA_BER_IDLE_MODE_CNF
                     3 - FTM_TDSCDMA_BER_ACQ_CNF
                     4 -   FTM_TDSCDMA_BER_CPHY_SETUP_CNF
                     5 - FTM_TDSCDMA_BER_PHYCHAN_ESTABLISHED_IND

      \param iTimeOut_ms = Timeout to use for waiting for the event. Units are milliseconds.

      \param iStatus =   0 ?FTM_TDSCDMA_BER_SYNC_STATUS_SUCCESS
                     1 ?FTM_TDSCDMA_BER_SYNC_STATUS_GEN_FAILURE
                     2 ?FTM_TDSCDMA_BER_SYNC_STATUS_TIMEOUT_EXPIRED
                     3 ?FTM_TDSCDMA_BER_SYNC_STATUS_EVENT_STATUS_FAILED

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_EVENT_STATUS_REQ(HANDLE hResourceContext, unsigned char iEventType, unsigned long iTimeOut_MS, unsigned short* iStatus );


   /******************************************************************************/
   /**
   TDSCDMA BER, Tx Power Override, Section 3.11

      This command allows user to overrie Tx power in non-signaling mode

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param byte = 1 = ON (override)
                    0 = OFF

      \param iUL_Pwr_dBm10 =   Power (dBm) x 10
                              For example: 22dBm = 220

      \param iStatus = 0 = COMMAND_SUCCESS
                       1 = COMMAND_FAIL

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_SET_UL_POWER(HANDLE hResourceContext, unsigned char bOverride, short iUL_Pwr_dBm10, unsigned short* iStatus);

   /******************************************************************************/
   /**
   TDSCDMA BER, Rx Level Report, Section 3.12

      This command returns the current receive power in RX_AGC and dBm for a selected receive chain.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iRxChain = 0 - Primary Rx
                        1 - Secondary Rx


      \param iRxAGC  = Rx AGC

      \param iRxPowerdBm  = Rx power in 1/10 dBm units
                            This value is signed

      \param iStatus = 0 = COMMAND_SUCCESS
                       1 = COMMAND_FAIL

      \warning

      \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_RX_LEVEL_REQ(HANDLE hResourceContext, unsigned char iRxChain, unsigned short* iStatus, short*iRxAGC, short* iRxPowerdBm);
   /******************************************************************************/
   /**
   TDSCDMA BER, TPC Control, Section 3.13

      This function sends FTM_TDSCDMA_BER_TPC_CONTROL command which simulates all up or all down bits.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iOverride_Enabled   =   0 ?Up down bits from generator; TCP_Pattern ignored
                              1 ?Override enabled; simulate all up or all down bits

      \param iTCP_Pattern  = Pattern per channel; example below sets all channels:

                        0 - All Down Power Control Bits
                        1 - All Up Power Control Bits

      \param iStatus = 0 = COMMAND_SUCCESS
                       1 = COMMAND_FAIL


      \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_TPC_CONTROL(HANDLE hResourceContext, unsigned short iOverride_Enabled, unsigned long iTCP_Pattern, unsigned short* iStatus);

   /******************************************************************************/
   /**
   TDSCDMA RSCP, RSCP Measurement, Section 3.13  *ToDo*

      This function sends FTM_TDSCDMA_BER_RSCP command which returns RSCP data.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iEcIo_Rx0   =   data

      \param iRSCP_Rx0   =   data

      \param iEcIo_Rx1   =   data

      \param iRSCP_Rx1   =   data

    \param iStatus = 0 = COMMAND_SUCCESS
                       1 = COMMAND_FAIL

      \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_RSCP(HANDLE hResourceContext, unsigned long* iEcIo_Rx0, unsigned long* iRSCP_Rx0, unsigned long* iEcIo_Rx1, unsigned long* iRSCP_Rx1, unsigned short* iStatus);

   /******************************************************************************/
   /**
   TDSCDMA BER, Clear the internal status of the TDSCDMA BER structure

      Resets the contents of all fields in the internal TDSCDMA_BER_State state structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_ClearStatus( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   TDSCDMA BER, Returns a copy of the internal TDSCDMA BER state. On the internal copy
            it clears the "updated" fields for each message type so that the
          next time this funciton is called. Only items that been received
          since the first function call are marked as "updated."


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pTDSCDMA_BER_State = reference to a TDSCDMA_BER_State structure that will be
                           filled in with the state information

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_GetStatus( HANDLE hResourceContext, unsigned char* pTDSCDMA_BER_State );

   /******************************************************************************/
   /**
   TDSCDMA BER, Returns a simplified status of whether a specified event has occured.

   The function operations upon the bHasUpdated array held in the TDSCDMA BER status
   structure (data type TDSCDMA_BER_State, as defined in QLib_Defines.h).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eEventID = The input parameter is an index into this array, and the function
                      returns a true if the event has occured and false if it has not.

      Data type is log_FTM2_TDSCDMA_BER_log_id_enum, defined in QLib_Defines.h

      Values are:
      \code
         LOG_FTM2_TDSCDMA_START_MODE_CNF          = 0 = FTM TDSCDMA BER start TDSCDMA mode confirmation
         LOG_FTM2_TDSCDMA_STOP_MODE_CNF           = 1 = FTM TDSCDMA BER stop TDSCDMA mode confirmation
         LOG_FTM2_TDSCDMA_IDLE_MODE_CNF     = 2 = FTM TDSCDMA BER start idle mode confirmation
         LOG_FTM2_TDSCDMA_ACQUIRE_CNF             = 3 = FTM TDSCDMA BER acquire confirmation
         LOG_FTM2_TDSCDMA_CPHY_SETUP_CNF           = 4 = FTM TDSCDMA BER CPHY setup confirmation
         LOG_FTM2_TDSCDMA_PHYCHAN_ESTABLISHED_IND = 5 = FTM TDSCDMA BER physical channel established confirmation
         LOG_FTM2_TDSCDMA_CPHY_ERROR_IND          = 6 = FTM TDSCDMA BER pyhsical channel error
         LOG_FTM2_TDSCDMA_RL_FAILURE_IND          = 7 = FTM TDSCDMA BER Reverselink error
      \endcode


   \param pTDSCDMA_BER_State = reference to a TDSCDMA_BER_State structure that will be
                           filled in with the state information

   \return true the event type has occurred, false if it has not.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_GetEventStatus( HANDLE hResourceContext, unsigned char eEventID );

   /******************************************************************************/
   /**
   TDSCDMA BER, close the TDSCDMA Non-signaling session.

      This low-level FTM operation is called and the associated event is verifed:
         STOP_TDSCDMA_MODE_REQ

      This function also calls QLIB_FTM_LOG_StopFTM_Log( HANDLE, LOG_FTM2_LOG_TDSCDMA_BER )
      to disable the FTM log that was started in QLIB_FTM_TDSCDMA_BER_StartSession


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if all operations succeeded and the correct event messages were received

   \warning This function will disable async logging and clear the async queue.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_BER_StopSession( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   TDSCDMA HSUPA BER, Setup a HSUPA E-PUCH channel.  This must be done after the
   FTM_TDSCDMA_BER_AcquirePilot function has completed successfully.

   This request attempts to reconfigure the HSUPA E-PUCH call when a call is already established.
   Some platforms may be able to use this command to initially establish the HSUPA call directly after performing an acquisition step

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iChannel = TDSCDMA RF Channel (downlink).
   \param iDL_Dpch_Slot = downlink DPCH timeslot. valid values are 2 to 6.
   \param iUL_Dpch_Slot = uplink DPCH timeslot. valid values are 1 to 6.
   \param iUL_MaxTxPwr = Maximum transmit power in dBm.
   \param iUL_TPC_StepSize = 1,2,3 dB per step
   \param bIs_Hsupa_On = turn on/off HSUPA (just effective in re-configuration case)
   \param iEpuch_Slot = HSUPA UL E-PUCH timeslot
   \param iEpuch_Code = HSUPA E-PUCH code, refer to TDSCDMA_HSUPA_EPUCH_CODE_ENUM
   \param iEpuch_TxPwr = transmit power on HSUPA channel (in dBm)
   \param iNum_Eucch = number of E-UCCH (max to 16)
   \param iMod_Type = modulation type on HSUPA channel
   \param iStatus =    0 == command success
                       1 == command fail

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_HSUPA_BER_StartSession(
      HANDLE hResourceContext, unsigned short iChannel,
      unsigned char iDL_Dpch_Slot, unsigned char iUL_Dpch_Slot, unsigned char iUL_MaxTxPwr, unsigned char bIs_Hsupa_On,
      unsigned char iEpuch_Slot, unsigned char iEpuch_Code, unsigned char iEpuch_TxPwr, unsigned char iNum_Eucch, unsigned char iMod_Type );

   /******************************************************************************/
   /**

   Start logging of TDSCDMA AGC packets.

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function WaitForNextTDSCDMA_RxAGC_Log() can be called to wait
   for the next TDSCDMA log message and have the values returned.

   \return true if successful, false if fail.

   \warning

        1. Before this function is called, the phone must be set in a TDSCDMA FTM mode, by
           calling either QLIB_FTM_SET_MODE() for basic RF testing, or by calling
            QLIB_FTM_TDSCDMA_BER_StartSession() for TDSCDMA BER testing.

      2. This function will set the async messasge logging status to ON, to
           turn off async messages, QLIB_DIAG_SetPhoneLoggingState() should be called.



   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_RxAGC_Start_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Wait a specified number of milliseconds for the next WCMA AGC log message.

   If the message is found, then the contents of the message are copied into

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function WaitForNextTDSCDMA_RxAGC_Log() can be called to wait
   for the next TDSCDMA log message and have the values returned.

   \param pTDSCDMA_AGC_Log = pointer to the are to store the TDSCDMA AGC log information.
                           This is of type "FTM2LogMessage_TDSCDMA_RxAGC" defined in
                     QLIB_Defines.h

   \param iTimeout_ms = # of milliseconds to wait for the AGC.  Default is 300ms

   \return true if a valid TDSCDMA log was found within the specified timeout, false if not.

   \warning Before this function is called, StartTDSCDMA_RxAGC_Log() must be called to setup
            capturing of TDSCDMA AGC messages.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_RxAGC_WaitForNextLog(
      HANDLE hResourceContext,  void* pTDSCDMA_RxAGC_Log, unsigned long iTimeout_ms );

   /******************************************************************************/
   /**

   Stop logging of TDSCDMA AGC packets.  This is important to do before changing
   RF modes or starting/stopping TDSCDMA BER

   This command calls the FTM_LOG_DISABLE() function with the proper settings.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function will set the async messasge logging status to OFF.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_RxAGC_Stop_Log( HANDLE hResourceContext  );


   /******************************************************************************/
   /**

   Start logging of TDSCDMA AGC packets.

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function WaitForNextTDSCDMA_TxAGC_Log() can be called to wait
   for the next TDSCDMA log message and have the values returned.

   Note QLIB_FTM_TDSCDMA_BER_StartSession() automatically calls this function when
   it begins.

   \return true if successful, false if fail.

   \warning

        1. Before this function is called, the phone must be set in a TDSCDMA FTM mode, by
           calling either QLIB_FTM_SET_MODE() for basic RF testing, or by calling
            QLIB_FTM_TDSCDMA_BER_StartSession() for TDSCDMA BER testing.

      2. This function will set the async messasge logging status to ON, to
           turn off async messages, QLIB_DIAG_SetPhoneLoggingState() should be called.



   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_TxAGC_Start_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Wait a specified number of milliseconds for the next WCMA AGC log message.

   If the message is found, then the contents of the message are copied into

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function WaitForNextTDSCDMA_TxAGC_Log() can be called to wait
   for the next TDSCDMA log message and have the values returned.

   \param pTDSCDMA_AGC_Log = pointer to the are to store the TDSCDMA AGC log information.
                           This is of type "FTM2LogMessage_TDSCDMA_TxAGC" defined in
                     QLIB_Defines.h

   \param iTimeout_ms = # of milliseconds to wait for the AGC.  Default is 300ms

   \return true if a valid TDSCDMA log was found within the specified timeout, false if not.

   \warning Before this function is called, StartTDSCDMA_TxAGC_Log() must be called to setup
            capturing of TDSCDMA AGC messages.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_TxAGC_WaitForNextLog(
      HANDLE hResourceContext,  void* pTDSCDMA_RxAGC_Log, unsigned long iTimeout_ms );

   /******************************************************************************/
   /**

   Stop logging of TDSCDMA AGC packets.  This is important to do before changing
   RF modes or starting/stopping TDSCDMA BER

   This command calls the FTM_LOG_DISABLE() function with the proper settings.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function will set the async messasge logging status to OFF.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_TxAGC_Stop_Log( HANDLE hResourceContext  );



#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_TDSCDMA_NS_H)
