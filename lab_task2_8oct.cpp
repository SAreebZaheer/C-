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

        cout << "Current length of the linked list is " << nodeCount << endl;
    }

    void traverse()
    {
        current = head;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void deletion(int pos)
    {
        int count = 1;
        current = head;
        bool del = false;
        while (del != true && count <= nodeCount)
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
                    nodeCount--;
                }
                else if (current->next == NULL)
                {
                    tail = previous;
                    previous->next = NULL;
                    del = true;
                    nodeCount--;
                }
                else
                {
                    previous->next = next;
                    next->prev = previous;
                    del = true;
                    nodeCount--;
                }
            }

            current = current->next;
            count++;
        }
    }

    void removeDup()
    {
        current = head;

        while (current != NULL)
        {
            node *duplicate = current->next;
            while (duplicate != NULL)
            {
                if (duplicate->data == current->data)
                {
                    
                    if (duplicate->prev)
                    {
                        duplicate->prev->next = duplicate->next;
                    }
                    else if (duplicate->next)
                    {
                        duplicate->next->prev = duplicate->prev;
                    }
                    else if (duplicate == tail)
                    {
                        tail = duplicate->prev;
                    }
                    node *temp = duplicate;   
                    duplicate = duplicate->next; 
                }
                else
                {
                    duplicate = duplicate->next;
                }
            }
            current = current->next;
        }
    }
};

int main()
{
    linkedList list1;

    list1.addNew(1, 1);
    list1.addNew(1, 2);
    list1.addNew(4, 3);
    list1.addNew(2, 4);
    list1.addNew(1, 5);
    list1.addNew(3, 6);
    list1.addNew(3, 7);
    list1.addNew(2, 8);
    list1.addNew(4, 9);
    list1.addNew(2, 10);
    list1.addNew(1, 11);

    cout << "Unsorted original linked list : " << endl;
    list1.traverse();

    list1.removeDup();

    cout << "Unsorted corrected linked list : " << endl;
    list1.traverse();
}