////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Stack_Expression_Command_Factory.h"

#define MEDIUM_PRECEDENCE 2

Modulo_Command::Modulo_Command() : Binary_Operation_Command(MEDIUM_PRECEDENCE) {

}

int Modulo_Command::evaluate(int left, int right) {

    if (!right)
        throw std::overflow_error("Invalid Denominator: Mod by zero exception.");

    return left % right;
}
