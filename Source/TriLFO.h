/*
  ==============================================================================

    TriLFO.h
    Created: 17 Nov 2015 10:16:51pm
    Author:  Jacob Penn

  ==============================================================================
*/

#ifndef TRILFO_H_INCLUDED
#define TRILFO_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class TriLFO
{
public:
    TriLFO();
    ~TriLFO();
    void setPhase(float phase);
    void setFrequency(float LFOFrequency);
    void setSampleRate(float sampleRate);
    float calcTriLFO(float centerValue, float modDepth);
private:
    float m_fPhase;
    float m_fFrequency;
    float m_fsampleRate;
};




#endif  // TRILFO_H_INCLUDED
