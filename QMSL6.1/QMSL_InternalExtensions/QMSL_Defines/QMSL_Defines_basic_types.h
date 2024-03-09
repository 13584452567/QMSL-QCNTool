/******************************************************************************/
/**
Program: QMSL

	$Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief
	Basic types for Internal Extensions

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/

#pragma once

// $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Defines/QMSL_Defines_basic_types.h#3 $
// this file should hold just basic typedefs like qword, uint, etc.

#include "QMSL_inc\QLIB_Defines.h"

typedef		unsigned __int64	qword;
typedef		unsigned char		uint1;        /* Unsigned 8  bit value type. */
typedef		unsigned short		uint2;        /* Unsigned 16 bit value type. */
typedef		unsigned long		uint4;        /* Unsigned 32 bit value type. */

typedef		signed char			int1;         /* Signed 8  bit value type. */
typedef		signed short		int2;         /* Signed 16 bit value type. */
typedef		long int			int4;         /* Signed 32 bit value type. */

typedef		signed long			sint31;       /* Signed 32 bit value */
typedef		signed short		sint15;       /* Signed 16 bit value */
typedef		signed char			sint7;        /* Signed 8  bit value */

typedef		unsigned __int64	uint64;      /* Unsigned 32 bit value */
typedef		unsigned long int	uint32;      /* Unsigned 32 bit value */
typedef		unsigned short		uint16;      /* Unsigned 16 bit value */
typedef		unsigned char		uint8;       /* Unsigned 8  bit value */

typedef		signed long int		int32;       /* Signed 32 bit value */
typedef		signed short		int16;       /* Signed 16 bit value */
typedef		signed char			int8;        /* Signed 8  bit value */

typedef		unsigned char		U8;
typedef		unsigned short		U16;
typedef		unsigned long		U32;
typedef		unsigned __int64    U64;

typedef		char				S8;
typedef		short				S16;
typedef		long				S32;
typedef		__int64             S64;


typedef unsigned long QWord[ 2 ];