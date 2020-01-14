/* Given a sorted array with repeatations, find leftmost
index of an element */
#include <bits/stdc++.h>
/* works on a sorted array */
using namespace std;

int binarySearch(int arr[], int l, int h, int x)
{
    if (h >= l)
    {
        int mid = l + (h - l)/2;

        if (arr[mid] == x && (mid == 0 || arr[mid -1] != x)) return mid;

        if (arr[mid] >= x)
        {
            return binarySearch(arr, l, mid-1, x);
        }

        else
        {
            return binarySearch(arr, mid+1, h, x);
        }
    }
    
    return -1;
    
}

int main()
{
    int arr[] = {2, 3, 3,3,3};
    cout << binarySearch(arr, 0, 4, 3) << endl;

    return 0;
}