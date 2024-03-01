#include <iostream>
#include "cat.hpp"
#include "dog.hpp"
#include "mouse.hpp"
#include "horse.hpp"
#include "mammal.hpp"

using namespace std;

int main() {
    Mammal* theArray[5];
    Mammal* ptr;
    int choice, i;
    for (i = 0; i<5; i++) {
    cout << "(1)dog (2)cat (3)horse (4)mouse: ";
    cin >> choice;
    switch (choice) {
        case 1: 
        ptr = new Dog(3);
        break;
        case 2: 
        ptr = new Cat(4); 
        break;
        case 3: ptr = 
        new Horse(10); 
        break;
        case 4: 
        ptr = new Mouse(2); 
        break;
        default: 
        ptr = new Mammal(5); 
        break;
    }
    theArray[i] = ptr;
    }
    for (i=0;i<5;i++)
    theArray[i]->Speak();
    // Always free dynamically allocated objects
    for (i=0;i<5;i++)
    delete theArray[i];

}