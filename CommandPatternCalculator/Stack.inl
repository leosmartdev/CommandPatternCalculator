////////////////////////////////////////////////////////////////////////////////

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const {

    // top index + 1 is the number of elements
    //  in the stack
    return this->top_ + 1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const {

    // exception if empty
    if (this->is_empty())
        throw Stack <T>::empty_exception();

    // return last element
    return this->data_->get(this->top_);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const {

    // stack empty when top is -1
    return this->top_ < 0;
}
