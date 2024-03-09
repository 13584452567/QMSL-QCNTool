/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Misc/QMSL_Camera/inc/QMSL_FTM_Camera.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_Camera
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_CAMERA_H)
#define _QMSL_FTM_CAMERA_H

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
                     Camera FTM
   *******************************************************************************/

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.1 Camera Start
      This command starts the camera services. The power to the sensor is turned on and set to
      the power-up state for operation. The sensor and the device driver are initialized. Setting picture
      dimensions and taking pictures cannot happen until this command is executed.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode


   \code
   This section of sample code taken from the QlibDemo.cpp program.  It demonstrates how to use the
   Camera API.  The assumption is that the QLIB communications with the phone have already been setup
   and the variable g_hResourceContext is a valid HANDLE.


   // Setup variables
   char _sPictureFileName[] = "C:\\FactoryTest.jpg";
   unsigned char   _bAutoPictureSize = true;   // Auto determine picture width
   unsigned short   _iPictureWidth = 0;         // not used because auto-
   unsigned short   _iPictureHeight = 0;
   unsigned short   _iDelay_ms = 2000;         // 2 seconds
   unsigned long   _iQuality = 99;            // % quality (0-99)
   unsigned short   _iFormat = CAMERA_JPEG;      // JPEG format
   unsigned long   _iPicDataSize = 0;         // Will get updated when picture is taken
   unsigned short   _iDataTransferSize = 512;   // Number of bytes transferred at a time
   void*   _piPicData = NULL;
   unsigned short   _iCameraStatus = CAMERA_SUCCESS;

   printf("\nTaking picture...");
   bOk = QLIB_FTM_CAMERA_PerformTakePictureSequence
         (
         g_hResourceContext,
         _bAutoPictureSize,
         _iPictureWidth,
         _iPictureHeight,
         _iDelay_ms,
         _iQuality,
         _iFormat,
         &_iPicDataSize,
         &_iCameraStatus
         );
   printf("\nQLIB_FTM_CAMERA_PerformTakePictureSequence = %s", bOk ? "PASS" : "FAIL");

   // Now transfer the picture into memory
   if (   ( bOk )
      &&   (_iPicDataSize != 0 )
      )
   {

      // Allocate memory
      _piPicData = malloc( _iPicDataSize );

      if ( _piPicData != NULL )
      {
         printf("\nRetrieving picture (%d bytes)...", _iPicDataSize );

         bOk = QLIB_FTM_CAMERA_GetEntirePicture
               (
                  g_hResourceContext,
                  _iPicDataSize,
                  _iDataTransferSize,
                  (unsigned char*) _piPicData,
                  &_iCameraStatus
               );

         printf("\nQLIB_FTM_CAMERA_GetEntirePicture = %s", bOk ? "PASS" : "FAIL");

         if (bOk)
         {
            // Select binary mode for the IO library
            _fmode = _O_BINARY;

            // Setup file pointer
            FILE* _hGraphicFile = NULL;

            // Now store this data into a file
            if (_hGraphicFile = fopen( _sPictureFileName,"w"))
            {
               // Write the data to a file
               fwrite( _piPicData, _iPicDataSize, 1, _hGraphicFile);
            }   // fopen()

            // Close the file
            if (_hGraphicFile != NULL )
               fclose( _hGraphicFile );

         }   // if (bOk)

      }   // if ( _piPicData != NULL )

      // Close the Camera Service
      bOk = QLIB_FTM_CAMERA_STOP( g_hResourceContext,  &_iCameraStatus );

      // Free th memory
      free( _piPicData);

   }   // if ( bOk ... )


   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_START( HANDLE hResourceContext, unsigned short* piCameraStatus );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.2 Camera Stop
      This command terminates the camera services. The power sensor is turned off. This command
      also de-allocates the memory heap allocated for picture storage.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_STOP( HANDLE hResourceContext, unsigned short* piCameraStatus );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.3 Camera Set Parm
      This command sets the operational parameters of the camera sensor. For a list of possible
      parameter identifiers, refer to the Camera Services Interface Specification and Operational
      Description (80-V5310-1).


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param   iParmId = Camera parameter identifier.  Refer to 80-V5310-1 for definitions of parameter identifiers.
   \code
        0 = CAMERA_PARM_STATE (Read Only)
        1 = CAMERA_PARM_ACTIVE_CMD (Read Only)
        2 = CAMERA_PARM_ZOOM
        3 = CAMERA_PARM_ENCODE_ROTATION
        4 = CAMERA_PARM_SENSOR_POSITION
        5 = CAMERA_PARM_CONTRAST
        6 = CAMERA_PARM_BRIGHTNESS
        7 = CAMERA_PARM_SHARPNESS
        8 = CAMERA_PARM_EXPOSURE
        9 = CAMERA_PARM_WB
        10 = CAMERA_PARM_EFFECT
        11 = CAMERA_PARM_AUDIO_FMT
        12 = CAMERA_PARM_FPS
        13 = CAMERA_PARM_FLASH
        14 = CAMERA_PARM_RED_EYE_REDUCTION
        15 = CAMERA_PARM_NIGHTSHOT_MODE
        16 = CAMERA_PARM_REFLECT
        17 = CAMERA_PARM_PREVIEW_MODE
        18 = CAMERA_PARM_ANTIBANDING
        19 = CAMERA_PARM_THUMBNAIL_WIDTH
        20 = CAMERA_PARM_THUMBNAIL_HEIGHT
        21 = CAMERA_PARM_THUMBNAIL_QUALITY
   \endcode
   \param   iParmValue = This is the camera parameter value.
                        Refer 80-V5310-1 for specific definitions for each parameter identifiers.

   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_SET_PARM
   (
      HANDLE hResourceContext,
      unsigned short iParmId,
      unsigned long iParmValue,
      unsigned short* piCameraStatus
   );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.4 Camera Set Dimensions
      This command sets the picture dimensions. The picture width is the horizontal width of the
      picture in number of pixels and the picture height is the vertical height of the picture in number of
      lines. The Camera Start command must be executed before using this command. Refer to Chapter
      3 for recommended picture resolutions.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iPictureWidth - This is the horizontal width of the picture in number of pixels.
   \param iPictureHeight- This is the Vertical height of the picture in number of pixels.
   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode
   \param iLCD_Width = # of pixel on the X axis of the LCD

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_SET_DIMENSIONS
   (
      HANDLE hResourceContext,
      unsigned short iPictureWidth,
      unsigned short iPictureHeight,
      unsigned short iLCD_Width,
      unsigned short* piCameraStatus
   );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.5 Camera Start Preview
      This command enters the preview state of camera services. This command must be executed each
      time the Camera Start or the Camera Set Dimensions command is called.
      NOTE A two second delay is recommended between Camera Start Preview and Camera Stop Preview
      commands in order for white balance and exposure to take effect. There is no software feedback
      mechanism indicating these parameters are ready; two seconds is a reasonable time for the human
      eye, which is the only method to verify this.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_START_PREVIEW( HANDLE hResourceContext, unsigned short* piCameraStatus );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.6 Camera Stop Preview
      This command exits the preview state of camera services. This command must be executed after
      Camera Start Preview command and before a picture is taken.
      NOTE A two second delay is recommended between Camera Start Preview and Camera Stop Preview
      commands in order for white balance and exposure to take effect. There is no software feedback
      mechanism indicating these parameters are ready; two seconds is a reasonable time for the human
      eye, which is the only method to verify this.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_STOP_PREVIEW( HANDLE hResourceContext, unsigned short* piCameraStatus );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.7 Camera Take Picture and Encode

      This command takes the picture, encodes the picture, and saves it in the phones allocated
      memory heap. The format of the picture can be either raw or JPEG-encoded data stored in the
      allocated memory buffer. Memory heap is allocated when this command is executed. Refer to
      Appendix A for details on how the allocated memory buffer or memory length is calculated.
      The compression ratio or quality factor is selected, and it impacts the output file size. A quality
      factor from 1 to 99 can be selected, with 1 as the lowest quality and 99 as the highest quality. In
      addition, the compression ratio is only used for JPEG-encoded format (not with the raw format).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param   iQuality - This is the compression ratio or quality factor (valid range of [1:99],
                      with 1 as the lowest quality and 99 as the highest quality).
   \param iFormat   - Format of picture data:
   \code
               0 = CAMERA_RAW
               1 = CAMERA_JPEG
   \endcode

   \param piPicDataSize = This is the size of the entire picture in bytes.

   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_TAKE_PICTURE_AND_ENCODE
   (
      HANDLE hResourceContext, unsigned long iQuality, unsigned short iFormat,
      unsigned long* piPicDataSize, unsigned short* piCameraStatus
   );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.8 Camera Get Picture
      This command retrieves raw or JPEG-encoded picture data from the allocated memory space
      used in the Camera Take Picture and Encode command, based on a data offset and size. Given the
      data offset and size, this command will need to be executed a number of times until all picture
      data is retrieved.
      The recommended size to retrieve at one time is 512 bytes. The picture data format is based on
      the format parameter configured in the Camera Take Picture and Encode command.
      NOTE When retrieving the picture data, the picture will not be displayed on the phones LCD.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDataOffset - The DATA_OFFSET is the offset in which to start retrieving picture data from memory.
   \param iDataSize - The size of picture data in bytes to retrieve from memory during this transaction.
   \param piPicData - The actual picture data is returned into this buffer, the number of bytes is DATA_SIZE.

   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_GET_PICTURE
   (
      HANDLE hResourceContext, unsigned long iDataOffset, unsigned short iDataSize,
      unsigned char* piPicData, unsigned short* piCameraStatus
   );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.9 Camera Get Parm
      This command retrieves the operational parameters of the camera sensor. For a list of possible
      parameter identifiers, refer to Camera Services Interface Specification and Operational
      Description (80-V5310-1).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iParmID - Camera parameter identifier. Refer to 80-V5310-1 for definitions of parameter identifiers.
   \code
        0 = CAMERA_PARM_STATE (Read Only)
        1 = CAMERA_PARM_ACTIVE_CMD (Read Only)
        2 = CAMERA_PARM_ZOOM
        3 = CAMERA_PARM_ENCODE_ROTATION
        4 = CAMERA_PARM_SENSOR_POSITION
        5 = CAMERA_PARM_CONTRAST
        6 = CAMERA_PARM_BRIGHTNESS
        7 = CAMERA_PARM_SHARPNESS
        8 = CAMERA_PARM_EXPOSURE
        9 = CAMERA_PARM_WB
        10 = CAMERA_PARM_EFFECT
        11 = CAMERA_PARM_AUDIO_FMT
        12 = CAMERA_PARM_FPS
        13 = CAMERA_PARM_FLASH
        14 = CAMERA_PARM_RED_EYE_REDUCTION
        15 = CAMERA_PARM_NIGHTSHOT_MODE
        16 = CAMERA_PARM_REFLECT
        17 = CAMERA_PARM_PREVIEW_MODE
        18 = CAMERA_PARM_ANTIBANDING
        19 = CAMERA_PARM_THUMBNAIL_WIDTH
        20 = CAMERA_PARM_THUMBNAIL_HEIGHT
        21 = CAMERA_PARM_THUMBNAIL_QUALITY
   \endcode


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piMinimumValue - Returns the minimum value of the operational parameter.
   \param piMaximumValue - Returns the maximum value of the operational parameter.
   \param piStepValue    - Returns the step value of the operational parameter.
   \param piDefaultValue - Returns the default value of the operational parameter.
   \param piCurrentValue - Returns the current value of the operational parameter.

   \param  piCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_GET_PARM
   (
      HANDLE hResourceContext, unsigned short iParmId, unsigned long* piMinimumValue,
      unsigned long* piMaximumValue, unsigned long* piStepValue, unsigned long* piDefaultValue,
      unsigned long* piCurrentValue, unsigned short* piCameraStatus
   );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, 2.3.10 Camera Get Info
      This command retreives camera information such as the sensor width, height, rotation and
      orientation. Refer to Chapter 3 for possible sensor resolutions.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piSensorWidth  - Returns the sensor width.
   \param piSensorHeight - Returns the sensor height.
   \param piFPS          - Returns the frames per second.
   \param piSensorRotationSensing  - Returns whether the sensor can sense when it is rotated (0 = not rotated, 1=Rotated)
   \param piDefaultRotation        - Returns the default rotation value when the sensor is not rotated.
   \param piDefaultOrientation     - Returns orientation (landscape or portrait):
   \code
        0 = CAMERA_ORIENTATION_LANDSCAPE
        1 = CAMERA_ORIENTATION_PORTRAIT
   \endcode

   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_GET_INFO
   (   HANDLE hResourceContext,
      unsigned short* piSensorWidth, unsigned short* piSensorHeight,
      unsigned short* piFPS, unsigned char* piSensorRotationSensing,
      unsigned short* piDefaultRotation,  unsigned short* piDefaultOrientation,
      unsigned short* piCameraStatus
   );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, Select camera sensor
      This command selects which camera sensor will be used for subsequent calls
      to the FTM Camera API.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSensorID  - Sensor number to select.  The sensor number is the same ID number used
                       in the embedded source code, specifically to the call to
                  camera_select_sensor().  If you are unsure of the sensor ID, then ask
                  the embedded developers.

   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_SET_SENSOR_ID
   (   HANDLE hResourceContext,
      unsigned char iSensorID,
      unsigned short* piCameraStatus
   );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, FTM_CAMERA_PerformTakePictureSequencePicture

      This command will sequence several steps in the FTM Camera API to take a picture.
      After this command is issued, the FTM_CAMERA_GetEntirePicture() can be called to return
      the picture data to the PC memory.

      The steps taken are documented in Section A.1 in the FTM Camera API document:
         1) FTM_START_CAMERA
         2) FTM_CAMERA_SET_PARM(  CAMERA_PARM_PREVIEW_MODE, CAMERA_PREVIEW_MODE_SNAPSHOT )
         3) FTM_CAMERA_SET_DIMENSIONS( x, y)
         4) FTM_CAMERA_START_PREVIEW()
         5) Delay delay_ms
         6) FTM_CAMERA_STOP_PREVIEW()
         7) image_size = FTM_CAMERA_TAKE_PICTURE_AND_ENCODE( quality, format )
         8) Return image_size


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bAudioPictureWidth - 1=Determine picture dimentions automatically, by using the largest size possible
                               for the installed sensor.  If this value == 1, then the iPictureWidth and iPictureHeight
                        values are ignored.

                               0=Use the dimensions specified in iPictureWidth and iPictureHeight
   \param iPictureWidth - This is the horizontal width of the picture in number of pixels.
   \param iPictureHeight- This is the Vertical height of the picture in number of pixels.
   \param iDelay_ms - delay in milliseconds between the Send Request and the Receive Response operations
   \param   iQuality - This is the compression ratio or quality factor (valid range of [1:99],
                      with 1 as the lowest quality and 99 as the highest quality).
   \param iFormat   - Format of picture data:
   \code
               0 = CAMERA_RAW
               1 = CAMERA_JPEG
   \endcode

   \param piPicDataSize = This is the size of the entire picture in bytes.

   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning FTM_STOP_CAMERA() must be called after this function is called.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_PerformTakePictureSequence
   (
      HANDLE hResourceContext,
      unsigned char bAutoPictureSize, unsigned short iPictureWidth, unsigned short iPictureHeight,
      unsigned short iDelay_ms, unsigned long iQuality, unsigned short iFormat,
      unsigned long* piPicDataSize, unsigned short* piCameraStatus
   );

   /******************************************************************************/
   /**
   Factory Test Mode Camera, FTM_CAMERA_GetEntirePicture

      This function calls the FTM_CAMERA_GET_PICTURE funciton as many times as
      necessary to return the entire picture from the phone to the PC.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDataSize - The size of picture data in bytes to retrieve from memory during per transaction.
   \param piPicData - The actual picture data is returned into this buffer, the number of bytes is DATA_SIZE.

   \param  iCameraStatus - Camera services status, returns code from calling camera services API:
   \code
       0 = CAMERA_SUCCESS
       1 = CAMERA_INVALID_STATE
       2 = CAMERA_INVALID_PARM
       3 = CAMERA_INVALID_FORMAT
       4 = CAMERA_NO_SENSOR
       5 = CAMERA_NO_MEMORY
       6 = CAMERA_NOT_SUPPORTED
       7 = CAMERA_FAILED
       8 = CAMERA_INVALID_STAND_ALONE_FORMAT
       9 = CAMERA_MALLOC_FAILED_STAND_ALONE
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_CAMERA_GetEntirePicture
   (
      HANDLE hResourceContext, unsigned long iPicDataSize, unsigned short iDataTransferSize,
      unsigned char* piPicData, unsigned short* piCameraStatus
   );




#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_CAMERA_H)
