////////////////////////////////////////////////////////////////////////////////

#include "StackExpressionCommandFactory.h"

// precedence of subtract operator
#define LOW_PRECEDENCE 1

//  default constructor
SubtractCommand::SubtractCommand() : BinaryOperationCommand(LOW_PRECEDENCE) 
{
	// 
}

//  evaluate
int SubtractCommand::evaluate(int left, int right) 
{
	return left - right;
}
