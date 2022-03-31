////////////////////////////////////////////////////////////////////////////////

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Command.h"
#include "Stack.h"

/**
*   @class Num_Command
*
*   A type of Command that holds an integer value.
*
*	Comment Pattern
*/
class Num_Command : public Command {

public:
	// Default constructor.
	Num_Command(void);

	/**
	*   Initializing constructor
	*
	*   @param: number              store some integer value
	*/
	Num_Command(int);

	/**
	*   Executes on an input stack by treating it like a calculator evaluation stack.
	*
	*   @param: evaluation stack    stack used for evaluating a postfix expression
	*/
	void execute(Stack<int> &);

	/**
	*   Returns int value of stored number
	*
	*   @return             number              stored int number
	*/
	int evaluate(void);

private:
	// stored number of a typical expression
	int _number;
};

#endif
