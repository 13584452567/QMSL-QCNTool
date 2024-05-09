/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_EGPRS_NS.h#5 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_EGPRS_NS
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_EGPRS_NS_H)
#define _QMSL_FTM_EGPRS_NS_H

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
                     GSM BER FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   GSM BER, Start a GSM BER session. After this function is called, the BCCH acquistion
   will need to be setup using FTM_GSM_BER_AssignBCCH.

      This function calls these operations and checks for errors:
         FTM_GSM_BER_ClearStatus

      This low-level FTM operation is called and the associated event is verifed:
         START_GSM_MODE_REQ

      \param iTimeOut_ms = millisecond timeout for all GSM BER operations.  This should
                      be long enough that all operations will return the desired
                      events before the timeout is complete.

                      If the command response events occur before the timeout is
                      complete then the program flow will continue immediately, so there
                      is no penalty for having a long time-out, unless an error occurs.

                      FTM_NONSIG_DEFAULT_TIMEOUT to use the system's default timeout.

                      Will only be updated when a session is being intilalized.

   \return true if network session is seutp successful, false if there are any failures

   \warning The active log mask will be changed to log only log FTM2 log packets.
            When the function is completed, the state of ASYNC logging will be enabled.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_StartSession(
      HANDLE hResourceContext, unsigned long iTimeOut_ms );

   /******************************************************************************/
   /**
   GSM BER, Assign a BCC.  Before this function is called, FTM_GSM_BER_StartSession
   must be called.  When the function is completed, the phone will be in the IDLE
   state.

   If using a CMU-200, the "connect" command should not be sent until after this function
   is executed.  Before this calling this function though, the BCCH channel should be
   established so that the phone can successfully acquire.


      These low-level FTM operations are called and the associated events are verifed:
         SELECT_SPECIFIC_BCCH_REQ
         START_IDLE_MODE_REQ

      \param iChannel = RF channel. Valid range depends on band.
      \param iBand
         \code
           0 = PGSM 900 = FTM_GSM_BER_PGSM_900
           1 = EGSM 900 = FTM_GSM_BER_EGSM_900
           2 = PCS 1900 = FTM_GSM_BER_PCS_1900
           3 = DCS 1800 = FTM_GSM_BER_DCS_1800
           4 = CELL 850 = FTM_GSM_BER_CELL_850
         \endcode

   \return true if network session is seutp successful, false if there are any failures

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_AssignBCCH(
      HANDLE hResourceContext, unsigned short iChannel, unsigned char iBand);

   /******************************************************************************/
   /**
   GSM BER, Assign a GSM traffic channel and configure a loopback.  Before using this
   function, FTM_GSM_BER_AssignBCCH() should be completed successfully and if a CMU-200
   is being used, the "connect" command should be sent it.

      These low-level FTM operations are called and the associated events are verifed:
         CHANNEL_ASSIGN_REQ
         CONFIG_LOOPBACK_TYPE_REQ


      \param iLoopbackType (uses FTM_GSM_BER_LoopbackType_Enum)
      \code
          0 = Disable Loopback = FTM_GSM_BER_Disable_Loopback
          1 = Loopback Type A  = FTM_GSM_BER_Loopback_Type_A
          2 = Loopback Type B  = FTM_GSM_BER_Loopback_Type_B
          3 = Loopback Type C  = FTM_GSM_BER_Loopback_Type_C
      \endcode
      \param iSlot = Slot - TCH slot:
      \code
          0 = Slot 0
          1 = Slot 1
          2 = Slot 2
          3 = Slot 3
          4 = Slot 4
          5 = Slot 5
          6 = Slot 6
          7 = Slot 7
      \endcode
      NOTE: NOTE When using a BCCH+TCH simultaneous configuration (required), not all slots
      will be available for the TCH.

      \param iMode
      \code
          0 = SPEECH - FULL RATE = FTM_GSM_BER_SPEECH_FULL_RATE
          1 = SPEECH - HALF RATE = FTM_GSM_BER_SPEECH_HALF_RATE
          2 = SPEECH - ENHANCED FULL RATE = FTM_GSM_BER_SPEECH_ENHANCED_FULL_RATE
          3 = AMR - FULL RATE = FTM_GSM_BER_AMR_FULL_RATE
          4 = AMR - HALF RATE = FTM_GSM_BER_AMR_HALF_RATE
          5 = DATA - 14.4 KBPS FULL RATE = FTM_GSM_BER_DATA_14_4_KBPS_FULL_RATE
          6 = DATA - 9.6 KBPS FULL RATE FTM_GSM_BER_DATA_9_6_KBPS_FULL_RATE
      \endcode
         NOTE: Options 1-6 may not be supported by the FTM software.

   \param iStatus
      \code
          0 = Success (DIAG_FTM_STATUS_SUCCESS)
          1 = Failure (DIAG_FTM_STATUS_FAIL)
      \endcode

   \return true if network session is seutp successful, false if there are any failures

   \warning The active log mask will be changed to log only log FTM2 log packets.
            When the function is completed, the state of ASYNC logging will be enabled.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_AssignTraffic(
      HANDLE hResourceContext, unsigned short iLoopbackType,
      unsigned char iSlot, unsigned char iMode );

   /******************************************************************************/
   /**
   GSM BER, 2.4 FTM configuration loopback type request
      This command calls CONFIG_LOOPBACK_TYPE_REQ and checks the return status.

      This used to set the UE to one of the supported loopback modes.
      Currently the supported modes are Loopback A (TCH loop with signalling of
      erased frames), Loopback B (TCH loop without signalling of erased frames),
      and Loopback C (TCH burst by burst). The user should be able to change
      loopback modes directly (example: Loopback C to Loopback A) at any time on
      the TCH.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iLoopbackType (uses FTM_GSM_BER_LoopbackType_Enum)
      \code
          0 = Disable Loopback = FTM_GSM_BER_Disable_Loopback
          1 = Loopback Type A  = FTM_GSM_BER_Loopback_Type_A
          2 = Loopback Type B  = FTM_GSM_BER_Loopback_Type_B
          3 = Loopback Type C  = FTM_GSM_BER_Loopback_Type_C
      \endcode

   \return true if successful, false if fail.

   \warning The status return value in the FTM response packet will not be evaluated.  This is
            because some early versions of embedded software were not initializing this status
          response value.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_ConfigLoopbackType(
      HANDLE hResourceContext, unsigned short iLoopbackType );

   /******************************************************************************/
   /**
   GSM BER, perform a handover operation.  Before using this function, FTM_GSM_BER_StartCall()
   should be completed successfully and if a CMU-200 is being used, the "connect"
   command should be sent it.

   This command can e used in place of FTM_GSM_BER_AssignBCCH() and FTM_GSM_BER_AssignTraffic()
   within the same session, in order to begin a traffic connection for the 1st time in a session.

   It can also be used to perform a handover to a new band, once the first channel of GSM non-signaling
   traffic has been setup.

      These low-level FTM operations are called and the associated events are verifed:
         CHANNEL_ RECONFIGURE_REQ

   Note: even though the loopback type is a parameter, it is not used right now for optimization
         reasons.  If a loopback is assigned before the handover it will be kept active after the
        handover is completed.  QLIB_FTM_GSM_ConfigLoopbackType() can be used to control the
        loopback separately from this handover command.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChannel = RF channel. Valid range depends on band.
   \param iBand
      \code
          0 = PGSM 900 = FTM_GSM_BER_PGSM_900
          1 = EGSM 900 = FTM_GSM_BER_EGSM_900
          2 = PCS 1900 = FTM_GSM_BER_PCS_1900
          3 = DCS 1800 = FTM_GSM_BER_DCS_1800
          4 = CELL 850 = FTM_GSM_BER_CELL_850
      \endcode
   \param iTSC = Training Sequence number (0-7).  The same number is used for both UL and DL.
   \param iSlot = Slot - TCH slot:
      \code
          0 = Slot 0
          1 = Slot 1
          2 = Slot 2
          3 = Slot 3
          4 = Slot 4
          5 = Slot 5
          6 = Slot 6
          7 = Slot 7
      \endcode
      NOTE: NOTE When using a BCCH+TCH simultaneous configuration (required), not all slots
      will be available for the TCH.

   \param iMode
      \code
          0 = SPEECH - FULL RATE = FTM_GSM_BER_SPEECH_FULL_RATE
          1 = SPEECH - HALF RATE = FTM_GSM_BER_SPEECH_HALF_RATE
          2 = SPEECH - ENHANCED FULL RATE = FTM_GSM_BER_SPEECH_ENHANCED_FULL_RATE
          3 = AMR - FULL RATE = FTM_GSM_BER_AMR_FULL_RATE
          4 = AMR - HALF RATE = FTM_GSM_BER_AMR_HALF_RATE
          5 = DATA - 14.4 KBPS FULL RATE = FTM_GSM_BER_DATA_14_4_KBPS_FULL_RATE
          6 = DATA - 9.6 KBPS FULL RATE FTM_GSM_BER_DATA_9_6_KBPS_FULL_RATE
      \endcode
      NOTE: Options 1-6 may not be supported by the FTM software.

   \param iPowerLevel = the new PCL to set the Tx level to
      \param iLoopbackType (uses FTM_GSM_BER_LoopbackType_Enum)
         \code
           0 = Disable Loopback = FTM_GSM_BER_Disable_Loopback
           1 = Loopback Type A  = FTM_GSM_BER_Loopback_Type_A
           2 = Loopback Type B  = FTM_GSM_BER_Loopback_Type_B
           3 = Loopback Type C  = FTM_GSM_BER_Loopback_Type_C
         \endcode

   \param iStatus
      \code
          0 = Success (DIAG_FTM_STATUS_SUCCESS)
          1 = Failure (DIAG_FTM_STATUS_FAIL)
      \endcode

   \return true if all operations succeeded and the correct event messages were received

   \warning The active log mask will be changed to log only log FTM2 log packets.
            When the function is completed, the state of ASYNC logging will be enabled.

          In an automated sequence, if a call has already been established one time then
          QLIB_FTM_GSM_BER_IsTrafficValid should be called after issuing this command
          in order to verify that the traffic channel is currently active.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_Handover(
      HANDLE hResourceContext,
      unsigned short iChannel, unsigned char iBand, unsigned char iTSC, unsigned char iSlot,
      unsigned char iMode, unsigned char iPowerLevel,
      unsigned char  iLoopbackType
   );


   /******************************************************************************/
   /**
   GSM BER, perform a handover operation.  Before using this function, FTM_GSM_BER_StartCall()
   should be completed successfully and if a CMU-200 is being used, the "connect"
   command should be sent it.

   This command must also be preceded by successful calls to both FTM_GSM_BER_AssignBCCH() and
   FTM_GSM_BER_AssignTraffic() within the same session, in order to perform a handover to a new
   band, once the first channel of GSM non-signaling has been setup.

      This function calls these operations and checks for errors:
         FTM_GSM_CHANNEL_ASSIGN_REQ
         FTM_GSM_CONFIG_LOOPBACK_TYPE_REQ( DISABLE )
         FTM_CONFIG_LOOPBACK_TYPE_REQ( iLoopBackType )

   This version of the handover function does not change the loopback configuration.  This is an
   optimization for builds of AMSS for which the embedded software automatically handles the loopback
   configuration when the channel is reassigned.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChannel = RF channel. Valid range depends on band.
   \param iBand
      \code
          0 = PGSM 900 = FTM_GSM_BER_PGSM_900
          1 = EGSM 900 = FTM_GSM_BER_EGSM_900
          2 = PCS 1900 = FTM_GSM_BER_PCS_1900
          3 = DCS 1800 = FTM_GSM_BER_DCS_1800
          4 = CELL 850 = FTM_GSM_BER_CELL_850
      \endcode
   \param iSlot = Slot - TCH slot:
      \code
          0 = Slot 0
          1 = Slot 1
          2 = Slot 2
          3 = Slot 3
          4 = Slot 4
          5 = Slot 5
          6 = Slot 6
          7 = Slot 7
      \endcode
      NOTE: NOTE When using a BCCH+TCH simultaneous configuration (required), not all slots
      will be available for the TCH.

   \param iMode
      \code
          0 = SPEECH - FULL RATE = FTM_GSM_BER_SPEECH_FULL_RATE
          1 = SPEECH - HALF RATE = FTM_GSM_BER_SPEECH_HALF_RATE
          2 = SPEECH - ENHANCED FULL RATE = FTM_GSM_BER_SPEECH_ENHANCED_FULL_RATE
          3 = AMR - FULL RATE = FTM_GSM_BER_AMR_FULL_RATE
          4 = AMR - HALF RATE = FTM_GSM_BER_AMR_HALF_RATE
          5 = DATA - 14.4 KBPS FULL RATE = FTM_GSM_BER_DATA_14_4_KBPS_FULL_RATE
          6 = DATA - 9.6 KBPS FULL RATE FTM_GSM_BER_DATA_9_6_KBPS_FULL_RATE
      \endcode
      NOTE: Options 1-6 may not be supported by the FTM software.

   \param iPowerLevel = the new PCL to set the Tx level to
      \param iLoopbackType (uses FTM_GSM_BER_LoopbackType_Enum)
         \code
           0 = Disable Loopback = FTM_GSM_BER_Disable_Loopback
           1 = Loopback Type A  = FTM_GSM_BER_Loopback_Type_A
           2 = Loopback Type B  = FTM_GSM_BER_Loopback_Type_B
           3 = Loopback Type C  = FTM_GSM_BER_Loopback_Type_C
         \endcode

   \param iStatus
      \code
          0 = Success (COMMAND_SUCCESS)
          1 = Failure (COMMAND_FAILED)
      \endcode

   \return true if all operations succeeded and the correct event messages were received

   \warning The active log mask will be changed to log only log FTM2 log packets.
            When the function is completed, the state of ASYNC logging will be enabled.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_Handover_NoLoopbackConfig(
      HANDLE hResourceContext,
      unsigned short iChannel, unsigned char iBand, unsigned char iTSC, unsigned char iSlot,
      unsigned char iMode, unsigned char iPowerLevel
   );

   /******************************************************************************/
   /**
   GSM BER, Clear the internal status of the GSM BER structure

      Resets the contents of all fields in the internal GSM_BER_State state structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_ClearStatus( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   GSM BER, Returns a copy of the internal GSM BER state. On the internal copy
            it clears the "updated" fields for each message type so that the
          next time this funciton is called. Only items that been received
          since the first function call are marked as "updated."

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pGSM_BER_State = reference to a GSM_BER_State structure that will be  filled in with
                           the state information

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_GetStatus( HANDLE hResourceContext, unsigned char* pGSM_BER_State );

   /******************************************************************************/
   /**
   GSM BER, Returns a simplified status of whether a specified event has occured.

   The function operations upon the bHasUpdated array held in the GSM BER status
   structure (data type GSM_BER_State, as defined in QLib_Defines.h).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param eEventID = The input parameter is an index into this array, and the function
                      returns a true if the event has occured and false if it has not.

      Data type is log_FTM2_GSM_BER_log_id_enum, defined in QLib_Defines.h

      Values are:
      \code
          LOG_FTM2_START_GSM_MODE_CNF       = 0 = Start GSM confirm
          LOG_FTM2_SELECT_SPECIFIC_BCCH_CNF = 1 = FTM GSM BER select specific BCCH confirmation
          LOG_FTM2_START_IDLE_MODE_CNF      = 2 = FTM GSM BER start idle mode confirmation
          LOG_FTM2_CHANNEL_ASSIGN_CNF       = 3 = FTM GSM BER channel assign confirmation
          LOG_FTM2_CHANNEL_RELEASE_CNF      = 4 = FTM GSM BER channel release confirmation
          LOG_FTM2_STOP_GSM_MODE_CNF        = 5 = FTM GSM BER stop GSM mode confirmation
          LOG_FTM2_PH_DATA_IND              = 6 = FTM GSM BER Ph data indication
          LOG_FTM2_FTM_LOG_GSM_BER_DED_RPT  = 7 = FTM GSM BER dedicated measurement report
      \endcode


   \param pGSM_BER_State = reference to a GSM_BER_State structure that will be
                           filled in with the state information

   \return true the event type has occurred, false if it has not.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_GetEventStatus( HANDLE hResourceContext, unsigned char eEventID );

   /******************************************************************************/
   /**
   GSM BER, Returns the current Layer 1, RX Level.

   This function will wait until the next FTM_LOG_GSM_BER_DED_RPT message arrives,
   then return the status of that message.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piDED_RPtRxLev_Full = RxLev_Full as reported by Layer 1
   \param piDED_RPtRxQual_Full = RxQual_Full as reported by Layer 1


   More information about RX_QUAL:

   In brief, the mobile measures the Rx qual as defined in 3GPP 45.08.

   There are two rx qual thresholds calculated namely rx qual full and rx qual sub on the downlink
   radio bursts. These two measure the radio's downlink quality over a single reporting period and
   report the measurements to the network ( measurement reporting period is104 frames for tch channel)
   so that the network has some information as to 'how the mobile see's the downlink radio quality'.

   Rx qual full is where the mobile makes quality threshold measurements on all downlink burst, ie tch,
   facch and sacch blocks utilizing burst information from the equalizer output for all 104 bursts
   on the downlink.

   Rx Qual Sub is a sub set of these 104 bursts. This is where the mobile only uses for quality
   measurements the SACCH blocks and the Silent Identifier (SID) frames. This is the scenario where
   there is no speech or signaling frames on the downlink to measure the downlink quality. The mobile
   will always have information in these frames as the network will always send SACCH frames and if no
   signaling or speech frames to transmit then it sends SID frames at specific radio blocks instead of
   signaling or speech frames, these frames are identified as SID frames. This Rx Qual sub is therefore
   an accurate measure of the quality of the downlink on a subset of the 104 burst.

   Therefore in a measurement report from the mobile to the network, the rx qual full might be 7
   (ie poor) and the rx sub might be 0 (ie good) when no signaling/speech information is on the downlink.

   PRBS would imply signal being generated all the time and hence the rx qual full would be 0, ie a
   full set of downlink bursts to process.

   ECHO would imply some silence in the downlink and hence the rx qual full would be 7 as
   there is poor data to measure quality on

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_GetRxMetrics(
      HANDLE hResourceContext, unsigned char* piDED_RPtRxLev_Full, unsigned char* piDED_RPtRxQual_Full );

   /******************************************************************************/
   /**
   GSM BER, Returns the status of the GSM traffic channel

   Use this function after GSM TCH has been assigned.

   Will return true if the last PH_DATA_IND message for the SACCH type had a valid CRC_PASS
   AND if the SACCH accumulator is > 0.

   The SACCH accumulator begins at a value of 40 when QLIB_FTM_GSM_BER_ClearStatus() is
   called.  It is then decremented by 1 if an invalid SACCH CRC is reported and incremented
   by 2 for each valid SACCH CRC.  The accumulator will saturate at 0 on the low end
   and 40 on the high end.

   The user can change the maximum value (normally 40) by calling QLIB_FTM_GSM_BER_SetSACCH_AccumulatorMax()

   This specification for this logic comes from the 3GPP document 45.008, in the
   "radio link failure" section.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return pass/fail according to the rules above.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_IsTrafficValid(   HANDLE hResourceContext );

   /******************************************************************************/
   /**
   GSM BER, Sets the maximum value for the SACCH accumulator.

   See the description for QLIB_FTM_GSM_BER_IsTrafficValid() for how the accumulator
   works

   Default value in the system is 40.  This function does not need to be called unless
   the user desires a value other than 40.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSACCH_AccumulatorMax = new SACCH accumulator maximum value to be used for QLIB_FTM_GSM_BER_IsTrafficValid()

   \return true if successful, false if failure

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_SetSACCH_AccumulatorMax( HANDLE hResourceContext, short iSACCH_AccumulatorMax );

   /******************************************************************************/
   /**
   GSM BER, Release the GSM channel and optionally stop a GSM Non-signaling session.

      This low-level FTM operation is called and the associated event are verifed:
         CHANNEL_RELEASE_REQ

   \return true if all operations succeeded and the correct event messages were received

   \warning If further GSM BER sessions will occur before the phone is reset, then
            the traffic loopback should be disabled using QLIB_FTM_GSM_ConfigLoopbackType()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_ReleaseTCH( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   GSM BER, close the GSM Non-signaling session.

      This low-level FTM operation is called and the associated event are verifed:
         STOP_GSM_MODE_REQ

      Note: this command does not wait for the asynchronous stop responds because
            some versions of software do not have this enabled and the response
           is low priority for this commands, compared to other commands such
           as traffice assign and handover.

      This function also calls QLIB_FTM_LOG_StopFTM_Log( HANDLE, LOG_FTM2_LOG_GSM_BER )
      to disable the FTM log that was started in QLIB_FTM_GSM_BER_StartSession

   \return true if all operations succeeded and the correct event messages were received

   \warning 1. This function will disable async logging and clear the async queue.
            2. If further GSM BER sessions will occur before the phone is reset, then
               the traffic loopback should be disabled using QLIB_FTM_GSM_ConfigLoopbackType()


   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_StopSession( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   GSM BER, Clear BER event status, Section 3.9 FTM Reset Event Status

      This command send FTM command to clear the event status.

      This command clears event status that is used for QLIB_FTM_GSM_BER_EVENT_STATUS_REQ function,

      This function could be called before the GSM BER function that generates the event.
      For example, QLIB_FTM_GSM_BER_AssignBCCH

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iStatus = 0 - COMMAND_SUCCESS
                   1 - COMMAND_FAILED
      \warning

      \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_EVENT_STATUS_CLEAR_REQ( HANDLE hResourceContext, unsigned short* iStatus );


   /******************************************************************************/
   /**
   GSM BER, Wait for event, Section 3.10

      This command waits for a specified GSM Layer 1 event to occur or until a timeout expires.
      This command is used to synchronize events so that use of the asynchronous messages are not required

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iEventType = See FTM_GSM_BER_EVENT_STATUS_Enum in QLib_Defines.h

                     0 - FTM_GSM_BER_START_GSM_MODE_SYNC_STATUS
                     1 - FTM_GSM_BER_SELECT_SPECIFIC_BCCH_CNF_SYNC_STATUS
                     2 - FTM_GSM_BER_START_IDLE_MODE_SYNC_STATUS
                     3 - FTM_GSM_BER_CHANNEL_ASSIGN_SYNC_STATUS
                     4 - FTM_GSM_BER_CHANNEL_RELEASE_SYNC_STATUS
                     5 - FTM_GSM_BER_STOP_GSM_MODE_SYNC_STATUS
                     6 - FTM_GSM_BER_SACCH_SYNC_STATUS

      \param iTimeOut_ms = Timeout to use for waiting for the event. Units are milliseconds.

      \param iStatus =   0  FTM_GSM_BER_SYNC_STATUS_SUCCESS
                     1  FTM_GSM_BER_SYNC_STATUS_GEN_FAILURE
                     2  FTM_GSM_BER_SYNC_STATUS_TIMEOUT_EXPIRED
                     3  FTM_GSM_BER_SYNC_STATUS_EVENT_STATUS_FAILED

      \warning

      \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_EVENT_STATUS_REQ(HANDLE hResourceContext,unsigned char iEventType, unsigned long iTimeOut_MS, unsigned short* iStatus);

   /******************************************************************************/
   /**
   GSM BER, Wait for event, Section 3.11

   This command returns the current receive power in RSSI and dBm.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus =   0  Command Success
                  1  Command Fail

   \param iRSSI   = RSSI value

   \param iRxPwr_indBm16 = Rx power in 1/16 dBm units.
                           this is a signed number

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_RX_LEVEL_REQ(HANDLE hResourceContext, unsigned short* iStatus, unsigned long *iRSSIValue, short* iRxPwr_in16dBm);

   /******************************************************************************/
   /**
   GSM BER, Wait for event, Section 3.11

   This command returns the current receive power in RSSI and dBm for both the paths.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus =   0  Command Success
                    1  Command Fail

   \param iPRxRSSI   = PRx RSSI value

   \param iPRxPwr_indBm16 = PRx Rx power in 1/16 dBm units.
                            this is a signed number

   \param iDRxRSSI   = DRx RSSI value

   \param iDRxPwr_indBm16 = DRx Rx power in 1/16 dBm units.
                            this is a signed number

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_BER_RX_LEVEL_REQ_V2(HANDLE hResourceContext, unsigned short* iStatus, unsigned long *iPRxRSSIValue, short* iPRxPwr_indBm16, unsigned long *iDRxRSSIValue, short* iDRxPwr_indBm16);

   /******************************************************************************
                     High level EGPRS BER FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   The only difference   between this function and FTM_GSM_BER_AssignBCCH is that
   this function goes into EGRPS IDLE mode instead of GSM Idle mode.

    Before this function is called, FTM_GSM_BER_StartSession
   must be called.  When the function is completed, the phone will be in the IDLE
   state.

   This function must be called before FTM_EGPRS_BER_StartIdleMode

      These low-level FTM operations are called and the associated events are verifed:
         SELECT_SPECIFIC_BCCH_REQ
         FTM_EGPRS_BER_START_GPRS_IDLE_MODE_REQ

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iChannel = RF channel. Valid range depends on band.
      \param iBand
         \code
           0 = PGSM 900 = FTM_GSM_BER_PGSM_900
           1 = EGSM 900 = FTM_GSM_BER_EGSM_900
           2 = PCS 1900 = FTM_GSM_BER_PCS_1900
           3 = DCS 1800 = FTM_GSM_BER_DCS_1800
           4 = CELL 850 = FTM_GSM_BER_CELL_850
         \endcode

   \return true if network session is setup successful, false if there are any failures

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_AssignBCCH(
      HANDLE hResourceContext, unsigned short iChannel, unsigned char iBand );

   /******************************************************************************/
   /**
   EGPRS BER, Start a EGPRS BER session by putting the phone into EGPRS Idle mode.
   Before this function is called, a valid   GSM BER session must be active.

      These low-level FTM operations are called and the associated events are verifed:
         FTM_EGPRS_BER_START_GPRS_IDLE_MODE_REQ

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if network session is setup successful, false if there are any failures

   \warning The active log mask will be changed to log only log FTM2 log packets.
            When the function is completed, the state of ASYNC logging will be enabled.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_StartIdleMode( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   High level EGPRS BER, calls FTM_EGPRS_BER_CONFIGURE_DL_TBF, and checks the status of
   the command response.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDL_TSC - Training sequence code for use on DL PDCH
   \param iDL_TFI - Expected temporary flow ID for use on DL PDCH. During the
                   SRB loop the UE actually ignores the received TFI, so this can
                   be fixed to 0.
   \param iChannel - Channel number for both downlink and uplink TBFs. Valid
                     range depends on band.
   \param iBand - Band information for both downlink and uplink TBFs
      \code
           0 = PGSM 900
           1 = EGSM 900
           2 = PCS 1900
           3 = DCS 1800
           4 = CELL 850
      \endcode


   \param bFirstSlotActive - First active slot flag. unsigned charean to indicate if the timeslot configuration is valid.
                             This should always be TRUE, since the feature currently supports   only one DL slot.

   \param iFirstSlotNum - First active timeslot number - Valid range is 0-7. This indicates the timeslot of the DL PDCH,
                                and will only be read if first active slot flag is TRUE.

   \param bSecondSlotActive - Second active slot flag - unsigned charean to indicate if the timeslot configuration is valid. This
                              should always be FALSE, since the feature does not currently
                              support a 2 DL configuration.
   \param bSecondSlotNum - Second active timeslot number - Valid range is 0-7. This indicates the timeslot of the DL PDCH,
                           and will only be read if second active slot flag is TRUE.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_Configure_DL_TBF(
      HANDLE hResourceContext,
      unsigned char iDL_TSC,
      unsigned char iDL_TFI,
      unsigned short iChannel,
      unsigned char iBand,
      unsigned char bFirstSlotActive,
      unsigned char iFirstSlotNum,
      unsigned char bSecondSlotActive,
      unsigned char iSecondSlotNum
   );


   /******************************************************************************/
   /**
   High level EGPRS BER, calls FTM_EGPRS_BER_CONFIGURE_UL_TBF, and checks the status of
   the command response.

   This command sends the configuration for the UL TBF to the UE. The embedded software will
   store this configuration for use when the SRB loop is established.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iUL_TSC - Training sequence code for use on UL PDCH

   \param iUSF - Uplink state flag assigned to the UE. During the SRB loop the
                 UE actually ignores the received USF, so this can be set to 0.

   \param iGamma - GAMMA_TN value.  It is a basically sets the attenuation level relative to max power
                   for a band, in unts of 2dB.

               Valid range is 0-31. This maps to the GAMMA_TN value in
                  3GPP TS 44.060. This sets the uplink power level based on the
                   equation given in 3GPP TS 45.008, section 10.2. The embedded software
                   uses an gamma parameter of 0.

                   The GAMMA_TN field is the binary representation of the parameter *CH for MS output
               power control in units of 2 dB, see 3GPP TS 45.008. The GAMMA_TN field is coded
               according to the following table:
      \code
         bit
         5 4 3 2 1
         0 0 0 0 0   *CH = 0 dB
         0 0 0 0 1   *CH = 2 dB
         : : : :
         1 1 1 1 0   *CH = 60 dB
         1 1 1 1 1   *CH = 62 dB
      \endcode

   \param bFirstSlotActive - First active slot flag. unsigned charean to indicate if the timeslot configuration is valid.
                             This should always be TRUE, since the feature currently supports   only one DL slot.

   \param iFirstSlotNum - First active timeslot number - Valid range is 0-7. This indicates the timeslot of the DL PDCH,
                                and will only be read if first active slot flag is TRUE.

   \param bSecondSlotActive - Second active slot flag - unsigned charean to indicate if the timeslot configuration is valid.
                              This should always be FALSE, since the feature does not currently
                              support a 2 DL configuration.
   \param bSecondSlotNum - Second active timeslot number - Valid range is 0-7. This indicates the timeslot of the DL PDCH,
                           and will only be read if second active slot flag is TRUE.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_Configure_UL_TBF(
      HANDLE hResourceContext,
      unsigned char iUL_TSC,
      unsigned char iUSF,
      unsigned char iGamma,
      unsigned char bFirstSlotActive,
      unsigned char iFirstSlotNum,
      unsigned char bSecondSlotActive,
      unsigned char iSecondSlotNum
   );


   /******************************************************************************/
   /**
   High level EGPRS BER, calls FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK, and handles all
   related events.

   After the DL and UL TBFs have been configured, the user should issue this command to establish
   the TBFs and close the SRB loop.

   Also calls QLIB_FTM_EGPRS_BER_ClearStatus() to clear all EGPRS status.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_Establish_SRB_LOOPBACK( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   High level EGPRS BER, calls FTM_EGPRS_BER_RELEASE_ALL_TBF, and handles all
   related events.

   This command directs the UE to release the UL and DL TBFs. This should only be issued when
   the UE is connected to the PDCH.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_Release_All_TBF( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   EGPRS BER, Clear the internal status of the EGPRS BER structure

      Resets the contents of all fields in the internal EGPRS_BER_State state structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_ClearStatus( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   EGPRS BER, Returns a copy of the internal EGPRS BER state. On the internal copy
            it clears the "updated" fields for each message type so that the
          next time this funciton is called. Only items that been received
          since the first function call are marked as "updated."

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pEGPRS_BER_State = reference to a EGPRS_BER_State structure that will be
                           filled in with the state information.
                     The structure type pointed to is EGPRS_BER_State

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_GetStatus(HANDLE hResourceContext, unsigned char* pEGPRS_BER_State );

   /******************************************************************************/
   /**
   High level EGPRS BER, calls FTM_EGPRS_BER_EXEC_VFS_REQ, and checks the status of
   the command response.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  iNumSegments = Input, Number of segments
   \param  aiNumFramesInSeg = Input, List of Number of frames in segments
   \param  aiSegGamma = Input, List of Gamma of segments
   \param  aiSegBand = Input, List of Bands of Segments
   \param  aiSegChan = Input, List of Channel numbers of segments.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_EXEC_VFS(
      HANDLE hResourceContext,
      unsigned char iNumSegments,
      unsigned char* aiNumFramesInSeg,
      unsigned char* aiSegGamma,
      unsigned char* aiSegBand,
      unsigned short*  aiSegChan
   );

   /******************************************************************************/
   /**
   EGPRS BER, Returns the current Layer 1, RX Level.

   This function will wait until the next FTM_LOG_EGPRS_BER_DED_RPT message arrives,
   then return the status of that message.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRxLev_average = RxLev_average as reported by Layer 1. Range should be 0-63.

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_GetRxMetrics( HANDLE hResourceContext, unsigned char* piRxLev_average );

   /******************************************************************************/
   /**
   EGPRS BER (80-V5529-1), Section 2.3.8, FTM Reset Event Status

   This command clears event status that is used for the FTM Wait For Event function.

   This function could be called before the EDGE BER function that generates the event. For
   example, before the FTM_EGPRS_BER_CONFIGURE_DL_TBF function described in section

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus = 0 - COMMAND_SUCCESS
                    1 - COMMAND_FAILED

   \return true if all operations succeeded and the correct event messages were received

   \warning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_EVENT_STATUS_CLEAR_REQ ( HANDLE hResourceContext, unsigned short *iStatus);

   /******************************************************************************/
   /**
   EGPRS BER (80-V5529-1), Section 2.3.8, FTM Wait For Event

   This command waits for a specified GSM Layer 1 event to occur or until a timeout expires. This
   command is used to synchronize events so that use of the asynchronous messages are not
   required

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iEventType = Event for establishing/releasing UL/DL TBF

                  See FTM_EGRPS_BER_EVENT_STATUS_Enum in QLib_Defines.h

                  0  FTM_EGPRS_BER_UL_TBF_ESTABLISHED_SYNC_STATUS
                  1  FTM_EGPRS_BER_UL_TBF_RELEASED_SYNC_STATUS
                  2  FTM_EGPRS_BER_DL_TBF_ESTABLISHED_SYNC_STATUS
                  3  FTM_EGPRS_BER_DL_TBF_RELEASED_SYNC_STATUS

    \param iTimeout_ms = Timeout to use for waiting for the event. Units are milliseconds.

   \param iStatus = Status whether the wait of success or not

                  0 - FTM_EGPRS_BER_SYNC_STATUS_SUCCESS
                  1  FTM_EGPRS_BER_SYNC_STATUS_GEN_FAILURE
                  2  FTM_EGPRS_BER_SYNC_STATUS_TIMEOUT_EXPIRED
                  3  FTM_EGPRS_BER_SYNC_STATUS_EVENT_STATUS_FAILED

   \return true if all operations succeeded and the correct event messages were received

   \warning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_EVENT_STATUS_REQ ( HANDLE hResourceContext,
         unsigned char iEvent_Type,
         unsigned long iTimeout_ms,
         unsigned short *iStatus);
   /******************************************************************************/
   /**
   GSM BER, Start a GSM BER session. (80-V3951-1, START_GSM_MODE_REQ)

   This function sends START_GSM_MODE_REQ command to mobile

   This command starts the GSM Layer 1 task from an inactive state. This initializes the Layer 1 subsystem and the drivers

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return

   \note This function can be used in QMSL FTM Sequencer operation

   \wanrning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_START_MODE_REQ (HANDLE hResourceContext, unsigned short *iStatus);
   /******************************************************************************/
   /**
   GSM BER, Acquire BCCH (80-V3951-1, SELECT_SPECIFIC_BCCH_REQ)

   This function sends START_GSM_MODE_REQ command to mobile

   This command allows the user to acquire timing and decode BCCH data on a specific RF channel.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus 0 == Command Success
               1 == Command Failed

   \param iChannel = RF channel. Valid range depends on band.
      \param iBand
         \code
           0 = PGSM 900 = FTM_GSM_BER_PGSM_900
           1 = EGSM 900 = FTM_GSM_BER_EGSM_900
           2 = PCS 1900 = FTM_GSM_BER_PCS_1900
           3 = DCS 1800 = FTM_GSM_BER_DCS_1800
           4 = CELL 850 = FTM_GSM_BER_CELL_850
         \endcode

   \return

   \wanrning

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_SELECT_SPECIFIC_BCCH_REQ(HANDLE hResourceContext, unsigned short iChannel, unsigned char iBand, unsigned short *iStatus);

   /******************************************************************************/
   /**
   EGPRS(EDGE) BER, Acquire BCCH (80-V5529-1, FTM_EGPRS_BER_START_GPRS_IDLE_MODE_REQ)

   This function sends FTM_EGPRS_BER_START_GPRS_IDLE_MODE_REQ command to mobile

   This command directs the UE to enter GPRS Idle mode. This should be done after the UE has successfully started GSM services and acquired the BCCH

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return

   \wanrning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_START_GPRS_IDLE_MODE_REQ(HANDLE hResourceContext, unsigned char* iStatus);
   /******************************************************************************/
   /**
   GSM BER, Stop a GSM BER session. (80-V3951-1, STOP_GSM_MODE_REQ)

   This function sends STOP_GSM_MODE_REQ to mobile

   This command stops the GSM Layer 1 services and returns the UE to the Inactive state. If the user has previously given a Start GSM mode request, the user must issue this command before proceeding to other FTM tests

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return

   \wanrning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_STOP_GSM_MODE_REQ (HANDLE hResourceContext, unsigned short *iStatus);

   /******************************************************************************/
   /**
   EGPRS (EDGE) BER, 80-V5529-1, FTM_EGPRS_BER_CONFIGURE_DL_TBF

   This function sends FTM_EGPRS_BER_CONFIGURE_DL_TBF command to mobile

   This command sends the configuration for the DL TBF to the UE. The embedded software stores this configuration for use when the SRB loop is established using the FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command. This command must be sent before the FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command is sent. The channel selected should match the PDCH configuration on the test box and does not need to match the BCCH channel.
   This command should also be used to buffer a DL TBF configuration when the user needs to reconfigure the SRB loop (handover).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDL_TSC - Training sequence code for use on DL PDCH
   \param iDL_TFI - Expected temporary flow ID for use on DL PDCH. During the
                   SRB loop the UE actually ignores the received TFI, so this can
                   be fixed to 0.
   \param iChannel - Channel number for both downlink and uplink TBFs. Valid
                     range depends on band.
   \param iBand - Band information for both downlink and uplink TBFs
      \code
           0 = PGSM 900
           1 = EGSM 900
           2 = PCS 1900
           3 = DCS 1800
           4 = CELL 850
      \endcode


   \param bFirstSlotActive - First active slot flag. unsigned charean to indicate if the timeslot configuration is valid.
                             This should always be TRUE, since the feature currently supports   only one DL slot.

   \param iFirstSlotNum - First active timeslot number - Valid range is 0-7. This indicates the timeslot of the DL PDCH,
                                and will only be read if first active slot flag is TRUE.

   \param bSecondSlotActive - Second active slot flag - unsigned charean to indicate if the timeslot configuration is valid. This
                              should always be FALSE, since the feature does not currently
                              support a 2 DL configuration.
   \param bSecondSlotNum - Second active timeslot number - Valid range is 0-7. This indicates the timeslot of the DL PDCH,
                           and will only be read if second active slot flag is TRUE.

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_CONFIGURE_DL_TBF(         HANDLE hResourceContext,
         unsigned char iDL_TSC,
         unsigned char iDL_TFI,
         unsigned short iChannel,
         unsigned char iBand,
         unsigned char bFirstSlotActive,
         unsigned char iFirstSlotNum,
         unsigned char bSecondSlotActive,
         unsigned char iSecondSlotNum,
         unsigned char* iStatus );
   /******************************************************************************/
   /**
   EGPRS (EDGE) BER, 80-V5529-1. FTM_EGPRS_BER_CONFIGURE_UL_TBF

   This function sends FTM_EGPRS_BER_CONFIGURE_UL_TBF command to mobile

   This command sends the configuration for the UL TBF to the UE. The embedded software stores this configuration for use when the SRB loop is established using the FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command. This command must be sent before the FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command is sent.
   This command should also be used to buffer a UL TBF configuration when the user needs to reconfigure the SRB loop (handover).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iUL_TSC - Training sequence code for use on UL PDCH

   \param iUSF - Uplink state flag assigned to the UE. During the SRB loop the
                 UE actually ignores the received USF, so this can be set to 0.

   \param iGamma - GAMMA_TN value.  It is a basically sets the attenuation level relative to max power
                   for a band, in unts of 2dB.

               Valid range is 0-31. This maps to the GAMMA_TN value in
                  3GPP TS 44.060. This sets the uplink power level based on the
                   equation given in 3GPP TS 45.008, section 10.2. The embedded software
                   uses an gamma parameter of 0.

                   The GAMMA_TN field is the binary representation of the parameter *CH for MS output
               power control in units of 2 dB, see 3GPP TS 45.008. The GAMMA_TN field is coded
               according to the following table:
      \code
         bit
         5 4 3 2 1
         0 0 0 0 0   *CH = 0 dB
         0 0 0 0 1   *CH = 2 dB
         : : : :
         1 1 1 1 0   *CH = 60 dB
         1 1 1 1 1   *CH = 62 dB
      \endcode

   \param bFirstSlotActive - First active slot flag. unsigned charean to indicate if the timeslot configuration is valid.
                             This should always be TRUE, since the feature currently supports   only one DL slot.

   \param iFirstSlotNum - First active timeslot number - Valid range is 0-7. This indicates the timeslot of the DL PDCH,
                                and will only be read if first active slot flag is TRUE.

   \param bSecondSlotActive - Second active slot flag - unsigned charean to indicate if the timeslot configuration is valid.
                              This should always be FALSE, since the feature does not currently
                              support a 2 DL configuration.
   \param bSecondSlotNum - Second active timeslot number - Valid range is 0-7. This indicates the timeslot of the DL PDCH,
                           and will only be read if second active slot flag is TRUE.

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_CONFIGURE_UL_TBF(   HANDLE hResourceContext,
         unsigned char iUL_TSC,
         unsigned char iUSF,
         unsigned char iGamma,
         unsigned char bFirstSlotActive,
         unsigned char iFirstSlotNum,
         unsigned char bSecondSlotActive,
         unsigned char iSecondSlotNum,
         unsigned char* iStatus );
   /******************************************************************************/
   /**
   EGPRS (EDGE) BER, 80-V5529-1, FTM_EGPRS_BER_CONFIGURE_DL_TBF_V2

   This function sends FTM_EGPRS_BER_CONFIGURE_DL_TBF_V2 command to mobile

   This command sends the configuration for the DL TBF to the UE. This is Ver 2 of the configure DL TBF command,
   which allows the configuration of more slots to support different EGPRS multislot classes.
   The user must configure a valid DL and UL TBF according to the UEs multislot capability.
   For example, in a class 10 UE, the user may not enable more than 4 DL slots using this command or more than 5 total slots (UL and DL).

   The embedded software stores this configuration for use when the SRB loop is established using the FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command. This command must be sent before the FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command is sent. The channel selected should match the PDCH configuration on the test box and does not need to match the BCCH channel.
   This command should also be used to buffer a DL TBF configuration when the user needs to reconfigure the SRB loop (handover).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDL_TSC - Training sequence code for use on DL PDCH
   \param iDL_TFI - Expected temporary flow ID for use on DL PDCH. During the
                   SRB loop the UE actually ignores the received TFI, so this can
                   be fixed to 0.
   \param iChannel - Channel number for both downlink and uplink TBFs. Valid
                     range depends on band.
   \param iBand - Band information for both downlink and uplink TBFs
      \code
           0 = PGSM 900
           1 = EGSM 900
           2 = PCS 1900
           3 = DCS 1800
           4 = CELL 850
      \endcode

   \param pSlotConfiguration, pointer to the GSM_EGPRS_CONFIGURE_DL_TBF_V2_Slot_Configuration defined in QLib_Defines.h

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_CONFIGURE_DL_TBF_V2(      HANDLE hResourceContext,
         unsigned char iDL_TSC,
         unsigned char iDL_TFI,
         unsigned short iChannel,
         unsigned char iBand,
         void * pSlotConfiguration,
         unsigned short* iStatus );

   /******************************************************************************/
   /**
   EGPRS (EDGE) BER, 80-V5529-1, FTM_EGPRS_BER_CONFIGURE_UL_TBF_V2

   This function send FTM_EGPRS_BER_CONFIGURE_UL_TBF_V2 to the mobile

   This command sends the configuration for the UL TBF to the UE. This is Ver 2 of the configure UL TBF command, which allows the configuration of more slots to support different EGPRS multislot classes.
   The user must configure a valid DL and UL TBF according to the UEs multislot capability.

   The embedded software stores this configuration for use when the SRB loop is established using the FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command.
   This command must be sent before the FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command is sent.
   This command should also be used to buffer a UL TBF configuration when the user needs to reconfigure the SRB loop (handover).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iUL_TSC - Training sequence code for use on UL PDCH

   \param iUSF - Uplink state flag assigned to the UE. During the SRB loop the
                 UE actually ignores the received USF, so this can be set to 0.

   \param pSlotConfiguration, pointer to the GSM_EGPRS_CONFIGURE_UL_TBF_V2_Slot_Configuration defined in QLib_Defines.h

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_CONFIGURE_UL_TBF_V2(   HANDLE hResourceContext,
         unsigned char iUL_TSC,
         unsigned char iUSF,
         void * pSlotConfiguration,
         unsigned short* iStatus );

   /******************************************************************************/
   /**
   EGPRS (EDGE) BER, 80-V5529-1, FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK

   This function sends FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK command to mobile

   After the DL and UL TBFs have been configured, the user should issue this command to establish the TBFs and close the SRB loop

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_ESTABLISH_SRB_LOOPBACK (HANDLE hResourceContext, unsigned char* iStatus);

   /******************************************************************************/
   /**
   EGPRS (EDGE) BER, 80-V5529-1, FTM_EGPRS_BER_RELEASE_ALL_TBF

   This function send FTM_EGPRS_BER_RELEASE_ALL_TBF to the mobile

   This command directs the UE to release the UL and DL TBFs. This should only be issued when the UE is connected to the PDCH

   \param iStatus 0 == Command Success
               1 == Command Failed

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_EGPRS_BER_RELEASE_ALL_TBF(HANDLE hResourceContext, unsigned char* iStatus);


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_LTE_NS_H)
