#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <cwctype>
using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора

    char fname[15], c;
    wchar_t wc; // Для поддержки русских символов

    cout << "Введите имя входного файла: ";
    cin >> fname;

    // Открываем входной файл
    ifstream ifs(fname);
    if (!ifs)
    {
        cout << "Не открыт входной файл " << fname;
        return 1;
    }
    cout << "Введите имя выходного файла: ";
    cin >> fname;

    // Открываем выходной файл
    ofstream ofs(fname);
    if (!ofs)
    {
        cout << "Не открыт выходной файл " << fname;
        return 1;
    }

    // Обработка файлов
    while (ifs && ofs)
    {
        ifs.get(c);
        c = toupper(c);
        ofs.put(c);
    }
    cout <<'.';
    cout << endl << "Выходной файл является копией входного файла в верхнем регистре";

    return 0;
}

//mod2in.txt
//mod2out.txt