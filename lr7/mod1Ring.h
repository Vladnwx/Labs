#pragma once
#include <string>
#include "mod1Krug.h"
class Ring : public Krug {
protected:
    std::string Width;
public:
    void Cring();
    void Init(int XN, int YN, std::string R, std::string Color, std::string Wid);
    virtual void Show();
};