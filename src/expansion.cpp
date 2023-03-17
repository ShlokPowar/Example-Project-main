#include "main.h"
#include "headers.hpp"

bool expanded = false;

void expand(){
    if(master.get_digital_new_press(DIGITAL_RIGHT)){
        expanded = !expanded;
        expansion.set_value(expanded);
    }
}