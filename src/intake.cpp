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