////////////////////////////////////////////////////////////////////////////////

#ifndef _MODULO_COMMAND_H_
#define _MODULO_COMMAND_H_

#include "BinaryOperationCommand.h"

/**
*   @class ModuloCommand
*
*   A type of BinaryOperationCommand that mods two numbers.
*
*	Command Pattern
*/
class ModuloCommand : public BinaryOperationCommand {

public:
	// Default constructor.
	ModuloCommand(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence          for implementating order-of-operations
	*/
	ModuloCommand(int);

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
