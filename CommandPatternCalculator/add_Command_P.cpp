////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"
#include "add_Command_P.h"

// precedence of add operator
#define LOW_PRECEDENCE 1

//  default constructor
add_Command_P::add_Command_P() : Binary_Op_Command(LOW_PRECEDENCE) 
{
	// nothing else to construct/initialize
}

//  evaluate
int add_Command_P::evaluate(int left, int right) 
{
	return left + right;
}
