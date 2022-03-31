////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Binary_Op_Command.h"

//  default constructor
Binary_Op_Command::Binary_Op_Command() : _precedence(0) 
{
	
}

//  precedence constructor
Binary_Op_Command::Binary_Op_Command(int precedence) : _precedence(precedence) 
{
	
}

//  get_precedence
int Binary_Op_Command::get_precedence() 
{
	return this->_precedence;
}

//  execute
void Binary_Op_Command::execute(Stack<int> & stack) 
{
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
