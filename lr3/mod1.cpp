// Задача 1

#include <iostream>
#include <conio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    // текущие индексы мин. и макс. элементов
    int imin, imax;
    // вычисленные n - количества элементов
    int n = sizeof(mas) / sizeof(int);

    int i; // начало неотсортированной части
    int j; // конец неотсортированной части

    // установка начальных индексов для мин и макс
    imin = i = 0;
    imax = i = 0;
    // system("cls");
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    for (i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    for (i = 0, j = n - 1; i < j; i++, j--)
    { // нахождение мин и макс
        imin = i;
        imax = i;
        for (int k = i; k <= j; k++)
        {
            if (mas[k] < mas[imin]) //Сравниваем текущее значение с минимальным и если оно меньше, то передаем минимальный указатель
            {
                imin = k;
            }

            if (mas[k] > mas[imax]) //Сравниваем текущее значение с максимальным и если оно больше, то передаем максимальный указатель
            {
                imax = k;
            }
        }
        //Меняем местами значения
        std::swap(mas[i], mas[imin]);

        // Если максимальный элемент был на позиции i, он мог быть перемещён
        if (imax == i)
        {
            imax = imin;
        }
        //Меняем местами значения
        std::swap(mas[j], mas[imax]);
    }

    for (int i : mas)
    { // вывод на экран

        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}