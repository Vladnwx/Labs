// Задача 2

#include <iostream>
#include <conio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    void qsort(int arr[], int start, int end);

    int mas1[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int mas2[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};

    std::cout << "Исходный массив: ";
    std::cout << std::endl;
    for (int i : mas1)
    { // вывод на экран

        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Пузырьковая сортировка: ";
    std::cout << std::endl;

    // Принцип работы пузырьковой сортировки:

    // Прохождение по всему массиву;
    // Сравнивание между собой пар соседних ячеек;
    // Если при сравнении оказывается, что значение ячейки j больше, чем значение ячейки j + 1, то мы меняем значения этих ячеек местами;

    // вычисленные n - количество элементов
    int n = sizeof(mas1) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (mas1[j] > mas1[j + 1])
            {
                // Меняем местами значения
                std::swap(mas1[j], mas1[j + 1]);
            }
        }
    }
    std::cout << "Отсортированный массив: ";
    std::cout << std::endl;
    for (int i : mas1)
    { // вывод на экран

        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Для работы с многомерным массивом пузырьковой сортировке нужно сначала развернуть такой массив в одномерный,\n отсортировать его, \nзатем свернуть его обратно в многомерный ";
    std::cout << std::endl;

    // быстрая сортировка:

    std::cout << "Быстрая сортировка: ";
    std::cout << std::endl;
    // вычисленные n - количество элементов
    int n2 = sizeof(mas2) / sizeof(int);

    qsort(mas2, 0, n2 - 1);

    std::cout << "Отсортированный массив: ";
    std::cout << std::endl;
    for (int i : mas2)
    { // вывод на экран

        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Для работы с многомерным массивом быстрой сортировке нужно сначала развернуть такой массив в одномерный,\n отсортировать его, \nзатем свернуть его обратно в многомерный ";
    std::cout << std::endl;

    return 0;
}

void qsort(int arr[], int start, int end) // переменные первого и последнего индексам массива
{
    // начальный индекс должен быть меньше конечного индекса
    if (start >= end)
    {
        return;
    }
    // проверяем все элементы относительно элемента с индексом start
    int current = start;
    for (int i = start + 1; i <= end; i++)
    {
        // если i-ый элемент меньше начального
        if (arr[i] < arr[start])
        {
            current++;
            std::swap(arr[current], arr[i]); // меняем его с текущим
        }
    }
    std::swap(arr[start], arr[current]); // Меняем выбранный (start или самый левый в данном случае) и последний текущий элементы
    if (current > start)
    {
        qsort(arr, start, current - 1); // Сортируем элементы слева
    }
    if (end > current + 1)
    {
        qsort(arr, current + 1, end); // Сортируем элементы справа
    }
}