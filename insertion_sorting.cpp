#include <iostream>
using namespace std;
int main()
{
    int a[100], n, f, temp;
    int i = 0, j;
    cout << "enter no. of elements:";
    cin >> n;
    cout << "Enter data:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Sorted list is:" << endl;
    while (i < n)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0)
        {
            if (temp < a[j])
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
            j--;
            a[j + 1] = temp;
        }
        i++;
        cout << "PASS" << "  " << i << endl;
        for (int k = 0; k < n; k++)
        {
            cout << a[k] << "\t";
        }
        cout << endl;
    }

    return 0;
}