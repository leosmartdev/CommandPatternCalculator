////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Binary_Operation_Command.h
//  Date:           10/17/2017
//  Description:    Headers for Binary_Operation_Command class.
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

#ifndef _BINARY_OPERATION_COMMAND_H_
#define _BINARY_OPERATION_COMMAND_H_

#include "Stack.h"
#include "Command.h"
#include "Number_Command.h"

/**
*   @class Binary_Operation_Command
*
*   A type of Command that involves two integers to be evaluated with some
*   operator.
*/
class Binary_Operation_Command: public Command {

    public:
        /// Default constructor
        Binary_Operation_Command(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          precedence          for implementating order-of-operations
        */
        Binary_Operation_Command(int);

        /**
        *   Executes on an input stack by treating it like a calculator
        *   evaluation stack. Top two ints are popped out of the stack and
        *   evaluated. The result is pushed back onto the stack.
        *
        *   @param[in]          evaluation stack    stack used for evaluating a postfix expression
        */
        void execute(Stack<int> &);

        /**
        *   Returns the precedence of some binary operator
        *
        *   @return             precedence          for implementating order-of-operations
        */
        int get_precedence(void);

        // Ryan: Why not just evaluate on two integers rather than Commands here?
        // Fixed: Changed design where integers are evaluated rather than commands

        /**
        *   Evaluates two integers
        *
        *   @param[in]          left                left-hand operand
        *   @param[in]          right               right-hand operand
        *   @return             result              calculated integer
        */
        virtual int evaluate(int, int) = 0;

    protected:
        /// precedence of the binary operator in a typical expression
        int precedence_;
};

#endif
