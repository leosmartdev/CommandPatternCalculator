////////////////////////////////////////////////////////////////////////////////

#ifndef _BINARY_OPERATION_COMMAND_H_
#define _BINARY_OPERATION_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include "Number_Command.h"

class Binary_Operation_Command: public Command {

    public:
        Binary_Operation_Command(void);

        Binary_Operation_Command(int);

        void execute(Stack<int> &);

        int get_precedence(void);

        virtual int evaluate(int, int) = 0;

    protected:
        int precedence_;
};

#endif
