#include <iostream>
#include "Sort.cpp"
#include "Money.cpp"

using namespace std;

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "ru_RU.utf8");
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора
    Money mas[]={Money(19,10),
    Money(99,99),
    Money(99,95),
    Money(19,95)
    };
    Sort(mas, sizeof(mas)/sizeof(mas[0]));
    for(int i = 0; i < sizeof(mas)/sizeof(mas[0]); i++)
    cout << "mas[" << i << "] = " << mas[i] << endl;
}

//g++ Money.cpp sort.cpp mod2.cpp -o mod1.exe