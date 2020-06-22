#include <Servo.h>
Servo lid_servo;  // create servo object to control a servo
Servo arm_servo;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int switch_pin = A5; // potentiometer wiper (middle terminal) connected to analog pin 3              // outside leads to ground and +5V
int switch_voltage = 0;  // variable to store the value read

float arm_pos1 = 180;
int arm_pos2 = 85;
int lid_pos1 = 122;
int lid_pos2 = 170;

int move_number = 0; //Keeps track of the number of movements completed by the box since turning on

void setup() {
  Serial.begin(9600);           //  setup serial
  arm_servo.attach(9);
  lid_servo.attach(3);

  arm_servo.write(arm_pos1);           //set door to hiding position
  lid_servo.write(lid_pos1);
}

void loop() {
  switch_voltage = analogRead(switch_pin);  // read the input pin
  Serial.println(switch_voltage);

  //Delcare movements


  if (switch_voltage < 500 ) {
    pick_movement();
  } else {
    lid_servo.write(lid_pos1);
    arm_servo.write(arm_pos1);
  }
}








void pick_movement() {
  //slow speed = .1
  //normal speed = .5
  //max speed = 3
  //
  if (move_number > 7 ) {
    move_number = 0;  //Loop through every possible move
  }
  
  //Move selection
  if (move_number == 0) {
    //Basic opening 
    int steps = 5;   
    float lid_des_pos_a[steps] = {lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos1};
    float lid_des_speed_a[steps] = {.5, .01, .01, .01, 1};
    float arm_des_pos_a[steps] = {arm_pos1, arm_pos2, arm_pos2, arm_pos1, arm_pos1};
    float arm_des_speed_a[steps] = {.01, .8, .01, .8, .01};
    float delay_a[steps] = {0, 0, 1, 0, 0};
    delay(2000);
    servo_movements(lid_des_pos_a, lid_des_speed_a, arm_des_pos_a, arm_des_speed_a, delay_a, steps);
  }
  else if (move_number == 1) {
    //Open lid, close lid, open lid, hit fast close
    int steps = 9;   
    float lid_des_pos_a[steps] = {lid_pos2, lid_pos2, lid_pos1, lid_pos1, lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos1};
    float lid_des_speed_a[steps] = {5, .01, 5, .01, 5, .01, .01, .01, 5};
    float arm_des_pos_a[steps] = {arm_pos1, arm_pos1, arm_pos1, arm_pos1, arm_pos1, arm_pos2, arm_pos2, arm_pos1, arm_pos1};
    float arm_des_speed_a[steps] = {.01, .01, .01, .01, .01, 3, 0, 3, .01};
    float delay_a[steps] = {0, 1, 0, 1.5, 0, 0, .25, 0, 0};
    servo_movements(lid_des_pos_a, lid_des_speed_a, arm_des_pos_a, arm_des_speed_a, delay_a, steps);
  }
  else if (move_number == 2) {
    //Open lid slow, move arm slow, close normal
    int steps = 5;   
    float lid_des_pos_a[steps] = {lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos1};
    float lid_des_speed_a[steps] = {.1, .01, .01, .01, .5};
    float arm_des_pos_a[steps] = {arm_pos1, arm_pos2, arm_pos2, arm_pos1, arm_pos1};
    float arm_des_speed_a[steps] = {.01, .1, .01, .5, .01};
    float delay_a[steps] = {0, 0, 5, 0, 0};
    servo_movements(lid_des_pos_a, lid_des_speed_a, arm_des_pos_a, arm_des_speed_a, delay_a, steps);
  }
 else if (move_number == 3) {
    //Immediate open hit fast close
    int steps = 9;   
    float lid_des_pos_a[steps] = {lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos1, lid_pos1, lid_pos2, lid_pos2, lid_pos1};
    float lid_des_speed_a[steps] = {3, .01, .01, .01, 3, .01, 3, .01, 3};
    float arm_des_pos_a[steps] = {arm_pos1, arm_pos2, arm_pos2, arm_pos1, arm_pos1, arm_pos1, arm_pos1, arm_pos1, arm_pos1};
    float arm_des_speed_a[steps] = {.01, 3, .01, 3, .01, .01, .01, .01, .01};
    float delay_a[steps] = {0, 0, .35, 0, 0, 2.5, 0, 3, 0};
    servo_movements(lid_des_pos_a, lid_des_speed_a, arm_des_pos_a, arm_des_speed_a, delay_a, steps);
  }

  else if (move_number == 4) {
    //2 fake hits
    int arm_pos3 = arm_pos2 + 15; 
    int steps = 9;   
    float lid_des_pos_a[steps] = {lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos1};
    float lid_des_speed_a[steps] = {3, .01, .01, .01, .01, .01, .01, .01, .5};
    float arm_des_pos_a[steps] = {arm_pos1, arm_pos3, arm_pos1, arm_pos3, arm_pos1, arm_pos2, arm_pos2, arm_pos1, arm_pos1};
    float arm_des_speed_a[steps] = {.01, 2, .2, 2, .2, 2, .01, 1, .01};
    float delay_a[steps] = {0, 0, 0, 0, 0, 0, .75, 0, 0};
    delay(2000);
    servo_movements(lid_des_pos_a, lid_des_speed_a, arm_des_pos_a, arm_des_speed_a, delay_a, steps);
  }
  else if (move_number == 5) {
    //lid bounces then arm hits
    int lid_pos3 = lid_pos1 + 20; 
    int steps = 15;   
    float lid_des_pos_a[steps] = {lid_pos3, lid_pos1, lid_pos3, lid_pos1, lid_pos3, lid_pos1,lid_pos3, lid_pos1, lid_pos3, lid_pos1, lid_pos1, lid_pos2, lid_pos2, lid_pos2, lid_pos1};
    float lid_des_speed_a[steps] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, .01, 2, .01, .01, 2};
    float arm_des_pos_a[steps] = {arm_pos1, arm_pos1, arm_pos1, arm_pos1,arm_pos1, arm_pos1,arm_pos1, arm_pos1,arm_pos1, arm_pos1,arm_pos1, arm_pos2, arm_pos2, arm_pos1, arm_pos1};
    float arm_des_speed_a[steps] = {.01, .01,.01, .01,.01, .01,.01, .01,.01, .01, .01, 1.2, .01, 1.2, .01};
    float delay_a[steps] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 0, 0};
    delay(2000);
    servo_movements(lid_des_pos_a, lid_des_speed_a, arm_des_pos_a, arm_des_speed_a, delay_a, steps);
  }
  else if (move_number == 6){
    //Hold switch lid hits the arm
    int steps = 14;   
    float lid_des_pos_a[steps] = {lid_pos2, lid_pos2, lid_pos2, lid_pos1, lid_pos2, lid_pos1, lid_pos2, lid_pos1, lid_pos2, lid_pos1, lid_pos2, lid_pos1, lid_pos2, lid_pos1};
    float lid_des_speed_a[steps] = {5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2};
    float arm_des_pos_a[steps] = {arm_pos1, arm_pos2, arm_pos2, arm_pos2, arm_pos2, arm_pos2, arm_pos2, arm_pos2, arm_pos2, arm_pos2, arm_pos2, arm_pos2, arm_pos1, arm_pos1};
    float arm_des_speed_a[steps] = {.01, 2,.01, .01,.01, .01,.01, .01,.01, .01, 1.2, .01, 2, .01};
    float delay_a[steps] = {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
    delay(2000);
    servo_movements(lid_des_pos_a, lid_des_speed_a, arm_des_pos_a, arm_des_speed_a, delay_a, steps); 
  }

  else if (move_number == 7){
    //Open small, close, open small, close, open full hit fast]
    int lid_pos3 = 155;
    int steps = 13;   
    float lid_des_pos_a[steps] = {lid_pos3, lid_pos3, lid_pos1, lid_pos1,  lid_pos3, lid_pos3, lid_pos1, lid_pos1, lid_pos2, lid_pos2, lid_pos2, lid_pos2, lid_pos1};
    float lid_des_speed_a[steps] = {.5,       .01,      .5,      .1,         .5,     .01,       .5,     .05,        5,      .05,       .05,          .05,      5};
    float arm_des_pos_a[steps] = {arm_pos1, arm_pos1, arm_pos1,  arm_pos1, arm_pos1, arm_pos1, arm_pos1, arm_pos1, arm_pos1, arm_pos2, arm_pos2, arm_pos1, arm_pos1};
    float arm_des_speed_a[steps] = {.01,    .01,        .01,    .01,         .01,      .01,     .01,       .01,      .01,     2,     .1,          2,    .01};
    float delay_a[steps] = {0, 1.5, 0, 1.5, 0, 1.5, 0, 2, 0, 0, .3, 0, 0};
    delay(2000);
    servo_movements(lid_des_pos_a, lid_des_speed_a, arm_des_pos_a, arm_des_speed_a, delay_a, steps);
    
  }



  
  move_number += 1;         //swith to next move
}













void servo_movements(float lid_des_pos_a[], float lid_des_speed_a[], float arm_des_pos_a[], float arm_des_speed_a[], float delay_a[], int steps) {
  for (int i = 0; i < steps; i++) {
    //Declare desired positions for the first step
    float lid_des_pos = lid_des_pos_a[i];
    float lid_des_speed = lid_des_speed_a[i];
    float arm_des_pos = arm_des_pos_a[i];
    float arm_des_speed = arm_des_speed_a[i];
    float cur_delay = delay_a[i];

    if (cur_delay != 0) {
      delay(cur_delay * 1000);
    } else {
      float arm_dir = 1;
      float lid_dir = 1;

      int done_arm = 0;
      int done_lid = 0;

      float arm_cur_pos = arm_servo.read();
      float lid_cur_pos = lid_servo.read();

      if (lid_des_pos - lid_cur_pos < 0) {
        lid_dir = -1;
      } else {
        lid_dir = 1;
      }
      if (arm_des_pos - arm_cur_pos < 0) {
        arm_dir = -1;
      } else {
        arm_dir = 1;
      }

      while (done_arm == 0 || done_lid == 0) {
        if ((lid_des_pos - lid_cur_pos) > 2 || (lid_des_pos - lid_cur_pos) < -2) {
          lid_cur_pos = lid_cur_pos + lid_des_speed * lid_dir;
          lid_servo.write(lid_cur_pos);
        } else {
          done_lid = 1;
        }

        if ((arm_des_pos - arm_cur_pos) > 2 || (arm_des_pos - arm_cur_pos) < -2) {
          arm_cur_pos = arm_cur_pos + arm_des_speed * arm_dir;
          arm_servo.write(arm_cur_pos);
        } else {
          done_arm = 1;
        }
        delay(10);
      }
    }
  }
}
