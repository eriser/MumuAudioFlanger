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
        //g.fillAll (Colour(uint8(30),uint8(30),uint8(30),float(1)));
        g.fillAll (Colour(uint8(0),uint8(0),uint8(0),float(1)));
        const float midY = getHeight() * 0.5f;
        g.setColour (Colour(uint8(115),uint8(255),uint8(255),float(1)));
        //vertical cutoff line
        g.drawLine(crossFreq, 0, crossFreq, getHeight());
        //Horiztonal Line
        g.drawLine(0,midY,getWidth(),midY);
        //Box Outline
        g.setColour (Colour(uint8(255),uint8(255),uint8(255),float(1)));
        g.drawLine(0, 0, getWidth(), 0);
        g.drawLine(0, getHeight(), getWidth(), getHeight());
        g.drawLine(0, 0, 0, getHeight());
        g.drawLine(getWidth(), 0, getWidth(), getHeight());
    }
//    void mouseDown(MouseEvent e)
//    {
//        crossFreq = e.x;
//        std::cout << crossFreq << std::endl;
//    }
};

#endif  // CROSSOVERCOMPONENT_H_INCLUDED
