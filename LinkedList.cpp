#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    // Конструктор без параметров, инициализирует val нулём и next как nullptr
    ListNode() {
        val = 0;
        next = nullptr;
    }

    // Конструктор с параметром данных, инициализирует val заданным значением и next как nullptr
    ListNode(int x) : val(x), next(nullptr) {}

    // Конструктор с параметром данных и указателем на следующий элемент списка
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    MyLinkedList() : head(nullptr), size(0) {} // Конструктор класса MyLinkedList
    size_t get_size() { return size; }    // Метод для получения размера списка
    void add_at_tail(int val);   // Метод для добавления элемента в конец списка
    void add_at_index(size_t index, int val); // Метод для добавления элемента по индексу
    void delete_at_index(size_t index);    // Метод для удаления элемента по индексу
    void addAtHead(int val); // Метод для добавления элемента в начало списка
    void print();   // Метод для вывода значений элементов списка
    void reverse(); // Метод для изменения порядка элементов в списке на обратный

private:
    ListNode* head; // Указатель на начало списка
    size_t size;    // Размер списка
};

// Метод добавления элемента в начало списка
void MyLinkedList::addAtHead(int val) {
    // Создать новый элемент списка с переданным значением и указателем на текущий head
    ListNode* newNode = new ListNode(val, head);

    // Обновить указатель head, чтобы он указывал на новый элемент
    head = newNode;

    // Увеличить размер списка
    ++size;
}

// Метод для вывода значений элементов списка
void MyLinkedList::print() {
    ListNode* current = head; // Указатель для прохода по списку, начиная с head

    // Пройти по всем элементам списка и вывести их значения через пробел
    while (current != nullptr) {
        cout << current->val << " "; // Вывести значение текущего элемента
        current = current->next; // Перейти к следующему элементу
    }

    cout << endl;
}

// Метод для изменения порядка элементов в списке на обратный
void MyLinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    // Пока не достигнут конец списка
    while (current != nullptr) {
        next = current->next; // Сохранить указатель на следующий элемент
        current->next = prev; // Изменить указатель на следующий элемент на предыдущий
        prev = current; // Переместить указатель на текущий элемент как предыдущий
        current = next; // Перейти к следующему элементу
    }

    head = prev; // Обновить указатель head на новое начало списка (бывший конец)
}

// Метод для добавления элемента в конец списка
void MyLinkedList::add_at_tail(int val) {
    // Создать новый элемент списка
    ListNode* newNode = new ListNode(val, nullptr);

    // Если список пуст, сделать новый элемент началом списка
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Иначе, найти текущий последний элемент и добавить новый элемент после него
    ListNode* it = head;
    while (it->next != nullptr)
        it = it->next;

    it->next = newNode;

    ++size; // Увеличить размер списка
}

// Метод для удаления элемента по индексу
void MyLinkedList::delete_at_index(size_t index) {
    if (index >= size + 1) {
        cout << "Index is larger than the size=" << size << "\n";
        return;
    }

    ListNode* prev = head;

    // Удаление первого элемента списка
    if (index == 0) {
        head = head->next;
        delete prev;
    }

    ListNode* curr = head->next;
    size_t pos = 0;

    // Поиск элемента для удаления и его удаление
    while (prev != nullptr && pos < index - 1) {
        prev = prev->next;
        curr = curr->next;
        ++pos;
    }

    prev->next = curr->next;
    delete curr;

    --size; // Уменьшить размер списка
}

// Метод для добавления элемента по индексу
void MyLinkedList::add_at_index(size_t index, int val) {
    ListNode* prev = head;
    ListNode* curr = head->next;
    size_t pos = 0;

    // Поиск места для вставки нового элемента
    while (prev != nullptr && pos < index - 1) {
        prev = prev->next;
        curr = curr->next;
        ++pos;
    }

    // Создание нового элемента и вставка его между prev и curr
    ListNode* newNode = new ListNode(val, curr);
    prev->next = newNode;

    ++size; // Увеличить размер списка
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    MyLinkedList* obj = new MyLinkedList();
    for (int val : arr) {
        obj->add_at_tail(val);
    }

    cout << "Original list: ";
    obj->print();

    cout << "Deleting the last element...\n";
    obj->delete_at_index(4);
    cout << "Modified list: ";
    obj->print();

    cout << "Add at index 3\n";
    obj->add_at_index((size_t)2, 10);

    cout << "Second modified list: ";
    obj->print();

    cout << "Adding at the head...\n";
    obj->addAtHead(0);

    cout << "Third modified list: ";
    obj->print();

    cout << "Reversed list: ";
    obj->reverse();
    obj->print();

    return 0;
}
