////////////////////////////////////////////////////////////////////////////////

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Stack.h"

/**
*   @class Command
*
*   An interface for simple commands that can execute over an evaluation stack.
*/
class Command {

    public:
        /// Default constructor
        Command(void) {}

        /// Destructor (virtual)
        virtual ~Command(void) {};

        /// Copy constructor (deleted)
        Command(const Command &) = delete;

        /// Equals operator (deleted)
        const Command & operator = (const Command &) = delete;

        /**
        *   Executes on an input stack by treating it like a calculator
        *   evaluation stack.
        *
        *   @param[in]          evaluation stack    stack used for evaluating a postfix expression
        */
        virtual void execute(Stack<int> &) = 0;
};

#endif
