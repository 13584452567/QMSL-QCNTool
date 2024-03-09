/******************************************************************************/
/**
Program: QMSL

	$Id: //depot/HTE/QDART/QMSL/NV_Manager/QMSL_CalSpecElement.h#4 $

\brief 
	STL Inlcudes

 \b QUALCOMM  \b PROPRIETARY 

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be 
published, or disclosed to others, or used for any purpose, and the   
document shall not be duplicated in whole or in part.  

\note   
Compiler:  Microsoft Visual C++ v6.0 SP4  
*******************************************************************************/
#if !defined(_STL_INCLUDE__INCLUDED_)
#define _STL_INCLUDE__INCLUDED_

#include <float.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <utility>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <fstream>
#include <numeric>
using namespace std;


// removes duplicate elements from a container.  Iterates through the container in reverse so
// duplicates are removed from the end.
template< class C >
void remove_dups( C& collection )
{
	C::iterator it = collection.end();
	if( collection.end() != collection.begin() )
	{
		for( --it; it != collection.begin(); --it )
			if( count(collection.begin(), collection.end(), *it) > 1 )
				it = collection.erase( it );
	}
}

string operator+(const string& lhs, long rhs);
string operator+(const string& lhs, double rhs);
/*
//erases all instances of given string from source string returns result string
string eraseChars( const string& sSource, const string& toRemove );
string eraseAfterLastQuote( string sSource );
string eraseAfterNewLineChar( string sSource);
double VoltsTodB( double volts );
*/
#endif