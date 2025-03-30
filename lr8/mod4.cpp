#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
using namespace std;

void fileCrypto(const std::string &, const std::string &, const std::string &);
void fileDeCrypto(const std::string &, const std::string &, const std::string &);
void printStreamBit(const std::ios& stream, const std::string& streamName);
void ilustrateStreamMethods(const std::string& filename);

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

    ilustrateStreamMethods(inFileName);

    // Шифрование и дешифровка
    fileCrypto(inFileName, outFileNameCrypto, key);
    fileDeCrypto(outFileNameCrypto, outFileNameDeCrypto, key);

    std::cout << "Обработка завершена успешно.\n";
    return 0;
}

void printStreamBit(const std::ios& stream, const std::string& streamName) {
    std::cout << "Состояние потока " << streamName << ":\n";
    std::cout << "  good(): " << stream.good() << "\n";
    std::cout << "  eof(): " << stream.eof() << "\n";
    std::cout << "  fail(): " << stream.fail() << "\n";
    std::cout << "  bad(): " << stream.bad() << "\n";
    std::cout << "  rdstate(): " << stream.rdstate() << "\n\n";
}

void ilustrateStreamMethods(const std::string& filename) {
    std::cout << "\n=== Иллюстрация методов управления состоянием потоков ===\n\n";
    
    // Создаем и открываем файловый поток
    std::ifstream file(filename, std::ios::binary);
    
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для демонстрации\n";
        printStreamBit(file, "после неудачного открытия");
        return;
    }
    
    // Проверяем начальное состояние
    printStreamBit(file, "до чтения");
    
    // Читаем несколько символов
    char ch;
    file.get(ch);
    std::cout << "Прочитан первый символ: " << ch << "\n";
    printStreamBit(file, "после чтения первого символа");
    
    // Определяем текущую позицию
    std::streampos pos = file.tellg();
    std::cout << "Текущая позиция чтения: " << pos << "\n\n";
    
    // Перемещаемся в начало файла
    file.seekg(0, std::ios::beg);
    std::cout << "Переместились в начало файла\n";
    printStreamBit(file, "после seekg(0)");
    
    // Читаем весь файл до конца
    std::cout << "Читаем весь файл до конца...\n";
    while (file.get(ch)) {
        // Просто читаем
    }
    printStreamBit(file, "после чтения до конца файла");
    
    // Пытаемся прочитать после конца файла
    file.get(ch);
    std::cout << "Попытка чтения после EOF\n";
    printStreamBit(file, "после попытки чтения после EOF");
    
    // Очищаем состояние потока
    file.clear();
    std::cout << "После clear()\n";
    printStreamBit(file, "после clear()");
    
    // Закрываем файл
    file.close();
    std::cout << "Файл закрыт\n";
    printStreamBit(file, "после close()");
    
    std::cout << "=== Конец иллюстрации ===\n\n";
}

void fileCrypto(const std::string &inFileName, const std::string &outFileName, const std::string &key)
{
    std::ifstream inFile(inFileName, std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "Ошибка: невозможно открыть входной файл для шифрования: " << inFileName << "\n";
        printStreamBit(inFile, "входной файл при ошибке открытия");
        return;
    }

    std::ofstream outFile(outFileName, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка: невозможно открыть выходной файл для шифрования: " << outFileName << "\n";
        printStreamBit(outFile, "выходной файл при ошибке открытия");
        inFile.close();
        return;
    }

    const size_t key_length = key.length();
    char ch;

    while (inFile.get(ch))
    {
        for (size_t i = 0; i < key_length; ++i)
        {
            ch ^= key[i];
        }
        outFile.put(ch);
    }
    
    // Проверяем состояние потоков после операции
    if (inFile.bad()) {
        std::cerr << "Ошибка: серьезная ошибка при чтении входного файла\n";
    } else if (inFile.fail() && !inFile.eof()) {
        std::cerr << "Ошибка: проблема при чтении входного файла\n";
    }
    
    if (outFile.bad()) {
        std::cerr << "Ошибка: серьезная ошибка при записи выходного файла\n";
    } else if (outFile.fail()) {
        std::cerr << "Ошибка: проблема при записи выходного файла\n";
    }

    inFile.close();
    outFile.close();
}

void fileDeCrypto(const std::string &inFileName, const std::string &outFileName, const std::string &key)
{
    std::ifstream inFile(inFileName, std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "Ошибка: невозможно открыть входной файл для дешифрования: " << inFileName << "\n";
        return;
    }

    std::ofstream outFile(outFileName, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка: невозможно открыть выходной файл для дешифрования: " << outFileName << "\n";
        inFile.close();
        return;
    }

    const size_t key_length = key.length();
    if (key_length == 0)
    {
        std::cerr << "Ошибка: ключ шифрования пуст!" << std::endl;
        inFile.close();
        outFile.close();
        return;
    }

    char ch;
    while (inFile.get(ch))
    {
        for (size_t i = 0; i < key_length; ++i)
        {
            ch ^= key[i];
        }
        outFile.put(ch);
    }
    
    // Проверяем состояние потоков после операции
    if (inFile.bad()) {
        std::cerr << "Ошибка: серьезная ошибка при чтении входного файла\n";
    } else if (inFile.fail() && !inFile.eof()) {
        std::cerr << "Ошибка: проблема при чтении входного файла\n";
    }
    
    if (outFile.bad()) {
        std::cerr << "Ошибка: серьезная ошибка при записи выходного файла\n";
    } else if (outFile.fail()) {
        std::cerr << "Ошибка: проблема при записи выходного файла\n";
    }

    inFile.close();
    outFile.close();
}