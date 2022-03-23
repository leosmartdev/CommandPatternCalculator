////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Stack_Expression_Command_Factory.h"

// precedence of divide operator
#define MEDIUM_PRECEDENCE 2

//
//  default constructor
//
Divide_Command::Divide_Command() : Binary_Operation_Command(MEDIUM_PRECEDENCE) {

    // nothing else to construct/initialize
}

//
//  evaluate
//
int Divide_Command::evaluate(int left, int right) {

    // Ryan: What about division by 0 here?
    // Fixed: Added exception handling for math errors

    // exception if divide by zero
    if (!right)
        throw std::overflow_error("Invalid Denominator: Divide by zero exception.");

    // divide
    return left / right;
}
