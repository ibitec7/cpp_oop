#include <iostream>
#include <cassert>
#include "stack.hpp"

using namespace std;

class RAStack: public Stack{
    private:
    int capacity;
    string *arr = nullptr;

    public:
    RAStack(): Stack(), capacity{2}, arr {new string[2]}{

    }

    ~RAStack(){
        delete[] arr;
    }

    void push(string item) override {
        if (N == capacity){
            resize(2*capacity);
        }
        arr[N++] = item;
    }

    string pop() override {
        assert(N > 0);
        if (N > 0 && N == capacity/4){
            resize(capacity/2);
        }
        return arr[--N];

    }

    bool empty(){
        return N == 0;
    }

    private:
    void resize(int newcap){
        string* newarr = new string[newcap];
        for (int i=0; i<N; i++){
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        capacity = newcap;
    }
};

int main(){
    RAStack a1 = RAStack();
    a1.push(string("Hello"));
    a1.push(string("World"));
    a1.push(string("Good"));
    a1.push(string("Day"));

    while (!a1.empty()){
        cout<<a1.pop()<<endl;
    }
}