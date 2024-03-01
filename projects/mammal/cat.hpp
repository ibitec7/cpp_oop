#ifndef CAT_H
#define CAT_H
#include "mammal.hpp"

using namespace std;

class Cat: public Mammal{
    public:
    Cat(int a): Mammal(a){
        cout<<"Cat is constructed..."<<endl;
    }

    ~Cat(){
        cout<<"Cat is destructed"<<endl;
    }

    void Move() const override{
        cout<<"Cat is moving"<<endl;
    }

    void Speak() const override{
        cout<<"Meow! Meow!"<<endl;
    }
};
#endif