////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "BinaryOperationCommand.h"

//  default constructor
BinaryOperationCommand::BinaryOperationCommand() : _precedence(0) 
{
	
}

//  precedence constructor
BinaryOperationCommand::BinaryOperationCommand(int precedence) : _precedence(precedence) 
{
	
}

//  get_precedence
int BinaryOperationCommand::get_precedence() 
{
	return this->_precedence;
}

//  execute
void BinaryOperationCommand::execute(Stack<int> & stack) 
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
