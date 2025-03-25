// Задача 4

#include <iostream>
#include <conio.h>
// #include <windows.h>
#include <string>
#include <cstring>
/*
Обе функции используются для динамического выделения памяти в языке C/C++, но имеют ключевые различия:
malloc	
Выделяет неинициализированную память (может содержать "мусор")	
Принимает 1 аргумент — общий размер в байтах: malloc(size_in_bytes)
работает быстрее, так как не тратит время на обнуление памяти.
- Когда нужно выделить память для данных, которые будут сразу перезаписаны.
- Для оптимизации производительности.

calloc
Выделяет память, инициализированную нулями (все байты = 0)
Принимает 2 аргумента — количество элементов и размер каждого: calloc(num_elements, element_size)
медленнее из-за инициализации, но безопаснее (избегает ошибок с неинициализированной памятью).
- Для массивов, структур или строк, где важна чистая память.
- Когда нужно избежать неопределенного поведения из-за "мусора".

*/

int main(int argc, char *argv[])
{
    // SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.utf8");
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    char A[] = "qwerty", B[] = "1234567890";

    char *str1, *str2;

    // Странно что применяется malloc и calloc, а не new
    str1 = (char *)calloc(100, sizeof(char)); // Выделяем память
    str2 = (char *)calloc(100, sizeof(char));

    int dlina1(char *);
    int dlina2(char *);
    int dlina3(char *);
    void kopir(char *, char *);
    void sravn(char *, char *);
    void konkat(char *, char *);

    kopir(A, str1);
    kopir(B, str2);
    std::cout << "результат копирования: str1=" << str1;
    std::cout << " str2=" << str2;
    std::cout << std::endl;

    std::cout << "Вычисление длины функция while \n";
    std::cout << "длина str1=" << dlina1(str1);
    std::cout << " str2=" << dlina1(str2);
    std::cout << std::endl;

    std::cout << "Вычисление длины функция for \n";
    std::cout << "длина str1=" << dlina2(str1);
    std::cout << " str2=" << dlina2(str2);
    std::cout << std::endl;

    std::cout << "Вычисление длины функция рекурсии \n";
    std::cout << "длина str1=" << dlina3(str1);
    std::cout << " str2=" << dlina3(str2);
    std::cout << std::endl;

    // вызов sravn(char *, char *)
    sravn(str1, str2);
    std::cout << "результат сравнения: str1=" << str1;
    std::cout << " str2=" << str2;
    std::cout << std::endl;

    // вызов konkat(char *, char *)
    konkat(str1, str2);
    std::cout << "результат сцепления: str1=" << str1;
    std::cout << " str2=" << str2;
    std::cout << std::endl;

    // Странно что применяется free, а не delete
    free(str1);
    free(str2);

    return 0;
}

// цикл while
int dlina1(char *str) // в принципе всё уже реализовано (в предыдущем варианте)
{
    if (str == NULL)
    { // Проверка что указатель не нулевой
        return 1;
    }
    size_t count = 0; // Используем платформенно зависимый счетчик
    while (str[count] != '\0')
    {
        count++;
    }
    return (int)count;
}

// цикл for
int dlina2(char *str)
{
    if (str == NULL)
    { // Проверка что указатель не нулевой
        return 1;
    }
    size_t count = 0; // Используем платформенно зависимый счетчик
    for (count; str[count] != '\0'; count++)
        ;
    return (int)count;
}
// через рекурсию
int dlina3(char *str)
{
    if (str == NULL)
    { // Проверка что указатель не нулевой
        return 1;
    }
    if (*str == '\0')
    {
        return 0;
    }
    return 1 + dlina3(str + 1);
}
// используем математику указателей
int dllna4(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        ptr++;
    }
    return ptr - str;
}

void kopir(char *str1, char *str2) // Копируем str1 в str2
{
    std::cout << "Копирование\n";

    if (str1 == NULL || str2 == NULL)
    { // Проверка что указатель не нулевой
        std::cout << "Указатель нулевой\n";
        return;
    }
    // Проверим что строки можно скопировать, т.е str1 меньше str2
    size_t dlinaStr1 = dlina1(str1);
    size_t dlinaStr2 = dlina1(str2);

    if (dlinaStr1 <= dlinaStr2)
    {
        int count = 0;
        while (count < dlinaStr1)
        {
            str2[count] = str1[count];
            count++;
        }
        str2[count] = '\0'; // Добавляем нулевой символ
    }
    else
    {
        std::cout << "Строка 1 по размеру больше строки 2, что приводит к затиранию данных за границами массива и не совсем хорошо\n";
        int count = 0;
        while (str1[count] != '\0')
        {
            str2[count] = str1[count];
            count++;
        }
        str2[count] = '\0'; // Добавляем нулевой символ
    }
}

void sravn(char *str1, char *str2)
{
    std::cout << "Сравнение\n";

    if (str1 == NULL || str2 == NULL)
    { // Проверка что указатель не нулевой
        std::cout << "Указатель нулевой\n";
        return;
    }

    // Проверим что строки равной длины
    size_t dlinaStr1 = dlina1(str1);
    size_t dlinaStr2 = dlina1(str2);

    if (dlinaStr1 != dlinaStr2)
    {
        std::cout << "Строки разные\n";
        return;
    }

    // Если я правильно понял условия задачи, то мы сравниваем значения в строках, а не их длину
    int count = 0;
    while (str2[count] != '\0')
    {
        if (str1[count] == str2[count])
        {
            count++;
        }
        else
        {
            std::cout << "Строки разные\n";
            return;
        }
    }
    std::cout << "Строки одинаковые\n";
}

void konkat(char *str1, char *str2) // Копируем str2 в str1
{
    std::cout << "Конкатенация\n";

    if (str1 == NULL || str2 == NULL)
    { // Проверка что указатель не нулевой
        std::cout << "Указатель нулевой\n";
        return;
    }

    // Проверим сколько нам нужно байт для конкатенации
    size_t dlinaStr1 = dlina1(str1);
    size_t dlinaStr2 = dlina1(str2);
    size_t dlinaResult = dlinaStr1 + dlinaStr2 + 1; // т.к. символ окончания строки нужен быдет один раз

    char *ptrResult = (char *)malloc(dlinaResult); // выделим память

    for (int i = 0; i < dlinaStr1; i++)
    {
        ptrResult[i] = str1[i];
    }

    for (int i = 0; i < dlinaStr2; i++)
    {
        ptrResult[dlinaStr1 + i] = str2[i];
    }

    ptrResult[dlinaResult-1] = '\0';
    
    std::cout << ptrResult;
    std::cout << std::endl;
    free(ptrResult);


}