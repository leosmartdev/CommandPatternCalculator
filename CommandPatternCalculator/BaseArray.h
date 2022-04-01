////////////////////////////////////////////////////////////////////////////////

#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <cstring> // for uInt definition

typedef unsigned int uInt;

/**
 * @class BaseArray
 *
 * Template Pattern
 */
template <typename T>
class BaseArray {

public:

	// Default constructor.
	BaseArray(void);

	/**
	* Initializing constructor.
	*
	* @param: length        Initial size
	*/
	BaseArray(uInt length);

	/**
	* Initializing constructor.
	*
	* @param: length        Initial size
	* @param: fill          Initial value for each element
	*/
	BaseArray(uInt length, T fill);

	/**
	* Copy constructor
	*
	* @param: arr         The source array.
	*/
	BaseArray(const BaseArray <T> & arr);

	// Destructor.
	~BaseArray(void);

	/**
	* Retrieve the current size of the array.
	*
	* @return: The current size
	*/
	uInt size(void) const;

	/**
	* Get the value at the specified index.
	*
	* @param: index               Zero-based location
	*/
	T & operator [] (uInt index);

	/**
	* @overload
	*/
	const T & operator [] (uInt index) const;

	/**
	* Get the value at the specified index.
	*
	* @param: index                 Zero-based location
	* @return: T at \index
	*/
	T get(uInt index) const;

	/**
	* Set the value at the specified \a index. 
	*
	* @param: index                 Zero-based location
	* @param: value                 New value for T
	*/
	void set(uInt index, T value);

	/**
	* Locate the specified value in the array.
	*
	* @param: ch        Value to search for
	* @return: Index value of the value
	* @return: -1        Value not found
	*/
	int find(T element) const;

	/**
	* @overload
	*
	* This version allows you to specify the start index of the search.
	*
	* @param: T                    Value to search for
	* @param: start                Index to begin search
	* @return: Index value of first occurrence
	* @return: -1                   Value not found
	*/
	int find(T element, uInt start) const;

	/**
	* Test the array for equality.
	*
	* @param: rhs                  second hand side of equal to sign
	* @return: true                 first side is equal to second side
	* @return: false                first side is not equal to second side
	*/
	bool operator == (const BaseArray <T> & rhs) const;

	/**
	* Test the array for inequality.
	*
	* @param: rhs                  second-hand size of not equal to sign
	* @return: true                 first side is not equal to second side
	* @return: false                first size is equal to second side
	*/
	bool operator != (const BaseArray <T> & rhs) const;

	/**
	* Fill the contents of the array.
	*
	* @param: T                    Fill value
	*/
	void fill(T element);

protected:
	// Pointer to the actual data.
	T * _data;

	// Current size of the array.
	uInt _cur_size;
};

// size
template <typename T>
inline
uInt BaseArray <T>::size(void) const {
	return this->_cur_size;
}

#include "BaseArray.cpp"

#endif   // !defined _BASE_ARRAY_H_
