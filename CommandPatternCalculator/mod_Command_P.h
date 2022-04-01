////////////////////////////////////////////////////////////////////////////////

#ifndef _MODULO_COMMAND_H_
#define _MODULO_COMMAND_H_

#include "Binary_Op_Command.h"

/**
*   @class mod_Command_P
*
*   A type of Binary_Op_Command that mods two numbers.
*
*	Command Pattern
*/
class mod_Command_P : public Binary_Op_Command {

public:
	// Default constructor.
	mod_Command_P(void);

	/**
	*   Initializing constructor
	*
	*   @param: priority          for implementating order-of-operations
	*/
	mod_Command_P(int);

	/**
	*   Mods two integers
	*
	*   @param: first                first-hand operand
	*   @param: second               second-hand operand
	*   @return: result              calculated integer
	*   @exception: overflow_error      denominator is zero
	*/
	int evaluate(int, int);
};

#endif
