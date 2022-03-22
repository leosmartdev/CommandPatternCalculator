////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Stack_Expression_Command_Factory.h
//  Date:           10/17/2017
//  Description:    Headers for Stack_Expression_Command_Factory class.
//                  A concrete factory class.
//
////////////////////////////////////////////////////////////////////////////////
//
//  Honor Pledge:
//
//  I pledge that I have neither given nor received any help on this assignment.
//
//  ibsardar
//
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2017 Copyright Holder All Rights Reserved.
//
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

/**
*   @class Stack_Expression_Command_Factory
*
*   A type of Expression_Command_Factory that creates commands for basic
*   calculator integer operations.
*/
class Stack_Expression_Command_Factory: public Expression_Command_Factory {

    public:
        /**
        *   Creates and returns a command representing some integer value
        *
        *   @param[in]          value               integer value
        *   @return             number command      command representing a number
        */
        Number_Command * create_number_command(int num);

        /**
        *   Creates and returns a command representing an addition operator
        *
        *   @return             add command         command representing an addition operator
        */
        Add_Command * create_add_command(void);

        /**
        *   Creates and returns a command representing a subtraction operator
        *
        *   @return             subtract command    command representing a subtraction operator
        */
        Subtract_Command * create_subtract_command(void);

        /**
        *   Creates and returns a command representing a multiplcation operator
        *
        *   @return             multiply command    command representing a multiplcation operator
        */
        virtual Multiply_Command * create_multiply_command(void);

        /**
        *   Creates and returns a command representing a division operator
        *
        *   @return             divide command      command representing a division operator
        */
        Divide_Command * create_divide_command(void);

        /**
        *   Creates and returns a command representing a modulo operator
        *
        *   @return             modulo command      command representing a modulo operator
        */
        Modulo_Command * create_modulo_command(void);
};

#endif
