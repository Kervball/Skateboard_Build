#ifndef Joystick_h
    #define Joystick_h

    #include "Arduino.h"
    class Joystick
    {
        public:
            //9 appple charger block
            //7.5 computer
            Joystick(int, float, int);
            enum speed { steady, faster, slower,mottor_toggle};
            int DeclareSpeed();
            speed current_status;
            int GetHighVolt(){ return high_volt;}
            
        private:
            int x_pin;
            int x_value;
            int btn_pin;
            int btn_value;
            int last_btn_value;
            bool power;
            int high_volt;
            int low_volt;
    };
#endif
