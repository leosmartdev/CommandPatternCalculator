////////////////////////////////////////////////////////////////////////////////

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Multiply_Command
*
*   A type of Binary_Operation_Command that multiplies two numbers.
*
*	Comment Pattern
*/
class Multiply_Command : public Binary_Operation_Command {

public:
	// Default constructor.
	Multiply_Command(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence          for implementating order-of-operations
	*/
	Multiply_Command(int);

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
