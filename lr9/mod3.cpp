#include <iostream>
using namespace std;

// Шаблон класса Stack
template <class T>
class TStack
{
protected:
    int numItem;
    T *item;

public:
    TStack(size_t size = 10) // Конструктор
    {
        numItem = 0;
        item = new T[size];
    }
    ~TStack() // Деструктор
    {
        delete[] item;
    }
    void push(T t) // Вставка элемента в стек
    {
        item[numItem++] = t;
    }
    T pop() // Извлечение элемента из стека
    {
        return item[--numItem];
    }
    T top() const { // Вернуть верхний элемент стека

        if (numItem > 0)
            return item[numItem-1];
        return T();
    }

    bool isEmpty() const // Стек пустой?
    {
        return numItem == 0;
    }
};

// Функция для сортировки железнодорожного состава
void sortVagon(int input[], int n)
{
    TStack<int> stack(n); // Тупик (стек)
    int sorted[n]= {0};        // Отсортированный состав
    int sortedIndex = 0;
    int next = 1; // Ожидаемый номер вагона

    for (int i = 0; i < n; i++)
    {
        // Помещаем текущий вагон в тупик
        stack.push(input[i]);
        // cout << "Вагон " << input[i] << " перемещен в тупик" << endl;

        // Пока в тупике есть вагоны и верхний вагон - ожидаемый
        while (!stack.isEmpty() && stack.top() == next)
        {
            // cout << "Вагон " << next << " перемещен в выходной путь" << endl;
            sorted[sortedIndex++] = stack.pop();
            next++;
        }
    }
        // Проверяем, все ли вагоны были перемещены
        while (!stack.isEmpty()) {
            sorted[sortedIndex++] = stack.pop();
        }

    // Выводим отсортированный состав
    for (int i = 0; i < n; i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;
}

int main()
{
    std::setlocale(LC_ALL, "ru_RU.utf8");
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора

    int input[] = {3, 1, 2, 5, 4};            // Приехал состав с номерами вагонов
    int n = sizeof(input) / sizeof(input[0]); // Размер стека (количество вагонов)

    cout << "Исходный состав: ";
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << "\nОтсортированный состав: ";
    sortVagon(input, n);
    cout << endl;
    return 0;
}