#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const char fname[] = "NewFile";

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора
    
    // Создаем новый файл, если только он уже не существует
    ofstream ofs(fname, ios::out | ios::__noreplace);
    if(!ofs)    // Проверка состояния потока
    {
        cout << "Ошибочная ситуация! Файл "
             << fname
             << " уже существует."
             << endl;
        return 0;
    }
    else
    {
        ofs << "Эта строка записывается "
            << "в новый файл";
        ofs.close();    // Закрываем файл
        
        fstream fs; // Определяем новый объект
        // Открываем файл и устанавливаем на EOF
        fs.open(fname, ios::out | ios::ate);  // Исправлено los::out на ios::out
        fs << "Сейчас к ней сделано добавление";
        fs.close(); // Закрываем файл
        
        // Открываем файл как входной
        ifstream ifs(fname); 
        
        if(ifs)
        {
            cout << "В старом файле содержится"
                 << "..." << endl;
            char Line[80];
            ifs.getline(Line, sizeof(Line));
            cout << Line;
        }
        else
        {
            cout << "Ошибочная ситуация "
                 << "при повторном открытии "
                 << fname
                 << endl;
        }
    }
    return 0;
}

//mod2in.txt
//mod2out.txt