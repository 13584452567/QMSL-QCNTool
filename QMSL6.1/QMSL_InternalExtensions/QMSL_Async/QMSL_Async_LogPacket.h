/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_LogPacket.h#3 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_LogPacket
 *
 *********************************************************************
 */

#pragma once


#pragma pack(push, 1)
#define PACKED

struct LogResponseHeader
{
   unsigned char cmd_code ;
   unsigned char more;
   unsigned short length;
   // followed by LogPacketHeader
};

struct LogPacketHeader
{
   unsigned short length ;
   unsigned short log_code ;
   unsigned __int64 timestamp;
};


#pragma pack(pop)

/**
 * Contains a phone log packet.
 * Manages all memory allocation and de-allocation.
 *
 * This class only stores the log packet portion of the total log response.  The
 * portion stored is:
 *    Field        Length (bytes)
 *    LENGTH          2
 *    LOG_CODE        2
 *    TIMESTAMP       8
 *    DATA         LENGTH-12
 *
 * The packet from the phone will contain an extra 4 bytes (cmd_code, more, and len).
 * This portion should be included when calling CQMSL_Async_LogPacket( const unsigned char* pPacket ),
 * but it will not be copied and stored.
 */
class CQMSL_Async_LogPacket
{
public:
   CQMSL_Async_LogPacket() : m_data(NULL) {}
   CQMSL_Async_LogPacket( const CQMSL_Async_LogPacket& copyPkt );
   explicit CQMSL_Async_LogPacket( const unsigned char* pPacket );
   virtual ~CQMSL_Async_LogPacket();
   CQMSL_Async_LogPacket& operator=( const CQMSL_Async_LogPacket& rhs );


   /**
    * Gets the size of the data contained in bytes.    **bc: is this payload size or packet size???
    *
    * \return the number of bytes in the contained log packet
    */
   unsigned short GetSize( void ) const;

   /**
    * Gets the log code of the contained log packet
    *
    * \return the log code
    */
   unsigned short GetLogCode( void ) const;

   /**
    * Gets the timestamp from which this message originated.
    *
    * \return timestamp
    */
   unsigned __int64 GetTimestamp( void ) const;

   /**
    * Returns one char/byte from the packet data at the index specified.
    * if invalid will return '\0'. The index includes the header.
    * i.e. index 0-11 would be header
    *
    * \param indexIntoPacketData : Index into the Packet Data.
    * \return char at index
    */
   unsigned char  GetBYTE(  unsigned short offset_from_payload ) const;
   unsigned char  GetSBYTE(  unsigned short offset_from_payload ) const;
   unsigned short GetWORD(  unsigned short offset_from_payload ) const;
   unsigned int   GetDWORD( unsigned short offset_from_payload ) const;

   /**
    * Fetches a value from the packet data at the byte_offset specified.
    * The byte_offset does not include the header.
    *
    * \param byte_offset : offset from beginning of payload to fetch
    * \return boolean status. False indicates byte_offset is greater than payload size
    */
   template < class TYPE >
   bool GetItem( TYPE& item, unsigned short byte_offset ) const
   {
      bool valid_read = GetItem(item, byte_offset, sizeof(TYPE) );

      if( !valid_read )
      {
         ZeroMemory( (void*)(&item), sizeof(TYPE) );
      }

      return valid_read;
   }

   /**
    * Fetches a value from the packet data at the byte_offset specified.
    * The byte_offset does not include the header.
    *
    * \param byte_offset : offset from beginning of payload to fetch
    * \return boolean status. False indicates byte_offset is greater than payload size
    */
   template < class TYPE >
   bool GetItem( TYPE& item, unsigned short byte_offset, unsigned num_bytes ) const
   {
      // the number of total bytes
      unsigned short pkt_size  = GetSize();

      // 0-based byte index of the last byte to read from the packet
      unsigned short last_byte = byte_offset + num_bytes - 1;

      // this is a valid read if the last byte index is less than the number of bytes in the packet
      // and if the object passed in is large enough to hold the requested number of bytes
      bool valid_read = (last_byte < pkt_size) && (num_bytes <= sizeof(TYPE));

      if( valid_read )
      {
         // copy the requested number of bytes
         CopyMemory( (void*)(&item), (void*)(GetPayload() + byte_offset), num_bytes );
      }
      else // zero the item if the read failed
      {
         if( num_bytes <= sizeof(TYPE) )
         {
            ZeroMemory( (void*)(&item), num_bytes );
         }
         else
         {
            ZeroMemory( (void*)(&item), sizeof(TYPE) );
         }
      }

      return valid_read;
   }

private:
   unsigned char* m_data;

   /**
    * Copy the packet data, assuming that it contains the extra 4 bytes
    * (cmd_code, more, and len) that will be ignored.
    *
    * \param pPacket : the full data packet from the phone including cmd_code, more, and len
    */
   void CopyFromFullAsyncMessage( const unsigned char* pPacket );

   /**
    * Copy the packet data, assuming that it only contains the useful packet data, NOT
    * including the extra 4 bytes (cmd_code, more, and len)
    *
    * \param pPacket : the log packet, DOES NOT including cmd_code, more, and len
    */
   void CopyFromLogPacket( const unsigned char* pPacket );

   /**
    * Gets the raw packet bytes, but just the payload part.
    * Skips the length, log_code, and timestamp.
    *
    * \return raw packet bytes
    */
   const unsigned char* GetPayload( void ) const;

   void Copy( const CQMSL_Async_LogPacket& rhs );
   void Free();
};