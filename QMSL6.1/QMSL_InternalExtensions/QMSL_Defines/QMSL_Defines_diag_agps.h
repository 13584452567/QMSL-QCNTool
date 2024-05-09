/******************************************************************************/
/**
Program: QMSL

	$Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief
	Basic types for Ineral Extensions

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/
#pragma once

#include "QMSL_Defines_basic_types.h"

#pragma pack(push, 1)
#define PACKED

#define C_LSM_START_DWELL_MAX_CFMODE		21
#define C_LSM_START_DWELL_MAX_SUB_MSEC		( 1023L << 8 )
#define C_LSM_START_DWELL_RESERVED_BYTES	8

#define C_LSM_SET_TEST_MODE_CMD_CODE 7
#define C_LSM_MODE_SETTING_PASSWORD 0xDEA5
#define C_LSM_START_PRESCIBED_DWELL_CMD_CODE 8
#define C_LSM_START_PRESCIBED_DWELL_CMD_CODE_2 9

/* struct definition for start dwell */
PACKED struct lsm_tapi_start_dwell_type
{
   U8	u_Flags;
   U8	u_Chan;
   U8	u_SvId;
   U8	u_CfMode;
   U8	u_PreDetN;
   U8	u_PreDetBitN;
   U8	u_LogCohSums;
   U8	u_ResyncTsBc;
   U16	w_PostDetN;
   U16	w_CohLogSource;
   U16	w_SubChanFreq;
   S32	l_RangeRate;
   U32	q_SubMsec;
   U32	q_NumDwells;
   U32 q_ResultsInterval;
   U16	w_SnrThresh;
   U16	w_InterChanFreq;
   U8	u_StopSvId;
   U8	u_Reserved[C_LSM_START_DWELL_RESERVED_BYTES];
};

PACKED struct hack_lsm_tapi_start_dwell_type
{
   unsigned short	u_Flags;
   unsigned short	u_Chan;
   unsigned short	u_SvId;
   unsigned short	u_CfMode;
   unsigned short	u_PreDetN;
   unsigned short	u_PreDetBitN;
   unsigned short	u_LogCohSums;
   unsigned short	u_ResyncTsBc;
   unsigned short	w_PostDetN;
   unsigned short	w_CohLogSource;
   unsigned short	w_SubChanFreq;
   long			l_RangeRate;
   unsigned long	q_SubMsec;
   unsigned long	q_NumDwells;
   unsigned long q_ResultsInterval;
   unsigned short	w_SnrThresh;
   unsigned short	w_InterChanFreq;
   unsigned short	u_StopSvId;
};

PACKED struct hack_lsm_tapi_time_tag_req_type
{
   unsigned short	u_TimeSystem;
   unsigned short	u_Flags;
   unsigned short	w_TagInterval;
};


/* enums for start dwell result type */
enum
{
   LSM_START_DWELL_REQ_PASS,
   LSM_START_DWELL_REQ_FAIL_LSM_TEST_MODE,
   LSM_START_DWELL_REQ_FAIL_PKT_LENGTH,
   LSM_START_DWELL_REQ_FAIL_CHAN,
   LSM_START_DWELL_REQ_FAIL_SVID,
   LSM_START_DWELL_REQ_FAIL_CFMODE,
   LSM_START_DWELL_REQ_FAIL_PRE_DET_N,
   LSM_START_DWELL_REQ_FAIL_PRE_DET_BIT_N,
   LSM_START_DWELL_REQ_FAIL_POST_DET_N,
   LSM_START_DWELL_REQ_FAIL_COH_LOG_SOURCE,
   LSM_START_DWELL_REQ_FAIL_SUB_MSEC,
   LSM_START_DWELL_REQ_FAIL_STOP_SVID,
   LSM_START_DWELL_REQ_FAIL_OTHER = 255
};


#define C_LSM_TIME_TAG_REQ_RESERVED_BYTES	4

/* bit definitions for time systems available */
#define	C_LSM_TIME_TAG_REQ_SYSTEM_GSM		0x01
#define	C_LSM_TIME_TAG_REQ_SYSTEM_UMTS		0x02

#define	C_LSM_TIME_TAG_REQ_SYSTEM_ALL	\
			( C_LSM_TIME_TAG_REQ_SYSTEM_GSM | C_LSM_TIME_TAG_REQ_SYSTEM_UMTS )

/* struct definition for time tag request */
PACKED struct lsm_tapi_time_tag_req_type
{
   U8	u_TimeSystem;
   U8	u_Flags;
   U16	w_TagInterval;
   U8	u_Reserved[ C_LSM_TIME_TAG_REQ_RESERVED_BYTES ];
};


/* enums for time tag result type */
enum
{
   LSM_TIME_TAG_REQ_PASS,
   LSM_TIME_TAG_REQ_FAIL_LSM_TEST_MODE,
   LSM_TIME_TAG_REQ_FAIL_PKT_LENGTH,
   LSM_TIME_TAG_REQ_FAIL_PENDING,
   LSM_TIME_TAG_REQ_FAIL_NO_SYSTEM_SPECIFIED,
   LSM_TIME_TAG_REQ_FAIL_OTHER =255
};




typedef enum
{

   LSM_PT_FFT_WIDE_BAND_ONLY,  /* 0 - Spectral Analysis test in Wide band */
   LSM_PT_FFT_WIDE_AND_NARROW  /* 1 - Spectral Analysis test in Wide
                                        Band and Narrow Band */
} lsm_pt_bandwidth_enum_type;

typedef enum
{

   LSM_PT_SAMPLING_FREQ_1MHz,  /* 0 - I/Q Capture Sampling frequency 1MHz */
   LSM_PT_SAMPLING_FREQ_2KHz   /* 1 - I/Q Capture Sampling frequency 2KHz */

} lsm_pt_sampling_freq_enum_type;

typedef enum
{

   LSM_PT_RECORD_SIZE_4096     /* 0 - I/Q Capture Record Size 4096 samples */

} lsm_pt_record_size_enum_type;


/* Enumerations for LSM test ID */
typedef enum
{

   LSM_PT_TEST_ID_PEEK_TEST,       /* 0 - LSM Peek test */
   LSM_PT_TEST_ID_POKE_TEST,       /* 1 - LSM Poke test */
   LSM_PT_TEST_ID_SELF_TEST,        /* 2 - LSM self test */
   LSM_PT_TEST_ID_STANDALONE_TEST, /* 3 - LSM Standalone test */
   LSM_PT_TEST_ID_SINGLE_CH_TEST,  /* 4 - LSM Single Channel test */
   LSM_PT_TEST_ID_FFT_TEST,        /* 5 - LSM Spectral Analysis test */
   LSM_PT_TEST_ID_IQ_CAPTURE,      /* 6 - LSM IQ sample capture test */
   LSM_PT_TEST_ID_DOWNLOAD_CODE,   /* 7 - LSM test code download */
   LSM_LT_TEST_ID_DWELL_TEST,      /* 8 - LSM dwell tes */
   LSM_PT_TEST_ID_NUM_TESTS        /* Enumeration for number of tests */

} lsm_pt_test_id_enum_type;


/* enum for the various dwell id types */
enum
{

   LSM_LT_DWELL_ID_STATS,          /* 0 - Dwell statistic results */
   LSM_LT_DWELL_ID_PEAK,           /* 1 - Dwell peak results */
   LSM_LT_DWELL_ID_INCOH_SUMS,     /* 2 - Dwell incoherent sums results */
   LSM_LT_DWELL_ID_COH_SUMS,       /* 3 - Dwell coherent sums results */
   LSM_LT_DWELL_ID_PEAK_PROF,      /* 4 - Dwell peak profile results */
   LSM_LT_DWELL_ID_NUM_RESULTS	  /* Enumeration for number of dwell results */

};


#define C_LSM_LT_DWELL_STATS_RESERVED 4

/* Structure for returning dwell statistic results */
PACKED struct lsm_lt_dwell_stats_type
{
   uint8      u_dwell_id;
   uint8      u_Reserved1;
   uint32     q_NumDwellsRequested;
   uint32     q_NumDwellsCompleted;
   uint32     q_NumDwellSuccesses;
   uint32     q_fcount;
   uint8      u_Reserved2[ C_LSM_LT_DWELL_STATS_RESERVED ];
};


#define C_LSM_LT_DWELL_PEAK_RESERVED 4
/* Structure for returning dwell peak results */
PACKED struct lsm_lt_dwell_peak_type
{
   uint8      u_dwell_id;
   uint8      u_Reserved1[3];
   uint8      u_Chan;
   uint8      u_SvId;
   uint8      u_DwellTag;
   uint8      u_CfMode;
   uint8      u_PreDetN;
   uint8      u_PreDetBitN;
   uint8      u_DwellFlags;
   sint7      b_BitEdgeDelta;
   uint16     w_PostDetTotal;
   uint16     w_AsProduct;
   uint16     w_PeakIndex;
   sint15     x_SubChanFreq;
   uint32     q_FCount;
   sint31     l_RangeRate;
   uint32     q_HwSubMsec;
   uint32     q_DataBits0;
   uint32     q_DataBits1;
   uint32     q_LowSnrs0;
   uint32     q_LowSnrs1;
   sint31     l_FreqEst;
   uint8      u_Reserved2;
   uint8      u_PeakFreqBin;
   uint8      u_LeftHumpOffset;
   uint8      u_RootWidth;
   uint16     w_ValidFlags;
   uint16     w_SubChanPeakIndex;
   sint15     x_Offset;
   uint16     w_Width;
   uint16     w_SnrDb;
   uint16     w_CnoDb;
   sint15     x_FreqInterp;
   uint16     w_Peak;
   uint16     w_Mean;
   uint16     w_Sym;
   sint31     l_SvSpeed;
   uint16     w_SvSpeedUnc;
   uint32     q_PeakSubMsec;
   uint16     w_CfWindowF;
   uint16     w_CfWindowT;
   uint8      u_Reserved3[ C_LSM_LT_DWELL_PEAK_RESERVED ];
};

/* Structure for returning dwell stat detection results */
PACKED struct lsm_lt_dwell_stat_detect_type
{
   uint8      u_dwell_id;
   uint8      u_SvId;
   uint8      u_Chan;
   uint8      u_Reserved1;
   uint16     w_PeakIndex;
   uint16     w_SnrDb;
   uint16     w_CnoDb;
   uint16     w_ValidFlags;
   uint32     q_FCount;
   uint32     q_Reserved2;
   uint32     q_Reserved3;
};


/* Structure for returning dwell incoherent sums results */
PACKED struct  lsm_lt_dwell_incoh_sums_type
{

   uint8      u_dwell_id;
   /* more stuff goes here */

};


/* Structure for returning dwell coherent sums results */
PACKED struct lsm_lt_dwell_coh_sums_type
{

   uint8      u_dwell_id;
   /* more stuff goes here */

};


/* Structure for returning dwell peak profile results */
PACKED struct lsm_lt_dwell_peak_prof_type
{

   uint8      u_dwell_id;
   /* more stuff goes here */

};


PACKED union lsm_lt_dwell_sub_result_type
{

   uint8                         u_dwell_id;
   lsm_lt_dwell_stats_type       z_dwell_stats;
   lsm_lt_dwell_peak_type        z_dwell_peak;
   lsm_lt_dwell_incoh_sums_type  z_dwell_incoh_sums;
   lsm_lt_dwell_coh_sums_type    z_dwell_coh_sums;
   lsm_lt_dwell_peak_prof_type   z_dwell_peak_prof;

};


/* Structure for returning LSM prescribed dwell results */
struct lsm_lt_dwell_result_type
{

   lsm_pt_test_id_enum_type      u_test_id;     /* =LSM_LT_TEST_ID_DWELL_TEST */
   lsm_lt_dwell_sub_result_type  z_dwell_sub_result;

};



union lsm_pt_result_type
{

   lsm_pt_test_id_enum_type      u_test_id;
   /* Test ID */
   uint32                        q_result_buf[8193];
   /* Buffer large enough to hold I/Q samples */
#if 0
   lsm_pt_peek_result_type       z_peek_result;
   /* Results from Peek test */
   lsm_pt_self_test_result_type  z_self_test_result;
   /* Results from Self Test */
   lsm_pt_fft_result_type        z_fft_test_result;
   /* Results from Spectral Analysis*/
   lsm_pt_iq_result_type         z_iq_capture_result;
   /* Results from I/Q capture test */
#endif
   lsm_lt_dwell_result_type      z_dwell_result;
   /* Results from dwell test */

};


typedef void (*lsm_pt_result_cb_type)(lsm_pt_result_type *p_test_result);


/* Structures needed for Time_tagging functions */
struct lsm_gsm_bs_type
{
   uint8  u_bsic;
   uint16 w_arfcn;
   uint8  u_tn;
   uint32 q_fn_lag;
   sint15 x_bit_lag;

};

struct lsm_gsm_ncell_db_type
{
   uint8  u_valid;
   uint8  u_num_cells;
   lsm_gsm_bs_type z_ncells[7]; /* Six Neighboring cells + Serving Cell */

};


#pragma pack(pop)
