////////////////////////////////////////////////////////////////////////////////

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

/**
*   @class add_Command_P
*
*   adds two numbers.
*
*	Command Pattern
*/
class add_Command_P : public Binary_Op_Command {

public:
	// Default constructor.
	add_Command_P(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence
	*	@description: for implementating order-of-operations
	*/
	add_Command_P(int);

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
