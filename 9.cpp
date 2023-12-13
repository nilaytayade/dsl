#include <iostream>
#include <string>
using namespace std;

class stack
{
private:
    int a[100];
    int top = -1;

public:
    void pop()
    {
        top--;
    }

    int peek()
    {
        return a[top];
    }

    void push(int val)
    {
        top++;
        a[top] = val;
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << a[i] << " ";
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    stack obj;
    string input;
    cin >> input;
    int length = input.length();

    for (int i = 0; i < length; i++)
    {
        if (input[i] == '[' || input[i] == '(' || input[i] == '{')
        {
            obj.push(input[i]);
        }
        else if ((input[i] == ')' && obj.peek() == '(') ||
                 (input[i] == '}' && obj.peek() == '{') ||
                 (input[i] == ']' && obj.peek() == '['))
        {
            obj.pop();
        }
    }

    if (obj.isEmpty())
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}
