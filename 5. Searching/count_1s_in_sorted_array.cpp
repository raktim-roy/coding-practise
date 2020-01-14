/* count the number of 1s present in a sorted array*/
#include <bits/stdc++.h>
using namespace std;


int leftIndex(int arr[], int size)
{
    int l = 0, h = size - 1;
    int mid = 0;

    while(l <= h)
    {
        mid = l + (h-l)/2;

        if(arr[mid] == 1 && (mid == 0 | arr[mid-1]!=1))
            return mid;
        
        else if(arr[mid]==0)
        {
            l = mid + 1;
        }

        else h = mid - 1;

    
    }

    return 0;
}

int main()
{
    int arr[] = {0,0,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << (n-leftIndex(arr,n)) << endl;
    return 0;
}