////////////////////////////////////////////////////////////////////////////////

#ifndef _MODULO_COMMAND_H_
#define _MODULO_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Modulo_Command
*
*   A type of Binary_Operation_Command that mods two numbers.
*
*	Command Pattern
*/
class Modulo_Command : public Binary_Operation_Command {

public:
	// Default constructor.
	Modulo_Command(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence          for implementating order-of-operations
	*/
	Modulo_Command(int);

	/**
	*   Mods two integers
	*
	*   @param: left                left-hand operand
	*   @param: right               right-hand operand
	*   @return: result              calculated integer
	*   @exception: overflow_error      denominator is zero
	*/
	int evaluate(int, int);
};

#endif
