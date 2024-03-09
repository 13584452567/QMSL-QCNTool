/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_WCDMA_NS.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_WCDMA_NS
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_WCDMA_NS_H)
#define _QMSL_FTM_WCDMA_NS_H

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
                     WCDMA BER FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   WCDMA BER, Start a WCDMA BER session. After this function is called, the acquisition
   function will need to be called, FTM_WCDMA_BER_Acquire.

      This function calls these operations and checks for errors:
         QLIB_FTM_WCDMA_BER_ClearStatus

      These low-level FTM operations are called and the associated events are verifed:
         START_WCDMA_MODE_REQ

      If the first START_WCDMA_MODE_REQ call fails, because a physical channel is
      already setup, then the function will call STOP_WCDMA_MODE_REQ and try to
      re-start the WCDMA non-signaling session.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTimeOut_ms = millisecond timeout for all WCDMA BER operations.  This should
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
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_StartSession(   HANDLE hResourceContext, unsigned long iTimeOut_ms );

   /******************************************************************************/
   /**
   WCDMA BER, acquire a downlink pilot.  Before this function is called,
   FTM_WCDMA_BER_StartSession must be called.  When the function is completed, the
   phone will be in the IDLE state.


   These low-level FTM operations are called and the associated events are verifed:
      ACQUIRE_REQ

      START_WCDMA_IDLE_REQ - will be called if any RMC channels have been setup sinc
      the last time that ACQUIRE_REQ has been called.

   This function will automatically retry the downlink acquisition up to 5 times, for the
   very first acquisition after the QLIB_FTM_WCDMA_BER_StartSession() is called.
   This is necessary because there are some layer 1 reasons why the first acquisition
   may not be successful immediately. In testing of 1000 attempts, it was to not
   explicitly issue an WCDMA_BER_IDLE command because this command is not necessary.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChannel = WCDMA RF channel

   \return true if network session is setup successful, false if there are any failures

   \warning Default values are used for the following:
      \code
          iAcqType = FTM_WCDMA_BER_AcqTypeFreqOnly
          iAcqMode = FTM_WCDMA_BER_AcqModeFull
          iScrCode = 0
          iPN_Pos  = 0
      \endcode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_AcquirePilot( HANDLE hResourceContext, unsigned short iChannel );

   /******************************************************************************/
   /**
   WCDMA BER, go to IDLE mode.

      This function calls these operations and checks for errors:
         FTM_WCDMA_START_IDLE_MODE_REQ

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if idle mode has been entered successfully, false if there are any failures

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_Idle( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   WCDMA BER, Setup a RMC DCH channel.  This must be done after the
   FTM_WCDMA_BER_AcquirePilot function has completed successfully.

      This low-level FTM operation is called and the associated event is verifed:
         RMC_DCH_SETUP_REQ

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRMC_Type (refer to FTM_WCDMA_BER_RMC_Type_Enum)
      \code
         FTM_WCDMA_BER_RMC_Type12_2kpbs            = 0,   //<!' RMC 12.2 kbps channel
         FTM_WCDMA_BER_RMC_Type64kbps            = 1,   //<!' RMC 64 kbps channel
         FTM_WCDMA_BER_RMC_Type384kpbs            = 2,   //<!' RMC 384 kbps channe (Not currently supported)
         FTM_WCDMA_BER_RMC_Type12_2kpbs_Symmetric   = 3,   //<!' RMC 12.2 kbps channel, block size in the DL and UL is the same
         FTM_WCDMA_BER_RMC_Type64kbps_Symmetric      = 4,   //<!' RMC 64 kbps channel, block size in the DL and UL is the same
         FTM_WCDMA_BER_RMC_Type384kbps_Symmetric      = 5      //<!' RMC 384 kbps channel, block size in the DL and UL is the same
         Note: For first 3 data rate enumeration, UL CRC bits are looped back from DL
         Note: For last  3 data rate enumeration, UL CRC is valid and computed based on Rx data bits
      \endcode
   \param iUL_MaxTxPwr = Maximum transmit power in dBm.

   \param iUL_DPCH_ScrCode = Scrambling code to use for the uplink.
   \param iUL_PCA (refer FTM_WCDMA_BER_PCA_Size_Enum)
      \code
          FTM_WCDMA_BER_PCA_Type_Alg1 = 0 = Power control algorithm 1
          FTM_WCDMA_BER_PCA_Type_Alg2 = 1 = Power control algorithm 2
      \endcode
   \param iUL_TPC_StepSize
      \code
         FTM_WCDMA_BER_PCA_Size_1dB = 0 = Stepsize 1 dB
         FTM_WCDMA_BER_PCA_Size_2dB = 1 = Stepsize 2 dB
      \endcode
   \param iDL_PriCPICH_Scr_Code = Primary CPICH downlink scrambling code.
   \param iDL_ChanCode = Downlink DPCH channelization code.

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_SetupRMC_DCH(
      HANDLE hResourceContext,
      unsigned char iRMC_Type, unsigned char iUL_MaxTxPwr, unsigned long iUL_DPCH_ScrCode, unsigned char iUL_PCA,
      unsigned char iUL_TPC_StepSize, unsigned short iDL_PriCPICH_Scr_Code, unsigned short iDL_ChanCode );

   /******************************************************************************/
   /**
   WCDMA BER, handover to a new RMC DCH channel.  This must be done after the
   QLIB_FTM_WCDMA_BER_SetupRMC_DCH function has completed successfully.

      This low-level FTM operation is called and the associated event is verifed:
         RMC_DCH_SETUP_REQ_V2

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRMC_Type (refer to FTM_WCDMA_BER_RMC_Type_Enum)
      \code
         FTM_WCDMA_BER_RMC_Type12_2kpbs            = 0,   //<!' RMC 12.2 kbps channel
         FTM_WCDMA_BER_RMC_Type64kbps            = 1,   //<!' RMC 64 kbps channel
         FTM_WCDMA_BER_RMC_Type384kpbs            = 2,   //<!' RMC 384 kbps channe (Not currently supported)
         FTM_WCDMA_BER_RMC_Type12_2kpbs_Symmetric   = 3,   //<!' RMC 12.2 kbps channel, block size in the DL and UL is the same
         FTM_WCDMA_BER_RMC_Type64kbps_Symmetric      = 4,   //<!' RMC 64 kbps channel, block size in the DL and UL is the same
         FTM_WCDMA_BER_RMC_Type384kbps_Symmetric      = 5      //<!' RMC 384 kbps channel, block size in the DL and UL is the same
         Note: For first 3 data rate enumeration, UL CRC bits are looped back from DL
         Note: For last  3 data rate enumeration, UL CRC is valid and computed based on Rx data bits
      \endcode
   \param iUL_MaxTxPwr = Maximum transmit power in dBm.

   \param iUL_DPCH_ScrCode = Scrambling code to use for the uplink.
   \param iUL_PCA (refer FTM_WCDMA_BER_PCA_Size_Enum)
      \code
          FTM_WCDMA_BER_PCA_Type_Alg1 = 0 = Power control algorithm 1
          FTM_WCDMA_BER_PCA_Type_Alg2 = 1 = Power control algorithm 2
      \endcode
   \param iUL_TPC_StepSize
      \code
         FTM_WCDMA_BER_PCA_Size_1dB = 0 = Stepsize 1 dB
         FTM_WCDMA_BER_PCA_Size_2dB = 1 = Stepsize 2 dB
      \endcode
   \param iDL_PriCPICH_Scr_Code = Primary CPICH downlink scrambling code.
   \param iDL_ChanCode = Downlink DPCH channelization code.
   \param iBetaC = Gain factor for DPCCH
   \param iBetaD = Gain factor for DPDCH
   \param iChannel = WCDMA RF Channel (downlink)

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_Handover(
      HANDLE hResourceContext,
      unsigned char iRMC_Type, unsigned char iUL_MaxTxPwr, unsigned long iUL_DPCH_ScrCode, unsigned char iUL_PCA,
      unsigned char iUL_TPC_StepSize, unsigned short iDL_PriCPICH_Scr_Code, unsigned short iDL_ChanCode,
      unsigned char iBetaC, unsigned char iBetaD, unsigned short iChannel);

   /******************************************************************************/
   /**
   WCDMA BER, handover to a new RMC DCH channel.  This must be done after the
   FTM_WCDMA_BER_SetupRMC_DCH function has completed successfully.

   This low-level FTM operation is called and the associated events are verifed:
   of the embedded function RMC_DCH_SETUP_REQ_V2.

   For the timer values (Txxx) refer to the 3GPP standard 25.331, section 8
   For the counter values (Nxxx) refer to section "13.3 - UE constants and parameters"

      This low-level FTM operation is called and the associated event is verifed:
         RMC_DCH_SETUP_REQ_V2B

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRMC_Type (refer to FTM_WCDMA_BER_RMC_Type_Enum)
      \code
         FTM_WCDMA_BER_RMC_Type12_2kpbs            = 0,   //<!' RMC 12.2 kbps channel
         FTM_WCDMA_BER_RMC_Type64kbps            = 1,   //<!' RMC 64 kbps channel
         FTM_WCDMA_BER_RMC_Type384kpbs            = 2,   //<!' RMC 384 kbps channe (Not currently supported)
         FTM_WCDMA_BER_RMC_Type12_2kpbs_Symmetric   = 3,   //<!' RMC 12.2 kbps channel, block size in the DL and UL is the same
         FTM_WCDMA_BER_RMC_Type64kbps_Symmetric      = 4,   //<!' RMC 64 kbps channel, block size in the DL and UL is the same
         FTM_WCDMA_BER_RMC_Type384kbps_Symmetric      = 5      //<!' RMC 384 kbps channel, block size in the DL and UL is the same
         Note: For first 3 data rate enumeration, UL CRC bits are looped back from DL
         Note: For last  3 data rate enumeration, UL CRC is valid and computed based on Rx data bits
      \endcode
   \param iUL_MaxTxPwr = Maximum transmit power in dBm.

   \param iUL_DPCH_ScrCode = Scrambling code to use for the uplink.
   \param iUL_PCA (refer FTM_WCDMA_BER_PCA_Size_Enum)
      \code
          FTM_WCDMA_BER_PCA_Type_Alg1 = 0 = Power control algorithm 1
          FTM_WCDMA_BER_PCA_Type_Alg2 = 1 = Power control algorithm 2
      \endcode
   \param iUL_TPC_StepSize
      \code
         FTM_WCDMA_BER_PCA_Size_1dB = 0 = Stepsize 1 dB
         FTM_WCDMA_BER_PCA_Size_2dB = 1 = Stepsize 2 dB
      \endcode
   \param iDL_PriCPICH_Scr_Code = Primary CPICH downlink scrambling code.
   \param iDL_ChanCode = Downlink DPCH channelization code.
   \param iBetaC = Gain factor for DPCCH. Default is 8.
   \param iBetaD = Gain factor for DPDCH. Default is 15.
    \param iDPCCH_PowerOffset = DPCCH Power Offset, default is -60
    \param n_312 = Maximum number of "in sync" received from L1.  Default is 0 (s1).
      \code
           FTM_WCDMA_BER_N312_s1    = 0
           FTM_WCDMA_BER_N312_s50   = 1
           FTM_WCDMA_BER_N312_s100  = 2
           FTM_WCDMA_BER_N312_s200  = 3
           FTM_WCDMA_BER_N312_s400  = 4
           FTM_WCDMA_BER_N312_s600  = 5
           FTM_WCDMA_BER_N312_s800  = 6
           FTM_WCDMA_BER_N312_s1000 = 7
      \endcode
    \param n_313 = Maximum number of successive "out of sync" received from L1. Default is 4 (s20).
      \code
           FTM_WCDMA_BER_N313_s1   = 0,
           FTM_WCDMA_BER_N313_s2   = 1,
           FTM_WCDMA_BER_N313_s4   = 2,
           FTM_WCDMA_BER_N313_s10  = 3,
           FTM_WCDMA_BER_N313_s20  = 4,
           FTM_WCDMA_BER_N313_s50  = 5,
           FTM_WCDMA_BER_N313_s100 = 6,
           FTM_WCDMA_BER_N313_s200 = 7
      \endcode
    \param n_315 = Maximum number of successive "in sync" received from L1 during T313 is activated. Default is 0 (s1).
      \code
           FTM_WCDMA_BER_N315_s1   = 0,
           FTM_WCDMA_BER_N315_s50  = 1,
           FTM_WCDMA_BER_N315_s100 = 2,
           FTM_WCDMA_BER_N315_s200 = 3,
           FTM_WCDMA_BER_N315_s400 = 4,
           FTM_WCDMA_BER_N315_s600 = 5,
           FTM_WCDMA_BER_N315_s800 = 6,
           FTM_WCDMA_BER_N315_s1000 = 7
      \endcode
    \param t_312 = T312: Timer in seconds for physical channel establishment procedure.  Refer to 25.331 Section 8 for
                        explicit definition.  Default is 1.
    \param t_313 = T313: Timer in seconds for radio link failure detection.  Refer to 25.331 Section 8 for explicit definition.
                  Default is 3.
   \param iChannel = WCDMA RF Channel (downlink).

   \return true if all operations succeeded and the correct event messages were received

   \warning The active log mask will be changed to log only log FTM2 log packets.
            When the function is completed, the state of ASYNC logging will be enabled.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_Handover_V2B(
      HANDLE hResourceContext,
      unsigned char iRMC_Type, unsigned char iUL_MaxTxPwr, unsigned long iUL_DPCH_ScrCode, unsigned char iUL_PCA,
      unsigned char iUL_TPC_StepSize, unsigned short iDL_PriCPICH_Scr_Code, unsigned short iDL_ChanCode,
      unsigned char iBetaC, unsigned char iBetaD,
      short iDPCCH_PowerOffset,
      unsigned char n_312,
      unsigned char n_313,
      unsigned char n_315,
      unsigned char t_312,
      unsigned char t_313,
      unsigned short iChannel );

   /******************************************************************************/
   /**
   WCDMA BER, Setup a default RMC DCH channel.  This function calls
   QLIB_FTM_WCDMA_BER_SetupRMC_DCH() with the following parameters:


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   iRMC_Type =  RMC 12.2 kbps channel
   iRMC_Type =  24dBm.
   iUL_DPCH_ScrCode = 0 = Scrambling code to use for the uplink.
   iUL_PCA =  Power Control Algorithm 1
   iUL_TPC_StepSize  = Stepsize 1 dB
   iDL_PriCPICH_Scr_Code = 0 = Primary CPICH downlink scrambling code.
   iDL_ChanCode = 3 = Downlink DPCH channelization code.

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_SetupDefaultRMC_DCH( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   WCDMA BER, 3.8 FTM WCDMA TFCS Configuration request

   The tfcs_config table must be 4 unique numbers, all between 0 and 3.
   This defines how the TFCI values should be mapped to each Transport Format
   Combination.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param aiTFCS_Config=

      To solve the Agilent issue you would send the command using tfcs_select =
      FTM_WCDMA_BER_UL_TFCS_CONFIG, and tfcs_config = {0,2,1,3}.

      If you don't send the command the default behavior is tfcs_config = {0,1,2,3}.
      Subtle difference, enough to break the Agilent.  Right now we don't really
      need to send a DL_TFCS_CONFIG since other the equipment are flexible or adhere
      to the standard RMC config.

   \param eTFCS_Select = specifies configuration of UL or DL, defined by
      \code
           FTM_WCDMA_BER_UL_TFCS_CONFIG = 0,
           FTM_WCDMA_BER_DL_TFCS_CONFIG = 1
      \endcode

   \param iStatus
      \code
          0 = Success (COMMAND_SUCCESS)
          1 = Failure (COMMAND_FAILED)
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_RMC_DCH_TFCS_CONFIG_REQ(
      HANDLE hResourceContext,
      unsigned char eTFCS_Select,
      unsigned char aiTFCS_Config[ 4] );

   /******************************************************************************/
   /**
   WCDMA BER, Clear BER event status, Section 3.9 FTM Reset Event Status

      This command send FTM command to clear the event status.

      This command clears event status that is used for QLIB_FTM_WCDMA_BER_EVENT_STATUS_REQ function,

      This function could be called before the WCDMA BER function that generates the event.
      For example, QLIB_FTM_WCDMA_BER_AcquirePilot

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iStatus = 0 - COMMAND_SUCCESS
                   1 - COMMAND_FAILED
      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_EVENT_STATUS_CLEAR_REQ(HANDLE hResourceContext, unsigned short* iStatus);

   /******************************************************************************/
   /**
   WCDMA BER, Wait for event, Section 3.10

      This command allows the user to wait for a specific WCDMA BER non-signaling event. By
      using this command it is possible to avoid using the asynchronous events for the most common
      event types.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iEventType = See FTM_WCDMA_BER_EVENT_STATUS_Enum in QLib_Defines.h

                     0 -   FTM_WCDMA_BER_START_WCDMA_MODE_CNF
                     1 - FTM_WCDMA_BER_STOP_WCDMA_MODE_CNF
                     2 - FTM_WCDMA_BER_IDLE_MODE_CNF
                     3 - FTM_WCDMA_BER_ACQ_CNF
                     4 -   FTM_WCDMA_BER_CPHY_SETUP_CNF
                     5 - FTM_WCDMA_PHYCHAN_ESTABLISHED_IND

      \param iTimeOut_ms = Timeout to use for waiting for the event. Units are milliseconds.

      \param iStatus =   0  FTM_WCDMA_BER_SYNC_STATUS_SUCCESS
                     1  FTM_WCDMA_BER_SYNC_STATUS_GEN_FAILURE
                     2  FTM_WCDMA_BER_SYNC_STATUS_TIMEOUT_EXPIRED
                     3  FTM_WCDMA_BER_SYNC_STATUS_EVENT_STATUS_FAILED

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_EVENT_STATUS_REQ(HANDLE hResourceContext, unsigned char iEventType, unsigned long iTimeOut_MS, unsigned short* iStatus );


   /******************************************************************************/
   /**
   WCDMA BER, Tx Power Override, Section 3.11

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
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_SET_UL_POWER(HANDLE hResourceContext, unsigned char bOverride, short iUL_Pwr_dBm10, unsigned short* iStatus);

   /******************************************************************************/
   /**
   WCDMA BER, Rx Level Report, Section 3.12

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
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_RX_LEVEL_REQ(HANDLE hResourceContext, unsigned char iRxChain, unsigned short* iStatus, short*iRxAGC, short* iRxPowerdBm);
   /******************************************************************************/
   /**
   WCDMA BER, TPC Control, Section 3.13

      This function sends FTM_WCDMA_BER_TPC_CONTROL command which simulates all up or all down bits.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iOverride_Enabled   =   0  Up down bits from generator; TCP_Pattern ignored
                              1  Override enabled; simulate all up or all down bits

      \param iTCP_Pattern  = Pattern per channel; example below sets all channels:

                        0 - All Down Power Control Bits
                        1 - All Up Power Control Bits

      \param iStatus = 0 = COMMAND_SUCCESS
                       1 = COMMAND_FAIL


      \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_TPC_CONTROL(HANDLE hResourceContext, unsigned short iOverride_Enabled, unsigned long iTCP_Pattern, unsigned short* iStatus);

   /******************************************************************************/
   /**
   WCDMA RSCP, RSCP Measurement, Section 3.13  *ToDo*

      This function sends FTM_WCDMA_BER_RSCP command which returns RSCP data.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iEcIo_Rx0   =   data

      \param iRSCP_Rx0   =   data

      \param iEcIo_Rx1   =   data

      \param iRSCP_Rx1   =   data

    \param iStatus = 0 = COMMAND_SUCCESS
                       1 = COMMAND_FAIL

      \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_RSCP(HANDLE hResourceContext, unsigned long* iEcIo_Rx0, unsigned long* iRSCP_Rx0, unsigned long* iEcIo_Rx1, unsigned long* iRSCP_Rx1, unsigned short* iStatus);

   /******************************************************************************/
   /**
   WCDMA BER, Clear the internal status of the WCDMA BER structure

      Resets the contents of all fields in the internal WCDMA_BER_State state structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_ClearStatus( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   WCDMA BER, Returns a copy of the internal WCDMA BER state. On the internal copy
            it clears the "updated" fields for each message type so that the
          next time this funciton is called. Only items that been received
          since the first function call are marked as "updated."


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pWCDMA_BER_State = reference to a WCDMA_BER_State structure that will be
                           filled in with the state information

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_GetStatus( HANDLE hResourceContext, unsigned char* pWCDMA_BER_State );

   /******************************************************************************/
   /**
   WCDMA BER, Returns a simplified status of whether a specified event has occured.

   The function operations upon the bHasUpdated array held in the WCDMA BER status
   structure (data type WCDMA_BER_State, as defined in QLib_Defines.h).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eEventID = The input parameter is an index into this array, and the function
                      returns a true if the event has occured and false if it has not.

      Data type is log_FTM2_WCDMA_BER_log_id_enum, defined in QLib_Defines.h

      Values are:
      \code
         LOG_FTM2_WCDMA_START_MODE_CNF          = 0 = FTM WCDMA BER start WCDMA mode confirmation
         LOG_FTM2_WCDMA_STOP_MODE_CNF           = 1 = FTM WCDMA BER stop WCDMA mode confirmation
         LOG_FTM2_WCDMA_START_IDLE_MODE_REQ     = 2 = FTM WCDMA BER start idle mode confirmation
         LOG_FTM2_WCDMA_ACQUIRE_CNF             = 3 = FTM WCDMA BER acquire confirmation
         LOG_FTM2_WCDMA_CPHY_SETUP_CNF           = 4 = FTM WCDMA BER CPHY setup confirmation
         LOG_FTM2_WCDMA_PHYCHAN_ESTABLISHED_IND = 5 = FTM WCDMA BER physical channel established confirmation
         LOG_FTM2_WCDMA_CPHY_ERROR_IND          = 6 = FTM WCDMA BER pyhsical channel error
         LOG_FTM2_WCDMA_RL_FAILURE_IND          = 7 = FTM WCDMA BER Reverselink error
      \endcode


   \param pWCDMA_BER_State = reference to a WCDMA_BER_State structure that will be
                           filled in with the state information

   \return true the event type has occurred, false if it has not.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_GetEventStatus( HANDLE hResourceContext, unsigned char eEventID );

   /******************************************************************************/
   /**
   WCDMA BER, close the WCDMA Non-signaling session.

      This low-level FTM operation is called and the associated event is verifed:
         STOP_WCDMA_MODE_REQ

      This function also calls QLIB_FTM_LOG_StopFTM_Log( HANDLE, LOG_FTM2_LOG_WCDMA_BER )
      to disable the FTM log that was started in QLIB_FTM_WCDMA_BER_StartSession


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if all operations succeeded and the correct event messages were received

   \warning This function will disable async logging and clear the async queue.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_BER_StopSession( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Start logging of WCDMA AGC packets.

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function WaitForNextWCDMA_AGC_Log() can be called to wait
   for the next WCDMA log message and have the values returned.

   Note QLIB_FTM_WCDMA_BER_StartSession() automatically calls this function when
   it begins.

   \return true if successful, false if fail.

   \warning

        1. Before this function is called, the phone must be set in a WCDMA FTM mode, by
           calling either QLIB_FTM_SET_MODE() for basic RF testing, or by calling
            QLIB_FTM_WCDMA_BER_StartSession() for WCDMA BER testing.

      2. This function will set the async messasge logging status to ON, to
           turn off async messages, QLIB_DIAG_SetPhoneLoggingState() should be called.



   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_AGC_Start_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Wait a specified number of milliseconds for the next WCMA AGC log message.

   If the message is found, then the contents of the message are copied into

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function WaitForNextWCDMA_AGC_Log() can be called to wait
   for the next WCDMA log message and have the values returned.

   \param pWCDMA_AGC_Log = pointer to the are to store the WCDMA AGC log information.
                           This is of type "FTM2LogMessage_WCDMA_AGC" defined in
                     QLIB_Defines.h

   \param iTimeout_ms = # of milliseconds to wait for the AGC.  Default is 300ms

   \return true if a valid WCDMA log was found within the specified timeout, false if not.

   \warning Before this function is called, StartWCDMA_AGC_Log() must be called to setup
            capturing of WCDMA AGC messages.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_AGC_WaitForNextLog(
      HANDLE hResourceContext,  void* pWCDMA_AGC_Log, unsigned long iTimeout_ms );

   /******************************************************************************/
   /**

   Stop logging of WCDMA AGC packets.  This is important to do before changing
   RF modes or starting/stopping WCDMA BER

   This command calls the FTM_LOG_DISABLE() function with the proper settings.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function will set the async messasge logging status to OFF.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_AGC_Stop_Log( HANDLE hResourceContext  );

   /******************************************************************************/
   /**

   Starts logging WCDMA AGC (LOG_FTM2_LOG_WCDMA_AGC_V2) packets.

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function QLIB_FTM_WCDMA_AGC_WaitForNextLog_V2() can be called
   to wait for the next WCDMA log message and have the values returned.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

        1. Before this function is called, the phone must be set in a WCDMA FTM mode,
         by calling either QLIB_FTM_SET_MODE() for basic RF testing, or by calling
         QLIB_FTM_WCDMA_BER_StartSession() for WCDMA BER testing.

      2. This function will set the async messasge logging status to ON, to
           turn off async messages, QLIB_DIAG_SetPhoneLoggingState() should be called.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_AGC_Start_Log_V2( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Wait a specified number of milliseconds for the next WCMA AGC log message.

   If the message is found, then the contents of the message are copied into a
   FTM2LogMessage_WCDMA_AGC_V2 structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pWCDMA_AGC_Log = pointer to the area to store the WCDMA AGC log information.
                           This is of type "FTM2LogMessage_WCDMA_AGC_V2" defined in
                     QLIB_Defines.h
   \param iTimeout_ms = # of milliseconds to wait for the WCDMA log.  Default is 300ms

   \return true if a valid WCDMA log was found within the specified timeout, false if not.

   \warning Before this function is called, QLIB_FTM_WCDMA_AGC_Start_Log_V2() must be
          called to setup capturing of WCDMA AGC messages.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_AGC_WaitForNextLog_V2( HANDLE hResourceContext,
         void* pWCDMA_AGC_Log,
         unsigned long iTimeout_ms );

   /******************************************************************************/
   /**

   Stop logging WCDMA AGC (LOG_FTM2_LOG_WCDMA_AGC_V2) packets.  This is important
   to do before changing RF modes or starting/stopping WCDMA BER.

   This command calls the FTM_LOG_DISABLE() function with the proper settings.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function will set the async message logging status to OFF.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_AGC_Stop_Log_V2( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   UMTS non-signaling, ensure mobile phone is in a "stopped" state for all
   UMTS non-signlaing modes (WCDMA/GSM).

   The procedure used is:
      1) Call STOP_WCDMA_MODE_REQ
      2) If the status code is successful, then this indicates the mobile was in
         the WCDMA mode, so the function will wait for the corresponding event.

      3) Call STOP_GSM_MODE_REQ
      4) If the status code is successful, then this indicates the mobile was in
         the GSM mode, so the function will wait for the corresponding event.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if the commands were executed without a device communication failure.

   \warning The mobile phone must be in FTM mode before this function is called.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_UMTS_BER_ForceStopped(   HANDLE hResourceContext );

   /******************************************************************************/
   /**
   WCDMA BER API, 80-V9698-1, START_WCDMA_MODE_REQUEST command

   This command starts the WCDMA Layer 1 task from an Inactive state. This will initialize the
   4 Layer 1 subsystem and the necessary driver

   This function can be used in FTM Sequencing mode operation.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_START_MODE_REQ(HANDLE hResourceContext, unsigned char* iStatus);

   /******************************************************************************/
   /**
   WCDMA BER API, 80-V9698-1, ACQUIRE_REQ command

   TThis command starts a cell search acquisition procedure. Currently, the user may only specify an
   3 ARFCN to perform the cell search procedure..

   This function can be used in FTM Sequencing mode operation.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iChannel = WCDMA RF channel

   \param iAcqType =   0  Frequency valid only
                  1  Frequency and scrambling code valid only (not supported)
                  2  Frequency, scrambling code, and PN position valid (not supported)

                  Frequency valid only(0) should be used for this parameter

   \param iAcqType =   0  Micro acquisition (not supported)
                  1  Full acquisition

                  Full acquisition (1) should be used for this parameter.

   \param iFreq   =   ARFCN to attempt acquisition
                  Required for acq_type  0, 1, or 2

   \param iScrCode =   DL scrambling code to acquire; used in conjunction with freq; only valid for acq_type  1 or 2
                  This field may be ignored for certain values of acq_mode, even if acq_type indicates to use this field

   \param iPN_Pos =   Used to search for pilot at a known PN position; used in conjunction with scr_code and freq; only valid for acq_type  2
                  This field may be ignored for certain values of acq_mode, even if acq_type indicates to use this field

   \param iStatus =    0 == command success
                       1 == command fail

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_ACQUIRE_REQ( HANDLE hResourceContext, unsigned char iAcqType, unsigned char iAcqMode, unsigned short iFreq, unsigned short iScrCode, unsigned long iPN_Pos, unsigned char* iStatus );

   /******************************************************************************/
   /**
   WCDMA BER API, 80-V9698-1, RMC_DCH_RECONFIGURE command

   This request attempts to reconfigure the RMC DCH call when a call is already established.
   Some platforms may be able to use this command to initially establish the RMC call directly after performing an acquisition step

   For the timer values (Txxx) refer to the 3GPP standard 25.331, section 8
   For the counter values (Nxxx) refer to section "13.3 - UE constants and parameters"

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRMC_Type (refer to FTM_WCDMA_BER_RMC_Type_Enum)
      \code
         FTM_WCDMA_BER_RMC_Type12_2kpbs            = 0,   //<!' RMC 12.2 kbps channel
         FTM_WCDMA_BER_RMC_Type64kbps            = 1,   //<!' RMC 64 kbps channel
         FTM_WCDMA_BER_RMC_Type384kpbs            = 2,   //<!' RMC 384 kbps channe (Not currently supported)
         FTM_WCDMA_BER_RMC_Type12_2kpbs_Symmetric   = 3,   //<!' RMC 12.2 kbps channel, block size in the DL and UL is the same
         FTM_WCDMA_BER_RMC_Type64kbps_Symmetric      = 4,   //<!' RMC 64 kbps channel, block size in the DL and UL is the same
         FTM_WCDMA_BER_RMC_Type384kbps_Symmetric      = 5      //<!' RMC 384 kbps channel, block size in the DL and UL is the same
         Note: For first 3 data rate enumeration, UL CRC bits are looped back from DL
         Note: For last  3 data rate enumeration, UL CRC is valid and computed based on Rx data bits
      \endcode
   \param iUL_MaxTxPwr = Maximum transmit power in dBm.

   \param iUL_DPCH_ScrCode = Scrambling code to use for the uplink.

   \param iUL_PCA (refer FTM_WCDMA_BER_PCA_Size_Enum)
      \code
          FTM_WCDMA_BER_PCA_Type_Alg1 = 0 = Power control algorithm 1
          FTM_WCDMA_BER_PCA_Type_Alg2 = 1 = Power control algorithm 2
      \endcode

   \param iUL_TPC_StepSize
      \code
         FTM_WCDMA_BER_PCA_Size_1dB = 0 = Stepsize 1 dB
         FTM_WCDMA_BER_PCA_Size_2dB = 1 = Stepsize 2 dB
      \endcode

   \param iDL_PriCPICH_Scr_Code = Primary CPICH downlink scrambling code.

   \param iDL_ChanCode = Downlink DPCH channelization code.

   \param iBetaC = Gain factor for DPCCH. Default is 8.

   \param iBetaD = Gain factor for DPDCH. Default is 15.

   \param iDPCCH_PowerOffset = DPCCH Power Offset, default is -60

   \param n_312 = Maximum number of "in sync" received from L1.  Default is 0 (s1).
      \code
           FTM_WCDMA_BER_N312_s1    = 0
           FTM_WCDMA_BER_N312_s50   = 1
           FTM_WCDMA_BER_N312_s100  = 2
           FTM_WCDMA_BER_N312_s200  = 3
           FTM_WCDMA_BER_N312_s400  = 4
           FTM_WCDMA_BER_N312_s600  = 5
           FTM_WCDMA_BER_N312_s800  = 6
           FTM_WCDMA_BER_N312_s1000 = 7
      \endcode
    \param n_313 = Maximum number of successive "out of sync" received from L1. Default is 4 (s20).
      \code
           FTM_WCDMA_BER_N313_s1   = 0,
           FTM_WCDMA_BER_N313_s2   = 1,
           FTM_WCDMA_BER_N313_s4   = 2,
           FTM_WCDMA_BER_N313_s10  = 3,
           FTM_WCDMA_BER_N313_s20  = 4,
           FTM_WCDMA_BER_N313_s50  = 5,
           FTM_WCDMA_BER_N313_s100 = 6,
           FTM_WCDMA_BER_N313_s200 = 7
      \endcode

   \param n_315 = Maximum number of successive "in sync" received from L1 during T313 is activated. Default is 0 (s1).
      \code
           FTM_WCDMA_BER_N315_s1   = 0,
           FTM_WCDMA_BER_N315_s50  = 1,
           FTM_WCDMA_BER_N315_s100 = 2,
           FTM_WCDMA_BER_N315_s200 = 3,
           FTM_WCDMA_BER_N315_s400 = 4,
           FTM_WCDMA_BER_N315_s600 = 5,
           FTM_WCDMA_BER_N315_s800 = 6,
           FTM_WCDMA_BER_N315_s1000 = 7
      \endcode

   \param t_312 = T312: Timer in seconds for physical channel establishment procedure.  Refer to 25.331 Section 8 for
                        explicit definition.  Default is 1.

   \param t_313 = T313: Timer in seconds for radio link failure detection.  Refer to 25.331 Section 8 for explicit definition.
                  Default is 3.

   \param iChannel = WCDMA RF Channel (downlink).

   \param iStatus =    0 == command success
                       1 == command fail

   \return true if all operations succeeded and the correct event messages were received

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_RMC_DCH_SETUP_REQ_V2B( HANDLE hResourceContext,
         unsigned char iRMC_Type,
         unsigned char iUL_MaxTxPwr,
         unsigned long iUL_DPCH_ScrCode,
         unsigned char iUL_PCA,
         unsigned char iUL_TPC_StepSize,
         unsigned short iDL_PriCPICH_Scr_Code,
         unsigned short iDL_ChanCode,
         unsigned char iBetaC,
         unsigned char iBetaD,
         short iDPCCH_PowerOffset,
         unsigned char n_312,
         unsigned char n_313,
         unsigned char n_315,
         unsigned char t_312,
         unsigned char t_313,
         unsigned short iChannel,
         unsigned char *iStatus);

   /******************************************************************************/
   /**
   WCDMA BER API, 80-V9698-1, STOP_WCDMA_MODE_REQ command

   This command stops the WCDMA Layer 1 services and returns to the inactive state.
   If the user has previously given a Start WCDMA mode request, the user must issue this command before proceeding to other FTM tests, or entering Online mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iStatus =    0 == command success
                       1 == command fail

   \return true if the commands were executed without a device communication failure.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_STOP_MODE_REQ(HANDLE hResourceContext, unsigned char* iStatus);



   /*******************************************************************************************
      HSDPA BER FTM
   /*******************************************************************************************/

   /******************************************************************************/
   /**
   HSDPA BER, Start a HSDPA BER session. Before this operation is called, a valid
   WCDMA BER session must be started by calling QLIB_FTM_WCDMA_BER_StartSession().

      This function calls these operations and checks for errors:
         FTM_HSDPA_BER_ClearStatus

      This low-level FTM operation is called and the associated event is verifed:
         START_HSDPA_REQ

      If the first START_HSDPA_REQ call fails, because a mode is already started then the
      function will stop HSDPA using STOP_HSDPA_REQ and try to re-start using START_HSDPA_REQ
      again.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if network session is setup successful, false if there are any failures

   \warning The active log mask will be changed to log only log FTM2 log packets.
            When the function is completed, the state of ASYNC logging will be enabled.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BER_StartSession( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   High level command for HSDPA BLER, calls RECONFIG_HSDPA_REQ and
   handles all related embedded events.

   While an HSDPA link is active, it is possible to dynamically reconfigure any or all of the high
   speed channels. The user should send updated channel configurations using the appropriate
   configuration commands in Sections 2.4 through 2.7, and then use this command to indicate
   which channels should be reconfigured by Layer 1. Note the reconfiguration happens using an
   activation time of now.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iReconfigBitmask - This bitmask represents which channels should be reconfigured by L1. It is possible
                             to reconfigure one or many channels by setting the appropriate bit in this 8 bit field. It
                             is assumed that the actual updated channel configurations have already been sent
                             down using the configuration commands. At least one of the channels must be
                             specified for reconfiguration using this bitmask. The user should not set any of the
                             upper 4 bits.
      \code
          Bit 0 = Reconfigure HS-DSCH channel
          Bit 1 = Reconfigure HS-PDSCH
          Bit 2 = Reconfigure HS-SCCH
          Bit 3 = Reconfigure HS-DPCCH
          Bits 4-7 = Reserved. Set to 0.

          Example: If the user wants to reconfigure both HS-DSCH and HS-DPCCH, the
                   reconfig_bitmask should be set to 0x09.
      \endcode


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BLER_Reconfigure_HS( HANDLE hResourceContext, unsigned char iReconfigBitmask );

   /******************************************************************************/
   /**
   High level command for HSDPA BLER, calls CONFIG_HS_PDSCH_REQ and verifies the
   return status.

   This command configures the HS-PDSCH. All configurations are buffered by the FTM software.
   This command is used when the user sends the start HSDPA command (if HSDPA is inactive) or
   reconfigure command (if HSDPA is active).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iHS_PDSCH_RadioLink_PCS Primary scrambling code for the HS radio link.


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BLER_Configure_PDSCH( HANDLE hResourceContext, unsigned short iHS_PDSCH_RadioLink_PCS );

   /******************************************************************************/
   /**
   High level command for HSDPA BLER, calls CONFIGURE_HS_SCCH_REQ  and verifies the
   return status.

   This command configures the HS-SCCH. The user can indicate to L1 the HS-SCCH
   channelisation code set. Up to four codes can be monitored at once by the UE.
   All configurations are buffered by the FTM software. This command is used when the user sends
   the start HSDPA command (if HSDPA is inactive) or reconfigure command (if HSDPA is
   active).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNumCodes - Number of channelisation codes in the HS-SCCH code set. Range is from 1-4

   \param aiCodes[4] - Array of 4 bytes, which represent the code numbers in the code set. Only num_codes
                      bytes need to be valid. For example, if num_codes is 3, the 4 bytes in the codes field
                      can be set to [ 12, 13, 14, X], where the first 3 bytes dictates the code set, and X is
                      dont care.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BLER_Configure_HS_SCCH( HANDLE hResourceContext, unsigned char iNumCodes, unsigned char aiCodes[4] );

   /******************************************************************************/
   /**
   High level command for HSDPA BLER, calls CONFIGURE_HS_DSCH_REQ and
   handles all related embedded events.

   This command configures the HS-DSCH. The user can indicate the H-RNTI identifier, the
   number of HARQ processes, and explicitly declare the Virtual IR buffer memory partition for
   each process. Up to eight HARQ processes can be configured. Note the total amount of Virtual IR
   buffer space that can be defined is limited by the UE category. If the user tries to configure the
   HS-DSCH for more soft memory than allowable by the UE, the UE will reject the configuration,
   and will result in an error in the HSDPA log events that results from the start or reconfigure
   HSDPA operation.

   All configurations are buffered by the FTM software. This command is used when the user sends
   the start HSDPA command (if HSDPA is inactive) or reconfigure command (if HSDPA is
   active).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iH_RNTI - 16 bit UE ID for use during HSDPA session.

   \param iNum_HARQ_Processes - Number of HARQ processes to define. Range is from 1-8.

   \param bMemPartitionValid - unsigned char, set to indicate the mem_partition_info field contains valid data.

   \param aiMemPartitionInfo[8] Array of 8 bytes that represent the number of soft bits to define for each HARQ
                                 process. This array is only valid if mem_partition_valid field is set to TRUE. If
                                 so, only num_harq_processes elements of this array need to be valid. The rest
                                 can be dont care values. Each valid element should take on one of the
                                 following values:
      \code
           0 = HMS800 (indicates 800 soft bits for the HARQ process)
           1 = HMS1600
           2 = HMS2400
           3 = HMS3200
           4 = HMS4000
           5 = HMS4800
           6 = HMS5600
           7 = HMS6400
           8 = HMS7200
           9 = HMS8000
           10 = HMS8800
           11 = HMS9600
           12 = HMS10400
           13 = HMS11200
           14 = HMS12000
           15 = HMS12800
           16 = HMS13600
           17 = HMS14400
           18 = HMS15200
           19 = HMS16000
           20 = HMS17600
           21 = HMS19200
           22 = HMS20800
           23 = HMS22400
           24 = HMS24000
           25 = HMS25600
           26 = HMS27200
           27 = HMS28800
           28 = HMS30400
           29 = HMS32000
           30 = HMS36000
           31 = HMS40000
           32 = HMS44000
           33 = HMS48000
           34 = HMS52000
           35 = HMS56000
           36 = HMS60000
           37 = HMS64000
           38 = HMS68000
           39 = HMS72000
           40 = HMS76000
           41 = HMS80000
           42 = HMS88000
           43 = HMS96000
           44 = HMS104000
           45 = HMS112000
           46 = HMS120000
           47 = HMS128000
           48 = HMS136000
           49 = HMS144000
           50 = HMS152000
           51 = HMS160000
           52 = HMS176000
           53 = HMS192000
           54 = HMS208000
           55 = HMS224000
           56 = HMS240000
           57 = HMS256000
           58 = HMS272000
           59 = HMS288000
           60 = HMS304000

         Example: For Fixed Reference Channel HSET5 QPSK, the mem_partition_info
         is set up as [ 11, 11, 11, X, X, X, X, X] where 11 represents 9600 soft bits for
         HARQ processes 0-2, and X is dont care value.
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BLER_Configure_HS_DSCH(
      HANDLE hResourceContext,
      unsigned short iH_RNTI,
      unsigned char iNum_HARQ_Processes,
      unsigned char bMemPartitionValid,
      unsigned char aiMemPartitionInfo[8]
   );

   /******************************************************************************/
   /**
   High level command for HSDPA BLER, calls QLIB_FTM_HSDPA_BLER_Configure_HS_DSCH
   with a specific HSET configuration.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iH_RNTI - 16 bit UE ID for use during HSDPA session.

   \param eHSET = parameter of type ftm_hsdpa_ber_hset_type (defined in QLib_Defines.h)
      \code
          HSDPA_HSET_1_QPSK = 1,      //!< ' HSET 1, QPSK
          HSDPA_HSET_1_16QAM,         //!< ' HSET1, 16QAM
          HSDPA_HSET_2_QPSK,         //!< ' HSET2, QPSK
          HSDPA_HSET_2_16QAM,         //!< ' HSET2, 16QAM
          HSDPA_HSET_3_QPSK,         //!< ' HSET3, QPSK
          HSDPA_HSET_3_16QAM,         //!< ' HSET3, 16QAM
          HSDPA_HSET_4_QPSK,         //!< ' HSET4, QPST
          HSDPA_HSET_5_QPSK,         //!< ' HSET5, QPST
          HSDPA_HSET_6_QPSK = 0xFF      //!< ' HSET6, QPST
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BLER_Configure_HS_DSCH_HSET( HANDLE hResourceContext, unsigned short iH_RNTI, unsigned char eHSET );

   /******************************************************************************/
   /**
   High level command for HSDPA BLER, calls CONFIGURE_HS_DPCCH_REQ and
   handles all related embedded events.

   This command configures the HS-DPCCH. All configurations are buffered by the FTM software.
   This command is used when the user sends the start HSDPA command (if HSDPA inactive) or
   reconfigure command (if HSDPA active).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iCPICH_PowerOffset- Power offset of HS-PDSCH relative to serving CPICH. Values can be -12
                              to 26, indicating -6 dB to 13 dB, in 0.5 dB steps

   \param iCQI_FeedbackCycle - Period for CQI reports. Range is from 0-160 with units in milliseconds. 0
                              indicates CQI reporting is to be turned off. Valid values between 0 and
                              160 are defined in the 3GPP specifications

   \param iCQI_RepetitionFactor - Parameter that controls if CQI reports are to be repeated. Valid range is 1-4

   \param iDeltaCQI- Parameter that controls power adjustment for CQI reports. Valid range is 0-8.

   \param iDeltaACK - Parameters that controls power adjustments for ACK indications. Valid range is 0-8.

   \param iDeltaNACK - Parameter that controls power adjustments for NACK indications. Valid range is 0-8

   \param iACK_NACK_RepetitionFactor - Parameter that controls repetition of ACK/NACK indications. Valid range is 1-4.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BLER_Configure_HS_DPCCH(
      HANDLE hResourceContext,
      unsigned char iCPICH_PowerOffset,
      unsigned char iCQI_FeedbackCycle,
      unsigned char iCQI_RepetitionFactor,
      unsigned char iDeltaCQI,
      unsigned char iDeltaACK,
      unsigned char iDeltaNACK,
      unsigned char iACK_NACK_RepetitionFactor
   );

   /******************************************************************************/
   /**
   HSDPA BLER, Clear BLER event status, Section 3.9 FTM Reset Event Status

      This command send FTM command to clear the event status.

      This command clears event status that is used for QLIB_FTM_HSDPA_BLER_EVENT_STATUS_REQ function,

      This function could be called before the HSDPA BLER function that generates the event.
      For example, QLIB_FTM_HSDPA_BER_StartSession

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iStatus = 0 - COMMAND_SUCCESS
                   1 - COMMAND_FAILED
      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BLER_EVENT_STATUS_CLEAR_REQ(HANDLE hResourceContext, unsigned short* iStatus);

   /******************************************************************************/
   /**
   HSDPA BLER, Wait for event, Section 3.10

      This command allows the user to wait for a specific HSDPA BLER non-signaling event. By
      using this command it is possible to avoid using the asynchronous events for the most common
      event types.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iEventType = See FTM_HSDPA_BLER_EVENT_STATUS_Enum in QLib_Defines.h

                     0 - FTM_HSDPA_BLER_HS_CHANNEL_START_SYNC_STATUS
                     1 - FTM_HSDPA_BLER_HS_CHANNEL_STOP_SYNC_STATUS
                     2 - FTM_HSDPA_BLER_HS_CHANNEL_RECFG_SYNC_STATUS

      \param iTimeOut_ms = Timeout to use for waiting for the event. Units are milliseconds.

      \param iStatus =   0  FTM_HSDPA_BLER_SYNC_STATUS_SUCCESS
                     1  FTM_HSDPA_BLER_SYNC_STATUS_GEN_FAILURE
                     2  FTM_HSDPA_BLER_SYNC_STATUS_TIMEOUT_EXPIRED
                     3  FTM_HSDPA_BLER_SYNC_STATUS_EVENT_STATUS_FAILED

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BLER_EVENT_STATUS_REQ(HANDLE hResourceContext, unsigned char iEventType, unsigned long iTimeOut_MS, unsigned short* iStatus );



   /******************************************************************************/
   /**
   WCDMA BER, Clear the internal status of the WCDMA BER structure

      Resets the contents of all fields in the internal WCDMA_BER_State state structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BER_ClearStatus( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   HSDPA BER, Returns a copy of the internal WCDMA BER state. On the internal copy
            it clears the "updated" fields for each message type so that the
          next time this funciton is called. Only items that been received
          since the first function call are marked as "updated."

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pWCDMA_BER_State = reference to a WCDMA_BER_State structure that will be
                           filled in with the state information.  Structure type is
                     HSDPA_BER_State.

   \return true if all operations succeeded and the correct event messages were received

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BER_GetStatus( HANDLE hResourceContext, unsigned char* pHSDPA_BER_State );

   /******************************************************************************/
   /**
   HSDPA BER, close the HSDPA Non-signaling session by calling this function and
   checking for the corresponding event:
      STOP_HSDPA_REQ

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if all operations succeeded and the correct event messages were received

   \warning This function will disable async logging and clear the async queue.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_HSDPA_BER_StopSession( HANDLE hResourceContext );

   /******************************************************************************
   UMTS Single Ended BER FTM
   *******************************************************************************/
   /******************************************************************************/
   /**
   Factory Test Mode Commands to start the SE BER logging

   This command starts the SE BER Logging.
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iFramesPerLog  = Number of Frames per each log.
   The UE will send a BER log packet every time it has processed iFramesPerLog number of received data blocks.
   8 -- Send a BER log packet every 8 data blocks processed.
   16 -- Send a BER log packet every 16 data blocks processed.
   32 -- Send a BER log packet every 32 data blocks processed.
   64 -- Send a BER log packet every 64 data blocks processed.

   \return true if successful, false if fail.

   \warning It is preferable to use the high-level function, QLIB_FTM_SE_BER_Start_Log(), which also handles changing the Log mask

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SE_BER_START_LOG_REQUEST( HANDLE hResourceContext,unsigned short iFramesPerLog );

   /******************************************************************************/
   /**
   Factory Test Mode UMTS Commands Stop BER Logging

   This command stops BER Logging.
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning It is preferable to use the high-level function, QLIB_FTM_SE_BER_Stop_Log(), which also handles changing the Log mask

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SE_BER_STOP_LOG_REQUEST( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode UMTS Commands Configure SE BER Log Request

   This command sets the required parameters to configure the Log request.
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iPnSeqType  =
   PN sequence sent over DL traffic channel by test box.  The UE uses the ITU-T O.150 recommendation for
   generation of PN data, and assumes the test box does as well.
   \code
   1 - PN9 sequence (length 511)
   2 - PN11 sequence (length 2047)
   3 - PN15 sequence (length 32767)
   \endcode

   \param ber_mode (Hard Coded to 3) in the command
   \code
   0 -- Reserved
   1 - ACQUIRE_RUN.  The UE will perform the acquisition step on every received data block from
   the physical layer.   If acquisition is successful, the UE will compute BER statistics on the
   remaining bits in the block.  This is a test feature only.
   2 - Reserved
   3 - AUTO.  The UE will perform acquisition, and then operate in steady state BER calculation
   mode.  The UE will also perform sync-loss detection, and automatically return to the acquisition
   state if necessary
   \endcode

   \param bPnInverted = Is the output of the shift register inverted.
   \code
   0 - Do not invert PN sequence (typical for PN9 and PN11)
   1 - Invert PN sequence.  The ITU-T O.150 recommendation indicates that for PN15, the output
   of the shift register, which defines the actual PN sequence, should be inverted.  Not all
   test boxes conform to this recommendation.  If the test box conforms for PN15, this field
   should be 1.  If the test box does not conform, this field should be 0.
   \endcode

   \param iAcqThreshold = Number of error free bits that must be detecting before acquire is a success.

   During acquisition, the UE will seed a local PN generator with the received data, and attempt to
   correlate the next set of received bits with the output of the local PN generator.  This exploits
   the properties of PN sequences generated by a shift register.  The acq_threshold defines the number
   of error free bits that must be detected before declaring the acquisition process successful and the
   UE to be synchronized to the PN stream. The UE will perform acquisition on a single data block at
   a time, so it is important that the user understand the data sizes for different non-signaling test cases.
   GSM Loop A/B (Full Rate speech): data block size = 260 bits
   GSM Loop C: data block size = 114 bits
   EGPRS SRB, MCS1-4: data block size = 114 bits
   EGPRS SRB, MCS5-6: data block size = 312 bits
   The FTM SE BER module does not support MCS7-9.   This is because there are only 306 usable data bits
   per burst.  Since the modulation type is the same (8PSK), it is therefore better to use MCS5/6
   exclusively.  The FTM SE BER module will always assume a MCS5/6 burst structure when 8PSK modulation
   is used.
   WCDMA RMC 12.2K: data block size = 244 bits

   \param iAcqLostWm  = Watermark for losing synchronization.
   If the number of errors in a received data block exceeds this threshold, the SE BER module will
   declare a sync lost condition and return to the acquisition state.  The SE BER log packet will
   indicate whether the module is in sync or not for each data block received.

   \return true if successful, false if fail.

   \warning It is preferable to use the high-level function, QLIB_FTM_SE_BER_Start_Log(), which also handles changing the Log mask

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SE_BER_CONFIGURE_REQUEST(
      HANDLE hResourceContext,
      unsigned short iPnSeqType,
      unsigned char bPnInverted,
      unsigned short iAcqThreshold,
      unsigned short iAcqLostWm );

   /******************************************************************************/
   /**
   This command clears the SE BER status vector for a given Loopback Type and zeroes the SE_BER_State structure .
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iSE_BER_Loopback_Type = SE_BER_LoopbackType
   \code
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC122K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC64K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_C,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_1_4,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_5_6,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_A,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_B
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC384K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC12p2K = 8,//TDS 12.2kbps rmc, for both Single code and multi-code
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC64K = 9, //TDS 64kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC144K = 10,//TDS 384kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC384K = 11,//TDS 384kbps rmc
   \endcode
   Types are supported.

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SE_BER_ClearStatus(
      HANDLE hResourceContext,
      unsigned long iSE_BER_Loopback_Type );

   /******************************************************************************/
   /**
   This command Measures the SE BER value for a given Loopback Type and updates the pSE_BER_State pointer instantaneously.
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pSE_BER_State  = Pointer the SE_BER_State structure

   \param iSE_BER_Loopback_Type = SE_BER_LoopbackType
   \code
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC122K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC64K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_C,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_1_4,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_5_6,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_A,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_B,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC384K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC12p2K = 8,//TDS 12.2kbps rmc, for both Single code and multi-code
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC64K = 9, //TDS 64kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC144K = 10,//TDS 384kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC384K = 11,//TDS 384kbps rmc
   \endcode
   Types are supported.

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SE_BER_GetStatus(
      HANDLE hResourceContext,
      void* pSE_BER_State,
      unsigned long iSE_BER_Loopback_Type );

   /******************************************************************************/
   /**
   This command Measures the SE BER value for a give Loopback Type and updates the pSE_BER_State pointer.
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pSE_BER_State  = Pointer the SE_BER_Status structure defined in QLib_Defines.h

   \param iSE_BER_Loopback_Type = SE_BER_LoopbackType
   \code
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC122K,  (12.2k)
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC64K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_C,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_1_4,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_5_6,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_A,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_B,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC384K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC12p2K = 8,//TDS 12.2kbps rmc, for both Single code and multi-code
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC64K = 9, //TDS 64kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC144K = 10,//TDS 384kbps rmc
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC384K = 11,//TDS 384kbps rmc
   \endcode
   Types are supported.

   \param iMeasurementCount = Number of bits to be collected for each SE BER measurement.

   \param iTimeOut_ms =  Time out duration before exiting the SE BER measurement.

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SE_BER_DoMeasurement(
      HANDLE hResourceContext,
      void *pSE_BER_State,
      unsigned long iSE_BER_Loopback_Type,
      unsigned long iMeasurementCount,
      unsigned long iTimeOut_ms );

   /******************************************************************************/
   /**
   High level function to start SE BER Logs, including setting the diagnostic log mask

   Calls these functions:
   \code
        QLIB_FTM_SE_BER_ClearStatus()
        QLIB_FTM_SE_BER_START_LOG_REQUEST()
        QLIB_FTM_SE_BER_CONFIGURE_REQUEST()
        QLIB_FTM_LOG_StartFTM_Log()
   \endcode


   \param iFramesPerLog  = Number of Frames per each log.
   The UE will send a BER log packet every time it has processed iFramesPerLog number of received data blocks.
   8 -- Send a BER log packet every 8 data blocks processed.
   16 -- Send a BER log packet every 16 data blocks processed.
   32 -- Send a BER log packet every 32 data blocks processed.
   64 -- Send a BER log packet every 64 data blocks processed.

   \param iPnSeqType  =
   PN sequence sent over DL traffic channel by test box.  The UE uses the ITU-T O.150 recommendation for
   generation of PN data, and assumes the test box does as well.
   \code
   1 - PN9 sequence (length 511)
   2 - PN11 sequence (length 2047)
   3 - PN15 sequence (length 32767)
   \endcode

   \param ber_mode (Hard Coded to 3) in the command
   \code
   0 -- Reserved
   1 - ACQUIRE_RUN.  The UE will perform the acquisition step on every received data block from
   the physical layer.   If acquisition is successful, the UE will compute BER statistics on the
   remaining bits in the block.  This is a test feature only.
   2 - Reserved
   3 - AUTO.  The UE will perform acquisition, and then operate in steady state BER calculation
   mode.  The UE will also perform sync-loss detection, and automatically return to the acquisition
   state if necessary
   \endcode

   \param bPnInverted = Is the output of the shift register inverted.
   \code
   0 - Do not invert PN sequence (typical for PN9 and PN11)
   1 - Invert PN sequence.  The ITU-T O.150 recommendation indicates that for PN15, the output
   of the shift register, which defines the actual PN sequence, should be inverted.  Not all
   test boxes conform to this recommendation.  If the test box conforms for PN15, this field
   should be 1.  If the test box does not conform, this field should be 0.
   \endcode

   \param iAcqThreshold = Number of error free bits that must be detecting before acquire is a success.

   During acquisition, the UE will seed a local PN generator with the received data, and attempt to
   correlate the next set of received bits with the output of the local PN generator.  This exploits
   the properties of PN sequences generated by a shift register.  The acq_threshold defines the number
   of error free bits that must be detected before declaring the acquisition process successful and the
   UE to be synchronized to the PN stream. The UE will perform acquisition on a single data block at
   a time, so it is important that the user understand the data sizes for different non-signaling test cases.
   GSM Loop A/B (Full Rate speech): data block size = 260 bits
   GSM Loop C: data block size = 114 bits
   EGPRS SRB, MCS1-4: data block size = 114 bits
   EGPRS SRB, MCS5-6: data block size = 312 bits
   The FTM SE BER module does not support MCS7-9.   This is because there are only 306 usable data bits
   per burst.  Since the modulation type is the same (8PSK), it is therefore better to use MCS5/6
   exclusively.  The FTM SE BER module will always assume a MCS5/6 burst structure when 8PSK modulation
   is used.
   WCDMA RMC 12.2K: data block size = 244 bits

   \param iAcqLostWm  = Watermark for losing synchronization.
   If the number of errors in a received data block exceeds this threshold, the SE BER module will
   declare a sync lost condition and return to the acquisition state.  The SE BER log packet will
   indicate whether the module is in sync or not for each data block received.

   \param iSE_BER_Loopback_Type = SE_BER_LoopbackType
   \code
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC122K,  (12.2k)
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC64K,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_C,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_1_4,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_EGPRS_SRB_5_6,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_A,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_GSM_B,
   LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_WCDMA_RMC384K,
     LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC12p2K = 8,//TDS 12.2kbps rmc, for both Single code and multi-code
     LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC64K = 9, //TDS 64kbps rmc
     LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC144K = 10,//TDS 384kbps rmc
     LOG_FTM2_FTM_LOG_SE_BER_LB_TYPE_TDSCDMA_RMC384K = 11,//TDS 384kbps rmc
   \endcode


   \param iMCS = expected MCS
   \code
   0 - Reserved
   1 - MCS1 (invalid for SE BER)
   2 - MCS2 (invalid for SE BER)
   3 - MCS3 (invalid for SE BER)
   4 - MCS4
   5 - MCS5 (UE Default Case)
   6 - MCS6
   7 - MCS7
   8 - MCS8
   9 - MCS9
   \endcode

   Clears SE BER STATUS
   Configures SE BER MEASUREMENT
   Sends SE BER LOG REQUEST
   Sends FTM LOG REQUEST
   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SE_BER_Start_Log(
      HANDLE hResourceContext,
      unsigned short iFramesPerLog,
      unsigned short iPnSeqType,
      unsigned char bPnInverted,
      unsigned short iAcqThreshold,
      unsigned short iAcqLostWm,
      unsigned long iSE_BER_Loopback_Type,
      unsigned short iMCS );

   /******************************************************************************/
   /**
   High level function to stop SE BER Logs.

   Calls QLIB_FTM_SE_BER_STOP_LOG_REQUEST and sets up diagnostic log mask to enable the FTM log

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SE_BER_Stop_Log( HANDLE hResourceContext);

   /******************************************************************************/
   /**
   High Level function which calls FTM_SE_BER_CONFIGURE_BIT_REORDERING to configure the
   bit re-ordering based the Call box.
   The user must select which ordering the test box uses, so FTM can properly
   arrange the bits for PN synchronization and classify the bits for Loop A/B
   processing.  This command should be sent prior to using the FTM SE BER Configure command.
   \param iBitOrder
   0 - Indicates to FTM that the test box applies the PN data at the input to the channel
   codec stage (after bit rearranging).  FTM treats this case as the default.
   1 - Indicates to FTM that the test box applies the PN data at the output of the vocoder
   (prior to bit rearranging)

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char  QLIB_FTM_SE_BER_Configure_Bit_Reordering(
      HANDLE hResourceContext,
      unsigned short iBitOrder);

   /******************************************************************************/
   /**
   High Level function which calls FTM_SE_BER_CONFIGURE_EDGE_EXPECTED_MCS to set the
   expected EDGE MCS.
   \param iMCS = expected MCS
   \code
   0 - Reserved
   1 - MCS1 (invalid for SE BER)
   2 - MCS2 (invalid for SE BER)
   3 - MCS3 (invalid for SE BER)
   4 - MCS4
   5 - MCS5 (UE Default Case)
   6 - MCS6
   7 - MCS7
   8 - MCS8
   9 - MCS9
   \endcode

   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char  QLIB_FTM_SE_BER_Configure_EDGE_Expected_MCS(
      HANDLE hResourceContext,
      unsigned short iMCS);

   /******************************************************************************/
   /**
   FTM Single-Ended BER API (80-VG331-1), Section 3.6, FTM SE BER Clear Synchronous Status

   This command clears the synchronous status of SE BER. The synchronous status is a simplified
   version of the SE BER, which stores BER/BLER failure statistics without context of the data
   channel configuraiton

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char  QLIB_FTM_SE_BER_CLEAR_SYNC_STATUS( HANDLE hResourceContext, unsigned short* iStatus );

   /******************************************************************************/
   /**
   FTM Single-Ended BER API (80-VG331-1), Section 3.7, FTM SE BER Get Synchronous Status

   This command returns the synchronous status of SE BER.
   The synchronous status is a simplified version of the SE BER, which stores BER/BLER failure
   statistics without context of the data channel configuration. For example BER from all GSM
   loops are handled by a single set of accumulators for the number of bits and the number of bit
   errors.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param dBER = Bit Error Rate (iTotal_Bit_Errors/iTotal_Bits * 100)
                 999.0 is returned if the target does not support the command

   \param iTotal_Bits = Total number of bits that have occurred since FTM_SE_BER_CLEAR_SYNC_STATUS was called

   \param iTotal_Bit_Errors = Total number of bit errors that have occurred since FTM_SE_BER_CLEAR_SYNC_STATUS was called.

   \param iStatus =   0 -COMMAND_SUCCESS
                  1 -COMMAND_FAILED

   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation

   In Sequencer operation, dBER is not updated.  User must calculate dBER based on iTotal_Bits and iTotal_Bits_Errors
   *******************************************************************************/
   QLIB_API unsigned char  QLIB_FTM_SE_BER_GET_SYNC_STATUS (HANDLE hResourceContext,
         unsigned long *iTotal_Bits,
         unsigned long *iTotal_Bit_Errors,
         double* dBER,
         unsigned short *iStatus);



#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_WCDMA_NS_H)
