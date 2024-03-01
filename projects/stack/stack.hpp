#include <iostream>

using namespace std;

class Stack{
    protected:
    int N;

    public:

    Stack() = default;

    virtual void push(string a){}

    virtual string pop(){}

    virtual bool isEmpty(){}

    virtual int size(){}
    
};