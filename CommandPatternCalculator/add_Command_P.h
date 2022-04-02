////////////////////////////////////////////////////////////////////////////////

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

/**
*   @class add_Command_P
*
*   add two numbers.
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
	*   @param: priority
	*	@description: for order of operations
	*/
	add_Command_P(int);

	/**
	*   Adds two integers
	*
	*   @param: first                first-hand operand
	*   @param: second               second-hand operand
	*   @return: result              calculated integer
	*/
	int get_val(int, int);
};

#endif
