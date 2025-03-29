#pragma once
#include <string>
class Point
{
protected:
    int X, Y;
    std::string Cvet;

public:
    void Init(int XN, int YN, std::string Color);
    virtual void Show();
    virtual void Hide();
    void Locat(int XL, int YL);
    void Fly(int Cost);
};