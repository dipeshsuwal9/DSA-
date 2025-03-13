#include <iostream>
using namespace std;
int main()
{
    int a[100], n;
    int x = 1;
    cout << "Enter no. of elements in the list";
    cin >> n;
    cout << "Enter data:";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // cout << "The list is:" << endl;
    for (int i = n - 1; i > 0; i--)
    {
        cout << "PASS" << "  " << x << endl;
        x++;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
            for (int k = 0; k < n; k++)
            {
                cout << a[k] << "\t";
            }
            cout << "\n";
        }
    }
}