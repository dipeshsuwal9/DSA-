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
struct node *pfirst = NULL, *pnew, *pthis, *ptemp, *plast, *ptemp1;
void create()
{
    pnew = (struct node *)malloc(sizeof(struct node));
    cout << "Enter data:";
    cin >> pnew->info;
    num = num + 1;
}
void insbg() // insertion from beginning
{
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        pfirst->next = NULL;
        pfirst->prev = NULL;
    }
    else
    {
        pnew->prev = NULL;
        pnew->next = pfirst;
        pfirst->prev = pnew;
        pfirst = pnew;
    }
}
void insend() // insertion from end
{
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        pfirst->next = NULL;
        pfirst->prev = NULL;
    }
    else
    {
        plast->next = pnew;
        pnew->prev = plast;
        pnew->next = NULL;
        plast = pnew;
    }
}
void insbf() // insertion before location
{
    int loc;
    cout << "Enter Location:" << endl;
    cin >> loc;
    pthis = pfirst;
    for (int i = 1; i < loc - 1; i++)
    {
        pthis = pthis->next;
    }
    ptemp = pthis->next;
    ptemp->prev = pnew;
    pnew->prev = pthis;
    pnew->next = ptemp;
    pthis->next = pnew;
}
void insaf() // insertion after location
{
    int loc;
    cout << "Enter location:" << endl;
    cin >> loc;
    pthis = pfirst;
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
void delbg() // deletion from beginning
{
    if (pfirst == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (pfirst->next == NULL)
    {
        cout << "Deleted item is" << pfirst->info << endl;
        free(pfirst);
        pfirst = NULL;
        pfirst->prev = NULL;
        plast = NULL;
        plast->next = NULL;
    }
    else
    {
        ptemp = pfirst->next;
        cout << "Deleted item is" << pfirst->info << endl;
        free(pfirst);
        pfirst = ptemp;
        pfirst->prev = NULL;
    }
    num = num - 1;
}
void delend() // deletion from end
{
    if (pfirst == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (pfirst->next == NULL)
    {
        cout << "Deleted item is" << pfirst->info << endl;
        free(pfirst);
        pfirst = NULL;
        pfirst->prev = NULL;
        plast = NULL;
        plast->next = NULL;
    }
    else
    {
        ptemp = plast->prev;
        cout << "Deleted item is" << plast->info << endl;
        free(plast);
        ptemp->next = NULL;
        plast = ptemp;
    }
    num = num - 1;
}
void delsp() // deleting specified node
{
    int loc;
    cout << "Enter location" << endl;
    cin >> loc;
    pthis = pfirst;
    for (int i = 1; i <= loc - 1; i++)
    {
        pthis = pthis->next;
    }
    ptemp1 = pthis->next;
    ptemp = pthis->prev;
    cout << "Deleted item is" << pthis->info << endl;
    free(pthis);
    ptemp->next = ptemp1;
    ptemp1->prev = ptemp;
    num = num - 1;
}
void display() // display functioin
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
int main()
{
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
