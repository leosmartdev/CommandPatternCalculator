////////////////////////////////////////////////////////////////////////////////

#ifndef _STACK_H_
#define _STACK_H_

#include <exception>

#include "Array.h"

typedef unsigned int uInt;

/**
 * @class Stack
 *
 * Template Pattern
 */
template <typename T>
class Stack {

public:

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the stack is empty.
     */
    class empty_exception : public std::exception {
		public:
			// Default constructor.
			empty_exception (void) : std::exception () {}
    };

    // Default constructor.
    Stack (void);

    // Copy constructor.
    Stack (const Stack & s);

    // Destructor.
    ~Stack (void);

    /**
     * Assignment operator
     *
     * @param     rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Stack & operator = (const Stack & rhs);

    /**
     * Push a new \a element onto the stack.
     *
     * @param     element       Element to add to the list
     */
    void push (T element);

    /**
     * Remove the top-most element from the stack.
     *
     * @exception      empty_exception    The stack is empty.
     */
    void pop (void);

    /**
     * Get the top-most element on the stack.
     *
     * @return         Element on top of the stack.
     * @exception      empty_exception    The stack is empty
     */
    T top (void) const;

    /**
     * Test if the stack is empty
     *
     * @retval         true          The stack is empty
     * @retval         false         The stack is not empty
     */
    bool is_empty (void) const;

    /**
     * Number of element on the stack.
     *
     * @return         Size of the stack.
     */
    uInt size (void) const;

    // Remove all elements from the stack.
    void clear (void);

private:
  // add member variable here

  // Pointer to stack data stored in an Array
  Array <T> * _data;

  // Top index of current stack
  int _top;
};

// size
template <typename T>
inline
uInt Stack <T>::size(void) const {

	// top index + 1 is the number of elements
	//  in the stack
	return this->_top + 1;
}

// top
template <typename T>
inline
T Stack <T>::top(void) const {

	// exception if empty
	if (this->is_empty())
		throw Stack <T>::empty_exception();

	// return last element
	return this->_data->get(this->_top);
}

// is_empty
template <typename T>
inline
bool Stack <T>::is_empty(void) const 
{
	// stack empty when top is -1
	return this->_top < 0;
}

#include "Stack.cpp"

#endif   // !defined _STACK_H_
