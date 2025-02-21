// singly circular linked list
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
struct node *pfirst = NULL, *pnew, *pthis, *ptemp, *plast;
void create()
{
    pnew = (struct node *)malloc(sizeof(struct node));
    cout << "enter data";
    cin >> pnew->info;
    num = num + 1;
}
void insbg() // insertion form beginning
{
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        plast->next = pfirst;
    }
    else
    {
        pnew->next = pfirst;
        pfirst = pnew;
        plast->next = pfirst;
    }
}
void insend() // insertion from end
{
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        plast->next = pfirst;
    }
    else
    {
        plast->next = pnew;
        plast = pnew;
        plast->next = pfirst;
    }
}
void insbf() // insertion before location
{
    int loc;
    cout << "enter location:";
    cin >> loc;
    if (loc == 1)
    {
        insbg();
    }
    else if (loc == 0)
    {
        cout << "Invalid location" << endl;
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
    else if (loc == 0)
    {
        cout << "Invalid location" << endl;
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
        while (pthis->next != pfirst)
        {
            cout << pthis->info << endl;
            pthis = pthis->next;
        }
        cout << pthis->info << endl;
    }
}
void delbg()
{
    if (pfirst == NULL)
    {
        cout << "list empty" << endl;
    }
    else if (pfirst == plast)
    {
        cout << "Deleted item is:" << pfirst->info << endl;
        free(pfirst);
        pfirst = NULL;
        plast = NULL;
    }
    else
    {
        ptemp = pfirst->next;
        cout << "Deleted item is:" << pfirst->info << endl;
        free(pfirst);
        pfirst = ptemp;
        plast->next = pfirst;
    }
    num = num - 1;
}
void delend()
{
    if (pfirst == NULL)
    {
        cout << "list empty" << endl;
    }
    else if (pfirst == plast)
    {
        cout << "Deleted item is:" << pfirst->info << endl;
        free(pfirst);
        pfirst = NULL;
        plast = NULL;
    }
    else
    {
        pthis = pfirst;
        while (pthis->next != plast)
        {
            pthis = pthis->next;
        }
        cout << "Deleted item is:" << plast->info << endl;
        free(plast);
        plast = pthis;
        plast->next = pfirst;
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
    else if (loc == 0)
    {
        cout << "Invalid location" << endl;
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