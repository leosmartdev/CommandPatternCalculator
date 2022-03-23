////////////////////////////////////////////////////////////////////////////////

#include "Stack_Expression_Command_Factory.h"
#include "Add_Command.h"

#define LOW_PRECEDENCE 1

Add_Command::Add_Command() : Binary_Operation_Command(LOW_PRECEDENCE) {

}

int Add_Command::evaluate(int left, int right) {

    return left + right;
}
