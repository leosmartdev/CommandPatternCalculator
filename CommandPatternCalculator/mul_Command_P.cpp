////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"

// precedence of multiply operator
#define MEDIUM_PRECEDENCE 2

//  default constructor
mul_Command_P::mul_Command_P() : Binary_Op_Command(MEDIUM_PRECEDENCE) 
{
	// to do ...
}

//  evaluate
int mul_Command_P::evaluate(int left, int right) 
{
	return left * right;
}
