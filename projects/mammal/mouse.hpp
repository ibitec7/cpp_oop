#ifndef MOUSE_H
#define MOUSE_H
#include "mammal.hpp"

using namespace std;

class Mouse: public Mammal{
    public:
    Mouse(int a): Mammal(a){
        cout<<"Mouse is constructed..."<<endl;
    }

    ~Mouse(){
        cout<<"Mouse is destructed"<<endl;
    }

    void Move() const override{
        cout<<"Mouse is moving"<<endl;
    }

    void Speak() const override{
        cout<<"Squeek! Squeek!"<<endl;
    }
};
#endif