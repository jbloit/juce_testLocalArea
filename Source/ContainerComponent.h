/*
  ==============================================================================

    ContainerComponent.h
    Created: 21 Apr 2021 4:03:12pm
    Author:  Julien Bloit

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ContainerComponent  : public juce::Component
{
public:
    ContainerComponent()
    {
        label.setText("label", juce::dontSendNotification);
        addAndMakeVisible(label);
    }

    ~ContainerComponent() override
    {
    }

    void paint (juce::Graphics& g) override
    {

        g.setColour (juce::Colours::grey);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    }

    void resized() override
    {

        auto area = getLocalBounds();
        DBG("CONTAINER LOCAL BOUNDS " << area.toString());
        
        auto labelBounds = area.reduced(proportionOfWidth(0.2));
        label.setBounds(labelBounds);
    }

    juce::Label label;
private:
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ContainerComponent)
};
