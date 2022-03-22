////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Modulo_Command.cpp
//  Date:           10/17/2017
//  Description:    Main implementation for Modulo_Command class.
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

#include <stdexcept>
#include "Stack_Expression_Command_Factory.h"

// precedence of modulus operator
#define MEDIUM_PRECEDENCE 2

//
//  default constructor
//
Modulo_Command::Modulo_Command() : Binary_Operation_Command(MEDIUM_PRECEDENCE) {

    // nothing else to construct/initialize
}

// Ryan: Why are you using the Factory here? This is not necessary and defeats
// the purpose of the Command pattern.
// Fixed: Changed the overall design so that I don't need to use the Factory here.

//
//  evaluate
//
int Modulo_Command::evaluate(int left, int right) {

    // Ryan: What about division by 0 here?
    // Fixed: Added exception handling for math errors

    // exception if right-hand number is zero
    if (!right)
        throw std::overflow_error("Invalid Denominator: Mod by zero exception.");

    // mod'em
    return left % right;
}
