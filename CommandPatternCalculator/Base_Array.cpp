////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>         // for std::out_of_bounds exception

// default length
#define DEFAULT_SIZE 10

//
// Base_Array - default constructor
//
template <typename T>
Base_Array <T>::Base_Array (void) :
        data_ (new T[DEFAULT_SIZE]),
        cur_size_ (DEFAULT_SIZE) {

    //...
}

//
// Base_Array - length constructor
//
template <typename T>
Base_Array <T>::Base_Array (size_t length) :
        data_ (new T[DEFAULT_SIZE]),
        cur_size_ (DEFAULT_SIZE) {

    // if length is valid, adjust size
    if (length > 0) {

        // reallocate memory
        delete [] this->data_;
        this->data_ = new T[length];

        // set size
        this->cur_size_ = length;
    }
}

//
// Base_Array - fill constructor
//
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill) :
        data_ (new T[DEFAULT_SIZE]),
        cur_size_ (DEFAULT_SIZE) {

    // if length is valid, adjust size
    if (length > 0) {

        // reallocate memory
        delete [] this->data_;
        this->data_ = new T[length];

        // set size
        this->cur_size_ = length;
    }

    // fill array
    this->fill(fill);
}

//
// Base_Array - copy constructor
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array) :
        data_ (new T[array.size()]),
        cur_size_ (array.size()) {

    // copy elements and fill array
    for (size_t i = 0; i < this->cur_size_; i++) {
        this->data_[i] = array[i];
    }
}

//
// ~Array
//
template <typename T>
Base_Array <T>::~Base_Array (void) {

    // release data from memory
    delete [] this->data_;
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index) {

    // exception if out of bounds
    if (index < 0 || index >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // return element
    return this->data_[index];
}

//
// operator []
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const {

    // exception if out of bounds
    if (index < 0 || index >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // return element
    return this->data_[index];
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const {

    // exception if out of bounds
    if (index < 0 || index >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // return element
    return this->data_[index];
}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value) {

    // exception if out of bounds
    if (index < 0 || index >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // set element
    this->data_[index] = value;
}

//
// find (value)
//
template  <typename T>
int Base_Array <T>::find (T value) const {

    // refer to find(value,size_t)
    return this->find(value, 0);
}

//
// find (value, size_t)
//
template <typename T>
int Base_Array <T>::find (T value, size_t start) const {

    // exception if out of bounds
    if (start < 0 || start >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // linear search
    for (size_t i=start; i<this->cur_size_; i++) {

        // found
        if (this->data_[i] == value) {
            return i;
        }
    }

    // not found
    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const {

    // check for self assignment
    if (this == &rhs) {
        return true;
    }

    // different lengths means not equal
    if (rhs.size() != this->size()) {
        return false;
    }

    // linear search
    for (size_t i=0; i<this->cur_size_; i++) {

        // elements do not match at this index
        if (this->data_[i] != rhs[i]) {
            return false;
        }
    }

    // arrays have identical content
    return true;
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const {

    // check for self assignment
    if (this == &rhs) {
        return false;
    }

    // different lengths means not equal
    if (rhs.size() != this->size()) {
        return true;
    }

    // linear search
    for (size_t i=0; i<this->cur_size_; i++) {

        // elements do not match at this index
        if (this->data_[i] != rhs[i]) {
            return true;
        }
    }

    // arrays have identical content
    return false;
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value) {

    // fill array
    for (size_t i = 0; i < this->cur_size_; i++) {
        this->data_[i] = value;
    }
}
