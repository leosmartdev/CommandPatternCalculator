////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Array.h
//  Date:           10/09/2017
//  Description:    Headers for Array class.
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

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring> // for size_t definition

#include "Base_Array.h"

/**
 * @class Array
 *
 * Basic implementation of a standard array class.
 */
template <typename T>
class Array : public Base_Array <T> {

public:
    /// Type definition of the element type.
    typedef T type;

    /// Default constructor.
    Array (void);

    /**
    * Initializing constructor.
    *
    * @param[in]      length        Initial size
    */
    Array (size_t length);

    /**
    * Initializing constructor.
    *
    * @param[in]      length        Initial size
    * @param[in]      fill          Initial value for each element
    */
    Array (size_t length, T fill);

    /**
    * Copy constructor
    *
    * @param[in]     arr         The source array.
    */
    Array (const Array & arr);

    /// Destructor.
    ~Array (void);

    /**
    * Assignment operation
    *
    * @param[in]       rhs      Right-hand side of equal sign
    * @return          Reference to self
    */
    const Array & operator = (const Array & rhs);

    /**
    * Retrieve the maximum size of the array.
    *
    * @return          The maximum size
    */
    size_t max_size (void) const;

    /**
    * Set a new size for the array. If \a new_size is less than the current
    * size, then the array is truncated. If \a new_size if greater then the
    * current size, then the array is made larger and the new elements are
    * not initialized to anything. If \a new_size is the same as the current
    * size, then nothing happens.
    *
    * The array's original contents are preserved regardless of whether the
    * array's size is either increased or decreased.
    *
    * @param[in]       new_size              New size of the array
    */
    void resize (size_t new_size);

private:
    /// Maximum size of the array.
    size_t max_size_;

    /**
     * Doubles the current max size until the current size is smaller.
     *
     * @param[in]     maximum size
     * @param[in]     current size
     * @retval        new maximum size
     */
    int bound_max(size_t max, size_t cur);
};

#include "Array.inl"
#include "Array.cpp"

#endif   // !defined _ARRAY_H_
