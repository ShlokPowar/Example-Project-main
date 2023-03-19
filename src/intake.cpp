#include "main.h"
#include "headers.hpp"


void setIntake(){
    print_to_screen("intaking");
    if(master.get_digital(DIGITAL_R1)){
        intake.move_voltage(12000);
    }
    else if(master.get_digital(DIGITAL_R2)){
        intake.move_voltage(-12000);
    }
    else{
        intake.move_voltage(0);
    }
}

void pleaseMoveOrElse(double v) {
    if (intake.get_actual_velocity() == 0) {
        intake.brake();
    }

    pros::delay(1);

    intake.move_voltage(v);
}