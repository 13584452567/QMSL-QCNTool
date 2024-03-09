/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Projects/QMSL_NVTool/QMSL_NVTool.cpp#16 $
 * $DateTime: 2016/06/14 10:10:39 $
 *
 * 
 ******************************************************************************
 *
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#include "stdafx.h"
#include "QMSL_inc/QLib.h"
#include "QMSL_inc/QLib_Defines.h"
//#include <sstream>

// Error Code Section
const int NVTOOL_NO_ERROR = 0;
const int NVTOOL_ERROR_NO_ARGUMENT = -1;
const int NVTOOL_ARGUMENT_INVALID  = -2;
const int NVTOOL_FAILURE_IN_QMSL_API = 3;


void NvToolCallBack
   (HANDLE hQMSLContext,
   unsigned char  iSubscriptionId,
   const char     *sRFNVid_EFSPath,//Change to char so that the efs filename is also shown
   unsigned short iNVToolFuncEnum,
   unsigned short iEvent,
   unsigned short iProgress)
{
   printf("Subscription ID:%u, %s, Function:%d, Event:%d, <NV_Process_Progress: %d%s>\n", iSubscriptionId, sRFNVid_EFSPath, iNVToolFuncEnum, iEvent, iProgress, "%");
}


using namespace std;

// print the usage of QMSL_NVTool
void PrintUsage();
// Parse command argument
void ParseArguments();
// Check whether there are enough arguments
bool CheckArguments();
// Dispatch command
bool DispatchCommand();
// Extract file name from argument 
// eg "-def="c:\temp\abc.txt"" filename="c:\temp\abc.txt"
string ExtractFileName(string sHeader, int size = 5);
// Extract COM port number
int ExtractCOMPort(string argument);
// Extract sleep counter for QPHONEMS
int ExtractSpeed(string argument);
vector<int> ExtractNVIDList(string agrument);
vector<int> ExtractDataTypeList(string agrument);
// Connect server
void ConnectServer();
// Disconnect Server
void DisconnectServer();

bool Src2Qcn(); //read NV values from NV source xml and write to QCN\n");
bool Src2Ph();  //read NV values from NV source xml and write to mobile\n");
bool Ph2Src();  //read NV values from mobile and write to NV source xml\n");
bool Src2BDF();  //read NV values from NV source xml and write to board data file\n");
bool BDF2Src();  //read NV values from board data file and write to NV source xml\n");
bool Ph2BDF();  //read BDF from phone and write to board data file\n");
bool BDF2Ph();  //read board data file and write to phone\n");
bool Ph2Qcn();  //read NV values from mobile and write to QCN\n");
bool Qcn2Ph();   //read NV values from QCN and write to mobile\n");
bool Qcn2Src();   //read NV values from QCN and write to NV source xml\n");
bool DiffQcns(); // diff QCN files;
bool CreateNVFilter(); // Create NV filter based on NV Item Id loaded by NV Definition.xml 
bool CreateCompNVFilter(); // Create NV filter for any NV Item Id NOT loaded by NV Definition.xml 
bool Qcn2Qcn();
bool Src2Tar();
bool VariantNV2Src();  // Write Variant NV (filled with zero) to a source file
bool DevTest();          // Used for development and test

bool LoadReadFilter();      // Load read filter XML
bool LoadWriteFilter();      // Load write filter XML
bool LoadNVDefinitionFile(); // Load NV definition file
bool LoadSrcFiles();      // Load NV Source Files
bool LoadQCNFiles();      // Load QCN files
bool LoadNVsFromMobile();   // Load NVs from mobile
bool LoadBDFFromMobile();   // Load BDF from mobile
bool LoadNVsFromBoardDataFile();   // Load NVs from board data file

bool SaveBDFToMobile();      // Save BDF to mobile
bool SaveNVsToMobile();      // Save NVs to mobile
bool SaveNVsToQCN();      // Save NVs to QCN
bool SaveNVsToSrc(bool dataFromBin);      // Save NVs to Source
bool SaveNVsToQCNOut();      // Save NVs to QCNOut File
bool SaveNVsToTAR();        //Save NVs to TAR File
bool SaveNVsToBoardDataFile();    //Save NVs to board data file


// A list of arguments separated by space
vector<string> gArgumentList;
// NV Definition files from argument list
vector<string> gDefFileList;
// NV source file(s) from argument list
vector<string> gSrcFileList;
// board data file(s) from argument list
vector<string> gBDFileList;
// Qcn file(s) from argument list
vector<string> gQcnFileList;
// Tar file(s) from argument list
vector<string> gTarFileList;
// Read filter from argument list
vector<string> gReadFilterList;
// Write filter from argument list
vector<string> gWriteFilterList;
// QCNs diff output file path;
vector<string> gDiffOutList;
// Filter file to be created with -filter or -compfilter option
vector<string> gFilterFileList;
// File list to store the qcn file to be written for QCN2QCN option
vector<string> gQCNOutFileList;
// NV ID list for generating variant NV
vector<int> gNVIDList; 
// Datatype ID list for generating variant NV
vector<int> gDataTypeIDList; 

// COM port to be used
int gComPort = -1;
// Sleep counter
unsigned long gSpeed = 1;
// QMSL Handle
HANDLE gQMSL;
// Use QPST for QLIB
unsigned char bQPST = 0;
// QMSL log filename;
string gQMSLLog;
// Install callback function
unsigned char bUseCallBack = 0;
// Sync EFS (eMMC)
unsigned char bSyncEFS = 0;

bool gTargetSupportMultiSim = false;

// Different actions to be taken
enum {
   SRC2QCN = 0,
   SRC2PH  = 1,
   PH2QCN  = 2,
   PH2SRC  = 3,
   QCN2PH  = 4,
   QCN2SRC = 5,
   DIFFQCNS = 6,
   FILTER   = 7,
   COMPFILTER = 8,
   QCN2QCN = 9,
    SRC2TAR = 10,
    BDF2SRC = 11,
    SRC2BDF = 12,
    PH2BDF = 13,
    BDF2PH = 14,
    VARIANTNV2SRC = 15,
    DEVTEST  = 16,
   UNKNOWN = 17
} cmdAction;

int gCmdAction = UNKNOWN;

int _tmain(int argc, _TCHAR* argv[])
{
   unsigned int _i = 0;
   int rc = NVTOOL_NO_ERROR; // return code;

   // too few arguments
   if(argc == 1)
   {   
      PrintUsage();
      return rc = NVTOOL_ERROR_NO_ARGUMENT;
   };

   // make the argument list
   for(_i = 0; _i < (unsigned int)argc; _i++)
   {   
      string argu = argv[_i];
      gArgumentList.push_back(argu);
   }   
   
   ParseArguments();

   unsigned long _timeBegin = ::GetTickCount();
   if(CheckArguments() == true)
   {
      ConnectServer();

      if(DispatchCommand()!= true)
      {
         printf("Dispatch Command failed\n");
		 rc = NVTOOL_FAILURE_IN_QMSL_API;
      }
   
      DisconnectServer();
   }
   else
   {
      printf("Failed to launched any action. Check argument list!\n");
	  return rc = NVTOOL_ARGUMENT_INVALID;
   }

   printf("Total Execution Time: %d ms\n", ::GetTickCount() - _timeBegin); 
   return rc;
}

void ParseArguments()
{
   string action = gArgumentList[1];
   
   size_t _position = 0;
   if((_position = action.find("-src2qcn")) == 0)
      gCmdAction = SRC2QCN;
   else if((_position = action.find("-src2ph")) == 0)
      gCmdAction = SRC2PH;
   else if((_position = action.find("-ph2qcn")) == 0)
      gCmdAction = PH2QCN;
   else if((_position = action.find("-ph2src")) == 0)
      gCmdAction = PH2SRC;
   else if((_position = action.find("-qcn2ph")) == 0)
      gCmdAction = QCN2PH;
   else if((_position = action.find("-qcn2src")) == 0)
      gCmdAction = QCN2SRC;
   else if((_position = action.find("-diffqcns")) == 0)
      gCmdAction = DIFFQCNS;
   else if((_position = action.find("-filter")) == 0)
      gCmdAction = FILTER;
   else if((_position = action.find("-compfilter")) == 0)
      gCmdAction = COMPFILTER;
   else if((_position = action.find("-qcn2qcn")) == 0)
      gCmdAction = QCN2QCN;
    else if((_position = action.find("-src2tar")) == 0)
      gCmdAction = SRC2TAR;
    else if((_position = action.find("-bdf2src")) == 0)
      gCmdAction = BDF2SRC;
    else if((_position = action.find("-src2bdf")) == 0)
      gCmdAction = SRC2BDF;
    else if((_position = action.find("-bdf2ph")) == 0)
      gCmdAction = BDF2PH;
    else if((_position = action.find("-ph2bdf")) == 0)
      gCmdAction = PH2BDF;
    else if((_position = action.find("-variantnv2src")) == 0)
      gCmdAction = VARIANTNV2SRC;
    else if((_position = action.find("-devtest")) == 0)
      gCmdAction = DEVTEST;
   else
      gCmdAction = UNKNOWN;
   
   unsigned int _i = 0;
   for(_i = 2; _i < gArgumentList.size(); _i++)
   {
      string argument = gArgumentList[_i];
      if((_position = argument.find("-def")) == 0)
      {
         string fileName = ExtractFileName(argument);
         gDefFileList.push_back(fileName);
      }
      else if((_position = argument.find("-src")) == 0)
      {
         string fileName = ExtractFileName(argument);
         gSrcFileList.push_back(fileName);
      }
      else if((_position = argument.find("-bdf")) == 0)
      {
         string fileName = ExtractFileName(argument);
         gBDFileList.push_back(fileName);
      }
      else if((_position = argument.find("-qcn")) == 0)
      {
         string fileName = ExtractFileName(argument);
         gQcnFileList.push_back(fileName);
      }
      else if((_position = argument.find("-tar")) == 0)
      {
         string fileName = ExtractFileName(argument);
         gTarFileList.push_back(fileName);
      }
      else if((_position = argument.find("-com")) == 0)
      {
         gComPort = ExtractCOMPort(argument);
      }
      else if((_position = argument.find("-speed")) == 0)
      {
         gSpeed = ExtractSpeed(argument);
      }
      else if((_position = argument.find("-qpst")) == 0)
      {
         bQPST = 1;
      }
      else if((_position = argument.find("-syncefs")) == 0)
      {
         bSyncEFS = 1;
      }
      else if((_position = argument.find("-log")) == 0)
      {
         string fileName = ExtractFileName(argument);
         gQMSLLog = fileName;
      }
      else if((_position = argument.find("-cb")) == 0)
      {
         bUseCallBack = 1;
      }
      else if((_position = argument.find("-rdf")) == 0)
      {
         string fileName = ExtractFileName(argument);
         gReadFilterList.push_back(fileName);
      }
      else if((_position = argument.find("-wtf")) == 0)
      {
         string fileName = ExtractFileName(argument);         
         gWriteFilterList.push_back(fileName);
      }
      else if((_position = argument.find("-diffout")) == 0)
      {
         string fileName = ExtractFileName(argument, 9);         
         gDiffOutList.push_back(fileName);
      }
      else if((_position = argument.find("-filterPath")) == 0)
      {
         string fileName = ExtractFileName(argument, 12);
         gFilterFileList.push_back(fileName);
      }
      else if((_position = argument.find("-outqcn")) == 0)
      {
         
         string fileName = ExtractFileName(argument, 8);
         gQCNOutFileList.push_back(fileName);
      }
      else if((_position = argument.find("-multisim")) == 0)
      {
         gTargetSupportMultiSim = true;
         argument.erase(0, 10);
      }
      else if((_position = argument.find("-nv")) == 0)
      {
          gNVIDList = ExtractNVIDList(argument);
      }
      else if((_position = argument.find("-datatype")) == 0)
      {
          gDataTypeIDList = ExtractDataTypeList(argument);
      }
   }
}


bool CheckArguments()
{
   bool _bResult = false;
   if(gCmdAction == SRC2QCN)
   {
      if((gDefFileList.size() >= 0) && (gSrcFileList.size() >= 1) && (gQcnFileList.size() == 1))
         _bResult = true;
   }
   else if(gCmdAction == SRC2PH)
   {
      if((gDefFileList.size() >= 1) && (gSrcFileList.size() >= 1) && (gComPort != -1))
         _bResult = true;
   }
   else if(gCmdAction == PH2QCN)
   {
      if((gDefFileList.size() >= 1) && (gQcnFileList.size() == 1) && (gComPort != -1))
         _bResult = true;
   }
   else if(gCmdAction == PH2SRC)
   {
      if((gDefFileList.size() >= 1) && (gSrcFileList.size() == 1) && (gComPort != -1))
         _bResult = true;   
   }
   else if(gCmdAction == QCN2PH)
   {
      if((gQcnFileList.size() == 1) && (gComPort != -1))
         _bResult = true;
   }
   else if(gCmdAction == QCN2SRC)
   {
      if((gQcnFileList.size() == 1) && (gSrcFileList.size() == 1) && (gDefFileList.size() >= 0))
         _bResult = true;
   }
   else if(gCmdAction == BDF2SRC || gCmdAction == SRC2BDF)
   {
      if((gBDFileList.size() == 1) && (gSrcFileList.size() == 1) && (gDefFileList.size() >= 0))
         _bResult = true;
   }
   else if(gCmdAction == BDF2PH || gCmdAction == PH2BDF)
   {
      if(gBDFileList.size() == 1)
         _bResult = true;
   }
   else if(gCmdAction == DIFFQCNS)
   {
      if((gQcnFileList.size() == 2) && (gDefFileList.size() >= 0) && (gDiffOutList.size() == 1))
         _bResult = true;
   }
   else if(gCmdAction == FILTER)
   {
      if((gFilterFileList.size() == 1) && (gDefFileList.size() >= 1))
         _bResult = true;
   }
   else if(gCmdAction == COMPFILTER)
   {
      if((gFilterFileList.size() == 1) && (gDefFileList.size() >= 1))
         _bResult = true;   
   }
   else if(gCmdAction == QCN2QCN)
   {
      if((gQcnFileList.size() >= 1) && (gQCNOutFileList.size()==1 ))
         _bResult = true;   
   
   }
   else if (gCmdAction == SRC2TAR)
   {
      if((gDefFileList.size() >= 1) && (gSrcFileList.size() >= 1) && (gTarFileList.size() >= 1))
         _bResult = true;
   }
   else if (gCmdAction == VARIANTNV2SRC)
   {
       if((gDefFileList.size() >= 1)&&(gSrcFileList.size() >= 1))
           _bResult = true;
   }
   else if (gCmdAction == DEVTEST)
   {
       if(gDefFileList.size() >= 1)
            _bResult = true;
   }
   return _bResult;

}

bool DispatchCommand()
{
   bool bResult = false;
   if(bUseCallBack)
   {
      QLIB_NV_ConfigureCallBack(gQMSL, &NvToolCallBack);
   }
     
    if (gCmdAction != SRC2TAR)
    {
        // preserve the names for any converstion to XML
        // In SRC2TAR case, we don't need the name.  The NV name is not in a tar file
        QLIB_NV_LoadNameFromNVDefinitionFile(gQMSL, true);
    }    
    QLIB_NV_SetTargetSupportMultiSIM(gQMSL, gTargetSupportMultiSim);
    QLIB_NV_SetCurrentSubscriptionIndex(gQMSL, 0);

   if(gCmdAction == SRC2QCN)
      bResult = Src2Qcn();
   else if(gCmdAction == SRC2PH)
      bResult = Src2Ph();
   else if(gCmdAction == PH2QCN)
      bResult = Ph2Qcn();
   else if(gCmdAction == PH2SRC)
      bResult = Ph2Src();
   else if(gCmdAction == BDF2SRC)
      bResult = BDF2Src();
   else if(gCmdAction == SRC2BDF)
      bResult = Src2BDF();
   else if(gCmdAction == BDF2PH)
      bResult = BDF2Ph();
   else if(gCmdAction == PH2BDF)
      bResult = Ph2BDF();
   else if(gCmdAction == QCN2PH)
      bResult = Qcn2Ph();
   else if(gCmdAction == QCN2SRC)
      bResult = Qcn2Src();
   else if(gCmdAction == DIFFQCNS)
      bResult = DiffQcns();
   else if(gCmdAction == FILTER)
      bResult = CreateNVFilter();
   else if(gCmdAction == COMPFILTER)
      bResult = CreateCompNVFilter();
   else if(gCmdAction == QCN2QCN)
      bResult = Qcn2Qcn();
   else if(gCmdAction == SRC2TAR)
      bResult = Src2Tar();
   else if(gCmdAction == VARIANTNV2SRC)
       bResult = VariantNV2Src();
   else if(gCmdAction == DEVTEST)
       bResult = DevTest();
   else
      PrintUsage();

   return bResult;
}


void PrintUsage()
{
   printf("USAGE:\n");
   printf("QMSL_NVTool [command] [arguments] [options]\n");
   printf("COMMAND:\n");
   printf("\t-src2qcn  read NV values from NV source xml and write to QCN\n");
   printf("\t-src2ph   read NV values from NV source xml and write to mobile\n");
   printf("\t-ph2src   read NV values from mobile and write to NV source xml\n");
   printf("\t-ph2qcn   read NV values from mobile and write to QCN\n");
   printf("\t-qcn2ph   read NV values from QCN and write to mobile\n");
   printf("\t-qcn2src   read NV values from QCN and write to NV source xml\n");
   printf("\t-diffqcns  Diff 2 QCN files\n");
   printf("\t-nvfilter  create NV filter based on NV ID loaded\n");
   printf("\t-compnvfilter  create NV filter based on NV ID NOT loaded by NV Def xml\n");
   printf("\t-qcn2qcn  Strip/Merge QCN(s) file with optional read filter\n");
    printf("\t-src2tar  read src file, write to TAR and compress tar to gz (Generates both .tar and .tar.gz file in the same location)\n");
   printf("\t-bdf2src   read NV values from board data file and write to NV source xml\n");
   printf("\t-src2bdf   read NV values from NV source xml and write to NV source xml board data file\n");
   printf("\t-bdf2ph   read board data file and write to phone\n");
   printf("\t-ph2bdf   read BDF from phone and write to NV source xml board data file\n");
   printf("\t-variantnv2src add variant RFNV into a source file in <NvItemData> format\n");
   
   printf("\nARGUMENTS:\n");
   printf("\t -def=<filename> NV definition xml path\n");
   printf("\t -src=<filename> NV source xml path\n");
   printf("\t -bdf=<filename> NV board data file path\n");
   printf("\t -qcn=<filename> QCN path \n");
   printf("\t -tar=<filename> TAR path \n");
   printf("\t -com=<COM port> COM port, for example -com=2\n");
   printf("\t -rdf=<filename> Read filter xml path. Read filter restricts the NV items to be read from sources\n");
   printf("\t -wtf=<filename> Write filter xml path. Read filter restricts the NV items to be written\n");
   printf("\t -diffout=<filename> A file path to store diff result.  Use file extension .HTML\n");
   printf("\t -filterPath=<fillename> Filter file name.  Use file extension .xml\n");
   printf("\t -outqcn=<filename> Output QCN output file for -qcn2qcn option \n");
   printf("\t -speed=<Sleep Counter> The argument for QLIB_Set_QPHONEMS_Userdefined_Sleep_Counter. For example, -speed=1\n");
   printf("\t -nv=the comman separated list of RFNV used by -varaintnv2src action\n");
   printf("\t -datatype=the comma separated list of Datatype ID used by -varaintnv2src action\n");

   printf("\nNOTE:Use a separate argument for every single file\n");
   printf("For example, combining two sources file to one qcn file\n");
   printf("QMSL_NVTool -src2qcn -def=\"Def.xml\" -src=\"s1.xml\" -src=\"s2.xml\" -qcn=\"NV.qcn\"");

   printf("\n\nThe table shows the minimum number of arguments required for each command\n");
   printf("\tdef\tsrc\tqcn\ttar\tcom\n");
   printf("src2qcn\t1\t1\t1\t0\t0\n");
   printf("src2ph\t1\t1\t0\t0\t1\n");
   printf("ph2src\t1\t1\t0\t0\t1\n");
   printf("ph2qcn\t1\t0\t1\t0\t1\n");
   printf("qcn2ph\t0\t0\t1\t0\t1\n");
   printf("qcn2src\t1\t1\t1\t0\t0\n");
   printf("src2tar\t1\t1\t0\t1\t0\n");

   printf("\nOPTIONS:\n");
   printf("\t -log=<filename> QMSL log path\n");
   printf("\t -qpst Use QPST when communicating with mobile\n");
   printf("\t -cb Enable callback (Print out every NV read/write status)\n");
   printf("\t -syncefs  Call QLIB_EFS2_SyncWithWait to synchronous modem file system on eMMC target\n");
   printf("\t -multisim  Enable NV support for multisim devices\n");
}

string ExtractFileName(string argument, int size)
{
   string fileName = argument.erase(0,size);
   return fileName;
}

vector<int> ExtractNVIDList(string argument)
{
    string NVIDList = argument.erase(0, 4);
    vector<int> result;
    std::stringstream ss(argument.c_str());
    unsigned int i;
    while (ss >> i)
    {
        result.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    return result;
}

vector<int> ExtractDataTypeList(string argument)
{
    string NVIDList = argument.erase(0, 10);
    vector<int> result;
    std::stringstream ss(argument.c_str());

    unsigned int i;
    while (ss >> i)
    {
        result.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    return result;
}

int ExtractCOMPort(string argument)
{
   int _comPort = -1;
   string comPort = argument.erase(0, 5);
   _comPort = atoi(comPort.c_str());
   return _comPort;
}

int ExtractSpeed(string argument)
{
   int _speed = 1;
   string comPort = argument.erase(0, 7);
   _speed = atoi(comPort.c_str());
   return _speed;
}

bool LoadReadFilter()
{
   bool bResult = true;
   unsigned int _i = 0;
   int _iResultCode = 0;
   
   for(_i = 0; _i < ::gReadFilterList.size(); _i++)
   {
      ::QLIB_NV_LoadReadFilter(gQMSL, gReadFilterList[_i].c_str(), &_iResultCode);
      printf("QLIB_NV_LoadReadFilter:%s, _iResultCode= %d\n", gReadFilterList[_i].c_str(), _iResultCode);
      
      if((_iResultCode == MSXML_FAILED_TO_LOAD_SRC) || (_iResultCode == MSXML_FAILED_TO_INSTANTIATE) )
      {
         bResult = false;
      }

   }
   return bResult;
}

bool LoadWriteFilter()
{
   bool bResult = true;
   unsigned int _i = 0;
   int _iResultCode = 0;
   for(_i = 0; _i < ::gWriteFilterList.size(); _i++)
   {
      ::QLIB_NV_LoadWriteFilter(gQMSL, gWriteFilterList[_i].c_str(), &_iResultCode);
      printf("QLIB_NV_LoadWriteFilter:%s, _iResultCode=%d\n", gWriteFilterList[_i].c_str(), _iResultCode);   
   
      if((_iResultCode == MSXML_FAILED_TO_LOAD_SRC) || (_iResultCode == MSXML_FAILED_TO_INSTANTIATE) )
      {
         bResult = false;
      }
   }
   return bResult;
}


bool LoadNVDefinitionFile()
{
   bool bResult = true;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iResultCode = 0;
   for(_i = 0; _i < ::gDefFileList.size(); _i++)
   {   
      ::QLIB_NV_LoadNVDataTypeDictinary(gQMSL, gDefFileList[_i].c_str(), &_iNumNVDef, &_iResultCode);
      printf("QLIB_NV_LoadNVDataTypeDictinary Def:%s, _iNumNVDef=%d, _iResultCode=%d\n", gDefFileList[_i].c_str(), _iNumNVDef, _iResultCode);

      ::QLIB_NV_LoadNVDefinitionFile(gQMSL, gDefFileList[_i].c_str(), &_iNumNVDef, &_iResultCode);
      printf("QLIB_NV_LoadNVDefinitionFile Def:%s, _iNumNVDef=%d, _iResultCode=%d\n", gDefFileList[_i].c_str(), _iNumNVDef, _iResultCode);

      if((_iResultCode == MSXML_FAILED_TO_LOAD_DEF) || (_iResultCode == MSXML_FAILED_TO_INSTANTIATE))
      {
		  printf("LoadNVDefinitionFile fails %d, most likely your PC needs to install msxml\n", _iResultCode);
         bResult = false;
      }
   }
   return bResult;
}


bool LoadSrcFiles()
{
   
   bool bResult = true;
   int _iResultCode = 0;
   int _iNumNVValues = 0;
   unsigned int _i = 0;
   for(_i = 0; _i < ::gSrcFileList.size(); _i++)
   {
      ::QLIB_NV_LoadNVsFromSource(gQMSL, gSrcFileList[_i].c_str(), &_iNumNVValues, &_iResultCode);
      printf("QLIB_NV_LoadNVsFromSource source:%s, _iNumNVValues=%d, _iResultCode=%d\n", gSrcFileList[_i].c_str(), _iNumNVValues, _iResultCode);
      
      if(	(_iResultCode == MSXML_FAILED_TO_LOAD_SRC) 
          || (_iResultCode == MSXML_FAILED_TO_INSTANTIATE) 
          || (_iResultCode == FAILED_TO_READ_ITEM_FROM_SRC_FILE ) 
          || (_iResultCode == NV_ITEM_FAILED_TO_SET_VALUE)
          || (_iResultCode == NV_ITEM_NOT_DEFINED)
          )
      {
         bResult = false;
      }
      
   }
   return bResult;
}

bool LoadQCNFiles()
{
   bool bResult = true;
   unsigned int _i = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   for(_i =0; _i < ::gQcnFileList.size(); _i++)
   {
      ::QLIB_NV_LoadNVsFromQCN(gQMSL, gQcnFileList[_i].c_str(), &_iNumNVValues, &_iResultCode);
      printf("QLIB_NV_LoadNVsFromQCN Qcn:%s, _iNumNVValues=%d, _iResultCode=%d\n", gQcnFileList[_i].c_str(), _iNumNVValues, _iResultCode);
   
      if( (_iResultCode == FAILED_TO_OPEN_QCN) ||
		  (_iResultCode == FAILED_TO_READ_ITEM_FROM_QCN_FILE ))
      {
         bResult = false;
      }
   }
   return bResult;
}

// QcaDeviceDefine.h
unsigned char OP_BDF_RW = 210;     

bool LoadBDFFromMobile()
{
   bool bResult = true;
   int _iResultCode = 0;
   int _iNumNVValues = 0;
   unsigned char _bSetModeFTM = 0;
   unsigned long _iPhoneMode = 0;

    ::QLIB_StartLogging(gQMSL, "c:\\log\\NVtool-log.txt");

   ::QLIB_FTM_WLAN_TLV_Create(gQMSL, OP_BDF_RW);
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_Create -- _OP_BDF_RW=%d\n", OP_BDF_RW);

    ::QLIB_FTM_WLAN_TLV_AddParam(gQMSL, "WLANBDF_actions", "1");    // _WLAN_BDFaction_READ
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_AddParam -- WLANBDF_actions=_WLAN_BDF_READ\n");

    ::QLIB_FTM_WLAN_TLV_AddParam(gQMSL, "BDFNamePathPhone", (char*)gBDFileList[0].c_str());
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_AddParam -- BDFNamePathPhone=%s\n", (char*)gBDFileList[0].c_str());

    ::QLIB_FTM_WLAN_TLV_AddParam(gQMSL, "BDFNamePathQDART", (char*)gSrcFileList[0].c_str());
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_AddParam -- BDFNamePathQDART=%s\n", (char*)gSrcFileList[0].c_str());

    ::QLIB_FTM_WLAN_TLV_Complete(gQMSL);
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_Complete\n");

   if(_iResultCode == FAILED_TO_CONNECT_TO_MOBILE)
   {
      bResult = false;
   }
    ::QLIB_StopLogging(gQMSL);
   return bResult;
}

bool SaveBDFToMobile()
{
   bool bResult = true;
   int _iResultCode = 0;    ::QLIB_StartLogging(gQMSL, "c:\\log\\NVtool-log.txt");

   ::QLIB_FTM_WLAN_TLV_Create(gQMSL, OP_BDF_RW);
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_Create -- _OP_BDF_RW=%d\n", OP_BDF_RW);

    ::QLIB_FTM_WLAN_TLV_AddParam(gQMSL, "WLANBDF_actions", "2");    // _WLAN_BDFaction_WRITE
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_AddParam -- WLANBDF_actions=_WLAN_BDF_READ\n");

    ::QLIB_FTM_WLAN_TLV_AddParam(gQMSL, "BDFNamePathPhone", (char*)gBDFileList[0].c_str());
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_AddParam -- BDFNamePathPhone=%s\n", (char*)gBDFileList[0].c_str());

    ::QLIB_FTM_WLAN_TLV_AddParam(gQMSL, "BDFNamePathQDART", (char*)gSrcFileList[0].c_str());
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_AddParam -- BDFNamePathQDART=%s\n", (char*)gSrcFileList[0].c_str());

    ::QLIB_FTM_WLAN_TLV_Complete(gQMSL);
   printf("LoadBDFFromMobile QLIB_FTM_WLAN_TLV_Complete\n");

   if(_iResultCode == FAILED_TO_CONNECT_TO_MOBILE)
   {
      bResult = false;
   }
    ::QLIB_StopLogging(gQMSL);
   return bResult;
}

bool LoadNVsFromBoardDataFile()
{
   bool bResult = true;
   int _iResultCode = 0;
   int _iNumNVValues = 0;

   ::QLIB_NV_LoadNVsFromBDF(gQMSL, gBDFileList[0].c_str(), &_iNumNVValues, &_iResultCode);
   printf("QLIB_NV_LoadNVsFromBDF _iNumNVValues=%d _iResultCode=%d\n", _iNumNVValues, _iResultCode);

   if(_iResultCode == FAILED_TO_ACCESS_BDF)
   {
      bResult = false;
   }
    return bResult;
}

bool SaveNVsToBoardDataFile()
{
   bool bResult = true;
   int _iResultCode = 0;

    ::QLIB_NV_WriteNVsToBDF(gQMSL, gBDFileList[0].c_str(), &_iResultCode);
   printf("QLIB_NV_WriteNVsToBDF BDF=%s _iResultCode=%d\n", gBDFileList[0].c_str(), _iResultCode);

   if(_iResultCode == FAILED_TO_ACCESS_BDF)
   {
      bResult = false;
   }
    return bResult;
}

bool LoadNVsFromMobile()   // Load NVs from mobile
{
   bool bResult = true;
   int _iResultCode = 0;
   int _iNumNVValues = 0;
   unsigned char _bSetModeFTM = 0;
   unsigned long _iPhoneMode = 0;

   ::QLIB_GetPhoneOperatingMode(gQMSL, &_iPhoneMode);
   printf("QLIB_GetPhoneOperatingMode : Phone Mode Return =%d\n", _iPhoneMode);

   if(_iPhoneMode != SYS_OPRT_MODE_FTM)
   {
      _bSetModeFTM = ::QLIB_DIAG_CONTROL_F(gQMSL, MODE_FTM_F);
      printf("QLIB_DIAG_CONTROL(h: MODE_FTM_F) status %d\n", _bSetModeFTM);
      Sleep(500);
   }

   ::QLIB_NV_LoadNVsFromMobile(gQMSL, &_iNumNVValues, &_iResultCode);
   printf("QLIB_NV_LoadNVsFromMobile _iNumNVValues=%d _iResultCode=%d\n", _iNumNVValues, _iResultCode);

   if(_iResultCode == FAILED_TO_CONNECT_TO_MOBILE)
   {
      bResult = false;
   }
   return bResult;
}
bool SaveNVsToMobile()      // Save NVs to mobile
{
   bool bResult = true;
   int _iResultCode = 0;
   
   ::QLIB_NV_WriteNVsToMobile(gQMSL, &_iResultCode);
   printf("QLIB_NV_WriteNVsToMobile _iResultCode=%d\n",  _iResultCode);

   if(bSyncEFS)
   {
      unsigned char _iExecutionStatus = 0;
      char * _pPath = "/";
      QLIB_EFS2_SyncWithWait(gQMSL, (unsigned char*) _pPath, 1000, &_iExecutionStatus);
      printf("QLIB_EFS2_SyncWithWait: _iExecutionStatus =%d\n", _iExecutionStatus);
   }   

   if(_iResultCode == FAILED_TO_CONNECT_TO_MOBILE)
   {
      bResult = false;
   }
   
   return bResult;
}

bool SaveNVsToQCN()         // Save NVs to QCN
{
   bool bResult = true;
   int _iResultCode = 0;
   ::QLIB_NV_WriteNVsToQCN(gQMSL, gQcnFileList[0].c_str(), &_iResultCode);
   printf("QLIB_NV_WriteNVsToQCN Qcn:%s, _iResultCode=%d\n", gQcnFileList[0].c_str(), _iResultCode);
   if(_iResultCode == FAILED_TO_OPEN_QCN)
   {
      bResult = false;
   }
   return bResult;
}
bool SaveNVsToQCNOut()         // Save NVs to QCN
{
   bool bResult = true;
   int _iResultCode = 0;
   ::QLIB_NV_WriteNVsToQCN(gQMSL, gQCNOutFileList[0].c_str(), &_iResultCode);
   printf("QLIB_NV_WriteNVsToQCN Qcn:%s, _iResultCode=%d\n", gQCNOutFileList[0].c_str(), _iResultCode);
   if(_iResultCode == FAILED_TO_OPEN_QCN)
   {
      bResult = false;
   }
   return bResult;
}


bool SaveNVsToSrc(bool dataFromBin)         // Save NVs to Source
{
   bool bResult = true;
   int _iResultCode = 0;
   
   if (dataFromBin)
      ::QLIB_NV_WriteNVsToSource(gQMSL, gSrcFileList[0].c_str(), &_iResultCode, '1');   
   else
      ::QLIB_NV_WriteNVsToSource(gQMSL, gSrcFileList[0].c_str(), &_iResultCode, '0');   
   printf("QLIB_NV_WriteNVsToSource Src:%s, _iResultCode=%d\n", gSrcFileList[0].c_str(), _iResultCode, dataFromBin);
   
   if((_iResultCode == MSXML_FAILED_TO_SAVE_SRC) || 
       (_iResultCode == MSXML_FAILED_TO_INSTANTIATE) || 
       (_iResultCode == FAILED_TO_OPEN_SRC) )
   {
      bResult = false;
   }
   return bResult;

}

bool SaveNVsToTAR()         // Save NVs to QCN
{
   bool bResult = true;
   int _iResultCode = 0;
   ::QLIB_NV_WriteNVsToTAR(gQMSL, gTarFileList[0].c_str(), &_iResultCode);
   printf("QLIB_NV_WriteNVsToTAR Qcn:%s, _iResultCode=%d\n", gTarFileList[0].c_str(), _iResultCode);
   if(_iResultCode == FAILED_TO_OPEN_TAR)
   {
      bResult = false;
   }
   return bResult;
}

bool Src2Qcn()
{
   
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   printf("QMSL_NVTool:NV Source to QCN\n");
   
   if( LoadNVDefinitionFile()   &&
      LoadReadFilter()      &&   
      LoadSrcFiles()         &&
      LoadWriteFilter()      &&
      SaveNVsToQCN())
   {
      bResult = true;
   }
   return bResult;
}

bool Src2Ph()
{
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   printf("QMSL_NVTool:NV Source to Mobile\n");
   
   if( LoadNVDefinitionFile() &&
      LoadReadFilter() &&
      LoadSrcFiles() &&
      LoadWriteFilter() &&
      SaveNVsToMobile() )
   {
      bResult = true;
   }
   return bResult; 
}

bool Ph2Qcn()
{
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   printf("QMSL_NVTool:Mobile to QCN\n");


   if( LoadNVDefinitionFile() &&
      LoadReadFilter() &&
      LoadNVsFromMobile() &&
      LoadWriteFilter() &&
      SaveNVsToQCN())
   {
      bResult = true;
   }
   return bResult;   
}

bool Ph2Src()
{
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   
   printf("QMSL_NVTool:Mobile to NV source\n");
   if(   LoadNVDefinitionFile() &&
      LoadReadFilter() &&
      LoadNVsFromMobile() &&
      LoadWriteFilter() &&
      SaveNVsToSrc(false))
   {
      bResult = true;
   }
   return bResult;
}

bool Src2BDF()
{
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   printf("QMSL_NVTool: NV xml to board data file\n");

   if(   LoadNVDefinitionFile() &&
//      LoadReadFilter() &&
      LoadSrcFiles() &&
//      LoadWriteFilter() &&
      SaveNVsToBoardDataFile())
   {
      bResult = true;
   }  
   return bResult;
}

bool BDF2Src()
{
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   
   printf("QMSL_NVTool:board data file to NV source\n");
   if(   LoadNVDefinitionFile() &&
//      LoadReadFilter() &&
      LoadNVsFromBoardDataFile() &&
//      LoadWriteFilter() &&
      SaveNVsToSrc(true))
   {
      bResult = true;
   } 
   return bResult;
}

bool Ph2BDF()
{
   bool bResult = false;
   
   printf("QMSL_NVTool:Mobile to BDF\n");
   if(   LoadBDFFromMobile() )
   {
      bResult = true;
   }
   return bResult;
}

bool BDF2Ph()
{
   bool bResult = false;
   printf("QMSL_NVTool:BDF to Mobile\n");
   if(   SaveBDFToMobile() )
   {
      bResult = true;
   }
   return bResult;
}

bool Qcn2Ph()
{
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   printf("QMSL_NVTool:QCN to Mobile\n");

   if(   LoadNVDefinitionFile() &&
      LoadReadFilter() && 
      LoadQCNFiles() &&
      LoadWriteFilter() &&
      SaveNVsToMobile())
   {
      bResult = true;
   }
   return bResult;
}

bool Qcn2Src()
{
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;

   printf("QMSL_NVTool:QCN to NV Source\n");
   
   if(   LoadNVDefinitionFile() &&
      LoadReadFilter() &&
      LoadQCNFiles() &&
      LoadWriteFilter() &&
      SaveNVsToSrc(false) )
   {
      bResult = true;
   }

   return bResult;
}

bool DiffQcns()
{
   int _iResultCode = 0;

   
   printf("QMSL_NVTool:DiffQcns\n");

   LoadNVDefinitionFile();

   ::QLIB_NV_QCN_Diff(gQMSL, gQcnFileList[0].c_str(), gQcnFileList[1].c_str(), gDiffOutList[0].c_str(), &_iResultCode);
   printf("QLIB_NV_QCN_Diff QCN1:%s, QCN2:%s, Output:%s _iResultCode=%d\n", gQcnFileList[0].c_str(), gQcnFileList[1].c_str(), gDiffOutList[0].c_str(), _iResultCode);

   return true;
}

void ConnectServer()
{
   if(bQPST == 1)
   {
      // Use QPST
      ::QLIB_SetLibraryMode(1);
   }
   
   if( (gCmdAction == SRC2PH)  ||
      (gCmdAction == PH2QCN)   ||
      (gCmdAction == PH2SRC)  ||
      (gCmdAction == QCN2PH)  ||
        (gCmdAction == PH2BDF)  ||
        (gCmdAction == BDF2PH)  )
   {
      gQMSL = ::QLIB_ConnectServer(gComPort);
        printf("ConnectServer: %d\n", (int)gQMSL);
   }
   else
      gQMSL = ::QLIB_ConnectServer(1);

   ::QLIB_ExtendedTextMessage_SetCategoryEnable(gQMSL, QMSL_ExtTextMsgCat_NV_Tool_Debug, 1);

   if(gQMSLLog.size() > 0)
   {
      char _sFileName[256];
      memset(_sFileName, 0, 256);
      strcpy_s(_sFileName, gQMSLLog.c_str());
      ::QLIB_StartLogging(gQMSL, _sFileName);
   }

   ::QLIB_Set_QPHONEMS_Userdefined_Sleep_Counter(gQMSL, gSpeed);
}

void DisconnectServer()
{
   if(gQMSLLog.size() > 0)
   {
      ::QLIB_StopLogging(gQMSL);
   }
   ::QLIB_DisconnectServer(gQMSL);

   ::QLIB_DisconnectAllServers();
}

bool CreateNVFilter()
{
   int _iResultCode = 0;

   printf("QMSL_NVTool:CreateNVFilter\n");

   LoadNVDefinitionFile();

   ::QLIB_NV_CreateNVFilter(gQMSL, gFilterFileList[0].c_str(), &_iResultCode);
   printf("QLIB_NV_CreateNVFilter: Filter:%s, _iResultCode=%d\n", gFilterFileList[0].c_str(), _iResultCode);

   return true;
}
bool CreateCompNVFilter()
{
   int _iResultCode = 0;
      
   unsigned short _iMaxNVId = 9000;

   printf("QMSL_NVTool:CreateNVFilter\n");

   LoadNVDefinitionFile();

   ::QLIB_NV_CreateComplementNVFilter(gQMSL, _iMaxNVId, gFilterFileList[0].c_str(), &_iResultCode);
   printf("QLIB_NV_CreateComplementNVFilter: Filter=%s, _iMaxNVId=%d _iResultCode=%d\n", gFilterFileList[0].c_str(), _iMaxNVId, _iResultCode);
   return true;
}



bool Qcn2Qcn()
{
   bool bResult = false;

   printf("QMSL_NVTool:Qcn2Qcn\n");

   if( LoadNVDefinitionFile() &&
      LoadReadFilter() &&
      LoadQCNFiles() &&
      SaveNVsToQCNOut())
   {
      bResult = true;
   }

   return bResult;
   
}


bool Src2Tar()
{
   
   bool bResult = false;
   unsigned int _i = 0;
   int _iNumNVDef = 0;
   int _iNumNVValues = 0;
   int _iResultCode = 0;
   printf("QMSL_NVTool: NV Source to TAR and GZ\n");
   
   if( LoadNVDefinitionFile() && 
      LoadSrcFiles()   &&
      SaveNVsToTAR())
   {
      bResult = true;
   }
   return bResult;
}


bool VariantNV2Src()
{
    int _iResultCode = 0;
    bool bResult = true;

    if( LoadNVDefinitionFile() )
    {
        for(unsigned int i = 0; i < gNVIDList.size(); i++)
        {
            for(unsigned int j = 0; j < gDataTypeIDList.size(); j++)
            {
                ::QLIB_NV_InsertDataTypeIntoVariantNV(gQMSL, gNVIDList[i], 0, -1, gDataTypeIDList[j], &_iResultCode);
                if( (_iResultCode == NVITEM_NOT_VARIANT ) || 
                    (_iResultCode == FAILED_TO_INSERT_DATA_INTO_VARIANT_NV)
                    )
                {
                    bResult = false;
                }
            }
        }

        // Write the data to source file
        ::QLIB_NV_WriteNVsToSourceSchema(gQMSL, 1);
        ::QLIB_NV_WriteNVsToSource(gQMSL, gSrcFileList[0].c_str(), &_iResultCode, 0);
         if((_iResultCode == MSXML_FAILED_TO_SAVE_SRC) || 
            (_iResultCode == MSXML_FAILED_TO_INSTANTIATE) || 
            (_iResultCode == FAILED_TO_OPEN_SRC) 
            )
        {
            bResult = false;
        }
    }
    else
        bResult = false;
    
    return bResult;
}


bool DevTest()
{
    int _iResultCode = 0;
    if( LoadNVDefinitionFile() )
    {
        ::QLIB_NV_InsertDataTypeIntoVariantNV(gQMSL, 28329, 0, 0, 102, &_iResultCode);
        //for(int i = 0; i < 10; i++)
        {
        ::QLIB_NV_InsertDataTypeIntoVariantNV(gQMSL, 28329, 0, -1, 104, &_iResultCode);
        ::QLIB_NV_InsertDataTypeIntoVariantNV(gQMSL, 28329, 0, -1, 105, &_iResultCode);
        ::QLIB_NV_InsertDataTypeIntoVariantNV(gQMSL, 28329, 0, -1, 106, &_iResultCode);
        
        }
        //::QLIB_NV_InsertDataTypeIntoVariantNV(gQMSL, 28329, 0, 1, 104, &_iResultCode);
        ::QLIB_NV_WriteNVsToSourceSchema(gQMSL, 1);
        ::QLIB_NV_WriteNVsToSource(gQMSL, "testoutput.xml", &_iResultCode, 0);
    }
    return true;

}