////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"

//  default constructor
mul_Command_P::mul_Command_P() : Binary_Op_Command(2) 
{
	// to do ...
}

//  evaluate
int mul_Command_P::evaluate(int first, int second) 
{
	return first * second;
}
