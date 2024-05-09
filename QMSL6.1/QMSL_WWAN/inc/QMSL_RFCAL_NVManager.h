/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_RFCAL_NVManager.h#16 $
 * $DateTime: 2016/05/13 14:02:59 $
 *
 * DESCRIPTION: QMSL_RFCAL_NVManager
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_RFCAL_NVMANAGER_H)
#define _QMSL_RFCAL_NVMANAGER_H

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
                     Calibration Data Manager
   *******************************************************************************/


   /******************************************************************************/
   /**
   Set the system parameters used to calculate CDMA 1x related NV items.  If the function
   is not called, the default values will be used.

   \param hResourceContext   Resource context that was returned from the call to ConnectServer().

   \param dMinRSSI [input] Minimum RSSI.  Default value is -115.0dBm

   \param dDynamicRange [input] Dynamic Range for CDMA 1x targets.  Default value is 102.4dB

   \param dWCDMADynamicRange [input] = Dynamic Range for UMTS target.  Default value is 85.3dB

   \return true if successful, false otherwise

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_SystemParameters( HANDLE hResourceContext, double dMinRSSI, double dDynamicRange, double dWCDMADynamicRange );

   /******************************************************************************/
   /**
   Set the system parameters used to calculate WCDMA related NV items.  If the function
   is not called, the default values will be used.

   \param hResourceContext   Resource context that was returned from the call to ConnectServer().

   \param dWCDMADynamicRange [input] = Dynamic Range for UMTS target.  Default value is 85.3dB

        \param dWCDMAMaxPower [input] = Max Power for UMTS target.  Default value is 28.3dB

   \return true if successful, false otherwise

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_WCDMA_SystemParameters_V2( HANDLE hResourceContext, double dWCDMADynamicRange, double dWCDMAMaxPower );

   /******************************************************************************/
   /**
   Generate Tx Linearizer, Tx AGC vs HDET, HDET offset and span NV items

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aTx_LinMeasured [input] Pointer to QMSL_CDMA_TxLin_struct.  The data structure stores 1x Tx linearizer calibration results.  See QLib_Defines.h for definition

   \param aTx_Lin_NV_Result [output] Pointer to QMSL_CDMA_TxLin_Cal_Result_struct.  The data structure stores the generated 1x Tx Linearizer related NV items.  See QLib_Defines.h for definition

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_CDMA_Tx_LinCal_Results(   HANDLE hResourceContext,
         unsigned short iNVModeID,
         void* aTx_LinMeasured,
         void* aTx_Lin_NV_Result,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Tx Frequency Compensation (TX_COMP_n) NV items

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aTx_Measured_Power [input] Pointer to QMSL_CDMA_TxLinVsFreq_struct.  The data structure stores Tx linearizer vs frequency results.  See QLib_Defines.h for definition

   \param aTx_MeasuredChannels [input] Pointer to QMSL_CDMA_MeasuredChannels_struct.  The data structure stores the list of RF channels, which the measurement is made.  See QLib_Defines.h for definition
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param aTx_NV_Channels [input] Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.  See QLib_Defines.h for definition.

   \param aTx_LinVsFreq_NV_Result [output] Pointer to QMSL_CDMA_Tx_LinVsFreq_Cal_NV_Result_struct.  The data structure that stores the NV item values generated.  See QLib_Defines.h for definition


   Note, User can use bC2K_Not_Overwrite_Tx_Pwr_Comp_Static_Component_With_Zero to NOT overwrite the static component by reading NV
   See bC2K_Not_Overwrite_Tx_Pwr_Comp_Static_Component_With_Zero in Qlib_Defines.h for details

   \param iNV_Resolution [input]  The number of NV value counts per dB
                           NV[chan] = ( measured-pwr[chan] - refChannelPwr ) * iNV_Resolution
                           For targets with 102.4 dB dynamic range, use 10 (ie 1/10dB per count).
                           For targets with 85.3 dB dynamic range, use 12 (ie 1/12dB per count).

   \param iNV_Tx_Comp_Type [input] 0 = QMSL_NV_TX_COMP, (NV_<bandclass>_TX_COMP_x NV items are generated)
                           1 = QMSL_NV_TX_PWR_COMP, (NV_<bandclass>_TX_PWR_COMP_x NV items are generated)

   \param bWriteNVChList [input] Generate calibration channel list NV_Cx_BCy_TX_CAL_CHAN_I NV item based on channesl in aRX_NV_Channels.  Note that not all target supports this NV items.  Please
                            refer to the target RF NV items document

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_Tx_LinVsFreq_Results   (   HANDLE    hResourceContext,
         unsigned short iNvModId,
         void* aTx_Measured_Power,
         void* aTx_MeasuredChannels,
         void* aTx_NV_Channels,
         int     iNV_Resolution_Type,
         int   iNV_Tx_Comp_Type,
         void* aTx_LinVsFreq_NV_Result,
         unsigned char bWriteNVChList,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Tx Frequency Compensation (TX_COMP_n) NV items with Tx Path as an input to support SV Path NV generation

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aTx_Measured_Power [input] Pointer to QMSL_CDMA_TxLinVsFreq_struct.  The data structure stores Tx linearizer vs frequency results.  See QLib_Defines.h for definition

   \param aTx_MeasuredChannels [input] Pointer to QMSL_CDMA_MeasuredChannels_struct.  The data structure stores the list of RF channels, which the measurement is made.  See QLib_Defines.h for definition
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param aTx_NV_Channels [input] Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.  See QLib_Defines.h for definition.

   \param aTx_LinVsFreq_NV_Result [output] Pointer to QMSL_CDMA_Tx_LinVsFreq_Cal_NV_Result_struct.  The data structure that stores the NV item values generated.  See QLib_Defines.h for definition

   \param iNV_Resolution [input]  The number of NV value counts per dB
                           NV[chan] = ( measured-pwr[chan] - refChannelPwr ) * iNV_Resolution
                           For targets with 102.4 dB dynamic range, use 10 (ie 1/10dB per count).
                           For targets with 85.3 dB dynamic range, use 12 (ie 1/12dB per count).

   \param iNV_Tx_Comp_Type [input] 0 = QMSL_NV_TX_COMP, (NV_<bandclass>_TX_COMP_x NV items are generated)
                           1 = QMSL_NV_TX_PWR_COMP, (NV_<bandclass>_TX_PWR_COMP_x NV items are generated)

   \param bWriteNVChList [input] Generate calibration channel list NV_Cx_BCy_TX_CAL_CHAN_I NV item based on channesl in aRX_NV_Channels.  Note that not all target supports this NV items.  Please
                            refer to the target RF NV items document

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param iTxPath [input] To indicate for which Tx path is the NV to be generated

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_Tx_LinVsFreq_Results_Extended( HANDLE hResourceContext,
         unsigned short iNV_Mode_Id,
         void* aTx_Measured_Power,
         void * aTx_MeasuredChannels,
         void* aTx_NV_Channels,
         int  iNV_Resolution,
         int  iNV_Tx_Comp_Type,
         void* aTx_LinVsFreq_NV_Result,
         unsigned char bWriteNVChList,
         unsigned char bCachedByNVManager,
         unsigned short iTxPath);

   /******************************************************************************/
   /**
   Generate Tx Frequency Compensation (TX_COMP_n) NV items for the Div Tx

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aTx_Measured_Power [input] Pointer to QMSL_CDMA_TxLinVsFreq_struct.  The data structure stores Tx linearizer vs frequency results.  See QLib_Defines.h for definition

   \param aTx_MeasuredChannels [input] Pointer to QMSL_CDMA_MeasuredChannels_struct.  The data structure stores the list of RF channels, which the measurement is made.  See QLib_Defines.h for definition
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param aTx_NV_Channels [input] Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.  See QLib_Defines.h for definition.

   \param aTx_LinVsFreq_NV_Result [output] Pointer to QMSL_CDMA_Tx_LinVsFreq_Cal_NV_Result_struct.  The data structure that stores the NV item values generated.  See QLib_Defines.h for definition

   \param iNV_Resolution [input]  The number of NV value counts per dB
                           NV[chan] = ( measured-pwr[chan] - refChannelPwr ) * iNV_Resolution
                           For targets with 102.4 dB dynamic range, use 10 (ie 1/10dB per count).
                           For targets with 85.3 dB dynamic range, use 12 (ie 1/12dB per count).

   \param iNV_Tx_Comp_Type [input] 0 = QMSL_NV_TX_COMP_MTD, (NV_<bandclass>_TX_COMP_x NV items are generated)
                           1 = QMSL_NV_TX_PWR_COMP, (NV_<bandclass>_TX_PWR_COMP_x NV items are generated)

   \param bWriteNVChList [input] Generate calibration channel list NV_Cx_BCy_TX_CAL_CHAN_I NV item based on channesl in aRX_NV_Channels.  Note that not all target supports this NV items.  Please
                            refer to the target RF NV items document

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_Tx_LinVsFreq_Results_MTD   (   HANDLE    hResourceContext,
         unsigned short iNvModId,
         void* aTx_Measured_Power,
         void* aTx_MeasuredChannels,
         void* aTx_NV_Channels,
         int     iNV_Resolution_Type,
         int   iNV_Tx_Comp_Type,
         void* aTx_LinVsFreq_NV_Result,
         unsigned char bWriteNVChList,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Tx Lim vs freq (TX_LIM_VS_FREQ) NV items.  Calcuations are based on the
   WCDMA NV Document 80-V6968-12 Rev H, section 4.3.3.11.


   The same calculations are used for CDMA2000 and WCDMA, this document is just a reference point.

   As for Feb 2008, certain CDMA2000 documents had a different formula.  The formula will
   be changed to match 80-V6968-12 after the following versions:
   \code
      80-V8891-11 Rev C for MSM6800
      80-VC467-11 Rev C for RTR6500
   \endcode


   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param dDesiredMaxPower [input] Desired maximum output power in dBm

   \param aTx_LimVsFreqMeasured [input] Pointer to QMSL_CDMA_TxLimVsFreq_struct.  The data structure stores Tx Lim vs Freq measurement.  See QLib_Defines.h for definition

   \param aTx_MeasuredChannels [input] Pointer to QMSL_CDMA_MeasuredChannels_struct.  The data structure stores the list of RF channels, which the measurement is made.  See QLib_Defines.h for definition

   \param aTx_NV_Channels [input] Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.  See QLib_Defines.h for definition.
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param aTx_LimVsFreq_NV_Result [output] Pointer to QMSL_CDMA_Tx_LimVsFreq_NV_struct.  The data structure that stores the
                                           NV item values generated.  See QLib_Defines.h for definition.
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_Tx_LimVsFreq_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         double dDesiredMaxPower,
         void* aTx_LimVsFreqMeasured,
         void* aTx_MeasuredChannels,
         void* aTx_NV_Channels,
         void* aTx_LimVsFreq_NV_Result,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Tx Lim vs freq (TX_LIM_VS_FREQ) NV items.  Calcuations are based on the
   WCDMA NV Document 80-V6968-12 Rev H, section 4.3.3.11. This has an extra parameter to support multiple Tx Paths


   The same calculations are used for CDMA2000 and WCDMA, this document is just a reference point.

   As for Feb 2008, certain CDMA2000 documents had a different formula.  The formula will
   be changed to match 80-V6968-12 after the following versions:
   \code
      80-V8891-11 Rev C for MSM6800
      80-VC467-11 Rev C for RTR6500
   \endcode


   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param dDesiredMaxPower [input] Desired maximum output power in dBm

   \param aTx_LimVsFreqMeasured [input] Pointer to QMSL_CDMA_TxLimVsFreq_struct.  The data structure stores Tx Lim vs Freq measurement.  See QLib_Defines.h for definition

   \param aTx_MeasuredChannels [input] Pointer to QMSL_CDMA_MeasuredChannels_struct.  The data structure stores the list of RF channels, which the measurement is made.  See QLib_Defines.h for definition

   \param aTx_NV_Channels [input] Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.  See QLib_Defines.h for definition.
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param aTx_LimVsFreq_NV_Result [output] Pointer to QMSL_CDMA_Tx_LimVsFreq_NV_struct.  The data structure that stores the
                                           NV item values generated.  See QLib_Defines.h for definition.
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param iTxPath [input] To indicate for which Tx path is the NV to be generated

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_Tx_LimVsFreq_Results_Extended(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         double dDesiredMaxPower,
         void* aTx_LimVsFreqMeasured,
         void* aTx_MeasuredChannels,
         void* aTx_NV_Channels,
         void* aTx_LimVsFreq_NV_Result,
         unsigned char bCachedByNVManager,
         unsigned short iTxPath);
   /******************************************************************************/
   /**
   Generate Tx Lim vs freq (TX_LIM_VS_FREQ) NV items for the Div Tx.  Calcuations are based on the
   WCDMA NV Document 80-V6968-12 Rev H, section 4.3.3.11.


   The same calculations are used for CDMA2000 and WCDMA, this document is just a reference point.

   As for Feb 2008, certain CDMA2000 documents had a different formula.  The formula will
   be changed to match 80-V6968-12 after the following versions:
   \code
      80-V8891-11 Rev C for MSM6800
      80-VC467-11 Rev C for RTR6500
   \endcode


   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param dDesiredMaxPower [input] Desired maximum output power in dBm

   \param aTx_LimVsFreqMeasured [input] Pointer to QMSL_CDMA_TxLimVsFreq_struct.  The data structure stores Tx Lim vs Freq measurement.  See QLib_Defines.h for definition
   \param aTx_MeasuredChannels [input] Pointer to QMSL_CDMA_MeasuredChannels_struct.  The data structure stores the list of RF channels, which the measurement is made.  See QLib_Defines.h for definition

   \param aTx_NV_Channels [input] Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.  See QLib_Defines.h for definition.
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param aTx_LimVsFreq_NV_Result [output] Pointer to QMSL_CDMA_Tx_LimVsFreq_NV_struct.  The data structure that stores the
                                           NV item values generated.  See QLib_Defines.h for definition.
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_Tx_LimVsFreq_Results_MTD(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         double dDesiredMaxPower,
         void* aTx_LimVsFreqMeasured,
         void* aTx_LimVsFreqMeasured_Pri,
         void* aTx_MeasuredChannels,
         void* aTx_NV_Channels,
         void* aTx_LimVsFreq_NV_Result,
         unsigned char bCachedByNVManager);


   /******************************************************************************/
   /**
   Generate DVGA and LNA related NV item values

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNv_Mode_ID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param iIntelliceiver [input] Is it Intelliceiver? 1 == Yes, 0 == No

   \param dDVGAOffsetScalingFactor [input]  The scaling factor to calculate the DVGAvsFreq offset.  DVGAvsFreq[_ch] = (DVGA[_ch] - refDVGA) / dDVGAOffsetScalingFactor

   For CDMA targets(MSM6K/7K,QSC6010/20/30), the scaling factor is 12\n
   For WCDMA targets, the scaling factor is 1\n
   For QSC6055/65/75/85 targets, the scaling factor is 1\n
   For QTR86xx targets, the scaling factor is 1

   Consult the RF NV document for the proper scaling factor.

   \param aRX_Measured [input] Pointer to QMSL_CDMA_RxFreq_Measurement_struct.  The data structure that stores receiver calibration results.  See QLib_Defines.h for definition

   \param aRX_MeasuredChannels [input] Pointer to QMSL_CDMA_MeasuredChannels_struct.  The list of RF channels which the receiver calibration runs.  See QLib_Defines.h for definition

   \param aRX_NV_Channels   [input]  Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.
                                 This list must always contain 16 values. If fewer channels are desired to be used then
                                 the last valid channel (highest frequency) is to be filled into the end of the
                                 list, such that there are 16 items in the list.

        \param aRX_DVGA_LNA_Cal_NV [output] Pointer to QMSL_CDMA_Rx_DVGA_LNA_Cal_NV_Result. The data structure stores the NV item values generated.

   \param bWriteNVChList [input] Generate calibration channel list NV_Cx_BCy_RX_CAL_CHAN_I NV item based on channesl in aRX_NV_Channels.  Note that not all targets supports this NV items.  Please
                            refer to the target RF NV items document

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              \n bCachedByNVManager == 1: Store NV items
                              \n bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
   \return

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_RxCal_Results(
      HANDLE hResourceContext,
      unsigned short iNV_Mode_ID,
      unsigned char iIsIntelliceiver,
      double dDVGAOffsetScalingFactor,
      void* aRX_Measured,
      void* aRX_MeasuredChannels,
      void* aRX_NV_Channels,
      void* aRX_DVGA_LNA_Cal_NV,
      unsigned char bWriteNVChList,
      unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate DVGA and LNA related NV item values for multicarrier WCDMA RF calibration

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iBand [input] Enumeration of the WCDMA band

   \param iNv_Mode_ID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param iIntelliceiver [input] Is it Intelliceiver? 1 == Yes, 0 == No

   \param dDVGAOffsetScalingFactor [input]  The scaling factor to calculate the DVGAvsFreq offset.  DVGAvsFreq[_ch] = (DVGA[_ch] - refDVGA) / dDVGAOffsetScalingFactor

   For CDMA targets(MSM6K/7K,QSC6010/20/30), the scaling factor is 12
   For WCDMA targets, the scaling factor is 1
   For QSC6055/65/75/85 targets, the scaling factor is 1

   Consult the RF NV document for the proper scaling factor.

   \param aRX_Measured [input] Pointer to QMSL_CDMA_RxFreq_Measurement_struct.  The data structure that stores receiver calibration results.  See QLib_Defines.h for definition

   \param aRX_MeasuredChannels [input] Pointer to QMSL_CDMA_MeasuredChannels_struct.  The list of RF channels which the receiver calibration runs.  See QLib_Defines.h for definition

   \param aRX_NV_Channels   [input]  Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.
   This list must always contain 16 values. If fewer channels are desired to be used then
   the last valid channel (highest frequency) is to be filled into the end of the
   list, such that there are 16 items in the list.

   \param aRX_DVGA_LNA_Cal_NV [output] Pointer to QMSL_CDMA_Rx_DVGA_LNA_Cal_NV_Result. The data structure stores the NV item values generated.

   \param bWriteNVChList [input] Generate calibration channel list NV_Cx_BCy_RX_CAL_CHAN_I NV item based on channesl in aRX_NV_Channels.  Note that not all targets supports this NV items.  Please
   refer to the target RF NV items document

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
   bCachedByNVManager == 1: Store NV items
   bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
   \return

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_WCDMA_MultiCarrier_RxCal_Results(
      HANDLE hResourceContext,
      unsigned int iBand,
      unsigned short iNV_Mode_ID,
      unsigned char iIsIntelliceiver,
      double dDVGAOffsetScalingFactor,
      void* aRX_Measured,
      void* aRX_MeasuredChannels,
      void* aRX_NV_Channels,
      void* aRX_DVGA_LNA_Cal_NV,
      unsigned char bWriteNVChList,
      unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate CDMA Rx IM2 calibration NV items

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeIe [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aRX_IM2_Result [input] Pointer to QMSL_CDMA_RxIM2_Measurement_struct.  The data structure stores IM2 calibration measurement.  See QLib_Defines.h for definition

   \param aRX_IM2_NV [output] Pointer to QMSL_CDMA_RxIM2_NV_struct.  The data structure stores the generated IM2 NV items.  See QLib_Defines.h for definition

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/


   QLIB_API unsigned char QLIB_RFCAL_Rx_IM2_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void*aRX_IM2_Result,
         void*aRX_IM2_NV,
         unsigned char bCachedByNVManager);



   /******************************************************************************/
   /**
   Generate CDMA Rx Intelliceiver calibration NV item

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aIntelliceiverValue [input] Pointer to QMSL_CDMA_Intelliceiver_Value.  The data structure stores CDMA Intelliceiver calibration value.  See QLib_Defines.h for definition

   \param aIntelliceiver_NV [output] Pointer to QMSL_RFCAL_NV_Item.  The data structure stores the generated NV Item.  See QLib_Defines.h for definition.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Rx_Intelliceiver_Cal_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aIntelliceiverValue,
         void* aIntelliceiver_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate CDMA Rx Intelliceiver calibration NV item for all Rx Paths

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aIntelliceiverValue [input] Pointer to QMSL_CDMA_Intelliceiver_Value.  The data structure stores CDMA Intelliceiver calibration value.  See QLib_Defines.h for definition

   \param aIntelliceiver_NV [output] Pointer to QMSL_RFCAL_NV_Item.  The data structure stores the generated NV Item.  See QLib_Defines.h for definition.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param iPath [input] Indicate the Rx Path for which Intelliceiver cal was done.
   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Rx_Intelliceiver_Cal_Results_Extended( HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aIntelliceiverValue,
         void* aIntelliceiver_NV,
         unsigned char bCachedByNVManager,
         unsigned short iPath);

   /******************************************************************************/
   /**
   Generate Tx Linearizer (Beta Scaling), Tx AGC vs HDET, HDET offset and span NV items

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aTx_Measured [input] Pointer to QMSL_CDMA_TxLin_BetaScaling_struct.  The data structure stores Tx linearizer calibration results.  See QLib_Defines.h for definition

   \param aTx_Result [output] Pointer to QMSL_CDMA_TxLin_BetaScaling_Result_struct.  The data structure stores the generated Tx Linearizer related NV items.  See QLib_Defines.h for definition

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_TxLinCal_BetaScaling_Results(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      void* aTx_Measured,
      void* aTx_Result,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   /**
   This function is added to support multiple Tx Paths as we have SV path addition to chipsets.

   Generate Tx Linearizer (Beta Scaling), Tx AGC vs HDET, HDET offset and span NV items

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aTx_Measured [input] Pointer to QMSL_CDMA_TxLin_BetaScaling_struct.  The data structure stores Tx linearizer calibration results.  See QLib_Defines.h for definition

   \param aTx_Result [output] Pointer to QMSL_CDMA_TxLin_BetaScaling_Result_struct.  The data structure stores the generated Tx Linearizer related NV items.  See QLib_Defines.h for definition

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
   \param iTxPath [input] To indicate the Tx path (Either Primary or SV Path (C2) )

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_CDMA_TxLinCal_BetaScaling_Results_Extended(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      void* aTx_Measured,
      void* aTx_Result,
      unsigned char bCachedByNVManager,
      unsigned short iTxPath
   );
   /******************************************************************************/
   /**
   Generate Tx Linearizer (Beta Scaling) nv Items for other channel
   ranges

   \param hResourceContext   Resource context that was returned
          from the call to ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV
          mode ID determines the set of NV items to be generated.
          See QLib_Defines.h for definition

   \param iChanRange [input] The channel range number

   \param aTx_Measured [input] Pointer to
          QMSL_CDMA_TxLin_BetaScaling_struct.  The data structure
          stores WCDMA Tx linearizer calibration results.  See
          QLib_Defines.h for definition

   \param aTx_Result [output] Pointer to
          QMSL_CDMA_TxLinCal_BetaScaling_Result_struct.  The data
          structure stores the generated WCDMA Tx Linearizer
          related NV items.  See QLib_Defines.h for definition

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager.   NV items stored in NV Manager will be
          written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone
          is called.

          bCachedByNVManager == 1: Store NV items
          bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_WCDMA_TxLinCal_Other_ChanRange(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned short iChanRange,
      void* aTx_Measured,
      void* aTx_Result,
      unsigned char bCachedByNVManager
   );


   /******************************************************************************/
   /**
   Generate Tx Linearizer (RTR6500) NV_BCx_TX_PDM_y_I and NV_BCx_TX_LIN_y, Tx AGC vs HDET, HDET offset and span NV items

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aTx_LinMeasured [input] Pointer to QMSL_CDMA_TxLin_struct.  The data structure stores 1x Tx linearizer calibration results.  See QLib_Defines.h for definition

   \param aTx_Lin_NV_Result [output] Pointer to QMSL_CDMA_TxLin_RTR6500_Result_struct.  The data structure stores the generated 1x Tx Linearizer related NV items.  See QLib_Defines.h for definition

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_CDMA_TxLinCal_RTR6500_Results(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      void* aTx_Measured,
      void* aTx_Result,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   /**
   Implement "ProcessTxSweep" function for Polar Calibration.
   See app note: MSM6275 External Polar Calibration with equipment(80-V9774-11).
   The output (aGSM_Polar_Cal_Processed) can be used as input to QLIB_RFCAL_GSM_Tx_Polar_Cal_Results()

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param aGSM_Polar_Cal_Measurement [input] Pointer to struct QMSL_GSM_Polar_Cal_Measurement in QLIB_Defines.h.  Polar calibration raw measurement data (including trigger and reference DAC segments).

   \param aGSM_Polar_Cal_Processed [output]  Pointer to struct QMSL_GSM_Polar_Cal_Measurement in QLIB_Defines.h   Polar calibration processed data (trigger and ref DAC segements removed.  Phase data are unwrapped)

   \return true if operation is successful, false otherwise

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Polar_ProcessTxSweep(HANDLE hResourceContext,
         void* aGSM_Polar_Cal_Measurement,
         void* aGSM_Polar_Cal_Processed);


   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Tx external polar calibration.  The NV items include NV_GSM_AMAM_MASTER_TBL_SEGx_Fn_I,
   NV_GSM_AMPM_MASTER_TBL_SEGx_Fn_I, NV_GSM_AMAM_ARFCN_Fn_I, NV_GSM_AMAM_DYNAMIC_RANGE_I

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param aGSM_Polar_Cal [input] Pointer to QMSL_GSM_Polar_Cal_Result.  Polar calibration processed data (Trigger and ref segments removed, phase unwrapped).  The data can come from QLIB_RFCAL_GSM_Tx_Polar_ProcessTxSweep()

   \param aGSM_Polar_Cal_NV [output] Pointer to QMSL_GSM_Polar_Cal_NV_struct.  NV items generated by smoothing algorithm

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Polar_Cal_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aGSM_Polar_Cal,
         void *aGSM_Polar_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM linear Tx DA calibration.  The NV items include QMSL_GSM_RGI_Fn_I,
   QMSL_GSM_PMEAS_Fn_I, NV_GSM_AMAM_ARFCN_Fn_I

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param aNum_GSM_Meas [input] Number of measured (chan, PA, RGI, power) entries in \a gsmMeas.

   \param aGSM_Meas [input] Measurements for GSM. Array of \a numGsmMeas QMSL_DA_Measurement's.

   \param aNum_EdgeMeas [input] Number of measured (chan, PA, RGI, power) entries in \a edgeMeas.

   \param aEdgeMeas [input] Measurements for EDGE. Array of \a numEdgeMeas QMSL_DA_Measurement's.

   \param aGSM_DA_Cal_NV [output] pointer to QMSL_GSM_DA_Cal_NV_Chan_struct containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   \warning The inputs are not sanity-checked, so the following must hold true:
            * The number of different channel, PA, and RGI entries are limited by
               QMSL_GSM_MAX_TX_CAL_CHANNELS, QMSL_GSM_MAX_TX_GAIN_STATES, and QMSL_GSM_MAX_RGI_STEPS .
            * Each channel in EDGE must have a corresponding channel in GSM (and vice versa)
            * NV frequency mappings should be consistent - for all entries with a given channel,
               the freqMapping entry should be the same.
            * Behavior when these conditions do not hold is undefined. ** Don't do it! **
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_DA_Cal_Results_v2(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned int numGsmMeas,
         void *gsmMeas,
         unsigned int numEdgeMeas,
         void *edgeMeas,
         void *aGSM_DA_Cal_NV,
         unsigned char bCachedByNVManager);


   /******************************************************************************/
   /**
   Generate the NV items associated with GSM linear Tx DA calibration.  The NV items include QMSL_GSM_RGI_Fn_I,
   QMSL_GSM_PMEAS_Fn_I, NV_GSM_AMAM_ARFCN_Fn_I

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param aGSM_DA_Cal [input] pointer to QMSL_GSM_DA_Cal_Result struct containing DA calibration sweep raw measurement data

   \param aGSM_DA_Cal_NV [output] pointer to QMSL_GSM_DA_Cal_NV_Chan_struct containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_DA_Cal_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aGSM_DA_Cal,
         void *aGSM_DA_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM linear Tx pre-distortion calibration.  The NV items include NV_GSM_<band>_AMAM_LINEAR_PA_RANGEA_F<n>_SEG<n>_I,
   NV_GSM_<band>_AMPM_LINEAR_PA_RANGEA_F<n>_SEG<n>_I, NV_GSM_AMAM_DYNAMIC_RANGE_I, NV_GSM_<band>_TX_AGC_SETTING_FOR_PRED_I

   NV_GSM_AMAM_ARFCN_Fn_I is populated as part of DA calibration (QLIB_RFCAL_GSM_Tx_DA_Cal_Results())

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param aGSM_PreDist_Cal [input] Pointer to QMSL_GSM_PreDist_Cal_Result struct containing raw pre-distortion calibration data. Phase (in degrees) and Amplitude (in dBm).

   \param aGSM_PreDist_Cal_NV [output] Pointer to QMSL_GSM_PreDist_Cal_NV_Chan_struct containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Linear_Process_PreDist_Cal_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aGSM_PreDist_Cal,
         void *aGSM_PreDist_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM linear Tx pre-distortion calibration.  The NV items include NV_GSM_<band>_AMAM_LINEAR_PA_RANGEA_F<n>_SEG<n>_I,
   NV_GSM_<band>_AMPM_LINEAR_PA_RANGEA_F<n>_SEG<n>_I, NV_GSM_AMAM_DYNAMIC_RANGE_I, NV_GSM_<band>_TX_AGC_SETTING_FOR_PRED_I

   NV_GSM_AMAM_ARFCN_Fn_I is populated as part of DA calibration (QLIB_RFCAL_GSM_Tx_DA_Cal_Results())

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param aGSM_PreDist_Cal [input] Pointer to QMSL_GSM_NonIQ_PreDist_Cal_Result struct containing raw pre-distortion calibration data. Phase (in degrees) and Amplitude (in dBm).

   \param aGSM_PreDist_Cal_NV [output] Pointer to QMSL_GSM_PreDist_Cal_NV_Chan_struct containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                                       bCachedByNVManager == 1: Store NV items
                                       bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Linear_Process_NonIQ_PreDist_Cal_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aGSM_PreDist_Cal,
         void *aGSM_PreDist_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM linear Tx pre-distortion calibration.  The NV items include NV_GSM_<band>_AMAM_LINEAR_PA_RANGEA_F<n>_SEG<n>_I,
   NV_GSM_<band>_AMPM_LINEAR_PA_RANGEA_F<n>_SEG<n>_I , NV_GSM_AMAM_DYNAMIC_RANGE_I, NV_GSM_<band>_TX_AGC_SETTING_FOR_PRED_I

        This API is used when the calibration waveform is EDGE_DC instead of DC_EDGE

   NV_GSM_AMAM_ARFCN_Fn_I is populated as part of DA calibration (QLIB_RFCAL_GSM_Tx_DA_Cal_Results())

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param aGSM_PreDist_Cal [input] Pointer to QMSL_GSM_PreDist_Cal_Result struct containing raw pre-distortion calibration data. Phase (in degrees) and Amplitude (in dBm).

   \param aGSM_PreDist_Cal_NV [output] Pointer to QMSL_GSM_PreDist_Cal_NV_Chan_struct containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Linear_Process_Swapped_PreDist_Cal_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aGSM_PreDist_Cal,
         void *aGSM_PreDist_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Tx external Linear clibration using characterized data and DUT Digital Gains.

   Processing may be done on the data before writing NV, as specified in the \a aGSM_EnhLinTx_Control input.

   Generated NV items include NV_GSM_<band>_AMAM_LINEAR_PA_RANGEA_F<n>_SEG<n>_I,
   NV_GSM_<band>_AMPM_LINEAR_PA_RANGEA_F<n>_SEG<n>_I, , NV_GSM_AMAM_DYNAMIC_RANGE__I, NV_GSM_<band>_TX_AGC_SETTING_FOR_PRED_I

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param aGSM_EnhLinTx_Control [input] Control parameters, whether to perform certain kinds of processing to fit the characterized data to the device.

   \param aGSM_EnhLinTx_CharData [input/output] Characterized data and DUT data for the calibration band, channels, and RGI.
   THIS DATA WILL BE CHANGED BY ANY FITTING OPERATIONS (i.e. power adaptation, slope correction)

   \param aGSM_EnhLinTx_NV [output] NV items generated.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_EnhLinTx_Cal_Process_Predist_NV(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned char bCachedByNVManager,
         void* aGSM_EnhLinTx_Control,
         void* aGSM_EnhLinTx_Data,
         void* aGSM_EnhLinTx_NV );

   /******************************************************************************/
   /**
   Averages input AMAM / AMPM curves to form a characterized curve for a device.

   Processing may be done on the data before writing NV, as specified in the \a aGSM_EnhLinTx_Control input.

   \param aControl [input]  Control parameters, whether to perform certain kinds of processing to fit the characterized data to the device.
      Currently, this is empty, but may be extended in the future.

   \param iNumCurvesIn [input] Number of curves in aInCurves. This MUST be greater than zero.

   \param aInCurves [input] Pointer to an array of QMSL_GSM_EnhLinTx_Cal_CharCurve (input curves to average), \a iNumCurvesIn elements long.

   \param aOutAvgCurve [output] Pointer to a QMSL_GSM_EnhLinTx_Cal_CharCurve to store the output averaged curve

   \param aOutInCurves [output] Pointer to an array of QMSL_GSM_EnhLinTx_Cal_ExtCharCurve, \a iNumCurvesIn elements long.
      This is used to store the input curves being processed.
      After the function returns, this data is valid and represents how the input curves were
      converted into the internal format.

   \param aOutWorkingCurves [output] Pointer to an array of QMSL_GSM_EnhLinTx_Cal_ExtCharCurve, \a iNumCurvesIn elements long.
      This is used to store the input curves jsut before averaging (but after any required processing).

   \param aOutAvgData [output] Pointer to a QMSL_GSM_EnhLinTx_Cal_ExtCharCurve to store the output averaged curve
      with extra data, like standard deviation information to indicate averaging quality.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_EnhLinTx_Cal_Average_AmamAmpm(   HANDLE hResourceContext,
         void* control,
         unsigned int iNumCurvesIn,
         void* inCurves,
         void* outAvgCurve,
         void* outInCurves,
         void* outWorkingCurves,
         void* outAvgData);

   /******************************************************************************/
   /**
   Averages input digital gain tables to form a averaged characterized digital gain table for a device.

   Processing may be done on the data before writing NV, as specified in the \a aGSM_EnhLinTx_Control input.

   \param iNumCurvesIn [input] Number of curves in aInCurves. This MUST be greater than zero.

   \param aInTables [input] Pointer to an array of QMSL_GSM_EnhLinTx_Cal_DigGainTable (input curves to average), \a iNumTablesIn elements long.

   \param aOutAvgTable [output] Pointer to a QMSL_GSM_EnhLinTx_Cal_DigGainTable to store the output averaged table.
         On failure, the output table will have zero elements, and the other data should not be considered valid.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_EnhLinTx_Cal_Average_DigGain(   HANDLE hResourceContext,
         unsigned int iNumTablesIn,
         void* inTables,
         void* outAvgTable);

   /******************************************************************************/
   /**
   Generate the Cx NV item associated with GSM linear Tx DA calibration.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeId [input] NV Mode to Set NV

   \param iChainId [input] C0, C2 etc

   \param aGSM_DA_Cal [input] pointer to QMSL_GSM_DA_Cal_Result
          struct containing DA calibration sweep raw measurement
          data

   \param aGSM_Linear_Tx_NV [output] Pointer to char buffer
          containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in
                              NV  Manager.  NV items stored in NV
                              Manager will be written to mobile
                              when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called. bCachedByNVManager == 1:
                              Store NV items bCachedByNVManager ==
                              0: Do not store NV items.  Generated
                              NV items will not be written to
                              mobile when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station  until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_GSM_Tx_DA_Cal_Generate_NV
   (   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned char iChainId,
      void* aGSM_DA_Cal,
      void* aGSM_Tx_Cx_Cal_NV,
      unsigned char bCachedByNVManager );

   /******************************************************************************/
   /**
   Generate the Cx NV item associated with GSM V4 DA-cal only with PCL-error tables calibration.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeId [input] NV Mode to Set NV

   \param iChainId [input] C0, C2 etc

   \param aGSM_PCL_Cal [input] pointer to QMSL_GSM_V4_PCL_Cal_Result
          struct containing PCL-error calibration sweep raw measurement
          data

   \param aGSM_Linear_Tx_NV [output] Pointer to char buffer
          containing NV items generated.

   \param iOrgPayloadSize  [input] The original size (bytes) of the payload in aGSM_Tx_Cx_Cal_NV.
            This is the number of bytes in the NV payload that contains valid data, which doesn't need to be overwritten.
            This should only include the RGI tables and associated PMEAS tables in the NV payload.

   \param bCachedByNVManager [input]  Store generated NV items in
                              NV  Manager.  NV items stored in NV
                              Manager will be written to mobile
                              when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called. bCachedByNVManager == 1:
                              Store NV items bCachedByNVManager ==
                              0: Do not store NV items.  Generated
                              NV items will not be written to
                              mobile when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station  until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_GSM_Tx_DA_Cal_Generate_NV_PCL
   (   HANDLE hResourceContext,
      unsigned short iNvModeId, unsigned char iChainId,
      void* aGSM_PCL_Cal,
      void* aGSM_Tx_Cx_Cal_NV,
      unsigned long iOrgPayloadSize,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   /**
   Generate the Cx NV item associated with GSM linear V4 calibration.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeId [input] NV Mode to Set NV

   \param iChainId [input] C0, C2 etc

   \param aGSM_V4_PCL_Cal [input] pointer to QMSL_GSM_V4_PCL_Cal_Result
          struct containing V4 calibration sweep raw measurement
          data (PCL error)

   \param aGSM_V4_DPD_Control [input] pointer to QMSL_GSM_EnhLinTx_Cal_Control struct

   \param aGSM_V4_DPD_Data [input] pointer to QMSL_GSM_EnhLinTx_Cal_Data struct

   \param aGSM_Tx_Cx_Cal_NV [output] Pointer to QMSL_GSM_Tx_Calibration_NV struct
          containing NV items generated.

   \param iOrgPayloadSize  [input] The original size (bytes) of the payload in aGSM_Tx_Cx_Cal_NV.
            This is the number of bytes in the NV payload that contains valid data, which doesn't need to be overwritten.
            This should only include the RGI tables and associated PMEAS tables in the NV payload.

   \param bCachedByNVManager [input]  Store generated NV items in
                              NV  Manager.  NV items stored in NV
                              Manager will be written to mobile
                              when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called. bCachedByNVManager == 1:
                              Store NV items bCachedByNVManager ==
                              0: Do not store NV items.  Generated
                              NV items will not be written to
                              mobile when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station  until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_GSM_V4_Cal_Tx_Generate_NV( HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned char iChainId,
         void* aGSM_V4_PCL_Cal,
         void* aGSM_V4_DPD_Control,
         void* aGSM_V4_DPD_Data,
         void* aGSM_Tx_Cx_Cal_NV,
         unsigned long iOrgPayloadSize,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the Cx NV item associated with GSM linear Tx DA and
   pre-distortion calibration.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeId [input] NV Mode to Set NV

   \param iChainId [input] C0, C2 etc

   \param aGSM_DA_Cal [input] pointer to QMSL_GSM_DA_Cal_Result
          struct containing DA calibration sweep raw measurement
          data

   \param aGSM_PreDist_Cal [input] Pointer to
          QMSL_GSM_PreDist_Cal_Result  struct containing raw
          pre-distortion calibration data. Phase (in degrees) and
          Amplitude (in dBm).

   \param aGSM_Linear_Tx_NV [output] Pointer to char buffer
          containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in
                              NV  Manager.  NV items stored in NV
                              Manager will be written to mobile
                              when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called. bCachedByNVManager == 1:
                              Store NV items bCachedByNVManager ==
                              0: Do not store NV items.  Generated
                              NV items will not be written to
                              mobile when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station  until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_GSM_Tx_DA_Cal_IQ_Predist_Cal_Generate_NV
   (   HANDLE hResourceContext,
      unsigned short iNvModeId, unsigned char iChainId,
      void* aGSM_DA_Cal,
      void* aGSM_PreDist_Cal,
      void* aGSM_Tx_Cx_Cal_NV,
      unsigned char bCachedByNVManager);


   /*******************************************************************************/
      QLIB_API unsigned char QLIB_RFCal_GSM_Tx_DA_Cal_IQ_Predist_Cal_Generate_Consolidated_NV
      (   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned char txAntPath,
      unsigned char rfmDevice,
      void* aGSM_DA_Cal,
      void* aGSM_PreDist_Cal,
      void* aGSM_Tx_Cx_Cal_NV,
      unsigned char bCachedByNVManager);




  /******************************************************************************/
   /**
   Generate the Cx NV item associated with GSM pre-distortion calibration only.
   - Relies upon DA cal data already being present in the Tx Cx NV.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeId [input] NV Mode to Set NV

   \param iChainId [input] C0, C2 etc

   \param aGSM_PreDist_Cal [input] Pointer to
          QMSL_GSM_PreDist_Cal_Result  struct containing raw
          pre-distortion calibration data. Phase (in degrees) and
          Amplitude (in dBm).

   \param aGSM_Linear_Tx_NV [output] Pointer to char buffer
          containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in
                              NV  Manager.  NV items stored in NV
                              Manager will be written to mobile
                              when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called. bCachedByNVManager == 1:
                              Store NV items bCachedByNVManager ==
                              0: Do not store NV items.  Generated
                              NV items will not be written to
                              mobile when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station  until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_GSM_Tx_IQ_Predist_Cal_Generate_NV(   HANDLE hResourceContext,
      unsigned short iNvModeId,unsigned char iChainId,
      void* aGSM_PreDist_Cal,
      void *aGSM_Tx_Cx_Cal_NV,
      unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the Cx NV item associated with GSM linear Tx DA and
   NonIQ pre-distortion calibration.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeId [input] NV Mode to Set NV

   \param iChainId [input] C0, C2 etc

   \param aGSM_DA_Cal [input] pointer to QMSL_GSM_DA_Cal_Result
          struct containing DA calibration sweep raw measurement
          data

   \param aGSM_PreDist_Cal [input] Pointer to
          QMSL_GSM_NonIQ_PreDist_Cal_Result  struct containing raw
          pre-distortion calibration data. Phase (in degrees) and
          Amplitude (in dBm).

   \param aGSM_Linear_Tx_NV [output] Pointer to char buffer
          containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in
                              NV  Manager.  NV items stored in NV
                              Manager will be written to mobile
                              when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called. bCachedByNVManager == 1:
                              Store NV items bCachedByNVManager ==
                              0: Do not store NV items.  Generated
                              NV items will not be written to
                              mobile when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station  until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_GSM_Tx_DA_Cal_NonIQ_Predist_Cal_Generate_NV
   (   HANDLE hResourceContext,
      unsigned short iNvModeId,unsigned char iChainId,
      void* aGSM_DA_Cal,
      void* aGSM_PreDist_Cal,
      void* aGSM_Tx_Cx_Cal_NV,
      unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the Cx NV item associated with GSM enhanced linear Tx DA and
   pre-distortion calibration.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeId [input] NV Mode to Set NV

   \param iChainId [input] C0, C2 etc

   \param numGsmMeas [input] Number of elements in gsmMeas array

   \param gsmMeas [input] QMSL_DA_Measurement array

   \param numEdgeMeas [input] Number of elements in edgeMeas array

   \param edgeMeas [input] QMSL_DA_Measurement array

   \param aGSM_EnhLinTx_Control [input] Control parameters, whether to perform certain kinds of processing to fit the characterized data to the device.

   \param aGSM_EnhLinTx_Data [input] Characterized data input to the Enhanced Predistortion Cal NV Generation

   \param aGSM_Tx_Cx_NV [output] Pointer to char buffer containing NV items generated.

   \param bCachedByNVManager [input]  Store generated NV items in
                              NV  Manager.  NV items stored in NV
                              Manager will be written to mobile
                              when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called. bCachedByNVManager == 1:
                              Store NV items bCachedByNVManager ==
                              0: Do not store NV items.  Generated
                              NV items will not be written to
                              mobile when
                              QLIB_RFCAL_NV_Manager_WriteToPhone()
                              is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station  until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_GSM_Tx_Enh_Cal_Generate_NV
   (   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned char iChainId,
      unsigned int numGsmMeas,
      void *gsmMeas,
      unsigned int numEdgeMeas,
      void *edgeMeas,
      void* aGSM_EnhLinTx_Control,
      void* aGSM_EnhLinTx_Data,
      void* aGSM_Tx_Cx_Cal_NV,
      unsigned char bCachedByNVManager);


   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Linear Envelope DC Cal .  The NV items include NV_<band>_LINEAR_ENVDC_CAL_VAL

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param iEnvDCVal [input] Env DC Cal calibration value

   \param pEnvDCValItem [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Linear_Env_DC_Cal_Results(HANDLE hResourceContext, unsigned short iNvModeId, unsigned short iEnvDCVal, void * pEnvDCValItem, unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Delay calibration.  The NV items include NV_<band>_POLAR_PATH_DELAY

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param iPolarDelayPathValue [input] Polar delay path calibration value

   \param pDelay_Cal_NVItem [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Delay_Cal_Results(HANDLE hResourceContext, unsigned short iNvModeId, unsigned short iPolarDelayPathValue, void * pDelay_Cal_NVItem, unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the chain enumerated NV items associated with GSM Delay calibration.
   The NV items include RFNV_GSM_C<chainID>_GSM<band>_POLAR_PATH_DELAY_I.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param iPolarDelayPathValue [input] Polar delay path calibration value

   \param pDelay_Cal_NVItem [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param chainID [input] The ID of the Tx chain being calibrated, i.e. CO, C2, etc.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Delay_Cal_Results_v2(HANDLE hResourceContext, unsigned short iNvModeId, unsigned short iPolarDelayPathValue, void * pDelay_Cal_NVItem, unsigned char bCachedByNVManager, unsigned short chainID);


   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Tx RSB calibration.  The NV items include NV_<band>_TX_RSB_CORR_I

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aRSB [input] Pointer to QMSL_GSM_Rx_RSB_struct.  See QLib_Defines.h for details

   \param pRSB_NVItem [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_RSB_Cal_Results(HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aRSB,
         void * pRSB_NVItem,
         unsigned char bCachedByNVManager
                                                           );

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Tx 4xFMod calibration.  The NV items includes NV_<band>_PA_TEMP_COMP_INDEX_11

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param i4xFModValue [input] 4xFMod Calibration result

   \param p4xFModNVItem [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_4xFMod_Cal_Results( HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned char i4xFModValue,
         void * p4xFModNVItem,
         unsigned char bCachedByNVManager
                                                              );

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Tx DC DC PDM calibration.  The NV items includes NV_GSM_<band>_SMPS_PDM_TBL_I

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aGSM_DC_DC_PDM_Cal [input] DC DC PDM cal measurements and parameters. See QLib_Defines.h for details

   \param aGSM_DC_DC_PDM_Cal_NV [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_DC_DC_PDM_Cal_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aGSM_DC_DC_PDM_Cal,
         void*aGSM_DC_DC_PDM_Cal_NV,
         unsigned char bCachedByNVManager);
   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Tx PA DAC calibration.  The NV items includes NV_GSM_<band>_PADAC_DC_OFFSET_I

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aGSM_PA_DAC_Cal [input] DC DC PDM cal measurements and parameters. See QLib_Defines.h for details

   \param aGSM_PA_DAC_Cal_NV [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_PA_DAC_Cal_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aGSM_PA_DAC_Cal,
         void*aGSM_DPA_DAC_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM Tx Pout calibration.  The NV items includes NV_<band>_PA_TEMP_COMP_INDEX_10

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param iVgaOut [input] Pout calibration value

   \param pPout_NVItem [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_Pout_Cal_Results(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned char iVgaOut,
      void * pPout_NVItem,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   /**
   Generate the NV items associated with OPLL calibration.  The NV items includes NV_<band>_OPLL_BW_VAL

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param iOPLLValue [input] OPLL calibration value

   \param pOPLL_NVItem [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Tx_OPLL_Cal_Results(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned char iOPLLValue,
      void * pOPLL_NVItem,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM IM2 calibration.  The NV items includes NV_GSM_IM2_<band>

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aGSM_IM2_Cal_Result [input] Pointer to QMSL_GSM_IM2_struct, GSM IM2 calibration result.  See QLib_Defines.h for details

   \param pGSM_IM2_NVItem [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_GSM_Rx_IM2_Cal_Results(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      void* aGSM_IM2_Cal_Result,
      void * pGSM_IM2_NVItem,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM LNA gain range calibration.  The NV items includes NV_<band>_RX_GAIN_RANGE_<n>_FREQ_COMP

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aGSM_Rx_Gain_Range_Result [input] Pointer to QMSL_GSM_Rx_Gain_Range_struct, GSM LNA range gain calibration values.  See QLib_Defines.h for details

   \param aGSM_Rx_Gain_Range_NV [output] Pointer to QMSL_GSM_Rx_Gain_Range_NV_struct.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GSM_Rx_Gain_Range_Results(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      void* aGSM_Rx_Gain_Range_Result,
      void* aGSM_Rx_Gain_Range_NV,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   /**
   Generate GSM calibrationa channel list item (NV_GSM_CAL_ARFCN NV) items.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aGSM_Cal_ARFCN_List [input] Pointer to an array of GSM calbrtation channel

   \param iNumOfChannel [input] Number of channel in aGSM_Cal_ARFCN_List

   \param pGSM_Cal_ARFCN_NV [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_GSM_CAL_ARFCN(HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned short* aGSM_Cal_ARFCN_List,
         unsigned char iNumOfChannel,
         void * pGSM_Cal_ARFCN_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM LNA gain range
   calibration.  The NV items includes
   RFNV_GSM_C<?>_<band>_RX_CAL_DATA

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aGSM_Rx_Calibration_Meas_n_Params [input] Pointer to
          QMSL_GSM_Rx_Calibration_Params_and_Meas, GSM LNA range
          gain calibration values.  See QLib_Defines.h for details

   \param aGSM_Rx_Calibration_NV [output] Pointer to
          QMSL_GSM_Rx_Calibration_NV.  See QLib_Defines.h
          for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
   bCachedByNVManager == 1: Store NV items
   bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSM_RX_CALIBRATION_GENERATE_NV(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      void* aGSM_Rx_Calibration_Params_n_Meas,
      void* aGSM_Rx_Calibration_NV,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   /**
   Generate the NV items associated with GSM LNA gain range for high linearity mode
   calibration.  The NV items includes
   RFNV_GSM_C<?>_<band>_RX_CAL_DATA

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aGSM_Rx_Calibration_Meas_n_Params [input] Pointer to
          QMSL_GSM_Rx_Calibration_Params_and_Meas, GSM LNA range
          gain calibration values.  See QLib_Defines.h for details

   \param aGSM_Rx_Calibration_NV [output] Pointer to
          QMSL_GSM_Rx_Calibration_NV.  See QLib_Defines.h
          for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
   bCachedByNVManager == 1: Store NV items
   bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   */
   QLIB_API unsigned char QLIB_GSM_RX_CALIBRATION_GENERATE_NV_HI_LIN(
      HANDLE hResourceContext,
      unsigned short iNvModeId,
      void* aGSM_Rx_Calibration_Params_n_Meas,
      void* aGSM_Rx_Calibration_NV,
      unsigned char bCachedByNVManager
   );

   /******************************************************************************/
   //new for consolidated NW item
      /**
   Generate the NV items associated with GSM LNA gain range for high linearity mode
   calibration.  The NV items includes
   QMSL_RFCAL_CONSOLIDATED_RX

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aGSM_Rx_Calibration_Meas_n_Params_Consolidated [input] Pointer to
          QMSL_GSM_Rx_Calibration_Params_and_Meas_Consolidated, GSM LNA range
          gain calibration values.  See QLib_Defines.h for details

   \param aGSM_Rx_Calibration_NV [output] Pointer to
          QMSL_GSM_Rx_Calibration_NV.  See QLib_Defines.h
          for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
   bCachedByNVManager == 1: Store NV items
   bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param NVversion [input] 

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   */
   QLIB_API unsigned char QLIB_GSM_RX_CALIBRATION_GENERATE_NV_CONSOLIDATED(
   HANDLE hResourceContext,
   unsigned short iNvModeId,
   void* aGSM_Rx_Calibration_Meas_n_Params_Consolidated,
   unsigned int size,
   void* aGSM_Rx_Calibration_NV,
   unsigned char bCachedByNVManager,
   unsigned int NVversion
);

   /******************************************************************************/
   /**
   Generate NV items related to carrier suppression calibration.  The NV Items include (NV_GSM_DCS_CARRIER_SUPPRESSION_I, NV_GSM_1900_CARRIER_SUPPRESSION_I)

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param nIdc [input] optimized Idc value found using the procedure that involves multiple sweeps using QLIB_FTM_TX_CS_SWEEP()

   \param nQdc [input] optimized Qdc value found using the procedure that involves multiple sweeps using QLIB_FTM_TX_CS_SWEEP()

   \param pGSM_Carrier_Suppression_NV [output] structure of type QMSL_RFCAL_NV_Item, the result of the NV will be stored here.  No action
                                        is required on this data, it is provided for troubleshooting purposes.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_GSM_CARRIER_SUPRRESSION(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         short iIdc,
         short iQdc,
         void * pGSM_Carrier_Suppression_NV,
         unsigned char bCachedByNVManager);



   /******************************************************************************/
   /**
   Generate NV items related to internal thermistor calibration.  The NV Items include (NV_THERM, NV_THERM_TEMP_MAX, NV_THERM_TEMP_MIN)

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pInt_Therm_Cal_Meas [input] Pointer to QMSL_Internal_Thermistor_Cal_Meas_struct.  See QLib_Defines.h for details

   \param pInt_Therm_Cal_NV [input] Pointer to QMSL_Internal_Thermistor_Cal_NV_struct.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Internal_Thermistor_Calibration_Results(   HANDLE hResourceContext,
         void *pInt_Therm_Cal_Meas,
         void *pInt_Therm_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate NV items related to GPS RFIC IM2 calibration.  The NV Items include (NV_GPS1_GPS_RFIC_IM2CAL_IM2DAC_I_CHANNEL_I, NV_GPS1_GPS_RFIC_IM2CAL_IM2DAC_Q_CHANNEL_I)

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pGPS_IM2_Cal_Results [input] Pointer to QMSL_GPS_IM2_Cal_Results_struct.  See QLib_Defines.h for details

   \param pGPS_IM2_Cal_NV [input] Pointer to QMSL_GPS_IM2_Cal_NV_struct.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_GPS_IM2_Calibration_Results(   HANDLE hResourceContext,
         void *pGPS_IM2_Cal_Results,
         void *pGPS_IM2_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate NV items related to receiver IQ mismatch calibration.  The NV Items include

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pRx_IQMismatch_Cal_Meas [input] Pointer to QMSL_RxIQMismatch_Cal_Meas_struct.  See QLib_Defines.h for details

   \param pRx_IQMismatch_Cal_NV [input] Pointer to QMSL_RxIQMismatch_Cal_NV_struct.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_Rx_IQMismatch_Calibration_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void *pRx_IQMismatch_Cal_Meas,
         void *pRx_IQMismatch_Cal_NV,
         unsigned char bCachedByNVManager);
   /******************************************************************************/
   /**
   Run the ICI calibration algorithm on the given input data, and provide the raw ICI coefficients.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pRx_ICI_Cal_Meas [input] Pointer to QMSL_Rx_ICI_Cal_Meas_struct.  See QLib_Defines.h for details

   \return true if operation is successful, false otherwise

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_Rx_ICI_Calibration_Algorithm( HANDLE hResourceContext, void *pRx_ICI_Cal_Meas );

   /******************************************************************************/
   /**
   Generate NV items related to receiver ICI calibration.  The NV Items include

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pRx_ICI_Cal_Meas [input] Pointer to QMSL_Rx_ICI_Cal_Meas_struct.  See QLib_Defines.h for details

   \param pRx_ICI_Cal_NV [input] Pointer to QMSL_Rx_ICI_Cal_NV_struct.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_Rx_ICI_Calibration_Results(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void *pRx_ICI_Cal_Meas,
         void *pRx_ICI_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate NV items related to CDMA/WCDMA Calibration Channels (NV_TX_CAL_CHAN, NV_RX_CAL_CHAN, NV_RX1_CAL_CHAN)

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeId [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param iChannelTypeEnum [input] Enumeration of QMSL_RFCAL_Channel_Type

   \param pChannel_List [input] The pointer to channel list

   \param iNumOfChannel [input] Number of channel in the list

   \param pRFCal_Chan_NV [output] Pointer to QMSL_RFCAL_NV_Item.  See QLib_Defines.h for details

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if operation is successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_CAL_CHAN(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned short iChannelTypeEnum,
         unsigned short* pChannel_List,
         unsigned short iNumOfChannel,
         void *pRFCal_Chan_NV,
         unsigned char bCachedByNVManager);


   /******************************************************************************/
   /**
   Utility function.  Do linear interpolation/extrapolation for raw measurement data.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param adRawX [input] An array of raw measurement data(double) on X axis

   \param adRawY [input] An array of raw measurement data(int) on Y axis.

   \param iNumRawData[input] Number of raw measurment data point.

   \param aInputX [input] An array of data on X axis to be intrepolated.

   \param aOutputY [output] An array of exterpolated/intrepolated data on Y axis.

   \param iNumDataPoint[input].  The number of data point to be intrepolated/extrapolated.

   \param iMinValue[input].  The lower bound of extrepolated/intrepolated data

   \param iMaxValue[input].  The upper bound of extrepolated/intrepolated data

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_LinearInterpolation(   HANDLE hResourceContext,
         double * adRawX,
         int *aiRawY,
         int iNumRawData,
         double* aInputX,
         int* aOutputY,
         int iNumDataPoint,
         int iMinValue,
         int iMaxValue);

   /******************************************************************************/
   /**
   Utility function.  Do linear interpolation/extrapolation for raw measurement data.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param adRawX [input] An array of raw measurement data(double) on X axis.  The data on X axis must be sorted.

   \param adRawY [input] An array of raw measurement data(double) on Y axis.

   \param iNumRawData[input] Number of raw measurment data point.

   \param aInputX [input] An array of data on X axis to be interpolated.

   \param aOutputY [output] An array of extrapolated/intrepolated data on Y axis.

   \param iNumDataPoint[input].  The number of data point to be intrepolated/extrapolated.

   \param iNumOfPtsToAverageSlope[input].  The number of points on each side of the data series used to calculate the slope for data extrapolation

   \param iMinValue[input].  The lower bound of extrepolated/intrepolated data

   \param iMaxValue[input].  The upper bound of extrepolated/intrepolated data

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_LinearInterpolation_SlopeAveragingExtrapolation
   (   HANDLE hResourceContext,
      double * adRawX,
      double *aiRawY,
      int iNumRawData,
      double* aInputX,
      double* aOutputY,
      int iNumDataPoint,
      int iNumOfPtsToAverageSlope,
      double iMinValue,
      double iMaxValue);

   /******************************************************************************/
   /**
   Generates VBATT ADC calibration NV items.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iADCMinV [input] VBATT ADC value read when supply voltage is set to the design dependent minimum operating voltage.

   \param iADCNomV [input] VBATT ADC value read when supply voltage is set to the design dependent nominal operating voltage.

   \param iADCMaxV [input] VBATT ADC value read when supply voltage is set to the design dependent maximum operating voltage.

   \param pVbattCalMin_NV [output] Pointer to QMSL_RFCAL_NV_Item data structure. See QLib_Defines.h for definition. Stores the NV item generated for VBATT ADC calibration when the supply voltage set to the design dependent minimum operating voltage.

   \param pVbattCalNom_NV [output] Pointer to QMSL_RFCAL_NV_Item data structure. See QLib_Defines.h for definition. Stores the NV item generated for VBATT ADC calibration when the supply voltage set to the design dependent nominal operating voltage.

   \param pVbattCalMax_NV [output] Pointer to QMSL_RFCAL_NV_Item data structure. See QLib_Defines.h for definition. Stores the NV item generated for VBATT ADC calibration when the supply voltage set to the design dependent maximum operating voltage.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_VBATT_ADC_CAL( HANDLE hResourceContext,
         unsigned short iADCMinV,
         unsigned short iADCNomV,
         unsigned short iADCMaxV,
         void * pVbattCalMin_NV,
         void * pVbattCalNom_NV,
         void * pVbattCalMax_NV,
         unsigned char bCachedByNVManager );

   /******************************************************************************/
   /**
   Generate V3 Cal Tx Linearizer, Tx Freq Comp , Rx Freq Comp, Tx AGC vs HDET, HDET offset and span NV items

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aFTM_Request [input] Pointer to FTM_Cal_Sweep_Request.  The data structure stores Tx measurement request.  See QLib_Defines.h for definition

   \param aFTM_Response [input] Pointer to FTM_Cal_Sweep_Response.  The data structure stores the Tx measurenment Response.  See QLib_Defines.h for definition
   Make sure the TxPower is dB10 for Linearizer and dB100 for FreqComp

   \param aTx_NV_Structure [output] Pointer to QMSL_Tx_Cal_Complete_NV_Type.  The data structure stores the Tx NV Data.  See QLib_Defines.h for definition

   \param numRecords [input] . The data variable stores the total numebr of measurements.

   \param aTx_Lin_Cal_NV_Info [input] .Pointer to QMSL_Tx_Cal_NV_Gen_Info.  The data structure stores the parameters needed for Tx NV generation.

   \param numLin [output] . Pointer to unsigned short. The data variable stores the total number of linearizers.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param iNVPath [input] . Path to which the NV should be written. 0 = PRx, 2= SV Path.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Complete_TxRxCal(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aFTM_Request,
         void* aFTM_Response,
         void* aTx_NV_Structure,
         unsigned short numRecords,
         void* aTx_Lin_Cal_NV_Info,
         unsigned short* numLin,
         unsigned short iNVPath,
         unsigned char bCachedByNVManager
                                                     );

   /******************************************************************************/
   /**
   Generate Version 2 of V3 Cal Tx Linearizer, Tx Freq Comp , Rx Freq Comp, Tx AGC vs HDET, HDET offset and span NV items

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param aFTM_Request [input] Pointer to FTM_Cal_Sweep_Request.  The data structure stores Tx measurement request.  See QLib_Defines.h for definition

   \param aFTM_Response [input] Pointer to FTM_Cal_Sweep_Response.  The data structure stores the Tx measurenment Response.  See QLib_Defines.h for definition
   Make sure the TxPower is dB10 for Linearizer and dB100 for FreqComp

   \param aTx_NV_Structure [output] Pointer to QMSL_Tx_Cal_Complete_NV_Type.  The data structure stores the Tx NV Data.  See QLib_Defines.h for definition

   \param numRecords [input] . The data variable stores the total numebr of measurements.

   \param aTx_Lin_Cal_NV_Info [input] .Pointer to QMSL_Tx_Cal_NV_Gen_Info.  The data structure stores the parameters needed for Tx NV generation.

   \param numLin [output] . Pointer to unsigned short. The data variable stores the total number of linearizers.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager.  NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
   bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items.  Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param iNVPath [input] . Path to which the NV should be written. 0 = PRx, 2= SV Path.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Complete_TxRxCal_Rev2(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aFTM_Request,
         void* aFTM_Response,
         void* aTx_NV_Structure,
         unsigned short numRecords,
         void* aTx_Lin_Cal_NV_Info,
         unsigned short* numLin,
         unsigned short* numDPDLin,
         unsigned short iNVPath,
         unsigned char bCachedByNVManager
                                                          );

   QLIB_API unsigned char QLIB_RFCAL_Override_DPD_NV(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aTx_NV_Structure,
         unsigned short NVPath,
         unsigned char bCachedByNVManager );
   //Temporary API , to be deleted.
   QLIB_API unsigned char QLIB_RFCAL_Complete_V2_V3_TxRxCal(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* aFTM_TxLin_Request,
         void* aFTM_TxLin_Response,
         void* aTx_NV_Structure,
         unsigned short numRecords,
         void* freq_comp,
         void* channel_list,
         unsigned short num_pa_states,
         unsigned char bCachedByNVManager
                                                           );
   /******************************************************************************/
   /**
   Add a NV item to NV Manager's cache.  The NV item must be managed by NV Manager.  Use QLIB_RFCAL_NV_Manager_IsNVItemManaged to
   check whether the NV item is managed.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pNVitem[input].  Pointer to QMSL_RFCAL_NV_Item.

   \return false if the NV item is managed by NV Manager

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_AddNVItem(   HANDLE hResourceContext,
         void* pNVItem);


   /******************************************************************************/
   /**
   The NV Manager has a built in list of RF NV items.  The function checks whether the NV item is in the list

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNVEnum[input] NV Item Enuermation

   \return true if the NV item is managed by NV Manager, false otherwise.

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_IsNVItemManaged(   HANDLE hResourceContext,
         unsigned short iNVEnum);


   /******************************************************************************/
   /**
   Get the number of NV items stored in NV Manager's cache.  The number includes both items generated by
   QLIB_RFCAL_xxx_Results functions and QLIB_RFCAL_NV_Manager_Add_OEM_NVItem.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNumOfItemInCache[input] number of NV items stored in NV Manager's cache

   \return true

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_GetNumItemInCache(   HANDLE hResourceContext,
         unsigned short* iNumOfItemInCache);


   /******************************************************************************/
   /**
   Add an OEM NV item to NV Manager's cache.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pNVitem[input].  Pointer to QMSL_RFCAL_NV_Item.

   \return

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Add_OEM_NVItem(   HANDLE hResourceContext,
         void* pNVItem);

   /******************************************************************************/
   /**
   Get a NV item stored in NV Manager.  Call this function after QLIB_RFCAL_xxx_Results

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNVEnum[input] NV Item Enuermation

   \param iStatus[output] The status bit in NV Manager.  1 if the item has data, 0 if the item is clear.

   \param pNVitem[output].  Pointer to QMSL_RFCAL_NV_Item.  The function will fill up this data struture if the item has data.

   \return false if the NV item is not managed by NV Manager

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_GetNVItem(   HANDLE hResourceContext,
         unsigned short iNVEnum,
         unsigned char* iStatus,
         void* pNVItem);

   /******************************************************************************/
   /**
   Backup RF NV item from mobile to NV Manager.

   This function backup RF NV data from mobile to NV Manager.  The data can be later combined
   with calibrated RF NV item value generated by NV Manager to create a single QCN file

   This function uses FTM_RFNV_READ command.  The device must be in FTM mode

   This function clear the RF NV data generated by previous call to to the same function

   \param a list of legacy or RFNV item ID

   \param a list of FTM_RFNV_READ FTM error code retrieved during the backup operation.  The size of
   this list should be the same as pRFNV_Item_List

   \param iNumOfRFNVItem, the size of pRFNV_Item_List

   \warning This function always return 1;

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_BackupNVItems( HANDLE hResourceContext,
         unsigned short* pRFNV_Item_List,
         unsigned short* pFTM_RFNV_Read_Error_Code_list,
         unsigned short  iNumOfRFNVItem
                                                             );
   /******************************************************************************/
   /**
   Copy RF NV item data from NV Tool area to NV Manager

   This function copies RF NV data stored/generate by NV Tool to NV Manager.  The data can be later combined
   with calibrated RF NV item value generated by NV Manager to create a single QCN file

   This function clear the RF NV data generated by previous call to to the same function

   See the following QMSL APIs for reference

   QLIB_NV_LoadNVDataTypeDictinary
   QLIB_NV_LoadNVDefinitionFile
   QLIB_NV_LoadNVsFromSource
   QLIB_NV_LoadNVsFromQCN
   QLIB_NV_LoadNVsFromPhone

   \param iNumOfItemsCopied, the number of items copied from NV Tool

   \warning This function always return 1;
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Copy_RFNV_Items_From_NV_Tool( HANDLE hResourceContext,
         unsigned short* iNumOfItemsCopied);

   /******************************************************************************/
   /**

   Force QLIB_RFCAL_NV_Manager_WriteToPhone to write NV through different method

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iWriteToPhoneMethod.  See QMSL_Manager_WriteToPhone_Method in Qlib_Defines.h

         Do not use NV_Manager_WriteToPhone_USE_LEGACY_NV_WRITE if you expect to write RFNV with ID > 20000
         NV_WRITE command does not work RFNV ID > 20000

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_WriteToPhoneMethod(HANDLE hResourceContext, int iWriteToPhoneMethod);


   /******************************************************************************/
   /**
   Write NV items stored in NV Manager to mobile station.  The NV items are generated by previous QLIB_RFCAL_xxx_Results calls
   By default, the API will use AUTO_DETECT method to use NV_WRITE or FTM_RFNV_WRITE to write data

   Call QLIB_RFCAL_NV_Manager_WriteToPhoneMethod to override the AUTO_DETECT mode

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param pWriteToPhoneStatus Pointer to QMSL_RFCal_WriteToPhone_Status.  This structure return the ID and status of NV items written to mobile.  This pointer can be NULL.

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_WriteToPhone( HANDLE hResourceContext, void *pWriteToPhoneStatus );


   /******************************************************************************/
   /**
   Adapt early exit stragety when NV Write failure occurs.

   By default, QLIB_RFCAL_NV_Manager_WriteToPhone will try to write every calibrated NV items cached by RFCal NV Manager.  This API will enable
   QLIB_RFCAL_NV_Manager_WriteToPhone to exit early when NV write failure to occurs

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iEnableEarlyExit 0 == Disable(Default)
                     1 == Enable

   \param iSzOfNVIDLIstToIgnore = Size of iSzOfNVIDLIstToIgnore

   \param iNVIDLIstToIgnore = A list of NV ID for this stragety to ignore NV write failure.  Note that some legacy NV items such as NV571 can be only be written once.

   \return false

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Enable_Early_Exit_WriteToPhone( HANDLE hResourceContext, unsigned char iEnableEarlyExit, int iSzOfNVIDLIstToIgnore, unsigned short* iNVIDLIstToIgnore);

   /******************************************************************************/
   /**
   This API verifies the RF NV items written by QLIB_RFCAL_NV_Manager_WriteToPhone.  The API should be called before QLIB_RFCAL_NV_Manager_Clear_Data API. 

   The API can be called in the following sequence

   1.  QLIB_RFCAL_NV_Manager_WriteToPhone
   2.  QLIB_EFS2_SyncWithWait
   3.  Reset the device (optional)
   4.  QLIB_RFCAL_NV_Manager_ReadVerify

   \param hResourceContext  Resource context that was returned from the call to QLIB_ConnectServer().

   \param pWriteToPhoneStatus Pointer to QMSL_RFCal_ReadVerify_Status.  This structure returns the ID and status of RF NV items written to mobile.

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_ReadVerify( HANDLE hResourceContext, void *pReadVerifyStatus );

   /******************************************************************************/
   /**
   Generate a QCN file of NV items generated.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param sFileName [input] File name path

   \return false

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Create_QCN( HANDLE hResourceContext, char* sQCNPath  );

   /******************************************************************************/
   /**
   Generate a QCN file based on the NVList passed.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param sQCNPath [input]   QCN File name path,
          pNvItemList[input],  NV List that need to be in the qcn

   \return false

   \warning
   *******************************************************************************/

  QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Create_QCN_By_NV_List( HANDLE hResourceContext, char* sQCNPath,void * pNvItemList  );


   /******************************************************************************/
   /**
   Generate a HTML file of NV items generated

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param sFileName [input] File name path

   \return true if operation is successful, false otherwise

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Create_HTML( HANDLE hResourceContext, char* sHTMLReportFile  );

   /******************************************************************************/
   /**
   Generate a text file of NV items stored in NV manager

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param sFileName [input] File name path

   \return true if operation is successful, false otherwise

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Create_Text( HANDLE hResourceContext, char* sTextOutputFile  );

   /******************************************************************************/
   /**
   Generate a XML file of NV items generated.  The XML file can be used by QRCT to load NV to mobile station.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param sFileName [input] File name path

   \return true if operation is successful, false otherwise

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Create_XML ( HANDLE hResourceContext, char* sXMLOutputFile  );


   /******************************************************************************/
   /**
   Generate a HTML file of NV items generated in byte (HEX) view.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param sFileName [input] File name path

   \return true if operation is successful, false otherwise

   \warning
   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Create_HTML_ByteStream ( HANDLE hResourceContext, char* sHTMLOutputFile  );


   /******************************************************************************/
   /**
   Clear all NV items stored in NV Manager.  The NV Items are generated by previous QLIB_RFCAL_xxx_Results calls or
   QLIB_RFCAL_NV_Manager_Add_OEM_NVItem.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_NV_Manager_Clear_Data( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   QLIB_RFCal_Interpolate.
   Given a known relationship of [X,Y] of length iInLen, performs
   linear interpolation and determines Y1 of length iOutLen
   corresponding to array X1.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_Interpolate(   HANDLE hResourceContext, float* X, float* Y, unsigned short iInLen,
         float* X1,unsigned short iOutLen, float *Y1);

   /******************************************************************************/
   /**
   QLIB_RFCal_Interpolate_Bias_with_Icq.
   Given a known relationship of [X,Y] of length iInLen, performs
   linear interpolation and determines Y1 of length iOutLen
   corresponding to array X1. Note the format of Y is
   b31:enable bit, b30-b16:15-bit Icq, b15-b0:16-bit bias value
   Note array max size = 512.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCal_Interpolate_Bias_with_Icq(   HANDLE hResourceContext, float* powerChar, unsigned long* icqBiasChar, unsigned short iInLen,
      float* powerInterp,unsigned short iOutLen, unsigned long *icqBiasInterp);
   /******************************************************************************/
   /**
   QLIB_RFCal_Compute_Bias_with_Icq.
   Calls functions which do the following
   1>Given a known relationship of [X,Y] of length iInLen, performs
   linear interpolation and determines Y1 of length iOutLen
   corresponding to array X1. 
   2>Given a known relationship of [X,Y] of length iInLen,  determines Y1 of length iOutLen
   corresponding to next highest X1.Also  Note the format of Y is
   b31:enable bit, b30-b16:15-bit Icq, b15-b0:16-bit bias value
   Note array max size = 512.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \return true if operation is successful, false otherwise

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCal_Compute_Bias_with_Icq(  HANDLE hResourceContext, float* powerChar, unsigned long* icqBiasChar, unsigned short iInLen,
      float* powerInterp,unsigned short iOutLen, unsigned long *icqBiasInterp);

   /******************************************************************************/
   /**
   Generate Ref Cal Tx Linearizer, Tx Freq Comp

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.  The NV mode ID determines the set of NV items to be generated.  See QLib_Defines.h for definition

   \param ref_cal_meas [input] Ref cal measurements (dBm*10)

   \param aTx_Lin_Cal_NV_Info [input] .Pointer to QMSL_Tx_Cal_NV_Gen_Info. The data structure stores the parameters needed for Tx NV generation.

   \param aTx_NV_Structure  [output] Pointer to QMSL_Tx_Cal_Complete_NV_Type. The data structure stores the Tx NV Data. See QLib_Defines.h for definition

   \param aTx_NV_Structure_Rev2 [output] Pointer to QMSL_Tx_Cal_Complete_NV_Type. The data structure stores the Tx NV Data. See QLib_Defines.h for definition

   \param aTx_NV_Structure_Rev2

   \param numRecords [input] . The data variable stores the total numebr of measurements.

   \param wfm_idx [input] waveform index

   \param write_to_v2_nv [input] flag to write to Rev2 Multi-Lin NV

   \param iNVPath [input] Path to which the NV should be written. 0 = PRx, 2= SV Path.

   \param bCachedByNVManager [input]  Store generated NV items in NV Manager. NV items stored in NV Manager will be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.
                              bCachedByNVManager == 1: Store NV items
                              bCachedByNVManager == 0: Do not store NV items. Generated NV items will not be written to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RefCal_MultiLin_NV_Write(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         void* ref_cal_meas,
         void* aTx_Cal_NV_Info,
         void* aTx_NV_Structure,
         void* aTx_NV_Structure_Rev2,
         long numRecords,
         int wfm_idx,
         bool write_to_v2_nv,
         int iNVPath,
         bool bCachedByNVManager );

   /******************************************************************************/
   /**
   TempComp Characterized table adjustment based on the calibration temperature Using QCN file
   \param sQCN_Path                      [input] static QCN File Path
   \param iRF_Mode                     [input] RF_Mode
   \param iTempCompAdjustMeasurementType   [input] TempcompAdjust MeasurementType. Valid measurement type for tempCompAdjust is QMSL_RFcal_TempCompAdj_MeasureType_TX_LIN_VS_TEMP
   \param iCurrentThermal_ADC            [input] The current thermal ADC value
   \param piPA_State                  [input] The array of calibration PA states of the curent band that needs to do tempComp Adjust
   \param iNum_Of_PaStates               [input] The number of piPA_State.
   \param piDeltaTempComp               [input] The TempComp adjusted value based on the calibration temperature
   \param piResultCode                  [output] The errorCode

   \return 1 if successful, 0 if failure.

   *******************************************************************************/

   QLIB_API unsigned char   QLIB_TempCompAdjustForMeasuredThermalValue( HANDLE hResourceContext,
         const char * sQCN_Path,
         int iRF_Mode,
         int iTempCompAdjustMeasurementType,
         int iCurrentThermal_ADC,
         int * piPA_State,
         unsigned char iNum_Of_PaStates,
         int * piDeltaTempComp,  // pass deltaTempComp to upper level for commonCal usuage, set it as int * dataType for possible of gsm tempComp usuage
         int *piResultCode );

   /******************************************************************************/
   /**
   TempComp Characterized table adjustment based on the calibration temperature using NVSrc XML and NVDef files
   \param sNVSrcXML_Path              [input] static RF NV Source File Path
   \param sNVDef_Path                     [input] NVDefinition File Path
   \param iRF_Mode                    [input] RF_Mode
   \param iTempCompAdjustMeasurementType  [input] TempcompAdjust MeasurementType. Valid measurement type for tempCompAdjust is QMSL_RFcal_TempCompAdj_MeasureType_TX_LIN_VS_TEMP
   \param iCurrentThermal_ADC           [input] The current thermal ADC value
   \param piPA_State                 [input] The array of calibration PA states of the curent band that needs to do tempComp Adjust
   \param iNum_Of_PaStates              [input] The number of piPA_State.
   \param piDeltaTempComp              [input] The TempComp adjusted value based on the calibration temperature
   \param piResultCode                 [output] The errorCode

   \return 1 if successful, 0 if failure.

   *******************************************************************************/
    QLIB_API unsigned char   QLIB_TempCompAdjustForMeasuredThermalValue_UsingSrcXML_NVFile ( HANDLE hResourceContext,
         const char * sNVSrcXML_Path,
       const char * sNVDef_Path,
         int iRF_Mode,
         int iTempCompAdjustMeasurementType,
         int iCurrentThermal_ADC,
         int * piPA_State,
         unsigned char iNum_Of_PaStates,
         int * piDeltaTempComp,  // pass deltaTempComp to upper level for commonCal usuage, set it as int * dataType for possible of gsm tempComp usuage
         int *piResultCode );

   /******************************************************************************/
   /**
   Generate Enh Sweep Calibration NV
   This function will get a list of sweep records that correspond
   to all measurment performed during calibration - and will walk
   through those measurement and generate multilin_v3, hdet_vs_agc,
   lim_vs_freq, lna_offset_vs_freq and dvga_vs_freq NV items

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
          0 = PRx, 2= SV Path.

   \param numRecords [input] The data variable stores the total
          numebr of measurements.

   \param refChan [input] Identifies the reference channel used.

   \param upperBoundChan [input] Identifies the upper bound channel to be used.

   \param hdetNVParams [input] Has params required for HDET NV Generation
          Pointer to QMSL_RFCAL_ESC_HDET_NV_Params type

   \param hdetNVRes [output] Has results from HDET NV Generation
          Pointer to QMSL_RFCAL_ESC_HDET_NV_Results type

   \param limVsFreqNv [output] Has results from Lim Vs Freq NV Generation
          Pointer to QMSL_RFCAL_Tx_LimVsFreq_NV_Results type

   \param aCal_Sweep_Records [input] .Pointer to cal_sweep_record.
          The data structure stores the information needed for NV
          generation.

   \param aESC_Cal_NV [output] Pointer to
          QMSL_RFCAL_ESC_Calibration_NV . The data structure stores
          the output NV.

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager. NV items stored in NV Manager will be written
          to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
          called.
            bCachedByNVManager == 1: Store NV items
            bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Generate_ESC_Tx_NV(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned short iNVPath,
         unsigned short numRecords,
         unsigned long refChan,
         unsigned long upperBoundChan,
         void* hdetNVParams,
         void* hdetNVRes,
         void* limVsFreqNv,
         void* aCal_Sweep_Records,
         void* aESC_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   
   Get NV enumeration with specific NvModeId and meas type
   This function will get the nv enumeration according to the NvModeId and measType.
   Details are according to QMSL_NVManager_SetupDefinition.xml

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iMeasType [input] Enumeration of pointer of type QMSL_MeasurementType 

   \param iState [input] Identifies the state

   \param iNVID [output] Returns the NVID enumeration

   \return true if successful, false otherwise

   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ID_BY_MEASUREMENT_TYPE(   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned short iMeasType,
      int iState,
      int* iNVID);

   /******************************************************************************/
   /**
   Generate Enh Sweep Calibration NV
   This function will get a list of sweep records that correspond
   to all measurment performed during calibration - and will walk
   through those measurement and generate multilin_v3, hdet_vs_agc,
   lim_vs_freq, lna_offset_vs_freq and dvga_vs_freq NV items

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
          0 = PRx, 2= SV Path.

   \param numRecords [input] The data variable stores the total
          numebr of measurements.

   \param refChan [input] Identifies the reference channel used.

   \param upperBoundChan [input]  Identifes the Upper Bound channel.

   \param hdetNVParams [input] Has params required for HDET NV Generation
          Pointer to QMSL_RFCAL_ESC_HDET_NV_Params type

   \param hdetNVRes [output] Has results from HDET NV Generation
          Pointer to QMSL_RFCAL_ESC_HDET_NV_Results type

   \param limVsFreqNv [output] Has results from Lim Vs Freq NV Generation
          Pointer to QMSL_RFCAL_Tx_LimVsFreq_NV_Results type

   \param aCal_Sweep_Records [input] .Pointer to cal_sweep_record.
          The data structure stores the information needed for NV
          generation.

   \param aProto_Cal_Records [input] .Pointer to
          QMSL_xpt_cal_nv_struct . The data structure stores
          the information needed for NV generation.

   \param aESC_Cal_NV [output] Pointer to
          QMSL_RFCAL_ESC_Calibration_NV . The data structure stores
          the output NV.

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager. NV items stored in NV Manager will be written
          to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
          called.
            bCachedByNVManager == 1: Store NV items
            bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Generate_ESC_and_ProtoCal_Tx_NV(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned short iNVPath,
         unsigned short numRecords,
         unsigned long refChan,
         unsigned long upperBoundChan,
         void* hdetNVParams,
         void* hdetNVRes,
         void* limVsFreqNv,
         void* aCal_Sweep_Records,
         void* aProto_Cal_Records,
         void* aESC_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Enh Sweep Calibration Rx NV
   This function will get a list of sweep records that correspond
   to all measurment performed during calibration - and will walk
   through those measurement and generate multilin_v3, hdet_vs_agc,
   lim_vs_freq, lna_offset_vs_freq and dvga_vs_freq NV items

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
          0 = PRx, 2= SV Path.

   \param numRecords [input] The data variable stores the total
          numebr of measurements.

   \param refChan [input] Identifies the reference channel used.

   \param aCal_Sweep_Records [input] .Pointer to cal_sweep_record.
          The data structure stores the information needed for NV
          generation.

   \param aRX_DVGA_LNA_Cal_NV [output] Pointer to QMSL_CDMA_Rx_DVGA_LNA_Cal_NV_Result.
          The data structure stores the NV item values generated.

   \param aRX_NV_Channels   [input]  Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.
          This list must always contain 16 values. If fewer channels are desired to be used then
          the last valid channel (highest frequency) is to be filled into the end of the
          list, such that there are 16 items in the list.

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager. NV items stored in NV Manager will be written
          to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
          called.
            bCachedByNVManager == 1: Store NV items
            bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Generate_ESC_Rx_NV(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned short iNVPath,
         unsigned short numRecords,
         unsigned short refChan,
         void* aCal_Sweep_Records,
         void* aRX_DVGA_LNA_Cal_NV,
         void* aRx_NV_Channels,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Enh Sweep Calibration Rx NV
   This function will get a list of sweep records that correspond
   to all measurment performed during calibration - and will walk
   through those measurement and generate multilin_v3, hdet_vs_agc,
   lim_vs_freq, lna_offset_vs_freq and dvga_vs_freq NV items

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
          0 = PRx, 2= SV Path.

   \param iNVChain [input] NV chain to which the NV should be written.
  
   \param numRecords [input] The data variable stores the total
          numebr of measurements.

   \param refChan [input] Identifies the reference channel used.

   \param aCal_Sweep_Records [input] .Pointer to cal_sweep_record.
          The data structure stores the information needed for NV
          generation.

   \param aRX_DVGA_LNA_Cal_NV [output] Pointer to QMSL_CDMA_Rx_DVGA_LNA_Cal_NV_Result.
          The data structure stores the NV item values generated.

   \param aRX_NV_Channels   [input]  Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.
          This list must always contain 16 values. If fewer channels are desired to be used then
          the last valid channel (highest frequency) is to be filled into the end of the
          list, such that there are 16 items in the list.

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager. NV items stored in NV Manager will be written
          to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
          called.
            bCachedByNVManager == 1: Store NV items
            bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Generate_ESC_Rx_NV_WithChainMap(   HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned short iNVPath,
         unsigned short iNVChain,
         unsigned short numRecords,
         unsigned short refChan,
         void* aCal_Sweep_Records,
         void* aRX_DVGA_LNA_Cal_NV,
         void* aRx_NV_Channels,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Unified Sweep Calibration Unified Rx NV
   This function will get a list of sweep records that correspond
   to all measurment performed during calibration - and will walk
   through those measurement and generate multilin_v3, hdet_vs_agc,
   lim_vs_freq, lna_offset_vs_freq and dvga_vs_freq NV items

   \param hResourceContext   Resource context that was returned from
   the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
   NV mode ID determines the set of NV items to be
   generated.  See QLib_Defines.h for definition

   \param iDev [input] Device to which to write the NV.
   0 = PRx, 2= SV Path.

   \param numRecords [input] The data variable stores the total
   numebr of measurements.

   \param refChan [input] Identifies the reference channel used.

   \param aCal_Sweep_Records [input] .Pointer to cal_sweep_record.
   The data structure stores the information needed for NV
   generation.

   \param aRX_NV_Channels   [input]  Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.
   This list must always contain 16 values. If fewer channels are desired to be used then
   the last valid channel (highest frequency) is to be filled into the end of the
   list, such that there are 16 items in the list.

   \param bCachedByNVManager [input]  Store generated NV items in
   NV Manager. NV items stored in NV Manager will be written
   to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
   called.
   bCachedByNVManager == 1: Store NV items
   bCachedByNVManager == 0: Do not store NV items.
   Generated NV items will not be written to mobile when
   QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
   QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Generate_Unified_ESC_Rx_NV(   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned short iDev,
      unsigned short numRecords_Type,
      void* aCal_Sweep_Records_Size,
      void* aCal_Sweep_Records_Type,
      unsigned short refChan,
      void* aCal_Sweep_Records,
      void* aRx_NV_Channels,
      unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Enh Sweep Calibration Enhanced Rx NV
   This function will get a list of sweep records that correspond
   to all measurment performed during calibration - and will walk
   through those measurement and generate multilin_v3, hdet_vs_agc,
   lim_vs_freq, lna_offset_vs_freq and dvga_vs_freq NV items. It also
   handles NV generation for intraband CA calibration.

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
          0 = PRx, 2= SV Path.

   \param numRecords [input] The data variable stores the total
          numebr of measurements.

   \param refChan [input] Identifies the reference channel used.

   \param aCal_Sweep_Records [input] .Pointer to cal_sweep_record.
          The data structure stores the information needed for NV
          generation.

   \param aRX_DVGA_LNA_Cal_NV [output] Pointer to QMSL_CDMA_Rx_DVGA_LNA_Cal_NV_Result.
          The data structure stores the NV item values generated.

   \param aRX_IntraCA_Cal_NV [output] Pointer to QMSL_LTE_Rx_IntraCA_Cal_NV_Result.
          The data structure stores the Intraband CA calibration NV item values generated.

   \param aRX_NV_Channels   [input]  Pointer to QMSL_CDMA_NVChannels_struct. The list of RF channels which NV generation is used.
          This list must always contain 16 values. If fewer channels are desired to be used then
          the last valid channel (highest frequency) is to be filled into the end of the
          list, such that there are 16 items in the list.

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager. NV items stored in NV Manager will be written
          to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
          called.
            bCachedByNVManager == 1: Store NV items
            bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/   
   QLIB_API unsigned char QLIB_RFCAL_Enh_Generate_ESC_Rx_NV( HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned short iNVPath,
         unsigned short numRecords,
         unsigned short refChan,
         void* aCal_Sweep_Records,
         void* aRX_DVGA_LNA_Cal_NV,
         void* aRX_IntraCA_Cal_NV,
         void* aRx_NV_Channels,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate FBRX Gain vs Freq Calibration NV
   This function will get a list of sweep records that correspond
   to all measurment performed during fbrx calibration - and will walk
   through those measurements and generate the FBRX_GAIN_FREQ NV item
   for the corresponding NV mode ID

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
          0 = PRx, 2= SV Path.

   \param Channel_List [input] .Pointer to calibration channels used for the
          FBRx calibration . This list is stored in the FBRX_GAIN_FREQ NV item
          
   \param aFbrx_Gain_Freq_Cal_Records [input] .Pointer to FBRX freq vs gain records.
          The data structure stores the information needed for NV
          generation.

   \param aFBGAIN_Cal_NV [output] Pointer to
          QMSL_RFCAL_FBRX_GAIN_FREQ_NV . The data structure stores
          the output NV.

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager. NV items stored in NV Manager will be written
          to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
          called.
            bCachedByNVManager == 1: Store NV items
            bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_Generate_FBRX_GAIN_FREQ_NV( HANDLE hResourceContext,
         unsigned short iNvModeId,
         unsigned short iNVPath,
         unsigned short numRecords,
         unsigned char numChannels,
         void* Channel_List,
         void* aFbrx_Gain_Freq_Cal_Records,
         void* aFBGAIN_Cal_NV,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Generate Enh Sweep Calibration Consolidated Rx NV
   
   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param nvmode              [input]     Calibration NV mode, See QLib_Defines.h for nv_mode_id_type Enum Definition.  

   \param aCal_Sweep_Records  [input]     Pointer to cal_sweep_record. Structure defined in QLib_Defines.h
                                          The data structure stores the information needed for NV generation.

   \param numRecords          [input]     Number of Cal Sweep Records

   \param rxNV                [input]     Pointer to the Rx NV structure QMSL_RFNV_RX_CAL_NV . See definition of structure in QLib_Defines.h

   \param pNVgenparam         [input]     Pointer to data structure that contains information about the NV (Version, Mode ID etc).

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Generate_ESC_Consolidated_Rx_NV(HANDLE hResourceContext,    
         unsigned short nvmode,
         void* pCalSweepRecords,
         unsigned short numRecords,
         void* rxNV,
         void* pNVgenparam,
         unsigned char bCachedByNVManager);

   /******************************************************************************/
   /**
   Function to generate additional FBRxGain Cal Records for NV generation based on the Generation type. If additional records cannot generated based for this type, 
   source records will be copied to destination records

   \param destRecords     Type : void                                               [output] pointer to destination Records. 

   \param srcRecords      Type : void                                               [input] pointer to Source Records    

   \param generationControl Type: void                                                [input] Pointer to control parameters that determine
                                                                                            algorithm used for record generation.
   \return unsigned char

   \warning : Number of destination records passed as an input to the function must be atleast twice the number of source records

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Generate_FBRx_Gain_Records_For_NVGeneration(void* destRecords, void* srcRecords, void* generationControl);

   /******************************************************************************/
   /**

QLIB_RFCAL_Update_Sweep_Records_With_Path_Specific_LossOffsets

Function to generate update Rx Cal Records for NV generation with path specific Cal loss offsets / Rx Path

\param numDevices   Type : unsigned int [input] number of devices also corresponds to number of loss Offsets in loss Offsets array

\param swpRecords     Type : void * [input/output] sweep records array to be updated. Underlying data type qmsl_cal_data_records

\param deviceList     Type : unsigned short * [input] device list.

\param lossOffsetList     Type : double * [input] loss Offsets

\return unsigned char

*******************************************************************************/
QLIB_API unsigned char QLIB_RFCAL_Update_Sweep_Records_With_Path_Specific_LossOffsets(unsigned int numDevices,
                                                                                      void* swpRecords, unsigned short * deviceList, double* lossOffsetList);

/******************************************************************************/
/**
   Generate FBRX DC Calibration NV
   This function will get the list of DC values generated for each Fbrx Gain State
   during fbrx DC calibration - and will walk
   through those measurements and generate the FBRX_DC_NV item
   for the corresponding NV mode ID

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
          0 = PRx, 2= SV Path.

   \param num_Gain_States [input] .Number of WTR  Gain states for which 
          the DC values have been calculated.

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager. NV items stored in NV Manager will be written
          to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
          called.
            bCachedByNVManager == 1: Store NV items
            bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param DC_Cal_Results [input] .Pointer to FBRx DC Cal.
          The data structure stores the information needed for NV
          generation.

   \param DC_Cal_NV [output] Pointer to
          QMSL_DC_CAL_NV_RESULT . The data structure stores
          the output NV.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_Generate_FBRX_DC_NV(   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned short iNVPath,
      unsigned char num_Gain_States,
      unsigned char tech,
      unsigned char bCachedByNVManager,
      void* DC_Cal_Results,
      void* DC_Cal_NV);

   QLIB_API unsigned char QLIB_RFCAL_Generate_FBRX_DROOP_NV_V2( HANDLE hResourceContext,
                        unsigned short iNvModeId,
                        unsigned short iNVPath,
                        unsigned char bCachedByNVManager,
                        void* FBRx_Droop_Cal_Results,
                        void* FBRx_Droop_Cal_NV
                        );

    /******************************************************************************/
   /**
   Generate FBRX DC Calibration NV
   This function will get the list of DC values generated for each Fbrx Gain State
   during fbrx DC calibration - and will walk
   through those measurements and generate the FBRX_DC_NV item
   for the corresponding NV mode ID

   \param hResourceContext   Resource context that was returned from
          the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
          NV mode ID determines the set of NV items to be
          generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
          0 = PRx, 2= SV Path.

   \param num_Gain_States [input] .Number of WTR  Gain states for which 
          the DC values have been calculated.

   \param bCachedByNVManager [input]  Store generated NV items in
          NV Manager. NV items stored in NV Manager will be written
          to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
          called.
            bCachedByNVManager == 1: Store NV items
            bCachedByNVManager == 0: Do not store NV items.
          Generated NV items will not be written to mobile when
          QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param FBRx_Droop_Cal_Results [input] .Pointer to FBRx Droop Cal.
          The data structure stores the information needed for NV
          generation.

   \param FBRx_Droop_Cal_NV [output] Pointer to
          QMSL_FBRX_DROOP_CAL_NV_RESULT . The data structure stores
          the output NV.

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
            QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/

   QLIB_API unsigned char QLIB_RFCAL_Generate_FBRX_DROOP_NV(   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned short iNVPath,
      unsigned char bCachedByNVManager,
      void* FBRx_Droop_Cal_Results,
      void* FBRx_Droop_Cal_NV,
      int techBWState);


    /******************************************************************************/
   /**
   Generate TX Common Calibration NV

   \param hResourceContext   Resource context that was returned from
   the call to QLIB_ConnectServer().

   \param iNvModeID [input] Enumeration of nv_mode_id_type.   The
   NV mode ID determines the set of NV items to be
   generated.  See QLib_Defines.h for definition

   \param iNVPath [input] Path to which the NV should be written.
   0 = PRx, 2= SV Path.

   \param packetSize [input] The data variable stores the total
   size of the package.

   \param bCachedByNVManager [input]  Store generated NV items in
   NV Manager. NV items stored in NV Manager will be written
   to mobile when QLIB_RFCAL_NV_Manager_WriteToPhone() is
   called.
   bCachedByNVManager == 1: Store NV items
   bCachedByNVManager == 0: Do not store NV items.
   Generated NV items will not be written to mobile when
   QLIB_RFCAL_NV_Manager_WriteToPhone() is called.

   \param aESC_Cal_NV [output] Pointer to
   QMSL_RFCAL_ESC_Calibration_NV . The data structure stores
   the output NV.

   \param hdetNVParams [input] Has params required for HDET NV Generation
   Pointer to QMSL_RFCAL_ESC_HDET_NV_Params type

   \param hdetNVRes [output] Has results from HDET NV Generation
   Pointer to QMSL_RFCAL_ESC_HDET_NV_Results type

   \param limVsFreqNv [output] Has results from Lim Vs Freq NV Generation
   Pointer to QMSL_RFCAL_Tx_LimVsFreq_NV_Results type

   \return true if successful, false otherwise

   \warning NV items are not written to the mobile station until
   QLIB_RFCAL_NV_Manager_WriteToPhone() is called

   *******************************************************************************/
   QLIB_API unsigned char QLIB_RFCAL_Process_CommonCAL_ESC_Tx_NV(   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned short iNVPath,
      unsigned int packetSize,
      unsigned char bCachedByNVManager,
      void* aESC_Cal_NV,
      void* hdetNVParams,
      void* hdetNVRes,
      void* limVsFreqNv);

   QLIB_API unsigned char QLIB_RFCAL_Process_CommonCAL_ESC_Rx_NV(   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned short iNVPath,
      unsigned char bCachedByNVManager,
      void* aRX_DVGA_LNA_Cal_NV,
      void* aRx_NV_Channels);

   QLIB_API unsigned char QLIB_RFCAL_Process_CommonCAL_ESC_Consolidated_Rx_NV(   HANDLE hResourceContext,
      unsigned short iNvModeId,
      unsigned int packetSize,
      unsigned char bCachedByNVManager,
      void* rxNV);


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_RFCAL_NVMANAGER_H)

