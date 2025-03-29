#pragma once
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"
#include "winbgim.h"
class Point
{
protected:
    int X, Y;
    unsigned short  Cvet;

public:
    void Init(int XN, int YN, unsigned short  Color);
    virtual void Show();
    virtual void Hide();
    virtual ~Point() = default;
    void Locat(int &XL, int &YL);
    void Fly(int Cost);
    void SectorColor(int Cost);
};