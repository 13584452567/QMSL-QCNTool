/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Connectivity/inc/QMSL_Connectivity_NFC/QMSL_Connectivity_NFC.h#7 $
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

#if !defined(_QLIB_NFC_H)
#define _QLIB_NFC_H

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
                     NFC FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_SetChipID

   This sets the chip ID in QMSL 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param ChipId = Chip ID (int, 0 - QCA1990, 1- NQ)
  
   \return true if successful, false if fail.

   \warning 

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NFC_SetChipID(
      HANDLE hResourceContext,
      int ChipId);

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_I2C_SLAVE_WRITE

   This allows one to write to I2C devices peripheral to the NFC controller.
      It can NOT be used to perform direct register writes on the I2C slave supporting the NCI interface 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  Nfc_i2c_slave_id = I2C slave address of NFC peripheral device (0 to 127)
   \param  Nfc_nb_reg_writes = number of registers to write (1 to 15)
   \param  pNfc_i2c_reg_addr = I2C register addresses (byte array)
   \param  pNfc_i2c_reg_val  = I2C register values to write (byte array)
   \param  pNfc_i2c_slave_status = returned byte value with command execution status
      \code
         0 = Command executed successfully
         1 = Undefined I2C address on this slave
         2 = Undefined or illegal I2C slave ID
         3 = Illegal state
        255 = Unspecified error
      \endcode

   \return true if successful, false if fail.

   \warning 

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NFC_I2C_SLAVE_WRITE(
         HANDLE hResourceContext, 
         unsigned char   Nfc_i2c_slave_id, 
         unsigned char   Nfc_nb_reg_writes,
         unsigned char* pNfc_i2c_reg_addr, 
         unsigned char* pNfc_i2c_reg_val,
         unsigned char* pNfc_i2c_slave_status);


   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_I2C_SLAVE_READ

   This allows one to read from I2C devices peripheral to the NFC controller.
      It can NOT be used to perform direct register reads on the I2C slave supporting the NCI interface 

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  Nfc_i2c_slave_id = I2C slave address of NFC peripheral device (0 to 127)
   \param  Nfc_nb_reg_reads_in = number of registers to read (1 to 15)
   \param  pNfc_i2c_reg_addr_in = I2C register addresses to read (byte array)
   \param  pNfc_i2c_slave_status = returned byte value with command execution status
      \code
         0 = Command executed successfully
         1 = Undefined I2C address on this slave
         2 = Undefined or illegal I2C slave ID
         3 = Illegal state
        255 = Unspecified error
      \endcode
   \param  pNfc_nb_reg_reads_out = number of registers that were read (1 to 15)
   \param  pNfc_i2c_reg_addr_out = I2C register addresses that were read (byte array)
   \param  pNfc_i2c_reg_val_out  = I2C register values that were read (byte array)

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NFC_I2C_SLAVE_READ(
         HANDLE hResourceContext, 
         unsigned char   Nfc_i2c_slave_id, 
         unsigned char   Nfc_nb_reg_reads_in,
         unsigned char* pNfc_i2c_reg_addr_in,
         unsigned char* pNfc_i2c_slave_status,
         unsigned char* pNfc_nb_reg_reads_out,
         unsigned char* pNfc_i2c_reg_addr_out, 
         unsigned char* pNfc_i2c_reg_val_out
         );


   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_NFCC_CMD_RSP

   This function allows one to send a NCI command to the NFC Controller for execution.
      The NCI command response message will be returned.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param Nfc_nfcc_cmd_len = length of the NCI command (3 to 258)
   \param pNfc_nfcc_cmd = byte array containing NCI command
   \param pNfc_nfcc_rsp_len = length of the NCI command response (3 to 258)
   \param pNfc_nfcc_rsp = byte array returning the NCI command response

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NFC_NFCC_CMD_RSP( 
      HANDLE hResourceContext,
      unsigned short   Nfc_nfcc_cmd_len,
      unsigned char*  pNfc_nfcc_cmd,
       unsigned short* pNfc_nfcc_rsp_len,
       unsigned char*  pNfc_nfcc_rsp
       );


   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_SEND_DATA

   This function allows one to send a NCI data message to the NFCC.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param Nfc_nci_pkt_len = length of the NCI data payload (3 to 258)
   \param pNfc_nci_payload = byte array containing NCI data payload

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NFC_SEND_DATA( 
      HANDLE hResourceContext,
      unsigned short Nfc_nci_pkt_len,
      unsigned char* pNfc_nci_payload
      );


   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_EnableLogs

   This function enables the NFC log packet (0x1802)

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_EnableLogs( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_ClearNtfLogs

   This function clears the buffered NFC log packets

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_ClearNtfLogs( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_GetNumNtfLogs

   This function queries and returns the number of buffered NFC log packets

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return number of buffered NFC log packets

   \warning

   *******************************************************************************/
    QLIB_API unsigned int QLIB_FTM_NFC_GetNumNtfLogs( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_GetOneNtfLog

   This function gets data for one buffered NFC log packet

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param logIndex = index in array of buffered NFC log packets to specify which log packet data to retrieve
   \param pNtf_len = returns length of the specified log packet
   \param pNtfPkt = returns data payload of the specified log packet

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_GetOneNtfLog( 
           HANDLE hResourceContext,
         int logIndex,
         unsigned short* pNtf_len,
         unsigned char* pNtfPkt );


   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_GetAllNtfLogs_String

   This function queries and returns the all the buffered NFC log packets as a string

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sNtfLogs = data payload of the all buffered NFC log packets as a string

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_GetAllNtfLogs_String( HANDLE hResourceContext, char* sNtfLogs );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_SetPollingMode

   This function sends a sequence of NCI commands to setup Polling Mode for Types A, B, and F

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
      \endcode
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_SetPollingMode( HANDLE hResourceContext, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_PollTypeA

   This function sends a sequence of NCI commands to setup Polling Mode for Type A only

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_PollTypeA( HANDLE hResourceContext, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_PollTypeB

   This function sends a sequence of NCI commands to setup Polling Mode for Type B only

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_PollTypeB( HANDLE hResourceContext, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_PollTypeF

   This function sends a sequence of NCI commands to setup Polling Mode for Type F only

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_PollTypeF( HANDLE hResourceContext, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_DetectTag

   After polling mode is enabled, this function can detect a tag and return data about the tag.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sTagType = returns information about the tag as string
   \param piErrorCode
      \code
         0 = Command executed successfully
         1 = NCI command-response failed
        2 = no NCI NTF packets (of any kind) were received
        3 = no RF_INTF_ACTIVATED_NTF packets were received
      \endcode

   \return true if successful, false if fail.

   \warning One of (QLIB_FTM_NFC_SetPollingMode, QLIB_FTM_NFC_PollTypeA, QLIB_FTM_NFC_PollTypeB, QLIB_FTM_NFC_PollTypeF) must be called before this

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_DetectTag( HANDLE hResourceContext, char* sTagType, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_SetListeningMode

   This function sends a sequence of NCI commands to setup Listening Mode for Types A, B, and F

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_SetListeningMode( HANDLE hResourceContext, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_ListenTypeA

   This function sends a sequence of NCI commands to setup Listening Mode for Type A only

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_ListenTypeA( HANDLE hResourceContext, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_ListenTypeB

   This function sends a sequence of NCI commands to setup Listening Mode for Type B only

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_ListenTypeB( HANDLE hResourceContext, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_ListenTypeF

   This function sends a sequence of NCI commands to setup Listening Mode for Type F only

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_ListenTypeF( HANDLE hResourceContext, int* piErrorCode );


   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_DetectField

   After listening mode is enabled, this function tries to detect a field from an external device.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFieldDet = returns information about field detecttion notifications as string
   \param piErrorCode
      \code
         0 = Command executed successfully
         1 = NCI command-response failed
        2 = no NCI NTF packets (of any kind) were received
        3 = no RF_FIELD_INFO_NTF packets were received
        4 = RF_FIELD_INFO_NTF packet(s) were received, but the payload indicated that a field was not detected
      \endcode
   \return true if successful, false if fail.

   \warning One of (QLIB_FTM_NFC_SetListeningMode, QLIB_FTM_NFC_ListenTypeA, QLIB_FTM_NFC_ListenTypeB, QLIB_FTM_NFC_ListenTypeF) must be called before this

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_DetectField( HANDLE hResourceContext, char* sFieldDet, int* piErrorCode );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_ExecuteNciSequenceFile

   This function will parse a text file to extract NCI command sequences and expected NCI responses.
     It will execute the NCI commands and check the responses vs. the expected responses

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sFilename = filename of the file with the NCI sequence
   \param sOutputStr = returns information about the NCI sequence execution as string
   \param piErrorCode = returns code to identify the type of error that may have occured
      \code
         0 = NCI command sequence executed successfully and responses were as expected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = file parsing error, line too short or too few bytes
        4 = file parsing error, line too long or too many bytes
        5 = file parsing error, non-hexadecimal character in data
        6 = file parsing error, number of bytes is inconsistent with nci payload length byte
        7 = could not open file
      \endcode
   \param piErrorLineNum = if there was a file parsing error, this identifies the line number in the text file

   \return true is always returned. otherwise QRCT won't display sOutputStr. piErrorCode must be checked to determine if function was successful

   \warning 

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_ExecuteNciSequenceFile( HANDLE hResourceContext, char* sFilename, char* sOutputStr,  int* piErrorCode, int* piErrorLineNum );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_Turn_Tx_CW_On

   This function enables TX CW

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning This function is not supported on NFC chip versions prior to 2.1

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_Turn_Tx_CW_On( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_Turn_Tx_CW_Off

   This function disables TX CW

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning This function is not supported on NFC chip versions prior to 2.1

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_Turn_Tx_CW_Off( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_SWP1_Detect

   After logs are enabled, this function tries to detect SWP1.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSWP1Detected
      \code
        0 = SWP1 was NOT detected
        1 = SWP1 was detected
        2 = SWP1 connection undetermined (unexpected NFCEE_DISCOVER_NTF payload)
      \endcode
   \param sSWP1Detect = verbose text result output
   \param piErrorCode
      \code
         0 = NCI command sequence executed successfully, responses were as expected, SWP1 detected
         1 = NCI command sequence executed but at least one response was not as expected
         2 = NCI command-response failed
        3 = null device handle
        4 = no NCI NTF packets (of any kind) were received
        5 = no NFCEE_DISCOVER_NTF packets were received
        6 = NFCEE_DISCOVER_NTF packet(s) were received, but the payload indicated that a SWP1 was NOT detected
        7 = NFCEE_DISCOVER_NTF packet(s) were received, but the payload was unexpected

      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_NFC_EnableLogs must be called before this.

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_SWP1_Detect( HANDLE hResourceContext, int* iSWP1Detected, char* sSWP1Detect, int* piErrorCode );


   /******************************************************************************/
   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_Self_Test

   This function runs proprietary self tests to detect SWP1 & SWP2, RF Oscillation, and Carrier Detection

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bCheckSWP1 = Flag to determine whether or not to try to detect SWP1
   \param bCheckSWP2 = Flag to determine whether or not to try to detect SWP2
   \param iRfOscLL = lower test limit for RF Osc count to be used by firmware to determine pass/fail
   \param iRfOscUL = upper test limit for RF Osc count to be used by firmware to determine pass/fail
   \param sTestResult = verbose text result output
   \param piErrorCodeNFCEE = Error Code of NFCEE Controller test
      \code
         0 = Pass
         1 = Fail
         2 = Time Out
        3 = Error
        255 = Results not found
      \endcode
   \param piErrorCodeRFOsc = Error Code of RF Oscillation test
      \code
         0 = Pass
         1 = Fail
         2 = Time Out
        3 = Error
        255 = Results not found
      \endcode
   \param piErrorCodeCarrierDet = Error Code of Carrier Detection test
      \code
         0 = Pass
         1 = Fail
         2 = Time Out
        3 = Error
        255 = Results not found
      \endcode
   \param piNFCEE = Return value of NFCEE Controller test
   \param piRFOsc = Return value of RF Oscillation test
   \param piCarrierDet = Return value of Carrier Detection test
   \return true if successful, false if fail.

   \warning QLIB_FTM_NFC_EnableLogs must be called before this.

   *******************************************************************************/
    QLIB_API unsigned char QLIB_FTM_NFC_Self_Test( 
      HANDLE hResourceContext, 
      unsigned char bCheckSWP1,
      unsigned char bCheckSWP2,
      unsigned int iRfOscLL,
      unsigned int iRfOscUL,
      char* sTestResult,
      unsigned char* piErrorCodeNFCEE,
      unsigned char* piErrorCodeRfOsc,
      unsigned char* piErrorCodeCarrierDet,
      int* piNFCEE,
      int* piRfOsc,
      int* piCarrierDet);

   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_REQ_CHIP_TYPE

   This gets the NFC chipset type from the device

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param ChipType = Returned value for Chip Type ID (0 - QCA1990, 1- NQ)
  
   \return true if successful, false if fail.

   \warning 

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_NFC_REQ_CHIP_TYPE( 
      HANDLE hResourceContext, 
      unsigned char* ChipType );

   /**
   Factory Test Mode NFC Commands, QLIB_FTM_NFC_FWPIN_CTRL

   This sets the FW Pin State for NQ chipsets

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param Fw_PinState = (0 - low, 1- high)
  
   \return true if successful, false if fail.

   \warning 

   *******************************************************************************/
   unsigned char QLIB_FTM_NFC_FWPIN_CTRL( 
      HANDLE hResourceContext, 
      unsigned char Fw_PinState );

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_NFC_H)

