#include <bits/stdc++.h>

using namespace std;

/* Write ur own max function */

int maxcuts(int n, int a, int b, int c)
{
    if( n == 0) return 0;
    if (n < 0) return -1;

    int res = max(maxcuts(n-a, a, b, c), maxcuts(n-b, a, b, c), maxcuts(n-c, a, b, c));

    if (res == -1) return -1;
    return (res + 1);
}

int main()
{
    int res = maxcuts(25,11,12,13);
    cout << res << endl;
}