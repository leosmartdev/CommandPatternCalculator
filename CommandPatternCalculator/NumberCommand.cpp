////////////////////////////////////////////////////////////////////////////////

#include "NumberCommand.h"

//  constructor
NumberCommand::NumberCommand() : _number(0) 
{

}

//  number constructor
NumberCommand::NumberCommand(int num) : _number(num) 
{
	// 
}

//  execute
void NumberCommand::execute(Stack<int> & stack) 
{
	stack.push(this->evaluate());
}

//  evaluate
int NumberCommand::evaluate() 
{
	return this->_number;
}
