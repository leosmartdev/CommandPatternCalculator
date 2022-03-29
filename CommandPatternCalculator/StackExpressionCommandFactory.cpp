////////////////////////////////////////////////////////////////////////////////

#include "StackExpressionCommandFactory.h"

// create_number_command
NumberCommand * StackExpressionCommandFactory::create_number_command(int num) 
{
	return new NumberCommand(num);
}

// create_add_command
AddCommand * StackExpressionCommandFactory::create_add_command() 
{
	return new AddCommand();
}

// create_subtract_command
SubtractCommand * StackExpressionCommandFactory::create_subtract_command() 
{
	return new SubtractCommand();
}

// create_multiply_command
MultiplyCommand * StackExpressionCommandFactory::create_multiply_command() 
{
	return new MultiplyCommand();
}

// create_divide_command
DivideCommand * StackExpressionCommandFactory::create_divide_command() 
{
	return new DivideCommand();
}

// create_modulo_command
ModuloCommand * StackExpressionCommandFactory::create_modulo_command() 
{
	return new ModuloCommand();
}
