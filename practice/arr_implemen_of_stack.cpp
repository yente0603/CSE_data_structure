#include <iostream>
using namespace std;
template <class T>

class Stack
{
public:
    Stack(int stackcapacity = 0);
    inline bool Empty() const
    // "inline" suggests compilier call the code
    // "const" for function: could NOT change the value of member
    {
        return top == -1;
    }
    void Push(const T &item)
    {
        if (top == capcatity - 1)
            throw "stack is overflow!";
        // "throw": exception
        stack[++top] = item;
    }
    void Pop()
    {
        if (Empty())
            throw "stack is overflow!";
        stack[top--].~T(); // destructor for T
    }
    inline T &Top() const
    {
        if (Empty())
            throw "stack is overflow!";
        return stack[top];
    }
    ~Stack();

private:
    T *stack;
    int top, capcatity;
};

template <class T>
Stack<T>::Stack(int stackcapacity) : capcatity(stackcapacity)
{
    Stack = new T[capcatity];
    top = -1;
}
int main()
{

    return 0;
}