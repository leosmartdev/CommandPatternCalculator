////////////////////////////////////////////////////////////////////////////////

#ifndef _EXPRESSION_COMMAND_FACTORY_H_
#define _EXPRESSION_COMMAND_FACTORY_H_

#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"

/**
*   @class Expression_Command_Factory
*
*   An interface for factories that construct commands including basic
*   integer operation commands.
*/
class Expression_Command_Factory {

    public:
        /// Default constructor
        Expression_Command_Factory(void) {}

        /// Destructor
        virtual ~Expression_Command_Factory(void) {};

        /// Copy constructor (deleted)
        Expression_Command_Factory(const Expression_Command_Factory &) = delete;

        /// Equals operator (deleted)
        const Expression_Command_Factory & operator = (const Expression_Command_Factory &) = delete;

        /**
        *   Creates and returns a command representing some integer value
        *
        *   @param[in]          value               integer value
        *   @return             number command      command representing a number
        */
        virtual Number_Command * create_number_command(int num) = 0;

        /**
        *   Creates and returns a command representing an addition operator
        *
        *   @return             add command         command representing an addition operator
        */
        virtual Add_Command * create_add_command(void) = 0;

        /**
        *   Creates and returns a command representing a subtraction operator
        *
        *   @return             subtract command    command representing a subtraction operator
        */
        virtual Subtract_Command * create_subtract_command(void) = 0;

        /**
        *   Creates and returns a command representing a multiplcation operator
        *
        *   @return             multiply command    command representing a multiplcation operator
        */
        virtual Multiply_Command * create_multiply_command(void) = 0;

        /**
        *   Creates and returns a command representing a division operator
        *
        *   @return             divide command      command representing a division operator
        */
        virtual Divide_Command * create_divide_command(void) = 0;

        /**
        *   Creates and returns a command representing a modulo operator
        *
        *   @return             modulo command      command representing a modulo operator
        */
        virtual Modulo_Command * create_modulo_command(void) = 0;
};

#endif
