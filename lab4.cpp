// singly linear linked list
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int num = 0;
struct node
{
    int info;
    struct node *next;
};
struct node *pfirst = NULL, *pnew, *pthis, *ptemp;
void create()
{
    // int data;
    pnew = (struct node *)malloc(sizeof(struct node));
    cout << "enter data";
    cin >> pnew->info;
    num = num + 1;
}
void insbg()
{
    if (pfirst == NULL)
    {
        pfirst = pnew;
        pnew->next = NULL;
    }
    else
    {
        pnew->next = pfirst;
        pfirst = pnew;
    }
}
void insend()
{
    if (pfirst == NULL)
    {
        pfirst = pnew;
    }
    else
    {
        pthis = pfirst;
        while (pthis->next != NULL)
        {
            pthis = pthis->next;
        }
        pthis->next = pnew;
    }
}
void insbf()
{
    int loc;
    cout << "enter location:";
    cin >> loc;
    if (loc == 1)
    {
        insbg();
    }
    else
    {
        pthis = pfirst;
        for (int i = 1; i < loc - 1; i++)
        {
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;
    }
}
void insaf()
{
    int loc;
    cout << "enter location:";
    cin >> loc;
    if (loc == num)
    {
        insend();
    }
    else
    {
        pthis = pfirst;
        for (int i = 1; i < loc; i++)
        {
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;
    }
}
void display()
{
    if (pfirst == NULL)
    {
        cout << "list empty" << endl;
    }
    else
    {
        pthis = pfirst;
        while (pthis != NULL)
        {
            cout << pthis->info << endl;
            pthis = pthis->next;
        }
    }
}
void delbg()
{
    if (pfirst == NULL)
    {
        cout << "list empty" << endl;
    }
    else if (pfirst->next == NULL)
    {
        cout << "Deleted item is:" << pfirst->info << endl;
        free(pfirst);
        pfirst = NULL;
    }
    else
    {
        ptemp = pfirst->next;
        cout << "Deleted item is:" << pfirst->info << endl;
        free(pfirst);
        pfirst = ptemp;
    }
    num = num - 1;
}
void delend()
{
    if (pfirst == NULL)
    {
        cout << "list empty" << endl;
    }
    else if (pfirst->next == NULL)
    {
        cout << "Deleted item is:" << pfirst->info << endl;
        free(pfirst);
        pfirst = NULL;
    }
    else

    {
        pthis = pfirst;
        while (pthis->next->next != NULL)
        {
            pthis = pthis->next;
        }
        cout << "Deleted item is:" << pthis->next->info << endl;
        free(pthis->next);
        pthis->next = NULL;
        num = num - 1;
    }
}
void delsp()
{
    int loc;
    cout << "enter location" << endl;
    cin >> loc;
    if (loc == 1)
    {
        delbg();
    }
    else if (loc == num)
    {
        delend();
    }
    else
    {
        for (int i = 1; i <= loc - 1; i++)
        {
            pthis = pthis->next;
        }
        cout << "Deleted item is:" << pfirst->next->info << endl;
        ptemp = pthis->next->next;
        free(pthis->next);
        pthis->next = ptemp;
        num = num - 1;
    }
}
int main()
{
    char ch;
    int a;
    do
    {
        cout << "1.Insertion from beginning" << endl
             << "2.Insertion from end" << endl
             << "3.Insertion before location" << endl
             << "4.Insertion after location" << endl
             << "5.Deletion form beginning" << endl
             << "6.Deletion from end" << endl
             << "7.Deleting specified node" << endl
             << "8.Display" << endl
             << "9.Exit" << endl;
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