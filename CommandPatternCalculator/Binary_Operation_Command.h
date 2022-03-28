////////////////////////////////////////////////////////////////////////////////

#ifndef _BINARY_OPERATION_COMMAND_H_
#define _BINARY_OPERATION_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include "Number_Command.h"

/**
*   @class Binary_Operation_Command
*
*   A type of Command that involves two integers to be evaluated with some operator.
*	
*	Command Pattern
*/
class Binary_Operation_Command : public Command {

public:
	// Default constructor
	Binary_Operation_Command(void);

	/**
	*   Initializing constructor
	*
	*   @param: precedence          for implementating order-of-operations
	*/
	Binary_Operation_Command(int);

	/**
	*   Executes on an input stack
	*
	*   @param: evaluation stack    stack used for evaluating a postfix expression
	*/
	void execute(Stack<int> &);

	/**
	*   Returns the precedence of some binary operator
	*
	*   @return: precedence          for implementating order-of-operations
	*/
	int get_precedence(void);

	/**
	*   Evaluates two integers
	*
	*   @param: left                left-hand operand
	*   @param: right               right-hand operand
	*   @return: result              calculated integer
	*/
	virtual int evaluate(int, int) = 0;

protected:
	// precedence of the binary operator in a typical expression
	int precedence_;
};

#endif
