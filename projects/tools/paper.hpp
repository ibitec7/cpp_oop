#ifndef PAPE_H
#define PAPER_H

#include "tool.hpp"

using namespace std;

class Paper: public Tool{
    public:
    Paper(int n){
        setStrength(n);
        type = 'p';
    }

    bool fight(Tool a){
        if (a.showType() == 'r'){
            strength*=2;
            return true;
        }
        else if (a.showType() == 's'){
            strength/=2;
            return false;
        }
        else{
            return false;
        }
    }
};

#endif