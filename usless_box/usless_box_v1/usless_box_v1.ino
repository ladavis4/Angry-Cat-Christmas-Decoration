#include <Servo.h>


Servo arm_servo;
Servo lid_servo;

int switch_pin = A5;
int switch_voltage = 0;  // variable to store the value read

//Constans for servo positions
int arm_pos1 = 180;
int arm_pos2 = 95;
int lid_pos1 = 100;
int lid_pos2 = 160;


int servo1_pos;  // desired angle for servo1
int servo2_pos;  // desired angle for servo2

int selected_move = 0;
void setup()
{
  Serial.begin(9600);           //  setup serial
  arm_servo.attach(9);           //set door servo on Pin 9 pwm
  lid_servo.attach(3);          //set finger servo on Pin 10 pwm


  arm_servo.write(arm_pos1);           //set door to hiding position
  lid_servo.write(lid_pos1);            //set finger to hiding position
}

void loop() {
  switch_voltage = analogRead(switch_pin);
  Serial.println(switch_voltage);          // debug value

  //if the switch is on, move door and finger to switch it off
  if (switch_voltage < 500)
  {
    if(selected_move > 2){
      selected_move = 0;  //Loop through every possible move 
    }
  
    if (selected_move == 0) {    ///Move Selection 
      simpleClose();
    }
    else if (selected_move == 1) {
      simpleClose();
    }
    else if (selected_move == 2) {
      simpleClose();
    }
    selected_move += 1;         //swith to next move
  }
}

/////////////MOVES////////////////////////////////////////
// basic move
void simpleClose()
{
  lid_servo.write(lid_pos2);
  delay(1500);
  arm_servo.write(arm_pos2);
  delay(2000);
  arm_servo.write(arm_pos1);
  delay(1000);
  lid_servo.write(lid_pos1);
    
}

//Movement Function 


/*
static unsigned long servo_time;

// check time since last servo position update
if ((millis() - servo_time) >= SERVO_SPEED) {
  servo_time = millis(); // save time reference for next position update

  // update servo1 position
  // if desired position is different from current position move one step left or right
  if (servo1_pos > servo1.read()) servo1.write(servo1.read() + 1);
  else if (servo1_pos < servo1.read()) servo1.write(servo1.read() - 1);

  // update servo2 position
  // if desired position is different from current position move one step left or right
  if (servo2_pos > servo2.read()) servo2.write(servo2.read() + 1);
  else if (servo2_pos < servo2.read()) servo2.write(servo2.read() - 1);
}
*/
