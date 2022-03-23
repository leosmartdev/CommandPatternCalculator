////////////////////////////////////////////////////////////////////////////////

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring> // for size_t definition

#include "Base_Array.h"

template <typename T>
class Array : public Base_Array <T> {

public:
    typedef T type;

    Array (void);

    Array (size_t length);

    Array (size_t length, T fill);

    Array (const Array & arr);

    ~Array (void);

    const Array & operator = (const Array & rhs);

    size_t max_size (void) const;

    void resize (size_t new_size);

private:
    size_t max_size_;

    int bound_max(size_t max, size_t cur);
};

#include "Array.inl"
#include "Array.cpp"

#endif   // !defined _ARRAY_H_
