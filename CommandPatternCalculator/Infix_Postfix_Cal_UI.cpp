// CommandPatternCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <assert.h>

#include <string>
#include <sstream>
#include <queue>

#include "Array.h"
#include "Stack.h"
#include "Command.h"
#include "Stack_Exp_Command_Factory.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
*   Parses string into a string array.
*   @param: std::string             user input infix expression
*   @return: Array<std::string>      infix expression
*/
Array<string> parse(string infix) {

	std::stringstream input_stream;
	string token;
	std::queue<string> input_items;

	input_stream.clear();
	input_stream.str(infix);
	while (getline(input_stream, token, ' '))
		input_items.push(token);

	// infix array
	Array<string> arr_infix(input_items.size());

	// pop all input_items into infix array
	for (int i = 0; i < arr_infix.size(); i++) {
		arr_infix[i] = input_items.front();
		input_items.pop();
	}

	// return infix expression
	return arr_infix;
}

/**
*   Determines if the input string can be converted into an integer.
*   @param: std::string             input string
*   @return: bool=true               input as int is a valid int
*   @return: bool=false              input as int is an invalid int
*/
bool is_integer(string str) {

	const char * chr_lst = str.c_str();

	char * ptr_to_last_ch;

	int rad = 10;

	long value = std::strtol(chr_lst, &ptr_to_last_ch, rad);

	// if the starting character is invalid (i.e. not a '+', '-', nor a digit)
	if (ptr_to_last_ch == chr_lst) {
		// invalid
		return false;
	}
	else if (*ptr_to_last_ch != '\0') {
		// invalid
		return false;
	}
	else {
		if ((int)value != value) {
			return false;
		}
		else {
			return true;
		}
	}
}

/**
*   Runs through the infix string array and makes sure it is valid.
*   @param: Array<std::string>      infix expression
*   @return: bool=true               input is valid
*   @return: bool=false              input is invalid
*/
bool is_valid(Array<string> & infix) {

	// # of opened parenthesis
	int opened = 0;

	// 0: nothing
	// 1: first-parenthesis
	// 2: second-parenthesis
	// 3: operator
	// 4: operand
	int lst_ch_type = 0;

	// while looping through infix array, check for the following:
	// - balanced parenthesis
	// - proper operand/operator/parenthesis placement
	for (int i = 0; i < infix.size(); i++) {

		// check for integer
		if (is_integer(infix[i])) {

			// invalid format if integer follows a
			// second-parenthesis or an operand
			if (lst_ch_type == 2 || lst_ch_type == 4)
				return false;

			lst_ch_type = 4;
		}
		else if (infix[i].size() == 1) {

			// check for operator or parenthesis
			switch (infix[i][0]) {

			case '(':

				// increment number of opened parenthesis
				opened++;

				// invalid format if first-parenthesis follows a
				// second-parenthesis or an operand
				if (lst_ch_type == 2 || lst_ch_type == 4)
					return false;

				// mark current item as first-parenthesis
				lst_ch_type = 1;

				// get out of the switch statement
				break;

			case ')':

				// decrement number of opened parenthesis
				opened--;

				// invalid format if second-parenthesis is the first
				// item or follows a first-parenthesis or an operator
				if (lst_ch_type == 0 || lst_ch_type == 1 || lst_ch_type == 3)
					return false;

				// mark current item as second-parenthesis
				lst_ch_type = 2;

				// get out of the switch statement
				break;

			case '+':
			case '-':
			case '*':
			case '/':
			case '%':

				// invalid format if any of the above operators is the
				// first item or follows a first-parenthesis or an operator
				if (lst_ch_type == 0 || lst_ch_type == 1 || lst_ch_type == 3)
					return false;

				// mark current item as operator
				lst_ch_type = 3;

				// get out of the switch statement
				break;

			default:

				// if none of the above characters was found, the
				// current item must be an invalid character
				return false;
			}

			// else it is a non-integer item of a size longer than 1
		}
		else {

			// invalid item
			return false;
		}
	}

	// if last item is "(" or some operator,
	// then we have an invalid expression
	if (lst_ch_type == 1 || lst_ch_type == 3)
		return false;

	// if opened is more than zero, we have too many "(",
	// if opened is less than zero, we have too many ")"
	if (opened != 0)
		return false;

	return true;
}

/**
*   Returns operator priority to use for order-of-operations
*   @param: std::string             some operator in string format
*   @return: int                     priority level
*/
int op_priority(std::string op) {

	if (op == "%" || op == "/" || op == "*")
		return 2;
	else if (op == "-" || op == "+")
		return 1;
	else
		return 0;
}

/**
*   Creates and returns a new postfix string array from the input infix string array.
*   @param: Array<std::string>      infix expression
*   @param: Stack_Exp_Command_Factory      factory that creates commands
*   @return: Array<Command*>         postfix expression represented by commands
*/
Array<Command*> infix_to_postfix(Array<string> & infix, Stack_Exp_Command_Factory & factory) {

	// easier to push into than Array
	std::queue<string> enqueue_postfixOP;

	// used to help convert infix to postfix
	Stack<string> pushpop_postfixOP;

	// go through infix item-by-item
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == "(")
			pushpop_postfixOP.push(infix[i]);
		else if (infix[i] == ")") {

			while (pushpop_postfixOP.top() != "(") {
				enqueue_postfixOP.push(pushpop_postfixOP.top());
				pushpop_postfixOP.pop();
			}

			pushpop_postfixOP.pop();
		}
		else if (infix[i] == "+" || infix[i] == "-" || infix[i] == "*" || infix[i] == "/" || infix[i] == "%") {

			// if stack is empty
			if (pushpop_postfixOP.is_empty()) {

				pushpop_postfixOP.push(infix[i]);

			}
			else {

				while (!pushpop_postfixOP.is_empty() &&
					op_priority(pushpop_postfixOP.top()) >= op_priority(infix[i])) {

					enqueue_postfixOP.push(pushpop_postfixOP.top());
					pushpop_postfixOP.pop();
				}

				pushpop_postfixOP.push(infix[i]);
			}
		}
		else
			enqueue_postfixOP.push(infix[i]);
	}

	while (!pushpop_postfixOP.is_empty()) {
		enqueue_postfixOP.push(pushpop_postfixOP.top());
		pushpop_postfixOP.pop();
	}

	Array<Command*> postfix_array(enqueue_postfixOP.size());

	for (int i = 0; i < postfix_array.size(); i++) {

		string item = enqueue_postfixOP.front();
		Command * cmd;
		if (item == "+") {
			cmd = factory.create_add_command();
		}
		else if (item == "-") {
			cmd = factory.create_sub_command();
		}
		else if (item == "*") {
			cmd = factory.create_mul_command();
		}
		else if (item == "/") {
			cmd = factory.create_div_command();
		}
		else if (item == "%") {
			cmd = factory.create_mod_command();
		}
		else {
			cmd = factory.create_num_command(std::stoi(item));
		}

		postfix_array[i] = cmd;

		enqueue_postfixOP.pop();
	}

	return postfix_array;
}

/**
*   Evaluates a postfix string array to some integer and returns it
*   @param: Array<Command*>         postfix expression represented by commands
*   @return: Integer                 final result value from expression
*   @exception: Math_Exception          Some math error while evaluating
*/
int get_val(Array<Command*> & postfix) {

	if (!postfix.size())
		return 0;

	Stack<int> stack;

	for (int i = 0; i < postfix.size(); i++) {
		try {
			postfix[i]->execute(stack);
		}
		catch (std::overflow_error & e) {
			for (int j = i; j < postfix.size(); j++)
				delete postfix[j];
			throw e;
		}

		delete postfix[i];
	}

	int result = stack.top();

	return result;
}

// main
int main(int argc, char * argv[]) {

	// user input expression
	string exp;

	// factory for infix_to_postfix
	Stack_Exp_Command_Factory factory;

	// menu - obtain user input expressions
	cout << "\nWelcome to the Design Pattern Calculator!" << endl;
	cout << "Instructions:" << endl;
	cout << "\t- Type \"QUIT(quit)\" to end your input." << endl;
	cout << "\t- Separate each operator/operand with a space." << endl;
	while (true) {
		cout << "\nPlease enter a mathematical expression: ";

		// user input string
		std::getline(cin, exp);
		if (exp == "QUIT" || exp == "quit")
			break;

		// parse expression into an Array
		Array<string> infix = parse(exp);

		// enqueue valid expression, exception if invalid
		if (is_valid(infix)) {
			// get postfix
			Array<Command*> postfix = infix_to_postfix(infix, factory);

			// check for math errors
			try {

				// get result
				int result = get_val(postfix);

				// print result
				cout << "The result is: " << result << endl;

			}
			catch (std::overflow_error e) {

				// print exception error and notify
				cout << e.what() << endl;
				cout << "(a result was ignored...)" << endl;
			}
		}
		else
			cout << "Invalid expression format: It was ignored." << endl;
	}

	// wait then quit
	cout << "\nThank you for using Calculator!" << endl;
	cin.ignore();
}
