#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const char fname[] = "NewFile";

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора
    cout << "Имя входного файла? ";
    char name[80];
    cin >> name;

    ifstream ifbin(name, ios::in | ios::binary);
    ifstream iftxt(name, ios::in);

    if (!iftxt || !ifbin)
    {
        cout << "Не открыт входной файл "
             << name << endl;
        return 1;
    }

    int countBin = 0;
    while (ifbin.get() != EOF)
    {
        countBin++;
    }

    cout << "В режиме binary прочитано "
         << countBin
         << " символов" << endl;

    int countTxt = 0;
    while (iftxt.get() != EOF)
    {
        countTxt++;
    }

    cout << "В режиме text прочитано "
         << countTxt
         << " символов" << endl;

    ifbin.close();
    iftxt.close();

    return 0;
 
}

//mod2in.txt
//mod2out.txt