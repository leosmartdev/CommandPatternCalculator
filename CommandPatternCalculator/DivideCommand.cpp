////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "StackExpressionCommandFactory.h"

// precedence of divide operator
#define MEDIUM_PRECEDENCE 2

//  default constructor
DivideCommand::DivideCommand() : BinaryOperationCommand(MEDIUM_PRECEDENCE) 
{

}

//  evaluate
int DivideCommand::evaluate(int left, int right) 
{
	// exception if divide by zero
	if (!right)
		throw std::overflow_error("Invalid Denominator: Divide by zero exception.");

	return left / right;
}
