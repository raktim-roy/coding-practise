#include <bits/stdc++.h>

using namespace std;

int power_of_two(int n)
{
    if ( n && !(n &(n-1)))
        return 1;
    else
    {
        return 0;
    }
    
}

int main()
{
    int num = 5;
    cout << power_of_two(num) << endl;
}