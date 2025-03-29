#include "mod1Ring.h"

void Ring::Init(int XN, int YN, std::string R, std::string Color, std::string Wid)
{
    Width = Wid;
    Krug::Init(XN, YN, R, Color);
}

void Cring();

void Ring::Show(){
    Krug::Show();
    SetFillStyle (10, GetBkColor);
    Pieslice(X, Y, 90, 320, Radius - std::stoi(Width));
}

