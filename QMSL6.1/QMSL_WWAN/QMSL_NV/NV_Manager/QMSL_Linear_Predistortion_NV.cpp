/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_Linear_Predistortion_NV.cpp#6 $
 * $DateTime: 2016/04/04 17:23:23 $
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

#include "QMSL_Linear_Predistortion_NV.h"
#if !defined( QMSL_POSIX_PORTABLE )
#else
void ZeroMemory(
   void* Destination,
   unsigned long Length
)
{
   memset((Destination),0, Length);
}
typedef unsigned long DWORD;     //!<' Definition of unsigned 32-bit type
#endif

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <set>
#include "QMSL_Vector.h"
#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
using namespace std;

#define PI 3.1415926538
#define NUMELEMS( arr ) ((sizeof(arr))/(sizeof(arr[0])))

//#define DEBUG_PREDIST_PHASEDRIFT
//#define DEBUG_PREDIST_XCORR
//#define DEBUG_PREDIST_AMAM_GAIN
//#define DEBUG_PREDIST_AMPM_GAIN
//#define DEBUG_SMOOTHING
//#define DEBUG_AMAM
//#define DEBUG_AMPM
//#define DEBUG_PREDIST_IQFFT
//#define DEBUG_SLOPE_COMP
//#define DEBUG_LOG_PREDIST_CAL_PARAMS
//#define DEBUG_UPDATE_DELAY_FOR_AMAM_GAIN_SPREAD

int ComputeFFT(const int isign, int numSamples_In,
               double * m_pDI, double * m_pDQ,
               double * m_pFFTI, double * m_pFFTQ)
{
   DWORD n, mmax, m, j, istep, i;
   double wtemp, wr, wpr, wi, wpi, theta,
          tempr, tempi;

   const DWORD nn = 32768;
   double* data = new double[2 * nn + 1];

   for (i = 1; i <= nn; i++)
   {
      data[2*i - 1] = 0.0;//zero out buffer
      data[2*i] = 0.0;//zero out buffer

      if(i < static_cast<unsigned int>(numSamples_In))
      {
         data[2*i - 1] = m_pDI[i-1];
         data[2*i] = m_pDQ[i-1];
      }

   }

   n = nn << 1;
   j = 1;

   //Perform bit-reversing
   for(i = 1; i < n; i += 2)
   {
      if(j > i)
      {
         SWAP(data[j], data[i]);
         SWAP(data[j+1], data[i+1]);
      }
      m = n >> 1;
      while( m >= 2 && j > m )
      {
         j -= m;
         m >>= 1;
      }
      j += m;
   }

   //Danielson-Lanczos routine
   mmax = 2;
   while( n > mmax)//Executed log2(nn) times.
   {
      istep = mmax << 1;
      theta = isign * 2* acos(-1.0) / mmax;//Initialize trigonometric recurrence
      wtemp = sin(0.5 * theta);
      wpr = -2.0 * wtemp * wtemp;
      wpi = sin(theta);
      wr = 1.0;
      wi = 0.0;
      for(m = 1; m < mmax; m += 2)//Danielson-Lanczos formula application
      {
         for(i = m; i <= n; i += istep)
         {
            j = i + mmax;
            if(j < 2 * nn)
            {
               tempr = wr * data[j] - wi * data[j+1];
               tempi = wr * data[j+1] + wi * data[j];
               data[j] = data[i] - tempr;
               data[j+1] = data[i+1] - tempi;
               data[i] += tempr;
               data[i+1] += tempi;
            }
         }
         wr = (wtemp = wr) * wpr - wi * wpi + wr;//Trigonometric recurrence
         wi = wi * wpr + wtemp * wpi + wi;
      }
      mmax = istep;
   }

   // scale the data if we go in the forward direction
   double divisor;
   if (isign == 1)
      divisor = (double)nn;
   else
      divisor = 1.0;
   for (i = 1; i <= nn ; i++)
   {
      m_pFFTI[i - 1] = 0.0;//zero out buffer
      m_pFFTQ[i - 1] = 0.0;//zero out buffer
      m_pFFTI[i - 1] = data[2 * i - 1] / divisor;
      m_pFFTQ[i - 1] = data[2 * i ] / divisor;
   }

   delete [] data;
   return 0;
}


float QMSL_Linear_Predistortion_NV::estimateAndCorrectPhaseDrift(float * PhaseVec,long estStart,long estEnd, long corrStart,long corrEnd)
{
   float phaseDiffAccum = 0.0;
   long slopeEstimationLength = 0;
   long loopVar = 0;

   //Before Correcting Phase Drift (Unwrap Phase)
   //Input Phase is between +/- 180

   //Fix the whole of the correction Region
   long min_start = 0;
   long max_end   = corrEnd;

#ifdef DEBUG_PREDIST_PHASEDRIFT
   static int i = 0;
   i++;
   ostringstream fnamestr;
   fnamestr.str("");

#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr << "C:\\Qualcomm\\QDART\\Temp\\Phase_Unwrap_" << i << ".csv";
#else
   fnamestr <<P_tmpdir <<"Phase_Unwrap_" << i << ".csv";
#endif



   ofstream phUnWrapFile;
   phUnWrapFile.open (fnamestr.str().c_str(),ios::out);
   phUnWrapFile << "Index,Ph_in,Ph_unWrap"<< endl;
#endif

   //Actual Unwrap (if diff > 170*2)
   for(loopVar = min_start+1; loopVar<=max_end; loopVar++)
   {
#ifdef DEBUG_PREDIST_PHASEDRIFT
      phUnWrapFile << loopVar << "," << PhaseVec[loopVar] << ",";
#endif
      while(fabs(PhaseVec[loopVar] - PhaseVec[loopVar-1]) > 340.0) //>2*pi
      {
         if(PhaseVec[loopVar] > PhaseVec[loopVar-1])
            PhaseVec[loopVar] = PhaseVec[loopVar] - 360;
         else
            PhaseVec[loopVar] = PhaseVec[loopVar] + 360;
      }
#ifdef DEBUG_PREDIST_PHASEDRIFT
      phUnWrapFile << PhaseVec[loopVar] << endl;
#endif
   }


#ifdef DEBUG_PREDIST_PHASEDRIFT
   phUnWrapFile.close();
#endif


   //??Normalize to first value (Set Phase[0]=0);



   for(loopVar = estStart; loopVar<estEnd; loopVar++)
   {
      phaseDiffAccum = phaseDiffAccum + (PhaseVec[loopVar+1] - PhaseVec[loopVar]);
      slopeEstimationLength++;
   }

   float averageSlopeChange = phaseDiffAccum / slopeEstimationLength;

#ifdef DEBUG_PREDIST_PHASEDRIFT
   fnamestr.str("");

#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr << "C:\\Qualcomm\\QDART\\Temp\\Phase_Corr_" << i << ".csv";
#else
   fnamestr <<P_tmpdir<<"Phase_Corr_" << i << ".csv";
#endif

   ofstream phCorrFile;
   phCorrFile.open (fnamestr.str().c_str(),ios::out);
   phCorrFile << "Ph_in,Ph_out"<< endl;
#endif

   for(loopVar = corrStart; loopVar<corrEnd; loopVar++)
   {
#ifdef DEBUG_PREDIST_PHASEDRIFT
      phCorrFile << PhaseVec[loopVar] << ",";
#endif
      PhaseVec[loopVar] = PhaseVec[loopVar] - (loopVar-corrStart)*averageSlopeChange;
#ifdef DEBUG_PREDIST_PHASEDRIFT
      phCorrFile << PhaseVec[loopVar] << endl;
#endif
   }
#ifdef DEBUG_PREDIST_PHASEDRIFT
   phCorrFile.close();
#endif

   return averageSlopeChange;
}

long QMSL_Linear_Predistortion_NV::crossCorrelate(float * CVec1,const float * CVec2, long CVec1Size, long CVec2Size)
{
   //Optimization 1
   //If we have more measured data than Input - truncate measured data
   if(CVec1Size > CVec2Size) CVec1Size = CVec2Size;

   vector <float> tempVec1(CVec1, CVec1+CVec1Size);
   vector <float> tempVec2(CVec2, CVec2+CVec2Size);
   int sizeVec1 = (int)tempVec1.size();
   int sizeVec2 = (int)tempVec2.size();
   unsigned int loopVar = 0;

   unsigned long sizeLargerVec = sizeVec1;

#ifdef DEBUG_PREDIST_XCORR
   static int i = 0;
   i++;
   ostringstream fnamestr1,fnamestr2;
   fnamestr1.str("");
   fnamestr2.str("");


#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr1 << "C:\\Qualcomm\\QDART\\Temp\\Cross_Corr_Inps_v1_" << i << ".csv";
   fnamestr2 << "C:\\Qualcomm\\QDART\\Temp\\Cross_Corr_Inps_v2_" << i << ".csv";
#else
   fnamestr1 <<P_tmpdir<<"Cross_Corr_Inps_v1_" << i << ".csv";
   fnamestr2 <<P_tmpdir<< "Cross_Corr_Inps_v2_" << i << ".csv";
#endif

   ofstream xCorrInFile1,xCorrInFile2;
   xCorrInFile1.open (fnamestr1.str().c_str(),ios::out);
   xCorrInFile2.open (fnamestr2.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < CVec1Size; loopVar++)
   {
      xCorrInFile1 << CVec1[loopVar] << endl;
   }
   for(loopVar = 0; loopVar < CVec2Size; loopVar++)
   {
      xCorrInFile2 << CVec2[loopVar] << endl;
   }
   xCorrInFile1.close();
   xCorrInFile2.close();
#endif

   if(sizeVec1 > sizeVec2)
   {
      tempVec2.resize(sizeVec1,0.0);
   }
   if(sizeVec1 < sizeVec2)
   {
      tempVec1.resize(sizeVec2,0.0);
      sizeLargerVec = sizeVec2;
   }

   unsigned long corrVecLen = 2*sizeLargerVec - 1;

   vector <float>::iterator Vec1BeginIter, Vec1EndIter;
   vector <float>::iterator Vec2BeginIter;

   vector <float> corrVec(corrVecLen);
   Vec1BeginIter = tempVec1.begin();
   Vec1EndIter = tempVec1.begin()+1;
   Vec2BeginIter = tempVec2.end()-1;

   cout << "Corr Vec Len = " << corrVecLen << endl;
   cout << "Correlation Started " << endl;

   for(loopVar = 0; loopVar < corrVecLen && Vec1EndIter != tempVec1.end(); loopVar++)
   {
      if(loopVar < sizeLargerVec)
      {
         corrVec[loopVar] = inner_product(Vec1BeginIter,Vec1EndIter,Vec2BeginIter,(float)0.0);
         ++Vec1EndIter;
         --Vec2BeginIter;
      }
      if(loopVar >= sizeLargerVec)
      {
         if(loopVar == sizeLargerVec)
         {
            Vec2BeginIter = tempVec2.begin();
            Vec1EndIter   = tempVec1.end();
         }
         ++Vec1BeginIter;
         corrVec[loopVar] = inner_product(Vec1BeginIter,Vec1EndIter,Vec2BeginIter,(float)0.0);
      }
   }
   cout << "Correlation Ended " << endl;

   float largestVal = (float)1e-100;
   unsigned long largestInd = 0;

   for(loopVar = 0; loopVar < corrVec.size(); loopVar++)
   {
      if(corrVec[loopVar] > largestVal)
      {
         largestVal = corrVec[loopVar];
         largestInd = loopVar;
      }
   }

#ifdef DEBUG_PREDIST_XCORR
   ostringstream fnamestr3,fnamestr4;
   fnamestr3.str("");
   fnamestr4.str("");

#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr3 << "C:\\Qualcomm\\QDART\\Temp\\Cross_Corr_Op_" << i << ".csv";
   fnamestr4 << "C:\\Qualcomm\\QDART\\Temp\\Cross_Corr_Delay" << i << ".csv";
#else
   fnamestr3 <<P_tmpdir<<"Cross_Corr_Op_" << i << ".csv";
   fnamestr4 <<P_tmpdir<< "Cross_Corr_Delay" << i << ".csv";
#endif

   ofstream xCorrOutFile1,xCorrOutFile2;
   xCorrOutFile1.open (fnamestr3.str().c_str(),ios::out);
   xCorrOutFile2.open (fnamestr4.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < corrVec.size(); loopVar++)
   {
      xCorrOutFile1 << corrVec[loopVar] << endl;
   }
   xCorrOutFile2 << "Delay : " << (largestInd - sizeVec1) << endl;
   xCorrOutFile1.close();
   xCorrOutFile2.close();
#endif

   return (largestInd - sizeVec1);
}

long QMSL_Linear_Predistortion_NV::crossCorrelateIQFFT
(float * CVec1,const float * CVec2, long CVec1Size, long CVec2Size)
{
   if(CVec1Size > CVec2Size) CVec1Size = CVec2Size;

   unsigned int n=CVec1Size;
   const unsigned int np = 32768;

   double* f0 = new double[np];
   double* f1 = new double[np];
   double* f2 = new double[np];

   double* g1_i = new double[np];
   double* g1_q = new double[np];
   double* g2_i = new double[np];
   double* g2_q = new double[np];

   double* f_i = new double[np];
   double* f_q = new double[np];
   double* g_i = new double[np];
   double* g_q = new double[np];

   unsigned int i=0;

   for(i=0; i < n; i++)
   {
      f0[i]=0.0;
      f1[i]=CVec2[i];
      f2[i]=CVec1[i];
   }

#ifdef DEBUG_PREDIST_IQFFT
   static int k=0;
   k++;
   ostringstream fnamestr_in;
   fnamestr_in.str("");
   fnamestr_in << "C:\\Qualcomm\\QDART\\Temp\\IQFFT_In_" << k << ".csv";

   ofstream xCorrInFile1;
   xCorrInFile1.open (fnamestr_in.str().c_str(),ios::out);
   for(unsigned int loopVar = 0; loopVar < n; loopVar++)
   {
      xCorrInFile1 << f1[loopVar] << "," << f2[loopVar] << endl;
   }
   xCorrInFile1.close();
#endif

   ComputeFFT(1, n, f1,f0, g1_i, g1_q);
   ComputeFFT(1, n, f2,f0, g2_i, g2_q);

   for(i=0; i < np; i++)
   {
      g_i[i] = g1_i[i]*g2_i[i] + g1_q[i]*g2_q[i];
      g_q[i] = g1_q[i]*g2_i[i] - g1_i[i]*g2_q[i];
   }

   ComputeFFT(1, n, g_i,g_q, f_i, f_q);

   double maxVal = 0;
   int Index = 0;
   double currentVal;
   for(i=0; i < n/2; i++)
   {
      currentVal = sqrt(f_i[i]*f_i[i]+f_q[i]*f_q[i]);
      if(currentVal > maxVal)
      {
         maxVal = currentVal;
         Index = i;
      }
   }

#ifdef DEBUG_PREDIST_IQFFT
   ostringstream fnamestr1;
   fnamestr1.str("");
   fnamestr1 << "C:\\Qualcomm\\QDART\\Temp\\IQFFT_Op_" << k << ".csv";

   ofstream xCorrOutFile1;
   xCorrOutFile1.open (fnamestr1.str().c_str(),ios::out);
   for(unsigned int loopVar = 0; loopVar < n; loopVar++)
   {
      xCorrOutFile1 << f_i[loopVar] << "," <<f_q[loopVar]<< ","
                    << sqrt(f_i[loopVar]*f_i[loopVar]+f_q[loopVar]*f_q[loopVar]) << endl;
   }
   xCorrOutFile1 << Index << endl;
   xCorrOutFile1.close();
#endif

   delete [] f0;
   delete [] f1;
   delete [] f2;
   delete [] g1_i;
   delete [] g1_q;
   delete [] g2_i;
   delete [] g2_q;
   delete [] g_i;
   delete [] g_q;
   delete [] f_i;
   delete [] f_q;

   return Index;
}

void QMSL_Linear_Predistortion_NV::computeGain(const float * InPwr,float * MeasPwr, unsigned long VecLength,
                                               unsigned long skipSamples, vector<float>& inPwr, vector<float>& gain)
{
   multimap<float, float> Pwr_Gain;
   unsigned int loopVar = 0;

   float minInPwr,maxInPwr;
   minInPwr = 20*log10(*min_element(&InPwr[skipSamples],&InPwr[VecLength-skipSamples]));
   maxInPwr = 20*log10(*max_element(&InPwr[skipSamples],&InPwr[VecLength-skipSamples]));

#ifdef DEBUG_PREDIST_AMAM_GAIN
   static int i = 0;
   i++;
   ostringstream fnamestr1;
   fnamestr1.str("");

#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr1 << "C:\\Qualcomm\\QDART\\Temp\\AMAM_GAIN_Inputs_" << i << ".csv";
#else
   fnamestr1 <<P_tmpdir<<"AMAM_GAIN_Inputs_" << i << ".csv";
#endif

   ofstream amamGainIpFile;
   amamGainIpFile.open (fnamestr1.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < VecLength; loopVar++)
   {
      amamGainIpFile << InPwr[loopVar] << "," << MeasPwr[loopVar]<< endl;
   }
   amamGainIpFile.close();
#endif


   float InPwrdBm;
   float estGain;
   int numSteps = 50;
   float inPwrRange = maxInPwr - minInPwr;
   float inPwrSteps = inPwrRange/numSteps;
   set<float> PwrSet;
   set<float>::iterator pwrIter;
   for(loopVar = 0; loopVar < static_cast<unsigned int>(numSteps); loopVar++)
   {
      PwrSet.insert((minInPwr+inPwrSteps*loopVar));
   }

   pair<multimap<float, float>::iterator, multimap<float, float>::iterator> startStopGains;
   multimap<float, float>::iterator pwrGainIter;

   float currBinInPwr;
   float PrevInPwrdBm;
   for(pwrIter=PwrSet.begin(); pwrIter!=PwrSet.end(); pwrIter++)
   {
      for(loopVar = skipSamples+1; loopVar<(VecLength-skipSamples); loopVar++)
      {
         currBinInPwr = (float)(*pwrIter);
         InPwrdBm = 20*log10(InPwr[loopVar]);
         PrevInPwrdBm = 20*log10(InPwr[loopVar-1]);
         if( (currBinInPwr >= PrevInPwrdBm) && (currBinInPwr <= InPwrdBm) || (currBinInPwr <= PrevInPwrdBm) && (currBinInPwr >= InPwrdBm))
         {
            if(PrevInPwrdBm != InPwrdBm)
            {
               estGain = MeasPwr[loopVar] - currBinInPwr +
                         ((MeasPwr[loopVar-1]-MeasPwr[loopVar])*(currBinInPwr - InPwrdBm))/(PrevInPwrdBm - InPwrdBm);
            }
            else // This will only happen in the currBinInPwr == PrevInPwrdBm == InPwrdBm
            {
               estGain = MeasPwr[loopVar] - currBinInPwr;
            }
            Pwr_Gain.insert(pair<float,float>(*pwrIter, estGain));
         }
      }
   }

   float sumGain;
   float meanGain;
   for(pwrIter=PwrSet.begin(); pwrIter!=PwrSet.end(); pwrIter++)
   {
      startStopGains = Pwr_Gain.equal_range(*pwrIter);

      sumGain = 0.0;

      for(pwrGainIter = startStopGains.first; pwrGainIter != startStopGains.second; pwrGainIter++)
      {
         sumGain = sumGain + (*pwrGainIter).second;
      }
      meanGain = sumGain/Pwr_Gain.count(*pwrIter);
      inPwr.push_back((float)((*pwrIter)));
      gain.push_back(meanGain);
   }
#ifdef DEBUG_PREDIST_AMAM_GAIN
   fnamestr1.str("");

#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr1 << "C:\\Qualcomm\\QDART\\Temp\\AMAM_GAIN_Outputs_" << i << ".csv";
#else
   fnamestr1 <<P_tmpdir<<"AMAM_GAIN_Outputs_" << i << ".csv";
#endif


   ofstream amamGainOpFile;
   amamGainOpFile.open (fnamestr1.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < inPwr.size(); loopVar++)
   {
      amamGainOpFile << inPwr[loopVar] << "," << gain[loopVar]<< endl;
   }
   amamGainOpFile.close();
#endif

}

void QMSL_Linear_Predistortion_NV::computePhase(const float * InPwr, float * MeasPhase, unsigned long VecLength
                                                , unsigned long skipSamples, vector<float>& inPwr, vector<float>& phase)
{
   multimap<float, float> Pwr_Phase;
   unsigned int loopVar =0;

   float minInPwr,maxInPwr;
   minInPwr = 20*log10(*min_element(&InPwr[skipSamples],&InPwr[VecLength-skipSamples]));
   maxInPwr = 20*log10(*max_element(&InPwr[skipSamples],&InPwr[VecLength-skipSamples]));

#ifdef DEBUG_PREDIST_AMPM_GAIN
   static int i = 0;
   i++;
   ostringstream fnamestr1;
   fnamestr1.str("");
   fnamestr1 << "C:\\Qualcomm\\QDART\\Temp\\AMPM_GAIN_Inputs_" << i << ".csv";

   ofstream ampmGainIpFile;
   ampmGainIpFile.open (fnamestr1.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < VecLength; loopVar++)
   {
      ampmGainIpFile << InPwr[loopVar] << "," << MeasPhase[loopVar]<< endl;
   }
   ampmGainIpFile.close();
#endif


   float InPwrdBm;
   float PrevInPwrdBm;
   float estPhase;

   int numSteps = 50;
   float inPwrRange = maxInPwr - minInPwr;
   float inPwrSteps = inPwrRange/numSteps;
   set<float> PwrSet;
   set<float>::iterator pwrIter;
   for(loopVar = 0; loopVar < static_cast<unsigned int>(numSteps); loopVar++)
   {
      PwrSet.insert((minInPwr+inPwrSteps*loopVar));
   }

   float currBinInPwr;
   for(pwrIter=PwrSet.begin(); pwrIter!=PwrSet.end(); pwrIter++)
   {
      for(loopVar = skipSamples+1; loopVar<(VecLength-skipSamples); loopVar++)
      {
         currBinInPwr = *pwrIter;
         InPwrdBm = 20*log10(InPwr[loopVar]);
         PrevInPwrdBm = 20*log10(InPwr[loopVar-1]);
         if( ((currBinInPwr >= PrevInPwrdBm) && (currBinInPwr <= InPwrdBm)) || ((currBinInPwr <= PrevInPwrdBm) && (currBinInPwr >= InPwrdBm)))
         {
            if(PrevInPwrdBm != InPwrdBm)
            {
               estPhase = MeasPhase[loopVar] +
                          ((MeasPhase[loopVar-1]-MeasPhase[loopVar])*(currBinInPwr - InPwrdBm))/(PrevInPwrdBm - InPwrdBm);
            }
            else  // This will only happen in the currBinInPwr == PrevInPwrdBm == InPwrdBm
            {
               estPhase = MeasPhase[loopVar];
            }
            Pwr_Phase.insert(pair<float,float>(*pwrIter, estPhase));
         }
      }
   }

   //With new method set first and last phase distortion to be equal to first_but_one and last_but_one


   pair<multimap<float, float>::iterator, multimap<float, float>::iterator> startStopPhases;
   multimap<float, float>::iterator pwrPhaseIter;

   float sumPhase;
   float meanPhase;
   for(pwrIter=PwrSet.begin(); pwrIter!=PwrSet.end(); pwrIter++)
   {
      startStopPhases = Pwr_Phase.equal_range(*pwrIter);

      sumPhase = 0.0;

      for(pwrPhaseIter = startStopPhases.first; pwrPhaseIter != startStopPhases.second; pwrPhaseIter++)
      {
         sumPhase = sumPhase + (*pwrPhaseIter).second;
      }
      meanPhase = sumPhase/Pwr_Phase.count(*pwrIter);

      inPwr.push_back(*pwrIter);
      phase.push_back(meanPhase);
   }

#ifdef DEBUG_PREDIST_AMPM_GAIN
   fnamestr1.str("");
   fnamestr1 << "C:\\Qualcomm\\QDART\\Temp\\AMPM_GAIN_Outputs_" << i << ".csv";

   ofstream ampmGainOpFile;
   ampmGainOpFile.open (fnamestr1.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < inPwr.size(); loopVar++)
   {
      ampmGainOpFile << inPwr[loopVar] << "," << phase[loopVar]<< endl;
   }
   ampmGainOpFile.close();
#endif
}


void QMSL_Linear_Predistortion_NV::splsmooth(const vector<float>& x, vector<float>& y, int meassize,  const vector<float>& xknots, int NknotIntervals)
{
   int ns,ind2=0,ind1=0,kr,j,li=0,i,lg,currRow;
   int xxknot_size = 0;
   float* R;
   float* A;
   float* coeffs;
   float * M;
   float* xxknots;
   float u = 0 ;
   float v = 0;
   float hj = 0;
   float sum;
   float *G;
   int A_size = 0;

   // Check that NknotIntervals is a valid size
   if ( NknotIntervals == 0 )
      return;

   G = (float*)malloc(25*sizeof(float));
   ns = NknotIntervals+ 3;
   R = (float*)malloc(ns*5*sizeof(float));
   M = (float*)malloc(meassize*4*sizeof(float));
   kr = 0;
   lg = 0;
   currRow = 0;
   xxknot_size = (NknotIntervals+5);
   xxknots = new float[xxknot_size];

   if(!G || !R || !M || !xxknots)
   {
      free(G);
      free(R);
      free(M);
      delete[] xxknots;
      return;
   }

   memset( G, 0, 25*sizeof(float) );
   memset( M, 0, meassize*4*sizeof(float));

   // Initialize xknots memory
   for(i = 0 ; i < xxknot_size ; i++)
   {
      xxknots[i] = 0;
   }

   xxknots[0] = xknots[0];
   xxknots[1] = xknots[0] ;

   for(i = 0 ; i <= NknotIntervals ; i++)
   {
      xxknots[i+2] = xknots[i];
   }
   xxknots[NknotIntervals+3] = xknots[NknotIntervals];
   xxknots[NknotIntervals+4] = xknots[NknotIntervals];

   //Orthogonal transformation
   if(NknotIntervals == 1)
   {
      third_order( x, y, meassize);
      // free allocated memory before returning
      delete[] xxknots;
      free(M);
      free(G);
      free(R);
      return;
   }
   else
   {
      for(j = 0; j <= NknotIntervals-1; j++)
      {
         ind1 = ind2;
         // Find the no of contributions due to interval j.
         while(ind2< meassize && x[ind2] <= xknots[j+1] )
         {
            ind2++;
         }
         li = ind2- ind1;
         if(li)
         {
            //NOTE : ind2 = one past last value in interval
            //Create A
            A_size = (ind2-ind1+lg)*5*sizeof(float);
            A = (float*)malloc(A_size);
            memset((void *) A,0, A_size );

            if(!A)
            {
               delete[] xxknots;
               free(M);
               free(G);
               free(R);
               return;
            }

            hj = xxknots[j+3] -xxknots[j+2];
            for(i = 0 ; i < li ; i++)
            {
               //fill spline matrix.
               u = x[ind1+i] - xxknots[j+2];
               v = xxknots[j+3] - x[ind1+i];
               A[5*i+0] = v/ (hj *(xxknots[j+3] - xxknots[j+1]));

               A[5*i+1] = u/ (hj *(xxknots[j+4] - xxknots[j+2]));
               A[5*i+2] = u * A[5*i+1]/(xxknots[j+5] - xxknots[j+2]);
               A[5*i+1] = ((x[ind1+i] -xxknots[j+1]) * A[5*i+0]  + (xxknots[j+4] - x[ind1+i]) * A[5*i+1])/(xxknots[j+4] - xxknots[j+1]);
               A[5*i+0] = v * A[5*i+0]/(xxknots[j+3] - xxknots[j+0]);
               A[5*i+3] = u* A[5*i+2];
               A[5*i+2] = ((x[ind1+i] - xxknots[j+1]) * A[5*i+1] + (xxknots[j+5] - x[ind1+i])*A[5*i+2]);
               A[5*i+1] = ((x[ind1+i] - xxknots[j])*A[5*i] + (xxknots[j+4] - x[ind1+i])*A[5*i+1]);
               A[5*i] = v*A[5*i];
               //Copy A to M
               M[(currRow)*4+0] = A[5*i];
               M[(currRow)*4+1] = A[5*i+1];
               M[(currRow)*4+2] = A[5*i+2];
               M[(currRow)*4+3] = A[5*i+3];
               currRow++;
               //augment Y to A.
               A[5*i+4] = y[ind1+i];
            }
            if(lg)
            {
               memcpy((void*)(A+5*li),(const void *)G,4*5*sizeof(float));
            }

            qrfact(A,li+lg,5);
            if(li+lg >=5)
            {
               memcpy(G,A,5*5*sizeof(float));
            }
            else
            {
               memcpy(G,A,(li+lg)*5*sizeof(float));
            }

            lg = 4;
            memcpy(R+5*kr,G,5*sizeof(float));
            for(i = 0 ; i < 4; i++)
            {
               memcpy((void *)(G+i*5),(const void*) (G+(i+1)*5+1),3*sizeof(float));
               G[i*5+3] = 0;
               G[i*5+4] = G[(i+1)*5+4];
            }
            //set last row of G to zero
            memset((void*)(G+4*5),0,5*sizeof(float));
            kr = kr+1;
            free(A);
         }
      }//for (j = 0:NKnotIntervals)

      //Transfer last rows to R
      memcpy((void *)(R+kr*5),(const void *)G,5*sizeof(float));
      for(i = 1 ; i < ns-kr; i++)
      {
         memcpy((void*)(R+(kr+i)*5),(const void *)(G+(i)*5+i),(4-i)*sizeof(float));
         memset((void *)(R+(kr+i)*5+4-i) ,0,i*sizeof(float));
         R[(kr+i)*5+4] = G[i*5+4];
      }
   }//if NknotIntervals > 1
   delete[] xxknots;
   free(G);

   //Get coefficients from R
   coeffs = (float *)malloc((ns+3)*sizeof(float));
   if(!coeffs)
   {
      free(R);
      free(M);
      return;
   }
   memset((void*) coeffs,0,(ns+3)*sizeof(float));
   for(i = ns-1 ; i >= 0; i--)
   {
      //d(i) = (R(i,5) - R(i,2:4)*d(i+[1:3]))/R(i,1);
      sum = R[i*5+1]*coeffs[i+1] + R[i*5+2]*coeffs[i+2] + R[i*5+3]*coeffs[i+3];
      coeffs[i] = R[i*5+4] - sum;
      if(R[i*5])
      {
         coeffs[i] /= R[i*5];
      }
   }

   free(R);
   //Get smoothed solution.
   //y = M*coeffs
   ind1 = 0 ;
   ind2 = 0;
   for(j = 0 ; j < NknotIntervals; j++)
   {
      ind1 = ind2;
      // Find the no of contributions due to interval j.
      while (ind2< meassize && x[ind2] <= xknots[j+1] )
      {
         ind2++;
      }
      li = ind2- ind1;
      if(li)
      {
         for(i = ind1; i < ind2; i++)
            y[i] = M[i*4]*coeffs[j] + M[i*4+1]*coeffs[j+1] + M[i*4+2]*coeffs[j+2] +M[i*4+3]*coeffs[j+3];
      }
   }

   free(coeffs);
   free(M);
}


void QMSL_Linear_Predistortion_NV::qrfact(float* A, int rows, int cols)
{
   int i,j,k,p,z;
   float housec=0;
   float normv = 0;
   float normw=0.0;
   float beta=0;
   float temp=0;
   float signvi = 0;

   float* H;
   float* tempA;

   for (i = 0; i <= cols-1; i++)
   {
      normv = 0 ;
      if (i >= rows-1)
         z = rows -1;
      else
         z = i;
      /*
      v = A(:,i);
      c = norm(v(i:end))* -sign(v(i));
      */

      if (A[z*cols+i] >= 0 )
         signvi = 1;
      else
         signvi = -1;

      for (j = z; j <= rows-1; j++ )
         normv = normv+ A[j*cols+i]*A[j*cols+i];

      housec = sqrt(normv)*(-signvi);

      /*
      w = [ zeros(1:i-1,1);v(i)-c;v(i+1:end,1)]
      beta = 2/(w'*w);
      H1 = eye(size(R,1)) - beta*w*w';
      A = H1*A;
      */
      if (housec)
      {
         normw = normv;
         normw = normw + housec*housec - 2*housec*A[z*cols+i];
         beta = 2/normw;

         /*
         Calculate H = H(i:end,i:end) since the part above is
         just identity matrix and has no affect on A
         */

         //Allocate space for  H
         H = (float*)malloc((rows-z)*(rows-z)*sizeof(float));
         if(!H)
         {
            return;
         }
         //Fill H
         for (k = 0; k <= rows-z-1; k++)
         {
            for (j = 0; j <= rows-z-1; j++)
            {
               if (k == j)
               {
                  // 1- v^2
                  H[k*(rows-z)+j] = 1 - beta*A[(z+k)*cols+i]*A[(z+k)*cols+i];
                  if (k == 0)
                  {
                     H[k*(rows-z)+j] = H[k*(rows-i)+j]+beta*(-housec*housec + 2*housec*A[(z+k)*cols+i]);
                  }
               }
               else if (k < j)
               {
                  H[k*(rows-z)+j] =  -beta*A[(z+k)*cols+i]*A[(z+j)*cols+i];
                  if (k == 0)
                  {
                     H[k*(rows-z)+j] = H[k*(rows-z)+j] + beta*housec* A[(z+j)*cols+i];
                  }
                  H[j*(rows-z)+k] = H[k*(rows-z)+j];
               }
            }
         }

         // matrix multiply
         //   tempA = H*A(i:end,:); A(i:end) = tempA;

         //Create tempA
         tempA = (float*)malloc((rows-z)*(cols-z)*sizeof(float));
         if(!tempA)
         {
            free(H);
            return;
         }
         for (k = z; k <= rows-1; k++)
         {
            for (j = z; j <=cols-1; j++)
            {
               temp = 0;
               for (p = z; p <=rows-1; p++)
                  temp = temp + H[(k-z)*(rows-z)+(p-z)]*A[p*cols+j];
               tempA[(k-z)*(cols-z)+(j-z)] = temp;
            }
         }
         // copy A(i:end) = tempA;
         for( k = z; k <=rows-1; k++)
         {
            for (j = z; j<=cols-1; j++)
            {
               temp = tempA[(k-z)*(cols-z)+(j-z)];
               A[k*cols+j] =  temp;
            }
         }

         //Free H and tempA
         free(H);
         free(tempA);
      }
   } //end for i

} //end of qrfact


void QMSL_Linear_Predistortion_NV::third_order(const vector<float>& x, vector<float>& y, int meassize)
{
   unsigned int row =0;
   int loopVar=0;
   // y = a + bx + cx^2 + dx^3
   float s_xny[4]; //0 - s_x0y,1 - s_xy, 2 - s_x2y
   float s_xn[7];  //0 - s_1, 1 - s_x  ,2 - s_x2, 6 - s_x6
   ZeroMemory(s_xny,4*sizeof(float));
   ZeroMemory(s_xn,7*sizeof(float));

   float a,b,c,d;

   float x_prods;
   unsigned int xpower;


   //Compute the elements of the matrix
   for( loopVar=0; loopVar<meassize; loopVar++)
   {
      x_prods = 1.0;
      for(xpower = 0; xpower < 4; xpower++)
      {
         s_xny[xpower] += pow(x[loopVar],(float)xpower) * y[loopVar];
      }
      for(xpower = 0; xpower < 7; xpower++)
      {
         s_xn[xpower] += pow(x[loopVar],(float)xpower);
      }
   }

   //Prepare the matrix
   float A[4][5];

   for( row = 0; row < 4; row ++)
   {
      for(unsigned int col = 0; col < 4; col ++)
      {
         A[row][col] = s_xn[row+col];
      }
   }

   for( row = 0; row < 4; row ++)
   {
      A[row][4] = s_xny[row];
   }

   qrfact(&(A[0][0]),4,5);

   d = (A[3][4])/A[3][3];
   c = (A[2][4] - d*A[2][3])/A[2][2];
   b = (A[1][4] - d*A[1][3] - c*A[1][2])/A[1][1];
   a = (A[0][4] - d*A[0][3] - c*A[0][2] -b*A[0][1])/A[0][0];

   //Now smooth
   for( loopVar=0; loopVar<meassize; loopVar++)
   {
      float x_ = x[loopVar];
      y[loopVar] = a + b*x_ + c*x_*x_ + d*x_*x_*x_;
   }
}



int QMSL_Linear_Predistortion_NV::choose_knots_x(const vector<float>& x, vector<float>& y, vector<float>& xknots,int meassize,float delta_x)
{
   int NKnots = 0;

   float min_x = *min_element(x.begin(),x.end());
   float max_x = *max_element(x.begin(),x.end());
   float current_x = min_x;

   while((current_x += delta_x) < max_x)
   {
      xknots.push_back( current_x );
      NKnots++;
   }

   xknots.push_back( max_x );
   NKnots++;

   return (NKnots-1);
}

int QMSL_Linear_Predistortion_NV::choose_knots_y(const vector<float>& x, vector<float>& y, vector<float>& xknots,int meassize,float delta_y)
{
   int NKnots = 0,i;
   float yknot=0;

   yknot = y[0];
   float xknot = x[0];
   xknots.push_back( xknot );
   NKnots++;
   for(i = 0; i < meassize-1; i++)
   {
      double yVal = y[i];
      double yValNext = y[i+1];
      if((yVal-yknot) > delta_y)
      {
         float xVal = x[i];
         float xValNext = x[i+1];
         NKnots++;
         xknots.push_back( (xValNext+xVal)/2 );
         yknot = (float)((yValNext+yVal)/2.0);
      }
   }

   xknot = x[meassize-1];
   xknots.push_back( xknot );
   return NKnots;
}

void QMSL_Linear_Predistortion_NV::smoothData( vector<float> InPwr, vector<float> InDistortion, vector<float>& SmoothedDistortion, float winSize, bool xknot)
{
   vector<float> xknots;
   int numIntervals;

   if(xknot)
   {
      numIntervals = choose_knots_x( InPwr, InDistortion, xknots, InPwr.size() ,winSize );
   }
   else
   {
      numIntervals = choose_knots_y( InPwr, InDistortion, xknots, InPwr.size() ,winSize );
   }

   SmoothedDistortion = InDistortion;
   splsmooth( InPwr, SmoothedDistortion,   InPwr.size(), xknots, numIntervals );

#ifdef DEBUG_SMOOTHING
   static int i = 0;
   i++;
   ostringstream fnamestr1;
   fnamestr1.str("");
   fnamestr1 << "C:\\Qualcomm\\QDART\\Temp\\Smoothing_IO_" << i << ".csv";

   ofstream smFile;
   smFile.open (fnamestr1.str().c_str(),ios::out);
   for(unsigned int loopVar = 0; loopVar < InPwr.size(); loopVar++)
   {
      smFile << InPwr[loopVar] << "," << InDistortion[loopVar]<< "," << SmoothedDistortion[loopVar]<< endl;
   }
   smFile.close();
#endif

}

void QMSL_Linear_Predistortion_NV::truncateData( float truncLevel, vector<float>& InPwr, vector<float>& Gain, vector<float>& Phase)
{
   vector<float>::iterator inpPwrIter,lastInpPwrIter;
   vector<float>::iterator lastGainIter,lastPhseIter;

   lastInpPwrIter = InPwr.begin();
   lastGainIter = Gain.begin();
   lastPhseIter = Phase.begin();
   for(inpPwrIter = InPwr.begin(); inpPwrIter!=InPwr.end(); inpPwrIter++)
   {
      if((*inpPwrIter) > truncLevel)
      {
         InPwr.erase(InPwr.begin(),lastInpPwrIter);
         Gain.erase(Gain.begin(),lastGainIter);
         Phase.erase(Phase.begin(),lastPhseIter);
         break;
      }
      lastInpPwrIter = inpPwrIter;
      if(inpPwrIter != InPwr.begin())
      {
         lastGainIter++;
         lastPhseIter++;
      }
   }
}

void QMSL_Linear_Predistortion_NV::generateAMAMNV( QMSL_Vector<float> targetOutputPowers, vector<float> inPwr,
                                                   vector<float> smoothedGain,   QMSL_Vector<long>& amamLinear)
{
   //Step 7.1.2 : Generate Measured Output Powers vector
   QMSL_2DVector<float, float> InterpAMAM;
   QMSL_Vector<float> outPower;
   QMSL_Vector<float> gainVec;
   QMSL_Vector<float> inPwrVec;
   unsigned long loopVar = 0;
   for(loopVar = 0; loopVar < inPwr.size(); loopVar++)
   {
      gainVec.Append(smoothedGain[loopVar]);
      outPower.Append(inPwr[loopVar]+smoothedGain[loopVar]);
      inPwrVec.Append(inPwr[loopVar]);
   }
   InterpAMAM.SetXYvectors(&outPower,&inPwrVec);

   //Step 7.1.3 : Generate AMAM Log Vector
   const int LINEAR_SECTION_OF_DATA = 2;
   QMSL_Vector<float> amAmLog;
   int numPointsToAverageSlope = inPwrVec.Size()/LINEAR_SECTION_OF_DATA;
   InterpAMAM.InterpolateY2vector_SlopeAveragingExtrapolation(targetOutputPowers,amAmLog,numPointsToAverageSlope);

   //Step 7.1.4 : Generate AMAM Linear Vector (Also from float to long)
   for(loopVar = 0; loopVar < amAmLog.Size(); loopVar++)
   {
      amamLinear.Append((long)pow(10.0,amAmLog[loopVar]/20.0));
   }

#ifdef DEBUG_AMAM
   static int amamIndex = 0;
   amamIndex++;
   ostringstream fnamestr1;
   fnamestr1.str("");

   ostringstream fnamestr2;
   fnamestr2.str("");

#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr1 << "C:\\Qualcomm\\QDART\\Temp\\AMAM_NVGEN_Inputs_" << amamIndex << ".csv";
   fnamestr2 << "C:\\Qualcomm\\QDART\\Temp\\AMAM_NVGEN_Outputs_" << amamIndex << ".csv";
#else
   fnamestr1 <<P_tmpdir<<"AMAM_NVGEN_Inputs_"<<amamIndex<<".csv";
   fnamestr2 <<P_tmpdir<<"AMAM_NVGEN_Ouputs_" << amamIndex << ".csv";
#endif


   ofstream amamFile1,amamFile2;
   amamFile1.open (fnamestr1.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < outPower.Size(); loopVar++)
   {
      amamFile1 << outPower[loopVar] << "," << gainVec[loopVar]<< "," << inPwrVec[loopVar]<<endl;
   }
   amamFile1.close();

   amamFile2.open (fnamestr2.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < targetOutputPowers.Size(); loopVar++)
   {
      amamFile2 << targetOutputPowers[loopVar] << "," << amAmLog[loopVar]<< "," << amamLinear[loopVar]<< endl;
   }
   amamFile2.close();

#endif
}


void QMSL_Linear_Predistortion_NV::generateAMPMNV( vector<float> inPwr, float dacScale, vector<float> smoothedPhaseDistortion, QMSL_Vector<long>& amPmProcessed)
{

   //Step 7.2.1 : Generate target input power (for phase).
   float maxPowerInput = *max_element(inPwr.begin(),inPwr.end()); //In Log Terms

   bool exceededMaxInputLevel = false;
   QMSL_Vector<float> targetInputPowers;
   unsigned int loopVar;
   for(loopVar = 1; loopVar < 128; loopVar++) //128*128 = 2^14
   {
      float inPwrLog = 20*log10(loopVar*(float)128.0*dacScale);
      if(!exceededMaxInputLevel && (inPwrLog < maxPowerInput ))
      {
         targetInputPowers.Append(inPwrLog);
      }
      else
      {
         targetInputPowers.Append(maxPowerInput);
         exceededMaxInputLevel = true;
      }
   }
   if(!exceededMaxInputLevel)
   {
      targetInputPowers.Append(20*log10((float)(pow(2.0,14)-1)*dacScale));
   }
   else
   {
      targetInputPowers.Append(maxPowerInput);
   }

   //Step 7.2.2 : Generate Array of Input Levels & Phases. Invert Phase
   QMSL_2DVector<float, float> InterpAMPM;
   QMSL_Vector<float> inPowers; //is the same as inPwrVec above (but done seperately to help refactorization)
   QMSL_Vector<float> phaseVec;
   for(loopVar = 0; loopVar < inPwr.size(); loopVar++)
   {
      inPowers.Append(inPwr[loopVar]);
      phaseVec.Append((float)-1.0*smoothedPhaseDistortion[loopVar]);
   }
   InterpAMPM.SetXYvectors(&inPowers,&phaseVec);

   //Step 7.2.3 : Generate AMPM Vector
   //Interpolate and figure out AMPM
   const int LINEAR_SECTION_OF_DATA = 8;
   QMSL_Vector<float> amPm;
   int numPointsToAverageSlope = inPowers.Size()/LINEAR_SECTION_OF_DATA;
   InterpAMPM.InterpolateY2vector_SlopeAveragingExtrapolation(targetInputPowers,amPm,numPointsToAverageSlope);

   //Step 7.2.4 : Normalize Phase.
   //Take min and set it to 0.
   QMSL_Vector<float> amPmNormalized;
   float minAmPm = *min_element(amPm._data.begin(),amPm._data.end());
   for(loopVar = 0; loopVar < amPm.Size(); loopVar++)
   {
      amPmNormalized.Append( amPm[loopVar] - minAmPm );
   }

   //Step 7.2.5 : Wrap into +/- 180
   float amPmVal;
   //Todo: Check if remainder is required
   float remainder;
   QMSL_Vector<float> amPmWrapped;
   for(loopVar = 0; loopVar < amPmNormalized.Size(); loopVar++)
   {
      amPmVal = amPmNormalized[loopVar];
      remainder = amPmVal-(long)amPmVal;
      if(amPmVal >= 0)
         amPmWrapped.Append(((((long)amPmVal+180)%360)-180)+remainder);
      else
         amPmWrapped.Append(((((long)amPmVal-180)%360)+180)+remainder);
   }

   //Step 7.2.6 : Scale to 16 bit number
   for(loopVar = 0; loopVar < amPmNormalized.Size(); loopVar++)
   {
      amPmProcessed.Append( (long)(amPmWrapped[loopVar]/180*pow(2.0,15)));
   }


#ifdef DEBUG_AMPM
   static int ampmIndex = 0;
   ampmIndex++;
   ostringstream fnamestr3;
   fnamestr3.str("");

   ostringstream fnamestr4;
   fnamestr4.str("");

#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr3 << "C:\\Qualcomm\\QDART\\Temp\\AMPM_NVGEN_Inputs_" << ampmIndex << ".csv";
   fnamestr4 << "C:\\Qualcomm\\QDART\\Temp\\AMPM_NVGEN_Outputs_" << ampmIndex << ".csv";
#else
   fnamestr3 <<P_tmpdir<<"AMPM_NVGEN_Inputs_"<<ampmIndex<<".csv";
   fnamestr4 <<P_tmpdir<< "AMPM_NVGEN_Outputs" << ampmIndex << ".csv";
#endif

   ofstream ampmFile1,ampmFile2;
   ampmFile1.open (fnamestr3.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < inPowers.Size(); loopVar++)
   {
      ampmFile1 << inPowers[loopVar] << "," << phaseVec[loopVar]<<endl;
   }
   ampmFile1.close();

   ampmFile2.open (fnamestr4.str().c_str(),ios::out);
   for(loopVar = 0; loopVar < targetInputPowers.Size(); loopVar++)
   {
      ampmFile2 << targetInputPowers[loopVar] << "," << amPm[loopVar]<< "," << amPmNormalized[loopVar] << "," << amPmWrapped[loopVar]<< "," << amPmProcessed[loopVar] << endl ;
   }
   ampmFile2.close();

#endif
}

void  QMSL_Linear_Predistortion_NV::slopeCompensate( vector<float> inPwr, vector<float>& outVector, float slopeFactor)
{
#ifdef DEBUG_SLOPE_COMP
   static int slopeCompLogIndex = 0;
   slopeCompLogIndex++;
   ostringstream fnamestr;
   fnamestr.str("");
   fnamestr << "C:\\Qualcomm\\QDART\\Temp\\SlopeComp_" << slopeCompLogIndex << ".csv";
   ofstream slopeCompLog;
   slopeCompLog.open (fnamestr.str().c_str(),ios::out);
#endif

   float maxPwr = *max_element(inPwr.begin(),inPwr.end());
   for(unsigned int loopVar = 0; loopVar<inPwr.size(); loopVar++)
   {
#ifdef DEBUG_SLOPE_COMP
      slopeCompLog<<inPwr[loopVar]<<","<<outVector[loopVar];
#endif

      outVector[loopVar] = static_cast<float>(outVector[loopVar]+(inPwr[loopVar]-maxPwr)/10.0*slopeFactor);

#ifdef DEBUG_SLOPE_COMP
      slopeCompLog<<","<<outVector[loopVar]<<endl;;
#endif
   }
#ifdef DEBUG_SLOPE_COMP
   slopeCompLog.close();
#endif
}

void QMSL_Linear_Predistortion_NV::logParams(const QMSL_GSM_PreDist_Cal_Result *params)
{
#ifdef DEBUG_LOG_PREDIST_CAL_PARAMS
   static int i = 0;
   i++;
   ostringstream fnamestr;
   fnamestr.str("");

#if !defined(QMSL_POSIX_PORTABLE)
   fnamestr << "C:\\Qualcomm\\QDART\\Temp\\Predist_Input_Params_" << i << ".txt";
#else
   fnamestr <<P_tmpdir<<"/Predist_Input_Params_" << i << ".txt";
#endif

   ofstream predistParamLogFile;
   predistParamLogFile.open (fnamestr.str().c_str(),ios::out);

   predistParamLogFile << "iFreqMapping[0] :" << params->iFreqMapping[0] << endl;
   predistParamLogFile << "iFreqMapping[1] :" << params->iFreqMapping[1] << endl;
   predistParamLogFile << "iFreqMapping[2] :" << params->iFreqMapping[2] << endl;
   predistParamLogFile << "iNumChannels :" << params->iNumChannels << endl;
   predistParamLogFile << "iNumPredistortionWaveformSamples :" << params->iNumPredistortionWaveformSamples << endl;
   predistParamLogFile << "iCalRgi :" << params->iCalRgi << endl;
   predistParamLogFile << "iSamplingRateHz :" << params->iSamplingRateHz << endl;
   predistParamLogFile << "iDcSamples :" << params->iDcSamples << endl;
   predistParamLogFile << "iEdgeSamples :" << params->iEdgeSamples << endl;
   predistParamLogFile << "iNoiseSamples :" << params->iNoiseSamples << endl;
   predistParamLogFile << "iEDGETxGainParam :" << params->iEDGETxGainParam << endl;
   predistParamLogFile << "iEDGETxCalScale :" << params->iEDGETxCalScale << endl;
   predistParamLogFile << "iDCTransientPercent :" << params->iDCTransientPercent << endl;
   predistParamLogFile << "iEDGETransientSymbols :" << params->iEDGETransientSymbols << endl;
   predistParamLogFile << "iOverRideModemConstants :" << params->iOverRideModemConstants << endl;
   predistParamLogFile << "dDigGainUnity :" << params->dDigGainUnity << endl;
   predistParamLogFile << "dRampUnity :" << params->dRampUnity << endl;
   predistParamLogFile << "dExtensionFloor :" << params->dExtensionFloor << endl;
   predistParamLogFile << "dDacScale :" << params->dDacScale << endl;

   predistParamLogFile.close();
#endif
}

#define MAX_ARR_SIZE 8192
#define MAX_DELAYS 7
long QMSL_Linear_Predistortion_NV::updateDelay
(float * CVec1,const float * CVec2, long CVecSize)
{

   static float gainArrDelay[MAX_ARR_SIZE][MAX_DELAYS]= {0.0};
   float gainMaxDelay[MAX_DELAYS] = {-10000.0,-10000.0,-10000.0,-10000.0,-10000.0,-10000.0,-10000.0};
   float gainMinDelay[MAX_DELAYS] = {10000.0,10000.0,10000.0,10000.0,10000.0,10000.0,10000.0};
   float rangeDelays[MAX_DELAYS] = {0};

   int delaySet[MAX_DELAYS] = {-3,-2,-1,0,1,2,3};
   int numDelays = 7;

   const int SKIP_SAMPLES = 300;
   const int HARD_CODED_AMAM_IN_BIN = 75;
   int lpVar = 0;

   for(lpVar = SKIP_SAMPLES; lpVar<CVecSize-SKIP_SAMPLES; lpVar++)
   {
      for(int delayVar = 0; delayVar<numDelays; delayVar++)
      {
         gainArrDelay[lpVar][delayVar] = CVec2[lpVar + delaySet[delayVar] ]-CVec1[lpVar];
      }
   }
#ifdef DEBUG_UPDATE_DELAY_FOR_AMAM_GAIN_SPREAD
   static int i = 0;
   i++;
   ostringstream fnamestr;
   fnamestr.str("");
   fnamestr << "C:\\Qualcomm\\QDART\\Temp\\Delay_Update_" << i << ".csv";
   FILE* fp = fopen(fnamestr.str().c_str(),"w");
#endif
   for(lpVar = SKIP_SAMPLES+2; lpVar<CVecSize-SKIP_SAMPLES; lpVar++)
   {
      if( (CVec1[lpVar] >= HARD_CODED_AMAM_IN_BIN && CVec1[lpVar-1] <= HARD_CODED_AMAM_IN_BIN) ||
            (CVec1[lpVar] <= HARD_CODED_AMAM_IN_BIN && CVec1[lpVar-1] >= HARD_CODED_AMAM_IN_BIN))
      {
#ifdef DEBUG_UPDATE_DELAY_FOR_AMAM_GAIN_SPREAD
         fprintf(fp,"%d,",lpVar);
#endif
         for(int delayVar = 0; delayVar<numDelays; delayVar++)
         {
            if(gainArrDelay[lpVar][delayVar] > gainMaxDelay[delayVar])
               gainMaxDelay[delayVar] = gainArrDelay[lpVar][delayVar];
            if(gainArrDelay[lpVar][delayVar] < gainMinDelay[delayVar])
               gainMinDelay[delayVar] = gainArrDelay[lpVar][delayVar];
            rangeDelays[delayVar] = gainMaxDelay[delayVar] - gainMinDelay[delayVar];
#ifdef DEBUG_UPDATE_DELAY_FOR_AMAM_GAIN_SPREAD
            fprintf(fp,"%f,%f,",gainMaxDelay[delayVar],gainMinDelay[delayVar]);
#endif
         }
#ifdef DEBUG_UPDATE_DELAY_FOR_AMAM_GAIN_SPREAD
         fprintf(fp,"\n");
#endif
      }
   }

   long delayUpdate;
   float smallestGainVariation = 10000.0;
   for(int delayVar = 0; delayVar<numDelays; delayVar++)
   {
      if(smallestGainVariation >= rangeDelays[delayVar])
      {
         smallestGainVariation = rangeDelays[delayVar];
         delayUpdate = delaySet[delayVar];
      }
   }

#ifdef DEBUG_UPDATE_DELAY_FOR_AMAM_GAIN_SPREAD
   fprintf(fp,"%d\n",delayUpdate);
   fclose(fp);
#endif

   return delayUpdate;
}


//Ignore double to float error, as this array has to be float
#pragma warning(disable:4305)

//! Input amplitude samples. Used for correlation and gain computations
const float QMSL_Linear_Predistortion_NV::ampl_in[ENV_IN_NUM_SAMPLES_SWAPPED] =
{
   10987,10983,10974,10960,10942,10922,10897,10871,10842,10814,10786,
   10758,10732,10709,10689,10674,10663,10658,10656,10661,10670,10685,
   10706,10729,10759,10790,10824,10861,10897,10934,10970,11003,11034,
   11062,11085,11103,11116,11121,11119,11111,11096,11070,11038,10997,
   10947,10889,10823,10748,10664,10573,10475,10368,10255,10135,10012,
   9881,9746.8,9609.1,9467.8,9326,9181,9038,8895.6,8755.7,8619.4,8487.5,
   8360.4,8241.1,8127.8,8023.4,7926,7837.8,7758.2,7687.3,7625,7569,7519.4,
   7475.8,7435,7397.4,7359,7321.7,7280.8,7235.6,7184,7124.5,7057.8,6980.3,
   6890.4,6789.3,6675,6546.2,6403.6,6247.3,6074.8,5887.5,5687.4,5474.7,5247,
   5008.8,4762,4506.3,4247,3985.2,3728,3478.5,3242.6,3031.8,2856.4,2722.7,
   2640,2628.3,2679,2790.3,2961.6,3179.5,3434.2,3717.4,4025.2,4344.6,4675,
   5009.7,5347.6,5685.1,6021,6352,6677.4,6997,7306.6,7607.3,7899,8179,
   8447.2,8705.3,8949,9179,9397.8,9602.7,9791,9968.1,10130,10275,10408,
   10527,10630,10720,10795,10856,10903,10937,10960,10966,10962,10947,
   10920,10880,10831,10771,10700,10621,10532,10434,10328,10216,10096,
   9969.5,9837.6,9701.2,9560,9415.6,9269,9119.8,8971.6,8823.4,8677.6,8533.5,
   8394.2,8260,8132,8012,7901,7800.4,7710.4,7631.8,7565.8,7515.5,7478,
   7455.2,7448,7455,7475,7513.2,7564,7627.9,7705.2,7794.5,7894.2,8004.1,
   8124.4,8252,8387,8527.3,8672.2,8820.5,8971.6,9123.5,9275.4,9426.6,9576.2,
   9721.7,9864,10001,10132,10258,10377,10489,10594,10693,10782,10865,
   10942,11012,11076,11136,11190,11239,11288,11334,11379,11423,11469,
   11516,11566,11617,11674,11734,11797,11865,11937,12014,12093,12177,
   12262,12350,12440,12530,12619,12707,12793,12874,12953,13026,13092,
   13153,13205,13251,13286,13315,13332,13341,13341,13332,13313,13287,
   13252,13210,13161,13106,13045,12980,12911,12839,12763,12685,12608,
   12530,12452,12375,12298,12224,12151,12081,12011,11943,11879,11815,
   11753,11691,11629,11568,11504,11439,11372,11302,11227,11149,11066,
   10978,10882,10782,10676,10563,10443,10318,10186,10050,9909,9763.5,
   9613.2,9461.1,9307,9151.7,8995.6,8840,8687.6,8536.5,8389.4,8247.4,8110.4,
   7978.7,7853,7735.2,7625.2,7522.7,7429.2,7343,7265.6,7196.2,7135.4,7081,
   7034,6995.6,6962.8,6936,6912.4,6896.5,6883,6873.4,6866.8,6862.9,6861,
   6860,6860,6860.9,6862.4,6865,6867.6,6868.1,6869.4,6870.7,6872,6871.7,
   6870.4,6870,6869.6,6867.5,6864.6,6862.8,6860.2,6856.9,6854,6851.1,6847.2,
   6844.2,6841.8,6839.5,6837.2,6836,6835.6,6835,6836,6837,6837.6,6839.8,
   6842.4,6845.5,6848.6,6853.1,6855.2,6859.1,6862,6865.9,6869.2,6871.8,6875.4,
   6878,6879.8,6882.3,6885.4,6888.1,6890,6894.6,6898.4,6901.8,6908,6915,
   6922.8,6931.8,6943,6955.3,6969,6985.6,7002.4,7022.4,7042,7062,7082,
   7103.5,7121.8,7137.4,7151,7159.8,7164,7162.2,7153.4,7134.5,7107.6,7070.3,
   7019.8,6958.3,6883,6793.2,6689,6572.2,6439.4,6289,6125.8,5948.3,5754,
   5546.9,5328,5097.1,4855.6,4607.2,4351.4,4094,3835.8,3584.3,3344,3118.4,
   2917,2751.3,2626.4,2546.3,2524.6,2558,2641,2769.4,2936.6,3129.2,3343,
   3568.4,3801,4036.8,4270.6,4500,4722.2,4937.7,5140.6,5335.9,5519,5689.5,
   5847.2,5994.8,6129.4,6252,6363.4,6464.1,6554.4,6636,6710,6774.1,6832.2,
   6883.2,6929.6,6970.5,7008.2,7041.3,7071.2,7099,7124,7145.8,7164.2,7178.9,
   7189.8,7194.5,7195.2,7188.1,7174.4,7152,7121,7078.6,7025,6959.3,6881.4,
   6789,6683.8,6563.9,6429,6280.4,6119,5941.1,5751,5549.7,5336.2,5114.5,
   4885.6,4653,4419,4187.1,3961,3750.8,3557.8,3388.5,3255.6,3161.5,3110.6,
   3107.8,3155.4,3247.1,3376,3544.3,3735.4,3944.6,4169.4,4401,4635.8,4868.8,
   5098.6,5321.3,5537,5739.3,5930.8,6110.4,6276.2,6428.5,6568,6692.7,6803,
   6902.8,6991,7065.9,7131.2,7189.6,7240.8,7284,7324.8,7362,7400.6,7439,
   7478,7524.8,7573.4,7629.5,7692.8,7765,7845.2,7933.2,8029.6,8136.5,8250,
   8370.4,8498.4,8629.8,8766.6,8907.5,9050,9193.1,9337.4,9481,9622,9760.5,
   9895.8,10027,10153,10274,10389,10497,10599,10694,10780,10861,10932,
   10997,11053,11101,11141,11174,11197,11212,11220,11219,11209,11192,
   11167,11132,11091,11042,10983,10916,10843,10762,10672,10577,10473,
   10364,10248,10125,9997.4,9866.6,9731,9592.3,9450.6,9308.9,9167.2,9026.5,
   8888.2,8754,8624.8,8502.3,8389,8286.8,8194.8,8116.7,8053,8005.5,7974.8,
   7964.2,7971.2,7997.2,8042,8108.7,8192.6,8293.9,8413.2,8548.5,8696.6,8860.3,
   9035.2,9219.5,9412,9612.1,9816.8,10027,10239,10450,10662,10873,11080,
   11282,11479,11669,11851,12026,12191,12345,12489,12622,12741,12849,
   12946,13027,13096,13154,13196,13228,13247,13256,13251,13237,13212,
   13179,13138,13089,13034,12973,12908,12839,12767,12693,12617,12542,
   12466,12393,12319,12249,12180,12114,12053,11994,11938,11887,11839,
   11795,11755,11719,11684,11655,11627,11604,11583,11566,11553,11543,
   11536,11533,11534,11540,11549,11565,11584,11611,11642,11679,11722,
   11772,11827,11889,11956,12028,12104,12184,12269,12354,12443,12532,
   12622,12711,12796,12881,12961,13037,13109,13173,13233,13286,13332,
   13371,13402,13428,13446,13457,13464,13465,13462,13453,13442,13429,
   13414,13399,13383,13368,13356,13345,13337,13331,13328,13329,13335,
   13342,13353,13368,13385,13404,13425,13446,13468,13491,13512,13533,
   13550,13565,13578,13586,13592,13594,13592,13586,13577,13565,13551,
   13532,13512,13491,13469,13448,13425,13406,13387,13370,13356,13347,
   13339,13336,13336,13341,13349,13361,13376,13394,13413,13436,13460,
   13483,13509,13532,13555,13577,13595,13611,13624,13635,13640,13644,
   13644,13641,13634,13625,13612,13599,13584,13568,13551,13535,13519,
   13505,13491,13479,13472,13465,13459,13457,13457,13460,13463,13467,
   13472,13477,13482,13485,13486,13482,13474,13462,13441,13415,13381,
   13336,13282,13217,13142,13055,12957,12846,12723,12589,12443,12286,
   12118,11940,11753,11558,11354,11145,10931,10713,10493,10270,10049,
   9829.4,9611,9399.7,9193.4,8993.3,8803.4,8621.5,8450.8,8290.6,8145.2,8011.7,
   7891,7783.2,7689.2,7608,7538.6,7480.5,7432,7393.4,7361.2,7334,7311,
   7290.2,7268.8,7245.8,7218.4,7187,7147.6,7101.7,7043.8,6976.5,6897,6803.6,
   6696.8,6576.5,6441.4,6290,6125,5945.2,5750,5540.8,5320,5086.8,4844.6,
   4594.4,4339.6,4084,3832.4,3589.5,3366.4,3167.9,3003,2893,2837.8,2844.3,
   2924.6,3071,3272.6,3524.2,3820,4143.9,4492,4859.4,5238.6,5625.2,6017.8,
   6414,6810.2,7203.2,7593.8,7978.5,8356,8724,9084.4,9435.2,9772.6,10098,
   10411,10710,10992,11260,11513,11749,11968,12171,12357,12525,12678,
   12816,12935,13041,13132,13210,13275,13327,13369,13403,13428,13445,
   13456,13463,13465,13465,13463,13458,13456,13453,13450,13450,13450,
   13453,13458,13464,13473,13483,13493,13505,13515,13525,13533,13540,
   13544,13543,13540,13531,13516,13496,13470,13437,13398,13352,13300,
   13239,13174,13104,13028,12947,12863,12776,12687,12596,12506,12414,
   12326,12239,12156,12076,12001,11931,11865,11806,11752,11705,11664,
   11629,11599,11577,11558,11545,11537,11533,11534,11538,11546,11557,
   11573,11591,11613,11637,11666,11697,11731,11770,11812,11857,11907,
   11959,12016,12074,12139,12204,12272,12343,12417,12490,12564,12637,
   12710,12780,12847,12911,12969,13021,13065,13102,13129,13146,13151,
   13144,13123,13088,13040,12974,12891,12793,12676,12543,12391,12223,
   12036,11831,11609,11370,11114,10844,10556,10254,9937.4,9608.7,9264.8,
   8911.5,8547,8172.4,7789.8,7400.1,7003.4,6602,6199,5793,5390.8,4992.5,
   4602,4225.7,3867.6,3535,3243.4,3004,2827,2728,2723.2,2802.5,2959,
   3192.5,3476.4,3799.5,4152.8,4527,4915.6,5312.8,5714.8,6120.4,6526,6926.4,
   7324.4,7716,8102,8477,8842.4,9196.6,9539.2,9867.6,10183,10481,10763,
   11030,11275,11501,11708,11895,12057,12199,12319,12414,12485,12534,
   12557,12556,12532,12483,12409,12312,12193,12050,11886,11701,11493,
   11266,11021,10758,10476,10180,9867,9539.6,9198.8,8847.2,8482.8,8108.5,
   7726.2,7334.7,6939.2,6538.7,6135,5730,5328.8,4931.5,4542.8,4169.5,3814.6,
   3487.3,3203.8,2971.6,2803,2724,2729.8,2819.5,2994.2,3234,3523.4,3852.2,
   4210.6,4586.1,4976,5375.3,5779,6183.8,6588,6990,7387.2,7779.6,8163.2,
   8538.5,8904,9257.1,9600,9929.9,10244,10542,10827,11095,11344,11575,
   11788,11980,12151,12304,12435,12545,12634,12703,12749,12775,12782,
   12767,12733,12680,12609,12522,12417,12298,12162,12015,11856,11685,
   11503,11315,11117,10913,10705,10494,10279,10064,9848,9633.8,9422.4,
   9214,9013.4,8817,8627,8446.7,8275.8,8114.3,7962,7823.4,7694.4,7577.7,
   7471,7377,7292.6,7220,7157,7102,7057,7018.5,6987.8,6961.9,6941.6,
   6926.5,6913.8,6904.3,6896.8,6891.5,6889,6885,6884.4,6884,6883,6884.5,
   6886,6888.2,6891.6,6897.5,6904,6914.4,6927.2,6942.8,6964.4,6989.5,7021.8,
   7060.4,7106.2,7160.5,7225,7299.3,7382.8,7478.4,7584.8,7704,7832.8,7974.4,
   8125.8,8288.6,8461,8642.2,8832.4,9028.8,9232,9441,9652.4,9867.7,10084,
   10301,10517,10731,10942,11148,11349,11544,11731,11908,12076,12235,
   12383,12516,12639,12749,12844,12926,12994,13047,13088,13114,13128,
   13126,13114,13091,13055,13010,12957,12895,12826,12751,12672,12590,
   12505,12420,12333,12248,12163,12083,12004,11929,11857,11790,11728,
   11669,11613,11561,11512,11466,11420,11376,11330,11283,11235,11186,
   11131,11072,11007,10936,10859,10775,10686,10587,10481,10369,10249,
   10123,9991.6,9854.1,9711.2,9564.9,9416,9264.9,9112.2,8960.6,8809.2,8660.5,
   8515,8372.6,8238.2,8107.7,7985,7870.8,7764.6,7668.2,7581.4,7503.5,7436.8,
   7379.2,7331.8,7293.1,7263,7239.8,7224,7212.8,7207.4,7204.5,7204,7201.9,
   7199.8,7194.5,7185,7168.2,7145.6,7113.7,7072.4,7019.5,6956.2,6879.1,6787,
   6682.5,6564,6427.7,6278,6113,5932.8,5739,5531.6,5311.4,5079.4,4836.7,
   4587,4331.6,4073,3816.6,3566.2,3325.5,3102.4,2903.7,2740.4,2617.6,2541,
   2526.9,2563,2648.5,2781.6,2950.5,3144.2,3359.2,3585.2,3818,4053,4287.1,
   4514.8,4737,4949.8,5152.5,5344,5525.1,5692.2,5847.2,5990,6119.2,6237.2,
   6342.2,6436,6517,6588.4,6650.3,6703,6745,6782,6811.4,6833,6850.7,
   6864.6,6874.5,6880.4,6884.3,6887.4,6888.7,6889,6888.7,6887.4,6886.1,6884.8,
   6884.5,6884.2,6882.9,6882.4,6883,6884,6883,6883.6,6884,6883.2,6884,
   6883.2,6883.9,6883,6883,6883,6883,6882.4,6883.8,6883.2,6884.5,6885,
   6886.1,6887,6888.4,6888,6888,6887.4,6885.2,6881.2,6874,6863.6,6852.7,
   6834.2,6810.7,6783,6745.7,6702.4,6650.2,6588.8,6518.5,6437,6343.1,6237.6,
   6121.6,5993,5849.9,5694.2,5527.1,5347.6,5154,4951.6,4737,4513.6,4282,
   4044,3802.9,3559.2,3317.5,3084.2,2862,2656.6,2475.1,2330.4,2225,2165,
   2160.3,2203.8,2287.8,2409,2557.5,2722.8,2896.6,3073.8,3249.8,3418,3575.5,
   3720.2,3849.4,3961,4052.5,4125.6,4176.7,4206.2,4214,4201,4162.6,4105.4,
   4028.3,3928.6,3811,3677.4,3529.5,3365.4,3195.6,3020,2842.5,2670,2509.1,
   2369.4,2259,2183.8,2155.1,2181,2253.3,2369,2528.7,2717.8,2928.4,3154.4,
   3392,3633.6,3876.6,4118,4354.3,4583,4803.8,5015.4,5215.8,5404.8,5581.5,
   5746.2,5898,6037.8,6166.2,6284,6387.1,6483,6567.7,6645,6714.5,6777.6,
   6835.2,6889.4,6942,6995,7047.6,7104,7163.4,7229.8,7302.5,7381.6,7472.5,
   7573.2,7685.3,7805,7940.7,8086.6,8242.8,8410.8,8588.5,8776.6,8971.6,9175.6,
   9385.8,9600,9819,10041,10263,10485,10706,10924,11138,11346,11547,
   11742,11927,12103,12269,12424,12566,12698,12816,12923,13017,13100,
   13170,13229,13278,13316,13344,13366,13379,13385,13386,13384,13377,
   13369,13358,13348,13338,13329,13321,13315,13313,13312,13314,13317,
   13323,13330,13338,13346,13352,13357,13360,13359,13353,13340,13319,
   13290,13251,13199,13136,13059,12969,12866,12743,12606,12452,12281,
   12092,11886,11666,11426,11170,10900,10613,10311,9996.4,9667,9325.5,
   8973.6,8610.5,8238.4,7859.2,7473,7082.8,6687.6,6292.4,5897.4,5505,5119,
   4743.9,4383,4041.1,3724,3444.2,3206.2,3017.5,2893.4,2838,2845.8,2920.3,
   3052,3224.8,3431,3663.8,3909.2,4162.4,4418.2,4672,4921,5160.9,5390.8,
   5608.8,5815,6005.3,6183.2,6344.9,6493.2,6626.5,6746.2,6852.2,6943.8,7024.6,
   7096,7155.3,7206.2,7249.8,7288,7320.5,7350.6,7379.1,7406.4,7434.4,7464,
   7495.8,7530.2,7568.9,7609.8,7655,7702.6,7753.1,7806.4,7859.7,7913,7966,
   8018,8066.4,8110.6,8151.5,8185.2,8214.8,8236.6,8251.3,8259,8259.1,8252.2,
   8239.1,8217,8190.5,8159.2,8121.9,8082,8040.2,7997,7953.8,7911.4,7872,
   7836.2,7806.5,7782.4,7764.1,7754.4,7752,7756,7769.2,7789.2,7815.8,7846.4,
   7883,7923.6,7966.3,8009.6,8053.1,8095,8133.8,8167.6,8199.6,8223.4,8242,
   8253.4,8257.9,8254.6,8243.3,8225,8199.4,8168.4,8131,8088.2,8042,7991.8,
   7941,7889.4,7840.1,7792,7750.7,7714.6,7686.1,7667.4,7660.5,7665.6,7684.3,
   7718.2,7767.4,7831,7913.6,8011.4,8123.1,8252.6,8397,8553.4,8722.8,8904.6,
   9094.6,9292,9499.6,9710.8,9926.3,10143,10361,10578,10792,11002,11205,
   11403,11589,11766,11932,12084,12222,12344,12450,12537,12607,12658,
   12687,12696,12685,12652,12597,12521,12423,12302,12162,12002,11818,
   11615,11395,11154,10897,10622,10332,10024,9704.7,9373,9026.7,8670.8,
   8305.3,7932.6,7552.5,7167.6,6779,6389,5999.7,5612,5232.6,4862.4,4503.4,
   4164.4,3849,3560.8,3310.5,3107.6,2951.8,2849,2811.1,2825.2,2884.6,2988.4,
   3121,3272.8,3436,3604.6,3770.2,3929,4076.8,4209.8,4329.1,4426,4503.5,
   4561,4597.3,4608.6,4598.2,4565,4508.8,4430.2,4332.8,4213,4077,3925,
   3760.7,3586.2,3406.7,3227,3057.5,2902.2,2771.5,2678.8,2634,2642,2711.4,
   2846.4,3032.6,3266,3545.6,3856.8,4191.8,4548.6,4919.5,5300.8,5690.2,6083.2,
   6477.8,6873,7264.4,7651.2,8031.9,8405.8,8771,9126.6,9469.6,9799.6,10117,
   10421,10707,10976,11229,11461,11675,11870,12044,12195,12325,12435,
   12521,12586,12628,12650,12648,12626,12584,12520,12439,12341,12223,
   12090,11943,11782,11608,11424,11230,11027,10820,10608,10391,10174,
   9957.6,9741.4,9530.5,9322.8,9124.1,8932.8,8749.7,8578,8419.9,8273.8,8141.9,
   8027.2,7928,7843.2,7775.8,7724.8,7688.9,7667,7660.3,7665.8,7682.5,7709.8,
   7744.5,7785.6,7830.9,7881.6,7931.6,7982,8033.1,8079.4,8122.7,8159.2,8191.5,
   8216.6,8233.9,8243.2,8244.3,8238,8223.2,8199.4,8168.5,8130.4,8085.5,8034.2,
   7977.3,7915.8,7852,7784,7715.1,7645.6,7575.4,7508.6,7441.5,7377.6,7317.6,
   7261.2,7209.4,7161,7119.4,7080.2,7047.4,7017.2,6993,6972,6953.9,6939.6,
   6926.7,6916,6908.5,6902,6897.3,6891.6,6888,6885.2,6881.7,6878.2,6875.6,
   6873,6868.7,6866.2,6862.3,6858.6,6855.5,6852.4,6848.8,6845.8,6842.6,6841,
   6838.4,6837,6836.1,6835.2,6835.5,6835.8,6837.1,6838.8,6841.4,6844,6847.3,
   6849.8,6853.7,6857.4,6860.5,6862.8,6865.3,6868.8,6871.4,6874,6875.3,6877.2,
   6878.9,6881.2,6883,6885.6,6890.4,6896,6903.2,6912,6924,6939.4,6958.5,
   6983.4,7014,7051.8,7094.9,7148.4,7209.6,7281,7364.1,7456,7559.8,7676,
   7803,7940.4,8090.2,8251.2,8420.4,8599,8788.7,8983.6,9184.4,9392.6,9604.5,
   9818.8,10036,10254,10472,10687,10900,11110,11314,11513,11704,11889,
   12064,12230,12386,12533,12667,12791,12904,13003,13093,13170,13237,
   13292,13337,13373,13398,13416,13427,13432,13431,13426,13416,13404,
   13392,13378,13365,13353,13341,13334,13327,13324,13324,13327,13334,
   13341,13355,13368,13382,13397,13413,13428,13442,13452,13460,13465,
   13464,13459,13447,13430,13405,13374,13336,13290,13237,13180,13114,
   13042,12967,12886,12803,12716,12627,12538,12448,12359,12271,12187,
   12103,12026,11951,11881,11814,11754,11697,11644,11597,11552,11510,
   11471,11432,11394,11354,11313,11270,11221,11169,11110,11046,10971,
   10888,10796,10693,10578,10452,10314,10163,9998,9821.8,9632,9427.5,
   9211.8,8981.6,8739.2,8484,8217,7939,7650,7351.2,7045,6729.5,6407.6,
   6081.8,5753.4,5423.9,5096,4776.1,4463.2,4162.8,3882.2,3626,3399.4,3210,
   3065.6,2968.3,2919,2923.2,2970.6,3054.9,3172.4,3310,3460.4,3618.3,3777,
   3930.2,4075,4206.2,4323,4423.6,4504.4,4564.5,4603.8,4623,4617.4,4590.8,
   4546,4475.1,4386.6,4280.5,4157.4,4020,3872.2,3716.7,3557.2,3401.4,3254,
   3125,3019.4,2945.1,2916.6,2934.5,2998.8,3114,3279.6,3482.9,3719,3988.1,
   4276.8,4582.2,4898.4,5222,5550.4,5880.2,6207.4,6531.6,6853,7163.5,7467.2,
   7762.5,8047.4,8320.5,8584,8834.4,9071.2,9296.3,9508,9706.5,9890.8,10063,
   10223,10368,10502,10624,10734,10832,10921,11000,11071,11133,11190,
   11240,11287,11329,11369,11408,11447,11486,11526,11569,11614,11664,
   11718,11777,11839,11908,11978,12056,12135,12219,12305,12393,12483,
   12573,12662,12750,12835,12918,12996,13070,13140,13202,13259,13307,
   13351,13386,13416,13437,13451,13462,13464,13464,13457,13449,13435,
   13422,13407,13390,13375,13360,13348,13336,13328,13322,13319,13319,
   13321,13327,13334,13343,13353,13362,13372,13380,13385,13387,13384,
   13376,13360,13338,13305,13264,13212,13151,13075,12990,12892,12782,
   12659,12525,12377,12220,12050,11873,11683,11487,11284,11074,10860,
   10641,10420,10199,9978.8,9760.4,9545.4,9334.3,9130,8932.9,8744.8,8567.4,
   8400.4,8245,8102.4,7972.7,7855.8,7752.8,7663,7585.1,7519.8,7464.1,7420,
   7383,7353.2,7327.2,7304.6,7283.8,7262,7237.3,7210.2,7176.7,7135.8,7086.5,
   7027.6,6956.8,6873.8,6779.1,6670,6545.7,6409,6257.9,6093,5913.5,5721.2,
   5517.7,5303.4,5080.2,4851,4616.7,4383.2,4151.8,3929,3720,3529.4,3365.6,
   3239.2,3150.8,3105,3113.7,3167,3263.7,3402,3572.5,3766.2,3979.2,4204.4,
   4436.7,4671,4904.1,5132.4,5355,5566.6,5768.5,5957.6,6133.8,6296.6,6445.7,
   6582,6700.8,6808.4,6902.1,6983.2,7052.5,7110.6,7158.9,7195.8,7226.7,7250,
   7268.7,7281,7290.4,7295.8,7300,7301.8,7303,7303,7301.6,7299,7294.2,
   7285.8,7276.7,7261.2,7241.5,7215.4,7181.9,7139.2,7087.6,7025,6949.8,6862.4,
   6762.9,6648,6519.5,6376.6,6217.9,6044.4,5856,5655,5438.4,5210,4971.5,
   4722,4466.5,4206.2,3946.1,3689,3441.1,3208,3003.8,2831.6,2705.7,2637.2,
   2632.5,2690.2,2812.1,2993.2,3217.5,3476,3764.9,4073.2,4395,4726.4,5061.5,
   5399,5737.9,6073,6402.4,6729,7045.3,7355,7655.1,7945.4,8225,8494.2,
   8751.1,8996.2,9228.5,9450,9656.9,9851.6,10035,10205,10365,10511,10647,
   10772,10886,10993,11090,11181,11266,11342,11415,11485,11551,11617,
   11680,11742,11806,11869,11935,12000,12068,12138,12209,12282,12357,
   12432,12506,12582,12656,12729,12799,12866,12928,12985,13034,13078,
   13111,13135,13149,13150,13139,13115,13075,13019,12950,12863,12759,
   12637,12499,12342,12167,11975,11765,11537,11293,11034,10756,10464,
   10159,9837.2,9504,9158,8801,8433.8,8056.6,7672,7279.8,6882.8,6480.1,
   6075.6,5670.5,5267,4867.6,4475.6,4096.4,3733,3399.4,3098.6,2840.9,2648.4,
   2531,2492.8,2541.8,2673.8,2869.2,3115,3403.2,3715.2,4044.4,4386,4732,
   5082,5430.6,5775.6,6116.7,6451,6776.8,7094.8,7403.5,7699.4,7985,8259.4,
   8521.1,8767,9000.5,9220,9422.4,9608.8,9781.9,9936.2,10075,10196,10302,
   10388,10458,10513,10548,10566,10569,10556,10528,10484,10427,10355,
   10271,10176,10070,9953.8,9829.7,9698.8,9560,9418.8,9272.7,9124.6,8975.2,
   8826,8679.4,8535.6,8395.7,8261,8133,8013,7902.1,7801.8,7711.8,7633,
   7568.8,7517,7477.8,7455.2,7447.5,7454.2,7475.5,7511.6,7562.1,7625,7703.5,
   7792.2,7892.1,8003.8,8122.5,8250,8383.7,8523.6,8667.4,8814,8963.2,9112,
   9261.5,9409,9556,9699,9839.5,9974.8,10106,10232,10353,10467,10576,
   10676,10771,10861,10943,11018,11088,11153,11209,11261,11308,11350,
   11386,11418,11446,11471,11491,11511,11525,11538,11550,11560,11567,
   11573,11579,11583,11586,11589,11590,11592,11593,11593,11593,11592,
   11591,11590,11588,11585,11580,11576,11570,11563,11555,11544,11532,
   11518,11501,11481,11458,11431,11401,11366,11328,11284,11234,11179,
   11119,11051,10978,10899,10815,10722,10624,10518,10407,10290,10166,
   10038,9905.5,9767.8,9626.9,9482.6,9336.5,9188.8,9040.7,8893,8745.6,8601,
   8459.2,8321.4,8189,8062,7940.5,7824.6,7717,7615,7520.3,7432,7349.1,
   7270.8,7196.7,7126,7056.5,6987.8,6916.5,6844.2,6768,6687,6598.7,6503.4,
   6399.2,6285.4,6161,6027,5878,5718.8,5547.5,5362,5164.3,4954.6,4733.3,
   4501.4,4260,4011.4,3756.3,3500.2,3245.5,2996,2764.6,2557.6,2384.6,2269.6,
   2218.5,2240.2,2340.4,2516.4,2749.5,3027,3348,3695,4061.5,4444,4836.5,
   5234.6,5638.1,6042.4,6447.4,6849,7247.9,7639.4,8026.3,8404.4,8774,9133.2,
   9482.1,9817.8,10140,10452,10746,11026,11292,11539,11770,11984,12181,
   12361,12526,12672,12801,12914,13014,13097,13166,13225,13270,13304,
   13329,13347,13356,13361,13360,13357,13350,13342,13336,13329,13322,
   13317,13316,13318,13321,13326,13335,13346,13360,13375,13390,13406,
   13422,13436,13448,13457,13463,13465,13461,13452,13437,13415,13385,
   13351,13308,13259,13202,13140,13071,12996,12918,12836,12750,12662,
   12574,12482,12394,12306,12220,12137,12057,11982,11910,11845,11785,
   11729,11681,11636,11597,11564,11534,11509,11489,11473,11460,11449,
   11443,11438,11435,11437,11439,11444,11453,11464,11478,11496,11518,
   11545,11575,11611,11652,11698,11749,11806,11868,11934,12006,12081,
   12161,12244,12328,12415,12501,12586,12670,12750,12829,12901,12969,
   13029,13081,13127,13162,13190,13207,13213,13211,13199,13177,13144,
   13103,13054,12997,12933,12863,12788,12708,12625,12541,12455,12369,
   12285,12202,12123,12046,11972,11905,11843,11786,11736,11691,11651,
   11619,11592,11569,11553,11542,11536,11532,11535,11540,11549,11562,
   11578,11597,11620,11646,11675,11708,11744,11783,11825,11873,11924,
   11977,12035,12097,12162,12230,12301,12374,12450,12526,12603,12681,
   12759,12836,12911,12983,13052,13117,13179,13235,13284,13327,13362,
   13390,13411,13425,13429,13426,13415,13394,13367,13333,13291,13242,
   13188,13128,13062,12995,12923,12847,12771,12694,12616,12538,12462,
   12386,12311,12241,12172,12107,12044,11985,11931,11880,11833,11789,
   11749,11712,11680,11649,11624,11600,11581,11564,11551,11541,11535,
   11532,11535,11540,11551,11567,11587,11614,11646,11683,11727,11776,
   11831,11893,11959,12029,12103,12179,12260,12340,12421,12501,12580,
   12652,12722,12785,12842,12889,12924,12949,12961,12960,12943,12910,
   12861,12795,12710,12606,12484,12344,12182,12004,11807,11590,11355,
   11103,10834,10549,10248,9932.9,9603.4,9261.1,8909,8543.5,8168.8,7787.4,
   7397.4,7001,6600.6,6197.9,5793.6,5389.3,4989,4593.3,4207.6,3833.5,3478,
   3148.5,2851.8,2597.8,2402.4,2271.3,2213,2240.5,2334.8,2485.4,2680.6,2905,
   3147,3399.9,3657.8,3912.5,4165,4409.9,4645.4,4870,5082.8,5285,5474.4,
   5650.8,5813.6,5964.8,6104,6230.3,6345.6,6451.1,6547.6,6634.5,6715,6790.4,
   6860.2,6928.4,6995,7061.3,7129.4,7200.5,7276.4,7359,7448,7548.1,7655.8,
   7773.1,7900,8039.9,8189.8,8348.6,8519.2,8698,8884.8,9078.3,9279.2,9486,
   9695,9908.8,10125,10340,10556,10769,10980,11185,11385,11580,11768,
   11945,12116,12276,12425,12562,12687,12802,12902,12991,13067,13129,
   13178,13215,13240,13253,13254,13245,13225,13196,13158,13113,13060,
   13001,12939,12870,12798,12724,12648,12571,12495,12418,12342,12267,
   12193,12122,12053,11984,11919,11854,11791,11729,11667,11606,11543,
   11480,11413,11347,11274,11198,11119,11033,10941,10844,10743,10634,
   10518,10395,10269,10135,9997,9853.4,9707.2,9556.7,9405,9250,9096.6,
   8943.3,8791.6,8642.9,8497,8357.5,8224,8096.7,7979,7871.5,7772.8,7686.1,
   7612.6,7551.9,7503,7469.9,7452,7448,7459.4,7485.5,7526,7579.2,7649.2,
   7730.2,7822,7926.2,8039,8160.5,8290.6,8426,8566.2,8711.2,8858,9006.8,
   9155,9302.9,9448.6,9592.9,9732.2,9868.5,10000,10126,10244,10355,10458,
   10554,10641,10721,10790,10848,10899,10937,10965,10982,10989,10983,
   10967,10940,10903,10852,10791,10719,10638,10547,10446,10334,10216,
   10090,9957.8,9818,9675,9526.5,9375.4,9222.1,9068,8913.9,8762.4,8613.4,
   8467.2,8327,8191.6,8064.7,7945.4,7833.9,7734,7646.1,7569.6,7504.8,7456,
   7421.5,7400.6,7396.7,7409.4,7437.2,7482,7542.8,7620.4,7713.5,7821.4,7945,
   8082.2,8232.2,8394,8567.2,8749,8940.6,9140,9345.1,9554.8,9768,9983.6,
   10201,10418,10633,10845,11053,11258,11455,11646,11827,12000,12164,
   12315,12455,12584,12699,12801,12890,12965,13025,13071,13104,13122,
   13128,13122,13103,13073,13034,12983,12925,12859,12787,12711,12630,
   12547,12462,12377,12292,12210,12129,12053,11980,11911,11849,11791,
   11741,11695,11654,11621,11594,11571,11554,11543,11535,11532,11535,
   11540,11548,11561,11577,11595,11617,11644,11672,11704,11740,11779,
   11822,11868,11917,11971,12029,12089,12154,12219,12289,12359,12432,
   12506,12580,12653,12723,12792,12857,12920,12974,13023,13065,13097,
   13118,13129,13130,13115,13087,13045,12984,12910,12818,12708,12580,
   12435,12272,12089,11889,11673,11436,11184,10916,10630,10330,10016,
   9687.8,9344.8,8991.5,8629,8254.4,7870.6,7480.1,7085,6682,6278.2,5872.9,
   5468.6,5067.8,4675,4296.2,3933.4,3595.5,3295.8,3045.5,2854.4,2739.8,2718.6,
   2780.4,2923,3144.7,3419.6,3735.9,4084.2,4455.5,4841.2,5236.9,5639.4,6043.7,
   6448,6849.7,7249,7642.8,8027.6,8405.5,8775.4,9134,9481.8,9817.5,10141,
   10450,10745,11026,11291,11538,11773,11991,12189,12374,12543,12692,
   12827,12948,13052,13143,13220,13285,13337,13380,13413,13437,13454,
   13465,13470,13473,13472,13468,13464,13459,13454,13451,13448,13447,
   13447,13450,13453,13457,13463,13469,13475,13481,13483,13484,13481,
   13474,13462,13443,13417,13383,13340,13286,13223,13148,13062,12964,
   12856,12734,12600,12455,12299,12131,11955,11767,11571,11369,11160,
   10945,10728,10506,10283,10061,9837.8,9618.7,9402.4,9192.5,8988.2,8791.4,
   8603.6,8423.8,8255,8097.5,7952.2,7815.4,7693.4,7581.5,7480.8,7388.6,7307.4,
   7234.2,7169,7107.8,7051.2,6998.9,6945,6893.5,6838.8,6781.2,6717.6,6648.5,
   6573,6487.7,6392.4,6287.3,6170,6041.5,5901,5746.4,5579,5398.6,5207,
   5000.8,4782.8,4554.7,4316,4067.5,3814.2,3559.2,3302.6,3052.7,2814,2602,
   2422,2288.3,2221.6,2230,2312,2468.1,2690.6,2961.7,3270,3613.5,3977,
   4354.7,4744.2,5143,5544.2,5949,6352.4,6754.6,7153,7546.7,7932.4,8311,
   8680.6,9038.5,9386.8,9721.9,10042,10348,10638,10909,11164,11401,11617,
   11812,11986,12138,12267,12373,12457,12515,12549,12560,12545,12507,
   12446,12360,12250,12118,11966,11788,11590,11374,11137,10882,10609,
   10320,10013,9692,9359,9011.1,8652.6,8283.6,7905,7518,7123.8,6726.1,
   6323.6,5918.6,5514,5111.9,4715.2,4326.7,3955.6,3603,3278.4,2992.1,2761.6,
   2594,2500,2503.3,2585.4,2738.9,2959,3223.5,3520,3839.7,4175.4,4519.6,
   4868,5218.1,5565.8,5911.5,6250.6,6583.5,6908.4,7223.8,7530.8,7826.8,8113,
   8387.1,8649.6,8901.7,9138.4,9364,9576.8,9778.6,9965.6,10141,10304,10455,
   10595,10724,10843,10952,11054,11146,11233,11312,11388,11459,11527,
   11592,11656,11719,11781,11846,11911,11977,12046,12116,12187,12261,
   12337,12415,12495,12575,12656,12735,12815,12894,12970,13045,13116,
   13185,13248,13306,13362,13409,13453,13491,13522,13547,13568,13582,
   13590,13595,13595,13591,13584,13573,13562,13549,13536,13522,13508,
   13495,13485,13476,13470,13467,13466,13467,13471,13477,13486,13497,
   13510,13524,13538,13551,13563,13575,13585,13592,13596,13595,13589,
   13580,13565,13543,13517,13486,13446,13403,13354,13298,13239,13175,
   13105,13034,12959,12883,12804,12724,12644,12564,12484,12406,12329,
   12255,12182,12113,12046,11981,11919,11861,11803,11749,11697,11646,
   11596,11548,11499,11451,11403,11356,11309,11259,11210,11161,11112,
   11063,11015,10967,10920,10877,10835,10797,10764,10734,10709,10689,
   10675,10668,10666,10670,10681,10697,10719,10747,10780,10815,10854,
   10897,10942,10989,11036,11085,11134,11184,11233,11281,11330,11378,
   11426,11474,11522,11570,11619,11669,11720,11775,11830,11888,11948,
   12011,12076,12145,12216,12290,12364,12441,12520,12601,12681,12761,
   12841,12918,12995,13067,13137,13204,13266,13324,13377,13424,13466,
   13501,13531,13554,13573,13585,13594,13596,13594,13590,13581,13571,
   13558,13544,13531,13517,13505,13493,13483,13476,13470,13467,13468,
   13471,13478,13485,13497,13511,13527,13542,13561,13579,13598,13614,
   13631,13646,13659,13670,13676,13682,13683,13682,13677,13671,13660,
   13647,13633,13617,13600,13582,13563,13546,13530,13514,13501,13489,
   13480,13474,13470,13470,13473,13479,13488,13500,13513,13529,13545,
   13562,13580,13599,13616,13632,13646,13659,13670,13677,13682,13683,
   13682,13677,13670,13660,13647,13631,13615,13598,13580,13562,13543,
   13526,13510,13495,13482,13473,13464,13458,13455,13454,13455,13456,
   13459,13462,13464,13466,13464,13460,13452,13438,13418,13388,13351,
   13304,13247,13175,13091,12994,12882,12754,12611,12451,12272,12078,
   11870,11641,11397,11139,10863,10572,10267,9947.7,9615.6,9270.7,8916,
   8548.8,8174.8,7791.6,7400.2,7003.5,6602.8,6198,5794.2,5390,4989,4593.7,
   4207.8,3833.6,3478,3148.5,2851.8,2596.8,2401.8,2271.3,2213,2240.8,2336.4,
   2484.7,2680.6,2905,3147.8,3399.9,3658.2,3914.2,4166,4409.9,4644.8,4870.8,
   5085.6,5287,5476.4,5653.6,5815.4,5966.4,6105,6230.3,6345,6448.3,6540.2,
   6623.5,6697.2,6763.8,6823.4,6875.3,6922,6964.3,7002.8,7037.4,7067.4,7095.5,
   7120.4,7141.6,7161.6,7177,7188,7194.6,7195.4,7189.6,7176.2,7155.5,7125.2,
   7085.1,7032,6968.6,6893,6801.2,6696.4,6577.4,6443.4,6293,6129.8,5952.3,
   5758.8,5553.6,5338,5108,4871.6,4628.8,4382.2,4137.5,3899.2,3671.9,3467.8,
   3290.8,3150,3066,3036.8,3066.6,3164,3323.5,3534.2,3791.2,4087,4410.9,
   4756,5119.8,5495.2,5878.4,6267,6657,7047,7433.5,7815.4,8191.6,8561,
   8919.6,9269,9606.3,9932.6,10245,10543,10825,11089,11339,11572,11783,
   11976,12151,12305,12438,12553,12648,12718,12770,12803,12812,12804,
   12778,12731,12666,12586,12488,12372,12245,12104,11948,11782,11606,
   11421,11227,11027,10822,10612,10400,10185,9971.5,9758.8,9548.2,9341.6,
   9139,8942,8753.8,8571.6,8399.7,8237,8085.1,7942.4,7810.9,7690.6,7580.5,
   7477.6,7385.4,7301.2,7223.4,7151,7081.7,7014.8,6949,6882.4,6812.5,6740.2,
   6662.4,6575.4,6482.2,6382,6270.4,6147.8,6014.5,5868.6,5712.5,5543.6,5363.4,
   5170.4,4967.4,4755,4533.8,4305.2,4072,3837,3603.5,3375.6,3160.4,2963.6,
   2793.6,2656,2567.2,2527.2,2539.1,2610.2,2729.5,2890.4,3084.8,3308,3546.9,
   3797,4054.7,4312.2,4569.2,4818,5061.5,5293.8,5516.2,5724.4,5920.9,6103,
   6269,6420.8,6558.7,6681.4,6789.5,6884,6966.4,7034.6,7093.4,7142,7181.1,
   7214.4,7241.1,7265.4,7287,7307.8,7330.9,7356.8,7388.2,7427,7473.7,7528.6,
   7596.5,7676.6,7769,7873.4,7991.9,8123.4,8267.5,8425,8594.5,8774.2,8964.2,
   9161.4,9367,9579,9794.8,10014,10235,10456,10676,10894,11107,11315,
   11518,11712,11898,12072,12236,12391,12530,12657,12772,12874,12960,
   13033,13092,13137,13169,13189,13196,13190,13175,13149,13114,13072,
   13021,12964,12902,12836,12765,12693,12620,12545,12470,12396,12324,
   12253,12185,12120,12058,11998,11943,11891,11843,11798,11757,11720,
   11687,11656,11629,11606,11585,11567,11554,11543,11537,11533,11534,
   11537,11548,11563,11582,11608,11638,11674,11717,11766,11819,11879,
   11943,12013,12087,12165,12244,12326,12408,12490,12570,12649,12721,
   12791,12854,12909,12955,12991,13018,13031,13034,13022,12996,12955,
   12901,12832,12747,12647,12535,12406,12266,12113,11947,11770,11584,
   11388,11185,10975,10761,10542,10321,10098,9876,9655.6,9437.7,9223.8,
   9016.5,8815.6,8622.7,8440,8268.7,8105,7958.6,7823,7700.2,7593.4,7502,
   7424.2,7361.4,7317,7285,7270,7270.1,7285.2,7314.5,7356.2,7412.5,7481.6,
   7560.9,7653,7756.1,7867,7988.1,8116,8251.4,8393.4,8540,8689.8,8842.9,
   8998,9154,9310,9463.7,9616.6,9765.6,9912.6,10052,10189,10320,10444,
   10561,10671,10773,10867,10956,11036,11109,11175,11235,11287,11334,
   11375,11411,11442,11469,11492,11511,11527,11542,11553,11562,11569,
   11574,11580,11584,11586,11587,11588,11586,11586,11584,11581,11576,
   11571,11564,11556,11547,11535,11522,11504,11487,11464,11438,11408,
   11375,11337,11294,11246,11193,11132,11068,10997,10919,10834,10744,
   10646,10543,10431,10316,10194,10066,9934,9796.6,9655,9511.1,9364.2,
   9215.5,9066,8916.6,8768.8,8623.3,8480,8341.8,8209.6,8084.5,7968,7860.5,
   7764.2,7677.2,7605,7545.6,7499,7467.9,7451.2,7448.9,7462.4,7490,7532,
   7587.1,7657,7738.5,7832,7936.5,8051.2,8174.4,8305.8,8443,8586.6,8734.4,
   8884.2,9036.9,9190,9341.4,9493,9641.6,9786.6,9926,10061,10187,10308,
   10421,10525,10617,10702,10776,10839,10892,10932,10963,10981,10988,
   10985,10970,10944,10909,10861,10804,10738,10662,10576,10483,10381,
   10272,10155,10032,9903.6,9769.5,9633,9490.1,9347.6,9203.3,9058,8914,
   8772.2,8633.6,8501.2,8374.5,8255,8145.4,8049,7963.6,7890,7836.2,7796.6,
   7774.4,7770.4,7785.5,7819.8,7872.3,7945.2,8036.2,8144,8270.5,8411.8,8566.8,
   8737.2,8917,9107.2,9306.8,9513.4,9724.8,9941,10160,10377,10593,10807,
   11017,11221,11415,11602,11779,11944,12095,12232,12353,12456,12543,
   12611,12661,12689,12696,12684,12649,12592,12514,12414,12292,12150,
   11987,11802,11599,11377,11135,10875,10599,10307,9999.5,9678,9344.5,
   8996.8,8639.1,8272,7896.4,7513.8,7126.8,6734.4,6340.5,5946.6,5554.2,5167.6,
   4787,4417,4065.1,3731.6,3423.2,3150.2,2918,2732.2,2601.6,2532.8,2520.9,
   2560,2649.5,2770.2,2912.7,3069.8,3231.5,3393.2,3547.3,3691.8,3823.2,3939,
   4033.5,4110.2,4167.9,4203,4216.5,4208.4,4180.4,4128.8,4058.7,3972,3864,
   3742.8,3608.6,3463.8,3312,3158.6,3007.7,2864,2735.2,2625,2547.2,2501.2,
   2490.2,2520.8,2589.5,2689.4,2818.1,2967.2,3131.3,3302,3477.2,3650.2,3817.3,
   3973.8,4118.5,4248.8,4362.5,4455.6,4530.4,4586,4615.6,4625.2,4615.2,4581.4,
   4526,4452.2,4359.5,4245.8,4119.3,3979,3827.7,3668.6,3505.6,3345.8,3191.5,
   3048.4,2925,2828.2,2760.2,2725,2730.9,2772.8,2846.7,2952,3080.5,3225.8,
   3382.4,3544,3705.1,3863,4011.3,4149,4272.7,4379.4,4467.5,4537.2,4586.3,
   4611.4,4615.9,4600,4557.4,4495,4411.8,4307.6,4183,4040,3883.1,3712.2,
   3532,3346,3158.1,2976.4,2805.9,2659.8,2547,2475.8,2455.1,2496,2592,
   2740,2942.5,3181.4,3450.7,3744.2,4054.5,4378.4,4709.7,5044.6,5381.3,5719,
   6052.5,6382.2,6705.3,7021.8,7330,7627.8,7916.5,8192.8,8457.7,8711,8949.1,
   9174.4,9385.1,9580.6,9761.5,9926.4,10075,10208,10323,10422,10503,10567,
   10614,10643,10654,10649,10624,10583,10525,10451,10356,10247,10122,
   9978.2,9819,9645.4,9455.4,9249,9028.9,8795,8547.6,8286.6,8014.2,7728.8,
   7432.5,7128.2,6813.3,6491,6162.5,5830,5495.9,5161.2,4828.5,4500.8,4184,
   3880,3592.7,3334.8,3105.8,2913,2770.2,2675.8,2631.4,2640.4,2694.5,2783,
   2901.4,3040.6,3188.8,3342,3492.2,3636.2,3769,3887.6,3990.5,4076.6,4142.8,
   4187,4211.1,4214,4192.9,4151.2,4089.2,4005.8,3902,3781.4,3644.5,3492.2,
   3328,3155,2978.2,2802,2631,2475.2,2341.5,2237.4,2172,2158.4,2193,
   2273,2404.4,2570.4,2763.7,2979.6,3209,3448,3690.7,3933.8,4174.1,4410,
   4638.3,4857,5066.1,5264.4,5451.5,5627.4,5790.7,5940.8,6080.1,6208,6322.2,
   6427.8,6522.9,6607.2,6683,6750,6810.3,6864.2,6912.9,6956,6993.4,7028.6,
   7060.6,7089,7114,7137.4,7157.3,7173.4,7184.9,7194,7195.7,7192,7180.1,
   7161.2,7133,7094.4,7045.5,6983.8,6909.3,6823,6720.8,6605,6474.3,6328,
   6167.5,5991.8,5800.6,5597.2,5380.3,5152,4911.9,4664.6,4410.6,4153.4,3896,
   3641.8,3397.2,3169.4,2961.6,2784,2650.4,2561.8,2523.9,2545,2618.5,2736.8,
   2893.1,3082.4,3292.2,3515,3747,3981.6,4216.9,4447.8,4672,4889,5096.3,
   5292.8,5479.7,5655,5815.7,5966.2,6106.4,6234.2,6350.5,6458,6554.9,6643,
   6724,6799,6869,6934,6996.3,7055.2,7113.5,7171,7228.5,7287.4,7347.2,
   7409,7471.7,7536,7601.9,7669.2,7735,7801.6,7865.8,7927.4,7986.5,8041,
   8091.5,8135.8,8174.2,8205,8228.5,8246.4,8255.2,8256.2,8249.4,8236,8217.3,
   8190.8,8160.4,8124.4,8087,8047.2,8007.9,7968.8,7933.8,7903,7877.5,7860.4,
   7850.6,7851.4,7864,7887.8,7923.5,7972.2,8033,8104,8190.3,8286.2,8391.7,
   8505.4,8627,8755,8888.5,9025.4,9164.6,9307,9447.7,9588.8,9726.5,9862.6,
   9995,10123,10248,10366,10478,10585,10685,10780,10869,10950,11025,
   11094,11157,11214,11265,11311,11352,11388,11421,11449,11473,11493,
   11511,11526,11539,11551,11559,11567,11574,11577,11581,11584,11586,
   11587,11588,11586,11585,11582,11578,11572,11566,11557,11547,11535,
   11520,11501,11479,11453,11423,11387,11345,11297,11243,11180,11108,
   11029,10938,10837,10726,10605,10470,10323,10164,9992.8,9807.8,9611,
   9401.6,9177.8,8943.2,8695.4,8435,8164.2,7882.7,7590,7288.2,6979,6659.6,
   6334.2,6003.5,5668,5330.5,4993,4658.5,4328.6,4006.5,3697,3407.4,3142.6,
   2907.5,2716,2575,2485.2,2454.3,2484,2562.1,2680,2831.4,3003.2,3185.8,
   3373.8,3560,3739.8,3909.1,4063.6,4202.7,4324,4425.4,4506.6,4566.8,4603.2,
   4617,4610,4580.3,4527.4,4456,4366,4254.1,4127.8,3988.9,3838,3680.5,
   3519,3357.8,3202.4,3059.8,2933,2834.1,2763.6,2726.2,2728.6,2769,2840.6,
   2942.5,3070.4,3214.5,3370,3531.8,3693.8,3851.9,4002.8,4140.5,4265.4,4375.4,
   4466.4,4538.7,4592,4620.9,4630,4618.3,4584.4,4529,4455.2,4361.6,4249.2,
   4123.3,3984,3836.6,3682,3526,3372.8,3231.5,3104.6,3003,2933,2897.1,
   2900,2951.7,3042.8,3170.5,3333,3522,3731,3952.9,4186.4,4423.8,4662,
   4897.7,5126.8,5349.9,5562.4,5763,5953.2,6128.7,6289.8,6437,6571,6687.2,
   6791.6,6883.2,6959.2,7022.5,7074.6,7114.7,7146.6,7169.2,7185,7194.8,7200.2,
   7202.8,7204.2,7205.5,7207.6,7213.8,7224.6,7239.8,7262,7293.1,7331.8,7379.2,
   7437.8,7504.5,7581.6,7669.2,7766,7872.1,7986,8110.4,8240.2,8376.4,8518.4,
   8665,8814.8,8966.7,9119.6,9272.2,9425,9573.9,9720.2,9862.2,9999.4,10129,
   10253,10370,10478,10575,10665,10743,10810,10869,10916,10950,10974,
   10986,10987,10978,10958,10926,10884,10833,10770,10698,10618,10528,
   10431,10325,10213,10093,9968.2,9838.1,9703,9566,9426.6,9285.1,9144.2,
   9004.4,8867,8732.3,8605.4,8484.2,8372.8,8271,8181.2,8105,8044.4,8000
};


long QMSL_Linear_Predistortion_NV::numEnvSamples = ENV_IN_NUM_SAMPLES;
long QMSL_Linear_Predistortion_NV::numEnvSamplesSwapped = ENV_IN_NUM_SAMPLES_SWAPPED;


