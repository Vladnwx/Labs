#include "mod1Krug.h"
#include "mod1Point.h"
#include "mod1Ring.h"
#include "winbgim.h"
#include "graphics.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    int d, r;
    Krug TestKrug;
    Ring TestRing;
    d = DETECT;
    initgraph(&d,&r, (char*) "");
    //initgraph(&d,&r, (char*) "c:\\bp\\bgi");
    setbkcolor(80);
    TestKrug.Init(150, 40, 50, 1);
  //  TestRing.Cring(); // в c++ не надо вызывать, т.к. конструктор уже был вызван по умолчанию при создании
    TestRing.Init(450, 80, 90, 50, 10);
    TestKrug.Fly(100);
    TestRing.Fly(60);
    TestKrug.Fly(60);
    TestKrug.SectorColor(100);
    TestRing.SectorColor(60);
    TestKrug.SectorColor(60);
    getch(); // Ожидание нажатия клавиши
    TestKrug.Hide();
    TestRing.Hide();
    getch(); // Ожидание нажатия клавиши
}

//g++ mod2.cpp mod1Krug.cpp mod1Ring.cpp mod1Point.cpp -o mod1.exe