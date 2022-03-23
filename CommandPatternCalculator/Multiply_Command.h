////////////////////////////////////////////////////////////////////////////////

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Operation_Command.h"

class Multiply_Command: public Binary_Operation_Command {

    public:
        Multiply_Command(void);

        Multiply_Command(int);

        int evaluate(int, int);
};

#endif
