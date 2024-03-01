#ifndef ROCK_H
#define ROCK_H

#include "tool.hpp"

using namespace std;

class Rock: public Tool{
    public:
    Rock(int n){
        setStrength(n);
        type = 'r';
    }

    bool fight(Tool a){
        if (a.showType() == 's'){
            strength*=2;
            return true;
        }
        else if (a.showType() == 'p'){
            strength/=2;
            return false;
        }
        else{
            return false;
        }
    }
};

#endif