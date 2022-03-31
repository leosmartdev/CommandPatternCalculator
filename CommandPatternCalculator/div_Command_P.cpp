////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Stack_Exp_Command_Factory.h"

// precedence of divide operator
#define MEDIUM_PRECEDENCE 2

//  default constructor
div_Command_P::div_Command_P() : Binary_Op_Command(MEDIUM_PRECEDENCE) 
{

}

//  evaluate
int div_Command_P::evaluate(int left, int right) 
{
	// exception if divide by zero
	if (!right)
		throw std::overflow_error("Invalid Denominator: Divide by zero exception.");

	return left / right;
}
