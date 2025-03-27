#include "mod3Stroka.cpp"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.utf8"); // Установка русской локали для корректного отображения кириллицы в консоли
    std::cout << "\033[2J\033[H";    // Очистка экрана и перемещение курсора
    
    
    Stroka s1("qwert"), s3, s4(s1), s5;

    s3.vvod();
    std::cout << std::endl;

    s3 = "asdfg";

    s3.vyvod();
    std::cout << std::endl;

    s5 = s1 + s3 + s4;
    std::cout << "длина s5 = " << s5.dlina();
    std::cout << std::endl;
    s5.vyvod();
    std::cout << std::endl;
    if (s1 == s5)
        std::cout << "строки s1 и s5 равны";
    else if (s1 == s4)
        std::cout << "строки s1 и s4 равны";
        std::cout << std::endl;
    return 0;
}