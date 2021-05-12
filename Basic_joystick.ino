#include "Joystick.h"

Joystick Remote_joystick(0,5,7);
int btn_value;
int joystick_value;
int current_speed;
bool mottor_on;
int Max_Speed;
enum speed { steady, faster, slower,mottor_toggle};


void setup() {
  Serial.begin(9600);
  int btn_value = 1;
  int joystick_value = Remote_joystick.GetHighVolt();
  Max_Speed = 1000;
  current_speed = 0;
}

void loop() { 
  //switch statement handling speeding up slowing down and mottot shut off
  //Remote_joystick.DeclareSpeed()
  switch(Remote_joystick.DeclareSpeed())
  {
    case faster:   //faster
      if(mottor_on)
      {
        if(current_speed < Max_Speed){current_speed += 10;}
      }
    break;
    
    case slower:   //slower    
      if(mottor_on)
      {
      if(current_speed > 0){current_speed -= 10;}
      }
    break;
    
    case mottor_toggle:   //mottor on/off
      mottor_on = !mottor_on;
      current_speed = 0;
    break;
        
    default: //no change in speed
    break;
  }

  Serial.print(Remote_joystick.DeclareSpeed());
  Serial.print("  ");
  Serial.print("current speed:  ");
  Serial.print(current_speed);

  Serial.print("  mottor power  ");
  Serial.println(mottor_on);
}
