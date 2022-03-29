////////////////////////////////////////////////////////////////////////////////

#ifndef _STACK_EXPRESSION_COMMAND_FACTORY_H_
#define _STACK_EXPRESSION_COMMAND_FACTORY_H_

#include "ExpressionCommandFactory.h"
#include "NumberCommand.h"
#include "AddCommand.h"
#include "SubtractCommand.h"
#include "MultiplyCommand.h"
#include "DivideCommand.h"
#include "ModuloCommand.h"

/**
*   @class StackExpressionCommandFactory
*
*   Creates commands for basic calculator integer operations.
*
*	Abstract Factory Pattern
*/
class StackExpressionCommandFactory : public ExpressionCommandFactory {

public:
	/**
	*   Creates and returns a command representing some integer value
	*
	*   @param         value               integer value
	*   @return             number command      command representing a number
	*/
	NumberCommand * create_number_command(int num);

	/**
	*   Creates and returns a command representing an addition operator
	*
	*   @return             add command         command representing an addition operator
	*/
	AddCommand * create_add_command(void);

	/**
	*   Creates and returns a command representing a subtraction operator
	*
	*   @return             subtract command    command representing a subtraction operator
	*/
	SubtractCommand * create_subtract_command(void);

	/**
	*   Creates and returns a command representing a multiplcation operator
	*
	*   @return             multiply command    command representing a multiplcation operator
	*/
	virtual MultiplyCommand * create_multiply_command(void);

	/**
	*   Creates and returns a command representing a division operator
	*
	*   @return             divide command      command representing a division operator
	*/
	DivideCommand * create_divide_command(void);

	/**
	*   Creates and returns a command representing a modulo operator
	*
	*   @return             modulo command      command representing a modulo operator
	*/
	ModuloCommand * create_modulo_command(void);
};

#endif
