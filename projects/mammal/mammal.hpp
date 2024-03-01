#include <iostream>
#ifndef MAMMAL_H
#define MAMMAL_H

using namespace std;


class Mammal{
    protected:
        int itsAge;
        
    public:
        Mammal(int a) : itsAge(a) {
        cout << "Mammal constructor..." << endl;
        }
        ~Mammal(void) {
        cout << "Mammal destructor..." << endl;
        }
        virtual void Move() const {
        cout << "Mammal moves a step!" << endl;
        }
        virtual void Speak() const {
        cout << "What does a mammal speak? Mammilian!" << endl;
        }

};
#endif