////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Binary_Operation_Command.h"

//
//  default constructor
//
Binary_Operation_Command::Binary_Operation_Command() : precedence_(0) {

	// nothing else to construct/initialize
}

//
//  precedence constructor
//
Binary_Operation_Command::Binary_Operation_Command(int precedence) :
	precedence_(precedence) {

	// nothing else to construct/initialize
}

//
//  get_precedence
//
int Binary_Operation_Command::get_precedence() {

	// return order-of-operations precedence of operator
	return this->precedence_;
}

//
//  execute
//
void Binary_Operation_Command::execute(Stack<int> & stack) {

	// first pop will be the right operand
	int right = stack.top();
	stack.pop();

	// second pop will be the left operand
	int left = stack.top();
	stack.pop();

	// handle math exception
	try {

		// evaluate (this must be some operator) and push onto stack
		int result = this->evaluate(left, right);
		stack.push(result);

	}
	catch (std::overflow_error e) {

		// throw it again
		throw e;
	}

}
