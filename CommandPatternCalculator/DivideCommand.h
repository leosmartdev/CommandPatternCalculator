////////////////////////////////////////////////////////////////////////////////

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "BinaryOperationCommand.h"

/**
*   @class DivideCommand
*   A type of BinaryOperationCommand that divides two numbers.
*
*	Command Pattern
*/
class DivideCommand : public BinaryOperationCommand {

public:
	// Default constructor.
	DivideCommand(void);

	/**
	*   Initializing constructor
	*   @param: precedence          for implementating order-of-operations
	*/
	DivideCommand(int);

	/**
	*   Divides two integers
	*   @param: left                left-hand operand
	*   @param: right               right-hand operand
	*   @return: result              calculated integer
	*   @exception: overflow_error      denominator is zero
	*/
	int evaluate(int, int);
};

#endif
