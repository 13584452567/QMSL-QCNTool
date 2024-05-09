/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_Linear_Predistortion_Cal_Client.cpp#5 $
 * $DateTime: 2016/04/04 17:51:51 $
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


/* This is the implementation of GSM_Tx_Linear_Process_PreDist_Cal_Results

   Note that SetElementData function is to map the generated data to NV items.  The omission of the function
   does not affect how NV is caclulated.  User will need to use their own mapping function to map the generated
   data into the NVs.

*/


void QMSL_CalDataManager::GSM_Tx_Linear_Process_PreDist_Cal_Results( nv_mode_id_type iNvModeId,
                                                                     QMSL_GSM_PreDist_Cal_Result* aGSM_PreDist_Cal,
                                                                     QMSL_GSM_PreDist_Cal_NV_Chan_struct* aGSM_PreDist_Cal_NV,
                                                                     bool bCachedByNVManager, bool swappedWaveformEdgeFirst)
{


   QMSL_Linear_Predistortion_NV::logParams(aGSM_PreDist_Cal);

   long waveformStart = aGSM_PreDist_Cal->iNoiseSamples;
   long dcDuration = aGSM_PreDist_Cal->iDcSamples;
   long edgeDuration = aGSM_PreDist_Cal->iEdgeSamples;
   long edgeWaveformStart = waveformStart+dcDuration;
   if(swappedWaveformEdgeFirst) edgeWaveformStart = waveformStart;
   long totalSamples  = aGSM_PreDist_Cal->iNumPredistortionWaveformSamples;

   //Skip 90 samples to avoid transients (for gain & phase)
   //Add comment in calibration doc about min of 180 symbols in cal waveform.
   float symbolrate = 270833.0;

   long edgeSkipSymbols = aGSM_PreDist_Cal->iEDGETransientSymbols;
   //Retain Default behaviour if not populated
   if(edgeSkipSymbols == 0) edgeSkipSymbols = 90;
   //Sanity Check on number of samples to skip.
   if(edgeSkipSymbols > 100 ) edgeSkipSymbols = 100;

   long skipSamples = (long)((edgeSkipSymbols/4)*(aGSM_PreDist_Cal->iSamplingRateHz/symbolrate));

   const float * ampl_in_main = &QMSL_Linear_Predistortion_NV::ampl_in[0];
   float ampl_in[ENV_IN_NUM_SAMPLES_SWAPPED];
   float ampl_in_log[ENV_IN_NUM_SAMPLES_SWAPPED];

   long numEnvSamples = QMSL_Linear_Predistortion_NV::numEnvSamples;
   if(swappedWaveformEdgeFirst) numEnvSamples = QMSL_Linear_Predistortion_NV::numEnvSamplesSwapped;

   //Modem Constants
   const float IN_ENV_MAIN_MAX = 13683.0;
   float DIG_GAIN_UNITY;
   float RAMP_UNITY;
   float EXTENSION_FLOOR;
   float IN_ENV_MAX;
   float SCALED_INV_ENV_MAX;
   float DAC_SCALE;

   bool preNikel = true;
   if(1 == aGSM_PreDist_Cal->iOverRideModemConstants)//Expose some parameters for NikeL on
   {
      DIG_GAIN_UNITY = aGSM_PreDist_Cal->dDigGainUnity;
      RAMP_UNITY = aGSM_PreDist_Cal->dRampUnity;
      EXTENSION_FLOOR = aGSM_PreDist_Cal->dExtensionFloor;
      DAC_SCALE = aGSM_PreDist_Cal->dDacScale;
      IN_ENV_MAX = IN_ENV_MAIN_MAX * DAC_SCALE;
      SCALED_INV_ENV_MAX = IN_ENV_MAX * (aGSM_PreDist_Cal->iEDGETxGainParam / DIG_GAIN_UNITY)
                           * (aGSM_PreDist_Cal->iEDGETxCalScale /RAMP_UNITY  );
      preNikel = false;
   }
   else //No Change for Poseidon
   {
      DIG_GAIN_UNITY = 128.0;
      RAMP_UNITY = 4096.0;
      EXTENSION_FLOOR = 1300.0;
      IN_ENV_MAX = IN_ENV_MAIN_MAX;
      SCALED_INV_ENV_MAX = IN_ENV_MAX; //No change for Poseidon/Older Targets
      DAC_SCALE = 1.0;
   }

   const float GAIN_MULT = (SCALED_INV_ENV_MAX / (SCALED_INV_ENV_MAX - EXTENSION_FLOOR));
   float curr_ampl;
   unsigned int loopVar = 0;
   for(loopVar = 0; loopVar < numEnvSamples; loopVar++)
   {
      //Scale
      curr_ampl = ampl_in_main[loopVar] * DAC_SCALE * (aGSM_PreDist_Cal->iEDGETxGainParam / DIG_GAIN_UNITY)
                  * (aGSM_PreDist_Cal->iEDGETxCalScale /RAMP_UNITY  );
      //Extend
      curr_ampl = (curr_ampl - EXTENSION_FLOOR) * GAIN_MULT;
      if(curr_ampl <= 0.0)
      {
         curr_ampl = 0.1;
      }
      ampl_in[loopVar] = curr_ampl;
      ampl_in_log[loopVar] = 20*log10(curr_ampl);
   }

   //#define CREATE_DEBUG_REFERENCE_DATA
#ifdef CREATE_DEBUG_REFERENCE_DATA
   FILE *ref_fp = fopen("C:\\Reference_Waveform.csv","w");
   int debugLpVar;
   for(debugLpVar = 0; debugLpVar < edgeDuration; debugLpVar++)
   {
      if(debugLpVar < numEnvSamples)
         fprintf(ref_fp, "%f,%f\n",ampl_in[debugLpVar],ampl_in_main[debugLpVar]);
   }
   fclose(ref_fp);
#endif

   QMSL_MeasurementType measTypeAMAM,measTypeAMPM,measTypePredRgi;
   measTypePredRgi = QMSL_GSM_TX_AGC_SETTING_FOR_PRED_I;

   // For AMAM_DYNRANGE NV
   float minOfMaxPowerVsChannel = +99;

   map<unsigned long, vector<float> > inPwrChanAMAM;
   map<unsigned long, vector<float> > inPwrChanAMPM;
   map<unsigned long, vector<float> > smGainChan;
   map<unsigned long, vector<float> > smPhseChan;

   //For Each channel
   unsigned long channelLoopVar = 0;
   for(channelLoopVar = 0; channelLoopVar < aGSM_PreDist_Cal->iNumChannels; channelLoopVar++)
   {
      float *ampl = aGSM_PreDist_Cal->adTxAmpl[channelLoopVar];
      float *phse = aGSM_PreDist_Cal->adTxPhaseArr[channelLoopVar];


      //Step 1: Estimate and Correct Phase Drift
      //Ignore first 60% & last 10% of dcDuration to avoid transients while computing phase slope
      float dcSkipPercent = aGSM_PreDist_Cal->iDCTransientPercent;
      //Apply Default to retain behaviour if SkipPercent Not populated
      if(dcSkipPercent == 0.0) dcSkipPercent = 60.0;
      //Apply Sanity Limits
      if(dcSkipPercent < 10) dcSkipPercent = 10.0;
      if(dcSkipPercent > 60) dcSkipPercent = 60.0;

      long estStart = waveformStart + dcDuration*dcSkipPercent/100;
      long estEnd   = waveformStart + dcDuration*9/10;

      if(swappedWaveformEdgeFirst)
      {
         estStart = waveformStart + edgeDuration + dcDuration*dcSkipPercent/100;
         estEnd   = waveformStart + edgeDuration + dcDuration*9/10;
      }

      aGSM_PreDist_Cal_NV->afreqErrEstimate[channelLoopVar] = QMSL_Linear_Predistortion_NV::estimateAndCorrectPhaseDrift(phse,estStart,estEnd,waveformStart,totalSamples);


      //Step 2: Get Alignment
      const int negDelayMargin = 200;
      long delay;
      if(preNikel)
      {
         delay = QMSL_Linear_Predistortion_NV::crossCorrelateIQFFT
                 (&ampl[edgeWaveformStart-negDelayMargin],&ampl_in[0], edgeDuration, numEnvSamples);
         delay = delay-negDelayMargin;
         delay = delay + 1; //Fix Delay to match Poseidon/Genesis Delay, + 1 : magic number
      }
      else
      {
         delay = QMSL_Linear_Predistortion_NV::crossCorrelateIQFFT
                 (&ampl[edgeWaveformStart-negDelayMargin],&ampl_in_log[0], edgeDuration, numEnvSamples);
         delay = delay-negDelayMargin;
         //Finding Variability in Delay estimates over run for NikeL.
         //Need to determine the delay that resutls in smallest spread of AMAM
         delay = delay + 1;
         delay = delay + QMSL_Linear_Predistortion_NV::updateDelay(&ampl_in_log[0],&ampl[edgeWaveformStart+delay],numEnvSamples);
      }

      aGSM_PreDist_Cal_NV->aDelayEstimate[channelLoopVar] = delay;

      //Vectors to hold inputpwr,gain,phase distortion
      //Make 2 extra to confirm that the output of the gain and phase function return the same.
      //These inPwr are in dBm and gain is in dB.
      vector<float> inPwr,inPwr1,inPwr2;
      vector<float> gain;
      vector<float> phase;

      //Step 3: Compute Gain
      QMSL_Linear_Predistortion_NV::computeGain
      (ampl_in, &ampl[edgeWaveformStart+delay], numEnvSamples,skipSamples,inPwr1,gain);

      //Step 4: Compute Phase (In Phase = 0);
      QMSL_Linear_Predistortion_NV::computePhase
      (ampl_in, &phse[edgeWaveformStart+delay], numEnvSamples,skipSamples,inPwr2,phase);

      if(inPwr1 == inPwr2)
      {
         inPwr = inPwr1;
      }

      //Step 5: Truncate Below Some Input Level

      float chosenInputLevelToTruncate;
      if(preNikel)
      {
         //Hardcoded only for pre NikeL targets
         chosenInputLevelToTruncate = 60;
      }
      else
      {
         //For NikeL the Pin + 3 dB seems empirically to be a good truncation point
         chosenInputLevelToTruncate = (*min_element(inPwr.begin(),inPwr.end())) + 3;
      }
      QMSL_Linear_Predistortion_NV::truncateData( chosenInputLevelToTruncate, inPwr,gain, phase);

      //Step 6: Smooth
      float AMAM_KNOT = (float)2.0;
      float AMPM_KNOT = (float)2.0;
      if(aGSM_PreDist_Cal->iOverrideSmooothingDefaults)
      {
         AMAM_KNOT = aGSM_PreDist_Cal->dAmAmKnot;
         AMPM_KNOT = aGSM_PreDist_Cal->dAmPmKnot;
      }
      vector<float> smoothedGain,smoothedPhaseDistortion;
      QMSL_Linear_Predistortion_NV::smoothData(inPwr,gain,smoothedGain,AMAM_KNOT,true);
      if(aGSM_PreDist_Cal->iOverrideSmooothingDefaults)
      {
         if(aGSM_PreDist_Cal->iEnableAmAmSmoothing == 0)
            smoothedGain = gain;
      }
      QMSL_Linear_Predistortion_NV::smoothData(inPwr,phase,smoothedPhaseDistortion,AMPM_KNOT,true);

      //Step 6.1 : Store the inPwr, Gain
      inPwrChanAMAM[channelLoopVar] = inPwr;
      smGainChan[channelLoopVar] = smoothedGain;

      //Step 6.2 : Truncate Again for AMPM and Store inPwr and Phase Dist
      //Todo: Hardcoded now. Fix Later
      //Maybe : Do offset from min Pin + 8dB
      if(preNikel)
      {
         chosenInputLevelToTruncate = 64;
      }
      QMSL_Linear_Predistortion_NV::truncateData( chosenInputLevelToTruncate, inPwr,smoothedGain,smoothedPhaseDistortion);

      inPwrChanAMPM[channelLoopVar] = inPwr;
      smPhseChan[channelLoopVar] = smoothedPhaseDistortion;

      //Step 7: Generate NV

      //Step 7.1 : Generate AMAM NV

      //Step 7.1.1 : Generate Target Output Powers
      float * amplEdgeWaveform = &ampl[edgeWaveformStart+delay];
      vector<float> measPwr(amplEdgeWaveform,amplEdgeWaveform+numEnvSamples);
      //measPwr in dBm
      // Fix NV Generation Power List : Only use samples that were used for AMAM/AMPM NV Computation and
      // not the entire EDGE duration. This fix worksaround a bug in MDM9k, where some of the initial
      // samples of the reference waveform are replaced by DC portion.
      float maxPowerOutput = *max_element(measPwr.begin()+skipSamples,measPwr.end()-skipSamples);
      if(maxPowerOutput < minOfMaxPowerVsChannel)
      {
         minOfMaxPowerVsChannel = maxPowerOutput;
      }

      //Store Min Power in EDGE duration as a sanity check
      aGSM_PreDist_Cal_NV->aMinPowerInEdgeDuration[channelLoopVar] = *min_element(measPwr.begin()+skipSamples,measPwr.end()-skipSamples);

   }

   QMSL_Vector<float> targetOutputPowers;

   for(loopVar = 1; loopVar < 128; loopVar++)
   {
      targetOutputPowers.Append(minOfMaxPowerVsChannel + (float)20.0*log10((float)loopVar*128/16383));
   }
   targetOutputPowers.Append(minOfMaxPowerVsChannel);

   for(channelLoopVar = 0; channelLoopVar < aGSM_PreDist_Cal->iNumChannels; channelLoopVar++)
   {
      vector<float> inPwrAMAM = inPwrChanAMAM[channelLoopVar];
      vector<float> inPwrAMPM = inPwrChanAMPM[channelLoopVar];
      vector<float> smoothedGain = smGainChan[channelLoopVar];
      vector<float> smoothedPhaseDistortion = smPhseChan[channelLoopVar];


      // Step 7.1.2 : Generate the NV
      QMSL_Vector<long> amamLinear;
      QMSL_Linear_Predistortion_NV::generateAMAMNV(targetOutputPowers, inPwrAMAM, smoothedGain,amamLinear);

      //Step 7.2 : Generate AMPM NV
      QMSL_Vector<long> amPmProcessed;
      QMSL_Linear_Predistortion_NV::generateAMPMNV(inPwrAMPM,DAC_SCALE,smoothedPhaseDistortion, amPmProcessed );


      //For each channel
      if(aGSM_PreDist_Cal->iFreqMapping[channelLoopVar] == QMSL_POLAR_CAL_F1_CHANNEL)
      {
         measTypeAMAM = QMSL_GSM_AMAM_LINEAR_PA_RANGEA_F1_I;
         measTypeAMPM = QMSL_GSM_AMPM_LINEAR_PA_RANGEA_F1_I;
      }
      if(aGSM_PreDist_Cal->iFreqMapping[channelLoopVar] == QMSL_POLAR_CAL_F2_CHANNEL)
      {
         measTypeAMAM = QMSL_GSM_AMAM_LINEAR_PA_RANGEA_F2_I;
         measTypeAMPM = QMSL_GSM_AMPM_LINEAR_PA_RANGEA_F2_I;
      }
      if(aGSM_PreDist_Cal->iFreqMapping[channelLoopVar] == QMSL_POLAR_CAL_F3_CHANNEL)
      {
         measTypeAMAM = QMSL_GSM_AMAM_LINEAR_PA_RANGEA_F3_I;
         measTypeAMPM = QMSL_GSM_AMPM_LINEAR_PA_RANGEA_F3_I;
      }

      //Need to store amamLinear, amPmWrapped
      QMSL_IntVector amam_seg1,amam_seg2,ampm_seg1,ampm_seg2;
      amam_seg1.Clear();
      amam_seg2.Clear();
      ampm_seg1.Clear();
      ampm_seg2.Clear();
      for(unsigned long loopVar = 0; loopVar < 2*QMSL_NV_MANAGER_POLAR_CAL_AMAM_TABLE_SIZE; loopVar++)
      {
         if(loopVar < QMSL_NV_MANAGER_POLAR_CAL_AMAM_TABLE_SIZE)
         {
            amam_seg1.Append((unsigned short)amamLinear[loopVar]);
            aGSM_PreDist_Cal_NV->aAMAM_AMPM_NV[channelLoopVar].aAMAM_NV[0].AMAM[loopVar]=(unsigned short)amamLinear[loopVar];
            ampm_seg1.Append((short)amPmProcessed[loopVar]);
            aGSM_PreDist_Cal_NV->aAMAM_AMPM_NV[channelLoopVar].aAMPM_NV[0].AMPM[loopVar]=(short)amPmProcessed[loopVar];
         }
         else
         {
            amam_seg2.Append((unsigned short)amamLinear[loopVar]);
            aGSM_PreDist_Cal_NV->aAMAM_AMPM_NV[channelLoopVar].aAMAM_NV[1].AMAM[loopVar - QMSL_NV_MANAGER_POLAR_CAL_AMAM_TABLE_SIZE ]
               =(unsigned short)amamLinear[loopVar];
            ampm_seg2.Append((short)amPmProcessed[loopVar]);
            aGSM_PreDist_Cal_NV->aAMAM_AMPM_NV[channelLoopVar].aAMPM_NV[1].AMPM[loopVar - QMSL_NV_MANAGER_POLAR_CAL_AMAM_TABLE_SIZE ]
               =(short)amPmProcessed[loopVar];
         }
      }
      m_oNV_Manager.SetElementData(amam_seg1,iNvModeId,measTypeAMAM, 1, true, bCachedByNVManager,
                                   &aGSM_PreDist_Cal_NV->aAMAM_AMPM_NV[channelLoopVar].aAMAM_NV[0].oNVitem);
      m_oNV_Manager.SetElementData(amam_seg2,iNvModeId,measTypeAMAM, 2, true, bCachedByNVManager,
                                   &aGSM_PreDist_Cal_NV->aAMAM_AMPM_NV[channelLoopVar].aAMAM_NV[1].oNVitem);

      m_oNV_Manager.SetElementData(ampm_seg1,iNvModeId,measTypeAMPM, 1, true, bCachedByNVManager,
                                   &aGSM_PreDist_Cal_NV->aAMAM_AMPM_NV[channelLoopVar].aAMPM_NV[0].oNVitem);
      m_oNV_Manager.SetElementData(ampm_seg2,iNvModeId,measTypeAMPM, 2, true, bCachedByNVManager,
                                   &aGSM_PreDist_Cal_NV->aAMAM_AMPM_NV[channelLoopVar].aAMPM_NV[1].oNVitem);
   }

   QMSL_IntVector predRgi;
   predRgi.Clear();
   predRgi.Append(aGSM_PreDist_Cal->iCalRgi);
   aGSM_PreDist_Cal_NV->aCalRGI.iPredistRGI = aGSM_PreDist_Cal->iCalRgi;
   m_oNV_Manager.SetElementData(predRgi,iNvModeId,measTypePredRgi, 0, true, bCachedByNVManager,
                                &aGSM_PreDist_Cal_NV->aCalRGI.oNVitem);

   QMSL_IntVector dynamicRange;
   dynamicRange.Append((int) (minOfMaxPowerVsChannel *100 ));
   dynamicRange.Append((int) 0);
   aGSM_PreDist_Cal_NV->aDyanmicRange.iMaxPower = (int) (minOfMaxPowerVsChannel *100 );
   m_oNV_Manager.SetElementData(dynamicRange,iNvModeId, QMSL_GSM_AMAM_DYNAMIC_RANGE, 0, true,
                                bCachedByNVManager, &aGSM_PreDist_Cal_NV->aDyanmicRange.oNVitem);
}


