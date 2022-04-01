////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"

//  default constructor
sub_Command_P::sub_Command_P() : Binary_Op_Command(1) 
{
	// 
}

//  evaluate
int sub_Command_P::evaluate(int first, int second) 
{
	return first - second;
}
