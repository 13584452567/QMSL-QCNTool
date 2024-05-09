/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Connectivity/inc/QMSL_Connectivity_ANT/QMSL_Connectivity_ANT.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_Connectivity_ANT
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QLIB_ANT_H)
#define _QLIB_ANT_H

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
                     ANT FTM
   *******************************************************************************/
   /******************************************************************************/
   /**

   This function will start the ANT Receiver test.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iFrequencyOffset [in] = Frequency offset from the start of band 2400 MHz
   \param dPacketRate [in] = Packet rate in Hz (packets per second)
   \param iNoOfPackets [in] = Number of packets to be received, 0 for continuous receive
   \param iDeviceNumber [in] = Device Number field in ANT Channel ID
   \param iDeviceType [in] = Device Type field in ANT Channel ID
   \param iTransmissionType [in] = Transmission Type field in ANT Channel ID
   \param iDataPayload [in] = 8 byte array containing the data payload to compare with the received data

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ANT_Receiver_Test(HANDLE hResourceContext,
                                   unsigned char iFrequencyOffset,
                                   double dPacketRate,
                                   unsigned short iNoOfPackets,
                           unsigned short iDeviceNumber,
                           unsigned short iDeviceType,
                           unsigned short iTransmissionType,
                                   unsigned char iDataPayload[8]);

   /******************************************************************************/
   /**

   This function will start the ANT Transmitter test.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iFrequencyOffset [in] = Frequency offset from the start of band 2400 MHz
   \param dPacketRate [in] = Packet rate in Hz (packets per second)
   \param iNoOfPackets [in] = Number of packets to be transmitted, 0 for continuous transmit
   \param iDeviceNumber [in] = Device Number field in ANT Channel ID
   \param iDeviceType [in] = Device Type field in ANT Channel ID
   \param iTransmissionType [in] = Transmission Type field in ANT Channel ID
   \param iDataPayload [in] = 8 byte array containing the data payload to transmit

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ANT_Transmitter_Test(HANDLE hResourceContext,
                                   unsigned char iFrequencyOffset,
                                   double dPacketRate,
                                   unsigned short iNoOfPackets,
                           unsigned short iDeviceNumber,
                           unsigned short iDeviceType,
                           unsigned short iTransmissionType,
                                   unsigned char iDataPayload[8]);

   /******************************************************************************/
   /**

   This function will start the ANT Transmitter test at the specified power level.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iFrequencyOffset [in] = Frequency offset from the start of band 2400 MHz
   \param iPowerLevel [in] = Power level 0-3
   \param dPacketRate [in] = Packet rate in Hz (packets per second)
   \param iNoOfPackets [in] = Number of packets to be transmitted, 0 for continuous transmit
   \param iDeviceNumber [in] = Device Number field in ANT Channel ID
   \param iDeviceType [in] = Device Type field in ANT Channel ID
   \param iTransmissionType [in] = Transmission Type field in ANT Channel ID
   \param iDataPayload [in] = 8 byte array containing the data payload to transmit

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ANT_Transmitter_Test_With_Power_Control(HANDLE hResourceContext,
                                   unsigned char iFrequencyOffset,
                           unsigned char iPowerLevel,
                                   double dPacketRate,
                                   unsigned short iNoOfPackets,
                           unsigned short iDeviceNumber,
                           unsigned short iDeviceType,
                           unsigned short iTransmissionType,
                                   unsigned char iDataPayload[8]);

   /******************************************************************************/
   /**

   This function will reset the running ANT Test.

   \param

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ANT_Reset_Test(HANDLE hResourceContext);

   /******************************************************************************/
   /**

   This function will get the final result / current status depending on whether the receiver test is running / completed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param packetsReceived [out] = Number of Packets received
   \param packetsLost [out] = Number of Packets lost
   \param packetsCRCError [out] = Number of Packets with CRC error
   \param totalBitErrors [out] = Total number of bits in error
   \param noOfSyncLosses [out] = Number of times the DUT went out of sync
   \param status [out] = Completion status of test

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ANT_Receiver_Test_Result_Status(HANDLE hResourceContext,
                                  unsigned short* packetsReceived,
                                  unsigned short* packetsLost,
                                  unsigned short* packetsCRCError,
                                  unsigned long* totalBitErrors,
                                  unsigned short* noOfSyncLosses,
                                  unsigned char* status);

   /******************************************************************************/
   /**

   This function will get the final result / current status depending on whether the transmitter test is running / completed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param packetsTransmitted [out] = Number of Packets transmitted
   \param status [out] = Completion status of test

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_ANT_Transmitter_Test_Result_Status(HANDLE hResourceContext,
                                  unsigned short* packetsTransmitted,
                                  unsigned char* status);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_ANT_H)
