/******************************************************************************/
/**
Program: QMSL

$Id: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_Vector.h#2 $

\brief Classes to handle integer and double arrays.

 \b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/

#if !defined(_QMSL_VECTOR_H)
#define _QMSL_VECTOR_H

#include "QMSL_CalDataManager_Exception.h"

#include <vector>
using namespace std;



/*--------------------------------------------------------------------------------------*/
/**
   Class QMSL_Vector

   \brief Single Dimension vector class which includes extra features for QMSL.

*/
/*--------------------------------------------------------------------------------------*/
template<class Type > class QMSL_Vector
{
public:
   //! Constructor
   /**
      Constructor

      \brief Sets the name of the vector

      \params  string sName = text that will be associated with the vector in the future

      \return none
   */
   QMSL_Vector( string  sName ="" )
   {
      SetName( sName);
   }


   /**
      \brief Array Operator to access array elements

      \params  int iIndex = Index value of the desired element.  Zero indexed.

      \return The vector value at the specified index
   */
   Type operator[]( unsigned int iIndex )
   {
      return _data[iIndex ];
   }

   /**
      \brief Function to access value of array elements

      \params  int iIndex = Index value of the desired element.  Zero indexed.

      \return The vector value at the specified index
   */
   Type GetValue( unsigned int iIndex )
   {
      return _data[iIndex ];
   }

   /**
      \brief Function to set an element's value

      \params  int iIndex = Index value of the desired element.  Zero indexed.
      \params  Type Value = the new value for this element

      \return The vector value at the specified index
   */
   void SetValue( unsigned int iIndex, Type Value )
   {
      _data[iIndex ] = Value;
   }

   /**
      \brief Return the vector size

      \params  none

      \return Number of elements in the vector
   */
   unsigned int Size( void )
   {
      return _data.size() ;
   }

   /**
      \brief Add a data value to the list

      \params  Type value = value to add to the list

      \return none
   */
   void Append( Type value )
   {
      _data.push_back( value );
   }

   /**
      \brief Add a data value to the list, based on a comma delimited string

      \params  char* sInputString = comma delimited list of values to append

      \return none
   */
   void AppendFromString( char* sInputString);

   /**

      \brief Get the name of the array

      \params  None

      \return Return a text name associated with the vector
   */
   string  GetName( void )
   {
      return m_sName;
   }

   /**
      \brief Set the name of the array

      \params  text name associated with the vector

      \return None
   */
   void SetName( string  sName )
   {
      m_sName = sName;
   }


   /**
      \brief Get the maximum value

      \params  None

      \return Return the maximum value in a list
   */
   Type Max( void );

   /**
      \brief Get the minimum value

      \params  None

      \return Return the minimum value in a list
   */
   Type Min( void );

   /**
      \brief Get the vector, represented as a string

      \param  string & sOutput = storage area for string
      \param  string  sFormat = %d for int, %6.2f for double
      \param   string  sDelimeter = character to delimit each value

      \return None
   */
   void GetString( string& sOutput, string sFormat, string sDelimeter = "\t");

   /**
      \brief Convert the vector to slope offset format

      \params  None

      \return None
   */
   void ConvertToSlopeOffset( void );
   /**
      \brief Copy the vector values into an array

      \param  string& sOutput = storage area for string
      \param  string sFormat = %d for int, %6.2f for double
      \param   string  sDelimeter = character to delimit each value

      \return None
   */
   void GetArray( Type* pTypeArray, int& iSizeOfTypeArray)
   {

      if(_data.size() <= iSizeOfTypeArray)
         iSizeOfTypeArray = _data.size();

      for(int i=0; i< iSizeOfTypeArray; i++)
      {
         pTypeArray[i] = _data[i];
      }
   }


   /**
      \brief Check limits of vector

      \param  Type* pLowerLimit = array of lower limits
      \param  Type* pUpperLimit = array of upper limits

      \return None
   */bool CheckLimit( Type* pLowerLimit, Type* pUpperLimit)
   {

      bool result = true;
      for(int i = 0; i < _data.size(); i++)
      {
         if( ( GetValue(i) < pLowerLimit[i]) ||
               ( GetValue(i) > pUpperLimit[i]) )
         {
            result = false;
            break;
         }
      }
      return result;
   }
   void Clear()
   {
      _data.clear();
   }
   bool IsEmpty()
   {
      return _data.empty();
   }

   //! Data storage
   vector < Type > _data;


protected:
   //! Text associated with the vector
   string m_sName;

};

/*--------------------------------------------------------------------------------------*/
/**
   \brief This class implements an integer vector so that duplicate code will not appear
   when the template is invoked.
*/
/*--------------------------------------------------------------------------------------*/
class QMSL_IntVector : public QMSL_Vector< int >
{
public:
   QMSL_IntVector( string sName ) :  QMSL_Vector<int>(sName) {};
   QMSL_IntVector( void ) :  QMSL_Vector<int>("IntVector") {};
};

/*--------------------------------------------------------------------------------------*/
/**
   \brief This class implements a double vector so that duplicate code will not appear
   when the template is invoked.
*/
/*--------------------------------------------------------------------------------------*/
class QMSL_DoubleVector : public QMSL_Vector< double >
{
public:
   QMSL_DoubleVector( string sName ) :  QMSL_Vector<double>(sName) {};
   QMSL_DoubleVector( void ) :  QMSL_Vector<double>("DoubleVector") {};
};




/*--------------------------------------------------------------------------------------*/
/**
   Class QMSL_2DVector

   \brief Two Dimensional vector class which combines the use of two single dimension
          vectors (x and y) in order to provide calculation functionality .

*/
/*--------------------------------------------------------------------------------------*/
template<class TypeX, class TypeY > class QMSL_2DVector
{
public:
   /**
      Constructor for QMSL_2DVector

      \brief Allows names to be set for X and Y

      \param  QMSL_Vector<TypeX> pvX = X vector
      \param   QMSL_Vector<TypeY> pvY = Y vector
      \param  string sNameY = text that will be associated with the Y vector

      \return none
   */
   QMSL_2DVector( void )
   {
      SetXYvectors(NULL, NULL );
   }


   /**
      Constructor for QMSL_2DVector

      \brief Allows names to be set for X and Y

      \param  QMSL_Vector<TypeX> pvX = X vector
      \param   QMSL_Vector<TypeY> pvY = Y vector
      \param  string sNameY = text that will be associated with the Y vector

      \return none
   */
   QMSL_2DVector( QMSL_Vector<TypeX>* pvX , QMSL_Vector<TypeY>* pvY )
   {
      SetXYvectors(pvX, pvY );
   }

   /**
      \brief Set the pointers to the X & Y vectors

      \return None
   */
   void SetXYvectors( QMSL_Vector<TypeX>* pvX , QMSL_Vector<TypeY>* pvY)
   {
      _pvX = pvX;
      _pvY = pvY;
   }

   /**
      \brief Return pointer to X vector

      \return Return pointer to X vector
   */
   QMSL_Vector<TypeX>* GetX( void )
   {
      return _pvX;
   } ;

   /**
      \brief Return pointer to Y vector

      \return Return pointer to Y vector
   */
   QMSL_Vector<TypeY>* GetY( void )
   {
      return _pvY;
   } ;

   /**
      \brief Return the vector size

      \params  none

      \return Number of elements in the vector
   */
   unsigned int Size( void )
   {
      if(_pvX != NULL)
      {
         //The expectation is that x and y will have the same size
         return _pvX->Size() ;
      }
      else
         return 0;
   }

   /**
      \brief Interpolate a single Y2 value based on X2, inside of the X and Y vectors.

      \param TypeX tXValue = The X2 value for which Y2 is calculated.
      \param bool bRoundResult = true if result should be rounded.

      \return Y2 value cooresponding to the X2 value, as interpolated inside X and Y vectors
   */
   TypeY InterpolateY2( TypeX tXValue, bool bRoundResult = false);

   /**
      \brief Interpolate a single Y2 value based on X2, inside of the X and Y vectors
            For data outside, use slope averaging extrapolation

      \param TypeX tXValue = The X2 value for which Y2 is calculated.
      \param bool bRoundResult = true if result should be rounded.

      \return Y2 value cooresponding to the X2 value, as interpolated inside X and Y vectors
   */
   TypeY InterpolateY2_SlopeAveragingExtrapolation( TypeX tX2, bool bRoundResult, int iNumOfPtToAveSlope );
   /**
      \brief Interpolate a single Y2 value based on X2, inside of the X and Y vectors.

      \param TypeX tXValue = The X2 value for which Y2 is calculated.
      \param bool bRoundResult = true if result should be rounded.
      \param TypeY yMin = minimum allowable value for Y
      \param TypeY yMax = maximum allowable value for Y

      \return Y2 value cooresponding to the X2 value, as interpolated inside X and Y vectors
   */
   TypeY InterpolateY2( TypeX tXValue, bool bRoundResult, TypeY yMin, TypeY yMax);

   /**
      \brief Interpolate a single Y2 value based on X2, inside of the X and Y vectors.
            For data outside, use slope averaging extrapolation

      \param TypeX tXValue = The X2 value for which Y2 is calculated.
      \param bool bRoundResult = true if result should be rounded.
      \param bool iNumPtToAveSlope = Number of points to caculate the slope for extrapolation
      \param TypeY yMin = minimum allowable value for Y
      \param TypeY yMax = maximum allowable value for Y

      \return Y2 value cooresponding to the X2 value, as interpolated inside X and Y vectors
   */
   TypeY InterpolateY2_SlopeAveragingExtrapolation( TypeX tXValue, bool bRoundResult, int iNumPtToAveSlope, TypeY yMin, TypeY yMax);
   /**
      \brief Interpolate an entire Y2 vector based on the values of an X2 vector,
              inside of the X and Y vectors.

      \param QMSL_Vector<TypeX> vXVector,  = X2 values for which Y2 will be calculated
      \param QMSL_Vector<TypeY> &vYVector  = reference to Y2
      \param bool bRoundResult = true if result should be rounded.

      \return none
   */
   void InterpolateY2vector( QMSL_Vector<TypeX> vXVector, QMSL_Vector<TypeY> &vYVector, bool bRoundResult = false );
   /**
      \brief Interpolate an entire Y2 vector based on the values of an X2 vector,
              inside of the X and Y vectors. For data outside, use slope averaging extrapolation

      \param QMSL_Vector<TypeX> vXVector,  = X2 values for which Y2 will be calculated
      \param QMSL_Vector<TypeY> &vYVector  = reference to Y2
      \param bool bRoundResult = true if result should be rounded.

      \return none
   */
   void InterpolateY2vector_SlopeAveragingExtrapolation( QMSL_Vector<TypeX> vXVector, QMSL_Vector<TypeY> &vYVector,int iNumOfPtToAveSlope, bool bRoundResult = false );

private:
   TypeX GetMaxXValue ();
   TypeX GetMinXValue ();
   TypeX Get2ndMaxXValue();
   TypeX Get2ndMinXValue();
   int Get2ndMaxXValue_Index();
   int Get2ndMinXValue_Index();
   TypeY Get2ndMaxX_YValue();
   TypeY Get2ndMinX_YValue();
   int GetMaxXValueIndex();
   int GetMinXValueIndex();
   TypeY GetMaxX_YValue();
   TypeY GetMinX_YValue();



protected:

   //! Data X storage
   QMSL_Vector<TypeX>* _pvX;

   //! Data Y storage
   QMSL_Vector<TypeY>* _pvY;
};

// This includes the larger implementation code
#include "QMSL_Vector-implementation.h"

#endif // !defined(_QMSL_VECTOR_H)
