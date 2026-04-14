//Datei: Button.h
//Headerdatei für die Klasse Button
//Autor: Andri Andermatt, 15.03.2025
#include <Arduino.h>
#include <vector>

#ifndef BUTTON_H_
#define BUTTON_H_
    class Button
    {
        public:
            enum outputState {none, time, twice, trice, click, error};

            explicit Button(int initPin); 
            //Inititialises the Button, 
            //pin: Pin Number of Button
           
            bool getState(outputState wantedState) const; 
            //Returns true if wantedState and actual state are the same

            void static inline updateAll();

            void updateButton();
            //Updates the State of the Button 
            //needs to be run once per Loop.
            //Preferably at the Start of every Loop

            ~Button();

        private:
            int pin; //Pin Number

            outputState state = none; //State of the Button

            //updateAll
            std::vector<Button*> static buttons; 

            //updateButton()
            enum loggingProcess {start, log, evaluate, reset};
            loggingProcess logButton = start;
            unsigned long logTime = 1000; //Time the Button has to log Edges in ms
            unsigned long startLogTime = 0; //Time the logging Cycle startet in ms

            int posEdges = 0; //Number of positive Edges during Log Time
            int negEdges = 0; //Number of negative Edges during Log Time

            //getPosEdge()
            bool readingLastP = false; //Last State of Reading
            bool edgeResetP = false; //Helper to ensure that only one positive cycle exists
            unsigned long lastTriggerTimeP = 0; //Time Edge was last triggered

            //getNegEdge()
            bool readingLastN = false; //Last State of Reading
            bool edgeResetN = false; //Helper to ensure that only one positive cycle exists
            unsigned long lastTriggerTimeN = 0; //Time Edge was last triggered

            int getPosEdge();
            //Returns true, if positive Edge is detected

            bool getNegEdge();
            //Returns true, if negative Edge is detected
    };
#endif //BUTTON_H_