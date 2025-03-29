#pragma once
#include <iostream> 
#include <string>

// Класс для работы со строками как со стандартным типом данных
class Stroka
{
    char* str; // Указатель на динамически выделенную память -> нужен деструктор
public:
    // Описание функций
    Stroka(const char* = "");                    // Конструктор с параметром
    Stroka(const Stroka&);            // Конструктор копирования
    ~Stroka();                       // Деструктор
    Stroka &operator=(const Stroka&); // Оператор присваивания
    Stroka &operator+(const Stroka&); // Оператор сложения (конкатенации)
    int operator==(const Stroka &) const;    // Оператор сравнения
    int dlina();                       // Метод для определения длины
    void vvod();                       // Метод ввода
    void vyvod();                      // Метод вывода

    friend std::ostream &operator<<(std::ostream &, const Stroka&);
    friend std::istream &operator>>(std::istream &, Stroka &);


};