#include "mod1Point.h"

void Point::Init(int XN, int YN, std::string Color)
{
    X = XN;
    Y = YN;
    Cvet = Color;
}

void Point::Show() {}
void Point::Hide() {}

void Point::Locat(int XL, int YL)
{
    XL = X;
    YL = Y;
}

void Point::Fly(int Cost)
{
    Show();
    Randomize();
    Repeat();
}