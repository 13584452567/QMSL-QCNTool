/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_MessageFilter.h#4 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_MessageFilter
 *
 *********************************************************************
 */

#pragma once

#include "QMSL_Async_Listener.h"
#include <vector>
using namespace std;

/**
 * Filters message packets from the phone based on a set of allowed substrings.
 */
class CQMSL_Async_MessageFilter : public CQMSL_Async_Filter
{
public:

   virtual bool CheckForValidPacket
   (
      int packetSize,
      unsigned char* data
   );

   /**
    * Adds a message ID to the list of allowed msg ids, enable multiple mask bits for ORing
    *
    * \param  ss_id = subsys identifier
    * \param  ss_mask = subsys mask
    */
   void AddMessageID( unsigned short ss_id, unsigned int ss_mask  );

   /**
    * Adds a substring to the list of allowed substrings.
    *
    * \param : searchSubString the substring to be added.
    */
   void AddSearchString( const string& searchSubString  );

   /**
    * Adds substrings to the list of allowed substrings.
    *
    * \param : searchSubStrings the substrings to be added.
    */
   template< class CONTAINER >
   void AddSearchStrings( const CONTAINER& searchSubStrings );

   void ClearFilters( void );

   /*
   void enableRegEx( bool enableIt );
   */

   /** virtual Copy of the filter */
   virtual CQMSL_Async_Filter* Clone() const;

private:
   vector<string> m_searchStrings;
   vector< pair<unsigned short, unsigned int> > m_msgIDs;
//	bool m_useRegEx;
};
