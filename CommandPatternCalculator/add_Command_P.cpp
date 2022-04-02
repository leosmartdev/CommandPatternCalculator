////////////////////////////////////////////////////////////////////////////////

#include "Stack_Exp_Command_Factory.h"
#include "add_Command_P.h"

//  default constructor
add_Command_P::add_Command_P() : Binary_Op_Command(1) 
{
	// 
}

//  get_val
int add_Command_P::get_val(int first, int second) 
{
	return first + second;
}
