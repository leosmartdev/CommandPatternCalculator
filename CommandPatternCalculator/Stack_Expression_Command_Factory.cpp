////////////////////////////////////////////////////////////////////////////////

#include "Stack_Expression_Command_Factory.h"

Number_Command * Stack_Expression_Command_Factory::create_number_command(int num) {

    return new Number_Command(num);
}

Add_Command * Stack_Expression_Command_Factory::create_add_command() {

    return new Add_Command();
}

Subtract_Command * Stack_Expression_Command_Factory::create_subtract_command() {

    return new Subtract_Command();
}

Multiply_Command * Stack_Expression_Command_Factory::create_multiply_command() {

    return new Multiply_Command();
}

Divide_Command * Stack_Expression_Command_Factory::create_divide_command() {

    return new Divide_Command();
}

Modulo_Command * Stack_Expression_Command_Factory::create_modulo_command() {

    return new Modulo_Command();
}
