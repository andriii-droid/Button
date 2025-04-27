//Datei: Button.h
//Headerdatei für die Klasse Button
//Autor: Andri Andermatt, 15.03.2025
#include <Arduino.h>

#ifndef BUTTON_H_
#define BUTTON_H_
    class Button
    {
        public:
            enum outputState {none, time, twice, click, error};

            explicit Button(int initPin); 
            //Inititialises the Button, 
            //pin: Pin Number of Button
           
            outputState getState() const {return state;}
            //Gets current State of the Button

            void updateButton();
            //Updates the State of the Button 
            //needs to be run once per Loop.
            //Preferably at the Start of every Loop

        private:
            int pin; //Pin Number

            outputState state = none; //State of the Button
            int logTime = 1000; //Time the Button has to log Edges in ms
            int posEdges = 0; //Number of positive Edges during Log Time
            int negEdges = 0; //Number of negative Edges during Log Time

            bool startLog();
            //Returns true if Button gets pressed

            bool getPosEdge();
            //Returns true, if positive Edge is detected

            bool getNegEdge();
            //Returns true, if negative Edge is detected
    };
#endif //BUTTON_H_