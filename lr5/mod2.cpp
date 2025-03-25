// Задача 2

#include <iostream>
#include <stdio.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора
    char name[50];
    FILE *in;
    int ch;
    size_t countPrint=0, countNonPrint=0;

//Воспользуемся короткой версией программы
    printf("Введите имя файла для просмотра: ");
    if (scanf("%s", name) && (in = fopen(name, "r")))
        while (!feof(in)){
            ch = getc(in);
            if(isprint(ch)) countPrint++;
            else countNonPrint++;
            putchar(ch);
        }
        std::cout << std::endl; 
        std::cout << "Печатаемых символов = "<< countPrint<<std::endl; 
        std::cout << "НЕ печатаемых символов = "<< countNonPrint<<std::endl; 
    
    return 0;
}