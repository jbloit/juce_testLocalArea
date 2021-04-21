#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    
    addAndMakeVisible(myContainer);
    targetRect = juce::Rectangle<float>(50, 50);
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    
    juce::Path targetPath;
    g.setColour(juce::Colours::red);
    g.drawRoundedRectangle(targetRect, 2.f, 3.f);
}

void MainComponent::resized()
{

    auto area = getLocalBounds();
    
    DBG("MAIN LOCAL BOUNDS " << area.toString());
    
    auto containerArea = area.reduced(proportionOfWidth(0.2));
    myContainer.setBounds(containerArea);
    
    // THIS is the important line
    auto targetBounds = getLocalArea(&(myContainer.label), myContainer.label.getLocalBounds());
    
    
    
    targetRect = targetBounds.toFloat();
    
    DBG("TARGET BOUNDS " << targetBounds.toString());
    
}
