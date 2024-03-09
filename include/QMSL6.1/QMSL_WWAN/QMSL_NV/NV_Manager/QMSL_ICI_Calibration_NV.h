/******************************************************************************/
/**
Program: QMSL

$Id: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_ICI_Calibration_NV.h#2 $

\brief
Definition of QMSL_ICI_Calibration_NV

In addition, this class provides functionality for common data manipulations.

\b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

\note
Compiler:  Microsoft Visual C++ v7.0
*******************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

#define QMSL_ICI_CX2_SAMPLES_PER_BPG 512
#define QMSL_ICI_BPG_PER_CAL 25
#define QMSL_ICI_SAMPLE_LENGTH 12800
#define QMSL_ICI_FULL_CPICH_SAMPLE_LENGTH 76800
#define QMSL_ICI_PI 3.1415926535897932384626433832795
#define QMSL_ICI_CIRLEN 16
#define QMSL_ICI_COEFF_BITWIDTH 10
//#define QMSL_ICI_TRUNC_BITS 9
#define QMSL_ICI_LAMBDA 0.999999
#define QMSL_ICI_CX2 7680000
#define QMSL_ICI_ERRVEC_LENGTH 12769
#define QMSL_ICI_COEFF_NV_LENGTH 16

typedef struct
{
   double real;
   double imaginary;
} ComplexDouble;


typedef struct
{
   int real;
   int imaginary;
} ComplexInt;

//--------------------------------------------------------------------------
/**
//
CLASS:  QMSL_ICI_Calibration_NV

\brief   Definition for ICI calibration core functions and NV computation class

This class contains several ICI calibrations specific functions for data manipulation,
NV computation and desired complex arithmetic functions.

*/
//--------------------------------------------------------------------------
class QMSL_ICI_Calibration_NV
{
public:
   /******************************************************************************/
   /**

   \brief Initialize class.

   Initialize class.

   \return  none

   \param   none

   \warning none

   *******************************************************************************/
   QMSL_ICI_Calibration_NV() { }

   /******************************************************************************/
   /**

   \brief Class destructor.

   Class destructor.

   \return  none

   \param None.

   \warning None.

   *******************************************************************************/
   ~QMSL_ICI_Calibration_NV() { }

   /******************************************************************************/
   /**

   \brief Conjugates and reverses the input Complex Data.

   Takes complex data, computes the conjugated and reverse indexed version of it and
   returns the same in another complex data array.

   \return  ComplexDouble array of reversed conjugated version of input

   \param   ComplexDouble array of input data

   \warning None.

   *******************************************************************************/
   void DoReverseConjugate(ComplexDouble* input, ComplexDouble* output, unsigned long length );

   /******************************************************************************/
   /**

   \brief Computes the lag after cross-correlation

   Used after correlation to compute the lag of the correlation peak.

   \return  The lag in samples.

   \param   input [input] ComplexDouble array of input data (the result of correlation)

   \param   length1 [input] length of the first of two sequences that were correlated

   \param   length2 [input] length of the second of two sequences that were correlated

   \warning None.

   *******************************************************************************/
   long ComputeLag(ComplexDouble* input, long length1, long length2 );

   /******************************************************************************/
   /**

   \brief Computes the frequency offset in Hz

   Computes the frequency offset in the IQ samples obtained from the phone's Rx chain.

   \return  The frequency offset

   \param   lag [input] Lag obtained from the ComputeLag function after cross-correlation

   \param   samp [input] IQ data obtained from phone's Rx chain

   \param   sampleLength [input] number of samples in above IQ data

   \param   cpich [input] Array of offline CPICH samples

   \param   aligned_cpich [output] Array of frequency offset compensated IQ data

   \param   numBPGperComputation [input] number of BPGs to be used per iteration in the
            computation of the freq offset

   \warning None.

   *******************************************************************************/
   double ComputeFrequencyOffset(long lag, ComplexDouble *samp, long sampleLength,ComplexDouble *cpich, ComplexDouble* aligned_cpich, long numBPGperComputation );

   /******************************************************************************/
   /**
   public  ApplyFrequencyOffset

   Applies the computed frequency offset to the input samples

   \param  iqsamp [inout] Array of input samples to which the frequency offset will be applied

   \param  sampleLength [input] Length of that array

   \param  offset [input] The frequency offset to be applied

   \return void
   *******************************************************************************/
   void ApplyFrequencyOffset(ComplexDouble* iqsamp, long sampleLength, double offset);

   /******************************************************************************/
   /**
   public  ComputeCoefficients

   The core of the ICI calibration exercise - computes the ICI filter coefficients using
   the RLS (recursive least squares) algorithm

   \param  sampIn [input] Rx data after initial processing

   \param  sampOut [input] Offline CPICH data after initial processing

   \param  cir [output] The computed ICI filter coefficients

   \param  cirLen [input] Number of ICI filter coefficients

   \param  sampLen [input] Length if sample arrays of received and offline data

   \param  lambda [input] Tuning parameter for algorithm

   \return double The estimate of the SNR based on the IQ data
   *******************************************************************************/
   double ComputeCoefficients(ComplexDouble *sampIn, ComplexDouble *sampOut, ComplexDouble *cir, int cirLen, int sampLen, double lambda);

   /******************************************************************************/
   /**
   public  NormalizeAndRound

   Normalize and round off the ICI filter coefficients that were computed
   by ComputeCoefficients

   \param  ICIfir [input] The ICI filter coefficients resulting from running
                          ComputeCoefficients

   \param  iqSamp [input] The Rx IQ data

   \return ComplexInt* The array of ICI filter coefficients
   *******************************************************************************/
   void NormalizeAndRound(ComplexDouble* ICIfir, ComplexDouble* iqSamp, ComplexInt* retval, long filterLength);

   /******************************************************************************/
   /**
   public  ComputeCoefficientsNV

   Convert the ICI filter coefficients into a format used by NV

   \param  ICIcoefs [input] The ICI filter coefficients

   \param  coefficients [output] The NV form of the ICI coefficients

   \return void
   *******************************************************************************/
   void ComputeCoefficientsNV(long* ICIcoefs, long* coefficients, long trunc_bits, long filterLength);

   /******************************************************************************/
   /**
   public  ComplexConvolve

   Performs the convolution of two sequences

   \param  x = First sequence
   \param  y = Second sequence
   \param  len1 = Length of first sequence
   \param  len2 = Length of second sequence
   \param  result = Ouput of convolution operation

   \return void
   *******************************************************************************/
   void ComplexConvolve(ComplexDouble* x, ComplexDouble* y, int len1, int len2, ComplexDouble* result);

   /******************************************************************************/
   /**
   public  FilterCPICH

   Uses the ComplexConvolve function to filter the input sequence

   \param  cpich = Complex input sequence
   \param  filteredCpich = Sequence after being rc-filtered

   \return void
   *******************************************************************************/
   void FilterCPICH( ComplexDouble* cpich, ComplexDouble* filteredCpich );

   /******************************************************************************/
   /**
   public  RemoveMean

   Computes and removes mean from complex input sequence

   \param  complex = Input sequence
   \param  length = Length of input sequence

   \return void
   *******************************************************************************/
   void RemoveMean( ComplexDouble* complex, long length );

   /******************************************************************************/
   /**
   public  CircShift

   Circular shifts the complex input sequence by shiftFactor samples

   \param  input = The complex input sequence
   \param  length = Length of the input sequence
   \param  shiftFactor = Number of samples by which input sequence has to be shifted

   \return void
   *******************************************************************************/
   void CircShift( ComplexDouble* input, long length, long shiftFactor );

   /******************************************************************************/
   /**
   public  Upsample

   Upsamples the complex input sequence by upSampleFactor

   \param  input = Complex input sequence
   \param  upsampledData = Upsampled sequence
   \param  inputLength = Length of the input sequence
   \param  upsampleFactor = Factor by which the input sequence is upsampled

   \return void
   *******************************************************************************/
   void Upsample( ComplexDouble* input, ComplexDouble* upsampledData, long inputLength, long upsampleFactor);

   static const long QMSL_ICI_Calibration_NV::full_cpich_i[QMSL_ICI_FULL_CPICH_SAMPLE_LENGTH];
   static const long QMSL_ICI_Calibration_NV::full_cpich_q[QMSL_ICI_FULL_CPICH_SAMPLE_LENGTH];
   static const double QMSL_ICI_Calibration_NV::sample_data_i[QMSL_ICI_SAMPLE_LENGTH];
   static const double QMSL_ICI_Calibration_NV::sample_data_q[QMSL_ICI_SAMPLE_LENGTH];
   static const double QMSL_ICI_Calibration_NV::cpich_raw_i[QMSL_ICI_SAMPLE_LENGTH];
   static const double QMSL_ICI_Calibration_NV::cpich_raw_q[QMSL_ICI_SAMPLE_LENGTH];
   static const double QMSL_ICI_Calibration_NV::rcfilt[QMSL_ICI_CX2_SAMPLES_PER_BPG];


   /******************************************************************************/
   /**
   public  ComplexMultiplyD

   Multiplies two complex numbers

   \param  x = First complex number
   \param  y = Second complex number

   \return ComplexDouble Product of x and y
   *******************************************************************************/
   ComplexDouble ComplexMultiplyD(ComplexDouble x, ComplexDouble y);

   /******************************************************************************/
   /**
   public  ComplexDivideD

   Divides two complex numbers

   \param  x = First complex number
   \param  y = Second complex number

   \return ComplexDouble Quotient of two complex numbers
   *******************************************************************************/
   ComplexDouble ComplexDivideD(ComplexDouble x, ComplexDouble y);

   /******************************************************************************/
   /**
   public  ComplexConjugate

   Computes the complex conjugate of the input

   \param  x = Input complex number

   \return ComplexDouble Conjugate
   *******************************************************************************/
   ComplexDouble ComplexConjugate(ComplexDouble x);

   /******************************************************************************/
   /**
   public  GetMagnitude

   Computes the magnitude of the input complex number

   \param  x = Input complex number

   \return double Magnitude
   *******************************************************************************/
   double GetMagnitude(ComplexDouble x);

private:
   /******************************************************************************/
   /**
   private  IntegerToTwosComplement

   Converts an integer to 2's complement form

   \param  x = Integer
   \param  n = Number of bits

   \return long Two's complement
   *******************************************************************************/
   long IntegerToTwosComplement( long x, long n);

   /******************************************************************************/
   /**
   private  sgn

   Returns the sign of the input power

   \param  x = Input number

   \return long Sign of input number
   *******************************************************************************/
   long sgn( double x );

   /******************************************************************************/
   /**
   private  unwrap

   Unwraps the phase of the input sequence

   \param  phase_array = Input array of phases
   \param  unwrapped_phase = Output array of unwrapped phases
   \param  length = Length of input array

   \return void
   *******************************************************************************/
   void unwrap( double* phase_array, double* unwrapped_phase, long length );
};