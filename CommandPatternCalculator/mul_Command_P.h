////////////////////////////////////////////////////////////////////////////////

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

/**
*   @class mul_Command_P
*
*   A type of Binary_Op_Command that multiplies two numbers.
*
*	Comment Pattern
*/
class mul_Command_P : public Binary_Op_Command {

public:
	// Default constructor.
	mul_Command_P(void);

	/**
	*   Initializing constructor
	*
	*   @param: priority          for implementating order-of-operations
	*/
	mul_Command_P(int);

	/**
	*   Multiplies two integers
	*
	*   @param: first                first-hand operand
	*   @param: second               second-hand operand
	*   @return: result              calculated integer
	*/
	int get_val(int, int);
};

#endif
