#include <iostream>
using namespace std;

class queue
{
private:
    int head, tail, count, size;
    char *que;

public:
    queue()
    {
        que = new char[5];
        head = 0;
        tail = -1;
        count = 0;
        size = 5;
    }

    void enqueue(char item)
    {
        if (count == size)
        {
            cout << "Queue is full. Cannot enqueue" << endl;
            return;
        }

        tail = (tail + 1) % size;
        que[tail] = item;
        count++;
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return;
        }

        cout << "Dequeued item: " << que[head] << endl;
        head = (head + 1) % size;
        count--;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        int current = head;
        for (int i = 0; i < count; i++)
        {
            cout << que[current] << " ";
            current = (current + 1) % size;
        }
        cout << endl;
    }

};

int main()
{
    queue q;

    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.display(); // Output: a b c
    q.dequeue();
    q.dequeue();
    q.enqueue('d');
    q.enqueue('e');
    q.display(); // Output: c d e
    q.dequeue();
    q.display(); // Output: d e

    return 0;
}