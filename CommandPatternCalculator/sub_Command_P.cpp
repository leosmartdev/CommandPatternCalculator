////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"

// precedence of subtract operator
#define LOW_PRECEDENCE 1

//  default constructor
sub_Command_P::sub_Command_P() : Binary_Op_Command(LOW_PRECEDENCE) 
{
	// 
}

//  evaluate
int sub_Command_P::evaluate(int left, int right) 
{
	return left - right;
}
