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

bool Button::getState(outputState wantedState) const
{
    if (wantedState == state)
    {
        return true;
    } else
    {
        return false;
    }
}

void Button::updateButton()
{
    switch (logButton)
    {
    case start:
        if (digitalRead(pin))
        {
            startLogTime = millis();

            logButton = log;
        }

        break;
    case log:
        posEdges += getPosEdge();
        negEdges += getNegEdge();

        if ((startLogTime + logTime) < millis())
        {
            logButton = evaluate;
        }
        break;
    case evaluate:
        if (posEdges > negEdges)
        {
        state = time;
        } else if (posEdges == negEdges)
        {
            switch (posEdges)
            {
            case 1:
                state = click;
                break;
            case 2:
                state = twice;
                break;
            case 3:
                state = trice;
                break;
            }
        }

        logButton = reset;
        break;
    case reset:
        state = none;
        posEdges = 0;
        negEdges = 0;

        logButton = start;
        break;
    }
}

int Button::getPosEdge()
{
    bool statePos = false;
    bool reading = digitalRead(pin);

    if (readingLastP != reading)
    {
        lastTriggerTimeP = millis();
        edgeResetP = true;
    }

    if ((millis() - lastTriggerTimeP > 50) && edgeResetP)
    {
        if (reading)
        {
            statePos = true;
            edgeResetP = false;
        }
    } else
    {
        statePos = false;
    }
    
    readingLastP = reading;
    return statePos;
}

bool Button::getNegEdge()
{
    bool stateNeg = false;
    bool reading = digitalRead(pin);

    if (readingLastN != reading)
    {
        lastTriggerTimeN = millis();
        edgeResetN = true;
    }

    if ((millis() - lastTriggerTimeN > 50) && edgeResetN)
    {
        if (!reading)
        {
            stateNeg = true;
            edgeResetN = false;
        }
    } else
    {
        stateNeg = false;
    }
    
    readingLastN = reading;

    return stateNeg; 
}