/******************************************************************************/
/**
Program: QMSL

   $Id: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_CalDataManager_Exception.h#2 $

\brief This is the general exception class used by the drivers.

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/
#ifndef QMSL_CalDataManager_Exception_h
#define QMSL_CalDataManager_Exception_h 1

// Define the longest description string allowed
#define QMSL_CalDataManager_Exception_Max_Descr_Len  256


// Macros for exception throwing
#define QMSL_THROW( description )   { QMSL_CalDataManager_Exception* _pException = new QMSL_CalDataManager_Exception( description );   throw ( _pException ); }

// NOTE: To create a description with a variable argument list, use this format:
//
// throw( new QMSL_CalDataManager_Exception("Exception with error code %d has occured.", 1001 ) );
//


#include <windows.h>  // win32 data types
//This is the general exception class used by the drivers.

/**
     class QMSL_CalDataManager_Exception : public CException
   \brief This class inherits from CException, and it supports the basic functionality found in the CException members.


   The macro: QMSL_THROW( description ) is defined to
   reduce the amount of code needed to throw an exception.
*/
class QMSL_CalDataManager_Exception // : public CException  //## Inherits: inherits from%35E5EBC50121
{
public:

   /******************************************************************************/
   /**

   \brief Constructor with variable argument list message

   Created when an exception is thrown. A message box will be displayed with
   the error message if the auto-show flag is set.

   \return  none

   \param char* description - Exception error message.

   \warning None.

   *******************************************************************************/
   QMSL_CalDataManager_Exception (char* format, ...);

   /******************************************************************************/
   /**

   \brief Get exception description string (error message).

   \return  char* - pointer to description string.

   \param none

   \warning None.

   *******************************************************************************/
   virtual char* get_Description ();

   /******************************************************************************/
   /**

   \brief Get exception error message.

   \return  BOOL - TRUE if successful.

   \param LPTSTR lpszError, - Pointer to buffer to hold error string.
   \param UINT nMaxError, - Max size of buffer in characters.
   \param PUINT pnHelpContext - not used.

   \warning None.

   *******************************************************************************/
   virtual BOOL GetErrorMessage (LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext = NULL);

   /******************************************************************************/
   /**

   \brief Set auto-show exceptions state.

   \return  void

   \param bool autoShowExceptions - auto-show exceptions state.

   \warning None.

   *******************************************************************************/
   static void setAutoMessageShow (bool autoShowExceptions);


private:
   /******************************************************************************/
   /**

   \brief Process Exception

   \return  none

   \param char* description = NULL terminated string with description of exception

   \warning None.

   *******************************************************************************/
   void ProcessException( char* description);

   /******************************************************************************/
   /**

   \brief Standard Constructor

   \return  none

   \param none

   \warning None.

   *******************************************************************************/
   QMSL_CalDataManager_Exception ();

   //! Static flag to indicate whether exception messages are shown automatically
   static bool _autoShowExceptions;

   // Buffer to hold description
   char _descriptionBuffer[ QMSL_CalDataManager_Exception_Max_Descr_Len ];
};

#endif
