#include <iostream>
#include <cstring>
using namespace std;

char pop();
void push(char);
int check_pre(char);

int top = -1;
char postfix[30];
char infix[30];
char stack[30];

int main()
{
    cout << "Enter infix expression: ";
    cin >> infix;
    int n = strlen(infix);
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (infix[i] >= 33 && infix[i] <= 47)
        {
            if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (top != -1 && stack[top] != '(')
                {
                    postfix[pos++] = pop();
                }
                pop(); // Remove '(' from stack
            }
            else
            { // Operator
                while (top != -1 && check_pre(stack[top]) >= check_pre(infix[i]))
                {
                    postfix[pos++] = pop();
                }
                push(infix[i]);
            }
        }

        while (top != -1)
        { // Pop all remaining operators
            postfix[pos++] = pop();
        }

        // postfix[pos] = '\0'; // Null terminate the string
        cout << "The postfix expression: " << postfix << endl;

        return 0;
    }
}

int check_pre(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    if (ch == '+' || ch == '-')
        return 2;
    return -1; // For any other character
}

void push(char data)
{
    if (top < 29)
    { // Prevent stack overflow
        stack[++top] = data;
    }
}

char pop()
{
    if (top != -1)
    {
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}