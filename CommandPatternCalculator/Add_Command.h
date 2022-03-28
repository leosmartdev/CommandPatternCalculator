////////////////////////////////////////////////////////////////////////////////

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Add_Command
*
*   adds two numbers.
*
*	Command Pattern
*/
class Add_Command : public Binary_Operation_Command {

public:
	// Default constructor.
	Add_Command(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence
	*	@description: for implementating order-of-operations
	*/
	Add_Command(int);

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
