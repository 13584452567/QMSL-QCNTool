/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Misc/QMSL_SECURITY_ID_SENSOR/inc/QMSL_FTM_SECURITY_ID_SENSOR.h#5 $
 * $DateTime: 2016/04/04 17:51:51 $
 *
 *
 ******************************************************************************
 *
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_SECURITY_ID_SENSOR_H)
#define _QMSL_FTM_SECURITY_ID_SENSOR_H

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
#endif


#ifdef __cplusplus
extern "C" {
#endif

   /******************************************************************************
                     SECURITY_ID_SENSOR FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR Start
      This command starts the SECURITY_ID_SENSOR susbsystem.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus - SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
   \endcode
   
   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_START( 
        HANDLE hResourceContext, 
        unsigned short* piSECURITY_ID_SENSORStatus );



   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR Write Parameter
      This command sets the values of a single scan parameter

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
      6 = SECURITY_ID_SENSOR_BUSY
   \endcode
   \param iParameterID = Parameter ID of scan parameter to be written
   \code
      0 = DBIAS_V1
      1 = DBIAS_V2
      2 = DBIAS_V3
      3 = DBIAS_V4
      4 = RBIAS_V1
      5 = RBIAS_V2
      6 = RBIAS_V3
      7 = RBIAS_V4
      8 = TBG_FREQ
      9 = TBG_ENABLE
      10 = RANGE_GATE_DELAY
      11 = RANGE_GATE_WIDTH
      12 = TEMPERATURE_SLOPE
      13 = TEMPERATURE_OFFSET
   \endcode
   \param iScaling = Scaling value by which the parameter value needs to be divided to get the actual value
   \param iValue = Scaled parameter value to be written

   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_WRITE_PARAMETER( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned short iParameterID,
      unsigned int iScaling,
      int iValue 
      );
   


   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR Read Parameter
      This command reads the values of a single scan parameter

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling camera services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
      6 = SECURITY_ID_SENSOR_BUSY
   \endcode
   \param iParameterID = Parameter ID of scan parameter to be written
   \code
      0 = DBIAS_V1
      1 = DBIAS_V2
      2 = DBIAS_V3
      3 = DBIAS_V4
      4 = RBIAS_V1
      5 = RBIAS_V2
      6 = RBIAS_V3
      7 = RBIAS_V4
      8 = TBG_FREQ
      9 = TBG_ENABLE
      10 = RANGE_GATE_DELAY
      11 = RANGE_GATE_WIDTH
      12 = TEMPERATURE_SLOPE
      13 = TEMPERATURE_OFFSET
   \endcode
   \param piScaling = Scaling value by which the parameter value needs to be divided to get the actual value
   \param piValue = Scaled parameter value

   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_READ_PARAMETER( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned short iParameterID,
      unsigned int* piScaling,
      int* piValue
      );


   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR Get Max Buffer Length
      Returns the max. number of bytes that can be transfered over the FTM link in a single transaction

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param piMaxBufferLength = Max. buffer length in bytes
   
   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_GET_MAX_BUFFER_LENGTH( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned int* piMaxBufferLength
      );

   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR Read Image
      Copies a part of a previsouly scanned image into a buffer

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param iOffset = Offset in bytes from beginning of buffer
   \param iLength = Number of bytes to read
   \param piDataLength = Actual number of bytes returned. May be different from requested length
   \param piBuffer = Buffer to receive data. Must be allocated by caller with at least iLength bytes
   
   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_READ_IMAGE( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned int iOffset,
      unsigned int iLength,
      unsigned int* piDataLength,
      unsigned char* piBuffer
      );


   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR EXEC
      Executes a self test or other routine

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
      6 = SECURITY_ID_SENSOR_BUSY
   \endcode
   \param iTestID = Test ID to execute
   \code
      2 = Digital Test
      3 = TFT Test
        4 = Rx Test
        5 = Tx Test
        6 = Noise Test
        7 = Image Quality Test BG Image
        8 = Image Quality Test FG Image
        9 = Image Quality Test Processing
        10 = Temperature Sensor Calibration
        11 = DBIas Calibration
        13 = Tone Burst Calibration BG Images
        14 = Tone Burst Calibration FG Images
        15 = Tone Burst Calibration Processing
        16 = Reset
        17 = Scan Image
   \endcode
   
   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_EXEC( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned short iTestID
      );


   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR READ EXEC STATUS
      Returns the status of any self test or calibration

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
      6 = SECURITY_ID_SENSOR_BUSY
   \endcode
   \param piTestStatus = Status of self test
   \code
      0 = IDLE / COMPLETE
      1 = EXECUTING TEST
   \endcode
   \param piTestID = Current/last self test that has been executed
   \code
      0 = None, no test has been executed
      2 = Digital Test
      3 = TFT Test
        4 = Rx Test
        5 = Tx Test
        6 = Noise Test
        7 = Image Quality Test BG Image
        8 = Image Quality Test FG Image
        9 = Image Quality Test Processing
        10 = Temperature Sensor Calibration
        11 = DBIas Calibration
        13 = Tone Burst Calibration BG Images
        14 = Tone Burst Calibration FG Images
        15 = Tone Burst Calibration Processing
        16 = Reset
        17 = Scan Image
   \endcode
   \param piTestResult = Test specific test result
   
   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_READ_EXEC_STATUS( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned short* piTestID,
       unsigned char* piTestStatus,
       unsigned char* piTestResult,
       unsigned short iBufferLength,
       unsigned short *piDataLength,
       unsigned char *buffer
       );


   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR READ INFO
      Returns information on the SECURITY_ID_SENSOR hardware and firmware

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param piFWVersion = Fingerpritn service FW version
   \param piChipID = SECURITY_ID_SENSOR Chip ID
   \param piChipSerialNumber = ASIC Serial Number
   \param piLotID = ASIC LOT ID (12 Bytes)
   \param piWaferID = ASIC WAFER IDF (3 Bytes)
   \param piSensorWidth = Width of sensor in pixels
   \param piSensorHeigth = Heigth of sensor in pixels
   \param piLivenessSupport = Indicates support of liveness detection
   \code
      0 = Not supported
      1 = Supported
   \endcode

   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_READ_INFO( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned int* piFWVersion,
      unsigned int* piChipID,
      unsigned int* piChipSerialNumber,
       unsigned char* piLotID,
       unsigned char* piWaferID,
      unsigned int* piSensorWidth,
      unsigned int* piSensorHeigth,
      unsigned char* piLivenessSupport
      );
   
   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR WRITE CALIBRATION
      Writes current settings to NVM memory

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param iKey = Security key to prevent accidental write Calibration Data. Must be 0xAACC5577

   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_WRITE_CALIBRATION( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned int iKey
      );
 

   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR READ TEMPERATURE
      Returns the current sensor temperatrure

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param piTemperature = Scaled sensor temperature
   \param piScaling = Scaling factor. Divide scaled temperature by this in order to get temperature in degrees Celsius

   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_READ_TEMPERATURE( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      int* piTemperature,
      unsigned int* piScaling
      );
   
  /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR READ LIVENESS
      Returns the status of the liveness detection

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param piLiveness = Liveness detection status
   \code
      0 = Not supported
      1 = Liveness not detected
      2 = Liveness detected
   \endcode

   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_READ_LIVENESS( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
      unsigned char* piLiveness
      );
   

  /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR_WRITE_MFG_DATA
      Writes value for manufacturing data entry

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param iEntryID = Entry ID of manufacturing data
   \param iDataLength = Length of data buffer
   \param buffer = Buffer that contains data


   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_WRITE_MFG_DATA( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
       unsigned short iEntryID,
       unsigned short iDataLength,
       unsigned char *buffer
      );


  /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR_READ_MFG_DATA
      Returns value for a manufacturing data data element

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param iEntryID = Entry ID of NVM element
   \param iBufferLength = Length of data buffer
   \param piDataLength = Actual length of data (0 = Entry not defined)
   \param buffer = Buffer that contains data


   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_READ_MFG_DATA( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
       unsigned short iEntryID,
       unsigned short iBufferLength,
       unsigned short* piDataLength,
       unsigned char *buffer
      );



  /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR_CALIBRATION_STATUS
      Returns calibration status information

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param piCalibrationStatus = Calibration status
   \param piEepromStatus = EEPROM status
   \param piOTPStatus = OTP Status


   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_CALIBRATION_STATUS( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
       unsigned char* piCalibrationStatus,
       unsigned char* piEepromStatus,
       unsigned char* piOTPStatus
      );


  /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR_SET_TEST_PARAMETER
      Writes the value of a Test Parameter

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param iTestParamaterID = Test parameter ID
   \param iDataLength = Length of parametr data
   \param piData = Test parameter data


   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_SET_TEST_PARAMETER( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
       unsigned short iTestParamaterID,
       unsigned short iDataLength,
       unsigned char* piData
      );


  /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR_GET_TEST_PARAMETER
      Returns the value of a Test Parameter

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus = SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      2 = SECURITY_ID_SENSOR_INVALID_ARGUMENT
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED,
   \endcode
   \param iTestParamaterID = Test parameter ID
   \param iBufferLength = Length of data buffer
   \param piDataLength = Length of parameter data
   \param buffer = Buffer to receive test parameter data


   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_GET_TEST_PARAMETER( 
      HANDLE hResourceContext, 
      unsigned short* piSECURITY_ID_SENSORStatus,
       unsigned short iTestParamaterID,
       unsigned short iBufferLength,
       unsigned short* piDataLength,
       unsigned char* buffer
      );


   /******************************************************************************/
   /**
   Factory Test Mode SECURITY_ID_SENSOR, SECURITY_ID_SENSOR Stop
      This command stops the SECURITY_ID_SENSOR susbsystem.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  piSECURITY_ID_SENSORStatus - SECURITY_ID_SENSOR services status, returns code from calling SECURITY_ID_SENSOR services API:
   \code
       0 = SECURITY_ID_SENSOR_SUCCESS
      1 = SECURITY_ID_SENSOR_ERROR
      3 = SECURITY_ID_SENSOR_NOT_AVAILABLE
      4 = SECURITY_ID_SENSOR_NOT_INITIALIZED
   \endcode
   
   \return 1 if successful, 0 if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SECURITY_ID_SENSOR_STOP( 
       HANDLE hResourceContext, 
       unsigned short* piSECURITY_ID_SENSORStatus );


#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_FTM_SECURITY_ID_SENSOR_H)
