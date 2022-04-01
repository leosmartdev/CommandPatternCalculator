////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"
#include "add_Command_P.h"

//  default constructor
add_Command_P::add_Command_P() : Binary_Op_Command(1) 
{
	// 
}

//  evaluate
int add_Command_P::evaluate(int first, int second) 
{
	return first + second;
}
