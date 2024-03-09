/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_FTMLogFilter.h#4 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_FTMLogFilter
 *
 *********************************************************************
 */

#pragma once

#include "QMSL_Async_Filter.h"
#include <set>
using namespace std;

/**
 * Filters ftm log packets from the phone based on a set of allowed ftm log codes.
 */
class CQMSL_Async_FTMLogFilter : public CQMSL_Async_Filter
{
public:

   /**
    * Checks the content of the message to determine if it should be passed on to the associated
    * listener object.
    * Will return true if the incoming message is an FTM log packet, and the packet's ftm log_code is in the
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
    * Used for ftm log-code filtering.
    * Adds the specified ftm log-code to the set of allowed codes.
    *
    * \param code the ftm log code to add to the set of allowed codes.
    */
   void AddCode( unsigned short code );

   /**
    * Used for ftm log-code filtering.
    * Adds the specified ftm log-codes to the set of allowed codes.
    *
    * \param code a container of unsigned shorts, each element representing an allowed code
    */
   template< class CONTAINER >
   void AddCodes( const CONTAINER& logCodes );

   /**
    * Clears the set of allowed ftm log codes.
    */
   void ClearCodes( void );

   /** virtual Copy of the filter */
   virtual CQMSL_Async_Filter* Clone() const;

private:
   set<unsigned short> m_logCodes;
};
