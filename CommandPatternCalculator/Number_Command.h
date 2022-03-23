////////////////////////////////////////////////////////////////////////////////

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Command.h"
#include "Stack.h"

/**
*   @class Number_Command
*
*   A type of Command that holds an integer value.
*/
class Number_Command: public Command {

    public:
        /// Default constructor.
        Number_Command(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          number              store some integer value
        */
        Number_Command(int);

        /**
        *   Executes on an input stack by treating it like a calculator
        *   evaluation stack. Stored integer of self is pushed onto the stack
        *
        *   @param[in]          evaluation stack    stack used for evaluating a postfix expression
        */
        void execute(Stack<int> &);

        /**
        *   Returns int value of stored number
        *
        *   @return             number              stored int number
        */
        int evaluate(void);

    private:
        /// stored number of a typical expression
        int number_;
};

#endif
