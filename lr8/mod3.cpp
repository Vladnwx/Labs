#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

void fileCrypto(const std::string &, const std::string &, const std::string &);
void fileDeCrypto(const std::string &, const std::string &, const std::string &);

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "ru_RU.utf8");
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    std::string inFileName = (argc < 2) ? "3in.txt" : argv[1];
    std::string key = (argc < 3) ? "Foobar" : argv[2];
    const std::string outFileNameCrypto = "3outCrypto.txt";
    const std::string outFileNameDeCrypto = "3outDeCrypto.txt";

    std::cout << "Использование: " << argv[0] << " <входной_файл> <ключ>\n";
    std::cout << "Текущие параметры:\n";
    std::cout << "  Входной файл: " << inFileName << "\n";
    std::cout << "  Ключ шифрования: " << key << "\n";
    std::cout << "  Зашифрованный файл: " << outFileNameCrypto << "\n";
    std::cout << "  Расшифрованный файл: " << outFileNameDeCrypto << "\n\n";

    // Шифрование и дешифровка
    fileCrypto(inFileName, outFileNameCrypto, key);
    fileDeCrypto(outFileNameCrypto, outFileNameDeCrypto, key);

    std::cout << "Обработка завершена успешно.\n";
    return 0;
}

std::ifstream fileCheckRead(const std::string &fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Ошибка открытия файла" << std::endl;
        // Возвращаем поток в состоянии fail
        return std::ifstream();
    }
    return file;
}

std::ofstream fileCheckWrite(const std::string &fileName)
{
    std::ofstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Ошибка открытия файла для записи" << std::endl;
        return std::ofstream(); // Возвращаем поток в состоянии fail
    }
    return file;
}

//
void fileCrypto(const std::string &inFileName, const std::string &outFileName, const std::string &key)
{

    fileCheckRead(inFileName);
    fileCheckWrite(outFileName);

    std::ifstream inFile(inFileName, std::ios::binary);
    std::ofstream outFile(outFileName, std::ios::binary);

    const size_t key_length = key.length();
    char ch;

    // Читаем файл побайтово
    while (inFile.get(ch))
    {
        for (size_t i = 0; i < key_length; ++i)
        {
            ch ^= key[i];
        }
        outFile.put(ch);
    }
}

void fileDeCrypto(const std::string &inFileName, const std::string &outFileName, const std::string &key)
{
    fileCheckRead(inFileName);
    fileCheckWrite(outFileName);

    std::ifstream inFile(inFileName, std::ios::binary);
    std::ofstream outFile(outFileName, std::ios::binary);

    const size_t key_length = key.length();
    if (key_length == 0)
    {
        std::cerr << "Ошибка: ключ шифрования пуст!" << std::endl;
        return;
    }

    char ch;
    while (inFile.get(ch))
    { // Чтение по одному байту
        for (size_t i = 0; i < key_length; ++i)
        {
            ch ^= key[i];
        }
        outFile.put(ch);
    }
}