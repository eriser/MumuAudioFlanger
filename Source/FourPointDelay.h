/*
  ==============================================================================

    FourPointDelay.h
    Created: 4 Oct 2015 8:27:11pm
    Author:  Jacob Penn
    This is a four point delay based off of 4 point spline interpolation.

  ==============================================================================
*/

#ifndef FOURPOINTDELAY_H_INCLUDED
#define FOURPOINTDELAY_H_INCLUDED

class FourPointDelay
{
public :
    FourPointDelay();
    ~FourPointDelay();
    void setMaxDelay(float sampleRate, float seconds);
    void setDelayTime(float sampleRate, float delayTime);
    void setFeedback(float feedBack);
    void setWetMix(float wetMix);
    void prepareToPlay();
    void setPlayheads();
    float process(float input);
    void resetDelay();
    
    
private :
    float m_fSampleRate;
    
    float m_fDelayInSamples;
    float m_fFeedback;
    float m_fWetLevel;
    
    float* m_pBuffer;
    int m_nReadIndex;
    int m_nDryIndex;
    int m_nWriteIndex;
    int m_nBufferSize;
    
    int m_nFuture1Index;
    int m_nFuture2Index;
    int m_nPast1Index;
    
    
};



#endif  // FOURPOINTDELAY_H_INCLUDED
