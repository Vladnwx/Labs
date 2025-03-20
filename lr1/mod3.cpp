// Задача 3

#include <iostream>
#include <windows.h>

int A,B;

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    int a=2, b=5;

    void obmen1(int, int);
    void obmen2(int*, int*);
    void obmen3(int&, int&);

    std::cout<< "до обмена 1 : a="<<a<<" b="<<b<<std::endl;
    obmen1(a, b);
    a=A;
    b=B;
    std::cout<< "после обмена 1 : a="<<a<<" b="<<b<<std::endl;
    
    std::cout<< "до обмена 2 : a="<<a<<" b="<<b<<std::endl;
    obmen2(&a, &b);
    std::cout<< "после обмена 2 : a="<<a<<" b="<<b<<std::endl;
    
    std::cout<< "до обмена 3 : a="<<a<<" b="<<b<<std::endl;
    obmen3(a, b);
    std::cout<< "после обмена 3 : a="<<a<<" b="<<b<<std::endl;
    return 0;
}

void obmen1(int x, int y){
    int temp = x;
    x=y;
    y=temp;
    A = x;
    B = y;
}

void obmen2(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void obmen3(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}