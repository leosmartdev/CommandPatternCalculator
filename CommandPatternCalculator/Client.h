////////////////////////////////////////////////////////////////////////////////

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
#include <string>

#include "Array.h"
#include "Command.h"
#include "Stack_Expression_Command_Factory.h"

class Client {

    public:
        void run();

    private:
        Array<std::string> parse(std::string);

        bool is_integer(std::string);

        bool is_valid(Array<std::string> &);

        int get_precedence(std::string);

        Array<Command*> infix_to_postfix(Array<std::string> &,
            Stack_Expression_Command_Factory &);

        int evaluate(Array<Command*> &);
};

#endif   // !defined _CLIENT_H_
