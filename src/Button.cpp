//Datei: Button.cpp
//Implementationsdatei für die Klasse Button
//Autor: Andri Andermatt, 15.03.2025
#include <Arduino.h>
#include <Button.h>


bool Button::getButtonPos()
{
    bool statePos;
    bool reading = butNature();

    if (trigLastTime != reading)
    {
        timeLastEdge = millis();
        trigEdgeTime = LOW;
    }

    if ((millis() - timeLastEdge > trigTime) && !trigEdgeTime)
    {
        if (reading)
        {
            statePos = true;
            trigEdgeTime = HIGH;
        } 
    } else
    {
        statePos = LOW;
    }

    trigLastTime = reading;

    return statePos;
}