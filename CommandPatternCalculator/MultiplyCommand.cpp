////////////////////////////////////////////////////////////////////////////////

#include "StackExpressionCommandFactory.h"

// precedence of multiply operator
#define MEDIUM_PRECEDENCE 2

//  default constructor
MultiplyCommand::MultiplyCommand() : BinaryOperationCommand(MEDIUM_PRECEDENCE) 
{
	// to do ...
}

//  evaluate
int MultiplyCommand::evaluate(int left, int right) 
{
	return left * right;
}
