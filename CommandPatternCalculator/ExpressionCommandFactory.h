////////////////////////////////////////////////////////////////////////////////

#ifndef _EXPRESSION_COMMAND_FACTORY_H_
#define _EXPRESSION_COMMAND_FACTORY_H_

#include "NumberCommand.h"
#include "AddCommand.h"
#include "SubtractCommand.h"
#include "MultiplyCommand.h"
#include "DivideCommand.h"
#include "ModuloCommand.h"

/**
*   @class ExpressionCommandFactory
*
*   An interface for factories that construct commands including basic integer operation commands.
* 
*	Abstract Factory Pattern
*/
class ExpressionCommandFactory {

public:
	// Default constructor
	ExpressionCommandFactory(void) {}

	// Destructor
	virtual ~ExpressionCommandFactory(void) {};

	// Copy constructor (deleted)
	ExpressionCommandFactory(const ExpressionCommandFactory &) = delete;

	// Equals operator (deleted)
	const ExpressionCommandFactory & operator = (const ExpressionCommandFactory &) = delete;

	/**
	*   Creates and returns a command representing some integer value
	*
	*   @param: value               integer value
	*   @return: number command      command representing a number
	*/
	virtual NumberCommand * create_number_command(int num) = 0;

	/**
	*   Creates and returns a command representing an addition operator
	*
	*   @return: add command         command representing an addition operator
	*/
	virtual AddCommand * create_add_command(void) = 0;

	/**
	*   Creates and returns a command representing a subtraction operator
	*   @return: subtract command    command representing a subtraction operator
	*/
	virtual SubtractCommand * create_subtract_command(void) = 0;

	/**
	*   Creates and returns a command representing a multiplcation operator
	*   @return: multiply command    command representing a multiplcation operator
	*/
	virtual MultiplyCommand * create_multiply_command(void) = 0;

	/**
	*   Creates and returns a command representing a division operator
	*   @return: divide command      command representing a division operator
	*/
	virtual DivideCommand * create_divide_command(void) = 0;

	/**
	*   Creates and returns a command representing a modulo operator
	*   @return: modulo command      command representing a modulo operator
	*/
	virtual ModuloCommand * create_modulo_command(void) = 0;
};

#endif
