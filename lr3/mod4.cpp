// Задача 4

#include <iostream>
#include <conio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};

    constexpr int n = sizeof(mas) / sizeof(mas[0]);

    // Индексы:
    int N1 = 0;
    int N2 = 5;

    std::cout << "Исходный массив: \n";
    for (int i : mas)
    { // вывод на экран
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Сортировка от индекса N1 и N2 по возрастанию
    // воспользуемся пузырьковой сортировкой для простоты реализации, иначе можно было бы использовать std:sort

    for (int i = N1; i < N2; i++)
    {
        for (int j = N1; j < N2 - 1; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                // Меняем местами значения
                std::swap(mas[j], mas[j + 1]);
            }
        }
    }
    std::cout << "Отсортированный массив: ";
    std::cout << std::endl;
    for (int i : mas)
    { // вывод на экран

        std::cout << i << " ";
    }
    return 0;
}