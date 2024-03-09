/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_Event.h#3 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_Event
 *
 *********************************************************************
 */

#pragma once

#include <list>
using namespace std;

/**
 * Contains a phone event packet.
 * Manages all memory allocation and de-allocation.
 * Provides static facilities for parsing the raw phone message and generating
 * new CQMSL_Async_EventObjects from the parsing.
 */
class CQMSL_Async_Event
{
public:
   CQMSL_Async_Event();
   CQMSL_Async_Event( const CQMSL_Async_Event& copyPkt );
   CQMSL_Async_Event( int eventId, __int64 timestamp, int payloadLen, const unsigned char* pPayload );
   virtual ~CQMSL_Async_Event();
   CQMSL_Async_Event& operator=( const CQMSL_Async_Event& rhs );

   /**
    * Gets the size of the payload contained in bytes.
    *
    * \return the number of bytes in the contained event payload
    */
   unsigned short GetPayloadLength( void ) const;

   /**
    * Gets the ID of the contained event packet
    *
    * \return the log code
    */
   unsigned short GetEventID( void ) const;

   /**
    * Gets the timestamp from which this event originated.
    *
    * \return timestamp
    */
   unsigned __int64 GetTimestamp( void ) const;

   /**
    * Gets payload of the contained event
    *
    * \return the raw payload bytes
    */
   const unsigned char* GetPayload( void ) const;

   /**
    * Events come from the phone as a single async message that may contain many events.
    * This static function takes a raw async message and parses it, creating new CQMSL_Async_Event
    * objects for every event found.
    *
    * \param pRawEventReport : the raw async message from the phone
    * \param events : a list of events that were parsed out of the raw data.
    *                 The list is simply appended to, so items present in "events"
    *                 will still be present after this function call.
    */
   static void ParseEventReport( unsigned char* pRawEventReport, list<CQMSL_Async_Event>& events );

private:
   typedef enum
   {
      FULL_SYS_TIME = 0,
      TRUNCATED_SYS_TIME,
      MAX_SYS_TIME = 0xffff
   } time_length_enum_type;
   typedef enum
   {
      NO_PAYLOAD_DATA = 0,
      ONE_BYTE_PAYLOAD_DATA,
      TWO_BYTE_PAYLOAD_DATA,
      VAR_LENGTH_PAYLOAD_DATA,
      MAX_PAYLOAD_DATA = 0xffff
   } payload_length_data_flag;
   typedef struct
   {
      time_length_enum_type		time_length;
      payload_length_data_flag	payload_length_flag;
      unsigned short				reserved;
      unsigned short				event_id;
   } event_id_type;

   int m_eventId;
   __int64 m_timestamp;
   int m_payloadLen;
   unsigned char* m_payload;

   void CopyPayload( const unsigned char* pPacket, int payloadLen );

   void Copy( const CQMSL_Async_Event& rhs );
   void Free();
};