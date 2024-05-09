/*!
 *********************************************************************
 *  $Id: //depot/HTE/QDART/QMSL6.1/QMSL_Core/Exception/QMSL_Exception.h#1 $
 *
 *  Project : QMSL
 *
 *  Package : Exception
 *
 *  Company : Qualcomm Technologies Incorporated
 *
 *  Purpose : Declaration of CQMSLApplicationException
 *
 *********************************************************************
<b>Version History:</b>
\verbatim
V0.1  03/13/2003  bcheadle    First Revision
V0.2  11/05/2003  bcheadle    getQMSL_ExceptionTypeAsString() added
V0.3  3/05/2006  bnorton    Remove Application Excpetion to make this class QMSL specific
\endverbatim
 *********************************************************************
 */

#if !defined(__QMSL_EXCEPTION_H)
#define __QMSL_EXCEPTION_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QMSL_Core\STL\QMSL_STL_Include.h"
#include "QMSL_Exception_ids.h"


enum QMSL_ExceptionType
{
	QMSL_GENERAL_EXCEPTION,
	QMSL_PHONE_EXCEPTION,
	QMSL_END_OF_EXCEPTION_TYPES

	/*	Removed:
	CALL_EXCEPTION,
	MEASUREMENT_EXCEPTION,
	TESTENVIRONMENT_EXCEPTION,	
	*/
};

 /**
CLASS
	CQMSL_Exception
    
	Exception class for the SUITE architecture.


USAGE
    Generally the object is created and thrown in the same statement:
		throw CQMSL_Exception( "SOME_ERROR", "Description of error" );

*/
class CQMSL_Exception  
{
public:
	CQMSL_Exception( const string& errorName, const string& errorDescription, const string& file="", int line=-1 );
	
	/*!
     * destructor
     */
	virtual ~CQMSL_Exception(){}

    /*!
     * Displays the error name and description
     */
	virtual void displayErrorMessage() const;

    /*!
     * returns the error name
     *
     * @return string  : the error name.  If the name was not found in the exception
	 *                   list, "ERR_NOT_FOUND" is returned.
     */
	virtual inline string getErrorName() const;

    /*!
     * returns the error description
     *
     * @return string  : the error description
     */
	virtual inline string getErrorDescription() const;

    /*!
     * Sets the error name.  If the provided name is not in the exception list,
	 * then the name is appended to the description and "ERR_NOT_FOUND" is set as name.
     *
     * @param errorName : the name of the error, should correspond with an entry in the
	 *                    exception list.
     */
	virtual inline void setErrorName( string errorName );

    /*!
     * Sets the error description
     *
     * @param errorDescription : the error description
     */
	virtual inline void setErrorDescription( string errorDescription );

	inline virtual void getFileInfo( string& file, int& line ) const
	{
		file = m_file;
		line = m_line;
	}

	virtual void logException( void );

	virtual QMSL_ExceptionType getQMSL_ExceptionType( void ) const;
	virtual string getQMSL_ExceptionTypeAsString( void ) const;

private:
	CQMSL_Exception(){}


    //! the name of the exception, should have an identical name in the exception list.
	string m_errorName;
	
    //! a detailed description of the exception.
	string m_errorDescription;

	string m_file;
	int m_line;

	static set< string > m_callExceptions;
	static set< string > m_measurementExceptions;
	static set< string > m_testEnvironmentExceptions;
	static set< string > m_phoneExceptions;
	static bool m_setsBuilt;

};

#endif	// __QMSL_EXCEPTION_H
