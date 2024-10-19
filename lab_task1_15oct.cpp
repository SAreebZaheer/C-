#include <iostream>
#include <string>
using namespace std;

class stack
{
private:
    int top;
    int length;
    char *st;

public:
    stack()
    {
        st = new char[1];
        top = -1;
        length = 1;
    }

    void push(char item)
    {
        if (top < length)
        {
            top++;
            st[top] = item;
        }
        else
        {
            cout << "Stack Overflow, Stack is full" << endl;
        }
    }

    char pop()
    {
        if (top != -1)
        {
            char item;
            cout << "Item popped : " << st[top] << endl;
            item = st[top];
            top--;

            return item;
        }
    }

    bool isBalanced(const string &parentheses)
    {
        int count = 0;

        st = new char[parentheses.size()];
        length = parentheses.size();

        for (int i = 0; i <= parentheses.size() - 1; i++)
        {
            push(parentheses[i]);

            if (parentheses[i] == ')')
            {
                count--;
            }
            else if (parentheses[i] == '(')
            {
                count++;
            }

            if (count < 0)
            {
                return false;
                break;
            }
        }

        if (count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack stack1;
    bool flag;
    string test;

    cout << "Please enter the test string : ";
    cin >> test;

    flag = stack1.isBalanced(test);

    if (flag)
    {
        cout << "String is balanced" << endl;
    }
    else
    {
        cout << "String is not balanced" << endl;
    }
}