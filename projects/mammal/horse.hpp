#ifndef HORSE_H
#define HORSE_H
#include "mammal.hpp"

using namespace std;

class Horse: public Mammal{
    public:
    Horse(int a): Mammal(a){
        cout<<"Horse is constructed..."<<endl;
    }

    ~Horse(){
        cout<<"Horse is destructed"<<endl;
    }

    void Move() const override{
        cout<<"Horse is moving"<<endl;
    }

    void Speak() const override{
        cout<<"Whee! Whee!"<<endl;
    }
};
#endif