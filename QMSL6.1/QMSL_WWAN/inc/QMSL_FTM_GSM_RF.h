/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_FTM_GSM_RF.h#13 $
 * $DateTime: 2016/04/20 15:33:41 $
 *
 * DESCRIPTION: QMSL_FTM_GSM_RF
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#include <vector>

#if !defined(_QMSL_FTM_GSM_RF_H)
#define _QMSL_FTM_GSM_RF_H

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
                  GSM FTM
*******************************************************************************/

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.9 Set PA profile

      1) Downloads the user-defined PA (power amplifier) ramp-up and ramp-down profile to the
         embedded platform and stores it in the PA LUT (look-up table) for use in subsequent
         transmits.

      2) Updates the four PA ramp offset tables for GSM 850 and GSM 900 RF operating mode and
         two PA ramp offset tables for GSM 1800 and GSM 1900 RF operating mode, such that they
         all have the same shape as the input PA ramp profile. GSM 850 and GSM 900 share the same
         PA ramp offset tables, as do GSM 1800 and GSM 1900. The first offset table is shared
         between both RF operating modes. The algorithm used to compute the PA ramp offset tables
         from the input PA ramp profile is explained below.


      The input data will be concatonated into the pa_lut_type structure,
      as summarized below:
   \code
         #define PA_LUT_MAX_SIZE      64  // Number of entries in the PA LUT

         struct pa_lut_cfg_type
         {
            unsigned char ramp_step_size;
            unsigned char pa_lut_size;
         } ;

         struct pa_lut_type
         {
            unsigned short ramp_up[PA_LUT_MAX_SIZE];
            unsigned short ramp_down[PA_LUT_MAX_SIZE];
         };
   \endcode

      See GSM FTM document for more detailed information.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  pRampUp   = pointer to memory buffer of 64 ramp up values
\param  pRampDown = pointer to memory buffer of 64 ramp down values
\param  iRampSize = Number of elements in the ramp size.  This is a maximum of 64. Normally this value is <TBD>
\param  iPaLookupTableSize = Number of elements in the PA look up table.  Normally this value is <TBD>.

\return true if successful, false if fail.

\warning This operation has not been tested yet in the factory library!

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_PA_PROFILE
( HANDLE hResourceContext, unsigned short* pRampUp, unsigned short* pRampDown,
  unsigned char iRampSize, unsigned char iPaLookupTableSize );

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.11 Set transmit continuous

This function configures transmit parameters to perform a continuous transmit operation.

   NOTE: A continuous transmit operation is one in which the transmitter, modulator, and related RF
   circuitry are left on and not allowed to burst. The actual transmit begins when the subsequent
   Set Tx ON function is issued, then the succeeding call to Set Tx OFF function will turn off the
   transmitter, modulator, and related circuitry.


   The data will be packed into this structure, which is referenced in the document

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param iSlotNum    = slot number
\param iDataSource = Modulation data source:
   \code
         0 - FTM_GSM_TX_DATA_SOURCE_PSDRND
         1 - FTM_GSM_TX_DATA_SOURCE_TONE,
         2 - FTM_GSM_TX_DATA_SOURCE_BUFFER
         3 - FTM_GSM_TX_DATA_SOURCE_TWOTONE
   \endcode
\param iTSCindex        = TSC Index number
\param iNumBursts       = # of bursts, if not infinate
\param bIsInfiniteDuration =
   \code
         1 - Infinate
         0 - Count bursts
   \endcode

\return true if successful, false if fail.

\warning When the Tx hardware is turned on, the receiver must be turned off;
         therefore, this API cannot be used simultaneously with the Set Rx Burst
       or the Set Rx Continuous API.

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_TRANSMIT_CONT
( HANDLE hResourceContext, unsigned char iSlotNum, short iDataSource, unsigned char iTSCindex,
  unsigned long iNumBursts, unsigned char bIsInfiniteDuration );


/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.12 Set transmit burst

This function configures parameters associated with a Tx burst.

      NOTE The bursts will start when the Set Tx ON API is issued and will last for the number of TDMA
      frames specified as one of the tx_burst parameters. If this parameter lists infinite burst
      transmission, the phone will keep issuing transmit bursts until the Set Tx OFF API is issued.


\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param iSlotNum    = slot number
\param iDataSource = Modulation data source:
\code
      0 - TX_DATA_SOURCE_PSDRND
      1 - TX_DATA_SOURCE_TONE,
      2 - TX_DATA_SOURCE_BUFFER

\endcode
\param iTSCindex        = TSC Index number
\param iNumBursts       = # of bursts, if not infinate
\param bIsInfiniteDuration = 1 - Infinate, 0 - Count bursts

\return true if successful, false if fail.

\warning When the Tx hardware is turned on, the receiver must be turned off;
         therefore, this API cannot be used simultaneously with the Set Rx Burst
       or the Set Rx Continuous API.

\note This function can be used in QMSL FTM Sequencer operation
*/
QLIB_API unsigned char QLIB_FTM_SET_TRANSMIT_BURST
( HANDLE hResourceContext, unsigned char iSlotNum, short iDataSource, unsigned char iTSCindex,
  unsigned long iNumBursts, unsigned char bIsInfiniteDuration );

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.13 Set Rx burst

      This function configures parameters to either start (RX_FUNCTION_GET_RSSI or
      RX_FUNCTION_GET_DC_OFFSETS) or stop sending Rx burst commands to the MDSP
      (RX_FUNCTION_STOP_CONTINOUS_RX), as specified by the enum_rx_function_type parameter.

      The document refers to the rx_burst_type structure, which is defined here:
\code
          struct rx_burst_type
          {
              unsigned char slot_num;  // 1 byte, unsigned 8-bit = slot number
              short rx_funct;       // 2 bytes, signed 16-bit, rx function ID
          };
\endcode

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param iSlotNum = Slot number to receive
\param iRxFunction =  Type of function for DSP to perform
\code
      0  - RX_FUNCTION_GET_RSSI
      1  - RX_FUNCTION_GET_DC_OFFSETS
      2  - RX_FUNCTION_STOP_CONTINOUS_RX

\endcode
\return true if successful, false if fail.

\warning Cannot be used while FTM_SET_TRANSMIT_BURST is active

\note This function can be used in QMSL FTM Sequencer operation
*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_RX_BURST( HANDLE hResourceContext, unsigned char iSlotNum, short iRxFunction);

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.14 Set Rx continuous

      This function configures the RF hardware such that the receiver is ON continuously and is not
      bursting. The enum_rx_function_type parameter specifies whether the receiver is to be turned
      ON (RX_FUNCTION_RF_RX_HW_ON) or OFF (RX_FUNCTION_RF_RX_HW_ON). This mode is used for
      performing hardware test and measurements.

      The document refers to the rx_burst_type structure, which is defined here:
         struct rx_burst_type
         {
            unsigned char slot_num; // 1 byte, unsigned 8-bit = slot number
            short rx_funct;         // 2 bytes, signed 16-bit, rx function ID
         };

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param iSlotNum    = Slot number to receive
\param iRxFunction = Type of function for DSP to perform
   \code
        0  - RX_FUNCTION_GET_RSSI
        1  - RX_FUNCTION_GET_DC_OFFSETS
        2  - RX_FUNCTION_STOP_CONTINOUS_RX
   \endcode

\return true if successful, false if fail.

\warning Cannot be used while QLIB_FTM_SET_TRANSMIT_BURST is active
\warning When RX Continuous is used the RSSI will not update.  This command mode is used for troubleshooting purposes only.

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_RX_CONTINUOUS( HANDLE hResourceContext, unsigned char iSlotNum, short iRxFunction );

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.15 Set Tx power level

      This function reads PA ramp profiles from NV or if NV is not loaded, it reads the default PA
      ramp profile from software, and then sets the corresponding Tx power level.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iPowerLevelID = Power level number to set,
\code
      0 to 14 = 5 dBm to 33 dBm in GSM 850 and GSM 900 mode,
      0 to 15 = 0 dBm to 30 dBm in GSM 1800 and GSM1900 mode

\endcode

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_TX_POWER_LEVEL( HANDLE hResourceContext, unsigned char iPowerLevelID );

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.16 Get RSSI

      This function returns a 32-bit unsigned raw receiver signal strength indicator (RSSI) value. This
      number is averaged over multiple bursts--currently over 10 bursts.

   A couple of points about this function, from questions asked:
      1. 10 bursts are just our default implementation on embedded side.  The PC
      side (QMSL) doesn't do any averaging.  If customer wants to change/define
      the number of averaging, they need to 1) change the embedded side FTM
      behavior and 2) change the PC side (by extending QMSL).  To extend the PC
      side, they can use SendSync function.  Keep in mind that QMSL is just a PC
      wrapper to all FTM functions.  In this case, it is just a wrapper of
      functions documented in CL93-V5370-1 (GSM FTM).

      2. Since QMSL is just a PC side wrapper on FTM function, you can look up the
      embedded side implementation to see how RSSI value is defined/derived.  You
      should be able to trace through the FTM dispatch table on embedded side.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iRssiValue = Return value of the RSSI value

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GET_RSSI( HANDLE hResourceContext, unsigned long* piRssiValue );

/********************************************************************************/
/**

Factory Test Mode GSM Commands 3.16 Get PRX DRX RSSI

QLIB_FTM_GET_GSM_PRX_DRX_RSSI API returns two 32-bit unsigned raw Receiver Signal Strength Indicator (RSSI) value.
One is for primary Rx and the other is for diversity Rx.
The RSSI values are averaged over multiple bursts, currently over 10 bursts.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param piPrxRssi - Primary RX RSSI raw value

\param piDrxRssi - Diversity RX RSSI raw value

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GET_GSM_PRX_DRX_RSSI( HANDLE hResourceContext,
                                                      unsigned long * piPRxRssi,
                                                      unsigned long * piDRxRssi );

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.16 Get RSSI in dB

      This function returns a 32-bit unsigned receiver signal strength indicator (RSSI) value in dBm.

   A couple of points about this function, from questions asked:
      1. 10 bursts are just our default implementation on embedded side.  The PC
      side (QMSL) doesn't do any averaging.  If customer wants to change/define
      the number of averaging, they need to 1) change the embedded side FTM
      behavior and 2) change the PC side (by extending QMSL).  To extend the PC
      side, they can use SendSync function.  Keep in mind that QMSL is just a PC
      wrapper to all FTM functions.

      2. Since QMSL is just a PC side wrapper on FTM function, you can look up the
      embedded side implementation to see how RSSI value is defined/derived.  You
      should be able to trace through the FTM dispatch table on embedded side.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iRssiValue = Return value of the RSSI value

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_RSSI_TO_DB( HANDLE hResourceContext, unsigned long* piRssiValue );


/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.17 Set PA start delta

   This function offsets the PA ramp start time by the specified amount. A positive value for
   3 startDelta causes the ramp to start later than it does, and a negative value causes the PA ramp to
   4 start earlier. The unit assumed for startDelta is quarter symbols.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iPA_StartDelta = Value (1/4 symbol) to adjust PA ramp start time

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_PA_START_DELTA( HANDLE hResourceContext, unsigned short iPA_StartDelta );

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.18 Set PA stop delta

   This function offsets the PA ramp stop time by the specified amount. A positive value for
   9 stopDelta causes the ramp to stop later than it does, and a negative value causes the PA ramp to
   10 stop earlier. The unit assumed for stopDelta is quarter symbols.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iPA_StopDelta = Value to adjust PA ramp stop time (1/4 symbols)

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_PA_STOP_DELTA( HANDLE hResourceContext, unsigned short iPA_StopDelta );


/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.2.19 Set PA DAC input

      The Set PA DAC input API uses the PA ramp offset table and the specified dacInput value to
      generate a PA ramp profile.

      This profile is such that it has the shape specified in the offset table,
      and the flat portion of the profile has a power corresponding to the dacInput specified. This
      generated PA profile is then copied to the PA LUT for use in the subsequent transmits (burst or
      continuous).

      In GSM 850 and GSM 900 RF operating mode, there are four PA ramp offset tables and in GSM
      1800 and GSM 1900 RF operating mode, there are two PA ramp offset tables to choose from.
      GSM 850 and GSM900 shared the same PA ramp offset tables, as does GSM 1800 and GSM
      1900. One of these offset tables will used to generate a PA ramp profile based on the dacInput
      value and RF operating mode.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iDACinput = DAC value that is used for the maximum level of the burst.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_PA_DAC_INPUT( HANDLE hResourceContext, unsigned short iDACinput );

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.x.xx Set AMAM Table DC

   Shifts the AMAM Table by a constant DC shift.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iDACinput = DC shift applied to the waveform.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_AMAM_TABLE_DC( HANDLE hResourceContext, short iDcOffset );

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.20 Set Tx Cal Sweep

      This function takes 3 parameters, a dac_start value, a dac_stop value and a dac_step value. It then
      turns the transmit burst on and varies the power from dac_start to dac_stop incrementing the
      power in steps of dac_steps. It uses the SET PA DAC input API to set the power for each burst. It
      has been introduced to make characterization of the GSM power amplifier easier and faster. Note
      the dac_step has to be positive.



\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iDAC_Start   = DAC value for the first burst step
\param   iDAC_Stop   = DAC value for the last burst step
\param   iDAC_Step   = Number of DAC values to increment between each burst (positive number)

\return true if successful, false if fail.

\warning The SET_TX_OFF command must be called before executing this command. Otherwise, results
       can be unpredictable.

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_TX_CAL_SWEEP
( HANDLE hResourceContext, unsigned short iDAC_Start, unsigned short iDAC_Stop, unsigned short iDAC_Step);


/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.21 Set Tx frame matrix

This function configures the Tx slots. It needs to be called seven times to configure all seven 3 slots.

\param  iSlotNum  = Slot number to be configured, 0 to 7
\param   iTurnSlotOn = Turn the slot on or off, 0=OFF, 1=ON
\param   iPwrLevel   = Power level for this slot; should be in dB*100
\param  iModScheme = Modulation Code Scheme; 0=MCS1, 1=MCS2, to 8=MCS9

\return true if successful, false if fail.

\warning

\note This function can be used in QMSL FTM Sequencer operation
*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_TX_FRAME_MATRIX ( HANDLE hResourceContext,
                                                      unsigned char iSlotNum, unsigned char iTurnSlotOn, short iPwrLevel, unsigned char iModScheme);

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.22 Rx gain range cal

This command combines a number of steps required to perform Rx gain range calibration across frequencies.

The traditional method of performing gain range calibration involved the following steps:
\code
    1. Set Mode.
    2. Set Channel 1.
    3. Turn RX on.
    4. Set gain range 0.
    5. Get RSSI.
    6. Repeat steps 4 and 5 through all gain ranges.
    7. Set Channel 2.
    8. Repeat steps 4 through 6, etc.
\endcode

This API now accepts a bit mask to specify which gain ranges are being calibrated and returns the
RSSI for all those gain ranges in a single command, i.e., it combines steps 5 and 6 above into a
single command. In addition, it also turns the receiver on/off based on input from the user.
18 The modified method of performing the gain range calibration is now:
\code
    1. Set Mode.
    2. Set Channel 1.
    3. Call Rx gain range cal command with:
       a. gain_range_bitmask = 0xF (for 4 gain ranges) or 0x1F (for 5 gain ranges)
       b. Number of Burst to Average set to some number greater than 1
       c. Toggle RX on/off set to TRUE (this will cause the phone to turn on the receiver)
    4. Read the response of Rx gain range cal with the result in the RSSI Result field.
    5. Set Channel 2.
    6. Call Rx gain range cal command as in step 3, but set Toggle RX on/off field to FALSE.
    7. Read the response of the command.
    8. Continue for the remaining channels.
    9. Set the last channel number.
    10. Call Rx gain range cal 1 command as in step 3, i.e., set Toggle RX on/off field to TRUE.
        This should cause the phone to turn off the receiver after making measurements for the last
        channel number.
    11. Read the results.
\endcode

\param  iRxRangeBitMask  = input, When a bit position is set, the gain range corresponding
               to that bit position is calibrated, e.g., 0b00001111 will
               give RSSI measurements for gain range 0,1,2,3
   Refer to FTM_GSM_RX_GainRange_Enum for definitions
   \code
       FTM_GSM_RX_GAIN_RANGE_0   = 0x01,  //!<' Gain range 0
       FTM_GSM_RX_GAIN_RANGE_1   = 0x02,  //!<' Gain range 1
       FTM_GSM_RX_GAIN_RANGE_2   = 0x03,  //!<' Gain range 2
       FTM_GSM_RX_GAIN_RANGE_3   = 0x04,  //!<' Gain range 3
       FTM_GSM_RX_GAIN_RANGE_4   = 0x05   //!<' Gain range 4
   \endcode

\param iNumAverages = Each RSSI measurement is obtained by averaging RSSI
                      over a number of bursts; this parameter allows the
                      number of bursts to be configured.

\param bToggleRx = input, Possible values are:
   \code
       TRUE = If RX was on, turn it off, If RX was off, turn it on
       FALSE = Do not alter the state of the receiver
   \endcode

\param aiRSSI_Result = output, Array of the results:
                          uint32 rssi[8]

      For example, if gain range bitmask = 0b00011101,
      rssi[0] = RSSI for gain range 0, rssi[1] = 0, rssi[2] = RSSI
      for gain range 2, rssi[3] = RSSI for gain range 3, rssi[4]
      = RSSI for gain range 4, etc.
      Note: Current targets have either 4 or 5 gain ranges.
      Setting bit positions that have no corresponding gain
      range will result in erroneous results.

      The size of the array is defined by FTM_GSM_RX_GAIN_RANGE_CAL_NUM_RETURN_VALUES in QLib_Defines.h

\return true if successful, false if fail.

\warning

\note This function can be used in QMSL FTM Sequencer operation
*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_RX_GAIN_RANGE_CAL(
   HANDLE hResourceContext,
   unsigned char iRxRangeBitMask,
   unsigned char iNumAverages,
   unsigned char bToggleRx,
   unsigned long aiRSSI_Result[8]
);

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.22 Switch LNA linearity mode.

This command switches LNA linearity mode for GSM RX gain range calibration.

\param rfMode     = The RF band.
\param channel    = The ARFCN.
\param linearity  = The LNA linearity to switch to. 0 - low linearity; 1 - high linearity.

\return true if successful, false if fail.

\warning

\note FTM command issued: _FTM_SET_LNA_LINEARITY
*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_RX_SET_LINEARITY(
   HANDLE hResourceContext,
   unsigned short rfMode,
   unsigned short channel,
   unsigned char linearity
);

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.22 Rx gain range cal for Diversity Rx calibration.

This command is similar to QLIB_FTM_RX_GAIN_RANGE_CAL, except that it simultaneously returns the PRx and DRx RSSI results.

This command combines a number of steps required to perform Rx gain range calibration across frequencies.

The traditional method of performing gain range calibration involved the following steps:
\code
    1. Set Mode.
    2. Set Channel 1.
    3. Turn RX on.
    4. Set gain range 0.
    5. Get RSSI.
    6. Repeat steps 4 and 5 through all gain ranges.
    7. Set Channel 2.
    8. Repeat steps 4 through 6, etc.
\endcode

This API now accepts a bit mask to specify which gain ranges are being calibrated and returns the
RSSI for all those gain ranges in a single command, i.e., it combines steps 5 and 6 above into a
single command. In addition, it also turns the receiver on/off based on input from the user.
18 The modified method of performing the gain range calibration is now:
\code
    1. Set Mode.
    2. Set Channel 1.
    3. Call Rx gain range cal command with:
       a. gain_range_bitmask = 0xF (for 4 gain ranges) or 0x1F (for 5 gain ranges)
       b. Number of Burst to Average set to some number greater than 1
       c. Toggle RX on/off set to TRUE (this will cause the phone to turn on the receiver)
    4. Read the response of Rx gain range cal with the result in the RSSI Result field.
    5. Set Channel 2.
    6. Call Rx gain range cal command as in step 3, but set Toggle RX on/off field to FALSE.
    7. Read the response of the command.
    8. Continue for the remaining channels.
    9. Set the last channel number.
    10. Call Rx gain range cal 1 command as in step 3, i.e., set Toggle RX on/off field to TRUE.
        This should cause the phone to turn off the receiver after making measurements for the last
        channel number.
    11. Read the results.
\endcode

\param  iRxRangeBitMask  = input, When a bit position is set, the gain range corresponding
               to that bit position is calibrated, e.g., 0b00001111 will
               give RSSI measurements for gain range 0,1,2,3
   Refer to FTM_GSM_RX_GainRange_Enum for definitions
   \code
       FTM_GSM_RX_GAIN_RANGE_0   = 0x01,  //!<' Gain range 0
       FTM_GSM_RX_GAIN_RANGE_1   = 0x02,  //!<' Gain range 1
       FTM_GSM_RX_GAIN_RANGE_2   = 0x03,  //!<' Gain range 2
       FTM_GSM_RX_GAIN_RANGE_3   = 0x04,  //!<' Gain range 3
       FTM_GSM_RX_GAIN_RANGE_4   = 0x05   //!<' Gain range 4
   \endcode

\param iNumAverages = Each RSSI measurement is obtained by averaging RSSI
                      over a number of bursts; this parameter allows the
                      number of bursts to be configured.

\param bToggleRx = input, Possible values are:
   \code
       TRUE = If RX was on, turn it off, If RX was off, turn it on
       FALSE = Do not alter the state of the receiver
   \endcode

\param aiRSSI_Result_PRx = output, Array of the results for the primary Rx chain:
                          uint32 rssi[8]

\param aiRSSI_Result_DRx = output, Array of the results for the diversity Rx chain:
                          uint32 rssi[8]

      For example, if gain range bitmask = 0b00011101,
      rssi[0] = RSSI for gain range 0, rssi[1] = 0, rssi[2] = RSSI
      for gain range 2, rssi[3] = RSSI for gain range 3, rssi[4]
      = RSSI for gain range 4, etc.
      Note: Current targets have either 4 or 5 gain ranges.
      Setting bit positions that have no corresponding gain
      range will result in erroneous results.

      The size of the array is defined by FTM_GSM_RX_GAIN_RANGE_CAL_NUM_RETURN_VALUES in QLib_Defines.h

\return true if successful, false if fail.

\warning

\note This function can be used in QMSL FTM Sequencer operation
*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_RX_GAIN_RANGE_CAL_PRX_DRX(
   HANDLE hResourceContext,
   unsigned char iRxRangeBitMask,
   unsigned char iNumAverages,
   unsigned char bToggleRx,
   unsigned long aiRSSI_Result_PRx[8],
   unsigned long aiRSSI_Result_DRx[8]
);


/******************************************************************************/
/**
FTM RF GSM, CL93-V5370-1 section 3.1.23, FTM_GSM_RX_FREQ_CAL_SWEEP

This command instructs the mobile to perform the GSM RX Frequency measurement.
It will setup the appropriate mobile logging so that the resulting log message will be captured.

The FTM command ID is FTM_GSM_RX_SWEEP_CAL (311)

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param pFTM_GSM_Rx_Freq_Cal_Sweep_Request_Response = structure to hold input and output values,
       of type "FTM_GSM_Rx_Freq_Cal_Sweep_Request_Response," as defined in QLIB_Defines.h

\return true if successful, false if fail.

\warning
*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_RX_FREQ_CAL_SWEEP(
   HANDLE hResourceContext, void* pFTM_GSM_Rx_Freq_Cal_Sweep_Request_Response);

/******************************************************************************
                  GSM Polar Tx Cal FTM
*******************************************************************************/

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.2 Do Autocal

The FTM_DO_AUTOCAL command is used to measure the amplitude and phase nonlinearity of the GSM power amplifier.
The function returns two tables. One of them is a measure of the DAC input to the power
amplifier versus the output power of the power amplifier.
The other is a table of the DAC input to the power amplifier versus the output-phase
distortion caused by the PA. These tables are then interpolated, as required,
and loaded into the MSM. The transmit data is then predistorted to compensate for the measured nonlinearity.
The inputs to the Autocal function are:

1. An external power measurement point.
2. The dynamic range of the measurement.
3. A flag to specify if the measured data is to be stored in NV.
4. The RSB-correction parameters.

This function will start the FTM2 logging, which will capture the GSM AUTOCAL log packet results.

Call QLIB_FTM_DO_GSM_AUTOCAL_GetResults() to get the results returned from the phone.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iPower = The transmitter output power at PA-DAC value; to allow for added resolution,
the power is read in units of (dBm/100); hence, the user inputs a number that is dBm value measured x 100.

\param   iPA_DAC_Value  = The DAC value in the external reference measurement that yielded the power in the next parameter.

\param   iMax_Power  = The maximum power to which the Autocal curves need to be measured and stored;
   to allow for added resolution, the power is read in units of (dBm/100);
   hence, the user inputs a number that is dBm value measured x 100.
\param  iMin_Power  = The minimum power to which the Autocal curves need to be measured and stored;
   to allow for added resolution, the power is read in units of (dBm/100);
   hence, the user inputs a number that is dBm value measured x 100.

\param  iWriteNVFlag = Flag that specifies whether to write the curves and associated parameters to NV, and
      also specifies to the frequency with which to associate the measured curve.
       0 = Do not write NV
       1 = Write curves and parameters to NV associated with frequency F1 of current band
       2 = Write curves and parameters to NV associated with frequency F1 of current band

\param  iRSB_Cor_A_R0 = A measure of the receiver phase imbalance in gain range 0;
   it is used by the system to correct the curves for this imbalance.
   Currently, RSB parameters are not being measured. The default value to use is 0

\param  iRSB_Cor_A_R1   = A measure of the receiver phase imbalance in gain range 1;
   it is used by the system to correct the curves for this imbalance.
   Currently, RSB parameters are not being measured. The default value to use is 0.

\param  iRSB_Cor_B_R0 = A measure of the receiver phase and amplitude imbalance in gain range 0;
   it is used by the system to correct the curves for this imbalance.
   Currently, RSB parameters are not being measured. The default value to use is 10000.

\param  iRSB_Cor_B_R1 = A measure of the receiver phase and amplitude imbalance in gain range 1;
   it is used by the system to correct the curves for this imbalance.
   Currently, RSB parameters are not being measured. The default value to use is 10000.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_DO_GSM_AUTOCAL(
   HANDLE hResourceContext,
   short iPower,
   unsigned short iPA_DAC_Value,
   long iMax_Power,
   long iMin_Power,
   unsigned char iWriteNVFlag,
   unsigned short iRSB_Cor_A_R0,
   unsigned short iRSB_Cor_A_R1,
   unsigned short iRSB_Cor_B_R0,
   unsigned short iRSB_Cor_B_R1);

/******************************************************************************/
/**
Gets the logged results from QLIB_FTM_DO_GSM_AUTOCAL.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param piNumPoints = number of measured points.  The maximum size will be 500, as set
                    by QMSL, so all arrays below should be at least 500 elements.


\param aiDAC_Values = Array of DAC values used for the sweep.
                       Number of elements filled in is the same as iNumPoints

\param afAMAM_Values = Array of AMAM values. Number of elements filled in is the same as iNumPoints .
\param afAMPM_Values = Array of AMpm values. Number of elements filled in is the same as iNumPoints .

\return true if successful, false if fail.

\warning  QLIB_FTM_DO_GSM_AUTOCAL must be called first otherwise the FTM2 logs will not be properly configured.

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_DO_GSM_AUTOCAL_GetResults(
   HANDLE hResourceContext,
   unsigned short* piNumPoints,
   unsigned short aiDAC_Values[],
   float afAMAM_Values[],
   float afAMPM_Values[]
);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.3 Set path delay

This API is used to introduce delays into the phase or envelope paths in the MSM to ensure that
the waveform does not become distorted. If the delay is a positive number the envelope path is delayed.
When the delay is negative, the phase path is delayed. The delay is in units of 1/416 us ~ 2.403 ns.
This API returns the delay in a packet format that can then be stored in NV memory.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  piDelay   = input/output, Positive delay -> envelope path delayed
                           Negative delay -> phase path delayed

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_PATH_DELAY( HANDLE hResourceContext, short *piDelay);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.3 Set path delay

This function is the same as QLIB_FTM_SET_PATH_DELAY(), except the input
and output delay values are separated into 2 variables instead of one.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  iDelay_input = input, Positive delay -> envelope path delayed
                           Negative delay -> phase path delayed

\param  piDelay_output  = output, Measured value returned from FTM operation
                                    Positive delay -> envelope path delayed
                           Negative delay -> phase path delayed

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_PATH_DELAY_V2(
   HANDLE hResourceContext,
   short iDelay_input,
   short *piDelay_output );

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.4 Enable Polar Ref Cal

This API is used by the SetPADAC API in Polar targets (MSM6275). When issued with the enable parameter set to
true, it allows the user to populate the entire AMAM table with the same DAC value. This has the same effect
as writing directly to the PA DAC. In order to return to regular transmit operation, and use the
measured AMAM curves, this API must be called with the enable parameter set to false.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  iEnable   =  1--enable , 0--disable

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_ENABLE_POLAR_REF_CAL( HANDLE hResourceContext,unsigned char iEnable);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.5 Set Two-tone Freq Offset

This API is used in conjunction with the Set OPLL bandwidth API and the tx.? API in GSM to calibrate the
Tx bandwidth. The tx.? API can be used to transmit a two-tone waveform that has one tone at center frequency
and another tone offset from the center. The offset in frequency of the second tone from the first is set
by this API. The difference in amplitude between the two tones is dependent on the frequency response of the OPLL.
This can be measured and the Set OPLL Bandwidth API can be programmed to achieve the required response.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  iFreqOffsetSecTone = Frequency offset of second tone specified in kHz, e.g., 5 MHz, will be specified as 5000

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_TWOTONE_FREQ_OFFSET( HANDLE hResourceContext, unsigned short iFreqOffsetSecTone);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.6 Do Calpath RSB

This API is used to measure the phase and amplitude imbalance, i.e., RSB or residual side band, in the calibration
path receiver. This API accepts two input parameters and returns two output parameters. The first parameter is a
subcommand ID, the second is a flag that should be set when the RSB measurement is completed, and the last two
parameters contain the results of the RSB measurement. The RSB measurement procedure involves multiple steps.
Each step is specified by the RSB subcommand ID.

The procedure used to measure the imbalances is as follows:

1. Turn off input to the receiver and call the API with subcommand ID 0. Clear the RSB done flag.
      This step ensures that the receiver DC is calibrated out (in gain range 0)
      before the imbalances are measured.

2. Input a strong tone (>0 dBm), offset from the carrier by about 30 to 40 kHz, to the receiver.
      Call the API with subcommand ID 4 with the RSB done flag cleared. This measures the RSB and returns
      the correction values A and B. These parameters should be written to NV for use during Autocal measurements.

3. Turn off input to the receiver and call the API with subcommand ID 1 with the RSB done flag cleared.
      This step ensures that the receiver DC is calibrated out (in gain range 1) before the imbalances are measured.

4. Repeat Step 2 but set the RSB done flag. This indicates that the measurement is completed and the
      internal variables can be reset. If this flag is not set, the phone will be in an invalid state and
      other APIs might not function.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  iRSB_Subcmd_ID  =  0 = Do dc calibration in gain range 0
                                       1 = Do dc calibration in gain range 1
                                       2,3 = Unused
                                       4 = Measure RSB
\param iDone_RSG = Done measuring RSB (Used to reset internal state)
\param piRSB_A = Measured RSB correction value - A
\param piRSB_B = Measured RSB correction value - B

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_DO_CALPATH_RSB(HANDLE hResourceContext,unsigned char iRSB_Subcmd_ID, unsigned char iDone_RSG, unsigned short* piRSB_A, unsigned short* piRSB_B);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.7 Set OPLL bandwidth

This API is used to adjust the OPLL bandwidth. It is used in conjunction with the tx.? API and the Set
two-tone frequency offset API to adjust the 3-dB bandwidth of the OPLL. It accepts a parameter that takes values
between 1 and 9. The bandwidth increases with increasing values of this parameter.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  iBandwidth_Num  = Number used to adjust OPLL bandwidth options are 1 to 9

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_OPLL_BW(HANDLE hResourceContext,unsigned char iBandwidth_Num);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.8 Baseband bandwidth Cal

This API allows for calibration of the RF-baseband bandwidth. The bandwidth of the RF baseband can be set by
issuing this API with a parameter between 0 and 15. The number that results in the best transmit spectrum is
then written to NV for use by software.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  iBandwidth_Num = Number used to increase the RF-baseband bandwidth

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_BASEBAND_BW_CAL(HANDLE hResourceContext,unsigned char iBandwidth_Num);


/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.9 Polar Tx Sweep Cal

This API allows for AMAM and AMPM calibration of the PA. A sequence of DAC and Duration are the inputs.
The transmitter transmits the sequence of given DAC values for the durations specified.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  numDac   : size of  dacList

\param  dacList  : Array of DACs to be transmitted

\param  dacDuration : Array of dacDurations.

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_POLAR_TX_SWEEP_CAL(HANDLE hResourceContext,unsigned long numDac, unsigned long * dacList, unsigned long * dacDuration );


/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.10 TX_RSB_DC_SWEEP

This API turns on the transmitter and sweeps through the specified RSB and DC correction
parameters. Each set of correction parameters are programmed for the specified duration (in units
of 1 symbol period or 3.692 us). The resulting waveform can be used in conjunction with external
measurements to find the correction values that result in the lowest Tx RSB and Tx DC values.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param iListSize = Number of steps that will be in the sweep.  For each step, there is an element
                   in the other input arrays (Alpha, Beta, IDC, QDC, Segement length)

\param aiAlpha = input, Array of Alpha value set during first segment (one of the two Tx RSB correction parameters)
\param aiBeta = input, Array of Beta value set during first segment (one of the two Tx RSB correction parameters)
\param aiI_DC_Correction = input, Array of DC corrections on I channel
\param aiQ_DC_Correction = input, Array of DC corrections on Q channel
\param aiSegmentLength = input, Array of segment length values, units are 3.692 us (microseconds)
\param piStatus = output, 0 - Success, 1 - Failure

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_TX_RSB_DC_SWEEP(
   HANDLE hResourceContext,
   unsigned char iListSize,
   short* aiAlpha,
   short* aiBeta,
   char* aiI_DC_Correction,
   char* aiQ_DC_Correction,
   unsigned short* aiSegmentLength,
   unsigned short* piStatus
);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.11 GSM_DETECTOR_CAL

This API is used to calibrate the transmit RF chipset's output power to expected levels.

This is required to ensure that process variations do not cause variation in output power across different phones.

This must be done prior to FTM_GSM_POLAR_TX_SWEEP_CAL, which is used to calibrate the PA's non-linearity.


In order to calibrate the RF chip's output power, the RF gain setting is varied and an internal power
detector is read. This command then searches through different gain settings until a required power detector
reading is obtained.

The inputs to this command are the required power detector setting (in units of unsigned 8-bits)
and a tolerance value. The command then settles to a power detector setting in the range -
Required detector settings - tolerance <= final reading <= Required detector settings + tolerance

Once this calibration is completed, the resulting value is programmed to hardware.

In addition, the command computes the gain settings required for cold temperature and
hot temperature conditions.  These values are optionally stored in NV for future use during
temperature compensation. The command also accepts a flag specifying whether the resulting
gain settings (at cold, room and hot temperature) should be stored to NV.

When the flag is true, the results are stored to NV.
The NV item names used are:
\code
    NV_<band>_PA_TEMP_COMP_INDEX_10_I.
       - Each NV item has an array of numbers where the results are stored. The order in which
         the results are stored is illustrated below:

            - NV_<band>_PA_TEMP_COMP_INDEX_10_I.value[0] = cold temp setting
                        -                             = max( room temp setting - 20, 0)

            - NV_<band>_PA_TEMP_COMP_INDEX_10_I.value[1] = room temp setting.
            - NV_<band>_PA_TEMP_COMP_INDEX_10_I.value[2] =  high temp setting.
                                                         = min( room temp setting + 60, 255)
\endcode
\param iDetVal = Input, This is the target power detector code to be achieved
\param iTol    = Input, This is the tolerance allowed when searching for the target value.
\param iStoreRes  = Input,
   \code
         0- Do not write the results to NV.
         1- Write the results to NV.
   \endcode

\param piVgaOut   = Output, Gain setting that causes the target power detector setting. This
              Output, is the "room temp setting" value that is written to NV.
\param piDetOut   = Output, Final power detector setting that was achieved. This should be within +/-
              tolerance of required target, unless the search could not converge within
           the required limit.
\param piStatus   =  Output,
    \code
         0 - Success
         0xFFFF - Failure. The required target could not be achieved within the given tolerance.
   \endcode

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_DO_TX_DETECTOR_CAL(
   HANDLE hResourceContext,
   unsigned char iDetVal,
   unsigned char iTol,
   unsigned char iStoreRes,
   unsigned char* piVgaOut,
   unsigned char* piDetOut,
   unsigned short* piStatus
);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.xx GSM_KVCO_CAL

This API is used to calibrate the VCO of the GSM Tx.

This must be done prior to FTM_GSM_POLAR_TX_SWEEP_CAL, which is used to calibrate the PA's non-linearity.

\param iLowChan   = Input, First channel. (Low edge of the band)
\param iHiChan = Input, Second channel. (High edge of the band)
\param piLowChanKvco = Output, First channel Kvco Value
\param piHiChanKvco  = Output, Second channel Kvco Value

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_DO_TX_KV_CAL(
   HANDLE hResourceContext,
   unsigned short iLowChan,
   unsigned short iHiChan,
   unsigned short *piLowChanKvco,
   unsigned short *piHiChanKvco
);

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.xx GSM_KVCO_CAL_V2

This API is used to calibrate the VCO of the GSM Tx - multiple bands/channels in one command

This must be done prior to FTM_GSM_POLAR_TX_SWEEP_CAL, which is used to calibrate the PA's non-linearity.

\param iNumBands  = Input, Number of Bands
\param iNumTxCycles  = Input, Number of Tx Cycles
\param iNumMeas   = Input, Number of measurements / cycle
\param piRfModeList  = Input, List of RF Modes
\param piKvChanCode  = Input/Output. Input : Channel List, 2 per band, one low and one high.
                                     Output: Kv Code List, 2 per band, per channel


\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_DO_TX_KV_CAL_V2(
   HANDLE hResourceContext,
   unsigned short iNumBands,
   unsigned short iNumTxCycles,
   unsigned short iNumMeas,
   unsigned short *piRfModeList,
   unsigned short *piKvChanCode
);
/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.12 TX_4xFMOD_SWEEP

This API is used to measure the RF setting that yields the lowest spur at the 4xfMod frequency.
The 4xfMod frequency is offset from the modulating frequency by 4 times the modulating frequency.

The modulating frequency used in this command is 13/192 MHz or 67.7kHz. Therefore this spur
would be at 67.7+4*67.7 = 5*67.7 kHz or at 67.7-4*67.7 = -3*67.7kHz.

Each possible set of RF settings that can affect this spur is identified by a unique index.

This command turns on the transmitter and steps through all possible indices.

The first step is considered a trigger and the RF setting for this step should be ignored.
In order to trigger the measurement instrument on the first step, the user must first call the
FTM_SET_TWOTONE_FREQ_OFFSET api to set the frequency offset to the 4xfMod frequency.
This will generate a tone at the 4xfmod frequency for the first step.

Following this, the remainder of the steps will each be programmed at one of the possible
RF indices. Thus steps 2 - N of the sweep will cycle through RF settings 1 to (N-1).
The command accepts the following 2 inputs:

   1. The duration of each step in units of symbols (i.e 3.692us). The duration must not
       be set very low, or else the measuring instrument will not be able to distinguish
      between steps. This number may be chosen based on the measurement resolution.

   2. The trigger level (in units of DAC level). This turns on the transmitter to the
       specified DAC level. In the first step this transmit power will be at the frequency
      offset specified by FTM_SET_TWOTONE_FREQ_OFFSET. Following the first step, this
      transmit power will move to 67.7 kHz.

The measurement box (spectrum analyzer) must be setup to measure the spur at the specified
4xfmod frequencies to capture this sweep. The user (or program that calls this API) may then
gather results of this sweep and write the best index to NV item name - NV_<band>_PA_TEMP_COMP_INDEX_11_I.

Note - This command will not write to NV. The user is responsible for measuring the sweep,
       finding the best index and writing that index to the above mentioned NV item.

\param iSegLength    = Duration of each step in units of symbols per step
\param iDACLevel     = DAC level of trigger step.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_TX_4X_FMOD_SWEEP(
   HANDLE hResourceContext,
   unsigned short iSegLength,
   unsigned short iDACLevel
);


/******************************************************************************/
/**
Factory Test Mode GSM Polar Command 2.xx TX_CS_SWEEP

This API turns on the transmitter and sweeps through the specified DC correction
parameters. Each set of correction parameters are programmed for the specified duration (in units
of 1 symbol period or 3.692 us). The resulting waveform can be used in conjunction with external
measurements to find the correction values that result in the lowest Tx DC (Carrier Suppression) values.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param iListSize = Number of steps that will be in the sweep.  For each step, there is an element
                   in the other input arrays (IDC, QDC, Segement length)

\param aiI_DC_Correction = input, Array of DC corrections on I channel
\param aiQ_DC_Correction = input, Array of DC corrections on Q channel
\param aiSegmentLength = input, Array of segment length values, units are 3.692 us (microseconds)
\param piStatus = output, 0 - Success, 1 - Failure

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_TX_CS_SWEEP(
   HANDLE hResourceContext,
   unsigned char iListSize,
   short* aiI_DC_Correction,
   short* aiQ_DC_Correction,
   unsigned short* aiSegmentLength,
   unsigned short* piStatus
);

/******************************************************************************/
/**
Factory Test Mode GSM Set SMPS PDM Command

This API is used in QE2 Targets for PAC DAC Calibration and PA DC DC PDM calibration.

\param  iPdm   : SMPS PDM value.

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_SET_SMPS_PDM(HANDLE hResourceContext,unsigned short iPdm);

/******************************************************************************
                  GSM Linear Tx FTM
*******************************************************************************/

/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.x.xx Tx Set PA Range

   Sets up Linear PA Range

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param iSlotNum = input, Specifies the slot for which the PA range is set
\param iPaRange = input, Specifies the PA Range to be set.

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_SET_GSM_LINEAR_PA_RANGE(HANDLE hResourceContext, unsigned short iSlotNum,
                                                        unsigned short iPaRange );


/******************************************************************************/
/**
Factory Test Mode GSM Commands 3.x.xx DA Calibration

   GSM Tx DA Calibration

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param iListSize = input, Number of segments
\param aiSegLength = input, array, Duration of each segment. Unit 3.692uS
\param aiRgi = input, array, Rgi of each segment
\param abGsmMode = input, array, Mode of each segment. GSM mode - 1, EDGE Mode - 0
\param aiPaRange = input, array, PA Range of each segment

\return true if successful, false if fail.

\warning

\note This function can be used in QMSL FTM Sequencer operation

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_DA_CAL(HANDLE hResourceContext,
                                       unsigned short iListSize,
                                       unsigned short*  aiSegLength,
                                       unsigned char *  aiRgi,
                                       unsigned char *  aiGsmMode,
                                       unsigned char *  aiPaRange
                                      );

/******************************************************************************/
/**
Factory Test Mode GSM V4 Calibration

This API performs calibration for multiple bands/channels/chains, and Tx/Rx in a single sweep.
- Configures the Frame Sweep Cal

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param aGSM_V4_Cal_CMD    = pointer to GSM V4 command array

\param iGSM_V4_Cal_CMD_Len = length in bytes of the apGSM_V4_Cal_CMD array

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_V4_CAL( HANDLE hResourceContext, void* aGSM_V4_Cal_CMD, unsigned short iGSM_V4_Cal_CMD_Len );

QLIB_API unsigned char QLIB_FTM_GSM_V4_CAL_COMPRESSED(HANDLE hResourceContext, void* aGSM_V4_Cal_CMD, unsigned short iGSM_V4_Cal_CMD_Len );

/******************************************************************************/
/**
Factory Test Mode GSM V4 Calibration - disable predistortion on the UE.

This API performs calibration for multiple bands/channels/chains, and Tx/Rx in a single sweep.
- disable predistortion on the UE.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param iGSM_ChainID = indicates the Tx/Rx chain for which predistoriton is being disabled

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_V4_DISABLE_PREDIST( HANDLE hResourceContext, unsigned short iGSM_ChainID );


/******************************************************************************/
/**
Factory Test Mode GSM V4 Calibration - executes the configured frame sweep

This API performs calibration for multiple bands/channels/chains, and Tx/Rx in a single sweep.
- Executes the Frame Sweep Cal
- QLIB_FTM_GSM_V4_CAL() must be called prior to this command.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_V4_CAL_EXECUTE_SWEEP( HANDLE hResourceContext );


/******************************************************************************/
/**
Factory Test Mode GSM V4 Calibration - returns measured results from phone.

This API performs calibration for multiple bands/channels/chains, and Tx/Rx in a single sweep.
- returns measured results from phone.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param psGSM_V4_Cal_FTM_Results = GSM_V4_FTM_CMD_Response_Type struct containing the measured results from the phone.

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_V4_CAL_GET_RESULTS( HANDLE hResourceContext, void* psGSM_V4_Cal_FTM_Results );


/******************************************************************************/
/**
Factory Test Mode GSM V4 Calibration - performs cleanup on the phone

This API performs calibration for multiple bands/channels/chains, and Tx/Rx in a single sweep.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_V4_CAL_CLEANUP( HANDLE hResourceContext );

/******************************************************************************/
/**
Factory Test Mode GSM RF Test Commands CL93-V5370-1

This command sets GSM PA Bias NV items namely RFNV_GSM_<chain>_<band>_SMPS_PDM_TBL_I,RFNV_GSM_<chain>_<band>_PA_ICQ_BIAS
based on the packet information from diag.
For each band, we pack the information below into the diag packet:
1. Online smps pdm per modulation and pcl.
2. Cal smps pdm per pa gain state.
3. Pa icq bias per modulation and rgi.
Embedded SW would set corresponding NV items using these values.

\param aGSM_SET_PA_BIAS_NV_CMD     = buffer containing the GSM SET PA BIAS NV Command

\param iGSM_SET_PA_BIAS_NV_CMD_Len = length in bytes of aGSM_SET_PA_BIAS_NV_CMD

\param _iFTM_Error_Code            =  FTM Error code returned by FTM command
*0 ?Success
*1 ?Failure occurred

\return true if successful, false if fail.

\warning

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_SET_PA_BIAS_NV(HANDLE hResourceContext, void* aGSM_SET_PA_BIAS_NV_CMD, unsigned short iGSM_SET_PA_BIAS_NV_CMD_Len, unsigned char * _iFTM_Error_Code );

/******************************************************************************/
/**
Factory Test Mode GSM Polar Command x.x Polar Tx PreDistortion Cal

This API allows for AMAM and AMPM calibration of the PA. The inputs are the preceding DC duration,
the edge duration and the following DC duration

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  iPreDcDuration  : Duration of the preceding DC waveform (Units : Quarter Symbols)

\param  iEdgeDuration   : Duration of the calibrated EDGE waveform (Units : Quarter Symbols)

\param  iCalRgi : Calibration RGI (Units : None)

\param  piDigScale : Return Scaling Factor (Units : None)

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_TX_CFG2_AMAM_SWEEP(HANDLE hResourceContext,
                                                   unsigned long iPreDcDuration, unsigned long iEdgeDuration,
                                                   unsigned long iCalRgi, unsigned long * piDigScale );


/******************************************************************************/
/**
Factory Test Mode GSM Polar Command x.x Polar Tx PreDistortion Cal

This API allows for AMAM and AMPM calibration of the PA. The inputs are the
the edge duration and the following DC duration

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

\param  iDcDuration  : Duration of the DC waveform (Units : Quarter Symbols)

\param  iEdgeDuration   : Duration of the calibrated EDGE waveform (Units : Quarter Symbols)

\param  iCalRgi : Calibration RGI (Units : None)

\param  iWaveformType : Waveform Type to be used. Default 0.

\param  piDigScale : Return Scaling Factor (Units : None)

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_TX_CFG2_AMAM_SWEEP_V2(HANDLE hResourceContext,
                                                      unsigned long iDcDuration, unsigned long iEdgeDuration,
                                                      unsigned long iCalRgi, unsigned long iWaveformType, unsigned long * piDigScale );

/******************************************************************************/
/**

Factory Test Mode GSM RF Test Commands CL93-V5370-1
Section X.X.X FTM_GSM_SETUP_RX_BURST_FOR_EXPECTED_PWR

 This command Sets the Rx LNA range based on a target dBm downlink level.

 This API has the following runtime dependencies.

 \param hResourceContext = Resource context that was returned from the call
                           to QLIB_ConnectServer()

 \param iExpected_RX_Power_dbm16 = Indicates the expected Rx power in 1/16 dBm units

\param iNumber_of_Averages = Number of Averages during actual measurement

 \param iFTM_Error_Code = FTM Error code returned by FTM command
                   * 0  Success
                   * 1  Failure occurred

 \return true if successful, false if fail.

\warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
                  It will only be available in AMSS MSM8974 equivalents according to the
                  Factory Test Roadmap document 80-NC791-1

 \note This function can be used in QMSL FTM Sequencer operation

 *******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_SETUP_RX_BURST_FOR_EXPECTED_PWR( HANDLE hResourceContext,
                                                                     unsigned short iExpected_RX_Power_dbm16,
                                                                     unsigned short iNumber_of_Averages,
                                                                     unsigned short* iFTM_Error_Code);

/******************************************************************************/
/**

Factory Test Mode GSM RF Test Commands CL93-V5370-1
Section X.X.X FTM_GSM_GET_MEAS_PWR

 This command Returns the Rx level, in both Rx RSSI and dBm16 units.

 This API has the following runtime dependencies.

 \param hResourceContext = Resource context that was returned from the call
                           to QLIB_ConnectServer()

 \param iMeasured_Dbm16_Value = Indicates the measured Rx power in 1/16 dBm units

\param iRaw_RSSI = Indicates the GSM RX RSSI value

 \param iFTM_Error_Code = FTM Error code returned by FTM command
                   * 0  Success
                   * 1  Failure occurred

 \return true if successful, false if fail.

\warning 2012.09: this function is not officially released in AMSS MSM8960 equivalents.
                  It will only be available in AMSS MSM8974 equivalents according to the
                  Factory Test Roadmap document 80-NC791-1

 \note This function can be used in QMSL FTM Sequencer operation

 *******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_GET_MEAS_PWR ( HANDLE hResourceContext,
                                                   unsigned short* iMeasured_Dbm16_Value,
                                                   unsigned long*  iRaw_RSSI,
                                                   unsigned short* iFTM_Error_Code);
QLIB_API unsigned char QLIB_FTM_GSM_GET_MEAS_PWR_DRX ( HANDLE hResourceContext,
                                                       unsigned short* iMeasured_Dbm16_Value,
                                                       unsigned long*  iRaw_RSSI,
                                                       unsigned short* iFTM_Error_Code);

/******************************************************************************/
/**
Factory Test Mode GSM Command API Doc CL93-V5370-1 section 3.1.xx Cmd Id 247 FTM_GSM_SET_LINEAR_RGI Set Linear RF Gain Index

This API forces the transmitter to use the specified RF gain index. When this API is used the
baseband (TX gain) setting will be switched to default (i.e. the value in the NV item
-NV_GSM_LINEAR_TX_GAIN_PARAM_I for GMSK transmit or to NV_EDGE_LINEAR_TX_GAIN_PARAM_I for 8PSK transmit).
The pa range is held at that current setting.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iSlotNum = input, Slot number to which this setting should be applied. The slot number should correspond
               to the slot number in the TX frame matrix and the Tx Frame matrix should reflect this
               slot as being on , else this API has no effect
\param  iRgiIndex = input, The RF gain index to use
\param  iModType = input, Flag specifying if the modulation type is GSM/EDGE . 1- refers to GSM and 0 - EDGE

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_SET_LINEAR_RGI( HANDLE hResourceContext,
                                                    unsigned short iSlotNum,
                                                    unsigned short iRgiIndex,
                                                    unsigned char iModType
                                                  );


/******************************************************************************/
/**
Factory Test Mode GSM Command API Doc CL93-V5370-1 section 3.1.xx Cmd Id 308 FTM_GSM_TX_ENVDC_CS_SWEEP Envelope DC Carrier Suppression Sweep

This API is only used for targets with Linear PAs. This API is very similar to the carrier suppression
sweep that is performed by applying a IQ DC offset on the IQ lines. The only difference here is that
the offset is applied to the Envelope path, in a linear target. On Linear targets, the RF impairment
that causes carrier leakage can be modeled as a DC offset on the envelope path. To counteract this
impairment, an equal and opposite DC offset can be applied to the Envelope path at baseband.
This command turns programs a CW tone and turns on the transmitter to transmit at an offset of about
200Khz from center frequency. It then sweeps through a number of DC offset values. The call box should
be set to measure the carrier leakage at center frequency. The call box returns the amplitude of the
carrier leakage across all the steps to the PC tools , which then determines the DC offset value
corresponding to the lowest carrier leakage.

\param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iNumSteps = input, Number of steps
\param  aiStepDuration = input, array, duration of step in units of quarter symbols (i.e., 0.923 us)
\param  aiDcValue = input, array, DC values

\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_TX_ENVDC_CS_SWEEP( HANDLE hResourceContext,
                                                       unsigned short iNumSteps,
                                                       unsigned short* aiStepDuration,
                                                       unsigned short* aiDcValue );

/******************************************************************************/
/**
Factory Test Mode GSM Command API Doc PENDING
This API is used to do the GSM Input Intercept Point (IIP2) calibration. IIP2 is  is a measure of
linearity that quantifies the second-order distortion generated by nonlinear systems and devices.
 \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
 \param use_default_params = input, whether to use default params or override it.
 \param start_i_code = input, start I_Code.
 \param start_q_code = input, start_q_code.
 \param rfcom_band = input,  rfcom_band.
 \paramunit_step_size = input, unit_step_size.
 \param width = input, width.
 \param arfcn = input, arfcn.
 \param  tx_rgi = input,  tx_rgi.
 \param  lna_range = input,  lna_range.
 \param  num_frames = input,  num_frames.
 \param step_duration_qs = input, step_duration_qs.
 \param dc_settling_time_qs = input, dc_settling_time_qs.
 \params[out] final_q_code = return final q code
 \params[out] final_i_code = return final i code
 \param[out] min_im2_result = return min_im2 result
 \param [out] status = status flag.
\return true if successful, false if fail.

\warning  none

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_DO_IP2_CAL( HANDLE hResourceContext,
                                                unsigned char use_default_params,
                                                short start_i_code,
                                                short start_q_code,
                                                unsigned char rfcom_band,
                                                unsigned char  unit_step_size,
                                                unsigned char  width,
                                                unsigned short arfcn,
                                                unsigned char  tx_rgi,
                                                unsigned char  lna_range,
                                                unsigned char  num_frames,
                                                unsigned short step_duration_qs,
                                                unsigned short dc_settling_time_qs,
                                                short& final_q_code,
                                                short& final_i_code,
                                                int& min_im2_result,
                                                unsigned char& status);


/******************************************************************************/
/**
Uses FTM_GSM_SET_ALT_PATH (FTM API) command for overwriting the alternate path in FTM mode.

\param  hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iEnable          = used to enbable/disable the overwriting of the alternate path.
   \code
      0 = disable,
      1 = enable
   \endcode
\param  iAltPath      = specifies the alternate path to use.
\param  iGSM_PrimPath = This is the primary Tx/Rx chain/path that was calibrated, not the alternate path.
      - For example, the primary path could be 0, but the alternate path could be 3.
\param  iStatus       = Reference to storage area for status

\return true if successful, false if fail.

\warning None.

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_SET_ALT_PATH
( HANDLE hResourceContext, unsigned char iEnable, unsigned char iAltPath, unsigned short iGSM_PrimPath, unsigned short* piStatus );


/******************************************************************************/
/**
QLIB_FTM_GSM_SET_DEVICE_AND_SIG_PATH

Uses FTM_GSM_SET_DEVICE_AND_SIG_PATH (FTM API) command for setting up the Tx,PRx and DRx devices to use in FTM mode.

\param  hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iPrxDev          = Prx Device
\param  iDrxDev          = Drx Device
\param  iTxDev           = Tx Device
\param  iPrxSigPath      = Prx SigPath
\param  iDrxSigPath      = Drx SigPath
\param  iTxSigPath       = Tx SigPath

\return true if successful, false if fail.

\warning None.

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_SET_DEVICE_AND_SIG_PATH
( HANDLE hResourceContext, unsigned char iPrxDev, unsigned char iDrxDev, unsigned char iTxDev,
  unsigned char iPrxSigPath, unsigned char iDrxSigPath, unsigned char iTxSigPath);

/******************************************************************************/
/**
QLIB_FTM_GSM_SET_ASDIV_PATH

Uses FTM_GSM_SET_ASDIV_PATH (FTM API) command for setting up the AS Div Path to use in FTM mode.

\param  hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  iAntSwDivPath    = ASDIV Path

\return true if successful, false if fail.

\warning None.
*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_SET_ASDIV_PATH( HANDLE hResourceContext, unsigned char iAntSwDivPath);

/******************************************************************************/
/**
Uses FTM_GSM_GET_NV_CONTAINER (FTM API) command for determining which NV to write to during alternate path calibration for GSM.

Given a band, Rx/Tx indicator, and the ID of the primary path that was calibrated, this function returns an enum indicating the
 NV container to use for the alternate path.

\param  hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  pNvContainer     = Reference to storage area for data
\param  iBand            = the "nv_mode_id_type" (10,18,11,12) indicating for which band the NV Container is desired.
   \code
      10 = EGSM,
      18 = G850,
      11 = DCS,
      12 = PCS
   \endcode
\param  iTxOrRx       = indicates whether the Tx or Rx NV container is desired.
   \code
      0 = Primary Rx,
      1 = Tx
      2 = Diversity Rx
   \endcode
\param  iGSM_PrimPath = This is the primary Tx/Rx chain/path that was calibrated, not the alternate path.
      - For example, the primary path could be 0, but the alternate path could be 3.
\param  iStatus       = Reference to storage area for status

\return true if successful, false if fail.

\warning None.

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_GET_NV_CONTAINER
(HANDLE hResourceContext, unsigned char* pNvContainer, unsigned char iBand, unsigned char iTxOrRx, unsigned short iGSM_PrimPath, unsigned short* piStatus);


/******************************************************************************/
/**
Uses FTM_GSM_GET_ENV_GAIN_NV_DATA (FTM API) command for reading NV data for GSM.

\param  hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
\param  itemID           = Enumeration ID of NV Item [NOTE - THIS INPUT IS UNNECESSARY]
\param  pItemData        = Reference to storage area for data
\param  piLength         = size of data, in bytes
\param  piStatus         = Reference to storage area for status
\code
  NV_DONE_S = 0,      // Request completed okay
  NV_FAIL_S = 1       // Request failed
\endcode
\param  retType          = Indicates if the 1st, 2nd, or 3rd element of ftm_gsm_env_gain_nv_data_type is desired.
\code
   retType = 1 -> gsm_linear_tx_gain_val (this is the default)
   retType = 2 -> edge_linear_tx_gain_val
   retType = 3 -> charpredist_env_gain[16]
 \endcode

The FTM_GSM_GET_ENV_GAIN_NV_DATA command returns a 10 byte header followed by the 20 byte struct shown below, ftm_gsm_env_gain_nv_data_type.

typedef PACK(struct)
{
   uint16 gsm_linear_tx_gain_val;
   uint16 edge_linear_tx_gain_val;
   uint8 charpredist_env_gain[16];
}ftm_gsm_env_gain_nv_data_type;

\return true if successful, false if fail.

\warning None.

*******************************************************************************/
QLIB_API unsigned char  QLIB_FTM_GSM_API_ReadEnvGainNV
(HANDLE hResourceContext, unsigned short iItemID, unsigned char* pItemData, unsigned short *piLength, unsigned short* piStatus, unsigned short retType);

/******************************************************************************/
/**
Uses FTM_GSM_FBRX_CAL (FTM API) command for performing GSM FBRx Gain Cal

\param  iGSM_PrimPat   = chain
\param  iModType       = specifies the modulation to use.
   \code
      0 for GMSK
      1 for 8PSK
\param  iPaRange      = specifies the PA state to use
\param  iRGI          = specifies the RGI to use
\param  iFBRxGain     = specifies the FBRx Gain State to use
\param  iEn_Debug     = to enable debug mode or not
\param  piStatus      = FBRx cal status
   \code
      1 FTM_GSM_FBRX_GAIN_CAL_NOT_GSM_STATE
      2 FTM_GSM_FBRX_GAIN_CAL_INVALID_CHANNEL
      3 FTM_GSM_FBRX_GAIN_CAL_IQ_CAPTURE_FAILURE
\param *piRawPower = FBRx Gain value is returned from API

\return true if successful, false if fail.

\warning None.

*******************************************************************************/
QLIB_API unsigned char QLIB_FTM_GSM_FBRX_CAL
(HANDLE hResourceContext,  unsigned short iGSM_PrimPath, unsigned char iModType, unsigned char iPaRange, unsigned short iRGI, unsigned char iFBRxGain, unsigned char iEn_Debug, unsigned char* piStatus, unsigned char *piModType, unsigned char* piPaRange, unsigned short* piRGI, unsigned char* piFBRxGain, int* piRawPower );

/******************************************************************************/
/**
Uses GSM_Generate_SELFTEST_FBRX_GAIN_FREQ_NV command for generating GSM_SELFTEST_FBRX_GAIN_FREQ_NV

\param  measurement_type   = GSM_GAIN_NV_TYPE_ID
\param  rf_mode            = specifies the rf mode to use.
   \code
      10 = EGSM,
      18 = G850,
      11 = DCS,
      12 = PCS
\param  num_channel      = number of channel for this rf mode
\param  channel_list     = channel lists
\param  num_elements     = number of elemets in fbrx_gain_cal_data
\param  fbrx_gain_cal_data   = all bytes

\return true if successful, false if fail.

\warning None.

*******************************************************************************/
QLIB_API unsigned char QLIB_RFCAL_Generate_GSM_FBRX_CAL_NV( HANDLE hResourceContext, unsigned short measurement_type, int rf_mode, unsigned int num_channel, std::vector<int>& channel_list, unsigned int num_elements,void* fbrx_gain_cal_data);
#ifdef __cplusplus
}  // extern "C"
#endif

#endif   // defined(_QLIB_FTM_GSM_RF_H)

