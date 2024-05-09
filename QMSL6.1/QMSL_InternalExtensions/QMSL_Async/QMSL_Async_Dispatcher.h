/*!
*********************************************************************
*  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_Dispatcher.h#5 $
*
*  Project : QMSL
*
*  Company : Qualcomm Technologies Incorporated
*
*  Purpose : Declaration of class CQMSL_Async_Dispatcher
*
*********************************************************************
*/

#pragma once

#include <set>
using namespace std;

// forward-declaration of listener classes
class CQMSL_Async_Listener;

/**
* Receives messages from a phone server and dispatches them to a set of registered listeners.
* Implements a bi-directional linkage with listeners to ensure robust operation if a lister or
* dispatcher goes out of scope (preventing one from interacting with an invalid pointer to the other).
*/
class CQMSL_Async_Dispatcher
{
public:

   static void ShutdownAll( void );

   //! Const handl to indicate that an operation is to be performed on all handles
   static const HANDLE ALL_HANDLES;

   /**
   *
   * \param void
   * \return
   */
   static CQMSL_Async_Dispatcher* GetInstance( void );

   /**
   * PacketReceived is the single point of entry into SUITE for messages coming from the phone communication library.
   *
   * \param msgSize : the size of the packet being sent
   * \param msgBuffer : the packet itself
   * \param handle : the unique identifier for the COM port
   */
   static void PacketReceived( unsigned short pktSize, unsigned char* pktBuffer, HANDLE handle );

   /**
   * LibraryLogMsgReceived is the single point of entry into SUITE for messages coming from the phone communication library.
   *
   * \param msgSize : the size of the lib log msg being sent
   * \param msgBuffer : the log msg itself
   * \param handle : the unique identifier for the COM port
   */
   static void LibraryLogMsgReceived( unsigned short pktSize, unsigned char* pktBuffer, HANDLE handle );

   /**
   * Removes a listener from the set of objects to be notified of incoming messages.
   * Every link between the dispatcher and listener is uniquely identified by handle and address (through AddListener).
   * You must call RemoveListener for every link that was established
   *
   * \param handle : the unique identifier for the COM port
   * \param pListener : a pointer to the listener object to be removed
   */
   virtual void RemoveListener( HANDLE handle, CQMSL_Async_Listener* pListener );

   /**
   * Adds a listener to the set of objects to be notified of incoming library log messages.
   * Every link between the dispatcher and listener is uniquely identified by handle and address.
   *
   * \param handle : the unique identifier for the COM port
   * \param pListener : a pointer to the listener object to be added
   */
   virtual void AddListener( HANDLE handle, CQMSL_Async_Listener* pListener );

   /**
   * Broadcasts a message to all registered listeners.
   *
   * \param msgSize : the size of the packet being sent
   * \param msgBuffer : the packet itself
   * \param handle : the unique identifier for the COM port
   */
   virtual void Broadcast( unsigned short msgSize, unsigned char* msgBuffer, HANDLE handle );

   /**
   * Broadcasts a message to all registered listeners.
   *
   * \param msgSize : the size of the packet being sent
   * \param msgBuffer : the packet itself
   * \param handle : the unique identifier for the COM port
   */
   virtual void BroadcastLibraryLog( unsigned short msgSize, unsigned char* msgBuffer, HANDLE handle );


   /**
   * Adds a listener from the set of objects to be notified of incoming messages.
   * Every link between the dispatcher and listener is uniquely identified by handle and address.
   *
   * \param handle : the unique identifier for the COM port
   * \param pListener : a pointer to the listener object to be added
   */
   virtual void AddLibraryLogListener( HANDLE handle, CQMSL_Async_Listener* pListener );

   virtual ~CQMSL_Async_Dispatcher();

   virtual void Shutdown( void );

private:
   CQMSL_Async_Dispatcher();
   CQMSL_Async_Dispatcher( const CQMSL_Async_Listener& ) {}
   CQMSL_Async_Dispatcher& operator=( const CQMSL_Async_Listener& )
   {
      return *this;   // wrong implementation, but this should never be called, wanted to use ASSERT but not available
   }

   /**
   * Private helper class for CQMSL_Async_Dispatcher.
   * Contains a handle and listener* along with comparison operators to allow it to be used as a key
   * in a sorted container.
   */
   class ListenerWithHandle
   {
   public:
      ListenerWithHandle( HANDLE h, CQMSL_Async_Listener* pO, bool isLibraryLogListener = false ) :
         handle(h), pListener(pO), m_inScope(true), m_isLibraryLogListener(isLibraryLogListener) {}

      ~ListenerWithHandle()
      {
         m_inScope = false;
      }
      /**
      * Less-than operator
      *
      * \param rhs : right-hand-side of the comparison
      * \return : less than result based on only handle and pListener
      */
      bool operator<(const ListenerWithHandle& rhs) const;
      /**
      * Equal operator
      *
      * \param rhs : right-hand-side of the comparison
      * \return : equality result based on only handle and pListener
      */
      bool operator==(const ListenerWithHandle& rhs) const;
      /**
      * Not-equal operator
      *
      * \param rhs : right-hand-side of the comparison
      * \return : not-equal result based on only handle and pListener
      */
      bool operator!=(const ListenerWithHandle& rhs) const;

      HANDLE handle;
      CQMSL_Async_Listener* pListener;

      bool m_isLibraryLogListener;

      bool m_inScope;
   };

   //! the set of listeners to be notified when new messages arrives, or when the dispatcher goes out of scope.
   set<ListenerWithHandle> m_listeners;

   //! a pointer to self to allow static functions to call non-static functions on the singleton instance.
   static CQMSL_Async_Dispatcher* m_pSelf;

   CRITICAL_SECTION m_cs;

   bool m_shuttingDown;

   static set<CQMSL_Async_Dispatcher*> m_activeDispatchers;

   void AddListenerImpl( HANDLE handle, CQMSL_Async_Listener* pListener, bool isLibraryLogListener );
   void BroadcastImpl( unsigned short msgSize, unsigned char* msgBuffer, HANDLE handle, bool isLibraryLogListener );
   void Free();
};