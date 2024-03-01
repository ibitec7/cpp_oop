#include "queue.hpp"
#include  <cassert>

using namespace std;

class RAQueue: public Queue{
    private:
    int capacity;
    string* arr = nullptr;
    int count = 0;

    public:
    RAQueue(): Queue(), capacity{2}, arr {new string[2]}{
        
    }

    ~RAQueue(){
        delete[] arr;
    }

    void enqueue(string item) override {
        if (N == capacity){
            resize(2*capacity);
        }
        arr[N++] = item;
    }

    string dequeue() override {
        assert(N > 0);
        if (N > 0 && N == capacity/4){
            resize(capacity/2);
        }
        N--;
        return arr[count++];
    }

    bool empty(){
        return N == 0;
    }

    int size(){
        return N;
    }

    private:
    void resize(int newcap){
        string* newarr = new string[newcap];
        for(int i=0; i<N; i++){
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        capacity = newcap;
    }
};

int main(){
    RAQueue a1 = RAQueue();
    a1.enqueue(string("Hello"));
    a1.enqueue(string("World"));
    a1.enqueue(string("Good"));
    a1.enqueue(string("Day"));

    while (!a1.empty()){
        cout<<a1.dequeue()<<endl;
    }
}