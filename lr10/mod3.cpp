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

        // Метод для перемещения элемента из одного списка в другой
        bool moveTo(LinkedList<T>& destination, const T& value) {
            Node<T>* node = find(value);
            if (node == nullptr) return false;
    
            // Создаем копию данных
            T dataCopy = node->data;
            
            // Удаляем из текущего списка
            if (!remove(dataCopy)) return false;
            
            // Добавляем в целевой список
            destination.push_back(dataCopy);
            return true;
        }

};

// Структура для хранения данных об автобусе
struct Bus
{
    int busNumber;
    string driverName;
    int routeNumber;

    // Конструктор
    Bus(int num = 0, const string &name = "", int route = 0)
        : busNumber(num), driverName(name), routeNumber(route) {}

    // Перегрузка оператора == для поиска по номеру автобуса
    bool operator==(const Bus &other) const
    {
        return busNumber == other.busNumber;
    }

    // Перегрузка оператора << для вывода информации об автобусе
    friend ostream &operator<<(ostream &os, const Bus &bus)
    {
        os << "Автобус №" << bus.busNumber << " (Маршрут №" << bus.routeNumber
           << "), Водитель: " << bus.driverName;
        return os;
    }
};
// Функция для ввода данных об автобусе
Bus inputBusData() {
    int number, route;
    string name;

    cout << "Введите номер автобуса: ";
    cin >> number;
    cin.ignore(); // Очищаем буфер после ввода числа

    cout << "Введите фамилию и инициалы водителя: ";
    getline(cin, name);

    cout << "Введите номер маршрута: ";
    cin >> route;

    return Bus(number, name, route);
}

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "ru_RU.utf8");
    std::cout << "\033[2J\033[H"; // Очистка экрана и перемещение курсора
    
    LinkedList<Bus> busesInDepot;    // Автобусы в парке
    LinkedList<Bus> busesOnRoute;    // Автобусы на маршруте

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить автобус в парк\n";
        cout << "2. Отправить автобус на маршрут\n";
        cout << "3. Вернуть автобус в парк\n";
        cout << "4. Показать автобусы в парке\n";
        cout << "5. Показать автобусы на маршруте\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Добавление автобуса в парк
                Bus newBus = inputBusData();
                busesInDepot.push_back(newBus);
                cout << "Автобус добавлен в парк.\n";
                break;
            }
            case 2: {
                // Отправка автобуса на маршрут
                if (busesInDepot.empty()) {
                    cout << "В парке нет автобусов.\n";
                    break;
                }

                cout << "Введите номер автобуса для отправки на маршрут: ";
                int busNum;
                cin >> busNum;

                Bus tempBus(busNum); // Создаем временный объект для поиска
                if (busesInDepot.moveTo(busesOnRoute, tempBus)) {
                    cout << "Автобус №" << busNum << " отправлен на маршрут.\n";
                } else {
                    cout << "Автобус с номером " << busNum << " не найден в парке.\n";
                }
                break;
            }
            case 3: {
                // Возврат автобуса в парк
                if (busesOnRoute.empty()) {
                    cout << "На маршруте нет автобусов.\n";
                    break;
                }

                cout << "Введите номер автобуса для возврата в парк: ";
                int busNum;
                cin >> busNum;

                Bus tempBus(busNum); // Создаем временный объект для поиска
                if (busesOnRoute.moveTo(busesInDepot, tempBus)) {
                    cout << "Автобус №" << busNum << " возвращен в парк.\n";
                } else {
                    cout << "Автобус с номером " << busNum << " не найден на маршруте.\n";
                }
                break;
            }
            case 4: {
                // Показать автобусы в парке
                cout << "\nАвтобусы в парке (" << busesInDepot.getSize() << "):\n";
                if (busesInDepot.empty()) {
                    cout << "В парке нет автобусов.\n";
                } else {
                    busesInDepot.print();
                }
                break;
            }
            case 5: {
                // Показать автобусы на маршруте
                cout << "\nАвтобусы на маршруте (" << busesOnRoute.getSize() << "):\n";
                if (busesOnRoute.empty()) {
                    cout << "На маршруте нет автобусов.\n";
                } else {
                    busesOnRoute.print();
                }
                break;
            }
            case 0: {
                cout << "Выход из программы.\n";
                break;
            }
            default: {
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
