#include <iostream>
#ifndef TOOL_H
#define TOOL_H

class Tool{
    protected:
    int strength;
    char type;

    public:
    virtual void setStrength(int n){
        strength = n;
    }

    char showType(){
        return type;
    }
};

#endif