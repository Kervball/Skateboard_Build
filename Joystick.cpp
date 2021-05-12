#include "Joystick.h"
#include "Arduino.h"


Joystick::Joystick(int x_pin_param, float volt_out, int btn_pin_param){
  //establish all private variables
  x_pin = x_pin;
  x_value = 0;
  btn_pin = btn_pin_param;
  btn_value = 0;
  last_btn_value = 1;
  power = false;
  //set pins as correct status
  pinMode(x_pin, INPUT);
  pinMode(btn_pin, INPUT_PULLUP); 
  ////////////mid band calculations
  high_volt = 100*volt_out+100;
  low_volt = 100*volt_out-100;
}

int Joystick::DeclareSpeed()
{
    btn_value = digitalRead(btn_pin);
    x_value = analogRead(x_pin);
    //check location of stick
    if(x_value > high_volt){current_status = faster;}
    if(x_value < low_volt){current_status = slower;}
    if(x_value > low_volt && x_value < high_volt){current_status = steady;}
    
    //check to see if toggle is pressed
    if (btn_value != last_btn_value)
    {
      if(btn_value == 0)
      {
        last_btn_value = btn_value;
        return 3;
      }
    }
    last_btn_value = btn_value;
    return current_status;
}
