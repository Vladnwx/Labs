#include "mod1Point.h"
#include <cstdlib>
#include <ctime>

void Point::Init(int XN, int YN, unsigned short Color)
{
    X = XN;
    Y = YN;
    Cvet = Color;
}

void Point::Show() {}
void Point::Hide() {}

void Point::Locat(int &XL, int &YL)
{
    XL = X;
    YL = Y;
}

void Point::Fly(int Cost)
{
    int XX, YY;
    Show();
    // Randomize(); такой функции нет в c++, заменим на подобную, тут она только объявляется
    //  Инициализация генератора случайных чисел
    srand(static_cast<unsigned>(time(nullptr)));
    // Repeat(); // такой функции нет в c++, реализуем по другому и вынесем отдельно

    do
    {
        // Получаем текущие координаты
        Locat(XX, YY);
        // Цикл перемещения по X
        do
        {
            XX = XX + round(((rand() % 2) - 0.5f) * Cost);
        } while (XX > 0 && XX < getmaxx());
        // Цикл перемещения по Y
        do
        {
            YY = YY + round(((rand() % 2) - 0.5f) * Cost);
        } while (YY > 0 && YY < getmaxy());
        // Скрываем объект, обновляем позицию и показываем снова
        Hide();
        X = XX;
        Y = YY;
        Show();
        delay(300);
    } while (!kbhit()); // Пока не нажата клавиша
    getch();
}
// для задачи 2
void Point::SectorColor(int Cost)
{
    int XX, YY;
    int originalColor = Cvet; // Сохраняем исходный цвет
    int sectorWidth = 30;     // Начальная ширина сектора
    bool expanding = true;    // Флаг для определения направления изменения сектора
    Show();
    srand(static_cast<unsigned>(time(nullptr)));
    do
    {
        // Изменение ширины сектора
        if (expanding)
        {
            sectorWidth += 5;
            if (sectorWidth >= 60)
                expanding = false;
        }
        else
        {
            sectorWidth -= 5;
            if (sectorWidth <= 10)
                expanding = true;
        }
        // Смена цвета
        Cvet = (Cvet + 1) % 16;
        // Перемещение
        Locat(XX, YY);
        do
        {
            XX = XX + round(((rand() % 2) - 0.5f) * Cost);
        } while (XX > 0 && XX < getmaxx());

        do
        {
            YY = YY + round(((rand() % 2) - 0.5f) * Cost);
        } while (YY > 0 && YY < getmaxy());
        Hide();
        X = XX;
        Y = YY;
        Show();
        delay(300);
    } while (!kbhit());

    Cvet = originalColor; // Восстанавливаем исходный цвет
    getch();
}
