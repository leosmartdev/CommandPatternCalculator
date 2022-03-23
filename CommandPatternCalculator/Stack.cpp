////////////////////////////////////////////////////////////////////////////////

//
// Stack
//
template <typename T>
Stack <T>::Stack (void) :
        data_ (new Array<T>()),
        top_  (-1) {

    //...
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack) :
        data_ (new Array<T>(stack.data_->size())),
        top_  (-1) {

    // if self assignment, ignore
    if (this == &stack)
        return;

    // mimic data members of input stack (by value!)
    *this->data_ = *stack.data_;
    this->top_   =  stack.top_;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void) {

    // call Array destructor
    delete this->data_;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs) {

    // check for self assignment
    if (this == &rhs) {

        // return value this is pointing at
        return * this;
    }

    // mimic data members of rhs stack (by value!)
    *this->data_ = *rhs.data_;
    this->top_   =  rhs.top_;

    // return value this is pointing at
    return * this;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element) {

    //
    // Make space in the array:
    //

    // if top has reached end of array
    if (this->size() >= this->data_->size()) {

        // resize
        this->data_->resize(this->size() + 1);
    }

    //
    // Add element:
    //

    // increment top & add element
    this->data_->set(++this->top_, element);
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void) {

    // exception if empty
    if (this->is_empty())
        throw Stack <T>::empty_exception();

    // decrement top
    this->top_--;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void) {

    // [Note]:  Don't free array memory; chances are the user will
    //          want to put another n elements back into the stack,
    //          and freeing then reallocating n elements every time
    //          clear is called can have heavy impact on performance.

    // reset top
    this->top_ = -1;
}
