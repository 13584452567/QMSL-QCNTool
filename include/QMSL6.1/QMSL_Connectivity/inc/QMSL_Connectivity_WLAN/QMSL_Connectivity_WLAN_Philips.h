/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Connectivity/inc/QMSL_Connectivity_WLAN/QMSL_Connectivity_WLAN_Philips.h#6 $
 * $DateTime: 2016/04/04 17:51:51 $
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

#if !defined(_QLIB_WLAN_PHILIPS_H)
#define _QLIB_WLAN_PHILIPS_H

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
                     WLAN FTM

     NOTE: Please check the module manfucturer's documentation for specific information
           about the commands or parameters.  The documentation for the module-specific
         commands is based sources and Qualcomm can give very little support about
         individual commands and they can also not add new commands unless the
         module vendor writes the corresponding firmware and provides the command
         specification.

   *******************************************************************************/
   /******************************************************************************/
   /**

   WLAN FTM, Set the WLAN module type

   Set the WLAN module type, to be used for all QMSL WLAN FTM functions except for
   QLIB_FTM_WLAN_USER_CMD().

   If this funciton is not called, then the default type is FTM_WLAN_ModuleType_Philips.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param eModuletype =
         Defined by FTM_WLAN_ModuleTypeEnum:
         \code
         FTM_WLAN_ModuleType_Philips   = 0x00,   //!< Philips WLAN module
         FTM_WLAN_ModuleType_Atheros   = 0x01,   //!< Atheros WLAN module
         \endcode
      \param iRequestSize = Number of bytes to be sent in the request packet.
      \param piRequestBytes = Pointer to a buffer of request packet contents.
      \param piResponseSize = Pointer to number of bytes received in the response packet
                        NOTE: when calling this function, the value must be equal to the
                        maximum size of the receive buffer.  When the function returns, the
                        value will be the actual number of bytes filled into the receive buffer.
      \param iResponseBytes = Pointer to a buffer to store the response packet contents.

   \return Returns true if the command was dispatched successfully through the FTM.

   \warning This function only sets QMSL's mode.  The phone must also have a certain
            NV item written to indicate whether the phone things the module is
          Atheros or Philips.  The NV item number is 4202. A value of 0 indicates
          Philips and a value of 1 indicates Atheros.


         These files come from the wlan folder in the bulid and must be put into the
         phone's EFS folder /brew

            AMSS folder: wlan\oem\phg_80211g\libs

         Finally, in the phone's EFS, you must delete file /brew/mod/netlist

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_SetModuleType
   (
      HANDLE hResourceContext,
      unsigned long eModuleType
   );


   /******************************************************************************/
   /**

   WLAN FTM ICD, 2.1 FTM_WLAN_DISPATCH

   Sends a request/response packet to a WLAN module.  The command packets are defined
   by the individual module vendors (e.g. Philips/Atheros).

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iRequestSize = Number of bytes to be sent in the request packet.
      \param piRequestBytes = Pointer to a buffer of request packet contents.
      \param piResponseSize = Pointer to number of bytes received in the response packet
                        NOTE: when calling this function, the value must be equal to the
                        maximum size of the receive buffer.  When the function returns, the
                        value will be the actual number of bytes filled into the receive buffer.
      \param iResponseBytes = Pointer to a buffer to store the response packet contents.

   \return Returns true if the command was dispatched successfully through the FTM.
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_USER_CMD
   (
      HANDLE hResourceContext,
      unsigned short iRequestSize,
      unsigned char* piRequestBytes,
      unsigned short* piResponseSize,
      unsigned char* piResponseBytes
   );


   /******************************************************************************/
   /**

   Philips WLAN command, START

      This message is defined in [8] but not defined or implemented in the BGW200
      implementation.

      To avoid any confusion the message is defined and implemented for BGW211.
      The target always returns PCTI_SUCCESS. The same message is used as CONNECT_DUT.

      Request and confirm have no parameters. In case of SPI and UART the status is always
      PCTI_SUCCESS.

   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_START
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode
   );


   /******************************************************************************/
   /**

   Philips WLAN command, STOP

      On reception of the STOP message the target cancels the currently performed test. The confirm
   message is sent when this has been finished. If no test is running the target immediately returns
   with success.

   The STOP request message has no parameters. The confirm message has no other parameters
   than the mandatory status code.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \return true if successful, false if failure
   \warning FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_STOP
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode
   );

   /******************************************************************************/
   /**

   Philips WLAN command, TX_CONTINUOUS

      On TX_CONTINUOUS message the target configures the system to continuously
      transmit a single sine wave. The offset frequency of this message is configured
      with the FreqOffs parameter. The confirm message is sent directly after the
      target has initiated the sine wave.

      The transmission stops on the STOP message. In case another test is already
      performing (e.g.TX_BURST), the target wont do anything and confirm with
      the PCTI_FAILURE.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param iChannelNo  = specifies the channel used for Tx. (1-14)
   \param iAntenna    = Antenna to be used for tx (1, 2).
   \param iRates      = Rate of transmission (IGNORED)
   \param iMode       = Data mode (IGNORED)
   \param iTxGain     = 0x00-0x0F are used for BGW200. Since this setting cannot be properly
                         mapped to BGW211, PCTI returns PCTI_FAILURE for all values except
                         for 0x10. With 0x10 the target takes the current values that can be
                         configured with TX_POWER_CONTROL (see 3.2.4)

   \param iSignalType = Offset frequency relative to the carrier, defined by FTM_WLAN_Philips_enSignalType
      \code
           FTM_WLAN_Philips_SINGLETONE_100KHZ    = 1,
           FTM_WLAN_Philips_SINGLETONE_3MHZ      = 2,
           FTM_WLAN_Philips_SINGLETONE_5d5MHZ    = 3,
           FTM_WLAN_Philips_DUALTONE_100_300KHZ  = 4,
           FTM_WLAN_Philips_DUALTONE_3_3d1MHZ    = 5,
           FTM_WLAN_Philips_DUALTONE_5d5_5d6MHZ  = 6,
           FTM_WLAN_Philips_QPSK_0_1_SEQUENCE    = 7,
           FTM_WLAN_Philips_QPSK_PN_SEQUENCE     = 8

      \endcode
   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_TX_CONTINUOUS
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char iChannelNo,
      unsigned char iAntenna,
      unsigned short iRates,
      unsigned char iMode,
      unsigned char iTxGain,
      unsigned short iSignalType
   );

   /******************************************************************************/
   /**

   Philips WLAN command, TX_BURST

      On TX_BURST the target initiates the transmission of valid WLAN broadcast frames.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param    iChannelNo       = This field specifies the channel used for Tx.
   \param    iAntenna        = Antenna to be used for tx
   \param    iRates           = Rate of transmission, defined by FTM_WLAN_Philips_enDataRate
      \code
          // 11b rates backwards compatible with washington
          FTM_WLAN_Philips_RATE_1_MBPS   = 0x0,
          FTM_WLAN_Philips_RATE_2_MBPS   = 0x1,
          FTM_WLAN_Philips_RATE_5_MBPS   = 0x2,
          FTM_WLAN_Philips_RATE_11_MBPS   = 0x3,
          // plcp rate codes used for OFDM rates
          FTM_WLAN_Philips_RATE_6_MBPS   = 11,
          FTM_WLAN_Philips_RATE_9_MBPS   = 15,
          FTM_WLAN_Philips_RATE_12_MBPS   = 10,
          FTM_WLAN_Philips_RATE_18_MBPS   = 14,
          FTM_WLAN_Philips_RATE_24_MBPS   = 9,
          FTM_WLAN_Philips_RATE_36_MBPS   = 13,
          FTM_WLAN_Philips_RATE_48_MBPS   = 8,
          FTM_WLAN_Philips_RATE_54_MBPS   = 12

      \endcode
   \param    bPreamble        = 0 = short,
                              1 = long preamble Only valid for 11b rates, in case of 1Mbps only long preamble is
                               allowed. For short preamble, PCTI returns PCTI_STATUS_FAILURE

   \param    iPacketLength    = Tx packet length to be used.
                        Number of bytes payload (frame body). The maximum length supported for the
                        frame body is 1500 bytes. The length of the frame on the air is
                        therefore Packet Length + 28 bytes (MAC header + FCS)
   \param    iPacketInterval  = Tx packet interframe time, units of microseconds
   \param    iNumberOfPackets = # of Tx packets to be used, 0 = infinite

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_TX_BURST
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char iChannelNo,
      unsigned char iAntenna,
      unsigned char iRates,
      unsigned char bPreamble,
      unsigned short iPacketLength,
      unsigned short iPacketInterval,
      unsigned long iNumberOfPackets
   );

   /******************************************************************************/
   /**

   Philips WLAN command, TX_POWER_CONTROL

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param iTxBB = Global linear baseband scaling factor, the default value is 16384.
                The scaling factor to get a target baseband backoff can be calculated
                using the Scaling Equation. The maximum allowed value of 32767 leads to a backoff
                of 3dB. Useful backoff values are between 3dB and 30dB.

   \param iTxLF  = LF attenuator setting in the RF IC (0 - 15dB)
   \param iTxRF  = RF attenuator setting in the RF IC (0 - 15dB)

     Scaling Equation: S = 10 ^[  (B - 3dB)/20 ] * 32768

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_TX_POWER_CONTROL
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned short iTxBB,
      unsigned char iTxLF,
      unsigned char iTxRF
   );

   /******************************************************************************/
   /**

   Philips WLAN command, RX_CONTINUOUS

      On RX_CONTINUOUS the target goes into receive mode. While it is in the receive mode it
      updates the internal RX statistics. All statistics are reset internally before the RX_CONTINUOUS
      mode is started.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param iChannelNo = This field specifies the channel used for Tx.
   \param iAntenna = Antenna to be used for tx

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_RX_CONTINUOUS
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char iChannelNo,
      unsigned char iAntenna
   );

   /******************************************************************************/
   /**

   Philips WLAN command, GET_MAC_ADDRESS

      The target reads the burned-in MAC address from the EEPROM and returns the address with the
      confirm message. This should never fail. In case the MAC_ADDRESS is not configured it returns
      0x424242424242.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param aiMAC_Address = Buffer to store MAC address, size is defined by FTM_WLAN_MAC_ADRESS_SIZE

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_GET_MAC_ADDRESS
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char aiMAC_Address[6]
   );

   /******************************************************************************/
   /**

   Philips WLAN command, SET_MAC_ADDRESS

      If there is no MAC_ADDRESS in the EEPROM, SET_MAC_ADDRESS appends a new
      information element containing the given address to the customer section of the EEPROM.
      If there is already a MAC_ADDRESS in the EEPROM, SET_MAC_ADDRESS replaces the old
      one with the given new one.

      If there is no valid VERSION field in the EEPROM, SET_MAC_ADDRESS appends a new
      VERSION information element containing the main version number associated with the firmware.
      This specification is valid for PCTI v1.36 or higher.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param aiMAC_Address = Buffer containing MAC address to be programmed.
                          Size is defined by FTM_WLAN_MAC_ADRESS_SIZE

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_SET_MAC_ADDRESS
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char aiMAC_Address[6]
   );

   /******************************************************************************/
   /**

   Philips WLAN command, SET_MODULE

      The SET_MODULE message is used to indicate to the target what kind of module it is working
      on. This may affect some internal settings. Currently there is only BGW211 defined for SA5253
      based modules.

      On the SET_MODULE message the target returns PCTI_SUCCESS in the case that the module
      type is BGW211. For all other values it returns PCTI_NOT_SUPPORTED.

      The SET_MODULE request message carries a single byte indicating the module type.
      PCTI currently only supports the BGW211 module. The confirm message only contains the
      status.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param iModule = Module id, defined by FTM_WLAN_Philips_enModuleType
      \code
          // Washington modules (not supported)
          FTM_WLAN_Philips_M1      = 0x00,
          FTM_WLAN_Philips_M2      = 0x01,
          FTM_WLAN_Philips_M3      = 0x02,
          FTM_WLAN_Philips_M4      = 0x03,
          FTM_WLAN_Philips_MWAmax   = 0x0F,

          // Georgia modules
          FTM_WLAN_Philips_M_BGW211   = 0x10

      \endcode

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_SET_MODULE
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char iModule
   );

   /******************************************************************************/
   /**

   Philips WLAN command, GET_HWSW_VERSIONS

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param piSwVer       = Major version in upper byte, minor version in lower byte
   \param piHwBBChipVer = Baseband IC version
   \param piHwRFChipVer = RF Chip version
   \param iEEPROMVerFirmware = Version expected and written by the firmware
   \param iEEPROMVerManufacture = Version found in the manufacturer section of the EEPROM
   \param iEEPROMVerCustomer = Version found in the customer section of the EEPROM

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_GET_HWSW_VERSIONS
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned short* piSwVer,
      unsigned short* piHwBBChipVer,
      unsigned short* piHwRFChipVer,
      unsigned short*   piEEPROMVerFirmware,
      unsigned short*   piEEPROMVerManufacture,
      unsigned short* piEEPROMVerCustomer
   );

   /******************************************************************************/
   /**

   Philips WLAN command, TX_POWER_SET_CALIBRATED

      On TX_POWER_SET_CALIBRATED the target uses the calibration data as stored in the internal
      EEPROM to set the TX output power at the antenna to the value requested in the message.

      In the case that no valid calibration data is stored in the EEPROM the target returns
      PCTI_FAILURE.

      The request message carries a single signed byte for the targeted output power in dBm. The full
      range is valid. If the specified power is larger than the calibrated power, the latter will be used. If
      the specified power is lower than the minimum possible power, which is at least 20 dB below the
      calibrated power, the minimum power will be used.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param iPower_dBm = Tx power in dBm
   \param iAddress = Address returned from confirm message body

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_TX_POWER_SET_CALIBRATED
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char iPower_dBm,
      unsigned long* piAddress
   );

   /******************************************************************************/
   /**

   Philips WLAN command, READ_STATISTICS (partial)

      Parses enough of the READ_STATISTICS result to return the RSSI
      levels.  Use the QLIB_FTM_WLAN_Philips_READ_STATISTICS_Partial() command
      to return the entire READ_STATISTICS structure.

      On READ_STATISTICS the target collects the internal counter in a structure
      and returns it with the confirm message and status PCTI_SUCCESS.

      Only a few of the available parameters are returned through the C interface.

      If the full packet response is desired, then the user command should be called.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param piNumRxFrames     - CRCOKA1
   \param piNumRxBytesOk    - CumulatedNumRx - BytesCRCOKA1
   \param piRSSI_OK         - BBRSSICumulated - AllRxCRCOKA1
   \param piRSSI_NOK        - BBRSSICumulated - AllRxCRCErrorA1
   \param piNumRxFrames_ant2     - CRCOKA2
   \param piNumRxBytesOk_ant2    - CumulatedNumRx - BytesCRCOKA2
   \param piRSSI_OK_ant2         - BBRSSICumulated - AllRxCRCOKA2
   \param piRSSI_NOK_ant2        - BBRSSICumulated - AllRxCRCErrorA2



   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_READ_STATISTICS_Partial
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned long* piNumRxFrames_ant1,
      unsigned long* piNumRxBytesOk_ant1,
      unsigned long* piRSSI_OK_ant1,
      unsigned long* piRSSI_NOK_ant1,
      unsigned long* piNumRxFrames_ant2,
      unsigned long* piNumRxBytesOk_ant2,
      unsigned long* piRSSI_OK_ant2,
      unsigned long* piRSSI_NOK_ant2
   );

   /******************************************************************************/
   /**

   Philips WLAN command, READ_STATISTICS (full)

      Reads the entire READ_STATISTICS result and copies it into a user defined
      buffer.  The parsing must be done by the user.

      To get RSSI only fields, use QLIB_FTM_WLAN_Philips_READ_STATISTICS_Partial()

      On READ_STATISTICS the target collects the internal counter in a structure
      and returns it with the confirm message and status PCTI_SUCCESS.

      Only a few of the available parameters are returned through the C interface.
      This is done to focus on the Antenna 1 receiver level measurements.

      If the full packet response is desired, then the user command should be called.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param pReadStatisticsUserBuffer - pointer to 128 bytes, into which the READ_STATISTICS
         structure will be copied.  Size of buffer is defined by
         FTM_WLAN_Philips_PCTI_READ_STATISTICS_RESPONSE_SIZE


   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_READ_STATISTICS_Full
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      void* pReadStatisticsUserBuffer
   );


   /******************************************************************************/
   /**

   Philips WLAN command, RESET_STATISTICS

      Reset the statistics reutrued by READ_STATISTICS

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_RESET_STATISTICS(
      HANDLE hResourceContext,
      unsigned char* piStatusCode
   );

   /******************************************************************************/
   /**

   Philips WLAN command, SLEEP_MODE

      Used to initiate Sleep Mode Setting for Power Save. The parameters specify
      modes like Sleep between beacons, sleep between DTIM beacons or wake after a
      specified time. Power save during IBSS is also specifiable.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param char iMode, defined by FTM_WLAN_Philips_enSleepMode
     \code

        FTM_WLAN_Philips_PCTI_SLEEP_DOWN = 0x0,
      0 = Go to sleep and awake with the next message from the host. Similar to
         SLEEP. Wake-up will not work over UART. The confirm is sent from the
         target after and of sleep. That means, in case of UART, never, in case of SPI
         before the command that woke up the target is processed.

        FTM_WLAN_Philips_PCTI_TIMED_SLEEP = 0x1
      1 = Go to sleep and wake up after a defined time. The request is confirmed after
         wake-up or directly in case of an error.
     \endcode
   \param iSleepTime_ms = sleep time in ms, when iMode = 1
   \param iReserved = reserved


   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_SLEEP_MODE
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char iMode,
      unsigned long iSleepTime_ms,
      unsigned char iReserved
   );


   /******************************************************************************/
   /**

   Philips WLAN command, LOOPBACK_MODE

      The LOOPBACK_MODE message enables a loopback behind the modem. Frames received
      from the air are completely decoded including error correction and sent back to the air with the
      same data rate after a programmable amount of time.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param    iChannel = Channel to operate on
   \param  iIfs     = Time in s between end of the received frame and start of the transmission,
                      Units are ms

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_LOOPBACK_MODE
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char iChannel,
      unsigned long iIfs
   );

   /******************************************************************************/
   /**

   Philips WLAN command, DEBUG_LEVEL

      The DEBUG_LEVEL messages configures the amount of debug messages sent over the UART
      interface. This may help customers to provide detailed information in case of problems. The
      message carries a bitmask where different kinds of debug messages can be separately
      configured. The debug output is enabled if the associated bit is set to 1. Per default (at startup),
      debug outputs are disabled.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param    iBitmask = Channel to operate on
     \code
       Bit 0 PCTI command handler verbose, show only PCTI command related prints
       Bit 1 Global verbose, show all prints
       Bitmask
       Bit 2-15 Reserved (unused)
     \endcode

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_DEBUG_LEVEL
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char iBitmask
   );

   /******************************************************************************/
   /**

   Philips WLAN command, CHECK_EXT_32KHZ_CLOCK

      Returns the status of the 32kHz clock

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = return status code, defined by FTM_WLAN_Philips_enPctiStatus
   \param    iStatus =
      \code
         0 = External clock is not available / running
         1 = External clock is available / running
      \endcode

   \param  piClockStatus, output,
      \code
         0 = External clock is not available / running
         1 = External clock is available / running
      \endcode


   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_CHECK_EXT_32KHZ_CLOCK
   (
      HANDLE hResourceContext,
      unsigned char* piStatusCode,
      unsigned char* piClockStatus
   );

   /******************************************************************************/
   /**

   Philips WLAN command to get the status value of the last QLIB_FTM_WLAN_Philips()
   function that was called. This is needed for QRCT because QRCT will not update
   the output status value in the case of a failure.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStatusCode = returns the status code of the last Philips WLAN function,
                         defined by FTM_WLAN_Philips_enPctiStatus

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Philips_GetLastStatus
   (
      HANDLE hResourceContext,
      unsigned char* piLastStatusCode
   );



   /*
    Notes on testing WLAN commands (May 22, 2006)
      QLIB_FTM_WLAN_Philips_SLEEP_MODE
      -   mode=SLEEP_DOWN fails, the phone does not send a response packet.
          This is probably because the module has gone to sleep and is not communicating with the ARM

      -   mode=SLEEP_TIMED, fails with Philips status code = 1


      QLIB_FTM_WLAN_Philips_LOOPBACK_MODE
      - Cannot be called after other Tx functions, like QLIB_FTM_WLAN_Philips_TX_CONTINUOUS

      QLIB_FTM_WLAN_Philips_RX_CONTINUOUS
      -   Cannot be called after other Tx functions, like QLIB_FTM_WLAN_Philips_TX_CONTINUOUS
          and  QLIB_FTM_WLAN_Philips_LOOPBACK_MODE


      QLIB_FTM_WLAN_Philips_TX_BURST
      -   Problem with rate=0 (1_MBPS), reported status is value 1 instead of 0

      QLIB_FTM_WLAN_Philips_READ_STATISTICS_Partial
      -   Not sure if this function is working because it has not been tested with WLAN equipment

      QLIB_FTM_WLAN_Philips_SET_MODULE
      - Philips command does not return a status value, so the value reported by QMSL is forced to
        FTM_WLAN_Philips_PCTI_FAILURE

   */

   /*
      These Philips commands are not enabled with a specific C interface, but it is
      possible to call QLIB_FTM_WLAN_USER_CMD().

      DISCONNECT_DUT
      CONNECT_DUT
      GET_TEMPERATURE
      SET_CALIBRATIONINFO
      GET_CALIBRATIONINFO
      EEPROM_READ
      EEPROM_WRITE
      SET_TX_DATA
      MEMORY_READ
      MEMORY_WRITE
      SB_REGISTER_WRITE
      RF_REGISTER_READ
      RF_REGISTER_WRITE
      COEX_LINE_READ
      COEX_LINE_WRITE
   */



#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_WLAN_PHILIPS_H)
