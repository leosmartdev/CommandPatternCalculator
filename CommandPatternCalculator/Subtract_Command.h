////////////////////////////////////////////////////////////////////////////////

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Subtract_Command
*
*   A type of Binary_Operation_Command that subtracts two numbers.
*/
class Subtract_Command: public Binary_Operation_Command {

    public:
        /// Default constructor.
        Subtract_Command(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          precedence          for implementating order-of-operations
        */
        Subtract_Command(int);

        /**
        *   Subtracts two integers
        *
        *   @param[in]          left                left-hand operand
        *   @param[in]          right               right-hand operand
        *   @return             result              calculated integer
        */
        int evaluate(int, int);
};

#endif
