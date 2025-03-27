#ifndef MOD4STROKA_H
#define MOD4STROKA_H

// Класс для работы со строками как со стандартным типом данных
class Stroka
{
    char* str; // Указатель на динамически выделенную память -> нужен деструктор
public:
    // Описание функций
    Stroka(char *);                    // Конструктор с параметром
    Stroka() {};                       // Конструктор по умолчанию
    Stroka(const Stroka&);            // Конструктор копирования
    ~Stroka();                       // Деструктор
    Stroka &operator=(const Stroka&); // Оператор присваивания
    Stroka &operator+(const Stroka&); // Оператор сложения (конкатенации)
    int operator==(const Stroka &);    // Оператор сравнения
    int dlina();                       // Метод для определения длины
    void vvod();                       // Метод ввода
    void vyvod();                      // Метод вывода
};
#endif