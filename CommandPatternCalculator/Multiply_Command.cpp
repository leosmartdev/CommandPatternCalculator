////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Multiply_Command.cpp
//  Date:           10/17/2017
//  Description:    Main implementation for Multiply_Command class.
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

// precedence of multiply operator
#define MEDIUM_PRECEDENCE 2

//
//  default constructor
//
Multiply_Command::Multiply_Command() : Binary_Operation_Command(MEDIUM_PRECEDENCE) {

    // nothing else to construct/initialize
}

// Ryan: Why are you using the Factory here? This is not necessary and defeats
// the purpose of the Command pattern.
// Fixed: Changed the overall design so that I don't need to use the Factory here.

//
//  evaluate
//
int Multiply_Command::evaluate(int left, int right) {

    // multiply
    return left * right;
}
