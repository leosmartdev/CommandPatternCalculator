////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Stack_Exp_Command_Factory.h"

// precedence of modulus operator
#define MEDIUM_PRECEDENCE 2

//  default constructor
mod_Command_P::mod_Command_P() : Binary_Op_Command(MEDIUM_PRECEDENCE) 
{

}

//  evaluate
int mod_Command_P::evaluate(int left, int right) 
{
	// exception if right-hand number is zero
	if (!right)
		throw std::overflow_error("Invalid Denominator: Mod by zero exception.");

	return left % right;
}
