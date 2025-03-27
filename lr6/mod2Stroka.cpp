#include <iostream>
#include <cstring>

#include "mod2Stroka.h"

//Реализация функций

// Конструктор с параметром
Stroka::Stroka(char *string)
{
    strcpy(str, string); // копирование
}

// Конструктор копирования
Stroka::Stroka(const Stroka &s)
{
    strcpy(str, s.str);
}

// Оператор присваивания
Stroka &Stroka::operator=(const Stroka &s)
{
    strcpy(str, s.str);
    return *this;
}

// Оператор сложения (конкатенации)
Stroka &Stroka::operator+(const Stroka &s)
{
    strcat(str, s.str);
    return *this;
}

// Оператор сравнения
int Stroka::operator==(const Stroka &s)
{
    if ((strcmp(str, s.str)) == 0)
        return 1;
    else
        return 0;
}

// Метод для определения длины
int Stroka::dlina()
{
    return strlen(str);
}

// Метод ввода
void Stroka::vvod()
{
    std::cin >> str;
}

// Метод вывода
void Stroka::vyvod()
{
    std::cout << str;
}