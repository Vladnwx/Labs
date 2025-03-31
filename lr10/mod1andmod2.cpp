#include <iostream>
using namespace std;

// Узел списка
template <typename T>
struct Node
{
    T data;     // Данные
    Node *next; // Указатель на следующий узел

    Node(const T &value) : data(value), next(nullptr) {}
};

// Класс односвязного списка
template <typename T>
class LinkedList
{
private:
    Node<T> *head; // Указатель на голову списка
    Node<T> *tail; // Указатель на хвост списка (для удобства добавления)
    size_t size;   // Размер списка

public:
    // Конструктор
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Деструктор
    ~LinkedList()
    {
        clear();
    }

    // Добавление в конец
    void push_back(const T &value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Добавление в начало
    void push_front(const T &value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr)
        {
            tail = head;
        }
        size++;
    }

    // Удаление первого элемента
    void pop_front()
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    // Удаление последнего элемента
    void pop_back()
    {
        if (head == nullptr)
            return;

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }

        Node<T> *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
    }

    // Очистка списка
    void clear()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }

    // Получение размера
    size_t getSize() const
    {
        return size;
    }

    // Проверка на пустоту
    bool empty() const
    {
        return size == 0;
    }

    // Вывод списка
    void print() const
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Поиск элемента
    Node<T> *find(const T &value) const
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Вставка после указанного значения
    bool insert(const T &after_value, const T &new_value)
    {
        Node<T> *target = find(after_value);
        if (target == nullptr)
        {
            return false; // Элемент не найден
        }

        Node<T> *newNode = new Node<T>(new_value);
        newNode->next = target->next;
        target->next = newNode;

        // Если вставляли после последнего элемента, обновляем tail
        if (target == tail)
        {
            tail = newNode;
        }

        size++;
        return true;
    }

    // Удаление элемента по значению
    bool remove(const T &value)
    {
        if (head == nullptr)
            return false;

        // Особый случай: удаление первого элемента
        if (head->data == value)
        {
            pop_front();
            return true;
        }

        Node<T> *current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            return false; // Элемент не найден
        }

        Node<T> *toDelete = current->next;
        current->next = toDelete->next;

        // Если удаляли последний элемент, обновляем tail
        if (toDelete == tail)
        {
            tail = current;
        }

        delete toDelete;
        size--;
        return true;
    }


};

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "ru_RU.utf8");
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора
    LinkedList<int> list;
    list.push_back(1);
    list.push_front(0);
    // Добавление в конец списка четырех элементов 2,3,4,5
    for (int i = 2; i < 6; i++)
        list.push_back(i);
    
        list.print();


    // Вставка элемента 200 после элемента 2
    list.insert(2, 200);
    // Удаление элемента 5
    if (!list.remove(5))
        cout << "не найден";

    list.print();


    return 0;
}
