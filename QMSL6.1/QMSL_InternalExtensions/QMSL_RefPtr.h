/******************************************************************************/
/**
Program: QMSL

$Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief
	Very similar to auto_ptr, but implements referency counting.  Ownership is shared, and
	the object pointed to is only deleted when the reference count reaches zero (no owners

    In addition, this class provides functionality for common data manipulations.

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/

#ifndef CQMSL_RefPtr_H__INCLUDED_
#define CQMSL_RefPtr_H__INCLUDED_

// $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_RefPtr.h#2 $

template <class TYPE>
class CQMSL_RefPtr
{
private:
   TYPE *ptr;
   int *pcount;
   void free() throw()
   {
      if (--*pcount == 0)
      {
         delete pcount;
         delete ptr;
      }
   }
   void copy(const CQMSL_RefPtr<TYPE> & p) throw()
   {
      ptr = p.ptr;
      pcount = p.pcount;
      ++*pcount;
   }
public:
   explicit CQMSL_RefPtr(TYPE *p = NULL) throw() :
      ptr(p), pcount(new int(1)) { }
   CQMSL_RefPtr(const CQMSL_RefPtr<TYPE> & obj) throw()
   {
      copy(obj);
   }
   ~CQMSL_RefPtr() throw()
   {
      free();
   }
   CQMSL_RefPtr<TYPE> & operator=(const CQMSL_RefPtr<TYPE> & rhs) throw()
   {
      if (this != &rhs)
      {
         free();
         copy(rhs);
      }
      return *this;
   }
   TYPE & operator*() const throw()
   {
      return *ptr;
   }
   TYPE * operator->() const throw()
   {
      return ptr;
   }

   virtual bool operator<( const CQMSL_RefPtr<TYPE>& rhs ) const
   {
      return ptr<rhs.ptr;
   }

   virtual bool operator>( const CQMSL_RefPtr<TYPE>& rhs ) const
   {
      return ptr>rhs.ptr;
   }

   virtual bool operator<=( const CQMSL_RefPtr<TYPE>& rhs ) const
   {
      return ptr<=rhs.ptr;
   }

   virtual bool operator>=( const CQMSL_RefPtr<TYPE>& rhs ) const
   {
      return ptr>=rhs.ptr;
   }

   virtual bool operator!=( const CQMSL_RefPtr<TYPE>& rhs ) const
   {
      return ptr!=rhs.ptr;
   }

   virtual bool operator==( const CQMSL_RefPtr<TYPE>& rhs ) const
   {
      return ptr==rhs.ptr;
   }

   bool isNull() const throw()
   {
      return ptr == NULL;
   }
};

#endif