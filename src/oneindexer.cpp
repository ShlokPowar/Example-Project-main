#include "main.h"
#include "headers.hpp"

void single_index(){
    if(master.get_digital(DIGITAL_L2)){
        indexerSingle.set_value(true);
        pros::delay(20);
        indexerSingle.set_value(false);
        pros::delay(275);
    }
    else{
        indexerSingle.set_value(false);
    }
}