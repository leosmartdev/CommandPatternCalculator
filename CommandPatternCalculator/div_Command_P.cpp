////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Stack_Exp_Command_Factory.h"

//  default constructor
div_Command_P::div_Command_P() : Binary_Op_Command(2) 
{

}

//  evaluate
int div_Command_P::evaluate(int first, int second) 
{
	// exception if divide by zero
	if (second == 0)
		throw std::overflow_error("Invalid: Divide by zero.");

	return first / second;
}
