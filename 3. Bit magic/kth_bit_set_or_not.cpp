#include <bits/stdc++.h>

using namespace std;

bool check_if_set(int num, int k)
{
    int x = 1<< (k-1);
    if (( num & x))
    {
        return true;
    }
    return false;
}


int main()
{
    int num = 5, k = 2;
    cout << check_if_set(num,k) << endl;
    return 0;
}