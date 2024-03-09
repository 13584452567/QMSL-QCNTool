/******************************************************************************
 * $File: //depot/HTE/QDART/QMSL6.1/QMSL_InternalExtensions/QMSL_1X_HDR_Radio.h $
 *
 * DESCRIPTION: QMSL_1X_HDR_Radio
 ******************************************************************************
 *
 * Copyright (c) 2014 QUALCOMM Technologies Incorporated.
 * All rights reserved.
 * Qualcomm Confidential and Proprietary
 *
 ******************************************************************************
 *
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_InternalExtensions/QMSL_1X_HDR_Radio.h#1 $
 * $DateTime: 2014/10/16 15:00:54 $
 *
 */

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_ENTER - Enter 1x mode of operation

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which 1x is to be entered
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_ENTER(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_EXIT - Exit 1x mode of operation

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which 1x is to be exited
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_EXIT(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_ENABLE - Enable radio for 1x mode of operation

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which 1x is to be enabled
\Param  [in]       iBand = CDMA band for which radio is enabled
\Param  [in]       iChannel = CDMA channel for which radio is enabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_ENABLE(HANDLE hResourceContext, unsigned char iDevice,
                                       unsigned char iBand, unsigned short iChannel, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_DISABLE - Disable radio for 1x mode of operation

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which 1x is to be disabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_DISABLE(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_WAKEUP_RX - Enable 1x receiver

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Rx is to be enabled
\Param  [in]       iBand = RF band to tune the receiver
\Param  [in]       iChannel = RF chan to tune the receiver
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_WAKEUP_RX(HANDLE hResourceContext, unsigned char iDevice,
      unsigned char iBand, unsigned short iChannel, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_SLEEP_RX - Disable 1x receiver

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Rx is to be disabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_SLEEP_RX(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_WAKEUP_TX - Enable 1x transmitter

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Tx is to be enabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_WAKEUP_TX(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_SLEEP_TX - Disable 1x transmitter

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Tx is to be disabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_SLEEP_TX(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_RETUNE - Retune 1x receiver and transmitter

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Tx is enabled
\Param  [in]       iBand = Band to be retuned to
\Param  [in]       iChannel = Chan to be retuned to
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_RETUNE(HANDLE hResourceContext, unsigned char iDevice,
                                       unsigned char iBand, unsigned short iChannel, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_ENABLE_DIV - Enable 1x receive diversity

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iMasterTxRxDevice = Master RxTx Device
\Param  [in]       iSlaveRxDevice = Slave Rx Device which is used for Rx Div
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_ENABLE_DIV(HANDLE hResourceContext, unsigned char iMasterTxRxDevice,
      unsigned char iSlaveRxDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_DISABLE_DIV - Disable 1x receive diversity

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iSlaveRxDevice = Slave Rx Device which is used for Rx Div
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_DISABLE_DIV(HANDLE hResourceContext, unsigned char iSlaveRxDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_GET_RXAGC - Query 1x RxAGC data

\Param  [in]   hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]   iDevice = Device for which RxAGC data is queried
\Param  [out]  iRxAGC = Current RxAGC value
\Param  [out]  iLNAState = Current LNA state
\Param  [out]  iLNAGainWord = Current RTR LNA Gain word
\Param  [out]  iIntelliceiverState = Current Intelliceiver State
\Param  [out]  iJammerState = Current Jammer State

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_GET_RXAGC(HANDLE hResourceContext, unsigned char iDevice,
      short *iRxAGC, unsigned char *iLNAState,
      unsigned char *iLNAGainWord, unsigned char *iIntelliceiverState,
      unsigned char *iJammerState);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_GET_TXAGC - Query 1x TxAGC data

\Param  [in]   hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [out]  iAVGAIndex = Current Tx AVGA Index
\Param  [out]  iAVGAVal = Current Tx AVGA Value
\Param  [out]  iDVGAVal = Current Digital Beta prime value
\Param  [out]  iTxAGCdBm = Current Tx AGC in dBm * 100
\Param  [out]  iPAState = Current PA State
\Param  [out]  iAPTVal = Current APT value

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_GET_TXAGC(HANDLE hResourceContext, unsigned char iDevice,
      unsigned short *iAVGAIndex, unsigned long *iAVGAVal,
      short *iDVGAVal, long *iTxAGCdBm,
      unsigned char *iPAState, unsigned long *iAPTVal);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_SET_TX_POWER - Set 1x Tx Power

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iTxPowerMode = Tx Power Mode: Open Loop/Closed Loop
\Param  [in]       iTxPower = Tx Power value in dBm * 10
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_SET_TX_POWER(HANDLE hResourceContext, unsigned char iDevice,
      unsigned char iTxPowerMode, unsigned short iTxPower, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_POWER_MODE_OVERRIDE - Set 1x Rx Power Mode

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iRxPowerMode = Rx Power Mode
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_POWER_MODE_OVERRIDE(HANDLE hResourceContext, unsigned char iDevice,
      unsigned char iRxPowerMode, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_1X_RADIO_CLEAR_PM_OVERRIDE - Clear 1x Rx Power Mode

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_1X_RADIO_CLEAR_PM_OVERRIDE(HANDLE hResourceContext, unsigned char iDevice,
      int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_ENTER - Enter HDR mode of operation

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which HDR is to be entered
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_ENTER(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_EXIT - Exit HDR mode of operation

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which HDR is to be exited
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_EXIT(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_ENABLE - Enable radio for HDR mode of operation

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iBand = CDMA band for which radio is to be enabled
\Param  [in]       iChannel = CDMA channel for which radio is to be enabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_ENABLE(HANDLE hResourceContext, unsigned char iDevice,
                                        unsigned char iBand, unsigned short iChannel, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_DISABLE - Disable radio for HDR mode of operation

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which HDR is to be disabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_DISABLE(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_WAKEUP_RX - Enable HDR receiver

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Rx is to be enabled
\Param  [in]       iNumCarrier = Number of band and Channel
\Param  [in]       iband0 = RF band0 to tune the receiver
\Param  [in]       iChan0 = RF chan0 to tune the receiver
\Param  [in]       iIndex0 = Carrier Index for first band chan set
\Param  [in]       iband1 = RF band1 to tune the receiver
\Param  [in]       iChan1 = RF chan1 to tune the receiver
\Param  [in]       iIndex1 = Carrier Index for second band chan set
\Param  [in]       iband2 = RF band2 to tune the receiver
\Param  [in]       iChan2 = RF chan2 to tune the receiver
\Param  [in]       iIndex2 = Carrier Index for third band chan set
\Param  [in]       iAGCMode = HDR AGC Mode to be configured to
\Param  [in]       iRTCMode = RTC offset to be used for given AGC Mode
\Param  [in]       iPrevAGC = Previous AGC to be used for RESUME AGC
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_WAKEUP_RX(HANDLE hResourceContext, unsigned char iDevice,unsigned char iNumCarrier,
      unsigned char iband0, unsigned short iChan0, unsigned char iIndex0,
      unsigned char iband1, unsigned short iChan1, unsigned char iIndex1,
      unsigned char iband2, unsigned short iChan2, unsigned char iIndex2,
      unsigned char iAGCMode, unsigned long iRTCMode,unsigned short iPrevAGC, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_SLEEP_RX - Disable HDR receiver

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Rx is to be disabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_SLEEP_RX(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_WAKEUP_TX - Enable HDR transmitter

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Tx is to be enabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_WAKEUP_TX(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_SLEEP_TX - Disable HDR transmitter

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Tx is to be disabled
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_SLEEP_TX(HANDLE hResourceContext, unsigned char iDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_RETUNE - Retune HDR receiver and transmitter

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = RF Device on which Tx is enabled
\Param  [in]       iNumCarrier = Number of band and Channel
\Param  [in]       iband0 = RF band0 to tune the receiver
\Param  [in]       iChan0 = RF chan0 to tune the receiver
\Param  [in]       iIndex0 = Carrier Index for first band chan set
\Param  [in]       iband1 = RF band1 to tune the receiver
\Param  [in]       iChan1 = RF chan1 to tune the receiver
\Param  [in]       iIndex1 = Carrier Index for second band chan set
\Param  [in]       iband2 = RF band2 to tune the receiver
\Param  [in]       iChan2 = RF chan2 to tune the receiver
\Param  [in]       iIndex2 = Carrier Index for third band chan set
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_RETUNE(HANDLE hResourceContext, unsigned char iDevice, unsigned char iNumCarrier,
                                        unsigned char iband0, unsigned short iChan0, unsigned char iIndex0,
                                        unsigned char iband1, unsigned short iChan1, unsigned char iIndex1,
                                        unsigned char iband2, unsigned short iChan2, unsigned char iIndex2, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_ENABLE_DIV - Enable HDR receive diversity

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iMasterTxRxDevice = Master RxTx Device
\Param  [in]       iSlaveRxDevice = Slave Rx Device which is used for Rx Div
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_ENABLE_DIV(HANDLE hResourceContext, unsigned char iMasterTxRxDevice,
      unsigned char iSlaveRxDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_DISABLE_DIV - Disable HDR receive diversity

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iSlaveRxDevice = Slave Rx Device which is used for Rx Div
\Param  [out]      iStatus = Positive if RFM execution successful and negative if execution failed

\return true if successful, false if fail.   \return unsigned char

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_DISABLE_DIV(HANDLE hResourceContext, unsigned char iSlaveRxDevice, int *piStatus);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_GET_RXAGC - Query HDR RxAGC data

\Param  [in]   hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]   iDevice = Device for which RxAGC data is queried
\Param  [out]  iRxAGC0 = Current RxAGC value for Carrier Index 0 in dBm * 10
\Param  [out]  iRxAGC1 = Current RxAGC value for Carrier Index 1 in dBm * 10
\Param  [out]  iRxAGC2 = Current RxAGC value for Carrier Index 2 in dBm * 10
\Param  [out]  iRxAGCall = Cumulative RxAGC value in dBm * 10
\Param  [out]  iLNAState = Current LNA state
\Param  [out]  iLNAGainWord = Current RTR LNA Gain word
\Param  [out]  iIntelliceiverState = Current Intelliceiver State
\Param  [out]  iJammerState = Current Jammer State

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_GET_RXAGC(HANDLE hResourceContext, unsigned char iDevice,
      short *iRxAGC0, short *iRxAGC1, short *iRxAGC2, short *iRxAGCall,
      unsigned char *iLNAState, unsigned char *iLNAGainWord,
      unsigned char *iIntelliceiverState, unsigned char *iJammerState);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_GET_TXAGC - Query HDR TxAGC data

\Param  [in]   hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]   iDevice = Device for which TxAGC data is queried
\Param  [out]  iAVGAIndex = Current Tx AVGA Index
\Param  [out]  iAVGAVal = Current Tx AVGA Value
\Param  [out]  iDVGAVal = Current Digital Beta prime value
\Param  [out]  iTxAGCdBm = Current Tx AGC in dBm * 100
\Param  [out]  iPAState = Current PA State
\Param  [out]  iAPTVal = Current APT value

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_GET_TXAGC(HANDLE hResourceContext, unsigned char iDevice, unsigned short *iAVGAIndex,
      unsigned long *iAVGAVal, short *iDVGAVal, long *iTxAGCdBm,
      unsigned char *iPAState, unsigned long *iAPTVal);

/******************************************************************************/
/**

QLIB_FTM_HDR_RADIO_SET_TX_POWER - Set HDR Tx Power

\Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\Param  [in]       iDevice = Device for which Tx Power is being set
\Param  [in]       iTxPowerMode = Tx Power Mode: Open Loop/Closed Loop
\Param  [in]       iTxPower = TX_POWER value in dBm * 10
\Param  [out]      iStatus

\return true if successful, false if fail.

\warning
*******************************************************************************/
unsigned char QLIB_FTM_HDR_RADIO_SET_TX_POWER(HANDLE hResourceContext, unsigned char iDevice,
      unsigned char iTxPowerMode, unsigned short iTxPower, int *piStatus);
