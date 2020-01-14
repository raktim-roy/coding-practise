#include <bits/stdc++.h>
/* Uses kerningham algo to find out the set bits
this reduces the no of bits traversed; instead of O(n bits)
only the set bits are needed (O set bits)  */
using namespace std;

int count_set_bits(int n)
{
    int res = 0;
    while ( n > 0)
    {
        n = n & (n-1); /* kerningham told that this sets the last set bit to zero */
        res++;
    }
    return res;
}   
int main()
{
    cout << count_set_bits(7) << endl;
}