////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Add_Command.h
//  Date:           10/17/2017
//  Description:    Headers for Add_Command class.
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

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Add_Command
*
*   A type of Binary_Operation_Command that adds two numbers.
*/
class Add_Command: public Binary_Operation_Command {

    public:
        /// Default constructor.
        Add_Command(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          precedence          for implementating order-of-operations
        */
        Add_Command(int);

        /**
        *   Adds two integers
        *
        *   @param[in]          left                left-hand operand
        *   @param[in]          right               right-hand operand
        *   @return             result              calculated integer
        */
        int evaluate(int, int);
};

#endif
