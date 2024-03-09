/******************************************************************************
 * *$Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_RF.h#67 $
 * *$DateTime: 2016/06/24 11:41:42 $
 *
 * DESCRIPTION: QMSL_FTM_RF
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_RF_H)
#define _QMSL_FTM_RF_H

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
   Commands for multiple FTM modes
   *******************************************************************************/

   /******************************************************************************/
   /**

   Factory Test Mode WCDMA Commands 3.2.1.9, Set mode

   Factory Test Mode GSM Commands 3.5, Set mode

   Factory Test Mode 1x RF Commands 3.2.11 (CL93-V5419-1)Set mode

   Factory Test Mode RF Commands 3.3.1.10 (CL93-V4168-1) Set mode

   This function sets the RF operating mode of the mobile. It initializes all of the necessary
   hardware to place the mobile in the requested RF mode.



   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  _eNewMode  = specifies the mode that the phone is to enter.
   FTM_RF_Mode_Enum is the definitive list of available modes.

   The following modes are defined by the enumeration, "ftm_mode_id_type" in the embedded software
   file services\ftm\ftm.h.
   \code
   PHONE_MODE_FM        = 1      (FM)
   PHONE_MODE_GPS       = 3      (GPS)
   PHONE_MODE_GPS_SINAD = 4      (GPS SINAD)
   PHONE_MODE_CDMA_800  = 5      (CDMA 800)
   PHONE_MODE_CDMA_1900 = 6      (CDMA 1900)
   PHONE_MODE_CDMA_1800 = 8      (CDMA 1800)
   PHONE_MODE_J_CDMA    = 14     (JCDMA)
   PHONE_MODE_CDMA_450  = 17     (CDMA 450)
   PHONE_MODE_CDMA_IMT  = 19     (CDMA IMT)

   PHONE_MODE_WCDMA_IMT   =9      (WCDMA IMT, Band I)
   PHONE_MODE_GSM_900     =10     (GSM 900)
   PHONE_MODE_GSM_1800    =11     (GSM 1800)
   PHONE_MODE_GSM_1900    =12,    (GSM 1900)
   PHONE_MODE_WCDMA_1900A =15,    (WCDMA 1900 A, Band II Add)
   PHONE_MODE_WCDMA_1900B =16,    (WCDMA 1900 B, Band II Gen)
   PHONE_MODE_GSM_850     =18,    (GSM 850)
   PHONE_MODE_WCDMA_800   =22,    (WCDMA 800, Band V Gen)
   PHONE_MODE_WCDMA_800A  =23,    (WCDMA 800, Band V Add)
   PHONE_MODE_WCDMA_1800  =25,    (WCDMA 1800, Band III)
   PHONE_MODE_WCDMA_BC4   =28,    (WCDMA BC4-used for both Band IV Gen and Band IV Add)
   PHONE_MODE_WCDMA_BC8   =29,    (WCDMA BC8, Band VIII)
   PHONE_MODE_MF_700      =30,    (MediaFLO)
   PHONE_MODE_WCDMA_BC9   =31,    (WCDMA BC9 (1750MHz & 1845MHz), Band IX)
   PHONE_MODE_CDMA_BC15   =32     (CDMA Band Class 15)

   PHONE_MODE_LTE_B1      =34,       (LTE Band Class 1)
   PHONE_MODE_LTE_B7     =35,      (LTE Band Class 7)
   PHONE_MODE_LTE_B13    =36,    (LTE Band Class 13)
   PHONE_MODE_LTE_B17    =37,     (LTE Band Class 17)
   PHONE_MODE_LTE_B38    =38,    (LTE Band Class 38)
   PHONE_MODE_LTE_B40    =39,    (LTE Band Class 40)
   PHONE_MODE_WCDMA_1500=40,      //!<' WCDMA BC11 (1500MHz) Band XI

   PHONE_MODE_LTE_B2=43,
   PHONE_MODE_LTE_B3=44,
   PHONE_MODE_LTE_B5=45,
   PHONE_MODE_LTE_B6=46,
   PHONE_MODE_LTE_B8=47,
   PHONE_MODE_LTE_B9=48,
   PHONE_MODE_LTE_B10=49,
   PHONE_MODE_LTE_B12=50,
   PHONE_MODE_LTE_B14=51,
   PHONE_MODE_LTE_B15=52,
   PHONE_MODE_LTE_B16=53,
   PHONE_MODE_LTE_B18=54,
   PHONE_MODE_LTE_B19=55,
   PHONE_MODE_LTE_B20=56,
   PHONE_MODE_LTE_B21=57,
   PHONE_MODE_LTE_B22=58,
   PHONE_MODE_LTE_B23=59,
   PHONE_MODE_LTE_B24=60,
   PHONE_MODE_LTE_B25=61,
   PHONE_MODE_LTE_B26=62,
   PHONE_MODE_LTE_B27=63,
   PHONE_MODE_LTE_B28=64,
   PHONE_MODE_LTE_B29=65,
   PHONE_MODE_LTE_B30=66,
   PHONE_MODE_LTE_B31=67,
   PHONE_MODE_LTE_B32=68,
   PHONE_MODE_LTE_B33=69,
   PHONE_MODE_LTE_B34=70,
   PHONE_MODE_LTE_B35=71,
   PHONE_MODE_LTE_B36=72,
   PHONE_MODE_LTE_B37=73,
   PHONE_MODE_LTE_B39=74,

   PHONE_MODE_WCDMA_BC19=75,     //!<' WCDMA BC19 (subset of 800MHz) Band XIX
   PHONE_MODE_LTE_B41=76,
   PHONE_MODE_LTE_B42=77,
   PHONE_MODE_LTE_B43=88,
   PHONE_MODE_LTE_B39_B=78,
   PHONE_MODE_LTE_B45=79,

   PHONE_MODE_LTE_B252=80,
   PHONE_MODE_LTE_B255=82,

   PHONE_MODE_LTE_B66=83,
   PHONE_MODE_LTE_B46=89,

   //TDSCDMA reserves 90 - 99
   PHONE_MODE_TDSCDMA_B34=90,
   PHONE_MODE_TDSCDMA_B39=91,
   PHONE_MODE_TDSCDMA_B40=92,
   PHONE_MODE_MAX         =255    (Last possible value, not a valid mode)

   \endcode

   \return true if successful, false if fail.

   \warning Must be called before any other FTM RF commands.
   \warning,  If the new mode is a GSM RF mode, a delay will be issued after the command
   is successfully sent to the mobile.  The duration of the delay is based on the
   value of delay type "QMSL_Timeout_Delay_GSM_RF_Mode" which can be controled by
   QLIB_ConfigureTimeOut() and read by QLIB_GetTimeOut()

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_MODE( HANDLE hResourceContext, short eNewMode );

   /******************************************************************************/

   /**
   This function gets the RF operating mode set previously using QLIB_FTM_SET_MODE_ID.
   It returns internal variable Diag_FTM::m_System_Mode
   Caller will have to cast iSystem_Mode to FTM_Mode_Id_Enum type

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iSystem_Mode  = specifies the mode that the phone is set to.

   FTM_Mode_Id_Enum is the definitive list of available modes.
   /******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_MODE_ID( HANDLE hResourceContext, short *iSystem_Mode );

   /******************************************************************************/
   /**

   This function sets the RF sub block mask of the mobile , for the RF mode set in the QLIB_FTM_SET_MODE()
   command

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  _eIndex  = Specifies the block NV or parent NV to be written to.

   \code
   _eIndex = -1 ( Writing to the Parent Band Class NV )
   _eIndex = 0  ( Pointing to the Band Class and Block mask corresponding to the Block 0 NV )
   _eIndex = 1  (  Pointing to the Band Class and Block mask corresponding to the Block 1 NV )

   \endcode
   \param  _eBlockMask  = Specifies the block mask to be set for the RF mode set in QLIB_FTM_SET_MODE().
   The block mask should be a mask where Block A = bit 0 , Block B = bit 1 and so on.

   \return true if successful, false if fail.

   \warning QLIB_FTM_SET_MODE should be called before this command.
   \warning This command should be called before any other RF commands.


   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_BLOCK_MASK( HANDLE hResourceContext, short eIndex , unsigned long eBlockMask );

   /******************************************************************************/
   /**

   This function returns the command mode (59, 75 or -1 (invalid));

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iCommandMode     = Detected command mode.  The value can be 59 (used in MSM6000/6025/6050),
   75, or -1 (invalid)

   \return true if successful, false if fail.

   *******************************************************************************/


   QLIB_API unsigned char QLIB_FTM_DETECT_COMMAND_CODE( HANDLE hResourceContext, short* iCommandMode );

   /******************************************************************************/
   /**

   This function sets the command code (59 or 75);

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eCommandMode       = Command code (59 or 75)

   Note: The library uses command code 75 by default. MSM6000/6025/6050 uses commmand code 59.
   For MSM6000/6025/6050, this function should be called prior to other FTM functions

   \return true if successful, false otherwise

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SET_COMMAND_CODE( HANDLE hResourceContext, short eCommandCode );

   /******************************************************************************/
   /**

   This function gets the command code (59 or 75) used by the handle

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eCommandMode       = Command code (59 or 75)

   \return true if successful, false otherwise

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_COMMAND_CODE( HANDLE hResourceContext, short* eCommandCode );

   /******************************************************************************/
   /**

   This function sets the system mode ID used by subsequent FTM API calls.
   It does not send diagnostic command to the mobile

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param eModeId = Mode ID

   The Mode IDs are from the FTM_Mode_Id_Enum in QLib_Defines.h
   \code
   FTM_MODE_ID_CDMA_1X     = 0,      //!<' RF CDMA 1X mode - RX0
   FTM_MODE_ID_WCDMA       = 1,      //!<' RF WCDMA mode
   FTM_MODE_ID_GSM         = 2,      //!<' RF GSM Mode
   FTM_MODE_ID_CDMA_1X_RX1 = 3,      //!<' RF CDMA 1X mode - RX1
   FTM_MODE_ID_BLUETOOTH   = 4,      //!<' Bluetooth
   FTM_MODE_ID_CDMA_1X_CALL= 7,      //!<' CALL CDMA 1X mode
   FTM_MODE_ID_LOGGING     = 9,      //!<' FTM Logging
   FTM_MODE_ID_AGPS        = 10,      //!<' Async GPS
   FTM_MODE_ID_PMIC        = 11,      //!<' PMIC FTM Command
   FTM_MODE_GSM_BER        = 13,      //!<' GSM BER
   FTM_MODE_ID_AUDIO       = 14,      //!<' Audio FTM
   FTM_MODE_ID_CAMERA      = 15,      //!<' Camera
   FTM_MODE_WCDMA_BER      = 16,      //!<' WCDMA BER
   FTM_MODE_ID_GSM_EXTENDED_C = 17,   //!<' GSM Extended commands
   FTM_MODE_CDMA_API_V2    = 18,      //!<' CDMA RF Cal API v2
   FTM_MODE_ID_MF_C        = 19,      //!<' MediaFLO
   FTM_MODE_RF_COMMON      = 20,      //!<' RF Common
   FTM_MODE_WCDMA_RX1      = 21,      //!<' WCDMA Diversity Rx (RX1)
   FTM_MODE_CDMA_C2        = 32,      //!<' CDMA C2
   FTM_MODE_CDMA_C3        = 40,      //!<' CDMA C3
   FTM_MODE_CDMA_C4        = 45,      //!<' CDMA C4
   FTM_MODE_ID_PRODUCTION  = 0x8000,   //!<' Production FTM
   FTM_MODE_ID_LTM         = 0x8001   //!<' LTM
   \endcode
   Note: This function sets

   \return true if successful, false otherwise

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SET_MODE_ID( HANDLE hResourceContext, short eModeId );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.1 Set PDM

   Factory Test Mode 1x RF Commands 3.2.2 (CL93-V5419-1)Set mode

   Factory Test Mode RF Commands 3.3.1.1 (CL93-V4168-1) Set mode

   This command sets the value of the PDM, based on PDM_ID.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iPDMtype  = represents the PDM to be set.
   \code
   WCDMA mode values
   2 - Tx AGC Adjust PDM
   4 - Trk Lo Adjust PDM

   GSM mode values
   0 - Trk Lo Adjust PDM

   CDMA mode values
   2 - Tx AGC Adjust PDM
   4 - Trk Lo Adjust PDM
   \endcode

   \param   iPDMvalue =
   \code
   For WCDMA mode Tx AGC Adjust PDM:
   PDM values from 0 to 511
   0   - lowest AGC voltage
   511 - highest AGC voltage

   For GSM mode values:
   PDM values from 0 to 4096

   For CDMA mode values:
   PDM values from 0 to 511
   0   - highest AGC voltage
   511 - lowest AGC voltage

   For FM mode values:
   PDM values from 0 to 511
   0   - lowest AGC voltage
   511 - highest AGC voltage
   \endcode

   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SET_PDM
   ( HANDLE hResourceContext, unsigned short iPDMtype, unsigned short iPDMvalue );

   /******************************************************************************/
   /**
   This function is the same as QLIB_FTM_SET_PDM(), except the iPDMvalue is signed
   for this version of the function.  This is applicable to the GSM VCTCXO PDM control.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iPDMtype  = represents the PDM to be set.
   \code
   WCDMA mode values
   2 - Tx AGC Adjust PDM
   4 - Trk Lo Adjust PDM

   GSM mode values
   0 - Trk Lo Adjust PDM

   CDMA mode values
   2 - Tx AGC Adjust PDM
   \endcode

   \param   iPDMvalue =
   \code
   For WCDMA mode Tx AGC Adjust PDM:
   PDM values from 0 to 511
   0   - lowest AGC voltage
   511 - highest AGC voltage

   For GSM mode values, the range depends upon the embedded RF software.  The typical ranges are be
   PDM values from -4096 to 4095  or  PDM values from -2048 to 2047

   For CDMA mode values:
   PDM values from 0 to 511
   0   - highest AGC voltage
   511 - lowest AGC voltage

   For FM mode values:
   PDM values from 0 to 511
   0   - lowest AGC voltage
   511 - highest AGC voltage
   \endcode

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SET_PDM_signed
   ( HANDLE hResourceContext, unsigned short iPDMtype, short iPDMvalue );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands x.x.x.x

   Set SMPS PA Bias override mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iOnOff = Override mode on/off

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_SMPS_PA_BIAS_OVERRIDE
   ( HANDLE hResourceContext, unsigned char iOnOff );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands x.x.x.x

   Set SMPS PA Bias value.  QLIB_SET_SET_SMPS_PA_BIAS_OVERRIDE (on) should be called first

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iPA_Bias_Value = Value of the PA Bias

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_SMPS_PA_BIAS_VAL
   ( HANDLE hResourceContext, unsigned short iPA_Bias_Value);


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.12 Set TX on

   Factory Test Mode GSM Commands 3.3 Set Tx ON

   Factory Test Mode 1x RF Commands 3.2.14 (CL93-V5419-1)Set Tx on

   Factory Test Mode RF Commands 3.3.1.13 (CL93-V4168-1) Set Tx on

   CDMA:  This command turns on the phone.s transmit chain (including the PA) and causes a CDMA
   reverse-link waveform to be generated on the current channel. All necessary encoder hardware
   initialization for transmitting is handled by this function.

   WCDMA: This command turns on the phones transmit chain (including the PA) and causes a WCDMA
   uplink waveform or CW to be generated on the current channel. All necessary encoder hardware
   initialization for transmitting is handled by this function.


   GSM:This command turns on the phones transmit chain (including the PA) and causes a GSM uplink
   burst to be generated on the current channel. The data that is transmitted and other parameters of
   transmission are set up by the Set Transmit Burst API (see Section 3.2.1.10).

   Hence, the Set Transmit Burst API must be called at least once after a mode change (to one
   of the GSM modes) and prior to the execution of the Set TX ON API.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \warning GSM: Set Transmit Burst must be setup before calling this function.


   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TX_ON( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.11 Set TX off

   Factory Test Mode GSM Commands 3.4 Set Tx OFF

   Factory Test Mode 1x RF Commands 3.2.13 (CL93-V5419-1)Set Tx off

   Factory Test Mode RF Commands 3.3.1.12 (CL93-V4168-1) Set Tx off

   This command turns off the phones transmit chain.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TX_OFF( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.8 Set LNA range

   Factory Test Mode GSM Commands 3.7 Set LNA range

   Factory Test Mode 1x RF Commands 3.2.10 (CL93-V5419-1)Set LNA range

   Factory Test Mode RF Commands 3.3.1.9 (CL93-V4168-1) Set LNA range

   This command sets the LNA range state machine to the specified state.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iLNArange =

   CDMA: the binary state of the LNA range state machine:
   0 - LNA_R0 - highest gain,
   1 - LNA_R1,
   2 - LNA_R2,
   3 - LNA_R3
   4 - LNA_R4 - lowest gain

   The number of possible gain states varies in different RF chipsets
   Please refer to relevant NV documents for the number of possible gain states.

   WCDMA: the binary state of the LNA range state machine:
   0 - LNA_R0 - highest gain,
   1 - LNA_R1,
   2 - LNA_R2,
   3 - LNA_R3 - lowest gain

   GSM: iLNArange = desired LNA range (0-3), 0 is highest gain, 3 is lowest gain

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_LNA_RANGE( HANDLE hResourceContext, unsigned char iLNArange);


   /******************************************************************************/
   /**
   This command sets the RF concurrency senario to select carriers

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iScenario = 0 Single SIM mode (default scenario)
                       1 DR-DSDS G+W
                       2 DR-DSDS W+W
                       3 DR-DSDS L+W

   \param piFTMErrorCode = 0  Success
                           1  Error

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_CONCURRENCY_SCENARIO( HANDLE hResourceContext, unsigned int iScenario, unsigned char * piFTMErrorCode);

   /******************************************************************************/
   /**
   This command enables/disables the device manager mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDeviceManagerMode = 0 Disable/Bypass
                               1 Enable/SSIM

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DEVICE_MANAGER_MODE( HANDLE hResourceContext, unsigned char iDeviceManagerMode);

   /******************************************************************************/
   /**
   QLIB_FTM_QLNK_SELF_TEST

   This command is used to do QLNK self-test with loop back. The loop-back type can be PreSERDES or SERDES

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iLoopBackType = Loop Back Type

   \param piFTMErrorCode =
   0 Success: TEST_SUCCESS
   1 Failure: CMD_TIME_OUT
   2 Failure: REG_RD_FAILURE
   3 Failure: REG_WR_FAILURE
   4 Failure: START_FAILURE
   5 Failure: STOP_FAILURE
   6 Failure: BER_SET_FAILURE

   \return true if successful, false if fail.

   *******************************************************************************/
   unsigned char QLIB_FTM_QLNK_SELF_TEST( HANDLE hResourceContext, unsigned char iLoopBackType, unsigned char * piFTMErrorCode );

   /******************************************************************************/
   /**
   QLIB_FTM_QLNK_WARM_START

   This command is to test if QLNK HW can be re-started after QLNK is stopped.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param piFTMErrorCode =
   0 Success: TEST_SUCCESS
   1 Failure: CMD_TIME_OUT
   2 Failure: REG_RD_FAILURE
   3 Failure: REG_WR_FAILURE
   4 Failure: START_FAILURE
   5 Failure: STOP_FAILURE
   6 Failure: BER_SET_FAILURE

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QLNK_WARM_START( HANDLE hResourceContext, unsigned char * piFTMErrorCode );

   /******************************************************************************/
   /**
   QLIB_FTM_QLNK_HIBERNATE

   This command is to test if QLNK HW can be stopped in high speed (HS) mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param piFTMErrorCode =
   0 Success: TEST_SUCCESS
   1 Failure: CMD_TIME_OUT
   2 Failure: REG_RD_FAILURE
   3 Failure: REG_WR_FAILURE
   4 Failure: START_FAILURE
   5 Failure: STOP_FAILURE
   6 Failure: BER_SET_FAILURE

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QLNK_HIBERNATE( HANDLE hResourceContext, unsigned char * piFTMErrorCode );

   /******************************************************************************/
   /**
   QLIB_FTM_QLNK_PING_TEST

   This command is to test if QLNK HW can go through with QLNK Ping command. It is a self-check test.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param piFTMErrorCode =
   0 Success: TEST_SUCCESS
   1 Failure: CMD_TIME_OUT
   2 Failure: REG_RD_FAILURE
   3 Failure: REG_WR_FAILURE
   4 Failure: START_FAILURE
   5 Failure: STOP_FAILURE
   6 Failure: BER_SET_FAILURE

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QLNK_PING_TEST( HANDLE hResourceContext, unsigned char * piFTMErrorCode );

   /******************************************************************************/
   /**
   QLIB_FTM_QLNK_BER_TEST

   This command is to test BIT Error Rate (BER) of QLNK HW.
   The test might also run with extra board noise conditions.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iBERThreshold = BER Threshold

   \param iBERValue = BER Value

   \return true if successful, false if fail.

   *******************************************************************************/
   unsigned char QLIB_FTM_QLNK_BER_TEST( HANDLE hResourceContext, unsigned long iBERThreshold, unsigned long * iBERValue );

   /******************************************************************************/
   /**
   QLIB_FTM_QLNK_REG_RW

   This command is to test WTR/DTR register writes and reads on AXI bus.
   The test will issue a WTR/DTR register write request followed by a WTR register read request.
   The read-out value should be the same as the written value.
   And the ordering or packets in FIFO should be correct too (by checking QDSS logging).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param piFTMErrorCode =
   0 Success: TEST_SUCCESS
   1 Failure: CMD_TIME_OUT
   2 Failure: REG_RD_FAILURE
   3 Failure: REG_WR_FAILURE
   4 Failure: START_FAILURE
   5 Failure: STOP_FAILURE
   6 Failure: BER_SET_FAILURE

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_QLNK_REG_RW( HANDLE hResourceContext, unsigned char * piFTMErrorCode );

   /******************************************************************************/
   /**
   QLIB_FTM_QLNK_WTR_RW

   This command is to test WTR register (scripts possibly) writes and reads on AXI bus.
   If the type is write, the test will issue a WTR register write request followed by a WTR register read request.
   The read-out value should be the same as the written value.
   And the ordering or packets in FIFO should be correct too (by checking QDSS logging).
   If the type is read, the test will only issue a WTR register read request.

   This command is only used internally.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iReadWriteType = read write type

   \param iRegAddress = register address

   \param iRegValLen = number of words (word = 4 bytes)

   \param piRegValueWrite = value to be written

   \param piRegValueRead = read out value

   \param piRegValReadLen = number of words read

   \piFTMErrorCode =
   0 Success: TEST_SUCCESS
   1 Failure: CMD_TIME_OUT
   2 Failure: REG_RD_FAILURE
   3 Failure: REG_WR_FAILURE
   4 Failure: START_FAILURE
   5 Failure: STOP_FAILURE
   6 Failure: BER_SET_FAILURE

   \return true if successful, false if fail.

   *******************************************************************************/
   unsigned char QLIB_FTM_QLNK_WTR_RW(
      HANDLE hResourceContext,
      unsigned char iReadWriteType,
      unsigned long iRegAddress,
      unsigned long iRegValLen,
      unsigned long *piRegValueWrite,
      unsigned long *piRegValReadLen,
      unsigned long *piRegValueRead,
      unsigned char *piFTMErrorCode );

   /******************************************************************************/
   /**
   QLIB_FTM_QLNK_DO_WTR_SCRIPT

   This command is to write a batch script into WTR and read out the status.
   Each request will do only one CSR write/read packet transmission from QRCT side to the embedded side.
   In embedded side, all CSR write packets will be assembled and programmed to WTR via QLNK.
   Each CSR read packet will be programmed right away and response back to QRCT.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iReadWriteType = Read/Write type

   \param iRegAddress = WTR register address

   \param iRegValLen = number of words (word = 4 bytes)

   \param piRegValueWrite = value to be written

   \param iDelayInUs = delay in microsecond

   \param iNumWrites = number of writes

   \param iLastWrite = indicates last write operation

   \param piValueReadLen = number of words read

   \param piRegValueRead = read out value

   \param piFTMErrorCode =
   0 Success: TEST_SUCCESS
   1 Failure: CMD_TIME_OUT
   2 Failure: REG_RD_FAILURE
   3 Failure: REG_WR_FAILURE
   4 Failure: START_FAILURE
   5 Failure: STOP_FAILURE
   6 Failure: BER_SET_FAILURE

   \return true if successful, false if fail.

   *******************************************************************************/
   unsigned char QLIB_FTM_QLNK_DO_WTR_SCRIPT(
      HANDLE hResourceContext,
      unsigned char iReadWriteType,
      unsigned long iRegAddress,
      unsigned short iRegValLen,
      unsigned long *piRegValueWrite,
      unsigned short iDelayInUs,
      unsigned short iNumWrites,
      unsigned char iLastWrite,
      unsigned short *piValueReadLen,
      unsigned long *piRegValueRead,
      unsigned char *piFTMErrorCode);

   /******************************************************************************/
   /**
   Factory Test Mode LTE Commands 3.2.1.8 Config deconfig Rx Chain

   This command config LTE Rx diversity

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iChainMask Bit0  chain 0 (rfm_device_0)
                      Bit1  chain 1 (rfm_device_1)
                      Bit2  chain 2 (rfm_device_3)
           iEnable = 1 - enable
                     0 - disable

           iFTMErrorCode = 0  Success
                           1  Error

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_CONFIG_DECONFIG_RX_CHAIN( HANDLE hResourceContext, unsigned short iChainMask, unsigned char iEnable, unsigned char * iFTMErrorCode);

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.6 Set RF channel

   Factory Test Mode GSM Commands 3.6 Set channel

   Factory Test Mode 1x RF Commands 3.2.7 (CL93-V5419-1)Set channel

   Factory Test Mode RF Commands 3.3.1.6 (CL93-V4168-1) Set channel

   CDMA/WCDMA: This command tunes the RF synthesizers to the frequency defined by the channel parameter,
   which is based on the band class from the Set Mode command. Set Mode must be called first.

   GSM: This command tunes the RF synthesizers to the frequency defined by the ARFCN parameter,
   which is based on the band class from the Set Mode command. Set mode must be called first.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iChannel =
   \code
   CDMA: desired channel that is used
   PHONE_MODE_CDMA_800 : 1-799, 991-1023
   PHONE_MODE_CDMA_1900: 0 - 1199
   PHONE_MODE_CDMA_1800: 0 - 599
   PHONE_MODE_J_CDMA:    1-799, 801-1039, 1041-1199, 1201-1600

   WCDMA: desired channel that is used

   GSM: desired ARFCN that is used:
   PHONE_MODE_GSM_900 : 128 to 251 for GSM 850 MHz,
   PHONE_MODE_GSM_1900 : 0 to 124 and 975 to 1023 for GSM 900 MHz,
   PHONE_MODE_GSM_1800 : 512 to 885 for GSM 1800 MHz,
   PHONE_MODE_GSM_850 : 512 to 810 for GSM 1900 MHz
   \endcode
   \return true if successful, false if fail.

   \warning Set Mode must be called before this.  This function must be called before
   any Tx or Rx specific functions.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_CHAN( HANDLE hResourceContext, unsigned long iChannel);

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands

   This command is used to set multiple carrier channels(=2) in multi carrier operation

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iChannel0 = desired first channel

   \param iChannel1 = desired second channel

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_MULTI_CHAN( HANDLE hResourceContext, unsigned short iChannel0,
                                                   unsigned short iChannel1 );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands

   This command is used to set multiple carrier channels(>=2) in multi carrier operation

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iChannels = array of channels

   \param iChannels_size = size of the array

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_MULTI_CHAN_ENH( HANDLE hResourceContext, long* iChannels,
                                                       UINT iChannels_size );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands

   This command is used to set multiple carrier channels(>=2) in multi carrier operation for tuning on multiple RF devices

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iChannels = array of channels

   \param iChannels_size = size of the array

   \param iRFdevice = device to tune

   \param iMulti_chan_idx = multi chan index

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_MULTI_CHAN_MULTI_TUNE(  HANDLE hResourceContext, long* iChannels, UINT iChannels_size, UINT iRFdevice, UINT iMulti_chan_idx );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.2 Get ADC

   Factory Test Mode 1x RF Commands 3.2.3 (CL93-V5419-1) Get ADC

   Factory Test Mode RF Commands 3.3.1.2 (CL93-V4168-1)  Get ADC

   This command returns the value of the specified analog-to-digital converter (ADC) channels.

   \param  iADC_type  = the ADC channel to be read
   \param  iADC_value = ADC value of the desired channel

   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_ADC_VAL
   ( HANDLE hResourceContext, unsigned short iADC_type, unsigned short* piADC_value );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.3 Get RX AGC

   Factory Test Mode 1x RF Commands 3.2.4 (CL93-V5419-1) Get Rx AGC

   Factory Test Mode RF Commands 3.3.1.3 (CL93-V4168-1)  Get Rx AGC

   This command returns the 10-bit twos complement output of the RX AGC loop.

   NOTE:  This number is normally represented as a signed number.  In this
   case, the sign is on the 10th bit, so if a signed number is
   desired, the user of this function will have to perform the
   conversion to a 16-bit signed value.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRX_AGC = For CDMA/WCDMA mode, AGC return value is from -512 to 511

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_RX_AGC( HANDLE hResourceContext, unsigned short* piRX_AGC );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands

   This command returns the 10-bit twos complement output of the RX AGC loop.
   The output corresponds to carrier 1 in a dual carrier setup.

   NOTE:  This number is normally represented as a signed number.  In this
   case, the sign is on the 10th bit, so if a signed number is
   desired, the user of this function will have to perform the
   conversion to a 16-bit signed value.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  iRX_AGC = For CDMA/WCDMA mode, AGC return value is from -512 to 511

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_CAGC_DUAL_CARRIER_RX_AGC( HANDLE hResourceContext, short* piRX_AGC );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.4 Get synthesizer lock state

   Factory Test Mode 1x RF Commands 3.2.5 (CL93-V5419-1) Get synthesizer lock state

   Factory Test Mode RF Commands 3.3.1.4 (CL93-V4168-1)  Get synthesizer lock state

   This command returns the combined (ANDed) lock state of the RF synthesizers.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  bLockState = 0 = if one or more is out of lock
   1 = if the synthesizers are all in lock

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_SYNTH_STATE( HANDLE hResourceContext, unsigned char* pbLockState);

   /*******************************************************************************/
   /**
   Factory Test Mode Common API Commands 2.1.26 Rx Trigger

   This command waits for the measured Rx Power to reach a given Trigger Level

   \param hResourceContext= Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTriggerLevel= Rx Power in 1/16 dBm units for GSM
                                  in 1/10 dBm units for all other technologies
   \param iTimeOut = Timeout in micro sec. Maximum timeout is 5,000,000 (5 sec)
   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  Timeout/Not implemented
   *  2  Technology not Supported
   *  3  RSSI read failed


   /*******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RX_WAIT_DBM( HANDLE hResourceContext, short iTriggerLevel, unsigned long iTimeout,unsigned short* iFTM_Error_Code );

   /*******************************************************************************/
   /**
   Factory Test Mode Common API Commands 2.1.26 Rx Trigger

   This command waits for the measured Rx Power to reach a given Trigger Level

   \param hResourceContext= Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTechnology = Technology being loaded
   *  0 - CDMA
   *  1 - WCDMA
   *  2 - GSM
   *  3 - LTE
   *  4 - TDSCDMA
   \param iDevice = Device to read Rx
   \param iTriggerLevel= Rx Power in 1/16 dBm units for GSM
                                  in 1/10 dBm units for all other technologies
   \param iTriggerDirection = Trigger Direction - Gets triggered if the Signal is above or below the threshold and not on Rising edge/Falling Edge
                                                   0-Rising signal level
                                                   1-Falling signal level
   \param iTimeOut = Timeout in micro sec. Maximum timeout is 5,000,000 (5 sec)
   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  Timeout/Not implemented
   *  2  Technology not Supported
   *  3  RSSI read failed


   /*******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RX_WAIT_DBM_V2( HANDLE hResourceContext, unsigned short iTechnology, unsigned short iDevice, short iTriggerLevel, unsigned short iTriggerDirection, unsigned long iTimeout,unsigned short* iFTM_Error_Code );

   /*******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.5 Set uplink waveform to CW

   Factory Test Mode 1x RF Commands 3.2.6 (CL93-V5419-1) Set  CDMA wave CW

   Factory Test Mode RF Commands 3.3.1.5 (CL93-V4168-1)  Set  CDMA wave CW


   This command turns off the spreading on the uplink in WCDMA mode. The TX chain and all
   clocks are active, but there is no modulating signal applied to the carrier; therefore a CW is
   generated.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  bSelectCW = 0 - OFF/LO/FALSE deselect CW
   1 - ON/HI/TRUE select CW

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CDMA_CW_WAVEFORM( HANDLE hResourceContext, unsigned char bSelectCW);

   /******************************************************************************/
   /**
   !! Document Reference TBD


   This command sets an offset tone at the given frequency offset in WCDMA mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iOffsetFreq = The offset frequency at which to generate the tone in Hz.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_OFFSET_CW( HANDLE hResourceContext, int iOffsetFreq);


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.7 Set LNA offset

   Factory Test Mode 1x RF Commands 3.2.9 (CL93-V5419-1) Set LNA offset

   Factory Test Mode RF Commands 3.3.1.8 (CL93-V4168-1)  Set LNA offset

   This command sets the LNA offset for a given index value.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iLNAindex  = LNA offset index ID (0 is highest gain)

   The number of possible LNA offset varies with RF chipsets
   Please refer to applicable RF NV documents for the number of possible gain state

   \param iLNAoffset = LNA offset value in 1/12 dB resolution for the index ID

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_LNA_OFFSET
   ( HANDLE hResourceContext, unsigned short iLNAindex, unsigned short iLNAoffset);


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.10 Set PA range

   Factory Test Mode 1x RF Commands 3.2.12 (CL93-V5419-1) Set PA range

   Factory Test Mode RF Commands 3.3.1.11 (CL93-V4168-1)  Set PA range

   This command sets the PA range state machine to the specified state.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iPArange = the binary state of the PA range state:
   \code
   0 - R0 = 0, R1 = 0,
   1 - R0 = 1, R1 = 0,
   2 - R0 = 0, R1 = 1,
   3 - R0 = 1, R1 = 1
   \endcode
   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_PA_RANGE( HANDLE hResourceContext, unsigned short iPArange );


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.13 Get WCDMA IM2

   Factory Test Mode 1x RF Commands 3.2.15 (CL93-V5419-1) Get CDMA IM2

   Factory Test Mode RF Commands (cdma2000) 3.3.1.14 (CL93-V4168-1)  Get CDMA IM2

   FTM GSM RF Commands 3.8(CL93-V5370-1)  Get CDMA IM2

   This command returns the optimum IM2 value for the current mode and channel of the mobile.
   RX signal inputs are required to be set before issuing this command or the results will not be
   accurate.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iI_Value = The I value
   \param  iQ_Value = The Q value
   \param  iTransConductance_Value = The transconductance value.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_CDMA_IM2
   (
      HANDLE hResourceContext, unsigned char* piI_Value, unsigned char* piQ_Value,
      unsigned char* piTransConductance_Value
   );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.14 Set DVGA offset

   Factory Test Mode 1x RF Commands 3.2.16 (CL93-V5419-1) Set DVGA offset

   Factory Test Mode RF Commands 3.3.1.15 (CL93-V4168-1)  Set DVGA offset

   This function sets the DVGA offset register for WCDMA mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iDVGAoffset = offset value, in 1/120ths of dB

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_DVGA_OFFSET( HANDLE hResourceContext, unsigned short iDVGAoffset );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands (FTM document details)

   This function sets the carrier 1 DVGA offset register for dual carrier WCDMA mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iDVGAoffset = offset value, in 1/10th dB resolution

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_DUAL_CARRIER_DVGA_OFFSET( HANDLE hResourceContext, short iDVGAoffset );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.15 TX calibration sweep

   Factory Test Mode 1x RF Commands 3.2.18 (CL93-V5419-1) Tx Sweep Cal

   Factory Test Mode RF Commands 3.3.1.17 (CL93-V4168-1)  Tx Sweep Cal

   This command sets up one or more complete TX sweeps from high power to low power with
   a predefined TX adjust PDM step size. Figure 2 illustrates one TX sweep.
   The start power is determined by the last TX adjust PDM value set by the user before the
   sweep. To prevent users from setting the TX power too high, the start power is also limited by
   TX_SWEEP_CAL_MAX.

   NOTE By default, TX_SWEEP_CAL_MAX is 450, while TX_SWEEP_CAL_MIN is 100. The
   TX_SWEEP_CAL_ STEP is set to 10.

   The stop power is governed by TX_SWEEP_CAL_MIN. The current implementation has two full
   sweeps to ensure a spectrum analyzer will catch at least one full sweep with the video trigger
   option. It could be reduced to one sweep for an automated test.

   This command sets up one or more complete TX sweeps from high power to low power with
   a predefined TX adjust PDM step size.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  bOnOff = 0 - no effect, 1 - to trigger TX calibration sweep

   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TX_SWEEP_CAL( HANDLE hResourceContext, unsigned char bOnOff );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.16 Get DVGA offset

   Factory Test Mode 1x RF Commands 3.2.18 (CL93-V5419-1) Get DVGA offset

   Factory Test Mode RF Commands 3.3.1.17 (CL93-V4168-1)  Get DVGA offset


   For MSM6000/6025/6050 targets, iExpectedRX_AGC is ignored.

   For MSM6100 (DMSS version: ??), iExpectedRX_AGC is ignored.
   For   MSM6300 (DMSS version: ??), iExpectedRX_AGC is ignored.
   For   MSM6500 (DMSS version: ??), iExpectedRX_AGC is ignored.

   For MSM6550 (DMSS version: ??), iExpectedRX_AGC is used.
   For MSM6500 (DMSS version: ??), iExpectedRX_AGC is used.

   For MSM6200 targets, this command assumes the user is inputting a mobile RX signal at the
   level equivalent to the NV item WCDMA_LNA_RANGE_FALL_I (all external losses, including
   fixture must be accounted for). The return value is in 1/12 dB resolution.

   For MSM6250 phase II targets, this command takes DVGA gain offset as an input instead of
   reading RFNV WCDMA_LNA_RANGE_FALL_I value. The input value needs to be converted from
   dBm to an RX AGC value.

   This command calibrates and returns the DVGA offset for the current channel of operation.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iExpectedRX_AGC = power level in RX AGC units, at the input to the phone
   \param  iDVGAoffset = return value of the measured DVGA offset

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_DVGA_OFFSET( HANDLE hResourceContext, short iExpectedRX_AGC, short* piDVGAoffset );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands (FTM document details)

   This command calibrates and returns the WCDMA dual carrier DVGA offset for the current channels of operation.
   The offset returned corresponds to carrier 1 in a dual carrier setup.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iExpectedRX_AGC = power level in RX AGC units, at the input to the phone
   \param  iDVGAoffset = return value of the measured DVGA offset

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_DUAL_CARRIER_DVGA_OFFSET( HANDLE hResourceContext, short iExpectedRX_AGC, short* piDVGAoffset );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 3.2.1.17 Get LNA offset

   Factory Test Mode 1x RF Commands 3.2.20 (CL93-V5419-1) Get LNA offset

   Factory Test Mode RF Commands 3.3.1.19 (CL93-V4168-1)  Get LNA offset


   This command calculates and returns the LNA offset value for the input ID parameter. The
   function assumes the user has set up the RX signal into the mobile at an appropriate level. This
   function controls the AGC state for the purpose of calculating the LNA offset of interest. This
   function was designed to be called with the following sequence in mind:

   1. Set the power level into the mobile RX appropriate for id=1.
   2. Call the function Get LNA Offset with id=1.
   3. Set the power level into the mobile RX appropriate for id=2.
   4. Call the function Get LNA Offset with id=2.
   5. Set the power level into the mobile RX appropriate for id=3.
   6. Call the function Get LNA Offset with id=3.

   NOTE Since the DVGA dynamic range is limited, all indexes feed on the previous index being
   calculated (with the exception of id=1). If the above sequence is not followed, the returned
   values may be meaningless.

   This command calculates and returns the LNA offset value for the input ID parameter.

   For all MSM6000/6025/6050 targets, iExpectedRX_AGC is ignored.

   For MSM6100 (DMSS version: ??), iExpectedRX_AGC is ignored.
   For   MSM6300 (DMSS version: ??), iExpectedRX_AGC is ignored.
   For   MSM6500 (DMSS version: ??), iExpectedRX_AGC is ignored.

   For MSM6550 (DMSS version: ??), iExpectedRX_AGC is used.
   For MSM6500 (DMSS version: ??), iExpectedRX_AGC is used.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iLNAindex = LNA offset index, 1-3, zero is the highest gain state, but is not a
   valid option for this function.
   \param  iExpectedRX_AGC = power level in RX AGC units, at the input to the phone
   \param iLNAoffsetValue = measured value of the LNA offset, in 1/12dB resolution

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_LNA_OFFSET
   ( HANDLE hResourceContext, unsigned short iLNAindex , short iExpectedRX_AGC, short* piLNAoffsetValue );

   /******************************************************************************/
   /**
   This command calculates and returns the LNA offset value for the input ID parameter. The
   function assumes the user has set up the RX signal into the mobile at an appropriate level.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRFdevice = RF Device to calibrate
   \param  iCarr = Carr to measure
   \param iLNAoffsetValue = measured value of the LNA offset, in 1/12dB resolution

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_MULTI_TUNE_LNA_OFFSET
   ( HANDLE hResourceContext, UINT iRFdevice , UINT iCarr, short* piLNAoffsetValue );

   /******************************************************************************/
   /**
   \code
   Factory Test Mode WCDMA Commands 3.2.2 Get HDET from Tx Sweep Cal
   Factory Test Mode RF Commands 3.3.1.20 (CL93-V4168-1) Get HDET from Tx Sweep Cal
   \endcode

   While the TX is ON, data is collected after the complete execution of the TX Sweep CAL subcommand.
   Each entry is bound to a tx_agc_pdm value taken during TX Sweep CAL. If the user wishes to read
   HDET values unrelated to TX Sweep CAL, the FTM_GET_ADC_VAL API should be used.

   This command returns a value from the HDET TX Sweep Cal array.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iIndex = HDET array index, the 0 index corresponds to the first step
   of the TX Sweep.

   \param  iHDETvalue = value of the HDET at the iIndex position

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_HDET_FROM_TX_SWEEP_CAL
   ( HANDLE hResourceContext, unsigned short iIndex, unsigned short* piHDETvalue );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 4.19 Get HDET from Tx Sweep Cal

   Factory Test Mode 1x RF Commands 3.2.26 (CL93-V5419-1) Get ALL HDET from Tx Sweep Cal

   While the TX is ON, data is collected after the complete execution of the TX Sweep CAL subcommand.
   Each entry is bound to a tx_agc_pdm value taken during TX Sweep CAL. If the user wishes to read
   HDET values unrelated to TX Sweep CAL, the FTM_GET_ADC_VAL API should be used.

   This command returns a value from the HDET TX Sweep Cal array.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  piHDETvalues = Array of 32 (defined by QLIB_FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL_ARRAY_SIZE) bytes,
   to store the average HDET for the first 32 steps of the Tx Sweep

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL
   ( HANDLE hResourceContext, unsigned char * piHDETvalues );
   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 4.19 Get HDET from Tx Sweep Cal

   Factory Test Mode 1x RF Commands 3.2.26 (CL93-V5419-1) Get ALL HDET from Tx Sweep Cal

   While the TX is ON, data is collected after the complete execution of the TX Sweep CAL subcommand.
   Each entry is bound to a tx_agc_pdm value taken during TX Sweep CAL. If the user wishes to read
   HDET values unrelated to TX Sweep CAL, the FTM_GET_ADC_VAL API should be used.

   This command returns a value from the HDET TX Sweep Cal array.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  piHDETvalues = Array of 32 (defined by QLIB_FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL_ARRAY_SIZE) bytes,
   to store the average HDET for the first 32 steps of the Tx Sweep

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_GET_ALL_HDET_FROM_TX_SWEEP_CAL
   ( HANDLE hResourceContext, unsigned short* piHDETvalues );

   /******************************************************************************/
   /**
   \code
   Factory Test Mode WCDMA Commands 3.2.2 Get HDET from Tx Sweep Cal
   Factory Test Mode RF Commands 3.3.1.20 (CL93-V4168-1) Get HDET from Tx Sweep Cal
   \endcode

   While the TX is ON, data is collected after the complete execution of the TX Sweep CAL subcommand.
   Each entry is bound to a tx_agc_pdm value taken during TX Sweep CAL. If the user wishes to read
   HDET values unrelated to TX Sweep CAL, the FTM_GET_ADC_VAL API should be used.

   This command returns a value from the HDET TX Sweep Cal array.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iIndex = HDET array index, the 0 index corresponds to the first step
   of the TX Sweep.

   \param  iHDETvalue = value of the HDET at the iIndex position

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_LPM_HDET_FROM_TX_SWEEP_CAL
   ( HANDLE hResourceContext, unsigned short iIndex, unsigned short* piHDETvalue );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 4.19 Get HDET from Tx Sweep Cal

   Factory Test Mode 1x RF Commands 3.2.26 (CL93-V5419-1) Get ALL HDET from Tx Sweep Cal

   While the TX is ON, data is collected after the complete execution of the TX Sweep CAL subcommand.
   Each entry is bound to a tx_agc_pdm value taken during TX Sweep CAL. If the user wishes to read
   HDET values unrelated to TX Sweep CAL, the FTM_GET_ADC_VAL API should be used.

   This command returns a value from the HDET TX Sweep Cal array.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  piHDETvalues = Array of 32 (defined by QLIB_FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL_ARRAY_SIZE) bytes,
   to store the average HDET for the first 32 steps of the Tx Sweep

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_ALL_LPM_HDET_FROM_TX_SWEEP_CAL
   ( HANDLE hResourceContext, unsigned short * piHDETvalues );

   /******************************************************************************/
   /**
   This command enables the LPM HDET.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  ienableHdetLPM = Enable\Disable LPM HDET

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ENABLE_LPM_HDET( HANDLE hResourceContext, unsigned char ienableHdetLPM  );


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 4.19 Get HDET from Tx Sweep Cal (V2)

   Factory Test Mode 1x RF Commands 3.2.26 (CL93-V5419-1) Get ALL HDET from Tx Sweep Cal

   While the TX is ON, data is collected after the complete execution of the TX Sweep CAL subcommand.
   Each entry is bound to a tx_agc_pdm value taken during TX Sweep CAL. If the user wishes to read
   HDET values unrelated to TX Sweep CAL, the FTM_GET_ADC_VAL API should be used.

   This command returns a value from the HDET TX Sweep Cal array.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  piHDETvalues = Array of 32 (defined by QLIB_FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL_ARRAY_SIZE) word,
   to store the average HDET for the first 32 steps of the Tx Sweep

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_ALL_HDET_FROM_TX_SWEEP_CAL_V2
   ( HANDLE hResourceContext, unsigned short * piHDETvalues );


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands Switch Tx Antenna

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param tx_antenna The Tx Antenna to switch to 0 indicates Primary Tx Antenna and 1 indicates Diversityy Tx Antenna

   \return true if successful, false if fail.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SWITCH_TX_ANT
   (HANDLE hResourceContext, unsigned short tx_antenna);



   /******************************************************************************/
   /**
   Factory Test Mode 1x RF Commands 3.2.28 (CL93-V5419-1) Set RF Power Mode

   This command overrides the automatic IntelliCeiver Power mode decision.
   This setting will be lost when changing the channel with the FTM_SET_CHAN API,
   or when the phone is returned to Online mode.

   \param  iMode = Power mode to force the IntelliCeiver to:
   0 = High Power mode
   1 = Mid Power mode
   2 = Low Power mode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_RF_POWER_MODE( HANDLE hResourceContext, unsigned char iMode );


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands 4.20 Set HDET Tracking

   This command enables/disables the HDET tracking. When the HDET tracking is enabled, the
   software will periodically read the HDET value and adjust the uplink power to meet a desired
   level based on a given HDET value.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iOnOff =
   \code
   0 = disable HDET tracking
   1 = enable HDET tracking
   \endcode

   \param  iHDETvalue = desired HDET value for setpoint

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_HDET_TRACKING
   ( HANDLE hResourceContext, unsigned short iOnOff, unsigned short iHDETvalue );


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, 4.21 Configure Tx Calibration Sweep

   Factory Test Mode CDMA Commands, 3.4.17  Set Tx Cal Sweep

   This command sets the time interval of each step in the Tx calibration sweep
   and the number of HDET readings averaged per step.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  iTimeInterval = For CDMA radio, the unit is expressed in terms of ms
   The value of 20 correponds to 20ms

   For WCDMA radio, the unit is expressed in terms on 1/32.768 kHz
   The value of 655 corresponds to 20 ms

   1/32.768 kHz = 0.0305 ms per count.
   The minimum value is 66, which is about 2 ms. Any number less
   than 66 will be forced to 66.

   The time interval is how long the step is (in time).  We found that a 2ms
   step time is ideal and anything below that is not repeatable.  We also
   tested the CMU-200's and the FSP measurement capabilities for 2ms and
   found them to be acceptable.  For these reasons, we suggest a value of
   66 (2ms) to be used for the time interval.



   \param  iNumofHDETReadingsPerStep= Number of HDET reads for averaging (from 1 to 255)
   During the top 32 power steps, the HDET will be measured.
   During the measurement of the HDET, each value is averaged
   with other HDET readings at the same power level.   This
   setting controls how many HDET averages are taken during
   each power step.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CONFIGURE_TX_SWEEP_CAL
   ( HANDLE hResourceContext, unsigned short iTimeInterval, unsigned short iNumofHDETReadingsPerStep);



   /******************************************************************************/
   /**
   Factory Test Mode CDMA Commands, 2.4.32(CL93-V5419-1) FTM SET TX POWER DBM

   Factory Test Mode LTE Commands, 2.1.13(80-VR832-1) FTM SET TX POWER DBM

   Factory Test Mode WCDMA Commands, 2.x.xx (CL93-V5368-1) FTM SET TX POWER DBM

   FTM_SET_TX_POWER_DBM API programs the PA range, LUT Index and Digital Gain to reach the
   programmed Tx Powe level with power limiting enabled.
   The PA range will be selected depending upon the current TXAGC value and by using the PA RISE/FALL
   values in NV. If the requested power is within a PA Rise/Fall hysteresis range then the current
   power level will be used to determine whether the power is rising or falling.

   This API has the following runtime dependencies.
   *   QLIB_FTM_SET_MODE
   *   QLIB_FTM_SET_CHAN
   *   QLIB_FTM_SET_TX_ON

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iEnable =
   0 ==> Disable
   1 ==> Enable

   \param iPowerLevel = TXAGC power to be set.
   Power level in 1/10dBm units, as a signed number

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TX_POWER_DBM( HANDLE hResourceContext, unsigned char iEnable, short iPowerLevel, unsigned short* iFTM_Error_Code);


   /******************************************************************************/
   /**

   Factory Test Mode CDMA Commands, (CL93-V5419-1) FTM SET PA STATE

   Factory Test Mode LTE Commands, (80-VR832-1) FTM SET PA STATE

   Factory Test Mode WCDMA Commands, (CL93-V5368-1) FTM SET PA STATE

   This command programs the PA state. Note that the PA state is the low level hardware control indicator,
   which is different from the PA range software abstraction.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iPA_State = Indicates the PA State to be selected

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_PA_STATE( HANDLE hResourceContext, unsigned char iPA_State, unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
   Factory Test Mode RF Commands x.x.x.x (CL93-V4168-1) QLIB_FTM_SET_TX_WAVEFORM

   This command is used to generate an Tx waveform of given type with specified attributes.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iWaveformType = 0 - CDMA_WAVEFORM
   1 - CW_WAVEFORM

   \param  iWaveformAttrib = 0 - CW_OFFSET_ZER0_KHZ
   1 - CW_OFFSET_19_2_KHZ

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TX_WAVEFORM( HANDLE hResourceContext, unsigned char iWaveformType , unsigned char iWaveformAttrib );

   /******************************************************************************/
   /**

   Factory Test Mode CDMA Commands, (CL93-V5419-1) FTM RF GET RX LEVEL DBM

   Factory Test Mode LTE Commands, (80-VR832-1) FTM RF GET RX LEVEL DBM

   Factory Test Mode WCDMA Commands, (CL93-V5368-1) FTM RF GET RX LEVEL DBM

   This command returns the Rx level, for a specified receiver, in both AGC and dBm units.
   This command is only valid when the Rx verification state has been enabled for a specified receiver
   using FTM_RF_SET_RX_VERIFICATION_STATE.
   Accessing different receivers is handled by changes in the RF MODE ID field.

   This API has the following runtime dependencies.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iRX_AGC = RX AGC value (Valid only if  enable_rx_closed_loop is 1.)

   \param iRX_Power_dBm = Rx power in 1/10 dBm units; this is a signed number
   (Valid only if  enable_rx_closed_loop is 1.)

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_RX_LEVEL_DBM( HANDLE hResourceContext ,
                                                     short* iRX_AGC,
                                                     short* iRX_Power_dBm,
                                                     unsigned short* iFTM_Error_Code);


   /******************************************************************************/
   /**

   This command returns the Rx level for WCDMA Receiver in both RxAGC and dBm units after tune away to WCDMA in X2W scenario
   This command is only valid after tuning to WCDMA in X2W.

   This API has the following runtime dependencies.
   QMSL_Ext_FTM_MEAS_XTOY_TEST_Y_v2

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param dlChannel = downlink channel

   \param iRX_AGC = RX AGC value (Valid only if  enable_rx_closed_loop is 1.)

   \param iRX_Power_dBm = Rx power in 1/10 dBm units; this is a signed number
   (Valid only if  enable_rx_closed_loop is 1.)

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_GET_RX_LEVEL_DBM_X2W_MEAS( HANDLE hResourceContext,
                                                                    unsigned short dlChannel,
                                                                    unsigned short* iRX_AGC,
                                                                    unsigned short* iRX_Power_dBm);

   /******************************************************************************/
   /**

   Factory Test Mode CDMA Commands, (CL93-V5419-1) FTM RF GET RX LEVEL DBM

   Factory Test Mode LTE Commands, (80-VR832-1) FTM RF GET RX LEVEL DBM

   Factory Test Mode WCDMA Commands, (CL93-V5368-1) FTM RF GET RX LEVEL DBM

   This command returns the Rx level, for all the requested receiver chains associated
   with one carrier, in both Rx AGC and dBm units. This command is only valid after the
   mode (Technology/Band) is set using FTM_SET_MODE and FTM_SET_CALIBRATION_STATE has
   been used to deactivate calibration state or calibration state has not been activated
   while the device was powered up. Also, its required to enable all receiver chains and
   program them to correct LNA state before requesting RxAGC for a Rx chain (e.g. secondary
   chain should be enabled using FTM_SET_SECODNARY_CHAIN before using this command).

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iSelect_Rx_Chain = Selects the receiver chaing for which Rx level needs to be measured.
                             * Rx0 - 0x0001
                             * Rx1 - 0x0002

   \param iResultSize = Holds size of Results in bytes

   \param iPayload_Size = Number of bytes in the response packet that will hold the
                          resuls for Rx level measurement

   \param Results = Number of bytes in the results field is variable and is defined
                    by Payload Size. The results will follow the sequence of bits
                    enabled in select_rx_chain field starting with least significant
                    bit.

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   * 0  Success
   * 1  Failure occurred
   * 2  At least one requested Rx is not available/configured

   \return true if successful, false if fail.

   \warning 2013.10: this function is in development and is not documented or supported for
   use outside of Qualcomm.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_MULTIPLE_RX_LEVEL_DBM( HANDLE hResourceContext ,
                                                              unsigned short  iSelect_Rx_Chain,
                                                              unsigned short  iResultSize,
                                                              unsigned short* iPayload_Size,
                                                              unsigned short* iFTM_Error_Code,
                                                              void* Results);

   /******************************************************************************/
   /**

   Factory Test Mode CDMA Commands, (CL93-V5419-1) FTM SET FREQ ADJUST

   Factory Test Mode LTE Commands, (80-VR832-1) FTM SET FREQ ADJUST

   Factory Test Mode WCDMA Commands, (CL93-V5368-1) FTM SET FREQ ADJUST

   Adjust the frequency of the mobile Tx and Rx (Only Tx for WCDMA). This applies only to
   XO systems starting with the NikeL modem platform. The default frequency adjustment is zero.
   Each specified adjustment clears the previous adjustment value before setting the new value.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()
   \param User_Freq_Adjust_ppb = User defined frequency adjustment in ppb units

   \param Centre_Freq_Hz = Tx carrier frequency for current cellular band/channel, in Hzs units
   Center frequency is either Rx or Tx, depending on where the reference
   measurement was made on

   \param Enable_XO_Freq_Adjust =
   *   0 - Total Frequency Adjust = User defined frequency adjustment (i.e. user_freq_adjust_ppb)
   *   1  Total Frequency Adjust = User defined frequency adjustment (i.e. user_freq_adjust_ppb)
   + Frequency error reported by XO manager.

   \param Total_Freq_Adjust_Hz = Total Frequency Adjust applied in hz units. This value is only
   used in the response packet. It should be set to 0 in the request
   packet.

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_FREQ_ADJUST( HANDLE hResourceContext,
                                                    long User_Freq_Adjust_ppb,
                                                    unsigned long Centre_Freq_Hz,
                                                    char Enable_XO_Freq_Adjust,
                                                    long* Total_Freq_Adjust_Hz,
                                                    unsigned short* iFTM_Error_Code);
   /******************************************************************************/
   /**

   Factory Test Mode LTE Commands, (80-VR832-1) FTM SET FREQ ADJUST

   This command is specific to LTE TDD mode of operation. It serves:
   1) Sets the TDD Uplink-Downlink configurations as per 3GPP TS3.6.211 Table 4.2-2
   2) Specifies if the UE has to transmit on all subframes within a frame.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param Sub_Frame_Assign = Valid subframe assignment
   - TDD_UL_DL_CFG_0 = 0
   - TDD_UL_DL_CFG_1 = 1
   - TDD_UL_DL_CFG_2 = 2
   - TDD_UL_DL_CFG_3 = 3
   - TDD_UL_DL_CFG_4 = 4
   - TDD_UL_DL_CFG_5 = 5
   - TDD_UL_DL_CFG_6 = 6

   \param Enable_Continuous_Tx =
   1  UE will transmit Continuously
   0  UE will transmit according to SUB_FRAME_ASSIGN

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0x0     Success
   *   0x1     An un-supported value requested in the Sub_Frame_Assign field.
   *  0x2    - An un-supported value requested in the Enable_Continuous_Tx field.
   *  0x3    - An un-supported values requested in the Sub_Frame_Assign and Enable_Continuous_Tx fields.
   *  0xFFFF - Indicates that the LTE TDD band is not set prior to sending this command or UE is in
   calibration state.

   \return true if successful, false if fail.

   \warning 2012.09: This command is removed on products after MSM8960/MDM9615.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_SET_TDD_PARAMS(   HANDLE hResourceContext,
                                                         char Sub_Frame_Assign,
                                                         char Enable_Continuous_Tx,
                                                         unsigned short* iFTM_Error_Code);
   /******************************************************************************/
   /**

   Factory Test Mode WCDMA Commands, 4.24 Set Tx sweep step size

   This command sets the PDM step size used for the Tx calibration sweep. For each step of the
   sweep, the PDM will be reduced by the specified step size. If this command is not used, then the
   step size will default to 10.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iStepSize = PDM step size to use for the Tx calibration sweep

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TX_SWEEP_STEP_SIZE
   ( HANDLE hResourceContext, unsigned char iStepSize );

   /******************************************************************************/
   /**
   Factory Test Mode 1x RF Commands 3.1.3.14 (CL93-V5864-1)Select receiver antenna source

   This command selects the antenna source for the second receiver. This command is intended for
   radio testing and factory calibration of designs implementing Full-Time SHDR. The
   command allows the second receiver to be switched between the primary antenna and the
   secondary antenna, depending on the input parameter passed to the command. The RF driver
   must have been correctly configured for antenna selection via the RF card file, and the feature
   FEATURE_FULL_TIME_SHDR_3 must be defined.

   The implementation of this command has the side effect of reconnecting Rx0 to the primary
   antenna when the antenna select parameter is 1. This command was designed to support FTS-3
   phone designs, but given the preceeding side effect, it also behaves correctly on FTS-4 designs
   that do not have a true CDMA secondary antenna

   \param  iAntennaSel =   0  Connect Rx1 to primary antenna
   1  Connect Rx1 to secondary antenna

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SELECT_RX_ANTENNA(HANDLE hResourceContext, unsigned char iAntennaSel);

   /******************************************************************************/
   /**
   Factory Test Mode 1x RF Commands 3.2.23 (CL93-V5419-1)Get CtoN

   This command returns the carrier-to-noise ratio as calculated at the Rx front end of the Rx chain.
   The value returned is 10 * (C/N) dB. This value was chosen to provide the result with one
   decimal place of precision.

   see also: Factory Test Mode Get C-to-N, CL93-V6487-1

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iCtoN = Returns the C/N ratio value with one decimal place = 10 * (C/N) dB

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_CTON( HANDLE hResourceContext, long* iCtoN);

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, 4.27 Do DC calibration

   This command performs DC calibration. The Set mode and Set RF Channel commands should
   be called first. The results of the calibration will be written to NV directly.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_DC_CAL(   HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, FTM_DO_IQ_MISMATCH_CAL

   This command performs Rx IQ Mismatch calibration. The Set mode and Set RF Channel commands should
   be called first. The results of the calibration will be written to NV directly by the embedded side.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param ftm_error_code = ftm_error_code returned by embedded side

   \param   iAmpComp = Amplitude mismatch compensation

   \param  iPhaseComp = Phase mismatch compensation

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_IQ_MISMATCH_CAL( HANDLE hResourceContext, unsigned short* iFtm_error_code, unsigned short* iAmpComp, unsigned short* iPhaseComp );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, ICI calibration

   This command performs ICI calibration and collects INO data returned via FTM log.

   QLIB_FTM_SET_MODE, QLIB_FTM_SET_CHAN, QLIB_FTM_SET_SECONDARY_CHAIN and QLIB_FTM_SET_LNA_RANGE should be called first.

   Call QLIB_ConfigureTimeout( hResourceContext, QMSL_Timeout_ICI_IQ_Data, TimeOut) to configure the timeout value for getting IQ data
   from asynchronus FTM log

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param multi_carrier = conveys whether multicarrier mode is enabled

   \param carrier_id = the carrier for which IQ data has to be obtained (0 or 1)

   \param ftm_error_code = ftm_error_code returned by embedded side

   \param ino_array = buffer for storing IQ data. Length needs to be 25600 bytes.
   IQ data is returned as interleaved I and Q bytes ex. I0, Q0, I1, Q1, I2, Q2 ... 12800 pairs of IQ data

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_ICI_CAL_DATA( HANDLE hResourceContext, unsigned char multi_carrier,
                                                     unsigned char carrier_id, unsigned short *iFtm_error_code, char* ino_array );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands

   This command triggers IQ data collection on the phone and returns such data in an array

   QLIB_FTM_SET_MODE, QLIB_FTM_SET_CHAN, QLIB_FTM_SET_SECONDARY_CHAIN should be called first.

   Call QLIB_ConfigureTimeout( hResourceContext, QMSL_Timeout_ICI_IQ_Data, TimeOut) to configure the timeout value for getting IQ data
   from asynchronus FTM log

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param ftm_error_code = ftm_error_code returned by embedded side

   \param ino_array = buffer for storing IQ data. Length needs to be 25600 bytes.
   IQ data is returned as interleaved I and Q bytes ex. I0, Q0, I1, Q1, I2, Q2 ... 12800 pairs of IQ data

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_WCDMA_IQ_LOGGING( HANDLE hResourceContext, unsigned short carrier_mode,
                                                        unsigned short carrier_id, unsigned short* iFtm_error_code, char* ino_array );


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, x.x.x.xx(CL93-V5368-1) Config EUL Waveform

   FTM_CONFIG_EUL_WAVEFORM API computes and configures all the necessary MDSP
   and hardware registers for EUL waveform generation.  The request packet
   contains all the EUL waveform configuration information.
   It also enables the EUL Waveform
   Users can also use this API to achieve R99 and HSDPA waveforms with the following conditions:
   * For R99 - Set the iDeltaHS, iDeltaEc and iDeltaEd params to -1 (disable) and bHSDPCCHEnable = False
   * For HSDPA - Set the iDeltaEc, iDeltaEd to -1 (disable)

   This API has the following runtime dependencies.
   *   QLIB_FTM_SET_MODE
   *   QLIB_FTM_SET_CHAN
   *   QLIB_FTM_SET_TX_ON
   *   QLIB_FTM_WCDMA_CW_WAVEFORM
   *   QLIB_FTM_SET_PA_RANGE
   *   QLIB_FTM_SET_PDM (optional)

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()
   \param iBetaC = Gain factor for DPCCH.  Range: 0-15
   \param iBetaD = Gain factor for DPDCH.  Range: 0-15
   \param iDeltaHS = Gain factor for HS-DPCCH (ACK/NACK/CQI).  Range -1 & 0-8
   \param iDeltaEc = EUL delta Ec fain factor.  Range -1 & 0-8
   \param iDeltaEd = EUL delta Ed fain factor.  Range -1 & 0-29
   \param iBetaEDSF2val = Beta ED SF2 values depends on Delta ED value selected
   \param iMu = Mu factor.  Range 0,1,2,4,6
   \param bDPDCHEnable = DPDCH enable flag.   Range: 0 or 1.
   \param bHSDPCCHEnable = HS-DPCCH enable flag.   Range: 0 or 1.
   \param iModScheme = Modulation: 0 for QPSK, 1 for 16QAM (if supported)
   \param iMPR = output - MPR backoff in dBx2 ex: '3'=>1.5dB.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CONFIG_EUL_WAVEFORM( HANDLE hResourceContext,
                                                        unsigned char iBetaC, unsigned char iBetaD, char iDeltaHS,
                                                        char iDeltaEc, char iDeltaEd, char iBetaEDSF2val,
                                                        unsigned char iMu, unsigned char bDPDCHEnable,
                                                        unsigned char bHSDPCCHEnable, unsigned char iModScheme, unsigned char* iMPR );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, x.x.x.xx(CL93-V5368-1) Disable EUL Waveform

   FTM_DISABLE_EUL_WAVEFORM API reverts back to WCDMA R99 waveform and
   all the EUL related register settings are erased.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DISABLE_EUL_WAVEFORM( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, x.x.x.xx(CL93-V5368-1) WCDMA Set TxAGC

   FTM_WCDMA_SET_TXAGC API  programs the PA range, RF Gain and Digital Gain to reach the programmed TxAGC.
   User can override the PA range lookup in this API by setting the PA_Override input to TRUE and provide a custom PA range.


   This API has the following runtime dependencies.
   *   QLIB_FTM_SET_MODE
   *   QLIB_FTM_SET_CHAN
   *   QLIB_FTM_SET_TX_ON
   *   QLIB_FTM_WCDMA_CW_WAVEFORM or QLIB_FTM_EUL_CONFIG_WAVEFORM

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iTxAGC = TxAGC power to be set.  Range: 0 to 1023
   AGC resolution is target-dependent
   TxAGC(dB10) = (TxPower(dBm)+70)/10
   TxAGC(dB12) = (TxPower(dBm)+57)/12

   \param iPAOverride = TRUE  = Override PA range and use iPARange field always for PA range
   FALSE = Use iTxAGC and NV PA switchpoints to determine PA range

   \param iPARange = Sets PA range when iPAOverride is TRUE.  PA R0/R1 settings are determined through
   the NV PA Range Map.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_SET_TXAGC( HANDLE hResourceContext,
                                                    short iTxAGC, unsigned char iPAOverride, unsigned char iPARange );

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, x.x.x.xx(CL93-V5368-1) WCDMA Set TxAGC Sweep

   FTM_WCDMA_TXAGC_SWEEP API performs TxAGC sweep from start to stop TxAGC in step provided.
   User can override the PA range lookup in this API by setting the PA_Override input to TRUE and provide a custom PA range


   This API has the following runtime dependencies.
   *   QLIB_FTM_SET_MODE
   *   QLIB_FTM_SET_CHAN
   *   QLIB_FTM_SET_TX_ON
   *   QLIB_FTM_WCDMA_CW_WAVEFORM or QLIB_FTM_EUL_CONFIG_WAVEFORM

   Resolution of Start/Stop/Step AGC values are target-dependent:
   TxAGC(dB10) = (TxPower(dBm)+70)/10
   TxAGC(dB12) = (TxPower(dBm)+57)/12

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()
   \param iStart = Start TxAGC  Range: 0 to 1023
   \param iStop = Stop TxAGC  Range: 0 to 1023
   \param iStep = Steps in AGC counts (can be positive or negative)
   \param iDelay = Step width in milliseconds (20000 => 20 ms)
   \param iPAOverride = TRUE  = Override PA range and use iPARange field always for PA range
   FALSE = Use current tx agc value and NV PA switchpoints to determine PA range
   \param iPARange = Sets PA range when iPAOverride is TRUE.  PA R0/R1 settings are determined through
   the NV PA Range Map.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WCDMA_TXAGC_SWEEP( HANDLE hResourceContext,
                                                      short iStart, short iStop, short iStep,
                                                      short iDelay, unsigned char iPAOverride, unsigned char iPARange );


   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, x.x.x.xx FTM IRAT MEAS GTOW TEST WCDMA

   FTM_MEAS_GTOW_TEST_WCDMA API is used as G2W Setup mode where the phone(RTR) is faked to GSM mode (from WCDMA mode) and brought back
   to WCDMA mode so that we can make measurements in WCDMA mode for G TO W InterRAT case going from G to W mode.
   This is done purely in FTM mode where only the RTR settings are changed to provide this scenario.
   This is useful in FTM InterRAT measurements to verify the RF part (not involving upper layers).

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_MEAS_GTOW_TEST_WCDMA( HANDLE hResourceContext,
                                                         unsigned short gsmBand, unsigned short gsmChan,
                                                         unsigned short wcdmaBand, unsigned short wcdmaChan);

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, x.x.x.xx FTM IRAT MEAS GTOW TEST GSM

   FTM_MEAS_GTOW_TEST_GSM API is used as G2W Cleanup mode where the phone(RTR) is faked to WCDMA mode (from GSM mode) and brought back
   to GSM mode so that we can make measurements in GSM mode for G TO W InterRAT case going back to G from W mode.
   This is done purely in FTM mode where only the RTR settings are changed to provide this scenario.
   This is useful in FTM InterRAT measurements to verify the RF part (not involving upper layers).

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_MEAS_GTOW_TEST_GSM( HANDLE hResourceContext,
                                                       unsigned short gsmBand, unsigned short gsmChan,
                                                       unsigned short wcdmaBand, unsigned short wcdmaChan);

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, x.x.x.xx FTM IRAT MEAS WTOG TEST GSM

   FTM_MEAS_WTOG_TEST_GSM API is used as W2G Setup mode where the phone(RTR) is faked to WCDMA mode (from GSM mode) and brought back
   to GSM mode so that we can make measurements in GSM mode for G TO W InterRAT case going to G from W mode.
   This is done purely in FTM mode where only the RTR settings are changed to provide this scenario.
   This is useful in FTM InterRAT measurements to verify the RF part (not involving upper layers).

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_MEAS_WTOG_TEST_GSM( HANDLE hResourceContext,
                                                       unsigned short gsmBand, unsigned short gsmChan,
                                                       unsigned short wcdmaBand, unsigned short wcdmaChan);

   /******************************************************************************/
   /**
   Factory Test Mode WCDMA Commands, x.x.x.xx FTM IRAT MEAS WTOG TEST WCDMA

   FTM_MEAS_WTOG_TEST_WCDMA API is used as W2G Setup mode where the phone(RTR) is faked to GSM mode (from WCDMA mode) and brought back
   to WCDMA mode so that we can make measurements in WCDMA mode for G TO W InterRAT case going back to W from G mode.
   This is done purely in FTM mode where only the RTR settings are changed to provide this scenario.
   This is useful in FTM InterRAT measurements to verify the RF part (not involving upper layers).

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_MEAS_WTOG_TEST_WCDMA( HANDLE hResourceContext,
                                                         unsigned short gsmBand, unsigned short gsmChan,
                                                         unsigned short wcdmaBand, unsigned short wcdmaChan);

   /******************************************************************************/
   /**
   Factory Test Mode 1x RF Commands 3.2.25 (CL93-V5419-1)Get CDMA IM2 with suppression

   This command returns the suppression achieved as well as the I, Q, and transconductance (gM)
   optimum IM2 values for the current mode and channel of the mobile. It is intended to augment the original Get CDMA IM2.

   Rx signal inputs are required to be set before issuing this command or results will not be accurate.

   The suppression level is given in units of dB.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iI_Value = I value
   \param   iQ_Value = Q value
   \param   iTransConductance_Value = Transconductance Value
   \param   iSuppression = Suppression

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_CDMA_IM2_WITH_SUPPRESSSION(   HANDLE hResourceContext,
                                                                     unsigned char* iI_Value,
                                                                     unsigned char* iQ_Value,
                                                                     unsigned char* iTransConductance_Value,
                                                                     unsigned short* iSuppression);



   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, 3.3.1.16(CL93-V4168-1) Set frequency sense gain

   This command sets the frequency sense gain register to set the DFM modulation index..

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iModulationIndex =
   Range of data is from 0 to 63 (6 LSBits of input byte):
   0 = lowest
   63 = highest.

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_FREQ_SENSE_GAIN(   HANDLE hResourceContext,
                                                          unsigned char iModulationIndex );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, 3.3.1.21(CL93-V4168-1) Get FM IQ

   This command returns the A and B compensation values for the FM RF Mode. This command
   assumes that the user is adding a Rx CW on channel center at -75 dBm. This function will lock
   the trk-lo tune of the radio off one channel, calculate the A and B values, retune the radio back to
   the original channel, and return the A and B values as a packed double word.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iFmIQValue =
   Most significant 16 bits = B values
   Least significant 16 bits = A values.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_FM_IQ(   HANDLE hResourceContext,
                                                unsigned long* iFmIQValue );



   /******************************************************************************
   Dual RX Chain FTM RF Commands
   *******************************************************************************/
   /******************************************************************************/
   /**
   Dual Rx Chain FTM Command 3.3.10 (CL93-V5864-1) Set secondary chain

   This command sets the secondary chain in one of three modes, DISABLED, RECEIVE DIVERSITY and OFF FREQUENCY SEARCH

   \param  mode
   \code
   0 = Disabled - puts the secondary chain ZIFRIC and ZIFLNA in disabled mode via SBI
   1 = Receive Diversity - enables the secondary chain ZIFRIC and ZIFLN via SBI and switches the RX_VCO_SEL MUX
   to the primary chain PLL; this means that both the primary
   and secondary chain are set to the same band class and
   channel.

   2 = Off frequency search (OFS) = allows you to set the secondary chain to a band class and channel that is
   independent of the primary chain settings
   \endcode
   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_SECONDARY_CHAIN( HANDLE hResourceContext, unsigned short iMode );


   /**
   For UMTS/WCDMA:
   Refer to section 2.2.29 (CL93-V5368-1) FTM_SECOND_CHAIN_TEST_CALL

   This command forces the AMSS to use the second chain for all WCDMA Rx processing in FTM mode. This test mode is used for production testing of the second receive chain functionality.
   To use the second chain test call, place the phone in FTM mode. Issue the FTM_SECOND_CHAIN_TEST_CALL command, with the mode parameter set to 1. The
   phone will now only respond to FL signals on the secondary antenna. All Tx functions continue to use the primary antenna port.
   The phone returns to normal operation (primary only) after a reset, or a FTM_SECOND_CHAIN_TEST_CALL command issued with mode parameter 0.
   NOTE:   The mode ID for the secondary chain WCDMA RF commands is 21.

   For cdma2000:
   Dual Rx Chain FTM Command 3.3.12 (CL93-V5864-1) Set second chain test call mode
   See also: CL93-V6408-1, App Note : FTM, Set Up MSM for Call Process on Second Rx Chain

   This function forces the AMSS to use the second chain for all CDMA 1x RX processing in online
   mode. This test mode is intended for production testing of the second receive chain functionality.
   To use the second chain test mode, first place the phone in FTM mode. Then issue the Second
   Chain Test Call Mode command, with the mode parameter set to Enable. Issue a runtime switch
   back to online mode. The phone will now only respond to forward link signals on the second
   antenna. All transmit functions continue to use the primary antenna port. The phone will return to
   normal operation after a reset, or a Second Chain Test Call Mode command with the mode set to
   Disable.


   \param  Byte mode  = enables and disables the second chain test call mode:
   \code
   For cdma2000:

   0 = Disabled
   1 = Enabled

   For WCDMA/UMTS:

   0 = Primary chain only
   1 = Secondary chain only
   2 = Primary and secondary chain

   \endcode

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SECOND_CHAIN_TEST_CALL( HANDLE hResourceContext, unsigned char iMode );

   /******************************************************************************/
   /**
   [List documentation here when available]

   This command loads the digital pre-distortion (DPD) tables

   \param  [in]       eDevice = RFM Device type for primary Tx path on which the command is triggered (FTM_PriPathDevType_Enum)
   \param  [in]       eXPT_type = Specifies the type of xPT mode for which load DPD/IQ capture must be performed ( 0 = EPT, 1 = ET )
   \param  [in]       eAction_type = Specifies the type of load DPD action which must be performed
   \param  [in]       iNum_AMAM = Specifies the number of elements of piAMAM_array
   \param  [in]       iNum_AMPM = Specifies the number of elements of piAMPM_array
   \param  [in]       iNum_EPDT = Specifies the number of elements of piEPDT_array
   \param  {in]       piAMAM    = array containing the data for DPD override, must contain the number of elements provided in iNum_amam
   \param  [in]       piAMPM    = array containing the data for DPD override, must contain the number of elements provided in iNum_ampm
   \param  {in]       piEPDT    = array containing the data for DPD override, must contain the number of elements provided in INum_epdt

   \return true if successful, false if fail.

   \note [note whether this function can be used in QMSL FTM Sequencer operation]

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOAD_DPD_TBLS( HANDLE hResourceContext,
                                                  unsigned char eDevice,
                                                  unsigned char eXPT_type,
                                                  unsigned char eAction_type,
                                                  unsigned short iNum_AMAM,
                                                  unsigned short iNum_AMPM,
                                                  unsigned short iNum_EPDT,
                                                  unsigned short* piAMAM,
                                                  unsigned short* piAMPM,
                                                  unsigned short* piEPDT );

   /******************************************************************************/
   /**
   [List documentation here when available]

   This command triggers Enhanced Power Tracking (xPT) IQ Capture.

   \param  [in]     eDevice = RFM Device type for primary Tx path on which the command is triggered (FTM_PriPathDevType_Enum)
   \param  [in]     eDevice_fb = Feedback RFM device type for the feedback path (FTM_FBPathDevType_Enum)
   \param  [in]     eXPT_type = Specifies the type of xPT mode for which load DPD/IQ capture must be performed (FTM_xptType_Enum)
   \param  [in]     iNum_samples = Specifies the number of samples that must be captured for xPT IQ capture
   \param  [in]     bFirst_trig = Specifies if this is the First IQ capture trigger to FW, allows FW to initialize HW on their side
   \param  [in]     bLast_trig = Specifies if this is the Last IQ capture trigger to FW, allows FW to de-initialize HW on their side
   \param  [in]     bDo_processing = Specify to FW whether to process the IQ samples on their side
   \param  [in]     iNum_captures = Specifies the number of IQ captures that must be triggered internally in SW by this command
   \param  [in]     iDelay_us = Specifies the delay in microseconds between any set-up for IQ capture and triggering IQ capture
   \param  [in]     bDo_leakage_cal = Specifies whether to perfom IQ capture for leakage cal or normal xPT IQ capture
   \param  [in]     iDebug_state = specifies whether files are saved to root EFS. Could also enable any other specialized debug, possibly extra debug messages.
   0  debug disabled. No files saved
   1  debug enabled. Files saved
   \param  [in]     iIq_file_name_len = The number of characters including extension for IQ data file name.
   Set this param to zero to indicate that an IQ file should not be saved.
   \param  [in]     iDpd_file_name_len = The number of characters including extension for DPD data file name.
   Set this param to zero to indicate that an DPD file should not be saved.
   \param  [in]     pIq_file_name = Optional. specifies the IQ file name to be used when saving IQ capture to EFS
   \param  [in]     pDPD_file_name = Optional. specifies the DPD file name to be used when saving to EFS


   \return true if successful, false if fail.

   \note [note whether this function can be used in QMSL FTM Sequencer operation]

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TRIGGER_XPT_IQ_CAP( HANDLE hResourceContext,
                                                       unsigned char eDevice,
                                                       unsigned char eDevice_fb,
                                                       unsigned char eXPT_type,
                                                       unsigned short iNum_samples,
                                                       unsigned char bFirst_trig,
                                                       unsigned char bLast_trig,
                                                       unsigned char bDo_processing,
                                                       unsigned char bDo_leakage,
                                                       unsigned char iDebug_state,
                                                       unsigned char iIq_file_name_len,
                                                       unsigned char iDpd_file_name_len,
                                                       char* pIq_file_name,
                                                       char* pDpd_file_name );


   /******************************************************************************/
   /**
   FTM_GET_ET_PATH_DELAY - Triggers ET IQ Capture and does delay processing.

   \param  [in]      eDevice = RFM Device type for primary Tx path on which the command is triggered
   \param  [in]      eDevice_fb = Feedback RFM device type for the feedback path
   \param  [in]      iNum_samples = Specifies the number of samples that must be captured for xPT IQ capture
   \param  [in]      bFirst_trig = Specifies if this is the First IQ capture trigger to FW, allows FW to initialize HW on their side
   \param  [in]      bLast_trig = Specifies if this is the Last IQ capture trigger to FW, allows FW to de-initialize HW on their side
   \param  [in]      iNum_captures = Specifies the number of IQ captures that must be triggered internally in SW by this command
   \param  [in]      iDebug_state = specifies whether files are saved to root EFS. Could also enable any other specialized debug, possibly extra debug messages.
   0  debug disabled. No files saved
   1  debug enabled. Files saved
   \param  [in]     iIq_file_name_len = The number of characters including extension for IQ data file name.
   Set this param to zero to indicate that an IQ file should not be saved.
   \param  [in]     iDelay_file_name_len = The number of characters including extension for Delay processing result data file name.
   Set this param to zero to indicate that an Delay processing result data file should not be saved.
   \param  [in]     pIq_file_name = Optional. Specifies the IQ file name to be used when saving IQ capture to EFS
   \param  [in]     pDelay_file_name = Optional. Specifies the Delay processing result data file name to be used when saving to EFS

   \param [out]     iComputedDelay = Used to store the returned delay value.
   \returns true if successful, false if fail.

   \Note: The change in the function prototype is intentional. Since pass by reference is not supported by all compilers(C), this has been changed to pointer.
   *******************************************************************************/
   unsigned char QLIB_FTM_GET_ET_PATH_DELAY( HANDLE hResourceContext,
                                             unsigned char eDevice,
                                             unsigned char eDevice_fb,
                                             unsigned short iNum_samples,
                                             unsigned char bFirst_trig,
                                             unsigned char bLast_trig,
                                             unsigned char iDebug_state,
                                             unsigned char iIq_file_name_len,
                                             unsigned char iDelay_file_name_len,
                                             char* pIq_file_name,
                                             char* pDelay_file_name,
                                             unsigned long* piComputedDelay);

   /******************************************************************************/
   /**
   [List documentation here when available]

   This command sets xPT cal config.

   \param  [in]     eDevice = RFM Device type for primary Tx path on which the command is triggered (FTM_PriPathDevType_Enum)
   \param  [in]     eDevice_fb = Feedback RFM device type for the feedback path (FTM_FBPathDevType_Enum)
   \param  [in]     eXPT_type = Specifies the type of xPT mode for which load DPD/IQ capture must be performed (FTM_xptType_Enum)

   \return true if successful, false if fail.

   \note [note whether this function can be used in QMSL FTM Sequencer operation]

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_XPT_CAL_CONFIG( HANDLE hResourceContext,
                                                       unsigned char eDevice,
                                                       unsigned char eDevice_fb,
                                                       unsigned char eXPT_type);

   /******************************************************************************/
   /**
   QLIB_FTM_SET_PATH_SEL_OVERRIDE_INDEX

   \param  [in]      iCarrierId
   \param  [in]      iBand
   \param  [in]      iTxPathIdx
   \param  [in]      iRxPathIdx
   \param  [in]      iDRxPathIdx

   \returns true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_PATH_SEL_OVERRIDE_INDEX( HANDLE hResourceContext,
                                                                unsigned char iCarrierId,
                                                                unsigned char iBand,
                                                                unsigned char iTxPathIdx,
                                                                unsigned char iPRxPathIdx,
                                                                unsigned char iDRxPathIdx);

   /******************************************************************************/
   /**
   QLIB_FTM_SET_DEVICE_PATH

   \param  [in]      hResourceContext - Phone Handle
   \param  [in]      masterDevice
   \param  [in]      masterDevicePath
   \param  [in]      slaveDevice
   \param  [in]      slaveDevicePath
   \param  [out]     status

   \returns true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_DEVICE_PATH( HANDLE hResourceContext,
                                                    unsigned char masterDevice,
                                                    unsigned char masterDevicePath,
                                                    unsigned char slaveDevice,
                                                    unsigned char slaveDevicePath,
                                                    unsigned char* pstatus);

   /******************************************************************************/
   /**
   [List documentation here when available]

   This command sets Enhanced Power Tracking (EPT) state. EPT is the new name for SAPT.

   \param  [in]      eDevice = RFM Device type for primary Tx path on which the command is triggered (FTM_PriPathDevType_Enum)
   \param  [in]      bSAPT_on = Specifies if SAPT must be turned on or off

   \return true if successful, false if fail.

   \note [note whether this function can be used in QMSL FTM Sequencer operation]

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_SAPT_STATE( HANDLE hResourceContext,
                                                   unsigned char eDevice,
                                                   unsigned char bSAPT_on );

   /******************************************************************************/
   /**
   [List documentation here when available]

   FTM_XPT_TX_AGC_OVERRIDE - Configures TX AGC Override.


   \param  [in]      eDevice = RFM Device type for primary Tx path on which the command is triggered
   \param  [in]      eXPT_type = XPT Mode type to override
   \param  [in]      eIQ_Override_type = IQ Gain Override Type
   \param  [in]      iIQ_gain = IQ Gain to override
   \param  [in]      eEnvSc_Override_type = Envelope Scale Gain Override Type
   \param  [in]      iEnvScale = Envelope Scale to override
   \param  [in]      iRGI = RGI to override
   \param  [in]      iPA_bias = PA SMPS Bias to override
   \param  [in]      iPA_state = PA State to override
   \param  [in]      iPA_curr = PA Quiescent Current to override
   \param  [in]      eDelay_Override_type = Delay Val Override Type
   \param  [in]      iDelay_us = Delay Value is us to override
   \param  [out]     piStatus = Returned command status

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_XPT_TXAGC_OVERRIDE( HANDLE hResourceContext,
                                                       unsigned char eDevice,
                                                       signed char eXPT_type,
                                                       unsigned char eIQ_Override_type,
                                                       long iIQ_gain,
                                                       unsigned char eEnvSc_Override_type,
                                                       long iEnvScale,
                                                       unsigned short iRGI,
                                                       unsigned short iPA_bias,
                                                       unsigned char iPA_state,
                                                       unsigned short iPA_curr,
                                                       unsigned char eDelay_Override_type,
                                                       long  iDelay_us );

   /******************************************************************************/
   /**
   [List documentation here when available]

   Initial check-in - interface is not final; will be finalized later

   FTM_XPT_TX_AGC_OVERRIDE - Configures TX AGC Override.


   \param  [in]      eDevice = RFM Device type for primary Tx path on which the command is triggered
   \param  [in]      eXPT_type = XPT Mode type to override
   \param  [in]      eIQ_Override_type = IQ Gain Override Type
   \param  [in]      iIQ_gain = IQ Gain to override
   \param  [in]      eTxFeGain_Override_type = TxFE Gain Override Type
   \param  [in]      iTxFeGain = TxFE Gain to override
   \param  [in]      eEnvSc_Override_type = Envelope Scale Gain Override Type
   \param  [in]      iEnvScale = Envelope Scale to override
   \param  [in]      iRGI = RGI to override
   \param  [in]      iPA_bias = PA SMPS Bias to override
   \param  [in]      iPA_state = PA State to override
   \param  [in]      iPA_curr = PA Quiescent Current to override
   \param  [in]      eDelay_Override_type = Delay Val Override Type
   \param  [in]      iDelay_us = Delay Value is us to override
   \param  [out]     piStatus = Returned command status

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_XPT_TXAGC_OVERRIDE_V2( HANDLE hResourceContext,
                                                          unsigned char eDevice,
                                                          signed char eXPT_type,
                                                          unsigned char eIQ_Override_type,
                                                          long iIQ_gain,
                                                          unsigned char eTxFeGain_Override_type,
                                                          long iTxFeGain,
                                                          unsigned char eEnvSc_Override_type,
                                                          long iEnvScale,
                                                          unsigned short iRGI,
                                                          unsigned short iPA_bias,
                                                          unsigned char iPA_state,
                                                          unsigned short iPA_curr,
                                                          unsigned char eDelay_Override_type,
                                                          long  iDelay_us );

   /******************************************************************************/
   /**
   FTM_DO_RSB_TXLO_CAL

   This command is used to perform WTR Internal RSB and TXLO
   Calibration.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param rsbLoPayload   QMSL_FTM_RSB_TXLO_PKT_TYPE payload
   \param iResponse Response Code

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_RSB_TXLO_CAL( HANDLE hResourceContext, void* rsbLoPayload, unsigned char* iResponse );

   /******************************************************************************/
   /**

   QLIB_FTM_XPT_MLINE_COMPUTE - Computes the M (Magic) Line for XPT


   \param  [in]   eXpt_type = xpt type (EPT/ET)
   \param  [in]   iLin_region_pct_x100 = Linear region percentage (x100) used in M Line Calculation
   \param  [in]   iComp_pct_x10 = Compression Point db10 to be used in M Line Calculation
   \param  [in]   eCurve_fit_type = M Line Curve Fit Type
   \param  [in]   iXpt_cal_data_len = length  of xpt_mline_outputs_data array
   \param  [in]   iRgi_delta_data_len = length of peRgi_delta_data array
   \param  [in]   peXpt_cal_data = see enum xpt_cal_data
   \param  [in]   peRgi_delta_data = pointer to the start of array of enum ftm_common_rgi_delta_data
   \param  [in]   iDpd_file_name_len = The number of characters including extension for DPD data file name.
   \param  [in]   pDpd_file_name = Specifies the DPD file name to retrieve from EFS.
   iXpt_cal_data_len number of DPD files will be retrieved.
   '_#' will be appended to the end of the file name to retreive each.
   ex. if pDpd_file_name is "dpd.bin" then first retrieved file will be "dpd_1.bin and so on.
   \param  [out]  iRsp_len = length of peRsp_payload array
   \param  [out]  peRsp_payload = pointer to start of response array of enum xpt_mline_outputs_data

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_XPT_MLINE_COMPUTE( HANDLE hResourceContext,
                                                      unsigned char eXpt_type,
                                                      unsigned long iLin_region_pct_x100,
                                                      unsigned long iComp_pct_x10,
                                                      unsigned char eCurve_fit_type,
                                                      unsigned char iXpt_cal_data_len,
                                                      unsigned char iRgi_delta_data_len,
                                                      void* peXpt_cal_data,
                                                      void* peRgi_delta_data,
                                                      unsigned char iDpd_file_name_len,
                                                      char* pDpd_file_name,
                                                      unsigned short* iRsp_len,
                                                      void* peRsp_payload );


   /******************************************************************************/
   /**

   QLIB_XPT_Get_Qrct_DPD_File - Creates a QRCT formatted DPD file from dpd data obtained from the EFS DPD file and
   optionally the Detrough data from the input EPDT array.

   \param  [in]     pEfs_file_name = specifies the DPD file name to be retrieved from device EFS
   \param  [in]     pQrct_file_name = specifies the DPD file name to be used when creating the QRCT compatable DPD file
   \param  [in]     iNumEpdt = Specifies the number of elements of piEPDT_array. Set to zero if no detrough data is desired
   \param  {in]     piEPDT = array containing the detrough data, must contain the number of elements provided in INum_epdt.
   set to NULL if iNumEPDT = 0

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_XPT_Get_Qrct_DPD_File( HANDLE hResourceContext,
                                                          char* pEfs_file_name,
                                                          char* pQrct_file_name,
                                                          unsigned short iNumEpdt,
                                                          unsigned short* piEPDT );

   /******************************************************************************/
   /**
   [List documentation here when available]

   QLIB_XPT_Scale_Detrough_Table - Scales the detrough table.

   \param  [in]     iNumEpdt = Specifies the number of elements of piEPDT_array. Set to zero if no detrough data is desired
   \param  [in]     piUnityEPDT = array containing the unity detrough data, must contain the number of elements provided in INum_epdt.
   set to NULL if iNumEPDT = 0
   \param  [in]     iPA_bias = PA SMPS Bias(x1000) to override
   \param  [in]     iQPOET_VD_min = QPOET output voltage(x1000) at value 0 detrough entry. Used to calculate scaled detrough table
   \param  [in]     iQPOET_VD_max = QPOET output voltage(x1000) at value 2^152 detrough entry. Used to calculate scaled detrough table
   \param  [in]     iET_VD_min = Vdmin(x1000) for ET performance, could be adjusted based on PA lab characterization. Used to calculate scaled detrough table
   \param  [out]    piScaledEPDT = array containing the scaled detrough values. Must be allocated to contain the number of elements provided in INum_epdt.

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_XPT_Scale_Detrough_Table( unsigned short iNumEpdt,
                                                         unsigned short* piUnityEPDT,
                                                         double iPA_bias,
                                                         double iQPOET_VD_min,
                                                         double iQPOET_VD_max,
                                                         double iET_VD_min,
                                                         unsigned short* piScaledEPDT );

   /******************************************************************************/
   /**
   QLIB_rf_common_xpt_expand_dpd_data

   This function uses the same algorithm from AMSS side to expand EPT/ET's AMAM/AMPM/EPDT tables.  The exapanded data can then be
   re-assembled to form a DPD_File.txt for QRCT to send DPD table to device and to verify ET/EPT calibration.

   The user shall extract the AMAM/AMPM/EPDT tables from Multi-Lin V3 NV and call the function 2 or 3 (if EPDT expansion is required) times.

   \param  [in]     iDPD_tbl_type (AMAM, AMPM, EPDT). See QMSL_load_dpd_input_table_type in QLibDefines.h
   \param  [in]     num_dpd_coeffs. The num of element in dpd_coeffs table.  Typical value is 16
   \param  [in]     dpd_coeffs, AMAM, AMPM or EPDT table data
   \param  [in]     expansion factor 4 for AMAM or AMPM, 8 for EPDT
   \param  [in/out] dpt_tbl, the data array to hold expanded AMAM/AMPM/EPDT data.  The size of data array should be expansion_factor * num_dpd_coeffs

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_rf_common_xpt_expand_dpd_data
   (
      unsigned char iDPD_tbl_type,
      unsigned short num_dpd_coeffs,
      unsigned short* dpd_coeffs,
      unsigned short expansn_ratio,
      unsigned short* dpd_tbl

   );
   /*******************************************************************************/
   /**
   QLIB_FTM_SET_DCOC_VAL command is used to set DCOC VAL.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param [in]  reg value  as defined in unsigned int

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_DCOC_VAL(HANDLE hResourceContext, unsigned int reg_value);


   /*******************************************************************************/
   /**
   QLIB_FTM_WRITE_DCOC_VAL command is used to write DCOC Value in EFS.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param [in]  reg value  as defined in unsigned int

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WRITE_DCOC_VAL(HANDLE hResourceContext, unsigned int reg_value);
   /******************************************************************************/
   /**
   FTM_SET_TUNER_SCENARIO_OVERRIDE

   This command is used to set a scenario in the DUT. When this FTM command is exercised,
   the FTM command dispatch will queue a call to RF TASK as if it was a QMI sensor update.

   \param data   Contains the scenario to be set (valid range - Scenario 0-63)

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TUNER_SCENARIO_OVERRIDE(  HANDLE hResourceContext, unsigned char data);


   /******************************************************************************/
   /**

   FTM_SET_TUNER_TUNE_CODE_OVERRIDE

   This command is used to override the complete tune code (a combination of capacitors and switches in the antenna tuner hardware) for the antenna tuner of interest.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iOverride_Flag   Set 1 to override.  Set 0 to disable override
   \param iCommand_Version The pOverrideData and pNV_Data format version.  The current version format is 0.
   \param pOverrideData    Pointer to FTM_Set_Tuner_Override_V0 . See QLib_Defines.h
   \param iResultCode      Result Code
   \param pNV_Data         Pointer to FTM_Set_Tuner_NVData_V0 . The pNV_Data is updated by embedded side with the code word value.  See QLib_Defines.h
   \param tunerID          Pointer to TunerID, a two byte indicator for which tuner was programmed

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SET_TUNER_TUNE_CODE_OVERRIDE(  HANDLE hResourceContext,
                                                                  unsigned char iOverride_Flag,
                                                                  unsigned char iCommand_Version,
                                                                  void* pOverrideData,
                                                                  unsigned long* iResultCode,
                                                                  void* pNV_Data,
                                                                  unsigned short* tunerID );

   /******************************************************************************/
   /**

   FTM_TUNER_RL_CMD

   This command is used to set and get tuner detector measurements

   \param hResourceContext  Resource context that was returned from the call to QLIB_ConnectServer()
   \param command_type      Set 0 to trigger RL measurements, 1 to get RL measurements
   \param pRLcmdInputParams Pointer to ftm_tuner_rl_cmd_inputs. See QLib_Defines.h
   \param pRLcmdOutputs     Pointer to ftm_tuner_rl_cmd_outputs. See QLib_Defines.h

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TUNER_RL_CMD( HANDLE hResourceContext,
                                                 unsigned char command_type,
                                                 void* pRLcmdInputParams,
                                                 void* pRLcmdOutputs );

   /******************************************************************************/
   /**

   QLIB_FTM_GET_TUNER_STATUS

   This command will get status of programmed tuners.

   \param hResourceContext Resource context that was returned from the call to QLIB_ConnectServer()
   \param numTuners        Number of tuners, max of 5
   \param pTunerStatus     Pointer to ftm_program_tuner_info. See QLib_Defines.h
   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_TUNER_STATUS( HANDLE hResourceContext,
                                                            unsigned char* numTuners,
                                                            void* pTunerStatus );

   /******************************************************************************/
   /**

   QLIB_FTM_PROGRAM_TUNER

   This command will program up to 5 tuners.

   \param hResourceContext Resource context that was returned from the call to QLIB_ConnectServer()
   \param numTuners        Number of tuners, max of 5
   \param pTunerSettings   Pointer to ftm_program_tuner_info. See QLib_Defines.h
   \param pStatus          Pointer to array of ftm_program_tuner_info structures that will be filled 
                           with programming status for each tuner (1 = Programming done without errors,
                           0 = Error during programming)

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PROGRAM_TUNER( HANDLE hResourceContext,
                                                  unsigned char numTuners,
                                                  void* pTunerSettings,
                                                  void* pStatus );

   /******************************************************************************/
   /**
   FTM RF Antenna Tuner Commands ICD (80-P5227-2) SET TUNER PROPERTIES

   This command will program the tuners associated with the specified antenna port.
   
   \param hResourceContext Resource context that was returned from the call to QLIB_ConnectServer()
   \param version          Subcommand version
   \param antennaPort      The antenna port number for tuners to be programmed
   \param updateType       Tunecode update type (see ftm_rf_ant_tuner_tune_code_update_enum_type)
   \param tunecodeSize     Size of tunecode to be programmed, max size is 8 bytes
   \param pTunecodeBytes   Pointer to a byte array filled with the tunecode bytes
   \param scenario         Scenario to program when updateType = FTM_SET_TUNER_TRIGGER_SCENARIO_OVERRIDE

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_ANT_TUNER_SET_TUNER_PROPERTIES( HANDLE hResourceContext,
                                                                      unsigned short version,
                                                                      unsigned char antennaPort,
                                                                      unsigned char updateType,
                                                                      unsigned char tunecodeSize,
                                                                      unsigned char* pTunecodeBytes,
                                                                      unsigned char scenario );

   /******************************************************************************/
   /**
   FTM RF Antenna Tuner Commands ICD (80-P5227-2) GET TUNER STATUS

   This command will get the status of all tuners on all antenna ports.
   
   \param hResourceContext Resource context that was returned from the call to QLIB_ConnectServer()
   \param version          Subcommand version
   \param source           Tunecode source (0 = Tuner HW, 1 = SW Memory)
   \param numAntennas      As an input parameter, specifies the max length of pTunerStatus
                           As an output parameter, the number of antenna ports reported
   \param pTunerStatus     Pointer to an array of ftm_rf_ant_tuner_tuner_status_data_type structures
                           that will be filled with the status of all tuners per antenna port.
                           The array must have at least numAntennas elements.

   \return true if successful, false if fail.

   \warning This command will fail if the numAntennas input value is less than number 
            of antenna ports reported.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_ANT_TUNER_GET_TUNER_STATUS( HANDLE hResourceContext,
                                                                  unsigned short version, 
                                                                  unsigned char source, 
                                                                  unsigned char* numAntennas, 
                                                                  void* pTunerStatus );

   /******************************************************************************/
   /*****                        FTM RF IQ CAPTURE Commands                     **/
   /******************************************************************************/

   /**
   QLIB_FTM_IQ_CAPTURE_GET_CONFIG API returns key parameters for FTM IQ Capture, including
   maximum sample size, sample data format, sample frequency, maximum number of samples
   that can be returned in a diagnostic packet.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iRxPath  = Selects the Rx path

   \param iMaxSampleSize = Maximum number of samples that can be collected with the
   current Rx settings.

   \param iSampleDataFormat = Bit format to be used to interpret IQ samples.
   * 0 = 8-bits per I or Q sample
   * 1 = 16-bits per I or Q sample.

   \param iSamplingFrequency = Sampling frequency in Hz

   \param iMaxDiagSampleSize = Maximum number of IQ sample pairs that the FTM IQ capture
   software can use in a diagnostic response packet.
   This number is only based on the diagnostic buffer capacity of
   the embedded modem. There are other diagnostic handlers that
   need to be considered too, suah as the limitation of the
   application processor and the desktop software too.
   Formula for Max samples = (Embedded diag_max - respone header - 100 bytes
   for HDLC escape characters)/sizeof(sample_data_format)

   \param iFTM_Error_Code =   FTM Error code returned by FTM command
   *   0  Success
   *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_IQ_CAPTURE_GET_CONFIG(   HANDLE hResourceContext,
                                                            unsigned short  iRxPath,
                                                            unsigned short* iMaxSampleSize,
                                                            unsigned short* iSampleDataFormat,
                                                            unsigned long*  iSamplingFrequency,
                                                            unsigned long*  iMaxDiagSampleSize,
                                                            unsigned short* iFTM_Error_Code);

   /**
   QLIB_FTM_IQ_CAPTURE_ACQUIRE_SAMPLES API acquires one set of IQ samples. There is only one set of sample
   data held in memory for a particular technology, so any samples captured by a previous call to
   QLIB_FTM_IQ_CAPTURE_ACQUIRE_SAMPLES() will be erased from memory, if the samples were
   for the same technolgy.
   The samples collected in one acquisition will be contiguous. Samples from different acquisitions
   are not time coherent.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iRxPath  = Selects the Rx path

   \param iSampleSize = Number of samples to capture.

   \param iCarrierId = Selects a carrier, for receiver chains that can capture more than one carrier in
   the receiver bandwidth.
   * 0 = Carrier 0
   * 1 = Carrier 1

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_IQ_CAPTURE_ACQUIRE_SAMPLES(    HANDLE hResourceContext,
                                                                  unsigned short iRxPath,
                                                                  unsigned long iSampleSize,
                                                                  unsigned char iCarrierId,
                                                                  unsigned short* iFTM_Error_Code);

   /**
   QLIB_FTM_IQ_CAPTURE_GET_SAMPLES API returns a section of the acquired IQ samples from the last
   call to QLIB_FTM_IQ_CAPTURE_ACQUIRE_SAMPLES(). The section of samples is identified by the offset
   and count of the samples in the IQ sample buffer.
   The number of samples will be limited by the embedded diagnostic system.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iRxPath  = Selects the Rx path

   \param iSampleOffset = The offset of the first sample to return in the sample_buffer field.

   \param iSampleSize = Number of I and Q sample pairs to be returned in the sample_buffer field.
   This value cannot exceed the max_diag_sample_size field value returned
   from FTM_IQ_CAPTURE_GET_CONFIG().

   \param iSampleBufferSize = Holds size of isamplebuffer in bytes.

   \param iSampleBuffer = Returns the samples, as specified by the sample_offset and sample_size
   fields. The field size is based on the combination of the sample_data_format
   and sample_size.
   For Example: if sample_data_format = 1 (i.e. 16bits per sample) and
   sample_size = 100, then the resulting data size will be
   2 samples (I & Q) *2 bytes * 100 samples = 400 bytes.

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  General Failure occurred
   * 2 - IQ samples not available
   * 3 - Illegal combination of the sample_offset and sample_size fields.

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_IQ_CAPTURE_GET_SAMPLES(  HANDLE hResourceContext,
                                                            unsigned short iRxPath,
                                                            unsigned long iSampleOffset,
                                                            unsigned long iSampleSize,
                                                            unsigned short iSampleBufferSize,
                                                            unsigned short* iFTM_Error_Code,
                                                            void* iSampleBuffer);

   /**
   QLIB_FTM_IQ_CAPTURE_ACQUIRE_PRXDRX_SAMPLES API

   Command to capture Simultaneous IQ data using
   FTM_LTE_IQ_CAPTURE_ACQUIRE_PRX_DRX_SAMPLES_HANDLER(FTM_REQ_DATA) function.

   This function will send configuration parameters to FW and initialize the IQ capture.
   This API keeps backward compatibility and also enables legacy IQ capture functionality
   that permits only single path (PRx or DRx) IQ capture.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iRxChain = Selects the Rx chain for which Rx IQ capture and analysis must be done
                     * 0x0001 = Rx0
                     * 0x0002 = Rx1
                     * 0x0003 = Rx0/Rx1 (Simultaneous)

   \param iSampleSize = Number of samples to capture.

   \param iCarrierId = Selects a carrier, for receiver chains that can capture more than one carrier in
                        the receiver bandwidth.
                        * 0 = Carrier 0
                        * 1 = Carrier 1

   \param iFTM_Error_Code = FTM Error code returned by FTM command
                           * 0  Success
                           * 1  Failure occurred
                           * 2  Failed to acquire IQ samples
                           * 3  IQ samples not available
                           * 4  Error processing IQ samples

   \return true if successful, false if fail.

   \warning

   \note
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_IQ_CAPTURE_ACQUIRE_PRXDRX_SAMPLES(HANDLE hResourceContext,
                                                                     unsigned short iRxChain,
                                                                     unsigned long iSampleSize,
                                                                     unsigned char iCarrierId,
                                                                     unsigned short* iFTM_Error_Code);

   /**
   QLIB_FTM_IQ_CAPTURE_GET_PRXDRX_SAMPLES API

   This command is used to fetch the acquired samples.
   Currently we only support fetching either PRx or DRx samples
   depending on the parameter antenna_sel described below.

   The following API is executed when we issue the above mentioned command

   rsp_pkt = FTM_LTE_IQ_CAPTURE_GET_PRX_DRX_SAMPLES_HANDLER(FTM_REQ_DATA)


   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iSampleOffset = The offset of the first sample to return in the sample_buffer field.

   \param iSampleSize = Number of I and Q sample pairs to be returned in the sample_buffer field.
   This value cannot exceed the max_diag_sample_size field value returned
   from FTM_IQ_CAPTURE_GET_CONFIG().

   \param iSampleBufferSize = Holds size of isamplebuffer in bytes.

   \param iAntennaSel = Selects the Rx Chain for which IQ samples need to be fetched
                        * Rx0  0x0001
                        * Rx1  0x0002

   \param iSampleBuffer = Returns the samples, as specified by the sample_offset and sample_size
   fields. The field size is based on the combination of the sample_data_format
   and sample_size.
   For Example: if sample_data_format = 1 (i.e. 16bits per sample) and
   sample_size = 100, then the resulting data size will be
   2 samples (I & Q) *2 bytes * 100 samples = 400 bytes.

   \param iFTM_Error_Code = FTM Error code returned by FTM command
                           * 0  Success
                           * 1  General Failure occurred
                           * 2 - Failed to acquire IQ samples
                           * 3 - IQ samples not available
                           * 4 - Error processing IQ samples

   \return true if successful, false if fail.

   \warning

   \note
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_IQ_CAPTURE_GET_PRXDRX_SAMPLES( HANDLE hResourceContext,
                                                                  unsigned long iSampleOffset,
                                                                  unsigned long iSampleSize,
                                                                  unsigned short iSampleBufferSize,
                                                                  unsigned short* iFTM_Error_Code,
                                                                  unsigned char iAntennaSel,
                                                                  void* iSampleBuffer);

   /**
   QLIB_FTM_IQ_CAPTURE_ANALYZE_SAMPLES API is used to analyze the acquired IQ data. This
   function is designed to be expandable, so that new types of analysis can be added without
   requiring an entirely new command.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iRxPath  = Selects the Rx path

   \param iAnalysisID = * 0 = C/N and frequencey offset, based on CW input
   * 1 = Phase noise based on CW input.

   \param iRfPowerLevel_dBm10 = Value of expected power level in dBm*10

   \param iAnalysisResult = Holds response data.

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   *   0  Success
   *   1  General Failure occurred
   *  2 - IQ samples not available

   \param iEstimated_sensitivity_dBm100 = Calculates the estimated sensitivity based on the above C/N and scales the results in dB100 units.
   \param iPeak_frequency_Hz = The center frequency of the bin with the highest energy is returned as the peak_frequency (Hz).
   \param cton_dB100 = Calculates the C/N and scales the result in dB100 units

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_IQ_CAPTURE_ANALYZE_SAMPLES(  HANDLE hResourceContext,
                                                                unsigned short iRxPath,
                                                                unsigned int iAnalysisID,
                                                                unsigned char inumAvarages,
                                                                unsigned int sample_size,
                                                                int iRfPowerLevel_dBm10,
                                                                unsigned short* iFTM_Error_Code,
                                                                int* iEstimated_sensitivity_dBm100,
                                                                int* iPeak_frequency_Hz,
                                                                int* iCtoN_dB100);

   /**
   QLIB_FTM_GSM_CAPTURE_IQ API is used to configure the IQ capture mode to be used
   for subsequent IQ captures in GSM.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iGSMIQCaptureMode = * 0 = Single shot logging
   * 1 = Continuous logging
   * 2 = Stop IQ logging.

   \return true if successful, false if fail.

   \warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
   It will only be available in AMSS MSM8974 equivalents according to the
   Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GSM_CAPTURE_IQ(    HANDLE hResourceContext,
                                                      unsigned short iGSMIQCaptureMode);

   /**
   QLIB_FTM_TDSCDMA_SWITCH_TX_WAVEFORM API is used to select the TDSCDMA wavefrom type.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iWaveformType = 0 ? special burst waveform
                          1 ? DPD waveform

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TDSCDMA_SWITCH_TX_WAVEFORM( HANDLE hResourceContext,
                                                               unsigned char iWaveformType );

   /**
   QLIB_FTM_LTE_CONFIG_TX_RX API groups FTM_SET_MODE, FTM_LTE_SET_TX_BANDWIDTH, FTM_LTE_SET_RX_BANDWIDTH,
   FTM_SET_CHAN, FTM_LTE_SET_TX_WAVEFORM, FTM_LTE_SET_NET_SIG_VALUE and FTM_LTE_SET_TX_MODULATION_TYPE
   into one command.

   This command directs the mobile to enter the LTE mode of operation and sets the LTE RF operating band.

   It also configures the transmit or receive chain bandwidth and tunes the LTE RF synthesizers to the
   frequency specified by the channel parameter. The DL frequency is computed from the UL channel number,
   provided as an input parameter .

   It sets the Tx modulation type and Tx waveform to either a 1 MHz offset CW tone or an LTE signal.

   It configures the LTE NS value that will be used for the FTM_SET_TX_POWER_DBM command. This value is
   used to determine the Additional Max Power Backoff to reduce spectrum emissions.

   This command must be sent prior to any other LTE FTM command.

   This command can be used for both FDD and TDD bands.

   This command is only valid after FTM_SET_CALIBRATION_STATE has been used to deactivate calibration state
   or if the calibration state has not been activated while the device was powered up.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iVersion  = Number indicating the version number of the format for request/response packet.
                      This field is updated and incremented by 1, whenever the request/response packet
                      definition is modified.
                      Current version  1 = Initial version.

   \param iBand = Defines the enumeration for LTE Band. Please refer to "FTM_RF_Mode_Enum" enumeration
                  defination in "QLib_Defines.h" for more information.

   \param = iTxChanBandWidth = 0 - RFCOM_BW_LTE_1P4MHz
                               1 - RFCOM_BW_LTE_3MHz
                               2 - RFCOM_BW_LTE_5MHz
                               3 - RFCOM_BW_LTE_10MHz
                               4 - RFCOM_BW_LTE_15MHz
                               5 - RFCOM_BW_LTE_20MHz

   \param = iRxChanBandWidth = 0 - RFCOM_BW_LTE_1P4MHz
                               1 - RFCOM_BW_LTE_3MHz
                               2 - RFCOM_BW_LTE_5MHz
                               3 - RFCOM_BW_LTE_10MHz
                               4 - RFCOM_BW_LTE_15MHz
                               5 - RFCOM_BW_LTE_20MHz

   \param iChannel = Defines the LTE Tx Channel number

   \param iTxWaveform = 0-CW, 1- PUSCH, 2- PUCCH, 3 - PRACH, 4 - SRS, 5 - UpPTS

   \param iNumRBsPUSCH = Number of UL resource blocks to transmit on the PUSCH.

   \param iNumRBsPUCCH = Number of UL resource blocks to transmit on the PUCCH.

   \param iPUSCHStartRBIndex = Starting resource block index on the PUSCH.

   \param iCWOffset = CW offset in KHz's.

   \param iModulationType  = 0 - QPSK, 1 - 16 QAM, 2 - 64 QAM

   \param iNS = Configures the NS value, which affects maximium output power according to
                Section 6.6.2.2.1 Minimum requirement (network signalled value "NS_03") in [R1]

                The valid settings are 1-32.

   \param iFTM_Error_Code =   FTM Error code returned by FTM command
                             * 0  Success
                             * 1  General failure occurred
                             * 2  Set mode failed
                             * 3  Failed to enable TDD mode.
                             * 3  Tune to channel not successful
                             * 4  Set UL configuration failed

   \return true if successful, false if fail.

   \warning 2013.10: this function is in development and is not documented or supported for
   use outside of Qualcomm.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_CONFIG_TX_RX( HANDLE hResourceContext,
                                                     unsigned char   iVersion,
                                                     unsigned short  iBand,
                                                     unsigned char   iTxChanBandWidth,
                                                     unsigned char   iRxChanBandWidth,
                                                     unsigned short  iChannel,
                                                     unsigned char   iTxWaveform,
                                                     unsigned char   iNumRBsPUSCH,
                                                     unsigned char   iNumRBsPUCCH,
                                                     unsigned char   iPUSCHStartRBIndex,
                                                     short           iCWOffset,
                                                     unsigned char   iModulationType,
                                                     unsigned char   iNS,
                                                     unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /*****                         FTM RF FBRx  Commands                         **/
   /******************************************************************************/

   /**
   QLIB_FTM_RF_MEAS_TX_PARAMS API commands UE to start capturing Tx measurements
   using FBRx. It will also process the captured IQ samples and calculate various Tx
   parameters.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iNumAverages  = Captures multiple IQ captures. the result will be averaged over
   the number of IQ captures.

   \param iCaptureOffset = Delay in nano seconds (ns) after FBRx is configured and enabled
   and before capturing IQ samples.

   \param iTxMeasurementConfig = Selects the parameters to be measured for the current UL
   config and power level.
   0xFFFFFFFF - Enable all parameters
   0x1 - Enable Tx power measurement
   0x2 - Enable EVM measurement
   0x4 - Enable ACLR measurement
   0x8 - Save Tx IQ sample capture (saves only samples from last capture if iNumAverages > 1)
   0x10 - Save Rx IQ sample capture (saves only samples from last capture if iNumAverages > 1)

   \param iResultSize = Holds size of iResult in bytes.

   \param iPayloadsize = Number of bytes in the iResult field of the response packet.

   \param iResult = Number of bytes in iResult is variable and is defined by iPayloadSize.
   The results will follow the bit sequence in iTxMeasurementConfig field starting with the
   least significant bit. Results will be available for only those Tx parameters that are
   enabled in request packet.

   \param iFTM_Error_Code =   FTM Error code returned by FTM command
   *   0  Success
   *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2013.07: this function is in development and is not documented or supported for
   use outside of Qualcomm.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_MEAS_TX_PARAMS(   HANDLE hResourceContext,
                                                        unsigned short  iNumAverages,
                                                        unsigned long   iCaptureOffset,
                                                        unsigned long   iTxMeasurementConfig,
                                                        unsigned short  iResultSize,
                                                        unsigned short* iFTM_Error_Code,
                                                        unsigned short* iPayloadsize,
                                                        void*           iResult);

   /**
   QLIB_FTM_FBRX_IQ_CAPTURE_TRIGGER API command acquires one set of IQ samples
   -> The technology and receiver chain combination are selected by the RF_MODE_ID field.
   There is only one set of sample data held in the memory. So any samples captured by a
   previous call to QLIB_FTM_FBRX_IQ_CAPTURE_TRIGGER will be erased from the memory.

   This command also returns key parameters for IQ capture, including sample frequency used
   to capture Rx and Tx samples and maximum number of samples that can be returned in a
   diagnostic packet.

   The samples collected in one acquisition will be contiguous. Samples from different
   acquistions are not time coherent.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iSampleSize = Number of samples to capture in multiple of 1024 samples.
   0 - 1024 samples
   1 - 2048 samples
   2 - 3072 samples
   3 - 4096 samples
   4 - 5120 samples
   5 - 6144 samples
   6 - 7168 samples
   7 - 8192 samples
   8 - 9216 samples
   Note:- Max number of Tx and Rx samples that can be acquired in one capture is 9216.

   \param iFBRxChain = Specifies the path to be used as FBRx
   0 -FBRx0

   \param iSampleDataFormatTx = Bit format to be used to interpret Tx IQ samples.
   * 0 = 8-bits per I or Q sample

   \param iSampleDataFormatRx = Bit format to be used to interpret Rx IQ samples.
   * 1 = 16-bits per I or Q sample

   \param iSamplingFrequency = Sampling frequency in Hz used for Tx and Rx sample capture.

   \param iMaxDiagSampleSizeTx = Maximum number of Tx IQ sample pairs that the FTM IQ capture
   software can use in a diagnostic response packet.

   \param iMaxDiagSampleSizeRx = Maximum number of Rx IQ sample pairs that the FTM IQ capture
   software can use in a diagnostic response packet.

   \param iFTM_Error_Code =   FTM Error code returned by FTM command
   *   0  Success
   *   1  Failure occurred

   \return true if successful, false if fail.

   \warning 2013.07: this function is in development and is not documented or supported for
   use outside of Qualcomm.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FBRX_IQ_CAPTURE_TRIGGER( HANDLE hResourceContext,
                                                            unsigned char   iSampleSize,
                                                            unsigned char   iFBRxChain,
                                                            unsigned short* iFTM_Error_Code,
                                                            unsigned char*  iSampleDataFormatTx,
                                                            unsigned char*  iSampleDataFormatRx,
                                                            unsigned long*  iSamplingFrequency,
                                                            unsigned long*  iMaxDiagSampleSizeTx,
                                                            unsigned long*  iMaxDiagSampleSizeRx);

   /**
   QLIB_FTM_FBRX_IQ_CAPTURE_GET_SAMPLES API returns a section of the acquired IQ samples
   (Tx or Rx) from the last call to FTM_FBRX_IQ_CAPTURE_TRIGGER. The section of samples is
   identified by the offset and count of the samples in the IQ sample buffer.

   The number of samples will be limited by the embedded diagnostic system

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iSampleSource  = Indicates if the samples returned in iSampleBuffer are Tx or Rx samples.

   \param iSampleOffset = The offset of the first sample to return in the iSampleBuffer field.

   \param iSampleSize = Number of I and Q sample pairs to be returned in the sample_buffer field.
   This value cannot exceed the iMaxDiagSampleSizeTx  or iMaxDiagSampleSizeRx  field value returned
   from FTM_FBRX_IQ_CAPTURE_TRIGGER().

   \param iSampleBufferSize = Holds size of iSamplebuffer in bytes.

   \param iSampleBuffer = Returns the samples, as specified by the iSampleOffset and iSampleSize
   fields. The field size is based on the combination of the iSampleDataFormatTx or iSampleDataFormatRx
   and iSampleSize.
   For Example: if iSampleDataFormatTx = 0 (i.e. 8bits per sample) and
   sample_size = 100, then the resulting data size will be
   2 samples (I & Q) *1 bytes per sample * 100 samples = 200 bytes.

   if iSampleDataFormatRx = 1 (i.e. 16bits per sample) and
   sample_size = 100, then the resulting data size will be
   2 samples (I & Q) * 2 bytes per sample * 100 samples = 400 bytes.

   \param iFTM_Error_Code = FTM Error code returned by FTM command
   * 0  Success
   * 1  General Failure occurred
   * 2 - IQ samples not available
   * 3 - Illegal combination of the iSampleOffset and iSampleSize fields.

   \return true if successful, false if fail.

   \warning 2013.07: this function is in development and is not documented or supported for
   use outside of Qualcomm.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FBRX_IQ_CAPTURE_GET_SAMPLES(  HANDLE hResourceContext,
                                                                 unsigned char iSampleSource,
                                                                 unsigned long iSampleOffset,
                                                                 unsigned long iSampleSize,
                                                                 unsigned short iSampleBufferSize,
                                                                 unsigned short* iFTM_Error_Code,
                                                                 void* iSampleBuffer);
   /**
   QLIB_FTM_SET_TUNER_SCENARIO_OVERRIDE sets the scenario index so that the Tuner CL or AOL algorithms
   can be tested for RL and other metrics

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param scenarioIndex  = Indicates the scenario index which will be sent to the phone

   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TUNER_SCENARIO_OVERRIDE(  HANDLE hResourceContext, unsigned char scenarioIndex );

   /**
   QLIB_FTM_SET_TUNER_PROGRAM_SCENARIO programs the scenario index so that the Tuner CL or AOL algorithms
   can be tested for RL and other metrics

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \note This command MUST be preceded by QLIB_FTM_SET_TUNER_SCENARIO_OVERRIDE so that the phone is aware of what
   scenario needs to be programmed

   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TUNER_PROGRAM_SCENARIO( HANDLE hResourceContext);

   /**
   QLIB_FTM_DO_TUNER_SELF_CAL performs required internal device calibration for all the tuner devices on the current target.
   It performs the calibration, regardless of the state of the NV items

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iResultCode = 0  Success, 1  Failure

   \note This command MUST be preceded by FTM_SET_CALIBRATION_STATE (CAL_STATE_ACTIVE)

   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_TUNER_SELF_CAL( HANDLE hResourceContext, unsigned short* iResultCode);

   /**
   QLIB_FTM_ENH_INTERNAL_DEVICE_CAL performs required Feedback Rx internal device calibration .

   This command  sets the calibration state,sets RF mode,sets UL channel,does TX AGC override and then performs the Feedback
   RX Internal Device Cal.So it has no dependencies.


   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ENH_INTERNAL_DEVICE_CAL( HANDLE hResourceContext, void* enh_internal_device_cal, void*  enh_internal_device_resp);

   /**
   QLIB_FTM_SET_FBRX_PATH setsup the Feedback Rx path  .

   This function will call the tech specific APIs that setup Feedback Path.


   ******************************************************************************/


   QLIB_API unsigned char QLIB_FTM_SET_FBRX_PATH(HANDLE hResourceContext, void* enh_internal_device_cal);

   /**
   QLIB_FTM_DO_FBRX_RSB_CAL API performs FBRx RSB Cal.
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_FBRX_RSB_CAL( HANDLE hResourceContext, void* rsbLoPayload, unsigned char* iResponse );

   /**

   QLIB_FTM_RF_MEAS_FBRX_NOISE performs FBRx Noise Floor Cal
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_MEAS_FBRX_NOISE( HANDLE hResourceContext,
                                                       unsigned short iTechId,
                                                       unsigned char iRFModeId,
                                                       unsigned char iDeviceId,
                                                       unsigned char iNumAverages,
                                                       unsigned char iNumBwTypes,
                                                       unsigned short* iChanList,
                                                       unsigned char* iBwList,
                                                       unsigned short* iFTMErrorCode,
                                                       void *iResult);


   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1 section x.x, QLIB_FTM_FBRX_SINGLE_TRIGGER

   This command instructs the mobile to read FBRxGain, LS_Error and XCorr logs.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param FTM_COMMON_FBRX_SINGLE_TRIGGER_Request_Payload =  structure to hold input values of type " FTM_COMMON_FBRX_SINGLE_TRIGGER_Request_Payload "
                       as defined in QLIB_Defines.h
   \param FTM_COMMON_FBRX_SINGLE_TRIGGER_Response_Payload Payload =  structure to hold input values of type " FTM_COMMON_FBRX_SINGLE_TRIGGER_Response_Payload "
                       as defined in QLIB_Defines.h

   \return true if successful, false if fail.

   \warning


   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FBRX_SINGLE_TRIGGER (  HANDLE hResourceContext,
                                                          void * ftm_common_fbrx_single_triggerFTM_COMMON_FBRX_SINGLE_TRIGGER_Request_Payload, void * FTM_COMMON_FBRX_SINGLE_TRIGGER_Response_Payload);


   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1 section x.x, QLIB_FTM_FBRX_SINGLE_TRIGGER_V2

   This command instructs the mobile to read FBRxGain, LS_Error and XCorr logs.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param FTM_COMMON_FBRX_SINGLE_TRIGGER_Request_Payload_V2 =  structure to hold input values of type " FTM_COMMON_FBRX_SINGLE_TRIGGER_Request_Payload_V2 "
                       as defined in QLIB_Defines.h
   \param FTM_COMMON_FBRX_SINGLE_TRIGGER_Response_Payload_V2 =  structure to hold input values of type " FTM_COMMON_FBRX_SINGLE_TRIGGER_Response_Payload_V2 "
                       as defined in QLIB_Defines.h

   \return true if successful, false if fail.

   \warning


   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FBRX_SINGLE_TRIGGER_V2 (  HANDLE hResourceContext,
                                                             void * ftm_common_fbrx_single_triggerFTM_COMMON_FBRX_SINGLE_TRIGGER_Request_Payload_V2, void * FTM_COMMON_FBRX_SINGLE_TRIGGER_Response_Payload_V2);


   /******************************************************************************/
   /**
   QLIB_FTM_FBRX_DEBUG_GET_SAMPLE_CAPTURES

   This command requests the FBRx captures store in the mobile internal buffer.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param FTM_FBRX_DEBUG_GET_SAMPLE_CAPTURES_Response_Payload *fbrx_samples_captures_response =   structure to hold the values for the FBRx captures."

   \return true if successful, false if fail.

   \warning
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FBRX_DEBUG_GET_SAMPLE_CAPTURES (  HANDLE hResourceContext,
                                                                     void * fbrx_samples_captures_response);


   /******************************************************************************/
   /**
   QLIB_FTM_SELFTEST_SET_FBRX_GAIN_STATE

   This command set the FBRX Gain State during self test.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param unsigned char device = Tx device to use for transmitting.

   \param unsigned char fbrxGainState = FBRx gain state to use for self test.

   \return true if successful, false if fail.

   \warning
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SELFTEST_SET_FBRX_GAIN_STATE (  HANDLE hResourceContext,
                                                                   unsigned char device,
                                                                   unsigned char fbrxGainState);

   /******************************************************************************/
   /**
   QLIB_FTM_SET_DIVERSITY_MODE_ID finds and sets the diversity system mode ID taking the current mode ID as input.
   If the current mode ID is already a diversity mode ID, the command simply sets the current mode ID again.
   If the current mode ID is unknown or does not have a corresponding diversity mode ID, the command logs an error.

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param diversityModeID holds the diversity mode ID that was set

   \note This command is intended only to update the system mode to the diversity mode ID.
         No command is sent to the phone.

         ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_DIVERSITY_MODE_ID( HANDLE hResourceContext, unsigned short* diversityModeID );


   /******************************************************************************/
   /**
   QLIB_FTM_SET_MULTI_CARRIER_TX API is used to enable or disable multi carrier waveform

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param iEnable = Used to enable or disable multi carrier waveform. 1: Enable and 0: Disable
   \param iCarrierMask = Mask indicating number of carriers to be enabled. 1: Single Carrier, 2: Second Carrier, 3: Dual Carrier...

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_MULTI_CARRIER_TX( HANDLE hResourceContext,
                                                         unsigned short iEnable,
                                                         unsigned int iCarrierMask);

   /********************************************************************************/
   /**
   QLIB_FTM_COMMON_SET_ANTENNA API is used to place the antenna switch in a given position

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param  [in]      rfm_device = the device to which the switch command needs to be sent
   \param  [in]      switch_position = the position of the switch
   \param  [in]      immediate = whether or not the switch needs to be executed immediately

   \return true if successful, false if fail.

   \note This function can be used in QMSL FTM Sequencer operation

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_COMMON_SET_ANTENNA( HANDLE hResourceContext,
                                                       unsigned char rfm_device, unsigned char switch_position,
                                                       unsigned char immediate);

   /********************************************************************************/
   /**
   QLIB_FTM_COMMON_PRINT_MESSAGE API is used to print a message sent from the tool to F3s

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param  [message]      pointer to the buffer carrying the message that needs to be printed
                          maximum allowed message length is only 63 bytes.
                          message should be null terminated

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_COMMON_PRINT_MESSAGE( HANDLE hResoureContext, char* message);

   /********************************************************************************/
   /**
   QLIB_FTM_RAW_PACKET API is used to send a raw data packet

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param  [in]      pointer to the raw packet
   \param  [in]      length of the packet

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RAW_PACKET( HANDLE hResourceContext,
                                               char* raw_packet,
                                               unsigned char length);

   /********************************************************************************/
   /**
   QLIB_FTM_RFFE_GET_DEVICE_SETTING API is used to query the expected
   RFFE bus transactions based on device type.

   \param [in]    pDeviceSettingRequest = Request Packet (Please
                  refer to the ICD document for byte order)

   \param [out]   iNumDevices = Number of devices in use for the current band and channel Id.

   \param [out]   pDeviceTransactions = Response packet which stores RFFE
                  device control information including bus Id, slave Id, manufacturer Id, product Id,
                  revision Id, number of expected RFFE transaction, transaction addresses and data for all
                  the transactions.
                  (Please refer to the ICD document for complete response format)

   \param [out]   iResultCode = 0 - Success, 1 - Error

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RFFE_GET_DEVICE_SETTING( HANDLE hResourceContext,
                                                            void* pDeviceSettingRequest,
                                                            unsigned char* iNumDevices,
                                                            void* pDeviceTransactions,
                                                            unsigned short* iFTM_Error_Code
                                                          );

   /********************************************************************************/
   /**
   QLIB_FTM_RF_SET_SELFTEST_MODE API is used to enable self-test flag

   \param [in]    pDeviceSettingRequest = Request Packet (Please
                  refer to the ICD document for byte order)

   \param [in]   iEnableFlag =  0 - off, 1 - on.

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_SET_SELFTEST_MODE(  HANDLE hResourceContext,
                                                          unsigned char   iEnableFlag);

   /********************************************************************************/
   /**
   QLIB_FTM_DRDS_RECONFIG_ENABLE API is used to enable RF path reconfiguration for DRDS mode

   \param [in]   tech1 - technology 1 (the technology whose paths will be reconfigured)

   \param [in]   band1 - RF mode enumeration for band 1

   \param [in]   tech2 - technology 2

   \param [in]   band2 - RF mode enumeration for band 2

   \param [out]  iFTM_Error_Code - variable to hold error code

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DRDS_RECONFIG_ENABLE( HANDLE hResourceContext,
                                                         unsigned short tech1,
                                                         unsigned short band1,
                                                         unsigned short tech2,
                                                         unsigned short band2,
                                                         unsigned char* iFTM_Error_Code );

   /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_RADIO_CONFIGURE API is used to send a radio configure command
   to the phone using the FTM-RF-TEST subsystem

   Factory Test Mode Commands Document 80-VXYZ-A

   \param [in] subscriber = Subscriber type

   \param [in] technology = Air Interface Technology (LTE, WCDMA etc.)

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] responseData = Pointer to Array of Response Properties

   \param [out] error_code = Ftm error code

   \param [out] specific_err_code = error code specific to the subcommand Radio Configure

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_RADIO_CONFIGURE(  HANDLE hResourceContext,
                                                                 unsigned long subscriber,
                                                                 unsigned long technology,
                                                                 void* request_data,
                                                                 void* respsonse_data,
                                                                 unsigned long* error_code,
                                                                 unsigned long* specific_err_code );

   /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_TX_CONFIGURE API is used to send a tx control command
   to the phone using the FTM-RF-TEST subsystem

   Factory Test Mode Commands Document 80-VXYZ-A

   \param [in] subscriber = Subscriber type

   \param [in] technology = Air Interface Technology (LTE, WCDMA etc.)

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] responseData = Pointer to Array of Response Properties

   \param [out] error_code = Ftm error code

   \param [out] specific_err_code = error code specific to the subcommand TxControl

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_TX_CONTROL(  HANDLE hResourceContext,
                                                            unsigned long subscriber,
                                                            unsigned long technology,
                                                            void* request_data,
                                                            void* respsonse_data,
                                                            unsigned long* error_code,
                                                            unsigned long* specific_err_code );


   /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_RX_MEASURE API is used to get the Rx power measurements from the phone using the FTM-RF-TEST subsystem

   Factory Test Mode Commands Document 80-VXYZ-A

   \param [in] subscriber = Subscriber type

   \param [in] technology = Air Interface Technology (LTE, WCDMA etc.)

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] responseData = Pointer to Array of Response Properties

   \param [out] error_code = Ftm error code
   
   \param [out] specific_err_code = error code specific to the subcommand RxMeasure

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_RX_MEASURE(  HANDLE hResourceContext,
                                                            unsigned long subscriber,
                                                            unsigned long technology, 
                                                            void* request_data,
                                                            void* respsonse_data,
                                                            unsigned long* error_code,
                                                            unsigned long* specific_err_code );

   /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_RX_MEASURE_BLOB API is used to get the Rx power measurements from the phone using the FTM-RF-TEST subsystem  and access Blob data through delayed response.

   Factory Test Mode Commands Document 80-VXYZ-A

   \param [in] subscriber = Subscriber type

   \param [in] technology = Air Interface Technology (LTE, WCDMA etc.)

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] responseData = Pointer to Array of Response Properties

   \param [out] responseBlobData = Pointer to Array of Blob Data

   \param [out] error_code = Ftm error code
   
   \param [out] specific_err_code = error code specific to the subcommand RxMeasure

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_RX_MEASURE_BLOB(  HANDLE hResourceContext,
                                                                 unsigned long subscriber,
                                                                 unsigned long technology, 
                                                                 void* request_data,
                                                                 void* respsonse_data,
                                                                 void* response_blob_data,
                                                                 unsigned long* error_code,
                                                                 unsigned long* specific_err_code );


  /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_TX_MEASURE API is used to report TX measurements like Power, EVM, ACLR, etc. computed by the UE.

   Factory Test Mode Commands Document 80-VXYZ-A

   \param [in] subscriber = Subscriber type

   \param [in] technology = Air Interface Technology (LTE, WCDMA etc.)

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] responseData = Pointer to Array of Response Properties

   \param [out] error_code = Ftm error code
   
   \param [out] specific_err_code = error code specific to the subcommand TxMeasure

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_TX_MEASURE(  HANDLE hResourceContext,
                                                            unsigned long subscriber,
                                                            unsigned long technology,
                                                            void* request_data,
                                                            void* respsonse_data,
                                                            unsigned long* error_code,
                                                            unsigned long* specific_err_code );

   /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_TX_MEASURE_BLOB API is used to report TX measurements like Power, EVM, ACLR, etc. computed by the UE and access Blob data through delayed response.

   Factory Test Mode Commands Document 80-VXYZ-A

   \param [in] subscriber = Subscriber type

   \param [in] technology = Air Interface Technology (LTE, WCDMA etc.)

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] responseData = Pointer to Array of Response Properties

   \param [out] responseBlobData = Pointer to Array of Blob Data

   \param [out] error_code = Ftm error code
   
   \param [out] specific_err_code = error code specific to the subcommand TxMeasure

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_TX_MEASURE_BLOB(  HANDLE hResourceContext,
                                                                 unsigned long subscriber,
                                                                 unsigned long technology, 
                                                                 void* request_data,
                                                                 void* respsonse_data,
                                                                 void* response_blob_data,
                                                                 unsigned long* error_code,
                                                                 unsigned long* specific_err_code );

   /********************************************************************************/
   /**
   QLIB_FTM_ASSIGN_RADIO_ALLOCATION API is used to override the TRM with the RF Path setting during Non-signaling for all RF paths


   \param [in] technology = Air Interface Technology (LTE, WCDMA etc.)

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] responseData = Pointer to Array of Response Properties

   \param [out] error_code = Ftm error code

   \param [out] specific_err_code = error code specific to the subcommand Assign Radio Allocation

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ASSIGN_RADIO_ALLOCATION(  HANDLE hResourceContext,
                                                             unsigned long technology,
                                                             void* request_data,
                                                             void* respsonse_data,
                                                             unsigned long* error_code,
                                                             unsigned long* specific_err_code );

   /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_QUERY_RECOMMENDED_RADIO_ALLOCATION API is used to get the RF device and sig_path info from the phone using the FTM-RF-TEST subsystem

   Factory Test Mode Commands Document 80-VXYZ-A

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] responseData = Pointer to Array of Response Properties

   \param [out] error_code = Ftm error code

   \param [out] specific_err_code = error code specific to the subcommand Query RRA

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_QUERY_RECOMMENDED_RADIO_ALLOCATION(  HANDLE hResourceContext,
                                                                                    void* request_data,
                                                                                    void* respsonse_data,
                                                                                    unsigned long* error_code,
                                                                                    unsigned long* specific_err_code );

   /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_IQ_CAPTURE

   \param [in] numProperties  = Number of Properties

   \param [in] properties = Pointer to Array of Properties

   \param [out] error_code = RF Test Error Code

   \param [out] specific_err_code = IQ Capture specific error code

   \param [out] resp_num_captures = Number of captures in response

   \param [out] resp_captures = Pointer to Array of Captures

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_IQ_CAPTURE(  HANDLE hResourceContext,
                                                            unsigned long numProperties,
                                                            void* properties,
                                                            unsigned long* resp_num_captures,
                                                            void** resp_captures,
                                                            unsigned long* error_code,
                                                            unsigned long* specific_err_code );

   /********************************************************************************/
   /**
   QLIB_FTM_RF_TEST_CMD_MSIM_CONFIGURE API is used to send a MSIM config command
   to the phone using the FTM-RF-TEST subsystem

   Factory Test Mode Commands Document 80-VXYZ-A

   \param [in] requestData = Pointer to Array of Request Properties

   \param [out] error_code = Ftm error code

   \param [out] specific_err_code = error code specific to the subcommand MSIM config

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_TEST_CMD_MSIM_CONFIG(  HANDLE hResourceContext,
                                                             void* request_data,
                                                             unsigned long* error_code,
                                                             unsigned long* specific_err_code );

   /********************************************************************************/
   /**
   QLIB_FTM_SET_TRM_ANT_PORT_STATE API is used to set the port position for Port A/Port B testing

   \param switch_position = 0: Port A, 1: Port B

   \param trm_result = 0: Port switch acknoledged(ACK), 1: NV overridden(NACK), 2: QTA in progress(NACK), 3: Swap in progress(NACK)

   \param error_code = 0: No error, 1: Unhandled request, 2: Invalid input

   \return True if the command execution was successful, false if not successful.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_SET_TRM_ANT_PORT_STATE( HANDLE hResourceContext, unsigned char switch_position, unsigned char* trm_result, unsigned char *error_code);

   /********************************************************************************/
   /**
   QLIB_FTM_TUNER_GET_TUNE_CODE is used to retrieve from hardware the tune codes that are being used on
   all tuners on a given transmit or receive chain

   Factory Test Mode Commands Document 80-VXYZ-A

   This function configures the Tx slots. It needs to be called seven times to configure all seven 3 slots.

   \param [in] rf_mode = RF Mode of the tech and band that are being tested

   \param [in] device_type = The type of device that's being verified, i.e. Tx, Rx or RxTx

   \param [out] num_tuners = The number of tuners whose properties will be described

   \param [out] tune_codes = The tune code being used by each tuner on this chain

   \param [out] nvg_statuses = The NVG status of each tuner on this chain

   \param [out] tunerIDs = The device ID of each tuner on this chain

   \param [out] tuneCodeSizes = The tune code size of the tune code being used by each tuner on this chain

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TUNER_GET_TUNE_CODE( HANDLE hResourceContext,
                                                        unsigned char rf_mode, unsigned char device_type, unsigned char* num_tuners,
                                                        unsigned long long* tune_codes, unsigned char* nvg_statuses, unsigned char* tunerIDs,  unsigned char* tuneCodeSizes );

   /********************************************************************************/
   /**
   QLIB_FTM_RADIO_CONFIG_V1 is used to configure radio using sequence build/execute opcode.

   This internally uses QLIB_FTM_CFG_AND_EXEC_ESC_SWEEP API to send the sweep to the device.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param params_ptr = Pointer to radio setup params. Radio setup params structure is of type ftm_cal_seq_bld_radio_setup_params

   \return true if successful, false if fail.
   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RADIO_CONFIG_V1( HANDLE hResourceContext, void* params_ptr );

   /********************************************************************************/
   /**
   QLIB_FTM_RADIO_TEAR_DOWN_V1 is used to tear down radio using sequence build/execute opcode.

   This internally uses QLIB_FTM_CFG_AND_EXEC_ESC_SWEEP API to send the sweep to the device.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param params_ptr = Pointer to radio setup params. Radio setup params structure is of type ftm_cal_seq_bld_radio_setup_params

   \return true if successful, false if fail.
   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RADIO_TEAR_DOWN_V1( HANDLE hResourceContext, void* params_ptr );

   /********************************************************************************/
   /**
   QLIB_FTM_LTE_SET_DEVICES API is used to set LTE device allocation

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param   [in]     point to packet of set let devices request command

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_SET_DEVICES( HANDLE hResourceContext, void* pRequest);

   /********************************************************************************/
   /**
   QLIB_FTM_LTE_RF_CONFIG API is used to config LTE setup

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()

   \param [in]   point to packet of set rf config chain data

   \param [out]  pStatus

   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LTE_RF_CONFIG( HANDLE hResourceContext, void* pData, unsigned short* pStatus);

   /********************************************************************************/
   /**
   QLIB_FTM_SET_TRANSFER_SIZE API is used to set max transfer size for certain FTM command

   This command is applicable to certain FTM commands. This command itself does not send any FTM command, just sets an internal variable.
   The default value is 3800.
   This command is applicable to
      QLIB_FTM_CFG_AND_EXEC_ESC_SWEEP_COMPRESSED
     QLIB_FTM_CFG_AND_EXEC_ESC_SWEEP
     QLIB_FTM_CFG_AND_EXEC_QSC_SWEEP
     QLIB_FTM_CALL_RFNV_READ_V2
     QLIB_FTM_CALL_RFNV_WRITE_V2

   \param hResourceContext = Resource context that was returned from the call
   to QLIB_ConnectServer()


   \param [in]  iTransferSize = user specified max transfer size

   \param [in]  iSleepTime = sleep time right after sending and receiving FTM command

   \return true if successful, false otherwise

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TRANSFER_SIZE( HANDLE hResourceContext, unsigned short iTransferSize, unsigned short iSleepTime);


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_RF_H)
