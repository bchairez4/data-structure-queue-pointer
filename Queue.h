/*****************************************************************************
*    Brian Chairez                                                           *
*    Goal: Manual implementation of std::Queue using dynamic arrays.         *
*****************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

// Treating the end of the array as the front of the line. conscious decision. wanna make executions faster than entering.
// Kinda like if you have to walk to the end of the line first to actually queue into it
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
        Queue(const int& capacity);
        Queue(Queue<T>& other);
        ~Queue();
        T& operator=(const Queue<T>& other);
        void push(const T& data);
        void pop();
        void clear();
        T& front() const;
        T& back() const;
        bool contains(const T& data) const;
        bool empty() const;
        int capacity() const;
        int size() const;
};

#endif
