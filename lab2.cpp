#include<iostream>
#include<cstring>
using namespace std;
int top=-1;
int pos=-1;
int n;
char infix[10],pf[10],stack[10];
char a,b;
int check(char op)
{
    if(op=='+'||op=='-')
    {
        return 1;
    }
    else if(op=='*'||op=='/')
    {
        return 2;
    }
}
char push(char x)
{
    top=top+1;
    stack[top]=x;
    return x;
}
char pop(char x)
{
    stack[top]=x;
    top=top-1;
    pos=pos+1;
    return x;
}
int main()
{
    cout<<"Enter infix:";
    cin>>infix;
    n=strlen(infix);
    for(int i=0;i<n;i++)
    {
        if(infix[i]>=33 && infix[i]<=47)
        {
            if(infix[i]=='(')
            {
                stack[i]=push(infix[i]);
            }
            else if(top>=0 && infix[i]=='+'|| infix[i]=='-'|| infix[i]=='*'||infix[i]=='/')
            {
                int a=check(infix[i]);
                int b=check(stack[i]);
                if(b>=a)
                {
                    a=pop(stack[i]);
                    pf[pos] = a;
                }
            }
            else if(infix[i]==')')
            {
                while(infix[i]!='(' || top>=0)
                {
                    a=pop(infix[i]);
                    pf[i]=a;
                    top=top-1;
                }
            }

        }
        else
        {
            a=push(stack[i]);
        }
    }
    cout<<pf[pos];
    return 0;
}