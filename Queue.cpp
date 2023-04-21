#include "Queue.h"
#include "QueueHelper.cpp"

#define BACK_OF_LINE 0
#define DOUBLE 2

/*****************************************************************************
    Constructors/Destructor
*****************************************************************************/
// Time Complexity: O(N), where N is specifed to 1 in this case.
template <class T>
Queue<T>::Queue() : capacity_(1), size_(0) {
    array_ = new T[capacity_];
}

// Time Complexity: O(N), where N is specifed by capacity.
template <class T>
Queue<T>::Queue(const int& capacity) : capacity_(capacity), size_(0) {
    if (capacity_ <= 0) {
        capacity_ = 1;
    }

    array_ = new T[capacity_];
}

// Time Complexity: O(N), where N is the number of elements in other.
template <class T>
Queue<T>::Queue(Queue<T>& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    array_ = new T[capacity_];
    
    deepCopy(array_, other.array_, size_);
}

// Time Complexity: O(1)
template <class T>
Queue<T>::~Queue() {
    memoryManage(array_);
    capacity_ = 1;
    size_ = 0;
}

/*****************************************************************************
    Operator Overload
*****************************************************************************/
// Time Complexity: O(N), where N is the number of elements in other.
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
// Time Complexity: O(N), where N is the number of elements in the queue
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
// Time Complexity: O(N), where N is the number of elements in the queue.
template <class T>
void Queue<T>::pop() {
    if (empty()) {
        std::cout<< "The Queue is empty. failed to execute pop." << '\n';
        return;
    }

    T* temp_array = new T[capacity_];

    int updated_size = size_ - 1;
    deepCopy(temp_array, array_, updated_size);
    size_ = updated_size;

    swap(temp_array, array_);
    memoryManage(temp_array);
}

//Erases and resets the whole queue
// Time Complexity: O(1)
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
// Time Complexity: O(1)
template <class T>
T& Queue<T>::front() const {
    return array_[size_ - 1];
}

//Access back of the line element. DO NOT USE ON EMPTY QUEUE
// Time Complexity: O(1)
template <class T>
T& Queue<T>::back() const {
    return array_[BACK_OF_LINE];
}

/*****************************************************************************
    Data Observation
*****************************************************************************/
// Time Complexity: O(N), where N is the number of element in the queue.
template <class T>
bool Queue<T>::contains(const T& data) const {
    if (empty()) {
        return false;
    }

    for (int i = 0; i < size_; ++i) {
        if (array_[i] == data) {
            return true;
        }
    }

    return false;
}

// Time Complexity: O(1)
template <class T>
bool Queue<T>::empty() const {
    return size_ == 0;
}

// Time Complexity: O(1)
template <class T>
int Queue<T>::capacity() const {
    return capacity_;
}

// Time Complexity: O(1)
template <class T>
int Queue<T>::size() const {
    return size_;
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
// Time Complexity: O(N), where N is the number of elements in the queue.
template <class T>
void Queue<T>::resize_() {
    capacity_ *= DOUBLE;

    T* temp_array = new T[capacity_];
    
    deepCopy(temp_array, array_, size_);
    swap(temp_array, array_);
    memoryManage(temp_array);
}

//emulates scooting but in reality its just copying one over
// Time Complexity: O(N), where N is the number of elemens in the queue.
template <class T>
void Queue<T>::scoot_() {
    T* temp_array = new T[capacity_];

    for (int i = 0; i < size_; ++i) {
        temp_array[i+1] = array_[i];
    }

    swap(temp_array, array_);
    memoryManage(temp_array);
}