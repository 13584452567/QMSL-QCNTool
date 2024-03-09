/******************************************************************************/
/**
Program: QMSL

	$Id: //depot/HTE/QDART/QMSL/Source/QpstPacketHelper.h#3 $

\brief Class to handle creation of packets for request and response

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/

#if !defined(_QPSTPACKETHELPER_H)
#define _QPSTPACKETHELPER_H

#include "../../QMSL_inc/QLib_Defines.h"

//! Maximum size of a Diagnostic Packet
#define QPST_PACKET_HELPER_MAX_PACKET_SIZE 6144

/*--------------------------------------------------------------------------------------*/
/**
	Class QpstPacketHelper

	\brief Class to handle creation of packets for request and response.

	This class allows the user to append values to the request data one at a time.  As
	each request is added, a "packed" memory buffer is created, which models contains
	the request packet data, exactly as the user requested.  For example, there is no
	filler space between elements in order to align on word boundaries.

	To handle the reponse data, values are "popped" from the end of the response packet,
	which is the location where data is returned from the phone.

*/
/*--------------------------------------------------------------------------------------*/
class QpstPacketHelper
{
public:
   /**
   	Constructor

   	\brief Initialize member variables

   	\return none
   */
   QpstPacketHelper( void);

   /**
   	FUNCTION: AppendRequest

   	\brief Append an 8-bit value to the request data

   	\param byte iValue = value to add to the request packet

   	\return None
   */
   void AppendRequest( byte iValue );

   /**
   	FUNCTION: AppendRequest

   	\brief Append a 16-bit value to the request data

   	\param word iValue = value to add to the request packet

   	\return None
   */
   void AppendRequest( word iValue );

   /**
   	FUNCTION: AppendRequest

   	\brief Append a 32-bute value to the request data

   	\param dword iValue = value to add to the request packet

   	\return None
   */
   void AppendRequest( dword iValue );


   /**
   	FUNCTION: AppendRequest

   	\brief Append another packet helper's request data this packet helper's request data

   	\param QpstPacketHelper oPacketHelper = Packet helper to add to the request packet

   	\return None
   */
   void AppendRequest( QpstPacketHelper oPacketHelper );

   /**
   	FUNCTION: AppendRequest

   	\brief Append a buffer the request data

   	\param iBuffer = pointer to the buffer of data that will be added
   	\param iNumBytes = number of bytes to apped to transfer

   	\return None
   */
   void AppendRequest( byte* iBuffer, dword iNumBytes);

   /**
   	FUNCTION: GetRequestLength

   	\brief Return the length of the request data

   	\param None

   	\return length of request data
   */
   word GetRequestLength( void )
   {
      return m_iRequestLen;
   }

   /**
   	FUNCTION: GetResponseLength

   	\brief Return the length of the response data

   	\param None

   	\return length of request data
   */
   word GetResponseLength( void )
   {
      return m_iResponseLen;
   }


   /**
   	FUNCTION: GetResponseStackSize

   	\brief Return the response stack size/length

   	\param None

   	\return length of response stack
   */
   word GetResponseStackSize( void )
   {
      return m_iResponseStackPtr;
   }

   /**
   	FUNCTION: GetRequestDataPtr

   	\brief Return a pointer to the request data

   	\param None

   	\return length of request data
   */
   byte* GetRequestDataPtr( void )
   {
      return m_aRequestData;
   }

   /**
   	FUNCTION: GetResponseDataPtr

   	\brief Return a pointer to the response data

   	\param None

   	\return Pointer to response data
   */
   byte* GetResponseDataPtr( void )
   {
      return m_aResponseData;
   }


   /**
   	FUNCTION: GetResponseLengthPtr

   	\brief Return a pointer to the response length

   	\param None

   	\return length of request data
   */
   word* GetResponseLengthPtr( void )
   {
      return &m_iResponseLen;
   }

   /**
   	FUNCTION: SetResponseStackSize

   	\brief Set the stack size to a fixed number.  This is useful for
   	       dealing with packets that do not return the correct number of bytes.

   	\param iStackSize = new stack size. If this is > the reponse packet length, then the size
   	                    will be set to the response packet length instead of the number
   						supplied here.

   	\return Pointer to response data
   */
   void SetResponseStackSize( word iStackSize );


   /**
   	FUNCTION: CopyRequestToResponse

   	\brief Copy the request data to the response data.  This is used mainly for
   	       testing the response functions.

   	\param None

   	\return None
   */
   void CopyRequestToResponse( void );

   /**
   	FUNCTION: PopResponseData

   	\brief Return the next byte on the response stack, which is at the end of the response packet.
   			This will decrement the response stack pointer to point to the next available item.

   	\param byte& iValue = by-reference storage for the next byte

   	\return true if successful, false if not successful.
   */
   bool PopResponseData( byte& iValue );

   /**
   	FUNCTION: PopResponseData

   	\brief Return the next word on the response stack, which is at the end of the response packet.
   			This will decrement the response stack pointer to point to the next available item.

   	\param word& iValue = by-reference storage for the next word

   	\return true if successful, false if not successful.
   */
   bool PopResponseData( word& iValue );

   /**
   	FUNCTION: PopResponseData

   	\brief Return the next dword on the response stack, which is at the end of the response packet.
   			This will decrement the response stack pointer to point to the next available item.

   	\param dword& iValue = by-reference storage for the next dword

   	\return true if successful, false if not successful.
   */
   bool PopResponseData( dword& iValue );

   /**
   	FUNCTION: PopResponseData

   	\brief Pop a certain number of bytes off the packet and into a buffer.
   			This will decrement the response stack pointer by iNumBytes.

   	\param iBuffer = pointer to the buffer of data that will store the contents taken from the request packet
   	\param piNumBytes = number of bytes to transfer

   	\return true if successful, false if not successful.
   */
   bool PopResponseData( byte* piBuffer, dword iNumBytes);


   /**
   	FUNCTION: Reset

   	\brief Reset the request and response packets, including data storage space and counters

   	\param None

   	\return None
   */
   void Reset( void );


private:
   //! Request Data Storage
   byte m_aRequestData[ QPST_PACKET_HELPER_MAX_PACKET_SIZE ];

   //! Response Data Storage
   byte m_aResponseData[ QPST_PACKET_HELPER_MAX_PACKET_SIZE ];


   //! Request data length
   word m_iRequestLen;

   //! Response data length
   word m_iResponseLen;

   //! Response stack pointer
   word m_iResponseStackPtr;

};


#endif // !defined(_QPSTPACKETHELPER_H)
