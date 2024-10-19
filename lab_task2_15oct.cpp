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

        else
        {
            return NULL;
        }
    }

    string reverseString(string &input)
    {
        int count = 0;
        char reverse;
        string result;

        st = new char[input.size()];
        length = input.size();

        for (int i = 0; i <= input.size() - 1; i++)
        {
            push(input[i]);
        }

        for (int i = 0; i <= input.size() - 1; i++)
        {
            reverse = pop();
            result += reverse;
        }

        return result;
    }
};

int main()
{
    stack stack1;
    string test, res;

    cout << "Please enter the test string : ";
    cin >> test;

    res = stack1.reverseString(test);

    cout << "Reversed String: " << res << endl;

    return 0;
}