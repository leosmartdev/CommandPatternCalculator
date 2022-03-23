////////////////////////////////////////////////////////////////////////////////

#include "Stack_Expression_Command_Factory.h"

//
// create_number_command
//
Number_Command * Stack_Expression_Command_Factory::create_number_command(int num) {

    return new Number_Command(num);
}

//
// create_add_command
//
Add_Command * Stack_Expression_Command_Factory::create_add_command() {

    return new Add_Command();
}

//
// create_subtract_command
//
Subtract_Command * Stack_Expression_Command_Factory::create_subtract_command() {

    return new Subtract_Command();
}

//
// create_multiply_command
//
Multiply_Command * Stack_Expression_Command_Factory::create_multiply_command() {

    return new Multiply_Command();
}

//
// create_divide_command
//
Divide_Command * Stack_Expression_Command_Factory::create_divide_command() {

    return new Divide_Command();
}

//
// create_modulo_command
//
Modulo_Command * Stack_Expression_Command_Factory::create_modulo_command() {

    return new Modulo_Command();
}
