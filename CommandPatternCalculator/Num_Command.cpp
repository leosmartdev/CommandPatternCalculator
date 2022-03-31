////////////////////////////////////////////////////////////////////////////////

#include "Num_Command.h"

//  constructor
Num_Command::Num_Command() : _number(0) 
{

}

//  number constructor
Num_Command::Num_Command(int num) : _number(num) 
{
	// 
}

//  execute
void Num_Command::execute(Stack<int> & stack) 
{
	stack.push(this->evaluate());
}

//  evaluate
int Num_Command::evaluate() 
{
	return this->_number;
}
