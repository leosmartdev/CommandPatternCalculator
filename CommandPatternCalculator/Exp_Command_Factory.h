////////////////////////////////////////////////////////////////////////////////

#ifndef _EXPRESSION_COMMAND_FACTORY_H_
#define _EXPRESSION_COMMAND_FACTORY_H_

#include "Num_Command.h"
#include "add_Command_P.h"
#include "sub_Command_P.h"
#include "mul_Command_P.h"
#include "div_Command_P.h"
#include "mod_Command_P.h"

/**
*   @class Exp_Command_Factory
*
*   An interface for factories that construct commands including basic integer operation commands.
* 
*	Abstract Factory Pattern
*/
class Exp_Command_Factory {

public:
	// Default constructor
	Exp_Command_Factory(void) {}

	// Destructor
	virtual ~Exp_Command_Factory(void) {};

	// Copy constructor (deleted)
	Exp_Command_Factory(const Exp_Command_Factory &) = delete;

	// Equals operator (deleted)
	const Exp_Command_Factory & operator = (const Exp_Command_Factory &) = delete;

	/**
	*   Creates and returns a command representing some integer value
	*
	*   @param: value               integer value
	*   @return: number command      command representing a number
	*/
	virtual Num_Command * create_number_command(int num) = 0;

	/**
	*   Creates and returns a command representing an addition operator
	*
	*   @return: add command         command representing an addition operator
	*/
	virtual add_Command_P * create_add_command(void) = 0;

	/**
	*   Creates and returns a command representing a subtraction operator
	*   @return: subtract command    command representing a subtraction operator
	*/
	virtual sub_Command_P * create_subtract_command(void) = 0;

	/**
	*   Creates and returns a command representing a multiplcation operator
	*   @return: multiply command    command representing a multiplcation operator
	*/
	virtual mul_Command_P * create_multiply_command(void) = 0;

	/**
	*   Creates and returns a command representing a division operator
	*   @return: divide command      command representing a division operator
	*/
	virtual div_Command_P * create_divide_command(void) = 0;

	/**
	*   Creates and returns a command representing a modulo operator
	*   @return: modulo command      command representing a modulo operator
	*/
	virtual mod_Command_P * create_modulo_command(void) = 0;
};

#endif
