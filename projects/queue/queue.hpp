#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

class Queue{
    protected:
    int N = 0;

    public:
    Queue() = default;

    virtual ~Queue() = 0;
    
    virtual void enqueue(string item) = 0;

    virtual string dequeue() = 0;

    virtual int size() = 0;

    virtual bool empty() = 0;
};

#endif