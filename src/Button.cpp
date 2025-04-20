//Datei: Button.cpp
//Implementationsdatei für die Klasse Button
//Autor: Andri Andermatt, 15.03.2025
#include <Arduino.h>
#include <Button.h>

Button::Button(int initPin, edgeType initEdge)
    :pin{initPin}, edge{initEdge}
{
    pinMode(pin, INPUT);

    if (edge == (timeNeg || timePos))
    {
        trigTime = 2000;
    } else
    {
        trigTime = 10;
    }
    

}

void Button::updateButton()
{
    static bool test = 0;

    if (digitalRead(pin) && timeLestPress + 2010 < millis())
    {
        timeLestPress = millis();
        Serial.println("start");
        //outState.positive = true;
        test = 1;
    } else if (timeLestPress + 2010 > millis())
    {    
        if (getButtonPos())
        {
            if (trigTime == 2000)
            {
                outState.timePos = true;
            } else
            {
                outState.positive = true;
            }
        }

        if (getButtonNeg())
        {
            if (trigTime == 2000)
            {
                outState.timeNeg = true;
            } else
            {
                outState.negative = true;
            }
        }

        if (getDouble())
        {
            outState.doubleTap = true;
        }
    } else if (test)
    {
        Serial.print("pos ");
        Serial.println(outState.positive);
        Serial.print("neg ");
        Serial.println(outState.negative);
        Serial.print("timepos ");
        Serial.println(outState.timePos);
        Serial.print("timeneg ");
        Serial.println(outState.timeNeg);
        Serial.print("double ");
        Serial.println(outState.doubleTap);
        test = 0;
    }
    
   
}

bool Button::getButtonPos()
{
    statePos;
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

bool Button::getButtonNeg()
{
    stateNeg;
    bool reading = butNature();

    if (trigLastTime != !reading)
    {
        timeLastEdge = millis();
        trigEdgeTime = LOW;
    }

    if ((millis() - timeLastEdge > trigTime) && !trigEdgeTime)
    {
        if (!reading)
        {
            stateNeg = true;
            trigEdgeTime = HIGH;
        } 
    } else
    {
        stateNeg = LOW;
    }

    trigLastTime = reading;

    return stateNeg;
}

bool Button::getDouble()
{
    bool flag = LOW;
    if (statePos)
    {
        ++counter;
        if (counter == 1)
        {
            doubleDelay = millis();
        }
    }

    if ((doubleDelay + 500 < millis()) && counter == 1)
    {
        counter = 0;
    }

    if (counter == 2)
    {
        counter = 0;
        flag = HIGH;
    }
    
    return flag;
}