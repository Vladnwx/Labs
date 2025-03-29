// Задача 6

#include <iostream>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    void fileCrypto(const char *, const char *, const char *);
    void fileDeCrypto(const char *, const char *, const char *);
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора
                  
    const char *inFileName= NULL; // файл откуда читаем
    if (argc < 2) inFileName = "6in.txt"; // ключ шифрования
    else inFileName = argv[1]; // ключ шифрования

    const char outFileNameCrypto[] = "6outCrypto.txt";     // файл вывода зашифрованного файла
    const char outFileNameDeCrypto[] = "6outDeCrypto.txt"; // файл вывода расшифрованного файла

    const char *key= NULL;
    if (argc < 3) key = "Foobar"; // ключ шифрования
    else key = argv[2]; // ключ шифрования

    printf("Использование: %s <ключ> %s <входной_файл> %s <выходной_файл> \n", argv[1], inFileName, outFileNameCrypto);
    fileCrypto(inFileName, outFileNameCrypto, key);
    fileDeCrypto(outFileNameCrypto, outFileNameDeCrypto, key);
    std::cout << std::endl;

    return 0;
}

FILE *fileCheckRead(const char *FileName)
{
    FILE *file = fopen(FileName, "r");
    if (!file)
    {
        printf("Ошибка открытия файла\n");
        return NULL;
    }
    return file;
}

FILE *fileCheckWrite(const char *FileName)
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
void fileCrypto(const char *inFileName, const char *outFileName, const char *key)
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

void fileDeCrypto(const char *inFileName, const char *outFileName, const char *key)
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