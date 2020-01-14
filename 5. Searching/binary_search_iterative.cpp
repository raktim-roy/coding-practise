#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int l, int h, int x)
{
    while(l < h)
    {
        int mid = l + (h-l)/2;

        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
        {
            h = (mid - 1);
        }

        else
        {
            l = (mid + 1);
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