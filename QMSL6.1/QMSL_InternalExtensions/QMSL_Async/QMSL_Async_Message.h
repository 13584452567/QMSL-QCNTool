/*!
*********************************************************************
*  $Id: //depot/HTE/QDART/QMSL/QMSL_InternalExtensions/QMSL_Async/QMSL_Async_Message.h#3 $
*
*  Project : QMSL
*
*  Package :
*
*  Company : Qualcomm Technologies Incorporated
*
*  Purpose : Declaration of class CQMSL_Async_Message
*
*********************************************************************
*/

#pragma once

#include <vector>
using namespace std;

#pragma pack(1)
struct ExtendedMessageHeader
{
   unsigned char			cmd_code;
   unsigned char			ts_type;
   unsigned char			num_args;
   unsigned char			drop_count;
   unsigned __int64		timestamp;
   unsigned short			linenumber;
   unsigned short			ss_id;
   unsigned int			ss_mask;
};
#pragma pack()

/**
* Contains a phone extended message (aka F3 message).  Responsible for parsing raw
* packet data from the phone server and creating the message text string from it.
* Manages all memory allocation and de-allocation.
*/
class CQMSL_Async_Message
{
public:
   CQMSL_Async_Message() : m_msgString(""), m_fileName(""), m_lineNumber(USHRT_MAX), m_timestamp(0), m_isOptMsg(false), m_hash(0) {}
   explicit CQMSL_Async_Message( unsigned char* data, bool isOptMsg = false );

   /**
   * Gets the parsed message string.
   * Empty string if no valid packet has been parsed yet.
   *
   * \return constant reference to the parsed message string.
   */
   const string& GetMessageString( void );

   /**
   * Gets the filename (from AMSS) from which this message originated.
   * Empty string if no valid packet has been parsed yet.
   *
   * \return constant reference to the filename.
   */
   const string& GetFileName( void );

   /**
   * Gets the line-number from the source file (from AMSS) from which this message originated.
   * USHRT_MAX if no valid packet has been parsed yet.
   *
   * \return line number
   */
   unsigned short GetLineNumber( void );

   /**
   * Gets the timestamp from which this message originated.
   * 0 if no valid packet has been parsed yet.
   *
   * \return timestamp
   */
   unsigned __int64 GetTimeStamp( void );

   unsigned short GetSSID( void );
   unsigned int GetSSMask( void );
   void GetName( string& name );

   /**
   * Returns true if the async packet that sourced this message was "optimized",
   * i.e. came from log _DIAG_OPTIMIZED_EXT_MSG_F rather than _DIAG_EXT_MSG_F
   *
   * \return bool - true for _DIAG_OPTIMIZED_EXT_MSG_F
   */
   bool IsOptimized( void )
   {
      return m_isOptMsg;
   }

   /**
   * returns the hash ID for optimized messages.
   * Only valid when IsOptimized() == true
   *
   * \return hash value, 0 if IsOptimized() == false
   */
   unsigned int GetHash( void )
   {
      return m_hash;
   }

   /**
   * Messages come through as printf-style packets (format string and args).
   * This function will return the number of arguments sent with the packet
   *
   * \return number of arguments in messag string
   */
   unsigned int GetNumArgs( void )
   {
      return m_args.size();
   }

   /**
   * Messages come through as printf-style packets (format string and args).
   * This function will return the argument at the specific index.
   * All arguments are stored as unsigned ints so they may need to be cast to the appropriate type
   *
   * \return number of arguments in message string
   */
   unsigned int GetArg( unsigned int );

private:
   /**
   * Converts a printf-style string with args into a single formatted message string
   * and stores it in m_msgString.
   *
   * \param fmt_string : the constant text and argument placeholders, like the first arg of printf()
   * \param args : the arguments to be inserted into the formatted string, like the "..." args of printf()
   */
   void GenerateMsgStr( const string& fmt_string, const vector<unsigned int>& args );

   string m_msgString;
   string m_fileName;
   unsigned short m_lineNumber;
   unsigned __int64 m_timestamp;
   unsigned short m_ssId;
   unsigned int m_ssMask;
   bool m_isOptMsg;
   unsigned int m_hash;
   vector<unsigned int> m_args;
};