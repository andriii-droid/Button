//Datei: Button.cpp
//Implementationsdatei für die Klasse Button
//Autor: Andri Andermatt, 15.03.2025
#include <Arduino.h>
#include <Button.h>

Button::Button(int initPin)
    :pin{initPin}
{
    pinMode(pin, INPUT);
}

void Button::updateButton()
{
    if (startLog() && !logging)
    {
        logging = true;
        startLogTime = millis();
    }

    if ((startLogTime + logTime) > millis())
    {
        /* logging */
    } else if (logging)
    {
        /* Auswertung */
    }
    
    
    
}

bool Button::startLog()
{
    return digitalRead(pin);
}

bool Button::getPosEdge()
{
    
}

bool Button::getNegEdge()
{
    
}