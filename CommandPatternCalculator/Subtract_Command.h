////////////////////////////////////////////////////////////////////////////////

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Operation_Command.h"

class Subtract_Command: public Binary_Operation_Command {

    public:
        Subtract_Command(void);

        Subtract_Command(int);

        int evaluate(int, int);
};

#endif
