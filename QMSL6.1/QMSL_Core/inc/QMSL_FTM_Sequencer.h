/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_Core/inc/QMSL_FTM_Sequencer.h#5 $
 * $DateTime: 2015/12/30 13:50:30 $
 *
 * DESCRIPTION: QMSL_FTM_Sequencer
 ******************************************************************************
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */
#if !defined(_QMSL_FTM_SEQUENCER_H)
#define _QMSL_FTM_SEQUENCER_H

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
                        FTM Sequencer
      *******************************************************************************/

   /******************************************************************************/
   /**
      Activate the sequenceing engine, either on PC or AMSS.  Subsequent QMSL calls will cache the diag command
      either on sequencing engine inside QMSL or AMSS

      The cached diag commands will only be executed or processed when QLIB_FTM_SEQ_EXECUTE_QUEUE() is called.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \return true if the opreation is successful

      \warning this function does not send any diag commands to mobile

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_ActivateBatchMode(HANDLE hResourceContext);

   /******************************************************************************/
   /**
      Deactivate the sequencing engine, either on PC or AMSS.  Subsequent QMSL calls will send the diag command
      to mobile. The diag command will be executed immediately.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \return true if the opreation is successful

      \warning this function does not send any diag commands to mobile

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_DeactivateBatchMode(HANDLE hResourceContext);
   /******************************************************************************/
   /**
      Set the to use the sequencer inside QMSL or embedded side.

      QMSL, by default, runs sequencer on AMSS side.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param bSequencerRunningOnPC = 1 (use the sequencer engine inside QMSL), QMSL_FTM_SEQUENCER_MODE_EMBEDDED
                                   = 0 (DEFAULT: use the sequencer engine on embedded side), QMSL_FTM_SEQUENCER_MODE_DESKTOP

      \return true if the opreation is successful

      \warning this function does not send any diag commands to mobile
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_SetSequencerMode(HANDLE hResourceContext, unsigned char bSequencerRunningOnPC);

   /******************************************************************************/
   /**
      Adds a wait relative to the last wait that was received.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iWaitTimeInus, wait time in micro seconds(us)

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_ADD_WAIT(HANDLE hResourceContext, unsigned long iWaitTimeInus, unsigned short* iFTM_Error_Code);


   /******************************************************************************/
   /**
      Controls capturing of commands. When capturing is turned on, all request traffic that is routed
      through the FTM Sequencer will be stored in the command queue for later execution.

      This API has no effect when sequenceing engine runs inside QMSL.

      This API will only work when sequencing engine runs on AMSS.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iCaptureOn, 1 == Turn on the capturing
                         0 == Turn off the capturing

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_CAPTURE_CONTROL(HANDLE hResourceContext, unsigned char iCaptureOn, unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
      This command sets a timing marker at the execution time, so that the next wait, created by FTM_SEQ_ADD_WAIT, will be relative to this point in time.

      This command can be used when the sequence contains some commands of variable duration and it is not necessary to use a fixed wait time.
      For example, if the commands occur before an equipment trigger

      This API has no effect when sequenceing engine runs inside QMSL.

      This API will only work when sequencing engine runs on AMSS.

      \param iFTM_Error_Code 0 = Success
                             1 = Failure

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_ADD_TIMING_MARKER(HANDLE hResourceContext, unsigned short* iFTM_Error);

   /******************************************************************************/
   /**
      Flush the commands buffered in QMSL to embedded (AMSS) sequencer.

      QMSL has 1k buffer.  The buffer will be flushed automatically to embedded sequencer when it is full.

      This API should be called prior to QLIB_FTM_SEQ_EXECUTE_QUEUE

      // embedded sequencer
      QLIB_FTM_SEQ_SetSequencerMode( g_hResourceContext, 0);
      QLIB_FTM_SEQ_ActivateBatchMode( g_hResourceContext );

      for(k = 0; k < 30; k ++)
      {
         QLIB_FTM_SET_PDM(g_hResourceContext, 2, 85 - k  );
         QLIB_FTM_SEQ_ADD_WAIT(g_hResourceContext, 20*ms, &iFTM_Error_Code);
      }

      QLIB_FTM_SEQ_Flush_Command_Buffer();

      QLIB_FTM_SEQ_STATUS( g_hResourceContext, & iFTM_Error_Code, & iQueue_Item_Count, &bIsExecuting, &iNext_ID_Number, & iTimeRef);
      // iQueue_Item_Count = 60 (30*2)
      // if QLIB_FTM_SEQ_Flush_Command_Buffer is not called, iQueue_Item_Count will be less than 60 as some commands
      // are still buffered up in QMSL

      QLIB_FTM_SEQ_EXECUTE_QUEUE( g_hResourceContext, &iFTM_Error_Code );


      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_Flush_Command_Buffer(HANDLE hResourceContext);

   /******************************************************************************/
   /**
      Resize QMSL local queued command buffer. The default size is defined as FTM_Sequencer_Command_Queue_Buffer_Size in QLib_Defines.h

      This function should be called when local queued command buffer is empty.  The command buffer is empty.

      The command buffer is empty either 1) after queue is executed or 2) no commands has been added to the queue.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iNewSize.  New size of the buffer.  It should be less than or equal to MAX_FTM_Sequencer_Command_Queue_Buffer_Size in QLib_Defines.h
                    It should never exceed the maximum diagnostic packet size handled by AMSS.

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_Resize_Command_Buffer(HANDLE hResourceContext, unsigned short iNewSize);

   /******************************************************************************/
   /**
      Executes the existing FTM Sequencer queue of FTM messages.

      This is a blocking function.  The function will return after the last command has been executed.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iFTM_Error_Code, FTM Error Code returned by embedded side

      \param iSequenceCompleted, 1 = FTM_SEQ_EXECUTE_QUEUE command returns.  Sequence completed before timeout,
                                 0 = FTM_SEQ_EXECUTE_QUEUE command returns.  Sequence did not complete before timeout
                           2 = FTM_SEQ_EXECUTE_QUEUE does not returns due to modem crash. or FTM_SEQ_EXECUTE_QUEUE command is not supported.

      \note Use QLIB_ConfigureTimeOut(hQMSL, QMSL_Timeout_Embedded_Sequencer_Execution) to configure the time out value

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_EXECUTE_QUEUE(HANDLE hResourceContext, unsigned short* iFTM_Error_Code, unsigned char *iSequenceCompleted);

   /******************************************************************************/
   /**
      Executes the existing FTM Sequencer queue of FTM messages.

      Unlike  QLIB_FTM_SEQ_EXECUTE_QUEUE, this api doesn't wait for sequencer to finish.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_EXECUTE_QUEUE_No_Wait(HANDLE hResourceContext);

   /******************************************************************************/
   /**
      Waits for FTM Sequencer to finish and updates the responses of all the FTM commands executed in sequencer mode

      The function will return after the last command of the ftm sequencer has been executed.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iFTM_Error_Code, FTM Error Code returned by embedded side

      \param iSequenceCompleted, 1 = FTM_SEQ_EXECUTE_QUEUE command returns.  Sequence completed before timeout,
                                 0 = FTM_SEQ_EXECUTE_QUEUE command returns.  Sequence did not complete before timeout
                                 2 = FTM_SEQ_EXECUTE_QUEUE does not returns due to modem crash. or FTM_SEQ_EXECUTE_QUEUE command is not supported.

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_EXECUTE_QUEUE_No_Wait should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_WAIT_FOR_SEQ_EXECUTION(HANDLE hResourceContext, unsigned short* iFTM_Error_Code, unsigned char *iSequenceCompleted);

   /******************************************************************************/
   /**
      Erases all messages in the FTM Sequencer queue. Resets the FTM Sequencer state machine to be not executing

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_CLEAR_QUEUE(HANDLE hResourceContext, unsigned short* iFTM_Error_Code);

   /******************************************************************************/
   /**
      Check whether any commands in last sequence execution has overrun

      This function should be called after QLIB_FTM_SEQ_EXECUTE_QUEUE

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iOverrun  1 == At least one of the commands from last sequence overran
                       0 == None of the commands from last sequence overran

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_Is_Last_Seqeunce_Overrun(HANDLE hResourceContext, unsigned char* iLast_Sequence_Overrun);

   /******************************************************************************/
   /**
      Create a FTM sequence file on the PC.  The file can then be moved to the modem file system and loaded to
      the embedded sequencer by calling QLIB_FTM_SEQ_LOAD_QUEUE_FROM_FILE.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param sFilePath = The file path on the PC.

      \param iUserVersion = User defined version number

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_CreateSequenceFile (HANDLE hResourceContext, char *sFilePath, unsigned short iUserVersion);

   /******************************************************************************/
   /**
      Return the status of the command queue

      This API has no effect when sequenceing engine runs inside QMSL.

      This API will only work when sequencing engine runs on AMSS.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iFTM_Error_Code, 1 == Error
                        0 == Success

      \param iQueue_Item_Count, the number of items in the FTM Sequencer queue

      \param bIsExecuting,   0  Not currently executing the queue commands
                        1  Currently executing the queue commands

      \param iNext_ID_Number,      If IS_EXECUTING==0  ID_NUMBER of the first item in the FTM Sequencer queue
                           If IS_EXECUTING==1  ID_NUMBER of current item being executed

      \param iTimeRef, TIme value is micro second, relative to the initial time

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_STATUS(HANDLE hResourceContext, unsigned short* iFTM_Error_Code, unsigned long* iQueue_Item_Count, unsigned char *bIsExecuting, unsigned long *iNext_ID_Number, unsigned long* iTimeRef);

   /******************************************************************************/
   /**
      Get the diag command response.  The respond corresponds the command identified by tcommand sequence ID

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iSeqID, the command sequence ID

      \param pData, a user provided data buffer to store the response

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_ActivateBatchMode should be called first
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_GET_RESPONSE(HANDLE hResourceContext, unsigned long iSeqID, unsigned char *pData);

   /******************************************************************************/
   /**
      80-N0528-4, FTM Sequencer Command

      This command stores all queue request items that are currently in memory to a user-specified file. The current queue is not erased or altered during this activity

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()


      \param iFormatVersion =  The file format version.  User should use 0 for this parameter.

      \param iUserVersion = User defined version number

      \param sFileName =  The file will be stored in \FTM_SEQ under the modem file system.  The filename should not
                          include any path information.

                      The file name size should be less 40.

                     The string is a series of signed 8-bit ASCII characters and it must be terminated with a NULL character (0x00).


      \param iFTM_Error_Code = 0 - Success
                               1 - General Error

      \return true if the opreation is successful

      \warning this function does not send any diag commands to mobile
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_STORE_QUEUE_TO_FILE(HANDLE hResourceContext, unsigned short iFormatVersion, unsigned short iUserVersion, unsigned char* sFileName, unsigned short *iFTM_Error_Code);

   /******************************************************************************/
   /**
      80-N0528-4, FTM Sequencer Command

      This command loads queue items from a user-specified file. The current queue is not erased before the load occurs.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param sFileName =  The file will be loaded from \FTM_SEQ under the modem file system.  The filename should not
                          include any path information.

                      The file name size should be less 40.

                     The string is a series of signed 8-bit ASCII characters and it must be terminated with a NULL character (0x00).

      \param iFTM_Error_Code = 0 - Success
                               1 - General Error

      \return true if the opreation is successful

      \warning this function does not send any diag commands to mobile
   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_LOAD_QUEUE_FROM_FILE(HANDLE hResourceContext, unsigned char* sFileName, unsigned short *iFTM_Error_Code);

   /******************************************************************************/
   /**
      80-N0528-4, FTM Sequencer Command

      This command stores, into an EFS file, a set of debug information that is available after
      execution has completed.

      The information includes the request packet data, the response packet data, the command status,
      and timing information, all of which is valuable for debugging issues.

      The user can specify the Mode EFS file that the data will be stored into, under "FTM_SEQ\" folder.

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param sFileName =  The file will be stored in \FTM_QSEQ under the modem embedded file system.
                     The filename should not include any path information.

                     The string is a series of signed 8-bit ASCII characters and it must be terminated
                     with a NULL character (0x00).

                     The maximum nuber of characters in the string, including NULL Character, is 40.

      \param iFTM_Error_Code 0 = Success
                             1 = Failure

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_STORE_DEBUG_INFO_TO_FILE must be called after the mobile has executed a
      sequence using the FTM_SEQ_EXECUTE_QUEUE command.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_STORE_DEBUG_INFO_TO_FILE(HANDLE hResourceContext, unsigned char* sFileName, unsigned short *iFTM_Error_Code);

   /******************************************************************************/
   /**
      80-N0528-4, FTM Sequencer Command

      This is a synchronous FTM Sequencer diagnostic command to report:
      - Timing overrun status plus command ID for the command that first resulted in timing overrun
      - The worst case time delta between the end of one command and the start of the next.
      - Command ID for the command that resulted in worst case time delta

      \param hResourceContext   Resource context that was returned from the call to QLIB_ConnectServer()

      \param iTiming_Overrun_Status  0  No Timing overrun
                                     1  Timing overrun occured

      \param iId_Number_Timing_Overrun If TIMING_OVERRUN_STATUS is value 1  then this field will
                                       contain the ID_NUMBER of the first command in the queue that
                                       resulted in timing overrun.
                                       If iTiming_Overrun_Status is value 0 then this field will
                                       be 0xFFFFFFFF.

      \param iTime_Delta_Worst_Case Reports the worst case time delta between end of one command and
                                    the start of next. If the command is after the ADD_WAIT then the
                                    delta is relative to the expected end of the ADD_WAIT

      \param iId_Number_Time_Delta_Worst_Case ID_NUMBER of the command that followed the worst case
                                              time delta.

      \param iFTM_Status
            0 = Success
            1 = Failure

      \return true if the opreation is successful

      \warning QLIB_FTM_SEQ_TIMING_ERROR_INFO must be called after the mobile has executed a
      sequence using the FTM_SEQ_EXECUTE_QUEUE command.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_FTM_SEQ_TIMING_ERROR_INFO(HANDLE hResourceContext,
         unsigned char* iTiming_Overrun_Status,
         unsigned long* iId_Number_Timing_Overrun,
         unsigned long* iTime_Delta_Worst_Case,
         unsigned long* iId_Number_Time_Delta_Worst_Case,
         unsigned short *iFTM_Status);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif   // defined(_QMSL_FTM_SEQUENCER_H)
