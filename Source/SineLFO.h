/*
  ==============================================================================

    SineLFO.h
    Created: 19 Oct 2015 6:19:00pm
    Author:  Jacob Penn

  ==============================================================================
*/

#ifndef SINELFO_H_INCLUDED
#define SINELFO_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SineLFO
{
public:
    SineLFO();
    ~SineLFO();
    void setPhase(float phase);
    void setFrequency(float LFOFrequency);
    void setSampleRate(float sampleRate);
    float calcSineLFO(float centerValue, float modDepth);
private:
    float m_fPhase;
    float m_fFrequency;
    float m_fsampleRate;
};




#endif  // SINELFO_H_INCLUDED
