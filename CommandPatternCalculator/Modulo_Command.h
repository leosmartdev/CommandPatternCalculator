////////////////////////////////////////////////////////////////////////////////

#ifndef _MODULO_COMMAND_H_
#define _MODULO_COMMAND_H_

#include "Binary_Operation_Command.h"

class Modulo_Command: public Binary_Operation_Command {

    public:
        Modulo_Command(void);

        Modulo_Command(int);

        int evaluate(int, int);
};

#endif
