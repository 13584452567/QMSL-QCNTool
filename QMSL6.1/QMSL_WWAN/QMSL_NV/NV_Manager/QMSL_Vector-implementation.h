/******************************************************************************/
/**
Program: QMSL

$Id: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_Vector-implementation.h#2 $

\brief This class is the interface to the phone under test. It wraps around
       the phone library supplied by Tim Walker.

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/

/** // For precompiled headers   */
#if !defined( QMSL_POSIX_PORTABLE )
#include "QMSL_CalDataManager_Utilities.h"
#else
#define QMSL_THROW(message) {};
#endif

/** // Class header           */
#include "QMSL_Vector.h"

#if !defined (QMSL_POSIX_PORTABLE)
template <class Type > void QMSL_Vector<Type>::AppendFromString( char* sInputString)
{

   char* _pParsePointer = sInputString;
   double _dNextValue = 0.0;

   // Loop through the data elements
   while ( QMSL_Utilities::ParseDouble( _pParsePointer, _dNextValue ) )
   {
      Append( (Type) _dNextValue );
   }  // while( ...ParseDouble(...))
}
#endif


/**
   \brief Get the maximum value

   \params  None

   \return Return the maximum value in a list
*/
template <class Type > Type QMSL_Vector<Type>::Max( void )
{
   Type _tLastMax = 0;
   bool _bFirstValue = true;

   // Loop through all values
   for ( unsigned int _iIndex = 0; _iIndex < Size(); _iIndex++ )
   {
      // Is this the first value?
      if ( _bFirstValue )
      {
         _tLastMax = _data[ _iIndex ]; // Set the min value
         _bFirstValue = false;         // Turn off the "first" flag
      }
      else
      {
         // Compare the current data element to the last min
         if ( _data[_iIndex ] > _tLastMax )
         {
            // Set the new minimum
            _tLastMax = _data[_iIndex ];

         }  // if ( _data[_iIndex ] > _tLastMax )
      } // _bFirstValue

   } // _iIndex

   return _tLastMax;
}

/**
   \brief Get the minimum value

   \params  None

   \return Return the minimum value in a list
*/
template <class Type > Type QMSL_Vector<Type>::Min( void )
{
   Type _tLastMin  = 0;
   bool _bFirstValue = true;
   unsigned int _iIndex;
   // Loop through all values
   for ( _iIndex = 0; _iIndex < Size(); _iIndex++ )
   {
      // Is this the first value?
      if ( _bFirstValue )
      {
         _tLastMin = _data[ _iIndex ]; // Set the min value
         _bFirstValue = false;         // Turn off the "first" flag
      }
      else
      {
         // Compare the current data element to the last min
         if ( _data[_iIndex ] < _tLastMin )
         {
            // Set the new minimum
            _tLastMin = _data[_iIndex ];
         }  // if ( _data[_iIndex ] < _tLastMin )
      } // _bFirstValue

   } // _iIndex

   return _tLastMin;
}


/**
   \brief Convert the vector to slope offset format

   \params  None

   \return None
*/
template <class Type > void QMSL_Vector<Type>::ConvertToSlopeOffset( void )
{

   // In slope offset, the first value remains and subsequent values are the difference between
   // the current item and the previous item.  To accomplish this efficiently, it is best
   // to start at the end of the last and move toward the beginning
   for ( int _iIndex = Size() -1; _iIndex > 0; _iIndex-- )
   {
      _data[ _iIndex ] = _data[ _iIndex ] - _data[ _iIndex -1 ];
   }
}

/**
   \brief Get the vector, represented as a string

   \param   string& sOutput = storage area for string
   \param  string sFormat = %d for int, %6.2f for double
   \param   string sDelimeter = character to delimit each value

   \return None
*/

#if !defined (QMSL_POSIX_PORTABLE)
template <class Type > void QMSL_Vector<Type>::GetString( string & sOutput, string  sFormat, string sDelimeter)
{

   // Set the name followed by colon & tab
   sOutput = GetName() + ":\t";

   string  _sNextValue;

   // Loop through each value
   for ( int _iIndex = 0; _iIndex < Size(); _iIndex++ )
   {
      // Add the next value
      _sNextValue.Format( sFormat.GetBuffer(0), _data[ _iIndex]);

      sOutput += _sNextValue;

      // Add the delimiter if ! the last value
      if ( _iIndex != Size() - 1 )
         sOutput += sDelimeter;
   }
}
#endif


/**
   \brief Get the index of the array element with largest X value

   \param   none

   \return index of the array element with largest X value
*/
template <class TypeX, class TypeY> int QMSL_2DVector<TypeX, TypeY>::GetMaxXValueIndex()
{
   TypeX maxX = TypeX();
   int   maxXindex = 0;
   if( _pvX->Size() > 0)
   {
      maxX = _pvX->GetValue(0);
      maxXindex = 0;
   }
   for(unsigned int i = 1; i < _pvX->Size(); i++)
   {
      if(_pvX->GetValue(i) > maxX)
      {
         maxX = _pvX->GetValue(i);
         maxXindex = i;
      }
   }

   return maxXindex;
}

/**
   \brief Get the largest X element from X array

   \param   none

   \return largest array element in X array
*/
template <class TypeX, class TypeY> TypeX QMSL_2DVector<TypeX, TypeY>::GetMaxXValue()
{
   TypeX maxX = 0;
   if( _pvX->Size() > 0)
      maxX = _pvX->GetValue(0);

   for(unsigned int i = 1; i < _pvX->Size(); i++)
   {
      if(_pvX->GetValue(i) > maxX)
         maxX = _pvX->GetValue(i);
   }

   return maxX;
}

/**
   \brief Get the 2nd largest X element from X array

   \param   none

   \return the 2nd largest array element in X array
*/
template <class TypeX, class TypeY> TypeX QMSL_2DVector<TypeX, TypeY>::Get2ndMaxXValue()
{

   TypeX maxX = GetMaxXValue();
   TypeX tempX ;
   TypeX maxX2nd;
   unsigned int i = 0;

   maxX2nd = tempX = _pvX->GetValue(i);

   if(tempX == maxX)
   {
      i++;
      maxX2nd = tempX = _pvX->GetValue(i);
   }

   for(; i < _pvX->Size(); i++)
   {
      tempX = _pvX->GetValue(i);
      if((tempX < maxX) && (tempX > maxX2nd))
         maxX2nd = tempX;
   }

   return maxX2nd;

}

/**
   \brief Get the 2nd smallest X element from X array

   \param   none

   \return the 2nd smallest array element in X array
*/
template <class TypeX, class TypeY> TypeX QMSL_2DVector<TypeX, TypeY>::Get2ndMinXValue()
{
   TypeX minX = GetMinXValue();
   TypeX tempX ;
   TypeX minX2nd;
   unsigned int i = 0;

   minX2nd = tempX = _pvX->GetValue(i);

   if(tempX == minX)
   {
      i++;
      minX2nd = tempX = _pvX->GetValue(i);
   }

   for(; i < _pvX->Size(); i++)
   {
      tempX = _pvX->GetValue(i);
      if((tempX > minX) && (tempX < minX2nd))
         minX2nd = tempX;
   }

   return minX2nd;

}


/**
   \brief Get the index of the array element with the 2nd smallest X value

   \param   none

   \return index of the array element with the 2nd smallest X value
*/
template <class TypeX, class TypeY> int QMSL_2DVector<TypeX, TypeY>::Get2ndMinXValue_Index()
{
   TypeX minX = GetMinXValue();
   TypeX tempX ;
   TypeX minX2nd;
   int minX2ndIndex = 0;
   unsigned int i = 0;

   minX2ndIndex = 0;
   minX2nd = tempX = _pvX->GetValue(i);

   if(tempX == minX)
   {
      i++;
      minX2nd = tempX = _pvX->GetValue(i);
      minX2ndIndex = i;
   }

   for(; i < _pvX->Size(); i++)
   {
      tempX = _pvX->GetValue(i);
      if((tempX > minX) && (tempX < minX2nd))
      {
         minX2nd = tempX;
         minX2ndIndex = i;
      }
   }

   return minX2ndIndex;

}

/**
   \brief Get the index of the array element with the 2nd largest X value

   \param   none

   \return index of the array element with the 2nd largest X value
*/
template <class TypeX, class TypeY> int QMSL_2DVector<TypeX, TypeY>::Get2ndMaxXValue_Index()
{
   TypeX maxX = GetMaxXValue();
   TypeX tempX ;
   TypeX maxX2nd;
   int maxX2ndIndex = 0;
   unsigned int i = 0;

   maxX2ndIndex = 0;
   maxX2nd = tempX = _pvX->GetValue(i);

   if(tempX == maxX)
   {
      i++;
      maxX2nd = tempX = _pvX->GetValue(i);
      maxX2ndIndex = i;
   }

   for(; i < _pvX->Size(); i++)
   {
      tempX = _pvX->GetValue(i);
      if((tempX < maxX) && (tempX > maxX2nd))
      {
         maxX2nd = tempX;
         maxX2ndIndex = i;
      }
   }

   return maxX2ndIndex;

}

/**
   \brief Get the Y array element with the largest X value

   \param   none

   \return Y array element with the largest X value
*/

template <class TypeX, class TypeY> TypeY QMSL_2DVector<TypeX, TypeY>::GetMaxX_YValue()
{
   int maxXindex =  GetMaxXValueIndex();
   return _pvY->GetValue(maxXindex);
}

/**
   \brief Get the Y array element with the smallest X value

   \param   none

   \return Y array element with the samllest X value
*/
template <class TypeX, class TypeY> TypeY QMSL_2DVector<TypeX, TypeY>::GetMinX_YValue()
{
   int minXindex =  GetMinXValueIndex();
   return _pvY->GetValue(minXindex);
}

/**
   \brief Get the Y array element with the 2nd largest X value

   \param   none

   \return Y array element with the 2nd largest X value
*/
template <class TypeX, class TypeY> TypeY QMSL_2DVector<TypeX, TypeY>::Get2ndMaxX_YValue()
{
   int maxX2ndIndex =  Get2ndMaxXValue_Index();
   return _pvY->GetValue(maxX2ndIndex);
}

/**
   \brief Get the Y array element with the 2nd smallest X value

   \param   none

   \return Y array element with the 2nd smallest X value
*/
template <class TypeX, class TypeY> TypeY QMSL_2DVector<TypeX, TypeY>::Get2ndMinX_YValue()
{
   int minX2ndIndex = Get2ndMinXValue_Index();
   return _pvY->GetValue(minX2ndIndex);
}

/**
   \brief Get the smallest X element from X array

   \param   none

   \return the smallest array element in X array
*/
template <class TypeX, class TypeY> TypeX QMSL_2DVector<TypeX, TypeY>::GetMinXValue()
{
   TypeX minX = 0;
   if( _pvX->Size() > 0)
      minX = _pvX->GetValue(0);

   unsigned int i;
   for(i = 1; i < _pvX->Size(); i++)
   {
      if(_pvX->GetValue(i) < minX)
         minX = _pvX->GetValue(i);
   }

   return minX;
}


/**
   \brief Get the index of the 2nd smallest element from X array

   \param   none

   \return the index of the 2nd smallest array element in X array
*/
template <class TypeX, class TypeY> int QMSL_2DVector<TypeX, TypeY>::GetMinXValueIndex()
{
   TypeX minX = 0;
   int minXindex = 0;
   if( _pvX->Size() > 0)
      minX = _pvX->GetValue(0);

   unsigned int i;
   for(i = 1; i < _pvX->Size(); i++)
   {
      if(_pvX->GetValue(i) < minX)
      {
         minX = _pvX->GetValue(i);
         minXindex = i;
      }
   }

   return minXindex;
}


/**
   \brief Interpolate a single Y2 value based on X2, inside of the X and Y vectors.
         The X and Y elements must be aligned (element 2 in X corresponds to element 2 in Y,
         but the X values do not need to be in numeric order.

   \param TypeX tXValue = The X2 value for which Y2 is calculated
   \param bool bRoundResult = true if result should be rounded.

   \return Y2 value cooresponding to the X2 value, as interpolated inside X and Y vectors
*/
template <class TypeX, class TypeY > TypeY QMSL_2DVector<TypeX,TypeY>::InterpolateY2( TypeX tX2, bool bRoundResult )
{
   // Y2 return value
   TypeY _tY2 = TypeY();
// double _dY2;

   // Other calculations
   TypeX _tChangeX;
   TypeY _tChangeY;

   TypeX _tX1;
   TypeY _tY1;

   //TypeY _tIntercept;

   // Slope
   double _dSlope;



   // Indexes
   int _iLowIndex = -1;
   int _iHighIndex = -1;
   int _iLastIndex = _pvX->Size() - 1;

   int _iIndex = 0;

   // Found Flag
   // bool _bSlopeFound = false;

   // Make sure pointers are valid
   //if ( !_pvX ) throw new QMSL_CalDataManagerException("QMSL_2DVECTOR: X vector is not specified" );
   //if ( !_pvY ) throw new QMSL_CalDataManagerException("QMSL_2DVECTOR: Y vector is not specified" );

   if (!_pvX) QMSL_THROW("QMSL_2DVECTOR: X vector is not specified")

      // Ensure that the vectors are the same size
      if ( _pvX->Size() != _pvY->Size() )
      {
#if !defined (QMSL_POSIX_PORTABLE)
         throw new QMSL_CalDataManager_Exception("QMSL_2DVECTOR: Vectors %s and %s cannot be combined because they have a different number of elements (%d & %d)",
                                                 _pvX->GetName(),
                                                 _pvY->GetName(),
                                                 _pvX->Size(),
                                                 _pvY->Size()
                                                );
#else

         printf("QMSL_2DVECTOR: Vectors %s and %s cannot be combined because they have a different number of elements (%d & %d)",
                _pvX->GetName(),
                _pvY->GetName(),
                _pvX->Size(),
                _pvY->Size()
               );

#endif
      }


   // If there is only one pair of (x,y), return y, regardless of x
   if(( _pvX->Size() == 1) && (_pvY->Size() == 1))
   {
      return _tY2 = _pvY->GetValue(0);
   }

   // The X value is greater than any elements in the array
   if(tX2 > GetMaxXValue())
   {
      double slope = (Get2ndMaxX_YValue() - GetMaxX_YValue()) / (Get2ndMaxXValue() - GetMaxXValue());
      return _tY2 = (TypeY) (slope * (tX2 - GetMaxXValue()) +  GetMaxX_YValue());

   }

   // The X value is less than any elements in the array
   if(tX2 < GetMinXValue())
   {
      double slope =  (Get2ndMinX_YValue() - GetMinX_YValue()) / (Get2ndMinXValue() - GetMinXValue());
      return _tY2 = (TypeY)( slope * (tX2 - GetMinXValue()) +  GetMinX_YValue());
   }

   // Check whether X value is in the array.  If so, returns the corresponding Y value
   TypeX _X_current;
   for ( _iIndex = 0; _iIndex <= _iLastIndex; _iIndex++ )
   {
      _X_current = _pvX->GetValue(_iIndex );
      if(tX2 == _X_current)
      {
         return _tY2 = _pvY->GetValue(_iIndex);
      }
   }


   // Values the store the closest match so far
   TypeX _X_low;
   TypeX _X_high;


   if(tX2 > _pvX->GetValue(0))
   {
      _X_low = _pvX->GetValue(0);
      _iLowIndex = 0;
   }
   else
      _X_low = -9999999;


   if(tX2 < _pvX->GetValue(0))
   {
      _X_high = _pvX->GetValue(0);
      _iHighIndex = 0;
   }
   else
      _X_high = 9999999;

   // _index represents the actual number of data points in the PDMvsPWR array
   for ( _iIndex = 0; _iIndex <= _iLastIndex; _iIndex++ )
   {
      // Assign the current value to a working variable
      _X_current = _pvX->GetValue(_iIndex );
      // If   (    the current HIGH INDEX is empty
      //       AND  the HIGH_VALUE is greater than the current value
      //      )
      if ( ( _X_current > tX2 ) && ( _X_current < _X_high ) )
      {
         _iHighIndex = _iIndex;
         _X_high = _X_current;
      }

      //      OR  (    the current value is less than the target
      //       AND  the LOW_VALUE is less than the current value
      //      )
      if (( _X_current < tX2 ) &&   ( _X_current > _X_low ))
      {
         _iLowIndex = _iIndex;
         _X_low = _X_current;
      }
   }// end for


   // if (_bSlopeFound )
   {

      // If no values are found, this is an error
      if (  ( _iHighIndex == -1)
            && ( _iLowIndex ==  -1)
         )
      {
#if !defined (QMSL_POSIX_PORTABLE)
         throw new QMSL_CalDataManager_Exception("During interpolation on %s and %s vectors, no data has been found",_pvX->GetName(), _pvY->GetName() );
#else
         printf("During interpolation on %s and %s vectors, no data has been found",_pvX->GetName(), _pvY->GetName() );
#endif

      }

      if ( _iHighIndex == -1) // If the high index is not found, then use only the low index
      {
         _iHighIndex = _iLowIndex + 1; // Assign the high index to low index + 1

         // Check for high index < size
         if ( _iHighIndex > _iLastIndex )
            _iHighIndex = _iLowIndex;

      }
      else if ( _iLowIndex == -1)
      {
         _iLowIndex = _iHighIndex - 1; // Assign the high index to low index - 1

         // Check for low index < 0
         if ( _iLowIndex < 0 )
            _iLowIndex = _iHighIndex;

      }
      else if (_iHighIndex == _iLowIndex )
      {
         _tY2 = (TypeY) _pvY->GetValue (_iHighIndex);
      }
      else
      {
         //calculate the slope using the current bin and the next one
         _tChangeY = _pvY->GetValue( _iHighIndex) - _pvY->GetValue(_iLowIndex);
         _tChangeX = _pvX->GetValue( _iHighIndex) - _pvX->GetValue(_iLowIndex);

         //find b, use either set of data but they must be from the same bin
         //using the lesser values because these may equal the target power
         _tY1 = _pvY->GetValue( _iLowIndex );
         _tX1 = _pvX->GetValue( _iLowIndex );

         _dSlope = (double) ( _tChangeY/_tChangeX );

         _tY2 = (TypeY)((_dSlope * (tX2 - _tX1)) + _tY1);
         // Now find PDM for the target power
         //_dY2 = ( _dSlope * tX2 ) + _tIntercept;

         /*
          if ( bRoundResult && (_iHighIndex != _iLowIndex ))
         {
          if(_dY2 < 0.0 ) //Checks to see if value is negative. If so you subtract .5
             _dY2 = _dY2 - .5;
          else
             _dY2 = _dY2 + .5;

         }
         // Assign to the final value, with type cast
         _tY2 = (TypeY) _dY2;
         */
         _tY2 = (TypeY) _tY2;
      }

   }  // _bIsSlopeFound


   return _tY2;
}

template <class TypeX, class TypeY > TypeY QMSL_2DVector<TypeX,TypeY>::InterpolateY2_SlopeAveragingExtrapolation( TypeX tX2, bool bRoundResult, int iNumOfPtToAveSlope )
{
   // Y2 return value
   TypeY _tY2 = TypeY();
// double _dY2;

   // Other calculations
   TypeX _tChangeX;
   TypeY _tChangeY;

   TypeX _tX1;
   TypeY _tY1;

   //TypeY _tIntercept;

   // Slope
   double _dSlope;
   double _dSlopeOnLowXside = 0;
   double _dSlopeOnHighXside = 0;

   // Indexes
   int _iLowIndex = -1;
   int _iHighIndex = -1;
   int _iLastIndex = _pvX->Size() - 1;

   int _iIndex = 0;

   // Found Flag
   // bool _bSlopeFound = false;

   // Make sure pointers are valid
   //if ( !_pvX ) throw new QMSL_CalDataManagerException("QMSL_2DVECTOR: X vector is not specified" );
   //if ( !_pvY ) throw new QMSL_CalDataManagerException("QMSL_2DVECTOR: Y vector is not specified" );

   if (!_pvX) QMSL_THROW("QMSL_2DVECTOR: X vector is not specified")

      // Ensure that the vectors are the same size
      if ( _pvX->Size() != _pvY->Size() )
      {

#if !defined ( QMSL_POSIX_PORTABLE )
         throw new QMSL_CalDataManager_Exception("QMSL_2DVECTOR: Vectors %s and %s cannot be combined because they have a different number of elements (%d & %d)",
                                                 _pvX->GetName(),
                                                 _pvY->GetName(),
                                                 _pvX->Size(),
                                                 _pvY->Size()
                                                );
#else
         printf("QMSL_2DVECTOR: Vectors %s and %s cannot be combined because they have a different number of elements  (%d & %d)",
                _pvX->GetName(),
                _pvY->GetName(),
                _pvX->Size(),
                _pvY->Size()
               );
#endif
      }


   // If there is only one pair of (x,y), return y, regardless of x
   if(( _pvX->Size() == 1) && (_pvY->Size() == 1))
   {
      return _tY2 = _pvY->GetValue(0);
   }

   _dSlopeOnLowXside = 0;
   int i = 0;
   for(i = 0; i < iNumOfPtToAveSlope; i++)
   {
      double _tempSlope = ( _pvY->GetValue(i) - _pvY->GetValue(i + 1)) / (_pvX->GetValue(i) - _pvX->GetValue(i + 1));
      _dSlopeOnLowXside = (_tempSlope + _dSlopeOnLowXside * i) / (i + 1);
   }

   int j = 0;
   _dSlopeOnHighXside = 0;
   for( i = 0, j = _pvX->Size() - 1; i < iNumOfPtToAveSlope; i++, j--)
   {
      double _tempSlope = ( _pvY->GetValue(j) - _pvY->GetValue(j-1)) / (_pvX->GetValue(j) - _pvX->GetValue(j-1));
      _dSlopeOnHighXside = (_tempSlope + _dSlopeOnHighXside * i) / (i + 1);
   }

   // The X value is greater than any elements in the array
   if(tX2 > _pvX->GetValue(_pvX->Size() - 1))
   {
      return _tY2 = (TypeY) (_dSlopeOnHighXside * (tX2 - _pvX->GetValue(_pvX->Size() - 1)) +  _pvY->GetValue(_pvY->Size() - 1));
   }

   // The X value is less than any elements in the array
   if(tX2 < _pvX->GetValue(0))
   {
      return _tY2 = (TypeY)( _dSlopeOnLowXside * (tX2 - _pvX->GetValue(0)) +  _pvY->GetValue(0));
   }

   // Check whether X value is in the array.  If so, returns the corresponding Y value
   TypeX _X_current;
   for ( _iIndex = 0; _iIndex <= _iLastIndex; _iIndex++ )
   {
      _X_current = _pvX->GetValue(_iIndex );
      if(tX2 == _X_current)
      {
         return _tY2 = _pvY->GetValue(_iIndex);
      }
   }


   // Values the store the closest match so far
   TypeX _X_low;
   TypeX _X_high;


   if(tX2 > _pvX->GetValue(0))
   {
      _X_low = _pvX->GetValue(0);
      _iLowIndex = 0;
   }
   else
      _X_low = -9999999;


   if(tX2 < _pvX->GetValue(0))
   {
      _X_high = _pvX->GetValue(0);
      _iHighIndex = 0;
   }
   else
      _X_high = 9999999;

   // _index represents the actual number of data points in the PDMvsPWR array
   for ( _iIndex = 0; _iIndex <= _iLastIndex; _iIndex++ )
   {
      // Assign the current value to a working variable
      _X_current = _pvX->GetValue(_iIndex );
      // If   (    the current HIGH INDEX is empty
      //       AND  the HIGH_VALUE is greater than the current value
      //      )
      if ( ( _X_current > tX2 ) && ( _X_current < _X_high ) )
      {
         _iHighIndex = _iIndex;
         _X_high = _X_current;
      }

      //      OR  (    the current value is less than the target
      //       AND  the LOW_VALUE is less than the current value
      //      )
      if (( _X_current < tX2 ) &&   ( _X_current > _X_low ))
      {
         _iLowIndex = _iIndex;
         _X_low = _X_current;
      }
   }// end for


   // if (_bSlopeFound )
   {

      // If no values are found, this is an error
      if (  ( _iHighIndex == -1)
            && ( _iLowIndex ==  -1)
         )
      {
#if !defined ( QMSL_POSIX_PORTABLE )
         throw new QMSL_CalDataManager_Exception("During interpolation on %s and %s vectors, no data has been found",_pvX->GetName(), _pvY->GetName() );
#else
         printf("During interpolation on %s and %s vectors, no data has been found",_pvX->GetName(), _pvY->GetName());
#endif
      }
      if ( _iHighIndex == -1) // If the high index is not found, then use only the low index
      {
         _iHighIndex = _iLowIndex + 1; // Assign the high index to low index + 1

         // Check for high index < size
         if ( _iHighIndex > _iLastIndex )
            _iHighIndex = _iLowIndex;

      }
      else if ( _iLowIndex == -1)
      {
         _iLowIndex = _iHighIndex - 1; // Assign the high index to low index - 1

         // Check for low index < 0
         if ( _iLowIndex < 0 )
            _iLowIndex = _iHighIndex;

      }
      else if (_iHighIndex == _iLowIndex )
      {
         _tY2 = (TypeY) _pvY->GetValue (_iHighIndex);
      }
      else
      {
         //calculate the slope using the current bin and the next one
         _tChangeY = _pvY->GetValue( _iHighIndex) - _pvY->GetValue(_iLowIndex);
         _tChangeX = _pvX->GetValue( _iHighIndex) - _pvX->GetValue(_iLowIndex);

         //find b, use either set of data but they must be from the same bin
         //using the lesser values because these may equal the target power
         _tY1 = _pvY->GetValue( _iLowIndex );
         _tX1 = _pvX->GetValue( _iLowIndex );

         _dSlope = (double) ( _tChangeY/_tChangeX );

         _tY2 = (TypeY)((_dSlope * (tX2 - _tX1)) + _tY1);
         // Now find PDM for the target power
         //_dY2 = ( _dSlope * tX2 ) + _tIntercept;

         /*
          if ( bRoundResult && (_iHighIndex != _iLowIndex ))
         {
          if(_dY2 < 0.0 ) //Checks to see if value is negative. If so you subtract .5
             _dY2 = _dY2 - .5;
          else
             _dY2 = _dY2 + .5;

         }
         // Assign to the final value, with type cast
         _tY2 = (TypeY) _dY2;
         */
         _tY2 = (TypeY) _tY2;
      }

   }  // _bIsSlopeFound


   return _tY2;
}





/**
   \brief Interpolate a single Y2 value based on X2, inside of the X and Y vectors.
         The X and Y elements must be aligned (element 2 in X corresponds to element 2 in Y,
         but the X values do not need to be in numeric order.

   \param TypeX tXValue = The X2 value for which Y2 is calculated
   \param TypeY yMin    = The lower limit of Y value
    \param TypeY yMax    = The upper limit of Y value
   \param bool bRoundResult = true if result should be rounded.

   \return Y2 value cooresponding to the X2 value, as interpolated inside X and Y vectors
*/
template <class TypeX, class TypeY > TypeY QMSL_2DVector<TypeX,TypeY>::InterpolateY2( TypeX tX2, bool bRoundResult, TypeY yMin,  TypeY yMax)
{

   // Y2 return value
   TypeY _tY2 = TypeY();

   if(yMin > yMax)//Check if min and max need swapping.
   {
      TypeY temp = yMin;
      yMin = yMax;
      yMax = temp;
   }

   _tY2 = InterpolateY2(tX2, bRoundResult);
   if(_tY2 < yMin)
      _tY2 = yMin;
   if(_tY2 > yMax)
      _tY2 = yMax;

   return _tY2;
}

template <class TypeX, class TypeY > TypeY QMSL_2DVector<TypeX,TypeY>::InterpolateY2_SlopeAveragingExtrapolation( TypeX tX2, bool bRoundResult, int iNumOfPtToAveSlope, TypeY yMin,  TypeY yMax)
{

   // Y2 return value
   TypeY _tY2 = TypeY();

   if(yMin > yMax)//Check if min and max need swapping.
   {
      TypeY temp = yMin;
      yMin = yMax;
      yMax = temp;
   }

   _tY2 = InterpolateY2_SlopeAveragingExtrapolation(tX2, bRoundResult, iNumOfPtToAveSlope);
   if(_tY2 < yMin)
      _tY2 = yMin;
   if(_tY2 > yMax)
      _tY2 = yMax;

   return _tY2;
}


/**
   \brief Interpolate an entire Y2 vector based on the values of an X2 vector,
          inside of the X and Y vectors.

   \param QMSL_Vector<TypeX> vXVector,  = X2 values for which Y2 will be calculated
   \param QMSL_Vector<TypeY> &vYVector  = reference to Y2
   \param bool bRoundResult = true if result should be rounded.

   \return none
*/
template <class TypeX, class TypeY > void QMSL_2DVector<TypeX,TypeY>::InterpolateY2vector( QMSL_Vector<TypeX> vXVector, QMSL_Vector<TypeY> &vYVector, bool bRoundResult )
{
   // Loop through the X2 vector and append values to the Y2 vector
   for ( int _iIndex = 0; _iIndex < vXVector.Size(); _iIndex++ )
   {
      vYVector.Append( InterpolateY2( vXVector[_iIndex], bRoundResult ) );
   }
}

/**
\brief Interpolate an entire Y2 vector based on the values of an X2 vector,
inside of the X and Y vectors. For data outside, use slope averaging extrapolation

\param QMSL_Vector<TypeX> vXVector,  = X2 values for which Y2 will be calculated
\param QMSL_Vector<TypeY> &vYVector  = reference to Y2
\param bool bRoundResult = true if result should be rounded.

\return none
*/
template <class TypeX, class TypeY > void QMSL_2DVector<TypeX,TypeY>::InterpolateY2vector_SlopeAveragingExtrapolation( QMSL_Vector<TypeX> vXVector, QMSL_Vector<TypeY> &vYVector,int iNumOfPtToAveSlope,  bool bRoundResult)
{
   // Loop through the X2 vector and append values to the Y2 vector
   for ( unsigned int _iIndex = 0; _iIndex < vXVector.Size(); _iIndex++ )
   {
      vYVector.Append( InterpolateY2_SlopeAveragingExtrapolation(vXVector[_iIndex], bRoundResult, iNumOfPtToAveSlope ));
   }
}