/* two pointer approach works as follows:
if the sum is lesser than the target elem
move the left pointer; if the sum is greater
move the right pointer */
#include <bits/stdc++.h>
using namespace std;

bool isPresent(int arr[], int n, int sum)
{
    int l = 0, h = n - 1;
    // int mid;

    while( l <= h)
    {
        if(arr[l] + arr[h] ==  sum)
            return true;
        
        else if(arr[l] + arr[h] > sum)
        {
            h--;
        }
        else l++;
    }

    return false;
}

int main()
{
    int arr[] = {2, 3, 7, 8, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 14;
    
    cout << isPresent(arr, n, sum);
}