/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Misc/QMSL_MatlabHelpers/inc/QLIB_MatlabHelpers.h#3 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QLIB_MatlabHelpers
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#pragma once

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


/******************************************************************************/
/**
Execute binary form of the MATLAB script that is used for CGPS IQ processing.

The MATLAB script name is: CGPS_IqTest_IqFileProc.m
The compiled binary form of the MATLAB script is: CGPS_IqTest_IqFileProc.exe
The "Component Technology File" is: CGPS_IqTest_IqFileProc.ctf

Both the .EXE and .CTF must be in the same folder as the QMSL client executable file or
those two files must be in the system path.

The purpose of this function is to simplify the process for a C program to call the .EXE file.
It is always possible to bypass this function and call the .EXE directly in your C program.

This process will run in a blocking fashion, meaning that the function will not return until
all of the MATLAB processing has been completed.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param dRF_NoiseFigure_dB = input, expected noise figure, dB
\param dSigFreq_kHz = input, CW offset from center frequency, kHz
\param dSigLevel_dBm = input, CW power level at the mobile input, dBm
\param sIQ_FileName = input, file name of text file that holds IQ data/.
                  This is the same file passed as the sIQ_FileName paremter to
                  QLIB_DIAG_GPS_START_IQ_TEST_CollectResults()
\param sOutputFolder = folder where MATLAB output files should be stored
\param bAutoClose = TRUE to close the MATLAB graph windows, FALSE to keep them open
               If set to TRUE then the MATLAB graph windows will not be shown.
\param sStandardOutputFile = file name to store standard output into. If NULL then standard output will not be stored
\param bWaitForCompletion = wait for the child process to complete before returning from this function
\param iPhoneState = call state. 0 = OoS, 1 = WCDMA in-service OR GSM Idle, 2 = GSM Traffic, 3 = 1x
\param sStdFolder = path name to store standard output into for Matlab. If NULL then standard output will not be stored


\return true if successful, false if fail.

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_MATLAB_IQ_FILE_PROC(
   HANDLE hResourceContext,
   double dRF_NoiseFigure_dB,
   double dSigFreq_kHz,
   double dSigLevel_dBm,
   char *sIQ_FileName,
   char *sOutputFolder,
   unsigned char bAutoClose,
   char *sStandardOutputFile,
   unsigned char bWaitForCompletion,
   unsigned char iPhoneState,
   const char *sStdFolder
   );

/******************************************************************************/
/**
Execute binary form of the MATLAB script that is used for CGPS IQ processing.

The MATLAB binary is invoved using a COM object which requires a QMSL DLL to be
registered using regsvr32

File: QMSL_MATLAB_Interface.DLL
uuid = 7EEA2D69-0CAE-40B8-B3A1-9D31F65FE46B
interface name = QMSL_MATLAB Interface


The MATLAB script name is: CGPS_IqTest_IqFileProc.m
The compiled binary form of the MATLAB script is: QMSL_Matlab_Generic.dll
The "Component Technology File" is: QMSL_Matlab_Generic.ctf

Both the .DLL and .CTF must be in the same folder as the QMSL client executable file or
those two files must be in the system path.

This process will run in a blocking fashion, meaning that the function will not return until
all of the MATLAB processing has been completed.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
\param dRF_NoiseFigure_dB = input, expected noise figure, dB
\param dSigFreq_kHz = input, CW offset from center frequency, kHz
\param dSigLevel_dBm = input, CW power level at the mobile input, dBm
\param sIQ_FileName = input, file name of text file that holds IQ data/.
                  This is the same file passed as the sIQ_FileName paremter to
                  QLIB_DIAG_GPS_START_IQ_TEST_CollectResults()
\param sOutputFolder = folder where MATLAB output files should be stored
\param bAutoClose = TRUE to close the MATLAB graph windows, FALSE to keep them open
               WARNING: if autoclose is set to false, it is possible to receive MATLAB exception
               after the file processing is completed. The only supported setting is for bAutoClose = true
               If set to TRUE then the MATLAB graph windows will not be shown.

\param iPhoneState = call state. 0 = OoS, 1 = WCDMA in-service OR GSM Idle, 2 = GSM Traffic, 3 = 1x
\param sStdFolder = path name to store standard output into for COM interface and Matlab. If NULL then standard output will not be stored


\return true if successful, false if fail.

*******************************************************************************/
QLIB_API unsigned char QLIB_CGPS_MATLAB_IQ_FILE_PROC_COM(
   HANDLE hResourceContext,
   double dRF_NoiseFigure_dB,
   double dSigFreq_kHz,
   double dSigLevel_dBm,
   char *sIQ_FileName,
   char *sOutputFolder,
   unsigned char bAutoClose,
   unsigned char iPhoneState,
   const char *sStdFolder
   );

/******************************************************************************/
/**
Execute binary form of the MATLAB script that is used for GNSS Gen8 (Callisto) IQ processing.

The MATLAB script names are: gnss_IqTest_IqFileProc.m, gnss_IqTest_JammerProc.m
The compiled binary form of the MATLAB script is: gnss_IqTest_IqFileProc.dll
The "Component Technology File" is: gnss_IqTest_IqFileProc.ctf
The MATLAB binary is invoked using a COM object which requires a QMSL DLL to be
registered using regsvr32

File: QMSL_MATLAB_Interface.DLL
uuid = 7EEA2D69-0CAE-40B8-B3A1-9D31F65FE46B
interface name = QMSL_MATLAB Interface

The MATLAB script names are: gnss_IqTest_IqFileProc.m, gnss_IqTest_JammerProc.m
The compiled binary form of the MATLAB script is: QMSL_Matlab_Generic.dll
The "Component Technology File" is: QMSL_Matlab_Generic.ctf

Both the .DLL and .CTF must be in the same folder as the QMSL client executable file or
those two files must be in the system path.

This process will run in a blocking fashion, meaning that the function will not return until
all of the MATLAB processing has been completed.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
 \param iPhoneState = phone state.
     iPhoneState = 100*gnssSig + 10*nwType + nwCond
     gnssSig:(1) GPS / (2) GLO
     nwType: (1) 1X / (2) WCDMA / (3) GSM / (4) Unconnected
     nwCond: (1) OoS/UnConnected
             (2) Idle
             (3) Traffic
     Note: Multimode OoS should be tested with nwType = 2 or 3.
\param dSigFreq_kHz = input, CW offset from center frequency, kHz
\param dSigLevel_dBm = input, CW power level at the mobile input, dBm
\param sIQ_FileName = input, file name of a .bin file that holds IQ data/.
\param sOutputFolder = folder where MATLAB output files should be stored
\param bAutoClose = TRUE to close the MATLAB graph windows, FALSE to keep them open
               WARNING: if autoclose is set to false, it is possible to receive MATLAB exception
               after the file processing is completed. The only supported setting is for bAutoClose = true
               If set to TRUE then the MATLAB graph windows will not be shown.
\param sStdFolder = path name to store standard output into for COM interface and Matlab. If NULL then standard output will not be stored
\return true if successful, false if fail.
*******************************************************************************/
QLIB_API unsigned char QLIB_GNSS_MATLAB_IQ_FILE_PROC_COM(
   HANDLE hResourceContext,
   unsigned long iPhoneState,
   double dSigFreq_kHz,
   double dSigLevel_dBm,
   char *sIQ_FileName,
   char *sOutputFolder,
   unsigned char bAutoClose,
   const char *sStdFolder
   );
/******************************************************************************/
/**
Execute binary form of the MATLAB script that is used for GNSS Gen8 (Callisto) IQ processing.

The MATLAB script names are: gnss_IqTest_IqFileProc.m, gnss_IqTest_JammerProc.m
The compiled binary form of the MATLAB script is: gnss_IqTest_IqFileProc.dll
The "Component Technology File" is: gnss_IqTest_IqFileProc.ctf
The MATLAB binary is invoked using a COM object which requires a QMSL DLL to be
registered using regsvr32

File: QMSL_MATLAB_Interface.DLL
uuid = 7EEA2D69-0CAE-40B8-B3A1-9D31F65FE46B
interface name = QMSL_MATLAB Interface

The MATLAB script names are: gnss_IqTest_IqFileProc.m, gnss_IqTest_JammerProc.m
The compiled binary form of the MATLAB script is: QMSL_Matlab_Generic.dll
The "Component Technology File" is: QMSL_Matlab_Generic.ctf

Both the .DLL and .CTF must be in the same folder as the QMSL client executable file or
those two files must be in the system path.

This process will run in a blocking fashion, meaning that the function will not return until
all of the MATLAB processing has been completed.

\param hResourceContext  = Resource context that was returned from the call to ConnectServer().
 \param iPhoneState = phone state.
     iPhoneState = 100*gnssSig + 10*nwType + nwCond
     gnssSig:(1) GPS / (2) GLO
     nwType: (1) 1X / (2) WCDMA / (3) GSM / (4) Unconnected
     nwCond: (1) OoS/UnConnected
             (2) Idle
             (3) Traffic
     Note: Multimode OoS should be tested with nwType = 2 or 3.
\param dSigFreq_kHz = input, CW offset from center frequency, kHz
\param dSigLevel_dBm = input, CW power level at the mobile input, dBm
\param sIQ_FileName = input, file name of a .bin file that holds IQ data/.
\param sOutputFolder = folder where MATLAB output files should be stored
\param bAutoClose = TRUE to close the MATLAB graph windows, FALSE to keep them open
               WARNING: if autoclose is set to false, it is possible to receive MATLAB exception
               after the file processing is completed. The only supported setting is for bAutoClose = true
               If set to TRUE then the MATLAB graph windows will not be shown.
\param sStdFolder = path name to store standard output into for COM interface and Matlab. If NULL then standard output will not be stored
\param sEngine = GNSS Engine - "Gen 8" or "Gen8A"
\param sAgcType = AGC Type - "HW" or "SW"
\return true if successful, false if fail.
*******************************************************************************/
QLIB_API unsigned char QLIB_GNSS_8A_MATLAB_IQ_FILE_PROC_COM(
   HANDLE hResourceContext,
   unsigned long iPhoneState,
   double dSigFreq_kHz,
   double dSigLevel_dBm,
   char *sIQ_FileName,
   char *sOutputFolder,
   unsigned char bAutoClose,
   const char *sStdFolder,
   const char *Engine,
   const char *AgcType
   );

/******************************************************************************/
/**
Execute binary form of the MATLAB script that is used to plot a figure.

The MATLAB binary is invoved using a COM object which requires a QMSL DLL to be
registered using regsvr32

File: QMSL_MATLAB_Interface.DLL
uuid = 7EEA2D69-0CAE-40B8-B3A1-9D31F65FE46B
interface name = QMSL_MATLAB Interface

The MATLAB script name is: qmsl_matlab_plot.m, print_to_error.m, and remove_special_string.m
The compiled binary form of the MATLAB script is: QMSL_Matlab_Generic.dll
The "Component Technology File" is: QMSL_Matlab_Generic.ctf
Both the .DLL and .CTF must be in the same folder as the QMSL client executable file or
those two files must be in the system path.

This process will run in a blocking fashion, meaning that the function will not return until
all of the MATLAB processing has been completed.

\param hResourceContext = Resource context that was returned from the call to ConnectServer().
\param sFileName = input, name of file containing the data to plot. must follow the required format. see below note.
\param sOutputPath = path (inc. file name) where MATLAB output files should be stored
\param sStdFolder = path name to store standard output into. If NULL then standard output will not be stored
\param bBackGround = TRUE, the MATLAB graph windows will not be shown.
\return true if successful, false if fail.

\IMPORTANT: Input file must follow format below:
line 1: figure title = string.
line 2: figure x-label = string.
line 3: figure y-label = string.
line 4: figure legend = string. If you have multiple lines to plot   in same figure,
          use legend to give each line a name. Use";" to delim them.
line 5: user defined text to display to figure.
line 6: figure style, default is "plot" options include "plot" and "bar" (must be lower case)
line 7 - 10: reserved. user data file should fill with emtpy lines for future backward compatibility.
begin of data: use a line starting with ***
data format per line:x(1) [] y(1)\n. Note [] represents for space. you must make
sure there are no extra spaces except the one separate x and y coordinates.
If you have multiple lines to plot in figure, please use another *** to start another data
section, immediately in the line following last data section.

An Example of input file:
   line1: BP amplitude vs time.                                          //title.
   line2: Time in seconds                                                //x-label and unit
   line3: BP Amp [dB]                                                //y-label and unit
   line4: BP Amp I data;BP Amp Q data                                    //legend: totally two lines.
   line5: Technology=CDMA, band=CDMA 800,channel=18                  //user defined text, optional
   line6: plot                                                       //optional, use lower case "plot" or "bar" (without quote)
   line 7- 10: empty.                                                    //reserved
   line11: ***                                                       //indicator of starting of data section
   line12: 0.000 53.000
   line13: 2.094 58.500
   ......
          4.187 58.000
   line#: ***                                                        //inication of another data section begin
         10.469 58.500
         12.562 59.500

*******************************************************************************/

QLIB_API unsigned char QLIB_MATLAB_GENERIC_PLOT_COM(
   HANDLE hResourceContext,
   char *sFileName,
   char *sOutputPath,
   char *sStdFolder,
   unsigned char bBackGround
   );



#ifdef __cplusplus
}   // extern "C"
#endif
