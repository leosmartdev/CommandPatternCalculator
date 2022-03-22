////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Add_Command.cpp
//  Date:           10/17/2017
//  Description:    Main implementation for Add_Command class.
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
#include "Add_Command.h"

// precedence of add operator
#define LOW_PRECEDENCE 1

//
//  default constructor
//
Add_Command::Add_Command() : Binary_Operation_Command(LOW_PRECEDENCE) {

    // nothing else to construct/initialize
}

//
//  evaluate
//
int Add_Command::evaluate(int left, int right) {

    // add
    return left + right;
}
