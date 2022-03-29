////////////////////////////////////////////////////////////////////////////////

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "BinaryOperationCommand.h"

/**
*   @class AddCommand
*
*   adds two numbers.
*
*	Command Pattern
*/
class AddCommand : public BinaryOperationCommand {

public:
	// Default constructor.
	AddCommand(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence
	*	@description: for implementating order-of-operations
	*/
	AddCommand(int);

	/**
	*   Adds two integers
	*
	*   @param: left                left-hand operand
	*   @param: right               right-hand operand
	*   @return: result              calculated integer
	*/
	int evaluate(int, int);
};

#endif
