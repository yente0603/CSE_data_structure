#include <iostream>
using namespace std;
/*compiler standard: g++11*/
class linkedList;
class doubleLinkedList;
class listNode
{
private:
    int data;
    listNode *next;

public:
    listNode() : data(0), next(nullptr) {}
    listNode(int num) : data(num), next(nullptr) {}
    friend class linkedList;
};
class doubleListNode
{
private:
    int data;
    doubleListNode *left, *right;

public:
    doubleListNode() : data(0), left(nullptr), right(nullptr) {}
    doubleListNode(int num) : data(num), left(nullptr), right(nullptr) {}
    friend class doubleLinkedList;
};
class linkedList
{
private:
    listNode *first;

public:
    linkedList() : first(nullptr) {}
    void printlist() const;
    void insert_front(const int x);
    void insert_back(const int x);
    void insert_middle(const int x, const int y);
    void deletenode(int x);
    void clear();
    void concatenation(const linkedList &list);
    void reserve();
};
class doubleLinkedList : linkedList
{
private:
    doubleLinkedList *head;

public:
    doubleLinkedList() : head(nullptr) {}
    void insert(int x)
    {
    }
};
void linkedList::printlist() const
{
    if (first == 0)
        fprintf(stdout, "list is empty!\n");
    else
    {
        listNode *current = first;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}
void linkedList::insert_front(const int x)
{
    listNode *newNode = new listNode(x);
    newNode->next = first;
    first = newNode;
}
void linkedList::insert_back(const int x)
{
    listNode *newNode = new listNode(x);
    if (first)
    {
        listNode *current = first;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }
    else
        first = newNode;
}
void linkedList::insert_middle(const int x, const int y)
{
    listNode *current = first,
             *newNode = new listNode(y);

    while (current->next != nullptr && current->data != x)
        current = current->next;
    if (current->data != x) // node is nonexistant
        fprintf(stdout, "there is no %d node in the list, no insertion.\n", x);
    else if (current)
    {
        listNode *newNode = new listNode(y);
        newNode->next = current->next;
        current->next = newNode;
    }
    else
    {
        listNode *newNode = new listNode(y);
        first = newNode;
    }
}
void linkedList::deletenode(int x)
{
    listNode *current = first,
             *previous = nullptr;
    while (current != nullptr && current->data != x)
    {
        previous = current;
        current = current->next;
    }
    if (!current) // list is empty
        fprintf(stdout, "there is no %d node in the list.\n", x);
    else if (current == first)
    {
        first = first->next;
        delete current;
        current = nullptr;
    }
    else
    {
        previous->next = current->next;
        delete current;
        current = nullptr;
    }
}
void linkedList::clear()
{
    while (first)
    {
        listNode *current = first;
        first = first->next;
        delete current;
        current = nullptr;
    }
}
void linkedList::concatenation(const linkedList &newList)
{
    // newList is concatenated to the end of *this.
    if (newList.first == nullptr) // newList is empty
        fprintf(stdout, "no new list.\n");
    else if (first) // nonempty of original list
    {
        listNode *current = first;
        while (current)
            current = current->next;
        current->next = newList.first; // concatenation
    }
    else // empty of original list; however, new list is nonempty
        first = newList.first;
}
void linkedList::reserve()
{
    listNode *current = first,
             *previous = nullptr;
    while (current)
    {
        listNode *r = previous;
        previous = current;
        current = current->next;
        previous->next = r;
    }
    first = previous;
}
int main()
{
    linkedList list;
    list.printlist();
    list.insert_front(10);
    list.insert_front(12);
    list.insert_back(9);
    list.insert_back(22);
    list.insert_back(30);
    list.printlist();
    list.insert_middle(9, 38);
    list.printlist();
    list.insert_middle(33, 38);
    list.printlist();
    list.deletenode(10);
    list.printlist();
    list.reserve();
    list.printlist();
    list.clear();
    list.printlist();
    return 0;
}