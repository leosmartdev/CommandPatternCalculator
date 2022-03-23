////////////////////////////////////////////////////////////////////////////////

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Divide_Command
*
*   A type of Binary_Operation_Command that divides two numbers.
*/
class Divide_Command: public Binary_Operation_Command {

    public:
        /// Default constructor.
        Divide_Command(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          precedence          for implementating order-of-operations
        */
        Divide_Command(int);

        /**
        *   Divides two integers
        *
        *   @param[in]          left                left-hand operand
        *   @param[in]          right               right-hand operand
        *   @return             result              calculated integer
        *   @exception          overflow_error      denominator is zero
        */
        int evaluate(int, int);
};

#endif
