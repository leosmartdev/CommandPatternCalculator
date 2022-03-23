////////////////////////////////////////////////////////////////////////////////

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Operation_Command.h"

class Add_Command: public Binary_Operation_Command {

    public:
        Add_Command(void);

        Add_Command(int);

        int evaluate(int, int);
};

#endif
