////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"

//  default constructor
mul_Command_P::mul_Command_P() : Binary_Op_Command(2) 
{
	// to do ...
}

//  get_val
int mul_Command_P::get_val(int first, int second) 
{
	return first * second;
}
