/******************************************************************************
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_Linear_Predistortion_NV.h#2 $
 * $DateTime: 2015/10/29 15:54:50 $
 *
 * DESCRIPTION:
 ******************************************************************************
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All rights reserved.
 * Qualcomm Technologies, Inc. Confidential and Proprietary.
 *
 ******************************************************************************
 */

#include <vector>
#include <map>
using namespace std;

#include "QLib_Defines.h"
#include "QMSL_Vector.h"

#if defined( QMSL_POSIX_PORTABLE )
/**

 enum:  QMSL_DataTypeEnum

 \brief This enumeration defines the storage type of each element
 */
enum QMSL_DataTypeEnum
{
   QMSL_word8,    //!<  ' Unsigned 8-bit
   QMSL_word16,   //!<  ' Unsigned 16-bit
   QMSL_int8,     //!<  ' Signed 8-bit
   QMSL_int16,    //!<  ' Signed 16-bit
   QMSL_word32,   //!<  ' Unsigned 32-bit
   QMSL_int32,    //!<  ' Signed 32-bit
   QMSL_word64,   //!<  ' Unsigned 64-bit
   QMSL_int64,    //!<  ' Signed 64-bit
};
#endif

#define ENV_IN_NUM_SAMPLES 5000
#define ENV_IN_NUM_SAMPLES_SWAPPED 5500

class QMSL_Linear_Predistortion_NV
{
public:

   /******************************************************************************/
   /**
   public static  estimateAndCorrectPhaseDrift

   Removes frequency error between the box and phone LO. The function evaluates the frequency error as
   the first derivative of the phase and removes this from all the phase samples. A window of the samples
   is used for the frequency error estimation (to avoid transients)

   \param  CVec1 = Input / Output array of phase samples
   \param  estStart = Input Phase estimation window start
   \param  estEnd = Input Phase estimation window end
   \param  corrStart = Input Phase correction window start
   \param  corrEnd = Input Phase correction window end

   \return estimatedFreqErrPerSample
   *******************************************************************************/
   static float estimateAndCorrectPhaseDrift(float * CVec1,long estStart,long estEnd, long corrStart,long corrEnd);

   /******************************************************************************/
   /**
   public static  crossCorrelate

   Time domain cross correlation, takes two input vectors and their sizes, and returns the delay

   \param  CVec1 = Input vector 1
   \param  CVec2 = Input vector 2
   \param  CVec1Size = Input vector 1 size
   \param  CVec2Size = Input vector 2 size

   \return long delay is the difference in number of samples between in the input vectors
   *******************************************************************************/
   static long crossCorrelate(float * CVec1,const float * CVec2, long CVec1Size, long CVec2Size);

   /******************************************************************************/
   /**
   public static  crossCorrelateIQFFT

   Faster FFT based cross correlation, takes two input vectors and their sizes, and returns the delay

   \param  CVec1 = Input vector 1
   \param  CVec2 = Input vector 2
   \param  CVec1Size = Input vector 1 size
   \param  CVec2Size = Input vector 2 size

   \return long delay is the difference in number of samples between in the input vectors
   *******************************************************************************/
   static long crossCorrelateIQFFT(float * CVec1,const float * CVec2, long CVec1Size, long CVec2Size);

   /******************************************************************************/
   /**
   public static  updateDelay

   Perform a gain vs. Pin computation for a set of delays and
   return the delay update that corresponds to the smallest gain
   variation in a specific Pin bin (hardcoded for now)

   \param  CVec1 = Input vector 1
   \param  CVec2 = Input vector 2
   \param  CVecSize = Input vectors size

   \return long Update to the correlation delay.
   *******************************************************************************/
   static long updateDelay(float * CVec1,const float * CVec2,long CVecSize);

   /******************************************************************************/
   /**
   public static  computeGain

   Determines the AMAM Gain Curve (not NV). Takes the input power vector and determines the mean of the
   output powers corresponding to that, and determines gain = mean output - input.

   Also change the input power vector to a sorted list of 0.1 dB array and report the gain corresponding to that

   \param  InPwr = Input Power Vector
   \param  MeasPwr = Measured Power Vector
   \param  VecLength = Length
   \param  skipSamples = Number of samples not included in computation
   \param  inPwr = Output. in 0.1dB steps
   \param  gain = Output. Gain corresponding to inPwr

   \return void
   *******************************************************************************/
   static void computeGain(const float * InPwr,float * MeasPwr, unsigned long VecLength, unsigned long skipSamples
                           , vector<float>& inPwr, vector<float>& gain);

   /******************************************************************************/
   /**
   public static  computePhase

   Determines the AMPM Discortion Curve (not NV). Takes the input power vector and determines the mean of the
   output phase corresponding to that, and determines distortion = mean output phase.

   \param  InPwr = Input Power Vector
   \param  MeasPhase = Measured Phase Vector
   \param  VecLength = Length
   \param  skipSamples = Number of samples not included in computation
   \param  inPwr = Output. in 0.1dB steps
   \param  phase = Output. Corresponding phase distortion

   \return void
   *******************************************************************************/
   static void computePhase(const float * InPwr,float * MeasPhase, unsigned long VecLength, unsigned long skipSamples
                            , vector<float>& inPwr, vector<float>& phase);

   /******************************************************************************/
   /**
   public static  SmoothData

   This function takes in the input power, Distortion (Gain or Phase) and
   generates a smoothed version that corresponds to the same input power

   \param  InPwr = Input Power (x)
   \param  InDistortion = Input distortion (measured gain/phase)
   \param  SmoothedDistortion = Output
   \param  winSize = Smoothing window size

   \return void
   *******************************************************************************/
   static void smoothData( vector<float> InPwr, vector<float> InDistortion, vector<float>& SmoothedDistortion, float winSize, bool xknot);

   /******************************************************************************/
   /**
   public static  truncateData

   Truncates data below certain input Level. (noise)

   \param  truncLevel = input level
   \param  InPwr = Input/Output Power Vector
   \param  Gain = Input/Output Gain Vector
   \param  Phase = Input/Output Phase Vector

   \return void
   *******************************************************************************/
   static void truncateData( float truncLevel, vector<float>& InPwr, vector<float>& Gain, vector<float>& Phase);

   /******************************************************************************/
   /**
   public static  generateAMAMNV

   AMAM NV Generation

   \param  targetOutputPowers = Input Array of powers (index into NV)
   \param  inPwr = Input Power Vector
   \param  smoothedGain = Input Gain Vector
   \param  amamLinear = Output AMAM NV Vector

   \return void
   *******************************************************************************/
   static void generateAMAMNV( QMSL_Vector<float> targetOutputPowers, vector<float> inPwr, vector<float> smoothedGain,
                               QMSL_Vector<long>& amamLinear) ;

   /******************************************************************************/
   /**
   public static  generateAMPMNV

   AMPM NV Generation

   \param  inPwr = Input Power Vector
   \param  smoothedPhaseDistortion = Input Gain Vector
   \param  amPmWrapped = Output AMPM NV Vector

   \return void
   *******************************************************************************/
   static void generateAMPMNV( vector<float> inPwr, float dacScale, vector<float> smoothedPhaseDistortion, QMSL_Vector<long>& amPmWrapped) ;

   /*!
   *  public static  slopeCompensatePhase
   *
   *  Function that'll apply a slope compensation
   *
   *  \param [in]       inPwr const vector<float>   = Reference input power.
   *  \param [in, out]  vector<float>&  = Vector to which the slope compensation is applied.
   *  \param [in]       slopeFactor float = Slope that is applied to the above vector (unit deg/10dB for phase, dB/10dB for power)
   *
   *  \return void
   *
   */
   static void slopeCompensate( vector<float> inPwr, vector<float>& outVector, float slopeFactor) ;

   /*!
   *  public static  logParams
   *
   *  Debug Function that'll log to csv all the input parameters (not data)
   *
   *  \param [in]       params const QMSL_GSM_PreDist_Cal_Result*   = Pointer to input Params
   *  \return void
   *
   */
   static void logParams(const QMSL_GSM_PreDist_Cal_Result *params);

#if !defined (QMSL_POSIX_PORTABLE)
   static const float QMSL_Linear_Predistortion_NV::ampl_in[ENV_IN_NUM_SAMPLES_SWAPPED];
#else
   static const float ampl_in[ENV_IN_NUM_SAMPLES_SWAPPED];
#endif
   static long numEnvSamples;
   static long numEnvSamplesSwapped;

   QMSL_Linear_Predistortion_NV() {};

private:
   static int  choose_knots_x(const vector<float>& x, vector<float>& y, vector<float>& xknots,int meassize,float delta_x);
   static int  choose_knots_y(const vector<float>& x, vector<float>& y, vector<float>& xknots,int meassize,float delta_y);
   static void splsmooth(const vector<float>& x, vector<float>& y, int meassize,  const vector<float>& xknots, int NknotIntervals);
   static void qrfact(float* A, int rows, int cols);
   static void third_order(const vector<float>& x, vector<float>& y, int meassize);
};

