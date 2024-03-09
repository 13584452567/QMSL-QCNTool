#if !defined( _QMSL_CalDataManager_Utilities_H )
#define _QMSL_CalDataManager_Utilities_H
/******************************************************************************/
/**
Program: QMSL

   $Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalDataManager_Utilities.h#2 $

\brief Contains small utility functions that are shared by different areas, but
        do not make sense to put under any specific component

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/
#include "QLIB_Defines.h"


/******************************************************************************/
/**

 CLASS  QMSL_CalDataManager_Utilities

 \brief Contains small utility functions that are shared by different areas, but
        do not make sense to put under any specific component

******************************************************************************/

class QMSL_CalDataManager_Utilities
{
public:

   /**
      \brief Add a data value to the list, based on a comma delimited string

      \param char* pStringToParse = pointer to string to be parsed
      \param double& dNextValue = storage for the next values


      \return true if an item was parsed, false if the end of the string was found and no item could be parsed

      \warning pStringToParse will be updated to point to the next value in the list
   */
   static bool ParseDouble( char*& pStringToParse, double& dNextValue);

};

#endif   // #if !defined( _QMSL_CalDataManager_Utilities_H )