#include <iostream>
using namespace std;

// Шаблон функции Sort
template <class T>
void Sort(T array[], size_t size)
{
    int i, j;
    T tmp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = size - 1; i < j; j--)
        {
            if (array[i] > array[j])
            {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "ru_RU.utf8");
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора
    int i;
    int mas[] = {10, 20, 30, 11, 25, 32, 0};

    Sort(mas, sizeof(mas)/sizeof(mas[0]));
    for (i = 0; i < sizeof(mas)/sizeof(mas[0]); i++)
    {
        std::cout << "mas[" << i << "] = " << mas[i] << endl;
    }

    return 0;
}