#ifndef MOD2STROKA_H
#define MOD2STROKA_H
// #include <iostream>
// #include <cstring>

// Класс для работы со строками как со стандартным типом данных
class Stroka
{
    char str[80]; // Массив для хранения символов строки
public:
    // Описание функций
    Stroka(char *);                    // Конструктор с параметром
    Stroka() {};                       // Конструктор по умолчанию
    Stroka(const Stroka &);            // Конструктор копирования
    Stroka &operator=(const Stroka &); // Оператор присваивания
    Stroka &operator+(const Stroka &); // Оператор сложения (конкатенации)
    int operator==(const Stroka &);    // Оператор сравнения
    int dlina();                       // Метод для определения длины
    void vvod();                       // Метод ввода
    void vyvod();                      // Метод вывода
};
#endif