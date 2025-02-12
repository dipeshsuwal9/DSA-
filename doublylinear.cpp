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
struct node *pfirst = NULL, *pnew, *pthis, *ptemp, *plast;
void create()
{
    pnew = (struct node *)malloc(sizeof(struct node));
    cout << "enter data";
    cin >> pnew->info;
    num = num + 1;
}
void insbg()
{
}