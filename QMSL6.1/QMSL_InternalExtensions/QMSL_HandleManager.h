/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_HandleManager.h#4 $
 *
 *  Project : QMSL
 *
 *  Package :
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_HandleManager
 *
 *********************************************************************
<b>Version History:</b>
\verbatim
V0.01  05/26/2005  bcheadle    creation
\endverbatim
 *********************************************************************
 */

#pragma once
#include <map>
#include <string>
#include "QMSL_inc\QLib.h"
#include "QMSL_inc\QLib_Defines.h"
#include "QMSL_Defines\QMSL_Defines_nv.h"


#if FALSE // def __SUITE__HIVE__
#include "HIVE_Listener.h"
#endif

class CQMSL_HandleManager
#if FALSE // def __SUITE__HIVE__
   : public HIVE_CListener
#endif
{
public:
   static HANDLE GetPhoneHandle( unsigned short comPort = QLIB_COM_AUTO_DETECT, unsigned int s = 30000);
   static void Shutdown( void );
   static void ConfigQmslTextLogs( unsigned short logmask, const std::string filename );
   static void ClearQmslTextLogs( void );
   static void SetTransportMode(unsigned char iTransportMode);
   static void SetQMSLUserDefinedTransportDLL( const std::string filename );
   static void SetQMSLUserDefinedResourceID( const std::string resourceID );
   static void SetQMSLComPortUsed (unsigned short iComPort );
#if FALSE // def __SUITE__HIVE__
   virtual BOOL HandleEvent (HIVE_CListenerEvent &event);
#endif

   // QMSL Merge
   virtual ~CQMSL_HandleManager();

private:
   CQMSL_HandleManager();

   static CQMSL_HandleManager* m_pSelf;

   struct HANDLE_INFO
   {
      HANDLE handle;
      std::string debugLogFile;
      unsigned short debugLogMask;
   };

   std::map<unsigned short, HANDLE_INFO> m_comPortsToHandles;
   unsigned short m_lastComPort;
   static std::string	m_qmslTextLogFilename;
   static bool m_configQmslTextLogs;
   static unsigned short m_qmslTextLogMask;

   static void StartDebugLog( HANDLE_INFO& handleInfo );

   static void Initialize( unsigned char iTransportMode = 1 );

   static unsigned char m_iTransportMode;

   static HMODULE m_hQMSLUserDLL;

   static std::string m_qmslUserDefinedTransportDLL;

   static std::string m_resourceID;

   static unsigned short m_iComPortOverride;

public:
   enum
   {
      eQPhoneMS = 0,
      eQPSTMode = 1,
      eUserDefinedTransport = 2
   } QMSLConnectionEnum;


};
