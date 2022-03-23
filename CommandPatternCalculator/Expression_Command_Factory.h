////////////////////////////////////////////////////////////////////////////////

#ifndef _EXPRESSION_COMMAND_FACTORY_H_
#define _EXPRESSION_COMMAND_FACTORY_H_

#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"

class Expression_Command_Factory {

    public:
        Expression_Command_Factory(void) {}

        virtual ~Expression_Command_Factory(void) {};

        Expression_Command_Factory(const Expression_Command_Factory &) = delete;

        const Expression_Command_Factory & operator = (const Expression_Command_Factory &) = delete;

        virtual Number_Command * create_number_command(int num) = 0;

        virtual Add_Command * create_add_command(void) = 0;

        virtual Subtract_Command * create_subtract_command(void) = 0;

        virtual Multiply_Command * create_multiply_command(void) = 0;

        virtual Divide_Command * create_divide_command(void) = 0;

        virtual Modulo_Command * create_modulo_command(void) = 0;
};

#endif
