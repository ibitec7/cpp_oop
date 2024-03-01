#include "queue.h"
#ifndef LLQUEUE_H
#define LLQUEUE_H

using namespace std;

class LLQueue: public Queue{
    private:
        struct Node{
            string data;
            Node* next;
        };
        Node *first = nullptr;

    public:
        LLQueue() = default;

        ~LLQueue(){
            while (first != nullptr){
                Node* second = first->next;
                delete first;
                first = second;
            }
        }

        void enqueue(string item) override {
            if (first == nullptr){
                first = new Node {item, nullptr};
                return;
            }
            else{
                Node* current = first;
                while (current->next != nullptr){
                    current = current->next;
                }
                current->next = new Node {item, nullptr};
                N++;
            }
        }

        string dequeue() override {
            Node* second = first->next;
            string data = first->data;
            delete first;
            first = second;
            return data;
        }

        bool empty(){
            return first == nullptr;
        }

        int size() override {
            return N;
        }
};

int main(){
    LLQueue a = LLQueue();
    a.enqueue("Hello");
    a.enqueue("World");
    a.enqueue("My");
    a.enqueue("Name");
    a.enqueue("Is");
    a.enqueue("Ibrahim");

    while (!a.empty()){
        cout<<a.dequeue()<<endl;
    }
}

#endif