#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int num = 0;
struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
};
struct node *pnew, *pthis, *ptemp, *ppthis, *root = NULL;
void create()
{
    char ch;
    int x;
    pnew = (struct node *)malloc(sizeof(struct node));
    cout << "Enter data:" << endl;
    cin >> pnew->info;
    pnew->lchild = NULL;
    pnew->rchild = NULL;
    if (root == NULL)
    {
        root = pnew;
    }
    else
    {
        pthis = root;
        while (pthis != NULL)
        {
            ppthis = pthis;
            cout << "Left or Right?(L/R):";
            cin >> ch;
            if (ch == 'L' || ch == 'l')
            {
                pthis = pthis->lchild;
                if (pthis == NULL)
                {
                    ppthis->lchild = pnew;
                }
            }
            if (ch == 'R' || ch == 'r')
            {
                pthis = pthis->rchild;
                if (pthis == NULL)
                {
                    ppthis->rchild = pnew;
                }
            }
        }
    }
}
void preorder(struct node *p)
{
    if (p != NULL)
    {
        cout << p->info << endl;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        cout << p->info << endl;
        inorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if (p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->info << endl;
    }
}
char stop()
{
    char ch = 'n';
    return ch;
}
int main()
{
    int a, b;
    char ch;
    do
    {
        cout << "1.Create or add node in binary tree" << endl
             << "2.Stop" << endl;
        cin >> b;
        switch (b)
        {
        case 1:
            create();
            break;
        case 2:
            ch = stop();
        }
    } while (ch != 'n');

    while (1)
    {
        cout << "1.Preorder Traversal" << endl
             << "2.Inorder Traversal" << endl
             << "3.Postorder Traversal" << endl
             << "4.Exit" << endl;
        cout << "Enter choice:" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "PREORDER" << endl;
            preorder(root);
            break;
        case 2:
            cout << "INORDER" << endl;
            inorder(root);
            break;
        case 3:
            cout << "POSTORDER" << endl;
            postorder(root);
            break;
        case 4:
            exit(0);
        }
    }
}