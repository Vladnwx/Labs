#include <iostream>
#include <cstring>
#include "mod1Stroka.h"
#include <string>
#include <locale>
#include <clocale>

// Конструктор с параметром
Stroka::Stroka(const char *string)
{ // std::cout << "\nКонструктор с параметром";
    str = new char[strlen(string) + 1];
    strcpy(str, string);
}

// Конструктор копирования
Stroka::Stroka(const Stroka &s)
{ // std::cout << "\nКонструктор копирования";
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}

// Деструктор
Stroka::~Stroka()
{ //  std::cout << "\nДеструктор";
    delete[] str;
}

// Оператор присваивания
Stroka &Stroka::operator=(const Stroka &s)
{ // std::cout << "\nОператор присваивания";
    if (this != &s)
    {
        delete[] str;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    return *this;
}

// Оператор сложения (конкатенации)
Stroka &Stroka::operator+(const Stroka &s)
{ // std::cout << "\nконкатенация";
    int new_size = dlina() + strlen(s.str) + 1;
    char *new_ptr = new char[new_size];
    strcpy(new_ptr, str);
    strcat(new_ptr, s.str);
    return *this;
}

// Оператор сравнения
int Stroka::operator==(const Stroka &s) const
{ //  std::cout << "\nсравнение";
    return strcmp(str, s.str) == 0;
}

// Метод для определения длины
int Stroka::dlina()
{ // std::cout << "\nдлина";
    return strlen(str);
}

// Метод ввода
void Stroka::vvod()
{
    const size_t MAX_INPUT = 256;     // Максимальный размер ввода
    char buffer[MAX_INPUT + 1] = {0}; // Временный буфер

    std::cout << "\nВведите строку: ";
    std::cin.getline(buffer, MAX_INPUT);
    delete[] str;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
}

// Метод вывода
void Stroka::vyvod()
{ // std::cout << "\nвывод";
    std::cout << str;
}

// Перегрузка оператора вывода (<<)
std::ostream &operator<<(std::ostream &os, const Stroka &s)
{
    os << s.str;
    return os;
}

// Оператор ввода (>>)
std::istream &operator>>(std::istream &is, Stroka &s)
{
    const size_t MAX_INPUT = 256;     // Максимальный размер ввода
   is.getline(s.str, MAX_INPUT); // русские буквы не читает((

    return is;
   // is >> s.str;
    //std::getline(is, s.str); //Тут нужно передавать String или преобразовывать его в стринг
}
