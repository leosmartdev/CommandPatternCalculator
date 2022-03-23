////////////////////////////////////////////////////////////////////////////////

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Number_Command: public Command {

    public:
        Number_Command(void);

        Number_Command(int);

        void execute(Stack<int> &);

        int evaluate(void);

    private:
        int number_;
};

#endif
