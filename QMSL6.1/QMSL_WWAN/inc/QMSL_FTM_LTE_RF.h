/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_LTE_RF.h#8 $
 * $DateTime: 2016/04/04 17:23:23 $
 *
 * DESCRIPTION: QMSL_FTM_LTE_RF
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_LTE_RF_H)
#define _QMSL_FTM_LTE_RF_H

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
                  LTE RF Calibration Commands
   *******************************************************************************/


   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), QLIB_FTM_LTE_SET_TX_BANDWIDTH

   This command configures the phone Tx chain bandwidth.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

    \param itxChanBW =  0 - RFCOM_BW_LTE_1P4MHz
                  1 - RFCOM_BW_LTE_3MHz
                  2 - RFCOM_BW_LTE_5MHz
                  3 - RFCOM_BW_LTE_10MHz
                  4 - RFCOM_BW_LTE_15MHz
                  5 - RFCOM_BW_LTE_20MHz

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_LTE_SET_TX_BANDWIDTH( HANDLE hResourceContext, unsigned char itxChanBW );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1),QLIB_FTM_LTE_SET_RX_BANDWIDTH

   This command configures the phone Tx Chain.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

    \param irxChanBW =  0 - RFCOM_BW_LTE_1P4MHz
                  1 - RFCOM_BW_LTE_3MHz
                  2 - RFCOM_BW_LTE_5MHz
                  3 - RFCOM_BW_LTE_10MHz
                  4 - RFCOM_BW_LTE_15MHz
                  5 - RFCOM_BW_LTE_20MHz

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_LTE_SET_RX_BANDWIDTH( HANDLE hResourceContext, unsigned char irxChanBW );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands : QLIB_FTM_LTE_SET_TX_CARRIER_INDEX

   This command directs the mobile to set the Current Carrier Index in FTM state machine.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param piFTMErrorCode = FTM Error Code : 0 - Success; 1 - Failure;

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_LTE_SET_TX_CARRIER_INDEX( HANDLE hResourceContext, unsigned char * piFTMErrorCode);

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), FTM_LTE_GET_RXAGC_DATA

   This command queries the phone for RXAGC and LNA state data and can return data for up to 4 Rx chains.
   Note: Some rx chain IDs may be invalid on some targets.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

    \param iRxChainMask =  mask to request data for up to 4 rx chains (0 through 3)
      \code
         bit 0 = Request data for chain RX0
         bit 1 = Request data for chain RX1
         bit 2 = Request data for chain RX2
         bit 3 = Request data for chain RX3
      \endcode
   \param piNumChains = Returns the # of chains for which data is valid
   \param piRx0AGC = Returns the RXAGC value for chain RX0
   \param piRx0LnaState = Returns the LNA Range value for chain RX0
   \param piRx1AGC = Returns the RXAGC value for chain RX1
   \param piRx1LnaState = Returns the LNA Range value for chain RX1
   \param piRx2AGC = Returns the RXAGC value for chain RX2
   \param piRx2LnaState = Returns the LNA Range value for chain RX2
   \param piRx3AGC = Returns the RXAGC value for chain RX3
   \param piRx3LnaState = Returns the LNA Range value for chain RX3

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_LTE_GET_RXAGC_DATA(
      HANDLE hResourceContext,
      unsigned char iRxChainMask,
      unsigned char* piNumChains,
      short* piRx0AGC,
      unsigned char* piRx0LnaState,
      short* piRx1AGC,
      unsigned char* piRx1LnaState,
      short* piRx2AGC,
      unsigned char* piRx2LnaState,
      short* piRx3AGC,
      unsigned char* piRx3LnaState
   );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), QLIB_FTM_LTE_SET_TX_MODULATION_TYPE

   This command configures the mobile Tx modulation type

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iModulationType  = 0 - QPSK, 1 - 16 QAM, 2 - 64 QAM

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/


   QLIB_API unsigned char QLIB_FTM_LTE_SET_TX_MODULATION_TYPE( HANDLE hResourceContext, unsigned long iModulationType);
   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), QLIB_FTM_LTE_SET_TX_WAVEFORM

   This command configures the phone Tx Waveform.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTxWaveform  = 0-CW, 1- PUSCH, 2- PUCCH, 3 - PRACH, 4 - SRS, 5 - UpPTS
    \param inumRBsPUSCH = Number of UL resource blocks to transmit on the PUSCH.
    \param inumRBsPUCCH = Number of UL resource blocks to transmit on the PUCCH.
   \param iPUSCHStartRBIndex = Starting resource block index on the PUSCH.

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_LTE_SET_TX_WAVEFORM( HANDLE hResourceContext, unsigned char iTxWaveform, unsigned char inumRBsPUSCH, unsigned char inumRBsPUCCH,unsigned char iPUSCHStartRBIndex );

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), QLIB_FTM_LTE_STOP_TX_WAVEFORM

   This command stops the phone LTE Tx Waveform transmission.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_LTE_STOP_TX_WAVEFORM( HANDLE hResourceContext );


   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), QLIB_FTM_SET_TX_GAIN_INDEX

   This command sets the Gain Index on from the corresponding LUT (characterization) table.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTxGainIndex  = Gain Index to set.

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SET_TX_GAIN_INDEX( HANDLE hResourceContext, unsigned short iTxGainIndex);

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), configure and execute LTE Tx Calibration Sweep

   This command sets the time interval of each step in the Tx calibration sweep
   and the number of HDET readings averaged per step.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRsvd = Reserved. Use 0
   \param  iTimeInterval = 2,20,40,60,80 ms

                            The time interval is how long the step is (in time).  We found that a 2ms
                     step time is ideal and anything below that is not repeatable.

   \param iGainIndexStepSize =  Gain Index step delta between adjacent steps.


   \param  iNumofHDETReadingsPerStep= Number of HDET reads for averaging (from 1 to 255)
                                       During the top 32 power steps, the HDET will be measured.
                              During the measurement of the HDET, each value is averaged
                              with other HDET readings at the same power level.   This
                              setting controls how many HDET averages are taken during
                              each power step.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_CONFIGURE_TX_SWEEP_CAL
   ( HANDLE hResourceContext, unsigned short iRsvd, unsigned short iTimeInterval, unsigned char iGainIndexStepSize, unsigned char iNumofHDETReadingsPerStep);


   /******************************************************************************/
   /**

   Factory Test Mode LTE Commands, (80-VR832-1) FTM LTE SET LNA STATE DBM

   Sets the Rx LNA range based on a target dBm downlink level.
   The LNA is selected based on the appropriate associated NV items for the LNA switch
   points, for the current band.  The LNA state selection will follow the LNA rise/fall
   hysteresis rules. Returns the selected LNA range identifier.

   \param hResourceContext = Resource context that was returned from the call
                             to QLIB_ConnectServer()

   \param iExpected_RX_Power_dBm = Expected Rx power in 1/10 dBm units; this is a signed number

   \param iSelected_LNA_Range = The Programed LNA Range that was selected,  based on expected
                                Rx power  value

   \param iFTM_Error_Code = FTM Error code returned by FTM command
         *   0  Success
         *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
                     It will only be available in AMSS MSM8974 equivalents according to the
                     Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_SET_LNA_STATE_DBM ( HANDLE hResourceContext ,
         short iExpected_RX_Power_dBm,
         unsigned char* iSelected_LNA_Range,
         unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**

   Factory Test Mode LTE Commands, 2.1.14(80-VR832-1) FTM LTE SET NET SIG VALUE

   FTM_LTE_SET_NET_SIG_VALUE configures the LTE NS means Network Signal that will be used
   for the FTM_SET_TX_POWER_DBM command. Network Signal utilizes Additional Max Power Back-off
   to reduce spectrum emissions.

   This API has the following runtime dependencies.
   *   This command must follow the FTM_SET_TX_POWER_DBM function.

   \param hResourceContext = Resource context that was returned from the call
                             to QLIB_ConnectServer()

   \param iNS = Configures the NS value, which affects maximium output power according to
                Section 6.6.2.2.1 Minimum requirement (network signalled value "NS_03") in [R1]

   The valid settings are 1-32.
   This field is used only if the Enable field of FTM_SET_TX_POWER_DBM is set to a
   value of 1.

   \param iFTM_Error_Code = FTM Error code returned by FTM command
         *   0  Success
         *   1  Failure occurred

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_LTE_SET_NET_SIG_VALUE( HANDLE hResourceContext, unsigned char iNS, unsigned short* iFTM_Error_Code);
   
   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), QLIB_FTM_LTE_GET_HORXD_BAND_SUPPORT_STATUS

   This command queries whether a specified band supports HORxD.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param rfMode  = rfMode to set
    \param supportStatus = Pointer to the variable to store the status of horxd_support

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_GET_HORXD_BAND_SUPPORT_STATUS( HANDLE hResourceContext, unsigned char rfMode, unsigned char* supportStatus);

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands(80-VR832-1), 2.1.31 Set fixed vectors for TX
   
   This command directs the mobile to use fixed vectors for TX.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  useFixedVector = 0 = Reset / Do not use fixed vector
                            1 = Set / Use fixed vector

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_USE_FIXED_VECTOR (  HANDLE hResourceContext, bool useFixedVector );

   
   /******************************************************************************/
   /**
   QLIB_FTM_LTE_NLIC_PARAMS_OVERRIDE command is used to override NLIC params such as delay, kernel selection, on/off etc

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  pNLICConfigRequestParams = Pointer to the structure with NLIC configuration request params
   \param  pStatus = Pointer to the variable to store the status of NLIC params override

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_NLIC_PARAMS_OVERRIDE( HANDLE hResourceContext, void *pNLICConfigRequestParams, unsigned short* pStatus);


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_LTE_RF_H)

