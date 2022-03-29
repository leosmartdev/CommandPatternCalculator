////////////////////////////////////////////////////////////////////////////////

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "BinaryOperationCommand.h"

/**
*   @class MultiplyCommand
*
*   A type of BinaryOperationCommand that multiplies two numbers.
*
*	Comment Pattern
*/
class MultiplyCommand : public BinaryOperationCommand {

public:
	// Default constructor.
	MultiplyCommand(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence          for implementating order-of-operations
	*/
	MultiplyCommand(int);

	/**
	*   Multiplies two integers
	*
	*   @param: left                left-hand operand
	*   @param: right               right-hand operand
	*   @return: result              calculated integer
	*/
	int evaluate(int, int);
};

#endif
