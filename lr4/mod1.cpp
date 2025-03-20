// Задача 1

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    char str1[] = "qwerty", str2[] = "1234567890";

    std::cout <<strlen(str1);
    std::cout <<std::endl;

    std::cout <<strcat(str1, str2);
    std::cout <<std::endl;

    std::cout <<strcpy(str1, str2);
    std::cout <<std::endl;

    std::cout <<strcmp(str1, str2);
    std::cout <<std::endl;

    return 0;
}