#include <iostream>
#include <stack>
#include <cctype> // for isdigit function

using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string &infix)
{
    stack<char> operators;
    string postfix;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch; // If operand, add to the postfix expression
        }
        else if (ch == '(')
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        }
        else if (isOperator(ch))
        {
            while (!operators.empty() && getPrecedence(ch) <= getPrecedence(operators.top()))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string &postfix)
{
    stack<int> operands;

    for (char ch : postfix)
    {
        if (isalnum(ch))
        {
            operands.push(ch - '0'); // Convert character to integer and push to stack
        }
        else if (isOperator(ch))
        {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (ch)
            {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                operands.push(operand1 / operand2);
                break;
            }
        }
    }

    return operands.top();
}

int main()
{
    string infixExpression;
    cout << "Enter the infix expression: ";
    cin >> infixExpression;

    // Convert infix to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
