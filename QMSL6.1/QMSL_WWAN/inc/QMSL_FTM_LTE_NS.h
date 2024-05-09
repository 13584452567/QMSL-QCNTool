/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_LTE_NS.h#13 $
 * $DateTime: 2016/05/25 12:04:50 $
 *
 * DESCRIPTION: QMSL_FTM_LTE_NS
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_LTE_NS_H)
#define _QMSL_LTE_NS_H

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
                                    LTE Non-signaling FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_START

   This command puts the UE in LTE Non-Signaling mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_START( HANDLE hResourceContext, unsigned long* pStatus );


   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_IS_CONNECTED

   This command queries if the UE is in LTE Non-Signaling mode call.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pStatus =  0  Success
                     1  Failure

   \return
      \code
          true  = Success
          false = Failure
      \endcode

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_IS_CONNECTED( HANDLE hResourceContext, unsigned long* pStatus );



   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_ACQ

   This command starts acquisition process.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iBand           = Band, this number is BC number minus 1.  For example, for BC13, band value is 12

   \param iEARFCN         = Channel, updated to unsigned long as of 4/2015 per 3GPP update

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_ACQ( HANDLE hResourceContext, unsigned char iBand, unsigned long iEARFCN, unsigned long* pStatus );




   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_HANDOVER

   This command hands over to the new channel.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iBand           = Band, this number is Band number minus 1.  For example, for LTE B13, band value is 12

   \param iEARFCN         = DL Channel number

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_HANDOVER( HANDLE hResourceContext, unsigned char iBand, unsigned long iEARFCN, unsigned long* pStatus );


   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_START_DP

   This command is used to start downlink reception on the UE

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iCRNTI           = C-RNTI used by UE

   \param iNetworkSigValue   = The network signaled valued - NS01,NS02,..

   \param iBSMaxPowerLimit =  The Base station maximum power limit.

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_START_DP( HANDLE hResourceContext, unsigned short iCRNTI, unsigned char iNetworkSigValue, char iBSMaxPowerLimit,unsigned char iDLLCID, unsigned char iULLCID,unsigned long* pStatus );



   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_START_DP_ENH

   This command is used to start downlink reception on the UE

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iCRNTI           = C-RNTI used by UE

   \param iNetworkSigValue   = The network signaled valued - NS01,NS02,..

   \param iBSMaxPowerLimit =  The Base station maximum power limit.

   \param iNumRx = The number of receivers to be used for this NS session
   
   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_START_DP_ENH( HANDLE hResourceContext, unsigned short iCRNTI, unsigned char iNetworkSigValue, char iBSMaxPowerLimit,unsigned char iDLLCID, unsigned char iULLCID, unsigned long* pStatus, unsigned char iNumRx );


   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_STOP

   This command halts all outstanding operation and exits the LTE mode. After this command is executed,
   FTM_LTE_NS_START command must be sent again to enter LTE mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_STOP( HANDLE hResourceContext, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_IDLE

   This command can be used to directly go form LTE CONNECTED state to an ENTERED_MODE state,
   without using  FTM_LTE_NS_STOP and FTM_LTE_NS_START commands.On success, the LTE NS state
   machine moves to Connected state

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_IDLE( HANDLE hResourceContext, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, FTM_LTE_NS_CONFIG_UL_WAVEFORM

   Configures the active resource blocks and modulation type for the LTE uplink waveform, overriding the settings in the DL DCI1.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iConfigOverride = 1 = Enable UL Override, ignore DCI 1 value sent over the air, and configure based on the parameters (Tx Chain, Start RB, Num RB, Modulation Type)
                        0 = Disable UL Grant override, use DCI 1 value sent over the air

   \param iTxChain =   0 = Tx 0
                  1 = Tx 1 (currently not supported)

   \param iStartRB = Starting resource block index that will be active

   \param iNumRB = Number of resources blocks that will be active.  The active resource blocks start at the index value indicated by START_RB_INDEX and are increasing by one after that

   \param iMCS  = Modulation Coding Scheme

               Refer to Table 8.6.1-1: Modulation, TBS index and redundancy version table for PUSCH of 3GPP TS 36.213
               The value of 0-10 is for QPSK with TBS value from 0 to 10
               The value of 11-20 is for 16 QAM with TBS value from 10 to 19


   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_CONFIG_UL_WAVEFORM( HANDLE hResourceContext, unsigned char iConfigOverride, unsigned char iTxChain, unsigned char iStartRB, unsigned char iNumRB, unsigned char iMCS, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, FTM_LTE_NS_CONFIG_UL_POWER

   Configures the active resource blocks and modulation type for the LTE uplink waveform, overriding the settings in the DL DCI1.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iTxChain =   0 = Tx 0
                  1 = Tx 1 (currently not supported)

   \param iTxPwrCtrlMode = Selects the transmitter power control mode
                     0 = enable power control bits
                     1 = direct tx level setting

   \param iTxLevel =   Indicates the power level in 10/dBm units as signed number.
                  This field is only used if TX_POWER_CONTROL_MODE is set to a value of 1

                  For example, use 230 for 23dBm.

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_CONFIG_UL_POWER( HANDLE hResourceContext, unsigned char iTxChain, unsigned char iTxPwrCtrlMode, short iTxLevel, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, QLIB_FTM_LTE_NS_TDD_CONFIG

   Configures the subframe assignment and special subframe number patterns.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iSubframeAssign =   LTE_L1_TDD_UL_DL_CFG_0 = 0,
                              LTE_L1_TDD_UL_DL_CFG_1 = 1,
                              LTE_L1_TDD_UL_DL_CFG_2 = 2,
                              LTE_L1_TDD_UL_DL_CFG_3 = 3,
                              LTE_L1_TDD_UL_DL_CFG_4 = 4,
                              LTE_L1_TDD_UL_DL_CFG_5 = 5,
                              LTE_L1_TDD_UL_DL_CFG_6 = 6,
                              LTE_L1_TDD_UL_DL_CFG_UNKNOWN_WITH_UNKNOWN_10MS_FRAME = 7,
                              LTE_L1_TDD_UL_DL_CFG_UNKONWN_WITH_KNOWN_10MS_FRAME   = 8 ,

   \param iSpecialSubFNPatterns =   LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_0 = 0,
                                    LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_1,
                                    LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_2,
                                    LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_3,
                                    LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_4,
                                    LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_5,
                                    LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_6,
                                    LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_7,
                                    LTE_L1_TDD_SPECIAL_SUBFRAME_PATTERN_8,

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_TDD_CONFIG( HANDLE hResourceContext, unsigned char iSubframeAssign, unsigned char iSpecialSubFNPatterns, unsigned long* pStatus );



   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, FTM_LTE_NS_GET_DL_LEVEL

   Returns downlink RX AGC and RX Level in dBm/10 units, for a specified receiver

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRxChain =   0 = Rx 0
                  1 = Rx 1
                  2 = Rx 2
                  3 = Rx 3

   \param iTxPwrC = Selects the transmitter power control mode
                     0 = enable power control bits
                     1 = direct tx level setting

   \param iRxAGC =      Receiver power in Rx AGC Units

   \param iRxLevel =   Receiver power in dBm/10 units. For example, -700 = -70dBm

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_GET_DL_LEVEL( HANDLE hResourceContext, unsigned char iRxChain, short* iRxAGC, short* iRxLeveldBm10, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, FTM_LTE_NS_RESET_DL_BLER_REPORT

   Resets the downlink BLER accumulators for a specified receiver.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_RESET_DL_BLER_REPORT( HANDLE hResourceContext, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, FTM_LTE_NS_GET_DL_BLER_REPORT

   Resets the downlink BLER accumulators for a specified receiver.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iTotalBlockReceived = Total number of blocks that have been received since FTM_LTE_NS_RESET_DL_BLER_REPORT was called

   \param iTotalBlockError = Total number of blocks errors that have been received since FTM_LTE_NS_RESET_DL_BLER_REPORT was called.

   \param iThroughput = Throughput, in bits/second, since FTM_LTE_NS_RESET_DL_BLER_REPORT was called.

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_GET_DL_BLER_REPORT( HANDLE hResourceContext, unsigned long* iTotalBlockReceived, unsigned long* iTotalBlockError, unsigned long* iThroughput, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, QLIB_FTM_LTE_EARLY_PASS_BLER_LIMIT
   Returns the LTE BLER limit for the number of received blocks according to early exit criterion. 
   The pass fail limit should to ensure that the % of BLER <= the value returned. 
   Reference - 3GPP 36.521-1 table G.2.4-1

   \param ulBlocks_Received = Total number of blocks that have been received since FTM_LTE_NS_RESET_DL_BLER_REPORT was called

   \return

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API double QLIB_FTM_LTE_EARLY_PASS_BLER_LIMIT( unsigned long ulBlocks_Received );
   
   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, FTM_LTE_NS_GET_ALL_CARR_DL_BLER

   Gets BLER for all LTE carriers.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pFTM_LTE_All_Carr_BLER_Info = Pointer to get LTE carrier(s) BLER information

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_GET_ALL_CARR_DL_BLER( HANDLE hResourceContext, void* pFTM_LTE_All_Carr_BLER_Info, unsigned long* pstatus);

   /******************************************************************************/
   /**

   Starts logging LTE AGC (LOG_FTM2_LTE_TX_AGC) packets.

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function QLIB_FTM_LTE_Tx_AGC_WaitForNextLog() can be called
   to wait for the next WCDMA log message and have the values returned.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

        1. Before this function is called, the phone must be set in a LTE FTM mode,
         by calling either QLIB_FTM_SET_MODE() for basic RF testing, or by starting
         LTE NS Call.

      2. This function will set the async messasge logging status to ON, to
           turn off async messages, QLIB_DIAG_SetPhoneLoggingState() should be called.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Tx_AGC_Start_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Starts logging LTE AGC (LOG_FTM2_LTE_TX_AGC_ENH) packets.

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function QLIB_FTM_LTE_Tx_AGC_Enh_WaitForNextLog() can be called
   to wait for the next WCDMA log message and have the values returned.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

   1. Before this function is called, the phone must be set in a LTE FTM mode,
   by calling either QLIB_FTM_SET_MODE() for basic RF testing, or by starting
   LTE NS Call.

   2. This function will set the async messasge logging status to ON, to
   turn off async messages, QLIB_DIAG_SetPhoneLoggingState() should be called.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Tx_AGC_Enh_Start_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Starts logging LTE AGC (LOG_FTM2_LTE_RX_AGC) packets.

   This command calls the FTM_LOG_ENABLE() function with the proper settings.
   Subsequently the function QLIB_FTM_LTE_Rx_AGC_WaitForNextLog() can be called
   to wait for the next WCDMA log message and have the values returned.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

        1. Before this function is called, the phone must be set in a LTE FTM mode,
         by calling either QLIB_FTM_SET_MODE() for basic RF testing, or by starting
         LTE NS Call.

      2. This function will set the async messasge logging status to ON, to
           turn off async messages, QLIB_DIAG_SetPhoneLoggingState() should be called.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Rx_AGC_Start_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Wait a specified number of milliseconds for the next LTE Tx AGC log message.

   If the message is found, then the contents of the message are copied into a
   FTM2LogMessage_LTE_Tx_AGC structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pLTE_Tx_AGC_Log = pointer to the area to store the LTE AGC log information.
                           This is of type "FTM2LogMessage_LTE_Tx_AGC" defined in
                     QLIB_Defines.h
   \param iTimeout_ms = # of milliseconds to wait for the LTE log.  Default is 300ms

   \return true if a valid LTE log was found within the specified timeout, false if not.

   \warning Before this function is called, QLIB_FTM_LTE_Tx_AGC_Start_Log() must be
          called to setup capturing of LTE Tx AGC messages.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Tx_AGC_WaitForNextLog( HANDLE hResourceContext,
         void* pLTE_Tx_AGC_Log,
         unsigned long iTimeout_ms );

   /******************************************************************************/
   /**

   Wait a specified number of milliseconds for the next LTE Tx AGC Enhanced log message.

   If the message is found, then the contents of the message are copied into a
   FTM2LogMessage_LTE_Tx_AGC_Enh structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pLTE_Tx_AGC_Log = pointer to the area to store the LTE AGC log information.
   This is of type "FTM2LogMessage_LTE_Tx_AGC_Enh" defined in
   QLIB_Defines.h
   \param iTimeout_ms = # of milliseconds to wait for the LTE log.  Default is 300ms

   \return true if a valid LTE log was found within the specified timeout, false if not.

   \warning Before this function is called, QLIB_FTM_LTE_Tx_AGC_Start_Log() must be
   called to setup capturing of LTE Tx AGC messages.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Tx_AGC_Enh_WaitForNextLog( HANDLE hResourceContext,
      void* pLTE_Tx_AGC_Log,
      unsigned long iTimeout_ms );

   /******************************************************************************/
   /**

   Wait a specified number of milliseconds for the next LTE Rx AGC log message.

   If the message is found, then the contents of the message are copied into a
   FTM2LogMessage_LTE_Rx_AGC structure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pLTE_Rx_AGC_Log = pointer to the area to store the LTE AGC log information.
                           This is of type "FTM2LogMessage_LTE_Rx_AGC" defined in
                     QLIB_Defines.h
   \param iTimeout_ms = # of milliseconds to wait for the LTE log.  Default is 300ms

   \return true if a valid LTE log was found within the specified timeout, false if not.

   \warning Before this function is called, QLIB_FTM_LTE_Rx_AGC_Start_Log() must be
          called to setup capturing of LTE Tx AGC messages.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Rx_AGC_WaitForNextLog( HANDLE hResourceContext,
         void* pLTE_Rx_AGC_Log,
         unsigned long iTimeout_ms );

   /******************************************************************************/
   /**

   Stop logging LTE AGC (LOG_FTM2_LOG_LTE_Tx_AGC) packets.  This is important
   to do before changing RF modes or starting/stopping LTE NS testing.

   This command calls the FTM_LOG_DISABLE() function with the proper settings.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function will set the async message logging status to OFF.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Tx_AGC_Stop_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Stop logging LTE AGC (LOG_FTM2_LOG_LTE_Tx_AGC_ENH) packets.  This is important
   to do before changing RF modes or starting/stopping LTE NS testing.

   This command calls the FTM_LOG_DISABLE() function with the proper settings.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function will set the async message logging status to OFF.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Tx_AGC_Enh_Stop_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   Stop logging LTE AGC (LOG_FTM2_LOG_LTE_Rx_AGC) packets.  This is important
   to do before changing RF modes or starting/stopping LTE NS testing.

   This command calls the FTM_LOG_DISABLE() function with the proper settings.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function will set the async message logging status to OFF.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_Rx_AGC_Stop_Log( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   This command Measures the LTE PDSCH BLER value for a give Loopback Type and updates the pSE_BER_State pointer.
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pLTE_PDSCH_BLER_Status  = Pointer the LTE_PDSCH_BLER_Status structure defined in QLib_Defines.h

   \param iMeasurementCount = Number of ACKs and NACKs to be collected for each LTE PDSCH BLER measurement.

   \param iTimeOut_ms =  Time out duration before exiting the LTE PDSCH BLER measurement.

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_LTE_PDSCH_BLER_DoMeasurement(
      HANDLE hResourceContext,
      void *pLTE_PDSCH_BLER_Status,
      unsigned long iMeasurementCount,
      unsigned long iTimeOut_ms
   );

   /******************************************************************************/
   /**
   High level function to start PDSCH Logs, including setting the diagnostic log mask

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_LTE_PDSCH_BLER_Start_Log(HANDLE hResourceContext );

   /******************************************************************************/
   /**
   High level function to stop PDSCH Logs, including setting the diagnostic log mask

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_LTE_PDSCH_BLER_Stop_Log(HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_ENABLE_SCELL

   This command configures and activates SCELL.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iBand           = SCELL LTE Band, this number is BC number minus 1.  For example, for BC13, band value is 12

   \param iEARFCN         = SCELL DL Channel

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_ENABLE_SCELL( HANDLE hResourceContext, unsigned char iBand, unsigned long iEARFCN, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands QLIB_FTM_LTE_NS_DISABLE_SCELL

   This command disables the SCELL mode and puts the UE back in PCELL only mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pStatus = 0  Success
                    1  Failure
                    2  Not Allowed
                    12  In progress
                    13  Already done
                    16  Invalid Argument
                    20  Bad data
                    55  Busy

   \return
      \code
          true  = Success
          false = Failure
      \endcode

    \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_DISABLE_SCELL( HANDLE hResourceContext, unsigned long* pStatus );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, QLIB_FTM_LTE_NS_ENABLE_MULTI_SCELL

   Configures and Activates SCELL<x> based on the bit mask. UE should be in connected state.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param icarrier_cfg = Carrier config bit mask. Bit0  SCELL1, Bit1  SCELL2 and so on. 
                         The bitmask should have only one bit ON at a time. Adding more than one Scell with a single command is not supported.

   \param pFTM_LTE_NS_Multi_SCC_Config = pointer to a structure that has scc<x> band, channel  and cell ID information

   \param pStatus =  0 ?Success
                     1 ?Failure
                     2 ?Not Allowed
                     12 ?In progress
                     13 ?Already done
                     16 ?Invalid Argument
                     20 ?Bad data
                     55 ?Busy

   \return
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_ENABLE_MULTI_SCELL (HANDLE hResourceContext, unsigned char icarrier_cfg, void* pFTM_LTE_NS_Multi_SCC_Config, unsigned long *pstatus);
   
   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, QLIB_FTM_LTE_NS_DISABLE_MULTI_SCELL

   Disables SCELL<x> based on the bitmask  and puts the UE in PCELL mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param icarrier_decfg = Carrier de-config bit mask. Bit0  SCELL1, Bit1  SCELL2 and so on. 
                         The bitmask should have only one bit ON at a time. Disabling more than one Scell with a single command is not supported.

   \param pStatus =  0 ?Success
                     1 ?Failure
                     2 ?Not Allowed
                     12 ?In progress
                     13 ?Already done
                     16 ?Invalid Argument
                     20 ?Bad data
                     55 ?Busy

   \return
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_DISABLE_MULTI_SCELL (HANDLE hResourceContext, unsigned char icarrier_decfg, unsigned long *pstatus);

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, QLIB_FTM_LTE_NS_ENABLE_MULTI_SCELL_UL_DL

   Configures and Activates SCELL<x> UL & DL based on the bit mask. UE should be in connected state.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iulcarrier_cfg = SCC UL carrier config bit mask. Bit0  SCELL1, Bit1  SCELL2 and so on. 
                           The bitmask should have only one bit ON at a time. Adding more than one Scell with a single command is not supported.

   \param idlcarrier_cfg = SCC DL carrier config bit mask. Bit0  SCELL1, Bit1  SCELL2 and so on. 
                           The bitmask should have only one bit ON at a time. Adding more than one Scell with a single command is not supported.

   \param pFTM_LTE_NS_Multi_SCC_UL_DL_Config = pointer to a structure that has scc<x> UL and DL parameters

   \param pStatus =  0 ?Success
                     1 ?Failure
                     2 ?Not Allowed
                     12 ?In progress
                     13 ?Already done
                     16 ?Invalid Argument
                     20 ?Bad data
                     55 ?Busy

   \return
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_ENABLE_MULTI_SCELL_UL_DL (HANDLE hResourceContext, unsigned char iulcarrier_cfg, unsigned char idlcarrier_cfg, void* pFTM_LTE_NS_Multi_SCC_UL_DL_Config,unsigned long *pstatus);

   /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, QLIB_FTM_LTE_NS_DISABLE_MULTI_SCELL_UL_DL

   Disables SCELL<x> UL/DL based on the bitmask  and puts the UE in PCELL mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iulcarrier_decfg = SCC UL Carrier de-config bit mask. Bit0  SCELL1, Bit1  SCELL2 and so on. 
                           The bitmask should have only one bit ON at a time. Disabling more than one Scell with a single command is not supported.

   \param idlcarrier_decfg = SCC DL Carrier de-config bit mask. Bit0  SCELL1, Bit1  SCELL2 and so on. 
                           The bitmask should have only one bit ON at a time. Disabling more than one Scell with a single command is not supported.

   \param pStatus =  0 ?Success
                     1 ?Failure
                     2 ?Not Allowed
                     12 ?In progress
                     13 ?Already done
                     16 ?Invalid Argument
                     20 ?Bad data
                     55 ?Busy

   \return
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_DISABLE_MULTI_SCELL_UL_DL (HANDLE hResourceContext,  unsigned char iulcarrier_decfg, unsigned char idlcarrier_decfg, unsigned long *pstatus);

         /******************************************************************************/
   /**
   Factory Test Mode LTE Non-Signaling Command, FTM_LTE_NS_RX_SELECT_CHAIN_REQ

   Select Rx Chain as the active decoding chain.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iCarrier0RxChain = carrier 0 rx chain mask. 0 = PRx, 1 = DRx, 2 = DRx2, 3 = DRx3

   \param iCarrier1RxChain = carrier 1 rx chain mask. 0 = PRx, 1 = DRx, 2 = DRx2, 3 = DRx3

   \param iCarrier2RxChain = carrier 2 rx chain mask. 0 = PRx, 1 = DRx, 2 = DRx2, 3 = DRx3

   \param iCarrier3RxChain = carrier 3 rx chain mask. 0 = PRx, 1 = DRx, 2 = DRx2, 3 = DRx3

   \param iCarrier4RxChain = carrier 4 rx chain mask. 0 = PRx, 1 = DRx, 2 = DRx2, 3 = DRx3

   \param pStatus =  0  Success
                     1  Failure
                     2  Not Allowed
                     12  In progress
                     13  Already done
                     16  Invalid Argument
                     20  Bad data
                     55  Busy

   \return

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NS_RX_SELECT_CHAIN_REQ (HANDLE hResourceContext,  unsigned char iCarrier0RxChain, unsigned char iCarrier1RxChain, unsigned char iCarrier2RxChain, unsigned char iCarrier3RxChain, unsigned char iCarrier4RxChain, unsigned long *pstatus);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_LTE_NS_H)
