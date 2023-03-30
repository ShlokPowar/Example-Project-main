#include "main.h"
#include "headers.hpp"


int rpms[3] = {0, 9400, 11166};
int mode = 0;

void toggle_flywheel(){
    
    // if(master.get_digital_new_press(DIGITAL_X)){
    //     toggle = !toggle;
    // }
    // if(toggle){
    //     flywheel.move_voltage(11000);
    // }
    // else{
    //     flywheel.move_voltage(0);
    // }

    if (master.get_digital_new_press(DIGITAL_X)) {
        ez::print_to_screen("sui");
        mode++;
        if (mode == 3) {
            mode = 0;
        }
    }

    if (master.get_digital_new_press(DIGITAL_Y)) {
        mode = 0;
    }

    flywheel.move_voltage(rpms[mode]);
    ez::print_to_screen("Moving\n");
}


// void flywheelPID(double target){
//     if (target == 0) { flywheel.brake(); }

//     //Constants
//     double kP = 0.6; // how much it tries to correct speed by
//     double kV = 0.0354; 
//     double threshold = 150; // maximum error in flywheel speed 

//     double error = 0; // normal loop variables to keep track
//     double prevError = 0;

//     double output = 0; // what to change flywheel by

//     while (true){
//         //Proportional
//         error = (target/3600)*127 - flywheel.get_actual_velocity()*6;

//         //Set Speed of Flywheel
//         if (error > threshold){
//             output = 127;
//         }

//         else if (error < - threshold){
//             output = 0;
//         }

//         else{
//             output = (kV * target) + (kP * error);
//         }

//         flywheel.move(output);

//         prevError = error;
//         pros::delay(10);
//     }
// }


// void set_flywheel_speed(int speed){
//     static std::unique_ptr<pros::Task> pidTask {};
//     if (pidTask != nullptr) {pidTask -> remove();}

//     pidTask = (speed == -1) ? nullptr : std::make_unique<pros::Task>([=]{flywheelPID(speed);});
// }