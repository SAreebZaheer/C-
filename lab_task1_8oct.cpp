#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

class linkedList
{
private:
    node *head;
    node *tail;
    node *current;
    node *previous;
    node *next;

public:
    int nodeCount;
    linkedList()
    {
        head = NULL;
        tail = NULL;
        nodeCount = 0;
    }

    void addNew(int item, int pos)
    {
        if (pos == 1)
        {
            if (head == NULL)
            {
                node *newNode = new node;
                head = newNode;
                newNode->data = item;
                newNode->next = NULL;
                newNode->prev = NULL;
            }
            else
            {
                node *newNode = new node;
                newNode->data = item;
                newNode->prev = NULL;
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            cout << "New node added at the start." << endl;
        }
        else
        {
            int count = 1;
            current = head;
            while (current->next != NULL)
            {
                current = current->next;
                count++;
            }

            if (pos - 1 == count)
            {
                node *newNode = new node;
                newNode->data = item;
                current->next = newNode;
                newNode->prev = current;
                newNode->next = NULL;
                tail = newNode;

                cout << "New node added at the end." << endl;
            }
        }

        nodeCount++;

        cout << "Curent length of the linked list is " << nodeCount << endl;
    }

    void deletion(int pos)
    {
        int count = 1;
        current = head;
        bool del = false;
        while (del != true || count > nodeCount)
        {
            previous = current->prev;
            next = current->next;
            if (pos == count)
            {
                if (current->prev == NULL)
                {
                    head = next;
                    next->prev = NULL;
                    del = true;
                }
                else if (current->next == NULL)
                {
                    tail = previous;
                    previous->next = NULL;
                    del = true;
                }
                else
                {
                    previous->next = next;
                    next->prev = previous;
                    del = true;
                }
            }

            current = current->next;
            count++;
        }
    }
    void traverse()
    {
        current = head;

        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main()
{
    linkedList list1;
    int item;
    int pos;
    int choice = 100;

    while (choice != 0)
    {
        cout << "Please enter 0 to exit, 1 to enter a new data item, 2 to delete item, or -1 to display all items." << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Please enter the data item you want to add: ";
            cin >> item;
            cout << "Please enter the position where you want to add the data item. Current Length of List is " << list1.nodeCount << endl;
            cin >> pos;

            list1.addNew(item, pos);
        }
        else if (choice == -1)
        {
            list1.traverse();
        }
        else if (choice == 2)
        {
            cout << "Please enter the position where you want to delete the data item. Current Length of List is " << list1.nodeCount << endl;
            cin >> pos;

            list1.deletion(pos);
        }
    }
}