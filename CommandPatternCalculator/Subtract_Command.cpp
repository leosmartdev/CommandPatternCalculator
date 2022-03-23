////////////////////////////////////////////////////////////////////////////////

#include "Stack_Expression_Command_Factory.h"

// precedence of subtract operator
#define LOW_PRECEDENCE 1

//
//  default constructor
//
Subtract_Command::Subtract_Command() : Binary_Operation_Command(LOW_PRECEDENCE) {

    // nothing else to construct/initialize
}

//
//  evaluate
//
int Subtract_Command::evaluate(int left, int right) {

    // subtract
    return left - right;
}
