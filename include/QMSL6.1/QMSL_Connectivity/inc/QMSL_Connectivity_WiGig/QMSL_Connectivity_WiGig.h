/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Connectivity/inc/QMSL_Connectivity_WiGig/QMSL_Connectivity_WiGig.h#17 $
 * $DateTime: 2016/05/15 01:23:55 $
 *
 * DESCRIPTION: QMSL_Connectivity_WiGig
 ******************************************************************************
 *
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QLIB_WIGIG_H)
#define _QLIB_WIGIG_H

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
                     WiGig FTM
   *******************************************************************************/
   /******************************************************************************/
   /**

   This function will read from a WiGig address.

   \param address = address to read
   \param data = pointer to hold read data

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_Read(
      HANDLE hResourceContext, 
      unsigned int address,
      unsigned int *data);

   /******************************************************************************/
   /**

   This function will write to a WiGig address.

   \param address = address to write
   \param data = data to write

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_Write(
      HANDLE hResourceContext, 
      unsigned int address,
      unsigned int data);

   /******************************************************************************/
   /**

   This function will execute a WiGig WMI command.

   \param command = command string. 
   \code
      Format: <WDelegate-n>|<Command Name>|[param1,param2,...paramN] where n = interface number and command name is defined in KnownMbCommands.xml
      Example: "WDelegate-0|SET_SSID|12,72,101,108,108,111,32,87,111,114,108,100,0
   \endcode
   \param response = response string. Format TBD

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_WmiCommand(
      HANDLE hResourceContext, 
      char* command,
      char* response);


   /******************************************************************************/
   /**

   This function will get a WiGig WMI command event string.

   \param interfaceName = "WDelegate-n" where n = interface number

   \param response = response string. Format TBD

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetEvent(
      HANDLE hResourceContext, 
      char* interfaceName,
      char* response);

   /******************************************************************************/
   /**

   This function will execute a WiGig WMI command.

   \param command = command string. 
   \code
      Format: <WDelegate-n>|<module ID>|<subtype ID>|[param1,param2,...paramN] where n = interface number,  
         module ID is:
            UT_MODULE_FLOWS_OPERATIONAL = 0x9
            UT_MODULE_MODES = 0xb
            UT_MODULE_DRIVERS = 0xc
            UT_MODULE_CALIB_MNGR = 0x7
         Note: the options for module ID are as shown above (use hexadecimal value without the "0x" prefix),
         and subtype ID is:
            hwm_analog_channel_switch = 0x200 (module ID = b, 1 parameter: channel 1,2, or 3)
            hwm_analog_tx = 0x201 (module ID = b, 1 parameter: enable 0 or 1)
            hwm_analog_rx = 0x202 (module ID = b, 1 parameter: enable 0 or 1)
            hwm_analog_if_loopback = 0x203 (module ID = b, 3 parameters: enable 0 or 1; tx_gain_index ; rx_gain_index )
            hwm_analog_amdet_loopback = 0x205 (module ID = b, 3 parameters: enable 0 or 1; tx_gain_index ; rx_gain_index )
            hwm_power_pwdn_abif_165 = 0x301 (module ID = b, 1 parameter: enable 0 or 1)


      Example: "WDelegate-0|UT_MODULE_MODES|hwm_analog_channel_switch|1"
      
      More commands used by QRCT:

         Command String                                                       Description
      "<Interface Name>|b|hwm_analog_tx|n,1"                             "Set Analog part to TX mode (call twice, set n=0 then n=1)"
      "<Interface Name>|b|hwm_analog_rx|n,1"                             "Set Analog part to RX mode (call twice, set n=0 then n=1)"
      "<Interface Name>|c|hwd_phy_rx_cal_corr_config|1000,1,100"         "corr_config_parameters"
      "<Interface Name>|c|hwd_phy_set_tx_swap_iq|n"                      "n=1-digitally swap or n=0-straight I-Q in TX"
      "<Interface Name>|c|hwd_phy_tx_singen_config|<freq>,0,6"           "Configure Tx freq (CW)"
      "<Interface Name>|c|hwd_phy_tx_singen_transmit|n"                  "Set on/off to BB tone (n=1 on, n=0 off)"
      "<Interface Name>|c|hwd_rfc_tx_sect_on|<rfSectorNo>,<rfSectorNo>"  "Set RF mode to TX and set gain sector number"
      "<Interface Name>|c|hwd_rfc_rx_sect_on|<rfSectorNo>,<rfSectorNo>"  "Set RF mode to RX and set gain sector number"
      "<Interface Name>|c|hwd_rfc_powerdown|1"                           "Set RF off"
      "<Interface Name>|c|hwd_abif_rx_table_index_force_mode|0,0"        "Force rx bb gain"
      "<Interface Name>|c|hwd_abif_rx_table_index_force_mode|1,40"       "Force rx bb gain"
      "<Interface Name>|c|hwd_phy_self_tx_mode_entry|1"                  "Move PHY to TX mode without control of SXD"
      "<Interface Name>|c|hwd_phy_rgf_tx_en|n"                           "enable/disable of PHY 'tx-en' bit (n=1 enable n=0 disable)"
      "<Interface Name>|c|hwd_phy_rgf_rx_en|n"                           "enable/disable of PHY 'rx-en' bit (n=1 enable n=0 disable)"
      "<Interface Name>|c|hwd_phy_self_rx_mode_entry|1"                  "Move PHY to RX mode without control of SXD"
      "<Interface Name>|c|hwd_phy_rx_agc_steps_disable|1"                ""
      "<Interface Name>|c|hwd_phy_rx_ina_det_mode|0"                     ""
   \endcode
   \param response = response string. Response string will look exactly like the command string except that the parameters will be
                     replaced with a 1 if the command was successful, or a 0 or no response if the command failed.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_UtCommand(
      HANDLE hResourceContext, 
      char* command,
      char* response);

   /******************************************************************************/
   /**

   This function will get the WiGig firmware version.

   \param major = pointer to hold version major value
   \param minor = pointer to hold version minor value
   \param svn = pointer to hold version svn value

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetFirmwareVersion(
      HANDLE hResourceContext, 
      unsigned int* major, unsigned int* minor, unsigned int* svn);

   /******************************************************************************/
   /**

   This function will get the WiGig RF status.

   \param rfConnected = pointer to hold rf status: 0 = no rf detected, 1 = rf detected
   \param rfName = pointer to char array hold RF name
   \param bbName = pointer to char array hold baseband name

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetRfStatus(
      HANDLE hResourceContext, 
      unsigned int *rfConnected, 
      char *rfName, 
      char *bbName);

   /******************************************************************************/
   /**

   This function will load the WiGig firmware globals file.

   \param fileName = full path name of Firmware Globals file

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_loadFwGlobalsFile(
      HANDLE hResourceContext, 
      char *fileName);

   /******************************************************************************/
   /**

   This function will transmit a single tone (cw) at the specified frequency offset.

   \param freqAmhz = frequency A in MHz - suggested value 100
   \param freqBmhz = frequency B in MHz - suggested value 100
   \param config = configuration value - suggested value 6
   \param startStop = 1 to start, 0 to stop transmission

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_TransmitSingleTone(
      HANDLE hResourceContext, 
      int freqAmhz, 
      int freqBmhz, 
      int config, 
      int startStop);

   /******************************************************************************/
   /**

   This function will transmit packets at the specified MCS.

   - To send endless packets with 1000 * (1/165MHz) silence and with 1000 bytes at 
     mcs 12, paramters should be: -1, 1000, 12, 1000
   - To stop sending packets (send just one packet) at mcs 12,
     paramters should be: 1, 1000, 12, 1000

   \param numPackets = number of packets to send (-1 = infinite)
   \param silencePeriod = silence period int uSec
   \param mcs = modulation scheme value 1 to 12
   \param numBytes = number of bytes in the packet - suggested value 1000

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_TransmitPackets(
      HANDLE hResourceContext, 
      int numPackets, 
      double silencePeriod, 
      int mcs, 
      int numBytes);

   /******************************************************************************/
   /**

   This function will set the channel.

   \param channel: channel number 1 to 3

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_SetChannel(
      HANDLE hResourceContext, 
      int channel);

   /******************************************************************************/
   /**

   This function will clear the Rx statistics counters.

   \param channel: channel number 1 to 3

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_ClearRxStatistics(
      HANDLE hResourceContext);

   /******************************************************************************/
   /**

   This function will get Rx statistics counters.

   \param counters = pointer to array of 14 integers to hold counter values:
   \code
   0: ina sync counter dp
   1: sfd sync counter sc
   2: sfd timeout counter dp
   3: ina sync counter dp
   4: ina sync counter dp
   5: ina sync counter dp
   6: ina sync counter dp
   7: ina sync counter cp
   8: sfd sync counter cp
   9: sfd timeout counter cp
   10: crc ok counter cp
   11: crc error counter cp
   12: ber last zero counter cp
   13: ber last non zero counter cp
   \endcode
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetRxStatistics(
      HANDLE hResourceContext, 
      int *counters
      );

   /******************************************************************************/
   /**

   This function will do a SW reset of the device.

   \param none

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_SwReset(
      HANDLE hResourceContext
      );

   /******************************************************************************/
   /**

   This function will do the internal DC and SAR calibrations.

   \param channel = channel number to perform cal on

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_DoInternalCals(
      HANDLE hResourceContext,
      int channel
      );

   /******************************************************************************/
   /**

   This function will set the config file path for wigig.

   \param path = full path of the wigig configuration files

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_SetConfigFilePath(
      HANDLE hResourceContext, 
      char* path
      );

   /******************************************************************************/
   /**

   This function will get the connected device interface name.

   \param name = device interface name

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetDeviceInterfaceName(
      HANDLE hResourceContext, 
      char *name
      );


   /******************************************************************************/
   /**

   This function will set the driver mode.

   \param mode = new driver mode: 
      WBE_MODE, WIFI_STA_MODE, WIFI_SOFTAP_MODE, CONCURRENT_MODE, SAFE_MODE

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_SetDriverMode(
      HANDLE hResourceContext, 
      char *mode
      );

   /******************************************************************************/
   /**

   This function will get the bb and rf tempurature.

   \param bbTemp = pointer to variable to hold bb temp
   \param rfTemp = pointer to variable to hold rf temp

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetTempurature(
      HANDLE hResourceContext, 
      double* bbTemp, double *rfTemp
      );

   /******************************************************************************/
   /**

   This function loads register CSV files for use by mnemonic read/write commands.

   \param path = directory containing csv files to load.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_LoadRegCsvFiles(
      HANDLE hResourceContext, 
      char *path
      );

   /******************************************************************************/
   /**

   This function performs a mnemonic read operation.

   \param interfaceName = "WDelegate-n" where n = interface number
   \param mnemonicName = mnemonic name of register
   \param value = value read from register

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_MnemonicRead(
      HANDLE hResourceContext, 
      char *interfaceName, 
      char *mnemonicName, 
      unsigned int *value
      );

   /******************************************************************************/
   /**

   This function performs a mnemonic write operation.

   \param interfaceName = "WDelegate-n" where n = interface number
   \param mnemonicName = mnemonic name of register
   \param value = value to write to register

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_MnemonicWrite(
      HANDLE hResourceContext, 
      char *interfaceName, 
      char *mnemonicName, 
      unsigned int value
      );

   /******************************************************************************/
   /**

   This function returns information about a mnemonic path.

   \param mnemonicName = mnemonic name of register or location
	\param address = address of mnemonic path
	\param startingBitNumber = starting bit number of bit field
	\param endingBitNumber = ending bit number of bit field
	\param mask = bit mask

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
	QLIB_API unsigned char QLIB_FTM_WIGIG_GetMnemonicInfo(
		HANDLE hResourceContext, 
		char *mnemonicName, 
		unsigned int *address, 
		int *startingBitNum, 
		int *endingBitNum, 
		unsigned int *mask
		);

   /******************************************************************************/
   /**

   This function gets the current rf settings: sector number, sector gain and 
   TX/RX enable state.

   \param sectorNo = currently set sector number
   \param sectorGainNo = currently set sector gain
   \param rfRxTxEn = bit 0 set is Rx Enabled, bit 1 set is TX enabled, 
                     bit 0 = 0 and bit 1 = 0 is idle mode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetRfSectorGain( 
      HANDLE hResourceContext, 
      short *sectorNo, 
      short *sectorGainNo, 
      unsigned int *rfRxTxEn 
      );

   /******************************************************************************/
   /**

   This function gets the current channel.

   \param channelNum = currently set channel

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetChannel( 
      HANDLE hResourceContext, 
      unsigned int *channelNum
      );

   /******************************************************************************/
   /**

   This function gets the current TX CW status.

   \param enabled = 1 if CW tone is enabled, 0 if not
   \param freq = current CW tone frequency in MHz

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetTxCwToneInfo( 
      HANDLE hResourceContext, 
      unsigned int *enabled, 
      double *freq
      );


      /******************************************************************************/
   /**

   This function gets the current TX tone status.

   \param enabled = 1 if CW tone is enabled, 0 if not
   \param freqA = current FreqA tone frequency in MHz
   \param freqB = current FreqB tone frequency in MHz
   \param Mode =  current tone mode
   \param SinMax = current sin max value

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_GetTxToneInfo( 
      HANDLE hResourceContext, 
      unsigned int *enabled, 
      double *freqA,
	  double *freqB,
	  unsigned int *Mode,
	  unsigned int *SinMax
      );

   /******************************************************************************/
   /**

   This function disables the RX IF.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_DisableRxIF(
      HANDLE hResourceContext
      );

   /******************************************************************************/
   /**

   This function disables the TX IF.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_DisableTxIF(
      HANDLE hResourceContext
      );

   /******************************************************************************/
   /**

   This function turns off the RX LO.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_TurnOffRxLO(
      HANDLE hResourceContext
      );

   /******************************************************************************/
   /**

   This function turns off the TX LO.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WIGIG_TurnOffTxLO(
      HANDLE hResourceContext
      );


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_WIGIG_H)
