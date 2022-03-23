////////////////////////////////////////////////////////////////////////////////

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Operation_Command.h"

class Divide_Command: public Binary_Operation_Command {

    public:
        Divide_Command(void);

        Divide_Command(int);

        int evaluate(int, int);
};

#endif
