////////////////////////////////////////////////////////////////////////////////

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Divide_Command
*
*   A type of Binary_Operation_Command that divides two numbers.
*
*	Command Pattern
*/
class Divide_Command : public Binary_Operation_Command {

public:
	// Default constructor.
	Divide_Command(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence          for implementating order-of-operations
	*/
	Divide_Command(int);

	/**
	*   Divides two integers
	*
	*   @param: left                left-hand operand
	*   @param: right               right-hand operand
	*   @return: result              calculated integer
	*   @exception: overflow_error      denominator is zero
	*/
	int evaluate(int, int);
};

#endif
