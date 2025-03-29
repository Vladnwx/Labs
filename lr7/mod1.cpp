#include "mod1Krug.h"
#include "mod1Ring.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    int d, r;
    Krug TestKrug;
    Ring TestRing;
    d = detect;
    initgraph(&d,&r,"c:\bp\bgi");
    SetBKColor(80);
    TestKrug.Init(150, 40, 50, 1);
    TestRing.Cring();
    TestRing.Init(450, 80, 90, 50, 10);
    TestKrug.Fly(100);
    TestRing.Fly(60);
    TestKrug.Fly(60);
    getch(); // Ожидание нажатия клавиши
    TestKrug.Hide();
    TestRing.Hide();
    getch(); // Ожидание нажатия клавиши
}
