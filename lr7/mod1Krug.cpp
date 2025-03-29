#include "mod1Krug.h"
void Krug::Init(int XN, int YN, std::string R, std::string Color)
{
    Point::Init(XN, YN, Color);
    Radius = R;
    Show();
}

void Krug::Show()
{
    SetColor(Cvet);
    SetFillStyle (1, Cvet);
    Pieslice(X, Y, 0, 320, Radius);
}

void Krug::Hide()
{
    SetColor(GetBkColor);
    SetFillStyle (1, GetBkColor);
    Pieslice(X, Y, 0, 320, Radius);
}
