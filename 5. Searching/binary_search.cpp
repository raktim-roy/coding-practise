#include <bits/stdc++.h>
/* works on a sorted array */
using namespace std;

int binarySearch(int arr[], int l, int h, int x)
{
    if (h >= l)
    {
        int mid = l + (h - l)/2;

        if (arr[mid] == x) return mid;

        if (arr[mid] > x)
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
    int arr[] = {2, 3, 4,6, 80};
    cout << binarySearch(arr, 0, 4, 6) << endl;

    return 0;
}