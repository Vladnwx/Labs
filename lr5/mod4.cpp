// Задача 4

#include <iostream>
#include <stdio.h>

int main(int argc, char *argv[])
{
    void filePageFix(char *, char *);
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора
    // char inFileName[50];
    char outFileName[] = "4out.txt"; // файл вывода

    // printf("Введите имя файла для просмотра: ");
    // if (scanf("%s", inFileName));

    // Для упрощения тестирования будем передавать заранее известное название файла
    char inFileName[] = "4"; // файл откуад читаем

    filePageFix(inFileName, outFileName);
    std::cout << std::endl;

    return 0;
}

//
void filePageFix(char *inFileName, char *outFileName)
{ // inFileName где ищем, outFileName - куда пишем
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

    char chStartPage = '-'; // Символ начала нумерации страницы
    char chNextPage = '\f'; // Символ перехода на следуюущую страницу страницы

    char numberPageValue[100]; // массив символов для сохранения номера страницы

    bool pagefirst = true; // страница первая
    bool pagelast = false;  // страница последняя

    int ch;
    while ((ch = getc(inFile)) != EOF) // Читаем до конца файла
    {
        // std::cout.put(ch);

        if (ch == chStartPage)
        {
            // std::cout << "Найдено начало обозначения страницы\n";
            ch = getc(inFile); // Читаем следующий символ
            size_t count = 0;  // Счетчик прочитанных символов
            while (ch != chStartPage)
            { // Читаем пока не найдем второй дефис
                if (isdigit(ch))
                { // Если символ является числом, то пишем его в массив
                    numberPageValue[count] = ch;
                    count++;
                }
                ch = getc(inFile);
            }
            count++;
            numberPageValue[count] = '\0';
            // std::cout << "Найдено окончание обозначения страницы\n";
        }

        else if (ch == chNextPage)
        {
            // std::cout << "Найден символ конца страницы \n";
            // На его место запишем номер страницы
            for (int i = 0; numberPageValue[i] != '\0'; i++)
            {
                fprintf(outFile, "\n");
                fprintf(outFile, "%c", numberPageValue[i]);
            }
            fprintf(outFile, "\f");
            ch = getc(inFile); // Читаем следующий символ
            if (ch != EOF) pagelast = false;
        }
        else
        {
            if (pagefirst && ch == '\n')
            {
                pagefirst=false;
                continue;
            }
            fprintf(outFile, "%c", ch);
        }
        
    }

    fclose(outFile);
    fclose(inFile);
    return;
}