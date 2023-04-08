#include "Queue.h"
#include "QueueHelper.cpp"

#define BACK_OF_LINE 0
#define DOUBLE 2

/*****************************************************************************
    Constructors/Destructor
*****************************************************************************/
template <class T>
Queue<T>::Queue() : capacity_(1), size_(0) {
    array_ = new T[capacity_];
}

template <class T>
Queue<T>::Queue(const int& capacity) : capacity_(capacity), size_(0) {
    array_ = new T[capacity];
}

template <class T>
Queue<T>::Queue(Queue<T>& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    array_ = new T[capacity_];
    
    deepCopy(array_, other.array_, size_);
}

template <class T>
Queue<T>::~Queue() {
    clear();
}

/*****************************************************************************
    Operator Overload
*****************************************************************************/
template <class T>
T& Queue<T>::operator=(const Queue<T>& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    array_ = new T[capacity_];

    deepCopy(array_, other.array_, size_);
}

/*****************************************************************************
    Data Modification
*****************************************************************************/
//Pushes to the beginning of the line, causes scooting.
template <class T>
void Queue<T>::push(const T& data) {
    if (size_ >= capacity_ - 1) {
        resize_();
    }
    //scoot the array to make room for the back of the line
    scoot_();

    //add to the beginning of the list and increment size counter
    array_[BACK_OF_LINE] = data;
    ++size_;
}

//Removes from the front of the line
template <class T>
void Queue<T>::pop() {
    if (empty()) {
        return;
    }

    T* temp_array = new T[capacity_];

    int updated_size = size_ - 1;
    deepCopy(temp_array, array_, updated_size);
    size_ = updated_size;

    swap(temp_array, array_);
    memoryManage(temp_array);
}

//Erases the whole Queue
template <class T>
void Queue<T>::clear() {
    if (empty()) {
        return;
    }

    memoryManage(array_);
    capacity_ = 1;
    size_ = 0;
}

//Access front of the line element. DO NOT USE ON EMPTY QUEUE
template <class T>
T& Queue<T>::front() const {
    return array_[size_ - 1];
}

//Access back of the line element. DO NOT USE ON EMPTY QUEUE
template <class T>
T& Queue<T>::back() const {
    return array_[BACK_OF_LINE];
}

/*****************************************************************************
    Data Observation
*****************************************************************************/
template <class T>
bool Queue<T>::contains(const T& data) const {
    for (int i = 0; i < size_; ++i) {
        if (array_[i] == data) {
            return true;
        }
    }

    return false;
}

template <class T>
bool Queue<T>::empty() const {
    return size_ == 0;
}

template <class T>
int Queue<T>::capacity() const {
    return capacity_;
}

template <class T>
int Queue<T>::size() const {
    return size_;
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
template <class T>
void Queue<T>::resize_() {
    capacity_ *= DOUBLE;

    T* temp_array = new T[capacity_];
    
    deepCopy(temp_array, array_, size_);
    swap(temp_array, array_);
    memoryManage(temp_array);
}

//emulates scooting but in reality its just copying one over
template <class T>
void Queue<T>::scoot_() {
    T* temp_array = new T[capacity_];

    for (int i = 0; i < size_; ++i) {
        temp_array[i+1] = array_[i];
    }

    swap(temp_array, array_);
    memoryManage(temp_array);
}
