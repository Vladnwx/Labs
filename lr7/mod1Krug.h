#pragma once
#include <string>
#include "mod1Point.h"
class Krug : public Point {
protected:
unsigned short  Radius;
public:
    void Init(int XN, int YN, 
        unsigned short  R, unsigned short Color);
        void Show() override;
        void Hide() override;
};