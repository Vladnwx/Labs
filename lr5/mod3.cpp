// Задача 2

#include <iostream>
#include <stdio.h>

int main(int argc, char *argv[])
{
    void fileSearchSubstring(char *, char *, char *);
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора
    char inFileName[50];
    char outFileName[] = "out.txt"; // файл вывода
    char string[] = "12345";        // искомая строка

    // Воспользуемся короткой версией программы
    printf("Введите имя файла для просмотра: ");
    if (scanf("%s", inFileName))
        ;

    fileSearchSubstring(inFileName, string, outFileName);
    std::cout << std::endl;

    return 0;
}

// Функция проверяет есть подстрока в исходной строке или нет
void fileSearchSubstring(char *inFileName, char *string, char *outFileName)
{ // inFileName где ищем, string - что ищем, outFileName - куда пишем
    FILE *outFile = fopen(outFileName, "w");
    if (!outFile)
    {
        printf("Ошибка создания файла\n");
        return;
    }
    FILE *inFile = fopen(inFileName, "r");
    if (!inFile)
    {
        printf("Ошибка открытия файла\n");
        return;
    }
    size_t ch;
    // Посчитаем сколько символов в искомой строке
    size_t lenghtString = 0;
    while (string[lenghtString] != '\0')
        lenghtString++;

    //std::cout << "\nlenghtString " << lenghtString;

    size_t count = 0; // Счетчик совпадений

    while (!feof(inFile))
    {
        ch = getc(inFile);

        //std::cout << "\ncount " << count;
        if (count == lenghtString)
        {
            printf("Совпадение найдено\n");
            fprintf(outFile, "Совпадение найдено");
            fclose(outFile);
            fclose(inFile);
            return;
        }
        if (ch == string[count])
            count++;
        else
            count = 0;
    }
    printf("Совпадение НЕ найдено\n");
    fprintf(outFile, "Совпадение НЕ найдено");
    fclose(outFile);
    fclose(inFile);
    return;
}