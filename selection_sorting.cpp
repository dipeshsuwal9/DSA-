#include <iostream>
using namespace std;
int main()
{
    int a[100], n, f, temp;
    cout << "enter no. of elements:";
    cin >> n;
    cout << "Enter data:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Sorted list is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "PASS" << "  " << i + 1 << endl;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            for (int k = 0; k < n; k++)
            {
                cout << a[k] << "\t";
            }
            cout << endl;
        }
    }
}