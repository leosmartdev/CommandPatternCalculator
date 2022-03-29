////////////////////////////////////////////////////////////////////////////////

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "BaseArray.h"

typedef unsigned int uInt;

/**
 * @class Array
 * 
 * Template Pattern
 */
template <typename T>
class Array : public BaseArray <T> {

public:

	// Default constructor.
	Array(void);

	/**
	* Initializing constructor.
	*
	* @param: length        Initial size
	*/
	Array(uInt length);

	/**
	* Initializing constructor.
	*
	* @param: length        Initial size
	* @param: fill          Initial value for each element
	*/
	Array(uInt length, T fill);

	/**
	* Copy constructor
	*
	* @param: arr         The source array.
	*/
	Array(const Array & arr);

	// Destructor.
	~Array(void);

	/**
	* Assignment operation
	*
	* @param: rhs      Right-hand side of equal sign
	* @return: Reference to self
	*/
	const Array & operator = (const Array & rhs);

	/**
	* Retrieve the maximum size of the array.
	*
	* @return: The maximum size
	*/
	uInt max_size(void) const;

	/**
	* Set a new size for the array.
	*
	* @param: new_size              New size of the array
	*/
	void resize(uInt new_size);

private:
	// Maximum size of the array.
	uInt _max_size;

	/**
	 * Doubles the current max size until the current size is smaller.
	 *
	 * @param: maximum size
	 * @param: current size
	 * @return: new maximum size
	 */
	uInt bound_max(uInt max, uInt cur);
};

// max_size
template <typename T>
inline
uInt Array <T>::max_size(void) const 
{
	return this->_max_size;
}

#include <stdexcept>         // for std::out_of_bounds exception

// default max length
#define DEFAULT_MAX_SIZE 10

// Array - default constructor
template <typename T>
Array <T>::Array(void) : BaseArray <T>(), _max_size(DEFAULT_MAX_SIZE) 
{
	delete[] this->_data;
	this->_data = new T[DEFAULT_MAX_SIZE];
	this->_cur_size = 0;
}

// Array - length constructor
template <typename T> 
Array <T>::Array(uInt length) : BaseArray <T>(DEFAULT_MAX_SIZE), _max_size(DEFAULT_MAX_SIZE) 
{
	// resize
	if (length >= 0)
		this->resize(length);
}

// Array (uInt, value)
template <typename T>
Array <T>::Array(uInt length, T fill) : BaseArray <T>(DEFAULT_MAX_SIZE), _max_size(DEFAULT_MAX_SIZE) 
{
	// resize
	if (length >= 0)
		this->resize(length);

	// fill array
	this->fill(fill);
}

// Array (const Array &)
template <typename T>
Array <T>::Array(const Array & array) : BaseArray <T>(), _max_size(array.max_size()) 
{
	delete[] this->_data;
	this->_data = new T[array.max_size()];
	this->_cur_size = array.size();

	// copy elements and fill array
	for (uInt i = 0; i < this->_cur_size; i++) {
		this->_data[i] = array[i];
	}
}

// ~Array
template <typename T>
Array <T>::~Array(void) 
{
	// BaseArray destructor will take care of this
}

// operator =
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs) 
{
	// check for self assignment
	if (this == &rhs) {
		// return value this is pointing at
		return *this;
	}

	// release current values from memory
	delete[] this->_data;

	// re-init
	this->_data = new T[rhs.max_size()];
	this->_cur_size = rhs.size();
	this->_max_size = rhs.max_size();

	// copy elements and fill array
	for (uInt i = 0; i < this->_cur_size; i++) {
		this->_data[i] = rhs[i];
	}

	// return value this is pointing at
	return *this;
}

// resize
template <typename T>
void Array <T>::resize(uInt new_size) 
{
	// if invalid new size
	if (new_size < 0) {
		// New size must be greater than 0. Resize ignored.
		return;
	}

	// if new size is larger than max
	if (new_size > this->_max_size) {
		// double the current max size until
		// the new size fits
		int new_max = this->bound_max(this->_max_size, new_size);

		// init array with new max size
		T * tmp = new T[new_max];

		// copy old array into bigger
		uInt i = 0;
		for (i = 0; i < this->_cur_size; i++) {
			tmp[i] = this->_data[i];
		}

		// delete old array
		delete[] this->_data;

		// set bigger array
		this->_data = tmp;
		this->_cur_size = new_size;
		this->_max_size = new_max;
		return;
	}

	// if new size is larger/smaller than the current
	if (new_size != this->_cur_size) {
		this->_cur_size = new_size;
	}
}

// bound_max (private)
template <typename T>
uInt Array <T>::bound_max(uInt max, uInt cur) {

	// double the current max size until the new size fits
	uInt new_max = max;
	while (cur > new_max) {
		new_max *= 2;
	}

	return new_max;
}

#endif   // !defined _ARRAY_H_
