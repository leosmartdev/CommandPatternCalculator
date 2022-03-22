////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Subtract.h
//  Date:           10/17/2017
//  Description:    Headers for Subtract class.
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

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Operation_Command.h"

/**
*   @class Subtract_Command
*
*   A type of Binary_Operation_Command that subtracts two numbers.
*/
class Subtract_Command: public Binary_Operation_Command {

    public:
        /// Default constructor.
        Subtract_Command(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          precedence          for implementating order-of-operations
        */
        Subtract_Command(int);

        /**
        *   Subtracts two integers
        *
        *   @param[in]          left                left-hand operand
        *   @param[in]          right               right-hand operand
        *   @return             result              calculated integer
        */
        int evaluate(int, int);
};

#endif
