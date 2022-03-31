////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"

// create_number_command
Num_Command * Stack_Exp_Command_Factory::create_number_command(int num) 
{
	return new Num_Command(num);
}

// create_add_command
add_Command_P * Stack_Exp_Command_Factory::create_add_command() 
{
	return new add_Command_P();
}

// create_subtract_command
sub_Command_P * Stack_Exp_Command_Factory::create_subtract_command() 
{
	return new sub_Command_P();
}

// create_multiply_command
mul_Command_P * Stack_Exp_Command_Factory::create_multiply_command() 
{
	return new mul_Command_P();
}

// create_divide_command
div_Command_P * Stack_Exp_Command_Factory::create_divide_command() 
{
	return new div_Command_P();
}

// create_modulo_command
mod_Command_P * Stack_Exp_Command_Factory::create_modulo_command() 
{
	return new mod_Command_P();
}
