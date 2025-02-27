#include <iostream>
using namespace std;
void TOH(int, char, char, char);
int main()
{
    int n;
    cout << "Enter number of disks" << endl;
    cin >> n;
    TOH(n, 'S', 'M', 'D');
    return 0;
}
void TOH(int n, char S, char M, char D)
{
    if (n > 0)
    {
        TOH(n - 1, S, D, M);
        cout << "Move disk a from " << S << " to " << D << endl;
        TOH(n - 1, M, S, D);
    }
}