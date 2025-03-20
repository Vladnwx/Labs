// Задача 1

#include <iostream>
#include <string>
#include <windows.h>
// Функция main() должна возвращать значение типа int. Это значение передается операционной системе и указывает на статус завершения программы.
// Обычно возвращается 0, если программа завершилась успешно, и ненулевое значение в случае ошибки.
// Функция main() может быть объявлена без параметров:
// Или с двумя параметрами для обработки аргументов командной строки
// argc (argument count) — количество аргументов командной строки.
// argv (argument vector) — массив строк, где каждый элемент — это аргумент командной строки. argv[0] обычно содержит имя программы.
int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    bool checkArgsInt(char *argument);
    // не будем использовать unsigned int, т.к. от нас это не требуют
    int a, b;
    // Чтобы можно было запускать через командную строку с аргументами
    if (argc == 3)
    {
        if (checkArgsInt(argv[1]) & checkArgsInt(argv[2]))
        {
            a = std::stoi(argv[1]);
            b = std::stoi(argv[2]);
        }
        else
            std::cerr << "Ошибка: введено не целое число." << std::endl;
    }
    else
    {
        std::cerr << "Ошибка: не введены два аргумент: число для возведения в степень и необходимая степень" << std::endl;
        std::cerr << "Пример ввода .\\mod1.exe 2 5" << std::endl;
        return 1;
    }

    long long power(int, int);

    power(a, b);

    return 0;
}

// Функция возведения в степень, можно конечно добавить извлечение корня, но этого не требуют
// Еще можно использовать алгоритм быстрого возведения в степень, но такая задача не ставится
long long power(int x, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    if (pow > 0)
    {
        std::cout << x << " в cтепени 0" << " равно 1" << std::endl;
    }
    long long result = 1;
    for (int i = 1; i <= pow; i++)
    {
        result *= x;
        std::cout << x << " в cтепени " << i << " равно " << result << std::endl;
    }
    return result;
}

// Функция проверки переданных аргументов
bool checkArgsInt(char *argument)
{
    try
    {
        std::stoi(argument);
        return true; // Полученное значение можно преобразовать в int
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Ошибка: аргумент должен быть целым числом." << std::endl;
        return false; // Завершаем программу с ошибкой
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Ошибка: число слишком большое." << std::endl;
        return false; // Завершаем программу с ошибкой
    }
}