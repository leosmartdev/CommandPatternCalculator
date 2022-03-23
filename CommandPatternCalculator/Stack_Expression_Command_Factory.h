////////////////////////////////////////////////////////////////////////////////

#ifndef _STACK_EXPRESSION_COMMAND_FACTORY_H_
#define _STACK_EXPRESSION_COMMAND_FACTORY_H_

#include "Expression_Command_Factory.h"
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"

class Stack_Expression_Command_Factory: public Expression_Command_Factory {

    public:
        Number_Command * create_number_command(int num);

        Add_Command * create_add_command(void);

        Subtract_Command * create_subtract_command(void);

        virtual Multiply_Command * create_multiply_command(void);

        Divide_Command * create_divide_command(void);

        Modulo_Command * create_modulo_command(void);
};

#endif
