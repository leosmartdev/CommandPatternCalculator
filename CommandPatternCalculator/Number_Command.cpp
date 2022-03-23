////////////////////////////////////////////////////////////////////////////////

#include "Number_Command.h"

Number_Command::Number_Command() : number_ (0) {

}

Number_Command::Number_Command(int num) : number_ (num) {

}

void Number_Command::execute(Stack<int> & stack) {

    stack.push(this->evaluate());
}

int Number_Command::evaluate() {

    return this->number_;
}
