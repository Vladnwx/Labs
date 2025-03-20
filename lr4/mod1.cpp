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
    int dlina1(char *);
    int dlina2(char *);
    int dlina3(char *);
    void kopir(char *, char *);
    void sravn(char *, char *);
    void konkat(char *, char *);

    // strlen
    //_Check_return_
    // size_t __cdecl strlen(
    //_In_z_ char const* _Str
    //);

    // использование функций длины строки


    std::cout << "Вычисление длины функция while \n";
    std::cout << "длина str1=" << dlina1(str1);
    std::cout << " str2=" << dlina1(str2);
    std::cout << std::endl;

    std::cout << "Вычисление длины функция for \n";
    std::cout << "длина str1=" << dlina2(str1);
    std::cout << " str2=" << dlina2(str2);
    std::cout << std::endl;

    std::cout << "Вычисление длины функция рекурсии \n";
    std::cout << "длина str1=" << dlina3(str1);
    std::cout << " str2=" << dlina3(str2);
    std::cout << std::endl;

    // std::cout <<"после обмена 1:  a= "<<a<<" b="<<b<<std::endl;

    // вызов kopir(char*, char*)
    kopir(str1, str2);
    std::cout << "результат копирования: str1=" << str1;
    std::cout << " str2=" << str2;
    std::cout << std::endl;

    // вызов sravn(char *, char *)
    std::cout << "результат сравнения: str1=" << str1;
    std::cout << " str2=" << str2;
    std::cout << std::endl;

    // вызов konkat(char *, char *)
    std::cout << "результат сцепления: str1=" << str1;
    std::cout << " str2=" << str2;
    std::cout << std::endl;

    return 0;
}

// цикл while
int dlina1(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

// цикл for
int dlina2(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
// через рекурсию
int dlina3(char *str)
{
    int count = 0;
    if (*str == '\0')
    {
        return 0;
    }
    return 1 + dlina3(str + 1);
    return count;
}

void kopir(char *, char *){
    std::cout << "Копирование\n";
}

void sravn(char *, char *){
    std::cout << "Сравнение\n";
}

void konkat(char *, char *){
    std::cout << "Конкатенация\n";

}