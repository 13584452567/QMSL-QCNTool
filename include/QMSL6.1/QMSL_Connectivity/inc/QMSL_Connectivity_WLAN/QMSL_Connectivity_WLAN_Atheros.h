/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Connectivity/inc/QMSL_Connectivity_WLAN/QMSL_Connectivity_WLAN_Atheros.h#18 $
 * $DateTime: 2016/04/29 13:10:12 $
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

/*
\code

   - Defines the "C" interface for all Factory Library functions.

   - Table of contents (text search can be done for the following sections)

         - General Information
         - Related Documents
         - Version History

         - WLAN FTM


   ------------------------------------------------------


   ----------------------
   General Information
   ----------------------

   - All data types used in this interface are ANSI C compatible.

   - All returns that indicate "true if succeed, false if fail" are defined
      as:  1 = true = Success , 0 = false = failure

      Functions that are not entirely upper case do not correspond directly to
      an FTM or diagnostic command.

      For example, QLIB_ConnectServer() is not mapped directly to a diagnostic
      command.


   - Variable Names
      Variable names are prefixed in lower case to indicate the data type.
      The following are defined:

         p = Pointer
         i = Integer type, either char, short, or long
         d = Double or floating point
         e = Enumeration (possibly stored as a short, but representing
                          a fixed list of possibilities)
         b = unsigned char, 0=false, 1=true

   ----------------------
   Related Documents
   ----------------------

   - The function name convention used in this document is as follows:

      QLIB_ indicates that this function corresponds to library function
      in the QLib project.

      From there, all diagnostic and FTM functions are named exactly as
      the command identifiers are defined in the QLib_Defines.h.

   - For a list of all document numbers referred to by QMSL, please see following section in the QDART Help file:
      1) QDART -> QDART Related Documents
   or  2) QDART -> QMSL -> Getting Started -> References.


\endcode
*/

#if !defined(_QLIB_WLAN_ATHEROS_H)
#define _QLIB_WLAN_ATHEROS_H

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

   Atheros WLAN command to set RX MAC ADDRESS

   \param aiMAC_Address = MAC Address

   \param aiBSS_ID = BSS ID

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SET_RX_MAC_ADDRESS
   (
      HANDLE hResourceContext, 
      unsigned char aiMAC_Address[6],
      unsigned char aiBss_Id[6]
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to set OTP MAC ADDRESS

   \param aiMAC_Address = MAC Address

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SET_OTP_MAC_ADDRESS
   (
      HANDLE hResourceContext, 
      unsigned char aiMAC_Address[6] 
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to set NV MAC ADDRESS, this command is handled by the FTM SW, not by UTF.
   Per design requested, this is for QC6174 only, furture chips might be added from FTM software

   \param nMac = number of Mac address, maximum number of MAC addresses supported is 4.

   \param aiMAC_Address = MAC Addresses, multiple of 6 bytes for 1+ mac address

   \return true if successful, false if failure

   \warning  QLIB_FTM_WLAN_SetModuleType() must be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SET_NV_MAC_ADDRESS
   (
      HANDLE hResourceContext, 
     int nMac,
      unsigned char aiMAC_Address[] 
   );


   /******************************************************************************/
   /**

   Atheros WLAN command to WRITE MAC ADDRESS

   \param aiMAC_Address = MAC Address
   
   \param location:      the location where the MAC Address is written to
                  = 1 - flash; 
                  = 5 - file
   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API   unsigned char QLIB_FTM_WLAN_Atheros_WRITE_MAC_ADDRESS
   ( 
      HANDLE hResourceContext,
      unsigned char aiMAC_Address[6], 
      int location
   );


   /******************************************************************************/
   /**

   Atheros WLAN command to READ MAC ADDRESS

   \param aiMAC_Address = MAC Address
   
   \param location:      the location where the MAC Address is written from
                  = 1 - flash; 
                  = 5 - file
   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API   unsigned char QLIB_FTM_WLAN_Atheros_READ_MAC_ADDRESS
   ( 
      HANDLE hResourceContext,
      int location, 
      unsigned char* aiMAC_Address
   );
   
   /******************************************************************************/
   /**

   Atheros WLAN command to write Bluetooth Device address into OTP

   \param aiBD_Address = BD Address

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SET_BD_ADDRESS_IN_OTP
   (
      HANDLE hResourceContext, 
      unsigned char aiBD_Address[6] 
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to read Bluetooth Device address from OTP

   \param aiBD_Address = BD Address read

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_GET_BD_ADDRESS_FROM_OTP
   (
   HANDLE hResourceContext,
   unsigned char *aiBD_Address 
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to use WLAN functionality to set Regulatory Domain values 

   \param aiBD_Address = 2 bytes of reg domain values

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SET_OTP_REG_DOMAIN
   ( 
   HANDLE hResourceContext,
    unsigned int aiRegDmn[2]
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to use WLAN functionality to read Regulatory Domain values

   \param aiBD_Address = Buffer for reg domain values

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_GET_OTP_REG_DOMAIN
   ( 
    HANDLE hResourceContext,
   unsigned int *aiRegDmn 
   );

   /******************************************************************************/
   /**

   Atheros WLAN command Set value for PCIe configuration via OTP

   \param iAction = Which PCIe configuration value is being set
               SSID = 0;
               SVID = 1;
               DeviceID = 2,
               VendorID = 3,

   \param iValue = Value to be set PCIe configuration item

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_SET_PCIe_CONFIG_IN_OTP_STREAM
   (
      HANDLE hResourceContext, 
      unsigned int iAction,
      unsigned int iValue
   );
   
   /******************************************************************************/
   /**

   Atheros WLAN command Get value for PCIe configuration from OTP stream

   \param iAction = Which PCIe configuration value to get
               SSID = 0;
               SVID = 1;
               DeviceID = 2,
               VendorID = 3,

   \param iValue = Value read from PCIe configuration item

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_GET_PCIe_CONFIG_FROM_OTP_STREAM
   (
      HANDLE hResourceContext, 
      unsigned int iAction,
      unsigned int *iValue
   );

   /******************************************************************************/
   /**

   Atheros WLAN command Set value for TOP Configuration area of OTP

   \param iAction = Which Top configuration value is being set
         Xtal settling time = 0 
         xtal_cdacin0 =1
         xtal_cdacout0 =2
         xtal_sel = 3
         Sdio vid = 4
         Sdio did = 5

   \param iValue = Value to be set for TOP configuration item

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_SET_TOP_CONFIG_IN_OTP
   (
       HANDLE hResourceContext, 
       unsigned int iAction,
       unsigned int iValue
   );
   
   /******************************************************************************/
   /**

   Atheros WLAN command Set value for BT Configuration area of OTP

   \param iAction = Which BT configuration value is being set
      PID of DFU = 0
      VID of DFU = 1
      PID of FW = 2
      VID of FW = 3
      PID of Preboot HID = 4
      VID of Preboot HID = 5

   \param iValue = Value to be set for TOP configuration item

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_SET_BT_CONFIG_IN_OTP
   (
       HANDLE hResourceContext, 
       unsigned int iAction,
       unsigned int iValue
   );

   /******************************************************************************/
   /**

   Atheros WLAN command Read value for TOP Configuration area of OTP

   \param iAction = Which Top configuration value is being read
         Xtal settling time = 0 
         xtal_cdacin0 =1
         xtal_cdacout0 =2
         xtal_sel = 3
         Sdio vid = 4
         Sdio did = 5

   \param iValue = Value read from TOP configuration item

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_GET_TOP_CONFIG_FROM_OTP
   (
       HANDLE hResourceContext, 
       unsigned int iAction,
       unsigned int *iValue
   );

   /******************************************************************************/
   /**

   Atheros WLAN command Read value for BT Configuration area of OTP

   \param iAction = Which BT configuration value is being set
      PID of DFU = 0
      VID of DFU = 1
      PID of FW = 2
      VID of FW = 3
      PID of Preboot HID = 4
      VID of Preboot HID = 5

   \param iValue = Value read from TOP configuration item

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_GET_BT_CONFIG_FROM_OTP
   (
       HANDLE hResourceContext, 
       unsigned int iAction,
       unsigned int *iValue
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to start self init cal

   \param iChannel = WLAN channel frequency in MHz on which self init to be performed

   \param iChainMask = Chain Mask enum, 
                        1 = Chain 0,
                        2 = Chain 1,
                        3 = Both Chains (0, 1)

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SELF_INIT_CAL
   (
      HANDLE hResourceContext, 
      int iChannel, 
      int iChainMask
   );
   
   /******************************************************************************/
   /**

   Atheros WLAN command to get self init cal result

   \param iChannel = WLAN channel frequency in MHz on which self init to be performed

   \param iChainMask = Chain Mask enum, 
                        1 = Chain 0,
                        2 = Chain 1,
                        3 = Both Chains (0, 1)
   
   \param iOlpcGainDelta = Pointer to 4 int array for Olpc Gain Delta

   \param iThermalCal = Pointer to 4 unsigned int array for Thermal Cal Value

   \param cmacOlpc = Pointer to 4 unsigned long array for cmacOlpc

   \param cmacPsat = Pointer to 4 unsigned long array for cmacPsat

   \param iCmacOlpcPcdac = Pointer to 4 unsigned int array for cmacPsat

   \param iCmacPsatPcdac = Pointer to 4 unsigned int array for cmacPsat

   \param iPsatParm = Pointer to 4 unsigned int array for cmacPsat

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_GET_SELF_INIT_CAL_RESULT
   ( 
     HANDLE hResourceContext, 
     int iChannel, 
     int iChainMask,
     int* iOlpcGainDelta,
     unsigned int* iThermalCal,
     unsigned long* cmacOlpc, 
     unsigned long* cmacPsat, 
     unsigned int* iCmacOlpcPcdac, 
     unsigned int* iCmacPsatPcdac, 
     unsigned int* iPsatParm
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to commit self init data

   \param iWriteOption = Write option
                     3 = Write to OTP
                     5 = Write to File

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SELF_INIT_COMMIT
   (
      HANDLE hResourceContext, 
      unsigned char iWriteOption
   );

   /*****************************************************************************
   /**
   Atheros WLAN Call back function for CW Freq Error measurement used in xtal calibration

      \param iCapValue = cap value
      \param iCwFreqMHz = channel freq in MHz
      \param dPowerLevel = expected power level in dBm
      \param numAvg = number of measurements used for power average

   \return measured power in dBm averaged over numAvg measurements

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   typedef double( *asyncCWFreqErrMessageCB  )
   (
     unsigned int iCapValue,
     unsigned int iCwFreqMHz,
     double dPowerLevel,
     unsigned int iNumAvg
   );

   typedef void( *asyncDbgMessageCB  )
   (
     char *strMsg
   );

    typedef void( *asyncQmslMessageCB  )
   (
     unsigned int type,
     char *strMsg
   );

   /*****************************************************************************
   /**
   Atheros WLAN Call back function for power measurement used in power calibration

      \param gain = current calibration gain setting (for logging)
      \param freq = channel freq in MHz
      \param powerLevel = expected power level in dBm
      \param numAvg = number of measurements used for power average
      \param iTriggerType = trigger type for power measurements
      \param iTriggerLevel = trigger level for power measurements, for measure CW tone, set iTriggerLevel = -1000

   \return measured power in dBm averaged over numAvg measurements

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   typedef double( *asyncPMMessageCB )
   (
     unsigned int iGain,
     unsigned int iFreq,
     double dPowerLevel,
     unsigned int iNumAvg,
     unsigned int iTriggerType,
     int iTriggerLevel      // for measure CW tone, set iTriggerLevel = -1000
   );

   /*****************************************************************************
   /**
   Atheros WLAN Call back function for signal generation used in Rx gain calibration

      \param inputSignalStrength_dBm = Desired input signal strength at receiver
      \param freq = channel freq in MHz
      \param rate
      \param numPackets - Number of packets for VSG to transmit
      \param bandWidth 

   \return Indication if function executed successfully
   *******************************************************************************/

   typedef int ( *asyncHandlerSG_CB )
   (
      int inputSignalStrength_dBm,
      unsigned int freq,
      unsigned int rate,
      unsigned int numPackets,
      unsigned int chain
   );

   /*****************************************************************************
   /**
   Atheros WLAN Call back function for power measurement used in power calibration

      \param status  = Indicates if the calibration completed successfully

   \return Indication if function executed successfully
   *******************************************************************************/

   typedef bool ( * asyncHandlerRxGainCalDoneCB )
   (
       unsigned int status
   );


      /*****************************************************************************
   /**
   Atheros WLAN Call back function for RF switch control

      \param chainMask = chain to turn ON.

   \return measured power in dBm averaged over numAvg measurements

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   typedef bool( *asyncRFSMessageCB )
   (
     int chainMask
   );

   /*****************************************************************************
   /**
   Atheros WLAN Call back function to set chain number which will be used by instruments to
   to get pathloss data.

      \param chainMask = chain to turn ON.

   \return measured power in dBm averaged over numAvg measurements

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   typedef bool( *asyncSetChainMessageCB )
   (
     int chainMask
   );

   /******************************************************************************/
   /**
   Atheros WLAN command to create tlv OP command

   Note: This command works only when target is awake.
       (Current supported chip set: QC98XX, AR6004)
  
   \param   opCode   = tlv opCode

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV_Create
   (
      HANDLE hResourceContext,
     unsigned char opCode
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to add tlv command

   Note: This command works only when target is awake.
       (Current supported chip set: QC98XX, AR6004)
  
   \param   pKey = pointer to tlv command key

         pData = pointer to tlv command value with size of iDataSize*iSequenceSize, if iSequenceSize>0

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV_AddParam
   (
      HANDLE hResourceContext,
      char *pKey, 
      char *pData 
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to send tlv command

   Note: This command works only when target is awake.
       (Current supported chip set: QC98XX, AR6004)
  
   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV_Complete
   (
      HANDLE hResourceContext
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to get tlv command response for the selected key 

   Note: This command works only when target is awake.
       (Current supported chip set: QC98XX, AR6004)
  
   \param   pKey = pointer to tlv response command key

         pData = pointer to tlv response command value with size of 1024 bytes

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV_GetRspParam
   (
      HANDLE hResourceContext,
      char *pKey, 
      char *pData
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to create tlv OP command

   Note: This command works only when target is awake.
       (Current supported chip set: QC98XX, AR6004)
  
   \param   opCode   = tlv opCode

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV2_Create
   (
      HANDLE hResourceContext,
     unsigned char opCode
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to add tlv command

   Note: This command works only when target is awake.
       (Current supported chip set: QC98XX, AR6004)
  
   \param   pKey = pointer to tlv command key

         pData = pointer to tlv command value with size of iDataSize*iSequenceSize, if iSequenceSize>0

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV2_AddParam
   (
      HANDLE hResourceContext,
      char *pKey, 
      char *pData 
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to send tlv command

   Note: This command works only when target is awake.
       (Current supported chip set: QC98XX, AR6004)
  
   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV2_Complete
   (
      HANDLE hResourceContext
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to get tlv command response for the selected key 

   Note: This command works only when target is awake.
       (Current supported chip set: QC98XX, AR6004)
  
   \param   pKey = pointer to tlv response command key

         pData = pointer to tlv response command value with size of 1024 bytes

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV2_GetRspParam
   (
      HANDLE hResourceContext,
      char *pKey, 
      char *pData
   ); 

      /******************************************************************************/
   /**
   Atheros WLAN command to send tlv command 

   Note: This command works only when target is awake.
       (Current supported chip set: QC6180)
  

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV2_CommandSend
   (
      HANDLE hResourceContext,
      void *para
   );

    /******************************************************************************/
   /**
   Atheros WLAN command to get Firmware version

   Note: This command works only when target is awake.
       (Current supported chip set: QC6174)
  
   \param   pData = pointer to firmware value

   \return true if successful, false if failure

   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_GetFwVersion
   (
      HANDLE hResourceContext,
      char *pData
   ); 

   QLIB_API char QLIB_FTM_WLAN_SetDFE
   (
      HANDLE hResourceContext,
      unsigned char enable
   ); 
   /******************************************************************************/
   /**
   Atheros WLAN command to StickyWrite command

   Note: This command works only when target is awake.
       (Current supported chip set: QC6174 and onward)
  
   \param   regField = Register.Field full entry name

         regValue = Value to be written to field

         prepost = 0 : prewrite data before target reset. 1: postwrite data after target reset.

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_QCA_StickyWrite
   (
      HANDLE hResourceContext,
      char *regField, 
      unsigned int regValue,
      int prepost
   ); 

      /******************************************************************************/
   /**
   Atheros WLAN command to StickyClear command

   Note: This command works only when target is awake.
       (Current supported chip set: QC6174 and onward)
  
   \param   regField = Register.Field full entry name

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_QCA_StickyClear
   (
      HANDLE hResourceContext,
      char *regField
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to load design specific library DLL for calibration, Tx, Rx, EEPROM, register access etc.

   Note: This cmd works only when target is awake.
       This cmd must be called before any cmd to access chip.
       (Current supported chip set: None, reserved API for future)
  
   \param   DevDLLname   = Device specific DLL name (less than 30 charactors, no path)
                    All chip specific DLLs must be in the same directory of QMSL dll.

       boardDataFName = Board data file name (less than 250 charactors)
            if no path in boardDataFName, board data file must be in .\..\driver\BoardData\ from QMSL dll location

         iNVMem      = device NV memory type
                     0: CalDataNone
                     1: CalDataFlash
                     2: CalDataEeprom
                     3: CalDataOtp
                     4: CalDataDontLoad
                     5: CalDataFile
                     6: CalDataDram

               ssid = 4 Hex digit SSID 

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_LoadDUT
   (
      HANDLE hResourceContext,
     unsigned char *DevDLLname, 
     unsigned char *boardDataFName, 
     int iNVMem, 
     unsigned int ssid
   ); 

   /******************************************************************************/
   /**
   Atheros WLAN command to unload loaded devlib library DLL 

   Note: This cmd works only when target is awake.

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_UNLoadDUT
   (
      HANDLE hResourceContext
   ); 


   /******************************************************************************/
   /**
   Atheros WLAN command to set more parameters for QLIB_FTM_WLAN_Atheros_Tx

   Note: This cmd might be called before calling QLIB_FTM_WLAN_Atheros_Tx().
       If this cmd doesn't be called all default setting will be used during    QLIB_FTM_WLAN_Atheros_Tx()
       (Current supported chip set: AR6004)
  
   \param   iDpdMode   = Set Tx dpdMode (PARD mode), this needs working together with board data settings.
                     1: turn off dpdMode. (default)
                     0: turn on dpdMode.   

              iAggr = Set Tx aggregation. (0 to 32)
                    Current firmware release for AR6004 only works for 0.

            iParam   = 0 (reserve for future)

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Tx_params
   (
        HANDLE hResourceContext,
        int iDpdMode,
        int iAggr,
        int iParam
   ); 

   /******************************************************************************/
   /**

   Atheros WLAN command to enable/disable transmit

   Note: Enable/disable continuous tx test cmd works only when target is awake.
       (Current supported chip set: AR6004)

   \param iMode =   0: TX_OFF
                  1: TX_SINE
                  2: TX_FRAME
                  3: TX_TX99
                  4: TX100


         iFreq = Transmit Frequency in MHz or Channel number
                 For example, 2412 for channel 1 in 802.11g, or 1

   iDataRate =  Tx data rate
               HT20 1 Mbps - 0
               HT20 2 Mbps (long) - 1
               HT20 2 Mbps (short) - 2
               HT20 5.5 Mbps (long) - 3
               HT20 5.5 Mbps (short) - 4
               HT20 11 Mbps (long) - 5
               HT20 11 Mbps (short) - 6
               HT20 6 Mbps - 8
               HT20 9 Mbps - 9
               HT20 12 Mbps - 10
               HT20 18 Mbps - 11
               HT20 24 Mbps - 12
               HT20 36 Mbps - 13
               HT20 48 Mbps - 14
               HT20 54 Mbps - 15
               HT20 MCS0 6.5 Mbps - 16
               HT20 MCS1 13 Mbps - 17
               HT20 MCS2 19.5 Mbps - 18
               HT20 MCS3 26 Mbps - 19
               HT20 MCS4 39 Mbps - 20
               HT20 MCS5 52 Mbps - 21
               HT20 MCS6 58.5 Mbps - 22
               HT20 MCS7 65 Mbps - 23
               HT40 MCS0 13.5 Mbps - 24
               HT40 MCS1 27 Mbps - 25
               HT40 MCS2 40.5 Mbps - 26
               HT40 MCS3 54 Mbps - 27
               HT40 MCS4 81 Mbps - 28
               HT40 MCS5 108 Mbps - 29
               HT40 MCS6 121.5 Mbps - 30
               HT40 MCS7 135 Mbps - 31
               HT20 MCS8 13 Mbps - 32
               HT20 MCS9 26 Mbps - 33
               HT20 MCS10 39 Mbps - 34
               HT20 MCS11 52 Mbps - 35
               HT20 MCS12 78 Mbps - 36
               HT20 MCS13 104 Mbps - 37
               HT20 MCS14 117 Mbps - 38
               HT20 MCS15 130 Mbps - 39
               HT40 MCS8 27 Mbps - 40
               HT40 MCS9 54 Mbps - 41
               HT40 MCS10 81 Mbps - 42
               HT40 MCS11 108 Mbps - 43
               HT40 MCS12 162 Mbps - 44
               HT40 MCS13 216 Mbps - 45
               HT40 MCS14 243 Mbps - 46
               HT40 MCS15 270 Mbps - 47


        dTxPwr = Tx Power in dBm (0.5 dBm steps)

       iAntenna = Antenna to use for Tx.
              1: antenna one, etc.

        iEnANI = 0 = Anti-noise immunity (ANI) algorithm is disabled
               1 = Anti-noise immunity (ANI) algorithm is enabled

        iScramblerOff = 1 Scrambler is disabled
                  = 0 Scrambler is enabled.  Scrambler is used with CCK frames

         iAifsn = value from 0 to 252,

         iPktSz = packet size, default is 1500.  Vary from 32 to 1500

         iTxPattern = Applies to CONT_TX_TX99, CONT_TX_TX100, and CONT_TX_MODE

            0: ZEROES_PATTERN
            1: ONES_PATTERN
            2: REPEATING_10
            3: PN7_PATTERN
            4: PN9_PATTERN
            5: PN15_PATTERN

         iShortGuard = 1: Use short guard band, 0: Don't use

         iNumPackets = number of packets to send, 0-65535

         iWlanMode = WLAN channel mode:

            0: NOHT
            1: HT20 (20Mhz channel BW)
            2: HT40PLUS (40MHz channel, primary channel high)
            3: HT40MINUS (40MHz channel, primary channel low)

         iTpcm = Tx Power Control Mode

            0: Tx Power
            1: Forced Gain
            2: Target Power

      iTxChainMask = Tx chain mask 
                 1: chain0
                 2: chain1
                 3: chain0 and chain1
                 4: chain2
                 5: chain0 and chain2
                 7: all 3 chains on

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Tx
   (
      HANDLE hResourceContext,
     int iMode,
     int iFreq,
     int iDataRate,
     double dTxPwr,
     int iAntenna,
     int iEnANI,
     int iScramblerOff,
     int iAifsn,
     int iPktSz,
     int iTxPattern,
     int iShortGuard,
     int iNumPackets,
     int iWlanMode,
     int iTpcm, 
     int iTxChainMask
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to enable/disable transmit

   Note: Enable/disable continuous tx test cmd works only when target is awake.
       This cmd must be called after loading chip specified DLL by calling QLIB_FTM_WLAN_Atheros_LoadDUT().
       (Current supported chip set: None, reserved API for future)

   \param iMode =   0: TX_OFF
                  1: TX_SINE
                  2: TX_FRAME
                  3: TX_TX99
                  4: TX100

         iFreq = Transmit Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g, or 1

         piDataRate: Array of Tx rates
            The size of the array must match the size of iNRate.
            The rate specifiers are:
                0 - 1Mbps
               1 - 2Mbps   (SHORT: iShortGi=1; LONG: iShortGi=0 )
               2 - 5.5Mbps (SHORT: iShortGi=1; LONG: iShortGi=0 )
               3 - 11Mbps   (SHORT: iShortGi=1; LONG: iShortGi=0 )
               4 - 6Mbps
               5 - 9Mbps
               6 - 12Mbps
               7 - 18Mbps
               8 - 24Mbps
               9 - 36Mbps
               10 - 48Mbps
               11 - 54Mbps
               12 - HT20 MCS0 6.5Mbps
               13 - HT20 MCS1 13Mbps
               14 - HT20 MCS2 19.5Mbps
               15 - HT20 MCS3 26Mbps
               16 - HT20 MCS4 39Mbps
               17 - HT20 MCS5 52Mbps
               18 - HT20 MCS6 58.5Mbps
               19 - HT20 MCS7 65Mbps
               20 - HT40 MCS0 13.5Mbps
               21 - HT40 MCS1 27Mbps
               22 - HT40 MCS2 40.5Mbps
               23 - HT40 MCS3 54Mbps
               24 - HT40 MCS4 81Mbps
               25 - HT40 MCS5 108Mbps
               26 - HT40 MCS6 121.5Mbps
               27 - HT40 MCS7 135Mbps
               28 - AC HT20 MCS0 
               29 - AC HT20 MCS1 
               30 - AC HT20 MCS2 
               31 - AC HT20 MCS3 
               32 - AC HT20 MCS4 
               33 - AC HT20 MCS5 
               34 - AC HT20 MCS6 
               35 - AC HT20 MCS7 
               36 - AC HT20 MCS8 
               37 - AC HT20 MCS9 
               38 - AC HT40 MCS0 
               39 - AC HT40 MCS1 
               40 - AC HT40 MCS2 
               41 - AC HT40 MCS3 
               42 - AC HT40 MCS4 
               43 - AC HT40 MCS5 
               44 - AC HT40 MCS6 
               45 - AC HT40 MCS7 
               46 - AC HT40 MCS8 
               47 - AC HT40 MCS9 
               48 - AC HT80 MCS0 
               49 - AC HT80 MCS1 
               50 - AC HT80 MCS2 
               51 - AC HT80 MCS3 
               52 - AC HT80 MCS4 
               53 - AC HT80 MCS5 
               55 - AC HT80 MCS6 
               55 - AC HT80 MCS7 
               56 - AC HT80 MCS8 
               57 - AC HT80 MCS9 
               58 - HT20 MCS8 
               59 - HT20 MCS9 
               60 - HT20 MCS10 
               61 - HT20 MCS11 
               62 - HT20 MCS12
               63 - HT20 MCS13
               64 - HT20 MCS14 
               65 - HT20 MCS15
               66 - HT40 MCS8 
               67 - HT40 MCS9 
               68 - HT40 MCS10 
               69 - HT40 MCS11
               70 - HT40 MCS12 
               71 - HT40 MCS13
               72 - HT40 MCS14 
               73 - HT40 MCS15 
               74 - AC HT20 2stream MCS0 
               75 - AC HT20 2stream MCS1 
               76 - AC HT20 2stream MCS2 
               77 - AC HT20 2stream MCS3 
               78 - AC HT20 2stream MCS4 
               79 - AC HT20 2stream MCS5 
               80 - AC HT20 2stream MCS6 
               81 - AC HT20 2stream MCS7 
               82 - AC HT20 2stream MCS8 
               83 - AC HT20 2stream MCS9 
               84 - AC HT40 2stream MCS0 
               85 - AC HT40 2stream MCS1 
               86 - AC HT40 2stream MCS2 
               87 - AC HT40 2stream MCS3 
               88 - AC HT40 2stream MCS4 
               89 - AC HT40 2stream MCS5 
               90 - AC HT40 2stream MCS6 
               91 - AC HT40 2stream MCS7 
               92 - AC HT40 2stream MCS8 
               93 - AC HT40 2stream MCS9 
               94 - AC HT80 2stream MCS0 
               95 - AC HT80 2stream MCS1 
               96 - AC HT80 2stream MCS2 
               97 - AC HT80 2stream MCS3 
               98 - AC HT80 2stream MCS4 
               99 - AC HT80 2stream MCS5 
               100 - AC HT80 2stream MCS6 
               101 - AC HT80 2stream MCS7 
               102 - AC HT80 2stream MCS8 
               103 - AC HT80 2stream MCS9 
               104 - HT20 MCS16 
               105 - HT20 MCS17 
               106 - HT20 MCS18 
               107 - HT20 MCS19 
               108 - HT20 MCS20
               109 - HT20 MCS21
               110 - HT20 MCS22 
               111 - HT20 MCS23
               112 - HT40 MCS16 
               113 - HT40 MCS17 
               114 - HT40 MCS18 
               115 - HT40 MCS19
               116 - HT40 MCS20 
               117 - HT40 MCS21
               118 - HT40 MCS22 
               119 - HT40 MCS23 
               120 - AC HT20 3stream MCS0 
               121 - AC HT20 3stream MCS1 
               122 - AC HT20 3stream MCS2 
               123 - AC HT20 3stream MCS3 
               124 - AC HT20 3stream MCS4 
               125 - AC HT20 3stream MCS5 
               126 - AC HT20 3stream MCS6 
               127 - AC HT20 3stream MCS7 
               128 - AC HT20 3stream MCS8 
               129 - AC HT20 3stream MCS9 
               130 - AC HT40 3stream MCS0 
               131 - AC HT40 3stream MCS1 
               132 - AC HT40 3stream MCS2 
               133 - AC HT40 3stream MCS3 
               134 - AC HT40 3stream MCS4 
               135 - AC HT40 3stream MCS5 
               136 - AC HT40 3stream MCS6 
               137 - AC HT40 3stream MCS7 
               138 - AC HT40 3stream MCS8 
               139 - AC HT40 3stream MCS9 
               140 - AC HT80 3stream MCS0 
               141 - AC HT80 3stream MCS1 
               142 - AC HT80 3stream MCS2 
               143 - AC HT80 3stream MCS3 
               144 - AC HT80 3stream MCS4 
               145 - AC HT80 3stream MCS5 
               146 - AC HT80 3stream MCS6 
               147 - AC HT80 3stream MCS7 
               148 - AC HT80 3stream MCS8 
               149 - AC HT80 3stream MCS9 
                          
      iNRate: Tx Rate Array Size (Maximum to 8)
            = 1 (For current release iNRate always set to 1, reserved for future.)

      ir = interleave packets from different rates.
         (Always set to 0, reserved for future.)

         pdTxPwr = Array of Tx Powers in dBm for each rate (0.5 dBm steps)
            The size of the array must match the size of iNRate.

      iRetries = The number of times a packet is retransmitted by MAC (0-15)

       iAntenna = Antenna to use for Tx.
              1: antenna one, etc.

      iBroadcast = 0: packets are unicast
               1: packets are broadcast

         iShortGuard = 1: Use short guard band, 0: Don't use

      iAggr = The number of aggregated packets (0-64)

         piPatternint = Array of patterns for each Tx rate which applies to CONT_TX_TX99, CONT_TX_TX100, and CONT_TX_MODE
            The size of the array must match the size of iNRate.
            0: ZEROES_PATTERN
            1: ONES_PATTERN
            2: REPEATING_10
            3: PN7_PATTERN
            4: PN9_PATTERN
            5: PN15_PATTERN

         iNumPktPerRate = number of packets to send for each rate (1-2147483647)

         piPktLen = Array of packet lengths for each data rate (1-32768)
            The size of the array must match the size of iNRate.

      iWlanMode = WLAN channel mode:
                  0: NOHT
                  1: HT20 (20Mhz channel BW)
                  2: HT40PLUS 
                  3: HT40MINUS 
               4: CCK
               5: VHT20
               6: VHT40Plus
               7: HT40MINUS
               8: VHT80_0
               9: VHT80_1
               10:VHT80_2
               11:VHT80_3

      iTPCM = Tx Power Control Mode
                  0: Tx Power
                  1: Forced Gain
                  2: Target Power
               3: Tx forced gain
               4: Forced gainIndex
               5: Forced target power

      iGain = Tx gain when iTPCM is set to use force tx gain

      iGainIndex = Tx gain index when iTPCM is set to use Forced gainIndex

      iDacGain = DAC gain when iTPCM is set to use Forced gainIndex

      iTxChainMask = Tx chain mask 
                 1: chain0
                 2: chain1
                 3: chain0 and chain1
                 4: chain2
                 5: chain0 and chain2
                 7: all 3 chains on

      iFlags = bit0 for Tx DPDMode (PAPRD mode)   1: enable; 0: disable
            bits 31-1 reserved for future

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_DevTx
   (
      HANDLE hResourceContext,
     int iMode,
     int iFreq,
     int *piDataRate, 
     int iNRate, 
     int ir, 
     double *pdTxPower,   
     int iRetries, 
     int iAntenna, 
     int iBroadcast, 
     int iShortGi, 
     int iAggr, 
     unsigned char *piPatternint, 
     int iNumPktPerRate, 
     int *piPktLen, 
     int iWlanMode, 
     int iTPCM, 
     int iGain, 
     int iGainIndex, 
     int iDacGain, 
     int iTxChainMask,
     int iFlags
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to initialize xtal Calibration

   Note: (Current supported chip set: QC6174)
       This cmd must be called after loading chip specified DLL 
         by calling QLIB_FTM_WLAN_Atheros_LoadDUT().

   \param iXtalTargetPPM =   targeted xtal cal Freq Error in PPM.

   \param iXtalTolerancePPM = the tolerance between the targeted xtal cal FreqErr and 
                              final calibrated xtal cal FreqErr in PPM.
   \param iXtalCapDelta = the delta value between the capout and capin.

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_xtal_CAL_INIT
   (
   HANDLE hResourceContext,
   int iXtalTargetPPM, 
   unsigned int iXtalTolerancePPM,
    int iXtalCapDelta,
   unsigned int dXtalCalSaveOption
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to perform xtal Calibration

   Note: (Current supported chip set: QC6174)
       This cmd must be called after loading chip specified DLL 
         by calling QLIB_FTM_WLAN_Atheros_LoadDUT() and QLIB_FTM_WLAN_Atheros_xtal_CAL_INIT().

   pAsyncCWFreqErrMessageCB = Call back delegate for FreqErr measurement.

   measAvg = number of average FreqErr measurements.

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_xtal_CAL
   (
   HANDLE hResourceContext,
   asyncCWFreqErrMessageCB pAsyncCWFreqErrMessageCB, 
    unsigned int measAvg
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to initialize transmit Calibration

   Note: (Current supported chip set: QC98xx, AR6004)
       This cmd must be called after loading chip specified DLL 
         by calling QLIB_FTM_WLAN_Atheros_LoadDUT().

   \param calDLLname =   calibration dll name (less than 30 charactors, no path)
                  Calibration DLLs must be in the same directory of QMSL dll.

   \param calPoints =   1: txgain calibration
                  2: 2 points calibration
                  5: 5 points calibration

   \param calGainMode =   Configuration options for calibration
      For one point calibration:
      0: txgain calibration
      1: gainIndex calibration (not implemented)
      2: selfInit calibration
      For two/fine point calibration:
      0: subsequent gain value is a delta from the previous gain value that the 1 calibrated point was measured
         gain[0]: initial gain value for 1st calibration point
         gain[1 ~ calPoints-1]: gain delta from the 1st point of calibration gain value
      1: subsequent gain value is calculated based on the delta of power in dB from the 1st point calibrated power
         targetPower[0]: the target power for the 1st point calibration
         targetPower[1 ~ calPoints-1]: the delta of power in dB from the 1st point calibrated power

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_INIT
   (
   HANDLE hResourceContext,
   unsigned char *calDLLname, 
   int iCalPoints, 
   int iCalGainMode
   );


   
   /******************************************************************************/
   /**

   Atheros WLAN command to run transmit calibration best on Target FW request

   \param 

   pAsyncPMMessageCB = Call back delegate for power measurement.

   measAvg = number of average power measurements.

   AllChainOn = set to 1 to calibrate with all chains on, and use an rf switch to 
                isolate individual chains, or set to 0 to turn one chain on at a time

   debugInfo = set to 1 to get additional debug information back 
               from FW during the calibration sequence

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Tx_FW_CAL
   (
   HANDLE hResourceContext,
   asyncSetChainMessageCB pAsyncSetChainMessageCB,
   asyncPMMessageCB pAsyncPMMessageCB,
   unsigned int measAvg,
   bool AllChainOn,
   asyncRFSMessageCB pAsyncRFSMessageCB,
   bool DebugInfo
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to perform FW driven Rx calibration

   \param 

   pAsyncHandlerSigGenCB = Callback delegate to communicate to QSPR
   an OFDM signal transmit request. 

   pAsyncHandlerRxGainCalDoneCB = Callback delegate to communicate 
   to QSPR that test is complete.


   \return true if successful, false if failure
   *******************************************************************************/


   QLIB_API unsigned char  QLIB_FTM_WLAN_Atheros_Rx_FW_CAL
   (
       HANDLE hResourceContext,
       asyncHandlerSG_CB pAsyncHandlerSigGenCB,
       asyncHandlerRxGainCalDoneCB pAsyncHandlerRxGainCalDoneCB,
       unsigned int radioId,
       unsigned int chainToCalibrate

       
   );



   /******************************************************************************/
   /**

   Atheros WLAN command to run transmit calibration for selected chain and channel

   Note: (Current supported chip set: QC98xx, AR6004)
       For QC98xx calibration, this cmd must be called after loading chip specified DLL 
         by calling QLIB_FTM_WLAN_Atheros_LoadDUT().

   \param 
             iFreq = Transmit Frequency in MHz or Channel number
                For example, 2412 for channel 1 in 802.11g, or 1

         iDataRate =  calibration data rate
            (Please refer iDataRate definition in QLIB_FTM_WLAN_Atheros_Tx for the rate specifiers for both QC98xx, AR6004)

      iTxChainMask = Tx chain mask, single chain only for calibration
                 1: chain0
                 2: chain1
                 4: chain2

          iPktSz = packet size, default is 1500.  Vary from 1-32768

       *pdTxPwrGoal = Array of tx target power goals and results in dBm. 
             Input: Array of tx target power goals in dBm.
            Output: Final calibrated power in dBm.
                  Array size must be 2 for 2 point cal, etc.

    *pdDeltaTxPwrGoal = Array of allowed power deviation between final calibrated power and target power goal in dBm. 
                  Array size must be 2 for 2 point cal, etc.

           dSlope = Gain slope.

     *piMaxIteration = Array of maximum iteration numbers for each calibration point.
                  Array size must be 2 for 2 point cal, etc.

            *piGain = Array of initial calibration gain settings and results.
             Input: Array of initial calibration gain settings.
            Output: Array of final calibrated gain settings.

                  Initial txgain and result for 1 point calibration 
                  Initial gainIndex and result for 2 points calibration.
                  Array size must be 2 for 2 point cal, etc.
                  For 2 point cal, in QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_INIT(), 
                  If calGainMode = 0 then 
                  The second element of *piGain in QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE() is an absolute gainIndex.
                  If calGainMode = 1 then
                  The second element of *piGain in QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE() is a delta from the first 
                  calibrated gain index value.

         *piDacGain = Array of initial dacGain and result for 2 point calibration. (For 2 point calibration only.)
             Input: Array of initial dacGain for 2 point calibration.
            Output: Array of final calibrated dacGain for 2 point calibration.

           numAvg = Number of average for each power measurement.

   pAsyncPMMessageCB = Call back delegate for power measurement.

         *piThermCal = Pointer for returned thermal temperature measurement.

       *piCorrection = Pointer for returned calculated calibration correction coefficient. 
                  For 1 point calibration only.

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_INIT() must be called first for running calibration.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE
   (
   HANDLE hResourceContext,
   unsigned long iFreq, 
   unsigned long iDataRate, 
   unsigned long iTxChainMask, 
   unsigned long iPktSz,
   double *pdTxPwrGoal, 
   double *pdDeltaTxPwrGoal, 
   double dSlope, 
   unsigned long *piMaxIteration,
   unsigned long *piGain, 
   long *piDacGain, 
   unsigned long iNumAvg, 
   asyncPMMessageCB pAsyncPMMessageCB,
   unsigned long *piThermCal, 
    long *piCorrection
   );


   /******************************************************************************/
   /**

   Atheros WLAN command to run transmit calibration for selected chain and channel

   Note: (Current supported chip set: AR6006)

   \param 
             iFreq = Transmit Frequency in MHz or Channel number
                For example, 2412 for channel 1 in 802.11g, or 1

         iDataRate =  calibration data rate
            (Please refer iDataRate definition in QLIB_FTM_WLAN_Atheros_Tx for the rate specifiers for both QC98xx, AR6004)

      iTxChainMask = Tx chain mask, single chain only for calibration
                 1: chain0
                 2: chain1
                 4: chain2

          iPktSz = packet size, default is 1500.  Vary from 1-32768

       *pdTxPwrGoal = Array of tx target power goals and results in dBm. 
             Input: Array of tx target power goals in dBm.
            Output: Final calibrated power in dBm.
                  Array size must be 2 for 2 point cal, etc.

    *pdDeltaTxPwrGoal = Array of allowed power deviation between final calibrated power and target power goal in dBm. 
                  Array size must be 2 for 2 point cal, etc.

           dSlope = Gain slope.

     *piMaxIteration = Array of maximum iteration numbers for each calibration point.
                  Array size must be 2 for 2 point cal, etc.

            *piGain = Array of initial calibration gain settings and results.
             Input: Array of initial calibration gain settings.
            Output: Array of final calibrated gain settings.

                  Initial txgain and result for 1 point calibration 
                  Initial gainIndex and result for 2 points calibration.
                  Array size must be 2 for 2 point cal, etc.
                  For 2 point cal, in QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_INIT(), 
                  If calGainMode = 0 then 
                  The second element of *piGain in QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE() is an absolute gainIndex.
                  If calGainMode = 1 then
                  The second element of *piGain in QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE() is a delta from the first 
                  calibrated gain index value.

         *piDacGain = Array of initial dacGain and result for 2 point calibration. (For 2 point calibration only.)
             Input: Array of initial dacGain for 2 point calibration.
            Output: Array of final calibrated dacGain for 2 point calibration.

           numAvg = Number of average for each power measurement.

   pAsyncPMMessageCB = Call back delegate for power measurement.

         *piThermCal = Pointer for returned thermal temperature measurement.

       *piCorrection = Pointer for returned calculated calibration correction coefficient. 
                  For 1 point calibration only.

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_INIT() must be called first for running calibration.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_V1
   (
   HANDLE hResourceContext,
   unsigned long iFreq, 
   unsigned long iDataRate, 
   unsigned long iTxChainMask, 
   unsigned long iPktSz,
   double *pdTxPwrGoal, 
   double *pdDeltaTxPwrGoal, 
   double dSlope, 
   unsigned long *piMaxIteration,
   unsigned long *piGain, 
   long *piDacGain, 
   unsigned long iNumAvg, 
   asyncPMMessageCB pAsyncPMMessageCB,
   unsigned long *piThermCal, 
   long *piCorrection
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to run transmit calibration for selected chain and channel

   Note: (Current supported chip set: QC98xx, AR6004)
       For QC98xx calibration, this cmd must be called after loading chip specified DLL 
         by calling QLIB_FTM_WLAN_Atheros_LoadDUT() and QLIB_FTM_WLAN_TLV_Create() _OP_CAL_INIT=23 called.

   \param 

   pAsyncPMMessageCB = Call back delegate for power measurement.

   measAvg = number of average power measurements.

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Tx_CAL
   (
   HANDLE hResourceContext,
   asyncPMMessageCB pAsyncPMMessageCB,
   unsigned int measAvg
   );

   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Gen_UTF_Cmd
   (
      HANDLE hResourceContext,
      unsigned int utfCmd,
      unsigned int inParams[],
      int iLen,
      unsigned int outParams[],
      int oLen[],
      unsigned int measurementCbType,
      asyncPMMessageCB cbPm,
      asyncCWFreqErrMessageCB cbFr,
      asyncDbgMessageCB cbDbg,
      int status[]
   );

   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Qmsl_Msg_Callback
   (
      HANDLE hResourceContext,
      asyncQmslMessageCB cbMsg
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to run transmit SCPC calibration for selected chain and channel

   Note: (Current supported chip set: QC6174)
       For QC6174 calibration, this cmd must be called after loading chip specified DLL 
         by calling QLIB_FTM_WLAN_Atheros_LoadDUT() and QLIB_FTM_WLAN_TLV_Create() _OP_CAL_INIT=23 called.

   \param 

   pAsyncPMMessageCB = Call back delegate for power measurement.

   measAvg = number of average power measurements.

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_TxSCPC_CAL
   (
   HANDLE hResourceContext,
   asyncPMMessageCB pAsyncPMMessageCB,
   unsigned int measAvg
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to run transmit SCPC PSATADJUST calibration for selected chain and channel

   Note: (Current supported chip set: QC6174)
       For QC6174 calibration, this cmd must be called after loading chip specified DLL 
         by calling QLIB_FTM_WLAN_Atheros_LoadDUT() and QLIB_FTM_WLAN_TLV_Create() _OP_CAL_INIT=23 called.

   \param 

   pAsyncPMMessageCB = Call back delegate for power measurement.

   measAvg = number of average power measurements.

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_TxSCPC_PSATADJUST_CAL
   (
   HANDLE hResourceContext,
   asyncPMMessageCB pAsyncPMMessageCB,
   unsigned int measAvg
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to run transmit calibration for selected chain and channel

   Note: (Current supported chip set: QC6174)
       For QC6174 xtal calibration, this cmd must be called after loading chip specified DLL 
         by calling QLIB_FTM_WLAN_Atheros_LoadDUT() and QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_INIT() called.

   \param 

   pAsyncCWFreqErrMessageCB = Call back delegate for CW Freq Error measurement.

   measAvg = number of average power measurements.

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_xtal_CAL
   (
   HANDLE hResourceContext,
   asyncCWFreqErrMessageCB pAsyncCWFreqErrMessageCB,
   unsigned int measAvg
   );


   /******************************************************************************/
   /**
   Atheros WLAN command to run offline SAT power measurement for SelfInitCalibration.

   Note: This cmd works only when target is awake.
       (Current supported chip set: AR6004)
       This cmd must be called after calling QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_INIT().

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SELF_CAL_MEAS
   (
   HANDLE hResourceContext,
   unsigned long iFreq, 
   unsigned long iTxChainMask,
   unsigned long iNumAvg, 
   unsigned long iPSatDAC, 
   double dTargetPower, 
   asyncPMMessageCB pAsyncPMMessageCB, 
   double *pdPSatPwr, 
   double *pdPSatOfdmDelta, 
   unsigned long *iThermCal
   );

   /******************************************************************************/
   /**
   Atheros WLAN command to complete SelfInitCalibration.

   Note: This cmd works only when target is awake.
       (Current supported chip set: AR6004)

   \param SelfInitSetUpFName =   Self Init calibration setup file name (less than 254 charactors)
               if no directory specified in the name, default path will be used ./../driver/boardData/
               ./ is where QMSL dll running.

   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SELF_CAL_SETUP
   (
   HANDLE hResourceContext,
   char *SelfInitSetUpFName
   );

   /******************************************************************************/
   /**
   Atheros WLAN command to complete SelfInitCalibration.

   Note: This cmd works only when target is awake.
       (Current supported chip set: AR6004)
       This cmd must be called after calling QLIB_FTM_WLAN_Atheros_LoadDUT().

   \param binFName = Self Init calibration bin file name (less than 254 charactors)
      if no directory specified in the name, default path will be used ./../driver/boardData/
      ./ is where QMSL dll running.


   \return true if successful, false if failure
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SELF_CAL_toBin
   (
   HANDLE hResourceContext,
   char *binFName
   );

   /******************************************************************************/
   /**
   Atheros WLAN command to complete Calibration.

   Note: This cmd works only when target is awake.
       (Current supported chip set: QC98xx, AR6004)

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE() must be called first to perform calibration.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_Done
   (
   HANDLE hResourceContext
   );

   /******************************************************************************/
   /**
   Atheros WLAN command to commit memory data structure into file/otp/eep

   Note: This cmd works only when target is awake.
       This cmd may be called after calling QLIB_FTM_WLAN_Atheros_Tx_CALIBRATE_Done(),
       if user wants to commite calibrated data into selected memory.
       (Current supported chip set: QC98xx, AR6004)

   \param 
             iTemplateNum = Design memory template number
                      0: AR6004
                     20: QC98xx
                     21: CUS220
                     22: CUS223
                     23: WB342
                     24: XB340
                     25: CUS226
                     26: CUS226_030
                     27: XB141

             iWriteOption = memory type for calibration data
                     0: auto;
                     1: flash; 
                     2: eeprom; 
                     3: otp; 
                     4: none; 
                     5: file; 

             iMemSize = memory size used for calibration data
                     0: auto; 
                     1: 1024(1k); 
                     2: 2048(2k); 
                     3: 4096(4k); 
                     4: 8192(8k);

             iCompress = use compression?
                     0: No
                     1: Yes
                     (For QC98XX, must be yes if using OTP.)

             iOverwrite = overwrite existing data?
                     0: No
                     1: Yes   (Not applicable for OTP)

             iSectionMask = section(s) to commit
                     0: all sections; 
                     1: ID; 
                     2: MAC addr.; 
                     3: 2G cal data; 
                     4: 5G cal data; 
                     5: 2G control data; 
                     6: 5G control data; 
                     7: config data; 
                     8: customer data; 
                     9: usb VID and PID; 
                     10:sdio PID(13 bits)
                     (This is supported for QC98XX only, set to 0 for others)

   \return true if successful, false if failure
   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_MEM_COMMIT
   (
      HANDLE hResourceContext,
      unsigned char iTemplateNum, 
      unsigned char iWriteOption, 
      unsigned long iMemSize,
      unsigned char iCompress, 
      unsigned char iOverwrite, 
      unsigned long iSectionMask  
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to enable continuous receive

   Note: Enable/disable continuous receive cmd works only when target is awake.
       (Current supported chip set: AR6004)

   \param iAction =   set promiscuous mode or not
            0 = promiscuous mode (accept all incoming frames)
               1 = filter mode (accept only frames with dest address equal specified mac address

         iEnANI = Disable/Enable Anti-noise immunity (ANI) algorithm
             0 = Anti-noise immunity (ANI) algorithm is disabled
                1=  Anti-noise immunity (ANI) algorithm is enabled

         iFreq = Receive Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

       iAntenna = Antenna to use for Rx.
              1: antenna one, etc.

      iRxChainMask = Rx chain mask 
                 1: chain0
                 2: chain1
                 3: chain0 and chain1
                 4: chain2
                 5: chain0 and chain2
                 7: all 3 chains on

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Rx
   (
      HANDLE hResourceContext,
      unsigned long iAction,
      unsigned long iEnANI,
      unsigned long iFreq,
      unsigned long iAntenna,
      unsigned long iRxChainMask
   );

   /******************************************************************************/
   /**
   Atheros WLAN command to setup continuous receive

   Note: Enable/disable continuous receive cmd works only when target is awake.
       This cmd must be called after loading chip specified DLL by calling QLIB_FTM_WLAN_Atheros_LoadDUT().
       (Current supported chip set: None, reserved API for future)

   \param 
         iFreq = Receive Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

       iAntenna = Antenna to use for Rx.
              1: antenna one, etc.

      iRxChainMask = Rx chain mask 
                 1: chain0
                 2: chain1
                 3: chain0 and chain1
                 4: chain2
                 5: chain0 and chain2
                 7: all 3 chains on

      piRate:  Pointer to an array of Rx rates
            (Please refer iDataRate definition in QLIB_FTM_WLAN_Atheros_DevTx for the rate specifiers.)
   
      iNRate: Rx Rate Array Size
            = 1 (For current release iNRate always set to 1, reserved for future.)

      iWlanMode = WLAN channel mode:
                     0: NOHT
                     1: HT20 (20Mhz channel BW)
                     2: HT40PLUS 
                     3: HT40MINUS 
                  4: CCK
                  5: VHT20
                  6: VHT40Plus
                  7: HT40MINUS
                  8: VHT80

      iPromiscuous =   0: promiscuous mode (accept all incoming frames)
                     1: filter mode (accept only frames with dest address equal specified mac address

      iBroadcast = 0: unicast
                1: broadcast

      piBSSID: 6 byte BSSID address

      piDestination: 6 byte Destination address

      iNumDescPerRate: number of packets to be received for each rate (1-2147483647)

      iDatacheck: datacheck (not used)

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_DevRxSetUp
   (
      HANDLE hResourceContext,
     int iFreq, 
     int iAntenna, 
     int iRxChainMask, 
     int *piRate, 
     int iNRate, 
     int iWlanMode,  
     int iPromiscuous, 
     int iBroadcast, 
     unsigned char aiBSSID[6], 
     unsigned char aiDestination[6], 
     int iNumDescPerRate, 
     int iDatacheck
   );

    /******************************************************************************/
   /**

   Atheros WLAN command to enable continuous receive

   \param iAction =   0 = promiscuous mode (accept all incoming frames)
               1 = filter mode (accept only frames with dest address equal specified mac address

         iEnANI = 0 = Anti-noise immunity (ANI) algorithm is disabled
                1=  Anti-noise immunity (ANI) algorithm is enabled

         iFreq = Receive Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

      iWlanMode = HT20/40 setting 0: noneHT; 1: HT20; 2: HT40PLUS, 3: HT40MINUS

         iAntenna 1 = antenna one
             2 = antenna two

         iRxChain 1 = rx chain one
             2 = rx chain two


   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Rx_HT
   (
      HANDLE hResourceContext,
      unsigned long iAction,
      unsigned long iEnANI,
      unsigned long iFreq,
     unsigned long iWlanMode,
      unsigned long iAntenna,
      unsigned long iRxChain
   );
   /******************************************************************************/
   /**

   Atheros WLAN FW command to get receive report

   Note: This cmd works only when target is awake.
       This cmd must be called after calling QLIB_FTM_WLAN_Atheros_Rx()
       (Current supported chip set: AR6004)

   \param iTotalPkt =   Total packet received

         iRSSIinDbm = RSSI in dBm

         iCRCErrPkt = CRC Error Pkt

         iSECErrPkt = SEC Error Pkt

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Rx_Report
   (
      HANDLE hResourceContext,
      unsigned long* iTotalPkt,
      double*       rssi,
      unsigned long* iCRCErrPkt,
      unsigned long* iSECErrPkt
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW command to get receive report

   Note: This cmd works only when target is awake.
       This cmd must be called after loading chip specified DLL by calling QLIB_FTM_WLAN_Atheros_LoadDUT().
       This cmd must be called after calling QLIB_FTM_WLAN_Atheros_DevRxSetUp()
       (Current supported chip set: None, reserved API for future)

   \param 
        iTotalPkt =   Total packet received

         iRSSIinDbm = RSSI in dBm

         iCRCErrPkt = CRC Error Pkt

         iSECErrPkt = SEC Error Pkt

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_DevRx_Report
   (
      HANDLE hResourceContext,
      unsigned long* iTotalPkt,
      double*       rssi,
      unsigned long* iCRCErrPkt,
      unsigned long* iSECErrPkt
   );


      /******************************************************************************/
   /**

   Atheros WLAN FW command to read a register

   Note: This cmd works only when target is awake.
       (Current supported chip set: AR6004)

   \param   iRegAddr  = register address

            piRegValue = pointer to the register value read from register

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_ReadReg
   (
      HANDLE hResourceContext,
      unsigned long iRegAddr,
      unsigned long* piRegValue
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW command to write a register

   Note: This command works only when target is awake.
       (Current supported chip set: AR6004)

   \param   iRegAddr  = register address

            iRegValue = register value to be written

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_WriteReg
   (
      HANDLE hResourceContext,
      unsigned long iRegAddr,
      unsigned long iRegValue
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW command for reading data from OTP into a user supplied buffer.
   Maximum of 8 bytes can be read

   Note: This command works only when target is awake.
       (Current supported chip set: AR6004)

   \param   iOffset_OTP =   offset from start of OTP

         piLength_OTP =   pointer to count of number of bytes to read, will be updated with 
                        number of bytes actually read on return.

            piDataBuf_OTP =   pointer to OTP output data buffer, to be fill with bytes read
         
   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_ReadSegmentOTP
   (
      HANDLE hResourceContext,
     unsigned long iOffset_OTP,
     unsigned long* piLength_OTP,
     unsigned char* piDataBuf_OTP
   );

   /******************************************************************************/
   /**

   Atheros WLAN command for reading data from OTP and writing to a file.

   Note: This command works only when target is awake.
       (Current supported chip set: QCA6174)

   \param    piFilename =   Filename to save data to
         
   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_DumpOTPToFile
   (
       HANDLE hResourceContext,
      char *piFilename
   );

   /******************************************************************************/
   /**

   Atheros WLAN command for reading data from OTP and compare against the data 
   in the provided file, previously created by calling FTM_WLAN_Atheros_DumpOTPToFile.

   Note: This command works only when target is awake.
       (Current supported chip set: QCA6174)

   \param    piFilename =   Filename containing the saved data for comparison

   \param    piResultsFilename = Name of File to print detailed results to

   \param    iResults = High level result returned, 0 if compare is pass, 1 if compare failed 
         
   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_CompareOTPAgainstFile
   (
      HANDLE hResourceContext,
       char *piFilename, 
      char *piResultsFilename, 
      unsigned int *iResults
   );


#if 1
// NOTE: This section ( inside the second #if 0 and #endif pair ) was extracted from Qlib.h
//       and it is completely removed from Qlib.h. Re-place this section in Qlib.h
//       when writing to OTP capability shall be allowed.
  /******************************************************************************/
   /**

   Atheros WLAN FW command for writing data to OTP from the user supplied buffer.  
   Maximum of 8 bytes can be written

   Note: This cmd works only when target is awake.
       (Current supported chip set: AR6004)

   \param   iOffset_OTP =   offset from start of OTP

         piLength_OTP =   pointer to count of the number of bytes to be written

            piDataBuf_OTP =   pointer to OTP input data buffer containing bytes to write

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_WriteSegmentOTP
   (
      HANDLE hResourceContext,
      unsigned long iOffset_OTP,
     unsigned long* piLength_OTP,
     unsigned char* piDataBuf_OTP
   );
#endif

   /******************************************************************************/
   /**

   Atheros WLAN FW command to read a data buffer from OTP

   Note: This cmd works only when target is awake.
       (Current supported chip set: AR6004)

   \param   piLength_OTP =   number of bytes to read

            piDataBuf_OTP =   OTP output data buffer pointer

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_ReadOTP
   (
      HANDLE hResourceContext,
     unsigned long* piLength_OTP,
     unsigned char* piDataBuf_OTP
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW command to write a data buffer to OTP

   Note: This cmd works only when target is awake.
       (Current supported chip set: AR6004)

   \param   piLength_OTP =   number of bytes to write

            piDataBuf_OTP = OTP input data buffer pointer

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_WriteOTP
   (
      HANDLE hResourceContext,
     unsigned long* piLength_OTP,
     unsigned char* piDataBuf_OTP
   );

   /******************************************************************************/
   /**

   Atheros WLAN Load design specific Ref file.

   Note: This command must be called after loading chip specified DLL by calling QLIB_FTM_WLAN_Atheros_LoadDUT().
       (Current supported chip set: None, reserved API for future)

   \param   piRefFilePath = the path for designed specified .ref file located. (Less than 256 charachers)

            piRefFileName = the file name for designed specified .ref file located. (Less than 30 charachers)

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_LoadREF
   (
      HANDLE hResourceContext,
      const char* piRefFilePath,
     const char* piRefFileName
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to enable/disable continuous transmit

   Note: Enable/disable continuous tx test cmd works only when target is awake.

   \param iMode =   0 = Disabling continuous Tx,
               1 = Enabling continuous unmodulated Tx
               2 = Enabling continuous modulated Tx

         iFreq = Transmit Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

         iDataRate =  0 - 1 Mbps
                  1 - 2 Mbps
                  2 - 5.5 Mbps
                  3 - 11 Mbps
                  4 - 6 Mbps
                  5 - 9 Mbps
                  6 - 12 Mbps
                  7 - 18 Mbps
                  8 - 24 Mbps
                  9 - 36 Mbps
                  10 - 48 Mbps
                  11 - 54 Mbps

        iTxPwr = Tx Power in dBm
               5 - 11 dBm for unmodulated Tx
               5 - 14 dBm for modulated Tx

         iAntenna 1 = antenna one
                 2 = antenna two

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_CONT_TRANSMIT
   (
      HANDLE hResourceContext,
      unsigned long iMode,
      unsigned long iFreq,
      unsigned long iDataRate,
      unsigned long iTxPwr,
      unsigned long iAntenna
   );


   /******************************************************************************/
   /**

   Atheros WLAN command to enable continuous receive

   \param iAction =   0 = promiscuous mode (accept all incoming frames)
               1 = filter mode (accept only frames with dest address equal specified mac address

         iFreq = Receive Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

         iAntenna 1 = antenna one
                 2 = antenna two

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_CONT_RECEIVE
   (
      HANDLE hResourceContext,
      unsigned long iAction,
      unsigned long iFreq,
      unsigned long iAntenna
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to get receive report

   \param iTotalPkt =   Total packet received

         iRSSI = RSSI

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_RECEIVE_REPORT
   (
      HANDLE hResourceContext,
      unsigned long* iTotalPkt,
      unsigned long* iRSSI
   );
   /******************************************************************************/
   /**

   Atheros WLAN command to set MAC address

   \param iMAC_Address  =   MAC address

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SET_MAC_ADDRESS
   (
      HANDLE hResourceContext,
      unsigned char aiMAC_Address[6]
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to force SLEEP or AWAKE

   \param iMode  =   1 = Wake up target
               2 = Force the target to sleep

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SLEEP_WAKE
   (
      HANDLE hResourceContext,
      unsigned char iMode
   );

   /******************************************************************************/
   /**

   Atheros WLAN command to force SLEEP or AWAKE

   \param iMode  =   1 = Wake up target
               2 = Force the target to sleep
               3 = Force the target into deep sleep

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V3_SLEEP_WAKE
   (
      HANDLE hResourceContext,
      unsigned char iMode
   );
   /******************************************************************************/
   /**

   Atheros WLAN command to load or unload Wlan driver

   \param iMode  0 = load driver
               1 = unload driver
               2 = auto load driver

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_Load_Driver
   ( 
   HANDLE hResourceContext,
   unsigned char iSubMode
   );
   /******************************************************************************/
   /**

   Atheros WLAN FW V2 command to enable/disable continuous transmit

   Note: Enable/disable continuous tx test cmd works only when target is awake.

   \param iMode =   0 = Disabling continuous Tx,
               1 = Enabling continuous unmodulated Tx
               2 = Enabling continuous modulated Tx

         iFreq = Transmit Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

         iDataRate =  0 - 1 Mbps
                  1 - 2 Mbps
                  2 - 5.5 Mbps
                  3 - 11 Mbps
                  4 - 6 Mbps
                  5 - 9 Mbps
                  6 - 12 Mbps
                  7 - 18 Mbps
                  8 - 24 Mbps
                  9 - 36 Mbps
                  10 - 48 Mbps
                  11 - 54 Mbps

        iTxPwr = Tx Power in dBm
               5 - 11 dBm for unmodulated Tx
               5 - 14 dBm for modulated Tx

         iAntenna 1 = antenna one
                 2 = antenna two

        iEnANI = 0 = Anti-noise immunity (ANI) algorithm is disabled
               1=  Anti-noise immunity (ANI) algorithm is enabled

        iScramblerOff = 1 Scrambler is disabled
                  = 0 Scrambler is enabled.  Scrambler is used with CCK frames

         iAifsn = value from 0 to 252,

         iPktSz = packet size, default is 1500.  Vary from 32 to 1500

         iTxPattern = Applies to CONT_TX_TX99, CONT_TX_TX100, and CONT_TX_MODE

            ZEROES_PATTERN = 0,
            ONES_PATTERN,
            REPEATING_10,
            PN7_PATTERN,
            PN9_PATTERN,
            PN15_PATTERN



   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V2_CONT_TRANSMIT
   (
      HANDLE hResourceContext,
      unsigned long iMode,
      unsigned long iFreq,
      unsigned long iDataRate,
      unsigned long iTxPwr,
      unsigned long iAntenna,
      unsigned long iEnANI,
      unsigned long iScramblerOff,
      unsigned long iAifsn,
      unsigned short  iPktSz,
      unsigned short  iTxPattern
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V3 command to enable/disable continuous transmit

   Note: Enable/disable continuous tx test cmd works only when target is awake.

   \param iMode =      0: TX_OFF
                  1: TX_SINE
                  2: TX_FRAME
                  3: TX_TX99
                  4: TX100


         iFreq = Transmit Frequency in MHz or Channel number
                 For example, 2412 for channel 1 in 802.11g, or 1

         iDataRate =  0 - 1 Mbps
                  1 - 2 Mbps
                  2 - 5.5 Mbps
                  3 - 11 Mbps
                  4 - 6 Mbps
                  5 - 9 Mbps
                  6 - 12 Mbps
                  7 - 18 Mbps
                  8 - 24 Mbps
                  9 - 36 Mbps
                  10 - 48 Mbps
                  11 - 54 Mbps
                  12 - HT20 MCS0 6.5 Mbps
                  13 - HT20 MCS1 13  Mbps
                  14 - HT20 MCS2 19.5  Mbps
                  15 - HT20 MCS3 26  Mbps
                  16 - HT20 MCS4 39  Mbps
                  17 - HT20 MCS5 52  Mbps
                  18 - HT20 MCS6 58.5  Mbps
                  19 - HT20 MCS7 65  Mbps
                  20 - HT40 MCS0 13.5  Mbps
                  21 - HT40 MCS1 27.0  Mbps
                  22 - HT40 MCS2 40.5  Mbps
                  23 - HT40 MCS3 54  Mbps
                  24 - HT40 MCS4 81  Mbps
                  25 - HT40 MCS5 108  Mbps
                  26 - HT40 MCS6 121.5  Mbps
                  27 - HT40 MCS7 135  Mbps

        iTxPwr = Tx Power in dBm (0.5 dBm steps)

         iAntenna 1 = antenna one
                 2 = antenna two

        iEnANI = 0 = Anti-noise immunity (ANI) algorithm is disabled
               1 = Anti-noise immunity (ANI) algorithm is enabled

        iScramblerOff = 1 Scrambler is disabled
                  = 0 Scrambler is enabled.  Scrambler is used with CCK frames

         iAifsn = value from 0 to 252,

         iPktSz = packet size, default is 1500.  Vary from 32 to 1500

         iTxPattern = Applies to CONT_TX_TX99, CONT_TX_TX100, and CONT_TX_MODE

            0: ZEROES_PATTERN
            1: ONES_PATTERN
            2: REPEATING_10
            3: PN7_PATTERN
            4: PN9_PATTERN
            5: PN15_PATTERN

         iShortGuard = 1: Use short guard band, 0: Don't use

         iNumPackets = number of packets to send, 0-65535

         iWlanMode = WLAN channel mode:

            0: NOHT
            1: HT20 (20Mhz channel BW)
            2: HT40PLUS (40MHz channel, primary channel high)
            3: HT40MINUS (40MHz channel, primary channel low)


   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V3_CONT_TRANSMIT(
      HANDLE hResourceContext,
      unsigned long  iMode,
      unsigned long  iFreq,
      unsigned long  iDataRate,
      unsigned long  iTxPwr,
      unsigned long  iAntenna,
      unsigned long  iEnANI,
      unsigned long  iScramblerOff,
      unsigned long  iAifsn,
      unsigned long  iPktSz,
      unsigned long  iTxPattern,
      unsigned long  iShortGuard,
      unsigned long  iNumPackets,
      unsigned long  iWlanMode);

   /******************************************************************************/
   /**

   Atheros WLAN FW V4 command to enable/disable continuous transmit

   Note: Enable/disable continuous tx test cmd works only when target is awake.

   \param iMode =      0: TX_OFF
                  1: TX_SINE
                  2: TX_FRAME
                  3: TX_TX99
                  4: TX100


         iFreq = Transmit Frequency in MHz or Channel number
                 For example, 2412 for channel 1 in 802.11g, or 1

         iDataRate =  0 - 1 Mbps
                  1 - 2 Mbps
                  2 - 5.5 Mbps
                  3 - 11 Mbps
                  4 - 6 Mbps
                  5 - 9 Mbps
                  6 - 12 Mbps
                  7 - 18 Mbps
                  8 - 24 Mbps
                  9 - 36 Mbps
                  10 - 48 Mbps
                  11 - 54 Mbps
                  12 - HT20 MCS0 6.5 Mbps
                  13 - HT20 MCS1 13  Mbps
                  14 - HT20 MCS2 19.5  Mbps
                  15 - HT20 MCS3 26  Mbps
                  16 - HT20 MCS4 39  Mbps
                  17 - HT20 MCS5 52  Mbps
                  18 - HT20 MCS6 58.5  Mbps
                  19 - HT20 MCS7 65  Mbps
                  20 - HT40 MCS0 13.5  Mbps
                  21 - HT40 MCS1 27.0  Mbps
                  22 - HT40 MCS2 40.5  Mbps
                  23 - HT40 MCS3 54  Mbps
                  24 - HT40 MCS4 81  Mbps
                  25 - HT40 MCS5 108  Mbps
                  26 - HT40 MCS6 121.5  Mbps
                  27 - HT40 MCS7 135  Mbps

        dTxPwr = Tx Power in dBm (0.5 dBm steps)

         iAntenna 1 = antenna one
                 2 = antenna two

        iEnANI = 0 = Anti-noise immunity (ANI) algorithm is disabled
               1 = Anti-noise immunity (ANI) algorithm is enabled

        iScramblerOff = 1 Scrambler is disabled
                  = 0 Scrambler is enabled.  Scrambler is used with CCK frames

         iAifsn = value from 0 to 252,

         iPktSz = packet size, default is 1500.  Vary from 32 to 1500

         iTxPattern = Applies to CONT_TX_TX99, CONT_TX_TX100, and CONT_TX_MODE

            0: ZEROES_PATTERN
            1: ONES_PATTERN
            2: REPEATING_10
            3: PN7_PATTERN
            4: PN9_PATTERN
            5: PN15_PATTERN

         iShortGuard = 1: Use short guard band, 0: Don't use

         iNumPackets = number of packets to send, 0-65535

         iWlanMode = WLAN channel mode:

            0: NOHT
            1: HT20 (20Mhz channel BW)
            2: HT40PLUS (40MHz channel, primary channel high)
            3: HT40MINUS (40MHz channel, primary channel low)

         iTpcm = Tx Power Control Mode

            0: Tx Power
            1: Forced Gain
            2: Target Power

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V4_CONT_TRANSMIT(
      HANDLE hResourceContext,
      unsigned long  iMode,
      unsigned long  iFreq,
      unsigned long  iDataRate,
      double  dTxPwr,
      unsigned long  iAntenna,
      unsigned long  iEnANI,
      unsigned long  iScramblerOff,
      unsigned long  iAifsn,
      unsigned long  iPktSz,
      unsigned long  iTxPattern,
      unsigned long  iShortGuard,
      unsigned long  iNumPackets,
      unsigned long  iWlanMode,
      unsigned long  iTpcm);

   /******************************************************************************/
   /**

   Atheros WLAN FW V2 command to enable continuous receive

   \param iAction =   0 = promiscuous mode (accept all incoming frames)
               1 = filter mode (accept only frames with dest address equal specified mac address

         iEnANI = 0 = Anti-noise immunity (ANI) algorithm is disabled
                1=  Anti-noise immunity (ANI) algorithm is enabled

         iFreq = Receive Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

         iAntenna 1 = antenna one
                 2 = antenna two

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V2_CONT_RECEIVE
   (
      HANDLE hResourceContext,
      unsigned long iAction,
      unsigned long iEnANI,
      unsigned long iFreq,
      unsigned long iAntenna
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V3 command to enable continuous receive

   \param iAction =   0 = promiscuous mode (accept all incoming frames)
               1 = filter mode (accept only frames with dest address equal specified mac address

         iEnANI = 0 = Anti-noise immunity (ANI) algorithm is disabled
                1=  Anti-noise immunity (ANI) algorithm is enabled

         iFreq = Receive Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

         iAntenna 1 = antenna one
                 2 = antenna two

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V3_CONT_RECEIVE
   (
      HANDLE hResourceContext,
      unsigned long iAction,
      unsigned long iEnANI,
      unsigned long iFreq,
      unsigned long iAntenna
   );

    /******************************************************************************/
   /**

   Atheros WLAN FW V3 command to enable continuous receive

   \param iAction =   0 = promiscuous mode (accept all incoming frames)
               1 = filter mode (accept only frames with dest address equal specified mac address

         iEnANI = 0 = Anti-noise immunity (ANI) algorithm is disabled
                1=  Anti-noise immunity (ANI) algorithm is enabled

         iFreq = Receive Frequency in MHz
                 For example, 2412 for channel 1 in 802.11g

      iWlanMode = HT20/40 setting 0: noneHT; 1: HT20; 2: HT40PLUS, 3: HT40MINUS

        iAntenna 1 = antenna one
                   2 = antenna two

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V3_CONT_RECEIVE_HT
   (
      HANDLE hResourceContext,
      unsigned long iAction,
      unsigned long iEnANI,
      unsigned long iFreq,
     unsigned long iWlanMode,
      unsigned long iAntenna
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V2 command to get receive report

   \param iTotalPkt =   Total packet received

         iRSSI = RSSI

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V2_RECEIVE_REPORT
   (
      HANDLE hResourceContext,
      unsigned long* iTotalPkt,
      unsigned long* iRSSI
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V4 command to get receive report

   \param iTotalPkt =   Total packet received

         iRSSIinDbm = RSSI in dBm

         iCRCErrPkt = CRC Error Pkt

         iSECErrPkt = SEC Error Pkt

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V4_RECEIVE_REPORT
   (
      HANDLE hResourceContext,
      unsigned long* iTotalPkt,
      double*         iRSSI,
      unsigned long* iCRCErrPkt,
      unsigned long* iSECErrPkt
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V3 command to get receive report

   \param iTotalPkt =   Total packet received

         iRSSI = RSSI

         iCRCErrPkt = CRC Error Pkt

         iSECErrPkt = SEC Error Pkt

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V3_RECEIVE_REPORT
   (
      HANDLE hResourceContext,
      unsigned long* iTotalPkt,
      unsigned long* iRSSI,
      unsigned long* iCRCErrPkt,
      unsigned long* iSECErrPkt
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW command to get therm adc value

   \param iThermAdc = Therm ADC value

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_GET_THERM
   (
      HANDLE hResourceContext,
      unsigned char* iThermAdc
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW command to kickstart self init

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_SELF_INIT_START
   (
     HANDLE hResourceContext
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW command to get self init results

   \param pPSatResultBuffer = Pointer to PSAT_CAL_RESULTS defined in QLib_Defines.h

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_GET_SELF_INIT_RESULT
   (
     HANDLE hResourceContext, 
      void* pPSatResultBuffer
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V3 command to set the RX filtering MAC address

   \param iMAC_Address  =   MAC address

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V3_SET_MAC_ADDRESS
   (
      HANDLE hResourceContext,
      unsigned char aiMAC_Address[6]
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V3 command to set the NIC MAC address

   \param iMAC_Address  =   MAC address

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V3_SET_NIC_MAC_ADDRESS
   (
      HANDLE hResourceContext,
      unsigned char aiMAC_Address[6]
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V3 command to set the cal file index

   \param iMAC_Address  =   MAC address

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V3_SET_CALIBRATION_FILE_INDEX
   (
      HANDLE hResourceContext,
      int calFileIndex
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V2 command to set MAC address

   \param iMAC_Address  =   MAC address

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V2_SET_MAC_ADDRESS
   (
      HANDLE hResourceContext,
      unsigned char aiMAC_Address[6]
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW V2 command to force SLEEP or AWAKE

   \param iMode  =   1 = Wake up target
               2 = Force the target to sleep

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_V2_SLEEP_WAKE
   (
      HANDLE hResourceContext,
      unsigned long iMode
   );

   /******************************************************************************/
   /**

   Atheros WLAN FW command to get spectral scan PSD

   Note: This cmd works only when target is awake.
       This cmd must be called after loading chip specified DLL by calling QLIB_FTM_WLAN_Atheros_LoadDUT().
       This cmd must be called after calling QLIB_FTM_WLAN_Atheros_DevRxSetUp()
       (Current supported chip set: None, reserved API for future)

   \param 
         bandwidthMHz =   receiver bandwith in MHz: 20, 40 or 80

         noisefloor = noise floor in dB (default 5)

         length = number of samples in PSD buffer

         buf = buffer to hold spectral scan data. Should be 512 in length

         freq = buffer to hold spectral scan frequencies relative to baseband in MHz. Should be 512 in length

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_GetSpectralScan
   (
      HANDLE hResourceContext,
      int bandwidthMHz,
      double noisefloor,
      int *length,
      double* ssData,
      double* freq
   );

 /******************************************************************************/
   /**

   Atheros WLAN FW command to get CW Tone RSSI

   Note: This cmd works only when target is awake.
       This cmd must be called after loading chip specified DLL by calling QLIB_FTM_WLAN_Atheros_LoadDUT().
       This cmd must be called after calling QLIB_FTM_WLAN_Atheros_DevRxSetUp()
       (Current supported chip set: None, reserved API for future)

   \param 
      bandwidthMHz =   receiver bandwith in MHz: 20, 40 or 80

         noisefloor = noise floor in dB (default 5)

         cwTone = buffer to hold RSSI

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WLAN_Atheros_CWTone_Rssi
   (
      HANDLE hResourceContext,
     int bandwidthMHz,
     double noisefloor,
      double* csRssi
   );

   /******************************************************************************/
   /**

   Atheros WLAN read XML file and write board data bin file using template file

   \param 
         xmlfileName =   file name of XML file containing NV data

         binfileName = file name of board data bin file to write

         templatefileName = file name of template information

         overwriteAllowed = if true, existing output bin file can be overwritten

         ErrorMessage = Output string containing any error details, 
                        Note: caller must allocate a 256 byte char array for this

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
QLIB_API   unsigned char QLIB_FTM_WLAN_QCA_READ_XML_WRITE_NVBIN
(
   char *xmlfileName, 
   char *binfileName, 
   char *templatefileName,
   unsigned char overwriteAllowed,
   char *ErrorMessage
);


   /******************************************************************************/
   /**

   Atheros WLAN read board data bin file and write XML file using template file

   \param 
         xmlfileName =   file name of XML file containing NV data

         binfileName = file name of board data bin file to write

         templatefileName = file name of template information

         overwriteAllowed = if true, existing output XML file can be overwritten

         ErrorMessage = Output string containing any error details, 
                        Note: caller must allocate a 256 byte char array for this

   \return true if successful, false if failure

   \warning QLIB_FTM_WLAN_SetModuleType() must be called first to set the WLAN module type
   *******************************************************************************/
QLIB_API unsigned char QLIB_FTM_WLAN_QCA_READ_NVBIN_WRITE_XML
(
   char *xmlfileName, 
   char *binfileName, 
   char *templatefileName,
   unsigned char overwriteAllowed,
   char *ErrorMessage
);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_WLAN_ATHEROS_H)
