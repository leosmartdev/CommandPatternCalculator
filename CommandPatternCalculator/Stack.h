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

// include the inline files
// #include "Stack.inl"
//
// size
//
template <typename T>
inline
uInt Stack <T>::size(void) const {

	// top index + 1 is the number of elements
	//  in the stack
	return this->_top + 1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top(void) const {

	// exception if empty
	if (this->is_empty())
		throw Stack <T>::empty_exception();

	// return last element
	return this->_data->get(this->_top);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty(void) const {

	// stack empty when top is -1
	return this->_top < 0;
}


// Stack
template <typename T>
Stack <T>::Stack(void) : _data(new Array<T>()), _top(-1) {
	//...
}

// Stack
template <typename T>
Stack <T>::Stack(const Stack & stack) : _data(new Array<T>(stack._data->size())), _top(-1) {

	// if self assignment, ignore
	if (this == &stack)
		return;

	// mimic data members of input stack (by value!)
	*this->_data = *stack._data;
	this->_top = stack._top;
}

// ~Stack
template <typename T>
Stack <T>::~Stack(void) {

	// call Array destructor
	delete this->_data;
}

// operator =
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs) {

	// check for self assignment
	if (this == &rhs) {
		return *this;
	}

	// mimic data members of rhs stack (by value!)
	*this->_data = *rhs._data;
	this->_top = rhs._top;

	return *this;
}

// push
template <typename T>
void Stack <T>::push(T element) {

	// Make space in the array:
	// if top has reached end of array
	if (this->size() >= this->_data->size()) {

		// resize
		this->_data->resize(this->size() + 1);
	}

	// Add element:
	// increment top & add element
	this->_data->set(++this->_top, element);
}

// pop
template <typename T>
void Stack <T>::pop(void) {

	// exception if empty
	if (this->is_empty())
		throw Stack <T>::empty_exception();

	// decrement top
	this->_top--;
}

// clear
template <typename T>
void Stack <T>::clear(void) {

	// reset top
	this->_top = -1;
}


#endif   // !defined _STACK_H_
