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

}

bool Button::startLog()
{

}

bool Button::getPosEdge()
{
    
}

bool Button::getNegEdge()
{
    
}