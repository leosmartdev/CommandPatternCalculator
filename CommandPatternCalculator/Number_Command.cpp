////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Number.cpp
//  Date:           10/17/2017
//  Description:    Main implementation for Number class.
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

#include "Number_Command.h"

//
//  constructor
//
Number_Command::Number_Command() : number_ (0) {

    // nothing else to construct/initialize
}

//
//  number constructor
//
Number_Command::Number_Command(int num) : number_ (num) {

    // nothing else to construct/initialize
}

//
//  execute
//
void Number_Command::execute(Stack<int> & stack) {

    // push self's int value onto stack
    stack.push(this->evaluate());
}

//
//  evaluate
//
int Number_Command::evaluate() {

    // just return the int value this command represents
    return this->number_;
}
