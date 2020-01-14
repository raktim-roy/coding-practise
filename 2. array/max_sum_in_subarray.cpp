#include <bits/stdc++.h>

using namespace std;

int maxSum(int arr[], int n, int k)
{
    if (n < k)
    {
        cout << "Invalid";
        return -1;
    }

    /* Compute sum of first window of size k */
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res += arr[i];
    }

    /* Compute sum of remaining windows
    removing first elemnt of previous
    window and adding last element of
    current window */
    int curr_sum = res;
    for(int i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i-k];
        res = max(res, curr_sum);
    }

    return res;
}


/* Driver code */
int main()
{
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4; /*Sub array size defined */
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}

/* Window sliding technique: 
If it is a non-negative unsorted array we can keep on adding
the elements untill the sum is less than the desired 
value. Once the sum of the array elements exceed the 
desired sum start removing from the beginning and continue
that */ 