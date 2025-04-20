//Datei: Button.h
//Headerdatei für die Klasse Button
//Autor: Andri Andermatt, 15.03.2025
#include <Arduino.h>

#ifndef BUTTON_H_
#define BUTTON_H_
    class Button
    {
        public:
            enum edgeType {negative, positive, toggle, timePos, timeNeg, doubleTap}; 
            //enum for diffrent Trigger types 

            explicit Button(int initPin, edgeType initEdge); 
            //Inititialises the Button, 
            //pin: Pin Number of Button
            //trigger: Defines behaovior of state. 
            //Possible Values: nature negative, positive, toggle, time, double
            //initTrigTime: Time if edgeType == timeTap; default is 2000
      
            bool getState() const { return state;}
            //Gets current State of the Button

            bool getNature() const {return butNature(); }
            //Gets nature State of the Button

            edgeType getTrigger() const {return edge;}
            //Gets the Trigger Type of the Button

            void updateButton();
            //Updates the State of the Button 
            //needs to be run once per Loop.
            //Preferably at the Start of every Loop
            //After all updateButton() Functions it is Recommended to put a delay(5) to avoid bouncing

        private:
            bool state = LOW;
            bool stateNeg = LOW; //State of Button
            bool statePos = LOW; //State of Button
            long timeLestPress = 0;  //Timestamp of Last Press

            struct statesStruct
            {
                bool negative = 0;
                bool positive = 0;
                bool timePos = 0;
                bool timeNeg = 0;
                bool toggle = 0;
                bool doubleTap = 0;
            };

            statesStruct outState;

            edgeType edge; //Defines how state is set
            int pin; //Pin of the Button

            bool trigLastPos = LOW; //Helper for Triggers

            bool trigLastNeg = HIGH; //Helper for Triggers

            bool trigToggle = LOW; //Helper for Toggle

            long trigTime;  //Time that Button needs to be pressed
            long timeLastEdge = 0;  //Timestamp of Last Edge
            bool trigLastTime = LOW; //Helper for Time Trigger
            bool trigEdgeTime = LOW; //Helper for Time Trigger

            int counter = 0; //Counter for double Tap
            int doubleDelay = 0;

            bool butNature() const {return digitalRead(pin);}
            //Gets Button State Nature

            bool getButtonPos();

            bool getButtonNeg();


            bool getDouble();
            //Gets Double Tap state




    };
#endif //BUTTON_H_