////////////////////////////////////////////////////////////////////////////////

#include "StackExpressionCommandFactory.h"
#include "AddCommand.h"

// precedence of add operator
#define LOW_PRECEDENCE 1

//  default constructor
AddCommand::AddCommand() : BinaryOperationCommand(LOW_PRECEDENCE) 
{
	// nothing else to construct/initialize
}

//  evaluate
int AddCommand::evaluate(int left, int right) 
{
	return left + right;
}
