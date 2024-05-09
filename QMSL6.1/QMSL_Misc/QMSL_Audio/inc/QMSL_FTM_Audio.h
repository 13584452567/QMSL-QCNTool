/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Misc/QMSL_Audio/inc/QMSL_FTM_Audio.h#4 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_Audio
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_AUDIO_H)
#define _QMSL_FTM_AUDIO_H

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
                     Audio FTM
   *******************************************************************************/
   /******************************************************************************/
   /**
   Factory Test Mode Audio, 2.4 Audio Set Path command

      The audio set path command activates a supported audio device in the phone. The audio device
      refers to the physical connection of a microphone/speaker or another audio input/output hardware
      to one of the vocoders PCM paths. Typical audio devices are handset, headset, and Bluetooth
      headset.

      NOTE Since some of the audio devices are featurized, not all audio devices are available on all
      platforms. If an audio path selected is not supported in the phone, the status field in the response
      packet is set to 2.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param  iAudioDevice - set the receive/transmit pair of audio devices

   \code
      0 = Handset
      1 = Handsfree kit
      2 = Mono headset
      3 = Stereo headset
      4 = Analog handsfree kit
      5 = Stereo DAC
      6 = Speaker phone
      7 = TTY Handsfree kit
      8 = TTY headset
      9 = TTY VCO
      10 = TTY HCO
      11 = Bluetooth intercom
      12 = Bluetooth headset
      13 = Bluetooth local audio
      14 = USB audio
      15 = SND_DEVICE_FM_RADIO_HEADSET
      16 = SND_DEVICE_FTM_HANDSET
      17 = SND_DEVICE_FTM_HEADSET
      18 = SND_DEVICE_FTM_SPEAKER
      19 = SND_DEVICE_FTM_CARKIT

   \endcode
      * The microphone and speaker used by each audio device varies between platforms. Refer
      to file msmaud.h for the mapping between audio devices and microphone/speaker pairs.


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_SET_PATH( HANDLE hResourceContext, unsigned short iAudioDevice );

   /******************************************************************************/
   /**
   Factory Test Mode Audio, 2.5 Audio Set Volume command
      The audio set volume command sets the RXvolume on the current audio path to the specified
      level (reference Figure 2-1). The volume steps are defined in arrays corresponding to the sound
      device and method in sndcal.c. Volume steps are from 0...4 (0 being mute and 4 being the
      loudest).

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iVolume - Volume steps from 0...4

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_SET_VOLUME( HANDLE hResourceContext, unsigned char iVolume );


   /******************************************************************************/
   /**
   Factory Test Mode Audio, 2.6 Audio DSP Loopback command

      The DSP loopback command can be used to perform an audio loopback in the DSP. After this
      command is sent, audio samples from the microphone specified in the current audio path are
      routed to the corresponding speaker.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bLoopbackOn - unsigned charean to switch DSP loopback on or off. 0 = Off, 1 = On

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_DSP_LOOPBACK( HANDLE hResourceContext, unsigned char bLoopbackOn );

   /******************************************************************************/
   /**
   Factory Test Mode Audio, 2.7 Audio PCM Loopback command
      The PCM loopback command can be used to perform a PCM loopback in the codec. Once this
      command is sent, audio samples from the microphone specified in the current audio path are
      looped back in the codec to the corresponding speaker.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param bLoopbackOn  - unsigned charean to switch PCM loopback on or off. 0 = Off, 1 = On

   \code
   \endcode


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_PCM_LOOPBACK( HANDLE hResourceContext, unsigned char bLoopbackOn );

   /******************************************************************************/
   /**
   Factory Test Mode Audio, 2.8 Audio Tones Play command

      The tones play command can be used to play out tones in specified frequencies, using the speaker
      in the current audio path. The user can specify up to two frequencies, the higher one first.

      Only one frequency is desired, the iLoFreq parameter is set to 0

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iHiFreq - Higher of the two frequencies in Hz. The maximum frequency that can be specified is 3500 Hz
   \param iLoFreq - Lower of the two frequencies in Hz. The minimum, frequency that can be specified is 50 Hz
   \param iMethod - method to play the sound. FTM_Audio_Sound_Methods_Enum can be used for the
                    basic values, but the specific audio features must be known to access methods beyond #3
      \code

          SND_METHOD_VOICE = 0,   // Use the device's voice generator

          // Application-Specific Methods

          SND_METHOD_KEY_BEEP = 1,// Use the device's keybeep generator
          SND_METHOD_MESSAGE = 2, // Use the path's ringer, or voice generator
          SND_METHOD_RING = 3,    // Use the device's ring generator
          #ifdef FEATURE_CLICK
             SND_METHOD_CLICK,       // Use the device's click generator
          #endif
          #if defined(FEATURE_AUDIO_FORMAT) || defined(FEATURE_MIDI_OUT)
            SND_METHOD_MIDI,        // Use the device's Midi generator
          #endif
            SND_METHOD_AUX,         // Use the device's auxiliary generator if avail.
            SND_METHOD_MAX          // Always last in the list

      \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_TONES_PLAY
   ( HANDLE hResourceContext, unsigned short iHiFreq, unsigned short iLoFreq, unsigned short iMethod );

   /******************************************************************************/
   /**
   Factory Test Mode Audio, 2.9 Audio Tones Stop command
      The tones stop command stops the current tone that is being played.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_TONES_STOP( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode Audio, 2.10 Audio Noise Suppressor command
      The noise suppressor command can be used to turn the noise suppressor on or off.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iNoiseSuppressorOn - 0 = Off, 1 = On (the default state)

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_NS_CONTROL( HANDLE hResourceContext, unsigned char iNoiseSuppressorOn );


   /******************************************************************************/
   /**
   Factory Test Mode Audio,

        Captures PCM data at 8kHz, with 16-bit samples.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNumBuffers - Number of buffers to be captured.  Can be from 1 to 100.

                        Each buffer is 160 samples, 1 sample = 16 bits.
                   100 buffers = 100 * 160 words = 100 * 160 * 2 byte = 32,000 bytes

   \param iDelay_ms - Number of milliseconds to wait between sending the command and receving
                      a response packet.  This time increased as more buffers are captured.
                  The maximum value needed is 2000 for 2 seconds.

   \return true if successful, false if fail.

   \warning QLIB_FTM_AUDIO_PCM_STOP_CAPTURE must be called after the PCM data is transferred to the PC

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_PCM_CAPTURE
   ( HANDLE hResourceContext, unsigned short iNumBuffers, unsigned short iDelay_ms);

   /******************************************************************************/
   /**
   Factory Test Mode Audio,
      Releases the memory buffer held for the captured PCM data.
      Must be called after QLIB_FTM_AUDIO_PCM_CAPTURE.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_PCM_STOP_CAPTURE( HANDLE hResourceContext );

   /******************************************************************************/
   /**
   Factory Test Mode Audio, 2.11 Get Audio PCM Capture Data
      This command is used to return the data from a PCM capture.  Data is
      separated into section of 512 bytes.  This command returns one section of the
      data last captured using the FTM_AUDIO_PCM_CAPTURE command


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iDataOffset - Offset in the PCM Capture buffer from which to return.
   \param iDataSize   - Number of bytes to transfer

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_GET_PCM_CAPTURE_DATA
   ( HANDLE hResourceContext, unsigned long iDataOffset, unsigned short iDataSize, unsigned char* pBuffer);

   /******************************************************************************/
   /**
   Factory Test Mode Audio

      This function calls the FTM_AUDIO_PCM_CAPTURE and FTM_AUDIO_GET_PCM_CAPTURE_DATA
      functions such that the PCM data will be captured and all of the data filled
      into the pBuffer storage area specified by the user.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iNumBuffers - Number of buffers to be captured.  Can be from 1 to 100.

                        Each buffer is 160 samples, 1 sample = 16 bits.
                   100 buffers = 100 * 160 words = 100 * 160 * 2 byte = 32,000 bytes

   \param iDelay_ms - delay in milliseconds between the Send Request and the receive Response operations
   \param pBuffer = storage space for PCM data.  For buffer size, see comments for bCreateWAVformat

   \param iDataTransferSize - number of bytes to transfer for each time the
                        FTM_AUDIO_GET_PCM_CAPTURE_DATA function is called.
                   This number should be a factor of the iDataSize number.
                   Only the value 512 will be tested for this parameter.

   \param bCreateWAVformat = Flag to indicate if the buffer should be stored in a WAV format.
                             If set to 0, no action occurs.  If set to 1, the first 44 bytes of
                       the buffer will be filled in with a WAV header and the PCM data
                       will be stored after that.

                             Note!  If this option is set to 1, then the user must specify
                       a buffer that is 44 bytes larger than the PCM data to be captured.

                       The WAV format is referenced from this web site:
                          http://ccrma.stanford.edu/courses/422/projects/WaveFormat/
   \code
       The WAV header is created as follows:
       // WAVE Header
       const dword c_iWAV_HeaderSize = 44;
       const byte c_iWAV_HeaderBuffer[ c_iWAV_HeaderSize ] =
       {
       0x52, 0x49, 0x46, 0x46, 0x3E, 0xA4, 0x00, 0x00, // 1-8
       0x57, 0x41, 0x56, 0x45, 0x66, 0x6D, 0x74, 0x20, // 9-16
       0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, // 17-24
       0x40, 0x1F, 0x00, 0x00, 0x80, 0x3E, 0x00, 0x00, // 25-32
       0x02, 0x00, 0x10, 0x00, 0x64, 0x61, 0x74, 0x61, // 33-40
       0x80, 0x3E, 0x00, 0x00                          // 41-44
       };
   \endcode


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_CapturePCMandTransferData
   (   HANDLE hResourceContext,
      unsigned short iNumBuffers,
      unsigned short iDelay_ms,
      unsigned char* pBuffer,
      unsigned short iDataTransferSize,
      unsigned char bCreateWAVformat
   );


   /******************************************************************************/
   /**
   Factory Test Mode Audio,
      Set the adjustment factor for CodecTxGain.
      The change will take effect immediately in the codec.

      The value still needs to be written to the NV item NV_CODECTXGAIN_ADJUST_I
      once the proper level is determined.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iCodecTxGainAdjust = adjustment value from -600 to +600, in 1/100dB steps

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_SET_CODECTXGAIN_ADJUST( HANDLE hResourceContext, short iCodecTxGainAdjust );
   /******************************************************************************/
   /**
   Factory Test Mode Audio,

   The Audio Set path command activates an input and an output device pairing for the FTM DSP Loopback and Tone Play test.

   NOTE: This API is introduced in MSM7x30 chipset targets. It replaces the FTM_AUDIO_SET_PATH 5 audio command for targets
   that follow the MSM7x30 chipset. This API is not available for pre-MSM7x30 chipset targets.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iInputDevice = Available options (depends on actual product requirements)
                     0  Handset Microphone (Mic1)
                     1  Headset Microphone (Mic2)
                     2  Digital Microphone 1
                     3  Digital Microphone 2
                     4  Digital Microphone 3
                     5  Digital Microphone 4
                     6  Aux In (analog)
                     7  FM Input (L and R)
                     8  LineIn Left
                     9  LineIn Right
                     10  Mic1 and AuxIn
                     11  Mic1 and Mic2
                     12  Digital Mic1 and Mic2
                     13  Digital Mic3 and Mic4

   \param OutputDevice = Available options (depends on actual product requirements)

                     0  Handset Earphone
                     1  Headset Earphone Left
                     2  Headset Mono Differential Output
                     3  Headset Left & Right
                     4  Speaker Phone 1 Left
                     5  Speaker Phone 1 Left & Right
                     6  Speaker Phone 2 Left
                     7  Speaker Phone 2 Left & Right
                     8  Lineout Left
                     9  Lineout Differential Output
                     10  Lineout Left & Right
                     11  Aux Out
                     12  FM Output (L& R)
                     13  HDMI SD0
                     14  HDMI SD1
                     15  HDMI SD2
                     16  HDMI SD3

   \param iStatus = Available options
               0  Success
               1  Command did not complete successfully
               2  Audio Path is not supported

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_SET_PATH_INPUT_OUTPUT( HANDLE hResourceContext, unsigned short  iInputDevice, unsigned short iOutputDevice, unsigned short* iStatus);
   /******************************************************************************/
   /**
   Factory Test Mode Audio,

   The Enable PCM Recording command starts PCM audio recording. The audio data cannot exceed 100 buffers.

   Each buffer contains 160 samples. This API is intended for use with FTM_AUDIO_GET_PCM_SAMPLES.

   NOTE: This API is introduced in MSM7x30 chipset targets and will replace the
   FTM_AUDIO_SET_PATH audio command for targets after the M7x30 chipset.
   This API will not be available for pre-MSM7x30 chipset targets.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iNum_PCM_Buffers = Nummber of PCM buffers (frame)

   \param iRate = PCM Sampling Rate 8000/16000/48000

   \param iNum_Channels = Numer of channels,

   \param iSample_Width = 8/16/24/32

   \param iFrameSize = Typical frame size = 160 for 8k voice

   \param sFileName = e_file name to store recorded PCM data

                  If efile_name is empty, data is saved to memory instead;
                  FTM_AUDIO_GET_PCM_SAMPLES is sent to phone to get PCM data after this command;
                  else, if a valid path exists, PCM data is saved to e_file in Flash memory on phone;
                  FTM_AUDIO_GET_PCM_SAMPLES are not issued

                  The filename size should not exceed 50 bytes

   \param sFilePath = e_file location in phone, QRCT will prefix standard e-file root directory to path user selected

                  The file path should not exceeed 128 bytes

   \param iStatus = Status
                0 - Success
                1 - Command did not complete successfully

   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_AUDIO_PCM_ENABLE_WITH_PARAMS( HANDLE hResourceContext, unsigned short iNum_PCM_Buffers, unsigned short iRate,  unsigned short iNum_Channels, unsigned short iSample_Width, unsigned short iFrameSize, char* sFileName, char* sFilePath, unsigned short* iStatus);



#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QLIB_FTM_AUDIO_H)
