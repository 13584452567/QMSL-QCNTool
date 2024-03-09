/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_Listener.h#5 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_Listener
 *
 *********************************************************************
 */

#pragma once

#if FALSE // def __SUITE__HIVE__
#include "HIVE_Listener.h"
#endif

// QMSL Merge
#include "QMSL_InternalExtensions\QMSL_RefPtr.h"
#include "QMSL_Async_Filter.h"
#include <set>
using namespace std;

// forward declaration of dispatcher
class CQMSL_Async_Dispatcher;

/**
 * The abstract listener class.  Child classes implement PacketReceived() to carry out
 * operations on incoming messages.  Maintains a bi-directional link with the dispatcher
 * such that both will be aware of the other going out of scope.
 */
class CQMSL_Async_Listener
{
public:

   CQMSL_Async_Listener();
   virtual ~CQMSL_Async_Listener();

   static void ShutdownAll( void );

   CQMSL_Async_Listener( const CQMSL_Async_Listener& copyObj );
   CQMSL_Async_Listener& operator=( const CQMSL_Async_Listener& rhs );

   /**
    * Removes the specified dispatcher from the set of dispatchers that this listener is registered with.
    * Typically, this would be called by the dispather itself to synchronize the bi-directional link when
    * the listener is removed from the set of registered listeners of the dispatcher.
    *
    * \param handle : the unique handle for this com port.
    * \param pDisp : a pointer to the CQMSL_Async_Dispatcher object to be removed from the set of
    *                registered dispatchers.
    */
   virtual void RemoveDispatcher( HANDLE handle, CQMSL_Async_Dispatcher* pDisp );

   /**
    * Adds the specified dispatcher to the set of registered dispatchers.
    * Typically, this would be called by the dispatcher itself to synchronize the bi-directional link when
    * the listener is added from the set of registered listeners of the dispatcher.
    *
    * \param handle : the unique handle for this com port.
    * \param pDisp : a pointer to the CQMSL_Async_Dispatcher object to be added to the set of
    *                registered dispatchers.
    */
   virtual void RegisterDispatcher( HANDLE handle, CQMSL_Async_Dispatcher* pDisp );


   /**
    * Callback function notifying the listener that a new message has been received by the dispatcher that is
    * intended for this listener.
    *
    * \param packetSize : the size of the packet being sent
    * \param data : the packet itself
    */
   virtual void PacketReceived
   (
      int packetSize,
      unsigned char* data
   ) = 0;

   virtual void SetFilter( const CQMSL_Async_Filter &filt );
   virtual bool CheckFilter( int packetSize, unsigned char* data ) const;

   virtual void Shutdown( void );

protected:
   mutable CRITICAL_SECTION m_cs;

private:

   void Copy( const CQMSL_Async_Listener& rhs );
   void Free();

   /**
   * Private helper class for CQMSL_Async_Listener.
   * Contains a handle and CQMSL_Async_Dispatcher* along with comparison operators to allow it to be used as a key
   * in a sorted container.
   */
   class DispatcherWithHandle
   {
   public:
      DispatcherWithHandle( HANDLE h, CQMSL_Async_Dispatcher* pS ) : handle(h), pDisp(pS) {}

      /**
      * Less-than operator
      *
      * \param rhs : right-hand-side of the comparison
      * \return : less than result based on handle and pDisp
      */
      bool operator<(const DispatcherWithHandle& rhs) const;
      /**
      * Equal operator
      *
      * \param rhs : right-hand-side of the comparison
      * \return : equality result based on handle and pDisp
      */
      bool operator==(const DispatcherWithHandle& rhs) const;
      /**
      * Not-equal operator
      *
      * \param rhs : right-hand-side of the comparison
      * \return : not-equal result based on handle and pDisp
      */
      bool operator!=(const DispatcherWithHandle& rhs) const;

      HANDLE handle;
      CQMSL_Async_Dispatcher* pDisp;
   };

   //! the set of dispatchers to be notified when this goes out of scope
   set<DispatcherWithHandle> m_dispatchers;

   CQMSL_RefPtr<CQMSL_Async_Filter> m_pFilter;

   bool m_shuttingDown;

   static set<CQMSL_Async_Listener*> m_activeListeners;

   // debug
   unsigned int m_id;
   static unsigned int m_idGen;
};
