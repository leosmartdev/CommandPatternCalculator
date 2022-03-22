////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Subtract.cpp
//  Date:           10/17/2017
//  Description:    Main implementation for Subtract class.
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

#include "Stack_Expression_Command_Factory.h"

// precedence of subtract operator
#define LOW_PRECEDENCE 1

//
//  default constructor
//
Subtract_Command::Subtract_Command() : Binary_Operation_Command(LOW_PRECEDENCE) {

    // nothing else to construct/initialize
}

//
//  evaluate
//
int Subtract_Command::evaluate(int left, int right) {

    // subtract
    return left - right;
}
