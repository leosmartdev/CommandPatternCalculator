////////////////////////////////////////////////////////////////////////////////

#include "Stack_Expression_Command_Factory.h"
#include "Add_Command.h"

// precedence of add operator
#define LOW_PRECEDENCE 1

//
//  default constructor
//
Add_Command::Add_Command() : Binary_Operation_Command(LOW_PRECEDENCE) {

	// nothing else to construct/initialize
}

//
//  evaluate
//
int Add_Command::evaluate(int left, int right) {

	// add
	return left + right;
}
