/*****************************************************************************
*    Brian Chairez                                                           *
*    Goal: Manual implementation of std::Queue using dynamic arrays.         *
*    Progess: Basic implementation and functions are complete                *
*****************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

// Treating the end of the array as the front of the line. conscious decision. Want to make executions faster than entering.
// Kind of like if you have to walk to the end of the line first to actually queue into it
//  Queue == F.I.F.O.
template <class T>
class Queue {
    private:
        int capacity_;
        int size_;
        T* array_;

        void resize_();
        void scoot_();
    public:
        Queue();
        Queue(int& capacity);
        Queue(Queue<T>& other);
        ~Queue();
        T& operator=(const Queue<T>& other);
        void push(T& data);
        void pop();
        void clear();
        T& front() const;
        T& back() const;
        bool contains(T& data) const;
        bool empty() const;
        int capacity() const;
        int size() const;
};

#endif