#include "safearr.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

class SafeVector: public SafeArray{
    protected:
    int capacity;
    int count = 0;

    public:
    SafeVector(int size): SafeArray(size){
        capacity = size;
    }

    void push_back(int val){
        if (sz==capacity){
            resize(capacity*2);
        }
        arr[sz++] = val;
    }

    int pop_back(){
            if (sz==0){
                throw underflow_error("Underflow error: Can not pop an empty vector");
            }
            if (sz>0 && sz==capacity/4){
                resize(capacity/2);
            }
            sz--;
            return arr[count++];
    }

    int back(){
        if (sz==0){
            throw underflow_error("Underflow error: Can not pop empty vector")
        }
        return arr[sz-1];
    }

    private:
    void resize(int cap){
        int* newarr = new int[cap];
        for (int i=0; i<cap; i++){
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        capacity = cap;
    }
};