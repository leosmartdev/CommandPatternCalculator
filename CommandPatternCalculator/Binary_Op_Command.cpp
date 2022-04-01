////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "Binary_Op_Command.h"

//  default constructor
Binary_Op_Command::Binary_Op_Command() : _priority(0) 
{
	
}

//  priority constructor
Binary_Op_Command::Binary_Op_Command(int priority) : _priority(priority) 
{
	
}

//  get_priority
int Binary_Op_Command::get_priority() 
{
	return this->_priority;
}

//  execute
void Binary_Op_Command::execute(Stack<int> & stack) 
{
	// first pop will be the second operand
	int second = stack.top();
	stack.pop();

	// second pop will be the first operand
	int first = stack.top();
	stack.pop();

	// handle exception
	try {
		int result = this->evaluate(first, second);
		stack.push(result);
	}
	catch (std::overflow_error e) {
		throw e;
	}

}
