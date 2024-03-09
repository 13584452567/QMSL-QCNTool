/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/inc/QMSL_NVTool.h#16 $
 * $DateTime: 2016/04/20 09:55:02 $
 *
 * DESCRIPTION: QMSL_NVTool
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_NVTOOL_H)
#define _QMSL_NVTOOL_H

#if !defined(_WINDOWS_)
#include "windows.h"
#endif

/**
Establish whether the library is being compiled into a DLL (exporting),
or being included from a client (importing)

When the DLL is built, then QLIB_EXPORTS should be defined
*/
#ifdef QLIB_API
#undef QLIB_API
#endif

#ifdef QLIB_EXPORTS
#define QLIB_API __declspec(dllexport)
#else
#define QLIB_API __declspec(dllimport)
#endif

#if defined(QLIB_STATIC)
#undef QLIB_API
#define QLIB_API
//#define QLIB_API __cdecl
#endif


#ifdef __cplusplus
extern "C" {
#endif


   /******************************************************************************
                                    NVTool
   *******************************************************************************/

   /******************************************************************************/

   /**
   *******************************************************************************/
   QLIB_API void QLIB_NV_ConfigureCallBack( HANDLE hResourceContext, nvToolCB pNvToolCallback);

   /******************************************************************************/

   QLIB_API void QLIB_NV_LoadNameFromNVDefinitionFile( HANDLE hResourceContext, unsigned char bLoadNameFromNVDefinitionFile);

   /******************************************************************************/

   QLIB_API unsigned char QLIB_NV_SetTargetSupportMultiSIM( HANDLE hResourceContext, unsigned char bTargetSupportMultiSIM);


   /**
   Gets the current index of the SIM selected

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()
   \pCurrentSubscriptionIndex current subscription Index

   \return status
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetCurrentSubscriptionIndex( HANDLE hResourceContext, unsigned char* pCurrentSubscriptionIndex);


   /**
   Sets the current index of the SIM selected

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()
   \param iCurrentSubscriptionIndex

   \return true
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_SetCurrentSubscriptionIndex( HANDLE hResourceContext, unsigned char iCurrentSubscriptionIndex);

   /**
   Remove all the NV definitions.  The associated values are also removed.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \return true
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ClearNVDefinition(HANDLE hResourceContext);

   /******************************************************************************/
   /**
   Clear all NV Items values.  All NV items will not have any values.  The NV items definition are not removed.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \return true
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ClearNVValues(HANDLE hResourceContext);

   /******************************************************************************/
   /**
   Get the number of NV definition loaded

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNumOfDefs, the number of NV definition loaded

   \return true
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNumOfNVDefinition(HANDLE hResourceContext, int * iNumOfNVDefs);

   /******************************************************************************/
   /**
   Get the number of NV and NV Efs definition loaded

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNumOfDefs, the number of NV definition loaded

   \param iNumOfNVEfsDefs, the number of NV Efs definition loaded

   \return true
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNumOfNVEfsDefinition(HANDLE hResourceContext, int * iNumOfNVDefs, int * iNumOfNVEfsDefs);

   /******************************************************************************/
   /**
   Get the list of Efs filenames currently loaded

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param filenames, array of strings buffers, size of at least 1024 characters, caller has allocated for filenames

   \param iNumberOfFilenames, the number rows in filenames array, returns number of named copied to filenames

   \return true
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVEfsFilenames(HANDLE hResourceContext, char *filenames[1024], int * iNumberOfFilenames);


   /******************************************************************************/
   /**
   Load a NV definition xml to NVTool
   This function can be called multiple times to load different set of NV items.  (for example, one from AMSS, one from OEM)
   A NV item is uniquely identified by ID. A NV item definition will override any previous definition loaded by QLIB_NV_LoadNVDefinitionFile

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sNV_Def_XML_Path, NV definition xml file path

   \param piResultCode, Result code, See QMSL_NVTool_ResultCode_Enum

   \param piNumNVDefLoaded, the number of NV item definition added to NVTool

   \return true if result code is 0
   *******************************************************************************/

   /******************************************************************************/
   QLIB_API unsigned char QLIB_NV_LoadNVDefinitionFile(HANDLE hResourceContext, const char * sNV_Def_XML_Path,  int* piNumNVDefLoaded, int * piResultCode);

   /******************************************************************************/
   /**
   Load the custom data type dictionary from NV Def into QMSL

   The custom data type are XML elements with <DataType> tag in NVDefinition.xml

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sNV_Def_XML_Path, NV definition xml file path

   \param piResultCode, Result code, See QMSL_NVTool_ResultCode_Enum

   \param piNumNVDefLoaded, the number of NV item definition added to NVTool

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_LoadNVDataTypeDictinary(HANDLE hResourceContext, const char * sNV_Def_XML_Path, int* piNumNVDefLoaded, int * piResultCode);

   /******************************************************************************/
   /**
   Query the custom data type dictionary typeid/name value pair

   The custom data type are XML elements with <DataType> tag in NVDefinition.xml

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sDataTypeDictionaryIDNameairBuffer, The string buffer to contain type ID/Name value pair in the following format
    
	For example 108,RFNV_DATA_AMAM_LIST_TYPE;109,RFNV_DATA_AMPM_LIST_TYPE;

   \param piResultCode, Result code, See QMSL_NVTool_ResultCode_Enum

   For example, 

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDataTypeDictionaryIDNamePair(HANDLE hResourceContext, char * sDataTypeDictionaryIDNamePairBuffer,  int * iSizeOfBuffer, int * piResultCode);


   /******************************************************************************/
   /**
   Query whether the RFNV item is a Variant RF NV

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRFNVID, the RF NV ID

   \param *iResult 1 = NV is variant or 0 = NV is not variant

   \param *iResultCode 1 =  YES or 0 = No or RFNV not defined

   For example, 

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_IsRFNVIDVariant(HANDLE hResourceContext, int iRFNVID, int* iResult, int *iResultCode);


   /**

   Load NV values from source file.  QLIB_NV_LoadNVDefinition must be called before this function.
   If an NV item has 128 data elements and wasn't been defined through QLIB_NV_LoadNVDefinition,  a generic NV item definition will be automatically created.

   For example, An NV item with id 9999 will be created even if its definition hasn't been defined
   <NvItem id="9999" name="XXXX" mapping="direct" encoding="dec">
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
   </NvItem>

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sNV_Src_XML_Path, NV source xml file path

   \param piNumOfNVItemValuesLoaded, the number of NV item values loaded

   \param piResultCode, Result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_LoadNVsFromSource(HANDLE hResourceContext, const char * sNV_Src_XML_Path, int* piNumOfNVItemValuesLoaded, int* piResultCode);
   /**
   Read NV items from QCN file
   QLIB_NV_LoadNVDefiniton should be called first.
   Any NV items in QCN file that has not loaded by QLIB_NV_LoadNVDefinition will be treated as a byte stream.  A NV item definition as a byte stream will be automatically created

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sQCN_Path, QCN File path

   \param iNumOfNVitemValuesLoaded, the number of NV items loaded

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_LoadNVsFromQCN(HANDLE hResourceContext, const char *sQCN_Path, int * iNumOfNVItemValuesLoaded, int *iResultCode);
   /**
   QLIB_NV_LoadNVDefinition should be called first
   Read NV values from mobile.  The NV items to be read are from the definition list(s) loaded by QLIB_NV_LoadNVDefinition

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNumOfNVItemValuesLoaded, the number of NV item values loaded from the mobile

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_LoadNVsFromMobile(HANDLE hResourceContext, int* iNumOfNVItemValuesLoaded, int* iResultCode);

   /**
   Write NV items to board data file

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sNV_Src_Xml, NV source file path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_WriteNVsToBDF(HANDLE hResourceContext, const char *sNV_Src_Xml, int* iResultCode);

   /**
   QLIB_NV_LoadNVDefinition should be called first
   Read NV values from board data file.  The NV items to be read are from the definition list(s) loaded by QLIB_NV_LoadNVDefinition

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sBDF_Path, board data file path and name

   \param  iNumOfNVItemValuesLoaded, the number of NV item values loaded from the BDF

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_LoadNVsFromBDF(HANDLE hResourceContext, const char *sBDF_Path,  int* iNumOfNVItemValuesLoaded, int* iResultCode);

   /**
   Write NV items to QCN file

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sQCN_Path, QCN file path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_WriteNVsToQCN(HANDLE hResourceContext, const char *sQCN_Path, int *iResultCode);

   /******************************************************************************/
   /**
   Select the NV source data schema.  By default, V2 schema will be used if the API is not called.

   User should call this API before calling QLIB_WriteNVsToSource

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iSchema,
   0 = Legacy, Use <NvItem> tag to store NV or RFNV data in XML
   1 = V2,     Use <NvItemData> tag to store NV or RFNV data in XML

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_WriteNVsToSourceSchema(HANDLE hResourceContext, unsigned short iSchema);

   /******************************************************************************/
   /**
   Write NV items to source file

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sQCN_Path, NV source file path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_WriteNVsToSource(HANDLE hResourceContext, const char *sNV_Src_Xml, int *iResultCode,  unsigned char dataFromBin=0);

   /******************************************************************************/
   /**
   Write NV items/local files to TAR file and Compress TAR to GZ

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sTAR_Path, TAR file path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_WriteNVsToTAR(HANDLE hResourceContext, const char *sTAR_Path, int *iResultCode);  

   /******************************************************************************/
   /**
   Write NV items to mobile

   WARNING:

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0

   \warning If service provisioning NV items are to be written,
   QLIB_DIAG_SPC_F() should be called first to send service provisioning code(SPC) to mobile.
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_WriteNVsToMobile(HANDLE hResourceContext, int *iResultCode);

   /******************************************************************************/
   /**
   Write one  NV item to mobile

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()
   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_WriteNVItemToMobileByIndex(HANDLE hResourceContext, int iIndex, int *iResultCode);

   /******************************************************************************/
   /**
   Write one  NV item to mobile

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()
   \param iNVId NV enumeration

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_WriteNVItemToMobileByNVID(HANDLE hResourceContext, int iNVId, int *iResultCode);

   /******************************************************************************/
   /**
   Read signle  NV item from mobile to QMSL NVTool memory

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId NV enumeration

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0

   \warning This API can only be used with other QLIB_NV_XXX APIs togther.  The NV Data is stored by QMSL NVTool memory
   This API is currently used by QRCT NV Manager
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ReadNVItemFromMobileByNVID(HANDLE hResourceContext, int iNVId, int *iResultCode);
   /******************************************************************************/
   /**
   Write one EFS item file to mobile

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param filename filename including path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \warning This API can only be used with other QLIB_NV_XXX APIs togther.  The EFS Data is stored by QMSL NVTool memory
   This API is currently used by QRCT NV Manager

   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_WriteNVItemToMobileByEfsFilename(HANDLE hResourceContext, char* filename, int* iResultCode);
   /******************************************************************************/
   /**
   Read EFS item file from mobile

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param filename filename including path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \warning This API can only be used with other QLIB_NV_XXX APIs togther.  The EFS Data is stored by QMSL NVTool memory
   This API is currently used by QRCT NV Manager

   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ReadNVItemFromMobileByEfsFilename(HANDLE hResourceContext, char* filename, int* iResultCode);
   /******************************************************************************/
   /**
   Get the NV definition string length by index.  A NV definition string is defined as <NV item name>:<id>:<format>

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex [in], should be between 0 to  GetNumOfNVDefinition() - 1

   \param iNVDefStrLength, the string length of the definition

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \example: "NV_PREF_MODE:10:u8,u16" , the length is 22

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDefinitionStringLengthByIndex(HANDLE hResourceContext, int iIndex, int* iNVDefStrLength, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV definition string by index.  A NV definition string is defined as <NV item name>:<id>:<format>

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param sNVDefintion [in/out], the NV definition string buffer

   \param iSizeOfNVDef [in], the size of NV definition string buffer

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \note call QLIB_NV_GetNVDefinitionStringLengthByIndex to determine the size of buffer first.

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDefinitionByIndex(HANDLE hResourceContext, int iIndex, char* sNVDefinition, int iSizeOfNVDef, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV definition field name string (NULL terminated) by index.  The string is comman delimited

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param sNVDefFieldName [in/out], the buffer to store the field name string

   \param iSzOfNVDefFieldName [in], the size of sNVDefFieldName

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \note  call QLIB_NV_GetNVDefinitionFieldNamesLength to find out the string length first

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDefinitionFieldNames(HANDLE hResourceContext, int iIndex, char* sNVDefFieldName, int iSzOfNVDefFieldName, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV definition field name string length by index.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param iNVDefFieldNameLength [in/out], the field name string length

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDefinitionFieldNamesLength(HANDLE hResourceContext, int iIndex, int* iNVDefFieldNameLength, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV definition field description string (NULL terminated) by index.  The string is comma delimited

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param sNVDefFieldDescription [in/out], the buffer to store the field description string

   \param iSzOfNVDefFieldDescription [in], the size of sNVDefFieldDescription

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \note  call QLIB_NV_GetNVDefinitionFieldDescriptionsLength to find out the string length first

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDefinitionFieldDescriptions(HANDLE hResourceContext, int iIndex, char* sNVDefFieldDescription, int iSzOfNVDefFieldDescription, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV definition field description string length by index.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param iNVDefFieldDescriptionLength [in/out], the field description string length

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDefinitionFieldDescriptionsLength(HANDLE hResourceContext, int iIndex, int* iNVDefFieldDescriptionLength, int *iResultCode);

   /******************************************************************************/
   /**
   Get the field names of a customer data type.  The field names is a comma delimited string

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sCustomTypeName, A null terminated custom data type name string

   \param iNVDefFieldNameLength [in/out], the field name string length

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \example

   <DataType name="custom">
   <Member name="field1" type="u8"></Member>
   <Member name="field2" type="u16"></Member>
   </DataType>

   Calling this function with "custom" will return "field1,field2"

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDataTypeDefinitionFieldNames(HANDLE hResourceContext, char* sCustomTypeName,char * sCustomTypeFileNames, int iNVDataTypeFielNamesStrLength, int *iResultCode);

   /******************************************************************************/
   /**
   Get the string length of the field names of a customer data type.  The field names is a comma delimited string

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sCustomTypeName, A null terminated custom data type name string

   \param iNVDataTypeFielNamesStrLength [in/out], the field name string length

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \example

   <DataType name="custom">
   <Member name="field1" type="u8"></Member>
   <Member name="field2" type="u16"></Member>
   </DataType>

   Calling this function with "custom" will return 11 (strlen("field1,field2"))

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_GetNVDataTypeDefinitionFieldNamesStringLength(HANDLE hResourceContext, char* sCustomTypeName, int* iNVDataTypeFielNamesStrLength, int *iResultCode);
   /******************************************************************************/
   /**
   Get the string length of the custom data type definition string

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sCustomTypeName, A null terminated custom data type name string

   \param iNVDataTypeDefStrLength [in/out], the type definition string length

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \example

   <DataType name="custom">
   <Member name="field1" type="u8"></Member>
   <Member name="field2" type="u16"></Member>
   </DataType>

   Call this function with "custom" will return 6 (strlen("u8,"u16"))

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDataTypeDefinitionStringLength(HANDLE hResourceContext, char* sCustomTypeName,int* iNVDataTypeDefStrLength, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV custom data type definiton by customer type name.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sCustomTypeName, Custom Type name , the "name" attribute value in <DataType> tag

   \param sNVDefintion, the data type definition string for this custom type buffer

   \param iSizeOfNVDef, the data type definition string buffer size

   \param iResultCode, the result code,See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVDataTypeDefinition(HANDLE hResourceContext, char* sCustomTypeName, char* sNVDefinition, int iSizeOfNVDef, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV definition from <EFSItemFiles> tag in NVdefintion.xml

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param filename [in], EFS file name

   \param sNVDefinition, the data type definition string

   \param iSizeOfNVDef, the data type definition string size

   \param iResultCode, the result code,See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_GetNVDefinitionByEfsFilename(HANDLE hResourceContext, char* filename, char* sNVDefinition, int iSizeOfNVDef, int* iResultCode);

   /******************************************************************************/
   /**
   Get the NV definition field names from <EFSItemFiles> tag in NVdefintion.xml

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param filename [in], EFS file name

   \param sNVDefinition, the field names of the data definition string

   \param iSizeOfNVDef, the field names of the data definition string size

   \param iResultCode, the result code,See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_GetNVDefinitionFieldNamesByEfsFileName(HANDLE hResourceContext, char* filename, char* sNVDefinition, int iSizeOfNVDef, int* iResultCode);

   /******************************************************************************/
   /**
   Get the NV definition field descriptions from <EFSItemFiles> tag in NVdefintion.xml

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param filename [in], EFS file name

   \param sNVDefinition, the field descriptions of the data definition string

   \param iSizeOfNVDef, the field descriptions of the data definition string size

   \param iResultCode, the result code,See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_GetNVDefinitionFieldDescriptionsByEfsFileName(HANDLE hResourceContext, char* filename, char* sNVDefinition, int iSizeOfNVDef, int* iResultCode);
   /******************************************************************************/
   /**
   Get the NV value byte stream by index

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param iNVValueBuffer, the NV value buffer

   \param iSzOfBuffer, size of iNVValueBuffer, the actual size of byte stream is returned

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVValueByteStreamByIndex(HANDLE hResourceContext, int iIndex, unsigned char *iNVValueBuffer, int* iSzOfBuffer, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV value string by index

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param iNVValueStrBuffer, the NV value buffer

   \param iSzOfStrBuffer, size of iNVValueStrBuffer

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVValueStringByIndex(HANDLE hResourceContext, int iIndex , char *iNVValueStrBuffer, int* iSzOfStrBuffer, int iMapping, int iEncoding, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV value string length by index

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param iNVValueStringLength, the NV value buffer string legnth

   \param iSzOfStrBuffer, size of iNVValueStrBuffer

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVValueStringLengthByIndex(HANDLE hResourceContext, int iIndex, int* iNVValueStringLength, int iMapping, int iEncoding, int* iResultCode);
   /******************************************************************************/
   /**
   Get the NV value string by Efs filename

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param filename, Full Efs filename

   \param iNVValueStrBuffer, the NV value buffer

   \param iSzOfStrBuffer, size of iNVValueStrBuffer

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVValueStringByEfsFilename(HANDLE hResourceContext, char* filename, char *iNVValueStrBuffer, int* iSzOfStrBuffer, int iMapping, int iEncoding, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV value byte stream by NV ID

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId NV enumeration

   \param iNVValueBuffer, the NV value buffer

   \param iSzOfBuffer, size of iNVValueBuffer, the actual size of byte stream is returned

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVValueByteStreamByNVID(HANDLE hResourceContext, int iNVId, unsigned char *iNVValueBuffer, int* iSzOfBuffer, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV value string by NV ID

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId NV enumeration

   \param iNVValueStrBuffer, the NV value buffer

   \param iSzOfStrBuffer, size of iNVValueStrBuffer

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GetNVValueStringByNVID(HANDLE hResourceContext, int iNVId , char *iNVValueStrBuffer, int* iSzOfStrBuffer, int iMapping, int iEncoding, int *iResultCode);

   /******************************************************************************/
   /**
   Get the NV value string length by NV ID

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId NV enumeration

   \param iNVValueStringLength, the NV value buffer length required

   \param iSzOfStrBuffer, size of iNVValueStrBuffer

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/

   QLIB_API unsigned char QLIB_NV_GetNVValueStringLengthByNVID(HANDLE hResourceContext, int iNVId , int* iNVValueStringLength, int iMapping, int iEncoding, int *iResultCode);
   /******************************************************************************/
   /**
   Set the NV value stored in a byte array by index

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param iNVValueBuffer, the NV value buffer

   \param iSzOfBuffer, size of iNVValueBuffer

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_SetNVValueByteStreamByIndex(HANDLE hResourceContext, int iIndex , unsigned char *iNVValueBuffer, int iSzOfBuffer, int *iResultCode);

   /******************************************************************************/
   /**
   Set the NV value stored in a string by index.  The NULL character terminated string should be in direct mapping and dec encoding

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to  GetNumOfNVDefinition() - 1

   \param iNVValueStr, the NV value string

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_SetNVValueStringByIndex(HANDLE hResourceContext, int iIndex , char *iNVValueStr, int iMapping, int iEncoding, int *iResultCode);

   /******************************************************************************/
   /**
   Set the NV value stored in a string by Efs filename.  The NULL character terminated string should be in direct mapping and dec encoding

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param filename, full Efs filename

   \param iNVValueStr, the NV value string

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_SetNVValueStringByEfsFilename(HANDLE hResourceContext, char* filename, char *iNVValueStr, int iMapping, int iEncoding, int* iResultCode);

   /******************************************************************************/
   /**
   Set the NV value stored in a byte array by NV ID.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId, NV enumeration

   \param iNVValueBuffer, the NV value byte array

   \param iSzOfBuffer, the number of byte in iNVValueBuffer

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_SetNVValueByteStreamByNVID(HANDLE hResourceContext, int iNVId , unsigned char *iNVValueBuffer, int  iSzOfBuffer, int *iResultCode);

   /******************************************************************************/
   /**
   Set the NV value stored in a string by NV ID.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId, NV enumeration

   \param iNVValueStr, the NULL character terminated value string

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_SetNVValueStringByNVID(HANDLE hResourceContext, int iNVId , char *iNVValueStr, int iMapping, int iEncoding, int *iResultCode);

   /******************************************************************************/
   /**
   Set the NV value stored in a string by NV ID for variant NV item types.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId, NV enumeration

   \param iNVValueStr, the NULL character terminated value string

   \param iIndex, Set this value to 0

   \param iMapping (direct = 0, byteStream = 1)

   \param iEncoding (dec = 0, hex = 1)

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_SetVariantNVValueStringByNVID(HANDLE hResourceContext, int iNVId, char *iNVValueStr, int iIndex, int iMapping, int iEncoding, int* iResultCode);

   /******************************************************************************/
   /**
    Insert a data type fragrement into a Variant RF NV.  The data fragment will be filled with zero

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId, RF NV enumeration ID.  The RFNV should be of type variant

   \param iIndex, Set this value to 0

   \param iPosition, The position in the variant NV list to insert the data.  Position 0 is the first data element.  Position (-1) to append to the end, 

   \param iDataTypeID, the DataType's typeid attribute value in NvDefinition.xml

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_InsertDataTypeIntoVariantNV(HANDLE hResourceContext, int iNVId, int iIndex, int iPosition, unsigned short iDataTypeID, int* iResultCode);


   /******************************************************************************/
   /**
    Remove a data type fragrement from a Variant RF NV.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId, RF NV enumeration ID.  The RFNV should be of type variant

   \param iIndex, Set this value to 0

   \param iPosition, The position in the variant NV list to insert the data.  Position 0 is the first data element.  Position (-1) to append to the end, 

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_RemoveDataTypeFromVariantNV(HANDLE hResourceContext, int iNVId, int iIndex, int iPosition, int* iResultCode);

   QLIB_API unsigned char QLIB_NV_Variant_CopyData(HANDLE hResourceContext, int iSourceNVId, int iSourceNVindex, int* iIndexList, int iSzIndexList, unsigned char iAction, int iDestNVId, int iDestNVindex, int iDestPosition, int* iResultCode);

   /******************************************************************************/
   /**
   Clear NV value by index

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iIndex, should be between 0 to GetNumOfNVDefinition() - 1

   \param iResultCode, Result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ClearNVValueByIndex(HANDLE hResourceContext, int iIndex, int* iResultCode);

   /******************************************************************************/
   /**
   Clear NV value by NV ID

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNVId, NV enumeration

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ClearNVValueByNVID(HANDLE hResourceContext, int iNVId, int* iResultCode);

   /******************************************************************************/
   /**
   Clear the write filter

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ClearWriteFilters(HANDLE hResourceContext);

   /******************************************************************************/
   /**
   Load write filter.  The write filter controls the NV items that can be written to XML, QCN or mobile

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFilter_XML_Path, Write filter definition (XML) file path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_LoadWriteFilter(HANDLE hResourceContext, const char * sFilter_XML_Path,  int* iResultCode);

   /******************************************************************************/
   /**
   Clear the read filter.  All the defined NV items (loaded from QLIB_NV_LoadNVDefinitionFile) will be read from mobile

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_ClearReadFilters(HANDLE hResourceContext);


   /******************************************************************************/
   /**
   Load read filter.  The read filter controls the NV items that can be read from XML, QCN or mobile

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFilter_XML_Path, read filter definition (XML) file path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_LoadReadFilter(HANDLE hResourceContext, const char * sFilter_XML_Path,  int* iResultCode);

   /******************************************************************************/
   /**
   Compare the two QCN files.   For NV items with multiple entries/indices, such as NAM based NV items, the function will
   only compare the data at Index 0

   It cannot compare EFS, PRL content in the QCN.

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sQCN1Path, 1st QCN file path

   \param sQCN2Path, 2nd QCN file path

   \param sHTMLPath, diff result path.  The diff output is stored in a HTML file.

   \param iResultCode, the result code

   \note Call QLIB_NV_LoadNVDataTypeDictinary and QLIB_NV_LoadNVDefinitionFile first

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_QCN_Diff(HANDLE hResourceContext, const char *sQCN1Path, const char *sQCN2Path, const char *sHTMLPath, int *iResultCode);

   /******************************************************************************/
   /**
   Generate a QDF formatted file.  A QDF file(text) contains NV item definitions.  The QDF is used by RF NV Manager to manage NV items.
   The NV items definition must be loaded by QLIB_NV_LoadNVDefinitionFile().
   Call QLIB_NV_LoadReadFilter prior to this function to filter the NV definition generated.

   This is a typical sequence to call QLIB_NV_GenerateQDF

   QLIB_NV_LoadNVDefinition
   QLIB_NV_LoadReadFilter (optional)
   QLIB_NV_Generate QDF

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sQDFPath, QDF file path

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_GenerateQDF(HANDLE hResourceContext, const char *sQDFPath, int *iResultCode);

   /******************************************************************************/
   /**
   Generate a NV filter based on the NV ID loaded by QLIB_NV_LoadNVDefinition API

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sFilterPath, Filter file to be created

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0,

   \warining QLIB_NV_LoadDefintion should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_CreateNVFilter(HANDLE hResourceContext, const char *sFilterPath, int *iResultCode);

   /******************************************************************************/
   /**
   Generate a NV filter based on the NV ID NOT loaded by QLIB_NV_LoadNVDefinition API

   For example, if NV item 0 to 3000 is loaded by QLIB_NV_LoadNVDefinition.  A filter file
   with NV ID between 3001 to iMaxNVId will be created

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param sCompFilterPath, Filter file to be created

   \param iMaxNVId, The maximum NV enuemration for the filter

   \param iResultCode, the result code, See QMSL_NVTool_ResultCode_Enum

   \return true if result code is 0

   \warining QLIB_NV_LoadDefintion should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_NV_CreateComplementNVFilter(HANDLE hResourceContext, unsigned short iMaxNVId, const char *sCompFilterPath, int *iResultCode);


   /******************************************************************************/
   /**
   API for tlv way to access QLIB_FTM_WLAN 

   \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   \param opCode, opCode for actions
   \param pKey, parameter key
   \param pData, parameter data

   \return true if result code
   *******************************************************************************/
   QLIB_API char QLIB_FTM_WLAN_TLV_Create(HANDLE hResourceContext, unsigned char opCode);

   QLIB_API char QLIB_FTM_WLAN_TLV_AddParam(HANDLE hResourceContext, char *pKey, char *pData);

   QLIB_API char QLIB_FTM_WLAN_TLV_Complete(HANDLE hResourceContext);

   QLIB_API char QLIB_FTM_WLAN_TLV_GetRspParam(HANDLE hResourceContext, char *pKey, char *pData);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_NVTOOL_H)
