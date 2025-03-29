#include "mod1Ring.h"

void Ring::Init(int XN, int YN, unsigned short R, unsigned short Color, unsigned short Wid)
{
    Width = Wid;
    Krug::Init(XN, YN, R, Color);
}

void Ring::Show(){
    Krug::Show();
    setfillstyle (10, getbkcolor());
    pieslice(X, Y, 90, 320, Radius - Width);
}

