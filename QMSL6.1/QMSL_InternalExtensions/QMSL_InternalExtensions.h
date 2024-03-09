/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_InternalExtensions.h#7 $
 *
 *  Project : QMSL
 *
 *  Package :
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_HandleManager
 *
 *********************************************************************
<b>Version History:</b>
\verbatim
\endverbatim
 *********************************************************************
 */

#pragma once

#include "QMSL_inc\QLIB.h"
#include "QMSL_HandleManager.h"
#include "QMSL_Async\QMSL_Async_LogPacket.h"
#include "QMSL_Async\QMSL_Async_LogCollector.h"
#include <vector>
using namespace std;

/**
 * Enables a single log code in the phone's log mask.
 * The phone is queried for its current log mask, then the log code bit is OR'ed into the existing log mask.
 * If the log code was already enabled, no new mask is set.
 *
 * \param handle : the unique identifier for the COM port
 * \param log_code : the log code to be enabled in the mask
 * \param equip_id : the enumberation identifying the sub-mask (see log_equip_id_enum_type)
 */
QLIB_API bool QMSL_Ext_Enable_Log_Code( HANDLE handle, unsigned short log_code, unsigned char equip_id );

/**
 * Enables multiple log codes in the phone's log mask.
 * The phone is queried for its current log mask, then the log code bits are OR'ed into the existing log mask.
 * If the log codes were already enabled, no new mask is set.
 *
 * \param handle : the unique identifier for the COM port
 * \param log_code : the log code to be enabled in the mask
 * \param equip_id : the enumberation identifying the sub-mask (see log_equip_id_enum_type)
 */
QLIB_API bool QMSL_Ext_Enable_Log_Codes( HANDLE handle, std::vector<unsigned short> log_codes, unsigned char equip_id );

/**
 * Disables multiple log codes in the phone's log mask.
 *
 * \param handle : the unique identifier for the COM port
 * \param log_code : the log code to be enabled in the mask
 * \param equip_id : the enumberation identifying the sub-mask (see log_equip_id_enum_type)
 */
QLIB_API bool QMSL_Ext_Disable_Log_Codes( HANDLE handle, const vector<unsigned short>& log_codes, unsigned char equip_id ); 

QLIB_API bool QMSL_Ext_Clear_All_Log_Codes( HANDLE handle, unsigned char equip_id );

QLIB_API  bool QMSL_Ext_GetSingleLog( HANDLE handle, unsigned short log_code, unsigned char equip_id, CQMSL_Async_LogPacket& logPckt, unsigned int timeout_ms = 2000 );

QLIB_API  bool QMSL_Ext_GetMultipleLogs( HANDLE handle, unsigned short log_code, unsigned char equip_id, vector<CQMSL_Async_LogPacket>& logPckts, unsigned int numPckts, unsigned int timeout_ms = 2000 );

QLIB_API  bool QMSL_Ext_GetSingleFTMLog( HANDLE handle, unsigned short ftm_log_code, CQMSL_Async_LogPacket& logPckt, unsigned int timeout_ms = 2000 );

QLIB_API  bool QMSL_Ext_GetMultipleFTMLogs( HANDLE handle, unsigned short ftm_log_code, vector<CQMSL_Async_LogPacket>& logPckt, unsigned int numPckts, unsigned int timeout_ms = 2000 );

QLIB_API bool QMSL_Ext_EnableFTMLog(HANDLE handle, unsigned short ftm_log_code);

QLIB_API bool QMSL_Ext_DisableFTMLog(HANDLE handle, unsigned short ftm_log_code);

QLIB_API  bool QMSL_Ext_StartFTMLogCollection( HANDLE handle, unsigned short ftm_log_code, CQMSL_Async_LogCollector& logCollector);

QLIB_API  bool QMSL_Ext_StopFTMLogCollection( HANDLE handle, CQMSL_Async_LogCollector& logCollector);

QLIB_API  bool QMSL_Ext_SBI_Write( HANDLE handle, unsigned char slave_id, unsigned char data_mask, unsigned char reg_address, unsigned char reg_data );

QLIB_API  bool QMSL_Ext_SBI_Read(HANDLE handle, unsigned char slave_id, unsigned char reg_address, unsigned char& reg_data );

QLIB_API  bool QMSL_Ext_SetDIPSwitchMask( HANDLE handle, unsigned short mask );

QLIB_API  bool QMSL_Ext_GetDIPSwitchMask( HANDLE handle, unsigned short* mask );

QLIB_API  bool QMSL_Ext_Security_Challenge( HANDLE handle );

/**
 * For ssid check the QXDM message view.  SSID will be displayed with mask to the left of the message item.
 * you can also find SSIDs in AMSSBuildID/services/diag/msgcfg.h
 * example:
 *    [04001/02] GSM L1/High
 *    where 4001 (decimal) is the SSID, and 02 is the bit to set.
 *    To enable this item send ssid=4001, with mask set to 4 (2^2=4)
 *
 * \param handle : the unique identifier for the COM port
 * \param mask : the message mask for the messages to be enabled (local to ssid)
 * \param ssid : the message group for which the mask applies (eg GSM L1)
 */
QLIB_API  bool QMSL_Ext_SetMessageMask( HANDLE handle, unsigned short mask, unsigned short ssid );


/***********************************************************************************
         *******           A G P S   C O M M A N D S          ********
         *******   To be moved to QLIB for official release.  ********
************************************************************************************/
QLIB_API  bool QLIB_LSM_SET_TEST_MODE( HANDLE handle, unsigned short mode_setting_password, unsigned char mode_action, unsigned short* mode_password_accept, unsigned char* mode_state );

QLIB_API  bool QLIB_LSM_START_PRESCIBED_DWELL( HANDLE handle, unsigned char flags, unsigned char chan, unsigned char sv_id, unsigned char cf_mode,
      unsigned char pre_detection_n, unsigned char pre_detection_bit_n,
      unsigned char log_coherent_sums, unsigned char resync_ts_bc, unsigned short post_detection_n,
      unsigned short coherent_log_source, unsigned short sub_chan_frequency, int range_rate,
      unsigned int sub_msec, unsigned int number_of_dwells, unsigned int results_out_interval,
      unsigned short snr_threshold, unsigned short inter_chan_frequency, unsigned char stop_sv_id,
      unsigned char* request_result );

QLIB_API  bool QLIB_LSM_START_PRESCIBED_DWELL_2( HANDLE handle, unsigned int flags, unsigned char pre_detection_n, unsigned char pre_detection_bit_n,
      unsigned char resync_ts_bc, unsigned char base_chan, unsigned char n_chan, unsigned char base_prn_code,
      unsigned short cf_window_f, unsigned short cf_window_t, unsigned short post_detection_n,
      unsigned short coherent_log_source, unsigned short snr_threshold, unsigned short mft_frequency_step,
      unsigned int number_of_dwells, unsigned int results_out_interval,
      unsigned int base_code_phase, int base_frequency,
      short inter_chan_freq_increment, short n_inter_dwell_freq_increments, int inter_dwell_freq_increment,
      int inter_chan_code_phase_increment, int inter_dwell_code_phase_increment, short n_inter_dwell_code_phase_increments,
      unsigned char inter_chan_prn_code_increment, unsigned char inter_dwell_prn_code_increment, short n_inter_dwell_prn_code_increments,
      unsigned char* request_result );

/***********************************************************************************
           *******           I Q  C A P T U R E   C O M M A N D S          ********
************************************************************************************/
/**
 * Gets the IQ Capture configuration information of the target platform.
 *
 * \param handle : the unique identifier for the COM port
 * \param maxRecordSize : max record size - output
 * \param sampleBitFormat : sample bit format - output
 * \param samplingFreq : sampling frequency - output
 * \param technology : 0 = Common (sub sys cmd code 4) 1 = MediaFLO (sub sys cmd code 10 ) - input
 */
QLIB_API  bool QMSL_Ext_IQ_CAPTURE_GET_CONFIG( HANDLE handle, unsigned short* maxRecordSize, unsigned short* sampleBitFormat, unsigned long* samplingFreq, unsigned char technology );
/**
 * Captures a new set of data and returns 256 records or returns the specified 256 records.
 *
 * \param handle : the unique identifier for the COM port
 * \param pIqData : IQ data records - output
 * \param dataIndex : record index - input
 * \param technology : 0 = Common (sub sys cmd code 4) 1 = MediaFLO (sub sys cmd code 10 ) - input
 */
QLIB_API  bool QMSL_Ext_IQ_CAPTURE_GET_DATA( HANDLE handle,  unsigned short* pIqData, unsigned short* dataIndex, unsigned char technology );
/**
 * Sets the antenna to be used for IQ Capture.
 *
 * \param handle : the unique identifier for the COM port
 * \param antenna : 0 Antenna0; 1 Antenna1; 2 antennas 1 and 2 - input
 */
QLIB_API  bool QMSL_Ext_IQ_CAPTURE_SET_ANTENNA( HANDLE handle, unsigned short antenna );

/**
 * Enables single-shot mode for GSM IQ Capture.
 *
 * \param handle : the unique identifier for the COM port
 */
QLIB_API  bool QMSL_Ext_GSM_IQ_CAPTURE_ENABLE_SINGLESHOT( HANDLE handle );


/***********************************************************************************
     *******    D I G I T A L  F I L T E R  C O E F F I C I E N T S    ********
************************************************************************************/
/**
 * Sets the digital filter coefficients in WCDMA.
 *
 * \param handle : the unique identifier for the COM port
 * \param coefficient_bytes : an array of twenty two bytes that represents the eleven coeffcients of the digital filter
 * \param band: byte that identifies the band in which the phone is operating
 * \param chain: byte that identifies whether the rx path is primary or diversity
 */
QLIB_API bool QMSL_Ext_FTM_HWTC_SET_RXF_FILTER_COEFFICIENTS( HANDLE handle, vector<long> coefficients, unsigned char band, unsigned char chain );

/**
 * Calculates a 22 byte array corresponding to the eleven digital filter coefficients using the decimal coefficient vector as input.
 *
 * \param coefficient_bytes : an array of twenty two bytes that represents the eleven coeffcients of the digital filter
 * \param decimalCoefficientsNumericVector: the input vector that contains the decimal values of the eleven coeffcients
 */
QLIB_API bool QMSL_Ext_Calculate_RxF_Filter_Coefficients( vector<long> decimalCoefficientsNumericVector, unsigned char* coefficient_bytes );

/************************************************
     *******    C0C1 DELAY VALUE     ********
************************************************/

/**
 * Sets the C0C1 Delay Value
 *
 * \param handle : the unique identifier for the COM port
 * \param delay_value : single unsigned long value for the C0C1 Delay
 * \param band: byte that identifies the band in which the phone is operating
*/
QLIB_API bool QMSL_Ext_FTM_HWTC_SET_C0_C1_DELAY( HANDLE handle, unsigned long delay_value, unsigned char band );

/************************************************
     *******    DVT String     ********
************************************************/

/**
 * Send a
 *
 * \param handle : the unique identifier for the COM port
 * \param sDVTString: [input/output] a NULL terminated DVT String
*/
QLIB_API bool QMSL_Ext_FTM_HWTC_SEND_DVT_STRING( HANDLE handle, char* sDVTString );

/**
 * Sets up multicarrier mode in WCDMA
 *
 * \param handle : the unique identifier for the COM port
 * \param secondCarrierDLChannel: the DL UARFCN of the second carrier
*/
QLIB_API bool QMSL_Ext_Setup_MultiCarrier_Mode( HANDLE handle, long secondCarrierDLChannel );


/***********************************************************************************
         *******           UBM   C O M M A N D S          ********
************************************************************************************/

/******************************************************************************/
/**
MBP RF DIAG, Subcommand 27

	This command dumps the SBI settings to a file in the phones EFS. The
	file is located in /dtv/rf/DUMP_mbp_rf_sbi_isdbt_b0v0_2m_uhf.txt (for ISDB-T) or
	/dtv/rf/DUMP_mbp_rf_sbi_dvbh_b0v0_2m_uhf.txt (for DVB-H).

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\return 1 if response packet was successfully returned, 0 if it failed for any reason.

\warning

*******************************************************************************/
QLIB_API bool QMSL_Ext_DIAG_MBP_RF_DUMP_SBI_SETTINGS_TO_EFS_CMD(HANDLE hResourceContext);

/***********************************************************************************
     *******              L T E   I N O   C O M M A N D S              ********
************************************************************************************/

/******************************************************************************/
/**

	Helper function to enable IQ log capture, capture a specified sample size and disable the logging.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param iCaptureType = The Capture Type (0-Continuous, 1-Burst)
\param iTestbusSelType = The Testbus Sel Type (1-8)
\param iBufferSize = Number of logs to capture.
\param iTimedCapture = Reserved for future use (set to 0)
\param iSystemTime = Reserved for future use (set to 0)
\param iCapture = vector returning the captured data

\return 1 if procedure completed successfully, 0 if it failed for any reason.

\warning

*******************************************************************************/
QLIB_API bool QMSL_Ext_FTM_LTE_INO_Capture(HANDLE hResourceContext,
      unsigned char iCaptureType,
      unsigned char iTestbusSelType,
      unsigned long iBufferSize,
      unsigned long iTimedCapture,
      unsigned long iSystemTime,
      vector<unsigned char>&iCapture);

/*******************************************************************
     *******         LTE INTER-RAT COMMANDS        ********
********************************************************************/

QLIB_API bool QMSL_Ext_FTM_MEAS_XTOY_TEST_Y(HANDLE hResourceContext,
      lte_ftm_xtoy_test_params* _pTestParams );
/*unsigned short iSourceTech,
unsigned short iSourceBand,
unsigned short iSourceChannel,
unsigned short iSourceBandwidth,
unsigned short iSourceDiversityEnable,
unsigned short iSourceBufferIndex,
unsigned short iTargetTech,
unsigned short iTargetBand,
unsigned short iTargetChannel,
unsigned short iTargetBandwidth,
unsigned short iTargetDiversityEnable,
unsigned short iTargetBufferIndex,
unsigned short iTestLevel );*/

QLIB_API bool QMSL_Ext_FTM_MEAS_XTOY_TEST_X(HANDLE hResourceContext,
      lte_ftm_xtoy_test_params* _pTestParams );
/*unsigned short iSourceTech,
unsigned short iSourceBand,
unsigned short iSourceChannel,
unsigned short iSourceBandwidth,
unsigned short iSourceDiversityEnable,
unsigned short iSourceBufferIndex,
unsigned short iTargetTech,
unsigned short iTargetBand,
unsigned short iTargetChannel,
unsigned short iTargetBandwidth,
unsigned short iTargetDiversityEnable,
unsigned short iTargetBufferIndex,
unsigned short iTestLevel );*/

QLIB_API bool QMSL_Ext_FTM_MEAS_XTOY_TEST_Y_v2(HANDLE hResourceContext,
      lte_ftm_xtoy_test_params_v2* _pTestParams );
/*unsigned short iSourceTech,
unsigned short iSourceBand,
unsigned short iSourceChannel,
unsigned short iSourceBandwidth,
unsigned short iSourceDiversityEnable,
unsigned short iSourceBufferIndex,
unsigned short iTargetTech,
unsigned short iTargetBand,
unsigned short iTargetChannel,
unsigned short iTargetBandwidth,
unsigned short iTargetDiversityEnable,
unsigned short iTargetBufferIndex,
unsigned short iTestLevel );*/

QLIB_API bool QMSL_Ext_FTM_MEAS_XTOY_TEST_X_v2(HANDLE hResourceContext,
      lte_ftm_xtoy_test_params_v2* _pTestParams );
/*unsigned short iSourceTech,
unsigned short iSourceBand,
unsigned short iSourceChannel,
unsigned short iSourceBandwidth,
unsigned short iSourceDiversityEnable,
unsigned short iSourceBufferIndex,
unsigned short iTargetTech,
unsigned short iTargetBand,
unsigned short iTargetChannel,
unsigned short iTargetBandwidth,
unsigned short iTargetDiversityEnable,
unsigned short iTargetBufferIndex,
unsigned short iTestLevel );*/

QLIB_API void QMSL_Ext_FTM_XTOG_GET_RSSI(HANDLE hResourceContext, unsigned short itargetTech, unsigned short iTargetBand, unsigned short iTargetChannel,
      unsigned short * iRSSIlevel, unsigned short *iftmerrorcode);

/*unsigned short itargetTech,
unsigned short iTargetBand,
unsigned short iTargetChannel,
unsigned short iRSSIlevel,
unsigned short iftmerrorcode,
*/

QLIB_API bool QMSL_Ext_SET_FB_PATH(HANDLE hResourceContext,unsigned char tx_device, unsigned char enable_fb_path,unsigned char fb_state);

QLIB_API bool QMSL_Ext_MEAS_FBRX_NOISE(HANDLE hResourceContext, unsigned short rf_mode,unsigned char mode_id,unsigned char device_id, unsigned char num_averages,unsigned char num_bw_types,unsigned short* chan_list,unsigned char*bw_list );

QLIB_API bool QMSl_Ext_Do_RSB_Cal(HANDLE hResourceContext, unsigned char txt_RFmode, unsigned char override_stg,unsigned char tx_device, unsigned char exit_required);

/*******************************************************************
 *******     TECHNOLOGY DEVICE STATUS UPDATE INTERFACE      ********
********************************************************************/
/******************************************************************************/
   /**
   LTE Device Status Update API

   \param   [in]      iManufId = RFFE Manufacturer ID. Don't care for internal testing.
   \param   [in]      iPrdId = RFFE Product ID.Don't care for internal testing.
   \param   [in]      iPrdRev = RFFE product Revision. Don't care for internal testing.
   \param   [in]      iRFMode = Band RF Mode
   \param   [in]      iTxChannel = UL channel number
   \param   [in]      iRxChannel = Corresponding DL channel number.
   \param   [in]      iCellIdx = 0 - Primary Cell, 1 = Secondary cell.
   \param   [in]      iRegIdx[8] = Register index. Don't care for internal testing.
   \param   [in]      iRegVal[8] = Register value. Don't care for internal testing.

   \param   [out]     iFTMErrorCode = 0 - Success, 1 - Error

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
QLIB_API bool QLIB_Ext_FTM_LTE_RFFE_DEVICE_STATUS_UPDATE( HANDLE hResourceContext,
      unsigned short iManufId,
      unsigned char iPrdId,
      unsigned char iPrdRev,
      unsigned char iRFMode,
      unsigned short iTxChannel,
      unsigned short iRxChannel,
      unsigned char iCellIdx,
      unsigned short* iRegIdx,
      unsigned char* iRegVal,
      unsigned char* iFTMErrorCode
      );

/******************************************************************************/
   /**
   TDS-CDMA Device Status Update API

   \param   [in]      iPrimDev = Rx0. Primary Device
   \param   [in]      iSecDev = Rx1. Secondary Device
   \param   [in]      iTxDev = Tx Device
   \param   [in]      iBandInd = Serving Cell Band Indicator
   \param   [in]      iBufId = Buffer Id.Hardcoded to 0
   \param   [in]      bDrxEnable = Enable/Disable DRx.
   \param   [in]      iUpdateType = 
   \param   [in]      iSwitchState = 0 - Port A, 1 - Port B

   \param   [out]     iFTMErrorCode = 0 - Success, 1 - Error

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

QLIB_API bool QLIB_Ext_FTM_TDSCDMA_TRIGGER_PORT_SWITCH( HANDLE hResourceContext,
      unsigned char iPrimDev,
      unsigned char iSecDev,
      unsigned char iTxDev,
      unsigned short iBandInd,
      unsigned short iBufId,
      bool bDRxEnable,
      unsigned short iUpdateType,
      unsigned char iSwitchState,
      unsigned char* iFTMErrorCode
      );

/******************************************************************************/
   /**
   CDMA Device Status Update API

   \param   [out]    iFTMErrorCode = 0 - Success, 1 - Error

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/

QLIB_API bool QLIB_Ext_FTM_TXRX_AGC_RELOAD( HANDLE hResourceContext,
      unsigned char* iFTMErrorCode
      );

/******************************************************************************/
typedef enum
{
   FTM_LTE_INO_ENABLE=1,
   FTM_LTE_INO_CAPTURE=3,
   FTM_LTE_INO_DISABLE=2
} FTM_LTE_INO_command_enum_type;

#define FTM_LTE_INO_LOG 0x20

typedef struct
{
   word ftm_lte_ino_ftm_log_id;
   byte ftm_lte_ino_payload[1024];
} ftm_lte_ino_log_capture;
