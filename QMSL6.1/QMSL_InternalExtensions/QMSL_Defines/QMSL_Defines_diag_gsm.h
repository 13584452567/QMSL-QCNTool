/******************************************************************************/
/**
Program: QMSL

	$Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief
	GSM Diag defintions

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/
#include "QMSL_Defines_basic_types.h"
#include "QMSL_InternalExtensions\QMSL_Async\QMSL_Async_LogPacket.h"
#include <vector>
using namespace std;

#define RFGSM_MAX_TX_SLOTS_PER_FRAME   5

#pragma pack(1)
struct l1_log_burst_metrics_T
{
   unsigned __int32    FN;
   WORD                arfcn : 12;
   unsigned __int32    rssi;
   __int16             pwr_dBm_x16;
   __int16             dc_offset_i;
   __int16             dc_offset_q;
   __int16             freq_offset;
   __int16             timing_offset;
   __int16             snr;
   BYTE                gain_state;
};

struct l1_gsm_dsds_enhanced_message_metrics_T
{
    byte                    subID;
    uint32                  FN;
    byte                    chan;
    /* MESSAGE METRICS */
    uint16                  rx_qual;
    byte                    status;    /* SID:bit3,4/CRC:bit2/FireCode:bit1/BFI:bit0 */
    uint16                  msg_len;
    uint16                  rx_qual_s;
    /* New for AMR */
    uint8                   codec_mode;
    uint16                  amr_status;
    uint8                   norm_c_over_i;
    uint8                   dl_acs;
    uint8                   ul_acs;
    /* FEATURE_GSM_AMR */
    uint8                   r_facch_storage_status;
    uint8                   r_facch_recomb_status;
};

struct gsm_dsds_l1_burst_metrics_T
{
   BYTE   subID;
   BYTE   channel;
   unsigned __int32    FN;
   WORD                arfcn;
   unsigned __int32    rssi;
   __int16             pwr_dBm_x16;
   __int16             dc_offset_i;
   __int16             dc_offset_q;
   __int16             freq_offset;
   __int16             timing_offset;
   __int16             snr;
   BYTE                gain_state;
};

struct gprs_dsds_l1_burst_metrics_a_T
{
   BYTE   subID;
   BYTE   channel;
   unsigned __int32    FN;
   BYTE   Tn;
   WORD                arfcn;
   unsigned __int32    rssi;
   __int16             pwr_dBm_x16;
   __int16             dc_offset_i;
   __int16             dc_offset_q;
   __int16             freq_offset;
   __int16             timing_offset;
   BYTE                Usf;
   __int16             snr;
   BYTE                gain_state;
   BYTE                mod;
   BYTE                filter;
   __int16             AciPwrN200;
   __int16             AciPwr0;
   __int16             AciPwrP200;
};

struct l1_gprs_log_burst_metrics_T
{
   BYTE				channel;
   unsigned __int32    FN;
   BYTE				TN;
   WORD                arfcn;
   unsigned __int32    rssi;
   __int16             pwr_dBm_x16;
   __int16             dc_offset_i;
   __int16             dc_offset_q;
   __int16             freq_offset;
   __int16             timing_offset;
   BYTE				usf;
   __int16             snr;
   BYTE                gain_state;
};

struct l1_gsm_log_monitor_metrics_record
{
   unsigned __int32    FN;
   unsigned __int16	arfcn;
   __int16				power_x16;
   unsigned __int32    rssi;
   BYTE				gainRange;
};


struct ftm_gsm_log_thermistor_data_type
{
   short	logID;
   short	therm_scaled_adc;
   short	bin_index;
   short	remainder_adc;
   short	comp_due_to_therm;
   short	vbatt_adc;
   short	backoff_due_to_vbatt;
};

class l1_gsm_log_monitor_metrics
{
public:
   explicit l1_gsm_log_monitor_metrics( const CQMSL_Async_LogPacket& packet )
   {
      numRecs = packet.GetDWORD( 0 );
      unsigned short offset = 4;
      for( unsigned int i=0; i<numRecs; ++i )
      {
         l1_gsm_log_monitor_metrics_record temp;
         packet.GetItem( temp, offset );
         temp.arfcn &= 0xFFF;
         records.push_back( temp );
         offset += sizeof(temp);
      }
   }

   unsigned __int32 numRecs;
   vector<l1_gsm_log_monitor_metrics_record> records;
};

struct gsm_status_type
{
   /* International Mobile Equipment ID */
   unsigned __int8 imei[9];
   /* International Mobile Subscriber ID */
   unsigned __int8 imsi[9];
   /* Location Area ID */
   unsigned __int8 lai[5];
   /* Cell ID */
   unsigned __int16 cell_id;
   /* Call Manager Overall Call State */
   unsigned __int8 call_state;
   /* Call Manager Operating Mode */
   unsigned __int8 operating_mode;
   /* Call Manager System Mode */
   unsigned __int8 system_mode;

};

//modulationType
enum modulationType:
unsigned __int8
{
   RF_MOD_GMSK,
   RF_MOD_8PSK,
   RF_MOD_UNKNOWN,
   RF_MAX_MOD_TYPE
};

//gsm band type
enum rfcom_gsm_band_type:
unsigned __int8
{
   RFCOM_BAND_GSM850,
   RFCOM_BAND_GSM900,
   RFCOM_BAND_GSM1800,
   RFCOM_BAND_GSM1900,
   RFCOM_NUM_GSM_BANDS
};

//Information sent in each slot
struct txSlotLogType
{
   unsigned __int16 powerIndex;
   __int32 powerIndbm;
   __int32 txPwrOffset;
   boolean preDistFlag;
   unsigned __int16 paScale;
   unsigned __int16 envGain;
   unsigned __int8 paRange;
   unsigned __int16 rgi;
   modulationType modType;
};

//Enhanced Tx Slot Type
struct txSlotLogTypeEnh
{
   unsigned __int16 powerIndex;
   __int32 powerIndbm;
   __int32 txPwrOffset;
   boolean preDistFlag;
   unsigned __int16 paScale;
   unsigned __int16 envGain;
   unsigned __int8 paRange;
   unsigned __int16 rgi;
   modulationType modType;
   __int16 coexBackoff;
   unsigned __int32 icqBias;
   unsigned __int16 smpsBias;
};

//FTM Log packet structure
struct txLogType
{
   unsigned __int32 frameNum;
   rfcom_gsm_band_type txBand;
   unsigned __int16 txChan;
   boolean logFlag;
   __int16 delayValue;
   __int32 freqError;
   unsigned __int8 numSlots;
   __int32 sarState;
   unsigned __int16 vBattmv;
   unsigned __int16 thermRead;
   unsigned __int8 tempCompIndex;
   __int32 tempCompBackoff;
   txSlotLogType txSlotLog[RFGSM_MAX_TX_SLOTS_PER_FRAME];
};

//FTM Enhanced Log Packet structure
struct txLogTypeEnh
{
   unsigned __int8 verNum;
   unsigned __int32 frameNum;
   rfcom_gsm_band_type txBand;
   unsigned __int16 txChan;
   boolean logFlag;
   __int16 delayValue;
   __int32 freqError;
   unsigned __int8 numSlots;
   __int32 sarState;
    unsigned __int16 vBattmv;
   unsigned __int16 thermRead;
   unsigned __int8 tempCompIndex;
   __int32 tempCompBackoff;
   __int16 tempRemainder;
   txSlotLogTypeEnh txSlotLog[RFGSM_MAX_TX_SLOTS_PER_FRAME];
};
#pragma pack()
