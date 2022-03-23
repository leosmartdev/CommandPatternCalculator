////////////////////////////////////////////////////////////////////////////////

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Stack.h"

class Command {

    public:
        Command(void) {}

        virtual ~Command(void) {};

        Command(const Command &) = delete;

        const Command & operator = (const Command &) = delete;

        virtual void execute(Stack<int> &) = 0;
};

#endif
