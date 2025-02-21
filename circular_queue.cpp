// circular queue
#include <iostream>
#include <stdlib.h>
#define max 5
using namespace std;
int queue[max];
int front = -1;
int rear = -1;
int x, a;
void enqueue()
{
    if (front == (rear + 1) % max)
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        cout << "Enter data:" << endl;
        cin >> x;
        rear = (rear + 1) % max;
        if (front == -1)
        {
            front = 0;
        }
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue empty" << endl;
    }
    else if (front == rear)
    {
        cout << "The dequeued element is" << queue[front] << endl;
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "The dequeued element is" << queue[front] << endl;
        front = (front + 1) % max;
    }
}
int main()
{
    char ch;
    do
    {
        cout << "1.Enqueue" << endl
             << "2.dequeue" << endl
             << "3.Display" << endl
             << "4.Exit" << endl;
        cout << "Enter choice:" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (front == -1)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                int i = front;
                while (i != rear)
                {
                    cout << queue[i] << endl;
                    i = (i + 1) % max;
                }
                cout << queue[i];
            }
            break;
        case 4:
            exit(0);
        }
        cout << "Do you want to continue?(y/n):" << endl;
        cin >> ch;
    } while (ch != 'n');
    return 0;
}