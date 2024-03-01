#ifndef DOG_H
#define DOG_H
#include "mammal.hpp"

using namespace std;


class Dog: public Mammal{
    public:
    Dog(int a): Mammal(a){
        cout<<"Dog is constructed..."<<endl;
    }

    ~Dog(void){
        cout<<"Dog is destructed..."<<endl;
    }

    void Move() const override{
        cout<<"Dog is moving"<<endl;
    }

    void Speak() const override{
        cout<<"Whoof! Whoof!"<<endl;
    }

    void WagTail(){
        cout<<"Wagging Tail!"<<endl;
    }
};

#endif

