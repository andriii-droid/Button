//Datei: Button.h
//Headerdatei für die Klasse Button
//Autor: Andri Andermatt, 15.03.2025
#include <Arduino.h>

#ifndef BUTTON_H_
#define BUTTON_H_
    class Button
    {
        public:
            enum outputState {none, time, twice, trice, click, error};

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
            unsigned long logTime = 1000; //Time the Button has to log Edges in ms
            unsigned long startLogTime = 0; //Time the logging Cycle startet in ms
            bool logging = false; //True if Button is currently logging

            int posEdges = 0; //Number of positive Edges during Log Time
            int negEdges = 0; //Number of negative Edges during Log Time

            //getPosEdge
            bool readingLastP = false; //Last State of Reading
            bool edgeResetP = false; //Helper to ensure that only one positive cycle exists
            unsigned long lastTriggerTimeP = 0; //Time Edge was last triggered

            //getNegEdge
            bool readingLastN = false; //Last State of Reading
            bool edgeResetN = false; //Helper to ensure that only one positive cycle exists
            unsigned long lastTriggerTimeN = 0; //Time Edge was last triggered

            bool startLog();
            //Returns true if Button gets pressed

            bool getPosEdge();
            //Returns true, if positive Edge is detected

            bool getNegEdge();
            //Returns true, if negative Edge is detected
    };
#endif //BUTTON_H_