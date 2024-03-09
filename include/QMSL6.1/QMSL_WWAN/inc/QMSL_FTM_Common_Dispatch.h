/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_Common_Dispatch.h#24 $
 * $DateTime: 2016/06/21 10:26:49 $
 *
 * DESCRIPTION: QMSL_FTM_Common_Dispatch
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QLIB_FTM_COMMON_DISPATCH_H)
#define _QLIB_FTM_COMMON_DISPATCH_H

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

#pragma once
   /******************************************************************************
                  Common RF FTM
   *******************************************************************************/
   /******************************************************************************/
   /**
   Factory Test Mode Common Commands GET Rx AGC Resolution

   Returns AGC to power constants for Rx

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  pdMinPower = RF Min Power
   \param  pdAGCRange = AGC Range
   \param  pdRFDynamicRange = RF Dynamic Range

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_AGC_RESOLUTION_RX
   ( HANDLE hResourceContext, double * pdMinPower, double * pdAGCRange, double * pdRFDynamicRange );

   /******************************************************************************/
   /**
   Factory Test Mode Common Commands GET Tx AGC Resolution

   Returns AGC to power constants for Tx

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param  pdMinPower = RF Min Power
   \param  pdAGCRange = AGC Range
   \param  pdRFDynamicRange = RF Dynamic Range

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_AGC_RESOLUTION_TX
   ( HANDLE hResourceContext, double * pdMinPower, double * pdAGCRange, double * pdRFDynamicRange );


   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1 section 2.1, FTM_TX_RX_FREQ_CAL_SWEEP

   This command instructs the mobile to perform the CDMA TX RX Frequency measurement
   described by 80-V5532-2.  It will setup the appropriate mobile logging so that the
   resulting log message will be captured.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pFTM_Tx_Rx_Freq_Cal_Sweep_Request_Response = structure to hold input and output values,
          of type "FTM_Tx_Rx_Freq_Cal_Sweep_Request_Response," as defined in QLIB_Defines.h

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_TX_RX_FREQ_CAL_SWEEP(
      HANDLE hResourceContext, void* pFTM_Tx_Rx_Freq_Cal_Sweep_Request_Response);

   /******************************************************************************/
   /**

   QLIB_FTM_CFG_AND_EXEC_CAL_SWEEP  - Start and execute the cal sweep.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_req = structure to hold input values of type "FTM_Cal_Sweep_Request"
                      as defined in QLIB_Defines.h
   \param num_seg = Number of segments in the list for the cal sweep
   \param  is_last_Sweep = Indicates whether this is the last sweep request
   \param  enableDbgMsgs = Indicates whether to enable debug messages or not

   \return  true if successful, false if fail.
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CFG_AND_EXEC_CAL_SWEEP( HANDLE hResourceContext, void* sweep_req, unsigned long num_seg, bool is_Last_Sweep, bool enableDbgMsgs );

   /******************************************************************************/
   /**

   QLIB_FTM_GET_CAL_SWEEP_RESULTS  - Fetch the cal sweep results. (DEPRECATED. Look for V2 below)

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_resp = structure to hold result values of type "FTM_Cal_Sweep_Response"
                      as defined in QLIB_Defines.h
   \param  sweep_req = structure that holds request params of the cal sweep sent to the UE as defined
                      in QLIB_Defines.h
   \param num_seg = Number of segments in the list for the cal sweep

   \return  true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_CAL_SWEEP_RESULTS( HANDLE hResourceContext, void * sweep_resp, void * sweep_req, unsigned long num_seg );

   /******************************************************************************/
   /**

   QLIB_FTM_GET_CAL_SWEEP_RESULTS_V2  - Fetch the cal sweep results V2.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_resp = structure to hold result values of type "FTM_Cal_Sweep_Response"
                      as defined in QLIB_Defines.h
   \param  sweep_req = structure that holds request params of the cal sweep sent to the UE as defined
                      in QLIB_Defines.h
   \param num_seg = Number of segments in the list for the cal sweep
   \param err_code_1 = First 32 bits of error code returned by Cal V3 sweep
   \param err_code_2 = Last 32 bits of error code returned by Cal V3 sweep

   \return  true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_CAL_SWEEP_RESULTS_V2( HANDLE hResourceContext, void * sweep_resp, void * sweep_req, unsigned long num_seg, unsigned int * err_code_1, unsigned int * err_code_2 );

   /******************************************************************************/
   /**

   QLIB_FTM_GENERATE_OPCODE  - Generates Opcodes for each segment of the cal sweep list based on the
                              actions to be performed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_req = structure to hold input values of type "FTM_Cal_Sweep_Request"
                      as defined in QLIB_Defines.h
   \param rfmode_seg = Bool to check if its a RF Mode Cfg Segment
   \param tuning_seg = Bool to check if its a Retune Segment
   \param rx_cfg_seg = Bool to check if its a Rx Cfg Segment
   \param rx_meas_seg = Bool to check if its a Rx Meas Segment

   \return  true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GENERATE_OPCODE( HANDLE hResourceContext, void* sweep_req, bool rfmode_seg, bool tuning_seg, bool rx_cfg_seg, bool rx_meas_seg );

   /**

   QLIB_FTM_GENERATE_SUB_OPCODE  - Generates Sub Opcodes for each segment of the cal sweep list based on the
                              actions to be performed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_req = structure to hold input values of type "FTM_Cal_Sweep_Request"
                      as defined in QLIB_Defines.h
   \param rfmode_seg = Bool to check if its a RF Mode Cfg Segment
   \param tuning_seg = Bool to check if its a Retune Segment
   \param rx_cfg_seg = Bool to check if its a Rx Cfg Segment
   \param rx_meas_seg = Bool to check if its a Rx Meas Segment

   \return  true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GENERATE_SUB_OPCODE( HANDLE hResourceContext, void* sweep_req, bool rfmode_seg, bool tuning_seg, bool rx_cfg_seg, bool rx_meas_seg );

   /**

   QLIB_FTM_DO_TX_INTERNAL_CAL  - Perform Tx Internal Device Cal.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  tech = Technology for Tx Internal Cal
   \param band = Band for Tx Internal Cal
   \param device = Device for Tx Internal Cal

   \return  true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_TX_INTERNAL_CAL( HANDLE hResourceContext, unsigned long tech, unsigned long band, unsigned long device );

   /******************************************************************************/
   /**

   QLIB_FTM_CFG_AND_EXEC_ESC_SWEEP  - Start and execute ESC cal sweep.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_rec = structure to hold input values of type "cal_sweep_record"
                      as defined in QLIB_Defines.h
   \param num_seg = Number of segments in the list for the cal swee
   \param  is_last_Sweep = Indicates whether this is the last sweep request
   \param  enableDbgMsgs = Indicates whether to enable debug messages or not

   \return  true if successful, false if fail.
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CFG_AND_EXEC_ESC_SWEEP( HANDLE hResourceContext,
                                                           void* sweep_rec,
                                                           unsigned long num_seg,
                                                           bool is_Last_Sweep,
                                                           bool enableDbgMsgs );

   /******************************************************************************/
   /**

   QLIB_FTM_CFG_AND_EXEC_ESC_SWEEP_COMPRESSED  - Start and execute
   ESC cal sweep. The FTM command will be sent with compression

   \param hResourceContext = Resource context that was returned
          from  the call to QLIB_ConnectServer()
   \param  sweep_rec = structure to hold input values of type
                      "cal_sweep_record" as defined in
                      QLIB_Defines.h
   \param num_seg = Number of segments in the list for the cal swee
   \param  is_last_Sweep = Indicates whether this is the last sweep request
   \param  enableDbgMsgs = Indicates whether to enable debug messages or not

   \return  true if successful, false if fail.
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CFG_AND_EXEC_ESC_SWEEP_COMPRESSED( HANDLE hResourceContext,
                                                                      void* sweep_rec,
                                                                      unsigned long num_seg,
                                                                      bool is_Last_Sweep,
                                                                      bool enableDbgMsgs );

   /******************************************************************************/
   /**

   QLIB_FTM_CFG_AND_EXEC_QSC_SWEEP  - Start and execute QSC cal sweep.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_rec = structure to hold input values of type "cal_sweep_record"
                      as defined in QLIB_Defines.h
   \param num_seg = Number of segments in the list for the cal swee
   \param  is_last_Sweep = Indicates whether this is the last sweep request
   \param  enableDbgMsgs = Indicates whether to enable debug messages or not
   \param  enableCompression = Indicates whether to compress the request packet or not

   \return  true if successful, false if fail.
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CFG_AND_EXEC_QSC_SWEEP( HANDLE hResourceContext,
                                                           void* sweep_rec,
                                                           unsigned long num_seg,
                                                           bool is_Last_Sweep,
                                                           bool enableDbgMsgs,
                                                           bool enableCompression);

   /******************************************************************************/
   /**

   QLIB_FTM_GENERATE_ESC_OPCODE  - Generates Opcodes for each segment of the cal sweep list based on the
                                   actions to be performed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_rec = structure to hold input values of type "cal_sweep_record"
                       as defined in QLIB_Defines.h

   \return  true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GENERATE_ESC_OPCODE( HANDLE hResourceContext,
                                                        void* sweep_rec );

   /******************************************************************************/
   /**
   FTM RF Common, 80-xxxxx-x Section 2.1, FTM_GET_ESC_SWEEP_RESULTS

   FTM_GET_ESC_SWEEP_RESULTS  - Get ESC Cal Sweep Results.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_rec = structure to hold input values of type "cal_sweep_record"
                       as defined in QLIB_Defines.h
   \param num_seg = Number of segments in the list for the cal sweep
   \param err_code = 64 bit error code returned by ESC sweep
   \param err_seg_num = 16 bit error segment number returned by ESC sweep

   \return  true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_ESC_SWEEP_RESULTS( HANDLE hResourceContext,
                                                          void * sweep_rec,
                                                          unsigned long num_seg,
                                                          unsigned __int64* err_code,
                                                          unsigned short* err_seg_num );

   /******************************************************************************/
   /**
   FTM RF Common, 80-xxxxx-x Section 2.1, QLIB_FTM_GET_ESC_SWEEP_RESULTS_COMPRESSED

   QLIB_FTM_GET_ESC_SWEEP_RESULTS_COMPRESSED  - Get ESC Cal Sweep Results as a compressed packet from the phone and uncompress the response packet.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  sweep_rec = structure to hold input values of type "cal_sweep_record"
                       as defined in QLIB_Defines.h
   \param num_seg = Number of segments in the list for the cal sweep
   \param err_code = 64 bit error code returned by ESC sweep
   \param err_seg_num = 16 bit error segment number returned by ESC sweep

   \return  true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_ESC_SWEEP_RESULTS_COMPRESSED( HANDLE hResourceContext,
                                                                     void * sweep_rec,
                                                                     unsigned long num_seg,
                                                                     unsigned __int64* err_code,
                                                                     unsigned short* err_seg_num );


   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1 section x.x, FTM_GET_THERM

   This command instructs the mobile to readback and return the thermistor value

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iThermValue      = Output value - The thermistor ADC value

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_THERM( HANDLE hResourceContext, unsigned char* iThermValue );

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1 section x.x, FTM_GET_ENH_THERM

   This command instructs the mobile to readback and return the thermistor value

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iThermValue      = Output value - The thermistor ADC value

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_ENH_THERM( HANDLE hResourceContext, unsigned long* iThermValue );

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1 section x.x, QLIB_FTM_GET_UNIFIED_ENH_THERM

   This command instructs the mobile to readback and return the thermistor value
   for a given tech on a device

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDevice          = Device for which therm read is being requested
   \param iRFmode          = RF mode in which therm read is being requested
   \param iThermValue      = Output value - The thermistor ADC value

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_UNIFIED_ENH_THERM( HANDLE hResourceContext, unsigned char iDevice, unsigned char iRfMode, unsigned long* iThermValue );


   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1 section x.x, QLIB_FTM_GET_UNIFIED_ENH_THERM_V2

   This command instructs the mobile to readback and return the thermistor value
   for a given tech, sig_path and tx rfm_device

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTechFamily      = Tech Family for which therm read is being requested
   \param iBand            = Band for which therm read is being requested
   \param iSubBand         = SubBand for which therm read is being requested
   \param iSigPath         = Tx Signal Path for which therm read is being requested
   \param iRfmDevice       = Tx Rfm Device for which therm read is being requested
   \param iThermValue      = Output value - The thermistor ADC value
   \param iThermValueDegC  = Output value - The thermistor value in degree Celcius

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_UNIFIED_ENH_THERM_V2( HANDLE hResourceContext, unsigned char iTechFamily, unsigned char iBand, unsigned char iSubBand,
                                                             unsigned char iSigPath, unsigned char iRfmDevice,
                                                             unsigned short* iThermValue, short* iThermValueDegC );


   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1 section 2.2, FTM_LOAD_RF_NV

   This operation is used to load RF NV from NV and into the RF Driver immediately.
   This allows the test automation to skip the step of putting the mobile into ONLINE only
   for the purpose of getting RF NV loaded properly.

   This command is designed to be used in test stations where RF Calibration is performed and
   non-signaling (specification/performance) testing is to be done immediately afterwards, without resetting the phone.

   If this step is not done, then the RF NV is not loaded from NV to the RF Driver, and the phone will not
   use the NV item changes that have occurred since the last time the phone was powered up.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pFTM_Error_Code = SUCCESS = 0, FAIL = 1

   \return true if successful, false if fail.

   \warning The transmitter should be turned off before this command is called.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOAD_RF_NV(
      HANDLE hResourceContext, unsigned short* pFTM_Error_Code);

   /******************************************************************************/
   /**
   FTM RF Common, 80-VA888-1, FTM_DO_INTERNAL_DEVICE_CAL

   This operation is used to perform internal calibrations, which are normally done
   the first time a phone is powered.   For example, on the MSM6280 with RTR6275,
   this function will calibrate NV_RFR_IQ_LINE_RESISTOR_I, NV_RFR_BB_FILTER_I, and
   NV_RTR_BB_FILTER_I.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pFTM_errorCode = SUCCESS = 0, FAIL = 1

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_INTERNAL_DEVICE_CAL(  HANDLE hResourceContext, unsigned short* pFTM_error_code );


   QLIB_API unsigned char QLIB_FTM_SET_CALIBRATION_STATE( HANDLE hResourceContext, unsigned char icalState );

   /******************************************************************************/
   /**
   Factory Test Mode RF Commands, 80-VP567-3  FTM_RFNV_READ

   This function will read NV items via FTM interface

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRFNV_ID = NV item enumeration

   \param  pData  = A byte array of NV item data

   \param iDataSz = [input] Size of the byte array
                    [output] The actual size of item data returned

   \param iFTM_Eror_Code = FTM Error code returned by FTM command
                     See rfnv_read_write_status_enum in QLib_Defines.h

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RFNV_READ(HANDLE hResourceContext, unsigned short iRFNV_ID, unsigned char* pData, unsigned short* iDataSz, unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
   Factory Test Mode RF Commands 80-VP567-3  FTM_RFNV_WRITE

   This function will write NV items via FTM interface

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRFNV_ID = NV item enumeration

   \param  pData  = A byte array of NV item data

   \param iDataSz = Size of the byte array

   \param iFTM_Eror_Code = FTM Error code returned by FTM command
                     See rfnv_read_write_status_enum in QLib_Defines.h

   \return true if successful, false if fail.

   \warning

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RFNV_WRITE(HANDLE hResourceContext, unsigned short iRFNV_ID, unsigned char* pData, unsigned short iDataSz, unsigned short* iFTM_Error_Code);

   /******************************************************************************/

   /**
   Factory Test Mode RF Commands, 80-VP567-3  FTM_GET_MAX_TRANSFER_SIZE

   This function will get the max transfer size of any FTM_RFNV_READ/WRITE_V2 via FTM interface.
   The size depends on diagnostic buffer maximum size on the target, which can vary from target to target.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param maxSize = [output] Diag Buffer max size

   \param iFTM_Eror_Code = FTM Error code returned by FTM command

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_MAX_TRANSFER_SIZE(HANDLE hResourceContext, unsigned short* maxSize, unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
   Factory Test Mode RF Commands, 80-VP567-3  FTM_CALL_RFNV_READ_V2

   This function will call FTM_CALL_RFNV_READ_V2 to accumlate data
   returned by FTM_RFNV_WRITE_V2

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRFNV_ID = NV item enumeration

   \param  pData  = A byte array of NV item data

   \param iDataSz = [input] Size of the byte array
                    [output] The actual size of item data returned

   \param  maxDIAGTransferSize  = Diag Buffer max size

   \param iFTM_Eror_Code = FTM Error code returned by FTM command

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CALL_RFNV_READ_V2(HANDLE hResourceContext, unsigned short iRFNV_ID, unsigned char* pData, unsigned short* iDataSz, unsigned short maxDIAGTransferSize, unsigned short* iFTM_Error_Code);
   /******************************************************************************/
   /**
   Factory Test Mode RF Commands, 80-VP567-3 FTM_CALL_RFNV_WRITE_V2

   This function will break large NV data into chunks of max DIAG
   transfer size.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRFNV_ID = NV item enumeration

   \param  pData  = A byte array of NV item data

   \param iDataSz = Size of the byte array

   \param maxDIAGTransferSize = Diag Buffer max size

   \param iFTM_Eror_Code = FTM Error code returned by FTM command

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CALL_RFNV_WRITE_V2(HANDLE hResourceContext, unsigned short iRFNV_ID, unsigned char* pData, unsigned short iDataSz,  unsigned short maxDIAGTransferSize, unsigned short* iFTM_Error_Code);
   /******************************************************************************/
   /**
   Factory Test Mode RF Commands x.x.x.x  FTM_DO_SELF_CAL

   This function is used to call the different Self Cal routines

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iCal_Type = Self Cal type

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_DO_SELF_CAL(HANDLE hResourceContext, unsigned char iCal_Type);

   /******************************************************************************/
   /**
   Factory Test Mode RF Commands. See 80-N7536-1

   This function is used to call FTM_ANT_TUNER_OVERWRITE_CMD (610) on FTM common dispatch

   \param iGSBICore = GSBICore

   \param iChipSelect = ChipSelect Value

   \param iCodeWord1 = code word 1

   \param iCodeWord2 = code word 2

   \param iCodeWord3 = code word 3

   \param iCodeWord4 = code word 4

   \return true if sent successful, false if fail.

   \warning This command is not used by any SUITE Dlls
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_ANT_TUNER_OVERWRITE_CMD(    HANDLE hResourceContext,
                                                               unsigned char iGSBICore,
                                                               unsigned char iChipSelect,
                                                               unsigned int iCodeWord1,
                                                               unsigned int iCodeWord2,
                                                               unsigned int iCodeWord3,
                                                               unsigned int iCodeWord4);


   /******************************************************************************/
   /**
   Factory Test Mode RF Commands. See 80-VA888-1

   This function is used to call FTM_RFFE_READWRITE (623) on FTM common dispatch

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iExtMode = Extened Mode: Non-extended (0). Extened (1)

   \param iReadWrite = Read(1), Write(0)

   \param iChannedl = RFFE 0 (0), RFFE 1(1)

   \param iSlave = Slave ID

   \param iAddress = Address

   \param iData = Data

   \param iHalfSpeed = Full speed (0), Half speed(1)

   \return true if sent successful, false if fail.

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_RFFE_READWRITE_CMD( HANDLE hResourceContext,
                                                       unsigned char iExtMode,
                                                       unsigned char iReadWrite,
                                                       unsigned char iChannel,
                                                       unsigned char iSlave,
                                                       unsigned short iAddress,
                                                       unsigned char* iData,
                                                       unsigned char iHalfSpeed);

   /******************************************************************************/
   /**
   Factory Test Mode RFFE Command Interface. See 80-NE517-1 A

   This function is used to call FTM_RFFE_MULTIBYTE_READWRITE (622) on FTM common dispatch

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iExtMode = Extened Mode: Non-extended (0). Extened (1)

   \param iReadWrite = Read(1), Write(0)

   \param iChannedl = RFFE 0 (0), RFFE 1(1)

   \param iSlave = Slave ID

   \param iAddress = Address

   \param iNumBytes = Number of Bytes to read/write

   \param iData = Data (LSB)

   \param iData1 = Data

   \param iData2 = Data

   \param iData3 = Data (MSB)

   \param iHalfSpeed = Full speed (0), Half speed(1)

   \return true if sent successful, false if fail.

   \warning
   *******************************************************************************/

   unsigned char QLIB_FTM_RFFE_MULTIBYTE_READWRITE_CMD( HANDLE hResourceContext,
                                                        unsigned char iExtMode,
                                                        unsigned char iReadWrite,
                                                        unsigned char iChannel,
                                                        unsigned char iSlave,
                                                        unsigned short iAddress,
                                                        unsigned char iNumBytes,
                                                        unsigned long* iData,
                                                        unsigned long* iData1,
                                                        unsigned long* iData2,
                                                        unsigned long* iData3,
                                                        unsigned char iHalfSpeed);


   /******************************************************************************/
   /**

   Sets the enhanced calibration action for

   \Param ienhCalAction = 0 - No Action
                     = 1 - APT
   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TX_ENH_CAL_ACTION( HANDLE hResourceContext, unsigned char ienhCalAction );

   /******************************************************************************/
   /**

   Loads the Tx linearizer calibration data to the embedded side data structures. Used when
   FTM_SET_TX_ENH_CAL_ACTION is used to set calAction > 0

   \Param pFTM_Tx_Lin_CalData_Req[input] , pointer to FTM_Load_Tx_Linearizer_Cal_Data_Request defined in Qlib_Defines.h
   \Param pFTM_Tx_Lin_CalData_Res[input], pointer to FTM_Load_Tx_Cal_Data_Response defined in QLib_Defines.h
   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOAD_TX_LINEARIZER_CAL_DATA( HANDLE hResourceContext, void * pFTM_Tx_Lin_CalData_Req, void * pFTM_Tx_Lin_CalData_Res );

   /******************************************************************************/
   /**

   Queries a RFFE Device and returns and manufacture id, product id and revision id

   \Param pFTM_GET_RFFE_DEVICE_INFO_Request , pointer to request packet
   \Param pFTM_GET_RFFE_DEVICE_INFO_Response, pointer to response packet
   \return true if successful, false if fail.

   \warning
    *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_RFFE_DEVICE_INFO( HANDLE hResourceContext,
                                                         void * pFTM_GET_RFFE_DEVICE_INFO_Request, void *pFTM_GET_RFFE_DEVICE_INFO_Response);


   /******************************************************************************/
   /**

   Queries a RFFE Device and returns and manufacture id, product id and revision id

   \Param pFTM_GET_RFFE_DEVICE_INFO_Request_V2 , pointer to request packet
   \Param pFTM_GET_RFFE_DEVICE_INFO_Response, pointer to response packet
   \return true if successful, false if fail.

   \warning
    *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_RFFE_DEVICE_INFO_V2( HANDLE hResourceContext,
                                                            void * pFTM_GET_RFFE_DEVICE_INFO_Request_V2, void *pFTM_GET_RFFE_DEVICE_INFO_Response);


   /******************************************************************************/
   /**

      /******************************************************************************/
   /**

   Queries a RFFE Device and returns and manufacture id, product id and revision id

   \Param pFTM_GET_RFFE_DEVICE_INFO_Request , pointer to request packet
   \Param pFTM_GET_RFFE_DEVICE_INFO_Response, pointer to response packet
   \return true if successful, false if fail.

   \warning
    *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_RFFE_DEVICE_IDS( HANDLE hResourceContext,
                                                        void * pFTM_GET_RFFE_DEVICE_INFO_Request, void *pFTM_GET_RFFE_DEVICE_INFO_Response);

   /******************************************************************************/
   /**

   Loads the Tx freq comp calibration data to the embedded side data structures. Used when
   FTM_SET_TX_ENH_CAL_ACTION is used to set calAction > 0

   \Param pFTM_Tx_Freqcomp_CalData_Req[input] , pointer to FTM_Load_Tx_FreqComp_Cal_Data_Request defined in QLib_Defines.h
   \Param pFTM_Tx_Freqcomp_CalData_Res[input], pointer to FTM_Load_Tx_Cal_Data_Response defined in Qlib_Defines.h
   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char  QLIB_FTM_LOAD_TX_FREQCOMP_CAL_DATA( HANDLE hResourceContext, void * pFTM_Tx_Freqcomp_CalData_Req, void * pFTM_Tx_FreqComp_CalData_Res);

   /******************************************************************************/
   /**

   Sets the power optimization mode for QPOET programming

   \Param iPwrOptMode   = 0 - POET SLEEP
                        = 1 - POET BYPASS
                        = 2 - POET APT
                        = 3 - POET ET
   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_PWR_OPTIMIZATION_MODE( HANDLE hResourceContext, unsigned char iPwrOptMode );

   /******************************************************************************/
   /**
   Factory Test Mode RF Commands. See 80-VA888-1

   This command forces the RF Driver to disable any activities that were started since the last call
   to FTM_RF_SET_MODE , for a technology.
   At the end of the execution, the RF devices will be disabled

   \Param

   \return true if successful, false if fail.

   \warning 2012.10: this function is not officially released in AMSS MSM8960 equivalents.
                     It will only be available in AMSS MSM8974 equivalents according to the
                     Factory Test Roadmap document 80-NC791-1

   \note This function can be used in QMSL FTM Sequencer operation
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_MODE_EXIT( HANDLE hResourceContext, unsigned short* iFTM_Error_Code);


   /*******************************************************************
   QLIB_FTM_RF_GET_TXLUT_INFO_FOR_RED_CAL - FTM commnad to get the LUT index for Reduced RGI sweep from the RFIC Table.
   This command is invoked only when RFIC table is loaded in the RFCAL just like any other param file.
   \param [in] hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param [in]devices = device selected from xtt.
   \param [in]rf_mode =  rfMode to identify technology band.
   \param [in] alt_path =  alt_path to select RfPath. Currently set to default 0 or primary.
   \param [in] num_valid_paStates = number of valid PA states.
   \param [in] pa_states = pa states for the sweep coming from param file.
   \param [out] lut_ids = Lut indexes list for each pa state coming from RFIC table.
   \param [out] prd_id = product id for each pa state coming from RFIC table.
   \param [out] mfg_id = manufacturing id for each pa state coming from RFIC table.
   \param [out] rev_id = revision id for each pa state coming from RFIC table.
   \return true if successful, false if fail.
   ********************************************************************/
   QLIB_API unsigned char QLIB_FTM_RF_GET_TXLUT_INFO_FOR_RED_CAL( HANDLE hResourceContext,
                                                                  unsigned char device,
                                                                  unsigned char rf_mode,
                                                                  unsigned char alt_path,
                                                                  unsigned int num_valid_paStates,
                                                                  void* pa_states,
                                                                  void* lut_ids,
                                                                  unsigned short& prd_id,
                                                                  unsigned short& mfg_id,
                                                                  unsigned short& rev_id);
   /*******************************************************************
   QLIB_FTM_GET_STATIC_INFO - FTM command to get the PA switchpoints from the Phone
   This command is invoked only when RFIC table is loaded in the RFCAL just like any other param file.
   \param [in] hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param static resp which contains status, active pa states,rise and fall switch points for PA
   \param static req contains band tech device and action to specify the extraction of PA switchpoints
   \return true if successful, false if fail.
   ********************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_STATIC_INFO( HANDLE hResourceContext,
                                                    void* static_resp, void* static_req);

   /*******************************************************************
   QLIB_FTM_SET_TUNABLE_CAP - FTM command to set the Tunable Cap on the QPA 4k QFE 4345
   This command is invoked only when RFIC table is loaded in the RFCAL just like any other param file.
   \param [in] hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param set_tunable_cap_pkt which contains tech and value of offset that will be written on the register
   \return true if successful, false if fail.
   ********************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_TUNABLE_CAP( HANDLE hResourceContext, void* pFTM_tunable_cap_pkt);

   /******************************************************************************/
   /**

   QLIB_FTM_GET_RF_PATH_INFORMATION  - Get Information regarding RF paths for calibration.

   This command is used to get RF Path information like RF Front End Path index , WTR VCO Path index, NV container Index etc. for band(s) of a technology.
   Information returned by this command is then used to build calibration sweeps.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param request = Pointer to request information

   \return status = Pointer to the response data

   \return  Returns of the error status of the command; ie. if the command got executed successfully or not.
   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_RF_PATH_INFORMATION( HANDLE hResourceContext, void* request, void* response );

   /******************************************************************************/
   /**
   QLIB_FTM_NLIC_CHAR_MODE_ENTER

   A command to signal entrance of FTM NLIC Mode to handle config properly

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iFTM_Error_Code = Pointer to the variable to store the Error code returned from NLIC params override

   \return true if successful, false if fail.

   \warning

   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NLIC_CHAR_MODE_ENTER( HANDLE hResourceContext, unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
   QLIB_FTM_NLIC_CHAR_PARAMS_OVERRIDE

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pNLICConfigRequestParams = Pointer to the structure with NLIC configuration request params

   \param nlic_type = NLIC Char Measurement Type

   \param measTime = NLIC Char Measurement duration

   \param iFTM_Error_Code = Pointer to the variable to store the Error code returned from NLIC params override

   \return true if successful, false if fail.

   \warning

   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NLIC_CHAR_PARAMS_OVERRIDE( HANDLE hResourceContext, void *pNLICConfigRequestParams,
                                                              unsigned short nlic_type, unsigned int measTime, unsigned short* iFTM_Error_Code );

   /******************************************************************************/
   /**
   QLIB_FTM_NLIC_CHAR_GET_MEAS_RESULTS

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pNLICMeasResults = Pointer to the structure with NLIC measurement result

   \param pStatus = Pointer to the variable to store the status of NLIC result fetch

   \param iFTM_Error_Code = Pointer to the variable to store the Error code returned from NLIC params override

   \return true if successful, false if fail.

   \warning

   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NLIC_CHAR_GET_MEAS_RESULTS( HANDLE hResourceContext, void* pNLICMeasResults, unsigned short nlic_type, unsigned short* num_ant, unsigned short *iFTM_Error_Code);

   /******************************************************************************/
   /**
    QLIB_FTM_GET_FEM_DIRECTORY_INFO  - Get Information regarding RF Front End Module Directory paths to copy neccessary parameter files for calibration.

   This command is used to get RF Front End Module directory paths in  \rfc\device_settings folder in the build.
   Information returned by this command is then used to copy the neccessary device_settings and xml parameter files from location1 to location2

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param request = pointer to request index (to get directory path information)

   \return status = pointer to directory path information

   \return  true if command execution was successful, false if unsuccessful.

   ******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_FEM_DIRECTORY_INFO( HANDLE hResourceContext, void* reqIdx, void* dirPathInfo );

   QLIB_API unsigned char QLIB_FTM_FEM_COMMON_DISPATCH( HANDLE hResourceContext, void *fem_report );

   /*******************************************************************************/
   /**
   FTM_GET_HW_INDEX_INFO - Query HW indices (platformID and boardID)

   This command is used to get RF Front End Module HW Indices (platformID and boardID) in rfdevice_fem\etc\efs folder in the build.
   Information returned by this command is then used to copy the neccessary device_lut and device_settings file(s) from location1 to location2

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if command execution was successful, false if unsuccessful.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_GET_HW_INDEX_INFO( HANDLE hResourceContext, void* hwIndicesInfo );

#ifdef __cplusplus
}  // extern "C"
#endif

#endif   // defined(_QLIB_FTM_COMMON_DISPATCH_H)

