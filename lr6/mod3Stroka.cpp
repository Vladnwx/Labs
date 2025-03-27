#include <iostream>
#include <cstring>

#include "mod3Stroka.h"

// Реализация функций

// Конструктор с параметром
Stroka::Stroka(const char *string)
{
    // std::cout << "Копирование\n";

    if (string == NULL) // Проверка что указатель не нулевой
    {
        // std::cout << "Указатель нулевой\n";
        return;
    }
    // Проверим что строки можно скопировать, т.е str1 меньше str2
    size_t dlinaStr1 = dlina();
    size_t dlinaStr2 = dlina(string);

    if (dlinaStr2 <= dlinaStr1)
    {
        int count = 0;
        while (count < dlinaStr1)
        {
            str[count] = string[count];
            count++;
        }
        str[count] = '\0'; // Добавляем нулевой символ
    }
    else
    {
        //  std::cout << "Строка 5 по размеру больше строки 1, что приводит к затиранию данных за границами массива и не совсем хорошо\n";
        int count = 0;
        while (string[count] != '\0')
        {
            str[count] = string[count];
            count++;
        }
        str[count] = '\0'; // Добавляем нулевой символ
    }
}

// Конструктор копирования
Stroka::Stroka(const Stroka &s)
{
    //std::cout << "Копирование\n";
    // Проверим что строки можно скопировать, т.е str1 меньше str2
    size_t dlinaStr1 = dlina();
    size_t dlinaStr2 = dlina(s.str);

    if (dlinaStr2 <= dlinaStr1)
    {
        int count = 0;
        while (count < dlinaStr1)
        {
            str[count] = s.str[count];
            count++;
        }
        str[count] = '\0'; // Добавляем нулевой символ
    }
    else
    {
        //  std::cout << "Строка 5 по размеру больше строки 1, что приводит к затиранию данных за границами массива и не совсем хорошо\n";
        int count = 0;
        while (s.str[count] != '\0')
        {
            str[count] = s.str[count];
            count++;
        }
        str[count] = '\0'; // Добавляем нулевой символ
    }
}

// Оператор присваивания
Stroka &Stroka::operator=(const Stroka &s)
{
        //std::cout << "Копирование\n";
    // Проверим что строки можно скопировать, т.е str1 меньше str2
    size_t dlinaStr1 = dlina();
    size_t dlinaStr2 = dlina(s.str);

    if (dlinaStr2 <= dlinaStr1)
    {
        int count = 0;
        while (count < dlinaStr1)
        {
            str[count] = s.str[count];
            count++;
        }
        str[count] = '\0'; // Добавляем нулевой символ
    }
    else
    {
        //  std::cout << "Строка 5 по размеру больше строки 1, что приводит к затиранию данных за границами массива и не совсем хорошо\n";
        int count = 0;
        while (s.str[count] != '\0')
        {
            str[count] = s.str[count];
            count++;
        }
        str[count] = '\0'; // Добавляем нулевой символ
    }
    return *this;
}

// Оператор сложения (конкатенации)
Stroka &Stroka::operator+(const Stroka &s)
{
    //std::cout << "Конкатенация\n";
    // Проверим сколько нам нужно байт для конкатенации
    size_t dlinaStr1 = dlina(str);
    size_t dlinaStr2 = dlina(s.str);
    size_t dlinaResult = dlinaStr1 + dlinaStr2 + 1; // т.к. символ окончания строки нужен быдет один раз
    for (int i = 0; i < dlinaStr2; i++)
    {
        str[dlinaStr1 + i] = s.str[i];
    }
    str[dlinaResult - 1] = '\0';
   // std::cout << std::endl;
    return *this;
}

// Оператор сравнения
int Stroka::operator==(const Stroka &s)
{
    // std::cout << "Сравнение\n";

    // Проверим что строки равной длины
    size_t dlinaStr1 = dlina(str);
    size_t dlinaStr2 = dlina(s.str);

    if (dlinaStr1 != dlinaStr2)
    {
        // std::cout << "Строки разные\n";
        return 0;
    }

    int count = 0;
    while (s.str[count] != '\0')
    {
        if (str[count] == s.str[count])
        {
            count++;
        }
        else
        {
            std::cout << "Строки разные\n";
            return 0;
        }
    }
    std::cout << "Строки одинаковые\n";
    return 1;
}

// Метод для определения длины
int Stroka::dlina()
{
    if (str == NULL)
        return 0;
    size_t count = 0; // счетчик
    for (count; str[count] != '\0'; count++)
        ;
    return (int)count;
}

int Stroka::dlina(const char *string)
{
    if (string == NULL)
        return 0;
    size_t count = 0; // счетчик
    for (count; string[count] != '\0'; count++)
        ;
    return (int)count;
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