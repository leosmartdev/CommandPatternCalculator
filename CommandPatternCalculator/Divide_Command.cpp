////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Stack_Expression_Command_Factory.h"

// precedence of divide operator
#define MEDIUM_PRECEDENCE 2

Divide_Command::Divide_Command() : Binary_Operation_Command(MEDIUM_PRECEDENCE) {

}

int Divide_Command::evaluate(int left, int right) {

    if (!right)
        throw std::overflow_error("Invalid Denominator: Divide by zero exception.");

    return left / right;
}
