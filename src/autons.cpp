#include "main.h"
#include "headers.hpp"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/117 (around 87% of max speed).  We don't suggest making this 117.
                             // If this is 117 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 60, 62.5, 225, 187.5, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-11, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-11, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(11);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-11, 117);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .

// void not_roller_side() {



//   flywheel.move_voltage(11125);

//   pros::delay(2500);

//   indexerSingle.set_value(true);
//   pros::delay(10);
//   indexerSingle.set_value(false);
//   pros::delay(1000);
//   indexerSingle.set_value(true);
//   pros::delay(10);
//   indexerSingle.set_value(false);
//   pros::delay(1000);

//   flywheel.move_voltage(0);
// }

// void not_roller_side() { // normal auton but for if you start on the side thats to the left of the roller
//   // what this does is
//   // 1. get roller (should be started FACING the roller)

//   chassis.set_drive_pid(10, 70);
//   chassis.wait_drive();
//   chassis.set_turn_pid(90.0, 100);
//   chassis.wait_drive();
  
//   intake.move_voltage(12000); // do rollers
//   chassis.set_drive_pid(3, 100); // move forward while intaking to keep contact with rollers
//   pros::delay(500);
//   intake.brake();
//   chassis.wait_drive();
//   chassis.set_drive_pid(-3.5,110);
//   chassis.wait_drive();
//   chassis.set_turn_pid(-10, -50);
//   chassis.wait_drive();
//   chassis.left_motors[0].brake();
//   chassis.left_motors[1].brake();
//   chassis.right_motors[0].brake();
//   chassis.right_motors[1].brake();

//   pros::delay(500);

//   intake.brake();
// ; // not sure if the robot will get stuck moving into the roller, so this is to hopefully stop the drivetrain
// }

void roller_side_single() { // normal auton but with single indexer
  // what this does is
  // 1. get roller (should be started right in front of roller)
  // 2. go to center
  // 3. shoot disks with single indexer
  //
  // should have one disk in storage and the other in intake            
  flywheel.move_voltage(11950);

  intake.move_voltage(-10750); // do roller 1
  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(415);

  intake.brake();
  chassis.wait_drive();

  // flywheel.move_voltage(11000);

  chassis.set_drive_pid(-3.5, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(-9, 60);
  chassis.wait_drive();
  chassis.left_motors[0].brake();
  chassis.left_motors[1].brake();
  chassis.right_motors[0].brake();
  chassis.right_motors[1].brake();

 //flywheel.move_voltage(10990); //11020

  pros::delay(900);

  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1200);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);

  flywheel.brake();

  chassis.set_turn_pid(-129.5, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(12, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(11.25, 30);
  intake.move_voltage(12000);
  chassis.wait_drive();

  pros::delay(520);

  flywheel.move_voltage(11350);

  pros::delay(900);

  chassis.set_turn_pid(-40, 120);
  chassis.wait_drive();

  pros::delay(1100);
  
  // flywheel.move_voltage(10650); //10875

  // pros::delay(2450);

  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1200);

  intake.move_voltage(-12000);

  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1200); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(100);

  // scuffed

  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);

  flywheel.brake();

  intake.brake();
}

void test_skills() { // programmers skills but the test version
  // what this does is
  // 1. get roller (should be started right in front of roller)
  // 2. shoot two disks INDIVIDUALLY
  // 3. get second roller
  // 4. move to center while picking up disks
  // 5. shoot picked up disks
  // 6. get line of disks to the front left of robot
  // 7. shoot picked up disks
  // 8. get line of disks on the other side
  // 9. shoot picked up disks
  // 10. head to other two rollers while picking up disks
  // 11. shoot disks
  // 12. get other two rollers
  // 13. expand

  // Step 1: get roller

  intake.move_voltage(10000); // do roller 1
  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  // Step 2: shoot two disks

  chassis.set_drive_pid(-4, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(-8.5, 25);
  chassis.wait_drive();

  flywheel.move_voltage(11125);

  pros::delay(2500);

  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);

  flywheel.move_voltage(0);

  pros::delay(100);

  // Step 3: get second roller

  intake.move_voltage(12000);

  chassis.set_turn_pid(90, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(5, 100);
  chassis.wait_drive();
  pros::delay(500);
  chassis.set_turn_pid(45, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(5, 100);
  chassis.wait_drive();
  pros::delay(500);
  chassis.set_drive_pid(-5, 100);
  chassis.wait_drive();
  chassis.set_turn_pid(90, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(5, 100);

  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  chassis.set_drive_pid(-2, 80);
  chassis.wait_drive();
  chassis.set_turn_pid(-8.5, 70);
  chassis.wait_drive();

  flywheel.move_voltage(11100);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);

  // Step 4: move to center while picking up disks

  chassis.set_turn_pid(90, 80);
  chassis.set_drive_pid(-5.25, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(225, 90);
  chassis.wait_drive();
  
  intake.move_voltage(12000);

  chassis.set_drive_pid(9, 85);
  chassis.wait_drive();
  pros::delay(1000);
  chassis.set_turn_pid(345, 80);
  chassis.wait_drive();

  flywheel.move_voltage(11100);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);

  chassis.set_turn_pid(320, 90);
  chassis.wait_drive();
  chassis.set_drive_pid(1, 85);
  chassis.wait_drive();

  pros::delay(1200);
  
  intake.brake();

  // Step 5: shoot picked up disks

  flywheel.move_voltage(9500);
  pros::delay(1500);

  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);

  // Step 6: get line of disks to the front left of robot

  chassis.set_turn_pid(135, 60);
  chassis.wait_drive();
  intake.move_voltage(12000);
  chassis.set_drive_pid(9, 110);
  chassis.wait_drive();
  pros::delay(1000);
  chassis.set_turn_pid(45, 60);
  chassis.wait_drive();
  chassis.set_drive_pid(18, 80);
  chassis.wait_drive();
  pros::delay(2000);
  intake.brake();

  // Step 7: shoot picked up disks

  chassis.set_turn_pid(-17, 25);
  chassis.wait_drive();

  flywheel.move_voltage(10166);
  pros::delay(1500);

  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);

  // Step 8: get line of disks on the other side

  pros::delay(1000);
  chassis.set_turn_pid(-90, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(23, 110);
  intake.move_voltage(12000);
  chassis.wait_drive();
  pros::delay(1000);
  chassis.set_turn_pid(-135, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(17, 90);
  chassis.wait_drive();
  
  pros::delay(1250);

  intake.brake();

  chassis.set_turn_pid(-275, 25);
  chassis.wait_drive();

  // Step 9: shoot picked up disks

  flywheel.move_voltage(9000);
  pros::delay(1500);

  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(100);
  indexerSingle.set_value(false);
  pros::delay(750);

  // Step 10: get other two rollers

  pros::delay(1000);
  flywheel.brake();

  chassis.set_turn_pid(-182, 25);
  chassis.wait_drive();
  chassis.set_drive_pid(10, 110);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, 25);
  chassis.wait_drive();

  chassis.set_drive_pid(13, 120);
  chassis.wait_drive();

  intake.move_voltage(12000); // do roller
  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  chassis.set_drive_pid(-7, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(-180, 25);
  chassis.wait_drive();
  chassis.set_drive_pid(13, 120);
  chassis.wait_drive();

  intake.move_voltage(12000); // do roller
  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  chassis.set_drive_pid(-9, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, 25);
  chassis.wait_drive();
  chassis.set_drive_pid(7, 100);
  chassis.wait_drive();

  // Step 11: expand

  expansion.set_value(true);

}

void other_skills(){
  intake.move_voltage(-9000); // do roller 1
  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(375);

  chassis.wait_drive();

  
  // Step 2: shoot two disks
  chassis.set_drive_pid(-2, 90);
  chassis.wait_drive();
  intake.move_voltage(12000);
  chassis.set_turn_pid(135,80);
  chassis.wait_drive();
  chassis.set_drive_pid(3, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(90, 70);
  chassis.wait_drive();
  chassis.set_drive_pid(10, 30);
  chassis.wait_drive();
  intake.move_voltage(-9000);
  chassis.set_drive_pid(1.5,100);
  pros::delay(500);
  chassis.set_drive_pid(-3, 70);
  chassis.wait_drive();
  intake.move_voltage(12000);
  chassis.set_turn_pid(0, 110);
  chassis.wait_drive();

  flywheel.move_voltage(10500);
  
  chassis.set_drive_pid(-27,110);
  chassis.wait_drive();
  chassis.set_turn_pid(10.5, 100);
  chassis.wait_drive();

  //index
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);

  flywheel.brake();

  chassis.set_turn_pid(0, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(19, 110);
  chassis.wait_drive();
  chassis.set_turn_pid(-138, 110);
  chassis.wait_drive();
  intake.move_voltage(12000);
  chassis.set_drive_pid(28, 70);
  chassis.wait_drive();
  flywheel.move_voltage(9020);
  chassis.set_turn_pid(-42, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 100);
  chassis.wait_drive();

  pros::delay(500);
  
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);

  flywheel.brake();

  chassis.set_drive_pid(5, 100);
  chassis.wait_drive();
  chassis.set_turn_pid(-139, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(13, 50);
  chassis.wait_drive();
  flywheel.move_voltage(9600);
  chassis.set_turn_pid(-88, 100);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 100);
  chassis.wait_drive();

  pros::delay(500);
  
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);

  flywheel.brake();

  chassis.set_drive_pid(5, 100);
  chassis.wait_drive();
  chassis.set_turn_pid(-139, 110);
  chassis.wait_drive();

  // chassis.set_drive_pid(3, 120);
  // chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, -180, 100);
  chassis.wait_drive();
  

  intake.move_voltage(-9000); // do roller 1
  chassis.set_drive_pid(1.5, 100); // engage roller

  pros::delay(365);

  chassis.wait_drive();

  intake.brake();

  chassis.set_drive_pid(-2, 100);
  chassis.wait_drive();
  // chassis.set_turn_pid(-135, 100);
  // chassis.wait_drive();
  // chassis.set_drive_pid(5, 100);





  intake.move_voltage(12000);
  // Step 2: shoot two disks
  chassis.set_drive_pid(-2, 90);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, 80);
  chassis.wait_drive();
  chassis.set_drive_pid(3, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, 70);
  chassis.wait_drive();
  chassis.set_drive_pid(6.75, 30);
  chassis.wait_drive();
  intake.move_voltage(-9000);
  chassis.set_drive_pid(2.25, 100);
  pros::delay(525);
  chassis.set_drive_pid(-3, 70);
  chassis.wait_drive();
  chassis.set_turn_pid(-180, 110);
  chassis.wait_drive();
  intake.move_voltage(12000);

  flywheel.move_voltage(10500);
  
  chassis.set_drive_pid(-27,110);
  chassis.wait_drive();
  chassis.set_turn_pid(-169.5, 100);
  chassis.wait_drive();

  //index
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(750); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300);

  flywheel.brake();

  chassis.set_turn_pid(-180, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(19, 110);
  chassis.wait_drive();
  chassis.set_turn_pid(-318, 110);
  chassis.wait_drive();
  intake.move_voltage(12000);
  chassis.set_drive_pid(28, 70);
  chassis.wait_drive();
  flywheel.move_voltage(10500);
  chassis.set_turn_pid(-222, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(-4.75, 100);
  chassis.wait_drive();

  pros::delay(500);
  
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);

  flywheel.brake();

  chassis.set_drive_pid(5, 100);
  chassis.wait_drive();
  chassis.set_turn_pid(-319, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(13, 50);
  chassis.wait_drive();
  flywheel.move_voltage(10250);
  chassis.set_turn_pid(-268, 100);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 100);
  chassis.wait_drive();

  pros::delay(500);
  
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(750);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);

  flywheel.brake();

  intake.brake();
  chassis.set_drive_pid(9, 100);
  chassis.wait_drive();
  chassis.set_turn_pid(45, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(5, 120);
  chassis.wait_drive();
  

  expansion.set_value(true);
}

void not_roller_side(){
  flywheel.move_voltage(-100);
  intake.move_voltage(12000);
  chassis.set_drive_pid(3.15, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(-5, 120);
  chassis.wait_drive();
  chassis.set_drive_pid(8, 70);
  chassis.wait_drive();
  flywheel.move_voltage(11115);
  chassis.set_turn_pid(-154.75, 120);
  chassis.wait_drive();

  pros::delay(1025);

  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(1000);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);

  pros::delay(150);

  chassis.set_turn_pid(135, 90);
  chassis.wait_drive();
  chassis.set_drive_pid(12, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(180, 90);
  chassis.wait_drive();
  intake.move_voltage(-10750); // do roller 1
  chassis.set_drive_pid(4.75, 100); // engage roller

  pros::delay(475);

  intake.brake();
  chassis.wait_drive();
  chassis.set_drive_pid(-2, 100);
}

void solo_wp(){
  flywheel.move_voltage(11700); //11590

  pleaseMoveOrElse(-12000); // do roller 1
  chassis.set_drive_pid(2.5, 127); // engage roller

  pros::delay(375);

  intake.brake();
  chassis.wait_drive();

  // flywheel.move_voltage(11000);

  chassis.set_drive_pid(-4.05, 127);
  chassis.wait_drive();
  chassis.set_turn_pid(-8.5, 127);
  chassis.wait_drive();

 //flywheel.move_voltage(10990); //11020

  pros::delay(350);

  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(700);
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(300);

  flywheel.move_voltage(10250);

  chassis.set_turn_pid(-130, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(11.5, 127);
  chassis.wait_drive();
  pros::delay(50);
  chassis.set_drive_pid(13.25, 45);
  pleaseMoveOrElse(12000);
  chassis.wait_drive();

  pros::delay(875);

  chassis.set_turn_pid(-39, 127);
  chassis.wait_drive();

  pros::delay(315);
  
  // flywheel.move_voltage(10650); //10875

  // pros::delay(2450);

  // indexerSingle.set_value(true);
  // pros::delay(10);
  // indexerSingle.set_value(false);
  // flywheel.move_voltage(12000);
  // pros::delay(300);

  // intake.move_voltage(-12000);

  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(550); //1000
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  pros::delay(550); 
  indexerSingle.set_value(true);
  pros::delay(10);
  indexerSingle.set_value(false);
  

  flywheel.move_voltage(10500);

  pros::delay(25);

  pleaseMoveOrElse(12000);
  chassis.set_turn_pid(-140, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(29.1, 120);
  chassis.wait_drive();
  // pros::delay(190);
  // chassis.set_turn_pid(-52.75, 127);
  // chassis.wait_drive();
  
  // pros::delay(60);

  // indexerSingle.set_value(true);
  // pros::delay(10);
  // indexerSingle.set_value(false);
  // pros::delay(25); //1000

  flywheel.brake();

  // pleaseMoveOrElse(12000);
  // chassis.set_turn_pid(-140, 127);
  // chassis.wait_drive();
  // chassis.set_drive_pid(13.1, 127);
  chassis.set_swing_pid(LEFT_SWING, -90, 127);
  chassis.wait_drive();
  pleaseMoveOrElse(-12000);
  chassis.set_drive_pid(6, 127);
}