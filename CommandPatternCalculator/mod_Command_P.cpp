////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Stack_Exp_Command_Factory.h"

//  default constructor
mod_Command_P::mod_Command_P() : Binary_Op_Command(2) 
{

}

//  evaluate
int mod_Command_P::evaluate(int first, int second) 
{
	// exception if second-hand number is zero
	if (!second)
		throw std::overflow_error("Invalid Denominator: Mod by zero exception.");

	return first % second;
}
