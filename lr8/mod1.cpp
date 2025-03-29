#include "mod1Stroka.h"
#include <iostream>
#include <locale>
#include <clocale>

int main(int argc, char *argv[])
{

    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора

    Stroka s1;

    s1 = "Это тестовая строка\n";

    s1.vyvod();

    std::cout << s1;

    std::cout << 1; //Это для просмотра фактической реализации
    std::cout << std::endl;

    std::cout << "Введите строку: ";

    std::cin >> s1;

    std::cout << "Вы ввели: ";

    std::cout << s1;

    std::cout << std::endl;
    return 0;
}

// g++ mod1Stroka.cpp mod1.cpp -o mod1.exe
// mingw32-make