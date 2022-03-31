////////////////////////////////////////////////////////////////////////////////

#ifndef _STACK_EXPRESSION_COMMAND_FACTORY_H_
#define _STACK_EXPRESSION_COMMAND_FACTORY_H_

#include "Exp_Command_Factory.h"
#include "Num_Command.h"
#include "add_Command_P.h"
#include "sub_Command_P.h"
#include "mul_Command_P.h"
#include "div_Command_P.h"
#include "mod_Command_P.h"

/**
*   @class Stack_Exp_Command_Factory
*
*   Creates commands for basic calculator integer operations.
*
*	Abstract Factory Pattern
*/
class Stack_Exp_Command_Factory : public Exp_Command_Factory {

public:
	/**
	*   Creates and returns a command representing some integer value
	*
	*   @param         value               integer value
	*   @return             number command      command representing a number
	*/
	Num_Command * create_number_command(int num);

	/**
	*   Creates and returns a command representing an addition operator
	*
	*   @return             add command         command representing an addition operator
	*/
	add_Command_P * create_add_command(void);

	/**
	*   Creates and returns a command representing a subtraction operator
	*
	*   @return             subtract command    command representing a subtraction operator
	*/
	sub_Command_P * create_subtract_command(void);

	/**
	*   Creates and returns a command representing a multiplcation operator
	*
	*   @return             multiply command    command representing a multiplcation operator
	*/
	virtual mul_Command_P * create_multiply_command(void);

	/**
	*   Creates and returns a command representing a division operator
	*
	*   @return             divide command      command representing a division operator
	*/
	div_Command_P * create_divide_command(void);

	/**
	*   Creates and returns a command representing a modulo operator
	*
	*   @return             modulo command      command representing a modulo operator
	*/
	mod_Command_P * create_modulo_command(void);
};

#endif
