#ifndef SCISSOR_H
#define SCISSOR_H

#include "tool.hpp"

using namespace std;

class Scissor: public Tool{
    public:
    Scissor(int n){
        setStrength(n);
        type = 'r';
    }

    bool fight(Tool a){
        if (a.showType() == 'p'){
            strength*=2;
            return true;
        }
        else if (a.showType() == 'r'){
            strength/=2;
            return false;
        }
        else{
            return false;
        }
    }
};

#endif