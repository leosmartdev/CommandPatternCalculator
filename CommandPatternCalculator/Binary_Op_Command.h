////////////////////////////////////////////////////////////////////////////////

#ifndef _BINARY_OPERATION_COMMAND_H_
#define _BINARY_OPERATION_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include "Num_Command.h"

/**
*   @class Binary_Op_Command
*
*   A type of Command that involves two integers to be evaluated with some operator.
*	
*	Command Pattern
*/
class Binary_Op_Command : public Command {

public:
	// Default constructor
	Binary_Op_Command(void);

	/**
	*   Initializing constructor
	*
	*   @param: priority          for implementating order-of-operations
	*/
	Binary_Op_Command(int);

	/**
	*   Executes on an input stack
	*
	*   @param: evaluation stack    stack used for evaluating a postfix expression
	*/
	void execute(Stack<int> &);

	/**
	*   Returns the priority of some binary operator
	*
	*   @return: priority          for implementating order-of-operations
	*/
	int get_priority(void);

	/**
	*   Evaluates two integers
	*
	*   @param: first                first-hand operand
	*   @param: second               second-hand operand
	*   @return: result              calculated integer
	*/
	virtual int evaluate(int, int) = 0;

protected:
	// priority of the binary operator in a typical expression
	int _priority;
};

#endif
