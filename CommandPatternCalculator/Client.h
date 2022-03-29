////////////////////////////////////////////////////////////////////////////////

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
#include <string>

#include "Array.h"
#include "Command.h"
#include "StackExpressionCommandFactory.h"

/**
*   @class Client
*   Client controls I/O and evaluation of the expression evaluator.
*/
class Client {

public:
	/**
	* main running process.
	*/
	void run();

private:
	/**
	*   Parses an std string into a string array.
	*   @param: std::string             user input infix expression
	*   @return: Array<std::string>      infix expression
	*/
	Array<std::string> parse(std::string);

	/**
	*   Determines if the input string can be converted into an integer by actually converting it.
	*   @param: std::string             input string
	*   @return: bool=true               input as int is a valid int
	*   @return: bool=false              input as int is an invalid int
	*/
	bool is_integer(std::string);

	/**
	*   Runs through the infix string array and makes sure it is valid.
	*   @param: Array<std::string>      infix expression
	*   @return: bool=true               input is valid
	*   @return: bool=false              input is invalid
	*/
	bool is_valid(Array<std::string> &);

	/**
	*   Returns operator precedence to use for order-of-operations
	*   @param: std::string             some operator in string format
	*   @return: int                     precedence level
	*/
	int get_precedence(std::string);

	/**
	*   Creates and returns a new postfix string array from the input infix string array.
	*   @param: Array<std::string>      infix expression
	*   @param: StackExpressionCommandFactory      factory that creates commands
	*   @return: Array<Command*>         postfix expression represented by commands
	*/
	Array<Command*> infix_to_postfix(Array<std::string> &, StackExpressionCommandFactory &);

	/**
	*   Evaluates a postfix string array to some integer and returns it
	*   @param: Array<Command*>         postfix expression represented by commands
	*   @return: Integer                 final result value from expression
	*   @exception: Math_Exception          Some math error while evaluating
	*/
	int evaluate(Array<Command*> &);
};

#endif   // !defined _CLIENT_H_
