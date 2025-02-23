#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int num = 0;
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *pnew, *pthis, *ptemp, *plast, *ptemp1;
struct node *head;
void create()
{
    pnew = (struct node *)malloc(sizeof(struct node));
    cout << "Enter data:" << endl;
    cin >> pnew->info;
    num = num + 1;
}
void insbg() // insertion from beginning
{
    if (head->next == head)
    {
        head->next = pnew;
        pnew->prev = head;
        pnew->next = head;
        head->prev = pnew;
    }
    else
    {
        ptemp = head->next;
        head->next = pnew;
        pnew->prev = head;
        pnew->next = ptemp;
        ptemp->prev = pnew;
    }
}
void insend() // insertion from end
{
    if (head->next == head)
    {
        head->next = pnew;
        pnew->prev = head;
        pnew->next = head;
        head->prev = pnew;
    }
    else
    {
        ptemp = head->prev;
        head->prev = pnew;
        pnew->next = head;
        pnew->prev = ptemp;
        ptemp->next = pnew;
    }
}
void insbf() // insertion before location
{
    int loc;
    cout << "Enter Location:" << endl;
    cin >> loc;
    if (loc > num || loc < 1)
    {
        cout << "Invalid Location" << endl;
    }
    else if (head->next == head)
    {
        head->next = pnew;
        pnew->prev = head;
        pnew->next = head;
        head->prev = pnew;
    }
    else if (loc == 1)
    {
        insbg();
    }
    else
    {
        pthis = head->next;
        for (int i = 1; i <= loc - 1; i++)
        {
            pthis = pthis->next;
        }
        ptemp = pthis->prev;
        ptemp->next = pnew;
        pnew->prev = ptemp;
        pnew->next = pthis;
        pthis->prev = pnew;
    }
}
void insaf() // insertion after location
{
    int loc;
    cout << "Enter Location:" << endl;
    cin >> loc;
    if (loc > num || loc < 1)
    {
        cout << "Invalid Location" << endl;
    }
    else if (loc == num)
    {
        insend();
    }
    else
    {
        pthis = head->next;
        for (int i = 1; i < loc; i++)
        {
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        ptemp->prev = pnew;
        pnew->next = ptemp;
        pnew->prev = pthis;
        pthis->next = pnew;
    }
}
void delbg() // deletion from beginning
{
    if (head->next == head)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        ptemp = head->next->next;
        cout << "Deleted item is " << head->next->info << endl;
        free(head->next);
        head->next = ptemp;
        ptemp->prev = head;
    }
    num = num - 1;
}
void delend() // deletion from end
{
    if (head->next == head)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        ptemp = head->prev->prev;
        cout << "Deleted item is " << head->prev->info << endl;
        free(head->prev);
        head->prev = ptemp;
        ptemp->next = head;
    }
    num = num - 1;
}
void delsp() // deletion from specific position
{
    int loc;
    cout << "Enter Location:" << endl;
    cin >> loc;
    if (loc > num || loc < 1)
    {
        cout << "Invalid Location" << endl;
    }
    else if (loc == 1)
    {
        delbg();
    }
    else if (loc == num)
    {
        delend();
    }
    else
    {
        pthis = head->next;
        for (int i = 1; i <= loc - 1; i++)
        {
            pthis = pthis->next;
        }
        ptemp1 = pthis->next;
        ptemp = pthis->prev;
        cout << "Deleted item is " << pthis->info << endl;
        free(pthis);
        ptemp->next = ptemp1;
        ptemp1->prev = ptemp;
        num = num - 1;
    }
}
void display()
{
    if (head->next == head)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        pthis = head->next;
        while (pthis != head)
        {
            cout << pthis->info << endl;
            pthis = pthis->next;
        }
    }
}
int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    head->next = head;
    head->prev = head;
    head->info = 0;
    char ch;
    int a;

    cout << "1.Insertion from beginning" << endl
         << "2.Insertion from end" << endl
         << "3.Insertion before location" << endl
         << "4.Insertion after location" << endl
         << "5.Deletion form beginning" << endl
         << "6.Deletion from end" << endl
         << "7.Deleting specified node" << endl
         << "8.Display" << endl
         << "9.Exit" << endl;
    do
    {
        cout << "Enter choice:";
        cin >> a;
        switch (a)
        {
        case 1:
            create();
            insbg();
            break;
        case 2:
            create();
            insend();
            break;
        case 3:
            create();
            insbf();
            break;
        case 4:
            create();
            insaf();
            break;
        case 5:
            delbg();
            break;
        case 6:
            delend();
            break;
        case 7:
            delsp();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        }
        cout << "continue?(y/n):";
        cin >> ch;
    } while (ch != 'n');
    return 0;
}