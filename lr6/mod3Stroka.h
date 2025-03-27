#ifndef MOD3STROKA_H
#define MOD3STROKA_H

// Класс для работы со строками как со стандартным типом данных
class Stroka
{
    char str[80] ={0}; // Массив для хранения символов строки
public:
    // Описание функций
    Stroka(const char *);                    // Конструктор с параметром
    Stroka() {};                       // Конструктор по умолчанию
    Stroka(const Stroka &);            // Конструктор копирования
    Stroka &operator=(const Stroka &); // Оператор присваивания
    Stroka &operator+(const Stroka &); // Оператор сложения (конкатенации)
    int operator==(const Stroka &);    // Оператор сравнения
    int dlina();                       // Метод для определения длины
    int dlina(const char *string);
    void vvod();                       // Метод ввода
    void vyvod();                      // Метод вывода
};
#endif