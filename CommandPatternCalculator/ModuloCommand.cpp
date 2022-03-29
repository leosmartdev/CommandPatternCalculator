////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "StackExpressionCommandFactory.h"

// precedence of modulus operator
#define MEDIUM_PRECEDENCE 2

//  default constructor
ModuloCommand::ModuloCommand() : BinaryOperationCommand(MEDIUM_PRECEDENCE) 
{

}

//  evaluate
int ModuloCommand::evaluate(int left, int right) 
{
	// exception if right-hand number is zero
	if (!right)
		throw std::overflow_error("Invalid Denominator: Mod by zero exception.");

	return left % right;
}
