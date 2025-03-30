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