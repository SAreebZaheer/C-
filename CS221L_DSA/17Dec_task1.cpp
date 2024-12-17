#include <iostream>
#include <list>
#include <string>

using namespace std;

struct node
{
    string name;
    int ID;
    string department;
    float GPA;
};

class HashMapTable
{
public:
    list<node> *table;
    int tableSize;

    HashMapTable()
    {
        tableSize = 11;
        table = new list<node>[tableSize];
    }

    int hashFunction(int data)
    {
        int index;

        index = data % tableSize;

        return index;
    }

    void insertElement(node data)
    {
        int index;

        index = hashFunction(data.ID);
        table[index].push_back(data);
    }

    void printTable()
    {
        for (int i = 0; i < tableSize; i++)
        {
            cout << "Bucket " << i+1 << ": ";
            if (table[i].empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                for (auto it = table[i].begin(); it != table[i].end(); ++it)
                {
                    cout << "Name: " << it->name << ", ID: " << it->ID << ", Department: "
                         << it->department << ", GPA: " << it->GPA << "; ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    HashMapTable table1;
    int choice;

    cout << "Please enter 1 if you want to insert elements on your own, or 2 to insert 10 predetermined elements: ";
    cin >> choice;

    if (choice == 1)
    {
        for (int i = 0; i < 11; i++)
        {
            node data;

            cout << "Please enter the name of the student: ";
            cin >> data.name;
            cout << "Please enter the student ID: ";
            cin >> data.ID;
            cout << "Please enter the department of the student: ";
            cin >> data.department;
            cout << "Please enter the GPA of the student: ";
            cin >> data.GPA;

            table1.insertElement(data);
        }
    }
    else if (choice == 2)
    {
        // Predefined student data (replace with your actual data)
        node student1 = {"Alice", 123, "CS", 3.8};
        node student2 = {"Bob", 456, "Math", 3.5};
        node student3 = {"Charlie", 789, "Physics", 3.9};
        node student4 = {"David", 010, "Engineering", 3.7};
        node student5 = {"Emily", 567, "English", 4.0};
        node student6 = {"Frank", 890, "History", 3.2};
        node student7 = {"Grace", 234, "Biology", 3.9};
        node student8 = {"Henry", 678, "Chemistry", 3.6};
        node student9 = {"Isabella", 901, "Psychology", 3.8};
        node student10 = {"Jack", 345, "Philosophy", 3.4};

        // Insert each student into the hash table
        table1.insertElement(student1);
        table1.insertElement(student2);
        table1.insertElement(student3);
        table1.insertElement(student4);
        table1.insertElement(student5);
        table1.insertElement(student6);
        table1.insertElement(student7);
        table1.insertElement(student8);
        table1.insertElement(student9);
        table1.insertElement(student10);
    }

    table1.printTable();
}