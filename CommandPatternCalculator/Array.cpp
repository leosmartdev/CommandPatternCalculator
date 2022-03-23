////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>         // for std::out_of_bounds exception

// default max length
#define DEFAULT_MAX_SIZE 10

//
// Array - default constructor
//
template <typename T>
Array <T>::Array (void) :
        Base_Array <T> (),
        max_size_ (DEFAULT_MAX_SIZE) {

    // Overrule Base_Array default constructor because we
    // don't know what the default size of the base array is
    // from this cpp file.
    delete [] this->data_;
    this->data_ = new T[DEFAULT_MAX_SIZE];
    this->cur_size_ = 0;
}

//
// Array - length constructor
//
template <typename T>
Array <T>::Array (size_t length) :
        Base_Array <T> (DEFAULT_MAX_SIZE),
        max_size_ (DEFAULT_MAX_SIZE) {

    // resize
    if (length >= 0)
        this->resize(length);
}

//
// Array (size_t, value)
//
template <typename T>
Array <T>::Array (size_t length, T fill) :
        Base_Array <T> (DEFAULT_MAX_SIZE),
        max_size_ (DEFAULT_MAX_SIZE) {

    // resize
    if (length >= 0)
        this->resize(length);

    // fill array
    this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array) :
        Base_Array <T> (),
        max_size_ (array.max_size()) {

    // overule Base_Array default constructor because we want 'max_size_'
    // amount of memory slots reserved instead of 'cur_size_' amount
    delete [] this->data_;
    this->data_ = new T[array.max_size()];
    this->cur_size_ = array.size();

    // copy elements and fill array
    for (size_t i = 0; i < this->cur_size_; i++) {
        this->data_[i] = array[i];
    }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void) {

    // Base_Array destructor will take care of this
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs) {

    // check for self assignment
    if (this == &rhs) {

        // return value this is pointing at
        return * this;
    }

    // release current values from memory
    delete [] this->data_;

    // re-init
    this->data_     = new T[rhs.max_size()];
    this->cur_size_ = rhs.size();
    this->max_size_ = rhs.max_size();

    // copy elements and fill array
    for (size_t i = 0; i < this->cur_size_; i++) {
        this->data_[i] = rhs[i];
    }

    // return value this is pointing at
    return * this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size) {

    // if invalid new size
    if (new_size < 0) {

        // New size must be greater than 0. Resize ignored.
        return;
    }

    // if new size is larger than max
    if (new_size > this->max_size_) {

        // double the current max size until
        // the new size fits
        int new_max = this->bound_max(this->max_size_, new_size);

        // init array with new max size
        T * tmp = new T[new_max];

        // copy old array into bigger
        size_t i = 0;
        for (i = 0; i < this->cur_size_; i++) {
            tmp[i] = this->data_[i];
        }

        // delete old array
        delete [] this->data_;

        // set bigger array
        this->data_ = tmp;
        this->cur_size_ = new_size;
        this->max_size_ = new_max;
        return;
    }

    // if new size is larger/smaller than the current
    if (new_size != this->cur_size_) {

        // simply change the variable
        // (memory allocated already based on max size)
        this->cur_size_ = new_size;
    }
}

//
// bound_max (private)
//
template <typename T>
int Array <T>::bound_max (size_t max, size_t cur) {

    // double the current max size until
    // the new size fits
    int new_max = max;
    while (cur > new_max) {
        new_max *= 2;
    }

    // return new max
    return new_max;
}
