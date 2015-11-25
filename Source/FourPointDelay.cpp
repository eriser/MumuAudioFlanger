/*
  ==============================================================================

    FourPointDelay.cpp
    Created: 4 Oct 2015 8:27:11pm
    Author:  Jacob Penn

  ==============================================================================
*/

#include "FourPointDelay.h"
#include "FourPointInterpolate.h"
#include <string.h>


FourPointDelay::FourPointDelay() :  m_fDelayInSamples(0),
                                    m_fFeedback(0),
                                    m_fWetLevel(0),
                                    m_pBuffer(nullptr),
                                    m_nReadIndex(0),
                                    m_nDryIndex(0),
                                    m_nWriteIndex(0),
                                    m_nBufferSize(0)
{
   
}

FourPointDelay::~FourPointDelay()
{
    if(m_pBuffer)
        delete [] m_pBuffer;
}

void FourPointDelay::setMaxDelay(float sampleRate, float seconds)
{
    //don't allow your delay time to be longer than the buffersize!
    m_nBufferSize = seconds * sampleRate;
}

void FourPointDelay::setDelayTime(float sampleRate, float delayTime)
{
    m_fDelayInSamples = delayTime * sampleRate;
    if ( m_fDelayInSamples < 0)
    {
        m_fDelayInSamples = 0;
    }
    if ( m_fDelayInSamples > m_nBufferSize)
    {
        m_fDelayInSamples = m_nBufferSize;
    }
}

void FourPointDelay::setFeedback(float feedBack)
{
    m_fFeedback = feedBack;
}

void FourPointDelay::setWetMix(float wetMix)
{
    m_fWetLevel = wetMix;
}

// Run prepare to play and then cook the variables
void FourPointDelay::prepareToPlay()
{
    //delete if it exists
    if (m_pBuffer)
        delete [] m_pBuffer;
    //create new buffer
    m_pBuffer = new float[m_nBufferSize];
    //clear it for junk data
    if (m_pBuffer)
        memset(m_pBuffer, 0, m_nBufferSize*sizeof(float));
    m_nWriteIndex = 0;
    m_nDryIndex = 0;
    m_nReadIndex = 0;
}

void FourPointDelay::setPlayheads()
{
    //set up dry signal output
    m_nDryIndex = m_nWriteIndex - 2;
    
    if (m_nDryIndex < 0)
    {
        m_nDryIndex += m_nBufferSize;
    }
    
    //setup wet signal output
    m_nReadIndex = m_nDryIndex - (int)m_fDelayInSamples;
    if (m_nReadIndex < 0)
    {
        m_nReadIndex += m_nBufferSize;
    }
    
    //setup our 1 sample in future
    m_nFuture1Index = m_nReadIndex + 1;
    if (m_nFuture1Index < 0)
    {
        m_nFuture1Index += m_nBufferSize;
    }
    
    //setup our 2 sample in future
    m_nFuture2Index = m_nReadIndex + 2;
    if (m_nFuture2Index < 0)
    {
        m_nFuture2Index += m_nBufferSize;
    }
    //setup out 1 sample in past
    m_nPast1Index = m_nReadIndex - 1;
    if (m_nPast1Index < 0)
    {
        m_nPast1Index += m_nBufferSize;
    }
    
}

float FourPointDelay::process(float audioInput)
{
    
    //Assign Our Data
    float input = audioInput;
    float xn = m_pBuffer[m_nDryIndex];
    float yn = m_pBuffer[m_nReadIndex];
    float yn_f1 = m_pBuffer[m_nFuture1Index];
    float yn_f2 = m_pBuffer[m_nFuture2Index];
    float yn_p1 = m_pBuffer[m_nPast1Index];
    
    //if nothing is happening, pass our signal
    if(m_fDelayInSamples == 0)
    {
        yn = xn;
    }else{
        //find fractional delay and calculate interpolation
        float fFracDelay = m_fDelayInSamples - (int)m_fDelayInSamples;

        yn = FourPointInterpolate(yn, yn_p1, yn_f1, yn_f2, fFracDelay);
        //yn = dLinTerp(yn, yn_p1, yn_f1, yn_f2, fFracDelay);
        //yn = Delay_interpolate(yn, yn_p1, yn_f1, yn_f2, fFracDelay);
        //yn = Delay_interpolate(yn, yn_f1, yn_f2, yn_p1, fFracDelay);
        
        //write data into our buffer
        m_pBuffer[m_nWriteIndex] = input + (m_fFeedback * yn);
        
        //move our data through the buffer
        m_nWriteIndex++;
        if(m_nWriteIndex > m_nBufferSize)
            m_nWriteIndex = 0;
        
        m_nDryIndex++;
        if(m_nDryIndex > m_nBufferSize)
            m_nDryIndex = 0;
        
        m_nReadIndex++;
        if(m_nReadIndex > m_nBufferSize)
            m_nReadIndex = 0;
        
        m_nFuture1Index++;
        if(m_nFuture1Index > m_nBufferSize)
            m_nFuture1Index = 0;
        
        m_nFuture2Index++;
        if(m_nFuture2Index > m_nBufferSize)
            m_nFuture2Index = 0;
        
        m_nPast1Index++;
        if(m_nPast1Index > m_nBufferSize)
            m_nPast1Index = 0;
    }
    
    //send back our wet/dry delay mix
    return ((m_fWetLevel * yn) + ((1.0 - m_fWetLevel) * input));

    
}


