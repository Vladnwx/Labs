#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора
    
    char name[12];
    fstream fn; // Неоткрытый объект-поток
    
    cout << "Введите имя файла: ";
    cin >> name;
    
    // Открыли входной поток
    fn.open(name, ios::in);
    
    if(fn) // Проверяем состояние потока
    {
        cout << "Файл открыт " << name << endl;
        fn.close(); // Закрываем файл
    }
    else
    {
        cout << "Не удалось открыть файл " << name << endl;
    }
    
    return 0;
}

//mod2in.txt
//mod2out.txt