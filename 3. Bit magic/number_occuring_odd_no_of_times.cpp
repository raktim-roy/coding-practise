#include <bits/stdc++.h>
using namespace std;

/* uses xor to find out the odd digit in a number or an array */
int getOddOccurrence(int ar[], int ar_size)
{
    int res = 0;
    for(int i = 0; i < ar_size; i++)
    {
        res = res ^ ar[i];
    }

    return res;
}

int main()
{
    int arr[]={3,3,3,2,4,2,4};
    cout << getOddOccurrence(arr, sizeof(arr)/sizeof(arr[0])) << endl;
}