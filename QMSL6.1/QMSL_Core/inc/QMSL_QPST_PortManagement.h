/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Core/inc/QMSL_QPST_PortManagement.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_QPST_PortManagement
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_QPST_PORT_MANAGEMENT_H)
#define _QMSL_QPST_PORT_MANAGEMENT_H

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
                     QPST Port Management

   The functions instruct QPST Server on how it should manage its COM port resources. All
   functions require QPST Server to be isntalled.
   *******************************************************************************/

   /******************************************************************************/
   /**
   Call QPST's COM interface to release COM port, similar to USB disconnect.
   
   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning This function requires QPST version 2.7.395.  The QMSL must run in QPST mode. 
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPST_SuspendPort ( HANDLE hResourceContext );
   
   /******************************************************************************/
   /**

   Call QPST's COM interface to set port auto repoen property 

   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \Param  [in]       bAutoPortReopen property =   // T->F, don't reopen port if device re-enumerates on USB
                                       // F->T, attempt to reopen port, reopen whenever device re-enumerates.
                  
   \return true if successful, false if fail.

   \warning This function requires QPST version 2.7.395.  The QMSL must run in QPST mode. 
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPST_SetAutoPortReopen ( HANDLE hResourceContext , unsigned char bAutoPortReopen);
   
   /******************************************************************************/
   /**
   Call QPST's COM interface to get port auto repoen property 

   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \Param  [in]       bAutoPortReopen property =   // T->F, don't reopen port if device re-enumerates on USB
                                       // F->T, attempt to reopen port, reopen whenever device re-enumerates.
                  
   \return true if successful, false if fail.

   \warning This function requires QPST version 2.7.395.  The QMSL must run in QPST mode. 
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPST_GetAutoPortReopen ( HANDLE hResourceContext , unsigned char* bAutoPortReopen);

   /******************************************************************************/
   /** Define a QPST Server Event to Trigger.  The event will be used by QLIB_QPST_WaitForEventTirgger function to 
   wait for the trigger
   

   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \Param  [in]       iQPSTServerEvent =  See QPST_Server_Event_Types in Qlib_SoftwareDownloadDefines.h
                  
   \return true if successful, false if fail.

   \warning This function requires QPST version 2.7.395.  The QMSL must run in QPST mode. 
   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPST_DefineEventTrigger(HANDLE hResourceContext, unsigned short iQPSTServerEvent);
   
   /******************************************************************************/
   /** Wait for QPST Server Event.  This function will wait for certain QPST Server event to happen.  The event is 
   defined through QLIB_QPST_DefineEvenetTrigger
   

   \Param  [in]       hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \Param  [in]       iTimeoutms =  The timeout in MS.
   \param  [in/out]   iWaitStatus = Return value of WIN32's WaitForSingleObject.  Please refer to Micrsoft documentation.                  
   \return true if successful, false if fail.

   \warning This function requires QPST version 2.7.395.  The QMSL must run in QPST mode. 
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPST_WaitForEventTrigger(HANDLE hResourceContext, unsigned long iTimeoutms, unsigned long* iWaitStatus);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_QPST_PORT_MANAGEMENT_H)
