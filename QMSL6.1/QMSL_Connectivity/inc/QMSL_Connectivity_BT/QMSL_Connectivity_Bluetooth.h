/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Connectivity/inc/QMSL_Connectivity_BT/QMSL_Connectivity_Bluetooth.h#13 $
 * $DateTime: 2016/06/21 22:25:47 $
 *
 *
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */

#if !defined(_QLIB_BLUETOOTH_H)
#define _QLIB_BLUETOOTH_H

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
                     Bluetooth FTM
   *******************************************************************************/

    /**  
   Configures the Bluetooth chip ID

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bluetoothChipID = set chip ID,
   bluetoothChipID = 0, for WCN2243 and WCN36xx
   bluetoothChipID = 3002, for AR3002 chipset
  
   \return true if successful, false if fail.

   \warning QLIB_FTM_SET_MODE( PHONE_MODE_BLUETOOTH ) must be called first

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_SET_CHIP_ID
   ( HANDLE hResourceContext, int bluetoothChipID);
    /******************************************************************************/ 
   /**  
   Configures the Bluetooth logging mode

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bluetoothLegacyLoggingEnable = if enabled uses legacy 0x117C log code,else uses Bluetooth log code 0x1366
   bluetoothLegacyLoggingEnable = 0, uses Bluetooth log code = 0x1366
   bluetoothLegacyLoggingEnable = 1, uses legacy FTM log code = 0x117C 
  
   \return true if successful, false if fail.

   \warning QLIB_FTM_SET_MODE( PHONE_MODE_BLUETOOTH ) must be called first

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_SET_LegacyLoggingMode
   ( HANDLE hResourceContext, int bluetoothLegacyLoggingEnable);

    /******************************************************************************/ 
   /**  
   Enables the Bluetooth HCI event logging mode for QRCT , logCode = 0x1366

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
    
   \return true if successful, false if fail.

   \warning QLIB_FTM_SET_MODE( PHONE_MODE_BLUETOOTH ) must be called first

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_EnableLogging
   ( HANDLE hResourceContext);

     /******************************************************************************/
   /**

   BT Commands:  QLIB_FTM_BT_GET_BD_ADDR

   Get the BD address.

   \param macAddr = pointer to 6 byte array to hold the BD address.

   \return true if successful, false if failure
  
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_GET_BD_ADDR
   (
      HANDLE hResourceContext,
      unsigned char *bdAddr
   );

   /******************************************************************************/
   /**

   BT Commands:  QLIB_FTM_BT_SET_BD_ADDR

   Set the BD address.

   \param macAddr = pointer to 6 byte array holding the desired BD address.

   \return true if successful, false if failure
  
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_SET_BD_ADDR
   (
      HANDLE hResourceContext,
      unsigned char* bdAddr
   );

   /******************************************************************************/
   /**
   Factory Test Mode Bluetooth Commands 1.2.1.1 User-specified HCI command

   Send a host controller interface (HCI) command to a device

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pBuffer = pointer to a series of bytes that will be sent as an HCI command.
   \param iLength = number of bytes to send, from pBuffer

   \return true if successful, false if fail.

   \warning QLIB_FTM_SET_MODE( PHONE_MODE_BLUETOOTH ) must be called first

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_HCI_USER_CMD
   ( HANDLE hResourceContext, unsigned char* pBuffer, unsigned char iLength);

   /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, custom command to activate Bluetooth mode

   Sends: 1) HCI Enable DUT, 2)HCI Write Scan Enable, 3) HCI Set Event Filter Conn 2

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param =pBuffer = pointer to a series of bytes that will be sent as an HCI command.
   \param iLength = number of bytes to send, from pBuffer

   \return true if successful, false if fail.

   \warning QLIB_FTM_SET_MODE( PHONE_MODE_BLUETOOTH ) must be called first

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_Enable_Bluetooth( HANDLE hResourceContext );

    /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, Write Scan Enable Command
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iScanEnableOption=                               
                              0x00 No Scans enabled. Default.
                              0x01 Inquiry Scan enabled,Page Scan disabled.
                              0x02 Inquiry Scan disabled,Page Scan enabled.
                              0x03 Inquiry Scan enabled,Page Scan enabled.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_WriteScanEnable(  HANDLE hResourceContext, unsigned char iScanEnableOption );

     /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, Set Event Filter
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iFilterType=                               
                              0x00 Clear All Filters
                              0x01 Inquiry result
                              0x02 Connection setup                        

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_SetEventFilter(  HANDLE hResourceContext, unsigned char iFilterType );

   /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, custom command turn on BT transmitter to a specific channel number

   The underlying HCI command is a vendor-specific command called BT_HCI_TX_CONTINUOUS_FREQ.
   This does not actually produce a CW signal, rather a a DH5 packet is transmitted every 6 slots.
   The result is a bursted signal.  It is apparently not possible to transmit just a CW signal
   using the available HCI commands.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChannel= channel number for Tx. (Tx frequency = 2402 + chan_num, in MHz)

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_SetCW(  HANDLE hResourceContext, unsigned char iChannel );

   /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, custom command turn on BT transmitter with a CW,
   to a specific channel number

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iAddr = 6 digit Bluetooth address.  This will temporarily load the BT address
                  into embedded RAM.  When modes are reset or the phone is restarted,
               the address will be gone.

                   The address will be transformed as follows:
               Input array: { 0x12, 0x90, 0x78, 0x56 0x34, 0x12 }

               Resulting BT address: 123456789012


   \return true if successful, false if fail.

   \warning If the NV_BD_ADDR_I NV item has a value then the NV address will always
            be used and the value specified in this command will be ignored.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_SetAddr(  HANDLE hResourceContext, unsigned char iAddr[6] );

   /******************************************************************************/
   /**

   This command issues a Bluetooth "Read_Local_Version_Information" HCI command to
   the Bluetooth module and then capture the resulting Bluetooth event log, which
   contains the Local_Version of the Bluetooth module.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param pBluetootHCI_Version = reference to the structure that will be filled in with the local version information.
                                 use the type Bluetooth_LocalVersion_struct, defined in QLIB_Defines.h

   \return true if successful, false if fail.

   \warning Will reset the log code and logging state



   *******************************************************************************/
   QLIB_API unsigned char QLIB_BT_GetModuleVersion( HANDLE hResourceContext, unsigned char* pBluetootHCI_Version  );

    /******************************************************************************/
   /**

   This command issues a enabled BT HCI event logging for 0x1366 log code       

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()   
   \param pBluetoothHCI_Logs
        1. First byte number of HCI logs
        2. Next byte = length of log payload, followed by payload bytes
          3. Step 2 continues till number of logs are not complete
    \param iNumberOfBytes
        Total number of received bytes

   \return true if successful, false if fail.
  

   \warning Will reset the log code and logging state

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_GetHCILogs( HANDLE hResourceContext, unsigned char* pBluetoothHCI_Logs , unsigned short* iNumberOfBytes);
   

   /******************************************************************************/
   /**

   This function sends BT HCI command and returns the first HCI event/response received

   Call QLIB_ConfigureTimeout( hResourceContext, QMSL_Timeout_BT_HCI_Response, TimeOut) to configure the timeout value for waiting for BT response

   See Test_FTM_BT() in QLibDemo.cpp on how to use this function

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pHCI_Buffer [in] = HCI command buffer

   \param iHCI_Length [in] = HCI command buffer length

   \param pBTResponseBuffer [in/out] = HCI response buffer

   \param iBTResponseLength [in/out] = [in] is the size of pBTResponseBuffer,
                              [out] is the length of valid data returned by pBTResponseBuffer, 0 means that there is no BT response

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_HCI_USER_CMD_WithEventResponse( HANDLE hResourceContext, unsigned char* pHCI_Buffer, unsigned short iHCI_Length, unsigned char* pBTResponseBuffer, unsigned short* iBTResponseLength );
   /******************************************************************************/
   /**

   This function sends BT HCI command and returns the first and second HCI event/response received

   Call QLIB_ConfigureTimeout( hResourceContext, QMSL_Timeout_BT_HCI_Response, TimeOut) to configure the timeout value for waiting for BT response

   See Test_FTM_BT() in QLibDemo.cpp on how to use this function

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pHCI_Buffer [in] = HCI command buffer

   \param iHCI_Length [in] = HCI command buffer length

   \param pBTResponseBuffer [in/out] = HCI response buffer

   \param iBTResponseLength [in/out] = [in] is the size of pBTResponseBuffer,
                              [out] is the length of valid data returned by pBTResponseBuffer, 0 means that there is no BT response

   \param pSecondBTResponseBuffer2 [in/out] = Second HCI response buffer

   \param iSecondBTResponseLength2 [in/out] = [in] is the size of pSecondBTResponseBuffer,
                              [out] is the length of valid data returned by pSecondBTResponseBuffer, 0 means that there is no BT response

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_HCI_USER_CMD_WithTwoEventResponse( HANDLE hResourceContext, unsigned char* pHCI_Buffer, unsigned short iHCI_Length, unsigned char* pBTResponseBuffer, unsigned short* iBTResponseLength, unsigned char* pSecondBTResponseBuffer2, unsigned short* iSecondBTResponseLength );

   /******************************************************************************/
   /**

   This function sends BT HCI command and returns the first and second HCI event/response received

   Call QLIB_ConfigureTimeout( hResourceContext, QMSL_Timeout_BT_HCI_Response, TimeOut) to configure the timeout value for waiting for BT response

   See Test_FTM_BT() in QLibDemo.cpp on how to use this function

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param pHCI_Buffer [in] = HCI command buffer

   \param iHCI_Length [in] = HCI command buffer length

   \param pBTResponseBuffer [in/out] = HCI response buffer

   \param iBTResponseLength [in/out] = [in] is the size of pBTResponseBuffer,
                              [out] is the length of valid data returned by pBTResponseBuffer, 0 means that there is no BT response

   \param pSecondBTResponseBuffer2 [in/out] = Second HCI response buffer

   \param iSecondBTResponseLength2 [in/out] = [in] is the size of pSecondBTResponseBuffer,
                              [out] is the length of valid data returned by pSecondBTResponseBuffer, 0 means that there is no BT response

   \param pThirdBTResponseBuffer3 [in/out] = Third HCI response buffer

   \param iThirdBTResponseLength3 [in/out] = [in] is the size of pThirdBTResponseBuffer,
                              [out] is the length of valid data returned by pThirdBTResponseBuffer, 0 means that there is no BT response


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_HCI_USER_CMD_WithThreeEventResponse( HANDLE hResourceContext, unsigned char* pHCI_Buffer, unsigned short iHCI_Length, unsigned char* pBTResponseBuffer, unsigned short* iBTResponseLength,unsigned char* pSecondBTResponseBuffer, unsigned short* iSecondBTResponseLength, unsigned char* pThirdBTResponseBuffer, unsigned short* iThirdBTResponseLength  );

   /******************************************************************************/
   /**

   This function disables the sleep feature of the BT device. Method should be called before calling QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_TXC_ONLY.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_DisableSleep(HANDLE hResourceContext);

   /******************************************************************************/
   /**

   This function will reset the BT controller.  This method should be utilized to stop the continouse Transmit of the device.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_HCI_Reset(HANDLE hResourceContext);

   /******************************************************************************/
   /**

   This method provides user to be able to poke 32 bit value into the memory.  The method sends the "EDL_POKE32_REQ" command.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param memAddress [in] = memory location where the data will be written

   \param datalength [in] = number of bytes taht need to be written. number of bytes must be multiple of 4 and must be >=  4.

   \param data [in] = data that is going to be written into the memory.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_EDL_POKE32_REQ(HANDLE hResourceContext, unsigned long memAddress, unsigned char datalength, unsigned char *data);

   /******************************************************************************/
   /**

   This method provides user to be able to poke 16 bit value into the memory.  The method sends the "EDL_POKE16_REQ" command.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param memAddress [in] = memory location where the data will be written

   \param datalength [in] = number of bytes taht need to be written. number of bytes must be multiple of 2 and must be >=  2.

   \param data [in] = data that is going to be written into the memory.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_EDL_POKE16_REQ(HANDLE hResourceContext, unsigned long memAddress, unsigned char datalength, unsigned char *data);


   /******************************************************************************/
   /**

   This method provides user to be able to poke 8 bit value into the memory.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param memAddress [in] = memory location where the data will be written

   \param datalength [in] = number of bytes taht need to be written.

   \param data [in] = data that is going to be written into the memory.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_EDL_POKE8_REQ(HANDLE hResourceContext, unsigned long memAddress, unsigned char datalength, unsigned char *data);




   /******************************************************************************/
   /**

   This method provides user to be able to peek 32 bit value into the memory.  The method sends the "EDL_PEEK32_REQ" command.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param memAddress [in] = memory location for reading the content of memory

   \param datalength [in] = number of bytes taht need to be read from the memory. Number of bytes must be multiple of 4 and must be >=  4.

   \param data [out] = data that is going to be read from the memory.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_EDL_PEEK32_REQ(HANDLE hResourceContext, unsigned long memAddress, unsigned char dataLengthToBeRead, unsigned char *data);



   /******************************************************************************/
   /**

   This method retrieves accumulated test statistics on received packets and the number of errors in the packets received during the testing.
   The method sends the "VS_PROD_TEST_SUBCOMMAND_TEST_STATS" command to gather the statistics.
   The method returns the unsigned char *, but BlueTooth_Prod_Test_Channel_Stat structure should be utilized while casting the parameteres.
   See section 2.5.1.3 of document 80-VE132-7.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param memAddress [in] = memory location for reading the content of memory

   \param datalength [in] = number of bytes taht need to be read from the memory. Number of bytes must be multiple of 4 and must be >=  4.

   \param channel1Stats [out] = statistics for channel 1

   \param channel2Stats [out] = statistics for channel 2

   \param channel3Stats [out] = statistics for channel 3

   \param channel4Stats [out] = statistics for channel 4

   \param channel5Stats [out] = statistics for channel 5

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_STATS(HANDLE hResourceContext,
         unsigned char *channel1Stats,
         unsigned char *channel2Stats,
         unsigned char *channel3Stats,
         unsigned char *channel4Stats,
         unsigned char *channel5Stats);

   /******************************************************************************/   
   /**

   This method retrieves accumulated test statistics for AR3002 chipset on received packets and
   the number of packets received with CRC errors during the testing.
   The method sends the "VS HCI_GET_PER" command to gather the statistics. Refer:80-Y0519-5
   The method returns the unsigned char *, but BlueTooth_Prod_Test_PER structure should be utilized while casting the parameteres.   
  
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param perStatistics [out] = PER statistics, total packets received and packets with CRC errors

   \param ipacketType [in] = defines the type of packet that will be transmitted. This parameter maps to BlueTooth_PacketType.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_HCI_GET_PER_AR3002(HANDLE hResourceContext,
         unsigned char *perStatistics,unsigned char ipacketType);


    /******************************************************************************/   
   /**

   This method retrieves the WiPower Register values.
   The method sends the "VS HCI_READ_WPR_REGISTER" command to Get the register values.
   Refer:Section 6 of 80-N2785-41  
  
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_BT_HCI_READ_WPR_REGISTER(HANDLE hResourceContext, 
       short* confReg,
       short* currReg,
       short* inteReg,
       short* impeReg);
   /******************************************************************************/   
  /**

   This method retrieves the WiPower Register values.
   The method sends the "VS HCI_READ_WPR_STARK_REGISTER" command to Get the register values.
   Refer:Section 6 of 80-N2785-41  
  
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_BT_HCI_READ_WPR_STARK_REGISTER(HANDLE hResourceContext, short* vthRegister, short* vclRegister, short* controlRegister, short* senseRegister);
   
   /******************************************************************************/   
   /**

   This method Writes the WiPower Register values.
   The method sends the "VS HCI_WRITE_WPR_REGISTER" command to Get the register values.
   Refer:Section 6 of 80-N2785-41  
  
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_BT_HCI_WRITE_WPR_REGISTER(HANDLE hResourceContext, char configByteValue, char  currentLimitValue, char  latchAlarms, char impedanceLimitValue);
   /******************************************************************************/   
   /**

   This method retrieves the WiPower Register values.
   The method sends the "VS HCI_WRITE_WPR_STARK_REGISTER" command to Get the register values.
   Refer:Section 6 of 80-N2785-41  
  
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_BT_HCI_WRITE_WPR_STARK_REGISTER(HANDLE hResourceContext, char vthRegister, char vclRegister, char controlRegister, char senseRegister);
   /******************************************************************************/   
   /**

   This method retrieves the WiPower STATUS Register value.
   The method sends the "VS HCI_READ_WPR_STATUS_REGISTER" command to Get the register values.
   Refer:Section 6 of 80-N2785-41  
  
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_BT_HCI_READ_WPR_STATUS_REGISTER(HANDLE hResourceContext, short* ocal, short* otal, short* comErl, short* oval, short* chgok);
   
   /******************************************************************************/ 
   /**

   This method measures and returns the RSSI for the specified channel.
  
   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param rssi [out] = averaged rssi value

   \param iChannelNumber [in] = the channel number for which rssi measurement  is requested

   \param noOfAverages [in][Optional] = Specify the number of averages for the rssi measurement 

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_HCI_GET_RSSI(HANDLE hResourceContext,
      short *rssi,unsigned char iChannelNumber, unsigned char noOfAverages = 255);

    /******************************************************************************/
   /**

   The method causes the device to transmit full Bluetooth packets while bursting, without
   being in a connection with another device.   The method accomplish this by sending the "VS_PROD_TEST_SUBCOMMAND_TEST_TX" command.
   See section 2.5.1.4 of document 80-VE132-7.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param hopChannels [in] = contains 5 channels the device hops over if limited hopping is available

   \param itransmitPattern [in] = defines the trasmit pattern.  this parameter maps to BlueTooth_TransmittPatternPayload.

   \param ipacketType [in] = defines the type of packet that will be transmitted. This parameter maps to BlueTooth_PacketType.

   \param idataWhiteningEnable [in] = TRUE will enable the whitening. FALSE will disable the whitening.

   \param itransitOutputPower [in] = determine the output power. It needs to be between 0-9.

   \param ireceiverHighGainEnable [in] = determine the receiver gain. TRUE enables high gain. FALSE enables low gain.

   \param itragetDeviceAddress [in] = 6 byte Master Bluetooth device address

   \param ipayloadLength [in] = payload length

   \param ilogicalTransportAddress [in] = logical transport address

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_TX(HANDLE hResourceContext,
         unsigned char ihopChannels[5],
         unsigned char itransmitPattern,
         unsigned char ipacketType,
         unsigned char idataWhiteningEnable,
         unsigned char itransitOutputPower,
         unsigned char ireceiverHighGainEnable,
         unsigned char itragetDeviceAddress[6],
         unsigned char ihoppingEnable,
         unsigned short ipayloadLength,
         unsigned char ilogicalTransportAddress);

    /******************************************************************************/
   /**

   The method causes the device to receive certain number of packets to test receiving rates of device transmitting in production
   test mode.  The method accomplish this by sending the "PROD_TEST_RX_BURST_CONFIG" command to the BT device.
   See document 80-VE132-7.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iNumberofPacketsToReceive = The packets number on which the Receiver test needs to receive

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_RX_BURST_CONFIG( HANDLE hResourceContext,
      unsigned short iNumberofPacketsToReceive);

   /******************************************************************************/
   /**

   The method causes the device to transmit full Bluetooth packets in list mode , without
   being in a connection with another device.   The method accomplish this by sending the "PROD_TEST_SEQ_TX" command.
   See document 80-Y2013-04.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iTxTestMode [in] = defines the trasmit pattern.

   \param iTxChannel [in] = defines the TX channel be transmitted.

   \param itransitOutputPower [in] = determine the output power. It needs to be between 0-9.

   \param itragetDeviceAddress [in] = 6 byte Master Bluetooth device address

   \param ilogicalTransportAddress [in] = logical transport address

   \param iNumberofPacketsForEachMode [in] = number of packets to use for each modulation type

   \param iNullPacketsEnable [in] = if null packets need to be sent before TX sequence

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_SEQ_TX(HANDLE hResourceContext,
         unsigned char iTxTestMode,
         unsigned char iTxChannel,
         unsigned char itragetDeviceAddress[6],
         unsigned char ilogicalTransportAddress,
       unsigned char itransitOutputPower,
       unsigned short iNumberofPacketsForEachMode,
         unsigned char iNullPacketsEnable);

    /******************************************************************************/
   /**

   The method causes the device to receive full Bluetooth packets in list mode , without
   being in a connection with another device.   The method accomplish this by sending the "PROD_TEST_SEQ_RX" command.
   See document 80-Y2013-04.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRxTestMode [in] = defines the receive pattern.

   \param iRxChannel [in] = defines the RX channel be received.

   \param itragetDeviceAddress [in] = 6 byte Master Bluetooth device address

   \param ilogicalTransportAddress [in] = logical transport address

   \param iNumberofRotation [in] = number of rotation to use for sequence

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_SEQ_RX(HANDLE hResourceContext,
         unsigned char iRxChannel,
         unsigned char itragetDeviceAddress[6],
         unsigned char ilogicalTransportAddress,
       unsigned short iNumberofRotation);

    /******************************************************************************/
   /**

   This method retrieves accumulated test statistics on received packets and the number of errors in the packets received during the testing.
   The method sends the "VS_PROD_TEST_SUBCOMMAND_TEST_SEQ_RX_STATUS" command to gather the statistics.
   The method returns the unsigned char *, but BlueTooth_Prod_Test_Channel_Stat structure should be utilized while casting the parameteres.
   See document 80-Y2013-04.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param DH1Stats [out] = statistics for DH1

   \param DH5Stats [out] = statistics for DH5

   \param twoDH5Stats [out] = statistics for 2DH5

   \param threeDH5Stats [out] = statistics for 3DH5

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_SEQ_RX_STATUS(HANDLE hResourceContext,
         unsigned char *DH1Stats,
         unsigned char *DH5Stats,
         unsigned char *twoDH5Stats,
         unsigned char *threeDH5Stats,
       unsigned char *leStats);

   /******************************************************************************/   
   /**

   The method sets the device into slave mode.  The device then specified frequency for the presence of a master device.
   Once the master device is found, the two devices transmit data.
   The method accomplish this by sending the "VS_PROD_TEST_SUBCOMMAND_TEST_SLAVE" command.
   See section 2.5.1.1 of document 80-VE132-7.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param hopChannels [in] = contains 5 channels the device hops over if limited hopping is available

   \param itransmitPattern [in] = defines the trasmit pattern.  this parameter maps to BlueTooth_TransmittPatternPayload.

   \param ipacketType [in] = defines the type of packet that will be transmitted. This parameter maps to BlueTooth_PacketType.

   \param idataWhiteningEnable [in] = TRUE will enable the whitening. FALSE will disable the whitening.

   \param itransitOutputPower [in] = determine the output power. It needs to be between 0-9.

   \param ireceiverHighGainEnable [in] = determine the receiver gain. TRUE enables high gain. FALSE enables low gain.

   \param itragetDeviceAddress [in] = 6 byte Master Bluetooth device address

   \param ipayloadLength [in] = payload length

   \param ilogicalTransportAddress [in] = logical transport address

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_SLAVE(HANDLE hResourceContext,
         unsigned char  ihopChannels[5],
         unsigned char  itransmitPattern,
         unsigned char  ipacketType,
         unsigned char  idataWhiteningEnable,
         unsigned char  itransitOutputPower,
         unsigned char  ireceiverHighGainEnable,
         unsigned char  itragetDeviceAddress[6],
         unsigned char  ihoppingEnable,
         unsigned short ipayloadLength,
         unsigned char  ilogicalTransportAddress);

   /******************************************************************************/
   /**

   The method causes the device to transmit continuously on the specified channel.
   The method accomplish this by sending the "VS_PROD_TEST_SUBCOMMAND_TEST_TXC_ONLY" command to the BT device.
   See section 2.5.1.5 of document 80-VE132-7.

   Note:
      In order to support 4020/4021/4025 and Marimba devices, following algorithm is been used.
         Method gets the unit app version by looking at the PF values (as per Bill Chens request).
         It is done by looking at the 4 bytes starting at 0x29 location of the event that was sent back.

         if power level less than or equal to 7 send the command as normal.  If the unit is 4025 then send a series of poke8 commands provided by the apps team.
         if power level is either 8 or 9 then take actions as described below.
            If unit 4025 send the Tx packet with Power level '7' in it and then send series of poke8 commands provided by Apps team.
            If unit is either 4020 / 4021 / 4000 then power level is set back to 7 and command is sent to the unit. (no Poke commands are sent)
            if some other unit is found (e.g .. Marimba), command is sent as is where the unit is expected to support power 8 and 9.



   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param ichannel [in] = device transmit channel

   \param itransmitOutputPower [in] = determine the output power. It needs to be between 0-9.

   \param itransmitType [in] = defines the trasmit type.  this parameter maps to BlueTooth_TransmitType.

   \param ipatternLength [in] = specifies the length of the repeated pattern

   \param ibitPattern [in] = bit pattern transmitted repeatdly

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_TXC_ONLY( HANDLE hResourceContext,
         unsigned char ichannel,
         unsigned char itransmitOutputPower,
         unsigned char itransmitType,
         unsigned char ipatternLength,
         unsigned long ibitPattern);

   /******************************************************************************/
    /**

   The method causes the device to transmit continuously on the specified channel and power level for AR3002 chipset.  

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param ichannel [in] = device transmit channel  (0-78)

   \param ichannel [in] = device power level (0-7)  

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_TXC_AR3002( HANDLE hResourceContext,
         unsigned char ichannel,unsigned char iPowerLevel);

   /******************************************************************************/
   
   /**

   The method causes the device to receive continuously on the specified channel to test receiving rates of device transmitting in production
   test mode.  The method accomplish this by sending the "VS_PROD_TEST_SUBCOMMAND_TEST_RX_ONLY" command to the BT device.
   See section 2.5.1.6 of document 80-VE132-7.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param hopChannels [in] = contains 5 channels the device hops over if limited hopping is available

   \param itransmitPattern [in] = defines the trasmit pattern.  this parameter maps to BlueTooth_TransmittPatternPayload.

   \param ipacketType [in] = defines the type of packet that will be transmitted. This parameter maps to BlueTooth_PacketType.

   \param idataWhiteningEnable [in] = TRUE will enable the whitening. FALSE will disable the whitening.

   \param itransitOutputPower [in] = determine the output power. It needs to be between 0-9.

   \param ireceiverHighGainEnable [in] = determine the receiver gain. TRUE enables high gain. FALSE enables low gain.

   \param itragetDeviceAddress [in] = 6 byte Master Bluetooth device address

   \param ipayloadLength [in] = payload length

   \param ilogicalTransportAddress [in] = logical transport address

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_RX_ONLY( HANDLE hResourceContext,
         unsigned char ihopChannels[5],
         unsigned char itransmitPattern,
         unsigned char ipacketType,
         unsigned char idataWhiteningEnable,
         unsigned char itransitOutputPower,
         unsigned char ireceiverHighGainEnable,
         unsigned char itragetDeviceAddress[6],
         unsigned char ihoppingEnable,
         unsigned short ipayloadLength,
         unsigned char ilogicalTransportAddress);
   /******************************************************************************/
   /**

   This function will start the BT LE Receiver test.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTestFrequency = The test frequency on which the Receiver test needs to be run

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_LE_HCI_Receiver_Test(HANDLE hResourceContext,
         unsigned char iTestFrequency);

   /******************************************************************************/
   /**

   This function will start the BT LE Transmitter test.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTestFrequency [in] = The test frequency on which the Transmitter test needs to be run
   \param iTestPayloadLength [in] = The length of data for the tx test
   \param iTestPayload [in] = The pattern of the payload
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_LE_HCI_Transmitter_Test(HANDLE hResourceContext,
         unsigned char iTestFrequency,
         unsigned char iTestPayloadLength,
         unsigned char iTestPayload);

   /******************************************************************************/
   /**

   This function will end the BT LE Test running.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_LE_HCI_Test_End(HANDLE hResourceContext,
         unsigned short* noOfPackets);

   /******************************************************************************/
   /**

   This function will end the BT GET PIN Connectivity command.

   \param BTResponse [out] 
   \param WLANResponse [out] 
   \param FMResponse [out] 
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_Get_PIN_CONNECTIVITIY(HANDLE hResourceContext,unsigned short* BTResponse,
      unsigned short* WLANResponse, unsigned short* FMResponse);

    /******************************************************************************/
   /**

   This function will end the BT Tx Continous Test running.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_PROD_TEST_SUBCOMMAND_TEST_STOP(HANDLE hResourceContext);

   /******************************************************************************/
   /**

   This function will write the BT SSBI value

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sAddress [in] = The address of the value to write in
   \param lValue [in] = The value to write in 
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_BT_SSBI_POKE(HANDLE phoneHandle, unsigned short sAddress, unsigned long lValue);

    /******************************************************************************/
   /**

   This function will read the BT SSBI value

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sAddress [in] = The address of the value to read
   \param lValue [out] = The value that reads 
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_SSBI_PEEK(HANDLE phoneHandle, unsigned short sAddress, unsigned char* lValue);

   QLIB_API unsigned char QLIB_FTM_BT_HCI_OTP_DUMP(HANDLE phoneHandle, unsigned char cPSType, unsigned short sOffset, unsigned char cDataLength, unsigned char* lValue);

   QLIB_API unsigned char QLIB_FTM_BT_HCI_EDL_DNLOAD_REQ(HANDLE phoneHandle, unsigned long sAddress, unsigned short sOffset, unsigned char dataLength, unsigned char* lValue);

   QLIB_API unsigned char QLIB_FTM_BT_HCI_EDL_TOPCFG_BURN_REQ(HANDLE phoneHandle, unsigned short sAddress, unsigned short sLength, unsigned short sEnable, unsigned short sOTPOffset);


   /******************************************************************************/
   /**

   This function will detach and erase the BT patch and NVM in the serial flash.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning For USB standalone devices, the driver will automatically download NVM 
            and patch to the serial flash during re-enumeration.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_HCI_SFLASH_DETACH_ERASE(HANDLE hResourceContext);

   /******************************************************************************/
   /**

   This function will send a Bluetooth "GET_FLASH_BURNING_STATUS" HCI command to
   the Bluetooth module and then capture the resulting Bluetooth event log, which
   contains the burn status of the serial flash.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param patchStatus [out] = Patch burn status
   \param nvmStatus [out] = NVM burn status
   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_HCI_SFLASH_GET_BURN_STATUS(HANDLE hResourceContext, unsigned char* patchStatus, unsigned char* nvmStatus);


   /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, CSR8811 Set TX Power level Command

     \param iTxPowerLevel= TX Power level in dB                        

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_CSR8811_SetTxPower(  HANDLE hResourceContext, unsigned char iTxPowerLevel );

      /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, CSR8811 Send Warm Reset Command                   

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_CSR8811_WarmReset(  HANDLE hResourceContext );

    /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, CSR8811 Set Packet Type Command

   \param iPacketType= Packet Type
   \param iPayloadLength = payload length

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_CSR8811_SetPacketType(  HANDLE hResourceContext, unsigned short iPacketType , unsigned short iPayloadLength);

   /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, CSR8811 Send Pause Command                   

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_CSR8811_Pause(  HANDLE hResourceContext );
   /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, CSR8811 Config XTAL FTrim Command

   \param iXtalFtrim= xtal ftrim value  
  
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_CSR8811_ConfigXtalFTrim(  HANDLE hResourceContext, unsigned short iXtalFTrim);

    /******************************************************************************/
   /**
   Factory Test Mode Bluetooth, CSR8811 CSR8811_Tx_Data_ON Command

   \param Freq= freq in MHz
   \param iPayloadType = modulation type
   \param packetType = BR or EDR
  
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_BT_CSR8811_Tx_Data_ON(  HANDLE hResourceContext, unsigned short iTxFreq, unsigned char iPayloadType, unsigned char packetType );

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_BLUETOOTH_H)
