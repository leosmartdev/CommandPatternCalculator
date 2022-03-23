////////////////////////////////////////////////////////////////////////////////

#include "Stack_Expression_Command_Factory.h"

#define MEDIUM_PRECEDENCE 2

Multiply_Command::Multiply_Command() : Binary_Operation_Command(MEDIUM_PRECEDENCE) {

}

int Multiply_Command::evaluate(int left, int right) {

    return left * right;
}
