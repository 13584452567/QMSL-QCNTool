/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_EventCollector.h#4 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_EventCollector
 *
 *********************************************************************
 */

#pragma once

#include "QMSL_Async_Listener.h"
#include "QMSL_Async_EventFilter.h"
#include "QMSL_Async_Event.h"

#include <list>
#include <vector>
using namespace std;

/**
 * Collects QMSL_Async_ events by implementing the listener and filter interface.
 * This class couples listening and filtering because of way events are sent from the phone:
 * events come in groups, contained in a single asynch message.  In order to efficiently filter
 * a single event in the bulk event packet from the phone, the listening and filtering should
 * be performed at the same time.
 */
class CQMSL_Async_EventCollector : public CQMSL_Async_Listener
{
public:

   CQMSL_Async_EventCollector() {}

   /**
    * Callback function notifying the listener that a new message has been received by the dispatcher that is
    * intended for this listener. Will ignore everything but event packets.  If it identifies that it's
    * acting as a filter and listener, it will assume that the filter personality already stored all
    * required events and do nothing.  If it's not acting as a filter, all events found in the event
    * report will be stored.
    *
    * \param packetSize : the size of the packet being sent
    * \param data : the packet itself
    */
   virtual void PacketReceived
   (
      int packetSize,
      unsigned char* data
   );

   /**
    * Clear the collection of events.
    */
   virtual void ClearEventPackets( void );

   /**
    * Get a vector containing the accumulated events.
    * The vector will be cleared, so after the function call
    * it will only contain events collected by this.
    *
    * \param eventPackets : in/out, will contain all gathered events
    */
   virtual void GetEventPackets( vector<CQMSL_Async_Event>& events ) const;

   /**
    * Gets the number of events accumulated so far.
    *
    * \return the number of events accumulated so far.
    */
   virtual int GetNumEventPackets( void ) const;

   virtual void SetFilter( const CQMSL_Async_Filter &filt );
   virtual bool CheckFilter( int packetSize, unsigned char* data ) const;

   /**
    * Get the most recent event received.
    * \param logPkt out param, a copy of the event most recently received
    */
   virtual void GetLastEvent( CQMSL_Async_Event& evt ) const;


   CQMSL_Async_EventCollector( const CQMSL_Async_EventCollector& copyObj );
   CQMSL_Async_EventCollector& operator=( const CQMSL_Async_EventCollector& rhs );

private:
   // store as a list so you don't get the inefficiency from all of the copies
   // caused by a vector re-allocation
   list<CQMSL_Async_Event> m_eventPackets;

   CQMSL_RefPtr<CQMSL_Async_EventFilter> m_pFilter;

   void Copy( const CQMSL_Async_EventCollector& rhs );
   void Free();
};
