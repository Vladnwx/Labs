#include <iostream>
#include <cstring>

#include "mod4Stroka.h"

// Реализация функций

// Конструктор с параметром
Stroka::Stroka(char *string)
{
    // std::cout << "\nКонструктор с параметром";
    if (string)
    {
        str = new char[strlen(string) + 1];
        strcpy(str, string);
    }
    else
    {
        str = new char[1];
        str[0] = '\0';
    }
}

// Конструктор копирования
Stroka::Stroka(const Stroka &s)
{
    // std::cout << "\nКонструктор копирования";
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}

// Деструктор
Stroka::~Stroka()
{
    //  std::cout << "\nДеструктор";
    delete[] str;
}

// Оператор присваивания
Stroka &Stroka::operator=(const Stroka &s)
{
    // std::cout << "\nОператор присваивания";
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
{
    std::cout << "\nконкатенация";
    // Вычисляем общий размер
    int new_size = dlina() + strlen(s.str) + 1;
    char* new_ptr = new char[new_size];
    strcpy(new_ptr, str);
    strcat(new_ptr, s.str);
    s(*new_ptr);
    return *this;
}

// Оператор сравнения
int Stroka::operator==(const Stroka &s)
{
    //  std::cout << "\nсравнение";
    return strcmp(str, s.str) == 0;
}

// Метод для определения длины
int Stroka::dlina()
{
    // std::cout << "\nдлина";
    return strlen(str);
}

// Метод ввода
void Stroka::vvod()
{
    const size_t MAX_INPUT = 256;     // Максимальный размер ввода
    char buffer[MAX_INPUT + 1] = {0}; // Временный буфер

    std::cout << "\nВведите строку: ";
    std::cin >> buffer;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
}

// Метод вывода
void Stroka::vyvod()
{
    // std::cout << "\nвывод";
    std::cout << str;
}