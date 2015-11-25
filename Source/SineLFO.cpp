/*
  ==============================================================================

    SineLFO.cpp
    Created: 19 Oct 2015 6:19:00pm
    Author:  Jacob Penn

  ==============================================================================
*/

#include "SineLFO.h"

SineLFO::SineLFO() : m_fPhase(0),
                     m_fFrequency(0),
                     m_fsampleRate(0)
{
    
}

SineLFO::~SineLFO(){}

void SineLFO::setPhase(float phase)
{
    m_fPhase = phase;
    if (m_fPhase < 0)
    {
        m_fPhase = 0;
    }
    if (m_fPhase > 1)
    {
        m_fPhase = m_fPhase - 1;
    }
}

void SineLFO::setSampleRate(float sampleRate)
{
    m_fsampleRate = sampleRate;
}

void SineLFO::setFrequency(float LFOFrequency)
{
    m_fFrequency = LFOFrequency;
}

float SineLFO::calcSineLFO(float centerValue, float modDepth)
{
    float LFOValue = centerValue + (modDepth*sin(2*M_PI*m_fPhase));
    m_fPhase = m_fPhase + (m_fFrequency/m_fsampleRate);
    if (m_fPhase > 1)
    {
        m_fPhase = m_fPhase - 1;
    }
    return LFOValue;
}