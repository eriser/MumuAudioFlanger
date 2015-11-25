/*
  ==============================================================================

    TriLFO.cpp
    Created: 17 Nov 2015 10:16:51pm
    Author:  Jacob Penn

  ==============================================================================
*/

#include "TriLFO.h"

TriLFO::TriLFO() : m_fPhase(0),
m_fFrequency(0),
m_fsampleRate(0)
{
    
}

TriLFO::~TriLFO(){}

void TriLFO::setPhase(float phase)
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

void TriLFO::setSampleRate(float sampleRate)
{
    m_fsampleRate = sampleRate;
}

void TriLFO::setFrequency(float LFOFrequency)
{
    m_fFrequency = LFOFrequency;
}

float TriLFO::calcTriLFO(float centerValue, float modDepth)
{
    float LFOValue = centerValue + modDepth * (std::abs(m_fPhase * 4 - 2) * -1 + 1);
    m_fPhase = m_fPhase + (m_fFrequency/m_fsampleRate);
    if (m_fPhase > 1)
    {
        m_fPhase = m_fPhase - 1;
    }
    return LFOValue;
}