#include <iostream>
#include <cstring>

// Класс для работы со строками как со стандартным типом данных
class Stroka
{
    char str[80]; // Массив для хранения символов строки
public:
    // Описание функций
    Stroka(char *);                    // Конструктор с параметром
    Stroka() {};                       // Конструктор по умолчанию
    Stroka(const Stroka &);            // Конструктор копирования
    Stroka &operator=(const Stroka &); // Оператор присваивания
    Stroka &operator+(const Stroka &); // Оператор сложения (конкатенации)
    int operator==(const Stroka &);    // Оператор сравнения
    int dlina();                       // Метод для определения длины
    void vvod();                       // Метод ввода
    void vyvod();                      // Метод вывода
};

/*
деструктор не требуется
Класс использует статический массив char str[80]
Память выделяется автоматически при создании объекта и освобождается при его уничтожении
Нет ручного управления памятью через new/malloc
*/
// Реализация функций

// Конструктор с параметром
Stroka::Stroka(char *string)
{
    strcpy(str, string); // копирование
}

// Конструктор копирования
Stroka::Stroka(const Stroka &s)
{
    strcpy(str, s.str);
}

// Оператор присваивания
Stroka &Stroka::operator=(const Stroka &s)
{
    strcpy(str, s.str);
    return *this;
}

// Оператор сложения (конкатенации)
Stroka &Stroka::operator+(const Stroka &s)
{
    strcat(str, s.str);
    return *this;
}

// Оператор сравнения
int Stroka::operator==(const Stroka &s)
{
    if ((strcmp(str, s.str)) == 0)
        return 1;
    else
        return 0;
}

// Метод для определения длины
int Stroka::dlina()
{
    return strlen(str);
}

// Метод ввода
void Stroka::vvod()
{
    std::cin >> str;
}

// Метод вывода
void Stroka::vyvod()
{
    std::cout << str;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора

    Stroka s1("qwert"), s3, s4(s1), s5;
    s3.vvod();
    s3 = "asdfg";
    s3.vyvod();
    s5 = s1 + s3 + s4;
    std::cout << "длина s5 = " << s5.dlina();
    s5.vyvod();
    if (s1 == s5)
        std::cout << "строки s1 и s5 равны";
    else if (s1 == s4)
        std::cout << "строки s1 и s4 равны";

    return 0;
}