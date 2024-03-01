#include <iostream>
#include "tool.hpp"
#include "scissor.hpp"
#include "rock.hpp"
#include "paper.hpp"

using namespace std;

int main(){
    // Example main function
    // You may add your own testing code if you like
    Scissor s1(5);
    Paper p1(7);
    Rock r1(15);
    if (s1.fight(p1)){
        cout<<"Scissor Wins"<<endl;
    }
    if (p1.fight(s1)){
        cout<<"Paper Wins"<<endl;
    }
}