////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Stack_Exp_Command_Factory.h"

//  default constructor
div_Command_P::div_Command_P() : Binary_Op_Command(2) 
{

}

//  get_val
int div_Command_P::get_val(int first, int second) 
{
	// COMMENT: A better conditional is second == 0 since that is what
	// you are actually testing for. Although you will get the same
	// result, its not semantically the same.

	// SOLUTION
	// add exception if second == 0
	// It will display Invalid error message in cosole command

	// exception if divide by zero
	if (second == 0)
		throw std::overflow_error("Invalid: Divide by zero.");

	return first / second;
}
