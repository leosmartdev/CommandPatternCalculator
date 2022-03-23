////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Binary_Operation_Command.h"

Binary_Operation_Command::Binary_Operation_Command() : precedence_(0) {

}

Binary_Operation_Command::Binary_Operation_Command(int precedence) :
        precedence_(precedence) {

}

int Binary_Operation_Command::get_precedence() {

    return this->precedence_;
}

void Binary_Operation_Command::execute(Stack<int> & stack) {

    int right = stack.top();
    stack.pop();

    int left = stack.top();
    stack.pop();

    try {

        int result = this->evaluate(left, right);
        stack.push(result);

    } catch (std::overflow_error e) {

        throw e;
    }

}
