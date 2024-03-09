/*!
*********************************************************************
*  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_LogCollector.h#4 $
*
*  Project : QMSL
*
*  Package : Phone
*
*  Company : Qualcomm Technologies Incorporated
*
*  Purpose : Declaration of class CQMSL_Async_LogCollector
*
*********************************************************************
*/

#pragma once

#include "QMSL_Async_Listener.h"
#include "QMSL_Async_LogPacket.h"

#include <list>
#include <vector>
using namespace std;

/**
* Collects phone logs by implementing the listener interface.
*/
class CQMSL_Async_LogCollector : public CQMSL_Async_Listener
{
public:
   CQMSL_Async_LogCollector() : m_size_limit(0) {}

   /**
   * Callback function notifying the listener that a new message has been received by the dispatcher that is
   * intended for this listener.  Will ignore everything but log packets.
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
   * Clear the collection of log packets.
   */
   virtual void ClearLogPackets( void );

   /**
   * Get a vector containing the accumulated log packets.
   * The vector will be cleared, so after the function call
   * it will only contain packets collected by this.
   *
   * \param logPackets : in/out, will contain all gathered log packets
   */
   virtual void GetLogPackets( vector<CQMSL_Async_LogPacket>& logPackets ) const;

   /**
   * Gets the number of log packets accumulated so far.
   *
   * \return the number of log packets accumulated so far.
   */
   virtual unsigned int GetNumLogPackets() const;

   /**
   * Get the most recent log packet received.
   * \param logPkt out param, a copy of the log packet most recently received
   */
   virtual void GetLastLogPacket( CQMSL_Async_LogPacket& logPkt ) const;

   /**
   * Clears the first packet if available.
   */
   virtual void ClearFirstPacket( void );

   /**
   * sets a size limit to prevent collection of packets beyond some number.  limit==0 indicates no limit
   */
   virtual void SetSizeLimit( unsigned int size_limit );

   /**
   * Returns the size of the logpacketcollection , i.e. size of the list 'm_logPackets'
   */
   long Size( void ) const;

   /**
   * The [] operator for this Class. Returns the log packet at the specified index.
   */
   const CQMSL_Async_LogPacket operator[]( long i ) const;

protected:
   // store as a list so you don't get the inefficiency from all of the copies
   // caused by a vector re-allocation
   list<CQMSL_Async_LogPacket> m_logPackets;
   unsigned int m_size_limit;
};
