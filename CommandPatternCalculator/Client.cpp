////////////////////////////////////////////////////////////////////////////////

//
// (resources)
//
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <stdexcept>

#include "Array.h"
#include "Stack.h"
#include "Client.h"
#include "Command.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//  run
void Client::run() {

    // user input expression
    string exp;

    // factory for infix_to_postfix
    StackExpressionCommandFactory factory;

    // menu - obtain user input expressions
    cout << "\nWelcome to the Multiple Expression Calculator! (using design patterns)" << endl;
    cout << "Instructions:" << endl;
    cout << "\t- Type \"quit\" on a seperate line to end your input." << endl;
    cout << "\t- Separate each operator/operand with a space." << endl;
    while(true) {
		cout << "\nPlease enter a mathematical expression: ";

        // user input string
        std::getline(cin, exp);
        if (exp == "QUIT" || exp == "quit")
            break;

        // parse expression into an Array
        Array<string> infix = this->parse(exp);

        // enqueue valid expression, exception if invalid
		if (this->is_valid(infix)) {
			// get postfix
			Array<Command*> postfix = this->infix_to_postfix(infix, factory);

			// check for math errors
			try {

				// get result
				int result = this->evaluate(postfix);

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

//
//  parse
//
Array<string> Client::parse(string infix) {

    // helper variables
    std::stringstream ss;
    string token;
    std::queue<string> items;

    // tokenize string
    ss.clear();
    ss.str(infix);
    while(getline(ss, token, ' '))
        items.push(token);

    // resultant infix array
    Array<string> infix_array(items.size());

    // pop all queue items into infix array
    for (int i=0; i<infix_array.size(); i++) {
        infix_array[i] = items.front();
        items.pop();
    }

    // return infix expression
    return infix_array;
}

//
//  is_integer
//
bool Client::is_integer(string str) {

    // convert string to char array for compatability with strtol
    const char * character_list = str.c_str();

    // this pointer will be used with the above character array
    // like the reading head in a turing machine
    char * ptr_to_last_consumed_character;

    // number's base
    // (10 is for base10 as 2 is for binary/base2)
    int radix = 10;

    // try to convert the character array to a base10 int
    long value = std::strtol(character_list, &ptr_to_last_consumed_character, radix);

    // if the starting character is invalid
    // (i.e. not a '+', '-', nor a digit)
    if (ptr_to_last_consumed_character == character_list) {

        // invalid number
        return false;

    // if the string begins with a number but is
    // interrupted by some invalid character before
    // reaching the end of the string
    } else if (*ptr_to_last_consumed_character != '\0') {

        // invalid number
        return false;

    // all characters are valid number characters
    } else {

        // if the number is larger than or smaller than the
        // maximum or minimum possible values of an integer
        if ((int)value != value) {

            // invalid integer
            return false;

        // if the number is within the bounds of the maximum
        // or minimum possible values of an integer
        } else {

            // valid integer
            return true;
        }
    }
}

//
//  is_valid
//
bool Client::is_valid(Array<string> & infix) {

    // # of opened parenthesis
    int opened = 0;

    // 0: nothing
    // 1: left-parenthesis
    // 2: right-parenthesis
    // 3: operator
    // 4: operand
    int last_type = 0;

    // while looping through infix array, check for the following:
    // - balanced parenthesis
    // - proper operand/operator/parenthesis placement
    for (int i=0; i<infix.size(); i++) {

        // check for integer
        if (this->is_integer(infix[i])) {

            // invalid format if integer follows a
            // right-parenthesis or an operand
            if (last_type == 2 || last_type == 4)
                return false;

            // mark current item as operand
            last_type = 4;

        // check for a 1 character string
        } else if (infix[i].size() == 1) {

            // check for operator or parenthesis
            switch (infix[i][0]) {

                case '(':

                    // increment number of opened parenthesis
                    opened++;

                    // invalid format if left-parenthesis follows a
                    // right-parenthesis or an operand
                    if (last_type == 2 || last_type == 4)
                        return false;

                    // mark current item as left-parenthesis
                    last_type = 1;

                    // get out of the switch statement
                    break;

                case ')':

                    // decrement number of opened parenthesis
                    opened--;

                    // invalid format if right-parenthesis is the first
                    // item or follows a left-parenthesis or an operator
                    if (last_type == 0 || last_type == 1 || last_type == 3)
                        return false;

                    // mark current item as right-parenthesis
                    last_type = 2;

                    // get out of the switch statement
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '%':

                    // invalid format if any of the above operators is the
                    // first item or follows a left-parenthesis or an operator
                    if (last_type == 0 || last_type == 1 || last_type == 3)
                        return false;

                    // mark current item as operator
                    last_type = 3;

                    // get out of the switch statement
                    break;

                default:

                    // if none of the above characters was found, the
                    // current item must be an invalid character
                    return false;
            }

        // else it is a non-integer item of a size longer than 1
        } else {

            // invalid item
            return false;
        }
    }

    // if last item is "(" or some operator,
    // then we have an invalid expression
    if (last_type == 1 || last_type == 3)
        return false;

    // if opened is more than zero, we have too many "(",
    // if opened is less than zero, we have too many ")"
    if (opened != 0)
        return false;

    return true;
}

//
//  get_precedence
//
int Client::get_precedence(std::string op) {

    if (op == "%" || op == "/" || op == "*")
        return 2;
    else if (op == "-" || op == "+")
        return 1;
    else
        return 0;
}

//
//  infix_to_postfix
//
Array<Command*> Client::infix_to_postfix(Array<string> & infix,
        StackExpressionCommandFactory & factory) {

    // easier to push into than Array
    std::queue<string> postfix_queue;

    // used to help convert infix to postfix
    Stack<string> postfix_stack;

    // go through infix item-by-item
    for (int i=0; i<infix.size(); i++) {
        if (infix[i] == "(")
            postfix_stack.push(infix[i]);
        else if (infix[i] == ")") {

            while (postfix_stack.top() != "(") {
                postfix_queue.push(postfix_stack.top());
                postfix_stack.pop();
            }

            postfix_stack.pop();
        }
        else if (infix[i] == "+" || infix[i] == "-" || infix[i] == "*" || infix[i] == "/" || infix[i] == "%") {

            // if stack is empty
            if (postfix_stack.is_empty()) {
			
				postfix_stack.push(infix[i]);

            } else {

                while (!postfix_stack.is_empty() &&
                        this->get_precedence(postfix_stack.top()) >= this->get_precedence(infix[i])) {

                    postfix_queue.push(postfix_stack.top());
                    postfix_stack.pop();
                }

                postfix_stack.push(infix[i]);
            }
        }
        else
            postfix_queue.push(infix[i]);
    }

    while (!postfix_stack.is_empty()){
        postfix_queue.push(postfix_stack.top());
        postfix_stack.pop();
    }

    Array<Command*> postfix_array(postfix_queue.size());

    for (int i=0; i<postfix_array.size(); i++) {

        string item = postfix_queue.front();
        Command * cmd;
        if (item == "+") {
            cmd = factory.create_add_command();
        } else if (item == "-") {
            cmd = factory.create_subtract_command();
        } else if (item == "*") {
            cmd = factory.create_multiply_command();
        } else if (item == "/") {
            cmd = factory.create_divide_command();
        } else if (item == "%") {
            cmd = factory.create_modulo_command();
        } else {
            cmd = factory.create_number_command(std::stoi(item));
        }

        postfix_array[i] = cmd;

        postfix_queue.pop();
    }

    return postfix_array;
}

//
//  evaluate
//
int Client::evaluate(Array<Command*> & postfix) {

    if (!postfix.size())
        return 0;

    Stack<int> stack;

    for (int i=0; i<postfix.size(); i++) {
        try {
            postfix[i]->execute(stack);
        } catch (std::overflow_error & e) {
            for (int j=i; j<postfix.size(); j++)
                delete postfix[j];
            throw e;
        }

        delete postfix[i];
    }

    int result = stack.top();

    return result;
}
