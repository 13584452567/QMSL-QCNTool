/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_EventFilter.h#4 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_EventFilter
 *
 *********************************************************************
 */

#pragma once

#include "QMSL_Async_Filter.h"
#include <set>
using namespace std;

// forward declarations
class CQMSL_Async_Event;

/**
 * Filters phone log packets from the phone based on a set of allowed log codes.
 */
class CQMSL_Async_EventFilter : public CQMSL_Async_Filter
{
public:
   virtual ~CQMSL_Async_EventFilter() {}

   /**
    * Checks the content of the message to determine if it should be passed on to the associated
    * listener object.
    * Will return true if the incoming message is a log packet, and the packet's log_code is in the
    * set of allowed log codes.
    *
    * \param packetSize : the size of the packet being sent
    * \param data : the packet itself
    * \return true if message should be passed on to the associated listener object
    */
   virtual bool CheckForValidPacket
   (
      int packetSize,
      unsigned char* data
   );

   /**
    * Checks the content of the message to determine if it should be passed on to the associated
    * listener object.
    * Will return true if the incoming message is a log packet, and the packet's log_code is in the
    * set of allowed log codes.
    *
    * \param eventSize : the size of the event received
    * \param data : the event packet itself
    * \return true if message should be passed on to the associated listener object
    */
   virtual bool CheckForValidEvent
   (
      const CQMSL_Async_Event& evt
   );


   /**
    * Used for log-code filtering.
    * Adds the specified log-code to the set of allowed codes.
    *
    * \param code the log code to add to the set of allowed codes.
    */
   void AddCode( unsigned short code );

   /**
    * Used for log-code filtering.
    * Adds the specified log-codes to the set of allowed codes.
    *
    * \param code a container of unsigned shorts, each element representing an allowed code
    */
   template< class CONTAINER >
   void AddCodes( const CONTAINER& logCodes )
   {
      m_logCodes.insert( logCodes.begin(), logCodes.end() );
   }

   /**
    * Clears the set of allowed log codes.
    */
   void ClearCodes( void );

   /** virtual Copy of the filter */
   virtual CQMSL_Async_Filter* Clone() const;
private:
   set<unsigned short> m_eventCodes;
};
