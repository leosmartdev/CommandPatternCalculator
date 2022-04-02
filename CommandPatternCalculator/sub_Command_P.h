////////////////////////////////////////////////////////////////////////////////

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

/**
*   @class sub_Command_P
*
*   A type of Binary_Op_Command that subtracts two numbers.
*
*	Comment Pattern
*/
class sub_Command_P : public Binary_Op_Command {

public:
	// Default constructor.
	sub_Command_P(void);

	/**
	*   Initializing constructor
	*
	*   @param         priority          for implementating order-of-operations
	*/
	sub_Command_P(int);

	/**
	*   Subtracts two integers
	*
	*   @param: first                first-hand operand
	*   @param: second               second-hand operand
	*   @return: result              calculated integer
	*/
	int get_val(int, int);
};

#endif
