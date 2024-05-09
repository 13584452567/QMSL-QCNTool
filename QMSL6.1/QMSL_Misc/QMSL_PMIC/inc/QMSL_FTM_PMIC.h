/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Misc/QMSL_PMIC/inc/QMSL_FTM_PMIC.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_PMIC
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_PMIC_H)
#define _QMSL_FTM_PMIC_H

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
                     PMIC FTM
   *******************************************************************************/


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 2.1  RTC Set or Get Time Command

   Sets or gets the phone's real time clock.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param   iReadWrite = 0 - Set Time, 1 - Get Time
   \param   iTimeMode = 0 - 12 hour format (AM), 1 - 12 hour format (PM), 2 - 24 hour format
   \param   iMonth = Month to set/get (1...12), 1 - January...12 - December
   \param   iDay = Day of Month.  Valid range is [0,31]
   \param   iYear = Year to set/get.  Valid range is [1980,2116]
   \param   iHour = Hour field of RTC time to set/get.  Valid range depends on time_mode field.
                  For time_mode = 0 or 1, valid range is [1,12].  For time_mode = 2, valid range is [0,23].
   \param   iMinute = Minute field of RTC time to set/get.  Valid range is [0-59]
   \param  iSecond =Second field of RTC time to set/get.  Valid range is [0-59]

   \return true if successful, false if fail.

   \warning If a "Get" operation is selected then the "by reference" values will be updated.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_RTC_SET_GET_TIME
   (
      HANDLE hResourceContext, unsigned char iReadWrite, unsigned char* iTimeMode, unsigned char* iMonth,
      unsigned char* iDay, unsigned short* iYear, unsigned char* iHour, unsigned char* iMinute,
      unsigned char* iSecond
   );

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 2.2  RTC Set or Get Alarm Time Command

   Sets or gets the phone's real time clock alarm.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param   iReadWrite = 0 - Set Alarm Time, 1 - Get Alarm Time
   \param  iAlarmId = 0 - RTC_ALARM_1, 1 - RTC_ALARM_2, 2 - RTC_ALARM_3,
           Note: RTC_ALARM_2 and RTC_ALARM_3 are not currently supported.

   \param   iTimeMode = 0 - 12 hour format (AM), 1 - 12 hour format (PM), 2 - 24 hour format
   \param   iMonth = Month to set/get (1...12), 1 - January...12 - December
   \param   iDay = Day of Month.  Valid range is [0,31]
   \param   iYear = Year to set/get.  Valid range is [1980,2116]
   \param   iHour = Hour field of RTC time to set/get.  Valid range depends on time_mode field.
               For time_mode = 0 or 1, valid range is [1,12].  For time_mode = 2, valid range is [0,23].
   \param   iMinute = Minute field of RTC time to set/get.  Valid range is [0-59]
   \param  iSecond =Second field of RTC time to set/get.  Valid range is [0-59]

   \return true if successful, false if fail.

   \warning If a "Get" operation is selected then the "by reference" values will be updated.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_RTC_SET_GET_ALARM_TIME(
      HANDLE hResourceContext, unsigned char iReadWrite, unsigned char* iAlarmId,
      unsigned char* iTimeMode, unsigned char* iMonth,
      unsigned char* iDay, unsigned short* iYear, unsigned char* iHour, unsigned char* iMinute,
      unsigned char* iSecond);


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 2.3  RTC Stop Command

   Stop the real time clock

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_RTC_STOP( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 2.4  RTC Get Alarm Status Command

   Get the alarm status

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iAlarmStatus = Status bits.  Alarm 1 trigger status is returned in bit 0 of alarm_status.
                          Alarms 2 and 3 are not currently supported, so alarm_status[7:1]
                     will always be 'b0000000.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_RTC_GET_ALARM_STATUS( HANDLE hResourceContext, unsigned char* iAlarmStatus );

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 2.5  RTC Disable Alarm Command

   Disable a RTC alarm

   \param iAlarmId = Alarm to disable, 0 - RTC_ALARM_1, 1 - RTC_ALARM_2, 2 - RTC_ALARM_3
                    Note: RTC_ALARM_2 and RTC_ALARM_3 are not currently supported.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_RTC_DISABLE_ALARM( HANDLE hResourceContext, unsigned char iAlarmId );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 2.6  RTC Set/Get Time Adjust Command

   Get or set the RTC time adjustment factor

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iReadWrite = 0 - Set Time Adjust, 1 - Get Time Adjust
   \param iTimeAdjust = 32 kHz clock adjustment to set in RTC hardware, or get the current value
                             from hardware.  Valid range is [0,127].  Actual adjustment is
                       (time_adjust-64)*3.05ppm

   \return true if successful, false if fail.

   \warning if iReadWrite = 0, then the by-reference value in iTimeAdjust will be updated

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_RTC_SET_GET_TIME_ADJUST
   ( HANDLE hResourceContext, unsigned char iReadWrite, unsigned char* iTimeAdjust );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.1  Set Charger Switch Command

   Configure the charger switch

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param   iChargerSwitchType =
   \code
               0 - CHG_SWITCH_WALL_CHGR
               1 - CHG_SWITCH_BATTERY_TRANSISTOR
               2 - CHG_SWITCH_WALL_PULSE_CHGR
               3 - CHG_SWITCH_VCP
               4 - CHG_SWITCH_BATT_ALARM
               5 - CHG_SWITCH_COIN_CELL
               6 - CHG_SWITCH_USB_CHGR
               7 - CHG_SWITCH_APP_CODE

   \endcode
               Note.  In the case of chg_switch_type = 7, this represents the application level code
            that handles the charger state machine.

            Disabling this switch resets the state machine and initializes the charger to a default state.

   \param   iChargerSwitchCommand = 0 - Disable Switch, 1 - Enable Switch

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CHG_SET_SWITCH_STATE
   ( HANDLE hResourceContext, unsigned char iChargerSwitchType, unsigned char iChargerSwitchCommand );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.2.1  Wall Pulse Charger Config

   Configure wall pulse charging

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChargerType = 0 - Q_LOW_SIDE, 1 - Q_HIGH_SIDE
   \param iTimeOn = Time on during pulse cycle
      \code
         0 - TON_62p5_MS
         1 - TON_125_MS
         2 - TON_250_MS
         3 - TON_500_MS

      \endcode
   \param iTimeOff = Time off during pulse cycle
      \code
         0 - TOFF_62p5_MS
         1 - TOFF_125_MS
         2 - TOFF_250_MS
         3 - TOFF_500_MS

      \endcode
   \param iTimeDone = Represents a t_done time as a multiple of the configured t_off time.
      \code
            0 - TOFF_X_16
            1 - TOFF_X_32
            2 - TOFF_X_64
            3 - TOFF_X_128

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CONFIG_WALL_PULSE_CHGR (
      HANDLE hResourceContext, unsigned char iChargerType,
      unsigned char iTimeOn, unsigned char iTimeOff, unsigned char iTimeDone
   );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.2.2  VBATT detect voltage Config

   Voltage threshold to enable wall pulse charging

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVbattDetectVoltage = Voltage level in mV

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CONFIG_WALL_PULSE_CHGR_VBAT_DET
   ( HANDLE hResourceContext, unsigned char iVbattDetectVoltage );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.2.3  Wall Charger Transistor Limits Config

   Configure the voltage and current limits of the wall charger transistor

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChargerMaxCurrent = Maximum current throught the wall charger.
                                    The current is represented by a voltage across a sense resistor, typically 0.1 ohm.
      \code

        0 - (010mV)/R
        1 - (020mV)/R
        2 - (030mV)/R
        3 - (040mV)/R
        4 - (050mV)/R
        5 - (060mV)/R
        6 - (070mV)/R
        7 - (080mV)/R
        8 - (090mV)/R
        9 - (100mV)/R
        10 - (110mV)/R
        11 - (120mV)/R
        12 - (130mV)/R
        13 - (140mV)/R
        14 - (150mV)/R
        15 - (160mV)/R
        16 - (170mV)/R
        17 - (180mV)/R
        18 - (190mV)/R
        19 - (200mV)/R
        20 - (210mV)/R
        21 - (220mV)/R
        22 - (230mV)/R
        23 - (240mV)/R
        24 - (250mV)/R
        25 - (260mV)/R
        26 - (270mV)/R
        27 - (280mV)/R
        28 - (290mV)/R
        29 - (300mV)/R

      \endcode

   \param iChargerMaxVoltage = Maximum wall transistor voltage.
      \code
         0 - VMAXSEL_4000mV
         1 - VMAXSEL_4025mV
         2 - VMAXSEL_4050mV
         3 - VMAXSEL_4075mV
         4 - VMAXSEL_4100mV
         5 - VMAXSEL_4125mV
         6 - VMAXSEL_4150mV
         7 - VMAXSEL_4175mV
         8 - VMAXSEL_4200mV
         9 - VMAXSEL_4225mV
         10 - VMAXSEL_4250mV
         11 - VMAXSEL_4275mV
         12 - VMAXSEL_4300mV
         13 - VMAXSEL_4325mV
         14 - VMAXSEL_4350mV
         15 - VMAXSEL_4375mV

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CONFIG_WALL_CHGR_TRANSISTOR_LIMITS
   ( HANDLE hResourceContext, unsigned char iChargerMaxCurrent, unsigned char iChargerMaxVoltage );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.2.4  Trickle Charger Config

   Configure the trickle charger limits

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChargerMaxCurrent = Maximum trickle charger current.
      \code
         0 - IMAX_00mA
         1 - IMAX_20mA
         2 - IMAX_30mA
         3 - IMAX_40mA
         4 - IMAX_50mA
         5 - IMAX_60mA
         6 - IMAX_70mA
         7 - IMAX_80mA

      \endcode


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CONFIG_TRICKLE_CHARGER
   ( HANDLE hResourceContext, unsigned char iChargerMaxCurrent );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.2.5  Coin Cell Charger Config

   Set the coin cell charger configuratin

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVoltageSetting = Coin Cell voltage setting
      \code
         0 - VSET_3p0V
         1 - VSET_3p1V
         2 - VSET_3p2V.

      \endcode
   \param iResistorSetting = Coin Cell resistor setting
      \code
         0 - RSET_2100_Ohms
         1 - RSET_1700_Ohms
         2 - RSET_1200_Ohms
         3 - RSET_800_Ohms

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CONFIG_COIN_CELL_CHGR
   ( HANDLE hResourceContext, unsigned char iVoltageSetting, unsigned char iResistorSetting );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.2.6  Battery Alarm Config

   Voltage threshold to enable wall pulse charging

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iUpperLimit  = Upper threshold voltage for battery alarm (mV)
   \param iLowerLimit  = Lower threshold voltage for battery alarm (mV)
   \param iHysteresisSetting  = Hysteresis setting.
      \code
         0 - HYST_122us
         1 - HYST_244us
         2 - HYST_488us
         3 - HYST_976us

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CONFIG_BATT_ALARM( HANDLE hResourceContext, unsigned short iUpperLimit,
         unsigned short iLowerLimit, unsigned char iHysteresisSetting );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.2.7  USB Charger Transistor Limit Config

   Configure the USB charger transistor

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iMaxCurrent  = Maximum current through USB pass transistor.
                              Current is given as a voltage across a sense resistor, typically 0.1 ohm.
      \code
         0 - IMAX_010mV_div_R
         1 - IMAX_020mV_div_R
         2 - IMAX_030mV_div_R
         3 - IMAX_040mV_div_R
         4 - IMAX_050mV_div_R
         5 - IMAX_060mV_div_R
         6 - IMAX_070mV_div_R
         7 - IMAX_080mV_div_R
         8 - IMAX_090mV_div_R
         9 - IMAX_100mV_div_R
         10 - IMAX_110mV_div_R
         11 - IMAX_120mV_div_R
         12 - IMAX_130mV_div_R
         13 - IMAX_140mV_div_R
         14 - IMAX_150mV_div_R
         15 - IMAX_160mV_div_R
         16 - IMAX_170mV_div_R
         17 - IMAX_180mV_div_R
         18 - IMAX_190mV_div_R
         19 - IMAX_200mV_div_R

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CONFIG_USB_TRANSISTOR_LIMITS
   ( HANDLE hResourceContext, unsigned char iMaxCurrent );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 3.2.8  Charger Power Control Limit Config

   Configure the charger power control limit

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iChargerType = Select Charger type to configure.
      \code
         0 - WALL_CHARGER
         1 - USB_CHARGER

      \endcode

   \param iMaxPower = Maximum power delivered by charger.
      \code
         0 - PMAXSEL_DISABLE
         1 - PMAXSEL_400mW
         2 - PMAXSEL_500mW
         3 - PMAXSEL_600mW
         4 - PMAXSEL_750mW
         5 - PMAXSEL_1000mW
         6 - PMAXSEL_1500mW
         7 - PMAXSEL_2000mW

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_CONFIG_PWR_CTRL_LIMIT(
      HANDLE hResourceContext,
      unsigned char iChargerType,
      unsigned char iMaxPower );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 4.1  Configure Analog Mux

   Configure the analog multiplexer

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iMuxSelect = Select AMUX channel to route to HKADC block.
                             Built-in prescaler value shown in parenthesis.
      \code
         0 - ADC_MUXSEL0 (2/3)
         1 - ADC_MUXSEL1 (1/2)
         2 - ADC_MUXSEL2 (1/8)
         3 - ADC_MUXSEL3 (none)
         4 - ADC_MUXSEL4 (1/2)
         5 - ADC_MUXSEL5 (none)
         6 - ADC_MUXSEL6 (none)
         7 - ADC_MUXSEL7 (none)
         8 - ADC_MUXSEL8 (none)
         9 - ADC_MUXSEL9 (none)
         10 - ADC_MUXSEL10 (2/5)
         11 - ADC_MUXSEL11 (none)
         12 - ADC_MUXSEL12 (none)
         13 - ADC_MUXSEL13 (none)
         14 - ADC_MUXSEL14 (none)
         15 - ADC_MUXSEL15 (disables AMUX)

      \endcode

   \param iMuxScale = Offset and gain settings to be applied to the input voltage.  Offset and gain applied after prescaler stage.
                     (Offset [Volts],Gain) shown in parenthesis
      \code
         0 - ADC_MUXSCALE0        (0, 1)
         1 - ADC_MUXSCALE1        (0, 1.25)
         2 - ADC_MUXSCALE2        (0, 1.667)
         3 - ADC_MUXSCALE3        (0, 2.5)
         4 - ADC_MUXSCALE4        (0, 5)
         5 - ADC_MUXSCALE5        (0.5, 1.25)
         6 - ADC_MUXSCALE6        (0.5, 1.667)
         7 - ADC_MUXSCALE7        (0.5, 2.5)
         8 - ADC_MUXSCALE8        (0.5, 5)
         9 - ADC_MUXSCALE9        (1, 1.667)
         10 - ADC_MUXSCALE10      (1, 2.5)
         11 - ADC_MUXSCALE11      (1, 5)
         12 - ADC_MUXSCALE12      (1.5, 2.5)
         13 - ADC_MUXSCALE13      (1.5, 5)
         14 - ADC_MUXSCALE14      (2, 5)
         15 - ADC_MUXSCALE15      (0, 1) [bypass mode]

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_AMUX_CONFIG
   ( HANDLE hResourceContext, unsigned char iMuxSelect, unsigned char iMuxScale );

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 6.1  Enable/Disable VREG Command

   Enable/disable a voltage regulator

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVRegCmd   = 0 - Disable selected regulators, 1 - Enable selected regulators

   \param iVRegSelect = Voltage regulators to perform the vreg_cmd on.  This can be a logical
                             OR of any of the following voltage regulator masks.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_CONTROL
   ( HANDLE hResourceContext, unsigned char iVRegCmd, unsigned long iVRegSelect );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 6.2  Set Voltage Level Command

   Set the voltage level of a regulator

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVRegSelect = Voltage regulator to set a desired output level.
      \code
         0 - VREG_MSMA
         1 - VREG_MSMP
         2 - VREG_MSME
         3 - VREG_MSMC1
         4 - VREG_MSMC2
         5 - VREG_MSMS
         6 - VREG_MEM
         7 - VREG_GP
         8 - VREG_CAM
         9 - VREG_TCXO
         10 - VREG_PA
         11 - VREG_RFTX
         12 - VREG_RFRX1
         13 - VREG_RFRX2
         14 - VREG_SYNT
         15 - VREG_WLAN
         16 - VREG_USB
         17 - VREG_BOOST
         18 - VREG_MMC
         19 - VREG_RUIM

      \endcode

   \param iVoltageLevel = Voltage level in millivolts to configure the selected regulator.
      \code
            Valid input range depends on the selected regulator ID.

            For VREG_PA,VREG_MSME,VREG_MSMC1,VREG_MSMC2:
               Range = [750, 1525] in 25 mV steps
                           [1550,3050] in 50 mV steps
            For VREG_BOOST and VREG_USB
               Range = [3000, 6100] in 100 mV steps
            For all other regulators
               Range = [1500, 3100] in 50 mV steps.
            NOTE: Command will support any mV input level between the lower and upper limits, but this will get rounded down
                  by PMIC driver API to the closest voltage the regulator can support (step size dependent).

               Example:  User selection of VREG_PA = 2940 mV will get converted to 2900 mV.

      \endcode
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_SET_LEVEL
   ( HANDLE hResourceContext, unsigned char iVRegSelect, unsigned short iVoltageLevel  );

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 6.X  Get Voltage Level Command

   Get the voltage level of a regulator

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVRegSelect = Voltage regulator to be queried.
      \code
         0 - VREG_MSMA
         1 - VREG_MSMP
         2 - VREG_MSME
         3 - VREG_MSMC1
         4 - VREG_MSMC2
         5 - VREG_MSMS
         6 - VREG_MEM
         7 - VREG_GP
         8 - VREG_CAM
         9 - VREG_TCXO
         10 - VREG_PA
         11 - VREG_RFTX
         12 - VREG_RFRX1
         13 - VREG_RFRX2
         14 - VREG_SYNT
         15 - VREG_WLAN
         16 - VREG_USB
         17 - VREG_BOOST
         18 - VREG_MMC
         19 - VREG_RUIM

      \endcode

   \param iVoltageLevel = Voltage level in millivolts returned from the selected regulator.
      \code
            Valid input range depends on the selected regulator ID.

            For VREG_PA,VREG_MSME,VREG_MSMC1,VREG_MSMC2:
               Range = [750, 1525] in 25 mV steps
                           [1550,3050] in 50 mV steps
            For VREG_BOOST and VREG_USB
               Range = [3000, 6100] in 100 mV steps
            For all other regulators
               Range = [1500, 3100] in 50 mV steps.
            NOTE: Command will support any mV input level between the lower and upper limits, but this will get rounded down
                  by PMIC driver API to the closest voltage the regulator can support (step size dependent).

               Example:  User selection of VREG_PA = 2940 mV will get converted to 2900 mV.

      \endcode
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_GET_LEVEL
   ( HANDLE hResourceContext, unsigned char iVRegSelect, unsigned short* iVoltageLevel  );

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 6.3  Config SMPS Mode

   Configure SMPS regulator mode.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVRegSmps = Voltage regulator to configure
      \code
         0 - SMPS_PA
         1 - SMPS_MSME
         2 - SMPS_MSMC1
         3 - SMPS_MSMC2
         4 - SMPS_BOOST

      \endcode

   \param iSmpsMode =
      \code
         0 - SMPS_MODE_TCXO_EN
         1 - SMPS_MODE_PWM
         2 - SMPS_MODE_PBM
         3 - SMPS_MODE_AUTOMATIC

      \endcode
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_CONFIG_SMPS_MODE
   ( HANDLE hResourceContext, unsigned char iVRegSmps, unsigned char iSmpsMode  );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 6.4  Config LDO Powerdown Switch

   Configure LDO power down functionality

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVRegCmd =
      \code
         0 - Disable LDO Powerdown functionality
         1 - Enable LDO Powerdown functionality

      \endcode

   \param iVRegSelect =
      \code
         0 - PDOWN_MSMP
         1 - PDOWN_MSMA
         2 - PDOWN_WLAN
         3 - PDOWN_RFRX2
         4 - PDOWN_RFRX1
         5 - PDOWN_RFTX
         6 - PDOWN_SYNT
         7 - PDOWN_TCXO
         8 - PDOWN_USB
         9 - PDOWN_MMC
         10 - PDOWN_RUIM
         11 - PDOWN_MSMS
         12 - PDOWN_MEM
         13 - PDOWN_CAM
         14 - PDOWN_GP

      \endcode
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_CONFIG_LDO_PD_SW
   ( HANDLE hResourceContext, unsigned char iVRegCmd, unsigned char iVRegSelect );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 6.5  Config Low Power Mode

   Configure LDO low power functionality

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVRegCmd =
      \code
         0 - Disable Low power functionality
         1 - Enable Low power functionality

      \endcode

   \param iVRegSelect =
      \code
         0 - LP_MSMA
         1 - LP_MSMP

      \endcode
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_CONFIG_LP_MODE_CONTROL
   ( HANDLE hResourceContext, unsigned char iVRegCmd, unsigned char iVRegSelect);

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 6.6  Config SMPS Clock

   Configure SMPS clock

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSmpsClockCmd =
      \code
         0 - Select source for SMPS clock
         1 - Select TCXO Divider for SMPS clock

      \endcode

   \param iSmpsClockConfig =
      \code
         For vreg_smps_clk_cmd = 0
         0 - SMPS_CLK_SEL_TCXO
         1 - SMPS_CLK_SEL_RC

         For vreg_smps_clk_cmd = 1
         0 - SMPS_TCXO_DIV_8
         1 - SMPS_TCXO_DIV_10
         2 - SMPS_TCXO_DIV_12
         3 - SMPS_TCXO_DIV_14
         4 - SMPS_TCXO_DIV_16
         5 - SMPS_TCXO_DIV_18

      \endcode
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_SMPS_CLK_CONFIG
   ( HANDLE hResourceContext, unsigned char iSmpsClockCmd, unsigned char iSmpsClockConfig );


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 7.1  Get Real Time Status Command

   Get interrupt status

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iInterruptStatusId=
      \code
         0 - VALID_CHG_RT_ST
         1 - INVALID_CHG_RT_ST
         2 - VALID_USB_CHG_RT_ST
         3 - INVALID_USB_CHG_RT_ST
         4 - CHG_I_LIMITING_RT_ST
         5 - CHG_P_LIMITING_RT_ST
         6 - PULSE_CHG_DONE_RT_ST
         7 - VCP_IRQ_RT_ST
         8 - T_STAT_CHANGED_RT_ST
         9 - BAT_STAT_CHANGED_RT_ST
         10 - VBAT_DET_RT_ST
         11-  BAT_FET_ON_RT_ST
         12 - KPD_PWR_KEY_ON_RT_ST
         13 - KPD_PWR_KEY_OFF_RT_ST
         14 - RTC_ALRM_RT_ST
         15 - OSC_HALT_RT_ST
         16 - PWR_RST_RT_ST
         17 - SMPL_RT_ST
         18 - CABLE_IN_RT_ST
         19 - OVER_TEMP_RT_ST
         20 - WDOG_TOUT_RT_ST
         21 - KPD_PWRON_EVENT_RT_ST
         22 - USB_BUS_VALID_RT_ST
         23 - USB_SN_VALID_RT_ST
         24 - USB_D_PLUS_HI_RT_ST
         25 - USB_ID_GND_RT_ST
         26 - USB_D_MINUS_HI_RT_ST
         27 - USB_ID_FLOATING_RT_ST
         28 - USB_BOFF_AON_RT_ST
         29 - USB_CARKIT_INT_RT_ST
         38 - MPP01_CHGED_RT_ST
         39 - MPP02_CHGED_RT_ST
         40 - MPP03_CHGED_RT_ST
         41 - MPP04_CHGED_RT_ST
         42 - MPP05_CHGED_RT_ST
         43 - MPP06_CHGED_RT_ST
         44 - MPP07_CHGED_RT_ST
         45 - MPP08_CHGED_RT_ST
         46 - MPP09_CHGED_RT_ST
         47 - MPP10_CHGED_RT_ST
         48 - MPP11_CHGED_RT_ST
         49 - MPP12_CHGED_RT_ST
         50 - MPP13_CHGED_RT_ST
         51 - MPP14_CHGED_RT_ST
         52 - MPP15_CHGED_RT_ST
         53 - MPP16_CHGED_RT_ST

      \endcode

   \param piInterruptCmd = Status returned.
      \code
         0 - Interrupt event real time status not triggered
         1 - Interrupt event real time status triggered

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_INT_GET_RT_STATUS
   ( HANDLE hResourceContext, unsigned char iInterruptStatusId, unsigned char* piInterruptStatus );

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands 7.2  Clear IRQ Command

   Clear the interrupt status for a specified handler

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iInterruptHandler=
      \code
         0 - VALID_CHG_RT_ST
         1 - INVALID_CHG_RT_ST
         2 - VALID_USB_CHG_RT_ST
         3 - INVALID_USB_CHG_RT_ST
         4 - CHG_I_LIMITING_RT_ST
         5 - CHG_P_LIMITING_RT_ST
         6 - PULSE_CHG_DONE_RT_ST
         7 - VCP_IRQ_RT_ST
         8 - T_STAT_CHANGED_RT_ST
         9 - BAT_STAT_CHANGED_RT_ST
         10 - VBAT_DET_RT_ST
         11-  BAT_FET_ON_RT_ST
         12 - KPD_PWR_KEY_ON_RT_ST
         13 - KPD_PWR_KEY_OFF_RT_ST
         14 - RTC_ALRM_RT_ST
         15 - OSC_HALT_RT_ST
         16 - PWR_RST_RT_ST
         17 - SMPL_RT_ST
         18 - CABLE_IN_RT_ST
         19 - OVER_TEMP_RT_ST
         20 - WDOG_TOUT_RT_ST
         21 - KPD_PWRON_EVENT_RT_ST
         22 - USB_BUS_VALID_RT_ST
         23 - USB_SN_VALID_RT_ST
         24 - USB_D_PLUS_HI_RT_ST
         25 - USB_ID_GND_RT_ST
         26 - USB_D_MINUS_HI_RT_ST
         27 - USB_ID_FLOATING_RT_ST
         28 - USB_BOFF_AON_RT_ST
         29 - USB_CARKIT_INT_RT_ST
         38 - MPP01_CHGED_RT_ST
         39 - MPP02_CHGED_RT_ST
         40 - MPP03_CHGED_RT_ST
         41 - MPP04_CHGED_RT_ST
         42 - MPP05_CHGED_RT_ST
         43 - MPP06_CHGED_RT_ST
         44 - MPP07_CHGED_RT_ST
         45 - MPP08_CHGED_RT_ST
         46 - MPP09_CHGED_RT_ST
         47 - MPP10_CHGED_RT_ST
         48 - MPP11_CHGED_RT_ST
         49 - MPP12_CHGED_RT_ST
         50 - MPP13_CHGED_RT_ST
         51 - MPP14_CHGED_RT_ST
         52 - MPP15_CHGED_RT_ST
         53 - MPP16_CHGED_RT_ST

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_INT_IRQ_CLR( HANDLE hResourceContext, unsigned char iInterruptHandler );



   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 8.1  Set PMIC Pin Drive Level

      The PMIC has three high strength drive pins that are connected to the LCD
      backlight (LCD_DRV pin), the keypad LEDs (KPD_DRV pin), and the vibrator
      (VIB_DRV pin).  Each pin has a programmable drive level as described below.

      FTM_SET_PMIC_DRIVE_LEVEL allows selection of one of three high drive pins
      and selection of the drive level.  A drive level selection of 0 will turn
      off the pin drive.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iHighDrivePinID =  Selects pin for drive level programming, values for this field are:
      \code
              0 = LCD_DRV pin
              1 = KPD_DRV pin
              2 = VIB_DRV pin
      \endcode

      \param iDriveLevel = Programs drive level for selected pin:
      \code
              a) LCD_DRV pin current = drive_level * 10mA.  Valid range is 0-15
              b) KPD_DRV pin current = drive_level * 10mA.  Valid range is 0-15
              c) VIB_DRV pin voltage = drive_level  * 100mV.  Valid range is 0 (off) or 12-31.
      \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SET_PMIC_DRIVE_LEVEL
   ( HANDLE hResourceContext, unsigned char iHighDrivePinID, unsigned char iDriveLevel );

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 8.2  Configure PMIC Speaker Path

      This command will configure the portion of the audio path that goes through
      the PMIC.  The command will support commands to enable/disable the speaker,
      to set the speaker gain, and to set the speaker delay.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iSpeakerCMD =
         \code
                0 - SPKR_DISABLE
                1 - SPKR_ENABLE
                2 - SPKR_MUTE_OFF
                3 - SPKR_MUTE_ON
                4 - SPKR_OFF
                5 - SPKR_ON
         \endcode
      \param iSpeakerGain =
         \code
                0 - SPKR_GAIN_MINUS_16DB
                1 - SPKR_GAIN_MINUS_12DB
                2 - SPKR_GAIN_MINUS_08DB
                3 - SPKR_GAIN_MINUS_04DB
                4 - SPKR_GAIN_00DB
                5 - SPKR_GAIN_PLUS_04DB
                6 - SPKR_GAIN_PLUS_08DB
                7 - SPKR_GAIN_PLUS_12DB
         \endcode

      \param iSpeakerDelay
         \code
                0 - SPKR_DELAY_10MS
                1 - SPKR_DELAY_100MS
         \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_SPKR_CONFIG (
      HANDLE hResourceContext, unsigned char iSpeakerCMD,
      unsigned char iSpeakerGain, unsigned char iSpeakerDelay
   );

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 9.1  Set digital in command

      This command will configure the selected Multi Purpose pin (MPP) to be a digital input pin.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iMPP =   Which MPP we want to configure. Values for this field are:

                  \code
                  0 - PM_MPP_1
                  1 - PM_MPP_2
                  2 - PM_MPP_3
                  = PM_NUM_MPP_PM6620
                  = PM_NUM_MPP_PM6640
                  = PM_NUM_MPP_PANORAMIX
                  ...
                  ...
                  ...
                  PM_MPP_INVALID

                  \endcode

      \param iLevel = The logic level reference that we want to use with this MPP. Values for this field are:

                  \code
                  0 - PM_MPP__DLOGIC__LVL_MSME
                  1 - PM_MPP__DLOGIC__LVL_MSMP
                  2 - PM_MPP__DLOGIC__LVL_RUIM
                  3 - PM_MPP__DLOGIC__LVL_MMC
                  4 - PM_MPP__DLOGIC__LVL_VDD
                  \endcode

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_MPP_CONFIG_DIGITAL_IN(
      HANDLE hResourceContext,
      unsigned char iMpp,
      unsigned char iLevel,
      unsigned short * piStatus);

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 9.2  Set digital out command

      This command will configure the selected Multi Purpose pin (MPP) to be a digital output pin.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iMPP =   Which MPP we want to configure. Values for this field are:

                  \code
                  0 - PM_MPP_1
                  1 - PM_MPP_2
                  2 - PM_MPP_3
                  = PM_NUM_MPP_PM6620
                  = PM_NUM_MPP_PM6640
                  = PM_NUM_MPP_PANORAMIX
                  ...
                  ...
                  ...
                  PM_MPP_INVALID

                  \endcode

      \param iLevel = The logic level reference that we want to configure. Values for this field are:

                  \code
                  0 - PM_MPP__DLOGIC__LVL_MSME
                  1 - PM_MPP__DLOGIC__LVL_MSMP
                  2 - PM_MPP__DLOGIC__LVL_RUIM
                  3 - PM_MPP__DLOGIC__LVL_MMC
                  4 - PM_MPP__DLOGIC__LVL_VDD
                  \endcode
      \param iCtrl = The logic level reference that we want to use with this MPP. Values for this field are:

                  \code
                  0 - PM_MPP__DLOGIC_OUT__CTRL_LOW,    MPP OUTPUT = LOGIC LOW
                  1 - PM_MPP__DLOGIC_OUT__CTRL_HIGH,    MPP OUTPUT = LOGIC HIGH
                  2 - PM PM_MPP__DLOGIC_OUT__CTRL_MPP,    MPP OUTPUT = CORRESPONDING MPP INPUT (see the note regarding MPP pairs within the description section)
                  3 - PM_MPP__DLOGIC_OUT__CTRL_NOT_MPP,   MPP OUTPUT  = CORRESPONDING INVERTED MPP INPUT (see the note regarding MPP pairs within the description section)
                  \endcode

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_MPP_CONFIG_DIGITAL_OUT(
      HANDLE hResourceContext,
      unsigned char iMpp,
      unsigned char iLevel,
      unsigned char iCtrl,
      unsigned short * piStatus);

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 9.3  Set digital inout command

      This command will configure the selected Multi Purpose pin (MPP) to be a digital bidirectional pin.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iMPP =   Which MPP we want to configure. Values for this field are:

                  \code
                  0 - PM_MPP_1
                  1 - PM_MPP_2
                  2 - PM_MPP_3
                  = PM_NUM_MPP_PM6620
                  = PM_NUM_MPP_PM6640
                  = PM_NUM_MPP_PANORAMIX
                  ...
                  ...
                  ...
                  PM_MPP_INVALID

                  \endcode

      \param iLevel = The logic level reference that we want to configure. Values for this field are:

                  \code
                  0 - PM_MPP__DLOGIC__LVL_MSME
                  1 - PM_MPP__DLOGIC__LVL_MSMP
                  2 - PM_MPP__DLOGIC__LVL_RUIM
                  3 - PM_MPP__DLOGIC__LVL_MMC
                  4 - PM_MPP__DLOGIC__LVL_VDD
                  \endcode
      \param iPup = The pull-up resistor setting of the selected MPP. Values fro this field are:

                  \code
                  0 - PM_MPP__DLOGIC_INOUT__PUP_1K          PULL UP = 1  K Ohms
                  1 - PM_MPP__DLOGIC_INOUT__PUP_3K          PULL UP = 3  K Ohms
                  2 - PM_MPP__DLOGIC_INOUT__PUP_10K        PULL UP = 10  K Ohms
                  3 - PM_MPP__DLOGIC_INOUT__PUP_30K        PULL UP = 30  K Ohms

                  \endcode

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_MPP_CONFIG_DIGITAL_INOUT(
      HANDLE hResourceContext,
      unsigned char iMpp,
      unsigned char iLevel,
      unsigned char iPup,
      unsigned short * piStatus);

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 9.4  Set analog in command

      This command will configure the selected Multi Purpose pin (MPP) to be an analog input pin.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iMPP =   Which MPP we want to configure. Values for this field are:

                  \code
                  0 - PM_MPP_1
                  1 - PM_MPP_2
                  2 - PM_MPP_3
                  = PM_NUM_MPP_PM6620
                  = PM_NUM_MPP_PM6640
                  = PM_NUM_MPP_PANORAMIX
                  ...
                  ...
                  ...
                  PM_MPP_INVALID

                  \endcode

      \param iChannel = Which analog mux or analog bus will the selected MPP be routed to. Values for this field are:

                  \code
                  0 - PM_MPP__AIN__CH_AMUX5
                  1 - PM_MPP__AIN__CH_AMUX6
                  2 - PM_MPP__AIN__CH_AMUX7
                  3 - PM_MPP__AIN__CH_AMUX8
                  4 - PM_MPP__AIN__CH_AMUX9
                  5 - PM_MPP__AIN__CH_AMUX1
                  6 - PM_MPP__AIN__CH_AMUX2
                  7 - PM_MPP__AIN__CH_AMUX3

                  \endcode

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_MPP_CONFIG_ANALOG_IN(
      HANDLE hResourceContext,
      unsigned char iMpp,
      unsigned char iChannel,
      unsigned short * piStatus);
   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 9.5  Set analog out command

      This command will configure the selected Multi Purpose pin (MPP) to be an analog output pin

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iMPP =   Which MPP we want to configure. Values for this field are:

                  \code
                  0 - PM_MPP_1
                  1 - PM_MPP_2
                  2 - PM_MPP_3
                  = PM_NUM_MPP_PM6620
                  = PM_NUM_MPP_PM6640
                  = PM_NUM_MPP_PANORAMIX
                  ...
                  ...
                  ...
                  PM_MPP_INVALID

                  \endcode

      \param iMpp_switch = This option allows the user to enable/disable the MPP output. Values for this field are:

                  \code
                  0 - PM_MPP__AOUT__SWITCH_OFF
                  1 - PM_MPP__AOUT__SWITCH_ON
                  2 - PM_MPP__AOUT__SWITCH_ON_IF_MPP_HIGH
                  3 - PM_MPP__AOUT__SWITCH_ON_IF_MPP_LOW

                  \endcode

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_MPP_CONFIG_ANALOG_OUT(
      HANDLE hResourceContext,
      unsigned char iMpp,
      unsigned char iMpp_switch,
      unsigned short * piStatus);
   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 9.6  Set current sink command

      This command will configure the selected Multi Purpose pin (MPP) to be a current sink.

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iMPP =   Which MPP we want to configure. Values for this field are:

                  \code
                  0 - PM_MPP_1
                  1 - PM_MPP_2
                  2 - PM_MPP_3
                  = PM_NUM_MPP_PM6620
                  = PM_NUM_MPP_PM6640
                  = PM_NUM_MPP_PANORAMIX
                  ...
                  ...
                  ...
                  PM_MPP_INVALID

                  \endcode

      \param iLevel = How much current we want to allow the MPP to sink.  Values for this field are:

                  \code
                  0 - PM_MPP__I_SINK__LEVEL_5mA
                  1 - PM_MPP__I_SINK__LEVEL_10mA
                  2 - PM_MPP__I_SINK__LEVEL_15mA
                  3 - PM_MPP__I_SINK__LEVEL_20mA
                  4 - PM_MPP__I_SINK__LEVEL_25mA
                  5 - PM_MPP__I_SINK__LEVEL_30mA
                  6 - PM_MPP__I_SINK__LEVEL_35mA
                  7 - PM_MPP__I_SINK__LEVEL_40mA

                  \endcode

      \param iMpp_switch = This option allows the user to enable/disable the MPP output. Values for this field are:

                  \code
                  0 - PM_MPP__AOUT__SWITCH_OFF
                  1 - PM_MPP__AOUT__SWITCH_ON
                  2 - PM_MPP__AOUT__SWITCH_ON_IF_MPP_HIGH
                  3 - PM_MPP__AOUT__SWITCH_ON_IF_MPP_LOW

                  \endcode

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_MPP_CONFIG_I_SINK(
      HANDLE hResourceContext,
      unsigned char iMpp,
      unsigned char iLevel,
      unsigned char iMpp_switch,
      unsigned short * piStatus);

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 1.2  Get Voltage Regulator Enumration List

      This command gets supported voltage Regulator enumeration list

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param piNumVreg = Num of supported voltage regulator

      \param piBufferSize =  Size of pBuffer.  The length of enumeration list string is returned with this paramter
                        A value of -1 is to indicate buffer overflow condition

      \param pBuffer = A buffer to store enumeration list string (null character terminated)

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning If the user buffer size is less than enumeration list string length, the function will return false
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_GET_ENUM_LIST(
      HANDLE hResourceContext,
      unsigned short* piNumVreg,
      short * piBufferSize,
      unsigned char * pBuffer,
      unsigned short *piStatus);

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands 1.2  Get Voltage Regulator Enumration List

      This command calls FTM_PMIC_VREG_GET_ENUM_LIST to get supported voltage Regulator enumeration list

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param piNumVreg = Num of supported voltage regulator

      \param aEnumIdList =  An array to store the list of enumeration id

      \param aEnumStrList = An array to store the list of enumeration string

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_GET_ENUM_LIST_IN_ARRAY_FORM(
      HANDLE hResourceContext,
      unsigned short* piNumVreg,
      unsigned short aEnumIdList[20],
      unsigned char aEnumStrList[20][8],
      unsigned short *piStatus);


   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands X.X Get PMIC Model

   This command calls FTM_PMIC_GET_MODEL to get PMIC Model ID

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piModel   = PMIC model number:
                  \code
                  0 = PMIC_IS_PM6610,
                  1 = PMIC_IS_PM6620,
                  2 = PMIC_IS_PM6640,
                  3 = PMIC_IS_PM6650,
                  4 = PMIC_IS_PM7500,
                  5 = PMIC_IS_PANORAMIX,
                  6 = PMIC_IS_INVALID
                  \endcode

   \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_GET_MODEL(
      HANDLE hResourceContext,
      unsigned short* piModel,
      unsigned short * piStatus);

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands.  Enable/Disable microphone

      This command calls FTM_PMIC_TEST_MIC(10) to command enable/disable the microphone

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
      \param iEnable = Enable if iEnable == 1
                       Disable if iEnable == 0

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_TEST_MIC_ENABLE(HANDLE hResourceContext, unsigned char iEnable, unsigned short *piStatus);

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands.  Set/Get Microphone voltage level.

      This command calls FTM_PMIC_TEST_MIC(10) to set/get microphone voltage level

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \param iEnable = Set level if iSet == 1
                       Get level if iSet == 0

       \param piVoltageLvl = Voltage Level

                     \code
                     0  PM_MIC_VOLT_2_00V
                     1  PM_MIC_VOLT_1_93V
                     2  PM_MIC_VOLT_1_80V
                     3  PM_MIC_VOLT_1_73V
                     \endcode

      \param piStatus = Return status
                  \code
                  0 = COMMAND_SUCESS
                  >0 = Error code
                  \endcode

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_TEST_MIC_SET_GET_VOLTAGE_LEVEL(HANDLE hResourceContext, unsigned char iSet, unsigned char* piVoltageLvl, unsigned short* piStatus);

   /******************************************************************************/
   /**
      Factory Test Mode PMIC Commands.  Enable/Disable microphone

      This command calls FTM_PMIC_TEST_RESET (11)

      The Hard Reset command resets all of the PMIC hardware blocks, excluding the RTC

      \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

      \return true if successful, false if fail.

      \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_TEST_HARD_RESET(HANDLE hResourceContext);

   /******************************************************************************/
   /**
   Factory Test Mode PMIC Commands  Enable/Disable VREG Command via enumeration

   Enable/disable a voltage regulator through voltage regulator enumeration.

   This command calls PMIC FTM command FTM_PMIC_TEST_VREG_EXT (15)

   This API can only set one regulator at a time.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVRegCmd   = 0 - Disable selected regulator, 1 - Enable selected regulator

   \param iVRegEnum = Voltage regulator enumeration

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_PMIC_VREG_CONTROL_EXT
   ( HANDLE hResourceContext, unsigned char iVRegCmd, unsigned short iVRegEnum );




#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_PMIC_H)
