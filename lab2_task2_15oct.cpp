#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class queue
{
private:
    int head, tail, count, size;
    char *que;

public:
    queue(int s = 100)  
    {
        size = s;
        que = new char[size];
        head = 0;
        tail = -1;
        count = 0;
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

    char dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty. Cannot dequeue" << endl;
        }
        
        char item = que[head];
        head = (head + 1) % size;
        count--;
        return item;
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
            cout << que[current];
            current = (current + 1) % size;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return count == 0;
    }

};

string removeFirstName(const string& fullName)
{
    queue nameQueue;
    string result;
    bool firstNameRemoved = false;

    
    for (char c : fullName)
    {
        nameQueue.enqueue(c);
    }


    while (!nameQueue.isEmpty())
    {
        char c = nameQueue.dequeue();
        if (c == ' ' && !firstNameRemoved)
        {
            firstNameRemoved = true;
        }
        if (firstNameRemoved)
        {
            result += c;
        }
    }

    return result;
}

int main()
{
    string fullName = "Syed Areeb Zaheer";
    string lastName = removeFirstName(fullName);
    cout << "Full name: " << fullName << endl;
    cout << "After removing first name: " << lastName << endl;

    return 0;
}