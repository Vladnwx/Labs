// Задача 5

#include <iostream>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    void fileCrypto(char *, char *, const char *);
    void fileDeCrypto(char *, char *, const char *);
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора

    char inFileName[] = "5in.txt";                   // файл откуда читаем
    char outFileNameCrypto[] = "5outCrypto.txt";     // файл вывода зашифрованного файла
    char outFileNameDeCrypto[] = "5outDeCrypto.txt"; // файл вывода расшифрованного файла

    const char *key= NULL;
    if (argc < 2) key = "Foobar"; // ключ шифрования
    else key = argv[1]; // ключ шифрования

    printf("Использование: %s <ключ> %s <входной_файл> %s <выходной_файл> \n", argv[1], inFileName, outFileNameCrypto);
    fileCrypto(inFileName, outFileNameCrypto, key);
    fileDeCrypto(outFileNameCrypto, outFileNameDeCrypto, key);
    std::cout << std::endl;

    return 0;
}

FILE *fileCheckRead(char *FileName)
{
    FILE *file = fopen(FileName, "r");
    if (!file)
    {
        printf("Ошибка открытия файла\n");
        return NULL;
    }
    return file;
}

FILE *fileCheckWrite(char *FileName)
{
    FILE *file = fopen(FileName, "w");
    if (!file)
    {
        printf("Ошибка открытия файла\n");
        return NULL;
    }
    return file;
}

//
void fileCrypto(char *inFileName, char *outFileName, const char *key)
{ // inFileName где ищем, outFileName - куда пишем

    FILE *inFile = fileCheckRead(inFileName);
    FILE *outFile = fileCheckWrite(outFileName);

    int key_lenght = (int)strlen(key);
    int ch;
    while ((ch = getc(inFile)) != EOF) // Читаем до конца файла
    {
        for (int i = 0; i < key_lenght; i++)
        {
            ch = ch ^ key[i];
        }
        fputc(ch, outFile);
    }

    fclose(outFile);
    fclose(inFile);
    return;
}

void fileDeCrypto(char *inFileName, char *outFileName, const char *key)
{ // inFileName где ищем, outFileName - куда пишем

    FILE *inFile = fileCheckRead(inFileName);
    FILE *outFile = fileCheckWrite(outFileName);

    int key_lenght = (int)strlen(key);
    int ch;
    while ((ch = getc(inFile)) != EOF) // Читаем до конца файла
    {
        for (int i = 0; i < key_lenght; i++)
        {
            ch = ch ^ key[i];
        }
        fputc(ch, outFile);
    }

    fclose(outFile);
    fclose(inFile);
    return;
}