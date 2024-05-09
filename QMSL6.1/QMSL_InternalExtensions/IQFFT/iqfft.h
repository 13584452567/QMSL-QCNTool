/******************************************************************************
 * $File: //depot/HTE/QDART/QMSL6.1/QMSL_InternalExtensions/IQFFT/iqfft.h $
 *
 * DESCRIPTION: CIQFFT
 ******************************************************************************
 *
 * Copyright (c) 2014 QUALCOMM Technologies Incorporated.
 * All rights reserved.
 * Qualcomm Confidential and Proprietary
 *
 ******************************************************************************
 *
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_InternalExtensions/IQFFT/iqfft.h#1 $
 * $DateTime: 2015/05/12 08:52:42 $
 *
 */
#pragma once

#pragma warning(disable:4786)

#include <math.h>
#include "qlib_defines.h"
#include <vector>

typedef enum
{
   FILTER_TYPE_VOID,
   FILTER_TYPE_CHEETAH,
   FILTER_TYPE_MAX = 0xFFFF
}IQFFT_FILTER_TYPE;

typedef struct 
{
   double *state;
   int index;
   int max_index;

}FirFilter;

const double DecimationCoeff_CheetahFilter[] =  {-1820, -3640, 3640, 20024, 29128, 20024, 3640, -3640, -1820 };

class CIQFFT  
{

public:
   // These two functions must be public for MSVC6
   CIQFFT();
   virtual ~CIQFFT();
public:
   static CIQFFT* GetInstance( void );	

   // Call this before doing anything else....or else!!
   virtual void Initialize( const int maxSize, const int sampleBitFormat, const double samplingFrequency );


   // Call this AFTER doing anything else to release memory!!
   //Must do Initialize BEFORE next time using the IQFFT class!
   //Deallocate memory for all buffers used during IQ processing	
   virtual void DeallocateMemory(void);

   //!Set max record size supported, data format, and sampling frequency.
   virtual void SetIQCaptureConfig(const int maxSize, const int sampleBitFormat, const double samplingFrequency, const bool isMediaflo = false );
   //!Should be called after setting pointer to the phone, 
   //dynamically allocates memory for all the buffers needed during I/Q processing
   virtual void AllocateMemory(void);
   //!Sets the raw I/Q data that will be transformed. Must be called prior to CaptureIQ()
   virtual void SetRawData( WORD* rawData );
   //!Obtains I/Q and decodes them
   virtual void DecodeData(void);

   //! Allows user to specify the IQ samples and the number of samples and sample rate, can be called instead of
   //! SetRawData() and DecodeData()
   virtual void SetIQ_Data( const double* pI_Samples, const double* pQ_Samples, const dword iNumSamples );

   virtual void DoPhase(double *phase, double* avgPhase);
   virtual void DoPhase_V2(double *phase, double* avgPhase);
   //!Configures parameters used in calculating Carrier-to-Noise
   //!Careful on changing the -999.0MHz value, if must change, do it only to a smaller value
   virtual void ConfigureCarrier2Noise(bool doPeakSearch = true, double RXOffsetMHz=0,
      bool doPSWin = false,double peakSearchWindowSizekHz=1.5,
      bool sumPwrAsBins = false, int totalBins4PwrSum=16,
      bool doBandWidthLimiting = false, double limitBwkHz=0,
      bool enableSampleRotation = false);
   //!Configures Windowing capabilities.  Should be called to performing windowing.
   virtual void ConfigureWindowing(BOOL enable, int type);
   //Peforms data windowing if enabled based on 3 types.
   virtual void DoWindowing();
   //!Performs statistical analysis in the I/Q time domain data
   virtual void DoStats();
   //!Get statistical results
   virtual void GetStats(double* Imean, double* IStdDev, double* Qmean, double* QStdDev);
   //Obtains I and Q in time as well as x-axis time labeling
   virtual void GetTimeDomain(double* tI, double* tQ, double* t);
   virtual double GetIM2Level(void);
   virtual double GetAmplitudeAtFreq(double Freq);
   //	virtual void CaptureIQMediaflo();

   //! Return the number of bins in the FFT
   virtual int GetFFT_Size( void );

   //Gets the FFT's I and Q 
   virtual void GetFFTIQ(double* FFTIBuffer, double* FFTQBuffer);

   virtual void getWindowedIQ(double* Windowed_I_Buffer, double* Windowed_Q_Buffer);
   virtual void SetWindowedIQ(double* Windowed_I_Buffer, double* Windowed_Q_Buffer);  
   virtual void getFilteredIQ(double* Filtered_I_Buffer, double* Filtered_Q_Buffer);

   //Computes FFT of captured data
   virtual int ComputeFFT(const int isign = 1);


   virtual int ComputeCarrier2Noise();
   //returns the record size used when FFT was performed
   virtual int GetFFTRecordSize();
   //returns the last capture size used
   virtual void SetCaptureSize(int size);
   //Sets the capture size.
   virtual void SetCaptureSize_V2(int size);
   //returns the I/Q format supported 4 - nibble, 8 - byte
   virtual int GetDataFormat( );
   //return sampling frequency supported
   virtual double GetSamplingFrequency( );
   //returns max record size supported
   virtual int GetMaxRecordSize( );
   //returns a measurement result beased on the type of measurement type requested
   virtual double GetMeasurement(int theMeasurementType);
   //performs an FFT then yields a Shifted FFT and the x-axis frequency labeling
   // returning linear will not normalize the result, and the "shiftFFTBuffer" will return the squared linear amplitude
   virtual bool DoShiftFFT( double* shiftFFTBuffer, double* Frequency, bool bReturnLinear = false );
   virtual void GetQSigned( double* QSignedBuffer );
   virtual void GetISigned( double* ISignedBuffer );
   virtual void GetAbsFFTMag( double* IQMagnitudeBuffer );
   virtual bool GetFFTRelative( double* FFTBufferh );
   virtual int GetCarrierFFTBin();
   virtual void GetQDataRaw( int* QRawBuffer );
   virtual void GetIDataRaw( int* IRawBuffer );
   virtual double GetFFTMaxValue();
   //!im2Offset is the intermod location, rxOffsetMHz is the actual RX signal offset
   virtual void ConfigureIIP2(double im2OffsetMHz, double rxOffsetMHz);
   //Performs an IMR2 suppression measurement
   virtual double GetIIP2Level();
   //!im3Offset is the intermod location, rxOffsetMHz is the actual RX signal offset
   virtual void ConfigureIIP3(double im3OffsetMHz, double rxOffsetMHz);
   //Performs an IMR3 suppression measurement
   virtual double GetIIP3Level();

   virtual double Jlblog(double x);

   //Computes the gain in the IQ samples in relation to the specified gain constant
   virtual double GetIQdataGain( double gainConstant );
   //Get the filter co-efficient and filter length based on filter type
   virtual const double* GetFilterCoeff(IQFFT_FILTER_TYPE filterType, unsigned int* len);
   //Configure filtering operation
   virtual void ConfigureFilter(bool bEnable, IQFFT_FILTER_TYPE filterType );
   //Initialize the Fir Filter based on length
   virtual bool InitFirFilter(FirFilter* filter, IQFFT_FILTER_TYPE filterType);
   //Function to call filtering operations
   virtual bool RunFirFilter(FirFilter* filter,IQFFT_FILTER_TYPE filterType);
   //Clear the FIR filter
   virtual void ResetFirFilter(FirFilter* filter);
   //Deallocate memory
   virtual void DeallocateFirFilter(FirFilter* filter);
   //Master function which calls sub filtering functions for I and Q samples
   virtual void FilteringOperation(FirFilter* filter, const double* filterCoeff, double* in, double* out);
   //Function where all filtering operations happen
   virtual bool FilterIQSamples(void);
   
protected:
   virtual double NormalizePhase(double theta);

   //!Windowing functionality
   virtual void WindowBartlett();
   virtual void WindowWelch();
   virtual void WindowHann(); 

   //Filtering computations
   virtual int ModAdd(int in, int addVal, const int max);

   //Decodes the I/Q samples 
   virtual void DecodeIQData(void);

private:
   // a pointer to self to allow static functions to call non-static functions on the singleton instance.
   static CIQFFT* m_pSelf;

   double* m_pDQ;  // signed decimal Q
   double* m_pDI;  // signed decimal I 
   double* m_pWindowedQ;  // signed decimal Q
   double* m_pWindowedI;  // signed decimal I 
   double* m_pFFTQ;  // signed decimal FFT Q
   double* m_pFFTI;  // signed decimal FFT I 
   double* m_pShiftFFTIQ;
   double* m_pShiftFFTFreq;
   double* m_pFilteredQ; // signed decimal Q
   double* m_pFilteredI; // signed decimal I
   int* m_pRawQ;   // unsigned interger Q
   int* m_pRawI;   // unsigned interger I

   //Members for Statistical Analysis
   double m_Imean;//mean of I
   double m_Qmean;//mean of Q
   double m_IStdDev;//Standard Deviation of I
   double m_QStdDev;//Standard Deviation of Q

   double m_fftMaxValue;
   IQFFT_FILTER_TYPE m_filterType;

   WORD* m_pRawIQ;  // IQ straight from the phone
   int m_maxIQPairs;//Hold the overall max record size
   int m_captureSize;//Hold the last capture size used
   int m_DataFormat;//Hold the data format 4 - nibble, 8 - byte
   int m_fftMaxRecordSize;//Hold the valid fft record size
   const int RECORD_SIZE;//The phone sends chunks of 256
   double m_SamplingFrequency;//Hold the sampling frequency
   BOOL m_windowingEnable;//1 - enable; 0 - disable
   bool m_filteringEnable;//1 - enable; 0 - disable
   int m_windowingType;//0 - Hann; 1 - Welch; 2 - Bartlett

   // Measurement Attributes
   double m_CNR;			        // computed Carrier-to-Noise
   double m_carrierPower;	  // computed carrier power
   int    m_carrierFFTBin;		// FFT bin of the carrier signal

   //!Used for IMR2 freq location at baseband
   double m_IM2OffsetMHz;
   //!Used for IM3 freq location at baseband
   double m_IM3OffsetMHz;
   //!Used for carrier freq location at baseband
   double m_rxOffsetMHz;
   bool m_peakSearch;

   //! Used primarily on C/N computation
   bool m_doPSWin;
   int m_psTotalBins;
   bool m_sumPwrAsBins;
   bool m_doBandWidthLimiting;
   bool m_enableSampleRotation;
   int m_totalBins4PwrSum;
   double m_psWinSizekHz;
   double m_pslimitBWkHz;
   double m_snrAdjust;
   int m_carrierWidth;

   bool m_isRawDataAvailable;

};
