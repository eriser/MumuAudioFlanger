/*
  ==============================================================================

    CrossoverComponent.h
    Created: 23 Nov 2015 12:07:35pm
    Author:  Jacob Penn

  ==============================================================================
*/

#ifndef CROSSOVERCOMPONENT_H_INCLUDED
#define CROSSOVERCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class CrossoverComponent  : public Component
{
public:
    CrossoverComponent()
    {
        setOpaque(true);
    }
    
    void setCrossoverFreq(float frequency)
    {
        crossFreq = frequency;
        repaint();
    }
    
    
private:
    float crossFreq;
    
    void paint (Graphics& g) override
    {
        Path lowPass;
        Path highPass;
        //g.fillAll (Colour(uint8(30),uint8(30),uint8(30),float(1)));
        g.fillAll (Colour(uint8(30),uint8(30),uint8(30),float(1)));
        const float midY = getHeight() * 0.5f;
        g.setColour (Colour(uint8(115),uint8(255),uint8(255),float(1)));
        //vertical cutoff line
        //Lowpass
        lowPass.startNewSubPath(0, midY);
        lowPass.quadraticTo(crossFreq-5, midY, crossFreq, getHeight());
        g.strokePath(lowPass, PathStrokeType(1.5f));
        //Highpass
        highPass.startNewSubPath(getWidth(), midY);
        highPass.quadraticTo(crossFreq+5, midY, crossFreq, getHeight());
        g.strokePath(highPass, PathStrokeType(1.5f));
        //Horiztonal Line
        //g.drawLine(0,midY,getWidth(),midY);
        //Box Outline
        g.setColour (Colour(uint8(255),uint8(255),uint8(255),float(1)));
        g.drawLine(0, 0, getWidth(), 0);
        g.drawLine(0, getHeight(), getWidth(), getHeight());
        g.drawLine(0, 0, 0, getHeight());
        g.drawLine(getWidth(), 0, getWidth(), getHeight());
    }
};

#endif  // CROSSOVERCOMPONENT_H_INCLUDED
