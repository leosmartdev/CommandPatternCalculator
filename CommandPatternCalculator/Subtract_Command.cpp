////////////////////////////////////////////////////////////////////////////////

#include "Stack_Expression_Command_Factory.h"

#define LOW_PRECEDENCE 1

Subtract_Command::Subtract_Command() : Binary_Operation_Command(LOW_PRECEDENCE) {
	
}

int Subtract_Command::evaluate(int left, int right) {

    return left - right;
}
