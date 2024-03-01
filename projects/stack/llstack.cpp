#ifndef LLSTACK_H
#define LLSTACK_H
#include "stack.hpp"
#include <string>

using namespace std;

class LLStack: public Stack{
    private:
    struct Node{
        string data;
        Node* next;
    };
    Node *first = nullptr;

    public:
    LLStack() = default;

    ~LLStack(){
        while (first != nullptr){
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    void push(string item){
        Node* second = first;
        first = new Node{item, second};
        N++;
    }

    string pop(){
        Node* second = first->next;
        string item = first->data;
        delete first;
        first = second;
        N--;
        return item;
    }

    bool empty(){
        return first == nullptr;
    }
    
};

int main(){
    LLStack a1 = LLStack();
    a1.push(string("Hello"));
    a1.push(string("World"));
    a1.push(string("Good"));
    a1.push(string("Day"));

    while (!a1.empty()){
        cout<<a1.pop()<<endl;
    }
}

#endif