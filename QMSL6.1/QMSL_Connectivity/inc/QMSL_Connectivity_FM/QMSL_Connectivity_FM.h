/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Connectivity/inc/QMSL_Connectivity_FM/QMSL_Connectivity_FM.h#8 $
 * $DateTime: 2016/04/04 17:23:23 $
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

#if !defined(_QLIB_FM_H)
#define _QLIB_FM_H

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
                     FM FTM (FM Broadcast Radio)
   *******************************************************************************/

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Enable Receiver

   Powers on and initializes the FM receiver.
      This is an asynchronous command used to power on the FM-RDS receiver.
      If not already enabled, this function will intialize the receiver with default settings.
      Only after successfully calling this function can many of the FM receiver interfaces be used.
      When enabling the receiver, the client must also provide the regional settings in which
      the receiver will operate. These settings are typically used for setting up the FM receiver
      for operating in a particular geographical region. These settings can be later changed through
      the use of the function QLIB_FTM_FM_RX_CONFIGURE_RECEIVER.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRadioBand =
      \code
         0 = FM_US_EUROPE_BAND      ( 87.5 MHz <-> 108 MHz)
         1 = FM_JAPAN_STANDARD_BAND   ( 76   MHz <-> 90 MHz)
         2 = FM_JAPAN_WIDE_BAND      ( 76   MHz <-> 108 MHz)
         3 = FM_USER_DEFINED_BAND   (as defined by parameters iUserDefinedBandFreqMin & iUserDefinedBandFreqMax)
      \endcode
   \param  iEmphasis =
      \code
         0 = FM_DE_EMP75            (pre-emphasis/de-emphasis typically used in the United States and Japan.)
         1 = FM_DE_EMP50            (pre-emphasis/de-emphasis typically used outside of the United states and Japan.)
      \endcode
   \param  iChSpacing =
      \code
         0 = FM_CHSPACE_200_KHZ
         1 = FM_CHSPACE_100_KHZ
         2 = FM_CHSPACE_50_KHZ
      \endcode
   \param  iRdsStd =
      \code
         0 = FM_RDS_STD_RBDS         RBDS mode (Typically used in the United States).
         1 = FM_RDS_STD_RDS         RDS mode (Typically used outside of the United States).
         2 = FM_RDS_STD_NONE         No RDS/RBDS decoding.
      \endcode
   \param  iUserDefinedBandFreqMin = min freq (in KHz) for FM_USER_DEFINED_BAND, must be >= 76000
   \param  iUserDefinedBandFreqMax = max freq (in KHz) for FM_USER_DEFINED_BAND, must be <= 108000 AND > iUserDefinedBandFreqMin

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_ENABLE_RECEIVER( HANDLE hResourceContext,
         unsigned char iRadioBand,
         unsigned char iEmphasis,
         unsigned char iChSpacing,
         unsigned char iRdsStd,
         unsigned long iUserDefinedBandFreqMin,
         unsigned long iUserDefinedBandFreqMax );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Disable Receiver

   Powers off and disables the FM Receiver.
      This is an asynchronous command used to power-off and disable the FM-RDS receiver.
      This function is expected to be used when the client no longer requires use of the FM receiver.
      While powered off, most functionality offered by the FM receiver will also be disabled until
      the client re-enables the receiver again via QLIB_FTM_FM_RX_ENABLE_RECEIVER.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_DISABLE_RECEIVER( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Configure Receiver

   Reconfigures the receiver's regional settings (FM Band, De-Emphasis, Channel Spacing, RDS/RBDS mode).
      This is an asynchronous command used to reconfigure various settings on the FM-RDS receiver.
      These settings typically differ from one geographical region to another.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRadioBand =
      \code
         0 = FM_US_EUROPE_BAND      ( 87.5 MHz <-> 108 MHz)
         1 = FM_JAPAN_STANDARD_BAND   ( 76   MHz <->  90 MHz)
         2 = FM_JAPAN_WIDE_BAND      ( 76   MHz <-> 108 MHz)
         3 = FM_USER_DEFINED_BAND   (as defined by parameters iUserDefinedBandFreqMin & iUserDefinedBandFreqMax)
      \endcode
   \param  iEmphasis =
      \code
         0 = FM_DE_EMP75            (pre-emphasis/de-emphasis typically used in the United States and Japan.)
         1 = FM_DE_EMP50            (pre-emphasis/de-emphasis typically used outside of the United states and Japan.)
      \endcode
   \param  iChSpacing =
      \code
         0 = FM_CHSPACE_200_KHZ
         1 = FM_CHSPACE_100_KHZ
         2 = FM_CHSPACE_50_KHZ
      \endcode
   \param  iRdsStd =
      \code
         0 = FM_RDS_STD_RBDS         RBDS mode (Typically used in the United States).
         1 = FM_RDS_STD_RDS         RDS mode (Typically used outside of the United States).
         2 = FM_RDS_STD_NONE         No RDS/RBDS decoding.
      \endcode
   \param  iUserDefinedBandFreqMin = min freq (in KHz) for FM_USER_DEFINED_BAND, must be >= 76000
   \param  iUserDefinedBandFreqMax = max freq (in KHz) for FM_USER_DEFINED_BAND, must be <= 108000 AND > iUserDefinedBandFreqMin

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_CONFIGURE_RECEIVER( HANDLE hResourceContext,
         unsigned char iRadioBand,
         unsigned char iEmphasis,
         unsigned char iChSpacing,
         unsigned char iRdsStd,
         unsigned long iUserDefinedBandFreqMin,
         unsigned long iUserDefinedBandFreqMax );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM RX Mute Mode

   Allows the muting and un-muting of the audio coming from the FM receiver.
      This is an asynchronous command used to mute or un-mute the FM audio.
      This command mutes the audio coming from the FM device. It is important to note
      that this only affects the FM audio and not any other audio system being used.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRxMute
      \code
         0 = FM_RX_NOMUTE     Unmute both audio channels
         1 = FM_RX_MUTELEFT   Mute only the left audio channel
         2 = FM_RX_MUTERIGHT  Mute only the right audio channel
         3 = FM_RX_MUTEBOTH   Mute both audio channels
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_MUTE_MODE( HANDLE hResourceContext, unsigned char iRxMute);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM RX Stereo Mode


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iStereo
      \code
         0 = FM_RX_AUTO_MONO_STEREO_MODE  Both mono and stereo reception is possible;  The FM hardware will transition to stereo when possible.
         1 = FM_RX_FORCE_MONO_ONLY_MODE   Force mono only reception.
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_STEREO_MODE( HANDLE hResourceContext, unsigned char iStereo);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM RX RF frequency

    Tunes the FM receiver to the supplied FM frequency.
      This is an asynchronous command which tunes the FM receiver to a station as specified
      by the supplied frequency. Only valid frequencies within the band set by
      QLIB_FTM_FM_RX_ENABLE_RECEIVER or QLIB_FTM_FM_RX_CONFIGURE_RECEIVER can be tuned by this function.
      Attempting to tune to frequencies outside of the set band will result in an error.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iFreqkHz =
      \code
         The frequency must be a multiple of 50 KHz and within the band ranges defined below

         FM_US_EUROPE_BAND:
            US/Europe FM band (87500 KHz <-> 108000 KHz)

         FM_JAPAN_STANDARD_BAND:
            Japan Standard Band (76000 KHz <-> 90000 KHz)

         FM_JAPAN_WIDE_BAND
            Japan Wide Band (76000 KHz <-> 108000 KHz)

         FM_USER_DEFINED_BAND
            User defined band ( x KHz <-> y KHz where x < y and x >= 76000 KHz and y <= 108000 KHz)

      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_STATION( HANDLE hResourceContext, unsigned long iFreqkHz );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Get FM RX station parameters

   Returns various statistics related to the currently tuned station.
      This is a synchronous command which returns various statistics related to the currently
      tuned station. Included in these statistics are the currently tuned frequency,
      the RDS/RBDS sync status, the RSSI level, current mute settings and the stereo/mono status.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStationFreq = Returns the currently tuned frequency in KHz
   \param piServAvble = Returns the current service available indicator for the current station
      \code
         0 = FM_RX_SERVICE_NOT_AVAILABLE - No stations were found in the FM band.
         1 = FM_RX_SERVICE_AVAILABLE - At least one station was found in the FM band.
      \endcode
   \param piRssi = Returns the current signal strength level (0-100 range).
      \code
         0 = -120 dBm
         1 = -119 dBm
         2 = -118 dBm
         ...
         100 = -20 dBm
   \param piStereoProgram = Returns the current mono/stereo indicator for this station.
      \code
         0 = FM_RX_MONO_PROGRAM - The currently received audio is mono
         1 = FM_RX_STEREO_PROGRAM - The currently received audio is stereo.
      \endcode
   \param piRdsSyncStatus = Returns the current RDS/RBDS synchronization status
      \code
         0 = FM_RX_NO_RDS_SYNC - No RDS/RBDS decoding possible.
         1 = FM_RX_RDS_SYNC - RDS/RBDS decoding.
      \endcode
   \param piMuteMode = Returns the current FM mute mode.
      \code
         0 = FM_RX_NOMUTE  Un-mute both audio channels
         1 = FM_RX_MUTELEFT - Mute only the left audio channel
         2 = FM_RX_MUTERIGHT - Mute only the right audio channel
         3 = FM_RX_MUTEBOTH - Mute both audio channels
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_GET_STATION_PARAMETERS( HANDLE hResourceContext,
         unsigned long* piStationFreq,
         unsigned char* piServAvble,
         unsigned char* piRssi,
         unsigned char* piStereoProgram,
         unsigned char* piRdsSyncStatus,
         unsigned char* piMuteMode );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set RX RDS Group Options

   This function enables or disables various RDS/RBDS group filtering and buffering features.
      Included in these features are the RDS group enable mask, RDS/RBDS group change filter,
      and the RDS/RBDS group buffer size.
      This is an asynchronous function used to set or unset various Rx RDS/RBDS group filtering
      and buffering options in the FM driver.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iMask = A bitmask of RDS/RBDS groups to enable.
   \param iGroupBufferSize = The number of RDS/RBDS groups to buffer before sending to the client. Max is 21 groups
   \param bChangeFilterEnabled = Flag used to determine whether the RDS/RBDS change filter should be enabled
      \code
         0 = FTM_FM_RX_RDS_CHANGE_FILTER_DISABLED
         1 = FTM_FM_RX_RDS_CHANGE_FILTER_ENABLED
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_RDS_GROUP_OPTIONS(HANDLE hResourceContext,
         unsigned long iMask,
         unsigned long iGroupBufferSize,
         unsigned char bChangeFilterEnabled);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Enable Transmitter

   Powers on and initializes the FM transmitter.
      This is an asynchronous command used to power on the FM-RDS transmitter.
      If not already enabled, this function will intialize the transmitter with default settings.
      Only after successfully calling this function can many of the FM transmitter interfaces be used.
      When enabling the transmitter, the client must also provide the regional settings in which
      the transmitter will operate. These settings are typically used for setting up the FM transmitter
      for operating in a particular geographical region. These settings can be changed through
      the use of the function QLIB_FTM_FM_TX_CONFIGURE_TRANSMITTER.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRadioBand =
      \code
         0 = FM_US_EUROPE_BAND      ( 87.5 MHz <-> 108 MHz)
         1 = FM_JAPAN_STANDARD_BAND   ( 76   MHz <-> 90 MHz)
         2 = FM_JAPAN_WIDE_BAND      ( 76   MHz <-> 108 MHz)
         3 = FM_USER_DEFINED_BAND   (as defined by parameters iUserDefinedBandFreqMin & iUserDefinedBandFreqMax)
      \endcode
   \param  iEmphasis =
      \code
         0 = FM_DE_EMP75            (pre-emphasis/de-emphasis typically used in the United States and Japan.)
         1 = FM_DE_EMP50            (pre-emphasis/de-emphasis typically used outside of the United states and Japan.)
      \endcode
   \param  iChSpacing =
      \code
         0 = FM_CHSPACE_200_KHZ
         1 = FM_CHSPACE_100_KHZ
         2 = FM_CHSPACE_50_KHZ
      \endcode
   \param  iRdsStd =
      \code
         0 = FM_RDS_STD_RBDS         RBDS mode (Typically used in the United States).
         1 = FM_RDS_STD_RDS         RDS mode (Typically used outside of the United States).
         2 = FM_RDS_STD_NONE         No RDS/RBDS decoding.
      \endcode
   \param  iUserDefinedBandFreqMin = min freq (in KHz) for FM_USER_DEFINED_BAND, must be >= 76000
   \param  iUserDefinedBandFreqMax = max freq (in KHz) for FM_USER_DEFINED_BAND, must be <= 108000 AND > iUserDefinedBandFreqMin

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_ENABLE_TRANSMITTER( HANDLE hResourceContext,
         unsigned char iRadioBand,
         unsigned char iEmphasis,
         unsigned char iChSpacing,
         unsigned char iRdsStd,
         unsigned long iUserDefinedBandFreqMin,
         unsigned long iUserDefinedBandFreqMax );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Disable Transmitter

   Powers off and disables the FM transmitter.
      This is an asynchronous command used to power-off and disable the FM transmitter.
      This function is expected to be used when the client no longer needs use of the FM transmitter.
      While powered off, most functionality offered by the FM transmitter will also be disabled until
      the client re-enables the device again via QLIB_FTM_FM_TX_ENABLE_TRANSMITTER.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_DISABLE_TRANSMITTER( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Configure Transmitter

   Reconfigures the transmitters regional settings (FM Band, Pre-emphasis, Channel Spacing, RDS/RBDS mode).
      This is an asynchronous command used to reconfigure various settings of the transmitter.
      These settings typically differ from one geographical region to another.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRadioBand =
      \code
         0 = FM_US_EUROPE_BAND      ( 87.5 MHz <-> 108 MHz)
         1 = FM_JAPAN_STANDARD_BAND   ( 76   MHz <->  90 MHz)
         2 = FM_JAPAN_WIDE_BAND      ( 76   MHz <-> 108 MHz)
         3 = FM_USER_DEFINED_BAND   (as defined by parameters iUserDefinedBandFreqMin & iUserDefinedBandFreqMax)
      \endcode
   \param  iEmphasis =
      \code
         0 = FM_DE_EMP75            (pre-emphasis/de-emphasis typically used in the United States and Japan.)
         1 = FM_DE_EMP50            (pre-emphasis/de-emphasis typically used outside of the United states and Japan.)
      \endcode
   \param  iChSpacing =
      \code
         0 = FM_CHSPACE_200_KHZ
         1 = FM_CHSPACE_100_KHZ
         2 = FM_CHSPACE_50_KHZ
      \endcode
   \param  iRdsStd =
      \code
         0 = FM_RDS_STD_RBDS         RBDS mode (Typically used in the United States).
         1 = FM_RDS_STD_RDS         RDS mode (Typically used outside of the United States).
         2 = FM_RDS_STD_NONE         No RDS/RBDS decoding.
      \endcode
   \param  iUserDefinedBandFreqMin = min freq (in KHz) for FM_USER_DEFINED_BAND, must be >= 76000
   \param  iUserDefinedBandFreqMax = max freq (in KHz) for FM_USER_DEFINED_BAND, must be <= 108000 AND > iUserDefinedBandFreqMin

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_CONFIGURE_TRANSMITTER( HANDLE hResourceContext,
         unsigned char iRadioBand,
         unsigned char iEmphasis,
         unsigned char iChSpacing,
         unsigned char iRdsStd,
         unsigned long iUserDefinedBandFreqMin,
         unsigned long iUserDefinedBandFreqMax );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM TX RF frequency

    Tunes the FM transmitter to the supplied FM frequency.
      This is an asynchronous command which tunes the FM transmitter to a station as specified
      by the supplied frequency. Only valid frequencies within the band set by
      QLIB_FTM_FM_TX_ENABLE_TRANSMITTER or QLIB_FTM_FM_TX_CONFIGURE_TRANSMITTER can be tuned by this function.
      Attempting to tune to frequencies outside of the set band will result in an error.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iFreqkHz =
      \code
         The frequency must be a multiple of 50 KHz and within the band ranges defined below

         FM_US_EUROPE_BAND:
            US/Europe FM band (87500 KHz <-> 108000 KHz)

         FM_JAPAN_STANDARD_BAND:
            Japan Standard Band (76000 KHz <-> 90000 KHz)

         FM_JAPAN_WIDE_BAND
            Japan Wide Band (76000 KHz <-> 108000 KHz)

         FM_USER_DEFINED_BAND
            User defined band ( x KHz <-> y KHz where x < y and x >= 76000 KHz and y <= 108000 KHz)

      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_TX_ENABLE_TRANSMITTER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_SET_STATION( HANDLE hResourceContext, unsigned long iFreqkHz );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM TX RDS Groups

   This function will transmit RDS/RBDS groups over an already tuned station.
      This function accepts a buffer containing one or more RDS groups.
      When sending this buffer, the client must also indicate how many groups
      should be taken from this buffer.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iNumTxRdsGroups = The number of RDS/RBDS groups to transmit
   \param  aiRdsData = Data containing one or more RDS groups; each consisting of 4 words (unsigned short)
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_TX_ENABLE_TRANSMITTER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_TX_RDS_GROUPS(HANDLE hResourceContext, unsigned long iNumTxRdsGroups, unsigned short* aiRdsData);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM TX Continuous RDS Groups

   This function will continuously transmit RDS/RBDS groups over an already tuned station.
      This function accepts a buffer containing one or more RDS groups.
      The FM client can pass a complete RDS group buffer to the FM driver
      which will be sent continuously by the FM transmitter or driver.
      This continuous transmission frees the client from needing to pass a
      constant stream of RDS/RBDS groups.
      However, only a single RDS/RBDS group buffer can be continuously transmitted
      at a time. Because of this fact, it is important that the client only pass
      the complete buffer it intends to transmit. Attempting to pass a buffer in two calls
      to this interface will be interpreted as two different RDS/RBDS transmits
      and all unsent groups may be cleared.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iNumTxRdsGroups = The number of RDS/RBDS groups to transmit
   \param  aiRdsData = Data containing one or more RDS groups; each consisting of 4 words (unsigned short)
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_TX_ENABLE_TRANSMITTER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_TX_CONT_RDS_GROUPS(HANDLE hResourceContext, unsigned long iNumTxRdsGroups, unsigned short* aiRdsData);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM TX Transmit RDS Group Control

   This function is used to pause/resume RDS/RBDS group transmission, or stop and clear all RDS groups.
      This function can be used with to control continuous and non-continuous RDS/RBDS group transmissions.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRdsCtrl =
      \code
         0 = FTM_TX_RDS_GROUP_PAUSE
         1 = FTM_TX_RDS_GROUP_CLEAR
         2 = FTM_TX_RDS_GROUP_RESUME
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_TX_ENABLE_TRANSMITTER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_TX_RDS_CTRL(HANDLE hResourceContext, unsigned char iRdsCtrl );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Get TX RDS Group Buffer Size

   This function will return the maximum number of RDS/RBDS groups which can be passed to the FM driver.
      This is used to determine the maximum RDS/RBDS buffer size for use when calling Transmit RDS groups and Transmit continuous RDS groups.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piGroupBufferSize = Returns The maximum number (0-62) of RDS/RBDS groups which can be passed to the FM driver at any one time.
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_TX_ENABLE_TRANSMITTER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_GET_RDS_GROUP_BUF_SIZE(HANDLE hResourceContext, unsigned long* piGroupBufferSize);

   /******************************************************************************/
   /**
   Factory Test Mode FM, Set FM Audio Route command


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iFmAudioRoute - set the audio route to/from the FM core
      \code
         0 = Audio to/from the FM core disabled.
         1 = Analog audio from the FM core enabled.
         2 = Digital audio from the FM core enabled (FM core is the master).
         3 = Digital audio from the FM core enabled (FM core is the slave).
         4 = Analog and digital audio from the FM core enabled (FM core is the master).
         5 = Analog and digital audio from the FM core enabled (FM core is the slave).
         6 = FM core digital input enabled (FM core is the master).
         7 = FM core digital input enabled (FM core is the slave).
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_SET_ROUTE_AUDIO( HANDLE hResourceContext, unsigned char iFmAudioRoute );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, SET SIGNAL THRESHOLD

   Set the threshold that the FM driver uses to determine which stations have service available

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iThreshold
      \code
         0 = FM_RX_THRESHOLD_VERY_WEAK
         1 = FM_RX_THRESHOLD_WEAK
         2 = FM_RX_THRESHOLD_STRONG
         3 = FM_RX_THRESHOLD_VERY_STRONG
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_SIGNAL_THRESHOLD(HANDLE hResourceContext, unsigned char   iThreshold);
   QLIB_API unsigned char QLIB_FTM_FM_RX_GET_SIGNAL_THRESHOLD(HANDLE hResourceContext, unsigned char* piThreshold);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, SET RX RDS GROUP PROCESSING OPTIONS

   This function enables or disables RDS/RBDS group processing features.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRdsProcOptions = Bit mask to determine what RDS processing the FM driver/hardware will do
      \code
         0x01 = FM_RX_RDS_GRP_RT_EBL         (RDS/RBDS Radio Text processing enable bit)
         0x02 = FM_RX_RDS_GRP_PS_EBL         (RDS/RBDS Program Service processing enable bit)
         0x04 = FM_RX_RDS_GRP_PS_SIMPLE_EBL   (RDS/RBDS Simple Program Service processing enable bit)
         0x08 = FM_RX_RDS_GRP_AF_EBL         (RDS/RBDS Alternative Frequency processing enable bit)
         0x10 = FM_RX_RDS_GRP_AF_JUMP_EBL   (RDS/RBDS Alternative Frequency Auto Jump enable bit)
         0x20 = FM_RX_RDS_GRP_ECC_EBL        (RDS/RBDS Extended Country Code enable bit)
         0x40 = FM_RX_RDS_GRP_PTNY_EBL       (RDS/RBDS Program Type Name enable bit)
        0x80 = FM_RX_RDS_GRP_RTPLUS_EBL       (RDS/RBDS RT PLUS (RT+) enable bit)
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_RDS_GROUP_PROC_OPTIONS(HANDLE hResourceContext, unsigned long iRdsProcOptions);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, SEARCH STATIONS

   This function initiates basic seek and scan operations

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iSearchMode      This setting decribes different search modes offered by the FM driver
      \code
         0 = FM_RX_SRCH_MODE_SEEK   (FM driver will tune to the next station that meets a signal level requirement)
         1 = FM_RX_SRCH_MODE_SCAN   (FM driver will tune to all stations that meet a signal level requirement)
      \endcode
   \param  iScanDwellTime   This setting describes how long, in seconds, the FM driver will stay tuned to a station during a scan.
      \code
         1 = FM_RX_DWELL_PERIOD_1S   (FM driver will remain tuned to the a station for 1 second  during a scan)
         2 = FM_RX_DWELL_PERIOD_2S   (FM driver will remain tuned to the a station for 2 seconds during a scan)
         3 = FM_RX_DWELL_PERIOD_3S   (FM driver will remain tuned to the a station for 3 seconds during a scan)
         4 = FM_RX_DWELL_PERIOD_4S   (FM driver will remain tuned to the a station for 4 seconds during a scan)
         5 = FM_RX_DWELL_PERIOD_5S   (FM driver will remain tuned to the a station for 5 seconds during a scan)
         6 = FM_RX_DWELL_PERIOD_6S   (FM driver will remain tuned to the a station for 6 seconds during a scan)
         7 = FM_RX_DWELL_PERIOD_7S   (FM driver will remain tuned to the a station for 7 seconds during a scan)
      \endcode
   \param  iSearchDirection   This setting decribes whether searches will increment or decrement frequencies while searching the band
      \code
         0 = FM_RX_SEARCHDIR_UP      (Each frequency searched will be greater than the previous frequency, except when wrapping around the band)
         1 = FM_RX_SEARCHDIR_DOWN   (Each frequency searched will be less than the previous frequency, except when wrapping around the band)
      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SEARCH_STATIONS(HANDLE hResourceContext, unsigned char iSearchMode, unsigned char iScanDwellTime, unsigned char iSearchDirection);
   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, CANCEL SEARCH

   This function cancels any ongoing search operation (including seek, scan, and searchlist)

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_CANCEL_SEARCH(HANDLE hResourceContext);
   /******************************************************************************/
   /******************************************************************************/
   /**
   Factory Test Mode FM, Set FM Alternate Frequency Threshold

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iAfThresholdLog - AF threshold to set in dBm (must be between -101 and -70 dBm)

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_AF_THRESHOLD(HANDLE hResourceContext, short   iAfThresholdLog);
   QLIB_API unsigned char QLIB_FTM_FM_RX_GET_AF_THRESHOLD(HANDLE hResourceContext, short* piAfThresholdLog);

   /******************************************************************************/
   /**
   Factory Test Mode FM, Set FM RSSI CHECK TIMER

   This command set the periodic time interval for monitoring channel condition

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iChCondTimer - each timer counts represents 5 ms

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_RSSI_CHECK_TIMER(HANDLE hResourceContext, unsigned char   iChCondTimer);
   QLIB_API unsigned char QLIB_FTM_FM_RX_GET_RSSI_CHECK_TIMER(HANDLE hResourceContext, unsigned char* piChCondTimer);

   /******************************************************************************/
   /**
   Factory Test Mode FM, Set FM RDS PI TIMER

   This command set the time to wait for RDS interrupt before declaring no RDS on channel

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iRdsTimeout - each timer counts represents 5 ms

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_RDS_PI_TIMER(HANDLE hResourceContext, unsigned char   iRdsTimeout);
   QLIB_API unsigned char QLIB_FTM_FM_RX_GET_RDS_PI_TIMER(HANDLE hResourceContext, unsigned char* piRdsTimeout);


   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM high/low side injection.

   This function can force the LO injection to the highside, lowside, or automatic side.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iHlsi
      \code
         0 = FM_HLSI_AUTO            Automatically select High-side/Low-side injection
         1 = FM_HLSI_LOWSIDE            Force Low-side injection
         2 = FM_HLSI_HIGHSIDE         Force High-side injection
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_HLSI(HANDLE hResourceContext, unsigned char iHlsi);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set Soft Mute

   This function enables/disables the soft-mute feature.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSoftMute
      \code
         0 = FM_RX_SOFTMUTE_DISABLED      Soft Mute feature is disabled.
         1 = FM_RX_SOFTMUTE_ENABLED      Soft Mute feature is enabled.
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_SOFTMUTE(HANDLE hResourceContext, unsigned char iSoftMute);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set Antenna

   This function can be used to override the automatic FM antenna selection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iAntenna
      \code
         0 = FM_ANTENNA_WIRED_HEADSET   Force selection of wired headset FM antenna.
         1 = FM_ANTENNA_PWB            Force selection of PWB FM antenna.
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_ANTENNA(HANDLE hResourceContext, unsigned char iAntenna);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Enable Notch

   This function enables/disables a low pass or high pass notch filter

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iNotch
      \code
         0 = FM_DISABLE_NOTCH_FILTERS         Do not enable either Notch Filter
         1 = FM_ENABLE_LOW_PASS_NOTCH_FILTER      Enable Low Pass Notch Filter
         2 = FM_ENABLE_HIGH_PASS_NOTCH_FILTER   Enable High Pass Notch Filter
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_ENABLE_NOTCH(HANDLE hResourceContext, unsigned char iNotch);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Read RDS Group Counters

   This function provides statistics related to incoming RDS data.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bResetCounters
      \code
         0 = Do NOT reset counters
         1 = Reset Counters
      \endcode
   \param piTotalRdsBlockErrors = Returns the Total count of RDS block errors received.
   \param piTotalRdsGroups = Returns the Total count of RDS groups received.
   \param piTotalRdsGroup0 = Returns the Total count of RDS group type 0A/0B received.
   \param piTotalRdsGroup2 = Returns the Total count of RDS group type 2A/2B received.
   \param piTotalRdsBlockB = Returns the Total count of RDS groups which matched Block-B match condition.
   \param piTotalRdsProcessedGroup0 = Returns the Total count of interrupts from processing RDS group type 0A/0B.
   \param piTotalRdsProcessedGroup2 = Returns the Total count of interrupts from processing RDS group type 2A/2B.
   \param piTotalRdsGroupFiltered   = Returns the Total count of RDS groups which passed the group filter.
   \param piTotalRdsChangeFiltered  = Returns the Total count of RDS groups which passed the change filter.

   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_READ_RDS_GROUP_COUNTERS(
      HANDLE hResourceContext,
      unsigned char bResetCounters,
      unsigned long* piTotalRdsBlockErrors,
      unsigned long* piTotalRdsGroups,
      unsigned long* piTotalRdsGroup0,
      unsigned long* piTotalRdsGroup2,
      unsigned long* piTotalRdsBlockB,
      unsigned long* piTotalRdsProcessedGroup0,
      unsigned long* piTotalRdsProcessedGroup2,
      unsigned long* piTotalRdsGroupFiltered,
      unsigned long* piTotalRdsChangeFiltered);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Select TX Internal Audio Tone

   This function selects between various audio tones to modulate the FM Transmitter

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTone
      \code
         0 = FM_TX_AUDIO_TONE_NOTONE            no audio tone
         1 = FM_TX_AUDIO_TONE_1KHZ_0DBFS_LR      1 kHz tone @ 0 dBFS applied equally to Left & Right
         2 = FM_TX_AUDIO_TONE_1KHZ_0DBFS_LEFT   1 kHz tone @ 0 dBFS applied to Left only
         3 = FM_TX_AUDIO_TONE_1KHZ_0DBFS_RIGHT   1 kHz tone @ 0 dBFS applied to Right only
         4 = FM_TX_AUDIO_TONE_1KHZ_N18DBFS_LR   1 kHz tone @ -18 dBFS applied equally to Left & Right
         5 = FM_TX_AUDIO_TONE_15KHZ_N18DBFS_LR   15 kHz tone @ -18 dBFS applied equally to Left & Right
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_TX_ENABLE_TRANSMITTER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_TX_SET_INTERNAL_TONE(HANDLE hResourceContext, unsigned char iTone);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Get RX RDS Program Service string

   This function will return the RX RDS Program Service string.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piLength = Returns the string length (max length = 108)
   \param sPS = Returns the Program Service string
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_GET_RDS_PS(HANDLE hResourceContext,  unsigned char* piLength, char* sPS);


   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Get RX RDS Radio Text string

   This function will return the RX RDS Radio Text string.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piLength = Returns the string length (max length = 64)
   \param sRT = Returns the Radio Text string
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_GET_RDS_RT(HANDLE hResourceContext,  unsigned char* piLength, char* sRT);


   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Get FM RX station parameters V2

   Returns various statistics related to the currently tuned station.
      This is a synchronous command which returns various statistics related to the currently
      tuned station. Included in these statistics are the currently tuned frequency,
      the RDS/RBDS sync status, the RSSI level, current mute settings and the stereo/mono status.
      The difference between the original and the V2 version of this command,
      is that rssi in V2 is returned as a signed char in dBm, because Android FTM implementations
      return the rssi as a signed byte, but QMSL function FTM_FM_RX_GET_STATION_PARAMETERS
      defined the rssi value as unsigned char, so it was interpreted incorrectly.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piStationFreq = Returns the currently tuned frequency in KHz
   \param piServAvble = Returns the current service available indicator for the current station
      \code
         0 = FM_RX_SERVICE_NOT_AVAILABLE - No stations were found in the FM band.
         1 = FM_RX_SERVICE_AVAILABLE - At least one station was found in the FM band.
      \endcode
   \param iRssi = Returns the current signal strength level (-120 to -1 dBm range).
   \param piStereoProgram = Returns the current mono/stereo indicator for this station.
      \code
         0 = FM_RX_MONO_PROGRAM - The currently received audio is mono
         1 = FM_RX_STEREO_PROGRAM - The currently received audio is stereo.
      \endcode
   \param piRdsSyncStatus = Returns the current RDS/RBDS synchronization status
      \code
         0 = FM_RX_NO_RDS_SYNC - No RDS/RBDS decoding possible.
         1 = FM_RX_RDS_SYNC - RDS/RBDS decoding.
      \endcode
   \param piMuteMode = Returns the current FM mute mode.
      \code
         0 = FM_RX_NOMUTE  Un-mute both audio channels
         1 = FM_RX_MUTELEFT - Mute only the left audio channel
         2 = FM_RX_MUTERIGHT - Mute only the right audio channel
         3 = FM_RX_MUTEBOTH - Mute both audio channels
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_Get_Station_Parameters_V2(
      HANDLE hResourceContext,
      unsigned long* piStationFreq,
      unsigned char* piServAvble,
      char* piRssi,
      unsigned char* piStereoProgram,
      unsigned char* piRdsSyncStatus,
      unsigned char* piMuteMode );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Get FM scaled RSSI

   Returns RSSI scaled to dBm

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iRssi = Returns the current signal strength level (-120 to -1 dBm range).
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_Get_Scaled_Rssi( HANDLE hResourceContext, int* piRssi );

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Get FM Pin Connectivity

   Returns results of Pin Connectivity tests

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iBtTestResult = Returns the Bluetooth pin connectivity test results
   \param iFmTestResult = Returns the FM pin connectivity test results
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_GET_PIN_CONNECTIVITY(HANDLE hResourceContext, unsigned short* piBtTestResult, unsigned short* piFmTestResult);

   /******************************************************************************/
   /**
   Captures WCNSS Audio data from 0x1558 log packets but only if the WCNSS Audio source is FM RX

   \param sFilename = Filename, including path, of the .wav file to be created from audio data
   \param iDuration_ms = capture length in ms
   \param iNumMissedPackets = number of missed log packets as determined by examining log packet timestamps
   \param iNumTotalPackets = number of captured log packets used to create the .wav file

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_WCNSS_Audio_Capture_FM_RX(HANDLE hResourceContext,  char* sFilename, int iDuration_ms, int* piMissedPackets, int* piTotalPackets);

   /******************************************************************************/
   /**
   High level function to activate logging for WCNSS Audio log = 0x1558

   \param iLogCode = Log code
   \param eAudioSourceToCapture = audio source value of log packets to buffer

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOG_StartWCNSSAudio_Log(HANDLE hResourceContext);

   /******************************************************************************/
   /**
   High level function to disable logging for WCNSS Audio log = 0x1558

   \param iLogCode = Log code

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_LOG_StopWCNSSAudio_Log(HANDLE hResourceContext);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Enable FM Rx Audio

   This function can be used to enable FM Rx audio output to either the headset or speaker

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iAudioDestination
      \code
         0 = FM_RX_AUDIO_TO_HEADSET   - Route FM Rx audio to headset
         1 = FM_RX_AUDIO_TO_SPEAKER   - Route FM Rx audio to speaker
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_ENABLE_AUDIO (HANDLE hResourceContext, unsigned char iAudioDestination);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Disable FM Rx Audio

   This function can be used to disable FM Rx audio output

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_DISABLE_AUDIO (HANDLE hResourceContext);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set FM Rx Audio Volume

   This function can be used to set the volume level of FM Rx audio output

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iAudioVolume = audio volume setting
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_AUDIO_VOLUME (HANDLE hResourceContext, unsigned char iAudioVolume);

   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Read Extended RDS Group Counters

   This function provides statistics related to incoming RDS data.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bResetCounters
      \code
         0 = Do NOT reset counters
         1 = Reset Counters
      \endcode
   \param piTotalRdsGroupLostSync = Returns the Total count RDS groups which lost synchronization.
   \param piTotalRdsGroupNoSync = Returns the Total count RDS groups which didn't sync.
   \param piTotalRdsGroupSyncIntr = Returns the Total count RDS groups which triggered synchronization interrupt.

   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_READ_RDS_GROUP_COUNTERS_EXT(
      HANDLE hResourceContext,
      unsigned char bResetCounters,
      unsigned long* piTotalRdsGroupLostSync,
      unsigned long* piTotalRdsGroupNoSync,
      unsigned long* piTotalRdsGroupSyncIntr);


   /******************************************************************************/
   /**
   Factory Test Mode FM Commands, Set Get Reset AGC

   This function provides control of the AGC

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param ctrl
      \code
         0x00 = Set AGC Gain State with "GainState" parameter.
         0x01 = Get Current AGC gain State and past 3 gain state changes. 
			0x02 = Reset AGC
      \endcode
   \param GainState
      \code
         0x00 = G0 state (HIGH)
         0x01 = G1 state (MIDPLUS)
			0x02 = G2 state (MID)
			0x03 = G3 state (MIDMIN)
			0x04 = G4 state (LOW)
      \endcode
   \param status = 0x00 Command succeeded, else Failed
   \param currentGainState
      \code
         0x00 = G0 state (HIGH)
         0x01 = G1 state (MIDPLUS)
			0x02 = G2 state (MID)
			0x03 = G3 state (MIDMIN)
			0x04 = G4 state (LOW)
      \endcode
	\param gainStateChange1
      \code
         0x00 = G0 state (HIGH)
         0x01 = G1 state (MIDPLUS)
			0x02 = G2 state (MID)
			0x03 = G3 state (MIDMIN)
			0x04 = G4 state (LOW)
      \endcode
   \param gainStateChange2
      \code
         0x00 = G0 state (HIGH)
         0x01 = G1 state (MIDPLUS)
			0x02 = G2 state (MID)
			0x03 = G3 state (MIDMIN)
			0x04 = G4 state (LOW)
      \endcode
   \param gainStateChange3
      \code
         0x00 = G0 state (HIGH)
         0x01 = G1 state (MIDPLUS)
			0x02 = G2 state (MID)
			0x03 = G3 state (MIDMIN)
			0x04 = G4 state (LOW)
      \endcode
   \return true if successful, false if fail.

   \warning QLIB_FTM_FM_RX_ENABLE_RECEIVER must be called before this.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_FM_RX_SET_GET_RESET_AGC(
      HANDLE hResourceContext,
		unsigned char ctrl, 
		unsigned char gainState, 
		unsigned char *status, 
		unsigned char *currentGainState, 
		unsigned char *gainStateChange1, 
		unsigned char *gainStateChange2, 
		unsigned char *gainStateChange3);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FM_H)
