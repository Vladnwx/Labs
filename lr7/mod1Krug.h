#pragma once
#include <string>
#include "mod1Point.h"
class Krug : public Point {
protected:
    int Radius;
public:
    void Init(int XN, int YN, std::string R, std::string Color);
    virtual void Show();
    virtual void Hide();
};