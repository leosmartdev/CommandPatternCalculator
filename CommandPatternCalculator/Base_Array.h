////////////////////////////////////////////////////////////////////////////////

#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <cstring> // for uInt definition

typedef unsigned int uInt;

/**
 * @class Base_Array
 *
 * Template Pattern
 */
template <typename T>
class Base_Array {

public:

	// Default constructor.
	Base_Array(void);

	/**
	* Initializing constructor.
	*
	* @param: length        Initial size
	*/
	Base_Array(uInt length);

	/**
	* Initializing constructor.
	*
	* @param: length        Initial size
	* @param: fill          Initial value for each element
	*/
	Base_Array(uInt length, T fill);

	/**
	* Copy constructor
	*
	* @param: arr         The source array.
	*/
	Base_Array(const Base_Array <T> & arr);

	// Destructor.
	~Base_Array(void);

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
	* @param: rhs                  Right hand side of equal to sign
	* @return: true                 Left side is equal to right side
	* @return: false                Left side is not equal to right side
	*/
	bool operator == (const Base_Array <T> & rhs) const;

	/**
	* Test the array for inequality.
	*
	* @param: rhs                  Right-hand size of not equal to sign
	* @return: true                 Left side is not equal to right side
	* @return: false                Left size is equal to right side
	*/
	bool operator != (const Base_Array <T> & rhs) const;

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
uInt Base_Array <T>::size(void) const {
	return this->_cur_size;
}

#include <stdexcept>         // for std::out_of_bounds exception

// default length
#define DEFAULT_SIZE 10

// Base_Array - default constructor
template <typename T>
Base_Array <T>::Base_Array(void) : _data(new T[DEFAULT_SIZE]), _cur_size(DEFAULT_SIZE) 
{
	//...
}

// Base_Array - length constructor
template <typename T>
Base_Array <T>::Base_Array(uInt length) : _data(new T[DEFAULT_SIZE]), _cur_size(DEFAULT_SIZE) 
{
	// if length is valid, adjust size
	if (length > 0) {

		// reallocate memory
		delete[] this->_data;
		this->_data = new T[length];

		// set size
		this->_cur_size = length;
	}
}

// Base_Array - fill constructor
template <typename T>
Base_Array <T>::Base_Array(uInt length, T fill) : _data(new T[DEFAULT_SIZE]), _cur_size(DEFAULT_SIZE) 
{
	// if length is valid, adjust size
	if (length > 0) {

		// reallocate memory
		delete[] this->_data;
		this->_data = new T[length];

		// set size
		this->_cur_size = length;
	}

	// fill array
	this->fill(fill);
}

// Base_Array - copy constructor
template <typename T>
Base_Array <T>::Base_Array(const Base_Array & array) : _data(new T[array.size()]), _cur_size(array.size()) 
{
	// copy elements and fill array
	for (uInt i = 0; i < this->_cur_size; i++) {
		this->_data[i] = array[i];
	}
}

// ~Array
template <typename T>
Base_Array <T>::~Base_Array(void) 
{
	// release data from memory
	delete[] this->_data;
}

// operator []
template <typename T>
T & Base_Array <T>::operator [] (uInt index) 
{
	// exception if out of bounds
	if (index < 0 || index >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	// return element
	return this->_data[index];
}

// operator []
template <typename T>
const T & Base_Array <T>::operator [] (uInt index) const 
{
	// exception if out of bounds
	if (index < 0 || index >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	// return element
	return this->_data[index];
}

// get
template <typename T>
T Base_Array <T>::get(uInt index) const 
{
	// exception if out of bounds
	if (index < 0 || index >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	// return element
	return this->_data[index];
}

// set
template <typename T>
void Base_Array <T>::set(uInt index, T value) 
{
	// exception if out of bounds
	if (index < 0 || index >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	// set element
	this->_data[index] = value;
}

// find (value)
template  <typename T>
int Base_Array <T>::find(T value) const 
{
	// refer to find(value,uInt)
	return this->find(value, 0);
}

// find (value, uInt)
template <typename T>
int Base_Array <T>::find(T value, uInt start) const 
{
	// exception if out of bounds
	if (start < 0 || start >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	// linear search
	for (uInt i = start; i < this->_cur_size; i++) {

		// found
		if (this->_data[i] == value) {
			return i;
		}
	}

	// not found
	return -1;
}

// operator ==
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const 
{
	// check for self assignment
	if (this == &rhs) {
		return true;
	}

	// different lengths means not equal
	if (rhs.size() != this->size()) {
		return false;
	}

	// linear search
	for (uInt i = 0; i < this->_cur_size; i++) {

		// elements do not match at this index
		if (this->_data[i] != rhs[i]) {
			return false;
		}
	}

	// arrays have identical content
	return true;
}

// operator !=
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const 
{
	// check for self assignment
	if (this == &rhs) {
		return false;
	}

	// different lengths means not equal
	if (rhs.size() != this->size()) {
		return true;
	}

	// linear search
	for (uInt i = 0; i < this->_cur_size; i++) {

		// elements do not match at this index
		if (this->_data[i] != rhs[i]) {
			return true;
		}
	}

	// arrays have identical content
	return false;
}

// fill
template <typename T>
void Base_Array <T>::fill(T value) 
{
	// fill array
	for (uInt i = 0; i < this->_cur_size; i++) {
		this->_data[i] = value;
	}
}

#endif   // !defined _BASE_ARRAY_H_
