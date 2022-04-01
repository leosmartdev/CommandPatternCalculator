////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"

// create_num_command
Num_Command * Stack_Exp_Command_Factory::create_num_command(int num) 
{
	return new Num_Command(num);
}

// create_add_command
add_Command_P * Stack_Exp_Command_Factory::create_add_command() 
{
	return new add_Command_P();
}

// create_sub_command
sub_Command_P * Stack_Exp_Command_Factory::create_sub_command() 
{
	return new sub_Command_P();
}

// create_mul_command
mul_Command_P * Stack_Exp_Command_Factory::create_mul_command() 
{
	return new mul_Command_P();
}

// create_div_command
div_Command_P * Stack_Exp_Command_Factory::create_div_command() 
{
	return new div_Command_P();
}

// create_mod_command
mod_Command_P * Stack_Exp_Command_Factory::create_mod_command() 
{
	return new mod_Command_P();
}
