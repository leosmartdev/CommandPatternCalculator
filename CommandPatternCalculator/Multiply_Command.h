////////////////////////////////////////////////////////////////////////////////

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Multiply_Command
*
*   A type of Binary_Operation_Command that multiplies two numbers.
*/
class Multiply_Command : public Binary_Operation_Command {

public:
	/// Default constructor.
	Multiply_Command(void);

	/**
	*   Initializing constructor
	*
	*   @param[in]          precedence          for implementating order-of-operations
	*/
	Multiply_Command(int);

	/**
	*   Multiplies two integers
	*
	*   @param[in]          left                left-hand operand
	*   @param[in]          right               right-hand operand
	*   @return             result              calculated integer
	*/
	int evaluate(int, int);
};

#endif
