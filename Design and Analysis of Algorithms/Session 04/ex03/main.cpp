#include <iostream>
#include <vector>

typedef struct Node{
    int value;
    Node* next;
    Node* prev;
} Node;

typedef struct LinkedList{
    Node* head;
    Node* tail;
} LinkedList;

void releaseMemory(LinkedList* list)
{
    Node* current = list->head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    list->head = nullptr;
    list->tail = nullptr;
}

Node* partition(LinkedList* list, Node* low, Node* high)
{
    Node* pivot = high;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->value < pivot->value) {
            i = (i == nullptr) ? low : i->next;
            std::swap(i->value, j->value);
        }
    }

    i = (i == nullptr) ? low : i->next;
    std::swap(i->value, pivot->value);
    return i;
}

void QuickSort(LinkedList* list, Node* low, Node* high)
{
    if (low == nullptr || high == nullptr || low == high || low == high->next) return;

    Node* pivot = partition(list, low, high);
    if (pivot->prev != nullptr)
        QuickSort(list, low, pivot->prev);
    if (pivot->next != nullptr)
        QuickSort(list, pivot->next, high);
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    std::cin >> n;

    LinkedList list;
    list.head = nullptr;
    list.tail = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;

        Node* newNode = new Node{value, nullptr, nullptr};
        if (list.head == nullptr) {
            list.head = newNode;
            list.tail = newNode;
        } else {
            list.tail->next = newNode;
            newNode->prev = list.tail;
            list.tail = newNode;
        }
    }

    QuickSort(&list, list.head, list.tail);
    for (Node* current = list.head; current != nullptr; current = current->next) {
        std::cout << current->value << " ";
    }
    std::cout << std::endl;

    releaseMemory(&list);
    return 0;
}