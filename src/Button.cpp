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
    if (digitalRead(pin) && !logging)
    {
        logging = true;
        startLogTime = millis();
    }

    if ((startLogTime + logTime) > millis())
    {
        posEdges += getPosEdge();
        negEdges += getNegEdge();
    } else if (logging)
    {
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
    } 
}

bool Button::getPosEdge()
{
    bool statePos;

    if (readingLastP != digitalRead(pin))
    {
        lastTriggerTimeP = millis();
        edgeResetP = true;
    }

    if ((millis() - lastTriggerTimeP > 50) && edgeResetP)
    {
        if (digitalRead(pin))
        {
            statePos = true;
            edgeResetP = false;
        }
    } else
    {
        statePos = false;
    }
    
    readingLastP = digitalRead(pin);

    return statePos;
}

bool Button::getNegEdge()
{
    bool stateNeg;

    if (readingLastN != digitalRead(pin))
    {
        lastTriggerTimeN = millis();
        edgeResetN = true;
    }

    if ((millis() - lastTriggerTimeN > 50) && edgeResetN)
    {
        if (!digitalRead(pin))
        {
            stateNeg = true;
            edgeResetN = false;
        }
    } else
    {
        stateNeg = false;
    }
    
    readingLastN = digitalRead(pin);

    return stateNeg; 
}