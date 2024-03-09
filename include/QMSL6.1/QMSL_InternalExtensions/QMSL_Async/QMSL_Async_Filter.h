/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_Filter.h#3 $
 *
 *  Project : QMSL
 *
 *  Package : Phone
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of class CQMSL_Async_Filter
 *
 *********************************************************************
 */

#pragma once

/**
 * The abstract filter class.  Child classes implement PacketReceived() to return true
 * if the message should be passed along the associated listener object.
 *
 */
class CQMSL_Async_Filter
{
public:
   virtual ~CQMSL_Async_Filter() {}

   /**
    * Checks the content of the message to determine if it should be passed on to the associated listener object.
    *
    * \param packetSize : the size of the packet being sent
    * \param data : the packet itself
    * \return true if message should be passed on to the associated listener object
    */
   virtual bool CheckForValidPacket
   (
      int packetSize,
      unsigned char* data
   ) = 0;

   /** virtual Copy of the filter */
   virtual CQMSL_Async_Filter* Clone() const= 0 ;
};

