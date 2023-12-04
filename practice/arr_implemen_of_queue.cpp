#include <iostream>
using namespace std;
template <class T>

class queue
{
public:
    queue(int stackcapacity = 0);
    inline bool Empty() const
    // "inline" suggests compilier call the code
    // "const" for function: could NOT change the value of member
    {
        return front = rear;
    }
    void Push(const T &item)
    {
        if ((rear + 1) % capacity == front)
            throw "queue is full!";
        // "throw": exception
        rear = (rear + 1) & capacity;
        queue[rear] = x;
    }
    void Pop()
    {
        if (Empty())
            throw "queue is empty!";
        front = (front + 1) % capacity;
        queue[front].~T(); // destructor for T
    }
    inline bool front
    {
        if (Empty())
            throw "queue is empty!";
        return queue[(front + 1) % capacity];
    }
    inline bool rear()
    {
        if (Empty())
            throw "queue is empty!";
        return queue[rear];
    }
    inline T &Top() const
    {
        if (Empty())
            throw "queue is empty!";
        return stack[top];
    }
    ~queue();

private:
    T *queue;
    int front, rear, capacity;
};

template <class T>
queue<T>::queue(int queuecapacity) : capcatity(queuecapacity)
{
    queue = new T[capcatity];
    front = rear = capacity = -1; // 0 is ok as well
}
int main()
{

    return 0;
}