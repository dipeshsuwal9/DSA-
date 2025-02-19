#include <iostream>
#include <cstdlib>
#define maxsize 5
using namespace std;
int main()
{
    int top = -1;
    int a;
    char stack[10];
    char ch;
    do
    {
        cout << "1.PUSH" << endl
             << "2.POP" << endl
             << "3.Display" << endl
             << "4.Exit" << endl;
        cout << "Enter choice:" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            if (top == maxsize - 1)
            {
                cout << "stack full" << endl;
            }
            else
            {
                top = top + 1;
                cout << "enter data" << endl;
                cin >> stack[top];
            }
            break;
        case 2:
            if (top < 0)
            {
                cout << "stack is empty" << endl;
            }
            else
            {
                cout << "The poped data is:" << stack[top] << endl;
                top = top - 1;
            }
            break;
        case 3:
            if (top < 0)
            {
                cout << "stack is empty" << endl;
            }
            else
            {
                for (int i = 0; i < top; i++)
                {
                    cout << stack[i] << endl;
                }
                break;
            case 4:
                exit(0);
            }
            cout << "Do you want to continue?(Y/N):" << endl;
            cin >> ch;
        }
    } while (ch != 'n' || ch != 'N');
    return 0;
}