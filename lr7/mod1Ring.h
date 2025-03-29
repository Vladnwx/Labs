#pragma once
#include "mod1Krug.h"
class Ring : public Krug {
protected:
unsigned short  Width;
public:
    void Cring();
    //Ring();
    void Init(int XN, int YN, 
        unsigned short  R, unsigned short Color, unsigned short  Wid);
    virtual void Show();
};