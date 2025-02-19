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
struct node *pnew, *pthis, *ptemp, *plast, *ptemp1, *phead;
void create()
{
    pnew = (struct node *)malloc(sizeof(struct node));
    cout << "Enter data:";
    cin >> pnew->info;
    num = num + 1;
}
void head()
{
    phead = (struct node *)malloc(sizeof(struct node));
    phead->next = phead;
    phead->prev = phead;
}
void insbg()
{
    if (pfirst == NULL)
    {
        phead->next = pnew;
        pnew->prev = phead;
        pnew->next = phead;
    }
    else
    {
        ptemp
            phead->next = pnew;
        pnew->prev = phead;
        pnew->next = ptemp;
        pfirst->prev = pnew;
        pfirst = pnew;
    }
}
void insend()
{
    if (pfirst == NULL)
    {
        phead->next = pnew;
        pnew->prev = phead;
        pnew->next = phead;
    }
    else
    {
    }
}