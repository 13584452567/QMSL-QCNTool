/*!
*********************************************************************
*  $Id: //depot/HTE/QDART/QMSL/BandHelper/bandhelper.h#6 $
*
*  Project : QMSL
*
*  Package : Managers / Call info / Band Helper
*
*  Company : Qualcomm Technologies Incorporated
*
*  Purpose : Declaration of band helper object
*
*********************************************************************
*/

#if !defined(BANDHELPER_H_INCLUDED)
#define BANDHELPER_H_INCLUDED

// Compiler working,
// 'CBandHelper::m_validChannelMap' : class 'std::map<_Kty,_Ty>' needs to have
//      dll-interface to be used by clients of class 'CBandHelper'
#pragma warning(disable:4251)

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if _MSC_VER < 1310 // MSVS2003
typedef signed __int64 INT64;
typedef unsigned __int64 UINT64;
#else
typedef signed long long INT64;
typedef unsigned long long UINT64;
#endif

#include "QMSL_Core\Exception\QMSL_Exception.h"
#include "QMSL_Core\STL\QMSL_STL_Include.h"
#include "QMSL_Core\src\QLib_CPP_Export_API.h"
#include "QMSL_inc\QLib.h"
#include "QMSL_inc\Qlib_Defines.h"

typedef enum
{
   STD_TYPE_CDMA,
   STD_TYPE_WCDMA,
   STD_TYPE_GSM,
   STD_TYPE_EDGE,
   STD_TYPE_ANALOG,
   STD_TYPE_HDR,
   STD_TYPE_TDSCDMA,
   STD_TYPE_MAX = 0xFFFFFFFF
} STD_TYPE;


enum TECHNOLOGY_FAMILY_TYPE
{
   TECHNOLOGY_CDMA,
   TECHNOLOGY_WCDMA,
   TECHNOLOGY_GSM,
   TECHNOLOGY_BLUETOOTH,
   TECHNOLOGY_MEDIAFLO,
   TECHNOLOGY_DVBH,
   TECHNOLOGY_ANALOG,
   TECHNOLOGY_GPS,
   TECHNOLOGY_ISDBT,
   TECHNOLOGY_1xEVDO,
   TECHNOLOGY_LTE,
   TECHNOLOGY_TDSCDMA,
   TECHNOLOGY_WLAN,
   TECHNOLOGY_NFC,
   TECHNOLOGY_MULTIMEDIA,
   TECHNOLOGY_FM_RADIO,
   //IF ADDING MORE ENUMS, ALSO ADD AN ENTRY IN TechnologyTypeToName METHOD
   TECHNOLOGY_TYPE_MAX = 0xFFFFFFFF
};

typedef struct
{
   double NDL_Offset;
   double NUL_Offset;
   double DL_FreqLow;
   double UL_FreqLow;

} EARFCN_params;

/*!
CLASS

responsible for defining the channels supported by a band
*/
class CChannelDefinition
{
public:
   CChannelDefinition( void );
   virtual ~CChannelDefinition() {}
   void AddChannelBoundaries( long lowChannel, long highChannel );
   void AddAdditionalChannel( long channel );
   void Clear( void );
   void ToString( string& theString );
   bool IsChannelValid( long channel );

private:
   vector< pair< long, long> > m_channelBoundaries;
   vector< long > m_additionalChannels;
};


/*!
CLASS

Defines the operations necessary to support channel to frequency conversions
for various technologies
*/

class QLIB_CPP_API CBandHelper
{
protected:
   //! Constructor for the CBandHelper class
   CBandHelper();

public:
   //! Destructor for the CBandHelper class
   virtual ~CBandHelper() {}

   /**
   * Calculates the downlink frequency of the band/channel.
   * Throws an exception if the band is invalid.
   *
   * \param band : identifies the band.
   * \param channel : identifies the channel.
   * \param skipChannelValidity : determines whether the function will check the channel for validity
   * \                             before calculating the frequency. If set to true the function will
   * \							    perform the frequency calculation regardless of the channel validity.
   * \								If set to false then the channel is checked for validity and -999 is
   * \								returned if found to be invalid.
   * \return frequency : returns the calculated frequency of the band/channel.
   */
   static double CalculateDLFrequency( BAND_CLASS_ENUM band, long channel, bool skipChannelValidity = true );
   /**
   * Calculates the uplink frequency of the band/channel.
   * Throws an exception if the band is invalid.
   *
   * \param band : identifies the band.
   * \param channel : identifies the channel.
   * \param skipChannelValidity : determines whether the function will check the channel for validity
   * \                             before calculating the frequency. If set to true the function will
   * \							    perform the frequency calculation regardless of the channel validity.
   * \								If set to false then the channel is checked for validity and -999 is
   * \								returned if found to be invalid.
   * \return frequency : returns the calculated frequency of the band/channel.
   */
   static double CalculateULFrequency( BAND_CLASS_ENUM band, long channel, bool skipChannelValidity  = true );
   static bool   IsValidChannel( BAND_CLASS_ENUM band, long channel );
   static bool   IsValidULChannel( BAND_CLASS_ENUM band, long channel );
   static bool   IsValidDLChannel( BAND_CLASS_ENUM band, long channel );
   static bool   GetMinMaxChannel( const BAND_CLASS_ENUM bandType, const LINK_TYPE uldl, unsigned long& min_channel, unsigned long& max_channel );
   static string BandTypeToBandName(const BAND_CLASS_ENUM bandType);
   static BAND_CLASS_ENUM BandNameToType(  const string& band, const TECHNOLOGY_FAMILY_TYPE tech );
   static FTM_RF_Mode_Enum BandTypeToRFMode(const BAND_CLASS_ENUM bandType);
   static BAND_CLASS_ENUM RFModeToBandType(const FTM_RF_Mode_Enum rfMode);
   static string TechnologyTypeToName(const TECHNOLOGY_FAMILY_TYPE technology);
   static int RFModeToBandNumber(const FTM_RF_Mode_Enum rfMode);
   static long AddFrequencyToULChannel(FTM_RF_Mode_Enum rfMode, long channel, double offsetMhz);

   /* Determine if the NV Mode match with the RF Mode*/
   static bool NVModeMatchRFMode(const FTM_RF_Mode_Enum rf_mode, const nv_mode_id_type nv_mode);

   //! returns the uplink channel corresponding to the given downlink channel
   static long CalculateULChan( BAND_CLASS_ENUM band, long dlChan );
   //! returns the downlink channel corresponding to the given uplink channel
   static long CalculateDLChan( BAND_CLASS_ENUM band, long ulChan );

   //! gets a comma delimited list of uplink channels for the specified band
   static void GetULChannels( BAND_CLASS_ENUM band, string& theString );
   //! gets a comma delimited list of downlink channels for the specified band
   static void GetDLChannels( BAND_CLASS_ENUM band, string& theString );

   static double GetTurnaroundConstant( BAND_CLASS_ENUM band );

   static int GetRxTxChanSep( BAND_CLASS_ENUM band );

   static short GetGSMRFComBandFromEnumBand( BAND_CLASS_ENUM band );
   static short GetWCDMARFComBandFromEnumBand( BAND_CLASS_ENUM band );

   static TECHNOLOGY_FAMILY_TYPE GetTechnologyFamily( BAND_CLASS_ENUM band );
   static TECHNOLOGY_FAMILY_TYPE GetTechnologyFamily( FTM_RF_Mode_Enum rfMode );
   static bool IsTDDMode(BAND_CLASS_ENUM band );
   static bool IsTDDMode(FTM_RF_Mode_Enum rfMode );
     
   //! converts from technology enum to mode id enum
    static short GetTxModeID(short tech);

   /**
    * Converts a frequency in Hz to the respective channel number for the given technology standard
    *
    * @param channel The channel number resolved from the frequency conversion.
    * @param tech The technology that is utilizing the conversion.
    * @param freqHz The frequency in Hz to be converted.
    * @param band <optional> Band specifier for the specific technology.
    * @param isUplink <optional> Some technologies differentiate conversion algroithms between the
    *    the uplink and downlink;  TRUE if conversion if for an uplink, else FALSE.  Default: TRUE
    *
    * @return bool If no channel could be resolved the return will be FALSE, else TRUE.
    */
   static bool FrequencyToChannel( long & channel, TECHNOLOGY_FAMILY_TYPE tech,
                                   const INT64 & freqHz, BAND_CLASS_ENUM band = END_OF_BH_BAND_CLASS_ENUM,
                                   bool isUplink = true );
   static BAND_CLASS_ENUM GetLTEBandFromChannel( long channel );

   static std::string GetBandNamefromNVMode(const nv_mode_id_type nv_mode);

private:
   static double WCDMA_CalculateFrequency( BAND_CLASS_ENUM band, long channel, bool uplink );
   static int WCDMA_GetRxTxChanSep( BAND_CLASS_ENUM band );
   static double WCDMA_GetRxTxFreqSep( BAND_CLASS_ENUM band );

   static double  LTE_CalculateFrequency( BAND_CLASS_ENUM band, long channel, bool uplink );
   static int     LTE_GetRxTxChanSep( BAND_CLASS_ENUM band );
   static double  LTE_GetRxTxFreqSep( BAND_CLASS_ENUM band );
   static EARFCN_params LTE_GetEARFCN_Parameters(BAND_CLASS_ENUM band);
   static int GetWLANChanFreqMhz(unsigned int chanID);

   static void BuildChannelMaps( void );
   typedef map< BAND_CLASS_ENUM, vector< pair< long, long> > > BAND_TO_MINMAX_VECTOR_MAP;

   BAND_TO_MINMAX_VECTOR_MAP m_validChannelMap;
   BAND_TO_MINMAX_VECTOR_MAP m_validTXLevMap;

   // NEW Band to Channel Maps
   typedef map< BAND_CLASS_ENUM, CChannelDefinition > BAND_TO_CHANNEL_DEFINITION_MAP;
   BAND_TO_CHANNEL_DEFINITION_MAP m_validULChannelMap;
   BAND_TO_CHANNEL_DEFINITION_MAP m_validDLChannelMap;

   bool m_mapsBuilt;

   //! a pointer to self to allow static functions to call non-static functions on the singleton instance.
   static CBandHelper* m_pSelf;
};

#endif // GSMCALLINFO_H_INCLUDED
