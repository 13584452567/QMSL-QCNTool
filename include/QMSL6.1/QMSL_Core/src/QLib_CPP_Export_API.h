/******************************************************************************/
/**
Program: QMSL

  $Id: //depot/HTE/QDART/QMSL6/src/QMSL_Core/QLib_CPP_Export_API.h#1 $

Provides access to C++ classes by exporting C++ symbols

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/

#if !defined(_QLIB_CPP_EXPORT_API_H)
#define _QLIB_CPP_EXPORT_API_H


// QLIB_EXPORT_C_PLUSPLUS indicates that the C++ classes should be exported
#if defined (QLIB_EXPORT_C_PLUSPLUS)

#ifdef QLIB_EXPORTS
#define QLIB_CPP_API __declspec(dllexport)
#else
#define QLIB_CPP_API __declspec(dllimport)
#endif

#else
#define QLIB_CPP_API

#endif



#endif // _QLIB_CPP_EXPORT_API_H
