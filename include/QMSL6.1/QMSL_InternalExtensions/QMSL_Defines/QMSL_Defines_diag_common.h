/******************************************************************************/
/**
Program: QMSL

	$Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief
	This file holds special defines for diag communication that don't appear in:
   log_codes.h
   log_codes_wcdma.h
   log_codes_umts.h
   log_codes_gsm.h
   nv_items.h

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/
#pragma once


#include "QLib_Defines.h"
#include "QMSL_Defines_basic_types.h"

#define VERNO_DATE_STRLEN 11
#define VERNO_TIME_STRLEN  8
#define VERNO_DIR_STRLEN   8

#pragma pack(push, 1)
#define PACKED

struct diag_verno_rsp_type
{
   BYTE cmd_code;												/* Command code               */
   char comp_date[ VERNO_DATE_STRLEN ];			/* Compile date Jun 11 1991   */
   char comp_time[ VERNO_TIME_STRLEN ];        /* Compile time hh:mm:ss      */
   char rel_date [ VERNO_DATE_STRLEN ];				/* Release date               */
   char rel_time [ VERNO_TIME_STRLEN ];			/* Release time               */
   char ver_dir  [ VERNO_DIR_STRLEN ];         /* Version directory          */
   BYTE scm;                                   /* Station Class Mark         */
   BYTE mob_cai_rev;                           /* CAI rev                    */
   BYTE mob_model;                             /* Mobile Model               */
   WORD mob_firm_rev;                          /* Firmware Rev               */
   BYTE slot_cycle_index;                      /* Slot Cycle Index           */
   BYTE hw_maj_ver;                            /* Hardware Version MSB       */
   BYTE hw_min_ver;                            /* Hardware Version LSB       */

   bool operator<( const diag_verno_rsp_type& rhs ) const
   {
      return cmd_code<rhs.cmd_code;
   }

   bool operator>( const diag_verno_rsp_type& rhs ) const
   {
      return cmd_code>rhs.cmd_code;
   }

   bool operator<=( const diag_verno_rsp_type& rhs ) const
   {
      return cmd_code<=rhs.cmd_code;
   }

   bool operator>=( const diag_verno_rsp_type& rhs ) const
   {
      return cmd_code>=rhs.cmd_code;
   }

   bool operator!=( const diag_verno_rsp_type& rhs ) const
   {
      return ( cmd_code != rhs.cmd_code &&
               comp_date != rhs.comp_date &&
               comp_time != rhs.comp_time &&
               rel_date != rhs.rel_date &&
               rel_time != rhs.rel_time &&
               ver_dir != rhs.ver_dir &&
               scm != rhs.scm &&
               mob_cai_rev != rhs.mob_cai_rev &&
               mob_model != rhs.mob_model &&
               mob_firm_rev != rhs.mob_firm_rev &&
               slot_cycle_index != rhs.slot_cycle_index &&
               hw_maj_ver != rhs.hw_maj_ver &&
               hw_min_ver != rhs.hw_min_ver
             );
   }

   bool operator==( const diag_verno_rsp_type& rhs ) const
   {
      return ( cmd_code == rhs.cmd_code &&
               comp_date == rhs.comp_date &&
               comp_time == rhs.comp_time &&
               rel_date == rhs.rel_date &&
               rel_time == rhs.rel_time &&
               ver_dir == rhs.ver_dir &&
               scm == rhs.scm &&
               mob_cai_rev == rhs.mob_cai_rev &&
               mob_model == rhs.mob_model &&
               mob_firm_rev == rhs.mob_firm_rev &&
               slot_cycle_index == rhs.slot_cycle_index &&
               hw_maj_ver == rhs.hw_maj_ver &&
               hw_min_ver == rhs.hw_min_ver
             );
   }
};
struct diag_ext_verno_rsp_type
{
   BYTE cmd_code;			// command code = 124
   BYTE reserved[3];		// reserved
   DWORD msm_hw_ver;		// MSM hardware verion
   DWORD mob_model;		// mobile model number
   string mob_sw_rev;		// mobile software revision string
   string model_str;		// mobile model string
};


#pragma pack(pop)