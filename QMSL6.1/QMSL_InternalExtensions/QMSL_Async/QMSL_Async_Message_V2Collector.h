/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL6.1/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_Message_V2Collector.h#1 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_MessageCollector
 *
 *********************************************************************
 */

#pragma once

#include "QMSL_Async_Listener.h"
#include "QMSL_Async_Message.h"

#include <list>
#include <vector>
using namespace std;

/**
 * Collects phone messages (F3 messages) by implementing the listener interface.
 */
class CQMSL_Async_Message_V2Collector : public CQMSL_Async_Listener
{
public:
   /**
    * Callback function notifying the listener that a new message has been received by the dispatcher that is
    * intended for this listener. Will ignore everything but extended message packets.
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
    * Clear the collection of message packets.
    */
   virtual void ClearMessagePackets( void );

   /**
    * Get a vector containing the accumulated message packets.
    * The vector will be cleared, so after the function call
    * it will only contain packets collected by this.
    *
    * \param msgPackets : in/out, will contain all gathered log packets
    */
   virtual void GetMessagePackets( vector<CQMSL_Async_Message>& msgPackets ) const;

   /**
    * Gets the number of message packets accumulated so far.
    *
    * \return the number of message packets accumulated so far.
    */
   virtual int GetNumMessagePackets( void ) const;

   /**
    * Get the most recent message packet received.
    * \param msg out param, a copy of the message packet most recently received
    */
   virtual void GetLastMessage( CQMSL_Async_Message& msg ) const;

private:
   // store as a list so you don't get the inefficiency from all of the copies
   // caused by a vector re-allocation
   list<CQMSL_Async_Message> m_messagePackets;
};
