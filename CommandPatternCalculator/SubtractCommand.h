////////////////////////////////////////////////////////////////////////////////

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "BinaryOperationCommand.h"

/**
*   @class SubtractCommand
*
*   A type of BinaryOperationCommand that subtracts two numbers.
*
*	Comment Pattern
*/
class SubtractCommand : public BinaryOperationCommand {

public:
	// Default constructor.
	SubtractCommand(void);

	/**
	*   Initializing constructor
	*
	*   @param         precedence          for implementating order-of-operations
	*/
	SubtractCommand(int);

	/**
	*   Subtracts two integers
	*
	*   @param         left                left-hand operand
	*   @param         right               right-hand operand
	*   @return             result              calculated integer
	*/
	int evaluate(int, int);
};

#endif
