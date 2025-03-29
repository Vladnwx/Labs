#include "mod1Krug.h"
void Krug::Init(int XN, int YN, 
    unsigned short R, unsigned short Color)
{
    Point::Init(XN, YN, Color);
    Radius = R;
    Show();
}

void Krug::Show()
{
    setcolor(Cvet);
    setfillstyle (1, Cvet);
    pieslice(X, Y, 0, 320, Radius);
}

void Krug::Hide()
{
    setcolor(getbkcolor());
    setfillstyle (1, getbkcolor());
    pieslice(X, Y, 0, 320, Radius);
}
