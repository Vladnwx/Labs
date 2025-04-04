// Задача 2

#include <iostream>
#include <conio.h>
//#include <windows.h>
#include <string>

int main(int argc, char *argv[])
{
    //SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.utf8");
    //system("chcp 65001"); // Устанавливаем кодовую страницу UTF-8
    //setlocale(LC_ALL, "Russian");
    //system("chcp 1251");


    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    char str1[] = "qwerty", str2[] = "1234567890";
    int dlina1(char *);
    int dlina2(char *);
    int dlina3(char *);
    void kopir(char *, char *);
    void sravn(char *, char *);
    void konkat(char *, char *);

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
    sravn(str1, str2);
    std::cout << "результат сравнения: str1=" << str1;
    std::cout << " str2=" << str2;
    std::cout << std::endl;

    // вызов konkat(char *, char *)
    konkat(str1, str2);
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
    if (*str == '\0')
    {
        return 0;
    }
    return 1 + dlina3(str + 1);
}

void kopir(char *str1, char *str2)
{
    std::cout << "Копирование\n";
    int count = 0;
    while (str2[count] != '\0')
    {
        str1[count] = str2[count]; //Тут бы конечно посмотреть на размеры массивов и выделить память, еслии её не хватит, но реализуем банальную ситуацию
        count++;
    }
    str1[count]='\0';
}

void sravn(char *str1, char *str2)
{
    std::cout << "Сравнение\n";
    int count = 0;
    while (str2[count] != '\0')
    {
        if (str1[count] == str2[count]) //Тут бы конечно посмотреть на указатели, вдруг ониодинаковые
        {
            count++;
        }
        else
        {
            std::cout << "Строки разные\n";
            return;

        }
    }
    std::cout << "Строки одинаковые\n"; //В задаче непонятны условия, можеть быть еще их нужно было сранивать по размеру?
}

void konkat(char *str1, char *str2)
{
    std::cout << "Конкатенация\n";
    
    int count1 = 0;
    while (str1[count1] != '\0')
    {
        count1++;
    }
    int count2 = 0;
    while (str2[count2] != '\0')
    {
        str1[count1-1+count2]=str2[count2]; //Тут бы конечно посмотреть на размеры массивов и выделить память, еслии её не хватит, но реализуем банальную сиитуацию
        count2++;                           
    }
    str1[count1+count2+1]='\0';

}