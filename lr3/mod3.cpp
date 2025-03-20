// Задача 1

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <algorithm>

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};

    constexpr int n = sizeof(mas) / sizeof(mas[0]);

    std::cout << "Исходный массив: \n";
    for (int i : mas)
    { // вывод на экран

        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Сортировка четных (по возрастанию) и нечетных (по убыванию)
    // Разделим на два подмассива: четные и нечетные
    // Отсортируем по требованию задачи
    // Выведем отдельно и вместе
    // Четное число делится на 2 с остатком

    int countEven = 0;
    int countOdd = 0;

    for (int i = 0; i < n; i++)
    {
        if (mas[i] % 2 == 0)
        {
            countEven++;
        }
        else
        {
            countOdd++;
        }
    }

    int *even = new int[countEven]; // массив четных чисел
    int *odd = new int[countOdd];   // массив нечетных чисел

    countEven = 0;
    countOdd = 0;

    for (int i = 0; i < n; i++)
    {
        if (mas[i] % 2 == 0)
        {
            even[countEven] = mas[i];
            countEven++;
        }
        else
        {
            odd[countOdd] = mas[i];
            countOdd++;
        }
    }

    // std::cout << countEven << " countEven";
    // std::cout << std::endl;
    // std::cout << countOdd << " countOdd";
    // std::cout << std::endl;
    // std::cout << sizeof(even) << " sizeof(even)";
    // std::cout << sizeof(even) / sizeof(even[0]) << " sizeof(even) / sizeof(even[0])";

    std::sort(even, even + countEven);
    std::sort(odd, odd + countOdd, std::greater<int>());

    std::cout << "массив четных: \n";
    for (int i = 0; i < countEven; i++)
    { // вывод на экран
        std::cout << even[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "массив нечетных: \n";
    for (int i = 0; i < countOdd; i++)
    { // вывод на экран
        std::cout << odd[i] << " ";
    }
    std::cout << std::endl;


    for (int i=0; i<countEven; i++)
    {
        mas[i]=even[i];
    }
    for (int i=0; i<countOdd; i++)
    {
        mas[countEven+i]=odd[i];
    }

    std::cout << "обший массив: \n";

    for (int i : mas)
    { // вывод на экран

        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}